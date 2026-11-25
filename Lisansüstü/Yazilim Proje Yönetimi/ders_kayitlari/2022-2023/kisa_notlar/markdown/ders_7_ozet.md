# Ders 7 Çalışma Özeti

## Genel Konular

- Proje planlamanın on beş aktivitesi (ekrandan, 00:10:00)
  - Ders, "Information Systems Project Management" kitabının planlama bölümünü izler. Kitaba göre proje planlama şu aktivitelerden oluşur: riskleri tanımlama ve azaltma eylemlerini belirleme, kabul ve kısıtları listeleme, kalitenin nasıl yönetileceğini belirleme, aktivite ve maliyet bileşenleri listesini oluşturma, aktiviteler arası bağımlılıkları kurma, efor ve maliyeti tahmin etme, iş takvimi ve kilometre taşlarını hazırlama, kaynakları atama ve seviyelendirme, bütçe ve takvimi müşteri gereksinimlerine uydurma, proje bütçesini hazırlama, proje belgelerini yönetme, devreye alma (implementation) planı, tamamlanma planı, iletişim planı ve proje planını yazma.
  - Adımlar sıralı görünse de iç içe geçer: aktiviteler belirlenirken bağımlılıklar, iş listesi ve kilometre taşları birlikte oluşur.
  - Aktiviteler, bir önceki aşamada (projeyi tanımlama) seçilen süreç modeline göre listelenir.
- Aktivite bağımlılıkları, gecikme ve öncelenme süreleri (ekrandan, 00:05:00)
  - Bağımlılık türleri: Finish-Start (en yaygın), Start-Start, Finish-Finish.
  - Finish-Finish örneği: belgeleme, kodlama dahil yazılım geliştirme bitmeden "bitti" sayılamaz.
  - Start-Start örneği: modelleme, bilgi toplama en azından başlamadan başlayamaz; bilgi toplama başlar başlamaz use case ya da sınıf diyagramı çizilemez, birkaç gün gecikme (lag time) gerekir.
  - Lag time, öncül ile ardıl arasındaki bekleme süresidir; lead time ise bağımlılıklar arasındaki örtüşmedir.
- İş kırılım yapısı (WBS) ve numaralandırma (ekrandan, 00:25:00)
  - WBS ağaç yapısıyla ya da seviyeli numaralandırmayla gösterilebilir; örneğin 10.20.15 üçüncü seviyede bir öğedir.
  - Numaraları 5'er artırarak boşluk bırakmak, sonradan araya aktivite eklemeyi kolaylaştırır. WBS, kararlı hale gelmeden (üst yönetim ve kıdemli teknik ekip gözden geçirmeden) numaralandırılmamalıdır.
  - WBS tanımlandıktan sonra Gantt diyagramına aktarılır; herhangi bir proje yönetimi aracı (örneğin MS Project) kullanılabilir.
- Kilometre taşları ve kalite planı
  - Kilometre taşları süreç modeline göre konur; şelale modelinde her ana adımın (gereksinim analizi, ön tasarım, ayrıntılı tasarım) sonuna bir kilometre taşı konur.
  - Gözden geçirmeler (review) kilometre taşlarında yapılır. Dışarıdan desteklenen projelerde ise destekleyici kurum zamana bağlı (örneğin altı ayda bir) denetim niteliğinde gözden geçirme yapar.
  - Kalite planında: süreç modelinin seçimi, gözden geçirme türleri (genel gözden geçirme, walkthrough, inspection, peer review), gözden geçirme kuralları ve takvimi, gözden geçirme ekibi ve üyelerin rolleri, test kuralları, sürüm (versiyon) yönetimi ve kalitenin nasıl ölçüleceği yer alır.
  - Kitap, müşterinin hata oranı ölçümü yoksa kalitenin kıyaslanamayacağını belirtir (ekrandan, 00:20:00).
- Aktivite tanımı (ekrandan, 00:30:00)
  - Her aktivite için: aktivitenin adı ve WBS numarası, tanımı, girdileri, yapılacak işler (efor), kaynaklar ve çalışma yüzdeleri, çıktıları belgelenir.
  - Örnek: "5.5.20.5 Evaluate Written Proposals" aktivitesi; girdiler: gereksinim tanımı, teklif çağrısı (RFP, Request for Proposal), satıcı teklifleri; kaynaklar: proje yöneticisi %20, donanım analisti %80.
- Efor ve süre tahmini
  - Yazılım projelerinde maliyet büyük ölçüde iş gücüdür; donanım ucuzladıkça iş gücü tahmini maliyet tahminiyle neredeyse eşdeğer hale gelir.
  - Tahmin, önceki projelere dayalı uzman görüşüyle ya da istatistiksel yöntemlerle yapılır. Tahmin işi yapacak ya da yapmaya yetkin kişiye yaptırılmalı ve bilgili kişilerce gözden geçirilmelidir (ekrandan, 00:35:00).
  - Müşterinin kesin bir bitiş tarihi varsa önce bitiş tarihi konur, geri kalan aktiviteler buna göre sıkıştırılır.
  - Tahmindeki tehlikeli alanlar: bütünleştirme şaşkınlığı (her işe bolca süre verip toplamın çok uzun çıkması), yeni teknoloji, yeni metodoloji ve dış bağımlılıklar (alt yükleniciler).
  - Üst yönetim tahminleri çok yüksek bulup reddedebilir; proje yöneticisi sorumluluğu çok, yetkisi sınırlı bir yöneticidir (ekrandan, 00:40:00).
- Takvim, kritik yol ve modülerlik
  - PERT (Program Evaluation and Review Technique) ve kritik yol analiziyle aktivitelerin sırası ve boşluklar belirlenir.
  - Bağımlılığı az, modüler yazılım planlamada esneklik sağlar; tasarım kalıpları ve yeniden kullanılabilir kütüphaneler süreyi kısaltır.
  - Gantt diyagramı seviyeli aktiviteleri, süreleri ve atanan kaynakları gösterir (ekrandan, 00:45:00).
- Kaynak atama ve seviyelendirme
  - Önce rol düzeyinde atama yapılır (örneğin %70 proje yöneticisi, %20 yazılım uzmanı ve sistem analisti, %10 donanım uzmanı), sonra belirli kişiler atanır.
  - Kişinin diğer projelerdeki yükü dikkate alınır (başka projede %70 çalışıyorsa bu projeye en fazla %30 ayırabilir).
  - Kaynak gereksinimleri düzleştirilir: kişi bazlı iş listelerine bakılarak aşırı yüklenenlerden az yüklenenlere iş kaydırılır ya da yeni kişi atanır.
- Bütçeyi ve takvimi müşteri gereksinimine uydurma (ekrandan, 00:50:00)
  - Tarihin kesin mi yoksa yalnız istenen mi olduğu belirlenir. Kesinse sistem sürümlere bölünebilir (release development) ya da işlevsellik azaltılabilir.
- Proje bütçesi ve nakit akışı (ekrandan, 00:55:00; 01:00:00)
  - Bütçe dört kalemden oluşur: personel ücretleri, harcamalar, sermaye maliyetleri ve ofis genel giderleri.
  - WBS'teki her aktivite için atanan kişilerin adam-ay ücretleri hesaplanır, genel harcamalar eklenir ve nakit akışı analizi yapılır; ardından getirilerle karşılaştırılır. Projeyi anlama aşamasındaki kaba fizibilite burada ayrıntılandırılır.
- Proje belgeleri, devreye alma ve eğitim (ekrandan, 01:05:00)
  - Proje belgeleri: proje planı ve sürümleri, toplantı gündemleri, durum raporları.
  - Eğitim iki yönlüdür: proje ekibinin eğitimi ve kullanıcıların eğitimi; kullanıcı kitlesi ve bilgi düzeyine göre farklı gruplara farklı eğitim planlanır.
- Tamamlanma kriterleri (ekrandan, 01:10:00)
  - Her proje türü için (uygulama geliştirme, sistem bütünleştirme, analiz/strateji projesi) tamamlanma kriterleri plana yazılır ve bir tamamlanma kriteri formunda başta ve sonda müşteri ile proje yöneticisi tarafından imzalanır.
  - Kabul testi, gereksinimlerle ve proje planıyla doğrudan ilişkilidir.
- İletişim planı (ekrandan, 01:15:00)
  - Paydaşlar: müşteri proje yönetimi, müşteri ekibi, proje ekibi, kullanıcılar, müşteri yönetimi, kendi yönetimimiz, alıcı gruplar ve dış paydaşlar.
  - Ekip içi, ekip-müşteri ve proje yöneticisi-üst yönetim iletişimi planlanır; sorunun bir üst kademeye aktarılması eskalasyon olarak adlandırılır.
- Proje planı içeriği (ekrandan, 01:20:00; 01:25:00; 01:30:00)
  - Giriş, proje tüzüğü (hedef, kapsam, teslim edilecekler, iş ihtiyacı/fırsatı, finansal faydalar), tamamlanma kriterleri, kabul ve kısıtlar, iş planı (WBS, kilometre taşları, tahmin, bütçe, nakit akışı), kapsam değişikliği, iş takvimi yönetimi, maliyet yönetimi, risk yönetimi, iletişim yönetimi, kalite yönetimi planları, proje organizasyonu ve rolleri, faturalama, ekler (ayrıntılı takvim, risk kontrol listeleri, WBS).
  - Yazılım proje planları için, belgede nelerin bulunacağını tanımlayan içerik standartları da vardır. <!-- BELİRSİZ: standardın adı altyazıda bozuk ("artırık planı", "ayrıplı standartları"); büyük olasılıkla IEEE yazılım proje yönetim planı standardı kastediliyor. -->
- Risk yönetimi (ekrandan, 01:35:00; 01:40:00; 01:45:00)
  - Riskin üç anahtar özelliği: olasılık, kayıp ve gelecek.
  - Reaktif (gerçekleşince çözme) ve proaktif (gerçekleşmeden önleme) yaklaşımlar; derste proaktif yaklaşım işlenir.
  - Risk türleri: proje riskleri (bütçe, zaman, personel), teknik riskler (altyapı, uygun olmayan yöntem, son teknoloji, hatalar, eksik belgeleme), işletme riskleri (pazar, satış, büyüklük, şirketin geleceğinin projeye bağlı olması).
  - Risk tablosu: risk adı, türü, olasılığı ve etkisi; etkisi küçük ve olasılığı düşük riskler elenir, diğerleri izlenir.
  - Her izlenen risk için risk bilgi sayfası: açıklama, işaretler, önlemler ve önlemlerin maliyeti; risk her kilometre taşında yeniden değerlendirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Planlama adımları iç içe geçer
  - Aktiviteler, bağımlılıklar, iş listesi ve kilometre taşları birbirini tamamlayarak oluşur; sıralı bir liste gibi düşünülmemelidir.
- Bağımlılıkları modele ve işin yapısına göre doğru kurmak
  - Yanlış kurulan bağımlılık takvimi bozar; bağımlılığı az modüler yapılar plana esneklik kazandırır.
- Kalite planında gözden geçirme kuralları
  - Kalite yönetimindeki en önemli şey gözden geçirmenin nasıl, ne zaman ve kimlerle yapılacağının tanımlanmasıdır.
- Yazılım projesinde maliyet iş gücüdür
  - Efor tahmini doğru yapılmazsa bütçe de yanlış olur; iş gücü sürekli maliyete çevrilerek bütçeyle karşılaştırılmalıdır.
- Tamamlanma kriterleri tablosu önemlidir
  - Her aşamanın bittiğini gösteren kriterler plana yazılmalıdır.
- Üst yönetim desteği
  - Hocanın davet ettiği sektör konuşmacılarının ortak görüşü: proje başarısında en büyük etken üst yönetim desteğidir (ekip, para ve müşteriyle iletişim sağlaması). Bu yüzden iletişim yönetimi ve eskalasyon planlanmalıdır.
- Risklerin önlemleri bedava değildir
  - Her önlemin maliyeti risk tablosuna yazılmalı; etkisi büyük ve olasılığı yüksek riskler daha sık aralıklarla izlenmelidir.

## Kısa Tekrar Notları

- Bağımlılık türleri: Finish-Start, Start-Start, Finish-Finish; lag = gecikme, lead = örtüşme.
- WBS: ağaç ya da seviyeli numara (10.20.15 → 3. seviye); numaralarda boşluk bırak, kararlı olmadan numaralandırma.
- Aktivite tanımı: tanım, girdiler, efor, kaynaklar (yüzdeleriyle), çıktılar.
- Tahmin tehlikeleri: bütünleştirme şaşkınlığı, yeni teknoloji, yeni metodoloji, dış bağımlılık.
- Kaynak atama: önce rol ve yüzde, sonra kişi; sonra seviyelendirme/düzleştirme.
- Kesin tarih varsa: sürümlere böl ya da işlevselliği azalt.
- Bütçe kalemleri: personel, harcamalar, sermaye maliyeti, ofis genel gideri; nakit akışı analizi.
- Eğitim: ekip eğitimi ve kullanıcı eğitimi.
- Tamamlanma kriteri formu: başta ve sonda müşteri ile proje yöneticisi imzalar.
- Paydaş kategorileri: müşteri proje yönetimi, müşteri ekibi, proje ekibi, kullanıcılar, müşteri yönetimi, kendi yönetimimiz, alıcı gruplar, dış paydaşlar.
- Risk = olasılık + kayıp + gelecek; proje, teknik, işletme riskleri; risk tablosu ve risk bilgi sayfası.

## Detaylı Açıklamalar

Planlama aşaması, projeyi anlama ve tanımlama aşamalarından sonra gelir. Tanımlama aşamasında seçilen süreç modeli, planlamada hangi aktivitelerin listeleneceğini belirler. Her aktivite için ne kadar süreceği ve kaç çalışan gerektiği tahmin edilir; aktiviteler arasındaki bağımlılıklar ve paralel yürüyebilecek işler saptanır. Bağımlılıkların çoğu Finish-Start türündedir: bir iş bitmeden diğeri başlamaz. Start-Start bağımlılıkta ikinci işin başlaması için birincinin başlamış olması gerekir; örneğin modelleme, bilgi toplama başladıktan birkaç gün sonra başlayabilir, bu bekleme lag time olarak verilir. Finish-Finish bağımlılıkta ise bir işin bitmesi diğerinin bitmesine bağlıdır; belgeleme ancak kodlama dahil geliştirme bittiğinde biter. Kitap, ekipman kurulumunun satın alma siparişine Finish-Start gecikmeli bağlı olmasını örnek verir: satıcı siparişi alıp işleyip teslim edene kadar kurulum başlayamaz (ekrandan, 00:05:00).

İş kırılım yapısı (WBS), işlerin hangi işlerin alt adımı olduğunu seviyeli olarak gösterir. Örnek WBS'te donanım seçimi ve satın alma birinci seviye, donanım seçimi ikinci seviye, onun alt adımları üçüncü seviye, değerlendirme adımlarının alt işleri dördüncü seviyedir. WBS numaraları zaman raporlamada ve maliyet takibinde kullanıldığı için, proje başladıktan sonra yeniden numaralandırmak zordur; bu yüzden numaralar boşluklu verilir ve WBS kararlı hale gelince numaralandırılır (ekrandan, 00:25:00). Her aktivite ayrıca bir aktivite tanım sayfasıyla belgelenir. Bilişim projelerinde sık görülen bir aktivite, teklif çağrısı (RFP) hazırlanıp satıcılara gönderilmesi ve gelen tekliflerin gereksinimleri karşılayıp karşılamadığının değerlendirilmesidir. Kitaptaki örnekte bu değerlendirmeyi %20 proje yöneticisi, %80 donanım analisti yürütür; proje yöneticisi işin yönetimini, analist asıl teknik değerlendirmeyi yapar (ekrandan, 00:30:00).

Kalite planı, hataların nerelerde bulunabileceğini ve nasıl yakalanacağını tanımlar. Kalite için önce uygun bir süreç modeli seçilir, sonra gözden geçirmeler planlanır. Gözden geçirme biçimleri formalite derecesine göre değişir: kaba bir gözden geçirmeden, daha ayrıntılı walkthrough'a ve en ayrıntılı inspection'a kadar. Plan; hangi aşamada hangi gözden geçirmenin yapılacağını, ekibin kimlerden oluşacağını, her üyenin hedefini, test kurallarını, sürüm yönetimini (her sürümde nelerin dağıtılacağı ve sürümler arasındaki farklar) ve kalitenin nasıl ölçüleceğini içerir.

Tahminde en büyük tuzak bütünleştirme şaşkınlığıdır: her alt işe "gerektiği kadar" süre verilip toplandığında proje süresi ve maliyeti kabul edilemez çıkar, plan geri dönüp sıkıştırılır. Yeni teknoloji, ekibin tanımadığı geliştirme ortamı, yeni metodoloji ve sözleşmesi iyi yapılmamış alt yükleniciler de tahminleri kaydırır. Üst yönetim tahminleri yüksek bulursa planı reddedebilir; kitap, tahminlerin geçerli olduğuna inanılıyorsa savunulmasını, aksi halde ya planın değiştirilmesini ya da azaltılmış eforun "dayatılmış tahmin" notuyla kabul edilmesini önerir (ekrandan, 00:40:00).

Kaynak atamada önce rollere yüzde verilir, sonra belirli kişiler atanır ve kişilerin diğer projelerdeki yükleri dikkate alınır. Tüm atamalar bittikten sonra kişi bazında iş listeleri incelenir; aşırı yüklenenlerden az yüklenenlere görev kaydırılır ya da yeni kişi eklenir. Plan yürütülürken de plana uyulup uyulmadığı izlenir; geride kalınırsa işlev azaltma, yeni sürüm planlama ya da ek çalışan gerekebilir.

Bütçe, kitapta dört tür maliyet kaleminden oluşur: personel ücretleri, harcamalar, sermaye maliyetleri ve ofis genel giderleri. Örnek bütçe tablosunda her aktivitenin sabit maliyeti, toplam maliyeti, temel çizgi (baseline) ve sapma (variance) sütunları vardır; örneğin "Purchase and expedite delivery" aktivitesinde 225.000 dolar sabit maliyet ve 225.920 dolar toplam maliyet görünür (ekrandan, 00:55:00). Bütçe, nakit akışı analizine ve beklenen getirilerle karşılaştırmaya temel olur.

Tamamlanma kriteri formu, uygulama projesi için kullanıcı tanımlı kabul testlerinin başarıyla tamamlanması, kullanıcıların eğitilmesi, uygulamanın bakım ekibince kabulü, yardım masası ve üretim prosedürlerinin kurulması, uygulamanın üretimce kabulü ve garanti süresinin tamamlanması gibi maddeler içerir; proje başında ve sonunda müşteri ve proje yöneticisi tarafından imzalanır (ekrandan, 01:10:00).

Risk yönetiminde Pressman'ın Software Engineering kitabındaki tanım izlenir: risk gelecekte ortaya çıkabilecek, belli bir olasılığı olan ve gerçekleşince kayıp doğuran bir durumdur. Risk olasılığı ve etkisi tahmin edilerek bir risk tablosu oluşturulur; ekipten de olası riskler için görüş alınır. Etkisi küçük ve olasılığı düşük riskler sürekli izlenmez. İzlenecek riskler için risk bilgi sayfası hazırlanır. Derste gösterilen örnekte (Risk #09: Pazarlama; olasılık yüksek, etki büyük, tür ticari) firmanın yalnız yazılımcılardan oluşan çekirdek kadrosu ve ürünün piyasada çok alternatifi olması açıklanır; işaretler müşteri adaylarının ilgisizliği ve bakımın ilk altı ayında ürünün amorti etme oranının %50'nin altında kalmasıdır; önlemler bir programcıya MBA yaptırmak, konu uzmanlığı odaklı danışmanlık almak ve bir iki firmayla indirimli pilot uygulama yapmaktır (ekrandan, 01:45:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
