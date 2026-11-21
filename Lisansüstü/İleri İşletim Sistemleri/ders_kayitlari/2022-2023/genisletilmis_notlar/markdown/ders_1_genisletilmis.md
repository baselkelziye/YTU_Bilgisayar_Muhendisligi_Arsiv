# Ders 1 Genişletilmiş Notu: İleri İşletim Sistemlerine Giriş ve Dersin Yaklaşımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İşletim Sisteminin Yeri ve Önemi
- 2. İşletim Sistemi ve Bilgisayar Mühendisliğinin Temel Konuları
- 3. Aracı ve Kaynak Yöneticisi Olarak İşletim Sistemi
- 4. Dersin Kapsamı ve Makale Temelli Yaklaşım
- 5. Bilimsel Makale Okuma ve Değerlendirme
- 6. Uygulama Çalışması Fikirleri

## 1. İşletim Sisteminin Yeri ve Önemi

Bu ilk ders, dersin konusunu ve nasıl işleneceğini tanıtan bir giriş dersidir. Kayıt boyunca ekranda yalnız hocanın kamera görüntüsü vardır; slayt ya da tahta kullanılmamıştır. Bu yüzden notun tamamı hocanın sözlü anlatımına dayanır.

Hoca işletim sistemini bilgisayar mühendisliğinin en temel konularından biri ve tam ortasında yer alan bir konu olarak tanımladı. Bir bilgisayar sistemi katmanlı düşünülebilir: en altta donanım, en üstte uygulamalar vardır. Uygulamalar iki türlü olabilir:

- Sistem uygulamaları: örneğin bir veri tabanı uygulaması ya da bir web uygulama sunucusu.
- Bunların üzerinde gerçekte çalışan, son kullanıcıya hitap eden uygulamalar.

Hangisi olursa olsun, alttaki donanım ile üstteki uygulamalar arasındaki etkileşimi, koordinasyonu ve kaynak yönetimini sağlayan, sistemin verimli çalışmasını mümkün kılan parça işletim sistemidir. Hoca bunun bir sunucu, bir dizüstü ya da masaüstü bilgisayar, cebimizdeki telefon ya da belirli bir amaç için kurulmuş gömülü bir sistem için aynı şekilde geçerli olduğunu belirtti.

## 2. İşletim Sistemi ve Bilgisayar Mühendisliğinin Temel Konuları

İşletim sisteminin bilgisayar mühendisi için bir başka önemi, mühendisliğin çok temel konularını doğrudan içermesi ve bu konuların uygulamaları üzerine kurulu olmasıdır. Hoca veri yapıları, algoritmalar ve programlama dillerini örnek verdi ve bunları somut durumlarla açıkladı.

### 2.1 Veri yapıları

Bir işletim sistemi altında çalışan programlar vardır ve bunlara karşılık gelen prosesler vardır. Bu proseslerin listesinin en verimli şekilde yönetilmesi ve liste içinde hızlıca hareket edilebilmesi gerekir; bu bir veri yapısı seçimi problemidir.

Donanım tarafından bakıldığında da benzer bir ihtiyaç vardır: belleğin hangi kısmının hangi prosese ait olduğunun tutulması ve bilinmesi gerekir. Bu bilgi de bir veri yapısında saklanır.

### 2.2 Programlama dilleri ve bağlam değişimi

Bir program parçasından başka bir program parçasına geçildiğinde, çalışmakta olan programın bilgilerinin kenara kaydedilmesi, yeni geçilecek programın bilgilerinin yüklenmesi ve stack (yığın) alanının ilklendirilmesi gerekir. Hoca bunu yönetebilmek için programlama dilinde uyguladığımız çalışma modelini bilmek ve ona hakim olmak gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bir prosesten diğerine geçişe genellikle bağlam değişimi (context switch) denir. Bu sırada işlemci yazmaçları, program sayacı ve stack göstergesi gibi bilgiler prosesin kontrol bloğuna kaydedilir, sonra çalıştırılacak prosesin kaydedilmiş değerleri yüklenir.

Hoca derste ilerleyen kısımda işletim sistemi konularının en alt seviyede assembly programlamaya ve donanıma da dokunduğunu, bu konulardan beslendiğini ekledi.

## 3. Aracı ve Kaynak Yöneticisi Olarak İşletim Sistemi

Hoca işletim sisteminin bir aracı ve bir kaynak yöneticisi olarak düşünülmesi gerektiğini vurguladı.

### 3.1 Kaynakları kendisi tüketmemeli

İşletim sistemi de bir programdır; onun da işlemci ve bellek ihtiyacı vardır. Ancak sistemin kullanılabilirliğini ve verimliliğini sağlamak için işlemci ve bellek kaynaklarının büyük kısmını diğer programların prosesleri kullanabilecek şekilde geride bırakmalıdır. Hoca bunu şöyle açıkladı: işlemci gücünün tamamını işletim sistemi kullanırsa ya da sistemdeki belleğin tamamına işletim sisteminin ihtiyacı olursa, program çalıştırmak için geriye pek bir şey kalmaz.

### 3.2 Varlığını hissettirmemeli

Aracı olmanın bir anlamı da işletim sisteminin varlığını çok hissettirmemesidir. Hoca bunu bir kesme örneğiyle anlattı: donanım seviyesinde bir kesme (interrupt) oluşur ve bu kesme, örneğin bir disk birimindeki okuma ya da yazma işleminin bittiğini bildirir. Bu işlemin bitmesini bekleyen asıl programın en kısa sürede haberdar edilmesi ve kaldığı yerden devam ettirilmesi gerekir. İşletim sistemi bu işi yaparken kendisi de işlemcide çalışan bir kod parçasıdır; buna rağmen en az gecikmeyle çalışabilecek durumda olmalıdır.

> **Hocanın vurgusu:** Bütün bu yönleriyle işletim sistemi çok merkezi ve önemli bir konumdadır.

## 4. Dersin Kapsamı ve Makale Temelli Yaklaşım

### 4.1 Araştırma geçmişi

Hoca işletim sistemleri üzerine çok uzun süre boyunca, farklı alanları kapsayan derin akademik çalışmalar yapıldığını anlattı: işlemci yönetimi, bellek yönetimi, çevre birimi yönetimi, üzerinde çalışan programların yönetimi, programların eş zamanlı çalışabilmesi, birbirleriyle etkileşmesi ve haberleşmesi. Bu çalışmaların pratik uygulamaları da yapılmış ve bugün farkında olarak ya da olmayarak kullandığımız modern işletim sistemlerinin temelleri böyle oluşmuştur.

### 4.2 Konu alanları

Hocanın derste saydığı konu alanları şunlardır:

- İşlemci yönetimi.
- Bellek yönetimi.
- Çevre birimi yönetimi.
- Birden fazla işlemcinin bir arada çalışması.
- Proses yönetimi: proses, bir programın işletim sistemi altında çalışan hâlidir. Prosesin çalışırken durdurulup yeniden çalışır hâle getirilmesi ve çalışma sıralarının verimli biçimde belirlenmesi bu başlığa girer.
- Proses göçü (migration): bir prosesin bir sistemden başka bir sisteme taşınması.
- Prosesler arası haberleşme ve senkronizasyon.
- Sanallaştırma: hocanın "günümüzün çok sıcak kavramı" dediği bu başlık altında sanallaştırmanın tipleri, yani normal (tam) sanallaştırma, para-sanallaştırma (paravirtualization), diğer sanallaştırma teknikleri ve container yapıları.
- Koruma (protection): proseslerin birbirinden korunması.
- Güvenlik (security).

> **Ek bilgi (derste anlatılmadı):** Tam sanallaştırmada konuk işletim sistemi değiştirilmeden çalışır ve donanım tamamen taklit edilir ya da donanım desteğiyle yalıtılır. Para-sanallaştırmada konuk işletim sistemi sanal makine izleyicisinin (hypervisor) farkındadır ve bazı ayrıcalıklı işlemler için doğrudan onu çağıracak şekilde değiştirilir. Container'lar ise ayrı bir çekirdek çalıştırmaz; aynı çekirdeği paylaşan, birbirinden yalıtılmış kullanıcı alanları sunar.

### 4.3 Makaleler üzerinden ilerleme

Hoca işletim sistemiyle ilgili temel kavramların kendisi tarafından motamot anlatılmayacağını belirtti. Ders temelde doktora seviyesinde konumlandırılmış bir lisansüstü derstir. Bunun yerine, yukarıdaki konuların ortaya çıkışını, bunlarla ilgili yapılmış araştırmaları, elde edilen sonuçları, bu sonuçların tartışmalarını ve bunlara bağlı tasarım kararlarını içeren, hocanın seçtiği 40 küsur makale incelenecektir. Bu makaleler, işletim sisteminin ilgili kısmında defakto standartların oturmasına ön ayak olmuş, konunun uzmanı kişilerin kaleminden çıkmıştır.

Ders düzeni şöyledir: her hafta incelenecek iki ya da üç makale duyurulur. Öğrenciler bu makaleleri bilimsel yayın inceleme mantığıyla okur, bireysel olarak değerlendirir ve özetler. Sonraki derste hoca makalelerde ele alınan konularla ilgili sorular sorar ve öğrencilerden yorum bekler; kendisi moderatör olarak eksik ya da sorunlu gördüğü cevaplara müdahale eder.

> **Hocanın vurgusu:** Lisansüstü ders lisans dersinden farklıdır. Lisansta bilgi daha çok aktarılır ve öğrenci yönlendirilir. Burada amaç, bilimsel yayın okuma, onun üzerine araştırma yapma ve yorumlama yeteneğini bir konu özelinde geliştirmektir. Dersin şekillenmesini öğrencinin çabası sağlar; hocanın en istemediği şey, kimse cevap vermediği için kendi sorusunu kendisinin cevaplamasıdır.

## 5. Bilimsel Makale Okuma ve Değerlendirme

Hoca makalelerin nasıl okunacağını, bir bilimsel makalenin bölümleri üzerinden anlattı.

### 5.1 Makalenin bölümleri

- **Abstract:** makalenin neyle ilgili olduğunu, neyin tartışıldığını ve incelendiğini gösterir. Yayının yapılmasındaki hedefi ve ne elde edilmeye çalışıldığını kısaca özetler.
- **Introduction:** konuya genel hatlarıyla giriş yapılan, problemin tarifinin yapıldığı ve öneminin ortaya konduğu bölümdür.
- **Related Work:** konuyla ilgili öncül çalışmalar. Hoca bu dersteki makalelerin çoğunda bu bölümün ya az olacağını ya da hiç olmayacağını söyledi; çünkü bu makalelerin çoğu konunun çözülmesi ya da ilk kez değerlendirilmesi yönündeki ilk çalışmalardır. Yine de bazılarında bulunacaktır.
- **Teorik inceleme ve deneyler:** konunun teorik olarak incelenmesi, bu incelemeye dayanan pratik deneyler ve elde edilen sonuçlar.
- **Yorumlar:** hangi yaklaşımın daha iyi olduğu ve hangi durum için daha geçerli olduğu.
- **Future work:** tek bir çalışmada konuyla ilgili bütün soru işaretlerini gidermek mümkün değildir. Önemli bir kısmı cevaplanır ama yapılması gereken çalışmalar da belirtilir: "Bu kadarı incelendi, bu sonuçlar elde edildi; sonrasında şunlara bakılmalı."

### 5.2 Değerlendirmede sorulacak sorular

Makaleden çıkarılacak özet ve yorum şu soruların cevabını içermelidir:

- Makalenin yazılma amacı ne?
- Kapsamı ne? Amaca ulaşırken yaptığı teorik incelemede ve deneysel çalışmalarda nelere dokunmuş?
- Ne elde etmiş, sonuçta neyi çözmüş?
- Amacı ne ölçüde çözmüş?
- Çözülmesi gereken başka şeyler kalmış mı?

### 5.3 Okuma sırası

Makaleler başka makalelere referans verir; bilimsel yayınların sonunda "şuradan, şu çalışmanın şu kısmından yararlandık" diyen bir referanslar bölümü bulunur. Hoca okuma için iki yol gösterdi:

- **Yukarıdan aşağı (top-down):** makaleyi baştan sona okumak. Başlangıçta bu yol uygundur.
- **Aşağıdan yukarı (bottom-up):** konuya hakim olup makaleleri daha rahat inceler hâle gelince önce referanslara bakıp orada neler olduğunu görmek, sonra makaleye dönmek.

Hangisinin seçileceğini okuyucunun kendisinin ayarlaması gerektiğini söyledi.

## 6. Uygulama Çalışması Fikirleri

Okunan konuların uygulamada pekişmesi için dersin bir de uygulama ayağı vardır: derste anlatılan konulardan biri seçilir, bir sanal makine ortamında gerçekleştirilir ve amaç, kapsam, yararlanılan kaynaklar, yapılanlar ve elde edilen sonuçları anlatan bir rapor yazılır. Hoca bunun "basit yapıda da olsa bir makale yazmak" anlamına geldiğini söyledi: ilgili makaleler girdi olarak alınır, sonuç kısa bir sunumla anlatılır. Hocanın örnek olarak verdiği konular şunlardır.

### 6.1 Sanal makineler arasında proses göçü

Aynı tipte ve aynı mimarideki iki işletim sistemi arasında bir prosesin taşınması: A sanal makinesindeki proses A'da durdurulur, B sanal makinesine göç ettirilir ve B'de çalıştırılır. Hoca bu tür işler için Linux kullanmanın çok daha kolay olduğunu, çünkü çekirdek kaynak koduna kadar her türlü kaynağa hakim olunabildiğini belirtti.

### 6.2 Kesme mekanizmaları

Kesme mekanizmaları, kesme önceliklerinin çözülmesi ve kesme gecikmesinin (latency) en aza indirilmesi. Hoca okunacak makaleler arasında bu konuyu ele alan makaleler olduğunu ve oradaki tekniklerin uygulanabileceğini söyledi.

### 6.3 Dosya sistemi performansı

Unix'teki ve Windows'taki dosya sistemlerinin okuma ve yazma performansları; dosyanın büyük ya da küçük olması, sıralı (sequential) ya da rastgele (random) erişilmesi gibi pek çok durum incelenebilir. Hoca bu durumların önemli olduğunu, çünkü dosya sistemine gelen istek modelinin ve istek karakteristiğinin kullanım yerine göre değiştiğini vurguladı: bir veri tabanından gelen istekler, bir web sunucusu ya da onun üzerinde çalışan uygulamadan gelen istekler ve sıradan bir kullanıcının profili birbirinden farklıdır.

### 6.4 Ortam ve araçlar

Hoca ortam olarak Unix tabanlı ilerlemenin, bu kapsamda Linux kullanmanın avantajlı olduğunu söyledi. İhtiyaca göre C/C++, kabuk betikleri (shell scripting), Perl ya da Python gibi betik dilleri, Java ya da Go kullanılabilir. Genel sınırlar bellidir ama içeride ne yapılacağı ve nasıl yapılacağı çalışmayı yapanın tasarım kararıdır. Hoca bu tür bir çalışmanın işletim sisteminin ana noktalarına dokunma imkânı verdiği için deneyimi ve bilgiyi artıracağını belirtti.

## Dersin Toparlaması

Bu giriş dersinde işletim sisteminin donanım ile uygulamalar arasındaki aracı ve kaynak yöneticisi rolü, kendi kaynak tüketimini düşük tutması ve kesme gibi olaylara en az gecikmeyle tepki vermesi gerektiği anlatıldı. İşletim sisteminin veri yapıları, algoritmalar, programlama dilleri ve assembly seviyesinde donanım bilgisiyle iç içe olduğu, proses listesi, bellek sahipliği ve bağlam değişimi örnekleriyle gösterildi. Ardından dersin kapsadığı konu alanları (işlemci, bellek ve çevre birimi yönetimi, çok işlemcili sistemler, proses yönetimi ve göçü, haberleşme ve senkronizasyon, sanallaştırma, koruma ve güvenlik) sayıldı.

Dersin geri kalanı, bu alanların temelini atan makalelerin okunup tartışılmasıyla ilerleyecektir. Bu yüzden derste bir bilimsel makalenin bölümleri ve bir makaleyi değerlendirirken sorulması gereken sorular (amaç, kapsam, sonuç, amaca ulaşma derecesi, açık kalan problemler) ayrıntılı olarak anlatıldı. Sonraki derslerde ilk makale grubunun değerlendirilmesine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
