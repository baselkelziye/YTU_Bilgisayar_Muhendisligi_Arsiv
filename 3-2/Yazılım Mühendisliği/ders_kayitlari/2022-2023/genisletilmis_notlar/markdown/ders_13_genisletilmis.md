# Ders 13 Genişletilmiş Notu: Dönem Projesi Sunumları (1. Gün)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Düzeni ve Sunumların Kapsamı
- 2. Birinci Sunum: Medya Takip Şirketi Bilgi Sistemi
- 3. İkinci Sunum: Yazılım Evi İnsan Kaynakları Sistemi
- 4. Üçüncü Sunum: Seyahat Acentesi Bilet ve Tatil Sistemi
- 5. Dördüncü Sunum: Seyahat Acentesi Rezervasyon ve Bilet Sistemi
- 6. Hocanın Rapor Düzeni Önerisi
- 7. Sunumlardan Çıkan Ortak Dersler
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Düzeni ve Sunumların Kapsamı

Bu ders, dönem projesi sunumlarının ilk günüdür. Konu anlatımı yapılmadı. Hoca bu hafta yalnız gönüllü grupları sunuma aldı ve sırayı derste belirledi. Toplam dört grup sundu. Kalan gruplar bir sonraki hafta sunacak.

Projeler dönem başında verilen vakalara dayanıyor. Bu derste üç farklı vaka sunuldu:

- **Medya takip şirketi:** Medya organlarını izleyen ve müşterilerine rapor hazırlayan bir şirket için bilgi sistemi.
- **Yazılım evi insan kaynakları:** Çalışanların işe alınması, projelere atanması, maaş ve tazminat hesabı ve işten çıkarılması gibi süreçleri yöneten bir sistem.
- **Seyahat acentesi:** Ulaşım bileti satışı, otel rezervasyonu, puan kazanma ve farklı ödeme yöntemleri olan bir sistem. Bu vakayı iki ayrı grup sundu.

Her sunum aşağı yukarı aynı iskeleti izledi. Önce proje planı anlatıldı: proje alan tanımı, kabuller ve kısıtlar, iş-zaman çizelgesi (Gantt diyagramı), ekip organizasyon şeması ve risk tablosu. Ardından gereksinimlerin modellenmesi geldi: kullanım durumu (use case) diyagramı, kullanım senaryosu metinleri ve izlenebilirlik tablosu (traceability matrix). Sonra nesneye dayalı modelleme ve tasarım: sınıf diyagramı, sıralama (sequence) diyagramı, etkinlik (activity) diyagramı ve durum (state) diyagramı. En sonda birim testleri (unit test) gösterildi.

Programın çalıştırılması (demo) ve koda dair sorular bu sunumların parçası değildi. Hoca, programların ayrıca asistanla yapılacak bir oturumda gösterileceğini söyledi. Bu yüzden gruplar arayüzlerini yalnızca kısaca gösterdi.

## 2. Birinci Sunum: Medya Takip Şirketi Bilgi Sistemi

### 2.1 Problem ve Kapsam

Grup, medya organlarındaki haberleri takip edip müşterilerine rapor hazırlayan bir şirket için bilgi sistemi geliştirdi. Projenin amacı, şirketteki elle yapılan işleri otomatikleştirmek ve müşteriler için raporları daha hızlı ve doğru hazırlamaktı.

Kapsamda medya organlarının takibi için ortak bir arayüz vardı. Bu arayüzde müşterilerin rapor tercihlerini kaydetme ve anket düzenleme gibi özellikler de yer alıyordu. Projenin şirketin belirlediği zaman, bütçe ve kaynak kısıtları içinde tamamlanacağı belirtildi.

Sistemin işlevleri şöyle anlatıldı:

- Şirket radyo, televizyon gibi farklı tipte medya organlarını izler. Sistemde yeni medya tipleri eklenebilir, sayıları değiştirilebilir ve güncellenebilir.
- Şirket yöneticisi yeni çıkan medya organlarını kataloğa ekler, değişenleri günceller, kapananları siler.
- Müşteriler şahıs veya şirket olabilir. Müşterinin rapor tipi anlaşma imzalanırken belirlenir ve süreç içinde değiştirilemez.
- Standart raporların belirli bir fiyat listesi vardır. Müşteri isterse özel fiyatlandırmayla özel rapor hazırlanır.
- Raporlar günlük, haftalık veya aylık hazırlanır. Müşteri isterse farklı periyotta, örneğin saatlik rapor da isteyebilir.
- Şirketin bir de anket hizmeti vardır. Anketörler anket işlerini ayrı bir arayüzden yürütür.

### 2.2 Kabuller ve Kısıtlar

Grubun kabulleri büyük ölçüde yukarıda anlatılan işleyişten oluşuyordu. Ek olarak, projedeki kaynakların ve içeriklerin rastgele üretildiği, bu yüzden gerçek içeriği yansıtmayabileceği kabul edildi.

Kısıtlar şunlardı:

- Bir müşteri yalnız bir türde olabilir (şahıs ya da şirket) ve bu süreç içinde değişmez.
- Şirket yalnız Türkçe medya organlarını takip eder.
- Anketler yalnız Türkiye'deki müşterileri kapsar.
- Kişisel verilerin korunması için gereken bütün önlemler alınmalıdır.
- Yazılım ve donanım şirket bütçesi çerçevesinde seçilmelidir.

Grup ayrıca müşteri sayısı ya da veri miktarı çok artarsa bilgi sisteminin ölçeklenmesi gerektiğini belirtti.

### 2.3 Gantt Diyagramı, Risk Tablosu ve Ekip

İş-zaman çizelgesinde ilk dört hafta gereksinimlerin belirlenmesi ve tasarıma, sonraki iki hafta arayüzün ve programın geliştirilmesine ve test işlemlerine ayrılmıştı. Hoca Gantt diyagramının nerede çizildiğini sordu. Grup bir Google Sheets şablonu kullandığını söyledi.

Risk tablosunda riskler olasılık, etki ve risk düzeyi sütunlarıyla sınıflandırılmıştı. Örnek olarak veri kaybı verildi: olasılığı düşük, ama şirket ve proje için etkisi çok yüksek bir risk. Ekip organizasyon şeması da gösterildi, görevler tek tek anlatılmadı.

<!-- BELİRSİZ: Gantt diyagramındaki son haftaların içeriği, risk tablosunun öteki satırları ve ekip şemasındaki roller altyazıda okunmuyor. -->

### 2.4 Use Case Diyagramı ve Kullanım Senaryoları

Analiz aşamasında temel aktör kullanıcıydı (müşteri). Diyagramda beş işlev vardı. Bunların arasında memnuniyet anketi sonuçlarını görüntüleme, rapor görüntüleme ve ücret bilgilerini görüntüleme sayıldı.

Diyagramdaki iki ilişki şöyle açıklandı:

- **extend:** Müşteri standart olarak seçtiği rapor dışında bir rapor görmek isterse özel ücretlendirmeye tabi olur. Bu durum ücret bilgilerini görüntüleme işlevine `extend` ile bağlanan "özel ücretlendirme" olarak çizildi.
- **include:** Müşterinin standart rapor tipini görebilmek için kullanıcı kaydı gerekir. Kullanıcı kaydı bütün işlevlere `include` ile bağlandı.

> **Ek bilgi (derste anlatılmadı):** UML'de `include`, temel kullanım durumunun her çalıştığında mutlaka çağırdığı ortak bir alt davranışı gösterir. `extend` ise temel kullanım durumuna yalnız belirli bir koşul sağlandığında eklenen isteğe bağlı davranıştır. Okun yönü de farklıdır: `include` okunu temel durumdan alt duruma, `extend` okunu ise genişleten durumdan temel duruma çizilir.

Her işlev için bir kullanım senaryosu metni yazılmıştı. Metinlerin başlıkları sırasıyla şunlardı: ilgililer ve beklentiler, ön koşullar, son koşullar, ana senaryo, alternatif akış. Grup "ücret bilgilerini görüntüleme" senaryosunu örnek verdi:

- **İlgili:** Ana aktör olan müşteri.
- **Ön koşul:** Müşterinin sisteme giriş yapmış olması. Bu, diyagramda `include` ile bağlanan kısımdır.
- **Son koşul:** Ücret bilgilerinin görüntülenmiş olması.
- **Ana senaryo ve alternatif akış:** Müşteri memnuniyet anketi oluşturduğunda ya da rapor görüntülediğinde ücret bilgilerinin görüntülenmesi için gereken adımlar.

### 2.5 İzlenebilirlik Tablosu

İzlenebilirlik tablosunda satırlar kullanıcının istediği gereksinimlerdi. Sütunlar ise programdaki sınıflar, modüller ve menülerdi. Grup bu tablo sayesinde her gereksinimin programda hangi modül ve sınıfla gerçeklendiğinin açıkça görüldüğünü anlattı.

### 2.6 Tasarım Sınıf Diyagramı

Tasarım sınıf diyagramının ortasında ana menüyü taşıyan bir ana arayüz sınıfı (main GUI) vardı. Anket oluşturmak için bir anket arayüzü, yeni kaynak eklemek için ayrı bir arayüz vardı. Raporların sınıflandırılması ve medya tipinin sınıflandırılması için iki ayrı sayılama tipi (enum) tanımlanmıştı. Ayrıca medya kaynağını temsil eden bir sınıf (Media Outlet) ve veritabanı işlemleri için bir sınıf vardı. Diyagramın ayrıntılı halinde her sınıfın metotları da gösterildi. Örneğin fiyatı döndüren bir `getPrice` metodu vardı.

Hoca diyagramdaki bazı bağlantıların kesikli çizgiyle çizildiğini fark edip anlamını sordu. Grubun cevabı şuydu: Bağlantılı sınıf doğrudan bir nitelik (attribute) olarak tutulmuyor, örneği (instance) bir metot içinde oluşturuluyor. Bu yüzden kesikli çizgi kullanıldı.

> **Ek bilgi (derste anlatılmadı):** UML sınıf diyagramında kesikli ok bağımlılık (dependency) ilişkisini gösterir. Bir sınıf ötekini yalnız bir metodunda parametre, yerel değişken ya da oluşturulan nesne olarak kullanıyorsa bu ilişki çizilir. Sınıf ötekini nitelik olarak tutuyorsa düz çizgili ilişki (association) kullanılır. Toplama (aggregation) ve bileşim (composition) ilişkinin daha güçlü biçimleridir.

### 2.7 Sıralama, Durum ve Etkinlik Diyagramları

**Rapor oluşturma sıralama diyagramı:** Müşteri ana arayüzde bir düğmeye basar ve rapor arayüzüne geçilir. Rapor arayüzü kendi fonksiyonlarıyla tarihi kontrol eder, başlangıç tarihini seçer, ardından rapor gösterme arayüzünden bir nesne yaratır. Sonra rapor arayüzüne dönülür. Önce borç hesaplanır, sonra güncellenir ve ana arayüze dönülür. Yeni müşteri oluşturma ve kaynak ekleme sıralama diyagramları da benzer çalışıyordu: yeni bir kaynak yaratılıp veritabanına ekleniyordu.

**Durum diyagramları:**

- Üyelik: Müşteriden ad ve üyelik tipi alınır, üyelik gerçekleştirilir, ana ekrana dönülür.
- Rapor gösterme: Müşteri seçilir, haber kaynağı ve tarih seçilir. O kaynak için o tarihte rapor bulunduysa raporlar gösterilir. Bulunamadıysa "rapor bulunamadı" hatası verilir ve ana ekrana dönülür.

**Etkinlik diyagramları:**

- Anket hizmeti: Anket hizmeti seçildiyse anket işlemleri ekranına gidilir, şablon seçilir ve sonuçlar gösterilir. Seçilmediyse doğrudan ana ekrana dönülür.
- Müşteri oluşturma: Müşteri adı ve üyelik tipi aynı anda girilir, ardından müşteri oluşturulur.
- Haber kaynağı oluşturma: Haber kaynağı ve platform aynı anda girilir, kaynak oluşturulur.
- Rapor çıkarma: Müşteri seçimi, haber kaynağı seçimi ve zaman aralığı seçimi aynı anda yapılır, ardından ilgili haberler gösterilir.

Grup bazı girişlerin "aynı anda" yapıldığını söyledi.

<!-- BELİRSİZ: Bu adımların çatallanma/birleşme (fork/join) çubuklarıyla çizilip çizilmediği altyazıdan anlaşılmıyor. -->

### 2.8 Birim Testleri

Hoca testlerin nasıl yapıldığını sordu. Birim testleri grup üyeleri arasında bölüşülmüştü:

- **Kaynakları yükleme testi:** Yeni bir nesne oluşturulur, kaynaklar yüklenir. Sonucun boş (null) olmadığı ve kaynak sayısının sıfırdan büyük olduğu kontrol edilir.
- **Müşterileri yükleme testi:** Aynı mantıkla çalışır.
- **Yeni kaynak ekleme testi:** Web tipinde yeni bir kaynak oluşturulup veritabanına eklenir. Kaydın veritabanına eklenip eklenmediği kontrol edilir. Eklendiyse test kaydı geri silinir.
- **Müşteri ekleme testi:** Günlük (daily) rapor tipinde bir müşteri oluşturulur, veritabanında olup olmadığı kontrol edilir, sonra silinir.
- **Müşteri silme testi:** Veritabanındaki seçilen bir müşteri silinmeye çalışılır. Müşteri bulunamazsa silme işlemi başarısız olarak döner.

Hoca ardından kullanıcı testi gibi bir şey yapılıp yapılmadığını sordu. Grup bunların birim testleri olduğunu, kullanıcı testi derste işlenmediği için uygulamadıklarını söyledi.

> **Ek bilgi (derste anlatılmadı):** Birim testi, programın en küçük parçasını (bir metot ya da sınıf) tek başına sınar ve genelde geliştirici tarafından yazılır. Kullanıcı testi ya da kabul testi (acceptance test) ise sistemin bütün olarak kullanıcının gereksinimlerini karşılayıp karşılamadığını sınar. Bu test genelde gerçek kullanıcılarla ya da onların senaryolarıyla yapılır.

Son olarak grup arayüzü kısaca gösterdi: kaynak silme, rapor isteme ve anket gibi özellikler vardı. Ayrıntılı demo asistanla yapılacak oturuma bırakıldı.

## 3. İkinci Sunum: Yazılım Evi İnsan Kaynakları Sistemi

### 3.1 Problem ve Amaç

Grup bir yazılım evinin insan kaynakları süreçlerini yöneten bir sistem geliştirdi. Varsayılan şirkette proje atama, takım oluşturma ve çalışan işe alma gibi işler elle yapılıyor, kayıtlar dosyalarda saklanıyordu. Bu hem insan gücü kaybına hem de kağıtların dolaşmasından doğan zaman kaybına yol açıyordu.

Sistemin amaçları şöyle sıralandı:

- İnsan kaynakları bölümündeki işlemleri hızlandırmak ve iş yükünü azaltmak.
- Proje ve çalışan bilgilerini dijital ortamda saklayıp taşınabilir hale getirmek.
- Çalışanları projelere atamak.
- Maaş ve tazminat hesaplarını otomatikleştirip hata payını düşürmek.
- Yöneticilere karar verme sürecinde yardımcı olacak bilgi sağlamak.

### 3.2 Sistemin Özellikleri

- **Proje atama:** Projeler, çalışanların yeteneklerine göre, örneğin programcıların bildiği programlama dillerine göre atanır. Sistem uygun atamaları otomatik olarak önerir.
- **Maaş ve tazminat hesabı:** Harici sistemler kullanılır. Kullanıcı istediği hesaplama hizmetine yönlendirilir. Sistem bu hizmetlerle entegre çalışır.
- **Çalışan oluşturma:** Yeni çalışanın türü seçilir, adı ve maaşı gibi bilgiler girilir. Çalışan programcıysa programlama dili de seçilir.
- **Çalışan düzenleme:** Kullanıcı bilgilerini yalnız yöneticiler (admin) düzenleyebilir.
- **Proje oluşturma:** Yönetici yeni proje tanımlar, projeye takım atar, kullanılacak programlama dilini seçer, başlangıç ve bitiş tarihlerini girer.
- **Takım oluşturma:** Yönetici her rol için kişi seçer. Takım beş kişiliktir. Test eden (tester) rolü isteğe bağlıdır, öteki dört rolün dolu olması zorunludur.

### 3.3 Kabuller ve Kısıtlar

Hoca grubun kabulleri ve kısıtları ayrı ayrı gösterip göstermediğini sordu ve ikisinin farkını açıkladı.

> **Hocanın vurgusu:** Kabuller ve kısıtlar ayrı ayrı yazılmalı. Kabuller genellikle olumlu olanlardır. Kısıtlar ise problemdeki, sistemdeki ya da projedeki sınırlamalardır.

Grubun kabulleri:

- Projede herkesin Java bildiği ve Java'ya uygun yazılım geliştirme araçlarını kullanabildiği.
- Proje için gereken bütün kaynaklara zamanında erişilebileceği.
- Gereksinimlerin projeye başlamadan tam ve doğru belirlendiği.

Grubun kısıtları:

- Proje beklenen sürede ve bütçede yapılmalıdır.
- Proje Java ile yazılmalıdır.
- Tazminat hesabı için muhasebe yazılımı kullanılmalıdır.
- Proje iş hukukuna ve veri koruma yasalarına uygun olmalıdır.
- Program ilk açıldığında ilk kullanıcı yönetici olarak kaydolur. Öteki kullanıcılar bu yönetici tarafından eklenir.
- Belirli bir dille yazılan projeye atanacak programcılar ve test edenler o dili bilmelidir. Bilmeyen kişi projeye atanmaz.
- Bir projede test eden dışındaki bütün rollerde birer kişi bulunması zorunludur.

Hoca "Java ile yazılmalıdır" kısıtına bir düzeltme önerdi. Kısıtın gerekçesiyle yazılması daha doğrudur.

> **Hocanın vurgusu:** "Proje Java diliyle yazılmalıdır" yerine "grup üyelerinin en iyi bildiği ve en hızlı yazabildiği dil Java'dır" ya da "bu sisteme en uygun dil Java'dır" gibi bir ifade kullanılabilir.

### 3.4 Gantt Diyagramı ve Süreç Modeli

Hoca Gantt diyagramının nerede çizildiğini ve hangi süreç modelinin kullanıldığını sordu. Grup diyagramı adını hatırlamadığı bir online platformda çizdiğini, şelale (waterfall) modelini kullandığını söyledi. Grubun iş akışı şu sırayla ilerledi:

1. Proje alan tanımı, kabul ve kısıtların belirlenmesi, risk tablosunun oluşturulması.
2. Kullanım senaryolarının hazırlanması ve use case diyagramının çizilmesi.
3. Sınıf diyagramlarının oluşturulması.
4. Her senaryo için sıralama, etkinlik ve durum diyagramlarının oluşturulması.
5. Arayüz tasarımı ve kodlamanın birlikte yapılması.
6. Birim testleri.
7. Raporun yazılması.

Ekip organizasyon şemasında proje yöneticisi, analist, yardımcı analist, geliştirici ve test eden rolleri dağıtılmıştı.

### 3.5 Risk Tablosu ve Riskin Takibi

Risk tablosunda zaman baskısı (projenin çok kısa sürede yapılması ve öteki derslerin projeleri yüzünden), bütçe kısıtları ve personel eksikliği gibi riskler vardı.

<!-- BELİRSİZ: Altyazıda "organizasyon etkisi büyük olasılığı düşük" deniyor; bu değerlendirmenin hangi riske ait olduğu net değil. -->

Hoca burada risk tablosundaki risklerden hangilerinin takip edilmesi gerektiğini sordu. Soru-cevap aşağıdaki gibi gelişti:

**Soru:** Bu risklerden hangileri uygulama boyunca, her aşamada takip edilmeli? Bunları nasıl belirlersiniz?

**Cevap:** Etkisi büyük ve olasılığı yüksek olanlar. Hoca cevabı tamamladı: Etkisi ve olasılığı yüksek ya da orta-yüksek olanlar takip edilir, düşük ve orta olanlar ihmal edilebilir. Ya da hangi düzeyden itibaren takip edileceğine dair bir sınır (eşik) konur.

> **Ek bilgi (derste anlatılmadı):** Risk yönetiminde bu yaklaşım genelde risk düzeyinin olasılık ve etkinin birleşimiyle belirlenmesine dayanır. Olasılık-etki matrisinde sağ üst köşedeki riskler sürekli izlenir ve bunlar için önceden önlem planı hazırlanır. Düşük düzeyli riskler yalnız kayıt altında tutulur.

### 3.6 Use Case Diyagramları

Grup iki kullanım durumu diyagramı çizmişti:

- **Proje ekleme:** Yönetici (manager) proje eklemek ister. Sisteme giriş yapmadıysa giriş (login) işlevi `extend` ile çalışır. Sonra proje bilgileri girilir.
- **Çalışan kaydı:** Çalışanı kendisi değil, yönetici ekler. Eklenen kişi yöneticiyse bir üst yönetici (supervisor) seçilir. Değilse öteki bilgilerle devam edilir.

> **Ders sonrası not:** Grup girişi, kullanıcı giriş yapmamışsa çalışan koşullu bir işlev olarak `extend` ile çizdi. Giriş, işlevin her çalışmasında gereken bir adım olarak görülürse, büyük olasılıkla `include` ile ya da senaryoda ön koşul olarak gösterilmesi daha yaygındır. Kısa nottaki örnekte de giriş `include` olarak geçiyor.

### 3.7 Sınıf, Sıralama, Etkinlik ve Durum Diyagramları

**Sınıf diyagramı:** Grup arayüz sınıflarını eklemedi, yalnız alan sınıflarını çizdi: yönetici (manager), çalışan (employee), takım ve proje. İlişkiler şöyleydi: Yönetici çalışanları kullanır. Çalışan bir takımın içinde yer alır. Takımlar projelere atanır. Ayrıca görev (task) ile ilgili bir sınıf da sayıldı.

<!-- BELİRSİZ: "task, start task" diye geçen sınıfın adı ve ilişkileri altyazıda net değil. -->

**Sıralama diyagramı:** Yönetici sisteme giriş yapar ve proje oluşturur. Sistem proje bilgilerini ister, yönetici verir. Bilgiler girildikten sonra proje bir takıma atanır, takıma ve yöneticiye bilgi verilir.

**Etkinlik diyagramı:** Kayıt sırasında kişinin verileri girilir. Kişi programcıysa programlama dili seçilir. Yöneticiyse üst yönetici seçilir. Diğer durumlarda yalnız genel bilgiler girilip işlem biter.

**Durum diyagramı:** Yönetici giriş yapar, proje verilerini oluşturur, bir takım atar ve en sonda projenin başlangıç-bitiş tarihlerini belirler.

### 3.8 Birim Testleri

Birim testleri yine üyeler arasında bölüşülmüştü:

- **Veritabanı testi:** Veritabanının ayağa kalkıp kalkmadığı, bağlantının kurulup kurulmadığı ve veritabanının oluşturulup oluşturulmadığı sınanır.
- **Veritabanına ekleme testleri.**
- **Çalışan oluşturma testi:** Çalışan bilgilerinin doğru girilip girilmediği kontrol edilir. Örneğin çalışan programcıysa bildiği dil girilmelidir, girilmezse hata verilir. Önce veritabanına bağlanılır, şirket bilgileri çekilir ve rastgele bir kullanıcı belirlenir. Grup, hızlı deneme için on rastgele kullanıcı üreten bir modül de yazmıştı.
- **Proje adı testi:** Bağlantı kontrol edilir, ardından proje adının veritabanında uygun biçimde durup durmadığı sınanır.
- **Giriş testi:** Veritabanı bağlantısı kontrol edilir. Girilen kullanıcı adı ve parola kontrol edilir. Doğruysa yetkilendirme (authorization) yapılır. Giriş yapan kişinin yönetici olup olmadığı da kontrol edilir.
- **Proje sınıfı testi:** Proje ekleme, tarih alma ve atama (get/set) metotları, takımın doğru oluşturulup projeye doğru atandığı sınanır.

Hoca herkesin kendi yazdığı birimin testini kendisinin yazıp yazmadığını sordu. Grup "evet" dedi. Hoca bunu olumlu buldu. Birim testi için kullanılacak programın kullanımını derste gösteremediğini, grupların bunu kendi araştırmalarıyla öğrendiğini belirtti.

> **Hocanın vurgusu:** Her geliştirici yazdığı birimin birim testini ayrı ayrı oluşturmalı. Hoca ilk iki grupta bunun yapılmış olmasından memnun kaldığını söyledi.

## 4. Üçüncü Sunum: Seyahat Acentesi Bilet ve Tatil Sistemi

### 4.1 Problem ve İşleyiş

Grup bir seyahat acentesi için bilet ve tatil sistemi gerçekledi. Sistemin temel algoritması şöyle anlatıldı:

1. Müşteri tatil ya da bilet almak istediğinde uygun tarihleri acente görevlisine iletir.
2. Görevli, bu tarihler arasında uygun otel ya da bilet varsa ödemeyi alır, bileti keser ve müşteriye bilgi verir.
3. Müşteri kullandığı ödeme yöntemine göre puan kazanır. Havayolu biletlerinde %1, otellerde gün bazında %2 puan kazanılır ve puanlar müşterinin hesabında gösterilir.

Proje alan tanımında acentenin bir havayolu, bir demiryolu ve bir otobüs firmasıyla anlaştığı, farklı şehir ve ülkelerdeki otellerle de anlaşma yaptığı kabul edildi. Bu anlaşmalar ileride güncellenebilecek biçimde tasarlanmıştı. Ödemede nakit, kredi kartı ve çek kabul ediliyordu.

### 4.2 Kabuller ve Kısıtlar

Kabuller beş başlıkta toplandı:

- **Çoklu hizmetler:** Farklı ulaşım yollarıyla ve farklı şirketlerle anlaşma.
- **Çeşitli ödeme yöntemleri.**
- **Puan sistemi:** Bilet ve otel rezervasyonunda %1 ve %2 puan kazanılır, puanlar sonraki alımlarda kullanılır.
- **Genişleyebilirlik:** İleride başka havayolu, otobüs ya da demiryolu şirketleriyle ve başka otellerle anlaşılabilir.
- **Anlaşmalar.**

Kısıtlar şunlardı:

- **Güvenlik:** Müşteri bilgileri güvenli bir veritabanında tutulur, yetkisiz erişim engellenir.
- **Fiyatlandırma:** Farklı şirketlerin fiyatlandırma politikaları takip edilir.
- **Bilet ve otel durumu:** Uygunluk veritabanından kontrol edilir, müşteri zor durumda bırakılmaz.
- **Uyumluluk:** Farklı firmaların sistemleriyle uyum sağlanır.
- **Müşteri memnuniyeti:** Personel eğitimi ve müşteri taleplerine hızlı yanıt.

### 4.3 İş-Zaman Çizelgesi, Ekip ve Risk Tablosu

Grup iş-zaman çizelgesini gün gün yazmıştı. Sıra şöyleydi: üç günlük tanışma toplantısı, proje planının ve risk tablosunun oluşturulması, isteklerin modellenmesi, nesneye dayalı modelleme, tasarım, kodlama, birim testleri ve rapor için son toplantı. Ekipte proje yöneticisi, yazılım geliştirici, sistem analisti ve test eden rolleri vardı.

Risk tablosunda her riskin olasılığı, etkisi ve önlemi incelendi:

| Risk | Etkisi | Önlem |
|---|---|---|
| Yazılım kütüphanesinin güncel olmaması | Yazılımda sorunlar ve müşteriye gecikme | Kütüphanelerin güncelliği kontrol edilir |
| Puan sisteminin çalışmaması | Puan hesabı yapılamaz | Modülün veritabanıyla uyumlu çalışması sağlanır ve denetlenir |
| Test aşamasında sorun | Testler yapılamaz | Java için uygun test kütüphaneleri kullanılır |
| Gereksinimlerin gerçekleştirilememesi | İstenen işlevler eksik kalır | Plandaki görev dağılımı uygun yapılır |

<!-- BELİRSİZ: Tablodaki olasılık ve etki düzeyleri altyazıda sözlü verilmedi; son iki satırın risk adları sunumdaki önlem cümlelerinden kurulmuştur. -->

### 4.4 Use Case Diyagramı ve Kullanım Senaryosu

Grup isteklerin modellenmesinde Violet UML Editor aracını kullandı. Hoca bu aracı daha önce başka bir derste kullanıp kullanmadıklarını sordu, grup bu derste öğrendiğini söyledi. Hoca diğer gruplarda da bu aracı kullanan olup olmadığını sordu.

Use case diyagramında dört aktör vardı: müşteri, acente görevlisi, otel sistemi ve seyahat firması sistemi. Son ikisi, acente görevlisinin yalnız bilgilendirme yaptığı dış sistemlerdi.

Grup "bilgilendirme" kullanım senaryosunu örnek olarak anlattı:

- **Birincil aktör:** Acente görevlisi.
- **Diğer ilgililer ve beklentileri:** Görevli, müşterinin onayladığı bilgileri firmaların sistemlerine aktarmak ister. Seyahat firması sistemi sattığı biletin bilgilerini, otel sistemi rezervasyon tarihlerini öğrenmek ister.
- **Ön koşullar:** Müşterinin bileti ya da tatili onaylamış olması, ödemeyi yapmış olması ve müşteri seyahat için geldiyse görevlinin bileti kesmiş olması.
- **Ana senaryo:** Müşteri ödemeyi yapar. Müşteri seyahat için geldiyse görevli bileti keser. Görevli bilgilendirmeyi yapar.
- **Alternatif akış:** Müşteri tatil için geldiyse görevli otel sistemini bilgilendirir. Seyahat için geldiyse seyahat firmasının sistemini bilgilendirir.

İzlenebilirlik tablosunda bu grup farklı bir yol izledi: eklenen sınıfları, sınıflar üzerinde yapılan değişiklikleri ve değişikliği yapan kişiyi yazdı.

### 4.5 Sınıf Diyagramı ve Nesneye Dayalı Tasarım

Sınıf diyagramında ilişkiler şöyleydi:

- Müşteri bilet ve rezervasyon işlemlerini yapar.
- Bilet ile firma arasında doğrudan ilişki vardır, firmaya bilet üzerinden ulaşılır.
- Müşteri ödeme yapar. Ödeme ya cüzdana bakiye yükleyerek ya da bilet veya tatil alırken doğrudan yapılır.
- Otelin tatille ilişkisi vardır, ama tatil olmadan da otel olabilir.
- Seyahat ve tatil, hizmet sınıfının alt türleridir.

Nesneye dayalı tasarım bölümünde arayüzler ve düğmeler arasındaki ilişkiler ele alındı: Bir düğmeye basıldığında hangi arayüzün açılacağı ve arayüzlerin boyutları gibi konular.

### 4.6 Sıralama Diyagramı Üzerine Hocanın Uyarısı

Hoca sıralama diyagramının nasıl çizildiğini sordu. Grup kullandığı programı hatırlayamadı, Violet olmadığını söyledi. Hocanın dikkatini çeken, diyagramdaki nesnelerin aynı hizada olmamasıydı.

> **Hocanın vurgusu:** Ardışıl (sıralama) diyagramda sınıflar ya da nesneler genelde üstte aynı hizada dizilir. Bu diyagramda farklı hizada olmaları değişik geldi.

> **Ders sonrası not:** UML'de nesneler genelde üstte aynı hizada başlar. Ancak bir nesne etkileşim sırasında bir `create` mesajıyla yaratılıyorsa kutusu yaratıldığı noktaya çizilebilir. Bu durumda farklı hiza UML'ye uygundur. Grubun diyagramındaki hizanın bu nedenle mi yoksa araçtan dolayı mı farklı olduğu altyazıdan anlaşılmıyor.

### 4.7 Etkinlik ve Durum Diyagramları

**Ödeme etkinlik diyagramı:**

1. Müşterinin onayı alınır.
2. Cüzdan kontrol edilir.
3. Yeterli bakiye yoksa ödeme yöntemi seçilir: çek, kredi kartı ya da nakit. Bu işlemden sonra cüzdan bakiyesi güncellenir.
4. Yeterli bakiye varsa ödeme gerçekleşir.
5. İşlemin rezervasyon mu bilet mi olduğu seçilir. Rezervasyonsa otel sistemi bilgilendirilir ve veritabanı işlemleri yapılır. Biletse bilet kesilir ve seyahat firması bilgilendirilir.

**Bilet bilgileri durum diyagramı:** Müşterinin istediği bilet bilgileri onaylanır. Bilet uygunsa devam edilir ve bilet onaylanır. Bilet yoksa müşteriye yeni bir tarih sorulur. Müşteri yeni bilet sorgulamak istemezse çıkış yapabilir.

### 4.8 Birim Testleri

Sistemde bir cüzdan bakiye sistemi vardı. Kullanıcı kendine bir cüzdan tanımlayıp bakiye yükleyebiliyor ve ödemeyi oradan yapabiliyordu. Grup bunu e-ticaret sitelerindeki cüzdan uygulamalarına benzetti. Cüzdanın yanında nakit, kredi kartı ve çekle ödeme de vardı. Testler üyeler arasında şöyle bölüşülmüştü:

- **Cüzdanla ödeme testi:** Cüzdanda yeterli bakiye varsa test başarılı olur. Yoksa "yeterli bakiye yok" uyarısı verilir. Örnekte cüzdanda 200 lira, biletin fiyatı 100 liraydı. Test başarılı olduktan sonra mevcut ve kalan bakiye yazdırıldı. Kalan bakiye $200 - 100 = 100$ liradır (ara adım eklendi).
- **Kredi kartıyla ödeme testi:** On altı haneli kart numarası, son kullanma tarihi ve CVV numarasıyla örnek bir kart girilir. Örnek otel fiyatı 300'dür. Proje tanımında belirtilmediği için kartta her zaman yeterli limit olduğu kabul edildi. Bu yüzden ödeme başarıyla gerçekleşir ve kalan bakiye yazdırılır.
- **Çek bakiye hesaplama testi:** Müşteri çekle bakiyesine ekleme yaptığında çalışan fonksiyonu sınar. Çekle aktarılan tutar ile bakiyede hazır bulunan tutarın toplamının doğru olup olmadığını kontrol eder.
- **Tatil puanı hesaplama testi:** Grubun kendi oluşturduğu puan formülünün doğru sonuç verip vermediğini kontrol eder.
- **Tatil seçim ekranı testi:** Konum, başlangıç ve bitiş noktaları seçilir, örneğin "İstanbul" bir değişkene atanır. Arama yapıldıktan sonra beklenen değerler karşılanıyorsa test başarılıdır. Bu testte üç farklı değer sınanıyordu.
- **Ulaşım seçim ekranı testi:** Kalkış yeri, varış yeri ve ulaşım türü (uçak, tren ya da otobüs) seçilir. Arama düğmesinden sonra değerler karşılanıyorsa test başarılıdır. Sonuçta "test başarılı" ya da "test başarısız" yazdırılır.

<!-- BELİRSİZ: Puan formülünün kendisi derste verilmedi. -->

## 5. Dördüncü Sunum: Seyahat Acentesi Rezervasyon ve Bilet Sistemi

### 5.1 Sistemin Yapısı

Bu grup da seyahat acentesi vakasını seçmişti. Sistem tatil ve ulaşım hizmetlerini yönetmek için bir bilgi sistemiydi ve iki temel hizmete ayrılıyordu:

- **Rezervasyon hizmeti:** Kullanıcılar belirli bölgelerdeki belirli otellerden belirli tarih ve fiyatlarla rezervasyon yapar.
- **Bilet hizmeti:** İki konum arasında, örneğin otellerin bulunduğu bölgeler arasında, belirli bir zaman için ulaşım sağlar.

Sistemde iki tür giriş vardı:

- **Standart kullanıcı:** Hizmetlerden yararlanır, rezervasyon ve bilet alır ya da bunları iptal eder.
- **Seyahat acentesi:** Bütün kullanıcıların, havuzdaki bütün otellerin, bütün rezervasyon ve biletlerin yönetiminden sorumlu yönetici (admin) rolüdür.

### 5.2 Kabuller ve Kısıtlar

Kabul olarak müşterilerin bilet ve tatil alımlarında puan kazanacağı, bu puanların bir havuzda toplanıp gelecekteki tatillerde kullanılacağı belirtildi. Kısıtlar şunlardı:

- Sistem yalnız kredi kartıyla ödeme kabul eder. Grup bunun sistemin olumsuz yanı olduğunu söyledi.
- Sistem yalnız belirli bölge ve tarihler için otel rezervasyonu kabul eder. Bu bölge ve tarihler, otellerin rezervasyon kabul ettiği bölge ve tarihlerle sınırlıdır.

### 5.3 Gantt Diyagramı, Ekip ve Risk Tablosu

Gantt diyagramında şu aşamalar vardı: proje konusunun belirlenmesi (25 Mart-5 Nisan), planın belirlenmesi (14 Nisan), görev dağılımı (23-24 Nisan), kodlama (20 Nisan-6 Mayıs), diyagramların çizilmesi (1-3 Mayıs) ve test ile kontrol (1-8 Mayıs).

Hoca bu çizelgeye bir eleştiri getirdi: Grup yazılım geliştirme sürecinin takibini fazla göstermemişti. Hoca bunun daha ayrıntılı verilebileceğini söyledi.

> **Ders sonrası not:** Altyazıya göre kodlama (20 Nisan) diyagramların çizilmesinden (1 Mayıs) önce başlıyor. Bu, analiz ve tasarımın kodlamadan önce geldiği şelale sırasına uymuyor. Altyazıdaki tarihler büyük olasılıkla yanlış duyulmuş olabilir ya da çizelge gerçekten böyleydi; hoca bu konuda ayrıca bir şey söylemedi.

Ekip organizasyonunda modelleme ve kodlama, arayüz tasarımı desteği, UML diyagramlarının hazırlanması, şema ve tabloların hazırlanması ve Gantt diyagramının hazırlanması görevleri dağıtılmıştı.

Risk tablosu üç başlıkta toplanmıştı:

- **Kullanıcı kaynaklı riskler:**
  - Gereksinimlerin sürekli değişmesi. Kullanıcılar proje ortasında fikir değiştirip farklı taleplerle gelebilir, bu da baştaki planı bozar.
  - Kullanıcının ilgi eksikliği. Kullanıcı iletişim kurmuyorsa ya da uygulamayı bilinçli kullanmıyorsa sorun çıkar.
- **Teknik riskler:**
  - Gerçekçi olmayan planlama. Baştan düzgün planlanmayan süreçte ortada sorunlar çıkar.
  - Yanlış kullanıcı arayüzü geliştirme. Olasılığı düşük ama olursa etkisi çok yüksektir.
  - Gereksiz özelliklerin eklenmesi. İnsanlar genelde daha basit ve sade bir sistem ister.
  - Beklenmeyen kullanıcı arayüzü zorlukları. Geliştiriciye uygun gelen arayüz gerçek kullanıcıda sorun çıkarabilir.
- **Personel kaynaklı riskler:**
  - Kilit personelin yetenekleri.
  - Uygun olmayan yöntem kullanımı ve kötü proje yönetimi. Bu durumda teslim tarihi kaçabilir ya da planlanmayan başka sorunlar çıkabilir.

### 5.4 Sınıf Diyagramı

Sınıf diyagramında beş sınıf vardı:

| Sınıf | Görevi | Nitelikler ve metotlar |
|---|---|---|
| Seyahat acentesi (Travel Agency) | Sistemin ana nesnesi, öteki sınıflarla etkileşimi yönetir | Bilet, rezervasyon ve otel sınıflarıyla ilişkili |
| Müşteri (Customer) | Acentenin hizmetlerini kullanan kişi | Bilet alabilir, otel rezervasyonu yapabilir |
| Bilet (Ticket) | Havayolu, otobüs, tren gibi ulaşım hizmetlerinin biletleri | Fiyat, kalkış ve varış noktaları, tarihler; satın alma ve iptal etme |
| Rezervasyon (Reservation) | Otel rezervasyonu | Otel adı, konum, giriş ve çıkış tarihleri; oluşturma ve iptal etme |
| Otel (Hotel) | Acenteyle anlaşmalı otel | Ad, konum, mevcut oda sayısı, fiyatlar |

Grup önce diyagramları sözlü olarak okumaya başladı. Hoca bunun yerine diyagramların üzerinden anlatılmasını istedi.

### 5.5 Sıralama Diyagramı

Sıralama diyagramındaki akış şöyleydi:

1. Müşteri nesnesi bir bilet ya da otel rezervasyonu talep eder ve talep seyahat acentesine yönlendirilir.
2. Seyahat acentesi rezervasyon nesnesine bir sorgu gönderir: boş yer olup olmadığı ve fiyat bilgisi.
3. Rezervasyon nesnesi bilgileri seyahat acentesine geri gönderir, acente de müşteriye iletir.
4. Müşteri bilgileri onaylarsa ödeme yapar.
5. Seyahat acentesi rezervasyon nesnesine talebin tamamlanmasını bildirir. Bu genelde biletin kesilmesi ya da otel rezervasyonunun onaylanması anlamına gelir.
6. Rezervasyon nesnesi seyahat acentesine ve müşteriye işlemin tamamlandığını bildirir.

Hoca bu diyagramın hangi aşamada kullanıldığını sordu. Altyazıda bu soruya doğrudan bir cevap yok. Hoca biraz sonra rapor düzeni üzerine konuşurken sıralama diyagramını tasarım aşamasına koydu (bkz. Bölüm 6).

### 5.6 Etkinlik ve Durum Diyagramları

Grup ardından karar noktası içeren bir akış anlattı: Müşteri bilet ya da otel rezervasyonu talep eder. Acente hizmetin mevcut olup olmadığını kontrol eder. Bu bir karar noktasıdır ve süreç iki yoldan birini izler. Hizmet mevcut değilse süreç durur. Mevcutsa acente müşteriye mevcudiyet ve fiyat bilgisini iletir. Müşteri bilgileri onaylar ve ödeme yapar. Ödeme onayından sonra acente bileti keser ya da otel rezervasyonunu yapar.

Ardından üç aktörlü bir akış anlatıldı: müşteri, çalışan ve yönetici. Müşteri bilgiyi sisteme iletir, bilgi çalışana gider ve rezervasyon isteği olarak işlenir. Çalışan isteği alıp mevcudiyet kontrolü yapar ve sonucu müşteriye iletir. Uygun bir seçenek varsa müşteri ödeme yapar. Ödeme puan ve indirimlerle hesaba yansır. Yönetici rezervasyon isteğini, ödemeyi, puanları ve indirim ayarlarını görebilir.

<!-- BELİRSİZ: Altyazıda karar noktalı akış "durum diyagramı" diye anılıyor, ama anlatım bir etkinlik diyagramına uyuyor. Üç aktörlü akışın da hangi diyagram türü olduğu (etkinlik diyagramı kulvarlarla mı, başka bir diyagram mı) altyazıdan anlaşılmıyor. -->

Son olarak grup durum diyagramını anlattı. Rezervasyon nesnesinin durumları şöyleydi:

1. **Talep edildi:** Müşteri acenteye rezervasyon talebiyle gelir.
2. Acente mevcudiyeti kontrol eder. Mevcutsa **rezervasyon mevcut** durumuna, değilse **mevcut değil** durumuna geçilir ve süreç biter.
3. Mevcut durumundan sonra acente fiyat bilgisini verir. Müşteri onayladığında **onaylandı** durumuna geçilir.
4. Müşteri ödeme yapar. Ödeme onaylandığında **ödeme alındı** durumuna geçilir ve rezervasyon tamamlanır.

### 5.7 Use Case Belgesi Sorusu

Hoca grubun use case belgesi olup olmadığını sordu. Grup ayrıca bir belge hazırlamadığını, sunumda anlatmayı düşündüğünü söyledi. Hoca sunumun rapordan yapıldığını teyit ettikten sonra raporun nasıl düzenlenmesi gerektiğini anlattı.

### 5.8 Birim Testleri

Bu grupta birim testlerini tek bir üye yazmıştı. İki test vardı:

- **Kayıt testi:** Kayıt için gereken kriterler tanımlanır. Kriterler sağlanırsa kullanıcının kaydolup giriş yaptığı doğrulanır.
- **Kullanıcı silme testi:** Sistemde var olan bir kullanıcının silinmesi sınanır.

Her iki testin de başarılı geçtiği gösterildi.

## 6. Hocanın Rapor Düzeni Önerisi

Hoca dördüncü sunumdan sonra raporun yapısına dair genel bir öneri yaptı. Diyagramlar birbiri ardına şekiller gibi gösterilmemeli. Rapor yazılım geliştirme aşamalarına göre bölüm bölüm düzenlenmeli.

> **Hocanın vurgusu:** Gereksinim analizi bölümünde use case diyagramı, use case belgesi (kullanım senaryoları) ve varsa kavramsal sınıf diyagramı verilmeli. Tasarım bölümünde ardışıl (sıralama) diyagram, durum diyagramı ve aktivite diyagramı tasarımı anlatmalı. UML sınıf diyagramı da bu bölümde tamamlanmış haliyle verilmeli. Bu düzen farkındalık açısından daha iyidir.

## 7. Sunumlardan Çıkan Ortak Dersler

Dört sunumdaki sorular ve geri bildirimler bir arada şu dersleri veriyor:

- **Kabul ve kısıt ayrımı:** Kabuller projenin dayandığı olumlu varsayımlardır. Kısıtlar problemdeki, sistemdeki ya da projedeki sınırlamalardır. İkisi ayrı başlıklarda yazılmalı.
- **Kısıtın gerekçesi:** Bir kısıt yalnız emir cümlesiyle değil, gerekçesiyle yazılmalı. Örneğin programlama dili seçimi ekip bilgisine ya da sisteme uygunluğa dayandırılmalı.
- **Risk takibi:** Risk tablosunda hangi risklerin takip edileceği belirlenmeli. Olasılığı ve etkisi yüksek ya da orta-yüksek olanlar izlenir, düşük olanlar ihmal edilebilir. Bunun için bir eşik konabilir.
- **Süreç takibi:** Gantt diyagramında yazılım geliştirme sürecinin aşamaları ve takibi ayrıntılı gösterilmeli. Hoca her grupta Gantt'ın hangi araçla çizildiğini ve hangi süreç modelinin seçildiğini sordu. Gruplar çoğunlukla şelale modelini kullandı.
- **Sınıf diyagramındaki çizgiler:** Kesikli ok bağımlılığı gösterir. Bir sınıf ötekini nitelik olarak tutmuyor, yalnız bir metodunda örneğini oluşturuyorsa kullanılır.
- **Sıralama diyagramının düzeni:** Nesneler genelde üstte aynı hizada dizilir.
- **Birim testi sorumluluğu:** Her geliştirici kendi yazdığı birimin testini yazmalı.
- **Rapor düzeni:** Diyagramlar analiz ve tasarım aşamalarına göre gruplanmalı.

## Örnek Sorular

Bu derste hazır kare ya da video yoktu. Aşağıdaki sorular hocanın sunumlar sırasında gruplara sözlü olarak sorduğu teknik sorulardır.

**Soru 1** (derste sözlü, 00:19:10)

Tasarım sınıf diyagramınızda bazı bağlantılar kesikli çizgiyle çizilmiş. Bunun anlamı nedir?

> **Çözüm (derste verilen cevap):** Bağlantılı sınıf doğrudan bir nitelik olarak tutulmuyor, örneği bir metot içinde oluşturuluyor. Bu yüzden kesikli çizgi kullanılır. UML'de bu ilişkinin adı bağımlılıktır (dependency).

**Soru 2** (derste sözlü, 00:24:37)

Birim testlerinin dışında kullanıcı testi gibi bir testiniz var mı?

> **Çözüm (derste verilen cevap):** Grup yalnız birim testleri yaptığını, kullanıcı testi derste işlenmediği için uygulamadığını söyledi.

**Soru 3** (derste sözlü, 00:36:41)

Gantt diyagramını nerede çizdiniz ve hangi süreç modelini kullandınız?

> **Çözüm (derste verilen cevap):** Grup bir online Gantt aracı kullandığını ve şelale (waterfall) modelini seçtiğini söyledi. Bu modelde aşamalar sırayla ilerler: alan tanımı ve plan, gereksinim modelleme, sınıf diyagramları, sıralama, etkinlik ve durum diyagramları, arayüz tasarımı ve kodlama, birim testleri, rapor.

**Soru 4** (derste sözlü, 00:38:28)

Risk tablosundaki risklerden hangileri uygulama boyunca her aşamada takip edilmeli? Bunları nasıl belirlersiniz?

> **Çözüm (derste verilen cevap):** Etkisi büyük ve olasılığı yüksek olanlar takip edilir. Hoca cevabı tamamladı: Olasılığı ve etkisi orta-yüksek olanlar da takip edilebilir, düşük ve orta olanlar ihmal edilebilir. Ya da hangi düzeyden itibaren takip edileceğine dair bir eşik konur.

**Soru 5** (derste sözlü, 00:45:11)

Herkes kendi yazdığı birimin birim testini kendisi mi yaptı?

> **Çözüm (derste verilen cevap):** Evet. Hoca bunun doğru bir uygulama olduğunu, her geliştiricinin kendi biriminin testini ayrı ayrı oluşturması gerektiğini söyledi.

**Soru 6** (derste sözlü, 01:09:28)

Bu ardışıl (sıralama) diyagramı nasıl çizdiniz? Nesneler genelde aynı hizada olur. Burada farklı hizada olması aracın bir hatası mı, yoksa bilerek mi böyle çizildi?

> **Çözüm (derste verilmedi):** Grup kullandığı aracı hatırlayamadı, soruya net bir cevap verilmedi. UML kuralına göre nesneler genelde üstte aynı hizada başlar. Bir nesne etkileşim sırasında `create` mesajıyla yaratılıyorsa kutusu yaratıldığı yükseklikte çizilir. Bunun dışında farklı hiza diyagramın okunmasını zorlaştırır ve düzeltilmelidir.

**Soru 7** (derste sözlü, 01:29:19)

Bu diyagram (sıralama diyagramı) hangi aşamada kullanılır?

<!-- BELİRSİZ: Grubun bu soruya cevabı altyazıda yok; cevap hocanın 01:31:56'daki rapor düzeni açıklamasından kurulmuştur. -->

> **Çözüm (hocanın sonraki açıklamasından):** Sıralama diyagramı tasarım aşamasında kullanılır. Hocanın önerdiği düzende gereksinim analizinde use case diyagramı, use case belgesi ve kavramsal sınıf diyagramı yer alır. Tasarımda ise ardışıl, durum ve aktivite diyagramları ile tamamlanmış UML sınıf diyagramı yer alır.

**Soru 8** (derste sözlü, 01:31:35)

Use case belgeniz var mıydı?

> **Çözüm (derste verilen cevap):** Grup ayrı bir use case belgesi hazırlamadığını söyledi. Hoca, gereksinim analizi bölümünde use case diyagramının yanında use case belgesinin (kullanım senaryosu metinlerinin) de bulunması gerektiğini belirtti. Bu belgede ilgililer ve beklentileri, ön koşullar, son koşullar, ana senaryo ve alternatif akışlar yazılır.

## Dersin Toparlaması

Bu derste dört grup dönem projesini sundu: bir medya takip şirketi bilgi sistemi, bir yazılım evinin insan kaynakları sistemi ve iki seyahat acentesi bilet ve tatil sistemi. Her sunum, dönem boyunca işlenen yazılım geliştirme aşamalarını somut bir proje üzerinde gösterdi. Proje planında alan tanımı, kabuller ve kısıtlar, Gantt diyagramı, ekip şeması ve risk tablosu yer aldı. Gereksinim modellemede use case diyagramı, kullanım senaryoları ve izlenebilirlik tablosu kullanıldı. Tasarımda sınıf, sıralama, etkinlik ve durum diyagramları çizildi. Son olarak birim testleri gösterildi.

Hocanın geri bildirimleri birkaç noktada toplandı: kabuller ile kısıtların ayrı yazılması ve kısıtların gerekçelendirilmesi, risklerin olasılık ve etkiye göre takip edilmesi, sınıf diyagramındaki bağımlılık çizgisinin anlamı, sıralama diyagramında nesnelerin hizası, her geliştiricinin kendi biriminin testini yazması ve raporun analiz ile tasarım aşamalarına göre düzenlenmesi. Kalan gruplar bir sonraki derste sunum yapacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
