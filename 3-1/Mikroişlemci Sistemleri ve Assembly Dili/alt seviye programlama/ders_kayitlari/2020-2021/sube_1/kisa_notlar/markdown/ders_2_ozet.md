# Ders 2 Çalışma Özeti

## Genel Konular

- Birinci haftanın tekrarı: sayı gösterimleri ve veri formatları
  - Bir bit dizisinin işaretli mi işaretsiz mi yorumlanacağını komut belirler. Sekiz adet 1'den oluşan dizi işaretsiz işlemde 255, işaretli işlemde -1 anlamına gelir.
  - İşaretli sayıların üç gösterimi: işaretli genlik (sign and magnitude), bire tümleyen ve ikiye tümleyen. İlk ikisinde iki ayrı sıfır gösterimi vardır (4 bitte `0000` ve `1000` ya da `0000` ve `1111`). İkiye tümleyende tekrar yoktur, fakat aralık asimetriktir: 4 bitte -8 ile +7 arası (ekrandan, 00:05:00).
  - BCD'de her ondalık basamak 4 bitle yazılır: 526 BCD'de 12 bit, doğrudan ikilikte 10 bit tutar.
  - 8086'da her bellek gözü 8 bittir. Word 2 gözü (16 bit), double word 4 gözü (32 bit) kaplar.
  - 8086 little endian çalışır: `12345678H` sayısı 100H adresinden itibaren `78H, 56H, 34H, 12H` sırasıyla yerleşir (ekrandan, 00:10:00). Big endian'da yüksek anlamlı byte düşük adrese yazılır.
- Mikroişlemcinin iç yapısı ve 8086 yazmaçları
  - Dört temel kavram: yazmaçlar, ALU, kontrol birimleri (bus kontrol ve yürütme birimi) ve bunları bağlayan yollar.
  - Genel amaçlı yazmaçlar AX, BX, CX, DX (8 bitlik AL/AH vb. erişimle), SI, DI, SP, BP; segment yazmaçları SS, CS, DS, ES; özel yazmaç IP; bayraklar CF, PF, AF, ZF, SF, TF, IF, DF, OF (ekrandan, 00:15:00).
  - AX akümülatördür: ALU sonuçları için özel, bazı komutlarda daha kısa ve hızlı kodlanır; çarpma, bölme ve giriş-çıkışta gizli operanddır.
  - BX dizi erişiminde dolaylı adreslemede kullanılır. CX döngü sayacıdır (`LOOP`), kaydırma ve döndürmede sayaç CL'dir. DX çarpma/bölmede gizli operanddır, 8 bite sığmayan port numarasını taşır.
  - SP yığının tepesini gösterir; yığına veri atıldıkça 2 azalır, çekildikçe 2 artar. Yığına yalnız word atılır. BP alt programda parametrelere erişmek için sabit referanstır.
  - SI ve DI katar (string) işlemlerinde kaynak ve hedef adresini tutar. İşlem CX kez tekrarlanır, yönü DF belirler.
- Segment ve offset ile fiziksel adres (offset memory model)
  - 8086'nın yazmaçları ve veri yolu 16 bit, adres yolu 20 bittir. Fiziksel adres: $PA = Segment \times 10H + Offset$.
  - Örnek: DS=1230H, SI=0045H için 12300H + 0045H = 12345H (ekrandan, 00:30:00).
  - Her segment 64 KB'lık bir alanı temsil eder. Varsayılan eşleşmeler: CS ile IP; DS ile BX, SI, DI; ES de DS gibi; SS ile SP ve BP (ekrandan, 00:30:00).
  - IP'ye programcı değer atayamaz. Komut yürütülünce komutun byte sayısı kadar artar; dallanmada hedef adresi ya da görece kayma uygulanır.
- Bayrakların anlamı
  - CF: işaretsiz işlemde taşma ya da elde/borç. PF: eşlik denetimi. AF: alt 4 bitten 5. bite elde, BCD düzeltmesinde gerekir. ZF: sonuç sıfır. SF: sonuç negatif.
  - TF: her komuttan sonra kesme üretir, adım adım hata ayıklama içindir. IF: INTR ucundan gelen kesmelere izin verir. DF: dizi işlemlerinde SI/DI'nin artacağını (DF=0) ya da azalacağını (DF=1) belirler. OF: işaretli işlemde taşma (ekrandan, 00:45:00).
  - OF örneği: 8 bit işaretli 100 + 100 = 200, +127 sınırını aşar; iki pozitifin toplamı negatif görünür.
- 32 ve 64 bit işlemcilerde yazmaçlar
  - 80386 ile EAX gibi 32 bitlik "extended" yazmaçlar gelir. Erişim yalnız AL, AH, AX ve EAX biçimindedir; üst 16 bitin ayrı adı yoktur.
  - 64 bitte RAX, EAX, AX, AL, AH; ayrıca RSI, RDI, RSP, RBP, RIP, R8-R15, RFLAGS, FS, GS (ekrandan, 00:50:00).
  - Real mode'da program 1 MB'ın her yerine erişir; protected mode'da her programa tablo üzerinden alan ve izin verilir.
  - SIMD (single instruction multiple data) komutları vektör yazmaçlarında çalışır; 512 bitlik bir yazmaçta tek komutla 64 byte işlenebilir.
- Basit bir işlemcide kontrol birimi
  - Instruction memory'den PC (8086'da IP) adresindeki komut okunur, instruction decoder kontrol işaretlerini (yazmaç adresleri, MUX seçimleri, FS, MW, RW vb.) üretir (ekrandan, 01:00:00).
  - Kontrol birimi instruction decoder, program counter ve branch control'den oluşur.
- 8086 komut yapısı
  - Genel biçim: `{Etiket :} Mnemonic {{Operand1,} Operand2} {; Açıklamalar}` (ekrandan, 01:25:00).
  - Operand almayan (`NOP`), tek operandlı (`MUL AX`) ve iki operandlı (`ADD AX, BX`) komutlar vardır. 8086'da üç operandlı komut yoktur.
  - İki operandlı komutta sonuç birinci operanda yazılır: Operand1 ← Operand1 işlem Operand2.
  - Operandlar aynı tipte olmalıdır. `ADD AX, AL` ve `MOV AL, BX` hatalıdır. Belirsiz bellek boyutu `BYTE PTR` ya da `WORD PTR` ile belirtilir.
- Komutlardaki kısaltmalar
  - acc, reg, regb, regw, sreg, mem, idata, disp8 ([-128, 127]) / disp16 ([-32768, 32767]), dest/src (ekrandan, 01:45:00).
- Veri aktarım komutları: MOV, LEA, LDS, LES, XCHG, XLAT/XLATB
  - Veri aktarım komutları bayrakları etkilemez (ekrandan, 01:50:00).
  - MOV kuralları: iki operand birden bellek olamaz, iki operand birden segment yazmacı olamaz, segment yazmacına sabit değer atanamaz, operandlar aynı tipte olmalıdır (ekrandan, 01:55:00).
  - İzin verilen biçimler: `MOV reg, idata`, `MOV mem, idata`, `MOV reg, reg`, `MOV reg, mem`, `MOV mem, reg`, `MOV sreg, reg`, `MOV sreg, mem`, `MOV reg, sreg`, `MOV mem, sreg` (ekrandan, 02:10:00).
  - LEA bir etiketin kendi segmentindeki offsetini (pointer gibi) verir; MOV ise içeriği getirir.
  - LDS/LES bellekten art arda iki word okur: ilki yazmaca, ikincisi DS'ye (ya da ES'ye) yüklenir.
  - XCHG iki operandın içeriğini tek komutta değiştirir.
  - XLAT: `AL ← DS:[BX+AL]`, yani BX'teki tablonun AL numaralı elemanını AL'ye kopyalar (ekrandan, 02:55:00).
- Bellek adresleme kipleri (veri erişimi için)
  - Doğrudan: `[100H]`. Dolaylı: `[BX]`. İndis: `[SI]`, `[DI]`. Baz indis: `[BX+SI]`. Baz göreli, indis göreli ve baz indis göreli: sabit eklenmiş biçimler, örneğin `[BX+SI+5]`.
  - Köşeli parantez içinde veri erişimi için yalnız BX, SI, DI ve sabit kullanılabilir; `[AX]` geçersizdir, `[2*SI]` gibi çarpma yapılamaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- İkiye tümleyen gösterimi bilgisayarlarda işaretli aritmetiğin temelidir.
  - Hoca konuyu önemli olarak işaretledi; diğer iki gösterimdeki çift sıfır sorunu ikiye tümleyende yoktur.
- 8086 little endian'dır.
  - Bellekten word ya da double word okurken byte sırası buna göre kurulur; derste birçok örnek bu kurala dayandı.
- Köşeli parantez içinde veri erişimi için yalnız BX, SI ve DI kullanılır.
  - Hoca "mutlaka aklınızda tutmanız gerekiyor" dedi; `[AX]` yazılamaz.
- Mnemonic doğru yazılmalıdır.
  - `MOV` yerine `MOVE` yazılan satır hatalı sayılır. Hoca komut setini (instruction set) yanınızda bulundurup her komutun kabul ettiği operandları oradan kontrol etmeyi istedi.
- Veri aktarım komutları bayrakları etkilemez.
  - Koşullu dallanmalar bayraklara bakar. Bu yüzden koşulu üreten komut ile dallanma arasına MOV konabilir; akış bozulmaz.
- Operand tip uyumu.
  - Bellek operandının boyutu belirsizse `BYTE PTR` ya da `WORD PTR` mutlaka yazılmalıdır.
- LEA ile MOV arasındaki fark.
  - LEA offset (pointer), MOV içerik döndürür. Hoca bu farkın dizi işlemlerinde sürekli kullanılacağını vurguladı.

## Kısa Tekrar Notları

- İşaretli/işaretsiz ayrımını bit dizisi değil komut yapar.
- 4 bit ikiye tümleyen aralığı: -8 … +7.
- Little endian: düşük anlamlı byte düşük adrese.
- $PA = Segment \times 10H + Offset$; 20 bit adres, 1 MB adres uzayı, segment başına 64 KB.
- CS:IP kod, DS:BX/SI/DI veri, SS:SP/BP yığın.
- SP her `PUSH`ta 2 azalır, yığına yalnız word atılır.
- CF işaretsiz taşma, OF işaretli taşma.
- `MUL AX`: AX × AX, sonuç DX:AX.
- 8086'da en fazla iki açık operand vardır, sonuç birinci operanda yazılır.
- MOV: mem-mem yok, sreg-sreg yok, sreg-idata yok, tip uyumu şart. IP'ye MOV yapılamaz.
- Harfle başlayan onaltılık sabitin başına 0 konur: `0ABCDH`.
- LEA offset verir, MOV içerik verir.
- LDS/LES: ilk word yazmaca, ikinci word DS/ES'ye.
- XLAT: `AL ← DS:[BX+AL]`.
- Veri aktarım komutları bayrak değiştirmez.

## Detaylı Açıklamalar

- **Tekrar: işaretli gösterimler.** 4 bitlik bir sayıda işaretli genlik gösteriminde en yüksek bit işarettir, kalan üç bit genliktir; `1000` "-0" olur. Bire tümleyende negatif sayının genliği kalan bitlerin tümleyenidir; `1111` "-0" olur. İkiye tümleyende negatif sayının genliği ikiye tümleyenle bulunur (bire tümleyen + 1 ya da sağdan ilk 1 dahil olduğu gibi bırakıp gerisini tersleme). Ekrandaki tabloda `1000` ikiye tümleyende -8, `1111` ise -1'dir (ekrandan, 00:05:00).

- **Yazmaçların görevleri.** AX akümülatördür: aynı işlem başka yazmaçla da yapılabilir ama akümülatöre özel kodlamalar daha kısa ve hızlıdır. BX, C'deki `dizi[i]` erişimine benzeyen dolaylı adreslemede adres tutar. CX, `LOOP` komutu için sayaçtır: her adımda CX bir azaltılır, sıfır değilse etikete dallanılır. Kaydırma ve döndürmede en fazla 16 adım anlamlı olduğu için sayaç olarak 8 bitlik CL yeter. EXE tipi programlarda veri, yığın ve kod için üç ayrı segment tanımlanır. Yığın; işletim sistemine ve alt programlardan dönüş adreslerini, alt programa aktarılan parametreleri tutar. Yığının boyutu baştan verilir ve aşılırsa komşu bölgeler bozulabilir. Alt programa girer girmez SP, BP'ye kopyalanır; böylece yığın işlemleri SP'yi değiştirse de parametrelere BP'ye göre sabit uzaklıkla erişilir.

- **Offset memory model.** 16 bitlik segment değeri 10H ile çarpılınca (4 bit sola kaydırılınca) 20 bite çıkar; buna 16 bitlik offset eklenir. Offset 0000H-FFFFH arasında değiştiği için her segment 64 KB'lık bir pencere gösterir. Örnek: DS=1230H, SI=0045H ise fiziksel adres 12300H + 0045H = 12345H olur (ekrandan, 00:30:00).

- **Bayraklar.** CF işaretsiz işlem sonucu yazmaç genişliğine sığmazsa 1 olur; çıkarmada borç bayrağıdır. PF çift eşlikte eşlik biti dahil 1'lerin sayısının çift olmasını sağlar, seri haberleşmede bozulma denetimi için kullanılır. AF alt 4 bitten elde çıktığını gösterir; BCD toplamında sonucu düzeltmek için gerekir. OF işaretli işlemde sonuç sığmazsa 1 olur: 8 bitte 100 + 100 = 200, en büyük pozitif değer 127 olduğu için sonuç negatif bir sayı gibi görünür. İki pozitifin toplamı negatif ya da iki negatifin toplamı pozitif çıkarsa taşma vardır.

- **32/64 bit, real/protected mode ve SIMD.** 32 bitlik yazmaçta AL, AH, AX ve EAX'e erişilebilir; üst 16 bite ulaşmak için EAX 16 bit sağa kaydırılır. 64 bitte RAX/EAX/AX/AL/AH ve R8-R15 vardır; 32 ve 64 bit programlarda SI yerine ESI ya da RSI kullanılır. 8086'nın 20 adres ucu $2^{20}$ = 1 M göz, yani 1 MB adresler; real mode'da program işletim sisteminin alanına da erişip bozabilir. Protected mode'da her programın alanı ve izinleri bir tablodan verilir. Vektör yazmaçları SIMD komutlarıyla aynı işlemi çok sayıda veriye uygular; 512 bitlik yazmaç ZMM, alt 256 biti YMM, alt 128 biti XMM diye adlandırılır.
  <!-- BELİRSİZ: Altyazıda vektör yazmaç adları "x, y, z" olarak geçiyor; XMM/YMM/ZMM olarak yorumlandı. -->

- **Kontrol birimi.** Ekrandaki şemada PC'nin gösterdiği komut instruction memory'den okunur ve instruction decoder'a gider (ekrandan, 01:00:00). Decoder; register file adreslerini (DA, AA, BA), MUX B/MUX D seçimlerini, ALU işlevini seçen 4 bitlik FS'yi, bellek yazma (MW) ve yazmaç yazma (RW) işaretlerini üretir. Hoca örnek olarak `MOV [100], AX` komutunda BA için AX'in adresi, MB için 0, MW için 1 üretildiğini anlattı. Dallanma komutlarında branch control, PC'nin komut boyu kadar mı artacağına, yeni değer mi alacağına ya da görece mi değişeceğine karar verir.

- **Komut yapısı örneği.** Hocanın slayta yazdığı örnek (ekrandan, 01:35:00):

  ```asm
  START: NOP              ; bir işlem yapmaz
         MUL AX           ; AX'in karesini alır
         ADD AX, BX
         ADD AX, [BX+SI+100H] ; DSx10H+(BX+SI+100H), baz + indis + göreli adresleme
         JMP START
  ```

  Bu kod sözdizimi olarak geçerli, algoritma olarak anlamsız bir sonsuz döngüdür. `MUL AX` tek açık operand alır, AX ve DX gizli operanddır; iki 16 bitlik sayının çarpımı 32 bite sığar ve DX:AX'e yazılır. `[BX+SI+100H]` tek bir operand sayılır; burada hesaplanan değer offsettir, 10H ile çarpılan ise DS'dir.

- **Tip belirsizliği: `INC [100H]`.** Bellekte 100H'da FFH, 101H'da 09H olsun (ekrandan, 01:40:00). `INC [100H]` byte mı word mü artırılacağı belli olmadığı için geçersizdir. `INC BYTE PTR [100H]` 100H'daki FFH'yi 00H yapar. `INC WORD PTR [100H]` little endian'a göre 09FFH değerini 0A00H yapar: 100H'a 00H, 101H'a 0AH yazılır. Operand bellek olduğu için değişiklik doğrudan belleğe yazılır.
  - Ders sonrası not: Hoca `INC BYTE PTR [100H]` sonrasında CF=1 olacağını söyledi. Intel belgelerine göre INC komutu CF'yi etkilemez (OF, SF, ZF, AF, PF'yi etkiler); CF=1 sonucu `ADD BYTE PTR [100H], 1` ile elde edilir.

- **MOV kuralları ve çözümleri.** `MOV [100H], [120H]` geçersizdir; önce `MOV AX, [120H]`, sonra `MOV [100H], AX` yazılır. `MOV CS, SS` (sreg-sreg) ve `MOV CS, 100H` (sreg-idata) geçersizdir; sabit önce genel yazmaca alınır (ekrandan, 02:05:00). `MOV AX, AL` tip uyumsuzdur. AX'in düşük byte'ına BL yazmak için `MOV AL, BL` yeterlidir; AH ve BX değişmez. Sabit örnekleri: `MOV DL, 1`, `MOV BX, 0ABCDH`, `MOV AL, 01010101B`, `MOV AH, 'A'` (ekrandan, 02:10:00). `MOV BYTE PTR [100H], 12H` yalnız (DS×10H+100H)'ye 12H yazar; `MOV WORD PTR [100H], 12H` değeri 0012H kabul eder ve 101H'a 00H yazar (ekrandan, 02:15:00). `MOV IP, AX` ve `MOV 12H, BYTE PTR [100H]` geçersizdir (ekrandan, 02:20:00). Segment yazmacı örnekleri: `MOV DS, AX`, `MOV SS, [100H]`, `MOV BX, CS`, `MOV [BX+DI+10H], DS` (ekrandan, 02:30:00).
  - Ders sonrası not: Hoca segment yazmacına sabit atamayı `MOV AX, 100H` ve `MOV CS, AX` ile gösterdi. Intel 8086 belgelerinde CS, MOV komutunun hedefi olamaz; CS büyük olasılıkla yalnız uzak JMP/CALL/RET ve kesmelerle değişir. Aynı yöntem DS, ES ve SS için geçerlidir (`MOV DS, AX`).

- **emu8086 denemeleri.** `MOV CX, [SI+5]` geçerlidir. `[AX]` "wrong parameter" hatası verir. `[2*SI]` yazıldığında emu8086 bunu sessizce `[SI+2]`'ye çevirir; bu nedenle çarpma ayrı komutla yapılır (ekrandan, 02:25:00):

  ```asm
  MOV DX, [SI]
  SHL SI, 1      ; SI = 2*SI
  MOV CX, [SI]
  ```

  Sola bir bit kaydırma 2 ile çarpmadır. Bu yöntem yalnız kaydırmada taşma oluşmayan küçük SI değerleri için anlamlıdır.

- **LEA ve MOV.** Veri segmentinde `Mydata DD 12345678H` tanımı 100H'dan başlarsa bellek 100H: 78H, 101H: 56H, 102H: 34H, 103H: 12H olur (ekrandan, 02:40:00). `MOV AX, [100H]` AX'e 5678H, `LEA AX, Mydata` ise 100H yükler. `LEA BX, Mydata` ve ardından `MOV AL, [BX+3]` AL'ye 103H'daki 12H'yi getirir; C'deki pointer aritmetiğine benzer. `MOV AX, [BX+3]` ise 103H ve 104H'daki iki byte'ı okur; hoca 104H'daki byte'ı AAH alarak sonucu 0AA12H diye verdi.

- **LDS/LES.** Aynı bellekte `LDS SI, [100H]` SI'ya 5678H, DS'ye 1234H yükler (ekrandan, 02:50:00). `LES` aynı işi ES ile yapar. Katar işlemlerinde kaynak DS:SI, hedef ES:DI olduğu için bu komutlarla adresler tek seferde ilklenebilir. Hoca bir kullanım yeri olarak belleğin en düşük adreslerindeki kesme vektör tablosuna erişimi gösterdi.

- **XCHG ve XLAT.** AX=1234H, BX=ABCDH iken `XCHG AX, BX` sonrası AX=ABCDH, BX=1234H olur; C'de geçici değişkenli üç işlem gereken takas tek komuttur. XLAT için tablo örneği (ekrandan, 02:55:00):

  ```asm
  Dizi DB 1,2,3,4,5,6,7,8
  N    DB 8
  ...
  LEA BX, Dizi
  MOV AL, 5
  XLAT          ; AL <-- DS:(BX+5)
  ```

  İndis 0'dan başladığı için 5 numaralı eleman 6'dır, AL=6 olur. XLAT, yedi parçalı gösterge kodları gibi önceden hesaplanmış bir arama tablosundan (lookup table) değer almak için kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
