# Ders 11 Genişletilmiş Notu: Adres Çözümleme Devreleri ve Önbelleğe Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Adres Çözümlemenin Çerçevesi
- 2. PPI Cihazı ve M/IO Ucu
- 3. Örnek 1: Tek PPI İçin 3x8 Dekoderli Çözümleme
- 4. Örnek 2: İki PPI İçin Çözümleme
- 5. Örnek 3: Farklı Boyutlu İki Cihaz (UART ve PPI)
- 6. Bellek Hiyerarşisi ve Önbelleğin Gerekçesi
- 7. Önbellek Tasarımı ve Eşleme Yöntemleri
- 8. Doğrudan Eşlemeli Önbellek ve Adres Alanları
- 9. Örnek Sorular

## 1. Adres Çözümlemenin Çerçevesi

Ders, bir önceki haftadan kalan adres çözümleme konusuyla başladı. Bir mikroişlemcili sistemin çalışabilmesi için yalnız mikroişlemci yetmez; veri belleği, komut belleği, G/Ç birimleri gibi çevre birimlerine ve bunları bağlayan yollara ihtiyaç vardır. CPU bu birimlerle (RAM, ROM, G/Ç) ortak bir yol üzerinden bağlıdır ve bu ortak yol üzerinde bir anda yalnız bir cihazla konuşur. Bunu sağlayan devre adres çözümleme devresidir: CPU'nun yürüttüğü komutun adres yoluna çıkardığı değer hangi çevre biriminin adres aralığındaysa yalnız o birimi etkin yapar. Böylece CPU konuşmak istediği tek cihazla ortak yol üzerinden konuşabilir.

Bellek birimleri ile G/Ç birimleri arasında temel bir boyut farkı vardır. Bellek cihazlarının 10-15 civarında adres ucu bulunur; mertebe olarak 10-100 KB'lık bloklar halinde karşımıza çıkarlar. G/Ç birimlerinin ise iki ya da bir adres ucu vardır; dolayısıyla G/Ç uzayında 4, 2 ya da 1 byte'lık yer kaplarlar (ekrandan, 00:15:00). Kapasiteleri bu kadar farklı cihazları aynı çözünürlükte çözümlemek anlamlı olmayabilir. Bu yüzden dersteki örneklerde yalnız G/Ç birimlerine odaklanıldı; bellek birimleri için ayrı bir adres çözümleme devresinin bulunduğu varsayıldı.

Örneklerdeki mikroişlemci genel bir cihazdır. 8086'da G/Ç ve bellek ×16 genişlikte görülüyordu; buradaki mikroişlemci ise 8 bit veri yoluna sahiptir, bu yüzden karşısında gördüğü bellek ya da G/Ç uzayını ×8 genişlikte görmek ister (ekrandan, 00:15:00).

## 2. PPI Cihazı ve M/IO Ucu

### 2.1 PPI'nin uçları ve yazmaçları

İlk örneklerde kullanılan cihaz, önceki derste genel biçimiyle tanıtılan paralel programlanabilir arayüz (PPI) G/Ç birimidir. Blok diyagramında şu uçlar vardır (ekrandan, 00:15:00):

- 8 bitlik çift yönlü veri ucu ($D_0$-$D_7$).
- İki adres ucu: $a_1$ ve $a_0$.
- $R/\overline{W}$ denetim ucu.
- Aktif 0 seçim ucu $\overline{CS}$ (chip select).
- Dış dünyaya açılan, yönü giriş ya da çıkış olarak ayarlanabilen PA, PB ve PC portları.

Cihazın dışarıdan erişilebilen yazmaçları adres uçlarına gelen değere göre seçilir:

```text
a1 a0   Erişilen yazmaç
0  0    Port A yazmacı
0  1    Port B yazmacı
1  0    Port C yazmacı
1  1    Denetim (yazma) / durum (okuma) yazmacı
```

Mikroişlemci Port A yazmacına bir değer yazdığında bu değer yazmacın paralel çıkışlarından Port A uçlarına çıkar; Port B için de aynısı geçerlidir. $11$ adresine yazma yapıldığında denetim yazmacına erişilir; bu yazmaçta Port A, Port B ve Port C'nin yönü gibi yapılandırma bitleri bulunur. Aynı adresten okuma yapıldığında durum (status) yazmacı okunur; bunun içinde strobe işareti gibi özel durumları gösteren bitler olabilir. Hoca bunun genel (jenerik) bir anlatım olduğunu, gerçek cihazlarda farklı senaryolar olabileceğini belirtti.

Bu bilgiler cihazın kendisiyle ilgilidir. Cihaz bir sisteme bağlandığında hangi sistem adresinin hangi iç yazmaca denk geleceği, bağlantının nasıl yapıldığına bağlıdır.

### 2.2 M/IO ucu

Örneklerdeki mikroişlemcinin fiziksel olarak $M/\overline{IO}$ adlı bir ucu olduğu varsayıldı (ekrandan, 00:25:00). Bu çift işlevli uç, yürütülen işlemin bir bellek işlemi mi yoksa bir G/Ç işlemi mi olduğunu ayırt eder ve değerini mikroişlemcinin kendisi, yürüttüğü komuta bakarak üretir. `MOV` gibi bir komut yürütülüyorsa erişilmek istenen şey bellek elemanlarıdır ve uç 1 olur. `IN` (dışarıdaki bir porttan okuma) ve `OUT` (bir porta yazma) komutları G/Ç işlemleridir; bu durumda mikroişlemci uçta 0 üretir.

Bu ucun neden gerekli olduğu şöyle açıklandı: Bir bellek uzayı ve ayrı bir G/Ç uzayı vardır ve her ikisinde de örneğin 80H adresi bulunur. Yalnız adres yoluna bakıldığında belleğin 80H'sine mi yoksa G/Ç uzayının 80H'sine mi erişilmek istendiği belli değildir. Dış dünyadan bakan adres çözümleme devresi bunu $M/\overline{IO}$ ucuna bakarak ayırt eder. Bu yüzden G/Ç adres çözümleme devresine $M/\overline{IO}$ ucu da girer.

## 3. Örnek 1: Tek PPI İçin 3x8 Dekoderli Çözümleme

### 3.1 Soru ve adres tablosu

Soru tahtaya şöyle yazıldı (ekrandan, 00:15:00): 8 bit veri yoluna sahip bir mikroişlemcinin (MP) G/Ç adres uzayında 80H adresinden itibaren ardışık adreslere yerleştirilmiş PPI G/Ç birimine ilişkin adres çözümleme devresini 3x8 dekoder ile gerçekleyiniz.

PPI'nin iki adres ucu olduğu için G/Ç uzayında 4 byte kaplar; 80H'den başlayınca 80H, 81H, 82H ve 83H adreslerini işgal eder. Bu adreslerin ikilik karşılıkları (ekrandan, 00:25:00):

```text
       A7 A6 A5 A4 A3 A2 | A1 A0
80H     1  0  0  0  0  0 |  0  0
81H     1  0  0  0  0  0 |  0  1
82H     1  0  0  0  0  0 |  1  0
83H     1  0  0  0  0  0 |  1  1
```

Cihazın dışarıdan erişilebilen 4 yazmacı vardır; bu yüzden verilen aralıkta 4 farklı durumu oluşturan adres uçları PPI'nin adres uçlarına bağlanmalıdır. Bunlar $A_1$ ve $A_0$'dır. Geri kalan $A_7$-$A_2$ uçlarının `100000` değerini alması, ve $M/\overline{IO}$'nun 0 olması, mikroişlemcinin bu PPI ile ilgili bir işlem yaptığını gösterir. Adres çözümleme devresi yalnız ve yalnız $M/\overline{IO} = 0$ iken ve adres 80H-83H aralığındayken $\overline{CS}$ üretmeli; adres aralık dışındaysa ya da aralık içinde olsa bile $M/\overline{IO} = 1$ ise üretmemelidir.

Sağlanması gereken koşullar:

```text
A7 <- 1
A6 <- 0
A5 <- 0
A4 <- 0
A3 <- 0
A2 <- 0
M/IO <- 0
```

### 3.2 3x8 dekoder

Hoca 3x8 dekoderin uçlarını hatırlattı: seçim uçları C (en anlamlı), B ve A; üç etkinleştirme ucu: aktif 1 $E_1$ ile aktif 0 $\overline{E_{2A}}$ ve $\overline{E_{2B}}$; aktif 0 çıkışlar $\overline{Y_0}$-$\overline{Y_7}$. Dekoder seçilmediğinde bütün çıkışları 1'dir; seçildiğinde yalnız seçim kodunun gösterdiği çıkış 0 olur.

> **Ek bilgi (derste anlatılmadı):** Bu uç yapısı, yaygın olarak kullanılan 74x138 tipi 3'ten 8'e kod çözücü entegresine karşılık gelir.

### 3.3 Bağlantının kurulması

Sağlanması gereken 7 koşul var, dekoderin ise 6 girişi (3 seçim, 3 etkinleştirme) var. Bu yüzden aynı aktiflikteki iki koşulun birleştirilmesi gerekir. $A_7$'nin 1 olması gerektiği için doğrudan aktif 1 $E_1$ ucuna bağlanır. $A_6$ aktif 0 $\overline{E_{2A}}$ ucuna bağlanır. $A_5$ ve $A_4$ birleştirilip $\overline{E_{2B}}$ ucuna bağlanır.

**Soru:** $A_5$ ya da $A_4$ sıfırdan farklıyken 1 veren, yalnız ve yalnız ikisi de 0 iken 0 veren lojik hangisidir? **Cevap:** OR kapısı. Bu yüzden $A_5$ ve $A_4$ bir OR kapısından geçirilerek aktif 0 etkinleştirme ucuna bağlanır.

Kalan üç koşul ($A_3$, $A_2$, $M/\overline{IO}$) seçim uçlarına verilir. Tahtadaki çözüm (ekrandan, 00:35:00):

```text
C   <- A3
B   <- A2
A   <- M/IO
E1  <- A7
E2A <- A6            (aktif 0)
E2B <- A5 OR A4      (aktif 0)
CS_PPI = Y0
```

İstenen aralıkta seçim uçlarına 000 geldiği için kullanılacak çıkış $\overline{Y_0}$'dır; PPI'nin $\overline{CS}$ ucu buraya bağlanır.

### 3.4 Devrenin sağlaması

Hoca devreyi, koşullardan biri bozulduğunda ne olacağına bakarak sınadı:

- $A_7 = 0$ gelirse $E_1$ etkin olmaz, dekoder seçilmez ve bütün çıkışlar 1 olur. $\overline{Y_0} = 1$ olduğu için PPI seçilmez.
- $A_6 = 1$ gelirse aktif 0 $\overline{E_{2A}}$ ucuna 1 gelmiş olur; dekoder yine seçilmez.
- $A_5$ ya da $A_4$'ten biri 1 olursa OR kapısı 1 üretir (OR için 1 yutan elemandır); $\overline{E_{2B}} = 1$ olur, dekoder seçilmez.
- Seçim uçlarına 000 dışında bir değer gelirse, örneğin $A_3 = 1$ ile 100, dekoder seçilir ama 0 çıkışı $\overline{Y_4}$'ten alınır, $\overline{Y_0}$ yine 1 kalır ve PPI seçilmez (ekrandan, 00:35:00).

### 3.5 Mikroişlemci tarafı bağlantılar ve anlam sırası

PPI'nin $\overline{CS}$ ucuna dekoderin $\overline{Y_0}$ çıkışı, $R/\overline{W}$ ucuna mikroişlemcinin $R/\overline{W}$ ucu, 8 bitlik veri uçlarına mikroişlemcinin $D_0$-$D_7$ uçları bağlanır.

Hoca adres uçlarını önce ters sırada bağladı: PPI'nin $a_1$ ucuna mikroişlemcinin $A_0$'ı, $a_0$ ucuna $A_1$'i. Bu durumda:

```text
Adres   MP A1 A0   PPI a1 a0   Erişilen yazmaç
80H     0  0       0  0        Port A
81H     0  1       1  0        Port C
82H     1  0       0  1        Port B
83H     1  1       1  1        Denetim/durum
```

Sistem çalışır ama 81H Port C'ye, 82H Port B'ye denk gelir. Genel kural, adres uçlarındaki anlam sırasının bağlantıda da korunmasıdır: PPI'nin $a_1$ ucuna mikroişlemcinin $A_1$'i, $a_0$ ucuna $A_0$'ı bağlanır. Böylece 80H Port A, 81H Port B, 82H Port C, 83H denetim/durum yazmacına karşılık gelir.

## 4. Örnek 2: İki PPI İçin Çözümleme

### 4.1 Soru

Hoca önce ACH yazdı, sonra örneği düzeltip şu soruyu verdi (ekrandan, 00:40:00 ve 00:45:00): Mikroişlemcinin A8H adresinden itibaren ardışık adreslere PPI1 cihazı, B0H adresinden itibaren ardışık adreslere PPI2 cihazı bağlanacaktır. Uygun adres çözümleme devresini 1 adet 3x8 dekoder ve gerekli basit lojik kapılar ile gerçekleyiniz.

Bu sefer devreye yine adres ve denetim uçları girer, ama iki $\overline{CS}$ çıkması gerekir: $\overline{CS_1}$ ve $\overline{CS_2}$. İki cihaz aynı anda seçilemeyeceği için ya ikisi de 1 olur ya da yalnız biri 0 olur; seçimler karşılıklı dışlayandır.

**Soru:** A8H'den sonra hangi adresler gelir? **Cevap:** A9H, AAH, ABH. Bir öğrenci "AAH gelmez mi" diye sordu, hoca doğruladı.

> **Hocanın vurgusu:** A8H'den sonra A9H'nin ardından B0H'ye geçmek sınavlarda en çok yapılan hatadır; doğrusu A8H, A9H, AAH, ABH'dir.

### 4.2 Adres tablosu

Her iki cihaz da 4 byte kaplar (ekrandan, 00:45:00 ve 00:50:00):

```text
            A7 A6 A5 A4 | A3 A2 | A1 A0
PPI1  A8H    1  0  1  0 |  1  0 |  0  0
      A9H    1  0  1  0 |  1  0 |  0  1
      AAH    1  0  1  0 |  1  0 |  1  0
      ABH    1  0  1  0 |  1  0 |  1  1
PPI2  B0H    1  0  1  1 |  0  0 |  0  0
      B1H    1  0  1  1 |  0  0 |  0  1
      B2H    1  0  1  1 |  0  0 |  1  0
      B3H    1  0  1  1 |  0  0 |  1  1
```

Her iki cihazın adres uçlarına mikroişlemcinin $A_1$ ve $A_0$'ı bağlanır. Seçim koşulları:

- PPI1: $A_7 = 1$, $A_6 = 0$, $A_5 = 1$, $A_4 = 0$, $A_3 = 1$, $A_2 = 0$, $M/\overline{IO} = 0$.
- PPI2: $A_7 = 1$, $A_6 = 0$, $A_5 = 1$, $A_4 = 1$, $A_3 = 0$, $A_2 = 0$, $M/\overline{IO} = 0$.

$A_4A_3$ aynı anda hem 01 hem 10 olamayacağı için iki cihaz aynı anda seçilemez.

### 4.3 Dekoder bağlantısı

İki cihazı birbirinden ayıran uçlar $A_4$ ve $A_3$'tür; bu uçlar mutlaka dekoderin seçim uçlarına bağlanmalıdır, yoksa iki ayrı çıkış elde edilemez. Yine 7 koşul ve 6 giriş vardır. Hoca bu kez farklı bir örnek olsun diye iki aktif 1 koşulu birleştirdi: $A_7$ ve $A_5$.

**Soru:** Her ikisi 1 iken 1 üreten lojik hangisidir? **Cevap:** AND kapısı.

Hoca birleştirme seçeneklerini şöyle özetledi: iki aktif 1 koşul AND ile aktif 1 bir uca, iki aktif 0 koşul OR ile aktif 0 bir uca bağlanabilir; iki aktif 1 koşul NAND ile birleştirilirse aktif 0 bir etkinleştirme ucuna da bağlanabilir.

Tahtadaki çözüm (ekrandan, 00:50:00):

```text
C   <- A4
B   <- A3
A   <- M/IO
E1  <- A7 AND A5
E2A <- A6        (aktif 0)
E2B <- A2        (aktif 0)
```

PPI1 için seçim kodu $A_4A_3M/\overline{IO} = 010$ olduğundan $\overline{CS}_{PPI1} = \overline{Y_2}$; PPI2 için $100$ olduğundan $\overline{CS}_{PPI2} = \overline{Y_4}$.

Mikroişlemci tarafında iki PPI'nin $D_0$-$D_7$ veri uçları, $a_1$, $a_0$ adres uçları (mikroişlemcinin $A_1$, $A_0$'ı) ve $R/\overline{W}$ uçları ortak olarak bağlanır; yalnız $\overline{CS}$ uçları farklıdır ($\overline{Y_2}$ ve $\overline{Y_4}$).

## 5. Örnek 3: Farklı Boyutlu İki Cihaz (UART ve PPI)

### 5.1 Soru

Aradan sonra, adres kapasiteleri farklı iki cihazın tek bir dekoderle nasıl çözümleneceğine bakıldı (ekrandan, 01:15:00 ve 01:25:00): Mikroişlemcinin A8H adresinden itibaren ardışık adreslere bir UART (seri haberleşme) birimi, 80H adresinden itibaren ardışık adreslere bir PPI birimi yerleştirilmek isteniyor. Gerekli adres çözümleme devresini 1 adet 3x8 dekoder ve gerekli basit lojik kapılar kullanarak gerçekleyiniz.

UART'ın tek adres ucu vardır, G/Ç uzayında 2 byte kaplar (A8H, A9H). PPI 4 byte kaplar (80H-83H).

### 5.2 İki yaklaşım

Bu tür durumlarda iki yol vardır:

- Dekoder çıkışları en küçük çözünürlüklü cihaza göre ayarlanır: her çıkış 2 byte seçer. Bir çıkış doğrudan UART'ın $\overline{CS}$'i olur. PPI'nin 4 byte'ı iki çıkışa bölünür ve bu iki çıkış birleştirilir. Aktif 0 çıkışlı dekoder ve aktif 0 $\overline{CS}$ ile "herhangi biri 0 olduğunda 0 üreten" lojik gerekir, bu da AND kapısıdır (alternatif 1a). Çıkışlar ve cihazın seçim ucu aktif 1 olsaydı "herhangi biri 1 olduğunda 1 üreten" OR kapısı kullanılırdı (alternatif 1b) (ekrandan, 01:20:00).
- Dekoder çıkışları büyük çözünürlüklü cihaza göre ayarlanır: her çıkış 4 byte seçer. Bir çıkış doğrudan PPI'nin $\overline{CS}$'i olur. UART'a ayrılan çıkış ise 4 byte seçtiği için, seçimde ve etkinleştirmede kullanılmayan bir adres biti ile daraltılır: o bitin 0 olduğu yarıyı seçmek için çıkış bu bitle OR'lanır (alternatif 2).

### 5.3 Adres tablosu

(ekrandan, 01:25:00)

```text
              A7 A6 A5 A4 A3 A2 A1 A0
UART  A8H      1  0  1  0  1  0  0  0
      A9H      1  0  1  0  1  0  0  1
PPI   80H      1  0  0  0  0  0  0  0
      81H      1  0  0  0  0  0  0  1
      82H      1  0  0  0  0  0  1  0
      83H      1  0  0  0  0  0  1  1
```

UART'ın iki adresini birbirinden ayıran bit $A_0$'dır; UART'ın adres ucuna mikroişlemcinin $A_0$'ı bağlanır. PPI için değişen bir şey yoktur; adres uçlarına $A_1$ ve $A_0$ bağlanır. UART ile PPI'yi birbirinden ayıran bitler $A_5$ ve $A_3$'tür; bunlar seçim uçlarına bağlanmalıdır. Ortak koşullar: $A_7 = 1$, $A_6 = 0$, $A_4 = 0$, $A_2 = 0$, $M/\overline{IO} = 0$.

### 5.4 Alternatif 1: 2 byte çözünürlük

$A_1$, PPI için hem 0 hem 1 değerini alırken UART için yalnız 0'dır; yani o da seçici bir bittir. $A_1$ de seçim uçlarından birine bağlanırsa her çıkış 2 byte'lık bir aralığa karşılık gelir. Anlam sırası korunarak C = $A_5$, B = $A_3$, A = $A_1$ bağlanır. Kalan 5 koşul 3 etkinleştirme ucuna dağıtılır (ekrandan, 01:30:00):

```text
C   <- A5
B   <- A3
A   <- A1
E1  <- A7
E2A <- A6 OR A4        (aktif 0)
E2B <- A2 OR M/IO      (aktif 0)

Y0 : 80H-81H  \
Y1 : 82H-83H  /-- AND --> CS_PPI
Y6 : A8H-A9H  ----------> CS_UART
```

UART için $A_5 = 1$, $A_3 = 1$, $A_1 = 0$, yani seçim kodu 110 ve çıkış $\overline{Y_6}$'dır.

> **Ders sonrası not:** Hoca çıkışı söylerken bir an "Y7" dedi; tahtadaki çizimde ve kod 110'a göre doğrusu $\overline{Y_6}$'dır.

PPI'nin düşük adresli iki byte'ı (80H, 81H) $A_5A_3A_1 = 000$ ile $\overline{Y_0}$'dan, üst iki byte'ı (82H, 83H) $001$ ile $\overline{Y_1}$'den seçilir. 80H-83H aralığında bir işlem yapıldığında bu ikisinden biri aktif olur, ikisi aynı anda aktif olamaz. Aranan, "herhangi biri 0 olduğunda 0 üreten" lojik olduğu için ikisi bir AND kapısıyla birleştirilir ve $\overline{CS}_{PPI}$ elde edilir.

Hoca bir de tersten soru sordu: $\overline{Y_4}$ hangi adresleri seçer? $\overline{Y_4}$'ün aktif olması için $A_7 = 1$, $A_6 = 0$, $A_4 = 0$, $A_2 = 0$, $M/\overline{IO} = 0$ ve seçim kodu $100$ ($A_5 = 1$, $A_3 = 0$, $A_1 = 0$) gerekir. $A_0$ 0 ya da 1 olabilir. Adres `1010 000x`, yani A0H ve A1H'dir.

### 5.5 Alternatif 2: 4 byte çözünürlük

Bu kez $A_1$ ne seçimde ne etkinleştirmede kullanılır; sonradan 4 byte'lık çıkışlardan birini daraltmak için kullanılacaktır. $A_5$ ve $A_3$ mutlaka seçim uçlarına bağlanır; üçüncü seçim ucuna $A_6$ verilir (ekrandan, 01:35:00):

```text
C   <- A5
B   <- A3
A   <- A6
E1  <- A7
E2A <- A4 OR A2        (aktif 0)
E2B <- M/IO            (aktif 0)

Y0 : 80H-83H  ----------------> CS_PPI
Y6 : A8H, A9H, AAH, ABH --+
A1 -----------------------+-- OR --> CS_UART (A8H-A9H)
```

UART için $A_5 = 1$, $A_3 = 1$, $A_6 = 0$ olduğundan çıkış $\overline{Y_6}$'dır; ama bu çıkış 4 byte seçtiği için A8H, A9H, AAH ve ABH adreslerinin hepsinde aktif olur. Oysa AAH adresiyle ilgili bir komut yürütüldüğünde UART seçilmemelidir. A8H-A9H aralığında $A_1$ her zaman 0'dır. $\overline{Y_6}$ ile $A_1$ bir OR kapısından geçirilirse: $A_1 = 1$ iken (AAH, ABH) OR çıkışı 1 olur ve aktif 0 $\overline{CS}$ seçim yapmaz; $A_1 = 0$ iken $\overline{Y_6}$'nın değeri geçer. Böylece yalnız A8H ve A9H seçilir. PPI için $A_5 = 0$, $A_3 = 0$, $A_6 = 0$ olduğundan $\overline{CS}_{PPI} = \overline{Y_0}$'dır.

### 5.6 Mikroişlemci tarafı bağlantılar

PPI'nin $D_0$-$D_7$ uçlarına mikroişlemcinin veri yolu, $a_1$, $a_0$ uçlarına mikroişlemcinin $A_1$, $A_0$'ı bağlanır; böylece 80H Port A, 81H Port B, 82H Port C, 83H denetim/durum olur. $\overline{CS}$ ucuna yapılan üç alternatiften herhangi birinin çıkışı, $R/\overline{W}$ ucuna mikroişlemcinin $R/\overline{W}$ ucu bağlanır. UART'ın 8 bitlik veri ucuna da aynı veri yolu bağlanır; veri yolu iki cihaza birden girer, ama $\overline{CS}$'ler aynı anda aktif olmadığı için mikroişlemci bir anda yalnız biriyle konuşur. UART'ın adres ucuna $A_0$, $\overline{CS}$ ucuna üretilen $\overline{CS}_{UART}$, $R/\overline{W}$ ucuna mikroişlemcinin $R/\overline{W}$ ucu bağlanır.

Daha karmaşık adres aralıklarında dekoderle bu şekilde çözümleme yapmak zorlaşır; bu durumda PAL, PLA gibi programlanabilir lojik entegreler kullanılır.

> **Hocanın vurgusu:** Adres çözümleme konusu önemlidir; hoca dersin bu bölümünü kapatırken bunu iki kez tekrarladı.

## 6. Bellek Hiyerarşisi ve Önbelleğin Gerekçesi

### 6.1 Hiyerarşinin katmanları

G/Ç konusunu kapatan hoca önbellek (cache) konusuna geçti. Bir mikroişlemcili sistemde bir bellek hiyerarşisi vardır (ekrandan, 01:45:00):

- **İkincil bellek birimleri:** manyetik disk, CD, DVD gibi. Kapasiteleri yüksek, erişim süreleri de yüksektir.
- **Ana bellek:** Bir programın çalışabilmesi için ana belleğe yüklenmesi gerekir; program oradan yürütülür. Kapasitesi daha küçük, erişim süresi daha kısadır.
- **Önbellek:** Ana bellekten erişim, ikincil belleğe göre hızlı olsa da çok hızlı değildir; araya daha küçük kapasiteli ama daha hızlı bir önbellek konur.
- **Yazmaçlar:** Erişim süresi en kısa, kapasitesi en küçük katmandır.

CPU'ya yaklaştıkça kapasite düşer, erişim süresi kısalır, üretim (birim) maliyeti artar. Bütün belleği önbellek ya da yazmaç olarak yapmak mümkün olsa da maliyet kullanılamaz düzeye çıkar; buradaki ödünleşim (trade-off) budur.

> **Ders sonrası not:** Hoca ikincil bellek birimleri için önce "erişim süreleri küçük" dedi, hemen ardından erişim sürelerinin de yüksek olduğunu söyleyerek düzeltti. Önbellek için de "erişim süresi daha yüksek" ve "ortalama erişim süresini arttırır" ifadelerini kullandı; kastedilen, önbelleğin erişim hızının yüksek olması ve ortalama erişim süresini kısaltmasıdır.

Günümüzdeki çok çekirdekli işlemcilerde her çekirdeğin (örneğin C1, C2, C3) kendine ait L1 ve L2 önbellekleri, bütün çekirdeklerin ortak kullandığı bir L3 önbelleği vardır (ekrandan, 01:45:00). Önbellek yalnız veri için değil komutlar için de kullanılır: yürütülecek komutlar için komut önbelleği (instruction cache), veriler için veri önbelleği (data cache) bulunur.

### 6.2 Yerellik

Önbelleği avantajlı yapan şey, yazılan kodlarda istatistiksel olarak görülen bir erişim örüntüsüdür (ekrandan, 01:50:00):

- **Uzamsal yerellik (spatial locality):** Dizi işlemlerinde dizi elemanları bellekte ardışık yerleşir. Bir göze erişildiyse sonraki çevrimlerde büyük olasılıkla komşu gözlere erişilecektir.
- **Zamansal yerellik (temporal locality):** Toplamın biriktirildiği bir değişkene (sum) her çevrimde tekrar tekrar erişilir; aynı hücreye farklı zamanlarda yeniden erişilir.

Bu özelliklere dayanarak ana belleğe göre küçük ama daha hızlı bir ara bellek konur. Bir adrese erişilmek istendiğinde yalnız o adres değil, onun komşuluk bloğunun tamamı önbelleğe taşınır. Sonraki erişimde CPU önce önbelleğe bakar ve veriyi orada bulabilir; böylece ortalama erişim süresi iyileşir.

### 6.3 Sanal bellek ile benzerlik

Benzer bir düzen ikincil bellek ile ana bellek arasında da vardır. İşletim sistemi ve başka programlar yüklenmiş, ana belleğin çoğu dolu olabilir. Çalıştırılmak istenen programın yalnız bir adres bloğu (sayfası) boş yere yüklenip çalıştırılır. Ana bellekte yer kalmadığında bir sayfa kaldırılmalıdır; bunun için uzun süredir hiç kullanılmamış sayfa, ana belleğe en önce yüklenmiş sayfa ya da ortalamada en az sıklıkla erişilen sayfa seçilebilir. Önbellek ile ana bellek arasındaki bu düzene önbellek kullanımı, ana bellek ile disk arasındakine sanal bellek (virtual memory) denir (ekrandan, 01:50:00).

Sanal bellek adının anlamı şudur: Bir program kendi 0 referansından itibaren göreli adresleme yapar ve kendine ait sanal bir adres uzayı vardır. Bu uzay fiziksel ana bellekten büyük de olabilir. Bütün adreslemeler kendi referansına göre yapıldığı için program parçalara bölünüp yüklense de çalışabilir. Diskten her satır için ayrı ayrı yükleme yapmak çok maliyetli olacağı için, yine uzamsal ve zamansal yerellikten yararlanılarak bir sayfa topluca ana belleğe yüklenir.

### 6.4 Bellek darboğazı

Hoca, işlemcilerin kabaca 10 yılda bir 10 kat performans artışı gösterdiğini, bellek teknolojisinin ise bu hızda ilerlemediğini söyledi. Bu yüzden bellek hiyerarşisi performans açısından bir darboğaz oluşturmaya başlar ve bu alandaki iyileştirmeler önem kazanır.

## 7. Önbellek Tasarımı ve Eşleme Yöntemleri

### 7.1 Temel sorular

Programın ikincil bellekten ana belleğe uygun biçimde getirildiği, ilgilenilen adres genişliğinin fiziksel adres yolu genişliğine eşit olduğu varsayıldı; sanal adresin fiziksel adrese nasıl çevrildiği sanal bellek konusunda görülecektir. CPU fiziksel adres yolu genişliğinde bir adres çıkarır; ana bellek bu adresi doğrudan karşılar. Ama önce daha küçük kapasiteli önbelleğe bakılmalıdır. Slayttaki sorular (ekrandan, 01:55:00): Önbellek nasıl düzenlenir? Her bellek adresi önbellekte nereye eşlenir? (Önbellek belleğin bir alt kümesi olduğu için birden çok bellek adresi aynı önbellek konumuna eşlenir.)

Aranan veri önbellekte yoksa (miss) bellek arayüzü ana belleğe gider, komşuluk bloğunu alıp önbelleğe taşır. Burada iki soru vardır: aranan veri önbellekte var mı, ve yeni veri geldiğinde önbellek doluysa hangi göz boşaltılacak? Bu iki soru birbirine bağlıdır: yerleştirme mantığı neyse arama mantığı ona göre kurulur.

- Veri sıradaki boş yere yerleştiriliyorsa, aranan verinin önbellekte olup olmadığını anlamak için bütün gözlere baştan sona bakmak gerekir.
- Yerleştirme adresin belirli bir kısmıyla, örneğin en düşük anlamlı 10 bitiyle belirleniyorsa, ana bellekte her 1K'lık uzaklıktaki veriler önbellekte hep aynı göze düşer. Aramak kolaydır ama yerleşim verimli değildir: kod hep 1K aralıklı verilere erişiyorsa, bunların hepsi önbelleğin aynı satırına düşer ve önbelleğin büyük kısmı kullanılamaz.

Hoca, bir aramanın kendisi uzun sürerse önbelleğin amacının (ortalama erişim süresini iyileştirmek) bozulacağını da vurguladı.

### 7.2 Üç eşleme yöntemi

Ana bellek adresleri ile önbellek adresleri arasında üç eşleme yöntemi vardır (ekrandan, 02:15:00): tam ilişkili (fully associative), doğrudan eşlemeli (direct mapped) ve küme ilişkili (set associative). İlk ikisi doğrudan anlaşılabilir olanlardır.

**Tam ilişkili önbellek.** Aranan veri önbellekte bulunamazsa, fiziksel adrese karşılık gelen ana bellekteki komşuluk bloğu alınır ve önbellekte sıradaki ilk boş göze konur. Hangi satırda hangi verinin olduğunu ayırt etmek için adresin geniş bir kısmı, ayırt edici adres alanı olarak veriyle birlikte aynı gözde saklanır. Bu alan bloktaki her byte için ayrı değil, bloğun tamamı için tektir. Aramada bu alana yukarıdan itibaren tek tek bakılır; verinin önbellekte olmadığına ancak bütün gözlere bakılıp eşleşme bulunamadığında karar verilebilir. Kötü yanı budur: bir veriyi bulmak için bütün gözlere bakmak gerekir ve erişim süresi artar.

Önbellek doluyken yeni bir blok getirilmesi gerekirse bir veri kaldırılmalıdır:

- **FIFO (first in first out):** önbelleğe en önce yerleştirilmiş veri kaldırılır.
- **LRU (least recently used):** erişiminin üzerinden en uzun süre geçmiş veri kaldırılır. Örneğin A en eski yerleştirilen veri ama bir önceki çevrimde okunmuş olsun, B'ye ise uzun süredir hiç erişilmemiş olsun; LRU B'yi kaldırır.
- Hoca ayrıca en az sıklıkla kullanılan verinin kaldırılabileceğini de söyledi.

**Doğrudan eşlemeli önbellek.** Fiziksel adresin düşük anlamlı kısmı önbelleğin indisi olur, yüksek anlamlı kısmı ayırt edici adres alanı (tag) olarak saklanır. Geniş bir ana bellekten yalnız düşük anlamlı belirli bir genişlik indis olarak kullanıldığı için, önbellek boyu kadar ötedeki adresler hep aynı satıra düşer; hangisinin o anda önbellekte olduğunu anlamak için indis dışındaki bitler tag olarak saklanır. Arama hızlıdır: adresin hangi bitlerinin indis olduğu bilindiği için doğrudan ilgili satıra gidilir ve tag karşılaştırılır. Eşitse veri okunur; değilse ana bellekten getirilir, aynı satıra yazılır ve hem veri hem tag değişir.

Kötü yanı şudur: Algoritma örneğin hep 512 byte ötedeki verilere erişiyorsa ve indis için 9 bit kullanılıyorsa, erişilen her veri önbelleğin aynı satırına düşer. Her erişimde tag uyuşmaz, veri ana bellekten getirilir, satır yeniden yazılır; önbelleğin geri kalan satırları hiç kullanılmaz.

**Küme ilişkili önbellek.** İki yöntemin iyi yanlarını birleştirir: yatayda tam ilişkili, dikeyde doğrudan eşlemeli çalışır. Aynı satıra eşlenen birkaç blok yan yana (yatayda çoğullanarak) tutulabilir; bir satırdaki N göz kendi aralarında tam ilişkili mantıkla çalışır. Böylece doğrudan eşlemenin erişim hızı ile tam ilişkili yapının esnekliği bir arada elde edilir.

## 8. Doğrudan Eşlemeli Önbellek ve Adres Alanları

### 8.1 Küçük örnek: 4 satırlık önbellek

Slayttaki tanıma göre doğrudan eşlemeli önbellekte her bellek adresi önbellekteki tek bir olası blokla ilişkilidir; bu yüzden veri önbellekteyse yalnız tek bir konuma bakmak yeter. Blok, önbellek ile bellek arasındaki aktarım birimidir (ekrandan, 02:25:00).

Slayttaki örnekte 0-F adresli bir ana bellek ve 4 byte'lık (4 satırlık) bir doğrudan eşlemeli önbellek vardır (ekrandan, 02:30:00). Adres yolu genişliği 4 bittir. Adresin düşük anlamlı 2 biti önbellek haritalamasında indis olarak kullanılır:

```text
Bellek adresi   İkilik   İndis   Tag
0               0000     00      00
4               0100     00      01
8               1000     00      10
C               1100     00      11
1               0001     01      00
...
```

Son iki biti 00 olan 0, 4, 8 ve C adresleri önbelleğin 0 numaralı satırına düşer. Satırdaki verinin hangisinden geldiğini ayırt etmek için kullanılmayan yüksek anlamlı 2 bit tag olarak saklanır: 0-3 adresleri için tag 00, 4-7 için 01, 8-B için 10, C-F için 11'dir.

> **Ders sonrası not:** Hoca ana belleği "15 byte'lık" olarak andı ve tahtaya da öyle yazdı; 0'dan F'ye 16 adres olduğu için bellek 16 byte'tır.

Örnek erişim: 0 numaralı satırda tag 11 ile bir veri (yani daha önce C adresinden getirilmiş veri) bulunsun. `MOV AL,[4]` komutu çalıştırılırsa CPU 4 adresinin ikilik halini (`0100`) yazar; indis 00, tag 01'dir. 0 numaralı satıra gidilir, oradaki tag 11'dir ve uyuşmaz. Birebir eşleme olduğu için veri başka bir satırda olamaz; bu bir cache miss'tir. Veri ana bellekten getirilip 0 numaralı satıra yazılır ve tag 01 olarak güncellenir. Aynı komut tekrar çalıştırılırsa yine 0 numaralı satıra gidilir, tag'ler (01) eşleşir ve veri önbellekten kullanılır.

### 8.2 Blok genişliği 1 byte'tan büyükse

Bir önbellek satırının (bloğunun) genişliği 1 byte değilse, ardışık birden çok byte aynı satıra karşılık gelir. Sonuç olarak bellek adresi alanlara bölünür (ekrandan, 02:40:00 ve 02:45:00): tag (doğru bloğun bulunup bulunmadığını denetler), index (bloğu seçer) ve blok içi byte offset. Blok içi offset de kendi içinde ikiye ayrılır: bir satırda birden çok word bulunabilir; word offset satırdaki hangi word'e, byte offset o word'ün hangi byte'ına erişileceğini belirler. Word genişliği veri yolu genişliğiyle ilgilidir; örneğin 64 bit veri yolunda bir word 8 byte'tır.

```text
| tag | index | word offset | byte offset |
```

### 8.3 Sayısal örnek

Verilenler (ekrandan, 02:40:00): blok genişliği 64 byte, CPU 32 bit adres ve 32 bit veri genişliğine sahip, önbellek kapasitesi 1024 byte. Bellekte her göz 1 byte'tır.

- Bir word 32 bit = 4 byte'tır. 4 byte'ı ayırt etmek için $\log_2 4 = 2$ bit gerekir: byte offset 2 bit.
- 64 byte'lık blokta $64 / 4 = 16$ word vardır. Bunlar arasında seçim için $\log_2 16 = 4$ bit gerekir: word offset 4 bit.
- Sağlama: $2 + 4 = 6$ bit, $2^6 = 64$; bir bloktaki 64 byte'ın herhangi birine erişilebilir.
- Satır sayısı $1024 / 64 = 16$'dır. Satır seçimi için $\log_2 16 = 4$ bit gerekir: index 4 bit.
- Kalan $32 - 4 - 4 - 2 = 22$ bit tag'dir. Bellekte ardışık 64 byte'lık bir bloğun bütün byte'larının en yüksek anlamlı 22 biti aynıdır; bu bloğun ortak ayırt edici adres alanı budur.

Sonuç: 32 bitlik fiziksel adres 22 bit tag, 4 bit index, 4 bit word offset ve 2 bit byte offset olarak dört parçaya ayrılır. Veri hem yerleştirilirken hem okunurken bu bölmeye göre işlem yapılır.

### 8.4 Bir adresin önbellekte aranması

Hoca bu bölmeyle bir adres örneği yaptı. <!-- BELİRSİZ: Örnek adresin onaltılık değeri altyazıda bozuk ("F00481216" gibi) geçiyor ve karelerde görünmüyor; hoca ilk dört onaltılık basamağı 1111 olarak yazdığını söyledi. --> Adres ikilik yazılıp alanlara ayrıldığında düşük 2 bit (byte offset) 00, sonraki 4 bit (word offset) 0000, sonraki 4 bit (index) 0110 ve tag bitlerinin hepsi 1 çıktı. Bu durumda:

1. Önbelleğin 16 satırından 6 numaralı satırına gidilir.
2. Bu satırdaki tag alanına bakılır. Satırdaki tag da bütünüyle 1'lerden oluşuyorsa aranan veri önbellektedir; eşleşmiyorsa veri ana bellekten getirilir.
3. Eşleştiği varsayılırsa satırdaki 64 byte'lık (16 word'lük) bloğun 0 numaralı word'üne (en düşük adresli word), onun da en düşük anlamlı byte'ına bakılır ve bu byte okunur.

> **Ek bilgi (derste anlatılmadı):** Hocanın söylediği alan değerleriyle (tag bütünüyle 1, index 6, word 0, byte 0) kurulan 32 bitlik adres büyük olasılıkla FFFFFD80H'dir; düşük 10 bit `01 1000 0000` = 180H olur.

Hoca dersin sonunda bu konudaki genel çerçeveyi özetledi: tam ilişkili, doğrudan eşlemeli ve küme ilişkili yapıların tanımları verildi; doğrudan eşlemeli önbellek için fiziksel adresin nasıl bölüneceği ve bu bölümleme çerçevesinde aranan verinin önbellekte nasıl bulunacağı konuşuldu. Bu yapının devresi ve diğer önbellek yapıları sonraki derslerde ele alınacaktır.

## 9. Örnek Sorular

### Soru 1 (ekrandan, 00:15:00)

8 bit veri yoluna sahip bir mikroişlemcinin G/Ç adres uzayında 80H adresinden itibaren ardışık adreslere yerleştirilmiş PPI G/Ç birimine (2 adres ucu) ilişkin adres çözümleme devresini 3x8 dekoder ile gerçekleyiniz.

> **Çözüm (derste verildi):** PPI 80H-83H'yi kaplar; $a_1$, $a_0$ uçlarına mikroişlemcinin $A_1$, $A_0$'ı (anlam sırası korunarak) bağlanır. Koşullar $A_7 = 1$, $A_6 = A_5 = A_4 = A_3 = A_2 = 0$, $M/\overline{IO} = 0$. C = $A_3$, B = $A_2$, A = $M/\overline{IO}$; $E_1 = A_7$; $\overline{E_{2A}} = A_6$; $\overline{E_{2B}} = A_5 + A_4$. $\overline{CS}_{PPI} = \overline{Y_0}$. Adresler: 80H Port A, 81H Port B, 82H Port C, 83H denetim/durum.

### Soru 2 (derste sözlü, 00:36:19)

Mikroişlemcinin $A_1$ ucu PPI'nin $a_0$ ucuna, $A_0$ ucu PPI'nin $a_1$ ucuna bağlanırsa 80H-83H adresleri hangi yazmaçlara karşılık gelir?

> **Çözüm (derste verildi):** 80H Port A, 81H Port C, 82H Port B, 83H denetim/durum yazmacı. Bu yüzden anlam sırası korunmalıdır.

### Soru 3 (ekrandan, 00:45:00)

Mikroişlemcinin A8H adresinden itibaren ardışık adreslere PPI1, B0H adresinden itibaren ardışık adreslere PPI2 bağlanacaktır. Uygun adres çözümleme devresini 1 adet 3x8 dekoder ve gerekli basit lojik kapılar ile gerçekleyiniz.

> **Çözüm (derste verildi):** PPI1: A8H-ABH, PPI2: B0H-B3H. Ayırt edici bitler $A_4$, $A_3$. C = $A_4$, B = $A_3$, A = $M/\overline{IO}$; $E_1 = A_7 \cdot A_5$; $\overline{E_{2A}} = A_6$; $\overline{E_{2B}} = A_2$. $\overline{CS}_{PPI1} = \overline{Y_2}$, $\overline{CS}_{PPI2} = \overline{Y_4}$. İki cihazın $A_1$, $A_0$, veri ve $R/\overline{W}$ uçları ortaktır.

### Soru 4 (derste sözlü, 00:42:45)

A8H adresinden başlayan 4 byte'lık bir aralık hangi adreslerden oluşur?

> **Cevap (derste verildi):** A8H, A9H, AAH, ABH. A9H'den sonra B0H'ye geçmek sık yapılan bir hatadır.

### Soru 5 (ekrandan, 01:25:00)

Mikroişlemcinin A8H adresinden itibaren ardışık adreslere bir UART birimi (1 adres ucu), 80H adresinden itibaren ardışık adreslere bir PPI birimi yerleştirilmek isteniyor. Gerekli adres çözümleme devresini 1 adet 3x8 dekoder ve gerekli basit lojik kapılar kullanarak gerçekleyiniz.

> **Çözüm (derste verildi):** UART A8H-A9H (adres ucuna $A_0$), PPI 80H-83H (adres uçlarına $A_1$, $A_0$). Ayırt edici bitler $A_5$, $A_3$. Alternatif 1 (2 byte çözünürlük): C = $A_5$, B = $A_3$, A = $A_1$; $E_1 = A_7$; $\overline{E_{2A}} = A_6 + A_4$; $\overline{E_{2B}} = A_2 + M/\overline{IO}$; $\overline{CS}_{UART} = \overline{Y_6}$; $\overline{CS}_{PPI} = \overline{Y_0} \cdot \overline{Y_1}$ (AND). Alternatif 2 (4 byte çözünürlük): C = $A_5$, B = $A_3$, A = $A_6$; $E_1 = A_7$; $\overline{E_{2A}} = A_4 + A_2$; $\overline{E_{2B}} = M/\overline{IO}$; $\overline{CS}_{PPI} = \overline{Y_0}$; $\overline{CS}_{UART} = \overline{Y_6} + A_1$ (OR).

### Soru 6 (derste sözlü, 01:29:09)

Soru 5'in birinci alternatifindeki devrede $\overline{Y_4}$ çıkışı hangi adresleri seçer?

> **Çözüm (derste verildi):** $A_7 = 1$, $A_6 = 0$, $A_5 = 1$, $A_4 = 0$, $A_3 = 0$, $A_2 = 0$, $A_1 = 0$, $M/\overline{IO} = 0$; $A_0$ serbest. Adres `1010 000x`: A0H ve A1H.

### Soru 7 (ekrandan, 02:30:00)

0-F adresli bir bellek ve 4 satırlık doğrudan eşlemeli bir önbellekte 0 numaralı satırda tag 11 bulunuyor. `MOV AL,[4]` komutu çalıştırıldığında ne olur? Komut ikinci kez çalıştırılırsa ne olur?

> **Çözüm (derste verildi):** 4 = `0100`; indis 00, tag 01. Satırdaki tag 11 olduğu için miss olur; veri ana bellekten getirilir ve satırın tag'i 01 olur. İkinci çalıştırmada tag'ler eşleşir (hit), veri önbellekten okunur.

### Soru 8 (ekrandan, 02:40:00)

Blok genişliği 64 byte, kapasitesi 1024 byte olan doğrudan eşlemeli bir önbellek, 32 bit adres ve 32 bit veri genişliğine sahip bir CPU'da kullanılıyor. 32 bitlik fiziksel adresi alanlara ayırınız.

> **Çözüm (derste verildi):** Byte offset $\log_2 4 = 2$ bit, word offset $\log_2 16 = 4$ bit, index $\log_2 (1024/64) = 4$ bit, tag $32 - 10 = 22$ bit.

## Dersin Toparlaması

Dersin ilk bölümünde G/Ç birimleri için adres çözümleme devreleri üç örnekle tasarlandı. Önce tek bir PPI için 3x8 dekoderli çözüm kuruldu: cihazın iç yazmaçlarını seçen düşük adres bitleri cihaza, geri kalan bitler ve $M/\overline{IO}$ ucu çözümleme devresine verildi; sabit bitler etkinleştirme uçlarına, gerektiğinde OR ya da AND ile birleştirilerek bağlandı ve adres uçlarının anlam sırasının korunması gerektiği gösterildi. Ardından iki PPI için ayırt edici bitlerin seçim uçlarına bağlanması gerektiği, son olarak da farklı boyutlu iki cihazda (UART ve PPI) dekoder çıkışlarının küçük ya da büyük çözünürlüğe göre ayarlanabileceği ve çıkışların kapılarla birleştirilerek ya da daraltılarak kullanılacağı görüldü.

İkinci bölümde bellek hiyerarşisi ve önbelleğin gerekçesi (uzamsal ve zamansal yerellik), sanal bellekle olan benzerliği ve işlemci-bellek hız farkından doğan darboğaz anlatıldı. Tam ilişkili, doğrudan eşlemeli ve küme ilişkili eşleme yöntemleri tanımlandı; doğrudan eşlemeli önbellekte tag alanının neden gerektiği küçük bir örnekle, fiziksel adresin tag, index, word offset ve byte offset alanlarına bölünmesi de sayısal bir örnekle gösterildi. Sonraki derslerde doğrudan eşlemeli önbelleğin devresine ve diğer önbellek yapılarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
