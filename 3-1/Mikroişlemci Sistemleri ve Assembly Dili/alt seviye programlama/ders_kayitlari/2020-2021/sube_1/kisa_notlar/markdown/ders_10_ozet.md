# Ders 10 Çalışma Özeti

## Genel Konular

- Önceki dersin tekrarı: yordamlar ve dış dosyadan yordam kullanımı
  - EXE programda ana yordam FAR olur. Aynı dosyadaki NEAR alt yordam `CALL etiket` ile, aynı dosyadaki FAR alt yordam `CALL FAR PTR etiket` ile çağrılır. NEAR çağrıda makine kodunda yalnız ofset, FAR çağrıda segment:ofset bulunur.
  - Başka dosyadaki yordam için ana dosyada `EXTRN etiket:FAR`, alt dosyada `PUBLIC etiket` yazılır ve yordam orada FAR tanımlanır. `EXTRN` tanımındaki FAR yüzünden assembler düz `CALL etiket` satırını `CALL FAR PTR` olarak derler.
  - Her dosya ayrı ayrı MASM ile OBJ'ye çevrilir, OBJ'ler birlikte linklenir. PUBLIC eksikse hata linkleme aşamasında çıkar.
  - Özyinelemeli EBOB: sonlanma $\gcd(x, 0) = x$, adım $\gcd(x, y) = \gcd(y, x \bmod y)$. Her çağrıda yığına atılan değerler incelenmişti.
- Yordam ve makro tanımı
  - Yordam: `etiket PROC [FAR]` ... `RET`/`RETF` ... `etiket ENDP`. Tip yazılmazsa NEAR kabul edilir. FAR yordam `RETF` ile döner.
  - Makro: `ad MACRO param1, param2, ...` ... `ENDM`. Parametre listesi isteğe bağlıdır.
  - Makro içinde etiket varsa `LOCAL L1` yazılır. Böylece makronun her açılışında etiket benzersiz bir adla değiştirilir.
- Örnek: üs alma (ekrandan, 00:20:00 ve 00:25:00)
  - Veri: `US1 DW 3`, `TABAN1 DW 2`, `SONUC1 DD ?`, `US2 DW 2`, `TABAN2 DW 3`, `SONUC2 DD ?`. Hedef $2^3$ ve $3^2$.
  - Kod: `MOV CX, US1` / `MOV AX, 1` / `MOV BX, TABAN1` / `L1: MUL BX` / `LOOP L1` / `LEA SI, SONUC1` / `MOV [SI], AX` / `MOV [SI+2], DX`. İkinci çift için aynı blok `L2` ile tekrar yazılır.
  - $x^0 = 1$ olduğu için AX başta 1 yapılır, döngü üs kadar döner. Sonuç DX:AX'tedir; AX düşük, DX yüksek word olarak yazılır.
  - DEBUG'da veri kesimi: `03 00 02 00 08 00 00 00 02 00 03 00 09 00 00 00` (ekrandan, 00:35:00). Little endian okunur: SONUC1 = 00000008H, SONUC2 = 00000009H.
  - Sonuç double word olsa da büyük taban ve üslerde taşabilir; kod küçük değerler için düşünülmüştür.
- Aynı işin dış dosyada FAR yordamla yapılması (ekrandan, 00:35:00 ve 00:50:00)
  - `USTAL PROC FAR` girdi BX = taban, CX = üs, dönüş DX:AX. AX parametre değildir, yordam içinde 1 yapılır.
  - Ana yordam CX ve BX'i doldurup `CALL USTAL` der, dönüşte DX:AX'i SONUC'a yazar.
  - Alt dosyada `END`'den sonra etiket yoktur. Bu, o dosyanın giriş noktası olmadığını gösterir.
- Aynı işin makroyla yapılması (ekrandan, 00:40:00, 00:45:00 ve 00:50:00)
  - `USTALM MACRO M_US, M_TABAN, M_SONUC` / `LOCAL L1` / `MOV AX, 1` / `MOV CX, M_US` / `MOV BX, M_TABAN` / `L1: MUL BX` / `LOOP L1` / `LEA SI, M_SONUC` / `MOV [SI], AX` / `MOV [SI+2], DX` / `ENDM`.
  - Makro ayrı bir dosyada durur ve `INCLUDE` ile eklenir. Ayrı OBJ üretmez, yalnız ana dosya derlenip linklenir.
  - Çağrı: `USTALM US1, TABAN1, SONUC1` ve `USTALM US2, TABAN2, SONUC2`. Parametre olarak bellek etiketleri verilir, yazmaçları önceden hazırlamak gerekmez.
  - LST dosyasında `INCLUDE` ile gelen makro tanımının makine kodu yoktur. Çağrı satırının da makine kodu yoktur; altında makro gövdesi açılır. `L1` etiketi birinci çağrıda `??0000`, ikincide `??0001` olur (ekrandan, 00:45:00).
- Yordam ve makro karşılaştırması (ekrandan, 01:15:00)
  - Çalışma şekli: yordam çalışma sırasında (run time), makro derleme sırasında devreye girer.
  - Çalışma süresi: yordamda CALL ve RET yükü vardır (NEAR'da IP, FAR'da CS ve IP yığına atılıp çekilir). Makroda bu yük yoktur, bu yüzden aynı işi yapan makro daha hızlıdır.
  - Kod büyüklüğü: yordam çağrısı kodu büyütmez. Makro her çağrıldığı yerde kodu kendi boyu kadar büyütür. Hiç çağrılmayan yordam yine kod üretir, hiç çağrılmayan makro üretmez.
  - Parametre aktarımı: yordama yazmaç, yığın ya da ortak veri kesimi üzerinden; makroya virgülle ayrılmış parametre listesiyle.
  - Kısa ve hızlı işler için makro, uzun ve ayrı mantıkta ele alınacak işler için yordam daha uygundur.
- DOS kesmeleri ve makrolar (ekrandan, 01:25:00 – 01:35:00)
  - Kesme `INT numara` ile bir fonksiyon gibi çağrılır. Kesme numaralarının bir kısmı BIOS'a, bir kısmı DOS'a ayrılmıştır. Fonksiyon numarası AH ile verilir.
  - Kesme, normal çağrıdan farklı olarak yığına bayrakları da atar; dönüş `IRET` ile yapılır.
  - INT 21H, AH=09H: DS:DX'teki metni `$` karakterine kadar yazar (`MSG DB 'DENEME', '$'`). AH=0AH klavyeden okuma yapar.
  - INT 21H, AH=01H: bir karakter okur, AL'ye koyar ve ekrana yansıtır (echo). AH=02H: DL'deki karakteri yazar.
  - COM programında `READCM MACRO` (`MOV AH, 01H` / `INT 21H`) ve `WRITECM MACRO` (`MOV AH, 02H` / `INT 21H`) tanımlanır; ana yordamda `READCM` / `MOV DL, AL` / `WRITECM` / `RET` yazılır.
  - Kesme çağrısı da yazmaç üzerinden parametre aktarımına bir örnektir. Aynı kesmeler EXE programda da kullanılabilir.
- Yığın üzerinden parametre aktarımı
  - Üç aktarım yolu vardır: yazmaç, yığın, ortak veri kesimi (EXTRN/PUBLIC).
  - Yığına atılan parametrelerin dönüşte kim tarafından kaldırılacağı tanımlanmalıdır. Kalırsa ana yordamın `RETF`'i bu değerleri IP ve CS diye çeker.
  - Dönüş değeri yığından geliyorsa onu okuyup kaldırmak ana yordamın işidir. Fazla parametreler ana yordam ya da alt yordam tarafından kaldırılabilir.
  - Yığından en fazla, yığına atılan parametre sayısı kadar değer döndürülebilir.
- Örnek: yığından iki parametreyle EBOB (ekrandan, 01:55:00 – 02:45:00)
  - Veri: `ASAYISI DW 12`, `BSAYISI DW 8`, `SONUC DW ?`. Ana dosyada `EXTRN _GCD_PROC:FAR`, ana yordamda `PUSH ASAYISI` / `PUSH BSAYISI` / `CALL _GCD_PROC`.
  - Alt yordam girişi: `PUSH BP` / `MOV BP, SP` / `PUSH BX` / `PUSH DX`. Parametreler: `MOV BX, [BP+6]` (B), `MOV AX, [BP+8]` (A).
  - Gövde: `CMP AX, BX` / `JAE TEKRAR` / `XCHG AX, BX` / `TEKRAR: CMP BX, 0` / `JA L1` / `JMP EXIT` / `L1: XOR DX, DX` / `DIV BX` / `MOV AX, BX` / `MOV BX, DX` / `JMP TEKRAR`. Çıkış: `POP DX` / `POP BX` / `POP BP` / `RETF`.
  - Sürüm 1: dönüş AX'te, parametreleri ana yordam kaldırır: `MOV SONUC, AX` / `POP AX` / `POP AX`.
  - Sürüm 2: dönüş AX'te, parametreleri alt yordam `RETF 4` ile kaldırır.
  - Sürüm 3: dönüş yığında. Alt yordam AX'i de korur ve `MOV [BP+8], AX` ile sonucu A'nın gözüne yazar. Ana yordam `POP AX` (B, boş okuma) / `POP AX` / `MOV SONUC, AX` yapar.
  - Sürüm 4: aynı yerleşimle alt yordam `RETF 2` ile döner; ana yordam yalnız `POP AX` / `MOV SONUC, AX` yapar.
  - Sonuç: $\gcd(12, 8) = \gcd(8, 4) = \gcd(4, 0) = 4$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazmaç koruma kuralı
  - Alt yordamda parametre ve dönüş için kullanılmayan, geçici işler için bozulan her yazmaç girişte PUSH edilir, dönüşten önce ters sırada POP edilir. Hoca bunu "temel kuralımız" ve "çok önemli" diye birkaç kez tekrarladı.
- BP'nin sabit referans olarak kullanılması
  - SP, alt yordam içindeki PUSH/POP'larla ve araya giren kesmelerle değişir. Bu yüzden girişte `MOV BP, SP` ile sabit bir referans alınır ve parametrelere BP'ye göre erişilir.
  - BP ile yapılan bellek erişiminde varsayılan segment SS'dir. BX, SI, DI ile DS'dir.
  - BP de bozulacağı için önce `PUSH BP` yapılır.
- Yığın çizimi
  - Hoca yığın üzerinden aktarımda her adımda yığının çizilmesini önerdi: altta OS CS ve OS IP, sonra A, B, ana CS, ana IP, BP ve korunan yazmaçlar. Yığın yüksek adresten düşük adrese doğru dolar.
- Dönüş değerinin yerleşimi için önerilen kalıp
  - Yığından dönen değerler, yığına atılmış parametreler arasında en yüksek adresli gözden başlayarak yazılsın. Düşük adresli çöp gözler alt yordamda `RETF n` ile atlanır; ana yordamda fazladan POP gerekmez.
- `RETF n`
  - `RETF n` önce IP'yi ve CS'yi çeker, sonra SP'yi n artırır. n çift sayıdır: çöp parametre sayısı × 2.
- Yığının en dolu olduğu an
  - Hoca, yığının en dolu olduğu andaki içeriğin sorulabileceğini söyledi. Özyinelemeli bir yordamda bu an zincirin en uç durumudur.
- Makroda `LOCAL`
  - Makroda etiket varsa `LOCAL` mutlaka yazılmalıdır, yoksa aynı etiket birden çok kez tanımlanmış olur.
- FAR yordam `RETF` ile bitirilmeli
  - Assembler FAR yordamdaki `RET`'i kendisi `RETF`'e çevirse de derste FAR yordamın `RETF` ile bitirilmesi kural olarak kabul edildi.

## Kısa Tekrar Notları

- Yordam her çağrıda aynı koda dallanır, kodu büyütmez, CALL/RET yükü vardır, çalışma sırasında devreye girer.
- Makro her çağrıda kopyalanır, kodu büyütür, çağrı yükü yoktur, derleme sırasında açılır; çağrılmazsa kod üretmez.
- Makroda etiket kullanılıyorsa `LOCAL`; assembler etiketleri `??0000`, `??0001` diye adlandırır.
- Makroya bellek etiketleri parametre olarak verilebilir; dosyaya `INCLUDE` ile eklenir, ayrı OBJ üretmez.
- INT 21H: AH=01H karakter okur (AL, echo'lu), AH=02H DL'yi yazar, AH=09H DS:DX'teki `$` ile biten metni yazar, AH=0AH girdi okur.
- Kesme bayrakları da yığına atar, `IRET` ile döner.
- Parametre aktarımı: yazmaç, yığın, ortak veri kesimi.
- Yığından aktarımda girişte `PUSH BP` / `MOV BP, SP`; FAR çağrıda ilk parametre (son atılan) `[BP+6]`, bir önceki `[BP+8]`.
- `[BP+...]` erişiminde varsayılan segment SS.
- Parametreleri ana yordam boş POP'larla ya da alt yordam `RETF n` ile kaldırır.
- Dönüş değeri yığındaysa okumak ana yordamın işidir; en yüksek adresli göze yazılırsa kalanlar `RETF n` ile atılır.
- Dönüş değeri AX'teyse ana yordam önce `MOV SONUC, AX` yapmalı, sonra boş POP'ları yapmalı.

## Detaylı Açıklamalar

- Üs alma örneğinde tek dosyalı çözüm, aynı bloğun iki kez yazılmasını gerektirdi; bu da modüler yapıya ihtiyaç doğurdu. Yordam çözümünde fonksiyon bir kara kutu olarak düşünüldü: girdileri CX (üs) ve BX (taban), çıktısı DX:AX. AX başlangıçta 1 yapıldığı için parametre değildir. Ana yordam her çağrıdan önce CX ve BX'i hazırlar, dönüşte sonucu `LEA SI, SONUCx` / `MOV [SI], AX` / `MOV [SI+2], DX` ile yazar. DEBUG'da ikinci çağrıda yordama CX = 2, BX = 3 ile girildiği, yani aynı kodun farklı parametrelerle çalıştığı görüldü.
- Makro çözümünde parametreler doğrudan bellek etiketleri olduğu için çağrı tek satıra indi: `USTALM US1, TABAN1, SONUC1`. LST dosyasında makro gövdesinin her çağrının altına açıldığı, `MOV AX, 1` gibi satırların makine kodlarının (`B8 0001`) orada üretildiği ve `LOOP ??0000` biçiminde benzersiz etiket kullanıldığı görüldü (ekrandan, 00:45:00). DEBUG'da program, gövde ana yordama elle yazılmış gibi dallanmasız yürüdü ve yine 8 ile 9 sonuçları yazıldı.
- DOS kesmeleri örneğinde önce `read.asm` COM programında `READ PROC NEAR` içinde `MOV AH, 01H` / `INT 21H` kullanıldı. Program DEBUG'da kesmeye gelince klavyeden karakter beklediği için orada durdu. Sonra `rw.asm` içinde iki makro tanımlandı. Hoca önce AH=02H fonksiyonunun AL'yi yazdığını düşündü; kesme listesine bakınca DL'yi yazdığını gördü ve araya `MOV DL, AL` ekledi. AH=01H okunan karakteri ekrana da yansıttığı için çalıştırınca karakter iki kez görünür. Hoca, DOS kesme listesinin (kitabın ekindeki liste ya da internetteki listeler) fonksiyonların parametreleri için kaynak olarak kullanılmasını önerdi.
- Yığından aktarımda yığının düzeni (FAR çağrı, girişte `PUSH BP` / `MOV BP, SP` sonrası) şöyledir:

  ```text
  Adres       İçerik
  BP+8        A (ilk atılan parametre)
  BP+6        B (ikinci atılan parametre)
  BP+4        ana yordam CS
  BP+2        ana yordam IP
  BP+0        eski BP          <- SP, BP
  BP-2        BX
  BP-4        DX               <- SP (PUSH BX, PUSH DX sonrası)
  ```

- DEBUG'daki değerler (ekrandan, 02:20:00): yığın 32 word olduğu için `PUSH DS` / `PUSH AX` sonrası SP = 3CH'dir; A ve B atılınca 38H, CALL FAR sonrası 34H, `PUSH BP` sonrası 32H (BP = 32H), BX ve DX sonrası 2EH olur. SS:2E'den itibaren `0000 (DX)`, `0000 (BX)`, `0000 (BP)`, `0016 (ana IP)`, `076D (ana CS)`, `0008 (B)`, `000C (A)`, `0000 (OS IP)`, `075A (OS CS)` görülür. Bu, yordam özyinelemeli olmadığı için yığının en dolu olduğu andır.
- Sürüm 1'de ilk denemede ana yordam önce iki `POP AX` yapıp sonra `MOV SONUC, AX` yazıyordu. Hoca bunun AX'teki dönüş değerini boş okumayla ezdiğini fark etti ve `MOV SONUC, AX` satırını POP'ların üstüne aldı.
- Sürüm 2'de `RETF 4` sonrası SP doğrudan 3CH'ye geldi; B ve A gözleri çöp kaldı. Hoca DEBUG'da bu gözlerdeki değerlerin de değişmiş olduğunu gösterdi.
- Sürüm 3'te AX de geçici yazmaç hâline geldiği için girişte `PUSH AX`, çıkışta `POP AX` eklendi; yığın SS:2C'ye kadar doldu. Sonuç A'nın gözüne (`[BP+8]`) yazıldı; ana yordam ilk POP ile B'yi boş okudu, ikinci POP ile sonucu aldı. Sürüm 4'te `RETF 2` B'nin gözünü atladığı için ana yordama dönüldüğünde yığının üstünde doğrudan sonuç vardı.
- Ders sonrası not: Hoca, `MOV BP, SP` satırı korunan yazmaçların PUSH'larından sonraya taşınırsa A ve B'ye "14 ve 16 ofset öteden" erişileceğini söyledi. `PUSH BP`, `PUSH AX`, `PUSH BX`, `PUSH DX` sonrası SP'den itibaren BX +2, AX +4, BP +6, ana IP +8, ana CS +10 ötededir; doğrusu B için `[BP+12]`, A için `[BP+14]`'tür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
