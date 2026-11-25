# Ders 6 Genişletilmiş Notu: Veri Yolu Yapıları, Seri Toplayıcı ve Komut Kümesi Mimarisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: Senkron Sayıcıda Kendi Kendini Düzeltme
- 2. Yazmaç Transferi İçin Üç Veri Yolu Yapısı
- 3. Ötelemeli Yazmaçlarla Seri Toplayıcı
- 4. Komut Kümesi Mimarisi ve Komut Biçimi
- 5. Adresleme Modları
- 6. Veri Transfer Komutları ve Yığın
- 7. Aritmetik, Lojik ve Bit İşlem Komutları
- 8. Öteleme ve Döndürme Komutları
- 9. Program Denetim Komutları
- 10. Koşullu Dallanma ve Bayraklar
- 11. Program Sayıcıyı Değiştiren Durumlar ve Kesmeler
- 12. Örnek Sorular

## 1. Tekrar: Senkron Sayıcıda Kendi Kendini Düzeltme

Ders, bir önceki haftanın son konusu olan senkron sayıcılarda kendi kendini düzeltme (auto-correction) mantığının kısa bir tekrarıyla başladı. Bütün durumları kullanmayan keyfi bir sayıcı düşünelim; örneğin 3 bitlik bir sayıcı yalnız 6 durumu belirli bir sırayla dolaşsın. Minimal fonksiyon elde etmek için kullanılmayan iki durum Karnaugh diyagramında don't care ($x$) kabul edilir. Sadeleştirme sırasında bu $x$ hücrelerinden bazıları 1, bazıları 0 alınır ve bu seçim kullanılmayan durumların doğal olarak hangi duruma gideceğini belirler.

Ardından sistemin kendini düzeltip düzeltemediğine bakılır. Kullanılmayan iki durum birbirine dönüyorsa, yani asıl sayma döngüsüne hiç girmeyen ayrı bir döngü oluşuyorsa devre bir hata sonucu bu durumlardan birine düşerse orada kalır. Bu durumda kullanılmayan durumlardan birinin asıl döngüdeki herhangi bir duruma dönmesi sağlanmalıdır. Bunun için Karnaugh diyagramında 1 olarak seçilmiş bir $x$ hücresi 0'a çevrilip devre yeniden tasarlanır.

## 2. Yazmaç Transferi İçin Üç Veri Yolu Yapısı

Ders kitabının slaytlarında yazmaçlar arası transfer için üç temel yapı vardır: her yazmacın önünde kendine adanmış bir MUX, bütün yazmaçların paylaştığı tek bir MUX ve ortak yol, ve MUX'suz üç durumlu (three-state) ortak yol. Hoca bu üç yapının hangi transferleri desteklediğini denetim işaretleri üzerinden tek tek inceledi.

Yazmaçların davranışı hepsinde aynıdır. Her yazmacın $n$ bitlik veri girişi, $n$ bitlik veri çıkışı ve bir yükleme (Load) ucu vardır. Yazmacın içindeki değer her zaman çıkış uçlarında hazırdır. Load işareti verildiğinde girişteki değer saatin yükselen kenarında içeri kopyalanır ve çıkışa yansır; Load gelmedikçe girişte ne olursa olsun içerideki değer değişmez.

### 2.1 Kombinasyonel ve ardışıl kısımlar

Slayttaki çizimde yazmaçlar (ardışıl kısımlar) mavi, MUX'lar ve bağlantılar (kombinasyonel kısımlar) siyah çizilmiştir (ekrandan, 00:15:00). Kombinasyonel kısımlar çıkış üretmek için saati beklemez; girişe değer geldiğinde kapı gecikmesi kadar süre sonra çıkış oluşur. Bu yüzden bir saat çevrimi içinde bütün MUX çıkışları ve yazmaç girişleri hazır olur.

Eşanlı transferlerde akla gelen soru şudur: R0'a bir değer yüklenirken bu yeni değer R0'ın çıkışından başka bir yazmacın girişine kadar gidip aynı çevrimde oraya da yüklenebilir mi? Yani "iki adım sonranın değeri" yüklenmiş olur mu? Hoca bunun olmadığını vurguladı. Yükleme saatin yükselen kenarında anlık olarak gerçekleşir; kenar geçtikten sonra yeni değerin başka yazmaçlara yayılıp yüklenmesi mümkün değildir, çünkü yükleme için ayrılmış bir zaman aralığı değil yalnız bir kenar anı vardır.

### 2.2 Adanmış (dedicated) MUX yapısı

Bu yapıda üç yazmacın her birinin önünde bir 2'ye 1 MUX vardır. Her MUX diğer iki yazmacın çıkışını alır ve seçtiğini kendi yazmacının girişine verir (ekrandan, 00:15:00). Hoca girişleri slayt üzerinde işaretledi:

```text
R0'ın MUX'u:  0 girişi <- R2,  1 girişi <- R1
R1'in MUX'u:  0 girişi <- R0,  1 girişi <- R2
R2'nin MUX'u: 0 girişi <- R0,  1 girişi <- R1
```

Denetim işaretleri üç yükleme ucu $L_0, L_1, L_2$ ve üç seçim ucu $S_0, S_1, S_2$'dir. MUX'lar 2'ye 1 olduğu için her birine tek seçim ucu yeter; toplam 6 denetim işareti vardır.

**R0 ← R1.** Yalnız R0'a yükleme yapılacağı için $L_0 = 1$, $L_1 = 0$, $L_2 = 0$ olur. R1 ve R2'nin girişinde de bir değer bulunur ama yükleme olmadığı için önemli değildir; bu yüzden $S_1 = x$, $S_2 = x$ (don't care). R0'ın MUX'unda R1, 1 numaralı girişte olduğu için $S_0 = 1$ (ekrandan, 00:20:00).

**R0 ← R1, R2 ← R1.** Virgülle yan yana yazılan transferler eşanlı (paralel) yapılır. R0 ve R2 yüklenecek: $L_0 = 1$, $L_1 = 0$, $L_2 = 1$. $S_0 = 1$ yine R1'i seçer, $S_1 = x$; R2'nin MUX'unda R1, 1 numaralı girişte olduğu için $S_2 = 1$ (ekrandan, 00:20:00).

**R0 ← R1, R2 ← R0.** Yükleme işaretleri aynıdır ($L_0L_1L_2 = 101$), $S_0 = 1$, $S_1 = x$; R2'nin MUX'unda R0, 0 numaralı girişte olduğu için $S_2 = 0$ (ekrandan, 00:20:00).

Burada bir öğrenci sorusu geldi.

**Soru:** İlk örnekte $L_2$ don't care olmamalı mı?
**Cevap:** Hayır. $L_2$ don't care bırakılırsa 1 de olabilir ve R2'ye istenmeyen bir değer yüklenir. Transfer ifadesinde R2'ye yükleme belirtilmemişse bu "yükleme" anlamına gelir; $L_2 = 0$ yazılmalıdır. Don't care yalnız yüklenmeyen yazmaçların MUX seçim uçlarında kullanılır. Kısaca, "yükle" emri yoksa "yükleme" emri vardır.

Buna göre adanmış MUX yapısı şunları destekler: kendisinden farklı bir kaynaktan tek hedefe yükleme, aynı kaynaktan farklı hedeflere eşanlı yükleme ve farklı kaynaklardan farklı hedeflere eşanlı yükleme.

### 2.3 MUX girişlerine fonksiyon koymak ve adanmış MUX'un kısıtı

Hoca, yapının yalnız saf transfer için değil, aritmetik ve lojik mikro işlemler için de kullanılabileceğini hatırlattı. Adanmış MUX yapısı sabit kalmak şartıyla, MUX girişlerine doğrudan yazmaç çıkışı yerine kombinasyonel devrelerin çıkışları verilebilir: iki yazmacın toplamı, bitwise AND'i, bir yazmacın tümleyeni ya da ikiye tümleyeni, ötelenmiş hali gibi. Örneğin R0'ın MUX'unun 0 girişine R1 + R2 getirilebilir.

Sonra şu soruyu sordu: Bu yapı hangi işlemi yapamaz? Öğrenciler toplama, öteleme ve aynı değerin iki çevrimde yayılması gibi önerilerde bulundu. Hoca, toplamanın ve ötelemenin de kombinasyonel devreyle MUX girişine bağlanabileceğini, dolayısıyla desteklendiğini söyledi. Aradığı cevap daha basitti: 2'ye 1 MUX yalnız diğer iki yazmacı gördüğü için **bir yazmaç kendi değerini kendine atayamaz**. R0 ← R0 anlamsız görünebilir, ama genelleştirilirse R0 ← $\overline{R0}$ (kendi bire tümleyenini kendine yazma) gibi kendi değerine bağlı bir işlem bu yapıda yapılamaz. MUX genişletilip her yazmacın önüne bütün kaynaklar (R0, R1, R2) ve bunların aritmetik/lojik fonksiyonları verilirse bu kısıt ortadan kalkar.

### 2.4 Tek ortak yol (single bus)

İkinci yapıda her yazmacın yine kendi yükleme ucu vardır, ama tek bir MUX bulunur. Bu MUX üç yazmacın çıkışını alır; çıkışı ortak yola (bus) verilir ve ortak yol bütün yazmaçların girişine gider (ekrandan, 00:30:00). Seçim uçları $S_1S_0$ hangi yazmacın yola çıkacağını belirler.

**R0 ← R1.** $L_0 = 1$, $L_1 = 0$, $L_2 = 0$; R1, 1 numaralı kanalda olduğu için $S_1S_0 = 01$. R1'in değeri bütün yazmaçların girişine, kendi girişi dahil, gelir; bu yapıda bir yazmaç kendi değerini kendine de yükleyebilir.

**R0 ← R1, R2 ← R1.** Yine $S_1S_0 = 01$ ile R1 yola çıkar; $L_0 = 1$, $L_1 = 0$, $L_2 = 1$ verilerek R0 ve R2'ye eşanlı yüklenir. Yani tek kaynaktan çok hedefe transfer desteklenir.

**Desteklenmeyen:** Bir öğrenci takası (swap) önerdi; hoca bunu ve genel olarak farklı kaynaklardan farklı hedeflere eşanlı transferi gösterdi. Örneğin R0 ← R1, R1 ← R0 aynı çevrimde yapılamaz, çünkü ortak yola bir çevrimde iki farklı değer çıkamaz.

Bu yapının adanmış MUX'a göre avantajı devre karmaşıklığının azalmasıdır: seçim uçlarının sayısı bir azalır (6 yerine 5 denetim işareti) ve üç MUX yerine tek MUX kullanılır.

> **Ders sonrası not:** Hoca bu karşılaştırmada "üç tane ikiye bir MUX yerine dörde bir MUX" dedi; slaytta ortak MUX 3'e 1 MUX olarak çizilmiştir (seçim için 2 bit yeter) (ekrandan, 00:30:00).

### 2.5 Üç durumlu (three-state) yol

Üçüncü yapıda MUX tamamen kalkar. Yazmacın veri çıkışı bir üç durumlu tampondan geçer ve veri girişiyle aynı çift yönlü hatta bağlanır; tamponun enable ucu ($E$) 1 iken yazmaç yola veri çıkarır, 0 iken yalnız yoldaki veriyi okuyabilir (ekrandan, 00:35:00). Bütün yazmaçlar tek ortak yola bağlıdır. Denetim işaretleri $E_0, E_1, E_2$ ve $L_0, L_1, L_2$'dir.

**R0 ← R1.** R1 yola çıkacağı için $E_0 = 0$, $E_1 = 1$, $E_2 = 0$; yalnız R0 yükleneceği için $L_0 = 1$, $L_1 = 0$, $L_2 = 0$ (ekrandan, 00:35:00).

Burada önemli kısıt şudur: **aynı anda yalnız bir enable 1 olabilir.** İki yazmaç birlikte yola veri çıkarırsa ve değerleri farklıysa (birinde 0, diğerinde 1) hat üzerinde kısa devre oluşur.

**R0 ← R0.** $E_0 = 1$, $L_0 = 1$, diğer bütün $E$ ve $L$ işaretleri 0. Yazmaç kendi değerini kendine kopyalayabilir.

**R0 ← R1, R2 ← R1.** $E_1 = 1$, $E_0 = E_2 = 0$; $L_0 = 1$, $L_1 = 0$, $L_2 = 1$. Tek sürücü kuralı bozulmaz, tek kaynaktan çok hedefe transfer yapılır.

**Desteklenmeyen:** R0 ← R1 ile birlikte R1 ← R0 gibi iki farklı kaynağın aynı anda yola çıkmasını gerektiren transferler yapılamaz, çünkü bu çakışmaya yol açar.

İşlev olarak üç durumlu yol ortak MUX yoluyla aynıdır; fark, MUX'un kaldırılıp yerine üç durumlu tamponlar ve çift yönlü uçlar kullanılmasıdır. Hoca, bu yapıların burada yalnız veri transferi için tanımlandığını, MUX'lar genişletilip girişlere kombinasyonel fonksiyonlar eklenerek yazmaçlar üzerinde aritmetik/lojik işlemlerin de yapılabileceğini tekrarladı.

## 3. Ötelemeli Yazmaçlarla Seri Toplayıcı

Ötelemeli yazmaçların bir saat girişi, bir seri girişi ve bir seri çıkışı vardır. İki $n$ bitlik ötelemeli yazmaç kaskat bağlanarak (birinin seri çıkışı diğerinin seri girişine) daha uzun bir yazmaç elde edilebilir; örneğin iki 4 bitlik yazmaçtan 8 bitlik bir yazmaç.

### 3.1 Problem

Tahtadaki problem (ekrandan, 00:45:00): 4 bitlik iki ötelemeli yazmaç kullanılarak 4 bitlik bir seri toplayıcı yapılacak ve işlem sonucu da yazmaçta saklanacak. Yazmaçlar toplanacak iki sayıyı tutar ve her saat darbesinde en düşük anlamlı bitten başlayarak birer bit gönderir. Toplayıcı her adımda yalnız sıradaki iki biti görür.

### 3.2 Onluk tabanda sezgi

Hoca önce kâğıt üzerinde onluk toplamayı hatırlattı (ekrandan, 00:45:00):

```text
  elde:  0 1 0 0
         1 2 8 7
       + 1 1 2 2
       ---------
         2 4 0 9
```

En düşük anlamlı basamakta başlangıçta elde yoktur: $7 + 2 = 9$, elde yok. $8 + 2 = 10$; 0 yazılır, 1 elde bir sonraki basamağa gider. $2 + 1 + 1 = 4$, elde yok. $1 + 1 = 2$. Sonuç 2409'dur.

Burada hoca öğrencilere hafızada neyin tutulması gerektiğini sordu. Bir öğrenci A ve B'den gelen bitlerin sonucunu önerdi; hoca toplam sonuçlarının ayrıca bir yazmaçta saklanacağını, ama ardışıl devre olarak hafızada tutulması gereken bilginin **bir önceki basamaktan elde gelip gelmediği** olduğunu söyledi. Yapılacak işlem buna göre değişir.

### 3.3 Durum diyagramı

Sistem ikilik tabanda çalışır. Girişler $A_i$ ve $B_i$, çıkış $S_i$'dir. Durum tek bir flip-flop ($q$) ile tutulur: 0 = elde yok, 1 = elde var (ekrandan, 00:50:00). İki giriş olduğu için her durumdan dört ok çıkar. Oklar "$A_iB_i$ / $S_i$" biçiminde yazılır:

```text
Durum 0 (elde yok):
  00/0 -> 0    (0+0+0 = 0, elde yok)
  01/1 -> 0    (0+1+0 = 1, elde yok)
  10/1 -> 0    (1+0+0 = 1, elde yok)
  11/0 -> 1    (1+1+0 = 10, elde var)
Durum 1 (elde var):
  00/1 -> 0    (0+0+1 = 1, elde yok)
  01/0 -> 1    (0+1+1 = 10, elde var)
  10/0 -> 1    (1+0+1 = 10, elde var)
  11/1 -> 1    (1+1+1 = 11, elde var)
```

(ekrandan, 00:55:00)

### 3.4 Durum tablosu ve fonksiyonlar

D flip-flop ile gerçekleme yapılacaktır. D flip-flop'ta bir sonraki durumda ne görülmek isteniyorsa o değer D girişine verilir, yani $D$ sütunu $Q$ sütununun aynısıdır (ekrandan, 00:55:00):

```text
A B q | Q | S | D
0 0 0 | 0 | 0 | 0
0 0 1 | 0 | 1 | 0
0 1 0 | 0 | 1 | 0
0 1 1 | 1 | 0 | 1
1 0 0 | 0 | 1 | 0
1 0 1 | 1 | 0 | 1
1 1 0 | 1 | 0 | 1
1 1 1 | 1 | 1 | 1
```

$S = f(A, B, q)$ ve $D = g(A, B, q)$ fonksiyonları bulunmalıdır. $D$ için Karnaugh diyagramı ($AB$ sütunlar 00, 01, 11, 10; $q$ satırlar):

```text
        AB=00  01  11  10
q = 0      0    0   1   0
q = 1      0    1   1   1
```

Buradan $D = AB + Aq + Bq$ çıkar (ara adım eklendi). Hoca bunun tanıdık bir fonksiyon olduğunu, tam toplayıcının elde çıkışıyla birebir aynı olduğunu gösterdi: tablonun her satırında "işlem sonucunda elde var mı?" sorusunun cevabı $D$ sütunudur. $S$ de tam toplayıcının toplam çıkışıdır: $S = A \oplus B \oplus q$. Bu mantıklıdır, çünkü $q$ zaten bir önceki adımın eldesidir ve D girişine de yeni elde bağlanır. Tablo ve iki fonksiyon Python ile sekiz satır için doğrulandı.

### 3.5 Devre

Elde bir tam toplayıcı modülü varsa devre doğrudan kurulur (ekrandan, 01:00:00):

- Tam toplayıcının A girişine A yazmacının seri çıkışı, B girişine B yazmacının seri çıkışı bağlanır.
- $C_{in}$ girişine D flip-flop'un $q$ çıkışı bağlanır; $C_{out}$ çıkışı flip-flop'un D girişine gider.
- Toplam çıkışı ($S$) saklanmak üzere bir yazmacın seri girişine geri verilir. Tahtadaki çizimde A yazmacının seri girişine 0, B yazmacının seri girişine $S$ bağlandı.
- Bütün saatler ortaktır, çünkü devre senkrondur. Başlangıçta flip-flop reset ile $q(t=0) = 0$ yapılır.

Her saat darbesinden önce iki yazmacın en sağdaki bitleri ve $q$ toplayıcının girişinde hazırdır; toplam ve elde oluşur. Saat kenarında yazmaçlar bir bit öteler, toplam biti yazmaca girer ve elde flip-flop'a yazılır. Dört saat darbesi sonunda iki sayının toplamı yazmaçta, son elde ise flip-flop'ta bulunur. Bu yapı da bir datapath'tir: yazmaçlar ve flip-flop ardışıl kısım, tam toplayıcı kombinasyonel kısımdır.

Hoca ardından ders kitabındaki hazır şekli gösterdi. Orada toplamın A yazmacına geri beslendiğini ve dört çevrim sonunda sonucun A yazmacında biriktiğini söyledi. <!-- BELİRSİZ: Ders kitabı şeklinin anına ait kare yok; toplamın hangi yazmaca yazıldığı altyazıdan alındı. -->

> **Ek bilgi (derste anlatılmadı):** Seri toplayıcı tek bir tam toplayıcı ve bir flip-flop ile $n$ bitlik toplama yapar ama $n$ saat çevrimi sürer; paralel (ripple carry) toplayıcı ise $n$ tam toplayıcıyla aynı işi tek çevrimde yapar. Bu, donanım miktarı ile hız arasındaki tipik bir ödünleşimdir.

Hoca bu bölümün sonunda dersin bu kısmında datapath kavramının tanımlandığını, çeşitli veri aktarım donanımlarının incelendiğini, yazmaç transfer dili notasyonunun görüldüğünü ve aritmetik/lojik işlem içeren atamaların kâğıt üzerinde nasıl tasarlanacağının gösterildiğini özetledi.

## 4. Komut Kümesi Mimarisi ve Komut Biçimi

Aradan sonra komut kümesi mimarisine (Instruction Set Architecture, ISA) geçildi. Bir algoritma yazıldığında assembly seviyesinde kodlanır, assembler ile makine koduna çevrilir, makine kodu bir program hafızasına yüklenir ve adım adım yürütülür. Bu süreçte işlemcinin hangi komutları desteklediği ISA'yı oluşturur.

### 4.1 İşlemciden beklenen komut grupları

Bir CPU tasarlanırken şunlar istenebilir: aritmetik işlemler, lojik işlemler, öteleme ve döndürme, bellekten veri okuma ve belleğe yazma. Bunların arasında en önemlilerinden biri program denetimidir. Hoca, yalnız sıralı komutlardan oluşan bir akışın aslında program sayılamayacağını, programı program yapan şeyin kontroller ve dallanmalar olduğunu vurguladı; if yapıları ve döngüler bunlarla kurulur.

Her komut grubunun arkasında bir donanım vardır. Yalnız aritmetik işlemler için ayrı bir modül, yalnız lojik işlemler için ayrı bir modül tasarlanabilir; ikisi bir denetim mantığında birleştirilirse aritmetik lojik birim (ALU) elde edilir. Bunun yanında aynı seviyede bir öteleme/döndürme modülü ve dallanmayı yöneten bir dallanma denetim birimi bulunabilir.

### 4.2 Program sayıcı

Program hafızasında sıradaki komutun adresini tutan yazmaç program sayıcıdır (PC); 8086'da Instruction Pointer olarak geçer. 8086'da IP kod segmentiyle birlikte kullanılarak 20 bitlik adres oluşturulur, ama derste daha basit bir model düşünüldü: PC program hafızasını tek başına adresler.

Bir basitleştirme daha yapıldı: her komut program hafızasında bir göz kaplasın. Bu RISC mimarisinde olası bir durumdur; RISC'te komutların boyutları ve yürütme süreleri eşittir, her komut bir çevrimde yürütülecek şekilde tasarlanır, karmaşık komut yoktur. CISC mimarisinde ise karmaşık komutlar vardır; komutların boyları ve yürütme süreleri birbirinden farklıdır ama karmaşık işlemler tek komutla yapılabilir.

Basit modelde her komuttan sonra PC bir sonraki gözü gösterecek şekilde artar. Bir karar noktasında koşul doğruysa PC'ye komutta verilen göreli adres (offset) eklenir ve program oraya dallanır. Yüksek seviyeli dillerdeki döngülerin assembly tarafında doğrudan karşılığı yoktur; döngüler koşullu ve koşulsuz dallanmalarla kurulur.

### 4.3 Komut biçimi

Hoca iki yönlü bir tasarım düşüncesi verdi. Örneğin program hafızası 14 bitlik gözlerden oluşuyorsa ve bütün komutlar 14 bitse, ya oluşturulmak istenen komut sayısına göre gerekli bit genişliğine karar verilir ya da eldeki bit genişliğine göre kaç komut ayrılabileceği belirlenir.

Bir komut üç alandan oluşur (ekrandan, 01:30:00):

```text
| Opcode | Mode | Address or operand |
```

- **Opcode:** Komutun işlevini, komut grubunu tanımlar. Aritmetik işlemlerin, lojik işlemlerin, döndürmelerin, bellekten okuma ve belleğe yazmanın kendi opcode'ları vardır. Opcode genişliği komut sayısını sınırlar; örneğin 5 bitlik opcode ile en fazla $2^5 = 32$ komut olabilir.
- **Mode:** İşlemin nasıl yapılacağını, yani adresleme modunu belirler: işlem yazmaçlar arasında mı, bir bellek adresi ile yazmaç arasında mı, bellek gözüne doğrudan adresle mi yoksa bir yazmaç üzerinden dolaylı olarak mı erişiliyor.
- **Address or operand:** Bellek işlemi yapılacaksa adres, yazmaçlarla işlem yapılacaksa yazmaçlar bu alana yerleştirilir.

İki operandlı komutlarda ilk operand aynı zamanda hedeftir. Üç operandlı komutlarda, örneğin MIPS'teki `add R1, R2, R3`, ilk operand hedef, sonraki iki operand kaynaktır.

### 4.4 Akümülatör

Akümülatör özel bir yazmaçtır; 8086'da AX buna karşılık gelir. Onu diğer yazmaçlardan ayıran şey ona özel komutların ve donanımın bulunmasıdır: aynı işlem akümülatörle yapıldığında daha hızlı çalışabilir. Genelde ALU sonuçlarının varsayılan olarak saklandığı yer akümülatördür; 8086'da AX bazı komutlarda gizli (örtük) operand olarak kullanılır.

## 5. Adresleme Modları

Adresleme modu, bir verinin bellekten nasıl okunacağını, yani etkin adresin (effective address) nasıl bulunacağını tanımlar. Tasarlanan bir işlemci bu modların hepsini, bir kısmını ya da yalnız birini destekleyebilir; ama kavramsal olarak hepsinin bilinmesi önemlidir.

### 5.1 Doğrudan adresleme örneği

Slayttaki örnekte bir komut iki adres gözü kaplar (ekrandan, 01:35:00):

```text
PC = 250
250: Opcode | Mode
251: ADRS
252: Next instruction
...
500: 800
```

Opcode "Load ACC", mod "Direct address", ADRS = 500'dür. İşlemci önce iki gözü okur (fetch), sonra komutu çözer (decode). Operand, veri belleğinin 500 numaralı adresindedir; işlemci oraya gider, 800 değerini getirir (operand fetch) ve yürütme aşamasında akümülatöre yazar: ACC ← 800. Doğrudan adreslemede adres değerinin kendisi komutun içinde bulunur ve doğrudan adres olarak kullanılır.

### 5.2 Doğrudan adresli dallanma

İkinci örnekte PC 300'ü gösterir. 300'de opcode ve mod, 301'de 500 adresi vardır; opcode "akümülatör 0 ise dallan", mod doğrudan adreslemedir. Komut çözüldüğünde: ACC = 0 ise PC 500 yapılır; ACC sıfır değilse sıradaki komuta geçilir. Komut 300 ve 301'i kapladığı için sıradaki komut 302'dedir.

RISC'te bütün komutlar aynı boyda olduğundan sonraki komutun adresini bulmak kolaydır; her komut 2 bayt ise PC'ye 2 eklenir. 8086 gibi değişken uzunluklu komutlarda ise opcode ve moda bakılarak komutun kaç bayt kapladığı belirlenir ve PC ona göre artırılır.

### 5.3 Ortak örnek ve tablo

Sonraki bütün örnekler aynı başlangıç durumu için yürütüldü (ekrandan, 01:35:00 ve 01:40:00):

```text
PC = 250; 250: opcode+mod (Load ACC), 251: 500, 252: sonraki komut
M[400] = 700, M[500] = 800, M[752] = 600, M[800] = 300, M[900] = 200
R1 = 400
```

Ders kitabının tablosu (ekrandan, 01:40:00):

```text
Mod                Sembol          Yazmaç transferi       Etkin adres  ACC
Direct             LDA ADRS        ACC <- M[ADRS]         500          800
Immediate          LDA #NBR        ACC <- NBR             251          500
Indirect           LDA [ADRS]      ACC <- M[M[ADRS]]      800          300
Relative           LDA $ADRS       ACC <- M[ADRS + PC]    752          600
Index              LDA ADRS (R1)   ACC <- M[ADRS + R1]    900          200
Register           LDA R1          ACC <- R1              --           400
Register-indirect  LDA (R1)        ACC <- M[R1]           400          700
```

**Doğrudan (direct).** Komuttaki adres operandın adresidir: ACC ← M[500] = 800.

**Anında (immediate).** Bazen bellekten okumak yerine yazmaca bilinen sabit bir başlangıç değeri yüklemek gerekir. Mod "immediate" ise komutun operand alanındaki sayının kendisi yüklenir: ACC ← 500. Etkin adres, sayının bulunduğu 251'dir. Türkçede "hemen adresleme" ya da sabit değer atama denir.

**Dolaylı (indirect).** Operand alanındaki adresin içeriği, asıl erişilecek bellek gözünün adresidir. M[500] = 800 olduğundan asıl adres 800'dür; ACC ← M[800] = 300. 800 adresini veren, içteki M[500] erişimidir.

**Göreli (relative).** Operand, PC'ye eklenecek bir uzaklıktır. 250'deki komut yürütülürken PC otomatik olarak sonraki komutu, yani 252'yi gösterir. Etkin adres $252 + 500 = 752$, ACC ← M[752] = 600. 8086'daki jump ve koşullu dallanma komutlarında makine kodundaki işaretli uzaklık PC'ye eklenir; işaretli olduğu için hem geriye (daha düşük adreslere) hem ileriye gidilebilir.

**İndisli (index).** Komuttaki adres bir tablonun (dizinin) başlangıç adresini, yazmaç ise tablonun kaçıncı gözüne gidileceğini gösterir. Etkin adres taban + indistir: $500 + 400 = 900$, ACC ← M[900] = 200. 8086'da bir dizinin SI numaralı gözüne erişim buna örnektir.

**Yazmaç (register).** Belleğe gidilmez, yazmacın içeriği doğrudan kullanılır: ACC ← R1 = 400.

**Yazmaç dolaylı (register-indirect).** Erişilecek bellek adresi yazmaçtadır. R1 = 400 olduğundan ACC ← M[400] = 700.

Tablodaki etkin adres ve ACC değerleri başlangıç durumuyla tek tek karşılaştırıldı ve tutarlı bulundu.

### 5.4 8086 karşılıkları

Öğrencilerin assembly dersini aldığını düşünen hoca, modların 8086 karşılıklarını tahtaya yazdı (ekrandan, 01:50:00):

- Doğrudan: `MOV AL,[100]` (köşeli parantez bellek erişimini gösterir).
- Anında: `MOV AL,100`.
- Dolaylı (bellek dolaylı): 8086'da adresin içeriğine gidip oradan yeni bir adres alan bir mod yoktur, örnek verilmedi.
- Göreli: `JLE L1`. Makine kodunda L1 etiketinin adresi, komutun bulunduğu yere göre işaretli 8 ya da 16 bitlik bir uzaklık olarak verilir ve PC'ye eklenir.
- İndisli: `MOV AL, dizi[SI]` biçimi.
- Yazmaç: `MOV AL,BL`.
- Yazmaç dolaylı: `MOV AL,[SI]`. <!-- BELİRSİZ: Altyazıda "MOVAL,SI" geçiyor; yazmaç dolaylı mod için 8086'da köşeli parantezli yazım gerekir, bu ana ait kare yok. -->

## 6. Veri Transfer Komutları ve Yığın

### 6.1 Tipik veri transfer komutları

Ders kitabının tablosu (ekrandan, 01:55:00):

```text
Load      LD
Store     ST
Move      MOVE
Exchange  XCH
Push      PUSH
Pop       POP
Input     IN
Output    OUT
```

Veri transfer komutları belleğe yazan ve bellekten okuyan, giriş/çıkış birimlerine veri gönderen ve onlardan veri okuyan, ayrıca yığını kullanan komutları kapsar. Temelde belleğe veri yazan ve bellekten veri getiren iki komut yeterli olabilir. Move ayrı bir grup olarak yazmaçlar arası transferi tanımlamak için kullanılabilir.

> **Ders sonrası not:** Hoca burada load'u "hafıza elemanına bir değer aktarma", store'u "hafızadan bir değeri getirme" diye tanımladı; doğrusu terstir. Load bellekten yazmaca okuma, store yazmaçtan belleğe yazmadır.

### 6.2 Exchange (takas)

Exchange komutu iki operandın yerini değiştirir (swap). C ile takas yapılırsa üç değişken ve üç adım gerekir (ekrandan, 01:55:00):

```c
int a, b, t;
t = a;
a = b;
b = t;
```

İşlemci XCH komutunu destekliyorsa aynı iş tek komutla yapılabilir. Hoca bunu üç çevrime karşı bir çevrim diye özetledi: derleyicinin ürettiği assembly kodu iyi optimize edilmemişse takas üç adımda yürür, XCH'yi kullanan optimize edilmiş kod ise tek adımda yürür. Bugün yüksek seviyeli dillerle program yazılıyor ve derleyicilerin optimizasyon seviyelerine çoğu zaman dokunulmuyor. Hoca, "assembly ne işimize yarar" sorusunun cevaplarından birinin bu olduğunu söyledi: işlemcinin yeteneklerini bilen biri derleyicinin ürettiği assembly kodunu inceleyip optimizasyon seviyesini değiştirebilir, hatta kodu elle düzenleyebilir.

### 6.3 Push ve pop, yığının kullanım alanları

Push ve pop, yığın denen özel bir bellek bölgesini kullanır. Yığın son giren ilk çıkar (LIFO) mantığıyla çalışır. Yığını yönetmek için ayrı bir işaretçi, yığın göstergesi (SP) vardır; hem bellek bölgesi hem de onu yöneten işaretçi donanımda gerçeklenmişse sistem push ve pop komutlarını destekler. Push yığının en üstüne yeni bir değer koyar, pop en üstteki değeri çeker; SP her işlemde otomatik olarak değişir.

Yığın şu amaçlarla kullanılır:

- Alt yordamlara parametre aktarımı.
- Program akışında geçici saklama alanı (değer yığına atılır, sonra geri çekilir).
- Alt yordam çağrılarında dönüş adreslerinin saklanması.

### 6.4 Yığın örneği

Slayttaki durumda SP = 101'dir; yığında 101'de C, 102'de B, 103'te A bulunur ve 100 boştur (ekrandan, 02:00:00). R1'in içeriği yığına atılırsa (push) önce SP bir azalarak sıradaki boş gözü, yani 100'ü gösterir; sonra R1'deki değer o adrese yazılır. Hoca örnekte R1'in içeriğini 400 alarak 400'ün 100 adresine yazıldığını söyledi. Yığından çekme (pop) yapılırken SP o anda dolu olan en üst gözü gösterir; o gözdeki değer okunur, sonra SP bir artar.

SP'nin azalması ya da artması yığının çalışma mantığına bağlıdır. 8086'da olduğu gibi burada da SP yüksek bir adresten başlar ve push yapıldıkça adres küçülür.

```text
PUSH R1:  SP <- SP - 1;  M[SP] <- R1
POP  R1:  R1 <- M[SP];   SP <- SP + 1
```

> **Ek bilgi (derste anlatılmadı):** Bu örnekte SP en üstteki dolu gözü gösterir, bu yüzden push'ta önce azaltma, pop'ta önce okuma yapılır. SP'nin ilk boş gözü gösterdiği tasarımlarda sıra tersine döner: push'ta önce yazma sonra azaltma, pop'ta önce artırma sonra okuma yapılır.

### 6.5 Giriş/çıkış komutları neden ayrı?

IN ve OUT, işlemciden dış dünyadaki birimlere veri gönderen ya da onlardan veri okuyan komutlardır. Bellek komutlarından ayrılmalarının nedenleri:

- İşlemci ve bilgisayar sistemi belirli bir elektriksel seviye standardına göre tasarlanmıştır; dış dünyaya yapılan bağlantılar farklı elektriksel ve lojik seviyelerde olabilir, bu yüzden araya fiziksel/elektriksel dönüştürücüler gerekir.
- İşlemci ile ona doğrudan bağlı birimler ortak bir standartla haberleşirken, bağlanan G/Ç cihazının kendine özgü bir standardı olabilir; cihazı uzun süre beklemek gerekebilir.
- Bellek birimleri az sayıdadır ama her biri büyük kapasitelidir; G/Ç birimleri çok sayıdadır ama her biri küçük bir adres alanı kaplar. Örneğin bir paralel giriş/çıkış birimi G/Ç uzayında 4 bayt kaplarken bir bellek birimi 512 kilobaytlık bir alan kaplayabilir.

Bu yüzden G/Ç cihazlarını bellekten ayırıp ayrı komutlarla ele almak daha yönetilebilir bir komut kümesi sağlar.

## 7. Aritmetik, Lojik ve Bit İşlem Komutları

### 7.1 Aritmetik komutlar

Ders kitabının tablosu (ekrandan, 02:05:00):

```text
Increment             INC
Decrement             DEC
Add                   ADD
Subtract              SUB
Multiply              MUL
Divide                DIV
Add with carry        ADDC
Subtract with borrow  SUBB
Subtract reverse      SUBR
Negate                NEG
```

**INC ve DEC.** Operandı bir artırır ya da bir azaltır. Aynı iş `ADD operand, 1` ile de yapılabilir, ama INC ve DEC'in ADD ve SUB'dan ayrı verilmesi çok sık görülür; bir birimlik artış ALU'da özel bir blokla ya da basit bir denetim algoritmasıyla daha hızlı yürütülebilir.

**ADD.** İki operandı toplar. İki operandlı mimaride sonuç ilk operanda yazılır; üç operandlı mimaride (MIPS'te `add r1, r2, r3`) sonuç ilk operanda, yani hedefe yazılır ve diğer iki operand kaynaktır.

> **Ders sonrası not:** Hoca bu noktada üç operandlı komutta "birinci operandımız kaynağı belirlemiş oluyor" dedi; dersin başında doğru olarak söylediği gibi ilk operand hedeftir (`add r1, r2, r3` ile $r1 \leftarrow r2 + r3$).

İşaretsiz toplamada oluşan taşmayı carry biti gösterir. 8 bitlik bir mimaride ADD, taşma olmadan 0 ile 255 arasındaki sonuçları verebilir; toplam 255'i aşarsa carry 1 olur. Yani işaretsiz sayılarda taşmayı carry biti belirtir.

İşaretli sayılarda 8 bitle $-128$ ile $127$ arası gösterilebilir. Çıkarma (ya da toplama) sonucu bu aralığın dışına çıkarsa işaretli taşma overflow ($V$) bayrağıyla izlenir.

**MUL ve DIV.** Verilen operandlar üzerinde çarpma ve bölme yapar; işaretsiz ve işaretli versiyonları tanımlanabilir.

**ADDC (add with carry).** Carry bayrağını iki operandla birlikte toplar, yani üç değeri toplar. Donanımı yalnız 8 bitlik toplamayı destekleyen bir mimaride, yazılım kütüphanesiyle 16 bitlik toplama yapmak için gereklidir: düşük anlamlı 8 bitin toplamından doğan elde, yüksek anlamlı 8 bitin toplamına ADDC ile aktarılır.

**SUBB (subtract with borrow).** Aynı fikrin çıkarma için olanıdır; 8 bitlik çıkarmaları bir kütüphaneyle 16 bite genişletmeyi sağlar.

**NEG.** Tek operand alır; operandın ikiye tümleyenini üretip aynı operanda yazar.

> **Ek bilgi (derste anlatılmadı):** 16 bitlik $X$ ile $Y$'nin 8 bitlik bir makinede toplanması: önce düşük baytlar ADD ile toplanır (carry oluşabilir), sonra yüksek baytlar ADDC ile toplanır, böylece düşük bayttan gelen elde yüksek bayta eklenmiş olur.

### 7.2 Lojik ve bit işlem komutları

Lojik ve bit işlem komutları lojik seviyede yapılan denetimler için gereklidir; örneğin bir operanddaki 1'lerin sayısını saymak ya da sayının sonundaki sıfırların (trailing zero) kaçıncı basamakta bittiğini bulmak. Bu gruptaki komutlar:

- CLR: operandı sıfırlar.
- SET: operandı birler.
- COMPLEMENT (NOT): operandın bire tümleyenini alır.
- AND, OR, XOR: bitwise işlemler.
- Carry bayrağına özel komutlar (8086'da da vardır): carry'yi sıfırlayan, birleyen ve tersleyen komutlar. Seri veri iletişiminde ya da sayıların anlam sırasını döndürmek gibi carry üzerinden çalışan işlemlerde kullanılır.

Hoca burada C dilinden bir ayrım hatırlattı: `if (A & B)` ile `if (A && B)` farklıdır. Tek `&` bitwise AND, çift `&&` lojik AND'dir. Donanım tarafında doğrudan desteklenen bitwise versiyonlardır; lojik işlem ayrı bir yapıdır.

## 8. Öteleme ve Döndürme Komutları

Ders kitabının tablosu (ekrandan, 02:10:00):

```text
Logical shift right       SHR    0 -> [ ... ] -> C
Logical shift left        SHL    C <- [ ... ] <- 0
Arithmetic shift right    SHRA   [MSB kendine geri beslenir ... ] -> C
Arithmetic shift left     SHLA   C <- [ ... ] <- 0
Rotate right              ROR    LSB hem MSB'ye hem C'ye
Rotate left               ROL    MSB hem LSB'ye hem C'ye
Rotate right with carry   RORC   [ ... ] -> C -> MSB
Rotate left with carry    ROLC   C <- [ ... ] <- C (eski C LSB'ye)
```

Döndürme ile öteleme arasındaki temel fark: döndürmede dışarı çıkan bit boşalan göze geri beslenir; ötelemede boşalan göze dışarıdan bir değer verilir ve çıkan bit geri dönmez.

### 8.1 Lojik öteleme

Sağa lojik ötelemede en düşük anlamlı bit carry'ye gider, her bit bir düşük anlamlı basamağa kayar, en yüksek anlamlı basamak boş kalır ve dışarıdan 0 ile beslenir. Sola ötelemede en yüksek anlamlı bit carry'ye gider, her bit bir üst basamağa kayar ve en düşük anlamlı basamağa 0 girer.

### 8.2 Aritmetik öteleme

Sola aritmetik öteleme (SHLA) sola lojik ötelemeyle aynı çalışır. Sağa aritmetik ötelemede (SHRA) amaç sayının işaretini korumaktır: bitler sağa kayar, en düşük anlamlı bit carry'ye gider ve boşalan en yüksek anlamlı basamağa sayının orijinal işaret biti yazılır. İşaret biti 0 ise 0, 1 ise 1 beslenir. Böylece pozitif sayı işareti korunarak 2'ye bölünür; işaret biti 1 olan negatif sayıda en yüksek iki bit 1 olur ve sayı yine 2'ye bölünmüş olur.

Hoca 4 bitlik bir örnek verdi. İkiye tümleyen gösteriminde $1110 = -2$'dir. SHRA ile en düşük anlamlı 0 carry'ye gider, diğer bitler bir sağa kayar ve en soldaki boş göze işaret biti 1 girer: $1111$. Bir öğrenci bunun $-1$ olduğunu söyledi; $-2$, $-1$ olmuş, yani sağa aritmetik öteleme işareti koruyarak 2'ye bölmüştür. <!-- BELİRSİZ: Tahtadaki 4 bitlik dizinin karesi yok; 1110 değeri hocanın söylediği -2'den kuruldu. -->

### 8.3 Ötelemede taşma

Öteleme ve döndürmede taşma şöyle tanımlanır: işlemden önce pozitif olan sayı işlemden sonra negatif olmuşsa ya da negatif sayı pozitif olmuşsa taşma vardır. SHRA'da işaret biti her zaman korunduğu için taşma olmaz. SHLA'da (ve SHL'de) ise taşma olabilir: örneğin en yüksek iki biti $01$ olan pozitif bir sayı sola ötelendiğinde 0 carry'ye gider, 1 en yüksek anlamlı bite geçer ve sonuç negatif olur.

### 8.4 Carry'li ve carry'siz döndürme

Carry kullanan döndürmede (RORC, ROLC) 8 bitlik yazmaç ve 1 bitlik carry birlikte 9 bitlik bir veri gibi döndürülür. Carry kullanmayan döndürmede (ROR, ROL) döndürme yazmacın kendi 8 biti üzerinde yapılır, ama çıkan bit carry'ye de kopyalanır.

Hoca kayan noktalı sayı gösterimiyle ilgili slaytları atladı.

## 9. Program Denetim Komutları

Ders kitabının tablosu (ekrandan, 02:15:00):

```text
Branch                    BR
Jump                      JMP
Call procedure            CALL
Return from procedure     RET
Compare (by subtraction)  CMP
Test (by ANDing)          TEST
```

Hoca bunları "programı program yapan şeyler" diye tanıttı: bir durumu kontrol edip ona göre aksiyon almak bu komutlarla olur; yalnız sıralı bir akışla algoritma koşturulamaz.

### 9.1 Koşullu dallanma, CMP ve TEST

Branch komutu çeşitli durumları kontrol ederek dallanmanın olup olmayacağını belirler. Dallanmadan önce bir karşılaştırma komutu yürütülmelidir.

**CMP.** Büyüklük, küçüklük, eşitlik, büyük eşit, küçük eşit gibi aritmetik karşılaştırmalar için kullanılır. CMP aslında çıkarma yapar. Dallanma açısından SUB da aynı bayrakları üretir, ama SUB sonucu ilk operanda yazarak onu bozar; CMP ise hiçbir operandı değiştirmez, yalnız bayrakları etkiler. Yalnız iki değeri karşılaştırmak isteniyorsa CMP, çıkarma sonucu zaten kullanılacaksa SUB anlamlıdır.

**TEST.** Bit bazında bir kontrol yapılacaksa, örneğin R1'in 7 numaralı biti 1 mi 0 mı, TEST kullanılır. TEST bitwise AND yapar; bayraklar uygun biçimde değişir ama sonuç saklanmaz. AND komutu ise 8086'da olduğu gibi sonucu ilk operanda yazar.

### 9.2 Örnek: `if (A > B)`

Tahtadaki akış (ekrandan, 02:20:00):

```c
if (A > B)
    f();
else
    g();
```

Karşılaştırma CMP ile yapılır ($A - B$), sonra "branch if greater" ile dallanılır. Bu komut çıkarma sonucunda belirli bayraklara bakar. Hoca, aynı bayraklara bakan birden çok komut adı olabileceğini söyledi: "branch if greater" ile "branch if not less or equal" aynı koşulu sınar; işaretsizde "branch if above" ile "branch if not below or equal" de aynıdır. Pratikte akışta hangi koşul yazılmışsa onun birebir karşılığı olan komut seçilmelidir; böylece kodun okunabilirliği artar.

### 9.3 Örnek: bir bitin denetimi

A'nın 3 numaralı biti 1 ise F, değilse G çalıştırılacaktır. TEST bitwise AND yaptığı için ilgilenilmeyen bitleri 0, ilgilenilen biti 1 olan bir maske uygulanır:

```text
TEST A, 08H     ; 0000 1000 maskesi, A'nın 3. biti
BNZ  L1         ; sonuç 0 değilse bit 1'dir, L1'e (F) dallan
```

AND sonucu 0 ise ilgilenilen bit 0'dır; 0 değilse bit 1'dir. Bu yüzden "branch if not zero" kullanılır ve F fonksiyonu L1'e yerleştirilir.

### 9.4 Koşulsuz dallanma, CALL ve RET

**JMP.** Koşulsuz dallanmadır; özellikle döngülerde kullanılır. Döngünün başında durum bir branch ile kontrol edilir, döngünün son adımında JMP ile tekrar bu kontrole gidilir.

**CALL ve RET.** Modüler programlama için kullanılır. Kodun fonksiyonlara bölünmesi bakım ve yönetilebilirlik açısından avantaj sağlar ve kod parçaları yeniden kullanılabilir. Çağrılan fonksiyon programdan farklı bir bellek bölgesinde olabilir. CALL'da iki şey olur: bulunulan yerin (dönüş) adresi bir yerde saklanır ve PC çağrılan fonksiyonu gösterecek şekilde güncellenir. RET saklanan dönüş adresini geri yükler, böylece PC ana programda kalınan yere döner.

> **Hocanın vurgusu:** Bir noktaya JMP ile gidilmişse geri JMP ile dönülebilir; ama CALL ile çağrılan bir fonksiyondan mutlaka RET ile dönülmelidir, çünkü dönüş adresinin saklanması ve geri yüklenmesi CALL/RET çiftinin içindedir.

## 10. Koşullu Dallanma ve Bayraklar

Koşullu dallanmalar iki seviyede incelendi: basit dallanmalar ve karmaşık dallanmalar. Karmaşık dallanmalar da işaretsiz ve işaretli sayı işlemleri sonrası olmak üzere ikiye ayrıldı.

### 10.1 Basit dallanmalar

Basit dallanmalar tek bir bayrağa bakar:

```text
BZ        Z = 1 ise dallan (branch if zero)
BNZ       Z = 0 ise dallan
BC        C = 1 ise dallan (branch if carry)
BNC       C = 0 ise dallan
BN / BM   N = 1 ise dallan (negatif; işaret biti, yani en yüksek anlamlı bit)
BP / BNN  N = 0 ise dallan (pozitif)
BV        V = 1 ise dallan (overflow)
BNV       V = 0 ise dallan
```

Overflow bayrağı işaretli sayılarda sonucun bit genişliğine sığmadığını gösterir; 8 bitlik işaretli sayılarda sonuç $-128 \dots 127$ aralığı dışındaysa $V = 1$ olur. Carry bayrağı ise işaretsiz sayılardaki taşmayı gösterir.

### 10.2 İşaretsiz ve işaretli adlandırma

Karşılaştırma her iki durumda da aynı çıkarma (CMP ya da SUB) ile yapılır ve tek bir sonuç ile bayraklar oluşur. Bu sonucun işaretsiz mi işaretli mi yorumlanacağı, hangi bayraklara bakılacağını değiştirir. Bu yüzden komut adları ayrılır: işaretsiz sayılarda göreli büyüklük için **above / below**, işaretli sayılarda **greater / less** kullanılır.

> **Ders sonrası not:** Hoca bu kısımda bir iki kez "işaretsiz sayılarda greater ve less" dedi; ders kitabı tablolarında ve hocanın genel anlatımında olduğu gibi greater/less işaretli, above/below işaretsiz sayılar içindir (ekrandan, 02:30:00 ve 02:45:00).

### 10.3 İşaretsiz sayılar için koşullar

Ders kitabının tablosu (ekrandan, 02:30:00). Buradaki $C$ bir borrow bitidir:

```text
BA   Branch if above          A >  B   C + Z = 0
BAE  Branch if above or equal A >= B   C = 0
BB   Branch if below          A <  B   C = 1
BBE  Branch if below or equal A <= B   C + Z = 1
BE   Branch if equal          A =  B   Z = 1
BNE  Branch if not equal      A != B   Z = 0
```

Hoca bu koşulları `CMP A, B` ($A - B$) sonrası için tek tek türetti (tahtada `CMP A,B ; A>B ise dallan ; BA L1`, ekrandan, 02:30:00):

- **BA ($A > B$).** $A$, $B$'den büyükse $A - B$'de borrow oluşmaz: $C = 0$. Sayılar eşit olsaydı sonuç 0 çıkar ve $Z = 1$ olurdu; yalnız büyükken dallanmak istendiği için $Z = 0$ da gerekir. İkisi birlikte $C + Z = 0$ ile sınanır: carry ile zero bayrağı OR'lanır, sonuç 0 ise L1'e dallanılır.
- **BAE ($A \ge B$).** Ya büyüktür ($C = 0$, $Z = 0$) ya eşittir ($C = 0$, $Z = 1$). İki durumda da $C = 0$ olduğundan yalnız $C = 0$'a bakmak yeterlidir.
- **BB ($A < B$).** Küçük sayıdan büyük sayı çıkarılınca mutlaka borrow oluşur: $C = 1$. Toplamada $C$ elde, çıkarmada borrow anlamındadır. Eşitlikte zaten borrow oluşmayacağı için $C = 1$'i yakalamak yeterlidir.
- **BBE ($A \le B$).** Küçükse $C = 1$; eşitse $Z = 1$ ve $C = 0$. İkisinden biri yeter: $C + Z = 1$.
- **BE / BNE.** Eşitliği yakalamak için yalnız zero bayrağına bakılır: $Z = 1$ eşit, $Z = 0$ eşit değil.

### 10.4 İşaretli sayılar için koşullar

Ders kitabının tablosu (ekrandan, 02:45:00):

```text
BG   Branch if greater           A >  B   (N xor V) + Z = 0
BGE  Branch if greater or equal  A >= B   N xor V = 0
BL   Branch if less              A <  B   N xor V = 1
BLE  Branch if less or equal     A <= B   (N xor V) + Z = 1
BE   Branch if equal             A =  B   Z = 1
BNE  Branch if not equal         A != B   Z = 0
```

İşaretli sayılarda işin içine taşma da girer. Hoca $A > B$ olan durumları işaret kombinasyonlarına göre ayırdı ve 8 bitlik sayılarla örnekledi (ekrandan, 02:40:00):

```text
A > B durumu                       Örnek              Sonuç (8 bit)        N  V
büyük pozitif - küçük pozitif      127 - 10 = 117     117                  0  0
büyük pozitif - negatif            127 - (-100) = 227 taşar, -29 görünür   1  1
küçük negatif - daha küçük negatif -10 - (-20) = 10   10                   0  0
negatif - en küçük negatif         -10 - (-128) = 118 118                  0  0
pozitif - negatif                  10 - (-10) = 20    20                   0  0
```

> **Ders sonrası not:** Hoca $-10 - (-128)$ için sonucu 127 dedi ve tahtaya öyle yazdı; doğru sonuç 118'dir. Sonucun 8 bitlik aralıkta kalması ve taşma olmaması değişmez.

$127 - (-100)$ örneğinde gerçek sonuç 227'dir; bu 8 bitlik işaretli aralığı aşar. Hoca bunu sayı doğrusu üzerinde gösterdi: $0 \dots 127$'den sonra $-128 \dots -1$ gelir; 127'den 100 adım daha ileri gidildiğinde sonuç negatif bölgeye düşer, yani işaret biti 1 olur. İki pozitif sayının (127 ve 100) toplanıp sonucun negatif çıkması zaten taşmanın tanımıdır.

Buradan çıkan sonuç: $A > B$ iken ya taşma olur ve işaret biti 1 çıkar ($N = 1$, $V = 1$) ya da taşma olmaz ve işaret biti 0 çıkar ($N = 0$, $V = 0$). $A > B$ olup taşmasız bir sonucun negatif çıkması mümkün değildir, çünkü o zaman $B$ daha büyük olurdu. Yani her durumda $N$ ile $V$ aynıdır ve $N \oplus V = 0$ olur. Eşitliği dışlamak için $Z = 0$ da gerekir; ikisi OR'lanarak **BG: $(N \oplus V) + Z = 0$** elde edilir. Eşitlik de dahil edilirse $Z$'nin 0 ya da 1 olması fark etmez, yalnız $N$ ile $V$'nin eşitliği aranır: **BGE: $N \oplus V = 0$**.

Küçüklük için $N$ ile $V$ farklı olmalıdır. $A < B$ iken $A - B$ taşma yoksa mutlaka negatiftir ($N = 1$, $V = 0$). Taşma ancak çok küçük bir negatif sayıdan büyük bir pozitif sayı çıkarılınca olur: örneğin $-127 - 10 = -137$ 8 bite sığmaz, sonuç pozitif görünür ($N = 0$, $V = 1$). Her iki durumda $N \oplus V = 1$ olur: **BL**. Eşitlik de eklenirse ya $N \oplus V = 1$ ya da $Z = 1$ olmalıdır: **BLE: $(N \oplus V) + Z = 1$**. Eşitlik ve eşitsizlik için yine yalnız $Z$'ye bakılır.

> **Ders sonrası not:** Hoca $-127 - 10$ örneğini ilk anlattığında sonucun negatif kaldığını ve $N = 1$ olduğunu söyledi; 8 bitlik aritmetikte $-137$ sığmadığı için sonuç $+119$ görünür, yani $N = 0$, $V = 1$ olur. Hoca dersin devamında BL koşulunu açıklarken bunu doğru biçimde "taşma var, N biti 0, V biti 1" diye verdi. Bütün örnekler Python ile 8 bitlik ikiye tümleyen aritmetiğinde doğrulandı.

## 11. Program Sayıcıyı Değiştiren Durumlar ve Kesmeler

PC'yi değiştiren üç durum vardır:

1. **Koşullu dallanma:** Koşul doğruysa PC, ilgili etiketi gösterecek şekilde göreli olarak değiştirilir (PC'ye bir değer eklenir ya da çıkarılır).
2. **CALL:** PC'ye doğrudan yeni bir değer yüklenir (dönüş adresi saklandıktan sonra).
3. **Kesme alt programları:** Bir kesme denetleyicisi tarafından sağlanır.

Kesme şöyle çalışır: işlemci bir iş yaparken dışarıdan bir kesme isteği gelir (örneğin dört farklı kaynaktan istek gelebilir). İstek karşılanacaksa işlemci bunu bir onay (acknowledge) işaretiyle karşı tarafa bildirir. Karşı taraf hangi kesmenin yürütüleceğini belirten bir kesme vektör adresi gönderir. İşlemci yaptığı işi yarıda bırakır, kaldığı yeri unutmamak için dönüş adresini saklar ve bu vektör adresine göre ilgili kesme alt programını yürütür; alt program bitince kaldığı yere döner. Böylece kesme tabanlı iletişimde PC'ye dolaylı olarak, sıfırdan yeni bir değer yüklenmiş olur.

## 12. Örnek Sorular

### Soru 1 (ekrandan, 00:20:00)

Adanmış MUX yapısında (R0'ın MUX'u: 0 ← R2, 1 ← R1; R1'in MUX'u: 0 ← R0, 1 ← R2; R2'nin MUX'u: 0 ← R0, 1 ← R1) aşağıdaki transferler için $L_0L_1L_2$ ve $S_0S_1S_2$ değerlerini bulunuz: (a) R0 ← R1; (b) R0 ← R1, R2 ← R1; (c) R0 ← R1, R2 ← R0.

> **Çözüm (derste verildi):** (a) $L_0 = 1$, $L_1 = L_2 = 0$; $S_0 = 1$, $S_1 = S_2 = x$. (b) $L_0 = 1$, $L_1 = 0$, $L_2 = 1$; $S_0 = 1$, $S_1 = x$, $S_2 = 1$. (c) $L_0 = 1$, $L_1 = 0$, $L_2 = 1$; $S_0 = 1$, $S_1 = x$, $S_2 = 0$.

### Soru 2 (derste sözlü, 00:22:43)

Adanmış 2'ye 1 MUX yapısı hangi tür işlemde sorun çıkarır?

> **Cevap (derste verildi):** Bir yazmaç kendi değerini (ya da kendi değerinin bir fonksiyonunu, örneğin R0 ← $\overline{R0}$) kendine yükleyemez, çünkü her MUX yalnız diğer iki yazmacı görür. MUX girişleri bütün kaynakları kapsayacak şekilde genişletilirse bu kısıt kalkar.

### Soru 3 (ekrandan, 00:30:00)

Tek ortak yol (3'e 1 MUX) yapısında R0 ← R1 ve R0 ← R1, R2 ← R1 için denetim işaretlerini yazınız. Bu yapı hangi transferi desteklemez?

> **Çözüm (derste verildi):** R0 ← R1: $L_0L_1L_2 = 100$, $S_1S_0 = 01$. R0 ← R1, R2 ← R1: $L_0L_1L_2 = 101$, $S_1S_0 = 01$. Yola bir çevrimde tek değer çıkabildiği için farklı kaynaklardan farklı hedeflere eşanlı transfer (örneğin R0 ← R1, R1 ← R0 takası) desteklenmez.

### Soru 4 (ekrandan, 00:35:00)

Üç durumlu yol yapısında R0 ← R1, R0 ← R0 ve R0 ← R1, R2 ← R1 için $E$ ve $L$ işaretlerini yazınız.

> **Çözüm (derste verildi):** R0 ← R1: $E_0E_1E_2 = 010$, $L_0L_1L_2 = 100$. R0 ← R0: $E_0E_1E_2 = 100$, $L_0L_1L_2 = 100$. R0 ← R1, R2 ← R1: $E_0E_1E_2 = 010$, $L_0L_1L_2 = 101$. Aynı anda yalnız bir $E_i$ 1 olabilir.

### Soru 5 (ekrandan, 00:45:00)

İki adet 4 bitlik ötelemeli yazmaç kullanarak 4 bitlik bir seri toplayıcı tasarlayınız; işlem sonucu da yazmaçta saklansın.

> **Çözüm (derste verildi, ekrandan 00:55:00 ve 01:00:00):** Durum elde bilgisidir (tek flip-flop). Durum diyagramı ve tablo Bölüm 3.3 ve 3.4'tedir. D flip-flop ile $D = AB + Aq + Bq$ (tam toplayıcı eldesi), $S = A \oplus B \oplus q$ (tam toplayıcı toplamı). Yazmaçların seri çıkışları tam toplayıcının A ve B girişlerine, $q$ $C_{in}$'e, $C_{out}$ D'ye bağlanır; toplam bir yazmacın seri girişine verilir, saatler ortaktır, başlangıçta $q = 0$. Dört saat darbesi sonunda toplam yazmaçtadır. Python ile 4 bitlik bir benzetim yapıldı: $1011 + 0110$ için yazmaçta $0001$, flip-flop'ta elde 1 kaldı ($= 17$).

### Soru 6 (derste sözlü, 00:44:20)

Seri gelen basamakları toplayan bir senkron ardışıl devrede hafızada tutulması gereken bilgi nedir?

> **Cevap (derste verildi):** Bir önceki basamaktan elde gelip gelmediği. Toplam bitleri ayrıca yazmaçta saklanır, ama ardışıl devrenin durumu yalnız eldedir.

### Soru 7 (ekrandan, 01:40:00)

PC = 250; 250'de "Load ACC" opcode'u ve mod, 251'de 500 vardır. M[400] = 700, M[500] = 800, M[752] = 600, M[800] = 300, M[900] = 200, R1 = 400. Doğrudan, anında, dolaylı, göreli, indisli, yazmaç ve yazmaç dolaylı modlarda etkin adresi ve ACC'ye yüklenen değeri bulunuz.

> **Çözüm (derste verildi):** Direct: EA 500, ACC 800. Immediate: EA 251, ACC 500. Indirect: EA = M[500] = 800, ACC 300. Relative: EA = 500 + 252 = 752, ACC 600. Index: EA = 500 + 400 = 900, ACC 200. Register: ACC = R1 = 400. Register-indirect: EA = R1 = 400, ACC 700.

### Soru 8 (derste sözlü, 02:11:19)

4 bitlik ikiye tümleyen gösteriminde $-2$'ye sağa aritmetik öteleme uygulanırsa sonuç nedir?

> **Cevap (derste verildi):** $1110 \to 1111$, yani $-1$. Sağa aritmetik öteleme işareti koruyarak 2'ye böler.

### Soru 9 (ekrandan, 02:20:00)

`if (A > B) f(); else g();` yapısı karşılaştırma ve dallanma komutlarıyla nasıl gerçeklenir?

> **Cevap (derste verildi):** `CMP A, B` ile $A - B$ yapılır, ardından "branch if greater" ile f'nin bulunduğu etikete dallanılır. Aynı bayraklara bakan "branch if not less or equal" de kullanılabilir, ama akıştaki koşulun birebir karşılığı olan komut okunabilirliği artırır.

### Soru 10 (derste sözlü, 02:20:15)

A'nın 3 numaralı biti 1 ise F, değilse G fonksiyonu çalıştırılacaktır. Hangi komutlar kullanılır?

> **Cevap (derste verildi):** `TEST A, 08H` ile yalnız 3. bit maskelenir; sonuç 0 değilse bit 1'dir: `BNZ L1` ile F'nin bulunduğu L1'e dallanılır.

### Soru 11 (ekrandan, 02:30:00)

`CMP A, B` sonrası işaretsiz sayılar için BA, BAE, BB ve BBE komutlarının bakması gereken bayrak koşullarını türetiniz.

> **Çözüm (derste verildi):** BA: borrow yok ve eşit değil, $C + Z = 0$. BAE: $C = 0$. BB: borrow var, $C = 1$. BBE: $C + Z = 1$.

### Soru 12 (ekrandan, 02:40:00)

8 bitlik işaretli sayılarda $A > B$ olan durumlar için $A - B$ işleminin $N$ ve $V$ bayraklarını inceleyerek BG koşulunu türetiniz.

> **Çözüm (derste verildi):** $A > B$ iken ya taşmasız pozitif sonuç ($N = 0$, $V = 0$; $127 - 10 = 117$) ya da taşmalı ve negatif görünen sonuç ($N = 1$, $V = 1$; $127 - (-100) = 227$, 8 bitte $-29$) çıkar. Her durumda $N \oplus V = 0$; eşitliği dışlamak için $Z = 0$. Sonuç: $(N \oplus V) + Z = 0$. $A < B$ için $N \oplus V = 1$ olur (örneğin $-127 - 10$: $N = 0$, $V = 1$).

## Dersin Toparlaması

Dersin ilk yarısında yazmaç transferi için üç veri yolu yapısı karşılaştırıldı. Adanmış MUX farklı kaynaklardan farklı hedeflere eşanlı transfere izin verir ama 2'ye 1 MUX'larla bir yazmaç kendine yükleme yapamaz. Ortak MUX yolu ve üç durumlu yol daha az denetim işareti ve daha basit donanımla tek kaynaktan çok hedefe transferi destekler, ama bir çevrimde yola tek değer çıkabildiği için takas gibi işlemleri yapamaz. Ardından ötelemeli yazmaçlarla bir seri toplayıcı tasarlandı; durumun yalnız elde bilgisi olduğu, durum fonksiyonunun da tam toplayıcının elde ve toplam çıkışlarına indirgendiği görüldü.

İkinci yarıda komut kümesi mimarisine geçildi: komut biçimi (opcode, mod, adres/operand), yedi adresleme modu ve ders kitabındaki ortak örnek üzerinden etkin adres hesabı, veri transfer, aritmetik, lojik, öteleme/döndürme ve program denetim komut grupları incelendi. Son olarak koşullu dallanmaların işaretsiz sayılarda $C$ ve $Z$, işaretli sayılarda $N \oplus V$ ve $Z$ bayraklarıyla nasıl gerçeklendiği türetildi ve PC'yi değiştiren dallanma, CALL ve kesme durumları özetlendi. Bir sonraki derste ALU'nun (aritmetik, lojik ve öteleme birimlerinin) nasıl tasarlanacağı ve register file ile birleştirilmesi, sonra da basit bir işlemci tasarımına doğru ilerlenmesi planlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
