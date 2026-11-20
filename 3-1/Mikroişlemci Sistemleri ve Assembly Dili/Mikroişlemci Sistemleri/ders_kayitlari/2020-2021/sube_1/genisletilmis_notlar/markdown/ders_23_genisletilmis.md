# Ders 23 Genişletilmiş Notu: Kesme Vektör Tablosunu Değiştirme (DIV0 Örneği) ve 8259A Kesme Denetleyicisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri aktarım yöntemleri: polling, kesme ve DMA
- 2. Kesme kaynakları ve donanım kesme uçları
- 3. IF ve TF bayrakları
- 4. Kesme vektör tablosu
- 5. Kesme işleminin adımları ve IRET
- 6. TF bayrağını değiştirme sorusu
- 7. Kesme vektör tablosunu değiştirme: DIV0 örneği
- 8. Ek donanımsız INTR kullanımı: sabit tip, genişletme ve daisy chain
- 9. 8259A programlanabilir kesme denetleyicisi
- 10. 8259A ayar yazmaçları: ICW ve OCW
- 11. 8259A ile buton sayacı örneği
- Örnek Sorular

Ders, kesmeler konusunun devamıdır. Önce geçen haftanın kısa bir tekrarı yapılır, ardından kesme vektör tablosundaki bir adresin programla nasıl değiştirileceği bir sıfıra bölme (DIV0) örneğiyle gösterilir. Aradan sonra yardımcı devre kullanmadan INTR ucunun nasıl kullanılabileceği anlatılır ve 8259A programlanabilir kesme denetleyicisine geçilir. Ders, 8259 ile kesme temelli bir buton sayacı örneğiyle biter. Slaytların adı "11.pptx"tir (ekrandan, 00:10:00).

## 1. Veri aktarım yöntemleri: polling, kesme ve DMA

Bir giriş/çıkış (I/O) cihazıyla veri alışverişinde üç yöntem vardır: polling, kesme (interrupt) ve doğrudan bellek erişimi (direct memory access, DMA). Slaytta bunun için bir benzetme vardır (ekrandan, 00:10:00): ders çalışan bir öğrenci, bir kova dolunca hoparlörün müzik çalacağını, o zaman kovayı varile boşaltabileceğini düşünür. Öğrenci işlemciyi, hoparlör kesme isteğini, kova giriş cihazını, varil belleği temsil eder.

**Polling** mantığında bir I/O cihazından veri okumadan önce cihazın hazır olup olmadığı denetlenir. İşlemci cihazın durum (status) yazmacını sürekli okur, bit maskelemesi yapar ve ilgilendiği bitin oluşup oluşmadığına bakar. Bit oluşmuşsa veri hazırdır ve okunabilir. Önceki derslerde bu yöntem şu uçlarla kullanılmıştı:

- 8251'de RxRDY ve TxRDY,
- 8255'te grup A ve grup B için INTRA ve INTRB,
- 8254'te OUT ucu,
- ADC entegresinde kesme isteği (INTR) ucu.

Bu cihazların hepsi kesmeyi de destekler. 8255'in INTRA ve INTRB uçları adından da anlaşıldığı gibi kesme isteği uçlarıdır. 8251'in RxRDY ve TxRDY uçları ve 8254'ün OUT ucu da kesme tetiklemek için kullanılabilir. ADC'de doğrudan bir kesme isteği ucu vardır. DAC'ta ise yalnız veri yazma yönünde çalıştığı için böyle bir uç yoktur. 8259, bu cihazlardan gelen kesme isteklerini yöneten yardımcı devredir.

**Kesme temelli** aktarımda işlemci, I/O cihazlarını önceden uygun şekilde programlamıştır ve başka bir işle uğraşır. Veri hazır olunca cihaz, kesme ucu üzerinden işlemciyi uyarır. İşlemci bir komutun ortasındaysa onu bitirir, sonra kesme isteğini karşılamak için ilgili fonksiyona dallanır.

**DMA**'da yine bir yardımcı devre, DMA denetleyicisi (DMA controller) vardır. İki birim arasında (I/O ile bellek ya da bellek ile bellek) veri aktarımını kendi üzerinden yürütür. Polling ve kesmede I/O cihazından okunan verinin belleğe yazılması için veri önce işlemciye okunur, sonra belleğe yazılır. DMA'da ise denetleyiciye hangi adresten okunacağı, hangi adrese yazılacağı ve kaç baytlık aktarım yapılacağı yazılır. Ardından işlemci yolların denetimini DMA denetleyicisine devreder ve iki birim arasındaki aktarım hızlıca yapılır. Hoca, DMA'nın vakit yetmediği için ders kapsamında ayrıntılı işlenmeyeceğini söyledi.

> **Hocanın vurgusu:** Polling, kesme ve DMA kavramsal olarak bilinmelidir; sınavda sözel soru olarak sorulabilir.

## 2. Kesme kaynakları ve donanım kesme uçları

Slayttaki kesme kaynakları şöyledir (ekrandan, 00:20:00):

- Yazılımsal olarak: INT, INTO, INT 3
- Donanımsal olarak: INTR, NMI (donanım kesmesiyle ilgili onay: $\overline{INTA}$)
- Kesme ile ilgili bayraklar: IF, TF
- Kesme ile ilgili dönüş komutu: IRET

### 2.1 Yazılımsal kesmeler

Yazılımsal kesmelerin bir türü doğrudan `INT` komutudur. Yanına verilen 0-255 arası 8 bitlik sabit değere göre 256 farklı kesme tipi tetiklenebilir. Bazı özel komutlar da vardır; örneğin `INTO` doğrudan tip 4 kesmesini tetikler.

Diğer tür, aritmetik işlemlerin sonucuna göre oluşan kesmelerdir. Bir sayı sıfıra bölünmeye çalışılırsa sıfıra bölme kesmesi oluşur. İşaretsiz bölmede sonuç da taşabilir. Örneğin DX:AX'te çok büyük, BX'te çok küçük bir değer varken `DIV BX` komutu verilirse bölüm 16 bite sığmayabilir; bu durumda da kesme otomatik olarak oluşur.

> **Ders sonrası not:** Hoca bölüm taşmasını "overflow kesmesi" olarak andı. 8086'da bölüm hedef yazmaca sığmadığında büyük olasılıkla sıfıra bölmeyle aynı tip 0 (divide error) kesmesi oluşur; tip 4 ise `INTO` komutuyla OF=1 iken oluşan taşma kesmesidir.

### 2.2 NMI ve INTR

İki donanım kesme ucu vardır: NMI (non-maskable interrupt) ve INTR (interrupt request). Biri maskelenemez olduğuna göre diğeri maskelenebilir: INTR, IF bayrağıyla maskelenir. IF=0 iken INTR ucuna ne kadar uzun seviye işareti verilirse verilsin işlemci bunu değerlendirmez. NMI otomatik olarak tip 2 kesmesini tetikler.

INTR'den bir istek gelince işlemci $\overline{INTA}$ ucundan onay (acknowledge) işareti gönderir. 8086'lı sistemlerde $\overline{INTA}$ iki kez aktif olur. Bazı sistemler kesme tipini ilk onayda okuyabilir, ama 8086'da ilk darbede veri uçlarındaki değer çöp kabul edilir ve okunmaz. İkinci darbede çevre birimi kesme tipini D0-D7 uçlarından işlemciye vermelidir. Slayttaki zamanlama diyagramı bunu gösterir (ekrandan, 00:15:00): INTR yükselir, $\overline{INTA}$ iki kez sıfıra iner, D7-D0'da ilk darbede anlamsız veri, ikinci darbede "Vector number" vardır. Slaytın altındaki uyarı şudur: "Dikkat! Adres uçlarından gönderilen kesme TİP'idir, kesme vektör tablosunun ilgili adresi değil."

Özetle kesme tipi üç yoldan belirlenir:

- `INT n` komutunda yanındaki 8 bitlik sabit değer,
- NMI'da her zaman tip 2,
- INTR'de veri yolunun düşük anlamlı 8 bitinden okunan değer.

INTR seviye tetiklemelidir: istek olarak algılanması için uçta lojik 1 değerinin belli bir süre kalması gerekir. NMI ise yükselen kenarla tetiklenir. Hocaya göre kenar tetikleme daha pratiktir, çünkü geçiş anı nettir. Seviye tetiklemede örnekleme anlarına göre kısa süreli bir değişim kaçırılabilir; kenar tetiklemede değişim anı yakalanır.

## 3. IF ve TF bayrakları

IF bayrağı INTR ucunun çalışıp çalışmayacağını, yani donanım kesmelerinin kullanılıp kullanılmayacağını belirler.

TF (trap flag) 1 yapıldığında her komut yürütüldükten sonra tip 1 single-step kesmesi oluşur. Bu, adım adım hata ayıklama (debug) için kullanılır. Hoca örnek olarak, her adımda bütün yazmaçların değerlerini ekrana yazdıran bir kesme alt programının TF ile birlikte kullanılabileceğini söyledi.

Her kesme tipine farklı bir kesme alt programı tanımlanabilir. Kesme alt programı yalnız o kesmeyle, yani o I/O cihazının verisi hazır olduğunda yapılacak işlemlerle ilgili komutları içerir. Bir kesme gelince kesme alt programına dallanılır, oradaki komutlar yürütülür ve geri dönülür.

IF ve TF'nin önemli bir özelliği şudur: ana programda IF=1 yapılmış olsun ve bir dış kesme gelsin. Kesme alt programına dallanınca IF otomatik olarak 0 yapılır. Böylece kesme alt programı yürürken aynı cihazdan yeni bir kesme gelmesi varsayılan olarak engellenir. Programcı bunun farkındaysa alt program içinde IF'yi kendisi 1 yaparak iç içe kesmelere izin verebilir. Aynı durum TF için de geçerlidir: ana programda TF=1 yapıldıktan sonra ilk komut yürütülünce tip 1 kesme alt programına gidilir ve TF otomatik olarak sıfırlanır. Böylece kesme alt programının kendi komutları için iç içe single-step kesmeleri oluşmaz.

Kesme alt programına gidiş ve dönüş, far call'dan farklıdır. İşlemci, dönüş için segment ve offset değerlerinden önce bayrak yazmacını da yığına atar. Bu yüzden kesme alt programları `RET` ile değil `IRET` (interrupt return) ile döner. `IRET` yığının en üstünden çektiği ilk değeri IP'ye, ikinciyi CS'ye, üçüncüyü bayrak yazmacına yazar.

## 4. Kesme vektör tablosu

Slayttaki tanım şöyledir (ekrandan, 00:25:00): "Kesme oluştuğunda mevcut CS:IP ile gösterilen kodun yürütülmesi bırakılarak, kesmeye ilişkin fonksiyonun yer aldığı kesim ve offset değerindeki kod işlenmelidir. Her kesmeye ilişkin fonksiyonların hangi hafıza adresinde yer aldığı Kesme Vektör Tablosu ile tutulur."

Toplam 256 kesme tipi vardır ve tablonun boyutu 1024 bayttır. Demek ki her göz için 4 bayt ayrılmıştır. 4 bayta bir fonksiyon yazılamayacağı için tabloda kesme alt programlarının komutları değil, yalnız adresleri vardır. Program örneğin 700H segmenti civarında çalışırken tablo bellek uzayının 0 adresinden başlar; bu, segmentler arası bir dallanmadır, yani far jump gibi düşünülmelidir. Bu yüzden her gözde 2 bayt segment, 2 bayt offset değeri bulunur. Hoca ilk anlatımda sırayı segment-offset diye söyledi, sonra örneğe geçerken düzeltti: her gözde düşük adreste offset, yüksek adreste segment vardır.

Tablo, 20 bitlik fiziksel adres uzayının 00000H adresinden başlar. Sistem açıldığında boştur. Reset anında işlemci CS'ye FFFFH, IP'ye 0000H atar; bunlardan hesaplanan fiziksel adres FFFF0H'dir (reset vektörü). Bu adreste sistemi devralan bir BIOS ROM'u bulunmalıdır.

$$\text{Fiziksel adres} = \text{FFFFH} \times 10\text{H} + 0000\text{H} = \text{FFFF0H}$$

Tablo üç aşamada dolar:

- BIOS, kendi içinde tanımlı bazı kesme alt programlarının adreslerini tabloya yerleştirir, denetimlerini yapar ve açılışı işletim sistemine (DOS) devreder.
- DOS kendi kesme alt programlarının adreslerini tabloya ekler.
- Kullanıcı, geliştirdiği yazılımların kesme ihtiyaçları için kendisine ayrılmış alanı kullanarak kendi kesme alt programlarının adreslerini yazar.

Tablodaki ilk tipler:

- tip 0: sıfıra bölme,
- tip 1: TF=1 iken her komuttan sonra oluşan single-step,
- tip 2: NMI,
- tip 3: breakpoint,
- tip 4: taşma (overflow).

Belirli bölgeler işletim sistemi ve BIOS için, belirli bölgeler kullanıcı için ayrılmıştır. Hoca dersin ikinci yarısında, dış kesmelerle ilgili olarak 1FH'ye kadar olan bölgenin özel olarak ayrıldığını, 20H'den itibaren işletim sistemi ve kullanıcının kullanabileceğini söyledi.

> **Ders sonrası not:** Hoca bu sınırı "1FH adresine kadar" diye söyledi. Kastedilen büyük olasılıkla kesme tipi numarasıdır: tip 00H-1FH tabloda 00000H-0007FH adreslerini kaplar.

## 5. Kesme işleminin adımları ve IRET

Kesmelerde bir önem sırası vardır. Analog bir sistemde iki isteğin tam aynı anda gelme olasılığı çok düşük olurdu. Ama işlemci ayrık zamanlı (dijital) çalışır ve kesme olup olmadığını belirli saat çevrimlerinde denetler; bu denetim aralığında birden fazla kaynaktan istek gelmiş olabilir. Slayttaki adımlar şöyledir (ekrandan, 00:30:00):

```text
Sıradaki işlem bittiğinde, işlemci:
- Komut işleme ile oluşan, single-step, NMI, INTR, INT sırasıyla
  bir kesme olup olmadığını kontrol eder.
- Kesme varsa
- PUSHF
- IF<-0, TF<-0 (INTR, single-step kesmeleri engellenir)
- PUSH CS
- PUSH IP
- IP<-Kesme_vektör_tablosu, CS<-Kesme_vektör_tablosu
```

Kesme tipi belli olunca işlemci tablonun o numaralı gözüne gider. NMI ise 2 numaralı gözü kullanacağını bilir; INTR ise tipi veri uçlarının düşük anlamlı baytından okumuştur; `INT` komutunda tip zaten komutun yanında verilmiştir. Tablodan IP ve CS okunduğu anda kesme alt programına geçilmiş olur: ana programın akışı kesilir ve kesme alt programına dallanılır.

Kesme alt programında veri aktarımı yapıldıktan sonra `IRET` ile dönülür. `IRET` yığına konan değerleri ters sırada çeker: en üstteki offset IP'ye, sonraki CS'ye, sonra bayrak değeri bayrak yazmacına yazılır. Bayraklar yığına IF sıfırlanmadan önce atıldığı için, kesme alt programında özel bir şey yapılmazsa alt program IF=0 ile çalışır; dönüşte orijinal bayraklar geri geldiği için ana programda IF=1 yapılmışsa ana program yine IF=1 ile devam eder. Hoca bunu "POPF'yi çalıştırmıyor ama buna benzer bir mantık" diye anlattı.

IF için iki özel komut vardır:

- `STI` (set interrupt flag): IF=1 yapar.
- `CLI` (clear interrupt flag): IF=0 yapar.

TF için özel bir komut yoktur.

## 6. TF bayrağını değiştirme sorusu

Hoca TF'nin nasıl 1 yapılabileceğini sordu. Önce emu8086'nın yardım belgesinden `LAHF` (load AH from flags) komutuna baktı: bu komut TF'yi AH'ye almaz. Hoca, işaret bayrağı (SF) gibi düşük bayttaki bir bayrak için `LAHF` ile AH'ye alıp bit işlemi yapıp `SAHF` (store AH into flags) ile geri yazmanın mümkün olduğunu, ama TF için bunun işe yaramadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** `LAHF` ve `SAHF` büyük olasılıkla yalnız bayrak yazmacının düşük baytını (SF, ZF, AF, PF, CF) taşır. TF ise bayrak yazmacının 8. bitindedir (bit 0'dan sayınca), yani yüksek bayttadır; bu yüzden bu komutlarla değiştirilemez.

**Soru:** Bir öğrenci, TF'nin kodda bir hata olduğunda kalkan bir bayrak olduğunu hatırladığını, kasıtlı olarak hatalı bir işlem yapıp bayrakları okuyarak bunun sağlanabileceğini önerdi. **Cevap:** Hoca, daha önce kullandıkları donanımsal bir 8086 sisteminde onaltılık kodların tek tek girilip adım adım çalıştırılabildiğini, yani sistemde hata olmasa da adım adım debug yapılabildiğini hatırlattı. Önerdiği yol şudur: bayrak yazmacı yığına atılır, bit işlemi yapılır ve bayrak yazmacı yığından geri yüklenir.

**Soru:** Bir öğrenci, işletim sistemleri dersinde TF'nin işletim sistemindeki hatalarda kalktığını gördüklerini, bunun aynı şey olup olmadığını sordu. **Cevap:** Hoca, işletim sistemi tarafında öyle çalışabileceğini, ama kendi örneklerinde işletim sistemi bulunmadığını söyledi. Doğrudan (native) denendiğinde TF, hata olmasa bile her komuttan sonra kesme oluşturur. Hoca bu davranışı daha önce benzetimde denediğini belirtti.

Bir öğrencinin yazılı olarak paylaştığı cevap da okundu: bayraklar yığına atılır, AX'e okunur ve AX üzerinde işlem yapılır. Hoca, yeri doğruysa bunun 8. bit olduğunu, 1 yapmak için bu yolun doğru olduğunu söyledi. 0 yapmak için de AND işlemiyle 8. bit 0 yapılır. Bu soru Örnek Sorular bölümünde kod olarak da verilmiştir.

## 7. Kesme vektör tablosunu değiştirme: DIV0 örneği

Slayt başlığı "Kesme Vektör Tablosunu Değiştirme", örnek ise "DIV0 kesme alt programının adresini değiştirme"dir (ekrandan, 00:40:00).

### 7.1 Ön bilgi: sıfıra bölmede dönüş adresi

Bir alt program `CALL` ile çağrıldığında, iş bitip dönülünce çağrının bir sonraki satırına gelinir. Hoca, sıfıra bölme kesmesi için özel bir durum olduğunu anlattı: bütün kesme istekleri, bütün far ve near çağrılar bir sonraki komuta döner; yalnız sıfıra bölme kesmesinde `IRET` ile dönüş, sıfıra bölmeyi oluşturan satırın kendisine yapılır. Bu yüzden durum ele alındıktan sonra işlemcinin bir sonraki komuta geçebilmesi için kesme alt programında ek bir işlem gerekir.

> **Ek bilgi (derste anlatılmadı):** Bu davranış işlemci kuşağına göre değişir. Intel belgelerine göre büyük olasılıkla 8086/8088'de sıfıra bölme kesmesinde yığına bölmeden sonraki komutun adresi atılır; 80286 ve sonrası işlemcilerde ise hatayı oluşturan bölme komutunun adresi atılır. Derste kullanılan DOSBox ortamında dönüş adresinin `DIV BX` komutunu gösterdiği debug çıktısında görülmüştür (bkz. 7.6).

### 7.2 Örneğin özellikleri

Hoca üç noktayı vurguladı:

- Örnek, kesme vektör tablosuna kendi kesme alt programını yalnız program çalıştığı sürece yerleştirir; program sonlanırken eski içeriği geri yazar. İşletim sistemi seviyesinde kalıcı bir kesme alt programı yerleştirmek için özel fonksiyonlar vardır; bu örnek öyle değildir.
- Örnek sıfıra bölme kesmesiyle ilgilidir; dönüş adresinin bir sonraki komuta taşınması gerekir.
- Tablonun 0. gözü değiştirilir. Tablo bellek uzayının 0 adresinden başlar; gözün düşük adreslerinde offset, yüksek adreslerinde segment vardır.

### 7.3 Program yapısı ve veri tanımları

Kodun veri kısmı şöyledir (ekrandan, 00:45:00):

```text
        PAGE 60,80
        TITLE ornek____

STACKSG SEGMENT PARA STACK 'STACK'
        DW 12 DUP(?)
STACKSG ENDS

DATASG  SEGMENT PARA 'DATA'
DIZI1       DW 1,2,3,4,5,6,7
DIZI2       DW 1,0,3,4,5,6,7
ELEMAN      DW 7
OLDOF       DW 0
OLDSG       DW 0
DATASG ENDS
```

Hoca yığın segmenti için şunları hatırlattı: fonksiyonlarda yığına atılacak her şeyi taşıyacak boyutta olmalı, çok küçük olmamalı ve çift sayıda bayt kaplamalıdır. `DW 12 DUP(?)` 12×2 = 24 bayttır; `DW` ile tanımlandığında sorun yoktur, `DB` ile tanımlanırsa sayı mutlaka çift olmalıdır.

İki dizinin karşılıklı elemanları bölünecektir: `DIZI1[i] / DIZI2[i]`. İlk bölme başarılı olur, ikinci bölmede $2/0$ işlemi vardır. Matematikte "bir şey bölü sıfır sonsuza gider" denir; burada da sonucun yazılabilecek en büyük 16 bitlik sayı, yani `0FFFFH` olması istenir. Diziler 7 elemanlıdır.

`OLDOF` ve `OLDSG` değişkenleri, program süresince değiştirilecek tablo gözündeki orijinal 4 baytı saklamak içindir. Kendi kesme alt programı yerleştirilmeden önce eski değerlerin yedeği alınır, program sonlanırken yedek geri yazılır ve sistem işletim sistemine öyle devredilir.

### 7.4 Kesme alt programı ve ana program

Kod segmentinin devamı şöyledir (ekrandan, 00:50:00, 01:00:00 ve 01:05:00):

```text
CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

NEWINT  PROC FAR
        PUSH BP
        MOV BP, SP
        MOV AX, [BP+2]
        ADD AX, 2
        MOV [BP+2], AX
        MOV AX, 0FFFFH
        POP BP

        IRET
NEWINT  ENDP

BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DATASG
        MOV DS, AX

        XOR AX, AX
        MOV ES, AX
        MOV AX, WORD PTR ES:[0]
        MOV OLDOF, AX
        MOV AX, WORD PTR ES:[2]
        MOV OLDSG, AX
        LEA AX, NEWINT
        MOV WORD PTR ES:[0], AX
        MOV AX, CS
        MOV WORD PTR ES:[2], AX

        STI
        XOR SI, SI

        MOV CX, ELEMAN

TEKRAR:
        XOR DX, DX
        MOV AX, DIZI1[SI]
        MOV BX, DIZI2[SI]
        DIV BX
        ADD SI, 2

        LOOP TEKRAR

        XOR AX, AX
        MOV ES, AX
        MOV AX, OLDOF
        MOV WORD PTR ES:[0], AX
        MOV AX, OLDSG
        MOV WORD PTR ES:[2], AX

        RETF
BASLA   ENDP

CODESG  ENDS
        END BASLA
```

`NEWINT` fonksiyonu da bu kod segmentinin içindedir. Program derlenip belleğe yüklenince nereye yerleşeceği baştan belli değildir; yüklendikten sonra belli olur. Bu yüzden `NEWINT`'in adresi tabloya program çalışırken yazılır. `NEWINT` 0 adresi bölgesinde değil, belleğin boş bir yerinde ayrılan segmenttedir; tablodan uzaktır. Hoca bunun far call'a benzediğini, bu yüzden hem segment hem offset değerinin gerektiğini söyledi.

Ana programın ilk üç satırı (`PUSH DS`, `XOR AX,AX`, `PUSH AX`) işletim sistemine dönüş değerlerini hazırlar. Sonraki iki satır, tanımlanan veri segmentinin DS olarak kullanılmasını sağlar.

**Yedekleme.** Önce AX sıfırlanır ve ES'ye AX atanır.

**Soru:** Neden ES'ye doğrudan 0 atanmadı da AX üzerinden dolambaçlı bir yol izlendi? **Cevap:** Segment yazmaçlarına doğrudan sayısal değer atanamaz; değer AX gibi bir genel amaçlı yazmaç üzerinden verilmelidir. Hoca öğrencinin bu cevabını doğruladı.

Normalde `[0]` gibi bir erişim veri segmentinden, yani DS'nin 0 offsetinden yapılır. `ES:` öneki varsayılanı geçersiz kılar; erişim ES segmentinin 0 numaralı offsetine yapılır. ES=0 olduğu için bu fiziksel 00000H adresidir. Hoca "0 segmentinin 0 offsetinde ne var?" diye sordu; cevap kesme vektör tablosudur. 00000H adresinde sıfıra bölme gözünün düşük anlamlı kısmı, yani daha önce yerleştirilmiş fonksiyonun offset değeri vardır. Bu değer AX'e alınıp `OLDOF`'a saklanır. Aynı işlem ES:[2] için yapılır: fiziksel 00002H adresindeki segment değeri okunup `OLDSG`'ye saklanır.

**Yeni adresi yazma.** `LEA` (load effective address) ile `NEWINT` etiketinin kendi segmenti içindeki offseti alınır. Bu örnekte `NEWINT` kod segmentinin başında olduğu için değer 0'dır; aşağıda tanımlanmış olsaydı önündeki kod kadar ileride olurdu. `LEA`, bu değeri elle hesaplamadan almak için kullanılır. Offset ES:[0]'a, yani fiziksel 0 adresine yazılır. Segment değeri için şu düşünülür: program şu anda bu kod segmentinde çalıştığına göre `NEWINT`'in segmenti zaten CS'dedir. CS de AX üzerinden alınıp fiziksel 2 adresine yazılır.

**Döngü.** Eleman sayısı CX'e yüklenir. Diziler word tanımlı olduğu için 16 bitlik bölme yapılır: DX:AX 32 bitlik sanal yazmacı BX'e bölünür. DX sıfırlanır, birinci dizinin elemanı AX'e, ikinci dizinin elemanı BX'e alınır, `DIV BX` yapılır ve sonraki elemana geçmek için SI 2 artırılır. Hoca, BX'e ayrıca atama yapmaya belki gerek olmadığını, biraz dolambaçlı olduğunu söyledi. Sıfıra bölme olmasaydı döngü bitip program sonlanırdı; bu verilerde ikinci elemanlarda sıfıra bölme kesmesi oluşur ve tabloya yerleştirilen `NEWINT` otomatik olarak çağrılır.

**Geri yükleme.** Ana programın sonunda yedeklenen offset ve segment değerleri AX üzerinden alınıp fiziksel 00000H ve 00002H adreslerine geri yazılır.

### 7.5 Kesme alt programında yığın ve BP kullanımı

`NEWINT`'e girildiğinde yığında şunlar vardır (ekrandan, 01:00:00): en altta işletim sistemine dönüş segmenti (OS CS, başta PUSH DS ile atılan) ve işletim sistemine dönüş IP'si (OS IP = 0), onun üstünde kesme sırasında atılan FLAG, ana programın CS'si (ANA CS) ve ana programda kalınan yerin IP'si (ANA IP). Alt program BP'yi de yığına atınca en üstte BP olur ve hem BP hem SP bu gözü gösterir.

Normalde `DIV BX` bir sonraki komuta dönülmesi gereken bir işlem olsaydı sorun olmazdı. Sıfıra bölmede dönüş `DIV BX` satırının başına yapıldığı için yığındaki ana IP değeri artırılmalıdır.

**Soru:** IP ne kadar artırılmalı? **Cevap:** `DIV BX` komutunun kapladığı alan kadar. Bir öğrencinin önerdiği gibi komutun boyuna bakılır; 2 bayttır. Bu yüzden IP 2 artırılır.

Hoca bunu, "SMD dersi" dediği önceki bir derste görülen yığından parametre aktarımına benzetti: yığından gelen bir değer üzerinde işlem yapılıp sonuç yine yığına yazılır. Bunun için yığında sabit bir referans gerekir ve BP kullanılır. BP geçici olarak kullanıldığı için orijinal değeri korunmalıdır. Temel kural şudur: alt programda dönüş değeri olarak kullanılmayan, yalnız geçici işler için kullanılan yazmaçlar, ana programdaki değerlerini korumak için alt programa girer girmez yığına atılır ve çıkarken ters sırada çekilir.

**Neden yalnız SP değil de BP?** Alt program içinde yığına bir şeyler PUSH ya da POP edilebilir; o zaman SP hareket eder ve sabit bir referans kalmaz. BP bir kez PUSH edilip `MOV BP, SP` yapılınca sabit bir referans elde edilir.

**Soru:** EXE ve COM tipi programlarda yığının dibi yüksek adres midir, düşük adres midir? **Cevap:** Yığına her değer atıldığında SP 2 azalır. Yani yığına ilk atılan değer, yığının dibi, daha yüksek adrestedir; yığının üstü daha düşük adreslerdedir.

> **Hocanın vurgusu:** Yığının dibi yüksek adreste, üstü düşük adrestedir; bu çok önemli bir noktadır ve kaçırılmamalıdır.

Buna göre ana IP, sabit referans BP'ye göre +2 ileridedir. `MOV AX, [BP+2]` ile bu değer AX'e okunur.

**Soru:** Köşeli parantez içinde varsayılan segment her zaman DS midir; [BP+2] ile yığından nasıl okunuyor? **Cevap:** Hayır. Dolaylı adreslemede köşeli parantezin içinde BX, SI, DI ya da sabit (immediate) bir değer varsa DS kullanılır. BP varsa yığın segmenti (SS) kullanılır. Hoca bunu ekranda çizdi (ekrandan, 01:05:00): "BX, SI, DI, imm → DS" ve "BP, SP → SS". Bu yüzden yukarıda ES:[0] erişiminde varsayılan DS'yi ezmek için `ES:` öneki kullanılmıştı.

> **Ders sonrası not:** Hoca çizimde SP'yi de SS ile eşledi. 8086'da SP büyük olasılıkla köşeli parantez içinde adresleme yazmacı olarak kullanılamaz; SP ile yapılan yığın erişimleri (PUSH, POP, CALL, RET) zaten SS'yi kullanır. Köşeli parantez içi adreslemede SS'yi varsayılan yapan yazmaç BP'dir.

Yığında her seferinde bir word atılıp çekildiği için adresler ikişer ikişer değişir; [BP+2] hemen bir sonraki göze denk gelir. Sonra AX 2 artırılır ve aynı sabit referansa geri yazılır. Artık ana IP değeri +2 olmuştur; dönüldüğünde `DIV BX` geçilmiş olur. Ardından AX'e dönüş değeri olan `0FFFFH` atılır, BP yığından orijinal değeriyle geri çekilir ve `IRET` ile dönülür. `POP BP`'den sonra SP ana IP gözünü gösterir. `IRET` en üstteki değeri (artık `DIV BX`'in 2 ilerisi) IP'ye, sonrakini CS'ye (orijinal CS), sonrakini bayrak yazmacına (orijinal bayraklar) atar. Sonuçta program `DIV BX`'ten sonraki komutla devam eder (ekrandan, 01:05:00).

### 7.6 DOSBox'ta adım adım çalıştırma

Program DOSBox'ta debug ile adım adım çalıştırıldı. Altyazıya göre başlangıçta 0 segmentinin 0 offsetinde, yani tablonun 0. gözünde, offset 1060H ve segment F000H değerleri vardı; bunlar `OLDOF` ve `OLDSG`'ye yedeklendi. <!-- BELİRSİZ: 1060H ve F000H değerlerini gösteren kare yok; değerler altyazıdan alındı. --> `LEA` komutundan sonra AX'e ne atanacağı soruldu; cevap 0'dı, çünkü `NEWINT` kod segmentinin 0 offsetindedir. Kod segmenti 076FH idi; bu değer de 2H adresine yazıldı. Tablonun 0. gözü dökülünce (dump) yeni adresin, yani kod segmentinin 0 offsetinin yerleştiği görüldü. Hoca, `STI` komutuna bu örnekte gerek olmadığını ama yine de konduğunu söyledi.

İlk bölme başarıyla yapıldı. İkinci elemanda bölme yapılınca program `NEWINT`'in başına geldi. Debug çıktısında (ekrandan, 01:10:00) o anda yazmaçlar CS=076F, SS=076A, DS=076C, SP=000E, IP=0000 idi. `d ss:e` dökümünde yığında sırasıyla ana programa dönüş IP'si (004BH), ana programa dönüş segmenti (076FH), bayrak yazmacı, işletim sistemine dönüş offseti (0000H) ve işletim sistemine dönüş segmenti görüldü. `PUSH BP`'den sonra SP=000C oldu, `MOV BP,SP` ile BP=000C yapıldı ve `MOV AX,[BP+2]` komutunun okuduğu değer `SS:000E=004B` idi. IP 2 artırılıp geri yazılınca yığındaki değer 4BH'den 4DH'ye çıktı:

$$004\text{BH} + 2 = 004\text{DH}$$

AX'e `0FFFFH` atandı, BP çekildi ve `IRET` ile `DIV BX`'ten sonraki `ADD SI,2` satırına dönüldü. Böylece $2/0$ işleminin sonucu `0FFFFH` olarak elde edildi; diğer elemanlar da benzer şekilde işlendi. Python ile denetlendiğinde bölümler sırasıyla 1, FFFFH, 1, 1, 1, 1, 1 olur.

> **Hocanın vurgusu:** Bu örnek kavranırsa diğer bütün kesme tipleri için kesme vektör tablosunun nasıl değiştirileceği ve kesme alt programının nasıl yazılacağı kabaca görülmüş olur. Neredeyse bütün far ve near çağrılar ve kesmeler bir sonraki satıra döner; özel durum yalnız sıfıra bölmedir ve dönüş değerini `DIV BX`'in boyu olan 2 kadar artırmak gerekir.

**Soru:** (Bir öğrencinin sorusu altyazıda yok; büyük olasılıkla sıfıra bölmeye yol açan komutun programın son komutu olması durumu soruldu.) **Cevap:** Hoca, program belleğin en sonuna yerleşmiş olsa bile programı sonlandırmak için en sonda bir `RETF` (ya da `RET`) bulunması gerektiğini, bu yüzden genel yazım kurallarına uyulduğunda sıfıra bölmeyi oluşturan komutun programın son komutu olamayacağını söyledi. <!-- BELİRSİZ: Soru metni altyazıda yok, yalnız cevap var (01:12:07). -->

## 8. Ek donanımsız INTR kullanımı: sabit tip, genişletme ve daisy chain

Aradan sonra hoca, az önceki örneğin yazılımsal işlemler sonucunda oluşan bir kesme olduğunu, bu derste asıl ilgilenilen grubun donanım kesmeleri olduğunu söyledi. NMI slaytı şöyledir (ekrandan, 01:25:00): "NMI ucu aktif olduğunda (NMI yükselen kenar tetikleme ile çalışan bir giriştir), kesme vektör tablosunun 008H adresinde yer alan TİP2 kesmesi işlenir. Kesme vektör adresi µP tarafından içeride çözümlenir."

$$4 \times 2 = 8 = 008\text{H}$$

INTR ise seviye tetiklemelidir. İşlemci isteği değerlendirirken uygunsa $\overline{INTA}$ ucunda iki sıfır geçişi oluşturur: ilki boş okuma, ikincisinde D0-D7'de vektör tipi beklenir. Bazı başka işlemciler tipi ilk onayda alabilir; 8259'da bu ayrı bir ayar bitiyle seçilir.

### 8.1 Sabit tipli devre

Slayttaki devrede (altyazıya göre) sağ tarafta pull-up dirençler ve DIP anahtarlar vardır. DIP anahtar ya sol taraftaki ucu sağ tarafa bağlar ya da bağlantıyı koparır. Bütün anahtarlar kapalıdır (uç 0'a bağlı), yalnız en baştaki anahtar bağlantıyı koparmıştır; pull-up direnç yüzünden o hat lojik 1'dedir. Butonlarda görülen pull-up mantığının aynısıdır. Bu değerler bir tampona (latch) bağlıdır; tamponun enable ucuna işlemcinin $\overline{INTA}$ ucu bağlıdır. INTR'ye bir istek gelir ve $\overline{INTA}$ 0 olursa, her $\overline{INTA}$ sıfır geçişinde veri uçlarına 01H gider. Bu yapılandırmada INTR'ye hangi kaynaktan istek gelirse gelsin 01H tipi kesme oluşur. Hoca önce değeri 10H diye okudu, sonra tersten okuduğunu söyleyerek 01H diye düzeltti. <!-- BELİRSİZ: Bu devrenin karesi yok; 01H değeri ve anahtarların konumu altyazıdan alındı. -->

### 8.2 74ALS244 ve 74ALS30 ile INTR genişletme

Slayt "Donanımsal Kesmeler INTR Genişletme" (ekrandan, 01:30:00) şu devreyi gösterir: D0-D7 düşük veri yoluna bir 74ALS244 tampon (U1) bağlıdır. Tamponun 1G ve 2G etkinleştirme uçları $\overline{INTA}$'ya bağlıdır. Tampon girişlerine aktif-0 $\overline{IR0}$-$\overline{IR6}$ istekleri gelir; D7'ye karşılık gelen giriş 10K pull-up direnciyle VCC'ye bağlıdır. Aynı yedi istek ve pull-up hattı 8 girişli 74ALS30 NAND kapısına (U2) girer; NAND çıkışı INTR'ye bağlıdır.

Kesme istekleri aktif 0'dır. Hiç istek yoksa bütün girişler 1'dir, NAND çıkışı 0 olur ve INTR'de istek oluşmaz. Herhangi bir istek 0 olursa NAND çıkışı 1 olur ve INTR'de istek oluşur. $\overline{INTA}$ geldiğinde tampon, isteklerin durumunu veri yoluna koyar; D7 her zaman 1'dir.

- Yalnız IR0 etkin: D0=0, diğerleri 1 → $1111\,1110_2$ = FEH.
- Yalnız IR6 etkin: D6=0 → $1011\,1111_2$ = BFH.
- IR0 ve IR6 birlikte etkin: D0=D6=0 → $1011\,1110_2$ = BEH.

Bu üç değer Python ile denetlendi. Bu devre, isteklerden yalnız biri, herhangi ikisi, herhangi üçü ya da hepsi aynı anda geldiğinde her birleşim için farklı bir kesme tipi üretir.

### 8.3 Daisy chain

Farklı kaynaklardan gelen istekler daisy chain mantığıyla da değerlendirilebilir. Slayttaki örnekte iki 8255 vardır. Mod 1'de kullanıldıklarında her birinin INTRA ve INTRB uçları kesme isteği oluşturabilir. Bu istekler aktif 1 olduğu için dört uç OR'lanarak tek bir uca, işlemcinin INTR ucuna bağlanır.

**Soru:** INTR'ye istek geldi; ama birinci 8255'in grup A'sından mı, grup B'sinden mi, ikinci 8255'in grup A'sından mı, grup B'sinden mi geldi? Bu nasıl anlaşılır? **Cevap:** Dört kaynağın ortak bir kesme tipi vardır. Kesme alt programında çevre birimlerinin durum yazmaçları okunur: örneğin birinci 8255'in durumu okunup INTRA'ya, sonra INTRB'ye, sonra diğer 8255'e bakılır. Hangi bitte istek varsa ilgili gruptan okuma yapılır. A ve B aynı anda gelmiş olabilir; önce A okunuyorsa A'ya yazılımsal olarak öncelik verilmiş olur. Yani kontrol sırası daisy chain'deki önem sırasını belirler.

Bu üç yaklaşım, yardımcı devre kullanmadan basit lojikle INTR'nin nasıl tetikleneceğini, kesme tipinin nasıl verileceğini ve birden fazla kaynağın nasıl birlikte kullanılacağını gösterir.

## 9. 8259A programlanabilir kesme denetleyicisi

Slayttaki tanım şöyledir (ekrandan, 01:35:00):

- 8259A programlanabilir kesme kontrol devresidir.
- Kesme isteklerine öncelik atayabilir (priority encoding).
- Tek başına 8 farklı kesme vektörü sağlar.
- Master (1)/Slave (8) formunda 64 farklı kesme vektörü sağlar.

8259, birden fazla kaynaktan gelen kesme isteklerini değerlendirir: tek bir 8259 ile 8'e kadar, kaskat (master-slave) bağlantıyla 64'e kadar kaynak. Kaskatta bir master vardır; masterın 8 kesme istek ucunun her birine bir 8259 daha bağlanır ve $8 \times 8 = 64$ kaynak elde edilir. Her isteğe hangi vektör tipinin verileceği 8259'a programlanır. Öncelik tanımlanabilir, bazı kesmeler maskelenerek açılıp kapatılabilir. Yani bir önceki bölümde basit lojikle yapılan işlerin hepsini donanımsal olarak yapan bir yardımcı devredir.

### 9.1 Uçlar

- 8259 8 bitlik bir cihazdır; I/O uzayına ardışık çift ya da ardışık tek adreslere yerleştirilir.
- Tek bir adres ucu (A0) vardır; I/O uzayında 2 bayt kaplar, ama erişilebilen iç yazmaç sayısı ikiden çok fazladır.
- 8 veri ucu (D0-D7) vardır.
- IR0-IR7: 8 kesme istek ucu.
- $\overline{RD}$ ve $\overline{WR}$ işlemciden gelir; $\overline{CS}$ adres çözümleme devresinin çıkışına bağlanır.
- INT ucu işlemcinin INTR ucuna bağlanır. 8 kaynaktan gelen istekler önceliklendirilip maskelendikten sonra seçilen istek bu uçla işlemciye iletilir.
- $\overline{INTA}$ ucu işlemcinin $\overline{INTA}$ ucuna bağlanır.
- CAS0-CAS2: kaskat uçları. Bir kod çözücü girişi gibi düşünülebilir; $2^3 = 8$ slave 8259'dan birini seçer. $\overline{SP}/\overline{EN}$ (slave program enable) ucuyla birlikte kullanılır.

Derste her sistemde tek bir 8259 kullanılacaktır. Bu yüzden $\overline{SP}/\overline{EN}$ ucu lojik 1'e bağlanır; bu, tek 8259'un master olacağı anlamına gelir.

### 9.2 İç yapı

Slayttaki iç yapı şöyledir (ekrandan, 01:40:00): IRQ0-IRQ7 girişleri Interrupt Request Register'a (IRR) gelir. IRR'nin çıkışı Priority Resolver'a, oradan Interrupt Service Register'a (ISR) bağlıdır. Altta bunların hepsine bağlı Interrupt Mask Register vardır. Üstte INT çıkışını üreten ve $\overline{INTA}$ girişini alan Control Logic bulunur; birimler bir iç veri yoluyla (Internal Bus) haberleşir. Yani 8259, uçlardaki istekleri kendi iç yazmacına kopyalar, aralarında öncelik tanımlar ve maskeleme ile bazılarını açıp kapatır.

### 9.3 Bağlantı ve kesme akışı

8259'un veri uçları işlemcinin D0-D7 uçlarına bağlanır. Ardışık çift adreslere yerleştirildiğinde işlemcinin A1 adres ucu 8259'un A0 ucuna bağlanır. $\overline{CS}$ adres çözümlemeden, $\overline{RD}$ ve $\overline{WR}$ işlemciden gelir, $\overline{SP}/\overline{EN}$ lojik 1'e bağlanır, INT ve $\overline{INTA}$ işlemciye bağlanır ve 8 IR ucuna 8 farklı kaynak bağlanabilir.

IR0-IR7'den birine (seviye çalışmada belli bir süre lojik 1 olarak) istek gelince akış şöyledir:

1. 8259, birden fazla istek gelmişse programlanabilir önceliklendirme ve maskelemeyi uygular, en öncelikli isteği belirler ve INT ucuyla işlemcinin INTR ucuna istek gönderir.
2. İşlemci yürüttüğü komutu bitirir. Kesmeyi karşılayabiliyorsa (örneğin IF=1 ise) bir sonraki komuta geçmeden $\overline{INTA}$ ile cevap verir.
3. 8259 ilk $\overline{INTA}$ darbesini alınca ISR ve IRR'deki ilgili bitleri değiştirir.
4. 8259 ikinci $\overline{INTA}$ darbesini bekler; onu da alınca öncelik verdiği kesme için programlanmış vektör tipini veri yoluna koyar. Böylece kesme isteğinin denetimi tamamlanır.

İki sonlandırma modu vardır:

- **Otomatik EOI (automatic end of interrupt):** ilgili ISR biti kendiliğinden 0 yapılarak istek kapatılır (değerlendirilmiş sayılır).
- **EOI (end of interrupt):** ISR'nin ilgili bitini sıfırlamak programcının görevidir.

Derste otomatik EOI modu kullanılacaktır. Hangi IR isteğinin hangi vektör tipini tetikleyeceği önceden programlanır; önceliklendirmeye göre istek INTR ucuna aktarılır ve ikinci $\overline{INTA}$'da programlanan tip veri yoluna çıkar.

## 10. 8259A ayar yazmaçları: ICW ve OCW

8259'un iki yazmaç grubu vardır:

- **Initialization Control Word (ICW):** başlangıçta nasıl ayarlanacağını belirtir.
- **Operational Control Word (OCW):** çalışma sırasındaki ayarları içerir.

Erişim tablosu şöyledir (ekrandan, 01:45:00):

| CS | A0 | Initialization |
|----|----|----------------|
| 0 | 0 | ICW1 |
| 0 | 1 | ICW2, ICW3, ICW4 |
| 1 | X | Not Address |

Bu, 8251'de bir akış şemasıyla hangi iç yazmaca erişileceğinin belirlenmesine benzer. A0=0 iken yapılan ilk erişim ICW1'edir. Sonra A0=1 iken yapılan ilk erişim ICW2'ye gider. ICW1'de 8259'ların kaskat mı tek mi çalışacağını belirten bir ayar vardır; kaskatta ICW3'e bir şey yazılır, tek çalışmada bu adım atlanır. ICW1'de ICW4'ün kullanılıp kullanılmayacağı da belirtilir; kullanılacaksa A0=1 iken yapılan sonraki erişim ICW4'e gider ve akış biter.

> **Ders sonrası not:** Altyazıda hoca kaskat/tek ve ICW4 ayarlarının "ICW2'de" olduğunu söylüyor (01:45:48, 01:46:10). Slayta göre (ekrandan, 01:50:00) bu bitler (SNGL ve IC4) ICW1'dedir; doğrusu ICW1'dir.

Ders kapsamında ICW1 ve ICW2 kullanılacak, tek 8259 olduğu için ICW3 atlanacak, otomatik EOI ve 8086 kullanımı (vektör tipinin ikinci $\overline{INTA}$'da verilmesi) için ICW4 de kullanılacaktır. Akış şöyledir: A0=0 ile ICW1 yazılır (tek mod, ICW4 gerekli), A0=1 ile ICW2 yazılır, A0=1 ile ICW4 yazılır ve ayar tamamlanır.

### 10.1 ICW1

Slayttaki ICW1 tablosu şöyledir (ekrandan, 01:50:00):

| AD0 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|-----|----|----|----|----|----|----|----|----|
| 0 | 0 | 0 | 0 | 1 | LTIM | 0 | SGNL | IC4 |

- D7-D5: x86 için 0.
- D4: sabit 1.
- D3 (LTIM): 1 seviye tetikleme (level trigger), 0 kenar tetikleme (edge trigger).
- D2: sabit 0.
- D1 (slaytta "SGNL", yaygın adı SNGL): 1 tek (single), 0 kaskat.
- D0 (IC4): 1 ICW4 gerekli, 0 ICW4 gerekmez.

LTIM biti için hoca şu ayrımı yaptı: 8259 normalde işlemcinin seviye tetiklemeli INTR ucuna bağlıdır; kenar tetiklemeli olan uç NMI'dır. Ama 8259'un IR girişleri kenar tetiklemeli olarak programlanabilir. O zaman 8259, IR girişindeki bir kenar geçişini, işlemcinin INTR ucunda belli bir süre kalan bir seviye isteğine dönüştüren yardımcı devre gibi çalışır.

> **Hocanın vurgusu:** 8259'daki bu ayar 8086'nın INTR ucunu kenar tetiklemeli yapmaz; yalnız 8259'un IR girişlerinin kenarla tetiklenmesini sağlar. İkisi arasında fark vardır.

> **Ek bilgi (derste anlatılmadı):** D2 bitinin adı ADI'dir (call address interval) ve büyük olasılıkla yalnız 8080/8085 modunda anlamlıdır; 8086 modunda dikkate alınmaz. Derste bu bit sabit 0 olarak kullanıldı.

### 10.2 ICW2

ICW2 tablosu şöyledir (ekrandan, 01:50:00):

| AD0 | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|-----|----|----|----|----|----|----|----|----|
| 1 | T7 | T6 | T5 | T4 | T3 | T2 | T1 | T0 |

Slayttaki açıklama: "T7=T0 is the assign to IR0, Vector address for ISR".

> **Hocanın vurgusu:** ICW2 çok önemlidir; bunu anlarsak 8259'u çözüyoruz.

ICW2'ye yazılan 8 bitlik değer, 8259'un üreteceği kesme tiplerine karşılık gelir. T2, T1 ve T0 bitleri otomatik olarak doldurulur: isteği gelen IR ucunun numarası (IR0 için 000, IR7 için 111) bu bitlere yazılır. Programcı yalnız T7-T3 bitlerini belirler. Böylece bir IR ucu tetiklendiğinde oluşan kesme tipi, T7-T3 ile IR numarasının birleşimidir.

**Örnek (derste sözlü ve tahtada):** T7-T3 = 10000 yazılmış olsun. IR4'e istek gelirse alt üç bit 100 olur:

$$1000\,0100_2 = 84\text{H}$$

Hoca önce "14H" dedi, sonra bitleri dörtlü ayırıp 84H olarak düzeltti. Aynı ayarla IR7'ye istek gelirse alt üç bit 111 olur ve tip 87H'dir. IR0 için 80H, IR1 için 81H, IR2 için 82H oluşur. IR numarasıyla tip arasındaki ilişki Python ile denetlendi.

### 10.3 ICW3, ICW4 ve OCW'ler

ICW3 ve ICW4'ün master/slave (kaskat) durumlarıyla ilgili kısımları derste kullanılmaz. ICW4'te iki bit 1 olmalıdır: otomatik EOI etkin olmalı ve 8086 kullanıldığı için 8086 modu seçilmelidir. Hocanın özeti: ICW4'e 03H yazılır.

> **Ek bilgi (derste anlatılmadı):** ICW4'te büyük olasılıkla D1 biti AEOI (otomatik EOI), D0 biti µPM (1 = 8086/8088 modu, 0 = 8080/8085 modu) bitidir. Bu yüzden $0000\,0011_2$ = 03H her iki ayarı birlikte seçer.

OCW'ler maskeleme ve öncelik atamayla ilgilidir. Slayttaki OCW tabloları şöyledir (ekrandan, 01:55:00):

- OCW1 (AD0=1): D7-D0 = M7-M0. "Mi: Interrupt mask, 1=mask set, 0=mask reset".
- OCW2 (AD0=0): D7=R (Rotate), D6=SL (Specific), D5=EOI, D4=0, D3=0, D2-D0=L2-L0 (IR Level to be acted Upon (0-7)).
- OCW3 (AD0=0): D7=0, D6=ESMM, D5=SMM (Special Mask Mode), D4=0, D3=1, D2=P (Poll Command), D1=RR, D0=RIS (Register Read Mode).

Maskeleme için OCW1 kullanılır; diğerleri kaskat modla da ilişkilidir. Derste tek 8259 master modda ve otomatik EOI ile kullanılacağı için OCW'lerle ilgili bir işlem yapılmayacaktır.

## 11. 8259A ile buton sayacı örneği

### 11.1 Donanım

Sistemde işlemciyle konuşan yalnız bir 8259 vardır. 8259'un IR0 ucuna pull-down ile çalışan bir buton bağlıdır: butona basılınca uca lojik 1 gelir ve kesme isteği oluşur.

Cihaz çift adreslere yerleştirildiği için adres çözümlemede A0=0 olmalıdır; işlemcinin A1 ucu doğrudan 8259'un adres ucuna bağlıdır. Kod çözücünün Y0 çıkışının seçilmesi için A2, A3 ve A4 0 olmalıdır. A5 ve A6 1 olmalıdır. A7 doğrudan aktif-0 bir uca bağlıdır, o da 0 olmalıdır. <!-- BELİRSİZ: Adres çözümleme devresinin karesi yok; bit değerleri altyazıdan alındı. -->

$$A7\ldots A0 = 0110\,00x0_2 \Rightarrow 60\text{H (A1=0)},\ 62\text{H (A1=1)}$$

Yani 8259, 60H'dan başlayan ardışık çift adreslere, 60H ve 62H'ye yerleştirilmiştir.

### 11.2 Amaç

Butona her basıldığında AX yazmacı kesme temelli olarak 1 artırılacaktır. "Her basıldığında" kenar tetiklemeyi kasteder: tuş basılı tutulduğu sürece değil, yalnız basıldığı anda AX artmalıdır. Butondan tetiklenecek kesme 40H tipinde olacaktır. Bu bir olay sayıcıdır (event counter): butona kaç kez basıldığı sayılır. Hocanın benzetmesiyle, buton ayakkabının altına bağlanırsa adım sayıcı gibi kullanılabilir.

### 11.3 Kod

Proteus'taki kodun ilgili kısmı şöyledir (ekrandan, 02:00:00 ve 02:05:00):

```text
NEWINT  PROC FAR
        PUSH BP
        MOV BP, SP
        INC AX
        POP BP
        IRET
NEWINT  ENDP

START PROC FAR
        XOR AX, AX
        MOV ES, AX
        MOV AL, 40H
        MOV AH, 4
        MUL AH
        MOV BX, AX
        LEA AX, NEWINT
        MOV WORD PTR ES:[BX], AX
        MOV AX, CS
        MOV WORD PTR ES:[BX+2], AX

MOV AL, 13H
OUT 60H, AL
MOV AL, 40H
OUT 62H, AL
MOV AL, 03H
OUT 62H, AL
STI
XOR AX, AX
ENDLESS:
JMP ENDLESS
RET
START ENDP
CODE    ENDS
        END START
```

Yapı DIV0 örneğine çok benzer: tabloya yüklenecek bir kesme alt programı, tabloyu değiştiren kısım, ana program ve 8259 ayarları vardır. Hoca, kodda kullanılmayan bir gecikme (delay) fonksiyonunu çıkardı. Ana programda polling ya da düğme okuma yoktur; yalnız 8259 ayarlanır ve sonsuz döngüye girilir.

> **Ders sonrası not:** Hoca bu örnekte programdan çıkarken eski vektör değerlerinin geri yazılmadığını, yazılsa iyi olacağını söyledi ve "kötü örnek almayın, siz yazın" dedi.

**Vektör adresi.** 40H tipi için tablo adresi 40H ile 4 çarpılarak bulunur. `MUL AH` sonrası AX'te 40H×4 değeri vardır:

$$40\text{H} \times 4 = 100\text{H}$$

Bu değer BX'e kopyalanır. `NEWINT`'in offseti ES:[BX]'e, mevcut kod segmenti ES:[BX+2]'ye yazılır; böylece tablonun 40H numaralı gözünün offset ve segmenti doldurulmuş olur. Benzetimdeki yazmaç penceresinde BX=0100 görülür (ekrandan, 02:05:00).

**ICW1.** 60H adresinde A0=0'dır; erişim ICW1'e gider. Yazılan değer 13H'dir:

$$13\text{H} = 0001\,0011_2$$

D4=1, LTIM=0 (kenar tetikleme), D2=0, SNGL=1 (tek 8259), IC4=1 (ICW4 kullanılacak); D7-D5=0 (8086).

**ICW2.** 62H adresi A0=1 demektir. ICW3 kullanılmadığı için A0=1 iken yapılan ilk erişim ICW2'ye gider. 40H yazılınca IR0'dan 40H, IR1'den 41H, IR2'den 42H, …, IR7'den 47H tipinde kesme oluşur.

**ICW4.** A0=1 iken yapılan ikinci yazma, bu akışta ICW4'e gider. 03H ile otomatik EOI ve 8086 modu seçilir.

Ardından `STI` ile IF=1 yapılır, AX sıfırlanır ve sonsuz döngüye girilir. İşlemci başka bir şey yapmasa da tuşlar sayılır: her kesmede `NEWINT` AX'i 1 artırır.

> **Hocanın vurgusu:** 8259 ayarlarından sonra `STI` ile IF bayrağını 1 yapmak çok önemlidir.

### 11.4 Benzetimde karşılaşılan sorun

AX'in artırıldığı yere breakpoint konarak çalıştırıldı. İlk basışta kesme alt programına gelindi ve AX=1 görüldü, ama ikinci basışta gelinmedi. İncelenince `IRET` ile dönülen değerin bozuk olduğu görüldü. Neden, hocanın kodu gösterebilmek için yığın segmentini ve veri segmentini kapatmış olmasıydı: yığın segmenti olmayınca dönüş adresi doğru saklanamıyordu. Yığın segmenti geri konup ASSUME satırına `SS:STACKSG` eklendi; veri segmenti kullanılmadığı için DS ayarına gerek görülmedi. Tekrar çalıştırıldığında, üç kez basıp durdurunca AX'te 3 değeri görüldü. Hoca, fonksiyon çağrısı olmasa da kesmeden dönerken değerlerin yığın segmentinden çekildiğini, bu yüzden yığının gerekli olduğunu vurguladı ve bunu DIV0 örneğiyle ilişkilendirdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:47:36): Kesme vektör tablosuna erişmek için ES neden `MOV ES, 0` ile değil, önce `XOR AX,AX` sonra `MOV ES,AX` ile sıfırlandı?

> **Çözüm:** Segment yazmaçlarına doğrudan sabit sayı atanamaz; değer bir genel amaçlı yazmaç (AX) üzerinden verilir.

**Soru 2** (derste sözlü, 00:52:02): DIV0 örneğinde tablonun 0 ve 2 adreslerine yazıldı. İlgilenilen kesme tipi 10H olsaydı hangi adreslere yazılırdı?

> **Çözüm:** Her vektör tipi için 4 bayt ayrılır. Tip $n$'nin offseti $4n$, segmenti $4n+2$ adresindedir. Tip 0 için $4 \times 0 = 0$ ve 2H. Tip 10H için 10H = 16, $16 \times 4 = 64$ = 40H; segment 40H + 2 = 42H adresine yazılır. Hoca önce hesaptan emin olamadı, sonra 10H'nin 16 olduğunu hatırlatarak 40H ve 42H sonucunu doğruladı.

**Soru 3** (derste sözlü, 00:57:36): Sıfıra bölme kesmesinden `DIV BX` komutundan sonraki komuta dönmek için yığındaki IP ne kadar artırılmalıdır?

> **Çözüm:** `DIV BX` komutunun boyu kadar, yani 2 bayt. Kesme alt programında `PUSH BP`, `MOV BP,SP`, `MOV AX,[BP+2]`, `ADD AX,2`, `MOV [BP+2],AX` ile artırılır. Debug çıktısında değer 004BH'den 004DH'ye çıkmıştır (ekrandan, 01:10:00).

**Soru 4** (derste sözlü, 01:01:52): Köşeli parantezli dolaylı adreslemede varsayılan segment yazmacı nedir?

> **Çözüm:** İçeride BX, SI, DI ya da sabit değer varsa DS; BP varsa SS. Bu yüzden `[BP+2]` yığın segmentinden okur. Varsayılanı değiştirmek için `ES:` gibi segment öneki kullanılır.

**Soru 5** (derste sözlü, 01:00:24): EXE ve COM tipi programlarda yığının dibi yüksek adreste midir, düşük adreste mi?

> **Çözüm:** Yüksek adreste. Her PUSH'ta SP 2 azalır; ilk atılan değer en yüksek adreste, yığının üstü düşük adreslerdedir.

**Soru 6** (derste sözlü, 00:33:21): TF için özel bir komut yoktur. TF nasıl 1 ya da 0 yapılabilir?

> **Çözüm:** Derste verilen cevap: bayrak yazmacı yığına atılır, AX'e alınır, 8. bit OR ile 1 (ya da AND ile 0) yapılır ve bayrak yazmacı yığından geri yüklenir. Kod derste yazılmadı; aşağıdaki parça bu anlatıma göre ajan tarafından yazılmıştır ve derlenmemiştir:

```text
PUSHF
POP AX
OR  AX, 0100H     ; TF = 1 (bit 8)
PUSH AX
POPF

PUSHF
POP AX
AND AX, 0FEFFH    ; TF = 0
PUSH AX
POPF
```

**Soru 7** (derste sözlü, 01:07:18): DIV0 örneğinde `LEA AX, NEWINT` komutundan sonra AX'e ne atanır?

> **Çözüm:** 0. `NEWINT` kod segmentinin en başında olduğu için offseti 0'dır.

**Soru 8** (derste sözlü, 01:29:39): 74ALS244/74ALS30 INTR genişletme devresinde (aktif-0 istekler, D7 pull-up ile 1) yalnız IR0, yalnız IR6 ve IR0 ile IR6 birlikte etkin olduğunda hangi kesme tipleri oluşur?

> **Çözüm:** Yalnız IR0: $1111\,1110_2$ = FEH. Yalnız IR6: $1011\,1111_2$ = BFH. IR0 ve IR6: $1011\,1110_2$ = BEH.

**Soru 9** (derste sözlü, 01:32:30): İki 8255'in INTRA ve INTRB çıkışları OR'lanıp tek INTR ucuna bağlanmışsa isteğin hangi kaynaktan geldiği nasıl anlaşılır?

> **Çözüm:** Dört kaynağın ortak bir kesme tipi vardır. Kesme alt programında 8255'lerin durum yazmaçları sırayla okunur ve INTRA/INTRB bitlerine bakılır. Okuma sırası yazılımsal önceliği belirler.

**Soru 10** (derste sözlü, 01:51:44): ICW2'de T7-T3 = 10000 yazılmışsa IR4'e ve IR7'ye istek geldiğinde işlemciye hangi kesme tipi aktarılır?

> **Çözüm:** T2-T0 = IR numarası. IR4: $1000\,0100_2$ = 84H. IR7: $1000\,0111_2$ = 87H.

**Soru 11** (derste sözlü, 02:04:43): 8259 buton örneğinde kesme ilk basışta geldi, ikinci basışta neden gelmedi?

> **Çözüm:** `IRET` ile dönülen adres bozulmuştu. Kod gösterim için yığın segmenti kapatıldığından dönüş adresi ve bayraklar doğru saklanamıyordu. Yığın segmenti geri eklenince sayaç doğru çalıştı.

## Dersin Toparlaması

Bu derste kesme mekanizması tablonun içeriğinden donanıma kadar bir bütün olarak ele alındı. Kesme vektör tablosunun 00000H'den başlayan 1024 baytlık yapısı, her gözde düşük adreste offset ve yüksek adreste segment bulunması ve tip $n$ için $4n$/$4n+2$ adresleri tekrar edildi. DIV0 örneğinde bir tablo gözünün programla nasıl yedeklenip değiştirileceği, kesme alt programının yığında BP ile sabit referans kurarak dönüş adresini nasıl düzelttiği ve program bitince eski vektörün nasıl geri yazıldığı adım adım ve debug çıktısıyla gösterildi.

İkinci yarıda INTR ucu önce yardımcı devre olmadan (sabit tipli tampon, NAND ile genişletme, daisy chain), sonra 8259A ile kullanıldı. 8259A'nın uçları, iç yazmaçları, iki $\overline{INTA}$ darbeli kesme akışı ve ICW1/ICW2/ICW4 ayarları anlatıldı; ICW2'deki T7-T3 + IR numarası ilişkisi vurgulandı. Ders, ICW1=13H, ICW2=40H, ICW4=03H ayarlarıyla IR0'a bağlı butonun her basışında AX'i artıran kesme temelli bir sayaçla bitti. Hoca, kalan son derste RAM ve ROM bellek arayüzünün işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
