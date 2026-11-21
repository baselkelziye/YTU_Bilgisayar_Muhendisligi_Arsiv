# Ders 2 Genişletilmiş Notu: Yazılım Geliştirme ve Kalite Yaklaşımı, McCall Kalite Modeli ve Kalite Sağlama Aktiviteleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı
- 2. Yazılım Mühendisliğinde Kalitenin Yeri
- 3. Yazılım Mühendisliğinin Katmanlı Yapısı ve Süreç Adımları
- 4. Klasik Yazılım Geliştirme Süreç Modelleri
- 5. Çevik Yaklaşımlar ve Kalite
- 6. Yazılım Kalitesinin Temel Kavramları ve McCall Üçgeni
- 7. Yazılım Kalite Özellikleri
- 8. McCall Kalite Modeli
- 9. Yazılım Kalite Sağlama Aktiviteleri
- 10. Yazılım Kalite Maliyeti
- 11. Yazılım Mühendisliği Standartları
- 12. Yazılım Kalite Yönetim Sistemi

## 1. Dersin Kapsamı

Bu derste ilk haftanın giriş içeriği tekrar edildi. Hoca önce dersin konu başlıklarını içeren slaytı gösterdi (ekrandan, 00:20:00 - 00:35:00). Ders 12 başlıkta ilerliyor.

İlk başlık **yazılım geliştirme ve kalite yaklaşımıdır**: yazılım mühendisliğinde kalitenin yeri, yazılım geliştirme süreç modelleri, çevik yaklaşımlarda kalite bakış açısı ve test güdümlü yazılım geliştirme. Süreç modelleri bu derste yalnız hızlıca özetlenecek.

Sonraki başlıklar **yazılım kalite özellikleri** ve **kalite sağlama aktiviteleridir**. Kalite özelliklerinin sınıflandırılması ve McCall modeli görülecek. Ardından kaliteli yazılım üretmek için neler yapıldığı ele alınacak: kalite standartlarını kullanmak, gözden geçirme (review) ve inceleme (inspection) yapmak, onaylama yapmak. Yazılım geliştirildikten sonra hata olup olmadığına bakmak için test süreci kullanılır.

**Yazılım inceleme** başlığında incelemenin gözden geçirmeden farkı, incelemenin önemi ve Fagan incelemesi görülecek. Bunu **geçerleme ve doğrulama** (verification, validation) izliyor.

**Test süreci** başlığında birim test, bütünlük testi, regresyon testi, sistem testi ve onaylama testinin birbirini nasıl izlediği görülecek. Bu sıra şelale modele göredir. Diğer süreç modellerinde de aynı testler yapılır, ancak sıralama farklıdır ve daha sık aralıklarla tekrarlanır.

**Test teknikleri** başlığında saydam kutu ve kara kutu testi işlenecek (ekrandan, 00:25:00). Hoca bunlara gri kutu testini de ekledi. Saydam kutu testine iç test, kara kutu testine dış test de denebilir. Ardından **hata giderme** (debugging) ve hata düzeyleri, yani bulunan hataların tipleri geliyor.

**Yazılım ölçümü** (software metrics) yazılım mühendisliğinin de konusudur, ama kaliteyle ilişkili olduğu için bu dersin de konusudur. Bitmiş bir yazılımın ya da geliştirme sırasında ara ürünlerin nasıl ölçüleceği ve bu ölçmenin metrikleri görülecek. Slaytta Halstead ve McCabe ölçütleri yazıyor (ekrandan, 00:25:00). Nesneye yönelik yazılımlar için Chidamber-Kemerer (CK) metrikleri de anlatılacak. İlk olarak bu metriklerle kalite faktörleri arasındaki ilişki kurulacak.

**Yazılım güvenilirliği** (reliability) de önemli bir kalite faktörüdür. Yazılım bir sonuç bulur ve önce kabaca bu sonucun doğru mu yanlış mı olduğuna bakılır. Güvenilirlik ise bu doğru sonuca yüzde kaç güvenilebileceğini, yani çalıştırma süresince bulunan hata oranını anlatır. Bununla ilgili modellemelerden kısaca söz edilecek.

**Test planlama ve yönetimi** başlığında test yönetimi, test planının oluşturulması, test senaryoları (testte kullanılacak verinin nasıl oluşturulacağı, nasıl seçileceği ve kaç veriyle test edileceği), test çalışma ekibinin yapısı ve test raporları görülecek (ekrandan, 00:30:00). Dönem içindeki uygulama projesi bu başlıkla ilişkilidir. Bu projede kaynak koduna sahip olunan bir yazılım seçilir. Önce o yazılım için bir gereksinim belgesi (SRS) hazırlanır; bu belge kullanıcı testinde kullanılır. Sonra test planı, test senaryoları ve test sonuç belgesinden oluşan bir test raporu yazılır. Hoca seçilecek yazılımın büyüklüğü sorulunca, tek kişilik bir çalışma için 50-70 gereksinim maddesi olan bir yazılımın yeterli olduğunu, birim test yapılabilmesi için kaynak kodunun mutlaka elde olması gerektiğini söyledi.

**Yazılım teslim sonrası kalite sağlama** başlığında bakım (maintenance) ve yazılım konfigürasyonu var. Konfigürasyon yönetimi aslında geliştirmenin başında başlar ve sonra da sürer. Bakım sırasında yapılan her değişiklik kayda geçirilmeli, yazılımın bütün elemanlarıyla ilgili bilgi izlenebilir biçimde tutulmalıdır.

Son başlık **kalite iyileştirmedir**: CMMI, CMMI yeterlilik düzeyleri, anahtar süreç alanları, süreç alanlarının sınıflandırılması ve People CMM (ekrandan, 00:35:00). Bir yazılım evi, iyi olduğunu müşterilerine ve iş ortaklarına göstermek için bazen sertifika almak durumunda kalır. CMMI firmaları belli düzeylere yerleştirir, anahtar süreç alanlarını belirtir ve çalışanların yetkinliklerini de içine alır.

Hoca bu başlıkların temel olduğunu, dönem içinde gerektikçe yeni yaklaşımlar ve kaliteyle ilgili başka konuların da ekleneceğini belirtti. Dönem içindeki makale çalışması için başlangıç kaynakları olarak Software Quality dergisini, IEEE Software dergisini, Software Test and Automation dergisini ve daha kapsamlı makaleler içeren IEEE Transactions on Software Engineering dergisini önerdi. Bu çalışma bir derleme makalesi biçimindedir; 2015 sonrası bir makale başlangıç noktası olarak alınır.

## 2. Yazılım Mühendisliğinde Kalitenin Yeri

Slayttaki tanıma göre yazılım mühendisliği bilgisayar bilimi, yönetim bilimi, ekonomi ve bilişim bilim dallarından yararlanır ve sorun çözümünde mühendislik yöntemlerini kullanır (ekrandan, 00:40:00).

Hoca kendi kısa tanımını da verdi: yazılım mühendisliği, **kaliteli yazılımı en ekonomik olarak elde etmeye çalışan ve bu çalışmada mühendislik yöntemlerini kullanan, problemlere çözüm arayan bilim dalıdır.** Bu tanımda üç anahtar kavram vardır:

- **Kaliteli yazılım:** Amaç yazılımı ne olursa olsun hızlıca elde etmek değil, kaliteli yazılımı elde etmektir. Kalite özellikleri ve bunun için yapılacak aktiviteler bu dersin konusudur.
- **En ekonomik olarak elde etmek:** Bu, en ucuza üretmek değil, en uygun yazılımı uygun maliyetle oluşturmaktır. Bu konu yazılım proje yönetimiyle ilgilidir.
- **Mühendislik yöntemlerini kullanmak:** Sorun çözümünde mühendislik yöntemlerine başvurmak.

### 2.1 Mühendisliğin İki Temel Bacağı

Hoca öğrencilere mühendislik yöntemlerinin iki temel bacağının ne olduğunu sordu. Bir öğrenci ölçülebilirliği önerdi. Hoca bunu doğruladı: bir mühendislik dalının altında ölçme işi bulunmalıdır. Hoca "mühendis" kelimesini "hendese" ile, yani ölçme bilimiyle ilişkilendirdiğini anlattı.

İkinci bacak **tasarımdır**. Mühendislik, bir işe hemen başlamak değil, önce iyi bir tasarım yapmaktır. Bu, mühendislik sertifikasyonlarında bölümlerden istenen ve öğrencilere kazandırılması gereken en önemli yetenektir. Hoca inşaat örneğini verdi: bir binaya başlamadan önce mimarın tasarım yapması, binanın elektrik işleri için de ayrı bir tasarımın hazırlanması gerekir. Yazılımda da hemen programı yazmaya başlanmaz; önce yazılımın alt modüllerinin tasarımı yapılır.

> **Hocanın vurgusu:** Tasarım ve ölçme, yazılım mühendisliği dahil bütün mühendislik alanlarının altında yatan iki temel yöntemdir.

> **Ek bilgi (derste anlatılmadı):** "Hendese" Arapça kökenli bir kelimedir ve Osmanlı Türkçesinde büyük olasılıkla geometri anlamında kullanılmıştır. "Mühendis" kelimesi de aynı köktendir. Hocanın ölçmeyle kurduğu bağ bu geometri ve ölçüm anlamından gelir.

## 3. Yazılım Mühendisliğinin Katmanlı Yapısı ve Süreç Adımları

### 3.1 Katmanlı Yapı

Slayta göre yazılım mühendisliğinin temelinde kalite bakış açısı olan, üzerinde mühendislik yöntemleri, süreçler, metodolojiler ve yazılım araçlarının (CASE tool) bulunduğu katmanlı bir yapısı vardır (ekrandan, 00:40:00).

En altta **kalite bakış açısı** bulunur. Onun üzerinde **süreçler** yer alır: kalite bakış açısını gözden kaçırmadan hangi yazılım geliştirme süreç modelinin kullanılacağına karar verilir. Sonra **yöntemler** gelir: o projeye uygun hangi yazılım geliştirme yönteminin ve hangi diyagramların kullanılacağı belirlenir. En üstte **araçlar** vardır.

CASE (Computer Aided Software Engineering), yazılım geliştirmede analiz ve tasarımdaki işleri kolaylaştıran, rutinleştiren ve hatayı azaltan yazılımların kullanılmasıdır. Bunlar yalnız çizim yapan araçlar değil, mantıklı ve "akıllı" çizim yapan araçlardır. Araçlar rastgele seçilemez; kullanılan yönteme, süreç modeline ve kalite bakış açısına uygun olmalıdır.

### 3.2 Esas Süreç Adımları

Yazılım geliştirme sürecinin esas adımları gereksinim analizi, tasarım, kodlama, test ve bakımdır (ekrandan, 00:45:00). Hoca slaytta tasarım maddesinin unutulduğunu ve diğer adımların yanlışlıkla alt madde gibi göründüğünü belirtti; beş adımın hepsi aynı düzeydedir. Bunlar yazılımın hazırlanması için temel işlemlerdir.

### 3.3 Destek Süreç Adımları

Destek süreç adımları, temel adımların daha iyi ve daha sağlıklı yapılmasını sağlar:

- Proje yönetimi
- Kalite yönetimi
- Geçerleme ve doğrulama (verification, validation)
- Formal teknik gözden geçirme
- Yazılım konfigürasyon yönetimi
- Yeniden kullanılabilirlik yönetimi
- Yazılım ölçümü
- Risk yönetimi

Bu adımların çoğu kalite yönetiminin altına girer: geçerleme, doğrulama, gözden geçirme, konfigürasyon yönetimi, yeniden kullanılabilirlik yönetimi ve yazılım ölçümü. Ayrı yazılmalarının nedeni, birçoğunun proje yönetimini de desteklemesidir. İyi bir proje yönetimi için yazılım ölçümünden destek alınır, risk yönetimi mutlaka proje yönetimi altında kullanılır, geçerleme ve doğrulama da her ikisinde yapılır. Yani proje yönetimi ile kalite yönetimi kısmen kesişir. Bazı yazılım mühendisliği kitapları bu yüzden ikisini "software engineering management" ya da "software management" adlı tek bir bölümde birleştirir.

## 4. Klasik Yazılım Geliştirme Süreç Modelleri

Süreç modelleri, yazılım geliştirme sürecinin adımlarının hangi sırada ve düzende uygulanacağını tanımlar. Başlıca modeller şunlardır (ekrandan, 01:10:00):

- Klasik doğrusal akış (Waterfall)
- Prototip model
- Artımlı (incremental) model
- Helezon (Spiral) model
- Hızlı Uygulama Geliştirme (Rapid Application Development)
- Birleştirilmiş Süreç (Unified Process) modeli

Bütün modellerde temel adımlar aynıdır; fark adımların sıralanmasında ve uygulanmasındadır.

### 4.1 Şelale Model

Klasik model, doğrusal akış modeli ya da şelale modeli diye de anılır. Adını şuradan alır: bir adım bitince bir sonrakine dökülür. Adımlar ardışık olarak yapılır, arada geri dönüşler yaşanabilir.

### 4.2 Prototip Model

Şelale modelde müşteri, analiz ve tasarım sırasında sonunda ne elde edeceğini canlandıramaz. Prototip modelde amaç bu canlandırmayı sağlamak için bir prototip geliştirmektir. Bu fark dışında model şelale modele benzer.

### 4.3 Artımlı Model

Artımlı (eklemeli, incremental) modelde yazılım bir bütün olarak yavaş yavaş değil, artımlarla geliştirilir. Ekip önce temel kullanılacak yazılımı, yani çekirdek yazılımı geliştirip kullanıma sunar. Bir yandan da eklemeleri geliştirir ve kullanıma alır.

### 4.4 Spiral Model

Slayttaki şekil spiral modelin evrimsel yazılım geliştirme süreç yapısını gösterir (ekrandan, 01:15:00). Şekildeki bölgeler müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve değişim ile müşteri değerlendirmedir. İçten dışa doğru sarmallar sırasıyla kavram geliştirme projesi, yeni ürün geliştirme projesi, ürün zenginleştirme projesi ve ürün bakım projesidir.

İçteki sarmalda önce bir prototip oluşturulur. Sonra eklemelerle kullanılacak yeni ürün geliştirilir, ardından ürün zenginleştirilir. Bu yüzden spiral model **hem artımlı hem evrimseldir**. Bakım aşamasında da aynı adımlardan sırayla geçilir.

Her sarmaldaki adımlar şunlardır:

- **Müşteri iletişimi:** Geliştirici ile müşteri arasında etkin iletişim; müşterinin ne istediğini anlamak için toplantılar, görüşmeler ve yerinde incelemeler.
- **Planlama:** Proje için zaman, kaynak ve yöntem tanımı.
- **Risk analizi:** Yapılan plan için teknik ve yönetim risklerinin belirlenmesi.
- **Mühendislik:** Yazılım tasarımının oluşturulması.
- **Yapım ve değişim (construction and release):** Gerçekleştirme, test, kurulum ve kullanıcı desteği.
- **Müşteri değerlendirmesi:** Müşterinin ürünü teslim alması ve kabul (onay) testini yapması.

### 4.5 RAD Modeli

RAD modeli iki koşul sağlanınca kullanılır. Birincisi, birden fazla ekip kurmaya yetecek kadar zengin bir yazılım kadrosunun olması ve yazılımın çok hızlı geliştirilmesinin gerekmesidir. Hoca bunun tek başına yeterli olmadığını vurguladı. İkincisi, yazılımın alt modüllere ayrılmaya ve farklı ekiplere modül dağıtmaya uygun olmasıdır.

RAD'de yazılım modüllere ayrılır. Her modülün analizi, tasarımı ve hızlı geliştirilmesi farklı ekiplere verilir ve ekipler aynı anda çalışır. Sonra modüller birleştirilir, test edilir, bütünlük testi yapılır ve yazılım kullanıma alınır.

### 4.6 Birleştirilmiş Süreç Modeli

Unified Process modeli, IBM'in daha sonra satın aldığı ve uzun yıllardır yönettiği Rational Unified Process (RUP) platformunun dayandığı modeldir. Hoca RUP'un yalnız bir CASE aracı değil, bu modele göre çalışan bir platform olduğunu belirtti. Modelde her evrede yapılan işler vardır (planlama, analiz-tasarım, yapım gibi), ancak evrelere farklı adlar verilir. Nesneye yönelik yaklaşımın gereklerini kullanır ve işe kullanım senaryolarını (use case) tanımlayarak başlar.

> **Ek bilgi (derste anlatılmadı):** Unified Process'in evreleri büyük olasılıkla başlangıç (inception), ayrıntılandırma (elaboration), yapım (construction) ve geçiş (transition) adlarıyla anılır. Hocanın "farklı isimler" dediği bu evrelerdir.

## 5. Çevik Yaklaşımlar ve Kalite

Hoca bu bölümde Scrum ile Kanban'ın birbirinden farkına girmeyeceğini, yalnız çevik modellerin kaliteyle ilişkisi üzerinde duracağını söyledi.

Hocaya göre sektörde çevik yaklaşımlar yaklaşık 20 yıldır kullanılıyor; 2000'li yıllarda diğer modellere alternatif olarak, bir tür başkaldırıyla, bir manifestoyla ortaya çıktılar. İlk yıllarda daha çok tanımı üzerinde duruldu; yaklaşık son on yıldır sektörde yaygın olarak kullanılıyor ve pek çok deneyim makalesi yazılıyor.

Slayttaki tanım şöyledir (ekrandan, 01:20:00): Çevik yaklaşımlar, artan müşteri taleplerini daha hızlı karşılamak amacıyla geleneksel sistem geliştirme modellerine alternatif olarak ortaya çıkmıştır. Çevik yaklaşımlar, yazılım geliştirme safhasında geç ortaya çıkan gereksinim değişimlerini çabuk karşılamayı esas alan modellere verilen genel bir isimdir.

### 5.1 Ekstrem Programlama (XP)

Çevik yaklaşımlarda ilk kullanılan model ekstrem programlamadır (eXtreme Programming). XP dört temel değer üzerine kuruludur: **basitlik, iletişim, geri besleme ve cesaret**. Bu değerler etrafında şu uygulamalar vardır:

- Küçük ve kısa aralıklı sürümler (release)
- Basit tasarım: basitlikten kasıt, basit bir tasarımla yola çıkılmasıdır
- Sürekli test
- Sürekli yeniden tasarım (refactoring), yani tasarımda sürekli iyileştirme
- Eşli programlama (pair programming); hocaya göre diğer modellerde pek bulunmaz
- Ortak kod mülkiyeti
- Devam ettirilebilir hız: fazla mesai olmaması hedeflenir

<!-- BELİRSİZ: Slaytta planlama oyunu, sistem metaforu, sürekli tümleştirme, ekip üyesi müşteri ve kodlama standartları gibi başka XP uygulamaları da yazıyor olabilir; slayt yalnız küçük önizlemede görüldü ve tam okunamadı. Altyazıda "... stratejisi oluşturulur" cümlesinin başı da kayıp. -->

### 5.2 Çevik Modellerde Kalite

Geleneksel süreç modellerine göre çevik modellerde kalite şöyle ele alınır:

- **Dinamik kalite değerlendirme, statik değerlendirmeden daha fazla kullanılır.** Yani kalite incelemeden çok testle sağlanır; yazılım doğrudan çalıştırılarak denenir.
- **Kalite işleri sürecin daha erken adımlarında başlar.**
- **Kalite aktiviteleri daha kısa aralıklarla yapılır.**
- **Kullanıcı hikayeleri, birim testler ve müşteri geri beslemesiyle doğruluk ve süreklilik sağlanır.** Müşteri ekibin içine dahil edilir.

### 5.3 Test Güdümlü Yazılım Geliştirme (TDD)

Test güdümlü yazılım geliştirme, çevik yöntemlerin temel özelliklerinden biridir. XP burada yalnız örnek olarak verildi; Scrum ve Kanban'da da TDD stratejisi kullanılır. TDD, yazılım geliştirme araçlarıyla hazırlanmış testler yazılarak ilerleyen, hızlı test temeline dayanan bir metodolojidir. Hoca çevik uygulamalarda TDD'nin hep altta gözetildiğini söyledi.

Slayttaki TDD uygulama basamakları şöyledir (ekrandan, 01:25:00):

1. Birim test case'leri yazmak.
2. Yazılmış test case'lerinin, henüz kod yazılmadığı için başarısız olduğunu görmek için çalıştırmak.
3. Kod yazarak test case'lerin geçmesini sağlamak.
4. Test case'leri tekrar koşturarak geçtiğini görmek.
5. Kodu yeniden düzenlemek.

Hoca bu konuda önceki yıllardan beri pek çok araştırma yapıldığını belirtti. Bir sonraki slaytın önizlemesinde, bir araştırmacının 24 lisans öğrencisiyle önce-test ve sonra-test yöntemlerini karşılaştırdığı, TDD'nin programcı üretkenliğini artırdığı ancak daha iyi kalite sağlamadığı sonucuna vardığı bir çalışma özetleniyor (ekrandan, 01:30:00).

<!-- BELİRSİZ: TDD araştırmasıyla ilgili slayt derste ayrıca okunmadı; bilgi yalnız küçük önizlemeden alındı. -->

## 6. Yazılım Kalitesinin Temel Kavramları ve McCall Üçgeni

Yazılım kalitesi temel kavramları bölümünün hedefleri slaytta şöyle sıralanıyor (ekrandan, 01:30:00):

- Yazılım kalite faktörlerinin anlaşılması
- Yazılım kalite faktörleri modelinin incelenmesi
- Kalite sağlama aktivitelerini özetleme
- Kalite maliyet modellerini anlama
- Geçerleme ve doğrulamanın yazılım kalitesindeki yerini tanımlama

### 6.1 Kaliteli Yazılımın Tanımı

**Kaliteli yazılım, önceden belirlenmiş olan işlevsel gereksinimlere ve yazılım geliştirme standartlarına uygun ve kabul edilebilir hata düzeyinde olan bir yazılımdır.** Bu tanım açılırsa kaliteli yazılım, önceden belirlenmiş işlevleri doğru olarak yerine getiren, gereksinimlere karşılık veren, standartlara uygun olan ve kabul edilebilir hata düzeyinde kalan yazılımdır. Yazılım mühendisliği tanımındaki "kaliteli yazılım" ifadesi budur. Peki işlevsel gereksinimlere ve standartlara uygunluk nasıl anlaşılır? Bunun için McCall modeli kullanılır.

### 6.2 McCall Kalite Üçgeni

McCall üçgeni kalite faktörlerini üç grupta toplar (ekrandan, 01:40:00):

| Grup | Kimin bakış açısı | Kalite faktörleri |
|---|---|---|
| Ürün kullanımı | Kullanıcı | Doğruluk, güvenilirlik, kullanışlılık, bütünlük, etkinlik |
| Ürün geçişi | Ürünü çalıştıran operatörler | Taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik |
| Ürün değişikliği | Bakımı yapan kişiler | Bakım yapılabilirlik, esneklik, test edilebilirlik |

Kullanıcı şunlara bakar: istediğim işi doğru yapıyor mu, bu doğruluğa ne kadar güvenebilirim, uygun mu, bütünlüğü (security) sağlanmış mı, etkin mi, performansı iyi mi?

Ürünün çalıştırılmasından ve sürdürülebilirliğinden sorumlu operatör şunlara bakar: yazılımı başka bir işletim sistemine kolayca aktarabiliyor muyum, yeniden kullanılabilir mi, birlikte çalışabilirliği (interoperability) nasıl?

Değişiklik yapacak kişi ise bakım yapılabilirliğe, esnekliğe ve test edilebilirliğe bakar.

## 7. Yazılım Kalite Özellikleri

Hoca kalite özelliklerini tanımlarıyla tek tek açıkladı (ekrandan, 01:55:00; ilk iki tanım slaytı önizlemede):

- **Doğruluk (correctness):** Spesifikasyonlara uygunluk, müşteri isteklerini karşılama derecesi.
- **Güvenilirlik (reliability):** Tasarlanan işlevleri istenilen duyarlılıkta yerine getirme olanağı. Hoca reliability üzerine pek çok model ve çalışma olduğunu, konunun yazılım kalite yönetimine de girdiğini belirtti.
- **Verimlilik (efficiency):** Programın işlevlerini yerine getirebilmesi için gereken bilgi işlem kaynakları (algoritmanın gerektirdiği bellek, işlem süresi) ve kodlamanın gideri; bunlara maliyetle kıyaslanarak karar verilir.
- **Güvenlik (security):** Yetkisiz kişilerin yazılıma girişinin önlenmesi.
- **Kullanışlılık (usability):** Öğrenme, işletme, girdi hazırlama ve çıktı yorumlamada sağlanan kolaylık.
- **Hata bulma kolaylığı:** Hatanın yerini bulma ve düzeltme olanağı.
- **Esneklik (flexibility):** Yazılımda değişiklik yapma kolaylığı.
- **Sınama yapılabilirlik (testability):** Yazılımın doğruluğunu sınamada kolaylık.
- **Taşınabilirlik (portability):** Yazılımın farklı donanımlarda ve işletim yazılımlarında kullanılma olanağı. Yazılım düşük maliyetle bir sistemden başka bir sisteme taşınabiliyorsa taşınabilirdir.
- **Yeniden kullanılabilirlik (reusability):** Yazılımın tümünün veya bir bölümünün başka bir uygulamada kullanılma olanağı.
- **Birlikte çalışabilirlik (interoperability):** Bir sistemin diğer sistemlerle beraber çalışabilme yeteneği.

Hata bulma kolaylığı, esneklik ve test edilebilirlik bakım yapacak kişiler için önemlidir; taşınabilirlik ise yazılımı işleten kişiler için önemlidir.

Yeniden kullanılabilirlik, hazırlanmış olanı tekrar yazmamak anlamına gelir; güvenilirlik gibi bu konuda da ayrı kitaplar bulunur. Hoca tasarım kalıplarını da yeniden kullanılabilirliğin bir alanı olarak gösterdi: belli bir problemin tasarım çözümü genelleştirilip başka yerlerde de kullanılır. Alana özgü diller ve alan (domain) temelli yaklaşımlarda da yeniden kullanılabilirlik gerçekleştirilir.

Slaytta interoperability "bağlanabilirlik" olarak yazılmış (ekrandan, 01:55:00). Hoca "birlikte çalışabilirlik" teriminin daha uygun olduğunu söyledi. En genel haliyle bu, bir yazılımın çıktısını başka bir yazılıma girdi olarak verebilme ve başka yazılımların çıktılarını girdi olarak kabul edebilme kolaylığıdır.

## 8. McCall Kalite Modeli

Kalite faktörleri genellikle doğrudan ölçülemez. Slayttaki tanıma göre yazılım kalite faktörleri ($F_i$) doğrudan ölçülmez; bazı özelliklere ($m_j$) bağlı birer doğrusal regresyon denklemiyle ya da faktör analiziyle kestirilir (ekrandan, 02:00:00):

$$F_i = c_1 m_1 + c_2 m_2 + \dots + c_n m_n$$

Burada $m_j$ ölçülebilir yazılım özellikleri, $c_j$ ise bunların etkisini gösteren katsayılardır.

<!-- BELİRSİZ: Formül slaytın küçük önizlemesinden okundu; son terimin $c_n m_n$ olduğu ve "diskriminant fonksiyonu" ifadesi önizlemede tam net değil. -->

Modelin şekli her kalite faktörünü ilişkili alt ölçütlere bağlar (ekrandan, 02:00:00). Hocanın anlattığı ve şekilden okunan bağlantılardan bazıları şunlardır:

- **Doğruluk:** izlenebilirlik, tam olma, uyumluluk. Bir yazılımın sonuçları izlenebiliyor mu, istenenlerin hepsi verilmiş mi, çıkan sonuçlar ortamla uyumlu mu?
- **Güvenilirlik:** hata toleransı, doğruluk, uyumluluk.
- **Etkinlik:** çalışma etkinliği, bellek etkinliği.
- **Bütünlük:** erişim kontrolü, erişim denetimi.
- **Kullanılabilirlik:** çalışabilirlik, eğitim, iletişim yapılabilirlik. Kolay çalıştırılabiliyor mu, ne kadar eğitim gerekiyor?
- **Yeniden kullanılabilirlik:** modülerite, genelleştirilebilirlik, yazılım sistemi ve makine bağımsızlığı.
- **Birlikte çalışabilirlik:** modülerite, iletişim genelliği, veri genelliği.

Şekildeki öteki alt ölçütler basitlik, conciseness (özlülük), instrumentation, ifade edilebilirlik ve geliştirilebilirliktir; bunlar bakım yapılabilirlik, test edilebilirlik, esneklik ve taşınabilirlik faktörlerine bağlanır.

<!-- BELİRSİZ: Şekildeki okların bakım yapılabilirlik, test edilebilirlik, esneklik ve taşınabilirlikten hangi alt ölçütlere gittiği karede birbirine karıştığı için tek tek okunamadı. -->

Model çok eskidir ama hâlâ kullanım alanı bulur. Benzer çalışmalar yapılmış olsa da McCall modelinin önemli bir yeri vardır, çünkü çoğu tanımsal olan kalite faktörlerini birkaç ölçülebilir değerle ilişkilendirir.

> **Ek bilgi (derste anlatılmadı):** Model, McCall, Richards ve Walters tarafından büyük olasılıkla 1977'de ABD hava kuvvetleri için hazırlanan bir raporda tanıtılmıştır. Slaytta ve altyazıda adı "Mc Call" ve "Makkol" diye geçer; doğru yazımı McCall'dır.

## 9. Yazılım Kalite Sağlama Aktiviteleri

Kaliteyi sağlamak için hata ve eksiklerin bulunması ve düzeltilmesi, özellikle de erken bulunup düzeltilmesi önemlidir. Bir basamakta yapılan hata sonraki basamakları da etkiler. Sonraki basamaklarda bu hatanın bulunma olasılığı azalır. Bu yüzden gözden geçirme yapmak çok önemlidir.

Kitaplar kalite aktivitelerini farklı biçimlerde ayırır: yazılımın hazırlanması sırasında, hazırlandıktan sonra ve kullanım aşamasında yapılanlar; ya da daha genel olarak teslim öncesi ve teslim sonrası. Teslim öncesinde hatayı bulmak önemlidir, çünkü düzeltme yalnız geliştirici ekip içinde kalır. Teslim sonrasında bulunan hata, ekibin müşteri gözündeki güvenini de kaybettirir ve daha büyük gider getirir.

Slayttaki kalite sağlama aktiviteleri şunlardır (ekrandan, 02:05:00):

- Standartlar
- Geçerleme ve doğrulama (verification / validation)
- Gözden geçirme ve denetim (reviews and audits)
- Test
- Hata / kusur analizi (error / defect)
- Değişim yönetimi, konfigürasyon yönetimi
- Eğitim
- Risk yönetimi

**Standartlar:** Yazılımın kaliteli olması için kurum içinde hangi standartların kullanılacağı belirlenmelidir.

**Verification ve validation:** Hoca ikisini şöyle ayırdı:

- **Verification (doğrulama):** Yazılımı doğru yolla üretiyor muyuz? Hazırlama sürecimiz doğru mu?
- **Validation (geçerleme):** Doğru yazılımı, yani istenen yazılımı ürettik mi?

İkisi de önemlidir ve test sürecinde her ikisi dikkate alınarak yapılan test işlemleri vardır.

**Gözden geçirme ve denetim:** Test, hataları daha teknik olarak bulur. Ancak hataları gözden geçirmeyle daha önceki adımlarda bulmak daha uygundur.

**Teslim aşaması ve sonrası:** Konfigürasyon yönetimi yapmak, eğitim vermek ve risk yönetimi gerçekleştirmek de kaliteyi sağlar. Konfigürasyon yönetimiyle bütünleşik görülebilen **sürüm yönetimi** (release management) de bir kalite sağlama aktivitesidir: yeni sürüm uygun zamanda ve uygun şekilde kullanıma alınır.

### 9.1 Geliştirme Sürecinde Kaliteyi Yükseltmek

Hoca, geliştirme sürecinin her adımında kaliteyi yükseltmek için yapılacakları anlattı:

- **Gereksinim analizi:** Sistemin kolayca kullanılıp öğrenilir olması için çaba gösterilir. İstenmeyen senaryolar daha gereksinim analizinde planlı olarak ele alınır.
- **Modüllere ayırma:** Modüller kalite göz önünde tutularak bölümlenir. Modül tanımları taşınabilirlik ve birlikte çalışabilirlik dikkate alınarak yapılır. Modül bağımsızlığı için modüller arası ilişki (coupling) sıfırlanamasa da en aza indirilir; modül içi tutarlılık (cohesion) artırılır.
- **Nesneye yönelik yaklaşım:** Modül kavramı klasik yazılım geliştirmede tanımlanır. Nesneye yönelik yaklaşımda aynı fikir sınıf yapısında görülür: sınıf içi kuvvet yüksek, sınıflar arası ilişki zayıf olmalıdır. Kohezyon ve kaplin kavramları CK metriklerinde de yer alır.
- **Test aşaması:** Doğruluğun yanında performans gibi kalite faktörlerine ve sistemle ilgili özelliklere de önem verilir. Gereksinim analizinde tanımlanan işlevsel olmayan gereksinimlerin de karşılanıp karşılanmadığı test sırasında sınanır.

<!-- BELİRSİZ: Ayrıntılı tasarım adımında ne yapılacağı altyazıda soru olarak kalmış; slayt önizlemesinde "doğruluk faktörüne ağırlık verilmesi" gibi bir madde görünüyor ama tam okunamadı. -->

## 10. Yazılım Kalite Maliyeti

Kalite aktiviteleri bazı kaynaklarda üçe ayrılır: hatayı önleme, hatayı bulma ve düzeltme, kullanım sırasında yapılanlar. Kaliteyi baştan sağlamanın (hata önleme) maliyeti, sonradan sağlamaya çalışmanın (hata bulma ve düzeltme) maliyetinden azdır.

Slayttaki değerlere göre bir yazılım hatasını düzeltme maliyeti şöyledir (ekrandan, 02:15:00):

| Aşama | Düzeltme maliyeti |
|---|---|
| Gereksinim analizi | 0.2 |
| Tasarım | 0.5 |
| Birim testi | 2 |
| Kabul testi | 5 |
| Bakım süreci | 20 |

Hoca bu maliyetlerin doğrusal artmadığını vurguladı. Ardışık aşamalar arasındaki oranlar sırasıyla $0.5/0.2 = 2.5$, $2/0.5 = 4$, $5/2 = 2.5$ ve $20/5 = 4$'tür (ara adım eklendi). Gereksinim analizinde 0.2 olan maliyet bakımda 20'ye çıkar, yani $20/0.2 = 100$ katına ulaşır (ara adım eklendi).

Hoca yazılım mühendisliği ve sistem analizi derslerinden tanıdık bir şekli tekrarladı: süreç ilerledikçe **hata bulma gideri artar**, çünkü daha fazla yazılımcı emeği gerekir; **hata bulma olasılığı ise düşer**, yani hata bulmak zorlaşır. Demek ki hatayı önlemeye daha çok çalışmak gerekir. Hoca son zamanlarda birçok sektördeki firmanın bunu dikkate almaya başladığını gözlemlediğini söyledi. Gözden geçirme de kademe kademe artırılır: review formal olmayan gözden geçirmedir, inspection daha formal bir incelemedir.

Slayta göre hata önleme maliyeti şu işlerden oluşur (ekrandan, 02:15:00):

- Kalite planlama
- Formal ve teknik gözden geçirme
- Test oluşturma (test planları, test case'leri ve senaryoları)
- Eğitim

**İç hata maliyeti**, yazılımın kullanıma alınmasından önce bulunan hataların maliyetidir; bu hatalar yazılım ekibi içinde kalır. **Dış hata maliyeti** ise yazılımın kullanımından sonra ortaya çıkan hatanın düzeltilme maliyetidir. Düzeltme gideri benzer olsa da dış hatada kurumun ve yazılım ekibinin müşteri karşısında güvenilirliğini kaybetmesi gibi önemli bir ek maliyet vardır.

Önizlemedeki bir slaytta iç ve dış hata maliyetlerini dallandıran bir kalite maliyet modeli şekli de vardı. Hoca ekonomi tarafına bu kadar girmek istemediğini söyleyerek bu şekli geçti.

## 11. Yazılım Mühendisliği Standartları

Kalite sağlama aktivitelerinin ilki standartlardır. Slayta göre yazılım mühendisliği standartları **yazılım geliştirme aşamasına, kaynağına ve değerlendirme ölçütünün tipine göre** üç ayrı biçimde sınıflandırılır (ekrandan, 02:20:00).

### 11.1 Standart Kaynakları

Hoca standart kaynaklarına örnek istedi. Bir öğrenci CMMI'ı önerdi. Hoca CMMI'ın bir sertifikasyon, yani yazılım evlerini sertifikalandırma sistemi olduğunu belirtti. Ardından kaynakları sıraladı:

- **IEEE:** Yazılım standartları yayımlar; standartlar numarayla belirtilir.
- **ISO:** Hoca derslerde en çok ISO ve IEEE standartlarını kullandığını, ISO 9001'in yazılım mühendisliğiyle ilgili geliştirmeleri verdiğini söyledi.
- **DoD (Department of Defense):** Çok genel standartlar.
- **IEC**
- **ASTM**

> **Ders sonrası not:** Hoca ISO'yu "Ulusal Standartlar Organizasyonu" diye andı. ISO büyük olasılıkla Uluslararası Standardizasyon Örgütü'dür (International Organization for Standardization). ISO 9001 de büyük olasılıkla yazılıma özgü değil, genel bir kalite yönetim sistemi standardıdır; yazılıma uygulanması için ayrı bir rehber (ISO/IEC 90003) vardır.

### 11.2 Aşamaya Göre Standartlar

IEEE ve DoD standartları yazılım geliştirme adımlarına göre de tanımlanmıştır: proje yönetimi, gereksinim tanımı, tasarım, kodlama, güvenlik ve geçerlilik, konfigürasyon yönetimi, kalite güvencesi (ekrandan, 02:20:00, önizleme). Örneğin proje yönetimi standardı proje planının hazırlanması ve izlenmesi için yol gösterir. Gereksinim tanımı için SRS belgesinin nasıl hazırlanacağını anlatan IEEE standardı, tasarım için yazılım tasarım belirtimi (Software Design Specification) standardı vardır. Her standardın bir numarası ve son güncelleme tarihi bulunur; bunlar IEEE sayfasında görülebilir, ancak son sürümlere erişim ücretli olabilir. Her aşama için tek değil, birden fazla standart vardır; bir planın ya da bir raporun nasıl yazılacağı için ayrı standartlar hazırlanmıştır.

### 11.3 Süreç Temelli ve Ürün Temelli Standartlar

Hoca yazılım standartlarının çoğunlukla **süreç temelli** olduğunu vurguladı. Bu standartlar yazılım geliştirme sürecinin (proje yönetimi, gereksinim tanımı, tasarım, kodlama) nasıl yapılması gerektiğini ve bu süreçte elde edilecek belgelerin hangi içerikle hazırlanacağını anlatır. Ürün standartları da vardır, ama daha azdır.

Yazılım dışındaki alanlarda ise standartlar genellikle ürünün tanımıdır. Hoca örnek olarak bir ağ kablosunun yapısını ve fiziksel özelliklerini tanımlayan standartları verdi. Yazılım standartlarında ise süreç anlatılır; kod ve ürünle ilgili özellikler daha azdır.

## 12. Yazılım Kalite Yönetim Sistemi

Slayttaki tanıma göre kalite yönetim sistemi, yazılım ürünlerinin istenen kalite faktörlerine sahip olmasını sağlayan, geliştirici ve kullanıcının birlikte belirlediği yönetim yapısı, sorumluluklar, etkinlikler, yetenekler ve kaynaklardan oluşur (ekrandan, 02:25:00). Hoca kurumlarda kalite yönetim sistemlerinin ve kalite bölümlerinin kurulmaya başladığını belirtti.

### 12.1 Standartlar, Kurum ve Proje İlişkisi

Standartlar, kalite yönetim sistemi ve projeler arasındaki ilişki slayttaki şekilde gösteriliyor. Hoca bunu şöyle özetledi:

```text
Genel standartlar (ISO 9001, IEEE, DoD, ...)
        |
        v
Kurumun kalite yönetim sistemi  -->  Kalite el kitabı
        |
        +--> A projesinin standartları (kurum standartları + projeye özgü ekler)
        +--> B projesinin standartları
        +--> ...
```

<!-- BELİRSİZ: Şekil yalnız küçük önizlemede görüldü; yukarıdaki yapı hocanın sözlü anlatımından kuruldu. -->

Bir kurum kendi kalite yönetim sistemini kurarken genel standartlardan hangilerini kendi bünyesinde geçerli kılacağını seçer. Bunu bir **kalite el kitabında** anlatır: hangi standartların kullanılacağı, genel standartların kurum için nasıl özetlendiği ve kalite kontrollerinin nasıl yapılacağı. Her proje kurum standartlarını alır; projeye özgü eklenecek standartlar varsa projenin başında bunları da ekler.

### 12.2 Kalite Güvencesi Planı

Kalite güvencesi için bir plan oluşturulur. Plan; geliştirilecek yazılım ürününün kalite etkenlerinin nasıl kapsanacağını, kalite kontrolünün nasıl yürütüleceğini, ne zaman ve kim tarafından uygulanacağını, CASE desteği alınıp alınmayacağını ve hangi aşamalarda kullanılacağını belirtir.

### 12.3 Yazılım Kalite Yönetimi

Slayta göre yazılım kalite yönetimi şunlarla yapılır (ekrandan, 02:30:00):

- Standartlar
- Yazılım geliştirme süreç modelleri
- Ölçüm yöntemleri
- Konfigürasyon yönetimi
- Doğrulama ve geçerleme

Bunlar kalitenin güvence altına alınması, yazılım sisteminin yüksek bir kalitede geliştirilmesi ve ölçüm yoluyla kalite derecesinin belirlenmesi yollarıyla sağlanır. Hoca her aşamada o aşamanın işlerini kalite hedefiyle birlikte düşünmek gerektiğini vurguladı: standartlar belirlenir, bir süreç modeli seçilip uygulanır (yani daha tanımlı ilerlenir), ölçüm yöntemleri kullanılır, konfigürasyon yönetimi yapılır ve her adımda doğrulama ile geçerleme yapılır.

Kaliteyi sağlama aktivitelerinden standartlar ve süreç modelleri görüldü. Üçüncü aktivite olan gözden geçirme (gözden geçirme nedir, inceleme nedir, aralarındaki fark nedir) sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:39:58): Mühendislik alanının iki temel aracı ya da gereği nedir?

> **Çözüm (derste verildi):** Ölçme (ölçülebilirlik) ve tasarım. Bir mühendislik dalının altında ölçme işi bulunur; mühendislik bir işe hemen başlamak değil, önce iyi bir tasarım yapmaktır.

**Soru 2** (derste sözlü, 02:17:00): Yazılım mühendisliği standartlarının kaynaklarına örnek verin.

> **Çözüm (derste verildi):** IEEE, ISO, DoD (Department of Defense), IEC ve ASTM. CMMI bir standart kaynağı değil, yazılım evlerini sertifikalandırma sistemidir.

**Soru 3** (derste sözlü, 02:19:30): ASTM'nin açılımı nedir?

> **Çözüm (derste verilmedi):** Cevap kayıtta duyulmuyor. ASTM büyük olasılıkla American Society for Testing and Materials'ın kısaltmasıdır (bugünkü adı ASTM International).

**Soru 4** (ekrandan, 02:15:00): Bir hatayı düzeltme maliyeti gereksinim analizinde 0.2, bakım sürecinde 20 ise, hata gereksinim analizi yerine bakımda bulunduğunda düzeltme maliyeti kaç katına çıkar? Maliyet artışı doğrusal mıdır?

> **Çözüm (derste verilmedi):** $20 / 0.2 = 100$ kat. Ardışık aşamalar arasındaki oranlar 2.5, 4, 2.5, 4'tür; artış doğrusal değildir (python ile kontrol edildi).

## Dersin Toparlaması

Bu derste önce dersin kapsamı tekrar edildi, ardından yazılım mühendisliğinde kalitenin yeri ele alındı. Yazılım mühendisliği, kaliteli yazılımı en ekonomik biçimde, ölçme ve tasarıma dayanan mühendislik yöntemleriyle elde etmeye çalışır. Katmanlı yapının temelinde kalite bakış açısı vardır; süreçler, yöntemler ve araçlar bunun üzerine kurulur. Klasik süreç modelleri (şelale, prototip, artımlı, spiral, RAD, Unified Process) özetlendi. Çevik yaklaşımların kaliteye bakışı dinamik değerlendirmeye, erken ve sık kalite işlerine ve test güdümlü geliştirmeye dayanır.

Dersin ikinci yarısında kaliteli yazılımın tanımı, McCall üçgeni ve kalite özellikleri, kalite faktörlerini ölçülebilir özelliklere bağlayan McCall kalite modeli, kalite sağlama aktiviteleri, hata düzeltme maliyetinin aşamalara göre doğrusal olmayan artışı, yazılım mühendisliği standartları ve kurumların kalite yönetim sistemi işlendi. Sonraki derste kalite sağlama aktivitelerinden gözden geçirme ve inceleme, aralarındaki farkla birlikte ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
