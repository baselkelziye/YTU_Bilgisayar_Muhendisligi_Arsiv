# Ders 10 Genişletilmiş Notu: Makrolar, DOS Kesmeleri ve Yığın Üzerinden Parametre Aktarımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Yordamlar ve Dış Dosyadan Kullanım
- 2. Yordam ve Makro: Temel Fark
- 3. Örnek: Üs Alma (Tek Dosyada)
- 4. Üs Almayı Dış Dosyada FAR Yordamla Yapmak
- 5. Üs Almayı Makroyla Yapmak
- 6. Yordam ve Makro Karşılaştırma Tablosu
- 7. DOS Kesmeleri ve Kesmeleri Makroya Çevirmek
- 8. Yordamlara Parametre Aktarım Yolları
- 9. Yığın Üzerinden Parametre Aktarımı: Varyasyonlar
- 10. Örnek: Yığından İki Parametreyle EBOB
- 11. Dönüş Değerini Yığından Vermek
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Yordamlar ve Dış Dosyadan Kullanım

Hoca derse geçen haftanın kısa bir tekrarıyla başladı. Geçen hafta aynı dosyada ve farklı dosyada yordam tanımlama, FAR ve NEAR yordamlar ve en büyük ortak bölen (EBOB) hesaplayan bir fonksiyonun farklı biçimlerde kullanılması görülmüştü. Parametreler o örneklerde yazmaçlar üzerinden aktarılmıştı.

### 1.1 Aynı dosyada yordam

EXE tipi bir programda ana yordam FAR olmalıdır. Aynı dosyadaki alt yordamlar NEAR olabilir; bu durumda çağırmak için `CALL etiket` yazmak yeterlidir. Aynı dosyada FAR tanımlanmış bir alt yordam ise `CALL FAR PTR etiket` ile çağrılır. DEBUG'da bakıldığında NEAR çağrının makine kodunda CALL'dan sonra mutlak bir ofset değeri, FAR çağrıda ise segment:ofset çifti bulunduğu görülmüştü.

### 1.2 Farklı dosyada yordam

Modüler kod geliştirmenin bir adım ötesi, alt yordamları farklı dosyalarda tanımlamaktır. İki dosya düşünelim: ana yordamın bulunduğu EXE programı (`ana.asm`) ve alt yordamın bulunduğu dosya (`alt.asm`).

- `ana.asm` içinde dışarıdan kullanılacak fonksiyon için bir `EXTRN` tanımı yapılır ve tipi iki nokta üst üste ile belirtilir: `EXTRN etiket:FAR`.
- Ana yordamda bu yordam yalnız `CALL etiket` ile çağrılır. Assembler, `EXTRN` tanımındaki FAR işareti yüzünden bu satırı `CALL FAR PTR` olarak derler.
- `alt.asm` içinde dışarıya kullandırılacak fonksiyon `PUBLIC etiket` ile tanımlanır. Ana yordamda FAR olarak kullanılacağı söylendiği için kendi dosyasında da FAR tanımlanmalıdır.

Yordamın girdi ve çıktıları baştan belirlenir. Örneğin "bu fonksiyonun girdileri AX ve DX, çıktısı AX'tir" diye anlaşılır ve ana yordam fonksiyona parametre aktarırken ve sonucu alırken bu prototipe uyar.

Derleme sırası şöyledir: `ana.asm` MASM'den geçirilip OBJ dosyası, `alt.asm` MASM'den geçirilip ikinci bir OBJ dosyası üretilir, sonra iki OBJ birlikte linklenir. `PUBLIC` tanımı eksikse hata linkleme aşamasında çıkar: ana yordam belirli adda bir etiket bekler ama bu etiketi dışarı sunan bir OBJ yoktur.

### 1.3 Özyinelemeli yordam

Geçen hafta EBOB fonksiyonu özyinelemeli olarak da yazılmıştı. Özyinelemeli bir fonksiyonun bir sonlanma koşulu olmalıdır, yoksa sonsuza kadar sürer. EBOB için sonlanma koşulu $\gcd(x, 0) = x$, yineleme adımı ise $\gcd(x, y) = \gcd(y, x \bmod y)$ idi. Her çağrıda yığına atılan değerler incelenmiş, yığına kaç kez değer atıldığına bakılarak yordamın kaç kez iç içe çağrıldığı izlenmişti.

> **Hocanın vurgusu:** Böyle özyinelemeli bir çağrıda "yığının en dolu olduğu andaki içeriği nedir?" sorusuyla karşılaşılabilir. Hoca bunu derste verilen örnek ya da kendi kurduğunuz örnekler üzerinde denemenizi önerdi.

Geçen hafta aynı işlerin makroyla da yapılabileceğinden ve makro ile yordam arasındaki farklardan da söz edilmişti. Bu ders makro tarafının örnekleriyle devam etti.

## 2. Yordam ve Makro: Temel Fark

Makro ve yordam, modüler kod geliştirmede kullanılabilecek iki araçtır.

### 2.1 Yordam

Yordam (prosedür) `CALL` ile çağrıldığında normal program akışı kırılır, IP yordamın tanımlı olduğu noktaya gider ve oradaki kodlar yürütülür. Dönüşte akış, CALL'dan sonraki satırdan devam eder. Biraz sonra aynı yordam yine çağrılırsa akış yine kırılır, yordam bu kez yeni parametrelerle yürütülür ve geri dönülür.

Bu yüzden yordam her çağrıldığında kod büyümez. Makine kodu, yordamın tanımlı olduğu yerde bir kez üretilir. Bir yordam tanımlanıp hiç çağrılmasa bile tanımı yüzünden makine kodu üretilir ve kod o kadar büyür.

Yordam tanımı bir başlangıç ve bitiş kelime grubu arasında yapılır:

```text
etiket  PROC [FAR]
        ...           ; yordamın işi
        RET / RETF
etiket  ENDP
```

Tip yazılmazsa yordam NEAR kabul edilir. Dönüşte mutlaka bir RET olmalıdır: FAR ise `RETF`, NEAR ise `RET`.

> **Hocanın vurgusu:** Assembler FAR tanımlı bir yordamdaki `RET`'i kendisi `RETF`'e çevirir, ama derste şu kural kabul edildi: yordam FAR ise dönüş mutlaka `RETF` olarak yazılır.

### 2.2 Makro

Makro dosyada bir tanım olarak durur. Makro her çağrıldığında, tanımındaki kod bloğu alınıp çağrıldığı yere yapıştırılır. Birkaç kez çağrılırsa aynı kod parçası birkaç kez tekrar eder. Bu yüzden makro her çağrıldığında kodu kendi büyüklüğü kadar büyütür. Buna karşılık makronun tanımlandığı bölge için makine kodu üretilmez: makro tanımlanıp hiç çağrılmazsa kod büyüklüğü değişmez.

Makro tanımı şöyledir:

```text
ad      MACRO  param1, param2, ...
        LOCAL  L1
        ...           ; makro kodu
        ENDM
```

Parametre listesi isteğe bağlıdır. Makro `ENDM` ile biter.

### 2.3 Makroda etiket ve LOCAL

Makro kodunda döngü ya da koşullu/koşulsuz dallanma, yani etiket varsa dikkat etmek gerekir. Makro her çağrıldığında aynı kod tekrarlandığı için, önlem alınmazsa aynı etiket her çağrıda yeniden konur. Kodda `L1` diye bir etiket varsa ilk çağrıda bir `L1`, ikinci çağrıda bir `L1` daha oluşur ve hangisinin kastedildiği belli olmaz.

Bunu önlemek için benzersiz kalması istenen etiketler `LOCAL` kelimesinden sonra verilir. Bu durumda makronun her açılışında `L1` benzersiz bir adla değiştirilir; `LOOP L1` satırındaki etiket de aynı adla değişir. Birinci çağrıda "L1 benzersiz 1", ikinci çağrıda "L1 benzersiz 2" gibi adlar oluşur.

> **Hocanın vurgusu:** Makroda etiket kullanılıyorsa `LOCAL` satırı mutlaka yazılmalıdır. Yazılmazsa aynı etiketin birden fazla tanımı olur.

## 3. Örnek: Üs Alma (Tek Dosyada)

Hoca makro örneğine geçmeden önce aynı işin tek dosyada nasıl yapılacağını gösterdi. Amaç $2^3$ ve $3^2$ değerlerini hesaplayıp sonuç değişkenlerine yazmaktır. Veri kesimi şöyledir (ekrandan, 00:20:00):

```text
DATASG  SEGMENT PARA 'DATA'
US1     DW 3
TABAN1  DW 2
SONUC1  DD ?
US2     DW 2
TABAN2  DW 3
SONUC2  DD ?
DATASG  ENDS
```

Üs ve taban word, sonuç double word olarak tanımlandı. Hoca bunun bütün word değerler için yeterli olmadığını, çok yüksek değerlerde sonucun double word'e de sığmayabileceğini, kodun küçük değerler için düşünüldüğünü belirtti.

### 3.1 EXE şablonunun başı

Program bir EXE şablonudur. Ana yordam `BASLA PROC FAR` ile başlar, ardından `PUSH DS` / `XOR AX, AX` / `PUSH AX` gelir. İşletim sistemi programı çağırdığında dönüş segmentini DS'de verir ve bu segmentin 0 ofsetine dönülmesini ister. Bu üç satır işletim sistemine dönüş adresini yığına koyar; ana yordamın sonundaki `RETF` sırasıyla 0 ofsetini ve segment değerini yığından çekerek işletim sistemine döner. Sonraki iki satır, `MOV AX, DATASG` ve `MOV DS, AX`, DS'nin tanımlanan veri kesimini göstermesini sağlar.

### 3.2 Algoritma

Üs alma, tabanı üs kadar kendisiyle çarpmaktır. $2^0 = 1$ olduğu için başlangıç değeri 1'dir ve her adımda sonuç taban ile çarpılır. Döngü üs kadar döner; bu yüzden CX'e üs yüklenir. Kod şöyledir (ekrandan, 00:25:00):

```text
        MOV CX, US1
        MOV AX, 1
        MOV BX, TABAN1
L1:
        MUL BX
        LOOP L1
        LEA SI, SONUC1
        MOV [SI], AX
        MOV [SI+2], DX

        MOV CX, US2
        MOV AX, 1
        MOV BX, TABAN2
L2:
        MUL BX
        LOOP L2
        LEA SI, SONUC2
        MOV [SI], AX
        MOV [SI+2], DX
```

$2^3$ için adım adım:

- Başlangıç: CX = 3, AX = 1, BX = 2.
- 1. çarpma: AX = 2 ($2^1$), CX = 2.
- 2. çarpma: AX = 4, CX = 1.
- 3. çarpma: AX = 8, CX = 0, döngüden çıkılır.

`MUL BX` sonucu DX:AX'te biriktirir. AX düşük anlamlı word olduğu için sonuç değişkeninin düşük word'üne, DX yüksek word'üne yazılır. Bunun için `LEA SI, SONUC1` ile sonucun etkin adresi SI'ya alınır, `MOV [SI], AX` ile düşük word, `MOV [SI+2], DX` ile bir sonraki word yazılır.

Aynı blok ikinci üs-taban çifti için `L2` etiketiyle bir kez daha yazıldı. Hoca, aynı görevi yerine getiren kod bloğunu tekrarlamak zorunda kalmanın modüler kullanım gerektiren bir durum olduğunu vurguladı.

### 3.3 DEBUG ile çalıştırma

DOSBox'ta uzun dosya adı sorun çıkardığı için dosya adı kısaltıldı, program derlenip DEBUG'da yürütüldü. Birinci çarpımlar sonunda DX = 0, AX = 8 oldu ve bu değerler SONUC1'e yazıldı. İkinci grup için CX = 2, BX = 3 ile iki çarpma yapıldı, AX = 9 oldu.

Veri kesiminin 0 ofsetinden alınan döküm (ekrandan, 00:35:00):

```text
076E:0000  03 00 02 00 08 00 00 00-02 00 03 00 09 00 00 00
```

İlk iki word US1 = 3 ve TABAN1 = 2'dir. Sonraki dört byte `08 00 00 00`, en düşük anlamlı byte'tan başladığı (little endian) için tersten okunur: SONUC1 = 00000008H. Aynı şekilde US2 = 2, TABAN2 = 3 ve SONUC2 = 00000009H görülür.

## 4. Üs Almayı Dış Dosyada FAR Yordamla Yapmak

### 4.1 Kara kutu tasarımı

Hoca önce şu soruyu sordu: CX'te üs, BX'te taban, AX'te 1 var; AX bir parametre midir? Cevap: hayır. AX her zaman 1 ile başlar, yani yordamın içinde atanacak bir değerdir. Fonksiyon bir kara kutu olarak düşünüldüğünde:

- Adı: `USTAL`.
- Girdiler: üs (CX) ve taban (BX).
- Çıktı: sonuç (DX:AX). Yordam sonucu nereye yazacağını bilmediği için çıktı yazmaçlarda üretilir.

AX ve DX parametre değildir; AX yordam içinde 1 yapılır ve parametrelere göre güncellenir. Fonksiyonun girdisi de çıktısı da yazmaçtır. Ana yordam iki iş yapar: parametreleri yazmaçlara aktarır ve dönen DX:AX değerini sonuç bölgesine yazar.

### 4.2 Kod

Alt dosya `ustal.asm` (ekrandan, 00:50:00):

```text
PUBLIC USTAL
MYCS    SEGMENT PARA 'CC'
        ASSUME CS:MYCS

USTAL   PROC FAR    ;girdi BX: taban, CX: us, donus DX:AX
        MOV AX, 1
L1:
        MUL BX
        LOOP L1
        RETF
USTAL   ENDP

MYCS    ENDS
        END
```

Ana dosyada `EXTRN USTAL:FAR` tanımı yapılır. Ana yordamda her çift için (ekrandan, 00:35:00):

```text
        MOV CX, US1
        MOV BX, TABAN1
        CALL USTAL
        LEA SI, SONUC1
        MOV [SI], AX
        MOV [SI+2], DX
```

Alt dosyada tek segment olduğu için assembler'a yalnız CS'nin bu segment olduğu söylenir. Yordam dışarıya FAR olarak kullandırıldığı için `PUBLIC` satırı vardır. Loop'un kaç kez döneceği zaten CX'teki üsten gelir.

> **Hocanın vurgusu:** Alt dosyadaki `END` kelimesinden sonra hiçbir etiket yoktur. Bu, o dosyanın EXE programı için bir giriş noktası oluşturmadığını belirtir. Buraya dikkat edilmelidir.

### 4.3 Derleme ve DEBUG

Ana dosya ve `ustal.asm` ayrı ayrı derlendi, `ana.obj + ustal.obj` birlikte linklendi. DEBUG'da DS ayarlandıktan sonra CX ve BX parametreleri hazırlandı, farklı dosyadaki FAR yordam çağrıldı. Yordamda AX 1 yapıldı, CX kadar döngüde kalındı, `RETF` ile ana yordama, `LEA` satırına dönüldü ve sonuç yerine yazıldı. İkinci çağrıda yordama girildiğinde CX = 2, BX = 3 idi; ilk çağrıda BX = 2, CX = 3 idi. Yani aynı fonksiyon farklı parametrelerle çağrılmış oldu.

## 5. Üs Almayı Makroyla Yapmak

### 5.1 İki parametreli makro

Makro ayrı bir dosyada (`USTAL_M.M`) tanımlandı (ekrandan, 00:40:00):

```text
USTALM  MACRO M_US, M_TABAN
        LOCAL L1
        MOV AX, 1
        MOV CX, M_US
        MOV BX, M_TABAN
L1:
        MUL BX
        LOOP L1
        ENDM
```

Etiket `USTALM`, `MACRO` kelimesi bunun bir makro tanımı olduğunu gösterir, ardından iki parametre gelir. Makroda kullanılacak yazmaçlar baştan bellidir. Fark şudur: yordam örneğinde parametreler CX ve BX üzerinden aktarılıyor, ana yordam önce bu yazmaçları dolduruyordu. Makroda ise çağrı sırasında doğrudan bellek etiketleri verilir: `USTALM US1, TABAN1` ve `USTALM US2, TABAN2`. Etiketlerin değerleri makronun içinde yazmaçlara alınır. Böylece çağrı tarafında parametre hazırlama ihtiyacı ortadan kalkar.

Makroyu ana dosyaya eklemek için `INCLUDE` ile makro dosyasının adı verilir. Makro dosyası ayrı bir OBJ üretmez; yalnız ana dosya derlenir ve doğrudan linklenir.

### 5.2 LST dosyasında makro

Ana dosyanın LST'sine bakıldığında şunlar görüldü:

- `INCLUDE` ile eklenen makro tanımı satırları dosyaya yapıştırılmış, ama bunlara karşılık makine kodu üretilmemiştir.
- `USTALM US1, TABAN1` çağrı satırının da makine kodu yoktur. Oysa yordam çağrısında `CALL` satırına bir makine kodu karşılık geliyordu, çünkü CALL bir 8086 komutudur. `USTALM` diye bir komut yoktur; assembler bu satırın yerine makro gövdesini koyar.
- `LOCAL L1` yüzünden etiket birinci çağrıda `??0000`, ikinci çağrıda `??0001` olarak adlandırılmış ve LOOP komutunda da bu adlar kullanılmıştır.

LST'den bir bölüm (ekrandan, 00:45:00):

```text
49                         USTALM US1, TABAN1
50  0009  B8 0001       1      MOV AX, 1
51  000C  8B 0E 0000 R  1      MOV CX, US1
52  0010  8B 1E 0002 R  1      MOV BX, TABAN1
53  0014                1  ??0000:
54  0014  F7 E3         1      MUL BX
55  0016  E2 FC         1      LOOP ??0000
56  0018  8D 36 0004 R      LEA SI, SONUC1
57  001C  89 04             MOV [SI], AX
58  001E  89 54 02          MOV [SI+2], DX
```

Hoca etiketin soru işaretiyle başlamasını, etiketlerin rakamla değil bir karakterle başlaması gerektiğiyle açıkladı.

> **Ek bilgi (derste anlatılmadı):** MASM'de etiket adı rakamla başlayamaz; harf dışında `?`, `@`, `_` ve `$` karakterleri de etiketin ilk karakteri olabilir. `LOCAL` ile üretilen `??nnnn` adları bu kuralı sağlar ve programcının yazacağı etiketlerle çakışma olasılığı düşüktür.

DEBUG'da program, makro gövdesi ana yordama elle yazılmış gibi hiçbir dallanma olmadan yürüdü: ilk çağrıda döngüde üç kez, ikincide iki kez dönüldü ve sonuçlar yazıldı. Bu, bölüm 3'teki tek dosyalı çözümle aynı yürütmedir.

### 5.3 Üç parametreli makro

Hoca son olarak makroya üçüncü bir parametre, sonucun yazılacağı yeri ekledi (ekrandan, 00:50:00):

```text
USTALM  MACRO M_US, M_TABAN, M_SONUC
        LOCAL L1
        MOV AX, 1
        MOV CX, M_US
        MOV BX, M_TABAN
L1:
        MUL BX
        LOOP L1
        LEA SI, M_SONUC
        MOV [SI], AX
        MOV [SI+2], DX
        ENDM
```

Makro artık "ilk parametredeki üs kadar tabanın kuvvetini hesaplar, sonucu üçüncü parametredeki double word'e yazar" diye tanımlanır. Ana yordam iki satıra iner: `USTALM US1, TABAN1, SONUC1` ve `USTALM US2, TABAN2, SONUC2`. İlk denemede ikinci çağrıya üçüncü parametre eklenmeyi unutulmuştu; düzeltilip yeniden derlendi. LST'de iki çağrının da aynı biçimde açıldığı, DEBUG'da 8 ve 9 sonuçlarının yazıldığı görüldü.

### 5.4 Ne zaman hangisi?

Modüler kod geliştirmede iki seçenek vardır: yordam ve makro. Makroya da parametre aktarılır, ama bu parametreler etiket biçimindedir; veri kesiminde tanımlı değerler verilebilir. Yordamlara farklı parametre aktarım yöntemleri vardır; derste şimdiye kadar yalnız yazmaç üzerinden aktarım görülmüştü.

Modüler geliştirme kodun sürekliliğini sağlar ve bakımı kolaylaştırır. Belirli bir işe odaklanmış, girdisi çıktısı belli bir fonksiyonda hata ya da özel bir durum çıktığında düzeltmek daha pratiktir.

Seçim için hoca şu ölçütü verdi:

- İşlem çok basit ve kısa sürüyorsa, yordam çağırma ve dönüş yükünden kurtulmak için makro daha faydalı olabilir.
- Daha uzun, karmaşık ve ayrı bir mantıkla işlenmesi gereken kod parçalarında CALL ve RET'in kapladığı süre ve yer, fonksiyon gövdesine göre görece küçük kalır; bu durumda yordam daha anlamlıdır.

Temel fark şudur: yordamda akış kırılır, arka planda yığına değerler atılıp dallanılır. Makroda kod her çağrıldığı yere kopyalanır ve her çağrıda kod boyutu büyür.

## 6. Yordam ve Makro Karşılaştırma Tablosu

Aradan sonra hoca, sohbet ekranından paylaştığı bir PDF üzerinden yordam ve makroyu karşılaştırdı (ekrandan, 01:15:00).

- **Çalışma şekli:** Yordam `CALL` ile çağrıldığında devreye girer; derleme sırasında değil, çalışma sırasında (run time) etkindir. Makro kopyalanıp ana programa konulduğu ve orada derlendiği için derleme sırasında devreye girer.
- **Çalışma süresi:** Ana mantık aynı olsa bile yordamda CALL ve RET'ten gelen ek işler vardır. NEAR yordamda IP yığına atılır ve dönüşte RET ile çekilir. FAR yordamda hem CS hem IP atılır, `RETF` ile ikisi de çekilir. Makroda çağırma ve dönüş yükü yoktur; bu yüzden aynı işi yapan makro yordamdan daha hızlı çalışır.
- **Kod büyüklüğü:** Yordam her çağrıldığında yalnız ilgili koda dallanılır, kod büyümez. Makro her çağrıldığında kodu makro kadar büyütür.
- **Parametre aktarımı:** Yordamlara yazmaçlar, yığın ve ortak veri kesimleri üzerinden parametre aktarılabilir. Makrolar, adlarından sonra virgülle ayrılmış bir parametre listesi kabul eder.

## 7. DOS Kesmeleri ve Kesmeleri Makroya Çevirmek

### 7.1 Kesme nedir (kısaca)

Kesme konusu henüz işlenmemişti, ama hoca kesmelerin bir fonksiyon gibi çağrılabildiğini anlattı. Bunun için `INT` kelimesi vardır; `INT` ardından bir kesme numarası verilince o kesme çalıştırılır. Kesme numaralarının bir kısmı kullanıcıya, bir kısmı BIOS'a, bir kısmı işletim sistemine (DOS) ayrılmıştır. Kesmeyi çağırırken parametre de aktarılabilir; hangi fonksiyonun çalışacağı genellikle AH ile seçilir.

<!-- BELİRSİZ: Hoca BIOS kesmeleri listesinde "00" parametresiyle video moduyla ilgili bir ayar yapıldığını söyledi; kesme numarası altyazıda "int 0,0 / x86" diye bozuk geçiyor ve o anın karesi yok. -->

> **Ek bilgi (derste anlatılmadı):** Video modu ayarı BIOS'un video kesmesi INT 10H'ın AH=00H fonksiyonudur. Hocanın gösterdiği satır büyük olasılıkla budur.

Kesme bir fonksiyon çağrısından farklı olarak yığına bayrak değerlerini de atar. Bu yüzden kesme yordamından farklı bir dönüş komutuyla, `IRET` (interrupt return) ile dönülür. Kesme çağırmak için `CALL` gibi `INT` kullanılır.

### 7.2 INT 21H fonksiyonları

Hoca DOS kesme listesini kitabın ekinden (80x86 Assembly Dili, "DOS Kesme Listesi") gösterdi (ekrandan, 01:30:00). Derste kullanılan INT 21H fonksiyonları:

- **AH = 09H:** DX'te bir ASCII karakter dizisinin başlangıç adresi verilir; o adresten itibaren sonlandırma karakteri (`$`) görülene kadar karakterler ekrana yazılır.
- **AH = 0AH:** Klavyeden (komut satırından) girdi okur.
- **AH = 01H:** Standart girdiden bir karakter okur ve ekrana yansıtır (read character from standard input with echo). Okunan değer AL'de döner.
- **AH = 02H:** Standart çıktıya bir karakter yazar. Yazılan karakter DL'den alınır.

### 7.3 COM programında metin yazdırma ve karakter okuma

Önce bir COM tipi programda AH = 09H ile metin yazdırma örneği gösterildi. Veri tanımı `MSG DB 'DENEME', '$'` idi (ekrandan, 01:25:00). Program derlenip linklendi; COM tipi program olduğu için linker uyarı verdi ve program COM'a çevrildi.

Sonra `read.asm` hazırlandı (ekrandan, 01:30:00):

```text
        PAGE 60,80
        TITLE ornek
CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG

BASLA   PROC NEAR
        CALL READ
        RET
BASLA   ENDP
READ    PROC NEAR
        MOV AH, 01H
        INT 21H
        ...
```

<!-- BELİRSİZ: READ yordamının son satırları ve WRITE yordamının içeriği karede görünmüyor; ilk derlemede çıkan hata altyazıda "I useh not converted" diye bozuk geçiyor ve hoca bir satırın yukarı alınması gerektiğini söyleyerek düzeltti. -->

DEBUG'da AH'ye 01H atanıp INT 21H çağrıldığında program klavyeden bir karakter beklediği için orada durdu; karakter girilince AL'ye yazıldı. Böylece COM programında iki ayrı işlev kullanılabildi: biri ekrana metin yazan, biri komut satırından karakter okuyan.

### 7.4 Kesmeleri makroya çevirmek

Ardından `rw.asm` dosyasında okuma ve yazma işleri birer makro olarak tanımlandı (ekrandan, 01:35:00):

```text
        TITLE ornek
READCM  MACRO
        MOV AH, 01H
        INT 21H
        ENDM

WRITECM MACRO
        MOV AH, 02H
        INT 21H
        ENDM

CODESG  SEGMENT PARA 'CODE'
        ORG 100H
        ASSUME CS:CODESG, SS:CODESG, DS:CODESG, ES:CODESG

BASLA   PROC NEAR
        READCM
        MOV DL, AL
        WRITECM
        RET
        ...
```

Hoca önce AH = 02H'nin AL'deki değeri yazdığını düşündü. Kesme listesine bakınca fonksiyonun DL'deki karakteri yazdığını gördü ve araya `MOV DL, AL` ekledi; kod açıklamalarına da "INT 21H 02H fonksiyonu DL'deki değeri yazdırır" ve "INT 21H 01H fonksiyonu AL'ye değer okur" notlarını yazdı. Hoca bu fonksiyonların ayrıntısını ezbere bilmediğini, deneyerek bulduklarını söyledi.

Çalıştırıldığında basılan karakter iki kez görünür: ilki okuma makrosunun yansıtmasıdır (AH = 01H okunan karakteri ekrana da basar), ikincisi yazma makrosunun çıktısıdır. Hoca listede yansıtmasız bir sürüm olup olmadığına baktı ve "without echo" diye geçen bir fonksiyon gösterdi.

> **Ek bilgi (derste anlatılmadı):** INT 21H'da yansıtmasız karakter okuma fonksiyonları AH = 07H ve AH = 08H'dir. Hocanın listede gösterdiği fonksiyon büyük olasılıkla bunlardan biridir.

COM programlarında dikkat edilecek nokta ana yordamın `ORG 100H`'den sonra başlamasıdır. Komut satırına yazma ve okuma, dosyaya ya da yazıcıya yazdırma gibi işler işletim sistemi tarafından kontrol edildiği için bu DOS kesmeleri üzerinden yapılır. Hoca fonksiyonların parametreleri için DOS kesme listesine (internette "DOS kesme listesi" diye aranabilir) bakılmasını ve bir kaynak sayfasını paylaşacağını söyledi.

Bu örnekte iki şey görülmüş oldu: COM programında makro tanımlama ve DOS kesmelerini makroya çevirerek komut satırından karakter okuyan ve komut satırına karakter yazan kodlar üretme. Bu kullanım COM programına özgü değildir; EXE programında da aynı kesme çağrıları yapılabilir. Hoca ödevlerde komut satırından parametre okumanın isteneceğini, bu durumda DOS kesmelerini makroya çevirmenin faydalı olacağını belirtti.

## 8. Yordamlara Parametre Aktarım Yolları

Yordamlara parametre aktarmanın üç yolu vardır:

- Yazmaç üzerinden aktarım.
- Yığın üzerinden aktarım.
- Ortak veri kesimi üzerinden aktarım (EXTRN/PUBLIC tanımlarıyla).

Yazmaç üzerinden aktarım son iki haftanın örneklerinde, özellikle EBOB örneğinde görüldü. Hoca, az önceki kesme örneklerinin de yazmaç üzerinden parametre aktarımı sayılabileceğini belirtti: yazmaçlara değer ayarlanır, sonra kesme fonksiyonu çağrılır.

Yazmaç üzerinden EBOB örneği şöyleydi: fonksiyon AX ve DX'te parametre kabul eder, sonucu döngüyle ya da özyinelemeyle hesaplar ve AX'te döndürür (ekrandan, 02:05:00). Ana programda ilgili yazmaçlara değerler konur, fonksiyon çağrılır ve dönen sonuç yazmaçtan alınır. Bu, standart bir yazmaç üzerinden aktarım ve yazmaç üzerinden değer döndürme örneğidir.

## 9. Yığın Üzerinden Parametre Aktarımı: Varyasyonlar

Fonksiyonu bir kara kutu, yanında da yığını düşünelim. Fonksiyon çağrılmadan önce yığına bazı değerler atılır, sonra fonksiyon çağrılır ve fonksiyon bir değer döndürür. Burada farklı durumlar oluşur:

- **Girdi yığından, çıktı yazmaçtan:** Dönüşte yığında fazladan değer kalır. Bu değeri kimin çekeceği tanımlanmalıdır; alt yordam da ana yordam da olabilir.
- **Bir parametre yığından, dönüş yığından:** Dönüş değeri yığında olduğu için onu çekmek mutlaka ana yordamın işidir. Değerin ana yordama kadar ulaşması, ana yordamın onu okuyup yığını temizlemesi gerekir.
- **İki parametre yığından, bir dönüş yığından:** Dönüş değerini okumak ve yığından kaldırmak ana yordamın görevidir. Fazla kalan ikinci parametreyi kaldırmak ise alt yordamın ya da ana yordamın görevi olabilir.

Yazmaçla aktarımda böyle bir sorun yoktur: bir ya da iki parametre yazmaçtan aktarılıp bir değer yazmaçtan döndürülebilir.

Temizlemenin neden gerektiği şöyle açıklandı. Ana yordamda yığının en altında işletim sistemine dönüş değerleri durur. Fonksiyon çağrılmadan önce A ve B yığına atılır, FAR CALL ile ana yordamın CS ve IP'si de atılır. Alt yordam `RETF` ile dönünce yığının en üstündeki IP ve CS çekilir. Ana yordama dönüldüğünde yığının üstünde A ve B kalmıştır. Bunlar kaldırılmadan ana yordam `RETF` yaparsa, işletim sistemine dönerken bu iki word'ü IP ve CS'ye yüklemeye çalışır. Temizlemekten kastedilen budur: A ve B kaldırıldıktan sonra `RETF` doğru dönüş değerlerini bulur.

## 10. Örnek: Yığından İki Parametreyle EBOB

İlk durum: iki parametre yığın üzerinden aktarılır, dönüş değeri yazmaçta (AX) verilir. EXE programında dışarıdan FAR bir fonksiyon kullanılır; fonksiyon başka bir dosyada `PUBLIC` olarak tanımlıdır.

### 10.1 Ana yordam

Ana dosya (ekrandan, 02:20:00 ve 02:25:00):

```text
        PAGE 60,80
        TITLE ornek
EXTRN _GCD_PROC:FAR

STACKSG SEGMENT PARA STACK 'STACK'
        DW 32 DUP(?)
STACKSG ENDS

DATASG  SEGMENT PARA 'DATA'
ASAYISI DW 12
BSAYISI DW 8
SONUC   DW ?
DATASG  ENDS

CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG
BASLA   PROC FAR
        PUSH DS
        XOR AX, AX
        PUSH AX
        MOV AX, DATASG
        MOV DS, AX

        PUSH ASAYISI
        PUSH BSAYISI
        CALL _GCD_PROC
        MOV SONUC, AX
        POP AX
        POP AX
        RETF
BASLA   ENDP
CODESG  ENDS
        END BASLA
```

Dönüş değeri AX'tedir. Yığına atılan iki parametreyi bu sürümde ana yordam kaldırır; bunun için iki boş (dummy) `POP AX` yapılır.

### 10.2 Yığının durumu ve BP referansı

Ana yordam A'yı, sonra B'yi yığına atar ve FAR yordamı çağırır. Yığın, alttan üste doğru şöyledir: OS CS, OS IP, A, B, ana CS, ana IP.

Alt yordam ve ana yordam aynı yığını kullanır, çünkü SS ikisinde de aynıdır. Alt yordamdayken işletim sisteminden ya da donanımdan bir kesme gelebilir; böyle bir durumda SP otomatik olarak değişir. Ayrıca alt yordam kendi içinde PUSH ve POP yaptıkça SP değişir. Yani SP, aktarılan parametreler için global bir referans değildir. Bu yüzden alt yordama girer girmez SP'nin değeri BP'ye kopyalanır. SS ile birlikte ofset olarak kullanılabilen iki yazmaç SP ve BP'dir; BP tam olarak bu amaca, yığında sabit bir referans oluşturmaya uygundur.

BP'yi bozmak da bir sorundur, çünkü başka programlar da BP'yi kullanıyor olabilir. Bu yüzden alt yordama girer girmez önce `PUSH BP` yapılır.

> **Hocanın vurgusu:** Bundan sonraki temel kural şudur: alt yordamda parametre aktarımı ve dönüş için kullanılmayan, genel ya da geçici işler için değeri bozulan her yazmaç girişte PUSH edilir ve dönüşten önce orijinal değeri geri yüklenir. Her PUSH'a karşılık RET'ten önce bir POP olmalı ve POP'lar ters sırada yapılmalıdır. Örneğin `PUSH BP` ardından `PUSH AX` yapıldıysa, önce AX sonra BP çekilir. Hoca bu konunun çok önemli olduğunu birkaç kez tekrarladı.

`PUSH BP` ve `MOV BP, SP` sonrası SP ve BP aynı gözü, eski BP'nin bulunduğu gözü gösterir. Bu yazmaçlar sıradaki dolu gözü gösterir. Yığına ilk atılan değer en yüksek adrestedir; yığına değer atıldıkça adres küçülür. Artık araya ne kadar kesme girerse girsin BP bu referansı göstermeye devam eder.

B, BP'den üç göz ötededir (ana IP, ana CS, B), ama her göz 2 byte olduğu için 6 adres ötededir: B `[BP+6]`'da, A `[BP+8]`'dedir (ekrandan, 02:05:00).

### 10.3 Alt yordam

Önceki (yazmaçlı) fonksiyon içeride AX, BX ve DX'i kullanıyor ve sonucu AX'te döndürüyordu. Dönüş AX'ten yapılacağı için kullanıcıya "AX'te parametre bulundurmayın, dönüşte AX bozulacak" denir. BX ve DX ise geçici olarak kullanıldığı için içerikleri korunmalıdır. Alt dosya (ekrandan, 02:10:00 ve 02:25:00):

```text
PUBLIC _GCD_PROC
CDESG   SEGMENT PARA 'CODE'
        ASSUME CS:CDESG

_GCD_PROC PROC FAR
        PUSH BP
        MOV BP, SP
        PUSH BX
        PUSH DX
        MOV BX, [BP+6]
        MOV AX, [BP+8]
        CMP AX, BX
        JAE TEKRAR
        XCHG AX, BX
TEKRAR: CMP BX, 0
        JA L1
        JMP EXIT
L1:     XOR DX, DX
        DIV BX
        MOV AX, BX
        MOV BX, DX
        JMP TEKRAR
EXIT:
        POP DX
        POP BX
        POP BP
        RETF
_GCD_PROC ENDP
CDESG   ENDS
        END
```

`PUSH BX` ve `PUSH DX` sonrası SP iki göz daha ilerler; bu yüzden parametreler SP'ye göre değil, girişte kurulan BP referansına göre okunur.

`MOV BX, [BP+6]` komutunda köşeli parantez içinde BP kullanıldığı için varsayılan segment DS değil SS'dir. İçeride BX, SI ya da DI olsaydı varsayılan segment DS olurdu. Komut SS'nin BP+6 ofsetindeki değeri, yani B'yi BX'e alır. `MOV AX, [BP+8]` ise A'yı AX'e alır.

> **Ders sonrası not:** Kodun üstündeki açıklama satırı `; AX<-[SS:(BP+6)]` olarak duruyor (ekrandan, 02:10:00), ama komut `MOV BX, [BP+6]`'dır. Hoca anlatırken de önce "AX'e atamış oluyoruz" deyip "yanlış yaptık" diye düzeltti: BP+6'daki B, BX'e alınır.

Sonrası geçen haftaki EBOB işleminin aynısıdır. A ve B karşılaştırılır; A küçükse `XCHG` ile yerleri değiştirilir, böylece AX'te hep büyük sayı olur. Sonra sonlanma koşulu denetlenir: işaretsiz A ve B için B = 0 ise $\gcd(A, 0) = A$'dır ve doğrudan EXIT'e gidilir; sonuç zaten AX'tedir. B sıfır değilse $\gcd(A, B) = \gcd(B, A \bmod B)$ hesaplanır: DX sıfırlanır, DX:AX BX'e bölünür, kalan DX'te oluşur, AX'e BX, BX'e DX atanır ve döngüye dönülür. EXIT'te geçici yazmaçlar DX, BX, BP sırasıyla geri çekilir ve `RETF` ile dönülür.

### 10.4 Dönüşte yapılan hata ve düzeltmesi

İlk yazılan ana yordamda CALL'dan sonra önce iki `POP AX`, sonra `MOV SONUC, AX` vardı (ekrandan, 02:10:00). Hoca DEBUG'da izlerken bunun hatalı olduğunu fark etti: AX'te dönüş değeri vardır ve boş okumalar AX'e yapılırsa dönüş değeri bozulur. `MOV SONUC, AX` satırı POP'ların üstüne alındı (ekrandan, 02:25:00).

### 10.5 DEBUG ile izleme

Program derlendi, iki OBJ birlikte linklendi, EXE'nin adı `ana` verildi ve DEBUG'da izlendi.

- İşletim sistemine dönüş değerleri atıldıktan sonra SP = 3CH'dir. Yığında OS CS = 075AH ve OS IP = 0000H görüldü.
- `PUSH ASAYISI` aslında `PUSH [0000]` olarak görünür: veri kesiminin 0 ofsetindeki word yığına atılır. PUSH yazmaç da bellek adresi de alabilir. SP = 3AH olur ve orada 12 (000CH) görülür.
- `PUSH BSAYISI` (`PUSH [0002]`) sonrası SP = 38H; yığında 12 ve 8 vardır.
- `CALL _GCD_PROC` dosyada bulunmayan, EXTRN tanımlı bir yordamı çağırır. Adresi linkleme aşamasında iki OBJ birlikte verilince bulunmuştu.
- Alt yordamda `PUSH BP` sonrası SP = 32H olur ve `MOV BP, SP` ile BP = 32H sabit referansı kurulur. `PUSH BX` ve `PUSH DX` sonrası SP = 2EH olur.

Bu an yığının en dolu olduğu andır. SS:2E'den itibaren döküm (ekrandan, 02:20:00):

```text
076F:0020                                            00 00
076F:0030  00 00 00 00 16 00 6D 07-08 00 0C 00 00 00 5A 07
```

Word word okunduğunda:

```text
Adres   Değer   Anlamı
2E      0000    DX (korunan)
30      0000    BX (korunan)
32      0000    BP (korunan)        <- BP
34      0016    ana yordama dönüş IP
36      076D    ana yordama dönüş CS
38      0008    B
3A      000C    A (12)
3C      0000    OS IP
3E      075A    OS CS
```

Değerler little endian olduğu için byte'lar ters okunur (örneğin `0C 00` = 000CH = 12). Tek bir fonksiyon kullanıldığı için BP'nin orijinal değeri 0'dı, ama başka bir değer de olabilirdi. Yordam özyinelemeli olsaydı, yığının en dolu olduğu an özyineleme zincirinin en uç noktası olurdu; burada iç içe değil döngüyle hesaplandığı için en dolu an burasıdır.

Hesaplama adımları:

- BX = 0008H (B), AX = 000CH (A). A büyük olduğu için takas yok.
- 1. tur: B ≠ 0. DX = 0, $12 \div 8$: bölüm 1, kalan 4. AX = 8, BX = 4.
- 2. tur: B ≠ 0. $8 \div 4$: kalan 0. AX = 4, BX = 0.
- 3. tur: B = 0, EXIT'e gidilir. Sonuç AX = 4.

Yani $\gcd(12, 8) = \gcd(8, 4) = \gcd(4, 0) = 4$.

EXIT'te DX, BX ve BP orijinal değerleriyle (hepsi 0) geri yüklendi. `RETF` öncesi SP = 34H'tür ve yığının üstünde ana yordama dönüş ofseti ve segmenti vardır. `RETF` sonrası SP = 38H olur; yığının üstünde artık aktarılan B ve A durur. Bunların yığında kalması işletim sistemine dönüşü bozacağı için kaldırılmalıdır. Önce `MOV SONUC, AX` ile sonuç veri kesimine yazıldı (veri kesiminde A, B ve 4 görüldü), sonra iki boş POP yapıldı. SP = 3CH'ye döndü, yığının üstünde OS ofseti ve segmenti vardı ve `RETF` ile işletim sistemine dönüldü.

Bu örnek, yığından iki word aktarılıp yazmaçtan bir değer döndürüldüğü ve parametrelerin ana yordam tarafından kaldırıldığı durumdur.

### 10.6 Parametreleri alt yordama kaldırtmak: RETF 4

Aynı örnekte yığından parametre kaldırma görevi alt yordama verildi. Ana yordama dönüldüğünde yığında çöp kalmamalıdır. Bunun için `RETF` (ya da `RET`) komutundan sonra bir çift sayı yazılır. Bu sayı, dönüşte SP'yi o kadar daha artırır. Alt yordamın sonu `RETF 4` olur (ekrandan, 02:25:00); ana yordamdaki iki boş POP kaldırılır.

`RETF 4` şunu yapar: yığının en üstündeki değeri IP'ye, sonrakini CS'ye yükler, sonra B ve A'yı çekmeden SP'yi 4 artırır. SP doğrudan OS IP'nin bulunduğu göze gelir. B ve A yığında kalır ama çöp olur; SP artırılarak boş geçilmiş, boş okunmuş olurlar.

DEBUG'da `RETF 4` öncesi SS:34'ten itibaren ana IP, ana CS, B ve A görüldü. `RETF 4` sonrası SP = 3CH oldu ve yığının üstünde OS ofseti ve segmenti vardı. Hoca SS:38'e baktığında B ve A'nın bulunduğu gözlerin değerlerinin de değişmiş olduğunu gösterdi; bu değerler orijinal hâlinde de kalabilirdi.

> **Ek bilgi (derste anlatılmadı):** SP'nin altında kalan gözler artık boş kabul edilir ve sonraki herhangi bir yığın işlemi bunların üzerine yazabilir. DEBUG'da `t` ile adım adım yürütme, işlemcinin tek adım kesmesini kullandığı için her adımda bayrakları, CS'yi ve IP'yi SP'nin altına yazar. Gözlerin değişmesinin nedeni büyük olasılıkla budur.

Bu, iki parametrenin yığından aktarıldığı, dönüşün yazmaçla yapıldığı ve çöp değerleri kaldırma görevinin alt yordama verildiği örnektir.

## 11. Dönüş Değerini Yığından Vermek

### 11.1 Kısıt

Dönüş değeri de yığın üzerinden verilebilir. Bunun için yığının belirli bir gözüne değer yazmak gerekir. Birden fazla değer de döndürülebilir, ama bir kısıt vardır: yığına kaç parametre atılarak alt yordama gidildiyse en fazla o kadar değer yığından döndürülebilir. Yığına iki word atıldıysa en fazla iki word dönebilir, üç word dönemez.

### 11.2 Sonucu hangi göze yazmalı?

Yığından iki parametre aktarılıp bir word döndürülecekse, parametreleri çekme görevi ana yordamdaysa, dönüş değeri B'nin gözüne de A'nın gözüne de yazılabilir.

- Sonuç B'nin gözüne yazılırsa, ana yordam dönüşte ilk `POP AX` ile sonucu alır, `MOV SONUC, AX` yapar, sonra ikinci `POP AX` ile A'yı boş okur.
- Sonuç A'nın gözüne yazılırsa, ilk `POP AX` B'yi boş okur, ikinci `POP AX` sonucu alır, ardından `MOV SONUC, AX` gelir.

Derste ikinci seçenek seçildi: dönüş değeri A'nın gözüne yazılır. Hoca, alt yordamın dönüş biçimine baştan karar verilip ona göre ilerlenmesi gerektiğini belirtti.

### 11.3 Alt yordamın yeni hâli

Dönüş değeri artık yığından verildiği için AX de alt yordamda geçici olarak kullanılan ve bozulan bir yazmaç olur. Bu yüzden girişte `PUSH AX`, çıkışta `POP AX` eklenir (ekrandan, 02:40:00):

```text
_GCD_PROC PROC FAR
        PUSH BP
        MOV BP, SP
        PUSH AX
        PUSH BX
        PUSH DX
        MOV BX, [BP+6]
        MOV AX, [BP+8]
        ...                 ; EBOB gövdesi aynı
EXIT:
        MOV [BP+8], AX
        POP DX
        POP BX
        POP AX
        POP BP
        RETF
_GCD_PROC ENDP
```

Hoca yığını baştan çizdi ve her adımda yığın çizilmesini tavsiye etti. Alttan üste: OS CS, OS IP (0000), A, B, ana CS, ana IP, BP, AX, BX, DX. Yığının ilk kullanılan gözü yüksek adreslidir, son PUSH'lanan değerler düşük adreslidir; bu gözden kaçırılmamalıdır. `PUSH BP` sonrası SP'nin gösterdiği göz BP'ye kopyalandığı için BP referansı orası olur; SP ise sonraki PUSH'larla ilerler. PUSH ve POP SP'nin gösterdiği adrese göre otomatik çalışır, ama BP elle sabitlendiği için parametrelerin yeri bu referansa göre hesaplanır. Parametreler yine `[BP+6]` (B) ve `[BP+8]` (A) adreslerindedir.

Hoca, `MOV BP, SP` satırı PUSH'lardan sonraya taşınsaydı parametrelere daha uzak ofsetlerden erişileceğini, bu yüzden girer girmez `PUSH BP` / `MOV BP, SP` yapmanın hesabı kolaylaştırdığını söyledi.

> **Ders sonrası not:** Hoca bu durumda A ve B'ye "2, 4, ... 14 ve 16 ofset öteden" erişileceğini söyledi. `PUSH BP`, `PUSH AX`, `PUSH BX`, `PUSH DX` sonrası `MOV BP, SP` yapılırsa BX +2, AX +4, eski BP +6, ana IP +8, ana CS +10 ötededir; doğrusu B için `[BP+12]`, A için `[BP+14]`'tür.

EXIT'te AX'teki sonuç A'nın gözüne, `[BP+8]`'e yazılır. Hoca, örnekte AX'teki değerin yığına yazılıp ana yordamda yine AX'e okunmasının genel durum için olduğunu, sonucun aynı yazmaçtan okunmak zorunda olmadığını belirtti.

Ana yordam:

```text
        CALL _GCD_PROC
        POP AX              ; B, boş okuma
        POP AX              ; dönüş değeri
        MOV SONUC, AX
```

### 11.4 DEBUG ile izleme

Hesaplama yine $\gcd(12, 8) = \gcd(8, 4) = \gcd(4, 0) = 4$ adımlarıyla yapıldı ve AX = 4 oldu. Sonuç yığına yazılmadan önce SS:2C'den itibaren bakıldığında yığın şöyleydi: en üstte DX, sonra BX, AX, BP, ana yordama dönüş ofseti, ana yordama dönüş segmenti, B ve A. `MOV [BP+8], AX` sonrası A'nın yerinde dönüş değeri görüldü. DX, BX, AX ve BP çekildi; `RETF` öncesi SS:34'ten itibaren ana yordama dönüş değerleri, B, dönüş değeri ve işletim sistemine dönüş değerleri vardı. `RETF` sonrası SS:38'de B ve dönüş değeri kaldı. İlk POP ile B boş okundu, ikinci POP ile dönüş değeri AX'e alındı ve SONUC'a yazıldı. Veri kesiminde A, B ve 4 görüldü, ardından işletim sistemine dönüldü.

Bu örnekte dönüşün bütün yükü ana yordamdaydı: işlemden sonra çöp hâline gelen B'yi yığından kaldırmak da ana yordamın göreviydi.

### 11.5 RETF 2 ile boş okumadan kurtulmak

Bu boş okumadan kurtulmak mümkündür. Alt yordam `RETF 2` ile dönerse (ekrandan, 02:45:00), IP ve CS çekildikten sonra SP 2 artırılır; SP B'nin gözünü atlar ve doğrudan dönüş değerinin bulunduğu gözü gösterir. Ana yordamda ilk `POP AX` kaldırılır:

```text
        CALL _GCD_PROC
        POP AX              ; dönüş değeri
        MOV SONUC, AX
```

DEBUG'da `RETF 2` satırındayken SS:34'ten itibaren ana IP, ana CS, B ve dönüş değeri görüldü. Komut IP'yi ve CS'yi çekti, SP'yi 2 artırdı. Ana yordama dönüldüğünde SS:3A'da yığının en üstünde dönüş değeri vardı; POP ile alınıp SONUC'a yazıldı, veri kesiminde A, B ve 4 görüldü ve işletim sistemine başarıyla dönüldü.

### 11.6 Önerilen kalıp ve özet

> **Hocanın vurgusu:** Anlatılan yöntemlerin hepsi geçerlidir, ama uygun bir pratik şudur: dönüş değerleri, yığından aktarılan parametreler arasında en yüksek adresli olandan başlayarak yerleştirilsin. Aradaki düşük adresli çöp değerler, `RETF` ya da `RET`'in yanına yazılan çift sayıyla, POP yapmadan SP artırılarak geçilir. Ana yordamın fazladan POP yapması gerekmez. Hoca bunu bir şablon uygulama olarak benimsemeyi önerdi.

Yığın üzerinden parametre aktarımında görülen bütün seçenekler:

- Yığından bir ya da iki parametre aktarılıp yazmaçtan değer döndürülür. Parametreleri ana yordam kaldırabilir (iki boş POP ya da SP'yi 4 artırmak) veya alt yordam kaldırabilir (`RETF` yanına çöp parametre sayısı × 2).
- Yığından parametre aktarılıp yığından değer döndürülür. Dönüş değeri kadar okumayı ana yordam yapmak zorundadır. Dönüş değerleri yüksek adresten başlayarak yazılmışsa, kalan boş değerler alt yordamda `RETF` yanındaki sayıyla atılabilir.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:29:44)

Üs alma yordamında CX'te üs, BX'te taban ve AX'te 1 değeri bulunuyor. AX bir parametre midir?

**Çözüm (derste verildi):** Hayır. AX her zaman 1 ile başlar ($x^0 = 1$), yani yordamın içinde atanan bir değerdir. Girdiler CX (üs) ve BX (taban), çıktı DX:AX'tir. AX ve DX parametre değil, yordam içinde güncellenen yazmaçlardır.

### Soru 2 (ekrandan, 00:45:00)

Üs alma makrosu kullanılan programın LST dosyasında `USTALM US1, TABAN1` satırının karşısında makine kodu yoktur ve altındaki satırlarda `??0000:` ile `LOOP ??0000` görülür. Bunun nedeni nedir?

**Çözüm (derste verildi):** `USTALM` bir 8086 komutu değildir. Assembler bu satırın yerine makro gövdesini koyar; makine kodu açılan gövdedeki komutlar için üretilir. Oysa `CALL` bir 8086 komutu olduğu için yordam çağrısında satırın makine kodu vardır. `LOCAL L1` yüzünden makro gövdesindeki `L1` etiketi her açılışta benzersiz bir adla değiştirilir: birinci çağrıda `??0000`, ikinci çağrıda `??0001`.

### Soru 3 (derste sözlü, 01:12:11)

Yordam ne zaman işlenir, makro ne zaman devreye girer? Hangisi daha hızlı çalışır?

**Çözüm (derste verildi):** Yordam `CALL` ile çağrıldığında, yani çalışma sırasında (run time) devreye girer. Makro kopyalanıp ana programa konulduğu ve orada derlendiği için derleme sırasında devreye girer. Yordamda CALL ve RET yükü vardır (NEAR'da IP, FAR'da CS ve IP yığına atılıp çekilir); makroda bu yük olmadığı için aynı işi yapan makro daha hızlıdır.

### Soru 4 (ekrandan, 02:20:00)

Ana yordam `PUSH ASAYISI` (12) ve `PUSH BSAYISI` (8) ile `_GCD_PROC` FAR yordamını çağırıyor. Yordam girişte `PUSH BP` / `MOV BP, SP` / `PUSH BX` / `PUSH DX` yapıyor. Yığın 32 word'lük ve ana yordam başında `PUSH DS` / `XOR AX, AX` / `PUSH AX` var. Yığının en dolu olduğu andaki içeriği ve SP değerini yazınız.

**Çözüm (derste verildi):** SP = 2EH. SS:2E'den yüksek adrese doğru: DX (0000), BX (0000), eski BP (0000, BP = 32H), ana IP (0016H), ana CS (076DH), B (0008H), A (000CH), OS IP (0000H), OS CS (075AH). DEBUG dökümünde `00 00 00 00 00 00 16 00 6D 07 08 00 0C 00 00 00 5A 07` olarak görüldü.

### Soru 5 (derste sözlü, 02:12:31)

Dönüş değeri AX'te olan ve iki parametresi yığından aktarılan bir yordam çağrısından sonra ana yordam `POP AX` / `POP AX` / `MOV SONUC, AX` yazıyor. Hata nedir?

**Çözüm (derste verildi):** Boş okumalar AX'e yapıldığı için AX'teki dönüş değeri bozulur ve SONUC'a yığındaki A değeri yazılır. `MOV SONUC, AX` satırı POP'lardan önce yazılmalıdır.

### Soru 6 (derste sözlü, 02:31:00)

Yığından iki parametre (önce A, sonra B) aktarılıyor ve bir word değer yığından döndürülecek. Sonuç hangi göze yazılmalı, ana yordam ne yapmalıdır?

**Çözüm (derste verildi):** Parametreleri ana yordam kaldırıyorsa iki göz de kullanılabilir. B'nin gözüne yazılırsa ilk POP sonucu, ikinci POP A'yı (boş) okur. A'nın gözüne (`[BP+8]`) yazılırsa ilk POP B'yi boş okur, ikinci POP sonucu alır. Önerilen kalıpta sonuç yüksek adresli göze, yani A'nın gözüne yazılır ve alt yordam `RETF 2` ile döner. Böylece B'nin gözü atlanır; ana yordam yalnız `POP AX` / `MOV SONUC, AX` yapar.

## Dersin Toparlaması

Bu derste modüler kod geliştirmenin iki aracı, yordam ve makro, aynı üs alma örneği üzerinden karşılaştırıldı. Yordam çalışma sırasında devreye girer, kodu büyütmez ama CALL/RET yükü taşır. Makro derleme sırasında her çağrıldığı yere açılır, kodu büyütür ama çağrı yükü yoktur; etiket içeriyorsa `LOCAL` kullanılmalıdır. Ardından DOS kesmeleri (INT 21H'nin 01H, 02H, 09H ve 0AH fonksiyonları) tanıtıldı ve COM programında karakter okuma ve yazma işleri makrolara çevrildi.

Dersin ikinci yarısında yordamlara yığın üzerinden parametre aktarımı işlendi. Alt yordama girer girmez `PUSH BP` / `MOV BP, SP` ile sabit bir referans kurmak, geçici yazmaçları korumak, parametrelere `[BP+6]` ve `[BP+8]` ile erişmek ve yığını temizleme sorumluluğunu ana yordama ya da alt yordama (`RETF n`) vermek EBOB örneğinde adım adım gösterildi. Dönüş değerinin yığından verilmesi için de en yüksek adresli göze yazma ve `RETF n` ile kalan gözleri atlama kalıbı önerildi. Sonraki derste ortak veri kesimi üzerinden (EXTRN/PUBLIC ile) parametre paylaşımı ve kesim birleştirme ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
