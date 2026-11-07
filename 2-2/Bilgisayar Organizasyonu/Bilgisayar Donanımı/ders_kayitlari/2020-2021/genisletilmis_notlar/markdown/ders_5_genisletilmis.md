# Ders 5 Genişletilmiş Notu: PAL, RAM Türleri, Bellek Organizasyonu, Çakışık Seçim ve Bellek Genişletme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Programlanabilir Lojik Cihazlara Dönüş: PLA Tekrarı
- 2. PAL (Programmable Array Logic)
- 3. RAM Türleri: Statik ve Dinamik RAM
- 4. Bellek Tanımları ve Bellek Organizasyonu
- 5. Bellek İşlemleri ve Kontrol Girişleri
- 6. Tazeleme ve Uçuculuk
- 7. Statik RAM Hücresi
- 8. RAM Bit Dilimi ve 16×1 RAM
- 9. Çakışık Seçim (Coincident Selection)
- 10. RAM Çipine Dışarıdan Bakış ve Üç Durumlu Çıkış
- 11. Kapasite Gösterimi ve Adres Ucu Hesapları
- 12. Boyuna Uzatma: 64K×8 Çiplerle 256K×8
- 13. Enine Genişletme: 64K×8 Çiplerle 64K×16
- 14. Örnek: 128K×16 Çiplerle 2 MB
- 15. Örnek: 64K×8 Çiplerle 512K×16

## 1. Programlanabilir Lojik Cihazlara Dönüş: PLA Tekrarı

Hoca derse, geçen hafta başlanan programlanabilir lojik cihazlar konusunun bir bölümünün yetişmediğini söyleyerek başladı. Bir öğrenci, ROM'u anladığını ama PLA konusunda kısa bir giriş istediğini belirtince önce PLA tekrar edildi, sonra PAL'e geçildi.

### 1.1 Üç Tür Cihaz

Programlanabilir lojik cihazlar, programlanabilir dizilerin bulunduğu bölgeye göre üç türe ayrılır. Üçünün de yapısında başta bir AND dizisi (AND array), sonda bir OR dizisi (OR array) vardır. Farkı yaratan, önlerindeki switch'lerden hangilerinin programlanabildiğidir.

| Cihaz | AND kapılarının önü | OR kapılarının önü |
| :--- | :--- | :--- |
| ROM | Sabit | Programlanabilir |
| PLA | Programlanabilir | Programlanabilir |
| PAL | Programlanabilir | Sabit |

ROM'da OR kapılarının önündeki bağlantılar, ROM tablosuna yazılacak değere göre seçilir.

**Soru:** PLA'da girişte de programlama var, yani adres kısmı da mı programlanabiliyor? **Cevap:** Evet, AND kapılarının önü de programlanabilir. Ama artık buna adres diye bakmıyoruz.

### 1.2 PLA'da Ortak Terim Aramak

Geçen haftaki örnekte iki çıkışlı bir fonksiyon, yani $F_1$ ve $F_2$ gerçekleştiriliyordu. Bu yüzden 4 AND kapılı ve 2 OR çıkışlı bir PLA seçilmişti. PLA tasarımında amaç, işi olabildiğince az AND kapısıyla yapmaktır. Bunun yolu, iki fonksiyon arasında olabildiğince çok ortak terim bulmaktır.

Bu örnekte $F_1$ ile $F_2$ arasında $AC$ ortak terimi vardı. Bu sayede toplam 4 terim, yani 4 AND kapısı yetti. Bu eşleşme olmasaydı 5 AND kapısı gerekecekti. AND kapılarının önündeki switch dizisi, hangi girişin hangi AND işlemine katılacağını seçer.

<!-- BELİRSİZ: F1 ve F2'nin tam denklemleri slaytta kalmış, altyazıda yalnız AC ortak terimi söyleniyor. -->

### 1.3 İkinci Örnek: Tümleyenleri de Denemek

Kitaptan alınan ikinci örnekte yine iki fonksiyon verilmişti. Fonksiyonlar Karnaugh haritasına taşınır ve yalnız kendileri değil tümleyenleri (komplement) de yazılır. Çünkü önceki işlemde ortak terim, $F_2$'nin tümleyeni alınınca ortaya çıkmıştı. Ayrıca $F_2$'nin hiç indirgenmemiş biçimi de yazılır. Sonra bu biçimlerin hangi birleşiminin daha çok ortak terim verdiğine bakılır.

Çözümde $F_1$'in tümleyeni ile $F_2$'nin indirgenmemiş biçimi kullanılmış, böylece ortak terim yakalanmış ve devre 4 AND kapısıyla gerçekleştirilmiştir. Hocanın benzer alıştırmalar için önerdiği yol da aynıdır: İki fonksiyonu ve tümleyenlerini ayrı ayrı yazın, gerekirse indirgenmemiş biçimlerini de yazın, sonra daha az AND kapısı veren birleşimi seçin.

<!-- BELİRSİZ: İkinci örneğin fonksiyonları ve ortak terimleri slaytta kalmış. Altyazıda ortak terim sayısı "bir iki tane" diye geçiyor. -->

AND kapısının kaç girişli olduğu önemli değildir. Örnekteki AND kapılarının aslında 6 girişi vardır: $A, B, C$ ve bunların tümleyenleri. Tasarımcı yalnız hangi girişi kullanacağına karar verir ve o switch'leri kapalı duruma getirir.

### 1.4 PLA'nın Avantajı

**Soru:** Bunun ne avantajı var? **Cevap:** ROM'u belli, sabit bir veriyi depolamak için kullanırız ve çok daha karmaşık bir yapıdır. Yalnız iki fonksiyonu gerçeklemek için ROM kullanmak çok verimli değildir. PLA, gereken fonksiyonları en az maliyetle nasıl gerçekleyeceğimizi bulmamızı sağlar. Bu tür yapılar çok büyük hacimli üretimlerde kullanılabilir ve farklı ihtiyaçlara göre tercih edilebilir.

## 2. PAL (Programmable Array Logic)

### 2.1 Yapı

PAL, ROM'un tam tersi çalışır. ROM'da AND kapılarının önü sabitti. PAL'de AND kapılarının önü programlanabilir, OR kapılarının önü sabittir.

Slayttaki yapı dört girişlidir: $A, B, C, D$. Her giriş tersleyen bir tampondan (inverting buffer) geçer. Böylece hem $A$ hem $A'$ üretilir, diğer girişler için de aynısı yapılır. Elimizde bütün girişler ve tümleyenleri hazırdır. Bunların önünde programlanabilir switch'ler bulunan AND kapıları vardır. Belli sayıda AND kapısı da sabit bir OR kapısıyla birleştirilmiştir.

Bu yapıdaki her OR kapısı en fazla 3 çarpım terimi (product term) toplayabilir. Bir fonksiyonda 3'ten fazla terim varsa çözüm, bir OR kapısının çıkışını sisteme yeniden giriş olarak vermektir.

### 2.2 Örnek: W, X, Y, Z Fonksiyonları

Dört fonksiyon, yani $W, X, Y, Z$ gerçekleştirilmek isteniyor. Girişler $A, B, C, D$'dir. Verilen mintermlerden indirgenmiş fonksiyonlar yazılmıştır. $Z$'nin indirgenmiş biçimi dört terimlidir, ama OR kapıları 3 girişlidir. Sorun buradadır.

$W$ iki terimlidir:

$$W = ABC' + A'B'CD'$$

Devrede birinci AND kapısı $A$, $B$ ve $C'$ girişlerini, ikinci AND kapısı $A'$, $B'$, $C$ ve $D'$ girişlerini alır. Böylece iki terim iki AND kapısıyla elde edilir.

<!-- BELİRSİZ: Slayttaki minterm listesi ile X ve Y denklemleri altyazıda okunmuyor. Burada yalnız W ve Z yazıldı. -->

### 2.3 Kullanılmayan AND Kapısı

OR kapısı 3 girişli, $W$ ise iki terimlidir. Geriye kullanılmayan bir AND kapısı kalır. Slaytta bu kapının ortasına tek bir çarpı işareti konmuştur. Bu işaret, bütün switch'lerin kapalı olduğunu gösterir. Her bağlantının üstüne ayrı ayrı çarpı atmak yerine kullanılır.

Hoca burada derste bir soru sordu: Bütün switch'leri kapalı bir AND kapısının çıkışı ne olur? Cevap 0'dır. Çünkü kapının girişinde hem $A$ hem $A'$ vardır. Biri 1 ise öteki 0'dır, dolayısıyla:

$$A \cdot A' = 0$$

Bu 0, OR kapısının bir girişine gider. Sistemin çalışmasını bozmaz, etkisiz bir giriş olur.

### 2.4 Z Fonksiyonu ve Geri Besleme

$Z$'nin dört çarpım teriminden ikisi $W$ ile aynıdır. $W$ zaten üretildiği için onu yeniden kurmaya gerek yoktur. $W$ çıkışı tersleyen bir tamponla sisteme giriş olarak bağlanır. Böylece $W$ ve $W'$ de birer giriş gibi kullanılabilir. $Z$'nin bulunduğu en alttaki bölümde bir AND kapısı yalnız $W$'yi alıp OR kapısına iletir, diğer iki AND kapısı kalan terimleri üretir:

$$Z = ABC' + A'B'CD' + AC'D' + A'B'C'D = W + AC'D' + A'B'C'D$$

Dört terim böylece 3 girişli OR kapısına sığar. İki yazımın aynı fonksiyon olduğu doğruluk tablosuyla denetlendi. Her iki yazım da $Z = 1$ sonucunu aynı satırlarda, yani $ABCD$ değerleri 1, 2, 8, 12 ve 13 iken verir (ara adım eklendi). Benzer biçimde $W = 1$ sonucu 2, 12 ve 13 için çıkar (ara adım eklendi). Hesap, $Z$'nin dört çarpım teriminden daha azıyla yazılamadığını da gösterir (ara adım eklendi).

<!-- BELİRSİZ: Hocanın Z'nin üçüncü terimini okuyuşu altyazıda karışık ("A, C değil, D değil, C değil, D değil"). AC'D' biçimi kısa notla aynıdır, slayt görülmedi. -->

Böylece programlanabilir lojik cihazların üç çözümü de görülmüş oldu.

## 3. RAM Türleri: Statik ve Dinamik RAM

Bu haftanın asıl konu başlığı bellek temelleridir (Memory Basics). Ağırlık rastgele erişimli bellekte (Random Access Memory), bunun çeşitlerinde ve kapasitenin nasıl artırılacağındadır.

RAM'in iki çeşidi vardır: statik RAM (SRAM) ve dinamik RAM (DRAM).

| Özellik | Statik RAM | Dinamik RAM |
| :--- | :--- | :--- |
| Yapı taşı | SR latch | Kapasitör |
| Maliyet | Pahalı, DRAM entegresinin neredeyse 10 katı | Belirgin biçimde ucuz |
| Kullanım | Küçük kapasitede, yalnız önbellek (cache) | Standart RAM bellek |

Hoca SRAM için önce "flip-floplarla" dedi, ardından "daha doğrusu latch ile" diye netleştirdi. Kapasitör teknolojisi daha ucuz olduğu için DRAM daha ucuzdur. SRAM ise pahalı olduğu için sistemde küçük kapasitede kullanılabilir. Küçük kapasitenin kullanıldığı yer de önbellektir. "RAM bellek" dediğimizde aklımıza ilk gelen yapı dinamik RAM'dir.

## 4. Bellek Tanımları ve Bellek Organizasyonu

### 4.1 Bellek Nedir?

Slayttaki tanım şöyledir: Bellek, depolama hücrelerinin ve bu hücrelere bilgi aktaran, onlardan bilgi alan gerekli devrelerin bir araya gelmiş hâlidir (a collection of storage cells together with the necessary circuit to transfer information to and from them). Önce tek bir hücreden söz edilir, sonra hücrelerin bir araya getirildiği daha büyük yapılardan.

Oluşan bellek alanının bir de organizasyonu gerekir. Bellek organizasyonu şu soruların cevabıdır: Kapasite ne kadar? Bellek kaç satırda adreslenmiş? Her satırda kaç bit ya da kaç bayt tutulabiliyor? Yapıyı genişletmek gerekince enine ve boyuna büyütme nasıl yapılır?

Bu derste ele alınan RAM uçucu (volatile) bir yapıdır. Üzerinde enerji olduğu sürece veriyi tutar.

Bellekte adreslenebilen satırlar vardır ve her satırda bir veri bulunur. Bu veri 1 bit, 1 bayt (8 bit) ya da bir kelime (word) olabilir.

### 4.2 Bütün Bellek İşlemlerini CPU Yapar

Bellek üzerinde yapılan bütün işlemler CPU tarafından yapılır. Sistemin yöneticisi merkezi işlem birimidir. Okuma ve yazmanın yönü şöyledir:

- **Okuma:** Bellekte kayıtlı bir verinin CPU içindeki bir register'a taşınmasıdır.
- **Yazma:** CPU register'ındaki bir verinin RAM'de belli bir adrese kaydedilmesidir.

Assembly dersinden bilindiği gibi, yazdığımız `move` komutuyla bellekte belli bir adrese yazma ya da oradan okuma yapılır. Gereken işlem CPU'nun gönderdiği komutla gerçekleşir.

### 4.3 Örnek Mimariler

Bellek adresi, bellekteki ilgili satırı gösterir ve seçer. O adreste tutulan verinin büyüklüğü, yani kelime genişliği, mimariye göre değişir. Hoca slayttaki mimarilerin eski olduğunu, önemli olanın adres ile bir gözde tutulan veri büyüklüğü arasındaki ayrım olduğunu söyledi.

| Mimari | Adres biti | Satır sayısı | Bir satırdaki veri |
| :--- | :---: | :--- | :--- |
| PDP-8 | 12 | $2^{12} = 4096$ | 12 bit |
| IBM 360 | 24 | $2^{24}$, yani 16 M | 8 bit (bayt) |
| Intel 8080 | 16 | $2^{16} = 65536$ | 8 bit |

Hoca PDP-8'deki 12 bitlik verinin sıra dışı, çok standart olmayan bir büyüklük olduğunu belirtti. IBM 360'ta 24 bitlik adres yolu 16 milyon farklı adresi gösterir. İşlemcinin veri yolu 8 değil de 32 bit ise toplam kapasite farklı yazılabilir: 16 M bayt, $4\text{M} \times 32$ bit olarak da ifade edilir.

> **Ders sonrası not:** Hoca burada "4 milyon byte, 4 milyon çarpı 32 bit" dedi. Doğrusu 4 M kelime ve her kelime 32 bittir. Toplam yine $4\text{M} \times 4$ bayt $= 16$ M bayttır. "16 milyon" da yuvarlak söyleyiştir: $2^{24} = 16.777.216$, yani tam olarak $16 \times 2^{20}$.

### 4.4 Bellek Blok Diyagramı

RAM'de okuma ve yazma kontrol uçları ile adres girişleri bulunmalıdır. Blok diyagramında $k$ adres hattı ve kelime başına $n$ bit için kapasite şöyle tarif edilir:

$$2^k \times n$$

$k$ adres ucu $2^k$ satır, yani $2^k$ kelime demektir. Her kelimenin kaç bit olduğu da ayrıca belirtilmelidir. Burada $n$ bit, veri giriş ve veri çıkış uçlarının sayısıdır.

### 4.5 Örnek: 10 Adres Biti, 16 Veri Biti

**Verilen:** Bir bellek modülü 10 adres bitiyle adresleniyor, 16 veri biti var. Yani $k = 10$, $n = 16$.

**İşlem:** 10 adres ucuyla $2^{10} = 1024$ farklı satır adreslenir. Her satırdaki kelime 16 bittir: 8 bit ve 8 bit, toplam 16 bit.

$$2^{10} \times 16 = 1\text{K} \times 16$$

Bu yazım modülün kaç adres ucu ve kaç veri hattı olduğunu gösterir. Kapasite bayt cinsinden de verilebilir. 16 biti $2 \times 8$ bit diye yazarsak ve 8 bit bir bayt olduğuna göre:

$$2^{10} \times 2 \times 8 \text{ bit} = 2 \text{ KB}$$

**Sonuç:** $1\text{K} \times 16$ ile 2 KB aynı belleği anlatır. Birincisi adres ve veri ucu sayısını, ikincisi toplam kapasiteyi gösterir.

> **Hocanın vurgusu:** İki gösterimi de bilmeniz gerekir.

## 5. Bellek İşlemleri ve Kontrol Girişleri

### 5.1 Kontrol Girişleri

Bir RAM çipinde kontrol ucu olarak önce chip select (CS) ucu, sonra okuma ve yazma uçları gelir. Blok diyagramında okuma ve yazma ayrı ayrı gösterilmişti. Bu iki sinyal birbirinin tümleyeni gibi çalışacağı için tek uçta birleştirilir: $R/\overline{W}$. Gösterimin anlamı şudur: $R$ 1'de aktif, $W$ 0'da aktiftir.

| CS | $R/\overline{W}$ | İşlem |
| :---: | :---: | :--- |
| 0 | fark etmez | İşlem yapılmaz |
| 1 | 0 | Seçili kelimeye yazma (write to selected word) |
| 1 | 1 | Seçili kelimeden okuma (read from selected word) |

Okuma ve yazmanın çalışması için önce çipin etkin olması gerekir. Okuma ya da yazma yapılmayacaksa CS ucunu 0 yapmak yeterlidir.

**Soru:** Okumada data input'a veri göndermek gerekiyor muydu? **Cevap:** Hayır. Okumada kullanılan taraf data output'tur.

### 5.2 Yazma Döngüsü

Yazma işlemi zamanlama diyagramı üzerinde izlendi. İşlemcinin saat işaretinin periyodu 20 ns'dir. $T_1, T_2, T_3$ ve sonraki periyotların her biri 20 ns sürer. Yazma şu sırayla olur:

- Bellek etkinleştirme (memory enable), yani CS ucu 0'dan 1'e geçer. Aynı sırada yazılacak adres, adres yoluna gönderilir.
- CS 1 olup adres yola bırakıldıktan **sonra** $R/\overline{W}$ işareti seçilir. Hoca bu sıraya özellikle dikkat çekti. İşaret 0'a düşünce yazma isteği belli olur.
- CPU yazılacak veriyi register'dan veri yoluna bırakır. Diyagramda bu bölge "data valid" diye gösterilir.
- Yazma, neredeyse $T_4$ periyodunun sonunda tamamlanır. Slayta göre yaklaşık 75 ns sürer.

Periyot 20 ns olduğuna göre $T_4$, 60 ile 80 ns arasıdır, 75 ns de bu aralıktadır (ara adım eklendi). Yani bir yazma yaklaşık 4 saat periyodunda biter. Bu, bellek biriminin ne kadar yavaş çalıştığını gösterir. Hocanın karşılaştırması şöyledir: İşlemci içinde her saat periyodunda bir komut işleyebilirken, belleğe bir veri yazmak ancak dört periyotta tamamlanır.

### 5.3 Okuma Döngüsü

Okuma diyagramın alt satırındadır:

- Önce bellek etkinleştirilir, yani 1'e çekilir.
- $R/\overline{W}$ ucu 1 yapılır.
- CPU okunacak adresi adres yoluna bırakır.
- Bellek birimi önce memory enable'ı, sonra okuma işaretini görür ve adresi çözümler. Ardından veriyi yola bırakır.
- Geçerli veri $T_4$ periyodu içinde veri yoluna düşer. Slayta göre okuma yaklaşık 65 ns'de tamamlanır. Bu değer de 60-80 ns aralığındadır (ara adım eklendi).

> **Ders sonrası not:** Hoca burada belleğin "ilgili adresi basa bıraktığını" söyledi. Bellek bu adımda adresi değil, o adresteki veriyi veri yoluna bırakır. Az önceki "geçerli verinin veri yoluna düşmesi" cümlesi de bunu söylüyor.

Hocanın vardığı sonuç şudur: Günümüzde işlemci teknolojileri çok hızlı gelişirken bellek teknolojisi bu açıdan yavaş kalıyor. Bu yüzden bellek üzerinde işlem yapmak kaçınılan bir iş hâline geliyor.

## 6. Tazeleme ve Uçuculuk

### 6.1 DRAM'de Tazeleme

Hoca RAM türlerine bu kez dezavantaj açısından döndü. DRAM'in kapasitörle yapılmasının bir dezavantajı vardır. Devre teorisi dersinden bilindiği gibi kapasitör, üzerinde biriktirilen yükü zamanla kaybeder. Bir bellek hücresini kapasitörle kurup içine lojik 1, yani 5 voltluk bir değer yüklediğimizde bu değer zamanla yavaş yavaş sıfırlanır.

Bunun önüne geçmek için DRAM entegresinde tazeleme (refreshing) işlemi gerekir. Bu işlem, hücrelerdeki mevcut değeri yeniden kendi üstüne yükleyerek değerin korunmasını sağlar. Hoca ayrıntılara ilerleyen bölümde döneceklerini söyledi.

SRAM latch'lerle kurulur ve pahalıdır. RAM alırken kapasite büyüdükçe maliyetin ne kadar arttığı biliniyor. Bunu bir de SRAM ile yaptığımızı düşünürsek maliyet çok daha yüksek olur. Tercih edilen, SRAM'i küçük kapasitede önbellekte kullanmaktır.

### 6.2 Uçucu ve Kalıcı Bellek

Güç kaynağına bağımlılık açısından bellek birimleri ikiye ayrılır:

- **Uçucu (volatile):** Güç kesilince saklanan bilgiyi kaybeder (loses stored information when power turned off). RAM bunun birebir örneğidir.
- **Kalıcı (non-volatile):** Güç kesilince de bilgiyi korur (retains information when power turned off).

> **Hocanın vurgusu:** Bu kavramları mesleğiniz gereği artık biliyor olmanız gerekir.

## 7. Statik RAM Hücresi

Aradan sonra hoca bir biti saklayan SRAM hücresinin nasıl tasarlandığına geçti. Hücre SR latch ile kurulur. Önce SR latch'in doğruluk tablosunu hatırlattı:

| $S$ | $R$ | $Q$ | Durum |
| :---: | :---: | :---: | :--- |
| 0 | 0 | Değişmez | No change |
| 0 | 1 | 0 | Reset |
| 1 | 0 | 1 | Set |
| 1 | 1 | Tanımsız | Undefined |

> **Ek bilgi (derste anlatılmadı):** Slayttaki latch, girişleri 1'de aktif olduğuna göre büyük olasılıkla NOR kapılıdır. NOR kapılı bir SR latch'te $S = R = 1$ iken iki çıkış da 0 olur; bu sonuç python benzetimiyle hesaplandı. Yani $Q$ ile $Q'$ birbirinin tümleyeni olmaktan çıkar.

Latch'in bir select ucu vardır. Bunu bir chip select ucu gibi düşünebilirsiniz. Girişte iki AND kapısı bulunur. Birine ikili giriş $B$, ötekine $B'$ bağlanmıştır, select ise ikisine de gider.

- **Select = 0:** AND kapıları kilitlenir. Latch'in iki girişi de 0 olur. $SR = 00$ durumu "değişmez" olduğu için hücredeki değer korunur.
- **Select = 1, $B = 0$:** $SR = 01$ olur, latch reset edilir, $Q = 0$.
- **Select = 1, $B = 1$:** $SR = 10$ olur, latch set edilir, $Q = 1$.

Select ucu çıkışı da kontrol eder. Hücrenin sağ tarafındaki AND kapılarına da select gider. Select 0 ise bu kapılar kilitlidir, 1 ise hücredeki değer dışarıda görülebilir. Yani select hem yazma hem okuma için gereklidir. Yazmada devrenin sol tarafındaki girişler, okumada sağ tarafındaki AND kapıları devreye girer.

Hücrenin bütün giriş birleşimleri için bu davranış python ile denetlendi: Select 1 iken $Q$, $B$ değerini alıyor; select 0 iken eski değerini koruyor ve çıkış 0 oluyor.

## 8. RAM Bit Dilimi ve 16×1 RAM

Bir hücre bir bit saklar. Amaç, bu hücrelerden çok sayıda bir araya getirip RAM çipi oluşturmaktır. Slaytın söylediği şudur: $m$ kelimeli ve kelime başına $n$ bitli bir RAM çipinde (internal structure of a RAM chip of $m$ words with $n$ bits per word) $m \times n$ tane ikili saklama hücresi gerekir.

### 8.1 Bit Dilimi (RAM Bit Slice)

Hücreler alt alta dizilir. Her birinin select ucuna bir kelime seçme (word select) hattı gelir: Word Select 0, Word Select 1, sonra sonuncusuna kadar. Bütün hücrelerin $B$ ve $B'$ girişleri alttaki ortak devreden üretilir.

**Yazma tarafı:** Kaydedilecek veri Data In girişine uygulanır. Data In ve onun tümleyeni birer AND kapısına girer ve $B$ ile $B'$ oluşur. Bu AND kapılarının öteki kontrol ucu, bit select ve $R/\overline{W}$ ile belirlenir. Bit select 1 ve $R/\overline{W}$ 0 iken bu kapılar açılır, Data In'den gelen veri $B$ ve $B'$ olarak hücrelere gider. Yalnız word select hattı 1 olan hücre bu değeri alır.

**Okuma tarafı:** Sağ taraftaki bölüm devreye girer. Bu yapılandırmada Data Out ucunu görmek için bit select'in 1 olması yeterlidir.

Bu davranış 16 hücrelik bir bit dilimi benzetimiyle rastgele okuma ve yazmalar üzerinde denendi. Okunan değerler, en son yazılan değerlerle uyuştu.

### 8.2 16×1 RAM

Bu yapının önüne 4'ten 16'ya bir decoder eklenir ve 0'dan 15'e kadar 16 RAM hücresi bir araya getirilirse 16×1 RAM elde edilir: 16 satır, her satırda 1 bit. Dış uçları şunlardır:

- 4 adres girişi ($2^4 \times 1$)
- 1 bit Data In
- 1 bit Data Out
- $R/\overline{W}$ kontrol ucu
- Memory enable ucu

## 9. Çakışık Seçim (Coincident Selection)

### 9.1 Neden Gerekli?

RAM'ler 16 ya da 32 satırlık değil, çok daha büyük kapasitelidir. Kapasite büyüdükçe içerideki decoder da çok büyür. Örneğin 1 MB'lık RAM, $2^{20} \times 8$ bit demektir. Bu 20 adres biti ve $20 \to 2^{20}$ bir decoder gerektirir.

Yapıyı daha ucuz ve daha az malzemeyle kurmak için adres uçları satır seçme (row select) ve sütun seçme (column select) diye ikiye bölünür. 20 ucu 10-10 bölersek iki ayrı $10 \to 2^{10}$ decoder kullanırız. Bu, daha az karmaşık bir devre ve daha düşük maliyet demektir. Adres uçlarını ikiye bölüp iki decoder kullanan bu çözüme **çakışık seçim** (coincident selection, coincident decoding) denir.

Hocanın aşağıda 16×1 için kullandığı sayım bu örneğe uygulanırsa, tek decoder $2^{20} = 1.048.576$ AND kapısı, iki decoder ise $2 \times 2^{10} = 2048$ AND kapısı demektir (ara adım eklendi).

### 9.2 Örnek: 16×1 RAM

**Verilen:** 16×1 RAM. Çakışık seçim olmasaydı 4'ten 16'ya bir decoder gerekecekti.

**İşlem:** 4 adres ucu ikiye bölünür. Yüksek anlamlı iki bit ($A_3 A_2$) satır seçmeye, düşük anlamlı iki bit ($A_1 A_0$) sütun seçmeye gider. Her biri için 2'den 4'e bir decoder yeter.

Hücrelerin numaraları adresle şöyle eşleşir (ara adım eklendi):

| Satır ($A_3 A_2$) / Sütun ($A_1 A_0$) | 00 | 01 | 10 | 11 |
| :---: | :---: | :---: | :---: | :---: |
| 00 | 0 | 1 | 2 | 3 |
| 01 | 4 | 5 | 6 | 7 |
| 10 | 8 | **9** | 10 | 11 |
| 11 | 12 | 13 | 14 | 15 |

**Seçilecek adres:** $1001$, yani 9. hücre.

- Yüksek anlamlı iki bit $A_3 A_2 = 10$ satır decoder'ına girer. Decoder'ın 2 numaralı çıkışı aktif olur, ikinci satır seçilir.
- Düşük anlamlı iki bit $A_1 A_0 = 01$ sütun decoder'ına girer. 1 numaralı çıkış aktif olur ve o sütunun bit select ucuna gider.
- Yalnız bu satır ile bu sütunun kesişimindeki hücre seçilir: $4 \times 2 + 1 = 9$ (ara adım eklendi).

Bütün 16 adresin farklı birer hücre seçtiği python ile denetlendi.

**Kazanç:** 2'den 4'e bir decoder'ın içinde 4 AND kapısı vardır. İki decoder toplam 8 AND kapısı eder. 4'ten 16'ya decoder ise 16 AND kapısı demektir. Böylece 16 yerine 8 AND kapısı kullanılmış olur.

> **Ders sonrası not:** Hoca bu örneği "16'dan 1'e" ve sonrakini "8'den 2'ye" RAM diye okudu. Bunlar $16 \times 1$ ve $8 \times 2$ gösterimleridir. Ayrıca 16-8 karşılaştırması yalnız decoder içindeki AND kapılarını sayar. Bir hücre, satır ve sütun hatlarının ikisi birden aktifken seçildiği için hücre tarafında da büyük olasılıkla bir birleştirme devresi vardır. Slayt görülmediği için bu devre burada verilmedi.

**Soru:** Bunu 3 boyutlu yapmak mümkün mü, böyle RAM'ler var mı? **Cevap:** Öyle bir durum yok. Ama hücrelerin arka arkaya devam ettiğini düşünün. Bir hücre yerine select ucunu sekiz hücreye birden verirseniz bir bit yerine sekiz biti birden seçersiniz. Bu da belki bir üç boyut gibi düşünülebilir.

### 9.3 Örnek: 8×2 RAM

Hoca bu soruya benzer bir örnek olarak 8×2 RAM'e geçti. Tek decoder ile yapılsaydı içinde 8 AND kapısı gerekirdi.

**İşlem:** 3 bitlik adres bu kez eşit bölünmez. Yüksek anlamlı 2 bit satır decoder'ına, düşük anlamlı 1 bit sütun decoder'ına gider. Sütun decoder'ının her çıkışı iki sütunu birden seçer. Örneğin 0 numaralı çıkış iki kolonu birden seçer. Amaç, seçilen her adreste 1 değil 2 bit bulunmasıdır.

**Seçilecek adres:** $011$.

- Yüksek anlamlı iki bit $01$, satır decoder'ının 1 numaralı çıkışını, yani o satırı seçer.
- Düşük anlamlı bit $1$, sütun decoder'ının 1 numaralı çıkışını seçer ve bu çıkış iki sütunu birden seçer.
- Satır ile iki sütunun kesişimindeki iki hücreden 2 bit okunur.

Sekiz adresin her birinin farklı iki hücre seçtiği, toplamda 16 hücrenin de kullanıldığı python ile denetlendi. Sayım burada da aynıdır: 2'den 4'e decoder 4, 1'den 2'ye decoder 2 AND kapısı içerir, yani 8 yerine 6 AND kapısı (ara adım eklendi).

Çakışık seçimin avantajı adres çözümleme kısmındadır. Decoder boyutu küçüldüğü için toplam AND kapısı azalır. Bu yapı bu nedenle tercih edilir.

## 10. RAM Çipine Dışarıdan Bakış ve Üç Durumlu Çıkış

Bundan sonra hoca RAM'in iç yapısına bakmayacaklarını, onu yalnız bir blok olarak ele alacaklarını söyledi.

Örnek çip $64\text{K} \times 8$ RAM'dir. Bu, $2^{16} \times 8$ bit demektir. Uçları şunlardır:

- 16 bit adres girişi
- 8 bit Data In
- 8 bit Data Out
- Chip select girişi
- $R/\overline{W}$ kontrol ucu

Çıkış üzerindeki üçgen sembolü üç durumlu (three-state) çıkışı gösterir. Bizim iki durumumuz lojik 0 ve lojik 1'dir. Üçüncü durum yüksek empedanstır (High-Z). Hocanın vurguladığı avantaj şudur: Yüksek empedanslı çıkış, bu devrelerin çıkışlarını birbirine kısa devre edebilmemizi sağlar.

> **Ek bilgi (derste anlatılmadı):** Yüksek empedanstaki bir çıkış büyük olasılıkla hattı sürmez, hatta bağlı değilmiş gibi davranır. Ortak hatta değeri yalnız seçili çipin koyabilmesi bu yüzden mümkündür. Birazdan görülecek bellek genişletme devrelerindeki ortak Data Out hatları da bu özelliğe dayanır.

## 11. Kapasite Gösterimi ve Adres Ucu Hesapları

Daha büyük bellek konusuna (making larger memories) girerken hoca, bellek temelleri için hazırladığı ek bir dokümana geçti. Bellekler temelde iki gruba ayrılır: Random Access Memory ve Read Only Memory. RAM uçucu, ROM kalıcıdır. ROM'un iç yapısı geçen hafta görülmüştü.

### 11.1 Terimler ve Ön Ekler

Bir bellek modülü tarif edilirken "number of words" kaç satır, yani kaç kelime olduğunu, "$n$ bit in words" ise her kelimenin kaç bit olduğunu söyler.

| Ön ek | Değer | Adres ucu |
| :--- | :---: | :---: |
| Kilo (K) | $2^{10}$ | 10 |
| Mega (M) | $2^{20}$ | 20 |
| Giga (G) | $2^{30}$ | 30 |
| Tera (T) | $2^{40}$ | 40 |
| Peta (P) | $2^{50}$ | 50 |
| Exa (E) | $2^{60}$ | 60 |
| Zetta (Z) | $2^{70}$ | 70 |
| Yotta (Y) | $2^{80}$ | 80 |

Hocaya göre bugün en erişilebilir ve kullanılır olan, terabayt mertebesindeki disklerdir.

### 11.2 Adres Ucu Örnekleri

Bir sayının üssü, adres ucu sayısını verir:

- $64\text{K} = 2^6 \cdot 2^{10} = 2^{16}$, yani 16 adres ucu.
- $2\text{M} = 2^1 \cdot 2^{20} = 2^{21}$, yani 21 adres ucu.
- $4\text{G} = 2^2 \cdot 2^{30} = 2^{32}$, yani 32 adres ucu.

**Kapasite örneği:** $2^{16} \times 32$ bit ise 16 adres ucu ve 32 veri ucu vardır. Bayt cinsinden yazmak için 32 bit, $4 \times 8$ bit diye yazılır:

$$2^{16} \times 32 \text{ bit} = 2^{16} \times 2^2 \times 8 \text{ bit} = 2^{18} \text{ bayt} = 2^8 \times 2^{10} \text{ bayt} = 256 \text{ KB}$$

> **Ders sonrası not:** Hoca bu adımda "4 çarpı 8 byte" ve "$2^2$ çarpı 8 byte" dedi. Doğrusu $4 \times 8$ **bit**, yani 4 bayttır. Sonuç olan 256 KB doğrudur.

### 11.3 Alıştırma: Adres ve Veri Uçları

Soru (How many address lines and input/output data lines are needed in each case?), verilen modüllerde kaç adres ucu ve kaç veri ucu olduğudur.

$48\text{K}$ için hocanın kuralı şudur: 32 olsaydı 5 bit, 64 olsaydı 6 bit diyecektiniz. 32 ile gösteremediğiniz her büyüklüğü 64 ile göstermeniz gerekir. Yani 48 için en az 6 bit gerekir ve K'den 10 bit gelir: $6 + 10 = 16$.

| Bellek | Hesap | Adres ucu | Veri ucu |
| :--- | :--- | :---: | :---: |
| $48\text{K} \times 8$ | $6 + 10$ | 16 | 8 |
| $512\text{K} \times 32$ | $9 + 10$ | 19 | 32 |
| $64\text{M} \times 64$ | $6 + 20$ | 26 | 64 |
| $2\text{G} \times 1$ | $1 + 30$ | 31 | 1 |

### 11.4 Bir Modülün Bayt Cinsinden Kapasitesi: 128K×16

Fiziksel uç sayısının yanında bayt cinsinden eş değer kapasite de hesaplanabilir. Hoca bu sırada, ileride tamamlayacağı bir soruya başladı: Elimizde $128\text{K} \times 16$ RAM çipleri var, toplam 2 MB oluşturmak istiyoruz.

$128 = 2^7$ ve K $= 2^{10}$ olduğundan bir çipte 17 adres ucu ve 16 veri ucu vardır. Bir modülün kapasitesi için 16 bit, $2 \times 8$ bit diye yazılır:

$$128\text{K} \times 16 = 2^{17} \times 2 \times 8 \text{ bit} = 2^{18} \text{ bayt} = 256 \text{ KB}$$

Bunlardan 4 tanesi 1 MB eder. 2 MB için 8 tane gerekir.

Bir öğrenci, 16'yı yanlışlıkla bir bayt gibi hesapladığı için karıştırdığını söyledi. Dikkat edilecek nokta budur: Sağdaki 16 bit olarak ifade edilir. Bayt cinsinden yazarken 2 bayta çevrilir.

## 12. Boyuna Uzatma: 64K×8 Çiplerle 256K×8

Amaç, elimizdeki RAM çiplerini kullanarak daha büyük kapasiteli RAM oluşturmaktır (making larger memories). Kapasite iki yönde artırılabilir: aşağıya doğru büyütme (memory extension) ve yana doğru genişletme (expansion). İlk örnek aşağıya doğru büyütmedir.

**Verilen:** 4 tane $64\text{K} \times 8$ RAM çipi ile $256\text{K} \times 8$ RAM oluşturulacak.

**Çip uçları:** $64\text{K} \times 8 = 2^{16} \times 8$. Her çipte 16 adres ucu ve 8 veri ucu vardır.

**Hedef uçlar:** $256\text{K} \times 8 = 2^{18} \times 8$. Hedefte 18 adres ucu gerekir.

**Çip sayısı:**

$$\frac{256\text{K} \times 8}{64\text{K} \times 8} = \frac{2^{18}}{2^{16}} = 2^2 = 4$$

### 12.1 "Ortak Bağlamak" Ne Demek?

Çipler yukarıdan aşağıya yerleştirilir ve 16 adres ucu ortak bağlanır. Hoca bunun nasıl bir yapı olduğunu sınıfa sordu. Her çipte $A_0$'dan $A_{15}$'e kadar uç vardır. Bütün çiplerin $A_0$ uçları birbiriyle kısa devre edilir ve dışarıya tek bir $A_0$ ucu verilir. Sonra bütün $A_1$ uçları birleştirilir ve $A_{15}$'e kadar böyle gider. İlgili ağırlıktaki uçlar birbirine bağlandığı için dışarıdan yine 16 adres ucu görünür.

**Soru:** Word'ü genişletmişiz gibi geliyor. **Cevap:** Hayır.

**Soru:** Ortak bağlı olduğu için 16 farklı durum mu saklayabiliyor? **Cevap:** Hoca "tabii ki" diye karşılık verip ortak bağlamayı anlatmaya devam etti.

> **Ders sonrası not:** Bu soruda geçen "16 farklı durum" ifadesi hesapla uyuşmuyor. 16 adres ucu $2^{16}$ farklı adres gösterir, 16 farklı durum değil.

### 12.2 Bağlantılar

- $A_0$-$A_{15}$: Bütün çiplerde ortaktır.
- $A_{16}$ ve $A_{17}$: En yüksek anlamlı iki uç, 2'den 4'e bir decoder'a girer ve 4 seçme ucu üretir.
- Decoder çıkışları: Her biri bir çipin chip select girişine bağlanır.
- $R/\overline{W}$: Bütün çiplerde ortaktır.
- Data In ve Data Out: Ortak bağlanır. Dışarıda 8 Data In ve 8 Data Out ucu olur.

Sonuçta daha çok satır eklenmiş, ama genişletme yapılmamıştır. Her modül 8 bitti, son yapının veri yolu genişliği de 8 bittir.

### 12.3 Çipler Arasında Nasıl Ayrım Yapılır?

**Soru:** Bütün adres uçları aynı bağlandı. Birinci RAM'in birinci alanındaki veriyi almak istediğimde adres hepsine gidiyor. RAM'ler arasında nasıl ayrım yapacağım? **Cevap:** Chip select ucuyla. $A_{17} A_{16}$ değerlerine göre seçilen modül değişir:

| $A_{17} A_{16}$ | Aktif decoder çıkışı | Seçilen çip |
| :---: | :---: | :--- |
| 00 | 0 | En üstteki |
| 01 | 1 | İkinci |
| 10 | 2 | Üçüncü |
| 11 | 3 | Dördüncü |

Örneğin $A_{17} A_{16} = 00$ iken yalnız en üstteki modülün chip select ucu etkindir. Diğer çiplerin chip select ucuna 0 gittiği için onlar aktif olmaz ve çıkışlarının 8 bitlik Data Out uçlarına hiçbir etkisi olmaz.

Hocanın benzetmesi şudur: Toplam kapasitenizi aşağıya doğru dört bölgeye bölün. En üstteki modül birinci bölgeyi, sonraki modüller sırayla diğer bölgeleri oluşturur. Bölgeyi seçen de en yüksek anlamlı iki adres bitidir.

Adresi $A_{17} A_{16}$ ve $A_{15}$-$A_0$ diye bölmenin her adresi tek bir çip ve çip içi adrese götürdüğü python ile denetlendi.

## 13. Enine Genişletme: 64K×8 Çiplerle 64K×16

Bu kez enine genişletmeden (making wider memories) söz ediliyor.

**Verilen:** 2 tane $64\text{K} \times 8$ çip ile $64\text{K} \times 16$ yapılacak. Hedef, aynı adreste 8 değil 16 bit okumaktır.

**Adres uçları:** $2^{16} \times 8$ ile $2^{16} \times 16$ arasında adres ucu sayısı değişmez, 16 kalır.

**Yerleşim:** Çipler yan yana konur.

- 16 adres ucu iki modüle de ortak bağlanır.
- Chip select ucu, aynı satırdaki diğer çipin chip select ucuna bağlanır.
- Soldaki çip yüksek anlamlı 8 biti, sağdaki çip düşük anlamlı 8 biti oluşturur. Toplam 16 bit olur.

> **Hocanın vurgusu:** Bu konu önemli.

## 14. Örnek: 128K×16 Çiplerle 2 MB

Hoca aradan sonra, kapasite hesabı için başladığı soruyu tamamladı.

### 14.1 Kaç Çip Gerekir?

**Soru metni:** $128\text{K} \times 16$ RAM çipleri veriliyor. 2 MB kapasite için kaç çip gerekir (How many RAM chips are needed to provide a memory capacity of 2 MB)?

Adres uçlarına hiç girmeden, toplam kapasite bir modülün kapasitesine bölünür:

$$\text{çip sayısı} = \frac{\text{toplam kapasite}}{\text{bir çipin kapasitesi}}$$

$$\frac{2 \text{ MB}}{128\text{K} \times 16} = \frac{2^{21} \times 8 \text{ bit}}{2^{17} \times 16 \text{ bit}} = \frac{2^{21}}{2^{17} \times 2} = \frac{2^{21}}{2^{18}} = 2^3 = 8$$

### 14.2 Kaç Adres Hattı Gerekir?

Sorunun devamı 2 MB'a erişmek için kaç adres hattı gerektiğini (How many address lines are required to access 2 megabyte?) ve bunların kaçının bütün çiplerin adres girişlerine bağlandığını soruyor (How many of these lines are connected to address inputs of all chips?). Bir öğrenci cevabı 19 olarak söyledi. Hoca ise kapasiteyi yeniden yazarak 20'ye ulaştı.

2 MB'ı doğrudan yazarsak:

$$2 \text{ MB} = 2^{21} \times 8 \text{ bit}$$

Bu biçimde 21 adres hattı ve 8 veri hattı görünür. Ama elimizdeki çipler 16 bitlik olduğu için kapasiteyi her satırda 16 bit olacak biçimde yazmak zorundayız:

$$2^{21} \times 8 \text{ bit} = 2^{20} \times 16 \text{ bit} = 1\text{M} \times 16$$

Bu yapılandırmada **20 adres ucu** vardır. Bunların 17'si ($A_0$-$A_{16}$) bütün çiplere ortak bağlanır. Kalan 3'ü decoder'a gider.

> **Hocanın vurgusu:** Soru, kapasiteyi elinizdeki modülün genişliğinde, yani 16 bitlik biçimde vermediği için biraz "trikli". Kapasiteyi önce çipin kelime genişliğine göre yeniden yazın.

### 14.3 Devre

8 çip alt alta çizilir. Hoca hepsini çizmek yerine 1. ve 2. çipleri, araya noktaları, en alta da 8. çipi koydu.

- $A_0$-$A_{16}$: 17 adres ucu bütün çiplerde ortaktır.
- $A_{17}, A_{18}, A_{19}$: 3'ten 8'e bir decoder'ın girişlerine bağlanır. 17 ile 3 toplam 20 adres ucu eder.
- Decoder çıkışları: 0 numaralı çıkış en üstteki çipin, 1 numaralı çıkış bir alttakinin, 7 numaralı çıkış en alttaki çipin chip select girişine bağlanır.
- Data In: 16 hat ortak bağlanır. Bütün çiplerin $D_0$ uçları birbirine bağlanıp tek bir data 0 hattı oluşur, $D_1$ uçları için de aynısı yapılır ve böyle sürer.
- Data Out: Üç durumlu 16 çıkış birbiriyle kısa devre edilir. Dışarıdan 16 Data Out ucu görünür.

Böylece 8 çip bağlanarak $1\text{M} \times 16$ yapı elde edilir. Bu, bir boyuna uzatma örneğidir.

**Soru:** 2 MB değil de 1,96 MB olsaydı ne olurdu? **Cevap:** Yine aynı sayıda modül kullanmak gerekirdi. Elimizdeki modül $128\text{K} \times 16$ olduğuna göre kapasite onun katları biçiminde gider. Fazla kısmı yalnızca kullanmayabilirsiniz. Hesapla: $1,96 \text{ MB} / 256 \text{ KB} = 7,84$, yani yine 8 çip (ara adım eklendi).

> **Ders sonrası not:** Altyazıda hoca soruyu aktarırken "20 megabayt olmasaydı da" diyor. Sorudaki kapasite 2 MB'tır. Buradaki 20 büyük olasılıkla, aynı cümlede geçen 20 adres ucu sayısından karışmıştır.

## 15. Örnek: 64K×8 Çiplerle 512K×16

Son örnek, iki yönde de genişletme içerir. Hoca bu soruyu önceden hazırlamadığını söyleyerek yazdı.

**Soru metni:** $64\text{K} \times 8$ RAM çipleri ve decoder kullanarak $512\text{K} \times 16$ RAM için bir blok diyagramı çizin.

### 15.1 Çip Sayısı

$$\frac{512\text{K} \times 16}{64\text{K} \times 8} = \frac{2^{19} \times 16}{2^{16} \times 8} = \frac{2^{19} \times 2}{2^{16}} = \frac{2^{20}}{2^{16}} = 2^4 = 16$$

### 15.2 Yerleşim ve Decoder

8 bitten 16 bite çıkmak gerektiği için hem enine genişletme hem boyuna uzatma yapılacaktır. $64\text{K} \times 8$ çipten iki tanesi yan yana konunca ancak 16 bit elde edilir. Bu yüzden 16 çip, **8 satır ve 2 sütun** olarak yerleşir.

Hoca hangi boyutta decoder gerektiğini sordu, cevap olarak 3'e 8'lik geldi. 8 satırı seçmek için önde bir 3'ten 8'e decoder gerekir.

### 15.3 Bağlantılar

- Toplam adres: $512\text{K} = 2^{19}$, yani 19 adres ucu.
- $A_0$-$A_{15}$: 16 adres ucu bütün çiplere ortak bağlanır.
- $A_{16}, A_{17}, A_{18}$: En yüksek anlamlı 3 uç, decoder'ın girişlerine bağlanır.
- Decoder çıkışları: 0 numaralı çıkış ilk satırdaki iki çipin chip select girişine birlikte bağlanır. Yan yana olan çiplerin chip select uçları ortaktır. 1 numaralı çıkış ikinci satıra, 7 numaralı çıkış en alt satıra gider.
- Data Out: Bir sütundaki çipler düşük anlamlı baytı ($D_7$-$D_0$), yanındaki sütun yüksek anlamlı baytı ($D_{15}$-$D_8$) oluşturur. Aynı sütundaki çiplerin veri uçları birbirine bağlanır.
- Data In: Aynı biçimde çizilir, toplam 16 bit olur.

<!-- BELİRSİZ: Bu örnekte hangi sütunun sol, hangisinin sağ olduğu altyazıda "şurası" diye geçiyor. Hoca önce düşük anlamlı baytı gösterdi. Sütunların yönü bu yüzden yazılmadı. -->

> **Ders sonrası not:** Hoca çizim sırasında önce "18 tane adres girişi var" dedi, sonra sayıp 19 olarak düzeltti. Doğrusu 19'dur: 16 ortak uç ve 3 decoder girişi. Decoder girişleri için söylenen "A0'dan A15'e kadar" ifadesi de ortak adres uçlarını anlatır. Decoder girişleri $A_{16}$-$A_{18}$'dir. Hocanın bundan sonra söylediği "16 tane adres ucunu oluşturduk" da yalnız ortak uçları kapsar, toplam yine 19'dur.

Bu devre, 19 bitlik rastgele adreslere 16 bitlik yazma ve okumalarla python'da benzetildi. Okunan değerler yazılanlarla uyuştu.

### 15.4 Dört Örneğin Karşılaştırması

| Hedef | Kullanılan çip | Çip sayısı | Yerleşim | Ortak adres | Decoder |
| :--- | :--- | :---: | :--- | :--- | :--- |
| $256\text{K} \times 8$ | $64\text{K} \times 8$ | 4 | 4 satır, 1 sütun | $A_0$-$A_{15}$ | 2'den 4'e |
| $64\text{K} \times 16$ | $64\text{K} \times 8$ | 2 | 1 satır, 2 sütun | $A_0$-$A_{15}$ | Yok |
| 2 MB ($1\text{M} \times 16$) | $128\text{K} \times 16$ | 8 | 8 satır, 1 sütun | $A_0$-$A_{16}$ | 3'ten 8'e |
| $512\text{K} \times 16$ | $64\text{K} \times 8$ | 16 | 8 satır, 2 sütun | $A_0$-$A_{15}$ | 3'ten 8'e |

Hocanın sözlü kuralı da bu tabloyla uyuşur: Elinizde 8 bitlik çipler varsa ve 32 bitlik bir veri yapısı kurmak istiyorsanız 4 tanesini yan yana dizersiniz. Boyuna uzatma için de çipleri alt alta yerleştirirsiniz.

> **Hocanın vurgusu:** Bu konularla ilgili mutlaka sınavda soru olacak. Daha küçük kapasiteli RAM modüllerini bir araya getirip daha büyük kapasiteli RAM oluşturmak güzel bir sistemdir. Ders kitabının her bölümünün sonunda bu konularla ilgili sorular var. O soruları çözmeye çalışın ve bu egzersizleri çoğaltın.

## Dersin Toparlaması

Ders, geçen haftadan kalan programlanabilir lojik cihazları tamamlayarak başladı. PLA'da ortak terim aramanın AND kapısı sayısını nasıl azalttığı hatırlatıldı. PAL'de OR kapılarının sabit olması ve en fazla 3 çarpım terimi toplaması yüzünden dört terimli bir fonksiyonun, başka bir çıkışın geri beslenmesiyle gerçekleştirildiği görüldü. Ardından bellek temellerine geçildi: SRAM ile DRAM'in farkı, $2^k \times n$ gösterimi, chip select ve $R/\overline{W}$ kontrolü, belleğin yaklaşık 4 saat periyodu süren okuma ve yazma döngüleri, uçuculuk ve DRAM'de tazeleme. SR latch ile bir SRAM hücresi kuruldu, bu hücrelerden bit dilimi ve 16×1 RAM oluşturuldu. Büyük belleklerde decoder'ın aşırı büyümesi, adres bitlerini satır ve sütuna bölen çakışık seçimle aşıldı.

Dersin son bölümünde RAM dışarıdan bir blok olarak ele alındı. Adres ve veri ucu hesapları yapıldı. Boyuna uzatmada adres, veri ve $R/\overline{W}$ uçlarının ortak bağlandığı, yüksek anlamlı adres bitlerinin decoder üzerinden çip seçtiği görüldü. Enine genişletmede ise adres ve chip select ortak kalır, veri uçları yan yana gelir. İki yöntem $64\text{K} \times 8$ çiplerle $512\text{K} \times 16$ örneğinde birleştirildi. Hoca, DRAM tazelemenin ayrıntılarına ilerleyen bölümde döneceklerini söylemişti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
