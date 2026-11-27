# Ders 4 Çalışma Özeti

## Genel Konular

- Zaman fizibilitesi (ekrandan, 00:05:00)
  - Belirlenen zaman içinde projenin nasıl tamamlanacağının belirlendiği fizibilite türüdür: "Bu projeyi yapabilmek için nasıl bir zaman ve iş planına ihtiyaç duyarım?"
  - Birbirinin tümleyeni sayılan iki teknik kullanılır: Gantt ve PERT. Biri diğerinden türetilebilir.
- Gantt çizelgesi (ekrandan, 00:10:00 ve 00:15:00)
  - 1910'larda proje planlama ve kontrolü için Henry Gantt tarafından önerilmiştir; adı önerenin soyadından gelir.
  - Projenin işlem adımları faaliyet olarak adlandırılır. Her faaliyetin süresi, başlangıç-bitiş zamanları ve kullanılacak kaynaklar diyagramdan okunabilir.
  - Faaliyetler hiyerarşiktir: iş paketi (birbiriyle ilgili işlerin bir paketi), faaliyet, alt faaliyet. Bu ağaç kırılımıyla projede yapılacaklar belirlenir.
  - Problem tanımından işletime kadar tüm aktivitelerin zamanları ve ilişkileri gösterilir; durak noktaları belirlenebilir.
  - Microsoft Project gibi araçlarla proje verisi işlem ağı olarak verildiğinde şunlar otomatik elde edilir: işleri tarih sırasıyla ve durak yerleriyle gösteren Gantt çizelgesi, her işin en erken ve en geç başlama-bitme tarihlerini gösteren görev durumu çizelgesi, görev paylaşımı çizelgesi, kritik yolu belirleyen işlem ağı.
- Örnek Gantt şeması: kitap satış web sitesi (ekrandan, 00:20:00)
  - Waterfall akışında Analiz (6 gün), Tasarım (7 gün), Geliştirme ve Test (14 gün) özet faaliyetleri; projenin tamamı 24.03.21 - 29.04.21, 27 gün.
  - Kaynaklar: Analist-1, Analist-2, Yazılımcı-1, Yazılımcı-2, Test Uzmanı. Öncül sütununda `2SS+1 day`, `11FF;10SS` gibi ilişki tanımları vardır.
- Gantt tablosunun sütunları
  - ID, WBS (Work Breakdown Structure, iş kırılım yapısı: hiyerarşik numaralandırma 0, 1, 1.1 ...), Task Mode (otomatik/göreli ya da elle sabitlenmiş tarih), Task Name, Duration, Start, Finish, Predecessors, Resource Names.
  - Başlangıç tarihi ve süre verilince bitiş tarihi otomatik hesaplanır; hesap çalışma takvimine (iş saatleri, hafta sonu, tatiller, kişi izinleri) göre yapılır.
- Öncül tanımlama ve dört ilişki türü
  - Finish to Start (bitiş-başlangıç): ilk faaliyet bitmeden ikincisi başlayamaz (analiz bitmeden tasarım başlamaz). En sık kullanılan ilişkidir.
  - Start to Start (başlangıç-başlangıç): iki faaliyet birlikte başlar; paralelleştirmeyi sağlar.
  - Finish to Finish (bitiş-bitiş): bir faaliyetin bitmesi için diğerinin bitmiş olması gerekir (kodlama bitmeden birim testler bitemez).
  - Start to Finish (başlangıç-bitiş): bir faaliyetin bitmesi için diğerinin başlamış olması gerekir.
- Kritik yol (ekrandan, 00:35:00)
  - Projenin zamanında bitmesi için üzerindeki tüm faaliyetlerin zamanında gerçekleşmesi gereken faaliyet zinciridir. Kritik yoldaki bir faaliyet X gün gecikirse proje de en az X gün gecikir.
  - Kritik yoldaki faaliyetlere kritik faaliyet denir; Gantt çizelgesinde kırmızı gösterilir.
- Kilometre taşı (milestone, durak noktası)
  - Süresi 0 gün olarak girilen, önemli olayları (faz sonu toplantısı, proje teslimi) işaretleyen noktalardır; içi dolu eşkenar dörtgenle gösterilir.
  - Toplantının kendisi efor gerektiriyorsa milestone'un yanına ayrıca birkaç saatlik bir toplantı faaliyeti eklenir.
- Bolluk (slack) (ekrandan, 00:40:00)
  - Kritik yolda olmayan esnek faaliyetlerin proje süresini etkilemeden kayabileceği en büyük miktardır.
  - Kritik olmayan faaliyetler mavi, bolluk miktarı gri uzun çizgiyle gösterilir.
- Kaynak atamaları (ekrandan, 00:45:00)
  - Kaynak, proje faaliyetlerinin ilerlemesi için gereken her şeydir: insan (iş gücü), ekipman, makine, malzeme, hizmet, para.
  - Kaynakların doğru ve etkin kullanımı proje yönetiminin başarısıyla doğru orantılıdır. Özellikle sınırlı kaynakların öncelikli ve doğru kullanılması önemlidir.
  - Kaynak tablosunda ad, tür (iş gücü / malzeme), en büyük kullanım yüzdesi ve birim ücret tanımlanır.
- Daha büyük bir Gantt örneği (ekrandan, 00:50:00)
  - 167 günlük bir projede İş Paketi 1: Problem Analizi, İş Paketi 2: Kavramsal Tasarım, İş Paketi 3: Kodlama ve Bütünleme gibi iç içe özet faaliyetler.
- MS Project uygulaması (ekrandan, 00:55:00 ve 01:00:00)
  - Görev ekleme, otomatik zamanlama, süre ve öncül verme, kaynak atama; Team Planner görünümünde aşırı yüklenen kaynak kırmızı görünür; Task Usage görünümünde işlerin saatleri günlere dağıtılmış olarak izlenir.
- PERT (ekrandan, 01:15:00)
  - Program Evaluation and Review Technique; proje yönetimi ve analizi için istatistiksel bir araçtır. Zaman, araç, maliyet ve kontrol gereklerini cevaplar.
  - Graf temellidir: faaliyetler düğümlerle, aralarındaki bağlantılar kenarlarla gösterilir. Bir olaya ancak önceki işlemler bitince ulaşılır.
  - Gantt paralelliği iyi gösterir ama dolaylı bağımlılıkları (hangi faaliyetin hangilerine dolaylı bağlı olduğu) göstermekte yetersizdir; PERT bunu ağ yapısıyla daha iyi izletir.
  - MS Project PERT'i "Network Diagram" adıyla aynı veriden çizer.
- Süre tahmini (effort estimation) (ekrandan, 01:25:00)
  - Proje başlamadan faaliyet sürelerini kestirmek zordur ve yazılım mühendisliğinde hâlâ araştırılan bir alandır.
  - Yöntemler: kafadan atmak (bilimsel değil), uzmana danışmak, Delphi gibi yöntemler, ağırlıklı ortalama, COCOMO / COCOMO II (kod satırı sayısına dayalı katsayısal modeller), function point türevi yöntemler, önceki projelerden öğrenen makine öğrenmesi tabanlı modeller.
  - PERT süre formülü: $S_b = \dfrac{S_i + 4 S_e + S_k}{6}$ ($S_i$ iyimser, $S_e$ en yaklaşık, $S_k$ kötümser süre).
- Farklı çözüm önerilerinin değerlendirilmesi ve fizibilite matrisi (ekrandan, 01:35:00 ve 01:40:00)
  - Her çözüm önerisi için fizibilite çalışması yapılır; aday sistemler matrisi ile alternatifler karşılaştırılır.
  - Fizibilite matrisinde satırlar fizibilite türleri ve yüzde ağırlıkları (Teknik %V, Ekonomik %W, Zaman %X, Sosyal %Y, Yönetim %Z), sütunlar önerilen sistemlerdir. Puanlar ağırlıklarla çarpılıp toplanır, en yüksek puanlı öneri seçilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Zaman maliyettir
  - Bir haftalık çalışma, çalışanların bir haftalık ücreti demektir; bu yüzden zaman fizibilitesi ekonomik fizibiliteye bağlanır. Efor genellikle adam-ay (man-month) ile ölçülür; hoca "The Mythical Man-Month" kitabını önerdi.
- Kaynak yüklemesi ve verimlilik
  - Paralel projelerde bir kişinin eforu bölüştürülür (haftada 2-1-2 gün paylaşımda A projesine %40). Kapasitenin üstüne atama aşırı yüklemedir; araçlar bunu kırmızıyla uyarır.
  - Bir ay boyunca yalnız bir hafta iş verilen çalışan %25 verimle kullanılmış olur; iş planı boşlukları başka projelerle doldurulmalıdır.
  - Gerçekçi atamada insanlar %100 yerine yaklaşık %80 ile tanımlanmalıdır; kesintiler (telefon, e-posta, müşteri, yardımlaşma) yüzünden kimse %100 eforla çalışamaz.
- Kritik yol ve bolluk birlikte düşünülmeli
  - Kritik yoldaki bir kaynak bir hafta işe gelemezse proje de bir hafta kayar; ya takviye kaynak eklenir ya da gecikme kabul edilir.
  - Bir faaliyeti sona bağlamamak ona esneklik (bolluk) kazandırır.
- Kaynak eklemek süreyi her zaman kısaltmaz
  - "Bir anne bebeği 9 ayda doğurur; 9 anne ile 1 ayda doğmaz." Bazı işler bölünemez; karar işin doğasına göre verilmelidir.
- Süre tahmini bir niyet beyanıdır
  - Plan "bu ekip ve kaynaklarla bu sürede yapılabilir" demektir; proje ilerledikçe güncellenmeli ve tamamlanma yüzdeleriyle izlenmelidir. "Yaz oraya 3 gün" diye geçiştirilecek bir konu değildir.
- MS Project'i kurup deneyin
  - Sürümü önemsizdir; yeni ve eski sürümlerde mantık aynıdır. Örnek bir proje üzerinde ilişkileri, kaynak atamalarını ve görünümleri kurcalayarak öğrenmek önerildi.

## Kısa Tekrar Notları

- Zaman fizibilitesi = zaman ve iş planı açısından yapılabilirlik; teknikleri Gantt ve PERT.
- Gantt: faaliyetler, süreler, başlangıç-bitiş, kaynaklar, ilişkiler; Henry Gantt, 1910'lar.
- WBS: faaliyetleri ağaç yapısında numaralandırır (kitaptaki bölüm-alt bölüm gibi).
- İlişkiler: FS (en sık), SS, FF, SF.
- Kritik yol: gecikmesi projeyi geciktiren faaliyet zinciri; kırmızı.
- Bolluk (slack): kritik olmayan faaliyetin proje süresini etkilemeden kayabileceği en büyük süre; mavi faaliyet, gri çizgi.
- Kilometre taşı: 0 günlük faaliyet, eşkenar dörtgen.
- Kaynak: insan, ekipman, malzeme, para; gerçekçi insan ataması yaklaşık %80.
- PERT: graf temelli; düğümler faaliyet, kenarlar bağımlılık; MS Project'te Network Diagram.
- Süre tahmini: $S_b = (S_i + 4S_e + S_k)/6$.
- Fizibilite matrisi: ağırlıklı puanlama ile çözüm önerileri sıralanır.

## Detaylı Açıklamalar

- Kitap satış web sitesi örneğinde (ekrandan, 00:20:00) Analiz özet faaliyeti 6 gün sürer: Fizibilite Çalışması (Analist-1, 24.03 - 29.03, 4 gün) ile Gereksinimlerin Belirlenmesi (Analist-2, 25.03 - 31.03, 5 gün) arasında `2SS+1 day` ilişkisi vardır, yani ikincisi birincinin başlangıcından bir gün sonra başlar. İki iş kısmen paralel olduğu için 4 + 5 = 9 değil, 6 iş günü tutar. Analiz Bitimi Toplantısı (31.03) 0 günlük bir kilometre taşıdır.
- Tasarım özet faaliyeti 7 gündür: Ön Tasarım (Yazılımcı-1, 1.04 - 5.04, 3 gün) bitmeden Ayrıntılı Tasarım (Yazılımcı-2, 6.04 - 9.04, 4 gün) başlayamaz (FS). Bu bağımlılık yüzünden ayrıntılı tasarım fareyle öne çekilemez. Tasarım Bitimi Toplantısı 9.04'tedir.
- Geliştirme ve Test 14 gündür: Ön Yüz Geliştirme (8 gün) ve Arka Plan Geliştirme (10 gün) tasarım toplantısına (8 numaralı satır) bağlıdır. Birim Test (10 gün) için `11FF;10SS` tanımlıdır: ön yüzle aynı anda başlar, arka planla birlikte biter. Sistem Testi (2 gün) ve Kullanıcı Testleri (4 gün) birim testten sonra başlar; Proje Teslim Toplantısı 29.04'tedir.
- Kritik yol slaytında (ekrandan, 00:35:00) faaliyetlerin çoğu kırmızıdır, yalnız Sistem Testi mavidir: 2 gün sürer, paralel giden Kullanıcı Testleri 4 gündür ve teslim toplantısı yalnız kullanıcı testlerine bağlıdır. Bu yüzden sistem testinin 2 günlük bolluğu vardır.
- Task Mode sütunu tarihlerin göreli (öncüllere ve sürelere göre otomatik) mi yoksa elle sabitlenmiş mi olacağını belirler. Kesin bir teslim tarihi (sözleşme cezası olan bir son tarih) elle sabitlenirse göreli faaliyetler geriye doğru planlanır ve projeye en geç ne zaman başlanması gerektiği görülür.
- Süreler iş günü olarak verilir; gerçek takvimde tatil, hafta sonu ya da çalışanın izni araya girince 3 iş günü 7-8 takvim gününe yayılabilir. Bu tanımlar araçtaki çalışma takviminde yapılır.
- Kaynak tablosunda iş gücü (Labor) ve malzeme / hizmet (örneğin barındırma hizmeti) kaynakları, en büyük kullanım yüzdeleri ve saatlik ya da sabit ücretleri tanımlanır. Saatlik ücret, aylık maliyetin aylık çalışma saatine (örneğin 180 saat) bölünmesiyle bulunur. Böylece her faaliyetin proje bütçesindeki payı da görülür.
- MS Project uygulamasında (ekrandan, 00:55:00) araya "Arabirim Tasarımı" (2 gün) eklendi, öncülü Analiz Bitimi Toplantısı (4) yapıldı. Önce Yazılımcı-1 ve Yazılımcı-2'ye birlikte atanınca Team Planner'da Yazılımcı-1 kırmızıya döndü, çünkü aynı tarihlerde Ön Tasarım'a %100 atanmıştı. İş yalnız o tarihlerde boşta olan Yazılımcı-2'ye verilince aşırı yüklenme kalktı. Test uzmanının aynı anda sistem ve kullanıcı testlerine %100 atanması da aşırı yüklenmeydi. Task Usage görünümünde toplam iş 416 saattir (Analiz 72, Tasarım 72, Geliştirme ve Test 272 saat) (ekrandan, 01:00:00).
- Arabirim tasarımı daha sonra Tasarım Bitimi Toplantısı'na da bağlandı. Paralelindeki ön tasarım ve ayrıntılı tasarım toplam 3 + 4 = 7 gün, arabirim tasarımı 2 gün sürdüğü için bu faaliyetin 7 - 2 = 5 günlük bolluğu oldu (ekrandan, 01:20:00).
- PERT süre tahmininde ekipteki herkes iyimser (hiç aksama olmadan en kısa süre), kötümser (gecikme ve kesintileri hesaba katan en uzun süre) ve en yaklaşık (normal gecikmelerle) süre tahmini yapar; her birinin ortalaması alınır. Ortalama değere 4, iyimser ve kötümser değerlere 1 ağırlık verilip toplam 6'ya bölünür. Bulunan süreler Gantt ya da PERT diyagramına faaliyet süresi olarak girilir.
- Fizibilite matrisinde ağırlıklar projeye göre değişir: altyapının sağlamlığı önemliyse teknik, maliyet önemliyse ekonomik, süre baskısı varsa zaman, son kullanıcının kabulü önemliyse (örneğin bir mobil oyun) sosyal fizibilitenin ağırlığı yükseltilir. Her satırdaki 100 puan alternatiflere dağıtılır (örneğin teknikte yerel Linux sunucuya yüksek, veri yurt dışına çıkamadığı için bulut çözümüne düşük puan). Ağırlıklı toplamlar sıralanır, en yüksek puanlı öneri projenin çözümü olarak seçilir.
- Fizibilite tamamlandıktan sonra sıradaki aşama gereksinim analizidir: iş analizi, modelleme, kullanım senaryoları ve müşteriden bilgi toplama yöntemleri.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
