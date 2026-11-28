# Ders 4 Genişletilmiş Notu: Gereksinim Mühendisliği Adımları, IEEE 830 SRS Yapısı ve Yazılım Kalite Özellikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Gereksinim Mühendisliğine Giriş
- 2. Başlangıç (Inception)
- 3. Bilgi Toplama (Elicitation)
- 4. İşleme (Elaboration)
- 5. Pazarlık (Negotiation)
- 6. Tanımlama (Specification)
- 7. Doğrulama (Validation)
- 8. Yönetim (Management) ve İzlenebilirlik Tablosu
- 9. Adımların Toplu Tekrarı ve Dış Kaynak Kullanımı Sorusu
- 10. IEEE 830 Yazılım Gereksinim Belirtimi (SRS) Şablonu
- 11. Fonksiyonel ve Fonksiyonel Olmayan Gereksinimler
- 12. Örnek SRS: Web Accessible Alumni Database
- 13. Yazılım Kalite Özellikleri ve McCall Kalite Modeli
- 14. SRS Standartları, Artefact Kavramı ve Genel Tekrar
- Örnek Sorular
- Dersin Toparlaması

## 1. Gereksinim Mühendisliğine Giriş

Bu dersin konusu gereksinim mühendisliği (requirements engineering), yani gereksinim analizi kapsamında yapılan işlerdir. Önceki iki haftada yazılım geliştirme süreç modelleri, klasik ve çevik yaklaşımlar (XP ve Scrum) ele alınmıştı; bu hafta doğrudan gereksinim analizinin alt adımlarına geçilir. Sistem analizi dersinde analiz aşaması üç adımla anlatılmıştı: bilgi toplama, modelleme ve gereksinim raporunun oluşturulması. Gereksinim mühendisliğinde bu üç temel adım daha ayrıntılı adımlara bölünür ve yeni adımlar eklenir. Adımlar anlatıldıktan sonra bir SRS (Software Requirements Specification) örneği incelenir.

Slayttaki adımlar şunlardır (ekrandan, 00:05:00):

- Başlangıç (Inception)
- Bilgi Toplama (Elicitation)
- İşleme (Elaboration)
- Pazarlık (Negotiation)
- Tanımlama (Specification)
- Doğrulama (Validation)
- Yönetim (Management)

Aynı slayttaki iki ilke de önemlidir:

- Gereksinim mühendisliği adımları, gerçeklenecek yazılımın doğasına ve kullanılan sürece göre düzenlenmelidir.
- Gereksinim mühendisliği adımları süresince yazılım ekibi ve müşteri birlikte çalışmalıdır. Müşterinin bir ekibinin, yazılım geliştirme sürecinin mümkün olduğunca çok adımının bir parçası olması yararlıdır.

Hoca, yönetimin aslında yeni bir adım olmadığını, diğer bütün adımların doğru yönetilmesi anlamına geldiğini belirtir. Tanımlama adımında SRS belgesi hazırlanır, doğrulama adımında ise bu raporun doğru olup olmadığı denetlenir. Müşterinin ekibin bir parçası olması çok önemlidir, çünkü analiz aşamasında yapılan iş problemi bütün ayrıntılarıyla öğrenmektir.

## 2. Başlangıç (Inception)

Başlangıç, yazılım projesinin başlatılıp başlatılmayacağına karar verilen adımdır. Yeni bir projeye başlamanın tipik nedenleri şunlardır:

- Yeni bir iş gereksinimi ortaya çıkması ya da mevcut iş süreçlerinde güçlükle karşılaşılması; üst düzey karar vericilerin bir gereksinim görmesi.
- Bir yazılım evi yeni bir ürün geliştirecekse yeni bir pazarın ya da hizmetin farkına varılması; şirketin üst düzey karar vericileri ve teknik ekibinin birlikte böyle bir karar alması.
- Yeni bir müşteri bulunması ve bu müşterinin istediği işin genel olarak başkalarının da ihtiyacı olduğunun düşünülmesi.

Başlangıç aşamasında paydaşlar belirlenmelidir. **Geliştirilecek sistemden doğrudan ya da dolaylı olarak faydalanabilecek herkes sistemin paydaşıdır.** Her paydaş sisteme farklı bir açıdan bakar ve projenin başarısı ya da başarısızlığı farklı paydaşları farklı biçimlerde etkiler. Bu yüzden kullanıcılara ve paydaşlara soru sorarken onların bakış açıları, onları etkileyecek nedenler ve bunların sonuçları üzerinde durulmalıdır.

Hoca bunu basit bir işletme örneğiyle açıklar: **fatura hazırlama** işi. Bu işte muhasebe tarafı, satın alma tarafı, kasada bulunan kişi ve alışveriş yapan kişi birer paydaştır. Her biri olayı kendi bakış açısıyla anlatacağı için olay anlatılırken hem satın almadan hem muhasebeden birinin bulunması gerekir.

Tekrar bölümünde hoca bu adımı proje planlamayla da ilişkilendirir: gereksinim analizine gelinene kadar proje planlama aşamasında sistemin neden geliştirildiği zaten sorgulanmıştır. Gereksinim analizinin başında bu problem tanımı iş süreçleri açısından yeniden ele alınır; temel ihtiyacın farkındalığı yaratılır, farklı kullanıcı tipleri ve bunların sisteme hangi açıdan baktığı, hangi işte devreye girdikleri belirlenir.

## 3. Bilgi Toplama (Elicitation)

Slayttaki genel ilkeler şunlardır (ekrandan, 00:10:00):

- Gereksinimler hakkında ayrıntılı bilgiler, tüm paydaşların etkin katılımı ile elde edilmelidir.
- Tüm paydaşların katıldığı toplantılar yapılmalıdır.
- Toplantılara hazırlık ve katılım kuralları belirlenmelidir.
- Gündem belirlenmelidir: önemli konuları atlamayacak kadar sıkı, yaratıcılığı önlemeyecek kadar açık olmalıdır.
- Düzeni sağlayacak ve tıkanıklıkları çözecek bir oturum başkanı seçilir.

Fatura örneğine dönülürse, fatura hazırlayan bir yazılım için muhasebe tarafında faturanın gelire nasıl aktarılacağı, satın alma tarafında satın alınan birimlerin faturaya nasıl aktarılacağı o taraftan birinin anlatımıyla öğrenilmelidir. Önce her paydaşla tek tek görüşülerek yaptığı iş anlaşılabilir, sonra hepsinin katıldığı ortak toplantı yapılır. Yerinde inceleme sırasında da sorular sorulabilir; tıkanıklıkları çözmek için ortak toplantılardan yararlanılır.

Sistem analizi dersinden hatırlanan bilgi toplama yolları şunlardır: kişilerle tek tek görüşme (interview), yerinde inceleme, benzer uygulamaların incelenmesi, yaygın bir kullanıcı ağı varsa anket düzenleme ve kurum söz konusuysa kurumun işleyişinin (hangi görevi kimin yaptığının) incelenmesi. Hoca bu noktada bir öğrenciye bilgi toplama yollarını sorar (bkz. Örnek Sorular). Yerinde inceleme için verilen örnek: depo için bir uygulama yapılıyorsa depoya gidip işin orada nasıl yapıldığını görmek; böylece işi gerçekten yapanla birebir çalışarak gereksinimler anlaşılır.

## 4. İşleme (Elaboration)

Slayttaki tanım şöyledir (ekrandan, 00:20:00):

- Bilgi toplama aşamasında toplanan "ham" bilgilerin "işlenmesi".
- Son kullanıcının ve diğer paydaşların yazılımla nasıl etkileşimde bulunacağının belirlenmesi ve ayrıntılandırılmasını amaçlar.
- Etkileşimler, kullanım senaryoları ile gösterilir (ileride anlatılacak).
- İşleme, kimi bilgilerin genişletilmesi, kimi bilgilerin özetlenmesi şeklinde gerçekleşir.
- Gereksinimlerin sınıflandırılması:
  - Normal gereksinimler.
  - Beklenen gereksinimler: Çok temel gereksinimleri kullanıcı belirtmeyebilir. Bunların da elde edilmesi gereklidir.
  - Heveslendirici gereksinimler: Müşteri beklentilerinin ötesinde ve varlığında müşteriyi sevindirecek özellikler.

Hoca bu adımı modelleme olarak da adlandırır. Sistemin kullanıcılarının hangi işlemleri yaptığı ve aralarında nasıl bir ilişki olduğu ortaya çıkarılır; bu kavramlara nesneye yönelik analiz ve tasarımda dönülecektir. Modelleme sırasında kullanım senaryolarını hazırlayacak biçimde çalışılır ve bir model oluşturulur. Oluşturulan modelde her kullanıcının sistemle ilişkisi ve yaptığı işler görünür hale gelir. Böylece gereksinimler net olarak ortaya çıkar: böyle bir sistemden standart olarak beklenenler, müşteriyi heveslendirecek olanlar ve etkileşimler belirlenmiş olur. Kullanım senaryosu yerine veri akış diyagramı gibi başka bir model de oluşturulabilir.

Hoca burada analiz ile tasarım arasındaki sınırı da hatırlatır: tasarımda bu gereksinimleri sağlamak için nasıl bir yazılım kurulacağı (yazılımın yapısı) ele alınır; gereksinim analizinde ise böyle bir uygulamada hangi işlemlerin yapılması gerektiği üzerinde durulur.

## 5. Pazarlık (Negotiation)

Slayttaki maddeler şunlardır (ekrandan, 00:25:00):

- Müşteriler sınırlı insan, zaman ve bütçe kaynakları çerçevesinde karşılanamayacak aşırı isteklerde bulunabilir.
- Paydaşlar gereksinimleri farklı önem düzeylerinde görebilir.
- Farklı paydaşların gereksinimleri birbiri ile çelişebilir.
- Pazarlık sonucunda tüm paydaşların razı olacağı bir gereksinimler listesi elde edilir.

Müşteri tektir, ama müşteri grubunun altında farklı kullanıcılar vardır. Kullanıcı tarafı ve müşteriyi temsil eden taraf aşırı isteklerde bulunabilir. Bazen teknik olarak mümkün olan bir istek bile insan, zaman ve bütçe kaynakları çerçevesinde karşılanamayabilir. Geliştiriciler olarak ne yapılabileceği belirlenmeli ve bu aşırı istekler ayıklanmalıdır.

Hoca pazarlığın iki temel ihtiyaç için yapıldığını özetler:

- **Müşteri ile geliştirici arasındaki pazarlık:** Müşterinin istekleri, geliştirici ekibin sınırlı kaynaklarıyla karşılanamayacak düzeydeyse orta yol bulunur. Sonuçta net bir "yapılabilecekler listesi" çıkar. Sistem analistleri bu aşamada destek verir.
- **Paydaşlar arasındaki pazarlık:** Fatura örneğinde muhasebe, satın alma ve stok tarafı olayı kendi bakış açısıyla, farklı biçimlerde anlatır; birbiriyle çelişen tanımlamalar olabilir ve herkes kendi yaptığı işi ön plana çıkarır. Gereksinim analizinin asıl hedefi geliştirilecek sistemin ne yaptığını anlamak olduğu için anlatımlar sadeleştirilmeli ve süreç dışarıdan, tarafsız bir gözle anlaşılmalıdır.

Hoca, pazarlığın sistem analizi dersinde ayrıca ele alınmayan bir adım olduğunu belirtir.

## 6. Tanımlama (Specification)

Bilgi toplandıktan, modellendikten ve yapılamayacaklar çıkarıldıktan sonra gereksinimler kağıda dökülür. Slayttaki maddeler şunlardır (ekrandan, 02:30:00):

- Gereksinimler tanımlama aşamasında, pazarlık sonucu üzerinde uzlaşılan haliyle kağıda dökülür.
- Tanımlama araçları:
  - Konuşma dili ile yazılmış belgeler
  - Kullanıcı senaryoları: Görülecek
  - Kullanım şemaları: Görülecek
  - Formel modeller (Matematiksel gösterim, işlenilmeyecek)
  - Bir ön ürün
- Birden fazla tanımlama aracı birlikte kullanılabilir.

Konuşma diliyle yazılmış belge, örneğin fonksiyonel ve fonksiyonel olmayan gereksinimlerin bir liste halinde verilmesidir. Konuşma dilinde nasıl yazılacağı SRS bölümünde ele alınır. Hoca bu derste tanımlama için iki ek bilgi verileceğini söyler: SRS belgesinin formatı ve yapısı ile kalite özelliklerinin hangi tür gereksinimlerde kullanılabileceği.

## 7. Doğrulama (Validation)

Slayttaki maddeler şunlardır (ekrandan, 00:30:00):

- Tanımlanmış gereksinimlerin tutarsızlıklara karşı sağlaması yapılır.
  - Gereksinimler açıkça ve yoruma yer bırakmayacak şekilde tanımlanmış mı?
  - Birbiri ile çelişen gereksinimler var mı?
  - Gereksinimlerde hatalar ve eksikler var mı?
  - Eksik gereksinimler var mı?
  - Gerçekçi olmayan gereksinimler var mı?
  - ...
- Doğrulama yapma için önerilen temel yol teknik değerlendirmedir (Formal technical review, sınama teknikleri arasında anlatılacak).

Gereksinimler konuşma diliyle anlatılıyorsa her cümle bir gereksinimi anlatacak biçimde basit cümleler kullanılır. Hoca iki noktayı vurgular: teknik değerlendirmede gereksinimi anlatan kişiler değil, yapılan iş yani gereksinimlerin kendisi değerlendirilir; ve değerlendirme bir özet geçiş biçiminde değil, raporun bütün gereksinimleri bu maddeler açısından tek tek gözden geçirilerek yapılır.

## 8. Yönetim (Management) ve İzlenebilirlik Tablosu

Yazılım geliştirme süreci içinde gereksinimlerde değişiklik olabilir:

- Yeni gereksinimler eklenebilir.
- Mevcut gereksinimlerden bazıları geçerliliğini yitirebilir.
- Gereksinimlerin önem sırası değişebilir.
- Bazı hatalı tahminler nedeniyle bazı gereksinimlerden vazgeçilebilir.

Ne tür gereksinimlerde ne tür değişikliklerin, nasıl ve hangi şartlarda yapılabileceği belirlenmelidir. Yönetim adımının iki hedefi vardır:

- Gereksinim mühendisliği çalışmaları içinde başlangıç, bilgi toplama, işleme, pazarlık, tanımlama ve doğrulama adımlarının doğru yürütülmesini sağlamak.
- Bu çalışma sonunda hazırlanan SRS belgesinin bütün yazılım geliştirme süreci boyunca yönetilebilmesini sağlamak: gerekirse yeni gereksinim eklemek, geçerliliğini yitiren gereksinimi çıkarmak, önem sırasını güncellemek.

Bu değişikliklerin nasıl yapılacağı resmi bir sözleşme haline getirilmelidir. SRS belgesi geliştirici ile müşteri arasında bir **şartname** niteliğindedir. Teslimde kullanıcı gereksinim analizindeki isteklerinin karşılanmadığını, geliştirici karşılandığını söylediğinde elde yalnız gereksinim belgesi olur; her iki taraf da bu belge üzerinde anlaşmıştır. Bu yüzden sonradan yapılacak değişikliklerin nasıl yapılacağı da bu aşamada belirlenmelidir.

Slaytta yönetimin devamı şöyle verilir (ekrandan, 00:35:00):

- Yazılım geliştirme süreci içerisinde gereksinimlerin gerçeklenmesinin (ve varsa gereksinimlerdeki değişikliklerin) izlenmesi gerekir.
- İzleme tablolar aracılığı ile yapılır:
  - İzlenebilirlik tabloları (Traceability table).

Slayttaki örnek tablo:

|     | B1 | B2 | B3 | ... |
|-----|----|----|----|-----|
| G1  | X  |    | X  |     |
| G2  |    | X  |    |     |
| G3  | X  |    |    |     |
| ... |    |    |    |     |

- G1, G2, ...: Gereksinimler
- B1, B2, ...: Sisteme çeşitli bakış açıları (Modüller, Paketler, Sınıflar vb.)

Tablo, hangi gereksinimin yazılımın hangi modülünde, hangi paketinde, hangi sınıfında karşılandığını gösterir. Böylece süreç boyunca gereksinimlerin ne kadar karşılandığı ve değişiklik olduysa nerede olduğu takip edilir. Örneğin tabloda G1 hem B1 hem B3'te, G2 B2'de, G3 B1'de karşılanmaktadır.

## 9. Adımların Toplu Tekrarı ve Dış Kaynak Kullanımı Sorusu

Hoca ilk bölümün sonunda bütün adımları yeniden özetler: başlangıçta projenin hangi temel ihtiyaç için yapıldığının farkındalığı yaratılır ve paydaşlar belirlenir; bilgi toplamada her paydaşla görüşülür ve ortak toplantılar yapılır; modellemede ham bilgiler işlenip kullanım senaryoları hazırlanır ve bütün gereksinimler ortaya çıkarılır; pazarlıkta müşteriler ile geliştiriciler ve farklı müşteri paydaşları arasında doğru yol bulunur; tanımlamada SRS belgesi oluşturulur (konuşma dili, matematiksel modeller, prototip); doğrulamada tutarsızlık, açıklık, çelişki, hata, eksik ve gerçekçilik denetlenir; yönetimde değişikliklerin nasıl ele alınacağı belirlenir ve izlenebilirlik tablosuyla takip edilir.

**Soru:** Bir firma uygulamayı dışarıdaki bir yazılım firmasına geliştirtiyorsa (outsource), gereksinim mühendisliğinin yönetimi kimde olur? Geliştirici firmada mı?

**Cevap:** Önce işin hangi bölümünün dışarıya verildiğine bakmak gerekir. Hoca, analiz ve tasarımın danışman bir kuruma, yazılım geliştirmenin başka firmalara verildiği çok taraflı bir proje örneği verir: bu durumda analiz ve tasarım raporlarından danışman kurum sorumludur, ama analiz için gerekli bilgilendirmeyi kurumun kendi çalışanları yapar ve doğru kullanıcıların seçilmesinden kurum yönetimi sorumludur. Sorumluluklar anlaşmaya göre değişebilir ve şartnamede açıkça yazılmalıdır. İşi anlatacak olanlar hem gereksinimleri doğru anlatmaktan hem de sonradan testleri yapmaktan sorumludur.

**Soru:** İki taraflı bir yapıda, yani bir firma kendi kullanımı için yazılımı dışarıdaki bir yazılım evine geliştirtiyorsa yönetim kimde olur? Bu, pazarlıktaki tarafsızlığı etkilemez mi?

**Cevap:** Bu anlaşmalarda iki tarafın sorumlulukları ayrı ayrı yazılmalıdır. Analiz ve tasarımın, yani gereksinim analizinin doğru yapılması geliştiren firmanın görevidir; işin anlatımı için seçilen paydaşların denetlenmesi ve çalışmalara katılması ise yazılımı geliştirten firmanın sorumluluğundadır.

## 10. IEEE 830 Yazılım Gereksinim Belirtimi (SRS) Şablonu

İkinci bölümde hoca IEEE'nin yazılım gereksinim belgesi standardını (IEEE 830) bir PDF şablonu üzerinden açar. Belgenin başında hangi projenin hangi sürümü olduğu, kim tarafından yazıldığı ve revizyon geçmişi bulunur. Hoca standardın uzun süredir kullanıldığını, arada ufak değişiklikler olsa da temelinin değişmediğini söyler.

> **Ders sonrası not:** Hoca standardın "99'dan beri" kullanıldığını söyledi; slaytta standardın adı IEEE 830-1998 olarak geçer (ekrandan, 02:20:00).

Şablonun içindekiler listesi şöyledir (ekrandan, 01:05:00 ve 01:10:00):

```text
1. Introduction
   1.1 Purpose
   1.2 Document Conventions
   1.3 Intended Audience and Reading Suggestions
   1.4 Product Scope
   1.5 References
2. Overall Description
   2.1 Product Perspective
   2.2 Product Functions
   2.3 User Classes and Characteristics
   2.4 Operating Environment
   2.5 Design and Implementation Constraints
   2.6 User Documentation
   2.7 Assumptions and Dependencies
3. External Interface Requirements
   3.1 User Interfaces
   3.2 Hardware Interfaces
   3.3 Software Interfaces
   3.4 Communications Interfaces
4. System Features
   4.1 System Feature 1
   4.2 System Feature 2 (and so on)
5. Other Nonfunctional Requirements
   5.1 Performance Requirements
   5.2 Safety Requirements
   5.3 Security Requirements
   5.4 Software Quality Attributes
   5.5 Business Rules
6. Other Requirements
```

### 10.1 Bölüm 1 ve 2: Genel tanım

Giriş bölümünde belgenin amacı, nasıl okunacağı, kimlerin okuması gerektiği (test uzmanları, kullanıcılar, proje yöneticileri), ürünün alanı (örneğin muhasebe programı mı, satın alma programı mı; hangi amaçla geliştirildiği) ve SRS hazırlanırken kullanılan referanslar verilir.

Genel tanım bölümünde ürün daha ayrıntılı anlatılır. Şablondaki açıklamalardan bazıları (ekrandan, 01:25:00):

- **2.1 Product Perspective:** Ürünün bir ürün ailesinin devamı mı, mevcut bir sistemin yerine mi geçtiği, yoksa yeni ve kendi başına bir ürün mü olduğu belirtilir. SRS daha büyük bir sistemin bileşenini tanımlıyorsa büyük sistemin gereksinimleri bu yazılımın işlevleriyle ilişkilendirilir ve aradaki arayüzler belirtilir; ana bileşenleri, alt sistem bağlantılarını ve dış arayüzleri gösteren basit bir diyagram yararlı olabilir.
- **2.2 Product Functions:** Ürünün yapması ya da kullanıcıya yaptırması gereken ana fonksiyonlar özetlenir. Ayrıntılar sonraki bölümde verileceği için burada üst düzey bir özet (örneğin madde listesi) yeterlidir. Fonksiyonlar SRS'in her okuyucusunun anlayacağı biçimde düzenlenir; ilişkili gereksinim gruplarını gösteren üst düzey bir veri akış diyagramı ya da nesne sınıf diyagramı çoğu zaman etkilidir.
- **2.3 User Classes and Characteristics:** Ürünü kullanması beklenen kullanıcı sınıfları belirlenir. Sınıflar kullanım sıklığına, kullanılan fonksiyon alt kümesine, teknik uzmanlığa, güvenlik ya da yetki düzeyine, eğitim düzeyine veya deneyime göre ayrılabilir. Bazı gereksinimler yalnız belirli kullanıcı sınıflarına ait olabilir; en önemli kullanıcı sınıfları ötekilerden ayırt edilir.

İşletim ortamı (ürünün nasıl bir ortamda çalışacağı), tasarım ve gerçekleme kısıtları (geliştiricilere konan kısıtlar, uyulacak standartlar) ve kullanıcı belgelerinin verilip verilmeyeceği de bu bölümdedir. **Kabuller** de belirtilir; örneğin geliştirmenin belirli bir ortamda yapılacağı ya da işletim sistemi olarak belirli bir ortamın seçileceği kabul edilebilir. Hoca, yanlış ya da hatalı bir kabulün sonradan değişmesi durumunda projeyi etkileyebileceğini vurgular. Projeye ilişkin bağımlılıklar da tanımlanmalıdır.

### 10.2 Bölüm 3: Dış arayüz gereksinimleri

Kullanıcı arayüzleri (ekran yapıları, hata mesajları), donanım arayüzleri, yazılım arayüzleri (belirli yazılım bileşenleri, veri tabanı, işletim sistemi gibi yapılar) ve iletişim arayüzleri bu bölümde tanımlanır.

### 10.3 Bölüm 4: Sistem özellikleri

Hoca asıl önemli bölümlerin 4 ve 5 olduğunu söyler. Bölüm 4 "System Features" sistemin özellikleridir, yani fonksiyonel gereksinimler burada yer alır. Her sistem özelliği bir ya da birkaç kelimelik bir adla verilir; özelliğin açıklaması ve önceliği (yüksek, orta, düşük) belirtilebilir. Ardından bu özelliği sağlamak için gereken fonksiyonel gereksinimler Requirement 1, Requirement 2 diye sıralanır. Şablondaki alt başlıklar şöyledir (ekrandan, 01:30:00):

- **4.1.2 Stimulus/Response Sequences:** Bu özellikte tanımlanan davranışı tetikleyen kullanıcı eylemleri ile sistem yanıtlarının sırası listelenir. Bunlar use case'lerle ilişkili diyalog öğelerine karşılık gelir.
- **4.1.3 Functional Requirements:** Bu özellikle ilişkili ayrıntılı fonksiyonel gereksinimler maddelenir. Bunlar, kullanıcının özelliğin sunduğu hizmetleri alabilmesi ya da use case'i yürütebilmesi için yazılımda bulunması gereken yeteneklerdir. Ürünün beklenen hata koşullarına ya da geçersiz girdilere nasıl yanıt vereceği de yazılır. Gereksinimler kısa, tam, belirsizlik içermeyen, doğrulanabilir ve gerekli olmalıdır. Gerekli bilgi henüz yoksa yer tutucu olarak "TBD" kullanılır. Her gereksinim bir sıra numarası ya da anlamlı bir etiketle tek olarak kimliklendirilir: `REQ-1:`, `REQ-2:`.

Büyük bir uygulamada System Feature 1, System Feature 2 alt modülleri ya da alt başlıkları temsil eder; çok küçük bir uygulamada doğrudan "fonksiyonel gereksinimler" denip sırayla maddelenebilir.

**Soru:** Fonksiyonel gereksinimleri belgenin hangi başlığı altına yazıyoruz?

**Cevap:** Dördüncü başlık olan System Features altına. 1. ve 2. bölümler belgenin genel başlangıcıdır (ürünün alanı, hedefi, kullanıcı sınıfları, gerekirse genel bir use case diyagramı); 3. bölüm ara birimlerdir (kullanıcı ekranları, donanım ara birimleri gibi); asıl önemli olanlar 4 ve 5'tir.

**Soru:** Bu belgenin Türkçesi var mı?

**Cevap:** Gösterilen belge orijinal IEEE 830 belgesidir. Yazılım standartları IEEE, ISO ve DoD gibi farklı kurumlar tarafından hazırlanır; kalite konusunda bunlara dönülecektir. Bu formata uygun Türkçe belgeler de bulunabilir. Öğrencilerin kendi belgelerinde bu formatın aynısını kullanması gerekmez, çünkü standart çok fazla ayrıntı içerir.

**Soru:** Örneğin faturalama, irsaliye ve stok gibi modüller ayrı sistem özellikleri mi olur?

**Cevap:** Evet. Her biri için yapılacak işlemler alt başlıklar halinde verilir; ama yalnız işlemin adı yazılmaz, her gereksinim bu özelliği sağlamak için sırasıyla yapılması gereken işlemi bir cümleyle anlatır.

### 10.4 Bölüm 5: Diğer fonksiyonel olmayan gereksinimler

Performans gereksinimleri, safety ve security gereksinimleri, diğer yazılım kalite özellikleri ve iş kuralları bu bölümdedir. Şablondaki açıklamalardan (ekrandan, 01:35:00):

- **5.3 Security Requirements:** Ürünün kullanımı ya da ürünün kullandığı ya da ürettiği verinin korunmasıyla ilgili güvenlik ve gizlilik gereksinimleri belirtilir; kullanıcı kimlik doğrulama gereksinimleri tanımlanır; ürünü etkileyen dış politika ya da düzenlemelere atıf yapılır; sağlanması gereken güvenlik ya da gizlilik sertifikaları tanımlanır.
- **5.4 Software Quality Attributes:** Müşteri ya da geliştirici için önemli olacak ek kalite özellikleri belirtilir. Dikkate alınabilecekler: adaptability, availability, correctness, flexibility, interoperability, maintainability, portability, reliability, reusability, robustness, testability ve usability. Bunlar mümkünse belirli, nicel ve doğrulanabilir yazılmalıdır. En azından çeşitli özellikler arasındaki göreli tercihler (örneğin öğrenme kolaylığı yerine kullanım kolaylığı) açıklanmalıdır.
- **5.5 Business Rules:** Ürünle ilgili işletim ilkeleri listelenir; örneğin hangi kişilerin ya da rollerin hangi koşullarda hangi fonksiyonları yapabileceği. Bunlar kendi başlarına fonksiyonel gereksinim değildir, ama kuralları uygulatmak için bazı fonksiyonel gereksinimleri gerektirebilir.

Her başlık altında yalnız bir gereksinim değil, birden fazla gereksinim yazılabilir. Analiz modelleri isteğe bağlıdır; analiz ve tasarımda veri akış diyagramı, sınıf diyagramı ya da use case diyagramı gibi modeller oluşturulmuşsa bunlar da eklenir.

**Soru:** Security gereksinimleri altında, örneğin öğrencilerin uzaktan bağlandığı bir uygulamada şifreleme (encryption) gibi şeyler mi yazılır, yoksa kullanıcının hangi ekran ve modüllere erişebileceğini gösteren bir yetki matrisi de buraya girer mi?

**Cevap:** Her ikisi de olabilir. Bu bölüm tek bir gereksinimden oluşmak zorunda değildir; ürün için, ürünün kullandığı veri için ve kullanıcı tanımlaması için ayrı ayrı gereksinimler sıralanabilir. Ayrıca bölüm yalnız safety ve security başlıklarıyla sınırlı değildir; şablondaki başlıklar örnektir. Fonksiyonel gereksinimlere girmeyen ve yazılım kalite özelliklerinden çıkarılan herhangi bir gereksinim ana başlık yapılabilir. Uygulamaya göre örneğin güvenirlik (reliability) öne çıkabilir ve ayrı bir başlık olarak yazılabilir.

## 11. Fonksiyonel ve Fonksiyonel Olmayan Gereksinimler

**Fonksiyonel gereksinimler (functional requirements)** yazılımda gerçekleştirilen temel işlemlerdir, yani yazılımın hangi fonksiyonları olduğudur ve o yazılıma özgüdür. Fatura kesme yazılımı örneğinde: alınacak ürünlerin belirlenmesi, her ürün için gereken bilgiler (fiyat, miktar), faturanın başında bulunması gereken bilgiler (faturanın kime ve hangi tarihte kesildiği) gibi işlemler fonksiyonel gereksinimlerdir.

Fonksiyonel gereksinimler iki biçimde yazılabilir: use case diyagramlarıyla (olayın nasıl işlediği ve taraflar arasındaki ilişki) ya da doğal dilde madde madde kısa cümlelerle. Doğal dil kullanılıyorsa **her basit cümlede yalnız bir gereksinim** olmalıdır; büyük bir uygulamada gereksinimler alt parçalara bölünerek verilebilir. Büyük bir uygulamada alt başlıklara bölmek ve sıralamak hem karışıklığı önler hem de kullanıcı testinde kolay takip edilmesini sağlar.

> **Hocanın vurgusu:** SRS raporu müşteri ile geliştirici arasında sözleşme niteliği taşır. "Şu fonksiyonu gerçekleştirecek" denen her şey kullanıcı kabul testinde takip edilebilecek biçimde, anlaşılır yazılmalıdır. Hangi yöntem seçilirse seçilsin (yazıyla Requirement 1, Requirement 2 ya da use case belgeleri), gereksinimler her cümlede bir gereksinim olacak biçimde basit cümlelerle yazılmalıdır; çünkü kabul testinde her cümle eşleştirilerek kontrol edilir.

**Fonksiyonel olmayan gereksinimler (non-functional requirements)** yazılımın yaptığı işle değil, yazılımın karakteristiğiyle ilgili gereksinimlerdir: performans, güvenlik, kullanılabilirlik ve benzerleri. Öğrenci bilgi sistemi, fatura sistemi ya da üretim planlama sistemi olsun, bunların fonksiyonel gereksinimleri birbirinden farklıdır. Fonksiyonel olmayan gereksinimlerde ise yazılım kalite özelliklerinden hangilerinin öne çıkacağı belirtilir; bu özelliklerin adları yazılımdan yazılıma değişmez, yalnız bazı yazılımlarda bazıları daha önemlidir. Örnekler: performansın nasıl olacağı, uzaktan erişilebilirlik (örneğin öğrenci bilgi sisteminin 7/24 çalışır durumda olması ve bunu sağlayacak özellikler), not giriş sisteminde güvenlik ve gizlilik gereksiniminin hangi seviyede olacağı.

Dersin sonundaki tekrar sorusunda hoca ayrımı şöyle özetler: yazılımın gerçekleştireceği işle ilişkili gereksinimler fonksiyonel gereksinimlerdir; o işi yapması için gereken altyapı özellikleri ve kalite özellikleri fonksiyonel olmayan gereksinimlerdir. Öğrenci bilgi sisteminde ders seçimi sırasında öğrencinin alttan aldığı bir ders olup olmadığının kontrol edilmesi bir fonksiyonel gereksinimdir. Kullanışlılık, kullanıcı dostu olma ve güvenlik ise fonksiyonel olmayan gereksinimlerdir.

## 12. Örnek SRS: Web Accessible Alumni Database

Hoca, IEEE 830 yapısını kullanan ve internetten alınmış bir öğrenci projesi SRS'ini gösterir. Belgenin kapağında "Software Requirements Specification, Version 1.0, Web Accessible Alumni Database" yazar (ekrandan, 01:50:00). Uygulama, mezunlar hakkındaki bilgilere web üzerinden erişilebilen bir sistemdir. Hoca, belgede bazı hatalar olabileceğini ama öğrencilerin çapına uygun bir örnek olduğu için gösterdiğini, internette şirketlerin kullandığı daha profesyonel SRS örneklerinin de bulunabileceğini belirtir.

Gözlemler şunlardır:

- Küçük projelerde 1., 2., hatta 3. bölümler çok kısa geçilebilir. Örneğin standarttaki "belgenin amacı" için 4-5 alt başlık varken bu ders projesinde amaç tek paragrafla verilmiştir: ürünün yeteneklerini hem son kullanıcılar hem geliştiriciler için açıklamak, işlevsel ve işlevsel olmayan gereksinimlerini belirtmek. Daha az formal bir içeriktir.
- Belgenin genel bakış kısmı sırasıyla projenin genel tanımını, fonksiyonel gereksinimleri ve en son bölümde fonksiyonel olmayan gereksinimleri vereceğini söyler. Ürünün hedefi, şu anki durum, kapsamı, ilgili taraflar (görevli, üniversitenin web sunucusu, bölümün sunucusu, veri tabanı) ve faydaları anlatılır.
- Fonksiyonel gereksinimler maddeler halinde ayrıca yazılmamış, use case diyagramı ve use case belgeleriyle verilmiştir. Bu yüzden önce aktörler açıklanmıştır (ekrandan, 01:55:00):
  - **4.1.1 Alumnus:** Mezun şu işlemleri yapar: Access Alumni Home Page, Fill out survey, Create new entry, Update entry, Search for Alumni.
  - **4.1.2 Secretary Staff:** Sekreterlik görevlisi, Fill out survey dışında mezunla aynı işlemleri yapar. Bu yüzden mezun (Alumnus) sistemin ana aktörü kabul edilmiştir.
- Sistem sınırları ve sınırlar içindeki işlemler genel bir use case diyagramıyla gösterilir. Her use case belgesinde use case'in adı, ne iş yaptığı, önceliği, ön koşulu ve temel işlemleri (basic path) yer alır; gerekirse istisna akışı (exception path) ve istisna durumunda nereye gidileceği gösterilir. Örneğin anket doldurma use case'inde ön koşul sayfaya erişilmiş olmasıdır ve 6 adım vardır; her adım tek bir işi anlatır. Hoca, yeni kayıt oluşturma use case'inde iki işin tek adımda birleştirildiğini, bunun ayrılabileceğini belirtir. Güncelleme ve arama gibi işlemler de aynı biçimde tanımlanır.
- Use case adımları yazıyla gereksinim olarak yazılsaydı, aynı adımlar o bölümün fonksiyonel gereksinimleri olurdu. İki yöntem de kullanılabilir.

Fonksiyonel olmayan gereksinimler bölümü şöyledir (ekrandan, 02:00:00):

- **5.1 User Interface Requirements:** Uygulamanın kullanıcı arayüzü kullanıcı dostu, sezgisel ve kolay kullanılır olmalı, ergonomi standartlarını uygulamalıdır.
- **5.2 Performance Requirements:** Sistem gerçek zamanlı çalışmalıdır: saklanan bilgi üzerinde mezunun tetiklediği her işlem 10 saniyeden kısa sürede tamamlanmalıdır. Sistem, veri bozulması olmadan en az 100 kullanıcının aynı anda kullanımına izin vermelidir.
- Ardından erişilebilirlik ve güvenirlik (availability ve reliability) ile güvenlik gereksinimleri gelir.

Hoca performans gereksinimlerinin iki cümlelik bir paragrafla yazıldığını, bunun 5.2.1, 5.2.2 diye maddelere ayrılmasının daha anlaşılır olacağını ve öğrencilerden böyle yapmalarını istediğini söyler. Güvenlik bölümündeki üç cümle için de aynı şey geçerlidir. Availability ile reliability'nin birleştirilmesi de gerekmezdi; reliability ayrı yazılabilirdi. Fonksiyonel olmayan gereksinimlerden anlaşılan, yazılımın yaptığı iş nedeniyle olan özellikler değil, bu işi yaparken gereken sistem kaynakları ve nitelikler açısından belirtimlerdir.

**Soru (bir öğrencinin gözlemi):** Örnek belgenin içindekiler listesinde 4.3'ün altındaki maddeler kaymış görünüyor.

**Cevap:** Evet; bu bir deneme örneğidir. Öğrenciler de ufak hatalar yapabilir, ama kapsamlı standardın aynı maddelerini yazmak zorunda değildirler. Özetlerken çok farklı bir yapı kurmamalı; asıl hedef sistem kapsamındaki bütün işlevsel ve işlevsel olmayan gereksinimlerin sıralanmasıdır.

## 13. Yazılım Kalite Özellikleri ve McCall Kalite Modeli

Hoca, sonraki haftaların konusu olsa da SRS'te sürekli geçen "Software Quality Attributes" kavramını açıklığa kavuşturur. Kalite özelliklerini belirten standartlar vardır; ISO 9126 bütün kalite özelliklerini sırayla, gruplamadan yazar. McCall ise bir modelleme çalışması yapmış ve **McCall'un kalite üçgeni** olarak bilinen modelde özellikleri üç gruba ayırmıştır (ekrandan, 02:15:00):

- **Ürünün çalışması (Product Operation):** Correctness (doğruluk), Reliability (güvenirlik), Usability (kullanışlılık), Integrity (bütünlük), Efficiency (etkinlik).
- **Ürün geçişi (Product Transition):** Portability (taşınabilirlik), Reusability (yeniden kullanılabilirlik), Interoperability (birlikte çalışabilirlik). Ürünün bir sistemden başka sisteme geçişi ya da sistem üzerinde diğer uygulamalarla çalışması sırasında önem kazanır.
- **Ürün revizyonu (Product Revision):** Maintainability (bakım yapılabilirlik), Flexibility (esneklik), Testability (test edilebilirlik). Ürünün düzeltilmesi ve bakımı sırasında, yani yazılımda sonradan değişiklik yapılacağı zaman önem kazanır.

Hoca kendi slaytında ürünün çalışması grubuna iki özelliği eksik yazdığını belirtip doğruluk ve güvenirliği ekler ve bir ayrımı vurgular:

> **Hocanın vurgusu:** Safety (güvenlik) ile güvenirlik (reliability) farklı şeylerdir. Correctness bize doğru sonuç verilmesidir; güvenirlik ise bu doğru sonuca hangi sınır aralığında, yüzde kaç güvenebileceğimizdir.

> **Ders sonrası not:** Hoca bu açıklamada bir an "usability bize doğru sonuç veriyor" dedi; bağlamdan doğru sonuç verme özelliğinin correctness olduğu anlaşılıyor.

### 13.1 Kalite özellikleri ve ölçütler

McCall modelinde soldaki kalite özellikleri tanımsaldır, doğrudan ölçülemez. Sağdaki ölçütler (criteria) daha ölçülebilirdir. Bu yüzden her kalite özelliği, ölçütlerin farklı katsayılarla birleşimi olarak değerlendirilir. Diyagramdaki ölçütler şunlardır (ekrandan, 02:10:00): Traceability, Completeness, Consistency, Accuracy, Error Tolerance, Execution Efficiency, Storage Efficiency, Access Control, Access Audit, Operability, Training, Communicativeness, Simplicity, Conciseness, Instrumentation, Self-descriptiveness, Expandability, Generality, Modularity, Software System Independence, Machine Independence, Communications Commonality, Data Commonality.

Hocanın anlattığı ve diyagramda okunan ilişkiler şöyledir:

| Kalite özelliği | İlişkili ölçütler |
|---|---|
| Correctness | Traceability, Completeness, Consistency |
| Reliability | Consistency, Accuracy, Error Tolerance |
| Efficiency | Execution Efficiency, Storage Efficiency |
| Integrity | Access Control, Access Audit |
| Usability | Operability, Training, Communicativeness |
| Maintainability | Simplicity, Conciseness, Self-descriptiveness, Modularity |
| Testability | Simplicity, Instrumentation, Self-descriptiveness, Modularity |
| Flexibility | Self-descriptiveness, Expandability, Generality, Modularity |
| Portability | Self-descriptiveness, Modularity, Software System Independence, Machine Independence |
| Reusability | Self-descriptiveness, Generality, Modularity, Software System Independence, Machine Independence |
| Interoperability | Modularity, Communications Commonality, Data Commonality |

<!-- BELİRSİZ: Diyagramdaki oklar çok sık ve kesişiyor; Correctness ile Maintainability, Testability, Flexibility ve Portability satırlarındaki bazı oklar kareden kesin okunamadı. Hocanın sözlü anlattığı ilişkiler aşağıda ayrıca verildi. -->

Hocanın sözlü açıklamaları:

- **Güvenirlik:** Doğruluk (accuracy) ve hata toleransı önemlidir; yani "doğru, ama ne kadar hatayla doğru".
- **Etkinlik:** Çalışma etkinliği (ne kadar sürede yanıt verdiği) ve bellek etkinliği.
- **Bütünlük:** Erişim kontrolü ve erişimin denetimi.
- **Kullanışlılık:** Çalıştırılabilirlik (operability), eğitim verilmesi ve iletişim kolaylığı.
- **Bakım yapılabilirlik:** Yazılımın kendi kendini ne kadar iyi tanımladığı; hem yazılımın iç açıklamaları hem belgelemesi bakım yapılabilirliği artırır. Yazılım modülerse bakım yapılabilirliği daha fazladır.
- **Birlikte çalışabilirlik:** Verinin genelliği (data commonality), iletişim genelliği (communications commonality) ve modülerlik.
- **Test edilebilirlik:** Basitlik; tasarımla sağlanır; yazılım içinde açıklamaların ve belgelerin olması gerekir; modüler yazılımlar daha kolay test edilir.
- **Esneklik:** Ne kadar genişletilebilir olduğu ve genelleştirilebilirliği.
- **Taşınabilirlik:** Yazılım sisteminden ve bilgisayardan (makineden) ne kadar bağımsız olduğu.
- **Yeniden kullanılabilirlik:** Basitlik, genellik, modülerlik, yazılım sisteminden bağımsızlık ve makineden bağımsızlık. Yeniden kullanılabilir yazılım parçaları geliştirmenin önemli bir yanı, özellikle makineden bağımsız ve daha genel yapıda yazılım geliştirmektir.

> **Ek bilgi (derste anlatılmadı):** ISO 9126'nın yerini büyük olasılıkla 2011'de yayımlanan ISO/IEC 25010 (SQuaRE ailesi) kalite modeli almıştır. Bu modelde de kalite özellikleri gruplar halinde verilir; örneğin işlevsel uygunluk, performans etkinliği, uyumluluk, kullanılabilirlik, güvenirlik, güvenlik, bakım yapılabilirlik ve taşınabilirlik.

## 14. SRS Standartları, Artefact Kavramı ve Genel Tekrar

Hoca toparlarken gereksinim analizinde hedefin SRS belgesini doğru ve koşullara uygun yapıda hazırlamak olduğunu söyler; bu belge teslimde şartname yerine geçeceği için içinde hata kalmamalıdır. Slayttaki maddeler şunlardır (ekrandan, 02:20:00):

- Gereksinimler, SRS (Software Requirements Specification) belgesi altında toplanır.
- SRS raporuna yönelik çeşitli standartlar mevcuttur:
  - IEEE 830-1998: SRS odaklı
  - ISO/IEC/IEEE 29148:2011 Systems and Software Engineering, Life Cycle Processes, Requirements Engineering
  - Ders kapsamında, gereksinim mühendisliği ve analiz bölümlerinde bu belgede yer alabilecek artefact'ların en yaygınları üzerinde çalışılacaktır.
  - Yazılım geliştirme sırasında kod dışında ortaya çıkardığımız her türlü metin ve şemaya "artefact" denilmektedir.

29148, gereksinim analizini yazılım yaşam döngüsü içine katan ve gereksinim mühendisliği sürecinin nasıl yürüdüğünü belirten ortak bir standarttır. Gereksinim modeli içinde hangi diyagramların ve hangi metinlerin bulunacağının doğru tanımlanması gerekir.

Ardından analiz ile tasarım yeniden karşılaştırılır. Analizde (gereksinim analizinde de, sistem analizinde de) "ne?" sorusuna cevap verilir: üzerinde yazılım geliştirilecek sistem nedir, bu anlaşılmaya ve nasıl anlaşıldığı belgelenmeye çalışılır. Modeller oluşturulur ama yazılım hazırlanmaz. Tasarımda ise sistemin en iyi çalışacak biçimde nasıl tasarlanacağı, hangi yazılım mimarisinin kullanılacağı, modüller arası ilişkilerin nasıl olacağı ve nesneye yönelikse sınıfların nasıl tanımlanacağı belirlenir.

Son olarak adımlar bir kez daha özetlenir: başlangıçta yukarıdan genel bir bakış alınır ve paydaşlar seçilir; bilgi toplamada sistemin çalışma kuralları, kullanıcı tipleri ve yaptıkları işler öğrenilir (anket, görüşme, yerinde inceleme, benzer ürünleri inceleme, kurumun işleyişi); modellemede tüm paydaşların yazılımla ilişkisi kullanım senaryoları ya da veri akış diyagramlarıyla gösterilir, bazı bilgiler genişletilir, bazıları özetlenir ve gereksinimler sınıflandırılır; pazarlıkta farklı kullanıcılardan gelen bilgiler düzeltilir ve aşırı istekler değerlendirilir; tanımlamada gereksinimler uzlaşılan haliyle kağıda dökülür.

> **Hocanın vurgusu:** Bir yazılım geliştirme projesinin başka hiçbir belgesi olmasa bile bir SRS belgesi vardır.

**Soru:** Bu derste görülenler klasik yazılım geliştirme ve çevik süreçlerin her ikisinde de aynı mı?

**Cevap:** Çevik süreçler kullanılsa da bir SRS belgesi hazırlanması gerekir. Fark sürecin takibindedir: analiz bitip tasarım başlamaz; analiz, tasarım, gerçekleştirme ve test küçük birimlere bölünür. Süreç farklıdır ama bu belge ve diğer belgeler hepsinde vardır; "çevik" diye hiç belgesiz çalışmak, programcılığı bir zanaat gibi yürütmek söz konusu değildir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:10): Bir sistem analizi ya da gereksinim analizi yaparken sistemin ne yaptığı hakkında nasıl bilgi toplarız? Bilgi toplama yollarını sayınız.

> **Derste verilen cevap:** Benzer uygulamalar incelenir; teknik araştırma yapılabilir; müşteriyle planlı biçimde, önce yönetimle sonra işi yapanlarla görüşmeler yapılır. Yerinde inceleme de bir yoldur: örneğin depo için uygulama yapılıyorsa depoya gidip işin nasıl yapıldığı görülür ve işi gerçekten yapanla birebir çalışılarak gereksinimler anlaşılır. Hoca tekrar bölümünde yaygın bir kullanıcı ağı varsa anketi ve kurumun işleyişinin incelenmesini de ekler.

**Soru 2** (derste sözlü, 02:20:40): Gereksinim analizindeki bilgi ve modeller SRS belgesinde saklanır. SRS belgesindeki tanımlamalar ne işe yarar, nerede kullanılır?

> **Derste verilen cevap:** Tasarımda kullanılır: ürünü kullanıcıya en uygun biçimde tasarlamak için gereksinimlere bakılır. İş bitince ürünün istenen şeyi yapıp yapmadığını kontrol etmek (cross-check) için kullanılır. Test aşamasında, özellikle kullanıcı kabul testinde kullanıcı "başta neler istemiştim" diye bu belgeye bakarak her maddeyi işaretler; belge, müşteriyle aradaki şartname niteliğini taşır. Bu yüzden iki tarafın da belgeyi kontrol etmesi gerekir.

**Soru 3** (derste sözlü, 02:31:16): Fonksiyonel gereksinim nedir, fonksiyonel olmayan gereksinim nedir? Fatura ya da öğrenci bilgi sistemi örneğinden bir fonksiyonel gereksinim veriniz.

> **Derste verilen cevap:** İlk cevapta "sistemin kullanışlılığı" fonksiyonel gereksinim olarak önerildi; bu doğru değildir, kullanışlılık fonksiyonel olmayan bir gereksinimdir. Kullanıcı dostu olma ve güvenlik de fonksiyonel olmayan gereksinimlerdir. Fonksiyonel gereksinim, yazılımın gerçekleştireceği işle ilişkili gereksinimdir; örneğin öğrenci bilgi sisteminde ders seçimi yapılırken öğrencinin alttan aldığı bir ders olup olmadığının kontrol edilmesi. O işi yapmak için gereken altyapı ve kalite özellikleri ise fonksiyonel olmayan gereksinimlerdir.

## Dersin Toparlaması

Bu derste gereksinim mühendisliğinin yedi adımı (başlangıç, bilgi toplama, işleme, pazarlık, tanımlama, doğrulama, yönetim) sistem analizi dersindeki üç adımlı yapının ayrıntılandırılmış hali olarak ele alındı. Paydaş kavramı, gereksinimlerin normal, beklenen ve heveslendirici diye sınıflandırılması, pazarlığın müşteri-geliştirici ve paydaş-paydaş boyutları, doğrulamada sorulacak sorular ve gereksinim değişikliklerinin izlenebilirlik tablosuyla yönetilmesi anlatıldı. Ardından IEEE 830 SRS şablonu bölüm bölüm incelendi; fonksiyonel gereksinimlerin 4. bölümde (System Features), fonksiyonel olmayan gereksinimlerin 5. bölümde yer aldığı ve her gereksinimin kabul testinde eşleştirilebilmesi için tek cümlede tek gereksinim olarak yazılması gerektiği vurgulandı. Bir öğrenci projesi SRS örneği üzerinde use case belgeleriyle verilen fonksiyonel gereksinimler ve maddelenmesi gereken fonksiyonel olmayan gereksinimler gösterildi.

Son bölümde fonksiyonel olmayan gereksinimlerin kaynağı olan yazılım kalite özellikleri McCall modeliyle (ürünün çalışması, ürün geçişi, ürün revizyonu) ve ölçülebilir ölçütlerle ilişkileri üzerinden tanıtıldı. Kalite özellikleri ve standartlar sonraki haftalarda kalite konusunda yeniden ele alınacak; kullanım senaryoları ve kullanım şemaları ise nesneye yönelik analiz bölümünde işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
