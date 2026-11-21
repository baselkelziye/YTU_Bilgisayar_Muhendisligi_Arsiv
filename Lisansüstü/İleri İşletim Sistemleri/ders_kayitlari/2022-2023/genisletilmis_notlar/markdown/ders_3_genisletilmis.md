# Ders 3 Genişletilmiş Notu: Süper Sayfalar ve Communicating Sequential Processes Makale Tartışması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu derste ekran paylaşımı yapılmadı; anlatım tamamen sözlü bir makale tartışmasıydı. Ders, öğrencilerin önceden okuduğu iki makale üzerinden soru-cevap biçiminde ilerledi: önce işletim sisteminde süper sayfa desteğini anlatan makale, aradan sonra C. A. R. Hoare'un 1978 tarihli "Communicating Sequential Processes" (CSP) makalesi. Hoca konuyu düz anlatmak yerine öğrencilere sorular yöneltti ve cevapları adım adım doğru noktaya taşıdı.

> **Ek bilgi (derste anlatılmadı):** Derste "SuperPage paper" diye anılan çalışma, bölüm başlıkları (promotion, demotion, eviction, kirli süper sayfaların dışarı yazılması) ve tartışılan yöntemler göz önüne alındığında büyük olasılıkla Navarro, Iyer, Druschel ve Cox'un "Practical, Transparent Operating System Support for Superpages" (OSDI 2002) makalesidir. Bu makale FreeBSD üzerinde rezervasyona dayalı bir süper sayfa sistemi gerçekler.

## İçindekiler

- 1. Sayfalı bellek, sayfa tablosu ve TLB
- 2. Süper sayfa fikri ve kısıtları
- 3. Bitişiklik gereksinimi ve compaction sorunu
- 4. Süper sayfa tahsis yaklaşımları
- 5. Promotion ve incremental promotion
- 6. Demotion, eviction ve kirli süper sayfalar
- 7. Makale okuma yöntemi üzerine
- 8. CSP makalesinin amacı ve tarihsel bağlamı
- 9. CSP'nin yedi temel önerisi
- 10. CSP'nin gerçeklenebilirliği ve günümüze etkisi
- Örnek Sorular

## 1. Sayfalı bellek, sayfa tablosu ve TLB

Makaleyi sunan öğrenci anlatıma sayfa kavramıyla başladı. Bir işletim sistemi belleği iki biçimde kullanabilir. Birincisi segmentli bellektir: 8086 işlemcisinde olduğu gibi bellek veri segmenti, kod segmenti gibi parçalara ayrılır ve gerçek adrese segment ile offset birlikte kullanılarak ulaşılır. İkincisi sayfalı bellektir. Sayfalı bellekte bellek sabit boyutlu parçalara bölünür; Linux bugün 4 KB'lık sayfalar kullanır. Bir süreç birkaç sayfadan oluşur. Sayfalar belleğe konabilir, diske çıkarılabilir, diskten tekrar getirilip başka çerçevelere yerleştirilebilir.

CPU bir adrese gitmek istediğinde mantıksal olarak bir sayfa numarası ve bir offset üretir; "bu sayfanın şu konumuna gitmek istiyorum" der. Bu adresin gerçek fiziksel adrese çevrilmesi gerekir. Sayfa numarasını fiziksel bellekteki çerçeve (frame) numarasına çeviren yapı sayfa tablosudur (page table). Adrese erişmek için önce sayfa tablosuna gidilir, çerçeve bulunur, sonra çerçeve ve offset ile bellekteki gerçek konuma ulaşılır. Her erişimde bu işlemin yapılması maliyetlidir.

Bu maliyeti azaltmak için özel bir donanım kullanılır: TLB (Translation Lookaside Buffer). CPU bir adres ürettiğinde önce sayfa tablosuna değil TLB'ye bakar. Örneğin 100 girdisi olan bir TLB bu girdilerin hepsine aynı anda bakabilir; böylece sayfa numarası üretildiği anda çerçeve numarası elde edilir.

TLB'de aranan kayıt yoksa TLB miss olur ve sayfa tablosuna gidilir. Sayfa tablosunda da sayfa bellekte yoksa sayfa hatası oluşur: sayfa diskten getirilir, belleğe konur ve sayfa tablosu güncellenir. TLB miss istenmeyen bir durumdur, çünkü her seferinde ayrıca bir tablo araması gerekir.

## 2. Süper sayfa fikri ve kısıtları

Makalenin amacı TLB kapsamını artırmak, yani TLB'nin aynı sayıda girdiyle daha fazla belleği kapsamasını sağlamaktır. Akla gelen en basit çözüm sayfa boyutunu büyütmektir: 4 KB yerine çok daha büyük sayfalar kullanmak. Ama sayfa boyutunu büyütmek performansı kendiliğinden artırmaz. Büyük bir sayfanın yalnız küçük bir kısmı kullanılırsa geri kalanı boşa gider.

Burada hoca bir ayrımı netleştirdi: makalede taban sayfa (base page) boyutu büyütülmüyor. Bu bir seçenek olarak anılıyor ama iyi bir çözüm olmadığı söyleniyor. Süper sayfa (superpage), birden fazla taban sayfanın bir bütün olarak kullanılması ve taban sayfa boyutunun bir katı olan daha büyük bir birim oluşturulmasıdır. Taban sayfalar, örneğin bellek ilk istendiğinde ya da süreç sayfaları kullandıkça, birleştirilir.

Öğrencinin aktardığı kısıtlar iki tanedir:

- Süper sayfa donanım tarafından desteklenmelidir.
- Süper sayfa hem sanal adres uzayında hem fiziksel adres uzayında bitişik (contiguous) olmalıdır.

> **Ek bilgi (derste anlatılmadı):** Süper sayfa makalelerinde genelde üçüncü bir kısıt da sayılır: hizalama (alignment). Bir süper sayfanın başlangıç adresi, hem sanal hem fiziksel tarafta, kendi boyutunun katı olmalıdır.

## 3. Bitişiklik gereksinimi ve compaction sorunu

### 3.1 Bitişiklik neden gerekli?

Hoca "bitişik olması ne demek ve neden gerekli?" diye sordu. Bir öğrenci bitişikliği, araya başka sayfalar girmeden ardışık yerleşim olarak tanımladı. Bir başka öğrenci bunun erişimde kolaylık sağladığını söyledi. Hoca burada "ardışık olmasa erişemez miyim, yoksa yalnız daha mı kolay erişirim?" diye sorarak öğrencileri asıl soruya yöneltti: sayfa ve çerçeve yapısı zaten hangi sorunu çözmek için getirilmişti?

Cevap şudur: segmentli sistemde bir sürecin belleği fiziksel olarak art arda gelmek zorundadır. Sayfalı sistemde ise sayfalar fiziksel bellekte farklı yerlerde olabilir. İşletim sistemi bellekte boş bulduğu, bir sayfa boyutuna denk gelen her yeri kullanabilir ve böylece parçalanmayı (fragmentation) en aza indirir.

Hoca ardından şu örneği verdi: taban sayfa 4K olsun ve bunlardan 10 tanesi birleştirilip 40K'lık bir süper sayfa yapılsın. Sayfa zaten sanal tarafı ifade eder; peki bu 40K'nın fiziksel taraftaki çerçeve karşılığı nasıl olmalıdır? Ardışık olmalıdır. Çünkü süper sayfaya tek bir girdiyle erişildiğinde offset sıralı kullanılır: 5'ten sonra 6, 6'dan sonra 7 gelir; 5'ten 25'e atlanamaz. Fiziksel taraf ardışık olmazsa offset'in gösterdiği yerde başka bir sürecin çerçevesi bulunabilir.

### 3.2 Eski sorunun geri gelmesi

Hocanın tartışmanın merkezine koyduğu soru şuydu: sayfa ve çerçeve yapısına, fiziksel bitişiklik zorunluluğunu ve parçalanmayı ortadan kaldırmak için geçildi. TLB erişimini azaltmak için sayfaları yeniden birleştirmeye başlarsak, çözmeye çalıştığımız sorunu tekrar oluşturmuş olmaz mıyız?

Bir öğrenci bunun sistemdeki süreç sayısına ve sürekli aynı süreçlerin çalışıp çalışmadığına bağlı olabileceğini söyledi. Hoca, çok kullanıcılı ve çok işlemli bir sistemde böyle bir varsayımla yapı kurulamayacağını, bunun öngörülemeyeceğini belirtti.

Hocanın vardığı sonuç şuydu: süper sayfalar 40K, 1 MB ya da 20-30 MB olursa, fiziksel bellekte bu süper sayfayı bir seferde alabilecek tek parça bir alan bulmak gerekir. Bellekte toplam olarak ihtiyacı karşılayacak kadar boş alan olabilir; ama bu alan tek parça değildir, farklı yerlere dağılmıştır.

### 3.3 Compaction, defragmentation ve garbage collection

Dağınık boş alanları kullanabilmek için yapılması gereken, onları tek parça olacak biçimde bir araya toplamaktır. Bir öğrenci bunun demotion ve eviction olduğunu söyledi; hoca bunun yanlış olduğunu, bu işleme compaction dendiğini belirtti. Disklerde aynı işleme defragmentation denir. Hoca, Java ve C# gibi nesneleri yığında (heap) ayıran dillerde benzer işlemin garbage collection olarak geçtiğini de ekledi.

> **Ders sonrası not:** Hoca garbage collection için compaction ile "aynı şey, hiçbir farkı yok" dedi. Garbage collection'ın asıl işi erişilemeyen nesnelerin belleğini geri kazanmaktır; her çöp toplayıcı sıkıştırma yapmaz. Hocanın kastettiği büyük olasılıkla sıkıştırma (compacting) yapan çöp toplayıcılardır.

Bu üç işlemin ortak sıkıntısı zamandır. Dolu alanları bir tarafa, boş alanları bir tarafa almak için bellekten belleğe kopyalama yapmak gerekir; başka çare yoktur. Kopyalanan alanda çalışması gereken bir süreç kopyalama sırasında çalıştırılamaz. Dolayısıyla süreçler durdurulmalıdır. Bu işlem aperiyodik olarak yapıldığında sistem zaman zaman tamamen duraklar, boş ve dolu alanlar toplanır, sonra süreçler kaldıkları yerden devam eder. Sayfa ve çerçeve yaklaşımı tam da bu çalışma-duraklama döngüsünü ortadan kaldırmak için getirilmişti: sayfa boyutu küçüktür, çerçeve boyutu sayfaya eşittir, çerçeveler belleğin her yerine dağılabilir ve sürece tahsis sayfa birimiyle yapılır.

Ardından hoca zinciri toparladı: her erişimde sayfa ve çerçeve tablosuna bakmak zaman kaybıdır, bu yüzden TLB ile donanımda hızlandırılır. TLB ile de bir maliyet kalır. TLB üzerinden yapılan aramanın masrafını azaltmak için sayfaları büyütmek gerekir. Makaledeki çalışmanın arkasındaki temel fikir budur: 4K ya da 8K'lık bir taban sayfa vardır, süper sayfa bunun 10, 20, 30 katıdır. Ama kontrolsüz büyütülürse sistem yine baştaki duruma döner.

> **Hocanın vurgusu:** Süper sayfa oluşturma kontrollü, durum izlenerek yapılmalıdır.

## 4. Süper sayfa tahsis yaklaşımları

Hoca süper sayfaların kaç farklı yaklaşımla oluşturulduğunu sordu. Öğrenciler önce üç yaklaşım saydı (rezervasyona dayalı, yer değiştirmeye dayalı ve donanımla bitişiklik gereksinimini azaltan). Tartışma sonunda makalenin karşılaştırdığı iki temel tahsis yaklaşımı üzerinde duruldu: yer değiştirmeye dayalı (relocation-based) ve rezervasyona dayalı (reservation-based) tahsis. Hoca, makalenin "tercih edilen" (preferred) bir yöntemden söz edebilmesi için en az iki alternatif olması gerektiğini, diğer yöntemin rezervasyonun anlatıldığı yerde yazdığını hatırlattı.

> **Hocanın vurgusu:** Yayımlanmış bir çalışma hakkında "olabilir" diye konuşulmaz; makalede ne yazıyorsa onun üzerinden konuşulur.

### 4.1 Yer değiştirmeye dayalı tahsis (relocation)

Hoca relocation'ı bir örnekle anlattı. Bir süreç için süper sayfa oluşturulmaya başlanmış olsun. İlk sayfanın çerçevesinin konduğu yerde arkasında iki çerçevelik daha boş yer vardır; böylece üç çerçevelik bir süper sayfa olmuştur. Şimdi süper sayfanın boyutu dörde çıkarılmak isteniyor, ama üçüncü çerçevenin arkasında boş yer yoktur. Bu durumda:

1. Bellekte dört çerçevelik başka bir boş yer bulunur.
2. Mevcut üç çerçeve oraya kopyalanır.
3. Dördüncü çerçevenin süper sayfanın ucuna eklendiği işletim sistemine bildirilir.

Burada da kopyalama yapılmıştır, ancak yalnız ilgili süreç kapsamında: o süreç durdurulur, onun sayfaları kopyalanır. Tehlike bir ya da birkaç adım sonra ortaya çıkar. Bellek doldukça yer bulunamamaya başlar ve bu kez bütün süreçleri durdurup compaction yapmak gerekir. Dolayısıyla relocation hem süreç bazında hem sistem genelinde öngörülebilir bir performans sağlamaz.

Relocation en iyi, boş bellek büyük ve bitişik alanlar bol olduğunda çalışır; çünkü o durumda yer değiştirmeye muhtemelen hiç ihtiyaç duyulmaz. Süreç sayısı arttıkça ya da bellek kapasitesi kısıtlı oldukça sürekli relocation yapmak gerekebilir.

### 4.2 Rezervasyona dayalı tahsis (reservation)

Rezervasyonda temel kriter, istenen (daha doğrusu öngörülen, arzu edilen) süper sayfa boyutuna eşit, bitişik bir fiziksel çerçeve bölgesinin önceden ayrılmasıdır. Örneğin bir uygulamanın en iyi çalışması için süper sayfa boyutunun taban sayfanın 50 katı olması gerektiği söylenebilir. Peki bunu söyleyebilmek için ne gerekir?

Bir öğrenci süreci önceden çalıştırıp karakteristiğini gözlemlemek gerektiğini söyledi. Hoca bunun anlamlı bir hedef olmadığını belirtti: bir süreci önce çalıştırıp, bir dahaki çalışmasında ona göre süper sayfa vermek bilimsel bir çözüm değildir. Hedef, daha önce hiç çalışmamış bir sürecin süper sayfa ihtiyacını tahmin edebilmek ya da bunu en az performans kaybıyla karşılayacak bir yapı kurmaktır. İstatistikteki karşılığıyla bu bir a priori, yani önceden kestirme sorunudur ve kolay değildir.

**Soru:** Rezervasyon boyutunu kim belirliyor; süreç mi "şu kadar ayır" diyor, yoksa sistem mi takip ediyor? **Cevap:** Süreçten gelen talebe göre değil, işletim sistemi kendi tahminiyle belirler. Orada bir kestirim (estimation, prediction) yapılması gerekir.

**Soru:** Tahmin tutmadığında yeniden relocation mı yapılır? **Cevap:** Evet; optimal durumdan çıkıldığında ya da ihtiyaç karşılanamadığında yine relocation gerekir.

Hoca iki yaklaşımı şöyle özetledi: rezervasyon önceden bilgi gerektirir, relocation ise tıkanıldığında kopyalama gerektirir. Bu ikisi arasında kontrollü bir yaklaşım aranır. Bir öğrenci birden fazla süper sayfa boyutu kullanmayı önerdi; hoca önce bir ara adımın, promotion'ın konuşulması gerektiğini söyledi.

## 5. Promotion ve incremental promotion

### 5.1 Promotion

Hoca promotion'ı şöyle tarif etti. Ortalama süper sayfa boyutunun 10 taban sayfa olduğu kabul edilsin. Başlangıçta süper sayfa hiç hesaba katılmadan süreçlere normal taban sayfalar tahsis edilir. Bir yandan da işletim sisteminin içinde periyodik çalışan bir kod parçası, süreçlere ait çerçevelerin bellekteki durumunu gözlemler: bir sürece ait kaç çerçeve arka arkaya, bitişik olarak gelmiş?

Öngörülen 10 çerçevenin arka arkaya geldiği görüldüğünde "bunlar için neden 10 ayrı girdi tutuyorum?" denir. Bu çerçeveler zaten kendiliğinden bellekte ardışık durmaktadır; onları ardışık hâle getirmek için uğraşılmamıştır. O zaman birleştirilip tek bir süper sayfa yapılır ve hepsine tek bir girdiyle erişilir. Doğal olarak fiziksel bellekte ardışık yerleşmiş çerçeveleri tespit edip tek bir girdiyle erişilebilir hâle getirme işlemine promotion denir.

**Soru:** Böyle yapılmasaydı TLB bunların her birini ayrı sayfa olarak göreceği için tek bir TLB girdisiyle hepsine ulaşılamayacaktı, değil mi? **Cevap:** Evet; her biri için ayrı arama yapmak gerekecekti.

### 5.2 Incremental promotion

Promotion'ın kolayca ve artarak yapılabilmesini sağlayan kavram rezervasyondur. Rezervasyonda fiziksel adres uzayında bir alanın önceden ayrıldığı varsayılır. Süreç sayfalarına dokundukça bu alandaki çerçeveler tahsis edilir. Tahsis edilen çerçevelerin sayısı belirli bir eşiği aştığında promotion yapılır ve TLB'deki girdi sayısı teke indirilir. Ardışık süper sayfalar oluştukça bunlar da birbirine bağlanabilir.

**Soru:** Bu büyütme nereye kadar sürebilir? **Cevap:** Rezervasyonun sınırına kadar. Rezervasyonun içinde kalındığı sürece oradaki bütün bellek fiziksel olarak ardışıktır; bu garanti edilir. Rezervasyonun dışında ise boş ve uygun çerçeve olmayabilir, başka bir sürece tahsis edilmiş bir çerçeve bulunabilir.

Bir öğrenci sürecin rezerve alanın bir kısmını kullanmadığı durumu önerdi. Hoca o durumda promotion değil, kullanılmayan rezerve alanın geri alınması gerektiğini belirtti.

## 6. Demotion, eviction ve kirli süper sayfalar

### 6.1 Demotion

Demotion, süreç süper sayfanın bütün parçalarını artık aktif olarak kullanmıyorsa süper sayfanın küçültülmesidir. Hoca demotion'daki temel problemi sordu. Bir öğrenci, küçültme sonrası rezerve alanda seyrek (sparse) parçalar oluşacağını söyledi. Bir başka öğrenci asıl sorunu tanımladı: süper sayfa için tek bir kirli (dirty) bit tutulur, hangi taban sayfanın kirli olduğunu anlamak zorlaşır.

Hocanın açıklamasıyla: donanımın sayfa-çerçeve mantığında her çerçeve için orada değişiklik olup olmadığını gösteren bir dirty bit vardır. Promotion yapıldıktan sonra ise bu bilgi süper sayfanın tamamı için tutulur. Süper sayfanın hangi parçasının değiştiği, dolayısıyla nereye kadar küçültüleceği bilinemez. Donanım sayfa mantığı üzerine kurulu olduğu için burada ihtiyaç duyulan desteği sağlamaz.

### 6.2 Eviction

Eviction, sayfanın diske alınmasıdır ve normal sayfalı bellek yönetimindeki işlemin aynısıdır. Fark, diske yazılan birimin süper sayfa boyutunda olmasıdır. Bir taban sayfa kirli olsa bile 10 taban sayfalık bir süper sayfanın tamamının diske yazılması gerekir.

Süper sayfanın içindeki bütün taban sayfaların değişmiş olması çok düşük bir olasılıktır. Buna rağmen temiz olanlar da yazılır ve daha sonra hepsi geri getirilir. Süper sayfa boyutu büyüdükçe ve eviction gerektikçe, sayfaların diske yazılıp geri okunmasından kaynaklanan disk G/Ç gecikmesi artar.

**Soru:** Diske yazılmış bir süper sayfanın taban sayfaları hangi durumdadır? **Cevap:** Hepsi temizdir (clean). Kirli oldukları için diske yazılmışlardır; diske yazıldıktan sonra bilinen bir duruma gelmişlerdir. Bir öğrenci bu noktada "population map"ten söz etti; hoca kirliliğin artık konu olmadığını, sorunun sayfayı geri getirirken ne yapılacağı olduğunu belirtti. Geri getirirken de rezervasyon gibi daha önce konuşulan mantıklar uygulanabilir.

Hoca ayrıca öğrencilerin spekülatif demotion bölümüne bakıp bakmadığını sordu; bu bölüm derste ayrıntılı tartışılmadı.

### 6.3 Kirli süper sayfaların dışarı yazılması: kriptografik özet

Hoca, bir süper sayfanın hangi parçalarının kirli olduğunu öngörebilecek bir yaklaşım olup olmadığını sordu ve öğrencileri makalenin 4.7 numaralı "Paging out dirty superpages" bölümüne yönlendirdi. Bu bölümde, normalde kriptografide kullanılan güvenli özet (secure hash) algoritmalarının, süper sayfanın hangi kısımlarının değiştiğini anlamak için kullanılması önerilir. Hocanın makaleden okuduğu yöntem şöyledir:

1. Temiz bir bellek sayfası diskten okunduğunda içeriğinin kriptografik özeti hesaplanır ve kaydedilir.
2. Kısmen kirli taban sayfalar bir süper sayfaya yükseltilirse ya da temiz bir süper sayfa kirlenirse, onu oluşturan bütün taban sayfalar kirli kabul edilir.
3. Sayfa dışarı yazılırken (flush) her taban sayfanın özeti yeniden hesaplanır ve saklanan değerle karşılaştırılır. Aynıysa sayfa değişmemiştir; farklıysa değişmiştir ve diske yazılmalıdır.

Hoca özetin taban sayfa başına hesaplandığına dikkat çekti. Süper sayfada 50 taban sayfa varsa, diskten okuma işleminin parçası olarak 50 ayrı özet hesaplanır ve kenarda tutulur. Dışarı yazma kararı donanım tek bit tuttuğu için süper sayfanın tamamı için alınır, ama yazma sırasında taban sayfa bazında karşılaştırma yapılır.

Bir öğrenci, çakışma olasılığının $2^{-80}$ civarında olduğunu ve bunun donanım hatası olasılığından çok daha küçük olduğu için yöntemin güvenli kabul edildiğini hatırlattı. Hoca bunun neden önemli olduğunu açıkladı: donanımda bir ya da birden fazla bit kendiliğinden değişebilir (bit flip). Bu yüzden seçilen özetin bit sayısı, çakışma olasılığı donanım hatası olasılığından çok daha düşük olacak kadar yüksek olmalıdır.

> **Ders sonrası not:** Hoca 160 bit ile 80 bit arasındaki ilişkiyi "yarısının iki katı" diye karışık ifade etti. Doğrusu şudur: $n$ bitlik bir özette doğum günü paradoksuna göre çakışma güçlüğü yaklaşık $2^{n/2}$'dir. 160 bitlik bir özet için bu $2^{160/2} = 2^{80}$ eder; yani 80, 160'ın yarısıdır. Makalede kullanılan özet büyük olasılıkla 160 bitlik SHA-1'dir.

Yöntemin bedeli, sürekli özet hesaplamak gerekmesidir. Derste aktarıldığına göre çok kötü durumlarda yaklaşık %60'a varan performans düşüşü gözlenmiş ve yöntemin kullanılmamasına karar verilmiş; hoca bunun anlamlı olmadığını belirtti.

## 7. Makale okuma yöntemi üzerine

Süper sayfa tartışmasının sonunda hoca, makalelerin yalnız giriş (introduction), özet (abstract) ya da sonuç bölümünün okunmasının yeterli olmadığını, makalenin tamamının okunması gerektiğini vurguladı. Makalede geçen kavramların bilinmesi gerekir.

> **Hocanın vurgusu:** Makalenin yalnız giriş, özet ya da sonuç kısmı okunmaz. Makalenin tamamıyla ilgili bilgi ve fikir sahibi olunmalı, makalede geçen kavramlar bilinmelidir.

**Soru:** Makale okurken 20-30 dakikadan sonra dikkat dağılıyor, ayrıntılar yerleşmiyor; önerebileceğiniz bir teknik var mı? **Cevap:** 20-30 dakika aralıksız okuyup 5-10 dakika ara vermek uygundur. Okurken not almak, önemli yerleri işaretlemek ve kenara yorum yazmak gerekir. Hoca kendisinin bildiği genel kavramlara ait yerleri hızlı geçtiğini, çalışmanın özüyle ilgili kısımları ise fosforlu kalemle ya da yanına çizgi çekip not düşerek pekiştirdiğini, bakması gereken yerleri ayrıca not aldığını anlattı.

Hoca ayrıca önceki haftaların makalelerine yetişemeyen öğrencilere, bir sonraki haftaya hazırlanırken öncekilere de bakmalarını önerdi; makaleler birbirini destekleyecek biçimde seçilmiştir.

## 8. CSP makalesinin amacı ve tarihsel bağlamı

### 8.1 Makalenin önerisi

Aradan sonra bir öğrenci Hoare'un "Communicating Sequential Processes" makalesini tanıttı. Öğrenciye göre makale, paralel ve dağıtık sistem yazılımlarının daha etkili tasarlanması için yeni bir programlama modeli önerir. Çok işlemcili sistemler yaygınlaştıkça süreçlerin haberleşmesi ve senkronizasyonu öne çıkar; Hoare bu sorunlara Dijkstra'nın çalışmalarını temel alan sistemli bir model sunar.

Hoca bunların doğru olduğunu, ama makalenin özet kısmında çok daha basit ve temel bir cümle bulunduğunu belirtti. Makalenin ilk cümlesi şudur: "This paper suggests that input and output are basic primitives of programming." Giriş ve çıkış diskten, kullanıcıdan ya da ağdan olabilir; ama programlama yapılıyorsa giriş ve çıkış olmadan program yazmak mümkün değildir. Dışarıdan hiç girdi almayan ve sonucunu dış dünyayla paylaşmayan bir program hiçbir işe yaramaz. Programlamanın temelinde bu vardır.

Bir öğrenci asıl sorunun çıktı üretmek değil girdi almak olduğunu, süreçler haberleşirken hangisinin ne zaman biteceğini ya da diğeriyle ne zaman iletişim kuracağını hesaplamanın zor olduğunu ekledi. Hoca, ilk cümlenin devamına dikkat çekti: eşzamanlı sıralı süreçlerin paralel bileşimi (parallel composition) de temel bir yapıdır. Çok işlemcili mimarilerdeki çok iş parçacıklı modeller aslında burayı referans alır. Her süreç girdiden çıktıya doğru ilerler; ama bu süreçler eşzamanlı, paralel ve birbiriyle iletişim içinde olacak biçimde birleştirilir. Bunların nasıl birleştirildiği doğrudan performansı etkiler; senkronizasyon ve eşzamanlılık kavramları buradan doğar.

### 8.2 Önceki yaklaşımlar

Hoca, Hoare'dan önce bu konuda neler önerildiğini sordu ve öğrencileri makalenin giriş kısmına yönlendirdi. Makalede, diğer önemli program yapılarının tasarımı konusunda daha az uzlaşma sağlandığı ve pek çok öneri yapıldığı yazar. Örnekler: altyordamlar, prosedürler (Algol 60), korutinler, sınıflar (Simula 67) ve Concurrent Pascal. Hoca sınıf kavramının 1967'de Simula 67'de bulunduğuna, yani yeni bir şey olmadığına dikkat çekti. Bir öğrenci semaforların ve koşullu kritik bölgelerin (conditional critical regions) de bu önceki çözümler arasında olduğunu belirtti. Makale, `while` ve `if-else` gibi üzerinde uzlaşılmış temel yapıları kabul eder; uzlaşma olmayan yer süreç yapılarıdır.

Öğrencilerin aktardığına göre Hoare, herkesin kabul edebileceği bir yapı kurmak için yöntemini dining philosophers, bounded buffer, monitörler, korutinler için kopyalama ve "squash" gibi örnekler, matris çarpımı gibi temel problemlerin çözümleriyle sınar. Hoca bunu, o güne kadar bilgisayar biliminde temel kabul edilen problemler için kendi yönteminin ürettiği çözümlerin avantaj, dezavantaj ve tutarlılığını sorgulamak olarak özetledi. Bir öğrenci makalenin ayrıca donanım-yazılım tasarımı, ağ protokolü, veritabanı ve işletim sistemi tasarımı gibi alanlarda uygulanabilirliği savunduğunu, daha kolay programlama sağladığını ileri sürdüğünü ekledi.

## 9. CSP'nin yedi temel önerisi

Bir öğrenci makalenin yedi temel önerisini saymaya başladı; hoca her birini makaleden okuyarak açıkladı.

### 9.1 Korumalı komutlar ve belirsizlik

Birinci öneri: Dijkstra'nın korumalı komutları (guarded commands), küçük bir gösterim değişikliğiyle, sıralı kontrol yapıları olarak ve belirsizliği (non-determinism) başlatmanın ve denetlemenin tek aracı olarak alınır.

Bir öğrenci korumaları, bir alana biri yazarken başkasının değiştirmemesi gereken bellek alanlarına erişimin kısıtlanması olarak, kritik bölgeye benzer biçimde açıkladı. Hoca belirsizliğin ne anlama geldiğini sordu. Öğrencinin örneği: iki süreç aynı yeri okuyup değiştiriyor ve sıraya konmuyorsa, 5 değeri iki kez artırıldığında 7 yerine 6 ya da başka bir değer çıkabilir. Hoca bunu şöyle genelleştirdi: çalışma sırası ya da zamanlaması sonucu değiştirmemelidir. Bir denetim mekanizması kurulmazsa çıkacak sonuç önceden bilinemez; bazen doğru, bazen yanlış sonuç üretilir. Bu istenmeyen bir belirsizliktir. Hocaya göre makalede kibarca "belirsizliği denetlemek" denen şey aslında onu bilimsel ve etkili biçimde ortadan kaldırmaktır.

Hoca "guard" kelimesini koruma görevlisi (bodyguard) benzetmesiyle açıkladı: o anda kaç süreç olursa olsun, korunan bölgeyle yalnız biri ilgilenir; o çıktıktan sonra diğeri girer.

### 9.2 Paralel komut

İkinci öneri: Dijkstra'nın `parbegin`'ine dayanan paralel komut, kendisini oluşturan sıralı komutların eşzamanlı çalışmasını belirtir. `parbegin A, B, C` denildiğinde A, B ve C süreçleri aynı zaman diliminde başlatılır. Başlatmanın kendisi de işlem gerektirdiği için aralarında örneğin 1 ya da 10 milisaniyelik farklar olabilir, ama aynı zaman dilimi içinde başlarlar. Makaleye göre bütün süreçler aynı anda başlar ve paralel komut ancak hepsi bittiğinde biter.

Hoca bunun nedenini sordu. Bu süreçler gelişigüzel değil, ortak bir amaç için birbirleriyle etkileşerek çalışan (kooperatif) süreçlerdir. Hocanın örneği: 1 milyon girdisi olan bir sözlükte belirli bir ölçütü sağlayan kelimeler 10 süreçle eşzamanlı aranıyor. Birinin bitmiş olması diğerlerinin de bittiği, bütün sonuçların bulunduğu anlamına gelmez; hepsinin bitmesi beklenmelidir.

Hocanın ikinci örneği Unix kabuğundan:

```text
cat dosya_adi | more
```

`more`, `cat` bittikten sonra başlasaydı bir anlamı olmazdı. `cat` çıktısının tamamını üretip bitirdikten sonra `more`'un sayfa sayfa gösterecek bir girdisi kalmazdı; `cat` bir terabayt veri basıyorsa, bir terabayt gönderildikten sonra `more`'u çalıştırmak anlamsızdır. İki süreç eşzamanlı başlamalıdır. Komut satırında boru (pipe) işaretiyle iki süreci bağlamak, aslında Dijkstra'nın `parbegin`'ini yapmaktır. Bu örnekte ilişki üretici-tüketici biçimindedir: `cat` üretir, `more` tüketir. Araya boru yerine `>` yönlendirmesi konsaydı, birinin çıktısı tamamlandıktan sonra diğeri tetiklenirdi; fark budur.

Makale ayrıca paralel komutla başlatılan süreçlerin global değişkenleri güncelleyerek birbirleriyle haberleşemeyeceğini söyler. Hoca bunun başka bir haberleşme yolu gerektirdiğini belirtti: ortak bellekte bir değeri yazıp okumak yoluyla ancak sınırlı veri aktarılabilir. Oysa borunun içinden byte'lar art arda, akış (stream) biçiminde bir süreçten diğerine geçer. Borunun disiplini FIFO ya da başka bir şey olabilir.

### 9.3 Giriş ve çıkış komutları

Üçüncü öneri ikinciyle bağlantılıdır: eşzamanlı süreçler arasındaki haberleşme için basit giriş ve çıkış komutları tanımlanır. Süreçler bellek üzerinden güncelleme yaparak konuşmayacaklarsa başka bir biçime ihtiyaç vardır; bu biçim giriş ve çıkış komutlarıdır.

### 9.4 Adlandırılmış haberleşme ve tamponsuz bekleme

Dördüncü öneri: haberleşme, bir süreç diğerini çıkış hedefi olarak, ikinci süreç de birinciyi giriş kaynağı olarak adlandırdığında gerçekleşir. Bu durumda çıkış değeri birinci süreçten ikinciye kopyalanır. Otomatik tamponlama yoktur. Genel olarak bir giriş ya da çıkış komutu, diğer süreç karşılık gelen çıkış ya da girişe hazır olana kadar bekletilir.

Hoca bunu isimli boruya (named pipe) benzetti: iki süreç rastgele değil, A "B ile konuşacağım", B de "A ile konuşacağım" diyerek eşleşir. Tamponsuzluğun önemi, `cat` örneğindeki sorunu çözmesidir: bir terabaytlık veri tamponlanmaya kalkılsaydı tamponun ne kadar büyük olacağı bilinemezdi. Bunun yerine, giriş almaya hazır olmayan bir süreç varsa çıkış yapan bekler; çıkış yapan hazır değilse giriş alan bekler. Böylece iki süreç arasında senkronizasyon ve birbirinin hızına uyum oluşur. Tampon kurulmadan tamponlanmış gibi bir etki elde edilir: yalnız birinin çalışması durdurulur, o süreç diğeri kabul edeceği zaman üretir.

**Soru:** Bu üretici-tüketici problemine benzemiyor mu? **Cevap:** Kesinlikle benziyor; tamponun dolu olduğu, tüketicinin tüketemediği ve üreticinin beklediği duruma denk geliyor.

Makaleye göre bu bekleme, bekletilen süreç için görünmezdir (invisible). Hocanın vurguladığı anlamı şudur: bekletilen süreç kendisini bekletmek için bir şey yapmaz, otomatik olarak bekletilir. Dolayısıyla Hoare bu yapıyı işletim sistemi düzeyinde önerir; süreçlerin bunun için birbirleriyle özel bir işlem yapmasına gerek yoktur. Programlar bu yaklaşıma uygun yazılırsa işletim sisteminin desteğiyle senkronizasyon kendiliğinden gerçekleşir.

> **Hocanın vurgusu:** Bekletmenin bekletilen süreç için görünmez olması çok önemlidir; senkronizasyonu süreç değil, işletim sistemi sağlar.

### 9.5 Giriş korumaları

Beşinci öneri: giriş komutları korumalarda yer alabilir. Giriş korumalı bir korumalı komut, yalnız giriş komutunda adı geçen kaynak karşılık gelen çıkış komutunu yürütmeye hazır olduğunda seçilir. Bir seçenekler kümesinde birden fazla giriş korumasının hazır kaynağı varsa yalnız biri seçilir, diğerlerinin etkisi olmaz; aralarındaki seçim keyfidir (arbitrary).

Hoca, işletim sistemi dersi almış öğrencilere bu tarifin günümüz senkronizasyon terminolojisinde hangi iki ilkele (primitive) denk düştüğünü sordu. Öğrenciler ikili semafor, exchange komutuyla yazılan kilit, test-and-set gibi cevaplar verdi. Hoca bunların yaklaşık olduğunu ama sorduğu ilkellerin wait ve signal olduğunu söyledi. "Seçim keyfidir" ifadesini signal all ile ilişkilendirdi: bekleyen birden fazla süreç sinyal alır ve bunlardan hangisinin çalışacağını işletim sistemi seçer.

> **Ek bilgi (derste anlatılmadı):** CSP'deki giriş korumalı alternatif komut, bugün Go dilindeki `select` ya da Unix'teki `select`/`poll` çağrılarına benzetilir: hazır olan kanallardan biri seçilip işlenir. Hocanın wait ve signal ile kurduğu bağ, koşul değişkenli monitörlerdeki bekleme ve uyandırma mantığına dayanan bir yorumdur.

Hoca, 1978'de tanımlanan bu yapının bugün semaforlar, kritik bölgeler ve üretici-tüketici çözümleri gibi pek çok yapının arkasında bilerek ya da bilmeyerek kullanıldığını vurguladı.

### 9.6 Tekrarlı komutun sonlanması

Altıncı öneriyi bir öğrenci açıkladı: giriş korumalı tekrarlı bir komut, girdi aldığı kaynak süreçlerin hepsi sonlandığında kendisi de sonlanır. Çıktı üretecek süreç sonlanmışsa onu bekleyen süreç bunu anlayıp kendini sonlandırabilir; böylece sonsuza kadar tüketmeye çalışan bir yapı sona erdirilir. Hoca bunu şöyle özetledi: bütün girdiler bittiyse, onlardan girdi alarak çıktı üreten tarafın çalışmaya devam etmesine gerek yoktur.

### 9.7 Örüntü eşleme ile filtreleme

Yedinci öneri: giriş ve çıkış birbirini karşılamalıdır. Bir süreç girdi için bir örüntü (pattern) belirleyebilir; bu örüntüye uymayan, kendisine gelen çıktıları girdi olarak kabul etmez. Hocaya göre bu, tam güvenli olmasa da güvenli sayılabilecek bir yaklaşımdır ve araya bir ölçüt, bir filtre koymayı sağlar. Hoca bunu ağ paketlerine benzetti: paketler sürekli gelir, ama paketteki protokole göre paketin IP'ye mi, TCP'ye mi, UDP'ye mi gideceği belirlenir. Süreçler giriş ve çıkış üzerinden etkileşirken ne tür girdi kabul edeceklerini ve ne zaman tetiklenip o girdiyi alarak çalışmaya başlayacaklarını belirleyebilmelidir. Hoca bunun çok basit ama etkili bir yöntem olduğunu belirtti.

## 10. CSP'nin gerçeklenebilirliği ve günümüze etkisi

Hoca makalenin devamındaki önemli bir cümleyi de okudu: önerilen dilde yazılan programlar hem tek bir ana belleği (main store) olan geleneksel bir makinede hem de giriş-çıkış kanallarıyla bağlı sabit bir işlemci ağında gerçeklenebilecek biçimde tasarlanmıştır. Yani CSP'yi gerçeklemek için özel bir donanım gerekmez.

Bunun sonucu olarak dil oldukça statiktir: program metni (yani kod), eşzamanlı çalışan süreç sayısına sabit bir üst sınır koyar. Özyineleme yoktur ve süreç değerli değişken (process-valued variable) olanağı yoktur.

**Soru:** "Process-valued variables" ne demek? **Cevap:** Hocanın açıklamasıyla, sürece özgü değeri olan değişkenlere ihtiyaç duyulmaz; süreçler ortak bir bellek üzerinden konuşmak zorunda değildir, aralarında önceki cümlede geçen giriş-çıkış kanalları vardır.

> **Ek bilgi (derste anlatılmadı):** "Process-valued variable", değeri bir süreç olan, yani süreçlerin bir değişkende tutulup aktarılabildiği, çalışma anında dinamik süreç oluşturmayı mümkün kılan değişkendir. CSP'de bu olmadığı için süreçlerin sayısı ve adları program metninde sabittir; hocanın vurguladığı "statik dil" özelliği buradan gelir.

Hoca, makalede çözülen bounded buffer ve dining philosophers problemlerinin daha da eski problemler olduğunu, makalede port adı (port name) kavramının da geçtiğini hatırlattı. Port kavramı hem yerelde isimli borular üzerinden hem ağ programlamadaki portlar üzerinden bugün kullanılmaktadır. Bir öğrencinin daha güncel makale isteğine hoca, 1978'de yazılmış bir makalede söylenenlerin 45 yıl sonra hâlâ kullanıldığını, makalenin günümüzü etkilemiş olmasının değerini gösterdiğini söyledi.

## Örnek Sorular

Bu derste ekranda soru gösterilmedi; aşağıdaki sorular hocanın derste sözlü olarak sorduğu sorulardır.

1. (derste sözlü, 00:13:33) 4K'lık 10 taban sayfa birleştirilerek 40K'lık bir süper sayfa yapılırsa, bu süper sayfanın fiziksel taraftaki çerçeve karşılığı nasıl olmalıdır? Neden?

   > **Çözüm:** Çerçeveler fiziksel bellekte ardışık olmalıdır. Süper sayfaya tek bir girdiyle erişildiğinde offset 0'dan 40K'ya kadar sıralı ilerler; bir çerçeveden ötekine atlanamaz. Ardışık olmazsa offset'in gösterdiği yerde başka bir sürecin çerçevesi bulunabilir. $10 \times 4\text{K} = 40\text{K}$.

2. (derste sözlü, 00:14:47) Sayfa ve çerçeve yapısı hangi sorunu çözmek için getirilmiştir? TLB erişimini azaltmak için sayfaları birleştirmeye başladığımızda bu sorun yeniden ortaya çıkar mı?

   > **Çözüm:** Sayfa ve çerçeve yapısı, süreçlerin fiziksel bellekte tek parça yer bulma zorunluluğunu ve dış parçalanmayı ortadan kaldırmak için getirilmiştir. Süper sayfalar fiziksel bitişiklik istediği için, kontrolsüz büyütülürlerse sorun geri gelir: toplamda yeterli boş bellek olsa da tek parça alan bulunamayabilir.

3. (derste sözlü, 00:21:55) Compaction, defragmentation ve (sıkıştırma yapan) garbage collection işlemlerinin ortak temel sıkıntısı nedir?

   > **Çözüm:** Zaman. Boş ve dolu alanları ayırmak için bellekten belleğe kopyalama gerekir; kopyalanan alanı kullanan süreçler bu sırada çalışamaz, durdurulmaları gerekir. Bu da sistemin öngörülemeyen anlarda duraklaması demektir.

4. (derste sözlü, 00:36:20) Relocation tabanlı süper sayfa tahsisi ne zaman en iyi çalışır, ne zaman sorun çıkarır?

   > **Çözüm:** Boş bellek büyük ve bitişik alanlar bol olduğunda iyi çalışır, çünkü yer değiştirmeye nadiren ihtiyaç duyulur. Süreç sayısı arttıkça ya da bellek kısıtlı oldukça sürekli kopyalama, sonunda da bütün süreçleri durduran compaction gerekir.

5. (derste sözlü, 00:42:36) Rezervasyona dayalı tahsiste incremental promotion nereye kadar sürdürülebilir?

   > **Çözüm:** Rezervasyonun sınırına kadar. Bitişiklik yalnız rezerve edilen fiziksel alan içinde garanti edilir; dışında başka bir sürece ait çerçeve bulunabilir.

6. (derste sözlü, 00:44:52) Demotion'daki temel problem nedir?

   > **Çözüm:** Donanım dirty biti çerçeve başına tutar, ama süper sayfa için tek bir bilgi kalır. Hangi taban sayfanın değiştiği bilinemediği için süper sayfanın hangi kısmına küçültüleceğine karar vermek zorlaşır.

7. (derste sözlü, 00:49:06) Kirli olduğu için diske yazılmış bir süper sayfanın taban sayfaları diske yazıldıktan sonra hangi durumdadır?

   > **Çözüm:** Hepsi temizdir (clean); içerikleri diske kaydedilmiş, bilinen bir duruma gelmiştir.

8. (derste sözlü, 00:57:42) Kirli taban sayfaları bulmak için kullanılan kriptografik özette bit sayısı neden önemlidir?

   > **Çözüm:** Donanımda kendiliğinden bit değişmeleri (bit flip) olabilir. Özetin çakışma olasılığı bu donanım hatası olasılığından çok daha küçük olmalıdır ki yöntem güvenli sayılsın. 160 bitlik bir özette doğum günü sınırıyla çakışma olasılığı yaklaşık $2^{-80}$'dir.

9. (derste sözlü, 01:30:33) `cat dosya_adi | more` komutunda `more`, `cat` bittikten sonra başlasaydı bir anlamı olur muydu? Boru yerine `>` kullanılsaydı ne değişirdi?

   > **Çözüm:** Olmazdı; iki süreç eşzamanlı başlamalıdır, `cat` üretirken `more` tüketir. Bu, Dijkstra'nın `parbegin`'inin günlük bir örneğidir. `>` ile yönlendirmede ise birinin çıktısı tamamlandıktan sonra diğeri tetiklenir.

10. (derste sözlü, 01:24:35) CSP'de korumalı komutların "belirsizliği denetlemek" için kullanılması ne anlama gelir?

    > **Çözüm:** Eşzamanlı süreçler ortak bir değeri sırasız güncellerse sonuç çalışma sırasına ve zamanlamaya bağlı olur (örneğin 5 değeri iki kez artırılınca 7 yerine 6 çıkabilir). Korumalar kritik bölgeye aynı anda yalnız bir sürecin girmesini sağlayarak sonucun sıradan bağımsız olmasını sağlar; hocaya göre "denetlemek" aslında istenmeyen belirsizliği ortadan kaldırmaktır.

11. (derste sözlü, 01:38:58) CSP'nin beşinci önerisinde tarif edilen davranış (birden fazla giriş koruması hazırsa yalnız birinin keyfi seçilmesi) günümüz senkronizasyon terminolojisinde hangi iki ilkele denk düşer?

    > **Çözüm:** Hocanın verdiği cevap wait ve signal'dir; keyfi seçim, signal all ile uyandırılan birden fazla süreçten birinin işletim sistemi tarafından seçilmesine benzetildi.

## Dersin Toparlaması

Bu derste iki makale üzerinden işletim sistemlerinin iki temel konusu tartışıldı. Süper sayfa makalesinde TLB kapsamını artırmak için taban sayfaların tek bir TLB girdisiyle erişilen süper sayfalarda birleştirilmesi incelendi. Hocanın öne çıkardığı nokta, süper sayfanın fiziksel bitişiklik istediği için sayfa ve çerçeve yapısının çözdüğü parçalanma ve compaction sorununu geri getirme riskidir. Relocation tabanlı tahsis kopyalama, rezervasyon tabanlı tahsis ise önceden kestirim gerektirir; rezervasyon içinde incremental promotion, demotion ve eviction ile kontrollü bir yapı kurulur. Süper sayfa başına tek dirty bit tutulması eviction maliyetini artırır; taban sayfa başına kriptografik özet bu sorunu çözse de hesap maliyeti yüksektir.

CSP makalesinde ise giriş ve çıkışın programlamanın temel ilkelleri olduğu, eşzamanlı sıralı süreçlerin korumalı komutlar, paralel komut ve birbirini adlandıran, tamponsuz ve otomatik bekletmeli giriş-çıkış komutlarıyla haberleştiği bir model ele alındı. Hoca bu fikirlerin bugünkü borular, portlar, üretici-tüketici çözümleri ve senkronizasyon ilkellerinin temelinde yattığını vurguladı. Bir sonraki dersin konularından birinin monitörler ve bu mantık üzerine kurulu, kendine özgü bir dili olan deneysel bir işletim sistemi ile Mesa dili olacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
