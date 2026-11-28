# Ders 10 Genişletilmiş Notu: Yazılım Kalitesi ve Test, JUnit ile Birim Test, Yazılım Ölçümü ve Risk Yönetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Mühendisliğinde Kalite Bakış Açısı
- 2. Yazılım Kalite Faktörleri ve McCall Modeli
- 3. Kaliteyi Sağlama Aktiviteleri ve Hata Maliyeti
- 4. Doğrulama, Geçerleme ve V Model
- 5. Test Adımları: Birim, Bütünleme, Sistem ve Onaylama Testi
- 6. JUnit ile Birim Test Uygulaması
- 7. Yazılım Proje Yönetimi
- 8. Yazılım Ölçümü: LOC ve İşlev Noktası
- 9. Yazılım Risk Yönetimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Mühendisliğinde Kalite Bakış Açısı

Ders, yazılım kalitesi ve test konusuyla başlar; ardından birim test uygulamasına, proje yönetimine, yazılım ölçümüne ve risk yönetimine geçilir.

### 1.1 Katmanlı yapı

Yazılım mühendisliğinin katmanlı bir yapısı vardır. Slayttaki şekilde alttan üste dört katman görülür (ekrandan, 00:10:00):

- Kalite bakış açısı (en altta, temel)
- Süreçler
- Yöntemler
- Yazılım araçları (en üstte)

Yazılım mühendisliği ilk derslerde, yazılım geliştirme çalışmalarının mühendislik temellerine uygun yürütülmesini sağlayan bilim dalı olarak tanımlanmıştı. Bu tanımdan üç soru çıkar:

- Kaliteli yazılımı nasıl ifade eder ve elde ederiz? Bu, **kalite yönetiminin** konusudur.
- Kaliteli yazılımı en ekonomik biçimde nasıl elde ederiz? Bunun cevabı **yazılım proje yönetimi** kısmında verilir.
- Bunu mühendislik yaklaşımıyla nasıl gerçekleştiririz? Mühendislik yaklaşımının iki temel öğesi **ölçme** ve **tasarım**dır. Tasarım ve modelleme, gereksinim analizi ve yazılım tasarımı konularında anlatılır. **Yazılım ölçümü** (*software metrics*) ise hem proje yönetiminin hem kalite yönetiminin alt başlıkları arasındadır.

Hoca, "mühendis" sözcüğünün "hendese"den geldiğini ve mühendisin ölçmeyi gerçekleştiren kişi olarak tanımlandığını hatırlatır.

Kalite bakış açısıyla kaliteli bir yazılım geliştirmek için formal bir süreç tanımı, o sürece uygun bir yöntem ve bunları destekleyen bir yazılım aracı gerekir.

### 1.2 CASE araçları

Hoca sınıfa CASE kavramını sorar. Açılımı *Computer Aided Software Engineering*'dir (bilgisayar destekli yazılım mühendisliği).

**Soru:** CASE nedir? **Cevap (bir öğrenci):** Yazılım geliştirme için üst düzey bir araç. **Hocanın tamamlaması:** Yazılım geliştirme sürecinde çalışanlara destek olan bir yazılım aracıdır.

CASE aracı farklı ölçeklerde olabilir:

- Yalnız analiz ve tasarım aşamasında diyagram çizimini destekleyen küçük bir araç. Böyle bir araç diyagram çizimini kolaylaştırır, standartlaştırır ve analizden tasarıma geçişte kontrol sağlar.
- Proje planından test aşamasına kadar bütün süreci yöneten ve destekleyen bir platform. Bunlara **bütünleşik CASE araçları** denir.

Örnek olarak Rational Rose verilir: daha önce bütünleşik bir CASE aracı olarak tanımlanıyordu, IBM tarafından satın alındıktan sonra bir platform haline geldi.

## 2. Yazılım Kalite Faktörleri ve McCall Modeli

### 2.1 McCall kalite üçgeni

Pek çok kalite modeli vardır; ISO 9126 standardı da yazılım kalite özelliklerini anlatır. Derste kullanılan McCall modeli kalite özelliklerini üç bölüme ayırır ve kalite özellikleri ile yazılım ölçütleri arasında ilişki kurarak onları daha sayılabilir, hesaplanabilir hale getirir. Slayttaki "McCall Kalite Üçgeni" şöyledir (ekrandan, 00:15:00):

| Bakış açısı | Kimin için | Kalite faktörleri |
|---|---|---|
| Ürün kullanımı (üçgenin tabanı) | Kullanıcı | Doğruluk, güvenirlik, kullanışlılık, bütünlük, etkinlik |
| Ürün değişikliği (sol kenar) | Bakım yapan yazılım mühendisleri | Bakım yapılabilirlik, esneklik, test edilebilirlik |
| Ürün geçişi (sağ kenar) | Yazılımı taşıyan ve çalıştıran | Taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik |

Kullanıcı açısından sorulan sorular şunlardır: Yazılım istediğimiz işi doğru yapıyor mu? Doğru yapıyorsa yüzde kaç hatayla, hata sınırı ne? Kullanıcı formları ve menüleri rahat kullanabiliyor mu? Güvenlik sorunu var mı? Hem veritabanı hem program cevap süresi açısından performans yeterli mi?

Ürün geçişi açısından: yazılım bir işletim sisteminden diğerine aktarılabiliyor mu, bütünü ya da bir kısmı başka bir yazılımda kullanılabiliyor mu, başka yazılımlarla veri alışverişi yapabiliyor mu?

### 2.2 Kalite özelliklerinin tanımları

- **Doğruluk** (*correctness*): spesifikasyonlara uygunluk ve müşteri isteklerini karşılama derecesi.
- **Güvenirlik** (*reliability*): tasarlanan işlevleri istenen duyarlılıkta yerine getirme olanağı, yani yazılımın ne kadar hatasız çalıştığı.
- **Güvenlik / bütünlük** (*security, integrity*): yetkisiz kişilerin yazılıma ve veriye girişini engelleme olanağı.
- **Kullanışlılık** (*usability*): öğrenme, çalıştırma, girdi hazırlama ve çıktı yorumlama kolaylığı.
- **Etkinlik** (*efficiency*): veritabanı ve program cevap performansı.

Bunların hepsi kullanıcı için önemli özelliklerdir. Bakım yapacaklar için:

- **Hata bulma kolaylığı**: hatanın yerini bulma ve düzeltme kolaylığı.
- **Esneklik** (*flexibility*): yazılımda değişiklik yapma kolaylığı.
- **Test edilebilirlik** (*testability*): yazılımın doğruluğunu sınamadaki kolaylık.

Çalıştıranlar için:

- **Taşınabilirlik** (*portability*): farklı donanımlarda ve işletim sistemlerinde çalışma özelliği.
- **Yeniden kullanılabilirlik** (*reusability*): yazılımın tümünün ya da bir bölümünün başka bir uygulamada kullanılabilme olanağı.
- **Birlikte çalışabilirlik** (*interoperability*): bir sistemin diğeriyle birlikte çalışabilme olanağı, yani kurumdaki diğer yazılımlara veri gönderip onlardan veri okuyabilmesi.

### 2.3 McCall yazılım kalite modeli

McCall modelinde yazılım kalite faktörleri doğrudan ölçülemez. Slayttaki ifade şöyledir (ekrandan, 00:20:00): yazılım kalite faktörleri ($F_i$) doğrudan ölçülmeyip, ancak bazı özelliklere ($m_i$) bağlı birer doğrusal regresyon denklemi

$$F_i = c_1 m_1 + c_2 m_2 + c_3 m_3$$

biçiminde ya da faktör analizi (diskriminant fonksiyonu) ile kestirilebilir. Yani herhangi bir kalite faktörü, farklı ölçütlerin farklı katsayılarla ağırlıklandırılmış toplamı olarak hesaplanır.

Modelin şeklinde sol tarafta kalite faktörleri (daha tanımsal bilgiler), sağ tarafta sayısal olarak hesaplanabilen ölçütler vardır ve aralarında eşleştirme yapılır. Derste anlatılan eşleşmeler:

- Doğruluk ↔ izlenebilirlik, tamlık, uyumluluk
- Güvenirlik ↔ uyumluluk, hata toleransı
- Etkinlik ↔ çalışma etkinliği, bellek etkinliği
- Bütünlük ↔ erişim kontrolü, erişim denetimi

<!-- BELİRSİZ: McCall eşleşme diyagramının (slayt 7) tamamı karede okunamadı; yalnız sözlü anlatılan eşleşmeler yazıldı. -->

Güvenirlik için istatistiğe dayanan modeller kullanılır: yazılım belirli bir süre çalıştığında kaç hata çıktığı ve bunların ne kadarının düzeltilebildiği gibi değerlerden hesap yapılır.

## 3. Kaliteyi Sağlama Aktiviteleri ve Hata Maliyeti

### 3.1 Kalite sağlama aktiviteleri

Kalite özelliklerini anladıktan sonra soru şudur: bu kaliteyi sağlamak için ne yapacağız? Yazılım kalitesini sağlama aktiviteleri:

- Standartları kullanmak
- Doğrulama ve geçerleme (*verification, validation*)
- Gözden geçirme ve denetim (*review, audit, inspection*); inceleme (*inspection*) gözden geçirmenin daha ayrıntılı biçimidir
- Test
- Hata/kusur analizi
- Değişim yönetimi (konfigürasyon yönetimi)
- Risk yönetimi
- Kullanıcılara eğitim

### 3.2 Hatanın bulunma zamanı ve maliyeti

Sistem analizi dersinden de bilinen bir diyagrama göre yazılım geliştirme süreci ilerledikçe hatayı bulma olasılığı düşer, hatayı bulma ve düzeltme gideri ise artar. Bu yüzden hata bulma sürecin başına çekilmelidir. Bunun yolu, kalite sağlama aktivitelerinden gözden geçirme ve denetimleri sık yapmaktır: her ara ürün (*artifact*) için bir gözden geçirme yapılmalıdır.

Slayt küçük resminde yazılım hatalarını düzeltme maliyetinin gereksinim analizinde 0,2, tasarımda 0,5, birim testte 2, kabul testinde 5, bakım sürecinde 20 olduğu yazmaktadır (ekrandan, 00:25:00). <!-- BELİRSİZ: Bu oranlar slayt küçük resminden okundu, derste sözlü anlatılmadı. -->

### 3.3 Hata önleme maliyeti

Slayttaki "Hata önleme maliyeti" kalemleri (ekrandan, 00:25:00):

- Kalite planlama
- Formal ve teknik gözden geçirme
- Test oluşturma
- Eğitim

**İç hata maliyeti**, yazılımın kullanıma alınmasından önce; **dış hata maliyeti** ise yazılımın kullanımından sonra ortaya çıkan hatanın düzeltilme maliyetidir. Ürün satıldıktan ve başka firmalar kullanmaya başladıktan sonra hata çıkarsa yalnız düzeltme maliyeti doğmaz, yazılım kullanımda olduğu için bir **güven eksikliği maliyeti** de gelir. Bu yüzden en doğrusu hatayı kullanıma almadan, iç hata maliyeti olarak düzeltmektir.

### 3.4 Yazılım mühendisliği standartları

Yazılım geliştirme sürecindeki her adımın nasıl yapılacağını anlatan standartlar vardır, örneğin IEEE standartları. Daha önce gereksinim analizi raporunun (SRS) nasıl hazırlanacağını belirten standart verilmişti. <!-- BELİRSİZ: SRS standardının numarası altyazıda kesik. --> Bunun yanında tasarım, güvenlik, geçerleme, konfigürasyon yönetimi ve kalite güvencesi standartları vardır; çalışmalar bu standartlar çerçevesinde yürütülür.

## 4. Doğrulama, Geçerleme ve V Model

### 4.1 Doğrulama ve geçerleme

Türkçede iki terim eş anlamlı gibi durur ama ders kapsamında şu karşılıklar kullanılır:

- **Doğrulama** (*verification*): Yazılımı doğru yolla mı ürettik? Ürünün gelişimini doğru yapıyor muyuz, gittiğimiz yol doğru mu?
- **Geçerleme** (*validation*): Doğru yazılımı, yani kullanıcıların istediği yazılımı mı ürettik?

> **Hocanın vurgusu:** Esasını İngilizcesiyle düşünün; Türkçede daha çok karışıyor.

**Soru:** Bu slaytta en üstteki eşleşme "doğrulama" değil "geçerleme" olacaktı, değil mi? **Cevap:** Evet, geçerleme olacak; iki terim yer değiştirecek. Hoca slaydı ders sırasında düzeltti.

### 4.2 V model yaklaşımı

V modelde yazılım geliştirme adımları sol kolda yukarıdan aşağı, test adımları sağ kolda aşağıdan yukarı ilerler ve her test adımı karşısındaki geliştirme adımına karşılık gelir. Düzeltilmiş slayttaki şekil (Şekil 3.2, "Yazılım geliştirme ve test sürecindeki geçerleme ve doğrulama aktiviteleri") şöyledir (ekrandan, 00:35:00):

| Geliştirme adımı (sol kol) | Eşleşme etiketi | Test adımı (sağ kol) |
|---|---|---|
| Müşteri gereksinimleri | Geçerleme | İşlemsel kullanım (kullanıcı testi) |
| Ürün spesifikasyonu | Geçerleme/Doğrulama | Sistem testi |
| Yüksek düzey tasarım | Doğrulama | Bütünlük testi |
| Alçak düzey tasarım | Doğrulama | Bileşen testi |
| Kodlama ve birim test (V'nin dibi) | | |

Şeklin sol tarafında, kodlamadan müşteri gereksinimlerine geri dönen kesikli bir ok "Yazılım Geliştirme G/D Aktiviteleri" diye etiketlenmiştir. Slaytın ilk halinde (ekrandan, 00:30:00) üst eşleşme "Doğrulama", alt iki eşleşme "Geçerleme" yazıyordu; hoca bunları yer değiştirdi.

Geliştirme adımları sırasıyla: müşteri gereksinimleri alınır, gereksinim analizinden sonra ürün spesifikasyonu çıkarılır, yüksek düzey tasarım (genel tasarım, mimari tasarım) ve alçak düzey tasarım (algoritmalar, veritabanı tasarımı gibi ayrıntılı tasarım) yapılır, sonra kodlama gelir. Test bu adımlara paralel ve karşıt olarak kurulur: kodlamadan hemen sonra birim test, sonra bileşen testi, bütünlük testi, sistem testi ve kullanıcı testi.

Eşleşmelerin anlamı:

- **Kullanıcı testi** müşteri gereksinimlerinin sağlanıp sağlanmadığını değerlendirir.
- **Sistem testi** ürün spesifikasyonunu, özellikle gereksinim analizinde belirtilen işlevsel olmayan gereksinimlerin (*non-functional requirements*) doğru gerçekleştirilip gerçekleştirilmediğini sınar.
- **Bütünlük testi** yazılımın mimari tasarıma uygun geliştirilip geliştirilmediğine bakar.
- **Bileşen testi** alçak düzey tasarımda verilen algoritmaların ve veritabanı tasarımlarının doğru gerçekleştirilip gerçekleştirilmediğine bakar.

Geliştirme sırasında bir adımdan diğerine geçerken de gözden geçirme yapılır; hatayı önlemek için aralarda gözden geçirme ve denetim şarttır. Ayrıca belirli bir yazılım geliştirme süreç modeli seçilir ve ona uyulur.

### 4.3 Gözden geçirme ve inceleme

Gözden geçirme (*review*) yazılım geliştirme sürecinin her adımında yapılır. Örneğin bir kod ya da tasarım belgesi oluşturulduğunda daha ayrıntılı bir inceleme (*inspection*) de yapılabilir. Yazılım kalitesini sağlama aşamasında bu, genel bir inceleme (review) ya da daha ayrıntılı inceleme (inspection) biçiminde görülür.

## 5. Test Adımları: Birim, Bütünleme, Sistem ve Onaylama Testi

Test, bir programdaki hataları bulmak amacıyla yapılır. Yazılımın gereksinim analizinde verilen işlevsel özellikleri açısından sınanmasını; performansı, dayanıklılığı ve yapısal özellikleri bakımından incelenmesini gerektirir.

### 5.1 Birim test

Birim test, kodlamadan hemen sonra yapılan, en alttaki test adımıdır. Yazılım tasarımının en küçük birimi olan **modül** üzerinde uygulanır. Ayrıntılı tasarım tanımlarına dayanarak modül içindeki hataları bulmak için önemli kontrol yolları test edilir. **Saydam kutu testi** olarak uygulanan bu işlem çok sayıda modül üzerinde paralel olarak yürütülür.

**Soru (hocanın sınıfa sorusu):** Birim testi kim yapar? **Cevap (bir öğrenci):** Kodu geliştiren. **Hoca:** Evet; bu yüzden V modelde kodlama ve birim test aynı kutuya yazılmıştır. Kodlamayı yapan kişi birim testi de gerçekleştirir; ardından varsa bileşen testi, sonra bütünlük, sistem ve kullanıcı testi gelir.

Birim testin kavramları (ekrandan, 00:40:00, slayt küçük resmi ve sözlü anlatım):

- **Test sürücü** (*test driver*): test programı verisini alarak test edilecek modüle ileten ve test sonucunu yazan ara program. Modül kendi başına çalışmıyor, başka bir modül tarafından yönlendiriliyorsa test sürücü o çağıran modülü örnekler.
- **Koçan** (*stub*): bir kukla (*dummy*) alt programdır; test edilen modülün henüz test edilmemiş ya da hazır olmayan alt programını temsil eder.

Birim testin yapısını gösteren şekilde ortada test edilen birim vardır. Test sürücü test verisini (test programını) test edilen birime aktarır ve sonuçları ortaya koyar. Test edilen modülün çağırdığı modüllerin yerine geçen Koçan 1, Koçan 2, ..., Koçan N bulunur. <!-- BELİRSİZ: Birim test yapısı şekli karede görülmedi; sözlü anlatımdan kuruldu. -->

### 5.2 Bütünleme (bütünlük) testi

Slayttaki tanım (ekrandan, 00:40:00): modüller bağımsız olmayıp birbirlerine bağlıdır; bu bağlantı "yazılım arabirimi" (*software interface*) ile sağlanır. Modüllerin birleştirilmesi sırasında şu sorunlar söz konusudur:

- Veri kaybı
- Dikkatsizlik nedeniyle birbirini ters etkileme
- Alt fonksiyonların birleştirilmesiyle beklenen ana fonksiyonun gerçekleşmemesi
- Her birinde göze alınabilen hata toleranslarının eklenerek büyümesi
- Genel veri yapılarının sorun yaratması

Bu hataları bulup gidermek için modüller birleştirilerek ana program oluşturulurken bütünleme testi uygulanmalıdır. Kısacası modüller tek tek doğru çalışıyor olabilir, ama birlikte de doğru çalışıp çalışmadıkları görülmelidir.

Bütünleme testi üç biçimde yapılabilir: bütün olarak sınama, artırmalı sınama ya da ikisi birden. Bütün olarak sınamak daha zordur, artırmalı sınama daha iyidir. Artırmalı sınamada yukarıdan aşağıya mı aşağıdan yukarıya mı gidileceğine karar verilir.

Hoca yukarıdan aşağı bütünlemede alttaki modüllerin koçan gibi göründüğünü ve test sürücüsü kullanıldığını anlatır; ardından alt birimlerin oluşturulduğu bir örnek verir: önce modül 2, 3 ve 4 test edilmiş olmalıdır, bunlar bir blok oluşturur ve modül 8'e aktarılır. <!-- BELİRSİZ: Modül numaralı bütünleme şekli karede görülmedi. -->

> **Ders sonrası not:** Anlatımda iki yaklaşım karışmış görünüyor. Büyük olasılıkla standart ayrım şöyledir: yukarıdan aşağı bütünlemede üst modülden başlanır ve henüz eklenmemiş alt modüllerin yerine **koçan** kullanılır; aşağıdan yukarı bütünlemede alt modüller kümeler (bloklar) halinde birleştirilir, bu kümeleri çalıştırmak için **test sürücü** kullanılır ve kümeler üst modüle aktarılır. Modül 2, 3, 4'ün bir blok oluşturup modül 8'e aktarılması aşağıdan yukarı yaklaşımın örneğidir.

### 5.3 Regresyon testi

Bütünlük testi yapıldıktan sonra alttaki bazı modüllerde değişiklik olmuşsa test tekrarlanmalıdır. Alttaki değişikliğin sistemi ne kadar etkilediğini görmek için bütünlük testinin tekrar edilmesine **regresyon testi** denir.

### 5.4 Sistem testi

Birim ve bütünlük testleriyle yazılımın doğru çalıştığı kanıtlanmıştır. Ancak yazılım tek başına çalışmaz: bir işletim sistemi üzerinde, veritabanı yönetim sistemiyle ve başka yazılımlarla etkileşim içinde çalışır. Sistem testi, yazılım alt sisteminin bilgisayar sistemi içinde denetlenmesi, işletim sistemiyle uyumunun ve etkileşiminin denenmesidir. Slayttaki sistem testi türleri (ekrandan, 00:45:00):

- **Güvenlik testi**: sistemin zararlı dış müdahalelerden ve bilgi hırsızlığından korunabildiğinin kanıtlanmasıdır.
- **Dayanıklılık (stres) testi**: sistemin miktar, frekans ya da hacim bakımından anormal biçimde yüklenmesi hallerindeki dayanıklılığını ölçmek amacıyla düzenlenir.
- **Yetenek (performans) testi**: gerçek zamanlı ve gömülü sistemlerde yazılım işlem süresinin bilgisayara dayalı sistemle uyarlığını sınar. Yeteneğin sınanması her test basamağında uygulanır.

Performans testinde yazılımın donanımla birlikte ne kadar sürede cevap verdiği, ne kadar veri saklayabildiği ve veriye ne kadar sürede erişilebildiği değerlendirilir. Bu testler yalnız kendi yazdığımız yazılımlarla yapılamaz; burada CASE araçları, test araçları devreye girer.

### 5.5 Onaylama testi

Onaylama testi, kabul testi (*acceptance test*), kullanıcı testi: hepsi aynı şeydir. Bütünleme testi sonunda yazılım bir paket haline getirilmiş, derlenmiş ve arabirim hataları düzeltilmiştir; sistem testinden sonra onaylama testi yapılır. Bu testte yazılımın müşteri ve kullanıcı beklentilerini ne kadar gerçekleştirdiği ortaya konur.

### 5.6 Testleri kim yapar?

Birim testi yazılım geliştirici yapar. Bütünlük testini bazen yazılım geliştiriciler, bazen test ekibi yapar. Sistem testi ve kullanıcı testi test uzmanlarınca yürütülür. Kullanıcı testi için test ekibi içinde, yazılımın uygulama konusunu bilen ve özellikle dikkatli olan ayrı bir grup görev alır; zaman zaman bu ekibin sistem analisti grubuyla birleştirildiği de görülür.

## 6. JUnit ile Birim Test Uygulaması

### 6.1 Birim sınama ve JUnit

Slayttaki "JUnit ile Birim Sınamaları" sayfası (ekrandan, 01:05:00):

- Birim sınama (*unit testing*), en küçük yazılım bileşeninin sınanmasıdır; NYP'de bireysel sınıfların sınanmasıdır.
- Ne zaman tasarlanır? Kodlamadan önce (TDD, test güdümlü geliştirme), kodlama sırasında ya da kodlamanın ardından.
- Bir sınıfın tek başına yürütemediği sorumlulukların sınanması için, o sınıfın ihtiyaç duyduğu diğer sınıfların yerine geçecek kod gerekebilir: vekil, sahte, yalancı kod/sınıf (*stub, dummy, surrogate, proxy*). Vekil yalnız ihtiyaç duyulan sınıflar gerçeklenene dek kullanılır.
- JUnit, Java ile yazılmış kodun birim sınaması için bir çerçeve programdır (*framework*).
- Diğer diller için de sürümleri vardır, örneğin C# için csUnit.
- IDE desteği: Eclipse'te hazır gelir (build path → add libraries), NetBeans'te hazır gelir.

Hoca test güdümlü geliştirmenin (TDD) çevik yöntemler konusunda anlatıldığını hatırlatır.

> **Hocanın vurgusu:** Kodlamayı hangi dille ya da ortamda yaptıysanız birim test aracınız da ona göre farklı olur; o dilin ya da ortamın özelliğine uygun birim test aracı kullanılmalıdır.

### 6.2 JUnit 3 ile test yapısı

JUnit ile test case hazırlarken:

- Her sınıfın birim testi için ayrı bir test sınıfında ayrı test case'ler hazırlanır.
- Test case'ler bir **test suite** altında toplanır; `TestAll` sınıfındaki `suite()` metodu statiktir.
- Her test case'in `setUp()` metodu her test için yeniden çalıştırılır.

### 6.3 JUnit 4 yenilikleri

JUnit'in dördüncü sürümüyle:

- Sınama sınıflarının `TestCase` sınıfından kalıtımla türetilmesi zorunlu değildir.
- Test metotlarının adlarının `test` sözcüğüyle başlaması zorunlu değildir; ilgili metotların başına `@Test` ek açıklaması (*annotation*) koymak yeterlidir.
- İstisna (*exception*) tanımlanan yazılımlarda, istisnaların gerçekten ortaya çıkıp çıkmadığı sınanabilir. Yazılım hazırlanırken istisna tanımı yapıldıysa test ederken de bu dikkate alınır.

### 6.4 Video kiralama örneği

Örnek, video kiralama uygulamasıdır. Sıralama diyagramında kullanıcı (müşteri), kiralama ve film sınıfları yer alır; her döngüde tek bir kiralama için ücret hesabı yapılır ve sonuç biriktirilir. Sınıf diyagramı kiralama, müşteri ve film arasındaki ilişkileri gösterir. <!-- BELİRSİZ: Sıralama ve sınıf diyagramları karede tam okunamadı. -->

Test case kaynak kodu (`testing/fowler00`) slayttan şöyledir (ekrandan, 01:15:00). Örnekteki müşteri adı ve onu tutan değişkenin adı bu notta genel bir adla değiştirilmiştir:

```java
package fowler_00;
import junit.framework.TestCase;
public class TestCustomer extends TestCase {
    private Customer musteri;
    private Movie matrix, monster, surrogate, terminator;
    protected void setUp() {
        musteri = new Customer("Ayse Yilmaz");
        matrix = new Movie("The Matrix", Movie.REGULAR);
        monster = new Movie("Monsters, Inc.", Movie.CHILDRENS);
        surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
        terminator = new Movie("Terminator Salvation", Movie.NEW_RELEASE);
    }
    public void testGetName() {
        String sonuc = musteri.getName();
        assertEquals("Ayse Yilmaz", sonuc);
    }
    public void testStatementWhenEmpty() {
        String sonuc = musteri.statement();
        String beklenen = "Rental Record for Ayse Yilmaz\n";
        beklenen += "Amount owed is 0.0\n";
        beklenen += "You earned 0 frequent renter points";
        assertEquals(beklenen, sonuc);
    }
}
```

Bu sınıfta:

- `setUp()` her testten önce bir müşteri ve farklı fiyat kodlarına sahip dört film oluşturur; böylece her test aynı başlangıç durumundan çalışır.
- `testGetName()` müşterinin adını döndüren metodu sınar.
- `testStatementWhenEmpty()` müşterinin hiç kiralaması yokken üretilen hesap dökümünün beklenen metinle (borç 0.0, sık kiralama puanı 0) birebir aynı olup olmadığını `assertEquals` ile karşılaştırır.

Refactor edilen örneğin kaynak kodlarından `Rental` ve `Movie` sınıfları slaytta şöyledir (ekrandan, 01:20:00):

```java
package fowler_00;
public class Rental {
    private Movie _movie;
    private int _daysRented;
    public Rental(Movie movie, int daysRented) {
        _movie = movie;
        _daysRented = daysRented;
    }
    public int getDaysRented() {
        return _daysRented;
    }
    public Movie getMovie() {
        return _movie;
    }
}
```

```java
package fowler_00;
public class Movie {
    public static final int CHILDRENS = 2;
    public static final int REGULAR = 0;
    public static final int NEW_RELEASE = 1;
    private String _title;
    private int _priceCode;
    public Movie(String title, int priceCode) {
        _title = title;
        _priceCode = priceCode;
    }
    public int getPriceCode() {
        return _priceCode;
    }
    public void setPriceCode(int arg) {
        _priceCode = arg;
    }
    public String getTitle() {
        return _title;
    }
}
```

`Customer` sınıfının kodu karelerde görülmediği için bu parçalar derlenmemiştir.

Test case'ler oluşturulduktan sonra test suite'e yerleştirilir; `TestAll` çalıştırılarak bütün testlerin sonucu ve hatalar görülür. Hoca son olarak JUnit'in çalıştırma ekranını ve bir tasarımın ardışık düzenlemelerle (*refactoring*) değiştirilebildiğini, refactor edilen kaynak kodların da incelenebildiğini gösterir.

> **Hocanın vurgusu:** JUnit'i önce küçük bir program parçası üzerinde denemeniz gerekir; böylece projede birim testi daha kolay yaparsınız.

Hoca ayrıca gereksinim analizi raporundaki gereksinimlerin nasıl karşılandığını belirten bir yorumun, yani kullanıcı testi bakışının, projelere eklenmesinin iyi olacağını söyler.

## 7. Yazılım Proje Yönetimi

### 7.1 Proje yöneticisinin bilgi alanları

Yazılım proje yönetimi denince üç alanın kesişimi akla gelir: proje yönetimi bilgi ve deneyimi, genel yönetim bilimi ve yazılım mühendisliği teknikleri. Yazılım proje yöneticisi bu kesişimdeki bilgi birikimine ve yeteneklere sahip olmalıdır.

- **Genel yönetim bilimi:** Proje yöneticisi sonuçta bir yöneticidir. Hem üst yönetimle ilişkilerinde hem proje ekibini yönetirken yöneticilik vasıfları gerekir: toplantı yönetimi, bilgi yönetimi, ekip yönetimi, eleman seçimi ve elemanların yeteneklerine göre görevlendirilmesi, sözlü ve yazılı iletişim.
- **Proje yönetimi bilgi ve deneyimi:** projenin zaman planı, kaynak planı, kapsamı ve bunların hepsini koruyacak risk yönetimi.
- **Yazılım mühendisliği teknikleri:** ve bunların temelindeki bilgisayar mühendisliği teknikleri; başarı için yapılan iş konusunda bilgi sahibi olmak gerekir.

### 7.2 Etkin proje yönetimi

Slayttaki "Etkin proje yönetimi" sayfası (ekrandan, 01:35:00):

- **İnsan kaynakları:** seçim, performans yönetimi, eğitim, kariyer geliştirme, organizasyon ve iş tasarımı, ekip kültürü geliştirme konuları üzerinde durulmalıdır.
- **Problemler:** bir proje planlanmadan önce amacı ve alanı belirlenmeli, alternatif çözümler düşünülmeli, teknik ve yönetim kısıtları tanımlanmalıdır.
- **Süreç:** yazılım geliştirme sürecinde gerçekleştirilen işlemler, esas işlemler ve bunların gerçekleşmesini destekleyen işlemlerden oluşur.

### 7.3 Esas adımlar ve destek aktiviteleri

Hoca, ilk derslerde görülen esas adımları ve destek aktivitelerini sınıfa sorar.

**Soru:** Yazılım geliştirmenin esas (temel) adımları nelerdir? **Cevap (bir öğrenci):** Analiz, tasarım, geliştirme, test ve bakım.

**Soru:** Bu adımları destekleyen, iyileştiren aktiviteler nelerdir? **Cevap:** Bir öğrenci gereksinim analizi, test ve planlamayı önerir. Hoca gereksinim analizinin zaten temel adım olduğunu, **proje planlamanın** ise destek aktivitesi sayılabileceğini söyler; bazı kaynaklar planlamayı da temel adım olarak alır, ama bu derste destek aktivitesi olarak görülmüştür. Bir öğrencinin önerdiği zaman yönetimi proje planlamanın içindedir. Diğer destek aktiviteleri: **risk yönetimi**, **konfigürasyon yönetimi**, **yazılım ölçümü**.

## 8. Yazılım Ölçümü: LOC ve İşlev Noktası

### 8.1 Ölçmenin zorluğu

Slayttaki maddeler (ekrandan, 01:40:00):

- Yazılım ürünü geliştirilirken ölçülebilir hedefler belirlenememektedir. Örneğin kullanım kolaylığı (*user-friendly*), güvenilir (*reliable*), bakım yapılabilir olsun deriz, ama bu özellikler için sayısal değerler verilmemektedir.
- Yazılım projelerinin gerçek maliyetlerini oluşturan çeşitli elemanları ölçmek zordur.
- Ürettiğimiz ürünlerin kalitesini ölçemeyiz. Örneğin potansiyel kullanıcının belirli bir kullanım süresinde karşılaşacağı hata olasılığı ya da ürünün farklı bir ortamda ne kadar sürede çalışabilir hale getirileceği ve ne kadar güvenilir olacağı söylenemez.
- Yeni bir geliştirme teknolojisi ya da aracının denenmesi sonucunda uygun olup olmadığı kesin ölçüm sonuçlarıyla değil, anlatım yoluyla cevaplanmaktadır.

Bu yüzden yazılım mühendisliğinde neyin ölçülebileceği ve hangi sayısal verinin bulunabileceği önemli bir sorudur. İki temel ölçüm biçimi vardır: **doğrudan ölçüm** ve **dolaylı ölçüm**. Burada özellikle büyüklük ölçümü önemlidir, çünkü maliyet tahmininin başlangıç noktasıdır.

### 8.2 Doğrudan ölçüm: kod satırı

Yazılımın büyüklüğünü doğrudan ölçmek satır saymaktır: **LOC** (*line of code*, kod satırı) ve **KLOC** (bin kod satırı). Bundan verimlilik, kalite ve gider değerleri türetilir: bu kadar kod satırını kaç kişi kaç ayda yazdı (verimlilik), bir satırın ya da bin satırın gideri ne (gider), kaç sayfa belge hazırlandı (belgeleme).

Slayt küçük resminde aynı oranların FP'ye göre tanımı görülür (ekrandan, 01:50:00): Verimlilik = FP / kişi·ay, Kalite = Hata / FP, Gider = Toplam gider / FP, Belgeleme = Belge sayfası / FP.

Doğrudan yazılım ölçüm tipleri: gider, süre, komut satırı, hız, bellek genişliği ve hata miktarı.

### 8.3 Dolaylı ölçüm: işlev noktası (function point)

Dolaylı ölçümde yazılımın büyüklüğü ve karmaşıklığı birden fazla değere bağlı olarak hesaplanır. Özellikle ticari uygulamalar için yazılıma girdi sayısı, çıktı sayısı, kullanıcının sorgulama sayısı, dosya (veritabanı tablosu) sayısı ve dış arabirim sayısı dikkate alınır. Bu, **işlev noktası** (*function point*, FP) kavramıdır.

Slayttaki ağırlık tablosu (ekrandan, 01:45:00):

| Parametre | Basit | Orta | Karmaşık |
|---|---|---|---|
| Kullanıcının yazılıma giriş sayısı | 3 | 4 | 6 |
| Kullanıcının aldığı çıktı sayısı | 4 | 5 | 7 |
| Kullanıcının sorgulama sayısı | 3 | 4 | 6 |
| Kütük sayısı | 7 | 10 | 15 |
| Dış arabirim sayısı | 5 | 7 | 10 |

Tabloda ayrıca her satır için "Sayılar" ve "FP" sütunları ile bir "Toplam" satırı vardır. Ağırlıklar parametrelerin birbirine göre önemini gösterir; en fazla önem taşıyan **kütük (dosya) sayısı**dır, yani yazılımın kullandığı tablo sayısı.

Hesap adımları:

1. Her parametre için sayı belirlenir.
2. Parametrenin karmaşıklığına göre basit, orta ya da karmaşık ağırlık seçilir.
3. FP sütununa sayı × ağırlık faktörü yazılır.
4. FP sütununun toplamı **sayı toplamı**dır.
5. Bu toplam, 14 sorunun cevaplarıyla düzeltilir (normalize edilir).

Düzeltme formülü (slayt küçük resmi ve sözlü anlatım, ekrandan, 01:45:00):

$$FP = \text{Sayı toplamı} \times \left(0.65 + 0.01 \sum_{i=1}^{14} F_i\right)$$

Burada $F_i$, 14 sorunun her birine 0 ile 5 arasında verilen cevaptır. Derste geçen soru örnekleri: güvenli yedekleme ve geri yükleme gerekli mi (örnek cevap 4), dağıtılmış fonksiyon var mı, uzaktan erişim var mı (hiç dağıtık uygulama değilse 0, tamamen dağıtıksa 5 gibi). <!-- BELİRSİZ: 14 sorunun tam listesi karede görülmedi. -->

**Örnek (derste sözlü, 01:44:09):** Yazılımda kullanılan 15 dosya (kütük) var ve karmaşıklık orta düzeyde.

- Verilen: kütük sayısı 15, orta ağırlık 10.
- İşlem: $15 \times 10 = 150$.
- Sonuç: Kütük satırının FP sütununa 150 yazılır.

Hocanın gösterdiği uygulamada 14 sorunun toplamı $\sum F_i = 32$ bulunmuştur. Bu durumda düzeltme çarpanı (ara adım eklendi):

$$0.65 + 0.01 \times 32 = 0.97$$

Yani sayı toplamı 0,97 ile çarpılarak FP bulunur.

> **Ek bilgi (derste anlatılmadı):** 14 sorunun her biri 0-5 arası puanlandığından $\sum F_i$ en az 0, en çok 70 olur. Bu yüzden düzeltme çarpanı 0,65 ile 1,35 arasında değişir; yani düzeltme, ham sayı toplamını en fazla yüzde 35 azaltıp artırabilir.

### 8.4 LOC ve FP ölçeklerinin kıyaslanması

Slayttaki "Kıyaslama ve eleştiriler" tablosu (ekrandan, 01:50:00):

| LOC ölçeği | FP ölçeği |
|---|---|
| − Programlama diline bağımlı (kısmen) | + Programlama dilinden bağımsız |
| − İyi tasarlanmış ama kısa yazılımları yeterince değerlendirememekte | − Sübjektiftir |
| − İşlemsel olmayan dillerdeki yazılımlara kolayca uyarlanamaz | − Doğrudan fiziksel bir ölçüt değildir |
| | − Veri toplaması güçtür |

Hocanın açıklamaları:

- LOC'nin dile bağımlılığı, C dilindeki kaç satırın başka bir dilde kaç satıra karşılık geldiğini gösteren dönüşüm tablolarıyla bir ölçüde giderilmeye çalışılmıştır.
- FP yalnız girdi-çıktı işlemleri üzerinde durur ve büyüklüğü buna göre hesaplar.
- LOC'de, etkinlik gözetilerek daha az satırda yazılmış bir program daha küçük ya da daha az karmaşık değildir; bu yüzden kısa ama iyi tasarlanmış yazılımlar yeterince değerlendirilemez.
- FP için bütün girdileri ve çıktıları otomatik sayan bir araç yoktur; yalnız hesaplamayı kolaylaştıran bazı Excel tabloları ve makrolar vardır.

Yine de ikisinden birini kullanmak zorundayız: yazılımın maliyetini hesaplarken bir başlangıç noktası gerekir. "Bu büyüklükteki bir yazılımı şu kadar sürede, şu kadar maliyetle, şu kadar iş gücüyle geliştirdik" diyebilmek için büyüklük ölçüsüne ihtiyaç vardır.

### 8.5 Maliyet tahmin yöntemleri

Büyüklük ölçütlerini başlangıç noktası alarak maliyet tahmini yapılır: projeye başlarken "bu proje ne kadarlık bir bütçeyle geliştirilir?" sorusuna cevap aranır. Yöntemler: uzman görüşü ve **Delphi yöntemi**, **analiz yöntemi** ve **istatistik modeller**. Hoca bunların ayrıntısını sonraki derse bırakır.

## 9. Yazılım Risk Yönetimi

### 9.1 Risk nedir?

Yazılım risk yönetimi, yazılım proje yönetimi içinde yapılan bir çalışmadır. Slayttaki tanım (ekrandan, 02:00:00):

- Risk; gelecek, değişim ve seçim ile ilgilidir. Yazılım mühendisliği risk yönetimi de aynı kavramlarla ilgilidir.
- **Gelecek:** Yazılım projesinin kötüye gitmesine neden olabilecek riskler nelerdir?
- **Değişim:** Müşteri gereksinimleri, gelişme teknolojileri, bilgisayarlar ve projeye bağlı tüm varlıklar nasıl değişir?
- **Seçim:** Kullanacağımız yöntem ve araçlar için kaç insan çalışmalı, kalite ölçütlerinden kaç tanesine önem verilmesi gerekir?
- Yazılım risklerinin iki genel özelliği vardır: **belirsizlik** ve **kayıp**.

Yani şu anda sorun olmayan durumlar, gelecekteki değişimler ve yaptığımız seçimler nedeniyle soruna dönüşebilir. Bir seçimin sonradan doğru olmadığı ortaya çıkarsa o da risk oluşturur. Bu yüzden sonradan çıkabilecek sorunları nasıl ortadan kaldıracağımızı ve B planını önceden düşünmeliyiz.

Teknik riskler üretilen yazılımın kalitesini tehdit eder (tasarım, doğrulama, bakım problemleri). İşletmecilik riskleri pazarlama riski, stratejik yönetim, bütçe ve satış desteği riskleridir.

### 9.2 Risk kategorileri

Risk belirleme bir risk kontrol listesiyle yapılır. Kategoriler:

- Ürün büyüklüğü riskleri
- İşletmecilik riskleri
- Müşteriyle ilişkili riskler
- Süreç riskleri
- Teknoloji (teknik) riski
- Geliştirme ortamı riskleri
- Personel riski

**Ürün büyüklüğü riskleri:** Ürünün satır sayısı ya da FP olarak büyüklüğü göreceli bir kavramdır. Bir öğrenci projesi, o güne kadar yapılanlardan büyükse büyük proje sayılır; bir şirket içinse şirketin o zamana kadar yaptıklarına göre değerlendirilir. Önceki ürünlerin ortalama büyüklüğünden sapma, ürünü kullananların sayısı ve yeniden kullanılan yazılım miktarı bu kategoriye girer.

**İşletmecilik riskleri:** Ürünün şirket geliri üzerindeki etkisi, dağıtım tarihinin şirketi zorlayıp zorlamadığı.

**Müşteriyle ilişkili riskler:** Müşteri daha önce çalışılmış bir müşteri mi, ilk kez mi karşılaşılıyor? Neye gereksinim duyduğunu biliyor mu? Ara kontrollerde destek olacak, gözden geçirmelere katılacak mı? Ürün alanında teknik olarak bilgili mi? Yazılım geliştirme sürecini anlıyor mu?

**Süreç riskleri:** Süreç ekip tarafından anlaşıldı mı? Bu süreç başka projelerde kullanıldı mı? Çalışanlar yazılım mühendisliği eğitimi aldı mı, standartları biliyorlar mı? Konfigürasyon yönetimi yapılıyor mu?

**Teknik riskler:** Kod belgeleme ve açıklaması var mı? Tasarım için bir yöntem kullanıldı mı? Test case'ler nasıl yaratılıyor? CASE araçları kullanılıyor mu? CASE aracı kullanmak da risk olabilir: araç ilk kez kullanılıyorsa ve elemanlar o konuda eğitim almamışsa bu bir risktir.

**Personel riski:** Slayttaki sorular (ekrandan, 02:05:00); aşağıdaki soruların cevaplarının çoğu "hayır" ise personel riski vardır:

- İnsanlar yeteneklerine göre kullanılıyor mu?
- Yeterli çalışan var mı?
- Personel çalışma süresinin ne kadarını bu projeye ayırıyor, yoksa yarım zamanlı (*part time*) mı çalışıyor?
- Verilen işler çalışanların beklentilerini karşılıyor mu?
- Personel gerekli eğitimi aldı mı?

### 9.3 Risk tablosu ve önem derecesi

Riskin proje için ne kadar önemli olduğunu ortaya koymak için bir tablo yapılır:

| Sütun | İçerik |
|---|---|
| 1 | Risk |
| 2 | Riskin kategorisi |
| 3 | Riskin olma olasılığı |
| 4 | Riskin projeye etkisi |
| 5 | Olasılık × etkiden çıkan önem derecesi (yüksek, orta, düşük) |

Önem derecesi için olasılık ile etkinin çarpımına göre aralıklar belirlenir ve riskler yüksek, orta, düşük diye kategorize edilir. Bunun önemi şudur: yalnız önem derecesi yüksek olanlar, projenin kritikliği fazlaysa yüksek ve orta olanlar takip edilir ve bunlar için önlem alınır; diğerleri takip edilmez.

> **Hocanın vurgusu:** Bütün riskleri sürekli takip edersek projenin maliyeti artar; bu yüzden takip edeceğimiz riskleri belirliyoruz.

### 9.4 Riskin ortadan kaldırılması

Riski ortadan kaldırmak için riskin **olasılığını** ve **etkisini** azaltmak gerekir. Bunun için talep izleme yapılır, insanlar arası iletişime destek olunur ve süreler izlenir. Hocanın örneği: bir donanım siparişi için iki ay süre verilmişse, sürenin bitmesine bir ay kala satış sorumlusu iş programını hatırlatır. Proje yöneticisi her şeyden önceden haberdar olabilecek biçimde çalışmalarını düzenlemelidir.

Hoca son olarak bir proje planında **zaman planı**, **kaynak planı** ve **risk tablosu** bulunması gerektiğini hatırlatır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:11:54): CASE nedir? Açılımını verip açıklayınız.

> **Çözüm (derste verilen):** *Computer Aided Software Engineering*, bilgisayar destekli yazılım mühendisliği. Yazılım geliştirme sürecinde çalışanlara destek olan yazılım aracıdır. Yalnız analiz ve tasarımda diyagram çizimini destekleyen küçük bir araç olabileceği gibi, proje planından teste kadar bütün süreci destekleyen bütünleşik bir platform da olabilir.

**Soru 2** (derste sözlü, 00:29:50): V modelde hangi test adımı hangi geliştirme adımına karşılık gelir?

> **Çözüm (derste verilen):** Kullanıcı testi ↔ müşteri gereksinimleri; sistem testi ↔ ürün spesifikasyonu (işlevsel olmayan gereksinimler); bütünlük testi ↔ yüksek düzey (mimari) tasarım; bileşen testi ↔ alçak düzey (ayrıntılı) tasarım; birim test kodlamayla aynı kutudadır.

**Soru 3** (derste sözlü, 00:36:24): Birim testi kim yapar?

> **Çözüm (derste verilen):** Kodu geliştiren yazılımcı. Bu yüzden V modelde kodlama ve birim test aynı kutuya yazılır.

**Soru 4** (derste sözlü, 01:35:29): Yazılım geliştirmenin esas adımları ve bunları destekleyen aktiviteler nelerdir?

> **Çözüm (derste verilen):** Esas adımlar: analiz, tasarım, geliştirme (kodlama), test, bakım. Destek aktiviteleri: proje planlama (zaman yönetimi dahil), risk yönetimi, konfigürasyon yönetimi, yazılım ölçümü.

**Soru 5** (derste sözlü, 01:44:09; ağırlık tablosu ekrandan, 01:45:00): Bir yazılımda orta karmaşıklıkta 15 kütük (dosya) kullanılıyor. İşlev noktası tablosunda bu satırın FP değeri nedir? 14 sorunun toplamı 32 ise düzeltme çarpanı kaçtır?

> **Çözüm:** Orta karmaşıklıkta kütük ağırlığı 10'dur; $15 \times 10 = 150$ (derste verildi). Düzeltme çarpanı $0.65 + 0.01 \times 32 = 0.97$ (ara adım eklendi, python ile kontrol edildi).

## Dersin Toparlaması

Bu derste yazılım kalitesi, kalite bakış açısının yazılım mühendisliğinin temel katmanı olmasından başlanarak ele alındı. McCall modeli kalite faktörlerini kullanıcı, bakımcı ve taşıyıcı bakış açılarına ayırıp ölçütlerin doğrusal birleşimiyle kestirdi. Kaliteyi sağlama aktiviteleri arasında özellikle erken gözden geçirme ve test öne çıktı, çünkü hata ne kadar geç bulunursa maliyeti o kadar artar. Doğrulama ile geçerleme ayrımı ve V model, test adımlarının (birim, bileşen, bütünlük, sistem, kullanıcı testi) geliştirme adımlarıyla nasıl eşleştiğini gösterdi. Birim testinin JUnit ile nasıl yazılacağı video kiralama örneği üzerinden incelendi.

Dersin ikinci yarısında yazılım proje yönetimine geçildi: proje yöneticisinin bilgi alanları, etkin proje yönetiminin öğeleri, doğrudan (LOC) ve dolaylı (işlev noktası) büyüklük ölçümü ile bunların kıyaslaması anlatıldı. Büyüklük ölçüsünün maliyet tahmininin başlangıç noktası olduğu vurgulandı; Delphi, analiz yöntemi ve istatistik modeller gibi maliyet tahmin yöntemlerinin ayrıntısı sonraki derse bırakıldı. Son olarak risk kavramı, risk kategorileri, risk tablosu ve olasılık × etki ile önem derecesinin belirlenmesi işlendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
