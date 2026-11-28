# Ders 1 Genişletilmiş Notu: Yazılım Mühendisliğine Giriş, Yazılım Türleri, Yanılgılar ve Süreç Adımları

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Sistem Analizi Dersiyle İlişkisi
- 2. Gereksinim Mühendisliği Neden Önemli?
- 3. Kaynak Kitaplar
- 4. Yazılım Mühendisliğinin Tanımı
- 5. Yazılımın Tanımı ve Yaşam Döngüsü
- 6. Yazılım Türleri
- 7. Eski Yazılım (Legacy Software)
- 8. Yazılımı Etkileyen Eğilimler
- 9. Paydaşlar ve Yazılım Hakkındaki Yanılgılar
- 10. Yazılım Süreçlerinin Genel Adımları
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kapsamı ve Sistem Analizi Dersiyle İlişkisi

Yazılım Mühendisliği dersi, sistem analizi dersinin devamı niteliğindedir. Sistem analizinde yazılım geliştirme süreçlerine bütünsel bakılmış; bir bilgi sisteminin ön incelemeden ve fizibilite çalışmasından başlayıp yerleştirilmesine ve kullanıma alınmasına kadar olan işlemlere giriş yapılmış, uygulama da gerçek hayata benzer biçimde bir grup projesiyle geliştirilmişti. Sistem analizi bu dersin ön koşuludur.

Bu derste de bir proje vardır, ancak vurgu farklıdır:

- Analiz ve tasarıma daha çok ağırlık verilir; analiz ve tasarım nesneye yönelik yaklaşımla yapılır.
- Proje yönetimi daha geniş çaplı ele alınır.
- Sistem analizinde hiç girilmeyen test tarafına da girilir.

Ders planında görülen konu akışı şöyledir (ekrandan, 00:10:45):

- Giriş, genel bilgiler, yazılım mühendisliğinin tanımı
- Sistem geliştirme süreci modelleri (şelale, spiral vb. klasik modeller)
- Çevik (*agile*) modeller
- Gereksinim mühendisliği
- Yazılım tasarımı
- Nesneye yönelik çözümleme ve tasarım
- Yazılım kalite özellikleri ve ölçütleri
- Yazılım mimarisi
- Yazılım test teknikleri
- Yazılım proje yönetimine giriş, yazılım risk yönetimi, yazılım konfigürasyon yönetimi

Hoca, süreç modelleri anlatılırken CASE araçlarının da tanımlanacağını, yazılım mimarisinin tasarım haftasıyla birleştirilerek özetlenebileceğini ve zaman kalırsa yeniden mühendislik (*re-engineering*) ile tersine mühendislik (*reverse engineering*) kavramlarının da ekleneceğini söyledi.

Bu ders bir programlama dili dersi değildir; belirli bir dilden sorumlu tutulmazsınız. Önemli olan analizin ve tasarımın nesneye yönelik yapılması ve yazılımın da buna uygun biçimde nesneye yönelik geliştirilmesidir. Dil seçimi, önceki programlama derslerinden gelen bilgiye dayanarak proje grubunun kararıdır.

## 2. Gereksinim Mühendisliği Neden Önemli?

Sistem analizi dersinde analiz aşaması daha düz bir bakış açısıyla görülmüştü: önce bilgi toplanır, sonra modellenir, sonra raporlanır. Geleneksel ve nesneye yönelik yaklaşımlar da tanıtılmıştı. Bu derste Pressman'ın kitabındaki *Requirements Engineering* bölümü izlenerek gereksinim analizi (*requirement analysis*) çok daha kapsamlı ele alınacak ve alt başlıklara bölünecektir.

Hocanın ayrımına göre sistem analizi, kullanıcıyla aradaki geniş kapsamlı bir adım gibi tanımlanabilir; gereksinim analizinde ise yazılım sisteminin bütün gereksinimleri tamamen ve ayrıntılı olarak ortaya konur. Bu aşamada yapılanlar:

- Çözülecek problemin ne olduğu ve gereksinimlerinin neler olduğu ortaya konur.
- Problem alt başlıklara ayrılır.
- Problem üzerinde çalışan kişiler, yani taraflar incelenir; her bir taraftan bakıldığında problemin nasıl göründüğüne bakılır.
- Her tarafın problemi nasıl anlattığı toplanır ve bu anlatımların kesişim noktaları yakalanır.

> **Hocanın vurgusu:** Hangi problemi çözecekseniz, o problemi yanlış anlarsanız çözümünüz de tasarımınız da yanlış olur. Bu yüzden önce doğru anlamayı sağlamak ve problemi doğru alt başlıklara ayırmak gerekir. Sektörde de gereksinim analizine artık çok önem verilmektedir.

## 3. Kaynak Kitaplar

Çok sayıda yazılım mühendisliği ders kitabı vardır, ancak dünyadaki üniversitelerin çoğunda temel olarak Sommerville'in ve Pressman'ın kitapları okutulur. Bu derste ağırlıklı olarak Pressman'ın kitabı izlenir; diğerleri ek kaynaktır. Slaytta verilen liste (ekrandan, 00:45:45):

- Roger S. Pressman, *Software Engineering: A Practitioner's Approach*, McGraw-Hill, 2014, 8. baskı.
- Craig Larman, *Applying UML and Patterns: Intro. OOAD & Iterative Development*, Prentice-Hall, 2004, 3. baskı.
- Ian Sommerville, *Software Engineering*, Pearson, 2015, 10. baskı.
- Martin Fowler, *UML Distilled*, Addison-Wesley, 2003, 3. baskı.
- ... ve diğerleri.

## 4. Yazılım Mühendisliğinin Tanımı

Kitaplarda yazılım mühendisliğinin analiz, tasarım ve test konularını kapsayan, hangi bilim dallarıyla ilişkili olduğunu belirten pek çok farklı tanımı vardır. Hoca, alandaki bütün konuları kısaca kapsayan şu tanımı verdi (ekrandan, 00:50:45):

> Yazılım mühendisliği, **kaliteli yazılımı** en **ekonomik** olarak hazırlamak üzere **mühendislik** araçlarını ve yeteneklerini kullanan bilim dalıdır.

Slaytta "Kaliteli Yazılımı", "Ekonomik" ve "Mühendislik" sözcüklerinin altı çizilmiştir (ekrandan, 00:55:45). Ders bu üç kavramı tek tek açtı.

### 4.1 Kaliteli Yazılım

Kaliteli yazılım, ne olursa olsun bir yazılım üretip kullanılır hale getirmek değildir. Kullanıldığı sürece hatayı en aza indiren, kullanıcının istediğini gerçekleştiren ve kalite özelliklerini sağlayan yazılımdır. Kalite kavramı ve kalite özellikleri farklı kurum ve kişilerin tanımlarına göre değişir; derste ileride hem IEEE'nin hem McCall'ın tanımları işlenecektir.

Kaliteli yazılım tanımının altında testin iyi yapılması gerektiği de anlaşılır. Yeterince test edilmiş bir yazılımda hatalar büyük ölçüde arındırılır, ancak tamamen yok etmek mümkün değildir.

> **Ek bilgi (derste anlatılmadı):** McCall kalite modeli (büyük olasılıkla 1977), kalite etkenlerini büyük olasılıkla ürünün işletimi (doğruluk, güvenilirlik, verimlilik, bütünlük, kullanılabilirlik), ürünün gözden geçirilmesi (bakım kolaylığı, esneklik, test edilebilirlik) ve ürünün geçişi (taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik) olmak üzere üç grupta toplar.

### 4.2 En Ekonomik

Kaliteli yazılım hazırlanırken "kaça çıkarsa çıksın, hangi yolla olursa olsun" denemez; yazılım en ekonomik biçimde hazırlanmalıdır. Ekonomik, en ucuz demek değildir; harcamalar ile fayda arasında en uygun olanıdır.

Bu kavram sistem analizi dersindeki fizibilite analizine bağlanır: teknik olurlulukta problemin teknik olarak çözülüp çözülemeyeceğine, ekonomik fizibilitede ise ekonomik olarak çözülüp çözülemeyeceğine bakılır. Yazılımın ekonomik hazırlanması iyi bir planlamaya bağlıdır: hem zaman planlaması hem kaynak planlaması. En önemli kaynak çalışanlardır (yazılım geliştiriciler, test gerçekleştirenler, analistler); bunların en iyi şekilde kullanılıp kullanılmadığı belirleyicidir. Bu nedenle yazılım mühendisliğinin bir alt başlığı da yazılım proje yönetimi ve planlamasıdır.

### 4.3 Mühendislik Araçları ve Yetenekleri

Hoca öğrencilere mühendislikte öne çıkan, bir mühendisin problem çözerken ve ürün geliştirirken kullanması gereken en önemli iki şeyin ne olduğunu sordu. Bir öğrencinin "beklenen performansı gerçekleştirmek ve bütçeyi aşmamak" tahmini üzerine hoca bunların hedefler olduğunu, sorunun ise kullanılan araçlar olduğunu belirtti. Cevap **tasarım** ve **ölçüm**dür (bu kısım bağlantı sorunları nedeniyle kesik kesik anlatıldı).

Ölçmenin önemi şudur: bitirilen bir ürün ölçüldüğünde, sonradan geliştirilenler bununla kıyaslanabilir. Ölçüm hem yapılan işi değerlendirmek için hem de o anda geliştirilen ürünün verileriyle daha sonra başlanacak ürünlerin maliyetini kestirmek için kullanılır.
<!-- BELİRSİZ: 01:50-01:53 arasında ölçüm anlatımı ses kesintileri nedeniyle altyazıda parçalı; ayrıntı eksik olabilir. -->

### 4.4 Alt Başlıklar

Tanımdaki kavramlardan yola çıkınca yazılım mühendisliğinin alt başlıkları ortaya çıkar. Slayttaki liste (ekrandan, 01:19:08; slayt küçük görüntüsünden):

- Yazılım geliştirme süreçleri
- Yazılım kalite ve test
- Yazılım proje yönetimi
- Mühendislik araç ve yetenekleri: tasarım, ölçüm

Tasarım kavramı genişletilerek yazılım mimarisi olarak da ele alınır; ölçüm ise güvenilirlik ve başka açılardan yazılımın değerlendirilmesini kapsar. Derste bu alt başlıkların her biri ayrıntılı işlenecektir.

## 5. Yazılımın Tanımı ve Yaşam Döngüsü

Geliştirilecek yazılım hakkında bir tanım birliğine varmak gerekir. Slayttaki tanım (ekrandan, 01:19:08; ekrandan, 01:10:45):

- **Yazılım:**
  - Herhangi bir boyuttaki herhangi bir tür donanımda çalışan bilgisayar programını **VE**
  - basılı veya elektronik ortamdaki her tür dokümanı içeren üründür.
    - Dokümanlar yazılım geliştirmeye ve son kullanıcıya yönelik olabilir.
- Yazılım bir üründür, ancak başka ürünler geliştirmeye veya elde etmeye yarayan bir araç da olabilir.
- **Yaşam döngüsü:** Yazılımın bir fikir olarak doğmasından kullanım dışı bırakılmasına kadar geçen süreç.
- Yazılım fiziksel bir ürün olmadığı için aşınmaz, ancak zamanla yetersizleşebilir.
  - Değişim kaçınılmazdır: yazılım, yaşam döngüsü süresince değişikliklere uğrar.
  - Değişiklikler yazılımda yeni hatalar oluşturabilir.
  - Yeni hatalar tam olarak düzeltilmeden yeni değişiklikler gerekebilir.
- Çözüm: yazılım mühendisliği ilkelerine uyularak daha iyi tasarlanmış yazılım.

Hoca, yazılım dendiğinde yalnız programın değil, yazılımla ilişkili her tür belgenin (kullanıcı belgeleri ve yazılımın bakımını yapacak kişilere bilgi veren belgeler) ve ilişkili veri hakkındaki bilginin de anlaşılması gerektiğini vurguladı. Yaşam döngüsünü (*software life cycle*) de yazılım gereğinin doğmasından yazılımın kullanım dışı kalmasına kadar geçen süreç olarak açıkladı: geliştirme süreci, belgeleriyle güncel olarak tam anlamıyla kullanımı, bakımı yapılmadan kullanılmaya devam edildiği dönem ve son buluşu.

## 6. Yazılım Türleri

Yazılım türleri öğrencilerin diğer derslerden bildiği konulardır; derste yalnız üzerinden geçildi. (Bu bölümün slaytları kayıt karelerinde yer almadığından anlatım altyazıdan aktarılmıştır.)

- **Sistem yazılımı:** İşletim sistemleri gibi; işletim sistemleri dersini almış biri bu türü bilir.
- **Mühendislik yazılımı.**
- **Gömülü (*embedded*) yazılım:** Donanımla sıkı ilişkisi olan ve örneğin araçların içinde çalışmasını sağlayan yazılımlar.
- **İşletmecilik (kurumsal) yazılımları:** ERP ve CRM gibi; yönetim bilgi sistemleri dersinde ayrıntılı görülür. Eski veritabanları kullanılarak yapılmış kurumsal yazılımlar da bu gruba örnektir.
- **Uygulama yazılımı:** Genellikle işletmecilik ya da mühendislik alanında kullanılır.

Uygulama yazılımları iş gereksinimleri için sürekli bakım halinde tutulur. Zamanla yenilik yapılması zorlaşır ve yazılım eski yazılıma (*legacy software*) dönüşür; zor da olsa kullanılmaya devam edilir.
<!-- BELİRSİZ: 00:08-00:11 arasında hocanın sesi gelmediği için uygulama yazılımı ve kurumsal yazılım tanımlarının slayttaki ayrıntısı altyazıda yok. -->

## 7. Eski Yazılım (Legacy Software)

Slayttaki içerik (ekrandan, 01:24:08):

- **Tanım:** İş sürecinin önemli bir parçası olan ve çok uzun süredir kullanılan yazılımlar.
- **Eski yazılımda bulunabilecek olumsuzluklar:**
  - Eksik veya hatalı dokümantasyon
  - Zamanla karmaşıklaşmış kod
  - Esnek olmayan yapı
  - Eski donanımla çok sıkı ilişki
  - Yazılım mühendisliğindeki gelişmelerden yoksunluk nedeniyle düşük kalite
- **Eski yazılımın değiştirilmesini gerektiren nedenler:**
  - İş alanındaki yeni gereksinimler
  - Güncel sistemlerle birlikte çalışabilmesi için uyumluluk kazandırılması
  - Donanımın ömrünün dolması nedeniyle daha güncel ortama taşınma gerekliliği

Hoca, kodun eski olduğu için üzerinde yapılan düzeltmelerle karmaşıklaştığını ve bu yazılımların en kötü tarafının eksik ve hatalı dokümantasyon olduğunu belirtti. Güncelleme gerektiğinde bunu yapmak şirketlerde zor olabilir, çünkü yazılımın altyapısını bilen kişi sayısı azdır. Bu yüzden eski yazılım, kurumun önemli işlemlerini yürüten ama hantal kalmış yazılım olarak tanımlanır.

## 8. Yazılımı Etkileyen Eğilimler

Slayttaki içerik (ekrandan, 01:29:08):

- **Yaygınlaşan bilgi-işlem:** Hesaplama gücünün giderek küçülen alanlara sıkıştırılabilmesi, bilişimin günlük yaşantımızla daha kolay bütünleşmesine olanak sağlıyor.
- **Yaygınlaşan haberleşme ağı:** Kablosuz ağların yaygınlaşması, bilişimin günlük yaşantımızla daha kolay bütünleşmesine olanak sağlıyor.
- **Özgür / açık kaynak yazılım:** Gevşek bir ekip tarafından geliştirilen yazılım daha anlaşılır ve geliştirilebilir olmalıdır.
- **Ayrıca:** takım çalışması zorunluluğu, küreselleşme, ekonomik krizler.

Hoca, hesaplama gücünün artmasının daha fazla yazılımın kullanılmasına ve yaygınlaşmasına, bunun da yazılımın geniş kitlelere yansımasına yol açtığını; özgür ve açık kaynak yazılımın da bu yaygınlaşmayı hızlandırdığını söyledi. Küreselleşme, ekonomik krizler ve ekip çalışması hem yazılım geliştirmeyi hem de yazılımın kullanımını etkileyen faktörlerdir.

## 9. Paydaşlar ve Yazılım Hakkındaki Yanılgılar

### 9.1 Paydaşlar: Müşteri, Kullanıcı, Yönetici, Programcı

Yazılım geliştirme sırasında bir müşteri tarafı, yazılım geliştirme birimindeki yöneticiler, teknik ekip (programcılar) ve kullanıcılar vardır. Her biri yazılım geliştirme işine farklı bakar ve her birinin kendine özgü yanılgıları olabilir.

**Müşteri** iki tipte karşımıza çıkar: bir yazılım evinde geliştirilen genel amaçlı yazılımı alıp kullananlar ya da bir işletmede yazılım geliştirme biriminden hizmet alan diğer departmanlar. Müşteri bazen doğrudan kullanıcı olabilir; bazen de bütün departman veya departmanın yönetim birimi müşteri sayılır.

Hocanın örneği: bir yazılım firması bir bankaya yazılım geliştiriyorsa **banka yönetimi müşteridir**. **Kullanıcılar** (*end user*, uç kullanıcı) ise o programı fiilen kullanacak banka memurları ya da bankanın müşterileridir.

### 9.2 Müşteri Açısından Yanılgılar

Slayttaki içerik (ekrandan, 01:34:08):

- "Programın yazılmasına başlanması için amaçları genel olarak belirlemek yeter, ayrıntılar sonra kararlaştırılabilir. Nasıl olsa yazılım esnektir."
  - Belirsiz gereksinimler, çürük atılmış temele benzer.
- "Yazılım esnektir. Değişen gereksinimler kolayca sisteme uyarlanabilir."
  - Yazılım yaşam döngüsünde ilerledikçe, değişen gereksinimleri yazılıma uyarlamanın bedeli üstel olarak artar.
- Sonuç: yazılım esnek bir oyun hamurundan çok kil veya cam gibidir.
  - Çevik süreçlerle esnekliğin artırılması hedeflenmektedir.

Hoca, ilk başta bütün kullanım ayrıntılarının verilmesi gerektiğini, aksi halde yazılımın iyi bir temele oturmayacağını söyledi. Yazılım geliştiriciler, gereksinimleri sonradan eklemenin iş gücünü artıracağını iyi bilir: yazılım ne kadar esnek olursa olsun, ilk baştaki gereksinimler değişiyorsa süreç baştan gözden geçirilmeli ya da yeniden yapılmalıdır. İşin zorluğu bu yüzden hafiflemez.

Müşterinin bir başka yanılgısı da "ne için istediğimi belirttiğimde işim biter, bundan sonrasını yazılımcı halleder" düşüncesidir. Oysa müşterinin her adımda bilgi vermesi, gerekli ürünleri ve ara ürünleri kontrol etmesi gerekir. Müşteriyi doğru yönlendirmek gerekir; çevik süreçlerle müşteri baştan işin içine katılıp sürece dahil edilebilir.

### 9.3 Programcı Açısından Yanılgılar

Slayttaki içerik (ekrandan, 01:39:08):

- "Yazılımı tamamlayıp müşteriye teslim edince işimiz biter."
  - Yazılım üstünde harcanan çabanın yarısından fazlası, yazılımın müşteriye ilk teslimatından sonra harcanmaktadır.
- "Yazılımı tamamlamadan kalitesini ölçemem."
  - Kalite güvence yöntemleri yazılım hayat döngüsünün her aşamasında uygulanabilir.
  - Çözümleme sürecinde dahi kullanılabilecek kalite ölçütleri bulunmaktadır.
- "Yazılım eşittir program."
  - Gereksinim analizi başlı başına bir emektir.
  - Dokümantasyon ve sınama çalışmalarını da unutmayın!
  - Bazı durumlarda entegrasyon çalışmaları da gerekmektedir.
- "Yazılım mühendisliğinin gereklerini uygulayarak boşuna çaba harcıyoruz."
  - Haritası olmayan yolunu kaybeder.
  - Kalite için harcanan çaba, karşılığını yazılım hayat döngüsünün ilerleyen aşamalarında fazlasıyla ödeyecektir.
  - Küresel ölçekte yazılım projelerinin %50'si başarısızlığa uğramaktadır.

Hoca, teslimattan sonra müşteriyi yazılıma alıştırma ve teslimatı (*release*) doğru yapma işinin de programcının sorumluluğunda olduğunu ekledi. Kalite güvencesi için her aşamada gözden geçirme (*review*) yapılır; bu sırada hem kontrol hem ölçme gerçekleştirilebilir. Program kod karmaşıklığı ya da güvenilirlik ölçüsü gibi metrikler yazılım bitmeden de uygulanabilir.

> **Hocanın vurgusu:** Her aşamada dokümantasyon ve tasarım yapmak, gereksinim analizini iyi yapmak "işi boşuna uzatmak" değildir. Bu en önemli yanılgılardan biridir; temel ilk başta sağlam kurulmadığında projelerin başarısız olduğu görülür.

### 9.4 Yönetici Açısından Yanılgılar

(Bu slayt kayıt karelerinde yer almadığından anlatım altyazıdan aktarılmıştır.)

- "İşler yetişmiyorsa takıma yeni bir programcı ekleriz." Yazılım hayat döngüsü içinde proje yönetimi baştan proje planlamasıyla başlamalı, yeni eleman da plana göre eklenmelidir.
- "Geliştirmesini üstlendiğim yazılımın tamamını veya bir kısmını fason olarak yaptırabilirim." Alt yükleniciler kullanılabilir, ancak bunlar baştan planlanmalı ve takibi, kontrolü iyi yapılmalıdır.
- Açık kaynaklı yazılım konusunda da yöneticilerin bazı yanılgıları olabilir.
<!-- BELİRSİZ: Açık kaynak yanılgısının içeriği derste açıklanmadı. -->

> **Ek bilgi (derste anlatılmadı):** Geciken bir projeye eleman eklemenin projeyi daha da geciktirdiği gözlemi literatürde büyük olasılıkla Brooks Yasası olarak bilinir (Frederick Brooks, *The Mythical Man-Month*, büyük olasılıkla 1975). Yeni katılanların projeyi öğrenmesi ve ekip içi iletişim yükünün artması bunun başlıca nedenleridir.

## 10. Yazılım Süreçlerinin Genel Adımları

Bu adımlar sistem analizinden de bilinir; derste tekrar gözden geçirildi. Slayttaki liste (ekrandan, 01:44:08):

- Çözümleme (*Analysis*)
- Tasarım (*Design*)
- Gerçekleme (*Implementation*)
- Sınama (*Testing*)
- Bakım (*Maintenance*)

Hoca, proje planlamanın ayrı bir adım olarak analizden önce de konabileceğini söyledi. Pressman'ın kitabına dayandırdığı tanıma göre analiz, tasarım, gerçekleme ve test temel adımlardır; bunları planlama, proje yönetimi, konfigürasyon yönetimi, risk analizi ve risk yönetimi, kalite yönetimi gibi **destek etkinlikleri** iyileştirir.

> **Ek bilgi (derste anlatılmadı):** Pressman'ın kitabının 8. baskısında genel süreç çerçevesi büyük olasılıkla iletişim, planlama, modelleme, inşa ve dağıtım (*communication, planning, modeling, construction, deployment*) etkinlikleri olarak verilir; proje izleme, risk yönetimi, kalite güvencesi, teknik gözden geçirmeler, ölçüm ve konfigürasyon yönetimi gibi işler ise "şemsiye etkinlikler" (*umbrella activities*) olarak adlandırılır.

Bu adımlar şelale (*waterfall*) modelinde olduğu gibi sırayla dizilebilir ya da başka modellere göre düzenlenebilir; süreç modelleri sonraki derslerin konusudur.

### 10.1 Çözümleme

Slayttaki içerik (ekrandan, 01:44:08):

- Çözümleme: bir şeyi **anlayabilmek** için parçalarına ayırmak.
- Gerçeklenecek sistemi **anlamaya** yönelik çalışmalardan ve **üst düzey** planlama eylemlerinden oluşur:
  - Uygulama alanı
  - Kullanıcı gereksinimleri
  - Program parçaları arasındaki üst düzey ilişkiler ve etkileşimler (NYP'deki parçalar: sınıflar ve nesneler)
- "Bir sorunu anlamadan çözemezsiniz."

Çözümleme, "ne yapıyoruz, problem nedir?" sorusuna cevap aranan aşamadır.

### 10.2 Tasarım ve Gerçekleme

Tasarım, çözümlemeden sonraki adımdır. Gereksinim analizinde elde edilen veriye göre sorunun çözümü planlanır ve model oluşturulur; yazılımın tasarımına ait planlar ve şemalar hazırlanır. Gerçekleme aşamasında ise elde bulunan tasarım bir programlama diliyle kodlanır.

### 10.3 Sınama

Slayttaki içerik (ekrandan, 01:49:08):

- Sınama neden önemlidir?
  - Yazılım sürecinde ilerledikçe, ortaya çıkabilecek hataların giderilme maliyeti üstel olarak artar.
  - Aksi gibi, hataların büyük çoğunluğunun kökenleri isteklerin belirlenmesi ve tasarım aşamalarındaki sorunlara dayanır.
  - Bu yüzden: erkenden, sık sık ve kolay sınama yapın.

Hoca bu nedenle yazılımın ara gözden geçirmelerle test edilmesi gerektiğini vurguladı.

### 10.4 Bakım ve Yeniden Mühendislik

Bakım aşamasında yapılanlar:

- Hataların düzeltilmesi: kod hatası, tasarım hatası ya da analiz hatası.
- Sistemin değişen işlevlerine uyum sağlanması.
- Yazılımın daha etkin hale getirilmesi.

Bakım sırasında yeniden mühendislik (*re-engineering*) ve yeniden düzenleme (*refactoring*) aşamalarından da geçilebilir: teknik bakış açısıyla işlevi değiştirmeden iç yapıyı değiştirmek, belgeleme yapmak, tasarımı iyileştirmek ya da yazılımı farklı bir ortam üzerine taşımak. Hoca bu kavramlara dönem içinde ayrıca değineceğini belirtti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:51:34): Yazılım mühendisliği tanımındaki "en ekonomik" kavramı açısından, sistem analizi dersinde bir projenin ekonomik olup olmadığına hangi çalışmada bakılıyordu?

> **Cevap (derste verildi):** Fizibilite çalışmasında, özellikle ekonomik fizibilitede. Fizibilite analizinde problemin teknik olarak (teknik olurluluk) ve ekonomik olarak çözülüp çözülemeyeceği incelenir. Ekonomik olmak en ucuz olmak değil, harcama ile fayda arasındaki en uygun dengedir.

**Soru 2** (derste sözlü, 00:54:20): Bir mühendisin problem çözerken ve ürün geliştirirken kullanması gereken, mühendislikte öne çıkan en önemli iki araç/yetenek nedir?

> **Cevap (derste verildi, 01:06:23):** Tasarım ve ölçüm. "Beklenen performansı sağlamak" ve "bütçeyi aşmamak" hedeflerdir, araç değildir. Ölçüm, biten bir ürünü sonrakilerle kıyaslamayı ve yeni ürünlerin maliyetini tahmin etmeyi sağlar.

## Dersin Toparlaması

Bu ilk derste yazılım mühendisliği "kaliteli yazılımı en ekonomik olarak hazırlamak üzere mühendislik araçlarını ve yeteneklerini kullanan bilim dalı" olarak tanımlandı ve bu tanımdaki her kavramın dersin bir alt başlığına (kalite ve test, proje yönetimi ve planlama, tasarım ve ölçüm, süreçler) karşılık geldiği gösterildi. Yazılımın yalnız program olmadığı, belgeleri ve veri bilgisiyle birlikte bir ürün olduğu; aşınmadığı ama değişikliklerle yetersizleştiği ve uzun süre yaşayan yazılımların eski yazılıma dönüştüğü anlatıldı. Müşteri, programcı ve yönetici açısından yaygın yanılgılar üzerinden, gereksinimlerin baştan doğru belirlenmesinin ve sürecin her aşamasında kalite güvencesinin neden zorunlu olduğu vurgulandı.

Son olarak yazılım sürecinin çözümleme, tasarım, gerçekleme, sınama ve bakım adımları gözden geçirildi. Bir sonraki derste bu adımların nasıl düzenlendiğini gösteren klasik süreç modelleri (şelale, spiral vb.), ardından da çevik modeller işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
