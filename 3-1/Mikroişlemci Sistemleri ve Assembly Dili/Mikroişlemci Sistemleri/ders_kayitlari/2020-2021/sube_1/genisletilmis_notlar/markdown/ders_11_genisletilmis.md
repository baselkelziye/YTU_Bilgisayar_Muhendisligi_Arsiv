# Ders 11 Genişletilmiş Notu: 8255 Mod 2, Seri Haberleşme ve 8251 USART

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 8255 modlarının tekrarı
- 2. Mod 1'de kesme izin bitleri ve durum sözcüğü
- 3. Mod 2: çift yönlü veri yolu
- 4. Modların port kullanımı özeti
- 5. Mod 1 Proteus örneğinin tekrarı
- 6. Seri ve paralel veri iletişimi
- 7. Senkron ve asenkron iletişim
- 8. Simplex, half duplex ve full duplex
- 9. Baud hızı ve hesap örnekleri
- 10. Hata tespiti: eşlik ve CRC
- 11. Yazılımsal seri gönderici ve alıcı
- 12. 8251 USART: uçlar ve bağlantı
- 13. 8251 yazmaçları ve erişim akışı
- 14. 8251 mod, kontrol ve durum yazmaçları
- Örnek Sorular

## 1. 8255 modlarının tekrarı

Ders, önceki haftada görülen 8255 bit set/reset (BSR), mod 1 ve mod 2 durumlarının tekrarıyla başlar. Üç mod birbirinden şöyle ayrılır:

- **Mod 0 (Basic I/O):** el sıkışma (handshake) gerektirmeyen temel giriş-çıkıştır. Karşı tarafın veriyi aldığı varsayılır. LED, düğme gibi doğrudan değer olarak sürülen ya da okunan uçlar bu moda karşılık gelir. Bir port ucuna LED ya da düğme bağlandıysa, o uçların mod 0'da ayarlanması gerektiği doğrudan çıkarılabilir.
- **Mod 1:** el sıkışma tabanlı iletişimdir. Veri uçlarının yanında el sıkışma uçları vardır. Giriş yönlü ayarlanmış bir portta dış dünya veri hazır olduğunda bir strobe ($\overline{STB}$) işareti gönderir, 8255 de karşı tarafa input buffer full (IBF) işaretiyle cevap verir. Çıkış yönlü bir portta 8255 veriyi uçlara hazırladığında dış dünyaya output buffer full ($\overline{OBF}$) işareti gönderir ve dış dünyadan acknowledge ($\overline{ACK}$) işareti bekler. Mod 1'de port ayarlandığı tek yönde çalışır.
- **Mod 2:** o da el sıkışma içerir, ama çift yönlüdür. Port adresine `OUT` komutu çalıştırılmışsa çıkış yönlü, `IN` komutu çalıştırılmışsa giriş yönlü bir el sıkışma iletişimi oluşur.
- **Bit set/reset modu:** port C'nin herhangi bir ucunu çıkış yönlü olarak doğrudan 0 ya da 1 yapmak için kullanılır. Bu uç G/Ç amaçlı kullanılabildiği gibi, mod 1 ve mod 2'de kesme izin (interrupt enable) bitlerini ayarlamak için de kullanılır.

## 2. Mod 1'de kesme izin bitleri ve durum sözcüğü

### 2.1 Giriş yönlü grup A

Giriş yönlü grup A'da dış dünyadan strobe geldiğinde veri uçları içeri örneklenir, okuma bitince dış dünyaya IBF gönderilir. Ancak bu sinyalleşme 8086'nın kesme istek ucu için uygun değildir. Bu yüzden ayrı bir kesme istek ucu (INTR) vardır: bu uç port C'nin 3 numaralı ucudur (PC3). INTR'nin oluşabilmesi için $\text{INTE}_A$ (interrupt enable A) bitinin 1 olması gerekir. $\text{INTE}_A$, dışarıdan erişilebilen bir ayar biti gibi düşünülebilir ve giriş yönlü grup A'da **PC4'ün BSR moduyla set edilmesine** karşılık gelir. Bu yapıldığında uygun strobe ve IBF anında INTR sinyali elde edilir.

### 2.2 Çıkış yönlü grup A ve grup B

Çıkış yönlü çalışmada 8255 veriyi uçlara koyunca dış dünyaya $\overline{OBF}$ gönderir; dış dünyadan $\overline{ACK}$ gelmesiyle bir sonraki gönderim çevrimi başlar. İşlem $\overline{OBF}$ ya da IBF üzerinden yoklama (polling) ile değil de kesmeyle yürütülmek isteniyorsa yine aynı sorun vardır: $\overline{OBF}$ tek başına kesme isteği oluşturabilecek yapıda değildir. Bu yüzden uygun $\overline{ACK}$ ve $\overline{OBF}$ anında kesme isteği üreten ayrı bir uç vardır; grup A için bu yine PC3'ten çıkar ve ilgili INTE biti BSR modunda set edilmelidir. <!-- BELİRSİZ: 00:07:24-00:07:39 arasında çıkış yönlü grup A için hangi port C bitinin set edileceği altyazıda kayıp; standart 8255'te bu PC6'dır. -->

Giriş yönlü grup B için de aynı durum geçerlidir: kesmeleri açmak, yani $\text{INTE}_B$ bitini set etmek için **PC2'nin BSR modunda set edilmesi** gerekir.

### 2.3 Durum sözcüğü (status word)

Mod 1'de port C adresinden yapılan okumalar **durum sözcüğünü** verir. Kesme tabanlı kullanımda INTR uçları yazmaçta birer bit olarak da saklanır; IBF ve $\overline{OBF}$ de durum bitleri olarak bulunur. Slayttaki tablo şöyledir (ekrandan, 00:10:00):

| Yön | D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|---|
| Giriş | I/O | I/O | $\text{IBF}_A$ | $\text{INTE}_A$ | $\text{INTR}_A$ | $\text{INTE}_B$ | $\text{IBF}_B$ | $\text{INTR}_B$ |
| Çıkış | $\overline{\text{OBF}}_A$ | $\text{INTE}_A$ | I/O | I/O | $\text{INTR}_A$ | $\text{INTE}_B$ | $\overline{\text{OBF}}_B$ | $\text{INTR}_B$ |

D7-D3 grup A'ya, D2-D0 grup B'ye aittir.

Veri aktarımının tamamlanıp tamamlanmadığı INTR biti üzerinden denetlenmek isteniyorsa maskeleme yapılır. $\text{INTR}_A$ D3'tedir: D7-D4 sıfırla maskelenir, D3 korunur, D2-D0 yine sıfırla maskelenir. Bu, $0000\,1000_2 = 08\text{H}$ ile VE'lemeye karşılık gelir. $\text{INTR}_B$ D0'da olduğundan maske `01H`'dir. Böylece $\text{INTR}_A$ ve $\text{INTR}_B$ yoklama mantığıyla okunabilir. Aynı işlem IBF ya da $\overline{OBF}$ üzerinden yürütülecekse $\text{IBF}_A$, $\text{IBF}_B$, $\overline{\text{OBF}}_A$, $\overline{\text{OBF}}_B$ bitleri uygun biçimde maskelenir.

## 3. Mod 2: çift yönlü veri yolu

Hoca, önceki derste mod 2 üzerinde durulmadığını hatırlatıp konuyu tamamlar.

Mod 2 (strobed bidirectional bus I/O) **yalnız grup A** tarafından desteklenir. Port A veri alışverişinden sorumlu çift yönlü porttur; port C'ye ait 5 uç el sıkışma ve kontrol işareti olarak kullanılır.

Kontrol sözcüğünde en yüksek anlamlı bitin (D7) 1 olması bir mod ayarı yapılacağı anlamına gelir. D6 = 1 ve D5 = X (önemsiz) grup A'nın mod 2'de çalışacağını belirtir. Grup A ve port C'nin ilgili kısmı için yön ayarı gerekmez, çünkü mod 2 zaten iki yönlüdür. Grup B ise mod 0 ya da mod 1'de, giriş ya da çıkış yönlü ayarlanabilir.

Mod 2'de PC3 bir kontrol biti (INTR) olarak görev yapar. Bu yüzden port C'nin düşük yarısından yalnız 3 bit, PC0-PC2, giriş ya da çıkış olarak kullanılabilir. İç yapı çiziminde port A, çift yönlü olduğu için iki yönlü okla gösterilir; bir taraf giriş yönlü, bir taraf çıkış yönlü kontrol işaretlerini taşır.

Hem giriş hem çıkış işlemlerinde kesme isteği oluşması isteniyorsa iki izin biti BSR modunda ayarlanır:

- **INTE1:** PC6 BSR modunda set edilir.
- **INTE2:** PC4 BSR modunda set edilir.

Veri gönderme ya da alma tamamlandığında INTR ucu, yani PC3 üzerinden kesme isteği oluşur.

### 3.1 Mod 2 zamanlaması

Slayttaki zamanlama diyagramında (ekrandan, 00:15:00) önce bir yazma, sonra bir okuma işlemi birbirini izler. Yazma işlemiyle değer 8255'e gönderilir, bir süre sonra port A'da veri olarak çıkar ve $\overline{OBF}$ etkin olup 0'a düşer. Dış cihazdan $\overline{ACK}$ gelince $\overline{OBF}$ yeniden 1'e çıkar ve yazma çevrimi tamamlanır. Okuma tarafında dış dünya veriyi port A uçlarına koyup $\overline{STB}$'yi 0'a çektiğinde veri içeri okunmaya başlar; okuma bitince IBF 1'e çekilir ve verinin okunduğu anlaşılır. Okuma çevrimi için de kesme tabanlı denetim çalışır.

Mod 2'de, INTE1 ve INTE2 birlikte etkinleştirildiğinde, durum sözcüğünde $\text{INTR}_A$ D3'te, $\text{IBF}_A$ D5'te, $\overline{\text{OBF}}_A$ D7'de bulunur.

## 4. Modların port kullanımı özeti

Hoca özet tabloyla üç modun port kullanımını karşılaştırır:

- **Mod 0:** port A giriş ayarlandıysa 8 bitin 8'i de giriş, çıkış ayarlandıysa 8'i de çıkış olur. Aynısı port B ve port C için geçerlidir; port C'nin yüksek ve düşük yarıları 4 bitlik ayrı portlar gibi kullanılabilir.
- **Mod 1:** giriş yönlü çalışmada port C'nin yalnız 6 ve 7 numaralı bitleri boşta kalır; çıkış yönlü çalışmada yalnız 4 ve 5 numaralı bitleri boşta kalır. Grup A ve grup B ayrı ayrı giriş ya da çıkış yönlü ayarlanabilir.
- **Mod 2:** port A çift yönlüdür; port B mod 0 ya da mod 1'de çalışır. Port C uçlarının kalanı grup B'nin mod 1 ayarlarına göre kullanılır.

## 5. Mod 1 Proteus örneğinin tekrarı

Önceki hafta yapılan mod 1 örneği tekrar ele alınır; örnek bir sonraki deneyin konusu olacağı için incelenmesi önerilir. Hoca örneğin paylaşılmadığını fark edip ders sırasında sisteme ekler.

### 5.1 Tuş takımı yardımcı devresi

Devrede 4×4 bir tuş takımı vardır, ama düşük seviyede sürülmez. Bir yardımcı devre, tuş tarama entegresi (Proteus'ta MM74C922, ekrandan 00:20:00), sütunları sürüp satırlardan okumayı otomatik yapar. Bir tuşa basılırsa satırların birinde varsayılan değerden farklı bir değer görülür. Bu anda hangi sütunun sürüldüğü bellidir; farklı olan satır da basılan tuşun satırıdır. Sütun taraması sonsuz döngüde çok hızlı döndüğü için tuşa çok kısa basılsa bile tarama eninde sonunda o sütuna gelir.

Entegrenin dışarıyla etkileşen iki ucu vardır: **DA (data available)** ve **$\overline{OE}$ (output enable)**. Bir tuşa basılınca DA ucu lojik 1 olur. DA'da 1 görüldüğünde $\overline{OE}$'ye 0 verilirse basılan tuşun ikili değeri D, C, B, A uçlarına çıkar.

### 5.2 Gösterge yardımcı devresi

Diğer tarafta 7 parçalı göstergeyi süren ikinci yardımcı devre **4511** entegresidir. Gösterge ortak katotludur. 4511, girişteki ikili değerin 7 parçalı karşılığını QA-QG uçlarında oluşturup ilgili parçaları yakar. Girişteki değeri içeride tutmak için bir latch enable (strobe) ucu vardır. Hoca, latch enable'a 0 verildiğinde girişler değişse bile göstergenin değişmediğini söyler.

> **Ders sonrası not:** Hoca latch enable'a 0 verilince değerin tutulduğunu söyledi; 4511'de büyük olasılıkla tersi geçerlidir: LE = 0 iken giriş göstergeye geçer, LE = 1 iken son değer tutulur. Devrede $\overline{OBF}$'nin yazmadan sonra 0'a düşerek bu ucu sürmesi de bu davranışla uyumludur.

### 5.3 Bağlantının kurulması

Tuşa basıldığında değer okunacağına göre grup A **mod 1 giriş** yönünde kullanılır; bu durumda $\overline{STB}$ ve IBF işaretleri söz konusudur.

**Soru (hocanın sınıfa sorusu):** Strobe işaretini DA mı yoksa $\overline{OE}$ mi üretir?

**Cevap:** $\overline{OE}$ dış dünyadan sürülen bir uçtur, DA ise dış dünyaya sinyal veren bir uçtur. 8255 tarafından bakıldığında DA'dan bir sinyal gelir, 8255 de buna cevap verir. Bu yüzden DA, 8255 için strobe gibi çalışır. IBF'ye karşılık da $\overline{OE}$ sürülür, yani IBF geldiğinde $\overline{OE}$ 0 yapılır. Devrede DA bir DEĞİL kapısından (U13) geçip PC4'e ($\overline{\text{STB}}_A$), PC5 ($\text{IBF}_A$) bir DEĞİL kapısından (U11) geçip $\overline{OE}$'ye bağlanır; tuş kodu PA0-PA3'e gelir (ekrandan, 00:25:00).

Gösterge devresinin etkileşim için iki ucu yoktur, yalnız latch enable ucu vardır. A, B, C, D uçlarına 8255 değer göndereceği için grup B **mod 1 çıkış** yönünde çalışır; bu durumda $\overline{OBF}$ ve $\overline{ACK}$ işaretleri vardır. İşlemci 8255'e veri yazınca $\overline{OBF}$ yazmadan sonra 0'a düşer; bu sinyal 4511'in strobe girişinde kullanılır. Ancak 4511'in $\overline{ACK}$ üretecek ucu yoktur. Hoca bunu dolaylı yoldan çözer: $\overline{OBF}$ art arda iki DEĞİL kapısından geçirilir. Proteus'ta kapıların özelliklerinde 100 ms gecikme ayarlıdır; böylece $\overline{OBF}$ geldikten 200 ms sonra kapı çıkışında $\overline{ACK}$'ye karşılık gelen değer oluşur. 4511 gerçekte $\overline{ACK}$ üretmez, ama benzetimde bu kabul edilebilir.

### 5.4 Adres çözümleme

Cihazın adres değeri 8 bite sığmadığı için adresin DX üzerinden verilmesi gerekir. Bu örnekte bazı adres uçları boşta bırakılmıştır, yani hangi değerde olacakları belirlenmemiştir; bu yüzden devre pek çok adreste çalışır. Hoca kolaylık olsun diye böyle yaptığını, ama öğrencilerin tasarımlarında cihazın sabit 4 baytlık adres aralığı dışında hiçbir adreste çalışmayacak biçimde tam adres çözümleme yapmaları gerektiğini belirtir. Olası adreslerin en düşüğü örnek adres olarak alınmıştır: cihaz **200H'den itibaren ardışık çift adreslerdedir**.

| Adres | Yazmaç |
|---|---|
| 200H | Port A |
| 202H | Port B |
| 204H | Port C |
| 206H | Kontrol yazmacı |

> **Hocanın vurgusu:** Kendi tasarımlarınızda cihazın 4 baytlık adres aralığını başka hiçbir adres değeriyle çalışmayacak biçimde çözümlemeniz gerekir.

### 5.5 Kod

Ekrandaki kod şöyledir (ekrandan, 00:30:00):

```asm
START:
        mov dx, 206h
        mov al, 09h
        out dx, al
        mov al, 05h
        out dx, al
        mov al, 0BCh
        out dx, al
        mov dx, 202h
ENDLESS:
tekrar1: mov dx, 204h
        in  al, dx
        and al, 08h
        cmp al, 00
        je  tekrar1
        mov dx, 200h
        in  al, dx
        mov bl, al
tekrar:  mov dx, 204h
        in  al, dx
        and al, 01h
        cmp al, 00
        je  tekrar
        mov dx, 202h
        mov al, bl
        out dx, al
        JMP ENDLESS
```

Akış:

- Kontrol adresine yazılan ilk iki değer port A ve port B'nin kesme izin bitlerini kurar. `09H` = $0000\,1001_2$: D7 = 0 (BSR), bit seçimi D3-D1 = 100 = 4, D0 = 1 (set), yani PC4 = 1 → $\text{INTE}_A$. `05H` = $0000\,0101_2$: bit seçimi 010 = 2, set, yani PC2 = 1 → $\text{INTE}_B$ (ara adım eklendi; değerler python ile çözüldü).
- `0BCH` grup A'yı giriş, grup B'yi çıkış yönlü mod 1'e ayarlayan kontrol sözcüğüdür.
- Kesmeler henüz görülmediği için yoklama mantığı kullanılır. Port C'den durum sözcüğü okunur, `08H` ile maskelenir; `08H`'de $\text{INTR}_A$ biti vardır. $\text{INTR}_A$ 1 olana kadar döngüde beklenir. Döngü kırıldığında dış dünyadan okunan veri 8255'in port A yazmacındadır; port A okunur ve değer geçici olarak BL'de saklanır.
- Ardından yazma yönü için aynı işlem yapılır: port C okunur, en düşük anlamlı bitteki $\text{INTR}_B$ `01H` ile maskelenir ve 1 olana kadar beklenir (hoca önce "interrupt enable B" dedi, sonra "interrupt request B" diye düzeltti). Bu bit 1 ise port B yeni veri göndermeye hazırdır; BL'deki değer `OUT` ile port B'ye yazılır.

Sonuçta port A'nın hazır olması beklenir, port A okunur, port B'nin hazır olması beklenir ve okunan değer olduğu gibi port B'ye yazılır. Basılan tuşa karşılık gelen değer 7 parçalı göstergede görünür.

**Soru:** Koddaki `CMP AL,00` ve `JE` yerine başka komutlar kullanılabilir mi? <!-- BELİRSİZ: sorunun tam metni altyazıda yok; hocanın cevabından JZ ve TEST kullanımıyla ilgili olduğu anlaşılıyor. -->

**Cevap:** `JE` ile `JZ` aynı komuttur. `CMP` yerine `TEST` de kullanılabilir. VE'leme sonucunda ilgilenilen bit 0 ise sonuç sıfır olur ve dallanma gerçekleşir; bit 1 ise sonuç sıfırdan farklıdır ve dallanma olmaz. Her iki yazım da aynı sonucu üretir.

## 6. Seri ve paralel veri iletişimi

Yeni konu seri haberleşme ve seri haberleşme yardımcı devresi **8251**'dir. Plan şöyledir: seri ve paralel iletişimin farkı görsel ve tanımsal olarak verilir, seri haberleşmeye ait kavramlar anlatılır, seri haberleşmenin yazılımla yapılması incelenir, sonra 8251'in blok diyagramı, yazmaçları ve işlevleri ele alınır.

Veri iletişiminde paralel ve seri olmak üzere iki yöntem vardır; seri iletişim de kendi içinde **senkron** ve **asenkron** olarak ikiye ayrılır (ekrandan, 00:35:00).

- **Paralel iletişim:** verinin farklı kısımları birden fazla kanal üzerinden **aynı anda** gönderilir. İki terminal arasında birden fazla tel döşenmelidir. Kısa mesafeler için çok daha hızlı ve maliyet açısından uygundur; mesafe uzadıkça çok sayıda paralel kanal döşemek maliyeti yükseltir. Örneğin 8 bitlik bir verinin bütün bitleri tek seferde aktarılır.
- **Seri iletişim:** veri önce serileştirilir, sonra karşı tarafa bit bit gönderilir. Uzun mesafede düşük maliyetiyle öne çıkar. Ancak 8 bitlik bir veri, örneğin en yüksek anlamlı bitten başlanarak, 8 adımda aktarılır; bu yüzden yavaştır.

Seri gönderimde bellekte paralel saklanan veri önce serileştirilmelidir (paralelden seriye dönüşüm). Karşı tarafta bitler tek tek biriktiği için gelen seri bilgi yeniden paralele çevrilmelidir (seriden paralele dönüşüm). Paralel iletişimde ise her bit için ayrı kanal olduğundan veri tek seferde aktarılır.

## 7. Senkron ve asenkron iletişim

### 7.1 Senkron iletişim

İki terminal ortak bir saat işaretini paylaşıyorsa senkron iletişim kullanılabilir. Her iki taraf veriyi aynı anda alıp gönderdiği için senkronizasyon sorunu, kaçak ya da kayma olmaz. Bu yüzden daha geniş paket boyutları kullanılır. Birden fazla paket bir araya gelip bir veri bloğu oluşturduğu için bloğun başı ve sonu çok bitli özel işaretlerle belirtilir. Alıcı aldığı seri bilgileri birleştirerek anlamlı veri bütününü yeniden elde eder.

Her bayt için ayrı işaretleme gerekmez, yalnız büyük bloğun başı ve sonu işaretlenir. Bu yüzden ek yük (overhead), yani işaretlemeye ayrılan bit sayısı daha azdır. Buna karşılık ortak saat işareti gerekir; uzun mesafeli bir iletişimden söz edildiği için bu görece pahalı bir yöntemdir. Slayt da senkron iletişimi şöyle özetler: gönderici ve alıcı senkronize olmalıdır (donanımda faz kilitlemeli döngülerle, PLL), veri bloğu gönderilebilir, asenkrona göre daha az ek yüklüdür, pahalıdır (ekrandan, 00:40:00).

Senkron iletişimde bağlantı, sistem 1 açısından tanımlanırsa, gönderme ucu, alma ucu, ortak toprak ve ortak saat işaretinden oluşur. Farklı çerçeve yapıları vardır:

- **BISYNC:** iki senkronizasyon karakterinden sonra veriler büyük bir paket halinde yerleştirilir, ardından hata kontrol baytları eklenir.
- **IBM SDLC (Serial Data Link):** başta ve sonda 8'er bitlik birer "parantez" (bayrak) vardır; aralarına adres ve kontrol bitleri, veri ve son olarak çerçeve kontrol (hata denetimi) bitleri yerleştirilir.

### 7.2 Asenkron iletişim

Asenkron iletişimde iki terminal arasında ortak saat işareti yoktur; iki taraf baştan veri gönderme frekansında kabaca anlaşır. Hoca şu örneği verir: birinci terminalin kristali 2 MHz'de çalışırken ikinci terminalin kristali üzerinde 2 MHz yazmasına rağmen 1,8 MHz'de çalışıyor olsun. Bu durumda bile, veri küçük paketlerle gönderildiği için, veri kaybı olmadan iletişim yapılabileceğini söyler.

Veriler küçük paketlerle gönderilir ve her paketin başına başlangıç, sonuna bitiş işaretleri eklenir. Paketler küçük olduğu ve her birinin sınırları işaretlendiği için ayrı bir senkronizasyon dizisine gerek yoktur. Taraflar veri genişliğinde de baştan anlaşır; örneğin 9600 baud'da 8 veri biti, 2 dur biti ve eşlik biti kullanılacaktır.

Hat üzerinde veri yokken varsayılan olarak **lojik 1**'dedir. İletişim başlatılacaksa gönderen taraf hattı **0'a çeker**; bu, karşı tarafta **start biti** olarak algılanır. Ardından bitler tek tek gönderilir; işlem bitince varsa eşlik biti, sonra dur bitleri eklenir. Gönderen ile alanın saat frekansları farklıysa küçük farklarla da olsa bitler yakalanabilir. Ama 8 bit yerine 20 ya da 50 bitlik paketler gönderilseydi, örneğin 2 MHz ile 1,8 MHz arasındaki kayma, 50 bitte bir sonraki ya da önceki bitin yanlışlıkla okunmasına yol açardı. Bu yüzden ortak saat olmayan asenkron iletişimde paketler küçük tutulur.

> **Ders sonrası not:** 2 MHz ile 1,8 MHz arasındaki fark %10'dur. Bu fark 10-11 bitlik bir çerçevede bile son bitlerde örnekleme noktasını bir bit süresine yakın kaydırır; pratikte UART'larda iki tarafın saat farkı büyük olasılıkla birkaç yüzdeyle sınırlı tutulmalıdır. Hocanın örneğinin asıl anlamı, kısa paketlerin saat farkına uzun paketlerden çok daha toleranslı olmasıdır.

Slayttaki şemalarda asenkron iletişimde her veri paketinin başı ve sonu ayrı ayrı işaretlenirken, senkron iletişimde paketler birleştirilip daha büyük bloklar halinde gönderilir.

### 7.3 Asenkron bağlantı ve sinyalleşme

Asenkron iletişim için toplam **3 tel** gerekir (ekrandan, 00:45:00). Uçlar sistem 1'e göre tanımlanırsa:

- **Transmit data:** sistem 1'in sistem 2'ye veri gönderdiği hat.
- **Receive data:** sistem 1'in sistem 2'den veri aldığı hat.
- **Signal common (ortak toprak):** iki sistem arasında ortak referans.

Ortak toprağın gerekçesi şudur: sistem 1'de toprak ve lojik 1 bir referansa göre, sistem 2'de başka bir referansa göre tanımlıysa ikisi arasında anlamlı bağlantı kurulamaz. Ortak toprak bağlandığında sistem 2'nin referansı sistem 1'inkine çekilir ve her iki tarafın "1" dediği değer anlamlı hale gelir.

Sinyalleşme şöyledir: hat boştayken lojik 1'dedir; veri gönderilmek istendiğinde verici hattı 0'a çeker. Hocanın anlattığı modelde alıcı, her bitin hatta kalma süresi boyunca hattı **iki kez örnekler**; iki örnekte de aynı değeri okumuşsa bit o değer olarak okunur. Alıcı önce start bitini bekler; iki örnekte de 0 görünce start bitinin geldiğini kabul eder. Verici ardından bitleri tek tek hatta koyar; her bitin hatta kalma süresi iki tarafın anlaştığı baud hızına uygundur. Slayttaki örnekte 0 ile birlikte 8 bitlik bir veri gönderilir. İki taraf 8 bitte anlaştığı için alıcı ardından dur bitlerini bekler. İki dur bitinde anlaşılmışsa birinci dur biti için hattı iki kez örnekler (hat 1'de mi? evet), sonraki çevrimde yine iki kez örnekler (yine 1). İki dur bitini de aldığını görünce çerçeveyi başarılı kabul eder. <!-- BELİRSİZ: 00:47:11'deki örnek bit dizisi altyazıda "1, 1, 0, 1, 1, 1, 1" ve "0" olarak geçiyor; slayt karesi bu ana denk gelmediği için tam sıra doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** Gerçek UART alıcıları genellikle hattı baud hızının 16 katı bir saatle izler ve her biti bit süresinin ortasına yakın bir noktada (çoğu zaman üç örnekle çoğunluk oylaması yaparak) örnekler. 8251'in mod yazmacındaki ×16 ve ×64 baud faktörleri bu amaçla kullanılır.

Ders kapsamında yalnız **asenkron** yapı kullanılacaktır. Asenkron iletişimde iki terminalin anlaşması gereken temel parametreler baud hızı, veri biti sayısı ve dur biti sayısıdır (hoca burada "senkron" dedi, bağlamdan asenkron kastedildiği anlaşılıyor).

## 8. Simplex, half duplex ve full duplex

Seri haberleşmede veri akış yönüne göre üç yapı vardır (ekrandan, 00:50:00):

- **Simplex:** hat yalnız tek yönlü veri aktarımına izin verir. Örneğin bilgisayardan yazıcıya veri gönderimi.
- **Duplex:** veri hem alma hem gönderme yönünde aktarılabilir. İki türü vardır:
  - **Half duplex:** çift yönlü aktarım desteklenir, ama kanal aynı anda tek yönde iletişime izin verir. Birinci sistem ikinci sisteme veri gönderiyorsa ikinci sistem, bire veri göndermek için bunun bitmesini beklemek zorundadır.
  - **Full duplex:** iki terminal eş zamanlı olarak birbirine veri gönderip alabilir.

Görsel olarak: alıcı ile verici arasında tek bir kanal varsa ve bu kanal tek yönlü iletişime adanmışsa yapı simplex'tir. Half duplex'te sistem iki yöne de imkân sahibidir, ama tek bir kanal vardır; o anda kanalı hangi taraf etkin ettiyse kanal o yönde çalışır, iletişim bitince diğer yön hattı kullanabilir. Full duplex'te birden fazla kanal vardır; biri ileri yönde, biri geri yönde çalışır.

**Soru (hocanın sınıfa sorusu):** Simplex aktarıma bir örnek verilebilir mi?

**Cevap:** Bir öğrenci "broadcasting" der. Hoca daha somut örnek olarak karasal TV ve radyo yayınlarını verir: radyo dinlenebilir, ama dinleyicinin sesi karşı tarafa ulaşmaz.

**Soru (hocanın sınıfa sorusu):** Half duplex haberleşmeye bir örnek?

**Cevap:** Telsiz. Telsizin tuşuna basınca hatta çıkma hakkı kazanılır ve söylenen karşı tarafa iletilir; bu sırada karşı tarafın söylediği hatta çıkamaz.

Full duplex yapıya örnek olarak cep telefonları ve sabit telefonlar verilir.

## 9. Baud hızı ve hesap örnekleri

Asenkron iletişimde iki terminalin anlaştığı iletişim frekansına **baud hızı** (baud rate) denir. Bu aynı zamanda sinyalin saniyedeki en fazla değişim sayısına karşılık gelir. Tersinden düşünülürse, sinyalin belirli bir değerinin (0 ya da 1) hatta ne kadar kalması gerektiği de buradan çıkar. Örneğin 1200 baud, saniyede 1200 bit aktarılabileceği ve her bitin hatta kalma süresinin $1/1200\text{ s} \approx 0{,}83$ ms olduğu anlamına gelir (altyazıda değer bozuk; değer python ile hesaplandı).

**Soru:** "Baud" neyin kısaltmasıdır?

**Cevap:** Bir kısaltma değil, doğrudan bir birim, bir kelime karşılığı olarak düşünülmelidir.

> **Ek bilgi (derste anlatılmadı):** Baud birimi büyük olasılıkla telgraf kodlamasıyla tanınan Fransız mühendis Émile Baudot'nun adından gelir.

### 9.1 Bit süresinden karakter hızına

Slayttaki ilk örnek (ekrandan, 01:10:00): bit süresi 3,33 ms, çerçeve 1 start, 8 veri, 2 stop bitinden oluşuyorsa bit hızı ve karakter hızı nedir?

Asenkron iletişimde yalnız bit süresiyle değil, paketin başlangıç ve bitiş ek yüküyle de ilgilenmek gerekir. Start biti başlangıç parantezi, dur bitleri bitiş parantezi gibi düşünülebilir. Periyottan frekansa geçilir:

- Bit hızı: $1 / 3{,}33\text{ ms} \approx 300$ bit/s.
- Çerçeve: $1 + 8 + 2 = 11$ bit. Bir karakterin gönderimi $11 \times 3{,}33\text{ ms} = 36{,}63$ ms sürer.
- Karakter hızı: $1 / 36{,}63\text{ ms} \approx 27{,}3$ karakter/s.

### 9.2 Dosya aktarım süresi

İkinci örnek (ekrandan, 01:10:00): modemler telefon şebekesi üzerinden genellikle 9600, 14400, 28800 ya da 56K bps hızında veri aktarır. 1 MB'lık bir dosya, çerçeve 1 start, 7 veri, 1 eşlik, 1 stop olacak biçimde gönderilirse aktarım ne kadar sürer?

- Çerçeve: $1 + 7 + 1 + 1 = 10$ bit; her karakter için 10 bit gerekir.
- Karakter sayısı: $1\text{ MB} = 2^{20} = 1\,048\,576$ (bir milyondan biraz fazla).
- Toplam bit: $1\,048\,576 \times 10 = 10\,485\,760$.
- 9600 bps: $10\,485\,760 / 9600 \approx 1092$ s, yani 18 dakika 12 saniye.
- 28800 bps: $10\,485\,760 / 28800 \approx 364$ s, yani 6 dakika 4 saniye.

Değerler python ile doğrulandı.

## 10. Hata tespiti: eşlik ve CRC

Seri haberleşmede önemli konulardan biri hatanın tespiti ve yerinin bulunmasıdır. Veri bit bit aktarıldığı ve her bit hatta belirli bir süre kaldığı için, bu süre içinde oluşabilecek bir elektromanyetik girişim gönderilen verinin karşı tarafa farklı bir değer olarak ulaşmasına yol açabilir. Hata olup olmadığını anlamak bir konu, hatanın nerede olduğunu anlamak ikinci bir konudur.

**Eşlik (parity) denetimi:** hata olup olmadığını anlamak için kullanılan yöntemlerden biridir.

- **Çift eşlik (even parity):** veri bitleri ve eşlik biti dahil 1 değerli bitlerin sayısının çift olması kuralıdır.
- **Tek eşlik (odd parity):** aynı sayının tek olması kuralıdır.

Tek sayıda bitte bozulma varsa eşlik denetimiyle anlaşılır; çift sayıda bitte bozulma varsa tespit edilemez. Yani eşlik denetimi hatayı yalnız belirli durumlarda yakalar.

**CRC:** özel CRC paketleri verinin ardına eklenerek gönderilir. Alıcı gelen paket bütünü için kendi CRC'sini hesaplar ve hocanın anlatımına göre hata olup olmadığını ve hatanın nerede olduğunu belirleyebilir.

> **Ders sonrası not:** Hoca CRC ile hatanın yerinin de bulunabileceğini söyledi; CRC büyük olasılıkla yalnız hata tespiti için kullanılır, hatanın yerini bulmak ve düzeltmek Hamming gibi hata düzelten kodların işidir.

Asenkron iletişim örneklerinde eşlik tarafı kullanılacaktır.

## 11. Yazılımsal seri gönderici ve alıcı

### 11.1 Gönderici akışı

Seri veri yazılımla gönderilir. Alıcının gönderme frekansını, veri genişliğini, başlangıç ve bitiş bit sayılarını bildiği varsayılır. Slayttaki akış şöyledir (ekrandan, 01:20:00):

```text
Start
  -> Karakter bit sayacını kur, start bitini gönder
  -> Bit süresi kadar bekle
  -> Karakteri akümülatöre al
  -> [döngü] Biti D0 üzerinden çıkar
       -> Bit süresi kadar bekle
       -> Sonraki biti D0'a döndür, bit sayacını azalt
       -> Son bit mi? Hayır ise döngü başına
  -> Gerekirse eşlik bitini ekle, dur bitlerini gönder
Return
```

Çıkış için 8255'in bir port ucu kullanılabilir; bu uç mod 0'da 0 ya da 1 yapılabilir. Start bitini göndermek hattı 0'a çekmek demektir; bu değer, iki terminalin anlaştığı baud hızına karşılık gelen bit süresi boyunca hatta kalır. Sonra gönderilecek karakter 8255'in ilgili portuna yazılır. Bu durumda D0 ucunda en düşük anlamlı bit bulunur, yani seri gönderilecek verinin en düşük anlamlı biti hatta konmuş olur. Asenkron aktarımda veriler zaten en düşük anlamlı bitten başlayarak gönderilmelidir. Bit süresi kadar beklenir, sonra porta yazılacak değer 1 bit sağa ötelenip yeniden yazılır; böylece 1 numaralı bit D0 ucuna (port A ile çalışılıyorsa PA0'a) gelir ve sayaç bir azaltılır. Bu işlem veri bit sayısı kadar tekrarlanır. Gerekiyorsa eşlik biti hesaplanıp hatta konur ve beklenir; son olarak dur biti sayısı kadar dur biti gönderilir.

### 11.2 Gönderici kodu

Ekrandaki kod şöyledir (ekrandan, 01:25:00). Slaytta DPORT bir port adresi sabitidir; hoca bunu port A'nın adresi, çıkış ucunu da PA0 olarak düşünmeyi söyler. Örnekte 8 veri biti, 1 start ve 1 stop biti vardır.

```asm
;Function: Serial data transmitter. DELAY
;          procedure determines data rate.
;Inputs:   Character to be transmitted assumed
;          passed in AL.
;Ouputs:   Serial data on bit 0 of DPORT.
;Destroys: AL,CX,flags.

        EXTRN   DELAY:NEAR
DPORT   EQU     00H

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

Fonksiyon, AL'deki veriyi asenkron çerçeve "parantezleriyle" birlikte yazılımla gönderir. Kodun akışı:

- Toplam 1 + 8 + 1 = 10 bit gönderileceği için CX = 10 yapılır.
- `CLC` (clear carry flag) carry bayrağını sıfırlar. AL ve carry birlikte 9 bit eder; 10. bit (dur biti) için özel bir işlem gerekecektir.
- `RCL AL,1` (rotate through carry left) AL'yi carry üzerinden bir kez sola döndürür: sıfırlanan carry AL'nin en düşük anlamlı bitine yerleşir, AL'nin en yüksek anlamlı biti carry'ye geçer.
- `OUT DPORT,AL` ile bu 0 değeri port A'nın 0 ucunda oluşur: start biti.
- Değerin hatta belirli süre kalması için hazır bir `DELAY` fonksiyonu çağrılır. "Hazır" ile önceden tanımlanmış, belirli süre boş döngü yapan bir fonksiyon kastedilir. 9600 baud'da veri hatta yaklaşık 104 µs kalmalıdır; demek ki `DELAY` çağrıldığı andan döndüğü ana kadar 104 µs süren bir boş döngüdür ($1/9600 \approx 104{,}2$ µs).
- `RCR AL,1` (rotate through carry right) AL'nin en düşük anlamlı bitindeki start bitini yeniden carry'ye alır ve AL'nin orijinal en yüksek anlamlı bitini yerine (D7) koyar. AL'nin en düşük anlamlı bitinde artık gönderilecek verinin en düşük anlamlı biti vardır.
- `STC` (set carry flag) carry'yi 1 yapar.
- `LOOP TRANS` ile sonraki bit için yeniden `OUT`'a gelinir. Bu kez AL'nin en düşük anlamlı biti, yani verinin D0'ı hatta konur, 104 µs beklenir ve AL bir bit sağa döndürülür.

Hoca önce `STC` satırını "carry sıfırlanıyor" diye okuyup AL'nin soldan sıfırlarla dolduğunu söyler, sonra bunun `STC` (set carry flag) olduğunu düzeltir. Her turda carry 1 yapılıp AL'ye soldan döndürüldüğü için AL soldan 1'lerle dolar. Start biti ve 8 veri biti gönderildikten sonra 10. bite gelindiğinde AL'nin en düşük anlamlı biti (ve diğer bütün bitleri) 1'dir; 10. bit kesinlikle 1 olur ve **dur biti** olarak gider. Özetle hat boştayken 1'dedir, start bitiyle 0'a çekilir, D0'dan D7'ye veri bitleri gönderilir ve 10. bit olan 1 dur bitini oluşturur.

Bit dizisi python benzetimiyle doğrulandı (ara adım eklendi): AL = 41H için hatta sırayla 0 (start), 1, 0, 0, 0, 0, 0, 1, 0 (D0-D7) ve 1 (stop) çıkar.

> **Ek bilgi (derste anlatılmadı):** Slayttaki çizimde DPORT'un 0 numaralı biti bir D tipi flip-flop üzerinden "Serial out" hattına, bir üç durumlu tampon üzerinden de "Serial in" hattına bağlanır. Yani aynı bit ucu hem gönderme hem alma için kullanılabilir.

### 11.3 Yazılımsal alıcı

Aynı yöntem seri veri almak için de kullanılabilir. Önce bir döngüde start bitinin gelip gelmediği, yani hattın 0'a düşüp düşmediği denetlenir. Donanımsal alımda olduğu gibi start biti iki kez örneklenerek doğrulanır. Start biti alındıysa sırasıyla verinin en küçük anlamlı bitinden (D0) başlayarak bitler gelir. Her bit okunur, belirli süre beklenir, bit carry üzerinden alınır ve AL yazmacı soldan sağa ötelenerek veri biriktirilir. Sonda dur biti ve varsa eşlik biti denetlenerek alım tamamlanır. Bu kısım için derste bir kod örneği verilmedi; gönderici koduna benzer biçimde yazılabileceği söylendi.

## 12. 8251 USART: uçlar ve bağlantı

Buraya kadar anlatılanlar seri haberleşmenin genel kavramlarıydı. Bundan sonra senkron ve asenkron seri veri alıp göndermeyi destekleyen programlanabilir yardımcı devre **8251** incelenir. 8255'ten önce kendi donanım ve yazılımıyla özel bir G/Ç cihazı yapılmış, sonra hazır 8255 incelenmişti. Burada da benzer bir akış vardır: önce 8255 ile yazılımsal bir seri port kurulmuş, şimdi bunun donanımsal karşılığı olan 8251 incelenecektir.

8251 bir **USART** entegresidir: universal synchronous/asynchronous receiver/transmitter, yani evrensel senkron/asenkron alıcı-verici (ekrandan, 01:30:00).

### 12.1 İşlemci tarafındaki uçlar

İç yapı ve 8086 bağlantısı slayttaki şemadan incelenir (ekrandan, 01:35:00):

- **CLK:** cihazın kendi çalışması için dışarıdan verilen saat işaretidir; içerideki denetim ve geçişleri de tetikler. Slaytta bu frekansın alıcı ya da vericinin veri bit hızının en az 30 katı olması gerektiği yazılıdır.
- **D7-D0:** cihaz 8 bitliktir ve 8 veri ucu doğrudan 8086'nın veri yoluna bağlanır. Cihaz ardışık çift adreslere yerleştirildiyse 8086'nın D0-D7 uçlarına, ardışık tek adreslere yerleştirildiyse D8-D15 uçlarına bağlanmalıdır.
- **RESET:** sistem resetlendiğinde cihazı da resetlemek için kullanılır.
- **RxRDY ve TxRDY:** 8086'da kesme isteği üreten kaynaklar olarak işlev görebilir. 8086 dış dünyaya veri göndermek istiyorsa 8251'in göndermeye hazır olduğunu denetlemelidir; bu TxRDY ucunun ya da TxRDY bitinin 1 olmasıyla anlaşılır. İstenirse bu donanımsal kesme isteği olarak kullanılır: art arda çok sayıda veri gönderilecekse her seferinde TxRDY 1'e çıktığında sonraki veri 8251'e yazılır; 8251 yazılan veriyi otomatik olarak bit bit gönderir. Dış dünyadan art arda veri okunacaksa, seri gelen bir paketin hazır olduğu RxRDY durum bitinin 1 olmasından anlaşılır. Bu iki işaret hem durum biti hem fiziksel uç olarak vardır; fiziksel uçlar kesme isteği için kullanılabilir ya da durum yazmacından okunup yoklama ile denetlenebilir.
- **$\overline{RD}$ ve $\overline{WR}$:** 8086 açısından tanımlıdır. 8086 8251'e bir değer yazmak istediğinde $\overline{WR}$'yi etkin yapar; okumak istediğinde $\overline{RD}$'yi.
- **$\overline{CS}$:** 8251'de bir chip select ucu vardır; cihazı etkin etmek için bu uca 0 verilmelidir.
- **C/$\overline{D}$ (control/data):** 8251'in **tek adres ucudur**. Bu uca 0 verilerek adreslenirse veri yazmaçlarına, 1 verilerek adreslenirse kontrol yazmaçlarına erişilir.

RxRDY ve TxRDY uçları bir kesme denetleyici yardımcı devrenin girişlerine bağlanır; o entegre de 8086'nın kesme istek ucuna bağlanır. 8086'da donanımsal dış kesmeler için tek bir giriş vardır: INTR ucu. Birden fazla kaynaktan gelen kesme isteğini değerlendirmek için ya öncelik kodlayıcıyla (kendi tasarladığımız özel bir cihazla) çözüm yapılır ya da hazır **8259 kesme denetleyicisi** kullanılır. Kaynaklar 8259'un girişlerine bağlanır, öncelikler ve sinyalleşmeler 8259'da programlanır ve 8259 8086'nın tek INTR ucuna bağlanır; seçimi 8259 yapar.

### 12.2 Dış dünya tarafındaki uçlar

- **Besleme uçları:** Vcc (+5 V) ve GND.
- **RxD ve TxD:** dış dünyadan seri gelen veriler RxD üzerinden alıcı tamponunda toplanır. Gönderilecek veriler önce gönderme tamponunda biriktirilir, sonra buradan bit bit gönderilir.
- **Modem kontrol uçları:** derste bunlarla ilgilenilmeyecektir.
- **RxC ve TxC:** alma ve gönderme için iki ayrı saat girişi. Böylece veri alma ve gönderme farklı frekanslarda yapılabilir; örneğin 9600'de gönderirken 28800'de alınabilir.

## 13. 8251 yazmaçları ve erişim akışı

### 13.1 Yazmaçlar

Şemada sol tarafta dışarıdan erişilebilen yazmaçlar, sağ tarafta dışarıdan erişilemeyen iki iç yazmaç (alıcı ve verici kaydırma yazmaçları) görülür. Dışarıdan erişilebilenler: mod yazmacı, senkronizasyon karakteri 1, senkronizasyon karakteri 2, kontrol yazmacı, data-in, data-out ve durum yazmacı; toplam 7 yazmaç.

Oysa tek bir adres ucu vardır. 8255'te iki adres ucuna karşılık $2^2 = 4$ yazmaç vardı ve cihaz G/Ç uzayında 4 bayt kaplıyordu. Aynı mantıkla 8251 tek adres ucu nedeniyle G/Ç uzayında **2 bayt** kaplar; yedi yazmaca erişim ise ardışık erişim sırasına bağlıdır. Cihaza ilk kontrol erişiminde mod yazmacına erişilir. Mod yazmacına senkron haberleşme yazıldıysa kontrol adresine sonraki erişimler senkronizasyon 1 ve senkronizasyon 2 karakterlerine gider. Asenkron haberleşme seçildiyse mod yazmacından sonraki kontrol erişimi kontrol yazmacına gider. Adres ucuna 0 verilerek yazma yapılırsa data-out tamponuna, okuma yapılırsa data-in tamponuna erişilir.

### 13.2 Erişim tablosu

Slayttaki tablo (ekrandan, 01:40:00):

| $\overline{CS}$ | C/$\overline{D}$ | $\overline{RD}$ | $\overline{WR}$ | Anlam |
|---|---|---|---|---|
| 1 | X | X | X | Veri yolu üç durumlu |
| 0 | X | 1 | 1 | Veri yolu üç durumlu |
| 0 | 1 | 0 | 1 | Durum → CPU |
| 0 | 1 | 1 | 0 | Mod, Kontrol, Sync ← CPU |
| 0 | 0 | 0 | 1 | Veri → CPU |
| 0 | 0 | 1 | 0 | Veri ← CPU |

- Cihaz seçilmemişse veri uçları hattan koparılmış gibi davranır.
- Cihaz seçilmiş ama okuma ya da yazma işareti gelmemişse veri uçları yine veri yolundan kopmuş gibidir.
- Kontrol adresinden (C/$\overline{D}$ = 1) okuma yapılırsa durum yazmacı işlemcinin veri uçlarına aktarılır.
- Kontrol adresine yazma yapılırsa değer belirli bir sırayla mod, kontrol ve senkronizasyon yazmaçlarına gider.
- Veri adresinden (C/$\overline{D}$ = 0) okuma data-in tamponunu okur; veri adresine yazma data-out tamponuna değer gönderir.

### 13.3 Kontrol yazma akışı

Karmaşık olan kısım kontrol yazmalarıdır; bunlar bir akış diyagramıyla izlenir:

```text
8251 resetlendi
  -> Kontrol adresine 1. yazma: MOD yazmacı
     -> Senkron mod mu?
        Evet -> sonraki yazma: SYNC 1
                -> iki sync karakteri seçildiyse sonraki yazma: SYNC 2
                -> sonraki yazma: KONTROL
        Hayır (asenkron) -> sonraki yazma: KONTROL
  -> Reset komutu değilse KONTROL yazmacına yazılmaya devam edilir
  -> Kontrol sözcüğü reset komutuysa akış başa döner
```

Resetten sonra adres ucuna 1 verilerek yapılan ilk yazma mod yazmacına gider. Mod yazmacında senkron mod seçildiyse bir ya da iki senkronizasyon karakteri yazma hakkı doğar: sonraki yazma senkronizasyon 1'e, iki karakter seçildiyse ikinci yazma senkronizasyon 2'ye gider. Asenkron haberleşme seçildiyse akışın diğer kolu izlenir ve gönderilen değer bir reset komutu değilse kontrol yazmacına yazılır.

En sık karşılaşılacak yapı şudur: cihaz resetlenir, ilk değer olarak mod yazmacına asenkron mod yazılır, sonra yine C/$\overline{D}$ = 1 ile reset olmayan bir komut gönderilir; bu kontrol yazmacına gider. Cihaz herhangi bir anda çalışırken reset kontrol komutu gönderilirse akış başa döner ve akışın neresinde olunduğu kesinleşir: cihaz sırasıyla mod ve kontrol akışını (senkron modda mod, senkronizasyon 1, senkronizasyon 2, kontrol akışını) izler.

> **Hocanın vurgusu:** Mod, senkronizasyon ve kontrol yazmaçlarına erişim bu akışa göre gerçekleşir; resetten sonraki ilk kontrol yazması her zaman mod yazmacına gider.

## 14. 8251 mod, kontrol ve durum yazmaçları

### 14.1 Mod yazmacı

Slayttaki asenkron mod biçimi (ekrandan, 01:45:00), D7'den D0'a: S2 S1 EP PEN L2 L1 B2 B1.

| Bitler | Alan | Değerler |
|---|---|---|
| B2 B1 (D1-D0) | Baud faktörü | 00: senkron mod, 01: ×1, 10: ×16, 11: ×64 |
| L2 L1 (D3-D2) | Veri biti sayısı | 00: 5, 01: 6, 10: 7, 11: 8 |
| PEN (D4) | Eşlik izni | 0: eşlik yok, 1: eşlik var |
| EP (D5) | Eşlik türü | 0: tek, 1: çift |
| S2 S1 (D7-D6) | Dur biti sayısı | 00: geçersiz, 01: 1, 10: 1,5, 11: 2 |

Mod yazmacına yazılan baytın son iki biti 00 ise 8251 **senkron moda** girer ve akış senkron koldan ilerler. Son iki bit 01, 10 ya da 11 ise cihaz **asenkron modda** çalışır ve bu bitler saat frekans faktörü olarak kullanılır: 01'de RxC ve TxC olduğu gibi baud hızı için kullanılır, 10'da 16'ya, 11'de 64'e bölünerek baud hızı üretilir.

Asenkron modda sonraki iki bit gönderilecek veri biti sayısını (5, 6, 7 ya da 8) belirler. Sonraki bit eşlik izni (PEN) bitidir: 0 ise eşlik biti kullanılmaz, 1 ise kullanılır. Eşlik seçildiyse EP biti tek mi çift mi olacağını belirler. Veri ve eşlik bitleri dahil 1'lerin toplam sayısının tek olması kuralı **tek eşlik** (odd parity), çift olması kuralı **çift eşlik** (even parity) olarak geçer. En yüksek anlamlı iki bit 1, 1,5 ya da 2 dur biti kullanılacağını söyler. Fiziksel olarak "bir buçuk bit" yoktur; bu, kapanış parantezinin hattın en az 1,5 bit süresi boyunca 1'de kalmasıyla değerlendirileceği anlamına gelir.

Slaytta senkron mod biçimi de görülür (D7'den D0'a SCS, ESD, EP, PEN, L2, L1, 0, 0), ama derste asenkron mod üzerinde durulur.

### 14.2 Kontrol yazmacı

Slayttaki biçim (ekrandan, 01:50:00), D7'den D0'a: EH IR RTS ER SBRK RxE DTR TxEN. Bütün durumlarda işlem, bit 1 yapıldığında gerçekleşir.

- **TxEN (D0):** gönderme izni. 8251'in dış dünyaya veri göndermesi isteniyorsa 1 yapılmalıdır.
- **DTR (D1):** modemle ilgilidir, kullanılmayacaktır.
- **RxE (D2):** alma izni. 8251'in dış dünyadan veri alıp biriktirmesi isteniyorsa 1 yapılmalıdır.
- **SBRK (D3):** seri haberleşmeyi kesmek için kullanılır; 1 yazılınca haberleşme kesintiye uğrar (slayta göre TxD 0'a zorlanarak break üretilir).
- **ER (D4):** hata bitlerini temizler. Daha önceki bir iletişim hatayla sonuçlandıysa, yeni bir iletişime başlamadan bu bit 1 yapılarak durum yazmacındaki hata bitleri sıfırlanmalıdır.
- **RTS (D5):** modemle ilgilidir, kullanılmayacaktır.
- **IR (D6):** iç reset (internal reset).
- **EH (D7):** hunt mod; derste 0 olarak kullanılacağı için ayrıntısına girilmez.

Buradan 8251'i resetlemenin iki yolu olduğu anlaşılır:

- Fiziksel olarak RESET ucuna 1 vermek.
- Yazılımla kontrol yazmacının D6 bitine 1 yazmak, yani kontrol adresine `40H` göndermek. Akış diyagramındaki reset işlemi buna karşılık gelir.

Çalışılacak mantık şöyledir: 8251'in mod yazmacına asenkron mod ve saat girişlerine bağlanan frekansla orantılı bir baud faktörü yazılır; ardından C/$\overline{D}$ = 1 ile yeniden adreslenerek kontrol sözcüğü yazılır. Reset yapıldığında bu yazma işlemleri baştan başlar.

### 14.3 Durum yazmacı

Durum yazmacına C/$\overline{D}$ = 1 iken yapılan okumalarla erişilir. Slayttaki biçim (ekrandan, 01:55:00), D7'den D0'a: DSR SYNDET FE OE PE TxE RxRDY TxRDY.

- **TxRDY (D0):** transmit ready. Hem durum biti hem fiziksel uç olarak vardır. Yoklamayla çalışılırken bu bitin 1 olup olmadığı denetlenir. 0 ise 8251 hâlâ önceki veriyi dış dünyaya aktarmakla meşguldür; üzerine yeni veri yazılırsa önceki veri ezilebilir. Bu yüzden TxRDY 1 olana kadar yoklama yapılır, 1 olunca yeni veri 8251'in data-out tamponuna yazılır.
- **RxRDY (D1):** dış dünyadan veri okunacaksa bu bitin 1'e çıkması gerekir. 1 ise bit bit gelen seri veri tamamen alınmış, paralelleştirilmiş ve data-in tamponuna konmuştur; işlemci veriyi data-in tamponundan okuyabilir. RxRDY 1 olana kadar 1 numaralı bit yoklanır.
- **TxE (D2):** slayta göre TxE ucuyla aynıdır (verici boş).
- **PE (D3), OE (D4), FE (D5):** hata bitleri.
- **SYNDET (D6), DSR (D7):** senkron mod ve modem işlemleriyle ilgilidir; konu kapsamı dışında bırakıldı.

> **Ders sonrası not:** Hoca TxRDY'yi anlatırken "kesme isteğiyle yürütmek istiyorsam durum bitini kontrol etmem lazım" dedi; bağlamdan durum bitinin denetlendiği yöntemin yoklama olduğu anlaşılıyor. Kesmeyle çalışmada fiziksel TxRDY ucu kesme isteği üretir.

Hata bitlerinin anlamı:

- **Eşlik hatası (PE):** gönderen taraf verinin sonuna hesapladığı eşlik bitini ekler. Alıcı veri kısmını alır, kendi eşliğini hesaplar ve aldığı eşlik bitiyle karşılaştırır; uyuşmazlık varsa eşlik hatası oluşur.
- **Taşma hatası (OE):** hoca bunu, veri gönderimi bitmeden üzerine yeni veri yazılması olarak anlatır.
- **Çerçeve hatası (FE):** örneğin start ve stop bitleri uygun biçimde beklenirken, iki dur biti beklenirken bir bitten sonra dur biti bitmişse çerçeve hatası biti 1 olur.

> **Ders sonrası not:** Hoca taşma hatasını gönderim tarafından anlattı; OE büyük olasılıkla alıcı tarafın hatasıdır: işlemci data-in tamponundaki karakteri okumadan yeni bir karakter gelir ve öncekinin üzerine yazılır.

Önceki veri alışverişlerinden kalan hatalar varsa, kontrol yazmacındaki ER biti 1 yapılarak hata bitleri topluca sıfırlanabilir.

Böylece 8251'in uç tanımları, yazmaç tanımları, durum bitleri ve erişim kuralları tamamlanmış olur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): 8255 mod 1'de giriş yönlü ayarlanmış grup A ve grup B için, durum sözcüğünden $\text{INTR}_A$ ve $\text{INTR}_B$ bitlerini ayırmak için hangi maskeler kullanılır?

> **Çözüm:** Giriş yönlü durum sözcüğünde $\text{INTR}_A$ D3'te, $\text{INTR}_B$ D0'dadır. $\text{INTR}_A$ için diğer bitler 0 ile maskelenir: $0000\,1000_2 = 08\text{H}$. $\text{INTR}_B$ için $0000\,0001_2 = 01\text{H}$. Durum sözcüğü port C adresinden okunur ve `AND AL,08H` ya da `AND AL,01H` uygulanır.

**Soru 2** (ekrandan, 00:30:00): 200H'den itibaren ardışık çift adreslere yerleşmiş 8255 için kontrol adresine sırasıyla `09H`, `05H` ve `0BCH` yazılıyor. Bu değerler ne yapar?

> **Çözüm (derste kısmen verildi, bit çözümlemesi python ile kesinleştirildi):** Kontrol adresi 206H'dir. `09H` = $0000\,1001_2$: D7 = 0 olduğu için BSR komutudur; D3-D1 = 100 → PC4, D0 = 1 → set. Giriş yönlü grup A'da PC4 = $\text{INTE}_A$. `05H` = $0000\,0101_2$: D3-D1 = 010 → PC2, set → $\text{INTE}_B$. `0BCH` = $1011\,1100_2$: D7 = 1 mod ayarı; D6-D5 = 01 grup A mod 1; D4 = 1 port A giriş; D3 = 1 PC üst yarısı giriş; D2 = 1 grup B mod 1; D1 = 0 port B çıkış; D0 = 0 PC alt yarısı çıkış. Yani grup A mod 1 giriş, grup B mod 1 çıkış.

**Soru 3** (derste sözlü, 00:24:32): Mod 1 girişe bağlanan tuş tarama entegresinde strobe işaretini DA mı yoksa $\overline{OE}$ mi sağlar?

> **Çözüm:** DA. DA dış dünyadan 8255'e gelen sinyaldir ve 8255 buna cevap verir; bu yüzden $\overline{STB}$ işlevini görür. 8255'in IBF cevabı ise $\overline{OE}$'yi sürer.

**Soru 4** (derste sözlü, 00:51:37 ve 00:52:55): Simplex ve half duplex iletişime birer örnek veriniz.

> **Çözüm:** Simplex: karasal TV ve radyo yayınları (dinleyicinin sesi yayıncıya ulaşmaz); bilgisayardan yazıcıya veri gönderimi de slayttaki örnektir. Half duplex: telsiz (tuşa basan hatta çıkar, bu sırada karşı taraf konuşamaz). Full duplex örneği: telefon.

**Soru 5** (ekrandan, 01:10:00): Bit süresi 3,33 ms ve çerçeve 1 start, 8 veri, 2 stop biti ise bit hızı ve karakter hızı nedir?

> **Çözüm:** Bit hızı $= 1/3{,}33\text{ ms} \approx 300$ bit/s. Karakter süresi $= 11 \times 3{,}33 = 36{,}63$ ms. Karakter hızı $= 1/36{,}63\text{ ms} \approx 27{,}3$ karakter/s.

**Soru 6** (ekrandan, 01:10:00): 1 MB'lık bir dosya modemle 1 start, 7 veri, 1 eşlik, 1 stop bitlik çerçevelerle gönderilecektir. 9600 bps ve 28800 bps için aktarım süresi nedir?

> **Çözüm:** $1048576 \times 10 = 10\,485\,760$ bit. 9600 bps: $10\,485\,760/9600 \approx 1092$ s = 18 dk 12 s. 28800 bps: $\approx 364$ s = 6 dk 4 s.

**Soru 7** (ekrandan, 01:25:00): Yazılımsal seri gönderici koduna AL = 41H verilirse hatta hangi bit dizisi çıkar? `STC` yerine `CLC` olsaydı ne değişirdi?

> **Çözüm (derste verilmedi):** Python benzetimiyle: 0 (start), 1, 0, 0, 0, 0, 0, 1, 0 (D0-D7, LSB önce) ve 1 (stop). `STC` yerine `CLC` olsaydı AL soldan 0'larla dolardı ve 10. bit 0 çıkardı; dur biti 1 olmadığı için alıcıda çerçeve hatası oluşurdu. Hocanın ilk okumasında yaptığı ve sonra düzelttiği nokta da budur.

**Soru 8** (derste sözlü, 01:24:26): 9600 baud'da `DELAY` fonksiyonu ne kadar sürmelidir?

> **Çözüm:** Bit süresi kadar: $1/9600 \approx 104{,}2$ µs, yani yaklaşık 104 µs.

## Dersin Toparlaması

Derste önce 8255'in mod 1'deki kesme izin bitleri ve durum sözcüğü tekrar edildi, eksik kalan mod 2 tamamlandı ve önceki haftanın tuş takımı-gösterge örneği adres yerleşimi ve koduyla yeniden ele alındı. Kesme izinlerinin BSR komutlarıyla açılması, durum sözcüğünün port C adresinden okunup maskelenmesi ve tam adres çözümleme gerekliliği öne çıkan noktalardı.

İkinci bölümde seri haberleşmeye geçildi: seri ve paralel iletişimin karşılaştırması, senkron ve asenkron iletişim, simplex/duplex yapıları, baud hızı ve çerçeve hesapları, eşlik ve CRC ile hata tespiti anlatıldı. 8255'in tek bir port ucuyla, RCL/RCR/STC komutlarıyla start, veri ve dur bitlerini üreten yazılımsal bir seri gönderici incelendi. Ardından bunun donanımsal karşılığı olan 8251 USART'ın uçları, tek adres ucuyla yedi yazmaca sıralı erişim akışı ve mod, kontrol ve durum yazmaçlarının bitleri anlatıldı. Sonraki derste 8251 örnekleri yapılacak ve 8254 entegresine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
