# Ders 19 Genişletilmiş Notu: Seri Haberleşme ve 8251 USART

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin planı
- 2. Paralel ve seri veri iletimi
- 3. Senkron ve asenkron seri iletişim
- 4. Asenkron çerçeve, baud rate ve parite
- 5. Simpleks, yarı dupleks ve tam dupleks
- 6. Baud rate ile data rate farkı
- 7. Hata tespiti: parite, checksum, CRC
- 8. Yazılımsal seri gönderme
- 9. 8251 USART: uçlar ve adres uzayı
- 10. G/Ç veri aktarım yöntemleri: polling, kesme, DMA
- 11. 8251 yazmaçlarına erişim ve ilk ayarlama akışı
- 12. Mod, kontrol ve durum yazmaçları
- 13. Proteus örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin planı

Bu haftanın konusu 8251 entegresi ve onun temeli olan seri haberleşmedir. Seri haberleşmeyi anlatmak için önce paralel veri aktarımı ele alınır, sonra seri haberleşmenin senkron ve asenkron türleri ve farklı tanımları verilir. Asıl amaç programlanabilir bir seri haberleşme entegresi kullanmaktır; ama önce aynı işin yazılımla (bir port ucunu bit bit sürerek) nasıl yapılacağı bir örnekle incelenir. Ardından 8251'in iç yapısı, uç tanımları ve programlanması, son olarak da Proteus örnekleri gelir.

## 2. Paralel ve seri veri iletimi

Slaytta veri iletimi bir ağaç olarak verilir: Data Transmission altında Parallel ve Serial, Serial altında da Synchronous ve Asynchronous (ekrandan, 00:15:00). Aynı slayttaki özet şudur:

- Seri: daha az maliyet, daha yavaş.
- Paralel: daha hızlı, kısa mesafeler için.

Paralel haberleşmede bir uç terminalden diğerine veri bir paket halinde, yani birden fazla bit aynı anda gönderilir. İletim ortamı tel ise birden fazla telin iki terminal arasında bağlı olması, elektromanyetik dalga ise birden fazla kanalın aynı anda kullanılması gerekir. 8 bitlik ya da 16 bitlik bir haberleşme o kadar tel ister ve bir seferde 8 ya da 16 bit aktarılır. Eski IDE kabloları (sabit diskten anakarta paralel veri taşıyan kablolar) ve anakart üzerindeki yollar örnek olarak verildi.

Seri haberleşmede veri bir seferde aktarılamaz, bit bit gönderilir. Gönderen terminal veriyi bir yazmaçta, yani paralel olarak tutar; bu yüzden veriyi önce serileştirmesi, bitlerine ayırıp sırayla göndermesi gerekir. Alıcı terminal bit bit gelen veriyi biriktirip yeniden birleştirir. Gönderici, paket halindeki veriyi en düşük anlamlı bitinden başlayarak hatta koyar.

Hız açısından paralel iletim bir birim zamanda bir baytı gönderirken seri iletim aynı baytı kabaca 8 birim zamanda gönderir. Buna rağmen seri iletimin tercih edilmesinin nedeni maliyettir. Paralel iletimde bit sayısı kadar tel gerekir; uzun mesafede maliyet çok yükselir, veri kaybı riski artar ve kaybı tespit etmek zorlaşır. Seri iletimde terminaller birbirinden uzak olabilir ve veri kaybını tespit eden sistemler kullanılabilir. Temelde gönderme ve alma için iki tel yeterlidir; bunlara ortak toprak ve senkron haberleşmede ortak saat gibi yardımcı bağlantılar eklenir. Az tel, düşük maliyet demektir; bedeli ise yavaşlıktır.

## 3. Senkron ve asenkron seri iletişim

Slayttaki karşılaştırma şöyledir (ekrandan, 00:20:00):

- **Synchronous (Senkron):** Sender and receiver must synchronize (done in hardware using phase locked loops, PLLs). Block of data can be sent. More efficient: less overhead than asynchronous transmission. Expensive.
- **Asynchronous (Asenkron):** Each byte is encoded for transmission (start and stop bits). No need for sender and receiver synchronization.

Senkron iletişimde iki terminal ortak bir saat kullanır. Bunun tersinde her terminal kendi saatini kullanır. Bu durumda terminallerin saatleri arasında küçük frekans farkları ya da başlangıç anları arasında faz farkı olabilir. Bu kayma yüzünden iki terminal aynı anda aynı tepkiyi veremeyebilir; örneğin gönderici yeni bir biti hatta koyarken alıcı hâlâ önceki biti örnekliyor olabilir.

Bundan iki sonuç çıkar:

- Ortak saat varsa zaman kayması nedeniyle veri kaybı ihtimali çok düşüktür. Bu yüzden senkron haberleşmede büyük veri parçaları (chunk) gönderilip alınabilir.
- Asenkron haberleşmede belirli bir veri boyutunu aştıktan sonra kayma riski çok yükselir, bazı bitler doğru örneklenemeyebilir. Bu yüzden veri küçük parçalar, ayrı paketler halinde gönderilmelidir.

İkinci bir sonuç da başlangıç ve bitiş işaretleriyle ilgilidir. Senkron haberleşmede büyük bir blok gönderildiği için bloğun başı ve sonu tek bir bitle değil, birer bit dizisiyle işaretlenir; hoca bunları "daha geniş parantezler" diye niteledi. Asenkron haberleşmede veri zaten küçüktür; buna büyük parantezler eklemek ek yükü (overhead) çok artırır. Bu yüzden asenkron haberleşmede başlangıç bir bitle, bitiş bir ya da iki bitle işaretlenir. Asenkron çerçevede yaklaşık 8 bitlik verinin başında ve sonunda bu başlama ve bitiş işaretleri bulunur.

Bağlantı açısından asenkron haberleşmede veri alma ve veri gönderme için birer tel ve iki sistemin ortak toprağı (ortak gerilim referansı) vardır, yani 3 tel gerekir. Senkron haberleşmede bunlara ortak saat işareti eklenir ve 4 tel olur.

> **Hocanın vurgusu:** Derste senkron ve asenkron haberleşmeden yalnız asenkron haberleşme kullanılacaktır. Senkron paket yapıları kapsam dışıdır.

## 4. Asenkron çerçeve, baud rate ve parite

### 4.1 Hattın kontrolü ve önceden anlaşma

Bir terminal veri gönderiyorsa hattın kontrolü ondadır: hattaki gerilim seviyesini gönderici (transmitter) belirler, alıcı (receiver) yalnız örnekleme yapar. Gönderici bir biti hatta koyduktan sonra bu bitin belirli bir süre hatta kalması gerekir ki karşı taraf onu örnekleyebilsin.

İki terminal asenkron haberleşmede baştan şu konularda anlaşmış olmalıdır:

- Kaç start biti kullanılacağı.
- Kaç stop biti kullanılacağı.
- Parite biti kullanılıp kullanılmayacağı; kullanılacaksa çift mi tek mi olacağı.
- Verinin kaç bitten oluştuğu.
- Her bitin hatta ne kadar süre kalacağı (baud rate).

Örneğin "bir start biti, even parite ve iki stop bitiyle veri göndereceğim" bilgisini iki taraf da baştan bilir.

**Soru:** Terminallerin parite kullanıp kullanmayacağı gibi ayarlarda anlaşması da bir veri iletişimi değil midir? **Cevap:** Hayır. Örneğin seri veri gönderen bir sensör alındığında veri sayfasında "9600 baud, 8 veri biti, bir start biti, iki stop biti, even parite ile çalışır" yazar. Anlaşmaktan kastedilen budur; ayrıca bir veri alışverişi yoktur.

### 4.2 Baud rate ve bit süresi

Bir bitin hatta ne kadar kalacağını baud rate belirler. Baud rate bir frekans gibi düşünülebilir: saniyede kaç bit gönderilebileceğini verir. Bit süresi frekansın tersidir:

$$T_{bit} = \frac{1}{\text{baud rate}}, \qquad \frac{1}{9600}\ \text{s} \approx 104\ \mu s$$

Yani hem donanımda hem yazılımda 9600 baud ile haberleşmede anlaşılmışsa her bit hatta yaklaşık 104 µs kalmalıdır.

### 4.3 Çerçevenin adımları

Slayttaki çerçeve şöyledir (ekrandan, 00:25:00): "Veri bitler halinde gönderilir. Alıcı taraf iletişimin başladığını/bittiğini başta ve sonda bulunan START ve STOP bitleri ile anlar. Hat boşta iken lojik 1 değerindedir." Altındaki dalga biçiminde hat önce 1'de (boş), sonra start biti (0), ardından veri bitleri `1 1 0 1 1 1 1 0` ve en sonda iki stop biti (1) görülür.

- **Boş hat:** Gönderici veri yokken hattı lojik 1'de tutar.
- **Start biti:** Gönderici iletişimi başlatmak için hattı bir bit süresi (9600 baud için yaklaşık 104 µs) boyunca 0'a çeker.
- **Alıcının örneklemesi:** Belirli bir frekansla değişen bir işaret doğru örneklenmek isteniyorsa en az iki katı frekansla örneklenmelidir. Alıcı da benzer biçimde 104 µs'lik bitin yaklaşık 50. mikrosaniyesinde (ortasında) ve yaklaşık 100. mikrosaniyesinde iki kez örnek alır. İki değer eşitse biti doğru okuduğunu kabul eder. Start biti böyle doğrulandıktan sonra gelen bitleri D0'dan başlayan veri olarak değerlendirir.
- **Veri bitleri:** En düşük anlamlı bitten başlayarak gönderilir; her biri hatta 104 µs kalır.
- **Parite biti:** İki taraf parite kullanmakta anlaştıysa veriden sonra gönderilir.
- **Stop biti:** Hat 1, 1,5 ya da 2 bit süresi boyunca 1'de tutulur. 1,5 bit, hattın $1{,}5 \times 104 \approx 156\ \mu s$ boyunca 1'de kalması demektir; 2 stop biti yaklaşık 208 µs'dir.
- **Yeniden boş hat:** Stop bitlerinden sonra hat yine 1'dedir ve bir sonraki aktarımı bekler.

**Soru:** Start bitini doğrulamak için iki noktada örnek alınıyor. Ya hattaki 0 aslında start biti değilse ve yalnızca denk gelmişse? **Cevap:** Bu durum seri haberleşmedeki hata türlerinden biridir: çerçevenin kayması, yani çerçeve hatası (frame error). Bu çerçevede gelen veri çöpe atılır, hat boşa çıkana kadar gelenler değerlendirilmez. Verinin doğru aktarılması için start bitinin gerçekten bir bit süresi boyunca (9600 baud için 104 µs) 0'da kalması gerekir ki alıcı onu ortada ve sonda aynı değerde örnekleyebilsin.

### 4.4 Parite hesabı

- **Even (çift) parite:** Parite biti dahil 1'lerin sayısı çift olur.
- **Odd (tek) parite:** Parite biti dahil 1'lerin sayısı tek olur.

Hoca slayttaki veri için pariteyi tahtada hesapladı (ekrandan, 00:35:00):

- Verilen: veri bitleri `1 1 0 1 1 1 1 0`.
- İşlem: 1'ler sayılır: 1, 2, 3, 4, 5, 6. Altı tane 1 vardır (python ile doğrulandı).
- Çift parite: sayı zaten çift, parite biti 1'lerin çiftliğini korumalı, P = 0.
- Tek parite: sayı çift, parite biti ile toplamın tek olması için P = 1.

Hoca aynı karede stop biti seçeneklerini 1, 1,5 ve 2 olarak not etti; stop bitlerinin sonunda ve start bitinden önce hattın "boş" olduğunu işaretledi.

## 5. Simpleks, yarı dupleks ve tam dupleks

Verinin alınıp gönderilmesinin eş zamanlı olup olmamasına göre üç yapı vardır (ekrandan, 00:40:00):

- **Simpleks:** Kanalı yalnız bir terminal sürer; haberleşme tek yönlüdür (Transmitter → Receiver).
- **Yarı dupleks (half duplex):** İki terminalin de alma ve gönderme yeteneği vardır ama tek bir kanal vardır; belirli bir anda ya A'dan B'ye ya B'den A'ya aktarım olur, ikisi aynı anda olamaz.
- **Tam dupleks (full duplex):** A'dan B'ye ve B'den A'ya iki ayrı kanal vardır, ikisi aynı anda kullanılabilir.

Hoca her yapı için öğrencilere örnek sordu:

- Simpleks için bir öğrenci yazıcıyı önerdi; hoca yazıcının da geri bilgi (yazdırdım/yazdıramadım) gönderdiğini hatırlatıp daha basit bir örnek istedi. Aranan cevap karasal radyo ve TV yayınıdır: yayın yapılır, alıcılar alır, ters yönde veri gönderilmez ve bu desteklenmez.
- Yarı dupleks için cevap telsizdir: tuşa basan kanalı kullanma hakkını alır, o konuşurken karşı taraf hattı kullanamaz, bıraktıktan sonra karşı taraf kullanabilir.
- Tam dupleks için örnek cep telefonudur: konuşurken bir yandan karşı tarafın sesi gelir, bir yandan bizim sesimiz gider; bu farklı frekanslarda eş zamanlı yapılır.

## 6. Baud rate ile data rate farkı

Data rate, saniyede gerçekten veriyle ilgili olan kaç bit gönderilebileceğinin en büyük değeridir. Baud rate ise start, stop ve parite gibi kontrol bitleri dahil, hatta saniyede kaç değişim yapılabildiğini verir. Veri, etrafındaki start, stop ve parite bitleri yüzünden baud rate'ten daha düşük bir hızla taşınır.

Örnek: 1200 baud, kontrol bitleri dahil saniyede 1200 bit gönderebilen bir kanal demektir. Bir bit hatta $1/1200\ \text{s} \approx 0{,}83\ \text{ms}$ kalmak zorundadır (python ile doğrulandı).

Slaytlarda verilen bir baud rate ve haberleşme yapısıyla belirli miktarda verinin ne kadar sürede aktarılacağını soran örnekler vardı; hoca bunların üzerinde durmadı, öğrencilerin kendilerinin bakmasını istedi. <!-- BELİRSİZ: bu örnek soruların metni karelerde yok. -->

## 7. Hata tespiti: parite, checksum, CRC

Seri veri uzak mesafelere gönderildiği için hatta elektromanyetik girişim riski yüksektir. Örneğin veri hattının yakınında bir motor çalışırsa oluşturduğu elektromanyetik alan anlık olarak hattaki gerilimi değiştirip karşı tarafa yanlış bir bit gitmesine yol açabilir. Ayrıca start ya da stop bitlerinde kayma olursa çerçeve hatası oluşur.

Hatayı tespit eden yöntemlerle hatayı düzelten yöntemler ayrı değerlendirilmelidir. Bazı yöntemler yalnız hatanın olup olmadığını gösterir; bazıları uygun kodlamalarla hatanın hangi bitte olduğunu da belirleyebilir.

Slayttaki özet (ekrandan, 00:45:00):

- **Parity Check:** Even parity: when odd numbers of 1 make D7 = 1 (send even number of 1). Odd parity: when even number of 1 make D7 = 1 (send odd number of 1).
- **Check Sum:** Used for block of data. Sum of all bytes without carry and 2's complements. Total sum result should be zero.
- **Cyclic Redundancy Code (CRC):** Synchronous communication. Stream of data can be represented by cyclic polynomial that divided by a constant polynomial. Remainder to set bits and send out as check for error.

Parite kontrolünün işleyişi şöyledir. Gönderici veriye ait pariteyi hesaplar, veriyi en düşük anlamlı bitten başlayarak gönderir, veri bitince hesapladığı parite bitini gönderir. Alıcı veriyi bildiği baud rate ile örnekleyip bir bayt oluşturur ve ardından gelen pariteyi not eder. Sonra aldığı veriden kendisi parite hesaplar ve gelen pariteyle karşılaştırır. Fark yoksa veri parite açısından doğru kabul edilir; fark varsa veride bozulma olmuştur ve veri değerlendirme dışı bırakılır. Parite tek sayıda bit hatasını yakalar ama çift sayıda bit değişirse parite aynı kalacağı için hatayı fark etmeyebilir.

Checksum'da gönderilecek veri blokları üzerinde toplama yapılır ve toplam karşı tarafa aktarılır. Hoca parite ve checksum'ın hata tespit yöntemleri olduğunu, hatanın yerini bulamayabildiklerini söyledi; CRC'yi ise hem hatanın varlığını hem yerini tespit etmeye yönelik bir yöntem olarak andı ve ayrıntısını öğrencilere bıraktı.

> **Ders sonrası not:** Hoca CRC için "hatanın nerede olduğunu da tespit eder" dedi. CRC büyük olasılıkla burada yalnız hata tespiti için kullanılır: alıcı aynı bölmeyi yapıp kalanı karşılaştırır, kalan farklıysa hata vardır ama hangi bitin bozulduğu genelde bulunmaz. Hatanın yerini bulup düzelten kodlar (örneğin Hamming kodu) ayrı bir sınıftır.

## 8. Yazılımsal seri gönderme

### 8.1 Senaryo ve sorun

Elimizde bir 8255 olduğunu ve herhangi bir portunun en düşük anlamlı bitinin seri veri çıkışı olarak kullanıldığını düşünelim. 8 veri biti, 1 start biti ve 1 ya da 2 stop biti gönderilecekse (paritesiz) toplam 10 ya da 11 bit gönderilmelidir. 8255 8 bitlik bir çevre birimi olduğu için ona 8 bitlik bir yazmaçla veri yazılır; ama 8 bitten fazla bilgiyi tutacak bir yapıya ihtiyaç vardır.

Hoca öğrencilere "elimizdeki yazmaç ve bayrakları kullanarak sanal bir 9 bitlik yazmaç nasıl oluşturabiliriz?" diye sordu. Cevap gelmeyince ipucu verdi: 8086'nın öteleme ve döndürme komutları içinde elde bayrağıyla birlikte döndürenler vardır (rotate with carry, left ya da right). Bu komutlar yazmacı CF ile sanal olarak birleştirip 9 bitlik bir yazmaç gibi döndürür. Aranan sanal yazmaç budur.

### 8.2 Bitlerin sırayla D0'a getirilmesi

- **Start biti:** CF sıfırlanır, sonra `RCL AL,1` yapılır. CF'deki 0 AL'nin 0. bitine gelir, AL'nin 7. biti CF'ye geçer. AL porta `OUT` ile yazılınca 0 değeri ilgili pinden çıkar; bir bit süresi beklenirse start biti gönderilmiş olur.
- **İlk veri biti:** `RCR AL,1` yapılınca CF'deki A7 yerine döner, 0. bitteki 0 CF'ye geçer, 0. bitte orijinal A0 olur. AL porta yazılıp beklenince A0 gönderilir.
- **Stop biti:** Bu noktada CF = 1 yapılırsa sonraki her sağa döndürmede AL soldan 1 ile beslenir. A1'den A7'ye kadar gönderildikten sonra 0. konuma bir 1 gelir; bu 1 stop bitidir. İki stop biti gerekiyorsa bir kez daha döndürülüp ikinci 1 de gönderilir.

### 8.3 Akış ve kod

Slayttaki akış şemasının adımları (ekrandan, 00:50:00):

```text
Start
  -> Set up character bit counter; Send start bit
  -> Wait bit time
  -> Get char in ACC
  -> [döngü] Output bit using D0
            -> Wait bit time
            -> Rotate next bit in D0; Decrement the bit counter
            -> Is last bit?  hayır: döngü başına
  -> Add parity if necessary; Send two stop bit
  -> Return
```

Slayttaki kod (ekrandan, 00:55:00):

```asm
;Function:  Serial data transmitter. DELAY
;           procedure determines data rate.
;Inputs:    Character to be transmitted assumed
;           passed in AL.
;Ouputs:    Serial data on bit 0 of DPORT.

;Destroys:  AL,CX,flags.

        EXTRN   DELAY:NEAR
        DPORT   EQU 00H

CODE    SEGMENT
        ASSUME  CS:CODE

FIG10_3 PROC    NEAR
        MOV     CX,10       ;10 bits/char
        CLC                 ;Start bit
        RCL     AL,1        ;Move to position 0
TRANS:  OUT     DPORT,AL    ;Transmit bit
        CALL    DELAY       ;Wait
        RCR     AL,1        ;Next bit
        STC                 ;Stop bit
        LOOP    TRANS       ;Do 10 times
        RET
FIG10_3 ENDP
CODE    ENDS
        END
```

Aynı slaytta yanında bir D flip-flop'lu çıkış devresi (D0 → D girişi, $\overline{OUT0}$ saat, Q → Serial out) ve D0'a bağlı üç durumlu bir giriş tamponu ($\overline{IN0}$ ile etkin, Serial in) çizilidir.

Kodun adım adım işleyişi:

- `CX = 10`: 1 start + 8 veri + 1 stop = 10 bit. İki stop biti için 11 yazmak yeterlidir.
- `CLC`, `RCL AL,1`: start biti olan 0 AL'nin 0. bitine gelir, A7 CF'de bekler.
- İlk tur: `OUT` start bitini çıkarır, `DELAY` bir bit süresi bekler, `RCR AL,1` ile A7 yerine döner, A0 0. bite gelir ve 0 CF'ye geçer; `STC` ile CF = 1 olur.
- Sonraki turlar: A0'dan A7'ye kadar her bit gönderilir; her `RCR` AL'yi soldan 1 ile besler.
- Son tur: CX'te hâlâ 1 vardır; 0. bitte 1 bulunur ve stop biti olarak gönderilir. Döngü biter, `RET` ile dönülür.

DELAY, çağrılmasından dönüşüne kadar 9600 baud için tam 104 µs harcayan, hassas hesaplanmış bir yordam olarak varsayılır. Tam 104 µs olmaması büyük sorun değildir: örneğin 4 µs'lik bir sapma 10 bitte toplam 40 µs kayma yapar; hoca bunun biraz büyük olduğunu, 1-2 µs'lik sapmaların ise etkisiz sayılabileceğini söyledi.

41H ('A') için rutinin D0'a çıkardığı bit dizisi python ile benzetildi: `0` (start), `1 0 0 0 0 0 1 0` (A0'dan A7'ye), `1` (stop).

### 8.4 Yazılımsal alma

Alma işlemi de benzer bir akışla yazılımla yapılabilir: gelen bit CF'ye alınıp start biti olup olmadığı kontrol edilir, sonraki bitler bir yazmaçta döndürülerek biriktirilir, 8 bit biriktikten sonra gelen bit yine CF'ye alınıp stop biti olup olmadığına bakılır. Hoca bu rutinin kodunu vermedi ve zorunlu olmayan bir ev çalışması olarak bıraktı. Ajanın yazdığı bir taslak Örnek Sorular bölümündedir (Soru 7).

## 9. 8251 USART: uçlar ve adres uzayı

### 9.1 Tanım

Seri iletişim yazılımla da sağlanabilir ama dersin asıl yaklaşımı programlanabilir çevre birimleri kullanmaktır. 8255'ten sonra görülen ikinci çevre birimi 8251'dir. 8255 PPI (Programmable Peripheral Interface) diye adlandırılıyordu; 8251 ise USART'tır: universal Synchronous/Asynchronous Receiver/Transmitter (ekrandan, 01:10:00). Seri veriyi hem alma hem gönderme yönünde destekler ve hem senkron hem asenkron haberleşmeyi yapabilir.

### 9.2 Blok şema

Slayttaki 8251A blok şemasında (ekrandan, 01:15:00) solda adres, veri ve kontrol yolları, entegrenin içinde ise şu bloklar vardır: Mode register, Sync character 1, Sync character 2, Control register, Receiver shift reg., Data-in buffer reg., Data-out buffer reg., Transmitter shift reg., Status register. Uçlar:

| Uç | Görev |
|---|---|
| D7-D0 | Veri yolu (isteğe bağlı 8286 tamponu üzerinden) |
| C/$\overline{D}$ | Tek adres ucu (A0 ya da uygun adres hattına bağlanır) |
| $\overline{RD}$, $\overline{WR}$ | Okuma ve yazma işaretleri |
| $\overline{CS}$ | Entegre seçme, adres çözücü çıkışına bağlanır |
| RESET | Donanımsal reset |
| CLK | İç zamanlama saati |
| RxD | Seri veri girişi (Receiver shift reg.'e) |
| TxD | Seri veri çıkışı (Transmitter shift reg.'den) |
| TxE | Verici boş (Indicates trans. empty) |
| RxRDY, TxRDY | Alıcı hazır, verici hazır (kesme isteği girişlerine IRn, IR(n+1) bağlanır) |
| $\overline{RxC}$, $\overline{TxC}$ | Alma ve gönderme saatleri |
| $\overline{DSR}$, $\overline{DTR}$, $\overline{CTS}$, $\overline{RTS}$, SYNDET | Modem kontrol ve senkron algılama |
| $V_{CC}$ (+5 V), GND | Besleme |

### 9.3 8255 ile karşılaştırma: veri ve adres uçları

8255'in 8 veri ucu vardı. 8 bitlik bir çevre birimini 16 bitlik veri yoluna sahip 8086'ya bağlamanın en pratik yolu onu ardışık çift adreslere ya da ardışık tek adreslere yerleştirmektir. Ardışık adreslere yerleştirmek için çift ve tek adreslerde veriyi düşük ve yüksek anlamlı veri yoluna yönlendiren bir çoğullayıcı gibi ek donanım gerekir. Aynı durum 8251 için de geçerlidir: 8 veri ucu olduğu için ardışık çift ya da ardışık tek adreslere yerleştirilir.

8255'in iki adres ucu (A0, A1) vardı, adres uzayında $2^2 = 4$ bayt kaplıyordu ve dışarıdan erişilen 4 yazmacı vardı (port A, port B, port C, kontrol). Her adres bir yazmaçla ilişkiliydi. 8251'in ise tek adres ucu vardır: C/$\overline{D}$ (kontrol/data).

Hoca öğrencilere 8251'in G/Ç uzayında kaç bayt kapladığını sordu. Tek adres ucu 0 ya da 1 olabileceği için $2^1 = 2$ bayt kaplar. Ama dışarıdan erişilen yazmaçları sayılınca 7 tane çıkar: mod, senkron 1, senkron 2, kontrol, data-in, data-out ve durum. Tek adres ucuyla 7 yazmaca erişebilmek için bir kural tanımlanmıştır; bazı yazmaçlara aynı adres üzerinden bu kurala göre erişilir.

### 9.4 C/$\overline{D}$, $\overline{RD}$ ve $\overline{WR}$ ile erişim

C/$\overline{D}$ adındaki çizgi, ucun 1 iken üstteki (C, kontrol), 0 iken alttaki (D, data) işlevi yaptığını gösterir (hoca bunu slayttaki ucu büyütüp ok çizerek gösterdi, ekrandan, 01:20:00).

- Adres ucu 0, yazma: veri yolundaki değer data-out tamponuna yazılır.
- Adres ucu 0, okuma: data-in tamponu okunur.
- Adres ucu 1, okuma: durum (status) yazmacı okunur.
- Adres ucu 1, yazma: sırasıyla mod, senkron 1, senkron 2 ve kontrol yazmaçlarına erişilir (ayrıntısı bölüm 11'de).

### 9.5 Diğer uçlar

$\overline{CS}$ ucuna adres çözümleme devresinin çıkışı bağlanır. 8251'in G/Ç uzayında planlanan iki adresinden birine `IN`/`OUT` yapılınca $\overline{CS}$ 0 olur ve entegre veri yoluna yazabilir ya da yoldan okuyabilir hale gelir. Başka adreslere erişilirken $\overline{CS}$ 1 olur ve entegre araya girip yola veri koymaz.

> **Ders sonrası not:** Hoca bir yerde "chip select ucuna 0 gelmişse mikroişlemci o sırada başka bir cihazla konuşuyordur" dedi. Bağlamdan büyük olasılıkla kastedilen 1'dir: $\overline{CS}$ = 1 iken entegre seçili değildir ve işlemci başka bir cihazla haberleşiyordur.

RxD dış dünyadan seri verinin geldiği uçtur (Receive Data). TxD veriyi bit bit dışarı gönderen fiziksel uçtur (Transmit Data). Modem kontrol uçları senkron/modem haberleşmesiyle ilgili olduğu için kullanılmayacak.

$\overline{RxC}$ ve $\overline{TxC}$ uçlarına bağlanan saat frekansı baud rate'i belirler: bu frekans aynen kullanılabilir, 16'ya ya da 64'e bölünebilir. RESET ucu entegreyi dışarıdan donanımsal olarak sıfırlar; örneğin sistem açılırken elektriksel seviyeler kararlı hale gelene kadar sistemin ürettiği reset işareti buraya verilerek entegre resette bekletilebilir. CLK ucu entegrenin iç zamanlaması içindir; 8086'yı süren yardımcı saat üreteci entegresinin çıkışı buraya verilebilir. CLK'nin alma ve gönderme baud rate'i ile ilgisi yoktur; baud rate yalnız $\overline{RxC}$ ve $\overline{TxC}$ ile ilgilidir. Slayttaki notta CLK için "frequency must be at least 30 times the data bit rate of the receiver or transmitter" yazar (ekrandan, 01:15:00).

### 9.6 RxRDY ve TxRDY

8251 RxD ucundan bit bit veri alır; 8 bit tamamlanınca ara yazmaçtaki (receiver shift register) veriyi data-in tamponuna aktarır. Data-in tamponu dolduğunda, yani işlemci veriyi okuyabilir hale geldiğinde RxRDY ucu 1'e çıkar. Bu fiziksel bir uç olduğu için işlemciye kesme isteği oluşturmakta kullanılabilir.

Gönderme yönünde işlemci dışarı gönderilecek bir baytı data-out tamponuna yazar; veri transmitter shift register'a aktarılır ve bit bit gönderilir. Gönderim tamamlanıp tampon boşalınca TxRDY 1'e çıkar; bu da bir sonraki bayt için kesme isteği oluşturmakta kullanılabilir.

> **Hocanın vurgusu:** RxRDY tampon dolduğunda, TxRDY tampon boşaldığında 1 olur. RxRDY = 1 "veri data-in tamponunda hazır, işlemci okuyabilir", TxRDY = 1 "önceki bayt gönderildi, işlemci yeni baytı data-out tamponuna yazabilir" demektir.

RxRDY ve TxRDY fiziksel uç olmalarının yanında durum yazmacında birer bit olarak da bulunur; bu yüzden polling mantığında durum yazmacı okunarak da kullanılabilirler.

## 10. G/Ç veri aktarım yöntemleri: polling, kesme, DMA

Hoca RxRDY'nin kesme için kullanılmasını anlatırken bir parantez açıp G/Ç cihazlarıyla işlemci arasındaki üç aktarım yöntemini hatırlattı:

- **Polling:** İşlemci çevre birimini sürekli kontrol eder: durum yazmacını okur, ilgili biti maskeler, hazır değilse yeniden okur. Bit hazır değerini alınca veriyi okur. Kod, cihaz hazır olana kadar aktif olarak bekleyip bloklanır.
- **Kesme tabanlı aktarım:** İşlemci başka bir işle (örneğin ekranı sürmekle) uğraşırken klavyeden bir tuşa basılır ve kesme istek ucu üzerinden fiziksel bir kesme isteği gelir. İşlemci o an yürüttüğü komutu bitirir, kesmenin kaynağına ve ilgili kesme alt yordamına bakar ve isteği yerine getirir (örneğin basılan tuşu okuyup komut satırına yazar).
- **DMA (Direct Memory Access):** İlk iki yöntemde bir G/Ç cihazından belleğe aktarılan veri önce mutlaka işlemciye gelir. DMA'da araya bir DMA kontrolcüsü girer. İşlemci başta kontrolcüyü programlar (kaynak ve hedef adresleri, kaç bayt aktarılacağı), sonra yol kontrolünü kontrolcüye devreder. Aktarım sırasında veri işlemciye uğramaz; bu yüzden büyük miktarda veri aktarımında DMA anlamlıdır.

Bu bağlamda RxRDY ve TxRDY uçları kesme tabanlı iletişim için, durum yazmacındaki karşılıkları ise polling için kullanılır.

## 11. 8251 yazmaçlarına erişim ve ilk ayarlama akışı

### 11.1 Erişim tablosu

Erişim kuralları (hocanın sözlü özeti):

| $\overline{CS}$ | C/$\overline{D}$ | İşlem | Erişilen yazmaç |
|---|---|---|---|
| 1 | X | X | Seçili değil, veri uçları yüksek empedans |
| 0 | X | $\overline{RD}$ ve $\overline{WR}$ yok | Veri uçları yüksek empedans |
| 0 | 1 | Okuma | Durum yazmacı |
| 0 | 0 | Okuma | Data-in tamponu |
| 0 | 0 | Yazma | Data-out tamponu |
| 0 | 1 | Yazma | Sıraya göre mod, senkron karakterleri ya da kontrol yazmacı |

Yüksek empedans, veri uçlarının sanki yoldan koparılmış gibi davranması demektir.

### 11.2 İlk ayarlama akış şeması

Slayttaki "8251 İlk Ayarlama" akışı (ekrandan, 01:30:00):

```text
Reset operation
  -> Put output in mode register
  -> Asynchronous?
       F (senkron): Put output in sync character 1
                    -> Two sync characters?  T: Put output in sync character 2
       T (asenkron): devam
  -> A0 = 1 ?
       F: Put output in data-out buffer reg.  -> tekrar A0 = 1 ? sorusuna
       T: Reset?
            T: Reset operation (başa dön)
            F: Put output in control reg.  -> tekrar A0 = 1 ? sorusuna
```

Hoca senkron dalı (senkron karakterleri) kapsam dışı diye üstünü çizdi. Akış reset ile başlar: reset donanımsal olarak RESET ucuyla ya da yazılımsal olarak yapılabilir. Resetten sonra adres ucu 1 iken yapılan ilk yazma mod yazmacına gider; mod yazmacına yazılan değer haberleşmenin senkron mu asenkron mu olacağını belirler. Asenkron seçildiyse adres ucu 1 iken yapılan ikinci yazma kontrol yazmacına gider. Kontrol yazmacına gönderilen değerle yazılımsal reset yapılabilir; yapılırsa akış başa döner, yapılmazsa değer kontrol sözcüğü olarak kalır. Adres ucu 0 iken yapılan okuma ve yazmalar veri tamponlarına gider.

Asenkron modda izlenecek yol şudur: entegre yazılımsal olarak resetlenir (akış bir kez reset yönünde döndürülür), sonra mod yazmacına asenkron mod ayarı yazılır, sonra adres ucu 1 ile bir yazma daha yapılarak kontrol değerleri ayarlanır.

## 12. Mod, kontrol ve durum yazmaçları

### 12.1 Mod yazmacı (asenkron)

Slayttaki asenkron mod sözcüğü (ekrandan, 01:35:00):

| D7 D6 | D5 | D4 | D3 D2 | D1 D0 |
|---|---|---|---|---|
| S2 S1 | EP | PEN | L2 L1 | B2 B1 |

- **B2 B1, baud rate faktörü:** 00 senkron mod, 01 faktör 1, 10 faktör 16, 11 faktör 64. Asenkron mod için son iki bite 00 dışında bir değer yazılır; 00 yazılırsa entegre senkron moda geçer. Faktör 1'de $\overline{RxC}$/$\overline{TxC}$ frekansı olduğu gibi baud rate olur; 16'da bu frekans 16'ya, 64'te 64'e bölünür.
- **L2 L1, veri biti sayısı:** 00 → 5, 01 → 6, 10 → 7, 11 → 8.
- **PEN, parite izni:** 0 parite yok, 1 parite var. Parite varsa start biti, D0-D7 veri bitleri, parite biti ve stop bitleri sırasıyla gönderilir; yoksa start, veri ve stop.
- **EP, parite türü:** 0 odd, 1 even.
- **S2 S1, stop biti sayısı:** 00 geçersiz, 01 → 1, 10 → 1,5, 11 → 2.

$\overline{RxC}$ ve $\overline{TxC}$'ye farklı frekanslar bağlanabilir ama faktör (1, 16 ya da 64) ikisine birlikte uygulanır.

Slaytın alt yarısındaki senkron mod sözcüğünü (SCS, ESD, EP, PEN, L2, L1, 0, 0) hoca kapsam dışı diye çizdi.

### 12.2 Kontrol yazmacı

Hoca modemle ilgili bitleri kullanılmayacak diye işaretledi; kalan bitler:

- **D0 TxEN (transmit enable):** 8251'in dışarı veri göndermesi için 1 yapılır.
- **D2 RxE (receive enable):** Dışarıdan veri alması için 1 yapılır. Hem göndermek hem almak isteniyorsa ikisi de 1 olmalıdır.
- **D4 ER (error reset):** 1 yazılınca önceki haberleşmeden kalmış üç hata bitini (parite, overrun, çerçeve) temizler.
- **D6 IR (internal reset):** 1 yazılınca 8251 yazılımsal olarak resetlenir.

> **Hocanın vurgusu:** 8251 programlanırken akış hep şöyle kurulacak: kontrol yazmacı üzerinden yazılımsal reset, ardından gerçek mod sözcüğü ve gerçek kontrol sözcüğü.

<!-- BELİRSİZ: kontrol yazmacının bit düzenini gösteren slayt karelerde yok; bit konumları 11H = ER + TxEN ve 40H = IR çözümlemesinden ve hocanın anlatımından alındı. RxE'nin D2 olduğu karelerden doğrulanmadı. -->

### 12.3 Durum yazmacı

Durum yazmacı adres ucu 1 iken yapılan okumalarda okunur. Slayttaki bit düzeni (ekrandan, 01:40:00):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|
| DSR | SYNDET | FE | OE | PE | TxE | RxRDY | TxRDY |

- **D0 TxRDY:** Fiziksel TxRDY ucuna karşılık gelir. Slayttaki nota göre data-out tamponunun boş olduğunu gösterir ve TxRDY ucundan farklı olarak $\overline{CTS}$ ucundan ve TxEN kontrol bitinden etkilenmez. Birden çok bayt gönderilecekse ilk bayt 8251'e yazılır, 8251 onu bit bit kendisi gönderir; bu bit 1 olunca sıradaki bayt yazılır.
- **D1 RxRDY:** RxRDY ucuyla aynıdır. Polling'de durum yazmacı okunur, bu bit maskelenir; 1 değilse okuma sürüyordur ve tekrar kontrol edilir; 1 olunca data-in tamponu okunur.
- **D2 TxE:** TxE ucuyla aynıdır (verici boş).
- **D3 PE (parite hatası):** Hesaplanan parite ile gelen parite farklıysa 1 olur. Gelen veri bozulmuştur ve atılmalıdır; üst katmanda yeniden isteme süreci varsa o başlatılabilir.
- **D4 OE (overrun hatası):** Örneğin TxRDY 1 olmadan yeni veri yazılıp gönderilmekte olan verinin üzerine yazılırsa ya da alma yönünde RxRDY 1 olmadan yarım bir veri okunursa oluşan hata. <!-- BELİRSİZ: hoca overrun'ı gönderme yönündeki üzerine yazmayla da açıkladı; 8251'de OE büyük olasılıkla yalnız alma yönünde, işlemci önceki baytı okumadan yeni bayt gelince 1 olur. -->
- **D5 FE (çerçeve hatası):** Örneğin iki stop biti beklenirken bir stop bitinden sonra 0 gelirse çerçeve hatalıdır ve FE 1 olur.
- **D6 SYNDET, D7 DSR:** Senkron mod ve modemle ilgilidir; hoca üstünü çizdi.

Hata bitleri kontrol yazmacındaki ER biti ile temizlenip sonraki sürece yeniden başlanabilir.

**Soru:** (Bir öğrenci 8251 ile 8255'in farkını sordu.) **Cevap:** 8255 paralel veri göndermek için kullanılıyordu; üç tane 8 bitlik portu vardı ve bir seferde 8 bit dışarı aktarılabiliyordu. 8251'in temel görevi seri aktarımdır ve fonksiyonları buna göredir. Ayrıca 8255'in iki, 8251'in tek adres ucu vardır; 8255'in dışarıdan erişilen 4, 8251'in 7 yazmacı vardır. <!-- BELİRSİZ: sorunun metni altyazıda duyulmuyor; yalnız cevaptan çıkarıldı. -->

## 13. Proteus örnekleri

### 13.1 Devre

Proteus'ta "Virtual Terminal" bileşeni eklenebilir (ekrandan, 01:45:00). Bu sanal terminalin RXD, TXD uçları ve modem kontrol uçları (RTS, CTS) vardır; özelliklerinden seri haberleşme ayarı yapılır. Örnekte 9600 baud, 8 veri biti, paritesiz, 1 stop biti ayarlıdır. Terminal ekranında bir tuşa basılınca karakter seri olarak karşı tarafa gönderilir; karşıdan gelen verinin ASCII karşılığı ekrana basılır.

Devrede ayrıca bir mantık analizörü vardır. Bu gönderme örneği olduğu için TxD ve TxRDY uçları analizöre bağlanmıştır; böylece her TxRDY 1 olduğunda yeni gönderimin başladığı görülebilir.

8251'in $\overline{RxC}$ ve $\overline{TxC}$ uçlarına 9600 Hz'lik bir saat (CLOCK) bağlıdır. Sanal terminal 9600 baud'da çalıştığı için mod yazmacında faktör 1 seçmek yeterlidir.

8251 208H ve 20AH adreslerine yerleştirilmiştir. Adres çözümleme için 4x16'lık bir kod çözücü (74HC154) kullanılmıştır (ekrandan, 02:00:00); tüm adres aralığı çözümlenmemiş olabilir, bazı uçlar boşta olabilir. Hoca bu devrenin 208H ve 20AH için uygun çözümleme yaptığını, öğrencilerin nasıl çalıştığını kendilerinin test etmesini söyledi.

Adreslerin ikilik yazımı (ekrandan, 01:50:00; python ile doğrulandı):

```text
20AH = 0000 0010 0000 1010
208H = 0000 0010 0000 1000
```

Cihaz ardışık çift adreslere yerleştirildiği için A0 her iki adreste de aynıdır; iki adres arasındaki tek fark A1 bitidir. Bu yüzden A1 hattı 8251'in C/$\overline{D}$ ucuna bağlanmıştır. 20AH'ye erişildiğinde C/$\overline{D}$ = 1 (kontrol/mod/durum), 208H'ye erişildiğinde C/$\overline{D}$ = 0 (veri) olur.

> **Ders sonrası not:** Hoca "ardışık çift adreslere yerleştirdiğimiz için A0 her zaman 1 gelecek" dedi. Doğrusu A0'ın her zaman 0 olmasıdır; çift adreslerin en düşük biti 0'dır (208H ve 20AH'nin ikilik yazımında da son bit 0'dır).

Adres 8 bite sığmadığı için dolaylı G/Ç adreslemesi gerekir. Normalde `OUT 58H, AL` gibi doğrudan adresleme yalnız adres 8 bite sığıyorsa yapılabilir. Sığmıyorsa önce adres DX'e, gönderilecek değer AL'ye konur ve `OUT DX, AL` çalıştırılır.

Hoca, 8251'in çalışması için RESET ve $\overline{CTS}$ uçlarının 0'da olması gerektiğini, laboratuvarda bu bağlantıların hazır yapılmış olarak verileceğini söyledi.

### 13.2 Gönderme örneği: sürekli 'A'

Program EXE tipindedir: yığın, veri ve kod segmenti tanımlıdır ve DS'nin veri segmentini göstermesi için ayar yapılır. Programın iki bölümü vardır: 8251'i yazılımsal olarak resetleyip ayarlayan bölüm ve 8251 hazır oldukça sürekli büyük 'A' gönderen sonsuz döngü. Döngünün içinde TxRDY'nin 1 olmasını bekleyen bir iç döngü vardır.

Ekrandaki kod (ekrandan, 01:55:00):

```asm
CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
START:
        MOV AX, DATA
        MOV DS, AX

        MOV DX, 020Ah

        MOV AL, 01001101B
        OUT DX, AL

        MOV AL, 40H
        OUT DX, AL

        MOV AL, 01001101B
        OUT DX, AL

        MOV AL, 00010001B
        OUT DX, AL

ENDLESS:
        MOV DX, 020AH
TEKRAR:
        IN  AL, DX
        AND AL, 01H
        JZ  TEKRAR

        MOV DX, 0208H
        MOV AL, 41H
        OUT DX, AL

        JMP ENDLESS
CODE    ENDS
        END START
```

Ayar sözcüklerinin çözümü (python ile doğrulandı):

- `01001101B` (4DH), mod yazmacı: B2 B1 = 01 faktör 1 ($\overline{RxC}$ ve $\overline{TxC}$ 1'e bölünür); L2 L1 = 11, 8 veri biti; PEN = 0, parite yok (EP önemsiz); S2 S1 = 01, 1 stop biti. Resetten sonraki ilk yazma olduğu için mod yazmacına gider.
- `40H` = `01000000B`, kontrol yazmacı: yalnız D6 (IR) 1, yani 8251 yazılımsal olarak resetlenir. Asenkron mod ayarlandığı için bu ikinci yazma kontrol yazmacına gitmiştir.
- Yine `01001101B`: resetten sonraki ilk yazma olduğu için tekrar mod yazmacına gider; asıl mod ayarı budur.
- `00010001B` = 11H, kontrol yazmacı: D4 (ER) hata bitlerini temizle, D0 (TxEN) göndermeye izin ver.

Döngüde 20AH'den (C/$\overline{D}$ = 1, okuma) durum yazmacı okunur. `AND AL, 01H` en düşük biti (TxRDY) maskeler; sonuç 0 ise TxRDY henüz 1 değildir ve `JZ TEKRAR` ile tekrar okunur. Sonuç 0 değilse yeni bayt gönderilebilir: veri C/$\overline{D}$ = 0 ile, yani 208H'ye yazılır. 41H büyük 'A'nın ASCII kodudur.

Hoca kodu bir yazmaçla değişen karakter gönderecek şekilde de denedi: karakter BL'de tutulup her gönderimden sonra `INC BL` yapılınca 'A'dan başlayarak ardışık bütün ASCII karakterleri gönderilir. Bu sırada duyulan zil sesleri ASCII tablosunun başındaki kontrol karakterlerinden kaynaklanır; bu karakterler gelince terminal uyarı sesi üretir. <!-- BELİRSİZ: bu değiştirilmiş kodun tam satırları karelerde yok. -->

Mantık analizöründe TxRDY 1'e çıktıktan sonra TxD hattında 41H'nin çerçevesi görülür: start biti 0, sonra 41H'nin en düşük biti 1, ardından 0'lar, 4 hanesinden gelen 1, en yüksek bit 0 ve stop biti. Python ile 41H'nin LSB'den MSB'ye bitleri `1 0 0 0 0 0 1 0` olarak doğrulandı.

### 13.3 Alma ve gönderme örneği

Bu örnekte devre aynıdır ama sanal terminalden de veri gönderilir: 8251 karakteri alır, işlemciye aktarır, işlemci karakterin bir sonraki ASCII karşılığını sanal terminale geri gönderir.

Kodun akışı (hocanın anlatımından):

- DS ayarı, yazılımsal reset, mod yazmacına aynı değer (faktör 1, 8 veri biti, paritesiz, 1 stop), kontrol yazmacına alma izni ve hata temizleme. <!-- BELİRSİZ: bu örneğin kontrol sözcüğü karelerde görünmüyor; hoca "Receive Enable ve Erase Errors" dedi. Karakter geri gönderildiği için TxEN'in de 1 olması gerekir. -->
- Sonsuz döngüde önce 20AH'den durum okunur, durum yazmacının 1 numaralı biti (RxRDY) maskelenir; 0 ise veri henüz alınmamıştır, beklenir.
- RxRDY 1 olunca data-in tamponu (208H) okunur. Okunan değer bir artırılır ('A' okunduysa 'B' olur) ve geçici olarak BL'ye konur.
- Sonra durum yazmacı yeniden okunur ve en düşük bit (TxRDY) maskelenir; 1 olana kadar beklenir.
- TxRDY 1 olunca BL'deki değer 208H'ye (data-out tamponu) yazılır.

Çalıştırıldığında terminalde küçük 'a'ya basılınca 'b', küçük 'b'ye basılınca 'c', büyük 'A'ya basılınca 'B' geri gelir; böylece hem veri alındığı hem gönderildiği görülür.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:48:31): Elimizdeki yazmaç ve bayrakları kullanarak 8 bitten büyük, sanal bir 9 bitlik yazmaç nasıl oluşturulur? (8 bitlik bir 8255 portundan 10-11 bitlik seri çerçeve gönderilmek isteniyor.)

> **Çözüm (derste verildi):** Elde bayrağıyla döndüren komutlar (`RCL`, `RCR`) AL ile CF'yi birleştirip 9 bitlik bir yazmaç gibi döndürür. `CLC` + `RCL AL,1` ile start biti (0) D0'a gelir; her `RCR AL,1` sıradaki biti D0'a getirir; `STC` ile AL soldan 1'lerle beslenir ve veriden sonra D0'a stop biti (1) gelir.

**Soru 2** (ekrandan, 00:35:00): Veri bitleri `1 1 0 1 1 1 1 0` olan bir çerçevede çift parite ve tek parite için parite biti ne olur?

> **Çözüm (derste verildi):** Veride altı tane 1 vardır. Çift paritede toplamın çift kalması için P = 0, tek paritede toplamın tek olması için P = 1.

**Soru 3** (derste sözlü, 00:38:32): Yalnız tek yönde haberleşilen (simpleks), bir seferde tek yönde ama iki yönü de destekleyen (yarı dupleks) ve aynı anda iki yönde haberleşilen (tam dupleks) yapılara günlük hayattan birer örnek verin.

> **Çözüm (derste verildi):** Simpleks: karasal radyo ve TV yayını. Yarı dupleks: telsiz. Tam dupleks: cep telefonu görüşmesi.

**Soru 4** (derste sözlü, 01:12:27): Tek adres ucu (C/$\overline{D}$) olan 8251, G/Ç adres uzayında kaç bayt yer kaplar?

> **Çözüm (derste verildi):** Tek adres ucu 0 ya da 1 olabilir; $2^1 = 2$ bayt kaplar. Buna karşın dışarıdan erişilen 7 yazmacı vardır ve bunlara erişim C/$\overline{D}$, $\overline{RD}$/$\overline{WR}$ ve yazma sırasıyla ayrılır.

**Soru 5** (derste sözlü, 00:29:01 ve 00:41:15): 9600 baud ve 1200 baud için bir bit hatta ne kadar süre kalır? 9600 baud'da 1,5 ve 2 stop biti ne kadar sürer?

> **Çözüm (derste verildi, python ile doğrulandı):** $1/9600 \approx 104{,}2\ \mu s$; $1/1200 \approx 0{,}83\ ms$. 1,5 stop biti $\approx 156\ \mu s$, 2 stop biti $\approx 208\ \mu s$.

**Soru 6** (ekrandan, 01:50:00): 8251 208H ve 20AH adreslerine yerleştirilmiştir. Hangi adres hattı C/$\overline{D}$ ucuna bağlanmalıdır ve neden dolaylı G/Ç adreslemesi gerekir?

> **Çözüm (derste verildi):** 20AH = `0000 0010 0000 1010`, 208H = `0000 0010 0000 1000`; tek fark A1 bitidir, bu yüzden A1 C/$\overline{D}$'ye bağlanır (20AH kontrol/durum, 208H veri). Adres 8 bite sığmadığı için `MOV DX, adres` ile DX kullanılıp `OUT DX, AL` / `IN AL, DX` yazılır.

**Soru 7** (derste, zorunlu olmayan ev çalışması, 00:58:47): Yazılımsal seri alma (receive) rutinini yazın: start bitini kontrol edin, 8 veri bitini biriktirin, stop bitini kontrol edin.

> **Çözüm (derste verilmedi):** Aşağıdaki rutin, gönderme örneğindeki varsayımlarla (seri giriş portun 0. bitinde, `DELAY` bir bit süresi, ayrıca yarım bit bekleyen `HALFDELAY` yordamı var) yazılmış bir taslaktır; derste yazılmadı ve derlenmedi, bit sırası python benzetimiyle kontrol edildi.
>
> ```asm
> RECV    PROC NEAR
> BEKLE:  IN   AL, DPORT
>         RCR  AL, 1          ; seri bit CF'ye
>         JC   BEKLE          ; hat 1 ise (boş) beklemeye devam
>         CALL HALFDELAY      ; start bitinin ortasına git
>         IN   AL, DPORT
>         RCR  AL, 1
>         JC   BEKLE          ; hâlâ 0 değilse sahte start, başa dön
>         MOV  CX, 8
> AL_BIT: CALL DELAY          ; sonraki bitin ortası
>         IN   AL, DPORT
>         RCR  AL, 1          ; bit CF'de
>         RCR  BL, 1          ; CF'yi BL'nin soluna sok (LSB önce gelir)
>         LOOP AL_BIT
>         CALL DELAY          ; stop biti
>         IN   AL, DPORT
>         RCR  AL, 1
>         JNC  BEKLE          ; stop biti 1 değilse çerçeve hatası
>         MOV  AL, BL         ; alınan karakter AL'de
>         RET
> RECV    ENDP
> ```
>
> 8 kez `RCR BL,1` yapıldığında ilk gelen bit (D0) BL'nin 0. bitine iner, son gelen bit (D7) 7. bitte kalır.

## Dersin Toparlaması

Bu derste seri haberleşmenin temeli kuruldu: paralel ve seri iletim karşılaştırıldı, senkron ve asenkron iletişimin farkı ve derste yalnız asenkron iletişimin kullanılacağı belirtildi. Asenkron çerçevenin yapısı (boş hat 1, start biti 0, LSB önce veri, isteğe bağlı parite, 1/1,5/2 stop biti), baud rate ile bit süresi ilişkisi, parite hesabı, simpleks/dupleks yapılar ve parite, checksum, CRC gibi hata tespit yöntemleri görüldü. Ardından aynı çerçevenin bir 8255 portunun tek bitinden, CF'yi 9. bit olarak kullanan `RCL`/`RCR` komutlarıyla yazılımsal olarak nasıl gönderileceği incelendi.

Dersin ikinci yarısında 8251 USART ele alındı: uçları, tek adres ucuyla 7 yazmaca erişim kuralı, ilk ayarlama akışı (yazılımsal reset, mod, kontrol), mod, kontrol ve durum yazmaçlarının bitleri. Proteus'ta 208H/20AH adreslerine yerleştirilmiş bir 8251 ile sürekli 'A' gönderen ve terminalden gelen karakterin bir sonrakini geri yollayan iki örnek çalıştırıldı. Bu örnekler bir sonraki 8251 laboratuvarının temelini oluşturuyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
