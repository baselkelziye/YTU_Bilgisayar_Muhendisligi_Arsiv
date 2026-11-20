# Ders 6 Çalışma Özeti

## Genel Konular

- Adres çözümleme devresinin görevi
  - Bütün hafıza ve çevre birimleri aynı adres, veri ve kontrol yollarını paylaşır. Adres ve kontrol yolunda sorun yoktur, ama iki cihaz aynı anda veri yoluna değer çıkarırsa çakışma olur.
  - Adres çözümleme devresi (kara kutu olarak) girişte adres uçlarını ve kontrol işaretlerini ($\overline{RD}$, $\overline{WR}$, M/$\overline{IO}$ gibi) alır; sistemdeki cihaz sayısı kadar çıkış üretir. Verilen adrese göre ya hiçbir cihazı ya da yalnız bir cihazı seçer. Seçilmeyen cihazların veri uçları yüksek empedansta kalır, yani hattan kopmuş gibi olur.
  - Cihazlar kapasiteleriyle orantılı, hizalı adreslere yerleştirilir. 1 MB'lık tek bir hafıza 0 adresinden başlar; 512 KB'lık bir cihaz 0 ya da 80000H adresine, 256 KB'lık bir cihaz dört noktadan birine (0, 40000H, 80000H, C0000H) konabilir.
  - Kapasitesi $2^{i+1}$ göz olan bir cihazda A0–Ai uçları cihazın kendi adres uçlarına gider; kalan uçlar çözümleme devresine girer (ekrandan, 00:05:00):
    - Hafıza: A19–A(i+1)
    - Değişken adresli G/Ç (DX ile): A15–A(i+1)
    - Sabit adresli G/Ç (8 bitlik port): A7–A(i+1)
- Basit çıkış birimi: 0F000H adresinde 8 LED (ekrandan, 00:10:00)
  - Donanım: 74245 çift yönlü alıcı-verici ve 8 LED. DIR ucu 5 V'a bağlıdır, yani A tarafı B tarafına kopyalanır (çıkış yönü). $\overline{E}$ ucu adres çözümleme devresinin çıkışına bağlıdır (ekrandan, 00:15:00).
  - Çözümleme koşulu: A15–A12 = 1, A11–A0 = 0, M/$\overline{IO}$ = 0, $\overline{WR}$ = 0. Devre, A15–A12 doğrudan, A11–A0 terslenerek ve $\overline{WR}$+M/$\overline{IO}$ (OR) terslenerek girdiği bir NAND kapısıdır; çıkışı yalnız bu koşulda 0 olur (ekrandan, 00:20:00).
  - Yanık-sönük deseni için B uçlarında 0,1,0,1,... gerekir. D7…D0 = 0101 0101B = 55H (ekrandan, 00:15:00).
  - Kod (ekrandan, 00:15:00): adres 8 bite sığmadığı için DX kullanılır.

    ```asm
    mov al, 55h
    mov dx, 0F000h
    out dx, al
    ```

- Basit giriş birimi: 0F000H adresinde 8 düğme
  - 74245'in DIR ucu toprağa bağlıdır, B tarafı A tarafına (dış dünyadan işlemciye) kopyalanır. Düğmeler pull-up dirençlerle 5 V'a bağlıdır: basılı değilken lojik 1, basılınca lojik 0 okunur (ekrandan, 00:30:00).
  - Çözümleme koşulu: A15–A12 = 1, A11–A0 = 0, M/$\overline{IO}$ = 0, $\overline{RD}$ = 0. Çıkış biriminden tek fark $\overline{WR}$ yerine $\overline{RD}$ kullanılmasıdır.
  - Hiçbir düğmeye basılmazsa okunan değer FFH'dir. Basılana kadar bekleyen kod (ekrandan, 00:30:00):

    ```asm
        mov dx, 0F000h
    L1: in  al, dx
        cmp al, 0FFh
        je  L1
    ```

- Basit G/Ç birimleri üzerine üç soru (ekrandan, 00:40:00)
  - Aynı adreste (0F000H) giriş ve çıkış birimi birlikte bulunabilir; biri yalnız `OUT` ($\overline{WR}$ = 0), diğeri yalnız `IN` ($\overline{RD}$ = 0) ile seçildiği için karışmazlar.
  - Birimi 0F001H (tek adres) adresine taşımak için: veri uçları D8–D15'e bağlanır ve çözümlemede A0 = 1 aranır (A0'daki tersleyici kaldırılır) ya da A0 yerine $\overline{BHE}$ = 0 kullanılır.
  - 0F000H adresinden 16 bitlik çıkış birimi: iki 74245 kullanılır; biri D0–D7'ye, diğeri D8–D15'e bağlanır. A0 çözümlemeden çıkarılır ve aynı seçim çıkışı iki cihaza da verilir (ya da çift adresteki için A0, tek adresteki için $\overline{BHE}$ kullanılır). Aktarım AL yerine AX ile yapılır.
- Programlanabilir G/Ç cihazları ve 8255 PPI
  - Programlanabilir cihazın içinde ayar yazmaçları vardır; yazılımla bu yazmaçlara değer gönderilerek cihazın işlevi değiştirilir.
  - 8255 (Programmable Peripheral Interface): TTL uyumlu, 8 bitlik, üç adet 8 bitlik genel amaçlı portu (A, B, C) olan paralel arayüz. Uçları: D0–D7, A0–A1, $\overline{CS}$, $\overline{RD}$, $\overline{WR}$, RESET, VCC, GND, PA0–PA7, PB0–PB7, PC0–PC7 (ekrandan, 00:55:00).
  - Portların gerekliliği: zamanlama uyumsuzluğu, elektriksel seviye uyumsuzluğu (TTL dışı seviyeler uçları yakabilir) ve yavaş değişen dış işaretlerin işlemciyi meşgul etmesi.
  - İki adres ucu → $2^2 = 4$ adet 8 bitlik yazmaç → G/Ç uzayında 4 bayt. Derste tasarlanan basit çıkış biriminin adres ucu yoktur ($\overline{E}$ bir chip select ucudur), bu yüzden 1 bayt yer kaplar.
  - Bağlantılar: $\overline{CS}$ adres çözümleme devresinin bir çıkışına; işlemcinin $\overline{RD}$ ucu 8255'in $\overline{RD}$ ucuna, $\overline{WR}$ ucu $\overline{WR}$ ucuna (çapraz değil); RESET toprağa.
  - Yazmaç seçimi (A1 A0): 00 Port A, 01 Port B, 10 Port C, 11 kontrol kelimesi. 11 adresine yazma kontrol kelimesini (ayar yazmacını) yazar.
  - Mod 0 (Basic I/O): Port A ve Port B 8 bit giriş ya da çıkış; Port C'nin alt ve üst 4 bitleri ayrı ayrı giriş ya da çıkış. Mod 1 ve Mod 2 el sıkışmalı modlardır: Grup A = Port A (veri) + PC üst 4 bit (el sıkışma); Grup B = Port B + PC alt 4 bit.
- 16 bitlik veri yolunda 8 bitlik çevre birimi
  - $\overline{BHE}$/A0 tablosu (ekrandan, 01:15:00): 0/0 ve 1/1 anlamlı değil (8 bitlik tek cihaz için), 0/1 tek adresteki bayt D8–D15, 1/0 çift adresteki bayt D0–D7.
  - Üç yaklaşım: ardışık çift adresler, ardışık tek adresler, ardışık adresler (veri yolunu D0–D7 ile D8–D15 arasında seçen karmaşık devre gerekir; derste ayrıntısına girilmedi).
- Örnek: F8H'den itibaren ardışık çift adreslerde 8255 (ekrandan, 01:20:00)
  - Adresler F8H, FAH, FCH, FEH. Sabit bitler A7–A3 = 11111 ve A0 = 0; ayrıca M/$\overline{IO}$ = 0. A2 ve A1 değişir, 8255'in yazmaç seçme uçlarına gider.
  - İşlemcinin A2'si 8255'in A1'ine, A1'i A0'ına bağlanırsa: F8H Port A, FAH Port B, FCH Port C, FEH kontrol (ekrandan, 01:25:00).
  - Bağlantılar çaprazlanırsa (A2 → 8255 A0, A1 → 8255 A1) Port A ve kontrol yerinde kalır, Port B ile Port C yer değiştirir (FAH Port C, FCH Port B).
  - Adres yalnız 8 bite sığdığı için A0–A7 çözümlemede yeterlidir, A8–A15 sıfır kabul edilir.
- 3×8 kod çözücü (74LS138) (ekrandan, 01:30:00)
  - Girişler C (ağırlık $2^2$), B ($2^1$), A ($2^0$); etkinleştirme uçları G1 (aktif 1), $\overline{G2A}$ ve $\overline{G2B}$ (aktif 0); çıkışlar Y0–Y7 aktif 0.
  - G1 = 1, G2A = 0, G2B = 0 iken CBA'nın ondalık değeri hangi çıkışı gösteriyorsa o çıkış 0, diğerleri 1 olur. Etkinleştirme koşulu sağlanmazsa bütün çıkışlar 1'dir.
  - Çıkışların aktif 0 olması, çevre birimlerinin $\overline{CS}$ uçları da aktif 0 olduğu için avantajlıdır; entegre tek başına adres çözümleme devresi olarak kullanılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ardışık çift adres hesabında onaltılık toplama hatası
  - A8H + 2 = AAH'dır, B0H değildir (ekrandan, 01:20:00). Cihazlar hizalı yerleştirildiği için adres dizisinde böyle bir sıçrama hatayı ele verir.
- Çözümleme devresi yalnız tek bir adres ve tek bir yön için seçim yapar
  - Adres bitlerinden biri, M/$\overline{IO}$ ya da $\overline{RD}$/$\overline{WR}$ farklıysa cihaz seçilmez. Örneğin aynı devreye 7000H (A15 = 0) ya da F001H (A0 = 1) verilirse çıkış 1 olur.
- 74245'in A/B uçları işlemcinin adres ve veri uçlarıyla karıştırılmamalı
  - A ve B yalnız entegrenin iç tarafına ait adlardır; $\overline{E}$ ucuna AX yazmacı değil, çözümleme devresinin çıkışı bağlanır.
- Uçlar işlemciye göre adlandırılır
  - 8255'in $\overline{RD}$ ucuna işlemcinin $\overline{RD}$ ucu bağlanır; çapraz bağlantı gerekmez ("tuzak soru").
- $\overline{CS}$ ucu doğrudan 0'a bağlanmaz
  - Bağlanırsa 8255, `MOV AX, BX` gibi ilgisiz komutlarda da etkin olur ve veri yolunda rastgele değerler görülür. $\overline{CS}$, adres çözümleme devresinin çıkışından gelmelidir.
- Bir işlemde $\overline{RD}$ ve $\overline{WR}$ aynı anda 0 olamaz; ikisinin birlikte 1 olduğu aralıklar olabilir.

## Kısa Tekrar Notları

- Çözümleme devresi: adres + kontrol işaretleri girer, cihaz başına bir $\overline{CS}$ çıkar, en fazla biri 0 olur.
- Hafıza A19–A(i+1), değişken G/Ç A15–A(i+1), sabit G/Ç A7–A(i+1) çözümlemeye gider.
- G/Ç adresi 8 bite sığmıyorsa `MOV DX, adres` ve `IN/OUT` ile DX kullanılır.
- 74245: $\overline{E}$ = 0 iken DIR = 1 → A'dan B'ye, DIR = 0 → B'den A'ya; $\overline{E}$ = 1 → yollar ayrık.
- Çıkış birimi: DIR = 5 V, $\overline{WR}$ ile çözümleme; giriş birimi: DIR = 0, $\overline{RD}$ ile çözümleme.
- Pull-up düğme: basılı değil 1, basılı 0; hiçbir düğme basılı değilken FFH.
- Aynı adreste bir giriş ve bir çıkış birimi birlikte bulunabilir.
- Tek adres → D8–D15 + (A0 = 1 ya da $\overline{BHE}$ = 0); 16 bitlik birim → iki 74245, A0 çözümlemeden çıkar.
- 8255: 3 port, 8 bit veri, A1A0 ile 4 yazmaç (PA, PB, PC, kontrol), G/Ç uzayında 4 bayt.
- Mod 0 temel G/Ç; Mod 1 ve Mod 2 el sıkışmalı (Grup A: PA + PC üst; Grup B: PB + PC alt).
- F8H çift adres örneği: F8H/FAH/FCH/FEH → PA/PB/PC/kontrol; işlemci A2 → 8255 A1, A1 → 8255 A0.
- 74LS138: G1 = 1, $\overline{G2A}$ = $\overline{G2B}$ = 0 iken $Y_{CBA}$ = 0.

## Detaylı Açıklamalar

- Adres çözümleme ve hizalı yerleştirme
  - Sistemdeki her cihaza kapasitesi kadar bir adres aralığı ayrılır ve bu aralık kapasiteyle hizalı başlar. Böylece cihazın kendi adres uçları düşük anlamlı bitleri, çözümleme devresi ise yüksek anlamlı sabit bitleri izler. Hoca, bilgisayarlarda G/Ç cihazlarının da belirli adres aralıklarına yerleştirildiğini ve bunların görülebildiğini hatırlattı.
  - Hafıza cihazı için kalan uçlar A19'a, değişken adresli G/Ç cihazı için A15'e, sabit adresli G/Ç cihazı için A7'ye kadar çözümlemeye girer.
- Basit çıkış birimi tasarımı
  - Soru: 8 LED ile 0F000H adresine yerleştirilmiş bir çıkış birimi tasarlayın ve LED'lerde yanık-sönük deseni oluşturun. Hoca önce 20 bitlik dedi, sonra G/Ç cihazı olduğu için adresin 16 bit olduğunu düzeltti.
  - Slaytta 8086'nın D7 ucu 74245'in A0'ına, D0 ucu A7'sine bağlıdır; B0'dan B7'ye LED'ler sırasıyla 0,1,0,1,0,1,0,1 değerini alır. Buna karşılık gelen D7…D0 değeri 0101 0101B = 55H'dir (ekrandan, 00:15:00).
  - Çözümleme: F000H = 1111 0000 0000 0000B (ekrandan, 00:20:00). NAND kapısının girişlerinden A15–A12 doğrudan, A11–A0 tersleyiciyle, $\overline{WR}$ ile M/$\overline{IO}$'nun OR'u da tersleyiciyle girer. Bu devre yalnız istenen koşulda 0 üretir. Hoca iki deneme yaptı (ekrandan, 00:25:00):
    - 7000H: A15 = 0 → VE kapısının çıkışı 0 → NAND çıkışı 1 → cihaz seçilmez.
    - F001H: A0 = 1 → tersleyiciden sonra 0 → çıkış 1 → cihaz seçilmez.
    - $\overline{WR}$ ve M/$\overline{IO}$ ikisi de 0 olunca OR çıkışı 0'dır; ikisinden biri 1 ise OR 1 olur ve cihaz seçilmez. Aranan "ikisi 0 iken 0" işlevi OR kapısıdır (slayttaki "+" işareti).
  - `OUT DX, AL` çalışınca M/$\overline{IO}$ = 0, $\overline{WR}$ = 0 olur, adres uçlarında F000H vardır; NAND çıkışı 0 olur, 74245 seçilir ve 55H LED'lere aktarılır.
  - `IN AL, DX` ile aynı adres verilirse $\overline{RD}$ = 0, $\overline{WR}$ = 1 olur ve çıkış birimi seçilmez.
- Basit giriş birimi tasarımı
  - Soru: 8 düğme ile 0F000H adresinde bir giriş birimi tasarlayın ve basılan tuş değerini okuyun.
  - Pull-up dirençli düğmede basılı değilken B ucu direnç üzerinden 5 V görür (lojik 1); basılınca uç doğrudan toprağa bağlanır (lojik 0), gerilim direnç üzerinde düşer ve kısa devre oluşmaz.
  - Hoca tahtaya önce A11 = 1 yazdı, bir öğrencinin uyarısıyla A11 = 0 olarak düzeltti (ekrandan, 00:35:00; derste düzeltme 00:37:53). Doğru koşul A15–A12 = 1, A11–A0 = 0'dır.
  - Bekleme döngüsünde `CMP` iki işleneni çıkarır, yalnız bayrakları değiştirir; AL = FFH ise `JE L1` ile tekrar okunur. Bir tuşa basıldıktan sonra AL'nin bitleri tek tek denetlenerek hangi tuşlara basıldığı bulunabilir.
  - Ders sonrası not: Hoca 00:34:45'te adresin "16 bite sığdığı için" DX ile verildiğini söyledi; kastedilen, adresin 8 bite sığmadığı için DX'in kullanıldığıdır (hoca 00:35:32'de böyle söyledi).
  - Ders sonrası not: Hoca 00:36:29'da AL'nin 1, 2, 4, 8, 16, 32, 64 gibi değerlerle karşılaştırılabileceğini söyledi. Bu dizide 128 (D7) de vardır. Ayrıca bu devrede basılı tuş 0 okunduğu için tek bir tuşa basıldığında AL, FFH'nin ilgili biti 0 yapılmış hâlidir (örneğin D0 tuşu için FEH). Bu yüzden karşılaştırma doğrudan bu değerlerle değil, bit bit maskeleme ile yapılmalıdır.
- Aynı adreste giriş ve çıkış, tek adres ve 16 bitlik birim
  - Giriş ve çıkış birimleri ayrı ayrı $\overline{RD}$ ve $\overline{WR}$ ile çözümlendiği için veri uçları aynı hatlara bağlanarak ikisi aynı anda sistemde bulunabilir.
  - Çift adreste 8 bitlik işlemde A0 = 0 (düşük bayt etkin), $\overline{BHE}$ = 1'dir. Tek adreste 8 bitlik işlemde işlemci veriyi D8–D15'te bekler; bu yüzden F001H için veri bağlantısı D8–D15'e taşınır ve çözümleme A0 = 1 ya da $\overline{BHE}$ = 0 ile yapılır.
  - 16 bitlik işlemde çift adresten okuma/yazma sırasında A0 = 0 ve $\overline{BHE}$ = 0 olur; iki 74245'in birlikte seçilmesi için A0 çözümlemeden çıkarılır.
  - Ders sonrası not: Hoca 16 bitlik çıkış birimi için "okumayı AL'den değil AX'den yapacağız" dedi; çıkış birimi olduğu için kastedilen yazmanın `OUT DX, AX` ile yapılmasıdır.
- 8255'in yapısı ve bağlanması
  - 8255'in fiziksel uç numaraları slaytta verilmiştir (ekrandan, 00:55:00): örneğin D0–D7 uçları 34–27, A0 9, A1 8, RESET 35, $\overline{RD}$ 5, $\overline{WR}$ 36, $\overline{CS}$ 6, VCC 26, GND 7.
  - Okuma işleminde ($\overline{RD}$ = 0, $\overline{CS}$ = 0) A1A0 = 00 ise Port A uçlarındaki değer veri uçlarına çıkar; 01 Port B, 10 Port C için aynıdır. 11 adresinden okuma hoca tarafından durum bilgisi okuma olarak anıldı, ayrıntısı sonraya bırakıldı.
  - Yazma işleminde ($\overline{WR}$ = 0) 00/01/10 adreslerinde veri yolundaki değer ilgili portun uçlarına çıkar; 11 adresine yazılan değer kontrol kelimesidir ve cihazın programlanabilir olmasının anlamı budur.
  - Hoca analog-sayısal ve sayısal-analog çeviricilerin de adres ucu olmadığını, onların da G/Ç uzayında 1 bayt kaplayacağını söyledi.
- F8H örneğinde adres bitleri
  - F8H = 1111 1000B, FAH = 1111 1010B, FCH = 1111 1100B, FEH = 1111 1110B (ekrandan, 01:20:00). A7–A3 ve A0 dört adreste de aynıdır, A2A1 ise 00, 01, 10, 11 değerlerini alır.
  - Ders sonrası not: Hoca 01:19:48'de önce "A7'nin 0 olması gerekiyor" dedi, hemen ardından (01:20:13) A7 = 1 olarak saydı. Slayt tablosu da A7 = 1 gösterir; doğrusu A7 = 1'dir.
  - Ders sonrası not: Hoca 00:03:44'te "356 kilobaytlık" bir cihazın dört noktaya yerleştirilebileceğini söyledi; dört hizalı nokta 256 KB için geçerlidir (1 MB / 256 KB = 4).
- 74LS138 3×8 kod çözücü
  - Hoca entegreyi "7438" diye andı, 3×8 kod çözücü olduğunu söyledi. <!-- BELİRSİZ: Altyazıda "7438"; derste anlatılan 3×8, G1/G2A/G2B uçlu entegre büyük olasılıkla 74LS138. -->
  - Doğruluk tablosu (ekrandan, 01:30:00): CBA = 000 → Y0 = 0, diğerleri 1; CBA = 001 → Y1 = 0, diğerleri 1; …; CBA = 111 → Y7 = 0.
  - Laboratuvarda adres çözümleme için bu kod çözücü kullanılacak; giriş uçlarına hangi adres bitlerinin bağlanacağı benzetimden önce elle (breadboard'da tel çeker gibi) belirlenecek.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
