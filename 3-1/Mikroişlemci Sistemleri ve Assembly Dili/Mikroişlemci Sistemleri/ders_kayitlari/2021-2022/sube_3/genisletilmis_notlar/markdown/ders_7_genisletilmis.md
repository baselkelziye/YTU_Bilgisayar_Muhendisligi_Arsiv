# Ders 7 Genişletilmiş Notu: Çevre Birimleri, Adres Çözümleme ve 8255'e Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çevre birimleri ve G/Ç adres uzayı
- 2. G/Ç haritalama yöntemleri: isolated ve memory mapped
- 3. Düğme arayüzü ve sıçrama (bouncing)
- 4. LED arayüzü
- 5. Basit çevre birimleri için adres çözümleme
- 6. Çevre birimi kontrol yöntemleri: yoklama ve kesme
- 7. 8255 programlanabilir çevre birimi arayüzü
- 8. 16 bitlik veri yolunda 8 bitlik çevre birimi
- 9. 8255 modları ve kontrol yazmacı
- Örnek Sorular

## 1. Çevre birimleri ve G/Ç adres uzayı

Bu derste mikroişlemcinin dış dünyayla iletişimi ele alınır: bir LED yakmak ya da söndürmek, bir düğmeden veri okumak gibi işler giriş-çıkış (G/Ç) birimleri, yani çevre birimleri üzerinden yapılır. Dersin ilk bölümünde basit düğme ve LED arayüzleri, ikinci bölümünde ise bu birimlerin organizasyonunu sağlayan 8255 entegresi anlatılır.

Slayttaki tanıma göre çevre birimleri (ekrandan, 00:05:00):

- giriş ve/veya çıkış cihazlarıdır,
- hafıza birimleri gibi belirli bir adres bölgesine yerleştirilir,
- hafıza birimine göre adres genişliği dardır (1-4 byte).

Mikroişlemciyi lojik derslerindeki bir kod çözücüden (decoder) ayıran temel nokta budur. 3'e 8 bir kod çözücüde girişlere 111 verildiğinde ilgili çıkış doğrudan seçilir ve oraya bağlı LED yakılabilir. Mikroişlemcide ise "şu LED'i yak" diye doğrudan bir port seçilmez; önce bir adres uzayı tanımlanır ve birim bu uzayda bir adrese yerleştirilir. İşlemci adres yolu üzerinden düğmenin ya da LED'in nerede olduğunu gösterir, birimi seçer, sonra veri yolundan okuma ya da yazma yapar. Adres yolu ile veri yolunun ayrı iki yol olmasının nedeni de budur.

Çevre birimlerine erişim Assembly'de iki komutla yapılır: `OUT` (veriyi porta gönder) ve `IN` (porttan akümülatöre veri oku).

### 1.1 Sabit ve değişken adresli G/Ç

G/Ç adresleri iki biçimde verilebilir:

- **Sabit (fixed) adres:** 8 bitlik adres, yani 00H ile 0FFH arası. Adres komutun içinde doğrudan yazılır; bu aralık sabit port adresleri için ayrılmıştır.
- **Değişken (variable) adres:** 16 bitlik adres `DX` yazmacına yüklenir ve komut `DX` üzerinden çalışır. 0100H ile 0FFFFH arası bu yolla kullanılır.

G/Ç işlemleri 8 ya da 16 bit olabilir: `AX` yazmacındaki 16 bitlik değer de gönderilebilir, yalnız yüksek ya da yalnız düşük anlamlı 8 biti de.

> **Ders sonrası not:** Hoca bir yerde "toplam 20 bitlik adres uzayının ilk 8 biti sabit, üstündeki 16 biti değişken" gibi bir ifade kullandı. Doğrusu: 20 bit bellek adres uzayıdır; G/Ç uzayı 16 bittir (64 KB). Bu uzayın 00H-0FFH kısmına 8 bitlik sabit adresle, tamamına `DX` ile erişilebilir.

## 2. G/Ç haritalama yöntemleri: isolated ve memory mapped

Mikroişlemci çevre birimlerinin adres düzenini kurarken iki yaklaşımı kabul eder (ekrandan, 00:10:00):

- **Isolated I/O Mapping:** $M/\overline{IO}$ ucu adres çözümleme için kullanılır.
- **Memory Mapped I/O:** $M/\overline{IO}$ ucu adres çözümleme için kullanılmaz.

### 2.1 Isolated I/O

Bu yaklaşımda G/Ç birimleri normal bellek adreslerinden farklı bir bölgede kabul edilir. Örneğin "32 numaralı adres" denildiğinde ana bellekteki 32. göze mi yoksa G/Ç uzayındaki 32 numaralı adrese mi gidileceği $M/\overline{IO}$ ucuyla belirlenir. Uç 1 olduğunda bellek seçilir ve 32 bellekteki gözü gösterir; uç 0 olduğunda G/Ç uzayı seçilir ve aynı adres bir çevre biriminden okuma ya da ona yazma anlamına gelir.

Hoca bunu kavramsal bir çizimle gösterdi: bir bellek bloğunun etkinleştirme ucu $M/\overline{IO}$ ucunun 1 değerinde, G/Ç bloğunun etkinleştirme ucu ise 0 değerinde (tümleyen girişle) çalışır. 8086'dan $M/\overline{IO}$=1 gelince bellek, 0 gelince G/Ç bloğu etkinleşir. Gerçek devrede araya başka ön devreler girer, ama temel mantık budur.

Isolated yöntemde iki ayrı uzay vardır: 20 bitlik, 1 MB'lık bellek uzayı ve 16 bitlik, 64 KB'lık G/Ç uzayı.

- Avantajı: komutlar ayrışır. `IN` ve `OUT` bellekten okumak için değil, çevre birimlerine erişmek için kullanılır. Bu, programları daha kolay ve anlaşılır kılar.
- Dezavantajı: G/Ç birimleri için fiziksel olarak ayrı bir uzay tasarlamak ve bunun için ek uçlar kullanmak gerekir.

Derste, lablarda ve sınavlarda genel olarak isolated yöntem kullanılacağı söylendi.

### 2.2 Memory mapped I/O

Slayta göre bazı işlemciler yalnız tek bir adres uzayına izin verir; bunlarda (ekrandan, 00:15:00):

- hafıza komutları ile G/Ç birimlerine erişilebilir,
- G/Ç birimleri için ayrı komutlara gerek yoktur,
- G/Ç ve hafıza işlemlerini ayıran fiziki uçlara gerek yoktur.

Bu yaklaşımda G/Ç kısmı belleğin içine gömülür: tek bellek uzayının bir bölümü (örneğin 64 KB'lık bir alan) G/Ç için ayrılır, bellek olarak 1 MB eksi bu alan kalır. G/Ç birimlerine `MOV` komutuyla erişilir. Derste bu yöntem üzerinde yoğunlaşılmayacağı belirtildi.

## 3. Düğme arayüzü ve sıçrama (bouncing)

Düğme arayüzü en basit giriş arayüzüdür; mikroişlemciye girdi verilmesini sağlar.

### 3.1 Sıçrama hatası

+5 V, bir düğme ve çıkışın alındığı bir düğümden oluşan basit bir devre düşünülsün. Teoride düğmeye basılmadığında çıkış 0, basıldığında 5 V'tur. Gerçekte ise düğmede mekanik bir titreşim (rezonans) vardır: çıkış hemen sabit seviyeye oturmaz, kısa bir süre birkaç kez salınır, sonra kararlı hale gelir. Buna sıçrama hatası (bouncing error) denir.

Program bu salınımı hesaba katmazsa hatalı kararlar verebilir. Yazılımda çözüm, basıştan sonra bir gecikme (delay) koyup değeri ancak sinyal kararlı hale geldikten sonra işlemektir. Donanımda ise sıçramayı önleyen (debounce) devreler vardır; bunlardan biri flip-flop tasarımıdır. Flip-flop veriyi bir süre içinde tuttuğu için ilk baştaki tepeleri eler. Proteus gibi simülasyon ortamlarında bu sorun görülmez, ama gerçek devrede bir ön devre gerekir.

### 3.2 Basınca 0 veren yapı

Hocanın vurguladığı ikinci nokta, mikroişlemcinin girişinde basılmadığı sürece lojik 1 olması ve düğmeye basılınca 0'a düşmesidir. Yani ucu sürekli 5 V besler ve basışta 0'a inmesi tespit edilir. 0'ı algılamak işlemci açısından daha basit bir yöntemdir.

> **Hocanın vurguladığı:** Sıçrama hatası ve düğmeye basılınca 0'ın algılanması, unutulmaması gereken iki noktadır.

### 3.3 Hangi düğme arayüzü doğru?

Slaytta altı düğme devresi verilmiş ve hangisinin bu yaklaşıma uygun olduğu soruldu (ekrandan, 00:20:00). Devreler (karedeki yerleşime göre):

| Konum | Devre | Değerlendirme |
|---|---|---|
| Sol üst | +5 V - düğme - 8086 | Basınca 1 verir, basılmayınca uç boşta; uygun değil |
| Orta üst | +5 V - düğme - düğüm; düğüm doğrudan toprağa ve 8086'ya | Basınca akım doğrudan toprağa akar, 8086 hep 0 okur; düğme bir şey değiştirmez |
| Sağ üst | +5 V - düğme - düğüm; düğüm 10 kΩ ile toprağa (R2) ve 8086'ya | Basmayınca 0, basınca 1; istenen yapının tersi |
| Sol alt | Toprak - düğme - 8086 | Basılmayınca da basınca da 0; uygun değil |
| Orta alt | Toprak - düğme - düğüm; düğüm doğrudan +5 V'a ve 8086'ya | Mantık doğru (normalde 1, basınca 0) ama 5 V doğrudan bağlı, koruma direnci yok |
| Sağ alt | Toprak - düğme - düğüm; düğüm 10 kΩ ile +5 V'a (R1) ve 8086'ya | Doğru cevap |

Doğru cevap sağ alttaki devredir. Orta alttaki devre de mantık olarak çalışır, ancak gerilim kaynağındaki dalgalanmalar yüzünden 5 V'un 8086 ucuna doğrudan bağlanması uygun değildir. Sağ alttaki devrede 10 kΩ'luk koruma direnci 8086'yı doğrudan 5 V ya da daha yüksek gerilimlerden korur; basılmayınca uç 1 olur, basınca 0 olur ve program 0'ın tespiti üzerine kurulabilir.

> **Ek bilgi (derste anlatılmadı):** Bu yapıya "pull-up direnci" denir. Direnç, düğme açıkken ucu 1'e çeker; düğme kapanınca uç toprağa bağlanır ve direnç üzerinden yalnız küçük bir akım akar, böylece kaynak kısa devre olmaz.

## 4. LED arayüzü

LED arayüzü basit bir çıkış devresidir. Buradaki ilke, LED'in mikroişlemcinin ucuyla doğrudan beslenmemesidir. Mikroişlemci uçları tetikleme için kullanılır: bir darbe ya da uzun süre 1 seviyesinde kalan bir kontrol sinyali üretirler. Proteus'ta uç doğrudan LED'e bağlansa LED yanar, ama gerçek hayatta bu yaklaşım kullanılmaz.

Slayttaki örnekler üzerinden hoca şunları söyledi (devre karesi kayıtta yok):

- Ucu doğrudan LED'e bağlayan devre simülasyonda çalışır ama gerçekte kullanılmaz; bir örnekte +5 V ters yönde verildiği için LED zaten yanmaz.
- Koruma direnci konmuş olsa bile mikroişlemcinin LED'i doğrudan beslemesi istenen durum değildir.
- LED'i sürekli besleyen bir devrede mikroişlemcinin gönderdiği verinin anlamı yoktur.
- Doğru yapıda uç bir transistörün beyzine bağlanır. Uç 0 iken transistör iletimde değildir ve +5 V LED'i yakmaz. Uç 1 olunca beyze akım verilir, transistör iletime geçer ve LED +5 V'tan beslenerek yanar.

<!-- BELİRSİZ: LED arayüzü devrelerinin slaytı (yaklaşık 00:22:00-00:24:30) karelerde yok; hangi devrenin doğru cevap olarak işaretlendiği yalnız anlatımdan kuruldu. -->

## 5. Basit çevre birimleri için adres çözümleme

Basit çevre birimlerinin de bir adres uzayına yerleşmesi için adres çözümlemesi gerekir. Slayttaki kural şudur (ekrandan, 00:25:00):

- Memory: A19-A(i+1)
- Variable I/O: A15-A(i+1)
- Fixed I/O: A7-A(i+1)

Bu bitler adres çözümleme devresine gitmelidir. Bellek bloğu 20 bitlik adresin tamamıyla adreslenir; G/Ç birimlerinde ise değişken adreslemede 16 bit, sabit adreslemede 8 bitlik adres bacakları kullanılır.

> **Ek bilgi (derste anlatılmadı):** Buradaki $i$, birimin içinde kendi adres uçlarıyla seçilen en yüksek bit numarası olarak okunabilir. Örneğin dört yazmaçlı bir birim A1-A0 ile kendi içinde seçim yapıyorsa ($i=1$), değişken G/Ç'de A15-A2 adres çözümleme devresine gider. Tek adresli bir birimde (8 LED gibi) bütün bitler çözümlemeye girer.

### 5.1 0F000H adresine 8 LED

Örnek: 8 LED 0F000H adresine yerleştirilecek, sonra bu LED'ler bir yanık bir sönük deseninde yakılacak (ekrandan, 00:30:00). Burada iki adım vardır: önce adres (donanımda LED'leri o adrese yerleştirmek), sonra veri (o adrese desen göndermek). İkisi aynı ortak yolu kullandığı için adım adım ilerlemek gerekir.

Devrede 74245 entegresi kullanılır. Hoca 74245'i hatırlattı: veri aktarım yönünü belirleyen çift yönlü bir tampondur (transceiver).

- DIR ucuna 5 V verilirse aktarım A portundan B portuna olur.
- DIR ucuna 0 (GND) verilirse aktarım B portundan A portuna olur.
- Bu aktarımlar ancak etkin düşük $\overline{E}$ ucu 0 iken gerçekleşir; $\overline{E}$=1 olursa entegre çalışmaz.

Karedeki devre:

```text
8086 (Minimum Mode)                74245                     LED'ler
D7 ... D0  ----------------------> A0 ... A7   B0 ... B7 --> 8 LED + dirençler --> GND
                                   DIR = 5V (A -> B)
                                   /E  <---- adres kod çözme kapısı
Kapı girişleri: A15 A14 A13 A12 (doğrudan), A11 ... A0 (tümleyen girişli),
                /WR + M//IO (tümleyen girişli)
```

Adres çözümleme yalnız $\overline{E}$ ucunda yapılan iştir. 0F000H = 1111 0000 0000 0000b olduğundan A15, A14, A13 ve A12 1, diğer bütün adres bitleri 0 olmalıdır. Ayrıca bu bir çevre birimi olduğu için $M/\overline{IO}$=0 (G/Ç seçimi), porta yazılacağı için $\overline{WR}$=0 olmalıdır. Kapı yalnız bu birleşimde çıkışını 0 yapar ve 74245 etkinleşir. Bir bit bile farklı gelirse (örneğin A0 yerine 1 gelirse) kapının çıkışı 1 olur, 74245 etkinleşmez ve 8 LED adres uzayında tetiklenmemiş olur. Adres çözümlemeden kastedilen budur.

Hoca, slayttaki çok girişli kapının kavramsal olduğunu, gerçekte bu kadar girişli bir kapının bulunmadığını da belirtti.

> **Ders sonrası not:** Hoca A19-A16'nın da kapıya 0 olarak girebileceğini söyledi. Karedeki kapının girişleri A15-A0 ile $\overline{WR}$ ve $M/\overline{IO}$'dur; G/Ç adres uzayı 16 bit olduğu için A19-A16 çözümlemeye girmez. Hoca adresi bir yerde "0F00H" diye okudu; doğrusu 0F000H.

Adres seçildikten sonra veri gönderilir. Ancak adres ve veri aynı ortak yoldan geçtiği için, adres ilk aşamada bir önceki hafta anlatılan mandal (latch) devresinde tutulur. Böylece yola başka bir veri konduğunda seçilen adres kaybolmaz; mandal yeni adres gelene kadar kapıyı beslemeye devam eder. Bu ön devre çizimde gösterilmemiştir.

Program (ekrandan, 00:30:00):

```text
    :
mov al, 55h
mov dx, 0F000h
out dx, al
    :
```

Adım adım:

- `mov al, 55h`: desen `AL`'ye yazılır. 55H = 0101 0101b, yani LED'ler bir yanık bir sönük olur.
- `mov dx, 0F000h`: değişken adresleme kullanıldığı için adres `DX`'e yüklenir.
- `out dx, al`: isolated yöntem kullanıldığı için `OUT` komutuyla desen o adrese gönderilir.

Sonuçta G/Ç uzayındaki 0F000H adresine yerleşmiş 8 LED'e desen gönderilmiş olur.

### 5.2 0F000H adresine 8 düğme

Aynı adrese bu kez 8 düğme yerleştirilir ve düğmeler okunur (ekrandan, 00:35:00). Farklar şunlardır:

- 74245'in DIR ucu GND'ye bağlıdır, yani aktarım B'den A'ya (düğmelerden işlemciye) olur.
- Okuma yapılacağı için kapıya $\overline{WR}$ yerine $\overline{RD}$ girer; $\overline{RD}$=0 olduğu durum kontrol edilir.
- Düğmelerin her biri bir uçla toprağa, diğer uçla bir direnç üzerinden 5 V'a bağlıdır; basılmayan düğmenin hattı 1'dir.

A15-A12 = 1111 ve geri kalanı 0 olduğunda kapı $\overline{E}$'yi etkinleştirir; artık 8 düğme yalnız 0F000H adresiyle okunabilir.

```text
    :
mov dx, 0F000h
in  al, dx
    :
```

`DX`'in gösterdiği G/Ç adresindeki veri `IN` komutuyla `AL`'ye okunur. (Hoca "port" kelimesini kullandığını, ama 8255'in portlarıyla karışmaması için bunun aslında "bu adresteki veri" olduğunu belirtti.)

### 5.3 Düğme bekleme döngüsü

Ardından aşağıdaki kodun ne iş yaptığı soruldu (ekrandan, 00:35:00):

```text
     mov dx, 0F000h
L1:  in  al, dx
     cmp al, 0FFh
     je  L1
     :
```

Bir öğrencinin cevabı: düğmelere hiç basılmadıysa düğmeler sürekli kontrol edilir. Hoca bunu açıkladı: bu devrede düğmelerin hatları 5 V'a çekilmiştir, adres seçilip okuma yapıldığında hiçbir düğmeye basılmamışsa bütün bitler 1 gelir, yani `AL` = 0FFH olur. `cmp al, 0FFh` bu değeri karşılaştırır; eşitse `je L1` başa döner. Bir düğmeye basılınca o bit 0 olur. Örneğin 5. bitteki düğmeye basılırsa okunan değer 1101 1111b = DFH olur, 0FFH'ye eşit olmaz ve döngüden çıkılır. Yani kod, herhangi bir düğmeye basılana kadar bekler.

### 5.4 Tartışma soruları

Slaytta üç soru daha gösterildi (ekrandan, 00:40:00), ama öğrencilerden cevap gelmediği için hoca cevaplamadan geçti ve araştırılmasını istedi. Sorular ve çözümleri "Örnek Sorular" bölümündedir.

## 6. Çevre birimi kontrol yöntemleri: yoklama ve kesme

Çevre birimlerinin kontrolü iki ana başlıkta, toplam üç biçimde yapılır: yoklamanın (polling) iki türü ve kesme (interrupt).

### 6.1 Öncelikli yoklama

Hoca bunu işletim sistemlerindeki süreç zamanlama algoritmalarına benzetti. Üç düğme olduğu düşünülsün:

- Birinci düğme kontrol edilir. Onunla iş bitmediyse, öncelikli olduğu için tekrar birinci kontrol edilir.
- Birinciyle iş bitince ikinciye geçilir. İkinciyle iş bitmese bile ikinci sürekli kontrol edilmez; başa dönülür ve birinci yeniden kontrol edilir.
- Birinci ve ikinciyle iş bittiyse üçüncüye geçilir; üçüncüden sonra yine birinciden başlanır.

Bu yaklaşım öncelikli birime daha sık gidilmesini sağlar.

### 6.2 Sıralı (round robin) yoklama

Birimler sırayla kontrol edilir: birinci girişi kontrol et, veriyi oku; ikinciyi kontrol et, veriyi oku; üçüncüyü kontrol et, veriyi oku; sonra başa dön. Burada her adımda en başa dönme yoktur; bir birimde veri yoksa doğrudan sonrakine geçilir.

**Soru:** Bu, işletim sistemlerindeki round robin zamanlamasıyla aynı mı? **Cevap:** Aynı yaklaşımdır. İşletim sistemlerinde süreçler belli zaman dilimleriyle dönüşümlü çalıştırılır; burada da portlar ya da giriş birimleri sırasal düzenle kontrol edilir.

### 6.3 Kesme

Kesme yönteminde birim bir kesme ürettiğinde işlemci o birime gider; kesme olmadığı sürece o birimle ilgilenmez. Günümüzde daha çok kullanılan yaklaşım budur. Konu ilerleyen haftalarda ayrıntılı işlenecek.

## 7. 8255 programlanabilir çevre birimi arayüzü

Şimdiye kadar anlatılan düğme ve LED'ler tek tek kullanılan basit birimlerdi. 8255 ise birden fazla porta sahip çevre birimlerini programlanarak kontrol etmeyi sağlayan bir entegredir. Dersin konu listesi (ekrandan, 00:45:00): 8255, pinleri, iç yapısı, 16 bit veri yolunda 8 bitlik çevre birimi, 8255 adres çözümleme ve 8255 modları (mod 0 ile LED ve buton, 7 parçalı gösterge, 3x4 tuş tarama; BSR; mod 1; mod 2). Bu derste mod 0'a kadar gelinir; mod 0 örnekleri sonraki derslere ve laba kalır.

### 7.1 Genel özellikler ve uçlar

8255'in genel adı programlanabilir çevre birimi arayüzüdür (Programmable Peripheral Interface, PPI).

- Üç adet 8 bitlik genel amaçlı port içerir: port A, port B, port C.
- Veri yolu genişliği 8 bittir. Mikroişlemci tarafındaki 8 bitlik veri girişi alınır ve ilgili porta yazılır ya da ilgili porttan okunur. 8086'nın veri yolu 16 bit olduğu için bunun nasıl bağlanacağı ayrıca ele alınır (Bölüm 8).
- **A1, A0:** port seçimi. 00 port A, 01 port B, 10 port C, 11 kontrol yazmacı.
- **$\overline{RD}$, $\overline{WR}$:** porttan okuma mı yapılacağını yoksa porta yazma mı yapılacağını belirler.
- **$\overline{CS}$ (chip select):** entegrenin çalışmasını sağlar. 8255'in 8086'nın adres uzayında nereye yerleşeceği bu uçla belirlenir; tıpkı 8 LED'in 0F000H'ye yerleştirilmesi gibi.
- **RESET:** entegreyi sıfırlar.

> **Hocanın vurgusu:** A1A0 = 11 durumu çok önemlidir. Bu durumda portlarla ilgisi kalmaz; gönderilen veri entegrenin iç yapısına gömülen bir kod, yani kontrol sözcüğüdür. Mikroişlemcinin bütün çevre birimi entegrelerinde, entegreyi yazılımla farklı modlara sokmaya yarayan böyle bir kontrol bloğu bulunur.

Uç tablosu (ekrandan, 00:50:00):

| A1 | A0 | $\overline{RD}$ | $\overline{WR}$ | $\overline{CS}$ | İşlem (Okuma) |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 0 | PORTA → Data Bus |
| 0 | 1 | 0 | 1 | 0 | PORTB → Data Bus |
| 1 | 0 | 0 | 1 | 0 | PORTC → Data Bus |
| 1 | 1 | 0 | 1 | 0 | Control Word → Data Bus |

| A1 | A0 | $\overline{RD}$ | $\overline{WR}$ | $\overline{CS}$ | İşlem (Yazma) |
|---|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 | Data Bus → PORTA |
| 0 | 1 | 1 | 0 | 0 | Data Bus → PORTB |
| 1 | 0 | 1 | 0 | 0 | Data Bus → PORTC |
| 1 | 1 | 1 | 0 | 0 | Data Bus → Control Word |

Hocanın örneği: A1, A0, $\overline{RD}$, $\overline{WR}$, $\overline{CS}$ = 0, 1, 0, 1, 0 ise port B seçilmiştir ve $\overline{RD}$=0 olduğu için port B'deki veri işlemcinin veri yoluna okunur.

### 7.2 İç yapı

İç yapıda bir okuma/yazma kontrol birimi, A1-A0 ile port seçimi ve iki kontrol grubu vardır:

- Port A'nın 8 biti vardır ve 8 biti birlikte giriş ya da çıkış yapılır; port A tamamen grup A'ya bağlıdır.
- Port B'nin 8 biti de birlikte ayarlanır; port B tamamen grup B'ye bağlıdır.
- Port C ikiye bölünür: yüksek anlamlı 4 biti (PCH) grup A'da, düşük anlamlı 4 biti (PCL) grup B'dedir. Bu iki yarı iç yapıda ayrı birimler olduğu için ayrı ayrı giriş ya da çıkış yapılabilir.

Örneğin port A tamamen giriş, port B çıkış, port C'nin üst 4 biti giriş, alt 4 biti çıkış olarak programlanabilir. Programlama A1A0=11 durumunda kontrol sözcüğüyle yapılır.

8255'in üç modu vardır: mod 0 doğrudan porta yazma ve porttan okumadır. Mod 1 ve mod 2 daha gelişmiş modlardır (kesme ve el sıkışma devreye girer); bu modlarda port C veri okuma-yazma için değil, programlama, kontrol ve durum belirleme için kullanılır. Port A ve port B ise her zaman veri için kullanılır.

## 8. 16 bitlik veri yolunda 8 bitlik çevre birimi

8086'nın veri yolu 16 bittir (D0-D15), ama 8255'in veri yolu 8 bittir ve üç 8 bitlik portu vardır. Bunu çözmek için 8086'nın $\overline{BHE}$ (bus high enable) ucu ile A0 birlikte kullanılır. $\overline{BHE}$=0 olduğunda yüksek anlamlı veri yolu (D8-D15) etkinleşir.

> **Ders sonrası not:** Hoca "$\overline{BHE}$'ye 1 verildiğinde düşük anlamlı D0-D7 aktif olur" dedi. Doğrusu: düşük bayt (D0-D7) $A0=0$ ile seçilir, yüksek bayt (D8-D15) $\overline{BHE}=0$ ile seçilir. $\overline{BHE}=1$ yalnız yüksek baytın kullanılmadığını gösterir. Bu yüzden çift adreslerdeki bayt D0-D7'den, tek adreslerdeki bayt D8-D15'ten aktarılır.

### 8.1 Yalnız çift adresler (F8H başlangıç)

Örnek: 8255 F8H başlangıç G/Ç adresine yerleştirilecek, yalnız çift adresler kullanılacak (ekrandan, 00:55:00). 8255'in dört birimi (port A, port B, port C ve kontrol yazmacı) olduğu için G/Ç uzayında dört adres gerekir. Çift adresler istendiği için adresler ikişer artar: F8H, FAH, FCH, FEH.

| | A7 | A6 | A5 | A4 | A3 | A2 | A1 | A0 |
|---|---|---|---|---|---|---|---|---|
| F8H | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| FAH | 1 | 1 | 1 | 1 | 1 | 0 | 1 | 0 |
| FCH | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |
| FEH | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 |

Tablodan görüldüğü gibi değişen bitler A2 ve A1'dir (slaytta "A2-A1 Register Select"). Bu yüzden CPU'nun A2 ucu 8255'in A1'ine, CPU'nun A1 ucu 8255'in A0'ına bağlanır: A2A1 = 00 port A, 01 port B, 10 port C, 11 kontrol yazmacı.

Devre (ekrandan, 01:00:00):

```text
CPU                         8255 PPI
D0-D7   <==============>    D0-D7
A2      ---------------->   A1
A1      ---------------->   A0
RD#     ---------------->   RD#
WR#     ---------------->   WR#

3'e 8 kod çözücü:
  A3 -> A0 (LSB), A4 -> A1, A5 -> A2 (MSB)
  M/IO# -> E1 (etkin düşük)
  A0    -> E2 (etkin düşük)
  A7 VE A6 -> E3 (etkin yüksek)
  Çıkış 7 (etkin düşük) -> CS#
```

Açıklama:

- Çok girişli bir kapı yerine kod çözücü kullanılır. 3'e 8 kod çözücüde girişlere 111 verilince (tümleyen çıkışlı olduğu için) 7 numaralı çıkış 0 olur. F8H'de A5-A4-A3 = 111 olduğu için Y7 $\overline{CS}$'ye bağlanır.
- $M/\overline{IO}$ etkin düşük girişe bağlanır, çünkü bu bir G/Ç birimidir ve uç 0 gelir.
- A0 etkin düşük girişe bağlanır, çünkü çift adreslerde son bit hep 0'dır (bir sayının çift ya da tek olduğu ikilikte son bitinden anlaşılır).
- A7 ve A6'nın ikisi de 1 olmalıdır; bir VE kapısıyla birleştirilip etkin yüksek girişe bağlanır.
- Bu birleşim dışında kod çözücü çalışmaz; böylece port A, port B, port C ve kontrol yazmacı yalnız çift adreslere yerleşir. Bu tasarımda veri yalnız 8 bitlik düşük bayt üzerinden gönderilir.

> **Hocanın vurgusu:** Adres çözümleme devresi farklı tasarlanabilir. Kod çözücüye A3, A4, A5 yerine A5, A6, A7 bağlamak da olur; önemli olan $\overline{CS}$'nin yalnız tablodaki adreslerde etkin olmasıdır.

> **Ders sonrası not:** Hoca konuşurken bir yerde "8255'in A1 ve A0'ına CPU'nun A1 ve A2'si bağlandı", tahtada da dördüncü adresi "FD" diye yazdı. Doğrusu: CPU A2 → 8255 A1, CPU A1 → 8255 A0 ve dördüncü çift adres FEH'dir (FDH tektir). Hoca ayrıca A1A0 değerlerini bir kez "00, 01, 01, 01" diye okudu; doğru sıra 00, 01, 10, 11'dir.

### 8.2 Yalnız tek adresler (F9H başlangıç)

Aynı entegre tek adreslere yerleştirilmek istenirse A0 = 1 olmalıdır: F9H, FBH, FDH, FFH. Port seçimi yine CPU'nun A2 ve A1 uçlarından alınır; tasarım değişmez. Farklar:

- A0 bir DEĞİL kapısından geçirilerek kod çözücünün etkin düşük girişine bağlanır.
- Tek adreslerde veri yüksek baytta aktarıldığı için 8255'in veri yolu D8-D15'e bağlanır.

Yani iki ayrı 8255 olsaydı biri düşük bayta ve çift adreslere, diğeri yüksek bayta ve tek adreslere yerleştirilebilirdi; ikisinin farkı yalnız A0'daki DEĞİL kapısı ve bağlandıkları veri yolu yarısı olurdu.

### 8.3 Hem çift hem tek adresler (C0H başlangıç)

Tek bir 8255 ile 16 bitlik veri yolunun iki yarısı da kullanılabilir, çünkü işlemcide $\overline{BHE}$ ucu vardır. Ancak bu tek seferde değil, iki çevrimde olur: önce bir 8 bit, sonra öteki 8 bit gönderilir ya da okunur.

Örnek: 8255 C0H başlangıç adresine, çift ve tek adresler kullanılarak yerleştirilecek (ekrandan, 01:05:00).

| | A7 | A6 | A5 | A4 | A3 | A2 | A1 | A0 | |
|---|---|---|---|---|---|---|---|---|---|
| C0H | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | çift |
| C1H | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | tek |
| C2H | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 | çift |
| C3H | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | tek |

Bu kez değişen bitler A1 ve A0'dır (slaytta "A1-A0 Register Select"); CPU A2 ve A1'i 8255'e bağlamak artık port A, B, C ve kontrol yazmacını ayırt edemez. Bunun yerine CPU'nun A1 ve A0 uçları doğrudan 8255'in A1 ve A0'ına bağlanır: C0H port A, C1H port B, C2H port C, C3H kontrol (ekrandan, 01:10:00). $\overline{RD}$ ve $\overline{WR}$ de doğrudan bağlanır.

Yonga seçimi için anlatılan tasarım:

- Kod çözücü girişlerine A4, A3, A2 bağlanır; bunlar 000 olduğu için Y0 çıkışı kullanılır. (Sağdaki üç sıfırı ya da başka bir üçlüyü seçmek de olurdu.)
- $M/\overline{IO}$ etkin düşük girişe, A5 de etkin düşük girişe bağlanır (A5 = 0).
- A7 ve A6 bir VE kapısıyla etkin yüksek girişe bağlanır.
- Y0, çip seçimi etkin olduğunda iki 74245 tamponunu birden etkinleştirecek bir ön devreye gider. 74245'lerin $\overline{OE}$ ucu etkin düşüktür.
- Y0 ile A0 bir VEYA kapısında birleşir: Y0=0 ve A0=0 iken çıkış 0 olur, düşük bayt tamponu etkinleşir ve CPU'nun D0-D7'si 8255'in D0-D7'sine bağlanır. A0=1 iken bu tampon çalışmaz.
- Y0 ile $\overline{BHE}$ ikinci bir VEYA kapısında birleşir: Y0=0 ve $\overline{BHE}$=0 iken yüksek bayt tamponu etkinleşir ve D8-D15 8255'in veri yoluna bağlanır.
- 74245'lerin DIR ucunun ayarına göre veri ya 8255'ten veri yoluna alınır ya da veri yolundan portlara yazılır.

Böylece 16 bitlik veri yolu, 8 bitlik tek bir 8255 ile iki çevrimde okunup yazılabilir.

<!-- BELİRSİZ: C0H örneğinin tampon ve VEYA kapılı devre karesi kayıtta yok (yalnız C0H-C3H eşleme karesi var); devre ayrıntıları anlatımdan kuruldu. -->

## 9. 8255 modları ve kontrol yazmacı

### 9.1 Modlar

Slayta göre 8255 dört farklı mod ile çalışabilir (ekrandan, 01:20:00):

- Mod 0: Basic I/O
- Bit Set Reset Mod
- Mod 1: Strobed I/O
- Mod 2: Bi-directional Bus

Mod 0 basit giriş-çıkış modudur ve üç port da bu modda çalışabilir. Mod 1 tek yönlü karşılıklı iletişime (el sıkışmaya), mod 2 iki yönlü karşılıklı iletişime dayanır; bunlar sonraki haftalarda işlenecek. Bu üç modun dışında, mod seçimine geçmeden kullanılan bit set/reset (BSR) modu vardır: seçili bir bitin 1 mi 0 mı olacağı doğrudan belirlenir.

### 9.2 Mod seçme kontrol sözcüğü

Önce 8255'in kontrol yazmacının adresi seçilir (A1A0 = 11). Artık o adrese gönderilen 8 bitlik sayı, entegreyi programlayan veridir. Bu verinin bir şablonu vardır (ekrandan, 01:25:00):

| Bit | Anlamı |
|---|---|
| D7 | Mode set flag (1 = aktif, mod seçme sözcüğü) |
| D6-D5 | Grup A mod seçimi: 00 = Mod 0, 01 = Mod 1, 1X = Mod 2 |
| D4 | Port A: 1 = giriş, 0 = çıkış |
| D3 | Port C (üst): 1 = giriş, 0 = çıkış |
| D2 | Grup B mod seçimi: 0 = Mod 0, 1 = Mod 1 |
| D1 | Port B: 1 = giriş, 0 = çıkış |
| D0 | Port C (alt): 1 = giriş, 0 = çıkış |

- En anlamlı bit D7, entegrenin mod seçme yapısına mı yoksa bit set/reset yapısına mı sokulacağını söyler.
- D6-D5, D4 ve D3 grup A'yı (port A ve port C'nin üst yarısı), D2, D1 ve D0 grup B'yi (port B ve port C'nin alt yarısı) ilgilendirir.
- Grup B'de mod 2 yoktur, çünkü mod 2 port A'yı tamamen kullanır ve ek sinyaller için başka uçlardan da yararlanır.

> **Hocanın vurgusu:** Bu şablonu ezberlemeye kesinlikle gerek yoktur. Lab'da ve sınavda bu arayüz tabloları elde bulunacak; önemli olan pinlerin neye karşılık geldiğini tablodan okuyup yorumlamaktır.

### 9.3 Örnek: 93H kontrol sözcüğü

C0H örneğindeki adreslerle (C0H port A, C1H port B, C2H port C, C3H kontrol), önce kontrol yazmacının adresi C3H `DX`'e yüklenir ve bu adrese `OUT` yapılır. C3H'nin son iki biti (A1A0) 11 olduğu için 8255 kontrol sözcüğü kabul etme durumuna geçer. Ardından 93H gönderilir (ekrandan, 01:30:00).

```text
mov dx, 0C3h     ; kontrol yazmacı adresi (A1A0 = 11)
mov al, 93h      ; kontrol sözcüğü
out dx, al
```

(ara adım eklendi: tahtada yalnız "Dx, C3" ve "Out, Dx" yazıyor; `AL` üzerinden gönderim büyük olasılıkla kastedilmiştir.)

93H = 1001 0011b çözümlemesi:

| Bit | Değer | Anlamı |
|---|---|---|
| D7 | 1 | Mod seçme sözcüğü |
| D6-D5 | 00 | Grup A mod 0 |
| D4 | 1 | Port A giriş |
| D3 | 0 | Port C üst (PC7-PC4) çıkış |
| D2 | 0 | Grup B mod 0 |
| D1 | 1 | Port B giriş |
| D0 | 1 | Port C alt (PC3-PC0) giriş |

Bu ayarda port A'ya LED bağlamanın anlamı yoktur, çünkü port A veri girişi olarak tanımlanmıştır. Port C'nin 4-7 numaralı uçlarına LED bağlanabilir. Port B'ye ve port C'nin 0-3 numaralı uçlarına düğmeler bağlanıp okunabilir.

> **Hocanın vurgusu:** Bu ayar yapılmadan port A, port B ve port C'nin iki yarısının ne olacağı belirlenemez. 8255'i kullanmadan önce kontrol yazmacına bir kontrol sözcüğü yazmak zorunludur.

### 9.4 Bit set/reset kontrol sözcüğü

İkinci tür kontrol sözcüğünde en anlamlı bit D7 = 0'dır. Bu durumda mod seçimi ya da port işlemi yapılmaz; yalnız hangi bitin 1 ya da 0 olacağı belirlenir. Bazı bitlerin değeri önemsizdir. Üç bit, ikilik karşılığıyla hangi bitin seçileceğini gösterir (örneğin 101 = 5), bir bit de o bitin 1 mi 0 mı yapılacağını belirler.

> **Ek bilgi (derste anlatılmadı):** Standart 8255'te BSR sözcüğünde D6-D4 önemsizdir, D3-D1 bit numarasını seçer, D0 = 1 o biti set eder, D0 = 0 reset eder. BSR yalnız port C'nin bitleri için geçerlidir. Hocanın "101 dersem 5. port" dediği, büyük olasılıkla port C'nin 5 numaralı ucudur (PC5).

<!-- BELİRSİZ: BSR kontrol sözcüğünün slaytı karelerde yok; bit konumları altyazıdan net çıkmıyor. -->

### 9.5 Mod 0

Mod 0 basit giriş-çıkış işlemleri için kullanılır:

- Herhangi bir kontrol ya da el sıkışma (handshake) yoktur. Örneğin "düğmeye basılınca, düğme bırakılana kadar yeni bilgi kabul etme" gibi bir mekanizma yoktur.
- Verinin gelip gelmediğini kontrol eden bir yapı, onay sinyali ya da kesme üretimi yoktur; yalnız portlardan veri okunur ve portlara veri yazılır.
- İki adet 8 bitlik (port A ve port B) ve iki adet 4 bitlik (port C'nin üst ve alt yarısı) port vardır.
- Kontrol sözcüğüne göre herhangi bir port giriş ya da çıkış olarak tanımlanabilir. Ancak bir portun tek tek bitleri farklı yönde ayarlanamaz; "port A'nın 3. biti giriş, 5. biti çıkış olsun" denemez.
- Modlarla birlikte mod 0'da toplam 16 farklı yön birleşimi oluşur.

> **Ek bilgi (derste anlatılmadı):** 16 sayısı, mod 0'da yönü ayrı ayrı seçilebilen dört birimden (port A, port B, PCH, PCL) gelir: her biri giriş ya da çıkış olabildiği için $2^4 = 16$ birleşim vardır.

## Örnek Sorular

### Soru 1: Hangi düğme arayüzü doğru?

(ekrandan, 00:20:00; derste sözlü, 00:17:53)

Slaytta altı düğme devresi var (Bölüm 3.3'teki tablo). Düğmeye basıldığında 8086'ya 0, basılmadığında 1 gidecek şekilde çalışan ve 8086 için uygun olan devre hangisidir?

**Çözüm (derste verildi):** Sağ alttaki devre: düğmenin bir ucu toprakta, diğer ucu 8086'ya giden düğümde; düğüm 10 kΩ'luk direnç üzerinden +5 V'a bağlı. Basılmayınca uç 1, basınca 0 olur. Orta alttaki devre de mantık olarak çalışır, ama 5 V'u 8086 ucuna doğrudan bağladığı için uygun değildir. Diğer devreler ya basışta 1 verir ya da basışta değer değişmez.

### Soru 2: Düğme bekleme döngüsü ne iş yapar?

(ekrandan, 00:35:00; derste sözlü, 00:36:14)

```text
     mov dx, 0F000h
L1:  in  al, dx
     cmp al, 0FFh
     je  L1
```

**Çözüm (derste verildi):** Düğme hatları 5 V'a çekildiği için hiçbir düğmeye basılmamışken okunan değer 0FFH'dir ve döngü `L1`'e döner. Bir düğmeye basılınca o bit 0 olur (örneğin 5. bit için DFH), değer 0FFH'den farklı olur ve döngüden çıkılır. Kod, herhangi bir düğmeye basılana kadar düğmeleri sürekli okur.

### Soru 3: Aynı adreste giriş ve çıkış birimi

(ekrandan, 00:40:00)

0F000H adresine hem 8 düğme (giriş) hem 8 LED (çıkış) yerleştirildi (ya da 4 düğme ve 4 LED). Bu durum problem oluşturur mu?

> **Çözüm (derste verilmedi):** Problem oluşturmaz. Çıkış biriminin adres kod çözme kapısında $\overline{WR}$, giriş biriminin kapısında $\overline{RD}$ vardır. `OUT` komutunda yalnız $\overline{WR}$=0 olur ve yalnız LED tamponu etkinleşir; `IN` komutunda yalnız $\overline{RD}$=0 olur ve yalnız düğme tamponu etkinleşir. Bir yolda aynı anda iki birim sürücü olmadığı için çakışma olmaz; aynı adres, okuma için giriş birimini, yazma için çıkış birimini gösterir.

### Soru 4: Basit birimi 0F001H adresine yerleştirmek

(ekrandan, 00:40:00)

Basit giriş/çıkış birimi 0F001H adresine yerleştirmek için ne yapılmalıdır?

> **Çözüm (derste verilmedi):** 0F001H = 1111 0000 0000 0001b. Kod çözme kapısında A0 girişi tümleyen girişten doğrudan girişe alınmalıdır (A0 = 1 iken etkin olacak şekilde); diğer girişler aynı kalır. Ayrıca 8086'da tek adresli bayt aktarımları veri yolunun yüksek yarısında (D8-D15) yapılır. Bu yüzden 74245'in A tarafı D0-D7 yerine D8-D15'e bağlanmalıdır. Program yalnız adres değişikliğiyle (`mov dx, 0F001h`) aynı kalır.

### Soru 5: 0F000H'den itibaren 16 bitlik basit çıkış birimi

(ekrandan, 00:40:00)

0F000H adresinden itibaren 16 bitlik bir basit çıkış birimi nasıl tasarlanmalıdır?

> **Çözüm (derste verilmedi):** 16 LED iki 8 bitlik gruba bölünür. Birinci grup bir 74245 ile D0-D7'ye bağlanır ve 0F000H'de (A0 = 0) etkinleşir; ikinci grup ikinci bir 74245 ile D8-D15'e bağlanır ve 0F001H'de ($\overline{BHE}$ = 0) etkinleşir. Her iki kapıda da A15-A1 = 1111 0000 0000 000b, $M/\overline{IO}$ = 0 ve $\overline{WR}$ = 0 koşulu bulunur; ek olarak birinci kapıya A0, ikinci kapıya $\overline{BHE}$ girer. 16 bitlik veri tek komutla yazılır: `mov dx, 0F000h` / `mov ax, <desen>` / `out dx, ax`. Bu çift adreste hizalı bir aktarım olduğu için A0 = 0 ve $\overline{BHE}$ = 0 birlikte oluşur ve iki tampon aynı anda etkinleşir.

### Soru 6: 8255'i F8H'den itibaren yalnız çift adreslere yerleştirmek

(ekrandan, 00:55:00 ve 01:00:00)

We want to use a 8255 PPI with the starting I/O address of F8h. Use even addresses only.

**Çözüm (derste verildi):** Adresler F8H, FAH, FCH, FEH (port A, port B, port C, kontrol). Değişen bitler A2-A1 olduğundan CPU A2 → 8255 A1, CPU A1 → 8255 A0. 3'e 8 kod çözücüye A5-A4-A3 (= 111) girer, Y7 → $\overline{CS}$. Etkinleştirme girişleri: $M/\overline{IO}$ ve A0 etkin düşük, A7·A6 etkin yüksek. Veri yolu D0-D7.

### Soru 7: 8255'i yalnız tek adreslere yerleştirmek

(derste sözlü, 01:01:55)

Aynı 8255 16 bitlik veri yolunda 8 bitlik tek adreslere nasıl yerleştirilir?

**Çözüm (derste verildi):** Adresler F9H, FBH, FDH, FFH. Port seçimi yine CPU A2-A1'den alınır. A0 bir DEĞİL kapısından geçirilerek kod çözücünün etkin düşük girişine bağlanır ve 8255'in veri yolu yüksek bayta (D8-D15) bağlanır.

### Soru 8: 8255'i C0H'den itibaren çift ve tek adreslere yerleştirmek

(ekrandan, 01:05:00)

We want to use a 8255 PPI with the starting I/O address of C0h. Use even and odd addresses.

**Çözüm (derste verildi):** C0H port A, C1H port B, C2H port C, C3H kontrol; CPU A1-A0 → 8255 A1-A0. Kod çözücü A4-A3-A2 = 000 ile Y0'ı verir; $M/\overline{IO}$ ve A5 etkin düşük, A7·A6 etkin yüksek girişlere bağlanır. Y0, A0 ile VEYA'lanarak düşük bayt 74245'ini, $\overline{BHE}$ ile VEYA'lanarak yüksek bayt 74245'ini etkinleştirir. Aktarım iki çevrimde yapılır.

### Soru 9: 93H kontrol sözcüğü ne anlama gelir?

(ekrandan, 01:30:00; derste sözlü, 01:27:39)

8255'in kontrol yazmacına (C3H) 93H yazılırsa portlar nasıl ayarlanmış olur?

**Çözüm (derste verildi):** 93H = 1001 0011b. D7 = 1 mod seçme; grup A mod 0, port A giriş, port C üst çıkış; grup B mod 0, port B giriş, port C alt giriş.

## Dersin Toparlaması

Bu derste mikroişlemcinin çevre birimleriyle nasıl iletişim kurduğu ele alındı. Çevre birimleri bellek gibi bir adres uzayına yerleştirilir; 8086'da isolated yöntemde $M/\overline{IO}$ ucu bellek ve G/Ç uzaylarını ayırır, `IN`/`OUT` komutları G/Ç uzayına erişir. Düğme arayüzünde pull-up dirençli, basınca 0 veren yapı ve sıçrama sorunu; LED arayüzünde ise ucun LED'i doğrudan değil, bir transistör üzerinden sürmesi gerektiği görüldü. 0F000H adresine yerleştirilen LED ve düğme örnekleriyle adres çözümlemenin 74245'in etkinleştirme ucunu yalnız istenen adres, $M/\overline{IO}$ ve $\overline{RD}$/$\overline{WR}$ birleşiminde etkinleştirmek olduğu gösterildi. Çevre birimlerinin yoklama ve kesmeyle kontrol edilebileceğinden söz edildi.

İkinci bölümde 8255 PPI'nin uçları, iç yapısı ve 16 bitlik veri yolunda 8 bitlik bir birim olarak çift, tek ya da her iki tür adrese yerleştirilmesi işlendi. Son olarak mod seçme kontrol sözcüğü ve bit set/reset sözcüğü tanıtıldı, mod 0'ın el sıkışmasız temel G/Ç modu olduğu anlatıldı. Mod 0 örnekleri (LED ve düğme, 7 parçalı gösterge, tuş tarama) ile mod 1 ve mod 2 sonraki derslerde işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
