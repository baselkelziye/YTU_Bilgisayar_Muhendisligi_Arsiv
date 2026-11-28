# Ders 6 Genişletilmiş Notu: Alan Modeli, Kullanım Senaryoları (Use Case) ve Nesne Yönelimli Tasarım Diyagramları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi: Analizden Tasarıma
- 2. Alan Modeli (Domain Model)
- 3. UP Kullanım Senaryosu Modelindeki Ürünler
- 4. Tasarım Kalıpları ve Yeniden Kullanılabilirlik
- 5. Kullanım Senaryoları (Use Case): Tanımlar
- 6. Use Case Seviyeleri ve Temel İş Süreci (EBP)
- 7. Use Case Diyagramları
- 8. Use Case Modelleme Kılavuzları
- 9. Tam Ayrıntılı (Fully Dressed) Use Case Örneği
- 10. Öz ve Somut Use Case'ler
- 11. Use Case Modellemenin Toparlanması
- 12. Nesne Yönelimli Tasarım Diyagramları

## 1. Dersin Çerçevesi: Analizden Tasarıma

Önceki derste gereksinim analizi ve nesneye yönelik analiz üzerinde durulmuştu. Bu derste önce, nesneye yönelik analiz ve tasarım için tavsiye edilen Larman'ın kitabının (UML and Patterns / Applying UML and Patterns) slaytları üzerinden bu konuların bir özeti yapıldı; ardından nesne yönelimli tasarımda kullanılan diyagramlara geçildi. Hoca, derste temel bilgilerin verildiğini, daha fazla ayrıntının ve özellikle tasarım kalıplarına geçişin bu kaynaklarda bulunabileceğini; projelerde de bu kaynaklardan yararlanılacağını belirtti.

Kullanılan slaytlarda alt bantta konuların sırası görülüyor: yinelemeli gereksinimler (iterative requirements), use case'ler, sistem sıralama diyagramları (sys. sequence diagrams), alan modelleri (domain models) ve işlem sözleşmeleri (operation contract) (ekrandan, 00:45:00 ve 00:55:00).

## 2. Alan Modeli (Domain Model)

### 2.1 Görsel sözlük olarak alan modeli

UML sınıf diyagramını çizmeden önce bir alan modeli (alana özgü model) geliştirilir. Bunun amacı, uygulamayla ilgili kavramların (ileride yazılım sınıflarına dönüşecek nesnelerin) neler olduğunu bir **görsel sözlük** biçiminde anlamaktır. Görsel sözlük hem alandaki kavramları hem bu kavramlar hakkında tutulacak bilgileri hem de kavramlar arasındaki ilişkileri belirten kelimeleri gösterir. Böylece bilgi sisteminde hangi nesnelerin olduğu ve bunlar arasındaki ilişkilerin ne olduğu ortaya çıkar; sonuç bir **kavramsal sınıf diyagramıdır**.

Alan modelini kurabilmek için önce use case'lerin (temel olarak) oluşturulmuş olması gerekir; çünkü kavramlar, gereksinimlerde anlatılan işlerden çıkarılır.

### 2.2 Örnek: Video mağazası kısmi alan modeli

Slayttaki kısmi alan modeli (ekrandan, 00:45:00):

| Sınıf | Özellikler |
|---|---|
| `Customer` | address, name, phoneNumber |
| `VideoStore` | address, name, phoneNumber |
| `Video` | ID |

| İlişki (ok yönüyle) | Bir uç | Diğer uç |
|---|---|---|
| `Customer` → `Rents-from` → `VideoStore` | `Customer`: * | `VideoStore`: 1 |
| `VideoStore` → `Stocks` → `Video` | `VideoStore`: 1 | `Video`: * |
| `Customer` → `Rents` → `Video` | `Customer`: 1 | `Video`: 1..* |

Okunuşu: Bir mağazanın birçok müşterisi vardır ve her müşteri bir mağazadan kiralama yapar. Mağaza envanterinde birçok video stoklar; bu ilişkiden mağazanın envanterinde hangi videoların olduğu görülür. Bir müşteri en az bir video kiralar. Mağazanın adres, ad ve telefon bilgileri tutulur. Hoca ayrıca ödeme bilgisinin (ne kadar ödendiğinin) de modele eklenebileceğini söyledi.

> **Ders sonrası not:** Hoca `Stocks` ilişkisi için mağazada "en az bir ve çok sayıda" video olduğunu söyledi. UML'de `*` çokluğu "sıfır ya da daha çok" (`0..*`) anlamına gelir; "en az bir" `1..*` ile gösterilir. Slayttaki `Rents` ilişkisinin video ucundaki `1..*` bu anlamdadır.

### 2.3 UML bağlantıları ve çokluk

UML bağlantılarında ilişki adı okun üzerinde yazılır ve okun yönü ilişkinin hangi yönde okunacağını gösterir. Çokluk (multiplicity) bire bir, bire çok, "en az bir ya da daha çok" (`1..*`), sınırlı bir aralık (hocanın örneğinde 1 ile 40 arası) ya da tam bir sayı (örneğin yalnız 5) olabilir. Bu gösterim ER diyagramında alışılandan biraz farklıdır ama mantık olarak çok farklı değildir.

> **Ek bilgi (derste anlatılmadı):** Larman'ın kitabında bu örnekler `*`, `1..*`, `1..40` ve `5` biçiminde yazılır. Aralık gösterimi `alt..üst` şeklindedir; `*` üst sınır olmadığını belirtir.

### 2.4 Analizde özellikler, tasarımda işlemler

Bir sınıf kutusunun altında işlemleri (örneğin müşterinin gerçekleştireceği işlemler) de görmek mümkündür. Ancak analizde önce özellikler verilir; işlemlerin ayrıntısı tasarımda, bütün olayla ilgili tanımlamalar yerleştiğinde verilir.

Hoca, alan modelinde bazı veri modeli kalıplarının da (analiz kalıpları) kullanılabileceğini, analiz sırasında tasarımda hangi tasarım kalıplarının kullanılabileceğinin düşünülmeye başlandığını ve veri modellemeden tasarım kalıplarına geçiş için önerilen kitaplar olduğunu söyledi.

## 3. UP Kullanım Senaryosu Modelindeki Ürünler

Hocanın "güzel bir şekil" dediği slayt, Unified Process'te (UP) hangi ürünün (artifact) hangi disiplinde üretildiğini gösterir (ekrandan, 00:50:00 ve 01:45:00):

- **İş modelleme (Business Modeling):** alan modeli (Domain Model).
- **Gereksinimler (Requirements), Use-Case Model içinde:**
  - metin olarak use case'ler (text use cases, yani use case belgeleri),
  - use case diyagramları,
  - sistem sıralama diyagramları (system sequence diagrams): aktör ile `:System` nesnesi arasında `foo(x)`, `bar(y)` gibi sistem işlemleri,
  - sistem işlem sözleşmeleri (system operation contracts): sistem işlemlerinden türetilir.
- **Tasarım (Design):** tasarım modeli (Design Model).

Slayttaki bulutta "Kısmi ürünler, her iterasyonda geliştirilir" yazıyor: her iterasyonda hangi yazılım elemanlarının eklendiği belirtilir.

Akış şöyledir: Alan modeli oluşturulduktan sonra iş modelleme çerçevesinde gereksinimler belirtilir. Gereksinimler sırasında use case belgesi, use case diyagramı ve sıralama diyagramları basit olarak çizilir. Tasarım kalıpları eklendiğinde ortaya çıkan model tasarım modelidir; sınıf diyagramının ve sıralama diyagramlarının tamamlanmış hali tasarım modelinde ortaya çıkar.

## 4. Tasarım Kalıpları ve Yeniden Kullanılabilirlik

Gereksinimler anlatılırken yazılım kalite özelliklerinden söz edilmişti: bazı özellikler kullanıcılar için, bazıları ise yazılım geliştiriciler ve yazılımı işletenler için önemlidir. Geliştirici açısından önemli özelliklerden biri **yeniden kullanılabilirliktir (reusability)**. Yeniden kullanılabilir nesne modelleri **tasarım kalıplarıdır (patterns)**. Hoca, tasarımda mutlaka tasarım kalıplarına yer verilmesi gerektiğini vurguladı.

Hoca, nesneye yönelik analiz ve tasarım üzerinde ilk çalışan üçlü olarak Booch, Jacobson ve Rumbaugh'u andı ve nesneye yönelik yaklaşımın onların çalışmalarıyla yaygınlaştığını söyledi. <!-- BELİRSİZ: altyazıda adlar "Buç, Jacobs'ın Romba" diye bozuk; bağlamdan Booch, Jacobson, Rumbaugh olarak düzeltildi. -->

> **Ders sonrası not:** Hoca tasarım kalıbı kavramının da bu üçlü tarafından ortaya atıldığını söyledi. Yazılımda tasarım kalıbı kavramı büyük olasılıkla daha çok Gamma, Helm, Johnson ve Vlissides'in (Gang of Four) 1994 tarihli "Design Patterns" kitabıyla yaygınlaşmıştır; Booch, Jacobson ve Rumbaugh ise UML'in ve nesneye yönelik yöntemlerin öncüleridir.

Buna göre nesneyle ilgili değerlendirme yapabilmek için UML sınıf diyagramlarını okuyup yazabilmek ("okuryazar olmak"), bir alan modeli yaratabilmek ve bununla ilişkili diğer yazılım elemanlarını hazırlayabilmek gerekir.

## 5. Kullanım Senaryoları (Use Case): Tanımlar

### 5.1 Genel bakış

Bu bölüm, önceki derste işlenen use case konusunun Larman'ın slaytları üzerinden tekrarıdır. Slayttaki genel bakış (ekrandan, 00:55:00):

- Use case'ler (özellikle) fonksiyonel gereksinimleri yakalamanın bir yoludur.
- Use case'ler bir sistemin kullanılmasına ilişkin hikâyelerdir.
- Hedefler: farklı use case seviyelerini tanımlamak, use case'leri popüler Cockburn formatında yazmak, öz (essential) ve somut (concrete) use case'leri karşılaştırmak, kılavuzları uygulamak, use case diyagramlarını okumak ve yazmak.

Gereksinim analizinde önce fonksiyonel, sonra fonksiyonel olmayan gereksinimler ele alınmıştı. Fonksiyonel gereksinimleri daha iyi ortaya çıkarmak için sistemde gerçekleşen işler kullanıcı hikâyeleri olarak anlaşılmaya çalışılır ve bunun için farklı use case seviyeleri oluşturulur. Veri akış diyagramlarında farklı notasyonlar olduğu gibi use case için de farklı formatlar vardır; burada Cockburn formatı kullanılır. Bu konuda Larman'ın kitabı ve Cockburn'ün etkili use case yazma kitabı tavsiye edildi.

> **Hocanın vurgusu:** Hedef, karşımıza gelen bir use case diyagramını okuyabilmek (hangi fonksiyonel gereksinimleri anlattığını anlayabilmek) ve bize bir hikâye verildiğinde onun use case diyagramını hazırlayabilmektir. Sınavlara çalışırken de buna dikkat edilmelidir; tasarıma doğru gidilen bir uygulamada size bir use case diyagramı verilmiş olabilir ya da sıfırdan bir hikâye verilmiş olabilir.

### 5.2 Use case, aktörler ve senaryo

Gayri resmî tanımla bir use case, bir aktörün bir hedefe ulaşmak için sistemi kullanmasının hikâyesidir; bu hikâyeler görsel olarak (diyagram) ve belge halinde tanımlanır. Örnek hikâye: **videoların kiralanması**.

- **Birincil aktör (primary actor):** hedefini gerçekleştirmek için sistemi kullanan aktör; bu uygulamada mağaza görevlisi.
- **Destek aktörleri (supporting actors):** sisteme hizmet veren dış ajanlar, örneğin başka sistemler. Bunların da uygulama içinde belirlenmesi gerekir.

Hikâyedeki her aktörün sistemle ilgili hedefi farklı olabilir: görevli video kiralama işlemini yapar ve aylık, günlük ya da belirli kişilere ait kiralama raporları almak ister; müşteri kendi aldığı videoları görmek ve kiralama yapmak isteyebilir.

**Senaryo (scenario):** aktörler ile sistem arasındaki bağlantıların, etkileşimlerin ve hareketlerin belirli bir sırasıdır. Burada sıra önemlidir: önce hangi işlem, aktivite ya da eylemin, sonra hangisinin gerçekleşeceği belirtilir. Senaryoya kullanım senaryosu da denir.

Daha kurallı söylersek bir use case, bir aktörün bir hedefi gerçekleştirmesine ilişkin **başarılı ve başarısız senaryoların toplamıdır**.

> **Ek bilgi (derste anlatılmadı):** Larman'ın kitabında senaryo, bir use case'in tek bir yolu olduğu için "use case örneği (use case instance)" olarak da adlandırılır. Ana başarı senaryosu bu yollardan yalnız biridir; uzantılar diğer yolları tanımlar.

### 5.3 Kısa (brief) format örneği

Slayttaki kısa format örnek (ekrandan, 01:00:00):

> **Rent Videos.** A Customer arrives with videos to rent. The Clerk enters their ID, and each video ID. The System outputs information on each. The Clerk requests the rental report. The System outputs it, which is given to the Customer with their videos.

Türkçesi: Müşteri kiralayacağı videolarla gelir. Görevli müşterinin ID'sini ve her videonun ID'sini girer (yani müşterinin önce kayıtlı olması, bir ID'sinin bulunması gerekir; her video da bir kimlik numarasıyla kayıtlıdır). Sistem her biri için bilgi verir. Görevli kiralama raporunu ister. Sistem raporu üretir ve rapor videolarla birlikte müşteriye verilir.

### 5.4 Use case'in nesneye yönelik analizdeki yeri

Nesneye yönelik analizde hedef, hangi gereksinimlerin olduğunu ve bu gereksinimlerin tasarım adımlarına nasıl girdi olarak aktarılacağını belirlemektir. UML diyagramlarına use case diyagramları ve use case belgeleriyle başlanır.

## 6. Use Case Seviyeleri ve Temel İş Süreci (EBP)

### 6.1 Ayrıntı seviyesi sorunu

Use case yazarken ne kadar ayrıntı verileceğine karar vermek gerekir. Örneğin video kiralama anlatılırken önce sistem başlatılır, sonra görevli kendini tanıtır (giriş yapar), sonra kiralama işlemi yapılır. Use case seviyelerinde iki hedef birlikte sağlanmalıdır: uzaktan bakıp büyük resmi görmek ve gerçek boyuttaki işleri görmek.

Bütün organizasyonun bütün ayrıntısını kapsayan use case'ler büyük resmin kaçırılmasına yol açar, yönetim ve karmaşıklık sorunları getirir. Bu yüzden çok fazla ayrıntı birden verilmez: önce işlevsel gereksinimin ne istediği ve hangi sınırlar içinde ne yapılması gerektiği genel ve basit olarak anlatılır; alttaki belirli bölümler için sonra bir seviye daha ayrıntı verilir.

Hoca, iş süreci anlatılırken "Bütün gün ne yapıyorsunuz?" sorusu sorulmuş gibi düşünülmesini önerdi: "Bütün gün sistemdeydim, çalışıyordum" yanıtı yetmez; hangi işlerin yapıldığı ortaya çıkarılmalıdır. Slayt küçük resimlerinde bu sorunun "Levels of Use Cases" başlıklı slaytlarda yer aldığı görülüyor (ekrandan, 01:05:00).

> **Ek bilgi (derste anlatılmadı):** Larman bu yaklaşımı "patron testi (boss test)" olarak adlandırır: patron "Bütün gün ne yaptın?" diye sorduğunda verilen yanıt (örneğin "giriş yaptım") onu memnun etmiyorsa, o adım tek başına bir EBP seviyesi use case değildir.

### 6.2 EBP kılavuzu

Slayttaki kılavuz (ekrandan, 01:05:00):

- Cockburn, Temel İş Süreci (Elementary Business Process, EBP) kılavuzunu destekler.
- Use case'lere EBP seviyesinde odaklanılmalıdır.
- EBP: "Bir kişinin bir yerde bir zamanda, bir iş olayına yanıt olarak gerçekleştirdiği, ölçülebilir iş değeri katan ve veriyi tutarlı bir durumda bırakan görev."

Hoca bunu "birim seviyesinde iş süreçleri rehberi" olarak açıkladı: görev bir işletme olayına cevap vermeli, ölçülebilir iş değeri eklemeli ve veri tutarlılığına dikkat etmelidir. Bütün yazarlar (Larman dahil) bunu belirtir; Cockburn ise özellikle adını koyarak EBP der.

Boyut kılavuzu (ekrandan, 01:10:00):

- EBP seviyesindeki bir use case genellikle tek ya da iki adımdan değil, birkaç adımdan oluşur.
- Tek bir adım değildir.

### 6.3 Aşama aşama ayrıntılandırma

Veri akış diyagramlarında aşama aşama gidildiği gibi, use case seviyelerinin ayrı adları olmasa da use case diyagramı tek adımda tamamlanmaz; olayın bütün ayrıntılarının verildiği karmaşıklığa doğru birkaç adımda ilerlenir.

Video mağazası örneğinde önce başlangıç, bağlanma (giriş), video kiralama ve müşteri takibi işleri ele alınır. Videolar bir tedarikçiden (temin edici şirket) alınıyorsa onunla ilgili işlemler de göz ardı edilmez; ancak temel işler ayrı bir use case diyagramıyla anlaşılmadan tedarikçiyle yapılan işleri hemen aynı diyagrama katmak doğru değildir. İş süreçleri basitten karmaşığa doğru adım adım gösterilir.

## 7. Use Case Diyagramları

### 7.1 Belge ve diyagram

UML use case diyagramlarını da içerir, ama use case'ler esasen **belgedir**: use case çalışması diyagram çizmek değil, ne olduğunu ve işlemlerin hangi kurallara göre gerçekleştiğini yazmaktır. Yine de diyagram da çizilir.

Sistem analizinden hatırlanacağı gibi veri akış diyagramı kat kat oluşturulur: önce bağlam (context) diyagramı, yani özet diyagram çizilir; sonra bu geliştirilerek 1. düzey ve 2. düzey ayrıntılı diyagramlar çizilir. Use case'ler için de benzer biçimde önce use case'ler adlarıyla tanımlanır ve sistemin özetini anlatan bir bağlam diyagramı oluşturulur.

Use case belgesinde daha fazla ayrıntı vardır: birincil aktör ve özellikleri, diğer ilgililer ya da ikincil aktörler, sistemin ne zaman çalışmaya başladığı ve çalışması için ön koşullar, üst seviye bir algoritma gibi sırasıyla metin olarak yazılan işlemler ve bunların alternatifleri.

### 7.2 Örnek: Video Store Information System

Slayttaki diyagram (ekrandan, 01:15:00):

- Sistem sınırı: **Video Store Information System**.
- Solda insan aktörler: **Clerk** (görevli), **Customer** (müşteri), **Administrator** (yönetici).
- Sağda dış sistem aktörü: **«actor» Credit Authorization Service** (kredi onay servisi), kutu olarak çizilmiş.
- Use case'ler: **Pay Fines**, **Rent Items**, **Manage Memberships**, **Log In**, **Manage Inventory**, **Manage Users**.
- Credit Authorization Service, Pay Fines ve Rent Items use case'lerine bağlıdır.
- Slayttaki uyarı: "Diyagram çizmeye çok zaman harcamayın. Use case çalışması metin yazmak demektir, diyagram çizmek değil."

Anlatıma göre kredi servisi, müşteri peşin para yatırmışsa ne kadar parası kaldığını, bugünkü kiralamaya yetip yetmeyeceğini ve ne kadar daha ödemesi gerektiğini kontrol eder. Görevli üyelikleri yönetir, sisteme günlük olarak giriş yapıp sistemi açar ve kiralama işlemini gerçekleştirir; kiralamanın nasıl yapılacağı onun sorumluluğundadır. Yönetici envanteri ve kullanıcıları yönetir. <!-- BELİRSİZ: karede aktörlerden use case'lere giden çizgilerin tam olarak hangi use case'lere bağlandığı seçilemiyor; görevli ve yönetici bağlantıları anlatımdan, müşteri bağlantıları kareden yaklaşık olarak çıkarıldı (Pay Fines, Rent Items, Manage Memberships). -->

### 7.3 Çizim kuralları

Hoca slayttaki yorumu şöyle aktardı: ilk olayı anlamak için diyagram çizilebilir ama çok zaman harcanmamalıdır; ilk çizimin ideal olması için uğraşılmaz, sonra düzeltilebilir. Diyagram oluşturulduktan sonra belge bütün adımlarıyla yazılır.

Bir sonraki slayttaki kurallar:

- Bilgisayar sistemi aktörü insan aktörden farklı olarak kutu şeklinde çizilir.
- Gerçek (canlı) birincil aktörler sol tarafa, sistem mekanizmaları (başka yazılımlar, uygulamalar) yani destek aktörleri sağ tarafa yazılır.

## 8. Use Case Modelleme Kılavuzları

### 8.1 Adlandırma ve kalite kontrolleri

Use case adları bir fiille başlar (örneğin "Manage Users", "Rent Items"); slayt küçük resminde CRUD işlemlerinin tek bir "Manage ..." use case'inde toplanması önerisi görülüyor (ekrandan, 01:20:00). <!-- BELİRSİZ: bu kılavuz slaytı yalnız küçük resim olarak göründü; metni tam okunamadı, hoca da adların nasıl başladığını sorup ayrıntı vermedi. --> Bütün sistemlerin bir başlangıç ve bir bitiş use case'ine sahip olduğu, bunun bilinmesi gereken bir kural olduğu söylendi.

Slayttaki kılavuz (ekrandan, 01:20:00):

- EBP seviyesindeki use case'ler tercih edilir; bunlara **kullanıcı seviyesi hedef (user-level goal)** use case'leri de denir.
- Yaygın kalite güvence kontrolleri; şunlar var mı:
  - Use case'ler: bir çeşit **Configure System**; bazen **Start Up** ve **Shut Down**.
  - Aktörler: **System Administrator**.

Hoca, iş süreçlerinin seviye seviye ve kullanıcı seviyelerine göre takip edilmesini; öngörülen sistemde konfigürasyon, başlangıç ve bitiş aşamalarının gerçekten bulunup bulunmadığının kontrol edilmesini söyledi.

### 8.2 Küçük ekiplerde çalışma

Küçük bir uygulama ve küçük bir ekiple çalışılıyorsa önce use case diyagramı çizilir ve ekip içinde üzerinde görüşülür. Örneğin 5-6 kişilik bir proje ekibinde önce çok özet bir taslak use case diyagramı çizilir, hangi işlemlerin olduğu üzerinde anlaşılır; sonra daha ayrıntılı işler katılarak diyagram bir seviye daha ayrıntılandırılır. Use case ayrıntılandıkça daha fazla sembol kullanan ve daha fazla dallanma gösteren "fully dressed" use case'ler ortaya çıkar.

### 8.3 Fonksiyonel olmayan gereksinimler

Use case'lerin hedefi, iş sürecini anlatarak fonksiyonel gereksinimleri ortaya çıkarmaktır. Hoca, fonksiyonel olmayan gereksinimlerin de use case'lerden çıkarılıp çıkarılamayacağını sordu ve yanıtladı: daha fazla ayrıntı verildiğinde fonksiyonel olmayan gereksinimlerden de ipuçları alınabilir (aşağıdaki "özel gereksinimler" bölümü buna örnektir).

## 9. Tam Ayrıntılı (Fully Dressed) Use Case Örneği

### 9.1 Başlık bilgileri ve paydaşlar

**UC1: Rent Videos** (videoların kiralanması):

- **Seviye:** kullanıcı seviyesi hedef (EBP seviyesi); iş süreçlerine kullanıcı tarafından bakıldığında onun hedefini ortaya koyan seviye.
- **Birincil aktör:** görevli (Clerk).
- **Ön koşul:** görevli tanıtılmış ve kimliği doğrulanmıştır (sistemi açabilir, güvenlik kontrolü yapılmıştır).
- **Paydaşlar ve ilgileri:**
  - Görevli: hızlı ve doğru (hatasız) giriş yapmak ister.
  - Müşteri: az zahmetle hızlı hizmet almak ister.
  - Muhasebe: işlemlerin (alınan paranın) doğru kaydedilmesini ister.
  - Pazarlama: satış yapılırken müşteri alışkanlıklarının da izlenmesini, yani müşteri analizi yapabilmeyi ister.

<!-- BELİRSİZ: başlık ve paydaş bilgilerinin bulunduğu slayt karelerde okunamadı; bu kısım anlatımdan yazıldı. -->

### 9.2 Ana başarı senaryosu ("happy path")

Slayttaki ana başarı senaryosu (Main Success Scenario, Basic Flow ya da "Happy Path") (ekrandan, 01:25:00):

1. Customer arrives at a checkout with videos or games to rent. (Müşteri kiralayacağı video ya da oyunlarla kasaya gelir.)
2. Clerk enters Customer ID. (Görevli müşteri ID'sini girer.)
3. Clerk enters rental identifier. (Görevli kiralama tanımlayıcısını girer.)
4. System records rental line item and presents item description. (Sistem kiralama kalemini kaydeder ve kalem açıklamasını gösterir.) Görevli bitti diyene kadar 3-4. adımları tekrarlar.
5. System displays total. (Sistem toplamı gösterir.)
6. Customer pays. System handles payment. (Müşteri öder; sistem ödemeyi işler.)
7. Clerk requests rental report. (Görevli kiralama raporunu ister.)
8. System outputs it. Clerk gives it to Customer. (Sistem raporu üretir; görevli raporu müşteriye verir.)
9. Customer leaves with rentals and report. (Müşteri kiraladıkları ve raporla ayrılır.)

Hoca 3-4. adımların tekrarını şöyle açıkladı: müşteri iki ya da üç video alacaksa 3. ve 4. adımlar o kadar kez tekrarlanır. "Sistem ödemeyi işler" ise ödemenin muhasebe servisine gelir olarak gönderilmesi anlamına gelir.

### 9.3 Uzantılar (alternatif akışlar)

Her şey yolunda giderse işlem yukarıdaki gibi olur; gitmezse alternatif akışlar (uzantılar, extensions) devreye girer. Anlatılan örnekler:

- Sistem herhangi bir anda çökerse: görevli sistemi yeniden başlatır, giriş yapar ve kurtarma (recovery) ister. Hoca burada yedekleme ve kurtarma (backup/recovery) kavramına gönderme yaptı.
- Müşteri yeni bir müşteriyse: üyelik (kayıt) işlemi gerçekleştirilir.
- Müşteri ID'si bulunamazsa, yani girişte hata varsa: giriş düzeltilir.

Uzantılar, mutlu yolda gitmeyen durumlarda ne olabileceğini ve buna karşılık ne yapılacağını gösterir.

<!-- BELİRSİZ: uzantıların slayttaki tam metni karelerde okunamadı; anlatımdan yazıldı. -->

### 9.4 Özel gereksinimler ve diğer bölümler

- **Özel gereksinimler:** örneğin mesajların ve kiralama raporlarının hangi dilde geleceği.
- **Teknoloji ve veri çeşitlemeleri:** ID'ler barkodla okunabilir ya da klavyeden girilebilir; barkod okuyucu olup olmadığı, verinin farklı biçimlerde girilmesi.
- **Sıklık:** bu işlemin ne sıklıkla yapılacağı.
- **Açık konular:** kapatılmış ya da henüz kapatılmamış konuların takibi.

Hocanın değindiği bir kural da use case'lerde basitliğin korunmasıdır.

## 10. Öz ve Somut Use Case'ler

Slayttaki tanım (ekrandan, 01:30:00):

- "Kullanıcı arayüzünü dışarıda tut" ("Keep the UI out").
- **Öz (essential)** use case'ler arayüzün ayrıntılarını erteler ve aktörlerin **niyetlerine** odaklanır.
- Öz: "Görevli müşteri ID'sini girer." (Clerk enters Customer ID.)
- Somut / daha kötü (concrete/worse): "Görevli müşterinin kimlik kartını alır ve barkodu lazer okuyucuyla okur."

<!-- BELİRSİZ: bu slayt teneffüs sırasında ekranda kalmıştır; hoca slaytı ayrıca anlatmadı, yalnız teneffüsten önce "basitliği koru" kuralına ve barkod/klavye girişine değindi. -->

## 11. Use Case Modellemenin Toparlanması

Teneffüsten sonra use case bölümü şu noktalarla tamamlandı:

- Use case diyagramına basit bakarak adımlar tamamlanır ve aktörün yaptığı işlemler onun bakış açısıyla görülmeye çalışılır.
- İşlemlerin sırası doğru tanımlanmalıdır. Bu, gereksinim analizinin bir özelliğidir: hangi olayın hangisinden önce olduğu iyi takip edilmeli ve tasarıma bu bilgi aktarılmalıdır.
- Use case'ler birer hikâyedir: her kullanıcının kendi yaptığı işi anlatmasıdır, yani sistemin farklı bakış açılarıyla anlatılması. Bu, gereksinimlerin daha çok insan tarafından anlaşılmasını sağlar.
- Birbiriyle ilişkili gereksinimler use case'lerde verilir; her iterasyonda belgeler ve diyagramlar biraz daha ayrıntılı ve daha fazla yazılım elemanı içerecek biçimde geliştirilir. Bu sırada sıralama diyagramlarına da hazırlık yapılır.
- UP ürünleri şeklinde, gereksinimler içinde metin use case'ler ve use case diyagramları daire içine alınarak bu bölümün kapsamı gösterildi (ekrandan, 01:45:00).
- Hedefler yeniden sayıldı: farklı use case seviyelerini tanımlamak, use case'leri istenen formatta yazmak, use case'ler arasında çakışma varsa görmek ve diyagramları da belgeleri de use case hazırlama rehberlerine uygun hazırlamak.

## 12. Nesne Yönelimli Tasarım Diyagramları

Bu bölümde nesne yönelimli tasarımda kullanılan diyagramların hepsi gözden geçirildi.

### 12.1 Sıralama şeması (sequence diagram)

Sıralama şemaları nesneler arasındaki iş birliğini gösterir. İş birliği (collaboration) diyagramları da bu işi görebilir, ama sıralama diyagramlarında nesnelerin etkinleştirildiği sıra da görülür. Hoca bu diyagramların ayrıntısının "Nesneye Dayalı Kavramlar" dersinde işlendiğini söyledi ve ayrıntıya girmedi.

Slayttaki "Sıralama Şemaları Ayrıntıları" (ekrandan, 01:50:00): iki nesne `nesne1: Sınıf1` ve `nesne2: Sınıf2` yan yana çizilir; `nesne1`'den `nesne2`'ye `[koşul] değişken := birMetot(param1: Tip, ... )` mesajı gönderilir ve kesikli okla geri dönülür. Gösterimler:

| Gösterim | Anlamı |
|---|---|
| Düz ok | Mesaj (metot çağırma) |
| Kesikli ok | Geri dönüş (ihmal edilebilir) |
| `[koşul]` etiketli ok | Koşullu mesaj (if) |
| `* [koşul]` etiketli ok | Döngülü mesajlar (for, while vb.) |
| `new` etiketli ok | Nesne oluşturma |
| Etkinlik çubuğunun kendi üzerine dönen oku | Nesnenin kendi metodunu çağırması |

Slaytta bu yansının yalnız bir hatırlatma olduğu, gerekli altyapının "Nesneye Dayalı Kavramlar" dersinde kazanıldığı yazıyor.

### 12.2 Etkinlik şeması (activity diagram)

Etkinlik (aktivite) diyagramlarına analiz aşamasında başlanır, tasarım aşamasında tamamlanır. Bir bölümde hangi işlemlerin yürüdüğünü takip etmek için kullanılır. Kullanılan öğeler: denetim akışı, etkinlik başlangıcı, eylem, karar verme, eş güdüm. Diyagram sinyal alma işaretiyle başlayabilir. Eş güdümde, farklı iki yerdeki etkinliklerin hangi noktada birleştiği ve diğer akışların nerede beklediği **fork** (çatallanma) ve **join** (birleşme) gösterimleriyle belirtilir.

Etkinlik şemaları, iki ayrı yerde yürüyen ve birden fazla aktör arasında bilgi akışı olan süreçlerin gösterilmesinde daha çok kullanılır; hoca örnek olarak havaalanındaki yer hizmetleri ve müşteri hizmetlerini verdi.

<!-- BELİRSİZ: etkinlik şeması ve havaalanı örneği slaytı karelerde yok; bu kısım anlatımdan yazıldı. -->

### 12.3 Durum şeması (state diagram)

Durum şemasında bir nesnenin hangi durumda olduğu ve hangi durumdan hangi duruma ne zaman (hangi olayla) geçtiği gösterilir. Başlangıç ve bitiş işaretleri vardır; durum geçişleri oklarla gösterilir ve okların üzerinde geçişi tetikleyen olay yazılır. Geçişlerdeki işlem daha ayrıntılı, daha teknik olarak da yazılabilir.

Hocanın anlattığı ilk örnek bir uçağın durumlarıdır: sipariş aşamasında, teslim edildi, kullanıma hazır, bakımda, kullanım dışı ve bitiş işareti. Geçişlerde teslim tarihinin belirtilmesi, kayıttan silinmesi gibi işlemler gösterilebilir. <!-- BELİRSİZ: uçak durum şeması slaytı karelerde yok; durum adları ve geçişlerin yönü anlatımdan yazıldı. -->

İkinci örnek, tasarım modelinden **NextGenPOS kasası** durum şemasıdır (ekrandan, 01:55:00). Geçişlerin olay etiketleri `«M»` ön ekiyle yazılmıştır.

| Kaynak durum | Olay | Hedef durum |
|---|---|---|
| Başlangıç | Güç açıldı / | Boşta bekleme |
| Boşta bekleme | «M» Satış başlatıldı / | Satış kaydetme |
| Boşta bekleme | «M» Kapatma düğmesine basıldı / | Bitiş |
| Satış kaydetme | «M» Barkod girildi / | Satış kaydetme (kendine dönüş) |
| Satış kaydetme | «M» Ürün iptal düğmesine basıldı / | Satıştan tek ürün silme |
| Satıştan tek ürün silme | «M» Barkod girildi / | Satış kaydetme |
| Satış kaydetme | «M» Alınacak ürün kalmadı / | Ödeme bekleme |
| Ödeme bekleme | «M» Ödeme alındı / | Makbuz verme |
| Makbuz verme | (etiketsiz) | Boşta bekleme |

<!-- BELİRSİZ: "Satış kaydetme" ile "Satıştan tek ürün silme" arasındaki iki okun hangi etikete ait olduğu karede tam seçilemiyor; tablo okların yerleşimine göre yazıldı. -->

Hocanın anlatımıyla: güç açılınca kasa boşta bekler; satış başlayınca satış kaydetme durumuna geçer; satış sırasında bir ürün satıştan çıkarılabilir; bütün ürünler bitince ödeme bekleme, ödeme alınınca makbuz verme durumuna geçilir ve kasa başka bir müşteri için yeniden boşta bekler. Bu durumların hepsi ya da bir kısmı gerçekleşir. Durum şeması tasarım sırasında hazırlanması gereken diyagramlardan biridir.

### 12.4 Tasarım modelinin tamamlanması

Tasarım modelini tamamlamak için sınıf diyagramı da tamamlanmalıdır: örneğin satış kalemleri gibi bütün sınıflar, hangi özelliklere ve hangi işlemlere sahip oldukları gösterilir. Yazılım kalitesi ve ölçütleri sonraki derslerde ele alınacaktır.

> **Hocanın vurgusu:** Tasarımla ilgili modellemede etkinlik diyagramları, durum diyagramları, sınıf diyagramları ve sıralama diyagramları tasarım sırasında tamamlanmış olmalıdır.

## Dersin Toparlaması

Bu derste nesneye yönelik analizden tasarıma geçiş, Larman'ın UP yaklaşımı üzerinden özetlendi. Önce alan modeli bir görsel sözlük olarak tanıtıldı ve video mağazası örneğinde kavramlar, özellikler ve çokluklu ilişkiler gösterildi. Ardından gereksinimlerin use case modelinde (metin use case'ler, use case diyagramları, sistem sıralama diyagramları, işlem sözleşmeleri) nasıl toplandığı, use case ve senaryo tanımları, EBP seviyesi, use case diyagramı çizim kuralları, kalite kontrolleri ve tam ayrıntılı Rent Videos örneği (paydaşlar, ana başarı senaryosu, uzantılar, özel gereksinimler) işlendi; öz use case'lerin arayüzden bağımsız olması gerektiği görüldü.

Dersin son bölümünde tasarımda tamamlanması gereken diyagramlar gözden geçirildi: nesneler arası mesajlaşmayı gösteren sıralama şeması, akışları ve eş güdümü gösteren etkinlik şeması, NextGenPOS kasası örneğiyle durum şeması ve tamamlanmış sınıf diyagramı. Yazılım kalitesi ve ölçütleri sonraki derslere bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
