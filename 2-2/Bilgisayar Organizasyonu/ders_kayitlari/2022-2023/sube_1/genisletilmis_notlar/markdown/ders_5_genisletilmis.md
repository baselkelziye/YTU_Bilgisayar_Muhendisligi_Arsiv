# Ders 5 Genişletilmiş Notu: Kısa Sınav Çözümü, Yazmaç Transfer Seviyesi ve Mikro İşlemler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kısa sınav sorularının çözümü
- 2. Paralel yüklemeli yazmaç ve enable mantığı
- 3. Veri yolu (datapath) ve kontrol birimi
- 4. Yazmaçların işlemcideki kullanımı
- 5. Yazmaç transfer notasyonu ve eş zamanlı transfer
- 6. Aritmetik mikro işlemler ve donanımı
- 7. Durum bitleri: carry ve overflow
- 8. Lojik mikro işlemler
- 9. Öteleme mikro işlemleri ve MUX ile yazmaç seçimi
- 10. Ötelemeli yazmaçlar
- 11. Sayıcılar ve kendini düzeltme
- Örnek Sorular

Dersin ilk yarısında önceki haftalarda yapılan kısa sınavın soruları ekranda çözülür. Bu sorular lojik devreler tekrarı niteliğindedir. Arandan sonra yazmaç seviyesindeki tasarıma, yani yazmaç transfer seviyesine (Register Transfer Level, RTL) geçilir. Slaytlar Mano ve Kime'nin "Logic and Computer Design Fundamentals" kitabının 7. bölümündendir. Anlatım slaytlar üzerinde el çizimiyle yürür.

## 1. Kısa sınav sorularının çözümü

Sorular A ve B grubu olarak iki sütunda hazırlanmıştır ve her soru bir grup içinde aynı mantıkla iki ayrı biçimde sorulmuştur. Soruların tam metinleri ve çözümleri "Örnek Sorular" bölümündedir. Burada her sorudan çıkan genel fikir özetlenir.

### 1.1 Farklı lojik fonksiyon sayısı

$n$ değişkenli bir fonksiyonun doğruluk tablosunda $2^n$ satır vardır. Her satırın çıkışı 0 ya da 1 olabildiğinden farklı fonksiyon sayısı $2^{2^n}$'dir. 3 değişken için $2^{2^3} = 2^8$, 4 değişken için $2^{2^4}$ olur.

### 1.2 Tam küme (complete set)

Boole cebrinin temel işlemleri AND, OR ve NOT'tur. Bir kapı kümesiyle bu üçü gerçeklenebiliyorsa küme tam kümedir. AND, OR, NOT zaten tam kümedir. Yalnız NAND ya da yalnız NOR da yeterlidir. NAND ve OR gibi bir küme fazladan kapı içerdiği için minimal değildir ama yine tam kümedir. OR ve NOT ile AND kurulabildiği için bu ikili de tam kümedir. AND ve OR ile ise NOT kapısı kurulamaz, bu yüzden AND-OR ikilisi tam küme değildir.

### 1.3 İşaretli ve işaretsiz karşılık, işaret genişletme

$(1000\,0000)_2$ işaretsiz olarak 128'dir. İşaretli bakıldığında en soldaki bit 1 olduğu için sayı negatiftir. Genliği bulmak için ikiye tümleyeni alınır; genlik yine 128 çıkar, sayı $-128$'dir. $(1111\,1111)_2$ işaretsiz 255, işaretli $-1$'dir. Hangi bit genişliğinde çalışılırsa çalışılsın tüm bitlerin 1 olduğu ikiye tümleyenli sayı $-1$'dir (ekrandan, 00:10:00).

Hoca bu soruyla ilgili işaret genişletme (sign extension) modülünü de hatırlatır. 4 bitlik işaretli bir sayıyı 8 bite çıkarmak için sayı negatifse soldan dört tane 1, pozitifse dört tane 0 eklenir. Bu aslında en yüksek anlamlı bitin sola doğru tekrarlanmasıdır, çünkü negatif sayıda bu bit zaten 1, pozitif sayıda 0'dır.

### 1.4 Karnaugh haritası soruları

Karnaugh haritası sorularında harita, en yüksek anlamlı iki değişken ($x, y$) bir kenarda, düşük anlamlı iki değişken ($z, w$) diğer kenarda olacak biçimde ve Gray kodu sırasıyla (00, 01, 11, 10) kurulur. Hoca hücre numaralarını bulmak için sıralamayı Excel'de yazar: satırlar 0, 1, 3, 2 / 4, 5, 7, 6 / 12, 13, 15, 14 / 8, 9, 11, 10 düzenindedir (ekrandan, 00:15:00).

Çarpımlar toplamı sorusunda köşelerdeki üç tane 1 ve bir don't care birlikte alınarak dörtlü bir grup kurulur; bu grup $\bar w \bar y$ terimini verir. Kalan 1, bir don't care de 1 kabul edilerek ikinci bir dörtlüye katılır ve $\bar w \bar x$ terimi gelir. <!-- BELİRSİZ: Bu sorunun minterm ve don't care listesi altyazıdan tam çıkmıyor, ekranda görülmedi. -->

Toplamlar çarpımı sorusu "Örnek Sorular" bölümünde ayrıntılı çözülür.

### 1.5 MUX ile gerçeklenen fonksiyon

MUX'un tanım bağıntısına göre seçim uçlarındaki ikili değer hangi girişi gösteriyorsa o giriş çıkışa aktarılır. Fonksiyon her seçim kombinasyonu için bir terim yazılarak elde edilir, sonra sadeleştirilir. Bir sadeleştirme adımında $\bar c a + c$ ifadesi çıkar; burada $\bar c$'nin etkisi yoktur ve ifade $a + c$'ye eşittir. Bu eşitlik hatırlanmıyorsa doğruluk tablosuyla görülebilir: $c = 0$ iken ifade $a$'dır, $c = 1$ iken 1'dir, yani $a$ ile $c$'nin OR'udur.

**Soru:** Tablodaki F sütununda "In0, In1" yazıyor, bunlar ne anlama geliyor? **Cevap:** Bunlar MUX'un giriş numaralarıdır (Input 0, Input 1...).

**Soru:** Sağdaki MUX'un seçim uçlarından biri $S_2$ yazılmış, $S_0$ olması gerekmez mi? **Cevap:** Evet, doğrusu $S_0$'dır. Hoca, $S_1, S_2$ sırası farklı yorumlanırsa çıkan sonucun şıklarda olup olmadığını kontrol eder: seçim sırası $b, c$ diye alınırsa fonksiyon $\bar c a + bc$ çıkar ve bu ifade şıklarda yoktur.

### 1.6 Karşılaştırıcı

1 bitlik karşılaştırıcıda eşitlik kontrolü XOR'un değili, yani XNOR kapısıdır. Eşitsizlik kontrolü doğrudan XOR kapısıdır.

### 1.7 Kod çözücülü soru ve değişken sırası

Bir soruda fonksiyon $z, y, x$ sırasında istenir, yani 1 numaralı minterm $z = 0, y = 0, x = 1$ durumudur. Çıkışlar sıralı makstermlere karşılık gelir ve fonksiyon enable ucuna bağlı olarak yazılır. Hoca, denklemle ilerlemenin mümkün olduğunu ama $z, y, x$ sırasında bir doğruluk tablosu kurmanın daha pratik olduğunu söyler; tablo kurulunca 0 ve 1 numaralı mintermler 1 çıkar. <!-- BELİRSİZ: Bu sorunun devresi ve tam metni ekranda görülmedi; altyazıdaki anlatım kısmen anlaşılıyor. -->

### 1.8 Yüklemeli sayıcı

Bu soruda sayıcının nereden saydığına bakmadan önce Load geldiğinde ne yüklendiğine bakılır. Anlam sırası önemlidir. Sonra Load'u süren bitin ilk kez 1 olduğu değer bulunur. Load işareti o değerden sonraki saat kenarında etkili olur ve yüklenen değer görülür (ekrandan, 00:30:00).

### 1.9 Çok fonksiyonlu yazmaç

4 bitlik, paralel yüklemeli, sağa ve sola ötelemeli, resetli bir yazmaç D flip-flop'lar ve 4'e 1 MUX'larla kurulur. 4 bit olduğu için 4 flip-flop ve her birinin önünde bir 4'e 1 MUX vardır. Pratik yol şudur: fonksiyon tablosunda her şık bir sütuna, yani bir bit dilimine karşılık gelir ve tablonun satırları MUX'un 0, 1, 2, 3 numaralı girişleridir. Kontrol bitleri doğrudan MUX'ların seçim uçlarına bağlanabilir. En düşük ve en yüksek dilimin uçtaki girişlerine Lin ve Rin bağlanır. MUX'un çıkışı D flip-flop'un D ucuna bağlıdır, çünkü D flip-flop girişindeki değeri bir sonraki kenarda çıkışa taşır (ekrandan, 00:35:00).

### 1.10 Toggle eden yapılar

$D$ flip-flop'ta $\bar Q$ tekrar $D$'ye bağlanırsa her kenarda içerik tersine döner: 1, 0, 1, 0... JK flip-flop'ta $J = K = 1$ iken $Q$ bir önceki durumunun değili olur. $J = \bar Q$, $K = Q$ bağlanırsa da toggle olur: içerik 1 iken $J K = 01$ gelir ve içerik 0'lanır; içerik 0 iken $J K = 10$ gelir ve 1 yapılır. $T = 1$ verilen T flip-flop zaten toggle eder (ekrandan, 00:40:00).

Toggle etmeyen iki yapının davranışı da incelenir. $T = \bar Q$ ise: $Q = 0$ iken $T = 1$ olur, sonraki durum 1; $Q = 1$ iken $T = 0$ olur, durum 1'de kalır. Yapı 1'e gelip takılır. $T = Q$ ise: $Q = 0$ iken $T = 0$, durum 0'da kalır; $Q = 1$ iken $T = 1$, durum 0'a geçer. Yapı 0'da takılır. Hoca önce bu ikinci durumu yanlış çıkarır, bir öğrencinin uyarısıyla düzeltir.

### 1.11 ROM ile gerçekleme ve sigorta sayısı

ROM'da sigorta korunduğunda ilgili kesişim noktasına çarpı atılır. Pratik olarak çıkış sütunlarında kaç tane 1 varsa o kadar sigorta korunur. İki bitlik iki sayının toplamı 4 girişli, 3 çıkışlı bir fonksiyondur. 0+0'dan 3+3'e kadar tüm toplamlar ikili yazılıp 1'ler sayılır.

**Soru:** Bir öğrenci sorunun formülünde $(A_1A_0)_2$'den sonrasının görünmediğini söyler. **Cevap:** Hoca formülün Word denklemi olarak yazıldığını ve aktarımda bozulmuş olabileceğini söyler; bundan sonra bu tür ifadeleri denklem yerine düz metin olarak yazmanın daha anlamlı olacağını belirtir.

## 2. Paralel yüklemeli yazmaç ve enable mantığı

### 2.1 Paralel yüklemeli yazmacı hatırlama

4 bitlik paralel yüklemeli bir yazmacın iç yapısında 4 flip-flop olmalıdır. Girilen değerin doğrudan içeride saklanması istendiği için D flip-flop en pratik seçimdir. Yazmaç senkron olmalıdır, yani tüm bitler aynı anda yüklenmelidir; bu yüzden flip-flop'ların saatleri ortaktır.

İçeriği 0000 ya da 1111'den başlatmak için bir clear ucu gerekebilir. Flip-flop'lardaki reset uçları genelde asenkrondur: clear ucuna 0 verilince saat beklenmeden tüm bitler sıfırlanır. Senkron reset istenirse clear'ın da arka tarafta senkron bir karşılığı olması gerekir.

### 2.2 Saatle yükleme kontrolü

Yükleme her saat kenarında değil yalnız istendiğinde olsun diye saat bir Load işaretiyle birlikte kullanılabilir. Load aktifken saat darbeleri flip-flop'ların saat uçlarına ulaşır, Load pasifken ulaşmaz. Slayttaki devrede bu iş bir OR kapısıyla yapılır.

**Soru:** Slaytta Load ile saat bir OR kapısına bağlanmış; anlatırken AND gibi düşünmüştüm, neden OR? **Cevap:** Mantık "Load 1 iken saat geçsin" diye kurulunca çıkan tasarım budur. Load 0 iken saat geçsin denirse AND ile benzer bir tasarım da olur, ama o zaman kontrol işaretinin tanımı değişir, işaret 0'da aktif gibi olur.

### 2.3 D girişi üzerinden enable

İkinci yol saati hiç bozmamaktır. Enable ve yükleme girişi olan bir bit, senkron ardışıl devre tasarımı gibi kurulur. Girişler dışarıdan gelen $EN$, dışarıdan gelen $D$ ve mevcut durum $Q$'dur. İstenen davranış şudur: $EN = 0$ ise önceki durum korunur, $EN = 1$ ise $Q$'nun önemi yoktur ve $D$ çıkışta görülür. D flip-flop'ta sonraki durum girişe eşit olduğundan flip-flop'un girişine sonraki durum bağlanır.

| $EN$ | $D$ | $Q$ | $Q^+ = D_{FF}$ |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

Dört minterm vardır: $\overline{EN}\,\bar D Q + \overline{EN}\,D Q + EN\,D \bar Q + EN\,D Q$. İlk ikisinden $\overline{EN}Q$ parantezine alınınca $D$'ler, son ikisinden $EN\,D$ parantezine alınınca $Q$'lar gider:

$$D_{FF} = \overline{EN}\,Q + EN\,D$$

Bu, slayttaki "D flip-flop with enable" devresidir: bir NOT, iki AND ve bir OR kapısı (ekrandan, 01:05:00). Blok kutulanır; dört tanesinin EN uçları ortak Load'a, saatleri ortak Clock'a bağlanınca 4 bitlik yüklemeli yazmaç elde edilir.

### 2.4 İki yaklaşımın farkı

Saatle kontrolde Load saat üzerinden etki eder ve o yazmacın gördüğü saat değişir. Enable'lı yapıda Load D girişi üzerinden etki eder ve sistem saati aynen kullanılır. Hoca'nın vurguladığı nokta şudur: her blokta saat korunursa devredeki bütün yazmaçlar aynı saati kullanır, senkron yapının kontrolü bozulmaz ve tasarıma fazladan karmaşıklık girmez.

> **Hocanın vurgusu:** Küçük bloklardan büyük bloklar kurmak dersin konusudur. Enable'lı D flip-flop bir kez tasarlanıp kutulanır, sonra yazmaçların yapı taşı olarak kullanılır.

## 3. Veri yolu (datapath) ve kontrol birimi

İşlemci tasarımında karşılaşılacak yapılardan biri tek çevrimli bilgisayar mimarisidir. Sisteme belirli saat darbelerinde kontrol işaretleri etki eder. Saat darbeleri öyle aralıklarla gelir ki çıkışların senkron girişlere kadar yayılmasına yetecek zaman kalır; girişler oturduktan sonra saat kenarı gelir.

Tasarımın iki ana başlığı vardır:

- **Datapath:** yazmaçlar, aralarındaki bağlantı yolları ve kombinasyonel devreler (sonuç üreten toplayıcı, ALU gibi birimler).
- **Kontrol birimi:** yürütülecek komut paketlenmiş bir ikili kod olarak gelir. Örneğin 5 bitle 32 komut kodlanabilir, ama kontrol işareti sayısı 10 olabilir: 3 tanesi yazmaç seçimini, 3 tanesi ALU fonksiyonunu, 4 tanesi sonucun yazılacağı yazmacın seçimini etkileyebilir. Kontrol birimi bu paketi kontrol sinyallerine çevirir. Ayrıca sonraki işlem sistemin durumuna bağlı olabilir; örneğin bir işlem sonucunda elde oluşmuşsa onu bir sonraki adıma taşımak için ek bir işlem gerekebilir. Bu yüzden kontrol birimi durum bilgisini de kullanır.

Datapath'e somut bir örnek: A ve B yazmaçlarının toplamını yine A'da saklamak isteniyor. Birinci sayı A'ya, ikinci sayı B'ye yüklenir; çıkışları 4 bitlik bir toplayıcıya gider; toplayıcının çıkışı döndürülüp A'nın paralel yükleme girişine bağlanır. A'ya değer öteleme ile ya da paralel yüklemeyle konabilir. Datapath denince akla böyle bir düzen gelmelidir.

## 4. Yazmaçların işlemcideki kullanımı

### 4.1 Genel amaçlı yazmaçlar ve gösterim

Yazmaçlar işlemcideki bellek hiyerarşisinin en hızlı ve genelde en az sayıdaki birimleridir. Girdi ve çıktı değerlerini saklamak için kullanılırlar ve komut kümesinde açık ya da örtük (gizli) operant olarak yer alabilirler.

Yazmaç büyük harfle gösterilir. $n$ bitlik bir yazmacın bitleri 0'dan $n-1$'e numaralanır ve tek tek bitlere erişilebilir. Bazı yazmaçların alt alanlarına da erişilebilir: 8086'daki AX yazmacının düşük anlamlı 8 biti AL, yüksek anlamlı 8 biti AH'dir.

### 4.2 Komut göstergesi (IP/PC)

Komut göstergesi (Instruction Pointer, program counter) sıradaki komutu gösterir. Çıkışı program belleğinin adres uçlarına bağlıdır; sıradaki komut çekilir, çözülür ve kontrol işlemleri yürütülür. Programcının doğrudan yazıp okuyabildiği genel amaçlı yazmaçların yanında, değerini program akışından alan böyle yazmaçlar da vardır.

Dallanma ve fonksiyon çağrısı yoksa her komuttan sonra gösterge bir sonraki komutu gösterecek kadar artar. Dallanmada hangi değeri alacağı dallanma kontrolü bitince belli olur; dallanmadan gelen ofset, göstergenin önündeki bir toplayıcı-çıkarıcı devreyle eklenir ("şu kadar ileri" ya da "şu kadar geri"). Sıralı yürütmedeki artış da aynı toplayıcı üzerinden yapılır.

Artış miktarı mimariye bağlıdır. RISC mimarisinde sonraki komut bir adres gözü (bir ofset) ötededir. CISC mimarisinde komut boyları farklıdır: iki yazmacı toplayan bir komut 2 bayt, bir bellek gözüyle bir yazmacı toplayan bir komut 3 bayt olabilir. Bu yüzden ne kadar ofset ekleneceği komut yürütülürken belirlenir.

### 4.3 Vektör yazmaçları ve SIMD

Günümüz işlemcilerinde 128, 256 ya da 512 bitlik vektör yazmaçları vardır. Böyle bir yazmaca birden fazla int, 16 tane short ya da daha fazla char sığabilir. Veri bir seferde yazılır ve bir komut tüm alt alanlara uygulanır; örneğin bir dizinin 0, 1, 2, 3. gözleri bu yazmaçta yan yana durur ve dört göze ait işlem tek komutla yapılır. Bu yaklaşım SIMD (single instruction multiple data) olarak bilinir ve bir seferde birden çok veriyi işleyerek throughput'u artırır. Bu yazmaçlar için özel kütüphaneler ve derleyici optimizasyonları vardır.

## 5. Yazmaç transfer notasyonu ve eş zamanlı transfer

### 5.1 Koşullu transfer ve dalga şekli

Basit bir datapath: R1 ve R2 yazmaçları ve aralarında $n$ bitlik bir yol. İki yazmaç da aynı saate bağlıdır ve yükselen kenarda tetiklenir. R1'in çıkışları R2'nin paralel yükleme uçlarına bağlıdır, R2'nin Load ucu $K_1$ ile kontrol edilir. Kontrol birimi bu yapıda $K_1$'i üreten birimdir.

Dalga şeklinde $K_1$ bir saat kenarından hemen sonra 1'e çıkar; o kenarı yakalayamaz. $K_1$ 1 iken gelen sonraki yükselen kenarda R2'nin girişindeki R1 değeri içeri yüklenir ("Transfer occurs here", $t+1$ anı). Bu transfer şöyle yazılır (ekrandan, 01:25:00):

$$K_1: R2 \leftarrow R1$$

### 5.2 Temel semboller

Slayttaki tablo (ekrandan, 01:30:00):

| Sembol | Anlamı | Örnek |
|---|---|---|
| Harf (ve rakam) | Yazmaç | AR, R2, DR, IR |
| Parantez | Yazmacın bir parçası | R2(1), R2(7:0), AR(L) |
| Ok | Veri transferi | $R1 \leftarrow R2$ |
| Virgül | Eş zamanlı transferleri ayırır | $R1 \leftarrow R2,\ R2 \leftarrow R1$ |
| Köşeli parantez | Bellek adresi | $DR \leftarrow M[AR]$ |

Atama sağdan sola yapılır. Parantez bit seçimidir: R2'nin 1 numaralı biti, 0-7 arası bitleri ya da AR'nin düşük anlamlı kısmı gibi. Köşeli parantezli örnekte belleğe doğrudan adres yazılmamış, adres bir yazmaçta (AR) tutulup verilmiştir; yani dolaylı adresleme yapılmış ve okunan değer DR'ye aktarılmıştır. Bu notasyon ileride tek çevrimli bilgisayar tasarımlarında da kullanılacaktır.

### 5.3 Eş zamanlı transfer neden çalışır?

Standart matematik notasyonundan farklı olarak $R1 \leftarrow R2,\ R2 \leftarrow R1$ eş zamanlı bir paralel yüklemedir ve iki yazmacın takasıdır (swap). Hoca bunu R1'in çıkışı R2'nin girişine, R2'nin çıkışı R1'in girişine bağlı iki yazmaç çizerek açıklar.

Saat kenarından hemen önce R1'in değeri R2'nin girişinde, R2'nin değeri R1'in girişinde hazır bekler. Saat seviye tetiklemeli ve uzun olsaydı sorun çıkardı: R1'e yüklenen değer çıkışa ulaşıp yayılarak R2'nin girişine gelir ve saat hâlâ aktifse R2'ye de yüklenir; iki yazmaçta da aynı değer görülebilirdi. Kenar tetiklemede ise yüklenen değerin çıkışa çıkıp karşı yazmaca dolaşması bitmeden saat kenarı çoktan geçmiştir. Böylece her yazmaç kenardan hemen önceki değeri alır ve takas doğru gerçekleşir.

> **Hocanın vurgusu:** Fonksiyonel programlamaya alışık birine FPGA'da ya da Verilog'da paralel atamalar garip gelebilir. Donanım olarak düşünmek gerekir: giriş değerleri hazırdır ve anlık bir saat kenarıyla birlikte içeri yüklenir. Daha fazla karmaşıklaştırmamak gerekir.

### 5.4 İşlem sembolleri

Kombinasyonel atama, yazmaç seviyesinde atama, toplama, çıkarma, bit düzeyinde AND, OR, XOR, NOT, sola öteleme, sağa öteleme, bit vektörü tanımı ve birleştirme (concatenation) için ayrı semboller tanımlanır. Birleştirmeye örnek: 4 bitlik iki değer bir yazmaçta yüksek ve düşük anlamlı kısım olarak sırt sırta konursa 8 bitlik bir değer elde edilir. <!-- BELİRSİZ: Bu sembollerin slayttaki tablosu karede görülmedi. -->

## 6. Aritmetik mikro işlemler ve donanımı

Slayttaki aritmetik mikro işlemler (ekrandan, 01:35:00):

| Sembolik gösterim | Açıklama |
|---|---|
| $R0 \leftarrow R1 + R2$ | R1 ile R2'nin toplamı R0'a |
| $R2 \leftarrow \overline{R2}$ | R2'nin bire tümleyeni |
| $R2 \leftarrow \overline{R2} + 1$ | R2'nin ikiye tümleyeni |
| $R0 \leftarrow R1 + \overline{R2} + 1$ | R1 artı R2'nin ikiye tümleyeni (çıkarma) |
| $R1 \leftarrow R1 + 1$ | R1'i bir artırma (yukarı sayma) |
| $R1 \leftarrow R1 - 1$ | R1'i bir azaltma (aşağı sayma) |

Hoca her birini toplayıcı ya da toplayıcı-çıkarıcı ve yazmaçlarla kurar.

### 6.1 $R0 \leftarrow R1 + R2$

Bir toplayıcının iki girişine R1 ve R2'nin çıkışları, çıkışına R0'ın girişi bağlanır; üç yazmacın saati ortaktır. Toplayıcı kombinasyonel olduğu için senkron çalışmaz; girişlerde ne varsa çıktıyı hemen üretir. R1 ve R2'de değerler hazırsa $R1 + R2$ saat gelmeden toplayıcının çıkışında kararlı biçimde bulunur. Saat kenarında bu değer R0'a kopyalanır. Değerin çıkması için saate gerek yoktur; saat yalnız paralel yükleme gibi senkron işlemler içindir.

### 6.2 $R2 \leftarrow \overline{R2}$

Basit yol: R2'nin her bitine bir NOT kapısı koyup sonucu R2'ye geri yüklemek.

Toplayıcı-çıkarıcıyla da yapılabilir. Toplayıcı-çıkarıcı B kanalına XOR'larla bir kontrol ekler ve $S = 1$ iken $A - B = A + \overline{B} + 1$ hesaplar. Yalnız $\overline{B}$'nin kalması için A kanalına $-1$ verilmelidir: genlikte $-1$ ile $+1$ birbirini götürür. 4 bitlik bir yazmaçta $-1$ tüm bitlerin 1 olmasıdır. Böylece $S = 1$, $A = 1111$, $B = R2$ verilip sonuç R2'ye geri yazılır (ekrandan, 01:40:00).

**Soru:** Değili oluşturmak için $-1$'den çıkarabilir miyiz? **Cevap:** Olabilir; hoca önce daha basit bir mantık olarak NOT kapılarını gösterir, sonra toplayıcı-çıkarıcıyla aynı işi yapar.

### 6.3 $R2 \leftarrow \overline{R2} + 1$

Yine toplayıcı-çıkarıcı çıkarma modunda ($S = 1$) çalıştırılır. A kanalına dört bitlik 0 verilirse sonuç $0 + \overline{R2} + 1$, yani R2'nin ikiye tümleyeni olur; R2'ye geri yazılır.

### 6.4 $R0 \leftarrow R1 + \overline{R2} + 1$

Bu doğrudan çıkarmadır ($R1 - R2$). $S = 1$, A kanalına R1, B kanalına R2 verilir ve sonuç R0'a yazılır.

Hoca burada bir genelleme yapar: girişler 1 ve 2, çıkış 0 numaralı yazmaç diye ayrı çizilmiştir, ama bütün yazmaçlar tek bir yerde tutulabilir. Üç kontrol alanı (birinci operandın adresi, ikinci operandın adresi, sonuç yazmacının adresi) verilirse R0 da R1 ve R2 ile aynı yerde bulunabilir. Girişler ayrı bir adres seçimiyle, sonucun yazılacağı yazmaç ayrı bir bit dizisiyle seçilir.

### 6.5 $R1 \leftarrow R1 + 1$

Toplama modu seçilir ($S = 0$). İkinci girişi tutan yazmaçta 0001 değeri oluşturulur. Saatler ortaktır. İlk kenardan sonra çıkışta $R1 + 1$ hazırdır ve sonraki kenarda R1'e yüklenir; sonra çıkışta $R1 + 2$ oluşur, sonraki kenarda o yüklenir. Böylece her saat kenarında R1 bir artar.

### 6.6 $R1 \leftarrow R1 - 1$

Çıkarma modu seçilir ($S = 1$). A kanalına R1, B kanalına 1 verilir; işlem $R1 - 1$'dir. Sonuç A kanalını besleyen R1'e geri yüklenir ve her kenarda R1 bir azalır.

### 6.7 Ortak datapath

Bu altı tasarımda çok ortak parça vardır: bir toplayıcı-çıkarıcı, iki giriş yazmacı ve sonucun yazıldığı yazmaçlar. Altı ayrı devre yerine hepsini destekleyen tek bir datapath ve toplama/çıkarma seçimini, sabit değerleri ve yüklemeleri ayarlayan bir kontrol yapısı kurulabilir. Bu, altı komutluk bir komut kümesinin öncülü gibidir. Adım adım ALU tasarımına, sonra CPU tasarımına (tek çevrimli, çok çevrimli, boru hatlı) giden akış buradan başlar.

> **Hocanın vurgusu:** Datapath denince akla yazmaçlar, fonksiyon yerine getiren kombinasyonel devreler ve bunları bağlayan yollar gelmelidir. Bu datapath iki yazmacı toplayıp saklayabilir, bir yazmacı artırıp azaltabilir, iki yazmacı çıkarabilir, bir yazmacın negatifini oluşturabilir. Bunların hepsi uygun kontrol işaretleriyle tek bir donanım üzerinde yürütülebilir. Bu konudan akılda kalması gereken budur.

## 7. Durum bitleri: carry ve overflow

Slayttaki yapıda bir toplayıcı-çıkarıcının girişlerinde R2 ve R1 vardır, sonuç R1'e yüklenir ($K_1$ Load), Select ucu $X$'tir. Farklı olarak iki durum biti vardır: $C$ (carry) ve $V$ (overflow). $C$ doğrudan son elde $C_n$'dir; $V$ ise $C_n$ ile $C_{n-1}$'in XOR'udur (ekrandan, 02:05:00).

- **Carry:** işaretsiz sayılarla yapılan toplamadaki taşmayı gösterir. "Büyük sayıları toplayınca elde oluştu" demek doğrudur ama teknik tanım budur.
- **Overflow:** işaretli sayılarla yapılan toplama ve çıkarmadaki taşmayı gösterir.

Taşma şu demektir: yazmaçların ve toplayıcı-çıkarıcının bit genişliği sabittir. Sonuç bu genişliğe sığmıyorsa taşma vardır. Örnek: 8 bitlik $1111\,1111$ ile en düşük biti 1 olan $0000\,0001$ işaretsiz toplanırsa her basamakta elde oluşur ve sonuç 9 bitlik $1\,0000\,0000$ olur; 8 bite sığmaz.

8 bitte işaretsiz işlemlerde sonuç 0 ile 255 arasındaysa taşma yoktur, 255'ten büyükse vardır. İşaretli işlemlerde aralık $-128$ ile $127$'dir. 127 ile 127'yi toplamak, $-128$'den 127 çıkarmak ya da $-128$ ile $-128$'i toplamak aralığın dışına çıkar. İşaretli işlemlerde taşma hem pozitif hem negatif yönde olabilir.

8086 için hoca şöyle bir örnek verir: add komutu girişleri işaretsiz sayı olarak ele alır ve carry üretebilir; subtract komutu girişleri işaretli sayı olarak ele alır ve overflow üretebilir; subtract'ın ürettiği carry belki anlamlı değildir ama overflow anlamlıdır.

> **Ders sonrası not:** Büyük olasılıkla 8086'da ADD ve SUB komutları işaretli ya da işaretsiz ayrımı yapmaz; ikisi de hem CF hem OF bayraklarını günceller. Hangi bayrağın anlamlı olduğu, sayıların programcı tarafından işaretli mi işaretsiz mi yorumlandığına bağlıdır.

Bir toplayıcı-çıkarıcı ve bir yazmaç dosyası kullanılarak hem bu datapath, hem kontrol işaretleri, hem de durum bitleri oluşturulabilir.

## 8. Lojik mikro işlemler

Slayttaki lojik mikro işlemler (ekrandan, 02:10:00):

| Kod | Sembolik gösterim | Açıklama |
|---|---|---|
| 00 | $R0 \leftarrow \overline{R1}$ | Bit düzeyinde NOT (bire tümleyen) |
| 01 | $R0 \leftarrow R1 \wedge R2$ | Bit düzeyinde AND (bitleri temizler) |
| 10 | $R0 \leftarrow R1 \vee R2$ | Bit düzeyinde OR (bitleri kurar) |
| 11 | $R0 \leftarrow R1 \oplus R2$ | Bit düzeyinde XOR (bitleri tümler) |

Dört işlemi destekleyen tek bir datapath için önce komutları ayırt etmek gerekir; dört senaryo 00, 01, 10, 11 diye kodlanır. Yapı derli topludur: hepsi R0'a yazar, birinci operant hep R1, ikinci operant hep R2'dir; tek operantlı NOT işlemi R1 üzerinden yapılır.

**Soru:** Bu dördünü tek yapıda nasıl birleştiririz? **Cevap (öğrenci):** Bir decoder ya da multiplexer kullanılabilir. Hoca MUX yapısını seçer.

Her bit dilimi için bir 4'e 1 MUX kullanılır, çünkü dört fonksiyon vardır. Seçim uçlarına $S_1$ ve $S_0$ bağlanır. $i$. dilim için:

- 0 numaralı girişe $R1_i$'nin NOT kapısından geçmiş hâli,
- 1 numaralı girişe $R1_i$ ve $R2_i$'nin AND'i,
- 2 numaralı girişe $R1_i$ ve $R2_i$'nin OR'u,
- 3 numaralı girişe $R1_i$ ve $R2_i$'nin XOR'u bağlanır.

Bu dilim 8 bitlik mimaride 8 kez tekrarlanır; MUX çıkışları R0'ın girişlerine gider, saat ortaktır. $\bar S_1 \bar S_0$ iken R0'a $\overline{R1}$, $\bar S_1 S_0$ iken AND sonucu atanır ve diğerleri de kontrol işaretine göre seçilir. Bu yapı lojik mikro işlem setinin tamamını destekler.

## 9. Öteleme mikro işlemleri ve MUX ile yazmaç seçimi

### 9.1 Öteleme

Slayttaki örnekler (ekrandan, 02:15:00):

| Tür | Gösterim | Kaynak R2 | Ötelemeden sonra R1 |
|---|---|---|---|
| Sola öteleme | $R1 \leftarrow sl\ R2$ | 10011110 | 00111100 |
| Sağa öteleme | $R1 \leftarrow sr\ R2$ | 11100101 | 01110010 |

Bir birimlik kaydırmadır. Bunun için sağa ve sola öteleyebilen bir yazmaç gerekir; bir right/left kontrol ucu 1 iken sağa, 0 iken sola ötelesin. Örneklerde boşalan bit iki yönde de 0 ile doldurulduğu için yazmacın left in ve right in girişleri 0 ile beslenir. Değer R2'de hazırdır, yazmaç senkron çalışır; 8 bitlik çıkış R1'e aktarılır, R1'in Load ucu uygun verilir ve saatler ortaklanır.

Bu tasarımda R2 yerinde ötelendiği için R2'nin içeriği de bozulur. R2'nin korunması isteniyorsa önce yükleme yapılıp öteleme R1 üzerinde yapılmalıdır.

### 9.2 MUX ile yazmaç seçimi

Aritmetik işlemler bir kenara bırakılıp yalnız veri transferine bakılırsa yapılan iş R0'a bir değer yüklemektir. 8086'nın veri transfer komutlarının özel bir hâli olan yazmaçtan yazmaca transfer buna karşılık gelir; aritmetik, lojik ve öteleme-döndürme komut gruplarının arkasında da böyle datapath'ler vardır.

Slayttaki yapıda 4 bitlik bir 2'ye 1 MUX, R2 (0 girişi) ile R1 (1 girişi) arasında seçim yapar; seçim ucunu $K_1$ sürer. R0'ın Load ucunu $K_1 + K_2$ (OR) sürer (ekrandan, 02:20:00). Ek kontrol işareti gereklidir, çünkü 0 numaralı giriş seçildiğinde $K_1 = 0$ olur ve tek başına yükleme işareti üretilemezdi.

| $K_1$ | $K_2$ | İşlem |
|---|---|---|
| 0 | 0 | Yükleme yok |
| 0 | 1 | $R0 \leftarrow R2$ |
| 1 | 0 | $R0 \leftarrow R1$ |
| 1 | 1 | $R0 \leftarrow R1$ |

Son iki satır birleşince $K_1 = 1$ iken $R0 \leftarrow R1$ yazılır. Ayrıntılı devrede A ve B kanallarının bitleri bit bazında MUX'a bağlıdır; karmaşık bir durum yoktur.

### 9.3 Genel yapı

MUX'un girişlerine yalnız yazmaçlar değil, yazmaçların farklı kombinasyonel devre sonuçları da bağlanabilir. En genel RTL yapısı, bir yazmaç kaynağı, adanmış (dedicated) lojik blokları ve bunlardan birini seçen bir MUX'tur. Adanmış bloklardan biri iki yazmacın toplamını, biri bire tümleyeni, biri ikiye tümleyeni, biri artırmayı, biri azaltmayı içerebilir. Kısıt, yazmaç kaynağının sınırlı olmasıdır. R0'ın çıkışı da geri döndürülüp girdi olarak kullanılabilir.

Hoca, "R1'in artırımı" ve "R2'nin artırımı" için ayrı adanmış bloklara gerek olup olmadığını sorar. Gerek yoktur: blok girdilerini yazmaç dosyasından seçerse iş tek adımda yapılır. $n$ kontrol ucu bir kod çözücüden geçip MUX seçimine bağlanırsa paketten açılmış hâliyle $2^n$ farklı fonksiyon seçilebilir. <!-- BELİRSİZ: Altyazıda "en adet giriş, logiki en adet seçim ucu" diye geçen ilişki tam anlaşılmıyor. -->

## 10. Ötelemeli yazmaçlar

### 10.1 Seri girişli, seri çıkışlı yazmaç

Basit bir seri ötelemeli yazmaçta her bitin çıkışı bir sonraki flip-flop'un girişine bağlıdır (kaskat). Saat kenarında her flip-flop'un girişindeki değer içeri alınır. Kopyalanan değer zincir boyunca son dilime yayılmadan saat kenarı geçmiştir; bu yüzden tüm bitlerde seri giriş görülmez, her bit yalnız bir basamak kayar. Boşalan uca dışarıdan seri giriş verilir.

Kullanım alanları:

- **Seri giriş:** veri dış dünyadan seri geliyorsa (seri haberleşme), boş bir 8 bitlik yazmaç 8 saat darbesi sonunda veriyi bit bit toplar; sonra paralel çıkıştan alınır.
- **Seri çıkış:** seri bir toplayıcı yapılacaksa A ve B sayıları iki yazmaca paralel yüklenir; saat darbeleriyle en düşük anlamlı bitten başlayarak sırayla çıkış verilir ve aynı saatle çalışan seri toplayıcıya gider.

### 10.2 Shift ve Load girişli yazmaç

Slayttaki fonksiyon tablosu (ekrandan, 02:35:00):

| Shift | Load | İşlem |
|---|---|---|
| 0 | 0 | Değişiklik yok |
| 0 | 1 | Paralel yükleme |
| 1 | X | $Q_0$'dan $Q_3$'e doğru öteleme (shift down) |

$i$. dilim için girişler Shift ($S$), Load ($L$), seri giriş (SI), $D_i$, bir düşük anlam sırasındaki $Q_{i-1}$ ve kendi çıkışı $Q_i$'dir. Bu $2^6$ satırlık bir tablo olur, ama mantıkla sadeleşir. Devrede her dilimde üç AND katmanı ve bir OR vardır: öteleme katmanı, yükleme katmanı ve değişiklik yok katmanı (ekrandan, 02:30:00).

- Shift = 1 ise $\overline{S}$ ile beslenen iki AND sıfırlanır (inhibe olur) ve yalnız öteleme katmanı etkili olur. Shift baskındır; Load'a bakılmaz.
- Shift = 0, Load = 1 ise yükleme katmanı etkilidir, değişiklik yok katmanı $\bar L$ ile inhibe edilir; $D_i$ yüklenir.
- Shift = 0, Load = 0 ise yalnız $Q_i$'yi geri besleyen katman etkilidir ve durum korunur.

Bu hiyerarşi şu denkleme karşılık gelir (0. dilimde $Q_{i-1}$ yerine seri giriş):

$$D_i = S\,Q_{i-1} + \bar S\,L\,D_i + \bar S\,\bar L\,Q_i$$

Aynı fonksiyon doğruluk tablosundan senkron ardışıl devre tasarımıyla çıkarılıp indirgenince de bu ifade elde edilir.

> **Hocanın vurgusu:** Bu tasarımda bir öncelik hiyerarşisi vardır. Önce Shift'e bakılır; Shift varsa Load'a bakılmadan öteleme yapılır. Shift yoksa ve Load varsa yükleme yapılır. İkisi de yoksa durum korunur.

### 10.3 MUX'lu çift yönlü ötelemeli yazmaç

Aynı iş kombinasyonel devre yerine bir MUX ile de yapılabilir. Shift ve Load gibi kontrol işaretleriyle üç senaryo vardır; üçü geçen ve 2'nin kuvveti olan en küçük sayı 4'tür, bu yüzden 2 seçim uçlu 4'e 1 MUX kullanılır. $S_1, S_0$ mod seçimidir (ekrandan, 02:40:00):

| $S_1$ | $S_0$ | MUX girişi | İşlem |
|---|---|---|---|
| 0 | 0 | $Q_i$ | Değişiklik yok |
| 0 | 1 | $Q_{i-1}$ | Bir düşük dilimden gelir: sola öteleme |
| 1 | 0 | $Q_{i+1}$ | Bir yüksek dilimden gelir: sağa öteleme |
| 1 | 1 | $D_i$ | Paralel yükleme |

Bitler en düşük anlamlı bit sağda olacak biçimde yazıldığında düşük dilimden yüksek dilime kayma sola öteleme, tersi sağa ötelemedir. Genel bit diliminin dışında iki özel durum vardır: 4 bitlik yazmaçta 0. dilimin 1 numaralı girişine LI (left serial input), 3. dilimin 2 numaralı girişine RI (right serial input) bağlanır. Hoca tanımı şöyle yapar: sağa ötelemede RI en yüksek bitten girer ve değer sağa kayar; sola ötelemede LI 0. bitten girer ve değer sola kayar. Öğrencilerin de bu tanımı kullanmasını ister.

Karmaşık kombinasyonel blok yerine MUX kullanmak tasarımı oldukça pratikleştirir.

## 11. Sayıcılar ve kendini düzeltme

### 11.1 Asenkron sayıcı

Slayttaki yapıda her flip-flop'un $D$ girişine kendi $\bar Q$'su bağlıdır, yani her biri sürekli toggle eder (kısa sınavda da vardı). Ancak her flip-flop'un saati bir öncekinin çıkışından gelir. Saat $f$ frekansındaysa ilk çıkış $f/2$, sonraki $f/4$, sonraki $f/8$, son çıkış $f/16$ frekansında değişir. İlk çıkış 0, 1, 0, 1; ikincisi 0, 0, 1, 1; sonrakiler daha uzun 0 ve 1 blokları biçiminde ilerler. Her flip-flop'un saati farklı kaynaktan geldiği için bu bir asenkron sayıcıdır. Kenar tetiklemesi değiştirilerek yukarı ya da aşağı sayan asenkron sayıcı yapılabilir; 1111'den sonra 0000'a (ya da tersine) dönen döngüsel bir sayıcıdır. <!-- BELİRSİZ: Bu slayt karelerde görülmedi. -->

**Doygun sayıcı (saturated counter):** belirli bir değerden aşağı sayıp 0000'a ulaşınca orada kalan ya da yukarı sayıp 1111'e ulaşınca orada kalan, yani sınır değere gelince o değerde kalan sayıcıdır.

### 11.2 Senkron sayıcı

Senkron sayıcıda tüm flip-flop'lar aynı saati kullanır. 4 bitlik bir senkron sayıcı için dışarıdan bir enable girişi ve dört durum değişkeni vardır, toplam 5 giriş. Sonraki durum bir öncekinin bir fazlası olacak biçimde tablo kurulur, her bit dilimindeki $D$ girişinin hangi küçük $q$ / büyük $Q$ geçişinde oluştuğuna bakılır ve $D$ uçları diğer $q$'lar ile enable cinsinden yazılır. Hoca bu tasarımı zaman darlığı nedeniyle ayrıntılı yapmaz; öğrencilerin denemesini önerir.

Slayttaki devrede her flip-flop'un girişinde bir XOR vardır; XOR'un bir girişi flip-flop'un kendi çıkışı, diğeri enable ile alt bitlerin AND zinciridir. Zincirin sonu carry çıkışı (CO) olur. Zincir seri (art arda AND) ya da paralel (her $C_i$ için ayrı çok girişli AND) kapılanabilir (ekrandan, 02:45:00).

Yükleme fonksiyonu eklenince devre karmaşıklaşır: sayma bloğu ile enable/yükleme bloğu Load işaretiyle ayrılır ve aynı anda etkin olmazlar. Böylece önce bir ilk değer yüklenip sonra o değerden saymaya devam edilebilir. Slayttaki BCD sayıcı örneğinde yükleme değeri 0'dır ve 0 ile 3 numaralı bitlerin ilk kez birlikte 1 olduğu anda, yani 9'da yükleme yapılır; sayıcı 0'dan 9'a kadar sayar.

### 11.3 Özel sayıcı ve kendini düzeltme

Slayttaki özel sayıcının durum diyagramı (ekrandan, 02:50:00), durumlar $ABC$:

```text
000 -> 001 -> 010 -> 100 -> 101 -> 110 -> 000  (sayma dizisi)
011 -> 110                                     (kullanılmayan durum)
111 -> 010                                     (kullanılmayan durum)
```

Hoca önce sayıcıyı "0'dan 6'ya kadar" diye anlatır, sonra düzeltir: sayıcı 0, 1, 2, 4, 5, 6 diye sayar ve 3 ile 7 görünmeyen (kullanılmayan) durumlardır.

Senkron ardışıl devre tasarımında minimal fonksiyonlar bulunurken Karnaugh haritasındaki seçime göre don't care'lere 0 ya da 1 değeri verilmiş olur. Bu değerler, devre kullanılmayan bir duruma düşerse oradan nereye geçeceğini belirler. Bu örnekte 3'ten sonra 6'ya, 7'den sonra 2'ye geçilir; ikisi de sayma dizisine döner. Bu yüzden sayıcı kendini düzeltir (self-correcting). Minimal fonksiyonlar 3'ten 7'ye, 7'den 3'e geçişe yol açsaydı devre kullanılmayan durumlarda dönüp kalır ve kendini düzeltemezdi.

> **Ek bilgi (derste anlatılmadı):** Diyagramdaki geçişler $D_A = A \oplus B$, $D_B = C$, $D_C = \bar B \bar C$ denklemleriyle tutarlıdır. Bu denklemler sekiz durumun hepsi için python ile kontrol edildi; slayttaki devrede bir XOR ve bir AND kapısı görünmesi de bununla uyumludur.

Hoca zorunlu olmayan bir alıştırma önerir: minimal fonksiyonlarla kendini düzeltmeyen bir sayma dizisi bulunup devre kendini düzeltecek biçimde nasıl değiştirilir, kurgulanıp test edilebilir.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:05:43)

3 değişkenli ve 4 değişkenli kaç farklı lojik fonksiyon yazılabilir?

> **Çözüm:** 3 değişkenle doğruluk tablosunda $2^3 = 8$ satır vardır ve her satır 0 ya da 1 olabilir: $2^{2^3} = 2^8 = 256$. 4 değişkenle $2^{2^4} = 65536$ (sayısal değerler python ile kontrol edildi).

### Soru 2 (derste sözlü, 00:06:31)

Şıklarda verilen kapı kümelerinden hangisi tam küme (complete set) değildir?

> **Çözüm:** AND-OR ikilisi. Bu iki kapıyla NOT kurulamaz. AND-OR-NOT, yalnız NAND, yalnız NOR, NAND-OR ve OR-NOT tam kümedir. <!-- BELİRSİZ: Şıkların tam listesi ekranda görülmedi. -->

### Soru 3 (ekrandan, 00:10:00)

$(1000\,0000)_2$ ve $(1111\,1111)_2$ sayılarının işaretsiz ve ikiye tümleyenli işaretli ondalık karşılıkları aşağıdakilerden hangisinde doğru verilmiştir?

| Şık | Sol: işaretsiz | Sol: işaretli | Sağ: işaretsiz | Sağ: işaretli |
|---|---|---|---|---|
| a | 128 | $-128$ | 255 | $-128$ |
| b | 128 | 128 | 128 | $-128$ |
| c | 255 | $-127$ | 255 | $-127$ |
| d | 255 | $-128$ | 127 | $-1$ |
| e | 128 | 127 | 255 | $-1$ |

> **Çözüm:** Sol soru: işaretsiz 128; işaretli olarak MSB 1 olduğundan negatif, ikiye tümleyeni alınınca genlik 128, sonuç $-128$. Cevap a. Sağ soru: işaretsiz 255, işaretli $-1$. Cevap e (python ile kontrol edildi).

### Soru 4 (ekrandan, 00:15:00)

$f(x,y,z,w) = \prod M(5,7,9,11,12,13,14) + d(1,3,4,10,15)$ fonksiyonunun minimum toplamlar çarpımı (minimal indirgenmiş) hâli hangisidir? ($M$: çıkışı 0 olan makstermler, $d$: fark etmez.) Görülen şıklar: a) $(x'+y'+w')(x'+z+w')(y'+z'+w')$, c) $x'+y$, e) $x' w' (y'+w')$. <!-- BELİRSİZ: d listesinin ilk üç elemanı ekrandan, 10 ve 15 altyazıdan alındı; b ve d şıkları ekranda görülmedi. -->

> **Çözüm:** 0'lar haritaya konur. Bir grup, $x$ ve $y$'nin 1 olduğu satırdaki 0'lar ile çevresindeki don't care'lerden oluşur ve $(\bar x + \bar y)$ terimini verir. İkinci grup, $w = 1$ olan iki sütundaki 0'ları ve don't care'leri kapsayan sekizlidir; $x$, $y$ ve $z$ elenir, $\bar w$ kalır. Sonuç: $f = (\bar x + \bar y)\,\bar w$. Python ile tüm tanımlı satırlarda kontrol edildi. Görülen a, c ve e şıkları bu fonksiyona eşit değildir.

### Soru 5 (ekrandan, 00:20:00)

4'e 1 MUX'un tanım bağıntısı: $S_1S_0 = 00 \to In0$, $01 \to In1$, $10 \to In2$, $11 \to In3$. Sol devrede girişler sırasıyla $a, c, a, b$; $S_1 = b$, $S_0 = c$. Sağ devrede girişler $a, b, a, c$; seçim uçları $S_1 = c$ ve (yanlışlıkla $S_2$ yazılmış) $S_0 = b$. Gerçeklenen $f$ fonksiyonunun indirgenmiş hâli hangisidir? Şıklar: a) $a \cdot c$, b) $a + b$, c) $b + c$, d) $a + c$, e) $b \cdot c$.

> **Çözüm (sol):** $f = \bar b \bar c\,a + \bar b c\,c + b \bar c\,a + b c\,b$. $\bar c a$ parantezine alınınca $\bar b + b = 1$; $\bar b c + bc = c$. Sonuç $\bar c a + c = a + c$, cevap d.
>
> **Çözüm (sağ):** $f = \bar c \bar b\,a + \bar c b\,b + c \bar b\,a + c b\,c = a\bar b + b$ biçiminde sadeleşir ve $a + b$ olur, cevap b. Seçim sırası $b, c$ diye alınsaydı $f = a\bar c + bc$ çıkardı ve şıklarda yoktu. İki sonuç da python ile kontrol edildi.

### Soru 6 (ekrandan, 00:30:00)

Yanda verilen sayıcı için sayma aralığı hangisidir? Sol devrede paralel girişler $D_3D_2D_1D_0 = 1001$; Load, çıkışlardan birine bağlıdır. Sol şıklar: a) 0-4, b) 6-12, c) 4-8, d) 0-12, e) 9-12. Sağ şıklar: a) 2-4, b) 8-12, c) 6-8, d) 2-12, e) 11-12.

> **Çözüm:** Sol: yüklenen değer $1001_2 = 9$. Sayıcı 9, 10, 11, 12 diye sayar; 2 numaralı bitin ilk kez 1 olduğu değer 12'dir ($1100_2$). 12'den sonraki kenarda 9 yüklenir. Cevap e) 9-12. Sağ: aynı yolla önce yüklenen değer, sonra en yüksek anlamlı bitin ilk kez 1 olduğu değer bulunur; ekrandaki işaretli cevap c) 6-8'dir (python ile 6, 7, 8, 6... dizisi kontrol edildi).

### Soru 7 (ekrandan, 00:35:00)

4 bitlik, paralel yüklemeli, sağa ötelemeli, sola ötelemeli ve resetli bir yazmaç D flip-flop'lar ve 4'e 1 MUX'larla tasarlanacaktır. Fonksiyon tablosu:

| $C_1$ | $C_0$ | $Q_3$ | $Q_2$ | $Q_1$ | $Q_0$ |
|---|---|---|---|---|---|
| 0 | 0 | $P_3$ | $P_2$ | $P_1$ | $P_0$ |
| 0 | 1 | $q_2$ | $q_1$ | $q_0$ | Lin |
| 1 | 0 | Rin | $q_3$ | $q_2$ | $q_1$ |
| 1 | 1 | 0 | 0 | 0 | 0 |

Sol soru: 1. bit kesitinde 4'e 1 MUX'a yapılan bağlantılara ilişkin hangisi yanlıştır? a) 0 numaralı girişe $P_1$, b) 1 numaralı girişe $q_0$, c) 2 numaralı girişe $q_3$, d) 3 numaralı girişe 0, e) MUX'un çıkışı D-FF'nin D ucuna bağlıdır. Sağ soru: aynı yazmacın 2. bit kesiti için a) 0 numaralı girişe $P_1$, b) 1 numaralı girişe $q_1$, c) 2 numaralı girişe $q_3$, d) 3 numaralı girişe 0, e) MUX çıkışı D ucuna.

> **Çözüm:** Her şık tablonun bir sütununa bakılarak kontrol edilir; $C_1C_0$ doğrudan MUX'un seçim uçlarına bağlanır. 1. bit sütunu: $P_1, q_0, q_2, 0$. 2 numaralı girişe $q_3$ değil $q_2$ bağlı olmalıdır; yanlış olan c. 2. bit sütunu: $P_2, q_1, q_3, 0$; 0 numaralı girişe $P_1$ değil $P_2$ bağlı olmalıdır, yanlış olan a. e şıkkı doğrudur: D flip-flop girişindeki değeri kenarda çıkışa taşıdığı için MUX çıkışı D ucuna bağlanır.

### Soru 8 (ekrandan, 00:40:00)

Aşağıdaki flip-flop bağlantılarından hangisi toggle etmez (her saat darbesinde 0-1 geçişi yapmaz)? Şıklarda $\bar Q$'su D'ye bağlı D flip-flop, $J = K = 1$ olan JK, $J = \bar Q$ ve $K = Q$ bağlı JK, $T = 1$ olan T ve çıkışı T girişine geri beslenen T flip-flop yapıları vardır.

> **Çözüm:** $D = \bar Q$, $J = K = 1$, $J = \bar Q, K = Q$ ve $T = 1$ toggle eder. Çıkışı T'ye geri beslenen yapı toggle etmez. $T = Q$ ise yapı 0'da takılır ($0 \to 0$, $1 \to 0$); $T = \bar Q$ ise 1'de takılır ($0 \to 1$, $1 \to 1$). Sol soruda işaretli cevap d, sağ soruda e'dir (python ile durum geçişleri kontrol edildi).

### Soru 9 (ekrandan, 00:45:00)

$(S_2S_1S_0)_2 = (A_1A_0)_2 + (B_1B_0)_2$ formülüyle ifade edilen iki bitlik iki sayının toplamı, iç yapısı verilen ROM (4x16 dekoder ve OR kapıları) ile gerçeklenecektir. Kaç sigortanın korunması gerekir? (Görülen şıklar: a) 24, b) 22, c) 20.)

> **Çözüm:** 0+0'dan 3+3'e kadar 16 toplamın ikili karşılığındaki 1'ler sayılır; her 1 korunan bir sigortadır. Toplam 22'dir, cevap b (python ile kontrol edildi).

Aynı sayfanın sağ sorusu: $(S_3S_2S_1S_0)_2 = (A_1A_0)_2 \times (B_1B_0)_2$, iki bitlik iki sayının çarpımı ROM ile gerçeklenecektir; kaç sigorta korunmalıdır? Görülen şıklar: a) 28, b) 24.

> **Çözüm (derste verilmedi):** 16 çarpımın ($0 \times 0$'dan $3 \times 3$'e) ikili karşılıklarındaki 1'ler sayılınca 14 bulunur (python ile hesaplandı). Diğer şıklar ekranda görülmediği için şık harfi belirtilemiyor.

## Dersin Toparlaması

Dersin ilk bölümünde kısa sınav soruları üzerinden lojik devrelerin temel araçları tekrar edildi: fonksiyon sayısı, tam kümeler, ikiye tümleyen ve işaret genişletme, Karnaugh haritası, MUX ile fonksiyon gerçekleme, karşılaştırıcı, yüklemeli sayıcılar, MUX'lu çok fonksiyonlu yazmaçlar, toggle eden yapılar ve ROM ile gerçekleme.

İkinci bölümde yazmaç transfer seviyesine geçildi. Enable'lı D flip-flop ile saati bozmadan yükleme yapan yazmaç kuruldu. Datapath ile kontrol birimi ayrıldı. RTL notasyonu ve eş zamanlı transferin kenar tetiklemeyle neden doğru çalıştığı gösterildi. Aritmetik mikro işlemlerin hepsi tek bir toplayıcı-çıkarıcı etrafında, lojik mikro işlemler bit başına bir 4'e 1 MUX ile, öteleme ve yazmaç seçimi MUX'larla kuruldu; carry ve overflow durum bitleri tanımlandı. Ötelemeli yazmaçlarda Shift > Load > koruma önceliği ve MUX'lu çift yönlü yazmaç, sayıcılarda asenkron, senkron, yüklemeli ve kendini düzelten tasarımlar ele alındı. Bir sonraki derste yazmaçlar arasında veri transferinin üç mimarisi (adanmış MUX'lar, ortak veri yolu MUX'u ve üç durumlu tampon) işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
