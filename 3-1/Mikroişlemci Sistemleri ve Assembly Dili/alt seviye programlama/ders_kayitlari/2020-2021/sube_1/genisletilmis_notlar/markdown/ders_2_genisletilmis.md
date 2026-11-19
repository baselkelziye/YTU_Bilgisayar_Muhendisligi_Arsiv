# Ders 2 Genişletilmiş Notu: 8086 Yazmaçlarının Tekrarı, Komut Yapısı ve Veri Aktarım Komutları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Birinci Haftanın Tekrarı: Sayı Gösterimleri ve Veri Formatları
- 2. Mikroişlemcinin İç Yapısı ve 8086 Yazmaçları
- 3. Segment Yazmaçları ve Fiziksel Adres
- 4. Instruction Pointer ve Bayraklar
- 5. 32 ve 64 Bitlik İşlemcilerde Yazmaçlar, Real ve Protected Mode
- 6. Basit Bir İşlemcide Kontrol Birimi
- 7. 8086 Komut Yapısı
- 8. Komutlardaki Kısaltmalar
- 9. Veri Aktarım Komutları ve MOV
- 10. Bellek Adresleme Kipleri
- 11. LEA: Load Effective Address
- 12. LDS ve LES
- 13. XCHG ve XLAT
- Örnek Sorular

## 1. Birinci Haftanın Tekrarı: Sayı Gösterimleri ve Veri Formatları

Ders, birinci haftanın son kısmı hızlı geçtiği için kısa bir tekrarla başladı. Geçen hafta mikroişlemcilerin tarihçesi üzerinden veri yolu ve adres yolu genişlikleri, bunların kaç bellek gözü adresleyebileceği ve kapasite hesabı konuşulmuştu. Ardından ikilik, onluk ve onaltılık tabanlar arasında hem tam sayılar hem de ondalıklı sayılar için dönüşümler yapılmıştı.

### 1.1 Gösterim tek, yorum komuttan gelir

Bellekte ya da yazmaçta duran şey yalnız bir bit dizisidir. Bu dizinin işaretli mi işaretsiz mi okunacağına komut karar verir. Örneğin sekiz adet 1'den oluşan dizi, işaretsiz sayılarla çalışan bir komut için 255, işaretli sayılarla çalışan bir komut için -1 anlamına gelir. Yani gösterim işaretten bağımsızdır; yorumu komut yapar.

### 1.2 Üç işaretli gösterim

Hoca 4 bitlik sayılar için üç gösterimi bir tablo üzerinden hatırlattı (ekrandan, 00:05:00):

| $b_3b_2b_1b_0$ | İşaretli genlik | Bire tümleyen | İkiye tümleyen |
|---|---|---|---|
| 0111 | +7 | +7 | +7 |
| 0001 | +1 | +1 | +1 |
| 0000 | +0 | +0 | +0 |
| 1000 | -0 | -7 | -8 |
| 1001 | -1 | -6 | -7 |
| 1110 | -6 | -1 | -2 |
| 1111 | -7 | -0 | -1 |

- **İşaretli genlik (sign and magnitude):** En yüksek anlamlı bit işaret bitidir (1 ise negatif, 0 ise pozitif). Kalan bitler sayının genliğidir. `0000` ve `1000` aynı değere, sıfıra karşılık gelir; bir gösterim boşa gider.
- **Bire tümleyen:** En yüksek bit yine işarettir. Sayı pozitifse kalan bitler olduğu gibi genliği verir; negatifse kalan bitlerin bire tümleyeni alınarak genlik bulunur. Burada da iki sıfır vardır: `1111` için kalan `111`'in tümleyeni `000` olduğundan `1111` de sıfırdır.
- **İkiye tümleyen:** En yüksek bit işarettir; negatif sayının genliği ikiye tümleyenle bulunur. İkiye tümleyen, bire tümleyen alıp 1 eklemekle ya da pratik yoldan, sağdan ilk 1'e kadar (o 1 dahil) bitleri olduğu gibi bırakıp gerisini terslemekle hesaplanır. Tekrarlı gösterim yoktur, ama aralık asimetriktir: 4 bitte -8 ile +7 arası.

> **Hocanın vurgusu:** Bilgisayarlarda ve mikroişlemcilerde işaretli sayı aritmetiğinde ikiye tümleyen mantığı kullanılır.

### 1.3 Karakterler ve BCD

Alfanümerik karakterlerin gösterimi için ASCII ve Unicode hatırlatıldı. BCD formatında her ondalık basamak 4 bitle yazılır. 526 sayısı BCD'de 5, 2 ve 6 rakamlarının 4 bitlik karşılıklarıyla toplam 12 bit tutar. Aynı sayı doğrudan ikiliğe çevrilirse $2^9 = 512 \le 526 < 1024$ olduğu için 10 bit yeter.

### 1.4 Bellek gözü, word ve double word

Bu ders boyunca, aksi belirtilmedikçe, 8086'da her bellek adresinde 8 bit veri tutulduğu kabul edilir. Temel veri birimi byte'tır. İki byte'lık veri word (16 bit) olur ve fiziksel olarak iki bellek gözünü kaplar. Double word 32 bittir ve dört gözü kaplar.

### 1.5 Little endian ve big endian

8086 veriyi little endian biçiminde saklar. 32 bitlik `12345678H` sayısı 100H adresinden itibaren yazılırken en düşük anlamlı byte en düşük adrese gider (ekrandan, 00:10:00):

| Adres | İçerik |
|---|---|
| 00103H | 12H (yüksek anlamlı byte) |
| 00102H | 34H |
| 00101H | 56H |
| 00100H | 78H (düşük anlamlı byte) |

Bu veriye "100H adresindeki double word" diye erişilir. Big endian'da ise yüksek anlamlı byte düşük adrese yazılır ve adres arttıkça daha düşük anlamlı byte'lar gelir.

Tek ve çift duyarlıklı kayan noktalı sayılara da değinilmişti, ama 8086'da kayan noktalı komutlar olmadığı için ayrıntıya girilmedi.

## 2. Mikroişlemcinin İç Yapısı ve 8086 Yazmaçları

### 2.1 Dört temel kavram

Bir mikroişlemcinin içinde mutlaka şunlar sayılmalıdır:

- **Yazmaçlar (register grubu):** Veri ve işlem sonuçlarını saklar, çeşitli komutlarda yardımcı görev alır. Genel amaçlı yazmaçların yanında segment yazmaçları ve instruction pointer gibi özel yazmaçlar vardır.
- **ALU (aritmetik lojik birim):** Bütün aritmetik ve lojik işlemlerin yapıldığı çekirdek.
- **Kontrol birimleri:** Dışarıyla veri alışverişini sağlayan bus kontrol birimi ve içerideki işlemleri yürüten yürütme birimi (execution unit).
- **Yollar:** Dış dünyaya bağlantıyı, yazmaçlar arası ve ALU ile veri transferini sağlar.

### 2.2 8086 yazmaçları

Hoca yazmaçları dört grupta gösterdi (ekrandan, 00:15:00):

- **Genel amaçlı yazmaçlar:** AX (AL, AH), BX (BL, BH), CX (CL, CH), DX (DL, DH), SI, DI, SP, BP. AX-DX'e 8 ve 16 bitlik erişim vardır; SI, DI, SP, BP'ye yalnız 16 bitlik erişim vardır.
- **Segment yazmaçları:** SS (stack segment), CS (code segment), DS (data segment), ES (extra segment).
- **Özel amaçlı yazmaç:** IP (instruction pointer).
- **Bayrak yazmacı:** CF, PF, AF, ZF, SF, TF, IF, DF, OF.

Adları: AX akümülatör, BX base register, CX count register, DX data register, SI source index, DI destination index, SP stack pointer, BP base pointer.

### 2.3 AX: akümülatör

Akümülatör, ALU'dan çıkan işlem sonuçlarının saklandığı özel bir yazmaçtır. Ayrıca akümülatöre özel komutlar vardır: aynı işlem herhangi bir genel amaçlı yazmaçla da yapılabilir, ama akümülatörle yapılırsa hem daha kısa sürer hem de komut bellekte daha az yer kaplayabilir. Çarpma ve bölmede AX (ya da AL) gizli operanddır: komutta açıkça yazılmaz ama işlem onun üzerinden döner. Giriş-çıkış komutlarında da kullanılır; bu, mikroişlemciler dersinin konusudur.

### 2.4 BX, CX ve DX

BX dizi erişiminde kullanılır. Dolaylı adreslemede adres değeri bir yazmaçta tutulur ve bellek gözüne bu yazmaç üzerinden erişilir. Bu, C'deki `dizi[i]` erişimine karşılık gelen bir yapıdır.

CX döngülerde tekrar sayısını tutar. Önce CX'e bir değer atanır, sonra `LOOP` komutu kullanılır. Her döngü adımında CX otomatik olarak bir azaltılır ve `LOOP` satırında kontrol edilir: CX sıfırsa döngü biter, değilse `LOOP`'un gösterdiği etikete dallanılır. Kaydırma ve döndürme (shift, rotate) işlemlerinde tekrar sayısı için CL kullanılır. Yazmaçlar en fazla 16 bit olduğundan anlamlı kaydırma en fazla 16 adımdır ve bu değer 8 bitlik bir yazmaca sığar.

DX çarpma ve bölmede gizli operanddır. Giriş-çıkış komutlarında port numarası 8 bite sığmıyorsa, yani komut içinde doğrudan verilemiyorsa, port adresi DX üzerinden verilir.

### 2.5 EXE programlarında üç blok ve yığın

EXE tipi programlarda üç ayrı blok tanımlanır:

- **Veri segmenti:** Değişken tanımları burada yapılır; genişliği tanımlanan veri miktarına bağlıdır.
- **Yığın segmenti:** Program işletim sisteminden çağrıldığında işletim sistemine dönüş adresi yığında tutulur; en önemli görevi budur. Alt programlara dallanıldığında ana programa dönüş adresleri de yığına yazılır. Yığın bazı algoritmalarda veri yapısı olarak ve alt programlara veri aktarmak için de kullanılır. Yığının boyutu baştan verilir; daha fazla veri atılırsa hemen ardından gelen kod segmentindeki yerler bozulabilir.
- **Kod segmenti:** Komutların makine kodu karşılıkları burada saklanır.

MOV gibi veri erişim komutları varsayılan olarak veri segmentini kullanır. `PUSH` ve `POP` gibi yığın komutları stack segmentini kullanır; bu segment içindeki konumu stack pointer belirler.

### 2.6 SP ve BP

Yığın alanı belirlendiğinde SP başlangıçta bu alanın en yüksek adresini gösterir. Yığına bir şey atıldıkça SP iki azalır, yığından çekildikçe iki artar. "Yığına atmak" deyince adres artıyormuş gibi anlaşılabilir; fiziksel olarak durum tersidir. SP her zaman çift değer gösterir ve ikişer değişir, çünkü yığına yalnız word tipinde veri atılır ve yığından yalnız word çekilir.

BP de SS ile birlikte kullanılır. Ana program alt programa parametreleri yığın üzerinden aktardığında, alt programa girer girmez SP değeri BP'ye kopyalanır. Alt program içinde yapılan her yığın işlemi SP'yi değiştireceği için sabit bir referans gerekir. Dönüş adresinin ve kaç parametre atıldığının bilindiği durumda parametrelere BP'ye göre sabit uzaklıklarla erişilebilir.

### 2.7 SI ve DI: katar işlemleri

Katar (string) işlemleri; bir byte dizisini bir adres aralığından başka bir aralığa kopyalamak, iki bloğun aynı indisli elemanlarını karşılaştırmak ya da bir bloğu sıfırlamak veya sabit bir değerle doldurmak gibi işlemlerdir. SI kaynak dizinin, DI hedef dizinin sıradaki gözünü tutar. Dizi komutu CX kez tekrarlanır; bu yüzden önce CX'e değer atanır ve işlemin artan mı azalan adreslere doğru mu yapılacağı belirtilir. Örneğin her byte kopyalandıktan sonra SI ve DI birer artırılır ve CX sıfır olana kadar devam edilir. SI, başka işlerde BX'te tutulan bir başlangıç adresine göre indis olarak da kullanılabilir.

## 3. Segment Yazmaçları ve Fiziksel Adres

8086 16 bitlik bir mikroişlemcidir: yazmaçları da veri yolu da 16 bittir. Fakat 20 adres ucu vardır. Dolayısıyla 16 bitlik yazmaçlardaki değerlerden 20 bitlik bir adres üretmek gerekir. Bu iş offset memory model ile yapılır:

$$PA = Segment \times 10H + Offset$$

16 bitlik bir değeri 10H ile çarpmak sonuna onaltılık bir 0 eklemek, yani 4 bit sola kaydırmaktır; sonuç 20 bite çıkar. Offset 16 bit olduğundan 0000H ile FFFFH arasında $2^{16}$ = 64K farklı değer alır. Bu yüzden her segment yazmacı, başlangıç adresinden itibaren 64 KB'lık bir alanı temsil eder; bu alan içindeki gezinme offset yazmaçlarıyla yapılır. Bu işi işlemcideki özel bir donanım yapar: bir yazmacı 4 bit kaydırıp diğerini ekler.

Slayttaki örnek (ekrandan, 00:30:00):

- Verilen: DS = 1230H, SI = 0045H.
- İşlem: $1230H \times 10H = 12300H$.
- Sonuç: $12300H + 0045H = 12345H$.

Varsayılan eşleşmeler (ekrandan, 00:30:00):

- **CS:** IP ile kullanılır. Hangi komutun yürütüleceği CS ve IP ile bulunur.
- **DS:** BX, SI, DI ile kullanılır. MOV gibi veri erişim komutlarında köşeli parantez içinde yalnız bu üç yazmaç kullanılabilir.
- **ES:** DS gibi, BX, SI, DI ile kullanılır.
- **SS:** SP ve BP ile kullanılır. SP'yi işlemci yığın işlemleriyle otomatik değiştirir; BP'yi programcı sabit referans için kullanır.

> **Hocanın vurgusu:** Köşeli parantez içinde dolaylı adresleme yaparken veri erişimi için yalnız BX, SI ve DI kullanılabilir. Köşeli parantez içine AX yazılamaz; bunu mutlaka aklınızda tutun.

## 4. Instruction Pointer ve Bayraklar

### 4.1 Instruction pointer

IP özel amaçlı bir yazmaçtır; programcı ona asla değer atayamaz, değerini yalnız işlemci belirler. IP sıradaki komutu gösterir. Bir komut yürütüldükten sonra IP, o komutun byte sayısı kadar artar; örneğin 4 byte'lık bir komuttan sonra IP'ye 4 eklenir. Aynı kod segmenti içinde başka bir noktaya dallanılırsa IP doğrudan hedef adresi alır. Görece dallanmada ("5 birim geri" ya da "10 birim ileri" gibi, işaretli sayı olarak) IP'ye bu kayma eklenir ya da çıkarılır.

### 4.2 Bayraklar

- **CF (carry flag):** Elde bayrağıdır; çıkarmada borç (borrow) bayrağı olarak görev alır. İşaretsiz sayılarla yapılan işlemin sonucu yazmaç genişliğine (8 ya da 16 bit) sığmazsa 1 olur. Kısaca işaretsiz sayılardaki taşmayı gösterir.
- **PF (parity flag):** Eşlik bayrağıdır, denetim amaçlıdır. Seri haberleşmede bir girişim bir biti bozabilir; gönderilen eşlik biti ile alıcıda hesaplanan eşlik karşılaştırılarak bu fark edilir. Çift eşlikte veri bitleri ile eşlik bitindeki 1'lerin toplam sayısı çift olmalıdır.
- **AF (auxiliary flag):** Yardımcı bayraktır. 8 bitlik toplama ya da çıkarmada düşük anlamlı 4 bitten 5. bite elde geçerse 1 olur. BCD işlemlerinde anlamlıdır: iki BCD basamağın toplamı 9'u aşabilir ve iki BCD basamak gerektirebilir; bu durumda sonuç ikilikten BCD'ye düzeltilmelidir.
- **ZF (zero flag):** İşlem sonucu sıfırsa 1 olur.
- **SF (sign flag):** İşlem sonucu negatifse 1 olur.
- **TF (trap flag):** Her komuttan sonra kesme oluşmasını sağlar (ekrandan, 00:45:00). Bu bayrak 1 yapılırsa işlemci her komuttan sonra tanımlı kesme alt programına dallanır. Bu alt program ekranda bütün yazmaçların değerlerini gösterip bir tuşa basılmasını bekleyebilir; böylece adım adım hata ayıklama yapılır.
- **IF (interrupt enable flag):** İşlemcinin fiziksel INTR (interrupt request) ucundan gelen kesme isteklerinin değerlendirilip değerlendirilmeyeceğini belirler. IF 1 değilse dışarıdan ne kadar kesme isteği gelirse gelsin karşılık bulmaz.
- **DF (direction flag):** Dizi işlemlerinde başlangıç adresinden itibaren artırarak mı azaltarak mı ilerleneceğini belirler. DF = 0 ise her işlemde SI ve DI artar; DF = 1 ise azalır. Bu yüzden SI ve DI'nin dizinin başını mı sonunu mu göstermesi gerektiği DF ile doğrudan ilişkilidir.
- **OF (overflow flag):** İşaretli işlemlerde sonuç veri genişliğine sığmazsa 1 olur.

### 4.3 Overflow örneği

AL'de 100, AH'de 100 olsun ve iki yazmaç işaretli olarak toplansın (`ADD AL, AH`):

- 8 bit işaretli sayıların aralığı -128 ile +127'dir.
- $100 + 100 = 200 > 127$, sonuç sığmaz.
- Sayıları bir çember üzerinde düşünürsek +127'den sonra -128 gelir. 200'ün 8 bitlik gösterimi işaretli olarak $200 - 256 = -56$ okunur (ara adım eklendi).

İki pozitif sayının toplamı negatif görünüyorsa ya da iki negatif sayının toplamı pozitif çıkıyorsa taşma olmuştur.

> **Ders sonrası not:** Hoca bu örnekte "işaretli sayılarda ADD komutu tam yürümez" dedi. ADD aynı bit işlemini hem işaretli hem işaretsiz sayılar için yapar; işaretsiz taşmayı CF, işaretli taşmayı OF gösterir. Bu örnekte OF = 1 olur, CF = 0 kalır (200 işaretsiz olarak 8 bite sığar).

## 5. 32 ve 64 Bitlik İşlemcilerde Yazmaçlar, Real ve Protected Mode

### 5.1 Extended yazmaçlar

80386 ve sonrasında 32 bitlik yazmaçlar gelir ve "extended" kelimesinden E harfiyle adlandırılır. 32 bitlik bir genel amaçlı yazmaçta en düşük 8 bite (AL), bir sonraki 8 bite (AH), düşük 16 bite (AX) ya da yazmacın tamamına (EAX) erişilebilir. Bunun dışında erişim yoktur: yüksek anlamlı 16 bitin özel bir adı yoktur. Ona ulaşmak için EAX 16 bit sağa kaydırılır, sonra AX, AH, AL üzerinden erişilir. Hoca, dönemin sonunda Windows'ta Visual Studio ya da Linux tarafında 32 bitlik assembly yazılacağını, orada SI gibi 16 bitlik bir yazmaç yerine ESI kullanılacağını söyledi.

### 5.2 Real mode ve protected mode

8086 real mode'da çalışır. 20 adres ucu olduğu için $2^{20}$ bellek gözü adresleyebilir: $2^{10}$ = 1K, $2^{20}$ = 1M. Her göz 1 byte olduğundan erişim kapasitesi 1 MB'tır. Real mode'da program belleğin herhangi bir adresine erişebilir; işletim sistemi varsa onun verisine ya da koduna erişip bozabilir.

80386'dan itibaren protected mode gelir. Protected mode'da her programın kullanacağı bellek bölgesi bir tablo üzerinden verilir ve her program için erişim izinleri tanımlanır. Program yalnız kendisine ayrılan alan içinde çalışabilir, dışına çıkamaz.

> **Ders sonrası not:** Hoca protected mode'daki tablonun FS ve GS yazmaçlarıyla gösterildiğini söyledi. Protected mode'da büyük olasılıkla bütün segment yazmaçları (CS, DS, SS, ES, FS, GS) tanımlayıcı tablosuna bir seçici (selector) tutar; FS ve GS 80386 ile gelen iki ek segment yazmacıdır.

### 5.3 64 bitlik yazmaçlar

64 bitlik işlemcilerde yazmaçlar R harfiyle başlar (ekrandan, 00:50:00): RAX yazmacın tamamı, EAX düşük 32 biti, AX düşük 16 biti, AL en düşük byte'ı, AH ikinci byte'ı gösterir. RBX, RCX, RDX de aynı yapıdadır. Ayrıca RSI, RDI, RSP, RBP, RIP, RFLAGS ve yeni genel amaçlı R8-R15 yazmaçları vardır; FS ve GS de bulunur. 64 bitlik programda SI yazmacı yoktur, RSI kullanılır.

### 5.4 Vektör yazmaçları ve SIMD

32 ve 64 bitlik işlemcilerde toplu işlemler için vektör yazmaçları vardır. Bunlar üzerinde SIMD (single instruction multiple data) komutları çalışır: tek bir komut çok sayıda veriye uygulanır. 64 bitlik işlemcilerde örneğin 512 bitlik vektör yazmaçları vardır ve bunlardan çok sayıda bulunur. Bir byte 8 bit olduğundan 512 bitlik bir yazmaca 64 byte sığar. İki dizinin 64'er elemanı iki vektör yazmacına konup aynı indisli elemanlar tek komutla toplanabilir. Derleyicide uygun optimizasyon bayrakları açılınca kod için vektör komutları üretilebilir; C/C++ tarafında vektör yazmaçlarını açıkça kullanmaya izin veren kütüphaneler de vardır. Assembly'de ise veri bu yazmaçlara açıkça atanır. En geniş (512 bit) yazmaç Z, onun düşük 256 biti Y, düşük 128 biti X diye adlandırılır. Bu konu ders kapsamında değildir.

> **Ek bilgi (derste anlatılmadı):** Intel'de bu yazmaçlar XMM (128 bit, SSE), YMM (256 bit, AVX) ve ZMM (512 bit, AVX-512) diye adlandırılır. Altyazıda "x, y, z" olarak geçen adlar büyük olasılıkla bunlardır.

## 6. Basit Bir İşlemcide Kontrol Birimi

Geçen haftanın son slaytında kalan kontrol birimi, şematik bir işlemci üzerinden anlatıldı (ekrandan, 01:00:00). Bu şema bütün mikroişlemciler için birebir geçerli değildir, ama işleyişi anlamak için önemlidir.

- Komutlar **instruction memory**'de saklanır. Sıradaki komutun adresini **PC** (program counter; 8086'daki karşılığı IP) gösterir.
- Bu adresteki komut **instruction decoder**'a aktarılır. Decoder lojik devrelerle kontrol işaretlerini üretir: register file adresleri (DA, BA, AA), MUX B ve MUX D seçimleri (MB, MD), ALU işlevini seçen FS, bellek yazma (MW), yazmaç yazma (RW) ve dallanma işaretleri (PL, JB, BC).
- Örneğin sonucun tekrar yazmaca yazılıp yazılmayacağını RW ucu belirler. Toplama mı çıkarma mı yapılacağını 4 bitlik FS (function select) belirler.
- Bir yazmaçtaki değeri veri belleğine yazmak için yollar izlenir: veri yalnız B yolu üzerinden belleğe gidebilir. Bu yüzden BA ile kullanılacak yazmacın adresi verilir, MUX B yazmaçtan gelen veriyi seçecek şekilde ayarlanır ve MW anlamlı değeri alır.

Hoca örnek olarak `MOV [100], AX` komutunu verdi: AX'teki değeri 100 numaralı bellek gözüne yazmak için decoder BA için AX'in adresini, MB için 0, MW için 1 üretir; diğer işaretler don't care ya da uygun 0 değerleridir.

Sıradaki komut bir dallanma komutuysa **branch control** devreye girer. PC'nin yürütülen komutun boyu kadar mı artacağına, yeni bir değer mi yükleneceğine ya da görece bir kaymanın mı ekleneceğine bu birim karar verir. Kısacası kontrol birimi instruction decoder, program counter ve branch control'den oluşur; instruction memory bu bloğun dışındadır.

## 7. 8086 Komut Yapısı

Aradan sonra yeni konuya geçildi. Bu bölümde komut türleri, komut tanımlarında kullanılan kısaltmalar, veri aktarım komutları ve sonraki haftalarda aritmetik, dallanma (özellikle koşullu dallanma), CALL ve RET komutları görülecekti.

### 7.1 Genel biçim

Bir 8086 komut satırının genel biçimi (ekrandan, 01:25:00):

```text
{Etiket :} Mnemonic {{Operand1,} Operand2} {; Açıklamalar}
```

Her komutun assembler'ın anlayacağı bir kısaltması vardır; buna **mnemonic** denir. Örneğin toplama için `ADD`. Süslü parantezler isteğe bağlı kısımlardır.

- **Operand almayan komut:** `NOP` (no operation). Hiçbir işlem yapmaz, işlemciyi bir döngü boyunca bekletir.
- **Tek operandlı komut:** `MUL AX`. Mnemonic multiplication'dan gelir. MUL, verilen parametreyi AX ile çarpar. Burada parametre de AX olduğu için komut AX'in karesini alır. İki 16 bitlik sayının çarpımı 32 bite sığar; sonuç DX ve AX yazmaçlarında birlikte saklanır. AX ve DX gizli operandlardır.
- **İki operandlı komut:** `ADD AX, BX`. İlk parametre aynı zamanda sonucun yazılacağı yerdir: AX ile BX toplanır, sonuç AX'e yazılır.

`MUL BX` yazılsa AX ile BX çarpılır ve sonuca DX de katılır; üç parametre varmış gibi görünür ama ikisi gizlidir. Açıkça yazılan operand sayısı 8086'da en fazla ikidir.

`ADD AX, [BX+SI+100H]` da iki operandlı bir komuttur. Köşeli parantez içindeki toplama geçerli bir aritmetiktir ve bir offset üretir; tek başına bir operand sayılır. Veri işlemlerinde varsayılan segment DS olduğundan işlemci DS'yi 4 bit sola kaydırır, buna BX+SI+100H'ı ekleyip fiziksel adresi bulur ve o gözdeki değeri AX'e ekler.

**Soru:** Önceki örnekte 10H ile çarpınca sağa dört 0 ekleniyordu (bir onaltılık basamak). Burada 100H eklenince neden öyle olmuyor?
**Cevap:** Köşeli parantez içindeki değer bir offsettir, segment değeriyle karıştırılmamalıdır. 10H ile çarpılan DS yazmacıdır; işlemci DS×10H'ye köşeli parantez içindeki BX+SI+100H değerini ekler.

### 7.2 Açıklama ve etiket

Noktalı virgülden sonra satır sonuna kadar yazılanları assembler dikkate almaz; bunlar açıklamadır. Etiket, adın sonuna iki nokta üst üste konarak tanımlanır ve dallanma hedefi olarak kullanılır. Hocanın slayta yazdığı örnek (ekrandan, 01:35:00):

```asm
START: NOP                    ; bir işlem yapmaz
       MUL AX                 ; AX'in karesini alır
       ADD AX, BX
       ADD AX, [BX+SI+100H]   ; DSx10H+(BX+SI+100H), baz + indis + göreli adresleme
       JMP START
```

Komutlar yukarıdan aşağı sırayla yürütülür; dallanma varsa etiketin gösterdiği adrese gidilir. Bu kod algoritma olarak anlamsız, ama sözdizimi olarak geçerli bir sonsuz döngüdür. İki operand varsa aralarına virgül, etiketten sonra iki nokta üst üste, açıklamadan önce noktalı virgül konmalıdır.

### 7.3 Operand sayısı ve tip uyumu

Slayttaki özet (ekrandan, 01:40:00):

- 80x86'da operand almayan, tek operand alan ve iki operand alan komutlar vardır. Üç operandlı komutlar yalnız 80x86 ailesinin üst serilerinde vardır; ders 8086 üzerinden yürüyeceği için üç operandlı komut görülmeyecek.
- Operand1 ← Operand1 **işlem** Operand2.
- Operandlar aynı tipte olmalı ya da uygun sözde komutla dönüşüm yapılmalıdır.

`ADD AX, AL` hatalıdır: 16 bitlik bir yazmaç ile 8 bitlik bir yazmaç işleme sokulamaz. `MOV AL, BX` de hatalıdır: 16 bitlik değerin 8 bitlik yere nasıl taşınacağı işlemcide tanımlı değildir.

### 7.4 BYTE PTR ve WORD PTR

Bellekte şu değerler olsun (ekrandan, 01:40:00):

| Adres | İçerik |
|---|---|
| 101H | 09H |
| 100H | FFH |

`INC [100H]` komutu belirsizdir: 100H'dan itibaren bir byte mı yoksa bir word mü artırılacağı belli değildir. Bu yüzden boyut açıkça yazılır:

- `INC BYTE PTR [100H]`: 100H'daki byte artırılır. $FFH + 1$ sonucunda 100H'da 00H kalır.
- `INC WORD PTR [100H]`: 100H'dan itibaren yerleşik word artırılır. Little endian'a göre FFH düşük, 09H yüksek anlamlı byte'tır; word değeri 09FFH'dir. $09FFH + 1 = 0A00H$ olur.

> **Ders sonrası not:** Hoca byte artırmada "elde de 1 olur, CF = 1" dedi. Intel belgelerine göre INC komutu CF'yi etkilemez (OF, SF, ZF, AF ve PF'yi etkiler). FFH'nin 00H'ye dönmesi ZF = 1 yapar; CF = 1 elde etmek için `ADD BYTE PTR [100H], 1` gerekir.

**Soru:** 0A00H belleğe yazılıyor mu, yoksa yalnız dönen bir değer mi?
**Cevap:** Operand bir bellek adresi olduğu için bellek güncellenir: 101H'da 0AH, 100H'da 00H olur. Aynı işlem veriyi önce bir yazmaca okuyup yazmaçta yapılsaydı yalnız yazmaçtaki değer değişir, bellek bozulmazdı.

## 8. Komutlardaki Kısaltmalar

Komut tanımlarında şu kısaltmalar kullanılır (ekrandan, 01:45:00):

| Kısaltma | Anlamı |
|---|---|
| acc | Akümülatör (AX) |
| reg | 8 ya da 16 bitlik herhangi bir yazmaç (AL, AH, AX, BX, BL …) |
| regb | 8 bitlik yazmaç (AL, AH, BL, BH, CL, CH …) |
| regw | 16 bitlik yazmaç (AX, BX, CX, DX …) |
| sreg | Segment (kesim) yazmacı |
| mem | Bellek adresi |
| idata | 8/16 bitlik sabit değer (immediate data) |
| disp8 / disp16 | [-128 … 0 … 127] / [-32768 … 0 … 32767] |
| dest / src | Hedef / kaynak |

Yazmaçlar işlemcinin içindedir. Bellek ise işlemcinin dışında ayrı bir bloktur: bellek işlemi için işlemcinin adres uçlarında bir adres üretilir, bu adres bellek biriminin adres uçlarına gider, ilgili göz seçilir ve içeriği veri uçlarından çıkar.

Displacement görece ileri-geri hareket miktarıdır. disp8 işaretli 8 bit sayıdır: bulunulan noktadan en fazla 128 byte geri ya da 127 byte ileri gidilebilir. Daha uzak atlamalar için 16 bitlik displacement gerekir. Bu yüzden 8 bitlik ve 16 bitlik dallanmalar ayrı komutlardır. (Slaytta "scr" yazıyordu; hoca bunun "src", yani source olması gerektiğini söyleyip düzeltti.)

## 9. Veri Aktarım Komutları ve MOV

### 9.1 Komut listesi

Veri aktarım komutları (ekrandan, 01:50:00):

- **MOV:** Bir kaynaktan hedefe veri kopyalar.
- **LEA (load effective address):** Bulunulan segmentte erişilmek istenen verinin pointer'ını (offsetini) döndürür.
- **LDS / LES:** Load data segment / load extra segment.
- **XCHG (exchange):** İki operandın içeriğini değiştirir. Yüksek seviyeli dilde bu iş geçici bir değişkenle üç işlemde yapılırken assembly'de tek komuttur.
- **XLAT / XLATB (translate):** Başlangıç adresi tutulan bir arama tablosunda (lookup table) verilen indisteki değeri döndürür.

> **Hocanın vurgusu:** Veri aktarım komutlarında bayraklar etkilenmez.

Hoca bunu öğrencilere verdiği komut seti (instruction set) belgesinde gösterdi. Belgede her komut için kabul ettiği operandlar, makine kodunun kaç byte olduğu, kaç saat çevrimi sürdüğü, etkilenen bayraklar ve açıklama vardır. MOV için hiçbir bayrak etkilenmez; buna karşılık XOR (iki operandı bit bit XOR'layıp sonucu birinci operanda yazar) SF, ZF, CF gibi bayrakları etkiler.

**Soru:** Bayrakların etkilenmemesi ne anlama geliyor?
**Cevap:** Assembly'de anlamlı bir program için koşullu ve koşulsuz dallanmalar gerekir. Koşullu dallanmalar bayrak durumlarına bakar. Örneğin bir değer diğerinden çıkarılır ve sonuç sıfırsa başka bir kola dallanılır; bu `JZ` (jump if zero) komutu ZF'ye bakar. MOV bayrakları etkilemediği için koşulu üreten komut ile dallanma arasına MOV konabilir, akış bozulmaz. MOV bayrakları bozsaydı onu koşulu üreten komuttan önce koymak gerekirdi.

### 9.2 Mnemonic doğru yazılmalı

Slaytta `MOV : move data` yazıyordu (ekrandan, 01:55:00). Hoca, mnemonic'in `MOV` olduğunu, `MOVE AX, BX` diye bir komut olmadığını vurguladı.

> **Hocanın vurgusu:** Ödevlerde ve projelerde `MOVE` yazılan satır hatalı sayılır. Komut setini yanınızda bulundurun ya da çevrimiçi halini edinin; komutları ve kabul ettikleri operandları oradan kontrol ederek assembly kodu yazın.

### 9.3 MOV kuralları

`MOV dest, src` işlemi dest ← src demektir: kaynaktaki veri hedefe kopyalanır. Kurallar (ekrandan, 01:55:00):

- dest = mem ve src = mem olamaz.
- dest = sreg ve src = sreg olamaz.
- dest = sreg ve src = idata olamaz.
- dest ve src aynı tipte olmalıdır.

**Bellekten belleğe aktarım.** `MOV [100H], [120H]` kesinlikle hatalıdır; 8086 bir seferde bellekten belleğe aktarım yapamaz. 120H'daki içeriği 100H'ya kopyalamak için arada bir yazmaç kullanılır:

```asm
MOV AX, [120H]
MOV [100H], AX
```

**Segment yazmaçları.** `MOV CS, SS` geçersizdir: iki segment yazmacı arasında aktarım yapılamaz. `MOV CS, 100H` de geçersizdir: segment yazmacına doğrudan sabit atanamaz (ekrandan, 02:05:00). Bu, örneğin belleğin en düşük adreslerindeki kesme vektör tablosuna bir şey yazmak gerektiğinde lazımdır; program yüksek segment değerlerinde çalışırken segment yazmacına istenen değer atanmalıdır. Çözüm yine yazmaç üzerinden gitmektir. Hoca slayta şunu yazdı:

```asm
MOV AX, 100H
MOV CS, AX
```

> **Ders sonrası not:** Intel 8086 belgelerine göre CS, MOV komutunun hedefi olamaz; assembler'lar `MOV CS, AX` için büyük olasılıkla hata verir. CS yalnız uzak JMP, CALL, RET ve kesmelerle değişir. Yöntem DS, ES ve SS için geçerlidir: `MOV AX, 100H` ardından `MOV DS, AX`.

**Tip uyumu.** `MOV AX, AL` tip uyumsuzluğundan hata verir; üstelik AL zaten AX'in parçası olduğu için mantık olarak da anlamsızdır. `MOV AX, BL` ile BL'yi AX'in düşük byte'ına yazmak isteniyorsa doğru komut `MOV AL, BL`'dir. Bu komut yalnız AX'in düşük 8 bitini değiştirir, AH'ye dokunmaz; BX de değişmez.

### 9.4 İzin verilen MOV biçimleri

Slayttaki liste (ekrandan, 02:10:00):

- `MOV reg, idata`
- `MOV mem, idata`
- `MOV reg, reg`
- `MOV reg, mem`
- `MOV mem, reg`
- `MOV sreg, reg`
- `MOV sreg, mem`
- `MOV reg, sreg`
- `MOV mem, sreg`

**Yazmaca sabit atama** (ekrandan, 02:10:00):

```asm
MOV DL, 1
MOV BX, 0ABCDH
MOV AL, 01010101B
MOV AH, 'A'
```

`MOV BX, ABCDH` yazılırsa hata alınır: onaltılık sayı harfle başlıyorsa bir etiketten ayırt edilebilmesi için başına 0 konmalıdır. Bu 0 sayıyı 20 bite çıkarmaz; assembler bunu yalnız sabit olduğunu anlamak için kullanır, değer yine 16 bittir. Onlu, onaltılı, sekizli, ikili sabitler ve ASCII karakter karşılıkları (`'A'`) yazmaca sabit olarak atanabilir.

**Belleğe sabit atama.** `MOV [100H], 12H` geçerli görünse de verinin boyutu belli değildir. DS×10H + 100H adresine yazılacak verinin tipi açıkça verilmelidir (ekrandan, 02:15:00):

```asm
MOV BYTE PTR [100H], 12H
; (DSx10H+100H) <-- 12H

MOV WORD PTR [100H], 12H   ; 0012H
; (DSx10H+100H) <-- 12H
; (DSx10H+101H) <-- 00H
```

WORD PTR verildiğinde işlemci 12H'yi 0012H olarak anlar ve 101H'a 00 yazması gerektiğini kendisi bilir; bunu ayrıca yazmak gerekmez.

**Yazmaçtan yazmaca** (ekrandan, 02:20:00): `MOV BX, AX` ve `MOV BL, CH` geçerlidir. `MOV IP, AX` geçersizdir; IP'ye dışarıdan değer atanamaz.

**Sabite atama.** `MOV 12H, BYTE PTR [100H]` anlamsızdır; bir sabite değer atanamaz.

**Segment yazmaçlarıyla** (ekrandan, 02:30:00):

```asm
MOV DS, AX            ; sreg, reg
MOV SS, [100H]        ; sreg, mem
MOV BX, CS            ; reg, sreg
MOV [BX+DI+10H], DS   ; mem, sreg
```

`MOV SS, [100H]` veri segmentinin 100H ve 101H offsetlerindeki word'ü okuyup SS'ye yazar. `MOV [BX+DI+10H], DS` 16 bitlik DS'yi o offsete ve bir sonraki adrese yazar. Segment yazmaçları 16 bit olduğu için burada ayrıca tip belirtmek gerekmez.

## 10. Bellek Adresleme Kipleri

Hoca adresleme kiplerini konu sırasında sonra gelmesine rağmen MOV ile birlikte anlattı. `MOV reg, mem` ve `MOV mem, reg` birlikte düşünülür: operandların yeri değiştirilebilir, aşağıdaki bütün bellek biçimleri iki yönde de kullanılabilir. Slayttaki örnekler (ekrandan, 02:20:00):

```asm
MOV [BX], AX       ; dolaylı adresleme
MOV AX, [BX]       ; dolaylı adresleme
MOV AX, [SI]       ; indis adresleme
MOV [DI], AX       ; indis adresleme
MOV [BX+SI], DX    ; baz indis göreli
```

Kiplerin listesi:

- **Doğrudan adresleme:** Offset doğrudan verilir, `MOV BYTE PTR [100H], …`.
- **Dolaylı adresleme:** Adres BX (base register) üzerinden verilir, `[BX]`.
- **İndis adresleme:** Dolaylı adreslemede indis yazmacı kullanılır, `[SI]` ya da `[DI]`.
- **Baz indis (dolaylı) adresleme:** BX'te baz, SI'da indis, `[BX+SI]`.
- **Baz göreli:** Baz + sabit, `[BX+5]`.
- **İndis göreli:** İndis + sabit, `[SI+5]`.
- **Baz indis göreli:** Baz + indis + sabit, `[BX+SI+5]`.

Bunların hepsi bir bellek bölgesinin adresini yazmaçlardaki değerlerden hesaplayan aritmetiktir. Köşeli parantez içinde veri erişimi için yalnız BX, SI, DI ve sabit değer kullanılabilir.

### 10.1 emu8086 denemeleri

Hoca bazı biçimleri emu8086'da denedi (ekrandan, 02:25:00):

- `MOV CX, [SI+5]` geçerlidir ve makine kodu üretir: SI'ya 5 eklenerek offset bulunur, DS×10H'ye eklenir.
- `MOV DX, [BX+SI+5]` ve `[BX+DI+5]` de geçerlidir.
- `[AX]` "wrong parameter" hatası verir; dolaylı adreslemede AX kullanılamaz.
- `[2*SI]` yazıldığında emu8086 hata vermez ama ifadeyi kendince `[SI+2]`'ye çevirir. Hoca bunu emu8086'nın emülasyon için kendince değişiklik yapmasına örnek gösterdi. 8086'da köşeli parantez içinde çarpma yoktur.

SI'nın iki katı offsetteki içeriği CX'e almak için iki komut kullanılır (ekrandan, 02:25:00):

```asm
MOV DX, [SI]
SHL SI, 1      ; SI'yı bir bit sola kaydır: SI = 2*SI
MOV CX, [SI]
```

Bir yazmacı bir bit sola kaydırmak sayıyı 2 ile çarpmaktır.

**Soru:** En anlamlı bitte 1 varsa sola kaydırınca kaybolmaz mı?
**Cevap:** Kaybolur. Shift arithmetic left kullanılsa da en yüksek bit 1, ikinci bit 0 ise sayı negatiften pozitife döner ve overflow olur; bu durumda ikiyle çarpma anlamsızdır ve ek işlemlerle ele alınmalıdır. Bu yöntem yalnız kaydırmada taşma oluşturmayan küçük SI değerleri için geçerlidir.

Adresleme kipleri bununla bitmiyor; burada yalnız veri erişimi için olanlar görüldü. Kod segmenti erişimi gibi diğer kipler sonra işlenecek.

## 11. LEA: Load Effective Address

`LEA regw, mem` komutu bellek operandının kendi segmentindeki offsetini yazmaca yükler: regw ← offset(mem) (ekrandan, 02:40:00).

Hoca bir veri segmenti çizdi: içinde başka tanımlar ve `Mydata DD 12345678H` (define double word) tanımı var. Derlemeden sonra Mydata'nın veri segmentinin 100H offsetine denk geldiği varsayıldı. Little endian yerleşim (ekrandan, 02:40:00):

| Adres | İçerik |
|---|---|
| 103H | 12H |
| 102H | 34H |
| 101H | 56H |
| 100H | 78H ← Mydata |

**`MOV AX, [100H]`:** Burada BYTE/WORD PTR yazılmadı, ama hedef AX 16 bit olduğu için bellekten 16 bit okunacağı anlaşılır. Little endian'a göre 100H düşük, 101H yüksek byte'tır; AX ← 5678H.

**`LEA AX, Mydata`:** Mydata'nın içeriği değil, segment içindeki offseti alınır; AX ← 100H. Bu, C'deki pointer değerine benzer.

**`LEA BX, Mydata` ardından `MOV AL, [BX+3]`:**

- `LEA BX, Mydata` → BX = 100H.
- `[BX+3]` → 100H + 3 = 103H.
- 103H'daki byte 12H'dir; AL ← 12H.

Bu, C'deki pointer aritmetiğine çok benzer: pointer artırılarak veriye erişilir.

> **Hocanın vurgusu:** LEA offset (pointer) döndürür, MOV verilen etiketin içeriğini döndürür. Bu fark dizi, word ve byte işlemlerinde sürekli kullanılacak; net olmalıdır.

**Soru:** `LEA AX, Mydata` yazdık; AX'i BX gibi indis olarak kullanamayız, değil mi?
**Cevap:** Evet. AX köşeli parantez içinde kullanılamadığı için ikinci örnek BX ile verildi. Dolaylı adresleme için LEA ile genellikle BX, SI ya da DI'ye atama yapılır.

**Soru:** `[BX+3]` adresindeki içerik AL yerine AX'e okunsaydı rastgele bir değer mi gelirdi?
**Cevap:** Rastgele değil, 104H'daki değer gelirdi. `MOV AX, [BX+3]` 103H'yı düşük, 104H'yı yüksek byte olarak okur. Hoca 104H'da AAH olduğunu varsayarak sonucu 0AA12H diye yazdı.

**Soru (öğrenci sorusu):** Bellekte 64 bitlik bir veri varsa doğrudan kullanılabilir mi?
**Cevap:** Hayır. 8086'nın yazmaçları ve komutları 16 bittir; 64 bitlik veriyi almak için belleğe dört kez gidilir. 16 bitlik toplama, çıkarma ve çarpma komutları tanımlıdır; 32 ya da 64 bitlik işlemler için fonksiyon yazmak gerekir. Örneğin 32 bitlik toplamada önce düşük 16 bitler toplanır, oradan gelen elde yüksek 16 bitlerin toplamına eklenir.

## 12. LDS ve LES

`LDS` (load data segment register) bir word yazmacı ve bir bellek adresi alır; verilen adresten art arda gelen iki word'ü aktarır. Aynı bellek yerleşimiyle (100H: 78H, 101H: 56H, 102H: 34H, 103H: 12H) hoca şu örneği yazdı (ekrandan, 02:50:00):

```asm
LDS SI, [100H]
; SI <-- 5678H
; DS <-- 1234H
```

- İlk word (100H-101H), little endian'a göre 5678H, operand olarak verilen SI'ya yazılır.
- Sıradaki word (102H-103H), 1234H, DS'ye yazılır.

Bu komuttan sonra programın veri segmenti değişmiş olur. Bir kullanım yeri, belleğin en düşük adreslerindeki kesme vektör tablosuna ulaşmaktır. Bunun için ana programın veri segmentinde uygun tanımlar önceden yapılmalıdır. LDS'nin LEA'dan çok farklı olduğuna dikkat edilmelidir: LEA offset verir, LDS bellekten iki word okur.

`LES` (load extra segment) aynı işi ES ile yapar: ilk word verilen yazmaca, ikinci word ES'ye. Katar işlemlerinde kaynak dizinin başını DS:SI, hedef dizinin başını ES:DI belirttiği için LDS ve LES ile bu adresler tek seferde ilklenebilir; LES ile birlikte DI verilirse hedef tam olarak hazırlanmış olur.

## 13. XCHG ve XLAT

### 13.1 XCHG

`XCHG dest, src` iki operandın içeriğini değiştirir: dest ↔ src. İzin verilen biçimler `XCHG reg, reg`, `XCHG reg, mem` ve `XCHG mem, reg`'dir (ekrandan, 02:50:00).

Örnek: başta AX = 1234H, BX = ABCDH olsun. `XCHG AX, BX` sonrasında AX = ABCDH, BX = 1234H olur. C'de bir geçici değişken ve üç işlem gereken takas, assembly'de tek komuttur.

### 13.2 XLAT / XLATB

XLAT ve XLATB aynı komuttur (translate byte). Doğrudan operandı yoktur; AL gizli operanddır. Yaptığı işlem (ekrandan, 02:55:00):

$$AL \leftarrow DS:[BX + AL]$$

Yani DS:[BX] adresindeki tablonun AL numaralı indisindeki değeri AL'ye kopyalar.

Arama tablosu (lookup table), içeriği önceden hesaplanıp bellekte saklanan bir tablodur; birebir eşleşmesi olan bir sözlük gibi düşünülebilir. Hoca kullanım yeri olarak yedi parçalı göstergeyi (seven segment display) verdi: 1 rakamını göstermek için iki LED yakılır, oysa 1'in ikilik gösteriminde tek bir 1 biti vardır. Göstergeye gönderilecek değer ikilik değerden farklıdır; doğru kod tablonun 1 numaralı indisinden alınır.

Slayttaki örnek (ekrandan, 02:55:00):

```asm
; DS tanımı
...
Dizi DB 1,2,3,4,5,6,7,8
N    DB 8
...
; DS tanım son

LEA BX, Dizi
MOV AL, 5
XLAT          ; AL <-- DS:(BX+5)
```

- `Dizi` byte tipinde 8 elemanlı bir dizidir, `N` eleman sayısıdır.
- `LEA BX, Dizi` → BX tablonun başlangıç offsetini tutar.
- `MOV AL, 5` → indis 5.
- `XLAT` → BX+5 offsetindeki byte AL'ye yazılır. İndis 0'dan başladığı için elemanlar BX+0: 1, BX+1: 2, …, BX+5: 6'dır. Sonuç AL = 6.

Hoca önce "5" deyip hemen "6" diye düzeltti. `DS:(BX+5)` gösterimi geçerli bir adresleme kipi değildir, yalnız işlevi anlatmak için yazılmıştır.

Bu örnekle veri aktarım komutları tamamlandı. Hoca, emu8086'yı ve komut setini indirip derste görülen geçerli ve geçersiz MOV varyasyonlarını denemeyi önerdi: her birinin makine kodunu görmek, geçersiz olanların neden çalışmadığını açıklamak ve aynı işi hangi komut birleşimleriyle yapabileceğini bulmak.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:26:36): İki adet 16 bitlik sayı çarpılırsa sonuç kaç bite sığar?

> **Çözüm:** 32 bite sığar. $(2^{16}-1)^2 < 2^{32}$ olduğundan sonuç DX:AX yazmaç çiftinde saklanır.

**Soru 2** (ekrandan, 01:40:00): 100H'da FFH, 101H'da 09H varken `INC [100H]` neden geçersizdir? `INC BYTE PTR [100H]` ve `INC WORD PTR [100H]` sonrası bellek ne olur?

> **Çözüm:** Boyut belirsizdir. BYTE PTR ile 100H'da 00H olur, 101H 09H kalır. WORD PTR ile word 09FFH'dir; $09FFH + 1 = 0A00H$, yani 100H'da 00H, 101H'da 0AH olur.

**Soru 3** (derste sözlü, 01:56:25): `MOV [100H], [120H]` geçersizdir. 120H'daki içerik 100H'ya kaç adımda, nasıl kopyalanır?

> **Çözüm:** Bir yazmaç üzerinden iki adımda: `MOV AX, [120H]` ve `MOV [100H], AX`.

**Soru 4** (ekrandan, 02:05:00): Segment yazmacına sabit atanamıyorsa bir segment yazmacına 100H nasıl yüklenir?

> **Çözüm:** Önce genel bir yazmaca: `MOV AX, 100H`, sonra `MOV DS, AX` (ES ve SS için de aynı). Hoca örneği CS ile yazdı; CS MOV ile değiştirilemez (bkz. 9.3'teki ders sonrası not).

**Soru 5** (derste sözlü, 02:06:13): BX = ABCDH iken `MOV AL, BL` çalıştırılırsa AX ve BX ne olur?

> **Çözüm:** AL ← BL = CDH; AH değişmez, BX değişmez (ABCDH). AX'in yeni değeri "eski AH" ile CDH'nin birleşimidir.
<!-- BELİRSİZ: AX'in başlangıç değeri altyazıda geçmiyor ve o anın karesi yok; sonuç yalnız düşük byte için verildi. -->

**Soru 6** (ekrandan, 02:10:00): `MOV BX, ABCDH` neden hata verir?

> **Çözüm:** Harfle başlayan onaltılık sayı bir etiket adıyla karışır; başına 0 konmalıdır: `MOV BX, 0ABCDH`. Değer yine 16 bittir.

**Soru 7** (ekrandan, 02:15:00): `MOV [100H], 12H` komutunun sorunu nedir?

> **Çözüm:** Belleğe yazılacak verinin boyutu belirtilmemiştir. `MOV BYTE PTR [100H], 12H` yalnız 100H'ya 12H yazar; `MOV WORD PTR [100H], 12H` 100H'ya 12H, 101H'ya 00H yazar.

**Soru 8** (ekrandan, 02:20:00): `MOV BX, AX`, `MOV BL, CH`, `MOV IP, AX` komutlarından hangisi geçersizdir?

> **Çözüm:** `MOV IP, AX`. IP'ye programcı değer atayamaz, değerini işlemci belirler.

**Soru 9** (derste sözlü, 02:22:30): Köşeli parantez içinde dolaylı adresleme için AX kullanılabilir mi?

> **Çözüm:** Hayır. Veri erişiminde yalnız BX, SI, DI ve sabit kullanılabilir; emu8086 `[AX]` için "wrong parameter" hatası verir.

**Soru 10** (ekrandan, 02:25:00): `[2*SI]` yazılamıyorsa SI'nın iki katı offsetteki word CX'e nasıl alınır?

> **Çözüm:** `SHL SI, 1` ile SI ikiyle çarpılır, sonra `MOV CX, [SI]`. Yalnız kaydırmada taşma olmayan küçük SI değerleri için geçerlidir.

**Soru 11** (ekrandan, 02:40:00): Mydata DD 12345678H veri segmentinin 100H offsetine yerleşmiştir. `MOV AX, [100H]`, `LEA AX, Mydata` ve `LEA BX, Mydata` + `MOV AL, [BX+3]` sonuçları nedir?

> **Çözüm:** `MOV AX, [100H]` → AX = 5678H. `LEA AX, Mydata` → AX = 100H. `LEA BX, Mydata` + `MOV AL, [BX+3]` → BX = 100H, 103H'daki byte okunur, AL = 12H.

**Soru 12** (ekrandan, 02:55:00): `Dizi DB 1,2,3,4,5,6,7,8` için `LEA BX, Dizi`, `MOV AL, 5`, `XLAT` sonrası AL nedir?

> **Çözüm:** AL ← DS:[BX+5]. İndis 0'dan başladığı için 5 numaralı eleman 6'dır; AL = 6.

## Dersin Toparlaması

Dersin ilk yarısı birinci haftanın tekrarıydı: işaretli sayı gösterimleri ve ikiye tümleyenin neden kullanıldığı, BCD, little endian yerleşim, 8086 yazmaçlarının görevleri, $Segment \times 10H + Offset$ ile 20 bitlik fiziksel adres üretimi, bayrakların anlamı, 32/64 bitlik yazmaçlar, real ve protected mode, SIMD ve basit bir işlemcide kontrol biriminin instruction decoder, program counter ve branch control ile nasıl çalıştığı. İkinci yarıda 8086 komut yapısına geçildi: etiket, mnemonic, en fazla iki açık operand ve açıklama; sonucun birinci operanda yazılması; tip uyumu ve BYTE PTR/WORD PTR ile boyut belirtme.

Veri aktarım komutlarından MOV'un kuralları (bellekten belleğe yok, segment yazmacından segment yazmacına yok, segment yazmacına sabit yok, IP'ye atama yok), veri erişimi için adresleme kipleri ve köşeli parantez içinde yalnız BX, SI, DI kullanılabileceği ayrıntılı işlendi. LEA'nın offset, MOV'un içerik döndürdüğü; LDS/LES'in bellekten iki word okuyarak yazmaç ve segment yazmacını birlikte yüklediği; XCHG'nin tek komutla takas yaptığı ve XLAT'ın `AL ← DS:[BX+AL]` ile tablodan değer aldığı gösterildi. Bütün bu komutlar bayrakları etkilemez. Sonraki derste aritmetik komutlara, dallanma komutlarına ve CALL/RET'e geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
