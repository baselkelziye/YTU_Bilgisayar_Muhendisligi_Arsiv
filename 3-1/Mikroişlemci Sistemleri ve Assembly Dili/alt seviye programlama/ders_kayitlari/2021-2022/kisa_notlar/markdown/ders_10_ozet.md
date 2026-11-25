# Ders 10 Çalışma Özeti

## Genel Konular

- EXE tipi program iskeletinin tekrarı (ekrandan, 00:10:00, 00:20:00)
  - Program üç kesimle tanımlanır: yığın (`STSG SEGMENT PARA STACK 'STSGM'`, `DW 20 DUP (?)`), veri (`DTSG SEGMENT PARA 'DTSGM'`) ve kod (`CDSG SEGMENT PARA 'CDSGM'`). Kesim adları ve sınıf adları programcının verdiği adlardır; `SEGMENT`, `PARA`, `STACK`, `ENDS` sabit sözde komutlardır.
  - `PARA` hizalaması yüzünden işletim sistemi her kesimi bir sonraki 16'nın tam katı adresten başlatır.
  - Bir kesimi yığın kesimi yapan şey `STACK` sözcüğüdür; program yüklenince SS bu kesimi gösterir.
  - Bir kesimi kod kesimi yapan şey, `END` sözcüğünden sonra yazılan giriş noktası etiketinin (`END ANA`) o kesimin içinde olmasıdır; yüklenince CS orayı gösterir.
  - Veri kesimi yüklenir yüklenmez DS tarafından gösterilmez. İşletim sistemi DS'ye dönülecek kesim değerini koyar ve "bu kesimin 0 ofsetine dön" bilgisini verir.
  - Ana yordam `ANA PROC FAR` olarak tanımlanır ve `RETF` ile biter. Yakın `RET` yığından yalnız IP'yi, `RETF` önce IP'yi sonra CS'yi çeker.
  - İlk üç satır dönüş adresini yığına koyar: `PUSH DS` / `XOR AX, AX` / `PUSH AX`. `PUSH 0` diye bir komut olmadığı için 0 değeri AX üzerinden atılır.
  - Sonraki iki satır veri kesimini DS'ye bağlar: `MOV AX, DTSG` / `MOV DS, AX`. Kod bunlardan sonra yazılır.
- Örnek 1: iki 32 bitlik sayının 64 bitlik sonuca toplanması (ekrandan, 00:25:00, 00:35:00, 00:45:00)
  - Veri: `ASAY DD 0ABCDEF98H`, `BSAY DD ...`, `SONUC DQ 0`. 32 bit için `DD` (define double word), 64 bit için `DQ` kullanılır.
  - Sayılar 16 bitlik iki parçaya bölünerek toplanır: düşük parçalar `ADD` ile, yüksek parçalar `ADC` ile toplanır; son elde `ADC WORD PTR [BX+4], 0` ile sonucun 33. bitine yazılır.
  - Parçalara erişmek için `LEA SI, ASAY`, `LEA DI, BSAY`, `LEA BX, SONUC` kullanıldı. Veri little endian saklandığı için en düşük adres en düşük anlamlı byte'tır; bir sonraki word `+2` ofsettedir.
  - `ADD [SI], [DI]` yazılamaz: iki bellek operandı tek komutta kullanılamaz. Önce `MOV AX, [SI]`, sonra `ADD AX, [DI]` yazılır.
  - `MOV` bayrakları etkilemediği için ilk toplamadan çıkan elde, aradaki `MOV` komutlarından geçip `ADC`'ye kadar korunur.
  - DEBUG'da derlenen veriyle (`BSAY = 0B9876543H`) sonuç bellekte `DB 54 55 65 01 00 00 00` olarak görüldü: $ABCDEF98_h + B9876543_h = 1\,6555\,54DB_h$.
- Örnek 2a: 300 elemanlı, negatif olmayan byte dizisinin ortalaması (ekrandan, 01:05:00, 01:25:00, 01:30:00)
  - Aralık analizi: en büyük toplam $300 \cdot 255 = 76500$; 16 bite sığmaz, 17 bite sığar. Toplam 32 bitlik DX:AX'te biriktirilir. Ortalama en çok 255 olduğu için sonuç byte'tır.
  - İşaretli olsaydı $-128 \cdot 300 = -38400$ de 16 bitlik işaretli aralığa sığmazdı.
  - Diziye indis yaklaşımıyla erişilir: `DIZI[SI]`, SI = 0, 1, 2, ... C'deki `dizi[i]` gibidir; makine kodunda `[SI + DIZI'nin ofseti]` olur. SI `XOR SI, SI` ile sıfırlanır.
  - Döngü: `ADC AL, DIZI[SI]` / `ADC AH, 0` / `ADC DX, 0` / `INC SI` / `LOOP L1`. Döngüden önce `XOR AX, AX`, `XOR DX, DX` ve `CLC`.
  - Döngü bitince SI = 300 = N olduğu için doğrudan `DIV SI` yazılır; bölüm AX'e, kalan DX'e düşer. AH kesinlikle 0 çıkar, ortalama `MOV ORT, AL` ile yazılır.
  - Deneme verisi `10, 20, 30, 40, 50` ve 295 tane `255`: toplam $75375 = 1266F_h$ (DX = 1, AX = 266F), ortalama $251 = FB_h$.
- Örnek 2b: 200 elemanlı word dizisinin ortalaması (ekrandan, 01:40:00)
  - $200 \cdot FFFF_h$ yine 32 bite sığar; biriktirme DX:AX'te kalır. Ortalama word olur.
  - Döngü: `ADC AX, DIZI[SI]` / `ADC DX, 0` / `ADD SI, 2` / `LOOP L1`. Çıkışta SI = 400 olur; `SHR SI, 1` ile 200'e indirilip `DIV SI` yapılır.
  - Deneme verisi `10, 20, 30, 40, 50` ve 195 tane `0FFFFH`: toplam $C2FFD3_h$, ortalama $F999_h$.
- Örnek 3: en büyük ortak bölen (EBOB, GCD) (ekrandan, 01:50:00, 01:55:00, 02:00:00)
  - Kural: $\gcd(A, B) = \gcd(B, A \bmod B)$, $\gcd(A, 0) = A$. Örnek: $\gcd(20, 16) = \gcd(16, 4) = \gcd(4, 0) = 4$.
  - A < B ise önce `XCHG AX, BX` ile yer değiştirilir. Bu if-null-then yapısıdır; koşul boş kola göre (`JAE NOSWAP`) yazılınca tek koşullu dallanma yeter.
  - While döngüsü: `CMP BX, 0` / `JE CIKIS` / `XOR DX, DX` / `DIV BX` / `MOV AX, BX` / `MOV BX, DX` / `JMP NOSWAP`. Kalan DX'tedir. Çıkışta sonuç AX'tedir, `MOV GCD, AX` ile yazılır.
  - DEBUG'da (20, 16) → 4, (16, 20) → 4 (önce yer değiştirir), (20, 1) → 1 ve aralarında asal (23, 7) → 1 denendi.
- Örnek 4: vücut kitle indeksi (BMI) dizisi (ekrandan, 02:25:00, 02:30:00, 02:40:00)
  - Formül: $BMI = \dfrac{w_{lb}}{h_{in}^2} \cdot 703$. Ağırlık (pound) word dizisi, boy (inç) byte dizisi, BMI word dizisi.
  - Önce 703 ile çarpılır, sonra bölünür; tersi tamsayı bölmede sonucu 0, 1, 2 gibi değerlere indirip hassasiyeti yok eder.
  - Byte ve word dizisine tek indisle erişim: `SHL SI, 1` ile word indisine geçilir, `SHR SI, 1` ile geri dönülür, sonra `INC SI`.
  - Döngü: `MOV AL, BOY[SI]` / `MUL AL` / `MOV BX, AX` / `SHL SI, 1` / `MOV AX, AGIR[SI]` / `MUL DI` (DI = 703) / `DIV BX` / `MOV BMI[SI], AX` / `SHR SI, 1` / `INC SI` / `LOOP L1`.
  - İlk kişi: boy 80, ağırlık 300 → $300 \cdot 703 = 337D4_h$, $80^2 = 1900_h$, BMI $= 20_h = 32$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Instruction set tablosunu okumayı bilmek
  - Bir komutun hangi tipe (immediate, yazmaç, bellek, dolaylı adresleme) girdiğini ve boyutunu tablodan bulabilmek gerekir. Kendi tahmininizi DEBUG'daki `U` (unassemble) çıktısı ya da LST dosyasıyla karşılaştırarak alıştırma yapın; örneğin `XOR AX, AX` → `33C0`.
- İki bellek operandı aynı komutta kullanılamaz
  - İşlemci veri yolu üzerinden bir anda tek birimle konuşur; birinci değer önce yazmaca alınır.
- Elde (carry) zinciri
  - Çok parçalı toplamada ara elde kaybedilmemelidir. `MOV`, `INC` ve `LOOP` bayrakları etkilemez; bu yüzden elde `ADC`'ye kadar taşınır. Etkileseydi `PUSHF/POPF` ya da ara yazmaçla saklamak gerekirdi.
- Önce aralık analizi
  - Biriktirici ve sonuç değişkeninin boyutu (byte, word, DX:AX) yazmadan önce en kötü durum hesaplanarak seçilir.
- Önce çarp, sonra böl
  - 8086 tamsayı çarpma ve bölmesi yapar; önce bölmek hassasiyet kaybettirir. Ayrıca `MUL` sonucu DX:AX'te oluştuğu için ardından gelen `DIV` için girdi hazır olur.
- Yazmaç yapısını bilmek
  - AX, BX, CX, DX'in düşük/yüksek yarılarına (AL/AH, ...) ayrı erişilir; SI, DI ve kesim yazmaçlarına yalnız 16 bit olarak erişilir.

## Kısa Tekrar Notları

- EXE iskeleti: `PUSH DS` / `XOR AX, AX` / `PUSH AX` / `MOV AX, DTSG` / `MOV DS, AX` / ... / `RETF`.
- `STACK` sözcüğü yığın kesimini, `END <giriş etiketi>` kod kesimini belirler.
- `DD` 32 bit, `DQ` 64 bit tanımlar.
- Çok parçalı toplama: ilk parça `ADD`, sonrakiler `ADC`; son elde `ADC WORD PTR [..], 0`.
- Bellekten belleğe toplama yok; önce yazmaca al.
- Byte dizisi toplamında `ADC AL, ...` / `ADC AH, 0` / `ADC DX, 0` zinciri, döngüden önce `CLC`.
- `[CX]` diye adresleme yoktur; indis için SI, DI, BX kullanılır.
- `DIZI[SI]` = `[SI + DIZI ofseti]`; word dizisinde indis 2'şer artar.
- `DIV` öncesi DX mutlaka belirlenmeli (`XOR DX, DX`).
- `XCHG` ile geçici değişkensiz yer değiştirme.
- Boş kolu olan if yapısında koşul boş kola göre yazılır, tek dallanma yeter.
- `SHL SI, 1` / `SHR SI, 1` ile byte ve word dizisine aynı indisle erişim.
- `MUL` ve `DIV` sabit (immediate) operand almaz; 703 önce DI'ye konur.

## Detaylı Açıklamalar

- **EXE iskeleti neden böyle?** İşletim sistemi EXE programı çağırırken dönüş işini programa bırakır. DS'de dönülecek kesimin değeri vardır ve dönüş ofseti 0'dır. Program bu iki değeri yığına koyar (önce DS, sonra 0). En sondaki `RETF` yığından ilk 0'ı IP'ye, sonra DS'nin eski değerini CS'ye alır ve işletim sistemine döner. Bundan sonra `MOV AX, DTSG` / `MOV DS, AX` ile kendi veri kesimimiz DS'ye bağlanır. Kesim değeri doğrudan DS'ye yazılamadığı için AX üzerinden geçilir.
- **Örnek 1 kodu** (kesim tanımları iskeletle aynıdır):

```asm
DTSG SEGMENT PARA 'DTSGM'
        ASAY  DD 0ABCDEF98H
        BSAY  DD 0B9876543H
        SONUC DQ 0
DTSG ENDS
...
        LEA SI, ASAY
        LEA DI, BSAY
        LEA BX, SONUC
        MOV AX, [SI]
        ADD AX, [DI]
        MOV [BX], AX
        MOV AX, [SI+2]
        ADC AX, [DI+2]
        MOV [BX+2], AX
        ADC WORD PTR [BX+4], 0
        RETF
```

<!-- BELİRSİZ: Örnek 1'in toplama satırlarının tamamı tek karede görünmüyor; satırlar anlatımdan ve DEBUG karesindeki `[BX+02],AX` ile `WORD PTR [BX+04],+00` satırlarından kuruldu. BSAY editörde 0EF987654H görünüyor; derlenip çalıştırılan sürümde bellekteki değer B9876543h idi. -->

- `ADD AX, [DI]` satırında `WORD PTR` gerekmez, çünkü AX işlemin word olduğunu belirtir. `ADC WORD PTR [BX+4], 0` satırında ise iki operanddan hiçbiri boyut belirtmediği için `WORD PTR` zorunludur. `SONUC` sıfırla başlatıldığı için son satır o word'e yalnız eldeyi (0 ya da 1) ekler. İki 32 bitlik sayının toplamı en çok 33. bite taşar, daha ötesine taşamaz.
- **Örnek 2a kodu** (ekrandan, 01:25:00, 01:30:00):

```asm
        MOV CX, N
        XOR SI, SI
        XOR AX, AX
        XOR DX, DX
        CLC
L1:     ADC AL, DIZI[SI]
        ADC AH, 0
        ADC DX, 0
        INC SI
        LOOP L1
        ; DX:AX <- sum (DIZI)
        DIV SI        ; AX <- DX:AX / SI, DX <- kalan
        MOV ORT, AL
        RETF
```

- Veri: `DIZI DB 10, 20, 30, 40, 50, 295 DUP (255)`, `N DW 300`, `ORT DB 0`. N, CX'e yükleneceği için word tanımlandı. DEBUG'da `MOV CX, [012C]` satırı N'nin 300 = 12Ch ofsetinde olduğunu gösterir. Bellek dökümünde 12Ch'den itibaren önce N (`2C 01`), sonra ORT (`FB`) görüldü; ardından gelen 0, sonraki kesimin `PARA` hizalaması için bırakılan dolgu byte'ıdır.

<!-- BELİRSİZ: Veri tanımının karesi okunmadı; değerler anlatımdan alındı (01:10:18-01:11:24). -->

- `ADC AL, DIZI[SI]` satırında `ADD` yerine `ADC` kullanılmasının nedeni genel bir ara adımda önceki toplamadan elde kalmış olabilmesidir; ilk adım için de `CLC` ile CF sıfırlanır. `ADC AX, DIZI[SI]` yazılamaz (byte dizisi ile word yazmaç uyuşmaz); `WORD PTR` ile zorlanırsa yan yana iki elemanı tek word gibi toplayan bir mantık hatası doğar.
- Python ile adım adım kontrol: toplam $150 + 295 \cdot 255 = 75375 = 1266F_h$, $75375 / 300 = 251$ kalan $75$; $251 = FB_h$. Derste DEBUG ekranında da DX = 0001, AX = 266F ve bölmeden sonra AL = FB, AH = 00 görüldü.
- **Örnek 2b**: dizi `DW` tanımlanır, 195 tane `0FFFFH` konur, ORT word olur. `ADC AH, 0` satırı kaldırılır, `INC SI` yerine `ADD SI, 2` yazılır. Döngüden çıkışta SI = 400 = 190h olur; `SHR SI, 1` ile 200'e iner. Sonuç `MOV ORT, AX` ile yazılır. Python kontrolü: $150 + 195 \cdot 65535 = 12779475 = C2FFD3_h$, $/200 = 63897 = F999_h$. Bellekte 190h ofsetinde önce N (`00C8`), sonra ORT (`F999`) görüldü.

> **Ders sonrası not:** 01:40:00 karesinde editörde `MOV ORT, AL` satırı henüz değiştirilmemiş görünüyor. Hoca anlatımda sonucun tamamının AX'te olduğunu ve ORT word olduğu için AX'in yazılması gerektiğini söyledi; doğru satır `MOV ORT, AX`'tir.

- **Örnek 3 kodu** (anlatımdan ve DEBUG karesinden kuruldu):

```asm
        MOV AX, ASAY
        MOV BX, BSAY
        CMP AX, BX
        JAE NOSWAP
        XCHG AX, BX
NOSWAP: CMP BX, 0
        JE CIKIS
        XOR DX, DX
        DIV BX          ; DX <- AX mod BX
        MOV AX, BX
        MOV BX, DX
        JMP NOSWAP
CIKIS:  MOV GCD, AX
        RETF
```

<!-- BELİRSİZ: GCD kodunun tam metni karede okunmadı. 02:00:00 DEBUG karesinde `CMP BX,+00` (0015), `JZ 0024`, `MOV AX,BX` (001E), `MOV BX,DX` (0020), `JMP 0015` (0022) görülüyor; etiket adları (NOSWAP, CIKIS) altyazıdan alındı. Komut uzunluklarına göre `XCHG` 0014 adresindedir ve dallanma hedefi `CMP BX, 0` satırıdır. -->

- `DIV BX` DX:AX'i böler; DX önceden sıfırlanmazsa önceki turdan kalan değer bölümü bozar (taşma bile olabilir). Python ile kontrol: (20, 16) → (16, 4) → (4, 0) → 4; (23, 7) → (7, 2) → (2, 1) → (1, 0) → 1. Aralarında asal sayılar en fazla döngü adımını üretir.
- **Örnek 4 kodu** (ekrandan, 02:30:00, 02:35:00):

```asm
        XOR SI, SI
        MOV CX, N
        MOV DI, 703
L1:     MOV AL, BOY[SI]
        MUL AL          ; AX <- AL^2 = h^2
        MOV BX, AX
        SHL SI, 1
        MOV AX, AGIR[SI]
        MUL DI          ; DX:AX <- w * 703
        ;DX:AX/h^2
        DIV BX          ; AX <- w*703/h^2, DX <- kalan
        MOV BMI[SI], AX
        SHR SI, 1
        INC SI
        LOOP L1
        RETF
```

<!-- BELİRSİZ: Döngüden önceki satırların sırası (XOR SI, SI ve MOV CX, N) DEBUG anlatımından (02:38:29) alındı; veri tanımlarının tamamı karede okunmuyor (200 kişilik diziler, ilk boy 80, ilk ağırlık 300). -->

- Derlenip çalıştırılan sürümde L1'in ilk satırı `XOR AX, AX` idi (02:30:00 ve 02:45:00 karelerinde görülüyor). Hoca bu satırın gereksiz olduğunu söyleyip kaldırdı: `MOV AL, BOY[SI]` / `MUL AL` AH'ı zaten belirler.
- DEBUG'da AGIR dizisinin ofseti C8h (BOY'un 200 byte'ından sonra), BMI dizisininki 25Ah görüldü. Python kontrolü: $80^2 = 6400 = 1900_h$, $300 \cdot 703 = 210900 = 337D4_h$ (DX = 0003, AX = 37D4), $210900 / 6400 = 32 = 20_h$, kalan $6100 = 17D4_h$; DEBUG ekranındaki değerlerle aynıdır.
- `BMI[SI]` yazımı makine kodunda `[SI + 025A]` olur; köşeli parantez içindeki her şey adrestir. Word dizisinde SI 1 artırılırsa birinci word'ün yüksek byte'ı ile ikinci word'ün düşük byte'ı birleşik okunur; bu yüzden indis 2 ile çarpılır. Her diziye ayrı indis yazmacı (SI, DI, BX) vermek de doğru bir çözümdür; tek indis yöntemi, elemanlara sırasız erişilen problemlerde işe yarar.
- Assembler ve emülatör bu ortamda kurulu olmadığı için kodlar derlenmedi; sayısal sonuçlar python ile kontrol edildi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
