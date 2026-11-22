# Ders 5 Genişletilmiş Notu: Kısa Sınav Çözümleri ve Hafıza Birimleri: SRAM, DRAM ve Hafıza Genişletme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kısa Sınav Soru 1: T Flip-Flop ile Paralel Yüklemeli Yazmaç
- 2. Kısa Sınav Soru 2: 1 Bitlik Karşılaştırıcılarla 2 Bitlik Karşılaştırıcı
- 3. Hafıza Birimleri ve Hafıza Hiyerarşisi
- 4. Temel Tanımlar: Adres, Bit, Byte, Word
- 5. Von Neumann ve Harvard, CISC ve RISC
- 6. Hafıza Organizasyonu ve Kontrol Uçları
- 7. Okuma ve Yazma Çevrimleri
- 8. SRAM Hücresi, Bit Dilimi ve RAM Entegresi
- 9. Satır-Sütun (Coincident) Seçimi
- 10. SRAM Dizileri: Kapasite ve Veri Yolu Genişletme
- 11. DRAM Hücresi
- 12. Verilog Örneklerine Kısa Bakış
- Örnek Sorular
- Dersin Toparlaması

## 1. Kısa Sınav Soru 1: T Flip-Flop ile Paralel Yüklemeli Yazmaç

Dersin ilk bölümünde bir önceki haftanın kısa sınavındaki iki soru çözüldü. Birinci soruda blok yapısı ve fonksiyon tablosu verilen 4 bitlik paralel yüklemeli bir yazmacın iç yapısının T flip-flop'lar, 4x1 çoğullayıcılar (MUX) ve gerekirse basit lojik kapılarla tasarlanması isteniyordu (ekrandan, 00:15:00). Yazmacın girişleri $M_2$, $M_1$ (fonksiyon seçimi), $CLK$ ve $D_4D_3D_2D_1$ (paralel yükleme verisi), çıkışları $Q_4Q_3Q_2Q_1$'dir. Notasyon: $q=(q_4q_3q_2q_1)_2$ şimdiki durum, $Q$ sonraki durumdur.

| $M_2$ | $M_1$ | $Q$ çıkışları | İşlem |
|---|---|---|---|
| 0 | 0 | $\bar{q}$ | 1'e tümleyen |
| 0 | 1 | $q$ | Aktarma (işlem yok) |
| 1 | 0 | $D_4D_3D_2D_1$ | Paralel yükleme |
| 1 | 1 | $q+1$ | Arttırma ($15+1=0$ kabul edilebilir) |

### 1.1 Bit dilimi yapısı

Yükleme ve fonksiyonların bütün bitlerde aynı anda, saat kenarıyla gerçekleşmesi gerektiği için bu bir senkron ardışıl devre tasarımıdır. İç yapı dört bit diliminden (bit slice) oluşur. Her dilim bir 4x1 MUX ve bir T flip-flop'tur: MUX'un çıkışı T girişine bağlanır, dilimin seçim uçları ($F_2F_1$) bütün dilimlerde birleştirilip dışarıdaki $M_2M_1$ uçlarına götürülür. Birinci dilim $D_1$ ve $Q_1$ ile, ikinci dilim $D_2$ ve $Q_2$ ile ilgilidir; diğerleri de böyle devam eder. Bu dilim yapısı benzetim (Logisim) dosyasında hazır verilmişti.

T flip-flop'un tanım bağıntısı şudur: $T=0$ verilirse durumunu korur, $T=1$ verilirse durumunu tersler (toggle). Hocanın en sık gördüğü hata, tasarımın T flip-flop yerine D flip-flop varmış gibi yapılmasıydı; bu tamamen farklı bir devre verir.

### 1.2 Tümleme ve aktarma

Seçim 00 iken içerideki değerin değili oluşmalıdır. Değeri tutan T flip-flop olduğu için her darbede terslemesi, yani $T=1$ olması gerekir. Bu yüzden MUX'un 00 girişine ($I_1$) sabit 1 bağlanır. Seçim 01 iken durum korunmalıdır, yani $T=0$; MUX'un 01 girişine ($I_2$) sabit 0 bağlanır (ekrandan, 00:20:00).

### 1.3 Paralel yükleme

Bir dilim için dışarıdan bir $D$ girişi ve bir $q$ durumu vardır; sonraki durumun $Q=D$ olması istenir. T ucuna ne bağlanacağını bulmak için olası bütün değerler yazılır ve ters tanım tablosu kullanılır: durum değişmiyorsa $T=0$, değişiyorsa $T=1$.

| $D$ | $q$ | $Q$ | $T$ |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 0 |

Bu tablo XOR kapısıdır: $T = D \oplus q$. Her dilimde $q_i$ ile $D_i$ XOR'lanıp MUX'un 10 girişine ($I_3$) bağlanır (ekrandan, 00:20:00). Saatin yükselen kenarıyla T flip-flop yalnız farklı olan bitleri terslediği için sonuçta $D$ yüklenmiş olur.

### 1.4 Arttırma

Hoca önemli bir yanlış anlamaya dikkat çekti: $q+1$, dört bitten oluşan sayıya aritmetik olarak 1 eklemektir; $q$'nun 1 ile OR'lanması değildir. OR olsaydı bu bir set/reset gibi davranırdı.

> **Hocanın vurgusu:** Arttırma tasarımı bit dilimi bazında yapılamaz. Örneğin 1111'e 1 eklenince bütün bitler değişir; bu yüzden bütün $q$'lar birlikte dikkate alınmalıdır.

Dışarıdan giriş yoktur, girişler yalnız $q$ değerleridir. 16 satırlık bir tablo yazılır, her satırda $Q=q+1$ (15'ten sonra 0) olur ve her bit için T değeri ters tanım tablosundan bulunur (ekrandan, 00:25:00). İlk satırlar şöyledir:

| $q_4q_3q_2q_1$ | $Q_4Q_3Q_2Q_1$ | $T_4T_3T_2T_1$ |
|---|---|---|
| 0000 | 0001 | 0001 |
| 0001 | 0010 | 0011 |
| 0010 | 0011 | 0001 |
| 0011 | 0100 | 0111 |
| 0100 | 0101 | 0001 |
| 0101 | 0110 | 0011 |
| 0110 | 0111 | 0001 |
| 0111 | 1000 | 1111 |

Tablonun geri kalanı aynı düzeni sürdürür. $T_1$ her adımda 1'dir (1 eklenince en düşük bit her zaman değişir), $T_2$ iki adımda bir, $T_3$ dört adımda bir, $T_4$ sekiz adımda bir 1 olur. Karnaugh haritalarıyla:

- $T_4$ yalnız iki 1 içerir (0111 ve 1111): $T_4 = q_3q_2q_1$.
- $T_3$ dörtlü bir grup verir: $T_3 = q_2q_1$.
- $T_2$ sekizli bir grup verir: $T_2 = q_1$.
- $T_1$'in bütün elemanları 1'dir: $T_1 = 1$.

Çizimde en düşük anlamlı dilimin MUX'unun 11 girişine ($I_4$) 1, ikinci dilime $q_1$, üçüncüye $q_1q_2$ (bir AND kapısıyla), dördüncüye $q_1q_2q_3$ bağlanır. Bir önceki dilimdeki çarpım bir sonrakinde yeniden kullanılır.

Bütün tasarım (dört işlem, 16 durum, 16 veri değeri) python ile kaba kuvvetle doğrulandı; sonraki durumlar fonksiyon tablosuyla birebir uyuşuyor.

### 1.5 Benzetim

Logisim'de önce 10 seçilip 0110 yüklendi (ekrandan, 00:30:00). Sonra 00 seçilince saat darbesiyle değer 1001 oldu, yani 1'e göre tümleyen alındı. 01 seçilince girişlerde 0110 olmasına rağmen değer korundu. 11 seçilince her saat darbesinde değer bir arttı ve 1111'den sonra 0000'a döndü.

**Soru:** Tabloları çizip Karnaugh haritası olmadan fonksiyonları doğrudan yazmak (örneğin yüklemede XOR'un görülmesi) yeterli mi? **Cevap:** Evet. Fonksiyonlar bit bazında yazılmış ve gerekçesi görülüyorsa kabul edilir; beklenen asıl şey bu ara fonksiyonlardır.

## 2. Kısa Sınav Soru 2: 1 Bitlik Karşılaştırıcılarla 2 Bitlik Karşılaştırıcı

İkinci soruda kesikli çizgiyle belirtilmiş bölgede yalnız blok yapısı ve fonksiyon tablosu verilen 1 bitlik karşılaştırıcılar kullanılarak 2 bitlik karşılaştırıcı tasarlanması isteniyordu; çıkıştaki OR (ve diğer) kapılar kesikli bölgenin dışında hazırdı (ekrandan, 00:35:00).

> **Hocanın vurgusu:** Soru "SADECE" 1 bitlik karşılaştırıcı kullanılmasını istiyordu. Bölgenin içinde başka kapılar kullanmak sorunun kuralını çiğnemektir.

### 2.1 İzlenecek yol

İlk adım, 2 bitlik karşılaştırıcının doğruluk tablosunu yapıp çıkışları $A_1$, $A_0$, $B_1$, $B_0$ cinsinden bulmaktır. Dört giriş olduğu için tablo 16 satırdır. Hoca Karnaugh haritasında gözle yapılan indirgemenin sonucunu gösterdi ve $A<B$ ifadesinin $A>B$ ifadesiyle aynı olduğunu, yalnız bütün terimlerde değillerin $A$ ile $B$ arasında yer değiştirdiğini söyledi.

> **Ders sonrası not:** Hocanın ekranda gösterdiği ifade incelenen karelerde yok. Karnaugh haritasından elde edilebilecek bir biçim $A>B = A_1\bar{B}_1 + A_0\bar{B}_1\bar{B}_0 + A_1A_0\bar{B}_0$'dır ve python ile 16 satırın hepsinde doğrulandı.

İkinci adım, 1 bitlik karşılaştırıcının çıkış fonksiyonlarını bulmaktır (ekrandan, 00:35:00):

| $A_i$ | $B_i$ | $>$ | $<$ | $=$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 0 |
| 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 1 |

Büyüktür çıkışının tek bir minterimi vardır: $(>) = A\bar{B}$. Küçüktür de tek satırdadır: $(<) = \bar{A}B$. Eşittir, iki değer aynıyken 1'dir; bu XOR'un değili, yani XNOR'dur: $(=) = \overline{A\oplus B} = A \odot B$.

Üçüncü adım, hedef fonksiyonları bu çıkışlar cinsinden yazmaktır.

### 2.2 Büyüktür çıkışı

Karşılaştırıcılar iki kat halinde düşünülür: ilk katta $A_1$ ile $B_1$, onun altında $A_0$ ile $B_0$ karşılaştırılır. $A>B$ iki terimin toplamıdır, toplama için çıkıştaki OR kapısı kullanılır.

- Birinci terim $A_1\bar{B}_1$'dir; bu, birinci katın $>$ çıkışıdır ve doğrudan OR'a gider.
- İkinci terim, birinci bitlerde $A$'nın küçük olmama durumu ile ikinci bitlerde $A$'nın büyük olma durumunun çarpımıdır: $\overline{(A_1<B_1)}\cdot(A_0>B_0)$.

İkinci terim "birinciyi olduğu gibi bırak, ikincinin değilini al ve çarp" biçimindedir, yani yine bir büyüktür fonksiyonudur. Bu yüzden bir 1 bitlik karşılaştırıcı daha konur: birinci girişine $(A_0>B_0)$, ikinci girişine $(A_1<B_1)$ verilir ve $>$ çıkışı ikinci terimi üretir.

$$A>B = (A_1>B_1) + \overline{(A_1<B_1)}\,(A_0>B_0)$$

### 2.3 Küçüktür ve eşittir çıkışları

Küçüktür için aynı yapı tersinden kurulur: $A<B = (A_1<B_1) + \overline{(A_1>B_1)}\,(A_0<B_0)$; ikinci terim, girişlerine $(A_0<B_0)$ ve $(A_1>B_1)$ verilen bir karşılaştırıcının $>$ çıkışıdır. Eşitlikte hem birinci bitlerin hem ikinci bitlerin eşit olması gerekir: $A=B = (A_1\odot B_1)(A_0\odot B_0)$; iki karşılaştırıcının $=$ çıkışları AND kapısına verilir (ekrandan, 00:40:00).

Üç ifade python ile 16 satırın hepsinde doğrulandı.

### 2.4 Benzetim ve karşılaştırıcının türü

Benzetimde $A$ sabit tutulup $B$ değiştirildi: $A=0$ iken $B=0$ için eşit, $B=1,2,3$ için $A<B$ yandı; $A=3$ iken $B=0,1,2$ için $A>B$, $B=3$ için eşit yandı. Hoca, verilen 1 bitlik karşılaştırıcının işaretsiz (unsigned) çalışacak biçimde hazırlandığını vurguladı. İkiye tümleyen (2's complement) modunda çalışan bir karşılaştırıcı alınsaydı işaretli sayı karşılaştırması yapılırdı ve sonuç istenen olmazdı.

## 3. Hafıza Birimleri ve Hafıza Hiyerarşisi

Aradan sonra haftanın konusu olan hafıza birimlerine geçildi. Hafıza birimi, bir veri bloğunu işlem boyunca, belirli bir süre boyunca ya da ROM'da olduğu gibi enerji kesilse bile tutabilen devre elemanıdır. Farklı seviyelerde saklanması gereken değerler olduğu için bir hiyerarşi ortaya çıkar.

Hoca bunu bir bilgisayarın açılışıyla anlattı. Açılışta önce BIOS donanım kontrollerini yapar ve sistemi işletim sistemine devreder; bu program BIOS ROM'una gömülüdür. Sonra işletim sisteminin program parçaları diskten ana belleğe (RAM) yüklenir ve programlar orada çalışır. Program çalışırken kullanılan veriler RAM'de olsa bile daha hızlı erişim için işlemciye yakın önbellek (cache) katmanlarında da tutulur. Önbellek işlemcinin içinde ya da hemen yanında olabilir.

Önbellek iki gözleme dayanır. Bir dizi üzerinde işlem yapılıyorsa bir sonraki adımda büyük olasılıkla hemen sonraki adrese erişilir; komşu veriler önbelleğe alınmışsa sonraki veriyi orada bulma olasılığı artar. Bir değer üzerinde tekrar tekrar güncelleme yapılıyorsa aynı değişkene defalarca erişilir; bu değer önbellekteyse güncelleme orada hızla yapılır.

> **Ek bilgi (derste anlatılmadı):** Bu iki gözlem literatürde uzamsal yerellik (spatial locality) ve zamansal yerellik (temporal locality) diye adlandırılır.

Hem komutların hem verinin işlemciye aktarılması gerekir: program belleğinden gelen komut çözülür, girdi verisi RAM'den çekilir. En içte, işlemcinin temel veri saklama birimleri olan yazmaçlar (register) vardır.

Hiyerarşi BIOS ROM'undan, ikincil bellekten ana belleğe, oradan önbelleğe, oradan yazmaçlara uzanır. Yazmaçlar işlemcinin içinde olduğu için en hızlıdır, ama üretim maliyeti yüksektir; bu yüzden az sayıdadır ve kapasiteleri düşüktür. Önbellek yazmaçlardan daha büyük kapasiteli ve biraz daha yavaştır; amacı ana belleğe tekrar gitmeden veriyi işlemciye yakın bir yerden okuyup yazmaktır.

Önbellekle çalışırken okuma sorun değildir. Ama işlenen veri önbelleğe geri yazılırsa ana bellekteki kopya eski kalır. İki kopya arasındaki tutarlılığı sağlamak ayrı bir çalışma konusudur.

### 3.1 SRAM ve DRAM'e ilk bakış

Zaman içinde SRAM ve DRAM mantıkları kullanılmıştır. SRAM flip-flop mantığına benzer biçimde saklar; bir flip-flop için en az iki NAND kapısı gerekir, bu da en az 4, standart bir hücrede 6 transistör demektir. CMOS teknolojisinde SRAM yalnız saklanan veri değişirken (0'dan 1'e ya da 1'den 0'a) enerji harcar. DRAM ise bir transistör ve bir kapasite elemanıyla saklar. Daha yoğun (dense) bir yapıdır, yani aynı alana daha fazla kapasite sığar. Olumsuz yönü, verinin kapasitedeki elektrik yüküyle saklanmasıdır: kaçak akımlar yükü zamanla azalttığı için verinin belirli aralıklarla yenilenmesi gerekir.

Hoca ayrıca double data rate (DDR) DRAM'lerden söz etti: işlemi saatin hem yükselen hem düşen kenarında yaparak etkin hızı iki katına çıkarırlar.

> **Ders sonrası not:** Hoca "dinamik RAM'de güncelleme saatin yükselen kenarında, DDR'de hem yükselen hem düşen kenarda yapılır" dedi. Burada kastedilen büyük olasılıkla yenileme (refresh) değil, veri aktarımıdır: senkron DRAM (SDRAM) veriyi saatin bir kenarında, DDR SDRAM her iki kenarında aktarır. "Dinamik" sözcüğü ise yükün yenilenme ihtiyacından gelir.

## 4. Temel Tanımlar: Adres, Bit, Byte, Word

Slaytta (ekrandan, 01:00:00) hafıza, hücreler ve bilgiyi bunlara aktaran devrelerin bütünü olarak tanımlanır. Hafıza organizasyonu, verinin nasıl erişildiği açısından temel mimari yapıdır. RAM, herhangi bir göze erişim süresinin seçilen gözden bağımsız olduğu hafızadır. Hafıza adresi, bir hafıza elemanını ya da eleman grubunu belirten bit vektörüdür.

Adres, işlemcinin uçlarıyla doğrudan adresleyebildiği gözlere karşılık gelen tekil değerdir. 20 bitlik adres çıkarabilen bir işlemci, uygun belleklerle desteklenmişse $2^{20}$ = 1M göze erişebilir; adresin her farklı değeri farklı bir göze karşılık gelir.

Veri tipleri (ekrandan, 01:15:00):

- Bit (binary digit): tek bir ikili basamak, atomik saklama genişliği. Tarihte üç durumlu (trinary) ve dört durumlu lojikler de denenmiştir, ama derste ikili sistemler kullanılır.
- Byte: birlikte erişilen 8 bit.
- Word: hafızanın tipik erişim birimi, işlemcinin bir seferde okuyup yazabildiği genişlik; genelde byte'ın ikinin kuvveti katlarıdır (1, 2, 4, 8 byte).

8086'nın 20 adres ucu ve 16 veri ucu vardır; word genişliği 16 bit, yani 2 byte'tır. Bu yüzden 8086'ya 8 bitlik bellekler bağlanırken veri genişliğini 16 bite çıkarmak için iki bellek yan yana kullanılır. Günümüzün 64 bitlik bilgisayarlarında word 8 byte'tır. Hafıza verisi saklanan ya da okunan bit grubudur; hafıza işlemleri temelde bit, byte ya da word üzerinden okuma ve yazmadır.

## 5. Von Neumann ve Harvard, CISC ve RISC

Von Neumann mimarisinde veri belleği ve program belleği için ortak veri ve adres yolları kullanılır; aynı adres uçlarıyla iki belleğe de erişilir. 8086 ve devamı bu mimaridedir. Harvard mimarisinde program belleğinin ve veri belleğinin kendine adanmış ayrı veri ve adres yolları vardır. Bu yüzden Harvard'da veri belleğindeki bir değer program belleğini bozamaz; Von Neumann'da ise böyle bir bozucu etki olabilir. Hoca Harvard'a örnek olarak cep telefonlarındaki ARM işlemcileri ve mikrodenetleyicileri verdi.

CISC (Complex Instruction Set Computer) karmaşık işlemleri destekleyen donanıma sahiptir. Basit komutlar kısa sürede, karmaşık komutlar 2-3 kat çevrimde biter; basit komutların bit genişliği dar, karmaşık ya da çok adımlı bellek işlemlerinin geniş olabilir. Çarpma, bölme, vektör işlemleri, hatta bir yazmaçtaki 1'lerin sayısını bulan komutlar vardır. Kısacası CISC'te komut uzunlukları ve yürütme süreleri komuttan komuta değişir; 8086 bir CISC işlemcisidir.

RISC (Reduced Instruction Set Computer) indirgenmiş bir komut kümesi kullanır: karmaşık işlemler yoktur, tasarım gereği her komutun bit genişliği eşittir ve hemen her durumda yürütme çevrim süreleri de eşittir. ARM ailesi ve Microchip PIC mikrodenetleyicileri RISC'tir.

## 6. Hafıza Organizasyonu ve Kontrol Uçları

Dışarıdan bakıldığında hafıza bir word dizisidir. Adres uçları dizinin hangi gözüne gidileceğini belirtir. Her gözün belirli bir genişliği vardır; içeride belki birden fazla 8 bitlik eleman yan yana kullanılmıştır, ama dışarıdan her göz bir word'dür. Veri giriş ve çıkış uçları word genişliğiyle uyumludur. Ayrıca okuma/yazma uçları ve hafıza elemanını etkinleştiren bir uç (chip select ya da memory enable) vardır.

Mimari örnekleri: DEC yapısında 12 bitlik adres, yani $2^{12}$ = 4096 göz ve her gözde 12 bitlik veri vardır. IBM tarafında 24 bitlik adresle $2^{24}$ = 16M göz adreslenir; 32 bitlik bellekler yan yana dizilince 4M adet 32 bitlik word'e erişilir. <!-- BELİRSİZ: 01:17:58 civarında "her birisi 16 bit veriden oluşan 2 üzeri 20 adet hafıza gözü" örneğinin hangi mimariye ait olduğu altyazıdan anlaşılmıyor. -->

Veri giriş ve çıkış uçları, üç durumlu (tri-state) kontrolle birleştirilip aynı uçlardan iki yönlü aktarım yapılabilir. $2^k$ gözlü ve her gözde $n$ bit olan bir hafızanın kapasitesi $2^k \times n$'dir. Slayttaki örnekte (ekrandan, 01:20:00) 3 adres ve 8 veri biti olan bir hafıza $2^3 = 8$ göz (0-7) ve 8 bitlik 8 word içerir. 10 adres ucu olan ve her gözü 16 bit (2 byte) olan hafıza ise $2^{10}\times 16$ kapasitelidir; tabloda adresler 0'dan 1023'e gider.

Hafıza erişimi, adres değerinin uçlara uygulanması, ilgili gözün aktif olması ve o göze yazma ya da ondan okuma yönünde verinin aktarılmasıdır.

### 6.1 Chip select ve adres çözümleme

Bir işlemciye birden fazla hafıza elemanı (BIOS ROM, ikinci bir ROM, ana bellek RAM'leri) aynı adres ve veri yollarıyla bağlı olabilir. Aynı anda iki eleman veri yoluna değer çıkarırsa (biri 0, biri 1) çakışma olur ve işlemci anlamlı veri okuyamaz. Bu yüzden aktarımı işlemci yönetir.

Hocanın örneğinde komut "100 adresinden oku" demektedir. İşlemci 100 değerini ikili olarak adres yoluna çıkarır. Adres çözümleme devresi bütün adres uçlarını ve read/write gibi kontrol uçlarını alır, her hafıza elemanı için bir CS çıkışı üretir. ROM1 0-1000, ROM2 1000-2000, RAM 2000-3000 aralığına yerleştirilmişse 100 adresi için yalnız ROM1'in CS'si aktif olur.

CS aktif olmayan bir elemanın adres ve veri uçları yüksek empedans gösterir: uçlar sonsuz dirençli, yani açık devre gibi davranır ve eleman devreden kopmuş gibi olur. Böylece işlemci yalnız ROM1'i görür. Slaytta CS aktif 1 olarak gösterilmiştir, ama pratikte çoğunlukla aktif 0 kullanılır.

Kontrol uçları tablosu (ekrandan, 01:25:00):

| CS | $R/\bar{W}$ | İşlem |
|---|---|---|
| 0 | X | Yok |
| 1 | 0 | Seçili word'e yazma |
| 1 | 1 | Seçili word'den okuma |

Veri yolu tek olduğu için işlemci aynı anda hem okuyup hem yazamaz. Bu yüzden iki işlem tek uçta birleştirilebilir: 1 okuma, 0 yazma. İşlemcide okuma ve yazma uçları ayrıksa hafıza elemanında da ayrık, işlemcide birleşikse hafızada da birleşik olmalıdır.

Slayta göre okuma işlemi, geçerli bir adresi adres hatlarına koyup okunan verinin kararlı hale gelmesini beklemektir. Yazma işlemi, geçerli adresi ve geçerli veriyi hatlara koyup yazma kontrol hattını değiştirmektir.

## 7. Okuma ve Yazma Çevrimleri

Genelde okuma daha kısa, yazma daha uzun sürer. Slayttaki sayısal örnekte (ekrandan, 01:30:00) işlemcinin saat frekansı 50 MHz'dir:

$$T_{clk} = \frac{1}{50\cdot 10^6}\ \text{s} = 20\cdot 10^{-9}\ \text{s} = 20\ \text{ns}$$

Bağlı hafızanın okuma (erişim) süresi 65 ns, yazma süresi 75 ns'dir. Dört çevrim $4\times 20 = 80$ ns ettiği için hem okuma hem yazma 4 saat çevriminde tamamlanır ($\lceil 65/20\rceil = \lceil 75/20\rceil = 4$, python ile doğrulandı).

Daha yavaş bir hafıza bağlanırsa işlemcinin onun hazır olmasını beklemesi gerekebilir; bunun için kontrol uçları vardır ve sistem öyle tasarlanmışsa gecikmeli okuma/yazma yapılabilir. T1-T4 dört zamanlı çevrim 8086'da bulunur; yavaş elemanlar için bekleme T3'te yapılır.

Yazma çevrimi şöyle ilerler:

- Adres yola çıkar ve dört çevrim boyunca geçerli kalır.
- Adres çözümleme devresi hafıza elemanını CS (memory enable) ile seçer.
- Yazma işaretinden hemen önce yazılacak veri veri yoluna konur.
- $R/\bar{W}$ ucu 0'a çekilir; bu "write" işaretidir. Üstü çizili $\bar{W}$, uç 0 iken yazma, 1 iken okuma yapıldığını gösterir.
- Aktarım $R/\bar{W}$'nin yükselen kenarında (ya da T4'ün düşen kenarında) başlar; başlangıçtan yaklaşık 75 ns sonra yazma tamamlanır. Bu süre boyunca adres geçerli kalmalıdır.

Okuma çevriminde adres yola çıkar, CS üretilir, işlemci okuma işaretini verir. Hafıza elemanı 65 ns sonra verisini veri yoluna çıkarır ve işlemci veriyi T4'ün düşen kenarında örnekler.

Hoca yol (bus) kavramını da açıkladı: örneğin $D_0$-$D_{15}$, 16 biti aynı anda paralel taşıyan hatlar demektir; anakart üzerinde sık biçimde yerleştirilmiştir.

## 8. SRAM Hücresi, Bit Dilimi ve RAM Entegresi

### 8.1 Kalıcı ve geçici hafıza

SRAM flip-flop ya da latch mantığında hücrelerden oluşur ve enerji sürdükçe değeri korur. DRAM'de değer kapasitedeki yüktür; kaçak akımlar yüzünden periyodik olarak yeniden yazılması gerekir. Geçici (volatile) hafıza enerji kesilince veriyi kaybeder (RAM). Kalıcı (non-volatile) hafıza enerji kesilse de veriyi korur; örneği bir önceki hafta görülen ROM'dur. ROM sigortaların yakılması ya da korunmasıyla programlanır ve bu yapı enerjiyle değişmediği için veri kalıcıdır.

### 8.2 Latch ve flip-flop farkı

Latch'te enable ucu seviye tetiklemelidir. Flip-flop'ta da enable vardır, ama kenar tetiklemelidir; bu, saat işaretinin yükselen ya da düşen kenarıyla tetiklemeye eşdeğerdir.

### 8.3 SRAM hücresi

Slayttaki hücre (ekrandan, 01:40:00) bir SR latch, bir Select girişi, çift raylı (dual rail) veri girişleri $B$ ve $\bar{B}$, çift raylı çıkışlar $C$ ve $\bar{C}$'den oluşur. Girişte ve çıkışta Select ile AND'lenen kapılar vardır. $m$ word ve word başına $n$ bitlik bir RAM, $m\cdot n$ hücreden ve ilgili devrelerden oluşur.

Select 0 iken S ve R uçlarına 0 gelir; SR latch 00 girişinde durumunu korur. Select 1 olunca giriş değerlerine göre içeri yazma yapılabilir. Select, tek bir bit için adresin kendisine karşılık gelir; daha büyük yapılarda adres uçlarını çözen bir dekoderden gelir.

### 8.4 SRAM bit dilimi

Birden fazla hücre üst üste konunca $2^n$ adet 1 bitlik word'ü tutan bir bit dilimi oluşur (ekrandan, 01:45:00). Her hücrenin seçimine word select denir. Kontrol hatları word select'ler, $R/\bar{W}$ ve bit select'tir; veri hatları data in ve data out'tur. Write logic dışarıdan gelen veriyi kendisi ve değili olarak hücrelere dağıtır, read logic hücreden çıkan veriyi dışarı aktarır. Adres bir dekoderden geçtiği için aynı anda yalnız bir word select aktiftir; data in bütün hücrelere ulaşsa da yalnız seçili hücreye yazılır.

Yazmada $R/\bar{W}=0$ ve bit select 1'dir; AND kapılarının girişleri 1 olduğu için (AND'de etkisiz eleman) veri ve değili seçili hücrenin S ve R uçlarına ulaşır. S=0, R=1 gelirse içeri 0, S=1, R=0 gelirse 1 yazılır. Okumada $R/\bar{W}=1$ olduğu için yazma tarafındaki kapılar 0 verir, S=R=0 olur ve hücre durumunu korur. Seçili hücrenin $C$, $\bar{C}$ çıkışları read logic'teki latch'e gider; böylece okuma işareti kesilse bile değer veri yoluna çıkarılabilir.

Bu dilimlerden $m$ tanesi yan yana konup aynı word select'lere bağlanırsa her gözü $m$ bit olan $2^n\times m$ kapasiteli bir yapı elde edilir.

### 8.5 $2^n\times 1$ RAM entegresi

Bir bit diliminden RAM entegresi yapmak için iki şey gerekir (ekrandan, 01:50:00):

- Dekoder: $n$ adres hattını $2^n$ word select hattına çözer. Örnekte 16x1 RAM için $A_3$-$A_0$ bir 4'ten 16'ya dekodere girer.
- Üç durumlu tampon: çıkıştaki tampon, birden fazla RAM entegresinin $c\times 2^n$ word'lük bir RAM'de birleştirilmesine izin verir.

Chip select, bit select gibi düşünülebilir. Entegre seçiliyse data in ve data out veri yoluna bağlıdır. Seçili değilse CS ile kontrol edilen üç durumlu tampon data out'u işlemcinin veri yolundan koparır, data in tarafında da durum değişikliği yapılmaz. Ayrı data in ve data out yerine iki yönlü iki üç durumlu tamponla tek bir veri yolu da kullanılabilir.

Dört adet 1 bitlik blok yan yana konup dekoderin aynı çıkışına bağlanırsa 2 adres girişiyle 4 göz seçilir ve her gözde 4 bit okunur: $2^2\times 4$ kapasite.

## 9. Satır-Sütun (Coincident) Seçimi

DRAM'lerde de karşılaşılan özel bir durumda satırlar ve sütunlar aynı adres uçlarıyla farklı zamanlarda seçilir. Veri çok yoğun saklandığı için erişim hem satır hem sütun dekoderiyle çözülür. İşlemcinin adres ucu sayısı aynıysa, örneğin T1 anında satır için, T2 anında sütun için farklı adres verilerek aynı 20 bitlik uçlar iki kez kullanılabilir. Bu durumda $2^{20}$ satır ve $2^{20}$ sütun ayrı ayrı seçilir, toplam $2^{20}\cdot 2^{20} = 2^{40}$ göz işaretlenebilir.

Slayttaki 16x1 RAM 4x4 hücre dizisiyle kurulur (ekrandan, 01:55:00): 2'den 4'e satır dekoderi word select'leri, enable girişli 2'den 4'e sütun dekoderi bit select'leri sürer; sütun dekoderinin enable ucu chip select'tir. Örneğin 1001 adresinde ilk iki bit 10 satırını, son iki bit 01 sütununu seçer.

Tek dekoderli yapıda bu RAM için 4 adres ucu gerekir ve 16 word select'ten biri seçilir. Satır-sütun seçiminde ise aynı 2 adres ucu iki farklı zamanda kullanılarak 16 gözden biri seçilir; karşılığında iki adres erişim zamanı gerekir. Slaytta adres uçları $A_0$-$A_3$ diye ayrı bağlanmış görünür, bu durum tek seferde 4 uç kullanmakla aynıdır.

Bloklar sütun seçimine ikişer ikişer sokulursa farklı bir arayüz elde edilir: 8x2 düzenleme (ekrandan, 02:50:00). Slayttaki örnekte 3 (011) adresinin ilk iki biti 1 numaralı satırı seçer, son bit 1 numaralı sütunu, yani 2 ve 3 numaralı bit dilimlerini erişir.

Genel bir SRAM bloğunda ortak bir $R/\bar{W}$ ucu (yazma uç 0 iken), entegreyi etkinleştiren bir CS ucu, adres yolu ve veri giriş/çıkış uçları vardır. CS 0 iken veri uçları yüksek empedanstadır. Bir yolun üzerine konan eğik çizgi ve sayı, o yolun kaç bitten oluştuğunu gösterir: slayttaki 64K x 8 RAM'de 16 bitlik adres yolu, 8 bitlik veri girişi ve 8 bitlik veri çıkışı vardır (ekrandan, 02:00:00).

## 10. SRAM Dizileri: Kapasite ve Veri Yolu Genişletme

Bir uygulamanın ihtiyacı tek bir çipin kapasitesinden büyükse çipler bir dizi halinde birleştirilir (ekrandan, 02:00:00). Word sayısını arttırmak adres uzunluğunu, word başına bit sayısını arttırmak veri giriş ve çıkış hatlarının sayısını arttırmayı gerektirir. CS hatları kullanılarak bütün adres, veri ve $R/\bar{W}$ hatları paralel bağlanır ve çözülmüş yüksek anlamlı adres bitleri CS'leri kontrol eder.

- Veri yolu genişletme: bloklar aynı anda seçilir. Adres sayısı aynı kalır, ama işlemcinin bir adreste gördüğü veri miktarı artar (örneğin 32 bit).
- Kapasite genişletme: bloklar dekoderli yapıyla farklı adreslerde seçilir. Her gözdeki veri miktarı aynıdır, ama dışarıdan görülen toplam göz sayısı artar.

Örneklerin ayrıntılı çözümleri Örnek Sorular bölümündedir (Soru 3, 4 ve 5). Ortak yöntem şudur: önce çipin ve hedef bloğun uç sayıları çıkarılır, sonra hedef kapasite çip kapasitesine bölünür. Word sayısı oranı kapasite genişletmesi için satır sayısını, bit genişliği oranı veri yolu genişletmesi için sütun sayısını verir.

$K$, $M$, $G$'nin ikili karşılıkları hatırlatıldı (ekrandan, 02:20:00): $2^{10}$ = K, $2^{20}$ = M, $2^{30}$ = G; yani 10, 20 ya da 30 bitle ifade edilebilen genişlikler. Her adres biti 0 ya da 1 olabildiği için $k$ bit $2^k$ farklı değer üretir; gereken adres ucu sayısı $\log_2(\text{göz sayısı})$'dır.

## 11. DRAM Hücresi

DRAM hücresi temelde bir transistör ve bir kapasite elemanıdır; kapasite de bir transistörden elde edilebildiği için iki transistörle oluşturulabilir. SRAM için ise 4 ya da 6 transistör gerektiği söylenmişti. Veri kapasitede yük olarak saklanır; yük kaçak akımlarla azalırsa yazılan 1 zamanla kaybolup 0'a dönebilir, ama 0 değerinin kaybolması diye bir durum yoktur. Blok gösteriminde $B$ veri girişi, $C$ çıkış ve Select seçim ucudur.

DRAM bit dilimleri SRAM'dekine benzer biçimde kurulur: her seçim ucu bir word select'tir ve $2^n\times 1$ bir DRAM dilimi oluşur. Satır-sütun seçimiyle veri daha yoğun yerleştirilir. Farklı DRAM mimarileri vardır, hoca bunların ayrıca incelenmesini önerdi.

## 12. Verilog Örneklerine Kısa Bakış

Dersin sonunda bir öğrenci, önceki derste gösterilen kodu sordu. Hoca bunun VHDL değil Verilog olduğunu belirtti ve MUX, dekoder, flip-flop, yarım toplayıcı, tam toplayıcı, $n$ bitlik toplayıcı, $n$ bitlik OR ve AND gibi temel elemanların Verilog tanımlarını kısaca gösterdi. Bir sonraki aşamada tek çevrimli bilgisayar (single cycle computer) tasarımına geçileceğini, orada kullanılan yazmaç dosyası (register file) için de örnekler olduğunu söyledi. Derleme ve benzetim için Icarus Verilog'u önerdi.

Örnek olarak 2x1 MUX gösterildi. Benzetim için iki dosya gerekir:

- Modül dosyası: 2x1 MUX davranışsal (behavioral) biçimde tanımlanır. `always` bloğu içinde değişen girişlere göre bir `if` kontrolüyle çıkış üretilir: seçim 0 ise çıkış A, 1 ise B olur. Hoca ekrandaki kodda küçük bir hata olabileceğini belirtti.
- Test bench dosyası: MUX modülünü kullanır, girişlerine 10 ns aralıklarla olası bütün değer kombinasyonlarını sırayla uygular, çıkışları inceler ve bir dalga biçimi (waveform) çizdirir.

<!-- BELİRSİZ: Verilog 2x1 MUX ve test bench kodu (02:51-02:53) karelerde yok; kodun kendisi nota alınmadı, iverilog ile derleme yapılmadı. -->

**Soru:** PLD uzantılı bir dosyada gösterilen daha karmaşık kod VHDL miydi? **Cevap:** Hayır. Bir önceki hafta görülen PAL, PLA, PLD devreleri FPGA'nın ilkel halleridir; o kod bir PLD entegresi için yazılmıştı. VHDL kodu IEEE standart kütüphanesinden modüller yükleyen tanımlarla başlar; Verilog ise `module` tanımlarıyla ilerler.

## Örnek Sorular

### Soru 1

(ekrandan, 00:15:00) Blok yapısı ve fonksiyon tablosu aşağıda verilmiş olan 4 bitlik paralel yüklemeli yazmacın iç yapısını gerekli sayıda T flip-flop, 4x1 çoğullayıcı ve basit lojik kapılar kullanarak tasarlayınız. Not: $q=(q_4q_3q_2q_1)_2$. Fonksiyon tablosu: $M_2M_1=00$: $\bar{q}$ (1'e tümleyen); $01$: $q$ (aktarma); $10$: $D_4D_3D_2D_1$ (paralel yükleme); $11$: $q+1$ (arttırma, $15+1=0$ kabul edilebilir).

> **Çözüm (derste verildi, ekrandan, 00:20:00 ve 00:25:00):** Her bit dilimi bir 4x1 MUX ve bir T flip-flop'tur; MUX çıkışı $T_i$'ye, seçim uçları ortak olarak $M_2M_1$'e bağlanır. MUX girişleri: 00 için 1, 01 için 0, 10 için $D_i\oplus q_i$, 11 için arttırma terimi. Arttırma terimleri durum tablosu ve Karnaugh haritalarından $T_1=1$, $T_2=q_1$, $T_3=q_2q_1$, $T_4=q_3q_2q_1$ çıkar. Bütün işlemler python ile doğrulandı.

### Soru 2

(ekrandan, 00:35:00) Kesikli çizgi ile belirtilmiş bölgede, SADECE blok yapısı ve fonksiyon tablosu verilmiş olan 1 bitlik karşılaştırıcılar kullanarak 2 bitlik karşılaştırıcı tasarlayınız. 1 bitlik karşılaştırıcı: $A_iB_i = 00 \to (=)$, $01 \to (<)$, $10 \to (>)$, $11 \to (=)$.

> **Çözüm (derste verildi, ekrandan, 00:40:00):** 1 bitlik karşılaştırıcıda $(>) = A\bar{B}$, $(<) = \bar{A}B$, $(=) = A\odot B$. İlk katta $A_1$-$B_1$ ve $A_0$-$B_0$ karşılaştırılır. $A>B = (A_1>B_1) + \overline{(A_1<B_1)}(A_0>B_0)$; ikinci terim, girişlerine $(A_0>B_0)$ ve $(A_1<B_1)$ verilen bir karşılaştırıcının $>$ çıkışıdır. $A<B = (A_1<B_1) + \overline{(A_1>B_1)}(A_0<B_0)$ aynı biçimde kurulur. $A=B$, iki $=$ çıkışının AND'idir. Üç çıkış python ile 16 satırda doğrulandı.

### Soru 3

(ekrandan, 02:20:00) 64K x 8 kapasitesindeki SRAM bloklarından kullanarak 256K x 8 kapasitesinde RAM bloğu tasarlayınız. Ders içinde sözlü soruldu (02:16:12): 64K x 8 SRAM'in kaç adres ucu vardır? Dekodere $A_1A_0$ bağlanırsa adresler nasıl dizilir (02:26:12)? RAM bloğunun CS'si tasarımda nereye karşılık gelir (02:32:29)?

> **Çözüm (derste verildi, ekrandan, 02:20:00 - 02:35:00):** $64K = 64\cdot 2^{10} = 2^{16}$, yani SRAM'de 16 adres ($A_0$-$A_{15}$) ve 8 veri ucu vardır. $256K = 2^{8}\cdot 2^{10} = 2^{18}$, yani RAM bloğunda 18 adres ($A_0$-$A_{17}$), 8 veri ($D_0$-$D_7$), bir $R/\bar{W}$ ve bir CS ucu vardır. $256K\times 8 / 64K\times 8$: bit genişlikleri aynı olduğu için veri yolu genişletme gerekmez; kapasite yönünde 4 SRAM kullanılır. Dört SRAM aynı anda seçilmemelidir; MUX'un tek çıkışı olduğu için MUX ile yapılamaz, bir 2x4 dekoder kullanılır: çıkışları SRAM'lerin CS'lerine bağlanır, aynı anda yalnız bir çıkış 1 olabilir. Dekoder girişlerine $A_{17}A_{16}$ bağlanır; böylece ilk 64K'lık adres bloğu birinci SRAM'de, ikinci 64K ikinci SRAM'de olur ve SRAM içindeki ardışık gözler RAM bloğunda da ardışık adres olur. Dekodere $A_1A_0$ bağlansaydı 0 adresi birinci, 1 ikinci, 2 üçüncü, 3 dördüncü, 4 yine birinci SRAM'de olurdu; yani aynı SRAM'de 0, 4, 8, ... adresleri bulunurdu. Kalan $A_0$-$A_{15}$ bütün SRAM'lere ortak bağlanır; $R/\bar{W}$ ve $D_0$-$D_7$ de ortaklanır, çünkü aynı anda yalnız bir SRAM seçilidir ve diğerlerinin veri uçları yüksek empedanstadır. RAM bloğunun CS'si dekoderin enable ucudur: enable 0 ise hiçbir SRAM seçilmez ve bütün veri uçları yüksek empedans olur.
>
> Çalışma örneği (ekrandan, 02:35:00): 3FFFFH adresine 00H yazılmak istenirse işlemci $A_0$-$A_{17}$'ye on sekiz tane 1, $R/\bar{W}$'ye 0, CS'ye 1, $D_0$-$D_7$'ye 00000000 çıkarır. $A_{17}A_{16}=11$ olduğu için dekoderin 3 numaralı çıkışı aktif olur; ilk üç SRAM yüksek empedanstadır. Dördüncü SRAM'in adres uçlarında FFFFH vardır, yani 00H bu SRAM'in son gözüne yazılır. Adres ayrıştırması python ile doğrulandı.

### Soru 4

(ekrandan, 02:40:00) 64K x 8 SRAM'lerden kullanarak 64K x 16'lık RAM bloğu tasarlayınız.

> **Çözüm (derste verildi, ekrandan, 02:40:00):** 64K x 8'de 16 adres ve 8 veri ucu, 64K x 16'da 16 adres ve 16 veri ucu vardır. $64K\times 16 / 64K\times 8$: word sayısı aynı, bit genişliği iki kat; 2 SRAM veri yolu genişletme yönünde kullanılır. İki SRAM aynı anda seçilmelidir: CS uçları birleştirilip RAM bloğunun CS'si yapılır, $R/\bar{W}$ uçları ortaklanır, $A_0$-$A_{15}$ ikisine ortak bağlanır; böylece iki SRAM'de aynı satır aktif olur. Birinci SRAM'in veri uçları $D_8$-$D_{15}$ (yüksek anlamlı byte, MSB), ikincisininki $D_0$-$D_7$ (düşük anlamlı byte, LSB) olur ve 16 bitlik word yan yana birleştirilir.

### Soru 5

(ekrandan, 02:45:00) 64K x 8 SRAM'lerden kullanarak 256K x 16'lık RAM bloğu tasarlayınız.

> **Çözüm (derste verildi, ekrandan, 02:45:00):** $256K\times 16 / 64K\times 8$: word oranı 4, bit oranı 2; 4 satır (kapasite genişletme) ve 2 sütun (veri yolu genişletme), toplam 8 SRAM. RAM bloğunda 18 adres ve 16 veri ucu vardır. Aynı satırdaki iki SRAM'in CS'leri ortaktır; satırların CS'leri $A_{17}A_{16}$ ile sürülen bir 2x4 dekoderden gelir, dekoderin enable ucu RAM bloğunun CS'sidir. $A_0$-$A_{15}$ ve $R/\bar{W}$ bütün SRAM'lere ortaktır. Her sütunun veri uçları kendi içinde ortaklanır; bir sütun yüksek anlamlı byte'ı ($D_8$-$D_{15}$), diğeri düşük anlamlı byte'ı ($D_0$-$D_7$) verir. Çip sayıları python ile doğrulandı.

## Dersin Toparlaması

Dersin ilk bölümünde kısa sınavın iki sorusu üzerinden iki tasarım yöntemi pekiştirildi. Birincisi, T flip-flop'lu senkron devrelerde ters tanım bağıntısıyla tasarım: paralel yükleme $T=D\oplus q$, arttırma ise bütün bitleri birlikte ele alan $T_1=1$, $T_2=q_1$, $T_3=q_2q_1$, $T_4=q_3q_2q_1$ fonksiyonlarıyla gerçekleşir. İkincisi, yalnız verilen bir blokla tasarım: hedef fonksiyonlar bulunur ve bloğun kendi çıkış fonksiyonları ($A\bar{B}$, $\bar{A}B$, XNOR) cinsinden yeniden yazılır.

İkinci bölümde hafıza birimleri işlendi: hafıza hiyerarşisi, bit/byte/word ve adres kavramları, Von Neumann/Harvard ve CISC/RISC ayrımları, $2^k\times n$ organizasyonu, CS ve $R/\bar{W}$ uçları, adres çözümleme ve yüksek empedans, dört zamanlı okuma/yazma çevrimleri, SRAM hücresi ve bit dilimi, dekoderli RAM entegresi, satır-sütun seçimi ve DRAM hücresi. Uygulamada SRAM'lerden kapasite genişletme (dekoder + yüksek anlamlı adres bitleri), veri yolu genişletme (ortak CS, yan yana veri uçları) ve ikisinin birleşimi çözüldü. Hoca bir sonraki aşamada tek çevrimli bilgisayar tasarımına ve yazmaç dosyasına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
