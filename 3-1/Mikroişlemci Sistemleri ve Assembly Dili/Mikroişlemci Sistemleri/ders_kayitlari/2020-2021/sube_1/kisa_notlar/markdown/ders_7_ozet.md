# Ders 7 Çalışma Özeti

## Genel Konular

- Önceki konuların kısa tekrarı
  - Basit (özel tasarım) giriş ve çıkış birimleri üç bölümden oluşur: adres çözümleme devresi, arayüz (doğrudan veri yoluna bağlanan eleman, örneğin 74245) ve çevre birimi (LED, düğme gibi G/Ç cihazı).
  - Aynı adresteki LED örneği yalnız yazma ($\overline{WR}$), düğme örneği yalnız okuma ($\overline{RD}$) işleminde etkin olacak biçimde çözümlenmişti.
  - Basit G/Ç birimi tek bir iş yapar. Programlanabilir çevre birimi ise genel bir port yapısına sahiptir ve yazılımla farklı işlere ayarlanır: 8255 farklı genişlikte paralel G/Ç, 8254 farklı dalga biçimlerinde zamanlama sağlar.
- 8255'in temel yapısı (tekrar)
  - 8 bitlik veri yolu, üç port (PA, PB, PC) ve iki adres ucu (A0, A1) vardır. İki adres ucu G/Ç uzayında $2^2 = 4$ baytlık yer demektir: port A, port B, port C ve kontrol yazmacı.
  - Mod 0'da porta yazılan değer uçlarda elektriksel sinyal olarak görünür. Porttan okuma, uçlardaki o anki lojik değerlerin 8 bitlik bir örneğini işlemciye aktarır.
  - $\overline{CS}$ cihazı etkinleştirir ve adres çözümleme devresinden sürülür; $\overline{CS}$ = 1 iken veri uçları veri yolundan kopmuş gibi davranır. $\overline{RD}$ ve $\overline{WR}$ doğrudan 8086'nın aynı adlı uçlarına bağlanır (ekrandan, 00:10:00).
- 16 bitlik veri yolunda bellek ve G/Ç düzeni
  - 8086 tek bir okuma/yazma çevriminde çift adresten 8 bit, tek adresten 8 bit ve çift adresten 16 bit işlem yapabilir. Bu yüzden 1 MB bellek $1M \times 8$ değil $512K \times 16$, 64 KB G/Ç uzayı da $32K \times 16$ olarak görülür (ekrandan, 00:15:00).
  - Uzay, 8 bit genişliğinde çift ve tek iki bloğa ayrılır. Çift blok A0 = 0 ile, tek blok $\overline{BHE}$ = 0 ile seçilir. Çift adresten 16 bit işlemde ikisi birlikte etkin olur; düşük bayt D0-D7, yüksek bayt D8-D15 üzerinden gelir.
  - 8 bitlik bir cihaz ya ardışık çift adreslere (veri D0-D7) ya da ardışık tek adreslere (veri D8-D15) yerleştirilir.
- Ardışık çift adres örneği: F8H'den itibaren (ekrandan, 00:20:00 ve 00:25:00)
  - Adresler F8H, FAH, FCH, FEH'dir. Ortak (sabit) bitler: A7-A3 = 1, A0 = 0; ayrıca G/Ç işlemi için M/$\overline{IO}$ = 0.
  - 3'e 8 kod çözücü: A3, A4, A5 seçim girişlerine (A3 en az anlamlı), M/$\overline{IO}$ ve A0 aktif düşük E1 ve E2'ye, A7 VE A6 aktif yüksek E3'e bağlanır. CBA = 111 = 7 olduğundan 7 numaralı çıkış $\overline{CS}$'yi sürer.
  - İşlemcinin A2'si 8255'in A1'ine, A1'i 8255'in A0'ına bağlanır. Sonuç: F8H port A, FAH port B, FCH port C, FEH kontrol yazmacı.
  - Örnek komutlar: `OUT 0F8H, AL` ve `IN AL, 0F8H`. Çift adresten 8 bitlik işlemde A0 = 0 ile $\overline{BHE}$ = 1 eşdeğerdir; A0 yerine $\overline{BHE}$ bir DEĞİL kapısından geçirilip E2'ye bağlanabilir.
- Ardışık tek adres örneği: F9H'den itibaren (ekrandan, 00:30:00 ve 00:35:00)
  - Adresler F9H, FBH, FDH, FFH'dir. Sabit bitler: A7-A3 = 1, A0 = 1, M/$\overline{IO}$ = 0; bu işlemde $\overline{BHE}$ = 0 olur.
  - Kod çözücüde A0 bir DEĞİL kapısından geçip E2'ye gider; 7 numaralı çıkış $\overline{CS}$'dir. 8255'in veri uçları D8-D15'e bağlanır.
  - Tek adresten 8 bitlik işlemde A0 = 1 ile $\overline{BHE}$ = 0 eşdeğerdir; DEĞİL kapısı yerine $\overline{BHE}$ doğrudan E2'ye bağlanabilir.
  - Sonuç: F9H port A, FBH port B, FDH port C, FFH kontrol yazmacı.
- Ardışık adres örneği: C0H'den itibaren (ekrandan, 00:40:00 ve 00:45:00; hoca bu kısımdan sorumlu olunmadığını söyledi)
  - Adresler C0H, C1H, C2H, C3H'dir. Sabit bitler: A7 = A6 = 1, A5 = A4 = A3 = A2 = 0, M/$\overline{IO}$ = 0. A1 ve A0 dört kombinasyonu oluşturur ve doğrudan 8255'in A1, A0 uçlarına bağlanır.
  - 8086 bu yerleşimi doğrudan desteklemez; iki adet 74245 tampon eklenir. Çift adreste (A0 = 0, Y0 = 0) 8255 verisi D0-D7'ye, tek adreste (A0 = 1, $\overline{BHE}$ = 0, Y0 = 0) D8-D15'e aktarılır.
  - Sonuç: C0H port A, C1H port B, C2H port C, C3H kontrol yazmacı.
- Kod çözücüde birleştirme kuralı
  - Yedi sabit bit, 3'e 8 kod çözücünün altı girişinden fazladır; iki bit tek girişte birleştirilir.
  - İkisi de 1 olması gereken iki bit VE kapısıyla aktif yüksek bir girişe, ikisi de 0 olması gereken iki bit VEYA kapısıyla aktif düşük bir girişe bağlanır (doğruluk tablolarından $E3 = A7 \cdot A6$, $\overline{E1} = A3 + A2$).
- 8255'in çalışma modları (ekrandan, 00:50:00)
  - Mod 0, Basic I/O: yalnız basit giriş ve çıkış; işlemci yazdığı ya da okuduğu verinin karşıya ulaşıp ulaşmadığını denetlemez.
  - Mod 1, Strobed I/O: el sıkışmalı (handshaking) ve tek yönlü; port baştan giriş ya da çıkış olarak ayarlanır. 8255 strobe gönderir, karşı taraf acknowledge ile alındığını bildirir.
  - Mod 2, Bi-directional Bus: el sıkışmalı ve çift yönlü; `IN` verilince port giriş, `OUT` verilince çıkış olur, yön otomatik değişir.
  - Bit Set/Reset (BSR) modu: port C'nin her ucunu ayrı ayrı çıkış olarak 1 ya da 0 yapar; mod 1 ve mod 2'de el sıkışma ve kesme izin bitlerini ayarlamak için de kullanılır.
- Kontrol yazmacı: mod 0 ayarı (ekrandan, 00:55:00 ve 01:00:00)
  - Kontrol yazmacı 8 bittir ve 8255'in A1 = A0 = 1 olduğu adreste yazılır.
  - D7 = 1 mod ayar sözcüğü, D7 = 0 BSR sözcüğüdür.
  - Grup A (port A ve port C üst 4 bit): D6-D5 mod seçimi (00 mod 0, 01 mod 1, 1X mod 2), D4 port A yönü, D3 port C üst (PC7-PC4) yönü.
  - Grup B (port B ve port C alt 4 bit): D2 mod seçimi (0 mod 0, 1 mod 1), D1 port B yönü, D0 port C alt (PC3-PC0) yönü.
  - Yön bitlerinde 1 giriş, 0 çıkıştır. LED bağlı port çıkış (0), düğme bağlı port giriş (1) olmalıdır.
  - Grup A ve grup B birbirinden bağımsız olarak farklı modlarda çalışabilir.
  - Mod 0 sözcüğü: D7 D6 D5 = 1 0 0 ve D2 = 0.
- Kontrol yazmacı: BSR ayarı (ekrandan, 01:05:00)
  - D7 = 0; D6, D5, D4 önemsizdir (don't care).
  - D3 D2 D1 üç bitlik ikilik sayısı port C'nin hangi ucunun (0-7) seçileceğini belirtir. D0 = 1 ucu 1 yapar (set), D0 = 0 ucu 0 yapar (reset).
  - Örnek: D3 D2 D1 = 110 = 6 ve D0 = 1 ise PC6 = 1 olur.
- Mod 0 örneği: 60H'den itibaren ardışık çift adresler (ekrandan, 01:10:00, 01:15:00 ve 01:20:00)
  - Adresler 60H, 62H, 64H, 66H. Sabit bitler: A7 = 0, A6 = 1, A5 = 1, A4 = 0, A3 = 0, A0 = 0, M/$\overline{IO}$ = 0 (aksi söylenmedikçe isolated I/O varsayılır).
  - Tahtadaki çözüm: C = A7, B = A6, A = A4; E1 (aktif yüksek) = A5; $\overline{E2A}$ = A3; $\overline{E2B}$ = A0 VEYA M/$\overline{IO}$. CBA = 010 = 2, yani Y2 çıkışı CS8255 olur.
  - Doğrulama: 70H'de A4 = 1 olur, CBA = 011 = 3 çıkar ve Y2 = 1 kalır; 61H'de A0 = 1 olduğu için VEYA çıkışı 1 olur ve hiçbir çıkış seçilmez.
  - Veri D0-D7'ye, işlemcinin A2'si 8255'in A1'ine, A1'i 8255'in A0'ına bağlanır.
- Proteus örneği: verilen devreden adres bulma (ekrandan, 01:25:00)
  - 74LS137 kod çözücüde A = A5, B = A6, C = A7; A0 DEĞİL kapısından geçip aktif yüksek E1'e, M/$\overline{IO}$ aktif düşük E2'ye, A4 VEYA A3 aktif düşük LE girişine bağlı; Y3 çıkışı CS8255'tir.
  - Y3 için CBA = 011: A7 = 0, A6 = 1, A5 = 1; ayrıca A0 = 0, M/$\overline{IO}$ = 0, A4 = A3 = 0. A2 ve A1 serbest kalır. Adresler yine 60H, 62H, 64H, 66H çıkar.
  - Adres tutma için 74273 (pozitif kenar tetiklemeli) kullanılmıştır; derste görülen seviye tetiklemeli 74373 ile aynı işi yapar.
  - Kod `ENDLESS: OUT 61H, AL / JMP ENDLESS` ile 61H'de cihazın seçilmediği, 60H'ye çevrilince seçildiği benzetimde gösterildi (ekrandan, 01:30:00).
- İşletim sistemsiz program yapısı
  - Bu uygulamalarda işletim sistemi yoktur; kod sürekli aynı denetimi yapacağı için sonsuz döngüyle yazılır.
  - Döngü olmazsa işlemci bellekteki rastgele içeriği komut olarak yürütür. `HLT` de kullanılabilir, ancak işlemciyi yeniden uyandırmak için dış donanım kesmesi gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ardışık çift adresler on altılık düzende yazılmalıdır.
  - F8H'den sonraki çift adres FAH'dır; A8H'den sonra B0H gelir sanmak sık yapılan bir hatadır (doğrusu AAH).
- Adres çözümleme devresi yalnız verilen adreslerde $\overline{CS}$ üretmelidir.
  - Verilen adreslerin hepsinde $\overline{CS}$ üretip başka hiçbir adreste üretmeyen devre doğrudur. Örneğin 60H-66H için tasarlanan devre 80H-86H'de de $\overline{CS}$ üretiyorsa hatalıdır.
  - Aynı adres aralığını sağlayan çok sayıda bağlantı biçimi vardır; çalışan herhangi biri yeterlidir.
- Kod çözücü uç adlandırması ezberlenmez.
  - CBA, A2A1A0, E1/E2/E3 ya da E1/E2A/E2B gibi farklı adlar olabilir. Uç üzerindeki yuvarlak aktif düşüklüğü gösterir; sınavda fonksiyon tablosu verilir.
  - Harfle adlandırılmış seçim uçlarında anlamlılık harf büyüdükçe artar: C en anlamlı uçtur.
- 8 bitlik adreslerle çalışılıyorsa çözümleme A0-A7 ile yapılır; 16 adres ucunun hepsini kullanmak gerekmez.
- Aksi söylenmedikçe isolated I/O kullanılır; bu durumda M/$\overline{IO}$ = 0 da çözümlemeye girmelidir.
- Laboratuvarda iki soru tipi vardır: verilen bağlantıdan cihazın adresini bulmak ya da verilen adres aralığı için çözümleme devresi tasarlamak.
- Port yönünü soruda verilen senaryoya göre öğrenci belirler: LED çıkış, düğme giriş.

## Kısa Tekrar Notları

- 8255: 4 adres (PA, PB, PC, kontrol); $\overline{CS}$ adres çözümlemeden, $\overline{RD}$/$\overline{WR}$ doğrudan 8086'dan.
- 1 MB = $512K \times 16$; G/Ç 64 KB = $32K \times 16$; çift blok A0 = 0, tek blok $\overline{BHE}$ = 0.
- Ardışık çift: veri D0-D7, işlemci A2-A1 → 8255 A1-A0. Ardışık tek: veri D8-D15, aynı adres bağlantısı.
- Çift adreste 8 bit: A0 = 0 ≡ $\overline{BHE}$ = 1. Tek adreste 8 bit: A0 = 1 ≡ $\overline{BHE}$ = 0.
- F8H çift: F8 PA, FA PB, FC PC, FE kontrol. F9H tek: F9 PA, FB PB, FD PC, FF kontrol. C0H ardışık: C0-C3 (74245 tamponlarıyla).
- İki 1 → VE → aktif yüksek giriş; iki 0 → VEYA → aktif düşük giriş.
- Modlar: Mod 0 basit G/Ç, Mod 1 tek yönlü el sıkışmalı, Mod 2 çift yönlü el sıkışmalı, BSR port C bit ayarı.
- Kontrol sözcüğü D7 = 1: mod; D6-D5 grup A modu, D4 PA, D3 PC üst, D2 grup B modu, D1 PB, D0 PC alt; 1 giriş, 0 çıkış.
- Mod 0'da 16 yön kombinasyonu: $2^4$ (PA, PB, PC üst, PC alt).
- BSR: D7 = 0, D3D2D1 bit numarası, D0 set/reset.
- 60H-66H çift: A7..A0 = 0110 0xx0, M/$\overline{IO}$ = 0.
- Gömülü kodda sonsuz döngü (`JMP`) kullanılır.

## Detaylı Açıklamalar

- 16 bitlik veri yolu ve 8 bitlik cihaz ilişkisi
  - 8086'nın 20 adres ucu 1 MB bellek, en çok 16 bitlik G/Ç adresi (adres DX'te tutulabildiği için) 64 KB G/Ç uzayı verir. İşlemci tek çevrimde 16 bit okuyabilmek için uzayı 16 bit genişliğinde satırlar olarak görür; her satır bir çift ve bir tek bayttan oluşur. Çift adres verilip 16 bit işlem yapıldığında hem A0 = 0 hem $\overline{BHE}$ = 0 olur ve aynı satırın iki baytı D0-D7 ile D8-D15 üzerinden birlikte aktarılır.
  - 8 bitlik bir cihazın tek veri yolu vardır. Bu yüzden ya hep çift bloktaki satırlara (ardışık çift adresler, D0-D7) ya da hep tek bloktaki satırlara (ardışık tek adresler, D8-D15) yerleşir. Bu durumda işlemcinin A0'ı sabit kalır, 8255'in yazmaç seçimini A2 ve A1 yapar. A1 ve A2 ters bağlanırsa yalnız port B ile port C'nin adresleri yer değiştirir.
- 3'e 8 kod çözücü ile çözümleme
  - Kod çözücünün iki aktif düşük ve bir aktif yüksek etkinleştirme girişi vardır. Etkinleştirme koşulu sağlanırsa seçim uçlarındaki ikilik sayının ondalık karşılığı olan çıkış 0, diğerleri 1 olur; koşul sağlanmazsa bütün çıkışlar 1 olur. Çıkışlar aktif düşük olduğundan seçilen çıkış doğrudan 8255'in $\overline{CS}$'sine bağlanabilir.
  - Örneklerde yedi sabit koşul (beş adres biti, A0 ve M/$\overline{IO}$) altı girişe sığdırılır. F8H örneğinde A7 ve A6 VE kapısıyla E3'e bağlanmıştır; F9H örneğinde aynı yapı korunur, yalnız A0 DEĞİL kapısından geçirilir ve veri yolu bağlantısı D8-D15'e taşınır.
- C0H ardışık yerleşim (sorumlu olunmayan kısım)
  - Ardışık adreslerde A0 da yazmaç seçimine katılır, bu yüzden 8255'in A1 ve A0'ı işlemcinin A1 ve A0'ına bağlanır. Kod çözücüde A4, A3, A2 seçim girişlerine (A2 en anlamlı), M/$\overline{IO}$ ve A5 aktif düşük girişlere, A7 VE A6 aktif yüksek girişe bağlanır; Y0 seçim çıkışıdır.
  - Alttaki 74245'in $\overline{OE}$'si Y0 VEYA A0 ile sürülür: çift adreste ikisi de 0 olur ve 8255 verisi D0-D7'ye geçer. Üstteki 74245'in $\overline{OE}$'si $\overline{BHE}$, Y0 ve A0'ın tersinin VEYA'sıyla sürülür: tek adreste üçü de 0 olur ve veri D8-D15'e geçer (ekrandan, 00:40:00).
- 8255 kontrol yazmacının kullanımı
  - Kontrol yazmacına, 8255'in A1 ve A0 uçlarını 1 yapan adrese `OUT` ile yazılır. En anlamlı bit sözcüğün türünü belirler: 1 ise mod ayarı, 0 ise BSR komutu.
  - Mod 0'da dört bağımsız parça vardır (PA, PB, PC üst, PC alt) ve her biri giriş ya da çıkış olabilir; bu yüzden $2 \times 2 \times 2 \times 2 = 16$ farklı yön kombinasyonu bulunur. Örneğin port A giriş, port B çıkış, PC alt çıkış ve PC üst giriş bunlardan biridir.
  - BSR sözcüğünde D3 D2 D1 bit numarasını, D0 yazılacak değeri verir. Bu mod şimdilik basit G/Ç gibi kullanılacak, mod 1 ve 2'de el sıkışma bitlerinin ayarı için de işe yarayacaktır.
- 60H örneğinin çözüm yöntemi
  - Önce adresler ikilik yazılır (60H = 0110 0000, 62H = 0110 0010, 64H = 0110 0100, 66H = 0110 0110). Dört adreste değişmeyen bitler sabit koşulları (A7 = 0, A6 = 1, A5 = 1, A4 = 0, A3 = 0, A0 = 0), değişen A2 ve A1 de 8255'in yazmaç seçimini verir. M/$\overline{IO}$ = 0 eklenince yedi koşul olur.
  - İkisi de 0 olması gereken A0 ve M/$\overline{IO}$ VEYA kapısıyla aktif düşük $\overline{E2B}$'ye bağlanır. Aktif yüksek bir girişe bağlamak burada anlamlı olmaz.
  - Ters yönde, verilen bir devreden adres bulunurken her girişin hangi değerde cihazı seçtiği yazılır ve serbest bitlerin (A2, A1) tüm kombinasyonları denenir. Proteus'taki devrede bu yolla 60H, 62H, 64H, 66H bulunmuştur.
- Benzetimde gözlem
  - 61H adresine yazıldığında kod çözücü çıkışlarının hepsi 1 kalır ve 8255 seçilmez; veri yolundaki değer cihaza alınmaz. JMP sırasında veri hattı yüksek empedans gösterir. Adres 60H yapılınca 8255 her `OUT`'ta AL'deki (o an rastgele olan) değeri alır.

> **Ders sonrası not:** Altyazıda F8H dizisinin dördüncü adresi "FA" olarak geçer (00:17:08, 00:26:11). Doğrusu FEH'dir ve kontrol yazmacı bu adrese düşer; ses tanıma hatası olması büyük olasılıktır.

> **Ders sonrası not:** Hoca 74273'ün MR ucunu chip select ya da output enable karşılığı olarak andı. 74273'te MR büyük olasılıkla aktif düşük temizleme (master reset) girişidir; lojik 1'e bağlanması flip-flopların sıfırlanmamasını sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
