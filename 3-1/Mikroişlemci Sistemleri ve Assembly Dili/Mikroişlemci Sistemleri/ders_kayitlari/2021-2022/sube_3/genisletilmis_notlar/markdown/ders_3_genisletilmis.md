# Ders 3 Genişletilmiş Notu: 8086 İç Yapısı, Yazmaçlar, Adresleme Modları ve Uç Tanımları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 16 bitlik işlemci, 20 bitlik adres ve 1 MB adres uzayı
- 2. 8086 iç yapısı: EU ve BIU
- 3. Segment mimarisi neden var?
- 4. 8086 yazmaçları
- 5. Bayrak yazmacı
- 6. Fiziksel adres üzerine sorular
- 7. Real mod hafıza adresleme
- 8. Veri adresleme modları
- 9. Program hafızası adresleme
- 10. Yığın adresleme
- 11. 8086 uç tanımları
- 12. Yol tamponlama ve mandallama
- Örnek Sorular

## 1. 16 bitlik işlemci, 20 bitlik adres ve 1 MB adres uzayı

Önceki derste mikroişlemci mimarilerinde 4, 8, 16 bit kavramları ile veri yolu ve adres yolu tanıtılmıştı. Bu derste dersin kapsamında kullanılacak 8086'nın iç yapısına geçilir. Uçlar (portlar) bu derste genel hatlarıyla tanıtılır, ayrıntıları ileride uygulamalarda verilecektir.

8086 16 bitlik bir mikroişlemcidir. Bunun anlamı, iç yapısındaki kaydedicilerin (yazmaç, register) 16 bitlik veri tutabilmesidir. 16 bitlik bir yazmaç en az `0000H`, en çok `FFFFH` değerini alabilir. Her onaltılık hane 4 bite karşılık geldiği için dört onaltılık hane 16 bit eder.

Öte yandan 8086'nın adres yolu 20 bittir. 20 bit ile $2^{20} = 1\,048\,576$, yani yaklaşık 1 milyon farklı hafıza gözü adreslenebilir. Hoca bunu kod çözücü (dekoder) mantığıyla açıkladı: nasıl bir 3x8 dekoder 3 bitlik girişle 8 farklı çıkıştan birini seçiyorsa, 20 bitlik adres girişi de "20 x 1M" bir dekoder gibi yaklaşık 1 milyon farklı satırdan birini etkinleştirir.

**Soru:** $2^{20}$ bit 1 megabayt etmez; $2^{20}$ bit $2^{17}$ bayttır, bu da $2^{7}$ KB eder. 1 MB nereden çıkıyor?

**Cevap:** 20 bit, saklanan verinin büyüklüğü değil, adresin kendisidir. $2^{10}$ = 1K ve $2^{20}$ = 1M'dir; 20 bitlik adres 1M farklı satırı seçer. Hafızanın her satırı (gözü) 8 bit, yani 1 bayt veri tutar. Bu yüzden toplam adreslenebilir alan $1\text{M} \times 1 \text{ bayt} = 1 \text{ MB}$ olur. Bayt hesabı mikroişlemciden değil, hafıza bloğunun yapısından gelir; adres bitleri yalnızca baytın nerede olduğunu gösterir. 16 bitlik bir işlemcide her gözün 2 bayt olması da düşünülebilirdi, ama 8086'da hafıza gözleri bayt yapısındadır.

Aynı mantık bugünkü bilgisayarlarda da geçerlidir: 32 bitlik adresli bir işlemci $2^{32}$ farklı konumu adresleyebilir; her konum 1 bayt olduğu için bu 4 GB eder ve bu işlemci 4 GB'tan fazla hafızayı doğrudan adresleyemez.

## 2. 8086 iç yapısı: EU ve BIU

Slayttaki blok diyagramda 8086 iki ana birime ayrılır (ekrandan, 00:10:00):

| Birim | İçindekiler |
|---|---|
| Execution Unit (EU) | AH/AL, BH/BL, CH/CL, DH/DL; SP, BP, DI, SI; geçici yazmaçlar (temporary registers); ALU; bayraklar (flags); EU kontrol birimi |
| Bus Interface Unit (BIU) | CS, DS, SS, ES; IP; iç iletişim yazmaçları (internal communications registers); toplama birimi (summation); 20 bitlik adres yolu; veri yolu; yol kontrolü (bus control) ve 8086 yolu; 6 baytlık komut kuyruğu (instruction queue) |

### 2.1 Genel amaçlı yazmaçlar ve 8 bitlik erişim

AX, BX, CX, DX genel amaçlı yazmaçlardır. Her biri 16 bittir ve 16 bitin tamamı kullanılacaksa AX, BX gibi adlarla anılır. 8086 ayrıca yazmacın yarılarına ayrı ayrı erişim imkânı verir: A yazmacının düşük anlamlı 8 biti AL, yüksek anlamlı (MSB tarafındaki) 8 biti AH adıyla kullanılabilir. Aynısı BL/BH, CL/CH, DL/DH için de geçerlidir.

Örneğin `0023H` gibi yalnızca düşük baytı anlamlı bir değer atanacaksa bütün yazmacı kullanmaya gerek yoktur; değer doğrudan AL, BL ya da CL'ye yazılabilir (ekrandan, 00:20:00).

Bunların yanında dört işaretçi ve indis yazmacı (SP, BP, SI, DI) vardır. BIU tarafında ise segment yazmaçları bulunur; hocaya göre bunlar özellikle önemlidir.

## 3. Segment mimarisi neden var?

Burada bir çelişki vardır: adres yolu 20 bit, yazmaçlar 16 bittir. Örneğin hafızada `F2F3EH` adresine bir şey yazılmak istensin (ekrandan, 00:20:00). Bu beş onaltılık hane, yani 5 x 4 = 20 bitlik bir değerdir ve adres yoluna konabilir. Ama işlemci adres yoluna ancak bir yazmaçtaki değeri yazabilir ve yazmaç 16 bittir; 5 haneli bir sayı tek bir yazmaca sığmaz.

Bu sorun hafızanın segmentlere ayrılmasıyla çözülmüştür. Hafızanın bir kısmı kod segmenti, bir kısmı veri segmenti, bir kısmı ekstra segment olur. İlk gönderilen 16 bitlik değer segmenti, yani segmentin başlangıç noktasını belirler. İkinci 16 bitlik değer ise o segmentin içindeki ofseti, yani başlangıçtan kaç satır ilerleneceğini verir. Ofset AX, BX, CX gibi bir yazmaçtan gelebilir. Böylece 20 bitlik adres, 16 bitlik yazmaçlarla iki adımda tanımlanmış olur.

BIU içindeki toplama birimi ilk gelen segment değerini onaltılık $10H$ ile çarpar ve ikinci değeri üstüne ekler. Hoca burada "10 ile çarpma"nın onluk 10 değil, onaltılık $10H$ (onluk 16) olduğunu vurguladı. Onaltılık bir sayıyı $10H$ ile çarpmak, sayıyı bir hane sola kaydırmak, yani sağına bir 0 eklemektir. Dört haneli segment beş haneye çıkar, ofset buna eklenir.

**Soru:** 20 bit gönderirken önce 16 bit, sonra 4 bit mi gönderiyoruz?

**Cevap:** Hayır, iki kez 16 bit gönderilir. Toplamda 20 bitlik adres, iki tane 16 bitlik değerin (iki çevrimde) birleştirilmesiyle oluşur.

**Soru:** İkinci değeri 16 bit yerine 8 bitle (AX yerine AL gibi) gönderemez miyiz?

**Cevap:** Segment 16 bitle tanımlanır ve segment değeri her 1 arttığında başlangıç adresi 16 bayt ilerler. Ofset 8 bit olursa her segmentin içi en çok `FFH`'ye kadar adreslenebilir; segmentler küçülür, aralarda kullanılamayan boşluklar kalır ve hafıza daha erken biter. Hoca tahtada şöyle gösterdi (ekrandan, 00:25:00): sıfırıncı segment `00000H` ile `0FFFFH` arasını, bir sonraki segment `10000H` ile `1FFFFH` arasını kaplar; en sonda `F0000H` ile `FFFFFH` arası son 64 KB'lık bölümdür. Bir segmentin içini tamamen kullanabilmek için ikinci çevrimde 16 bitlik ofset gönderilmelidir. Hafızanın tamamını kaplayabilmek ve her segmentin içindeki her adresi gösterebilmek için iki tane 16 bitlik değerin art arda gelmesi en etkin çözümdür.

Kısacası, 20 bitlik yazmaçlar olsaydı bu düzenlemeye hiç gerek kalmazdı. 16 bitlik yazmaç ile 20 bitlik adres yolunun bir arada olması segment yapısını zorunlu kılmıştır.

## 4. 8086 yazmaçları

### 4.1 AX: akümülatör

En çok kullanılacak yazmaçtır ve genel olarak akümülatör diye anılır. AL (low) ve AH (high) olarak 8 bitlik parçalar halinde de kullanılabilir. Veri transferlerinde çok kullanılır. Çarpma ve bölme işlemlerinde gizli (örtük) operand olarak kullanılır. Giriş/çıkış komutlarında, yani bir porttan veri okurken ya da porta veri yazarken DX yazmacıyla birlikte kullanılır.

### 4.2 BX: taban yazmacı

Base register olarak geçer. Dizi biçiminde bir veri bloğu varsa kullanılacak yazmaçtır. BL ve BH olarak 8 bitlik de kullanılabilir.

### 4.3 CX: sayaç yazmacı

Adı "count"tan gelir. Sayma ve öteleme işlemlerinde kullanılır. Örneğin bir değeri iki kez sağa ötelemek aslında iki adımlık bir sayma işlemidir. Yüksek seviyeli dillerdeki `for` döngüsünün karşılığında, örneğin 1'den 5'e kadar sayan bir döngüde, artırma/azaltma CX üzerinden yapılır ve CX'in belirli bir değere ulaşması döngüden çıkış koşulu olarak denetlenir.

### 4.4 DX: veri yazmacı

Hoca bunun "data register" olarak akılda tutulabileceğini söyledi. Bir porttan veri okunurken port numarasını tutar. Çarpma ve bölmede de kullanılır.

> **Ek bilgi (derste anlatılmadı):** 8086'da 16 bitlik `MUL` sonucunun yüksek yarısı DX'e, düşük yarısı AX'e yazılır; 16 bitlik `DIV`'de ise bölünen 32 bitlik sayı DX:AX çiftinde tutulur, bölüm AX'e, kalan DX'e yazılır. Derste DX'in "bölünen sayıyı tutmak için" kullanıldığı söylendi; bu, bölünenin yüksek yarısının DX'te olmasına karşılık gelir.

### 4.5 SP: yığın işaretçisi

Slayttaki tanımlar (ekrandan, 00:30:00):

- SP: yığın yazmacı (stack pointer).
- Yığının en üst adresini işaretlemek için kullanılır.
- SS ile birlikte kullanılır.
- Her zaman çift bir değer gösterir.
- WORD tipinde veriyi gösterir.

Yığın, son girenin ilk çıktığı (LIFO) bir yapıdır ve SP en son ekleneni tutar. Yığına erişirken segment değeri SS'den, ofset SP'den gelir.

SP'nin hep çift değer göstermesinin nedeni şudur: yazmaçlar 16 bit, ama her hafıza gözü 1 bayttır. Bir yazmacın tamamı yığına atıldığında iki göz kullanılır (bir bayt AL, bir bayt AH), bu yüzden SP bir değil iki kez değiştirilir: `PUSH`'ta 2 azalır, `POP`'ta 2 artar.

### 4.6 BP: taban işaretçisi

SS ile birlikte, yani yığın segmentindeki verilerle kullanılır. Bir indisten sonra yazılacak veriler için işaretçi olarak ve alt programlara parametre aktarırken kullanılacaktır.

### 4.7 SI ve DI

Source Index ve Destination Index, dizi komutlarında kaynak ve hedef indisini tutan yazmaçlardır. Örneğin bir dizinin belirli elemanları alınacaksa kaynak ve hedef bu yazmaçlarla belirtilir.

### 4.8 Segment yazmaçları

- CS (kod segmenti): komutların bulunduğu bölge.
- SS (yığın segmenti): SP ve BP ile kullanılır.
- DS (veri segmenti): yalnızca veriler için ayrılmış bölge; içinde BX, SI ve DI ile adresleme yapılır.
- ES (ekstra segment): veri segmentinin yanında kullanılan bölge; özellikle dizi (string) işlemlerinde kullanılacak.

Hoca fiziksel adresin oluşumunu şöyle örnekledi: AX'e `1230H` yazılıp segment olarak gönderilsin; işlemci bunu veri segmenti olarak tutar. Sonra gönderilen ofset ile o segmentin içinde ilgili satıra gidilir. İşlemci segment değerini $10H$ ile çarpıp (bir hane sola kaydırıp) ikinci gelen değeri ekler ve 5 haneli, 20 bitlik fiziksel adresi elde eder.

Uygulamalarda öğrencilere bir şablon verilecek ve veri segmenti bu şablonun başında (kodun başında) zaten tanımlanmış olacak. Bu durumda öğrenci yalnızca 16 bitlik bir yazmaçtan ofseti verir; bu ofset tanımlı veri segmentinin içindeki konumu gösterir.

### 4.9 IP: komut işaretçisi

Slayttaki tanımlar (ekrandan, 00:35:00):

- IP: Instruction pointer.
- Sıradaki işlenecek komutu gösterir.
- CS ile birlikte kullanılır.
- Efektif program adresi: $CS \times 10H + IP$.

Komutlar da hafızada bir yerde durur. İşlemci `MOV`, `ADD` gibi bir komutu yürütmek için o komutun hafızadaki adresine gitmelidir; bu adresi tutan yazmaç IP'dir.

## 5. Bayrak yazmacı

Bayrak yazmacında işlem sonuçlarının durumunu gösteren bayraklar bulunur. Program yazarken bazı bayraklar okunarak dallanma ve hesap kontrolü yapılacaktır. Derste bunların bir kısmına değinildi.

> **Ders sonrası not:** Hoca 8086'da "14-16 kadar" bayrak olduğunu söyledi. Bayrak yazmacı 16 bittir, ama 8086'da büyük olasılıkla bunların yalnızca 9'u tanımlıdır: 6 durum bayrağı (CF, PF, AF, ZF, SF, OF) ve 3 kontrol bayrağı (TF, IF, DF). Derste anlatılanlar da bu dokuz bayraktır.

### 5.1 Elde bayrağı (CF)

Toplama işleminde elde oluştuğunda 1 olur. Hoca bunu işaretli taşmadan (overflow) ayrı, "aşım değil elde" durumu olarak tanımladı.

### 5.2 Eşlik bayrağı (PF)

Bir toplama ya da çıkarma işleminin sonucundaki 1 olan bitlerin sayısıyla ilgilidir. 1'lerin sayısı tekse PF = 0, çiftse PF = 1 olur. Hoca tahtadaki örnek sonuçta 1'lerin sayısı çift olduğu için PF'nin 1 olacağını gösterdi. Eşlik tanımının (tek ya da çift eşlik) farklı sistemlerde farklı kullanılabileceğini, ama burada yazılan biçimin genel kullanım olduğunu belirtti.

Hoca bayrağın amacını veri iletimiyle açıkladı: bir veri karşı tarafa gönderilirken eşlik bilgisi de gönderilir. Örneğin gönderilen verideki 1'lerin sayısı tektir ve eşlik bilgisi 0 olarak gider. Alıcı, gelen verideki 1'lerin sayısının çift olduğunu, ama eşlik bilgisinin 0 geldiğini görürse yolda bir sorun olduğunu anlar ve veriyi yeniden ister.

### 5.3 Yardımcı elde bayrağı (AF)

4 bitlik kısımların (nibble) toplama/çıkarma sonucunda oluşan eldeyi gösterir. Toplama sonucunda düşük 4 bitlik kısımdan bir üst 4 bitlik kısma elde geçerse AF = 1 olur. <!-- BELİRSİZ: 00:38:20 civarında hocanın tahtada kullandığı toplama örneğinin sayıları altyazıdan çıkarılamıyor ve bu ana ait kare yok. -->

### 5.4 Sıfır bayrağı (ZF) ve işaret bayrağı (SF)

İşlem sonucu 0 ise ZF = 1 olur; bazı örneklerde bu kontrol edilecektir. İşlem sonucu negatifse SF = 1 olur.

### 5.5 Tuzak, kesme ve yön bayrakları

Slayttaki tanımlar (ekrandan, 00:40:00):

- **Trap Flag (TF):** Her komuttan sonra kesme oluşmasını sağlar.
- **Interrupt enable Flag (IF):** Kesme kaynaklarının kesme oluşturmasına izin verir.
- **Direction Flag (DF):** Dizi işlemlerinde başlangıç adresinden itibaren artırarak/azaltarak sıradaki göze erişimi belirler.
- **Overflow Flag (OF):** İşaretli işlemlerde taşma durumunda 1 değerini alır.

Hoca kesme bayrağını bir USB aygıtı takıldığında çıkan uyarı sesi örneğiyle anlattı: bir kesme oluştuktan ve ona cevap verildikten sonra ilgili durum sıfırlanmazsa, yeni bir kesme (örneğin aygıt çıkarıldığında çıkacak ses) kabul edilmez. Kesmeler 8. ya da 9. haftada ayrıntılı işlenecek.

> **Ders sonrası not:** Hoca anlatımda tuzak bayrağı (TF) için "sıfırlanırsa kesme oluşması önlenir" tanımını, ikinci bayrak için de "hata ayıklama (debug) amaçlı" tanımını verdi. Slayttaki tanımlarla karşılaştırıldığında bu iki açıklama yer değiştirmiştir: kesmelerin kabul edilip edilmeyeceğini IF belirler; TF ise her komuttan sonra kesme üreterek adım adım çalıştırmayı (hata ayıklamayı) sağlar.

DF, dizi işlemlerinde adreslerin artarak mı azalarak mı ilerleyeceğini belirler.

OF için hoca, sonuç artık yazmacın sığabileceği basamakların dışına çıktığında, yani "16 bitin bir bit fazlası" oluştuğunda bu bayrağın kontrol edileceğini söyledi.

> **Ders sonrası not:** Sonucun 16 biti aşması (en anlamlı bitten dışarı elde çıkması) aslında CF ile gösterilir. OF ise slayttaki tanımdaki gibi işaretli işlemlerde sonucun işaretli aralığın dışına çıkmasını gösterir; örneğin iki pozitif sayının toplamının negatif görünmesi. Derste verilen açıklama büyük olasılıkla bu iki durumu karıştırmaktadır.

## 6. Fiziksel adres üzerine sorular

**Soru:** Segmenti bir hane kaydırıp ofseti ekleyerek fiziksel adrese ulaşıyoruz. Fiziksel adresten tekrar segment ve ofset değerine ulaşabilir miyiz?

**Cevap:** Hoca önce örnekle gösterdi: kod segmenti `1234H`, ofset `0005H` olsun. Fiziksel adres $1234H \times 10H + 0005H = 12345H$ olur (ekrandan, 00:45:00). Basit durumda bu adres yeniden $10H$'e bölünüp segment ve ofset ayrılabilir. Ama öğrencinin belirttiği gibi ofset büyük olunca karışıklık çıkar: segment `1231H`, ofset `0035H` olduğunda da $1231H \times 10H + 0035H = 12310H + 0035H = 12345H$ olur. İki farklı çift aynı yeri gösterdiği için fiziksel adresten geri dönüş tek türlü değildir. Hoca buna pratikte gerek de olmadığını söyledi: fiziksel adres hafızadaki gerçek yeri gösterir, segment ve ofseti ise programcı kodda kendisi verdiği için zaten bilir.

**Soru:** Fiziksel adresi nerede kullanıyoruz, bir işe yarıyor mu?

**Cevap:** Fiziksel adres, hafızada yazılacak ya da okunacak gerçek yeri söyler. Hoca tahtada şöyle gösterdi (ekrandan, 00:45:00): veri segmentinin başlangıç adresi kodun başında `1234H` olarak verilmişse, bu segment fiziksel olarak `12340H` adresinden başlar ve 64 KB boyunca sürer. Program yalnızca bu başlangıçtan kaç satır aşağı inileceğini (ofseti) söyler; segment başlangıcı ile ofsetin birleşimi fiziksel adresi oluşturur. Real modda çalışıldığı için doğrudan fiziksel adresler kullanılır.

**Soru:** Eşlik bayrağı yalnızca güvenlik (hata denetimi) amacıyla mı kullanılıyor?

**Cevap:** Eşlik bayrağı genellikle mikroişlemcinin çevre birimlerine gönderdiği verinin doğru gidip gitmediğini denetlemek için kullanılır. Örneğin mikroişlemci bir entegreye 8 bitlik veri yolundan veri gönderirken eşlik bilgisini de gönderir; entegre bu bilgiye bakarak bitlerin sağlıklı ulaşıp ulaşmadığını anlar. Bunu yalnızca ağ iletişimi olarak düşünmemek gerekir, entegreler arasında da kullanılır.

**Soru:** 8 bitin içinde iki tane 1 birden 0'a dönüşürse eşlik bayrağı değişmez, değil mi?

**Cevap:** Evet. Eşlik çok basit bir denetim mekanizmasıdır ve yalnızca tek sayıda bitin değiştiği hataları yakalar. İki bit birden değişirse işe yaramaz. Ağ derslerinde görülen CRC ve checksum gibi polinom tabanlı yöntemler çok daha güçlü denetim sağlar.

## 7. Real mod hafıza adresleme

8086'nın iki çalışma modu vardır: real mod ve protected mod. Real modda 1 MB'lık alan adreslenir, yani her satırı bir bayt olan yaklaşık 1 milyon satırlık hafıza bloğuna erişilir. Uygulamalarda real mod kullanılacak, yani doğrudan fiziksel adresler üzerinde çalışılacaktır.

Slayttaki maddeler (ekrandan, 00:50:00):

- Real modda segment adres ve ofset adres değerlerinin birleşimiyle hafızada istenen alana erişilir.
- Bir segment değeri 64 KB'lık alanı gösterir (NEDEN?).
- Ofset değeri 64 KB'lık alan içinde bir yeri gösterir.
- Örnek: Segment değeri `1000H`, ofset değeri `2000H` ise mikroişlemcide erişilen fiziksel adres ne olur?
- $1000H \times 10H + 2000H = 12000H$ (`1000H:2000H`).

Hoca "neden 64 KB?" sorusunu sınıfa yöneltti. Hafıza bloğu segmentlere ayrılmıştır; illa bir tane CS, bir tane DS, bir tane ES olacak diye bir şey yoktur. Ama her segmentin içi 64 KB'tır, yani 64K satır içerir. Bunun nedeni ofsetin 16 bit olmasıdır; ofsetin 16 bit olmasının nedeni de yazmaçların 16 bit olmasıdır. AX gibi bir yazmaç `0000H` ile `FFFFH` arasında değer alabilir; tek seferde adreslenebilecek aralık `0000H`-`FFFFH`'dir ve bu $2^{16} = 65\,536$ bayt, yani 64 KB eder (64 x 1024). Segment yazmacı da aynı aralıkta değer alır; 20 bitlik adresteki fazladan hane segment değerinin kaydırılmasıyla gelir.

Örnekte işlemci `12000H` fiziksel adresini kendisi hesaplar. Programcı, segment tanımlıysa yalnızca ofseti vererek bu adrese eriştiğini belirtir.

Segment kullanımları için özel atamalar vardır: SP ve BP için SS; kodların bulunduğu bölge için CS; veriler için DS ve ES, ES ayrıca dizi işlemlerinde.

Protected modda 1 MB'tan daha geniş bir hafıza alanı kullanılır. Bu modda hafızada (yine ana hafızada) tutulan bazı tablolar üzerinden adresleme yapılır. Bu derste protected mod kullanılmayacak.

## 8. Veri adresleme modları

Adresleme modu, bir adresten veri okunurken ya da bir adrese veri yazılırken o adresin nasıl bulunacağını belirleyen yöntemdir; program hafıza adresleme modları da denir.

### 8.1 Genel komut yapısı

En çok kullanılacak komut `MOV`'dur (ekrandan, 00:55:00):

```text
MOV  AX, BX
     ^   ^
     |   +-- Source (kaynak)
     +------ Destination (hedef)
```

`MOV AX, BX` komutu kaynak (BX) yazmacındaki veriyi hedef (AX) yazmacına alır. Örneğin AX'te `1234H`, BX'te `ABCDH` olsun. Komuttan sonra AX'in içi BX'teki veriyle dolar ve AX'teki eski veri kaybolur. Sayının sonundaki `H`, sayının onaltılık olduğunu belirtir; bunu unutmamak gerekir.

### 8.2 Yazmaç adresleme

En çok kullanılacak moddur; yazmaçlar arasında veri aktarımıdır. 8 bitlik yazmaçlar da kullanılabilir, ama iki tarafın genişlikleri uyumlu olmalıdır: kaynak 16 bit, hedef 8 bit olamaz.

> **Ek bilgi (derste anlatılmadı):** 8086'da `MOV` komutunda kaynak ve hedef yazmaçların genişliği aynı olmalıdır; yani `MOV AX, BL` gibi 8 bitten 16 bite aktarım da derleyici tarafından reddedilir. Hocanın "hedef 16 bit olabilir" ifadesi büyük olasılıkla bu genişletme komutlarının (`MOVZX` gibi, 80386 ile gelen) varlığıyla karışmıştır; 8086'da bu tür aktarım için önce yüksek bayt sıfırlanır ya da `CBW` kullanılır.

### 8.3 Anında (immediate) adresleme

Yazmacın içine doğrudan bir değer yazmaktır. Değer onluk, onaltılık ya da ikilik verilebilir. Derste slayttaki örnekler sözlü olarak şöyle anlatıldı:

- AL'ye onaltılık `0F2H` yazılır; AL'nin içeriği `F2H` olur. Harfle (A-F) başlayan onaltılık sayıların başına 0 konmalıdır, aksi halde derleyici kabul etmez. `F2H` 8 bitlik bir sayıdır, bu yüzden AL'ye yazılmıştır.
- CX'e `100` yazılır; sonunda bir harf olmaması sayının onluk olduğunu gösterir.
- BL'ye ikilik (binary) yazılmış 8 bitlik bir sayı atanır.
- AH'ye `'A'` karakteri atanır. ASCII karakterler 8 bittir; büyük `A` harfinin ASCII kodu 65'tir (`41H`). Hoca bunu "65 herhalde" diye söyledi; doğrudur.

<!-- BELİRSİZ: 00:56:05-00:57:41 arasındaki anında adresleme slaytının tam komut metni ve BL'ye yazılan ikilik sayının değeri karelerde yok; yalnızca anlatımdan aktarıldı. -->

### 8.4 Doğrudan adresleme

Bu modda yazmaca bir sayı yazılmaz. Slayttaki örnekte `1234H` değeri, veri segmentinin içinde tanımlanmış bir ofsettir; DS içindeki `1234H` ofsetindeki gözün içeriği BX'e yazılır. Hoca burayı önemli olarak vurguladı: `1234H` BX'e yazılmaz, o adresteki veri yazılır; adres bir etiket gibidir.

<!-- BELİRSİZ: Doğrudan adresleme slaytının tam komut metni karelerde yok; anlatıma göre büyük olasılıkla MOV BX, [1234H] biçimindedir. -->

### 8.5 Yazmaç dolaylı adresleme

Slayttaki bilgiler (ekrandan, 01:00:00):

- BP (SS ile), BX, DI ve SI (DS ile) yazmaçları ile kullanılabilir.
- Hafıza ofset değeri bir yazmaçta saklanır.
- `MOV AX, [BX] ; AX <- DS:BX`

Slayttaki şekil şu değerleri gösterir:

| Öğe | Değer |
|---|---|
| DS | `0100H` (segment başlangıcı $0100H \times 10H = 01000H$) |
| BX | `1000H` |
| Fiziksel adres | $01000H + 1000H = 02000H$ |
| `02000H` gözü | `12H` |
| `02001H` gözü | `34H` |
| Sonuç | AH = `34H`, AL = `12H`, AX = `3412H` |

Adım adım çözüm:

1. BX'in içindeki `1000H` bir adres bilgisidir (ofset).
2. Veri segmenti `0100H` bir hane sola kaydırılır: `01000H`.
3. Ofset eklenir: $01000H + 1000H = 02000H$.
4. Hafızadaki her göz 8 bit (1 bayt) olduğu halde hedef AX 16 bittir. Bu yüzden işlemci otomatik olarak hem `02000H` hem `02001H` gözlerini okur.
5. `02000H`'deki `12H` AL'ye, `02001H`'deki `34H` AH'ye yerleşir; AX = `3412H`.

> **Ders sonrası not:** Hoca little-endian ve big-endian kavramlarını anarken hangi baytın AH'ye, hangisinin AL'ye gideceğini karışık anlattı ("tam tersi ise 12'yi AH'ye yazar"). 8086 little-endian'dır: düşük adresteki bayt yazmacın düşük yarısına (AL), yüksek adresteki bayt yüksek yarısına (AH) gider. Slayttaki AX = `3412H` sonucu da bunu gösterir.

### 8.6 Taban artı indis adresleme

Bu modda BX'e bir indis yazmacı eklenir. Anlatıma göre BX ile DI toplanır ve elde edilen adresteki veri DX'e alınır. Hoca bunun yazmaç dolaylı adreslemenin bir indis eklenmiş biçimi olduğunu söyledi: orada BX'in içindeki değer adresti, burada BX + DI toplamı adrestir.

<!-- BELİRSİZ: Taban artı indis slaytının tam komut metni karelerde yok; anlatıma göre büyük olasılıkla MOV DX, [BX+DI] biçimindedir. -->

> **Ders sonrası not:** Hoca bu modda "çift dolaylama" olduğunu söyledi. Burada adres iki yazmacın toplamıyla hesaplanır, ama hafızaya bir kez erişilir; yani adresin kendisi hafızadan okunmaz. Bu anlamda gerçek bir "çift dolaylı" adresleme değildir.

### 8.7 Yazmaç göreli ve taban göreli artı indis adresleme

Yazmaç göreli adreslemede bir indis yazmacı yerine sabit bir sayısal değer (yer değiştirme) eklenir; iki mod aynı mantıkla çalışır. Son olarak üçünün birleştiği bir mod vardır: BX'teki değer, SI'nın gösterdiği değer ve dışarıdan verilen sayısal bir değer toplanır. Bununla iki boyutlu veri adreslemesi yapılabilir.

## 9. Program hafızası adresleme

Bir komut çalıştırılırken aslında kod segmentinin içinde IP'nin gösterdiği yerdeki komut çalıştırılır (CS:IP). `JMP` ya da `CALL` gibi komutlarla IP'nin gösterdiği yer değiştirilerek başka bir adrese dallanılır. Bu dallanma üç yolla yapılabilir:

- **Doğrudan:** CS'ye ve IP'ye doğrudan değer atanıp o adrese atlanır. Hoca örnekte başlangıcı `200` olan bir kod segmentinde `300` ofset aşağıdaki komuta gitmeyi anlattı. Bu, IP'nin içeriğini doğrudan değiştirmek, yani programın belirli bir hafıza adresine zıplamaktır.
- **Göreli:** Mevcut IP'nin değeri bilinmese bile, örneğin `JMP 100` ile mevcut konumdan 100 ileriye zıplanır.
- **Dolaylı:** Yazmaç dolaylı veri adreslemesinde olduğu gibi, bir yazmacın içindeki adresin gösterdiği yere gidilir.

## 10. Yığın adresleme

Yığın, SS (yığın segmenti) içindeki bölgedir. Yığına veri atmak için `PUSH`, yığından veri çekmek için `POP` kullanılır. Yığın LIFO (last in, first out) mantığıyla çalışır: son atılan ilk çıkar.

- CS'nin o anki değeri `PUSH CS` ile yığına atılabilir, ama `POP CS` yapılamaz; bu derleyici (assembler) hatası verir.
- `PUSH` ve `POP` her zaman bir WORD (2 bayt, 16 bit) taşır. Bu 16 bitlik yazmaç yapısına uyar: yazmacın tamamı tek bir `PUSH` ya da `POP` ile işlenir.
- `PUSH BL` gibi 8 bitlik işlem çalışmaz, hata verir; SP'yi tek adım hareket ettirip yalnızca 8 bit taşımak mümkün değildir.

Her `PUSH` işleminde SP'nin gösterdiği adresin bir ve iki altına (SP-1 ve SP-2) 2 bayt veri yazılır ve SP 2 azaltılır. Adresler küçülerek ilerler, yani yığın aşağı doğru büyür. `POP` işleminde SP'nin gösterdiği adres ve bir üstündeki adres okunur, SP 2 artırılır.

Slayttaki şekil (ekrandan, 01:20:00):

- (a) `PUSH`: BX'teki `1234H` yığına yazılır; yığında `12` ve `34` baytları yer alır. Adres $SS \times 10H + SP$ ile hesaplanır.
- (b) `POP`: yığındaki `12` ve `34` baytları okunur ve CX'e `1234H` olarak yazılır.

Hoca SP'nin her zaman en son yazılan veriyi göstermesi gerektiğini vurguladı; böylece `POP` ile doğrudan o veri okunabilir. Okuma yapıldıktan sonra SP iki üste geçer ve bir önceki veriyi gösterir.

## 11. 8086 uç tanımları

8086, 40 bacaklı bir kılıfa sahip bir entegredir. Bacakların hepsi kullanılmasa da mümkün olduğunca bilinmelidir.

Slayttaki uç diyagramı (ekrandan, 01:25:00):

| Sol taraf (1-20) | Sağ taraf (40-21) | Maksimum mod | Minimum mod |
|---|---|---|---|
| 1 GND | 40 Vcc | | |
| 2 AD14 | 39 AD15 | | |
| 3 AD13 | 38 A16/S3 | | |
| 4 AD12 | 37 A17/S4 | | |
| 5 AD11 | 36 A18/S5 | | |
| 6 AD10 | 35 A19/S6 | | |
| 7 AD9 | 34 $\overline{BHE}$/S7 | | |
| 8 AD8 | 33 MN/$\overline{MX}$ | | |
| 9 AD7 | 32 $\overline{RD}$ | | |
| 10 AD6 | 31 | $\overline{RQ}$/$\overline{GT0}$ | HOLD |
| 11 AD5 | 30 | $\overline{RQ}$/$\overline{GT1}$ | HLDA |
| 12 AD4 | 29 | $\overline{LOCK}$ | $\overline{WR}$ |
| 13 AD3 | 28 | $\overline{S2}$ | IO/M |
| 14 AD2 | 27 | $\overline{S1}$ | DT/$\overline{R}$ |
| 15 AD1 | 26 | $\overline{S0}$ | $\overline{DEN}$ |
| 16 AD0 | 25 | QS0 | ALE |
| 17 NMI | 24 | QS1 | $\overline{INTA}$ |
| 18 INTR | 23 $\overline{TEST}$ | | |
| 19 CLK | 22 READY | | |
| 20 GND | 21 RESET | | |

### 11.1 Ortak adres/veri uçları ve ALE

Adres yolu 20 bit, veri yolu 16 bittir; ayrı ayrı tasarlansaydı 36 bacak gerekirdi. Bunun yerine 16 bit iki yol için ortak yapılmıştır: AD15-AD0 ortak adres/veri uçlarıdır.

Ortak uçlarda o anda adres mi veri mi bulunduğunu belirten bir işaret gerekir; hoca bunu trafik ışığı sinyalizasyonuna benzetti. Veri gönderilmeden önce adresin belirlenmiş olması gerekir; aksi halde veri yerine adres bilgisi alınabilir ya da yanlış adresten veri okunur. Bu yüzden iki aşamalı bir yapı vardır: önce adres verilir ve tutulur, sonra aynı uçlardan veri taşınır.

Bunu belirleyen uç ALE'dir. Slayttaki tanım (ekrandan, 01:30:00): "AD15-AD0 (I/O-3): 8086'nın adres/veri yolu hatları, çoklanmış (multiplexed) adres/veri yolunu oluşturur. ALE mantık 1 olduğunda bu hatlar adres bitlerini içerir. Bir hold acknowledge oluştuğunda bu uçlar yüksek empedans durumuna girer." ALE 0 iken bu uçlarda veri vardır.

> **Ders sonrası not:** Hoca slayttaki "(I/O-3)" gösterimini "adresler giriş, veriler çıkış" diye yorumladı. Bu gösterim büyük olasılıkla ucun çift yönlü (giriş/çıkış) ve üç durumlu (three-state) olduğunu anlatır. Adres 8086 tarafından dışarı verilir (çıkış); veri ise okumada içeri (giriş), yazmada dışarı (çıkış) akar.

A19-A16 uçları yalnızca adres taşır, veri yolu bileşenleri yoktur. Bunların ek olarak S3-S6 durum (status) bilgisi verme işlevi de vardır.

### 11.2 BHE

$\overline{BHE}$ (bus high enable), 16 bitlik veri yolunun yüksek anlamlı 8 bitinin (D15-D8) kullanılıp kullanılmayacağını belirler. Hoca bunu 8 bitlik entegrelerle bağlantılandırdı: dışarıda bazen 8 bitlik entegreler kullanılacak ve veri yolunun yalnızca bir yarısı bağlanacaktır; hangi yarının geçerli olduğu bu uçla denetlenir.

> **Ders sonrası not:** Hoca "BHE 0 ise yüksek anlamlı 8 bit gönderilir, düşük anlamlı 8 bite yazılmaz; BHE 1 ise düşük anlamlı 8 bite yazılır" dedi. 8086'da büyük olasılıkla doğrusu şudur: $\overline{BHE}$ = 0 yalnızca yüksek baytı (D15-D8) etkinleştirir; düşük baytın (D7-D0) etkin olup olmadığını ise A0 belirler. $\overline{BHE}$ = 0 ve A0 = 0 ise 16 bitin tamamı, $\overline{BHE}$ = 1 ve A0 = 0 ise yalnız düşük bayt, $\overline{BHE}$ = 0 ve A0 = 1 ise yalnız yüksek bayt aktarılır.

### 11.3 Kesme uçları: NMI ve INTR

NMI (non-maskable interrupt) maskelenemez kesme girişidir. İşlemcideki kesme bayrağının (IF) durumuna bakılmaksızın, bu uçtan gelen sinyal 8086'yı kesme işlemine sokar, yani kesme kodunun çağrılmasını sağlar. En yüksek öncelikli kesme ucudur ve vektör 2 olarak anılacaktır. Kesme, bir sinyal geldiğinde işlemcinin kendi işini bırakıp kesme kodunu çalıştırması demektir.

INTR ise engellenebilen (maskelenebilen) kesme girişidir. $\overline{INTA}$ da kesmeyle ilgili bir uçtur. Ayrıntılar kesmeler haftasında işlenecek.

### 11.4 CLK, READY, RESET, TEST

CLK, mikroişlemcinin çalışmasını sağlayan saat işaretinin girişidir. Bilgisayarlardaki işlemcilerde olduğu gibi saat frekansı (MHz, GHz) işlemlerin ne kadar hızlı yapılabileceğini belirler.

READY, mikroişlemcinin hazır olduğunu söyler: 1 iken hazır, 0 iken bekleme (wait) durumuna, yani işlem yapmama durumuna girer. RESET ucu mikroişlemciyi sıfırlama durumuna sokar. $\overline{TEST}$ ucu, hocanın anlatımıyla mikroişlemcinin bekleme durumuna geçip geçmediğinin test edildiği uçtur.

> **Ek bilgi (derste anlatılmadı):** $\overline{TEST}$ ucu büyük olasılıkla 8086'nın `WAIT` komutuyla birlikte kullanılır: `WAIT` çalıştırıldığında işlemci $\overline{TEST}$ ucu 0 olana kadar bekler. Bu uç genellikle bir matematik yardımcı işlemcisiyle eşzamanlama için kullanılır.

### 11.5 Minimum ve maksimum mod

Bazı uçlar iki farklı modda farklı işlev görür. Modu MN/$\overline{MX}$ ucu seçer. Uç adındaki eğik çizgi (ya da üst çizgi) ilgili işlevin 0'da aktif olduğunu gösterir. Bu uca 0 verilirse maksimum mod uçları, 1 verilirse minimum mod uçları aktif olur.

### 11.6 RD, WR, IO/M, DT/R, DEN

- $\overline{RD}$: işlemcinin veri okuduğunu belirten işarettir; okuma sırasında 0 olur.
- $\overline{WR}$: işlemcinin karşı tarafa veri yazacağını belirten işarettir. Portlarla çalışırken kullanılacaktır.
- IO/M: işlemin ana hafızaya mı, bir giriş/çıkış birimine mi yapıldığını belirtir. Giriş/çıkış birimi bir entegre olabilir, hafıza da bir hafıza modülüdür. Örneklerde bir entegrenin portlarından veri okunurken bu uç giriş/çıkış olarak ayarlanacak; bu uç çok sık kullanılacak.
- DT/$\overline{R}$ (data transmit/receive): hafızadan işlemciye veri alınıyorsa (receive) 0, işlemciden hafızaya veri yazılıyorsa (transmit) 1 üretir.
- $\overline{DEN}$ (data enable): işlemci veri yolunda veri olduğunu bildirmek için bu ucu 0 yapar.

> **Ders sonrası not:** Hoca bu uç için "0 üretirse ana hafızaya, 1 üretirse giriş/çıkışa yazılır" dedi. 8086'nın minimum mod ucu büyük olasılıkla M/$\overline{IO}$'dur (yol tamponlama şeklinde de M/$\overline{IO}$ yazar): 1 hafıza, 0 giriş/çıkış erişimini gösterir. Hocanın tarif ettiği kutupluluk, 8088'deki IO/$\overline{M}$ ucuna uyar.

### 11.7 Saat frekansı ve osilatör

İşlemcinin içinde ne kadar işlem yapılırsa yapılsın, bunların etkin olabilmesi için bir saat darbesiyle tetiklenmesi gerekir. Hoca bunu lojik devreler laboratuvarındaki flip-flop deneyine benzetti: girişler değiştirilse de çıkışa ancak saate basıldığında aktarılıyordu.

**Soru (hocanın kendi sorduğu):** Saat frekansını 5 MHz yerine 5 GHz yapamaz mıydık?

**Cevap:** 8086 fiziksel olarak en fazla 5 MHz'lik saatle çalışabilir, daha hızlı saati desteklemez. Bugünkü işlemcilerde hız aşırtma (overclock) ile sınırlar zorlanabilir, ama bunun ısınma, soğutma gerekliliği gibi riskleri vardır. 8086 için en yüksek çalışma frekansında bir osilatör devresi kullanılır. Deneyler simülasyon ortamında (Proteus) yapılacağı için böyle bir devre tasarlanmayacak; 8086 seçildiğinde saat frekansı yazılım ayarıyla verilir.

> **Ders sonrası not:** Temel 8086 için 5 MHz doğrudur, ama büyük olasılıkla 8 MHz (8086-2) ve 10 MHz (8086-1) çalışabilen sürümleri de vardır. "8086 en fazla 5 MHz" ifadesi yalnızca temel sürüm için geçerlidir.

## 12. Yol tamponlama ve mandallama

### 12.1 Sorun

Donanımsal olarak 8086 kullanırken en büyük sorun, veri ve adres yolunun ortak olması yüzünden eşzamanlama gerekmesidir. Slayttaki maddeler (ekrandan, 01:35:00):

- 8086/8088'in adres/veri yolu, entegre devre için gereken uç sayısını azaltmak için çoklanmıştır (paylaşılmıştır).
- Hafıza ve G/Ç birimleri, bir okuma/yazma çevrimi boyunca adresin geçerli ve kararlı kalmasını ister.
- Yollar çoklanmışsa adres hafızada ve G/Ç'de değişir; bu da verinin yanlış yerlere yazılmasına ya da yanlış yerlerden okunmasına yol açar.

Yani önce adres belirlenir, sonra o adresten veri okunup veri yoluna konur ya da o adrese veri yazılır. Adres bilgisinin, aynı uçlara veri yazıldığında kaybolmaması için "havada tutulması" gerekir. Bunu sağlayan entegrelere mandal (latch) devreleri denir; hoca "latch"in tutmak, askıda tutmak anlamına geldiğini söyledi.

### 12.2 74LS373 mandal

74LS373, 8 bit giriş (D0-D7) ve 8 bit çıkış olan bir mandal entegresidir. Doğruluk tablosuna göre çalışması:

| $\overline{OE}$ | LE | D | Çıkış |
|---|---|---|---|
| 0 | 1 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 0 | 0 | X | Önceki çıkış (tutma) |
| 1 | X | X | Yüksek empedans |

- LE yüksek iken giriş çıkışta aynen görülür; bu sırada tutma yoktur.
- LE = 0 ve $\overline{OE}$ = 0 iken çıkış bir önceki çıkışın aynısıdır, yani mandal veriyi tutar. Giriş değişse bile çıkış değişmez.

<!-- BELİRSİZ: 74LS373 doğruluk tablosu slaytı karelerde yok; tablo hocanın anlatımına göre kuruldu, $\overline{OE}$ = 1 satırı anlatımda geçmedi, standart davranışa göre eklendi. -->

Adres verisi gönderildikten sonra veri gönderildiğinde önceki adresin bir yerde tutulması gerekir; bu devre bunu yapar.

### 12.3 74LS245 çift yönlü tampon (transceiver)

Adres mandallandıktan sonra verinin yönü de belirlenmelidir. Örneğin hafızadan işlemciye veri okunurken veri yolunda önceden kalmış değerler olabilir; okunmak istenen verinin veri yoluna doğru yönde konması gerekir. Bunu 74LS245 sağlar. İki kontrol ucu vardır:

| $\overline{G}$ (enable) | DIR | İşlem |
|---|---|---|
| 0 | 0 | B'den A'ya veri aktarımı |
| 0 | 1 | A'dan B'ye veri aktarımı |
| 1 | X | Yalıtım (çalışmaz) |

Enable ucu 1 (yüksek) olduğunda entegre yalıtımdadır, çalışmaz. Enable 0 olunca entegre çalışır ve yönü DIR ucu belirler.

Hoca örnekte A tarafına hafızanın, B tarafına 8086'nın bağlandığını varsaydı: bu entegre olmasaydı, 8086'nın veri uçlarında bir şey dururken hafızadan okunan veri bunun üzerine konur ve adres verisiyle çakışabilirdi. İlk çözüm adresi mandallamak, ikinci çözüm 8086'nın bu entegreye yön bilgisi vermesidir. Hocanın varsayımıyla hafızadan okuma için A'dan B'ye aktarım, yani DIR = 1 gerekir.

> **Ders sonrası not:** Hoca DT/$\overline{R}$'nin okumada (receive) 0 olduğunu da söyledi. Yol tamponlama şeklinde (ekrandan, 01:45:00) DT/$\overline{R}$ doğrudan 245'in DIR ucuna bağlıdır ve 8086 tarafı büyük olasılıkla A tarafıdır. Bu durumda okumada DT/$\overline{R}$ = DIR = 0 olur ve veri B'den (hafıza/yol tarafı) A'ya (8086 tarafı) akar. Hocanın "A tarafı hafıza, okumada DIR = 1" örneği bu bağlantıyla çelişir; tutarlı olan, DT/$\overline{R}$ = 0 iken verinin 8086'ya doğru aktığıdır.

### 12.4 74LS244 sekizli tampon

Slayttaki doğruluk tablosu (ekrandan, 01:40:00):

| $\overline{1G}$, $\overline{2G}$ | D | Çıkış |
|---|---|---|
| L | L | L |
| L | H | H |
| H | X | (Z) |

$\overline{1G}$ ve $\overline{2G}$ düşük verildiğinde giriş doğrudan çıkışa verilir; yüksek verildiğinde çıkış yüksek empedanstadır. Entegrede 1A1-1A4/1Y1-1Y4 ve 2A1-2A4/2Y1-2Y4 olmak üzere dörderli iki tampon grubu vardır. Hoca bu entegrenin durum (status) bitleri için kullanılacağını söyledi.

> **Ders sonrası not:** Yol tamponlama şeklinde (ekrandan, 01:45:00) 74LS244, M/$\overline{IO}$, $\overline{RD}$ ve $\overline{WR}$ kontrol hatlarını tamponlayarak "buffered control bus" oluşturur. A19-A16/S6-S3 durum bitlerini ve $\overline{BHE}$/S7'yi tutan entegre ise üçüncü bir 74LS373'tür.

### 12.5 Bütün sistem: yol tamponlama şeması

Slayttaki şemada bağlantılar şöyledir (ekrandan, 01:45:00):

```text
8086 tarafı                Entegre             Tamponlu çıkış
-----------                -------             --------------
M/IO, RD, WR        --->   74LS244 (OE=GND)  -> M/IO, RD, WR  (buffered control bus)
BHE/S7, A19/S6..A16/S3 ->  74LS373 (G, OE)   -> BHE, A19..A16
AD15..AD8           --->   74LS373 (G=ALE)   -> A15..A8       (buffered address bus)
AD7..AD0            --->   74LS373 (G=ALE)   -> A7..A0
AD15..AD8           <-->   74LS245 (G, DIR)  <-> D15..D8
AD7..AD0            <-->   74LS245 (G, DIR)  <-> D7..D0
ALE                 --->   373'lerin G ucu
DEN                 --->   245'lerin G ucu
DT/R                --->   245'lerin DIR ucu
```

Hoca akışı tahtada adım adım anlattı:

1. 8086 AD uçlarına bir adres koyar. Bu değer hem 373'lere hem 245'lere gider.
2. Adres gönderildiği için ALE = 1 yapılır. ALE, 373'lerin mandallama ucuna bağlıdır; 373'ler adresi alır.
3. ALE 0'a düşürülür. Artık AD uçlarındaki değer değişse bile 373 çıkışları güncellenmez; adres tutulmuş olur. Bu adres hafızada ilgili gözü etkinleştirmiştir ve etkin kalır.
4. AD uçlarına artık veri konur (ALE = 0 olduğu için bu bir veridir).
5. 245'in yönü belirlenir: $\overline{DEN}$ 8086 tarafından 0 yapılınca 245'ler etkinleşir ("veri var"). DT/$\overline{R}$ ile verinin hafızaya mı yazılacağı (transmit) yoksa mandallanmış adresteki gözden mi okunacağı (receive) seçilir.
6. Okuma durumunda, etkinleştirilen hafıza gözünün veri uçları (her hücreye bağlı D hatları, hocanın deyişiyle kartezyen bir yapı gibi) veri yoluna konur ve veri yolundan okunur.

245'ler yönü belirtir: mikroişlemciden hafızaya veri mi yazılacak, hafızadan mikroişlemciye veri mi okunacak. Bunu işlemci $\overline{DEN}$ ve DT/$\overline{R}$ ile belirler. ALE ise 373 entegresini mandallamak için kullanılır. Üçüncü 373 de vardır, çünkü A19-A16 uçları adres yanında S3-S6 durum bitlerini de taşır; bu bitlerin gerekirse okunabilmesi için onlar da mandallanır.

245 bir transceiver'dır: RAM'e hem okuma hem yazma yapılabilir, çevre birimlerine de hem okuma hem yazma yapılabilir; EPROM'a ise genellikle yalnızca okuma yapılır. Hoca, şemadaki bir bağlantının (ALE'nin G yerine başka bir uca gidiyor görünmesi) büyük olasılıkla çizim hatası olduğunu, ALE'nin mandalı etkinleştirdiğini belirtti.

Uygulamalarda bu şablon hazır verilecek; öğrenci mandal devresi tasarlamayacak. Ama adres ile verinin mandal yardımıyla nasıl ayrıldığı ve transceiver'ın önemi kavranmalıdır. Yol zamanlaması (bus timing) slaytlarının bu aşamada çok önemli olmadığı söylendi.

> **Hocanın vurgusu:** Adres/veri ayrımının mandal ile nasıl yapıldığını ve transceiver'ın neden gerektiğini kavramak gerekir; devreler hazır verilse de mantığı bilinmelidir.

### 12.6 Neden 20 bitlik yazmaç yok?

**Soru:** 16 bitlik yazmaç yerine 20 bitlik yazmaç olsaydı segment yapısıyla uğraşmazdık. Neden 16 bitlik yazmaç kullanılıyor?

**Cevap:** İşlemciler adım adım geliştirildi. 8086'dan önceki kuşakta 8 bitlik yazmaç ve 16 bitlik adres yolu vardı; 8086 ile adres yolu 20 bite genişletildi. Sonraki işlemcilerde yazmaç ve adres boyutu 32'ye, sonra 64'e çıkarıldı. 8086'yı popüler kılan şey, 20 bitlik adres ile 16 bitlik yazmacın uyumsuzluğunun segment yapısı ve mandal devreleriyle sorunsuz çözülmesidir. Ortak bacaklar olduğu sürece 32/32 bir yapıda da mandal devresi gerekirdi.

> **Ders sonrası not:** Hoca 32 bitlik yazmaç ve 32 bitlik adres yoluna geçen işlemcinin 80286 mı 80386 mı olduğundan emin olamadı. Büyük olasılıkla doğrusu 80386'dır; 80286 16 bitlik yazmaçlara ve 24 bitlik adres yoluna sahiptir.

## Örnek Sorular

### Soru 1

(ekrandan, 00:50:00) Segment değeri `1000H`, ofset değeri `2000H` ise mikroişlemcide erişilen fiziksel adres ne olur?

> **Çözüm (derste verildi):** $1000H \times 10H = 10000H$; $10000H + 2000H = 12000H$. Gösterim: `1000H:2000H`.

### Soru 2

(ekrandan, 00:50:00) Bir segment değeri neden 64 KB'lık alanı gösterir?

> **Çözüm (derste verildi):** Ofset 16 bittir, çünkü 8086'nın yazmaçları 16 bittir. 16 bitlik ofset `0000H`-`FFFFH` arasında değer alır; bu $2^{16} = 65\,536$ farklı bayt, yani 64 KB eder.

### Soru 3

(derste sözlü, 00:10:20) 20 bitlik adres yolu neden 1 MB'lık adres uzayı verir? $2^{20}$ bit 1 MB etmez mi?

> **Çözüm (derste verildi):** 20 bit, verinin büyüklüğü değil adresin kendisidir ve $2^{20}$ (yaklaşık 1 milyon) farklı gözü seçer. Her göz 1 bayt tuttuğu için adres uzayı $2^{20} \times 1 \text{ bayt} = 1 \text{ MB}$ olur.

### Soru 4

(derste sözlü, 00:41:06; ekrandan, 00:45:00) Fiziksel adresten segment ve ofset değerleri tek türlü geri bulunabilir mi? `1234H:0005H` ve `1231H:0035H` çiftlerini karşılaştırın.

> **Çözüm (derste verildi):** $1234H \times 10H + 0005H = 12340H + 0005H = 12345H$ ve $1231H \times 10H + 0035H = 12310H + 0035H = 12345H$. İki farklı çift aynı fiziksel adresi verdiği için geri dönüş tek türlü değildir.

### Soru 5

(ekrandan, 01:00:00) DS = `0100H`, BX = `1000H`, hafızada `02000H` gözünde `12H`, `02001H` gözünde `34H` varken `MOV AX, [BX]` komutundan sonra AX ne olur?

> **Çözüm (derste verildi):** Fiziksel adres $0100H \times 10H + 1000H = 02000H$. AX 16 bit olduğu için `02000H` ve `02001H` okunur; little-endian düzende AL = `12H`, AH = `34H`, yani AX = `3412H`.

### Soru 6

(derste sözlü, 00:21:27) Segment ve ofset gönderirken ikinci değeri (ofseti) 16 bit yerine 8 bit (AL gibi) göndersek ne olur?

> **Çözüm (derste verildi):** Ofset 8 bit olursa her segmentin içi yalnızca `00H`-`FFH` arası adreslenebilir. Segmentler küçülür, aralarda adreslenemeyen boşluklar kalır ve 1 MB'lık alanın tamamı kaplanamaz. Hafızanın tamamını kesintisiz kaplamak için ofset de 16 bit olmalıdır.

### Soru 7

(derste sözlü, 00:46:51) 8 bitlik bir veride iki bit birden değişirse eşlik bayrağı bu hatayı yakalar mı?

> **Çözüm (derste verildi):** Hayır. İki bit birden değişince 1'lerin sayısının tek/çift durumu değişmez; eşlik yalnızca tek sayıda bitin değiştiği hataları yakalar. Daha güçlü denetim için CRC ya da checksum gerekir.

### Soru 8

(derste sözlü, 01:48:58) 20 bitlik adres yoluna rağmen 8086'da neden 20 bitlik yazmaç değil de 16 bitlik yazmaç var?

> **Çözüm (derste verildi):** Mimari kuşaklar halinde gelişti; bir önceki kuşaktaki 8 bit yazmaç/16 bit adres yapısından 16 bit yazmaç/20 bit adres yapısına geçildi. Uyumsuzluk segment yapısı ve mandal devreleriyle çözüldüğü için sorun yaratmadı; sonraki kuşaklarda yazmaç ve adres genişliği eşitlendi (32/32, 64/64).

## Dersin Toparlaması

Bu derste 8086'nın 16 bitlik yazmaçlarla 20 bitlik adres yolunu nasıl bir araya getirdiği temel soru olarak ele alındı. EU ve BIU birimleri, genel amaçlı, işaretçi, indis ve segment yazmaçları, bayrak yazmacı tanıtıldı. Segment:ofset yapısının neden gerektiği, fiziksel adresin $\text{segment} \times 10H + \text{ofset}$ ile nasıl hesaplandığı ve bir segmentin neden 64 KB olduğu örneklerle gösterildi. Ardından `MOV` komutu üzerinden veri adresleme modları (yazmaç, anında, doğrudan, yazmaç dolaylı, taban+indis, göreli), program hafızası adresleme ve yığın adresleme anlatıldı.

Dersin son bölümünde 8086'nın 40 bacaklı uç yapısı, ortak adres/veri uçları ve ALE, $\overline{BHE}$, NMI/INTR, minimum/maksimum mod gibi uçlar ile adres/veri ayrımını sağlayan 74LS373 mandal, 74LS245 transceiver ve 74LS244 tampon entegreleri incelendi. Bir sonraki derste ilk dış birim (çevre birimi) entegresine geçilecek; bu entegrede port okuma/yazma, burada tanıtılan IO/M, $\overline{RD}$, $\overline{WR}$ gibi uçlarla birlikte kullanılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
