# Ders 1 Çalışma Özeti

## Genel Konular

- Yazılım proje yönetiminin üç halkası
  - Yazılım proje yönetimi üç alanın kesişimidir: proje yönetimi bilgi ve deneyimi, genel yönetim bilimi ve yazılım mühendisliği teknikleri (ekrandan, 00:40:00).
  - Proje yönetimi bilgi ve deneyimi zaman planı, kaynak planı ve kapsam yönetimi gibi konuları kapsar.
  - Genel yönetim bilimi, proje yöneticisinin ekibindeki kişilerle ilişkisi açısından gereklidir; işletme ve endüstri mühendisliğinin yönetim bilgisidir.
  - Yazılım mühendisliği teknikleri bu işlerin yazılım projesinde nasıl uygulanacağını belirler.
- Etkin proje yönetimi ve 3P (People, Problem, Process)
  - İnsan kaynakları (People): seçim, performans yönetimi, eğitim, kariyer geliştirme, organizasyon ve iş tasarımı, ekip kültürü geliştirme (ekrandan, 01:05:00).
  - Problem: proje planlanmadan önce amacı ve alanı belirlenmeli, alternatif çözümler düşünülmeli, teknik ve yönetim kısıtları tanımlanmalıdır.
  - Süreç (Process): yazılım geliştirme sürecinde gerçekleştirilen işlemler, esas işlemler ve bunları destekleyen işlemlerden oluşur.
  - Hoca 3P'ye sonradan dördüncü bir P eklendiğini, ama standart olarak 3P düşünülebileceğini söyledi.
- Yazılım geliştirme sürecinde esas ve destek işlemler
  - Esas (temel) işlemler: gereksinim analizi, tasarım, gerçekleştirme (kodlama ve veritabanı oluşturma) ve test.
  - Destek işlemler: proje yönetimi, kalite yönetimi, risk yönetimi, konfigürasyon yönetimi.
- Gereksinim türleri
  - İşlevsel gereksinimler (functional requirements): problem alanıyla ilgili, sistemin ne yapması gerektiğini tanımlar (örneğin bir hastane bilgi sisteminde neler olmalı).
  - İşlevsel olmayan gereksinimler (non-functional requirements): kalite özellikleri; eş zamanlılık, yedekleme ve kurtarma (backup/recovery), erişilebilirlik, çevrim içi erişim hızı, güvenlik, güvenilirlik gibi.
- Yapısal yaklaşımla gereksinim analizi modeli
  - Amaçlar: müşteri ihtiyaçlarını açıklamak, yazılım tasarımına temel hazırlamak, yazılım oluşturulduktan sonra ihtiyaçları karşılayıp karşılamadığını doğrulamak.
  - Model katmanları (ekrandan, 01:35:00): merkezde veri sözlüğü; çevresinde varlık ilişki diyagramı, veri akış diyagramı ve durum geçiş diyagramı; en dışta veri nesne tanımı, süreç spesifikasyonu ve kontrol spesifikasyonu.
  - Veri akış diyagramları genelden ayrıntıya iner: taslak (bağlam) diyagram, birinci seviye diyagram, tek bir işi ayrıntılayan alt seviye diyagram.
- Veri akış diyagramı örnekleri
  - Öğrenci bilgi sistemi: taslak diyagramda tek işlem; birinci seviyede ders seçimi, sınav sonuçlarının sisteme eklenmesi ve sınav sonucunun görüntülenmesi işlemleri ve iki veritabanı tablosu (ekrandan, 01:40:00).
  - Doktor muayenehanesi faturalama sistemi: doktor, hasta ve sigorta şirketi dış varlıklar; muayene kaydının incelenmesi, faturanın hazırlanması, hasta ödemeleri ve sigorta ödemeleri alt işlemleri; fatura hazırlama işleminin (2.0) üç alt işleme ayrıştırılması (ekrandan, 01:45:00).
- Yazılım süreç modelleri ve çevik yaklaşımlar
  - Şelale (waterfall) modeli sıralı akıştır; spiral model döngüseldir; prototip modelde analiz ve tasarım bir döngüdedir; RAD modelinde birkaç koldan paralel geliştirme yapılır.
  - Çevik yaklaşımlar artan müşteri taleplerini hızlı karşılamak ve geç ortaya çıkan gereksinim değişikliklerine uyum sağlamak için ortaya çıkmıştır (ekrandan, 01:50:00). Sektörde Scrum ve Kanban olarak görülür.
  - Çevik modellerde dinamik kalite değerlendirmesi, kalite işlemlerinin sürecin erken adımlarında başlaması, kullanıcı hikayeleri, birim testler ve müşteri geri beslemesi öne çıkar (ekrandan, 01:55:00).
  - Çevik projelerde de proje yönetimi vardır: üst yönetimle ekip arasında iletişimi sağlayan, projeden sorumlu bir proje yöneticisi ya da proje koordinatörü bulunur.
- Zamanlama ve proje planına giriş
  - Zamanlama: durak noktaları, tamamlanma süresi, işlerin bitiş süresine etkisi, hangi işin beklemeye tahammülü olmadığı, hangi alt işin ne zaman başlaması gerektiği. Şematik gösterim PERT ve Gantt çizelgeleriyle yapılır.
  - İş kırılım yapısı (WBS) örneği ve proje planı içeriği ekranda gösterildi (ekrandan, 02:00:00 ve 02:05:00); ayrıntısı sonraki derse bırakıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım proje yönetimi, üç halkanın (proje yönetimi, genel yönetim, yazılım mühendisliği teknikleri) birleşimidir; yalnız birini bilmek yetmez.
  - Proje yönetimi ve genel yönetim konuları genel proje yönetimi derslerinde verilir; bu derste fark yaratan, bunların yazılım mühendisliği teknikleriyle uygulanmasıdır.
- Problemi doğru koymak önemlidir.
  - Örneğin bir hastane bilgi sistemi için sıfırdan geliştirme mi, hazır bir ürünün uyarlanması mı daha uygun, maliyet, teknik güç ve yönetim kısıtları açısından değerlendirilmelidir (fizibilite).
- Test de bir esas işlemdir; destek işlemlerle karıştırılmamalıdır.
- Çevik yaklaşım proje yönetimini ortadan kaldırmaz.
  - Herkes birbirine karşı sorumludur, ama yine de projeden sorumlu bir yönetici (ya da koordinatör) tanımlanır; proje yönetimi evreleri çevik metodolojiye uyarlanarak uygulanır.

## Kısa Tekrar Notları

- Yazılım proje yönetimi = proje yönetimi bilgi ve deneyimi + genel yönetim bilimi + yazılım mühendisliği teknikleri.
- 3P: People (insan kaynakları), Problem, Process (süreç).
- Esas işlemler: analiz, tasarım, gerçekleştirme, test. Destek işlemler: proje, kalite, risk, konfigürasyon yönetimi.
- Gereksinimler: işlevsel (ne yapacak) ve işlevsel olmayan (kalite özellikleri).
- Yapısal analiz modeli: merkezde veri sözlüğü; ERD (veri), DFD (süreç), durum geçiş diyagramı (kontrol).
- DFD'ler genelden ayrıntıya: bağlam diyagramı, 1. seviye, alt seviye (örneğin 2.0 işleminin 2.1, 2.2, 2.3'e ayrılması).
- Nesneye yönelik yaklaşımda süreç akışı use case diyagramlarıyla da gösterilir.
- Süreç modelleri: şelale, spiral, prototip, RAD; çevik yaklaşımlar (Scrum, Kanban, XP, TDD).
- Zamanlama PERT ve Gantt çizelgeleriyle gösterilir; işler WBS ile alt adımlara ayrılır.

## Detaylı Açıklamalar

Yazılım proje yönetimi üç alanın kesişiminde durur. Birincisi proje yönetimi bilgi ve deneyimidir: zaman planı, kaynak planı ve kapsam yönetimi gibi projenin iyi yönetilmesi için gereken bilgiler. İkincisi genel yönetim bilimidir: proje yöneticisi ekibindeki insanlarla çalışır, bu yüzden işletme ve endüstri mühendisliğinde öğretilen yönetim bilgisine ihtiyaç duyar. Üçüncüsü yazılım mühendisliği teknikleridir: bu işler bir yazılım projesinde hangi tekniklerle yapılacak? Ekrandaki Venn şemasında bu üç alanın kesiştiği kırmızı bölge "yazılım proje yönetimi" olarak işaretlenmiştir (ekrandan, 00:40:00).

Etkin proje yönetimi İngilizcede 3P ile özetlenir. People, yani insan kaynakları: ekibe kimin seçileceği, performansın nasıl izleneceği, eğitim ve kariyer gelişimi, organizasyon içindeki iş tasarımı ve ekip kültürü. Problem: proje planlanmadan önce amaç ve alan belirlenir, alternatif çözümler düşünülür, her alternatifin teknik ve yönetim kısıtları tanımlanır. Hocanın örneğinde bir hastane bilgi sistemi geliştirilecekse önce nasıl bir hastane için olduğu, sıfırdan mı yazılacağı yoksa satılan bir ürünün mü uyarlanacağı, hazır ürünün maliyet ve teknik açıdan uygun olup olmadığı netleştirilir. Bu, sistem analizi ve tasarımı dersindeki fizibilite analizine karşılık gelir. Process, yani süreç: yazılım geliştirme sürecindeki işlemler esas işlemler (gereksinim analizi, tasarım, gerçekleştirme, test) ve destek işlemler (proje yönetimi, kalite yönetimi, risk yönetimi, konfigürasyon yönetimi) olarak ikiye ayrılır.

Gereksinim analizinde gerçek hayatta işin nasıl yürüdüğü ve müşterinin istekleri anlaşılır, bu istekler gereksinimlere dönüştürülür. Gereksinimler işlevsel ve işlevsel olmayan diye gruplanır. İşlevsel gereksinimler problem alanına özgüdür; işlevsel olmayan gereksinimler ise her yazılımdan beklenen ama yazılıma göre farklı düzeyde önem taşıyan kalite özellikleridir (eş zamanlılık, yedekleme ve kurtarma, erişilebilirlik, çevrim içi erişim hızı, güvenlik, güvenilirlik). Proje yöneticisi isteklerin geçerli, yani yazılıma aktarılabilir olup olmadığını netleştirmeli, kapsamı buna göre belirlemelidir.

Yapısal yaklaşımla gereksinim analizi modelinin merkezinde veri sözlüğü vardır; yazılımın kullandığı ve ürettiği tüm nesneleri tanımlar. Çevresinde üç diyagram bulunur: varlık ilişki diyagramı (veri nesne tanımı; varlıklar ve aralarındaki ilişkiler), veri akış diyagramı (süreç spesifikasyonu; verinin sistemde nasıl taşındığı ve bunu sağlayan fonksiyonlar) ve durum geçiş diyagramı (kontrol spesifikasyonu) (ekrandan, 01:35:00). Veri akış diyagramları genelden ayrıntıya iner. Öğrenci bilgi sistemi örneğinde taslak diyagramda öğrenci ve öğretim üyeleri dış varlıklar, öğrenci bilgi sistemi tek işlemdir. Birinci seviyede bu tek işlem "Ders Seç", "Sınav sonuçlarını sisteme ekle" ve "Sınav sonucu görüntüle" işlemlerine ayrılır; "Öğrenci-Ders veritabanı tablosu" ve "Öğrenci-Not veritabanı tablosu" veri depoları eklenir (ekrandan, 01:40:00). Faturalama örneğinde doktor, hasta ve sigorta şirketi dış varlıklardır; "2.0 fatura hazırlama" işlemi bir alt seviyede "2.1 Hastanın sigorta durumunun incelenmesi", "2.2 Listelenen miktarla faturayı kıyaslama" ve "2.3 Hastanın ödemesi gereken tutarı faturalama" işlemlerine ayrılır (ekrandan, 01:45:00). Aynı akış nesneye yönelik yaklaşımda use case diyagramlarıyla da gösterilebilir.

Şelale modeli süreci sıralı anlatmak için kullanılır, ama gerçek süreç her zaman böyle akmaz: spiral model döngüseldir, prototip modelde analiz ve tasarım bir döngü içinde ilerler, RAD modelinde birkaç koldan paralel geliştirme yapılır. 2000'lerin başından itibaren yaygınlaşan çevik yaklaşımlar, müşteri taleplerini daha hızlı karşılamak ve geliştirme sırasında değişen gereksinimlere uyum sağlamak için geleneksel modellere alternatif olarak çıkmıştır. Çevik modellerde dinamik kalite değerlendirmesi statik değerlendirmeden daha fazla uygulanır, kalite işlemleri sürecin erken adımlarında başlar ve daha kısa aralıklarla yapılır; kullanıcı hikayeleri, birim testler ve müşteri geri beslemesi doğruluk ve süreklilik sağlar (ekrandan, 01:55:00). Çevik projelerde de bir proje yöneticisi ya da koordinatörü vardır; proje yönetimi evreleri çevik metodolojiye uyarlanarak uygulanır.

Son olarak zamanlamaya giriş yapıldı: hangi tarihlerde ne yapılacağı, durak noktaları, tamamlanma süresi, işlerin bitişe etkisi ve hangi işin beklemeye tahammülü olmadığı. Bunlar PERT ve Gantt çizelgeleriyle gösterilir. Ekranda şelale modeline göre bir WBS örneği (1.0 Analiz, 2.0 Tasarım, 3.0 Gerçekleme, 4.0 Test ve alt adımları) ve proje planının içerik listesi gösterildi (ekrandan, 02:00:00 ve 02:05:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
