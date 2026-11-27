# Ders 11 Genişletilmiş Notu: Kodlama, Yazılım Kalitesi, Test, Yeni Sisteme Geçiş, Bakım ve Spor Salonu Örnek Vakası

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yeri: sistem geliştirme sürecinin son aşamaları
- 2. Kodlama
- 3. Programlama dili ve ortamının seçimi
- 4. Yazılım kalitesi ve kalite faktörleri
- 5. Yazılımda kalitenin sağlanması
- 6. Test türleri ve test adımları
- 7. Yeni sisteme geçiş
- 8. Bakım ve bir bilgi sisteminin ömrü
- 9. Örnek vaka çalışması: spor salonu sistemi
- Örnek Sorular

## 1. Dersin yeri: sistem geliştirme sürecinin son aşamaları

Bu ders, dönem boyunca anlatılan sistem geliştirme sürecinin son halkalarını tamamlar. Ön inceleme ve fizibilitesi yapılmış, analizle problemi modellenmiş, tasarımla çözüm önerisi ortaya konmuş bir sistem artık kodlanacak (gerçekleştirilecek), test edilerek gereksinimleri karşıladığı onaylanacak, devreye alınacak ve bakımı yapılacaktır. Ders dört başlıkta ilerler: kodlama ve yazılım kalitesi, kaliteyi destekleyen test teknikleri, yeni sisteme geçiş yöntemleri ve bakım. Sonunda basit bir proje (spor salonu sistemi) üzerinden analiz ve tasarım adımlarının uçtan uca kısa bir gösterimi yapılır (ekrandan, 00:05:00).

## 2. Kodlama

### 2.1 Kodlamaya ne zaman geçilir?

Slayttaki ilk ilke şudur: kodlama, tasarım tamamlanıp diyagram, algoritma ve sözde kodlar oluşturulduktan sonra yapılır (ekrandan, 00:10:00). Küçük ödevlerde doğrudan oturup kod yazmaya başlamak mümkün olabilir; ama büyük ölçekli bir bilgi sisteminde "sen şu modülü yaz, sen bunu bağla, şu sınıflar sende olsun" diye işe başlanamaz. Ortada formal olarak ifade edilmiş bir çözüm önerisi, yani tasarım bulunmalıdır.

Tasarım bile tek başına yeterli değildir. Önceki derslerde ardışıl (sıralama) diyagramlarıyla nesnelerin bir sorumluluğu birlikte nasıl yerine getirdiği gösterilmişti; ama bu diyagramlar algoritmayı içermez. Algoritmalar için akış diyagramları ve sözde kodlar (pseudocode) yazılır, başka diyagramlar da çizilir. Bunlardan sonra kodlamaya geçilir.

Nesneye yönelik bir sistemde kodlamaya en az bağımlı birimden başlayıp en çok bağımlı, yani en karmaşık birime doğru ilerlemek daha doğru bir yaklaşımdır. Programlama dillerinin ayrıntısı ayrı derslerin konusu olduğu için burada yalnız bakım yapılabilirliği ve sürdürülebilirliği sağlamak için kodlamada dikkat edilmesi gereken başlıklar ele alınır.

### 2.2 Spesifikasyonlar ve okunabilir kod

Slayta göre kodlama spesifikasyonlara uymalı, kolay okunabilmeli, düzenlenebilmeli, test edilebilmeli ve değiştirilebilmelidir (ekrandan, 00:10:00). Spesifikasyon, kod yazım şekline dair formal tanımlardır: bir şirket politikası olabilir ya da ISO, IEEE gibi kuruluşların standartları izlenebilir. Bu tanımlar ekip içi iletişimi kolaylaştırır ve koda sonradan başka biri geldiğinde onun daha kolay çalışmasını garanti eder. Spesifikasyonlara uyulursa kodlama kalitesi doğal olarak artar.

Zaman baskısıyla ("üç saat içinde şu modül bitmeli, beş saat içinde şu servise bağlanmalı") kod aceleyle yazılabilir; ama mümkünse ardından kod elden geçirilmeli, okunaklı ve düzenlenebilir hale getirilmelidir. Kodun başkaları tarafından da değiştirilebilir olması esastır.

### 2.3 Kodlama standartlarının temel kuralları

Slaytta belirlenen kodlama standartlarına uyulması gerektiği ve bunun iki alt maddesi verilir: açıklama satırları kullanılmalı, kod yazım deseni kullanılmalı. Ayrıca anlamlı isimlendirmeler yapılmalıdır (ekrandan, 00:10:00).

**Açıklama satırları.** Genellikle atlanan ya da savsaklanan bir iştir. Bazen bir satır kod için on satır açıklama yazılabilir: kodun ne yaptığı, neye bağlandığı, tasarımın hangi kısmıyla ilgili olduğu, ne aldığı ve ne verdiği, kimin yazdığı, hangi sürümde olduğu. Açıklamalar belli bir desene uygun yazılırsa .NET, Java ya da Python gibi ortamlar bunlardan API dokümantasyonunu otomatik üretebilir. Böylece ayrıca bir dokümantasyon yazma ve onun bakımını üstlenme sorumluluğundan kurtulunur; kod ve dokümantasyon tek bir çözümde birleşir.

**Kod yazım deseni.** Bir projede bütün birimlerde aynı desen kullanılmalıdır. Değişkenler Türkçe mi İngilizce mi adlandırılıyor, camel case mi başka bir biçim mi kullanılıyor sorularının cevabı ne olursa olsun önemli olan tutarlılıktır. <!-- BELİRSİZ: altyazıda camel case ile karşılaştırılan ikinci yazım biçiminin adı "Jason Style" olarak geçiyor; hangi biçim kastedildiği anlaşılmıyor. -->

**Anlamlı isimlendirme.** Fonksiyon ve nesne adları genellikle bir ölçüde anlamlı verilir; ama bir fonksiyonun içindeki değişkenlere, dizilere ve veri yapılarına çoğu zaman A, B, C gibi adlar verilir. Yazdıktan hemen sonra A dizisinin neyi tuttuğu hatırlanabilir, on beş gün sonra biraz düşünerek bulunabilir; ama daha uzun süre geçtikten sonra ya da başkasının kodunu çözmek gerektiğinde "A ne, B ne, X, Y, Z ne?" sorusuyla kalınır. Değişkenlere, fonksiyonlara, bloklara ve nesnelerin iç yapılarına anlamlı adlar vermek gerekir. Bu kurallar genellikle hız uğruna atlanır, ama sonunda hepsi kaliteye bağlanır; baştan doğru yapılırsa sonradan fazladan emek harcamak gerekmez.

## 3. Programlama dili ve ortamının seçimi

Kodlamanın hangi dil ya da diller ve hangi geliştirme ortamı (IDE) ile yapılacağı aslında daha önce belirlenmişti. Slayttaki ifadeyle gereksinimlere uygun olacak dil(ler) fizibilitede seçilip ön tasarım aşamasında kesinleştirilmiştir (ekrandan, 00:15:00). Teknik fizibilitede diller ve ortamlar karşılaştırılmış, projeye neden uygun oldukları gösterilmiş; tasarımda da bunlar kesinleşmiş, gerekiyorsa alım ve kurulumları yapılmıştır. Slaytta dil seçiminde dikkat edilmesi gereken yedi faktör sıralanır:

- Genel uygulama alanı
- Algoritma ve veri yapılarının karmaşıklığı
- Yazılımın kullanılacağı ortam
- Uygulama koşulları
- Personelin bilgi düzeyi
- Yapılacak yatırım miktarı
- Müşteri koşulları

### 3.1 Uygulama alanı ve algoritma karmaşıklığı

Bazı diller web ortamlarına, bazıları matematiksel hesaplara, bazıları veri depolama ve sorgulama ya da işlem tabanlı (transaction processing) çalışmalara daha uygundur. Amacına ya da uygulama alanına uymayan bir dil seçimi geliştirmeyi zorlaştırır; bu aynı zamanda fizibilitenin düzgün yapılmadığını gösterir.

Algoritmalarda kullanılacak veri yapılarının dilde ve kütüphanelerinde bulunup bulunmadığı, yoksa sıfırdan mı yazılacağı, bunların karmaşıklığı ve ne kadarının hazır hizmet ya da kütüphane olarak kullanılabileceği de seçimde önemli bir faktördür.

### 3.2 Kullanım ortamı ve uygulama koşulları

Bankacılık gibi çok sayıda işlem ve veri içeren bir uygulamada, bugün pek çok alternatif olsa da COBOL hâlâ işlem ve kayıt tabanlı işlerde çok etkin çalışır, çünkü doğrudan bu alan için tasarlanmıştır. Ama aynı dille mobil bir uygulama geliştirilemez; ana bilgisayarda (mainframe) çalışan bir işlem sistemi için tasarlanmış bir dil, Intel ya da ARM işlemcili sıradan bir bilgisayarda kullanılamaz.

Sanal makine üzerinde çalışan, ara kod üreten Java ve .NET gibi platformlar taşınabilirlikleri nedeniyle yaygınlaşmıştır. Yine de bazen yerel (native) dile ihtiyaç duyulur. React Native ya da Flutter gibi hibrit ortamlar hem iOS hem Android için kod üretmeyi sağlar ama sınırları vardır; mobil cihazdaki sensörlerin belli özelliklerini derinlemesine kullanmak gerekiyorsa Kotlin gibi yerel bir dil gerekebilir. Hoca kullanım ortamını ve uygulama koşullarını (çalışma ve kullanım koşulları) bu bağlamda birlikte ele alır.

### 3.3 Personel, yatırım ve müşteri koşulları

Çok etkin bir dil bulunsa bile ekipte onu bilen yoksa eğitim ve öğrenme süreci gerekir; üstelik iyi bilinen bir dil kadar etkin kullanılamaz. Dilin ya da ortamın lisans bedeli kullanıcı başına ya da geliştirici başına yüksekse büyük bir yatırım gerekir; bu da ekonomik fizibiliteyi, kâra geçiş noktasını sarsabilir.

Müşteri koşulları diğer kriterlerin önüne geçebilir. Ekip daha önceki projelerinde .NET Core kullandığı için onu tercih etmek isteyebilir; ama müşteri "sunucu tarafında yalnız PHP kullanıyorum, sistem buna entegre olmalı" derse dil PHP olur. Hoca bu örnekle şunu vurgular: en uygun dili seçmek istenir ama "en uygun" her zaman teknik açıdan en iyi olan değildir; farklı kriterler birlikte etki ederek seçimi belirler ve amaç bunlar arasında optimum olanı bulmaktır.

## 4. Yazılım kalitesi ve kalite faktörleri

### 4.1 Kalitenin tanımı

Kodlamada bunca kurala dikkat etmenin amacı kaliteyi artırmaktır. Slayttaki formal tanım şudur: **Kalite, işlevsel gereksinimlere, geliştirme standartlarına ve beklenen tüm özelliklere tamamen uygun yazılımdır** (ekrandan, 00:25:00).

Hoca bu tanımda "beklenen tüm özellikler" kısmının işlevsel olmayan gereksinimleri işaret ettiğini vurgular: performans, toplam kullanıcı sayısı, birim zamanda yapılan işlem garantisi, birim zamanda okunan ve yazılan veri miktarının garantisi gibi. Yazılım kalitesi denince anlaşılması gereken asıl şey işlevsel olmayan gereksinimlerin tamamıdır. Bunlar tasarımı da doğrudan değiştirir: tek sunuculu basit bir uygulama ve bir iş katmanı yeterli olabilir; ama örneğin bir video sunucusu gibi aynı anda çok sayıda yayın yapması beklenen bir sistemde bütün tasarım değişir, sistemi dağıtık bir mimaride paralelleştirmek gerekir.

### 4.2 Kalite faktörleri

Slaytta on bir kalite faktörü sıralanır (ekrandan, 00:25:00):

- Doğruluk
- Güvenilirlik
- Verimlilik
- Güvenlik
- Kullanışlılık
- Hata bulma kolaylığı
- Esneklik
- Sınama kolaylığı
- Taşınabilirlik
- Tekrar kullanılabilirlik
- Bağlanabilirlik

**Doğruluk**, sistemin işlevsel gereksinimleri beklendiği gibi yerine getirmesi, doğru girdiden doğru çıktı üretmesi, yanlış çalışmamasıdır. Hata (bug) olmaması ya da hata olacaksa hatalı işlemlerin kontrol edilip engellenmesi diye de düşünülebilir.

**Güvenilirlik** (reliability), sisteme ne kadar güvenilebileceği ve hangi stres altında çalışmaya devam edebileceğidir. Örneğin bir ders seçim sisteminde aynı anda kaç öğrencinin ders seçebileceği ya da kaç ders seçimine kadar sistemin güvenilir hizmet vermeyi sürdüreceği bir stres beklentisidir.

**Verimlilik**, hizmeti sunarken belleğin, işlemcinin ve diğer kaynakların ne kadar harcandığıdır; kaynakların ölçülü kullanılması beklenir.

**Güvenlik** (security), yetkisiz işlemlerin yapılmaması ve yasal olmayan yollarla erişime izin verilmemesidir.

**Kullanışlılık**, kullanıcının gereksiz kontrollerle uğraşmadan girdisini hızlı ve etkin biçimde verip hizmetini alabilmesidir.

Kalite yalnız kullanıcı tarafından bakılarak değerlendirilmez; teknik personel açısından da faktörler vardır. **Hata bulma kolaylığı**, bir hata oluştuğunda onun kolayca bulunabilmesidir; önceki bölümdeki kodlama kurallarına ne kadar uyulursa bu faktör o kadar iyi karşılanır. **Esneklik**, değişen koşullara uyum sağlayabilme ve farklı koşullar altında hizmet vermeye devam edebilmedir. **Sınama kolaylığı**, bir testi yapmanın zahmetli olmamasıdır; özellikle regresyon testlerini yapan test otomasyonu araçlarına uygun bir yazılım daha kalitelidir. **Taşınabilirlik**, yazılımın farklı ortamlarda çalışıp hizmet verebilmesidir. **Tekrar kullanılabilirlik**, yazılımın parçalarının (bir sınıfın, bir API'nin, bir adaptör grubunun) alınıp başka bir uygulamada ya da serviste kullanılabilmesidir. **Bağlanabilirlik**, dış sistemlerin ne kadar kolay ve hangi koşullarda bağlanabildiğidir. Belli bir protokol, belli port ayarları gibi çok sayıda şart koşan bir sistem bağlanması zor bir sistemdir; "şu API'ye şu formatta gönder, yeter" diyebilen bir sistem daha kolay bağlanır ve daha esnektir.

Hoca yazılım kalitesinin ayrı bir dersin konusu olduğunu, burada yalnız ana başlıkların anılıp geçildiğini belirtir.

## 5. Yazılımda kalitenin sağlanması

Özellikle ekiplerce geliştirilen sistemlerde herkes farklı biçimde çalışabilir; bunu homojen hale getirmek, kontrol etmek ve denetlemek zordur. Bu yüzden kalite çalışmalarının da tanımlı, formal ve belgelenmiş biçimde yürütülmesi gerekir. Slayttaki maddeler şunlardır (ekrandan, 00:30:00):

- Planlama aşamasında kalite kontrolü yöntem ve araçları belirlenmeli.
- Geliştirme sürecinde durak noktalarında yapılanlar gözden geçirilmeli.
- Kaynak program sınanmalı.
- Gerçekleştirilmiş projenin gereksinimleri karşılaması gözden geçirilmeli.
- Bunlar plan dahilinde yapılmalı: yazılım inceleme planı, kaynak programı sınama planı, kabul muayene planı.

### 5.1 Kalite kontrol yönteminin baştan belirlenmesi

Daha sistem geliştirilmeden, planlama ve ön inceleme safhasında, yönetim kademesi (proje yöneticisi ya da ekip lideri) bir kalite kontrol yöntemi belirlemelidir: hangi kalite faktörlerinin nasıl karşılanacağını garanti etmek için hangi kontrollerin hangi yordamla yapılacağı, kullanılacak izleme ve ölçüm araçları ve metrikler baştan yazılmalıdır. Kalite kontrolü tanımlanmadan kontrol edilemez; kontrol edilmeyen kalite de ölçülemez, yani sistemin kaliteli olup olmadığı hakkında yorum yapılamaz. Hoca bunun teknik personelden çok yönetim kademesinin işi olduğunu belirtir.

### 5.2 Durak noktalarında gözden geçirme

Analiz, tasarım ve gerçekleştirme sırasında daha önce sözü edilen kilometre taşları (milestone, durak noktaları) tanımlanmalı ve bu noktalarda durup bir gözden geçirme (review) yapılmalıdır. Adım adım kalitenin sağlanıp sağlanmadığı, risklerin oluşup oluşmadığı ya da oluşabileceği değerlendirilir; kötüye giden bir şey fark edilirse revizyonlar, eklemeler ya da çıkarmalar yapılır. Kalite yalnız başta planlanmakla kalmaz, süreç boyunca kontrol edilmeye devam edilir.

### 5.3 Kaynak programın sınanması ve gereksinimlerin gözden geçirilmesi

Kaliteyi sağlamanın bir diğer unsuru testtir: kaynak kodlardan başlayarak modüller, bütün program ve bunların birlikte çalışması farklı kademelerde test edilmelidir. Ancak testler kodun doğru çalıştığını (örneğin doğruluk ve verimlilik faktörlerinin karşılandığını) gösterse bile, sistemin gerçekten istenen şeyi yapıp yapmadığı ayrıca gözden geçirilmelidir. Bu, kullanıcı kabul testi (UAT) ile, müşteri ya da kullanıcı gözüyle yapılır.

### 5.4 Üç plan

Bütün bunlar rastgele değil, önceden belirlenmiş planlar dahilinde yapılır:

- **Yazılım inceleme planı:** geliştirme sürecinin tamamının nasıl izleneceği, hangi kilometre taşlarının olacağı (belli tarihler, belli bir aşamanın bitişi, belli bir ekibin belli bir teslimi), bu noktalarda neler yapılacağı ve risk oluşursa hangi önlemlerin alınacağı yazılır.
- **Kaynak programı sınama planı (test planı):** neyin nasıl test edileceği ve test sonuçlarına göre hangi aksiyonların alınacağı belirlenir. Hoca test planı olmadan yola çıkan bir ekibin "kafası kesik tavuk gibi" ortada dolaşacağını söyler. Bu da yöneticinin takip etmesi gereken bir iştir.
- **Kabul muayene planı:** ürün bitip müşteriye son hali gösterildiğinde gereksinimlerin karşılanıp karşılanmadığının nasıl değerlendirileceği, kabul testinin nasıl yapılacağı ve hangi ölçütlerle kabul edilip edilmeyeceği formal olarak yazılır.

Hoca kaliteyi kolları birbirine dolanmış çok kollu bir ahtapota benzetir: bir faktör karşılandığında iş bitmiş sayılmaz, çünkü başka faktörler de kaliteyi olumlu ya da olumsuz etkiler.

## 6. Test türleri ve test adımları

### 6.1 Test türleri

Testler hataları bulmak ve ortaya çıkarmak için yapılır. Derste dört test türü anlatılır:

- **Fonksiyonel (işlev) testler:** girdi-işlem-çıktı döngüsünün doğru olup olmadığını sınar. Uç değer analizi de bu gruptadır; örneğin negatif bir sayının karekökü alınmaya çalışıldığında sistemin nasıl davrandığını kontrol etmek bir fonksiyonel testtir.
- **Performans testleri:** tepki süresi, bellek kullanımı, iletişim hızı gibi darboğazları ve kaliteyi bozabilecek faktörleri ortaya çıkarır.
- **Dayanıklılık (stres) testleri:** aşırı yüklenme durumunda sistemin davranışını sınar. Ağ bant genişliği çok düştüğünde sistem bunu telafi edebiliyor mu, yoksa çöküyor mu; kullanıcı sayısı aşırı arttığında ne oluyor gibi sorulara cevap arar.
- **Yapısal testler:** iç işleyiş testleridir. Fonksiyonel teste benzer ama bütün parçaların, birimlerin ve modüllerin mantıksal çalışma yollarının ve senaryolarının doğru işleyip işlemediğini, sorumlulukların doğru yerine getirilip getirilmediğini sınar.

Performans ve dayanıklılık gibi testler aslında sistem testleri grubundadır.

### 6.2 Test adımları ve spiral şema

Bir bilgi sistemi sınanırken izlenen temel adımlar şunlardır:

- **Birim (ünite) testi:** proje olsun olmasın, yazılan bütün kodlar için ilk önce mutlaka yapılması gereken testtir.
- **Bütünleme testi:** yapısal testlere karşılık gelir; yapısal ve fonksiyonel yönler burada karışıktır.
- **Onaylama testi:** kabul testi, kullanıcı kabul testi (user acceptance test) olarak da bilinir.
- **Sistem testi:** performans, dayanıklılık gibi testler son aşamada sistem testi olarak yapılır.

Slayttaki "Test Adımları" şeması, içten dışa açılan bir spiral (salyangoz) biçimindedir (ekrandan, 00:40:00). Spiralin sol tarafında geliştirme katmanları, sağ tarafında bunları sınayan testler yer alır:

```text
Geliştirme katmanı (spiralde)      Sınayan test
---------------------------------  -----------------
Kodlama (K)                    ->  Ünite testi (Ü)
Tasarım (T)                    ->  Bütünleme testi (B)
Sistem gereksinimleri (G)      ->  Onaylama testi (O)
Sistem geliştirme (S)          ->  Sistem testi (ST)
```

Spiralin en içinde kodlama vardır ve kodlama birim testleriyle sınanır. Bir dış katmanda tasarım vardır; tasarımı sınamak için bütünleme testi yapılır: parçalar bir arada düzgün çalışacak mı, ortaya konan çözüm gerçekten işlevsel bir çözüm mü? Hoca bunu bir araba motoruna benzetir. Önce her parça kendi içinde test edilir (basınç, sıcaklık dayanımı, sıvı dayanımı, germe ve çekme gerilmeleri); bu birim testidir. Motorun bütün parçaları bir araya getirilip ilk çalıştırma yapıldığında parçaların birlikte düzgün çalışıp çalışmadığına bakılır; bu da bütünleme testidir. Yazılımda da sınıfların, modüllerin ve servislerin bütünleştiğinde doğru çalışıp çalışmadığı bütünleme testiyle sınanır.

Parçalar birlikte düzgün çalışıyorsa, yani düzgün bir tasarım yapılmışsa, sıradaki soru şudur: ürün doğru yapıldı ama doğru ürün mü yapıldı? Gereksinimleri karşılayan, beklentileri yerine getiren bir ürün mü ortaya çıktı? Bu, onaylama (kabul) testiyle sınanır ve doğrudan sistem gereksinimlerine karşılık gelir: use case'lerde ya da iş gereksinimleri dokümanında (BRD) yazılan süreçlerin beklentiyi karşılayacak biçimde gerçekleştirilip gerçekleştirilmediği kontrol edilir.

> **Hocanın vurgusu:** Birim ve bütünleme testleri "ürünü doğru yaptım mı" sorusunu, onaylama testi ise "doğru ürünü yaptım mı" sorusunu cevaplar.

En dışta sistem geliştirme sürecinin tamamı vardır; geri kalan kalite kriterleri sistem testleriyle (dayanıklılık, performans gibi) sınanır.

### 6.3 Adımların özeti

Hoca adımları bir kez daha özetler:

- Birim testi her modüle ve birime ayrı ayrı uygulanır; kod doğruluğu test edilir.
- Modüller bağlanarak sistem bir araya geldiğinde bütünleme testi yapılır. Bütün parçalar birleştikten sonra tek seferde yapılabilir ama bu çok zordur; genellikle artımlı olarak, modüller geliştikçe ve birleştikçe yapmak daha doğrudur.
- Onaylama testinde gereksinimlerin ne kadar karşılandığına bakılır.
- Sistem testinde bütün birimler birlikte test edilir; düzeltilmesi gereken hatalar ortaya çıkar. Güvenlik testleri, dayanıklılık testleri, performans testleri ve darboğaz analizi genel sistem testleri olarak adlandırılır.

Bu dört adım ve içlerindeki testler, sürecin bütün adımlarında doğru şeylerin üretilip üretilmediğini görmek için yapılır.

### 6.4 Testlerin yinelemeli doğası

Kodlama sırasında birim ve bütünleme testleri, ortaya çıkan ürün üzerinde de kabul testleri yapılır. Bulunan hataların bir kısmı yalnız kodda olabilir ve kod düzeltilir. Bir kısmı tasarım hatasıdır; tasarım ve gerçekleştirme güncellenir, yeniden test edilir. Kabul testinde "değil" denirse bir revizyon daha yapılır; süreç bu şekilde yinelemeli devam eder.

En kötü durum, kabul testinde gereksinimin yanlış anlaşıldığının ortaya çıkmasıdır (hocanın verdiği örnekte müşterinin, notların sistemdeki gibi hesaplanmadığını, dönem bazlı bir hesap gerektiğini söylemesi). <!-- BELİRSİZ: 00:44:06 civarındaki örnek altyazıda kopuk; müşterinin kabul testinde dile getirdiği eksik gereksinimin tam içeriği net değil. --> Böyle bir hata analize kadar geri gidip problem uzayında değişiklik yapmayı gerektirir: analizler, buna göre tasarım ve gerçekleştirme güncellenir ve hepsinin testleri yeniden yapılır. Bunun maliyeti her zaman daha yüksektir. Testler kullanıcı kabul edene kadar sürer ve sonunda beklenen hizmeti sağlayan bilgi sistemi geliştirilmiş olur.

## 7. Yeni sisteme geçiş

### 7.1 Geçiş adımları

Testlerden başarıyla çıkmış yeni bir sistem vardır; şimdi bu sistemin devreye alınması gerekir. Bu, bir yükleme dosyasını çift tıklayıp "İleri, İleri, Çalıştır" demek kadar basit değildir. Slayttaki geçiş adımları şunlardır (ekrandan, 00:45:00):

- Ön tasarımda belirlenen donanımın kurulumu
- Ağ yapısının oluşturulması
- Kayıtların yeni sisteme aktarılması
- Eğitim: sistemle ilgilenecekler, uç kullanıcılar, üst yönetim
- Devreye alma

Artık geliştirme ortamında değil, işletim (production) ortamındayız. Fizibilitede ve ön tasarımda kesinleşen donanımların kurulması ve test edilmesi, ağ ve bağlı diğer sistemlerle iletişim altyapısının kurulup test edilmesi gerekir.

Başka ortamlarda tutulan verilerin (örneğin eski sistemin veri tabanının) yeni sisteme aktarılması ve entegre edilmesi çoğu zaman çok zahmetlidir. Bu iş bazen başlı başına ayrı bir proje olarak ele alınır ve veri taşıma projesi (data migration project) diye adlandırılır; özellikle büyük iş yerlerinde ya da holding ölçeğindeki kurumlarda yalnız bu dönüşüm için ayrı geçiş projeleri gerekebilir.

Eğitim, sisteme dokunan bütün taraflar için planlanmalıdır. Sistemi kullanacak uç (son) kullanıcılara, yani operatörlere neyi nasıl yapacakları öğretilir. Yönetime hangi raporları alabileceği, hangi sorgulamaları yapabileceği, hangi gösterge panellerinin (dashboard) olduğu, rollerin ve güvenliğin nasıl işlediği anlatılır. Sistemin ayakta ve devrede kalmasını sağlayacak teknik (destek) personel de nasıl destek vereceğini bilecek şekilde eğitilir. Bütün bunlar bittiğinde yeni sistem kullanılmaya başlanabilir.

### 7.2 Beş geçiş yöntemi

Temelde beş geçiş yöntemi tanımlanmıştır: doğrudan geçiş, paralel geçiş, dereceli geçiş, prototip geçiş ve dağıtılmış geçiş. Slaytta her biri yatay bir zaman şeridi üzerinde "Eski Sistem" ve "Yeni Sistem" bölgeleriyle çizilmiştir (ekrandan, 00:50:00). Şekiller metin olarak şöyle özetlenebilir:

```text
Doğrudan geçiş   : [ Eski Sistem | Yeni Sistem ]           tek bir dikey sınır
Paralel geçiş    : [ Eski Sistem     ]                      iki şerit bir süre üst üste
                           [     Yeni Sistem ]
Dereceli geçiş   : [ Eski Sistem  /  Yeni Sistem ]          eğik sınır
Prototip geçiş   : [ Eski Sistem | Yeni Sistem ]
                   [ Prototip    |               ]          eski sistemin altında prototip şeridi
Dağıtılmış geçiş : [ Eski Sistem _|‾ Yeni Sistem ]          merdiven biçiminde sınır
```

Hoca şekillerin üzerine kalemle zaman ekseni çizer: soldan sağa giden bir ok, başlangıçta 0, sağ uçta $t$ (ekrandan, 00:50:00).

### 7.3 Doğrudan geçiş

Eski sistem belli bir ana kadar bütün işler için kullanılır, yeni sistem bu sırada bir yerde geliştirilir. Tam belli bir anda eski sistemin "şalteri indirilir": örneğin bir akşam mesai bitiminde eski sistemin fişi çekilir, yeni sistemin fişi takılır ve ertesi sabah bütün işler yeni sistemle yapılır.

İyi yanı, artık eski sistemle uğraşmak gerekmemesidir: bir iş iki kez yapılmaz, iki ayrı kayıt tutulmaz. Kötü yanı risktir: yeni sistem ne kadar test edilmiş olursa olsun gözden kaçmış hatalar ya da fark edilmemiş eksikler olabilir. İşi etkileyecek önemli bir sorun çıkarsa geri dönülecek eski sistem yoktur; hata yeni sistemde düzeltilene kadar işler aksar.

### 7.4 Paralel geçiş

Doğrudan geçişin riskini azaltmak için paralel geçiş yapılabilir. Bir $t_0$ anından bir $t_1$ anına kadar (örneğin iki ay boyunca) hem eski hem yeni sistem eş zamanlı kullanılır. Bu aralık bir yedek (tampon) bölgedir: yeni sistemde yanlışlar ya da eksikler bulunursa iş etkilenmez, çünkü aynı işler eski sistemde de yapılmaktadır. $t_1$'e kadar sorunlar giderilip yeni sistemin düzgün çalıştığından emin olununca eski sistem sonlandırılır ve yalnız yeni sistemle devam edilir. Yeni sistemde ciddi sorun çıkarsa $t_1$ biraz ötelenerek hizmette aksama yaşanmadan eski sistemle devam edilebilir.

Bedeli, aynı işin iki kez yapılmasıdır: bir sipariş hem eski hem yeni sisteme girilir, kargo bilgisi iki sistemde de işlenir. Hangi sistemin gerçek hizmet veren sistem olduğu da seçilmelidir; genellikle eski sistem yaşatılır ve yeni sistemin çalıştığı alan bir tür canlı test, saha testi alanı gibi düşünülür. Bu süre boyunca herkesin her işi iki kez yapması yorucudur.

### 7.5 Dereceli geçiş

Paralel geçişin çift iş yükünü hafifletmek için dereceli geçiş yapılabilir. Hoca slayttaki eğik sınırın sol tarafını tarar ve altına $t_0$ ile $t_1$ yazar (ekrandan, 00:55:00). Sistemdeki hizmet noktaları, servisler, birimler ya da modüller (fatura kesme, sipariş, üretim planlama, bordro, makine kontrolü, izin takibi gibi) yatay şeritler olarak düşünülür.

$t_0$ anında yeni sistemin yalnız belli modülleri ya da özellikleri devreye alınır. Bu büyük olasılıkla en basit, en risksiz, en az bağlantısı olan ve tek başına hizmet verebilen parçadır. O hizmet artık yalnız yeni sistemle, geri kalan her şey eski sistemle yapılır. Bir süre sonra yeni sistemin başka özellikleri kullanılmaya başlanıp eski sistemdeki karşılıkları kapatılır. Modül modül ilerlenerek $t_1$ anına gelindiğinde bütün hizmetler yeni sistemle sunulur ve eski sistemin fişi çekilir. Böylece eski sistem en az riskliden en çok riskliye doğru yavaş yavaş terk edilir.

Artısı, bir birim için aynı işin iki kez yapılmamasıdır. Eksisi, iki sistemin birbiriyle uyumlu çalışması gerekmesidir: örneğin sipariş eski sisteme girilirken fatura yeni sistemden kesilebilmelidir. Bunun için ortak bir veri tabanı ya da sistemlerin birbirinin verisine erişebilmesi gerekebilir; bu da ek geliştirme isteyebilir. Böyle bir uyum varsa dereceli geçiş gerçekten iyi bir yöntemdir.

### 7.6 Prototip geçiş

Prototip geçiş, doğrudan geçişle paralel (ve dereceli) geçişi hibrit biçimde birleştirme fikridir. Belli bir $t$ anına kadar bütün gerçek işler eski sistemle yapılır. Hoca slayttaki düz prototip şeridini düzeltir: prototipin sıfırdan başlayıp yavaş yavaş büyüyen bir eğri olarak düşünülmesinin daha doğru olduğunu, prototipin zamanla son ürüne doğru evrildiğini söyler.

Bu süre boyunca belli işler hem eski sistemde (kesinlikle) hem de prototip üzerinde yapılır. Prototip evrimleştirilir; prototipte görülen hatalar giderilir. $t$ anına gelindiğinde prototipin eski sistemdeki bütün gereksinimleri beklentilerle birlikte daha iyi karşıladığına ikna olunur ve doğrudan geçişteki gibi eski sistemin fişi bir anda çekilip bütün işlevsellik yeni sistemle sürdürülür. Bu yöntemde $t$ anına kadar esas sistem eski sistemdir; prototipi evrimleştirmek ek bir yük olarak taşınır.

### 7.7 Dağıtılmış geçiş

Hoca ilk dördün temel geçiş yöntemleri olduğunu, dağıtılmış geçişin onlara göre biraz "uydurulmuş" bir yöntem olduğunu söyler: dereceli geçişin merdiven haline getirilmiş biçimidir (ekrandan, 01:00:00). Merdivenin basamakları iş birimleri, yani departmanlardır: önce insan kaynakları, sonra pazarlama, sonra satış, ardından depo, üretim ve en son muhasebe yeni sisteme geçer. Ayrı iş birimlerinin teker teker yeni sisteme alınmasına dağıtılmış geçiş denir.

Dereceli geçişte olduğu gibi eski ve yeni sistemin bir süre uyumlu çalışabilmesi gerekir. Örneğin insan kaynakları yeni sistemi kullanırken depo çalışanları hâlâ eski sistemdeyse, bir depo çalışanının izin ya da sağlık raporu girişi yeni sistemdeki insan kaynakları hizmetine düzgün ulaşmalıdır. Fark şudur: her departman kendi içinde bir kerede geçtiği için departman içi sıkıntılar ve çift iş sorunu ortadan kalkar. Bu yöntem her departman için ayrı bir doğrudan geçiş gibi düşünülebilir.

## 8. Bakım ve bir bilgi sisteminin ömrü

### 8.1 Bakımın tanımı

Yeni sisteme geçildikten sonra iş bitmez. Slayttaki ifadelerle yazılım yaşayan bir süreçtir, evrimleşir; kullanıma geçişten sonra yazılımdaki değişikliklere bakım denir (ekrandan, 01:05:00). Bu değişiklikler kaçınılmazdır ve sistemdeki, koddaki, tasarımdaki her türlü değişikliği kapsar. Kullanıma geçtikten sonraki bütün işlemler bakım işlemleridir. Temelde üç tür bakım vardır:

- Zaman içinde ihtiyaçlar değişir: **iyileştirici bakım**.
- Altyapı değişimi olabilir: **uyarlayıcı bakım**.
- Testlerde fark edilmeyen hatalar olabilir: **düzeltici bakım**.

### 8.2 İyileştirici bakım

Sistem kullanılırken ihtiyaçlar değişebilir. Hocanın örneğinde bir not sistemi artılı ve eksili harf notlarıyla devreye alınmıştır; sonra bir yönetmelik ya da kanun değişikliğiyle notların AA, BA, BB, CB, CC gibi iki harfli bir ölçekle tutulması gerekir. Bir başka örnekte yeni bir güvenlik düzenlemesi şifrelerin belli bir algoritmayla, belli uzunlukta bir anahtarla şifrelenip belli bir ortamda saklanmasını şart koşar. İhtiyaç değiştiği için sistemi değiştirerek buna uyum sağlamak iyileştirici bakımdır.

### 8.3 Uyarlayıcı bakım

Altyapı değişebilir. Örneğin sistem bir veri merkezindeki bir kümede (cluster) hizmet verirken bulut hizmetlerine (hocanın örneğinde Amazon'un web servislerine) taşınması istenebilir. Ölçeklendirme de bir altyapı değişimidir: dikey ölçeklendirme nispeten kolaydır, ama yatay ölçeklendirme (paralel bilgisayarlar ya da sunucular eklemek) için tasarımın buna uygun olması gerekir; eş zamanlama ve orkestrasyon sorunları ortaya çıkabilir. Bilgi sistemini yeni altyapıya uyarlamak için yapılan değişikliklere uyarlayıcı bakım denir.

### 8.4 Düzeltici bakım ve bakımın ekonomisi

Hoca iyileştirici ve uyarlayıcı bakımın geliştirici açısından "ekmeğin yağlı kısmı" olduğunu söyler: değişiklik isteği iş bittikten sonra geldiği için ücretlendirilebilir. Örneğin saat ücreti 100 avro artı KDV olan bir ekip için 36 adam-saatlik bir değişiklik $36 \times 100 = 3600$ avro artı KDV olarak faturalanır.

Düzeltici bakım ise bunun tersidir. Testlerde fark edilmeyip sonradan ortaya çıkan hatalar geliştiricinin kendi yanlışı ya da eksiğidir; bunlar için fatura kesilemez. Müşteri memnuniyeti kapsamında hatalar giderilip sistemin normal hizmet vermesi sağlanmalıdır.

> **Hocanın vurgusu:** İyileştirici ve uyarlayıcı bakım geliştirici açısından kazançlıdır; düzeltici bakım ise önceden yapılıp bitirilmiş olması gereken bir işin düzeltilmesi olduğu için tehlikelidir.

### 8.5 Bir bilgi sisteminin ömrü

Sistem devrededir, gerektikçe bakımı yapılır ve kullanılmaya devam eder. Bu, sistemin ihtiyaçları ya da giderek artan işlevsel olmayan gereksinimleri karşılayamayacağı noktaya kadar sürer. O noktada yeni bir bilgi sistemi tasarlanır ve süreç baştan başlar: yeni fizibilite, analiz, tasarım, gerçekleştirme, sınama, devreye alma, geçiş ve bakım.

Hoca bunu bir üniversitenin öğrenci kayıt sisteminin tarihçesiyle örnekler. En başta bilgi sistemi yoktu; öğrencinin alması gereken dersler kartondan bir karneye kaydedilir, her dönem bir sütuna karşılık gelen bu tabloya hangi dersin hangi dönem hangi notla geçildiği elle işlenirdi. Sonra ilk bilgi sistemine geçildi ve yıllarca kullanıldı; ancak kullandığı teknoloji yükü kaldıramayınca yerine yeni bir sistem geldi. Bu yeni sistem de kendi içinde o kadar çok değişti ki büyük ölçekli iki geçiş yaşadı ve artık yalnız adı aynı kaldı; ileride başka bir sisteme geçilmesi de olasıdır. Bir bilgi sisteminin hikâyesi budur.

## 9. Örnek vaka çalışması: spor salonu sistemi

Teorik anlatım tamamlandıktan sonra hoca, analiz ve tasarım adımlarının bir projede nasıl uygulandığını göstermek için basit bir örnek vaka sunar (ekrandan, 01:10:00). Örneğin tam ya da kusursuz olmadığını, yalnız belli adımları "ucundan göstermek" amacıyla hazırlandığını baştan belirtir. Fizibilite ve önceliklendirme atlanır; odak analiz ve tasarımdır.

### 9.1 Problem tanımı

Müşteriyle görüşmeler ve yerinde gözlem sonucunda varılan problem tanımı slaytta şöyledir (ekrandan, 01:15:00):

> Hizmet vermekte olan bir spor salonu artan müşteri sayısı ve genişleyen ders içerikleri sebebiyle yeni bir yönetim sistemine ihtiyaç duymaktadır. Var olan sistemde müşteriler spor salonuna giderek bilgi almakta, kayıt olmakta, kayıtlar yönetim tarafından yerel olarak depolanmaktadır. Bu durum zaman kaybı oluşturmakta ve yönetimi zorlaştırmaktadır.
>
> Spor salonu, online olarak kişilerin üye olup, çeşitli derslere ait sınıfların takvim ve eğitmen bilgilerini görüntüleyebilmesini, istedikleri sınıflara kayıt olabilmesini istemektedir. Aerobik, step, pilates, dans gibi farklı ders içerikleri olabilmektedir. Yönetim tarafından belirlenen derslerin tarih ve saat bilgileri ile oluşturulan sınıfların kapasite bilgileri üyeler tarafından görüntülenebilmelidir. Eğitimciler de sisteme kişisel bilgilerini girip güncelleyebilmelidir. Ayrıca eğiticisi oldukları sınıfların katılımcı bilgilerini görüntüleyebilmelidir.
>
> Her ay sabit bir üyelik ücreti alınmakta, bu ücret dahilinde üyeler süresiz olarak fitness salonundan faydalanmaktadır. Pilates, dans vb. derslerin olduğu sınıflara katılmak isteniyorsa ekstra ücret ödenmektedir. Üyeler grup derslerine katılınabilir, özel ders talebinde de bulunulabilir. Bu durumda ücretler grup ücretlerinden farklı olarak hesaplanmaktadır ve müşteriye belirtilmelidir.

Hoca bu tanıma görüşmelerde nasıl varıldığını da anlatır: hangi derslerin olduğu, zamanla değişip değişmeyeceği (yeni dersler eklendiği için artıyor), sınıfların kapasitesi, ücretlendirmenin nasıl olduğu sorularak öğrenilmiştir. Örneğin aylık grup dersi için bir tutar varken birebir özel ders kursa ve zamana göre farklı ücretlendirilir.

### 9.2 Gereksinimlerin formal hale getirilmesi: BRD

Toplanan beklentiler iki yoldan biriyle formal hale getirilir. İşlevsel bir çözümlemeyle ilerleniyorsa gereksinimler bir iş gereksinimleri dokümanında (business requirement document, BRD) tablo halinde yazılır; aynı anda roller de bulunur. Bu örnekte üç rol vardır:

- **Yönetim:** üyelik başvurusunu onaylar, sınıf oluşturur, eğitmen ile tarih ve saat belirler, güncelleme yapar.
- **Üyeler:** bilgilerini girerek üye olur, sınıfları görüntüler, sınıfa kayıt olur, özel ders talebinde bulunur.
- **Eğitmenler:** bilgilerini günceller, katılımcı listelerini görüntüler.

Nesneye yönelik yolda ise bir use case diyagramıyla aktörler ve senaryolar ortaya konur, senaryolar da use case dokümanları halinde yazılır. İki yoldan biri seçilmelidir. <!-- BELİRSİZ: BRD tablosunun slaytı karelerde yok; roller ve görevler altyazıdan alınmıştır. -->

### 9.3 Veri toplama: anket örneği

Ön inceleme ve fizibilitede elde edilen raporlar, mevcut kaynaklar, görüşmeler, toplantılar ve yerinde gözlem ihtiyaçları belirlemeye yarar. Bu örnekte yerinde gözleme ek olarak bir anket de yapılır; çünkü spor salonunun üyeleri son kullanıcılar gibidir, sayıları çok ve beklentileri farklı olabilir. Slayttaki anket örneği şöyledir (ekrandan, 01:20:00):

- Soru-1: Var olan sistemde sorun yaşıyor musunuz? (Evet / Hayır)
- Soru-2: Online sisteme geçmek sorunları çözecek mi? (Evet / Hayır)
- Soru-3: Online sistemde ihtiyaç duyduğunuz modülleri işaretleyin: Üyelik işlemi, Takvim görüntüleme, Ücret ödeme
- Soru-4: Rakipleriniz tarafından kullanıldığını gördüğünüz sistemlerde dikkatinizi çeken özellikler nelerdir? (açık uçlu)
- Soru-5: ...

Birinci soruya "hayır" cevabı verilirse sonraki sorulara geçmeden anket bitirilebilir (bir tür "go to" dallanması). Üçüncü soruda modüller önceliklendirilebilir; gerçek bir ankette seçenek sayısı daha fazla olmalıdır. Kapalı uçlu soruların yanında katılımcının kendini rahatça ifade edebileceği açık uçlu sorular da konmalıdır. Hoca dördüncü sorunun aslında yönetime daha uygun olduğunu, üyelere sorulacaksa "online üyelik deneyimlerinizde dikkat çeken ya da olmazsa olmaz dediğiniz özellikler nelerdir" biçiminde sorulabileceğini belirtir.

### 9.4 İşlevsel analiz: bağlam diyagramı ve veri akış diyagramları

BRD'den sonra işlevsel çözümleme, yani işlevsel spesifikasyonların yazılması gelir; bunun için veri akış diyagramları kullanılır. Derste görülen iki notasyondan Gane-Sarson notasyonuyla önce bir bağlam (context) diyagramı, yani 0. seviye diyagram çizilir. Ortada sistem, çevresinde dış varlıklar ve aralarında veri akışları vardır. Bu örnekteki akışlar şunlardır: üyeler bilgilerini verir, sınıf seçer, sınıf bilgilerini alır, ücret öder; yönetim sınıf bilgisini girer ve raporları alır; eğitmenler bilgilerini güncellemek için bilgi verir ve katılımcı listelerini sistemden alır. Bu akışlar o anda gözlemlenenlerdir ve değişebilir.

Ardından iş gereksinimlerini karşılayacak süreçler ortaya çıkarılır: üye olma, ödeme yapma, sınıfa kayıt olma, sınıf oluşturma, katılımcıları görüntüleme, bilgi güncelleme. Hangi süreçten hangi verinin akacağı ve hangi veri deposuna neyin kaydedileceği 1. seviye diyagramda gösterilir. Bazı süreçlerin alt süreçleri de gösterilmelidir; örneğin 3. süreç olan ödeme sürecinin 2. seviye diyagramında toplam ücretin hesaplanması, ödemenin alınması ve kalan borcun hesaplanması ayrı alt süreçlerdir. Diyagramlar da yetmez; her süreç için süreç formları doldurulur ve süreçlerin içinde ne yapılacağı sözde kod ya da karar tablolarıyla ifade edilir. <!-- BELİRSİZ: bağlam diyagramı ve DFD slaytları karelerde yok; süreç numaraları ve akış adları altyazıdan alınmıştır. -->

### 9.5 Veri sözlüğü

Bütün veri öğeleri bir veri sözlüğünde tanımlanır: her veri akışı, veri deposu, veri yapısı, bileşik (kompozit) ve tekil eleman için bir sözlük girdisi oluşturulur. Derste iki örnek girdi gösterilir:

- **Veri akışı örneği (kişisel bilgiler):** tanımı ad, soyad, yaş, boy, kilo ve iletişim bilgileridir; kaynağı üye, hedefi üye olma sürecidir; kullandığı veri yapısı "üye detayları" adlı bileşik yapıdır (bu yapı da ayrı bir sözlük girdisinde tanımlanır).
- **Veri deposu örneği (sınıf bilgileri):** adı, tanımı ve miktarı (günde ortalama 10 giriş beklendiği) yazılır.

<!-- BELİRSİZ: veri sözlüğü slaytı karelerde yok; alan adları altyazıdan alınmıştır. -->

### 9.6 Varlık ilişki diyagramı

Süreçler bulunurken aynı anda veri nesneleri (varlıklar) ve aralarındaki ilişkiler de modellenir. Slayttaki ifade şudur: veri nesneleri arasındaki ilişkiler Entity Relationship Diagram (ERD) ile tanımlanır (ekrandan, 01:25:00). Diyagramdaki varlıklar, nitelikleri ve ilişkiler şöyledir:

| Varlık | Nitelikler |
|---|---|
| Üye | Yaş, Ad Soyad, Boy-Kilo, İletişim Bilgisi |
| Sınıf | İsim, Kapasite, Yer, Tarih-Saat |
| Eğitmen | Ad Soyad, Yaş, Branş |
| Muhasebe | Ödenen Tutar, Borç |
| Yönetim | (nitelik gösterilmemiş) |

| İlişki | Bağladığı varlıklar |
|---|---|
| Kaydol | Üye ile Sınıf |
| Ders Ver | Sınıf ile Eğitmen |
| Ödeme Yap | Üye ile Muhasebe |
| Sınıf Oluştur | Sınıf ile Yönetim |
| Raporla | Muhasebe ile Yönetim |

Hoca diyagramda benzersiz tanımlayıcıların (birincil anahtarların) ve çokluk (kardinalite) bilgilerinin bulunmadığını, bunların eklenmesi gerektiğini belirtir. Analiz safhasında bulunan bu model, tasarımda veri tasarlanırken birincil ve yabancı anahtarlar, çokluklar ve eksik olan yeni varlıklar eklenerek son haline getirilebilir. Varlık ilişki diyagramıyla veri de modellenince işlevsel analiz modeli tamamlanmış olur.

### 9.7 Nesneye yönelik analiz: use case diyagramı, senaryo dokümanı, kavramsal sınıf diyagramı

Aynı veriler nesneye yönelik olarak çözümlenmek istenirse use case modellemesi yapılır ve bir kavramsal sınıf diyagramı oluşturulur. Use case diyagramında aktörler ve senaryolar gösterilir. Örneğin "sınıfa kaydolma" senaryosu "özel ders" senaryosuyla genişletilebilir (extend), ayrıca "sınıf bilgisini görüntüleme" senaryosunu içermelidir (include). Eğitmenin iki senaryosu, yönetimin de sınıf oluşturma senaryosu vardır. Hoca diyagramda eksik ya da fazla olabileceğini, amacın yalnız nasıl yapılacağını göstermek olduğunu söyler.

Diyagram da yetmez; her senaryo için bir senaryo dokümanı yazılır. Dokümanda senaryonun adı ve kodu, birincil aktör, ilgililer ve beklentileri, destek aktörleri, ön koşullar, son koşullar, ana akış (etken cümlelerle) ve alternatif akışlar bulunur. Derste ödeme senaryosu örneklenir: ana akışta kullanıcı kredi kartı ve fatura bilgilerini girer; alternatif akışta bilgiler yanlışsa hata mesajı verilir. Bütün senaryoların dokümanları bir araya gelince SRS (yazılım gereksinim spesifikasyonu) dokümanının çatısı oluşur.

Son olarak kavramsal sınıf diyagramı çizilir: üye, sınıf, eğitmen, yönetim ve ders kavramları ile aerobik, dans, pilates gibi ders türleri. Böylece analiz modeli hem işlevsel hem nesneye yönelik olarak tamamlanır. <!-- BELİRSİZ: use case diyagramı, senaryo dokümanı ve kavramsal sınıf diyagramı slaytları karelerde yok; ayrıntılar altyazıdan alınmıştır. -->

### 9.8 İşlevsel tasarım: yapı diyagramı

Tasarımda çözüm önerisi ifade edilir. İşlevsel yolda bu yapı diyagramlarıyla yapılır; gerekirse ana modül ve alt modüller bazında diyagramlar çizilir. Slayttaki "Sistem Tasarımı - Yapı Diyagramı" şöyledir (ekrandan, 01:30:00):

```text
Spor Salonu
|-- Üye Olma            (giden: Üyelik Bilgileri, dönen: Üyelik Onayı)
|-- Üye Girişi Yapma    (giden: Kullanıcı Bilgileri, dönen: Doğrulama)
|   `-- Sınıf Bilgileri Görüntüleme   (Sınıf Seçimi)
|       `-- Sınıfa Kaydol             (Sınıf Seçimi)
|           <seçim>
|           |-- Grup Dersine Katıl
|           `-- Özel Ders Al
`-- Sınıf Oluşturma     (giden: Sınıf Bilgileri)
```

Sınıfa kayıt, eşkenar dörtgenle gösterilen bir seçimle ya grup dersine katılma ya da özel ders alma biçiminde yapılır. Hoca bu diyagramda eksikler olduğunu açıkça belirtir: seçim dallarındaki okların üzerinde hangi verinin ya da hangi mesajın aktığı yazılmamıştır; diyagram böyle bırakılırsa eksik olur. Yapı diyagramı ve gerekirse modüller için girdi-işlem-çıktı (IPO) kartlarıyla tasarım işlevsel olarak ifade edilir.

### 9.9 Nesneye yönelik tasarım: tasarım sınıf diyagramı ve ardışıl diyagram

Use case ve kavramsal sınıf diyagramından devam ediliyorsa tasarım sınıf diyagramı ve etkileşim diyagramları çizilir; derste etkileşim diyagramı olarak yalnız ardışıl (sequence) diyagram gösterilir.

> **Hocanın vurgusu:** Ardışıl diyagramın amacı nesnelerin birlikte nasıl çalıştığını ve sorumluluğun nasıl yerine getirildiğini göstermektir, algoritma göstermek değildir.

Sorumluluklar senaryolardaki fiillerden bulunur; sonra her sorumluluğun kime verileceği GRASP kalıplarıyla düşünülür: işin uzmanı kim, iyi uyum (yüksek uyum) nasıl sağlanır, az bağımlılık nasıl sağlanır, değişimlerden nasıl korunulur, çok biçimli davranışlar nasıl modellenir. Bu örnekte varılan kararlar şunlardır: borç öğrenme sorumluluğu spor salonundadır; sınıf kendi bilgisini vermekle yükümlüdür; her dersin bir saat ücreti vardır ve bunu ders bilmelidir. Üyelik için ayrı bir sınıf tanımlanmıştır, büyük olasılıkla üye ayrıldığında da üyelik bilgileri kalsın diye. Tasarım sınıf diyagramında öz nitelikler, tipleri, görünürlükleri, metotlar ve sınıfların hangi yönde birbirini kullandığı gösterilir; bu, yazılım tasarım çözümünün kendisidir. <!-- BELİRSİZ: tasarım sınıf diyagramı ve ardışıl diyagram slaytları karelerde yok; sınıf adları ve ilişkiler altyazıdan alınmıştır. -->

Slaytta yer darlığı nedeniyle üç sorumluluk tek bir ardışıl diyagramda gösterilmiştir; normalde her biri ayrı diyagram olmalıdır:

- **Üye olma:** üye olma isteğine onay döner.
- **Sınıfa kayıt:** üye ile sınıf arasında sınıf bilgisini alma ve kayıt olma mesajları.
- **Borç öğrenme:** üye borcunu spor salonundan öğrenir. Spor salonu sınıflardan ödenecek tutarları alır; sınıf bunun için dersten saat ücretini ve katılım süresini alır ve saat ücreti çarpı katılım süresini geri döner. Spor salonu bu tutarları kullanarak borcu üyeye bildirir. Böylece dört nesne birlikte çalışarak toplam borç tutarını hesaplama sorumluluğunu yerine getirir.

Toplamda $k$ senaryo ve bu senaryoların içinde $n > k$ sorumluluk varsa $n$ sorumluluğun her biri için ayrı ardışıl diyagram çizilmelidir; tasarım başkalarının, özellikle diğer teknik personelin anlayacağı biçimde açıkça ifade edilmelidir.

Nesneye yönelik yolda en temelde sınıf diyagramı ve ardışıl diyagramlar üretilerek çözüm önerisi ortaya konur. Ardından kodlama, sınama, devreye alma ve bakım aşamalarıyla süreç devam eder.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:05): Projede kullanılacak programlama dili ve geliştirme ortamı sürecin hangi aşamasında seçilir?

> **Cevap (derste verildi):** Fizibilitede, teknik fizibilite yapılırken diller ve ortamlar karşılaştırılıp seçilir; ön tasarım aşamasında kesinleştirilir.

**Soru 2** (derste sözlü, 01:20:39): Bağlam (context) diyagramında ortadaki sistemin çevresinde yer alan öğeler nelerdir?

> **Cevap (derste verildi):** Dış varlıklardır (bu örnekte üyeler, yönetim ve eğitmenler); sistemle aralarındaki ilişkiler veri akışlarıyla gösterilir.

**Soru 3** (derste sözlü, 01:31:47): Spor salonu tasarımında üye bilgileri üyeden bağımsız saklansın diye tanımlanan "Üyelik" sınıfı hangi GRASP kalıbına örnektir?

> **Cevap (derste verildi):** Yapay sınıf (Pure Fabrication). Hoca bunun bir ürün tanımı (Product Specification) sınıfı gibi düşünülebileceğini de söyler.

**Soru 4** (ekrandan, 00:40:00): Test adımları spiralinde ünite, bütünleme, onaylama ve sistem testleri sırasıyla hangi geliştirme katmanlarını sınar?

> **Cevap (derste verildi):** Ünite testi kodlamayı, bütünleme testi tasarımı, onaylama testi sistem gereksinimlerini, sistem testi sistem geliştirme sürecinin tamamını sınar.

## Dersin Toparlaması

Bu derste sistem geliştirme sürecinin tasarımdan sonraki aşamaları tamamlandı. Kodlama ancak tasarım, algoritmalar ve sözde kodlar hazır olduğunda başlar; kod spesifikasyonlara uygun, okunabilir, düzenlenebilir, test edilebilir ve değiştirilebilir olmalı, açıklama satırları, tutarlı yazım deseni ve anlamlı adlarla yazılmalıdır. Dil seçimi uygulama alanı, karmaşıklık, ortam, personel, yatırım ve müşteri koşullarının dengesidir. Yazılım kalitesi büyük ölçüde işlevsel olmayan gereksinimlerle ilgilidir; on bir kalite faktörü vardır ve kalite, planlama aşamasında belirlenen yöntemlerle, durak noktalarında yapılan gözden geçirmelerle ve inceleme, sınama ve kabul muayene planlarıyla sağlanır. Test adımları (ünite, bütünleme, onaylama, sistem) sürecin farklı katmanlarını sınar; onaylama testi "doğru ürünü yaptım mı" sorusunu cevaplar.

Devreye alma için donanım, ağ, veri aktarımı ve eğitim adımlarından sonra beş geçiş yönteminden biri seçilir: doğrudan, paralel, dereceli, prototip ya da dağıtılmış geçiş; her biri risk ile iş yükü arasında farklı bir denge kurar. Kullanıma geçtikten sonraki değişiklikler iyileştirici, uyarlayıcı ve düzeltici bakımdır; sistem ihtiyaçları karşılayamaz hale geldiğinde döngü yeni bir sistemle baştan başlar. Spor salonu örnek vakası, problem tanımından ardışıl diyagrama kadar dönem boyunca işlenen analiz ve tasarım araçlarının bir projede nasıl birlikte kullanıldığını gösterdi. Bu dersle teorik anlatım tamamlanmış olur; sonraki haftalarda dönem projelerinde bu araçların uygulanması ele alınır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
