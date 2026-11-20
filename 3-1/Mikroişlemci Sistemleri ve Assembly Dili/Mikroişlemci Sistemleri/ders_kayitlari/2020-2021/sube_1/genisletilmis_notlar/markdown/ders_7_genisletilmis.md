# Ders 7 Genişletilmiş Notu: 8255 Adres Çözümleme Alternatifleri, Çalışma Modları ve Kontrol Yazmacı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersin tekrarı ve programlanabilir arayüz kavramı
- 2. 8255'in uçları ve yazmaçları
- 3. 16 bitlik veri yolunda bellek ve G/Ç düzeni
- 4. Birinci alternatif: ardışık çift adresler (F8H)
- 5. İkinci alternatif: ardışık tek adresler (F9H)
- 6. Üçüncü alternatif: ardışık adresler (C0H)
- 7. Kod çözücüde iki biti birleştirme kuralı
- 8. 8255'in çalışma modları
- 9. Kontrol yazmacı: mod 0 ayarı
- 10. Kontrol yazmacı: Bit Set/Reset modu
- 11. Mod 0 örneği: 60H'den itibaren ardışık çift adresler
- 12. Proteus örneği: verilen devreden adres bulma ve benzetim
- 13. İşletim sistemsiz programlarda sonsuz döngü
- Örnek Sorular

## 1. Önceki dersin tekrarı ve programlanabilir arayüz kavramı

Ders, önceki haftanın konularını hatırlatarak başlar. Önceki hafta özel tasarım (custom) basit bir çıkış birimi ve basit bir giriş birimi tasarlanmış, bunlar LED ve düğme arayüzü örnekleriyle verilmişti. Giriş-çıkış komutlarının bütün kullanım biçimleri, G/Ç haritalama yöntemleri ve etkileri, düğme bağlantı biçimleri, kontak gürültüsü ve LED bağlantı biçimleri konuşulmuş, ardından adres çözümlemenin genel tanımı verilmişti.

Bu donanım örneklerindeki birimler üç bölümden oluşur:

- **Adres çözümleme devresi:** cihazın yalnız kendi adresinde etkin olmasını sağlar.
- **Arayüz (interface):** doğrudan veri yoluna bağlanan elemandır; örneklerde 74245 kullanılmıştı.
- **Çevre birimi (G/Ç cihazı):** çıkış örneğinde LED'ler, giriş örneğinde düğmeler.

İki örnek aynı adresteydi. Aralarındaki tek fark, LED örneğinin yalnız yazma işleminde (write ile birlikte çözümleme), düğme örneğinin ise yalnız okuma işleminde, yani F000H adresinden okuma yapıldığında etkin olmasıydı. Bu örnekler 16 bitlik veri yoluna sahip 8086'ya 8 bitlik bir G/Ç cihazının nasıl bağlanacağını gösteriyordu. Ayrıca F000H adresinde 16 bitlik basit bir çıkış biriminin nasıl yapılacağı soru olarak tartışılmıştı. 8255 tarafında da uçlar, iç yapı ve 16 bitlik veri yolunda 8 bitlik cihaz bağlama konuşulmuş, adres çözümleme devresinde kalınmıştı. Bu derste mod 0 ve örnekleri bitirilecek, mümkünse bit set/reset modu ve mod 1'e geçilecektir (dersin konu listesi, ekrandan, 00:05:00).

Basit G/Ç birimleri yalnız donanıma bağlı tek bir iş yapabilir. **Programlanabilir çevre birimleri** ise genel geçer bir port yapısına sahiptir ve yazılımla farklı işlere ayarlanabilir: farklı veri genişliklerinde paralel iletişim, farklı hızlarda seri iletişim ya da farklı dalga biçimlerinde zamanlama. Farklı genişlikte veri giriş-çıkışı 8255'e, zamanlama çıkışları ise 8254 entegresine karşılık gelir. Bu cihazlar ders boyunca adım adım görülecektir.

## 2. 8255'in uçları ve yazmaçları

8255'in 8 bitlik bir veri yolu ve üç portu vardır: port A, port B ve port C. Mod 0'da (Basic I/O) A grubu kendi içinde 8 bit giriş ya da 8 bit çıkış, B grubu (port B) da aynı biçimde ayarlanabilir. Port C ise iki yarıya ayrılır: düşük anlamlı 4 biti ve yüksek anlamlı 4 biti birbirinden bağımsız olarak giriş ya da çıkış yapılabilir. Dolayısıyla mod 0'da 8255 iki adet 8 bitlik ve iki adet 4 bitlik bağımsız port gibi davranır. İlerideki derslerde mod 1 ve mod 2'de port C'nin el sıkışma (handshaking) için kontrol ve sinyal uçları ürettiği görülecektir; orada port A ile port C'nin bir kısmı grup A'yı, port B ile port C'nin kalan kısmı grup B'yi oluşturacaktır.

Cihazın iki adres ucu (A0, A1) vardır. Bu, 8086'nın G/Ç uzayında $2^2 = 4$ baytlık yer kapladığı, yani dışarıdan erişilebilen dört yazmacı olduğu anlamına gelir: port A yazmacı, port B yazmacı, port C yazmacı ve kontrol yazmacı.

- Mod 0'da port A yazmacına yazılan değer, port A'nın fiziksel uçlarında elektriksel sinyal olarak oluşur.
- Kontrol yazmacına yazılan değerin her bitinin bir işlevi vardır; 8255 bu bitlere göre programlanır.
- Mod 0'da fiziksel uçlardaki elektriksel değerler sürekli olarak port yazmaçlarında lojik seviye olarak tutulur. İlgili adresten okuma yapmak, port uçlarındaki fiziksel değerin 8 bitlik bir örneğini alıp işlemciye aktarmak demektir.

Böylece mod 0'da istenen anda port uçları okunabilir ya da port uçlarında istenen değer oluşturulabilir.

Kontrol uçları ekrandaki slaytta şöyle özetlenir (ekrandan, 00:10:00):

- $\overline{CS}$: 8255'i etkinleştirir (enable). Önceki haftanın özel tasarım cihazlarındaki enable ucunun karşılığıdır. $\overline{CS}$'ye lojik 1 verilirse cihazın veri uçları 8086'nın veri yolundan koparılmış gibi davranır; veri yoluna bir şey çıkaramaz, veri yolundan bir şey okuyamaz. $\overline{CS}$, cihazı belirli bir adres aralığına yerleştiren adres çözümleme devresinden sürülür.
- $\overline{RD}$: işlemcinin 8255'ten okuma yapmasını sağlar.
- $\overline{WR}$: işlemcinin 8255'e yazma yapmasını sağlar. $\overline{RD}$ ve $\overline{WR}$ doğrudan 8086'nın aynı adlı uçlarına bağlanır.
- A0 ve A1: port (yazmaç) seçim uçları.

## 3. 16 bitlik veri yolunda bellek ve G/Ç düzeni

Ders boyunca temel soru şudur: 16 bitlik bir veri yoluna 8 bitlik cihazlar nasıl bağlanır? Bunun için 8086'nın adresleme mantığını hatırlamak gerekir (ekrandan, 00:15:00).

8086'nın 20 adres ucu vardır; $2^{20}$ = 1 MB bellek adreslenebilir. G/Ç için en çok 16 adres ucu kullanılabilir, çünkü G/Ç adresi en fazla DX'te saklanabilir; bu da 64 KB'lık bir G/Ç uzayı verir. 1 MB'lık alan için olası düzenlerden biri $1M \times 8$, yani her biri 8 bit olan 1M adres gözüdür. Ancak bu düzen işlemci için anlamlı değildir, çünkü 8086 tek bir okuma/yazma çevriminde şu işlemleri yapabilir:

- çift adresten 8 bitlik işlem,
- tek adresten 8 bitlik işlem,
- çift adresten 16 bitlik işlem.

Bir seferde 16 bit okuyabilmek için işlemci 1 MB'ı $\times 16$ mantığında, yani $512K \times 16$ olarak görmelidir. G/Ç uzayında da aynı biçimde 64 KB, $32K \times 16$ olarak görülür.

Pratikte uzay, örneğin G/Ç için 64 KB, 32K'lık iki bloğa ayrılır: çift adres bloğu ve tek adres bloğu. Her bloğun genişliği 8 bittir. Çift adresten 8 bitlik bir işlem çift bloktaki bir satıra, tek adresten 8 bitlik bir işlem tek bloktaki bir satıra denk gelir. Çift adresten 16 bitlik işlemde ise verinin düşük kısmı çift adresten, yüksek kısmı hemen ardından gelen (artı bir) tek adresten gelir. Bu iki adres aynı satırdaki çift ve tek bloklardır; iki blok birlikte etkinleştirilir ve veri D0-D7 ile D8-D15 üzerinden 16 bit olarak aktarılır.

Çift blok A0 = 0 ile, tek blok $\overline{BHE}$ (bus high enable) = 0 ile etkinleştirilir. İşlemci çift adresten 16 bitlik işlem yaptığında hem $\overline{BHE}$'yi 0 yapar hem de adres çift olduğu için A0 zaten 0'dır.

Bundan şu sonuç çıkar: 16 bitlik işlemciye 8 bitlik bir arayüz bağlanırken cihaz ya ardışık çift adreslere ya da ardışık tek adreslere yerleştirilir. Ardışık çift adreslere yerleştirilen cihaz veriyi D0-D7 üzerinden, ardışık tek adreslere yerleştirilen cihaz D8-D15 üzerinden sunmalıdır.

## 4. Birinci alternatif: ardışık çift adresler (F8H)

Önceki haftadan kalan örnekte 8255'in F8H'den itibaren ardışık çift adreslere yerleştirilmesi isteniyordu. 8255 G/Ç uzayında 4 bayt kapladığı için dört çift adres gerekir: F8H, FAH, FCH, FEH.

> **Hocanın vurgusu:** On altılık düzende yazıldığını unutmayın. Sık yapılan hatalardan biri, örneğin A8H'den sonraki çift adresin B0H olduğunu sanmaktır. F8H'den sonraki çift adres FAH, sonra FCH, sonra FEH'dir.

> **Ders sonrası not:** Altyazıda dizinin dördüncü adresi iki yerde "FA" olarak geçer (00:17:08, 00:26:11). Doğrusu FEH'dir; ses tanıma hatası olması büyük olasılıktır. Ayrıca A8H'den sonraki çift adres AAH'dir.

Adresler ikilik yazıldığında dördünde de A7, A6, A5, A4, A3 = 1 ve A0 = 0'dır. Değişen bitler A2 ve A1'dir; dört farklı kombinasyon oluşturdukları için 8255'in adres uçlarına bağlanırlar: işlemcinin A2'si 8255'in A1'ine, A1'i 8255'in A0'ına. Bu ikisi ters bağlansaydı yalnız port B ile port C'nin adresleri karışırdı.

Ek olarak bu bir G/Ç işlemi olduğu için M/$\overline{IO}$ = 0 olmalıdır. Hoca bu değeri derste öğrencilere sordu; G/Ç işlemlerinde M/$\overline{IO}$ ucu 0 değerini alır. Böylece çözümleme devresi A7-A3 = 1, A0 = 0 ve M/$\overline{IO}$ = 0 olduğunda 8255'in $\overline{CS}$'sine 0, diğer bütün durumlarda 1 üretmelidir (ekrandan, 00:20:00).

Bu yapılandırma çift adresten 8 bitlik işleme aittir. Örneğin `OUT 0F8H, AL` komutu çalıştırıldığında (adres sayısının başına 0 konması gerekir) F8H çift adres, AL kullanıldığı için de işlem 8 bitliktir. İşlemci A7-A3'e 1, A0'a 0 üretir. Veri yolunun yüksek anlamlı kısmı kullanılmadığı için $\overline{BHE}$'ye de 1 üretir. Aynı durum `IN AL, 0F8H` için de geçerlidir.

### 4.1 3'e 8 kod çözücü ile çözümleme

Devrede bir 3'e 8 kod çözücü kullanılır (ekrandan, 00:25:00). Kod çözücünün üç seçim ucu ve üç etkinleştirme ucu vardır; etkinleştirme uçlarından ikisi aktif düşük (E1, E2), biri aktif yüksektir (E3). Etkinleştirme koşulu sağlandığında seçim uçlarındaki ikilik sayının ondalık karşılığı olan çıkışı 0, diğerlerini 1 yapar. Hoca seçim uçlarını anlam sırasına göre C, B, A olarak adlandırır; formül $(CBA)_2 = (\ \ )_{10}$ biçiminde yazılır.

Slayttaki bağlantılar:

- Seçim girişleri: A3 → kod çözücünün A0'ı (en az anlamlı), A4 → A1, A5 → A2.
- M/$\overline{IO}$ → E1 (aktif düşük).
- A0 → E2 (aktif düşük).
- A7 ve A6 → VE kapısı → E3 (aktif yüksek).
- 7 numaralı çıkış → 8255 $\overline{CS}$.

Toplam yedi sabit koşul vardır (A7, A6, A5, A4, A3, A0, M/$\overline{IO}$) ama kod çözücünün altı girişi bulunur. Bu yüzden iki koşul birleştirilir: ikisi de 1 olması gereken A7 ve A6 bir VE kapısından geçirilip aktif yüksek E3'e bağlanmıştır.

`OUT 0F8H, AL` için kontrol edelim: M/$\overline{IO}$ = 0 ve A0 = 0 olduğu için iki aktif düşük girişe 0 gelir; A7 = A6 = 1 olduğundan VE çıkışı 1 olur ve aktif yüksek girişe 1 gelir. Cihaz etkindir. Seçim uçlarında $(CBA)_2 = (111)_2 = 7$ olduğundan 7 numaralı çıkış 0 olur ve 8255 seçilir. Çıkışlar zaten aktif düşük olduğu için bu çıkış doğrudan $\overline{CS}$'ye bağlanır.

Diğer bağlantılar: işlemcinin $\overline{RD}$ ve $\overline{WR}$'si 8255'in $\overline{RD}$ ve $\overline{WR}$'sine, A2 ve A1 de yukarıda anlatıldığı gibi 8255'in A1 ve A0'ına bağlanır. Çift adresten 8 bitlik işlem yapılacağı için 8255'in veri uçları işlemcinin düşük anlamlı veri yoluna (D0-D7) bağlanır.

### 4.2 A0 = 0 ile BHE = 1'in eşdeğerliği

Çift adresten 8 bitlik işlemlerde A0'ın 0 olmasını aramak ile $\overline{BHE}$'nin 1 olmasını aramak aynı şeydir (karede $A0 = 0 \equiv \overline{BHE} = 1$ olarak yazılmıştır). Bu yüzden A0'ı E2'ye bağlamak yerine $\overline{BHE}$ bir DEĞİL kapısından geçirilip aktif düşük E2'ye bağlansaydı da aynı sonuç elde edilirdi.

### 4.3 Sonuç adres haritası

İşlemcinin A2'si 8255'in A1'ine, A1'i 8255'in A0'ına bağlandığı için 8086'nın G/Ç uzayında:

| Adres | 8255 yazmacı |
|---|---|
| F8H | Port A |
| FAH | Port B |
| FCH | Port C |
| FEH | Kontrol yazmacı |

## 5. İkinci alternatif: ardışık tek adresler (F9H)

Bu kez 8255, F9H'den itibaren ardışık tek adreslere yerleştirilir: F9H, FBH, FDH, FFH (ekrandan, 00:30:00). İkilik yazıldığında dördünde de A7-A3 = 1 ve A0 = 1'dir. M/$\overline{IO}$ = 0 olmalıdır. Veri yolunun yüksek anlamlı kısmı kullanılacağı için $\overline{BHE}$ de 0 olur. A2 ve A1 yine dört kombinasyonu oluşturur ve 8255'in adres uçlarına bağlanır.

Örnek komutlar `OUT 0F9H, AL` ya da `IN AL, 0FBH` olabilir. Bu komutlarda işlemci A7-A3'e 1, tek adres olduğu için A0'a 1, M/$\overline{IO}$'ya 0 ve $\overline{BHE}$'ye 0 üretir. Tek adresten 8 bitlik işlemlerde A0'ın 1 olmasını aramak ile $\overline{BHE}$'nin 0 olmasını aramak eşdeğerdir; hoca bunu üç çizgili eşitlik işaretiyle gösterdi.

Kod çözücü yapısı birinci alternatifle aynıdır, tek fark A0'ın bir DEĞİL kapısından geçirilip E2'ye bağlanmasıdır:

- A3, A4, A5 → seçim girişleri A0, A1, A2.
- M/$\overline{IO}$ → E1 (aktif düşük).
- A0 → DEĞİL → E2 (aktif düşük).
- A7 VE A6 → E3 (aktif yüksek).
- 7 numaralı çıkış → $\overline{CS}$.

Kontrol: A3, A4, A5 = 1; M/$\overline{IO}$ = 0; A0 = 1 olduğu için DEĞİL çıkışı 0'dır. İki aktif düşük girişe 0, aktif yüksek girişe 1 gelir; cihaz seçilir. $(CBA)_2 = (111)_2 = 7$ olduğu için yine 7 numaralı çıkış $\overline{CS}$'yi üretir (ekrandan, 00:35:00). Etkinleştirme koşulu sağlanmazsa, yani bu dört adres dışında bir adres verilirse bütün çıkışlar 1 olur ve cihaz seçilmez; istenen tam olarak budur.

Bu derste hoca bir kuralı da hatırlattı: bir entegrede harflerle adlandırılmış uçlar görülürse, harf büyüdükçe anlamlılık artar. Yani en anlamlı seçim ucu C'dir. Ondalık karşılık hesaplanırken C, B, A değerlerinden oluşan ikilik sayıya bakılır.

$\overline{RD}$, $\overline{WR}$ ve adres bağlantıları ilk alternatifle aynıdır. Veri ise veri yolunun yüksek anlamlı kısmında beklendiği için 8255'in veri uçları işlemcinin D8-D15 uçlarına bağlanır.

Tek adresten 8 bitlik işlemde A0 = 1 ile $\overline{BHE}$ = 0 eşdeğer olduğundan, A0'ın DEĞİL kapısından geçirilip E2'ye bağlandığı yer yerine $\overline{BHE}$ doğrudan E2'ye bağlanabilirdi (karede "BHE → E2" notu, ekrandan, 00:35:00).

**Soru:** Kod çözücü uçlarının adlarını ezberlemek gerekiyor mu? **Cevap:** Hayır. Uç adları kaynağa göre değişebilir: seçim uçları CBA ya da A2A1A0, etkinleştirme uçları E1, E2, E3 ya da E1, E2A, E2B gibi. Önemli olan işleyişidir: iki aktif düşük ve bir aktif yüksek etkinleştirme ucu olmalıdır. Aktif düşük uçların girişinde küçük bir yuvarlak bulunur; aktif yüksek uçta bu gösterim yoktur. Hoca yüz yüze sınavlarda kod çözücünün fonksiyon tablosunu verdiğini, kendi kullandığı gösterimi de sınavda vereceğini söyledi.

Sonuç adres haritası:

| Adres | 8255 yazmacı |
|---|---|
| F9H | Port A |
| FBH | Port B |
| FDH | Port C |
| FFH | Kontrol yazmacı |

## 6. Üçüncü alternatif: ardışık adresler (C0H)

Hoca bu kısımdan sorumlu olunmadığını, yalnız nasıl çalıştığını görmek için anlattığını belirtti.

Önceki alternatiflerde adresler ikişer ikişer artıyordu. Ardışık çift adreslerde bir sonraki adres çift bloğun bir üst satırı, ardışık tek adreslerde tek bloğun bir üst satırıdır. Üçüncü alternatifte 8 bitlik cihaz gerçekten ardışık adreslere yerleştirilir. 8086 bunu doğrudan desteklemez; harici donanım eklemek gerekir.

Örnekte 8255'in C0H'den itibaren ardışık adreslere yerleştirilmesi istenir: C0H, C1H, C2H, C3H. Bu adreslerde sabit bitler A7 = 1, A6 = 1, A5 = 0, A4 = 0, A3 = 0, A2 = 0'dır; ayrıca M/$\overline{IO}$ = 0. Önceki alternatiflerde A0 sabitti (0 ya da 1); burada ise A1 ve A0 dört kombinasyonu oluşturur. Bu yüzden işlemcinin A0'ı 8255'in A0'ına, A1'i 8255'in A1'ine bağlanır (register select).

Devre (ekrandan, 00:40:00):

- Kod çözücü seçim girişleri: A4 → A0, A3 → A1, A2 → A2.
- M/$\overline{IO}$ → E1 (aktif düşük), A5 → E2 (aktif düşük), A7 VE A6 → E3 (aktif yüksek).
- Y0 çıkışı → 8255 $\overline{CS}$. A4, A3, A2 = 000 olduğundan ikilik karşılık 0'dır ve Y0 seçilir.
- İki adet 74245 tampon: biri 8255 verisini D0-D7'ye, diğeri D8-D15'e aktarır.
- Alttaki (D0-D7) 74245'in $\overline{OE}$'si = Y0 VEYA A0.
- Üstteki (D8-D15) 74245'in $\overline{OE}$'si = $\overline{BHE}$ VEYA Y0 VEYA (A0'ın tersi).

Çalışma mantığı:

- **Çift adres:** A0 = 0'dır. Verilen adres aralığında Y0 = 0'dır. VEYA kapısının iki girişi 0 olduğu için çıkışı 0 olur ve alttaki tamponun aktif düşük $\overline{OE}$'si etkinleşir; 8255'in veri uçları D0-D7'ye aktarılır.
- **Tek adres:** A0 = 1'dir, DEĞİL kapısından sonra 0 olur. Tek adresle işlem yapıldığı için $\overline{BHE}$ = 0, aralık içinde olunduğu için Y0 = 0'dır. Üç giriş de 0 olduğunda VEYA çıkışı 0 olur, üstteki tamponun $\overline{OE}$'si etkinleşir ve 8255'in veri uçları veri yolunun yüksek anlamlı kısmına aktarılır.

Önceki bağlantılardan farkı ek tampon denetimidir; doğrudan ardışık adresleri 8086 desteklemediği için bu tamponlar gerekir. Ardışık çift ya da ardışık tek yerleşimde böyle bir karmaşaya gerek kalmaz.

**Soru:** Y0 nedir? **Cevap:** Kod çözücünün çıkışları Y0, Y1, ..., Y7 olarak adlandırılır; Y0, sıfır numaralı çıkıştır.

Sonuç adres haritası: C0H port A, C1H port B, C2H port C, C3H kontrol yazmacı.

> **Ders sonrası not:** Altyazının 00:38:43 civarında 74245 için "latch" denir. 74245 bir tampon/alıcı-verici (transceiver) entegresidir, tutucu değildir; hoca aynı yerde "buffer" kelimesini de kullanır.

## 7. Kod çözücüde iki biti birleştirme kuralı

Hoca konunun anlaşılıp anlaşılmadığını görmek için birleştirme mantığını doğruluk tablosuyla açıkladı (ekrandan, 00:45:00).

C0H örneğinde A7 ve A6'nın ikisi de 1 olduğunda cihaz seçilebilmelidir; herhangi biri 0 ise VE çıkışı 0 olur ve E3 etkin olmaz. E3 için istenen tablo şudur:

| A7 | A6 | E3 |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Bu tablo çözüldüğünde $E3 = A7 \cdot A6$ bulunur.

Aynı mantık 0 olması gereken iki bit için de kurulur. Örneğin A3 ve A2'nin ikisi de 0 olmalı ve bunlar aktif düşük E1'e bağlanmak isteniyor. Yalnız ikisi de 0 iken E1'e 0, diğer durumlarda 1 gelmelidir. Bu tablo çözüldüğünde $\overline{E1} = A3 + A2$, yani VEYA bulunur.

Kural:

- İkisi de 1 olması gereken iki değer → VE kapısı → aktif yüksek etkinleştirme ucu.
- İkisi de 0 olması gereken iki değer → VEYA kapısı → aktif düşük etkinleştirme ucu.

## 8. 8255'in çalışma modları

8255 dört farklı modda çalışabilir (ekrandan, 00:50:00):

- **Mod 0, Basic I/O:** Yalnız basit giriş ve çıkış yapılır. İşlemci `IN` ya da `OUT` verir ve 8255'in bunu yerine getirdiğini varsayarak devam eder; kontrol etmez. Giriş işleminde 8255'in uçlarındaki değerlerin hazır olduğu varsayılır ve doğrudan okunur. Çıkış işleminde değer doğrudan gönderilir ve gönderildiği varsayılır.
- **Mod 1, Strobed I/O (handshaking):** Port tek yönlü çalışır; baştan giriş ya da çıkış olarak ayarlanır ve yalnız o yönde çalışır. Basic I/O'dan farkı, verinin karşı tarafa ulaşıp ulaşmadığının el sıkışma ile denetlenmesidir. Örneğin 8255 bir strobe işareti gönderir; karşı taraf veriyi almışsa acknowledge (ack) ile bildirir ve verinin gittiği anlaşılır.
- **Mod 2, Bi-directional Bus:** Bu da bir el sıkışma modudur, ancak veri portu çift yönlüdür. Baştan yön ayarlanmaz: o portla ilgili `IN` komutu çalıştırılırsa port giriş, `OUT` komutu verilirse çıkış olarak çalışır; yön değişimi otomatiktir. Hem gönderme hem alma için el sıkışma işaretleri vardır.
- **Bit Set/Reset (BSR) modu:** İki kullanımı vardır. Birincisi basit G/Ç gibi: port C'nin herhangi bir ucu çıkış olarak ayrı ayrı 1 ya da 0 yapılabilir. İkincisi mod 1 ve mod 2'de kontrol işaretleri içindir: örneğin kesmeleri etkinleştirmek için port C'nin ilgili bitleri BSR ile 1 ya da 0 yapılır.

**Soru:** Laboratuvarlarda hangi mod kullanılacak? **Cevap:** İlk laboratuvarda mod 0, sonrakinde mod 1 kullanılacak; mod 2 ile ilgili laboratuvar sorusu yoktur.

## 9. Kontrol yazmacı: mod 0 ayarı

Kontrol yazmacı 8 bitlik bir yazmaçtır. 8255'in A1 ve A0 uçlarının ikisi de 1 olduğunda bu yazmaca erişilir. Yani 8255'in adres uçlarını 1 yapan bir adrese `OUT` ile yazılan veri kontrol yazmacına aktarılır (karede "8255 A1 = 1, A0 = 1", ekrandan, 00:55:00).

En yüksek anlamlı bit (D7) sözcüğün türünü belirler:

- D7 = 1: mod ayar komutu (mode set flag, 1 = active); mod 0, 1, 2 seçimi yapılır.
- D7 = 0: BSR modu komutu.

Kontrol sözcüğünün mod ayarı bitleri slayttaki tabloya göre şöyledir (ekrandan, 00:55:00):

| Bit | Grup | İşlev |
|---|---|---|
| D7 | — | Mod ayar bayrağı (1 = etkin) |
| D6-D5 | A | Mod seçimi: 00 = mod 0, 01 = mod 1, 1X = mod 2 |
| D4 | A | Port A: 1 = giriş, 0 = çıkış |
| D3 | A | Port C üst (PC7-PC4): 1 = giriş, 0 = çıkış |
| D2 | B | Mod seçimi: 0 = mod 0, 1 = mod 1 |
| D1 | B | Port B: 1 = giriş, 0 = çıkış |
| D0 | B | Port C alt (PC3-PC0): 1 = giriş, 0 = çıkış |

Grup A, port A ve port C'nin yüksek anlamlı 4 bitinden; grup B, port B ve port C'nin düşük anlamlı 4 bitinden oluşur. D6 ve D5 bitlerine 00 yazılırsa grup A mod 0'da çalışır. Grup A ve grup B birbirinden bağımsızdır: örneğin grup A mod 0'dayken grup B mod 1'de, ya da grup A mod 2'deyken grup B mod 0'da çalışabilir.

Mod 0 için D7 = 1, D6 D5 = 00 ve D2 = 0 olmalıdır (karede bu bitler 1, 0, 0 ve 0 olarak işaretlenmiştir, ekrandan, 01:00:00). D4 port A'nın 8 bitinin (PA0-PA7) tamamının giriş mi çıkış mı olacağını belirler; bu yön kontrol sözcüğü yazılırken baştan belirlenir ve 8255 çalıştığı sürece mod 0'da öyle kalır.

**Soru (hocadan):** Port A'ya LED bağlıysa yönü ne olmalı? **Cevap:** Çıkış; D4 = 0. Port A'ya düğme bağlıysa veri okunacağı için port giriş olmalıdır; D4 = 1 (karede "PA → LED out 0, PA → buton in 1", ekrandan, 01:00:00).

Hoca, problemlerde portların hangi yönde olduğunu açıkça söylemeyeceğini belirtti. Düğme, LED, 4x4 tuş takımı tarama, 7 parçalı gösterge gibi uygulamalarda portun basic I/O modunda çalışacağı zaten anlaşılır; yönü de bağlanan cihaza ve senaryoya göre öğrenci belirler.

Port C'nin üst yarısı (PC7-PC4) D3 ile, grup B'de port B (PB7-PB0) D1 ile, port C'nin alt yarısı (PC3-PC0) D0 ile aynı biçimde giriş ya da çıkış yapılır.

### 9.1 Mod 0'da kaç farklı yön yapılandırması vardır?

Hoca derste öğrencilere şunu sordu: hepsi mod 0'da olmak üzere 8255 giriş/çıkış yönü bakımından kaç farklı biçimde ayarlanabilir? Port A kendi başına 8 bit olarak giriş ya da çıkış, port B 8 bit olarak giriş ya da çıkış, port C'nin düşük ve yüksek 4 bitleri de ayrı ayrı giriş ya da çıkış olabilir. Dört bağımsız parçanın her biri için iki seçenek vardır:

$$2 \times 2 \times 2 \times 2 = 2^4 = 16$$

Yalnız mod 0 kullanılsa bile 8255 on altı farklı kombinasyonda ayarlanabilir. Örneğin port A giriş, port B çıkış, port C alt çıkış ve port C üst giriş bu kombinasyonlardan biridir. Benzer bir sayım mod 1 geçildiğinde de yapılacaktır; orada grup A ve grup B bağımsız çalıştığı için seçenekler yeniden incelenecektir.

## 10. Kontrol yazmacı: Bit Set/Reset modu

BSR modunun iki kullanımı tekrar hatırlatılır: port C'nin her ucunu ayrı ayrı çıkış olarak 1 ya da 0 yapmak ve mod 1, mod 2'de el sıkışma yapılandırma bitlerini ayarlamak (karede "PC her bir pinini ayrı ayrı → out 1, 0" ve "mod 1, mod 2 handshaking config bit", ekrandan, 01:05:00).

BSR sözcüğünün bitleri (ekrandan, 01:05:00):

| Bit | İşlev |
|---|---|
| D7 | BSR bayrağı: 0 = etkin |
| D6, D5, D4 | Önemsiz (don't care) |
| D3, D2, D1 | Bit seçimi (B2, B1, B0): port C'nin 0-7 numaralı ucu |
| D0 | 1 = set, 0 = reset |

Kontrol sözcüğüne en yüksek anlamlı biti 0 olarak yazılan her komut BSR komutu olarak anlaşılır. D6, D5, D4'e yazılan değerlerin işlevi yoktur. D3, D2, D1'den oluşan üç basamaklı ikilik sayı 0 ile 7 arasında bir değer alır ve port C'nin o numaralı ucunu seçer. Slayttaki bit seçme tablosunda B0 = D1, B1 = D2, B2 = D3'tür.

Derste verilen örnek: D3 = 1, D2 = 1, D1 = 0 ise $(D3\,D2\,D1)_2 = (110)_2 = 6$ olur ve port C'nin 6 numaralı ucunda işlem yapılır. Hangi işlemin yapılacağını D0 belirler: D0 = 1 yazılmışsa PC6 çıkış olarak ayarlanır ve 1 yapılır; D0 = 0 yazılsaydı PC6'da lojik 0 oluşurdu. BSR modu el sıkışma konusunda ayrıca kullanılacaktır; şimdilik basit G/Ç mantığında görülür.

Mod 0'ın özeti şöyledir: basit giriş-çıkış işlemleri içindir ve el sıkışma yoktur. Hepsi mod 0'da kullanıldığında iki adet 8 bitlik ve iki adet 4 bitlik port bulunur, herhangi biri giriş ya da çıkış olabilir ve 16 farklı kombinasyon vardır. Mod 0'da porta değer gönderildiğinde değerin yazıldığı varsayılır, tekrar kontrol edilmez.

## 11. Mod 0 örneği: 60H'den itibaren ardışık çift adresler

Hoca örneklerin sırasını şöyle verdi: önce 8255'in chip select'inin nasıl çalıştığı, sonra LED-düğme, ardından 7 parçalı gösterge ve 4x4 tuş tarama. Bu kayıtta yalnız ilk örnek tamamlanır; diğerleri aradan sonraki derse kalır. Örnek Proteus dosyaları dersin çevrimiçi sistemine konmuştur.

Laboratuvarda iki tür soruyla karşılaşılacaktır:

- Bağlantısı verilen bir devrede programlanabilir cihazın hangi adreste olduğunu bulmak.
- Cihazın adres aralığı verilip buna uygun adres çözümleme devresini tasarlamak.

### 11.1 Problem

Tahtada yazılan problem (ekrandan, 01:15:00): **60H adresinden itibaren ardışık çift adreslere 8255 yerleştirmek istiyoruz. Adres çözümleme devresini 3x8 kod çözücü kullanarak gerçekleyiniz (isolated I/O kullanılarak).**

Tasarlanan devrenin doğru olup olmadığı nasıl anlaşılır? En basit yöntem birkaç adresi denemektir (60H, 61H, 66H gibi); kesin olarak emin olmak için ise bütün adres aralığı denenmeli, kaçak olup olmadığı kontrol edilmelidir.

> **Hocanın vurgusu:** Adres çözümleme devresi verilen adreslerin (60H, 62H, 64H, 66H) hepsinde chip select üretmeli, bunlar dışındaki hiçbir adreste üretmemelidir. Yalnız bu durumda devre doğrudur. Örneğin 60H-66H için chip select üretip 80H, 82H, 84H, 86H için de üreten bir devre hatalıdır.

### 11.2 Sabit bitlerin bulunması

Her on altılık basamak dört ikilik basamakla yazılır. 60H'nin 6'sı 0110, 0'ı 0000 olur. Dört adresin ikilik yazımı (ekrandan, 01:15:00):

| Adres | A7 | A6 | A5 | A4 | A3 | A2 | A1 | A0 |
|---|---|---|---|---|---|---|---|---|
| 60H | 0 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| 62H | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 0 |
| 64H | 0 | 1 | 1 | 0 | 0 | 1 | 0 | 0 |
| 66H | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 |

Hoca aksi belirtilmedikçe isolated I/O kullanılacağını, bu yüzden sabit bitlere ek olarak M/$\overline{IO}$'nun da 0 olması gerektiğini ve bunun çözümlemeye girmesi gerektiğini vurguladı. Sabit koşullar: A7 = 0, A6 = 1, A5 = 1, A4 = 0, A3 = 0, A0 = 0, M/$\overline{IO}$ = 0. Toplam yedi değer vardır; 3'e 8 kod çözücünün altı girişi olduğu için yine ikisi birleştirilmelidir.

Kod çözücünün seçim ve etkinleştirme uçlarına farklı sinyaller farklı sırada bağlanarak aynı mantık elde edilebilir. Yalnız 60H, 62H, 64H, 66H için chip select üreten çok sayıda bağlantı vardır; çalışan herhangi biri yeterlidir.

### 11.3 Tahtadaki çözüm

Hoca kod çözücü uçlarını şöyle adlandırdı: çıkışlar $\overline{Y0}$-$\overline{Y7}$ (üstündeki çizgi aktif düşük olduklarını gösterir), seçim uçları anlam sırasına göre C, B, A (C en anlamlı), etkinleştirme uçları E1 (aktif yüksek), $\overline{E2A}$ ve $\overline{E2B}$ (aktif düşük). Kurulan bağlantı (ekrandan, 01:20:00):

- A0 ve M/$\overline{IO}$ → VEYA kapısı → $\overline{E2B}$. Yalnız ikisi de 0 iken chip select üretilmesi istendiği için birleşik sonucu aktif yüksek bir uca bağlamak anlamlı değildir; VEYA ile aktif düşük uca bağlanır.
- A3 → $\overline{E2A}$.
- A5 → E1.
- A7 → C, A6 → B, A4 → A.

Verilen aralık için C = A7 = 0, B = A6 = 1, A = A4 = 0 olur; $(CBA)_2 = (010)_2 = 2$. Chip select 2 numaralı çıkıştan çıkar; bu uç "$\overline{CS8255}$" diye etiketlenir ve 8255'in aktif düşük chip select ucuna bağlanır.

### 11.4 Yanlış adreslerde kontrol

Hoca devreyi iki yanlış adresle sınadı:

- **`OUT 70H, AL`:** 70H'nin 60H'den tek farkı A4'ün 1 olmasıdır. Diğer değerler aynı kaldığı için $(CBA)_2 = (011)_2 = 3$ olur; Y3 = 0, Y2 = 1 kalır. 8255 Y2'ye bağlı olduğu için seçilmez.
- **`OUT 61H, AL`:** Tek fark A0'ın 1 olmasıdır. VEYA kapısının çıkışı 1 olur, $\overline{E2B}$'ye 1 gelir ve kod çözücü hiç etkinleşmez; bütün çıkışlar 1 olur. Y2 = 1 olduğundan cihaz seçilmez.

Hoca bir ön koşulu da hatırlattı: 8 bitlik sabit adreslerle çalışılıyorsa adres çözümlemenin A0-A7 ile yapılması kabul edilir; 16 adres ucunun hepsini kullanmak gerekmez. Bu kabul altında kurulan devre yalnız 60H, 62H, 64H, 66H için `IN` ve `OUT` komutlarında Y2'de 0 üretir; MOV gibi bellek komutlarında ya da başka adreslerle yapılan `IN`/`OUT` işlemlerinde Y2 = 1 olur.

### 11.5 8255'in diğer bağlantıları

- Kod çözücünün Y2 çıkışı → 8255 $\overline{CS}$.
- İşlemcinin $\overline{RD}$'si → 8255 $\overline{RD}$; $\overline{WR}$'si → 8255 $\overline{WR}$.
- İşlemcinin A2'si → 8255 A1; A1'i → 8255 A0 (adresi belirleyen değişken bitler A2 ve A1'dir).
- Ardışık çift adresler olduğu için 8255'in D0-D7'si işlemcinin D0-D7'sine birebir bağlanır.

Bu çözüm pek çok olası çözümden biridir.

## 12. Proteus örneği: verilen devreden adres bulma ve benzetim

### 12.1 Devre ve 74273

Proteus'taki şablonda (ekrandan, 01:25:00) adres tutma için 74273 entegreleri kullanılmıştır. Derste tutucu (latch) olarak 74373 görülmüştü; 74273 aynı mantıkla çalışır. 74273'te CLK girişine verilen işaret, latch enable'ın karşılığıdır. Ancak 74273 yükselen kenarda tetiklenir; ALE işareti buna uyumlu olacak biçimde değiştirilmiştir. Derste görülen entegre seviye tetiklemeli, buradaki kenar tetiklemelidir. Hoca laboratuvar sorusundaki boş bırakılan bağlantıların bu örnekten hareketle görülebileceğini söyledi.

> **Ders sonrası not:** Hoca 74273'ün MR ucunu chip select, chip enable ya da output enable karşılığı olarak andı ve bu ucun lojik 1'e çekildiğini söyledi. 74273'te MR büyük olasılıkla aktif düşük temizleme (master reset) girişidir; lojik 1'e bağlanması flip-flopların sıfırlanmamasını sağlar.

<!-- BELİRSİZ: 01:07:51 civarında ALE işaretinin 74273 için nasıl "değiştirildiği" (örneğin terslendiği) altyazıdan ve karelerden net değil. -->

### 12.2 Devreden adresin bulunması

Bu kez ikinci soru tipine yönelik çözüm yapılır: verilen adres çözümleme devresinin hangi adreslerde çalıştığı bulunur. Devrede 74LS137 3'e 8 kod çözücü kullanılmıştır ve gösterim farklıdır (ekrandan, 01:25:00):

- A5 → A, A6 → B, A7 → C (seçim uçları).
- A0 → DEĞİL kapısı (U5) → E1 (aktif yüksek).
- M/$\overline{IO}$ → E2 (aktif düşük).
- A4 ve A3 → VEYA kapısı (U3) → LE (aktif düşük).
- Y3 çıkışı → CS8255.

Çözüm adımları:

- Y3 seçildiğine göre seçim uçlarında 3 oluşmalıdır: $(CBA)_2 = (011)_2$. Buradan A7 = 0, A6 = 1, A5 = 1 bulunur.
- A0 bir DEĞİL kapısından geçip aktif yüksek bir uca bağlanmıştır. Bu uçta 1 olması gerektiğine göre A0 = 0'dır.
- M/$\overline{IO}$ aktif düşük bir uca bağlıdır; demek ki M/$\overline{IO}$ = 0 olmalıdır.
- A3 ve A4 bir VEYA kapısından geçip aktif düşük bir uca bağlanmıştır. VEYA kapısı ancak iki girişi de 0 iken 0 üretir: A4 = 0, A3 = 0.
- A2 ve A1 devrede yoktur; sabitlenmemişlerdir.

8 bitlik adres A7..A0 = 0 1 1 0 0 x x 0 olur. Serbest bitlere 00, 01, 10, 11 verilince sırasıyla 60H, 62H, 64H, 66H elde edilir. Böylece önceki çözüm ters yönden de doğrulanmış olur.

Donanımın geri kalanı: işlemcinin A2'si 8255'in A1'ine, A1'i 8255'in A0'ına bağlıdır. 8255'in RESET ucu 0'dadır, böylece 8255 sürekli reset almaz. Veri uçları işlemcinin düşük anlamlı veri uçlarına bağlıdır; işlemcinin veri uçları AD olarak adlandırıldığı için 8255'in D0'ı AD0'a, ..., D7'si AD7'ye bağlanır. Bu şablonda veri uçları için ayrı bir tutucu ya da DT/$\overline{R}$, $\overline{DEN}$ denetimli tampon yoktur; hoca şimdilik bunun böyle çalıştığının kabul edilebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** 74LS137, 74LS138'e benzer bir 3'e 8 kod çözücüdür; farkı adres girişlerini tutan bir tutucu (latch) bulunmasıdır. LE (latch enable) girişi düşükken seçim girişleri geçirgendir, yükselince son değer tutulur. Bu devrede LE'yi VEYA çıkışına bağlamak, A4 = A3 = 0 olmadıkça seçim girişlerinin güncellenmemesi demektir; hoca bu ucu derste bir etkinleştirme girişi gibi yorumladı.

### 12.3 Yazılım ve benzetim

Kaynak kod sekmesindeki program şudur (ekrandan, 01:30:00):

```asm
CODE    SEGMENT PUBLIC 'CODE'
        ASSUME CS:CODE

START:
        ; Write your code here
ENDLESS:
        OUT 61H, AL
        JMP ENDLESS

CODE    ENDS
        END START
```

Bu basit COM tipi bir programdır. `END START` ile verilen etiket programın giriş adresini belirtir. ENDLESS etiketinde 61H adresine bir değer çıkılır ve tekrar ENDLESS'a dönülür; yani sürekli 61H'ye yazılır.

Kod 61H ile çalıştırıldığında A0 = 1 olur, DEĞİL kapısından sonra 0'a döner ve aktif yüksek etkinleştirme ucuna 0 gelir. Kod çözücünün bütün çıkışları 1 olur, chip select üretilmez ve 8255 çalışmaz. Veri uçlarında görülen mavi değerler işlemcinin veriyi gönderdiğini, ama cihaz etkin olmadığı için içeri alınmadığını gösterir. Gri görülen durumlar JMP komutuna karşılık gelir; orada veri hattı yüksek empedanstadır.

Aynı işlem 60H adresiyle yapıldığında cihaz seçilir ve her çalışmada gönderilen değeri içeri alır. O anda AL'de rastgele bir değer vardır, ama 8255 onu alır. Bu örnek, 8255'in chip select'inin önceki haftanın özel tasarım devrelerindeki enable ucu gibi çalıştığını gösterir.

**Soru:** Laboratuvar şablonunda 74273 bağlantıları boş mu gelecek? **Cevap:** Hoca soruyu 74273 için anladığını belirterek ilk deneylerde orasının boş gelebileceğini, sonraki deneyler programlanabilir cihazlar üzerine olduğu için orada hazır geleceğini, ancak ilk deneyde bu bağlantıyı öğrencinin yapması gerekeceğini bildiğini söyledi.

> **Ders sonrası not:** Hoca bu kısımda (01:28:34) bir kez "8253'ün D0'ı" dedi; anlatılan entegre 8255'tir.

## 13. İşletim sistemsiz programlarda sonsuz döngü

Hoca bir noktanın farkında olunmasını istedi: Sistem Programlama (SMB) dersinde yazılan programlar bir işletim sistemi tarafından çağrılacak şekilde tasarlanmıştı. Bu uygulamalarda ise işletim sistemi yoktur. Kod genellikle sürekli aynı denetimi yapacağı için sonsuz döngü olarak yazılır.

**Soru:** Sonsuz döngü yapılmazsa, yani `OUT` komutundan sonra `JMP ENDLESS` olmazsa ne olur? **Cevap:** İşlemci sonraki adreslerdeki içeriği komut olarak yürütmeye devam eder. Bu içerik rastgele komutlar üretir; işlemci bunları işleyerek ilerler, ama istenen ya da ne olduğu bilinen bir komut yürütülmez. Örneğin bellek tamamen 00 ile başlatılmışsa, 00'a karşılık gelen komut sürekli çalıştırılmaya çalışılır. Bu yüzden örneklerde mutlaka sonsuz döngü bulunur.

**Soru:** Döngü yerine HLT kullanılabilir mi? **Cevap:** Kullanılabilir, mantıklıdır. Ancak HLT ile durduktan sonra işlemciyi uyandırmak için dış donanım kesmesi vermek gerekir. Dış kesmeler henüz görülmediği için bu aşamada benzetim yeniden başlatılarak bu aşılabilir. Şimdilik pratik olan, kodları kontrollü bir sonsuz döngü hâlinde yazmaktır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00 ve 00:25:00): 8255'i 8086'nın G/Ç uzayında F8H'den itibaren ardışık çift adreslere yerleştiriniz. Sabit bitleri, kod çözücü bağlantısını, veri yolu bağlantısını ve adres haritasını veriniz.

Çözüm (derste verildi): Adresler F8H, FAH, FCH, FEH. Sabitler A7-A3 = 1, A0 = 0, M/$\overline{IO}$ = 0. A3, A4, A5 kod çözücünün seçim girişlerine; M/$\overline{IO}$ ve A0 aktif düşük E1 ve E2'ye; A7 VE A6 aktif yüksek E3'e bağlanır. $(CBA)_2 = 111 = 7$, yani Y7 $\overline{CS}$'yi sürer. İşlemcinin A2'si 8255 A1'e, A1'i 8255 A0'a bağlanır; veri D0-D7'dir. F8H port A, FAH port B, FCH port C, FEH kontrol yazmacıdır.

**Soru 2** (derste sözlü, 00:19:29 ve 00:20:57): `OUT 0F8H, AL` komutu çalışırken M/$\overline{IO}$ ve $\overline{BHE}$ hangi değerleri alır?

Çözüm (derste verildi): G/Ç işlemi olduğu için M/$\overline{IO}$ = 0. Çift adresten 8 bitlik işlem yapıldığı ve veri yolunun yüksek kısmı kullanılmadığı için $\overline{BHE}$ = 1.

**Soru 3** (ekrandan, 00:30:00 ve 00:35:00): Aynı 8255'i F9H'den itibaren ardışık tek adreslere yerleştiriniz.

Çözüm (derste verildi): Adresler F9H, FBH, FDH, FFH. Sabitler A7-A3 = 1, A0 = 1, M/$\overline{IO}$ = 0 ($\overline{BHE}$ = 0 olur). Kod çözücü bağlantısı Soru 1'deki gibidir; yalnız A0 bir DEĞİL kapısından geçip E2'ye bağlanır (ya da $\overline{BHE}$ doğrudan E2'ye bağlanır). Y7 $\overline{CS}$'dir. Veri D8-D15'tir. F9H port A, FBH port B, FDH port C, FFH kontrol yazmacıdır.

**Soru 4** (ekrandan, 00:40:00; sorumlu olunmayan kısım): 8255'i C0H'den itibaren ardışık adreslere yerleştiriniz.

Çözüm (derste verildi): Adresler C0H-C3H. Sabitler A7 = A6 = 1, A5 = A4 = A3 = A2 = 0, M/$\overline{IO}$ = 0. İşlemcinin A1, A0'ı 8255'in A1, A0'ına bağlanır. Kod çözücünün Y0 çıkışı $\overline{CS}$'dir. İki 74245 kullanılır: D0-D7 tamponunun $\overline{OE}$'si Y0 + A0, D8-D15 tamponunun $\overline{OE}$'si $\overline{BHE}$ + Y0 + $\overline{A0}$ ile sürülür.

**Soru 5** (derste sözlü, 00:58:44): Bütün portlar mod 0'da olmak üzere 8255 giriş/çıkış yönü bakımından kaç farklı biçimde ayarlanabilir?

Çözüm (derste verildi): Port A, port B, port C üst ve port C alt bağımsız olarak giriş ya da çıkış olabilir: $2^4 = 16$.

**Soru 6** (derste sözlü, 00:56:04): Port A'ya LED bağlıysa kontrol sözcüğünün D4 biti ne olmalıdır? Düğme bağlıysa?

Çözüm (derste verildi): LED için port çıkış olmalı, D4 = 0. Düğme için port giriş olmalı, D4 = 1.

**Soru 7** (ekrandan, 01:05:00): BSR modunda D3 D2 D1 = 110 ve D0 = 1 olan bir kontrol sözcüğü yazılırsa ne olur?

Çözüm (derste verildi): D7 = 0 olduğu için sözcük BSR komutudur. $(110)_2 = 6$, D0 = 1 olduğundan port C'nin 6. ucu (PC6) 1 yapılır. D6, D5, D4 önemsizdir; sözcük ikilik olarak 0XXX1101 biçimindedir.

**Soru 8** (ekrandan, 01:15:00 ve 01:20:00): 60H adresinden itibaren ardışık çift adreslere 8255 yerleştirmek istiyoruz. Adres çözümleme devresini 3x8 kod çözücü kullanarak gerçekleyiniz (isolated I/O kullanılarak).

Çözüm (derste verildi): Adresler 60H, 62H, 64H, 66H. Sabitler A7 = 0, A6 = 1, A5 = 1, A4 = 0, A3 = 0, A0 = 0, M/$\overline{IO}$ = 0. Tahtadaki çözümde A7 → C, A6 → B, A4 → A; A5 → E1; A3 → $\overline{E2A}$; A0 + M/$\overline{IO}$ → $\overline{E2B}$. $(CBA)_2 = 010 = 2$, Y2 → $\overline{CS}$. İşlemcinin A2, A1'i 8255'in A1, A0'ına; D0-D7 doğrudan bağlanır. 70H'de $(CBA)_2 = 011$ çıkar ve Y2 seçilmez; 61H'de VEYA çıkışı 1 olur ve kod çözücü etkinleşmez. Bu bağlantının yalnız 60H, 62H, 64H, 66H'de (M/$\overline{IO}$ = 0 iken) Y2 = 0 verdiği, A0-A7'nin 256 değeri python ile taranarak doğrulandı.

**Soru 9** (ekrandan, 01:25:00): Proteus şablonundaki devrede 74LS137'nin A, B, C girişlerine A5, A6, A7; E1'e A0'ın tersi; $\overline{E2}$'ye M/$\overline{IO}$; $\overline{LE}$'ye A4 + A3 bağlıdır ve Y3 8255'in $\overline{CS}$'sini sürmektedir. 8255 hangi adreslerdedir?

Çözüm (derste verildi): Y3 için A7 A6 A5 = 011; A0 = 0; M/$\overline{IO}$ = 0; A4 = A3 = 0; A2, A1 serbest. Adres 0110 0xx0, yani 60H, 62H, 64H, 66H.

**Soru 10** (derste sözlü, 01:32:32): Kodda `JMP ENDLESS` ile sonsuz döngü kurulmazsa ne olur?

Çözüm (derste verildi): İşlemci sonraki bellek içeriğini rastgele komutlar olarak yürütür; davranış belirsiz olur. `HLT` kullanılabilir ama işlemciyi uyandırmak için dış donanım kesmesi gerekir.

## Dersin Toparlaması

Bu derste 16 bitlik veri yoluna sahip 8086'ya 8 bitlik bir programlanabilir çevre biriminin (8255) bağlanmasının üç yolu incelendi. Ardışık çift adreslerde veri D0-D7 üzerinden, ardışık tek adreslerde D8-D15 üzerinden aktarılır; her ikisinde de işlemcinin A0'ı sabit kalır, 8255'in yazmaç seçimini A2 ve A1 yapar. Gerçekten ardışık adresler ise ancak iki 74245 tampon ve ek denetim lojiğiyle mümkündür. 3'e 8 kod çözücüyle çözümlemede sabit bitler bulunur, girişten fazla koşul varsa ikisi 1 olması gerekenler için VE, ikisi 0 olması gerekenler için VEYA kapısıyla birleştirilir. Doğru devre yalnız verilen adreslerde chip select üretmelidir.

Ardından 8255'in dört modu (basic I/O, strobed I/O, çift yönlü yol ve bit set/reset) tanıtıldı, kontrol yazmacının mod 0 ve BSR biçimleri bit bit açıklandı. 60H'den itibaren ardışık çift adres örneği hem tasarım hem de verilen devreden adres bulma yönünde çözüldü ve Proteus'ta 61H ile 60H adresleri karşılaştırılarak chip select'in çalışması gösterildi. Aradan sonraki derste LED-düğme, 7 parçalı gösterge ve 4x4 tuş tarama örnekleriyle devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
