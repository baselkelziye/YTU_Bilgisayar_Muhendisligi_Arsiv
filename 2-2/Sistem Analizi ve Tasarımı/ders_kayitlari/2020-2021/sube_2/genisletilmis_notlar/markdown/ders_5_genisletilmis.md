# Ders 5 Genişletilmiş Notu: Gereksinim Analizi, Kullanım Senaryoları ve Bilgi Toplama Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Analiz aşamasına giriş
- 2. Gereksinim analizi
- 3. Sistem analizi yöntemleri ve SRS
- 4. Analiz sürecinin akışı ve yönetim incelemesi
- 5. Kullanım senaryosu (use case) modellemesi
- 6. Senaryoların yazılması
- 7. Senaryolar arası ilişkiler
- 8. Sözleşmeler (contracts)
- 9. Araştırma ve bilgi toplama yöntemleri
- 10. İş gereksinimleri dokümanı (BRD) ve araştırma raporu
- Örnek Sorular

## 1. Analiz aşamasına giriş

Ders, ilk dört haftada işlenenlerin kısa bir tekrarıyla başladı: bilgi sisteminin ne olduğu, türleri, tarafları ve rolleri; bir bilgi sistemi geliştirme sürecinin adımları ve izlenebilecek süreç modelleri; ön inceleme ve fizibilite aşamaları. Önceki derste özellikle zaman fizibilitesi üzerinde durulmuş, Gantt ve PERT diyagramlarıyla iş zaman planı, kaynak ataması ve iş kırılım yapısı (work breakdown structure) bir proje yönetim aracı üzerinden gösterilmişti.

Bu hafta ve sonraki iki hafta boyunca yazılım geliştirme sürecinin bir sonraki basamağı olan **analiz** aşaması işlenecektir. Slayttaki ders kapsamı dört başlıktır (ekrandan, 00:15:00):

- Gereksinim Analizi
- İş Analizi
- Kullanım Senaryoları
- Bilgi Toplama Yöntemleri

Hoca "use case" terimini "kullanım senaryosu" olarak çevirmeyi tercih ettiğini söyledi; "kullanım durumu" diyenler de vardır, ancak işin içinde rol oynayan aktörler olduğu için "senaryo" kelimesi ona daha anlamlı gelmektedir. İş analizi yapılıp senaryolarla modellenmeden önce işin nasıl yapıldığını öğrenmek, yani bilgiyi kaynağından toplamak gerekir; bu yüzden ders bilgi toplama yöntemleriyle bitecektir. Sonraki haftalarda fonksiyonel çözümleme (analizin teknik bir modele dönüştürülmesi), SRS ve senaryoların nesneye yönelik bir analiz modeline dönüştürülmesi işlenecektir.

> **Hocanın vurgusu:** Dersin adının yarısı "sistem analizi"dir; bu üç hafta yaşam döngüsünün geri kalanı için kilit önemdedir. Her adım bir öncekinden beslendiği için ne fizibilite ne de analiz "boş ver" denerek geçilmelidir.

## 2. Gereksinim analizi

### 2.1 Tanım

Gereksinim analizi; problemin ne olduğu, çözümlerinin ya da çözüm yaklaşımlarının neler olacağı ve çözülmeye çalışılan problemi işler hale getiren sistemin nasıl çalışacağıyla ilgili soruların cevaplarını bulmak için yapılan işlemler bütünüdür. Alternatif çözümler olabilir; amaç probleme en uygun çözümü sağlayan ana öğeleri, yani sistemin işlevlerini, fonksiyonlarını ya da sorumluluklarını bulmak ve ayrıntılarıyla tanımlamaktır.

Bu aşamada ortada henüz yaratılmaya başlamış bir sistem yoktur. Analiz, işi (business tarafını) anlayıp bunu teknik dile çevirmek için bir ara basamaktır. Bilgilere nereden erişileceği de belirlenmelidir: iş birimleri, müşteri ya da son kullanıcı pazarı gibi taraflardan neler toplanabileceği ve bu tarafların ihtiyaçlarının neler olduğu ortaya konur.

Gereksinim analizinin sonucunda kullanıcının ihtiyaç duyacağı bütün gereksinimler belirlenir ve her birinin nasıl çalışarak gerçekleştirileceğine dair "niyet beyanları" yazılır. Ayrıca şunlar da çıktı olabilir:

- Varsa mevcut sistemin durumu.
- En uygun çözümün nasıl seçildiğinin değerlendirmesi ve alternatif yaklaşımlar.
- Yeni bir sistem yerine yalnız iyileştirme yapılacaksa, mevcut sistemin nasıl iyileştirilebileceğine dair öneriler. Örneğin bir öğrenci bilgi sisteminin belli kısımlarının iyileştirilmesi önerisi analiz safhasının çıktısı olabilir.

### 2.2 Öncelikle yapılması gerekenler

Slaytta gereksinim analizine başlarken yapılacaklar şöyle sıralanır (ekrandan, 00:20:00):

- Fizibilite raporları gözden geçirilmeli
- Tüm teknik terimler incelenmeli
- Ayrıntılı inceleme planı yapılmalı
- Proje grubunun görev dağılımı yapılmalı
- Denetleme mekanizması kurulmalı

Teknik terimler alana özgü (domain specific) terimlerdir. Öğrenci bilgi sistemi için "ön koşullu ders" ya da "ağırlıklı genel not ortalaması (AGNO)", bir kripto borsası uygulaması için o alana has terimler bunlara örnektir. Hoca ilk iki maddenin doğrudan analizle, son üç maddenin ise temelde proje yönetimiyle ilgili olduğunu belirtti: incelemenin nasıl yapılacağı, kimin hangi işi yapacağı ve bunun izlenip yönetilmesi için bir denetim mekanizması.

### 2.3 Mevcut sistemin incelenmesi

Her zaman sıfırdan yeni bir sistem yapılmayabilir; mevcut bir sistemi önce inceleyip sonra iyileştirmek ya da yeni bir sisteme dönüştürmek gerekebilir. Bu durumda mevcut problemin nasıl çözüldüğü, mevcut sistemin nasıl çalıştığı ve nelere mal olduğu anlaşılmalıdır. Bu işi ikinci haftada tanıtılan **sistem analisti** yapar ve şunları ortaya koyar:

- Mevcut bilgi kaynakları, donanım ve yazılım kaynakları.
- Problemi çözmek için hangi bilgilerin kullanıldığı ve miktarları (örneğin ağ trafiği, birim zamandaki işlem sayısı).
- İç ve dış paydaşlarla ne kadar bilgi transferi olduğu, başka sistemlerle ne kadar veri alışverişi yapıldığı ya da yapılması gerekeceği.
- Sistemin döngüsü, yaptıkları, çalışma süreleri ve performansı; raporlama ve arşivleme.
- Sistemin personeli (tarafları) ve maliyetleri.

Mevcut sistem yoksa bunlar yapılmaz; o zaman doğrudan işin kendisi anlaşılmaya çalışılır, yani **iş analizi** yapılır. İş analizi her durumda yapılacak işlerden biridir.

## 3. Sistem analizi yöntemleri ve SRS

### 3.1 İki temel yaklaşım

Gereksinimlerin ortaya konması için yapılan sistem analizinde iki temel yaklaşım vardır (ekrandan, 00:25:00):

- **Gereksinimler önceden müşteri ile saptanırsa: akış diyagramları gösterimi.** Bilişim alanı, işlevler, ara birimler ve kabul kriterleri belirlenip diyagramlarla gösterilir. Müşteri neye ihtiyacı olduğunu biliyor ve aktarabiliyorsa, ya da iş bir ihale gibi her şeyin "noktasına virgülüne kadar" tanımlandığı kontratlı bir işse (savunma sanayiinde sık görülür) bu yöntem kullanılabilir. Burada algoritmaları göstermek için kullanılan bilinen akış diyagramları kullanılır; bunun yanında analiz ve tasarım modelini gösteren başka diyagramlar da üretilir.
- **Gereksinimler önceden saptanmazsa: prototip oluşturulur.** Müşteri ne istediğini tam bilmiyor, anlatamıyor ya da bazı şeylerin farkında değilse, analist anladığı kadarıyla bir prototip üretir (artımlı, iteratif süreç modellerinde olduğu gibi bir sürüm). Müşteriyle birlikte prototip üzerinde tartışılır ("bunu da yapabiliyor muyuz?", "biz bunu böyle yapmıyoruz, şunlar şuradan geliyor" gibi) ve gereksinimler kararlaştırılır. Sürümler ilerledikçe ürün son bilgi sistemine yaklaşır.

Hoca buradaki "tartışma"nın bir atışma değil, birlikte bakıp değerlendirme (İngilizcedeki arguing anlamında) olduğunu vurguladı. Hangi yol izlenirse izlensin, sonunda belirli teknik çıktılar ve diyagramlar üretmek gerekir.

### 3.2 Sistem Gereksinimleri Spesifikasyonu (SRS)

Slayttaki ifadeler şöyledir (ekrandan, 00:30:00):

- Analist ve müşterinin ortak çalışması ile sistem gereksinimlerinin özellikleri ortaya konulur: belge haline gelir → sistem gereksinimleri spesifikasyonu, sistem prototipi.
- Sistem geliştirme planı da gözden geçirilir.
- Sistem geliştirme planı ile sistem analizi birlikte iç içe gerçekleştirilir: tanımlama aşaması.

Analiz yapılıp analiz modeli ortaya konduktan sonra bunun yazılım geliştiricilere ve tasarımcılara anlatılması gerekir; bu **SRS** (Software ya da System Requirements Specification) ile yapılır. Hoca bunu "sistem gereksinimleri spesifikasyonu" diye çevirdi; spesifikasyon "tanımlama" demektir. Gereksinimler müşteriden doğduğu için bu belge müşteriyle ortak çalışılarak hazırlanır. Hoca "müşteri" kelimesini iş birimi ve son kullanıcı dahil, hizmet edilen tarafın genel adı olarak kullandı.

SRS'in bir standardı da vardır: **IEEE 830**, yazılım gereksinimlerinin nasıl tanımlanacağına dair resmi bir formattır. SRS ortaya çıktığında analiz bitmiş sayılır. Belgede şunlar bulunur:

- Sistemin sahip olması gereken işlevler ve işlev dışı özellikler (**işlevsel olmayan gereksinimler**).
- Sistemin sorumlulukları ve sınırı; hangi verinin nereden alınıp nereye verileceği.
- Kalite unsurları; örneğin "saniyede 10 bin kullanıcıya hizmet verebilmelidir", ağ genişliği ya da sistem tepkisiyle ilgili gereksinimler.

SRS hazırlanırken sistem geliştirme planı (fizibilitede yapılan Gantt diyagramı) da gözden geçirilir. Analiz sonucunda yeni modüllere ihtiyaç doğabilir; bunun için ilave iş gücü ya da zaman gerekebilir, ya da fazla planlanan işler azaltılabilir. Bu yüzden plan ve analiz paralel yürütülür.

## 4. Analiz sürecinin akışı ve yönetim incelemesi

### 4.1 Akış

Hoca analiz sürecinin akışını bir şema üzerinden anlattı (şemanın karesi yoktur; akış altyazıdan kurulmuştur):

```text
Yazılım planı (project charter, fizibilite matrisi)
  -> İdari inceleme: revizyon ya da kabul
  -> Gereksinimler biliniyor mu?
       Evet  -> gereksinimler yazılır
       Hayır -> prototip / model oluşturulur
  -> (isteğe bağlı ara çıktı) İş gereksinimleri dokümanı (BRD)
  -> Yazılım gereksinimleri dokümanı (SRS)
  -> Teknik inceleme: revizyon ya da kabul
  -> Yönetim incelemesi: onay -> tasarıma başlanır
                         ret  -> revizyon, gerekirse SRS güncellenir
```

<!-- BELİRSİZ: Akış şemasının slayttaki tam biçimi karelerde yok; adımlar altyazıdaki anlatımdan çıkarıldı. -->

İşin ne olduğunun anlaşıldığı aşamada bir **BRD** (Business Requirements Document, iş gereksinimleri dokümanı) da oluşturulabilir. Bu, SRS'ten önce üretilen bir ara çıktıdır: önce işin ne olduğu BRD'de, sonra teknik tarafı SRS'te anlatılır.

### 4.2 Yönetim incelemesinde bakılanlar

İdari inceleme, daha önce konuşulan yönetim fizibilitesine, yani yönetimin kararına karşılık gelir. Hoca bu noktalar üzerinde çok durmayacağını söyleyerek genel olarak şunlara bakıldığını belirtti:

- İhtiyaçlar işletmenin stratejileriyle uyumlu mu?
- Bu konularda deneyim, bilgi ya da sağlam öngörü var mı?
- Daha fazla finansal fayda sağlıyor mu?
- Çok fazla organizasyonel değişiklik gerektiriyor mu? Değişim; kaynak ihtiyacı, zaman kaybı ve masraf demektir.
- Raporlaması daha iyi, kullanıcılara daha fazla bilgi sağlayan bir veri akışı var mı?
- Daha hızlı mı, yeni teknolojiye sahip mi, ileriye yatırım niteliğinde mi?

Bunlara bakılarak modelin uygun olup olmadığına karar verilir.

## 5. Kullanım senaryosu (use case) modellemesi

### 5.1 Tanım ve amaç

Use case modellemesi (kullanım senaryosu modellemesi), işlerin ne olduğunu anlamanın formal bir yoludur; iş ihtiyaçlarının (business requirements) bulunması, ortaya konması ve tanımlanması için kullanılan bir modelleme yaklaşımıdır. Slayttaki tanımlar şöyledir (ekrandan, 00:35:00):

- Kullanım Senaryosu Diyagramı
- Kullanıcının bakış açısından sistemin fonksiyonel çözümlemesini tanımlar
- Sistemin ihtiyaçlarını yerine getirmek için gereken davranışlar için kullanılır
- Aktörler: Kullanıcılar, dış sistemler, fiziksel çevre etmenleri, ...
- Senaryolar: Bir olay akışı şeklinde sistemce sağlanan fonksiyonellik
  - Ön koşullar ve son koşulları, senaryo, birincil ve ilgili aktörleri olmalıdır.

Hoca, çevik (agile) süreçlerde use case'lerin ağır kaldığını ve yerini daha kısa kullanıcı hikayelerine (user story) bıraktığını, hızlı geliştirme yapanlar için bunların "ayak bağı" olmaya başladığını söyledi; ancak büyük sistemlerde use case kullanımı devam etmektedir.

Use case modellemesi sonunda tek bir diyagram üretir. Bu diyagram, bilgisayardan anlamayan birinin bile bakıp "evet bu sorumluluklar var, bunlar yapılmalı" diyebileceği ya da "biz bunu böyle yapmıyoruz" diye tepki verebileceği bir modeldir. Diyagramın her parçası için ayrıca yazılmış belgeler de olur.

> **Hocanın vurgusu:** Analiz tarafı çok yazmalıdır. Önce project charter, sonra fizibilite çıktıları, ardından BRD ve en sonunda SRS yazılır; bir yandan da diyagramlar çizilir.

Use case modellemesi kullanıcı gözüyle bakar ve sistemin fonksiyonel çözümlemesini tanımlar; yani sistemin sorumluluklarını, en kaba tabirle modüllerini ve bunların içindeki kırılımları ortaya koyar.

### 5.2 Üyelik örneği

Hoca bir yerlere üye olma işleminin bile bir senaryo olduğunu ve alt senaryolar içerdiğini gösterdi:

- Kullanıcının daha önce kayıtlı olup olmadığı kontrol edilir. Hangi verinin hangi kaynakta durduğu ve kontrolün nasıl yapılacağı tanımlanmalıdır.
- Kayıtlı değilse yeni kayıt alınır. Kurumsal müşteriden ve bireysel müşteriden farklı bilgiler alınabilir; hangi bilgilerin nasıl alınacağı tanımlanmalıdır.
- Kullanıcı şifresini unutursa ne olacağı yeni bir sorumluluktur: yalnız e-posta mı gönderilecek, yoksa telefon ve SMS de işin içine girecek mi?

Her bir fonksiyonelliğin ne olacağının ve nasıl çalışacağının anlatıldığı bu modellemeye use case modellemesi denir.

### 5.3 Aktörler ve senaryolar

Sistem çalışırken bilgileri kim girecek, işin içinde kimler rol alacak? Bunlara **aktör** denir. Aktör, yapılan sistemin kullanıcıları, hizmet alınan ya da verilen sistemler, hatta fiziksel çevre elemanları olabilir. Aktörlerin etkileşime geçtiği, olay akışı şeklinde sistemin sağladığı işlevselliklere **senaryo** denir.

Bir senaryonun ön koşulları (bu şartlarda çalışırım) ve son koşulları (çalıştığımda şunu garanti ederim), olay akışı (ana senaryo) ve birincil ve varsa ilgili aktörleri tanımlanmalıdır.

**Soru (hocanın kendi sorusu):** Aktörsüz senaryo olur mu? **Cevap:** Görünüşte bir senaryo başka bir senaryoya bağlı olarak aktörsüz kalabilir, ama o da sonunda bir aktörle etkileşir; bu yönüyle aktörsüz senaryo yoktur. Hiçbir senaryoyla ilgisi olmayan aktör de olmaz: kenarda durup hiçbir şeyle etkileşmeyen bir taraf sistemin parçası değildir ve aktör olarak modellenmez.

### 5.4 Diyagramın bileşenleri

Use case diyagramı dört bileşenle çizilir:

- **Aktör:** çöp adam olarak çizilir (çizmesi kolay olduğu için).
- **İlişki:** aktörü senaryoya ya da senaryoyu senaryoya bağlayan çizgiler.
- **Senaryo (use case):** adı elips (oval) içine yazılır.
- **Sistem sınırı:** senaryoları içine alan dikdörtgen; zorunlu değildir, ama sistemin sınırlarını gösterir.

Bu diyagram, "bu sorumlulukları yerine getirmeyi vaat ediyorum" şeklinde bir niyet beyanıdır.

### 5.5 Örnek: okul servisi takip sistemi

Slayttaki diyagram şöyledir (ekrandan, 00:45:00). Slaytta "Aktörler insan olmak zorunda değildir", "Aktörler ve sistem etkileşimini gösterir", "Üç senaryo mevcuttur" yazar.

| Aktör | İlişkili senaryo |
|---|---|
| GPS System | Report location |
| (adı yazılmamış aktör) | Find arrival times |
| (adı yazılmamış aktör) | Report error |

Üç senaryo sistem sınırını gösteren dikdörtgenin içindedir.

Hoca örneği şöyle kurdu: bir filo ya da okul servisi yönetim sistemi düşünülsün; bütün araçlarda GPS modülü takılıdır ve bu modüller bilgi sistemine konum gönderir. Gönderim sıklığı (saatlik, dakikalık, saniyelik) iş modeline, yani gereksinime bağlıdır. Örneğin her dakika zaman damgası, plaka (ya da şasi numarası) ve GPS koordinatlarının tanımlı bir protokolle gönderilmesi istenebilir. Bu başlı başına bir sorumluluktur ve "Report location" senaryosu olarak modellenir; bunu yapan aktör araçlardaki GPS sistemidir.

Araçların okula ne zaman varacağının hesaplanması da bir sorumluluktur: sistem konumu takip eder, okula olan uzaklığı bilir ve hız tahminiyle "A aracı 15 dakika sonra, B aracı 20 dakika sonra gelecek" gibi sonuçlar üretir. Bu "Find arrival times" senaryosudur. GPS cihazları bir hizmet ya da bakım anlaşmasıyla alınıyorsa ve arada bozulup konum bilgisi vermiyorsa, bunun bildirilmesi için "Report error" senaryosu yazılır.

<!-- BELİRSİZ: Hoca sağdaki adı yazılmamış aktör için altyazıda "herhalde teknik personel" gibi bir ifade kullanıyor; aktörün kim olduğu slaytta belirtilmemiş. -->

Bu diyagram sistemin kuş bakışı bir resmidir: sistemin sorumlulukları ve bunların kimlerle ilgili olduğu (öğretmen, doktor, şoför ya da GPS sistemi gibi) gösterilir. Aktörün "kanlı canlı" bir insan olması gerekmez; bir cihaz ya da dış sistem de aktör olabilir. Gerçek sistemlerde üç senaryo olmaz, çok daha fazlası olur. Büyük sistemlerde tek bir karmaşık diyagram yerine alt sistemlere göre ayrı diyagramlar (öğrenci işleri, öğretim üyesi, danışmanlık işlemleri gibi) çizilebilir. Ders projelerinde tek bir use case diyagramı yeterlidir.

Diyagramda adı konan her senaryonun içi ayrıca yazılmalıdır; bu örnekte üç senaryo yazılır ve hepsi bir araya geldiğinde use case modelini oluşturur.

### 5.6 Birincil ve destek aktörler

Aktör, sistemle etkileşen her türlü insan, sistem ya da cihazdır. **Birincil aktör** (primary actor) bir senaryodan asıl faydayı sağlayan ya da işlemleri başlatan "başrol oyuncusu"dur. Diğer aktörler senaryoda yer alır ama yalnız bilgi ya da destek sağlar; örneğin bir sistem bir çıktı üreterek destek veriyor olabilir.

Senaryo ise anlamlı bir sonuca ulaşmak, yani bir sorumluluğu yerine getirmek için aktörle sistem arasında gerçekleşen olaylar zincirinin adım adım yazılmış halidir.

## 6. Senaryoların yazılması

### 6.1 Senaryoların ifade edilmesi

Slayttaki ilkeler şöyledir (ekrandan, 00:50:00):

- İhtiyaç-özellik listesi değil
- Sistem kara kutu olarak alınır, sorumlulukları ifade edilir
- Aktörler-sistem etkileşimi, etken cümlelerle söylenir
- Ne yapar? Cevaplanır. Nasıl yapar? Tasarımın sorusudur
- Sistemin bitmiş hali hayal edilir. Oluşabilecek senaryolar yazılır.
- Sistemin sınırları doğru belirlenmelidir. Neler dışarıda, neler içeride olmalı?

Senaryo "şu olmalıdır, şöyle yapılmalıdır" diye bir liste değildir. Gerçek hayatta iş nasıl yapılıyorsa (iş modeli neyse) yazıya dökülür ve adım adım anlatılır. Sistem içi görülmeyen bir kara kutu olarak düşünülür ve vermesi gereken hizmetin adımları ifade edilir. Problem yazılır, çözüm henüz yazılmaz. Sistemin bitmiş hali hayal edilerek oluşabilecek bütün senaryolar bulunmalıdır; ancak bunun sonu gelmeyeceği için sorumluluk sınırlarının (neyin içeride, neyin dışarıda olduğunun) doğru belirlenmesi gerekir.

### 6.2 Kullanım senaryosunda yer alan bilgiler

Slayttaki şablon şöyledir (ekrandan, 00:55:00):

- **Önsöz**
  - Birincil Aktör
  - İlgililer ve Beklentileri: Sistemin çalışmasından etkilenen ve beklentileri olan diğer aktörler. İlk başta doğru tanımlanmazsa sistemin sınırları çizilemez. Bazı durumlar unutulabilir.
  - Ön koşullar: senaryonun başlaması için gerekli koşullar
  - Son koşullar: senaryo tamamlanınca sistemin olacağı durum (ilgililerin beklentileri)
- **Ana Başarılı Senaryo:** Sistemin en doğal çalışma şekli, adım adım yazılır. Koşul-dallanma olmaz. Etken cümlelerle, kimin ne yaptığı açık şekilde belirtilir. Üç tipi vardır: kullanıcı-sistem etkileşimi-tetikleme, onaylama, durum değişikliği-bilgi kaydı.
- **Alternatif Akış:** Ana senaryo dışındaki başarılı-başarısız sonuçlara götüren kısım. Şart belli olmalı. Bunlarla tüm amaçlar sağlanmış olur.
- **Sıra Dışı Durumlar:** Hata olunca yapılacaklar.
- **Özel istekler:** istenen hız, güvenlik vs gibi kalite kısıtları.
- **Teknolojik beklentiler:** dil-platform vs.

Hoca bu şablonu okul servisi örneğindeki "Find arrival times" senaryosu ve bir ders kayıt senaryosu üzerinden açıkladı.

**Önsöz.** Senaryoya bir kod ve ad verilir: "Use case 1: Find arrival times" gibi. Kod UC1, KS1 ya da S1 olabilir. Ardından birincil aktör yazılır: "Primary actor: GPS sistemi" gibi. Başka sistemlerde bu depo çalışanı, lisans öğrencisi ya da bir hastane bilgi sisteminde laborant, eczacı, pratisyen doktor veya röntgen teknisyeni olabilir. Birincil aktör, senaryoyu kimin çalıştırdığı ya da senaryonun asıl faydasını kimin gördüğü sorusunun cevabıdır. Sonra destek aktörleri, yani ilgililer (stakeholders) ve beklentileri yazılır. Bunların baştan doğru tanımlanması sistemin sınırlarını düzgün çizmek için önemlidir.

**Ön ve son koşullar.** Ön koşul, senaryonun çalışması için gereken şarttır; örneğin toplam 30 kredilik ders alabilmek için not ortalamasının 3.0'ın üzerinde olması gerekiyorsa bu bir ön koşuldur. Son koşul, senaryo bittiğinde sistemin hangi durumda olacağı, neyin garanti edildiği ve ilgililerin beklentilerinin nasıl karşılandığıdır.

**Ana başarılı senaryo.** İşin yapılması için gereken adımlar en doğal çalışma şekliyle, koşulsuz ve dallanmasız yazılır. Örneğin: "Öğrenci seçmek istediği dersin kodunu girer, grubunu seçer. Sistem öğrenciyi derse kaydeder." Kimin ne yaptığı ("okur", "yazar", "toplar", "sunar") etken cümlelerle açıkça belirtilir.

**Alternatif akışlar.** Kapasitenin yetersiz olması ya da öğrencinin AGNO veya ön koşul nedeniyle dersi alamaması gibi başarılı ya da başarısız sonuçlara götüren dallanmalar burada yazılır. Numaralandırma ana senaryodaki adıma göre yapılır: "4a: AGNO yetersizse ...", "4b: Kontenjan doluysa derse kayıt yapılamaz." Ana başarılı senaryo dümdüz başarıya giden yoldur; alternatif akışlar bu yoldaki sapmalardır.

**Sıra dışı durumlar.** Hata olduğunda yapılacaklar (exception handling) yazılır; örneğin bazı kayıtların geri alınması. Yazılmayabilir, ama yazılırsa daha iyi bir iş modeli ortaya konur.

**Özel istekler ve teknolojik beklentiler.** Özel istekler kalite kısıtlarıdır: bir işlemin belirli sürede yapılması, güvenlik için belirli bir protokol ya da algoritmanın kullanılması, birim zamanda belirli sayıda eş zamanlı kullanıcıya hizmet verilmesi. Teknolojik beklentiler ise belirli bir dil, platform, kütüphane ya da cihaz kullanılması gibi kısıtlardır.

> **Hocanın vurgusu:** Aktör tanımı, ön koşul, son koşul ve ana başarılı senaryo kesinlikle bulunur; alternatif akış çoğu zaman bulunur; diğerleri bazen bulunur.

Her senaryo için bu belge yazıldığında sistemin bütün sorumlulukları formal olarak tanımlanmış, iş modeli yazılmış olur. Bu metinler BRD'de ve sonra SRS'te gereksinim tanımları olarak birebir kullanılabilir. Hoca sonraki derste işlevsel çözümlemeyle birlikte, artık yaygın kullanılmayan ama temelini bilmekte fayda olan bir form tipinden de bahsedeceğini söyledi.

## 7. Senaryolar arası ilişkiler

### 7.1 Üç ilişki türü

Slayttaki tanımlar şöyledir (ekrandan, 01:00:00):

- **İçerme:** Birçok senaryo grubunda kullanılan başka bir senaryo grubu. Alt programa dallanıp geri dönmek gibi.
- **Genişletme:** Belirli koşulda ana senaryodan ayrılma noktasından sonra çalışan senaryo.
- **Özelleştirme:** Daha genel senaryodan özel senaryolar türetilir (ödeme → nakitle, kartla, çekle, ...).

**İçerme (include)**, login işlemleri ya da SMS atma gibi pek çok senaryoda tekrarlanan bir iş grubunun ayrı bir senaryo olarak modellenip gereken yerlerde çağrılmasıdır; bir fonksiyon çağrısına benzer. **Genişletme (extend)**, bir senaryoyu genişleten ve seçenekli olarak başka işlevlerin de yapılmasını sağlayan senaryodur. **Özelleştirme**, genel bir ödeme senaryosundan nakit, kart ya da çekle ödeme senaryolarının türetilmesi gibidir; ancak çoğu zaman bu da genişletmeyle ifade edilebilir. Bu yüzden en çok içerme ve genişletme kullanılır.

### 7.2 Bağıntı (association) ilişkisi

Önce senaryolar ve aktörler belirlenir, sonra ilişkilendirilir. Aktörle senaryo arasındaki ilişkiye **bağıntı ilişkisi** (association relation) denir. Bir aktör en az bir senaryoyla ilişkilidir; ilişkisi yoksa sistemde yeri yoktur. Bir senaryo birden fazla aktörle (birincil ve destek aktörleriyle) bağıntılı olabilir. Her araçta olmasa da, yönlü bir ok birincil aktörü, yönsüz bir çizgi destek aktörünü gösterir.

Hoca bunu iki senaryolu basit bir hastane örneğiyle açıkladı: hasta hem "tahlil verme" hem "tahlil sonucu alma" senaryolarının birincil aktörüdür. Tahlil vermede laboratuvar da vardır; laboratuvardaki test işlemleri için hizmet sunduğu için destek aktörüdür. Böylece "tahlil verme" senaryosu iki aktörle bağıntılıdır.

### 7.3 Genişletme ilişkisi

Slayttaki metin ve diyagram şöyledir (ekrandan, 01:15:00):

- (Extend Relation) bir senaryonun başka senaryolar ile ilişkilendirilerek yeni işlevler kazandırılması.
- Birkaç adımdan oluşan karmaşık işlevler için alt senaryolar **eklenti senaryolar** (extension use case) ile gösterilir.
- Genişletilmiş senaryo tek başına anlamlı olmalıdır. Eklenti olmadan da davranış sergileyebilmelidir.

Diyagram (Hastane Bilgi Sistemi):

| Kaynak | İlişki | Hedef |
|---|---|---|
| Hasta | birincil aktör (yönlü ok) | Tahlil Ver |
| Hasta | birincil aktör (yönlü ok) | Tahlil Sonucu Al |
| Laboratuvar | destek aktörü (yönsüz çizgi) | Tahlil Ver |
| Kısa Mesaj At | `<<genişlet>>` | Tahlil Ver |
| e-posta ile sonuçları gönder | `<<genişlet>>`, koşul: "Sonuçlar Çıktıysa" | Tahlil Sonucu Al |

"Tahlil Ver" senaryosu, tahlil yapıldığında hastaya ya da bir doktora SMS gönderilmesiyle genişletilmiştir: senaryo tek başına çalışır, istenirse SMS gönderme de dahil edilir. Benzer şekilde hasta normalde tahlil sonucunu sisteme girip ekranda görebilir; sonuçlar çıktıysa sonuçlar ayrıca e-postayla da gönderilebilir.

> **Hocanın vurgusu:** Ana senaryo her zaman tek başına anlamlı olmalıdır; hiçbir eklenti olmasa da bir sorumluluğu yerine getirebilmelidir.

### 7.4 İçerme ilişkisi

İçerme (include) Türkçede "ekleme ilişkisi" diye de çevrilebilir. Hoca örnek olarak "sıra numarası alma" senaryosunu verdi: bu kendi içinde bir senaryodur ve tahlil vermede, randevu almada, doktor muayenesinde ve başka pek çok yerde kullanılabilir. Ortak bir işlev olduğu için tek bir senaryo olarak tanımlanıp gereken yerlere eklenir. Aynı şekilde "kan verme" adımları da tahlil vermenin ve başka işlemlerin içine eklenebilir. Böylece ortak işlevler bir bileşen gibi düşünülür, aynı adımlar tekrar tekrar yazılmaz ve model basitleşir.

<!-- BELİRSİZ: İçerme ilişkisi slaytının karesi yok; örnekler altyazıdan alındı. -->

### 7.5 Aktörler arası genelleştirme

Senaryolar arasında değil, genellikle aktörler arasında kurulan bir ilişki daha vardır. Aynı işleri yapan aktörler varsa bunlar bir **genelleştirme** (kalıtım) ilişkisine konup ortak işlevler soyut bir aktörde tanımlanabilir. Örneğin ad, soyad ve kimlik numarası gibi ortak bilgiler soyut bir aktörde tutulup doktor ve hasta kendi özel özellikleriyle ayrı ayrı modellenebilir.

<!-- BELİRSİZ: Genelleştirme slaytında üst aktör altyazıda "laborant" olarak geçiyor ve doktorla hastanın bu aktörden türediği söyleniyor; karesi olmadığı için slayttaki aktör adları doğrulanamadı. -->

Hoca konunun erken olduğunu belirterek şunu ekledi: senaryolar teknik bir analiz modeline dönüştürülüp sınıflar keşfedilmeye başlandığında aktörler neredeyse her zaman birer sınıf olarak modellenir. Yani aktörler sistemin dışında kalan şeyler değildir, sistemin bileşenleri olarak da karşımıza çıkar.

Sistem sınırı dikdörtgenle gösterilir; sistemin adı dikdörtgenin üstüne yazılabilir ve bütün senaryolar dikdörtgenin içinde kalır. Çizilmesi zorunlu değildir.

### 7.6 Örnek: banka sistemi

Slayttaki diyagram şöyledir (ekrandan, 01:20:00):

| Kaynak | İlişki | Hedef |
|---|---|---|
| Customer | bağıntı | Open Account |
| Customer | bağıntı | Deposit Funds |
| Customer | bağıntı | Withdraw Funds |
| Bank Employee | bağıntı | Open Account |
| Calculate Bonus | `<<extend>>`, koşul: "Amount over 10,000 or Age over 55" | Deposit Funds |
| Deposit Funds | `<<include>>` | Update Balance |
| Withdraw Funds | `<<include>>` | Update Balance |
| NRFC Customer | genelleştirme (ok Customer'a) | Customer |
| NRFC Customer | bağıntı | Convert Currency |

Hoca diyagramı şöyle okudu: müşteri hesap açabilir. Okla gösterilmemiş olsa da birincil aktör müşteridir. Hesap açma bir senaryodur, çünkü belirli işlemlerin belirli sırayla yapılması gerekir; bankadaki memur (Bank Employee) da bu senaryoda birlikte çalışır, yani müşteri tek başına hesap açamaz. Para yatırma ve para çekme senaryolarını yalnız müşteri yapar. Para yatırılırken tutar 10.000'in (TL ya da dolar) ya da müşterinin yaşı 55'in üzerindeyse faizde artış gibi bir bonus hesaplanır: "Calculate Bonus" senaryosu "Deposit Funds"ı genişletir. Para yatırma her zaman tek başına çalışabilir, şart sağlandığında bonus hesabı da çalışır.

Hem para yatırma hem para çekme, hesaptaki bakiyenin güncellenmesi işlemini (Update Balance) içerir. Fatura ödeme gibi başka işlemlerde de bakiye güncellemek gerekir; bu senaryo her yerde içerilir ve adımlar tekrar yazılmaz. "NRFC Customer" Customer'dan türetilmiştir; hoca bunu döviz işlemleri yapabilen yabancı müşteri gibi düşünmeyi önerdi.
### 7.7 Modelin müşteriyle birlikte genişletilmesi

Use case modellemesi artımlı bir süreçtir; bütün aktör ve senaryolar ilk seferde görülemeyebilir. Hoca banka diyagramı üzerinde müşteriyle yapılan bir toplantıyı canlandırarak ekrana çizim yaptı:

- Müşteri, para yatırma ve çekme işlemlerinde mutlaka bir veznedarın (Clerk) bulunması gerektiğini söyler. Diyagrama yeni bir **Clerk** aktörü çizilir ve "Deposit Funds" ile "Withdraw Funds" senaryolarına bağlanır.
- Müşteri, veznedarların gün sonunda mutlaka para sayımı yapması gerektiğini söyler. Diyagrama **"End of day calculations"** senaryosu eklenir ve Clerk'e bağlanır; senaryonun adımları müşteriyle konuşularak yazılır.
- Senaryolar bir dikdörtgen içine alınır ve üzerine sistemin adı yazılır.

<!-- BELİRSİZ: Bu çizimler ders sırasında ekrana elle yapıldı; karede görünmüyor, eklenen öğeler altyazıdan aktarıldı. Hoca Bank Employee aktörünün dikdörtgenin içinde kaldığını da söyledi. -->

Böylece her toplantıda bir şeyler konuşularak iş uzayının basit bir şeması ortaya konur: hangi aktörler ve sorumluluklar var, kim kiminle ilişkili, hangi senaryolar genişletilebilir ya da ortak kullanılabilir, kalıtım gerekiyor mu, yeni aktör var mı.

## 8. Sözleşmeler (contracts)

Senaryolar her zaman yeterli olmayabilir; bazı karmaşık işlemler için ayrıca sözleşme (contract) yazılabilir. Hoca bunun biraz "uç nokta" olduğunu, ayrıntısına girmeden varlığının bilinmesini istediğini söyledi. Slayttaki maddeler şöyledir (ekrandan, 01:25:00):

- Bazı durumlarda karmaşık işlemlerin daha iyi anlaşılabilmesi için.
- Ön koşullar sağlandığında sistemin alacağı son durumun daha iyi açıklanmasını sağlar.
- Aktör-sistem etkileşimi yanında sistem içi nesnelerdeki değişim de belirtilir.
- İşlemler belirlenir. Karmaşık olanları için sözleşme yazılır.
- Önemli olan son koşullardır. (bir nesne yaratma yok etme, bir özellik güncellenmesi, bir bağlantı oluşturma-koparma)
- Modele bazı eklentiler (nitelik gibi) yapılmasına neden olabilirler.
- İşin nasıl yapılacağını göstermezler. O, tasarımın işidir.

Sözleşmeyi senaryonun son koşullarının daha açılmış, daha teknik hali olarak düşünmek mümkündür. Sıra şöyledir: önce senaryolar ve adımları yazılır, gerekiyorsa bazı adımlar için sözleşme eklenir. Sözleşme yazarken modele yeni bir şeyin eklenmesi ya da bir senaryonun değiştirilmesi gerektiği ortaya çıkabilir. Yine de "nasıl" sorusu her zaman tasarıma bırakılır.

**Örnek: çalışan çıkartma sözleşmesi.** Bir "bölüm kapama" senaryosu olsun: bir bölüm kapatıldığında derslikler fakülteye devredilir, bilgisayarlar ayniyata verilir ve bölüm personeli işten çıkarılır. İşten çıkarma tek adımda yapılabilecek atomik bir iş değildir, bu yüzden bunun için bir sözleşme yazılabilir. Sözleşmede hangi işlemin yapılacağı, kimin için yapılacağı, hangi senaryoda ve hangi koşulda çalışacağı ve son koşullar bulunur. Hocanın gösterdiği son koşullar şunlardır:

- Sistem tüm bölüm çalışanlarının tazminatını hesaplamıştır.
- Çalışanın iş yerine bağlantısı kesilmiştir.

Burada bir hesap vardır ama nasıl yapılacağı söylenmez; bu tasarımda çözülür. "Bağlantının kesilmesi" teknik olarak çalışan nesnesinin yok edilmesi anlamına gelir.

<!-- BELİRSİZ: Sözleşme örneği slaytının karesi yok; son koşullar altyazıdan aktarıldı. -->

## 9. Araştırma ve bilgi toplama yöntemleri

### 9.1 Genel bakış

Use case'leri çizerken ve senaryoların içini yazarken bilgiye nasıl erişileceği, işin nasıl yapıldığının nasıl öğrenileceği sorusu **bilgi toplama** konusudur. Slayttaki başlıklar şöyledir (ekrandan, 01:30:00):

- Araştırma sürecinde var olan sistemin eksik ya da yanlış anlaşılmaması için bilgi toplama önemlidir
- Gözleme Yaklaşımı
  - Mevcut belge-form-dosya örneklemesi
  - İş ortamı gözlenmesi
- Kişisel Görüşme Yöntemi (Toplantı, Mülakat, Ortak Gereksinim Planlaması)
  - Yapılandırılmamış görüşme
  - Yapılandırılmış görüşme
- Anket Yöntemi
  - Açık uçlu sorular
  - Kapalı uçlu sorular

### 9.2 Gözleme yaklaşımı

Hoca "gözleme yaklaşımı" adını kendisinin koyduğunu söyledi. Bu yaklaşımda analist iş ortamına gider, oturur ve bakar; mevcut belgeleri, formları, dosyaları ve iş yapılırken kullanılan bütün araç ve gereçleri gözler, örnekler (sampling). Böylece normal çalışma koşullarında işin nasıl yapıldığı adım adım görülür: önce telefonla bir şey konuşulur, sonra bir form doldurulur, form bir yere onaylatılır, ilgili birimlere gönderilir, gelen onaylara göre bir belge oluşturulur gibi. Analist hiçbir şeye karışmaz, "siz devam edin" der ve yalnız gözleyerek bilgi toplar.

### 9.3 Kişisel görüşme yöntemi

Kişisel görüşmeler toplantılar, mülakatlar ve ortak gereksinim planlaması (seminer tarzı oturumlar) şeklinde olabilir. Sistem analisti kullanıcıyla işin yapıldığı yerde karşılıklı görüşür ve soru sorar; bu kez yalnız bakılmaz, konuşarak öğrenilir. Dikkat edilecekler:

- Randevu alınmalı, konuya hazırlıklı gidilmeli; hiçbir şey bilmeden gidilmemeli.
- Konu başlıkları (gündem, agenda) belirlenmeli.
- Görüşmede mutlaka not tutulmalı ya da kayıt alınmalı.
- Hitap biçimine ve duruşa dikkat edilmeli; özensiz davranmak karşı tarafın güvenini sarsabilir.
- Görüşme sonunda neyin konuşulduğu, neyin konuşulmadığı, hangi konulara hiç değinilmediği ve gelecek görüşmelerin planı belirlenmelidir.

Görüşme bir ekiple toplantı, işi yapan kişiyle birebir mülakat, kişilerle ayrı ayrı mülakatlar ya da bütün heyetle bir seminer şeklinde olabilir.

### 9.4 Yapılandırılmış ve yapılandırılmamış görüşme

Yapılandırılmış görüşmenin özellikleri slaytta şöyledir (ekrandan, 01:35:00):

- Amaçlar saptanmış
- Kimle görüşüleceği belli
- Zamanı ve yeri belli
- Taraflara amaç, süre ve gerekli dokümanlar bildirilmiş
- Sorular belli
- Görüşmeden sonra en kısa zamanda sonuçlar değerlendirilip yorumlanmış
- Sonuçlar formal olarak yazılıp tüm ilgililere dağıtılmış

Bunlar yoksa görüşme **yapılandırılmamış** görüşmedir: amaç daha gevşektir, taraflar tam belli değildir ("şu kişi de olur, bu kişi de olabilir"), görüşme spontane gelişir, zamanı ve yeri anlık belirlenir, sorular tam belli değildir. Yapılandırılmamış görüşmenin sonunda da bir değerlendirme tutanağı hazırlamak faydalıdır.

Hoca iki türü şöyle karşılaştırdı:

| Özellik | Yapılandırılmış | Yapılandırılmamış |
|---|---|---|
| Değerlendirme kolaylığı | Kolay | Zor |
| Harcanan zaman | Az | Fazla |
| Spontane gelişme, yeni fikirler, rahat ifade | Az | Fazla |
| Esneklik | Az | Fazla |
| Görüşmeyi yapanın kontrolü | Fazla | Az |
| Doğruluk ve güvenilirlik | Fazla | Az |
| Genişlik ve derinlik | Az (sınırlar belli) | Fazla (her yere dallanabilir) |

> **Ders sonrası not:** Hoca genişlik ve derinlik karşılaştırmasında "yapılandırılmış görüşme her yere uzayabileceği için daha fazla" dedi; bağlama göre büyük olasılıkla "yapılandırılmamış görüşme" kastedilmiştir, tablo buna göre düzenlendi.

Konuşup karara bağlamak ya da belirli bir işin tam olarak nasıl yapıldığını öğrenmek için yapılandırılmış görüşme tercih edilmelidir. Müşteri muğlaksa, gereksinimini ifade edemiyorsa ya da analist iş alanını tam bilmiyorsa yapılandırılmamış görüşmeyle başlanabilir ve zamanla yapılandırılmış görüşmeler artırılabilir.

**Soru sıralaması.** Görüşmelerdeki sorular iki şekilde sıralanabilir:

- **Piramit yapı (tümevarım):** ayrıntılı ve kapalı uçlu sorulardan açık uçlu sorulara doğru gidilir. Seçenekli, şıklı sorularla başlanıp yoruma dayalı sorulara geçildiği için karşı tarafın konuya ısınması sağlanır.
- **Tümdengelim:** önce açık uçlu, yoruma dayalı sorular sorulur, giderek kapalı uçlu sorulara gidilir. Görüşme daha rahat bir sohbet şeklinde başlar. Karşı taraf konuya istekliyse ve fikirlerini serbestçe ifade edebiliyorsa bu yöntem daha doğrudur.

### 9.5 Anket yöntemi

Anket, son kullanıcıya yönelik paket programlarda (piyasaya açılacak uygulamalarda) ya da iş birimi çok büyük olduğu ve herkesle toplantı yapmanın mümkün olmadığı durumlarda tercih edilir. Slayttaki ilkeler şöyledir (ekrandan, 01:40:00):

- Sorular ve cevap alanlarından oluşan form
- Açıklık: Sorular tam ve açık olmalı, eksik olmamalı
- Hatırlatma: Değerlendirmede bilgi istenen olaydan geçen zaman, cevaplayan için önemi dikkate alınmalı
- Cevap arzusu oluşturma: Özel yaşamla ilgisiz, cevaplaması kolay, ilgi çekici sorular olmalı
- Hataya engel olma: Hatasız cevap için eleme sorusu ya da çoktan seçmeli cevaplama tercih edilmeli
- İfade kolaylığı: Görsel öğelerle istenen cevap desteklenebilir
- Cevaplayıcıyı şartlandırma: Şartlandırma olmamalı, seçim özgürlüğü bırakılmalı

Hatırlatma ilkesi, bilgi istenen olayın üzerinden çok zaman geçtiyse ya da cevaplayan için önemsizse anketin bunu hatırlatması gerektiği anlamına gelir. Hataya engel olmak için eleme soruları ya da aynı sorunun farklı biçimde tekrar sorulduğu kontrol soruları kullanılabilir. Şartlandırmaya örnek olarak hoca "Sizce de böyle olmamalı, değil mi?" gibi yönlendirici bir soruyu verdi; sorular net ve yönlendirmesiz olmalıdır.

**Avantajlar:** Çok sayıda kişiden, büyük bir kitleden veri toplanabilir; hızlı cevaplanır; maliyeti düşüktür; kimlikler gizli tutulabilir, bu yüzden katılımcılar daha rahat görüş ve öneri bildirebilir. Bu nedenle anket analiz hızını artırabilir.

**Dezavantajlar:** İyi yapılandırılmamışsa az kişi cevaplar ya da yarıda bırakır; herkes bütün soruları cevaplamayabilir ve bazı alanlar zayıf kalır; kimlik gizli değilse esneklik azalır. Toplantı ya da gözlemde olduğu gibi vücut dili analiz edilemez: kişinin işi severek mi, zorlanarak mı yaptığı görülemez. Sorular bulanıksa net bilgi elde edilemez.

### 9.6 Açık uçlu ve kapalı uçlu sorular

**Açık uçlu sorular**, cevaplayıcının kendi ifadeleriyle yanıt verdiği serbest metin sorularıdır.

- Avantajlar: seçenekli sorularla alınamayacak fikir ve görüşler, işin yapılışıyla ilgili önemli noktalar öğrenilebilir; cevaplayıcının bakış açısı, endişeleri ve iş öncelikleri daha iyi anlaşılır; cevaplayıcı duygularını daha rahat ifade eder.
- Dezavantajlar: yazmak zaman alıcı ve yorucudur, kaçamak ya da eksik yanıtlar gelebilir; verilerin okunup anlamlandırılması çok zaman alır; eğitim ve deneyim seviyesi cevabın kalitesini etkiler; sayısal bilgi almak zordur. Bunun için "en iyi ve en kötü üç madde" ya da "önem sırasına göre sıralayın" gibi sıralama veya puanlama soruları kullanılabilir.

**Kapalı uçlu sorular** için slayttaki maddeler şöyledir (ekrandan, 01:45:00):

- Cevaplayıcıdan sabit cevap seçenek kümesinden seçim ister. Çoktan seçmeli, iki cevaplı, sıralamalı olabilir.
- Avantajlar
  - Cevap çok kolay ve hızlı bulunur
  - Kodlanması ve işlenmesi sorunsuzdur
  - Cevap olasılıklarını anketin amacıyla ilgili olacak şekilde sınırlar
  - Herkese aynı bakış açısını iletir, cevaplayıcının yorumlama etkisini devre dışı bırakır
  - Hatırlamayı kolaylaştırır: Hangi eğitimleri aldınız sorusu şıklarıyla olunca insan kolay hatırlar
- Dezavantajlar
  - Cevaplayanlar konuyla ilgili gerçek duygularını yansıtmayan seçeneklere maruz kalabilir. Gerçek cevabına benzeyen şıkkı seçerek ince ama önemli farklılıkları yok eder.
  - Kişinin cevabı yoksa da, soruyu anlamasa da cevaba zorlar
  - Soruların çoğu kapalı uçlu olursa görüşlerin ifadesine izin verilmediğinden cevaplayıcılar kendilerini engellenmiş hisseder

Hoca kapalı uçlu soruların otomatik olarak, örneğin bir çevrimiçi form aracıyla bile işlenebileceğini söyledi. Hatırlatma örneğinde, hangi sertifika programlarına katıldığını unutan biri bir liste görünce kolayca işaretleyebilir.

İki tür şöyle karşılaştırılır:

| Özellik | Kapalı uçlu | Açık uçlu |
|---|---|---|
| Cevaplama hızı | Yüksek | Düşük (yazma gerekir) |
| Bilginin genişliği ve derinliği | Az | Fazla (her tür bilgi alınabilir) |
| Hazırlama | Zor | Kolay |
| Okuma ve analiz | Kolay | Zor |

Hoca bunu sınav hazırlamaya benzetti: test sorusu hazırlamak zordur ama okuması kolaydır, çünkü sistem okuyabilir; klasik soru hazırlamak kolaydır ama okuması saatler alır. İki tür soru dengeli ve amaca uygun kullanılmalıdır.

**Soruların sıralanması.** Anket soruları genelden özele ya da özelden genele sıralanabilir; genellikle genelden özele gitmek daha doğrudur. Basitten zora sıralanırsa tepki azalır. Sorular mantık sırasında olmalı, önceki sorular sonrakilere hazırlık yapmalı; daldan dala atlamak ve ani konu değişiklikleri cevaplayanı şaşırtıp yanlış cevaplara yol açabilir. Geniş kitlelere yönelik anketler sıkmayan, özendirici ve kendini ifade etmeye imkan tanıyan seçeneklerle hazırlanmalıdır.

Özetle üç bilgi toplama yöntemi vardır: bakma ve gözleme; kişisel ya da grup halinde karşılıklı görüşme; yüz yüze olmayan anket. Bunlar işin ne olduğunu ve nasıl yapıldığını öğrenmek için kullanılır; öğrenilen iş, use case modellemesi gibi bir yöntemle modellenir.

## 10. İş gereksinimleri dokümanı (BRD) ve araştırma raporu

### 10.1 BRD içeriği

Toplanan bilgiler ve senaryolarla modellenen iş gereksinimleri bir **iş gereksinimleri dokümanı** (Business Requirements Document, BRD) ile rapor haline getirilir. Slayttaki içerik şöyledir (ekrandan, 01:50:00):

- Özet
- Amaç, hedef
- İhtiyaç (Sistem neden lazım)
- Kapsam (Sınırlar)
- Mali analiz
- İşlevsel Gereksinimler (Üst seviyeli)
- Kaynak ihtiyacı
- İş Zaman Planı
- Maliyet-Fayda Analizi

Bunların hepsinin her zaman bulunması gerekmez. İhtiyaç maddesi project charter'da da geçen "sistem neden lazım?" sorusunun cevabıdır. Kapsam, neyin yapılıp neyin yapılmayacağını belirler. Mali analiz ve maliyet-fayda analizi doğrudan ekonomik fizibiliteden alınabilir; kaynak ihtiyacı (kişi ve teknik) ve iş zaman planı da zaman planından gelir.

> **Hocanın vurgusu:** BRD'deki en önemli kısım işlevsel gereksinimlerin üst seviyede modellenmesidir. Burada senaryoların içi değil, senaryoların kendileri ve ön koşul, son koşul gibi basit tanımları yeterlidir; senaryoların tamamı SRS'te tanımlanır.

### 10.2 Alternatif: araştırma raporu

BRD'nin alternatifi daha genel bir raporlama biçimi olan **araştırma raporu**dur. Slayttaki yapı şöyledir (ekrandan, 01:50:00):

- Teknik personel için bilgi toplama sonuçlarının teknik raporu
  - Başlık: yürütücü
  - İçindekiler
  - Araştırma amacı
  - Araştırma metodolojisi (yöntem, işlem, analiz, yorum)
  - Sonuç ve öneriler
  - Ekler (veri toplama formları, tablolar, grafikler, bibliyografya)
- Yönetici için özet rapor (Teknik rapordan sonra)
  - Araştırmanın amacı
  - Kullanılan yöntem
  - Elde edilen sonuçlar

Yönetici özeti (executive summary) teknik rapor bittikten sonra yazılır ve amaç, yöntem ve sonuçları özetler. Teknik rapor daha uzun ve daha tekniktir; ekler bölümünde formlar, tablolar, grafikler ve anket sonuçları yer alabilir. Bu derste odakta olan çıktı BRD'dir.

### 10.3 Örnek BRD: web sitesi gereksinimleri

Hoca öğrencilerin internette "business requirements document" araması yapıp farklı örneklere bakmasını önerdi ve 2014 tarihli örnek bir belgeyi gösterdi. Belge, iş ortaklarının birlikte çalışmasını sağlayan bir derneğin web sitesi için gereksinim tanımlarını içerir. Yapısı şöyledir:

- **İçindekiler:** genel bakış, paydaşlar (stakeholders), işlevsel gereksinimler, işlevsel olmayan gereksinimler.
- **Değişiklik geçmişi:** sürüm, yazan, kontrol eden, tarih ve açıklama. Belge sürümlendirilir (ilk sürüm, bir toplantıdan sonraki sürüm gibi) ve değişiklikler tabloda izlenir.
- **Giriş / genel bakış:** sistemin ne yaptığını anlatan kısa bir metin.
- **Paydaşlar:** kim oldukları, hangi organizasyondan oldukları ve rolleri; bunlar aslında aktörlerdir.
- **Etkilenen iş süreçleri:** yeni üye kaydı, üyelik yenileme, iletişim ve yorum yapma gibi kapsamdaki süreçler; bunların dışındakiler sistem sınırı dışındadır.
- **Kısıtlamalar, varsayımlar, riskler:** istenirse eklenebilir.
- **İşlevsel gereksinimler tablosu:** gereksinim kimliği (use case kodu gibi), gereksinim cümlesi, Must/Want önceliği ve yorum. Örneğin ana sayfanın organizasyonun amacını göstermesi ve önümüzdeki toplantıları listelemesi "Must", kaynaklar/bağlantılar sayfası "Want" olarak işaretlenmiştir. Bir yorumda, bilgi toplama sırasında üyelerin bilgilerinin bulunduğu bir hesap tablosu dosyasının elde olduğu ve doğrudan veri tabanına aktarılabileceği not edilmiştir.

İşlevsel olmayan gereksinimler tablosu karede şöyledir (ekrandan, 01:55:00):

| Requirement ID | Requirement Statement | Must/Want |
|---|---|---|
| NF001 | The website shall cost less than \$1,000 to build. | Must |
| NF002 | The website shall cost less than \$300 per year to host / maintain. | Must |
| NF003 | The website shall be secure from hackers. | Must |
| NF004 | The website shall be backed up nightly and be able to be restored on one hour's notice. | Must |
| NF005 | The website will be ready to launch within 60 days of securing a vendor. | Want |

Hoca işlevsel olmayan gereksinimlerin sistemin sunduğu hizmetler olmadığını, ama sistemi ayakta tutan, kaliteli olmasını sağlayan ve tasarımı doğrudan etkileyen gereksinimler olduğunu vurguladı. İşlevsel gereksinimler tablosu aslında senaryoların bir "niyet beyanı"dır; senaryoların ayrıntısı SRS'te yazılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:40:36): Aktörsüz bir senaryo olabilir mi? Hiçbir senaryoyla ilişkisi olmayan bir aktör modellenmeli mi?

> **Cevap (derste verildi):** Bir senaryo başka bir senaryoya bağlı olarak doğrudan aktörsüz görünebilir, ama dolaylı olarak yine bir aktörle etkileşir; bu yüzden aktörsüz senaryo yoktur. Hiçbir senaryoyla etkileşmeyen bir taraf sistemin parçası değildir, aktör olarak modellenmez.

**Soru 2** (ekrandan, 00:45:00 ve derste sözlü, 00:51:13): Okul servisi sisteminin use case diyagramında "Find arrival times" senaryosu var. Bu senaryonun belgesi hangi bölümlerden oluşur ve nasıl yazılır?

> **Cevap (derste verildi):** Önsözde kod ve ad (UC1: Find arrival times), birincil aktör, ilgililer ve beklentileri, ön koşullar ve son koşullar yazılır. Ardından koşulsuz ve dallanmasız ana başarılı senaryo, etken cümlelerle ve kimin ne yaptığı belirtilerek adım adım yazılır. Sapmalar alternatif akışlarda (4a, 4b gibi), hatalar sıra dışı durumlarda, kalite kısıtları özel isteklerde, dil ve platform kısıtları teknolojik beklentilerde verilir. Aktör, ön/son koşul ve ana başarılı senaryo mutlaka bulunur.

**Soru 3** (ekrandan, 01:20:00 ve derste sözlü, 01:21:59): Banka use case diyagramı müşteriye gösterildiğinde müşteri iki istekte bulunur: para yatırma ve çekmede mutlaka bir veznedar bulunmalı ve veznedarlar gün sonunda para sayımı yapmalıdır. Diyagram nasıl güncellenir?

> **Cevap (derste verildi):** Yeni bir Clerk aktörü eklenir ve Deposit Funds ile Withdraw Funds senaryolarına bağıntı ilişkisiyle bağlanır. Yeni bir "End of day calculations" senaryosu eklenir ve Clerk'e bağlanır; bu senaryonun adımları müşteriyle birlikte yazılır. Senaryolar sistem sınırı dikdörtgeni içine alınır.

**Soru 4** (ekrandan, 01:20:00): Banka diyagramında "Calculate Bonus" ile "Deposit Funds" arasında ve "Deposit Funds"/"Withdraw Funds" ile "Update Balance" arasında hangi ilişkiler vardır, neden?

> **Cevap (derste verildi):** "Calculate Bonus", "Deposit Funds"ı `<<extend>>` ile genişletir: para yatırma tek başına çalışır, yalnız tutar 10.000'in ya da yaş 55'in üzerindeyse bonus hesaplanır. "Deposit Funds" ve "Withdraw Funds", "Update Balance"ı `<<include>>` ile içerir: bakiye güncelleme her iki işlemde (ve fatura ödeme gibi başka işlemlerde) ortak olarak çalışan bir alt senaryodur, adımları tekrar yazılmaz.

## Dersin Toparlaması

Bu derste analiz aşamasına giriş yapıldı. Gereksinim analizi, problemi ve sistemin sorumluluklarını tanımlayan ve sonunda SRS belgesini üreten süreç olarak tanımlandı; gereksinimlerin önceden bilinip bilinmemesine göre akış diyagramları ya da prototip yaklaşımının seçileceği, sürecin BRD ve SRS üzerinden teknik ve idari incelemelerle tasarıma bağlandığı anlatıldı. İş analizinin formal yolu olarak use case modellemesi ayrıntılı işlendi: aktörler, senaryolar, sistem sınırı, senaryo şablonu (önsöz, ana başarılı senaryo, alternatif akışlar, sıra dışı durumlar, özel istekler, teknolojik beklentiler), include/extend/genelleştirme ilişkileri ve karmaşık işlemler için sözleşmeler. Ardından senaryoları yazmak için gereken bilgiyi toplama yöntemleri (gözleme, yapılandırılmış ve yapılandırılmamış görüşme, açık ve kapalı uçlu sorularla anket) ve toplanan bilginin BRD ya da araştırma raporu ile raporlanması gösterildi.

Sonraki derste sistem analizine fonksiyonel çözümleme ve SRS belgesinin içeriğiyle devam edilecek; ardından kavramsal problem uzayının nesneye yönelik olarak nasıl modelleneceği ve senaryoların nasıl gerçekleneceği işlenecek, böylece gereksinim analizi üç haftada tamamlanacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
