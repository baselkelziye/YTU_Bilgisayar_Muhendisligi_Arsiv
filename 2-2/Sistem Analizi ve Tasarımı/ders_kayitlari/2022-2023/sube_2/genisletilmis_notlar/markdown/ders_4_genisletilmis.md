# Ders 4 Genişletilmiş Notu: Gereksinim Analizi, İş Analizi, Kullanım Senaryosu Modellemesi ve Bilgi Toplama Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Gereksinim Analizine Giriş
- 2. Gereksinim Analizi Safhasının Tanımı ve Çıktıları
- 3. Mevcut Durumun Tespiti
- 4. Gereksinimlerin Belirlenmesi ve SRS Dokümanı
- 5. Gereksinim Analizinin Genel Akışı
- 6. İdari İncelemede Yönetimin Baktığı Noktalar
- 7. Kullanım Senaryosu Modellemesi
- 8. Kullanım Senaryosu Diyagramı
- 9. Senaryo Yazma Kuralları
- 10. Kullanım Senaryosu Dokümanının Şablonu
- 11. Senaryolar Arası İlişkiler
- 12. Hastane Örneği Üzerinde İlişkileri Okumak
- 13. Bankacılık Örneği
- 14. Araştırma ve Bilgi Toplama Yöntemleri
- 15. Gözlem Yöntemi
- 16. Kişisel Görüşme Yöntemi
- 17. Anket Yöntemi
- 18. İş Analizinin Çıktısı: BRD ve Araştırma Raporu

## 1. Gereksinim Analizine Giriş

Hoca derse, bir bilgi sistemi geliştirme çalışmasının bütününü hatırlatarak başladı. Bir ekip önce bir problemi inceler, Project Charter gibi bir belgeyle işi yapıp yapamayacağına karar verir ve niyetini ortaya koyar. Ardından alternatif sistem önerileri için fizibilite çalışması yapılır. Öneriler ekonomik, zaman, sosyal, yasal ve teknik fizibilite açısından, ağırlıkları da düşünülerek karşılaştırılır ve mantıklı bir çözüm önerilir. Önerilen çözüm üzerinden problemin gereksinimleri ortaya çıkarılır: Bu analiz safhasıdır. Sonra analizdeki problemin parçalarına uygun bir tasarım hazırlanır, gerçekleştirilir ve devreye alınır.

Bu dersin konusu, fizibilite çalışmasından sonra gelen safhadır. Bu safhada yapılanların hepsi aslında teknik değildir. Ama sistemin teknik çözümlemesine yol gösterir, ona zemin hazırlar ve sağlam bir dayanak oluşturur. Safhalar içindeki genel adı **gereksinim analizidir**.

Sıralama şöyledir: Birinci aşama ön inceleme, ikinci aşama fizibilite çalışmaları, üçüncü aşama gereksinim analizidir.

### 1.1 Gereksinim Analizinin İki Adımı

Gereksinim analizi temel olarak ikiye ayrılır. İlk adım **iş analizidir**. Buna iş gereksinimlerinin (business requirements) ortaya çıkarılması, belirlenmesi de denebilir. Bu ders iş analizini anlatır.

İş analizinde mevcut durumda işin nasıl yapıldığı, işleyişin nasıl olduğu anlaşılır. Örneğin kâğıt üzerinde formlar dolduruluyorsa bunların neler olduğu ve hangi bilgilerin doldurulduğu belirlenir. Bu akışa kimlerin dahil olduğuna, kimin hangi rolü üstlendiğine, nereden sorumlu olduğuna bakılır: Bir şeyi taşıyor mu, dolduruyor mu, yoksa gerçekten bir şey üretiyor mu? Bütün tarafların ne yaptığıyla birlikte işin anlaşıldığı ve bunun **formal bir biçimde raporlandığı** aşama iş analizi aşamasıdır.

İkinci adım **çözümleme** ya da **işlevsel çözümlemedir**. İş analizinin çıktılarıyla ortaya konan iş gereksinimleri, teknik modele altyapı oluşturacak şekilde dönüştürülür. Yani biraz daha teknik bir gösterimle yazılım dünyasına yaklaştırılır. Gereksinimler belirlendikten sonra bunların hangi yazılım süreçleri ya da iş akış süreçleriyle gerçekleştirilmesi gerektiği tanımlanır. Bu adım haftaya işlenecek.

İki adım bir araya geldiğinde problem uzayı modellenmiş olur. Problemin ihtiyaçları, yani gereksinimler (requirements) belirlenmiş, tanımlanmış, açıklanmış ve birbirleriyle ilişkileri ortaya konmuştur. Bunların nasıl işlediği de teknik görsel çıktılara dönüştürülmüştür.

### 1.2 İş Analizinin Sonuçlarını Ortaya Koymanın İki Yolu

İş analizinin sonuçlarını oluşturmak ve raporlamak için iki temel yol vardır.

- **Gereksinimlerin tanımlanması:** Gereksinimler bir tablo ya da rapor halinde tanımlanır. Bu yapılabilir.
- **Kullanım senaryosu modellemesi (use case modeling):** Özellikle nesneye dayalı bir sistem geliştirilecekse çözümlemeye ve tasarıma yardım etme konusunda daha başarılı ve daha doğru yoldur.

Hoca kullanım senaryolarını çok basit olmasına rağmen kuvvetli, temel bir araç olarak niteledi.

### 1.3 Bilgiye Erişme Sorusu

İşin analizini yapabilmek için sistem analistinin bir şekilde veriyi toplaması, bilgiye erişmesi gerekir. Bunun bir yolu yordamı olmalıdır. Müşteriye ya da sistemi talep eden tarafa gittiğinizde kimlerle, nasıl görüşmelisiniz? Problemin ne olduğunu, analiz modeli halinde raporlayabileceğiniz biçimde nasıl almalısınız?

Bazen de belirli bir müşteri yoktur, son kullanıcıya hitap eden bir yazılım oluşturmak istersiniz. Hocanın örneği mobil dünyadan: App Store'da hep trend olsun, kendi alanında ilk 10 ya da ilk 5 içinde yer alsın istiyorsunuz. Bunun için uygulamanın ne gibi özellikleri olmalı? İnsanların ihtiyacı ne, ne bekliyorlar? Bunu da ancak bilgi toplayarak öğrenebilirsiniz. Bilgi toplamanın yolları dersin ikinci yarısında anlatıldı.

## 2. Gereksinim Analizi Safhasının Tanımı ve Çıktıları

Gereksinim analizi, bilgi sistemi geliştirme sürecindeki üçüncü adıma verilen isimdir. Bu safhada problemin ne olduğu, çözümü için hangi parçalara ihtiyaç olduğu, bu parçaların nasıl çalıştığı, sistemin genelinin nasıl çalışması ve nasıl bir hizmet üretmesi gerektiği sorgulanır. Bu soruların cevaplarını ortaya çıkarmak için yapılan çalışmalar gereksinim analizi aşamasını oluşturur.

Fizibilitedeki önerilere dayanılarak müşterinin ya da son kullanıcının isteklerini en uygun biçimde karşılayan çözüm aranır. Hedef, en hızlı üretilen, en az maliyetle üretilen ya da en az sistem kaynağı tüketen çözüm olabilir. Hedef hangisiyse onu en iyi karşılayan çözümde olması gereken ana parçaların ve bunların görev, sorumluluk ve işlevlerinin tanımlanması, bu safhanın temel amacıdır. Bunun için hedefler ayrıntılandırılır, bilgi kaynakları ve kullanıcıların ihtiyaçları net, somut biçimde belirlenir.

### 2.1 Safhanın Çıktıları

Bir safhayı yaşadığımızı ve düzgün işlettiğimizi söyleyebilmek için çıktı üretmemiz gerekir. Gereksinim analizinin çıktıları şunlardır:

- Son kullanıcının ya da müşterinin bu sistemde çözmek istediği bütün ihtiyaçların listesi.
- Mevcut durum. Var olan bir bilgi sistemi olabilir ya da hiç olmayabilir. Mevcut işleyişin nasıl olduğu ortaya konur.
- Fizibiliteden gelen önerilerle en uygun çözümün değerlendirmesi. Yani fizibilitenin kesinleştirilmesi ve bunun raporlanması.

### 2.2 Yeni Sistem Yerine İyileştirme

Analiz sonucunda yeni bir sistem geliştirmek yerine mevcut sistemde belli geliştirmeler yaparak ihtiyaçların karşılanabileceği de fark edilebilir. O zaman sorulacak soru şudur: Mevcut sistemi nasıl iyileştirebilirim? Donanımda genişleme ya da ölçeklendirme mi gerekir, yazılıma ne gibi ilaveler yapılmalıdır? Belki iki temel modül eklemek yetecektir. Belki de girdi sağlamak için bir QR okuyucu ya da RFID okuyucu entegrasyonuyla sistem çalışmaya devam edecek ve bütün beklentileri karşılayacaktır. Böyle bir çözüm bulunabiliyorsa yalnız bu önerilir. Her zaman yeni bir sistem ortaya koymak gerekmez.

### 2.3 Bu Aşamada Fizibilitenin Gözden Geçirilmesi

Gereksinim analizi yapılırken fizibilite raporları gözden geçirilir ve kullanılacak bütün teknik terimler incelenir. Üst yönetimin süreci nasıl denetleyeceğine dair yönetim inceleme planı da yapılır.

Zaman fizibilitesi kapsamında proje grubu işlere paylaştırılmış, görev dağılımı yapılmıştı. Burada yeni işlevler ya da görevler ortaya çıkabilir, iş planında değişiklik gerekebilir. Bu yüzden görev dağılımının nihai hali burada oluşturulur. Hoca farkı şöyle anlattı: Fizibilitedeki bilgi aslında bir tahmindi, bir niyetti, "şöyle yapabiliriz" demekti. Analizle birlikte artık "şu faaliyet fazlaymış, şu faaliyetleri mutlaka eklemem gerekir, o yüzden kaynakları şöyle değiştiriyorum" diyebiliriz. Bir yandan da ayrıntılı inceleme planıyla birlikte yönetim denetim mekanizması mutlaka kurgulanır.

## 3. Mevcut Durumun Tespiti

Bir sistem analisti ya da analist ekibi, problemi ortaya koymak ve çözüm önerisi geliştirmek üzere çalışmaya başladığında ilk yapması gereken şey mevcut durumu anlamaktır: Var olan sistem nedir, nasıl çalışır, bu çalışmanın maliyeti nedir? Bunun için analistlerin var olan sisteme hâkim olmaları, onu kullanmaları, onunla çalışmaları gerekir. İncelenecek başlıklar şunlardır:

- Bilgi kaynakları, donanım ve yazılım.
- Kullanılan bilginin hacmi, içeride ne kadar bilgi kullanıldığı.
- Dış sistemlerle etkileşimin ne kadar olduğu.
- Sistemin rutin olarak yaptığı döngüsel işler, bunların ne kadar sürdüğü, ne kadar sürede bir yapıldığı.
- Arşivleme için yapılanlar.
- Üretilen çıktılar ve raporlar, bunların formatları.
- Sistemle etkileşen bütün paydaşlar: Kimler, ne görev yapıyorlar, işlerini ne kadar zorlanarak ya da kolaylıkla yapıyorlar?
- Mevcut sistemin çalışma maliyetleri.

Analistten beklenen, bunların hepsini ortaya çıkarıp mevcut durumun adeta **fotoğrafını çekmesidir**. Hoca bunu Nutuk'a benzetti: Atatürk, Nutuk'ta 19 Mayıs 1919'da Samsun'a çıktığını söyleyip önce memleketin o anki halini anlatır. Burada da önce içinde bulunduğumuz durumu tanıyıp somut biçimde ortaya koyarız, ondan sonra yeni sistemi oluşturmaya geçeriz.

## 4. Gereksinimlerin Belirlenmesi ve SRS Dokümanı

Mevcut sistemi ortaya koyduk ve ona hâkim olduk. Yeni istekler, değişen gereksinimler var. Bu ihtiyaçların listesi oluştuktan sonra gereksinimleri belirlemek için müşterinin durumuna göre iki yol izlenir.

### 4.1 Müşteri Ne İstediğini Biliyorsa: İş Akışları

Müşteri problemini biliyor ve "bana bu lazım, şu kalite kriterleriyle lazım" diyebiliyorsa gereksinimler daha net ifade edilebilir. Müşteriyle birlikte netleştirilen gereksinimler akış diyagramlarıyla, yani iş akışlarıyla anlatılır. İşlevlerin neler olacağı, arayüzleri, kabul kriterleri ve organizasyonda hangi bilişim alanlarına hizmet ettiği belirtilir ve diyagramlarla ifade edilir.

### 4.2 Müşteri Ne İstediğini Bilmiyorsa: Prototip

Bazen müşteri ne istediğini tam anlatamaz ya da farkında değildir. "Bunu da yapabiliyor muyuz?" diyen, hatta "Ben onun bilgisayarla yapılabileceğini bilmiyordum" diyen müşteri bile olabilir. Siz de o çalışma alanına (domain) çok hâkim değilseniz şu yol daha doğrudur:

1. Önce basit bir prototip oluşturun ve çözüm önerinizi bu prototiple sunun.
2. Müşteriyle birlikte üzerinden geçin. Yetkililer baksın, "burası güzel, bu işimi çok kolaylaştırdı" ya da "biz bunu böyle yapamayız, çünkü şöyle bir şey yapması lazım" desinler.
3. Bu geri bildirimlerle prototipi genişletin, güncelleyin, iyileştirin.

Böylece prototip üzerinden müşteriyle tartışarak, adım adım ilerleyerek gereksinimlerin son haline karar verilir.

### 4.3 SRS Dokümanı

İki yoldan biriyle gereksinimler belirlendikten sonra iş analizi modelinin sonuçları elimizdedir: Bu sistem şu işi yapmalıdır, şöyle bir modülü olmalıdır, bu modülde şu işler şöyle yapılmalıdır, bu modül şuna şöyle hizmet etmelidir, şu modülden çalışabilmek için şunları almalıdır. Yani parçaların nasıl bir araya geldiği, kimin kime ne sunduğu ve ne aldığı, hangi ihtiyaçların nasıl karşılandığı yazılır.

Müşteriyle birlikte bulunan gereksinimlerin ve özelliklerinin rapor haline getirilmiş biçimine **sistem gereksinimleri spesifikasyonu** denir. Kısaltması **SRS** olan bu dokümanda baştaki S hem sistem (system) hem yazılım (software) olabilir, ikisi de geçer. Genellikle "software requirement specification" olarak kullanılır. Hoca bunun bir sistem prototipi ya da niyet beyanı olarak da düşünülebileceğini söyledi. SRS'in içeriğine bu hafta ve önümüzdeki hafta temel olarak değinilecek.

> **Hocanın vurgusu:** İnternette "SRS document" diye aratıp farklı örneklere mutlaka bakın. Genel yapıları üç aşağı beş yukarı benzerdir. İçeriklerin farklı yaklaşımlarla nasıl oluşturulduğunu inceleyin.

Gereksinim spesifikasyonu oluşturulurken sistemin geliştirme planı, yani Gantt şeması da gözden geçirilir. Yönetimin bunu nasıl onaylayacağı ve işlerin doğru yürüdüğünü nasıl takip edeceği de eş zamanlı olarak SRS ile buluşturulur. Geliştirme planı ve sistem analizi esasen iç içe, aynı anda yürütülür. Buna gereksinimlerin tanımlanma aşaması da denir.

## 5. Gereksinim Analizinin Genel Akışı

Hoca slaytta bir iş akışı üzerinden süreci özetledi:

1. Ana sisteme ait yazılım elemanları, konu, kaynaklar ve giderler belirlenir. Teknik, ekonomik, zaman ve diğer fizibiliteler bir araya getirilerek yapılabilirlik etüdü gerçekleştirilir.
2. Bununla bir yazılım planı oluşur. Bu, geçen hafta anlatılan niyet beyanıdır, yani Project Charter: Problem ne, amaç ne, nasıl yaparız, ne kadar zamanda, kim ne yapar, ne kadar kaynakla yaparız?
3. Plan **idari incelemeden** geçer, yani yönetim gözden geçirir. Gerekiyorsa revize edilir. Kabul edilince gereksinim analizi aşamasına geçilir.
4. Gereksinimler biliniyorsa tanımlanır. Tasarım kısıtları, başka sistemlerle konuşma arayüzleri, başka işlevlerle etkileşim noktaları ve yönetimin onay kriterleri belirlenir. Bunlar yazılım gereksinimlerini, yani SRS dokümanını oluşturur.
5. Gereksinimler bilinmiyorsa model oluşturulur, örneğin prototip geliştirilir.
6. Gereksinimler **teknik incelemeden** geçer ve revize edilir. Bu incelemeyi daha çok analistler yapar. Bütün gereksinimler bittiğinde doküman tamamlanmış olur.
7. Yönetim, planı gereksinim analizinde yapılan her şeyle birlikte **yeniden inceler**. Kabul ederse tasarım aşamasına geçilir. Etmezse gerekli revizyonlar yapılıp inceleme tekrarlanır.

Hoca, son revizyon için şekilde geriye bir dönüş oku çizilmesi gerektiğini de söyledi. Akıştaki birinci ve dördüncü karar noktaları idari incelemelerdir.

<!-- BELİRSİZ: 00:27:42'de hoca akıştaki "birinci ve dördüncü" karar noktalarının idari olduğunu söylüyor; ikinci ve üçüncü noktalar altyazıda numarayla sayılmıyor. İkincisi "gereksinimler biliniyor mu" dallanması, üçüncüsü teknik inceleme gibi görünüyor, ama slaytta doğrulanamadı. -->

## 6. İdari İncelemede Yönetimin Baktığı Noktalar

Hoca, yönetimin ileride yaptığınız bir analizi gözden geçirirken nelere bakacağının şimdiden farkında olmanızı istedi. Yönetim şunlara bakar:

- **Stratejik uyum:** Belirlediğiniz ihtiyaçlar işletmenin genel stratejileriyle uyumlu mu, yoksa alakasız mı?
- **Bilgi, deneyim ve öngörü:** İş akışının nasıl olacağına dair kararlarda üçü birlikte kullanıldı mı? Çözümü ortaya koyanlar mevcut sistemi biliyor mu, deneyim sahibi mi, değişebilecek durumlara karşı öngörü çalıştırıldı mı?
- **Çatışan ihtiyaçlar:** Birbiriyle çekişen ihtiyaçlar varsa hangisi işletmeye daha çok fayda sağlar? Hangisiyle devam edilir, hangisi bırakılır?
- **Somut mali fayda:** Verimlilik ve kârlılık artışı sağlanıyor mu, ne kadar? Hocanın deyişiyle: Attığım taş ürküttüğüm kuşa değecek mi, verdiğim paranın karşılığını alabilecek miyim?
- **Organizasyondaki sayısal değişiklik:** Sistem çalışan sayısında azalma ya da artma olasılığı yaratıyor mu? Hoca, o günlerde duyulan Amazon'un 9000 kişiyi işten çıkarması haberini örnek verdi: Bir sistem devreye alınınca 9000 kişi işten ayrılacak mı? Bunun şirket için iyi olacağını da ekledi. Tersine, sistemi çalıştırmak için yeni bir istihdam kanalı da gerekebilir.
- **Raporlama kalitesi:** Hızlı ve ayrıntılı raporlar var mı?
- **Bilgi akışları ve güncellemeleri:** Planlı mı yapılıyor, rastgele mi?
- **Fark:** Yeni çözüm mevcut durumdan fark edilir derecede iyi ve hızlı mı, bu değişikliği yapmaya gerçekten değecek mi?
- **Teknoloji uyumu:** Kullanılan teknolojiler yeterli mi, mevcut bilgilerimizle ve çalışan sistemlerimizle uyumsuzluk yaşar mıyız?
- **Kullanıcı etkileşimi ve verinin organizasyonu:** Düzgün mü?

> **Hocanın vurgusu:** Yönetim raporlara çok önem verir, her şeyi raporlar üzerinden izler. Bu yüzden bütün sistemlerin çok net ve derin, özelleştirilebilir raporlar üretmesini ister. İşlettiğiniz bütün süreçlerle ilgili farklı kırılımlarda ayrıntılı analiz raporları oluşturmanız size fayda sağlar. Yöneticiler ne kadar iyi rapor oluşturulduğuna mutlaka bakar.

Hoca bu nedenle eksik kalan proje modüllerine genellikle istatistik raporlamalar eklediğini söyledi ve bir spor salonu bilgi sistemi üzerinden örnek verdi:

- Abone sayısının aylara ve haftalara göre değişimi bir grafikle gösterilebilir.
- Saatlere göre kullanım sıklığı bir pasta ya da radar grafiğinde gösterilebilir.
- Belli yaş gruplarındaki abonelerin hafta içi ve hafta sonu kullanım yoğunlukları ya da saat dağılımları bir ısı haritasıyla (heatmap) gösterilebilir.

Bu bölümü toparlarsak: Gereksinim analizinde, özellikle ilk aşama olan iş analizinde müşteriyle birlikte çalışılır. Müşteri ihtiyacını biliyorsa iş akışlarıyla gösterilir, bilmiyorsa prototiple devam edilir. Her durumda önce mevcut sistem ortaya konur, sonra isteklerin neler olduğu ve nasıl yapılabilecekleri yazılır. Yönetimin belli kriterlerle inceleyeceği de göz önünde tutularak bu kriterleri karşılayan bir doküman ve çözüm önerisi hazırlanır.

## 7. Kullanım Senaryosu Modellemesi

İş analizinde gereksinimlerin neler olduğunu ve işlerin nasıl aktığını ortaya koymamız gerekir. Hoca bunu bir sipariş sistemiyle örnekledi: Sipariş kimin ekranına düşüyor? O kişi depodan ürünü kendisi mi alıyor, yoksa depoda birine "şunu getir" mi diyor? Ürünü kendi dağıtım araçlarıyla mı dağıtıyor, kargocuya mı veriyor? Bir dağıtım planlaması yapılıyor mu, yapılıyorsa kim yapıyor? Yani iş nasıl akıyor, her adımda ne yapılması lazım?

Bunu anlatmanın çok basit ve çok etkili yollarından biri **kullanım senaryosu modellemesidir (use case modeling)**. Gereksinim analizi safhasında, özellikle iş analizi yaparken, gereksinimlerin ve bu gereksinimlerdeki eylem akışlarının nasıl olması gerektiğinin **yarı formal, yarı yapılı** bir biçimde anlatıldığı modele bu ad verilir.

Her senaryo sistemdeki bir sorumluluktur. Sistemin bir çözüm üretmek için koşması gereken bir yol, bir akıştır. "Kullanım senaryosu" denmesinin sebebi de budur: Senaryoyu çalıştırıp kullanırız ve sonucunda bize faydalı bir çıktı üretir. Örneğin siparişin kargoya verilmesini sağlar ya da bir satış fişi oluşturup muhasebe sistemine aktarır.

### 7.1 Kargo Dağıtım Planlaması Örneği

Hoca, bir dağıtım şebekesini yönettiğinizi varsaymamızı istedi. 22 Mart Çarşamba günü İstanbul'da Esenler bölgesine 600 paket, 600 tekil adrese dağıtılacak. Bu adresler kaç araçla, en az yol yapılarak, en kısa sürede nasıl dağıtılabilir? Bu planlama için adım adım şunların anlatılması gerekir:

- Adres bilgileri nereden ve nasıl alınacak?
- Paket bilgileri ve boyutları nereden ve nasıl alınacak?
- Bu bilgiler üzerinde nasıl bir algoritma koşturularak optimizasyon yapılacak?

Bunlar, işin yazılımını yapacak teknik kişilere anlatılmalıdır. Kullanım senaryosu modellemesi bunun için kullanılır.

**Soru:** Kargo firmaları dağıtımı gerçekten böyle planlı mı yapıyor? **Cevap:** Hocaya göre planlı dağıtan da var, planlamayan da. Aras örneğinde durum şöyle olabilir: Bir mahalle ya da dağıtım bölgesi için iki araç varsa, iki aracın toplam kapasitesi kadar paket planlanır ve sürücüye "bugün bunlar teslim edilecek, ister sağdan gir ister soldan" denir. Bazı firmalar ise az önce anlatılan optimizasyonu çok iyi kullanır. Hoca, bunu ilk başlatanlardan biri olarak Amazon ile çalışan Kolay Gelsin'i örnek verdi. Amazon gece saatlerinde ertesi günün dağıtım listesini verir. Paketlerin boyutu ve adresleri bellidir. Firma, dağıtım anındaki araçlarına ne kadar yük vereceğini ve nasıl bir rota izleneceğini planlar. Sabah rotayı sürücünün navigasyonuna "bu sırayla dağıtacaksın" diye verir.

<!-- BELİRSİZ: 00:36:45'te öğrencinin sorusu altyazıda yok, yalnız hocanın cevabı var. Soru cevaptan kuruldu. Cevabın ilk cümlesinde "Ticari boşluk şöyle" diye anlamsız bir ifade geçiyor. -->

Dağıtım bilgileri de toplanır. Hoca burada ilk derste anlatılan **geri besleme** mekanizmasını hatırlattı. Bu veriler rota optimizasyonu için sisteme yeniden verilir. Belki bir haftalık izleme sonunda şu görülür: Güneyden başlarsam toplam dağıtım sürem 3 saat uzuyor, batıdan başlarsam trafik daha hızlı aktığı için daha çabuk dağıtıyorum. Böylece model kendini iyileştirebilir.

## 8. Kullanım Senaryosu Diyagramı

Modellemenin temel çıktısı **kullanım senaryosu diyagramıdır (use case diagram)**. Bu diyagram, sistemin kullanıcıların bakış açısıyla işlevsel bir çözümlemesidir. Sistemin modüllerini, sahip olması gereken temel nitelikleri ve hizmetleri gösteren çok basit bir diyagramdır.

### 8.1 Aktörler ve Senaryolar

Diyagramda iki temel unsur vardır.

**Aktörler:** Hocanın sorusuyla: Senaryoda kim oynar? Aktör oynar. Aktörler sistemin kullanıcıları, sistemin etkileştiği dış sistemler ya da farklı fiziksel birimler olabilir. Sistemle etkileşime geçen her tür canlı, cansız varlık ya da birim aktör olabilir.

**Senaryolar:** Sistemin bir olay akışı şeklinde sağladığı işlevlerdir. Yani bir iş akışıyla yerine getirilebilen bir sorumluluktur. Her senaryo sistemde ayrı bir sorumluluk olmalıdır. Kargo örneğinde kargo yolunun bulunması bir sorumluluktur. Daha da kırılırsa araç kapasitelerinin belirlenmesi, kargo boyutlarının ve teslim adreslerinin öğrenilmesi gibi alt işler de alt senaryolar olarak işletilir. Demek ki işlevsellikler senaryolarla paketlenir ve her sorumluluk ayrı bir senaryo olur.

Bir senaryoyu düzgün ifade etmek için şunlar tanımlanır:

- **Ön koşullar:** Senaryo çalışmak için neye ihtiyaç duyar?
- **Son koşullar:** Senaryo çalıştığında neyin olmasını garanti eder?
- **Adım adım akış:** Şu yapılır, bu yapılır.
- **Aktörler:** Birinci aktör ve varsa destek aktörleri.

Bunlar yazıldığında senaryo tanımlanmış olur. Bir diyagram hazırlanır ve diyagramdaki bütün senaryolar için ayrı birer doküman oluşturulup bir paket halinde belgelenir. Böylece iş analizi kullanım senaryolarıyla ortaya konmuş olur.

### 8.2 Dört Temel Sembol

Dilin ne kadar basit olduğunu dört temel sembol gösterir:

| Sembol | Çizimi | Anlamı |
| :--- | :--- | :--- |
| Aktör | Çöp adam | Sistemle etkileşen birim |
| Kullanım senaryosu | İçinde adı yazan elips | Bir sorumluluk, bir iş akışı |
| İlişki | Düz çizgi ya da ok | Aktörler ile senaryolar arasındaki bağlantı |
| Sistem sınırı | Kutu (dikdörtgen) | Neyin sistemin içinde, neyin dışında olduğu |

Neden çöp adam? Çünkü çizmesi kolaydır. Bu diyagramlar genellikle kâğıda, beyaz tahtaya, duvara ya da bir çizim aracıyla ekrana çizilir. Sistem sınırı isteğe bağlıdır. Özellikle dış aktörleri ve haberleşilen harici sistemleri göstermek istiyorsanız senaryoları ve varsa ilgili aktörleri bir kutunun içine alırsınız.

### 8.3 Araç Takip Sistemi Örneği

Hoca çok basit bir örnekle başladı. Dikdörtgenle gösterilen sistem bir **araç takip sistemidir**. Sistemin içinde aktör yoktur, iki harici aktör vardır: Operatör bir insandır, GPS sistemi ise başka bir sistemdir. GPS sistemi de aktör olarak modellenir, çünkü onunla etkileşim yaşanır. Demek ki aktör insan olmak zorunda değildir. Hoca modelin bu kadar basit ve soyut olmasının sebebini şöyle açıkladı: Şu anda işi modelliyoruz ve kendimizi teknik ayrıntılardan arındırmaya çalışıyoruz.

Sistemde üç sorumluluk vardır:

- **Report Location (konum raporla):** Araçların konumunu raporlama sorumluluğu. Bunun için harici GPS sistemiyle birlikte çalışılır. Aktör senaryoya bir çizgiyle bağlanır. Ok kullanılırsa bağlantı yönlü olur.
- **Find Arrival Times (varış zamanlarını bul):** Araçların varış zamanını söyleme sorumluluğu. Ayrı bir iş akışı olduğu için ayrı bir elipstir. Örneğin okul servislerinde operatör araçların okula ne zaman varacağını bulabilir.
- **Report Errors (hataları raporla):** Hataların raporlanması. Bunu da operatör yapar.

<!-- BELİRSİZ: 00:44:37'deki anlatımda Report Location senaryosu GPS sistemine bağlanıyor. 00:53:06'daki şablon örneğinde ise "use case 1, report location" için birinci aktör operatör, destek aktörü GPS sistemi deniyor. Diyagramda operatörün Report Location ile bağlantısı olup olmadığı altyazıdan anlaşılmıyor. -->

Varış zamanı için araç konumlarını bilmek gerekiyorsa operatör neden tek başına görünüyor, Find Arrival Times senaryosunun GPS sistemiyle ilişkisi olmayacak mı? Hocanın cevabı: Bu tamamen analiz modeline, problemi nasıl modellediğinize ve problemin doğasına bağlıdır. Zaman çok basit biçimde uzaklık bölü hız olarak hesaplanıyorsa başka bir sistemle haberleşmeye gerek olmayabilir. Google Maps gibi bir servisten hizmet alınacaksa, diyagrama "harita servisi" adlı bir aktör eklenmeli ve bu senaryoya bağlanmalıdır. Aynı problem için diyagram, modellemeye göre farklı çizilebilir.

Özetle kullanım senaryosu diyagramı, sistemi, sorumluluklarını, sistemle etkileşen aktörleri ve bu aktörlerin hangi senaryolarda yer aldığını bir arada gösterir.

### 8.4 Her Senaryoya Bir Doküman

Diyagramdaki her elips bir senaryodur ve kendine ait bir dokümanı olmalıdır. Örnekteki senaryolara use case 1, 2 ve 3 dersek her biri için ayrı bir doküman yazılır. $n$ tane senaryo varsa $n$ tane kullanım senaryosu dokümanı gerekir.

Dokümanlarda iki aktör türü geçer:

- **Birinci aktör (primary actor):** Senaryodan asıl faydayı sağlayan, işlemleri başlatan ve tetikleyen aktördür. Hoca operatörü ve GPS sistemini örnek gösterdi.
- **Destek aktörü:** Akışa bilgi ve destek sağlayan, hizmet veren aktördür.

Senaryo ise anlamlı bir sonuca ulaşmak için aktör ile sistem arasında gerçekleşen olaylar zinciridir, yani adım adım yapılacakların yazıldığı iş akışıdır.

## 9. Senaryo Yazma Kuralları

Senaryo bir ihtiyaç ya da özellik listesi değildir. "Şunun yapılması gerekiyor, bunun olması gerekiyor" diye yazılmaz. Sistem ya da o sorumluluk bir **kara kutu** gibi, içi görülmeyen kapalı bir kutu gibi ele alınır. Sistemin ne gibi sorumluluklara sahip olduğu ve ne hizmet sunduğu aktör ile sistem arasındaki etkileşimler olarak ifade edilir.

> **Hocanın vurgusu:** Senaryolarda mutlaka etken cümle kurmak zorundayız. Edilgen cümle kurarsak işi kimin yaptığı, işin sorumlusu belli olmaz.

Senaryoda nelerin olduğu yazılır, yani "ne yapar?" sorusu cevaplanır. İşlerin nasıl yapılacağı tasarımın problemidir ve senaryolarda bu ayrıntıya yer verilmez. Teknik ayrıntı burada yoktur. Yalnız iş akışı somut ve etken cümlelerle net biçimde ifade edilir.

> **Hocanın vurgusu:** Sistemin bittiğini, bitmiş halinin elimizde olduğunu düşünün ve bu halde oluşabilecek bütün sorumlulukların senaryolarını yazın. "Şöyle bir sorumluluk var ama senaryosunu yazmaya gerek duymadım" olamaz.

Peki nerede duracağız? Hangi sorumluluk benim sistemimin, hangisi dış sistemlerin sorumluluğu ya da hizmet alınması gereken bir iş? Bunun için sistem sınırları doğru belirlenmelidir. Senaryolar yalnız sistem sınırları içindeki sorumluluklar için yazılır. Dışındakiler "başkasının işi, başkasının problemi" diyerek dışarıda bırakılır. Yoksa bu işin sonu gelmez, dünyadaki bütün sorumlulukları üstlenmiş oluruz.

## 10. Kullanım Senaryosu Dokümanının Şablonu

Kurala uygun bir dokümanın içeriği şu sırayı izler. Önce senaryonun kod numarası ve adı yer alır: Örneğin "use case 1, Report Location".

### 10.1 Ön Söz (Preface)

Ön söz, senaryoya bir girizgâhtır. Hoca içeriği örneklerle anlattı:

- **Birinci aktör:** Örneğin operatör.
- **Destek aktörleri, ilgililer ve beklentileri:** Örneğin GPS sistemi araçların koordinat bilgisini verir, ondan beklenti bu hizmeti sunmasıdır.
- **Ön koşul (precondition):** Örneğin hafta içi mesai saatlerinde olmak. Hafta sonu ve mesai dışında izleme yapılması istenmiyordur.
- **Son koşul (postcondition):** Senaryo tamamlandığında sistemde bir değişiklik olacaksa neyin olmasının garanti edildiği yazılır. Örneğin Find Arrival Times senaryosu sonunda okulun bütün öğrenci servislerinin sabah okula varış saatleri bir veri tabanı tablosuna kaydedilir ya da bir rapor oluşturulup bir yere gönderilir.

### 10.2 Ana Başarılı Senaryo

Ön sözden sonra **ana başarılı senaryo** gelir. Bu, senaryonun en doğal çalışma şeklidir ve 1, 2, 3, 4 diye numaralanmış cümlelerle adım adım yazılır. Her cümle etkendir, kimin ne yaptığı açıktır. Adımlar birer buyruk, birer komut gibidir. **Burada koşul yer almaz.** "Eğer şöyleyse şöyle olur, yoksa böyle olur" ifadeleri dallanmadır ve sonra alternatif akış olarak belirtilir.

Adımlarda genelde üç tip iş yapılır:

- Kullanıcı ile sistem etkileşimi ya da kullanıcının sistemi tetiklemesi.
- Onay.
- Durum değişikliği ya da bilgi kaydı.

Hoca bunu **ders kaydı** senaryosuyla örnekledi. Ön koşul, öğrencinin o dersi alabiliyor olmasıdır. Örneğin birinci sınıf öğrencisi dördüncü sınıf dersi almaya çalışınca sistem engeller. Son koşul, dersin alınması ve kaydın yaratılmasıdır. Ana başarılı senaryo şöyledir:

1. Öğrenci almak istediği dersin kodunu sisteme girer.
2. Sistem dersin gününü, saatini ve kredisini gösterir.
3. Öğrenci onay butonuna basar.
4. Sistem ikinci onaydan sonra kaydı gerçekleştirir.

### 10.3 Alternatif Akışlar

Hayat her zaman böyle güllük gülistanlık değildir. Dersin kontenjanı doluysa ne olacak, ön koşulu varsa ne olacak? Bu farklı durumlar **alternatif akış** bölümünde anlatılır. Akış hangi adımdan dallanıyorsa o adımın numarasıyla adlandırılır. Kontenjan durumu, onay butonuna basılan 3. adımdan dallanır:

- **3a.** Sistem kapasiteyi ya da kontenjanı kontrol eder. Kapasite doluysa hata verir ve kaydı gerçekleştirmez.
- **3b.** Sistem kapasiteyi kontrol eder. Kapasite doluysa özel öğrenci kontenjanına bakar (örneğin Erasmus durumu). Özel öğrenciyse kaydı gerçekleştirir.

Dallanma daha da derinleşebilir: 3a1, 3a2, 3b1, 3b2 gibi.

> **Ders sonrası not:** Hoca anlatırken numaraları önce "4A" dedi, sonra "3A" diye düzeltti, 00:59:37'deki genel dallanma örneğinde yine 4A, 4B, 4A1, 4B2 kullandı. Kendi kuralına göre numara dallanılan adımdan gelir. Kontenjan kontrolü 3. adımdan dallandığı için doğrusu 3a ve 3b'dir. 4A gösterimi, 4. adımdan dallanan bir akış için geçerli olur.

Ön söz, ana başarılı senaryo ve alternatif akışlar, bir senaryonun dokümanı için **yeterli başlıklardır**.

### 10.4 İsteğe Bağlı Bölümler

Bundan sonrası isteğe bağlıdır, ama use case'lerde genellikle görülür:

- **Sıra dışı durumlar (exceptions):** Exception handling mekanizması nasıl olacak? Sistem hatayla karşılaştığında kayıt gerçekleşmiş mi sayılacak, geri mi alınacak? Yani transaction processing nasıl olacak? Özellikle açıklanması gerekiyorsa yazılır.
- **Özel istekler:** Kalite kriterleri ve kısıtlarıdır. Örnekler: saniyede 10.000 ders kaydı yapılabilmelidir; iletişimde 256 bit SSL şifreleme kullanılmalıdır; bir login senaryosunda en az üç seviyeden oluşan resim doğrulamalı CAPTCHA yapılmalıdır. Böylece senaryoyu okuyan teknik taraf tasarımdan önce bunları görür ve dikkate alır.
- **Teknolojik beklentiler:** Dil, platform ya da kullanılması gereken kütüphane gibi özel kısıtlar varsa eklenir.

### 10.5 Modül ve Senaryo Farkı

Bu şablondaki doküman, sistemdeki bütün sorumluluklar için yazılmak zorundadır. Bir modülde tek bir sorumluluk olması gerekmez, bir modülün işleri için birden fazla senaryo gerekebilir.

> **Hocanın vurgusu:** "Uygulamamızda 5 modül var, 5 use case yazarız, tamam bitti" dememelisiniz. 5 modüldeki işlevsellik daha fazla sayıda senaryoyla bir araya gelir. Modüller, senaryoların bir arada çalışmasıyla oluşur.

Hoca, çok karmaşık durumlarda senaryoların yeterli olmadığını ve alt parçaların **sözleşme (contract)** denen yapılarla yazılabildiğini söyledi. Bu konunun üzerinde durmadı, geçti.

## 11. Senaryolar Arası İlişkiler

Senaryolar bir arada çalışır ve birbirleriyle etkileşir. Buna senaryolar arası ilişkiler denir. Üç temel tür vardır.

### 11.1 İçerme (Include)

Bir senaryonun çalışması için başka bir senaryonun mutlaka işletilmesi gerekir. Hocanın benzetmesiyle bu, **bir fonksiyon çağırıp geri dönmek gibidir**. İçerilen senaryo çoğu zaman pek çok senaryoda kullanılır. En güzel örnekler login senaryoları ve kimlik doğrulama (authentication) mekanizmalarıdır: Bir access token kontrolü yapılması, kullanıcının doğrulanmış olup olmadığına bakılması gerekir. Örneğin ders kaydından önce öğrencinin login olup olmadığının ve ders kayıt izninin kontrolü ayrı bir senaryodur. Bu senaryo ders kayıt senaryosuna include edilir ve diyagramda gösterilir.

### 11.2 Genişletme (Extend)

Belli bir koşulda ana senaryodan ayrılma noktasından sonra çalışan senaryolardır. Hoca bir hastane bilgi sistemindeki tahlil sonucu alma senaryosunu örnek verdi. Sonuç normalde ekranda okunabilir, ama istenirse basılı olarak adrese mektupla da gönderilebilir. Ana senaryo mutlaka tek başına çalışabilmelidir. İstenirse bu ek parçayla genişletilip daha uzun biçimde de işletilir. Kâğıda basılıp adrese yollanma ayrı bir senaryodur ve tahlil sonucu görme senaryosunu extend eder.

Genişleten senaryo tek başına çalışmaz. Ana senaryoya bağlı olarak onu genişletir.

### 11.3 Genelleştirme (Özelleştirme)

Genel senaryolardan özel senaryolar türetilmesidir. Hoca bunu kalıtıma benzetti, ama "kalıtım değil, genelleştirme demek daha doğru" diye de ekledi. Örneğin bir **ödeme** senaryosu tek başına çalışmaz. Ödeme ya nakit ya kartla ya da çekle yapılır. Her birinin akışı başkadır, bu yüzden her biri ayrı bir özel senaryodur. Ama hepsi nihayetinde ödeme senaryosunun özelleştirilmiş parçaları olarak modellenebilir.

## 12. Hastane Örneği Üzerinde İlişkileri Okumak

Hoca ilişkilerin diyagramda nasıl okunduğunu basit diyagramlarla gösterdi.

### 12.1 Bağıntı (Association)

Aktörler ile senaryolar arasındaki ilişkiye bağıntı (association, relation) denir. Bir aktörün **en az bir** senaryoyla ilişkili olması beklenir. Sistemin yanında başıboş duran bir çöp adam çok saçma olur, çünkü sistemle ilişkisi yok demektir. Buna karşılık bir senaryo birden fazla aktörle ilişkili olabilir.

Hastane bilgi sisteminde **tahlil verme** senaryosu hem laboratuvarla hem hastayla bağıntılıdır. Şekilde hastadan senaryoya bir ok görülüyor. Hocaya göre oklu gösterim gördüğünüzde okun çıktığı aktör birinci aktördür, diğeri destek aktörüdür. Bunlara stakeholder da denir. Tahlil vermenin esas aktörü hastadır.

<!-- BELİRSİZ: 01:07:05-01:07:24 arasında hoca "tahlil verme" senaryosunu anlatırken "tahlil sonucu almayla laboratuvarın herhangi bir ilgisi yok, sadece hasta bununla ilgili" diyor. Hemen önce laboratuvarın tahlil vermeyle bağıntılı olduğunu söylemişti. Hangi senaryonun kastedildiği slaytta doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** Birincil aktörün ilişki okuyla gösterilmesi büyük olasılıkla zorunlu bir UML kuralı değil, bazı kaynakların kullandığı bir gösterimdir. Birincil aktörü kesin olarak belirtmenin yolu, derste anlatılan senaryo dokümanının ön söz bölümüdür.

### 12.2 Genişletme İlişkisi

Bir senaryonun başka senaryolarla ilişkilendirilip ilave işlevlerle genişletilmesi durumunda genişleten senaryoya **extension use case** denir. Hastane örneğinde tahlil verme, "kısa mesaj at" senaryosuyla genişletilebilir. Tahlil sonucu alma da, sonuçlar çıktıysa e-postayla gönderme senaryosuyla genişletilebilir. Duruma göre iki senaryo birlikte, karma bir senaryo gibi çalışır.

### 12.3 Ekleme İlişkisi

Include, bir senaryo içindeki adımların diğer senaryolarda da yer alması durumudur. Sıra numarası almak ya da login olmak gibi ortak işlevler bu ilişkiyle gösterilir. Hastane örneğinde tahlil vermek için mutlaka kan vermek ve sıra numarası almak gerekir. Bunlar kendi içinde adımlardan oluşan ayrı senaryolardır.

### 12.4 Aktörler Arasında Genelleştirme

Genelleştirme yalnız senaryolarda değil, aktörlerde de olabilir. Şekilde tahlil sonucu alma senaryosu laborantla ilişkilidir ve doktor aktörü laboranttan türetilmiştir. Muayene senaryosuyla yalnız doktor etkileşime girer. Ama doktor aynı zamanda bir laborant olduğu için tahlil sonucunu da alabilir. Doktordan bu senaryoya doğrudan ok çizilmemiştir, çünkü türetme bunu sağlar.

Hoca hastanın da laboranttan türetildiğini gördü ve bunu neden böyle gösterdiğini hatırlamadığını söyledi. Okumasını şöyle yaptı: Hasta da bir laboranttır, laborant olduğu için tahlil sonucunu alabilir. Laborant bu modelde sanki soyut (abstract) bir aktör gibi yer alır.

> **Ders sonrası not:** Hoca "hasta da bir laborant" okumasını şekle bakarak yaptı. Genelleştirme derste kalıtım gibi anlatıldığına göre, bu okuma hastanın bir tür laborant olduğunu söyler ve anlam olarak tutarsızdır. Daha tutarlı bir model büyük olasılıkla "tahlil sonucu alan" gibi soyut bir aktör tanımlayıp doktoru ve hastayı ondan türetmek ya da hastayı senaryoya doğrudan bağlamaktır.

## 13. Bankacılık Örneği

Hoca son olarak bir banka sistemi örneğini okudu. Sistem analisti bankaya gitmiş, işlerin nasıl yürüdüğünü incelemiş, bilgi toplamış ve şu sonuca varmıştır. Aşağıdaki İngilizce adlar kısa nottaki slayt karesinden alınmıştır.

**Aktörler:** Banka çalışanı (Bank Employee), müşteri (Customer) ve yabancı müşteri. Yabancı müşteri NRFC'dir (non-resident foreign customer). Hoca bir an "citizen" dedi, sonra "customer" diye düzeltti. NRFC, müşteriden genelleştirme ilişkisiyle türetilmiştir, yani aynı zamanda bir müşteridir.

**Senaryolar ve ilişkiler:**

- **Open Account (hesap açma):** Müşteri ve banka çalışanı birlikte rol alır. Müşteri bir şey yapar, banka çalışanı bir şey yapar, onay verilir ve hesap adım adım açılır.
- **Deposit Funds (para yatırma):** Kendi başına çalışabilir. Tutar 10.000 TL'nin üzerindeyse ya da müşterinin yaşı 55'in üzerindeyse ilave bir bonus hesabı gerekir, örneğin puan verilir. Bu nedenle **Calculate Bonus** senaryosu para yatırmayı **extend** eder.
- **Withdraw Funds (para çekme):** Müşteri hesaptan para çekebilir.
- **Update Balance (bakiye güncelleme):** Para yatırma da çekme de bakiyenin güncellenmesini ve bir yere kaydını gerektirir. Bu nedenle Deposit Funds ve Withdraw Funds bu senaryoyu **include** eder. Ayrı bir iş akışı olduğu için ayrı bir senaryo olarak modellenir.
- **Convert Currency (kur dönüşümü):** Farklı para birimleri arasında dönüşümü yalnız yabancı müşteriler yapabilir.

Genelleştirme sayesinde yabancı müşteriler hesap da açabilir, para da yatırıp çekebilir. Yerli müşteri ise başka para biriminde işlem yapamaz. Hoca "Hocam böyle şey olur mu, biz dolarla işlem yapıyoruz" itirazını önceden karşıladı: Türkiye'de elbette yapılabilir, ama bu örnekteki banka böyle çalışıyor ve model buna göre kurulmuştur. Gerçek bir bankada çok daha fazla senaryo gerekebilir, bu basit bir örnektir.

> **Ek bilgi (derste anlatılmadı):** Kısa nottaki slayt tarifine göre ok Calculate Bonus'tan Deposit Funds'a, Deposit Funds'tan da Update Balance'a doğrudur. UML gösteriminde büyük olasılıkla extend oku genişleten senaryodan genişletilene, include oku ise içeren senaryodan içerilene doğru çizilir. Yani iki okun yönü aynı mantığı izlemez, bu yüzden okurken karıştırmamak gerekir.

### 13.1 Kaç Doküman Gerekir?

Sayım şöyledir:

- Temel işler, başka bir deyişle modüller: hesap açma, para yatırma, para çekme, kur dönüşümü. Toplam 4.
- İlave sorumluluklar: bonus hesaplama ve bakiye güncelleme. Toplam 2.
- Senaryo sayısı: $4 + 2 = 6$.
- Aktör sayısı: 3. Bunlardan biri genelleştirme ilişkisiyle bağlıdır.

> **Hocanın vurgusu:** İş analizini tamamlamak için bu diyagramı çizmek yeterli değildir. Bir diyagram ve 6 kullanım senaryosu dokümanı gerekir. Her dokümanda aktörler, ön ve son koşullar, ana akış, varsa alternatif akışlar, teknolojik beklentiler ve sıra dışı durumlar yer alır.

### 13.2 Teknik Tarafa Geçiş

Özetle iş analizinde müşteriyle çalışılır, mevcut sistem ortaya konur, yeni sistemden beklentiler ve sorumluluklar belirlenip nasıl yapılacakları yazılır. Aktörler ve ilişkiler kullanım senaryosu diyagramıyla gösterilir, bütün senaryolar için akışları içeren dokümanlar hazırlanır ve bunlar bir rapor olarak üretilir. Bu çalışma alanını hiç bilmeyen bir yazılım personeli, bu dokümanları ve sonrasında geliştirilecek analiz modellerini okuyarak tasarımı oluşturmaya başlayabilir: "Bunları şöyle modelleyelim, bu sorumlulukları böyle yerine getirelim."

## 14. Araştırma ve Bilgi Toplama Yöntemleri

Use case'leri yazabilmek için önce işlerin neler olduğunu öğrenmek, bilgiyi çalışan taraflardan ya da mevcut durumdan almak gerekir. Bunun yolu yordamına **araştırma ve bilgi toplama yöntemleri** denir. Bu önemlidir, çünkü mevcut sistemin ya da problemin eksik veya yanlış anlaşılmaması ancak doğru ve düzgün bilgi toplamakla sağlanır.

Üç temel yöntem vardır:

- **Gözlem yöntemi:** İş ortamının gözlenmesi ve mevcut belge, form ve dosyaların örneklenmesi.
- **Kişisel görüşme yöntemi:** Yapılandırılmamış ve yapılandırılmış görüşmeler.
- **Anket yöntemi:** Bilgi toplanmak istenen hedef kitleye anket uygulanması.

Hoca birinci yönteme şakayla "gözleme yaklaşımı" adını verdi: Öğle saatlerinde akla peynirli, patatesli gözleme geliyor.

## 15. Gözlem Yöntemi

Sistem analisti müşterinin ortamına gider. Bu bir birim olabilir: muhasebe, stok, üretim, depo, insan kaynakları gibi. Bilgi sistemi işletmenin geneli içinse bütün birimlere ayrı ayrı gidilir. Hoca sahneyi şöyle canlandırdı: Patron çalışanlara "Yeni sistemi kuracak ekipten bu arkadaş önce işlerin nasıl olduğunu görüp anlayacak, ona gereken kolaylığı sağlayalım" der, bir de çay söyler. Siz de oturur, ortamı gözlersiniz.

Gözlemde iki şey yapılır:

**Belge ve formların örneklenmesi:** Çalışanlar kâğıt ya da form dolduruyor, bir şeyler raporluyor ya da dosyalıyorsa bunlardan örnek, yani kopya alınır. Her belgenin ne işe yaradığı sorulur. Bir çalışan şöyle diyebilir: "Bunu falan kişiye veriyoruz, o da kilolarına ve boyutlarına göre sıralayıp hangi sırayla arabaya yükleneceğine karar veriyor."

**İş ortamının gözlenmesi:** Kim nasıl çalışıyor, neler yapıyor, ne gibi sorumlulukları yerine getiriyor? Örneğin siparişlerin adreslerini ürünlerin üzerine yapıştırıp dağıtım birimine teslim etmek bir sorumluluktur. Üretim süreçleri de izlenebilir. Mevcut bir sistem varsa nasıl kullanıldığına bakılır: Neresine tıklıyorlar, hangi ekranı açıyorlar, ne giriyorlar, ne çıkıyor, nereye yolluyorlar? Sistem hangi işlemlerin sonucunda ne gibi çıktılar üretiyor?

Gözlem belli bir süre yapılır: bir gün, bir hafta, iki hafta, belki bir ay. Süre işin karmaşıklığına, derinliğine ve boyutuna göre değişir. Bu gözlemler sonunda problemin ne olduğu, eksik noktalar ve işin hangi senaryolarla işlemesi gerektiği anlaşılır ve bir use case modellemesi haline getirilir.

## 16. Kişisel Görüşme Yöntemi

Tek başına gözleyerek anlayamadığınız ayrıntılar olabilir. Bu durumda insanlarla etkileşime geçilir. Toplantı, mülakat ya da çok daha büyük ölçekte, daha geniş katılımlı ortak gereksinim planlama seminerleri yapılabilir. Yöntemin özü, kullanıcılarla ya da mevcut sistemin taraflarıyla karşılıklı görüşüp sorular sorarak işin ne olduğunu ortaya çıkarmaktır.

### 16.1 Görüşme Kuralları

- **Randevu ve hazırlık:** Her tür görüşmede randevu almak ve hazırlıklı olmak esastır.
- **Başlangıç konuşması:** Konuyu sistem analisti açar. Toplantı niye yapılıyor, hangi bilgiler alınmak isteniyor, neyin açıklığa kavuşturulması gerekiyor?
- **Belli konular:** Konular çok ayrıntılı olmayabilir, yalnız bir alan bile olabilir. Ama mutlaka belli olmalıdır. Bu bir kahve muhabbeti değil, bilgi edinme görüşmesidir.
- **Not alma:** Görüşme süresince not alınır.
- **Hitap ve duruş:** Bacak bacak üstüne atıp kaykılarak ya da "abi niye öyle oldu" diye konuşulmaz. Sistem analisti düzgün bir dille iletişim kurar.
- **Çıkış notu:** Sonunda neler konuşuldu, başlıca noktalar neydi, neler konuşulmadı, neler konuşulacak ve bunlar nasıl planlanacak, bunları içeren bir toplantı sonu tutanağı hazırlamakta fayda vardır.

### 16.2 Yapılandırılmış ve Yapılandırılmamış Görüşme

**Yapılandırılmış görüşmede** amaçlar önceden saptanmıştır. Kimlerle görüşüleceği, ne konuşulacağı, zamanı ve yeri bellidir. Toplantının amacı, tahmini süresi ve gerekli dokümanlar önceden bildirilir, herkes hazır gelir. Sorular bellidir. Görüşmeden sonra en kısa zamanda sonuçlar değerlendirilir, yorumlanır, toplantı tutanağı haline getirilir ve bütün katılımcılara, gerekiyorsa yönetim kademesine dağıtılır.

**Yapılandırılmamış görüşmede** kullanıcıların ya da mevcut sistem sahiplerinin ne yaptığı, nerede zorlandığı, beklentileri ve "ne olsa daha iyi olur" soruları daha rahat, daha ucu açık biçimde konuşulur. Örneğin bir çalışan şöyle diyebilir: "Biz bunları elle giriyoruz ama zaten başka yerde kayıtları var, keşke oradan çekilebilse, biz yalnız kontrol edip onay versek."

Hoca iki türü slayttaki tabloyla karşılaştırdı. Tablo kısa nottaki slayt karesinden alınmıştır.

| Ölçüt | Yapılandırılmamış | Yapılandırılmış |
| :--- | :---: | :---: |
| Değerlendirme | Zor | Kolay |
| Harcanan zaman | Çok | Az |
| Eğitim | Sınırsız | Sınırlı |
| Kendiliğinden oluşma | Fazla | Az |
| Cevaplayanın kendi görüşünü ortaya koyması | Çok fazla | Çok az |
| Esneklik | Çok | Az |
| Görüşmecinin kontrol etmesi | Az | Fazla |
| Doğruluk | Az | Fazla |
| Güvenilirlik | Az | Fazla |
| Genişlik ve derinlik | Fazla | Az |

Hocanın gerekçeleri şöyledir:

- **Değerlendirme:** Yapılandırılmış görüşmede her şey belli olduğu için değerlendirmesi kolaydır. Yapılandırılmamış görüşme geniş ve rahat olduğu için değerlendirmesi zordur.
- **Zaman:** Yapılandırılmış görüşme önceden çalışıldığı için toplantıda daha az zaman alır. Yapılandırılmamışta laf lafı açar, daha çok zaman harcanır.
- **Eğitim:** Yapılandırılmışta eğitim ihtiyacı sınırlıdır. Diğerinde sürekli eğitim ihtiyacı vardır.
- **Kendiliğinden gelişme:** Yapılandırılmışta çok kısıtlıdır. Yapılandırılmamışta "aklıma şu geldi, şu da olsa" gibi yeni istek ve fikirler kendiliğinden doğabilir.
- **Kontrol:** Yapılandırılmış görüşmede bütün ipler görüşmecinin elindedir, çünkü önceden hazırlanmıştır. Hoca slaytta "anketör" yazmasının yanlış olduğunu, görüşmeyi yapan kişinin kastedildiğini söyledi.
- **Doğruluk ve güvenilirlik:** Yapılandırılmış olduğu için fazladır.
- **Genişlik ve derinlik:** Yapılandırılmamışta laf lafı açar ve konu geniş bir skalaya yayılır. Yapılandırılmışta sınırlar belli olduğu için azdır.

> **Ders sonrası not:** Altyazıda iki satır karışık geçiyor. 01:27:57'de "Eğitim ihtiyacı yapılandırılmışta sınırlıdır, yapılandırılmışta sınırsızdır" denmiş; kısa nottaki slayt tablosuna göre sınırsız olan yapılandırılmamış görüşmedir. 01:29:10'da "genişlik ve derinlik yapılandırılmış görüşmede fazlayken ... oldukça azdır" denmiş; hocanın "sınırları belli olduğu için" gerekçesine göre doğrusu, yapılandırılmamışta fazla, yapılandırılmışta az olmasıdır.

### 16.3 Soruların Sıralanması

Görüşürken sorular nasıl sıralanır? İki yaklaşım vardır.

**Tümevarım** yaklaşımı piramit yapısı gibi düşünülebilir. Cevapları belli, evet-hayır ya da "şu orandadır" türünden ayrıntılı, kapalı uçlu sorulardan başlanır. "Siz ne düşünüyor, ne bekliyorsunuz?" gibi yoruma açık sorulara doğru gidilir. Bu yaklaşım mülakat veren kişiyi konuya ısındırmak için tercih edilebilir.

**Tümdengelim** yaklaşımı bunun tersidir. Açık uçlu sorularla başlanır, kapalı sorulara doğru gidilir. "Ne düşünüyorsunuz?" diye başladığı için mülakat daha kolay başlar, sonra daralır. Mülakat veren kişi konu hakkında istekliyse ve fikirlerini serbestçe ifade ediyorsa bu yaklaşım daha doğrudur.

> **Ek bilgi (derste anlatılmadı):** Tümdengelim yaklaşımına büyük olasılıkla, açıktan dara inen biçimi nedeniyle kaynaklarda "huni" yapısı da denir. Hoca derste yalnız tümevarım için "piramit" benzetmesini kullandı.

## 17. Anket Yöntemi

Birinci yöntemde izleyerek, ikincisinde konuşarak bilgi topladık. Üçüncü yöntem ankettir.

### 17.1 Anket Ne Zaman Kullanılır?

Müşteri belliyse gözlem ve görüşme daha doğru yöntemlerdir. Müşteri kendi organizasyonunuzda başka bir birim ya da dış müşteri olabilir, ama nihayetinde bellidir ve beklentisi de bellidir.

Hocanın karşı örneği bir mobil oyundur. Oyunun tutup tutmayacağını, hedef kitlenin beklentilerine uyup uymadığını belirlemeye çalışıyorsunuz. Burada gözlem ya da görüşme yapmak saçma olur. Son kullanıcıya, pazara yönelik bir çözüm oluşturmak istiyorsanız anket yöntemi daha doğru bir yaklaşımdır.

### 17.2 İyi Anket Hazırlamanın Kuralları

Anket, soru ve cevap alanlarından oluşan bir formdur. Kurallar şunlardır:

- **Açıklık:** Sorular tam, eksiksiz ve açık olmalıdır.
- **Hatırlatma:** Bilgi istenen olaydan uzun zaman geçtiyse cevaplayan ayrıntıları unutmuş olabilir. Hatırlatma gerekebilir.
- **Cevap arzusu oluşturma:** Özel yaşamla ilgisiz, cevaplaması kolay ve ilgi çekici sorular hazırlanmalıdır. Hocaya göre bunu yapmak oldukça zordur.
- **Hatalı cevabı engelleme:** Çoktan seçmeli eleme soruları kullanılabilir. 3-5 soru sonra daha önce sorulan bir şey yeniden sorularak kontrol sorusu konabilir.
- **Görsel destek:** Cevaplar görsel öğelerle desteklenebilir, bu ifadeyi kolaylaştırır.
- **Şartlandırmama:** Cevaplayan düşüncesini özgürce aktarabilmelidir. "Sizce de çok iyi değil mi?" ya da "Menülerde şöyle bir yapı olması sizce de çok kötü değil mi?" gibi sorular sorulmaz.

**Kötü anket örneği:** Hoca, kısa süre önce eline geçen bir anketi anlattı. Anketin girişinde bilgilerin gizli tutulacağı ve kişisel hiçbir şeyi yansıtmayacak biçimde işleneceği, yani anonim veri toplandığı yazıyordu. Formu açınca ilk soru e-posta adresi, ikinci soru çalışılan üniversite ve bölüm, üçüncü soru unvandı. Hoca, o e-postaya sahip tek bir kişi olduğunu ve bu soruyla anonimliğin kalmadığını söyledi. Anketi kapatıp çıktı, yani cevaplamadı. Bu kötü bir anket tasarımıdır.

> **Hocanın vurgusu:** Ankette soru hazırlamak gerçekten zor bir iştir. Kişinin kim olduğunu kesinlikle fark etmeden bilgi toplamanız önemlidir.

### 17.3 Anketin Avantajları ve Dezavantajları

**Avantajlar:**

- Çok sayıda kişiden veri toplanabilir.
- Hızlıdır ve maliyeti düşüktür.
- Kimlikler gizli kaldığı için katılanlar düşüncelerini rahatça aktarabilir. Hoca, verdiği örnekte böyle olmadığını da hatırlattı.
- Analiz, özellikle dijital ortamda hızlı yapılabilir.

**Dezavantajlar:**

- Katılımı sağlamak zordur, beklenenden az kişi cevap verebilir.
- Herkes bütün soruları düzgün cevaplamayabilir. Kontrol sorularıyla bu test edilebilir: İlk soruda "ak", kontrol sorusunda "kara" diyen biri okumadan cevaplamıştır, sonuçları değerlendirmeye alınmaz.
- Gönüllü bilgi verme kısıtlıdır, insanlar ankette çok özel şeyler aktarmak istemez. Esnekliği azdır. Birebir görüşmede, özellikle de yapılandırılmamış görüşmede çok daha fazla bilgi toplanabilir.
- Kişinin vücut dili analiz edilemez.
- Muğlak ifadelerle sorulan soruya muğlak cevap gelir.

### 17.4 Açık Uçlu ve Kapalı Uçlu Sorular

**Açık uçlu sorularda** cevaplayan yanıtı kendi ifadeleriyle oluşturur: "Beklentileriniz nelerdir?" Esnektir, hazır cevaplarla alınamayacak ayrıntılar alınır, gerçek görüş daha iyi anlaşılır, gerçek duygular daha kolay ifade edilir. Ama kimse uzun uzun yazmak istemez, zaman alıcı ve yorucudur. "Evet evet, çok güzel" deyip eksik ya da yanlış cevap verilebilir. Anketi düzenleyen için cevapları okumak, işlemek ve analiz etmek zordur, daha çok zaman ister. Cevaplayanın eğitim seviyesi cevabın kalitesini ve kapsamını doğrudan etkiler. Bu yüzden açık uçlu soruları biraz kısıtlamakta fayda vardır. Örneğin "en iyi ve en kötü üç taneyi sıralayın" denebilir, bu sonra daha kolay işlenir.

**Kapalı uçlu sorularda** sabit bir cevap kümesi vardır. Çoktan seçmeli, çoktan çok seçmeli ya da sıralama olabilir: "Birden 5'e kadar sıralayın, en önemlisine 1 verin." Cevaplar çok kolay ve hızlı okunur, kodlanır ve işlenir. Kullanıcıyı kısıtlı cevaba yönelttiği için bu bir avantaj da olabilir. Herkese aynı soruyu aynı bakış açısıyla iletir, açık uçlu sorudaki yorum etkisini devre dışı bırakır. Şıkları göstermek hatırlamayı da kolaylaştırır. Örneğin eğitim seviyesi sorulduğunda herkes farklı bir şey yazabilir. Ama okur yazar değil, okur yazar, ilkokul, ortaokul, lise, lise terk, üniversite, üniversite terk, iki yıllık, dört yıllık, yüksek lisans, doktora, doktora devam ediyor gibi net bir dağılım verilirse kişi kendine en uygun olanı hemen işaretler.

Dezavantajları da vardır:

- Bütün seçenekleri düzgün hazırlayamamış olabilirsiniz. Cevaplayan vermek istediği cevabı şıklar arasında bulamayabilir.
- İnce ve önemli farklar kaybolabilir.
- Kişinin cevabı yoksa ama cevap vermek zorundaysa "birinciye tıklayıp geçeyim" diye doldurma cevap verebilir.
- Bütün sorular kapalı uçluysa "kendi görüşümü iki satır yazamadım" diyerek engellenmiş hissedebilir.

Sonuç olarak ankette açık ve kapalı uçlu sorular **dengeli** kullanılmalıdır. Hoca slayttaki karşılaştırmadan yalnız bir kısmını okudu: Tamamlama hızı açık uçlu soruda yavaş, kapalı uçlu soruda hızlıdır.

<!-- BELİRSİZ: 01:40:46'da "Araştırma yapısı yüksektir, kapalı uçlu, alçaktır. Burada çok fazla kişisel veri toplayabiliyoruz" deniyor. Slayttaki ölçüt adı ve kişisel veri cümlesinin hangi soru türüne ait olduğu altyazıdan net değil. Tablonun geri kalanı okunmadı. -->

### 17.5 Soruların Sıralanması

Görüşmede olduğu gibi ankette de sorular genelden özele ya da özelden genele sıralanabilir. Genelden özele gitmek ve basit sorulardan zor sorulara ilerlemek tercih edilir. Kişi doğrudan zor sorularla karşılaşırsa "Ne uğraşacağım" deyip kapatıp çıkabilir. Hazırlayıcı ve giderek zorlaşan sorularla cevaplayanın ilgisi ve işbirliği sağlanabilir.

Sorular bir mantık sırasıyla birbirini izlemeli, önceki sorular sonrakilere hazırlık yapmalıdır. Ani konu değişiklikleri ve daldan dala atlamalar düzenli bir ankette olmamalıdır. Farklı konular varsa ayrı bölümler halinde kurgulanmalıdır. Bunları hazırlamak deneyim gerektirir. Bazen dış anket firmalarından bile destek alınabilir.

## 18. İş Analizinin Çıktısı: BRD ve Araştırma Raporu

Bu yöntemlerle bilgi toplanıp use case modellemesi dokümanlarıyla birlikte üretildikten sonra bir **iş gereksinimleri dokümanı (business requirements document, BRD)** oluşturulması beklenir. BRD, iş analizi çıktısının üretildiği rapordur. İçeriği şöyledir:

- Özet.
- Raporun ve sistemin amacı ve hedefi.
- Bu sisteme neden ihtiyaç olduğu.
- Sistemin sınırları, yani çalışmanın kapsamı.
- Fizibiliteden gelen ekonomik ve mali analiz.
- İşlevsel gereksinimler, yani kullanım senaryoları: Hem diyagram hem senaryolar.
- Kaynak ihtiyacı.
- İş-zaman planı.
- Maliyet-fayda analizi, yani fizibilite raporu.

> **Hocanın vurgusu:** İnternette "business requirements document" ya da "BRD" diye aratıp örneklerine mutlaka bakın.

### 18.1 Araştırma Raporu Alternatifi

Başka bir biçim isteyenler için **araştırma raporu** formatı vardır. Bu, bilgi toplama sonuçlarının teknik bir raporla ifade edilmesidir. Yapısı şöyledir:

- Başlık ve içindekiler.
- Amaç.
- Metodoloji. Alt başlıkları yöntem, işlem, analiz ve yorumdur.
- Sonuç ve öneriler.
- Toplanan bilgilerle ilgili ekler: formlar, tablolar, grafikler.

Bu teknik raporla birlikte üst düzey yöneticiler için bir **yönetici özeti (executive summary)** yazılması da beklenir. Zamanı kıymetli yöneticiler koca rapor yerine özetini okumayı tercih eder. Burada amaç, yöntem ve sonuçlar çok daha kısa biçimde tartışılır.

Bizim için önemli olan ise iş gereksinimlerinin ortaya konmasıdır, yani BRD'nin oluşturulmasıdır. Gereksinimler üst seviyede de verilebilir, ama daha da iyisi use case'ler halinde vermektir. Doküman bu içerikle hazırlandığında analizin ilk safhası olan iş analizi kuralına uygun tamamlanmış, problem uzayı ve sorumluluklar düzgün biçimde ifade edilmiş olur.

## Dersin Toparlaması

Bu derste sistem analizinin ilk adımı olan iş analizi işlendi. Gereksinim analizi, fizibiliteden sonra gelen üçüncü safhadır ve iş analizi ile işlevsel çözümlemeden oluşur. Analist önce mevcut durumun fotoğrafını çeker, sonra müşteriyle birlikte, müşteri ne istediğini biliyorsa iş akışlarıyla, bilmiyorsa prototiple gereksinimleri belirler. Bunu yaparken yönetimin stratejik uyum, mali fayda ve raporlama kalitesi gibi ölçütlerle inceleme yapacağını göz önünde tutar. Gereksinimleri ifade etmenin güçlü aracı kullanım senaryosu modellemesidir: Bir diyagram ve her senaryo için ana başarılı akışı, alternatif akışları, ön ve son koşulları etken cümlelerle yazılmış bir doküman. Senaryolar birbirine include, extend ve genelleştirme ilişkileriyle bağlanır. Bilgi ise gözlem, kişisel görüşme ve anketle toplanır, sonuçlar BRD olarak raporlanır.

Gelecek hafta sistem analizinin ikinci adımı olan fonksiyonel çözümleme ele alınacak. Bu çözümlemenin sonucunda bir SRS dokümanının nasıl oluşturulduğu ve neleri içerdiği tartışılacak. Ayrıca özellikle nesneye dayalı geliştirmede, senaryolardan yola çıkarak bir kavramsal modelin, yani analiz uzayı modelinin nasıl kurulduğuna bakılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
