# Ders 6 Çalışma Özeti

## Genel Konular

- Proje yönetimi yol haritasının tekrarı
  - Proje yönetimi; projeyi anlama, projeyi tanımlama, projeyi planlama ve projeyi izleme/kontrol aşamalarından oluşur. Bu derste planlama aşamasına geçilir.
  - Ders, "Information Systems Project Management" kitabının planlama bölümünü izler (ekrandan, 00:05:00).
  - Projeyi anlama aşamasının soruları: projenin gerekçesi, arka planı (background), proje politikaları, oyuncular ve rolleri, müşterinin öncelikleri (ekrandan, 00:10:00).
  - Müşterinin önceliği, başarı göstergeleri olan bütçe, kapsam ve zamandan hangisinin müşteri için en önemli olduğudur.
  - Projeyi tanımlama aşamasının soruları: teslim edilecekler (deliverables), kapsam (hem sistem hem proje kapsamı), teslim edileceklerin nasıl gözden geçirileceği, müşteri organizasyonunun yapısı (ekrandan, 00:10:00).
- Teslim edilecekler ve kapsam
  - Teslim edilecekler yalnız kod değildir: SRS (yazılım gereksinim belirtimi) belgesi, tasarım belgesi, test örnekleri, proje planı, risk planı, veritabanı tanımları gibi belgeler de teslim edilecekler arasındadır.
  - Resmî ve ihaleli projelerde teslim edilecek belge sayısı artar; rutin iş projelerinde birkaç belgeyle sınırlı kalır.
  - Sistem alanının terminolojisi ve sınırları öğrenilmelidir (örnek: hastane bilgi sistemine nelerin girdiği).
  - Müşterinin teslime kadar isteyeceği değişikliklerin nasıl kayda alınacağı ve maliyetinin nasıl anlaşılacağı tanımlama aşamasında belirlenir.
- Yazılım geliştirme süreç modelinin seçimi
  - Planlamadan önce şelale, spiral, RAD, prototip, birleşik süreç (Unified Process) ya da Scrum ve XP gibi çevik modellerden hangisinin (ya da hibritinin) kullanılacağı belirlenir.
  - Seçim; ekibe, kurumun yapısına ve projenin yapısına göre yapılır. Zaten kullanılan bir sistemin yenilenmesinde müşteri isteklerini anlatmak kolay olduğu için şelale de uygun olabilir.
- Proje planlamanın on beş etkinliği (ekrandan, 00:25:00)
  - 1) Proje risklerini tanımlamak ve azaltma eylemlerini belirlemek, 2) kabulleri ve kısıtları listelemek, 3) kalitenin nasıl yönetileceğini belirlemek, 4) etkinlik ve maliyet bileşenleri listesini oluşturmak, 5) etkinlikler arası bağımlılıkları kurmak, 6) iş gücünü ve maliyetleri tahmin etmek, 7) zaman çizelgesini ve kilometre taşlarını hazırlamak, 8) kaynakları atamak ve seviyelemek, 9) bütçeyi ve çizelgeyi müşteri gereksinimleriyle uyumlamak, 10) proje bütçesini hazırlamak, 11) proje evrakını yönetmek, 12) uygulamaya geçişi planlamak, 13) tamamlamayı planlamak, 14) iletişimi planlamak, 15) proje planını yazmak.
- Kabuller (varsayımlar) ve kısıtlar
  - Kabul: Projeye "böyle olduğunu kabul ederek" başlanan olumlu varsayımdır. Proje kabulleri (örneğin hiçbir çalışan ayrılmayacak, proje bitene kadar rapor ya da izin alınmayacak) ve teknik kabuller (her çalışan seçilen dili ve veritabanı yönetim sistemini yeterli düzeyde biliyor, ayrıca eğitim ayrılmıyor) olabilir.
  - Kısıt: Planın dayandığı sınırdır (örneğin projede yalnız bir sistem analisti çalışabilecek).
  - Kabuller ve kısıtlar anlaşıldıktan sonra riskler daha iyi anlaşılır. Risk, bugün sorun olmayan ama gelecekte sorun olabilecek durumdur; risk tanımına ona karşı geliştirilecek plan da dahildir.
- Kalite planı
  - Kalite planı kalite yönetiminin nasıl yapılacağını tanımlar. Yazılım geliştirmede kalite için yapılanların başında gözden geçirme (review) gelir.
  - Gözden geçirme ekibi (müşteri tarafından kimler, müşteri ekibin içinde mi) ve gözden geçirmenin zamanlaması belirlenir.
  - Zamanlama ya takvime göre (üç ayda, altı ayda bir) ya da süreç adımlarına bağlı kilometre taşlarına göre (gereksinim analizi bitti, ön tasarım bitti, veritabanı tasarımı bitti, program tasarımı bitti) yapılır.
  - Kalite planında hata maliyetleri, hata durumunda birim testinin yeniden yapılması, kalitenin ölçülmesi, gözden geçirme planı, walkthrough türü gözden geçirme ve versiyon kontrolü (konfigürasyon yönetimi) yer alır.
- Ayrıntılı etkinlik listesi ve iş kırılım yapısı (WBS)
  - Yazılım projesinde etkinlikler yazılım geliştirme sürecinin adımlarıdır. Ana adımlar (planlama, gereksinim analizi, tasarım, gerçekleştirme, test) alt adımlara bölünür.
  - Gereksinim analizinin temelde üç alt adımı vardır; Pressman'ın kitabında bu yedi alt adım olarak verilir: başlangıç/fizibilite, bilgi toplama, ayrıntılandırma (elaboration, modelleme), pazarlık (negotiation), SRS belgesinin yazılması, doğrulama (validation) ve gereksinim yönetimi.
  - Etkinlik listesinin ayrıntısı hem süreç modeline hem de işin ne kadar ayrıntılı ele alınacağına bağlıdır. Çevik süreçte iş küçük parçalara bölünür; her parça için analiz, tasarım ve gerçekleştirme yapılıp birleştirilir.
  - İş kırılım yapısı (Work Breakdown Structure, WBS): Projedeki bütün etkinliklerin hiyerarşik olarak seviyelere ayrıldığı listedir. Ağaç olarak ya da girintili, numaralı liste olarak gösterilebilir (ekrandan, 00:30:00).
  - Numaralandırma: Örnek WBS'te ana işler 5'er aralıkla numaralanır (1.0 yönetim ve destek, 5.0 donanım seçimi ve edinimi, 10.0 sistem geliştirme, 20 müşteriye teslim, 25.0 uygulamaya geçiş). Aralık bırakmak sonradan iş eklemeyi kolaylaştırır. 10.20.15 gibi bir numara üçüncü seviyedeki bir öğedir (ekrandan, 00:35:00).
- WBS hazırlarken dikkat edilecekler
  - Önce yönetim, koordinasyon ve kontrol dahil bütün işler yazılır, sonra seviyelendirilir.
  - Etkinlikler bağımsız olmalı, her etkinliğe bir çalışan grubu atanabilmeli, etkinlikler arası iletişim sağlanmalı ve proje ilerlemesi etkinliklerden izlenebilmelidir.
  - Her etkinliğin tanımında: hangi işi gerçekleştirdiği, girdileri, gereken iş gücü ve çalışan türü, kaynakları, kimin hangi oranda çalışacağı ve çıktısı yer alır.
- Etkinlikler arası bağımlılıklar (ekrandan, 00:40:00)
  - Bitiş-Başlangıç (finish-start, FS): Öncül bitince ardıl başlar. En sık kullanılan ve Gantt araçlarında varsayılan bağımlılıktır.
  - Bitiş-Bitiş (finish-finish, FF): Öncül bitmeden ardıl bitemez (örnek: kodlama bitmeden dokümantasyon bitmez; geliştirme bitmeden test bitmez).
  - Başlangıç-Başlangıç (start-start, SS): Ardılın başlaması için öncülün başlamış olması gerekir, bitmiş olması gerekmez (örnek: bilgi toplama başladıktan sonra modelleme başlayabilir).
  - Başlangıç-Bitiş (start-finish, SF): Nadirdir; kitap bunu dikkate almaz.
  - Gecikme (lag) ve öne alma (lead): Bağımlılığa süre eklenebilir (örnek: bilgi toplama başladıktan beş gün sonra modellemeye başla).
- Tahmin ve kaynak sınıflandırma (ekrandan, 00:45:00)
  - Tahmin bütçe değildir: tahmin iş gücünü (adam-gün, adam-ay), bütçe parayı ifade eder.
  - Tahmin aşağıdan yukarı, WBS'in en alt seviyesinde yapılır; üst seviyenin tahmini alt seviyelerin toplamıdır.
  - İş gücü tahmininin üç bileşeni: işi yapacak kişinin iş sınıfı (rolü), her iş sınıfı için gereken zaman yüzdesi ve etkinliğin toplam iş gücü (saat ya da gün).
- MS Project ile Gantt ve PERT uygulaması (oturumun ikinci yarısı, ekrandan, 01:00:00-01:25:00)
  - Örnek proje: bir bitirme projesi (literatür taraması, danışman toplantısı, veri seti oluşturma, ara rapor yazımı, uygulama).
  - Özet görev, alt görev (girinti), otomatik zamanlama, öncüller, öteleme (lag), kilometre taşı (0 günlük görev), kaynak atama, kaynak ücreti, kritik görevler ve bolluk (slack), çalışma takvimine hafta sonu ekleme ve ağ (PERT) diyagramı gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Planlama, proje anlaşılıp tanımlanmadan yapılmaz
  - Teslim edilecekler, kapsam, değişiklik yönetimi kuralları ve süreç modeli planlamadan önce belirlenmiş olmalıdır.
- Teslim edilecekler yalnız kod değildir
  - Yazılımın sonradan yaşamasını sağlayacak belgeler ve kodun teslim edilip edilmeyeceği baştan belirlenir.
- Kabul, kısıt ve risk birbirine çok benzer ama kavram olarak farklıdır
  - Maddeleri neredeyse aynı olabilir; kabul olumlu varsayım, kısıt sınır, risk gelecekte ortaya çıkabilecek sorundur.
- Gözden geçirme zamanlaması
  - Gözden geçirmenin takvime mi yoksa süreç adımlarına bağlı kilometre taşlarına mı göre yapılacağı kalite planında açıkça yazılmalıdır.
- WBS hiyerarşiktir
  - Gantt aracında etkinlikler alt alta yazılır ama seviyelendirme (girinti) aracın içinde yapılır.
- Varsayılan bağımlılık bitiş-başlangıçtır
  - Gantt aracında hiçbir tür seçilmezse bağımlılık bitiş-başlangıç kabul edilir.
- Yazılım proje yönetiminde üç bilgi alanı gerekir
  - Alan bilgisi (yazılım/bilgisayar mühendisliği), proje yönetimi bilgisi ve temel yönetim bilgisi. Gantt ve PERT proje yönetimi tekniklerine girer.

## Kısa Tekrar Notları

- Planlama sırası: riskler, kabuller ve kısıtlar, kalite planı, etkinlik listesi, bağımlılıklar, tahmin, çizelge ve kilometre taşları, kaynak atama ve seviyeleme, bütçe, iletişim planı, planın yazılması.
- Teslim edilecekler: kod, SRS, tasarım belgesi, test örnekleri, plan, risk planı, veritabanı tanımları.
- Kabul = olumlu varsayım; kısıt = planın sınırı; risk = gelecekte olabilecek sorun ve ona karşı plan.
- Kalite planının merkezinde gözden geçirme vardır; walkthrough ve versiyon kontrolü önerilir.
- WBS = etkinliklerin hiyerarşik listesi; ağaç ya da girintili numaralı liste; numaralarda aralık bırakmak ekleme kolaylığı sağlar.
- Bağımlılık türleri: FS (varsayılan), FF, SS, SF (nadir); lag ile gecikme eklenir.
- Tahmin ≠ bütçe; tahmin aşağıdan yukarı yapılır.
- MS Project'te süresi 0 gün olan görev kilometre taşıdır (elmas simgesi).
- Kritik görev uzarsa proje bitişi uzar; kritik olmayan görevin bolluğu (slack) vardır.
- Gantt diyagramı başlangıç-bitiş tarihlerini, PERT (ağ) diyagramı görevler arası bağlantıları daha iyi gösterir.

## Detaylı Açıklamalar

- **Planlamaya geçiş.** Ders, önceki iki aşamanın kısa tekrarıyla başladı. Projeyi anlama aşamasında gerekçe, arka plan, politikalar, oyuncular ve müşterinin önceliği sorgulanır. Projeyi tanımlama aşamasında teslim edilecekler, sistem ve proje kapsamı, teslim edileceklerin gözden geçirilme biçimi ve müşteri organizasyonu belirlenir. Ayrıca teslime kadar müşterinin isteyeceği değişikliklerin nasıl kayıt altına alınacağı ve maliyetinin nasıl karşılanacağı da bu aşamada kurala bağlanır. Son olarak hangi yazılım geliştirme süreç modelinin (şelale, spiral, RAD, prototip, birleşik süreç, Scrum, XP ya da bunların hibriti) kullanılacağına ekip, kurum ve proje yapısına göre karar verilir.

- **Kabuller, kısıtlar ve riskler.** Kabuller, plan yapılırken doğru varsayılan şeylerdir: hiçbir çalışanın projeden ayrılmayacağı, proje bitene kadar kimsenin rapor ya da izin almayacağı (iş gücü analizi buna göre yapılır) ya da her çalışanın seçilen programlama dilini ve veritabanı yönetim sistemini bildiği (ayrıca eğitim süresi ayrılmaz). Kısıtlar planın dayandığı sınırlardır; örneğin belirli bir dönemde projede yalnız bir sistem analistinin çalışabilecek olması. Bunlar anlaşıldığında riskler kolay görülür: bir kabul tutmazsa ortaya çıkacak durum bir risktir. Riskler ayrıntılı olarak sonraki derslerde ele alınacaktır.

- **Kalite planı ve gözden geçirmeler.** Kalite planında ilk belirlenen, gözden geçirmelerin kimlerle ve ne zaman yapılacağıdır. Çevik bir yöntem kullanılıyorsa müşteri sürekli ekibin içinde olabilir. Gözden geçirmeler takvime bağlı (üç ayda, altı ayda bir) ya da süreç adımlarına bağlı kilometre taşlarında yapılabilir: gereksinim analizi bittiğinde, genel tasarım bittiğinde, ayrıntılı tasarımın alt adımları (veritabanı tasarımı, program tasarımı) bittiğinde. Kitaba göre kalite planı hataların maliyetini, programda hata bulununca birim testinin yinelenmesini, kalitenin ölçülmesini, gözden geçirme planını (walkthrough türü önerilir) ve versiyon kontrolünü (konfigürasyon yönetimi) içerir.

- **Ayrıntılı etkinlik listesi.** Bir yazılım projesinin etkinlikleri yazılım geliştirme sürecinin adımlarıdır. Örneğin gereksinim analizi bir üst başlıktır; altında en basit hâliyle üç alt adım vardır. Pressman bunu yedi adımda verir: başlangıç (fizibilite), bilgi toplama, ayrıntılandırma (modelleme ve diyagramlar), pazarlık, SRS belgesinin oluşturulması, doğrulama ve gereksinim yönetimi. Pazarlık adımında müşteri tarafındaki farklı departman ve çalışanların çelişen istekleri giderilir ve isteklerin geliştirici açısından yapılabilir olup olmadığı konuşularak bir sonuca varılır; sistem analisti bu yüzden geliştiricilerle müşteri arasında köprü kuran kişi olarak tanımlanır. Gereksinim yönetimi, gereksinimlerin geliştirme boyunca karşılanıp karşılanmadığının izlenmesidir.

- **İş kırılım yapısı (WBS).** WBS bütün proje etkinliklerinin seviyelere ayrılmış listesidir. Kitaptaki örnek bir anahtar teslim bilgi sistemi projesidir: 1.0 yönetim ve destek, 5.0 donanım seçimi ve edinimi (5.5 seçim: gereksinimlerin tanımlanması, satıcıların belirlenmesi, değerlendirme; değerlendirmenin altında değerlendirme kurallarının yazılması, sunumlar, referans kontrolü, fiyat pazarlığı ve son seçim; 5.10 edinim), 10.0 sistem geliştirme, 20 müşteriye teslim, 25.0 uygulamaya geçiş (25.5 uygulama planı, 25.10 uygulamaya destek, 25.15 uygulama sonrası gözden geçirme) (ekrandan, 00:35:00). Numaralar seviyeyi gösterir; aralıklı numara vermek araya iş eklemeyi kolaylaştırır. WBS ancak yeterince kararlı hâle geldiğinde numaralandırılmalıdır, yoksa yeniden numaralama gerekir (ekrandan, 00:35:00).
  <!-- BELİRSİZ: Örnek WBS tablosunun (Exhibit 4.10) tamamı karelerde görünmüyor; 5.0 ve 10.0 altındaki maddeler altyazıdan aktarıldı. -->

- **Bağımlılıklar.** Bağımlılık iki etkinlik arasındaki ilişkidir; bağımlı olan ardıl (successor), bağlı olunan öncül (predecessor) adını alır (ekrandan, 00:40:00). Dört tür vardır: bitiş-başlangıç, bitiş-bitiş, başlangıç-başlangıç ve nadir görülen başlangıç-bitiş. Gecikme (lag) ile ardılın öncülden belirli bir süre sonra başlaması sağlanır. Bu ilişkilerden bir öncelik-sonralık (öncül-ardıl) diyagramı oluşturulur.

- **Tahmin.** Her etkinliğin ne kadar süreceği, kaç kişi gerektiği ve hangi rollerin hangi oranda çalışacağı tahmin edilir. Örneğin donanım seçimi etkinliğinde daha çok donanım analistleri ve proje yöneticisi çalışır. Tahmin bütçe değildir; tahmin iş gücü, bütçe para birimiyle ifade edilir. Tahmin WBS'in en alt seviyesinde yapılır, üst seviyeler bunların toplamıdır (ekrandan, 00:45:00).

- **MS Project ile Gantt uygulaması.** Oturumun ikinci yarısında bir bitirme projesi örneği üzerinden MS Project'te Gantt grafiği oluşturuldu (ekrandan, 01:20:00):

```text
ÇÇY  Görev                    Süre    Başlangıç  Bitiş      Öncüller
0    Bitirme Projesi          41 gün  4.04.23    30.05.23
1    Literatür Taraması       8 gün   4.04.23    13.04.23
1.1    IEEE                   3 gün   4.04.23    6.04.23
1.2    Elsevier               3 gün   4.04.23    6.04.23
1.3    SpringerLink           3 gün   7.04.23    11.04.23   2
1.4    Google Scholar         4 gün   7.04.23    12.04.23   3
1.5    Danışman Toplantısı    0 gün   13.04.23   13.04.23   5TB+1 gün;4
2    Veri Seti Oluşturma      8 gün   14.04.23   25.04.23
2.1    Görüntü Toplama        5 gün   14.04.23   20.04.23   6
2.2    Görüntüleri Etiketleme 8 gün   14.04.23   25.04.23   8BB
3    Ara Rapor Yazımı         4 gün   27.04.23   2.05.23    9TB+1 gün;8
3.1    Özet-Giriş             4 gün   27.04.23   2.05.23
3.2    Method                 3 gün   27.04.23   1.05.23
3.3    Rapor teslimi          0 gün   2.05.23    2.05.23    11;12
4    Uygulama                 20 gün  3.05.23    30.05.23   13
```

  - ÇÇY sütunu WBS numarasıdır. "TB" bitiş-başlangıç, "BB" başlangıç-başlangıç bağımlılığıdır; "+1 gün" bir günlük ötelemedir.
  - Süresi 0 gün olan danışman toplantısı ve rapor teslimi kilometre taşıdır.
  - Özet görevlerin süresi alt görevlerden otomatik hesaplanır.
  - Kritik görevler gösterildiğinde (Biçim > Kritik Görevler, Bolluk) SpringerLink taramasının bolluğu olduğu görülür: danışman toplantısı ondan bir gün sonra biten Google Scholar taramasına bağlı olduğu için SpringerLink bir gün uzasa da proje bitişi değişmez.
  - Proje > Çalışma Zamanını Değiştir ile cumartesi ve pazar çalışma günü yapılınca proje bitiş tarihi öne geldi (ekrandan, 01:25:00).
  - Kaynak sayfasında kaynaklara standart ücret girilir; ücret görevlere çalışılan güne göre dağıtılır (ekrandan, 01:25:00).
  - Ağ (PERT) diyagramı görevler arası bağlantıyı gösterir, kritik görevler kırmızı, diğerleri mavidir; ancak başlangıç-bitiş tarihlerini Gantt grafiği kadar net göstermez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
