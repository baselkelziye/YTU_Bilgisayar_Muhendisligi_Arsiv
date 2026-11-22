# Ders 13 Genişletilmiş Notu: Kısa Sınav Çözümü, Sanal Bellek, TLB ve Sayfa Değiştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kısa Sınav Çözümü: Kontrol Kelimesi ve Komut Kodlama
- 2. Kısa Sınav Çözümü: Tam Toplayıcılarla Aritmetik Birim
- 3. Kısa Sınav Bonus Soruları
- 4. Bellek Hiyerarşisinde Sanal Belleğin Yeri
- 5. Sanal Bellek Kavramı ve Temel Tasarım Soruları
- 6. Parçalanma Sorunu ve Sayfalama
- 7. Adres Çevirisi ve Sayfa Tablosu
- 8. Page Fault ve Adres Eşlemenin Matematiksel Tanımı
- 9. Cache ile Sanal Belleğin Karşılaştırılması
- 10. TLB (Translation Lookaside Buffer)
- 11. Sayfa Değiştirme Politikaları
- 12. Bütünleşik Örnek: TLB, Sayfa Tablosu ve L1 Cache
- 13. Cache Örnekleri
- 14. Örnek Sorular

## 1. Kısa Sınav Çözümü: Kontrol Kelimesi ve Komut Kodlama

Dönemin son dersi, ikinci kısa sınavın çözümüyle başladı. Birinci soru iki kısımdan oluşuyordu: verilen komutlar için kontrol kelimesini yazmak ve verilen komutları makine koduna çevirmek. Soruda derste görülen tek çevrimli bilgisayar mimarisi, komut kümesi (instruction set), function unit'in fonksiyon tablosu ve komut formatları verilmişti. Yani çözüm için gereken bütün bilgi soru kağıdındaydı (ekrandan, 00:05:00).

Ekranda görülen kontrol kelimesi kodlaması şöyledir:

| Alan | Anlamı ve kodları |
|---|---|
| DA, AA, BA | R0 = 000, R1 = 001, ..., R7 = 111 |
| MB | Register = 0, Constant = 1 |
| FS | $F = A$: 0000, $A+1$: 0001, $A+B$: 0010, $A+B+1$: 0011, $A+\bar B$: 0100, $A+\bar B+1$: 0101, $A-1$: 0110, $A$: 0111, $A \wedge B$: 1000, $A \vee B$: 1001, $A \oplus B$: 1010, $\bar A$: 1011, $B$: 1100 |
| MD | Function = 0, Data in = 1 |
| RW | No Write = 0, Write = 1 |

Komut formatları da ekrandaydı: (a) register formatı Opcode (15-9), DR (8-6), SA (5-3), SB (2-0); (b) immediate formatı Opcode, DR, SA, OP (2-0); (c) jump ve branch formatı Opcode, AD (sol, 8-6), SA (5-3), AD (sağ, 2-0).

### 1.1 Kontrol kelimesinin yazılması

Yöntem her komut için aynıdır: komut kümesi tablosuna gidilir, komutun hangi kanalları kullandığına bakılır, kullanılmayan alanlar "don't care" bırakılır.

- **Store:** Komut kümesinde store, RA ve RB parametrelerini alır, D parametresi yoktur. Bu yüzden DA "don't care" olur. A kanalı adresi, B kanalı veriyi verir. İşlem B kanalından çıkmalıdır, bu yüzden MB register seçilir. Belleğe yazma olduğu için MW = 1'dir. Function unit, MD çıkışı, branch ve jump kontrolleri kullanılmaz; bunlar "don't care" olur. Koşullu ya da koşulsuz dallanma olmadığı için PL = 0'dır.
- **XOR:** Üç operand vardır: hedef, A adresi, B adresi. Sonuç B kanalından gelir (MB = 0), function unit'te XOR seçilir (FS = 1010). Sonuç MD üzerinden hedef yazmaca aktarılır (MD = 0), register file'a yazma vardır (RW = 1), belleğe yazma ve dallanma yoktur.
- **Move B:** Hedef ve B kanalı kullanılır, A kanalı kullanılmaz. Fonksiyon tablosunda $F = B$ satırı 1100'dür. Sonuç hedefe yazılır (RW = 1).
- **Add immediate:** Immediate formatında sabit için 3 bitlik bir alan ayrılmıştır. Komut hedef, A ve operand kullanır; örnekteki 3 değeri OP alanına ikilik olarak (011) gömülür. MB = 1 seçilir, çünkü sabit değer komuttan gelir ve function unit'e B girişi yerine aktarılır. FS, toplama için 0010'dur. Sonuç register file'a yazılır.
- **Jump:** Koşulsuz dallanmadır ve yalnız A kanalını kullanır. Örnekte A kanalı R4'ü gösterdiği için AA = 100 yazılır, diğer alanlar "don't care" olur. Aritmetik işlem yapılmaz; yalnız program counter değişir, bu yüzden PL ve JB ile koşulsuz dallanma belirtilir.

### 1.2 Komutun makine koduna çevrilmesi

İkinci kısımda her komutun opcode'u komut kümesi tablosundaki opcode sütunundan alınır, operandlar formata göre yerleştirilir.

- **Add:** Üç parametre kullanır, register formatıdır; DR, SA ve SB kodlanır.
- **Load immediate:** Komutta belirtilen sabit bir değeri yazmaca yükler. Immediate formatını kullanır: hedef ve operand vardır, A kanalı boştur. Operandın B tarafından gelmesinin nedeni, komuttan gelen sabitlerin function unit'e yalnız B girişi üzerinden aktarılabilmesidir.
- **Branch if negative:** "R7'ye bak, değer negatifse PC'yi $-20$ ofset kadar değiştir" anlamındadır. Jump ve branch formatı kullanılır; ofset AD (sol) ve AD (sağ) alanlarına bölünür, R7 de SA alanına yazılır. $-20$ değeri 6 bitlik ikiye tümleyenle $101100$'dür.
- **OR:** Üç operand verilir.
- **Shift right:** B kanalı ve hedef kullanılır, A kanalı "don't care" olur. Kaynak R2 (SB alanı), hedef R4'tür.

## 2. Kısa Sınav Çözümü: Tam Toplayıcılarla Aritmetik Birim

İkinci soruda aritmetik birim için 16 fonksiyonlu bir tablo verilmişti ve devrenin MUX katı kullanılarak tasarlanması isteniyordu. 16 fonksiyon için 4 seçim biti ($S_3, S_2, S_1, S_0$) ve 16'ya 1'lik MUX'lar gerekir. Soruda bir kısıt da vardı: fonksiyon seçme bitlerinin en düşük anlamlısı doğrudan tam toplayıcının elde girişine (carry in) bağlanmalıydı.

### 2.1 Genel yapı

Tam toplayıcılarla bir aritmetik birim kurmanın en genel hâlinde A sayısı ve kontrol bitleri bir "A input logic" bloğundan geçip toplayıcının X girişine, B sayısı ve kontrol bitleri bir "B input logic" bloğundan geçip Y girişine bağlanır. Elde girişi de bir "Cin input logic" bloğundan gelir (ekrandan, 00:10:00):

$$X = f_1(A, S), \quad Y = f_2(B, S), \quad C_{in} = f_3(A, B, S)$$

Bulunması gereken $f_1$, $f_2$ ve $f_3$ fonksiyonlarıdır. Soruda verilen kısıt yüzünden $f_3$ doğrudan $C_{in} = S_0$ olur. Bu durumda elde girişi tabloya kopyalanır ve her fonksiyon için yalnız X ve Y'ye ne verileceği kalır.

### 2.2 Fonksiyonların gerçeklenmesi

Her işlem $F = X + Y + C_{in}$ biçiminde düşünülür. Ekranda tablonun son satırları görülüyordu: 10 $A + B'$ (complement addition), 11 $A + B + 1$ (add with carry), 12 $B'$ (complement B), 13 $1$ (one), 14 $A' + B$ (complement addition), 15 $A' + B' + 1$ (complement add with carry) (ekrandan, 00:10:00). Hoca fonksiyonları sırayla şöyle gerçekledi:

| Fonksiyon | $C_{in}$ | X | Y | Açıklama |
|---|---|---|---|---|
| $A + B$ | 0 | A | B | Bitler doğrudan bağlanır |
| $A$ | 1 | A | 1111... | $A + (-1) + 1 = A$ |
| $A + 1$ | 1 | A | 0 | Artı 1 eldeden gelir |
| $A - 1$ | 0 | A | 1111... | $-1$, B'lerin hepsi 1 yapılarak verilir |
| $B + 1$ | 1 | 0 | B | |
| $B - 1$ | 0 | 1111... | B | |
| $A - B$ | 1 | A | $\bar B$ | $A + \bar B + 1$ |
| $\bar A$ | 0 | $\bar A$ | 0 | |
| $0$ | 1 | 1111... | 0 | $-1$ X'ten ya da Y'den verilebilir |
| $A + \bar B$ | 0 | A | $\bar B$ | |
| $A + B + 1$ | 1 | A | B | |
| $\bar B$ | 0 | 0 | $\bar B$ | |
| $1$ | 1 | 0 | 0 | |
| $\bar A + B$ | 0 | $\bar A$ | B | |
| $\bar A + \bar B + 1$ | 1 | $\bar A$ | $\bar B$ | |

<!-- BELİRSİZ: Tablonun 0-9 numaralı satırlarının sırası ekranda görünmüyor; yukarıdaki ilk dokuz satır hocanın anlatım sırasıdır, tablo numaraları doğrulanamadı. -->

Devre 1 bitlik tam toplayıcılarla çizildiğinde dikkat edilmesi gereken nokta elde zinciridir: her dilimin elde girişine bir önceki dilimin elde çıkışı bağlanır (ör. 4. dilimin elde girişine 3. dilimin elde çıkışı). $S_0$ yalnız 0. bitteki tam toplayıcının elde girişine bağlanır. 8 bitlik hazır bir tam toplayıcı kullanılırsa MUX çıkışları ilgili $X_i$, $Y_i$ bitlerine bağlanır. Bütün MUX'ların seçim uçları ortaktır ve fonksiyon seçme bitlerine bağlanır.

### 2.3 Bayraklar

- **S (işaret):** sonucun en yüksek anlamlı biti.
- **C (elde):** en yüksek anlamlı bitin toplamından çıkan elde.
- **Z (sıfır):** bütün toplam bitleri NOR'dan geçirilir.
- **V (taşma):** $C_6$ ile $C_7$'nin farklı olması, yani $V = C_6 \oplus C_7$.

## 3. Kısa Sınav Bonus Soruları

### 3.1 CMP A, B sorusu

Soru, CMP A, B komutu yürütüldüğünde V = 1, N = 0, C = 1 ve Z = 0 üreten bir A, B ikilisi istiyordu (ekrandan, 00:15:00). Hocanın çözümü şöyledir:

- CMP bir çıkarma işlemidir.
- **C = 1:** C burada borç (borrow) görevindedir. A ve B işaretsiz sayı olarak ele alındığında $A < B$ olmalıdır (koşul 1). Bu, ya iki sayının en anlamlı bitleri aynıyken A'nın genliğinin küçük olması ya da A'nın en anlamlı biti 0, B'ninki 1 iken mümkündür.
- **Z = 0:** $A \neq B$ olmalıdır.
- **V = 1 ve N = 0:** Sonuç $-128$'den aşağı doğru taşmalıdır. İşlem $A + (-B)$ olarak düşünülürse iki negatif sayının toplamı pozitif çıkmalıdır. Bunun için A çok küçük bir negatif sayı (koşul 2: en anlamlı biti 1), B çok büyük bir pozitif sayı (koşul 3: en anlamlı biti 0) olmalıdır.
- Koşul 2 ve 3 sağlanırsa işaretsiz gösterimde A, B'den büyük olur; koşul 1 sağlanamaz. Sonuç: bu bayrakları üreten hiçbir A, B ikilisi yoktur.

**Soru:** Bu soruyu sayısal bir örnekle gösterebilir miyiz? **Cevap:** Böyle bir ikili olmadığı için verilecek her örnek "olmayan" örneğidir. Örneğin A = 0, B = 1 alınırsa $-B$ ikiye tümleyenle yazılır (ilk 1'e kadar bitler olduğu gibi bırakılır, sonrası tersine çevrilir), toplamda $C_6$ ve $C_7$ eldeleri oluşmaz, $V = C_6 \oplus C_7 = 0$ ve işaret biti 1 çıkar; istenen sonuç elde edilmez. Hoca, sorunun bonus olduğu için "ikili örneği verin" ifadesinin bilerek yanıltıcı seçildiğini söyledi.

> **Ders sonrası not:** Bu sonuç C'nin borç olarak yorumlanmasına bağlıdır. Python ile bütün 8 bitlik ikililer denendiğinde borç yorumunda hiçbir ikili çıkmadı. Mano & Kime'deki function unit'te çıkarma $A + \bar B + 1$ ile yapılır ve C bu toplamanın elde çıkışıdır; bu yorumda C = 1 işaretsiz $A \ge B$ demektir. O zaman örneğin $A = 80_{16}$ ($-128$), $B = 01_{16}$ için sonuç $7F_{16}$ olur ve V = 1, N = 0, C = 1, Z = 0 elde edilir.

### 3.2 Opcode sayısı sorusu

10 bit uzunluğunda komutlar kullanan bir işlemcide komut formatı opcode, operand 1, operand 2 biçimindedir ve 8 yazmaç vardır. Her operand için $\log_2 8 = 3$ bit gerekir; iki operand 6 bit tutar. Geriye 4 bit kalır ve bunlarla $2^4 = 16$ farklı opcode tanımlanabilir.

## 4. Bellek Hiyerarşisinde Sanal Belleğin Yeri

Haftanın konusu sanal bellektir (virtual memory). Cache ve sanal bellek, bellek hiyerarşisinde birbirini tamamlayan iki alt başlıktır.

Cache, ana bellekten işlemciye veri aktarımını hızlandıran bir iyileştirmedir. Her veri erişiminde belleğe gitmek yerine araya daha hızlı ama kapasitesi daha düşük bir bellek birimi konur. Önceleri işlemcinin dışında olan cache, zamanla işlemci yongasının içine girmiştir; güncel işlemcilerde L1, L2, L3 cache bulunur. Cache iki yerellik özelliğinden yararlanır:

- **Uzamsal yerellik (spatial locality):** Bir dizi üzerinde çalışırken bir sonraki döngüde büyük olasılıkla hemen sonraki adrese erişilir; adres komşuluğu vardır.
- **Zamansal yerellik (temporal locality):** Aynı adrese farklı zamanlarda tekrar tekrar erişilebilir.

Bu yüzden bellekten veri okunurken veri işlemciye doğrudan değil, bir blok hâlinde cache'e kopyalanır ve cache'ten okunur. Ekrandaki tekrar slaytı da şunu özetliyordu: cache zorunlu değildir, işlemci aritmetiği yapar, bellek veriyi tutar, cache yalnız aktarımı hızlandırır; hiyerarşinin her seviyesi bir üst seviyenin alt kümesidir (ekrandan, 00:25:00).

Benzer mantık hiyerarşinin öbür ucunda da geçerlidir. Ana belleğin kapasitesi sınırlıdır, ama çalıştırılacak programlar ya da program parçaları bu kapasiteden büyük olabilir. O zaman programın yalnız gereken parçaları ikincil bellekten ana belleğe getirilir. Aranan veri ana bellekte yoksa ikincil bellekten getirilmelidir. Tıpkı cache'te bir bloğun nereye düşeceğinin eşleştirilmesi gibi, burada da ikincil bellekteki verinin ana bellekte nereye düşeceği eşleştirilir. Bu eşleştirmeyi tutan yapı sayfa tablosudur (page table); ikincil bellekten ana belleğe her seferinde bir sayfa (page) getirilir.

Sayfa tablosu büyük bir tablodur ve kendisi de bellekte durur. Bu yüzden ona erişimi hızlandırmak için sayfa tablosuna özel küçük bir cache kullanılabilir. Resmin tamamı şöyledir: program bir sanal adres üretir; sayfa tablosunun cache'inden ya da sayfa tablosundan fiziksel karşılığı bulunur; gerekirse sayfa ikincil bellekten ana belleğe taşınır; ana bellekten bir blok cache'e getirilir (cache direct mapped, fully associative vb. olabilir); işlemci veriyi cache'ten okur. Dolayısıyla bir adres hem sanal bellek tarafında hem de veri cache'i tarafında ayrı ayrı parçalara bölünür.

## 5. Sanal Bellek Kavramı ve Temel Tasarım Soruları

Bir programın işgal edeceği alan, ana bellekte ona ayrılabilecek alandan çok daha fazla olabilir. Programın kendi içinde kullandığı veri uzayını tanımlayan şey sanal adrestir. Sanal adres, fiziksel adresten (ana bellek adresinden) farklıdır ve daha büyük bir uzayı adresler. Sanal bellek, çalıştırılan herhangi bir programın kaplayabileceği adres alanını gösteren bir yapıdır ve her programın kendine ait bir sanal adres uzayı vardır.

Bir programın sanal adres uzayındaki bir alan ile başka bir programınkinin ana bellekte yükleneceği yer aynı olabilir. Bu, cache'te farklı adres alanlarının aynı cache satırına düşebilmesine benzer.

İkincil bellekten ana belleğe bir seferde aktarılabilen bloğun belirli bir büyüklüğü vardır. Bu, cache'teki satır (line, block size) kavramının karşılığıdır ve sanal bellekte **sayfa (page)** olarak adlandırılır. Aranan veri ana bellekte yoksa, onu içeren sayfa ikincil bellekten ana belleğe taşınmalıdır.

Ekrandaki "Basic Issues in VM System Design" slaytında tasarımın temel soruları sıralanıyordu (ekrandan, 00:30:00):

- İkincil bellekten ana belleğe aktarılan bilgi bloklarının boyutu.
- Ana bellek doluyken yeni blok getirilirse hangi bölgenin boşaltılacağı: **replacement policy**.
- Yeni bloğun ana belleğin hangi bölgesine konacağı: **placement policy**.
- Eksik verinin ikincil bellekten yalnız bir hata (fault) oluştuğunda getirilmesi: **demand load policy**.

İkincil belleğe erişim bir erişim süresi, yani bir maliyet olarak geri döner. Bu maliyeti azaltmak için yerine koyma ve yerleştirme kuralları iyi seçilmelidir.

Ana bellekte bazı alanlar farklı programlarca kullanılabildiği için güvenlik de önemlidir. Bu, sayfa tablosundaki kontrol bitleriyle sağlanır. Her programın kendi sayfa tablosu olduğundan programlar kendilerine ait bir adres uzayı varmış gibi çalışır, ama arka planda fiziksel adresleri örtüşebilir. Programın sanal adres uzayındaki veri ona özeldir ve başka programla paylaşılmak istenmez. Eşlemeyi programın kendisi denetleyemez; bunu daha üst seviyedeki işletim sistemi denetler. Büyük kapasiteden küçük kapasiteye dönüşümü de sayfa tablosu sağlar.

## 6. Parçalanma Sorunu ve Sayfalama

Ekrandaki "Simple Example: Base and Bound Reg" slaytında bellekte alttan yukarı OS, User A, User B ve User C yerleşmişti; User B'nin alanı \$base ile \$base + \$bound arasındaydı. Kullanıcı alanlarının arasında taralı boşluklar vardı ve slayt şunu söylüyordu: User D için toplamda yeterli yer var, ama bitişik değil ("fragmentation problem") (ekrandan, 00:35:00).

Bloklar muntazam yerleşmediği için aralardaki boşlukların her biri bir bloğun sığmasına yetmez, ama toplamları bir bloktan fazladır. Parçalanma (fragmentation) sorunu, blokların yerleşimini düzenleyip boşlukları bir bütün hâlinde tutmakla ilgilidir. "Notes on Page Table" slaytında belirtildiği gibi sayfalama bu sorunu çözer: bütün parçalar aynı boyda olduğu için bütün boşluklar kullanılabilir. Ayrıca işletim sistemi her süreç için diskte bir takas alanı (swap space) ayırır; süreç büyümek istediğinde işletim sistemi önce kullanılmayan sayfaları verir, yoksa bazı eski sayfaları (LRU ile seçerek) diske atar. Her sürecin kendi sayfa tablosu vardır ve sayfa tablosu sanal belleğin özüdür (ekrandan, 01:00:00).

## 7. Adres Çevirisi ve Sayfa Tablosu

### 7.1 Basit örnek: 32 KB sanal, 8 KB fiziksel

Ekrandaki "Paging Organization (assume 1 KB pages)" slaytında sanal bellekte 0, 1024, 2048, ..., 31744 adreslerinden başlayan page 0 - page 31, fiziksel bellekte 0, 1024, ..., 7168 adreslerinden başlayan page 0 - page 7 vardı; aradaki eşlemeyi bir adres çeviri haritası (Addr Trans MAP) yapıyordu. Slayt, sayfanın hem eşleme birimi hem de diskten fiziksel belleğe aktarım birimi olduğunu vurguluyordu (ekrandan, 00:45:00).

Program kendi tanımında 32 KB'lık bir alana ihtiyaç duyar ve verilerini 1 KB'lık bloklar hâlinde tutar; yani 32 sayfası vardır. Ana bellekte ise 8 KB'lık bir sınır vardır. Böylece 32 sanal sayfanın 8 fiziksel sayfaya eşlenmesi gerekir.

Bu eşleme cache'teki adres bölmesine benzer. Cache'te fiziksel adresin düşük anlamlı bitleri byte ve word ofseti olarak ayrılır, belirli sayıda bit de satır numarasını gösterir. Burada da sanal adresin düşük anlamlı kısmı sayfa içindeki ofsettir ve fiziksel adrese olduğu gibi geçer. Yüksek anlamlı kısım (0-31) ise hangi fiziksel sayfaya (0-7) düşüleceğini gösteren bir dönüşüm tablosuyla çevrilir.

Adım adım:

- Sayfa boyutu 1 KB ise ofset için $\log_2 1024 = 10$ bit gerekir.
- 32 farklı sanal sayfayı adreslemek için $\log_2 32 = 5$ bit gerekir. Sanal adres $5 + 10 = 15$ bittir.
- 8 fiziksel sayfa için $\log_2 8 = 3$ bit gerekir. Fiziksel adres $3 + 10 = 13$ bittir; yani belleğin 13 adres ucu vardır. Sanal adresin ise fiziksel bir karşılığı yoktur; program kendi ihtiyacına göre tanımlamıştır.

Fiziksel adresler doğrudan bir eşleme ile belirlenmez. Sırada boş bir fiziksel sayfa varsa sayfa oraya yerleştirilir. Hepsi doluysa biri kaldırılır ve yerine yeni sayfa konur. Bu kararları yerleştirme ve değiştirme politikaları verir. Tablo başta boş olabilir; program çalıştıkça ihtiyaç duyulan sayfalar ikincil bellekten ana belleğe aktarılır ve tablo yavaş yavaş dolar. Çekilmemiş sayfalar için tabloda değer yoktur. Fiziksel bellek dolduktan sonra yeni bir sayfa gerekirse hangisinin yerine konacağına değiştirme politikası karar verir ve sayfa tablosu güncellenir.

### 7.2 Eşleme fonksiyonu

Ekrandaki "Virtual Memory Mapping Function" slaytı eşlemeyi şöyle tanımlıyordu (ekrandan, 00:40:00):

$$\text{Fiziksel ofset} = \text{Sanal ofset}$$
$$\text{PPN} = \text{PageTable}[\text{VPN}]$$

Sayfa numarası tabloda index olarak kullanılır; fiziksel sayfa numarasına "page frame" de denir.

Sayfa tablosunun ilk sütunu sanal sayfa numarası (bu örnekte 5 bit), ikinci sütunu ona karşılık gelen fiziksel sayfa numarasıdır (bu örnekte 3 bit). Program kendi kodunu yürütürken 15 bitlik sanal adres uzayında değerler üretir, ama bu değerlerin fiziksel karşılığı 13 bitlik adres uzayına eşlenerek kullanılır.

Sanal adresin fiziksel karşılığı şöyle bulunur: 5 bitlik VPN ile sayfa tablosunun ilgili satırına gidilir, oradaki 3 bitlik PPN alınır ve sanal adresin 10 bitlik ofsetiyle yan yana yazılarak 13 bitlik fiziksel adres oluşturulur.

### 7.3 Sayfa tablosu satırının yapısı

Ekrandaki "Address Mapping: Page Table" slaytında sanal adresin sayfa numarası, sayfa tablosu taban yazmacından (Page Table Base Reg) başlayan tabloda index olarak kullanılıyordu. Her satırda V (valid), A.R. (access rights) ve P.P.A. (physical page address) alanları vardı; P.P.A. ofsetle birleştirilerek fiziksel bellek adresi oluşuyordu. Slaytın alt notu: sayfa tablosu fiziksel bellekte bulunur (ekrandan, 00:50:00).

- **Valid biti:** İlgili sayfa ikincil bellekten ana belleğe yüklenmişse 1'dir. Cache'teki gibi, ilk başta rastgele bir değer yüzünden sayfa varmış gibi algılanmasın diye valid bitleri başlangıçta 0 yapılır. Daha önce fiziksel belleğe yüklenmemiş sayfanın valid biti 0'dır.
- **Erişim hakları (access rights):** Erişimin read only, write only, read/write ya da executable olarak yapılabilmesini belirleyen bitlerdir.
- **PPN:** İlgili VPN'e karşılık gelen fiziksel sayfa numarasıdır.

Her satır bir giriş (entry) olarak düşünülebilir. Örnekteki tablo $2^5 = 32$ satırlıdır. Her satırda 1 valid biti, erişim hakları için en az 2 (kullanıcılarla ilgili bilgi de düşünülürse yaklaşık 3) bit ve 3 bitlik PPN vardır; satır başına 6-7 bit eder ve tablo yaklaşık 32 byte'lık bir alan tutar. Bu çok küçük bir program içindir; gerçek programlarda sayfa tablosu çok daha büyüktür ve ana bellekte saklanmalıdır.

Eşlemenin farklı kullanıcılar ya da programlar tarafından değiştirilmesi doğru değildir; bu yüzden sayfa tabloları işletim sistemine ait yapılardır ve işletim sistemi tarafından değiştirilir.

## 8. Page Fault ve Adres Eşlemenin Matematiksel Tanımı

Sanal adres uzayı, fiziksel adres uzayından (ana belleğin kapasitesinden) çok daha büyüktür. Bütün programlar tek tek günümüzdeki RAM kapasitesinden büyük olmasa da birlikte çalışan çok sayıda program vardır ve her birine ayrılan alan düşünüldüğünde bu kısıt ortaya çıkar. Gereken şey, sanal belleğin her satırını ana bellekteki karşılığına eşleyen bir fonksiyondur. Ekrandaki "Address Map, Mathematically Speaking" slaytı bunu şöyle tanımlıyordu (ekrandan, 00:55:00):

$$V = \{0, 1, \ldots, n-1\} \text{ sanal adres uzayı } (n > m)$$
$$M = \{0, 1, \ldots, m-1\} \text{ fiziksel adres uzayı}$$
$$\text{MAP}: V \to M \cup \{\theta\}$$

$$\text{MAP}(a) = \begin{cases} a' & \text{a sanal adresindeki veri M'de } a' \text{ fiziksel adresindeyse} \\ \theta & \text{a sanal adresindeki veri M'de değilse} \end{cases}$$

Eşleme fiziksel adresi döndürüyorsa ilgili sayfa zaten ana belleğe yüklenmiştir. Boş küme ($\theta$) döndürüyorsa aranan sayfa ana bellekte yoktur; bu bir **page fault**'tur. Slayttaki akışta işlemci a adresini adres çeviri mekanizmasına verir; sonuç a' ise ana belleğe gidilir, 0 ise işletim sisteminin hata işleyicisi (OS fault handler) devreye girer ve sayfayı diskten ana belleğe taşır ("OS performs this transfer"). Ardından veri ana bellekten okunabilir.

## 9. Cache ile Sanal Belleğin Karşılaştırılması

Ekranda "Comparing the 2 levels of hierarchy" slaytının küçük resmi görünüyordu (ekrandan, 01:20:00); hoca karşılaştırmayı şöyle anlattı:

| Özellik | Cache | Sanal bellek |
|---|---|---|
| Aktarım birimi | Blok ya da line | Page |
| Veri bulunamazsa | Miss | Page fault |
| Birim boyutu | Byte mertebesinden günümüzde kilobayta kadar | Kilobaytlar mertebesi |
| Yerleştirme | Direct mapped ya da N-way set associative | Fully associative |
| Değiştirme | FIFO, LRU ya da random | LRU |
| Yazma | Write through ya da write back | Write back |

<!-- BELİRSİZ: Slaytın küçük resminde blok boyutu 32-64 B, sayfa boyutu 4K-8KB gibi okunuyor; küçük resim net değil. -->

Sanal bellekte LRU, işleyiş açısından en mantıklı yöntem olarak öne çıkar. Yazma tarafında cache'te iki seçenek vardı: write through'da cache ve bellek aynı anda güncellenir; write back'te yalnız cache güncellenir ve güncel veri cache'ten çıkarılacağı zaman belleğe yazılır. Sanal bellekte write back uygulanır, çünkü hem bellekte hem ikincil bellekte aynı anda güncelleme yapmak pratik değildir. Bellekteki sayfa güncellenir; sayfanın çıkarılması gerektiğinde ikincil bellekte güncellenir.

## 10. TLB (Translation Lookaside Buffer)

### 10.1 Amaç

Sayfa tablosu $2^{\text{VPN bit sayısı}}$ satırlık, görece büyük bir tablodur. Amacı, program bir sanal adresi referans ettiğinde işlemcinin fiziksel adreste hangi değeri okuyacağını çözmektir: VPN satırındaki PPN alınır ve ofsetle birleştirilerek fiziksel adres oluşturulur.

Sayfa tablosunun yerine değil, önüne ona özel bir cache konabilir. Bu cache'e **Translation Lookaside Buffer (TLB)** denir. Bir sanal adres referansı oluşunca doğrudan sayfa tablosuna bakmak yerine önce TLB'ye bakılır; giriş oradaysa PPN doğrudan alınır. Böylece belleğe gidip sayfa tablosundan okumak gerekmez.

Ekrandaki slayt, TLB'nin de diğer cache'ler gibi fully associative, set associative ya da direct mapped düzenlenebileceğini söylüyordu. TLB'ler genelde küçüktür; yüksek seviyeli makinelerde bile çoğunlukla 128-256 girişi geçmez, bu da fully associative aramaya izin verir. Orta seviyeli makinelerin çoğu küçük n-way set associative düzen kullanır. Slayttaki şemada CPU sanal adresi (VA) TLB'ye verir; hit ise fiziksel adres (PA) cache'e gider, miss ise çeviri (translation) yapılır; cache miss olursa ana belleğe gidilir. Şemada TLB erişimi $1/2\,t$, cache $t$, ana bellek $20\,t$ olarak gösterilmişti (ekrandan, 01:25:00).

### 10.2 Resmin tamamı

- Program bir sanal adres üretir. İlk iş TLB'ye bakmaktır.
- VPN TLB'de yoksa TLB miss olur. O zaman sayfa tablosuna gidilir. Sayfa tablosunda da page fault varsa sayfa ikincil bellekten fiziksel belleğe yüklenir, ardından TLB güncellenir.
- TLB hit olursa PPN hızlıca elde edilir ve sanal adresin ofsetiyle birleştirilerek fiziksel adres bulunur.
- İşlem store ise erişim hakkı da TLB'den kontrol edilir. Yazma hakkı yoksa işlem yazma koruması istisnasıyla (exception) sonlanır. Hak varsa yazma yapılır; artık fiziksel adres referansı söz konusu olduğundan veri önce cache'te aranır. Cache'te varsa güncellenir ve write through ya da write back hangisi geçerliyse bellek de ona göre güncellenir.
- Aranan fiziksel adres cache'te varsa veri doğrudan cache'ten alınır; yoksa ana bellekten cache'e getirilip cache üzerinden kullanılır.

Yani bir sanal bellek referansıyla başlayan süreç, sayfa tablosunun cache'i olan TLB'den veri cache'ine kadar uzanır.

### 10.3 TLB'nin tag ve veri alanları

Normal bir veri cache'inde tag, index ve veri alanları vardı; tag fiziksel adresin index dışındaki bir parçasıydı. TLB'den nihai olarak istenen şey, VPN'i alıp PPN döndüren bir eşleme fonksiyonudur. Bu yüzden TLB'nin veri alanı PPN'dir. Tag alanı TLB'nin düzenine göre değişir:

- **Fully associative TLB:** tag doğrudan VPN'dir.
- **Set associative TLB:** VPN'in bir kısmı index'i belirler, kalan kısmı tag alanına gider; index ile tag birleşince VPN oluşur.

Referans sanal adres üzerinden yapıldığı için VPN bilinir; ilgili sayfa fiziksel belleğe yüklenmişse PPN'i çekmek için TLB kullanılır.

TLB satırında ayrıca valid ve dirty bitleri bulunur. Valid biti satırın anlamlı veri içerip içermediğini gösterir. Dirty biti, ilgili sayfa ana bellekte güncellenmiş ama ikincil bellekte henüz güncellenmemişse 1'dir. Fully associative ya da set associative cache'lerde write back kullanıldığında, değiştirilecek satırın dirty biti 1 ise belleğin de güncellenmesi gerektiği anlaşılır; burada da aynı mantık geçerlidir.

### 10.4 TLB örneği (Example-2)

Ekrandaki soru şöyledir (ekrandan, 01:30:00): Küçük bir TLB, 20 bitlik sanal sayfa numarası, 12 bitlik fiziksel sayfa numarası ve 12 bitlik sayfa ofseti için aşağıdaki girişlere sahiptir. Sayfa numaraları ve ofsetler onaltılıktır. Listelenen her sanal adres için hit olup olmadığını, hit ise fiziksel adresi verin: (a) 02BB4A65, (b) 0E45FB32, (c) 0D34E9DC, (d) 03CA0777.

| Valid | Dirty | Tag (VPN) | Veri (PPN) |
|---|---|---|---|
| 1 | 1 | 01AF4 | FFF |
| 0 | 0 | 0E45F | E03 |
| 0 | 0 | 012FF | 2F0 |
| 1 | 0 | 01A37 | 788 |
| 1 | 0 | 02BB4 | 45C |
| 0 | 1 | 03CA0 | 657 |

Çözüm:

- Sanal adres VPN ve VPO'dan oluşur. VPO 12 bittir (sayfa ofseti hem sanal hem fiziksel taraf için aynı genişliktedir), VPN 20 bittir; sanal adres 32 bittir.
- Fiziksel adres PPN (12 bit) ve PPO'dan (12 bit) oluşur; 24 bittir.
- TLB'de 20 bitlik VPN'ler tag olarak, 12 bitlik PPN'ler veri olarak duruyor; bu yüzden TLB fully associative'dir ve aramada bütün satırlar tek tek kontrol edilir.
- Verilen adresler 8 onaltılık basamaklı, yani 32 bitlik sanal adreslerdir; ilk 5 basamak VPN, son 3 basamak ofsettir.
- **(a) 02BB4A65:** Tag 02BB4 bulunur, valid = 1. Bu örnekte yalnız okuma (load) yapıldığı varsayıldığı için dirty biti önemli değildir. Sayfa fiziksel belleğe yüklenmiştir; PPN = 45C, ofset A65. Fiziksel adres = **45CA65** (24 bit).
- **(b) 0E45FB32:** Tag 0E45F bulunur ama valid = 0; eşleşme şans eseridir. **TLB miss.** Bunun page fault olup olmadığı bilinemez; bunun için sayfa tablosunun bu satırındaki valid bitine bakmak gerekir.
- **(c) 0D34E9DC:** Tag 0D34E TLB'de yoktur. **TLB miss.**
- **(d) 03CA0777:** Tag 03CA0 bulunur ama valid = 0. **TLB miss.**

Sonuçlar python ile doğrulandı.

## 11. Sayfa Değiştirme Politikaları

Bir sayfanın değiştirilmesi gerektiğinde kullanılabilecek kurallar ekrandaki "Page Replacement Policy" slaytında sıralanıyordu (ekrandan, 01:45:00):

- **Random:** Fiziksel bellekteki rastgele bir sayfa kaldırılır. Slayta göre şaşırtıcı derecede iyi çalışır.
- **FIFO (first in, first out):** Fiziksel belleğe ilk konmuş (en eski) sayfa kaldırılır.
- **MIN ya da OPTIMAL:** Gelecekte en geç kullanılacağı tahmin edilen sayfa kaldırılır. Optimal durumu hedefler.
- **LRU (least recently used):** En uzun süredir kullanılmayan sayfa kaldırılır.
- **NFU/Clock (not frequently used):** LRU'nun yaklaşığıdır; yakın zamanda kullanılmış sayfalar atılmaz.

Örneklerde üç çerçeveli (programa ayrılmış 3 sayfalık yer), başlangıçta boş bir bellek ve A B C A B D A D B C B referans dizisi kullanılır (ekrandan, 01:40:00).

### 11.1 FIFO

| Referans | A | B | C | A | B | D | A | D | B | C | B |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Frame 1 | A | A | A | A | A | **D** | D | D | D | **C** | C |
| Frame 2 | | B | B | B | B | B | **A** | A | A | A | A |
| Frame 3 | | | C | C | C | C | C | C | **B** | B | B |
| Fault | F | F | F | | | F | F | | F | F | |

- İlk üç referansta tablo boş olduğu için A, B, C sırayla yüklenir: 3 page fault.
- A ve B bellekte bulunur. D gelince bellek doludur; ilk giren A kaldırılır, D birinci çerçeveye konur.
- A tekrar gelince bellekte D, B, C vardır: page fault. En eski yerleştirilen B'dir; B kaldırılır, A ikinci çerçeveye konur.
- D birinci çerçevede bulunur. B gelince bellekte D, A, C vardır: page fault. Sırada ilk giren C'dir; C kaldırılır, B konur.
- C gelince en eski olan (birinci çerçevedeki) D'dir; yerine C konur. Son B üçüncü çerçevede bulunur.
- Sonuç: **7 page fault** (slaytta da "Result: 7 page faults").

### 11.2 LRU

LRU için en uzun süredir kullanılmayan çerçeveyi gösteren bir değişken (bayrak) tutulur.

- A, B, C sırayla 1., 2. ve 3. çerçeveye yerleşir. LRU, 1. çerçeve (A) olur.
- A erişiminden sonra LRU 2. çerçeve, B erişiminden sonra 3. çerçeve olur.
- D gelince bellek dolu ve D yoktur; LRU 3. çerçeveyi gösterir, C kaldırılır, D konur. Bellek: A, B, D.
- D erişiminden sonra LRU 1. çerçeve, A erişiminden sonra 2. çerçeve olur; D erişiminden sonra da 2. çerçeve kalır. B erişiminden sonra LRU 1. çerçeveye geçer.
- C gelince bellek A, B, D ile doludur; LRU 1. çerçeveyi gösterir, A kaldırılır, C konur. Bellek: C, B, D; LRU 2. çerçeve olur. Son B bellekte bulunur.
- Sonuç: **5 page fault.**

FIFO'da D geldiğinde ilk yüklenen A (1. çerçeve) kaldırılırken, LRU'da en uzak geçmişte kullanılan 3. çerçeve (C) kaldırılır.

### 11.3 Optimal

Optimal politikada yakın gelecekte kullanılacaklar korunur, en uzak gelecekte kullanılacak olan değiştirilir.

- A, B, C 1., 2. ve 3. çerçeveye yerleşir; A ve B erişimlerinde zaten bellektedir.
- D gelince bellek doludur. Gelecekte A ve B erişimleri vardır; C en uzaktadır. C'nin bulunduğu 3. çerçeve değiştirilir, D konur. Bellek: A, B, D.
- A, D ve B bellekte bulunur. C gelince bellekte A, B, D vardır. Bir sonraki adımda B'ye erişilecektir; A ve D'ye bir daha erişilmeyecektir. 1. ve 3. çerçeve gelecekteki kullanım açısından eşittir, aralarından biri rastgele seçilir.

> **Ders sonrası not:** Derste optimal için toplam sayı söylenmedi. Python ile yapılan simülasyonda optimal politika da bu dizi için 5 page fault verir (A, B, C, D ve son C).

## 12. Bütünleşik Örnek: TLB, Sayfa Tablosu ve L1 Cache

Hoca bu örneği biraz karmaşık ama resmin tamamını görmek açısından önemli bir örnek olarak tanıttı.

> **Hocanın vurgusu:** Bu örnek resmin tamamını görmek açısından önemlidir; dikkatle incelenmelidir.

### 12.1 Verilenler

Soru şöyledir (ekrandan, 02:10:00): Şekil ile verilen virtual memory, TLB, page table ve cache yapısı için sayfa boyutu 1 KB, veri yolu genişliği 32 bit, sanal adres genişliği 20 bit, fiziksel adres genişliği 18 bittir. (a) Sistemde adres dönüşümünde oluşan adres parçalarının kaç bit uzunlukta olduğunu ve sayfa tablosu satır sayısını şekil üzerinde soru işaretli alanlara yazınız. (b) Verilen TLB ve sayfa tablosu içeriğine göre verilen sanal adresler için tabloları (onaltılık olarak) doldurunuz.

Şekilde (ekrandan, 01:50:00) iki aşama vardır: sanal bellek kısmı ve veri cache kısmı. TLB fully associative'dir, blok başına 1 giriş ve toplam 16 giriş içerir. L1 cache 8-way set associative'dir, her blokta 8 word vardır, toplam kapasite 512 word'dür. Şekilde CPU'dan çıkan sanal adres VPN ve VPO'ya, VPN'den TLB tag'i (TLBT) çıkar; TLB miss olursa sayfa tablosuna gidilir; PPN ile PPO fiziksel adresi oluşturur; fiziksel adres cache için CT (tag), CI (index), CWO (word offset) ve CBO (byte offset) alanlarına bölünür.

### 12.2 Alan genişlikleri

- **Ofset:** 1 KB'lık sayfa $2^{10}$ göz demektir; ofset 10 bittir. Yalnız sayfa boyutuna bakarak hem VPO hem PPO 10 bit bulunur.
- **VPN:** Sanal adres 20 bit, 10 biti ofset; VPN = 10 bit.
- **PPN:** Fiziksel adres 18 bit, 10 biti ofset; PPN = 8 bit. TLB miss olursa PPN sayfa tablosunun ilgili satırından gelir; o da 8 bittir.
- **TLB tag:** TLB fully associative olduğu için tag VPN ile aynıdır: 10 bit. Bir sanal adres referans edildiğinde TLB'nin 16 satırında VPN ile örtüşen tag aranır. Varsa TLB hit olur ve PPN doğrudan TLB'den alınır. Yoksa bellekteki sayfa tablosunun ilgili satırından PPN çekilir.
- **Sayfa tablosu satır sayısı:** VPN 10 bit olduğu için $2^{10}$ satır.

Cache tarafı (ekrandan, 02:00:00):

- Bir blokta 8 word var ve yapı 8-way olduğu için bir kümede $8 \times 8 = 64$ word bulunur. Toplam kapasite word cinsinden verildiği için byte'a çevirmeye gerek yoktur: $512 / 64 = 8$ küme. Hoca bunları "satır" olarak adlandırdı; her satırda 8 blok kendi aralarında fully associative yerleşir.
- 8 kümeyi ifade etmek için $\log_2 8 = 3$ bit: **cache index = 3 bit.**
- Mimari 32 bitlik olduğu için bir word $32/8 = 4$ byte'tır. Word içindeki byte'ı seçmek için $\log_2 4 = 2$ bit: **byte offset = 2 bit.**
- Blokta 8 word olduğundan word seçmek için $\log_2 8 = 3$ bit: **word offset = 3 bit.**
- **Tag:** Burada hoca öğrencilere tag genişliğinin nasıl bulunacağını sordu.

**Soru (hocanın sorusu):** Tag alanının genişliği nasıl bulunur? **Cevap:** İlk akla gelen sanal adres genişliği (20) yanlıştır. Sanal bellek programla ilgili sanal bir şeydir; fiziksel gerçeği yansıtmaz. Önceki haftaki cache sorusunda olduğu gibi bölünen şey fiziksel adrestir. Fiziksel adres 18 bittir (10 bit ofset + TLB'den ya da sayfa tablosundan gelen 8 bit PPN). 18 bitin 8'i ($3 + 3 + 2$) index ve ofsetlere gittiği için **tag = $18 - 8 = 10$ bit.**

> **Hocanın vurgusu:** Sanal bellek tarafıyla cache tarafını birleştiren köprü fiziksel adres genişliğini bulmaktır. Fiziksel adres bulunduktan sonra cache'in yapısına göre bölünür ve işlemler yürütülür.

Cache'te hit olursa veri L1'den okunur. Bir bloğun genişliği 8 word × 4 byte = **32 byte**'tır (32 bit değil). Veri yolu 32 bit olduğu için bu 32 byte'ın 4 byte'lık (bir word'lük) kısmı seçilip CPU'ya aktarılır.

Sınav için çeşitlemeler: TLB set associative olabilir; o zaman VPN ikiye bölünür, bir kısmı index'i gösterir, bir kısmı tag'e ayrılır. Veri yolu genişliği, sanal ya da fiziksel adres genişliği, L1 cache yapısı da değiştirilebilir. Sorunun ikinci aşamasında TLB, sayfa tablosu ve cache içerikleri verilip TLB hit/miss, page fault ve L1 hit/miss durumları sorulabilir.

> **Hocanın vurgusu:** Bu örnekte TLB fully associative olduğu için VPN doğrudan tag ile eşittir. TLB set associative olsaydı tag ile index'in birleşimi VPN'i oluştururdu; bu önemli bir noktadır.

Özet alan genişlikleri: VPN 10, VPO 10, TLB tag 10, PPN 8, fiziksel adres 18 bit; cache CT 10, CI 3, CWO 3, CBO 2.

### 12.3 Birinci referans: 0x04AA4

- 20 bitlik (5 onaltılık basamak) sanal adres ikilik yazılır: $0000\ 0100\ 1010\ 1010\ 0100$.
- 10 bit + 10 bit olarak ikiye bölünür. Yüksek anlamlı 10 bit VPN'dir: $00\ 0001\ 0010$ = **0x012**. Düşük anlamlı 10 bit VPO = PPO'dur: $10\ 1010\ 0100$ = **0x2A4**.
- TLB tag VPN ile aynıdır: **0x012**.
- TLB'de 012 tag'i valid = 1 ile vardır: **TLB hit.** PPN = **0xA1**.
- TLB'de valid olarak bulunan bir değer, sayfanın ana bellekte yüklü olduğunu gösterir: **page fault yok.**
- Fiziksel adres, PPN'in ofsetin soluna yazılmasıyla bulunur. A1 sekiz bit olarak $1010\ 0001$, ardından 10 bitlik ofset $10\ 1010\ 0100$ yazılır: $10\ 1000\ 0110\ 1010\ 0100$ = **0x286A4**.

**Soru:** A1'den sonra yazılan bitler nereden geldi? **Cevap:** Sayfa genişliği sanal adreste de fiziksel adreste de aynıdır, çünkü ikincil bellekten bir seferde bir sayfa alınıp belleğe kopyalanır. Sayfa içindeki konum değişmez; değişen yalnız sayfanın yerleştirildiği numaradır (VPN ile PPN farklı olabilir). Bu yüzden sanal adresin ofset kısmı aynı zamanda fiziksel adresin ofset kısmıdır; PPN'in yanına yazılan bitler doğrudan VPO'dan gelir. (Öğrencinin "fully associative için mi?" sorusuna hoca, bunun cache ya da TLB ile ilgisi olmadığını, yalnız sanal adresin ikiye bölünmesiyle ilgili olduğunu söyledi.)

### 12.4 İkinci referans: 0x078E6

- İkilik: $0000\ 0111\ 1000\ 1110\ 0110$.
- VPN = $00\ 0001\ 1110$ = **0x01E**; VPO = PPO = $00\ 1110\ 0110$ = **0x0E6**; TLB tag = **0x01E**.
- 01E TLB'de yoktur: **TLB miss.**
- Sayfa tablosunda 01E satırına bakılır; valid = 1'dir. Sayfa ikincil bellekten ana belleğe yüklenmiştir ama ilk kez referans edildiği için TLB'de yoktur: **page fault yok.** PPN = **0x57**.
- Fiziksel adres: PPN $0101\ 0111$ ve 10 bitlik ofset $00\ 1110\ 0110$ yan yana yazılır: $01\ 0101\ 1100\ 1110\ 0110$ = **0x15CE6** (hoca okurken önce bir basamağı 7 okudu, sonra E olarak düzeltti).

**Soru:** TLB'de bulunamayınca page fault'u sayfa tablosuna bakarak mı anlıyoruz? **Cevap:** Evet. Sayfa tablosunda valid biti 1 ise ilgili sayfa fiziksel belleğe yüklenmiştir ve page fault yoktur; 0 ise page fault vardır.

Bütün adres bölmeleri ve fiziksel adresler python ile doğrulandı.

## 13. Cache Örnekleri

### 13.1 64 KB direct mapped cache'te adres bölmesi

Soru (ekrandan, 02:25:00): 64 KB'lık, direct mapped, blokları 4 word (32 byte) olan bir cache belleğiniz olsun. 32 bitlik adres kullanıldığına göre adres alanlarını (bit konumlarını göstererek) belirtin: byte offset, word offset, index ve tag bitlerinin yerini ve sayısını verin.

- Toplam kapasite 64 KB, her satırda 32 byte varsa satır sayısı bu ikisinin bölümüdür. Satır sayısı adres bölmesinde **index** alanını belirler (hoca bunu öğrencilere sordu ve "index" cevabını aldı).
- $\dfrac{64 \cdot 2^{10}}{32} = \dfrac{2^{16}}{2^5} = 2^{11}$ satır → **index = 11 bit.**
- 4 word 32 byte ise 1 word $32/4 = 8$ byte'tır; word içindeki byte için $\log_2 8 = 3$ bit → **byte offset = 3 bit.**
- Bir blokta 4 word vardır; $\log_2 4 = 2$ bit → **word offset = 2 bit.**
- $3 + 2 + 11 = 16$; adres 32 bit olduğu için **tag = 16 bit.**

```text
| tag (16 bit) | index (11 bit) | word offset (2 bit) | byte offset (3 bit) |
```

> **Hocanın vurgusu:** Direct mapped'te satır sayısı doğrudan adresin bir alanıdır (birebir eşleme). Set associative'de de kısmen böyledir. Fully associative'de ise adres bölmesinde index alanı yoktur.

### 13.2 Aynı cache'e ardışık referanslar

Aynı yapıdaki (tag 16, index 11, word offset 2, byte offset 3) boş bir cache'e sırasıyla 4, 16, 32, 20, 80, 68, 76, 224, 36, 44, 16, 172, 20, 24, 36, 68 adreslerine erişiliyor. Her erişimde hit ya da miss durumu ve cache içeriği istenir (ekrandan, 02:20:00 ve 02:30:00).

Her erişimde 32 byte'lık veri alınır. Ofset 5 bit olduğu için en düşük anlamlı 5 bit dışındaki 27 biti aynı olan 32 byte bir seferde cache'in bir satırına çekilir. Tag ve index onaltılık ya da onlu verilebilir (burada en fazla 7'ye çıktıkları için fark etmez); word ve byte ofsetleri ikilik verilmiştir.

| Ref. | Adres | Tag | Index | Word | Byte | Sonuç |
|---|---|---|---|---|---|---|
| a | 4 | 0 | 0 | 00 | 100 | miss |
| b | 16 | 0 | 0 | 10 | 000 | hit |
| c | 32 | 0 | 1 | 00 | 000 | miss |
| d | 20 | 0 | 0 | 10 | 100 | hit |
| e | 80 | 0 | 2 | 10 | 000 | miss |
| f | 68 | 0 | 2 | 00 | 100 | hit |
| g | 76 | 0 | 2 | 01 | 100 | hit |
| h | 224 | 0 | 7 | 00 | 000 | miss |
| i | 36 | 0 | 1 | 00 | 100 | hit |
| j | 44 | 0 | 1 | 01 | 100 | hit |
| k | 16 | 0 | 0 | 10 | 000 | hit |
| l | 172 | 0 | 5 | 01 | 100 | miss |
| m | 20 | 0 | 0 | 10 | 100 | hit |
| n | 24 | 0 | 0 | 11 | 000 | hit |
| o | 36 | 0 | 1 | 00 | 100 | hit |
| p | 68 | 0 | 2 | 00 | 100 | hit |

Adım adım:

- **4:** 32 bitlik ikilikte üst 16 bit 0 (tag 0), sonraki 11 bit 0 (index 0), word ve byte ofseti $00\ 100$. Cache boş olduğu için miss. 0-31 adreslerinin içeriği bir seferde cache'in 0. satırına çekilir; valid = 1, tag = 0 yazılır.
- **16:** Tag 0, index 0. 0. satırda tag 0 ve valid = 1; aranan veri burada. Word ve byte ofsetleriyle 0-31 içeriğinden 16. byte alınır: hit.
- **32:** Tag 0, index 1 (11 bitlik kısım tek tek ayrılmalıdır), ofsetler $00\ 000$. 1. satırın valid biti 0: doğrudan miss. 32-63 adreslerinin içeriği 1. satıra konur, valid = 1, tag = 0.
- **20:** Tag 0, index 0: hit.
- **80:** Index 2, miss; 64-95 adresleri 2. satıra konur.
- **68, 76:** Index 2, tag 0, valid = 1: hit.
- **224:** Tag 0, index 7. 7. satırın valid biti 0: miss. 224-255 adresleri 7. satıra konur.
- **172:** Index 5, valid 0: miss. 160-191 adresleri 5. satıra konur.
- Geri kalan erişimlerin hepsi cache'ten karşılanır. Aradaki diğer cache satırları geçersiz (non-valid) kalır.

Sonuç: 16 erişimin **5'i miss, 11'i hit** (python ile doğrulandı).

## 14. Örnek Sorular

**Soru 1 (ekrandan, 00:15:00):** CMP A, B komutu yürütüldüğünde V = 1, N = 0, C = 1 ve Z = 0 değerlerine sahip olmaktadır. Bu sonucu üreten bir A, B ikilisi örneği veriniz.

> **Çözüm (derste):** C borç kabul edilirse C = 1 için işaretsiz $A < B$ olmalıdır. V = 1 ve N = 0 için $A + (-B)$ iki negatif sayının toplamı olmalı ve pozitif çıkmalıdır; bu A'nın en anlamlı bitinin 1, B'ninkinin 0 olmasını gerektirir. O zaman işaretsiz $A > B$ olur ve C = 1 sağlanamaz. Bu bayrakları üreten hiçbir A, B ikilisi yoktur. (C'nin $A + \bar B + 1$ toplamının elde çıkışı olarak yorumlandığı durum için Bölüm 3.1'deki ders sonrası nota bakın.)

**Soru 2 (derste sözlü, 00:17:35):** Toplam 10 bit uzunluğunda komutlar kullanan bir işlemcide komut formatı opcode, operand 1, operand 2 biçimindedir ve 8 yazmaç vardır. En fazla kaç farklı opcode tanımlanabilir?

> **Çözüm (derste):** Her operand için 3 bit, toplam 6 bit; opcode'a 4 bit kalır. $2^4 = 16$ opcode.

**Soru 3 (ekrandan, 01:30:00):** 20 bitlik VPN, 12 bitlik PPN ve 12 bitlik sayfa ofseti olan küçük bir TLB'nin girişleri Bölüm 10.4'teki tabloda verilmiştir. (a) 02BB4A65, (b) 0E45FB32, (c) 0D34E9DC, (d) 03CA0777 sanal adresleri için hit olup olmadığını ve hit ise fiziksel adresi veriniz.

> **Çözüm (derste):** (a) hit, fiziksel adres 45CA65. (b) Tag var ama valid = 0: TLB miss. (c) Tag yok: TLB miss. (d) Tag var ama valid = 0: TLB miss.

**Soru 4 (ekrandan, 01:40:00):** Başlangıçta boş, üç sayfalık bir bellekte A B C A B D A D B C B referans dizisi için FIFO, LRU ve optimal politikalarda kaç page fault oluşur?

> **Çözüm (derste):** FIFO 7, LRU 5 page fault. Optimal için derste sayı söylenmedi; Bölüm 11.3'teki adımlarla 5 page fault olur (python ile doğrulandı).

**Soru 5 (ekrandan, 02:10:00):** Sayfa boyutu 1 KB, veri yolu 32 bit, sanal adres 20 bit, fiziksel adres 18 bit; TLB fully associative 16 girişli; L1 cache 8-way set associative, blokta 8 word, toplam 512 word. (a) Adres parçalarının bit uzunluklarını ve sayfa tablosu satır sayısını bulunuz. (b) 0x04AA4 ve 0x078E6 sanal adresleri için VPN, VPO, TLBT, TLB hit/miss, page fault, PPN ve fiziksel adresi bulunuz.

> **Çözüm (derste):** (a) VPN 10, VPO 10, TLBT 10, PPN 8 bit, sayfa tablosu $2^{10}$ satır; cache CT 10, CI 3, CWO 3, CBO 2. (b) 0x04AA4: VPN 0x012, VPO 0x2A4, TLBT 0x012, TLB hit, page fault yok, PPN 0xA1, fiziksel adres 0x286A4. 0x078E6: VPN 0x01E, VPO 0x0E6, TLBT 0x01E, TLB miss, page fault yok, PPN 0x57, fiziksel adres 0x15CE6.

**Soru 6 (ekrandan, 02:15:00):** Aynı sistemde boş bir cache ile başlandığı varsayılarak sırasıyla 0x000F4, 0x004E2 ve 0x008F1 sanal adreslerine erişilmek istenirse cache içeriğinin son hâli nasıl olur, çizerek gösteriniz.

> **Çözüm (derste verilmedi):** Ekrandaki notta bu üç adresin VPN'leri 000, 001, 002 olarak ayrılmış ve sayfa tablosundaki karşılıkları 1F, 28, 93 olarak işaretlenmişti (sayfa tablosunda üçünün de valid biti 1). Fiziksel adresler: $0x000F4 \to$ PPN 1F, ofset 0F4 → $1F \cdot 2^{10} + 0F4 = 0x07CF4$; $0x004E2 \to$ PPN 28, ofset 0E2 → $0x0A0E2$; $0x008F1 \to$ PPN 93, ofset 0F1 → $0x24CF1$. 18 bitlik fiziksel adres CT (10) | CI (3) | CWO (3) | CBO (2) olarak bölünür: 0x07CF4 → CT = 0x07C, CI = 7, CWO = 5, CBO = 0; 0x0A0E2 → CT = 0x0A0, CI = 7, CWO = 0, CBO = 2; 0x24CF1 → CT = 0x24C, CI = 7, CWO = 4, CBO = 1. Üç adresin de index'i 7'dir; 8-way set associative cache'te 7 numaralı kümenin üç ayrı yoluna (way) tag 0x07C, 0x0A0 ve 0x24C ile birer blok (8 word) yerleşir ve üç erişim de miss olur (python ile hesaplandı).

**Soru 7 (ekrandan, 02:25:00):** 64 KB'lık, direct mapped, blokları 4 word (32 byte) olan bir cache'te 32 bitlik adres için byte offset, word offset, index ve tag bitlerinin sayısını bulunuz.

> **Çözüm (derste):** Index $\log_2(2^{16}/2^5) = 11$, byte offset $\log_2 8 = 3$, word offset $\log_2 4 = 2$, tag $32 - 16 = 16$ bit.

**Soru 8 (ekrandan, 02:30:00):** Aynı cache'e boş başlangıçla 4, 16, 32, 20, 80, 68, 76, 224, 36, 44, 16, 172, 20, 24, 36, 68 adreslerine sırayla erişildiğinde hit ve miss durumları nedir?

> **Çözüm (derste):** 4, 32, 80, 224 ve 172 miss; diğerleri hit. Toplam 5 miss, 11 hit (ayrıntı Bölüm 13.2'de).

## Dersin Toparlaması

Ders, kısa sınavın çözümüyle tek çevrimli bilgisayarda kontrol kelimesi ve komut kodlamayı, tam toplayıcılarla aritmetik birim tasarımını ve bayrak mantığını tekrar ettikten sonra bellek hiyerarşisinin ikinci ucuna, sanal belleğe geçti. Sanal bellekte her programın kendi sanal adres uzayı vardır. Bu uzay sayfalara bölünür ve sayfa tablosu yardımıyla daha küçük fiziksel belleğe eşlenir. Sanal adresin ofset kısmı fiziksel adrese olduğu gibi geçer, VPN ise sayfa tablosundan ya da onun cache'i olan TLB'den alınan PPN ile değiştirilir. Aranan sayfa bellekte yoksa page fault olur ve işletim sistemi sayfayı diskten getirir. Bellek doluysa hangi sayfanın çıkarılacağına FIFO, LRU, optimal gibi politikalar karar verir.

Hocanın kapanıştaki özeti şudur: cache ve sanal bellek, derste iki parça hâlinde görülen ve birbirine bağlı iki uçtur. Onları birleştiren kısım fiziksel adresin elde edilmesidir. VPN'e karşılık gelen PPN bulunur, PPN ile ofset birleştirilerek fiziksel adres oluşturulur ve fiziksel adres cache'in özelliğine göre bölünür. Fully associative'de index alanı yoktur ve tag daha büyüktür; set associative ve direct mapped'te byte offset, word offset, index ve tag alanları vardır. Hoca, verilen bir kodun cache yapısını ne kadar verimli kullandığını ve buna göre ne kadar hızlı çalışacağını yorumlayabilmenin önemli olduğunu, bu konuların işletim sistemleri gibi derslerde de karşılarına çıkacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
