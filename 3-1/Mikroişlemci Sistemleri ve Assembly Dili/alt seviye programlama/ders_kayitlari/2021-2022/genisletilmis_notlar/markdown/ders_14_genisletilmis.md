# Ders 14 Genişletilmiş Notu: Kod Kesimlerini Birleştirme, MAP Dosyası ve Yığından Parametre Alan Harici Yordamlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Haftaların Özeti ve Dersin Hedefi
- 2. Örnek 1: Word Dizide Byte Tanımlı Bir Elemanı Sayma
- 3. Byte Değeri Word'e Genişletme: İşaretsiz ve İşaretli Durum
- 4. Örnek 1'in Ana Yordamı
- 5. Örnek 1'in Harici Yordamı ve Yığın Çerçevesi
- 6. Derleme, Bağlama ve DEBUG ile Deneme
- 7. MAP Dosyası ile Kesim Yerleşimi
- 8. Kod Kesimlerini Birleştirme
- 9. Örnek 2: Her Elemanı İkili Gösterimindeki 1 Sayısına Bölme
- 10. Aynı Kesimde Yakın (NEAR) Yordam
- Örnek Sorular

## 1. Önceki Haftaların Özeti ve Dersin Hedefi

Önceki haftalarda COM tipi programlardan sonra yordamlar arasında parametre aktarma yöntemleri anlatılmıştı. Bunlardan biri `EXTRN` ve `PUBLIC` tanımlarıyla değişkenleri paylaşmaktı: farklı yordamlara gidilse bile aynı veri kesimi kullanılabiliyordu. Diğeri parametreleri yığına atıp (`PUSH`) yordam içinde yığından okumaktı.

Bu derste bunun bir adım ötesine geçilir: farklı dosyalarda, dolayısıyla farklı kod kesimlerinde yazılan yordamlar aynı kod kesimine nasıl konur? Hoca bunu iki örnek program üzerinden ve bağlayıcının (linker) ürettiği MAP uzantılı dosyayı inceleyerek anlattı. Örnekler aynı zamanda EXE tipi program yazma pratiği için seçildi.

## 2. Örnek 1: Word Dizide Byte Tanımlı Bir Elemanı Sayma

### 2.1 Soru

Slaytta verilen soru şudur (ekrandan, 00:30:00):

> Örnek1: Word tanımlı bir dizide byte tanımlı bir elemanın kaç kez geçtiğini bulan EXE tipi ASM programını yazınız. Dizinin adresini, eleman sayısını ve aranan sayıyı stack'e atan ve sonucu AX üzerinden döndüren bir harici yordam kullanınız. Kod kesimini ortak alan olarak belirleyecek ek işlemleri gerçekleştiriniz.

Deneme için 11 elemanlı bir dizi kullanıldı: altı tane 12, ardından 13, 14, 15, 16, 17. Her eleman word tanımlıdır. 12 arandığında 6, 13 arandığında 1, dizide hiç olmayan 18 arandığında 0 sonucu beklenir.

Dikkat edilmesi gereken iki nokta vurgulandı. Birincisi dizi word tanımlı, aranan sayı ise byte tanımlıdır; karşılaştırmadan önce bir genişletme gerekir. İkincisi dizinin adresi, eleman sayısı ve aranan sayı yığına atılacak, harici yordam bunları yığından alacak ve sonucu AX üzerinden döndürecektir.

### 2.2 Sayma yordamının akış diyagramı

Hoca yalnız sayma yordamının akışını çizdi; ana yordamın ne yapacağı zaten belliydi. Yordam dizinin adresini, `n`'yi ve aranan sayıyı alır:

```text
TMP = 0
for i = 0 .. n-1:
    if dizi[i] == aranan:
        TMP++
return TMP
```

Daha önceki programlama derslerinden bilinen basit bir yapıdır. Burada fark, değerlerin yığından alınması ve TMP'nin AX olmasıdır.

### 2.3 Sınavda "300 elemanlı" ifadesi

Hoca aynı soruyu sabah grubunda 300 elemanlı dizi ile çözdüğünü söyledi. Soruda 300, 500, 1000 gibi bir eleman sayısı verilmesinin amacı, sayının 255'ten büyük olduğunu, yani eleman sayısının (`n`) word tanımlanması gerektiğini ima etmektir. Sınavda dizinin değerleri bilinmiyorsa `DW 300 DUP(?)` yazılması beklenir; bellekte o an orada ne varsa o değerler kalır. Derste deneme yapılabilsin diye 11 elemanlı dizi kullanıldı, 300'lük tanım yorum satırı olarak bırakıldı.

## 3. Byte Değeri Word'e Genişletme: İşaretsiz ve İşaretli Durum

### 3.1 Neden genişletme gerekir

Yığına atılabilen değerler word tanımlı olmalıdır. `n` word olduğu için `PUSH n` yazılabilir; `aranan` byte olduğu için `PUSH aranan` yazılamaz. Bu yüzden aranan sayı önce AX'e alınır, AX yığına atılır. Bunun iki yolu vardır ve hangisinin seçileceği sayının işaretli olup olmadığına bağlıdır.

### 3.2 Sayısal örnek

Hoca bir sonraki sayfada şu örneği çizdi (ekrandan, 00:40:00). AL'de `10110011` olsun.

- İşaretsiz (pozitif) kabul edilirse basamak değerleri toplanır: $128 + 32 + 16 + 2 + 1 = 179$.
- İşaretli kabul edilirse en anlamlı bit 1 olduğu için sayı negatiftir. Mutlak değeri ikiye tümleyen (two's complement) ile bulunur: önce bire tümleyen, `01001100`; sonra 1 eklenir, `01001101` $= 64 + 8 + 4 + 1 = 77$. Sayı $-77$'dir.
- Aynı sonuca $179 - 256 = -77$ ile de ulaşılır.

Şimdi bu byte'ın başına AH olarak sekiz sıfır eklendiğini düşünelim. Sayı işaretsizse (179) hiçbir şey değişmez. Ama sayı işaretli ve $-77$ ise, 16 bitlik AX'in en anlamlı biti 0 olur ve sayı pozitif 179'a dönüşür; işaret kaybolur. İşaretli sayıyı korumak için AL'nin en anlamlı bitinin AH'nin bütün bitlerine taşınması gerekir.

### 3.3 CBW komutu

Hoca bu işi yapan komutu sordu; cevap gelmeyince kendisi verdi: `CBW` (convert byte to word). Operand almaz. AL'yi işaretine dikkat ederek AX'e genişletir: AL'nin en anlamlı biti 1 ise AH'nin bütün bitlerini 1, 0 ise 0 yapar. Böylece negatif sayının negatifliği korunur.

**Soru:** `CBW` ile BL'yi BX'e genişletebilir miyiz, örneğin `CBW BL, BX` yazarak?
**Cevap:** Hayır. Böyle bir kullanım yoktur; komut yalnız AL'yi AX'e genişletir. Hoca sınavda bu şekilde yazan öğrenciler olduğunu söyledi.

Kodda iki seçenek şöyle yazıldı (ekrandan, 00:45:00):

```asm
        XOR AX, AX          ; egerki sayi isaretsiz ise
        MOV AL, aranan
        ; MOV AL, aranan    ; egerki sayi isaretli ise
        ; CBW
        PUSH AX
```

Hoca yorum satırlarında Türkçe karakter kullanmamayı önerdi; derleme sırasında sorun çıkarabileceği için.

## 4. Örnek 1'in Ana Yordamı

Ana yordam, alışılmış EXE iskeletine parametre hazırlama ve çağrı satırlarının eklenmesiyle yazıldı. Sırayla `n` yığına atılır, `aranan` word'e çevrilip atılır, `LEA AX, dizi` ile dizinin adresi (C'deki karşılığıyla dizinin işaretçisi) alınıp atılır, `CALL SAY` ile yordam çağrılır ve AX'te dönen sonuç `MOV sonuc, AX` ile yazılır. `SAY` bu dosyada olmadığı için dosyanın başına `EXTRN SAY:FAR` yazılır.

Kod kesimleri birleştirildikten sonraki son hali (ekrandan, 01:15:00):

```asm
                EXTRN SAY:FAR
myss            SEGMENT PARA STACK 'sta'
                DW 20 DUP(?)
myss            ENDS

myds            SEGMENT PARA 'dat'
dizi            DW 12, 12, 12, 12, 12, 12, 13, 14, 15, 16, 17
;dizi           DW 300 DUP(?)
n               DW 11
aranan          DB 18
sonuc           DW ?
myds            ENDS

mycs            SEGMENT PARA PUBLIC 'code'
                ASSUME CS:mycs, DS:myds, SS:myss
MAIN            PROC FAR
                PUSH DS
                XOR AX, AX
                PUSH AX
                MOV AX, myds
                MOV DS, AX

                PUSH n
                XOR AX, AX          ; egerki sayi isaretsiz ise
                MOV AL, aranan
                ; MOV AL, aranan    ; egerki sayi isaretli ise
                ; CBW
                PUSH AX
                LEA AX, dizi
                PUSH AX
                CALL SAY
                MOV sonuc, AX

                RETF
MAIN            ENDP
mycs            ENDS
                END MAIN
```

İlk yazımda kod kesimi `mycs SEGMENT PARA 'code'` biçimindeydi, `aranan DB 12` ve `sonuc DW 11` yazılıydı (ekrandan, 00:45:00). `PUBLIC` sözcüğü ve `sonuc DW ?` sonradan eklendi; `aranan` denemelerde 12, 13 ve 18 yapıldı.

## 5. Örnek 1'in Harici Yordamı ve Yığın Çerçevesi

### 5.1 Yordam dosyası

Yordam ayrı bir dosyada yazıldı. Bu dosyada yalnız kod kesimi vardır. Yordam `PROC FAR` tanımlanır, çünkü başka bir kesimden çağrılır ve `RETF` ile döner. Ana dosyadan `EXTRN` ile kullanılabilmesi için burada `PUBLIC SAY` yazılır.

Yordamın başında `PUSH BP` ile BP saklanır, `MOV BP, SP` ile BP yığının o anki tepesine eşitlenir. Parametreler BP'ye göre bulunur. Yordamda kullanılan yazmaçlar, çağıranın değerleri bozulmasın diye yığına atılır ve sonda ters sırayla geri alınır. AX sonuç taşıdığı için saklanmaz: çağıran yordam sonucun AX'te döneceğini, yani AX'in değişeceğini zaten bilir.

Bir şeyin üzerine sayma yapılacaksa ilk değerinin sıfır olduğundan emin olunmalıdır; bu yüzden `XOR AX, AX` yazılır. Döngüde `CMP BX, [DI]` kullanılır: köşeli parantez nedeniyle DI'nin gösterdiği adresten bir word okunur ve BX ile karşılaştırılır. Eşit değilse `JNE atla` ile artırma atlanır, eşitse `INC AX` yapılır. Dizi word olduğu için DI 2 artırılır ve `LOOP L1` ile dönülür.

Son hali (ekrandan, 01:10:00):

```asm
                PUBLIC SAY
mycs            SEGMENT PARA PUBLIC 'code'
                ASSUME CS:mycs
SAY             PROC FAR

                PUSH BP
                MOV BP, SP
                PUSH CX
                PUSH DI
                PUSH BX
                MOV CX, [BP+10]
                MOV DI, [BP+6]
                MOV BX, [BP+8]

                XOR AX, AX
L1:             CMP BX, [DI]
                JNE atla
                INC AX
atla:           ADD DI, 2
                LOOP L1

                POP BX
                POP DI
                POP CX
                POP BP
                RETF 6
SAY             ENDP
mycs            ENDS
                END
```

Derste `L1` etiketi önce `XOR AX, AX` satırına yazılmıştı. Bir öğrenci bu durumda her turda AX'in sıfırlanacağını söyledi; etiket `CMP` satırına taşındı.

### 5.2 Yığın çerçevesi

Hoca yığını 0'dan 15'e numaralanmış bir şekil üzerinde doldurdu (ekrandan, 00:55:00). Alttan üste sıra şöyledir:

| Yığındaki değer | Kim attı | BP'ye göre konum |
|---|---|---|
| DS | ana yordam (`PUSH DS`) | |
| 0 | ana yordam (`PUSH AX`) | |
| n | ana yordam | `[BP+10]` |
| aranan (word) | ana yordam | `[BP+8]` |
| dizinin adresi | ana yordam | `[BP+6]` |
| dönüş CS'si | `CALL` (uzak) | `[BP+4]` |
| dönüş IP'si (ofset) | `CALL` | `[BP+2]` |
| eski BP | yordam (`PUSH BP`) | `[BP]` |
| CX, DI, BX | yordam | BP'nin altında |

Uzak (FAR) bir yordam çağrıldığında, dallanmadan önce dönülecek yerin kod kesimi değeri ve ofset değeri yığına atılır. Yordamda `PUSH BP` ve `MOV BP, SP` yapıldıktan sonra BP ile SP aynı yeri gösterir; parametrelerin yeri BP'ye göre bellidir.

**Soru:** BP kurulduktan sonra CX, DI ve BX'i yığına attık ama BP'ye eklediğimiz ofsetleri değiştirmedik. Sorun olur mu?
**Cevap:** Olmaz. `MOV BP, SP` bu üç değer atılmadan önce yapıldı. Sonraki `PUSH`'larda SP otomatik olarak değişir, ama BP yerinde kalır; BP'ye göre parametrelerin yeri değişmez. Değerler BP kurulmadan önce yığına atılsaydı (önceki hafta öyle bir örnek yapıldı) ofsetler onlara göre yeniden hesaplanmalıydı. Hoca iki tekniği de görülsün diye farklı haftalarda farklı sıralar kullandığını söyledi.

### 5.3 Yığının temizlenmesi: RETF 6

`POP` komutlarıyla yordamın kendi attığı dört değer (BX, DI, CX, BP) çekilir. `RETF` uzak yordamdan dönüldüğü için IP ve CS'yi yığından otomatik olarak çeker. Ama ana yordamın attığı üç parametre hâlâ yığındadır. Varsayılan yaklaşımda bunları harici yordam temizler; bunun için `RETF`'den sonra kaç byte temizleneceği yazılır. Yığında üç word, yani $3 \cdot 2 = 6$ byte vardır. `RETF 6` kendisi 4 byte (IP ve CS), ardından 6 byte daha çeker; toplam 10 byte.

Bir öğrenci derste chat üzerinden `POP` sırasında yazım hatası olup olmadığını sordu. Hoca ekrandaki kodda sıranın BX, DI, CX, BP olduğunu, yani atılma sırasının tersi olduğunu gösterdi. Ayrıca, yığına konup çağıran tarafından temizlenen parametrelerin herhangi bir sırayla herhangi bir yazmaca çekilebileceğini, önemli olanın yığından doğru sayıda değerin çekilmesi olduğunu söyledi.

## 6. Derleme, Bağlama ve DEBUG ile Deneme

### 6.1 Komutlar

Program DOSBox'ta derlendi. Önce `mount c c` ile sürücü bağlanır ve kaynakların bulunduğu klasöre geçilir. İki dosya ayrı ayrı `MASM` ile derlenir, `LINK` aşamasında `+` ile birlikte bağlanır:

```text
masm 231221a.asm
masm 231221b.asm
link 231221a.obj + 231221b.obj
debug 231221a.exe
```

DEBUG'da `U` (unassemble) ile kod görüntülenir. Birleştirme yapılmadan önce ana kod kesimi ile yardımcı yordamın kesim değerleri farklıdır; uzak çağrı başka bir CS değerine dallanır (altyazıda 076F ve 0772 gibi değerler okunuyor). İlk beş komut (`PUSH DS`, `XOR AX, AX`, `PUSH AX`, `MOV AX, myds`, `MOV DS, AX`) `T` ile yürütülüp DS ayarlandıktan sonra `D DS:0` ile veri kesimi görüntülenir.

### 6.2 Veri kesiminin dökümü

DEBUG'daki döküm şöyleydi (ekrandan, 01:00:00):

```text
076D:0000  0C 00 0C 00 0C 00 0C 00-0C 00 0C 00 0D 00 0E 00
076D:0010  0F 00 10 00 11 00 0B 00-0C 0B 00 ...
```

Word elemanlar little endian saklandığı için her eleman `0C 00` biçiminde görünür. Dizinin 11 elemanından sonra `n = 000B` (11), ardından byte olarak `aranan = 0C` (12), ardından `sonuc` gelir.

Burada `sonuc` alanında beklenmedik biçimde 11 (`0B 00`) görüldü. Sebep, kaynakta `sonuc DW 11` yazılmış olmasıydı; `DW ?` yapılıp yeniden derlenince alan 0 oldu. Bir öğrenci `?` ile tanımlanan alanın çöp değer içerebileceğini sordu. Hoca, normalde `?`'nin "bellekte orada ne varsa kalsın" anlamına geldiğini, ama kullandıkları DOSBox ortamında bu alanların 0 ile dolu geldiğini söyledi. Bir kez de yalnız bir dosya yeniden derlendiği için eski hal çalıştırıldı; iki dosyanın da derlenmesi gerekir.

> **Ek bilgi (derste anlatılmadı):** `DUP(?)` ve `?` ile tanımlanan alanlar EXE dosyasının içinde yer alıyorsa bağlayıcı bunları büyük olasılıkla 0 olarak yazar; bu yüzden yükleme sonrası 0 görülmesi DOSBox'a özgü olmayabilir. Kesimin sonunda kalan başlatılmamış alanlar ise dosyaya yazılmayabilir ve yükleme anındaki bellek içeriğini taşıyabilir. Programın doğruluğu bu davranışa bağlanmamalı, sayaçlar açıkça sıfırlanmalıdır.

### 6.3 Sonuçlar

`G` ile program sonuna kadar çalıştırılıp `D DS:0` ile bakıldığında:

- `aranan = 12` için sonuç 6 çıktı; dizide gerçekten altı tane 12 vardır.
- `aranan = 13` için (dökümde `0D`) sonuç 1 çıktı.
- `aranan = 18` için (dökümde $12_h$; $16 + 2 = 18$) sonuç 0 çıktı.

Hoca ayrıca `T` ile adım adım ilerleyip yığına önce `n`'in (değeri `B`) atıldığını, sonra AX sıfırlanıp AL'ye 12 konduğunu ve atıldığını, sonra `LEA` ile dizinin adresinin alınıp atıldığını gösterdi. `CALL` sonrası kod kesimi değeri değişti (altyazıda ana kesim 078A, yordamın kesimi 078D olarak okunuyor); iki kod kesimi henüz ayrıdır.

## 7. MAP Dosyası ile Kesim Yerleşimi

### 7.1 MAP dosyasının oluşturulması

`LINK` komutunun sonuna noktalı virgül konmazsa bağlayıcı MAP dosyası oluşturulup oluşturulmayacağını sorar; bir ad verilince dosya oluşur. MAP dosyası her kesimin başlangıç ve bitiş fiziksel adresini (beş haneli onaltılık sayı), boyutunu, adını ve sınıfını listeler. Hoca dosyayı bir metin düzenleyicide açtı.

### 7.2 Yığın kesimi

**Soru (hocanın sorusu):** Yığın kesiminin boyutu neden $28_h$?
**Cevap:** `DW 20 DUP(?)` 20 word, yani 40 byte yer açar; $40 = 28_h$.

### 7.3 Hizalama tipi ve kesimin başlangıç adresi

Yığın kesimi $0_h$–$27_h$ arasını kaplar. Bir sonraki kesim $28_h$'tan başlayabilecekken $30_h$'tan başlar.

**Soru (hocanın sorusu):** Neden $30_h$?
**Cevap (bir öğrenci):** Hizalama tipi `PARA` verildiği için. Paragraf, adresin 16'ya tam bölünebilmesi, yani son onaltılık hanesinin 0 olması demektir. `BYTE` verilseydi kesim $28_h$'tan, `PAGE` verilseydi $100_h$'tan başlardı.

### 7.4 Veri kesimi boyutu

Veri kesimi $1B_h$ byte yer kaplar. Hesap:

| Değişken | Tanım | Boyut (byte) |
|---|---|---|
| dizi | 11 × `DW` | $11 \cdot 2 = 22$ |
| n | `DW` | 2 |
| aranan | `DB` | 1 |
| sonuc | `DW` | 2 |
| Toplam | | $27 = 1B_h$ |

$1B_h = 16 + 11 = 27$.

> **Hocanın vurgusu:** Bu tür kesim boyutu hesaplarının sınavda sorulduğunu, bu yüzden ayrıntılı anlattığını söyledi.

### 7.5 Kod kesimleri

Birleştirmeden önce MAP dosyasında iki ayrı kod kesimi görünür: biri $21_h$, diğeri $22_h$ byte boyutundadır ve her biri paragraf sınırından başlar.

## 8. Kod Kesimlerini Birleştirme

### 8.1 PUBLIC birleştirme tipi

İki kod kesimi, kesim tanımında sınıf adından önce `PUBLIC` sözcüğü yazılarak birleştirilir. Bu hem ana dosyada hem harici yordamın dosyasında yapılmalıdır:

```asm
mycs            SEGMENT PARA PUBLIC 'code'
```

Koşullar: kesim adları aynı olmalı, sınıf adları aynı olmalı ve kesimler `PUBLIC` tanımlanmalıdır. Hizalama tiplerinin de aynı olması istenir. Böylece derlenip bağlandığında MAP dosyasında bir yığın kesimi, bir veri kesimi ve tek bir kod kesimi kalır. Birleşmiş kod kesiminin boyutu $52_h$ çıktı.

### 8.2 Birleşik boyut neden 52h?

**Soru (hocanın sorusu):** İlk kod kesimi $21_h$, ikincisi $22_h$ idi. Toplamları $52_h$ eder mi?
**Cevap:** Etmez; $21_h + 22_h = 43_h$. Hizalama `PARA` olduğu için ikinci parça 16'nın katından başlar; ilk parça $21_h$ byte olsa da $30_h$'a kadar yer kaplar. Doğru hesap $30_h + 22_h = 52_h$'tır.

### 8.3 MAP dosyasındaki giriş noktası satırı

**Soru:** MAP dosyasının en altındaki "program entry point" satırı ne demek?
**Cevap:** Programa girildiğinde hangi kesimin hangi ofsetinden başlanacağını söyler; buradan fiziksel adres de hesaplanabilir. Hoca bunun derste kullanılan konular için doğrudan bir anlam taşımadığını, farklı bir DOS ortamında farklı biçimde görünebileceğini söyledi.

### 8.4 Assembly'de blok yorum

**Soru:** Yorum satırlarını tek tek noktalı virgülle yazmak yerine blok yorum yapma imkânı var mı?
**Cevap:** Yok.

### 8.5 Kesimleri birleştirmenin yararı

**Soru:** İki kod kesimini birleştirmenin faydası nedir?
**Cevap:** Önce, tek bir kesim olur ve işlemler tek kesim üzerinden yürür. Hoca C ile benzetme yaptı: en basit "Hello World" programında bile ilk satır `#include <stdio.h>`'dir; `printf` ve `scanf`'in kodunu başkası yazmıştır, hazır kullanılır. Assembly'de de birçok iş yapan yordamlar ayrı dosyalarda yazılmıştır; `EXTRN` ve `PUBLIC` ile bağlama aşamasında kendi kesiminize katılır. On farklı yordam ayrı dosyalarda olsa ve her biri ayrı kesim olsa, her kesim 64K'lık ayrı bir alan anlamına gelir. Küçük yordamlar için bu gereksizdir; hepsi tek bir kod kesimine konabilir. Java'daki çok sayıda `import` da benzer bir durumdur.

Aynı kesimde olunca başka bir yordamın içindeki bir ofsete bile dallanılabilir (örneğin `JMP 0022`); hoca bunun ustalık isteyen ve yer tasarrufu sağlayan bir kullanım olduğunu söyledi.

DEBUG'da birleştirilmiş programa bakıldığında ana yordamın `CALL`'ı kendi kod kesimi değerine (altyazıda 7F6F gibi okunuyor) dallanır; yardımcı yordam aynı kesimin devamındadır. Hizalama `PARA` iken yordam $30_h$'tan başlar ve arada boşluk kalır. Hizalama `BYTE` yapılınca yordam ana kodun bittiği yerin hemen ardından başlar: `RETF`'nin hemen arkasından `PUSH BP`, `MOV BP, SP`, `PUSH ...` komutları gelir ve kod `RETF 6` ile biter.

## 9. Örnek 2: Her Elemanı İkili Gösterimindeki 1 Sayısına Bölme

### 9.1 Soru

Aradan sonra ikinci örneğe geçildi. Slayttaki sorunun görünen kısmı şöyledir (ekrandan, 01:50:00):

> Örnek 2: 5 elemanlı Word tanımlı işaretli sayılardan oluşan bir dizide her bir elemanının binary gösterimindeki 1'lerin sayısını bulup, dizinin o elemanını bulduğunuz sayıya böl[en] ... yazınız. Verilen sayının içerisinde 1'lerin topla[mını bulan] ... harici yordam olarak yazınız.

<!-- BELİRSİZ: Soru metninin ortası DOSBox penceresinin altında kalıyor; köşeli parantezli ve üç noktalı kısımlar karede okunamadı. Altyazıya göre sonuç aynı dizinin üzerine yazılıyor. -->

### 9.2 Elle çözüm: FAh

Hoca tahtada ilk elemanı çözdü (ekrandan, 01:50:00). $FA_h$'ın ikili gösterimi `1111 1010`'dur. $FF_h = 255$ olsaydı, $FA_h$ ondan 5 eksik olduğu için $250$'dir. İçinde 6 tane 1 vardır. $250 / 6$: bölüm 41, kalan 4. Diziye ondalık 41 değil, onaltılık karşılığı yazılır: $41 = 32 + 9 = 29_h$. Yani $FA_h$'ın yerine $29_h$ yazılacaktır.

Dizinin bütün işlemleri ana yordamda yapılır; ana yordam her elemanı yığın üzerinden harici yordama gönderir, yordam tek bir elemanı alıp 1'leri sayar, böler ve sonucu döndürür.

### 9.3 Ana yordam

Ana yordam Örnek 1'in dosyası kopyalanıp değiştirilerek yazıldı. Dizi word ve 5 elemanlıdır; sonuç aynı dizinin üzerine yazılacağı için ayrı bir sonuç değişkeni yoktur. SI indis olarak kullanılır ve sıfırlanır. Her turda `PUSH dizi[SI]` ile eleman yığına atılır, yordam çağrılır, AX'te dönen sonuç `MOV dizi[SI], AX` ile aynı yere yazılır, SI 2 artırılır ve `LOOP L1` ile `n` kez dönülür. Yığına atılan eleman burada temizlenmez; yordamın dönüşte temizlemesi beklenir.

Karede görülen tanımlar (ekrandan, 01:35:00) ve DEBUG'daki döngü (ekrandan, 01:50:00) birlikte şöyledir:

```asm
                EXTRN SAYveBOL:FAR
myss            SEGMENT PARA STACK 'sta'
                DW 20 DUP(?)
myss            ENDS

myds            SEGMENT PARA 'dat'
dizi            DW 0FAh, 0FFh, 0ABh, 12h, 16h
n               DW 5
myds            ENDS

mycs            SEGMENT BYTE PUBLIC 'code'
                ASSUME CS:mycs, DS:myds, SS:myss
MAIN            PROC FAR
                PUSH DS
                XOR AX, AX
                PUSH AX
                MOV AX, myds
                MOV DS, AX

                XOR SI, SI
                MOV CX, n
L1:             PUSH dizi[SI]
                CALL SAYveBOL
                MOV dizi[SI], AX
                ADD SI, 2
                LOOP L1

                RETF
MAIN            ENDP
mycs            ENDS
                END MAIN
```

<!-- BELİRSİZ: L1 etiketi ve CALL/ADD/LOOP satırları ana yordamın karesinde henüz yazılmamıştı; DEBUG çıktısında PUSH [SI+0000], CALL 076D:002E, MOV [SI+0000],AX, ADD SI,+02, LOOP 001B sırası görülüyor ve kod buna göre tamamlandı. -->

DEBUG çıktısında `MOV CX,[000A]` görülür: `n`, 5 word'lük (10 byte) diziden hemen sonra, $0A_h$ ofsetindedir.

### 9.4 Yordam: 1'leri sayma

Eleman `[BP+6]`'dan alınır (uzak yordam, tek parametre). 16 bitlik sayının 16 bitini tek tek CF'ye düşürmek için 16 kez sağa kaydırılır (`SHR AX, 1`); düşen bit `ADC BX, 0` ile sayaca eklenir. Sonuç BX'te birikir; BX önceden `XOR BX, BX` ile sıfırlanır. Örnekteki $FA_h$ için sonunda BX = 6 olur.

Sağa ya da sola kaydırmanın fark etmediği, çünkü yalnız CF'ye düşen bitlerin toplamının kullanıldığı söylendi. Döndürme (`ROR`/`ROL`) da kullanılabilir.

**Soru (hocanın sorusu):** 16 kez kaydırdıktan sonra kaydırılan yazmaçta ne kalır?
**Cevap (bir öğrenci):** Sıfır. 16 bitlik sayı 16 kez sağa ya da sola kaydırılırsa 0 olur ve değer kaybolur. Bu yüzden bölmeden önce eleman `[BP+6]`'dan yeniden okunur. Döndürme kullanılsaydı 16 turdan sonra değer korunurdu. Hoca, bu yüzden tekrar bellekten okumayı gerektirmeyen döndürmenin optimizasyon açısından daha mantıklı olabileceğini söyledi.

İlk yazımda sayma BX'te, sonuç AX'te tasarlanmıştı; bölme komutu AX'i bölünen olarak kullandığı için hoca yazmaçları değiştirdi: eleman AX'e, sayaç BX'e alındı (ekrandan, 01:40:00 ve 01:45:00).

### 9.5 İşaretli bölme: CWD ve IDIV

Soruda sayılar işaretli verildiği için bölme `IDIV` ile yapılır. Word boyutunda `IDIV` DX:AX ikilisini operanda böler; bölüm AX'e, kalan DX'e düşer.

**Soru (hocanın sorusu):** DX ne olacak?
**Cevap (öğrenciler):** Bir öğrenci DX'te başka bir değer kalmış olabileceğini, sıfırlanması gerektiğini söyledi; bir başkası DX'in değerinin bozulmaması için yığına atılıp geri alınması gerektiğini ekledi. Hoca `PUSH DX` / `POP DX` eklendi ama DX'i sıfırlamanın yetmeyeceğini belirtti: sayı işaretli olduğu için DX'e 0 koymak, negatif bir sayıyı büyütürken işaretini kaybettirir. Bir öğrenci doğru komutu söyledi: `CWD` (convert word to double word).

`CWD` operand almaz; AX'i işaretini koruyarak DX:AX'e genişletir. AX'in en anlamlı biti 1 ise DX'in bütün bitleri 1, 0 ise bütün bitleri 0 olur. Ardından `IDIV BX` ile bölünür ve sonuç AX'te döner.

### 9.6 Sıfıra bölme kontrolü

Hoca bir örnekle sordu: dizinin altıncı elemanı $00_h$ olsaydı ne olurdu? 0'ın içinde hiç 1 yoktur, BX = 0 olur ve $0 / 0$ yapılır. Bu "divide by zero" hatası verir ve programın akışı bir kesme (interrupt) tarafından kesilir; kesmeler bir sonraki konudur. Bu yüzden saymadan sonra BX 0 ile karşılaştırılır; `JE` ya da `JZ` aynı anlamdadır. Sorun varsa AX'e 0 yazılarak dönülür. AX'e 65536 farklı değerden biri yazılabilir, metin yazılamaz; bu durumda 0 döndürmek seçildi.

> **Hocanın vurgusu:** Bu tür durumlara dikkat edin; aynı şey ödevlerde ve sınavlarda da karşınıza çıkabilir. Bölmeden önce bölen bir if ile kontrol edilmelidir.

### 9.7 Çalıştırma ve sonuçlar

İki dosya derlenip `link 231221c.obj + 231221d.obj` ile bağlandı, MAP dosyası da oluşturuldu. Kesimler `BYTE` hizalamayla birleştirildiği için DEBUG'da ana yordamın `RETF`'si $002D_h$'ta biter, yordam hemen $002E_h$'ta `PUSH BP` ile başlar (ekrandan, 01:50:00). Yordam DEBUG'da `RETF 2` ile biter: tek bir word parametre temizlenir.

`D DS:0` ile önce dizi (`FA`, `FF`, `AB`, `12`, `16`) görüldü; `G` ile çalıştırıldıktan sonra ilk eleman $29_h$, ikinci eleman $1F_h$ oldu. Hoca ikinci sonucu da elle doğruladı: $FF_h = 255$, içinde 8 tane 1 vardır; $255 / 8$: bölüm 31, kalan 7; $31 = 16 + 15 = 1F_h$.

Dizinin bütün elemanları için beklenen sonuçlar (python ile doğrulandı):

| Eleman | Ondalık | 1 sayısı | Bölüm | Kalan | Yazılan |
|---|---|---|---|---|---|
| $FA_h$ | 250 | 6 | 41 | 4 | $29_h$ |
| $FF_h$ | 255 | 8 | 31 | 7 | $1F_h$ |
| $AB_h$ | 171 | 5 | 34 | 1 | $22_h$ |
| $12_h$ | 18 | 2 | 9 | 0 | $09_h$ |
| $16_h$ | 22 | 3 | 7 | 1 | $07_h$ |

<!-- BELİRSİZ: Derste ekranda yalnız ilk iki sonuç (29 ve 1F) ayrıca gösterildi; son üç satır python hesabıdır. -->

## 10. Aynı Kesimde Yakın (NEAR) Yordam

**Soru (hocanın kendi sorduğu):** Yordamlar artık aynı kesimdeyse yordamı `NEAR` tanımlayamaz mıyız?
**Cevap:** Tanımlanabilir. Kesimler birleştiriliyorsa harici yordam başka bir dosyada yazılsa bile yakın olabilir. Ana yordam `FAR` kalır, çünkü işletim sistemine dönmektedir. Yordam `PROC NEAR` yapılır ve `RETF` yerine `RET` kullanılır. Bu durumda DEBUG'da `CALL` komutu yalnız ofset değerini yazar; o ofset yordamın `PUSH BP` ile başladığı yerdir.

<!-- BELİRSİZ: Ana dosyadaki EXTRN satırının NEAR olarak değiştirildiği altyazıda söyleniyor gibi ("bu da near"), ama karede görülmedi. -->

**Soru:** Yordamı NEAR yaptığımızda yığına kod kesimi atılmadı; o zaman hâlâ `[BP+6]` mı kullanılmalı?
**Cevap:** Hayır, `[BP+4]` olmalı. Yakın çağrıda yalnız ofset (IP) yığına atılır, CS atılmaz. `[BP+2]` dönüş ofseti, `[BP+4]` parametre olur. Hoca önce düzeltmeden çalıştırdı ve dizide "bambaşka" değerler oluştuğunu gösterdi; ofsetler 4 yapılınca ilk eleman yeniden $29_h$ oldu.

Son hali (ekrandan, 01:55:00):

```asm
                PUBLIC SAYveBOL
mycs            SEGMENT BYTE PUBLIC 'code'
                ASSUME CS:mycs
SAYveBOL        PROC NEAR

                PUSH BP
                MOV BP, SP
                PUSH BX
                PUSH CX
                PUSH DX

                MOV AX, [BP+4]
                XOR BX, BX
                MOV CX, 16
L1:             SHR AX, 1
                ADC BX, 0
                LOOP L1

                MOV AX, [BP+4]

                CMP BX, 0
                JE sorunvar
                CWD                 ; AX -> DX:AX
                IDIV BX             ; DX:AX / BX -> Bolum: AX, Kalan: DX
                JMP atla
sorunvar:       MOV AX, 0

atla:           POP DX
                POP CX
                POP BX
                POP BP

                RET 2
SAYveBOL        ENDP
mycs            ENDS
                END
```

**Soru:** Uzak tanımlı yordamları aynı kod kesimine aldığımızda, yordam diğer dosyadaki değişkenlere doğrudan adıyla erişebilir mi?
**Cevap:** Hayır, önceki hafta anlatılan yol izlenir. Değişken tanımlandığı dosyada `PUBLIC dizi` ile, kullanılacağı dosyada tipiyle birlikte `EXTRN dizi:WORD` ile bildirilir. Ancak o zaman kullanılabilir; başka bir yol yoktur.

> **Ek bilgi (derste anlatılmadı):** Assembler bir `CALL`'ın yakın mı uzak mı olacağına hedefin tipine bakarak karar verir. Harici bir yordam için bu tip `EXTRN` satırından gelir; yordam `PROC NEAR` yapılıp çağıran dosyada `EXTRN ...:FAR` bırakılırsa çağrı uzak, dönüş yakın olur ve yığın dengesi bozulur. Bu yüzden iki tanımın birlikte değiştirilmesi gerekir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Word tanımlı bir dizide byte tanımlı bir elemanın kaç kez geçtiğini bulan EXE tipi ASM programını yazınız. Dizinin adresini, eleman sayısını ve aranan sayıyı stack'e atan ve sonucu AX üzerinden döndüren bir harici yordam kullanınız. Kod kesimini ortak alan olarak belirleyecek ek işlemleri gerçekleştiriniz.

> **Çözüm (derste verildi):** Bölüm 4 ve 5'teki iki dosya. Ana yordam `PUSH n`, word'e genişletilmiş `aranan` (işaretsizse `XOR AX, AX` / `MOV AL, aranan`, işaretliyse `CBW`) ve `LEA AX, dizi` ile adresi atar, `CALL SAY` yapar, `MOV sonuc, AX` yazar. Yordam `[BP+10]` n, `[BP+6]` adres, `[BP+8]` aranan ile çalışır ve `RETF 6` ile döner. İki kod kesimi `mycs SEGMENT PARA PUBLIC 'code'` ile birleştirilir. Deneme dizisinde 12 için 6, 13 için 1, 18 için 0.

**Soru 2** (ekrandan, 00:40:00): AL'de `10110011` varken sayı işaretsiz ve işaretli kabul edilirse değeri nedir? AH sıfırlanarak AX'e genişletilirse ne olur?

> **Çözüm (derste verildi):** İşaretsiz 179, işaretli $-77$ (ikiye tümleyen ya da $179 - 256$). AH = 0 ile genişletme işaretsiz sayıyı korur ama $-77$'yi $+179$'a çevirir; işaretli sayı için `CBW` kullanılmalıdır.

**Soru 3** (derste sözlü, 00:42:00): Byte tipindeki işaretli bir sayıyı işaretini koruyarak word'e genişleten komut hangisidir? BL'yi BX'e genişletmek için kullanılabilir mi?

> **Cevap (derste verildi):** `CBW`. Operand almaz, yalnız AL'yi AX'e genişletir; BL/BX için kullanılamaz.

**Soru 4** (derste sözlü, 01:05:40): MAP dosyasında yığın kesiminin boyutu neden $28_h$, bir sonraki kesim neden $30_h$'tan başlıyor?

> **Cevap (derste verildi):** `DW 20 DUP(?)` = 40 byte = $28_h$. Hizalama `PARA` olduğu için sonraki kesim 16'nın katı olan $30_h$'tan başlar (`BYTE` olsaydı $28_h$, `PAGE` olsaydı $100_h$).

**Soru 5** (derste sözlü, 01:07:13): Örnek 1'in veri kesimi neden $1B_h$ byte yer kaplar?

> **Cevap (derste verildi):** $11 \cdot 2 + 2 + 1 + 2 = 27 = 1B_h$ (dizi, `n`, `aranan`, `sonuc`).

**Soru 6** (derste sözlü, 01:11:28): $21_h$ ve $22_h$ byte'lık iki kod kesimi `PARA` hizalamayla birleştirildiğinde boyut neden $52_h$ olur?

> **Cevap (derste verildi):** İkinci parça $30_h$'tan başlar; $30_h + 22_h = 52_h$. $21_h + 22_h = 43_h$ olurdu.

**Soru 7** (ekrandan, 01:50:00): 5 elemanlı word tanımlı işaretli sayılardan oluşan bir dizide her elemanın ikili gösterimindeki 1'lerin sayısını bulup elemanı bu sayıya bölen ve sonucu dizinin üzerine yazan programı, 1'leri sayıp bölen kısmı harici yordam olarak yazınız. <!-- BELİRSİZ: soru metninin bir kısmı karede kapalı. -->

> **Çözüm (derste verildi):** Bölüm 9.3 ve 10'daki kod. 16 kez `SHR AX, 1` / `ADC BX, 0` ile 1'ler sayılır, eleman yeniden okunur, BX = 0 ise AX = 0 döndürülür, değilse `CWD` / `IDIV BX`. FAR sürümde parametre `[BP+6]` ve `RETF 2`, NEAR sürümde `[BP+4]` ve `RET 2`. $FA_h \to 29_h$, $FF_h \to 1F_h$.

**Soru 8** (derste sözlü, 01:43:31): İşaretli `IDIV` öncesi DX'e ne yapılmalıdır? Sıfırlamak yeterli mi?

> **Cevap (derste verildi):** Yeterli değildir; negatif sayıda işaret kaybolur. `CWD` ile AX, DX:AX'e işaretini koruyarak genişletilir.

**Soru 9** (derste sözlü, 01:46:19): Eleman $00_h$ olursa ne olur?

> **Cevap (derste verildi):** 1 sayısı 0 olur ve $0/0$ sıfıra bölme hatası verir; bölmeden önce `CMP BX, 0` / `JE` ile kontrol edilip AX = 0 döndürülür.

**Soru 10** (derste sözlü, 01:54:10): Yordam NEAR yapıldığında parametre hâlâ `[BP+6]`'da mıdır?

> **Cevap (derste verildi):** Hayır; CS yığına atılmadığı için `[BP+4]`'tedir.

## Dersin Toparlaması

Bu derste yığın üzerinden parametre alan harici yordamlar iki örnekle tekrar edildi ve yeni olarak farklı dosyalardaki kod kesimlerinin tek kesimde birleştirilmesi gösterildi. Birinci örnekte word dizide byte tanımlı bir değer sayıldı; byte'ın yığına atılmadan önce word'e genişletilmesi gerektiği, işaretsiz durumda AH'nin sıfırlandığı, işaretli durumda `CBW` kullanıldığı görüldü. Yordamın içinde parametrelere BP üzerinden erişildi, kullanılan yazmaçlar saklandı ve yığın `RETF 6` ile temizlendi. MAP dosyası üzerinden kesimlerin boyutları ve hizalama tipinin kesim başlangıçlarına etkisi incelendi; `PUBLIC` birleştirme tipiyle iki kod kesimi tek kesime indi ve hizalama `BYTE` yapılınca yordamın ana kodun hemen ardına yerleştiği görüldü.

İkinci örnekte her elemanın 1 bitleri `SHR` ve `ADC` ile sayıldı, işaretli bölme için `CWD` ve `IDIV` kullanıldı, sıfıra bölme bir kontrolle önlendi. Son olarak, birleştirilmiş kesimde yordamın `NEAR` tanımlanabileceği ve bu durumda yığında CS olmadığı için parametre ofsetinin 2 azaldığı gösterildi. Hoca bir sonraki derste kesme (interrupt) mekanizmasının, son derste ise yüksek seviyeli dillerle assembly'nin birlikte kullanımının anlatılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
