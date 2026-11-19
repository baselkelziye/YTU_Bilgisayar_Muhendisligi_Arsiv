# Ders 4 Genişletilmiş Notu: Yığın, Döngü, Bayrak, Mantıksal, Öteleme-Döndürme ve Dizi Komutları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yığın Komutları
- 2. Döngü Komutları
- 3. Döngü Şekilleri ve Assembly Karşılıkları
- 4. Bayraklarla İlgili Komutlar
- 5. Mantıksal Komutlar
- 6. Öteleme ve Döndürme Komutları
- 7. Dizi (String) Komutları
- Örnek Sorular

## 1. Yığın Komutları

Geçen hafta karşılaştırma komutu ve koşullu dallanma komutları incelenmişti. Bu hafta önce yığın komutlarına, sonra döngü komutlarına geçildi; dersin ikinci yarısında bayrak, mantıksal, öteleme-döndürme ve dizi komutları işlendi.

### 1.1 Yığının mantığı

Yığın komutları iki gruptur: yığına veri atanlar (PUSH, PUSHF) ve yığından veri çekenler (POP, POPF). Yığın, üst üste konan nesneler gibi çalışır: yalnız en üste veri konabilir, veri çekildiğinde de en üstteki alınır. Bir veri çekildikten sonra sırada kalan en üstteki veri bir sonraki çekmede alınır.

PUSH ve POP kullanıldığında varsayılan segment yazmacı **SS (stack segment)**'tir. Hoca buna dikkat edilmesini istedi.

### 1.2 POP ve POPF

Slaytta POP şöyle tanımlandı (ekrandan, 00:05:00):

```text
POP: pop word from stack
POP dest
dest <- SS:[SP]
POP regw
POP mem
```

POP tek bir parametre alır: hedef, 16 bitlik bir yazmaç ya da bellek adresidir. Bellek adresi verildiğinde BYTE PTR ya da WORD PTR yazmaya gerek yoktur, çünkü POP her zaman bir word (16 bit) çeker.

Çekilen veri SS segmentinin SP offset'indeki veridir. SP başlangıçta yığının en büyük adresini gösterir. Yığına bir şey atıldıkça ikişer azalır, yığından bir şey çekildikçe ikişer artar. İkişer değişmesinin nedeni, yığın komutlarının word ile çalışmasıdır. Yığında hiçbir şey kalmadığında SP yeniden ilk değerine döner: EXE programlarında bu, yığın segmentinin boyutudur. COM programlarında tek bir segment hem kod, hem yığın, hem veri segmenti olarak kullanıldığı için ilk değer FFFEH'tır. Hoca EXE ve COM programlarının ayrıntısına ileride bakılacağını söyledi.

POPF (pop flags from stack), yığının o anki en üstündeki word'ü alıp bayrak yazmacına yazar.

### 1.3 PUSH ve PUSHF

PUSH yığına bir word atar. Tek parametresi kaynaktır ve yığının en üstündeki göze yazılır. Kaynak sabit (immediate) bir değer, 16 bitlik bir yazmaç, bir bellek adresi ya da bir segment yazmacı olabilir. Bellek adresinde yine WORD PTR yazmaya gerek yoktur.

Hoca, PUSH ile segment yazmacının yığına atılabildiğini, ama POP ile yığından segment yazmacına yazılamadığını söyledi. `POP CS` diye bir komut olmadığını, bunun yerine önce `POP AX`, sonra `MOV CS, AX` yazılması gerektiğini anlattı.

> **Ders sonrası not:** Hoca POP ile hiçbir segment yazmacına yazılamadığını söyledi ve CS için `POP AX` + `MOV CS, AX` önerdi. Doğrusu: 8086'da `POP DS`, `POP ES` ve `POP SS` geçerli komutlardır; geçersiz olan yalnız `POP CS`'tir. `MOV CS, AX` da geçersizdir, çünkü CS MOV ile hedef olarak yazılamaz; CS yalnız uzak JMP/CALL ve RET/IRET ile değişir.

PUSHF bayrak yazmacını yığına atar. Bayrak yazmacı 16 bit olduğu için yığının en üstündeki göze doğrudan yazılır.

## 2. Döngü Komutları

Döngü komutları **CX** yazmacıyla birlikte çalışır. CX'in adı count register'dır; döngülerde iterasyon sayısını tutar. Bu yüzden döngüye girmeden önce mutlaka CX'e uygun değer atanmalıdır.

Slayttaki dört döngü komutu şunlardır (ekrandan, 00:10:00):

- LOOP: CX ≠ 0 olduğu sürece döner.
- LOOPZ / LOOPE: CX ≠ 0 ve son işlemin sonucu sıfır (ZF = 1) olduğu sürece döner.
- LOOPNZ / LOOPNE: CX ≠ 0 ve son işlemin sonucu sıfırdan farklı (ZF = 0) olduğu sürece döner.
- JCXZ: CX = 0 ise dallanır.

İlk üçünde CX her döngüde otomatik olarak bir azalır. JCXZ'de ise CX'in nasıl değişeceğini programcı kontrol eder: duruma göre ikişer, üçer ya da birer azaltabilir.

### 2.1 LOOP

LOOP (loop until complete) bir etiketle kullanılır: `LOOP L1`. Örneğin L1 etiketi 100 adresinde, LOOP komutu 110 adresinde olsun. Derlenmiş kodda LOOP'un yanında etiketin adresi değil, aradaki fark kadar görece bir değişim yer alır; slayttaki `disp` (displacement) budur. 8 bitlik displacement ile -128 ile +127 adım arasında ileri ya da geri gidilebilir. Bu değeri programcı hesaplamaz; etiket verildiğinde assembler kendisi displacement'a çevirir.

> **Hocanın vurgusu:** Etiket tanımlanırken adının sonuna iki nokta üst üste konur (`L1:`). Çağrılan tarafta yalnız adı yazılır (`LOOP L1`).

Her LOOP geçişinde CX bir azaltılır, sonra displacement ile gösterilen adrese gidilir. Döngü, CX 0 olduğunda kırılır.

### 2.2 LOOP izleme tablosu

Hoca LOOP'un çalışmasını bir tabloyla izletti. `toplam`, data segmentte tanımlı bir değişkendir (ekrandan, 00:15:00):

| Komut | toplam | CX | SI |
|---|---|---|---|
| `MOV toplam, 0` | 0 | ? | ? |
| `MOV CX, 5` | 0 | 5 | ? |
| `MOV SI, 1` | 0 | 5 | 1 |
| `L1: ADD toplam, SI` | 1 | 5 | 1 |
| `INC SI` | 1 | 5 | 2 |
| `LOOP L1` | 1 | 4 | 2 |

İlk satırda CX ve SI için önceden bilgi olmadığından soru işareti bırakıldı. CX'e 5, SI'ya 1 atanması, döngünün beş kez döneceği ve 1'den 5'e kadar sayıların toplanacağı anlamına gelir.

Adım adım:

- 1. geçiş: toplam = 0 + 1 = 1, SI = 2, LOOP sonrası CX = 4.
- 2. geçiş: toplam = 1 + 2 = 3, SI = 3, CX = 3.
- 3. geçiş: toplam = 3 + 3 = 6, SI = 4, CX = 2.
- 4. geçiş: toplam = 6 + 4 = 10, SI = 5, CX = 1 (ara adım eklendi).
- 5. geçiş: toplam = 10 + 5 = 15, SI = 6, LOOP CX'i 0 yapar ve döngü kırılır.

Sonuç: toplam = 15.

> **Ders sonrası not:** Hoca "CX değeri 0 iken LOOP satırına gelinirse döngü kırılır" dedi. Doğrusu: LOOP önce CX'i bir azaltır, sonra CX'e bakar; azaltma sonunda CX 0 olursa döngüden çıkılır. Döngüye CX = 0 ile girilirse CX FFFFH olur ve döngü 65536 kez döner.

**Soru:** Bu örnekte neden SI kullanıldı? **Cevap:** SI ve DI indeks yazmaçlarıdır; döngünün iterasyon değişkeni gibi düşünülebilirler. Başka bir genel amaçlı yazmaç da kullanılabilirdi. Ama döngü içinde dolaylı adresleme (köşeli parantez içinde yazmaç) gerekirse kullanılabilecek yazmaçlar bunlar olduğundan, SI ve DI'yı indis olarak kullanmak hatayı önler. İleride dizi işlemlerinde bu alışkanlık işe yarayacak.

### 2.3 LOOPZ / LOOPE

LOOPZ de bir etiketle kullanılır; displacement'ı assembler hesaplar. Önce LOOP'un eşdeğeri yazıldı:

```asm
DEC CX
JNZ L1
```

LOOPZ'den hemen önce bayrakları etkileyen bir işlem (CMP, TEST ya da başka bir komut) yapılmış olmalıdır. LOOPZ, bu işlemin sonucu sıfırsa ve CX sıfır değilse döngüye devam eder. Eşdeğeri:

```asm
L1:  ...
     CMP ...
     JNZ CIKIS
     DEC CX
     JNZ L1
CIKIS:
```

Bu, iç içe iki if gibidir: önce sonuç sıfır mı diye bakılır, sıfır değilse çıkılır; sıfırsa CX azaltılır ve CX sıfır değilse L1'e dönülür. İki koşuldan biri sağlanmazsa döngü kırılır.

### 2.4 LOOPNZ / LOOPNE

Slayt (ekrandan, 00:25:00): "LOOPNZ disp. Her loop geçişinde CX azaltılır, sonrasında disp ile gösterilen adrese gidilir. CX≠0 ve ZF=0 olduğu sürece tekrarlanır." Eşdeğeri tahtada şöyle çizildi:

```asm
L1:  ...
     CMP ...
     JZ CIKIS
     DEC CX
     JNZ L1
CIKIS:
```

İşlem sonucu sıfırsa döngüden çıkılır. Sıfır değilse CX azaltılır ve CX 0'a düşmediyse döngüye devam edilir. Yine iki if peş peşe sağlanmaktadır.

### 2.5 JCXZ

JCXZ (jump if CX zero) CX'i kendisi azaltmaz. Döngü içinde CX ile ne yapılacağına programcı karar verir: `SUB CX, 2` ile ikişer azaltılabilir ya da bir koşula göre 1 veya 2 azaltılabilir. Böylece döngünün kaç kez döneceği çalışma sırasında dinamik olarak belirlenebilir.

Tipik kullanım:

```asm
L1:  ...             ; CX'i değiştiren bir işlem
     JCXZ L2         ; CX = 0 ise döngüyü kır
     JMP L1          ; değilse devam et
L2:  ...
```

> **Hocanın vurgusu:** Adı üzerinde, CX 0 olduğunda dallanır. JCXZ'yi döngüyü kıran bir komut olarak düşünün.

## 3. Döngü Şekilleri ve Assembly Karşılıkları

Slaytta beş döngü şekli akış şemasıyla verildi: for to, for downto, while, repeat until ve iç içe for (ekrandan, 00:35:00). Her şemada döngüden önce bir işlem (`AX = 0`) ve döngüden sonra bir işlem (`BX = 1`) var; bunlar döngüye nereden girildiğini ve nereden çıkıldığını ayırt etmek içindir. Döngü içinde döngü değişkeni bir biriktirici yazmaçta (AX) toplanır.

- For to: döngü değişkeni artarak ilerler.
- For downto: döngü değişkeni yüksek değerden sıfıra doğru azalır. Azalma birer birer olsaydı döngü değişkeni olarak doğrudan CX kullanılabilirdi; bu, assembly açısından ek bir yazmaç tutmamayı sağlar.
- While: koşul sağlandığı sürece döngüde kalınır. Koşul baştan sağlanmıyorsa gövde hiç çalışmayabilir.
- Repeat until: koşul sonda sınanır, gövde en az bir kez çalışır. Çıkış koşulu baştan sağlanıyor olsa bile gövde bir kez yapılır.
- Önceki iki for türünde döngünün kaç kez döneceği bellidir; while ve repeat until'de koşula bağlıdır.

İç içe döngüde dikkat edilecek nokta, LOOP ile yazıldığında iki döngünün de CX kullanmak zorunda olmasıdır. İç döngünün CX'i değiştirmesi dış döngüyü bozmamalıdır. Bu yüzden iç döngüye girerken `PUSH CX`, çıkarken `POP CX` yazılır. Slayttaki iç içe döngüde dış döngü I = 0'dan 3'e (0, 1, 2, 3; toplam 4 kez) döner, bu yüzden dış döngü için CX = 4 atanır. İç döngüye girmeden `PUSH CX` ile 4 yığına atılır; iç döngüde CX 4, 3, ... diye azalırken dış döngünün değeri yığında bozulmadan durur. İç döngü kırılınca `POP CX` ile 4 geri alınır, dış döngünün LOOP'u CX'i 3 yapar ve dış döngü 3 değeriyle yeniden çalışır.

<!-- BELİRSİZ: 00:35:00 karesinde hoca iç döngüyü tahtada J = I+1'den 4'e diye değiştirip ilk tur için CX = 4 dedi; kodlama sırasında (01:15:00) slaytın asıl hâli J = 2'den 4'e kullanıldı. Not kodlanan hâli izler. -->

### 3.1 LOOP'u for gibi kullanmak

Ara öncesinde hoca bir genel kural koydu: LOOP, C'deki for'a karşılık gelir.

**Soru:** Döngünün içinde CX sıfırlanırsa LOOP döngüyü kırar mı? **Cevap:** Evet, teknik olarak kırar. Ama bu, kodun anlaşılmasını hem yazan hem okuyan için zorlaştırır. C'de for döngüleri genelde break ile kırılmaz; LOOP da yalnız döngü sayısı belli işler için kullanılmalıdır. Koşula bağlı döngüler için while mantığı (CMP ve koşullu dallanma) ya da JCXZ kullanılmalı; CX ile ilgili koşullar orada kurulursa takip kolay olur.

**Soru:** Clock cycle açısından LOOP mu, CMP ve koşullu dallanma mı daha hızlı? **Cevap:** Hoca ezbere bilmediğini söyledi. Koşullu dallanma tek başına kullanılamaz; LOOP yerine yazıldığında CMP, koşullu dallanma ve ters koldaki JMP olmak üzere ek komutlar gelir. LOOP da arka planda CX'i karşılaştırır, azaltır ve dallanır; bu yüzden belki eşdeğer bir süreye çıkabileceğini, ama yanılıyor olabileceğini söyledi. Asıl kural: LOOP döngü sayısı belli işler için, koşullu dallanma sayısı belli olmayan işler için.

### 3.2 For to

Akış şeması (ekrandan, 00:40:00): `AX = 0`; I = 1'den 10'a, birer artarak; gövde `AX = AX + I`; çıkışta `BX = 1`.

Önce AX sıfırlanır. Bunun için `MOV AX, 0` yazılabilir; hoca eşdeğeri olan `XOR AX, AX`'i hatırlattı.

**Soru:** Neden `XOR AX, AX` tercih ediliyordu? **Cevap:** İkisi de AX'e sıfır atar, ama XOR daha az clock cycle'da çalışır (ayrıntısı 5.4'te).

Sonra I için `MOV SI, 1`, döngü sayısı için `MOV CX, 10` yazılır (1'den 10'a 10 kez):

```asm
     XOR AX, AX
     MOV SI, 1
     MOV CX, 10
L1:  ADD AX, SI
     INC SI
     LOOP L1
     MOV BX, 1
```

Sonuç: AX = 1 + 2 + ... + 10 = 55. Bu kod akış şemasının birebir karşılığıdır.

Bu çözüm ek bir indis yazmacı kullanır. Döngü içinde CX zaten 10'dan 1'e kadar değer alır, döngüden CX = 0 ile çıkılır. Bu yüzden döngü değişkenine gerek olmayabilir:

```asm
     XOR AX, AX
     MOV CX, 10
L1:  ADD AX, CX
     LOOP L1
     MOV BX, 1
```

İşlevsel olarak ikisi eşdeğerdir: ilkinde AX'e önce 1, sonra 2, 3 ... eklenir; ikincisinde önce 10, sonra 9, 8 ... eklenir. İkinci biçim gövdede yalnız yazmaç toplaması olduğu için uygundur. Gövdede `[SI]` gibi bellek erişimi olsaydı SI'yı indis olarak kullanmak zorunlu olurdu. Hoca ilk biçime alışmanın da iyi olacağını söyledi.

### 3.3 For downto

Akış şeması (ekrandan, 00:30:00): `AX = 0`; I = 10'dan 0'a, ikişer azalarak; gövde `AX = AX + I`; çıkışta `BX = 1`.

Döngü değişkeni ikişer azalıp sıfırda bittiği için bu yapı JCXZ'ye çok uygundur. Hoca kodu tahtada şöyle kurdu (ekrandan, 00:45:00):

```asm
     MOV AX, 0
     MOV CX, 10
L1:  ADD AX, CX
     SUB CX, 2
     JCXZ L2
     JMP L1
L2:  MOV BX, 1
```

AX'e her adımda o anki döngü değişkeni (CX) eklenir: 10 + 8 + 6 + 4 + 2 = 30. Slayttaki "2" kutusu için ayrıca "×2" yazmaya gerek olmadığını, downto olduğu için azalmanın dolaylı olarak anlaşıldığını söyledi.

> **Hocanın vurgusu:** 10 çift sayı olduğu için ikişer azaltınca CX mutlaka bir yerde sıfıra varır. Başlangıç değeri dışarıdan geliyorsa ve azaltma onu tam sıfıra eriştirmeyebiliyorsa JCXZ yetmez.

Bu durumda CX'i işaretli bir karşılaştırmayla sınamak gerekir: sayı negatife geçebileceği için `CMP CX, 0` ve işaretli sayılarda geçerli olan less/greater ailesinden bir koşullu dallanma kullanılır.

<!-- BELİRSİZ: Hoca bu kısmı tahtada yazıp sildi ve "JLE ise döngüye devam, L1" dedi (00:48:08). CX ≤ 0 iken döngüden çıkılmalıdır: doğru biçim `CMP CX, 0` + `JLE L2` (çıkış) + `JMP L1`, ya da `CMP CX, 0` + `JG L1`. O anın karesi yok. -->

### 3.4 While

Akış şeması (ekrandan, 00:50:00): `AX = 0`; `I = 1`; koşul `I ≤ 10` doğruysa (T) `AX = AX + I` ve `I = I + 2`, sonra koşula dönülür; yanlışsa `BX = 1`.

Alışkanlık olsun diye `XOR AX, AX` ile başlanır, I için `MOV SI, 1` yazılır. Koşul "SI ≤ 10 ise devam"dır. Koşullu dallanma derslerinde görüldüğü gibi, if'lerde yanlış (false) kolu yazmak işi kolaylaştırır. Yanlış kol "SI > 10"dur ve işaretsiz sayı için JA ile yazılır:

```asm
     XOR AX, AX
     MOV SI, 1
L2:  CMP SI, 10
     JA L1
     ADD AX, SI
     ADD SI, 2
     JMP L2
L1:  MOV BX, 1
```

Sonuç: AX = 1 + 3 + 5 + 7 + 9 = 25.

Hoca geri dönüş etiketinin nereye konacağını sordu ve toplama satırına dönülürse karşılaştırma bir daha yapılmayacağı için sonsuz döngüde kalınacağını gösterdi; L2 karşılaştırmanın yapıldığı satırda olmalıdır.

> **Hocanın vurgusu:** Bu tür döngülerdeki hataların büyük kısmı etiketin yanlış yere konmasından kaynaklanır. Birincisi etiket tanımında iki nokta üst üste unutulur, ikincisi döngünün nereye bağlanacağı kaçırılır. Etiketlere anlamlı adlar verin: çıkış etiketine `CIKIS`, dönüş etiketine `TEKRAR` gibi.

### 3.5 Repeat until

Ara sonrasında repeat until ile devam edildi. Akış şeması (ekrandan, 00:55:00): `AX = 0`; `I = 2`; `AX = AX + I`; `I = I + 2`; koşul `I > 10` yanlışsa (F) toplamaya dönülür, doğruysa `BX = 1`. While'dan farkı, gövdenin en az bir kez çalışmasıdır.

Hoca koşulu önce "SI = 10 ise sonlandır" diye yazmaya başladı, sonra düzeltti: I, 2'den başlayıp ikişer arttığı için I 10'u geçtiğinde döngü kırılır, yani I ≤ 10 olduğu sürece devam edilir. Yanlış kol için işaretsiz sayılarda "below or equal" kullanılır (ekrandan, 01:10:00):

```asm
     XOR AX, AX
     MOV SI, 2
L1:  ADD AX, SI
     ADD SI, 2
     CMP SI, 10
     JBE L1
     MOV BX, 1
```

L1 toplamanın yapıldığı satırdadır. Sonuç: AX = 2 + 4 + 6 + 8 + 10 = 30.

### 3.6 İç içe for

Akış şeması (ekrandan, 01:15:00): `AX = 0`; dış döngü I = 0'dan 3'e birer; iç döngü J = 2'den 4'e birer; iç gövde `AX = AX + I + J`; çıkışta `BX = 1`.

İçeride dış döngü değişkeni de kullanıldığı için I'yı SI ile, J'yi DI ile tutmak anlamlıdır. SI de alışkanlık olsun diye XOR ile sıfırlanır. Dış döngü 0, 1, 2, 3 için 4 kez döner (`MOV CX, 4`); iç döngü 2, 3, 4 için 3 kez döner (`MOV CX, 3`). Tahtadaki kod:

```asm
     XOR AX, AX
     XOR SI, SI
     MOV CX, 4
L1:  PUSH CX
     MOV DI, 2
     MOV CX, 3
L2:  ADD AX, SI
     ADD AX, DI
     INC DI
     LOOP L2
     POP CX
     INC SI
     LOOP L1
     MOV BX, 1
```

<!-- BELİRSİZ: Hoca dış döngüde SI'yı artırmayı unuttuğunu söyleyip `INC SI` ekledi (01:15:15); satırın tam yeri altyazıda net değil. I'nın 0'dan başlaması için iç döngüden sonra (POP CX ile LOOP L1 arasında) olması gerekir. -->

Çalışma: CX = 4 yığına atılır. İç döngü CX = 3 ile başlar, CX 2, 1, 0 olur ve iç döngü kırılır. `POP CX` dış döngünün 4 değerini geri yükler, SI artar, LOOP CX'i 3 yapar ve başa dönülür; bu kez yığına 3 atılır. Sonuç: her I için iç toplam $3I + 9$, toplam $\sum_{I=0}^{3}(3I+9) = 54$ (python ile doğrulandı).

> **Hocanın vurgusu:** PUSH ve POP birer parantez gibidir. Parantez açıldıysa uygun yerde kapatılmalıdır; yoksa yığına atılan ile yığından çekilen miktar örtüşmez ve yanlış değerler çekilir.

PUSH ve POP, emu8086'da ya da DOSBox üzerindeki debug aracında bir EXE veya COM programı olmadan da istenen yerde çalıştırılabilir; POP varsa yığından bir şey çeker, PUSH varsa yığına bir şey atar. Ama bir program akışı içinde yığına ne atıldıysa aynı miktar çekilmelidir. Slayttaki çözümde döngü değişkenleri ters seçilmişti (dışta DI, içte SI); mantık aynıdır. Üç iç içe for da yazılabilir: her iç for'a girmeden önce bir üst for'un CX'i yığında saklanmalıdır.

## 4. Bayraklarla İlgili Komutlar

Bayrak yazmacı 16 bitlik bir yazmaçtır ama 16 ayrı bayrak yoktur. Auxiliary, carry, parity, zero, sign, direction gibi belirli bayraklar vardır. Yalnız bazı bayrakların özel komutu vardır; diğerleri için başka bir yol izlenir. Slayttaki liste (ekrandan, 01:20:00):

| Komut | Anlamı |
|---|---|
| CLC | clear carry flag |
| CMC | complement carry flag |
| STC | set carry flag |
| CLD | clear direction flag |
| STD | set direction flag |
| STI | set interrupt flag |
| CLI | clear interrupt flag |
| LAHF | load AH with flag: AH ← SF, ZF, ?, AF, ?, PF, ?, CF |
| SAHF | store AH to flag: SF, ZF, ?, AF, ?, PF, ?, CF ← AH |

### 4.1 Carry bayrağı komutları

CLC carry'yi sıfırlar, STC 1 yapar. CMC carry'nin tümleyenini alır; hoca bunu XOR ile gösterdi (ekrandan, 01:30:00):

$$C \oplus 1 = C \cdot \bar{1} + \bar{C} \cdot 1 = \bar{C}$$

Yani C 1 ise 0, 0 ise 1 olur. Carry önemlidir, çünkü öteleme ve döndürme işlemlerinde bitler carry üzerinden geçebilir; carry'deki bir biti sınamak ya da algoritmada carry'de belirli bir değer oluşturmak gerektiğinde bu komutlar kullanılır.

### 4.2 Direction bayrağı komutları

CLD direction bayrağını sıfırlar, STD 1 yapar. Direction bayrağı dizi işlemlerinde adres yönünü belirler. DF = 0 ise her kopyalama işleminden sonra hem kaynak hem hedef adresi bir artar. DF = 1 ise adresler birer azalır; kaynak ve hedef dizilerin son adreslerinden başlanıp ilk adreslerine doğru gidilir.

### 4.3 Interrupt bayrağı ve veri aktarım yöntemleri

IF bayrağı yalnız 8086'nın INTR ucuna gelen kesme istekleriyle ilgilidir. Dış çevre birimleri bu fiziksel uçta lojik 1 seviyesi oluşturursa işlemci bunu bir kesme isteği olarak değerlendirir.

Hoca, bunun işlemcide veri aktarımının üç yolundan biri olduğunu anlattı:

- Polling: İşlemci belirli bir koşul sağlanana kadar bir bayrağı döngü içinde sürekli kontrol eder ("veri hazır mı?"). Veri hazır olunca okur. Burada aktif bir bekleme vardır.
- Interrupt: Çevre birimi hazır olduğunda kesme üretecek şekilde ayarlanır, işlemci o arada başka işlerle uğraşır. INTR ucundan istek gelince mevcut işi kesip çevre biriminden veriyi okur.
- DMA (Direct Memory Access): İlk iki yolda veri, bellekten çevre birimine, çevre biriminden belleğe ya da iki bellek birimi arasında aktarılırken işlemciden geçer. DMA'da işlemci aradan çıkar; kaynak ve hedef birimler bir DMA denetleyicisi üzerinden adresleri ve aktarılacak miktarı ayarlar, aktarım işlemci olmadan yapılır.

IF = 1 ise INTR ucundan gelen kesme istekleri değerlendirilir, IF = 0 ise dikkate alınmaz. STI ve CLI bu bayrağı ayarlar.

### 4.4 LAHF ve SAHF ile diğer bayraklar

SF, ZF, AF ve PF için özel komut yoktur. Bunlar için LAHF ve SAHF kullanılır. LAHF, bayrak yazmacının düşük 8 bitini AH'ye kopyalar; bu bitlerden 5'i anlamlıdır (SF, ZF, AF, PF, CF), 3'ü boştur. Bit sırası: 7 SF, 6 ZF, 5 boş, 4 AF, 3 boş, 2 PF, 1 boş, 0 CF. SAHF, AH'deki değeri aynı sırayla bayrak yazmacının bu bitlerine yazar.

Fikir şudur: bayraklar LAHF ile AH'ye alınır, AH üzerinde bit işlemi yapılır, SAHF ile geri yazılır. Hoca bunun için kullanılacak bit özdeşliklerini tahtaya yazdı (ekrandan, 01:35:00):

- $x + 1 = 1$
- $x \cdot 0 = 0$
- $x \oplus 0 = x$
- $x \oplus 1 = \bar{x}$

Bunlara ek olarak $x \cdot 1 = x$ ve $x + 0 = x$, yani diğer bitleri korumak için AND'de 1, OR ve XOR'da 0 kullanılır.

Üç örnek çözüldü (her biri Örnek Sorular bölümünde de var):

- SF'nin tümleyenini almak (ekrandan, 01:30:00): `LAHF` ile AH'nin 7. biti SF olur. `XOR AH, 80H` yalnız 7. biti tersler, diğer bitler 0 ile XOR'landığı için korunur. `SAHF` ile geri yazılır.
- SF'yi sıfırlamak: `LAHF`, sonra `AND AH, 7FH`, sonra `SAHF`. 7FH = 0111 1111'dir; 7. bit 0 ile AND'lendiği için kesinlikle 0 olur, diğerleri 1 ile AND'lendiği için korunur. Derste tartışılan iki kez XOR'lama sonucu değiştirmez (x ⊕ 1 ⊕ 1 = x); 80H ile AND'leme ise diğer bitleri sıfırlar ama SF'yi olduğu gibi bırakır.
- PF'yi 1 yapmak (ekrandan, 01:35:00): `LAHF` ile AH'nin 2. biti PF olur. Yalnız 2. biti 1 olan sabit 0000 0100 = 04H'tir. `OR AH, 04H` bu biti kesinlikle 1 yapar, diğer bitler 0 ile OR'landığı için değişmez. Ardından `SAHF`.

Böylece özel komutu olmayan bayraklar için genel set ve clear işlemleri kurulmuş olur.

## 5. Mantıksal Komutlar

Mantıksal komutlar NOT, OR, AND, XOR ve TEST'tir (ekrandan, 01:40:00). Bunların bir kısmının aritmetik komutlarda benzeri vardır.

### 5.1 NOT ve NEG

NOT bire tümleyen, NEG ikiye tümleyen üretir. Örnek: AL = 1001 1100.

- `NOT AL` → AL = 0110 0011 (her bit terslenir).
- `NEG AL` → AL = −AL, ikiye tümleyen: 0110 0100.

> **Ders sonrası not:** Hoca bu sayıyı işaretli olarak −68, NEG sonucunu +68 diye okudu. Doğrusu: 1001 1100 = 9CH, işaretli 8 bit olarak −100'dür; NEG sonucu 0110 0100 = 64H = +100'dür ($6 \cdot 16 + 4 = 100$). Python ile doğrulandı. Hocanın ikiye tümleyen için söylediği bit dizisi de altyazıda farklı geçiyor; doğru sonuç 0110 0100'dür.

NOT tek işlenen alır; yazmaç ya da bellek olabilir. Bellek işleneninde boyutu belirtmek için mutlaka WORD PTR ya da BYTE PTR kullanılmalıdır.

### 5.2 OR ve AND

OR bit bit (bitwise) VEYA yapar. Örnek (ekrandan, 01:40:00):

```text
AL       = 1100 0110
88H      = 1000 1000
OR AL,88H: 1100 1110
```

AND bit bit VE yapar. Sabitte 1 olan bitler korunur, 0 olan bitler sıfırlanır (maskelenir). Aynı AL ile:

```text
AL        = 1100 0110
88H       = 1000 1000
AND AL,88H: 1000 0000
```

<!-- BELİRSİZ: Altyazıda AND örneğinde AL "11001100" diye geçiyor; karede AL ← 1100 0110 ve sonuç 1000 0000 yazılı, not kareyi izler (01:39:17). -->

OR ve AND iki parametre alır, sonucu hedefe yazar. Kullanılabilen biçimler: yazmaç-sabit, bellek-sabit, yazmaç-yazmaç, yazmaç-bellek, bellek-yazmaç.

> **Hocanın vurgusu:** Bellek ile sabit kullanılan işlemlerde PTR mutlaka yazılmalıdır. Örneğin `OR [100H], 80H` yazılırsa 80H mı yoksa 0080H mı kastedildiği belli değildir; bunu WORD PTR ya da BYTE PTR belirler. Bir derleyici ya da emülatör varsayılan olarak byte ya da word kabul ediyor olabilir; bu önemli değil. Derslerde ve sınavlarda boyut açıkça yazılmalıdır.

### 5.3 XOR

XOR bit bit özel VEYA yapar; iki yazmaç arasında ve yazmaç ile bellek arasında kullanılabilir. Bir biti 0 ile XOR'lamak kendisini, 1 ile XOR'lamak tümleyenini verir. Slayt (ekrandan, 01:45:00):

- `XOR AL, 0FFH` → AL'deki 1'ler 0, 0'lar 1 yapılır. Yani `NOT AL`'ye denktir.

Bir biti kendisiyle XOR'lamak:

$$x \oplus x = x \cdot \bar{x} + \bar{x} \cdot x = 0$$

Her iki çarpım da sıfırdır, sonuç sıfırdır. Bu yüzden bir yazmacı kendisiyle XOR'lamak bütün bitlerini sıfırlar: `XOR AX, AX`.

### 5.4 XOR AX, AX neden tercih edilir

Slaytta `XOR AX, AX ; 4 clock cycle, 3 byte` ve `MOV AX, 0 ; 3 clock cycle, 2 byte` yazıyordu (ekrandan, 01:45:00). Hoca değerlerin ters yazıldığını söyleyip düzeltti:

- `XOR AX, AX`: 3 clock cycle, 2 byte.
- `MOV AX, 0`: 4 clock cycle, 3 byte.

Bu yüzden AX'i sıfırlamak için `XOR AX, AX` tercih edilir.

### 5.5 TEST

TEST'in aritmetik komutlardaki karşılığı CMP'dir. CMP arka planda hedef − kaynak çıkarmasını yapar, sonucu saklamaz ama bayrakları etkiler. TEST de aynı mantıkla çalışır, ama çıkarma yerine hedef AND kaynak işlemini yapar. Slayt (ekrandan, 01:50:00):

```text
TEST : test bits
TEST dest, src
dest AND src
Sadece bayraklar değişir, sonuç saklanmaz
TEST reg, idata
TEST mem, idata; PTR gerekli
TEST reg, reg
TEST reg, mem
TEST mem, reg
```

CMP ile büyüklük-küçüklük ve eşitlik durumları denetlenir; TEST ile bir bitin 1 mi 0 mı olduğu anlaşılır. TEST de CMP gibi koşullu dallanma komutlarıyla birlikte kullanılır.

### 5.6 Kapı örneği

Bir donanım 8 farklı kapının açık ya da kapalı olduğunu okuyup AL'ye aktarıyor. AL'nin i. biti i. kapının durumudur: 1 kapı açık, 0 kapı kapalı (ekrandan, 01:50:00). Soru: 6 numaralı kapının açık mı kapalı mı olduğunu anlayıp uygun etikete dallanmak.

**Soru:** Bu CMP ile yapılabilir mi? **Cevap:** Hayır. CMP sabit bir değerle karşılaştırır; değeri sabitlemek bütün bitleri belirlemek demektir. Oysa yalnız bir bitle ilgileniliyor, diğer 7 bit "don't care"dir. Bir bit sabit, diğerleri değişken olunca $2^7 = 128$ farklı değer çıkar; her biriyle ayrı ayrı karşılaştırmak mümkün değildir. Bu yüzden TEST kullanılır.

6. biti 1 olan sabit 0100 0000 = 40H'tir. `TEST AL, 40H` yapılınca, 6. bit 1 ise sonuç sıfırdan farklı, 0 ise sonuç sıfır olur:

```asm
     TEST AL, 40H
     JZ KAPALI_6
     ...              ; 6. kapı açık
KAPALI_6:
     ...              ; 6. kapı kapalı
```

Hoca etiket adlarının rakamla başlamaması gerektiğini (zannettiğini) söyleyerek `6_KAPALI` gibi bir ad yerine alt çizgili bir ad kullandı. Arada uygun JMP'ler olduğu varsayılır. Sonuç olarak CMP sabit bir değerle karşılaştırmak için, TEST tek bir bitin değerini belirlemek için kullanılır.

### 5.7 Population count

Aynı soru farklı biçimde de sorulabilir: kaç kapının açık olduğunu, yani bir yazmaçta kaç tane 1 olduğunu bulmak. Bu işleme **population count** denir. Bir öğrencinin önerdiği gibi öteleme ve carry kontrolüyle yapılır (ekrandan, 01:55:00):

- AL bir bit sağa ötelenir, en düşük bit carry'ye düşer.
- Carry `JC` (carry = 1 ise dallan) ile sınanır; dallanılan etikette sayaç bir artırılır.
- Ya da JC kullanmadan `ADC BX, 0` yazılır: BX'e 0 ile birlikte carry eklenir, carry'deki bit doğrudan sayaca toplanır.

Bu 8 adımlık bir döngüye konursa, her ötelemeyle sıradaki bit carry'ye gelir ve bütün bitler sayılır.

## 6. Öteleme ve Döndürme Komutları

Öteleme komutları shift, döndürme komutları rotate işlemleridir. Temel fark şudur: shift'te bir yöne kaydırınca boş kalan bit 0 ile doldurulur, uçtan çıkan bit kaybolur. Rotate'te boş kalan yere öbür uçtan çıkan bit gelir.

Shift komutları aritmetik ve lojik olarak ikiye ayrılır: SHL (shift logical left), SAL (shift arithmetic left), SHR (shift logical right), SAR (shift arithmetic right). Aritmetik işlemlerde önemli olan sayının işaret bitini korumaktır. SAL ile SHL birbirinin aynısıdır; yalnız SAR özel bir durum oluşturur. Rotate komutları da carry'yi içine alanlar (RCL, RCR) ve almayanlar (ROL, ROR) olarak ikiye ayrılır.

### 6.1 SHL

Slayt (ekrandan, 02:00:00): her bit bir üst bite kopyalanır, en yüksek bit CF'ye gider, boş kalan en düşük bite 0 girer. Biçimler: `SHL reg, 1`, `SHL mem, 1`, `SHL reg, CL`, `SHL mem, CL`; `SAL = SHL`.

> **Hocanın vurgusu:** Bu genel olarak hata yapılan bir nokta. Öteleme miktarı 1 ise doğrudan sabit olarak yazılabilir; 1'den fazlaysa mutlaka CL yazmacı üzerinden verilir. `SHL AX, 4` diye bir komut yoktur. Bunun yerine `MOV CL, 4` ve `SHL AX, CL` yazılır. `SHL BX, 1` ise geçerlidir. CL yerine DL ya da başka bir yazmaç kullanılamaz.

> **Ek bilgi (derste anlatılmadı):** 1'den büyük sabit öteleme miktarı (`SHL AX, 4`) 80186 ve sonraki işlemcilerde geçerlidir; 8086'da yoktur. Dersin konusu 8086 olduğu için kural CL'dir.

Miktarın neden CX değil de CL'de verildiği de açıklandı. 16 bitlik bir yazmacı en fazla 16 kez ötelemenin ya da döndürmenin anlamı vardır; sonraki döndürmeler öncekilerin tekrarıdır. Bu sayı 8 bite sığdığı için CL yeterlidir.

`SHL AX, CL` komutunda 16 bitlik bir yazmaçla 8 bitlik bir yazmaç yan yana durur. MOV'da tip uyumu gerektiği için 8 bitlik bir yazmaç 16 bitlik bir yazmaca kopyalanamaz; ama öteleme ve döndürmede bu özel bir durumdur ve komut geçerlidir.

> **Hocanın vurgusu:** Hoca, kod bloğundaki hataları düzeltme sorularında içinde 16 bitlik yazmaçla CL'nin yan yana olduğu bir SHL ya da SHR koyduklarını ve bunun genelde yanlışlıkla hatalı işaretlendiğini söyledi. Bu satır hatalı değildir.

Bir öğrencinin sorusu üzerine, bellek işleneninde BYTE PTR ya da WORD PTR'nin gerekebileceği de belirtildi.

### 6.2 SHR

En yüksek anlamlı bitler düşük anlamlı bitlere doğru kopyalanır, boş kalan en yüksek bite 0 yüklenir, en düşük bit CF'ye aktarılır. Bellek işleneninde yine PTR unutulmamalı, birden fazla ötelemede yine CL kullanılmalıdır. `SHR BX, CL` geçerli bir komuttur.

### 6.3 SAR

Slayt (ekrandan, 02:05:00): "SAR: shift arithmetic right. Öteleme işleminde sayının işaret bitini dikkate alır." Biçimler SHL ile aynıdır. MSB hem kendi yerinde kalır hem bir sağa kopyalanır, en düşük bit CF'ye gider.

Örnek: 1000 0000 (−128) bir kez SAR ile ötelenirse bütün bitler bir sağa kayar, boş kalan en yüksek bite öncekinin işaret biti (1) konur: 1100 0000 = −64. İşaret korunmasaydı (lojik öteleme) en yüksek bite 0 gelir ve sonuç +64 olurdu.

Öteleme komutlarının aritmetik anlamı:

- SHL (= SAL): 2 ile çarpma.
- SHR: 2'ye bölme.
- SAR: işarete dikkat ederek 2'ye bölme, yani işaretli ikiye bölme.

Hoca dört kez SAR örneğini adım adım yaptı:

```asm
MOV AL, 80H
MOV CL, 4
SAR AL, CL
```

- Başlangıç: 1000 0000 = −128
- 1. öteleme: 1100 0000 = −64
- 2. öteleme: 1110 0000 = −32
- 3. öteleme: 1111 0000 = −16
- 4. öteleme: 1111 1000 = −8

Sonucun negatif olduğu MSB'den anlaşılır; genliği bulmak için ikiye tümleyeni alınır: ilk 1'e kadar olan bitler aynen bırakılır, sonrakilerin hepsi terslenir.

> **Ders sonrası not:** Hoca dört ötelemeden sonra elde edilen sayının −16 olduğunu söyledi. Doğrusu: −128'i dört kez ikiye bölmek −8 verir; dört SAR sonrası AL = 1111 1000 = F8H = −8'dir. −16, üç ötelemeden sonraki değerdir (python ile doğrulandı).

### 6.4 RCL ve RCR

RCL (rotate carry left), elde 9 bitlik sanal bir yazmaç varmış gibi çalışır: işlenenin en yüksek biti CF'ye aktarılır, CF'deki değer en düşük bite aktarılır, diğer bitler birer sola kayar. Bir kez döndürme sabit 1 ile, birden fazla döndürme CL ile verilir; bellek işleneninde PTR gerekir. `RCL AX, CL` geçerli bir komuttur.

RCR (rotate carry right) aynı mantıkla sağa döndürür: en düşük bit CF'ye gider, CF'deki değer en yüksek bite döner.

### 6.5 ROL ve ROR

ROL ve ROR'da döndürme, işlenenin kendi bitleri içinde yapılır; döndürme yönüne göre en yüksek ya da en düşük bit öbür uca geçerken CF'ye de kopyalanır. CF yalnız kopyalama için kullanılır. Bellek işleneninde PTR, birden fazla döndürmede CL kuralları burada da geçerlidir.

> **Ders sonrası not:** Hoca ROL/ROR'u "döndürme yalnız 8 bitlik alanda yapılır" diye anlattı. Bu, byte işlenen içindir; işlenen word ise döndürme 16 bit üzerinde yapılır (RCL/RCR'de de word için sanal yazmaç 17 bittir).

Öteleme ve döndürmenin en yaygın kullanıldığı yerlerden biri az önce görülen population count'tur. Bu, while döngüsü içinde JC ya da ADC ile yapılan, kontrol gerektiren uzun bir işlemdir. Güncel işlemcilerde bir değerde kaç tane 1 olduğunu tek komutla bulan özel komutlar vardır.

## 7. Dizi (String) Komutları

Hoca kalan komut gruplarını sıraladı: dizi komutları, giriş-çıkış komutları, bekletme komutları ve BCD komutları; ardından adresleme kiplerine geçilecek. Bu konulardan ayrıntıya girmeden geçileceğini söyledi.

### 7.1 Dizi komutları dolaylı döngüdür

Slayttaki liste (ekrandan, 02:15:00):

| Grup | Komutlar |
|---|---|
| Kopyalama | MOVSB, MOVSW |
| Karşılaştırma | CMPSB, CMPSW |
| Tarama | SCASB, SCASW |
| Yükleme | LODSB, LODSW |
| Saklama | STOSB, STOSW |
| İşaret genişletme | CBW, CWD |
| Önekler | REP, REPE/REPZ, REPNE/REPNZ |

Dizi komutları içinde bir döngü barındırır. Tek satırlık bir komuttur ama arka planda, LOOP komutunun eşdeğerinde görüldüğü gibi, CX kadar tekrar eden bir döngü çalışır. Bu yüzden komutu çalıştırmadan önce CX'te uygun değerin oluşturulması gerekir.

Her komutun byte (B) ve word (W) sürümü vardır. Komut, aldığı adresin bir byte dizisi mi word dizisi mi olduğuna bakmaz; bu kontrol programcıdadır. Örneğin iki byte'lık elemanlardan oluşan bir word dizisi tanımlanıp başlangıç adresiyle byte dizi işlemi yapılabilir, assembler sorun çıkarmaz. Adresler adrestir, her adreste bir byte saklanır; onu byte mı word mü ele alacağı programcıya kalmıştır.

Tekrar sayısı CX'te tutulur ve REP, REPE, REPNE gibi öneklerle tekrarlı işlem elde edilir.

### 7.2 Hazırlık: CX, DF, DS:SI, ES:DI

Bir dizi işleminden önce üç hazırlık yapılır:

- 1. CX'e uygun değer (eleman sayısı) yazılır.
- 2. DF'ye uygun değer verilir. DF = 0 ise referans olarak dizilerin başlangıç adresleri verilir ve her adımda bir sonraki büyük adrese gidilir. DF = 1 ise referans dizilerin son adresleridir ve her adımda bir azalarak dizinin ilk adresine doğru gidilir.
- 3. Başlangıç adresleri hazırlanır: kaynak DS:SI, hedef ES:DI.

> **Ders sonrası not:** Hoca DF = 1 durumunu anlatırken bir yerde "DF değerim sıfırsa" dedi (02:19:55); bağlamdan doğrusu DF = 1'dir.

### 7.3 Komutlar tek tek

- MOVS (MOVSB, MOVSW): DS:SI'daki veriyi ES:DI'ya kopyalar. Kaynaktaki değer kaybolmaz. MOVSB'de SI ve DI birer, MOVSW'de ikişer otomatik olarak değişir (DF'ye göre artar ya da azalır). Bir dizinin tamamını başka bir adrese kopyalamak için kullanılır.
- CMPS (CMPSB, CMPSW): DS:SI ile ES:DI'daki elemanları karşılaştırır. Çıkarma yapar, sonucu saklamaz, yalnız bayraklar etkilenir; bayraklar tekrarın ne kadar süreceğini belirlemek içindir. İki dizideki ilk farklı elemanı ya da ilk eşleşmeyi bulmak için kullanılır.
- SCAS (SCASB, SCASW): CMPS iki dizi arasında karşılaştırırken SCAS, AL (byte) ya da AX (word) ile ES:DI'daki elemanı karşılaştırır. Yazmaçtaki bir referans değeri dizide bulana kadar aramak için kullanılır.
- LODS (LODSB, LODSW): Dizinin sıradaki elemanını (DS:SI) AL ya da AX'e yükler. Dizinin elemanlarını sırayla alıp işlemek için kullanılır.
- STOS (STOSB, STOSW): AL ya da AX'teki değeri dizinin sıradaki gözüne (ES:DI) yazar. Bütün elemanlara aynı ilk değeri vermek için hızlı bir yoldur.

<!-- BELİRSİZ: Hoca MOVS ve CMPS'i anlatırken birkaç yerde kaynak ile hedefi karıştırdı ("destination bölgesi data segment ve source index", "MOVS WORD her seferinde bir byte"); not doğru eşleşmeyi (kaynak DS:SI, hedef ES:DI) yazar. Hoca LODS/STOS slaytında da bir yanlışlık olabileceğini söyleyip sonra sorun olmadığını belirtti (02:30:22). -->

### 7.4 CBW ve CWD

CBW (convert byte to word) ve CWD (convert word to double word) işlenen almaz; gizli işlenenleri vardır. İkisi de işareti koruyarak genişletir (sign extend). Kare (ekrandan, 02:35:00):

- CBW: AX ← AL. AL = 1000 0000 (8 bit işaretli −128) iken CBW sonrası AX = 1111 1111 1000 0000 = FF80H olur; bu da 16 bit işaretli olarak −128'dir.
- CWD: DX:AX ← AX. AX = −128 iken CWD sonrası DX:AX 32 bitlik sanal bir yazmaç gibi düşünülür ve yine −128'i tutar; DX'in bütün bitleri 1 olur (FFFFH).

Fark, aynı değerin AL'de 8 bit, AX'te 16 bit, DX:AX'te 32 bit işaretli sayı olarak ele alınmasıdır.

CWD'nin kullanıldığı yer bölmedir. İşaretli bölme komutu IDIV, örneğin `IDIV BX`, DX:AX'i BX'e böler. AX'teki 16 bitlik işaretli bir sayıyı bölmeden önce CWD ile 32 bite genişletmek gerekir.

### 7.5 LEA ile başlangıç adresi

Hoca LEA'yı hatırlattı: değişkenin adresini alır. Daha teknik olarak, değişkenler data segmentte tanımlanır ve adres segment:offset biçimindedir. `dizi1 DB ...`, `dizi2 DW ...`, `var DW 5` gibi tanımlarda değişkenin segment başından itibaren kaçıncı offset'te olduğu hesaplanmaz; LEA bu offset'i, yani başlangıç adresini verir (ekrandan, 02:40:00).

### 7.6 Örnek: diziyi sıfırlamak

Kare (ekrandan, 02:40:00):

```asm
LEA DI, dizi     ; DI <- offset(dizi), başlangıç adresi
CLD              ; DF <- 0
XOR AL, AL       ; AL <- 0
MOV CX, size     ; CX <- eleman sayısı
REP STOSB        ; dizi[i] <- AL
```

REP öneki, CX 0 olana kadar tekrarla ve her adımda CX'i bir azalt demektir; tahtada eşdeğeri `DEC CX` + `JZ CIKIS` olarak yazıldı.

> **Ek bilgi (derste anlatılmadı):** REP, CX'i her tekrardan önce sınar: CX başta 0 ise string komutu hiç çalışmaz. Sonra komutu bir kez çalıştırır ve CX'i azaltır. Bu yüzden tahtadaki eşdeğer, sınamanın komuttan önce yapıldığı bir döngü olarak okunmalıdır.

Adım adım: DI dizinin ilk gözünü gösterir. DF = 0 olduğu için ileri gidilecektir. İlk STOSB dizi[0]'a AL'yi (0) yazar. Byte işlemi olduğu için DI bir artar ve dizi[1]'i gösterir; CX size − 1 olur. Bu, CX kez tekrarlanır. CX dizinin boyutu olduğundan dizinin tamamı sıfırlanır. Kod bloğunun karşılığı: `dizi ← 0`.

Hoca bu sırada DF'yi 1 yapan komutun STD olduğunu da hatırlattı.

### 7.7 Örnek: diziyi kopyalamak

Kare (ekrandan, 02:45:00):

```asm
LEA SI, dizi1
LEA DI, dizi2
CLD              ; DF <- 0
MOV CX, size
REP MOVSB        ; ES:DI <- DS:SI
```

Data segmentte iki dizi vardır: dizi1'in başlangıç adresi SI'da, dizi2'nin başlangıç adresi DI'dadır. EXE ve COM programları başlarken ES ve DS birbirine eşittir, bu yüzden kodda ES değiştirilmemiştir. Ama komut arka planda ES:DI ve DS:SI üzerinden çalışır; farklı bir data segmentle işlem yapılacaksa ES mutlaka değiştirilmelidir.

DF = 0 olduğu için artan adreslere gidilir; başlangıç adresi bilindiğine göre bu anlamlıdır. CX'te iki dizinin ortak boyutu vardır. İlk adımda SI'nın gösterdiği dizi1[0] alınıp DI'nın gösterdiği dizi2[0]'a yazılır, CX bir azalır. CX 0 olmadığı için tekrarlanır; SI ve DI otomatik olarak birer artar ve bir sonraki gözleri gösterir. Size kez tekrarlanınca sonuç: dizi2 ← dizi1.

### 7.8 Önekler ve LOOP karşılıkları

- REP: ardından gelen string komutunu her seferinde CX'i bir azaltarak CX 0 olana kadar tekrarlar. Birebir eşdeğeri LOOP'tur.
- REPE / REPZ: CX 0 olana kadar ya da ZF 0 olana kadar tekrarlar; yani CX ≠ 0 ve ZF = 1 iken tekrarlar. LOOPZ'ye eşdeğerdir.
- REPNE / REPNZ: CX ≠ 0 ve ZF = 0 iken tekrarlar. LOOPNZ'ye eşdeğerdir.

Örneğin `REPE CMPSW` ile iki dizide ilk farklı eleman bulunur; `REPNZ CMPSW` ile ilk aynı eleman bulunur.

Fark şudur: LOOP komutlarının her birine birer makine komutu üretilir; öneklere ayrı bir komut üretilmez, önek string komutunun bir parçası olur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Aşağıdaki kod çalıştığında toplam, CX ve SI'nın son değerleri nedir?

```asm
     MOV toplam, 0
     MOV CX, 5
     MOV SI, 1
L1:  ADD toplam, SI
     INC SI
     LOOP L1
```

> **Çözüm:** Döngü beş kez döner. toplam sırasıyla 1, 3, 6, 10, 15 olur. Son durumda toplam = 15, SI = 6, CX = 0.

**Soru 2** (derste sözlü, 00:39:19): AX'i sıfırlamak için neden `MOV AX, 0` yerine `XOR AX, AX` tercih edilir?

> **Çözüm:** İkisi de AX'e 0 atar. `XOR AX, AX` 3 clock cycle ve 2 byte, `MOV AX, 0` 4 clock cycle ve 3 byte'tır (ekrandan, 01:45:00, hocanın düzelttiği hâli). XOR daha kısa ve hızlıdır.

**Soru 3** (ekrandan, 00:50:00): I = 1'den başlayıp I ≤ 10 olduğu sürece `AX = AX + I` ve `I = I + 2` yapan while döngüsünü yazın.

> **Çözüm:** `XOR AX, AX`, `MOV SI, 1`, `L2: CMP SI, 10`, `JA L1`, `ADD AX, SI`, `ADD SI, 2`, `JMP L2`, `L1: MOV BX, 1`. Geri dönüş CMP satırına yapılır. AX = 25 olur.

**Soru 4** (derste sözlü, 01:27:27): Sign flag için özel bir komut yoktur. SF'nin tümleyeni alınıp bayrak yazmacına nasıl yazılır?

> **Çözüm:** `LAHF` (AH'nin 7. biti SF olur), `XOR AH, 80H` (yalnız 7. bit terslenir), `SAHF`.

**Soru 5** (derste sözlü, 01:30:08): SF nasıl sıfırlanır?

> **Çözüm:** `LAHF`, `AND AH, 7FH`, `SAHF`. 7FH = 0111 1111 olduğu için yalnız 7. bit sıfırlanır, diğer bitler korunur. İki kez 80H ile XOR'lamak ya da 80H ile AND'lemek istenen sonucu vermez.

**Soru 6** (ekrandan, 01:35:00): Parity flag nasıl 1 yapılır?

> **Çözüm:** `LAHF` (AH'nin 2. biti PF olur), `OR AH, 04H`, `SAHF`.

**Soru 7** (derste sözlü, 01:36:39): AL = 1001 1100 iken `NOT AL` ve `NEG AL` sonrası AL ne olur?

> **Çözüm:** `NOT AL` → 0110 0011. `NEG AL` → 0110 0100. AL başta işaretli olarak −100 (9CH), NEG sonrası +100'dür (64H). Hoca derste −68 / 68 dedi; doğru değer ±100'dür (bkz. 5.1'deki ders sonrası not).

**Soru 8** (ekrandan, 01:50:00): AL'nin i. biti i. kapının açık (1) ya da kapalı (0) olduğunu gösteriyor. 6 numaralı kapının durumuna göre dallanın. Bu iş CMP ile yapılabilir mi?

> **Çözüm:** CMP ile yapılamaz, çünkü diğer 7 bit "don't care"dir ve 128 farklı değer çıkar. `TEST AL, 40H` ve `JZ KAPALI_6` yazılır; sonuç sıfırsa 6. kapı kapalıdır, değilse açıktır.

**Soru 9** (derste sözlü, 01:53:21): Kaç kapının açık olduğu, yani AL'de kaç tane 1 olduğu nasıl bulunur?

> **Çözüm:** 8 adımlık bir döngüde AL bir bit ötelenir, çıkan bit CF'ye düşer. CF ya `JC` ile sınanıp sayaç artırılır ya da `ADC BX, 0` ile doğrudan sayaca eklenir (population count).

**Soru 10** (derste sözlü, 02:02:50): Bir kod bloğunda `SHL AX, CL` satırı var. 16 bitlik yazmaçla 8 bitlik yazmaç yan yana olduğu için bu satır hatalı mıdır?

> **Çözüm:** Hayır, geçerlidir. Öteleme ve döndürmede miktar CL ile verilir ve işlenen 16 bit olabilir. Geçersiz olan `SHL AX, 4` gibi 1'den büyük sabit miktar ya da CL yerine başka bir yazmaç kullanmaktır.

**Soru 11** (ekrandan, 02:05:00): `MOV AL, 80H`, `MOV CL, 4`, `SAR AL, CL` sonrası AL nedir?

> **Çözüm:** −128 → −64 → −32 → −16 → −8. AL = 1111 1000 = F8H = −8. Hoca derste −16 dedi; −16 üç ötelemeden sonraki değerdir (bkz. 6.3'teki ders sonrası not).

**Soru 12** (ekrandan, 02:40:00): `LEA DI, dizi`, `CLD`, `XOR AL, AL`, `MOV CX, size`, `REP STOSB` kod bloğu ne yapar?

> **Çözüm:** dizi isimli dizinin size elemanını baştan sona sıfırlar: her adımda ES:DI'ya AL (0) yazılır, DI bir artar, CX bir azalır.

**Soru 13** (ekrandan, 02:45:00): `LEA SI, dizi1`, `LEA DI, dizi2`, `CLD`, `MOV CX, size`, `REP MOVSB` kod bloğu ne yapar?

> **Çözüm:** dizi1'in size byte'ını dizi2'ye kopyalar (dizi2 ← dizi1). ES = DS varsayılır; farklı segment için ES değiştirilmelidir.

## Dersin Toparlaması

Bu derste 8086 komut setinin büyük bir kısmı tamamlandı. Yığın komutlarıyla SS:SP üzerinden word ile çalışma, döngü komutlarıyla CX'in rolü ve LOOP ailesinin CMP + koşullu dallanma karşılıkları görüldü. For to, for downto, while, repeat until ve iç içe for akış şemaları assembly'ye çevrildi; LOOP'un yalnız döngü sayısı belli işler için kullanılması, while döngüsünde koşulun yanlış kolunun yazılması, etiketlerin doğru satıra konması ve iç içe döngülerde CX'in PUSH/POP ile korunması vurgulandı.

İkinci yarıda özel komutu olan bayraklar (CF, DF, IF) ve olmayanlar için LAHF/SAHF ile bit işlemi, mantıksal komutlar ve TEST ile tek bit sınama, öteleme ve döndürmede CL kuralı ve SAR ile işaretli bölme, son olarak dizi komutları ve önekleri işlendi. Dizi komutlarının dolaylı döngü olduğu, öncesinde CX, DF, DS:SI ve ES:DI'nın hazırlanması gerektiği iki örnekle (diziyi sıfırlama, kopyalama) gösterildi. Giriş-çıkış ve BCD komutları bir sonraki derse kaldı; hoca BCD komutlarının basit örneklerle kısaca geçileceğini, ardından adresleme kiplerine başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
