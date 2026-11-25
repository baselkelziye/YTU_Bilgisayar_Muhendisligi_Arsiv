# Ders 12 Genişletilmiş Notu: Yordamlar (NEAR/FAR, CALL/RET, Yazmaçla Parametre Aktarma) ve Makrolar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yordam Tanımları
- 2. CALL ve RET: NEAR Yordamın Çalışması
- 3. Örnek 1: Üs Alma Yordamı (EXE, Yazmaçla Parametre Aktarma)
- 4. Yordamda Yazmaçların Korunması
- 5. Örnek 1'in DEBUG ile İzlenmesi
- 6. FAR Yordamlar, EXTRN ve PUBLIC
- 7. Örnek 2: Ayrı Dosyadaki FAR Toplama Yordamı
- 8. Makrolar
- 9. Örnek 3: Diziyi Yarıya Bölen Ana Yordam ve En Küçük Elemanı Bulan Makro (COM)
- 10. Çağrılan Yordamın Veri Kesimine Erişimi
- Örnek Sorular

## 1. Yordam Tanımları

Önceki derste COM tipi programlar işlenmiş ve EXE tipiyle karşılaştırılmıştı. Bu noktaya kadar programlarda tek bir yordam (ana yordam) kullanıldı. Bu derste bir kod kesiminde birden fazla yordamın nasıl yazıldığı, nasıl çağrıldığı ve nelere dikkat edilmesi gerektiği işlendi.

Yordam bir kod parçası olduğu için kod kesiminin içine yazılır. Yazım biçimi şöyledir (ekrandan, 00:15:00):

```text
yordam_ismi   PROC   FAR | NEAR
              ...            ; yordamın kodu
              RETF | RET
yordam_ismi   ENDP
```

- `FAR` yordam **intersegment**, yani kesimler arası dallanma içindir. `RETF` ile biter.
- `NEAR` yordam **intrasegment**, yani kesim içi dallanma içindir. `RET` ile biter.

Bir kod kesiminin içine istenildiği kadar yordam yazılabilir; örneğin ana yordamın altına `yordam2 PROC NEAR` ... `RET` ... `yordam2 ENDP` eklenir, en sonda kesim `ENDS` ile kapatılır. Tek kısıt, kesimin 64 KB'lık alanına sığmaları ve taşmamalarıdır.

Bir yordamı çağırmak için, NEAR ya da FAR olsun, `CALL` mnemoniği kullanılır: `CALL yordam_ismi`.

## 2. CALL ve RET: NEAR Yordamın Çalışması

Hoca çalışma mantığını şu şemayla anlattı (ekrandan, 00:20:00):

```text
ANA    PROC FAR
       PUSH DS
       ...
       CALL ustal   ---------------------+
       ...   <-- dönüş noktası           |
       RETF                              |
ANA    ENDP                              |
ustal  PROC NEAR   <---------------------+
       MOV ...     (yordamın ilk komutu)
       ...
       RET  ---> yığından dönüş ofsetini alıp CALL'dan sonraki satıra döner
ustal  ENDP
```

Akış `CALL ustal` satırına geldiğinde program, sanki bir `JMP` komutu varmış gibi `ustal` yordamının ilk komutunun ofsetine dallanır. Dallanmadan önce bir iş daha yapar: CALL'dan hemen sonraki satırın ofsetini, yani **dönüş adresini**, yığına atar. Şemada yığın 15..0 bitlik tek bir word gözü olarak gösterildi ve içine "offset" yazıldı.

Yordam çalışıp `RET` komutuna gelince yığının tepesindeki değer, yani o dönüş ofseti alınır ve akış oraya, CALL'dan sonraki satıra döner. Bir yordam bir ana yordam içinden n kez çağrılabilir; döngü içinde ya da farklı satırlardan. Her seferinde dallanılır, yordam çalışır ve geri dönülür. NEAR yordamda yığına atılan tek değer dönüş ofsetidir; FAR yordamda bir değer daha atılır (Bölüm 6).

## 3. Örnek 1: Üs Alma Yordamı (EXE, Yazmaçla Parametre Aktarma)

### 3.1 Problem ve akış

Amaç bir sayının üssünü alan bir yordam yazmaktır. Örnek olarak `sayi = 2`, `ust = 10` için $2^{10} = 1024$ bulunacaktır. Akış diyagramı şöyle çizildi (ekrandan, 00:35:00):

```text
START
  -> sayi, ust (giriş)
  -> ustal(sayi, ust) yordamı çağrılır; sonuç yazmaçla döner
  -> sonuc (çıktı)
STOP
```

Hoca parametre aktarmanın birçok yöntemi olduğunu, bu derste yalnız ilkinin, yani **yazmaç üzerinden parametre aktarmanın** işleneceğini, diğerlerinin sonraki derste görüleceğini söyledi. Program EXE tipinde yazıldı; sonraki örneklerden biri COM tipinde yazılacaktı.

### 3.2 Yığının genişliği

Yığın kesimi `DW 20 DUP(?)` ile tanımlandı. Hoca bu noktada sık yapılan bir hatayı düzeltti: bazı öğrenciler yığını `DB` ile tanımlarsa `PUSH AL` gibi byte değerleri yığına atabileceklerini düşünmüştü.

> **Hocanın vurgusu:** Yığını byte, word, double word ya da quad word olarak tanımlamanız fark etmez; yığının genişliği bir word'dür. 40 byte'lık bir yığın ile 20 word'lük bir yığın arasında boyut ve genişlik açısından hiçbir fark yoktur. Yığına her seferinde bir word atılır.

### 3.3 Değişkenlerin tipi

İlk taslakta `sayi DB 2`, `ust DB 10` yazıldı; sonuç ise $1024$ byte'a sığmadığı için `sonuc DW ?` oldu. Kod yazıldıkça tipler düzeltildi:

- `ust` döngü sayacı olarak CX'e alınacaktır: `MOV CX, ust`. CX word, `ust` byte olursa tip uyuşmaz. Bazı öğrencilerin yaptığı gibi `ust`u byte bırakıp `XOR CX, CX` / `MOV CL, ust` yazmak yerine `ust`u `DW` yapmak hem daha basit hem de bir byte daha harcayarak daha verimlidir.
- `sayi` da BX ile çarpılacağı için (Bölüm 3.5) `DW` yapıldı.

### 3.4 Yazmaçla parametre aktarma

Ana yordamda `MOV CX, ust` ve `MOV BX, sayi` yazıldıktan sonra `CALL ustal` çağrılır. Yazmaçlar işlemcinin içindeki donanım birimleridir; her yordam için ayrı bir yazmaç takımı yoktur. Bu yüzden değerleri yazmaçlara yerleştirip CALL ile yordama dallanınca yordam aynı değerleri aynı yazmaçlarda bulur. Sonuç da yazmaçla döner: yordam sonucu AX'e koyar, ana yordam CALL'dan sonra `MOV sonuc, AX` yazar.

> **Hocanın vurgusu:** Buna yazmaç üzerinden parametre aktarma denir. Yazmaç sayısı sınırlı olduğu için (yaklaşık 8-10 yazmaç) bu yöntemle aktarılabilecek parametre sayısı da sınırlıdır. 50-100 parametre gerektiren durumlar için başka yöntemler vardır.

### 3.5 Üs alma algoritması ve 8 bitlik çarpmanın yetersizliği

Bir sayının 10. kuvveti, 10 tane 2'nin çarpılmasıdır. Sonucu tutan yazmaç önce 1 yapılır (çarpmanın etkisiz elemanı), sonra döngüde 10 kez 2 ile çarpılır: $1\cdot2 = 2$, $2\cdot2 = 4$, ... Döngü sayacı CX'tedir.

İlk akla gelen `MUL BL` komutudur: $AX \leftarrow AL \cdot BL$. Hoca bunun nasıl çalıştığını AH | AL tablosuyla gösterdi (ekrandan, 00:35:00, 00:40:00). AL'de sırasıyla 2, 4, 8, 16, 32, 64 oluşur ve AH 0 kalır. Taşma olunca AH 1, AL 0 olur. Bir sonraki adımda yine AL ile çarpıldığı için $0 \cdot 2 = 0$ çıkar ve sonuç AX'e yazıldığı için AH de sıfırlanır. Bundan sonra her adımda sonuç 0 kalır.

> **Ders sonrası not:** Hoca taşmanın 64 · 2 = 128 adımında olduğunu, AL'nin en çok 127 tutabileceğini söyledi ve tabloda 128 satırına AH = 1, AL = 0 yazdı. `MUL` işaretsiz çarpmadır; AL 255'e kadar değer tutar ve 128 = $0080_h$ AL'ye sığar. Taşma bir sonraki adımda olur: $128 \cdot 2 = 256 = 0100_h$, AH = 1, AL = 0. Ardından $0 \cdot 2 = 0$ ile AX tamamen 0'a iner (python ile adım adım kontrol edildi). Varılan sonuç değişmez: $2^{10}$ 8 bitlik çarpımla bulunamaz.

Bu yüzden 16 bitlik çarpma kullanılır: `MUL BX` ile $DX:AX \leftarrow AX \cdot BX$. En büyük sonuç $2^{10} = 1024$ AX'e sığdığı için DX hep 0 kalır. Sayının BX'te olması gerektiği için ana yordamda `MOV BX, sayi` yazıldı ve `sayi` word yapıldı.

### 3.6 Kod

Dersin sonunda editörde görülen hali (ekrandan, 00:50:00):

```asm
mys     SEGMENT PARA STACK 's'
        DW 20 DUP(?)
mys     ENDS
myd     SEGMENT PARA 'd'
sayi    DW 2
ust     DW 10
sonuc   DW ?
myd     ENDS
myc     SEGMENT PARA 'c'
        ASSUME CS:myc, DS:myd, SS:mys
ANA     PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, myd
        MOV DS, AX

        MOV CX, ust
        MOV BX, sayi
        CALL ustal
        MOV sonuc, AX

        RETF
ANA     ENDP
ustal   PROC NEAR
        PUSH CX
        PUSH DX
        MOV AX, 1
L1:     MUL BX              ; AX * BX -> DX:AX;
        LOOP L1
        POP DX
        POP CX
        RET
ustal   ENDP
myc     ENDS
        END ANA
```

## 4. Yordamda Yazmaçların Korunması

Hoca durumu bir iş bölümüyle anlattı: ana yordamı bir mühendis yazmış, `ustal` yordamını ise başka bir geliştiriciye alt iş paketi olarak vermiştir. Bu geliştirici üst tarafta hangi yazmaçların ne için kullanıldığını bilmez; yalnız BX ve CX'ten değerleri alacağını ve sonucu AX'te vereceğini bilir. O hâlde yordamın içinde değerini bozduğu her yazmacı girişte yığına atmalı, çıkışta geri almalıdır.

Yazmaçlar tek tek incelendi:

- **BX:** Başta 2'dir, RET'ten önce de 2'dir. Sonuç BX'te oluşmaz, değer bozulmaz; saklanmasına gerek yoktur.
- **CX:** Başta 10'dur, LOOP ile 0'a iner. Bozulduğu için girişte `PUSH CX`, çıkışta `POP CX` yazılır.
- **AX:** Sonuç AX'te döneceği için AX'in değişeceği zaten bilinmektedir. Çağıran taraf sonucu AX'ten alacağını bilir; AX saklanmaz.
- **DX:** Hoca derste hangi yazmacın daha saklanması gerektiğini sordu; bir öğrenci DX dedi. DX'in başlangıç değeri bilinmez, ama `MUL BX` onu 0 yapar. Bu yüzden `PUSH DX` / `POP DX` eklenir.

POP sırası PUSH sırasının tersidir: önce `PUSH CX`, sonra `PUSH DX` yapıldıysa önce `POP DX`, sonra `POP CX` yazılır. Yığın LIFO (son giren ilk çıkar), aynı anlamda FILO (ilk giren son çıkar) çalışır.

**Soru:** DX çarpma işleminde zaten 0 oluyor; onu yığına atmaya gerek var mıydı? (derste sözlü, 00:49:18)
**Cevap:** Evet. Ana yordamın tamamını gördüğümüz için DX'in kullanılmadığını düşünüyoruz. Ama gerçek bir projede yordamı yazan, onu çağıracak kodu (belki 10 yıl sonra yazılacak kodu) bilmez. Çağıran taraf örneğin `MOV DX, 2` yapıp yordamdan dönünce `CMP DX, AX` yapıyor olabilir; dönüşte DX 0 olduğu için karşılaştırma bozulur. Yordamda kullanılan yazmaçları önce yığına atmak, iş bitince geri almak bir alışkanlık olmalıdır.

> **Hocanın vurgusu:** Bir prosedür yazdığınızda, prosedürün içinde kullandığınız yazmaçları önce yığına atıp sonra yığından geri almanız beklenir.

**Soru:** Burada sonucun AX'e sığacağını varsaydık, değil mi? Üs büyürse (örneğin 20) sonuç sığmaz. (derste sözlü, 00:51:17)
**Cevap:** Evet, örnekteki sınır değerler için sonucun AX'e sığacağı varsayıldı. Daha büyük değerler için sonucun tipi, sığacağı kadar büyütülmelidir: double word (4 byte, `DD`), quad word (8 byte, `DQ`), hatta 10 byte (`DT`).

## 5. Örnek 1'in DEBUG ile İzlenmesi

Program DOSBox'ta MASM ile derlendi, LINK ile bağlandı ve DEBUG ile açıldı. `U` (unassemble) çıktısında yordam bölümü şöyle görüldü (ekrandan, 00:45:00):

```text
079C:0011 E80400    CALL  0018
079C:0014 A30400    MOV   [0004],AX
079C:0017 CB        RETF
079C:0018 51        PUSH  CX
079C:0019 52        PUSH  DX
079C:001A B80100    MOV   AX,0001
079C:001D F7E3      MUL   BX
079C:001F E2FC      LOOP  001D
079C:0021 5A        POP   DX
079C:0022 59        POP   CX
079C:0023 C3        RET
```

`CALL ustal` satırı `CALL 0018` olarak görünür: NEAR yordam olduğu için assembler yordam adını, dallanılacak ofsete çevirmiştir; 0018 `PUSH CX` satırıdır. CALL komutu 0011'de ve 3 byte olduğu için bir sonraki komutun ofseti 0014'tür; dallanma anında yığına 0014 atılır.

Adım adım izleme:

- `D DS:0` ile veride 2 ve 10 (0A) görülür. `G` ile program çalıştırılınca sonuç ofset 4'te düşük byte önce olmak üzere `00 04` olarak, yani $0400_h = 1024$ görülür.
- Yeniden yüklenip `T` (trace) ile ilerlenir: CX'e belleğin 2. ofsetindeki 10 (000A), BX'e 0. ofsetteki 2 alınır. Yığında başlangıçta `PUSH DS` ile atılan değer ve `PUSH AX` ile atılan 0 bulunur; SP = 0024'tür.
- CALL çalışınca IP = 0018, SP = 0022 olur; `D SS:22` ile yığında 0014 görülür.
- `PUSH CX` ile SP azalır; `D SS:20` ile orada CX'in değeri A görülür. `PUSH DX` ile 0 atılır, SP bir word daha azalır.
- `MOV AX, 1` ile AX = 0001; döngüde AX 2, 4, 8, ... olur. Döngüyü 1000 kez dönecek bir programda trace ile adım adım ilerlemek mantıklı değildir; `P` (proceed) komutu LOOP'u tek seferde geçip bir sonraki satıra gelir.
- `POP DX` ve `POP CX` ile SP artar, CX yeniden A olur. `RET` yığının tepesindeki 0014'ü IP'ye alır; SP = 0024 olur.
- `MOV [0004], AX` ile sonuç `sonuc` değişkenine (ofset 4) yazılır. `RETF` ile ana yordam biter; `PUSH DS` ve `PUSH AX` ile atılan iki değer çekildiği için SP 0024'ten 0028'e çıkar.

## 6. FAR Yordamlar, EXTRN ve PUBLIC

FAR yordamda dallanma kesimler arasıdır. Hoca bunu iki ayrı 64 KB'lık kod kesimiyle çizdi (ekrandan, 00:55:00): birinci kesimde (CS1) `MAIN` yordamı vardır ve içinde `TEST` çağrılır; ikinci kesimde (CS2) `TEST` yordamı vardır ve `RETF` ile biter.

`TEST` çağrılınca kendi kesimimizden çıkıp başka bir kesimin belli bir ofsetine gidilir. Dönüş için artık yalnız ofset yetmez. CALL önce kod kesiminin (CS) değerini, sonra çağrıdan sonraki komutun ofsetini yığına atar; yığına iki word gider. Şemada yığında altta CS, üstte offset gösterildi. `RETF` çalışınca yığının tepesindeki iki değer alınır: üstteki dönülecek ofset (IP), alttaki kod kesiminin değeri (CS) olur ve akış çağıran kesimde kaldığı yerden devam eder.

`TEST` yordamı çağıran kesimde bulunmadığı için bu, çağıran dosyada `EXTRN` sözde komutuyla bildirilir (hoca yazımında bir "E" eksik olduğuna dikkat çekti: EXTERN değil EXTRN). Yordamın bulunduğu dosyada ise yordamın başka kesimlerden kullanılabilmesi için `PUBLIC` ile tanımlanması gerekir. Hoca bunu Java'daki `public`, `private`, `protected` erişim belirleyicilerine benzetti: PUBLIC yazılmazsa varsayılan özeldir (private).

## 7. Örnek 2: Ayrı Dosyadaki FAR Toplama Yordamı

### 7.1 Ana program (EXE)

BL ve BH'de verilen iki sayıyı toplayıp sonucu AX'te döndüren harici, FAR tipli bir `TOPLAMA` yordamı yazılacaktır. Ana program bir önceki örneğin kopyalanıp değiştirilmesiyle yazıldı. Veri: `sayi1 DB 170`, `sayi2 DB 172`, `sonuc DW ?`. Kodun ilgili kısmı (ekrandan, 01:35:00):

```asm
        MOV BL, sayi1
        MOV BH, sayi2
        CALL TOPLAMA
        MOV sonuc, AX
        RETF
ANA     ENDP
myc     ENDS
        END ANA
```

`TOPLAMA` bu dosyadaki kesimlerde olmadığı için dosyanın başında `EXTRN` ile FAR tipli harici yordam olduğu bildirilir. <!-- BELİRSİZ: EXTRN satırı karelerde görünmüyor; MASM'deki yazımı büyük olasılıkla `EXTRN TOPLAMA:FAR` biçimindedir. -->

### 7.2 Yordam dosyası

Yordam ayrı bir dosyada, yalnız bir kod kesiminden oluşur (ekrandan, 01:00:00; gövde altyazıdan ve DEBUG ofsetlerinden):

```asm
        PUBLIC TOPLAMA
mycode  SEGMENT PARA 'kod'
        ASSUME CS:mycode
TOPLAMA PROC FAR
        XOR AX, AX
        MOV AL, BL
        ADD AL, BH
        ADC AH, 0
        RETF
TOPLAMA ENDP
mycode  ENDS
        END
```

<!-- BELİRSİZ: PUBLIC satırı ve gövdenin ilk iki komutu karelerde görünmüyor; altyazıya ve DEBUG'da ADD AL,BH'nin 0004 ofsetinde, AL'nin AA olmasına göre yazıldı. -->

Önce AX sıfırlanır, BL AL'ye alınır, BH eklenir; taşma (elde) olursa `ADC AH, 0` ile AH'ye eklenir. AH 0 olduğu için sonuç AX'te oluşur. Dosyada yığın ve veri kesimi yoktur; bu dosya tek başına çalıştırılabilir bir program oluşturmaz. Hoca bunu, yazılmış fonksiyonların toplandığı ve gerektikçe çağrıldığı kendi kütüphanenize benzetti. Dosyanın sonunda `END` vardır ama giriş noktası adı yazılmaz.

### 7.3 Derleme ve bağlama

İki dosya MASM ile ayrı ayrı derlenir, ikisinin de OBJ dosyası oluşur. Bağlama aşamasında iki OBJ dosyası `+` ile birleştirilir (ekrandan, 01:05:00):

```text
link 091221b.obj + 091221c.obj
Run File [091221B.EXE]: 091221
List File [NUL.MAP]:
Libraries [.LIB]:
```

Satır sonuna noktalı virgül konursa soru sorulmaz ve EXE dosyasının adı ilk OBJ dosyasının adını alır. Noktalı virgül konmazsa EXE adı sorulur ve yeni bir ad verilebilir.

### 7.4 DEBUG ile izleme

- `U` ile bakıldığında CALL satırında hedef olarak başka bir kesim (0770) ve onun 0 ofseti görülür; ana kod 076E kesimindedir.
- Başlangıçta SP = 0028 görülür. Yığın 20 tanımlandığı hâlde 28 görünmesi sorun değildir: DEBUG değerleri onaltılık gösterir, $28_h = 2\cdot16 + 8 = 40$ byte = 20 word'dür.
- `PUSH DS` ile yığına DS'nin başlangıç değeri 075A atılır, ardından 0 atılır. `MOV AX, myd` / `MOV DS, AX` ile DS = 076D olur. `D DS:0` ile `AA` ve `AC` görülür: $170 = AA_h$, $172 = AC_h$.
- `MOV BL, sayi1` ve `MOV BH, sayi2` ile BX = ACAA olur. CALL çalışınca CS ve IP değişir, SP 4 azalarak 0020 olur (iki word). `D SS:20` ile yığında 0016 (dönüş ofseti) ve 076E (kesim) görülür.

Yordamın içi (ekrandan, 01:10:00):

```text
AX=00AA  BX=ACAA  ...  SP=0020  ...  CS=0770  IP=0004
0770:0004 02C7        ADD   AL,BH
AX=0056  ...  OV UP EI PL NZ AC PE CY
0770:0006 80D400      ADC   AH,00
AX=0156  ...  NV UP EI PL NZ NA PO NC
0770:0009 CB          RETF
AX=0156  ...  SP=0024  CS=076E  IP=0016
076E:0016 A30200      MOV   [0002],AX
```

$AA_h + AC_h = 156_h$: AL'ye 56 yazılır ve elde bayrağı kurulur (NC'den CY'ye). `ADC AH, 00` ile AH = 1 olur, AX = $0156_h = 342 = 170 + 172$. `RETF` ile SP 4 artarak 0024 olur, CS 076E'ye, IP 0016'ya döner. Sonuç `MOV [0002], AX` ile yazılır ve `D DS:0` ile 0156 görülür.

> **Ek bilgi (derste anlatılmadı):** Karedeki bayraklarda `ADD AL, BH` sonrası OV ve AC de kuruludur. İşaretli yorumla $AA_h = -86$ ve $AC_h = -84$'tür; toplam $-170$ 8 bitlik işaretli aralığın (−128..127) dışında kaldığı için taşma (OF) kurulur. Alt dörtlüklerin toplamı $A + C = 16_h$ 4 biti aştığı için yardımcı elde (AF) da kurulur.

### 7.5 Soru-cevaplar

**Soru:** Aynı adlı (`TOPLAMA`) iki fonksiyon iki farklı dosyada olursa ne olur? (derste sözlü, 01:10:32)
**Cevap:** Hoca önce bunun farklı parametreli fonksiyon ezme (overloading) olup olmadığını sordu; öğrenci ayrı bir dosyada aynı adlı ikinci bir fonksiyonu kastettiğini söyledi. Örneğin dördüncü bir dosyada da `TOPLAMA` varsa ve üç dosya birlikte link edilirse sorun çıkar, çünkü bağlayıcı hangi `TOPLAMA`'yı alacağını bilemez. Yalnız ana dosya ile o dördüncü dosya link edilirse sorun çıkmaz. Fonksiyon ezilemez.

**Soru:** Ana dosyada NEAR tipte bir `TOPLAMA` olsaydı? (derste sözlü, 01:11:48)
**Cevap:** Burada harici yordamın FAR olduğu bildirildi. Her şeyi tek kesimde yazacaksanız (örneğin COM programında) bütün yordamları alt alta NEAR yazabilirsiniz, EXTRN/PUBLIC ile uğraşmanız gerekmez. `TOPLAMA` ana dosyaya da kopyalanabilir; orada FAR yazılıp PUBLIC yapılırsa başka dosyalardan da kullanılabilir. Kesimlerin farklı dosyalardan da olsa birleştirilmesi ileride görülecektir.

## 8. Makrolar

### 8.1 Yazım

Makrolar C, Java, Python gibi yüksek seviyeli dillerdeki makrolara benzer bir mantıkla kullanılır. Fonksiyonlara göre avantajları ve dezavantajları vardır. Yazım şöyledir (ekrandan, 01:30:00, 01:45:00):

```text
makro_ismi   MACRO  param1, param2, ...
             LOCAL  etiket1, etiket2, ...
             ...    ; makronun kodu
             ENDM
```

- `MACRO` bir sözde komuttur. Varsa parametreler yanına yazılır; tip yazılmaz.
- Makroda kullanılan etiketler (L1, L2, ...) `LOCAL` ile bildirilir. Hoca makroya özel kesim tanımları gerekiyorsa `ASSUME` ile söylenebileceğini de belirtti. Bu satırlar isteğe bağlıdır.
- Makro `ENDM` ile biter. `ENDM`'den önce makro adı yazılmaz (yordamdaki `ENDP`'nin aksine).

Makro, yordamın içinde doğrudan adı ve varsa parametreleri yazılarak çağrılır: `MM` ya da `ENKCK dizi, n`.

### 8.2 Makro ile yordamın farkı

Yordamda çağrı anında yığına dönüş adresi atılır, akış yordama dallanır ve RET ile geri döner; yordam nerede çağrılırsa çağrılsın kodu bellekte bir kez bulunur. Makroda ise assembler makro adının geçtiği her yere makronun kodunu **kopyalayıp yapıştırır**. Akış kaldığı yerden düz devam eder; CALL, RET ve yığın işlemi yoktur. Buna karşılık makro n kez kullanılırsa ve kodu örneğin 10 byte ise program her kullanımda 10 byte büyür.

Bir fark daha vardır: yordamlarda yazım sırası önemli değildir, ama makro çağrılmadan önce yazılmış olmalıdır. Bu yüzden örnekte makro ana yordamın hemen üstüne yazıldı.

> **Hocanın vurgusu:** Makro, çağrılmadan önce tanımlanmış olmalıdır.

## 9. Örnek 3: Diziyi Yarıya Bölen Ana Yordam ve En Küçük Elemanı Bulan Makro (COM)

### 9.1 Soru

Hoca soruyu ekrana elle yazdı (ekrandan, 01:50:00):

> n elemanlı bir dizinin elemanlarını 2'ye bölen main yordamın içinde dizinin en küçük elemanını bulan macro'yu COM tipi program için yazınız.

Yani dizinin bütün elemanları ana yordamda ikiye bölünecek, en küçük eleman makroda bulunacaktır.

### 9.2 COM iskeleti

Önceki derste COM programı için iki yazım biçimi görülmüştü: önce veri yazılıp başta `JMP` ile ana yordama dallanılan biçim ve önce kod, altına veri yazılan biçim. Bu örnekte ikincisi kullanıldı. Kesim `ORG 100h` ile başlar, `ASSUME CS:cseg, DS:cseg, SS:cseg` yazılır, ana yordam NEAR'dır ve `RET` ile biter.

### 9.3 İkiye bölme

Hoca bir değerin yarısını bulmak için hangi komutun kullanılabileceğini sordu.

**Soru:** Bir değişkenin ya da yazmacın yarısını nasıl buluruz? (derste sözlü, 01:37:19)
**Cevap:** Bir öğrenci önce bölünecek değeri AX'e, 2'yi BX'e koyup `DIV BX` yapılabileceğini söyledi. Hoca bunun doğru olduğunu ama daha karmaşık ve zaman alıcı olduğunu belirtti. Daha verimli yol sağa kaydırmadır: sola bir kaydırma 2 ile çarpar, sağa bir kaydırma 2'ye böler. Bu 2'ye (2'nin kuvvetlerine) özeldir; 3'e bölmek için DIV gerekir.

İlk yazılan `SHR dizi[SI], 1` yeterli değildir, çünkü dizide negatif elemanlar vardır. Aritmetik kaydırma `SAR` sayının işaretini koruyarak 2'ye böler; burada mutlaka `SAR` kullanılır.

### 9.4 En küçük elemanı bulan makro

Algoritma: dizinin ilk elemanı şimdilik en küçük kabul edilip AL'ye alınır. SI bir artırılır, ikinci elemandan başlanarak kalan `n - 1` eleman taranır. Her elemanda AL ile karşılaştırılır; AL küçükse atlanır, değilse dizideki eleman daha küçüktür ve AL'ye alınır.

Makro içindeki `L1` etiketi ana yordamdaki `L1` ile karışmamalı, makro birden fazla kez çağrıldığında da her kopyada ayrı olmalıdır. Bu yüzden `L1` ve `don` etiketleri `LOCAL` ile yerel yapılır.

Hoca parametre geçirmenin ne kadar kolay olduğuna dikkat çekti: C ya da Java'daki makrolara göre daha az uğraş gerektirir, sanki Python'da yazılıyormuş gibi parametre verilir. Makro sonucu AL'de bırakır, ana yordam `MOV kck, AL` ile yazar.

### 9.5 Kod

Ekrandaki son hali (ekrandan, 01:45:00, 01:55:00):

```asm
cseg    SEGMENT PARA 'kod'
        ORG 100h
        ASSUME CS:cseg, DS:cseg, SS:cseg

ENKCK   MACRO dizi, n
        LOCAL L1, don
        XOR SI, SI
        MOV AL, dizi[SI]
        INC SI
        MOV CX, n
        DEC CX
L1:     CMP AL, dizi[SI]
        JL don
        MOV AL, dizi[SI]
don:    INC SI
        LOOP L1
        ENDM

ANA     PROC NEAR
        XOR SI, SI
        MOV CX, n
L1:     SAR dizi[SI], 1
        INC SI
        LOOP L1
        ENKCK dizi, n
        MOV kck, AL
        RET
ANA     ENDP
dizi    DB 10, -2, 4, 6, 10, 3, 5, 17
n       DW 8
kck     DB ?
cseg    ENDS
        END ANA
```

> **Hocanın vurgusu:** `MACRO`, `LOCAL`, `ENDM`, `PROC`, `ORG`, `SEGMENT`, `PARA`, `ASSUME` sözde komutlardır; `XOR` gibi mnemoniklerle karıştırmayın. Sözde komutları komut kümesinde (instruction set) bulamazsınız. Bu ayrım sınavda soruluyor.

### 9.6 Derleme ve DEBUG ile izleme

Derlemede tek uyarı, yığın kesimi olmadığına dair uyarıdır; COM programında bu beklenir ve kabul edilebilir. EXE dosyası EXE2BIN ile COM'a çevrilir; COM dosyası 53 byte'tır (DEBUG'da CX = 0035).

Unassemble çıktısında ana yordamın `LOOP L1` ile biten döngüsünden sonra makronun komutları açılmış olarak görülür (ekrandan, 01:50:00):

```text
0775:0100 33F6        XOR  SI,SI
0775:0102 8B0E3201    MOV  CX,[0132]
0775:0106 D0BC2A01    SAR  BYTE PTR [SI+012A],1
...
0775:0114 8B0E3201    MOV  CX,[0132]
0775:0118 49          DEC  CX
0775:0119 3A842A01    CMP  AL,[SI+012A]
0775:011D 7C04        JL   0123
0775:011F 8A842A01    MOV  AL,[SI+012A]
```

Dizi 012A ofsetinden başlar; `n` 0132'de, `kck` 0134'tedir. `G` ile çalıştırınca `D DS:012A` ile `kck`ta FF görülür. İkiye bölünmüş dizi $5, -1, 2, 3, 5, 1, 2, 8$'dir; en küçük eleman $-1$'dir ve 8 bitlik karşılığı $FF_h$'dir (python ile kontrol edildi).

Adım adım izlemede: CX'e 8 yüklenir; ilk eleman 0A, bir kez sağa kaydırılınca 05 olur; FE (−2) kaydırılınca FF (−1) olur; 4, 2 olur. Döngünün geri kalanı `P` ile geçilir; 17, 8 olur. Makroda AL'ye ilk eleman 05 alınır, SI bir artar, CX 8'den 7'ye iner. AL = 05 ile ikinci eleman FF karşılaştırılır; AL küçük olmadığı için `JL` dallanmaz ve FF AL'ye alınır (AX = FFFF görülür, AH ile ilgilenilmez). Bu en küçük değer olduğu için döngünün sonuna kadar değişmez. Sonra AL `kck`a yazılır ve RET ile program biter.

Hoca önceki dersten de hatırlattı: COM programında yığına bir şey atılmadığında yığının tepesinde dönüş için 0000 word'ü bulunur.

Son olarak makro ana yordamda ikinci kez çağrıldı (derste sözlü, 01:53:32). Unassemble çıktısında aynı komutların ikinci kez kopyalandığı görüldü; yerel etiket sayesinde ilk kopya 0123 ofsetine dallanırken ikinci kopya 013F ofsetine dallanır. Bu ikinci çağrı yalnız kopyalamayı göstermek içindi, mantıksal bir işe yaramadığı için çalıştırılmadı.

## 10. Çağrılan Yordamın Veri Kesimine Erişimi

**Soru:** Veri kesiminde tanımladığımız bir değişkene, çağırdığımız (başka kesimdeki) fonksiyon erişebilir mi? (derste sözlü, 01:54:34)
**Cevap:** Evet. Hoca Örnek 2'yi DEBUG'da yeniden açıp gösterdi: FAR CALL ile kod kesimi (CS) ve ofset değişir, ama DS ve SS değişmez. Başka bir kod kesimindeyken de aynı veri kesimi ve aynı yığın kullanılır. Orada yapılan bir PUSH, ana programın yığınına gider.

Hoca soruyu genişletip adres aktarma (pointer) fikrini sözde kodla anlattı: ana yordamda `LEA SI, sayi1` ile değişkenin adresi SI'ye yüklenir ve `PUSH SI` ile yığına atılır. Çağrılan yordam bu adresi yığından alır ve `MOV` ile o adrese, örneğin AX'teki sonucu yazar. Hoca bunun sözde kod olduğunu, ayrıntısının sonraki derste görüleceğini belirtti. Özetle: yordamın içinde değişkenin adını doğrudan yazarak kullanmak beklenen yol değildir; ama değişkenin adresi biliniyorsa o adrese yazılabilir.

<!-- BELİRSİZ: Hoca "sayi1'i doğrudan yazarak kullanabilir miyim? Hayır" dedi; ayrı dosyada derlenen yordam için mi, genel olarak mı söylendiği altyazıdan net değil. -->

## Örnek Sorular

**1.** (derste sözlü, 00:39:14) `ustal` yordamında CX dışında başka hangi yazmacın değeri yığında saklanmalıdır?

> **Çözüm (derste verildi):** DX. `MUL BX` sonucu DX:AX'e yazdığı için DX bozulur (burada 0 olur). BX değişmez; AX'te sonuç döndüğü için AX saklanmaz.

**2.** (ekrandan, 00:35:00) $2^{10}$'u bulmak için döngüde `MUL BL` kullanılırsa ne olur?

> **Çözüm (derste verildi, ders sonrası notla):** Sonuç 8 biti aştığında AH = 1, AL = 0 olur; sonraki adımda AL (0) ile çarpıldığı için AX sıfırlanır ve sonuç 0 kalır. Taşma $128 \cdot 2 = 256$ adımında olur (hoca 128 adımında dedi; Bölüm 3.5). Çözüm `MUL BX` ile DX:AX'e çarpmaktır.

**3.** (derste sözlü, 01:06:01) Yığın `DW 20 DUP(?)` ile tanımlandığı hâlde DEBUG'da SP = 0028 görünüyor. Sorun var mı?

> **Çözüm (derste verildi):** Yoktur. DEBUG onaltılık gösterir: $28_h = 40$ byte = 20 word.

**4.** (derste sözlü, 01:37:19) Bir değerin yarısını en verimli nasıl buluruz? Dizide negatif sayılar varsa hangi komut kullanılır?

> **Çözüm (derste verildi):** Sağa bir bit kaydırarak. DIV de çalışır ama daha yavaştır. Negatif sayılar için işareti koruyan `SAR`, işaretsiz sayılar için `SHR`.

**5.** (ekrandan, 01:50:00) n elemanlı bir dizinin elemanlarını 2'ye bölen main yordamın içinde dizinin en küçük elemanını bulan macro'yu COM tipi program için yazınız.

> **Çözüm (derste verildi):** Bölüm 9.5'teki kod. `dizi DB 10, -2, 4, 6, 10, 3, 5, 17` için sonuç `kck = FFh` ($-1$).

**6.** (derste sözlü, 01:10:32) İki ayrı dosyada aynı adlı FAR `TOPLAMA` yordamı varsa ne olur?

> **Çözüm (derste verildi):** İkisi de aynı anda link edilirse bağlayıcı hangisini alacağını bilemez ve sorun çıkar; yalnız biri link edilirse sorun çıkmaz.

**7.** (derste sözlü, 01:54:34) FAR çağrıyla başka bir kod kesimindeki yordama gidildiğinde, yordam ana programın veri kesimine ve yığınına erişebilir mi?

> **Çözüm (derste verildi):** Evet. FAR CALL yalnız CS ve IP'yi değiştirir; DS ve SS aynı kalır.

## Dersin Toparlaması

Bu derste bir kod kesiminde birden fazla yordam yazmak ve onları `CALL` ile çağırmak işlendi. NEAR (kesim içi) çağrıda yığına yalnız dönüş ofseti atılır ve `RET` onu geri alır; FAR (kesimler arası) çağrıda önce CS, sonra ofset atılır ve `RETF` ikisini geri alır. Üs alma örneğinde parametreler ve sonuç yazmaçla aktarıldı; 8 bitlik çarpmanın taşma yüzünden yetersiz kaldığı, 16 bitlik `MUL BX` ile DX:AX'e çarpmak gerektiği görüldü. Yordamın, bozduğu yazmaçları (CX, DX) girişte PUSH, çıkışta ters sırayla POP ile koruması gerektiği vurgulandı. Toplama örneğinde yordam ayrı bir dosyaya yazıldı; `EXTRN` ve `PUBLIC` sözde komutlarıyla iki OBJ dosyası LINK aşamasında birleştirildi ve DEBUG'da CS, IP ve SP'nin değişimi izlendi.

İkinci bölümde makrolar anlatıldı: makronun gövdesi çağrıldığı her yere kopyalanır, yığın ve dallanma maliyeti yoktur ama kod büyür; makro çağrılmadan önce tanımlanmalı, etiketleri `LOCAL` ile yerel yapılmalıdır. COM tipi örnekte dizi `SAR` ile yarıya bölündü ve en küçük eleman makroyla bulundu. Hoca yığın üzerinden ve adres (pointer) ile parametre aktarma yöntemlerinin sonraki derste işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
