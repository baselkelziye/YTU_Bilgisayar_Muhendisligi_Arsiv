# Ders 10 Genişletilmiş Notu: EXE Programı Örnekleri: 32 Bitlik Toplama, Dizi Ortalaması, EBOB ve Vücut Kitle İndeksi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Instruction Set Tablosunu Okuma
- 2. EXE Program İskeletinin Tekrarı
- 3. Örnek 1: İki 32 Bitlik Sayının 64 Bitlik Sonuca Toplanması
- 4. Örnek 2a: Byte Dizisinin Ortalaması
- 5. Yazmaçların Yarılarına Erişim
- 6. Örnek 2b: Word Dizisinin Ortalaması
- 7. Örnek 3: En Büyük Ortak Bölen
- 8. Örnek 4: Vücut Kitle İndeksi ve Tek İndisle İki Diziye Erişim
- Örnek Sorular

## 1. Instruction Set Tablosunu Okuma

Ders, önceki derslerde kullanılan instruction set (komut kümesi) tablosunun nasıl okunacağıyla ilgili bir uyarıyla açıldı. Tabloda her komutun farklı operand tipleri için ayrı satırları vardır. Bir komutun immediate (sabit) değer aldığı durum ile dolaylı adresleme üzerinden parametre aldığı durum farklı satırlara, farklı makine kodlarına ve farklı boyutlara karşılık gelir. Önceki iki derste anlatılan adresleme kiplerinin bu tablodaki etkisi bu yüzden önemlidir.

Hocanın önerdiği alıştırma şudur: yazdığınız bir komutun tablonun hangi satırına denk geldiğini ve kaç byte tuttuğunu önce kendiniz tahmin edin, sonra programı assembler'dan geçirip DEBUG ortamında `U` (unassemble) komutuyla ya da LST dosyasıyla karşılaştırın. Dersin sonunda bunun bir örneği gösterildi: DEBUG'da `U CS:0` ile bakıldığında `XOR AX, AX` komutunun `33C0` makine koduna karşılık geldiği görülür; tabloda da bu komutun 33 ile başlayan satırı bulunmalıdır (ekrandan, 01:30:00).

> **Hocanın vurgusu:** Instruction set tablosuyla ilk kez sınavda karşılaşmak çok zaman kaybettirir. Hangi komutların legal, hangilerinin illegal olduğunu, sözde komutları, koşullu dallanmaları ve döngülerin nasıl kurulduğunu tekrar edin; derste yapılan örnekleri kendiniz yeniden yazmayı deneyin.

## 2. EXE Program İskeletinin Tekrarı

### 2.1 Sözde komutlar ve gerçek komutlar

Sözde komutlar (pseudo komutlar), makine kodu karşılığı olmayan, assembler'a derleme zamanında nasıl davranması gerektiğini söyleyen özel sözcüklerdir. `DW`, `DUP`, `SEGMENT`, `PARA`, `STACK` bunlara örnektir. `PUSH DS`, `XOR AX, AX` gibi komutlar ise gerçek komutlardır ve makine kodu karşılıkları vardır. LST dosyasında hangi satırların makine kodu ürettiği, hangilerinin üretmediği görülebilir.

### 2.2 Üç kesim

EXE tipi programın iskeleti şöyledir (ekrandan, 00:10:00, 00:20:00):

```asm
STSG SEGMENT PARA STACK 'STSGM'
        DW 20 DUP (?)
STSG ENDS

DTSG SEGMENT PARA 'DTSGM'
        ASAY DW 0F000H
DTSG ENDS

CDSG SEGMENT PARA 'CDSGM'
        ASSUME CS: CDSG, DS: DTSG, SS: STSG

        ANA PROC FAR

                PUSH DS
                XOR AX, AX
                PUSH AX

                MOV AX, DTSG
                MOV DS, AX

                ;CODE

                RETF
        ANA ENDP

CDSG ENDS

        END ANA
```

Programda yığın, veri ve kod olmak üzere üç kesim vardır. İşletim sistemi program çağrıldığında bu kesimleri belleğe sırayla yerleştirir. `PARA` hizalama parametresi, kesimin bir sonraki 16'nın tam katı adresten başlatılması demektir. `STSG`, `DTSG`, `CDSG` adları ve tırnak içindeki sınıf adları programcının verdiği adlardır; `SEGMENT`, `PARA`, `STACK`, `ENDS` ise sabit sözcüklerdir.

- **Yığın kesimi:** Bir kesimi yığın kesimi yapan şey `STACK` sözcüğüdür. Program yüklenirken işletim sistemi bu sözcüğe bakarak SS yazmacına bu kesimin değerini verir.
- **Veri kesimi:** `DTSG`'yi veri kesimi olarak kullanmak niyetindeyiz, ancak program belleğe yüklendiği anda DS bu kesimi göstermez. DS'de o anda işletim sisteminin verdiği başka bir değer vardır (bkz. 2.3).
- **Kod kesimi:** Bir kesimi kod kesimi yapan şey, `END` sözcüğünden sonra yazılan giriş noktası (entry point) etiketinin, burada `ANA`'nın, o kesimin içinde olmasıdır. Kesim belleğe yüklenince CS orayı gösterecek biçimde ayarlanır ve yürütme o etiketten başlar.

### 2.3 Dönüş adresi ve RETF

EXE tipi programla işletim sistemi arasında baştan bir anlaşma vardır: program bitince doğru yere dönme görevi çağrılan programa aittir. İşletim sistemi bunun için şu bilgiyi verir: "DS içindeki değer döneceğin kesimdir ve sen bu kesimin 0 ofsetine döneceksin."

Bu yüzden EXE programın ana yordamı `FAR` tipinde tanımlanır ve `RETF` (return far) ile döner. Yakın (near) dönüş yığından çektiği tek değeri IP'ye yazar. Uzak dönüş ise yığından çektiği ilk değeri IP'ye, ikinci değeri CS'ye yazar; böylece başka bir kesimin herhangi bir ofsetine dönülebilir.

Kodun başındaki üç satır bu dönüşü hazırlar:

1. `PUSH DS`: dönülecek kesim değeri yığına atılır.
2. `XOR AX, AX`: AX sıfırlanır.
3. `PUSH AX`: dönüş ofseti olan 0 yığına atılır. `PUSH 0` diye bir komut olmadığı için sabit değer doğrudan yığına atılamaz; 0 değeri AX üzerinden dolaylı atılır.

`RETF` çalıştığında yığından ilk gelen değer 0'dır ve IP'ye yüklenir; ikinci değer işletim sisteminin DS ile verdiği kesimdir ve CS'ye yüklenir. Böylece işletim sistemindeki doğru yere dönülür.

Sonraki iki satır, `MOV AX, DTSG` / `MOV DS, AX`, bellekte sıradaki boş yere yüklenmiş olan veri kesimimizin kesim değerini alıp DS'ye yazar. Bu noktadan sonra DS bizim tanımladığımız kesimi gösterir ve asıl kod `;CODE` yazan yere yazılır.

## 3. Örnek 1: İki 32 Bitlik Sayının 64 Bitlik Sonuca Toplanması

### 3.1 Problem ve yaklaşım

Bir önceki derste "Örnek 0" olarak, iki 16 bitlik sayıyı toplayıp sonucu 32 bitlik bir değişkende saklayan EXE programı yazılmıştı. Bu derste bir adım ileri gidildi (ekrandan, 00:25:00):

- Örnek 0: 16 bitlik A + 16 bitlik B → 32 bitlik sonuç.
- Örnek 1: 32 bitlik A + 32 bitlik B → 64 bitlik sonuç.

İki 32 bitlik sayının toplamı 33. bite taşabilir, ama 33 bitlik bir veri tipi olmadığı için sonuç 64 bitlik bir değişkende tutulur. İki yaklaşım mümkündür: sayıları 4 byte'a ayırıp byte byte toplamak ya da 16 bitlik iki parçaya ("chunk") ayırıp toplamak. İşlemci 16 bitlik toplamayı doğrudan desteklediği için ikinci yol daha hızlıdır.

Tahtadaki şekilde iki sayı 16 bitlik iki sütuna bölünür (ekrandan, 00:35:00). Önce düşük anlamlı sütunlar toplanır ve sonuç yerine yazılır. Buradan bir elde çıkabilir; bu elde yüksek anlamlı sütunların toplamına eklenmelidir. Bu toplamdan da bir elde çıkabilir; o da sonucun bir sonraki sütununa yazılmalıdır. Yani bir `ADD` ve ardından iki "add with carry" (`ADC`) işlemi gerekir.

### 3.2 Veri tanımı

**Soru:** 32 bitlik bir değişken nasıl tanımlanır? **Cevap:** `DD` (define double word) ile. Hoca burada `DDW` yazılmaması konusunda şakayla uyardı. 64 bitlik değişken için `DQ` (define quad word) kullanılır.

```asm
DTSG SEGMENT PARA 'DTSGM'
        ASAY  DD 0ABCDEF98H
        BSAY  DD 0EF987654H
        SONUC DQ 0
DTSG ENDS
```

(ekrandan, 00:45:00) `SONUC` sıfırla başlatılır; bu, son adımda işe yarar.

### 3.3 Parçalara erişim

**Soru:** Değişkenler 32 ve 64 bitlik; bunların 16 bitlik parçalarına nasıl erişiriz? **Cevap:** Adreslerini `LEA` (load effective address) ile yazmaçlara alıp ofset ekleyerek (ekrandan, 00:30:00):

```asm
        LEA SI, ASAY
        LEA DI, BSAY
        LEA BX, SONUC
```

Veri little endian biçiminde saklandığı için en düşük anlamlı byte en düşük adrestedir. SI, A sayısının en düşük anlamlı byte'ını gösterir; adres büyüdükçe daha yüksek anlamlı byte'lar gelir. `[SI]` düşük word'ü, `[SI+2]` yüksek word'ü verir. `+1` bir byte, `+2` bir word ötedir.

### 3.4 İki bellek operandı neden olmaz?

Hoca önce `ADD [SI], [DI]` yazıp bunun olup olmayacağını sordu (ekrandan, 00:30:00), sonra `WORD PTR` eklenmiş hâlini de sordu.

**Soru:** `ADD WORD PTR [SI], [DI]` yazabilir miyiz? **Cevap:** Hayır. Asıl sorun `WORD PTR` değildir; iki bellek adresi üzerinden işlem yapılamaz. Mikroişlemci birden fazla çevre birimine ve belleğe yollar üzerinden bağlıdır, ama bir anda yalnız biriyle konuşabilir. Telin bir ucunda işlemci, diğer ucunda bellek vardır; aynı komut içinde bir yerden bir değer, başka yerden ikinci bir değer okuyamaz. Bu yüzden birinci değer önce yazmaca alınır.

### 3.5 Toplama adımları

1. `MOV AX, [SI]`: A'nın düşük word'ü AX'e alınır.
2. `ADD AX, [DI]`: B'nin düşük word'ü eklenir. Burada `WORD PTR` gerekmez, çünkü AX işlemin word olduğunu zaten belirtir. Önce DX'e alıp sonra toplamak da olur ama iki adım sürer; bir operandı yazmaç, diğeri bellek olan tek `ADD` yeterlidir.
3. `MOV [BX], AX`: toplam, sonucun düşük word'üne yazılır. `MOV SONUC, AX` yazılamaz, çünkü SONUC 64 bitlik bir değişkendir ve tip hatası verir. Önce BX'e alıp sonra yazmak işi uzatır; köşeli parantezli `[BX]` doğrudan doğru yeri gösterir.
4. `MOV AX, [SI+2]`: A'nın yüksek word'ü alınır.
5. `ADC AX, [DI+2]`: B'nin yüksek word'ü, birinci toplamadan gelen elde ile birlikte eklenir.
6. `MOV [BX+2], AX`: sonucun ikinci word'üne yazılır.
7. `ADC WORD PTR [BX+4], 0`: ikinci toplamadan çıkan elde, sonucun üçüncü word'üne eklenir. Oradaki değer zaten 0 olduğu için sonuç 0 ya da 1 olur, yani elde 33. bite yazılmış olur. Burada iki operanddan hiçbiri boyut belirtmediği için `WORD PTR` zorunludur.

```asm
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

<!-- BELİRSİZ: Toplama satırlarının hepsi aynı karede görünmüyor; satırlar anlatımdan ve 00:45:00 DEBUG karesindeki `[BX+02],AX` ve `WORD PTR [BX+04],+00` satırlarından kuruldu. -->

### 3.6 Elde aradaki MOV komutlarında kaybolur mu?

**Soru:** `ADD AX, [DI]` satırında oluşan elde, ancak birkaç satır sonraki `ADC`'de kullanılıyor. Aradaki komutlar bu eldeyi bozabilir mi? **Cevap:** Bunu instruction set tablosundaki bayrak sütunundan kontrol ederiz. `MOV` komutları hiçbir bayrağı etkilemez. Bu yüzden `ADD`'den çıkan CF, aradaki `MOV` komutlarından geçip `ADC`'ye kadar taşınır. Bayrakları etkileyen bir komut araya girseydi, eldeyi önceden saklamak gerekirdi: `PUSHF` / `POPF`, başka bir yazmaç ya da eldeyi oluşur oluşmaz sonucun ilgili byte'ına yazmak. Aynı sınıfın başka bir oturumunda yapılan ilk çözüm de bu son yaklaşımdı; iki yaklaşım da doğrudur.

Bir öğrenci en düşük anlamlı parçaların toplanmasında neden elde düşünülmediğini sordu. **Cevap:** Düşük anlamlı 16 bitlere dışarıdan gelen bir elde yoktur; bu yüzden ilk toplama `ADD` ile yapılır.

### 3.7 Derleme ve DEBUG ile kontrol

Program DOSBox içinde MASM ile derlendi (obje dosyası oluşturuldu; LST dosyası istenmedi), linker'dan geçirildi ve oluşan EXE DEBUG'a verildi. DEBUG'da `R` yazmaçları gösterir, `T` bir adım yürütür. `T`'den sonra bir sayı verilirse o kadar adım birden yürütülür; hoca bunu derste yanlışlıkla bir tuşa basınca keşfetti (4 adım birden yürüdü).

İki 32 bitlik sayının toplamı yalnız 33. bite taşabilir, daha ötesine taşamaz. Hoca bunu görmek için hesap makinesinde taşma üreten değerler seçti. Derlenip çalıştırılan sürümde B sayısı editördekinden farklıydı: bellekte `43 65 87 B9`, yani $B9876543_h$ görüldü. `D DS:0` ile bellek dökümünde (ekrandan, 00:45:00):

- A: `98 EF CD AB` (little endian, $ABCDEF98_h$),
- B: `43 65 87 B9`,
- SONUC: `DB 54 55 65 01 00 00 00`.

Python ile kontrol: $ABCDEF98_h + B9876543_h = 1\,6555\,54DB_h$. Sonuç 64 bitlik alanın 8 byte'ının tamamını kaplar; yüksek anlamlı byte'ların çoğu 0 kalmıştır ve 33. bitteki 1, beşinci byte'taki `01` olarak görünür.

> **Ek bilgi (derste anlatılmadı):** Editörde görünen ilk değerlerle ($ABCDEF98_h + EF987654_h$) de toplam $1\,9B66\,65EC_h$ olur; bu da 33. bite taşar.

## 4. Örnek 2a: Byte Dizisinin Ortalaması

### 4.1 Soru ve aralık analizi

Aradan sonra tahtaya şu soru yazıldı (ekrandan, 01:05:00):

> Verilen 300 elemanlı, pozitif değerlere sahip byte tipindeki dizinin ortalamasını bulan EXE tipindeki assembly programını yazınız. (b şıkkı: aynı soru word dizisi için.)

"Pozitif" bilgisi önemlidir: negatif değer olsaydı işaretli bölme gerekebilirdi. Değerler pozitif (sonradan "negatif olmayan" diye düzeltildi) olduğu için biriktirilen toplam da pozitif olur.

Aralık analizi (ekrandan, 01:35:00): bir byte gözünün alabileceği en büyük değer 255'tir. Eleman sayısı 255 olsaydı toplam 16 bite sığardı. Ama $300 \cdot 255 = 76500 > 65535$; toplam 16 bitten taşar. Hex olarak bakıldığında 17. bite yalnız bir bit taşar. 500 elemanlı bir byte dizisinde bile $500 \cdot 255 = 127500$ yine 17 bite sığar. Sonuçta biriktirici 32 bitlik bir yazmaç ya da bellek alanı olmalıdır.

**Soru:** Dizi işaretli olsaydı ne olurdu? **Cevap:** En küçük değer −128 olur; $-128 \cdot 300 = -38400$ çıkar. Bu da 16 bitlik işaretli aralığa ($-32768$ ile $32767$ arası) sığmaz; yine en az 32 bit gerekir.

**Soru:** Ortalama byte mı, word mü tutulmalı? **Cevap:** Byte. Eleman sayısı ne olursa olsun, bir byte dizisinin ortalaması en çok 255 olur ($255 \cdot 300 / 300$).

Toplam 300'e bölüneceği için bölme 16 bitliktir. 16 bitlik bölme zaten DX:AX'i böldüğü için toplamı doğrudan DX:AX sanal 32 bitlik yazmacında biriktirmek en uyumlu çözümdür: DX yüksek anlamlı 16 bit, AX düşük anlamlı 16 bittir.

### 4.2 Veri tanımı

En kötü durumu denemek için dizinin başına 5 değer, ardına 295 tane 255 konuldu:

```asm
        DIZI DB 10, 20, 30, 40, 50, 295 DUP (255)
        N    DW 300
        ORT  DB 0
```

N, CX'e yükleneceği için word tanımlandı. Ortalama 255'e yakın ama tam 255 olmayan bir değer çıkmalıdır.

<!-- BELİRSİZ: Veri tanımının karesi okunmadı; satırlar anlatımdan (01:10:09-01:11:24) kuruldu. -->

### 4.3 Döngü ve indis yaklaşımı

Döngü sayısı CX'te tutulur: `MOV CX, N`, `L1:` etiketi ve `LOOP L1` (ekrandan, 01:15:00).

Dizinin elemanlarına indis yaklaşımıyla erişildi. Önceki derslerde `LEA BX, DIZI` ile alınan adres `[BX]` içinde kullanılıyordu; bu dolaylı adreslemedir ve BX bir ofset (örneğin 100H) taşır. İndis yaklaşımında ise C'deki `dizi[i]` gibi `DIZI[SI]` yazılır; SI = 0 birinci eleman, 1 ikinci eleman, 2 üçüncü elemandır. Bu yazım aslında `[SI + DIZI]` demektir: DIZI'nin ofseti immediate bir değer olarak adrese eklenir. DEBUG'da bu açıkça görülür. Bu yüzden SI, ofset değil indis olduğu için `XOR SI, SI` ile sıfırlanır.

**Soru:** Bir sonraki elemana nasıl geçilir? **Cevap:** `INC SI`.

Bir öğrenci indis olarak doğrudan CX'i kullanmayı önerdi. **Cevap:** Köşeli parantez içinde CX yazılamaz; indis yazmacı (SI, DI, BX) gerekir. `MOV SI, CX` gibi bir kopyalama da teknik olarak mümkündür, ama hangisinin daha hızlı olduğuna komut sürelerine bakarak karar verilmelidir; hocanın tahmini `INC SI`'nin daha hızlı olduğuydu.

### 4.4 Eldeli biriktirme

Biriktirmeden önce AX ve DX sıfırlanır (`XOR AX, AX`, `XOR DX, DX`), tıpkı C'de toplam değişkenini sıfırlamak gibi.

Döngünün ortasındaki genel bir adımı düşünelim: önceki toplamalardan bir elde gelmiş olabilir ve kaybedilmemelidir. Bu yüzden toplama `ADD` değil `ADC` ile yapılır. Ayrıca dizi byte dizisi olduğu için `ADC AX, DIZI[SI]` yazılamaz: dizinin tipi byte, yazmaç word'dür. `WORD PTR` ile zorlamak da yanlıştır; derlenir ama yan yana iki elemanı birleştirip 16 bitlik hatalı bir değer toplar. Doğrusu AL kullanmaktır:

1. `ADC AL, DIZI[SI]`: sıradaki eleman ve önceki elde AL'ye eklenir.
2. `ADC AH, 0`: AL'den taşan elde AH'ye aktarılır.
3. `ADC DX, 0`: AH'den (AX'ten) taşan elde DX'e aktarılır. Hoca burada "byte byte gitmek zorunda mıyız, büyük bir adım atalım" diyerek eldeyi doğrudan DX'e aktardı.

İlk adımı ayrıca düşünmek gerekir: döngüye girerken CF'nin değerinden emin değiliz. Bu yüzden döngüden önce CF, `CLC` (clear carry flag) komutuyla sıfırlanır.

Kod (ekrandan, 01:25:00, 01:30:00):

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

> **Ek bilgi (derste anlatılmadı):** `XOR` komutu CF'yi her zaman 0 yapar; bu yüzden `XOR DX, DX`'ten hemen sonraki `CLC` bu kodda zararsız ama gereksizdir. `INC` ve `LOOP` ise CF'yi değiştirmez; elde zinciri bu sayede bozulmaz.

### 4.5 Bölme

**Soru:** Döngü bittiğinde SI'nin değeri nedir? **Cevap:** 300. Bu yüzden N'yi tekrar bir yazmaca almaya gerek yoktur; doğrudan `DIV SI` yazılır. SI 16 bitlik olduğu için bu 16 bitlik bölmedir: DX:AX / SI. Bölüm AX'e, kalan DX'e yazılır. Ortalama tamsayı bölmesiyle bulunduğu için kalanla ilgilenilmez.

**Soru:** Sonuç AX'te çıktı ama ortalama byte; AH için ne söylenebilir? **Cevap:** AH kesinlikle 0 çıkar, çünkü byte dizisinin ortalaması en çok 255'tir. Bu yüzden `MOV ORT, AL` yazılır; ORT zaten byte tanımlanmıştı, her şey birbiriyle uyumludur.

### 4.6 DEBUG ile kontrol

DOSBox penceresinde Ctrl+F4, bağlanan (mount edilen) klasördeki değişiklikleri DOSBox'a yansıtır; bunu derste öğrenciler hatırlattı. Böylece DOSBox'ı kapatıp açmaya gerek kalmaz. Dosya `ORTB` adıyla derlendi, linklendi ve DEBUG'da açıldı (ekrandan, 01:30:00).

`U CS:0` ile bakıldığında `MOV CX, N` satırının `MOV CX, [012C]` olduğu görülür: N, 300 byte'lık dizinin hemen arkasında, 300 = 12Ch ofsetindedir. `ADC AL, DIZI[SI]` ise `ADC AL, [SI+0000]` olarak görünür, çünkü DIZI ofset 0'dadır. Döngünün bittiği adrese kadar `G` ile çalıştırıldı.

Beklenen toplam (ara adımlar python ile kontrol edildi): ilk beş değer $10+20+30+40+50 = 150$, kalan $295 \cdot 255 = 75225$, toplam $75375 = 1266F_h$. DEBUG ekranında DX = 0001, AX = 266F görüldü. `DIV SI`'den sonra AH = 00 ve AL = FB çıktı: $75375 / 300 = 251$ (kalan 75), $251 = FB_h$.

Sonucun belleğe yazıldığını görmek için veri kesiminin 12Ch ofsetinden döküm alındı: önce N (`2C 01`), sonra ORT (`FB`) görüldü. Arkasındaki 0'ın açıklaması: sonraki kesim `PARA` hizalı olduğu için 16'nın tam katından başlamalıdır; veri kesimi 16'nın tam katında bitmediği için aradaki bir byte 0 ile doldurulmuştur.

## 5. Yazmaçların Yarılarına Erişim

Bir öğrencinin sorusu üzerine hoca, yazmaç yapısını hatırlattı ve bu konunun ilk iki haftanın derslerinden yeniden dinlenmesini istedi:

- AX 16 bitlik bir yazmaçtır; düşük anlamlı yarısına AL, yüksek anlamlı yarısına AH ile erişilir.
- BX için BL ve BH, CX için CL ve CH, DX için DL ve DH aynı biçimde kullanılır.
- SI ve DI doğrudan 16 bitlik yazmaçlardır; düşük ve yüksek yarılarına ayrı ayrı erişilemez.
- Kesim yazmaçları da yalnız 16 bit olarak kullanılır.

## 6. Örnek 2b: Word Dizisinin Ortalaması

### 6.1 Soru ve değişiklikler

> 200 elemanlı, negatif olmayan değerli word dizisinin ortalamasını bulan EXE tipi assembly kodunu yazınız.

Önceki kod üzerinde şu değişiklikler yapıldı:

- Dizi `DW` tanımlandı, eleman sayısı 200 yapıldı.
- İlk beş değer kaldı, arkasına 195 tane `0FFFFH` (en büyük değer) kondu.
- Ortalama artık word tipinde olmalıdır.

**Soru:** Biriktirme yine DX:AX'te yapılabilir mi? **Cevap:** Hesap makinesiyle bakıldı: $200 \cdot FFFF_h = 13107000$ yine 32 bite sığar. DX:AX ile devam edilebilir.

### 6.2 Döngü

Dizi elemanı word olduğu için doğrudan AX'e eklenir; AX'ten taşan elde DX'e aktarılır. Önceki koddaki `ADC AH, 0` satırının çıkarılması yeterlidir. Word dizisinde her eleman iki adres ötededir, bu yüzden `INC SI` yerine `ADD SI, 2` yazılır.

**Soru:** Döngü kırıldığında SI kaçtır? **Cevap:** 400; 200 kez ikişer artırıldı. Bölme için eleman sayısı gerekir, yani SI'nin yarısı.

**Soru:** Bir adımda nasıl yarıya indiririz? **Cevap:** `SHR SI, 1` (shift right) ile. Bir bit sağa kaydırmak ikiye bölmektir; SI'de 200 kalır.

Sonra `DIV SI` ile DX:AX'teki toplam 200'e bölünür; bölüm AX'tedir. ORT word olduğu için sonuç AX ile yazılmalıdır (AL'de ortalamanın yalnız bir kısmı vardır).

```asm
        MOV CX, N
        XOR SI, SI
        XOR AX, AX
        XOR DX, DX
        CLC
L1:     ADC AX, DIZI[SI]
        ADC DX, 0
        ADD SI, 2
        LOOP L1
        ; DX:AX <- sum (DIZI)
        SHR SI, 1
        DIV SI        ; AX <- DX:AX / SI, DX <- kalan
        MOV ORT, AX
        RETF
```

(ekrandan, 01:40:00)

> **Ders sonrası not:** 01:40:00 karesinde son satır editörde henüz `MOV ORT, AL` olarak görünüyor ve `SHR SI,` satırı yazılmakta. Hoca anlatımda ORT word olduğu için değerin AX'ten yazılması gerektiğini söyledi; doğru satır `MOV ORT, AX`'tir.

> **Ek bilgi (derste anlatılmadı):** `ADD SI, 2` komutu, `INC SI`'den farklı olarak CF'yi değiştirir. Bu kodda zararsızdır: elde, `ADD SI, 2`'den önce `ADC DX, 0` ile zaten DX'e aktarılmıştır ve SI 400'ü geçmediği için `ADD SI, 2` CF'yi hep 0 yapar.

### 6.3 DEBUG ile kontrol

Dosya `ORTW` adıyla Ctrl+F4 ile güncellendi, derlendi, linklendi ve DEBUG'da döngünün bittiği adrese kadar `G` ile çalıştırıldı.

Beklenen toplam (python ile kontrol edildi): $195 \cdot 65535 + 150 = 12779475 = C2FFD3_h$. DEBUG'da DX = 00C2, AX = FFD3 görüldü. SI = 0190 idi; bu, 400'ün hex karşılığıdır ve gerçekten ikiye bölünmesi gerektiğini gösterir. Bölmeden sonra $12779475 / 200 = 63897 = F999_h$ elde edildi. Değerlerin hepsi FFFF olmadığı için ortalama FFFF'e yakın ama ondan küçüktür.

Sonuç değişkeni 400 byte'lık dizinin arkasındadır, yani veri kesiminin 190h ofsetinden bakılır. Dökümde önce N (`00C8` = 200), sonra ORT (`F999`) görüldü.

## 7. Örnek 3: En Büyük Ortak Bölen

### 7.1 Matematiksel temel

> Verilen pozitif A ve B sayılarının en büyük ortak bölenini (GCD) bulan EXE programını yazınız.

Kullanılan bilgi (ekrandan, 01:50:00):

$$\gcd(A, B) = \gcd(B,\ A \bmod B), \qquad \gcd(A, 0) = A$$

Örnek: $\gcd(20, 16) = \gcd(16, 4) = \gcd(4, 0)$. Burada B = 0 olduğu için durma koşulu sağlanmıştır ve A döndürülür: sonuç 4.

Bu yaklaşımda A'nın büyük sayı olduğu kabul edilir. A < B ise önce A ile B yer değiştirilir (swap). Hoca küçük sayının büyük sayıya bölünmesinin bu yaklaşımda hatalı bir ara sonuç vereceğini söyledi (16'nın 20'ye bölümü 0, kalan 16).

> **Ek bilgi (derste anlatılmadı):** Matematiksel olarak A < B iken bir tur fazladan dönülür ve ilk turda sayılar kendiliğinden yer değiştirir: $\gcd(16, 20) = \gcd(20, 16 \bmod 20) = \gcd(20, 16)$. Yani yer değiştirme doğruluk için şart değildir ama bir turu kısaltır.

### 7.2 Veri ve yazmaçlar

`ASAY DW 20`, `BSAY DW 16` (önce 16 ve 20 sırası tartışıldı), `GCD DW 0`. Değerler word olduğu için mod işlemi 16 bitlik bölmeden gelir: DX:AX bir değere bölünür, kalan DX'te oluşur. A, AX'te; B, BX'te tutulur: `MOV AX, ASAY`, `MOV BX, BSAY`.

### 7.3 Yer değiştirme: boş kola göre koşul

Kontrol `CMP AX, BX` ile yapılır. "A < B ise swap" yapısında true kolunda swap vardır, false kolu boştur. Önceki derste görüldüğü gibi koşul dolu kola göre yazılırsa iki dallanma (bir koşullu, bir koşulsuz) gerekir; boş kola göre yazılırsa tek koşullu dallanma yeter. Sayılar pozitif olduğu için işaretsiz dallanma kullanılır. Hoca önce `JA` (jump above) diye başladı, sonra eşitlik durumunu da düşünerek `JAE` (jump above or equal) seçti: sayılar eşitse yer değiştirmeye gerek yoktur, zaten birinin diğerine göre modu 0 çıkar ve işlem bir adımda biter.

**Soru:** Swap nasıl yapılır? C'de geçici değişkenle üç adımda yapılıyordu. **Cevap:** Assembly'de `XCHG` (exchange) komutu vardır; geçici değişken olmadan `XCHG AX, BX` ile yer değiştirilir. Hoca bunu "assembly bilmenin güzelliği" diye niteledi.

### 7.4 While döngüsü

`NOSWAP` etiketinden sonra A artık büyük sayıdır. While döngüsünde önce durma koşulu kontrol edilir, çünkü koşul daha ilk anda sağlanmış olabilir (B = 0 ise hiç bölme yapılmaz): `CMP BX, 0`. Burada da koşul boş kola göre yazılır: B = 0 ise döngüden çıkılır (`JE CIKIS`). Sonra bölme yapılır:

**Soru:** `DIV BX` ne yapar? **Cevap:** DX:AX'i BX'e böler. DX'in değerini garanti etmedik; bu yüzden bölmeden önce mutlaka `XOR DX, DX` çalıştırılmalıdır.

Bölümden sonra AX'teki bölümle ilgilenilmez; kalan DX'tedir. Yeni değerler: BX → AX, DX → BX. Sıra önemlidir; önce `MOV AX, BX`, sonra `MOV BX, DX`. Ardından while'ın başındaki kontrole koşulsuz dönülür (`JMP NOSWAP`). Döngü kırıldığında BX = 0'dır ve aranan değer AX'tedir: `MOV GCD, AX`.

```asm
        MOV AX, ASAY
        MOV BX, BSAY
        CMP AX, BX
        JAE NOSWAP
        XCHG AX, BX
NOSWAP: CMP BX, 0
        JE CIKIS
        XOR DX, DX
        DIV BX          ; AX <- bölüm, DX <- kalan
        MOV AX, BX
        MOV BX, DX
        JMP NOSWAP
CIKIS:  MOV GCD, AX
        RETF
```

<!-- BELİRSİZ: Kodun tam metni karede okunmadı. 02:00:00 DEBUG karesinde `CMP BX,+00` (0015), `JZ 0024` (0018), `MOV AX,BX` (001E), `MOV BX,DX` (0020), `JMP 0015` (0022) görülüyor; geri kalan satırlar ve etiket adları altyazıdan kuruldu. Komut uzunlukları bu sırayla tutarlıdır. -->

Hoca, kodun aynı dersin başka bir oturumunda yazılan hâlinden biraz farklı olduğunu belirtti.

### 7.5 DEBUG ile deneme

Dosya `GCD` adıyla derlendi ve DEBUG'da adım adım yürütüldü (ekrandan, 02:00:00). Ara adımlar python ile de kontrol edildi:

- **(20, 16):** AX = 14h (20), BX = 10h (16). `CMP` sonrası `JNB` (aynı komut) doğrudan `CMP BX, 0` satırına atladı, `XCHG` atlandı. İlk bölme: bölüm 1, kalan 4. Yeni değerler AX = 10h, BX = 4. İkinci bölme: 16 / 4, kalan 0. AX = 4, BX = 0. Döngüden çıkıldı, `GCD` = 4. Bellek dökümünde 20, 16 ve 4 görüldü.
- **(16, 20):** Programı yeniden derlememek için DEBUG'da `R AX` ve `R BX` komutlarıyla yazmaç değerleri değiştirildi. Bu kez AX daha küçük olduğu için `XCHG` çalıştı; AX = 20, BX = 16 oldu ve kalan adımlar ilk denemeyle aynı gitti.
- **(20, 1):** Tek turda AX = 1, BX = 0 olur; sonuç 1.
- **(23, 7):** Aralarında asal sayılar en çok tur sayısını üretir. 23 = 17h, 7 = 7h. Turlar: (7, 2), (2, 1), (1, 0); sonuç 1.

## 8. Örnek 4: Vücut Kitle İndeksi ve Tek İndisle İki Diziye Erişim

### 8.1 Soru ve tipler

> Kişi ağırlık ve boy değerlerinin tutulduğu dizileri kullanarak kişilere ilişkin vücut kitle indeksi (BMI) değerini hesaplayın.

Formül (ekrandan, 02:25:00):

$$BMI = \frac{w_{lb}}{h_{in}^2} \times 703$$

Ağırlık pound, boy inç cinsindendir. Hoca hesap makinesiyle birimleri gösterdi: 100 kg yaklaşık 220 pound, 200 kg yaklaşık 440 pound eder. Ağırlık bu yüzden byte'a sığmaz, word dizisi olmalıdır. Boy inç cinsinden 3 metre bile olsa 8 bite sığar; boy dizisi byte dizisidir. BMI değerleri de word dizisi kabul edildi.

Hazır bir kod incelendi. 200 kişilik bir liste vardır: boy ve ağırlık dizilerinde birkaç olası değer ve 195 tane uç değer; BMI dizisi için 200 word'lük sıfırlanmış yer ayrılır.

<!-- BELİRSİZ: Veri tanımlarının tamamı karede okunmuyor (02:40:00 karesinde yalnız `(100)` ve `DUP (250)` parçaları görülüyor). DEBUG'da ilk boy 80, ilk ağırlık 300 olarak okundu. -->

### 8.2 Tek indisle byte ve word dizisine erişim

Her diziye ayrı bir indis yazmacı vermek mümkündür: boy için SI, ağırlık için DI, BMI için BX. Bu derste ise bir kullanım senaryosu göstermek için bütün diziler tek indisle (SI) gezildi.

**Soru:** Boy dizisinin bir elemanıyla çalışırken aynı sıradaki ağırlık elemanına erişmek için SI nasıl değişmeli? **Cevap:** Ağırlık word dizisi olduğu için aynı sıradaki elemana iki kat ileri gidilmelidir. SI `SHL SI, 1` ile ikiyle çarpılır, word dizilerine erişilir, sonra `SHR SI, 1` ile ikiye bölünüp `INC SI` ile bir sonraki byte indisine geçilir.

### 8.3 İşlem sırası: önce çarp

8086'nın çarpma ve bölmesi tamsayı işlemidir. Ağırlık bir word, boyun karesi de bir word'dür ve değerleri birbirine yakındır. Önce bölme yapılırsa sonuç 0, 1 ya da 2 gibi değerler olur; bu hassasiyet kaybı sonra 703 ile çarpılarak düzeltilemez. Önce ağırlığı 703 ile çarpıp sonra boyun karesine bölmek, sonuçları anlamlı bir aralıkta tutar.

`MUL` iki operand ya da immediate değer almaz; `MUL 703` diye bir komut yoktur. 703 değeri bu yüzden döngü dışında DI'ye konur ve `MUL DI` ile kullanılır.

### 8.4 Döngü

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

(ekrandan, 02:30:00, 02:35:00)

Adım adım:

1. Boy byte dizisi olduğu için sıradaki boy AL'ye alınır.
2. `MUL AL`, AL'nin karesini alır; 8 bitlik çarpmanın sonucu AX'te oluşur. Boyun karesi AX'tedir.
3. Sonraki çarpma ve bölme DX:AX'i kullanacağı için boyun karesi BX'e kopyalanır.
4. `SHL SI, 1` ile SI ikiyle çarpılır; artık word dizilerinin aynı sıradaki elemanını gösterir.
5. Ağırlık AX'e alınır ve `MUL DI` ile 703 ile çarpılır. 703 byte'a sığmadığı için 16 bitlik çarpma yapılır; sonuç DX:AX'tedir.
6. `DIV BX`, DX:AX'i boyun karesine böler. Çarpma sonucu zaten DX:AX'te oluştuğu için bölmenin girdisi kendiliğinden hazırdır; ayrıca atama gerekmez. Bölüm AX'te, kalan DX'tedir; kalanla ilgilenilmez.
7. BMI sonucu, BMI word dizisinin sıradaki gözüne yazılır. İlk turda SI = 0, `SHL` sonrası yine 0 olduğu için ilk değer BMI'nin 0. byte'ına; ikinci turda SI = 1, `SHL` sonrası 2 olduğu için bir sonraki word gözüne yazılır.
8. `SHR SI, 1` ile indis byte indisine geri döner, `INC SI` ile bir artar ve döngü başa döner.

Derlenip çalıştırılan sürümde L1'in ilk satırı `XOR AX, AX` idi (02:30:00 karesinde görülüyor). Hoca bu satırın gereksiz olduğunu, önceki bir denemeden kaldığını söyleyip kaldırdı; `MOV AL, BOY[SI]` / `MUL AL` AH'ı zaten belirler.

### 8.5 DEBUG ile kontrol

İlk kişi için beklenen değer hesap makinesiyle bulundu: $300 \cdot 703 / 80^2 = 32$ (tamsayı bölme). DEBUG'da (ekrandan, 02:40:00, 02:45:00):

- CX = 00C8 (200), DI = 02BF (703).
- AL'ye ilk boy alındı: 50h = 80. `MUL AL` sonrası AX = 1900h ($80^2 = 6400 = 1900_h$). Bu değer BX'e kopyalandı.
- `SHL SI, 1` sonrası `MOV AX, [SI+00C8]` ile ilk ağırlık okundu: 012Ch = 300. AGIR dizisi, BOY'un 200 byte'ından sonra C8h ofsetindedir.
- `MUL DI` sonrası DX = 0003, AX = 37D4: $300 \cdot 703 = 210900 = 337D4_h$.
- `DIV BX` sonrası AX = 0020 (= 32), DX = 17D4 (kalan 6100).
- `MOV [SI+025A], AX` ile sonuç BMI dizisinin ilk gözüne yazıldı.
- `SHR SI, 1`, `INC SI` sonrası SI = 0001 oldu ve `LOOP` ile CX = 00C7'ye inerek döngü başına dönüldü.

Bütün değerler python ile de kontrol edildi ve DEBUG ekranıyla aynı çıktı.

### 8.6 Soru: DIZI[SI] ile [SI] farkı

**Soru:** `BMI[SI]` ile yazınca da adres mi kullanılmış olur, word dizisinde neden SI ikişer artmalı? **Cevap:** DEBUG'daki `MOV [SI+025A], AX` satırı bunu gösterir: `BMI[SI]` yazımı, köşeli parantez içinde indis yazmacı artı immediate bir değere dönüşür. 025Ah, BMI dizisinin veri kesimine göre başlangıç ofsetidir. Köşeli parantez içinde verilen her şey adrestir. Word dizisinin bir sonraki elemanı 2 byte ötededir. SI bir artırılırsa, birinci word'ün yüksek anlamlı byte'ı ile ikinci word'ün düşük anlamlı byte'ı birleşik okunur ve yanlış bir değer elde edilir.

Hoca tek indis yönteminin neden gösterildiğini de açıkladı: her diziye ayrı yazmaç verip SI'yi birer, DI ve BX'i ikişer artırmak da doğru bir çözümdür. Ama her problemde indislere sırayla erişilmez. Bir byte dizisi ile bir word dizisinin aynı sıradaki elemanlarına sırasız erişmek gerektiğinde, byte indisini ikiyle çarpmak word dizisindeki karşılığa erişmeyi sağlar.

> **Hocanın vurgusu:** Bu örnekte iki noktaya dikkat: aynı indisle hem byte hem word dizisine erişim ve çarpma-bölme içeren hesaplarda önce çarpmanın yapılması. Önce çarpmak hem hassasiyeti korur hem de bölmenin girdisini DX:AX'te hazır bırakır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): 32 bitlik A sayısı ile 32 bitlik B sayısını toplayıp sonucu 64 bitlik bir değişkende saklayan EXE programını yazınız.

> **Çözüm (derste verildi):** Bölüm 3.5'teki kod. Düşük word'ler `ADD`, yüksek word'ler `ADC` ile toplanır, son elde `ADC WORD PTR [BX+4], 0` ile yazılır. $ABCDEF98_h + B9876543_h = 1\,6555\,54DB_h$.

**Soru 2** (derste sözlü, 00:28:39): `ADD WORD PTR [SI], [DI]` yazılabilir mi?

> **Cevap (derste verildi):** Hayır; iki bellek operandı tek komutta kullanılamaz. İşlemci veri yolu üzerinden bir anda tek birimle konuşur.

**Soru 3** (ekrandan, 01:05:00): Verilen 300 elemanlı, pozitif değerlere sahip byte tipindeki dizinin ortalamasını bulan EXE tipindeki assembly programını yazınız. (b) Aynı soruyu 200 elemanlı word dizisi için çözünüz.

> **Çözüm (derste verildi):** (a) Toplam en çok $300 \cdot 255 = 76500$ olduğu için DX:AX'te `ADC AL` / `ADC AH, 0` / `ADC DX, 0` ile biriktirilir, `DIV SI` ile bölünür, `MOV ORT, AL` yazılır (Bölüm 4.4). Deneme verisinde ortalama $FB_h = 251$. (b) `ADC AX` / `ADC DX, 0` / `ADD SI, 2`, çıkışta `SHR SI, 1`, `DIV SI`, `MOV ORT, AX` (Bölüm 6.2). Deneme verisinde ortalama $F999_h$.

**Soru 4** (derste sözlü, 01:07:03): Byte dizisi işaretli olsaydı en kötü durumda toplam 16 bite sığar mıydı?

> **Cevap (derste verildi):** Hayır; $-128 \cdot 300 = -38400 < -32768$. En az 32 bit gerekir.

**Soru 5** (derste sözlü, 01:23:46): Byte ortalaması döngüsü bittiğinde SI'nin değeri nedir; bölmede bu nasıl kullanılır?

> **Cevap (derste verildi):** SI = 300 = N olur; doğrudan `DIV SI` yazılabilir. Word dizisinde SI = 400 olur ve `SHR SI, 1` ile 200'e indirilir.

**Soru 6** (ekrandan, 01:50:00): Pozitif A ve B sayılarının en büyük ortak bölenini $\gcd(A, B) = \gcd(B, A \bmod B)$ ve $\gcd(A, 0) = A$ bilgisini kullanarak bulan EXE programını yazınız.

> **Çözüm (derste verildi):** Bölüm 7.4'teki kod: A < B ise `XCHG`, sonra `CMP BX, 0` / `JE CIKIS` / `XOR DX, DX` / `DIV BX` / `MOV AX, BX` / `MOV BX, DX` / `JMP NOSWAP`, çıkışta `MOV GCD, AX`. $\gcd(20, 16) = 4$, $\gcd(23, 7) = 1$.

**Soru 7** (ekrandan, 02:25:00): Kişi ağırlık ve boy değerlerinin tutulduğu dizileri kullanarak kişilere ilişkin BMI değerini hesaplayın: $BMI = \dfrac{w_{lb}}{h_{in}^2} \times 703$.

> **Çözüm (derste verildi):** Bölüm 8.4'teki kod. Ağırlık word, boy byte, BMI word dizisidir. Önce 703 ile çarpılır, sonra boyun karesine bölünür. Boy 80, ağırlık 300 için $BMI = 210900 / 6400 = 32$.

## Dersin Toparlaması

Bu derste, önceki haftalarda kurulan EXE program iskeleti tekrar edildi ve üzerine dört örnek program yazıldı. Ortak fikirler şunlardır: önce değerlerin alabileceği en kötü aralık hesaplanır ve biriktirici ile sonuç değişkeninin boyutu buna göre seçilir; çok parçalı toplamada elde `ADC` zinciriyle taşınır ve araya giren komutların bayrakları etkileyip etkilemediği instruction set tablosundan kontrol edilir; 16 bitlik çarpma ve bölmede DX:AX sanal 32 bitlik yazmacı olarak kullanılır ve `DIV` öncesi DX belirlenir; tamsayı aritmetiğinde önce çarpılır, sonra bölünür.

Diziler için indis yaklaşımı (`DIZI[SI]`) tanıtıldı. Bu yazımın makine kodunda indis yazmacı artı dizi ofseti olduğu DEBUG'da görüldü. Word dizilerinde indisin ikişer artması, byte ve word dizisine `SHL`/`SHR` ile tek indisle erişim ve boş kolu olan if yapılarında koşulun boş kola göre yazılması örneklerle gösterildi. Bu noktaya kadar yalnız tek ana yordamlı EXE programları işlendi; COM tipi programlar ve alt yordamlar henüz ele alınmadı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
