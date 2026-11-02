# Ders 5 Çalışma Özeti

## Genel Konular

- Gantt diyagramı ve iş kırılım yapısı (Work Breakdown Structure, WBS) tekrarı.
- Faaliyetler arası ilişki tipleri: FS, SS, FF, SF.
- Kritik yol (critical path), kilometre taşı (milestone) ve bolluk (slack) kavramları.
- Kaynak tanımlama ve kaynak ataması.
- PERT diyagramı (Program Evaluation and Review Technique) ve CPM (Critical Path Method) farkı.
- MS Project ile proje planlama ve izleme adımları, temel çizgi (baseline) kavramı.
- Yazılım proje maliyet tahmin yöntemleri: bilirkişi takdiri, Delphi yöntemi, analiz yöntemi, istatistik modeller.
- COCOMO ve Putnam modelleri.
- Yazılım büyüklük ölçümü: LOC/KLOC ve işlev noktası (Function Point).
- Dönem planı: ara sınav 27 Nisan 2021, sunumlar 4 Mayıs 2021'den itibaren.

## Hocanın Özellikle Vurguladığı Kısımlar

- Faaliyetler arası varsayılan ilişki bitiş-başlangıçtır (Finish to Start). Bu yüzden FS ayrıca yazılmaz.
- Kritik yoldaki bir faaliyet x gün gecikirse proje de x gün gecikir. Kritik faaliyetler Gantt diyagramında kırmızı gösterilir.
- Kilometre taşı sıfır günlük bir olaydır ve eşkenar dörtgen ile gösterilir.
- PERT süresi belirsiz faaliyetler için, CPM süresi önceden belli faaliyetler için kullanılır. Yazılım projelerinde süreler belirsiz olduğu için PERT daha uygundur.
- En önemli kaynak insandır. Sınırlı kaynaklar önce planlanır, diğerleri onlara göre ayarlanır.
- Uygulama projesinde en az MS Project düzeyinde bir proje yönetim aracı kullanılmalı. Proje planı izlenmeli ve gösterilmeli.
- Uygulama projesi yalnızca plan değildir: gereksinim analizi yapılacak, SRS dokümanı çıkarılacak, bir modülün tasarımı ve programı gerçekleştirilecek.
- Analiz yönteminde her alt işe bol süre verilirse "birleştirme şaşkınlığı" ortaya çıkar: toplam süre ve maliyet beklenenin çok üstüne çıkar. Bu durumda süreler yeniden sıkıştırılır.
- LOC objektif bir ölçü değildir ama doğrudan ve kolay ölçüldüğü için yine de kullanılır.

## Kısa Tekrar Notları

- WBS: faaliyetlerin ve alt faaliyetlerin hiyerarşik listesi. WBS numarası (1.1, 1.2) ile Gantt sıra numarası farklıdır.
- İlişki tipleri:
  - FS (bitiş-başlangıç): B'nin başlaması için A bitmeli. Varsayılan.
  - SS (başlangıç-başlangıç): B'nin başlaması için A başlamış olmalı.
  - FF (bitiş-bitiş): B'nin bitmesi için A bitmiş olmalı.
  - SF (başlangıç-bitiş): B'nin bitmesi için A başlamış olmalı. Nadir kullanılır.
- `2SS+1`: 2 numaralı faaliyet başladıktan 1 gün sonra bu faaliyet başlar.
- Bolluk (slack): kritik yolda olmayan bir faaliyetin projeyi geciktirmeden kayabileceği süre.
- Kritik yolda ileri geçiş ve geri geçiş süreleri eşittir, yani bolluk sıfırdır.
- PERT beklenen süresi: $t_e = \dfrac{t_o + 4t_m + t_p}{6}$ ($t_o$ iyimser, $t_m$ en olası, $t_p$ kötümser).
- Maliyet tahmin yöntemleri: bilirkişi takdiri, Delphi, analiz yöntemi (ürüne göre veya üretim aşamasına göre), istatistik modeller.
- İstatistik modellerin genel biçimi: $Y = aX^b$.
- Temel COCOMO: iş gücü $E = a \cdot \text{KLOC}^b$ (kişi-ay), süre $T = c \cdot E^d$.
- Orta COCOMO: iş gücüne ürün, donanım, personel ve proje özelliklerinden gelen bir düzeltme faktörü (EAF) eklenir.
- İşlev noktası: $FP = \text{sayı toplamı} \times (0{,}65 + 0{,}01 \sum_{i=1}^{14} F_i)$.
- LOC programlama diline bağlıdır. FP dilden bağımsızdır ama daha öznel ve verisi zor toplanır.

## Detaylı Açıklamalar

### Gantt diyagramı ve WBS örneği

- Gantt diyagramı 1910'lardan beri kullanılır. Her faaliyetin başlangıç ve bitiş zamanını ve kaynaklarını tek şemada gösterir.
- Örnek proje: kitap satışı yapan bir web sitesinin geliştirilmesi.
  - Şelale (waterfall) modeli kullanılıyor. Ana adımlar: analiz, tasarım, geliştirme ve test.
  - Başlangıç 24 Mart, bitiş 29 Nisan olarak verilmiş.
  - Analiz altında fizibilite çalışması ve gereksinimlerin belirlenmesi var. Bunlar WBS'de 1.1 ve 1.2, Gantt'ta 2. ve 3. faaliyettir.
- Örnekte WBS yalnızca 2. düzeye inmiş. Daha sıkı izlenmesi gereken projelerde 3. ve 4. düzeye kadar inilir.
- Öncül (predecessor) sütununda faaliyetler arası ilişki yazılır. Örnekler:
  - Analiz bitimi toplantısı, gereksinimlerin belirlenmesi bitince yapılır.
  - Ayrıntılı tasarım için ön tasarım, ön tasarım için analiz bitmiş olmalı.
  - Gereksinimlerin belirlenmesi ile fizibilite arasında `2SS+1` ilişkisi var: fizibilite başladıktan bir gün sonra gereksinim belirleme başlar.
  - Birim test için iki koşul var. SS: kodlama başlamışsa birim test başlayabilir. FF: kodlama bitmeden birim test bitemez, çünkü test edilecek yeni kod kalmamış olmalı.
- Örnekte neredeyse tüm faaliyetler kritik yolda. Yalnızca bir faaliyet (mavi) kritik değil ve bolluğu var.
- Kilometre taşları: analiz bitimi toplantısı, tasarım bitimi toplantısı, proje teslim toplantısı.

### Kaynak ataması

- Kaynaklar: insan (en önemlisi), ekipman (bilgisayar, ağ cihazları), para, seyahat, malzeme, alt yükleniciler.
- Önce kaynaklar tanımlanır: projeye ayrılma oranı (örnekte herkes %100), standart saat ücreti, fazla mesai ücreti. Hosting servisi gibi malzemeler miktarıyla girilir.
- Sonra hangi kaynağın hangi faaliyete ne kadar süreyle atanacağı belirlenir.
- Planlamada önce görev tipi yazılır ("2 sistem analisti"). Atama yapılınca kişi adlarıyla özelleştirilir.
- Bir faaliyeti birden fazla kişi yapabilir.

### PERT ve CPM

- PERT graf temelli bir yöntemdir. Gantt faaliyetlerin paralelliğini iyi gösterir ama dolaylı bağımlılıkları göstermekte zayıftır. PERT bu bağlantıları daha iyi gösterir.
- MS Project'te "Network Diagram" görünümü Gantt planını PERT olarak gösterir. Kırmızı kutular kritik görevlerdir. Her kutuda başlangıç, bitiş, süre ve atanan kaynak yazar.
- PERT ve CPM ikisi de ağ (şebeke) diyagramıdır.
  - CPM: süreler kesin ve önceden belliyse. Örnek: her prosesin süresi dakikasına kadar belli bir otomasyon süreci.
  - PERT: süreler belirsizse. Yazılımda analiz ve tasarım süreleri projeye, müşteriye ve uygulama alanına göre değişir.
- PERT'te bir faaliyetin süresi iyimser, en olası ve kötümser tahminlerden hesaplanır. Bu hesabı genelde proje yönetim yazılımı istatistiksel olarak yapar.

### MS Project ile planlama ve izleme

- Bir proje yönetim aracı şunları yapabilmeli:
  - Faaliyet takvimini ve Gantt şemasını göstermek.
  - PERT diyagramı çizmek.
  - Kaynak kullanım yüzdelerini ve kaynak maliyetlerini analiz etmek.
- Gantt'tan alınan çıktılar: faaliyet süreleri, başlangıç-bitiş tarihleri, bağımlılıklar, kritik yol, bolluk süreleri, projenin toplam süresi ve bitiş tarihi. Bitiş tarihi istenen tarihi aşıyorsa plan sıkıştırılır.
- Planlama adımları:
  1. Proje başlangıç tarihini ve takvimi belirle.
  2. Görevleri gir.
  3. Süreleri hesapla ve gir.
  4. Kaynak listesini hazırla ve kaynakları ata.
  5. Görevler arası bağlantıları kur.
  6. Planı son kez ayarla ve temel çizgi (baseline) olarak kaydet.
- Proje bilgisi menüsünde başlangıç tarihi, öncelik, takvim türü ve para birimi tanımlanır. Ayrıca görevlerin saatle mi sabit birimle mi girileceği seçilir.
- Takvim ayarları: çalışma saatleri (örneğin 8-17), günde 8 saat, haftada 40 saat, ayda yaklaşık 20 iş günü, resmî tatiller. Mali yıl farklı bir ayda başlayabilir.
- İletişim: ekip üyelerine görev atamalarının ve olayların bildirilmesi. Teams gibi araçlar bunu destekler. Çok uluslu ekiplerde bu özellik daha önemlidir.
- Baseline, yapılandırma yönetiminden (configuration management) gelen bir kavramdır.
  - Plan tamamlanınca ilk baseline kaydedilir.
  - Her dönüm noktasında (analiz sonu, tasarım sonu) plan yeniden kaydedilir. Planlanan ile gerçekleşen karşılaştırılır.
  - Gerçekleşenlere göre plan güncellenir. Bu döngü tüm aşamalar bitene kadar sürer.
  - Proje kapatılırken proje bilgileri arşive kaydedilir.
- İzleme sırasında atama bilgileri girilir: işin ne kadarının bittiği, kalan iş ve süre, gerçek başlama tarihi, maliyet. Kalan işin fazla mesaiyle mi normal mesaiyle mi bitirileceği de belirtilir.
- Görevler tamamlanma durumuna veya kritik olup olmamasına göre filtrelenebilir.
- MS Project dışında açık kaynaklı ve ekip çalışmasını daha iyi destekleyen araçlar da kullanılabilir.

### Yazılım proje maliyet tahmin yöntemleri

- Planlama aşamasındaki tahminler genelde tutarsızdır. Analiz ve tasarım ilerledikçe plan güncellenerek tahmin iyileştirilir.
- **Bilirkişi takdiri:** benzer projelerde çalışmış deneyimli proje yöneticisi, bitmiş projelere benzeterek tahmin yapar.
- **Delphi yöntemi:** birden fazla uzmanın görüşü birleştirilerek ortak bir tahmine varılır. Adımlar:
  1. Sistem tanımlanır, uzmanlar seçilir.
  2. Anket soruları hazırlanır ve dağıtılır.
  3. Sonuçlar analiz edilir. Görüşler ortak karara yakınsa rapor hazırlanır.
  4. Yakın değilse ek bilgi verilir, yanıtlar düzenlenir ve anket tekrarlanır.
  - Delphi yalnızca maliyet tahmini için değil, genel olarak ortak karara varmak için kullanılan bir yöntemdir.
- **Analiz yöntemi:** proje hiyerarşik olarak parçalara ayrılır. En alt elemandan başlanarak her parçanın maliyeti tahmin edilir ve yukarı doğru toplanır.
  - Ürüne göre: yazılımın modülleri.
  - Üretim aşamasına göre: proje yönetimi, analiz, tasarım, kodlama, birim test, birleştirme ve kabul testi.
  - Bu yöntem diğer yöntemlerle birlikte kullanılabilir.
- **İstatistik modeller:** uzman bilgisi yerine bitmiş projeler arşivini kullanır. Arşivde projenin türü, süresi, maliyeti, aşama maliyetleri ve riskleri bulunur.

### COCOMO ve Putnam modelleri

- COCOMO (Constructive Cost Model), Barry Boehm'in modelidir. Boehm yazılım ekonomisi alanındaki ilk çalışmaları yapmıştır.
- Temel COCOMO: KLOC (bin kod satırı) üzerinden iş gücü kestirilir. $E = a \cdot \text{KLOC}^b$, $T = c \cdot E^d$.
- $a, b, c, d$ katsayıları çok sayıda bitmiş proje üzerinde istatistiksel olarak bulunmuştur. Hoca 64 projeden söz etti.
- Orta COCOMO: ürün, donanım, personel ve proje özelliklerine göre bir düzeltme faktörü eklenir. Slayttaki aralık 0,90-1,40.
- COCOMO'da uygulama:
  1. Ürünün alt sistemleri ve modülleri tanımlanır.
  2. Her modülün büyüklüğü tahmin edilir.
  3. Modül düzeyinde düzeltme faktörleriyle iş gücü ve süre hesaplanır.
  4. Değerler yukarı doğru toplanır.
  5. Duyarlılık analizi yapılır. Planlama ve analiz giderleri de eklenir.
  6. Sonuçlar Delphi ile birkaç uzmana değerlendirilir.
- Putnam modeli (altyazıda "Putnam Reyle"): iş gücünü KLOC, teknoloji katsayısı ve geliştirme süresine (yıl) bağlar.
- Her iki modelde başlangıç büyüklüğü KLOC yerine işlev noktası da olabilir.

### Yazılım büyüklük ölçümü

- Yazılımda karmaşıklık ölçütleri gibi birçok ölçüt vardır (örneğin döngüsel karmaşıklık, cyclomatic complexity). Bu derste büyüklük ölçümüne odaklanıldı.
- Doğrudan ölçüm: gider, süre, komut satırı, hız. En önemli örneği LOC.
- Dolaylı ölçüm: birden fazla değer kullanılır. En önemli örneği işlev noktası.
- LOC/KLOC kullanım alanları:
  - Verimlilik: bu büyüklükteki yazılım için kaç kişi-ay çalışıldı.
  - Kalite: belirli kullanım süresinde KLOC başına hata sayısı.
  - Gider: KLOC başına maliyet.
  - Belgeleme: KLOC başına belge sayfası.
- İşlev noktası hesabı:
  - Sayılan öğeler: kullanıcı girdisi, çıktı, sorgu, dosya, dış arabirim sayısı.
  - Her öğe basit, orta veya karmaşık olarak sınıflandırılır ve ağırlık faktörüyle çarpılır. Örnekler: girdi 3/4/6, dosya 7/10/15.
  - Çarpımlar toplanır: sayı toplamı.
  - 14 genel özellik sorusu 0-5 arası puanlanır. Örnekler: güvenli yedekleme ve geri yükleme, iletişim altyapısı, dağıtık işleme, kritik performans, yoğun sistem yükü, çevrim içi veri girişi.
  - Örnekte $\sum F_i = 32$. Düzeltme çarpanı $0{,}65 + 0{,}01 \times 32 = 0{,}97$.
- İşlev noktası da LOC gibi verimlilik, kalite, gider ve belgeleme ölçümünde kullanılır. Örneğin işlev noktası başına gider veya belge sayfası.
- LOC ve FP karşılaştırması:

| Ölçüt | LOC | Function Point |
|---|---|---|
| Programlama diline bağlılık | Bağlı | Bağımsız |
| Nesnellik | Doğrudan fiziksel ölçü | Daha öznel, kullanım özelliklerine dayanır |
| Veri toplama | Kolay (satır sayılır) | Zor (girdi, çıktı, dosya vb. sayılır) |
| Zayıf yön | İyi tasarlanmış kısa kodu ve işlemsel olmayan dilleri iyi değerlendiremez | Tahmine dayanır |

### Dönem planı ve duyurular

- 6. ve 7. haftalarda konu anlatımı sürecek.
- 8. hafta (27 Nisan 2021) ara sınav yapılacak. Büyük ihtimalle test usulü olacak; hoca kesin karar vermedi. Lisans sınav haftasıyla aynı haftaya konuldu.
- Kaynaklar:
  - Pressman, *Software Engineering* kitabının proje yönetimi bölümleri.
  - *Information Systems Project Management* kitabı (AMACOM yayınları).
  - Hocanın AVESİS sayfasındaki slaytlar. Bir kısmı henüz yüklenmedi.
- Sunumlar 9. haftadan (4 Mayıs 2021) itibaren başlayacak. Önce makale sunumları, sonra uygulama projesi sunumları yapılacak. Sınıf kalabalık olduğu için her birine üç hafta ayrıldı.
- Bir öğrenci makale sunumunu 11 Mayıs'ta yapmak istedi; hoca kaydetti.
- Uygulama konusunu bildirmeyenler bu hafta bildirmeli. Makale önerisine 4 gün içinde dönüş almayanlar e-postayı yeniden göndermeli.
- Erasmus öğrencisine sınav tarihi ve Pressman kitabının proje yönetimi konuları İngilizce olarak iletildi.

### Ders sonrası notlar

- Hoca PERT formülünü "en kötümser süre + 4 × en olası süre + en kötümser süre, bölü 6" diye okudu. Doğrusu ilk terimin iyimser süre olmasıdır: $t_e = (t_o + 4t_m + t_p)/6$.
- Hoca varsayılan ilişki için "artık buna FF yazmamız gerekmiyor" dedi. Kastedilen FS'dir. Yazılmayan varsayılan ilişki bitiş-başlangıç (FS) ilişkisidir.
- Hoca SS ilişkisini önce "fizibilitenin başlayabilmesi için gereksinim belirlemenin başlaması" diye söyledi, sonra düzeltti. Doğrusu: gereksinim belirleme, fizibilite başladıktan 1 gün sonra başlar.
- Hoca düzeltme çarpanının sayı toplamını "küçülteceğini" söyledi. Bu yalnızca $\sum F_i < 35$ için doğrudur. Çarpan 0,65 ile 1,35 arasında değişir; büyük $\sum F_i$ değerlerinde sayı toplamını artırır.
- Altyazıdaki "Kokomo" COCOMO, "BOEM" Boehm, "DELF/DELFI" Delphi, "K-Log/Carlock" KLOC, "Presma" Pressman, "Amacom" AMACOM olmalı.
- Boehm'in orijinal COCOMO çalışması literatürde 63 projeye dayanır; hoca 64 dedi.
- CPM ve PERT'in karmaşıklık karşılaştırmasındaki cümle altyazıda karışık ("CPM PERT'den daha karmaşık CPM'e göre"). Genel kabul: PERT üç süre tahmini kullandığı için CPM'den daha karmaşıktır; CPM tek süre kullanır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
