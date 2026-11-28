# Ders 2 Genişletilmiş Notu: Yazılım Mühendisliğine Giriş Tekrarı, CASE ve Klasik Yazılım Geliştirme Süreç Modelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Mühendisliğine Giriş Konularının Tekrarı
- 2. Yazılım Hakkındaki Yanılgılar
- 3. Yazılım Süreçlerinin Genel Adımları
- 4. Şemsiye (Umbrella) Etkinlikleri
- 5. Bilgisayar Destekli Yazılım Mühendisliği (CASE)
- 6. Yazılım Geliştirme Süreç Modellerine Giriş
- 7. Şelale (Ardışıl) Modeli
- 8. Ön Ürün (Prototip) Modeli
- 9. Artımsal / Yinelemeli Modeller: Spiral ve Kazan-Kazan
- 10. Hızlı Uygulama Geliştirme (RAD)
- 11. Bileşen Tabanlı Uygulama Geliştirme
- 12. Unified Process
- 13. Süreç Boyunca Proje Ekibinin Büyüklüğü
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Mühendisliğine Giriş Konularının Tekrarı

Ders, bir önceki haftada anlatılan giriş konularının kısa bir tekrarıyla başlar. Önceki haftada ders planı, genel bilgiler ve yazılım mühendisliğinin tanımı ele alınmış; yazılım mühendisliği adımları ve yazılım geliştirme süreci ise kısmen anlatılabilmişti. Bu yüzden bu konular hızlıca yeniden gözden geçirilir. Hoca, sistem analizi dersinde yalnız şelale (waterfall) modelinin görüldüğünü, bu derste spiral model, RAD ve prototip model gibi modellerin, bir sonraki haftada da çevik (agile) modellerin işleneceğini belirtir.

### 1.1 Yazılım mühendisliğinin tanımı ve alt alanları

Yazılım mühendisliği, **kaliteli yazılımı en ekonomik biçimde hazırlamak üzere mühendislik araçlarını ve yeteneklerini kullanan bilim dalıdır**. Alt alanları arasında yazılım geliştirme süreçleri ve bunlarla ilişkili modeller, yazılım kalite ve test, yazılım proje yönetimi, analiz ve tasarım teknikleri (bu derste nesneye yönelik modelleme ile birlikte) ve yazılım mimarisi sayılır.

### 1.2 Yazılım eşittir program değildir

Dar anlamda yazılım, bir donanım üzerinde çalışan bilgisayar programıdır. Ancak sistem analizi dersinden başlayarak vurgulanan görüşe göre yazılım yalnız program değildir; **program, belgeler ve veri tabanıyla ilişkili açıklamaların bütünüdür**.

### 1.3 Yazılım türleri

Slaytta yazılım türleri şöyle sıralanır (ekrandan, 00:05:00):

- **Sistem yazılımı:** Diğer programlara hizmet sunmak üzere hazırlanmış programlar; derleyiciler, işletim sistemleri vb.
- **Mühendislik yazılımı / bilimsel yazılım:** Mühendislik ve bilimsel hesaplamalarda kullanılmak üzere hazırlanmış programlar; büyük hacimli verilerle uğraşır, "numara öğütmek / number crunching" olarak anılır.
- **Gömülü (embedded) yazılım:** Donanımla çok sıkı ilişkilidir, denetim amaçlıdır, gerçek zamanlı uygulamalardır.

Bunlara ek olarak uygulama yazılımları ve bir işletmedeki işleri gerçekleştiren **kurumsal yazılımlar** da vardır.

### 1.4 Eski yazılım (legacy software)

Kurumsal yazılımlar zamanla eski yazılıma dönüşür. Eski yazılım (legacy software), Pressman'ın kitabında geçen ve iş hayatında da kullanılan bir kavramdır: iş sürecinin önemli bir parçası olan ve uzun süredir kullanılan yazılımdır. Bu yazılımlarda şu olumsuzluklar görülebilir:

- Eksik ve hatalı dokümantasyon,
- Zaman içindeki düzeltmelerle karmaşıklaşmış kod ve yapılar,
- Esnek olmayan bir yapı,
- Yazılım mühendisliği gelişmelerine paralel geliştirilmemişse yetersiz belgeler.

İş alanındaki yeni gereksinimler ya da güncel sistemlere uyum için bu yazılımların güncellenmesi gerekebilir; ancak belgeleri az olduğundan güncelleme kolay değildir.

### 1.5 Yazılım geliştirmeyi etkileyen eğilimler

Bilgi işlem kaynaklarının yaygınlaşması, haberleşme ağlarının yaygınlaşması, açık kaynaklı yazılımın varlığı ve ekip çalışmasının zorunlu hale gelmesi yeni yaklaşımları doğurmuştur. Hoca, bir sonraki hafta anlatılacak çevik yöntemlerin bu eğilimlerden beslendiğini ve tanımlarının yaklaşık 20 yıl önce yapıldığını belirtir.

## 2. Yazılım Hakkındaki Yanılgılar

Yanılgılar, yazılım geliştirmede yer alan üç paydaş grubuna göre incelenir: müşteri, geliştirici ve yönetim. Sistem analizi dersinden hatırlanacağı gibi **müşteri**, yazılımı kullanacak firma ya da aynı şirketteyse yazılımı kullanacak departmandır. **Uç kullanıcı (kullanıcı)** ise örneğin müşteri muhasebe departmanıysa, yazılan programı bizzat kullanacak olan çalışanlardır.

### 2.1 Müşteri açısından yanılgılar

Slayttaki ifadeler (ekrandan, 00:10:00):

- *"Programın yazılmasına başlanması için amaçları genel olarak belirlemek yeter, ayrıntılar sonra kararlaştırılabilir. Nasıl olsa yazılım esnektir."* Gerçekte belirsiz gereksinimler çürük atılmış temele benzer; gereksinimler belirsizse yazılımın hazırlanması sırasında zorluk çıkar.
- *"Yazılım esnektir. Değişen gereksinimler kolayca sisteme uyarlanabilir."* Gerçekte yazılım yaşam döngüsünde ilerledikçe değişen gereksinimleri yazılıma uyarlamanın bedeli üstel olarak artar, çünkü geliştiricilerin iş gücü artar.
- **Sonuç:** Yazılım esnek bir oyun hamurundan çok kil veya cam gibidir. Çevik süreçlerle esnekliğin artırılması hedeflenmektedir.

Hoca, bu yanılgıların sonuçta daha fazla maliyete yol açtığını vurgular.

### 2.2 Geliştirici açısından yanılgılar

Hoca, programcı, yazılımcı gibi adlar yerine hepsine **yazılım geliştirici** denmesinin daha doğru olduğunu belirtir. Geliştiricilerin yanılgıları:

- **"Yazılımı tamamlayıp müşteriye teslim ettiğimizde işimiz biter."** Gerçekte ilk teslimattan sonra bir takip süresi vardır. Bu sürede müşterinin yazılıma, belgelere ve yardım (help) bölümüne alıştığı ve eğitimin iyi sonuç verdiği izlenmelidir; aksi halde daha büyük sorunlar çıkar.
- **"Yazılımı tamamlamadan kalitesini ölçemem."** Gerçekte kalite güvence yöntemleri yaşam döngüsünün her aşamasında uygulanır; ara gözden geçirmeler ve kalite ölçütleri vardır, arada ölçme ve değerlendirme yapılabilir.
- **"Yazılım eşittir program."** Belge hazırlamak geliştiricilerin pek hoşuna gitmez, ama gereksinim analizi raporu özel emek ister; testlerde hangi test verisinin kullanıldığı ve testin nasıl yapıldığı da belgelenmelidir.
- **"Yazılım mühendisliğinin gereklerini uygularsak boşa çaba harcarız, süremiz uzar."** Hoca bu şikâyetin geliştiricilerden çok sık geldiğini, ancak hangi model seçildiyse ona uyularak yazılım mühendisliği adımlarının mutlaka uygulanması gerektiğini söyler.

### 2.3 İdari yanılgılar

Üçüncü paydaş grubu, yazılımı geliştiren kurumun ya da müşteri kurumun yöneticileridir. Slayttaki ifadeler (ekrandan, 00:15:00):

- *"İşler yetişmiyorsa takıma yeni programcılar ekleriz."* Yazılım hayat döngüsü içinde ilerledikçe yeni elemanların yazılıma hakim olması üstel olarak zorlaşır, işler daha da gecikir. Yeni elemanların kullanılan araçlara (tool) ve ekip yapısına hakim olması zaman alır. Hoca burada proje yönetiminin önemini vurgular: hangi evrede kaç elemana ihtiyaç olduğu önceden planlanmalıdır.
- *"Geliştirmesini üstlendiğim yazılımı tamamen veya kısmen fason yaptırırım."* Proje ilerlemesini kendi içinde denetleyemeyen bir firma, dışarıya verdiği işi izlemekte de zorlanacaktır. Alt yüklenici kullanılabilir, ama alt yükleniciler arasındaki kurallar ve yönetmelik baştan planlanıp kayda geçirilmeli, firma dış paydaşları nasıl denetleyeceğini bilmelidir.
- *"Açık kaynak yazılım üretirsem kâr edemem."* Danışmanlık hizmetleri ile kâr edilebilir; başka iş modelleri de vardır. Hoca açık kaynak üretiminin idari olarak seçilebilecek yollardan biri olduğunu ve günümüzde yaygın kullanıldığını belirtir.

**Soru:** Açık kaynakta para kazanma nasıl oluyor? Kod tamamen açıksa firma nasıl kazanç sağlar? **Cevap:** Açık kaynak yazılımı yazan firma ya da gruptan, yazılımın kullanımı sırasında nasıl uygulanacağı konusunda danışmanlık hizmeti istenebilir; kazanç buradan sağlanır. Bu, günümüzde yaygın bir yöntemdir.

## 3. Yazılım Süreçlerinin Genel Adımları

Süreç modellerini anlayabilmek için önce yazılım geliştirme sürecinin adımları yeniden ele alınır. Sistem analizi dersinden bu adımlarla tanışıklık vardır; ancak burada bütün bilgi sistemini değil, yalnız yazılımı geliştirme çerçevesinde ve daha sistematik bakılır. Hoca, bu listeye yazılım proje planlamayı, ön incelemeyi ve fizibiliteyi bilerek almadığını belirtir. Slayttaki adımlar (ekrandan, 00:20:00):

1. **Çözümleme (*Analysis*)**
2. **Tasarım (*Design*)**
3. **Gerçekleme (*Implementation*)**
4. **Sınama (*Testing*)**
5. **Bakım (*Maintenance*)**

### 3.1 Çözümleme

Slayttaki tanım (ekrandan, 00:20:00): *Çözümleme, bir şeyi anlayabilmek için parçalarına ayırmaktır.* Gerçeklenecek sistemi anlamaya yönelik çalışmalardan ve üst düzey planlama eylemlerinden oluşur:

- Uygulama alanı,
- Kullanıcı gereksinimleri,
- Program parçaları arasındaki üst düzey ilişkiler ve etkileşimler (NYP'deki parçalar: sınıflar ve nesneler).

Slayttaki özlü söz: *"Bir sorunu anlamadan çözemezsiniz."*

Çözümleme aşamasında **"ne?"** sorusuna cevap verilir: gerçekleşecek sistem nedir, neyin yazılımı hazırlanacaktır? Sorun yalnız genel olarak anlaşılmaz; her parçası ayrı ayrı ele alınır, hangi bilgilerin alındığı ve kullanıldığı değerlendirilir. Problem iyice anlaşılmadan yazılımı tasarlamak ve gerçeklemek mümkün değildir. Dönemin ilerleyen bölümlerinde gereksinim analizi ve **SRS (Software Requirement Specification)** belgesi ayrıntılı işlenecek; sistem analizi dersinde "bilgi toplama, modelleme ve SRS belgesini hazırlama" diye kısaca görülen analiz süreci daha fazla aydınlatılacaktır.

### 3.2 Tasarım

Tasarım, bir araştırma ya da geliştirme sürecinin çeşitli dönemlerinde izlenecek yol ve işlemleri belirleyen bölümdür. Çözümlemede anlaşılan sorunun kâğıt üzerinde ya da prototiple, hangi yazılım teknikleri kullanılarak çözüme nasıl ulaştırılacağına karar verilir ve çözümün modeli oluşturulur.

Tasarımı mühendislik yöntemleriyle ele alan **yazılım mimarisi**, yazılım mühendisliğinin ayrı bir alt başlığıdır ve ayrı dersleri de vardır. Tasarımın nasıl yapıldığı çok önemli olduğu için sektörde yazılım mimarları önemli çalışma yapan uzmanlar olarak kabul edilir.

### 3.3 Gerçekleme

Gerçekleme (implementation), eldeki tasarımın seçilen programlama dili ve veri tabanıyla hayata geçirildiği süreçtir; hem veri yapısı hem işlemler tasarımdan alınır. Hoca, bu konunun programlama derslerinde ayrıntılı görüldüğü için üzerinde fazla durmaz.

### 3.4 Sınama

Gerçeklemeden sonra yazılımın doğru hazırlanıp hazırlanmadığı, müşteriden alınan bilgilerin doğru hayata geçirilip geçirilmediği ve problemin doğru çözülüp çözülmediği sınanır. Slayttaki içerik (ekrandan, 00:25:00):

- **Sınama neden önemlidir?**
  - Yazılım sürecinde ilerledikçe ortaya çıkabilecek hataların giderilme maliyeti üstel olarak artar.
  - Aksi gibi, hataların büyük çoğunluğunun kökenleri isteklerin belirlenmesi ve tasarım aşamalarındaki sorunlara dayanır.
  - Bu yüzden: **Erkenden, sık sık ve kolay sınama yapın.**

Hoca, sistem analizi dersinde kullandığı iki grafiği sözlü olarak anlatır: yazılım geliştirme süreci x eksenine yerleştirildiğinde, süreç ilerledikçe **hatanın bulunma olasılığı azalır**, **hatanın düzeltilme maliyeti artar**. Bu yüzden hatalar zamanında yakalanmalıdır. Bunun için yalnız en sonda test yapmak yetmez; testler önceden kararlaştırılmalı ve aradaki aşamalarda **gözden geçirme (review)** yapılmalıdır. Hoca bunun yalnız çevik yöntemlere özgü olmadığını, bütün yazılım geliştirme süreçlerinde bulunduğunu belirtir. Hataların çoğunun kökeni tasarım aşamasındaki sorunlar olduğu için kalite yönetimine yazılıma başlarken, mümkün olduğunca erken başlanmalıdır.

> **Hocanın vurgusu:** Sonraya kalan hataların maliyeti üstel olarak artar; hatalar zamanında, erken aşamalarda yakalanmalıdır.

### 3.5 Bakım

Sınanan yazılım kullanıma verildikten sonra bakım süreci başlar. Bakım gerektiren durumlar:

- Tasarım hatası, kodlama hatası ya da gereksinim analizi hatası olabilir. Tasarım ve gereksinim hataları daha korkutucudur, çünkü geliştirme evrelerinin en başına dönmek gerekir ve bu daha maliyetlidir.
- Sistemin işlevlerini değiştirmek ya da yeni fonksiyonlar eklemek istenebilir.
- Yazılım farklı bir ortama taşınmak istenebilir.

Hoca buradan şu sonucu çıkarır: bir donanımın ya da makine parçasının bakımıyla yazılımın bakımı aynı değildir; yazılımın bakımı, en baştaki evreye dönüp yeniden hazırlamayı gerektirebileceği için daha maliyetlidir.

Slayttaki bakım içeriği (ekrandan, 00:40:00):

- **Yeniden mühendislik (Refactoring / Software re-engineering)**
  - Teknik bakış açısı: Yazılımın işlevini değiştirmeden iç yapısını değiştirmek.
  - Olası eylemler:
    - Yazılımın belgelendirilmesi
    - Tasarımın iyileştirilmesi/değiştirilmesi
    - Yazılımın farklı bir ortama taşınması

## 4. Şemsiye (Umbrella) Etkinlikleri

Analiz, tasarım, gerçekleme, test ve bakım, yazılım geliştirme sürecinin **temel adımlarıdır** ve modelin yapısına göre birer birer ya da iç içe yürütülür. Hoca, Pressman'ın kitabında da yer alan bir yaklaşımla, bu adımların sağlıklı yürütülebilmesi için **destek (umbrella, şemsiye) etkinliklerine** ihtiyaç olduğunu anlatır:

- Yazılım proje yönetimi: sürecin bir plan dahilinde yürütülmesi,
- Yazılım kalite yönetimi: ilk baştan başlayarak kalite değerlendirmelerinin yapılması,
- Yazılım konfigürasyon yönetimi: geliştirme sırasında olan değişikliklerin kayda alınması,
- Ölçme: ilk derste mühendisliğin temel gereklerinden biri olarak tanımlanan, yapılan işlerin ölçülmesi.

Bu koruyucu etkinlikler olmadan yalnız temel işleri yapmak başarı için yeterli değildir.

## 5. Bilgisayar Destekli Yazılım Mühendisliği (CASE)

### 5.1 Tanım

CASE (Computer Aided Software Engineering), 1980'lerin sonundan itibaren var olan ve çeşitli örnekleri geliştirilen bir kavramdır. CAD/CAM yazılımları tasarımcılara ve mimarlara nasıl kolaylık sağlıyorsa, CASE araçları da yazılım geliştiricilerin kendi işleri için bir yardımcı yazılım oluşturma fikrinden doğmuştur: yazılım geliştirme süreci daha hızlı ve daha destekli geçirilebilir mi?

Slayttaki tanım (ekrandan, 00:35:00):

- CASE (Computer Aided Software Engineering); yazılım mühendisliği görevlerinin bilgisayar yardımı ile otomatik olarak (!) gerçekleştirilmesidir.
- CASE ortamı, belirli bir sorunun çözümü ya da bir kurumun yönetim bilişim sistemi için gerekli yazılımı otomatik olarak geliştiren bir bilgisayar sistemidir.
  - Bu sistem; otomatik yazılım araçlarının ve yapısal yöntemlerin bir kombinasyonu olup, yazılım geliştirme sürecini adım adım izleyerek gerçekleştirmekte ve yazılımı üretmektedir.
  - Avrupa ülkelerinde "bütünleşik programlama desteği ortamı" anlamında IPSE (Integrated Programming Support Environments) adı da verilir.

### 5.2 Tam CASE aracı ve bütünleşik CASE araçları

Bugün klasik yaklaşımdaki veri akış diyagramları ve yapısal diyagramlar için de, nesneye yönelik yaklaşımdaki UML ve kullanım durumu (use case) diyagramları için de bu tür ortamlar vardır. Yalnız diyagram çizen bir araç (laboratuvarda çizim için gösterilenler gibi) tam bir CASE aracı sayılmaz.

Tam CASE aracını ayıran özellik, **adımlar arasında birleşiklik sağlamasıdır**. Örneğin analiz modeli çıkarılmış bir yazılımın tasarım UML diyagramları hazırlanırken analizdeki çizime aykırı olarak daha fazla aktör kullanılmışsa araç bu uyumsuzluğu bildirir. Yani yalnız sembolleri kolay çizmeye yardım etmez; hem veri hem işlemler açısından aynı problemi analizden sonra tasarıma, oradan kodlamaya taşırken geliştiriciyi yönlendirir.

- **Bütünleşik CASE araçları**, proje planlamadan başlayarak analizdeki modellemeyi, tasarımı ve program kodunun hazırlanmasını kapsayan, bütün süreci takip edebilen araçlardır.
- Diğer araçlar yalnız bir evreyi destekler: örneğin ekran görünümleri tanımlandığında o ekranın çalışmasını sağlayan kodu otomatik üreten kod geliştiriciler ya da yalnız nesneye yönelik UML diyagramlarını destekleyen programlar.

Bütünleşik CASE araçlarının temel işlevleri: diyagram çizimi, tasarım ve analiz işlemleri, kod dönüştürücü ve hangi fonksiyonların, işlemlerin ve modellerin bulunduğunun tutulduğu bir veri tabanı / arşiv.

Bu araçlar iyi kullanılırsa geliştiricinin işini kolaylaştırır. Ancak bütün evreyi kapsayan karmaşık araçlar yeterli eğitim ve deneyim olmadan, baştan yeterli hazırlık yapılmadan kullanılırsa ilk kullanıldıkları projede zarar bile verebilir. Bu yüzden kullanımdan önce iyi bir eğitim verilmelidir.

## 6. Yazılım Geliştirme Süreç Modellerine Giriş

Slayttaki içerik (ekrandan, 00:55:00):

- Yazılım geliştirme bir süreç olarak ele alınmalıdır.
  - Süreç: Önceden belirlenmiş adımlardan oluşan iş akışı.
- Süreç modelleri, yazılım geliştirme sürecinin yapısını ve adımlarını belirler.
  - Önceden ve iyi planlanmış bir süreç, zamanında ve 'kaliteli' bir 'ürün' elde edilmesini sağlar.
- Çeşitli modellerin kendine özgü avantaj ve dezavantajları vardır.
  - Gerçeklenecek projeye uygun modelin seçilmesi gerekir.

Bütün modellerde analiz, tasarım, gerçekleme, test ve bakım aşamaları vardır; değişen, bunların sırası, ilişkileri ve kurallarıdır. Hoca, bu hafta klasik süreçlerin işleneceğini ve "artık yalnız agile kullanılıyor, diğerleri hiç kullanılmıyor" diye bir kural olmadığını vurgular; önemli olan hangi modelin ne zaman daha uygun olduğunu bilmektir. Yazılım firmalarıyla yapılan araştırma ve anketler bugün de sürmektedir; hoca, çevik yaklaşımın gerçekten iyi olup olmadığını ya da bazı yanılgılara götürüp götürmediğini irdeleyen çalışmalar bulunduğunu, ama çevik yaklaşımın sektöre dinamizm kazandırdığının açık olduğunu belirtir.

**Soru:** Çevik yazılım derken ne kastediliyor? Agile olarak mı yazılıyor? **Cevap:** Evet, agile, "çevik" anlamındadır. Süreci hızlandırmayı amaçlayan, kendine özgü kuralları olan bir yaklaşımdır; ayrıntıları bir sonraki hafta işlenecektir.

## 7. Şelale (Ardışıl) Modeli

Şelale, waterfall, sequential (ardışıl) adlarının hepsi aynı modeli ifade eder. Slayttaki içerik (ekrandan, 01:00:00):

- **Ardışıl Model / Şelale Modeli (Sequential / Waterfall)**
  - Adımlar: Çözümleme → Tasarım → Kodlama → Sınama → Bakım.
  - Bir adımın tamamlanmasından sonra diğerine geçilir.
  - Eksiklikler veya hatalar fark edilirse bir önceki adıma geçilir.
- **Artılar:**
  - En eski model, yaygın kullanımda.
  - İyi tanımlanmış adımlar.
- **Eksiler:**
  - Son ürünün eldesi uzun süreceğinden müşteri sabırlı olmalıdır.
  - Adımları geride bıraktıkça, ilerleyen aşamalarda karşılaşılan hataların düzeltilmesi üstel olarak zorlaşmaktadır.
  - Bir çok 'müşteri' de gereksinimleri eksiksiz ve kesin belirtmekte zorlanmaktadır.
- **Sonuç:** Hiç model kullanmamaktan iyidir!
  - Önceden bir çok kez başarıya ulaştırılmış projelere benzer yeni projelerin yürütülmesi için kullanılabilir (rutin projeler).

Hoca, Gantt diyagramında ve zaman planında da adımların ardışık göründüğünü, ancak her adımın kendi içinde birbirinin bitişini beklemeyen alt adımları olabileceğini ekler. Modelin eksileri arasında müşterinin bir prototip gibi ara bir sonuç görememesini ve gereksinimleri bildirme sürecinden uzak kalmasını da sayar. Gereksinimler iyi anlaşılmışsa ve daha önce bu konuda yazılım geliştirilmişse, örneğin kurumsal yazılımlarda, şelale modeli hâlâ kullanılır. Müşterinin alışkın olmadığı yeni bir program yazılıyorsa müşterinin ürünü kafasında canlandırması zorlaşır.

## 8. Ön Ürün (Prototip) Modeli

Ön ürün modeli daha çok **prototip model** adıyla bilinir. Müşteri dinlenir, bir prototip oluşturulur, müşterinin bu prototipi denemesiyle tasarım daha kolay yapılır ve tasarım netleştikten sonra asıl ürün geliştirilir.

Prototip, daha kolay yazılım geliştirme araçları ve altyapısıyla oluşturulan bir modeldir. Bu sayede müşteri ve kullanıcı ürünü daha erken tanımlamaya başlayabilir. <!-- BELİRSİZ: Prototip modeline ait slayt (21. slayt) karelerde görünmüyor; artı ve eksiler yalnız altyazıdan aktarıldı. -->

- **Artısı:** Ürünün daha erken denenmesi.
- **Eksileri:**
  - Fizibilitede belirlenen asıl araçlar kullanılmadığı için prototip mükemmel olmaz, eksik hazırlanabilir.
  - Prototipte daha kolay araçlar kullanıldığı için oradaki alışkanlıklar sonradan müşteriye yansıyabilir.

Hoca bu ikinci eksiği bir örnekle açıklar: prototipte ekran tanımı çok basit bir araçla yapılır ve müşterinin yanında "bu oldu mu?" diye sorulup olmadıysa hemen değiştirilir. Müşteri, asıl yazılımda da her şeyin aynı kolaylıkla değiştirilebileceği kanısına varabilir.

## 9. Artımsal / Yinelemeli Modeller: Spiral ve Kazan-Kazan

### 9.1 Artımsal / yinelemeli modeller

Slayttaki içerik (ekrandan, 01:05:00):

- **Artımsal / Yinelemeli Modeller (Incremental / Iterative)**
  - Adımlar: Analiz – Tasarım – Kodlama – Sınama – Bakım (slaytta adımlardan geriye dönen bir ok vardır).
  - Gereksinimler önemlerine ve birbirine bağımlılıklarına göre sıralanarak her yinelemede bunların bir kısmı tamamlanır.
- **Artılar:**
  - Ön ürün modeli ve ardışıl modelin güçlü yönlerini kendinde toplayarak dezavantajlarını geride bırakmıştır.
  - Nesneye yönelik programlama metodolojisi ile uyum içerisindedir.
- **Eksiler:** Yazılımın küçük artımlarına fazla yoğunlaşmak, sistemin geneline bakıldığında kolayca görülebilecek sorunların gözden kaçmasına neden olabilir.
- **Sonuçlar:** Sistemin genelini göz ardı etmemek şartıyla güçlü bir modeldir.
- **Örnekler:** Spiral Model ve Kazan-Kazan Modeli.

Hoca, daha basit yapıdaki artımsal (incremental) modelin de bulunduğunu, ama bu özelliklerin sarmal modelde daha iyi görüldüğünü belirtir.

### 9.2 Sarmal (spiral) model

Spiral model hem **artımsal** hem **yinelemeli** bir modeldir ve hem prototip modelin hem şelale modelinin özelliklerini taşır; daha sağlam ilerler. Eksisi: çok küçük bir yazılım geliştirilecekse ya da piyasaya hızlı ürün çıkarmak isteyen rekabetçi bir firmada çalışılıyorsa uygun değildir, çünkü çok fazla kontrol yapılır. **Hata kritik yazılımlarda** kullanılması daha uygundur.

Slayttaki diyagram (ekrandan, 01:10:00) birbirini kesen eksenlerle altı bölgeye ayrılmış, içten dışa genişleyen elipslerden oluşur. Bölgeler sırasıyla:

| Bölge | Slayttaki açıklama |
|---|---|
| Müşteri ile İletişim | Gereksinimlerin Belirlenmesi |
| Planlama | Kaynaklar, zamanlama, yapılacaklar, vb. |
| Risk Analizi | Teknik, mali ve politik riskler |
| Çözümleme ve Tasarım | — |
| Gerçekleme ve Kurulum | Kullanıcı eğitimi, dokümantasyon, vb. dahil |
| Müşteri Tarafından Ürünün Değerlendirilmesi | — |

Hoca, imleçle çevrimleri göstererek şu sırayı anlatır:

1. En içteki çevrimde, bütün geliştirme adımları uygulanarak kullanıma alınmayacak bir **prototip** geliştirilir.
2. Bir sonraki çevrimde **kullanıma alınacak ürün** geliştirilir.
3. Sonra eklemelerle **zenginleştirilmiş ürün** geliştirilir.
4. Bakım sürecinde de aynı yol izlenir: bakımda nelere ihtiyaç olduğu, neden bakım istendiği, hangi kaynakların gerektiği, ne zaman bitirilebileceği, neyin yapılıp neyin yapılamayacağı irdelenir; planın riskleri belirlenir, analiz-tasarım ve gerçekleme-kurulum yapılır.

Her çevrimde önce müşteriyle iletişim kurulup gereksinimler belirlenir, sonra kaynaklar ve zamanlama planlanır, ardından teknik ve mali riskler analiz edilir; plan sürekli gözden geçirilir ve plan üzerinde risk analizi yapılır. Sonra çözümleme ve tasarım, ardından gerçekleme ve kurulum gelir; bu aşamaya spiral modelde **construction (yapım)** aşaması da denir. Son olarak ürün (prototip, asıl ürün ya da zenginleştirilmiş ürün) müşteri tarafından değerlendirilir.

> **Hocanın vurgusu:** Spiral model, her aşamada risk analizinin yapıldığı süreç modelidir.

> **Ders sonrası not:** Hoca spiral modeli "her aşamada risk analizi yapılan tek model" olarak tanıttı. Aynı derste gösterilen kazan-kazan modelinin diyagramında da "Seçeneklerin Değerlendirilmesi ve Risklerin Çözülmesi" bölgesi vardır (ekrandan, 01:15:00); bu nedenle "tek" ifadesi büyük olasılıkla klasik modeller arasında açık bir risk analizi bölgesi bulunduran model anlamında okunmalıdır.

**Neden artımsal ve yinelemeli?** Dışa doğru gidildikçe prototipte, ürünü üretirken ve ürüne eklemeler yaparken hep aynı evreler tekrarlanır; bu modeli **yinelemeli** yapar. Her çevrimde ürün büyüdüğü için model **artımsaldır**. Altı adım kendi içinde ardışıktır: müşteriyle iletişim, planlama, risk analizi, çözümleme ve tasarım, gerçekleme ve kurulum (deployment), müşteri tarafından değerlendirme.

**Şelaleyle karşılaştırma:** Bu adımların çoğu şelalede de vardır, ama eklemeler yapılmıştır. Şelalede çözümlemeden başlanıyordu; ön inceleme ve planlama (müşteriyle iletişim dahil) daha önce yapılması gereken işler olarak düşünülüyordu ve risk analizi adımı yoktu. Spiral model süreci daha evrimsel ve iyileştirici hale getirir (önce prototip, sonra ürün); bu yüzden şelaleye göre daha çok zaman gerektirir, ama kontroller çok fazladır. Hatanın en aza indirilmesi gereken ve bütçesi çok düşük olmayan yazılım ürünlerinde kullanılabilir.

### 9.3 Kazan-kazan (WINWIN) modeli

Hoca bu modelin her kaynakta bulunmadığını, Pressman'ın kitabında yer aldığını ve yalnız varlığının bilinmesinin yeterli olduğunu belirtir. Model de spiral gibi hem yinelemeli hem evrimseldir; ancak adımları farklıdır.

Slayttaki diyagram (ekrandan, 01:15:00), spiraldekine benzer biçimde altı bölgeye ayrılmış elipslerden oluşur:

1. İlgililerin (paydaşlar) Belirlenmesi
2. Kazanma Durumlarının Belirlenmesi
3. Uzlaşma ve Seçeneklerin Belirlenmesi
4. Seçeneklerin Değerlendirilmesi ve Risklerin Çözülmesi
5. Gerçekleme ve Kurulum
6. İlgililer Tarafından Değerlendirmeler

Slaytın altında paydaş tanımı yer alır: *Paydaş: Yazılımın başarısı ve başarısızlığının etkileyeceği kişi ve kurumlar.* Müşteri, yazılım geliştirici ve yönetici paydaşlardır. Her paydaşın yazılımdan ne kazanmak istediği belirlenir, bunlar için uzlaşma seçenekleri ortaya konur ve her birinin isteğini asgari düzeyde karşılayacak biçimde ilerlenir.

> **Ek bilgi (derste anlatılmadı):** Kazan-kazan spiral modeli büyük olasılıkla Barry Boehm ve arkadaşlarının 1990'larda spiral modele paydaş uzlaşması (Theory W) eklemesiyle ortaya çıkmıştır. Pressman'ın kitabı bu modeli spiral modelin bir türevi olarak aktarır.

## 10. Hızlı Uygulama Geliştirme (RAD)

RAD (Rapid Application Development, hızlı uygulama geliştirme) artımsal bir modeldir; hedefi daha hızlı geliştirmektir. Şirketlerde çok hızlı yazılım geliştirme ihtiyacı varsa kullanılır. Hoca şu soruları sorar: Bu model her uygulamaya uyarlanabilir mi? Yazılım ya da problem alt bölümlere ayrılabiliyor mu? Alt bölümlere ayırmak tek başına yeterli değildir; alt modüllerin eşzamanlı ilerleyebilmesi ve yazılımın bileşenlerden kurulabilmesi gerekir. Ayrıca yazılım evinin her parçaya atanacak kadar elemanı olmalı, çalışanlar uyum sağlayabilmelidir; yüksek teknik riskler varsa model zorlaşır.

Slayttaki içerik (ekrandan, 01:20:00):

- Kısa geliştirme çevrimleri üzerinde duran artımsal bir model.
- **Ön koşullar:**
  - Uygulamanın yaklaşık/ortalama 3 aylık bölümlere ayrılabilmesi,
  - Yeterli sayıda bölümün eşzamanlı ilerlemesinin sağlanabilmesi,
  - Yazılımın bileşenlerden kurulabilmesi.
- **Artılar:**
  - Bu sürece uygun yazılım projelerinde verimliliğin artması.
- **Eksiler:**
  - Büyük ölçekli çalışmalarda yeterli sayıda bölümü eşzamanlı ilerletebilecek sayıda çalışanın bulunamaması.
  - Çalışanlar hıza uyum sağlayabilmelidirler.
  - Yüksek teknik risklere uygun değil.
- **Sonuç:**
  - Prototip geliştirmede kullanılması veya ana fikirlerinin diğer süreçlere uygulanması yerinde olacaktır.

Hoca RAD akışını sözlü olarak anlatır (modelin şekli o gün kullanılan slayt dosyasında yoktu):

1. Problem anlaşılır: ne isteniyor ve proje bu koşullara uygun mu?
2. Proje alt bölümlere ayrılabiliyor mu, bakılır.
3. Her alt modüle bir ekip atanır.
4. Her parça için analiz, tasarım, veri modelleme, işlem modelleme ve hızlı yazılım geliştirme adımları uygulanır.
5. Her parça önce tek başına test edilir, sonra parçalar uyumluluk açısından ortak bir teste tabi tutulur ve kullanıma alınır.

Hoca, modelin işletmelerdeki rekabete dayalı, hızla kullanıma geçecek yazılımları geliştirmek üzere IBM tarafından ortaya atıldığını söyler.

> **Ders sonrası not:** Hoca RAD'ın IBM tarafından ortaya atıldığını söyledi. RAD büyük olasılıkla James Martin'in IBM'de geliştirdiği ve 1991'de yayımladığı kitapla yaygınlaştırdığı bir yaklaşımdır; yani bağlantı doğrudur, ama kavram genellikle James Martin'in adıyla anılır.

## 11. Bileşen Tabanlı Uygulama Geliştirme

Uygulama hazır bileşenlerden oluşuyorsa **bileşen tabanlı (component based)** yaklaşım kullanılır. Bileşenlerin ve hazır kütüphanelerin kullanımı RAD'da da vardır; ancak özellikle bu yönü öne çıkaran bileşen tabanlı modeller de tanımlanmıştır.

Slayttaki içerik (ekrandan, 01:25:00):

- Uygulamanın hazır yazılım bileşenlerinden oluşturulmasını öngörür.
- **Aşamaları:**
  - Konu alanı mühendisliği (Domain Engineering)
  - Aday bileşenlerin sınıflandırılması ve seçilmesi (Qualification)
  - Seçilen bileşenlerin kendi yazılımımıza uyarlanması (Adaptation)
  - Bileşenlerin bir araya getirilmesi (Composition)
- **Artılar:**
  - Yeniden kullanımın özendirilmesi (azalan giderler?)
- **Eksiler:**
  - Uygun bileşenlerin bulunması gerekliliği (her zaman bulunmaz)
  - Bileşenlerin uyarlanması gerekliliği (göründüğü kadar kolay olmayabilir)
- **Sonuçlar:**
  - Özellikle hızlı uygulama geliştirme olmak üzere, ana fikirleri çeşitli süreçlere uygulanabilir.

Bu yaklaşımda **yeniden kullanım (reusability)** önemlidir: şirketin bir yazılım kütüphanesi olmalı, bileşenleri belirlenmeli ve yeniden kullanıma önem verilmelidir. Hoca, birkaç hafta sonra işlenecek yazılım kalite özellikleri arasında yeniden kullanılabilirliğin önemli bir yer tuttuğunu ve bileşen tabanlı yaklaşımın bunu desteklediğini belirtir. Uygun bileşenler her zaman bulunamayabileceği için model en çok, çok benzer programlar hazırlayan ve bunları bileşenlere dönüştürebilen şirketlere uygundur.

## 12. Unified Process

### 12.1 Arka plan

Unified Process, nesneye yönelik yaklaşım kullanıldığında buna bağlı olarak kullanılan bir süreç modelidir. Hoca modeli Rational Rose ürünü üzerinden tanıtır: CASE ürünlerinin ortaya çıktığı ilk yıllarda (1990'lar) kendi adını taşıyan bir firma tarafından hazırlanan bu ürün, bütün süreci takip edebildiği için büyük kurumsal firmalarda kullanılmış, daha sonra IBM tarafından satın alınarak IBM'in bir platformu haline gelmiştir. Özellikle nesneye yönelik yaklaşımla hazırlanan yazılımların bütün sürecinin takibinde kullanılmıştır.

> **Ders sonrası not:** Hoca Rational Rose'u hem bir CASE platformu hem de süreç modeli olarak andı. Büyük olasılıkla doğru ayrım şöyledir: Rational Rose, Rational Software firmasının UML modelleme (CASE) aracıdır; süreç modeli ise aynı firmanın Rational Unified Process (RUP) adıyla sunduğu Unified Process uyarlamasıdır. Firma 2003'te IBM tarafından satın alınmıştır.

### 12.2 Evreler

Modelde döngüsel bir yapı vardır; hoca bunun bir sonraki hafta görülecek XP'nin çevrim adımlarına da biraz benzediğini söyler. Şekildeki etkinlikler spiral modeldeki adlarla şöyledir: communication (iletişim), planning (planlama), modeling (modelleme), construction (yapım) ve deployment (müşterinin değerlendirmesi ve release, yani ürünün yayımlanması). Bakım çalışmalarıyla ürün yeni sürümlere (release) geçebilir; bu değişikliklerin takibi konfigürasyon yönetiminin konusudur.

Bu etkinlikler dört temel evrede toplanır:

- **Inception (başlangıç):** Müşteriyle iletişim ve planlamanın başlaması.
- **Elaboration (hazırlık):** Planın tamamlanıp modellemeye geçilmesi; planlama ile modelleme birleşir.
- **Construction (yapım):** Tasarımın bir bölümü, kodlama ve mühendislik testi.
- **Transition (geçiş):** Kullanıcı testi ve kullanıcı değerlendirmelerinin yapılması, kullanıma geçiş.

En sonda production (ürünün elde edilmesi) gelir. Spiraldeki gibi "önce prototip, sonra ürün, sonra zenginleştirilmiş ürün" diye katmanlar sayılmaz; hangi katmanda olunursa o katmanın çıktısı kullanılacak ürün olarak çıkarılır. Her çevrimin sonunda bir **software increment** (yazılım artımı), yani yazılım ürününün yeni bir aşaması elde edilir.

### 12.3 Evrelerin çıktıları

Slayttaki tablo (ekrandan, 01:45:00):

| Inception phase | Elaboration phase | Construction phase | Transition phase |
|---|---|---|---|
| Vision document | Use-case model | Design model | Delivered software increment |
| Initial use-case model | Supplementary requirements including non-functional | Software components | Beta test reports |
| Initial project glossary | Analysis model | Integrated software increment | General user feedback |
| Initial business case | Software architecture description | Test plan and procedure | |
| Initial risk assessment | Executable architectural prototype | Test cases | |
| Project plan, phases and iterations | Preliminary design model | Support documentation: user manuals, installation manuals, description of current increment | |
| Business model, if necessary | Revised risk list | | |
| One or more prototypes | Project plan including iteration plan, adapted workflows, milestones, technical work products | | |
| | Preliminary user manual | | |

**Inception evresi.** Bir vizyon dokümanı çıkarılır: yapılacak işin vizyonu kabaca açıklanır. Başlangıç use case modeliyle yapılacak iş ve ilgililer belirtilir. Başlangıç proje sözlüğü, hem müşterinin hem geliştiricinin kullanacağı ortak terimleri tanımlar. İşin iş gerekçesi (business case) ortaya konur, ilk risk değerlendirmesi yapılır (bu işin riskleri nedir?), temel bir planlama yapılır, gerekirse bir iş modeli ve bir ya da daha fazla prototip oluşturulur. Spiral modeldeki gibi risk için ayrı bir aşama yoktur; risk değerlendirmesi başlangıç çalışmalarının içindedir.

**Elaboration evresi.** Planlama ile modelleme eşleştirilir. Use case modeli tamamlanır; işlevsel olmayan gereksinimleri de kapsayan ek gereksinimler verilir. Hoca, gereksinim analizinin henüz ayrıntılı görülmediğini hatırlatarak kısaca açıklar: işlevsel gereksinimler işin hangi alt başlıkları kapsadığını, işlevsel olmayan gereksinimler ise işe özgü olmayan özellikleri (örneğin kalite özellikleri) anlatır. Yazılım mimarisinin tanımına başlanır (asıl mimari tasarım modelinde belirlenir), bir ön tasarım modeli hazırlanır. Başlangıçta yapılan risk değerlendirmesi bu evrede risk listesi üzerinden gözden geçirilerek netleştirilir. Proje planı ve kilometre taşları (milestones) da bu evrede çıkar.

**Construction evresi.** Modellemede ortaya çıkanların ayrıntılı tasarımı yapılır ve program ya da veri tabanı gerçeklemesiyle hayata geçirilir. Çıktılar: ayrıntılı tasarım modeli, yazılım bileşenleri, bütünleşik yazılım artımları; yazılım bileşenleri üzerinde test planları ve test durumları (test cases); kullanıcı belgeleri, kurulum el kitapları gibi destek belgeleri ve o anda hangi artımda olunduğunun açıklaması.

**Transition evresi.** Müşteri değerlendirmesine (deployment) geçiş işlemleri yapılır; test raporları hazırlanır ve genel kullanıcı geri bildirimi toplanır. İlerleyen haftalarda görülecek alfa ve beta testleri bu evrede yapılan işlerdendir.

## 13. Süreç Boyunca Proje Ekibinin Büyüklüğü

Dersin sonunda hoca, hangi aşamada kaç kişinin çalıştığını canlandırmak için bir grafik gösterir. Slayttaki şekil (ekrandan, 02:00:00): "Figure 2-3: Staffing levels of a typical project". Yatay eksen proje zamanıdır (Planning, Analysis, Design, Implementation), dikey eksen çalışan sayısıdır (Number of people on staff, 2'den 20'ye). Eğri planlamada en düşük düzeyde başlar, analizde yükselir, tasarım boyunca yaklaşık aynı düzeyde kalır, gerçeklemede en yüksek noktaya çıkar ve projenin sonunda hızla düşer. <!-- BELİRSİZ: Grafikteki değerler sayısal olarak verilmemiş; eğri planlamada yaklaşık 2, analiz ve tasarımda yaklaşık 8-9, gerçeklemede yaklaşık 17 kişi düzeyinde görünüyor. -->

Hoca, farklı modellerde analiz, tasarım ve gerçeklemenin hep yapıldığını, ama sıralarının, önemlerinin ve aynı anda yapılabilme derecelerinin değişebildiğini belirtir. Grafiği şöyle yorumlar:

- **Planlama:** İlk başta az kişi çalışır. Proje yöneticisi müşterinin istek ve bilgilerini alarak daha fazla çalışır; proje ekibindeki kişilere ve ekipte olmayan ama yazılım birimine destek veren uzmanlara (örneğin ağ ve veri tabanı alanlarında çalışanlara) danışarak planlama yapılır.
- **Analiz:** Daha fazla kişi çalışır; sistem analistleri ve yazılım mühendisleri yazılım geliştiricilere de danışarak çalışır.
- **Tasarım:** Yazılım mimarları ağırlık kazanır; modellemeler kapsamında diyagramlar çizilir ve bunların bütünlük içinde çalışması sağlanır. Gerçeklemeye göre daha az çalışan vardır.
- **Gerçekleme:** Doğal olarak en fazla çalışanın bulunduğu aşamadır.

## Örnek Sorular

**1. (derste sözlü, 00:17:23)** Açık kaynak yazılım üreten bir firma, kod herkese açıkken nasıl para kazanabilir?

> **Çözüm:** Derste verilen cevaba göre, açık kaynak yazılımı yazan firmadan ya da gruptan yazılımın nasıl uygulanacağı ve kullanılacağı konusunda danışmanlık hizmeti istenebilir; kazanç buradan sağlanır. Slaytta ayrıca başka iş modellerinin de bulunduğu belirtilmiştir (ekrandan, 00:15:00).

**2. (derste sözlü, 00:34:05)** Bir aracın tam bir CASE aracı sayılması neye bağlıdır?

> **Çözüm:** Derste verilen cevaba göre, yalnız diyagram çizebilmek yeterli değildir. Tam CASE aracı yazılım geliştirme adımları arasında birleşiklik sağlar: aynı problemi analizden tasarıma ve koda taşırken geliştiriciyi yönlendirir ve adımlar arasındaki tutarsızlıkları (örneğin analizde olmayan bir aktörün tasarımdaki UML diyagramında kullanılması) bildirir.

**3. (derste sözlü, 00:59:06)** Çevik (agile) yazılım ne demektir?

> **Çözüm:** Derste verilen cevaba göre, agile "çevik" anlamındadır; yazılım sürecini hızlandırmayı amaçlayan ve kendine özgü kuralları olan bir yaklaşımdır. Ayrıntıları bir sonraki derste işlenecektir.

**4. (derste sözlü, 01:06:43)** Spiral model neden hem artımsal hem yinelemeli bir model olarak sınıflandırılır?

> **Çözüm:** Derste verilen cevaba göre, prototipte, kullanılacak ürünü geliştirirken, ürüne eklemeler yaparken ve bakımda hep aynı altı adım (müşteriyle iletişim, planlama, risk analizi, çözümleme ve tasarım, gerçekleme ve kurulum, müşteri değerlendirmesi) tekrarlandığı için yinelemelidir; her çevrimde ürün büyüyüp zenginleştiği için artımsaldır.

## Dersin Toparlaması

Bu derste önce yazılım mühendisliğine giriş konuları tekrar edildi: yazılımın yalnız programdan ibaret olmadığı, yazılım türleri, eski yazılımın güncelleme sorunları ve müşteri, geliştirici ve yönetim açısından yazılım hakkındaki yanılgılar. Ardından yazılım geliştirme sürecinin beş genel adımı (çözümleme, tasarım, gerçekleme, sınama, bakım) ayrıntılı ele alındı; hataların erken yakalanmasının önemi ve bu adımları destekleyen proje, kalite ve konfigürasyon yönetimi ile ölçme gibi şemsiye etkinlikleri vurgulandı. Bilgisayar destekli yazılım mühendisliği (CASE) kavramı ve bütünleşik CASE araçlarının işlevleri tanıtıldı.

Dersin ikinci yarısında klasik yazılım geliştirme süreç modelleri işlendi: şelale, prototip, artımsal/yinelemeli modeller olarak spiral ve kazan-kazan, hızlı uygulama geliştirme (RAD), bileşen tabanlı geliştirme ve nesneye yönelik yaklaşımla kullanılan Unified Process. Her modelin artıları, eksileri ve hangi proje türüne uygun olduğu karşılaştırıldı; son olarak bir projede aşamalara göre çalışan sayısının nasıl değiştiği gösterildi. Bir sonraki derste yazılım geliştirme süreç modellerinin çevik (agile) halleri işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
