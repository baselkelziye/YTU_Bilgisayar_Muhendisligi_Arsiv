# Ders 4 Genişletilmiş Notu: Hafıza Elemanları: Hiyerarşi, RAM ve ROM Yapısı, Hafıza Arayüzü ve Genişletme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hafıza hiyerarşisi
- 2. Yerellik ve ön belleğin çalışması
- 3. Kalıcı ve geçici hafıza: ROM ve RAM'in kullanım yerleri
- 4. RAM'in blok yapısı ve iç yapısı
- 5. ROM çeşitleri ve iç yapısı
- 6. SRAM ve DRAM
- 7. Hafıza tanımları
- 8. Harvard ve von Neumann mimarileri
- 9. Ortak yol, adres çözümleme ve chip select
- 10. Mikroişlemciye uygun hafıza arayüzü
- 11. Hafızayı lojik fonksiyon olarak kullanmak
- 12. Erişim süresi, yazma süresi ve hafıza çevrimleri
- 13. Tek çevrim, çok çevrim ve boru hattı
- 14. RAM hücresinden RAM entegresine
- 15. Kapasite ve veri yolu genişletme
- Örnek Sorular

Bu derste lojik devre tekrarının son başlığı olan hafıza elemanları işlenir. Dersin ilk yarısında önceki slayt setinin sonundaki "Memories" bölümü üzerinden hafıza hiyerarşisi, RAM ve ROM'un temel yapısı anlatılır. Aradan sonra hafıza temelleri slaytlarıyla hafıza tanımları, mimariler, adres çözümleme, mikroişlemciye uygun hafıza arayüzü, okuma ve yazma çevrimleri ve hafıza genişletme ele alınır. Anlatım İngilizce slaytlar üzerinde el çizimiyle yürür.

## 1. Hafıza hiyerarşisi

Bir bilgisayardaki hafıza birimleri bir hiyerarşi içinde düşünülebilir. Hoca bunu tahtaya iç içe kutular olarak çizdi: CPU ve içindeki yazmaçlar, ön bellek, bellek ve ikincil hafıza (ekrandan, 00:10:00).

### 1.1 Yazmaçlar

En üstte CPU'nun içindeki **yazmaçlar** (register) vardır. Bunlar çok yüksek hızlı hafıza elemanlarıdır, ancak imalat maliyetleri yüksektir; bu yüzden az sayıda ve küçük kapasitede kullanılırlar. Hoca, Mikroişlemci Sistemleri dersinden hatırlatarak, Intel mimarisinde dışarıdan erişilebilen AX, BX, CX, DX gibi az sayıda genel amaçlı yazmaç olduğunu, 64 bitlik sürümlerde bunların çeşitlendiğini ve ayrıca vektör yazmaçları bulunduğunu söyledi. Yazmaçlar komutlar yürütülürken girdi sağlar ve işlem sonuçlarını tutar. Hiyerarşinin en hızlı, kapasitesi en düşük ve birim maliyeti en yüksek kısmıdır.

### 1.2 Ön bellek, bellek ve ikincil hafıza

Sonraki seviye **ön bellektir** (cache). Ön belleğin CPU içinde yer alan seviyeleri de, hemen CPU dışında yer alan seviyeleri de vardır; tahtadaki çizimde bu yüzden CPU kutusuyla iç içe çizildi. Ön bellek yazmaçlardan daha yavaştır ama daha yüksek kapasitededir.

Ardından **bellek** (ana bellek) gelir. Günümüzde bellek dinamik RAM mantığıyla kurulur; bunun ne demek olduğu derste ilerde görülür. En altta ise **ikincil hafıza birimleri** vardır: sabit disk, manyetik teyp, CD-ROM gibi.

Hiyerarşide CPU'dan ikincil hafızaya doğru gidildikçe hız düşer, erişim süresi artar ve ikincil hafızada çok yüksek değerlere ulaşır. Birim başına üretim maliyeti ise CPU'ya yakın birimlerde daha yüksektir.

> **Ders sonrası not:** Hoca 00:13:26'da "erişim süresi CP içerisindeki elemanlarda en yüksek" dedi, hemen ardından ön belleğe ve belleğe doğru gittikçe arttığını söyledi. Doğrusu, erişim süresi yazmaçlarda en düşüktür ve aşağı seviyelere doğru artar; ilk ifade bir dil sürçmesidir.

### 1.3 Hız ile erişim süresi farkı

**Soru:** Erişim süresiyle hız arasındaki fark nedir? İkisi aynı yönde mi değişiyor?

**Cevap:** Hız, tek başına bir hafıza elemanına girdi verildiğinde çıktı üretme süresidir. Erişim süresi ise hiyerarşi içinde önce bir yerde arayıp bulunamazsa ötekine bakmayı, CPU'nun adres çözümlemesini ve farklı elemanlara bakmayı da içerir. İkisi yakın kavramlardır, ama erişim süresi dış etkenleri de kapsar. İleride ön bellekten bir veriyi bulma ve bulamama olasılıkları hesaba katılarak ortalama erişim süresi hesaplanacaktır.

## 2. Yerellik ve ön belleğin çalışması

### 2.1 Uzamsal ve zamansal yerellik

CPU bir komut ya da veri için bellekten okuma yapmak istediğinde, isteği belleğe götürüp sonucu geri getirmek uzun sürer. Daha küçük ama hızlı bir ön bellek, programların genel bir özelliğinden yararlanarak performansı artırır. Hoca bunu iki örnekle tahtaya yazdı (ekrandan, 00:10:00):

```text
for (i = 0; i < 100; i++)
    x = array[i];        -> spatial locality

for (...)
    x = x + i;           -> temporal locality
```

İlk döngüde sıfır indisli elemana erişildikten sonra bir sonraki adımda bir indisli elemana erişilir; erişimler hep komşu adreslere gider. Bu, **uzamsal yerellik** (spatial locality) özelliğidir. İkinci döngüde ise aynı $x$ değişkenine farklı zamanlarda tekrar tekrar erişilir; bu da **zamansal yerellik** (temporal locality) özelliğidir.

### 2.2 Blok halinde getirme ve yerleştirme

Bu özellikler yüzünden CPU bellekte bir adrese eriştiğinde bellekten tek bir veri okunmaz; erişilen nokta ve çevresindeki bellek bölgesi ön belleğe aktarılır. Sonraki erişimde CPU önce ön belleğe bakar. Veri oradaysa ön bellekten kullanılır; ön belleğin erişim hızı yüksek olduğu için ortalama erişim süresi kısalır.

> **Ders sonrası not:** Hoca 00:10:40'ta "ortalama erişim süremi arttırmış oldum" dedi. Kastedilen, ön bellekte bulunan veriler sayesinde ortalama erişim süresinin **azalmasıdır** (ya da erişim hızının artmasıdır).

Aranan veri ön bellekte yoksa CPU bellekten ilgili bloğu getirir ve ön bellekte bir yere yerleştirir. Boş yer kalmamışsa hangi bloğun kaldırılacağına karar verilmesi gerekir. Boş yer olsa bile, ön belleğin yerleştirme kurallarına (politikalarına) göre mevcut bloklardan biri kaldırılıp yenisi onun yerine konabilir.

### 2.3 Bellek ile ikincil hafıza arasındaki benzer ilişki

Programlar belleğe yüklenip oradan çalıştırılır. Ancak program belleğe sığmayacak kadar büyük olabilir ya da zaman paylaşımlı çalışmada bellekte yer kalmamış olabilir. Bu durumda bellekteki bir sayfa (page) kaldırılır, yerine gereken sayfa ikincil hafızadan getirilir. Sonuçta zincir şöyle işler: CPU önce ön belleğe bakar; yoksa bellekten getirir; bellekte de yoksa ikincil hafızadan bir sayfa belleğe, oradan bir parça ön belleğe getirilir ve CPU onu işler.

## 3. Kalıcı ve geçici hafıza: ROM ve RAM'in kullanım yerleri

Derste iki temel hafıza türü ele alınır: kalıcı hafıza (ROM tarzı) ve geçici hafıza (RAM tarzı).

Kalıcı hafızada program bir kez yazıldıktan sonra enerji kesilse bile içerik kalır. Enerji yokken hafıza gözlerine erişilemez ama program orada durur; enerji verilince tekrar okunabilir. RAM gibi geçici hafızalar ise enerji olduğu sürece veriyi saklar, enerji kesilince kaybeder.

### 3.1 BIOS ve reset vektörü

Sistemin açılışına yönelik programlar, örneğin BIOS, ROM tabanlı çiplerde bulunur. Açılışta bu program çevre birimlerini kontrol eder, CPU'yu uygun şekilde şartlar ve açılışı işletim sistemine devreder. BIOS'taki program güncelleme sırasında bozulursa bilgisayar açılmaz. CPU'ya ilk enerji verildiğinde baktığı adres, yani **reset vektörünün** gösterdiği adres alanında böyle bir ROM'un bulunması uygundur.

Şartlamaya örnek olarak hoca, 64 bitlik Intel işlemcilerin bile ilk enerji verildiğinde 16 bitlik modda açıldığını ve bir durum geçiş diyagramı üzerinden 64 bitlik kullanıcı moduna getirilmesi gerektiğini söyledi; bu geçişler de BIOS'un kontrolünde yapılır.

### 3.2 Mikrodenetleyici ve genel amaçlı bilgisayar farkı

Mikrodenetleyici programlarken aslında onun ROM'u programlanır. CPU açıldığında belirli bir adresten çalışmaya başlar; derlenen program o adresten itibaren yerleştiği için doğrudan çalışır. Mikrodenetleyicilerde ayrıca bir RAM alanı da vardır.

Genel amaçlı bir bilgisayarda ise ROM'daki program ön kontrolleri yapıp açılışı işletim sistemine devreden bir ara kontroldür. İşletim sistemi ikincil hafızadan sayfalar halinde belleğe, oradan ön belleğe ve CPU'ya aktarılarak yüklenir. Kullanıcı programları RAM üzerinde çalışır; sığmayan kısımlar ikincil hafızada sayfa boyutunda bloklar halinde durur ve gerektikçe belleğe getirilir.

## 4. RAM'in blok yapısı ve iç yapısı

### 4.1 ROM ile RAM'in temel farkı ve kapasite

Önceki derste programlanabilir cihazlarda görüldüğü gibi, ROM'un içinde adres ucu sayısı kadar girişi olan ve $2^{\text{adres}}$ tane satır (hafıza gözü) seçebilen bir dekoder vardır. $N$ adres ucu olan ve her gözü $M$ bit olan bir ROM'un kapasitesi $2^N \times M$ bittir. ROM kalıcıdır ve operasyon sırasında yalnız okunur. RAM ise operasyon sırasında hem okunur hem yazılır.

Slayttaki RAM özellikleri şunlardır (ekrandan, 00:25:00):

- Büyük miktarda veriyi saklamada yazmaçlardan daha verimlidir.
- Okunabilir ve yazılabilir, adreslenebilir bir hafızadır.
- Senkron (saatli) ya da asenkron (saatsiz) olabilir.
- SRAM boyutu (kelime sayısı) $\times$ (kelime başına bit) diye verilir. Adres $m$ bit, veri $n$ bit ise $2^m \times n$ bitlik RAM'dir.
- Örnek: adres 5 bit, veri 8 bit ise $32 \times 8$ bitlik RAM.
- Yazma: veri girişi ve adres stabil olur, write işareti verilir (sonra geri çekilir).
- Okuma: adres stabil olur, read işareti verilir, veri çıkışı geçerli olur.

Blok şemada veri girişi ($n$), adres ($m$), write ve read girişleri ile veri çıkışı ($n$) vardır. $32 \times 8$ örneğinde içeride 32 göz vardır ve her biri 8 bit saklar; veri girişi ve çıkışı 8 bittir, 32 gözü seçebilmek için dekoderin $\log_2 32 = 5$ girişi, yani 5 adres ucu gerekir. Böylece adres ve veri ucu sayıları RAM kapasitesinden bulunur.

Şemada veri girişi ve veri çıkışı ayrı çizilmiştir. Ancak daha önce görülen üç durumlu tampon (tri-state buffer) mantığıyla aynı uçlar hem okuma hem yazma için kullanılabilir: dışarıdan gelen uçlar RAM'in hemen içinde ikiye ayrılıp tamponlarla giriş ya da çıkış yönüne bağlanır.

### 4.2 İç yapı: dekoder ve üç durumlu tamponlar

RAM'in iç yapısında $m$'den $2^m$'e bir dekoder bulunur (ekrandan, 00:20:00). Dekoderin çıkışları Sel$_0$, Sel$_1$, ..., Sel$_{2^m-1}$ satırlarını seçer. Her satır $n$ bitlik bir hafıza gözüdür. Veri girişleri $d_{n-1}, \dots, d_0$, write işaretiyle kontrol edilen üç durumlu tamponlardan geçerek hücrelere ulaşır. Hücrelerin çıkışları sütun boyunca ortaklanır ve read işaretiyle kontrol edilen üç durumlu tamponlardan $q_{n-1}, \dots, q_0$ veri çıkışlarına gider.

Read ve write uçları iki biçimde olabilir. 8086'da read ve write iki ayrı aktif 0 uçtur ve ikisi aynı anda aktif olmaz. Bazı mimarilerde ise tek bir R/$\overline{W}$ ucu vardır; örneğin 0 değeri bir işlemi, 1 değeri diğerini seçer. Bu şemada iki ayrı uç kullanılmış ve ikisinin aynı anda aktif olmayacağı varsayılmıştır.

### 4.3 Yazma ve okuma adımları

Bir hafıza gözüne $n$ bitlik değer yazmak için:

1. Adres uçlarına hedef gözün adresi verilir; dekoder o satırı seçer.
2. Veri girişlerine yazılacak değer konur.
3. Write işareti verilir. Aktif 1 seçimli tamponlar açılır ve değer seçili satırdaki hücrelere (bu aşamada D flip-flop'lar gibi düşünülebilir) yazılır.
4. Seçim ve write işareti kaldırılınca değer hücrede saklı kalır.

Aynı adresten okumak için:

1. Aynı adres verilir, aynı satır seçilir.
2. Her sütundaki hücrelerin çıkışları ortak hatta bağlıdır. Dekoder sayesinde aynı anda yalnız bir satır seçilidir; seçilmeyenler yüksek empedans gösterir. Böylece yalnız seçili satırın değerleri çıkış tamponlarının girişine kadar gelir.
3. Read işareti verilince değerler tamponlardan veri çıkışlarına geçer ve dışarıdan okunabilir.

## 5. ROM çeşitleri ve iç yapısı

ROM'un özelliği operasyon sırasında yalnız okuma yönünde çalışmasıdır. Tarihsel gelişimle şu çeşitleri vardır:

- **Maskeli ROM** (masked ROM): üretim sırasında belirli değerlerle ilklendirilir, bir daha değiştirilemez.
- **Bir kez programlanabilen ROM:** programlanmamış üretilir, bir kez programlandıktan sonra değiştirilemez.
- **Elektriksel olarak programlanan, ışıkla silinen ROM:** üzerinde çipin iç yapısının göründüğü bir pencere vardır. Normal uçlar dışındaki programlama uçları şartlanınca programlama moduna geçilir ve ROM'a yazılabilir. Programlama modundan çıkınca operasyon sırasında yazma yapılamaz ve veri enerji kesilse de saklanır. Çip ultraviyole ışıkta belirli bir süre bekletilirse içerik silinir.
- **EEPROM** (E-kare ROM): programlama uçlarıyla elektriksel olarak hem programlanabilir hem silinebilir.

ROM'un blok şemasında adres ($m$), read ve veri çıkışı ($n$) uçları vardır; RAM gibi senkron ya da asenkron olabilir (ekrandan, 00:30:00). Şemadaki eğik çizgili oklar, MUX gösteriminde olduğu gibi, birlikte iş gören $m$ ayrı teli (adres 0'dan adres $m-1$'e) gösterir.

İç yapıda yine bir dekoder ve daha önceden programlanmış bir sigorta yapısı vardır. Dekoder aynı anda yalnız bir satırı seçer, diğerleri hattan kopmuş gibi davranır. Seçilen satırdaki tüm veri gözleri üç durumlu tamponların girişine ulaşır; read işareti verilince veri çıkışlarına ve dış dünyaya iletilir.

## 6. SRAM ve DRAM

RAM'ler statik ve dinamik olarak ikiye ayrılır (ekrandan, 01:35:00):

- **Statik RAM (SRAM):** bilgi latch'lerde (flip-flop) saklanır. Hoca bir flip-flop için en az 6 transistör gerektiğini söyledi.
- **Dinamik RAM (DRAM):** bilgi kapasitörlerde elektrik yükü olarak saklanır. Yük zamanla kaçar ("leaks off"), bu yüzden yükün periyodik olarak tazelenmesi (refresh) gerekir.

DRAM slaydındaki bilgiler şunlardır (ekrandan, 01:50:00): DRAM yüksek kapasiteyi düşük maliyetle sağladığı için yüksek kapasiteli hafıza uygulamalarına hakimdir. Temel ilke bilginin kapasitörlerde saklanmasıdır. DRAM hücresi bir kapasitör C ve bir transistör T'den oluşur. Kapasitörde yeterli yük lojik 1, yetersiz yük lojik 0 demektir. Transistör yükü tutmak ve kapasitörü şarj ya da deşarj etmek için anahtar olarak kullanılır. Slayttaki DRAM hücre modelinde Select ucu hem bir D latch'in C ucunu hem de çıkıştaki üç durumlu tamponu kontrol eder; $B$ girişi D'ye, tampon çıkışı C hattına gider.

Hafıza gözü seçilince transistör açılır ve kapasitör, saklanacak değere göre şarj edilir. Seçim kaldırıldığında yük kapasitörde kalır, yani değer saklanmış olur. Ancak kaçak akımlar (transistördeki küçük kaçaklar dahil) yüzünden yük yavaş yavaş azalır. Kullanılan kapasitörün özelliğine göre lojik 1'in ne kadar sürede lojik 0'a düşeceği hesaplanır ve belirli periyotlarla değerler yeniden yazılır. DRAM'in "dinamik" adı buradan gelir. DRAM hücresi kabaca iki transistör genişliğinde yer kapladığı için DRAM'ler SRAM'lere göre çok daha yoğundur.

Güce bağımlılık açısından da iki tür vardır (ekrandan, 01:35:00): **volatile** (geçici) hafıza güç kesilince bilgiyi kaybeder, **non-volatile** (kalıcı) hafıza güç kesilince bilgiyi korur. ROM'lar kalıcı, RAM'ler geçici hafızaya karşılık gelir.

## 7. Hafıza tanımları

Aradan sonra hafıza temelleri slayt setine geçildi. İlk tanımlar şunlardır (ekrandan, 00:50:00):

- **Hafıza:** depolama hücreleri ile bunlara bilgi aktaran ve bunlardan bilgi alan devrelerin toplamı.
- **Hafıza organizasyonu:** hafızanın, verinin nasıl erişildiğine göre temel mimari yapısı. Bilgisayar mimarisinde veri erişiminin nasıl planlandığı ve tasarlandığıyla ilgilidir.
- **Rastgele erişimli hafıza (RAM):** herhangi bir hücreye (ya da hücre topluluğuna) veri aktarma süresinin seçilen hücreye bağlı olmadığı hafıza.
- **Hafıza adresi:** belirli bir hafıza elemanını (ya da eleman topluluğunu) tanımlayan bit vektörü.

Devamındaki tanımlar şunlardır (ekrandan, 01:00:00):

- **Bit:** tek bir ikili basamak (binary digit'in kısaltması). Hafızada saklanabilen atomik değer 0 ya da 1'dir.
- **Byte:** birlikte erişilen 8 bit.
- **Word:** hafıza için tipik erişim birimi olan bit topluluğu; genelde byte'ın ikinin kuvveti katlarıdır (1, 2, 4, 8 byte vb.).
- **Hafıza verisi:** hafıza hücrelerine yazılacak ya da hücrelerden okunacak bit ya da bit topluluğu.
- **Hafıza işlemleri:** hafıza biriminin desteklediği işlemler; tipik olarak bit, byte, word gibi bir veri elemanı üzerinde okuma ve yazma.

Günümüz bilgisayarlarında ikili lojik elektriksel olarak gerçeklenir: 0 ve 5 V ya da kullanılan MOS yapısına göre 0 ve 3,3 V veya daha düşük seviyeler. Hoca, tüm bilgisayarların ikili mantık kullanmadığını, Sovyetler döneminde üç değerli lojik üzerinde çalışan Setun adlı bir bilgisayarın geliştirildiğini de söyledi.

Mikroişlemci Sistemleri dersinden hatırlatıldığı üzere iki byte bir word (16 bit), iki word bir double word oluşturur; quad word da vardır. Derste **aksi belirtilmedikçe her hafıza gözünün 1 byte (8 bit) olduğu varsayılır.**

Hafıza işlemleri byte ya da word seviyesinde yapılır. Bit seviyesinde işlem desteklemek pratik değildir; bit seviyesindeki bir işlem genelde byte okunup ilgili bit değiştirilerek byte olarak geri yazılmasıyla yapılır.

## 8. Harvard ve von Neumann mimarileri

CPU'da programların çalışabilmesi için bir komut (program) hafızası gerekir; komutlar ayrıca bellekten veri isteyebilir. Program ve veri hafızasının ayrı mı yoksa ortak mı yolları kullandığına göre iki temel mimari vardır.

### 8.1 Harvard mimarisi

CPU'nun veri hafızasına ve program hafızasına ayrı ayrı yollarla eriştiği yapıdır. Veri hafızası için bir veri yolu (data bus), bir adres yolu (address bus) ve bir kontrol yolu; program hafızası için de ayrı bir veri, adres ve kontrol yolu vardır. Dolayısıyla iki ayrı yol takımına ve iki ayrı kontrolcüye ihtiyaç duyulur. Avantajı, dışarıdan çalıştırılan bir programın işletim sistemi ya da kritik programlarla aynı hafızayı kullanmamasıdır; bu güvenlik açısından bir artıdır.

### 8.2 von Neumann mimarisi

CPU'dan tek bir veri yolu, adres yolu ve kontrol yolu çıkar. Program hafızası (örneğin ROM) da veri hafızası da aynı yolları kullanır. Bu durumda komutlar çalışırken birbirinin verisine erişme olasılığı bir güvenlik sorunu oluşturabilir. Tek bir kontrolcüyle yönetilebilir.

Hafıza hiyerarşisiyle birlikte düşünülürse CPU'daki yazmaçlar ön bellekle, ön bellek ana bellekle, ana bellek de ikincil hafızayla konuşur. Harvard mimarisinde bu hiyerarşi hem veri hem program hafızası için ayrı ayrı yürütülmelidir. Ön bellek yalnız veri için değildir; bir **program ön belleği** de vardır. Komutlar hafızadan toplu olarak program ön belleğine getirilir ve oradan tüketilir. Veride de, örneğin bir döngüdeki erişimde, veri ve komşuluğu ön belleğe taşınır.

## 9. Ortak yol, adres çözümleme ve chip select

### 9.1 Neden adres çözümleme gerekir?

von Neumann mimarisinden yola çıkan genel bir sistem blok diyagramında CPU'dan çıkan veri, adres ve kontrol yollarına G/Ç cihazları ve hafıza birimleri (bir kısmı RAM, bir kısmı ROM) bağlıdır; hepsi aynı yolları paylaşır (ekrandan, 00:55:00). CPU aynı anda yalnız biriyle konuşmalıdır. İki cihaz aynı anda veri çıkarırsa, örneğin biri 0 biri 1, elektriksel, lojik ya da veri genişliği seviyesinde çakışma olur.

Bunu önlemek için tasarımda her blok (G/Ç ya da hafıza birimi) belirli bir adres aralığına yerleştirilir. Hoca, bilgisayarın donanım özelliklerinde ya da sürücülerde görülen cihaz adreslerinin bu sabit, ayrılmış adresler olduğunu söyledi; yeni bir hafıza elemanı takılınca alan genişler.

**Adres çözümleme devresi** adres yolundan ve kontrol yolundan bazı işaretleri alır. O an yürütülen komut, örneğin `MOV AX, [100h]`, hangi adrese erişiyorsa ve o adres önceden ayrılmış hangi bloğa düşüyorsa yalnız o bloğu seçen kontrol işaretini üretir. Çıkışlardan aynı anda yalnız biri aktiftir.

> **Hocanın vurgusu:** Sistemdeki her cihazın belirli bir adres aralığı vardır ve adres çözümleme devresi yalnız o aralığa düşen cihazı aktif eder; bu önemli bir noktadır.

### 9.2 Chip select ucu

Hafıza elemanlarının read ve write dışında bir de **chip select (CS)** ucu vardır. Adres çözümleme devresi seçimi bu uç üzerinden yapar. CS aktif 0 ya da aktif 1 olabilir; slayttaki örnekte aktif 1'dir. CS'ye pasif değer gelen elemanın veri çıkışları yüksek empedans gösterir, yani hattan kopmuş gibidir. Adres uçları tüm elemanlara gider ama yalnız seçilen eleman veri yoluna bağlıdır ve verilen read ya da write komutuna göre işlem yapar.

Slayttaki kontrol girişleri şunlardır (ekrandan, 01:20:00):

- **Hafızadan okuma:** adres hatlarına geçerli bir adres koy, okunan verinin kararlı hale gelmesini bekle.
- **Hafızaya yazma:** adres hatlarına geçerli bir adres, veri hatlarına geçerli veri koy; hafıza yazma kontrol hattını değiştir (toggle).
- **Chip select:** seçilecek kelimeyi içeren RAM çipini ya da çiplerini etkinleştirir.

| CS | R/$\overline{W}$ | Hafıza işlemi |
|---|---|---|
| 0 | X | Yok |
| 1 | 0 | Seçili kelimeye yazma |
| 1 | 1 | Seçili kelimeden okuma |

## 10. Mikroişlemciye uygun hafıza arayüzü

Hafıza yapısı kurulurken mikroişlemcinin adres ucu sayısı, veri ucu sayısı ve bir saat çevriminde desteklediği okuma/yazma işlemleri birlikte dikkate alınır.

### 10.1 16 bitlik mimari

16 bitlik bir mimari, mikroişlemcinin 16 veri ucu ve içindeki yazmaçların 16 bit olması demektir. Hocanın örneğindeki 16 bitlik Intel mikroişlemcisinin 20 adres ucu vardır. Adreslenebilen göz sayısı:

$$2^{20} = 2^{10} \cdot 2^{10} = 1\text{K} \cdot 1\text{K} = 1\text{M}$$

Her göz 1 byte olduğundan adreslenebilir kapasite 1 MB'dir (ekrandan, 01:05:00). Bu mikroişlemci tek bir çevrimde şu hafıza işlemlerini destekler:

- tek adresten 8 bit,
- çift adresten 8 bit,
- çift adresten 16 bit.

Hafıza mikroişlemciye $1\text{M} \times 8$ biçiminde bağlanırsa kapasite doğru olur, ama 16 bitlik veri bir seferde alınamaz. $1\text{M} \times 16$ gibi özel bir yapı kurulursa 16 bit okunabilir, fakat 8 bitlik erişimde her satırın yarısı kullanılmaz ve kapasitenin yarısı boşa gidebilir.

Uygun arayüz, bir öğrencinin önerdiği gibi, yan yana iki tane 8 bit genişliğinde blok kullanmaktır. Toplam 1 MB olacağı için her blok 512K gözdür ve yapının toplam biçimi $512\text{K} \times 16$ olur. Bir adres verildiğinde iki bloğun aynı satırı seçilebilmelidir. Bunun için:

- $A_0$ adres çözümleme devresine gitmez; çift ve tek blokları seçmek için kullanılır.
- Çift adresler bir blokta, tek adresler diğerinde durur. $A_0 = 0$ çift bloğu seçer.
- Tek blok için ayrı, aktif 0 bir seçim ucu (bus high enable) kullanılır.

Bu üç işlem şöyle gerçekleşir:

- Çift adresten 16 bit: $A_0 = 0$ ve bus high enable = 0; iki blok birlikte seçilir. $A_0$ çıkarıldığında ardışık iki adres aynı satıra düşer ve 16 bitlik veri çıkar.
- Tek adresten 8 bit: $A_0 = 1$ olduğundan çift blok seçilmez; bus high enable aktif olur ve yalnız tek bloktan veri gelir.
- Çift adresten 8 bit: $A_0 = 0$, bus high enable = 1 (pasif); yalnız çift bloktan veri gelir.

### 10.2 32 bitlik mimari

32 bitlik Intel mimarisinde 32 veri ucu ve 32 adres ucu vardır. Desteklenen kapasite:

$$2^{32} = 2^2 \cdot 2^{10} \cdot 2^{10} \cdot 2^{10} = 4\text{G}$$

Yani 4G göz, her göz 8 bit olduğundan 4 GB. Desteklenen işlemler şunlardır (ekrandan, 01:10:00):

- çift adresten 8 bit,
- tek adresten 8 bit (yani her hafıza gözüne tek tek erişim),
- çift adresten 16 bit,
- 4'ün tam katı adreslerden 32 bit (son iki biti 00, 01, 10, 11 olan ardışık dört adres birlikte).

16 bitlik mimaride iki blok kullanıldığı gibi burada $32/8 = 4$ blok gerekir; her biri 8 bit genişliğindedir. Bloklar tek tek de seçilebilmesi gerektiği için her birinin kendi aktif 0 enable ucu vardır: $E_0, E_1, E_2, E_3$. Mikroişlemci yürütülen komuta bakar:

- Çift adresten 8 bitlik işlemde, verilen adrese göre $E_0$ ya da $E_2$ aktif olur.
- 32 bitlik işlemde $E_0$, $E_1$, $E_2$, $E_3$'ün hepsi aktif olur ve dört bloğun aynı satırı birlikte 32 bit olarak çıkar.

Bu mimarinin görmek istediği hafıza arayüzü kabaca $1\text{G} \times 32$ biçimindedir.

### 10.3 8088

8088'in adres yolu 8086'daki gibi 20 bittir, ama veri yolu 8 bittir. Toplam kapasite 1 MB'dir. İçinde 16 bitlik yazmaçlar vardır, yani 16 bitlik işlem yürütebilir; fakat hafıza arayüzünde 8 veri ucu olduğu için tek adresten ve çift adresten 8 bit okuyabilir. 16 bitlik bir veriyi yazmacına doldurmak için iki okuma yapması gerekir. Bu yüzden 8088'in hafıza arayüzü $1\text{M} \times 8$ biçimindedir.

Slaytta tarihsel örnekler de listelenir (ekrandan, 01:15:00): PDP-8 12 bitlik adresle 4096 tane 12 bitlik kelime; IBM 360 24 bitlik adresle 16.777.216 tane 8 bitlik byte ya da 4.194.304 tane 32 bitlik kelime; Intel 8080 16 bitlik adresle 65.536 tane 8 bitlik byte adresler. Bu değerler $2^{12} = 4096$, $2^{24} = 16.777.216$, $2^{24}/4 = 4.194.304$ ve $2^{16} = 65.536$ ile tutarlıdır.

## 11. Hafızayı lojik fonksiyon olarak kullanmak

Temel bir hafıza bloğunda $n$ veri girişi, $n$ veri çıkışı, $k$ adres ucu ve read/write uçları vardır; kapasitesi $2^k \times n$'dir. Read ve write tek uçta birleşmişse ucun değeri işlemi belirler; ayrı uçlarsa aynı anda aktif olmamaları gerekir, çünkü aynı göze aynı anda okuma ve yazma yapılamaz.

Hafıza bir tablo gibi düşünülebilir: satırlar numaralandırılmıştır, bir adres verildiğinde o satırdaki değer elde edilir. Bu yüzden hafıza bir **lookup table** olarak da kullanılabilir. Örneğin 10 adres ucu ve 16 bitlik çıkışı olan bir hafızada çıkışın her biti (15 numaralı bit, 14 numaralı bit, ...) 10 girişli ayrı bir lojik fonksiyona karşılık gelir; yani bu hafıza 10 girişli 16 farklı fonksiyonu gerçekler.

Bu özellik FPGA tasarımlarında kullanılır: bazı fonksiyonlar lookup table olarak hafıza elemanıyla gerçeklenir. Çok katlı kapılardan oluşan bir tasarımda gecikmeler dikkate alınarak, hafıza elemanı kullanmak hem süre hem tasarım karmaşıklığı açısından daha pratik olabilir; tasarımcı bu ödünleşimi değerlendirir.

## 12. Erişim süresi, yazma süresi ve hafıza çevrimleri

### 12.1 Okuma ve yazma süreleri farklı modellenir

Okumada mevcut verinin birkaç kontrol kapısından geçip dışarı aktarılması yeterlidir; yazmada ek işlemler vardır. Bu yüzden **erişim süresi** (okuma) ve **yazma süresi** ayrı verilir ve farklı olabilir.

Slayttaki örnekte bir hafıza çevrimi her biri 20 ns olan dört darbeden (T1, T2, T3, T4) oluşur; yazma çevrimi 75 ns, okuma çevrimi 65 ns olarak gösterilir (ekrandan, 01:25:00). Bu fark, okuma ve yazmanın senkron bir saat işaretiyle kontrol edildiği durumda önemlidir: okuma daha kısa sürse bile bütün işlemler aynı periyotta yapılacağı için saat periyodu 75 ns'nin üzerinde olmak zorundadır. Yani hafızanın yazma süresi tasarımın saat frekansını etkiler. Hoca bu çevrimlerin 8086'lı bir mikroişlemci sistemine ait olduğunu söyledi.

### 12.2 Yazma çevrimi

> **Hocanın vurgusu:** Okuma ve yazma çevrimleri hep mikroişlemci açısından tanımlanır; yazma çevrimi mikroişlemcinin hafızaya yazmasıdır. Bu önemli bir noktadır. Dalga şekillerine göre (ekrandan, 01:25:00):

1. Mikroişlemci erişilecek gözün adresini adres hatlarına koyar; adres T1'den T4'ün sonuna kadar geçerlidir.
2. Hafıza elemanı için chip select (slaytta "memory enable") üretilir. Bunu büyük olasılıkla CPU değil adres çözümleme devresi üretir.
3. Mikroişlemci veriyi hazırlar; veri girişi T2'den itibaren geçerlidir.
4. R/W hattı sıfıra çekilerek yazma komutu verilir ve T4'e kadar bu seviyede kalır.

Hafıza yazma işaretini örneklediğinde veri hatlarında geçerli verinin hazır olması gerekir; bu veriyi mikroişlemci koyar. Karşı taraftan yazmanın tamamlandığına dair bir onay (handshaking) olmadığından, adres ve veri yeterince uzun süre hatta stabil tutulur ve yazmanın gerçekleştiği varsayılır.

### 12.3 Okuma çevrimi

1. Mikroişlemci okumak istediği adresi koyar; adres dört saat çevrimi boyunca stabil kalmalıdır.
2. Adres çözümleme devresi hafıza için chip select üretir.
3. R/W hattı bir değerinde kalır (okuma).
4. Hafızanın veriyi ne kadar sürede çıkaracağı tasarım gereği bilinir. Geçerli veri T4 içinde çıkar ve T4'ün düşen kenarında veri hatları örneklenerek okunur.

Bu yapıda bir okuma ya da yazma çevrimi birden fazla saat darbesiyle kontrol edilir.

## 13. Tek çevrim, çok çevrim ve boru hattı

Hafıza çevriminin birden fazla saat darbesi sürmesi, hocanın işlemci mimarileri hakkında genel bir açıklama yapmasına yol açtı. Derste tek çevrimli bilgisayar (CPU) tasarımı görülecektir; orada bir saat darbesinde bir komut yürütülür.

Bir komutun yürütülmesi alt bloklara ayrılabilir: komutun getirilmesi (instruction fetch), çözülmesi (decode), gerekirse hafızadan operand getirilmesi (operand fetch), yürütme (execute) ve sonucun geri yazılması (write back). Tek çevrimli mimaride bu bloklar sıralı bağlıdır; bir blok çalışırken diğerleri boşta bekler ve komut beş bloktan sırayla geçer.

Hocanın "multicycle" başlığı altında anlattığı yapıda ise her blok belirli bir anda farklı bir komutun ilgili kısmını işler. Örneğin boru hattı boşken $t = 1$'de bir `add` komutu getirilir; $t = 2$'de `add` çözülürken getirme bloğu boşta beklemesin diye kuyruktaki ikinci komut (örneğin bir hafıza okuma komutu) getirilir; $t = 3$'te `add` operand getirmeye, ikinci komut çözmeye geçer ve üçüncü komut getirilir. Komutlar komut hafızasından tek tek değil, toplu olarak CPU içindeki bir **komut kuyruğuna** alınır, çünkü yürüttükçe tek tek okumak masraflıdır.

> **Ders sonrası not:** Hoca bu örtüşmeli yürütmeyi "multicycle" mimari başlığı altında anlattı ve "pipeline" ile aynı bağlamda kullandı. Yaygın terminolojide çok çevrimli (multi-cycle) işlemci, bir komutu birkaç saat çevriminde yürüten ama komutları örtüştürmeyen tasarımdır; anlatılan örtüşmeli yapı ise büyük olasılıkla boru hattı (pipeline) olarak adlandırılır.

Boru hattından yüksek performans beklenir, ama veri bağımlılıkları, yapısal bağımlılıklar ve dallanma komutları yüzünden her zaman verimli kullanılamaz:

- **Dallanma:** Koşul sağlanırsa uzaktaki bir komuta atlanır, sağlanmazsa hemen alttaki komut yürütülür. Boru hattında dallanma komutu işlenirken onun altındaki komutlar da sonraki bloklarda işlenmeye başlanır. Dallanma gerçekleşirse bu işlemler çöpe gider ve atılmalıdır. Ya bu durumda boru hattı durdurulup sıralı yürütmeye geçilir (performans düşer) ya da **dallanma tahmini** yapılır.
- **Veri bağımlılığı:** Örneğin birinci komut $A \leftarrow A + B$, ikinci komut $A \leftarrow A / 2$ ise, ikinci komut birincinin sonucunu beklemek zorundadır; güncel olmayan $A$'yı işlemek anlamsızdır. Bu sırada veri bağımlılığı olmayan komutlar öne alınıp yürütülebilir.

Hocanın verdiği Intel örneğinde bir hafıza çevrimi 4 saat darbesi (T1–T4) sürer; adresin, kontrol işaretlerinin ve verinin hatta konması bu darbelere dağıtılır, hepsi aynı anda yapılmaz.

## 14. RAM hücresinden RAM entegresine

### 14.1 SRAM hücresi

Statik RAM hücresi bir SR latch ile modellenir. Hücrede saklanacak bit $B$ ve değili $\overline{B}$ simetrik olarak kullanılır; **Select** ucu hücrenin seçim (adres) ucudur. Hocanın anlatımına göre yazmada, örneğin 1 yazılacaksa, veri girişi 1 olur, yazma için read ucu 0 tutulur ve ilgili satır seçilir; kapı çıkışları sonucunda latch'in S ucuna 1, R ucuna 0 gelir ve hücreye 1 yazılır. Okumada read ucu 1 olur; S ve R uçlarına 0, 0 gelir ve latch içindeki değeri korur. Seçilen hücrenin değeri çıkış latch'i üzerinden dışarı aktarılır, seçilmeyenlerinki aktarılmaz.

<!-- BELİRSİZ: SRAM hücresinin ve bit slice'ın kapı düzeyindeki bağlantıları (01:36–01:39) yalnız altyazıdan aktarıldı; ilgili slaytların karesi yok. Kapı yerleşimi ve "read" ucunun yazma sırasındaki değeri slayttan doğrulanamadı. -->

Hücreler alt alta dizilerek $2^n \times 1$ bitlik bir RAM sütunu (bit slice) kurulur. Her satırı ayrı seçebilmek için $2^n$ tane **word select** ucu gerekir; bunlar hücrelerin Select uçlarına bağlanır. Kara kutu olarak bakıldığında bu blokta $2^n$ seçim ucu, 1 bit veri girişi, 1 bit veri çıkışı, bloğu seçen bir seçim ucu ve okuma/yazma kontrol ucu vardır.

### 14.2 $2^n$ kelime $\times$ 1 bit RAM entegresi

Slayta göre bir RAM dilimiyle RAM entegresi kurmak için şunlar gerekir (ekrandan, 01:40:00):

- **Dekoder:** $n$ adres hattını $2^n$ word select hattına çevirir.
- Çıkışta bir **üç durumlu tampon:** birden çok RAM entegresinin birleştirilip $c \times 2^n$ kelimelik bir RAM oluşturulmasına izin verir.

Slayttaki örnek $16 \times 1$ RAM'dir: $A_3$–$A_0$ adres uçları bir 4'ten 16'ya dekodere girer, dekoderin 0–15 çıkışları RAM hücrelerinin word select hatlarını sürer. Veri girişi, Read/Write ve Chip select read/write lojiğine gider; veri çıkışı chip select ile kontrol edilen tampondan geçer. Okumada hücreler durumlarını korur ve adrese göre seçili olanın değeri veri çıkışına gelir. Çip seçilmişse veri dışarı gider, seçilmemişse tampon hattı koparır.

### 14.3 Adresi iki zamanda göndermek

$n$ adres ucu ile $2^n$ göz adreslenebilir. Aynı sütun yapısı $N$ kez tekrarlanırsa $2^n \times N$ bitlik çıkış elde edilir, ama yine yalnız $2^n$ satır seçilir. Bunu iyileştirmek için seçim iki ayrı zamana bölünebilir: ilk gönderilen $n$ bitlik adres bir satırı, ikinci gönderilen $n$ bitlik adres bir sütunu seçer; ikisinin kesiştiği nokta istenen hafıza gözüdür. Bu yapı derinlemesine $M$ kez tekrarlanırsa aynı anda $M$ bitlik veri erişilir. Böylece aynı $n$ adres ucuyla

$$2^n \times 2^n \times M$$

bitlik bir kapasiteye erişilmiş olur. Bu, adres değerlerinin zaman çoğullamasıyla sağlanır.

Adres bitlerinin yarısı satıra, yarısı sütuna **aynı anda** verilseydi $2^{n/2}$ satırdan biri ve $2^{n/2}$ sütundan biri seçilirdi; çarpım yine $2^{n/2} \cdot 2^{n/2} = 2^n$ olurdu. Yani aynı anda verildiğinde ikiye bölmenin kapasite açısından bir farkı yoktur.

> **Ek bilgi (derste anlatılmadı):** Adresin satır ve sütun olarak iki zamanda gönderilmesi DRAM entegrelerinde yaygındır; satır adresi RAS, sütun adresi CAS işaretiyle alınır. Böylece entegrenin adres ucu sayısı yarıya iner.

## 15. Kapasite ve veri yolu genişletme

### 15.1 Kapasite genişletme: $256\text{K} \times 8$

Elimizde $64\text{K} \times 8$ RAM'ler olsun. Her birinin 8 veri ucu, $64\text{K} = 2^6 \cdot 2^{10} = 2^{16}$ olduğu için 16 adres ucu, bir chip select ve bir R/W ucu vardır. Bunlarla $256\text{K} \times 8$ bir hafıza kurulacaktır. Veri genişliği aynıdır, kapasite büyür.

- Gereken entegre sayısı: $256\text{K} / 64\text{K} = 4$.
- $256\text{K} = 2^{18}$ olduğundan büyük hafızanın adresi 18 bittir. Entegrelerde 16 adres ucu olduğundan iki uç fazladır.
- Düşük anlamlı 16 adres biti (hat 0–15) dört entegreye ortak gider.
- En yüksek anlamlı 2 bit (hat 17 ve 16) bir 2'den 4'e dekoderin girişine verilir; dekoderin enable ucuna memory enable bağlanır. Dekoder çıkışları entegrelerin CS uçlarını sürer.
- R/W dört entegreye ortak gider.

Slayta göre entegrelerin adres aralıkları şöyledir (ekrandan, 01:45:00):

| En yüksek 2 bit | Entegre | Adres aralığı |
|---|---|---|
| 00 | 1 | 0 – 65.535 |
| 01 | 2 | 65.536 – 131.071 |
| 10 | 3 | 131.072 – 196.607 |
| 11 | 4 | 196.608 – 262.143 |

Dekoder kullanmanın avantajı, entegrelerden aynı anda yalnız birinin aktif olmasıdır. Her entegreye aynı 16 bitlik adres gider, ama yüksek anlamlı 2 bite göre yalnız biri seçilir. 8 bitlik tek bir çıkış gerektiği için tüm entegrelerin veri uçları ortaklanır: her entegrenin 0 numaralı veri ucu birbirine, 1 numaralıları birbirine bağlanır ve toplam 8 uç oluşur. Aynı anda yalnız bir entegre aktif olduğundan çakışma olmaz; dışarıda yalnız seçili entegrenin ilgili satırındaki 8 bit görülür.

### 15.2 Veri yolu genişletme: $64\text{K} \times 16$

Bu kez $64\text{K} \times 8$ entegrelerle $64\text{K} \times 16$ kurulacaktır. Kapasite (kelime sayısı) aynıdır, iki tarafın da 16 bitlik adresi vardır. Gereken entegre sayısı:

$$\frac{64\text{K} \times 16}{64\text{K} \times 8} = 2$$

Kapasitede genişleme yok, veri yolu iki kat genişliyor. 16 adres ucu iki entegreye ortak gider. Bir entegre veri yolunun yüksek anlamlı 8 bitini, diğeri düşük anlamlı 8 bitini taşır; girişte ve çıkışta yan yana durarak 16 bitlik veri oluştururlar. Bir satırdan veri okunurken ya da yazılırken öteki entegrede de aynı satırın erişilmesi gerektiği için iki entegre **aynı anda** seçilmelidir: R/W ve CS işaretleri ikisine ortak gider.

### 15.3 İkisini birlikte: $256\text{K} \times 16$

Hoca karşılaştırma için önceki örneği aynı oranla yeniden yazdı: $256\text{K} \times 8 / 64\text{K} \times 8$ işleminde veri genişliği yönünde katkı yoktur, kapasite yönünde 4 kat vardır; bu yüzden 4 entegre kapasite yönünde kullanılır. $256\text{K} \times 16$ bir hafıza $64\text{K} \times 8$ entegrelerle kurulmak istense veri genişletme yönünde 2, kapasite genişletme yönünde 4 kat gerekir:

$$\frac{256\text{K} \times 16}{64\text{K} \times 8} = 4 \times 2 = 8$$

Yani 8 entegre, 4 satır ve 2 sütun biçiminde yerleştirilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:44): $32 \times 8$ bitlik bir RAM'in kaç veri ucu ve kaç adres ucu vardır?

> **Çözüm (derste verildi):** Her göz 8 bit olduğundan 8 veri ucu vardır. 32 gözü seçmek için dekoderin $\log_2 32 = 5$ girişi, yani 5 adres ucu gerekir. Slaytta da "adres 5 bit, veri 8 bit: $32 \times 8$ bit RAM" yazar (ekrandan, 00:25:00).

**Soru 2** (derste sözlü, 01:01:31): 16 bitlik, 20 adres ucu olan bir mikroişlemci kaç hafıza gözü ve ne kadar kapasite adresleyebilir?

> **Çözüm (derste verildi):** $2^{20} = 2^{10} \cdot 2^{10} = 1\text{M}$ göz. Her göz 1 byte olduğundan 1 MB (ekrandan, 01:05:00).

**Soru 3** (derste sözlü, 01:03:34): Bu 16 bitlik mikroişlemci tek çevrimde tek adresten 8 bit, çift adresten 8 bit ve çift adresten 16 bit okuyabiliyorsa hafıza $1\text{M} \times 8$ olarak bağlanırsa hangi işlemde sorun çıkar? Uygun arayüz nedir?

> **Çözüm (derste verildi):** $1\text{M} \times 8$ arayüzde 16 bitlik veri bir seferde alınamaz. $1\text{M} \times 16$ ise 8 bitlik erişimde satırların yarısını boşa harcar. Uygun arayüz, bir öğrencinin dediği gibi yan yana iki 8 bit genişliğinde bloktur: toplam $512\text{K} \times 16$. $A_0 = 0$ çift bloğu, aktif 0 bir bus high enable ucu tek bloğu seçer; 16 bitlik çift adres erişiminde ikisi birlikte seçilir.

**Soru 4** (derste sözlü, 01:10:25): 32 veri ve 32 adres ucu olan bir mikroişlemcinin desteklediği kapasite nedir? Her göze tek tek, çift adreslerden 16 bit ve 4'ün katı adreslerden 32 bit erişim desteklendiğine göre 4 GB hafıza nasıl bağlanmalıdır?

> **Çözüm (derste verildi):** $2^{32} = 4\text{G}$ göz, yani 4 GB. $32/8 = 4$ tane 8 bit genişliğinde blok kullanılır; her birinin kendi aktif 0 enable ucu ($E_0$–$E_3$) vardır. Arayüz kabaca $1\text{G} \times 32$'dir.

**Soru 5** (derste sözlü, 01:12:14): Bu 32 bitlik arayüzde çift adresten 8 bitlik bir işlem yürütülürken hangi enable uçları aktif olabilir? 32 bitlik işlemde hangileri?

> **Çözüm (derste verildi):** Çift adresten 8 bitte, verilen adrese göre $E_0$ ya da $E_2$. 32 bitlik işlemde $E_0$, $E_1$, $E_2$, $E_3$'ün hepsi.

**Soru 6** (derste sözlü, 01:13:55): 8 veri ucu ve 20 adres ucu olan, içinde 16 bitlik yazmaçlar bulunan 8088 hafıza arayüzünü nasıl görmek ister?

> **Çözüm (derste verildi):** Kapasite 1 MB'dir ve 8 veri ucu olduğu için yalnız tek ya da çift adresten 8 bit okuyabilir; 16 bitlik veriyi iki okumayla alır. Arayüz $1\text{M} \times 8$'dir.

**Soru 7** (ekrandan, 01:45:00): Dört tane $64\text{K} \times 8$ RAM entegresiyle $256\text{K} \times 8$ RAM kurunuz.

> **Çözüm (derste verildi):** $256\text{K}/64\text{K} = 4$ entegre. 18 bitlik adresin düşük 16 biti dört entegreye ortak, en yüksek 2 biti (17, 16) 2'den 4'e dekodere gider ve dekoder çıkışları CS uçlarını sürer. Veri uçları ve R/W ortaktır. Adres aralıkları 0–65.535, 65.536–131.071, 131.072–196.607, 196.608–262.143'tür.

**Soru 8** (derste sözlü, 01:47:13): $64\text{K} \times 8$ entegrelerle $64\text{K} \times 16$ hafıza kaç entegreyle ve nasıl kurulur?

> **Çözüm (derste verildi):** $(64\text{K} \times 16)/(64\text{K} \times 8) = 2$ entegre. 16 adres ucu, R/W ve CS ikisine ortak gider; biri yüksek, diğeri düşük anlamlı 8 bit veriyi taşır.

**Soru 9** (derste sözlü, 01:48:14): $256\text{K} \times 16$ bir hafıza $64\text{K} \times 8$ entegrelerle kurulmak istense kaç entegre gerekir?

> **Çözüm (derste verildi):** Veri genişletme yönünde 2, kapasite genişletme yönünde 4 kat: $4 \times 2 = 8$ entegre, 4 satır ve 2 sütun.

## Dersin Toparlaması

Bu derste hafıza elemanları hiyerarşiden başlayarak ele alındı. Yazmaç, ön bellek, bellek ve ikincil hafıza arasında hız, kapasite ve maliyet dengesi; uzamsal ve zamansal yerelliğin ön belleği neden etkili kıldığı; bellek ile ikincil hafıza arasındaki sayfa ilişkisi anlatıldı. ROM ve RAM'in kullanım yerleri, blok ve iç yapıları, ROM çeşitleri, SRAM ve DRAM hücreleri ve volatile/non-volatile ayrımı görüldü. Harvard ve von Neumann mimarileri karşılaştırıldı; ortak yolda aynı anda tek cihazın konuşmasını sağlayan adres çözümleme ve chip select mantığı kuruldu.

İkinci yarıda mikroişlemcinin adres ve veri ucu sayısıyla tek çevrimde desteklediği erişimlere göre uygun hafıza arayüzünün nasıl seçileceği 16 bitlik, 32 bitlik mimariler ve 8088 üzerinden çalışıldı. Okuma ve yazma sürelerinin farklılığı ve T1–T4 hafıza çevrimleri, tek çevrimli tasarımla boru hattı arasındaki fark ve boru hattını bozan dallanma ve veri bağımlılıkları, RAM hücresinden dekoder ve üç durumlu tamponla RAM entegresi kurulması ve son olarak kapasite ile veri yolu genişletme işlendi. Sonraki derste beşinci hafta slaytlarıyla devam edilecek; derste ilerde tek çevrimli CPU tasarımı görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
