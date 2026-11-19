# Ders 13 Çalışma Özeti

## Genel Konular

- Ödev sorularının çözümü üzerinden boyut analizi ve çarpma/bölme sırası
  - Soru 1: AL, AH, BL ve CL'yi toplayıp sonucu DX'te saklamak (ekrandan, 00:15:00). Dört 8 bitlik değerin toplamı en çok $4 \times 255 = 1020$ olduğundan 16 bite sığar. DX önce `XOR DX, DX` ile sıfırlanır; toplamalar DL'de yapılır, her toplamadan sonra elde `ADC DH, 0` ile DH'a eklenir. En büyük değerlerle (hepsi 255) sağlama yapıldığında sonuç 03FCH çıkar.
  - Soru 2: DL'deki sayının küpü (ekrandan, 00:20:00). $255^2 = 65025$ 16 bite, $255^3 = 16\,581\,375$ ise 32 bite sığar. Önce `MOV AL, DL` ve `MUL DL` ile kare AX'e alınır. İkinci kez `MUL DL` yazılırsa AH'daki anlamlı kısım kaybolur; bunun yerine `XOR DH, DH` ile DL 16 bite genişletilir ve `MUL DX` ile sonuç DX:AX'e alınır. 255 için ara sonuç FE01H, sonuç 00FD02FFH olur.
  - Soru 3: rastgele sayı üretimi (ekrandan, 00:25:00). Seed `CS:23` adresindeki word'dür; kod segmenti açıkça `CS:` önekiyle ya da CODESG değeri ES'ye konarak `ES:[23]` biçiminde kullanılır. Sonra `MUL A_SAY`, `ADD AX, C_SAY` / `ADC DX, 0`, `DIV M_SAY` yapılır; kalan DX'tedir. 8 bitlik sonuç için kalanın düşük baytı alınabilir ya da 256'ya göre mod alınabilir.
  - Genel kural: ardışık çarpma ve bölmede önce çarpma, sonra bölme yapılmalıdır. Önce çarpma yapılınca DX:AX bölme için hazır olur; önce bölme yapılırsa DX'te kalan durur ve hesap bozulabilir (ayrıntı ve düzeltme Detaylı Açıklamalar'da).
  - Biriktirme 32 bite taşıyorsa doğal "sanal 32 bitlik yazmaç" DX:AX'tir: düşük word AX'te toplanır, her adımın eldesi `ADC DX, 0` ile DX'e eklenir.
- Yüksek seviyeli dil ile assembly bağlantısının iki yolu (ekrandan, 00:30:00)
  - Inline: yüksek seviyeli dil kodunun içine assembly bloğu yerleştirilir.
  - Object code: ayrı derlenen assembly dosyasının obje dosyası, C kodunun obje dosyasıyla birlikte linklenir ve C'den fonksiyon gibi çağrılır.
  - İletişim iki yönlü olabilir (C'den assembly, assembly'den C çağırma); derste yalnız C'den assembly yordamı çağırma ele alındı.
- Visual Studio'da .asm dosyası derleme ortamı
  - Boş proje oluşturulur, Source Files'a yeni öğe eklenir, uzantısı `.asm` verilir.
  - Dosyanın özelliklerinde Genel > Öğe Türü "Custom Build Tool" seçilir. Command Line alanına Visual Studio ile gelen ML assembler'ı çağıran komut yazılır (`ml /c /Cx /coff` ve tam dosya yolu), Output alanına `.obj` uzantılı dosya adı verilir.
  <!-- BELİRSİZ: Command Line'ın tam metni (tırnak ve makro adları) altyazıdan "çift tırnak, yüzde ve full path" diye geçiyor; ekranda okunamadı. -->
- Inline assembly örneği: dizi elemanlarının bitlerini ters çevirme (ekrandan, 00:40:00 ve 00:45:00)
  - `const int n = 10;` ve `int dizi[10]` dizisi 1-10 değerleriyle doldurulur, `%08x` ile 8 hex basamak olarak yazdırılır. `sizeof(int)` 4 bayt = 32 bit olduğu için 8 hex basamak gerekir.
  - `__asm { ... }` bloğu (başta iki alt çizgi) içinde dış döngü ECX = n ile, iç döngü ECX = 32 ile döner; dış döngünün sayacı `push ecx` / `pop ecx` ile korunur.
  - İç döngüde `shr eax, 1` en düşük biti CF'ye atar, `rcl ebx, 1` CF'yi EBX'e sağdan besler (CF ile birlikte 33 bitlik döndürme). 32 tekrar sonunda EBX, EAX'in bit sırası ters çevrilmiş halidir.
  - `mov dizi[esi], ebx` ve `add esi, 4` ile sonuç aynı göze yazılır; int 4 bayt olduğu için indis 4 artar.
  - Çıktı: 1 → 80000000, 2 → 40000000, 3 → C0000000, ..., 10 (0AH) → 50000000 (ekrandan, 00:50:00).
- 32 bitlik inline assembly kuralları
  - Proje x64 değil x86 olarak derlenmelidir; Visual Studio'da 16 bitlik derleme imkânı yoktur.
  - Dolaylı adreslemede ESI, EDI, EBX kullanılır (64 bitte RSI vb.); döngüler ECX üzerinden döner. 8 ve 16 bitlik yazmaçlara (AL, AX, CL, DH...) erişim sürer, EAX'in yüksek 16 bitine ayrı erişim yoktur.
  - Yığın tanımı C programından gelir, ayrıca yapılmaz.
  - Debug > Windows > Disassembly, Registers ve Memory pencereleriyle kod adım adım (F11) incelenebilir. `push ecx` sonrası ESP 4 azalır; yığına 10 değeri 4 bayt little endian olarak yazılır (ekrandan, 01:20:00).
  - Korumalı modda çalışıldığı için görülen adresler fiziksel adres değildir.
- Ayrı assembly dosyası örneği: selection sort, C ve assembly karşılaştırması (ekrandan, 01:25:00, 01:40:00, 01:45:00)
  - C sürümü `SelSortC(int *sdizi, int boyut)`: her adımda dizinin kalanındaki en büyük elemanı bulup baştaki göze yazar; karmaşıklık $O(n^2)$, sonuç büyükten küçüğe sıralıdır.
  - Assembly sürümü `.586`, `PUBLIC _SelSortASM`, `_CODE SEGMENT dword public 'CODE' use32`, `ASSUME CS:_CODE`, `_SelSortASM PROC NEAR` ile tanımlanır. C tarafında ad `SelSortASM`, assembly tarafında başında alt çizgiyle `_SelSortASM` yazılır.
  - C tarafında dışarıdan gelen fonksiyon için prototip (`extern`, C çağırma kuralı, `void`, `int*` ve `int` parametre) tanımlanır.
  - 100 000 elemanlı dizide Release/x86 modda C sürümü yaklaşık 14,66 saniye sürdü; assembly sürümü 3-4 kat kadar hızlı çıktı (optimizasyon bayraklarının hepsi açık olmayabilir).
- Çağırma kuralları (calling conventions)
  - Parametrelerin nereden (yığın/yazmaç) ve hangi sırayla aktarıldığı, yığını kimin temizlediği (caller/callee) dil, derleyici ve işletim sistemine göre standarttır (Wikipedia "x86 calling conventions" tablosu, ekrandan, 01:30:00).
  - 32 bitlik cdecl: parametreler yığından, sağdan sola (RTL) aktarılır, yığını çağıran temizler. Dönüş değeri EAX'tedir.
  - System V AMD64 (Linux 64 bit): ilk 6 tamsayı parametre RDI, RSI, RDX, RCX, R8, R9; kayan noktalı parametreler XMM0-7; kalanlar yığından.
  - 16 bitte Turbo C gibi derleyicilerde parametreler soldan sağa AX, DX, BX yazmaçlarıyla aktarılabiliyordu.
- `_SelSortASM` içinde yığın düzeni
  - Girişte EBP, ECX, EDI, ESI, EAX, EBX, EDX sırayla yığına atılır, sonra `MOV EBP, ESP`. NEAR çağrı olduğu için yığında yalnız dönüş IP'si vardır.
  - Her öge 4 bayt olduğundan EBP'den itibaren 7 yazmaç (0-24) ve dönüş IP'si (28) geçilir: dizi adresi [EBP+32], n [EBP+36]'dadır.
  - Debug modda disassembly'de `push 186A0h` (100 000) ve ardından `push eax` (dizi adresi), sonra `call _SelSortASM` görülür; bu RTL kuralına uyar (ekrandan, 01:55:00).
  - Release modda derleyici C fonksiyonunu çağırmak yerine main'in içine gömer (inline eder) ve döngüleri LOOP yerine CMP/Jcc ile, `cmovle` gibi 8086'da olmayan komutlarla kurar (ekrandan, 01:50:00).
- Linux'ta GCC ve NASM ile C-assembly bağlantısı
  - NASM, MASM sözdizimine yakın olduğu için tercih edilir. Makefile iki adımı toplar: NASM ile `-f elf32` (ya da `elf64`) obje dosyası üretilir, GCC ile `main.c` ve obje birlikte derlenip linklenerek `topla` çalıştırılabiliri elde edilir; `./topla` ile çalıştırılır.
  - Fonksiyon NASM'de `global Topla` ile dışarı açılır; GCC'de alt çizgi öneki gerekmez.
  - 32 bit sürüm (ekrandan, 02:05:00): EBP, EDI, ECX yığına atılır, `MOV EBP, ESP`; dizi [EBP+16], n [EBP+20]'dedir. `ADD EAX, [EDI]`, `ADD EDI, 4`, `LOOP L1` ile toplam EAX'te birikir ve EAX dönüş değeridir.
  - 64 bit sürüm (ekrandan, 02:10:00): dizi RDI'da, n RSI'dadır. `PUSH RCX`, `MOV RCX, RSI`, `XOR RAX, RAX`, `ADD RAX, [RDI]`, `ADD RDI, 4`, `LOOP L1`; dönüş değeri RAX'tedir.
- GDB ile hata ayıklama (ekrandan, 02:15:00 ve 02:20:00)
  - `gdb topla`, `break main`, `run`, `set disassembly-flavor intel`, `disassemble main`, `x/i $rip`, `info registers`, `print $eax`.
  - Diğer komutlar: continue, finish, step, stepi, next, nexti, backtrace, up/down, kill, quit.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ardışık çarpma ve bölmede önce çarpma yapın.
  - Matematikte sıra fark etmese de assembly'de DX'te kalan değer yüzünden sonuç bozulur.
- İşlem öncesi boyut analizi yapın.
  - En büyük eleman değeri ile eleman sayısının çarpımı, toplamın 16 bite mi 32 bite mi sığacağını söyler (ör. $127 \times 60\,000$ 16 biti aşar).
- Toplama yapmadan önce yüksek yarının (DH, DX) değerini kesinleştirin.
  - Rastgele kalan değer en sık görülen hatalardan biridir.
- Kodu mutlaka en büyük değerlerle deneyerek sağlayın; programlayıcı hesap makinesiyle kontrol edin.
- İşaretli sayıda genişletme işaret korunarak yapılmalıdır (DL negatifse DH = FFH); işaretli çarpmada IMUL kullanılır.
- 32 bitlik inline assembly için x86 derleme seçilmeli; dolaylı adreslemede ESI/EDI/EBX, döngüde ECX kullanılmalıdır.
- Yığından parametre okurken ofsetleri yığına atılan yazmaç sayısına ve çağrı tipine (NEAR/FAR) göre hesaplayın.
- Derleyici optimizasyonu iyi kullanılırsa elle yazılmış assembly her zaman daha hızlı değildir; ne yapıldığı biliniyorsa kritik fonksiyonlarda hız kazanılabilir.

## Kısa Tekrar Notları

- 4 × 8 bit toplam → DX: `XOR DX,DX`, `ADD DL,x`, `ADC DH,0`. 4 × 255 = 03FCH.
- Küp: `MOV AL,DL`, `MUL DL` (AX = DL²), `XOR DH,DH`, `MUL DX` (DX:AX = DL³). 255³ = 00FD02FFH.
- Sıralı çarpma/bölmede önce çarpma.
- Inline: `__asm { }`, x86 derleme, ESI/EDI/EBX, ECX ile döngü.
- Bit ters çevirme: `shr eax,1` + `rcl ebx,1`, 32 kez.
- Visual Studio'da .asm için Custom Build Tool + `ml /c /Cx /coff`.
- MASM tarafında C fonksiyon adının başında alt çizgi; GCC/NASM'de yok.
- cdecl (32 bit): yığından, sağdan sola, dönüş EAX.
- System V AMD64: RDI, RSI, RDX, RCX, R8, R9; dönüş RAX.
- 7 yazmaç PUSH + NEAR dönüş IP'si → dizi [EBP+32], n [EBP+36].
- Release modda derleyici fonksiyonu inline edebilir; çağrı görünmeyebilir.
- GDB: break, run, set disassembly-flavor intel, disassemble, x/i, info registers, print.

## Detaylı Açıklamalar

- Ödev çözümlerinde ortak sorun, 16 bitlik bir işlem yaparken yazmacın yüksek yarısının değerinin belirsiz kalmasıydı. DX'e toplam biriktirirken önceki adımlar 8 bitlik yapılıp son toplama DX üzerinden yapılırsa DH'daki rastgele değer sonuca karışır. Çözüm, DX'i baştan sıfırlamak ve her 8 bitlik toplamanın eldesini `ADC DH, 0` ile DH'a eklemektir. İlk toplamadan elde gelemez ama sonraki üç toplamanın her birinde elde oluşabilir. Hoca kodu emu8086'da tüm değerler 255 iken adım adım yürüttü; her toplamada CF=1 oldu ve sonuç 03FCH (1020) çıktı.
- Çarpma ve bölme sırası: 16 bitlik `DIV` bölümü AX'e, kalanı DX'e yazar; 16 bitlik `MUL` ise sonucu DX:AX'e yazar. Önce çarpma yapılırsa DX çarpımın yüksek word'üyle dolar ve ardından gelen bölme doğru 32 bitlik sayıyı böler. Hoca, önce bölme yapılırsa DX'te kalan kalanın sonraki işlemlerde yüksek anlamlı word gibi kullanıldığını söyledi. Aynı mantık 8 bitlik işlemlerde AH için de geçerlidir.
  - Ders sonrası not: Hoca, önce bölme yapılınca DX'teki kalanın sonraki `MUL` ile birlikte çarpıldığını söyledi. Doğrusu: `MUL r/m16` yalnız AX'i çarpar, DX'i girdi olarak kullanmaz, üzerine yazar. Önce bölmenin asıl sakıncaları kalanın (kesirli kısmın) kaybolması ve DX'teki kalanın sonraki bir `DIV` ya da 32 bitlik işlemde DX:AX'in parçası sayılmasıdır.
- Küp örneğinde ikinci çarpmanın 16 bitlik olması gerekir; ama AX ile 8 bitlik DL çarpılamaz. DL'yi DX'e genişletmek için işaretsiz durumda DH sıfırlanır, işaretli durumda işaret biti DH'a yayılır (DL'nin en yüksek biti 1 ise DH = FFH) ve IMUL kullanılır. Böylece `MUL DX` ile DX:AX = DL³ elde edilir.
- Inline assembly örneğinde bit ters çevirme şöyle çalışır: EAX sağa kaydırıldıkça en düşük biti CF'ye düşer; `rcl ebx, 1` ise EBX'i CF üzerinden sola döndürerek bu biti EBX'in en düşük bitine yerleştirir. Orijinal sayı sağdan "boşaltılırken" yardımcı yazmaç sağdan "doldurulur"; 32 adım sonunda bit sırası ayna görüntüsü olur. Örneğin 1 (yalnız en düşük bit 1) ters çevrilince yalnız en yüksek bit 1 olur: 80000000H. 0AH = 1010B ters çevrilince en üstteki 4 bit 0101B olur: 50000000H.
- Visual Studio'da Release ve Debug derlemelerin disassembly'si farklıdır. Release modda derleyici `SelSortC` fonksiyonunu main'in içine gömdüğü için çağrı ve parametre aktarımı görünmez; Call Stack'te "[Inline Frame] SelSortC" yazar ve dizi boyutu 186A0H sabiti olarak karşılaştırmalara girer (ekrandan, 01:35:00). Debug modda ise `push 186A0h`, `push eax`, `call _SelSortASM` sırası açıkça görülür.
  - Ders sonrası not: Hoca derste parametreleri yazmaç ve yığında bulamadı, sonra Release modda fonksiyon çağrısının ortadan kalktığını gösterdi. Ekrandaki "[Inline Frame]" ifadesi, aranan parametrelerin bu inline etme yüzünden görünmediğini gösteriyor.
- `_SelSortASM` içinde yazmaç atamaları (ekrandan, 01:45:00): EBX iç döngünün kalan sayısını, EAX dizinin başlangıç adresini tutar; iç döngüde ESI dizinin geri kalanını tarar, EDI o ana kadar bulunan seçili elemanın adresini, EDX de onun değerini tutar. İç döngü bitince `MOV EDX, [ESI]`, `XCHG EDX, [EDI]`, `MOV [ESI], EDX` ile değiş tokuş yapılır ve `LOOP dis_don` ile dış döngüye dönülür.
  - Ders sonrası not: Hoca ESI'yi C'deki `i`'ye, EDI'yi `j`'ye eşledi. Ekrandaki kodda ise ESI tarayan işaretçidir, EDI seçilen elemanın adresini tutar; `JGE ATLA` nedeniyle seçilen eleman en küçüktür ve kalan aralığın sonuna yazılır. Sonuç yine büyükten küçüğe sıralı dizidir (ekranda görünen satırlar python ile benzetilerek denendi). <!-- BELİRSİZ: kodun 20-22. satırları ve 40. satırdan sonrası karelerde görünmüyor. -->
- Linux 32 bit örnekte hoca yığını önce FAR çağrı varsayarak (ANA CS ile) çizdi, ofsetler tutmayınca NEAR çağrıya göre düzeltti: ECX [EBP], EDI [EBP+4], EBP [EBP+8], dönüş IP'si [EBP+12], dizi [EBP+16], n [EBP+20]. Hoca toplamın $n(n+1)/2$ olduğunu ve 32 bitte taşma kontrolü yapılmadığını belirtti; 64 bit sürümde RAX kullanıldığı için bu sorun yoktur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
