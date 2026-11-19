# Ders 1 Genişletilmiş Notu: Derse Giriş, Sayı Sistemleri ve 8086 Mimarisine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konusu: x86 16 Bitlik Assembly
- 2. Assembly Neden Öğrenilir?
- 3. Kullanılacak Araçlar
- 4. Neden 16 Bit? Mikroişlemci ve Mikrodenetleyici
- 5. Dönem Boyunca İşlenecek Konular
- 6. Mikroişlemcilerin Tarihsel Gelişimi
- 7. Sayı Sistemleri ve Tabanlar Arası Dönüşüm
- 8. İşaretli ve İşaretsiz Sayılar
- 9. Bilgisayarlarda Veri Formatları
- 10. 8086'nın İç Yapısı ve Yazmaçları
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Konusu: x86 16 Bitlik Assembly

Dersin konusu assembly dilidir; daha açık söylemek gerekirse Intel x86 mimarisinin 16 bitlik işlemcileri (8086 ailesi) için olan assembly. Bugün kullandığımız Intel işlemciler 64 bitliktir. İlk işlemciden bu noktaya gelinene kadar hem donanım hem yazılım tarafı çok gelişti. Örneğin eskiden matematik işlemci ayrı bir çip olarak sağlanırdı, bugün işlemcinin içine dahil edilmiştir. Cache seviyesi üçe çıkmıştır ve bunların bir kısmı çipin içindedir. Assembly dili de bu süreçte yeni fonksiyonlarla genişlemiştir.

Bir mikroişlemci üreticisi, ürettiği işlemcinin anlamlı olabilmesi için donanımın yanında bir de assembly dilini sağlamak zorundadır. Assembly, donanımla uyumlu program parçalarını yazabildiğimiz dildir. Üretici kendi işlemcisi için bir C derleyicisi yazmaz; C derleyicilerini üçüncü taraflar sağlar. Derleyicinin yaptığı iş, yüksek seviyeli bir dili assembly'ye çevirmektir. Assembly'ye çevrilen kod da bir assembler ile makine koduna çevrilir. Farklı assembler'lar kullanılabilir, ama genellikle üreticinin tanımladığı çerçevede kalınır.

### 1.1 Derleme zinciri

Derlenen diller için bugünkü hiyerarşi şöyledir:

1. Program yazılır.
2. Programda makrolar (örneğin `#define`) varsa bir ön işlemden geçer; makrolarla tanımlanan şeyler yerlerine yazılır.
3. Kod derlenir ve assembly karşılığına dönüşür.
4. Assembly kodu assembler'dan geçirilir ve donanımın anlayabileceği ikili bir bit dizisine dönüşür.

Bu bit dizileri belirli genişlikteki hafıza bölgelerinde saklanır. Ortaya çıkan makine kodu, çalıştırılacak her assembly komutunun karşılığı ve parametrelerinden oluşur. Komutların uzunlukları ve bir komuttan sonra hangi parametrelerin geleceği komutun içinde tanımlı olduğu için, komutlar peş peşe gelse de birbirine karışmaz. Bir bit dizisinin işlemcide komutlara nasıl çevrildiğini, slaytların sonundaki Bilgisayar Donanımı dersine dokunan kısımda çok basit bir mimari üzerinden gösterecekleri söylendi.

Assembly, bir mikroişlemcinin yapabileceği bütün işlem uzayını tanımlayan bir dil olarak düşünülebilir. C'deki tek bir satır birden fazla assembly satırıyla karşılanabilir.

## 2. Assembly Neden Öğrenilir?

### 2.1 Donanımın yeteneklerini öğrenmek: 1 bitlerini saymak

Hoca konuyu bir soruyla açtı: 16 bitlik bir değişkenin içinde rastgele ya da bir hesaplama sonucunda oluşmuş bir değer var. Bu değerdeki 1 bitlerinin sayısını nasıl buluruz?

Akla gelen ilk yol bir döngüyle bitleri tek tek kontrol etmektir. Bu durumda karmaşıklık bit genişliğiyle orantılıdır; $n$ bitlik bir sayı için $n$ adım gibi. Ama bu iş donanımda da yapılabilir: bir yazmaçtaki 1 bitlerinin sayısını bulan ayrı bir donanım parçası çipin içine yerleştirilebilir ve onu kullanmak için bir assembly komutu sunulabilir. Günümüz işlemcilerinde tam adı *population count* olan `POPCNT` komutu vardır. Bu komut, donanımda kaç saat çevrimi sürüyorsa o sürede, bir yazmaçtaki 1 bitlerinin sayısını tek seferde döndürür.

Demek ki assembly bilmek, arkadaki donanımın desteklediği mantıkları öğrenmek ve bazı işleri daha pratik yapabilmek demektir.

### 2.2 Derleyici ve optimizasyon: Godbolt örneği

Assembly derleyiciyle de yakından ilişkilidir. Hoca bunu Compiler Explorer (godbolt.org) sitesinde gösterdi. Bu site, sunucuda kurulu birçok dil ve derleyiciyle, yazdığınız kodun assembly karşılığını üretir.

Ekrandaki örnekte 1'den `num`'a kadar sayıları toplayan bir C++ fonksiyonu vardı (ekrandan, 00:15:00):

```cpp
int square(int num) {
    int sum=0;
    for (int i=1; i< num; i++)
    {
        sum= sum +i;
    }
    return sum;
}
```

Sağ tarafta x86-64 clang 9.0.0 çıktısı görülüyordu. Döngü, sayaç `[rbp - 12]` ile `num` değeri (`[rbp - 4]`) arasında bir `cmp` karşılaştırması, `jge .LBB0_4` koşullu atlaması ve döngü sonunda `jmp .LBB0_1` ile kurulmuştu. Yani kod birebir dönüştürülmüştü.

Hoca burada bir soru sordu: 1'den $n$'e kadar sayıların toplamının karmaşıklığı nedir? İlk bakışta $n$ gibi görünür. Ama matematikte bu toplamın $\frac{n(n+1)}{2}$ olduğunu biliyoruz; yani toplam sabit sürede ($O(1)$) hesaplanabilir. Peki derleyici bunu anlar mı? Uygun optimizasyon parametreleri verildiğinde anlayabilir ve döngü yerine bu formülü üretebilir. Hoca bununla ilgili izlenmesini tavsiye ettiği bir YouTube kanalının linkini paylaştı.

Buradan çıkan sonuç: Derleyiciler bazı kodları mükemmel biçimde optimize edemeyebilir. Assembly biliyorsak bir kod parçasını alıp inceleyebilir ve hızlandırabiliriz.

### 2.3 Vektör komutları ve performans

Günümüz işlemcilerinde vektör komutları vardır. Bunlar ders kapsamında değildir, ama aynı YouTube kanalının diğer videolarında temel seviyede anlatılmaktadır. Bir komutu birden fazla veri üzerinde çalıştırmak (single instruction multiple data, SIMD) için Intel ailesinin vektör komutları kullanılır. Örneğin bir `char` karakterin 64 ya da 512 tanesini tek seferde işleyebilen komut grupları vardır. Normalde birçok çevrimde yapılan iş bir seferde yapılabilir.

Assembly performans gereken her yerde önemlidir. GPU tarafında da böyledir; orada işlemcilerdeki gibi açık bir assembly verilmez, kapalı bir derleyici ve dil karşılığı verilir, ama temelinde yine assembly vardır.

## 3. Kullanılacak Araçlar

### 3.1 EMU8086

x86 16 bitlik assembly için kullanılabilecek araçlardan biri EMU8086'dır. Adı "emülatör" olsa da aslında bir simülatördür, yani bir benzetim yapar. Bu yüzden ürettiği sonuçlara tam olarak güvenilmez. Hızlıca bir şey denemek, makine kodu karşılıklarını, byte genişliklerini görmek ve algoritmik bir uygulamanın sonucunu görmek için kullanılır.

Hoca örnek bir COM tipi program açıp `emulate` tuşuna bastı. Açılan pencerede her satırın assembly komutu ve makine kodu karşılığı görülür. Örneğin programın başındaki `jmp start` satırı `EB 0C` olmak üzere iki byte yer kaplar (ekrandan, 00:25:00). `view` menüsünden yazmaçlar, ayrıca bayraklar izlenebilir. Komutlar adım adım yürütülür; ileri ve geri gidilebilir, program yeniden yüklenebilir. Çalışma sırasında herhangi bir yazmacın değeri (AX'i word ya da byte olarak) elle değiştirilip etkisi görülebilir.

Hoca neden EMU8086'ya güvenilmediğini şu örnekle gösterdi (ekrandan, 00:25:00): Kaynak kodda `shl ax, 3` satırı vardı. Bu komut 8086'da tanımlı değildir. EMU8086 ise hata vermek yerine bunu üç ayrı `SHL AX, 1` komutuna çevirmişti. Buna bakarak 16 bitlik x86 assembly'de böyle bir komut olduğu sanılabilir, ama bu yanlıştır.

> **Ek bilgi (derste anlatılmadı):** 8086'da öteleme ve döndürme komutlarında sayı ya sabit 1 ya da CL yazmacıyla verilir. Sabit sayıyla birden fazla öteleme (`shl ax, 3` gibi) 80186 ve sonraki işlemcilerde gelmiştir.

### 3.2 DOSBox ve MASM

Esas olarak güvenilecek ortam DOSBox'tır. DOSBox bir DOS emülatörüdür; üzerine kendi assembler'ımızı kurarız. Temel alınan assembler Microsoft Macro Assembler'dır (MASM). Hoca kendi sürümünün büyük olasılıkla MASM 5.0 olduğunu söyledi. MASM, DOSBox açıldıktan sonra kurulur.

DOSBox'ın kendi deposu ya da doğrudan bir sabit disk benzetimi yoktur. Bu yüzden yerel bilgisayardaki bir klasör `mount` komutuyla bir sürücü (örneğin C ya da D) olarak bağlanır. Bunu her açılışta elle yapmak yerine, DOSBox yapılandırma dosyasının `autoexec` bölümüne yazmak gerekir; buraya yazılan komutlar DOSBox açılınca otomatik çalışır. Sürücüler arası geçiş DOS'taki gibi `C:` ya da `D:` yazarak yapılır. Kurulumun ayrıntıları kod yazmaya başlandığında anlatılacak.

### 3.3 Godbolt ve komut kümesi referansı

Üçüncü araç olarak Godbolt sitesi deneme amaçlı kullanılabilir; orada 64 bitlik çıktılar üretilir. Ayrıca hoca bir başvuru kaynağı paylaşacağını söyledi: bütün komutların bulunduğu bir komut kümesi (instruction set) PDF'i. Bu belgede her komutun alabileceği parametreler, makine kodu karşılıkları, yürütme süresi, yaptığı işlem ve etkilediği bayraklar yazılıdır. Komutlar işlendikçe bu tablo örnekler üzerinden kullanılacak.

## 4. Neden 16 Bit? Mikroişlemci ve Mikrodenetleyici

### 4.1 Neden 16 bitlik mimari?

16 bitlik mimari bir dönemlik ders kapsamına sığar. Günümüzdeki 64 bitlik mimariyi bir derse sığdırmaya çalışmak yetmeyebilir; assembly çok çeşitlenmiş ve karmaşıklaşmıştır. 16 bitin bir avantajı da geriye dönük uyumluluktur: 8086 ailesinde görülen komutların çoğunu günümüzün 64 bitlik işlemcileri de destekler.

Amaç, mikroişlemcinin donanımıyla sıkı ilişki içindeki assembly yapısını anlamaktır. Assembly, işlemcinin yazılım açısından yapabileceklerini ve kısıtlarını ortaya koyar. Bu öğrenildikten sonra aynı mimarinin yeni ailelerine genişlemek kolaydır; 64 bitle başlamak daha karmaşık gelebilir.

16 bitlik programlar günümüz bilgisayarlarında doğrudan çalıştırılamaz; bu yüzden emülatör ve simülatör kullanılır. Bugünkü bilgisayarlar 32 ve 64 bitlik komutları destekler, 32 bitlikleri çalıştırmak için bile bazen ek kütüphane kurmak gerekir. Ders 16 bit kapsamında kalacak, ama aynı komutlar 32 ve 64 bitlik sistemlerde de kullanılacak, C'den assembly çağırma ve Linux tarafındaki karşılıklar da görülecek.

**Soru:** x86 dışında bir işlemci hakkında ders olacak mı? **Cevap:** Bu derste yalnız x86 var. Elektronik ve Haberleşme Mühendisliğinde önce Motorola 6800, sonra x86 16 bit teorik olarak, ardından uygulaması görülür. Eğitim sistemi değişince bir de gömülü sistemler dersi geldi; orada mikrodenetleyicilere ilişkin assembly görülebilir.

### 4.2 Mikroişlemci ile mikrodenetleyici farkı

Mikroişlemci tek başına, yalnız enerji verildiğinde çalışabilir durumda değildir. Çalışması için hafıza birimleri, çevre birimleri, saat darbe üreteci, reset devresi, tutucu ve tekrarlayıcı devreler gibi yardımcı birimler gerekir. Mikrodenetleyici ise bu yapıların hepsini kendi bünyesinde barındırır. Mikroişlemciler genel amaçlıdır; mikrodenetleyiciler daha basit işleri yerine getirmek için tanımlanmış, daha özelleşmiş yapılardır.

## 5. Dönem Boyunca İşlenecek Konular

Hoca ders tanıtım formunu paylaşarak haftalık programı anlattı (ekrandan, 00:45:00). Temel kaynak Seçkin Yayıncılık'tan çıkan *80x86 Assembly Dili* kitabının 2. baskısıdır (A. Tevfik İnan); diğer kaynaklar Peter Abel, Walter A. Triebel ve Barry Brey'in kitaplarıdır (ekrandan, 00:40:00). Hoca, derste yanlış bir şey söylenirse doğrunun bu kitaba bakılarak belirleneceğini vurguladı.

Konular ve hocanın her biri için verdiği açıklamalar:

- **Alt seviye programlamanın özellikleri, sayı ve kodlama sistemleri, x86 ailesi, yazmaçlar ve bayraklar:** bu haftanın konusu.
- **Veri aktarma, aritmetik ve dallanma komutları:** x86 assembly'nin kapasitesi ve kodlamada uyulması gereken kısıtlar görülecek; özellikle dallanma komutlarının nasıl kullanılabileceği.
- **Çevrim komutları:** C'deki `for`, `while`, `do while` yapılarının assembly karşılıkları.
- **Bayrak komutları:** dallanmalar bayraklara bakılarak kurulur.
- **Mantıksal komutlar ve öteleme/döndürme:** bit düzeyindeki işler için gerekir.
- **Katar (string) işlemleri:** bir hafıza bölgesini başka bir bölgeye aktarmak, iki bölgeyi karşılaştırmak, bir bölgeyi belirli bir değerle doldurmak ya da sıfırlamak.
- **Ön ekler:** doğrudan makine kodu karşılığı olmayan, assembler'ın ön işlemle anlam kazandırdığı yapılar (C'deki `define` benzeri).
- **Adresleme modları:** hafızadaki bir göze erişmenin yolları. Her biri için komutun bir varyasyonu vardır. Uygun modu seçmek programı daha etkin yapar; modları bilmek aynı zamanda assembly'nin kısıtlarını bilmek demektir.
- **Programlama araçları, çalışma ortamı ve debug:** debug programı bir programı adım adım çalıştırmayı, her yazmacın değerini görmeyi, sıfırdan assembly komutlarıyla program oluşturmayı ve makine kodunu değiştirmeyi sağlar.
- **EXE ve COM tipi programlar:** EXE tipi daha büyük ve daha geniş program hafızası kullanabilir, ek yükü (overhead) daha büyüktür. COM tipi tek bir segmente sığan kısa ve hızlı işler içindir, ek yükü daha küçüktür.
- **Yordam ve makro, parametre aktarma, ortak kesim ve EXTRN/PUBLIC, kesme ve vektör tablosu, yüksek seviyeli dillerle kullanım.**

### 5.1 İkiye bölme ve bit sayma: öteleme komutlarının önemi

**Soru (hocadan):** x86'da `DIV` komutuyla bölme yapılabiliyor. İkiye bölme işlemini yapmanın en uygun yolu nedir? **Cevap:** `DIV` çok uzun çevrim süren, karmaşık bir komuttur. Bir yazmaçtaki değeri ikiye bölmek için bir kez sağa ötelemek yeterlidir. 2'nin kuvvetlerine bölmede sağa öteleme kullanılır.

Hoca `POPCNT` örneğine de geri döndü: önceki x86 sürümlerinde böyle bir komut yoktur. Assembly'de yazmak için öteleme ya da döndürme komutları kullanılır. Öteleme komutu her çalıştığında en düşük anlamlı bit elde (carry) bayrağına aktarılır. 8 bitlik bir yazmaçta 8 kez döndürme yapıp her seferinde elde bayrağına bakarak 1 bitleri sayılabilir.

### 5.2 Makro ve yordam

Programları tek bir akış olarak yazmak takip edilebilir ve düzenlenebilir değildir. Bu yüzden programlar yordam ve makrolar halinde yazılacaktır.

- **Yordam (procedure):** fonksiyona karşılık gelir. Çağrıldığında tanımlı olduğu yere dallanılır, kod çalışır ve kalınan yere geri dönülür.
- **Makro:** C'deki makronun karşılığıdır. Derleme (assembly) öncesinde, makronun geçtiği her yere makro kodu kopyalanır ve öyle derlenir. Tanım `macro` ile başlar, `endm` ile biter; sonra makro adıyla çağrılır.

**Soru (hocadan):** Makro çağırmak program boyutunu (diskteki makine kodunun boyutunu) artırır mı? Yordam çağırmak artırır mı? **Cevap:** Makro her çağrıldığı yere kopyalandığı için her çağrı kodu makro boyu kadar büyütür; hiç çağrılmazsa makine koduna etkisi yoktur. Yordam ise koda bir kez eklenir; hiç çağrılmasa bile yer kaplar, ama her çağrı ek bir büyüme yaratmaz.

**Soru (hocadan):** Bu durumda makro ne zaman, yordam ne zaman kullanılmalı? **Cevap:** Makronun çağrı maliyeti yoktur, çünkü kod zaten çağrıldığı yere kopyalanmıştır. Yordam çağırırken ise ana koddaki durumu korumak gerekir: o anki yazmaç değerleri yığına atılır, yordama gidilir, dönüşte yığından geri alınır. Yani yordamın bir çağrı maliyeti vardır. Bu yüzden makrolar çağrı maliyetini aşmayacak kadar kısa işler için, yordamlar daha uzun ve karmaşık işler için uygundur.

### 5.3 Parametre aktarma yöntemleri

İleride görülecek parametre aktarma yöntemleri şöyle özetlendi:

- **Yazmaç üzerinden:** Yordamı çağırmadan önce yazmaçlara değer yüklenir. Yordama gidildiğinde bu değerler yazmaçlarda durduğu için yordam içinde kullanılabilir.
- **Ortak hafıza üzerinden:** Alt yordamlar ortak bir veri hafızası kullanacak şekilde tanımlanabilir.
- **EXTRN ve PUBLIC:** Programlar farklı dosyalarda tutulabilir ve ayrı ayrı derlenebilir. Bir modül dışarıdaki `x` değişkenini kullanmak istiyorsa onu `extern` olarak, diğer modül dışarıya kullandırmak istiyorsa `public` olarak tanımlar. İki obje dosyası birlikte bağlandığında (link) bu tanımlar eşleşir. Aynı mantık hafıza bölgeleri için de kurulabilir.
- **Yığın üzerinden:** Çağrıdan önce parametreler bilerek yığına atılır. Çağrıyla birlikte üstlerine dönüş adresi gibi değerler gelir. Yordam içinde bu ek değerlerin boyu hesaplanarak parametrelere erişilir.

Hoca değer ile referans aktarımı konusunda şunu söyledi: Assembly'de aslında her şey değer olarak aktarılır. Bir yazmaç üzerinden bir hafıza bölgesinin adresi de aktarılabilir; bu bir pointer aktarımına denk gelir. Yani bir pointer da aktarılsa onun değeri aktarılmış olur, ama bu bir adres ya da referans aktarımı olarak yorumlanabilir.

> **Ders sonrası not:** Hoca, `CALL` komutunu yürütmeden önce işlemcinin yazmaçların değerlerini otomatik olarak yığına attığını söyledi. Doğrusu: 8086'da `CALL` yalnız dönüş adresini yığına atar (yakın çağrıda IP, uzak çağrıda CS ve IP). Diğer yazmaçları korumak programcının işidir; gerekiyorsa `PUSH` ile yığına atılır, dönüşte `POP` ile geri alınır.

### 5.4 Programda kaç yazmaç kullanılabilir?

**Soru:** Programda kullanabileceğimiz yazmaç sayısını kim belirliyor? **Cevap:** İşlemcinin genel amaçlı yazmaçlarının hepsi kullanılabilir, burada bir kısıt yoktur. Yalnız bazı komutlar belirli yazmaçları varsayılan olarak kullanır. Örneğin `LOOP` komutu her döngüde CX'teki değeri otomatik azaltır; döngüyle CX kullanılmalıdır. Çarpma ve bölme varsayılan olarak AX (akümülatör) ve DX (data) yazmaçlarını birlikte kullanır. Kendi yazdığımız bir yordamın dönüş değerini bir yazmaçta tutuyorsak, ana programda o yazmacı korumamız gerekir. Yüksek seviyeli dillerle birlikte kullanımda, örneğin Visual Studio derleyicisi dönüş değerini mimariye göre AX, EAX ya da RAX'te tutar. Varsayılan yazmaçlar bozulmadığı sürece istenen yazmaç istenen yerde kullanılabilir.

> **Ders sonrası not:** Hoca Linux tarafında 7 parametrenin 7 farklı yazmaçla döndürüldüğünü, fazlasının yığından geçtiğini söyledi. Doğrusu: Linux x86-64 çağrı kuralında (System V) ilk 6 tam sayı parametre RDI, RSI, RDX, RCX, R8 ve R9 yazmaçlarıyla aktarılır, fazlası yığından geçer. Dönüş değeri RAX'tedir.

### 5.5 Kesme yapısı

Bir tuşa basılmasını beklemenin iki yolu vardır:

- **Yoklama (polling), aktif bekleme:** Program düğmeleri okur, değer sıfır mı diye bakar, değilse başa dönüp yeniden okur.
- **Kesme:** Düğmenin ürettiği sinyal fiziksel bir kesme ucuna bağlanır ve düğme bir kesme numarasına (örnekte 10) atanır. Programda 10 numaralı kesme oluştuğunda yapılacak işler tanımlanır. Ana akış ekran sürme, klavye okuma gibi işlerle devam ederken düğmeye basıldığı anda bu işler kesilir, 10 numaralı kesme vektörünün alt programına dallanılır, düğmeye ilişkin işler yapılır ve kalınan yere dönülür. Aktif bekleme yoktur.

Kesmelerin donanımda nasıl oluşturulduğu, nasıl programlandığı ve alt yordamlarının nasıl yazıldığı ilerleyen haftalarda görülecek. O noktadan sonra programlar kesmeler aktif kullanılarak yazılacak.

### 5.6 Yüksek seviyeli dillerle birlikte kullanım

Son konu, assembly programlarının C ile birlikte kullanımıdır: Visual Studio'da bir assembly dosyasındaki fonksiyonun C'den çağrılması, assembly'den C fonksiyonu çağrılması, benzer işlerin Linux tarafında yapılması. Bunlar büyük olasılıkla hem 32 hem 64 bitlik programlar üzerinden incelenecek.

Arada hoca, assembly'nin doğrudan kullanıldığı yerlere de örnek verdi. Borsa işlemleri gibi hızın kritik olduğu işlerde derleyici çıktısına güvenmeyip kodu assembly'de iyileştirmek gerekebilir. Mikrodenetleyiciler çoğunlukla assembly ile programlanır. Bir mikrodenetleyicinin derleyicisi üzerinde çalışan topluluk, genel bir C derleyicisininkinden çok daha dar olduğu için derleyici optimizasyonu daha büyük bir soru işaretidir. Android'de Java tabanlı sanal makine üzerinden yazılan bir oyun yerine doğrudan (native) yazılan oyun çok daha performanslı çalışır.

## 6. Mikroişlemcilerin Tarihsel Gelişimi

### 6.1 Intel 4004

Intel'in ürettiği ilk mikroişlemci 4004'tür (ekrandan, 01:30:00). Slayttaki bilgiler: 4 bitlik mikroişlemci, adresleme kapasitesi 4096 x 4 bit, 45 komut, 30 gram ağırlık, saniyede 50000 işlem (30 tonluk ENIAC saniyede 100000 işlem), oyun ve küçük kontrol sistemlerinde kullanıldı, RTL (direnç-transistör lojiği) ile tasarlandı. Sonrasında daha yüksek frekanslı 4040 geliştirildi.

"4 bitlik" demek, yazmaçların ve hafıza gözlerinin 4 bitlik olması, işlemcinin bir seferde 4 bitlik işlem yapabilmesi demektir.

Mikroişlemci hafıza birimleriyle adres uçları ve veri uçları üzerinden haberleşir. Adres uçları hafıza biriminin adres uçlarına doğrudan bağlıdır ve belirli bir gözü seçmeye yarar. İşlemci bir adres ürettiğinde hafızanın o gözüne erişir; gözdeki değer veri uçlarından çıkar ve işlemcinin veri yolu üzerinden yazmaçlara aktarılır.

Hoca bu bilgiyle 4004 üzerinden adres ve veri ucu sayısını sordu (ayrıntılı çözüm Örnek Sorular bölümünde). Sonuç: 12 adres ucu ($2^{12} = 4096$), 4 veri ucu. Buradan donanım ve yazılımın iç içe olduğu görülür: 12 adres ucu varsa, hafızaya erişen bir komut 12 bitlik adresi sağlamak zorundadır.

> **Hocanın vurgusu:** Bir mikroişlemcinin kaç bitlik olduğu yazmaç genişliğiyle ilgilidir, adres ucu sayısıyla değil. 4004'ün yazmaçları 4 bit genişliğindedir ve dışarıdan bir seferde 4 bit veri alır; bu yüzden 4 bitlik bir işlemcidir.

Hoca ayrıca 45 komutu kodlamak için kaç bit gerektiğini sordu (çözüm Örnek Sorular bölümünde: 6 bit).

> **Ders sonrası not:** Hoca saniyede 50000 işlemi "frekansı 50000, yani 50 kHz'lik bir işlemci" diye yorumladı. Saniyedeki işlem sayısı ile saat frekansı aynı şey değildir; bir komut birden çok saat çevriminde yürütülür. 4004'ün saat frekansı büyük olasılıkla 740 kHz civarındadır.

### 6.2 Intel 8008 ve 8080

Slayta göre 1971'de Intel 8008 tanıtıldı: 8 bitlik bir mikroişlemci, 16 KB adresleme kapasitesi, toplam 48 farklı komut. Mikroişlemcilerin daha karmaşık sistemlerde kullanımı mümkün oldu (ekrandan, 01:35:00).

Hoca burada derste kullanılacak bir varsayım koydu: 4004'ten sonrası için, aksi belirtilmedikçe her hafıza gözü 8 bit (1 byte) veri tutar. Bu varsayımla 8008'in adres ve veri yolu genişliği soruldu (çözüm Örnek Sorular bölümünde: 14 adres ucu, 8 bit veri yolu). Bu arada birim ön ekleri hatırlatıldı: ikilik gösterimde K $= 2^{10}$, M $= 2^{20}$, G $= 2^{30}$.

> **Ders sonrası not:** Slaytta 8008'in tanıtım yılı 1971 yazıyor; 8008 büyük olasılıkla 1972'de piyasaya çıktı.

Ardından gelen 8080 de 8 bitlik bir işlemcidir ve 64 KB hafıza kapasitesine sahiptir; TTL teknolojisiyle uyumlu geliştirilmiştir. Bu dönemde Intel dışında başka firmalar da uyumlu işlemciler üretmiştir; hoca ayrıntıya girmedi.

> **Ders sonrası not:** Hoca 8080 için "$2^8 \cdot 2^{10}$, 18 adres ucu" dedi. Doğrusu: $64\text{K} = 2^6 \cdot 2^{10} = 2^{16}$; yani 8080'in 16 adres ucu vardır.

### 6.3 8086 ve 8088

Ders boyunca temel alınacak işlemci 8086'dır; IBM PC'lerde kullanılan hali 8088'dir. Slayttaki bilgiler (ekrandan, 01:40:00): 1978'de 8086, bir yıl sonra 8088 tanıtıldı; 16 bitlik mikroişlemciler; komut yürütme süresi 400 ns (saniyede 2,5 milyon işlem); adresleme kapasitesi 1 MB; 4 veya 6 byte'lık komut kuyruğu; çarpma, bölme gibi komutlar; varyasyonlarıyla 20000'i bulan komut sayısı.

İkisi de 16 bitliktir, çünkü yazmaçları 16 bittir. 16 bitlik yazmaçların 8 bitlik düşük (low) ve yüksek (high) yarılarına da ayrıca erişilebilir. İkisi de 1 MB adresleyebildiği için $1\text{M} = 2^{20}$ olmak üzere 20 adres ucuna sahiptir. Fark veri yolundadır: 8086'nın veri yolu 16 bit, 8088'in 8 bittir. 8088, 16 bitlik bir hafıza erişimi için iki kez erişmek zorundadır; kabaca 8086 veri erişiminde 8088'den iki kat hızlıdır.

#### Komut kuyruğu (prefetch queue)

Hafızaya erişmek en çok zaman alan iştir. 8086 hafızaya gitmişken ardışık birkaç komutu birlikte okuyup işlemcinin içine (kuyruğa) alır; böylece sıradaki komutu yürütürken yeniden program hafızasına gitme maliyetinden kurtulur. Hoca kuyruğun ne zaman çöp olacağını sordu (çözüm Örnek Sorular bölümünde: atlama ve dallanmalarda).

Günümüz işlemcilerinde de kuyruk vardır ve dallanma tahmini (jump/branch prediction) yapılır: çalışacak kodun dallanıp dallanmayacağı yüzde kaç olasılıkla bilinerek kuyruk ona göre doldurulur. Tahmin doğru çalışırsa program her zaman kuyruk kullanıyormuş gibi olur. Hoca, Intel ailesinde yakın zamanda çıkan donanımsal açıklardan birinin bu tahmin mekanizmasındaki bir açığı kullandığını hatırlattı.

> **Ek bilgi (derste anlatılmadı):** Hocanın andığı açıklar büyük olasılıkla 2018'de duyurulan Spectre ve Meltdown'dur; Spectre, dallanma tahminini kötüye kullanarak spekülatif yürütme üzerinden veri sızdırır.

#### CISC yapısı

8086 ve 8088 karmaşık komut kümeli bilgisayar (Complex Instruction Set Computer, CISC) mimarisindedir. Bunu tanımlayan özellikler:

- Çarpma ve bölme gibi karmaşık komutlar vardır; data sheet'e bakıldığında 10, 20-30 saat çevrimi süren işlemler görülür.
- Komut uzunlukları farklıdır; örneğin toplama 2 byte, çarpma 5 byte yer kaplayabilir.
- Komutların yürütme süreleri farklıdır; örneğin bir komut 4 çevrim sürerken çarpma ya da bölme 20-30 çevrim sürebilir.

Bu kadar küçük bir işlemcide bile komut varyasyonu 20000'i bulurken, günümüz işlemcilerinde bu sayı çok daha büyüktür. Bu da dersin 16 bitle işlenmesinin bir başka sebebidir.

### 6.4 80286, 80386 ve 80486

8086'dan sonra 286 gelir ve adresleme kapasitesi artar. 386, 32 bitlik bir işlemcidir; veri yolu ve adres yolu 32 bittir, adresleme kapasitesi 4 GB'tır: $2^{32} = 2^2 \cdot 2^{10} \cdot 2^{10} \cdot 2^{10}$ byte, yani 4 GB.

486'nın slayttaki özellikleri (ekrandan, 01:50:00): 1989'da tanıtıldı, 32 bit adres ve veri yolu, cache kullanımı, DX modelinde matematik işlemci ana işlemciyle birleştirilmiş. Sonrasında Pentium, Celeron, Itanium, Core, Core 2 ve Core i aileleri gelir.

#### Cache

Cache (ön bellek), hafıza hiyerarşisinde yazmaçlardan sonra işlemciye en yakın hafıza birimidir. RAM'den veri yazmaçlara aktarılırken arada tampon görevi görür. RAM'den daha hızlıdır; buna uygun bir teknolojiyle üretilir ve işlem birimine yakındır. Faydası iki tür erişim düzeninden gelir:

- **Uzamsal yerellik (spatial locality):** Bir `for` döngüsüyle dizinin `i` numaralı gözüne erişildiyse, bir sonraki adımda `i+1` numaralı göze erişilecektir. Komşu veriler bloklar halinde cache'e alınırsa, işlemci veriyi önce cache'te arayıp hızla bulur.
- **Zamansal yerellik (temporal locality):** 1'den $n$'e kadar toplam alırken toplamı tutan `sum` değişkenine döngünün her adımında, yani farklı zamanlarda tekrar tekrar erişilir. Bu değişken cache'te tutulursa her seferinde RAM'e gitmek gerekmez.

Cache'teki bir veri değiştirildiğinde RAM'deki karşılığının ne zaman güncelleneceği gibi sorunlar Bilgisayar Donanımı dersinde görülecek.

#### Kayan nokta ve matematik işlemci

8086'da kayan noktalı sayı komutları yoktur. Eskiden genel amaçlı işlemcinin yanında matematik işlemleri için bir yardımcı işlemci (coprocessor) kullanılırdı; 8086'nın yanındaki yardımcı işlemci 8087'dir ve kayan nokta işlemleri onda vardır. Matematik işlemcinin aynı çipe gömülmesi hocaya göre 386 ya da 486'da olmuştur; slayt bunun 486 DX modelinde olduğunu gösteriyor.

## 7. Sayı Sistemleri ve Tabanlar Arası Dönüşüm

### 7.1 İkilik sistem

Mikroişlemci en temel seviyede ikilik (binary) mantıkla, 0 ve 1 olarak değerlendirilen elektriksel seviyelerle çalışır. Tek ikilik sistem bu değildir: Sovyetler döneminde $-5$ V, $0$ V ve $+5$ V gibi üç seviyeli, üçlük (ternary) bir bilgisayar mimarisi de geliştirilmiştir. İkilik sistemde bir basamak (bit, *binary digit*) iki farklı değer tutar ve $n$ bitle $2^n$ farklı değer gösterilir. Üçlük sistemde bir basamak (trit) üç değer tutar ve $n$ tritle $3^n$ değer gösterilir. Bugün ikilik yapı standart haline gelmiştir.

Assembly'de sabitler ikilik (sonuna `B` eklenerek), onluk ve onaltılık tabanda yazılabilir. Bu yüzden tabanları ve tabanlar arası dönüşümü bilmek gerekir.

### 7.2 Rakam, basamak ve konumsal değer

Rakam, ilgili tabandaki tek bir değeri gösteren semboldür. Onluk tabanda 0-9, sekizlik tabanda 0-7, ikilik tabanda 0 ve 1, onaltılık tabanda 0-9 ile A, B, C, D, E, F kullanılır.

Sayı, basamakların yan yana gelmesiyle oluşur ve her basamağın değeri konumuna bağlıdır. Slayttaki örnek (ekrandan, 01:55:00): Onluk tabanda 132 sayısında 2 birler basamağında ($10^0$), 3 onlar basamağında ($10^1$), 1 yüzler basamağındadır ($10^2$):

$$132 = 10^2 \cdot 1 + 10^1 \cdot 3 + 10^0 \cdot 2$$

Diğer tabanlarda da aynı mantık geçerlidir: en düşük anlamlı basamak birler basamağıdır, bir sonraki basamak tabanın birinci kuvvetidir. Bu yüzden aynı "11" rakam dizisi farklı tabanlarda farklı değer taşır:

- $(11)_2 = 2 + 1 = 3$
- $(11)_8 = 8 + 1 = 9$
- $(11)_{10} = 11$

Kesirli sayılarda noktanın sağındaki basamakların ağırlıkları negatif kuvvetlerdir. Onluk tabanda $0.1 = 0 \cdot 10^0 + 1 \cdot 10^{-1} = 0.1$; aynı basamaklar ikilik tabanda $(0.1)_2 = 0 \cdot 2^0 + 1 \cdot 2^{-1} = 0.5$ eder.

### 7.3 Onluktan başka tabana tam sayı dönüşümü

Onluk tabandaki bir sayıyı ikilik tabana çevirmek için sayı ardışık olarak ikiye bölünür. Her adımda kalan, ilgili basamağı verir. İlk bölmenin kalanı en düşük anlamlı basamaktır; sonra bölüm alınıp yeniden bölünerek devam edilir. Sekizlik tabana çevirirken aynı işlem 8'e bölerek yapılır; bölüm tabandan küçük kalınca durulur.

<!-- BELİRSİZ: Onluktan ikilik ve sekizlik tabana tam sayı dönüşüm örneklerinde kullanılan sayılar altyazıdan çıkmıyor ve o anlara ait kare yok. -->

Onaltılık örnek: $(109)_{10}$'un onaltılık karşılığı.

- $109 \div 16 = 6$, kalan $13$. Onaltılık tabanda A = 10, B = 11, C = 12, D = 13 olduğundan en düşük anlamlı basamak D'dir.
- Bölüm $6$, 16'dan küçük olduğu için bölme biter; 6 bir sonraki basamaktır.
- Sonuç: $(109)_{10} = (6D)_{16}$. Kontrol: $6 \cdot 16 + 13 = 109$.

### 7.4 Kesirli sayıların dönüşümü

Kesirli kısmı onluktan ikilik tabana çevirirken tabanla (2) çarpılır. Her çarpımın tam kısmı sıradaki basamağı verir; basamaklar bu kez noktadan sonra soldan sağa yazılır. Kalan kesirli kısımla devam edilir.

Slayttaki örnek: $(0.625)_{10} = (?)_2$ (ekrandan, 02:00:00)

- $0.625$: tam kısım $0$, sonuç $0.$ ile başlar.
- $0.625 \cdot 2 = 1.25$, tam kısım $1$.
- $0.25 \cdot 2 = 0.5$, tam kısım $0$.
- $0.5 \cdot 2 = 1.0$, tam kısım $1$.
- Noktadan sonra $0$'a ulaşıldı, işlem biter: $(0.625)_{10} = (0.101)_2$.

Bazen kesirli kısım hiç sıfır olmaz ve tekrarlı bir sayı çıkar; o zaman sayı yaklaşık olarak yazılır. Hocanın ikinci örneği (sayı altyazıda açıkça söylenmiyor, adımlardan $0.2$ olduğu anlaşılıyor):

- $0.2 \cdot 2 = 0.4$ → $0$
- $0.4 \cdot 2 = 0.8$ → $0$
- $0.8 \cdot 2 = 1.6$ → $1$
- $0.6 \cdot 2 = 1.2$ → $1$
- Kalan yine $0.2$; başa dönüldü.

Sonuç: $(0.2)_{10} = (0.\overline{0011})_2$, yani 0011 grubu sonsuza kadar tekrar eder (python ile doğrulandı).

## 8. İşaretli ve İşaretsiz Sayılar

İşaretsiz sayılarda bütün basamaklar konumsal değerlerine göre değerlendirilir ve sayının genliği hesaplanır. İşaretli ikilik sayılar ise genel olarak üç farklı biçimde gösterilebilir (ekrandan, 02:05:00): işaretli genlik gösterimi, 1'e tümleyen işaretli sayı ve 2'ye tümleyen işaretli sayı. Hoca üçünü 4 bitlik sayılar üzerinden anlattı.

### 8.1 İşaretli genlik gösterimi

En yüksek anlamlı bit (MSB) işareti belirler: 1 ise sayı negatif, 0 ise pozitiftir. Kalan bitler sayının genliğidir.

- $(0011)_2$: MSB 0, sayı pozitif; genlik $011 = 3$; değer $+3$ (ekrandan, 02:05:00).
- $(1011)_2$: MSB 1, sayı negatif; genlik $011 = 3$; değer $-3$.

4 bitle $2^4 = 16$ farklı yazım vardır, ama bu gösterimde iki yazım aynı değeri verir: $0000 = +0$ ve $1000 = -0$. Bu yüzden yalnız 15 farklı değer üretilir. İşaretli genlik gösteriminin sorunu budur.

### 8.2 1'e tümleyen işaretli sayı

MSB yine işarettir. MSB 0 ise genlik bitleri olduğu gibi kullanılır. MSB 1 ise genlik bitlerinin 1'e tümleyeni (her bitin tersi: 1 yerine 0, 0 yerine 1) alınarak genlik bulunur.

- $(0011)_2$: pozitif, genlik $3$; değer $+3$.
- $(1011)_2$: negatif; genlik bitleri $011$'in tersi $100 = 4$; değer $-4$.

Burada da 16 yazımdan yalnız 15 farklı değer çıkar. Hocanın sorusuna gelen cevapla gösterildiği gibi (ekrandan, 02:10:00): $0000$'da MSB 0 olduğu için değer $+0$; $1111$'de MSB 1, genlik bitleri $111$'in tersi $000$, değer $-0$. Sıfır yine iki kez gösterilir.

### 8.3 2'ye tümleyen işaretli sayı

MSB yine işarettir. Pozitif sayıda genlik bitleri olduğu gibi kullanılır. Negatif sayıda genlik, genlik bitlerinin 2'ye tümleyeni alınarak bulunur. 2'ye tümleyen, 1'e tümleyene 1 eklemektir. Pratik yolu: sağdan başlayarak ilk 1 de dahil olmak üzere bitleri olduğu gibi bırak, ondan sonraki bütün bitleri tersle.

Hoca iki yolun aynı sonucu verdiğini 8 bitlik bir örnekle gösterdi: önce 1'e tümleyen alınıp 1 eklendi, sonra pratik yolla aynı sonuç bulundu.

<!-- BELİRSİZ: 02:11:59'daki 8 bitlik 2'ye tümleyen örneğinin bitleri altyazıda tutarsız; o ana ait kare yok. -->

4 bitlik örnek (ekrandan, 02:15:00):

- $(0011)_2$: pozitif, değer $+3$.
- $(1011)_2$: negatif. Genlik bitleri $011$'in 2'ye tümleyeni: sağdan ilk 1 olduğu gibi kalır, sonrakiler terslenir → $101 = 5$. Değer $-5$.

#### En büyük ve en küçük değer

Hoca 2'ye tümleyende yazılabilecek en büyük ve en küçük sayıyı ve gösterimlerini sordu. En büyük sayı pozitif olmalıdır; MSB 0 ve genlik bitleri en büyük değer: $0111 = 7$, genel olarak $2^{n-1} - 1$. En küçük sayı için iki aday tartışıldı:

- $1000$: negatif; genlik bitleri $000$'ın 1'e tümleyeni $111 = 7$, buna 1 eklenince $8$; değer $-8$.
- $1001$: negatif; genlik bitleri $001$'in 1'e tümleyeni $110$, buna 1 eklenince $111 = 7$; değer $-7$.

Demek ki 4 bitte en büyük sayı $0111 = 7$, en küçük sayı $1000 = -8$'dir. Bu $n$ bite genelleştirilebilir.

### 8.4 Üç gösterimin karşılaştırılması

Hoca üç gösterimin değerlerini bir tabloda karşılaştırdı. İşaretli genlikte ve 1'e tümleyende iki sıfır vardır; ama negatif ve pozitif yöndeki aralıklar simetriktir ($-7 \ldots +7$). 2'ye tümleyende aralık simetrik değildir ($-8 \ldots +7$), ama 16 gösterimin hepsi kullanılır. Günümüz işlemcilerinde işaretli sayılar 2'ye tümleyenle gösterilir; derste de negatif sayılar için 2'ye tümleyen kullanılacak.

## 9. Bilgisayarlarda Veri Formatları

Bilgisayarda alfanümerik verinin tutulması için farklı formatlar vardır (ekrandan, 02:20:00): ASCII, Unicode, BCD, işaretli ve işaretsiz sayılar, kayan noktalı sayılar. 8086'da kayan noktalı sayı komutları olmadığı için derste yalnız tam sayılarla, işaretli ve işaretsiz olarak çalışılacak.

Sayı formatları 8, 16 bit ve istenirse 32, 64 bit olabilir. Kendi tanımladığımız formatlar da olabilir, ama bunların toplama, çıkarma, bölme gibi işlemlerini kendi yazdığımız fonksiyonlarla desteklememiz gerekir. Örneğin 8086 doğal olarak (native) 16 bitlik çarpmayı destekler; 32 bitlik bir sayı tipi tanımlayıp onun çarpmasını kendi fonksiyonumuzla yazabiliriz.

> **Hocanın vurgusu:** Bir bit dizisinin işaretli mi işaretsiz mi değerlendirileceği kullanılan assembly komutuna bağlıdır. İşaretli karşılaştırma komutu kullanılırsa bit dizisi işaretli sayı olarak değerlendirilir; işaretli çarpma yapan `IMUL` ile kullanılırsa işaretli, `MUL` ile kullanılırsa işaretsiz sayı olarak değerlendirilir.

Kayan noktalı sayılar çözünürlüğe (precision) göre ayrılır; C'deki `float` ve `double` buna örnektir.

### 9.1 ASCII ve Unicode

ASCII, alfanümerik karakterleri 7 bitle kodlar. 128 gözlü bir arama tablosu (lookup table) gibi düşünülebilir: 7 bitlik değere göre tablodaki karakter alınır. 8 bitlik genişletilmiş bir sürümü de vardır. Ama dünyadaki bütün alfabeleri göstermeye bunlar yetmez; bunun için Unicode ortaya çıkmıştır. Unicode'un farklı bit genişliklerinde sürümleri vardır ve dünyada kullanılan bütün gösterilebilir karakterleri kapsar.

<!-- BELİRSİZ: Unicode sürümlerinin bit genişlikleri altyazıda "16-30 gibitlik" olarak bozuk geçiyor; büyük olasılıkla 16 ve 32 bitlik (UTF-16, UTF-32) kastediliyor. -->

### 9.2 BCD

BCD (binary coded decimal), onluk gösterimdeki her basamağın 4 bitle ifade edildiği gösterimdir (ekrandan, 02:25:00). Normal ikilik sayılarda her basamağın ağırlığı sayıdaki konumuna göre verilir; BCD'de ise her dört bitlik grup bir onluk basamağa karşılık gelir. 8086 assembly'sinde BCD sayılarla işlem yapan komutlar vardır. Slayta göre BCD karmaşık işlemler için çok uygun değildir.

Örnek: $(526)_{10}$ sayısı.

- 6 basamağı 4 bitle: $0110$
- 2 basamağı 4 bitle: $0010$
- 5 basamağı 4 bitle: $0101$
- Sonuç: $(526)_{10} = (0101\ 0010\ 0110)_{BCD}$, toplam 12 bit.

Aynı sayının doğrudan ikilik karşılığı $1000001110$'dur, yani 10 bit (python ile doğrulandı). İkilik gösterim daha az yer kaplar ama ondan onluk değeri bir bakışta okumak zordur. BCD'de ise her 4 bitlik grup doğrudan birler, onlar, yüzler basamağını verir; insan için daha okunaklıdır.

**Soru (hocadan):** BCD'de neden her onluk basamak için 4 bit kullanılıyor? 3 bit yetmez mi? **Cevap (bir öğrenci ve hoca):** 3 bitle yalnız 0-7 arası 8 değer yazılabilir, 8 ve 9 yazılamaz. 4 bit, 0-9 arası 10 rakamı gösterebilecek genişliktedir. Ama bir fazlalık (redundancy) da oluşur: 4 bit 16 değer üretir, bunlardan 6'sı kullanılmaz.

> **Ders sonrası not:** Hoca, en yüksek anlamlı biti 1 olan BCD değerlerinden yalnız 9'un kullanıldığını söyledi. Doğrusu: MSB'si 1 olan $1000$ (8) ve $1001$ (9) kullanılır; kullanılmayan 6 değer $1010$-$1111$ (10-15) arasıdır.

### 9.3 8 bitlik ikili sayılar

Her hafıza gözünün 8 bit tuttuğu varsayımıyla işaretli ve işaretsiz gösterimler 8 bit üzerinden tanımlanır (ekrandan, 02:35:00). Slayta göre en anlamlı bitin ağırlığı işaretsiz sayılarda $2^7 = 128$, işaretli sayılarda $-2^7 = -128$'dir. 8 bit işaretsiz sayılar 0-255 arasındaki 256 değeri, 8 bit işaretli sayılar $-128$ ile $127$ arasındaki değerleri gösterebilir. Bilgisayarlarda işaretli sayılar 2'ye tümleyen yapıdadır.

Hocanın örneği $10001111$ bit dizisidir (bitler altyazıdaki basamak basamak anlatımdan kuruldu):

- **İşaretsiz yorum (`MUL` gibi işaretsiz komutlarla):** Bütün basamaklar konumsal ağırlıklarıyla toplanır: $2^7 \cdot 1 + 2^3 \cdot 1 + 2^2 \cdot 1 + 2^1 \cdot 1 + 2^0 \cdot 1 = 128 + 15 = 143$.
- **İşaretli yorum, MSB ağırlığı $-128$:** Alt 7 bitin katkısı $15$, MSB'nin katkısı $-128$; toplam $-113$.
- **İşaretli yorum, klasik yol:** MSB 1, sayı negatif. Pratik yolla 2'ye tümleyen: sağdan ilk 1 olduğu gibi kalır, sonrakiler terslenir → genlik $01110001 = 64 + 32 + 16 + 1 = 113$. Değer $-113$.

İki yöntem aynı sonucu verir (python ile doğrulandı: $143 - 256 = -113$).

> **Ders sonrası not:** Hoca örneğe başlarken "işaretli sayı komutuyla, yani MUL komutuyla" dedi, hemen ardından MUL'un yalnız işaretsiz sayılarda çarpma yaptığını belirtti. Doğrusu: `MUL` işaretsiz, `IMUL` işaretli çarpmadır; 143 sonucu işaretsiz yorumdur.

### 9.4 Word, double word ve endian düzeni

8 bitlik veriye byte denir. Hafızada iki byte birlikte kullanılarak 16 bitlik word, iki word birlikte kullanılarak 32 bitlik double word tanımlanır (ekrandan, 02:40:00).

Byte'tan büyük verilerin hafızada saklanması genel olarak iki biçimde olur. Örneğin 8 byte'lık (64 bit) bir veri:

- **Little endian:** verinin düşük anlamlı byte'ları hafızanın düşük adreslerinde saklanır.
- **Big endian:** verinin düşük anlamlı byte'ları yüksek adreslerde, yani yüksek anlamlı byte düşük adreste saklanır.

8086 little endian kullanır; Motorola ailesi big endian kullanır.

Örnek: 32 bitlik $(12345678)_{16}$ değeri. 8 onaltılık basamak var, her biri 4 bit, toplam 32 bit, yani bir double word. Bu değer 100h adresinden itibaren yerleştirilecek. Her iki onaltılık basamak bir byte'tır. Slayttaki şekil (ekrandan, 02:40:00):

| Adres | Little endian | Big endian |
| :---: | :---: | :---: |
| 00100H | 78H (düşük anlamlı byte) | 12H |
| 00101H | 56H | 34H |
| 00102H | 34H | 56H |
| 00103H | 12H (yüksek anlamlı byte) | 78H |

Big endian sütunu, hocanın tahtada önce yanlış yerleştirip sonra düzelttiği haliyle verilmiştir: verinin en yüksek anlamlı byte'ı (12H) en düşük adrese (100h) yerleşir.

### 9.5 Kayan noktalı sayılar

8086'da olmasa da genel olarak kayan noktalı sayılardan söz edilebilir. Sayı 64 bitte saklanıyorsa çift duyarlıklı (double precision), 32 bitte saklanıyorsa tek duyarlıklı (single precision) adını alır. İşaret, taban ve üs alanlarının aldığı değerlere göre sayının onluk karşılığı hesaplanır. 8086'da olmadığı için hoca üzerinde durmadı.

## 10. 8086'nın İç Yapısı ve Yazmaçları

Mikroişlemci ile assembly birbirine doğrudan bağlı olduğu için 8086'nın iç yapısını bilmek gerekir (ekrandan, 02:45:00). Bir mikroişlemcinin içinde en temel anlamda şunlar vardır: yazmaçlar, aritmetik-mantık birimi (ALU), kontrol birimi (şemada bus control ile gösterilen kısım) ve bu birimler arasındaki yollar.

### 10.1 Yazmaç grupları

Slayttaki şekilde yazmaçlar dört grupta gösterildi (ekrandan, 02:50:00):

- **Genel amaçlı yazmaçlar:** AX (AL, AH), BX (BL, BH), CX (CL, CH), DX (DL, DH), SI, DI, SP, BP.
- **Segment yazmaçları:** SS, CS, DS, ES.
- **Özel amaçlı yazmaç:** IP.
- **Bayrak yazmacı:** FLAGS (CF, PF, AF, ZF, SF, TF, IF, DF, OF).

Genel amaçlı yazmaçların hepsi programda kullanılabilir; tek koşul, bazı komutların varsayılan olarak kullandığı yazmaçları bozmamaktır. Özel yazmaçlar programın çalıştığı noktayı belirler.

### 10.2 Genel amaçlı yazmaçlar

- **AX (akümülatör):** Varsayılan olarak ALU sonuçlarının saklandığı yazmaçtır. Akümülatöre özel komutlar vardır; bunlar daha az yer kaplar ve daha hızlı çalışır. Bir işlemi akümülatör üzerinden yapmak programı hızlandırır. 8 bitlik düşük (AL) ve yüksek (AH) yarılarına ayrı adlarla erişilir.
- **BX (base register, taban yazmacı):** Bir taban oluşturur, adresler bu tabana göre belirlenebilir; ama genel amaçlıdır. BL ve BH yarılarına erişilir.
- **CX (count, sayaç):** Döngülerde varsayılan yazmaçtır. `LOOP` komutu her döngüde CX'i bir azaltır, CX sıfır olunca döngü otomatik olarak kırılır. Yani `LOOP`'tan önce CX'e atanan değer döngünün kaç kez döneceğini belirler. CL ve CH yarılarına erişilir.
- **DX (data):** Çarpma ve bölmede AX ile birlikte yardımcı yazmaç olarak kullanılır; bazı komutlarda varsayılan çıktının saklandığı yazmaçtır. Genel amaçlıdır.
- **SP ve BP (stack pointer, base pointer):** Yığın işlemlerinde ve yığında adresleme yaparken kullanılır.
- **SI ve DI (source index, destination index):** Bir döngüdeki iterasyon değişkenine benzer bir işlev görürler. Ayrıca katar işlemlerinde verinin bir hafıza bölgesinden diğerine aktarılması gibi işlerde kaynak ve hedef başlangıç adreslerini tutarlar.

### 10.3 Segment yazmaçları ve fiziksel adres

8086 16 bitlik bir işlemcidir ama 20 adres ucu vardır. 16 bitlik yazmaçlarla 20 bitlik adres üretmek için segment-offset hafıza modeli kullanılır:

$$\text{Fiziksel adres} = \text{Segment} \times 10h + \text{Offset}$$

Segment, turuncu ile gösterilen segment yazmaçlarından biridir (16 bit). Offset, IP, SI, DI gibi bir yazmaçtaki 16 bitlik değerdir. 10h ile çarpmak, sonuna dört ikilik 0, yani bir onaltılık 0 eklemek demektir. 16 bitlik değerin sonuna 4 bit eklenince 20 bitlik bir değer olur; bunun üzerine 16 bitlik offset eklenerek 20 bitlik fiziksel adres oluşturulur. Hafıza segmentlere bölünerek adreslenir ve hangi segmente erişileceğini segment yazmacı belirler.

### 10.4 Bayraklar

Bayraklar işlemlerin yönünde ve koşullu dallanmalarda kullanılır:

- **CF (carry):** elde bayrağı.
- **PF (parity):** işlem sonucunun eşlik durumu.
- **AF (auxiliary):** 4 bitlik işlemlerde oluşan eldeyi tutan yardımcı bayrak.
- **ZF (zero):** sonuç sıfır mı.
- **SF (sign):** sonuç pozitif mi negatif mi.
- **TF (trap):** adım adım debug için.
- **IF (interrupt):** donanımsal kesmeleri açıp kapamak için.
- **DF (direction):** katar işlemlerinde kopyalamanın düşük adresten yüksek adrese mi, tersine mi yapılacağı.
- **OF (overflow):** işlem sonucu veri tipine sığmayıp taşma oluştu mu.

Hoca yazmaçları bu derste hızlı geçtiğini, önümüzdeki derste tekrar üzerinde duracağını söyledi.

### 10.5 32 ve 64 bitlik yazmaçlar

32 bitlik işlemcilerde yazmaç uzayı genişler. Yazmaçların 32 bitlik sürümleri *extended* kelimesinden gelen E harfiyle adlandırılır. 32 bitlik EAX'in düşük anlamlı 16 biti AX'tir; AX'in düşük yarısı AL, yüksek yarısı AH'dir. Bütün yazmaçlar için aynı yapı kurulur. 64 bitlik mimaride yazmaçlar R harfiyle genişler (ekrandan, 02:55:00): RAX (EAX, AX, AL, AH), RBX, RCX, RDX, RSI, RDI, RSP, RBP, RIP, R8-R15, RFLAGS; segment yazmaçlarına FS ve GS eklenir.

**Soru:** 16 bitlik yazmacın iki 8 bitlik yarısına ayrı ayrı erişebiliyoruz, ama 32 bitlik yazmacın yüksek anlamlı 16 bitine neden erişemiyoruz? **Cevap:** Hoca bunu tasarım tercihi olarak yorumladı. En kötü durumda 32 bitlik yazmaç 16 bit sağa ötelenirse üst kısım AX'e geçer ve orada işlenebilir. İki 16 bitlik yarıya aynı anda erişimi desteklemek donanımı iki katına çıkarmayı gerektirir; iki 8 bitlik yarıya erişimi desteklemenin donanım karmaşıklığı ise düşüktür. Hoca, "tasarım gereği" cevabının kaçamak olduğunu, altında başka sebepler de yatabileceğini ekledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:12:05): 16 bitlik bir değişkende rastgele bir değer var. Bu değerdeki 1 bitlerinin sayısını nasıl buluruz?

> **Çözüm (derste verildi):** Yazılımda bir döngüyle bitler tek tek kontrol edilir; karmaşıklık bit genişliğiyle orantılıdır ($n$ bit için $n$ adım). 8086'da bu, döndürme/öteleme komutlarıyla yapılır: her ötelemede en düşük anlamlı bit elde bayrağına geçer ve sayılır. Günümüz işlemcilerinde `POPCNT` komutu bu işi donanımda tek komutla yapar.

**Soru 2** (derste sözlü, 00:16:04): 1'den $n$'e kadar sayıların toplamını hesaplamanın karmaşıklığı nedir?

> **Çözüm (derste verildi):** Döngüyle $O(n)$. Ama $\sum_{i=1}^{n} i = \frac{n(n+1)}{2}$ olduğundan toplam $O(1)$ sürede hesaplanabilir. Derleyici uygun optimizasyon parametresiyle bu dönüşümü yapabilir.

**Soru 3** (derste sözlü, 00:42:37): x86'da bölme `DIV` ile yapılabiliyor. İkiye bölmeyi yapmanın en uygun yolu nedir?

> **Çözüm (derste verildi):** `DIV` çok çevrim süren karmaşık bir komuttur. Değeri bir kez sağa ötelemek ikiye bölmek demektir; 2'nin kuvvetlerine bölmede sağa öteleme kullanılır.

**Soru 4** (derste sözlü, 00:50:34): Makro çağırmak derlenmiş makine kodunun boyutunu artırır mı? Yordam çağırmak artırır mı?

> **Çözüm (derste verildi):** Makro her çağrıldığı yere kopyalandığı için her çağrıda kod makro boyu kadar büyür; hiç çağrılmazsa etkisi yoktur. Yordam bir kez yer kaplar (hiç çağrılmasa bile); her çağrı ek büyüme yaratmaz.

**Soru 5** (derste sözlü, 00:53:47): Makro ne zaman, yordam ne zaman kullanılmalı?

> **Çözüm (derste verildi):** Makronun çağrı maliyeti yoktur ama kodu büyütür. Yordam kodu büyütmez ama yazmaçları yığına atıp geri alma gibi bir çağrı maliyeti vardır. Çağrı maliyetini aşmayacak kadar kısa işler makroyla, uzun ve karmaşık işler yordamla yazılır.

**Soru 6** (derste sözlü, 01:29:15): 4004, her biri 4 bit tutan 4096 hafıza gözünü adresleyebiliyor. 4004'ün kaç adres ucu ve kaç veri ucu vardır?

> **Çözüm (derste verildi):** $N$ adres ucuyla $2^N$ göz adreslenir. $4096 = 2^{12}$ olduğundan $N = \log_2 4096 = 12$ adres ucu vardır (öğrencilerin önerdiği 4096 ve 1024 yanlıştır; 4 uçla yalnız $2^4 = 16$ göz adreslenir). Her göz 4 bit tuttuğu için veri ucu sayısı 4'tür. Toplam kapasite $2^{12} \times 4$ bit.

**Soru 7** (derste sözlü, 01:33:02): 4004'ün 45 komutu var. Hepsinin birbirinden farklı (birbirinin varyasyonu olmayan) komutlar olduğu varsayılırsa, bu komutları kodlamak için en az kaç bitlik komut genişliği gerekir?

> **Çözüm (derste verildi):** $2^5 = 32 < 45 \le 64 = 2^6$ olduğundan 6 bit gerekir; 7'ye gerek yoktur. 6 bitle 64 farklı kod üretilir; $64 - 45 = 19$ kod boşta kalır.

> **Ders sonrası not:** Hoca boşta kalan kod sayısını "45-64, 9 tane" diye söyledi. Doğrusu $64 - 45 = 19$'dur.

**Soru 8** (derste sözlü, 01:36:03): Her hafıza gözünün 1 byte tuttuğu varsayılırsa, 16 KB adresleyebilen 8008'in adres ve veri yolu genişlikleri nedir?

> **Çözüm (derste verildi):** Toplam 16 KB ve her göz 1 byte olduğundan $16\text{K}$ göz vardır. $16\text{K} = 2^4 \cdot 2^{10} = 2^{14}$, yani 14 adres ucu. 8 bitlik işlemci dışarıdan 8 bit veri aldığından veri yolu 8 bittir.

**Soru 9** (derste sözlü, 01:42:03): 8086'nın komut kuyruğu (prefetch queue) ne zaman çöp olur?

> **Çözüm (derste verildi):** Kuyruk, hafızada ardışık yerleşmiş komutları önceden okur. Sıradaki komut bir atlama (`JMP`) ya da dallanma ise program hafızanın başka bir yerine gider; önceden okunan komutların anlamı kalmaz ve kuyruk boşa gider.

**Soru 10** (derste sözlü, 02:04:49): 4 bitlik işaretli genlik gösteriminde kaç farklı değer üretilebilir? Hangi iki gösterim eşdeğerdir?

> **Çözüm (derste verildi):** 16 yazım vardır, ama $0000 = +0$ ve $1000 = -0$ aynı değeri gösterir; yalnız 15 farklı değer üretilir.

**Soru 11** (derste sözlü, 02:08:23): 4 bitlik 1'e tümleyen işaretli sayılarda 16 yazıma rağmen 15 farklı değer var. Sorunlu gösterimler hangileri?

> **Çözüm (derste verildi):** $0000$: MSB 0, değer $+0$. $1111$: MSB 1, genlik bitleri $111$'in tersi $000$, değer $-0$. Sıfır iki kez gösterilir.

**Soru 12** (derste sözlü, 02:14:22): 4 bitlik 2'ye tümleyen işaretli sayılarda yazılabilecek en büyük ve en küçük sayı nedir, gösterimleri nelerdir?

> **Çözüm (derste verildi):** En büyük: $0111 = +7$ ($2^{n-1} - 1$). En küçük: $1000$; genlik bitleri $000$'ın 1'e tümleyeni $111$, artı 1 → $8$, değer $-8$. Önerilen diğer aday $1001$ ise $-7$ eder.

**Soru 13** (ekrandan, 02:00:00): $(0.625)_{10} = (?)_2$

> **Çözüm (derste verildi):** $0.625 \cdot 2 = 1.25$ (1), $0.25 \cdot 2 = 0.5$ (0), $0.5 \cdot 2 = 1.0$ (1); kesirli kısım sıfır oldu. Sonuç $(0.101)_2$.

**Soru 14** (ekrandan, 02:25:00): $(526)_{10}$ sayısını BCD ile yazın. Neden her basamak için 4 bit kullanılır?

> **Çözüm (derste verildi):** $5 \to 0101$, $2 \to 0010$, $6 \to 0110$; $(526)_{10} = (0101\ 0010\ 0110)_{BCD}$. 3 bit yalnız 0-7'yi gösterir, 8 ve 9 için yetmez. 4 bit 0-9'u gösterir; 16 değerden 6'sı kullanılmaz.

**Soru 15** (ekrandan, 02:40:00): 32 bitlik $12345678h$ değeri 100h adresinden itibaren little endian ve big endian düzende nasıl saklanır?

> **Çözüm (derste verildi):** Little endian: 100h: 78h, 101h: 56h, 102h: 34h, 103h: 12h. Big endian: 100h: 12h, 101h: 34h, 102h: 56h, 103h: 78h.

## Dersin Toparlaması

Bu ilk derste dersin kapsamı çizildi: x86 ailesinin 16 bitlik assembly dili. Assembly'nin donanımın yeteneklerini (ör. `POPCNT`) ve kısıtlarını gösterdiği, derleyicinin her kodu iyi optimize edemediği ve bu yüzden assembly bilmenin performans için önemli olduğu anlatıldı. Kullanılacak araçlar tanıtıldı: hızlı deneme için EMU8086, esas ortam olarak DOSBox ve MASM, başvuru kaynağı olarak komut kümesi belgesi. Dönemin konuları (komutlar, adresleme modları, EXE/COM programlar, yordam ve makro, parametre aktarma, kesmeler, C ile birlikte kullanım) özetlendi.

İkinci yarıda 4004'ten Core i ailesine mikroişlemcilerin gelişimi adres ve veri yolu hesaplarıyla incelendi; komut kuyruğu, CISC yapısı ve cache kavramları açıklandı. Ardından sayı tabanları ve dönüşümler, üç işaretli sayı gösterimi (2'ye tümleyenin neden tercih edildiği dahil), BCD, ASCII/Unicode ve endian düzeni işlendi. Ders, 8086'nın yazmaçları, segment-offset adreslemesi, bayraklar ve 32/64 bitlik yazmaç uzantılarına hızlı bir girişle bitti. Hoca yazmaçları önümüzdeki derste tekrar ele alıp kalınan yerden devam edeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
