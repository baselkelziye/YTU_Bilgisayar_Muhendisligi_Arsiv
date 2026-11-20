# Ders 4 Genişletilmiş Notu: Laboratuvar Tanıtımı: Proteus ile 8086 Devre Tasarımı ve Adres Çözümlemeye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvarın yapısı ve Proteus
- 2. Proteus'ta 8086 projesi oluşturma
- 3. 8086 sembolü ve uç bağlantıları
- 4. Şematik çizim: yol, terminal ve etiketleme
- 5. Eleman kütüphanesi ve 74273
- 6. 8255 ile temel G/Ç
- 7. 74LS137 ile adres çözümlemeye giriş
- 8. Laboratuvar şablonu: devre blokları
- 9. 16 bitlik veri yolunda 8 bitlik çevre birimi: F8h örneği
- 10. Benzetimi çalıştırma ve örnek kod
- Örnek Sorular

## 1. Laboratuvarın yapısı ve Proteus

Bu kayıt dersin laboratuvar bölümünün tanıtım oturumudur ("Lab 0") ve bir araştırma görevlisi tarafından anlatılmıştır. Ekranda dönem boyunca yapılacak laboratuvarların konuları listelenir (ekrandan, 00:05:00): 8255 ile temel G/Ç (Basic I/O), 8255 ile el sıkışma (handshake), USART, sayıcılar (counters) ve kesmeler (interrupt). Bu sıra, dersin teorik bölümünde işlenecek çevre birimlerinin sırasıyla örtüşür.

Laboratuvarda verilen her problemin çözümünde iki temel adım vardır. Birincisi donanım adımıdır: şematik üzerinde bağlantıları yapmak, gerekirse ek bir donanım elemanı eklemek. İkincisi yazılım adımıdır: problemi algoritmik olarak düşünüp 8086 assembly kodunu yazmak. Eskiden kodun yüklenip gerçek donanım elemanlarıyla denendiği fiziksel mikroişlemci deney kartları kullanılırken, artık bilgisayar ortamında benzetim yapan Proteus yazılımı kullanılır. Proteus'ta iki sekme vardır: kodun yazıldığı "Source Code" sekmesi ve kodun yüklendiği işlemcinin bağlı olduğu, sürükle bırak mantığıyla çalışan "Schematic Capture" sekmesi.

## 2. Proteus'ta 8086 projesi oluşturma

Proteus açıldığında "New Project" ile yeni bir proje başlatılır ve projeye ad verilir (örnekte "lab_0"). Ardından şu adımlar izlenir:

- "Create a schematic from the selected template" varsayılan olarak seçili kalır.
- PCB ile işimiz olmadığı için "Do not create a PCB layout" seçili kalır.
- Önemli adım: "Firmware Project" seçilir. Aile (family) olarak 8086, denetleyici (controller) olarak 8086 seçilir.
- Derleyici (compiler) seçilmelidir. Listede MASM32 bulunur; ilk kullanımda "Download" ile indirilip kurulum sihirbazı tamamlanır, sonra seçilebilir hâle gelir.
- Özet ekranında şablonun yeri, PCB olmadığı ve "Firmware project: 8086 compiled by MASM32, autoplace processor on schematic" bilgisi görülür (ekrandan, 00:15:00). "Finish" ile proje oluşturulur.

> **Hocanın vurgusu:** Derleyiciyi seçmeyi unutmayın; bazı öğrenciler bu adımı atlıyor.

Proje oluşunca solda şematik, sağda kaynak kod sekmesi açılır. Kaynak kod sekmesine 8086 için uygun biçimde assembly kodu yazılır. Şematik sekmesinde ise elemanlar sürüklenip bırakılır, bağlanır, etiketlenir; giriş-çıkış elemanları ve gerekirse benzetim için osiloskop eklenir. 8086 ve MASM32 seçildiği için şematiğe otomatik olarak bir 8086 yerleştirilmiş olur; bazı uçları bağlıdır, bazıları boştur. Laboratuvarlarda genellikle sıfırdan proje yerine bazı bölümleri önceden bağlanmış bir şablon verilir.

## 3. 8086 sembolü ve uç bağlantıları

Ekranda Proteus'un yerleştirdiği 8086 sembolü (U1) ve dört soru gösterilir (ekrandan, 00:20:00): RESET nereye, neden bağlı? READY neden üçgene bağlı, üçgen sembolü nedir? Koyu mavi ve kırmızı pinler neden farklı kalınlıkta? AD ne demek?

Sembolde sol tarafta RESET (21), READY (22), $\overline{INTA}$/QS1 (24), INTR (18), HOLD/$\overline{GT1}$ (31), HLDA/$\overline{GT0}$ (30), $\overline{TEST}$ (23), NMI (17), MN/$\overline{MX}$ (33), CLK (19); sağ tarafta AD[0..15], A[16..19], ALE/QS0 (25), $\overline{BHE}$ (34), DT/$\overline{R}$/$\overline{S1}$ (27), $\overline{DEN}$/$\overline{S2}$ (26), $\overline{RD}$ (32), $\overline{WR}$/$\overline{LOCK}$ (29), M/$\overline{IO}$/S0 (28) uçları bulunur. Bu uçların bazıları sık kullanılır, bazıları hiç kullanılmaz. Slaytlarda uçların giriş (I) ya da çıkış (O) olduğu belirtilmiştir; çift tıklayınca işlemcinin program dosyası ve saat frekansı gibi özellikleri görülür.

### 3.1 RESET, READY ve MN/MX

RESET toprağa bağlıdır, yani 0'dır: işlemci çalıştığı sürece sıfırlama durumu oluşmamalıdır. READY ve MN/$\overline{MX}$ üçgen sembolüne bağlıdır; üçgen lojik 1 (güç) demektir. READY'nin 1 olması işlemcinin hazır kabul edilmesi, MN/$\overline{MX}$'in 1 olması işlemcinin minimum modda çalışması anlamına gelir. Derste 8086 hep minimum modda kullanılır; böylece ek tampon ve benzeri devrelere gerek kalmaz.

Uç adındaki çizgi (şapka) etkin seviyeyi gösterir. MN'nin üzerinde şapka yoktur, MX'in üzerinde vardır. Bu yüzden uca 1 verilirse minimum mod, 0 verilirse maksimum mod seçilir. Genel kural şudur: şapkalı bir giriş 0 ile beslendiğinde etkin olur (aktif düşük), şapkasız giriş 1 ile beslendiğinde etkin olur. Eğik çizgiyle ayrılmış adlar (MN/$\overline{MX}$ gibi) ucun iki durumdaki anlamını gösterir.

Aynı kural çıkışlar için de geçerlidir. ALE (Address Latch Enable) şapkasız bir çıkıştır; 1 olduğunda yolda adres bilgisi bulunduğunu, yani adresin yakalanabileceğini bildirir.

### 3.2 AD uçları ve yol kalınlığı

AD, adres ve veri (address/data) demektir. Aynı kalın hattan aynı anda hem adres hem veri okunmaz; zaman paylaşımı (time multiplexing) vardır. 16 bit, bazen adres bazen veri taşımak için ortak kullanılır. A16-A19 ise yalnız adres taşır ve 20 bitlik adresi tamamlar.

Koyu mavi kalın çizgiler yoldur (bus): birden fazla biti birlikte taşır. İnce kırmızı çizgiler tek hattır (single line). Bağlantı yaparken bu ayrım gözetilir; yol ile tek hat farklı biçimde çizilir.

## 4. Şematik çizim: yol, terminal ve etiketleme

Yol çizerken "bus" modu seçilir. Boş bir yere sağ tıklayıp "Place" ile terminal seçilerek AD0-AD15 yolu bir yol terminaliyle sonlandırılabilir; çizginin sonundaki üçgen, yolun orada bittiğini gösterir. İki yol da aralarına yol çizilerek birleştirilir.

Devre büyüdüğünde, sağ üstte uzak bir devreye AD yolundan birkaç bit çekmek gerekebilir. Bunu beş altı yerde yapmak karmaşık bir çizim üretir. Bunun yerine etiketleme (label) yapılır: yola ya da tek hatta sağ tıklayıp "Edit Properties" penceresindeki "Label" sekmesinden bir ad verilir. Örnekte yola uçla aynı ad, AD[0..15], verilmiştir. Başka bir yerde aynı adla bir yol çizilirse, arada kablo olmasa da iki yol bağlı sayılır.

Etiketleme tek hatlar için de yapılır. AD yolundan tek tek bitler çekilip her birine AD0, AD1, ... adı verilir. Örneğin AD0 etiketli hat 74273'ün D0 girişine (3 numaralı uç) bağlanarak işlemcinin adres/veri 0. biti flip-flop'a getirilir. AD0'dan AD7'ye kadar aynı işlem yapılırsa 16 bitin düşük anlamlı byte'ı (least significant byte) aktarılmış olur.

Güç ve toprak gibi elemanlar sol araç çubuğundaki sembolden alınır. Aynı yerden "default" terminal de seçilebilir: işlemcinin bir ucuna, örneğin $\overline{RD}$ (32) ya da $\overline{WR}$ (29) ucuna bir terminal bağlanıp etiket verilir ve bu sinyal başka yerde aynı adla çağrılır. Bu yöntem özellikle 8255'in chip select bağlantısında kullanılacaktır.

Soru-cevap kısmında etiketin önemi bir kez daha açıklanır: etiket kullanılmazsa her yolu fiziksel olarak sürükleyip bağlanacak yere kadar uzatmak gerekir. 44 farklı bağlantı olan bir tasarımda bu, karmakarışık bir devre demektir; etiket ise aynı bağlantıyı kablosuz kurar.

## 5. Eleman kütüphanesi ve 74273

Yeni eleman eklemek için sol araç çubuğundaki eleman modu seçilip "P" düğmesine basılır; anahtar kelimeyle arama yapılan "Pick Devices" penceresi açılır. Örneğin "74273", "flip flop" ya da direnç için "res" yazılınca kütüphanedeki uygun elemanlar listelenir.

Ekranda 74273 aramasının sonucu görülür (ekrandan, 00:25:00): 74273, 74ALS273, 74F273, 74HC273, 74HCT273, 74LS273 gibi sürümler "Octal D-Type Positive-Edge-Triggered Flip-Flops With Clear" açıklamasıyla listelenir. Önizlemede D0-D7 girişleri, Q0-Q7 çıkışları, CLK (11) ve aktif düşük MR (1) uçları vardır; D0 3 numaralı, Q0 2 numaralı uçtur. Eleman seçilip "OK" denince çalışma alanında istenen yere bırakılır.

## 6. 8255 ile temel G/Ç

8255, temel G/Ç ve el sıkışma gibi işlemleri sağlayan yardımcı bir çevre birimidir; teorik derste ayrıntısıyla anlatılacaktır. Temel G/Ç işlemine örnek olarak butonlardan veri okuyup bu veriyi LED'e yazmak verilir.

Ekrandaki 8255 sembolünde (ekrandan, 00:30:00) solda D0-D7 veri uçları AD[0..7] yoluna bağlıdır. Ayrıca $\overline{RD}$ (5) ve $\overline{WR}$ (36) uçları RD ve WR etiketlerine, A0 (9) ucu A1 etiketine, A1 (8) ucu A2 etiketine, RESET (35) toprağa, $\overline{CS}$ (6) ucu CS8255 etiketine bağlıdır. Sağda 8'er bitlik PA0-PA7, PB0-PB7 ve PC0-PC7 portları vardır. Soldaki veri yolundan gelen veri sağdaki portlara bağlı G/Ç cihazlarına gönderilir ya da onlardan okunur. 8255'in A0-A1 uçlarının işlemcinin A1-A2 hatlarına bağlanmasının nedeni 9. bölümdeki çift adres örneğinde görülür.

Sıfırdan bir proje kurulduğunda, eklenen 8255'in RESET ucu toprağa çekilmeli ve denetim sinyalleri beslenmelidir; aksi hâlde eleman doğru çalışmaz.

## 7. 74LS137 ile adres çözümlemeye giriş

8255 belli adreslerde çalışmalıdır. Bunun için işlemcinin ürettiği adres süzülür ve yalnız istenen adres geldiğinde 8255 etkinleştirilir; buna adresleme (adres çözümleme) denir. Bu iş için bir kod çözücü (decoder) kullanılır. Örnekte kütüphanede "74LS137" aranır ve 3'e 8 kod çözücü seçilir.

Kod çözücünün mantığı şudur: $n$ girişli bir kod çözücü $2^n$ çıkış verir. $n = 3$ ise $2^3 = 8$ çıkış vardır; girişteki 3 bitlik her kombinasyon çıkıştaki 8 durumdan birine eşlenir. 000 geldiğinde 0. çıkış, 001 geldiğinde 1. çıkış seçilir ve bu, 111 için 7. çıkışa kadar sürer.

### 7.1 Veri sayfası ve doğruluk tablosu

Ekranda 74LS137 veri sayfası ve işlev tablosu gösterilir (ekrandan, 00:35:00). Uçlar: A (1), B (2), C (3), $\overline{GL}$ (4), $\overline{G2}$ (5), G1 (6), Y7 (7), GND (8), Y6-Y0 (9-15), VCC (16). Üç etkinleştirme girişinden G1 aktif yüksek, $\overline{GL}$ ve $\overline{G2}$ aktif düşüktür; tabloda $\overline{GL}$ = L, G1 = H, $\overline{G2}$ = L olduğunda seçim girişleri çıkışa yansır. Tablonun diğer satırlarında $\overline{G2}$ = H ya da G1 = L iken bütün çıkışlar H'dir.

A, B, C seçim girişleridir ve buraya adres bitleri verilecektir. C en anlamlı, B ortanca, A en az anlamlı bittir. Çıkışlardaki küçük yuvarlak (bubble) çıkışların aktif düşük olduğunu gösterir: seçilen çıkış L, diğerleri H olur.

Örnek (adım adım): C = L, B = L, A = H, yani CBA = 001.

- 001 ikilik sayısı 1'e eşittir, dolayısıyla Y1 seçilir.
- Çıkışlar aktif düşük olduğundan Y1 = 0, diğerleri 1'dir.
- Y0'dan Y7'ye: 1 0 1 1 1 1 1 1.

> **Ders sonrası not:** Anlatımda çıkış dizisi "1, 0, 1, 1, 1, 1, 1" diye yedi değerle okunmuştur; sekiz çıkışın doğru dizisi 1 0 1 1 1 1 1 1'dir (ekrandaki tablodan ve python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** 74LS137'nin $\overline{GL}$ ucu büyük olasılıkla adres tutma (latch enable) girişidir; tablonun son satırına göre $\overline{GL}$ = H olunca çıkış, tutucuda saklanan adrese göre kalır. Bu yüzden 74LS138'den farkı içinde bir adres tutucu bulunmasıdır. Proteus şablonundaki sembolde bu üç uç E1, E2 ve LE olarak adlandırılmıştır (ekrandan, 00:40:00).

Kod çözücünün uygun bir çıkışı 8255'in $\overline{CS}$ ucuna verilir. Belirli bir adres kombinasyonu geldiğinde o çıkış 0 olur ve 8255 o adres için etkinleşir.

## 8. Laboratuvar şablonu: devre blokları

Laboratuvarlarda paylaşılan tipik şablon ekranda gösterilir (ekrandan, 00:40:00). Solda 8086 (U1) vardır; NMI ucu bir etikete, $\overline{RD}$, $\overline{WR}$ ve M/$\overline{IO}$ uçları terminallere bağlıdır. Ortada üç 74273 bulunur: U6 AD0-AD7'yi alıp A0-A7'yi, U7 AD8-AD15'i alıp A8-A15'i, U10 AD16-AD19'u alıp A16-A19'u verir; çıkışlar ADR[0..19] yoluna toplanır. Sağda 74LS137 (U2), CS8255 etiketi, 8255A (U4), dört buton ve 7 parçalı bir gösterge vardır. 74273'lerin CLK ve MR uçları boş bırakılmıştır.

### 8.1 74273'ler neden var?

Derste bu soru sorulur. Kabaca söylemek gerekirse 74273'ler bir süzgeç görevi görür. AD hatları bazen adres, bazen veri taşıdığından, adres taşıdıkları anda bu adresin soldaki AD'lerden sağdaki A'lara aktarılması gerekir. Sekizli D flip-flop'lar saat girişinde uygun kenar geldiği anda D girişindekini Q çıkışına aktarır. Bu kenar, adres verisinin AD'lerde bulunduğu ana denk getirilirse adres flip-flop'larda tutulur. Böylece 8086 tasarımcılarının az uç kullanmak için seçtiği zaman paylaşımlı yol, mühendisin tarafında bu devreyle çözülür.

Adres 20 bittir (0-19), veri 16 bittir (0-15). Çıkış yoluna ADR etiketi verildiği için devrenin herhangi bir yerinde istenen adres biti bu etiketle çağrılabilir.

> **Hocanın vurgusu:** MR, reset ile ilgilidir; nasıl besleneceği veri sayfasından bulunmalıdır. Asıl önemli olan CLK'dır. İşlemcide adresle ilgili bir sinyal vardır ("şu anda yolda adres var" der); adresler tam yerleştiğinde CLK bu sinyalle uygun biçimde beslenmelidir. Bunu bulmak laboratuvar görevine bırakıldı.

### 8.2 Blokların birleşimi

Tasarım bloklara ayrılabilir:

- İşlemci bloğu (8086).
- Adres tutma bloğu: adresin veriden ayrılıp süzüldüğü 74273'ler.
- Adres çözümleme bloğu: ortadaki kod çözücü.
- Yardımcı çevre birimi: 8255 ya da sayıcı, USART, ADC/DAC.
- Bunlara bağlı giriş-çıkış elemanları: buton, LED, osiloskop vb.

Laboratuvar sorusu genellikle "8255 yalnız şu adreste çalışsın" der. Tutulan adresin istenen adres olup olmadığı kod çözücüyle bir kez daha süzülür; kod çözücü çıkışının bir biti uygun seviyeye gelince 8255 etkinleşir. O adreste 8255 veri okuyorsa okur, yazıyorsa yazar; okuma mı yazma mı yapılacağı yazılan assembly kodundaki komutlara bağlıdır.

## 9. 16 bitlik veri yolunda 8 bitlik çevre birimi: F8h örneği

Adres çözümleme teorik derste ayrıntısıyla anlatılacağından burada yalnız ana fikir verilir. 8086'nın veri yolu 16 bit, 8255 ise 8 bitlik bir çevre birimidir.

Ekrandaki tablo (ekrandan, 00:45:00):

| $\overline{BHE}$ | A0 | Aktarım |
|---|---|---|
| 0 | 0 | Anlamlı değil |
| 0 | 1 | Tek adresteki byte, D8-D15 |
| 1 | 0 | Çift adresteki byte, D0-D7 |
| 1 | 1 | Anlamlı değil |

A0 adresin en sağdaki, en az anlamlı bitidir ve adresin çift mi tek mi olduğunu belirtir. $\overline{BHE}$'nin şapkalı olması, 1 olduğunda yüksek byte'ın etkin olmadığı anlamına gelir. $\overline{BHE}$ = 1 ve A0 = 0 iken 16 bitlik yolun yüksek kısmı değil, düşük kısmı (D0-D7) etkindir.

> **Ek bilgi (derste anlatılmadı):** Bu tablo 8 bitlik bir çevre birimi bağlamında verilmiştir. Bellek erişiminde $\overline{BHE}$ = 0, A0 = 0 durumu büyük olasılıkla çift adresten başlayan 16 bitlik (word) aktarım anlamına gelir; $\overline{BHE}$ = 1, A0 = 1 ise hiçbir byte'ın aktarılmadığı durumdur.

### 9.1 Örnek: F8h başlangıç adresli 8255

Soru: 8255'i başlangıç G/Ç adresi F8h olacak ve yalnız çift adresler kullanılacak biçimde bağlamak istiyoruz.

- 8255 dört ardışık port adresine ihtiyaç duyar (ayrıntısı 8255 dersinde görülecek).
- Başlangıç adresi F8h'dir. Yalnız çift adresler kullanılacağı için sonraki adres F9h değil FAh'dir. On altılık düzende FAh'den sonra FBh atlanır ve FCh gelir; FDh atlanır ve FEh gelir.
- Adresler ikiliğe açılır (A7'den A0'a):

| Adres | A7 | A6 | A5 | A4 | A3 | A2 | A1 | A0 |
|---|---|---|---|---|---|---|---|---|
| F8H | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| FAH | 1 | 1 | 1 | 1 | 1 | 0 | 1 | 0 |
| FCH | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |
| FEH | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |

- Dört adreste de A0 = 0'dır. Bu, istenen "çift adres" koşulunun sağlandığını gösterir ve tabloya göre verinin D0-D7 üzerinden aktarılacağı anlamına gelir.
- Değişen bitler A2 ve A1'dir (00, 01, 10, 11). Ekranda bunlar "A2-A1 Register Select" olarak işaretlenmiştir: 8255'in kendi A0 ve A1 uçları işlemcinin A1 ve A2 hatlarıyla beslenir. Bu, 6. bölümdeki şemada 8255'in A0 ucunun A1 etiketine, A1 ucunun A2 etiketine bağlı olmasının nedenidir.
- Kalan bitler (A7, A6, ... A3) adrese ait bilgidir; 74273'lerden geçmiş ADR bitlerinden seçilerek kod çözücüye verilir ve 8255'in $\overline{CS}$ ucu bunlarla üretilir. Tam adres çözümleme teorik derste yapılacaktır.

Tablodaki ikilik açılımlar python ile doğrulanmıştır.

## 10. Benzetimi çalıştırma ve örnek kod

Proteus'ta fare tekerleğiyle yakınlaştırılır, sürükleyerek çizilir, Escape ile işlemden vazgeçilir. Eleman kütüphanesinden ihtiyaç duyulan elemanlar (örneğin şablonda verilmemişse bir buton) eklenir. Bir elemana bir kez tıklayıp "OK" denince ikinci tıklamada istenen yere bırakılır; uçları basılı tutup sürükleyerek bağlantı yapılır. Gereken yerlerde toprak ve lojik 1 bağlamayı unutmamak gerekir. Canlı gösterimde 8086'nın ALE ucuna bir terminal bağlanıp "ALE" etiketi verilmiş, 74ALS137 de çalışma alanına eklenmiştir (ekrandan, 00:50:00).

Ardından derslerin başında hocaların paylaştığı örneklerden biri açılır: adres çözümleme devresi kurulmuş, seçilen adres değerlerine göre kod çözücünün uygun çıkışı 8255'in chip select ucuna bağlanmış, giriş-çıkış birimleri 8255'e bağlanmıştır. "Run Simulation" düğmesine basınca benzetim başlar; butonlara basıldıkça LED'lerin davranışı değişir. Kaynak kod sekmesinde bu örneğin kodu görülür (ekrandan, 00:55:00):

```text
CODE    SEGMENT PUBLIC 'CODE'
        ASSUME CS:CODE

START:
        MOV AL, 81H
        OUT 66H, AL
        MOV AL, 0FFH
        out 64H, AL
        ; Write your code here
ENDLESS:
        IN AL, 64H
        OR AL, 0F0H
        CMP AL, 0FFH
        JZ ENDLESS
        MOV CL, 4
        SHL AL, CL
        OUT 64H, AL
        JMP ENDLESS
CODE    ENDS
        END START
```

Kodun başındaki yorumlarda işlemcinin 8086, derleyicinin MASM32 olduğu ve benzetimden önce 8086 model özelliklerinde iç bellek boyutunun 0x10000 yapılması gerektiği yazar; derleme çıktısı "Compiled successfully." der. Kod derste satır satır açıklanmamıştır.

> **Ek bilgi (derste anlatılmadı):** 81H denetim sözcüğü (1000 0001) büyük olasılıkla 8255'i mod 0'da PA, PB ve PC'nin üst yarısı çıkış, PC'nin alt yarısı giriş olacak biçimde kurar; 66H denetim yazmacı, 64H port C adresidir (taban 60H, A2-A1 yazmaç seçimi). Döngü PC'nin alt dört bitini okur, üst dört biti 1 yapar; sonuç FFH ise (aktif düşük butonlardan hiçbiri basılı değilse) okumayı sürdürür, değilse değeri 4 bit sola kaydırıp PC'nin üst yarısına (LED'lere) yazar.

Kodun satır satır izlenmesi (debug) de mümkündür: kod satır satır yürütülürken alttaki pencerede AL, AH gibi yazmaçların değerleri görülür. Bu konu derste süre yetmediği için ayrıntılı gösterilmemiştir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00; derste sözlü, 00:17:23): Proteus'un yerleştirdiği 8086'da RESET nereye, neden bağlıdır? READY neden üçgene bağlıdır, üçgen sembolü nedir? Koyu mavi ve kırmızı uçlar neden farklı kalınlıktadır? AD ne demektir?

Çözüm (derste verildi): RESET toprağa (0) bağlıdır ki işlemci çalışırken sıfırlama durumu oluşmasın. Üçgen lojik 1'dir; READY = 1 ve MN/$\overline{MX}$ = 1 (minimum mod) verilir. Kalın mavi çizgiler çok bitli yol, ince kırmızı çizgiler tek hattır. AD adres/veri demektir: AD0-AD15 zaman paylaşımıyla bazen adres bazen veri taşır, A16-A19 yalnız adres taşır.

**Soru 2** (derste sözlü, 00:18:27): Derste 8086 hangi modda çalıştırılır ve MN/$\overline{MX}$ ucuna ne verilir?

Çözüm (derste verildi): Minimum mod; ek tampon gerekmesin diye. MN şapkasız olduğundan uca 1 verilir; 0 verilirse ($\overline{MX}$ etkin) maksimum mod seçilir.

**Soru 3** (derste sözlü, 00:19:23): ALE nedir, giriş mi çıkış mıdır, hangi seviyede etkindir?

Çözüm (derste verildi): Address Latch Enable; işlemcinin çıkışıdır. Şapkasız olduğundan 1 olduğunda yolda adres bulunduğunu bildirir.

**Soru 4** (ekrandan, 00:35:00): 74LS137'de $\overline{GL}$ = L, G1 = H, $\overline{G2}$ = L ve C B A = L L H iken Y0-Y7 çıkışları nedir?

Çözüm (derste verildi, düzeltilerek): CBA = 001 = 1 olduğundan Y1 seçilir. Çıkışlar aktif düşük olduğundan Y0..Y7 = 1 0 1 1 1 1 1 1.

**Soru 5** (derste sözlü, 00:38:00; ekrandan, 00:40:00): Laboratuvar şablonunda 74273'ler neden vardır?

Çözüm (derste verildi): AD hatları zaman paylaşımlı olduğundan, adres taşıdıkları anda adresi yakalayıp A0-A19 çıkışlarında tutmak için. CLK girişi adresin yolda bulunduğunu bildiren işlemci sinyaliyle beslenmelidir.

**Soru 6** (ekrandan, 00:45:00): "We want to use a 8255 PPI with the starting I/O address of F8h. Use even addresses only." 8255'in adreslerini, A0'ın değerini ve yazmaç seçim bitlerini bulunuz.

Çözüm (derste verildi): Adresler F8h, FAh, FCh, FEh'dir (1111 1000, 1111 1010, 1111 1100, 1111 1110). Hepsinde A0 = 0'dır; $\overline{BHE}$ = 1 ile veri D0-D7'den aktarılır. A2-A1 = 00, 01, 10, 11 yazmaç seçimini yapar; A7-A3 = 11111 adres çözümlemede kullanılır.

## Dersin Toparlaması

Bu oturumda laboratuvar çalışmalarının yürütüleceği Proteus ortamı tanıtıldı: 8086 ve MASM32 ile proje oluşturma, otomatik yerleştirilen 8086'nın RESET, READY ve MN/$\overline{MX}$ bağlantıları, şapkalı uçların aktif düşük anlamı, AD uçlarının zaman paylaşımı, yol ve tek hat çizimi ile etiketleme. Ardından laboratuvar şablonunun blokları incelendi: adresi zaman paylaşımlı yoldan ayırıp tutan 74273 flip-flop'ları, adresi süzüp 8255'in chip select ucunu süren 74LS137 kod çözücü ve G/Ç işlemini yapan 8255.

Son olarak 16 bitlik veri yolunda 8 bitlik bir çevre birimi kullanmanın ana fikri F8h örneğiyle verildi: çift adresler A0 = 0 demektir, veri D0-D7'den akar, A2-A1 8255'in yazmacını seçer ve üst adres bitleri kod çözücüye gider. Tam adres çözümleme ve 8255'in ayrıntıları teorik derslerde işlenecek, birinci laboratuvar 8255 ile temel G/Ç üzerine olacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
