# Ders 7 Genişletilmiş Notu: Döngü Komutları, Döngü Yapıları, Bayrak Komutları, Öteleme ve Döndürme Komutları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: Döngü Komutları
- 2. Dört Döngü Komutunun Yapısı
- 3. Döngü Komutlarının Slayttaki Tanımları ve Kullanım Örnekleri
- 4. Yüksek Seviye Döngülerin Assembly Karşılıkları
- 5. İç İçe İki FOR Döngüsü
- 6. Bayraklarla İlgili Komutlar
- 7. Mantıksal Komutlar Üzerine Hatırlatma
- 8. Öteleme ve Döndürme Komutları
- 9. Dizi Örneği: Byte Dizisindeki Tek Elemanları Sayma
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş: Döngü Komutları

Bir önceki derste yığın komutlarına kadar gelinmişti. Bu ders döngü komutlarıyla başladı. Hoca döngü komutlarını, yüksek seviye dillerdeki `for` döngüsüne eşdeğer olarak, döngü sayısının bilindiği durumlar için kullanılan komutlar diye tanıttı. Dört komut vardır: `LOOP`, `LOOPZ` (loop zero), `LOOPNZ` (loop not zero) ve `JCXZ` (jump if CX zero). İlk üçünde döngü sayısı tam olarak bellidir. Dördüncüsünde döngü sayısının değiştirilmesi programcıya bırakılmıştır, ama kabaca onda da döngü sayısının bilindiği varsayılabilir.

Dört komutun ortak noktası, döngü değişkeninin CX yazmacı olmasıdır. Hoca CX'in "count register" olarak adlandırıldığını hatırlattı: adı üzerinde, kaç kez dönüleceği bu yazmaçta tutulur (ekrandan, 00:05:00).

## 2. Dört Döngü Komutunun Yapısı

Hoca dört komutu beyaz tahtada bir tablo üzerinde karşılaştırdı. Tablonun satırları döngü değişkeni, CX'in nasıl değiştiği, yapı ve döngüyü kırma koşuludur (ekrandan, 00:10:00 ve 00:15:00).

### 2.1 LOOP

Yapı şöyledir: döngüden önce CX'e ilk değer atanır, sonra bir etiket tanımlanır. Etiketin hemen ardından iki nokta üst üste gelir; hoca bunun unutulmaması gerektiğini söyledi. Ardından döngü gövdesindeki işlemler gelir ve gövdenin sonunda `LOOP etiket` yazılır:

```asm
        MOV CX, ...
etiket: ...
        ...
        LOOP etiket
```

Kod yukarıdan aşağı aktığı için gövde yürütüldükten sonra `LOOP` satırıyla yeniden etikete gidilir. `LOOP` şöyle çalışır: önce CX'i bir azaltır, sonra elde edilen değer sıfır mı diye bakar. Sıfır değilse etikete dallanır, sıfırsa döngü kırılır ve alt satıra geçilir. Kırma koşulu yalnız CX'in sıfıra ulaşmasıdır. Yani `LOOP`'un altındaki satıra gelinmişse CX sıfır olmuştur; gövdenin içindeysek CX henüz sıfır olmamıştır.

### 2.2 LOOPZ

`LOOPZ`'de de yapı aynıdır: döngüden önce `MOV CX, ...`, etiket, gövde ve sonda `LOOPZ etiket`. Fark, döngüde kalma koşuludur. Döngüde kalmak için iki koşul birlikte sağlanmalıdır: CX ≠ 0 ve ZF = 1. Alt satıra geçilmişse bunun iki nedeni olabilir: ya CX == 0 olmuştur ya da işlem sonucu sıfırdan farklı çıkmış, yani ZF = 0 olmuştur. Bunlardan biri gerçekleşince döngü kırılır.

### 2.3 LOOPNZ

`LOOPNZ`'de döngüde kalmak için CX ≠ 0 ve ZF = 0 olmalıdır; yani işlem sonucu sıfırdan farklı olmalıdır. Döngü ya CX == 0 olunca ya da tek başına ZF = 1 olunca kırılır.

### 2.4 JCXZ

`JCXZ` "CX sıfırsa dallan" anlamına gelir. Burada da CX döngü değişkenidir, ama önemli bir fark vardır. `LOOP`, `LOOPZ` ve `LOOPNZ`'de CX'in değeri otomatik olarak azaltılır; bu azaltma, bu komutlar yürütülürken yapılır (önce azaltılır, sonra sıfır mı diye kontrol edilir). `JCXZ`'de ise CX otomatik değer almaz; CX'in değer kontrolü kullanıcıdadır.

Yapısı şöyledir (ekrandan, 00:15:00):

```asm
          MOV CX, ...
etiket1:  ...
          ...            ; CX değiştirilir
          JCXZ etiket2
          JMP etiket1
etiket2:  ...
```

Bu yapı ilk bakışta sonsuz döngü gibi görünür. Akış şöyledir: CX'e ilk değer verilir, gövde CX'in bu değeriyle yürütülür, gövdenin bir yerinde CX güncellenir, sonra CX sıfır mı diye bakılır. Koşullu dallanmalarda koşul sağlanırsa etikete dallanılır, sağlanmazsa hemen alttaki komut çalışır. Alttaki komut `JMP` olduğu için döngünün başına dönülür. Kırma koşulu CX'in sıfıra ulaşmasıdır.

CX'in sıfıra ulaşabilmesi için döngü içinde CX'e mutlaka bir müdahale yapılmalıdır: `INC`, `DEC`, `SUB`, `ADD` gibi işlemlerle. Hoca CX'in bu sayede istenildiği gibi değiştirilebileceğini gösterdi: CX ikişer ikişer artırılabilir ya da bir koşul konabilir. Tahtaya çizdiği akışta "tekse CX = CX + 1, çiftse CX = CX + 2" gibi bir koşullu güncelleme vardı. Hoca artırmanın zorunlu olmadığını, belirli bir ilk değerden başlayıp azalta azalta gitmenin daha doğru olduğunu ekledi.

### 2.5 ZF'yi Kim Değiştirdi?

Hoca `LOOPZ` ve `LOOPNZ` için bir uyarı yaptı. Döngü satırına gelindiğinde ZF, gövdede ZF'yi en son değiştiren komutun sonucunu taşır. Bu komut `LOOP`'un hemen üstündeki satır olmayabilir. Örneğin gövdede bir aritmetik işlem varsa bu işlem ZF'yi değiştirir; ama hemen üstteki satır bir veri aktarım komutuysa ZF'yi değiştirmez ve ZF daha önceki komuttan kalır. Döngü, en son ZF'yi değiştiren işlemin sonucuna göre de kırılabilir.

> **Hocanın vurgusu:** `LOOP`, `LOOPZ` ve `LOOPNZ`'de CX ile oynamaya gerek yoktur; her geçişte bir azaltılır. `JCXZ`'de ise CX mutlaka programcı tarafından değiştirilmelidir. CX'e ilk değer verildikten sonra döngü içinde değiştirilmezse döngü sonsuza kadar döner.

## 3. Döngü Komutlarının Slayttaki Tanımları ve Kullanım Örnekleri

### 3.1 LOOP ve Yer Değiştirme

Slaytta `LOOP` komutunun yanına bir yer değiştirme (displacement) aldığı görülür. Hoca bu kavramı hatırlattı: yer değiştirme, `LOOP` komutunun bulunduğu satıra göre ne kadar ileri ya da geri gidileceğini belirten bir parametredir. 8 ya da 16 bitlik işaretli sayı olabilir; böylece geriye ya da ileriye doğru bir adrese gidilebilir. Her `LOOP` geçişinde CX bir azaltılır. Döngünün devam koşulu CX'in sıfırdan farklı olması, kırma koşulu CX'in 0 olmasıdır.

### 3.2 Örnek: 1'den 5'e Kadar Sayıların Toplamı

Slayttaki ilk örnek 1'den 5'e kadar sayıların toplamıdır. <!-- BELİRSİZ: bu slaytın karesi okunmadı; satırlar altyazıdan kuruldu. --> Toplamı tutan bir değişken 0 ile başlatılır. Beş sayı olduğu için CX'e 5 atanır.

> **Hocanın vurgusu:** Döngülerde değer CL ya da CH'ye değil, 16 bitlik CX'e atanır. Bu çok önemlidir.

Sayılar 1'den başladığı için SI'ye 1 atanır. Döngüde toplama SI eklenir ve SI bir artırılır, sonra `LOOP` satırına gelinir. Döngü CX'in 5, 4, 3, 2 ve 1 değerleri için döner. CX = 1 iken toplama yapıldıktan sonra `LOOP` CX'i azaltır, CX 0 olur ve döngü kırılır; döngüye CX = 0 için girilmez. Döngü bittiğinde SI = 6, CX = 0 ve toplam 15'tir (python ile doğrulandı).

Hoca aynı işlemin daha kısa bir yolunu gösterdi: CX zaten 5'ten 1'e kadar değer aldığı için toplam doğrudan CX üzerinden alınabilir. Bu durumda toplama CX eklenir; SI'ye ilk değer veren satır ve `INC SI` kaldırılır.

### 3.3 LOOPZ (LOOPE) ve Bir Kullanım Senaryosu

Slaytta `LOOPZ` ile `LOOPE`'nin (loop equal) aynı komut olduğu yazar (ekrandan, 00:20:00): `LOOPZ disp`; her geçişte CX azaltılır, sonra `disp` ile gösterilen adrese gidilir; CX ≠ 0 ve ZF = 1 olduğu sürece tekrarlanır.

Hoca bunun nerede kullanılabileceğini bir senaryoyla anlattı. İki dizinin karşılıklı elemanları karşılaştırılıyor olsun ve ilk farklılığın hangi indiste görüldüğü bulunmak istensin. Karşılaştırma eşitse ZF = 1 olur ve döngü devam eder. Döngü ya son elemanla (CX = 0) biter ya da arada bir indiste çıkılır. CX = 0 ile çıkılmışsa farklılık yoktur. ZF = 0 ile çıkılmışsa aranan eleman bulunmuştur ve konumu CX'ten hesaplanabilir (hocanın ifadesiyle "n − CX indisinde").

### 3.4 LOOPNZ (LOOPNE) ve Bir Kullanım Senaryosu

`LOOPNZ` da bir yer değiştirme alır. Devam koşulu CX ≠ 0 ve ZF = 0'dır; yani işlem sonucu sıfır olmamalıdır. Aynı iki dizi senaryosunda bu kez ilk aynı eleman aranır. Aynı eleman bulunduğu an ZF = 1 olur ve döngü sonlanır. Hiç aynı eleman yoksa döngü CX = 0 ile sonlanır. Hangi koşulla çıkıldığına bakılarak, dizileri baştan tararken ilk aynı elemana rastlanıp rastlanmadığına karar verilir.

## 4. Yüksek Seviye Döngülerin Assembly Karşılıkları

Hoca önce bir önceki haftayı hatırlattı. IF-THEN-ELSE (iki kol dolu), ELSE kolu boş ve THEN (true) kolu boş durumları işlenmişti. Kollardan biri boşken koşul boş kol için yazılırsa tek bir koşullu dallanma komutu yeter. Dolu kol için yazılırsa iki dallanma komutu gerekir. Döngülerde de aynı mantık kullanılacaktır.

Ele alınacak yapılar şunlardır:

- FOR TO: `for (i = 0; i < n; i++)` biçimindeki artan döngü.
- FOR DOWN TO: `for (i = n; i > 0; i--)` biçimindeki azalan döngü.
- WHILE: Koşul başta kontrol edilir; koşul tutmuyorsa döngüye hiç girilmeden çıkılabilir.
- REPEAT UNTIL: Gövde en az bir kez kesin yürütülür, kontrol sonra yapılır.
- İç içe iki FOR.

Slaytlarda her yapının yanında bir akış diyagramı vardır. Döngünün hemen öncesindeki `AX = 0` ve sonrasındaki `BX = 1` atamaları, döngüye girildiğini ve çıkıldığını belirlemek için konmuş anlamlı işaretlerdir.

### 4.1 FOR TO

Döngü değişkeni I, 1'den 10'a birer birer artar; gövdede AX = AX + I yapılır (ekrandan, 00:25:00). Slayttaki kod:

```asm
        XOR AX, AX
        MOV SI, 1
        MOV CX, 10
tekrar: ADD AX, SI
        INC SI
        LOOP tekrar
        MOV BX, 1
```

`XOR AX, AX` AX'i sıfırlar. I değişkeni SI'de tutulur ve ilk değeri 1'dir. Döngü 1'den 10'a 10 kez döneceği için CX'e 10 atanır. Gövdede `ADD AX, SI` ile toplam AX'te birikir. Yüksek seviye dillerde döngü değişkeni kendiliğinden artar, burada ise bunu yapan otomatik bir komut yoktur; I'yı `INC SI` ile kendimiz artırırız. `LOOP` CX'i bir azaltıp etikete döner. CX 10, 9, ..., 1 değerleri için gövdeye girilir; CX = 1 iken `LOOP` CX'i 0 yapar ve döngü kırılır, ardından `MOV BX, 1` gelir. Sonuç AX = 55'tir (python ile doğrulandı).

Hoca bir soru sordu: CX zaten 10'dan 1'e iniyor; ayrıca SI kullanmaya gerek var mı? Aynı işlem işlevsel olarak şöyle de yapılabilir: CX'e 10 atanır ve gövdede `ADD AX, CX` yapılır. Bu kez 1'den 10'a değil 10'dan 1'e toplanır, ama sonuç aynıdır (55). İlk sürüm indis değişkeninin 1'den 10'a birebir değişimini gösterir; ikincisi işlevsel olarak aynı hesaptır.

### 4.2 FOR DOWN TO, İkişer Azalan

Bu örnekte döngü değişkeni (I = 10) ikişer ikişer azalır; akış diyagramında I = 10, adım 2 ve son değer 0'dır (ekrandan, 00:30:00). Adımın 2 olması için CX'in programcının kontrolünde olması gerekir. CX programcının kontrolündeyse `LOOP` yerine `JCXZ` kullanmak anlamlıdır:

```asm
        XOR AX, AX
        MOV CX, 10
tekrar: ADD AX, CX
        SUB CX, 2
        JCXZ devam
        JMP tekrar
devam:
```

AX sıfırlanır. Döngünün kaç adım gideceği doğrudan belli değildir, çünkü değişken ikişer azalır; ama başlangıç değeri 10'dur ve CX'e atanır. Döngü değişkeni olarak yine CX seçilir. Gövdede AX ile CX toplanır, sonra `SUB CX, 2` ile CX her adımda iki azaltılır. `JCXZ` yanlış dönerse alttaki `JMP` satırına, oradan da `tekrar` etiketine gidilir. CX == 0 olduğunda `devam` etiketine dallanılır ve döngü kırılır. Sonuç AX = 10 + 8 + 6 + 4 + 2 = 30'dur (python ile doğrulandı).

Hoca burada bir "kaçak" olup olmadığını sordu. Bir öğrenci CX 11 ya da 9 olsaydı sorun çıkacağını söyledi ve hoca bunu doğruladı. Bu örnekte CX tek bir sayıyla başlasaydı, 2 çıkarıldığı hâlde CX sıfırdan geçmeyebilirdi; döngü hiç kırılmazdı. Python ile CX = 9'dan başlayan 16 bitlik bir benzetimde CX 1'den sonra FFFFh'ye geçer ve hiçbir zaman 0 olmaz.

### 4.3 WHILE

WHILE örneği, CX dışında başka bir koşul olduğu için koşullu dallanma komutuyla yazılır. <!-- BELİRSİZ: WHILE slaytının karesi okunmadı; aşağıdaki satırlar altyazıdan kuruldu. --> Akış diyagramında `I <= 10` koşulunun true kolunda işlemler vardır, false kolu boştur ve iki kol döngünün çıkışında birleşir. Döngü kırıldıktan sonra `BX = 1` ataması gelir.

AX `XOR AX, AX` ile sıfırlanır. Döngü değişkeni I'nın ilk değeri 1'dir ve SI'de tutulur. Ardından SI 10 ile karşılaştırılır. Bir önceki haftadan hatırlanacağı gibi koşul boş kol için yazılırsa işlem basitleşir. Boş kolun koşulu "I > 10"dur. SI'nin 10'dan büyük olması `JA` (jump above) ile denetlenir. `JA` işaretsiz sayılarda işlenen 1, işlenen 2'den büyükse verilen etikete dallanır. Döngü değişkeni 1'den başlayıp artarak 10'a kadar gittiği için işaretsiz sayılarla çalışıldığı anlaşılır; bu yüzden `JA` kullanılır.

Koşul sağlanırsa döngü kırılır ve BX'e 1 atanan satıra gidilir. Döngüdeysek AX ile SI toplanıp AX'e yazılır, döngü değişkeni 2 artırılır ve `tekrar` etiketine dönülür. Orada SI yeniden 10 ile karşılaştırılır. Altyazıdan kurulan biçimi şöyledir:

```asm
        XOR AX, AX
        MOV SI, 1
tekrar: CMP SI, 10
        JA devam
        ADD AX, SI
        ADD SI, 2
        JMP tekrar
devam:  MOV BX, 1
```

While kontrolü de bir koşullu dallanmadır ve false kolu boştur. Koşul boş kol için yazıldığı için tek bir koşullu dallanma komutu yeterli oldu. (Bu biçimle AX = 1 + 3 + 5 + 7 + 9 = 25 olur; python ile hesaplandı, sonuç derste söylenmedi.)

### 4.4 REPEAT UNTIL

REPEAT UNTIL ile WHILE arasındaki fark şudur: WHILE'da döngünün hiç gerçekleşmeme ihtimali vardır; başta koşul yanlışsa döngüye girilmeden çıkılır. REPEAT UNTIL'de gövde en az bir kez yürütülür, sonra koşul sağlanırsa döngü kırılır. Döngü koşul sağlanmadığı sürece devam eder; bu yüzden koşulun false kolu geri dönüş, true kolu çıkıştır ve true kolu boştur (ekrandan, 00:35:00).

Slayttaki kod:

```asm
        XOR AX, AX
        MOV SI, 2
tekrar: ADD AX, SI
        ADD SI, 2
        CMP SI, 10
        JBE tekrar
        MOV BX, 1
```

Akış diyagramında AX = 0, I = 2, AX = AX + I, I = I + 2 kutuları ve `I > 10` karar kutusu vardır; F kolu gövdenin başına döner. AX sıfırlanır, SI'ye 2 atanır. Gövdenin ilk adımı SI'yi AX'e eklemek, ikincisi döngü değişkenini 2 artırmaktır. Sonra SI 10 ile karşılaştırılır. İ 2'den 10'a kadar gittiği için işaretsiz sayılarda "küçük eşit" komutu `JBE` (jump below or equal) kullanılır; `JBE` işlenen 1 ≤ işlenen 2 ise dallanır. Hoca slaytın kenarına `JBE` için "jump below or equal" yazdı. Koşul false iken (I ≤ 10) `JBE` doğru döner ve gövde tekrarlanır; I > 10 olunca alt satıra geçilir. Sonuç AX = 2 + 4 + 6 + 8 + 10 = 30'dur (python ile doğrulandı).

Hoca anlatırken kodun doğruluğunu bir an sorguladı ve öğrencilerle birlikte yeniden kontrol etti.

**Soru:** Kod doğru mu? Bu bir do-while olmadı mı?

**Cevap:** Doğrudur; REPEAT UNTIL'in yapısı gereği gövde önce çalışır ve bu bir do-while'a denk gelir. Alt satıra I > 10 olduğunda geçilir.

**Soru:** Diyagramda false kolu tekrar edildiğine göre, okunuş açısından `JBE` yerine `JNA` (jump not above) yazmak daha doğru olmaz mı?

**Cevap:** `JNA` ile `JBE` aynı komuttur; işlev olarak fark yoktur. Okunuş açısından haklısın, `JNA` kullanılabilir; diyagramdaki koşul "I > 10" olduğu için onun değili olarak okunur. Önemli olan, false kolunun hangi durumda sağlandığını yazmaktır; ikisi de bunu sağlar.

## 5. İç İçe İki FOR Döngüsü

Hoca özel bir duruma geçti: iç içe iki FOR. Bir FOR yazılacaksa döngü sayısı belli olduğu için mutlaka CX kullanılır. Dıştaki döngü için de içteki döngü için de CX kullanılmalıdır. Sorun şudur: dıştaki CX'in herhangi bir değeri için iç döngüde CX'e değer atanırsa dıştaki değer bozulur. Dış döngünün her değeri için içteki döngü 3 kez dönmelidir, ama iki döngünün değişkenleri birbirini etkiler.

Hoca öğrencilere ne yapılması gerektiğini sordu; sohbetten "push-pop" cevabı geldi. Hoca daha genel bir kavramla toparladı: dıştaki döngü değişkeni, iç döngüye girmeden önce bir şekilde korunmalı, iç döngü kırıldığında geri okunmalıdır. Bunun iki yolu vardır (ekrandan, 00:45:00):

- Yol 1: Kullanılmayan bir yazmaca yedeklemek. Örnekte DI, SI ve AX kullanıldığı için DX boştur: iç döngüden önce `MOV DX, CX`, iç döngüden sonra `MOV CX, DX`.
- Yol 2: Yığını kullanmak. İç döngüden önce `PUSH CX` ile CX'teki değer yığının tepesine atılır, iç döngüden sonra `POP CX` ile geri çekilir.

Slayttaki problem: dış döngü I = 0'dan başlar, adım 1, son değer 3; iç döngü J = 2'den başlar, adım 1, son değer 4; gövde AX = AX + I + J (ekrandan, 00:40:00). Slayttaki kod:

```asm
        MOV AX, 0
        MOV CX, 4
        MOV DI, 0
L2:     PUSH CX
        MOV CX, 3
        MOV SI, 2
L1:     ADD AX, DI
        ADD AX, SI
        INC SI
        LOOP L1
        POP CX
        INC DI
        LOOP L2
        MOV BX, 1
```

Hoca kodu içten dışa doğru açıkladı. İç döngü J'nin 2, 3 ve 4 değerleri için, yani 3 adım çalışır; bu yüzden `MOV CX, 3`. İç döngü değişkeni J için SI seçilir ve SI'ye 2 atanır. Dış döngü değişkeni I için DI seçilmiştir. Gövdede AX'e önce dış değişken (DI), sonra iç değişken (SI) eklenir; AX bir toplayıcı (aggregator) gibi kullanılır. `INC SI` iç değişkeni artırır, `LOOP L1` ile `MOV CX, 3` birlikte iç döngünün her DI değeri için 3 kez dönmesini sağlar. İç döngünün başında ve sonunda CX `PUSH`/`POP` ile yedeklenip geri yüklenir.

Dış döngü I'nın 0, 1, 2, 3 değerleri için 4 adım dönmelidir; bu yüzden CX'e 4 yüklenir. DI 0'dan başlar. Dış döngünün gövdesinde iç döngü dışında ayrı bir işlem yoktur; ama yüksek seviye dilde döngü değişkeni kendiliğinden artacağı için burada `INC DI` yazılmalıdır. `LOOP L2` dış döngüyü `L2: PUSH CX` satırına döndürür; yani dış döngünün her adımında CX yeniden yedeklenir. Dış döngü de kırıldıktan sonra `MOV BX, 1` gelir. Dış döngüye başlamadan önce AX'e 0 atanması da gerekir. Sonuç AX = 54'tür (python ile doğrulandı: $3 \cdot (0+1+2+3) + 4 \cdot (2+3+4) = 18 + 36 = 54$; derste sayısal sonuç söylenmedi).

Hoca yığın yaklaşımında dikkat edilmesi gerekenleri ekledi. İç döngüye girmeden önce program akışı gereği başka `PUSH` komutları olsaydı, uygun yerde karşılık gelen `POP` komutları da konmalıydı. İç döngünün içinde bir `PUSH` varsa `LOOP`'tan önce bir `POP` olmalıdır. Yığına atma ve yığından çekme "parantezleri" birbirini karşılarsa, iç döngü her bittiğinde yığının tepesinden çekilen değer atılan CX'in kendisi olur. `POP`'lar eksik kalırsa yığının tepesinde farklı bir değer kalır ve bu, program akışını bozar.

> **Hocanın vurgusu:** İç içe iki döngüde iç döngüye girmeden önce dış döngü sayısını tutan CX bir şekilde yedeklenmelidir: ya kullanılmayan bir yazmaca atılır ya da, bütün yazmaçlar meşgulse, yığına atılıp sonra geri çekilir.

Hoca aradan sonra bayrak komutlarına, mantıksal komutlara kısa bir hatırlatmaya, öteleme ve döndürme komutlarına ve son olarak emu8086 üzerinde dizi örneklerine geçileceğini söyledi.

## 6. Bayraklarla İlgili Komutlar

Bazı bayraklara adıyla erişilebilir; yani komutlarla doğrudan değiştirilebilirler. Hoca bayrakları, nasıl değiştirildiklerine göre üç gruba ayırdı (ekrandan, 01:00:00 ve 01:05:00).

### 6.1 Birinci Grup: Doğrudan Komutu Olan Bayraklar (CF, DF, IF)

Slayttaki komutlar ve hocanın kenara yazdığı etkileri şöyledir:

| Komut | Açılım | Etki |
|---|---|---|
| `CLC` | clear carry flag | CF ← 0 |
| `CMC` | complement carry flag | CF ← CF' |
| `STC` | set carry flag | CF ← 1 |
| `CLD` | clear direction flag | DF ← 0 |
| `STD` | set direction flag | DF ← 1 |
| `STI` | set interrupt flag | IF ← 1 |
| `CLI` | clear interrupt flag | IF ← 0 |

"Clear" sıfır atamak, "set" bir atamaktır. `CMC`, CF'ye mevcut değerinin değilini atar. Hoca CF'nin işaretsiz sayılarda taşmayı gösterdiğini hatırlattı.

DF dizi (katar) işlemleriyle ilgilidir ve bir sonraki hafta ayrıntılı işlenecektir. Dizi işlemlerinde bir kaynak ve bir hedef dizi vardır. Dizilerin başlangıç adresinden itibaren adres artırılarak mı gidilecek, yoksa son elemandan geriye doğru adres azaltılarak mı gidilecek, bunu DF belirler. DF = 0 ise baştan sona doğru adresler otomatik artırılır; DF = 1 ise sondan başa doğru birer birer azaltılır.

IF donanımsal kesmeleri açıp kapatan bayraktır. Başka bir deyişle, mikroişlemcinin INTR (interrupt request) adlı fiziki bir ucu vardır; bu uçtan gelen kesmelerin işlemciye aktarılıp aktarılmayacağını IF belirler. IF = 1 ise aktarılır, IF = 0 ise engellenir.

### 6.2 İkinci Grup: LAHF ve SAHF'a Konu Olan Bayraklar (SF, ZF, AF, PF, CF)

SF, ZF, AF ve PF için doğrudan komut yoktur (CF'nin zaten vardır). Bunları değiştirmek için iki komut kullanılır: `LAHF` (load AH with flag register) ve `SAHF` (store AH to flag register).

Bayrak yazmacı 16 bitliktir, ama bitlerinin hepsi anlamlı değildir; bazıları boştur. `LAHF` bu bitlerin bazılarını AH'a belirli bir sırayla kopyalar. Slayttaki gösterim `AH ← SF,ZF,?,AF,?,PF,?,CF` biçimindedir:

| AH biti | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|---|
| Bayrak | SF | ZF | ? | AF | ? | PF | ? | CF |

Bayraklar AH'a alındıktan sonra AH üzerinde bit maskelemeyle istenen bitler 1 ya da 0 yapılabilir; birden çok bayrak aynı anda kurulup temizlenebilir. Değişikliğin etkili olması için değerlerin bayrak yazmacına geri yazılması gerekir. Bunu `SAHF` yapar: AH'ın 7. bitini SF'ye, 6. bitini ZF'ye, 4. bitini AF'ye, 2. bitini PF'ye ve 0. bitini CF'ye aktarır.

### 6.3 Üçüncü Grup: OF ve TF

OF işaretli sayılarda taşmayı gösterir. TF ise adım adım hata ayıklama içindir. TF kurulduğunda her komut yürütüldükten sonra özel bir tek adım (single step) kesmesi tetiklenir. Böylece her komuttan sonra sistem durur ve programcıya bir şey yapma imkânı verir: örneğin yazmaçların o anki değerleri ekrana yazdırılır ve bir tuşa basılması beklenir; tuşa basılınca bir sonraki komuta geçilir. <!-- BELİRSİZ: altyazıda "bunu bir reset ettiğimiz zaman" geçiyor; 8086'da tek adım kesmesi TF = 1 iken oluşur, burada TF'nin 1 yapılması kastedilmiş olmalı. -->

Bu iki bayrak için bir önceki hafta görülen `PUSHF` ve `POPF` komutları kullanılır. `PUSHF` ile 16 bitlik bayrak yazmacı yığına atılır. Yığının tepesinde bayrak değerleri durur; burada bit işlemleriyle OF ve TF'ye denk gelen bitler 1 ya da 0 yapılır. İş bitince `POPF` ile değer bayrak yazmacına geri çekilir ve değiştirilen değerler etkili olur.

Hoca bu üç grubu basitten karmaşığa sıraladı: doğrudan komutu varsa en basiti odur; AH'a yüklenebiliyorsa ikinci derece; yığın üzerinden yapılması gerekiyorsa üçüncü derece zorluktur. Bu üç yolla bütün bayraklar 0 ya da 1 yapılabilir.

## 7. Mantıksal Komutlar Üzerine Hatırlatma

Mantıksal komutlar daha önce görülmüştü; hoca kısa bir hatırlatma yaptı (ekrandan, 01:10:00 ve 01:15:00). Bu komutlar bit düzeyinde (bitwise) işlem yapar. Bir işlenenin b numaralı bitiyle üç şey yapılmak istenebilir: 0 yapmak, 1 yapmak ya da tümleyenini almak.

- 0 yapmak için `AND` komutu işlenenle ve anlık (immediate) bir maskeyle kullanılır. Maskenin b. biti 0, diğer bitleri 1 olmalıdır.
- 1 yapmak için `OR` komutu bir anlık maskeyle kullanılır. Maskenin b. biti 1, diğerleri 0 olmalıdır.
- Tümleyen almak için `XOR` komutu bir anlık maskeyle kullanılır. Maskenin b. biti 1, diğerleri 0 olmalıdır.

Bunun dayanağı tek bitlik bir $x$ için şu özelliklerdir: $x \cdot 0 = 0$ (b. bit 0 ile AND'lenince 0'a çekilir), $x + 1 = 1$ (1 ile OR'lanınca 1 olur), $x \oplus 1 = \bar{x}$ (1 ile XOR'lanınca değili çıkar). Hoca, bayraklar için az önce set ve reset anlatıldığı gibi, mantıksal komutlarla da herhangi bir işlenenin herhangi bir bitinin kurulabileceğini, temizlenebileceğini ya da tümlenebileceğini hatırlattı. Slaytta `AND mem, idata` biçimi için "PTR gerekli" notu görülür (ekrandan, 01:15:00).

`TEST` ve `CMP` koşullu dallanmalarla birlikte çalışır. `CMP` iki işlenen arasındaki büyük, küçük, büyük eşit, küçük eşit ve eşit durumlarını denetler; arka planda bir çıkarmadır. `TEST` ise işlenenin belirli bir bitinin 1 mi 0 mı olduğunu anlamayı sağlar; arka planda bir `AND`'dir. İkisinde de işlem sonucu bir yerde saklanmaz, yalnız bayraklar etkilenir. Koşullu dallanma komutlarından önce ya arka planda bir aritmetik/mantık işlemi yürütülür ya da akışa göre `TEST` veya `CMP` kullanılır.

## 8. Öteleme ve Döndürme Komutları

### 8.1 Genel Kavramlar

Öteleme (shift) işlemlerinde işlenen sağa ya da sola kaydırılır. Sola kaydırmada en yüksek anlamlı taraftan, sağa kaydırmada en düşük anlamlı taraftan bir bit dışarı çıkar ve öbür uçta bir bitlik yer boşalır. Ötelemede boşalan yer genellikle 0 ile beslenir. Döndürmede (rotate) de kaydırma yapılır, ama dışarı çıkan bit öbür taraftan geri beslenir.

Öteleme işlemlerinin lojik ve aritmetik türleri vardır. Döndürme işlemlerinin ise CF ile (with carry) ve CF'siz (without carry) türleri vardır. CF kullanılıyorsa 8 bitlik bir yazmaç için sanki 9 bit, 16 bitlik yazmaç için 17 bit üzerinden döndürme yapılır; CF kullanılmıyorsa 8 ya da 16 bit üzerinden döndürülür. Lojik işlemlerde sayının işaretine dikkat edilmez, aritmetik işlemlerde işaret korunur.

### 8.2 SHL / SAL

`SHL` (shift left logical) bütün bitleri bir anlamlı sıra yukarı kaydırır (ekrandan, 01:20:00). D0'daki bit D1'e, D1'deki D2'ye kayar; en anlamlı bit (D7 ya da D15) CF'ye gider. Boş kalan en düşük anlamlı bit 0 ile beslenir.

Hoca lojik kullanım için bir örnek verdi. 16 kapıya bağlı 16 sensör olsun; sensör değeri 1 ise kapı açık, 0 ise kapalıdır. 16 sensörün değeri AX'te biriktirilmiş olsun. Kaç kapının açık olduğunu bulmak için AX her seferinde bir kez sola ötelenir ve CF'ye düşen değere bakılır. CF = 1 ise ilgili kapı açıktır. CF'nin kaç kez 1 olduğu sayılırsa açık kapı sayısı, yani AX'teki 1'lerin sayısı bulunur. Bu tamamen lojik bir durumdur.

Komut bir yazmaç ya da bellek işleneniyle kullanılabilir. Bir kez ötelenecekse sayı doğrudan 1 olarak yazılır (`SHL reg, 1`, `SHL mem, 1`). Örneğin üç kez ötelenecekse önce CL'ye öteleme sayısı atanır, sonra `SHL AX, CL` yazılır (tahtada `MOV CL, 3` / `SHL AX, CL`).

> **Hocanın vurgusu:** Birden büyük öteleme ve döndürme sayıları mutlaka CL üzerinden verilmelidir.

`SHL` en yüksek anlamlı bite dikkat etmez. Örneğin en yüksek bit 1, bir sonraki bit 0 ise sayı negatiftir; bir kez sola ötelenince en yüksek bit 0 olur ve sayı pozitife döner. Yani sola ötelemede taşmalar olabilir. Aritmetik olarak sola öteleme 2 ile çarpmaya denk gelir. İşaret bitine dikkat edilmediği için lojik sola öteleme ile aritmetik sola öteleme aynıdır: `SAL = SHL`.

### 8.3 SHR

`SHR` (shift logical right) her biti bir düşük anlamlıya kaydırır: D0 CF'ye gider, D1 D0'ın yerine geçer, ..., D7 D6'ya gider. Boşalan en yüksek bit 0 ile beslenir. Bir kez kaydırma için işlenen doğrudan 1 yazılabilir, birden fazlası CL ile verilir. Kapı örneğinde olduğu gibi, sayının işaretine ve değerine bakılmadan bitlerin tek tek 1 ya da 0 olarak değerlendirildiği lojik durumlar için kullanılır.

Hoca burada emu8086 hakkında bir uyarı yaptı. emu8086 bir emülatördür; komutları fiziki hâlleriyle değil taklit ederek çalıştırır. emu8086'da `SHR AX, 4` yazılırsa hata vermez. Bu, anlık değerin 1'den farklı olabileceği anlamına gelmez; emülatörün sağladığı bir kolaylıktır. Komut kümesine bakıldığında böyle bir biçim yoktur. emu8086 bu satırı derlerken dört tane `SHR AX, 1` komutuna çevirir.

> **Ek bilgi (derste anlatılmadı):** 1'den büyük anlık öteleme sayısı (`SHR AX, 4` gibi) özgün 8086/8088'de yoktur; büyük olasılıkla 80186 ve sonraki işlemcilerle eklenmiştir. 8086 hedeflenen bir assembler'da bu satır hata verebilir ya da işlemci seçimi gerektirebilir.

### 8.4 SAR

`SAR` (shift arithmetic right) sayının işaret bitini dikkate alır (ekrandan, 01:25:00). Sola ötelemede (2 ile çarpmada) işaret bitine dikkat edilemediği söylenmişti, ama sağa ötelemede dikkat edilebilir. `SAR`'da da D0 CF'ye gider, D1 D0'a, ..., D7 D6'ya gider; ancak D7 kendisini tekrar ederek doldurulur.

Örnek: `MOV AL, -16` / `SAR AL, 1`.

- 16'nın ikili gösterimi: $0001\,0000_2$.
- −16 için bunun ikiye tümleyeni alınır. Hocanın pratik yöntemi: sağdan itibaren ilk 1 dahil, ilk 1'e kadar olan bitleri olduğu gibi bırak, sonrakilerin değilini al. Sonuç: $-16 = 1111\,0000_2$.
- Bir bit sağa aritmetik öteleme: D0 (0) CF'ye gider, diğer bitler bir sağa kayar, en yüksek bit (1) kendini tekrarlar. AL = $1111\,1000_2$, CF = 0.
- Sonucun değeri: sayı negatiftir; genliği için yine ikiye tümleyen alınır: $0000\,1000_2 = 8$. Sonuç −8'dir.

Hoca genliği öğrencilere sordu, cevap gelmeyince kendisi verdi: genlik 8, sayı negatif, sonuç −8. Yani −16'nın sağa aritmetik ötelenmesi 2'ye bölmeye karşılık gelir ve bu, en yüksek anlamlı bitin tekrarlanmasıyla sağlanır.

İkinci örnek: `MOV AL, 16` / `SAR AL, 1`. $0001\,0000_2$ sağa ötelenir, en yüksek bit (0) tekrar edilir: $0000\,1000_2 = 8$. Sayı pozitifse aritmetik öteleme pozitif sayıyı 2'ye böler; negatifse işaret tekrarlandığı için negatiflik korunur. Her iki sonuç da python ile doğrulandı.

### 8.5 RCL ve RCR

CF ile döndürmelerde CF, işlenene eklenmiş bir bit gibi davranır; 8 bitlik bir işlenen için toplam 9 bit üzerinden döndürülür. `RCL`'de CF'deki değer en düşük anlamlı bite kopyalanır, her bit bir yüksek anlamlıya geçer, D7 de CF'ye kopyalanır; dairesel bir yapıdır. `RCR` benzer şekilde ters yönde çalışır: CF en yüksek anlamlı bite döner, her bit bir düşük anlamlıya geçer, en düşük anlamlı bit CF'ye gider. Bir kez döndürmede işlenen 1 yazılabilir, birden fazlası CL ile verilmelidir.

### 8.6 ROL ve ROR

CF'siz döndürmelerde yalnız işlenenin genişliği üzerinden döndürme yapılır. `ROL`'de en yüksek anlamlı bit en düşük anlamlı bitin yerine gelir, diğer bitler bir yükseğe kayar (D6 D7'ye geçer). D7, D0'a kopyalanırken aynı zamanda CF'ye de kopyalanır. `ROR` da işlenen genişliği üzerinden çalışır; en düşük anlamlı bit D7'ye kopyalanırken CF'ye de kopyalanır. Bir kez döndürmede 1 doğrudan yazılabilir; birden fazlası mutlaka CL ile verilmelidir.

## 9. Dizi Örneği: Byte Dizisindeki Tek Elemanları Sayma

Döngü ve öteleme işlemleri görüldükten sonra bunları birlikte kullanan bir örnek çözüldü. Hoca problemi beyaz tahtaya yazdı:

> Verilen N elemanlı `array` byte dizisi içinde kaç adet tek eleman olduğunu `odd` isimli değişkende saklayan assembly kodunu yazınız.

### 9.1 Değişkenlerin Tanımlanması

Hoca öğrencilerin henüz eksiksiz bir assembly programı oluşturmak için gerekli ön bilgiye sahip olmadığını, programın başlangıç ve bitiş kısımlarının hazır kabul edileceğini, yalnız kod kısmının düzenleneceğini söyledi. Kabaca bir veri segmenti (değişken tanımları burada yapılır) ve bir kod segmenti (bu değişkenlere erişilir) olacaktır.

N 500 seçildi. Önce N'nin tipi soruldu: define byte mı, define word mü? 500 byte'a sığmadığı için `DW` kullanılır. `ARRAY` bir byte dizisidir, bu yüzden `DB` ile tanımlanır. Tekrarlayan elemanlar `DUP` (duplicate) sözde komutuyla yazılabilir; hoca bunu assembler'ın özel bir kelimesi gibi düşünmeyi önerdi. Dizide beş farklı eleman ve 495 tane 81 vardır; toplam 500 eleman olur.

`ODD` değişkeninin tipi ve ilk değeri soruldu. Bir öğrenci word olması gerektiğini, 500 tane tek sayı olabileceğini söyledi; ilk değer de 0 olmalıydı. Hoca bunu genelleştirdi: kod verilen özel durum için değil, en kötü durum için yazılmalıdır. En kötü durumda bütün sayılar tek olabilir ve ODD'ye 500 yazılması gerekebilir; bu byte'a sığmaz, bu yüzden word tanımlanır. ODD bir sayaç olduğu için ilk değeri 0'dır.

### 9.2 Program Şablonu

Tanımlar emu8086'daki şablona aktarıldı (ekrandan, 01:35:00). Altyazıda dizinin ilk elemanları "1, 2, 5, 8, 80" diye geçiyor, ama karede tanım `ARRAY DB 1,2,8,20,25,495 DUP(81)` olarak görünüyor; hoca da "sayılarda birazcık farklılık olabilir" dedi. Not karedeki değerleri kullanır.

```asm
STEK    SEGMENT PARA STACK 'STK'
        DW 30 DUP(?)
STEK    ENDS

DSG     SEGMENT PARA 'DTS'
N       DW 500
ARRAY   DB 1,2,8,20,25,495 DUP(81)
ODD     DW 0
DSG     ENDS

CSG     SEGMENT PARA 'CODE'
        ASSUME CS:CSG, DS:DSG, SS:STEK
BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DSG
        MOV DS, AX
;kod buradan sonra
        ...
;kod buraya kadar
        RETF
BASLA   ENDP
CSG     ENDS
        END BASLA
```

Hoca şablonu kısaca gösterdi: veri segmenti 5. satırda açılıp 9. satırda kapanır. Programın bir yığın kesimi olmalıdır; yığın kesiminde yığın için yer ayrılır. Kod segmentinin içinde özel başlatma ve sonlandırma satırları vardır; bunların ne olduğuna daha sonra bakılacaktır. Kod, işaretli aralığa yazılır.

### 9.3 Dört Çözüm Yolu

Hoca problemin kaç farklı yolla çözülebileceğini sordu. Tahtada dört yöntem toplandı (ekrandan, 01:45:00):

1. `SHR` + `ADC`: Bir öğrencinin önerisi. Eleman sağa ötelenerek en düşük biti CF'ye düşürülür, `ADC` ile CF sayaca eklenir.
2. `SHR` + `JC`: Yine sağa öteleme, ama CF'ye `JC`/`JNC` ile bakılır.
3. `TEST` (AND) + koşullu dallanma: En düşük bit, kaydırmadan maskelenerek denetlenir.
4. `DIV` + `JZ`: Sayı 2'ye bölünür, kalanın sıfır olup olmadığına bakılır.

Hoca bir sayının tek mi çift mi olduğunu anlamak için en anlamsız bite bakmak gerektiğini, ama "sıfır numaralı bitin ne olduğunu söyle" diyen bir komut olmadığını belirtti; bu ancak bazı işlemler ve manipülasyonlarla anlaşılabilir.

> **Ders sonrası not:** Hoca üçüncü yöntemi sayarken "TEST ve jump carry, jump not carry bakarız" dedi ve tahtaya `JC` yazdı. Sonra yöntemi uygularken "yanlış yazmışım" diyerek tahtadakini `JZ` olarak düzeltti (ekrandan, 02:00:00). `TEST`, `AND` gibi CF'yi her zaman 0 yapar; doğru denetim `JZ`/`JNZ` iledir.

Hoca önce "akla ilk gelen" dördüncü yöntemle başladı.

### 9.4 Yöntem 4: DIV ile

Önce döngünün kaç adım süreceği soruldu: 500. Döngü değişkeni CX'tir ve herhangi bir eleman sayısı için genel yazmak adına `MOV CX, N` kullanılır. Sonra `L1:` etiketi (hemen ardından iki nokta üst üste) ve gövdenin sonunda `LOOP L1` yazıldı.

Dizinin ilk elemanını almak için bir indis yazmacı, SI kullanıldı ve sıfırlandı. Eleman `MOV AL, ARRAY[SI]` ile alınır (ekrandan, 01:45:00). Hoca bu gösterimi açıkladı: `ARRAY[SI]`, veri segmentinde ARRAY adresinden SI kadar ötedeki ofsetteki değeri okumak demektir; tahtada `DS:(ARRAY+SI)` olarak yazıldı. Tip uyuşmazlığı olup olmadığı soruldu: AL 8 bitliktir, ARRAY byte tanımlıdır; emülatörde denenince sorun çıkmadı. Sonraki elemana geçmek için `LOOP`'tan önce `INC SI` yazılır; dizi byte olduğu için her eleman bir bayt yer kaplar ve bir adres ilerlemek yeterlidir.

Ardından AL'deki değerin 2'ye bölünmesi gerekiyordu. Bir öneri `SHR AL` idi; ama `SHR` lojik bir sağa öteleme olduğu için kalanı vermez. Kalan isteniyorsa `DIV` kullanılmalıdır. Önce `DIV 2`, sonra bir öğrencinin önerisiyle `DIV AL, 2` denendi; ikisi de "should be a register or a memory location" hatası verdi. Yani iki biçim de `DIV`'in sözdizimine uymaz.

Hoca `DIV`'in gizli işlenenini hatırlattı. 8 bitlik bölmede AX işlenene bölünür; bölüm AL'ye, kalan (AX mod işlenen) AH'a yazılır. 16 bitlik bölmede (örneğin `DIV BX`) DX:AX ikilisi işlenene bölünür; bölüm AX'e, kalan DX'e yazılır. Burada AL 2'ye bölüneceği için 8 bitlik bölme yapılmalı ve işlenen 8 bitlik olmalıdır: `MOV BL, 2` / `DIV BL`. `MOV BL, 2` döngünün dışına alınabilir; BL bir daha bozulmayacağı için bir kez atamak yeterlidir.

Hoca `DIV BL` ile bir şeyin gözden kaçtığını söyledi: bölme AX'i böler, AL'de istenen değer vardır, ama AH'ta ne olduğu belli değildir. Bunu göstermek için `MOV AX, ARRAY[SI]` denendi; "operands do not match: 16 bit register and 8 bit address" hatası alındı (ekrandan, 01:50:00), çünkü AX 16 bitliktir ve ARRAY byte tipindedir. Amaç doğru ama yapılış yanlıştır. AH'ta rastgele bir değer olabilir; ayrıca döngü boyunca her bölmenin kalanı AH'ta kalır. Bu yüzden bölmeden önce AH'ın 0 olduğu garanti edilmelidir.

Sonra koşul yazıldı. Akış "Tek mi? Tekse ODD'yi artır; çiftse (false kolu) bir şey yapma" biçimindedir; false kolu boştur. Bölme sonucunda kalan (AH) yalnız 0 ya da 1 olabilir. Kalan sıfırsa sayı çifttir ve `JZ` ile dallanılabilir. Ancak `DIV` sonrasında hem AL hem AH değiştiği için ZF'nin hangisine göre değiştiğinden emin olunamaz. Bu yüzden önce `AND AH, 01H` ile AH'ın son biti maskelenir; böylece ZF'nin AH'tan geldiği garanti olur. Sonuç sıfırsa sayı çifttir ve artırma yapılmadan sonraki elemana geçilir; tekse `INC ODD` ile sayaç artırılır.

Karede görülen kod (ekrandan, 01:55:00) ve önceki satırlarla birlikte yöntem:

```asm
        MOV CX, N
        XOR SI, SI
        MOV BL, 2
L1:     MOV AL, ARRAY[SI]
        MOV AH, 0          ; AH sıfırlanır
        DIV BL             ; 8 bit div: AL <- AX/op, AH <- AX mod op
        AND AH, 01H
        JZ CIFT
        INC ODD
CIFT:   INC SI
        LOOP L1
```

<!-- BELİRSİZ: AH'ı sıfırlayan satırın tam yazımı (MOV AH, 0 ya da XOR AH, AH) ve MOV BL, 2'nin tam yeri karede görünmüyor; DIV BL'den LOOP L1'e kadar olan satırlar kareden alındı, XOR SI, SI satırı 01:45:00 karesinden. -->

Kod emülatörde çalıştırıldı. `RETF` satırına kadar çalıştırma yapıldı (run until). Bu sırada CX giderek azalır, SI artar; SI en sonunda 500'e, CX 0'a ulaşır. Emülatör yavaş olduğu için biraz beklendi. Durduktan sonra "view → variables" ile ODD değişkenine bakıldı; onaltılık gösterim işaretsize çevrildiğinde 497 görüldü (ekrandan, 01:55:00). Hoca dizide 1, 25 ve 495 tane 81 olmak üzere 497 tek değer bulunduğunu, sonucun doğru olduğunu söyledi. Python ile yapılan sayım da 497 = 01F1h verdi.

### 9.5 Yöntem 3: Adres Üzerinden Erişim ve TEST

İkinci dosyada üçüncü yöntem uygulandı, ama bu kez dizi elemanlarına indisle değil, adresleri üzerinden (işaretçi mantığıyla) erişildi. Köşeli parantez içinde adres veren yazmaçlar BX, DI ve SI'dir. Plan, dizinin başlangıç adresini BX'e almak ve BX'i işaretçi olarak kullanmaktır.

Hoca bir değişkenin adresini almanın nasıl yapıldığını sordu; adres almak, değişkenin kendi segmentinde hangi ofsette olduğunu bulmak demekti. Bir süre cevap gelmedi; sonunda bir öğrenci "load effective address" dedi. `LEA BX, ARRAY` ile ARRAY'in ofseti BX'e alınır. Bu satırdan sonra `[BX]`, `ARRAY[0]`'a eşittir (ekrandan, 02:00:00). `MOV AL, [BX]` dizinin ilk elemanını alır. Sonraki elemana geçmek için SI'ye bile gerek yoktur: dizi byte olduğu için `INC BX` bir sonraki elemana gitmek demektir.

Elemanın son biti `TEST` ile maskelenir. Maske, son biti 1, diğer bitleri 0 olan 01H'dir. Koşul yine "tekse işlem var, çiftse yok" biçimindedir. `TEST` sonucu 0 ise sayı çifttir ve `JZ CIFT` ile atlanır; hemen alttaki satır tek koluna karşılık gelir: `INC ODD`.

Hoca `MOV AL, [BX]` ve `TEST AL, 01H` satırlarının birleştirilip birleştirilemeyeceğini sordu ve iki satırın yerine `TEST [BX], 01H` yazdı. Emülatör bunu derlerken satırı bir byte işlemine çevirdi; yani tip belirtilmezse byte kabul etti. Hoca tipin açıkça belirtilmesi gerektiğini söyledi: `TEST BYTE PTR [BX], 01H`. Satır adres üzerinden çalıştığı için 16 bitlik bir değer verilse de byte işlemi bozulmadı. Birleştirilmiş yöntem:

```asm
        LEA BX, ARRAY
        MOV CX, N
L1:     TEST BYTE PTR [BX], 01H
        JZ CIFT
        INC ODD
CIFT:   INC BX
        LOOP L1
```

<!-- BELİRSİZ: Birleştirilmiş son hâlin karesi okunmadı; satır sırası anlatımdan kuruldu. INC BX'in TEST'ten sonra gelmesi, bulunan 497 sonucuyla tutarlıdır. -->

Hoca akışı özetledi: dizinin elemanı 01H ile test edilir; sonuç 0 ise sayı çifttir ve sonraki elemana geçilir; tekse ODD artırılır ve sonraki elemana geçilir. Kod emülatörde çalıştırıldığında BX 500 ilerler, CX 0'a ulaşır; ODD yine 1F1h, yani işaretsiz 497 çıktı.

### 9.6 Yöntem 2: SHR ve JNC

Aradan sonra üçüncü dosyada ikinci yöntem uygulandı. Yine `LEA BX, ARRAY`, `MOV CX, N`, `L1:` ve `LOOP L1` yazıldı. Sıradaki eleman `MOV AL, [BX]` ile alınır, sonraki elemana geçmek için `INC BX` yazılır. Ardından `SHR AL, 1` ile AL'nin en düşük anlamlı biti CF'ye düşürülür. Koşul yine boş kol (çift kol) için yazılır: çiftse CF'ye düşen değer 0'dır, bu yüzden `JNC CIFT`. Tek kolunda `INC ODD` vardır.

```asm
        LEA BX, ARRAY
        MOV CX, N
L1:     MOV AL, [BX]
        INC BX
        SHR AL, 1
        JNC CIFT
        INC ODD
CIFT:   LOOP L1
```

Kod derlendi, hata yoktu; `RETF`'e kadar çalıştırıldı ve ODD yine işaretsiz 497 olarak görüldü.

### 9.7 Yöntem 1: SHR ve ADC

Son dosyada ilk yöntemi öneren öğrenci kodu hocayla birlikte yazdırdı. `LEA BX, ARRAY` ve `MOV CX, N` ile başlandı (ekrandan, 02:25:00), döngü oluşturuldu. Gövde: `MOV AL, [BX]`, `INC BX`, `SHR AL, 1` ve `ADC ODD, 0`. Önce sayaç olarak başka bir yazmaç düşünüldü (CX olmaz, DX olabilir), ama ODD değişkeni zaten vardır; doğrudan `ADC ODD, 0` yazıldı.

```asm
        LEA BX, ARRAY
        MOV CX, N
L1:     MOV AL, [BX]
        INC BX
        SHR AL, 1
        ADC ODD, 0
        LOOP L1
```

Hoca çözümü şöyle açıkladı: her eleman için en düşük anlamlı bit CF'ye düşürülür, sonra elde ile toplama (add with carry) yapılır. ODD başta 0'dır; ODD ile 0 toplanır, üstüne CF eklenir. CF 1 ise ODD bir artar, 0 ise olduğu gibi kalır. Sonuç yine 1F1h = 497 oldu.

### 9.8 Dallanmasız Kodlama Üzerine

Hoca bu çözümün önemli bir özelliğine dikkat çekti. İlk derslerde mikroişlemcinin içinde bir önden çekme kuyruğu (prefetch queue) olduğu anlatılmıştı: işlemci başka işlerle meşgulken sıradaki komutları bellekten önden okuyup içeri kopyalar ki sırası geldiğinde bir daha belleğe gitmesin. Bu önden çekilen komutlar bazı durumlarda çöpe gider; örneğin dallanmalarda. Koşullu dallanma yazılırken koşul boş kol için yazıldığından sırayla çekilen kodlar dolu kolun kodlarıdır; dallanma gerçekleşirse bunlar boşa gider.

Bu yüzden günümüzde dallanmasız kodlama (branchless coding) adı sıkça geçen bir yaklaşımdır: dallanma koşulu bir mantık işlemine dönüştürülür ve işlemler buna göre tanımlanır. `SHR` + `ADC` çözümünde hiç dallanma yoktur. Hoca ilgilenenlerin "branchless coding" diye araştırmasını önerdi.

### 9.9 Word Dizisine Geçiş

Son örnekte aynı kodda dizinin tanımı byte'tan word'e çevrildi ve tekleri saymak için hangi değişikliklerin gerektiği soruldu. Öğrenciler AL yerine AX kullanılması ve BX'in 2 artırılması gerektiğini söyledi. Hoca bunu onayladı:

- Dizi word olduğu için sıradaki eleman görünüşte 1 olsa da aslında 0001h'dir; 16 bitlik bir değerdir ve AX'e okunur. Öteleme de AX üzerinden yapılır.
- Her eleman iki bayt yer kapladığı için (yüksek anlamlı baytı 00, düşük anlamlı baytı 01) sonraki eleman iki adres ötededir: `ADD BX, 2`.

Karede görülen gövde (ekrandan, 02:30:00):

```asm
L1:     MOV AX, [BX]
        SHR AX, 1
        ADC ODD, 0
        ADD BX, 2
        LOOP L1
```

Dizide yine 497 tek sayı vardır, yalnız word tipindedir; çalıştırıldığında yine 497 görüldü. Emülatörün çözümlediği kodda `LEA BX, ARRAY` satırı `MOV BX, 00002h` olarak, `ADC ODD, 0` satırı ise `ADC w.[003EAh], 0` olarak görünür (ekrandan, 02:30:00). N iki bayt yer kapladığı için ARRAY 2. ofsette başlar; 500 word eleman 1000 bayt tuttuğu için ODD $2 + 1000 = 1002 = 03EAh$ ofsetindedir (python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** Bu gövdede `ADD BX, 2` satırının `ADC`'den sonra gelmesi önemlidir: `ADD` CF'yi değiştirir; `SHR` ile `ADC` arasına konsaydı `ADC` öteleme sonucunu değil toplamanın elde bitini ekleyebilirdi. Byte sürümündeki `INC BX` ise CF'yi etkilemediği için `SHR`'den önce durabilir.

Bu ortamda assembler ya da 8086 emülatörü kurulu olmadığı için dört çözüm derlenmedi; komutların etkisi python ile taklit edildi ve dördü için de 497 bulundu.

### 9.10 Problemlerin Genel Akışı ve emu8086 ile MASM

Hoca karşılaşılacak problemlerin genellikle bu örnekteki gibi olacağını söyledi: veri kesimi tanımı verilmez, yalnız problem tanımı verilir. Problemden hareketle değişkenlerin byte mı word mü olacağına (örneğin sayma adedinin word'e sığacağına) karar verilip veri segmenti tanımı yapılmalıdır. Çözüm yöntemi olarak pek çok seçenek vardır; doğru çalışan bir çözüm bir cevaptır, ama olabildiğince optimal, daha az satırlı bir çözüm hedeflenmelidir. Bu, pratik yaptıkça gelişir.

Hoca şu aşamada emu8086 ile devam edileceğini, ama ileride arka planda DOS çalıştıran bir yapıya, DOSBox üzerinde MASM'e (Microsoft Macro Assembler) geçileceğini söyledi. Aynı kod emu8086'da çalışsa da referans DOSBox ve MASM olacaktır; orada çalışmayan kod hatalı sayılır. emu8086'nın `SHR AX, 4` gibi kolaylıklarına bu yüzden güvenilmemelidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:29:35): İkişer azalan FOR DOWN TO örneğinde (`MOV CX, 10` / `tekrar: ADD AX, CX` / `SUB CX, 2` / `JCXZ devam` / `JMP tekrar`) bir "kaçak" olabilir mi?

> **Çözüm:** Evet. CX tek bir sayıyla (örneğin 9 ya da 11) başlasaydı, 2 çıkarıla çıkarıla 1'den sonra sıfırı atlayıp FFFFh'ye geçerdi; CX hiçbir zaman 0 olmayacağı için `JCXZ` dallanmaz ve döngü sonsuza kadar döner. CX = 10 ile başlandığında döngü 5 kez döner ve AX = 30 olur.

**Soru 2** (derste sözlü, 00:36:07 ve 00:37:06): REPEAT UNTIL örneğinde (`CMP SI, 10` / `JBE tekrar`) döngüden ne zaman çıkılır? `JBE` yerine `JNA` yazmak daha doğru olmaz mı?

> **Çözüm:** Alt satıra I > 10 olduğunda geçilir; I ≤ 10 iken `JBE` dallanır ve gövde tekrarlanır. `JNA` ile `JBE` aynı komuttur; işlev olarak fark yoktur. Diyagramdaki koşul "I > 10" olduğu için `JNA` okunuş açısından onun değili olarak daha doğrudan okunur; ikisi de kullanılabilir.

**Soru 3** (derste sözlü, 00:39:51): İç içe iki FOR'da iki döngü de CX kullanıyorsa dış döngünün değeri nasıl korunur?

> **Çözüm:** İç döngüye girmeden önce dış CX yedeklenir, iç döngü bitince geri yüklenir: ya kullanılmayan bir yazmaçla (`MOV DX, CX` ... `MOV CX, DX`) ya da yığınla (`PUSH CX` ... `POP CX`). Yığın kullanılırsa aradaki bütün `PUSH`'lara karşılık `POP` olmalıdır.

**Soru 4** (derste sözlü, 01:25:05; ekrandan, 01:25:00): `MOV AL, -16` / `SAR AL, 1` sonrasında AL'deki değer nedir?

> **Çözüm:** $-16 = 1111\,0000_2$. `SAR` bitleri bir sağa kaydırır, D0 (0) CF'ye gider, MSB (1) tekrar edilir: $1111\,1000_2$. Genlik için ikiye tümleyen alınır: $0000\,1000_2 = 8$; sonuç −8'dir, CF = 0.

**Soru 5** (derste sözlü, 01:32:09 ve 01:33:33): Tek eleman sayma örneğinde N (500) ve ODD değişkenleri hangi tipte, ODD hangi ilk değerle tanımlanmalıdır?

> **Çözüm:** İkisi de word (`DW`). 500 byte'a sığmaz; en kötü durumda dizinin bütün elemanları tek olabilir ve ODD 500'e ulaşabilir. ODD bir sayaç olduğu için ilk değeri 0'dır: `N DW 500`, `ODD DW 0`.

**Soru 6** (derste sözlü ve tahtada, 01:30:09; ekrandan, 01:45:00): N elemanlı `ARRAY` byte dizisindeki tek eleman sayısını `ODD` değişkenine yazan kodu yazınız. Kaç farklı yolla çözülebilir?

> **Çözüm:** Derste dört yol verildi: (1) `SHR` + `ADC ODD, 0`, (2) `SHR` + `JNC`, (3) `TEST BYTE PTR [BX], 01H` + `JZ`, (4) `MOV BL, 2` / `DIV BL` + `AND AH, 01H` + `JZ`. Kodları Bölüm 9.4-9.7'dedir. `ARRAY DB 1,2,8,20,25,495 DUP(81)` için dördü de ODD = 01F1h = 497 verdi.

**Soru 7** (derste sözlü, 01:46:48 ve 01:49:25): AL'deki değeri 2'ye bölüp kalanı bulmak için `DIV 2` ya da `DIV AL, 2` neden kullanılamaz? `MOV BL, 2` / `DIV BL` yazınca neyi gözden kaçırırız?

> **Çözüm:** `DIV`'in tek açık işleneni vardır ve bu bir yazmaç ya da bellek olmalıdır; anlık değer verilemez. 8 bitlik `DIV BL`, AL'yi değil AX'i böler (AL ← AX / BL, AH ← AX mod BL). AH'ta rastgele bir değer ya da önceki bölmeden kalan bulunabileceği için bölmeden önce AH sıfırlanmalıdır.

**Soru 8** (derste sözlü, 01:56:45-01:58:08): Dizi elemanlarına indis yerine adres üzerinden erişmek için dizinin başlangıç adresi bir yazmaca nasıl alınır?

> **Çözüm:** `LEA BX, ARRAY` ile ARRAY'in kendi segmentindeki ofseti BX'e alınır; köşeli parantez içinde adres olarak BX, SI ya da DI kullanılabilir. Bundan sonra `[BX]`, `ARRAY[0]`'a eşittir; byte dizisinde `INC BX` sonraki elemana geçer.

**Soru 9** (derste sözlü, 02:01:31): `MOV AL, [BX]` ve `TEST AL, 01H` satırları nasıl tek satırda birleştirilir?

> **Çözüm:** `TEST BYTE PTR [BX], 01H`. Bellek işleneni ile anlık değer birlikte kullanıldığı için boyut belirsizdir; emülatör byte kabul etti, ama tip `BYTE PTR` ile açıkça yazılmalıdır.

**Soru 10** (derste sözlü, 02:28:32; ekrandan, 02:30:00): `ARRAY` byte yerine word dizisi olarak tanımlanırsa `SHR` + `ADC` çözümünde neler değişir?

> **Çözüm:** Eleman AX'e okunur ve AX ötelenir (`MOV AX, [BX]`, `SHR AX, 1`); her eleman iki bayt olduğu için `INC BX` yerine `ADD BX, 2` yazılır. `ADC ODD, 0` ve `LOOP L1` değişmez. Sonuç yine 497'dir.

## Dersin Toparlaması

Bu derste döngü sayısının bilindiği durumlar için 8086'nın dört döngü komutu incelendi. `LOOP` CX'i azaltıp sıfır değilse dallanır; `LOOPZ` ve `LOOPNZ` buna ZF koşulunu ekler; `JCXZ` ise CX'e dokunmadan yalnız CX = 0 ise dallanır ve CX'in değiştirilmesini programcıya bırakır. Bu komutlarla FOR TO, ikişer azalan FOR DOWN TO, WHILE ve REPEAT UNTIL yapıları kuruldu; koşulun boş kol için yazılmasının tek dallanmayla yetinmeyi sağladığı ve iç içe döngülerde dış CX'in yazmaç ya da yığınla korunması gerektiği gösterildi.

Ardından bayraklar üç gruba ayrıldı (doğrudan komutlu CF, DF, IF; LAHF/SAHF ile değiştirilen SF, ZF, AF, PF, CF; PUSHF/POPF ile değiştirilen OF ve TF), mantıksal komutlarla bit kurma, temizleme ve tümleme hatırlatıldı, öteleme (`SHL`/`SAL`, `SHR`, `SAR`) ve döndürme (`RCL`, `RCR`, `ROL`, `ROR`) komutları ele alındı. Son olarak bu komutlar bir dizideki tek elemanları saymak için dört farklı yolla emu8086 üzerinde birleştirildi; dallanmasız `SHR` + `ADC` çözümü öne çıkarıldı. Bir sonraki hafta dizi (katar) işlemlerine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
