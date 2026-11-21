# Ders 4 Genişletilmiş Notu: Gereksinim Mühendisliği Adımları, Nesneye Yönelik Çözümleme, Kullanım Öyküleri (Use Case) ve UML Kullanım Şemaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Akademik Veritabanlarına ve Standartlara Uzaktan Erişim (VETİS ve IEEE Xplore)
- 2. Gereksinim Mühendisliği Süreci ve 7 Temel Adımı
- 3. Gereksinimlerin Sınıflandırılması ve İzlenebilirlik Tabloları (Traceability Tables)
- 4. Nesneye Yönelik Çözümleme (Object-Oriented Analysis) ve Uygulama Alanı Analizi
- 5. Doğal Dilden Kullanım Öykülerine Geçiş ve NextGenPOS Örneği
- 6. UML Kullanım Şemaları (Use Case Diagrams) ve Violet UML Uygulaması
- Örnek Sorular
- Dersin Toparlaması

## 1. Akademik Veritabanlarına ve Standartlara Uzaktan Erişim (VETİS ve IEEE Xplore)

Bir önceki dersin sonunda yazılım gereksinimleri belgesi (**SRS — *Software Requirements Specification***) standartlarından (**`IEEE 830-1998`** ve **`ISO/IEC/IEEE 29148:2011`**) söz edilmişti. Bu dersin başında hoca, genellikle ücretli olan uluslararası standartlara, bilimsel dergilere ve konferans bildirilerine üniversite kütüphanesinin kurumsal aboneliği üzerinden nasıl uzaktan erişilebileceğini uygulamalı olarak göstermiştir.

Üniversite kütüphanesinin web sayfasında öğrenci numarası (akademik personel için sicil numarası) ile kütüphane hesabı oluşturulduktan sonra, eski ve verimsiz vekil sunucu (*proxy server*) yöntemi yerine geliştirilen **VETİS (Kampüs Dışı Erişim Sistemi)** üzerinden **IEEE Xplore Digital Library** veritabanına bağlanılabilir. Üniversite kütüphaneleri temel aboneliklerinin yanı sıra zaman zaman ek veritabanlarını "deneme erişimine" açarlar; akademisyen ve öğrencilerden yoğun talep gören deneme paketleri daha sonra kalıcı aboneliğe dönüştürülür.

Hoca, IEEE Xplore üzerinden **IEEE Std 830-1998** (*IEEE Recommended Practice for Software Requirements Specifications*) standardını aratıp tam metin PDF belgesini açarak standartların yapısı hakkında iki önemli noktaya dikkat çekmiştir:
1. **Standartların Olgunlaşması ve Revizyon Döngüsü:** Yaklaşık 39–40 sayfalık bir belge olan `IEEE 830-1998`, kendisinden önceki **1993** sürümünün 1998 yılında revize edilmesiyle ortaya çıkmıştır. Bir standart yeterince olgunlaşıp oturduğunda uzun süre yeniden düzenlemeye (*refactoring* / revizyona) ihtiyaç duymadan yürürlükte kalabilir.
2. **Telif Hakları ve Mesleki Etik:** İndirilen standart PDF'lerinin altbilgisine (*footer*) sistem tarafından otomatik olarak hangi üniversitenin aboneliği üzerinden ve hangi tarihte indirildiği bilgisi basılır. Kurumsal abonelikle erişilen bu korumalı kaynakları kurum dışındaki kişilerle paylaşmak mesleki etik kurallarına aykırıdır.

## 2. Gereksinim Mühendisliği Süreci ve 7 Temel Adımı

**Gereksinim mühendisliği (*Requirements Engineering*)**, yazılım projesinin amaçlarını, kapsamını ve kısıtlarını belirleyen 7 adımlı bir süreçtir (ekrandan, 00:18:10). Bu yedi adım kendi içinde şelale modeli gibi ardışık olarak yürütülebileceği gibi, daha önce hiç girilmemiş yeni bir problem alanında çalışılıyorsa çevik (*agile*) bir yaklaşımla artımsal ve yinelemeli olarak da yürütülebilir. Hangi süreç modeli seçilirse seçilsin, gereksinimler **müşterinin gereksinimleri** olduğu için gereksinim mühendisliği ve çözümleme aşamalarında müşterinin sürece aktif olarak katılması ve yazılım ekibiyle yakın çalışması zorunludur.

Slaytta gereksinim mühendisliğinin 7 adımı Türkçe ve İngilizce terimleriyle şöyle sıralanmıştır (ekrandan, 00:18:10):
1. **Başlangıç (*Inception*)**
2. **Bilgi Toplama (*Elicitation*)**
3. **İşleme (*Elaboration*)**
4. **Pazarlık (*Negotiation*)**
5. **Tanımlama (*Specification*)**
6. **Doğrulama (*Validation*)**
7. **Yönetim (*Management*)** (tüm proje boyunca devam eden şemsiye etkinlik)

### 2.1 Başlangıç (Inception)

**Başlangıç (*Inception*)** adımı, yazılımın bir fikir olarak doğduğu ve yazılım projesinin **ilk aşamalarının** (yani gereksinim mühendisliğinin diğer adımlarının ve yapılabilirlik [*feasibility*] çalışmasının) başlatılıp başlatılmamasına karar verilen adımdır (ekrandan, 00:18:10). Bir yazılım fikri iki kaynaktan doğabilir (ekrandan, 00:18:10):

- **Müşterinin bir yazılım projesi başlatılmasını düşünmesine neden olan olaylar (ekrandan, 00:18:10):**
  - *Yeni bir iş gereksiniminin belirlenmesi,*
  - *Mevcut iş süreçlerinde güçlüklerle veya verimsiz noktalarla karşılaşılması,*
  - *Müşterinin üst düzey karar vericileri ve astları arasında geçen kısa bir sözlü konuşma veya toplantı* (örneğin kahve makinesi başında veya asansörde geçen iki dakikalık bir görüşme bile başlangıç aşamasını ateşleyebilir).
- **Bir uygulama yazılımı (yazılım evinin kendi ürünü) söz konusu ise (ekrandan, 00:18:10):**
  - *Yeni bir pazarın veya verilmesi yararlı olacak bir hizmetin farkına varılması,*
  - *Yazılım şirketinin üst düzey karar vericileri ve teknik ekibinin sözlü konuşması ile yeni bir yazılım projesinin başlatılması* (*"Müşterilerimiz şu konuda güçlük yaşıyor, bunu şöyle tasarlayabiliriz"* $\rightarrow$ *"Kulağa iyi geliyor, gereksinim ve yapılabilirlik çalışmasına başla, sonra devam edip etmeyeceğimize karar verelim"*).

Genel amaçlı bir uygulama yazılımı geliştirilecek olsa bile, temel gereksinimleri belirlemek ve ilk **pilot uygulamayı** gerçekleştirmek üzere bir müşteriyle anlaşılabilir. Hoca burada **prototip** ile **pilot uygulama** arasındaki farkı özellikle vurgulamıştır:
- **Prototip (*Ön ürün*):** Tam işlevsel olmayan, gereksinimleri veya tasarımı doğrulamak için hızlıca hazırlanan modeldir.
- **Pilot uygulama:** İlk sürümü tamamlanmış olan gerçek ürünün, ilk kez gerçek bir müşteri ortamında uygulanması ve denenmesidir. Pilot uygulamanın yapıldığı müşteride daha önce öngörülmemiş teknik aksaklıklar çıkma olasılığı (teknik risk) daha yüksektir; ancak müşteri bunun karşılığında sorunların yazılım ekibince çok yakından ve hızla çözülmesi avantajını ve **daha indirimli/avantajlı fiyat** olanağını elde eder. Yazılım evi ise projenin sonraki fazları ve diğer müşterilere yapılacak satışlar için çok değerli saha verileri kazanır.

> **Hocanın vurgusu:** Başlangıç (*Inception*) aşamasında yapılması gereken **en önemli etkinlik paydaşların (*stakeholders*) belirlenmesidir**; çünkü ikinci aşama olan bilgi toplamada bilginin kimlerden toplanacağı bu listeye bağlıdır. Gerçeklenecek sistemden doğrudan veya dolaylı, olumlu veya olumsuz etkilenecek tüm paydaşlar, bunların sisteme **bakış açıları** ve **kazanma durumları** daha bu ilk adımda sorular sorularak netleştirilmelidir.

### 2.2 Bilgi Toplama (Elicitation)

**Bilgi Toplama (*Elicitation*)** aşamasında, başlangıç adımında belirlenen tüm paydaşların etkin katılımı sağlanarak gereksinimler hakkında ayrıntılı ham bilgi toplanır. Bu işin en doğru yolu tüm paydaşların katıldığı **yüz yüze toplantılar** düzenlemektir. Verimli bir bilgi toplama toplantısının üç temel kriteri vardır:
1. **Ön Hazırlık ve Katılım Kuralları:** Katılımcılar toplantı kurallarını bilmeli ve toplantıya ön hazırlık yaparak gelmelidir.
2. **Dengeli Gündem (*Agenda*):** Toplantının önceden belirlenmiş bir gündemi olmalıdır; ancak gündem ne kadar ayrıntılı ve sıkı tutulmalıdır? Gündem **aşırı katı ve ayrıntılı** olursa yaratıcılığı baltalar; oysa bu aşamada toplantıların **beyin fırtınası (*brainstorming*)** havasında geçmesi ve mümkün olduğunca çok fikir keşfedilmesi istenir. Tersine, gündem **tamamen ucu açık** bırakılırsa toplantı dağılır, ayrıntıda boğulunur ve verimli ilerlenemez. Bu nedenle önemli konuları atlamayacak ama beyin fırtınasını da engellemeyecek bir denge noktası kurulmalıdır.
3. **Oturum Başkanı (*Moderator / Chair*):** Farklı paydaşların bakış açıları ve çıkarları birbiriyle çeliştiği için toplantılarda kaçınılmaz olarak tıkanıklıklar yaşanır. Bu tıkanıklıkları çözecek yetenekli bir oturum başkanına ihtiyaç vardır. Hoca, kalabalık ve kaotik toplantılarda düzeni sağlama konusunda klasik bir başvuru kaynağı olarak ABD'nin kuruluş dönemindeki parlamenter toplantı kurallarına dayanan ***Robert's Rules of Order*** kitabını referans vermiştir.

### 2.3 İşleme (Elaboration)

**İşleme (*Elaboration*)** aşaması, bilgi toplama adımında elde edilen **ham verilerin işlenerek yapılandırılmış bilgiye dönüştürüldüğü** ve ayrıntılandırıldığı adımdır (ekrandan, 00:30:00). Bu aşamada şu çalışmalar yürütülür (ekrandan, 00:30:00):
- **Kullanıcı-Yazılım Etkileşiminin Belirlenmesi ve *Storyboarding*:** Son kullanıcının ve diğer paydaşların yazılımla nasıl etkileşimde bulunacağı belirlenir (ekrandan, 00:30:00). Bunun için sinema ve animasyon sektöründe senaryonun kritik sahnelerinin karikatürist/ressam tarafından kare kare çizilmesine benzeyen **hikâye tahtası (*storyboarding*)** yöntemi kullanılabilir. Yazılımda *storyboarding* mutlaka elle çizim veya grafik programıyla yapılmak zorunda değildir; *Visual Basic* gibi sürükle-bırak (*drag-and-drop*) tarzı bir GUI tasarım ortamında ana veri giriş ekranlarının, rapor ekranlarının ve hangi düğmeye basıldığında hangi ekrana geçileceğinin hızlıca çizilmesi de etkili bir *storyboard* uygulamasıdır. Ayrıca etkileşimler **kullanım senaryoları (*use cases*)** ile gösterilir (ekrandan, 00:30:00).
- **Bilgilerin Özetlenmesi ve Genişletilmesi:** Toplanan ham verilerin bir kısmı aşırı ayrıntılı veya tekrarlı (*duplicate*) ifadeler içeriyorsa bunlar özetlenerek daraltılır; buna karşılık bir işlev hakkında yalnızca bir-iki cümle söylenmiş ve yeterli bilgi toplanamamışsa ilgili paydaşlara (yazışmayla veya küçük bir ek toplantıyla) geri dönülerek o kısım genişletilir (ekrandan, 00:30:00).
- **Gereksinimlerin Sınıflandırılması:** Elde edilen gereksinimler hem teknik niteliklerine göre (**işlevsel / işlevsel olmayan**) hem de müşteri beklenti düzeyine göre (**normal / beklenen / heveslendirici**) sınıflandırılır (ekrandan, 00:30:00). Bu sınıflandırma bir sonraki bölümde ayrıntılı olarak incelenmiştir.

### 2.4 Pazarlık (Negotiation)

**Pazarlık (*Negotiation*)** aşamasında, farklı paydaşların birbiriyle çelişen gereksinimleri ve öncelik dereceleri uzlaştırılır. Üstelik müşteri tarafındaki tüm paydaşlar kendi aralarında tam bir uzlaşıya varmış olsalar bile, talep ettikleri özelliklerin tamamı projenin mevcut **zaman, bütçe ve insan kaynağı** sınırları içinde gerçeklenemeyecek kadar büyük olabilir. Müşteri bu teknik çaba tahminini tam olarak yapamayacağı için, gereksinimleri doğru zamanlama ve bütçeye kanalize etmek yazılım evinin görevidir. Ayrıca yazılım evi de vereceği sözü tutmak zorunda olan bir paydaş olarak kendi bakış açısını pazarlık masasına koyar. Bu adımın sonunda **tüm paydaşların razı olduğu ve altına imza atabileceği uzlaşılmış bir gereksinimler listesi** elde edilir (ancak imza henüz atılmaz; önce tanımlama ve doğrulama adımları tamamlanmalıdır).

### 2.5 Tanımlama (Specification)

**Tanımlama (*Specification*)** aşamasında, pazarlık adımında uzlaşılan ancak hâlâ doğal konuşma diliyle veya dağınık toplantı tutanakları hâlinde bulunan gereksinimler, konuşma dilinin doğal belirsizliğinden arındırılarak kendi içinde tutarlı, mantıksal kurallara dayanan ve doğrulanabilir yöntemlerle belgelendirilir:
1. **Doğal konuşma dili metinleri:** Tamamen sıfırlanamasa da belirsizliği azaltmak için mümkün olduğunca daraltılır.
2. **Kullanım senaryosu metinleri (*Use case narratives*) ve UML kullanım şemaları (*Use case diagrams*):** Hoca bu iki aracın her projede bulunmasının **elzem** olduğunu vurgulamıştır.
3. **İsteğe bağlı görsel araçlar:** *Storyboard* çizimleri ve çeşitli özelliklere yönelik **prototipler**.
4. **Formel modeller (*Formal models*):** İşin mantıksal ve matematiksel açıdan en uç noktasıdır. Gereksinimlerin ve bileşen davranışlarının matematiksel gösterime dayanan, teorem olarak ispatlanabilir mantıksal dillerle (örneğin **Z dili**) tanımlanmasıdır. Türkiye'de ve dünyada ticari yazılımlarda nadiren görülür; ancak yolcu uçağı **uçuş kontrol yazılımı**, sensör verilerine dayalı ulusal **afet erken uyarı sistemi** (hatalı alarmın kitlesel panik, kaos, ekonomik yıkım ve can kaybına yol açabileceği sistemler) veya **savunma sanayii** yazılımları gibi **görev kritik (*mission-critical*)** sistemlerde kodlamaya geçmeden önce matematiksel doğrulama yapmak için kullanılır.

### 2.6 Doğrulama (Validation)

**Doğrulama (*Validation*)** aşaması, tanımlanmış gereksinimlerin tutarsızlıklara ve hatalara karşı sınandığı bir test etkinliğidir; çünkü gereksinim aşamasında gözden kaçan bir hata ilerleyen aşamalarda üstel olarak artan bir maliyetle geri döner (ekrandan, 00:50:00). Bu adımda şu soruların sağlaması yapılır (ekrandan, 00:50:00):
- *Gereksinimler açıkça ve insan yorumuna yer bırakmayacak şekilde tanımlanmış mı?*
- *Birbiri ile çelişen gereksinimler var mı?* (Pazarlık aşamasında yapılan uzlaştırma hatalarından ötürü hâlâ çelişkiler kalmış olabilir.)
- *Gereksinimlerde hatalar ve eksikler var mı?* (Belirlenmiş bir gereksinimin ayrıntılarının eksik kalması durumu.)
- *Eksik gereksinimler var mı?* (Hiç keşfedilememiş, tamamen gözden kaçmış gereksinimler.)
- *Gerçekçi olmayan gereksinimler var mı?* (Özellikle teknik ekibin deneyimsizliğinden kaynaklanan, mevcut teknoloji veya kaynaklarla yapılamayacak vaatler.)

Doğrulama yapmak için önerilen temel yöntem, ilerleyen haftalarda sınama teknikleri kapsamında ayrıntılı işlenecek olan ve belirli bir gündem/ön hazırlık disipliniyle yürütülen **Resmi Teknik Değerlendirme (*Formal Technical Review* — FTR)** toplantısıdır (ekrandan, 00:50:00).

### 2.7 Yönetim (Management)

**Yönetim (*Management*)** aşamasıyla birlikte, doğrulamadan geçmiş olan gereksinim mühendisliği çıktı belgesi (**SRS**) resmi proje sözleşmesinin ayrılmaz parçası hâline gelir ve taraflarca imzalanır (çevik süreçlerde daha hafif sıklet, ardışık süreçlerde ise personel görevlendirme ve SGK/mevzuat ayrıntılarını da içeren daha ağır sıklet sözleşmeler imzalanır; ayrıca olası gereksinim değişikliklerinin nasıl fiyatlandırılıp uzlaşılacağına dair ilkeler de sözleşmeye eklenir).

Ancak gereksinim yönetimi sözleşme imzalanınca biten bir adım değil, **tüm yazılım geliştirme süreci boyunca yürütülen şemsiye bir süreçtir**. Daha bakım aşamasına bile geçmeden yeni gereksinimler eklenebilir, mevcut gereksinimlerin bir kısmı geçerliliğini yitirebilir, önem sıraları değişebilir veya zaman/çaba tahminlerindeki sapmalar yüzünden bazı (özellikle heveslendirici) gereksinimlerden erken aşamada vazgeçilebilir.

## 3. Gereksinimlerin Sınıflandırılması ve İzlenebilirlik Tabloları (Traceability Tables)

### 3.1 İşlevsel (Functional) ve İşlevsel Olmayan (Non-Functional) Gereksinimler

İşleme (*Elaboration*) aşamasında ve birinci ders saatinin sonundaki soru-cevap bölümünde hoca, gereksinimlerin teknik doğasına göre **işlevsel (*functional*)** ve **işlevsel olmayan (*non-functional*)** olarak ikiye ayrıldığını somut örneklerle açıklamıştır:

**Soru:** Fonksiyonel olmayan gereksinimleri tekrar açıklayabilir misiniz? Bunlar da uygulamaya dahil ediliyor mu?

**Cevap:** Evet, her tür gereksinim uygulamaya dahil edilir. İkisi arasındaki fark şudur:
- **İşlevsel Gereksinimler (*Functional Requirements*):** Sistemin problem alanının çekirdek iş kuralları ve iş mantığı çerçevesinde **yapması gereken işler ve sahip olması gereken yeteneklerdir**.
  - *Örnek 1 (Raporlama):* *"Sistemde şu içeriklere sahip şu raporlar hazırlanabilmelidir."*
  - *Örnek 2 (Kütüphane Otomasyonu):* *"Kullanıcı modülünde ödünç verme ve iade alt modülleri yer almalıdır. Öğrenciler kitapları 2 hafta süreyle ödünç alabilmeli ve birer haftalık en fazla 2 uzatma yapabilmelidir; gecikme durumunda gün başına 1 TL ceza uygulanmalıdır. Akademik personel ise 4 hafta süreyle ödünç alabilmeli, ikişer haftalık 3 uzatma yapabilmeli; gecikme durumunda gün başına 5 TL ceza uygulanmalıdır. Bu kurallar kütüphane yönetimi tarafından sistem üzerinden tanımlanabilmelidir."*
- **İşlevsel Olmayan Gereksinimler (*Non-Functional Requirements*):** Bu işlevler yerine getirilirken **hangi sistem düzeyi özelliklerin, platform/mimari kısıtlarının veya başarım (performans) ölçütlerinin** sağlanması gerektiğini belirten gereksinimlerdir.
  - *Örnek 1 (Veritabanı kısıtı):* *"Verinin kalıcılığı ilişkisel veritabanı yönetim sistemi kullanılarak sağlanmalı ve müşteriye ek lisans maliyeti çıkarmamak için MySQL kullanılmalıdır."*
  - *Örnek 2 (Başarım kısıtı):* *"Sistem 1000 kayıtlık bir raporu 1 saniyenin altında hazırlayabilmelidir."*
  - *Örnek 3 (Platform ve çalışma ortamı kısıtı):* *"Kütüphane bilgi sistemi mutlaka kütüphanenin kendi sunucularında yerel (on-premise) olarak çalıştırılmalı ve Red Hat Linux 12.0 sürümü desteklenmelidir."*

### 3.2 Normal, Beklenen (Expected) ve Heveslendirici (Exciting) Gereksinimler

Gereksinimler müşteri beklentisi açısından üç kategoriye ayrılır (ekrandan, 00:38:50):
1. **Normal Gereksinimler:** Müşterinin toplantılarda açıkça dile getirdiği, sistemin yapması gereken işlevsel ve işlevsel olmayan gereksinimlerdir (ekrandan, 00:38:50).
2. **Beklenen Gereksinimler (*Expected Requirements*):** Çok temel gereksinimlerdir; o problem alanındaki herkesin (hatta alan dışındaki insanların bile genel kültür olarak) bu özelliği bildiği varsayıldığı için **kullanıcı bunları açıkça belirtmeyebilir** (ekrandan, 00:38:50). Örneğin bir kütüphane otomasyonunda fiziksel kitapların belirli bir süreyle ödünç verildiği ve zamanında iade edilmezse ceza uygulandığı herkesçe bilinir; kütüphane personeli bunu söylemeyi atlayabilir. Eğer yazılım evi daha önce hiç kütüphane otomasyonu yapmamışsa bu temel gereksinimi fark edemeyebilir ve değişiklik maliyeti zamanla üstel arttığı için ileride büyük bir kriz yaşanır.
   > **Hocanın vurgusu:** Beklenen gereksinimler çok tehlikelidir. Gereksinim mühendisliği ekibinin bir üyesi olarak herhangi bir konuda en ufak bir belirsizlik, soru işareti veya "içinizi gıcıklayan" bir nokta varsa **asla varsayımda bulunmayın, mutlaka müşteriye sorun**; altında müşterinin söylemeyi unuttuğu bir beklenen gereksinim yatıyor olabilir.
3. **Heveslendirici Gereksinimler (*Exciting Requirements*):** Müşteri beklentilerinin ve temel ihtiyaçlarının ötesinde olan, gerçeklendiğinde müşteriyi çok sevindirecek ve projeyi kurum içinde sevdirmeye yarayacak ancak olmazsa olmaz olmayan **"lüks"** özelliklerdir (ekrandan, 00:38:50). Gerçekten lüks olan bu özelliklerin baştan "heveslendirici" olarak işaretlenmesi hem yazılım evinin hem de müşterinin elini rahatlatır: projede süre veya bütçe sıkıntısıyla karşılaşıldığında temel ve beklenen gereksinimlere dokunmadan bu heveslendirici gereksinimlerden kolayca vazgeçilebilir.

> **Ek bilgi (derste anlatılmadı):** Gereksinimlerin *Normal (Performance/Linear)*, *Beklenen (Must-be/Expected)* ve *Heveslendirici (Attractive/Exciting)* şeklinde üçlü sınıflandırılması, yazılım mühendisliği ve kalite yönetimi literatüründe büyük olasılıkla Noriaki Kano tarafından 1984 yılında geliştirilen **Kano Modeli**'ne dayanmaktadır.

### 3.3 İzlenebilirlik Tabloları (Traceability Tables)

Gereksinim yönetimi (*Management*) aşamasında gereksinimlerin gerçeklenmesini ve değişikliklerin etkisini takip etmek (*trace* etmek) için **İzlenebilirlik Tabloları (*Traceability Tables* / Matrisleri)** kullanılır (ekrandan, 00:55:30):

```text
               Sisteme Çeşitli Bakış Açıları (Modüller, Paketler, Sınıflar vb.)
                     +------+------+------+------+
                     |  B1  |  B2  |  B3  | ...  |
              +------+------+------+------+------+
              |  G1  |  ✓   |      |  ✓   |      |
Gereksinimler |  G2  |      |  ✓   |      |      |
 (G1, G2, ..) |  G3  |  ✓   |      |      |      |
              | ...  |      |      |      |      |
              +------+------+------+------+------+
```

Bir projede birden fazla izlenebilirlik tablosu oluşturulur (ekrandan, 00:55:30):
- Her tablonun **satırlarında** gereksinimler ($G_1, G_2, G_3, \dots$) yer alır.
- **Sütunlarında** ise sisteme yönelik çeşitli **bakış açıları ($B_1, B_2, B_3, \dots$)** bulunur: birinci tabloda sütunlar **modüller** (Personel Modülü, Rapor Modülü, Kargo Modülü vb.), ikinci tabloda **paketler**, üçüncü tabloda ise **sınıflar** olabilir (en başta henüz sınıf tasarımı yapılmadığı için modül tablosuyla başlanır; analiz ve tasarımda ilerledikçe paket ve sınıf tabloları eklenir).
- İlgili gereksinim hangi modül, paket veya sınıfla ilişkiliyse kesişim hücresine işaret ($\checkmark$ veya matris gösteriminde `1`, diğer hücrelere `0`) konulur. Örneğin yukarıdaki tabloda $G_1$ gereksinimi $B_1$ ve $B_3$ ile, $G_2$ gereksinimi ise yalnızca $B_2$ ile ilişkilidir (ekrandan, 00:55:30).

**İzlenebilirlik Tablosunun Sağladığı İki Büyük Yarar:**
1. **Değişiklik Yönetimi:** Müşteri $G_1$ gereksiniminde bir değişiklik istediğinde, bu değişikliğin hangi modülleri, paketleri ve sınıfları ($B_1$ ve $B_3$) etkileyeceği anında görülür.
2. **Sınama ve Hata Ayıklama (*Debugging*) Uzayını Daraltma:** Yazılımda bir hata (*bug*) çıktığında, hatanın hangi gereksinimle ($G_1$) ilgili olduğu zaten bellidir. İzlenebilirlik tablosuna bakılarak $G_1$'in yalnızca $B_1$ ve $B_3$ sınıflarıyla ilişkili olduğu görülür; böylece yüzlerce sınıf arasında kaybolmak yerine **arama uzayı doğrudan $B_1$ ve $B_3$ sınıflarına daraltılarak** hatanın kök nedenine hızla odaklanılır.

## 4. Nesneye Yönelik Çözümleme (Object-Oriented Analysis) ve Uygulama Alanı Analizi

Sözlük anlamıyla **çözümlemek (analiz etmek)**, bir bütünü anlamak için parçalarına ayırmaktır. Yazılım mühendisliğinde **Nesneye Yönelik Çözümleme (*Object-Oriented Analysis*)** aşamasında temel olarak **"Ne?"** sorusu sorulur:
- Uygulama alanını (*problem domain*) anlamak (alandaki varlıklar nelerdir, nitelikleri ve eylemleri nelerdir, bu varlıklar arasındaki etkileşimler ve sahiplik/parça-bütün ilişkileri nelerdir?),
- Kullanıcı gereksinimlerini anlamak (gereksinim mühendisliğini çözümlemenin ilk adımı sayan yaklaşımlarda bu madde çözümlemenin içindedir; öncülü sayan yaklaşımlarda ise gereksinim mühendisliğinde tamamlanmış kabul edilir),
- Gerçek dünya problemini sınıflar ve nesneler cinsinden **alan modeline (*domain model* / analiz modeli)** taşımak ve üst düzey planlama eylemlerini yürütmek (örneğin gereksinim aşamasında *"en az 5 yıl deneyimli 5 personel çalışacak"* kararı alınmışsa, eldeki bu kritere uyan 6 personelden hangilerinin projeye atanacağını belirlemek).

### 4.1 Uygulama Alanının Çözümlenmesi (Domain Analysis)

Slaytta uygulama alanını anlamak ve bilgileri analiz modeline taşımak için yararlanılabilecek 5 temel kaynak listelenmiştir (ekrandan, 01:20:00):
1. **Teknik literatür** (akademik yayınlar, kitaplar ve uluslararası standartlar — hocanın en çok güvendiği birincil kaynak),
2. **Mevcut uygulamalar** (problem alanındaki rakip yazılımların işlevlerini ve ücretsiz demo sürümlerini inceleyerek *"Başkaları ne yapmış, biz üstüne ne katabiliriz ve nasıl farklılaştırabiliriz?"* sorusunu sormak),
3. **Müşteri anketleri** (potansiyel kullanıcı kitlesinden beklenti toplamak),
4. **Uzman tavsiyeleri** (özellikle projenin yapıldığı özel bir müşteri yoksa veya henüz pilot müşteri bulunamamışsa bir **konu alanı uzmanından [*domain expert*]** danışmanlık almak),
5. **Mevcut ve gelecekteki gereksinimler** (sektörel dergiler, haberler ve gelecek eğilimi [*trend*] analizleri) (ekrandan, 01:20:00).

> **Hocanın vurgusu:** Problem alanı hakkında bilgi edinmeden **"müşterinin dilinden konuşamazsınız"** (ekrandan, 01:20:00). Her problem alanının kendine özgü bir terminolojisi (jargonu) vardır. Hem teknik belgelerde ve süreç yapıtlarında (*artifacts*) hem de son kullanıcı ekranlarında ve raporlarda aklımıza gelen ilk kelimeyi değil, **müşterinin o kavram için kullandığı terimi** kullanmak zorundayız; aksi hâlde iletişim kopuklukları yaşanır ve ekranlardaki etiketlerin bile sonradan tek tek düzeltilmesi gerekir.

## 5. Doğal Dilden Kullanım Öykülerine Geçiş ve NextGenPOS Örneği

Gereksinimlerin ilk belirlenmesi aşamasında müşterinin beklentilerini doğal konuşma diliyle anlatan bir **gereksinimler belgesi** ortaya çıkar (ekrandan, 01:26:00). Hoca, bundan sonraki tüm analiz ve tasarım adımlarında ortak örnek olarak kullanılacak olan **NextGenPOS Perakende Satış Programı** örnek gereksinimler belgesini slaytta paylaşmıştır (ekrandan, 01:26:00):

> **NextGenPOS Perakende Satış Programı**
> Eski yazılım ihtiyaçlarımızı karşılayamadığından, yenilenecek donanımla birlikte perakende satış programımızın da yenilenmesine gerek duyuyoruz. Program kasada yapılan alış-veriş işlemlerine yardımcı olmalıdır. Yapılan her işlem program tarafından saklanmalı; mali bilgiler harici bütçe sistemine, mal çıkış bilgileri ise harici envanter sistemine iletilmelidir. Saklanan işlemler üzerinde daha sonra raporlamalar ve analizler yapılabilmelidir. Sistem yapılan alış-verişler karşılığında müşteriye fiş vermelidir. Yapılan her satış için KDV de hesaplanarak ayrıca belirtilmelidir. Şirketimizin birden fazla şubesi olup tüm şubelerdeki işlemler merkezi sunucuya iletilmelidir. (ekrandan, 01:26:00)

*(Not: Hoca bu paragraftaki tüm cümlelerin sistemin yapacağı işleri anlattığı için **işlevsel gereksinim** olduğuna dikkat çekmiştir.)*

Doğal dille yazılmış bu metinden **kullanım öykülerine (*use cases* / kullanım senaryosu metinlerine)** geçiş yapılır (ekrandan, 01:26:00). **Kullanım öyküleri**, programın yapacağı işleri ve son kullanıcı ile sistemin nasıl etkileşeceğini ayrıntılı adımlarla, açık, net ve belirsizlikten uzak kurallarla anlatan yazılı belgelerdir. Bu metinler:
1. Son kullanıcı ile yazılım ekibi arasında net bir anlaşma zemini oluşturur,
2. UML kullanım şemalarının (*use case diagrams*) ve alan modelinin (*domain model*) çıkarılmasına temel oluşturur,
3. İleride yapılacak **doğrulama ve geçerleme sınamaları (*validation tests*)** için doğrudan test senaryosu zemini sağlar (sistemin senaryodaki adımlara uygun çalışıp çalışmadığı kontrol edilir).

### 5.1 Kullanım Öyküsü Metninin Yapısı ve 3 Ana Bölümü

Standart bir kullanım öyküsü metni **3 ana bölümden** oluşur:
1. **Giriş Bölümü:** Sistemin hangi koşullar ve sınırlar içinde neyi yapacağını tanımlar. Kendi içinde **4 alt bölümden** oluşur (ekrandan, 01:33:00):
   - **Birincil Aktör (*Primary Actor*):** Sistemle etkileşimde bulunan insanlara ya da harici yazılım/donanım sistemlerine **aktör (*actor*)** denir (örneğin mal çıkış bilgilerinin aktarıldığı *Harici Envanter Sistemi* insan olmayan bir aktördür). Bir kullanım öyküsüyle birden fazla aktör etkileşebilir; ancak işin odağında yer alan, işi başlatan veya en çok etkileşen aktör **birincil aktör** olarak seçilir.
   - **İlgililer ve İlgi Alanları (*Stakeholders and Interests*):** Bu öyküyle ilişkili tüm aktörler (paydaşlar) ve bu öyküden beklentileri (kazanma durumları) listelenir. Kullanım öyküsünde yer alacak her adım, burada tanımlanan ilgi alanlarına uygun olmalıdır (ekrandan, 01:33:00).
   - **Ön Koşullar (*Preconditions*):** Ana öykü başlamadan önce sistemin içinde bulunması gereken durum veya tamamlanmış olması gereken işlemdir (ekrandan, 01:33:00).
   - **Son Koşullar (*Postconditions*):** Ana öykü başarıyla tamamlandığında sistemin ulaşacağı durumdur (ekrandan, 01:33:00).
2. **Ana Öykü (*Main Success Scenario*):** Her şeyin yolunda gitmesi hâlinde yürütülecek eylemlerin `1`'den `N`'ye kadar numaralandırılarak anlatıldığı kısımdır (ekrandan, 01:36:30).
3. **Alternatif Öyküler (*Extensions / Alternative Flows*):** Ana öyküde bir aksilik, istisna veya `if-else` dallanması olduğunda (`else` dalında) yapılacak işlemlerin anlatıldığı kısımdır (ekrandan, 01:40:00).

### 5.2 Örnek Kullanım Öyküsü: Satış İşlemi

*NextGenPOS* gereksinimler belgesinden çıkarılan **Satış İşlemi** kullanım öyküsünün tam metni slaytlarda şu şekilde verilmiştir (ekrandan, 01:33:00; ekrandan, 01:36:30; ekrandan, 01:40:00):

```text
KULLANIM ÖYKÜSÜ: Satış İşlemi
--------------------------------------------------------------------------------
[1. GİRİŞ BÖLÜMÜ]
Birincil Aktör: Kasiyer.
İlgililer ve İlgi Alanları:
• Kasiyer: Doğru ve hızlı giriş ister, kasa açığı maaşından kesildiğinden ödeme
  hataları istemez.
• Satıcı: Satış komisyonlarının güncellenmesini ister.
• Müşteri: En az çaba ile hızlı hizmet ister. Ürün iadesinde kullanmak üzere fiş
  ister.
• ...
Ön Koşullar:
• Kasiyerin kimliği doğrulanır.
Son Koşullar:
• Ödeme tahsil edilir. Satış kaydedilir. Fiş yazılır.
--------------------------------------------------------------------------------
[2. ANA ÖYKÜ]
1.  Müşteri kasaya alacağı ürünlerle gelir.
2.  Kasiyer yeni bir satış işlemi başlatır.
3.  Kasiyer ürünün barkodunu girer.
4.  Sistem bir satış kanalı maddesi oluşturur. Bu maddede ürün tanımı, fiyatı ve
    toplam bedel (aynı maldan birden fazla alınmış olabilir) yer alır.
5.  Kasiyer 3. ve 4. adımları müşterinin alacağı tüm ürünler için tekrarlar.
6.  Sistem toplam bedeli KDV ile birlikte hesaplar.
7.  Kasiyer müşteriye toplamı bildirir ve ödeme ister.
8.  Müşteri ödemeyi yapar ve sistem ödemeyi tahsil eder.
9.  Sistem tamamlanan işlemin kaydını tutmayı tamamlar ve harici envanter ile
    mali sistemlere gerekli bilgileri gönderir.
10. Sistem fiş verir.
11. Müşteri ürünlerle birlikte ayrılır.
--------------------------------------------------------------------------------
[3. ALTERNATİF ÖYKÜLER]
3a. Geçersiz barkod
    1. Sistem uyarı mesajı verir ve kayıt girişini reddeder.
3-7a. Müşteri bir kalem malı alışverişten çıkartmak ister.
    1. Kasiyer satıştan çıkarmak üzere ürünün barkodunu okutur.
    2. Sistem güncel toplamı bildirir.
...
```

> **Ders sonrası not:** Slayt 71'deki Ana Öykü 6. adımda *"Sistem toplam bedeli vergi iadesi ile birlikte hesaplar"* yazmaktadır; hoca derste artık vergi iadesi uygulaması kalmadığını ve gereksinim metninde de KDV geçtiğini belirterek bu ifadeyi canlı yayında **"KDV ile birlikte hesaplar"** şeklinde düzeltmiştir (ekrandan, 01:36:30).

### 5.3 Kullanım Öyküsü Yazımında Kritik Kurallar

Hoca, kullanım öyküsü metni yazılırken uyulması gereken dört temel kuralı ayrıntılarıyla açıklamıştır:
1. **Ön Koşulların Ayrı Öyküye Dönüşmesi:** Ön koşullarda *"Kasiyerin kimliği doğrulanır"* denildiğinde analiz burada bırakılmaz; kimliğin anahtarla mı, akıllı kartla mı, kullanıcı adı-parolayla mı yoksa parmak iziyle mi doğrulanacağı ayrıntılandırılır ve dokümantasyonda başlı başına ayrı bir **Kimlik Doğrulama Kullanım Öyküsü** yer alır.
2. **Adımların Numaralandırılması (Ana ve Alternatif Öykü):**
   - Ana öyküde adımlar `1`'den başlayarak numaralandırılır; böylece 5. adımda olduğu gibi (*"Kasiyer 3. ve 4. adımları ... tekrarlar"*) başka adımlara referans verilerek döngüler kurulabilir. Hiçbir döngü olmasa bile ileride gelebilecek değişiklikler için numaralandırma zorunludur (yalnızca madde imi konulmaz).
   - Alternatif öykülerde **iki parçalı bir kodlama** kullanılır (ekrandan, 01:40:00):
     - **`3a`:** Ana öykünün **3. adımında** (barkod girilmesi) oluşabilecek **ilk (`a`)** alternatif durumu (*Geçersiz barkod*) gösterir.
     - **`3-7a`:** Ana öykünün **3. ila 7. adımları arasında** (3 ve 7 dahil; ürünlerin okutulmasından toplam bedelin bildirilmesine kadar herhangi bir anda) oluşabilecek **ilk (`a`)** alternatif durumu (*Müşterinin bir kalem malı alışverişten çıkartmak istemesi*) gösterir. Aynı `3-7` aralığında ikinci bir alternatif durum daha olsaydı **`3-7b`** olarak adlandırılırdı.
     - Her alternatif öykünün kendi içindeki eylemler de yine `1, 2, ...` biçiminde numaralandırılır (hatta `3a` içindeki *"1. Sistem uyarı mesajı verir ve kayıt girişini reddeder"* cümlesi istenirse `1. Sistem uyarı mesajı verir`, `2. Sistem kayıt girişini reddeder` şeklinde iki ayrı alt madde olarak da yazılabilir).
     - Eğer müşteri ödeme tahsil edildikten sonra (9. adımdan itibaren) üründen vazgeçerse bu artık kasa içi silme değil, fişle birlikte müşteri ilişkileri bankosunda yürütülecek bir **Ürün İadesi** sürecidir; bu durum **`9a. Ürün iadesi`** olarak yazılıp ayrı bir *Ürün İade Kullanım Öyküsü*'ne referans verilebilir.
3. **Alternatifleri Ana Öyküye Sıkıştırmama:** Koşullu (`if-else`) durumlar asla ana öykünün içine tıkıştırılmamalı, mutlaka **Alternatif Öyküler** bölümüne ayrılmalıdır.
4. **Edilgen Değil, Etken (*Active*) Cümle Kurma Zorunluluğu:**
   > **Hocanın vurgusu:** Kullanım öyküsündeki (hem ana hem alternatif öyküdeki) bütün cümleler **öznesi belli olan etken (*active*) cümleler** olmalıdır; **kesinlikle edilgen (*passive*) cümle kullanılmaz**. Örneğin 2. adımda *"Yeni satış işlemi başlatılır"* denmez, **"Kasiyer yeni bir satış işlemi başlatır"** denir. Çünkü edilgen yazıldığında işlemi kasiyerin ekrandaki bir düğmeye basarak mı başlattığı, yoksa sistemin yürüyen banda ürün konulduğunu sensörle algılayıp otomatik olarak mı başlattığı belirsiz kalır.

## 6. UML Kullanım Şemaları (Use Case Diagrams) ve Violet UML Uygulaması

Kullanım öyküsü metinleri işlevleri çok net tanımlasa da uzun ve ayrıntılı belgelerdir; sisteme kuşbakışı bakarak hangi işlevlerin (*use case*) bulunduğunu, bu işlevler arasındaki ilişkileri ve her işlevin hangi birincil aktörle etkileştiğini tek bir büyük resimde görmek için **UML Kullanım Şemaları (*Use Case Diagrams*)** çizilir (ekrandan, 01:40:00; ekrandan, 02:13:00).

> **Hocanın vurgusu (Use Case Şeması Ne Değildir?):**
> 1. Use case şeması **bir akış şeması (*flowchart*) değildir**; hangi işlemin hangi sırada yürütüleceğini göstermez (işlem sırasını göstermek *Sequence Diagram*, *Activity Diagram* ve *State Diagram*'ların görevidir).
> 2. Use case şeması **bir kullanıcı yetki/hak şeması da değildir**.
> 3. Gerçek bir projede yüzlerce use case olabileceği için şemayı karmaşıklaştırmamak adına her use case tüm aktörlerle değil, **yalnızca kendi birincil aktörü ile** ilişkilendirilir.

### 6.1 Çizim Kuralları ve Semboller

Slaytta UML kullanım şemasının temel sembolleri ve kuralları şöyle gösterilmiştir (ekrandan, 02:13:00):

```text
   O                     .-------------------.
  /|\ -------------------|    Use Case A     |
  / \                    |-------------------|
Kişi türü adı            | Extension Points  |
(İnsan Aktör)            |  Adım K, Adım L   |
                         '-------------------'
                             ^            \
                <<extends>> /              \ <<includes>>
                           /                v
                  .--------------.    .--------------.      .------------------.
                  |  Use Case B  |    |  Use Case C  |------|     <<actor>>    |
                  '--------------'    '--------------'      |  HW/SW Element   |
                                                            '------------------'
```

- **Use Case (İşlev):** Elips ile gösterilir, içine işlevin adı yazılır (ekrandan, 02:13:00).
- **İnsan Aktör (Kullanıcılar):** Çöp adam (*stick figure*) ile çizilir, altına kişi türü adı (ör. `Kasiyer`) yazılır (ekrandan, 02:13:00).
- **İnsan Olmayan Aktör (*HW/SW Element*):** Yazılımımızın tümleşik çalıştığı harici bir yazılım veya donanım bileşeni (ör. *Harici Envanter Sistemi*, *Banka Provizyon Sistemi*) dikdörtgen ile çizilir. Ancak UML sınıf şemalarında dikdörtgen "sınıfı" temsil ettiği için, bunun bir sınıf değil aktör olduğunu belirtmek üzere üst kısmına guillemet (`« »` veya iki küçüktür / iki büyüktür işaretiyle **`<<actor>>`**) stereotipi yazılır (ekrandan, 02:13:00).
- **Etkileşim / Kullanım (*Association*):** Aktör ile birincil olduğu use case arasındaki ilişki **düz çizgi** ile gösterilir (ekrandan, 02:13:00).
- **Use Case'ler Arası İlişkiler (`<<includes>>` ve `<<extends>>`):** İki use case arasındaki ilişki **kesikli çizgi ve ucu açık ok (`----->`)** ile çizilir ve üzerine stereotip olarak ilişkinin türü yazılır (ekrandan, 02:13:00):
  1. **`<<includes>>` (veya `<<include>>`) İlişkisi:** Ana senaryonun her çalışmasında mutlaka yürütülen bir alt senaryoyu veya zorunlu ön koşulu ifade eder. İngilizce okunuşu *"Use Case A includes Use Case C"* (A, C'yi içerir) olduğundan, **okun yönü ana senaryodan (`A`) içerilen alt senaryoya (`C`) doğrudur** (`A ----<<includes>>---> C`).
  2. **`<<extends>>` (veya `<<extend>>`) İlişkisi:** Yalnızca belirli bir koşul sağlandığında devreye giren **alternatif senaryoyu** ifade eder. (Hoca, buradaki `extends` teriminin Java'daki kalıtım [*inheritance*] anahtar kelimesiyle hiçbir ilgisi olmadığını, UML'in Java'dan önce de var olduğunu vurgulamıştır; aktörler veya use case'ler arasında kalıtım teknik olarak mümkün olsa da use case şemasında kalıtım gösterimine pratikte gerek yoktur.) İngilizce okunuşu *"Use Case B extends Use Case A"* (B alternatif senaryosu, A ana senaryosunu genişletir / A'nın bir alternatifidir) olduğundan, **okun yönü alternatif senaryodan (`B`) ana senaryoya (`A`) doğrudur** (`B ----<<extends>>---> A`).
  3. **Uzantı Noktaları (*Extension Points*):** İsteğe bağlı olarak ana use case elipsi ortadan bölünüp alt kısmına `Extension Points: Adım K, Adım L` (ör. `3`, `3-7`) yazılabilir ve `<<extends>>` okunun ucu doğrudan ilgili adım numarasına değdirilebilir (ağır sıklet CASE araçları bunu destekler ancak kullanımı zorunlu değildir) (ekrandan, 02:13:00).

**Soru:** Alternatif senaryolar UML kullanım şemasında `<<extends>>` olarak mı belirtilmeli?

**Cevap:** Evet. Kullanım öyküsü metninde yazılan alternatif senaryolar, UML use case şemasında ayrı birer use case elipsi olarak çizilmeli ve ana use case'e doğru `<<extends>>` (veya `<<extend>>`) okuyla bağlanmalıdır. Hiç alternatif senaryo yazmamak hem metin puanını hem de şemadaki `<<extends>>` puanını zincirleme olarak kaybettirir.

### 6.2 Violet UML Editor ile Genişletilmiş Satış Şeması Uygulaması

Hoca dersin son bölümünde hafif sıklet bir çizim aracı olan **Violet UML Editor** üzerinde *Satış İşlemi* kullanım şemasını adım adım oluşturmuş ve genişletmiştir (ekrandan, 02:36:00):

```text
    O
   /|\ ---------+-------------------------.
   / \          |                         |
 Kasiyer        |                         v
                |                 .---------------.     <<extend>>    .-----------------.
                |                 |     Satış     | < - - - - - - - - | Geçersiz Barkod |
                |                 '---------------'                   '-----------------'
                |                   /     ^     ^  \
                |          .-------'      |     |   '-------- <<include>> --------.
                |         /               |     |                                 v
        .-------------------------.       |     |   <<extend>>            .--------------.
        | Satışın ön koşuludur    |       |     '- - - - - - - - - - - -  |  Ürün Silme  |
        '-------------------------'       |                               '--------------'
                \                  <<extend>>                                     ^
                 \                      |                                         :
                  v                     |                                         :
         .-------------------.          |                               .-------------------.
         | Kimlik Doğrulama  |          |                               |   Provizyon       |
         '-------------------'          |                               '-------------------'
                                 .--------------.                                 |
                                 | Loyalty Card |                                 | <<extend>>
                                 '--------------'                                 v
                                        ^                                 .---------------.
                                         \                                |     Ödeme     |
                           .-----------------------------------------.    '---------------'
                           | Config.xml'de yapılan ayara göre        |
                           | includes ilişkisine de dönebilir.       |
                           '-----------------------------------------'
```

Şemadaki ilişkilerin mühendislik gerekçeleri şöyledir (ekrandan, 02:36:00):
- **`Kasiyer` — `Satış` ve `Kimlik Doğrulama`:** Kasiyer her iki işlemin de birincil aktörüdür. `Kimlik Doğrulama` satışın ön koşulu olduğu için ya bir UML **Not (*Note*)** kutusuyla *"Satışın ön koşuludur"* diye bağlanır ya da `Satış ----<<include>>---> Kimlik Doğrulama` oku çizilir.
- **`Satış ----<<include>>---> Ödeme`:** Bedavaya ürün verilmediği için her satış işlemi mutlaka bir ödeme işlemini içerir (`<<include>>`).
- **`Provizyon ----<<extend>>---> Ödeme`:** Ödemenin ana senaryosu nakit ödemedir. Ancak müşteri kredi kartı, banka kartı veya yemek kartı ile ödeme yapmak isterse POS cihazı banka sistemiyle haberleşerek **Provizyon** (PIN doğrulaması, kart limiti/bakiye kontrolü ve kayıp/çalıntı kart sorgusu) alır. Her ödeme kartla yapılmadığı için `Provizyon`, `Ödeme` use case'inin bir alternatif senaryosudur ve ok **Provizyon'dan Ödeme'ye doğru `<<extend>>`** olarak çizilir.
- **`Geçersiz Barkod ----<<extend>>---> Satış` ve `Ürün Silme ----<<extend>>---> Satış`:** Barkodun tanımsız çıkması (`3a`) ve müşterinin okutulan bir ürünü alışverişten çıkartmak istemesi (`3-7a`) her satışta gerçekleşmeyen alternatif akışlar olduğu için her ikisinden de `Satış` use case'ine doğru `<<extend>>` oku çizilir.
- **`Loyalty Card (Müşteri Sadakat Kartı) ----<<extend>>---> Satış`:** Süpermarketlerin müşteri alışveriş örüntülerini analiz edip kampanya sunmak ve karşılığında müşteriye indirim vermek için kullandığı sadakat kartları (*Loyalty Card*), normal perakende mağazalarda isteğe bağlıdır (kart olmadan da alışveriş yapılabilir); bu yüzden `Loyalty Card`'dan `Satış`'a doğru **`<<extend>>`** oku çizilir (hoca kendi hazır slaydında okun yönünün ters kaldığını fark edip canlı yayında `Loyalty Card ----<<extend>>---> Satış` yönüne düzeltmiştir) (ekrandan, 02:36:00). Ancak *Metro Gross Market* gibi yalnızca sadakat kartı sahiplerinin alışveriş yapabildiği toptancı mağazalarda bu kart bir ön koşuldur ve ilişki `Satış ----<<include>>---> Loyalty Card` olur. Eğer yazılım her iki mağaza tipine de satılacaksa, şemada `<<extend>>` okunun üzerine bir UML Notu (*Note*) bağlanarak *"Config.xml'de yapılan ayara göre includes ilişkisine de dönebilir"* açıklaması düşülebilir (ekrandan, 02:36:00).

## Örnek Sorular

### Soru 1: İşlevsel ve İşlevsel Olmayan Gereksinimlerin Ayrımı (Derste Sözlü ve Ekrandan, 00:35:00 – 01:01:15)

**Soru:** Bir kütüphane otomasyonu ve bir raporlama sistemi için aşağıda verilen gereksinim ifadelerini **işlevsel (*functional*)** ve **işlevsel olmayan (*non-functional*)** olarak sınıflandırınız ve nedenini açıklayınız:
1. *"Öğrenciler kitapları 2 hafta süreyle ödünç alabilmeli, gecikme durumunda gün başına 1 TL ceza uygulanmalıdır; akademik personel ise 4 hafta ödünç alabilmeli ve gecikme durumunda gün başına 5 TL ceza uygulanmalıdır."*
2. *"Verinin kalıcılığı ilişkisel veritabanı kullanılarak sağlanmalı ve ek lisans masrafı çıkarmamak için MySQL kullanılmalıdır."*
3. *"Sistem 1000 kayıtlık bir raporu 1 saniyenin altında hazırlayabilmelidir."*
4. *"Bilgi sistemi kütüphanenin kendi sunucularında yerel olarak çalıştırılmalı ve Red Hat Linux 12.0 sürümü desteklenmelidir."*

**Cevap (derste verildi):**
- **1. madde İşlevsel Gereksinimdir (*Functional Requirement*):** Sistemin problem alanının çekirdek iş kuralları çerçevesinde **ne iş yapacağını** (ödünç verme süreleri, uzatma hakları, kullanıcı tipine göre ceza hesaplama kuralları) tanımlar.
- **2, 3 ve 4. maddeler İşlevsel Olmayan Gereksinimlerdir (*Non-Functional Requirements*):** Sistemin işlevlerini yerine getirirken uyması gereken **sistem düzeyi kısıtları, teknoloji/lisans seçimini (*MySQL*), başarım/performans hedefini (*1000 kayıt < 1 saniye*) ve işletim sistemi/donanım platformunu (*yerel sunucu, Red Hat Linux 12.0*)** tanımlar.

---

### Soru 2: Doğal Dil Gereksinim Metninden Kullanım Öyküsü ve UML Use Case Şeması Çıkarma (Ekrandan, 01:26:00 – 02:36:00)

**Soru (hocanın derste verdiği klasik 1. vize soru kalıbı):** Aşağıda doğal konuşma diliyle verilen *NextGenPOS Perakende Satış Programı* gereksinimler belgesini okuyunuz:
> *"Program kasada yapılan alış-veriş işlemlerine yardımcı olmalıdır. Yapılan her işlem program tarafından saklanmalı; mali bilgiler harici bütçe sistemine, mal çıkış bilgileri ise harici envanter sistemine iletilmelidir... Sistem yapılan alış-verişler karşılığında müşteriye fiş vermelidir. Yapılan her satış için KDV de hesaplanarak ayrıca belirtilmelidir."* (ekrandan, 01:26:00).

1. Bu belgede yer alan **Satış İşlemi** için kurallara uygun bir **Kullanım Öyküsü (*Use Case*)** metni (Giriş, Ana Öykü ve en az iki Alternatif Öykü bölümleriyle) yazınız.
2. Yazdığınız kullanım öyküsünden (ve ödeme/sadakat kartı uzantılarından) yararlanarak **UML Kullanım Şemasını (*Use Case Diagram*)** çiziniz.

**Cevap (derste verildi):**
1. **Kullanım Öyküsü Metni:** Bölüm 5.2'de tam metni verilen *Satış İşlemi* kullanım öyküsüdür. Tam puan alabilmek için:
   - **Giriş** bölümünde *Birincil Aktör* (`Kasiyer`), *İlgililer ve İlgi Alanları* (`Kasiyer`, `Satıcı`, `Müşteri`), *Ön Koşullar* (`Kasiyerin kimliği doğrulanır`) ve *Son Koşullar* (`Ödeme tahsil edilir. Satış kaydedilir. Fiş yazılır.`) eksiksiz yer almalıdır (ekrandan, 01:33:00).
   - **Ana Öykü** adımları `1`'den `11`'e kadar numaralandırılmalı, 5. adımda `3. ve 4. adımlar`a döngü referansı verilmeli ve tüm cümleler **etken (*active*)** yapıda kurulmalıdır (ekrandan, 01:36:30).
   - **Alternatif Öyküler** ana öyküye tıkıştırılmamalı; `3a. Geçersiz barkod` ve `3-7a. Müşteri bir kalem malı alışverişten çıkartmak ister` şeklinde adım/aralık koduyla ve kendi alt adım numaralarıyla (`1, 2`) yazılmalıdır (ekrandan, 01:40:00).
2. **UML Kullanım Şeması:** Bölüm 6.2'de çizilen şemadır. `Kasiyer` çöp adam olarak `Satış` ve `Kimlik Doğrulama` elipslerine düz çizgiyle bağlanır; zorunlu içerme olan `Ödeme` için `Satış ----<<include>>---> Ödeme` oku, alternatif senaryolar için ise `Geçersiz Barkod ----<<extend>>---> Satış`, `Ürün Silme ----<<extend>>---> Satış`, `Loyalty Card ----<<extend>>---> Satış` ve `Provizyon ----<<extend>>---> Ödeme` kesikli ucu açık okları doğru yönde çizilir (ekrandan, 02:36:00).

## Dersin Toparlaması

Bu derste ilk olarak üniversite kütüphanesinin **VETİS** sistemi üzerinden **IEEE Std 830-1998** gibi yazılım mühendisliği standartlarına uzaktan erişim uygulaması gösterilmiş; ardından **Gereksinim Mühendisliği** sürecinin 7 adımı (**Başlangıç [*Inception*], Bilgi Toplama [*Elicitation*], İşleme [*Elaboration*], Pazarlık [*Negotiation*], Tanımlama [*Specification*], Doğrulama [*Validation*]** ve **Yönetim [*Management*]**) ayrıntılı olarak incelenmiştir. Gereksinimlerin **işlevsel / işlevsel olmayan** ve **normal / beklenen (*expected*) / heveslendirici (*exciting*)** olarak sınıflandırılması ile gereksinimlerin proje boyunca **İzlenebilirlik Tabloları (*Traceability Tables*)** aracılığıyla modül, paket ve sınıflarla eşleştirilerek izlenmesi ele alınmıştır.

Dersin ikinci yarısında **"Ne?"** sorusuna odaklanan **Nesneye Yönelik Çözümleme (*Object-Oriented Analysis*)** aşamasına geçilmiş; uygulama alanını (*domain*) anlama kaynakları ve müşterinin terminolojisiyle konuşmanın önemi vurgulanmıştır. *NextGenPOS Perakende Satış Programı* örneği üzerinden doğal dildeki gereksinimlerden **Kullanım Öyküsü (*Use Case*)** metni yazma kuralları (Giriş bölümü, numaralandırılmış ve etken cümleli Ana Öykü, `3a` ve `3-7a` formatlı Alternatif Öyküler) ve buradan **UML Kullanım Şeması (*Use Case Diagram*)** çizme kuralları (insan ve `<<actor>>` stereotipli insan olmayan aktörler, `<<includes>>` ve `<<extends>>` ok yönleri) *Violet UML Editor* üzerinde uygulamalı olarak gösterilmiştir. Bir sonraki derste çözümleme aşamasının devamı olarak **Alan Modeli (*Domain Model*)** oluşturulması işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
