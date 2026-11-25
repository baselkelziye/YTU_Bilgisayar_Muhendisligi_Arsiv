# Ders 10 Genişletilmiş Notu: Vize Sorularının Çözümü, Boru Hattı ve Giriş/Çıkış Arayüzü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Vize sorularının çözümü
- 2. Tek çevrimli bilgisayarda saat frekansı sınırı
- 3. Boru hattı (pipeline) mantığı
- 4. Boru hattı tehlikeleri ve dallanma
- 5. Çok çevrimli yapıya geçiş
- 6. Giriş/çıkış sisteminin genel mimarisi
- 7. Klavye ve veri aktarım yöntemleri
- 8. İkincil bellek, önbellek ve ekranlar
- 9. Paralel arayüz
- 10. Strobe ve el sıkışma ile asenkron aktarım
- 11. Seri haberleşme
- 12. Polling ve kesme tabanlı aktarım
- 13. DMA kontrolcüsü
- Örnek Sorular

Dersin ilk yarısında ara sınav (vize) soruları ekranda çözülür. Sorular iki grup hâlinde hazırlanmıştır ve her soru iki grupta aynı mantıkla, farklı sayılarla sorulmuştur. Aradan sonra önceki haftalardan kalan boru hattı konusu tamamlanır, ardından giriş/çıkış (G/Ç, input/output) arayüzü anlatılır. Slaytlar Mano ve Kime'nin "Logic and Computer Design Fundamentals" kitabındandır; anlatım slaytlar üzerinde el çizimiyle yürür.

## 1. Vize sorularının çözümü

Soruların tam metinleri ve şıkları ekranda görüldüğü kadarıyla "Örnek Sorular" bölümündedir. Burada her sorudan çıkan genel fikir anlatılır.

### 1.1 Bayraklar ve işaretli çıkarma

İki sayı birbirinden çıkarılıp işaret, taşma (overflow) ve sıfır bayraklarının durumu sorulur. Sayılar eşit olmadığı için sıfır bayrağı 1 olamaz. İkinci şıkta $127 - (-1)$ işlemi yapılır. Bu $127 + 1 = 128$ demektir ve 8 bitlik ikiye tümleyen aralığı ($-128 \ldots 127$) dışındadır. Pozitiften negatife bir taşma olur, sonuç negatif görünür; taşma bayrağı 1, işaret bayrağı 1, sıfır bayrağı 0'dır. Hoca bunun iki yolla bulunabileceğini söyler: sayıları akılda hesaplayarak ya da bayrakları üreten lojik devreleri kullanarak. <!-- BELİRSİZ: İlk şıktaki sayılar altyazıda bozuk ("x1, x127, x128"); sonucun aralık içinde kaldığı ve taşma olmadığı söyleniyor, sayılar ekranda görülmedi. -->

### 1.2 İkiye tümleyenli sayının ondalık karşılığı

$(1111\,0000)_2$ sayısının en soldaki biti 1 olduğu için sayı negatiftir. Genliği bulmak için ikiye tümleyeni alınır. Hoca kısa yolu kullanır: sağdan başlayıp ilk 1'i görene kadar bitler olduğu gibi bırakılır, sonra kalan bitler tersine çevrilir. Böylece $(0001\,0000)_2 = 16$ bulunur ve sayı $-16$'dır (python ile kontrol edildi). <!-- BELİRSİZ: Sorunun diğer grubundaki ifade ("en küçük yazılabilecek sayı") altyazıdan tam çıkmıyor. -->

### 1.3 Adresleme modları

Bir yazmaca sabit bir değer atamak anlık (immediate) adreslemedir. İşlenen olarak doğrudan bir yazmacın kullanıldığı durum yazmaç adreslemedir.

### 1.4 Bellek kapasitesi

Kapasite, adreslenebilen göz sayısı ile her gözün genişliğinin çarpımıdır. 12 adres biti varsa $2^{12} = 2^2 \cdot 2^{10} = 4\text{K}$ göz vardır. Veri yolu 64 bit ise her göz $64 / 8 = 8$ bayttır ve kapasite $4\text{K} \cdot 8 = 32$ KB olur.

Diğer grupta 16 bit adres ve 32 bit veri yolu vardır (ekrandan, 00:10:00):

$$2^{6} \cdot 2^{10} \cdot \frac{32\ \text{bit}}{8\ \text{bit}} = 64\text{K} \cdot 4 = 256\ \text{KB}$$

Cevap b şıkkıdır (python ile kontrol edildi).

### 1.5 Aritmetik öteleme

Bu sorunun bir grubunda şıklardan birinde hata olduğu için soru herkese doğru sayılmıştır; hoca yine de doğru çözümü gösterir. Aritmetik sağa ötelemede işaret biti korunur ve diğer bitler birer sağa kayar. Derste sağa öteleme sonucu $(1101\,1010)_2$ bulunur; sayı negatif kaldığı için taşma yoktur. Bu sayının genliği için yine ilk 1'e kadar olduğu gibi bırakıp sonrasını ters çevirince $(0010\,0110)_2 = 38$ çıkar, sonuç $-38$'dir.

Aritmetik sola öteleme ile mantıksal sola öteleme aynıdır: tüm bitler bir sola kayar, sağdan 0 girer. Aynı sayı sola ötelendiğinde en soldaki bit 0 olur, sayı pozitife döner. İşaret değiştiği için aritmetik sola ötelemede taşma vardır.

Diğer grupta sağa öteleme sonucu $(1111\,1010)_2 = -6$ bulunur, burada da taşma yoktur. <!-- BELİRSİZ: Ötelenen sayılar ekranda görülmedi. Sonuçlardan geriye gidilirse ilk grupta $(1011\,0100)_2 = -76$, ikinci grupta $(1111\,0100)_2 = -12$ olmalıdır (python ile kontrol edildi), ama soru metni doğrulanamadı. -->

### 1.6 Program sayacı

"Aşağıdaki komutların kaç tanesinin yürütülmesinden sonra program sayacı değişir?" sorusunda dallanma komutlarında PC zaten değişir. Diğer komutlarda da bir sonraki komuta geçmek gerektiği için PC değişir. Koşullu, koşulsuz dallanma, yükleme/saklama ve diğer bütün komutlardan sonra PC değişir; cevap hepsidir.

### 1.7 Komut formatı

Komut 20 bit uzunluğundadır ve 32 yazmaç vardır. Bir yazmacı adreslemek için $\log_2 32 = 5$ bit gerekir. Üç yazmaç alanı $3 \cdot 5 = 15$ bit tutar, opcode'a $20 - 15 = 5$ bit kalır. Bu da $2^5 = 32$ farklı işlem kodu demektir.

Diğer grupta komut 24 bit, yazmaç sayısı 64'tür. Her yazmaç alanı 6 bit, üçü 18 bit eder; opcode 6 bit kalır ve $2^6 = 64$ işlem kodu yazılabilir (python ile kontrol edildi).

### 1.8 Bellek genişletme

128K×16'lık modüllerle 128K×64 yapmak için modüller aynı anda aktif olacak biçimde yan yana bağlanır. Her biri veri yoluna 16 bit katkı yapar ve 64 bit için 4 modül gerekir. Bu veri yolu genişletmesidir.

128K×16'lık DRAM modülleriyle 1M×32 kapasiteli bir blok tasarlanacaktır (ekrandan, 00:15:00). Önce modül sayısı bulunur:

$$\frac{1\text{M} \cdot 32}{128\text{K} \cdot 16} = \frac{1024}{128} \cdot 2 = 16$$

Veri yolunu 16'dan 32'ye çıkarmak için modüller ikişer ikişer yan yana konur. Bu durumda 8 satır blok oluşur ve bu bloklar farklı zamanlarda seçilecektir. 8 bloğu seçmek için 3 adres biti, yani 3'e 8 dekoder gerekir. Cevap "16 adet RAM ve 3-to-8 dekoder" şıkkıdır.

### 1.9 Bellek türleri, PLA, PAL ve ROM

Bellek birimleriyle ilgili soruda statik RAM, ROM ve dinamik RAM hakkında ifadeler vardır; yanlış olan madde dinamik RAM ile ilgili olandır. <!-- BELİRSİZ: Şıkların metni ekranda görülmedi. -->

PLA sorusunda AND katındaki terimler okunur: $AB$, $AC$, $BC$ ve $\bar A \bar B \bar C$. Buna göre:

$$F_1 = AB + AC + BC, \qquad F_2 = AB + AC + \bar A \bar B \bar C$$

Cevap anahtarında hatalı işaretlenen soru, çıkışları minterm listeleriyle veren sorudur. Şıklar $A = \sum m(1,2,5,7)$, $B = \sum m(0,2,4,7)$, $C = \sum m(0,1,4,6)$, $D = \sum m(1,3,5,7)$ ve "diğer şıkların tamamı yanlıştır" biçimindedir (ekrandan, 00:20:00). Hoca devredeki terimlerin hep üçlü ya da ikili terimler olduğunu, şıklardaki fonksiyonların ise dört mintermli olduğunu söyleyip doğrudan e şıkkını işaretler. <!-- BELİRSİZ: Bu sorunun devre şekli ekranda görülmedi; e şıkkının nasıl doğrulandığı altyazıdan tam çıkmıyor. -->

PAL sorusunda hoca slayttaki PAL yapısını açar: PAL'da AND katı programlanabilir, OR katı sabittir. Hem AND hem OR katının programlanabildiğini söyleyen şık bu yüzden yanlıştır. ROM sorusunda ise ROM'da AND katının sabit, OR katının programlanabilir olduğu hatırlatılır; AND katı aslında adres dekoderinin içindedir.

### 1.10 Bayrak lojiği: NOR ve XOR

Akümülatörün bütün bitleri bir NOR kapısına girer. NOR ancak tüm girişleri 0 iken 1 verir; yani yazmaç değeri 0 olduğunda 1 olur. Bu sıfır bayrağıdır.

İkinci soruda bitler bir XOR kapısına girer. XOR, AND, OR, NAND ve NOR gibi değişme ve birleşme özelliğine sahiptir. Bu yüzden çok girişli bir XOR, girişlerin ikişer ikişer XOR'lanıp sonuçların yine XOR'lanması gibi davranır. Girişteki 1'lerin sayısı tek ise çıkış 1 olur. Eşlik (parity) tanımı da eşlik biti dahil 1'lerin sayısının tek ya da çift olmasıdır. Dolayısıyla bu devre eşlik bitini üreten bayrak lojiğidir.

### 1.11 Asenkron (ripple) sayıcı

Devrede dört D flip-flop vardır. Her flip-flop'un $\overline{Q}$ çıkışı kendi $D$ girişine bağlıdır, yani her yükselen kenarda içerik tersine döner (toggle). FF0'ın saati dış saatten, diğerlerinin saati bir önceki flip-flop'un $Q$ çıkışından gelir (ekrandan, 00:30:00).

İlk grupta başlangıç $(Q_0, Q_1, Q_2, Q_3) = (1, 0, 0, 1)$ ve iki saat sonrası sorulur. Hoca saat dalga şeklini çizip ilerler. Birinci kenarda $Q_0$ 1'den 0'a düşer; bu düşen kenar olduğu için $Q_1$ etkilenmez. İkinci kenarda $Q_0$ 0'dan 1'e çıkar. Bu yükselen kenar $Q_1$'i 0'dan 1'e çıkarır, $Q_1$'in yükselen kenarı $Q_2$'yi 0'dan 1'e çıkarır, $Q_2$'nin yükselen kenarı da $Q_3$'ü 1'den 0'a düşürür. Sonuç $(1, 1, 1, 0)$'dır.

İkinci grupta başlangıç $(0, 0, 1, 1)$, sorulan üç saat sonrasıdır. $Q_0$ sırasıyla 1, 0, 1 olur ve 1'de kalır. $Q_0$'ın iki yükselen kenarı $Q_1$'i önce 1'e, sonra 0'a taşır. $Q_1$'in tek yükselen kenarında $Q_2$ 1'den 0'a düşer. $Q_2$'de yalnız düşen kenar olduğu için $Q_3$ değişmez. Sonuç $(1, 0, 0, 1)$'dir (ekrandan, 00:30:00). İki sonuç python ile simülasyonla doğrulandı.

### 1.12 Karşılaştırıcı devre

Bir devrenin X, Y, Z çıkışlarından hangisinin hangi durumda tek başına 1 verdiği sorulur. Devre iki bitlik $A_1 A_0$ ve $B_1 B_0$ sayılarını karşılaştırır. XOR kapıları bitlerin farklı olduğu durumu, XNOR kapıları aynı olduğu durumu yakalar. Bir kol eşitliğe, diğer kol farka göre çalışır. Uzun bir açılımdan sonra çıkışların küçüklük, eşitlik ve büyüklük durumlarını verdiği görülür; örneğin Z eşitlik durumuyla ilgilidir. <!-- BELİRSİZ: Devre ve şıklar ekranda görülmedi; X ve Y'nin hangi duruma karşılık geldiği altyazıdan çıkmıyor. -->

### 1.13 Sayıcı tasarımında flip-flop sayısı

Sayıcı 8, 9, 10, 11, 12 sayıp başa dönmektedir; 5 durum vardır. JK flip-flop'larla tasarlanacak ve dışarıdan giriş yoktur. Dış giriş olmadığı için devre Moore makinesidir. Gereken flip-flop sayısı:

$$\lceil \log_2 5 \rceil = 3$$

Diğer grupta sayıcı 3, 4, 5, 6, 7 sayar; yine 5 durum, dış giriş yok, yine 3 flip-flop ve Moore makinesi.

### 1.14 Doğrusal geri beslemeli ötelemeli yazmaç (LFSR)

Dört D flip-flop A, B, C, D sırasıyla zincirlenmiştir ve hepsi aynı saati kullanır. A'nın girişine bir XOR kapısı bağlıdır; XOR'un girişleri B'nin çıkışı ve D'nin çıkışıdır (ekrandan, 00:35:00). Geçiş denklemleri:

$$Q_A^+ = q_B \oplus q_D, \quad Q_B^+ = q_A, \quad Q_C^+ = q_B, \quad Q_D^+ = q_C$$

Hoca doğru şıkkı doğrulamak için $(q_A, q_B, q_C, q_D) = (0, 1, 0, 1)$ durumunu dener. Durum değişimi eş zamanlı olduğu için önce her flip-flop'un girişine gelen değer yazılır: B'ye 0, C'ye 1, D'ye 0 gelir. XOR'un iki girişi de 1 olduğundan A'ya 0 gelir. Sonraki durum $(0, 0, 1, 0)$'dır, yani b şıkkı (python ile kontrol edildi). Diğer şıklar denenince hatalı sonuç çıkar.

### 1.15 Çarpım için yazmaç genişliği

5 bitlik herhangi iki sayının (işaretli ya da işaretsiz) çarpımını saklamak için en az kaç bitlik yazmaç gerektiği sorulur. İşaretsiz düşünüldüğünde en büyük çarpım $31 \cdot 31$'dir. Hoca 4 bitle genelleme yapar: $15 \cdot 15 = 225$ ve 8 bite sığar. Buradan $n$ bitlik iki sayının çarpımının $2n$ bit gerektirdiği görülür; 5 bit için 10 bit gerekir, diğer grupta (4 bit) 8 bit. Hoca bu sorunun "herhangi iki sayının çarpımı" dediğini, yani işaretli ve işaretsiz bütün durumları destekleyen en genel yapıyı sorduğunu ve sonraki çarpıcı sorusuyla karıştırılmaması gerektiğini vurgular.

> **Ek bilgi (derste anlatılmadı):** $31 \cdot 31 = 961$ 10 bite sığar. İşaretli 5 bitlik sayılarda en büyük genlikli çarpım $(-16) \cdot (-16) = 256$'dır ve bu da 10 bitlik işaretli aralıkta kalır. Bu iki değer python ile kontrol edildi.

### 1.16 TEST, CMP, NEG ve bit temizleme

"Bir yazmaç değerinin 0 olup olmadığını test etmek için TEST kullanılamaz" ifadesi yanlıştır. Tüm bitleri 1 olan bir değerle yazmaç TEST'e sokulursa, sonuç 0 çıktığında yazmacın 0 olduğu anlaşılır.

Bit işleme sorusunda "NEG komutu birler tümleyenini hesaplar" ifadesi yanlıştır. Bütün bitleri tersine çevirmek birler tümleyenidir; NEG ise ikiye tümleyen alır. R1'in 1 numaralı bitini 0 yapmak için yalnız o biti 0, diğerleri 1 olan bir maskeyle AND yapılır: $\text{FD} = (1111\,1101)_2$. Böylece yalnız 1. bit 0 olur, diğer bitler özgün değerini korur.

### 1.17 Öteleme-toplama (shift-and-add) çarpıcısı

Hoca bu soruyu "sınavın en can alıcı sorularından biri" diye tanıtır.

> **Hocanın vurgusu:** Öteleme-toplama çarpıcısının çalışmasını adım adım izleyip yazmaç ve toplayıcı genişliklerini buradan çıkarmak gerekir.

Yapıda A (her saatte bir sola ötelenir, $\ll 1$), B (her saatte bir sağa ötelenir, $\gg 1$), bir AND katı, bir toplayıcı ve P yazmacı vardır (ekrandan, 00:40:00). Saat gelmeden önce B'nin en düşük anlamlı biti A'nın bütün bitleriyle AND'lenir; çıkış A genişliğindedir. Toplayıcı bu değeri P'nin içeriğiyle toplar. Saat kenarında toplam P'ye yazılır, aynı anda A bir sola, B bir sağa ötelenir.

15 × 15 örneği (ekrandan, 00:45:00):

| Saat | A | B | AND çıkışı | P (saatten sonra) |
|---|---|---|---|---|
| Başlangıç | 15 | 15 | 15 | 0 |
| 1 | 30 | 7 | 30 | 15 |
| 2 | 60 | 3 | 60 | 45 |
| 3 | 120 | 1 | 120 | 105 |
| 4 | 240 | 0 | 0 | 225 |

Dört saat darbesinde çarpım biter (python ile kontrol edildi).

Genişlikler şöyle çıkarılır. B'ye yazılan en büyük değer 15'tir ve 4 bite sığar. A'da son adımda 240 oluşur, ama bu değer bir daha kullanılmaz; bu yüzden en yüksek anlamlı biti atılabilir, yüklenmesine bile gerek yoktur. A'da mutlaka korunması gereken en büyük değer 120'dir ve 7 bite sığar. Toplamalarda en büyük işlem 120 + 105'tir, yani iki 7 bitlik değer toplanır. Toplayıcı 7 bit, P 7 bit yeterlidir; 225'in 8. biti toplayıcının elde çıkışında (Cout) tutulur. Cevap: A 7 bit, B 4 bit, toplayıcı 7 bit, P 7 bit.

Hoca bunu bir karşı örnekle karşılaştırır: çarpma 15'i kendisiyle 15 kez toplayarak yapılsaydı son işlem $210 + 15 = 225$ olurdu ve toplayıcı ile P 8'er bit olmalıydı. Ayrıca 15 toplama, dolayısıyla 15 saat çevrimi gerekirdi. Öteleme-toplama yapısında en büyük toplama 7 bitlik sayılarla yapılır ve son artığın en yüksek anlamlı bitinin atılması sorun oluşturmaz.

> **Ders sonrası not:** Hoca bir yerde A'da korunması gereken değeri "220" diye söyler; tablo ve ekran 120'dir.

## 2. Tek çevrimli bilgisayarda saat frekansı sınırı

Aradan sonra hoca tek çevrimli (single-cycle) bilgisayar mimarisine, yani denetimi kablolu (hardwired) olan yapıya döner. Bu yapıda hem senkron hem kombinasyonel devreler vardır ve sabit frekanslı bir saat kullanılır. Hoca öğrencilere en yüksek frekansı neyin belirlediğini sorar.

**Soru:** Bu mimaride kullanılabilecek en yüksek frekansı ne etkiler? **Cevap (bir öğrenci):** Yayılım gecikmesi (propagation delay). Hoca bunu açar: bütün komutlar bir saat çevriminde gerçekleşir. Çevrim başladığında PC'ye değer yüklenir, yazmaç dosyasından değer okunur, çoklayıcılardan geçilir, işlem yapılır ve sonuç yazılır. Anlamlı verinin ilgili yere ulaşması zaman alır.

Bu yüzden bütün komutlar içinde en çok bloktan geçen, yani yürütülmesi en uzun süren komut bulunur. Onun süresi saat periyodunun alt sınırıdır. Daha yüksek frekansa çıkılırsa periyot bu süreden kısa olur ve komut bir sonraki saat kenarına kadar bitmez.

Slaytta bir komutun geçtiği bloklar ve gecikmeleri verilmiştir (ekrandan, 01:10:00):

| Blok | Gecikme |
|---|---|
| PC | 0,2 ns |
| Komut belleği | 4 ns |
| Yazmaç dosyası (okuma) | 0,6 ns |
| MUX B | 0,2 ns |
| Fonksiyon birimi ya da veri belleği | 4 ns |
| MUX D | 0,2 ns |
| Yazmaç dosyası (yazma) | 0,6 ns |

Bunların toplamı periyodu, tersi de en yüksek frekansı verir. Toplam $9{,}8$ ns'dir; en yüksek frekans yaklaşık $1 / 9{,}8\ \text{ns} \approx 102$ MHz olur (ara adım eklendi, python ile hesaplandı).

Bir komut yürürken bloklar sırayla etkin olur: PC'den komut belleğine, oradan çözmeye... Herhangi bir anda yalnız bir blok çalışır, diğerleri boşta bekler. Boşta bekleyen bir şey varsa bu iyileştirilebilir.

## 3. Boru hattı (pipeline) mantığı

### 3.1 Aşamalara bölme

Fikir, komut yürütmeyi fonksiyonel alt bloklara bölmektir. Aşama sayısı 3, 4, 5, 6 ya da 7 olabilir. Bir seferde tek komut yürütmek yerine, farklı komutların farklı parçaları farklı bloklarda aynı anda yürütülür. Derste beş aşamalı bir yapı kurulur:

- Komut getirme (Instruction Fetch, IF): komut, komut belleğinden getirilir.
- Komut çözme (Instruction Decode, ID): komutun ne yaptığı çözülür.
- İşlenen getirme (Operand Fetch, OF): komutun işlenenleri alınır.
- Yürütme (Execution, EX): işlem yapılır.
- Geri yazma (Write Back, WB): sonuç belleğe ya da yazmaç dosyasına yazılır.

Bloklar böyle art arda bağlı bırakılırsa tek çevrimli bilgisayardan farkı yoktur. Ayırmak için her bloğun çıktısı bir yazmaçta saklanmalıdır. Böylece bir blok sonraki komut üzerinde çalışırken önceki çıktısı bozulmaz ve sonraki saat çevriminde bir sonraki bloğa aktarılır. Her iki blok arasında bir yazmaç olması gerekir.

### 3.2 Boru hattı tablosu

Komutlar K1, K2, K3, K4, K5 sırayla bellekten çekilir. Hoca zaman–aşama tablosunu çizer (ekrandan, 01:15:00 ve 01:25:00):

| Aşama | t=1 | t=2 | t=3 | t=4 | t=5 | t=6 | t=7 |
|---|---|---|---|---|---|---|---|
| IF | K1 | K2 | K3 | K4 | K5 | | |
| ID | | K1 | K2 | K3 | K4 | K5 | |
| OF | | | K1 | K2 | K3 | K4 | K5 |
| EX | | | | K1 | K2 | K3 | K4 |
| WB | | | | | K1 | K2 | K3 |

$t = 1$'de K1 getirilir. $t = 2$'de sonuç ara yazmaçtan ID'ye aktarılır; IF boşta beklemesin diye K2 getirilir. $t = 3$'te K1'in işlenenleri alınır, K2 çözülür, K3 getirilir. $t = 5$'te boru hattı tamamen doludur: K1 geri yazılır, K2 yürütülür, K3'ün işlenenleri getirilir, K4 çözülür, K5 getirilir. $t = 6$'da K1 boru hattından çıkmıştır. Bundan sonra her çevrimde bir komut tamamlanır.

### 3.3 Frekans ve verim

Aşamaların yürütme süreleri incelenir; en uzun süreli aşama bütün boru hattı için ortak saat periyodunu belirler. Tüm sürece göre değil, en uzun aşamaya göre bir frekans seçildiği için sistem daha yüksek frekansla sürülebilir. Ayrıca verim (throughput) doğrudan artar: seri yürütmede boru hattında her an tek komut varken, burada aynı anda birden fazla komut yürür.

> **Ek bilgi (derste anlatılmadı):** Slayttaki gecikmelerde en uzun blok 4 ns'dir. Aşamalar bu bloklara göre ayrılırsa periyot büyük olasılıkla 4 ns'ye ve frekans yaklaşık 250 MHz'e kadar inebilir; ara yazmaçların kendi gecikmesi bu değeri biraz düşürür.

## 4. Boru hattı tehlikeleri ve dallanma

Komutların boru hattına aksamadan girebilmesi için kendi aralarında bazı koşulları sağlaması gerekir. Hoca bunları slayta yazar (ekrandan, 01:25:00):

- Ardışık olarak aynı ve tekil donanım kaynaklarını tüketmemeli.
- Ardışık komutlarda girdi değeri bir önceki komutun çıktısı olmamalı.
- Koşullu dallanma komutları olmamalı.

### 4.1 Yapısal tehlike (structural hazard)

Tek bir çarpma birimi varsa ve K1 ile K2 aynı zaman aralığında ona ihtiyaç duyuyorsa, ya da tek bir toplayıcı hem PC'yi artırmak hem işlemi yapmak için gerekiyorsa, kaynak aynı anda iki komuta verilemez. İki komut boru hattının farklı aşamalarında olsa bile aynı tekil donanıma ihtiyaç duyuyorsa birbirini beklemek zorundadır.

### 4.2 Veri tehlikesi (data hazard)

Örnekte ilk komut ADD R1, R2, R3 (sonuç R1'e), ikinci komut SUB R2, R3, R1'dir (R1 kaynak) (ekrandan, 01:25:00). Komutlar 100H, 101H, 102H... adreslerinden art arda çekilmiştir. İlk komutun sonucu oluşmadan, yani R1'e yazılmadan ikinci komut işlenen getirme aşamasına gelirse R1'in eski, güncellenmemiş değerini okur. Bu yüzden sonraki komutun girdisi önceki komutun çıktısı olmamalıdır.

Gerçek programlarda böyle bağımlılıklar doğal olarak oluşur. Bu durumda ya boru hattı bekletilir ya da iki bağımlı komut arasına bunlarla ilgisi olmayan başka bir komut yürütülür. Buna sırasız yürütme (out-of-order execution) denir.

### 4.3 Kontrol tehlikesi ve dallanma tahmini

Komutlar yürütülmeden önce bellekten art arda çekilip boru hattına konmuştur. Örneğin üçüncü komut bir koşullu dallanma olsun. K4 ve K5'in boru hattına girmesi ancak dallanma gerçekleşmezse anlamlıdır. Dallanma gerçekleşirse K4 ve K5 çöpe gider. Dallanmanın olup olmayacağı ise komut yürütülene kadar bilinmez.

Yapılabilecekler:

- Dallanma sonucu belli olana kadar boru hattını bekletmek.
- Hep sıradaki komutları (koşulun "false" kolunu) yüklemek. Yanlış çıkarsa boru hattındaki bazı işler çöpe atılır ve boşa işlem yapılmış olur.
- Daha önceki dallanmaların sonucuna (en son ne olduysa ona) göre false ya da true kolunu yüklemek.
- Kodun akışına bakıp hangi kolun yükleneceğine karar veren ayrı bir blok tasarlamak.

Hoca bir istatistik verir: x86 sistemlerde koşullu dallanma komutlarının yaklaşık %75'i "false" sonuç üretir. Bu hem donanımın hem de yüksek seviyeli dillerin derleyicilerinin kodu nasıl çevirdiğinin bir sonucudur. <!-- BELİRSİZ: Bu oranın kaynağı derste belirtilmedi. -->

**Soru (hoca):** Bu durumda sıradaki komutları yüklemeyi tercih eder misiniz? **Cevap (bir öğrenci):** Tercih edilebilir. Hoca onaylar ve gerekçesini verir: rastgele seçilse başarı %50 olurdu; sıradaki komutları yükleyerek en azından %75 olasılıkla boru hattına doğru komutlar alınmış olur.

Hoca konuyu üç tehlikeyle toparlar: veri tehlikesi (yeni komut önceki komutların sonucuna bağlıdır), yapısal tehlike (tekil donanım kaynağına farklı aşamalar aynı anda erişmek ister) ve dallanma ile koşullu dallanmada boru hattına alınan bazı işlerin çöpe gitmesi. Hepsi boru hattının performansını olumsuz etkiler.

## 5. Çok çevrimli yapıya geçiş

Boru hattı kullanmak için tek saat çevriminde komut yürüten mimariden uzaklaşıp birden fazla saat darbesiyle komut yürüten mimariye geçmek gerekir. Böyle bir yapıda yeni bir komutun mu yükleneceğine, yoksa önceki komutun alt adımlarının mı sürdüğüne bakılmalıdır. Hoca ayrıntıya girmeden slayttaki yapının farklarını gösterir:

- Ara yazmaçlar gerekir. Yazmaç dosyasında doğrudan erişilebilen yazmaçların yanında boru hattının her katının değerlerini saklayan yazmaçlar da bulunur, dosya büyür. Erişimin dışarıdan görünen yazmaçlara mı yoksa ara yazmaçlara mı yapıldığını belirleyen bir kontrol bloğu eklenir.
- Ayrı olan komut belleği ve veri belleği birleşmiştir.
- Kontrol birimi bir durum makinesine benzer; bir komut geldiğinde kaç saat çevrimi verileceğini ve yükleme yapılıp yapılmayacağını denetleyen ardışıl bir devre bloğu içerir.
- Çözmeden önce komutun kendisinin saklandığı bir komut yazmacı (instruction register) eklenmiştir. Bu, boru hattının ilk aşamasının çıkış yazmacı gibi düşünülebilir.

## 6. Giriş/çıkış sisteminin genel mimarisi

### 6.1 Yollar ve adres çözümleme

Mikro işlemcili bir sistemde işlemci, RAM (geçici bellek), ROM (kalıcı bellek) ve G/Ç birimleri vardır (ekrandan, 01:30:00 ve 01:35:00). İşlemciden veri, adres ve kontrol yolları çıkar; genişlikleri mimariye göre değişir. Veri yolu RAM ile çift yönlüdür, adres yolu gözleri seçer, kontrol uçları okuma ve yazmayı denetler. ROM yalnız okunur. G/Ç cihazları da veri yolundan okuyup yazabilir, adres ve kontrol işaretlerine göre çalışır.

Tek işlemcili bir yapıda işlemci aynı anda yalnız bir birimle konuşabilmelidir. Bunu bir adres çözümleme devresi sağlar. Bu devreye adres bitleri ve kontrol işaretleri girer, çıkışları birimlerin chip select uçlarını sürer. Tasarımda hangi birimin hangi adres aralığında olduğu bilinir. Yürütülen komut ROM'un aralığına düşüyorsa yalnız ROM seçilir; RAM ve G/Ç birimleri seçilmediği için yüksek empedans gösterir ve hattan kopmuş gibi davranır.

### 6.2 Bellek ve G/Ç uzayının ayrılması

Bu yapıda bellek birimleri ve G/Ç birimleri ayrı gruplanmıştır. 8086'da bellek işlemleri MOV komutuyla, G/Ç işlemleri IN ve OUT komutlarıyla yapılır. Fiziksel bir $M/\overline{IO}$ ucu vardır: MOV yürütülünce 1, IN/OUT yürütülünce 0 olur (ekrandan, 01:35:00). Her iki durumda adres ve veri değerleri aynı olabilir; bu uca bakılarak işlemin bellek mi G/Ç mı olduğu ayırt edilir.

Ayırmanın nedeni şudur: RAM ve ROM işlemcinin korunaklı uzayındadır; elektriksel seviye ve zamanlama olarak işlemciyle uyumlu hâle getirilmiştir. G/Ç cihazları ise çok geniş bir üretici yelpazesinden gelir; elektriksel seviyelerin ve protokollerin uyumlaştırılması gerekir. Dış dünyayla ilgili bu portların bellekten ayrılması daha uygundur.

### 6.3 Arayüz

RAM ve ROM doğrudan yollara bağlanırken G/Ç cihazlarının yapısı farklıdır. Paralel haberleşme, seri haberleşme, kesme denetimi, USB, SPI gibi çeşitli denetleyiciler vardır. Bu denetleyiciler ya da arayüzler (interface), dış dünyaya bağlanan donanımı işlemcinin adres, veri ve kontrol uçlarıyla uyumlu hâle getiren ara katmanlardır. Yani "G/Ç cihazı" dediğimiz şeyde aslında iki alt modül vardır: arayüz ve cihazın kendisi.

## 7. Klavye ve veri aktarım yöntemleri

### 7.1 Klavye tarama

G/Ç cihazları insanın bilgisayarla etkileşimini sağlayan dönüştürücülerdir. Klavyede bir mikro denetleyici vardır. Mikro denetleyici 3 bitle bir dekoder üzerinden 8 satırı, 4 bitle bir 16'ya 1 çoklayıcı üzerinden 16 sütunu denetler (ekrandan, 01:40:00).

Tarama şöyle yapılır. Dekodere 0 verilip ilk satır sürülür. Çoklayıcının seçim uçlarına sırayla 0, 1, 2, ..., 15 verilip her sütun mikro denetleyiciye okunur. Sonra dekoderden bir sonraki satır seçilir ve bütün sütunlar yine okunur. Bu, bütün satır ve sütunlar için tekrarlanır.

Bir tuşa basıldığında ilgili satır ve sütun kısa devre olur. Örneğin 2 numaralı satır sürülürken bir tuşa basılıysa, bu tuşun bulunduğu 11 numaralı sütuna 1 gelir. Tarama sırasında 11. sütun seçildiğinde tuş hâlâ basılıysa çoklayıcı çıkışında 1 okunur. Hangi satırın sürüldüğü ve hangi sütunun okunduğu bilindiği için basılan tuş bulunur. Bir insanın tuşa basıp bırakma süresi içinde klavye bütün taramayı belki yüzlerce kez yapar, bu yüzden tuşu yakalamak zor değildir.

Bulunan tuşun karakter kodu belirlenir ve PS/2, USB ya da Bluetooth arayüzüyle HID (insan arayüz cihazı) protokolü üzerinden gönderilir. Bütün tarama ayrı bir mikro denetleyicide yapılır; bu donanım işlemci yollarına doğrudan bağlı değildir. Arada bir arayüz vardır ve işlemciye aktarımı o yapar.

### 7.2 Üç aktarım yöntemi

> **Hocanın vurgusu:** Mikro işlemci ile G/Ç birimi arasındaki veri aktarımı üç şekilde olabilir: polling, interrupt ve DMA (direct memory access) (ekrandan, 01:45:00).

**Polling (yoklama):** İşlemci G/Ç cihazının ilgili yazmacını okur, maskeler ve istenen durum var mı diye bakar. Yoksa başa dönüp yeniden okur. Sürekli aktif okuma yaptığı için sürekli meşguldür.

**Interrupt (kesme):** İşlemci kendi genel görevlerini yürütür (ekrana yazma vb.). Klavyede bir tuş yakalanıp arayüze bildirilince arayüz işlemciye bir kesme isteği gönderir. İşlemci genel görevini durdurur, kesmeyle ilgili programı yürütür, sonra görevine geri döner. Kesme isteğiyle birlikte hangi programın yürütüleceği bilgisi de gelir. Kesme asenkron gelir ve donanım bunu yakalayabilir. Polling'de işlemci G/Ç yazmacını bir döngüde sürekli okurken, kesmede veri hazır olduğunda donanımsal bir istek gelir.

**DMA:** Polling ve kesmede veri her seferinde okunup işlemciye alınır. Bir G/Ç biriminden belleğe bir veri bloğu aktarılacaksa, G/Ç biriminden okuma ve belleğe yazma her adımda işlemciden geçer. DMA kontrolcüsü işlemciyi aradan çıkarır ve G/Ç birimi ile bellek arasında doğrudan aktarım yapar. Aktarımdan önce kontrolcüye başlangıç adresi (örneğin G/Ç biriminin okunacak yazmacı), hedef adresi (bellekte yazılmaya başlanacak yer) ve veri boyutu yüklenir. Sonra işlemci veri, adres ve kontrol yollarının denetimini DMA kontrolcüsüne bırakır. Kontrolcü veriyi adım adım aktarır, bitince kesmeyle işlemciyi uyarır ve yolların denetimini geri verir. DMA'nın en önemli özelliği verinin işlemciden geçmemesidir; ama bu süre boyunca işlemci yolların denetimini kaybeder.

## 8. İkincil bellek, önbellek ve ekranlar

İkincil bellek birimleri manyetik diskler ve SSD'ler gibi yapılardır. Yürütülen bütün komutlar aslında ana bellekten yürütülür; bir kod yürütülecekse mutlaka ana belleğe yüklenmiş olmalıdır. Ancak programlar o anda kullanılabilen bellekten çok daha büyük olabilir. Bu yüzden veri ikincil bellekte kalıcı tutulur ve yürütülecek kısım sayfa (page) olarak ana belleğe yüklenir.

Ana belleğe sürekli erişmek maliyetli olduğu için işlemci ile ana bellek arasına önbellek (cache) konur. Önce önbelleğe bakılır, aranan veri oradaysa oradan kullanılır. Önbelleğin avantajı programların yapısından gelir: algoritmalar döngüler, dizi işlemleri ve bir biriktiriciye tekrarlı erişimler içerir. Bir adrese erişiliyorsa sonraki çevrimlerde komşularına erişme olasılığı yüksektir; aynı adrese yeniden erişme olasılığı da yüksektir. Erişilen bölge ve çevresi önbelleğe alınırsa sonraki erişimlerde veriyi önbellekte bulma olasılığı artar.

> **Ek bilgi (derste anlatılmadı):** Hocanın anlattığı iki eğilim, uzamsal yerellik (komşu adreslere erişim) ve zamansal yerellik (aynı adrese tekrar erişim) adlarıyla bilinir.

Manyetik disklerde bit, manyetik kutup olarak saklanır; SSD gibi elektronik yapılarda bitin elektriksel bir karşılığı saklanır.

Ekranlarda eski CRT monitörler ekran yüzeyindeki üç renkli fosfor noktalarına elektron göndererek renk üretir. Bir pikselin üç renk alt pikseli birlikte etkinse beyaz, yalnız biri etkinse kırmızı, yeşil ya da mavi görünür; değişik oranlarla her renk kombinasyonu elde edilir. Elektron bir gerilimle koparılır, yatay ve dikey plakalardaki elektrik alanıyla yönlendirilip ilgili satır ve sütuna düşürülür. Günümüzde ise daha çok sıvı kristal (LCD) ve LED ekranlar vardır; bunlarda ışığın polarizasyonuyla piksel değerleri oluşturulur. <!-- BELİRSİZ: Altyazıda "RISC ekranlar" geçiyor; bağlamdan büyük olasılıkla LCD kastediliyor. -->

Bu arayüzlerin sağladıkları:

- Elektriksel seviye dönüşümü.
- Protokol uyumu.
- G/Ç cihazları genelde yavaş olduğu için kesme tabanlı aktarım desteği; işlemcinin veri gelene kadar beklemesinin önüne geçilir.

## 9. Paralel arayüz

Programlanabilir paralel arayüzün işlemci tarafında genelde 8 bitlik bir veri yolu vardır; 16 bitlik mimarilerde de 8 bitlik arayüzler yaygındır. Dış dünya tarafında iki ya da üç port (Port A, Port B, bazılarında Port C) ve kontrol/durum bitleri bulunur. 8086'yla kullanılan arayüzlerde Port C, kontrol ve durum işlevini de üstlenen çok görevli bir porttur.

İşlemci tarafında bir chip select (CS) ucu, iki yazmaç seçme ucu (RS1, RS0) ve okuma/yazma uçları (RD, WR) vardır. İç yapıda veri yolu tamponları, bir iç yol, Port A ve Port B yazmaçları, kontrol yazmacı, durum yazmacı ile zamanlama ve kontrol devresi bulunur (ekrandan, 01:55:00).

Yazmaç seçimi (ekrandan, 01:55:00):

| CS | RS1 | RS0 | Seçilen yazmaç |
|---|---|---|---|
| 0 | x | x | Hiçbiri: veri yolu yüksek empedansta |
| 1 | 0 | 0 | Port A yazmacı |
| 1 | 0 | 1 | Port B yazmacı |
| 1 | 1 | 0 | Kontrol yazmacı |
| 1 | 1 | 1 | Durum yazmacı |

> **Ders sonrası not:** Altyazıda kontrol ve durum yazmaçlarının ikisi de "1.0" diye geçer; slayta göre kontrol yazmacı 10, durum yazmacı 11'dir.

Hoca yüksek empedansı açıklar. Empedans, AC sinyalli devrelerde elemanların akıma karşı gösterdiği dirençtir; DC devrelerdeki dirence karşılık gelir. Yüksek empedans, çok yüksek direnç demektir; pratikte hattan seri olarak kopmak gibidir. Akım akmadığı için gerilim de içeri yansımaz. Cihaz seçilmediğinde yüksek empedans gösterir ve hattan kopmuş gibi davranır.

Port A yazmacı fiziksel olarak PA0–PA7 uçlarına bağlıdır. Port A çıkış yönünde ayarlanmışsa yazmaca yazılan değer uçlarda da görünür. Giriş yönünde ayarlanmışsa uçlara uygulanan gerilimin lojik seviyesi doğrudan yazmaca aktarılır; yazmaç bir mandal (latch) gibi çalışır ve okunduğunda o anki uç değerleri elde edilir. Port B için de aynısı geçerlidir. Kontrol yazmacı genelde çıkış yönlüdür; örneğin iki paralel arayüz haberleşirken bir tarafın kontrol işaretleri karşı tarafın durum bitlerine bağlanır. Durum yazmacı da karşı cihazın işini bitirdiğini algılamayı ve sonraki aktarıma başlamayı sağlar.

## 10. Strobe ve el sıkışma ile asenkron aktarım

Bu bölümdeki mantık hem arayüz ile G/Ç cihazı arasındaki, hem de iki G/Ç birimi arasındaki iletişim için geçerlidir. Verinin üretildiği yer kaynak birim (source unit), aktarılacağı yer hedef birimdir (destination unit).

### 10.1 Strobe ile aktarım

**Hedef başlatmalı aktarım (destination-initiated):** Hedef, veri okumak istediğini bir strobe (tetikleme) işaretiyle kaynağa bildirir. Kaynak bu işareti alınca veriyi hazırlar ve belirli bir süre sonra veri yoluna koyar. Hedef strobe'u kaldırdığında kaynak bir süre sonra veriyi yoldan kaldırır. Hedef veriyi strobe'un düşen kenarında örnekleyebilir; o anda yolda hâlâ anlamlı veri vardır (ekrandan, 02:05:00).

**Kaynak başlatmalı aktarım (source-initiated):** Kaynak önce anlamlı veriyi yola koyar, sonra strobe gönderir. Bir süre tutar, sonra strobe'u ve ardından veriyi kaldırır. Hedefin veriyi normalde strobe'un düşen kenarında örneklemesi beklenir.

İkisinde de bir sorun vardır. Kaynak başlatmalıda hedef o sırada başka bir işle meşgul olabilir ve strobe'u hiç fark etmeyebilir; kaynak verinin çöpe gidip gitmediğini bilemez. Hedef başlatmalıda da kaynak veriyi zamanında koyamamış olabilir; hedef belki önceki adımdan kalan ya da anlamsız bir veriyi okur. Burada el sıkışma yoktur; karşı tarafın uygun davrandığı yalnız varsayılır.

### 10.2 El sıkışma (handshaking)

Doğrulamayı sağlamak için iki işaret kullanılır: request ve reply (ekrandan, 02:10:00).

**Hedef başlatmalı el sıkışma:** Hedef "senden veri okumak istiyorum" diyerek request'i yükseltir. Kaynak bunu alınca veriyi hazırlar, yola koyar ve "anlamlı veriyi yola koydum" diye reply'ı yükseltir. Hedef reply'ı alınca request'i düşürür; bu düşen kenarda veri yolunu örnekler, yani veriyi okur. Kaynak request'in düştüğünü görünce verinin okunduğunu anlar, veriyi yoldan kaldırır ve reply'ı 0'a düşürür. Döngü request ve reply 0'dayken başlamıştır ve yine 0'da biter. Hedef verinin yolda olduğunu bilir; kaynak da koyduğu verinin okunduğuna dair bir cevap alır.

Hoca örnek verir: klavye kaynak başlatmalı aktarıma uygundur, çünkü tuşa basılınca veri hazırdır ve işlemci uyarılır. Yazıcı ise hedef başlatmalı yapıya örnek olabilir: yazıcı "basmayı bitirdim, bana yeni veri gönder" der.

**Kaynak başlatmalı el sıkışma:** Kaynak veriyi üretir (örneğin klavyede bir tuşa basılmıştır), önce yola koyar, sonra request'i 1'e çıkarır. Hedef "verini okuyorum" diye reply'ı yükseltir ve veriyi örnekler. Örnekleme tasarıma göre request'in yükseldiği anda ya da başka bir noktada yapılabilir. Kaynak reply'ı alınca request'i düşürür, sonra veriyi kaldırır. Hedef de reply'ı düşürerek başa döner. Böylece iki taraf da verinin yola konduğundan ve okunduğundan emin olur.

## 11. Seri haberleşme

### 11.1 Seri arayüz ve bit sırası

Seri arayüzün işlemci tarafında genelde 8 bitlik bir veri yolu, dış tarafta TxD (gönderme) ve RxD (alma) uçları vardır (ekrandan, 02:20:00). İşlemciden gelen 8 bitlik veri bir yazmaca alınır ve bit bit karşı tarafa gönderilir. Dışarıdan bit bit gelen veri biriktirilir, 8 bitlik paralel veri hâline getirilir ve işlemciye aktarılır. Yani göndermede paralelden seriye, almada seriden paralele dönüştürücü gerekir.

Önce en düşük anlamlı bit (D0) gönderilir, sonra D1, D2... Alıcı tarafında da ilk gelen bit en düşük anlamlı bittir. Gönderici yazmacını sağa öteleyerek tüketir; alıcı gelen biti soldan besleyip sağa öteler. Tekrarladıkça ilk giren D0 en düşük anlamlı bit konumuna kadar kayar.

### 11.2 Asenkron ve senkron haberleşme

Senkron haberleşmede iki terminal arasında TX, RX, saat ve ortak toprak olmak üzere dört tel vardır. Asenkron haberleşmede TX, RX ve toprak vardır; saat hattı yoktur.

Saat hattı şunu sağlar: iki terminalin kendi iç saatleri mükemmel olmayabilir, ama aktarım ortak saatin her yükselen kenarında bir bit olarak yürüdüğü için iç saatler farklı da olsa çok uzun bit dizileri gönderilebilir. Asenkron haberleşmede iç saatler arasında küçük bir fark varsa, örneğin 10 bitten sonra alıcı 11. biti atlayıp 12. biti okuyabilir; bir senkron kayması olur.

Bu yüzden asenkron haberleşmede veri 5, 6, 7 ya da 8 bitlik paketlerle gönderilir ve paketin başı ile sonu bir "parantezle" belirtilir. Hat boştayken lojik 1'dedir. Gönderen hattı 0'a çekerek aktarımın başladığını bildirir (start biti). İki taraf baştan baud hızında, veri biti sayısında, eşlik olup olmadığında ve stop biti sayısında anlaşmıştır. Start bitinden sonra en düşük anlamlı bitten başlayarak anlaşılan sayıda veri biti gelir; her bitin hatta kalma süresi baud hızıyla belirlidir. Ardından hat 1 ya da 1,5 bit süresi boyunca 1'de kalır (stop) ve sonraki çevrimi bekler (ekrandan, 02:20:00). Asenkron haberleşmede doğrulama için tek bir eşlik biti gönderilir.

Hoca örnek verir: 115200 baud hızında sistem saniyede 115200 değişimi destekler.

> **Ders sonrası not:** Altyazıda bit süresi "115.200 saniye" diye geçer; doğrusu $1/115200$ saniye, yani yaklaşık $8{,}68\ \mu\text{s}$'dir (python ile hesaplandı). Hoca büyük olasılıkla "1 bölü 115200" demiştir.

Senkron haberleşmede uzun bit dizileri gönderilebilir. Diziler uzun olduğu için girişime (gürültüye) açıktır; bu yüzden tek eşlik biti yerine çerçeveyi başlatan ve bitiren ayrı bit dizileri ve kontrol dizileri kullanılır. Gönderilen bütün veri bir fonksiyondan geçirilip bir doğrulama değeri üretilir. Alıcı kendi aldığı veri için aynı değeri hesaplar ve gelenle karşılaştırır; hata olup olmadığını anlar. Bazı doğrulama yöntemleri hatayı düzeltmeye de yardım eder.

### 11.3 Klavyede kesme tabanlı okuma

Klavyeden gelen veri hızı çok düşüktür. Hoca kaba bir hesap yapar: dakikada en fazla 300 kelime yazıldığı varsayılsa bile 8 ile çarpınca 2400 bit, ek bitlerle yaklaşık 3000 bit eder. RAM hızıyla karşılaştırıldığında bu, en yüksek durumda bile çok düşüktür. İşlemci bunu polling ile okumaya çalışsa çok vakit kaybeder. Bu yüzden yavaş G/Ç cihazları kesme tabanlı okunur. <!-- BELİRSİZ: Hesaptaki birimler altyazıda net değil ("300 kelime" × 8). -->

Tuşa basılınca bir saat işareti tetiklenir ve veri saat darbeleriyle bit bit karşı tarafa aktarılır, orada bir yazmaçta biriktirilir. Veri hazır olunca işlemci bir kesme isteğiyle tetiklenir. İşlemci genel kod akışını yarıda kesip veriyi okuyacak alt programı yürütür, okuduğu karakteri örneğin terminal ekranına basar ve genel işlemlerine döner. Polling'de ise kesme isteği yoktur: işlemci durum yazmacının adresini gönderir, okur, maskeler, aradığı değer yoksa yeniden okur. Tuşa basılıp veri yazmaca biriktirilene kadar boşuna bekler.

### 11.4 USB

USB cihazları hub'lar ve denetleyiciler üzerinden haberleşir ve enerjilerini alır. Slaytta bilgisayardaki kök hub'a (root hub) monitör ve yazıcı bağlıdır; monitörün hub'ına klavye ve başka bir hub, klavyenin hub'ına fare ve oyun çubuğu, diğer hub'a mikrofon ve iki hoparlör, yazıcının hub'ına tarayıcı bağlıdır (ekrandan, 02:25:00). Hoca bu konunun üzerinde durmaz.

### 11.5 Bit kodlama: NRZI ve Manchester

Seri haberleşmede bit değerini doğrudan göndermek de, bitleri farklı biçimde kodlamak da kullanılır.

**NRZI (non-return-to-zero inverted):** Art arda gelen 0'ları birbirinden ayırt edebilmek için her 0'da bir durum değişimi yapılır. 1'ler için böyle bir değişim yoktur.

**Manchester kodlama:** Lojik 0 düşen kenarla, lojik 1 yükselen kenarla gönderilir. Böylece her bit için mutlaka bir geçiş olur. Yakalanan her geçiş, senkronu tutturmak için kullanılabilecek bir an sağlar.

> **Ek bilgi (derste anlatılmadı):** Manchester kodlamada derste söylenen kural (0 = düşen kenar, 1 = yükselen kenar) IEEE 802.3 gösterimidir; bazı kaynaklarda ters gösterim de kullanılır.

### 11.6 Senkron paket yapısı

Slayttaki pakette önce bir senkronizasyon bit dizisi vardır; haberleşmenin başlayacağını bildirir. Ardından verinin kimden kime gideceğini belirten bir alan gelir. Veri paketinde aktarım sırasında hata oluşup oluşmadığını tespit eden ve gerekirse düzelten bir CRC alanı (ya da checksum) bulunur. Paket ayrı bir paket sonu (End of Packet) dizisiyle biter. Hata düzeltme önemlidir: uzun bir bit dizisini seri olarak yeniden istemek maliyetlidir, mümkünse gelen veriyi yerinde düzeltmek daha verimlidir.

## 12. Polling ve kesme tabanlı aktarım

### 12.1 Polling akışı

Slayttaki yapıda işlemci, arayüz ve G/Ç cihazı vardır. Arayüzde bir veri yazmacı ve bir durum yazmacı bulunur; durum yazmacının bir biti bayraktır (flag). G/Ç cihazı veriyi hazırlayınca Ready işaretiyle arayüze gönderir, arayüz Acknowledge ile cevap verir (ekrandan, 02:30:00). Veri arayüze aktarılınca durum yazmacının bayrağı 1 olur.

İşlemci adres uçlarıyla veri yazmacını ya da durum yazmacını seçebilir. Polling akışı şöyledir:

```text
1. Durum yazmacının adresini gönder, veri yolundan durum yazmacını oku.
2. Okunan değeri maskele; bayrak 1 mi?
3. 0 ise 1. adıma dön.
4. 1 ise veri yazmacının adresini gönder, veriyi oku.
5. Veriyi işle ve 1. adıma dön.
```

Bayrak 1 olduğunda G/Ç cihazı veriyi oluşturmuş ve arayüzün veri yazmacına aktarmış demektir.

### 12.2 Birden fazla kesme kaynağı ve vektör adresi

Kesme isteği gönderebilecek birden fazla G/Ç cihazı olabilir, ama işlemcinin tek bir donanımsal kesme isteği ucu (INTR) vardır. Bir kaynaktan istek geldiğinde işlemci kaynağa onay (acknowledge) işaretleri gönderir ve kaynaktan bir vektör adresi bekler. Vektör adresi, o kaynağın kesmesine karşılık hangi programın yürütüleceğinin bilgisidir; her kesme kaynağının kendi vektör adresi olabilir.

### 12.3 Papatya zinciri (daisy chain)

Kaynakların isteği bir OR kapısı üzerinden işlemcinin kesme girişine bağlanır. İşlemcinin onay çıkışı en yüksek öncelikli cihazın giriş ucuna bağlanır; bağlama sırası önceliği belirler. Kesmeyi bu cihaz istemişse onayı alır almaz kendi vektör adresini veri yoluna koyar ve işlemci bu adresteki programı yürütür. İstemeyen cihaz vektör adresi çıkarmaz, onayı zincirdeki bir sonraki cihaza aktarır. Kesmeyi isteyen cihaz onayı alınca kendi vektör adresini (örneğin VAD2) veri yoluna çıkarır; işlemci 2 numaralı cihaza ait kesme alt programını yürütür. Öncelik giriş ve öncelik çıkış (PI/PO) mantığı bir flip-flop ile tanımlanabilir; hoca bunun ayrıntısına girmez.

### 12.4 Öncelik kodlayıcı ile paralel öncelik

Birden fazla cihazın tam aynı anda kesme istemesi çok düşük olasılıktır. Ancak sistem senkron bir ardışıl devre olduğu için iki saat kenarı arasında farklı anlarda gelen bütün istekler eş zamanlı sayılır; daha ince bir denetim çözünürlüğü yoktur. İki saat arasında gelen istekleri önceliklendirmek için öncelik kodlayıcı (priority encoder) kullanılır.

Öncelik kodlayıcı en yüksek anlamlı girişten başlayarak ilk gördüğü 1'in ikili karşılığını çıkışa verir. Normal kodlayıcıda yalnız bir girişin 1 olmasına izin verilirken burada birden fazla 1 olabilir. Kesme istekleri 3, 2, 1, 0 sırasıyla bağlanırsa öncelik atanmış olur.

Slayttaki yapıda kesme yazmacının her biti (3 en yüksek, 0 en düşük öncelik) maske yazmacının aynı numaralı bitiyle AND'lenir ve AND çıkışları kodlayıcının $D_3 \ldots D_0$ girişlerine gider (ekrandan, 02:35:00). Böylece istenen kaynak maskelenebilir. Örneğin A cihazı en yüksek önceliğe, sonra sırasıyla B, C, D'ye öncelik verilmiş olsun. Belirli bir anda A'nın isteği maskelenmek istenirse maske yazmacına 0111 yazılır; A en yüksek öncelikli olsa da kodlayıcıda çıktı üretmez. Hem öncelik tanımlanır hem istenen kaynak maskelenir.

Kodlayıcının $A_1 A_0$ çıkışları dört farklı durumu gösterir. Vektör adresi (VAD), bu iki bit ve geri kalan altı bitin 0 olmasıyla 8 bit olarak oluşturulur. Kodlayıcının $V$ çıkışı işlemciye kesme isteği olarak gider; işlemcinin kesme onayı VAD'ı veri yoluna çıkarır (ekrandan, 02:35:00).

## 13. DMA kontrolcüsü

DMA kontrolcüsü G/Ç birimi ile bellek arasındaki aktarımı arada işlemci olmadan yapar. İşlemci önce kontrolcüyü programlar: başlangıç adresi, hedef adresi ve aktarılacak verinin boyutu (bit ya da bayt cinsinden). Sonra yolların denetimi kontrolcüye geçer.

Kontrolcü başlangıç adresini ve hedef adresini sırayla etkinleştirir; seçilen iki birim arasında veri, işlemcinin veri yolu üzerinden doğrudan aktarılır, işlemciye uğramaz. Ardından kontrolcü sayacı, başlangıç adresini ve hedef adresini bir artırır ve sonraki veriyi aktarır. Bunu veri boyutu kadar tekrarlar. Bitince işlemciye bir kesme isteği gönderir; işlemci o sırada beklemede olduğu için bu kesmeyle yeniden devreye girer. <!-- BELİRSİZ: Altyazıda sayacın "bir artırıldığı" söyleniyor; kaynak kitapta kelime sayacı büyük olasılıkla her aktarımda azaltılır. -->

Slayttaki bağlantı yapısında (ekrandan, 02:40:00) işlemcinin Interrupt, BG (bus grant) ve BR (bus request) uçları, DMA kontrolcüsünün aynı adlı uçlarına bağlıdır. Kontrolcünün DS (DMA select) ve RS (register select) uçları bir adres dekoderinden sürülür; işlemci kontrolcünün yazmaçlarını bu yolla programlar. Kontrolcü G/Ç cihazıyla DMA request ve DMA acknowledge işaretleriyle konuşur. Okuma ve yazma kontrol hatları ile adres ve veri yolları işlemci, bellek ve kontrolcü arasında ortaktır.

Akış: işlemci önce DMA'yı programlar. Sonra BR ve BG uçlarıyla veri ve adres yolunun denetimini kontrolcüye bırakır. Kontrolcü okuma/yazma işaretleriyle G/Ç cihazından belleğe veri yolu üzerinden aktarım yapar; bu sırada veri hiç işlemciye uğramaz. Bütün veri aktarılınca kesme tetiklenir, yolların denetimi DMA'dan alınıp yeniden işlemciye verilir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:10:00)

16 bit adres ve 32 bit veri yolu genişliği olan bir bellek modülünün kapasitesi aşağıdakilerden hangisidir? a) 128 KB, b) 256 KB, c) 512 KB, d) 1 MB, e) 2 MB

> **Çözüm:** $2^{16} \cdot \frac{32}{8} = 64\text{K} \cdot 4 = 256$ KB. Cevap b (python ile kontrol edildi). Diğer grupta 12 bit adres ve 64 bit veri yolu ile $2^{12} \cdot 8 = 32$ KB bulunur.

### Soru 2 (ekrandan, 00:15:00)

128K×16'lık DRAM modülü kullanılarak 1M×32 kapasitesinde RAM bloğu tasarlanmak isteniyor. Buna göre kaç adet RAM modülü ve nasıl bir dekodere ihtiyaç vardır? a) 8 adet RAM ve 2-to-4 dekoder, b) 16 adet RAM ve 2-to-4 dekoder, c) 8 adet RAM ve 4-to-16 dekoder, d) 8 adet RAM ve 3-to-8 dekoder, e) 16 adet RAM ve 3-to-8 dekoder

> **Çözüm:** $\frac{1\text{M} \cdot 32}{128\text{K} \cdot 16} = 16$ modül. İkişer modül yan yana konunca 8 satır blok oluşur; 8 bloğu seçmek için 3'e 8 dekoder gerekir. Cevap e.

### Soru 3 (derste sözlü, 00:13:37)

Komut uzunluğu 20 bit, yazmaç sayısı 32'dir ve komut formatında üç yazmaç alanı vardır. Kaç farklı işlem kodu (opcode) tanımlanabilir?

> **Çözüm:** Her yazmaç alanı $\log_2 32 = 5$ bit, üçü 15 bit. Opcode'a 5 bit kalır: $2^5 = 32$ işlem kodu. Diğer grupta 24 bit ve 64 yazmaçla $24 - 18 = 6$ bit, $2^6 = 64$ işlem kodu (python ile kontrol edildi).

### Soru 4 (ekrandan, 00:20:00)

Bir devrenin A, B, C, D çıkışları için aşağıdakilerden hangisi doğrudur? a) $A = \sum m(1,2,5,7)$, b) $B = \sum m(0,2,4,7)$, c) $C = \sum m(0,1,4,6)$, d) $D = \sum m(1,3,5,7)$, e) Diğer şıkların tamamı yanlıştır. <!-- BELİRSİZ: Devre şekli ekranda görülmedi; soru metninin başı karede yok. -->

> **Çözüm:** Hoca devredeki terimlerin üçlü ya da ikili terimler olduğunu, şıklardaki fonksiyonların dört mintermli olduğunu söyleyerek e şıkkını işaretler. Cevap anahtarında bu soru başta yanlış şıkla işaretlenmişti, doğru cevap e'dir.

### Soru 5 (ekrandan, 00:30:00)

Şekilde verilen 4 FF'lu devrede başlangıç koşulu $(Q_0, Q_1, Q_2, Q_3) = (0, 0, 1, 1)$ olarak veriliyor. Çıkışların 3 clock sonraki değerleri aşağıdakilerden hangisidir? a) $(1, 0, 1, 1)$, b) $(1, 0, 0, 1)$, c) $(1, 1, 1, 1)$, d) ...

Devre: dört D flip-flop; her birinin $\overline{Q}$'su kendi $D$'sine bağlı, FF0'ın saati CK, FF1, FF2, FF3'ün saati sırasıyla $Q_0$, $Q_1$, $Q_2$.

> **Çözüm:** Her flip-flop kendi saatinin yükselen kenarında toggle eder. 1. kenar: $Q_0$ 0→1 (yükselen), $Q_1$ 0→1 (yükselen), $Q_2$ 1→0 (düşen, durur): $(1,1,0,1)$. 2. kenar: $Q_0$ 1→0 (düşen, durur): $(0,1,0,1)$. 3. kenar: $Q_0$ 0→1, $Q_1$ 1→0 (düşen, durur): $(1,0,0,1)$. Cevap b (python ile simülasyonla doğrulandı). Diğer grupta başlangıç $(1,0,0,1)$ ve iki saat sonrası sorulur; sonuç $(1,1,1,0)$'dır.

### Soru 6 (ekrandan, 00:35:00)

Aşağıda verilen doğrusal geri beslemeli ötelemeli yazmaç (Linear Feedback Shift Register) senkron devresinde hangi "present state $(q_A, q_B, q_C, q_D)$" / "next state $(Q_A, Q_B, Q_C, Q_D)$" değeri doğrudur? a) $(0,0,0,0)/(1,0,0,0)$, b) $(0,1,0,1)/(0,0,1,0)$, c) $(1,0,0,1)/(0,1,0,0)$, d) $(0,0,1,1)/(0,0,0,1)$, e) $(0,1,0,0)/(0,0,1,0)$

Devre: A→B→C→D zinciri, ortak saat; A'nın girişi $q_B \oplus q_D$.

> **Çözüm:** $Q_A = q_B \oplus q_D$, $Q_B = q_A$, $Q_C = q_B$, $Q_D = q_C$. $(0,1,0,1)$ için $Q_A = 1 \oplus 1 = 0$, $Q_B = 0$, $Q_C = 1$, $Q_D = 0$: $(0,0,1,0)$. Cevap b (python ile kontrol edildi). Örneğin a şıkkında $(0,0,0,0)$'dan yine $(0,0,0,0)$'a geçilir, $(1,0,0,0)$'a değil.

### Soru 7 (derste sözlü, 00:33:38)

8, 9, 10, 11, 12 sayıp kendini tekrarlayan, dışarıdan girişi olmayan bir sayıcı JK flip-flop'larla tasarlanacaktır. En az kaç flip-flop gerekir ve devre ne tür bir makinedir?

> **Çözüm:** 5 durum vardır: $\lceil \log_2 5 \rceil = 3$ flip-flop. Dış giriş olmadığı için Moore makinesidir. Diğer grupta (3, 4, 5, 6, 7) yine 3 flip-flop ve Moore makinesi.

### Soru 8 (derste sözlü, 00:36:10)

5 bitlik herhangi iki sayının (işaretli ya da işaretsiz) çarpımını saklayabilmek için en az kaç bitlik yazmaç gerekir?

> **Çözüm:** $n$ bitlik iki sayının çarpımı $2n$ bit ister: 10 bit. Diğer grupta 4 bit için 8 bit ($15 \cdot 15 = 225$).

### Soru 9 (ekrandan, 00:40:00)

Şekildeki öteleme-toplama çarpıcısında A her saatte bir sola, B bir sağa ötelenir; B'nin en düşük anlamlı biti A ile AND'lenip P'ye eklenir. 4 bitlik iki işaretsiz sayının çarpımı için A, B, toplayıcı ve P en az kaç bit olmalıdır? Başlangıçta değerlerin yüklü olduğu varsayılırsa çarpım kaç saat darbesinde biter? <!-- BELİRSİZ: Soru metni ekranda görülmedi; soru altyazıdaki anlatımdan kuruldu. -->

> **Çözüm:** 15 × 15 en kötü durumdur. P: 0, 15, 45, 105, 225; A: 15, 30, 60, 120, 240; B: 15, 7, 3, 1, 0 (ekrandan, 00:45:00; python ile kontrol edildi). Son adımdaki 240 kullanılmadığı için A'da korunacak en büyük değer 120'dir: A 7 bit. B 4 bit. En büyük toplama $120 + 105$ olduğu için toplayıcı 7 bit, P 7 bit; 225'in 8. biti Cout'ta tutulur. Çarpım 4 saat darbesinde biter.

### Soru 10 (derste sözlü, 00:38:01)

Bit işleme komutlarıyla ilgili aşağıdakilerden hangisi yanlıştır? (Şıklardan biri: "NEG komutu birler tümleyenini hesaplar." Bir başkası: R1'in 1. bitini temizlemek için uygun maske.) <!-- BELİRSİZ: Şıkların tam metni ekranda görülmedi. -->

> **Çözüm:** NEG ikiye tümleyen alır, bu yüzden ilk ifade yanlıştır. R1'in 1. bitini temizlemek için yalnız o biti 0 olan $\text{FD} = (1111\,1101)_2$ ile AND yapılır; diğer bitler korunur.

### Soru 11 (derste sözlü, 01:06:23)

Tek çevrimli (hardwired) mimaride kullanılabilecek en yüksek saat frekansını ne belirler?

> **Çözüm:** Yayılım gecikmesi. En çok bloktan geçen, yani en uzun süren komutun toplam gecikmesi saat periyodunun alt sınırıdır. Slayttaki gecikmelerle toplam $9{,}8$ ns ve en yüksek frekans yaklaşık 102 MHz'tir (ekrandan, 01:10:00; python ile hesaplandı).

### Soru 12 (derste sözlü, 01:22:13)

x86 sistemlerde koşullu dallanmaların yaklaşık %75'inin "false" sonuç verdiği biliniyorsa, boru hattına sıradaki komutları yüklemek tercih edilir mi?

> **Çözüm:** Evet. Rastgele seçimde doğru tahmin olasılığı %50 olurdu; sıradaki komutlar yüklenirse boru hattına yaklaşık %75 olasılıkla doğru komutlar alınır. Yanlış çıkarsa alınan işler çöpe atılır.

## Dersin Toparlaması

Dersin ilk yarısında vize soruları üzerinden önceki haftaların konuları tekrar edildi: işaretli aritmetik ve bayraklar, ikiye tümleyen, adresleme modları, bellek kapasitesi ve genişletme, aritmetik öteleme, komut formatı, programlanabilir lojik (PLA, PAL, ROM), sıfır ve eşlik bayrakları, ripple sayıcı, LFSR, sayıcı tasarımı, çarpım genişliği, TEST ve NEG komutları ve öteleme-toplama çarpıcısı.

İkinci yarıda tek çevrimli bilgisayarın saat frekansının en uzun yol tarafından sınırlandığı gösterildi ve bu sınırı aşmak için beş aşamalı boru hattı kuruldu. Boru hattının yapısal, veri ve kontrol tehlikeleri ile dallanmada izlenebilecek yollar tartışıldı. Ardından giriş/çıkış sistemine geçildi: adres çözümleme, bellek ve G/Ç uzayının ayrılması, arayüzün görevi, klavye taraması, polling, kesme ve DMA ile aktarım, paralel arayüz, strobe ve el sıkışma, asenkron ve senkron seri haberleşme, NRZI ve Manchester kodlama, papatya zinciri ve öncelik kodlayıcıyla kesme yönetimi ve DMA kontrolcüsünün bağlantı yapısı anlatıldı. Ders bir sonraki hafta kalınan yerden devam edecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
