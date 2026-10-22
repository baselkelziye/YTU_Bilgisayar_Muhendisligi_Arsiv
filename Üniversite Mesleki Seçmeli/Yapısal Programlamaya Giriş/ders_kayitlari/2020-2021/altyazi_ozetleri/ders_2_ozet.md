# Ders 2 Çalışma Özeti

## Genel Konular

- Bu ders, birinci dönemdeki Bilgisayar Bilimlerine Giriş dersinin bir tekrarıdır. Makinenin en temelinden başlanır, verinin nasıl saklandığı anlatılır ve dersin sonunda algoritma kavramına giriş yapılır.
- Bilgisayar nedir?
  - Bilgisayar bir hesaplama aracıdır. İnsandan farkı, tarif edilen işlemi hızlı ve hatasız yapması ve çok büyük veriyi saklayabilmesidir.
  - Bilgisayar, tarif ettiğiniz işlemi yapar. Toplama yapmak isterken `x = a * b;` yazarsanız bilgisayar çarpma yapar. Beklenmeyen sonuç bilgisayarın değil, sizin hatanızdır.
- Bilgisayarın temel bileşenleri
  - İşlem birimi (CPU): programları koşturur, yani komutları sırayla icra eder (execute).
  - Ana bellek (main memory, birinci bellek): CPU'nun doğrudan veri alabildiği bellektir. Genellikle RAM'dir. Program ve veri (data) burada saklanır.
  - Bus (veri yolu): CPU ile bellek arasındaki haberleşmeyi ve veri transferini sağlar. Üç tane bus vardır: adres bus, data bus ve control bus.
  - Dördüncü bir yapı temel sistemde zorunlu değildir: bus'a bağlanan çevresel birimler (peripheral devices). Genellikle giriş-çıkış (I/O) işleri için kullanılırlar.
- Program ve proses
  - Program, bizim yazdığımız ve anladığımız koddur (for, while vb.). Bilgisayar bunu doğrudan anlamaz. Derleyici (compiler) kodu çalıştırılabilir (executable) hâle getirir.
  - Çalıştırılabilir dosya çalıştırıldığında (çift tıklayarak ya da komut satırından) bir örneği belleğe yüklenir. Çalışmakta olan bu programa proses (process, program in execution) denir. Görev yöneticisinde (Ctrl+Alt+Del) her prosesin bir ID'si görülür.
  - CPU kodu derlemez. CPU, proseste bulunan makine komutlarını tek tek icra eder.
- Bus'ların görevi
  - Program counter (PC), sıradaki komutun bellekteki adresini tutar. Instruction register gibi başka özel register'lar da vardır.
  - Okuma: control bus "okuma yapılacak" sinyalini gönderir, adres bus okunacak adresi gösterir, okunan veri data bus üzerinden işlemciye gelir.
  - Yazma (ör. `x = x + 1` sonrası güncel değerin belleğe kaydedilmesi): control bus yazma sinyali gönderir, adres bus'tan yazılacak adres, data bus'tan yazılacak veri gider.
  - İşlemcinin içinde büyük bir hafıza yoktur. Bu yüzden program ve veri yardımcı bellekten (ana bellek) bus'lar yoluyla getirilir.
- Komut çevrimi (instruction cycle)
  - Fetch instruction: komutu "gidip getirmek". Adres bus üzerinden yer bulunur, data bus üzerinden komut getirilir.
  - Decode instruction: 0 ve 1'lerden oluşan komut çözümlenir. Komut, opcode (operation code; ör. ADD, SUB) ve operandlardan (hangi verilerle işlem yapılacağı, sonucun nereye yazılacağı) oluşur.
  - Execute instruction: komutun gereği yerine getirilir. Matematiksel ve mantıksal işlemler ALU'da (aritmetik lojik ünite) yapılır.
  - Write back: sonuç gerekiyorsa belleğe yazılır.
  - Çevrim, program sonlanana (termination) ya da beklenmedik şekilde durana (halt) kadar devam eder.
- Bilginin 0 ve 1 ile kodlanması
  - Bilgisayar elektrikle çalışır (ör. 0-5 V veya 0-12 V aralığı). Aradaki her voltaj değerini ayrı bir bilgi olarak kullanmak yerine yalnızca iki durum kullanılır: 0 ve 1.
  - Sebep: iletkendeki direnç, ısı ve dış etkiler yüzünden gönderilen voltaj karşı tarafa kayıpla ulaşır. Çok seviyeli bir kodlamada 1 V gönderilir de 0,5 V okunursa yanlış bilgi alınır. Hoca bunu orta bahçenin iki ucundan parmakla işaret vermeye benzetir: uzaktan kaç parmak kaldırıldığı anlaşılmaz, ama elin havada olup olmadığı anlaşılır.
  - Bu yüzden belli bir eşiğin (ör. 3 V) altı 0, belli bir eşiğin (ör. 7 V) üstü 1 kabul edilir. Arada kalan bölgeye kararsızlık kuşağı denir. Bu bölge ne kadar dar olursa o kadar iyidir.
  - Voltajın 0'dan yükseğe çıkması zaman alır. Milyarlarca bit için bu süre önemlidir. 12 V yerine 5 V kullanılmasının bir sebebi de daha kısa sürede ulaşılmasıdır.
- Yarı iletkenler ve transistör
  - Elektriğin varlığını ve yokluğunu en iyi temsil eden malzemeler yarı iletkenlerdir (silisyum, germanyum). Bu malzemeler bariyer voltajı aşılana kadar yalıtkan, aşıldıktan sonra iletkendir. Hoca değerleri silisyum için 0,7 V, germanyum için 0,3 V olarak hatırlar.
  - Diyot: uygulanan gerilim bariyer voltajından fazlaysa akım geçirir (1), azsa geçirmez (0).
  - Transistör bir musluğa benzer. Musluk sonuna kadar kapatılırsa direnç sonsuz olur ve akım sıfırlanır ($I = V/R$). Musluk açıldıkça akım artar. Bilgisayarda transistörün yalnızca akım geçirip geçirmediğine (0/1) bakılır.
  - Transistörler birbirine bağlanarak lojik kapılar (AND, OR), flip-flop'lar ve register'lar oluşturulur. Toplama, çıkarma, çarpma, bölme gibi işlemler bu devrelerle 0 ve 1'ler üzerinde yapılır. Detaylar Lojik Devreler ve Elektronik Devreler derslerinde görülür.
- Transistör yoğunluğunun sınırı (R-C etkisi)
  - Akım geçen her transistörde ısı açığa çıkar. İşlemcilerin soğutulmasının (termal macun, fan) sebebi budur. Soğutucu devreden çıkarsa işletim sistemi donanıma zarar gelmemesi için bilgisayarı kapatır.
  - Transistörler birbirine çok yaklaştırılırsa direnç ve ısı etkisi (R etkisi) artar. Çok uzaklaştırılırsa hem daha az transistör sığar hem de iki iletken arasına giren yalıtkan bir kondansatör etkisi (C etkisi) oluşturur.
  - Bu iki etki arasında bir orta yol bulmak gerekir. Buna trade-off (ödünleşim) denir: bir şeyden ödün verilirken başka bir şey kazanılır.
  - Bu sınırlar yüzünden kuantum bilgisayarlar ve ışığın varlığını/yokluğunu kullanan optik bilgisayarlar üzerinde çalışılmaktadır.
- Her CPU'nun kendi komut seti vardır
  - "Each CPU (processing unit) has its own instruction set and architecture." Her işlemcinin kendine özgü bir komut seti ve mimarisi vardır. Bir işlemcinin data sheet'ine bakılırsa komut seti görülür. Başka bir modelde komutlar ve mimari farklıdır.
  - ARM ile Intel/AMD işlemcilerin geliştirme mantıkları farklıdır (RISC/CISC komut seti mimarileri, Harvard/von Neumann mimarileri). Detaylar Mikroişlemciler dersinde görülür.
- Bellekler ve hızları
  - RAM'de bilgi transistör ve kondansatörlerle saklanır. Dinamik RAM'ler kondansatör ve transistörle, statik RAM'ler ve cache bellekler daha çok transistörle yapılır.
  - Eski (dönen diskli) hard disklerde veri manyetik olarak yazılır ve manyeto-rezistif bir okuma kafasıyla okunur. Hard diskler 5400 veya 7200 rpm (dakikadaki dönüş sayısı) ile döner.
  - CD ve DVD'lerde veri ışıkla yakılır (pit ve land). Yazılmış bölge farklı renkte görünür.
  - Hız sıralaması: işlemci (GHz mertebesi) > RAM (MHz mertebesi) > hard disk.
- Darboğaz örneği (laboratuvar bilgisayarları)
  - Bölüm laboratuvarındaki Core 2 Duo, 4 GB RAM'li bilgisayarlar yalnızca C, Java gibi işler için kullanılıyordu ve yavaştı.
  - RAM'i artırmak işe yaramazdı, çünkü bir C programı RAM'in çok küçük bir kısmını kullanır. Darboğaz hard diskti. Hard diskler SSD ile değiştirilince açılış süresi bir buçuk dakikadan 10-15 saniyeye indi.
  - Hoca bunu hızlı bir arabayla toprak yolda gitmeye benzetir: sistemin en yavaş birimi iyileştirilmelidir.
- Von Neumann ve Harvard mimarisi
  - Von Neumann: komutlar ve veriler aynı ana bellekte, bütünleşik olarak saklanır.
  - Harvard: program belleği ile veri belleği ayrıdır. CPU bunlara farklı kanallardan erişir. Kod alınırken veri de hazırlanabildiği için bus'lar daha etkin kullanılır.
  - Günümüzde kesin bir ayrım yoktur. Firmalar iki mimarinin üstün yanlarını birleştirir.
- İşlemcide 0 ve 1'lerin kullanımı
  - Instruction set encoding: her komuta (ör. ADD) belli bir 0-1 dizisi karşılık getirilir.
  - Instruction execution: komutların görevi yerine getirilir. Toplama işlemi lojik seviyede, lojik kapılardan oluşan toplama devreleriyle yapılır. Çıkarma da toplama cinsinden yapılabildiği için bunlara toplama-çıkarma devreleri denir.
- Makine dili, assembly ve programlama dilleri
  - Her işlemcinin komut setini ezberleyip problem çözmek makul değildir. Komut seti işlemciden işlemciye değişir. Hoca örnek olarak PIC16F84 ile PIC16F877 arasındaki büyük farkları verir.
  - Makine dili ve onun doğrudan karşılığı olan assembly dili donanıma bağımlıdır (hardware dependent). Taşınabilir değildir ve bunlarla kod yazmak zordur.
  - Programlama dilleri donanımdan bağımsızdır (hardware independent) ve konuşma diline daha yakındır. Yazılan kaynak kod (`.c`, `.py`, `.java`, `.cs`) bir derleyici veya yorumlayıcı ile makine koduna çevrilir. Executable dosya, eklenen kütüphaneler yüzünden kaynak koddan çok daha büyük olabilir.
  - Python, Java, C# gibi dillerde kaynak kod önce bir ara koda (bytecode) çevrilir. Bu ara kod, Java Virtual Machine gibi mekanizmalarla çalışılan işletim sistemine göre makine koduna dönüştürülür.
  - Derleyici kaynak kodu ayrıştırırken sözdizimi (syntax) ve anlam (semantic) analizi yapar. Detaylar Programlama Dillerinin Kavramları ve Derleyici Tasarımı derslerinde görülür.
  - Bir işlem komut setinde yoksa diğer işlemler cinsinden tarif edilmelidir. Örneğin 8086 işlemcilerde karşılaştırma için CMP komutu vardır, PIC'lerde ise yoktur ve karşılaştırma çıkarma ile yapılır.
- Veri türleri ve kodlanmaları
  - Günlük hayattaki veriler: karakterler ve metinler, sayılar (integer, floating point, karmaşık sayı), boolean, görüntü, ses, video ve her türlü fiziksel büyüklük.
  - Karakterler ASCII veya Unicode gibi bir sistematikle kodlanır. Büyük harf ile küçük harf arasında 32 fark vardır. Shift veya Caps Lock'a basınca bu bit değişir.
  - Integer: en anlamlı bit (MSB) işaret bitidir (1 negatif, 0 pozitif), geri kalan bitler büyüklüğü tutar. C'de `int` 4 byte = 32 bittir. Aralığı $-2^{31}$ ile $2^{31}-1$ arasıdır. Daha büyük aralık için 8 veya 16 byte kullanılabilir.
  - Floating point: işaret biti, mantissa ve exponent alanlarından oluşur. Herkesin aynı şekilde kodlaması için IEEE 754 standardı vardır. Single precision 32 bit, double precision 64 bittir. Double daha hassastır. Hoca hassasiyetin önemini şöyle anlatır: mayın taramada %90 başarı yetersizdir, müzik işlemede %85 sorun olmayabilir.
  - Karmaşık sayı: iki floating point değerden oluşur ($a + bi$).
  - Boolean: doğrudan 0 ve 1 (false/true).
  - Bunlar ilkel (primitive) veri tipleridir. Görüntü, ses gibi veriler bunlardan oluşturulur.
- Görüntü
  - Görüntü satır ve sütunlardan oluşur. Her kesişim noktasına piksel denir. Satır × sütun sayısı çözünürlüğü verir.
  - Gri seviye bir görüntüde her piksel 8 bit (0-255) tutar: 0 siyah, 255 beyaz. Piksel başına bit sayısı arttıkça renk çeşitliliği artar.
  - Bellek tek boyutludur. Görüntü bellekte (0,0)'dan (M−1, N−1)'e kadar art arda saklanır.
  - Boyut = M × N × piksel başına bit. Örneğin 10 × 10 × 8 bit = 800 bit = 100 byte.
- Ses
  - Ses tek boyutlu bir dizidir. Ses dalgasından belli bir örnekleme frekansıyla örnekler alınır.
  - CD kalitesi için örnekleme frekansı 44.100 Hz'dir, yani saniyede 44.100 örnek alınır. İnsan kulağının duyabildiği en yüksek frekans yaklaşık 20 kHz'dir ve örnekleme frekansı bunun en az iki katı olmalıdır.
  - Ses örnekleri negatif değer de alabilir. 10 bitlik örnekler $-2^9$ ile $2^9-1$ arasındadır.
  - Örnek başına bit sayısı artırılabilir, ama ses kartının çözünürlüğü (genellikle 16 bit) bir üst sınır koyar.
  - Stereo kayıt iki ayrı dizi demektir. Daha fazla kanal daha fazla dizi demektir.
- Video
  - Video, saniyede en az 24 görüntünün (frame) art arda gelmesi ve bunlarla eş zamanlı bir sesin birleştirilmesidir. Ses ve görüntü senkronize olmazsa konuşanın ağız hareketleri sesle uyuşmaz.
- Bit, byte ve birimler
  - 1 bit iki durum tutar (var/yok). 4 bit bir nibble, 8 bit bir byte'tır.
  - 1 KB = $2^{10}$ byte, 1 MB = $2^{10}$ KB = $2^{20}$ byte, 1 GB = $2^{30}$ byte. Terabyte ve sonrası aynı mantıkla devam eder.
  - Küçük "b" bit, büyük "B" byte anlamına gelir (Mb megabit, MB megabyte). İnternet hızları genelde bit cinsinden verilir (Gbps).
- Sampling ve quantization
  - Analog sinyal (ör. $x(t)$: ses, sıcaklık, döviz kuru) sonsuz detay içerir. Bilgisayarın belleği ise sonludur. Bu yüzden sinyal iki eksende ayrıklaştırılır (discretization).
  - Zaman ekseninde ayrıklaştırmaya örnekleme (sampling) denir. Sonuç bir dizidir: $x[n]$, $n = 0, 1, \ldots, n_{max}$. Bu da $n_{max}$ elemanlık bir bellek tahsisi demektir.
  - Genlik ekseninde ayrıklaştırmaya nicemleme (quantization) denir. 0 ile max arasındaki aralık, $m$ bitle temsil edilebilecek seviyelere bölünür: $\text{aralık} \le 2^m$.
  - Toplam boyut $n_{max} \times m$ bit olur.
  - Her iki ayrıklaştırma da orijinal veride kayba yol açar. Bu kayıp, insan kulağının veya gözünün fark etmeyeceği düzeyde tutulmalıdır.
- Sinüzoidaller ve tını
  - Her sinyal teorik olarak sinüzoidal sinyallerin toplamı olarak yazılabilir.
  - DTMF: telefon tuşları iki sinüzoidalin toplamıyla kodlanır. Örneğin 1 tuşu 697 Hz ile 1209 Hz'in toplamıdır.
  - C6 notası yaklaşık 1047 Hz'lik bir sinüs dalgasıdır. Aynı nota obua veya klarnetle çalındığında temel frekansın yanında ek frekans bileşenleri oluşur. Enstrümanları birbirinden ayıran bu özelliğe tını (timbre) denir.
  - Örnekleme teoremi: örnekleme frekansı, sinyaldeki en yüksek frekans bileşeninin en az iki katı olmalıdır. Daha düşük frekansla örneklenen sinyal geri oluşturulduğunda (reconstruction) bileşenler birbirine karışır.
- Gerçek dünya problemleri ve algoritma
  - Bir problemde giriş verileri verilir (ya da bulunur) ve bunlardan bir çıkış üretilmesi istenir. Girişle çıkış arasındaki fonksiyona sistem modeli, transfer fonksiyonu veya davranış fonksiyonu denir.
  - Hoca havuz problemini örnek verir: dolduran musluklar ($+t_1$, $+t_2$), boşaltan musluk ($-t_3$) ve havuzun hacmi girişlerdir. Havuzun ne kadar sürede dolacağı çıkıştır.
  - Algoritma: giriş verilerinden çıkışı üreten fonksiyonu bulma sürecidir. Her zaman matematiksel bir formül değildir. Örneğin bir sayı dizisinin en büyüğünü bulmak da bir algoritmadır.
  - Algoritma görece soyuttur, programlama somuttur. Kafada oluşturulan çözüm taslağı bir programlama dilinin kurallarına göre yazılır. Buna gerçekleştirme (implementation) denir.
- Algoritmanın özellikleri
  - Unambiguous (açık, belirsizlik içermeyen): her adım, bilgisayarın yapabildiği temel işlemler cinsinden tarif edilmelidir. Bilgisayar "2t = 4'te 2'yi karşıya götür", "karesini al", "sırala" gibi ifadeleri bilmez. Bunların nasıl yapılacağı tarif edilmelidir.
  - Finite (sonlu): algoritma bir yerde bitmelidir. Ayrıca komut seti de sonludur, yalnızca komut setinde bulunan komutlar kullanılabilir.
  - Sequence and set (sıralı komutlar kümesi): komutlar mantıklı bir sırayla gelmelidir. Hoca bunu en önemli özellik olarak görür.
- Üç temel yapı
  - Sıralı işlemler (sequential): ör. `a = a + 1`, `a = 5`. Akış bu satırlara geldiğinde hepsi mutlaka yapılır.
  - Şartlı işlemler (conditional): `if (...) {...} else {...}`. Bir kısım yapılırken diğer kısım yapılmaz.
  - Tekrarlı işlemler (repetitive):
    - Belirli (definite): kaç kez tekrar edileceği bellidir (ör. 1'den 100'e, 50'den 30'a). Genellikle `for` ile yazılır.
    - Belirsiz (indefinite): ne zaman biteceği belli değildir (bulana kadar, bir değerden büyük olana kadar). Genellikle `while` ve `do-while` ile yazılır.
  - Dördüncü bir yapı yoktur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgisayar tarif edileni hatasız yapar. Hata tarifte ise sonuç da hatalıdır. Hoca Prolog ödevinden örnek verir: ebeveyn-çocuk ilişkisini yanlış tarif eden öğrencinin programında bir çocuğun birden fazla annesi çıkıyordu.
- Mülakatlarda ve sınavlarda sık sorulan soru: bir bilgisayar sisteminde temelde kaç tür bus vardır? Cevap: üç (adres, data, control).
- Fetch "getirmek" değil, "gidip getirmek"tir. Çünkü önce gidilecek adresin bilinmesi gerekir.
- "Each CPU has its own instruction set and architecture." Bu cümle not edilmeli ve unutulmamalıdır.
- Algoritma yazarken (özellikle sözde kod ve akış diyagramında) yalnızca temel işlemler kullanılır: toplama, çıkarma, çarpma, bölme, eşitlik, karşılaştırma ve atama. "Sırala", "karesini al", "5. kuvvetini al" gibi kısa yollar yanlıştır. Bunların nasıl yapılacağı tarif edilmelidir.
- Algoritmada sıra çok önemlidir. Önce çorap, sonra ayakkabı giyilir. Kek tarifinde yumurta ve şeker köpürene kadar çırpılmadan diğer malzemeler eklenirse kek bozulur.
- Algoritmada yalnızca üç yapı vardır: sıralı, şartlı ve tekrarlı. Dördüncüsü yoktur.
- Sınavlar ve ödevler diğer şubeyle ortaktır. Hocalar farklı yollardan aynı hedefe ulaşır. Hoca diğer şubenin derslerini de izlemeyi önerir.

## Kısa Tekrar Notları

- Temel bileşenler: CPU, ana bellek, bus (adres, data, control). Dördüncü olarak çevresel birimler (I/O).
- Proses: çalışmakta olan program.
- Komut çevrimi: fetch, decode, execute, write back.
- Opcode = işlem (ADD, SUB) + operandlar.
- 0/1 kodlama: kayıplı iletimde iki durum güvenilirdir. Eşikler arası bölge kararsızlık kuşağıdır.
- R-C etkisi: sık yerleşim ısı (R), seyrek yerleşim kondansatör etkisi (C) getirir. Arada bir trade-off vardır.
- Von Neumann: tek bellek. Harvard: ayrı program ve veri belleği.
- Makine dili ve assembly donanıma bağımlı, programlama dilleri bağımsızdır.
- ASCII: 'A' = 65 = `01000001`, 'a' = 97 = `01100001`. Fark 32'dir.
- `int`: 32 bit, aralık $-2^{31}$ ile $2^{31}-1$.
- IEEE 754: single 32 bit, double 64 bit.
- Görüntü boyutu = M × N × piksel başına bit.
- Ses boyutu = süre (s) × örnekleme frekansı × örnek başına bit. CD: 44.100 Hz.
- k farklı değer için gereken bit sayısı: $2^n \ge k$ olan en küçük $n$.
- Sampling zamanda, quantization genlikte ayrıklaştırmadır.
- Örnekleme teoremi: en yüksek frekansın en az iki katı.
- Algoritma: unambiguous, finite, sequence and set.
- Üç yapı: sequential, conditional, repetitive (definite: `for`; indefinite: `while`, `do-while`).

## Detaylı Açıklamalar

Ders, Telegram grubu ve sohbet kuralları gibi duyurularla başlar. Hoca, BLM1011'i almamış öğrencilere geçen dönemin ders kayıtlarını izlemelerini önerir. Akış diyagramı notasyonunun diğer kaynaklardan farklı olabileceğini ve bu notasyona uygun problem çözülmesi gerektiğini belirtir. Ardından OneNote üzerinde çizerek konuyu makinenin en temelinden başlatır.

### Bellek adresleme örneği

Bir öğrencinin bilgisayarında 16 GB RAM vardır. İşlemcinin bu belleğin her byte'ını adresleyebilmesi için kaç bit gerekir?

- 16 GB = $2^4 \times 2^{30}$ byte = $2^{34}$ byte.
- Her byte'a ayrı bir adres verilir. 0. byte'tan $(2^{34}-1)$. byte'a kadar adresleri yazmak için 34 bitlik adres gerekir. 0. byte'ın adresi 34 tane 0, son byte'ın adresi 34 tane 1'dir.
- Bellekteki toplam bit sayısı: $2^{34} \times 8 = 2^{34} \times 2^3 = 2^{37}$ bit.
- Bitler tek tek adreslenmez. Adresleme genellikle byte byte yapılır. Bu, belleğin kaç bitlik hücrelerle organize edildiğine bağlıdır.

### Metin boyutu örneği

Bir metinde 100 karakter vardır ve bu metinde 50 farklı karakter kullanılmıştır. Metin en az ne kadar yer kaplar?

- 50 farklı karakteri ayırt etmek için $2^n \ge 50$ olmalıdır. $2^5 = 32$ yetmez, $2^6 = 64$ yeter. Karakter başına en az 6 bit gerekir.
- Hangi karaktere hangi 0-1 dizisinin verileceği burada önemli değildir. Önemli olan karakter başına bit sayısıdır.
- Toplam: 100 × 6 = 600 bit.

### Görüntü boyutu örneği

512 × 512 bir görüntüde her piksel 400 farklı renkten birini alabilir.

- $2^8 = 256$ yetmez, $2^9 = 512$ yeter. Piksel başına 9 bit gerekir.
- Toplam: $2^9 \times 2^9 \times 9 = 2^{18} \times 9$ bit.

Hocanın bu iki örnekteki birim dönüşümleri hatalıdır. Doğru değerler aşağıdaki notta verilmiştir.

### Ders sonrası notlar

- **600 bitin boyutu:** Derste 600 bit için "yarım kilobayt ile 1 kilobayt arası" denildi. $2^{10}$ bit 1 kilobit'tir, kilobayt değildir. 600 bit = 75 byte'tır.
- **512 × 512 görüntünün boyutu:** Derste $2^{18} \times 9$ bit "yaklaşık 9 megabit, yani yaklaşık 1 megabayt" olarak hesaplandı. Oysa $2^{18}$, $2^{20}$ değil $2^{20}/4$'tür. Doğru sonuç $2^{18} \times 9 = 2.359.296$ bit = 294.912 byte = 288 KB'tır (yaklaşık 2,25 megabit).
- **RAM ve işlemci hızı:** Derste 3200 MHz RAM ile 3,2 GHz işlemci arasında "10³ kat fark" olduğu söylendi. 3200 MHz = 3,2 GHz'tir, yani ikisinin saat frekansı aynıdır. Bellek erişimi işlemciye göre yine de yavaştır, ama sebebi bu değildir: erişim gecikmesi (latency) ve bus üzerinden veri aktarımı zaman alır.
- **Hard disk dönüş hızı:** Derste 7200 rpm "yaklaşık 0,01 Hz" olarak hesaplandı. 7200 / 60 = 120 dönüş/saniye, yani 120 Hz'tir. Bir dönüş yaklaşık 8,3 ms sürer. Hard diskin yavaşlığı bu mekanik dönüş ve kafa hareketinden kaynaklanır.
- **İşlemcideki transistör sayısı:** Derste güncel i7/i9 işlemciler için 40-50 milyon transistör denildi. Güncel masaüstü işlemcilerde transistör sayısı milyarlar mertebesindedir.
- **İnsan kulağının duyma aralığı:** Derste "2 Hz ile 20 kHz" ve "2 kHz'de duymaya başlarsınız" denildi. Kabul edilen aralık yaklaşık 20 Hz ile 20 kHz arasıdır.
- **Floating point alanları:** Derste mantissa ve exponent alanlarının "virgülden önceki ve virgülden sonraki kısımları" tuttuğu söylendi. IEEE 754'te sayı $(-1)^{\text{işaret}} \times 1{,}\text{mantissa} \times 2^{\text{exponent}-\text{bias}}$ biçiminde saklanır. Exponent virgülün yerini (ikinin kuvvetini), mantissa ise anlamlı basamakları tutar. Single precision'da 1 işaret, 8 exponent ve 23 mantissa biti vardır.
- **Integer gösterimi:** Derste işaret biti ve büyüklük bitleri (sign-magnitude) anlatıldı. Bu gösterimle 32 bitte aralık $-(2^{31}-1)$ ile $2^{31}-1$ olur ve iki ayrı sıfır (+0, −0) çıkar. Tahtadaki $-2^{31}$ ile $2^{31}-1$ aralığı, bilgisayarların gerçekte kullandığı ikiye tümleyen (two's complement) gösterimine aittir. İkiye tümleyende de en anlamlı bit 1 ise sayı negatiftir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
