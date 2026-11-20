# Ders 8 Genişletilmiş Notu: 8255 Mod 0 Uygulamaları: LED-Düğme, 7 Parçalı Gösterge ve Tuş Takımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dört düğme ve dört LED: problem ve donanım
- 2. Mod seçimi ve kontrol sözcüğü
- 3. Kontrol sözcüğünü yazan kod
- 4. Programın akışı: LED'leri yakma, okuma, maskeleme, kaydırma
- 5. Proteus'ta adım adım çalıştırma
- 6. 7 parçalı gösterge
- 7. Tek ortak anotlu göstergede 0 yakma
- 8. Dört göstergenin çoğullanması
- 9. Matris tuş takımı
- 10. Tuş takımı örneği
- Örnek Sorular

## 1. Dört düğme ve dört LED: problem ve donanım

Ders, önceki dersin sonunda başlanan 8255 mod 0 örneklerinin ikincisiyle açılır. Bu örnekte bir LED dizisi ile bir düğme dizisi birlikte kullanılır. Problemin öncül bilgileri şunlardır:

- 8086'nın G/Ç uzayında 60H adresinden başlayan ardışık çift adreslere bir 8255 yerleştirilmiştir.
- 8255'in port C'sine 4 düğme ve 4 LED, şekilde verilen yapıda bağlanmıştır.
- İstenen uygulama: başta bütün LED'ler yanık olacak; hangi numaralı düğmeye basılırsa o numaralı LED sönecek, diğerleri yanık kalacak.

60H'den başlayan ardışık çift adresler için önceki dersteki adres çözümleme devresi aynen geçerlidir. Bu devrenin çıkışı bir etiket üzerinden 8255'in $\overline{CS}$ ucuna verilir. İşlemcinin $\overline{RD}$ ve $\overline{WR}$ uçları 8255'in aynı adlı uçlarına bağlanır, RESET ucu toprağa çekilir. İşlemcinin A1 ucu 8255'in A0'ına, A2 ucu 8255'in A1'ine bağlıdır. Cihaz ardışık çift adreslerde olduğu için veri uçları D0-D7 işlemcinin düşük anlamlı veri yoluna bağlanır; benzetimde işlemcinin veri uçları AD0-AD7 diye etiketlenmiştir (ekrandan, 00:05:00).

Bu bağlantılar sonunda adresler şöyle çıkar:

| Adres | 8255 yazmacı |
|---|---|
| 60H | Port A |
| 62H | Port B |
| 64H | Port C |
| 66H | Kontrol yazmacı |

### 1.1 Donanımdan çıkarılması gerekenler

Kod yazmadan önce iki soru cevaplanmalıdır: düğmeye basıldığında okunacak değer 0 mı 1 mi, ve LED'i yakmak için 8255 ucunda hangi değer oluşturulmalı?

Düğmeler anlık (momentary) basmalı düğmelerdir; bırakıldığında kendiliğinden eski konumuna döner. Şemada düğmelerin 8255'e bağlı tarafı bir pull-up dirençle 5 V'a çekilmiştir, öteki tarafı topraktadır (ekrandan, 00:05:00 ve 00:25:00). Bu yüzden düğmeye basılmadığında uçta lojik 1, basıldığında lojik 0 görülür. Sonuç: port C'nin alt yarısında herhangi bir bitte 0 okunursa o düğmeye basılmıştır.

LED'lerin anot tarafı 8255'e (PC4-PC7), katot tarafı toprağa bağlıdır. Bir LED'i yakmak için ilgili uçta lojik 1 oluşturmak gerekir.

## 2. Mod seçimi ve kontrol sözcüğü

"Mod 0" cevabı doğrudur ama gerekçesi de bilinmelidir. Düğme ve LED gibi elemanlarda işlemcinin gönderdiği ya da 8255 üzerinden okunan verinin karşıya ulaşıp ulaşmadığını denetlemeye gerek yoktur; durum kritik değildir ve basit paralel veri aktarımı söz konusudur. Bu durumda 8255'i mod 0'da kullanmak anlamlıdır.

> **Hocanın vurgusu:** Mod seçiminde yalnız "mod 0" demek yetmez; el sıkışma ve denetim gerekmediği için mod 0 seçildiği söylenebilmelidir.

Bütün elemanlar port C'ye bağlıdır. Port C'nin üst yarısında LED'ler olduğu için PCH çıkış, alt yarısında düğmeler olduğu için PCL giriş olmalıdır. Port C'nin iki yarısı ayrı ayrı giriş ya da çıkış yapılabilir, ama port C'ye yazma ve port C'den okuma her zaman 8 bit birden yapılır. Bu yüzden okunan değerde düşük 4 bit korunacak biçimde maskeleme gerekir. Çıkış yönlü uçlara `OUT` ile değer yazmak anlamlıdır; giriş yönlü uçlara değer yazılsa da bunun karşılığı olmaz.

Kontrol sözcüğü slayttaki şemaya göre bit bit kurulur (ekrandan, 00:10:00). Ekranda hocanın kırmızıyla yazdığı notlar "PCL: buton, giriş" ve "PCH: LED, çıkış" şeklindedir; port A ve port B kutuları çarpı ile işaretlenmiştir.

| Bit | Anlamı | Değer | Gerekçe |
|---|---|---|---|
| D7 | Mod ayar bayrağı | 1 | Mod ayarı yapılıyor |
| D6 D5 | Grup A modu | 0 0 | Grup A (port A ve PCH) mod 0 |
| D4 | Port A yönü | X | Port A kullanılmıyor |
| D3 | PCH yönü | 0 | LED'ler, çıkış |
| D2 | Grup B modu | 0 | Grup B (port B ve PCL) mod 0 |
| D1 | Port B yönü | X | Port B kullanılmıyor |
| D0 | PCL yönü | 1 | Düğmeler, giriş |

X'ler 0 kabul edilirse kontrol sözcüğü $1000\,0001_2 = 81H$ olur (python ile doğrulandı). Port A ve port B'nin yönü önemsizdir, ama modlar önemlidir: grup A'nın modu PCH'yi, grup B'nin modu PCL'yi etkilediği için iki grup da mod 0'a alınır.

## 3. Kontrol sözcüğünü yazan kod

Kontrol sözcüğü kontrol yazmacına, yani 66H adresine yazılmalıdır. Sistem açılıp resetlendiği anda 66H G/Ç adresine 81H gönderilmelidir.

### 3.1 Neden MOV değil, OUT?

Aksi belirtilmedikçe derste isolated I/O kullanılır. Bu, adres çözümlemede M/$\overline{IO}$ ucunun kullanıldığı anlamına gelir. Sonuç olarak G/Ç cihazı `IN` ve `OUT` komutlarında seçilir, `MOV` komutlarında seçilmez; `MOV` bellek işlemi yapar. Bu yüzden 8255'in bir yazmacına değer yazmak için bir kez `OUT` kullanmak gerekir.

### 3.2 OUT komutunun parametreleri

`OUT` iki parametre alır: port adresi ve veri yazmacı. Veri yazmacı `AL` ya da `AX` olabilir. Bağlantıda cihazın 8 bitlik veri yolu yalnız işlemcinin 8 bitlik veri yoluna bağlı olduğu için 8 bitlik işlem yapılır ve `AL` kullanılır.

Port adresi için iki yaklaşım vardır:

- Sabit adres (fixed, p8): 8 bite sığan adresler; adresin kendisi doğrudan yazılır.
- Değişken adres (variable): 8 bite sığmayan adresler; adres `DX` yazmacına konur.

66H 8 bite sığdığı için doğrudan yazılabilir: `OUT 66H, AL`. Bu komuttan önce AL'de 81H oluşturulmalıdır. Bir yazmaçta sabit (immediate) değer oluşturmak için `MOV` kullanılır. İki işlenenin ikisi birden köşeli parantezli bellek işleneni olamaz. Tahtadaki iki satır (ekrandan, 00:15:00):

```text
MOV AL, 81H   ; grup A ve grup B mod 0
OUT 66H, AL   ; PCL giriş (düğmeler), PCH çıkış (LED'ler), PA ve PB önemsiz
```

> **Hocanın vurgusu:** Kod yazarken her satıra noktalı virgülle açıklama yazılmalıdır. Yazılacak kod iki satır olsa da "port C low input, port C high output, port A ve port B don't care, mod 0" gibi açıklamalar kodun okunabilirliği ve değerlendirilmesi için çok önemlidir.

> **Ders sonrası not:** Hoca `MOV AL, 81H` komutunu anlatırken AL'yi "source", 81H'yi "destination" olarak adlandırdı. Doğrusu tersidir: Intel sözdiziminde ilk işlenen hedef (destination), ikinci işlenen kaynaktır (source). Komut 81H sabitini (kaynak) AL yazmacına (hedef) kopyalar.

**Soru:** 66H, 8086 için 8255'in kontrol yazmacını mı gösteriyor? **Cevap:** Evet. 8255 60H'den başlayan ardışık çift adreslere yerleştirildi ve 8255'in A0'ına işlemcinin A1'i, A1'ine işlemcinin A2'si bağlandı. Bu bağlantılar sonucunda 60H port A, 62H port B, 64H port C ve 66H kontrol yazmacı olur.

Bu iki satırın karşılığı: 8255'in kontrol yazmacına 81H atanır; grup A ve grup B mod 0'a alınır, PCL giriş, PCH çıkış yapılır.

## 4. Programın akışı: LED'leri yakma, okuma, maskeleme, kaydırma

Benzetimdeki COM tipi programın tamamı aşağıdadır (ekrandan, 00:20:00 ve 00:30:00):

```text
CODE    SEGMENT PUBLIC 'CODE'
        ASSUME CS:CODE
START:
        MOV AL, 81H
        OUT 66H, AL
        MOV AL, 0FFH
        out 64H, AL
        ; write your code here
ENDLESS:
        IN  AL, 64H
        OR  AL, 0F0H
        CMP AL, 0FFH
        JZ  ENDLESS
        MOV CL, 4
        SHL AL, CL
        OUT 64H, AL
        JMP ENDLESS
CODE    ENDS
        END START
```

### 4.1 Başlangıçta LED'leri yakmak

`MOV AL, 0FFH` ve `OUT 64H, AL` port C'ye FFH yazar. Bunun hemen öncesinde PCL giriş yapılmıştı. PCL uçlarına da 1 yazılmış olur, ama bu uçlar giriş yönlü olduğu için yazmanın etkisi yoktur. PCH'deki dört uca 1 gelir ve dört LED yanar. Başta bütün LED'lerin yanmasını sağlayan durum budur.

### 4.2 Düğmeleri okumak

`IN AL, 64H` port C'nin uçlarındaki değerleri AL'ye kopyalar. PCL anlamlıdır, ama PCH çıkış olduğu için oradan anlamlı bir değer okunamaz. Hiçbir tuşa basılmıyorsa pull-up dirençler yüzünden PC0-PC3'te 1 1 1 1 görülür; PC4-PC7'de ise istenmeyen değerler olabilir. Bu bitler, PCL bozulmadan maskelenmelidir.

### 4.3 İki maskeleme seçeneği

AL'nin bitleri $b_7 \dots b_0$ olsun. Hoca iki seçenek verir:

- `AND AL, 0FH`: üst 4 bit 0 ile VE'lenir, dolayısıyla 0 olur; alt 4 bit (B3, B2, B1, B0) korunur. Tuşa basılmıyorsa sonuç 0FH olur.
- `OR AL, 0F0H`: üst 4 bit 1 ile VEYA'lanır; bir şeyi 1 ile VEYA'lamak onu 1 yapmaktır. Alt 4 bit korunur. Tuşa basılmıyorsa sonuç FFH olur.

Hoca `OR` seçeneğini tercih eder, çünkü maskelemeden sonra değer kaydırılarak doğrudan kullanılacaktır ve tuşsuz durumda FFH elde etmek daha uygundur.

Benzetimde ilk okumada alt 4 bit F, üst 4 bit 0 geldi (yazmaç penceresinde AX = 00FF görülür; ekrandan, 00:30:00). Hoca, üst yarıya herhangi bir değer gelebileceği için buna güvenilmediğini, bu yüzden maskelendiğini vurgular.

### 4.4 Tuşa basılıp basılmadığını anlamak

`CMP AL, 0FFH` ile AL, FFH ile karşılaştırılır. Sonuç sıfırsa (AL = FFH) hiçbir tuşa basılmamıştır ve `JZ ENDLESS` ile başa dönülür: port C yeniden okunur, maskelenir, yeniden bakılır. Tuşa basılmadıkça döngü sürer.

Döngü kırıldıysa bir tuşa basılmıştır. Basılan düğmeye göre `OR` sonrası AL değerleri (python ile doğrulandı):

| Basılan düğme | PC3 PC2 PC1 PC0 | AL |
|---|---|---|
| B3 | 0 1 1 1 | F7H |
| B2 | 1 0 1 1 | FBH |
| B1 | 1 1 0 1 | FDH |
| B0 | 1 1 1 0 | FEH |

Hoca bu değerleri tahtada bulurken bir an B1 için "EH" dedi, sonra düzeltip FDH'ye ulaştı.

### 4.5 Kaydırma ile LED'lere taşıma

Bu değer elde edildikten sonra LED'lere aktarmak için yapılan işlem çok basittir: AL dört bit sola kaydırılır. Böylece alt yarıdaki düğme bit örüntüsü üst yarıya, yani LED bitlerine taşınır; alt yarıya 0'lar gelir ama orası giriş olduğu için önemsizdir. Sonuç port C'ye yazılınca basılan düğmeye karşılık gelen LED söner. Ardından `JMP ENDLESS` ile başa dönülüp yeni bir tuşa basılması beklenir.

`SHL` komutunun iki kullanımı vardır:

- `SHL kaynak, 1`: bir kez kaydırmak için 1 doğrudan (immediate) yazılabilir.
- `SHL kaynak, CL`: birden fazla kaydırmada sayı `CL` üzerinden verilir.

Dört kez kaydırılacağı için önce `MOV CL, 4`, sonra `SHL AL, CL` yazılır, ardından `OUT 64H, AL` gelir.

Kaydırma sonuçları (python ile doğrulandı):

| AL (OR sonrası) | `SHL AL, 4` sonrası | Sönen LED ucu |
|---|---|---|
| FEH | E0H ($1110\,0000_2$) | PC4 |
| FDH | D0H ($1101\,0000_2$) | PC5 |
| FBH | B0H ($1011\,0000_2$) | PC6 |
| F7H | 70H ($0111\,0000_2$) | PC7 |

Tuş bırakıldığında AL yeniden FFH olur ve döngü port C'ye yazmadan başa döner, bu yüzden son yazılan durum korunur.

## 5. Proteus'ta adım adım çalıştırma

Hoca benzetimi bu kez duraklatma (pause) ile başlatır ve hata ayıklama ekranına düşer. Debug menüsünden 8086 yazmaç penceresi ve 8255 iç durum penceresi açılır (ekrandan, 00:20:00). Bu tür hata ayıklama COM tipi programlarda sorunsuz yapılabilir; EXE tipi programlarda biraz sıkıntı olur.

- İlk adımda `MOV AL, 81H` yürütülür ve AL'nin 81H ile yüklendiği görülür.
- 8255 iç durum penceresinde başta her şey 0'dır. `OUT 66H, AL` yürütülünce kontrol sözcüğü 81H olur; pencere grup A ve grup B'nin mod 0'da (set/reset modunda değil) çalıştığını, PCH'nin çıkış, PCL'nin giriş olduğunu gösterir. Port A ve port B önemsizdi ama X yerine 0 yazıldığı için onlar da çıkış yönlü görünür.
- İki adım daha atılıp 64H'ye FFH gönderilince LED'ler yanar.

Bir sonraki adımda bir düğmeye basılı tutulur. Benzetim hemen ilgili satıra geçmediği için hoca bir satıra çift tıklayarak kesme noktası (breakpoint) koyar ve benzetimi çalıştırır. B0'a basılıyken kesme noktasında AL = FEH görülür. CL'ye 4 atanır, AL dört kez kaydırılınca E değeri AL'nin öteki yarısına geçer (E0H). `OUT 64H, AL` ile yazılınca PC4'e bağlı LED söner (ekrandan, 00:35:00). Hoca bu LED'in "4 numaralı" olduğunu, ama PC4'e bağlı olduğu için birinci düğmeyle aynı anlam sırasında bulunduğunu belirtir. B3'e basılınca AL = F7H olur, kaydırma sonucu 70H yazılır ve en yüksek anlamlı bitteki (PC7) LED söner.

Örneğin akılda kalması gereken noktaları hoca şöyle toparlar: port C'nin düşük ve yüksek anlamlı yarıları ayrı ayrı giriş ve çıkış için kullanılabilir; yönler bağlanan düğme ya da LED dizisine göre belirlenir; port 8 bit okunduğu için anlamsız yarı maskelenmelidir. Maskeleme iki biçimde yapılabilir: F ile VEYA'lamak ya da 0 ile VE'lemek. Maskelemek, ilgilenilen bitleri koruyup ilgilenilmeyen bitleri önceden belirlenen bir değere zorlamak demektir.

## 6. 7 parçalı gösterge

7 parçalı gösterge (seven segment display) içinde 8 LED bulunan bir elemandır. LED'lerin yerleşimi sayesinde 0'dan F'ye kadar onaltılık değerleri ve noktalı ondalık değerleri gösterebilir. Hoca LED sembollerini tahtaya rakam biçiminde çizer (ekrandan, 00:40:00): üstte a, sağ üstte b, sağ altta c, altta d, sol altta e, sol üstte f, ortada g ve sağ altta nokta için h. Toplam 8 LED vardır.

Göstergenin 9 ucu vardır: bir ortak uç ve a, b, c, d, e, f, g, h veri uçları (ekrandan, 00:45:00).

### 6.1 Ortak katot ve ortak anot

Bir LED'in bir tarafı anot (+), öteki tarafı katottur (−).

- LED'lerin katotları ayrı ayrı dışarı veri ucu olarak çıkarılır ve bütün anotlar birleştirilip tek bir ortak uç olarak verilirse **ortak anotlu (OA) 7 parçalı gösterge** elde edilir.
- Her LED'in anodu ayrı ayrı dışarı verilir ve bütün katotlar birleştirilip ortak uç yapılırsa **ortak katotlu (OK) 7 parçalı gösterge** elde edilir.

Ekranda "ortak uç LED katot → OK 7 parçalı gösterge" ve "ortak uç LED anot → OA 7 parçalı gösterge" diye yazılmıştır (ekrandan, 00:45:00).

### 6.2 Ortak anotlu göstergede değer oluşturmak

Ortak anot ucunda lojik 0 varsa, veri uçlarına 0 ya da 1 verilmesi fark etmez: LED'in yanması için anot ile katot arasında pozitif gerilim farkı gerekir ve bu fark oluşamaz, hiçbir LED yanmaz. Yani bütün LED'leri söndürmenin kısa yolu ortak anot ucuna 0 vermektir.

Bir değer göstermek için ortak anoda lojik 1 bağlanır; yanacak parçanın katoduna lojik 0, sönük kalacak parçanın katoduna lojik 1 verilir. Hoca benzetimde 2 rakamını bu mantıkla yakar ve noktayı da söndürür.

### 6.3 Ortak katotlu göstergede değer oluşturmak

Ortak katotluda yakmak için ortak uca 0 verilir (katot 0 olmalıdır ki LED yanabilsin), sonra yanacak her parçaya 1 verilir. Hoca 2 rakamını burada da gösterir. <!-- BELİRSİZ: Hoca ortak katotlu için bitleri sayarken "3 yanmayacak, 4 yanacak, 5 yanacak, 6 yanmayacak, 7 yanacak" diyor; hangi uç numaralandırmasına göre saydığı altyazıdan anlaşılmıyor ve değer karede görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Derste 2 rakamının sayısal değeri söylenmedi. 2 için a, b, g, e, d parçaları yanar; c, f ve h söner. $hgfedcba$ sırasıyla ortak anotlu göstergede bu büyük olasılıkla $1010\,0100_2 = A4H$, ortak katotluda bunun tümleyeni $5BH$ olur (python ile hesaplandı).

### 6.4 İki tip arasındaki ilişki

Ortak anotlu göstergede bir değeri yakan veri ve ortak uç değerlerinin hepsinin bire tümleyeni alınırsa aynı değer ortak katotlu göstergede yakılmış olur. Yanlışlıkla ortak anotluya ortak katotlunun verisi gönderilirse rakam "sönük olarak", yani parçaların tersi yanarak görünür. Yakılmak istenen değer sönük görülüyorsa, veri yanlış ortak uç tipine göre gönderilmiş demektir.

> **Hocanın vurgusu:** Bunu anlamak için LED'in nasıl yandığı, anot ve katodun neresi olduğu bilinmelidir. Bütün anotlar birleşirse ortak anotlu, katotlar veri olarak dışarı çıkar; bütün katotlar birleşirse ortak katotlu, anotlar veri olarak dışarı çıkar.

## 7. Tek ortak anotlu göstergede 0 yakma

Bu örnekte 8255'e tek bir ortak anotlu 7 parçalı gösterge bağlanmıştır (Proteus bileşeni 7SEG-MPX1-CA). Göstergenin veri uçları port B'ye bağlıdır: a ucu PB0'a, ..., h ucu PB7'ye denk gelir. Ortak anot ucu doğrudan lojik 1'e (besleme) bağlıdır (ekrandan, 00:50:00). Soru: göstergede 0 değerini göstermek.

### 7.1 Port ayarı

Gösterge port B'ye bağlı olduğu için port B çıkış olmalıdır. Gönderilen veriyi denetleyecek bir el sıkışma sinyal grubu olmadığı için mod 0 seçilir. Bütün port B mod 0 çıkış yapılır.

Kontrol sözcüğü (ekrandan, 00:55:00 civarı anlatım):

- D7 = 1 (mod ayar bayrağı etkin).
- Grup A'nın modu (mod 0, 1 ya da 2) önemsizdir; port A ve PCH de önemsizdir.
- D2 = 0: grup B mod 0.
- D1 = 0: port B çıkış.
- D0: PCL önemsiz.

Hoca bunu $1\,XXXX\,0\,0\,X$ diye yazar; X'ler 0 alınırsa gönderilecek değer 80H olur. Bu değer 66H adresindeki kontrol yazmacına gönderilir.

### 7.2 0 rakamının verisi

0 rakamı için a, b, c, d, e, f parçaları yanık, g ve h sönük olmalıdır. Ortak anoda lojik 1 verilir. En yüksek anlamlı bit PB7 = h olduğu için anlam sırası $hgfedcba$ korunarak:

| h | g | f | e | d | c | b | a |
|---|---|---|---|---|---|---|---|
| 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |

Yani port B'ye gönderilecek değer $1100\,0000_2 = C0H$'dir (python ile doğrulandı). Bunun tersi, yani 3FH gönderilirse ortak anotlu göstergede 0 "sönük" görünür: yalnız g ve h yanar, diğerleri söner.

### 7.3 EXE tipi kod

Kod bu kez EXE tipi yazılmıştır (ekrandan, 00:55:00):

```text
STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DATA    SEGMENT PARA 'DATA'
DIGITS  DB 0C0H
DATA    ENDS

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
START:
        MOV AX, DATA
        MOV DS, AX
        MOV AL, 80H
        OUT 66H, AL
        MOV AL, 0FFH
        OUT 62H, AL
        MOV AL, 0FFH
        OUT 64H, AL
        MOV AL, DIGITS
        OUT 62H, AL
        ; Write your code here
ENDLESS:

        JMP ENDLESS
CODE    ENDS
        END START
```

EXE tipi programlarda üç segment tanımlanır: yığın (stack), veri (data) ve kod (code). En altta `END` kelimesinden sonra programın başlangıç etiketi verilir; program belleğe yüklendiğinde `START` etiketinden çalışmaya başlar.

- Yığın segmenti, fonksiyon çağrıları ve geri dönüşler için ayrılan bir alandır ve çift sayıda baytlık olmalıdır.
- Veri segmentinde bayt genişliğinde `DIGITS` adlı bir değişken tanımlanır ve değeri C0H'dir: az önce bulunan, ortak anotlu göstergede 0'ı yakan değer.
- `MOV AX, DATA` ve `MOV DS, AX` satırları, tanımlanan veri segmentinin kullanılabilmesi için gereklidir. İşletim sistemi ya da başka bir kod programı çağırdığında veri segmentinde başka bilgiler bulunur; bu iki satır varsayılan veri segmentini programın kendi segmentine eşitler. Segment yazmaçlarına başka yazmaçlardan değer atanabilir ama doğrudan sabit atanamaz; bu yüzden işlem iki satırla yapılır.
- `MOV AL, 80H` ve `OUT 66H, AL`: port B mod 0 çıkış (diğerleri önemsiz).
- `OUT 62H` ile FFH: port B'nin bütün uçlarına 1 verilir, yani gösterge sönük başlar.
- `OUT 64H` ile FFH: port C'ye FFH yazılır, ama port C'ye bir şey bağlı değildir; yalnız adım adım çalışırken görülsün diye konmuştur.
- `MOV AL, DIGITS` ve `OUT 62H, AL`: C0H port B'ye gönderilir ve göstergede 0 yanar.

Hoca bu kodun COM tipi de yazılabileceğini, iki farklı örnek elde bulunsun diye birini COM birini EXE verdiğini söyler.

## 8. Dört göstergenin çoğullanması

Sonraki soru: aynı port ile 4 tane 7 parçalı gösterge sürülebilir mi?

### 8.1 Çalışma mantığı

Dört göstergenin a-h veri uçları ortak olarak port B'ye bağlıdır; her göstergenin ortak anot ucu ayrı bir port C ucuna (PC0, PC1, PC2, PC3) bağlıdır (ekrandan, 01:05:00 ve 01:10:00). Sistem çok yavaş çalıştırılsa şu görülür:

- Birinci gösterge etkinleştirilir, diğerleri kapatılır; birinci basamağın verisi port B'den gönderilir ve belirli bir süre yanık bırakılır.
- Bütün göstergeler kapatılır, yalnız ikinci gösterge etkinleştirilir, ikinci basamağın verisi gönderilir, beklenir.
- Aynı işlem üçüncü ve dördüncü basamak için yapılır, sonra birinci basamağa dönülür.

Örneğin 1234 yakılmak istenirse önce yalnız birinci basamakta 1 yanar, sonra yalnız ikincide 2, sonra üçüncüde 3, sonra dördüncüde 4. Basamak geçişi saniyede 25 kereden fazla olursa, yani yenileme frekansı 25 Hz'in üstüne çıkarsa göz yanan ışıkları tamamlar ve hepsi aynı anda yanıyormuş gibi algılar.

### 8.2 Uç tasarrufu

Alternatif olarak her göstergenin veri uçları ayrı bir porta bağlanabilir ve ortak uçları sabit sürülebilirdi. Ama her gösterge için 8 veri ucu gerekir. Çoğullama ile 8 veri ucu ve 4 gösterge etkinleştirme ucu, toplam 12 uç yeter. Yapı ölçeklenebilirdir: 100 basamak için çoğullamayla $100 + 8 = 108$ uç, ayrı ayrı sürmede $100 \times 8 = 800$ veri ucu gerekir. Bu, az sayıdaki ucu verimli kullanmak için bir tarama mantığıdır.

> **Ders sonrası not:** Hoca ayrı portlardan sürme seçeneği için "port A, port B, port C, port D" dedi ve gereken veri ucu sayısını "4 × 4 = 16" olarak verdi. Her basamak 8 veri ucu istediği için doğrusu $4 \times 8 = 32$ uçtur; bu hocanın 100 basamak için verdiği $100 \times 8$ hesabıyla da tutarlıdır. Ayrıca tek bir 8255'te yalnız üç port (A, B, C) bulunur; dört ayrı port için büyük olasılıkla ikinci bir çevre birimi gerekir.

### 8.3 Ortak anot ucunun sürülmesi

**Soru (hoca sınıfa sordu):** Ortak anotlu bir göstergeyi kapatmak (disable) için ortak anot ucuna hangi değer verilmeli? **Cevap:** Lojik 0. Anot artı taraf olduğu için 0 verilirse gösterge kapanır. Açmak için ortak anoda lojik 1, yanacak her parçaya 0 verilir; örneğin a ve b'ye 0 verilirse yalnız o iki parça yanar. Ekranda PC0'a giden ortak uca "logic 0" yazılmış ve ortak anot ucu "OA" diye işaretlenmiştir (ekrandan, 01:05:00).

Algoritma: sırasıyla display 1'i etkinleştir (diğerleri kapalı), birinci basamağın verisini gönder, biraz bekle, bütün göstergeleri söndür, sonraki basamağa geç, onu etkinleştir, verisini gönder, bekle; bunu döngü içinde tekrarla.

### 8.4 Örnek kod ve port ayarı

**Soru (hoca sınıfa sordu):** Port B'den göstergelerin verisi, port C'den etkinleştirme işaretleri gönderiliyorsa port B ve port C'nin yönleri ve modları ne olmalı? **Cevap:** İkisi de mod 0 çıkış.

Kontrol sözcüğünde yalnız D7 = 1 yapılıp diğer bütün bitlere 0 yazılırsa: grup A ve grup B mod 0, PCL çıkış, port B çıkış, PCH çıkış, port A çıkış olur. Yani bütün portları mod 0 çıkış yapmak için 80H yazmak yeterlidir (ekranda kontrol sözcüğü şemasının yanında daire içinde "80H" yazılıdır; ekrandan, 01:20:00).

Örnek kod yine EXE tipidir: yığın, veri ve kod segmentleri tanımlanır, `START` etiketinden girilir, veri segmenti iki satırla ayarlanır. Ardından:

- Kontrol sözcüğüne 80H yazılır: bütün portlar mod 0 çıkış.
- Port B'ye FFH gönderilir: bütün parçalar sönük.
- Port C'ye FFH gönderilir: bütün ortak anotlar lojik 1, yani bütün göstergeler etkin.
- Bu dört satırın sonucu: bütün göstergeler etkin ama bütün parçaları sönük.
- Son olarak veri segmentindeki `DIGITS` dizisinin bir elemanı (`DIGITS+1` gibi bir indeksle) AL'ye alınıp port B'den gönderilir.

`DIGITS` dizisi bayt dizisi olarak tanımlanmıştır ve ortak anotlu göstergede 0, 1, 2, ..., 9 rakamlarını görmek için a = bit 0, h = bit 7 anlam sırasında gönderilmesi gereken verileri içerir. <!-- BELİRSİZ: DIGITS dizisinin değerleri hiçbir karede görünmüyor. --> Bütün göstergeler aynı anda etkin olduğu için gönderilen rakam dördünde birden görünür: önce dördünde de 1, kod 9 için güncellenince dördünde de 9 görülür. Port C'nin bütün uçlarından lojik 1 çıktığı benzetimde kırmızı renkle görülür.

> **Ek bilgi (derste anlatılmadı):** Ortak anotlu göstergede $hgfedcba$ sırasıyla 0-9 rakamları için yaygın kullanılan değerler C0H, F9H, A4H, B0H, 99H, 92H, 82H, F8H, 80H, 90H'dir. Derste kullanılan dizinin değerleri karede görünmediği için bunlarla aynı olduğu büyük olasılıkla doğrudur ama doğrulanamadı (özellikle 6, 7 ve 9 için farklı biçimler kullanılabilir).

## 9. Matris tuş takımı

7 parçalı göstergede bazı uçları bütün göstergeler için ortak veri olarak kullanıp uç tasarrufu yapılmıştı. Tuş takımında da benzer bir mantık vardır: tuşlar matris biçiminde yerleştirilir ve satır ve sütun üzerinden sürülüp okunur.

### 9.1 Uç sayısı

Takımda 4 satır ve 3 sütun, toplam 12 tuş vardır. Her tuş için ayrı uç kullanılsa 12 uç gerekirdi. Matris yapısında tuş tarama ile 3 sütun için 3, 4 satır için 4, toplam 7 uç yeter. Bu ölçeklenebilir: 10 × 10 matris biçimindeki bir takım için 20 uç yeterken tuşlar tek tek sürülseydi 100 port ucu gerekirdi. Algoritma biraz zorlaştırılıp donanımdaki bağlantı sayısı azaltılmış olur, çünkü yeterli uç yoktur.

### 9.2 Temel kural

Bir tuşa basıldığında o tuşun satır hattı ile sütun hattı kısa devre olur. Ön koşul: aynı anda birden fazla tuşa basılmaz. Basılırsa donanımın farklılaşması, örneğin devrenin diyotlarla korunması gerekir. Gerekirse satırlar pull-up ya da pull-down dirençlerle yukarı ya da aşağı çekilir. Ekranda iki takım yan yana gösterilir: "Sütundan sürülen satırdan pullup direnç ile okunan tuş takımı" ve "Sütundan sürülen satırdan pulldown direnç ile okunan tuş takımı" (ekrandan, 01:15:00).

### 9.3 Pull-up ile okunan satırlar

Satırlar 8255'in port uçlarına bağlanacağı için, pull-up dirençlerle lojik 1'e çekilmişlerse hiçbir tuşa basılmadığında 8255 uçlarında 1 görülür.

- Sütunların hepsi 1 ile sürülürse basılan tuşu anlamanın faydası olmaz: tuşa basıldığında 1 seviyesindeki sütun pull-up'lı satırla kısa devre olur ve satırda yine 1 görülür.
- Hepsi 0 ile sürülürse basılan tuşun satırı 0 olur. Ama aynı satırdaki tuşlar ayırt edilemez: 4'e, 5'e ya da 6'ya basılsa da aynı satır 0 olur.
- Çözüm: sütunlar sırayla, her seferinde yalnız biri 0 olacak biçimde sürülür. Basılan tuşun sütunu o anda etkinse ilgili satırda 0 görülür.

Tarama saniyede bin mertebesinde frekanslarda yapılır; tuş basılı kaldığı sürede dönen 0 mutlaka basılan tuşun sütununa denk gelir. Örnekler:

- 5'e basılıyken ikinci sütun etkinleştirildiğinde ikinci satırda 0 görülür: matrisin (2, 2) gözü, yani 5.
- Yıldız (*) tuşuna basıldığında tarama o sırada üçüncü sütunda olsa bile, parmak çekilmeden etkin sütun birinci sütuna gelir ve dördüncü satırda 0 görülür: dördüncü satır, birinci sütun, yani yıldız.

Sonuç: pull-up dirençlerle okunan bir takımda sütunu etkinleştirmek için o sütuna 0 verilir. Bütün sütunlara 0 verilirse hangi satırdaki tuşa basıldığı anlaşılır ama tuşun kendisi anlaşılmaz; bu yüzden her seferinde tek sütun etkinleştirilir.

### 9.4 Pull-down ile okunan satırlar

Pull-down dirençlerle okunan satırlarda hiçbir tuşa basılmadığında 8255 uçlarında 0 görülür.

- Sütunlar 0 ile sürülürse tuşa basıldığında değişim görülmez: 0 ile 0 kısa devre olur.
- Hepsi 1 ile sürülürse basılan tuşun satırında 1 okunur, ama aynı satırdaki tuşlar (4, 5, 6) ayırt edilemez.
- Çözüm: tek bir sütun etkinleştirilir; burada etkinleştirmek ilgili uca 1 vermektir.

Örnek: 8'e basılmış olsun. Önce birinci sütun taranır, değişiklik olmaz. İkinci sütun etkinleştirildiğinde etkin sütun basılan tuşun sütununa denk gelir ve üçüncü satırda 1 görülür. Tuşların yerleşimi önceden bilindiği için üçüncü satır, ikinci sütundaki tuşun 8 olduğu anlaşılır.

### 9.5 Yönler

Satırlardan okunur, sütunlardan sürülür. Sürmek, uçta değer oluşturmak demektir. 8255'e bağlandığında sürülen sütunlar 8255 açısından çıkış, okunan satırlar giriş olmalıdır.

## 10. Tuş takımı örneği

Soru: 60H'den başlayan ardışık çift adreslere yerleştirilmiş bir 8255'in port C'sine bir tuş takımının satırları bağlıdır; sütunlar port A'nın düşük anlamlı 3 biti ile sürülür. Port A ve port C nasıl ayarlanmalıdır?

Hoca burada "satır" ve "sütun" kavramına dikkat çeker: hangisinin satır sayılacağı, pull-up ya da pull-down direncin nereye bağlı olduğuyla ilgilidir. Takım yan çevrilse pull-up dirençler sütunlara bağlıymış gibi görünürdü. Önemli olan, pull-up dirençlerin bağlı olduğu tarafın giriş, öteki tarafın çıkış (sürülen sütun) olmasıdır.

Şemada sütun 1, 2, 3 sırasıyla PA0, PA1, PA2'ye; pull-up'lı A, B, C, D satırları PC0, PC1, PC2, PC3'e bağlıdır (ekrandan, 01:30:00).

### 10.1 Kontrol sözcüğü

Port A mod 0 çıkış, port C'nin alt yarısı mod 0 giriş olmalıdır. Ekranda "PortA mod 0 output" ve "PCL mod 0 input" notları vardır (ekrandan, 01:25:00).

- D7 = 1: mod ayarı.
- D6 D5 = 0 0: port A grup A'da olduğu için grup A mod 0.
- D4 = 0: port A çıkış.
- D3 = X: PCH ile ilgilenilmiyor.
- D2 = 0: PCL giriş yapılacağı için grup B mod 0.
- D1 = X: port B önemsiz.
- D0 = 1: PCL giriş.

X'ler 0 alınırsa değer yine 81H olur ve 66H port adresine gönderilir. Kod COM tipidir ve ilk iş 66H'ye 81H yazmaktır.

### 10.2 Sütun etkinleştirme ve okuma

Satırlar pull-up'lı olduğu için bir sütun 0 yapılınca etkin olur. Örnek kod port A'ya (60H) FDH gönderir. FDH $= 1111\,1101_2$'dir (ekranda "1111 1101" yazılıdır; ekrandan, 01:30:00): PA0 = 1, PA1 = 0, PA2 = 1. Yani yalnız ikinci sütun etkindir; ekranda bu sütun ve 2, 5, 8, 0 tuşları kırmızıyla işaretlenmiştir. <!-- BELİRSİZ: 01:26:25 civarında hoca "yüksek anlamlı 4 bitine 0 versek 3'e karşılık gelir" diyor; neyi kastettiği altyazıdan anlaşılmıyor. -->

Ardından satırlar `IN AL, 64H` ile okunur ve okunan değer 02H ile denetlenir. 02H $= 0000\,0010_2$ yalnız PC1'i, yani ikinci satırı (B satırı) seçer. İkinci sütun etkinken ikinci satır 0 okunursa basılan tuş 5'tir. Koşul sağlandığında program "tuş var" etiketine dallanır ve BL'deki değer sıfırdan farklı bir değere atanarak tuşa basıldığı işaretlenir. <!-- BELİRSİZ: Bu kısmın kodu karede görünmüyor; altyazıda hem "2H ile karşılaştırıyoruz" hem "0.2 ile test edildiği durumda" geçiyor. Komut büyük olasılıkla TEST AL, 02H'dir. -->

Hoca örneğin tam bir örnek olmadığını, başta bütün sütunu tarıyormuş gibi düşündüğünü ama aslında yalnız 5 tuşunu algıladığını belirtir. Tam ölçekli kullanım için her sütun sırayla etkinleştirilmeli, satırlardan okunan değer 1, 2, 4, 8 ile karşılaştırılarak hangi satırın etkin olduğu bulunmalıdır. Sütunu program zaten kendisi etkinleştirdiği için satır ve sütun bilgisinden basılan tuş matris biçiminde bulunur. Hangi tuşun hangi satır ve sütuna denk geldiği veri segmentinde bir tablo olarak tanımlanıp ilgili değer oradan alınabilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00 ve 00:10:00): 8086'nın G/Ç uzayında 60H'den itibaren ardışık çift adreslere bir 8255 yerleştirilmiştir. 8255'in port C'sine 4 düğme (PC0-PC3, pull-up'lı) ve 4 LED (PC4-PC7, anot porta, katot toprağa) bağlıdır. Başta bütün LED'lerin yanık olduğu, basılan sıradaki düğmeye karşılık gelen LED'in söndüğü uygulamayı gerçekleyin.

> **Çözüm (derste verildi):** Mod 0; PCL giriş, PCH çıkış, PA ve PB önemsiz. Kontrol sözcüğü 81H, 66H'ye yazılır. Port C'ye FFH yazılarak LED'ler yakılır. Döngüde `IN AL, 64H`, `OR AL, 0F0H`, `CMP AL, 0FFH`, `JZ ENDLESS`; tuşa basılınca `MOV CL, 4`, `SHL AL, CL`, `OUT 64H, AL`, `JMP ENDLESS`. Tam kod 4. bölümdedir.

**Soru 2** (derste sözlü, 00:11:10): 66H G/Ç adresine 81H değerini nasıl yazarsınız?

> **Çözüm (derste verildi):** Isolated I/O kullanıldığı için `MOV` ile değil `OUT` ile: `MOV AL, 81H` ve ardından `OUT 66H, AL`. Adres 8 bite sığdığı için doğrudan yazılır; 8255 8 bitlik veri yoluna bağlı olduğu için `AL` kullanılır.

**Soru 3** (derste sözlü, 00:30:33): `OR AL, 0F0H` maskelemesinden sonra B3, B2, B1 ve B0 düğmelerinden birine basıldığında AL'de hangi değer okunur? `SHL AL, 4` sonrası değer ne olur?

> **Çözüm (derste verildi, python ile doğrulandı):** B3: F7H → 70H; B2: FBH → B0H; B1: FDH → D0H; B0: FEH → E0H.

**Soru 4** (derste sözlü, 00:49:26 ve ekrandan, 00:50:00): 8255'in port B'sine bir ortak anotlu 7 parçalı gösterge bağlıdır (a = PB0, ..., h = PB7). Göstergede 0 değerini göstermek için port nasıl ayarlanmalı ve porta hangi değer gönderilmelidir?

> **Çözüm (derste verildi):** El sıkışma olmadığı için port B mod 0 çıkış; kontrol sözcüğü 80H (X'ler 0), 66H'ye yazılır. Ortak anot lojik 1; a-f için 0, g ve h için 1: $1100\,0000_2 = C0H$, port B'ye (62H) gönderilir.

**Soru 5** (derste sözlü, 01:04:40): Ortak anotlu bir göstergeyi kapatmak için ortak anot ucuna hangi değer verilmelidir?

> **Çözüm (derste verildi):** Lojik 0. Açmak için lojik 1 verilir ve yanacak parçalara 0 gönderilir.

**Soru 6** (derste sözlü, 01:06:17): Dört göstergeli çoğullamalı devrede veri port B'den, gösterge etkinleştirme işaretleri port C'den gönderiliyor. Port B ve port C'nin yönleri ve modları ne olmalıdır? Kontrol sözcüğü kaçtır?

> **Çözüm (derste verildi):** İkisi de mod 0 çıkış. Bütün portları mod 0 çıkış yapan kontrol sözcüğü 80H'dir.

**Soru 7** (derste sözlü, 01:22:19 ve ekrandan, 01:25:00): 60H'den itibaren ardışık çift adreslerdeki bir 8255'in port C'sine bir tuş takımının pull-up'lı satırları bağlı, sütunlar port A'nın düşük anlamlı 3 biti ile sürülüyor. Port A ve port C nasıl ayarlanmalıdır?

> **Çözüm (derste verildi):** Port A mod 0 çıkış, PCL mod 0 giriş. Kontrol sözcüğü $1000\,0001_2 = 81H$ (X'ler 0), 66H'ye yazılır. Satırlar pull-up'lı olduğu için bir sütunu etkinleştirmek için o sütuna 0 verilir; örneğin FDH yalnız ikinci sütunu etkinleştirir.

**Soru 8** (derste sözlü, 01:11:13): Dört ortak anotlu göstergede 1234 değerini gösteren uygulamanın algoritmasını yazın.

> **Çözüm (derste verildi, yalnız algoritma):** Birinci göstergeyi etkinleştir (yalnız onun ortak anodu 1), 1'in verisini port B'den gönder, bekle; yalnız ikinciyi etkinleştir, 2'nin verisini gönder, bekle; üçüncü için 3, dördüncü için 4; sonra birinci basamağa dön. Döngü 25 Hz'in üstünde tekrarlanmalıdır. Kodu derste yazılmadı.

**Soru 9** (derste sözlü, 01:32:52): 4 × 3 tuş takımında basılan tuşun hangisi olduğunu bir yazmaçta saklayan uygulamayı tasarlayın.

> **Çözüm (derste verilmedi, yalnız hocanın tarif ettiği yöntem):** Her sütunu sırayla tek başına 0 yapıp (FEH, FDH, FBH ile PA0, PA1, PA2) port C'yi okuyun; alt 4 bitte 0 olan bit satırı verir (1, 2, 4, 8 değerleriyle denetlenir). Satır ve sütun bilgisinden tuş, veri segmentindeki bir tablodan bulunup yazmaca konur. Kod derste yazılmadı.

## Dersin Toparlaması

Bu derste 8255'in mod 0'da üç tipik insan arayüzüyle kullanımı görüldü. Dört düğme ve dört LED örneğinde port C'nin iki yarısının ayrı yönlere ayarlanabildiği, ama okuma ve yazmanın 8 bit yapıldığı için anlamsız yarının `AND` ya da `OR` ile maskelenmesi gerektiği öğrenildi; düğme bitleri `SHL` ile LED bitlerine taşındı ve program Proteus'ta adım adım izlendi. 7 parçalı göstergede ortak anot ve ortak katot yapıları, parça verisinin bit sırasıyla nasıl kurulduğu (ortak anotluda 0 için C0H) ve EXE tipi program iskeleti incelendi. Ardından birden fazla göstergenin ortak veri hattı ve sırayla etkinleştirilen ortak uçlarla çoğullanarak sürülmesi anlatıldı.

Son olarak matris tuş takımında satır ve sütun hatlarıyla uç sayısının nasıl azaltıldığı, pull-up ve pull-down durumlarında etkin sütunun hangi değerle sürüleceği ve sütunların sırayla taranarak basılan tuşun bulunması görüldü. Tüm örneklerde ortak yöntem aynıdır: donanımdan giriş/çıkış yönlerini ve etkin seviyeleri çıkarmak, kontrol sözcüğünü bit bit kurmak, sonra sonsuz döngüde okuma ve yazma akışını yazmak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
