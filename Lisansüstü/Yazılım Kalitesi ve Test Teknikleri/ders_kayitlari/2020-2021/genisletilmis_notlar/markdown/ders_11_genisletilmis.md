# Ders 11 Genişletilmiş Notu: Öğrenci Makale Sunumları: Test Aracıları, Yazılım Hata Tahmini, GUI Test Otomasyonu ve Metamorfik Test

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Test Aracıları: Regresyon Testine Dağıtık Bir Yaklaşım
- 3. Yazılım Hata Tahmininde Kalıtımın Etkinliği
- 4. GUI Testleri için Otomatik Test Scripti Üretimi
- 5. Makine Öğrenmesiyle Yazılım Hata Tahmini: Sistematik İncelemeler
- 6. Metamorfik Test
- Dersin Toparlaması

## 1. Dersin Yapısı

Bu ders tümüyle öğrenci makale sunumlarına ayrıldı. Beş öğrenci, yazılım kalitesi ve test teknikleri alanından seçtikleri makaleleri anlattı. Sunumların ortak noktası, büyüyen yazılımlarda testin maliyetini ve hata kaçırma riskini azaltmaya yönelik yaklaşımlardı: regresyon testini akıllı aracılarla yönetmek, hataları metriklerden önceden tahmin etmek, GUI testlerini otomatikleştirmek ve test oracle problemini metamorfik ilişkilerle hafifletmek. Hoca sunumlar arasında kısa değerlendirmeler yaptı.

## 2. Test Aracıları: Regresyon Testine Dağıtık Bir Yaklaşım

İlk sunum, 2019 tarihli bir IEEE konferans bildirisine (başlığı altyazıda "The Next Generation of Test Cases" olarak geçiyor) ve bununla ilgili birkaç çalışmaya dayanıyordu. Sunumun akışı regresyon testi, yazılım aracıları ve test aracıları şeklindeydi; yazılım aracıları test aracılarının temeli kabul edildiği için önce onlar anlatıldı.

### 2.1 Sorun: Büyüyen Yazılımda Regresyon Testi

Teknoloji geliştikçe ve yazılımların boyutu büyüdükçe test aşamalarında bağımlılıklar artar ve yazılım testi zorlaşır (ekrandan, 00:10:00). Belirli bir hata düzeltmesinin (bug fix) ya da yeni eklenen bir özelliğin testini yapmak görece kolaydır, çünkü kapsam bellidir: SRS belgesinde yazan kapsam ya da daha önce bulunmuş bir hatanın yeniden testi. Asıl kritik olan regresyon testi kapsamıdır. Bu kapsam ister otomatik ister elle koşulsun, her seferinde yeniden yapılandırılması (konfigüre edilmesi) gerekir; yazılım büyüdükçe bu iş karmaşıklaşır.

Regresyon testinin tanımı şöyle verildi: Yazılım üzerinde yapılan herhangi bir değişiklikten sonra, bu değişikliğin yazılımın diğer alanlarını etkilemediğini doğrulamak için yapılan test tipidir. Değişiklik ya da düzeltmenin başka yerlerde yol açabileceği hataları bulmak için yazılımın değiştirilmeyen tarafları test edilir. Öncelikli amaç, yazılımın kritik alanlarının hâlâ beklendiği gibi çalıştığını görmektir. Test uzmanları işlevlerin kritikliğine göre bir regresyon kapsamı oluşturur, scriptleri yazar ve bunlar otomatik koşulur.

Bu düzende görülen sorunlar:

- İnsan merkezli karar ağırlığı nedeniyle test senaryolarının maliyetli planlanması.
- Kötü önceliklendirilmiş test paketleri: Sonraki adımda koşması gereken bir test case'in önce koşması hem hatalı hem maliyetli bir planlamadır.
- Yapılandırma yapılsa bile arada gözden kaçan test senaryoları. Sunucu, sektörde kaçırılan hataların çoğunlukla yeni özellik testlerinden değil regresyon kapsamından çıktığını gözlemlediğini, literatürde de durumun benzer olduğunu söyledi.

Slaytta otomasyon testleri şöyle tanımlandı (ekrandan, 00:15:00): Otomasyon testleri, uygun maliyetli ve otomatikleştirilmiş bir şekilde sistem güvenilirliğine olan güvenin tasarlanması, sürekli yürütülmesi ve sürdürülmesi sürecidir. Farklı test gereksinimlerini ve etki alanı ihtiyaçlarını karşılayan senaryolar test uzmanlarınca oluşturulur ve tekrar tekrar otomatik çalıştırılır. Geleneksel regresyon testi seçim mekanizmaları genel test paketi optimizasyonuna ulaşmaya çalışır; ancak çalışma anında yanıt verme, esneklik, sağlamlık ve yeniden yapılandırılabilirlik için tasarlanmamışlardır, karmaşıklığa ve değişikliklere yetersiz ve esnek olmayan tepki verirler. Örneğin otomasyon sistemi her koşuda aynı çıktıyı bekler; loglardan ya da test raporlarından anlık bilgi toplayıp buna uyum sağlayamaz.

Sunucu bunu bir sektör deneyimiyle örnekledi: Mobil servis testlerinde, zaten oturum açılmış bir cihaz üzerinde koşacak testlerin önüne bir oturum açma testi konmuş, bu ilk testteki yanlış bir yapılandırma yüzünden gece boyunca bütün test senaryoları başarısız olmuş ve testler bir gece daha beklemek zorunda kalmıştı. Merkezî mekanizmaların yürütme sırasında toplanan bilgilere uyum sağlayamaması, verimsiz ve maliyetli test planlamasına yol açar.

### 2.2 Yazılım Aracıları

Yazılım aracıları kişiselleştirilmiş bilgi yönetimi, e-ticaret, kullanıcı arayüzü tasarımı, bilgisayar oyunları ve karmaşık endüstriyel süreç yönetimi gibi pek çok alanda kullanılan bir disiplindir. Sunumda iki tanım aktarıldı: 1994'te Ted Selker'e göre yazılım aracıları "başka birinin sizin için yapabileceği bir şeyi yaparak insan ilişkisini taklit eden bilgisayar programları"dır; 1995'te başka bir araştırmacı ise aracıyı "görevlerin devredilebileceği bir yazılım varlığı" olarak tanımlamıştır. <!-- BELİRSİZ: 1995 tanımının sahibinin adı altyazıda "Peter Yanka" olarak geçiyor, doğrulanamadı. -->

Yazılım aracılarının ortak özellikleri slaytta şöyle sıralandı (ekrandan, 00:20:00):

- **Özerklik:** Aracılar problem çözme görevlerinin çoğunu insanların ya da diğer aracıların doğrudan müdahalesi olmadan gerçekleştirebilmeli, kendi eylemleri ve iç durumları üzerinde bir dereceye kadar kontrole sahip olmalıdır.
- **Sosyal yetenek:** Uygun gördüklerinde diğer aracılar ve insanlarla, kendi problem çözme süreçlerini tamamlamak ve başkalarına yardım etmek için etkileşime girebilmelidir. Yani hem yardım alabilir hem yardım verebilirler.
- **Duyarlılık:** Çevrelerini (fiziksel dünya, bir kullanıcı, bir aracı topluluğu, internet vb.) algılamalı ve içinde olan değişikliklere zamanında yanıt vermelidir; örneğin bir kullanıcının yaptığı işlemi algılamak.
- **Proaktivite:** Yalnızca çevreye tepki olarak hareket etmemeli; fırsatçı, hedefe yönelik davranış gösterebilmeli ve uygun yerde inisiyatif alabilmelidir.

### 2.3 Test Aracıları

Test aracıları test etkinliğini ve verimliliğini artırmayı, dolayısıyla kaliteyi yükseltmeyi amaçlar. Sunucu bunu derste görülen kalite hedefleriyle bağladı: Projelerde önceden belirlenmiş metrikler (örneğin geliştirmeden kaçan hata sayısı, kaçacak kritik hata sayısı) vardır; test süreci ne kadar etkin olursa bu hedeflere o kadar yaklaşılır.

Test aracıları, kendi kendini yönetebilen ve uyarlanabilir eylemler yapabilen test case'ler geliştirerek regresyon testi üzerindeki kontrolün tek merkezden yürütülmesini önlemeyi hedefler. Test sırasında sürekli uyum sağlamalı, loglardan ve test raporlarından bilgi toplayıp işleyebilmelidirler. Makalede benimsenen tanıma göre aracılar; algılayabilen, yanıt verebilen, inisiyatif alabilen, kendi hedeflerini seçebilen ve uygun gördüklerinde başkalarıyla etkileşime girebilen, bir yürütme ortamında çalışan yazılım sistemleridir.

Geleneksel yaklaşımda regresyon testi genellikle sürekli entegrasyon sürecine bağlanır ve sistemin yürütülmesinden sonra elde edilen bilgilere göre hangi test durumlarının pakete gireceği belirlenir. Test senaryosu birkaç bileşenden (girdiler, çıktılar, beklenen sonuçlar) oluşan statik bir varlıktır ve tam olarak hangi değerin bekleneceğini bilen bir scriptte somutlaştırılır. Bu statik yapı nedeniyle oldukça karmaşık ve merkezî bir test planlama tekniği gerekir.

Makalenin vizyonu slaytta şöyle ifade edildi (ekrandan, 00:25:00): Test aracılarının kullanımına yönelik genel vizyon, sürekli test seçiminin, önceliklendirmenin ve zamanlamanın büyük bir kısmını merkezî bir regresyon testi otomasyon çerçevesinden, test aracılarının nasıl ve neyi yürüteceklerine kendi başlarına karar verebilecekleri daha düşük bir soyutlama seviyesine kaydırmaktır. Eski düzende tek bir regresyon test sistemi mühendislerin yazdığı test case'leri belirli zamanlarda belirli kararlarla çalıştırır; önerilen dağıtık düzende ise her test aracısı kendi zamanlamasına ve kararına sahiptir ve aracılar birbirleriyle ilişki kurar. Böylece testler hedeflerin özgün kapsamının ötesine geçebilir, hedefler ya da yazılım güncellendiğinde aracılar uyum sağlar. Aracılar tamamen insan kontrolünden çıkmış değildir.

**Uyarlanabilir özerklik**, aracının koşullara göre özerklik düzeyini değiştirebilmesidir ve iki boyutta tanımlanır:

- **Kendi kendine yeterlilik:** Bir görevi dışarıdan yardım almadan yerine getirebilme.
- **Kendi kendine yönelim:** Aracının kendi hedeflerine karar verebilmesi.

### 2.4 Önceki Aracı Tabanlı Test Çalışmaları

Aracılar testin farklı yönlerini otomatikleştirmek için daha önce de kullanılmıştır:

- Uyarlanabilir test yönetim sistemi (ATMS), test aracıları ve bulanık (fuzzy) mantık kullanarak her test turunda yürütülecek uygun test senaryosu setini seçmeyi amaçlamıştır.
- Bir çalışmada farklı aracı türleri (dağıtıcı aracı, test tekniği aracısı vb.) kullanılmıştır. <!-- BELİRSİZ: Bu çalışmanın adı ve üçüncü aracı türü altyazıda anlaşılmıyor. -->
- BDI (Belief-Desire-Intention) modeli koordinatör ve runner aracılarını ayırmak için kullanılmıştır: Koordinatörler test planı oluşturur, runner'lar testleri yürütüp sonuçları koordinatörlere geri gönderir.
- Bu öneriye kadarki en kapsamlı çalışma, dört tür aracıyla (gereksinim, oluşturma, yürütme ve raporlama aracıları) bütün test yaşam döngüsünü otomatikleştirmiştir.

### 2.5 Bir Test Aracısı Modeli

Makalede önerilen test aracısı modelinin durumları ve geçişleri slaytta bir durum diyagramıyla verildi (ekrandan, 00:30:00). Diyagramdaki geçişler metne şöyle aktarılabilir:

```text
Entry -> Idle
Idle <-> Execute
Idle <-> Interact
Execute <-> Interact
Idle -> Out of Order
Execute -> Out of Order
Interact -> Out of Order
Out of Order <-> Regenerate
Regenerate -> Idle
```

- **Idle:** Aracı hiçbir şeye bağlı değildir; gerektiğinde kendi görevini yürütecektir.
- **Execute:** Görev oluşturulduğunda ya da aracı başka bir aracıdan görev aldığında bu duruma geçer; yürütmeden önce ve sonra başka bir aracıdan yardıma ihtiyacı olup olmadığına karar verir.
- **Interact:** Başka bir aracıdan talep geldiğinde bu duruma geçer ve isteği kabul edip yardım edip etmeyeceğine kendisi karar verir.
- **Out of Order:** Aracı ilk amacına hizmet edemeyeceğine karar verdiğinde (bir bozulma fark ettiğinde) bu duruma geçer.
- **Regenerate:** Gerekirse bu duruma geçer ve bir test mühendisinin yardımıyla test senaryosu yeniden tasarlanır.

Sunucu, slaytın dışında yardımlaşmayı bir örnekle anlattı. A test aracısının bir görevi vardır ama kaynakları yetmez; B'den yardım ister. B Idle durumundan Interact durumuna geçip talebi değerlendirir, kendi çıkarına bir katkısı olmadığını görür ve reddeder, sonra Idle durumuna döner. Aynı talebi alan C aracısı ise Interact durumunda talebin kendi koşacağı test senaryoları için yararlı olduğunu (o testin loglarına, hata raporlarına ya da doğrudan çıktısına ihtiyacı olduğunu) görür, yardım etmeyi kabul edip Execute durumuna geçer ve A'nın görevini tamamlamasına yardım eder. Bu örnekte aracıların kendi karar mekanizması, sosyal yeteneği ve proaktifliği birlikte görülür.

### 2.6 Etkileşim Düzeyleri

Çalışma, dağıtık regresyon testinde dört etkileşim düzeyini test aracılarının uyarlanabilir davranışına katmayı önerir:

- **Yanıt beklenmeyen etkileşim:** Bir aracı diğer aracılara bilgi yayınlar (yürütme süresi, hata tespiti, test kapsamı, loglar, test raporları) ve yanıt beklemez.
- **Birebir diyalog:** A aracısı B'den bilgi ister ve yanıt bekler.
- **Birebir yetkilendirme (delegasyon):** A bir görevi ya da alt görevi B'ye devreder ve yürütme kanıtı ve bilgisiyle bir yanıt bekler.
- **Bire çok diyalog/delegasyon:** Birden fazla aracının işe karıştığı durum. Örnek: A, B'den yardım ister; B talebi çıkarına uygun bulduğu için kabul eder ama kaynakları yetmez, A'nın görevi için C'den yardım ister.

### 2.7 Sonuç ve Değerlendirme

Slayttaki sonuca göre (ekrandan, 00:35:00) çalışmanın amacı, test senaryosu kavramını yeniden değerlendirmek için uyarlanabilir özerk aracı paradigmasını yazılım test alanına uygulamaktır. Bu tür aracılar yardıma ne zaman ihtiyaç duyduklarını ve farklı koşullarda diğer aracılara ne zaman yardım edeceklerini sürekli düşünüp karar vermelidir. Sunucu, önerinin çok yeni olduğunu ve bu yaklaşıma tam uyan pek araç bulunmadığını, bir geliştirme ortamı eklentisinde test aracıları olsa da bunların yine bir test koordinatörü tarafından yönetildiğini belirtti. Sunucuya göre yaklaşım sektöre etkin biçimde uygulanabilirse büyük yazılımlardaki regresyon karmaşasını ve maliyetini önemli ölçüde azaltabilir.

## 3. Yazılım Hata Tahmininde Kalıtımın Etkinliği

İkinci sunumun konusu "Yazılım Hata Tahmininde (SFP) Kalıtım Yönü Etkinliği" idi (ekrandan, 00:40:00). Sunum giriş, kalıtım metrikleri, yazılım hata tahmin teknikleri ve sonuç bölümlerinden oluşuyordu. Çalışmanın amacı yazılım hata tahmini çalışmalarını toplamak, düzenlemek, sınıflandırmak ve incelemektir.

### 3.1 Yazılım Hata Tahmini (SFP)

Yazılım hata tahmini (Software Fault Prediction), geliştirme ve test sürecinin kaliteli yazılım üretmesine yardım eden bir araştırma alanıdır. Geliştirme sürecinin etkinliğini doğrulamak için ölçüm gerekir; 1970'lerde önerilen ilk ölçümler (McCabe, Halstead vb.) kodlanmış son ürün üzerinde tanımlanmıştı. <!-- BELİRSİZ: Altyazıda "MAKAEP, HLAT ve ULPRİD" olarak geçen üçüncü ölçüm adı anlaşılmıyor. --> Erken hata tespiti zaman ve maliyetten tasarruf sağlar ve yazılımın karmaşıklığını azaltır; bu yüzden hatalı sınıfları tespit edip testi onlara yoğunlaştırmak önemlidir. <!-- BELİRSİZ: Sunumda 2014 yılı küresel yazılım harcaması ve kalite kontrol/test payı için verilen rakamlar ("3.8 milyar dolar", "%23") altyazıdan doğrulanamadı. -->

Kaynak kodun kalitesi iç (dahili) metriklerle, yazılımın davranışı ve işlevselliği dış (harici) metriklerle ölçülür. Literatürde çaba tahmini, hata tahmini, kalite tahmini ve stres tahmini gibi pek çok tahmin yaklaşımı vardır. Hata tahmini, geliştirmenin ilk aşamalarında makine öğrenmesiyle hatalı sınıfların belirlendiği görece yeni bir alandır. Kullanılan yöntemler arasında destek vektör makineleri, Naive Bayes, karar ağaçları ve sinir ağları bulunur. Bu teknikler yazılımın metriklerinden, benzer projelerin metriklerinden ve önceki sürümlerin hata bilgilerinden hata tahmin modelleri kurar.

Tipik hata tahmin süreci iki aşamalıdır:

- **Eğitim aşaması:** Bileşenlere ait hata bilgisi ile yöntem düzeyi ya da sınıf düzeyi metrikler kullanılarak tahmin modeli kurulur.
- **Tahmin aşaması:** Sınıflandırma yöntemleri, hata verisiyle ilişkilendirilmiş metrikleri kullanarak sınıfları "hatalı" ya da "hatasız" olarak etiketler.

### 3.2 Kalıtım ve Hata Tahmini

Slayttaki giriş maddeleri şöyleydi (ekrandan, 00:45:00): Nesne yönelimli paradigmada kalıtım önemli bir özelliktir; kalıtım ölçütleri, hata tahminine dayalı olarak sınıfın karmaşıklığını tanımak için yararlıdır. Kalıtım ilişkisi ne kadar büyükse bir sınıfın yöntemlerinin o kadar çok kalıtım alması beklenir; sınıf karmaşıklaşır ve ek testler gerekir. Kalıtım yeniden kullanım, test edilebilirlik ve karmaşıklık açısından etkilidir; teknik sorunları önlemek için sınırlar içinde tutulmalıdır. Uygun aralıkta kullanılırsa yazılım karmaşık hale gelmez.

Hata tahmini literatüründe bağlaşım (coupling) ve uyum (cohesion) gibi nesne yönelimli metrikler çok çalışılmıştır. Bunlar tek başına ya da birlikte kullanılır; Chidamber-Kemerer (CK) metrik seti bu birlikte kullanımın en yaygın kabul gören örneğidir. Ancak CK setinde kalıtım metriklerinin ayrıca kullanımı ve değerlendirilmesi eksiktir; bu eksiklik kalıtıma odaklanan bir çalışmayı teşvik etmiştir. Çalışma, literatürde tanımlanan 54 kalıtım metriğini kataloglamış, hata tahmininde kullanılan nesne yönelimli metrikleri, veri setlerini, teknikleri ve performans ölçütlerini incelemiş, çeşitli kalıtım metriği kombinasyonları içeren 78 açık veri seti belirlemiş ve hata tahmininde kalıtımın etkinliğini göstermiştir.

### 3.3 Kalıtım Metrikleri

Hata tahmini, kalıtım metriklerini birbirinden bağımsız olarak ya da bir kombinasyon halinde makine öğrenmesi algoritmalarıyla birlikte kullanır (ekrandan, 00:50:00). Tanımı verilen metrikler:

- **Depth of Inheritance Tree (DIT):** İncelenen sınıfın kalıtım ağacında köke olan uzaklığı.
- **Number of Children (NOC):** Bir sınıfın alt sınıflarının sayısı. Alt sınıf sayısı arttıkça kalıtım yoluyla yeniden kullanımın arttığı anlaşılır.
- **Attribute Inheritance Factor (AIF):** Sistemdeki miras alınan özniteliklerin, bütün sınıfların öznitelik toplamına oranı.

Diğer metriklerin yalnızca adları okundu; slayttaki listeden okunabilenler: Method Inheritance Factor (MIF), Number of Methods Inherited, Number of Methods Overridden, Number of New Methods, Inheritance Coupling, Fan-in ve Fan-out, Fan-down, Fan-up, Object-to-Root Depth, Object-to-Leaf Depth, Measure of Functional Abstraction (MFA), IFANIN, Number of Ancestor Classes (NAC), Number of Descendent Classes (NDC). Altyazıda devamında Class-to-Leaf Depth, Number of Parents, Number of Descendents, Average Inheritance Depth, Specialization Ratio, Reuse Ratio, Class Complexity Due to Inheritance, Total Progeny Count, Total Ascendancy Count, Total Length of Inheritance Chain gibi metrikler sayılarak toplam 54'e ulaşıldı.

### 3.4 Hata Tahmin Teknikleri

Kalıtım metrikleri istatistiksel yöntemlerle ya da makine öğrenmesi yöntemleriyle işlenerek yazılımdaki hatalar tespit edilir.

**İstatistiksel yöntemler:** Bir çalışmada tek değişkenli ikili lojistik regresyon ve lojistik regresyon olmak üzere iki istatistiksel yaklaşım kullanılmıştır. Bağımlı değişkenin yalnızca iki sınıf (hatalı/hatasız) aldığı durumda lojistik regresyon uygundur. <!-- BELİRSİZ: Altyazıda "doğrusal regresyon" geçiyor; ikili bağımlı değişken için kastedilenin lojistik regresyon olduğu bağlamdan çıkarıldı. -->

**Makine öğrenmesi yöntemleri:**

- **Destek vektör makinesi (SVM):** İki sınıf arasında bir uzaklık ölçüsü düşünerek sınıfları ayıran boşluğu (marjı) bulur; bu boşluk özellik vektörlerinin bir fonksiyonuyla belirlenir.
- **Karar ağacı:** Örnekleri karşılaştırmalarla uygun sınıflara ayırır; her örneği öznitelikleriyle ilişkilendirip hangi gruba ait olduğunu belirler. Örüntü tanımadaki başarısı, hata örüntülerini saptamada tercih edilmesinin nedenidir.
- **AdaBoost:** Sınıflandırıcı topluluğu kuran algoritmalar arasında başarılıdır; en çok tek düzeyli karar ağaçlarıyla kullanılır ve ağırlıkları yinelemeli güncelleyerek güçlü bir sınıflandırıcı oluşturur.
- **Rastgele orman (RF):** Breiman'ın 2001'de önerdiği sınıflandırıcıdır (ekrandan, 00:55:00). Binlerce girdi değişkenini yönetebilir ve büyük veri tabanlarında verimli çalışır; sınıflandırmada hangi değişkenlerin önemli olduğunu gösteren tahminler sunar. Slayttaki şekilde veri seti birden çok karar ağacına verilir, her ağacın sonucu çoğunluk oylaması ya da ortalama ile birleştirilerek son sonuç elde edilir. Farklı projelerden elde edilmiş karar ağaçlarının birlikte rastgele orman olarak kullanılmasıyla hata tahmini başarıyla yapılabilir.
- **K en yakın komşu (k-NN):** Uygulaması kolay, gözetimli bir algoritmadır; hem sınıflandırma hem regresyonda kullanılır, endüstride daha çok sınıflandırmada. Yeni örneğin mevcut örneklere uzaklığı hesaplanır ve en yakın K komşuya bakılır.
- **Yapay sinir ağları:** En yaygın modeli çok katmanlı algılayıcıdır (MLP). Nesne yönelimli metrikler üzerinde sınıflandırmada etkin bir tekniktir; katman sayısının belirlenmesi zor problemlerinden biridir.

### 3.5 Sonuç

Yazılım geliştirilirken nesneler arasında kalıtım kaçınılmazdır ve kalıtımın ölçülmesi pek çok yazılım probleminin çözümüne ışık tutar. Kalıtım metrikleriyle hata tahmini iki yolla yapılabilir: istatistiksel yöntemlerle ya da makine öğrenmesi algoritmalarıyla. Sonuç olarak bir yazılımda hata içeren sınıflar kalıtım metrikleri kullanılarak tespit edilebilir.

> **Hocanın vurgusu:** Metrikler yazılım kalitesi için gerçekten çok önemlidir; derste de üzerinde durulmuştu.

## 4. GUI Testleri için Otomatik Test Scripti Üretimi

Üçüncü sunum, 2018 tarihli bir IEEE yazılım testi konferansında (ICST) yayımlanan, GUI testleri için otomatik test scripti üretimini konu alan bir çalışmayı anlattı. <!-- BELİRSİZ: Makalenin tam başlığı altyazıda bozuk ("Automatically Generating Certificate for Buing Test"); konu GUI testi için test scripti üretimidir. -->

### 4.1 GUI ve GUI Testi

GUI (grafiksel kullanıcı arayüzü), bilgisayarda yapılan işlemleri simgeleyen pencere, düğme ve panellerin tümüdür. GUI testi, tasarım aşamasında oluşan hataları belirlemek ve uygulamanın arayüzünü test etmek için yapılır. Arayüzün işlevsel özelliklere göre doğru çalışıp çalışmadığı ile menü, düğme, simge ve metin kutularının boyut, renk, yazı, yerleşim, konum ve çözünürlükleri kontrol edilir. Bu testler genelde kullanıcılar ya da üçüncü taraf şirketler tarafından elle ya da otomatik yollarla yapılır.

### 4.2 Çevik Geliştirme ve Regresyon Testinin Maliyeti

Slayttaki metne göre (ekrandan, 01:05:00) çevik yaklaşımlarla uygulamaların kısa sürede, donanım ve yazılımdaki değişikliklere hızlı cevap vererek ve belirli bir kalite düzeyiyle piyasaya sürülmesi yönünde güçlü bir talep vardır. Yinelemeli geliştirmede her döngüde yeni işlevler eklenir; yeni işlevlerin mevcut işlevleri bozmadığından emin olmak için her döngüde regresyon testi gerekir. Regresyon testinde yalnız eklenen ya da değiştirilen işlevler değil, değiştirilmemiş mevcut işlevler de test edilir; bu da çok fazla adam-saat demektir. Şirketler bu zamanı yeni özelliklere harcamayı tercih eder.

Bu nedenle test otomasyonu gerekir. Test otomasyonu, önceden beklenen sonuçlarla gerçek sonuçları karşılaştırmak ve testlerin koşulmasını kontrol etmek için geliştirilen yazılımdan ayrı bir yazılımın kullanılmasıdır; amacı testte harcanan adam-saati azaltmaktır. Selenium WebDriver bu araçlardan biridir ve daha çok web uygulamalarında kullanılır; örneğin bir login sayfası için tarayıcı üzerinden otomatik test adımları yürütülebilir. Ancak Selenium gibi araçlar kullanılsa bile test scriptlerini yazılımcıların yazması gerekir ve bu da çok adam-saat tutar.

### 4.3 Mevcut Yaklaşımlar

- **Capture & replay (yakala ve yeniden oynat):** Test scripti oluşturmada en yaygın yöntemlerden biridir; Selenium IDE de bunu kullanır. Programlama bilgisi olmayan kullanıcılar arayüz üzerinde işlem yaparak ekran durumlarını kaydeder ve script elde eder. Ancak bu yolla hazırlanan scriptler sonradan kullanılmaz hale gelmeye daha yatkındır ve bakım maliyetini artırır. <!-- BELİRSİZ: Bakım maliyeti artışı için verilen yüzdeler ("%19 ve %4") altyazıda anlaşılmıyor. -->
- **Model tabanlı yaklaşım (Tanno):** Girdi değerlerini de içeren ekran tasarım belgelerinden ekran geçişleri için otomatik test scripti üretir (ekrandan, 01:10:00). Tamamlanmış ve ayrıntılı tasarım belgesi gerektirdiği için şelale modelinde yararlı olabilir; fakat müşteri istekleriyle sürekli değişen çevik projelerde ve web uygulamalarında böyle bir belge elde etmek zordur.
- **Yüksek soyutlamalı modellerden üretim:** Girdi formu değerlerini içeren ayrıntılı modeller yerine iş akış diyagramları gibi modellerden test senaryosu üreten araçlar vardır. stateMatrix bir durum geçiş tablosundaki N-anahtar (N-switch) kapsamı temelinde senaryo üretir; TQCAssist iş akış diyagramlarından iş akışlarını kapsayan senaryolar üretir. Model oluşturma emeği azalır, ama modeller test scripti için gerekli bilgiyi içermediğinden scriptleri otomatik üretmek mümkün değildir.
- **Ekran geçişlerini otomatik dolaşma:** Başka bir yaklaşım, link ve butonlara otomatik basarak ekran geçişlerini dolaşır ve test senaryosu ile scripti elde eder. Ancak geçişin bir koşula bağlı olduğu ekranlarda (örneğin veri tabanındaki duruma ya da bir girdi değerine göre farklı ekrana gidilmesi) eksikler kalır; her geçişin elle kontrolü gerekir ve bu ihmal edilirse otomatik scriptler tüm geçişleri kapsayamaz. <!-- BELİRSİZ: Bu yaklaşımın sahibinin adı altyazıda "Dalmayer" olarak geçiyor, doğrulanamadı. -->

### 4.4 Önerilen Yöntem

Önerilen yöntem, uygulamanın kaynak kodu ve çalıştırılabilir hali üzerinde statik ve dinamik analiz yaparak test scriptlerini otomatik üretmeyi ve ekran geçişlerini kapsamayı amaçlar. Slayttaki ifadeye göre (ekrandan, 01:15:00) yöntem, çalışma saatlerini azaltırken test kalitesini koruyarak regresyon testini otomatikleştirmeyi hedefler ve üç şartı yerine getirmelidir:

- **Şart 1:** Ön hazırlıkta ek çalışma saati ve araç işlemi gerektirmeden test scriptlerini otomatik oluşturmak.
- **Şart 2:** Otomatik oluşturulamayan test scriptlerine karşılık gelen ekran geçişlerini kullanıcıya göstermek.
- **Şart 3:** Tüm ekran geçişlerinin testlerini, otomatik oluşturulan testler ve elle desteklenen testlerle kapsamak.

Yöntemin genel akışı slayttaki şekilde verildi:

```text
Girdi: kaynak kod, ilk URL
  (3.1) Ekran geçiş bilgisinin çıkarılması
  (3.2) Test case'lerin üretilmesi
  (3.3) Test scriptlerinin ve ekran geçiş diyagramının üretilmesi
Çıktı: test scripti, ekran geçiş diyagramı
```

**3.1 Ekran geçiş bilgisinin çıkarılması:** Ekran geçişleri kaynak koddan statik analizle çıkarılır ve kontrol edilecek bütün geçişlerin bir özeti oluşturulur. Sunumdaki örnekte bir web çatısındaki denetleyici kodunda gelen istek (request) ve dönüş ifadeleri (return statement) incelenir; her dönüş ifadesi, farklı koşullara göre varılabilecek hedef ekranları temsil eder. <!-- BELİRSİZ: Örnekte kullanılan web çatısının adı altyazıda bozuk ("Spin Flavor"). -->

**3.2 Test case'lerin üretilmesi:** Slayttaki açıklamaya göre (ekrandan, 01:20:00) kullanıcının başlangıç noktası olarak verdiği ilk URL'den başlanır, test hedefi üzerindeki bir linke ya da butona basılarak arama yapılır; giriş formu varsa öngörülen değer girilir. Her ekran için geçiş hedefinin daha önce aranıp aranmadığı URL ve HTML gibi bilgilerle belirlenir. Yeni bir ekran geçişi bulunduğunda o andaki işlem dizisi bir test case olarak kaydedilir. Aranan ekranların sayısı 3.1'de elde edilen varış noktası sayısıyla eşleşmiyorsa önceki ekrana dönülüp arama tekrarlanır. Bir çakışma olursa ya da bir hedef ekranın aranma sayısı belirli bir sınırı aşarsa ekran analiz edilmiş kabul edilir ve analiz edilmemiş başka bir ekrana geçilir. Bu işlem bütün ekranlar analiz edilene kadar sürer.

**3.3 Test scriptleri ve ekran geçiş diyagramının üretilmesi:** 3.2'de kaydedilen her test senaryosu bir test scripti olarak çıkarılır. 3.1'de bulunan bir ekran geçişi için 3.2'de script üretilemediyse bu geçiş diyagramda gösterilir. Slayttaki örnek şekilde A ekranından B ve C'ye, C'den B'ye geçişler düz okla, C'den henüz ulaşılamamış bir ekrana geçiş ise kesikli çizgiyle ve "ulaşılamayan ekranı göster" notuyla çizilmiştir. Bu gösterim, kullanıcıyı eksik testi elle oluşturmaya teşvik eder.

### 4.5 Deney ve Sonuçlar

Yöntem bir örnek web uygulaması üzerinde denenmiştir. Geleneksel yöntemde test scriptleri Selenium ile elle yazılmış ve süre ölçülmüş; önerilen yöntemde ise aynı iş ekran geçiş bilgisiyle yapılmıştır. Sunucunun aktardığı sonuçlar:

- Elle script hazırlama süresi 998 saniye, önerilen yöntemle 393 saniyedir. Azalma oranı $(998-393)/998 \approx 0.606$, yani yaklaşık %61'dir.
- Otomatik üretilen scriptler ekran geçişlerinin yaklaşık %63'ünü kapsamış; otomatik üretilemeyen geçişlerin diyagramda gösterilip elle tamamlanmasıyla kapsam %100'e çıkmıştır. Önerilen yöntemin ekran geçiş diyagramında koyu renkli okların otomatik üretilen geçişleri, kesikli çizgilerin ise sonradan elle test edilen geçişleri gösterdiği söylendi (ekrandan, 01:25:00).

Sunucu çalışmada tartışılan önemli bir noktayı da aktardı: Test scripti hazırlamak çok adam-saat aldığı için şirketler manuel teste yönelir, çünkü script hazırlama süresi testi elle yapma süresine yakındır. Üstelik uygulama sürekli değiştiği için hazırlanan scriptlerin tekrar kullanılabileceği garanti değildir. Bu konuda bir çalışmada, belirli bir süre sonunda scriptlerin büyük bölümünün değiştirilmesi gerektiği bulunmuştur. <!-- BELİRSİZ: Bu çalışmanın yazarı ("Lietso"), koşulları ("6 farklı işletim sistemi, 8 ay") ve oranı ("%63") altyazıda net değil. --> Tüm ekran geçişlerini kapsayan testi elle yapmak 940 saniye sürerken önerilen yöntemle scriptleri elde etmek 393 saniye sürmüştür. Bu yüzden scriptler ileride kullanılamaz hale gelse bile otomasyona yönelmek daha verimli görünmektedir.

> **Ders sonrası not:** Sunucu 393 saniyenin manuel yürütmeden "%12 daha düşük" olduğunu söyledi; altyazıdaki değerlerle $393/940 \approx 0.42$, yani 393 saniye 940 saniyeden yaklaşık %58 daha kısadır. Söylenen oran büyük olasılıkla Whisper bozmasıdır ya da makaledeki başka bir karşılaştırmaya aittir.

> **Ders sonrası not:** Sunumun sonunda azalma oranı altyazıda "161 oranında" olarak geçiyor; doğrusu yukarıdaki hesapla uyumlu olarak yaklaşık %61'dir.

## 5. Makine Öğrenmesiyle Yazılım Hata Tahmini: Sistematik İncelemeler

Dördüncü sunum "Yazılım Hata Tahminlemesinde Kullanılan Yöntemler" başlığını taşıyordu ve makine öğrenmesi yöntemlerini, bunların istatistiksel yöntemlerle karşılaştırmasını ele aldı. Hoca, bu sunumun bir önceki kalıtım sunumuyla aynı güne denk gelmesinin iyi olduğunu, sunucunun da ikinci sunumdaki çalışmaların içinde geçen bir makaleden yola çıktığını belirtti.

> **Hocanın vurgusu:** Hata tahmini üzerinde gerçekten çok fazla çalışma vardır.

### 5.1 Ana Makale: Malhotra'nın Sistematik İncelemesi

Ana makale, makine öğrenmesi teknikleriyle yazılım hata tahmini üzerine Malhotra'nın sistematik literatür incelemesidir. Çalışma 1991-2013 arasındaki çalışmaları inceler. Sunucu bu kapsamda beş makaleye baktığını, sunumda bunların üçünü anlattığını söyledi.

**İnceleme süreci:** Kitchenham'ın sistematik literatür incelemesi kılavuzuna göre dokuz adımlı bir süreç izlenmiştir: incelemenin gerekliliğinin belirlenmesi, inceleme protokolünün geliştirilmesi (kıdemli araştırmacılardan oluşan bir grupla düzenli değerlendirmeler), araştırma sorularının belirlenmesi, arama stratejisi, seçim kriterleri, kalite değerlendirmesi, veri çıkarma, veri sentezi ve sonuçların raporlanması.

**Araştırma soruları** slaytta tablo olarak verildi (ekrandan, 01:35:00):

| No | Araştırma sorusu |
|---|---|
| RQ1 | Hata tahmininde hangi makine öğrenmesi teknikleri kullanılmıştır? |
| RQ2 | RQ1'deki tekniklerle hata tahmininde ne tür deneysel doğrulama yapılmıştır? |
| RQ2.1 | Özellik azaltma için hangi teknikler kullanılmıştır? |
| RQ2.2 | Hangi metrikler yaygın kullanılmıştır? |
| RQ2.3 | Hangi metrikler yararlı bulunmuştur? |
| RQ2.4 | Hangi metrikler yararlı bulunmamıştır? |
| RQ2.5 | Hangi veri setleri kullanılmıştır? |
| RQ2.6 | Veri setlerindeki hata dağılımı nedir? |
| RQ2.7 | Hangi performans ölçütleri kullanılmıştır? |
| RQ3 | Makine öğrenmesi tekniklerinin genel performansı nedir? |
| RQ4 | Makine öğrenmesi teknikleri istatistiksel tekniklerden daha mı iyidir? |
| RQ5 | Diğerlerinden anlamlı biçimde üstün bir makine öğrenmesi tekniği var mı? |
| RQ6 | Makine öğrenmesi tekniklerinin güçlü ve zayıf yönleri nelerdir? |

**Arama ve seçim:** Ders kitaplarında ve araştırmalarda geçen terimler (software, defect, fault, error, proneness, decision tree, genetic algorithms vb.) AND ve OR ile birleştirilerek bir arama ifadesi kurulmuş, yedi dijital kütüphanede ve konferans yayınlarında arama yapılmıştır. Aramadan 96 çalışma, bunların kaynakçalarından 26 çalışma daha bulunarak toplam 122 çalışmaya ulaşılmıştır.

Dahil etme kuralları:

- Hata tahmini için makine öğrenmesi kullanan çalışmalar.
- Makine öğrenmesinin yanında başka yöntemler de kullanan çalışmalar (karşılaştırma yapılabilmesi için).
- Makine öğrenmesi ile istatistiksel teknikleri birleştiren çalışmalar.

Hariç tutma kuralları:

- Makine öğrenmesi kullanıp sonuç ya da analiz vermeyen çalışmalar.
- Makine öğrenmesi kullanıp hata tahmini yapmayan çalışmalar.
- Birden fazla yerde yayımlanmış aynı çalışmanın tekrarları (yalnız biri alınır).
- İnceleme (review) çalışmaları.
- <!-- BELİRSİZ: Altyazıda "bağımlı değişkene dayalı çalışmalar" da hariç tutulan grup olarak geçiyor; ölçütün tam ifadesi anlaşılmıyor. -->

İki araştırmacı bağımsız olarak çalışıp ortak karara varmış ve bu kurallarla 122 çalışmadan 79'u seçilmiştir.

**Kalite değerlendirme anketi:** 79 çalışmaya 15 soruluk bir anket uygulanmıştır (ekrandan, 01:40:00). Her soru için "yes" 1 puan, "partly" 0.5 puan, "no" 0 puan verilir. Sorulardan bazıları: araştırmanın amacı açıkça belirtilmiş mi, bağımsız değişkenler açıkça tanımlanmış mı, veri seti boyutu uygun mu, veri toplama prosedürü açık mı, metrikler alt seçimle mi belirlenmiş, makine öğrenmesi teknikleri gerekçelendirilmiş ve açıkça tanımlanmış mı, performans ölçütleri açık mı, sonuçlar açık mı, çalışmanın sınırlılıkları belirtilmiş mi, yöntem tekrarlanabilir mi, istatistiksel ile makine öğrenmesi arasında ve makine öğrenmesi teknikleri arasında karşılaştırma var mı, literatüre katkı var mı, yıllık ortalama atıf sayısı yeterli mi. Anketten 9.5 ve üzeri puan alan 64 çalışma seçilmiştir.

```text
Seçim akışı:
  Arama: 96 çalışma + kaynakçalardan 26 = 122
  Dahil etme / hariç tutma kuralları   ->  79
  Kalite anketi (15 soru, >= 9.5 puan)  ->  64
```

### 5.2 Bulgular

**Kullanılan teknikler:** 64 çalışmadaki yöntemler yedi kategoride toplanmıştır (karar ağaçları, Bayes öğrenmesi, sinir ağları vb.). Sunucu, karar ağacı ve Bayes içeren çalışmaların sayısını 31, sinir ağı içerenlerin sayısını 17 olarak aktardı.

**Özellik azaltma:** Çalışmaların %49'unda özellik azaltma yöntemi kullanılmıştır. En çok kullanılan özellik seçim yöntemi korelasyon tabanlı özellik seçimidir (CFS).

**Metrikler:** Üç gruba bakılmıştır. Prosedürel metrikler (Halstead, McCabe, satır sayısı / LOC) çalışmaların %51'inde kullanılmış, ancak bunların yararı konusunda çalışmalarda olumlu bir not düşülmemiştir. Nesne yönelimli metrikler %28 oranında kullanılmıştır; bunlar arasında en çok kullanılanlar CBO (Coupling Between Objects, nesneler arası bağlaşım) ve RFC (Response For a Class) olmuştur. LOC hem prosedürel hem nesne yönelimli metrikler arasında sayılmıştır. Hibrit metrik kullanan çalışmalar çok az olduğu için ayrıca sayısal olarak verilmemiştir.

**Veri setleri:** Slayttaki grafiğe göre (ekrandan, 01:45:00) çalışmaların yaklaşık %60'ında açık NASA veri setleri, yaklaşık %15'inde PROMISE veri setleri kullanılmıştır; Eclipse, açık kaynak ve diğer veri setleri daha düşük oranlardadır. Özel (private) veri setlerinin içeriğine erişilemez.

**Performans ölçütleri:** Aynı slayttaki ikinci grafikte accuracy, precision, recall, specificity, PF, FNR, ROC, balance, completeness, F-measure ve diğer ölçütlerin kaç çalışmada kullanıldığı gösterildi; en çok kullanılan ölçüt recall, ardından accuracy olarak görünmektedir. Karşılaştırma ROC eğrisinin altındaki alan (AUC) üzerinden yapılmıştır.

> **Ders sonrası not:** Sunucu ROC'u "doğru pozitif oranının yanlış pozitif oranına bölünmesiyle" bulunan bir değer olarak anlattı. Doğrusu: ROC eğrisi, doğru pozitif oranının (TPR) yanlış pozitif oranına (FPR) karşı çizilen eğridir; AUC bu eğrinin altında kalan alandır, iki oranın bölümü değildir.

**Tekniklerin karşılaştırılması:** Ortalama AUC değerlerine göre rastgele orman 0.83 ile en yüksek değere ulaşmıştır. Sunucunun aktardığına göre Naive Bayes, MLP ve Bayes ağları yaklaşık 0.78, SVM yaklaşık 0.7 değerindedir. Ayrıca her tekniği sabit tutup diğerleriyle çalışma çalışma karşılaştıran bir diyagram gösterildi: Örneğin rastgele orman ile Bayes ağının birlikte incelendiği 10 çalışmanın 9'unda rastgele orman daha iyi sonuç vermiştir. Rastgele ormana en yakın yöntemler Bayes ağları ve MLP'dir; Naive Bayes ise pek çok çalışmada rastgele ormanın altında kalmıştır.

**İstatistiksel yöntemlerle karşılaştırma:** İstatistiksel yöntemler içinde en çok kullanılan lojistik regresyondur. 64 çalışmanın 19'unda lojistik regresyon ile makine öğrenmesi teknikleri birlikte uygulanmış; makine öğrenmesi yöntemleri lojistik regresyondan yaklaşık %2 daha başarılı bulunmuştur. Bagging bu çalışmaların tamamında, rastgele orman %80'inde lojistik regresyondan daha iyi sonuç vermiştir. Araştırmacılar 64'te 19 çalışmanın genelleme için az olduğunu not etmiştir.

**Güçlü ve zayıf yönler** (ekrandan, 01:50:00):

- Rastgele orman gürültülü ve eksik veri içeren setlerde başarılıdır ve hızlı eğitilir.
- Naive Bayes hata tahmini problemlerinde iyi performans gösterir ve değişken özelliklere sahip çoklu veri kümelerini işlemede iyidir.
- SVM gereksiz özellikler ve yüksek boyutlulukla çok iyi başa çıkar.
- Naive Bayes'in zayıf yanı özellikler arası korelasyonu dikkate almamasıdır; modelin performansı kullanılan öznitelik seçim tekniğine bağlıdır.

**Sonuçlar ve öneriler:** En çok kullanılan yöntemler Naive Bayes, SVM ve rastgele ormandır; en çok kullanılan özellik seçimi CFS, en çok kullanılan veri seti NASA'dır; en sık kullanılan performans ölçütleri F-measure, recall, AUC ve accuracy'dir. En iyi performansı rastgele orman vermiştir. Araştırmacılar makine öğrenmesinin hata tahmininde daha çok kullanılmasını ve makine öğrenmesi ile lojistik regresyonu karşılaştıran çalışmaların artırılmasını önermiştir. Sunucu bu öneriyi, derste görülen bir bilgiyle bağladı: Hata kod canlıya çıktıktan sonra bulunursa maliyeti çok daha yüksektir (sunucu yaklaşık 20 kat dedi); hata ne kadar erken bulunursa emek, maliyet ve müşteri memnuniyeti açısından o kadar kazançlıdır.

### 5.3 İkinci Makale: Nesne Yönelimli Sistemlerde Hata Tahmini

İkinci makalede makine öğrenmesi teknikleri nesne yönelimli bir yazılım üzerinde denenmiştir. Veri seti olarak PROMISE deposundaki Xerces sürümleri kullanılmıştır. Süreç şöyledir:

- WEKA üzerinde korelasyon tabanlı özellik seçimiyle ön işleme.
- 17 makine öğrenmesi tekniğinin belirlenmesi.
- WEKA üzerinde 10 katlı çapraz doğrulamayla model eğitimi ve doğrulama.
- Friedman testiyle tekniklerin topluca karşılaştırılması.
- Wilcoxon testiyle ikili karşılaştırma.

Slayttaki tablodan seçilmiş değerler aşağıdadır (ekrandan, 01:55:00); tablo Xerces'in dört sürümündeki (init, 1.2, 1.3, 1.4) değerleri ve ortalamayı (AVG) verir:

| Teknik | init | 1.2 | 1.3 | 1.4 | AVG |
|---|---|---|---|---|---|
| LR | 0.525 | 0.555 | 0.757 | 0.903 | 0.685 |
| NB | 0.732 | 0.616 | 0.788 | 0.841 | 0.744 |
| BN | 0.761 | 0.677 | 0.825 | 0.927 | 0.798 |
| MLP | 0.720 | 0.605 | 0.749 | 0.903 | 0.744 |
| ADT | 0.793 | 0.741 | 0.775 | 0.940 | 0.812 |
| Bagging | 0.803 | 0.763 | 0.818 | 0.928 | 0.828 |
| RF | 0.786 | 0.766 | 0.838 | 0.913 | 0.826 |
| LB | 0.800 | 0.758 | 0.802 | 0.946 | 0.827 |
| AB | 0.803 | 0.742 | 0.819 | 0.931 | 0.824 |
| DTNB | 0.768 | 0.703 | 0.804 | 0.934 | 0.802 |

Tablodaki 17 tekniğin tamamı için AVG sütunu, dört sürüm değerinin aritmetik ortalamasıyla python ile kontrol edildi; hepsi üç basamağa yuvarlanmış ortalamayla uyuşuyor. Örneğin Bagging için $(0.803+0.763+0.818+0.928)/4 = 0.828$.

Bagging 0.828 ile en iyi ortalamayı vermiş, rastgele orman 0.826 ile hemen arkasında kalmıştır; LogitBoost (LB) ve AdaBoost (AB) de iyi sonuç veren yöntemler arasındadır. Bir önceki incelemede rastgele orman en iyiydi ve Bagging ona yakındı; bu çalışmada sıralama ters dönmüştür. Friedman testinde ortalama sıra küçüldükçe yöntem daha iyidir: Bagging 2.80 ile ilk sırada, ardından LB 3.00, AB 3.30 ve RF 4.00 gelmektedir. Wilcoxon testiyle Bagging, lojistik regresyon ve rastgele orman dahil diğer yöntemlerle ikili olarak karşılaştırılmış ve hepsine göre üstün çıkmıştır.

> **Ek bilgi (derste anlatılmadı):** Bagging (bootstrap aggregating), eğitim verisinden yerine koymalı örneklemeyle çok sayıda alt küme üretip her birinde bir model eğitir ve tahminleri oylama ya da ortalama ile birleştirir. Rastgele orman, buna ek olarak her bölünmede özniteliklerin rastgele bir alt kümesini kullanan, karar ağacı tabanlı bir bagging türüdür. Bu yüzden iki yöntemin sonuçlarının birbirine yakın çıkması beklenen bir durumdur.

### 5.4 Üçüncü Makale: 2009 Tarihli Sistematik İnceleme

Üçüncü makale 2009 tarihli bir sistematik incelemedir. Burada doğrudan performans ölçütleri karşılaştırılmamış, daha çok sayısal ve oransal bir inceleme yapılmıştır: hangi veri setlerinin kullanıldığı, 2005 öncesi ve sonrası veri seti kullanımının dağılımı, yöntemlerin oransal karşılaştırması, en çok kullanılan yöntem ve metrik, en çok yayın yapılan yayın grubu.

Bulgular:

- Makine öğrenmesi yöntemleri literatüre 1990'larda girmiş olsa da yayınlar 2005'ten sonra artmıştır. Bunun başlıca nedeni açık veri setlerinin çoğalmasıdır; açık veri setleri sayesinde çalışmalar tekrarlanabilir hale gelmiştir.
- En çok yayın IEEE yazılım mühendisliği yayınlarından incelenmiştir.
- 2005 öncesinde özel veri setleri yaklaşık %60 oranında kullanılırken, 2005 sonrasında açık veri setleri %52 ile en çok kullanılan veri setleri olmuştur. <!-- BELİRSİZ: Altyazıda 2005 öncesi için yalnız "veri setleri %60" geçiyor; kastedilenin özel veri setleri olduğu bağlamdan çıkarıldı. -->
- 2009'a kadarki tüm çalışmalarda makine öğrenmesi yöntemleri %59, makine öğrenmesi ile istatistiksel yöntemleri birlikte kullananlar %18 oranındadır. 2005 sonrasında makine öğrenmesi kullanımı %66'ya çıkmış, birlikte kullanım ise %17'de kalmıştır.

Malhotra'nın incelemesiyle bu makale arasında beş yıl olmasına rağmen sonuç değişmemiştir: Makine öğrenmesi ile istatistiksel yöntemleri birlikte kullanan çalışmalar azdır ve araştırmacılar bu yönde çalışma yapılmasını önermektedir.

> **Hocanın vurgusu:** Hata tahmini konusunda gerçekten çok çalışma vardır; özellikle yapay zeka uygulamalarıyla birleştirildiği için teknik uygulamaları ve teknikleriyle mühendislik yaklaşımına açık bir alandır. Konunun farklı açılardan iki kez incelenmesi yararlı olmuştur.

## 6. Metamorfik Test

Son sunum metamorfik yazılım testini anlattı. Hoca sunumun kaynağının 2016 tarihli bir IEEE Transactions on Software Engineering makalesi olduğunu belirtti.

### 6.1 Test Oracle Problemi

Yazılımın rolü ve miktarı arttıkça karmaşıklığı da artar; hataları bulmaya yönelik testler zorlaşır ve uzar. Yazılım doğrulamasında temel amaç en kısa sürede en çok hatayı yakalamaktır. Testin temel sorunlarından biri, test edilen yazılımın hangi girdiye hangi çıktıyı üretmesi gerektiğini belirlemektir. Her test girdisi için doğru sonucun önceden hesaplanması gerekir ve bu zaman alır. Bu sorun **test oracle problemi** olarak bilinir. Karmaşık hesaplama yapan yazılımlarda (yapay zeka, biyoinformatik gibi) beklenen çıktıları önceden hesaplamak çok emek ister.

### 6.2 Metamorfik Test Yaklaşımı ve Metamorfik İlişkiler

Metamorfik test, Chen ve arkadaşlarının 1998'de ortaya attığı bir kavramdır. Test edilen yazılımda girdiler ve çıktılar arasında **metamorfik ilişkiler** belirlenir ve test bu ilişkiler üzerinden yapılır. Amaç test oracle problemini daha hızlı ve daha az emekle çözmektir.

Sinüs fonksiyonu örneği slaytta şöyle verildi (ekrandan, 02:05:00):

$$\sin(x) = \sin(x + 360^\circ) \qquad \text{veya} \qquad \sin(-x) = -\sin(x)$$

Bu eşitlikler metamorfik ilişkilerdir. Buna göre sinüs fonksiyonu için 15 girdisinin vereceği çıktı hesaplandığında, 375 girdisi için yeniden hesap yapmak yerine 15 için doğru olan çıktı kullanılabilir. Sunucu anlatırken $\sin 15^\circ$ için 0.2 gibi bir değer "varsaydı"; yani $\sin(15^\circ)$ 0.2 ise $\sin(375^\circ)$ da 0.2, $\sin(-15^\circ)$ ise $-0.2$ olmalıdır. Benzer biçimde 360'ın her katı eklendiğinde yeni hesap gerekmez.

> **Ders sonrası not:** Sunucu 0.2 değerini yalnızca örnek olsun diye varsaydı. Gerçek değer $\sin(15^\circ) \approx 0.2588$'dir (python ile kontrol edildi). İlişkilerin doğruluğu bu değerden bağımsızdır.

Böylece metamorfik test yalnızca oracle problemini hafifletmekle kalmaz, testi büyük ölçüde otomatik hale de getirir.

### 6.3 Arama Motoru Örneği

İkinci örnekte, bir arama motorunda bir sorgunun döndürdüğü sonuç sayısını veren bir fonksiyon düşünüldü. Fonksiyona tek kelimelik bir $Q$ sorgusu verilir. Sonra $Q$ sabit tutulup yanına bir kelime daha eklenir. İkinci sorgunun sonuç sayısı birincisinden kesinlikle fazla olamaz; en fazla eşit olabilir:

$$\text{sonuç}(Q \cup \{K\}) \le \text{sonuç}(Q)$$

Sunucu bunu canlı olarak denedi: "metamorfik" kelimesi yaklaşık 128 bin sonuç, "metamorfik test" ise yaklaşık 35.600 sonuç verdi. İlişki sağlandığı için küçük bir metamorfik test başarıyla yapılmış oldu. Bir gün bir kelime eklendiğinde sonuç sayısı artarsa metamorfik ilişki ihlal edilmiş olur ve arama motorunda bir hata bulunduğu anlaşılır.

Bu örnek, metamorfik ilişkinin yalnızca eşitlik olmak zorunda olmadığını gösterir: Büyüktür, küçüktür ya da başka ilişkiler de kullanılabilir. İki farklı girdinin çıktıları arasında bir ilişki tespit etmek yeterlidir.

### 6.4 Neden Metamorfik Test?

Metamorfik test oracle problemi için büyük kolaylık sağlar ve testi otomatikleştirir. Test verisini ve doğru çıktıları önceden planlarken, aralarında metamorfik ilişki bulunan girdiler için ikinci hesaplama süresi neredeyse sıfıra iner: 15 derece hesaplandıysa 375 dereceyi ayrıca hesaplamaya gerek kalmaz.

### 6.5 Metamorfik Testin Temel Süreçleri

- **1. Metamorfik ilişkilerin kurulması:** Önce test edilen programın genel özellikleri belirlenir, ardından sinüs ya da arama motoru örneğindeki gibi birkaç metamorfik ilişki bulunur. İlişkiler her zaman matematiksel bir formül olmak zorunda değildir; her yazılım için farklı olabilir.
- **2. Kaynak test senaryolarının oluşturulması:** Kullanılacak teste dayalı kaynak test senaryoları hazırlanır.
- **3. Metamorfik test durumlarının yürütülmesi (test case execution):** Slayttaki ifadeye göre (ekrandan, 02:10:00) takip eden testlerin senaryolarını oluşturmak, kaynak ve takip testlerini yürütmek ve ilişkileri kontrol etmek için metamorfik ilişkiler kullanılır. Bir kaynak test senaryosunun ve takip testinin çıktıları metamorfik ilişkiyi ihlal ederse metamorfik test senaryosu başarısız sayılır ve test edilen programın bir hata içerdiği anlaşılır.

### 6.6 Kaynaklar

Sunucu, Chen ve arkadaşlarının 1998 makalesi dışında metamorfik test hakkında genel bilgi veren kaynakların az olduğunu belirtti. Yöntem yapay zeka ve biyoinformatik gibi farklı alanlarda denenmiş, sonuçlar ayrı ayrı yayımlanmıştır. Literatürün dağınık olması, son durumun analizini ve yeni araştırma yönlerinin belirlenmesini zorlaştırır. Seçilen makale bu nedenle uzun bir inceleme makalesidir: 1998-2015 arasında yayımlanmış 119 metamorfik test makalesini incelemiş, araştırma soruları sorup cevaplamıştır.

> **Hocanın vurgusu:** Bu sunum farklı bir yaklaşım getirdi; metamorfik test konusunda en azından bir kavram ve yaklaşım kazandırılmış oldu.

## Dersin Toparlaması

Bu derste öğrenci sunumları üzerinden yazılım testinin güncel araştırma konuları ele alındı. Test aracıları, regresyon testini merkezî ve statik bir yapıdan dağıtık, uyarlanabilir ve kendi kararını veren aracılara taşımayı öneriyor. Yazılım hata tahmini, kalıtım metrikleri ve CK metrikleri gibi nesne yönelimli ölçütleri makine öğrenmesi ve istatistiksel yöntemlerle birleştirerek testi hatalı olma olasılığı yüksek sınıflara yoğunlaştırmayı amaçlıyor. İncelenen çalışmalarda NASA ve PROMISE veri setleri, CFS özellik seçimi ve AUC ölçütü öne çıkıyor; en iyi sonuçlar rastgele orman ve Bagging gibi topluluk yöntemlerinden geliyor. GUI testinde kaynak kodun statik analizi ile dinamik dolaşmayı birleştiren bir yöntem script hazırlama emeğini yaklaşık %61 azaltıyor. Metamorfik test ise girdiler arası ilişkileri kullanarak test oracle problemini hafifletiyor.

Bu konular dersin önceki haftalarında görülen regresyon testi, ölçütler (McCabe, Halstead, CK) ve kalite hedefleriyle doğrudan bağlantılıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
