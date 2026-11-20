# Ders 17 Genişletilmiş Notu: 8254 Modları, Counter Latch ve Read-Back Komutları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sayıcı ve zamanlayıcı ayrımı
- 2. 8254'ün genel özellikleri ve frekans bölme
- 3. 8254 uçları ve adresleme
- 4. Kontrol sözcüğü
- 5. Mod 0: Interrupt on Terminal Count
- 6. Mod 1: Hardware Retriggerable One Shot
- 7. Mod 2: Rate Generator ve örnek
- 8. Mod 3: Square Wave Generator ve örnek
- 9. Mod 4 ve Mod 5: Strobe modları
- 10. Sayıcının iç yapısı
- 11. Counter latch komutu
- 12. Read-back komutu
- 13. Durum baytı (status byte)
- Örnek Sorular

Dersin slayt akışı (ekrandan, 00:20:00) şöyledir: 8254 Programmable Interval Timer (PIT), 8254 iç yapısı ve uç tanımları, kontrol sözcüğü, mod 0-mod 5, counter latch komutu, read-back komutu ve durum baytı. Önceki derste modlara kadar gelinmişti; bu ders kısa bir tekrarla başlar, sonra modlara ve okuma komutlarına geçer.

## 1. Sayıcı ve zamanlayıcı ayrımı

8254 hem sayıcı (counter) hem zamanlayıcı (timer) olarak kullanılabilen yardımcı bir devredir. İkisi arasındaki fark, sayıcının CLK girişine bağlanan işaretin niteliğindedir.

Sayıcı olarak çalışmada CLK girişine bir **olay tetiklemeli (event trigger)** kare dalga bağlanır: bir olay gerçekleştiği anda bir darbe oluşur. Hoca bunu tahtada şöyle çizdi: uzun süre hiçbir olay yok, sonra bir darbe, yine uzun bir boşluk, sonra sık aralıklarla gelen darbeler. Yani darbeler arası süre düzensizdir.

Hocanın verdiği iki günlük hayat örneği:

- **Montaj hattı:** bandın iki yanına karşılıklı bir lazer alıcı ve verici konur. Ürün aradan geçerken ışın kesilir, geçtikten sonra bağlantı yeniden kurulur. Her ürün böylece bir kare darbe üretir ve sayıcı geçen ürünleri sayar.
- **Adım sayar:** ayakkabının tabanında yumuşak bir düğme olduğu düşünülür. Ayak her basıp kalktığında bir darbe oluşur, her adım bir sayma demektir.

Zamanlayıcı olarak çalışmada ise CLK girişine **sabit frekanslı** bir saat işareti bağlanır. Böylece her saat darbesinden sonra ne kadar süre geçtiği kesin olarak bilinir. Böyle bir saat kristallerle elde edilebilir: kristale basınç uygulandığında belirli bir frekansta salınım yapar; bu salınım yükseltici devrelerle alınıp eşik devrelerinden geçirilince düzgün bir kare dalga elde edilir.

Sonuç olarak sayıcı ile zamanlayıcı arasındaki temel fark, CLK ucuna bağlanan işaretin frekansı, sıklığı ve periyodik olup olmamasıdır.

## 2. 8254'ün genel özellikleri ve frekans bölme

8254'ün içinde kontrol ve haberleşme bloklarının yanında **3 bağımsız sayıcı** vardır. Her sayıcı **16 bitliktir** ve **aşağı doğru sayar (down counter)**: yüklenen değerden geriye sayar, sıfıra ulaşınca bir çıkış üretir.

Cihazın veri yolu ise 8 bittir. Bu yüzden işlemci bir sayıcıya 16 bitlik bir sayma değeri yazmak isterse bunu bir seferde yapamaz, iki seferde yapmalıdır. Hangi baytın önce alınacağı programlanabilir (bölüm 4).

Her sayıcı mod 0'dan mod 5'e kadar 6 moddan birinde programlanabilir. Sayıcıların CLK girişlerine 8 MHz'e kadar frekanslı işaretler bağlanabilir.

### 2.1 Sayıcı bir frekans bölücüdür

Hoca, sayıcıların temelde bir **frekans bölücü** olarak düşünülebileceğini vurguladı. Lojik devreler dersindeki asenkron sayıcı hatırlatıldı: en düşük anlamlı bitten alınan işaretin frekansı saat frekansının yarısı, ikinci bitten alınanınki dörtte biri, üçüncü bitten alınanınki sekizde biridir; her bit frekansı ikiye böler. 8254'te ise yüklenen değer ne ise saat frekansı o değere bölünür.

Slayttaki şekilde (ekrandan, 00:25:00) CLK girişine kare dalga uygulanan "16 bitlik sayıcı ilk değer" bloğu aşağı sayarak 0000H'ye iner; OUT çıkışı bu anda değişir.

Pratik örnek: CLK girişine 2 MHz bağlıyken 1 kHz'lik işaret isteniyorsa

$$\frac{2\times10^6}{1\times10^3} = 2000$$

olduğundan sayma değeri olarak 2000 yüklenir.

> **Hocanın vurgusu:** Sayma değerini bulmak için sayıcının bir frekans bölücü olarak çalıştığını kavramak gerekir.

8254'ün ilk IBM PC'lerde hangi işler için kullanıldığından önceki derste bahsedilmişti.

## 3. 8254 uçları ve adresleme

Slayttaki uç tanımları (ekrandan, 00:30:00):

- **CLK:** sayıcılar için saat girişi. Zamanlayıcı yapılacaksa sabit frekanslı saat, sayıcı yapılacaksa olaylardan üretilen asenkron kare dalgalar bu uçtan verilir.
- **GATE:** sayıcılar için dış kontrol ucu. Bazı modlarda GATE = 0 saymayı duraklatır, bazı modlarda GATE'ten gelen bir sinyal yeni bir sayma çevrimi başlatır.
- **OUT:** sayma işlemi bitince değişir; INTR için kullanılabilir.

Hoca, sayıcının istenen herhangi bir anda değerinin okunup yazılımla değerlendirilebileceğini de belirtti: illa sıfıra düşmesini beklemek gerekmez, kontrol edilmek istenen bir değere ulaşıldığında da işlem yapılabilir. Donanım açısından ise temel mantık, sayma değeri sıfıra düştüğünde OUT çıkışında uygun değerin üretilmesidir. OUT ucunun değeri durum baytından (status word) da okunabilir; böylece OUT ucunu donanımsal olarak izlemeden yazılımla bilgi edinmek mümkündür (bölüm 13).

OUT uçları hassas zamanlamaya dayalı kesme istekleri için kullanılabilir. Hocanın uygulama örneği: 500 elma sayıldığında bir paket tamamlanmış olacak ve paket kapatılacak; 500. saymadan sonra sayıcı temelli bir kesme isteği üretilebilir.

İki adres ucu (A1, A0) cihazın G/Ç uzayında 4 bayt yer kapladığını gösterir:

| A1 | A0 | Seçim |
|---|---|---|
| 0 | 0 | Counter 0 |
| 0 | 1 | Counter 1 |
| 1 | 0 | Counter 2 |
| 1 | 1 | Control Register |

(ekrandan, 00:30:00)

8 bitlik veri yolu nedeniyle cihaz 16 bitlik işlemciye bağlanırken derste anlaşılan ardışık çift adresler ya da ardışık tek adresler yöntemi kullanılır.

## 4. Kontrol sözcüğü

Kontrol sözcüğüne, cihaz seçiliyken A1 A0 = 11 adresine yazma yapılarak erişilir. Bit yapısı:

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|
| SC1 | SC0 | RW1 | RW0 | M2 | M1 | M0 | BCD |

- **SC1 SC0 (sayıcı seçimi):** hangi sayıcıyla işlem yapılacağını seçer. 11 değeri özel bir durumdur (read-back komutu, bölüm 12).
- **RW1 RW0 (okuma/yazma biçimi):** sayıcılar 16 bit, veri yolu 8 bit olduğu için gönderilecek ilk baytın düşük mü yüksek mi anlamlı olduğu, her ikisinin de gerekip gerekmediği buradan seçilir.
  - 01: yalnız LSB. 0-255 arası bir değer yüklenecekse kullanılır; sayıcı adresine yapılan ilk yazma ilk değeri oluşturur ve sayma başlar.
  - 11: önce LSB, sonra MSB. LSB gönderilir gönderilmez sayma başlamaz, MSB de gönderildikten sonra başlar. Örneğin 0010H yüklenecekse üst bayt 00 olsa bile mutlaka gönderilmelidir; sistem 00 gelip gelmeyeceğini bilemez.
  - 10: yalnız MSB. Değerin son iki onaltılık basamağı 00 olacaksa yalnız yüksek anlamlı bayt gönderilebilir.
  - 00: özel durum (counter latch komutu, bölüm 11).
- **M2 M1 M0 (mod):** 6 mod için 3 bit gerekir. Mod 2 ve mod 3'te M2 önemsizdir (X10 ve X11). Yani M1 M0 = 11 ise kesinlikle mod 3, 10 ise mod 2'dir. Diğer modlar 3 bitle okunur; örneğin 101 mod 5'tir.
- **BCD:** 0 ise 16 bit ikili sayma, 1 ise 16 bit BCD sayma.
  - İkili modda yazılabilecek en büyük değer FFFFH = 65535'tir; 0 da sayılırsa 65536 adım sayılabilir.
  - BCD modda her 4 bitlik basamağa en çok 1001 (9) yazılabilir; en büyük değer 9999'dur, 0 da sayılırsa 10000 adım sayılabilir.

## 5. Mod 0: Interrupt on Terminal Count

Hoca modlara geçmeden önce genel bir sınıflama yaptı: modların bir kısmı tek seferlik, bir kısmı periyodik olarak tekrarlıdır; tekrarlananlar içinde de dışarıdan tetiklemeyle tekrarlananlar ve dışarıdan tetikleme kabul etmeyenler vardır. Slayttaki mod adları (ekrandan, 00:35:00):

- Mode 0: Interrupt on Terminal Count
- Mode 1: Hardware Retriggerable One Shot
- Mode 2: Rate Generator
- Mode 3: Square Wave Generator
- Mode 4: Software Triggered Strobe
- Mode 5: Hardware Triggered Strobe

Hoca mod 0'ı önce yanlış anlattığını söyleyip düzeltti. Doğru anlatım şöyledir: kontrol sözcüğü yazılır yazılmaz OUT 0'a iner. Sonra sayma değeri gönderilir. LSB yazıldıktan sonra CLK'nin her düşen kenarında sayma değeri bir azalır. Sayma değeri 0'a ulaşınca OUT 1'e çıkar ve orada kalır. OUT'un 0'da kaldığı süre sayma süresiyle belirlenir.

GATE ile sayma etkinleştirilip durdurulabilir. GATE = 0 olursa sayma geçici olarak duraklar (sistem inhibe olur), GATE yeniden 1 olunca kaldığı yerden devam eder ve 0'a ulaşınca OUT 1'e çıkar. Bu, OUT'un 0'da kalma süresini uzatır.

Yazılan sayma değeri doğrudan sayıcının iç yazmacına yazılmaz; önce geçici bir yazmaca yazılır. CLK'nin ilk düşen kenarında geçici yazmaçtan sayıcıya aktarılır, sonraki çevrimlerde adım adım azaltılır.

### 5.1 Mod 0 dalga şekli: CW = 10

Slayttaki dalga şeklinde kontrol sözcüğü olarak 10, sayma değeri olarak LSB = 3 yazılmıştır (ekrandan, 00:40:00). Hoca 10'un onaltılık olduğunu belirleyip ikiliğe açtı (ekranda 0001 0000):

- SC1 SC0 = 00: Counter 0.
- RW1 RW0 = 01: yalnız LSB.
- M2 M1 M0 = 000: mod 0.
- BCD = 0: ikili sayma.

Yani 10H, "Counter 0'ı yalnız LSB bekleyerek mod 0'da ikili saydır" demektir.

Dalga şeklinin altındaki sayma değerleri sırasıyla N, N, N, N, 03, 02, 02, 02, 01, 00, FFFF'dir (ekrandan, 00:40:00). "N" adımları sayma değerinin henüz sayıcıya aktarılmadığı adımlardır (bölüm 6'da açıklanan null count). 3'ten saymaya başlanır; GATE'in 0'a indiği süre boyunca değer 02'de bekler, GATE 1'e dönünce 01 ve 00'a iner ve OUT 1'e çıkar.

<!-- BELİRSİZ: 00:40:56 altyazıda "60 olduğumuz config word" geçiyor; slayttaki değer CW = 10 olduğu için 10H olarak yazıldı. -->

### 5.2 Yeniden başlatma

Yeni bir çevrim ancak yeni bir sayma değeri yüklenerek ya da yeni bir kontrol sözcüğü ve ardından sayma değeri yazılarak başlatılır. Bu yüzden mod 0 yalnız yazılımla tekrarlanabilen tek seferlik bir moddur. Önceki sayma bitmeden yeni değer yüklenirse sayma süresi uzar; hoca bunun ayrıntı olduğunu, çok önemli olmadığını söyledi.

## 6. Mod 1: Hardware Retriggerable One Shot

Mod 1 tekrarlanabilir bir işlemdir ve GATE ile tetiklenir; adı da bunu söyler: "Hardware Retriggerable". Mod 0 yalnız yazılımla yeniden tetiklenebiliyordu; mod 1'de sayma GATE ucu üzerinden yeniden başlatılabilir. Hoca mod 1'i, mod 0'ın GATE ucundan yeniden tetiklenebilir versiyonu olarak özetledi.

Dalga şekli şöyledir: boştayken OUT 1'dedir. GATE tetiklenince OUT 0'a iner, sayma süresince 0'da kalır, sayma bitince 1'e çıkar ve orada kalır. İstenirse bir süre sonra GATE'ten yeniden sinyal verilerek işlem tekrar başlatılır.

Dalga şekillerinde "N" ile gösterilen adımlar **null count** adımlarıdır: kontrol sözcüğü yazılmış ama sayma değeri henüz yüklenmemiş ya da sayıcıya aktarılmamıştır, dolayısıyla sayma başlamamıştır.

### 6.1 Mod 1 dalga şekli: CW = 12

Slayttaki örnekte CW = 12, LSB = 3'tür (ekrandan, 00:45:00). 12H = 00 01 001 0, yani Counter 0, yalnız LSB, mod 1, ikili sayma. Mod 0 örneğinden tek farkı mod bitleridir.

Sayma değeri 3 yüklendiği halde sayma başlamaz; GATE'ten tetik beklenir. Tetik geldiğinde OUT 0'a iner, 03, 02, 01, 00 diye sayılır, sayma bitince OUT 1'e çıkar. Slaytta değerler N, N, N, N, N, 03, 02, 01, 00, FFFF, 03, 02 diye ilerler: ikinci GATE darbesiyle aynı değerle (3) sayma yeniden başlar (ekrandan, 00:45:00).

Sayma sırasında yeni bir sayma değeri yazılırsa bu hemen etkili olmaz; bir sonraki tetikten sonra geçerli olur.

> **Ders sonrası not:** Hoca mod 1'de saymanın GATE'in "sıfır geçişinde, düşen kenarda" (00:45:49) ve "1-0 geçişinde" (00:55:21) başladığını söyledi. Slayttaki dalga şeklinde OUT, GATE darbesinin yükselen kenarından sonra 0'a iner; 8254 veri sayfasında da mod 1 ve mod 5'in tetiği GATE'in yükselen kenarıdır (0→1). Hocanın mod 5 için söylediği "0-1 geçişi" doğrudur.

## 7. Mod 2: Rate Generator ve örnek

Mod 2 periyodik olarak tekrarlanan bir moddur ve tetiğe ihtiyaç duymaz: yazılımla ayarlanır ve kendiliğinden tekrarlar. Sayma süresince OUT 1'dedir; sayma son değere gelince bir CLK süresi boyunca 0'a iner, sonra yeniden 1'e çıkar ve aynı değerle tekrar sayar. Böylece bir CLK süresi uzunluğunda **aktif sıfır darbeler** üretir. GATE'ten tetikleme yapılamaz, ama GATE saymayı durdurabilir.

> **Ders sonrası not:** Hoca 00:47:31'de bir CLK'lik 0 darbesinden sonra OUT'un "tekrar sayma süresi boyunca sıfırda" kaldığını söyledi. Doğrusu, sayma süresi boyunca OUT 1'de kalır; hoca hemen sonra şekli de bu biçimde çizdi (uzun süre 1, bir CLK 0).

Slayttaki örnekte CW = 14H (mod 2) ve sayma değeri 3'tür: kontrol sözcüğü ve sayma değeri yazıldıktan sonra 3, 2, 1 diye sayılır, bir CLK boyunca OUT 0 olur, sonra aynı değerle darbe üretmeye devam eder. Bir çevrim sürerken yeni bir sayma değeri yazılırsa bu bir sonraki çevrimden itibaren geçerli olur. Hoca bu dalga şekli ayrıntılarıyla daha fazla ilgilenilmeyeceğini belirtti.

### 7.1 Mod 2 örneği: 50 µs'de bir darbe

Soru (ekrandan, 00:50:00): CNTR0'ı 50 µs'de bir darbe üretecek şekilde ayarlayın. CLK0 = 2 MHz.

Çözüm hocanın anlatımıyla şöyle kurulur:

1. **Sayıcı ve mod belli:** Counter 0 kullanılacağı için SC = 00. Aktif sıfır darbe katarı üretileceği için mod 2 seçilir: M2 M1 M0 = 010. RW ve BCD bitleri sayma değerine bağlıdır, önce sayma değeri bulunur.
2. **Birimleri eşleştir:** CLK frekans (Hz, saniyedeki değişim sayısı) olarak, darbe aralığı ise periyot olarak verilmiştir; doğrudan karşılaştırılamaz. Önce periyottan frekans bulunur: $f = 1/T$. Mikro $10^{-6}$ olduğundan $T = 50\times10^{-6}$ s ve
   $$f = \frac{1}{50\times10^{-6}} = 20\,000 \text{ Hz} \text{ (ara adım eklendi)}$$
3. **Bölme oranı:** Mega $10^6$ olduğundan
   $$\text{Sayma değeri} = \frac{2\times10^6}{\left(\frac{1}{50\times10^{-6}}\right)} = 100 = 64\text{H}$$
4. **RW ve BCD:** 100 sekiz bite sığdığı için yalnız LSB göndermek yeterlidir: RW1 RW0 = 01. Değer onlu 100 ya da onaltılık 64 olarak gönderilebilir; ikili sayma seçmekte bir sakınca yoktur: BCD = 0.
5. **Kontrol sözcüğü:** 00 01 010 0 B = 14H.

Kod (ekrandan, 00:55:00):

```asm
MOV AL, 14H
OUT CONTROL_ADDRESS, AL
MOV AL, 64H
OUT CNTR0_ADDRESS, AL
```

Önce kontrol değeri AL'ye yüklenip `OUT` ile kontrol adresine yazılır. Ardından cihaz bir sayma değeri bekler.

> **Hocanın vurgusu:** Sayma değeri kontrol adresine değil, sayıcının kendi adresine (burada Counter 0 adresine) gönderilmelidir.

Hoca bu noktada mod 0, 1 ve 2'yi şöyle özetledi: mod 0 ve mod 1 tek seferlik işlemlerdir; mod 0 yazılımla yeni sayma değeri yüklenince, mod 1 GATE ucundan tetik gelince yeniden başlar. Mod 2 periyodik bir işlemdir.

## 8. Mod 3: Square Wave Generator ve örnek

Mod 3 kare dalga üretmek için kullanılır. Sayma değeri yüklenip mod 3 ayarlandığında sayma süresinin yarısında OUT bir düzeyde, kalan yarısında öteki düzeyde kalır; yaklaşık %50 görev oranlı (duty cycle) bir kare dalga elde edilir. Yüklenen değer tekse tam ikiye bölünemez; OUT'un 1'de kaldığı süre bir CLK fazla olur. Örneğin 5 yüklenirse 3 CLK boyunca 1'de, 2 CLK boyunca 0'da kalır. GATE = 0 iken sayma duraklar.

Mod 2 ile mod 3'ün ikisi de periyodiktir. Farkları şudur: mod 2'de işaret yalnız bir CLK süresi 0'da kalır, mod 3'te sürenin yaklaşık %50'sinde 1, %50'sinde 0'dadır.

Slayttaki dalga şeklinde kontrol sözcüğü 16H'dir: 00 01 011 0, yani Counter 0, yalnız LSB, mod 3, ikili sayma. Sayma değeri yüklenince sürecin yarısında OUT 0, yarısında 1 olur.

<!-- BELİRSİZ: 00:55:33 hoca önce yarı sürede OUT'un 0'da, kalan yarıda 1'de kaldığını söyledi; tek değer örneğinde ise 1'de kalma süresini uzun verdi. Mod 3 dalga şeklinin karesi yok; dalganın 1 ile mi 0 ile mi başladığı ekrandan doğrulanamadı. -->

### 8.1 Mod 3 örneği: 1 kHz kare dalga

Soru (ekrandan, 01:00:00): CNTR1'i 1 kHz frekansında kare dalga üretecek şekilde ayarlayın. CLK1 = 2 MHz.

1. **Sayma değeri:** frekans bölücü mantığıyla
   $$\frac{2\times10^6}{1\times10^3} = 2000$$
2. **Sayıcı:** Counter 1, SC = 01.
3. **RW:** 2000 sekiz bite sığmaz, 16 bit gönderilir: önce LSB, sonra MSB, RW = 11.
4. **Mod:** mod 3, M = 011.
5. **BCD:** bu sefer BCD sayma seçildi: BCD = 1.
6. **Kontrol sözcüğü:** 01 11 011 1 B = 77H. Slaytta "CNTR1 seç, önce LSb sonra MSb, BCD sayma" yazar.

Ekrandaki kod (ekrandan, 01:00:00), hocanın derste yaptığı düzeltmeyle birlikte:

```asm
MOV AL, 77H
OUT CNTROL, AL
MOV AX, 2000H
OUT CNTR1, AL
MOV AL, AH
OUT CNTR1, AL
```

Kontrol adresinin değeri bu örnekte bilinmiyor; sistemden hesaplanabilir. Sayma değeri AX'e alınır, önce AL (düşük bayt) Counter 1 adresine yazılır, sonra yüksek bayt AL'ye taşınıp yine aynı adrese yazılır. Ekrandaki ilk yazımda beşinci satır `MOV AH, AL` idi; hoca 01:03:30'da AL'ye AH'ın taşınması gerektiğini söyleyerek bunu `MOV AL, AH` olarak düzeltti.

Hoca burada sınıfa şunu sordu: bu ayarlarla 2000H yüklendi, sayıcı kaç adım sayar? Cevap: BCD modda saydırıldığı için 2000 adım. BCD modda saydırmak isteniyorsa onlu değerin basamakları onaltılık basamaklar olarak gönderilmelidir; 2000H'nin her basamağı zaten geçerli bir BCD basamağıdır.

### 8.2 Aynı sonucu veren üç yol

Hoca aynı 1 kHz kare dalgayı üreten üç kodu karşılaştırdı:

1. **BCD mod, 2000H:** kontrol sözcüğü 77H; sayıcıya 2000H yazılır. BCD modda 2000 adım sayar.
2. **İkili mod, onlu 2000:** kontrol sözcüğü 76H (BCD biti 0); sayıcıya onlu 2000 yazılır. 2000 adım sayar.
3. **İkili mod, 07D0H:** kontrol sözcüğü 76H; 2000'in onaltılık karşılığı hesap makinesiyle 7D0H bulunur ve sayıcıya 07D0H yazılır. Yine 2000 adım sayar.

Üç kodda da 16 bitlik değer AX'e alınır, `OUT CNTR1, AL`, `MOV AL, AH`, `OUT CNTR1, AL` sırası kullanılır. Hoca duruma göre hangisi gerekiyorsa onun kullanılabileceğini söyledi.

<!-- BELİRSİZ: 01:00:41-01:03:43 arasında yazılan ikinci ve üçüncü kodun karesi yok; kontrol sözcüğü 76H ve değerler altyazıdan alındı, satırların tam yazımı ekrandan doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** İkili modda 2000H yazılsaydı sayıcı 2000H = 8192 adım sayardı ve çıkış 1 kHz yerine yaklaşık 244 Hz olurdu. BCD biti, aynı bit dizisinin onlu mu onaltılık mı yorumlanacağını belirler.

## 9. Mod 4 ve Mod 5: Strobe modları

Hoca mod 4'ü mod 2'nin tek seferlik hali, mod 5'i de mod 4'ün dışarıdan tetiklenebilir hali olarak tanıttı. Mod 2'de bir darbe katarı üretiliyordu; mod 4'te tek bir darbe üretilir.

Mod 4 slaytı (ekrandan, 01:05:00):

- OUT başta 1.
- Sayma değeri 1 olunca OUT 1 → 0.
- 1 CLK sonra OUT 0 → 1 olur ve kalır.
- Yeni sayma değeri yazılmadıkça tekrarlamaz.
- GATE = 0 ise sayma duraklar.

Kontrol sözcüğü ve sayma değeri yazılınca sayma başlar, sayma sona erince bir CLK boyunca 0'a iner, sonra 1'de kalır. GATE 0'a inseydi sayma geçici olarak duraklatılacaktı.

Mod 5 mod 4'ün aynısıdır, ama sayma GATE ucundan gelen bir 0→1 geçişiyle başlar. Kontrol sözcüğü ve sayma değeri yazıldıktan sonra GATE'ten ilk tetik geldiğinde sayma başlar, bitince tek bir darbe üretilir. Yeniden tetik gelirse işlem bir kez daha tekrarlanır.

| Mod | Ad | Tekrar | Yeniden başlatma |
|---|---|---|---|
| 0 | Interrupt on Terminal Count | Tek seferlik | Yazılım (yeni sayma değeri) |
| 1 | Hardware Retriggerable One Shot | Tek seferlik | GATE tetiği |
| 2 | Rate Generator | Periyodik (1 CLK'lik 0 darbe) | Kendiliğinden |
| 3 | Square Wave Generator | Periyodik (%50 kare dalga) | Kendiliğinden |
| 4 | Software Triggered Strobe | Tek darbe | Yazılım (yeni sayma değeri) |
| 5 | Hardware Triggered Strobe | Tek darbe | GATE tetiği |

## 10. Sayıcının iç yapısı

Hoca üç sayıcıdan birinin iç blok yapısını gösterdi:

- **Count element (CE):** sayma işlemini fiziksel olarak yapan birimdir.
- **Output latch yazmaçları (OL, iki adet 8 bit):** CE'nin o anki değeri istenen bir anda bu iki yazmaca kopyalanabilir ve sonra okunabilir. Bu sırada CE saymaya devam eder; bu yazmaçlar yalnız anlık değeri not etmeye yarar.
- **Counter register'lar (CR):** sayıcıya yazılan yeni değer doğrudan CE'ye gitmez, önce CR'lere yazılır. LSB gönderilince düşük anlamlı CR'ye, MSB gönderilince yüksek anlamlı CR'ye yazılır. Sayma çevrimi bitince (ya da moda göre uygun anda) CR'lerden CE'ye aktarılır.
- **Status register ve status latch:** asıl durum yazmacı ayrıdır; sayıcı bazı işlemlerini bu yazmaca göre yapar. Dışarıdan okunan değer ise bu yazmacın o anki kopyasını tutan status latch'ten gelir.

## 11. Counter latch komutu

Counter latch komutu, CE'nin anlık değerinin OL yazmaçlarına kopyalanmasını sağlar. İşlemci bu değerleri istediği zaman OL'den okuyabilir.

Komut formatı (ekrandan, 01:10:00): A1 A0 = 11; $\overline{CS}$ = 0; $\overline{RD}$ = 1; $\overline{WR}$ = 0 iken

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|
| SC1 | SC0 | 0 | 0 | X | X | X | X |

SC1 SC0 latch'lenecek sayıcıyı belirtir: 00 Counter 0, 01 Counter 1, 10 Counter 2, 11 read-back komutu. D5 D4 = 00 counter latch komutunu belirtir. Kontrol sözcüğü incelenirken "özel durum" denen RW = 00 durumu budur.

Bu değer kontrol yazmacına yazıldığı anda sayıcının o anki sayma değeri OL'ye kopyalanır. Ardından ilgili sayıcının adresinden okuma yapılınca kopyalanan değer alınır.

Okuma sırası, sayıcı ilk programlanırken seçilen RW biçimiyle aynıdır: yalnız LSB, yalnız MSB ya da önce LSB sonra MSB. Örneğin sayıcı 16 bit için önce LSB sonra MSB olarak ayarlandıysa, ilk okunan 8 bit LSB'ye, ikinci okunan MSB'ye karşılık gelir.

<!-- BELİRSİZ: 01:10:42 altyazıda "counter 0 için 0, counter 1 için 0" geçiyor; seçim kodları slayttan (00, 01, 10) alındı. -->

## 12. Read-back komutu

Read-back komutu, sayma değerini ve istenirse sayıcının durumunu latch'leyebilen bir komuttur. Counter latch yalnız OL'de değer oluştururken read-back hem OL'de hem status latch'te değer oluşturabilir. Böylece bir sayıcı için toplam 3 adet 8 bitlik yazmaç (OL'nin iki baytı ve status latch) okunabilir; okuma sırası belirli bir kurala bağlıdır.

Slayttaki maddeler (ekrandan, 01:15:00):

- Latch'lenmiş sayma değerini veya sayıcı durumunu (STATUS) okumak için kullanılır.
- Birden fazla sayıcı için sayma değeri/durumu bir seferde okumak için kullanılabilir.
- Bir sayıcıya ilişkin hem sayma hem durum okumak için komut verilirse:
  - Sayıcı adresinden ilk okuma durum,
  - İkinci (ve üçüncü) okuma latch'lenmiş sayma değeri,
  - Sonraki okumalar latch'lenmemiş sayıcı değerlerini verir.

> **Hocanın vurgusu:** Hem durum hem sayma latch'lendiyse önce durum, sonra sayma değeri okunur. Sayma değeri iki baytsa önce LSB, sonra MSB; tek baytsa hangi biçimde programlandıysa o biçimde okunur.

Komut bitleri hocanın anlatımıyla:

- D7 D6 = 11: read-back komutu.
- D5 = 0: sayma değerini latch'le (aktif sıfır).
- D4 = 0: durumu latch'le (aktif sıfır).
- D3, D2, D1: sırasıyla Counter 2, Counter 1, Counter 0'ı seçer.

Örneğin D7 D6 = 11, D5 D4 = 00, D3 D2 D1 = 111 verilirse üç sayıcının hem durumu hem sayma değeri tek komutla latch'lenir.

Bir sayıcı için durum ya da sayma bir kez latch'lendiyse, okunmadan verilen yeni latch komutu çalışmaz. Slayttaki tablo birden fazla latch işleminin sonucunu bu şekilde özetler; hoca ayrıntısına bakılmasını önerdi.

> **Ek bilgi (derste anlatılmadı):** 8254 veri sayfasında read-back komutunun D0 biti 0 olmalıdır. Üç sayıcının hem durumunu hem sayma değerini latch'leyen komut buna göre 11 00 111 0 B = CEH olur.

## 13. Durum baytı (status byte)

Durum baytının yapısı (ekrandan, 01:20:00):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|
| OUTPUT | NULL COUNT | RW1 | RW0 | M2 | M1 | M0 | BCD |

- D7 = 1: OUT ucu 1; D7 = 0: OUT ucu 0.
- D6 = 1: null count; D6 = 0: sayma değeri okunabilir.
- D5-D0: sayıcının programlandığı mod (kontrol sözcüğündeki RW, mod ve BCD bitleri).

Hoca önce durum baytının kontrol sözcüğü adresinden okunduğunu söyledi, sonra bunu düzeltti: durum baytı, read-back komutuyla ilgili sayıcının durumu latch'lendikten sonra **o sayıcının adresinden** yapılan okumada elde edilir. Bu yüzden içindeki RW, mod ve BCD bilgileri o sayıcıya aittir ve o sayıcının OUT ile null count durumu buradan görülür.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Mod 0 dalga şeklinde kontrol sözcüğü olarak 10 gönderilmiştir. Bu değerin anlamı nedir?

Çözüm (derste verildi): 10H = 0001 0000 B. SC = 00 Counter 0, RW = 01 yalnız LSB, M = 000 mod 0, BCD = 0 ikili. Counter 0, yalnız 8 bitlik LSB bekleyerek mod 0'da ikili sayar.

**Soru 2** (ekrandan, 00:50:00): CNTR0'ı 50 µs'de bir darbe üretecek şekilde ayarlayın. CLK0 = 2 MHz.

Çözüm (derste verildi): Mod 2 seçilir. Sayma değeri $\dfrac{2\times10^6}{1/(50\times10^{-6})} = 100 = 64\text{H}$, 8 bite sığdığı için yalnız LSB. Kontrol sözcüğü 00 01 010 0 B = 14H. Kod: `MOV AL, 14H`, `OUT CONTROL_ADDRESS, AL`, `MOV AL, 64H`, `OUT CNTR0_ADDRESS, AL`.

**Soru 3** (ekrandan, 01:00:00): CNTR1'i 1 kHz frekansında kare dalga üretecek şekilde ayarlayın. CLK1 = 2 MHz.

Çözüm (derste verildi): Mod 3. Sayma değeri $2\times10^6 / 1\times10^3 = 2000$; 16 bit, önce LSB sonra MSB. BCD sayma ile kontrol sözcüğü 01 11 011 1 B = 77H, sayıcıya 2000H yazılır. İkili sayma tercih edilirse kontrol sözcüğü 76H, sayıcıya onlu 2000 ya da 07D0H yazılır.

**Soru 4** (derste sözlü, 00:59:17): Kontrol sözcüğü 77H iken sayıcıya 2000H yüklendi. Sayıcı kaç adım sayar?

Çözüm (derste verildi): BCD modda sayıldığı için 2000 adım.

**Soru 5** (derste sözlü, 00:56:56): Mod 3'te sayma değeri olarak 5 yüklenirse OUT kaç CLK 1'de, kaç CLK 0'da kalır?

Çözüm (derste verildi): Tek değer tam bölünemediği için 1'de kalma süresi bir CLK fazladır: 3 CLK 1'de, 2 CLK 0'da.

## Dersin Toparlaması

Bu derste 8254'ün sayıcı ile zamanlayıcı olarak kullanımı, frekans bölücü mantığı, uçları ve kontrol sözcüğü tekrar edildikten sonra altı modu dalga şekilleriyle incelendi. Mod 0 ve mod 4 yazılımla, mod 1 ve mod 5 GATE tetiğiyle yeniden başlatılan tek seferlik modlardır; mod 2 bir CLK'lik aktif sıfır darbe katarı, mod 3 yaklaşık %50 görev oranlı kare dalga üreten periyodik modlardır. Mod 2 ve mod 3 örneklerinde sayma değerinin CLK frekansının istenen frekansa bölünmesiyle bulunduğu, kontrol sözcüğünün kontrol adresine, sayma değerinin sayıcı adresine yazıldığı ve BCD/ikili seçimin yüklenecek değerin yazımını nasıl değiştirdiği görüldü.

Dersin son kısmında sayıcının iç yapısı (CE, CR, OL, status latch), anlık sayma değerini kopyalayan counter latch komutu, sayma ve durum değerlerini birden fazla sayıcı için latch'leyebilen read-back komutu ve sayıcı adresinden okunan durum baytı anlatıldı. Bir sonraki derste 8254 ile iki uygulama örneği yapılacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
