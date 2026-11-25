# Ders 11 Çalışma Özeti

## Genel Konular

- G/Ç birimleri için adres çözümleme (address decoding): temel çerçeve
  - CPU; RAM, ROM ve G/Ç birimleriyle ortak bir yol üzerinden bağlıdır ve bir anda yalnız bir cihazla konuşur. Hangi cihazın konuşacağını adres çözümleme devresi belirler: adres yolundaki değer hangi cihazın adres aralığındaysa yalnız o cihazın seçim (chip select, $\overline{CS}$) ucu etkin yapılır.
  - Bellek birimlerinin 10-15 civarında adres ucu vardır ve 10-100 KB mertebesinde blok kaplarlar. G/Ç birimlerinin ise 1 ya da 2 adres ucu vardır; G/Ç uzayında 2 ya da 4 byte yer kaplarlar. Bu yüzden G/Ç birimleri için ayrı bir adres çözümleme devresi kurulur.
  - Örneklerdeki mikroişlemci 8 bit veri yoluna sahiptir; bellek ve G/Ç uzayını ×8 genişlikte görür.
- PPI (paralel programlanabilir arayüz) cihazı (ekrandan, 00:15:00)
  - 8 bitlik veri ucu ($D_0$-$D_7$), iki adres ucu ($A_1$, $A_0$), $R/\overline{W}$ denetim ucu, aktif 0 $\overline{CS}$ ucu ve dışarıya açılan PA, PB, PC portları vardır.
  - İç yazmaç seçimi: $A_1A_0 = 00$ Port A yazmacı, $01$ Port B, $10$ Port C, $11$ denetim/durum yazmacı. $11$ adresine yazma denetim yazmacına (port yönleri gibi yapılandırma bitleri), okuma durum yazmacına (strobe gibi durum bitleri) erişir.
- $M/\overline{IO}$ ucu (ekrandan, 00:25:00)
  - Mikroişlemcinin ürettiği bu uç, yürütülen işlemin bellek mi G/Ç mı olduğunu belirtir: `MOV` gibi bellek komutlarında 1, `IN`/`OUT` komutlarında 0 olur.
  - Bellek uzayında da G/Ç uzayında da aynı (örneğin 80H) adres bulunabileceği için G/Ç adres çözümlemesine $M/\overline{IO} = 0$ koşulu mutlaka katılır.
- 3x8 dekoder (74138 tipi) ile çözümleme
  - Seçim uçları C (en anlamlı), B, A; etkinleştirme uçları $E_1$ (aktif 1), $\overline{E_{2A}}$ ve $\overline{E_{2B}}$ (aktif 0); çıkışlar $\overline{Y_0}$-$\overline{Y_7}$ aktif 0'dır. Dekoder seçilmezse bütün çıkışlar 1 olur.
  - Sabit olması gereken adres bitleri etkinleştirme uçlarına, cihazları birbirinden ayıran bitler seçim uçlarına bağlanır. Uç sayısı yetmezse aynı aktiflikteki iki koşul bir kapıyla birleştirilir: iki "0 olmalı" koşulu OR kapısıyla aktif 0 uca, iki "1 olmalı" koşulu AND kapısıyla aktif 1 uca (ya da NAND ile aktif 0 uca) bağlanır.
- Örnek 1: 80H-83H aralığına tek PPI (ekrandan, 00:25:00 ve 00:35:00)
  - $A_1, A_0$ dört yazmacı seçtiği için PPI'nin adres uçlarına gider. $\overline{CS}$ için $A_7 = 1$, $A_6 = A_5 = A_4 = A_3 = A_2 = 0$, $M/\overline{IO} = 0$ gerekir.
  - Çözüm: C = $A_3$, B = $A_2$, A = $M/\overline{IO}$; $E_1 = A_7$; $\overline{E_{2A}} = A_6$; $\overline{E_{2B}} = A_5 + A_4$ (OR). $\overline{CS}_{PPI} = \overline{Y_0}$.
  - Mikroişlemcinin $A_1$/$A_0$ uçları PPI'ye ters sırayla bağlanırsa 81H Port C'ye, 82H Port B'ye denk gelir. Kural: adres uçlarının anlam sırası bağlantıda korunur ($A_1 \to a_1$, $A_0 \to a_0$); böylece 80H Port A, 81H Port B, 82H Port C, 83H denetim/durum olur.
- Örnek 2: A8H'den PPI1, B0H'den PPI2 (ekrandan, 00:45:00 ve 00:50:00)
  - PPI1: A8H-ABH, PPI2: B0H-B3H. İki cihazı ayıran bitler $A_4$ ve $A_3$'tür, bunlar mutlaka seçim uçlarına bağlanır.
  - Çözüm: C = $A_4$, B = $A_3$, A = $M/\overline{IO}$; $E_1 = A_7 \cdot A_5$ (AND); $\overline{E_{2A}} = A_6$; $\overline{E_{2B}} = A_2$. $\overline{CS}_{PPI1} = \overline{Y_2}$ (010), $\overline{CS}_{PPI2} = \overline{Y_4}$ (100).
  - İki cihazın seçimi karşılıklı dışlayandır; ikisi aynı anda seçilemez.
- Örnek 3: farklı boyutlu iki cihaz, A8H'den UART, 80H'den PPI (ekrandan, 01:25:00 - 01:35:00)
  - UART (seri haberleşme birimi) tek adres ucuna sahiptir, 2 byte kaplar (A8H-A9H); adres ucuna $A_0$ bağlanır. PPI 4 byte kaplar (80H-83H).
  - Alternatif 1 (2 byte çözünürlük): seçim uçları $A_5, A_3, A_1$; $E_1 = A_7$, $\overline{E_{2A}} = A_6 + A_4$, $\overline{E_{2B}} = A_2 + M/\overline{IO}$. $\overline{CS}_{UART} = \overline{Y_6}$; PPI'nin iki yarısı $\overline{Y_0}$ (80-81H) ve $\overline{Y_1}$ (82-83H) bir AND kapısıyla birleştirilir (herhangi biri 0 iken 0 üretir). Aktif 1 çıkışlı dekoder ve aktif 1 $CS$ olsaydı OR kapısı kullanılırdı (alternatif 1b).
  - Alternatif 2 (4 byte çözünürlük): seçim uçları $A_5, A_3, A_6$; $E_1 = A_7$, $\overline{E_{2A}} = A_4 + A_2$, $\overline{E_{2B}} = M/\overline{IO}$. $\overline{CS}_{PPI} = \overline{Y_0}$; $\overline{Y_6}$ A8H-ABH'yi seçer, $\overline{Y_6} + A_1$ (OR) ile aralık A8H-A9H'ye daraltılır ve $\overline{CS}_{UART}$ elde edilir.
  - Daha karmaşık adres aralıklarında dekoder yerine PAL, PLA gibi programlanabilir lojik entegreler kullanılır.
- Bellek hiyerarşisi ve önbellek (cache) (ekrandan, 01:45:00 ve 01:50:00)
  - Hiyerarşi: yazmaçlar, önbellek, ana bellek, ikincil bellek (manyetik disk, CD, DVD). CPU'ya yaklaştıkça kapasite azalır, erişim süresi kısalır, birim maliyet artar.
  - Çok çekirdekli işlemcilerde her çekirdeğin kendine ait L1 ve L2 önbelleği, bütün çekirdeklerin paylaştığı bir L3 önbelleği vardır. Ayrıca komut önbelleği (instruction cache) ve veri önbelleği (data cache) ayrılabilir.
  - Önbellek programların yerellik özelliğine dayanır: dizi elemanları gibi ardışık adreslere erişim uzamsal yerellik (spatial locality), toplam değişkeni gibi aynı hücreye tekrar tekrar erişim zamansal yerellik (temporal locality) örneğidir. Erişilen adresin komşuluk bloğu topluca önbelleğe taşınır.
  - Disk ile ana bellek arasındaki benzer düzen sanal bellektir (virtual memory): program kendi sanal adres uzayına sahiptir, sayfalar ana belleğe yüklenir; yer yoksa en eski yüklenen, en uzun süre kullanılmayan ya da en az sıklıkla kullanılan sayfa çıkarılır.
  - İşlemci performansı kabaca 10 yılda 10 kat artarken bellek teknolojisi bu hızda ilerlemez; bellek hiyerarşisi bir darboğaz olur.
- Önbellek eşleme yöntemleri (ekrandan, 02:15:00 - 02:45:00)
  - Yerleştirme mantığı ile arama mantığı birbirine bağlıdır.
  - Tam ilişkili (fully associative): blok önbellekteki ilk boş yere konur, bloğun tamamı için geniş bir ayırt edici adres alanı (tag) saklanır. Aramada bütün satırlara bakmak gerekir (yavaş). Önbellek doluysa FIFO (en eski yerleştirilen) ya da LRU (en uzun süredir erişilmeyen) veri çıkarılır.
  - Doğrudan eşlemeli (direct mapped): adresin düşük anlamlı kısmı satır indisidir, geri kalan yüksek anlamlı kısım tag olarak saklanır. Tek satıra bakmak yeter (hızlı), ama aynı indise düşen adreslere sırayla erişilirse önbelleğin yalnız bir satırı kullanılır.
  - Küme ilişkili (set associative): yatayda tam ilişkili, dikeyde doğrudan eşlemeli çalışır; aynı indise düşen birkaç blok bir satırda yan yana tutulabilir.
  - Adres alanları: tag | index | word offset | byte offset.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adres çözümleme konusu önemlidir.
  - Hoca dersin sonunda bu konunun önemli olduğunu iki kez söyledi.
- A8H'den sonra gelen adres A9H, AAH, ABH'dir; B0H değil.
  - Hoca bunun sınavlarda en çok yapılan hata olduğunu belirtti.
- İki cihazı birbirinden ayıran adres bitleri mutlaka dekoderin seçim uçlarına bağlanmalıdır.
  - Bu bitler etkinleştirme uçlarına konursa iki farklı seçim çıkışı elde edilemez.
- Adres uçlarının anlam sırası bağlantıda korunmalıdır.
  - Ters bağlantı da çalışır ama port adresleri beklenen sırada olmaz (81H Port C'ye denk gelir).
- Direct mapped önbellekte tag alanı zorunludur.
  - Birden çok bellek adresi aynı satıra düştüğü için satırdaki verinin hangi adresten geldiği ancak tag ile anlaşılır.

## Kısa Tekrar Notları

- G/Ç adres çözümlemesine $M/\overline{IO} = 0$ koşulu katılır.
- 4 byte kaplayan cihazda $A_1, A_0$, 2 byte kaplayanda $A_0$ cihazın adres uçlarına gider; geri kalan bitler çözümleme devresine girer.
- 3x8 dekoderde sabit bitler $E_1$ (1 olmalı) ve $\overline{E_{2A}}$, $\overline{E_{2B}}$ (0 olmalı) uçlarına, ayırt edici bitler C, B, A'ya gider.
- İki "0 olmalı" koşulu OR, iki "1 olmalı" koşulu AND ile birleştirilir.
- Aktif 0 çıkışların birleştirilmesi (herhangi biri seçilince seçim) AND kapısıyla yapılır; aktif 1 çıkışlarda OR kullanılır.
- Büyük çözünürlüklü bir çıkışı daraltmak için kullanılmayan bir adres biti çıkışla OR'lanır ($\overline{Y_6} + A_1$).
- Bellek hiyerarşisi: yazmaç, önbellek, ana bellek, ikincil bellek.
- Yerellik: uzamsal (komşu adresler) ve zamansal (aynı adres tekrar).
- Eşleme: tam ilişkili, doğrudan eşlemeli, küme ilişkili. Değiştirme: FIFO, LRU.
- 16 byte bellek, 4 satırlık direct mapped önbellek: indis = adresin düşük 2 biti, tag = yüksek 2 bit; 0, 4, 8, C adresleri 0 numaralı satıra düşer.
- 32 bit adres, 32 bit veri, 64 byte blok, 1024 byte önbellek: 22 bit tag, 4 bit index, 4 bit word offset, 2 bit byte offset.

## Detaylı Açıklamalar

- **Örnek 1 ayrıntısı (ekrandan, 00:25:00):** 80H-83H adreslerinin ikilik yazılışı `1000 0000`, `1000 0001`, `1000 0010`, `1000 0011`'dür. Dört farklı durum yalnız $A_1A_0$'da oluşur. Geri kalan $A_7$-$A_2$ bitlerinin `100000` olması ve $M/\overline{IO} = 0$ olması, işlemin bu PPI ile ilgili olduğunu gösterir. 3x8 dekoderin 6 girişine 7 koşul bağlanacağı için iki aktif 0 koşul ($A_5$, $A_4$) OR kapısıyla birleştirilir: OR'un çıkışı yalnız ikisi de 0 iken 0 olur. Seçim uçlarına $A_3$, $A_2$, $M/\overline{IO}$ verildiğinde istenen aralıkta seçim kodu 000 olur, yani $\overline{Y_0}$. Herhangi bir bit yanlışsa ya dekoder seçilmez (bütün çıkışlar 1) ya da başka bir çıkış 0 olur (örneğin $A_3 = 1$ iken $\overline{Y_4}$); her iki durumda da $\overline{Y_0} = 1$ kalır ve PPI seçilmez (ekrandan, 00:35:00). PPI'nin geri kalan bağlantıları: $D_0$-$D_7$ mikroişlemcinin veri yoluna, $R/\overline{W}$ mikroişlemcinin $R/\overline{W}$ ucuna, $a_1$, $a_0$ mikroişlemcinin $A_1$, $A_0$ uçlarına.
- **Örnek 2 ayrıntısı (ekrandan, 00:45:00 ve 00:50:00):** A8H = `1010 1000`, B0H = `1011 0000`. PPI1 için $A_7 = 1$, $A_6 = 0$, $A_5 = 1$, $A_4 = 0$, $A_3 = 1$, $A_2 = 0$; PPI2 için $A_4 = 1$, $A_3 = 0$, diğerleri aynı. Ayırt edici $A_4$, $A_3$ seçim uçlarına, $M/\overline{IO}$ üçüncü seçim ucuna verilir. İki aktif 1 koşul ($A_7$, $A_5$) AND kapısıyla $E_1$'e bağlanır. PPI1 için seçim kodu $A_4A_3M/\overline{IO} = 010$ ($\overline{Y_2}$), PPI2 için $100$ ($\overline{Y_4}$) olur. İki PPI'nin veri, adres ($A_1$, $A_0$) ve $R/\overline{W}$ uçları ortak yola paralel bağlanır; yalnız $\overline{CS}$ uçları farklıdır.
- **Örnek 3 ayrıntısı (ekrandan, 01:25:00 - 01:35:00):** A8H-A9H (`1010 100x`) ile 80H-83H (`1000 00xx`) karşılaştırıldığında UART ile PPI'yi $A_5$ ve $A_3$ ayırır; ortak koşullar $A_7 = 1$, $A_6 = 0$, $A_4 = 0$, $A_2 = 0$, $M/\overline{IO} = 0$'dır. Alternatif 1'de $A_1$ de seçim ucuna verilir; her çıkış 2 byte'lık bir aralık seçer. Seçim kodu $A_5A_3A_1$: UART için 110 ($\overline{Y_6}$), PPI'nin alt yarısı 000 ($\overline{Y_0}$, 80-81H), üst yarısı 001 ($\overline{Y_1}$, 82-83H). Tersten okuma: $\overline{Y_4}$ ($A_5 = 1$, $A_3 = 0$, $A_1 = 0$) A0H-A1H adreslerini seçer. Alternatif 2'de $A_1$ hiç kullanılmaz, her çıkış 4 byte seçer; $\overline{Y_6}$ A8H-ABH'yi seçtiği için $A_1$ ile OR'lanır, $A_1 = 1$ olan AAH-ABH elenir. Her iki alternatifte de UART'ın adres ucuna $A_0$, PPI'nin adres uçlarına $A_1$, $A_0$ bağlanır.
- **Direct mapped örneği (ekrandan, 02:30:00):** 4 bit adresli (0-F) bir bellek ve 4 satırlık (4 byte) bir direct mapped önbellek. İndis düşük 2 bit, tag yüksek 2 bittir. 0. satırda tag `11` (yani C adresinden gelen veri) varken `MOV AL,[4]` çalıştırılırsa adres `0100`'dür: indis `00`, tag `01`. Tag uyuşmadığı için cache miss olur; veri ana bellekten getirilir, satırın verisi ve tag'i `01` olarak güncellenir. Aynı komut tekrar çalıştırılırsa tag'ler eşleşir ve veri önbellekten okunur.
- **Adres alanlarının hesabı (ekrandan, 02:40:00):** Word 32 bit = 4 byte olduğu için byte offset $\log_2 4 = 2$ bit. 64 byte'lık blokta 16 word var, word offset $\log_2 16 = 4$ bit (toplam 6 bit, $2^6 = 64$). Önbellek $1024 / 64 = 16$ satır, index $\log_2 16 = 4$ bit. Tag $32 - 4 - 4 - 2 = 22$ bit. Ardışık 64 byte'lık bir bloğun bütün byte'larının yüksek anlamlı 22 biti aynıdır.
- **Ders sonrası notlar:**
  - Hoca direct mapped örneğinde ana belleği "15 byte" olarak andı ve tahtaya da öyle yazdı; 0-F adresleri 16 byte'tır.
  - Hoca önbellek için "erişim süresi daha yüksek" ve "ortalama erişim süresini arttırır" dedi; kastedilen erişim hızının yüksek, ortalama erişim süresinin kısa olmasıdır.
  - Hoca ikincil bellek birimleri için önce "erişim süreleri küçük" dedi, hemen ardından yüksek olarak düzeltti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
