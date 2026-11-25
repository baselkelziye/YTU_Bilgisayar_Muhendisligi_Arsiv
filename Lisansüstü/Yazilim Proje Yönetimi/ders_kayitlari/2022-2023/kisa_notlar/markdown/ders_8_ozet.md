# Ders 8 Çalışma Özeti

## Genel Konular

- Proje planlamanın on beş aktivitesinin tekrarı (ekrandan, 00:20:00)
  - Ders, "Information Systems Project Management" kitabının proje planlama bölümünü izler. Kitaba göre proje planlama şu on beş aktiviteden oluşur:
    - 1\. Proje risklerini tanımlamak ve bunları azaltacak eylemleri belirlemek
    - 2\. Proje kabullerini (varsayımlarını) ve kısıtlarını listelemek
    - 3\. Kalitenin nasıl yönetileceğini belirlemek
    - 4\. Aktivite ve maliyet bileşenleri listesini oluşturmak
    - 5\. Aktiviteler arasındaki bağımlılıkları kurmak
    - 6\. İş gücünü ve maliyetleri tahmin etmek
    - 7\. İş takvimini ve kilometre taşlarını (milestone) hazırlamak
    - 8\. Proje kaynaklarını atamak ve seviyelendirmek
    - 9\. Bütçeyi ve takvimi müşteri gereksinimleriyle uyumlu hale getirmek
    - 10\. Proje bütçesini hazırlamak
    - 11\. Proje belgelerini (evrak işlerini) yönetmek
    - 12\. Uygulamaya geçişi (implementation) planlamak
    - 13\. Tamamlanmayı planlamak
    - 14\. İletişimi planlamak
    - 15\. Proje planını yazmak
  - Aktivite listesi, daha önce seçilen yazılım geliştirme süreç modeline bağlıdır; model değişirse aktiviteler de değişir.
  - Bağımlılık türleri: bitiş-başlangıç (finish-start), başlangıç-başlangıç (start-start), bitiş-bitiş (finish-finish).
  - 4-9 arası maddeler iç içe geçmiştir ve MS Project gibi bir proje planlama aracında (ücretsiz ve açık kaynaklı seçenekler de vardır) birlikte yürütülür; süre tanımı ve en iyi yolun bulunması PERT diyagramıyla, iş takvimi Gantt ile yapılır.
- Kaynak atama ve seviyelendirme
  - En önemli kaynak insan kaynağıdır (iş gücü).
  - Önce görevler işi en iyi yapacak kişilere göre atanır; sonra kişi bazlı planda bazı kişilerin aşırı yüklü, bazılarının boş olduğu görülür ve iş yükü yeniden dağıtılarak seviyelendirilir.
  - Herkes doluysa projeye özel ya da kalıcı yeni eleman alınması düşünülür.
- Bütçe ve bütçe kalemleri
  - Bütçe, görevlere atanan kişilerin ücretleri ve görevde çalıştıkları saatlerden çıkarılır.
  - Başlıca kalemler: iş gücü (birinci kalem), satın alınacak donanım, ağ/bağlantı ücretleri, kira ve malzeme gibi süreli giderler, danışmanlık ücretleri, seyahat harcamaları, sarf malzemeleri.
  - Her kalem bütçede ayrı bir satırdır; ayrıntılar ayrı tablolarda verilir.
- Teslim edilecekler, uygulama ve iletişim planlaması
  - Dağıtım listesinde test planları, yarı ürünler ve ürünler yer alır (dağıtım listesi, projenin tanımlanması aşamasında görülmüştü).
  - Grup içi iletişimin nasıl yürüyeceği planlanır.
- Risk kategorileri (kitaptaki sınıflama) (ekrandan, 00:30:00 ve 00:35:00)
  - Personel (staff) riskleri: anahtar personelin gerektiğinde bulunmaması, anahtar yeteneklerin gerektiğinde bulunmaması, proje sırasında personel kaybı.
  - Donanım (equipment) riskleri: donanımın zamanında teslim edilmemesi, donanıma erişimin kısıtlanması, donanım arızası.
  - Müşteri (client) riskleri: müşteri kaynaklarının gerektiği gibi sağlanmaması, müşteri personelinin kararları zamanında vermemesi, teslim edilenlerin takvime göre gözden geçirilmemesi, bilgili müşteri personelinin daha az yetkin kişilerle değiştirilmesi.
  - Kapsam (scope) riskleri: ek iş gerektiren gereksinimlerin ortaya çıkması, kapsam değişikliklerinin projeye dahil sayılması, kapsam değişikliklerinin proje yönetiminin bilgisi dışında yapılması.
  - Teknoloji riskleri: teknolojinin projeyi tehlikeye atan teknik ya da performans sınırları, bileşenlerin kolay bütünleşememesi, teknolojinin yeni ve az anlaşılmış olması.
  - Dağıtım (delivery) riskleri: teslim sürelerine uyulmaması, kapasite ve işlevsel gereksinimlerin karşılanamaması.
  - Fiziksel riskler: afet, hasar, virüs gibi; seyrek görülür ama gerçekleşirse yıkımı büyüktür.
- Risk tablosu ve risk takibi
  - Her risk için kategori, olma olasılığı ve gerçekleşirse etkisi belirlenir; ikisi birleştirilerek riskin derecesi (düşük, orta, yüksek) bulunur.
  - En etkili riskler takibe alınır: her kilometre taşında olasılık ve etkinin hâlâ aynı olup olmadığı kontrol edilir.
  - Her risk için alınacak önlem, önlemin maliyeti ve takip planı belirlenir.
  <!-- BELİRSİZ: Risk tablosunun kitaptaki sütunları kareden görülmedi; altyazıda tarih, açıklama, olasılık, etki ve derece geçiyor. -->
- Proje kabulleri (assumptions) (ekrandan, 00:40:00 ve 00:50:00)
  - Kabuller, doğru çıktığında projeye destek olan, iş yükünü azaltan ve kaynakları güvenceye alan varsayımlardır; geçersiz çıkarlarsa proje zarar görür.
  - Kaynak kabulleri: proje personeli, bilgisayar kaynakları ve müşteri kaynakları gerektiğinde erişilebilir olacak; personelin en az n yüzdesi geliştirme ortamında deneyimli olacak; müşteri, işlevsel gereksinimleri ayrıntılı anlatabilecek personel sağlayacak.
  - Dağıtım kabulleri: onaya sunulan teslim edilenler n iş günü içinde geri dönecek; donanım siparişleri belirtilen sürede gelecek.
  - Ortam kabulleri: projeyi etkileyecek aykırı bir durum olmayacak, sorunlar zamanında çözülecek, tanımlanan proje organizasyonu kurulacak, belirlenen metodoloji (örneğin Scrum) kullanılacak, müşterinin iç süreçleri (satın alma gibi) zamanında tamamlanacak, sistem bileşenleri bütünleşebilecek.
  - Bütçe kabulleri: tahminlerin belirli bir doğrulukta olduğu, listede olmayan seyahat ya da sarf giderine ihtiyaç olmayacağı, danışmana gerek olmayacağı ya da danışmanlık giderinin bütçedeki kadar kalacağı.
  - İşlevsel kabuller: yazılımın iş alanıyla ilgili varsayımlar.
- Proje kısıtları (constraints) (ekrandan, 00:45:00 ve 00:55:00)
  - Kabuller ve kısıtlar çoğu zaman birbirinin tersidir: ağ yöneticisinin yarı zamanlı çalışabileceği bir kabul olarak da, daha fazla çalışamayacağı bir kısıt olarak da yazılabilir.
  - Kısıtlar da aynı sınıflarla verilir: kaynak (anahtar personel yarı zamanlı, bilgisayar kaynakları sınırlı, müşteri kaynakları kısıtlı), dağıtım (gözden geçirme için en az n iş günü gerekmesi, donanım teslim süresinin kesin belirlenememesi), ortam (geliştirme ortamının ya da metodolojinin ekip için yeni olması, müşteri iç süreçlerinin yetersiz ve öngörülemez olması), bütçe (seyahat ya da danışmanlık giderlerinin tam tahmin edilememesi), işlevsel (kapsamın belirsiz olması, projenin başka bir uygulamadan veri almasına bağlı olması).
- Proje planı dokümanının içeriği (ekrandan, 01:25:00)
  - Giriş ve proje tanımı: amaç, kapsam, temel teslim edilecekler, iş gereksinimi ya da fırsat, finansal tahmin.
  - Tamamlanma kriterleri (proje türüne göre değişir).
  - İş planı: teslim edilecekler, genel yaklaşım, iş kırılım yapısı (WBS), iş listesi, kilometre taşları, tahmini zaman, bütçe ve nakit akışı.
  - Proje organizasyonu ve ekip yapısı, görevler için gereken yetenekler.
  - Kapsam yönetim planı, takvim yönetim planı (olası kaymalar, kontrol süreçleri), maliyet yönetim planı, risk yönetim planı, iletişim yönetim planı, kalite yönetim planı.
  - Ekler: risk kontrol listeleri, ayrıntılı iş listesi, WBS, proje paydaşları.
  - Kitaptaki içerik tablosu bir taslaktır; IEEE proje planı formatı da kullanılabilir.
- Tamamlanma kriterleri (ekrandan, 01:20:00)
  - Uygulama geliştirme: kabul testlerinin başarıyla bitmesi, kullanıcı eğitiminin tamamlanması, uygulamanın devreye alınması, tarih karşılaştırması, mevcut sistemin kullanımdan kaldırılması, destek gruplarına devir.
  - Sistem entegrasyonu: garanti süresinin tamamlanması, uygulama bakım, yardım masası ve üretim prosedürlerinin kurulması, üretime devir.
  - Altyapı: donanım ve sistem yazılımı kurulumunun tamamlanması, sistem testinin başarıyla bitmesi, masaüstü değişikliklerinin tamamlanması, sistem destek ve yardım masası prosedürlerinin kurulması.
  - Yalnız analiz projesi: son SRS raporunun hazırlanması, gözden geçirilmesi, sunulması ve müşteri görüşlerinin alınması.
- Projeyi yürütme (Running the Project) (ekrandan, 01:30:00)
  - Planlamadan sonra gereksinim analizi, tasarım ve gerçekleştirme sürerken kontrol mekanizması kurulur.
  - Kontrol soruları: Etkin bir ekip kuruluyor mu? Takvim, tahmin ve bütçeye göre neredeyim? Riskler yönetiliyor mu? Takvim sorunları çözülüyor mu? Kapsam değişikliği istekleri yönetiliyor mu? Kalite yönetiliyor mu? Gerektiğinde ayrıntıya iniliyor mu? Alt yükleniciler taahhütlerini yerine getiriyor mu? Müşterinin beklentileri anlaşılıyor ve karşılanıyor mu? Düzenli ve etkin ekip toplantıları yapılıyor mu? Proje durumu ve açık sorunlar düzenli raporlanıyor mu? İlerleme üzerine düşünmeye zaman ayrılıyor mu? Ekip başarılarını kutluyor mu?

## Hocanın Özellikle Vurguladığı Kısımlar

- Risk kategorileri kurum düzeyinde sabit olmalı
  - Her projede farklı kategori ve adlandırma kullanmak yerine yazılım geliştirme ekibi ya da kurum bir kez kategori tanımı yapar ve hep onu kullanır. Böylece riskler için arşiv bilgisi tutmak ve projeler arası araştırma yapmak kolaylaşır.
- Kapsam değişikliklerinin kurallı yürütülmesi
  - En büyük risklerden biri, proje yöneticisinin bilgisi olmadan sistem analistlerine doğrudan istek iletilmesi ve gereksinimlerin kuralsız değiştirilmesidir. Müşteri ile geliştirici arasında kurallı bir alan (kapsam) tanımı ve değişiklik prosedürü olmalıdır.
- Müşteri kaynaklarının önemi
  - Müşteri iş gücü özellikle gereksinim analizinde gereklidir; işi doğru anlatabilecek kişiler seçilmeli, anlatamayan kişi değiştirilmelidir.
- Fiziksel riskler
  - Seyrek görülürler ama gerçekleştiklerinde yıkımları büyüktür.
- Riskin takibi
  - Risk bir kez belirlenip bırakılmaz; her kilometre taşında olasılık ve etki yeniden değerlendirilir.
- Projeyi yürütmenin özü
  - Planlanan ile gerçekleşen arasındaki fark her adımda görülebilmeli ve izlenebilmelidir.

## Kısa Tekrar Notları

- Proje planlama 15 aktiviteden oluşur; 4-9 arası maddeler bir planlama aracında iç içe yürütülür.
- Bağımlılık türleri: FS, SS, FF.
- Kaynak yönetimi: önce atama, sonra seviyelendirme; gerekirse yeni eleman.
- Bütçenin birinci kalemi iş gücüdür; ardından donanım, bağlantı, danışmanlık, seyahat, sarf malzemesi gelir.
- Risk sınıfları: personel, donanım, müşteri, kapsam, teknoloji, dağıtım, fiziksel.
- Risk derecesi = olasılık ile etkinin birleşimi; düşük, orta, yüksek.
- Kabul: doğru çıkarsa projeye yarayan varsayım. Kısıt: projeyi sınırlayan koşul. Çoğu zaman birbirinin tersidir.
- Kabul ve kısıt sınıfları: kaynak, dağıtım, ortam, bütçe, işlevsel.
- Proje planı dokümanı: tanım, tamamlanma kriterleri, iş planı, organizasyon, kapsam/takvim/maliyet/risk/iletişim/kalite yönetim planları, ekler.
- Tamamlanma kriterleri proje türüne (uygulama geliştirme, sistem entegrasyonu, altyapı, analiz) göre değişir.
- Projeyi yürütme: planlanan ile gerçekleşenin sürekli karşılaştırılması.

## Detaylı Açıklamalar

- Bu ders, proje planlama konusunun toparlandığı derstir. Kitaptaki on beş planlama aktivitesi baştan gözden geçirilir. Aktivitelerin listelenmesi, seçilen süreç modeline bağlıdır; örneğin şelale ile çevik bir model farklı aktivite listeleri doğurur. Aktiviteler belirlendikten sonra aralarındaki bağımlılık türü (bitiş-başlangıç, başlangıç-başlangıç, bitiş-bitiş) tanımlanır, her aktiviteye süre verilir, PERT diyagramıyla en iyi yol bulunur ve Gantt şemasıyla takvim çıkarılır. Kilometre taşları aynı zamanda gözden geçirme noktaları olarak kullanılabilir.
- Kaynak seviyelendirmede amaç, insan kaynağının dengeli kullanılmasıdır. İlk atama işi en iyi yapacak kişilere göre yapıldığından bazı kişilerin planı aşırı dolar. Bu kişilerin bazı işleri diğerlerine aktarılır; herkes doluysa dışarıdan proje bazlı ya da kalıcı eleman alınır. Bütçe ise kişilerin ücretleri ve göreve ayırdıkları saatlerle başlar, donanım, bağlantı, kira, danışmanlık, seyahat ve sarf malzemesi gibi kalemlerle tamamlanır.
- Risk konusunda kitabın sınıflaması önceki derste görülen sınıflamadan (proje, ürün, teknik riskler) farklıdır. Önemli olan hangi sınıflamanın seçildiği değil, kurum içinde tek bir sınıflamanın tutarlı kullanılmasıdır. Risk tablosunda her risk için sınıf, olasılık ve etki yazılır; bunlardan risk derecesi bulunur. Yüksek dereceli riskler için önlem, önlemin maliyeti ve takip planı belirlenir; her kilometre taşında risk yeniden değerlendirilir.
- Kabuller ve kısıtlar proje planının temel girdileridir. Projelerde sorun çıktığında neden çoğu zaman geçersiz çıkan bir kabul ya da hiç belirlenmemiş bir kısıttır. Örneğin müşterinin ana bilgisayarının (mainframe) günde 24 saat erişilebilir olacağı kabul edilirse ve müşteri ekibi normal sekiz saatlik iş gününe sınırlarsa proje zarar görür; tersine normal iş günü varsayılıp müşteri 24 saat erişim sağlarsa proje kazançlı çıkar (ekrandan, 00:40:00). Kısıtlarda da benzer örnekler vardır: hep Scrum ile çalışan bir ekibin yeni projede ilk kez Kanban kullanması bir ortam kısıtıdır; projenin girdilerinin başka bir uygulamanın çıktısı olması ise işlevsel bir kısıttır, çünkü o uygulamanın beklenmesi gerekebilir.
- Proje planı dokümanı, planlama aktivitelerinin çıktılarını bir araya getirir. Proje tanımı ve amaçtan sonra tamamlanma kriterleri gelir: projenin bittiğine hangi ölçütlerle karar verileceği proje türüne göre baştan yazılır. İş planı WBS, iş listesi ve kilometre taşlarını; yönetim planları ise kapsam, takvim, maliyet, risk, iletişim ve kalite konularını içerir. Çevik yürüyen projelerde iletişim daha sık ve daha önemli olur.
- Planlamadan sonra gelen "projeyi yürütme" aşamasında yöneticinin kendine sorduğu kontrol soruları, planın gerçekle karşılaştırılmasına dayanır: ekip etkin mi, takvim ve bütçe tutuyor mu, riskler ve kapsam değişiklikleri yönetiliyor mu, müşteri beklentileri karşılanıyor mu, durum raporları düzenli mi. Ekibin başarılarını kutlaması ve proje bilgilerinin arşivlenmesi projenin kapatılması aşamasında ele alınacaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
