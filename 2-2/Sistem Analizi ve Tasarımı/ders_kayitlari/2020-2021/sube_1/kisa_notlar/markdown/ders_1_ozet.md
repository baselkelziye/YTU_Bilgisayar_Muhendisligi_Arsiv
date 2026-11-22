# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin amacı ve kapsamı
  - Şimdiye kadarki derslerde küçük problemler için algoritma kurup program yazıldı. Bu derste bakış açısı yükseltilir: bir problemi baştan sona bir bilgi sistemi olarak nasıl geliştireceğimiz ve bu bilgi sisteminin genel sistemler içindeki yeri ele alınır.
  - Süreç olurluluk (fizibilite) analiziyle başlar, sistem analiziyle sürer, en uygun bilgi sistemi tasarımına karar verilir, tasarım gerçekleştirilir, test edilmiş yazılım kullanıma alınır.
  - Hedef, büyük resmi kaybetmeden ayrıntıları ele alabilmektir.
- Dersin konu akışı (ekrandaki ders planından, 00:05:00)
  - Giriş ve sistem tanımı; sistem tipleri, bilgi sistemi geliştirme sürecindeki taraflar (müşteri, kullanıcı, proje yöneticisi, sistem analisti); sistem geliştirme süreci (şelale/waterfall modeli).
  - Ön inceleme ve fizibilite çalışmaları, zaman fizibilitesi (proje planlamasında zaman planlaması).
  - Sistem analizi: veri toplama, iş analizi, kullanım senaryoları; veri modelleme ve fonksiyonel çözümleme; nesneye yönelik çözümleme.
  - Sistem tasarımı: mimari tasarım (yapı diyagramları, ardışıl diyagramlar), girdi, çıktı, veri yapısı ve arabirim tasarımı.
  - Veritabanı tasarımı, kodlama, test süreçleri, yeni sisteme geçiş, bakım ve destek süreçleri; örnek bir analiz-tasarım vaka çalışması.
- Diğer bölümlerdeki "sistem analizi" dersleriyle fark
  - Elektrik mühendisliğinde sistem analizi, elektrik devrelerinin matematiksel analizidir; bu dersten çok farklıdır.
  - Endüstri mühendisliği ve işletmede ders daha yakındır: endüstriyel/işletme sistemlerinin modellenmesi ve iş analizinin bilgi sistemi geliştirenlere nasıl aktarılacağı anlatılır.
  - Bu derste ise gerçek bir sistemin analiz edilip ona uygun bilgi sisteminin tasarlanması hedeflenir.
- Sistem kavramı
  - Sistem: birbiriyle ilişkili, her biri bir işi ya da fonksiyonu yerine getiren alt sistemlerden (parçalardan) oluşan bütündür. Biyolojik, bilgisayar ve sosyal sistemler örnektir.
  - Bilgi sistemi: işletme görevlerini yerine getirmek için gereken bilgiyi çıktı olarak sağlamak üzere veriyi toplayan, işleyen ve saklayan, iç bileşenleri birlikte çalışan sistemdir.
- Bir sistemin elemanları ("General Depiction of a System" şekli, ekrandan, 00:55:00)
  - Amaç (hedef), sınır (boundary), dış ortamdan gelen girdiler (input), dış ortama verilen çıktılar (output), elemanlar ya da alt sistemler (subsystem), elemanlar arasındaki iç ilişkiler (interrelationship).
- Üniversite örneği
  - Girdi: yeni öğrenciler, yeni öğretim elemanları ve görevliler. Çıktı: mezunlar, yayınlar.
  - Elemanlar: öğrenciler, öğretim üyeleri, idari çalışanlar; cansız elemanlar olarak sınıflar, odalar, laboratuvarlar.
  - Hiyerarşik alt sistemler: üniversite yönetimi, fakülteler, bölümler, ana bilim dalları.
  - İç ilişkiler: yönetmelikler ve mevzuat (lisans, yüksek lisans yönetmeliği gibi).
  - Çevre: mezunların çalıştığı yerler, öğrencilerin aileleri, staj yerleri, ortak projeler yürütülen diğer üniversiteler, Yükseköğretim Kurulu, öğrencinin geldiği liseler.
  - Amaç: iyi mezunlar yetiştirmek ve nitelikli yayın üretmek; kurumlar bunu vizyon, misyon ve hedefler olarak yazar.
- Sistem sınırı ve otomasyon sınırı (Figure 1-4, ekrandan, 01:00:00)
  - Sistemin çevresi en dıştadır; sistem sınırı sistemi çevreden ayırır; sistemin içinde elle yürüyen kısım ve onun içinde otomasyon sınırıyla ayrılan otomatik kısım bulunur.
  - Kurumun personel, öğrenci, evrak takip gibi alt sistemleri aynı yönetim bilgi sisteminde birbiriyle haberleşiyorsa tek bir bütünleşik sistem vardır; bilgi için araya belge gidip geliyorsa sistem tam otomatikleşmemiştir.
- Sistem düşüncesi ("Systems" Thinking, ekrandan, 01:10:00)
  - Bir şeyi sistem olarak tanımlayabilmek, alt sistemlerini belirlemek, sistemin özelliklerini ve fonksiyonlarını belirlemek, sınırların nerede olduğunu (ya da olması gerektiğini) belirlemek, girdileri ve çıktıları belirlemek, alt sistemler arasındaki ilişkileri belirlemek.
  - Hocanın eklediği madde: geri besleme ile çıktıların iyileştirilmesi.
- Geri besleme
  - Çıktılar değerlendirilir; bulunan eksikliklere göre girdiler ya da sistemin işlemleri (fonksiyonları, elemanları) değiştirilir. Her sistem geri beslemeli olmalıdır.
  - Üniversite örneği: akreditasyon (MÜDEK) öz değerlendirmesi, mezun ve staj yerlerinden (paydaşlardan) görüş alınması, buna göre ders eklenmesi/çıkarılması, eksik alanlara öğretim elemanı alınması.
- Bütünleşik işletme sistemi örneği
  - Müşteri destek sistemi (CRM: müşteri bilgileri ve siparişler), envanter yönetim sistemi ve üretim sistemi birbirine bağlı çalışmalıdır; sipariş için hem stok hem üretim bilgisi gerekir.
- Bilgi sistemi tipleri (EIS/DSS kısmı ekrandan, 01:20:00)
  - İşlem işleme sistemi (Transaction Processing System, TPS): tek bir temel işi yapar (bordro, ATM'den para çekme).
  - Yönetim bilgi sistemi (MIS): TPS'leri bir arada çalıştırır, üst yönetime karşılaştırılabilir ve özetlenmiş raporlar üretir (ör. muhasebe bilgi sistemi; bordro onun alt programıdır).
  - Üst yönetim bilgi sistemi (Executive Information System, EIS): yöneticilere stratejik planlama için bilgi verir; bilgi kurum veritabanından ya da borsa raporları gibi dış kaynaklardan gelebilir.
  - Karar destek sistemi (Decision Support System, DSS): seçeneklerin olası etkisini "ne olur eğer" (what if) sorularıyla incelemeye yarar; uzman sistemlerle ve bilgi tabanlı sistemlerle yakından ilişkilidir. Bir Excel tablosu da karar destek aracı olabilir.
- Sistem analistinin bilgi ve becerileri (ekrandan, 01:25:00)
  - Teknik: programlama dilleri, genel bilgisayar bilgisi, ağ, iletişim, veritabanı yönetim sistemleri, işletim sistemleri, geliştirme araçlarının seçimi.
  - İşletme: organizasyonun nasıl çalıştığı, yapısı, yönetimi, hangi kademenin hangi işi yaptığı, aktiviteler ve aktörler, başarı ölçütleri, strateji, planlar ve kurum kültürü.
  - İnsan: en önemli kişilerarası beceri açık ve etkili iletişimdir; insanların nasıl düşündüğü, öğrendiği, değişikliğe nasıl tepki verdiği, nasıl iletişim kurduğu ve çalıştığı bilinmelidir; görüşme, dinleme ve gözlem becerisi, iyi yazılı ve sözlü sunum, ekip çalışması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Diyagramlar resim çizmek değildir
  - Diyagram sembollerinin arkasındaki mantık kaybedilmemelidir. Modelleme, tasarlanacak sistemin sembollerle anlatımıdır.
- Bir sistem olabilmek için amaç şarttır
  - Üniversite örneğinde girdi, çıktı, alt sistem ve ilişkiler sayıldıktan sonra amaç ayrıca tanımlanmadıkça tanım eksik kalır.
- Geri besleme sistem düşüncesinin en önemli maddesidir
  - Slaytta olmasa da hoca bunu sistem kurallarına ekledi ve dersin sonunda tekrar sordu.
- Sistem analisti köprü roldür
  - Küçük firmalarda proje yöneticisi ya da teknik destek ekibi, büyük firmalarda iş analistinden gelen bilgiyi analiz edip tasarıma dönüştüren ve yazılım mühendislerine aktaran kişidir. Kullanıcıların işini değiştirdiğimiz için onların tepkisini önceden kestirebilmelidir.
- Nesneye yönelik ve yapısal yaklaşım
  - Nesneye yönelik programlama dersindeki bazı diyagramlar burada da kullanılır; analiz ve tasarım hem yapısal hem nesneye yönelik yaklaşımla yürütülebilir.

## Kısa Tekrar Notları

- Sistem = amaç + sınır + girdi + çıktı + elemanlar/alt sistemler + iç ilişkiler + geri besleme.
- Alt sistemler hiyerarşik düzenlenir ve ayrıştırılabilir olmalıdır.
- Sistem sınırı sistemi çevresinden, otomasyon sınırı otomatik kısmı elle yürüyen kısımdan ayırır.
- Geri besleme: çıktıyı değerlendir, girdiyi ya da işlemleri düzelt.
- Bilgi sistemi tipleri: TPS (tek iş), MIS (TPS'leri birleştirip raporlar), EIS (üst yönetime stratejik bilgi), DSS ("ne olur eğer" analizi).
- Sistem analistinin üç beceri alanı: teknik, işletme, insan (iletişim en önemlisi).
- Fizibilite = olurluluk, yani yapılabilirlik çalışması.
- Sistem geliştirmede başlangıç modeli şelale (waterfall) modelidir; çevik (agile) ve spiral modeller ileride yazılım mühendisliği dersinde ele alınır.

## Detaylı Açıklamalar

- Dersin yeri: Önceki derslerde problem tanımlanıp algoritma ve program yazılıyordu. Sistem analizi ve tasarımı bir üst seviyeden bakar: önce problemin yapılabilir olup olmadığı (fizibilite) incelenir, sonra mevcut iş bilgisayar devreye girmeden nasıl yürüyor anlaşılır (iş analizi), bu iş modellenir, buna en uygun bilgi sistemi tasarlanır, kodlanır, test edilir ve kullanıma alınır. Bu sürecin ilk modeli olarak şelale modeli kullanılır. Çevik ve spiral modeller gibi alternatifler yazılım mühendisliği dersinin konusudur.
- Sistemin genel tanımı: Sistem, bir hedefi olan, birbiriyle ilişkili elemanlardan oluşan, çevresinden sınırlarla ayrılan, çevresinden girdi alan ve elemanları arasındaki iç ilişkiler ile fonksiyonlar sayesinde çevresine çıktı üreten yapıdır. Sistemin elemanları alt sistemlere ayrılır, alt sistemler hiyerarşik olarak düzenlenir; gerekiyorsa sistemde bir otomasyon kısmı bulunur ve bu otomasyon sınırları içinde nelerin yapılacağı tanımlanır.
- Üniversite örneğinin ayrıntısı: Üniversitede bir öğrenci yalnızca "sistemin elemanı" değildir; hangi fakültenin hangi bölümünün öğrencisi olduğu da hiyerarşi içindeki yeridir. Öğretim üyesi için bu hiyerarşi ana bilim dalına kadar iner. Alt sistemlerin görevleri de ayrı ayrı tanımlanabilir: fakülte, bölümlerinin laboratuvar, ders ve araştırma olanaklarını eşit sağlamak ve üniversite yönetimiyle iletişimi yürütmekle; bölüm ise laboratuvar bakımı, ders programlarının yapılması ve yeni ders açma kararlarıyla görevlidir. Liselerde hangi derslerin okutulduğunu bilmek, gelen öğrencinin ne bildiğini anlayıp müfredatı ona göre kurmak için gerekir; bu yüzden liseler de sistemin ortamındaki ilişkili kurumlardır.
- Geri besleme örneği: Üniversite, akreditasyon için yaptığı öz değerlendirmede iyi yaptığını söylemekle yetinemez, bunu belgelemek zorundadır. Mezunların ve staj yapılan kurumların görüşleri alınır; sektörden test konusunda ders talebi gelmesi üzerine daha önce yüksek lisansta verilen yazılım kalite süreçleri dersi lisansa seçimlik olarak eklenmiştir. Değerlendirme sonuçlarına göre işleyiş değiştirilir, ders eklenir ya da çıkarılır, eksik alanlara öğretim elemanı alınır. Bu, çıktıların değerlendirilip girdilerin ya da fonksiyonların değiştirilmesidir.
- Bütünleşik sistem: Bir işletmede müşteri destek sistemi müşteri bilgilerini ve siparişleri tutar. Sipariş verildiğinde ürünün stokta olup olmadığı envanter yönetim sisteminden, üretilmesi gerekiyorsa üretim sisteminden öğrenilir. Bu üç alt sistem birbirine bağlı çalışmazsa bilgi elle taşınır ve sistem tam otomatikleşmemiş olur.
- Bilgi sistemi tiplerinin ilişkisi: Muhasebe bilgi sistemi bir yönetim bilgi sistemidir; onun altında bordro gibi tek işi yapan işlem işleme sistemleri bulunur. EIS doğrudan üst yönetime bilgi verir. DSS çok geniş bir kategoridir: senaryolar kurup her senaryoda en uygun hareketi seçmek için kullanılan her araç (basit bir hesap tablosu, uzman sistem, bilgi tabanlı sistem) karar destek amaçlı çalışabilir. Bilgi sistemi tipleri sonraki derste ayrıntılı işlenecektir.
- Sistem analistinin becerileri: Teknik tarafta, küçük bir firmaya anahtar teslim sistem kurarken hangi ağ altyapısının, hangi veritabanı yönetim sisteminin ve işletim sisteminin seçileceğine karar verebilecek kadar bilgi gerekir. İşletme tarafında kurumun yapısı, kademeleri, aktörleri ve aktiviteleri, başarı ölçütü, stratejisi ve kültürü bilinmelidir. İnsan tarafında analist ekip üyeleri, müşteri ve tedarikçilerle yazılı ve sözlü iletişim kurar; görüşme, dinleme ve gözlem, analiz aşamasında bilgi toplamanın temel yöntemleridir.

<!-- BELİRSİZ: Slayt 3 ("Thinking in terms of Systems"), 4 ("Characteristics of systems"), 8 (bütünleşik sistem şekli), 9 ("Types of information systems": TPS, MIS), 11 ve 12 (analistin teknik ve işletme becerileri) karelerde yalnız küçük önizleme olarak görünüyor; bu kısımlar altyazıdan yazıldı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
