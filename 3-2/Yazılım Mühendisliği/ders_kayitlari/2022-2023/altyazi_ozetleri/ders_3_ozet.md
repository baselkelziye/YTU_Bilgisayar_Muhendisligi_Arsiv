# Ders 3 Çalışma Özeti

## Genel Konular

- Sınav ağırlıkları ve dönem projesinin tanıtımı.
- Üç proje konusu: seyahat acentesi bilet ve tatil sistemi, yazılım evi insan kaynakları sistemi, medya takip sistemi.
- Analiz ve tasarımın önemi: "salıncak hikâyesi".
- Sistem geliştirme yaşam döngüsü (SDLC) ve yazılım geliştirme yaşam döngüsü.
- Temel ve destek (şemsiye) aktivitelerinin tekrarı. Ölçmenin önemi.
- CASE araçları: üst, orta ve alt CASE.
- Süreç sertifikasyonu: CMM, CMMI ve düzeyleri. Türkiye'deki durum.
- Nesneye yönelik gereksinim analizine giriş: kullanıcı hikâyeleri, use case belgesi ve diyagramı.
- Fonksiyonel ve fonksiyonel olmayan gereksinimler.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Projede her şey nesneye yönelik yapılacak:** analiz, modelleme, tasarım ve kodlama. Sistem Analizi dersindeki gibi klasik yöntem seçme serbestliği yok.
- **En az bir modül kodlanacak ve çalıştırılarak gösterilecek.** Sistemin tamamının çalışması gerekmiyor.
- **Diyagramlar mutlaka bir araçla çizilecek.** Önerilen araç Violet UML. Amaç hem standart çizim hem de diyagramlar arası geçişte (use case → sınıf → sıralama) tutarlılık.
- **Grubu kurmak öğrencilerin sorumluluğunda.** Hoca listeden grup oluşturmayacak. Bildirilen grup sonradan büyütülemez. Grupta ders bırakan olursa kalanlar işi bitirir.
- **Grupta herkes aynı notu almayabilir.** Sunumda her üye her soruya cevap verebilmeli.
- **Varsayım ve kısıtlar yazılabilir, ama projeyi küçültecek varsayımlar kabul edilmez.**
- **Müşteri işi basitten karmaşığa anlatmalı.** Analistin de iletişim ve soru sorma becerisi iyi olmalı.
- **Belgeleme yoksa** sonradan sisteme müdahale etmek çok zorlaşır, tersine mühendislik (re-engineering) gerekir.
- **Use case diyagramı tek seferde ayrıntılı çizilmez.** Önce özet diyagram, sonra kademe kademe ayrıntı.
- Sınavda verilen bir senaryonun use case diyagramını ve belgesini yazabilmeniz bekleniyor.
- **CMMI 2. düzeyde konfigürasyon yönetimi, 3. düzeyde risk yönetimi şarttır.** İhalelerde genellikle en az 3. düzey istenir.

## Kısa Tekrar Notları

- **Not dağılımı:** 1. vize %25, 2. vize (kısa test) %15, proje %20, final %40.
- **Proje teklifi son tarihi:** 4 Nisan. E-postayla grup üyelerinin adları, numaraları ve seçilen konu gönderilecek.
- **Proje raporu ve kod:** 15 Mayıs (fiilen 14 Mayıs akşamı). Online Yıldız'a ayrı ayrı yüklenecek.
- **SDLC temel işlemleri:** gereksinim analizi, tasarım, gerçekleme, test.
- **Şemsiye aktiviteleri:** proje yönetimi, risk yönetimi, kalite yönetimi, konfigürasyon yönetimi, ölçme.
- **Ölçme ne işe yarar?** Karmaşıklık ve büyüklük ölçümü, çalışan verimliliği, geçmiş projelerin verisiyle yeni projelerde maliyet tahmini.
- **CASE katmanları:**
  - Üst CASE: diyagram çizimi ve tanımlama.
  - Orta CASE: analiz ve tasarım.
  - Alt CASE: kod üretme ve kod çevirme.
  - Hepsi ortak bir veri deposundan (veri modelleri, veri sözlüğü) beslenir.
- **CMMI düzeyleri:** 0 Yürütülmeyen, 1 Giriş, 2 Yönetilen/Yinelenebilir, 3 Tanımlanmış, 4 Nicel yönetilen, 5 İyileştirilen.
- **Use case belgesi:** ad, seviye, birincil aktör, ön koşullar, paydaşlar ve ilgileri, ana başarı senaryosu (sıralı adımlar).
- **Fonksiyonel gereksinim:** Sistemde yapılan işler, işin adım adım nasıl yapıldığı.
- **Fonksiyonel olmayan gereksinim:** Kaliteyle ilgili kurallar. Örnek: performans, yanıt süresi, güvenlik.

## Detaylı Açıklamalar

### Sınavlar ve Not Dağılımı

| Bileşen | Ağırlık | Açıklama |
|---|---|---|
| 1. ara sınav | %25 | Genellikle klasik. Genel sorular ve bir uygulama sorusu. Gereksinim analizine kadar olan konular. |
| 2. ara sınav (kısa sınav) | %15 | Test. Tüm konulardan kısa sorular. İkinci sınav haftasında. |
| Proje | %20 | Ekip çalışması, rapor, kod ve sunum. |
| Final | %40 | |

- Hoca, sınavların yapılış biçimiyle ilgili o dönemdeki belirsizlik nedeniyle ağırlıkların güncellenebileceğini söyledi.

### Dönem Projesi

**Genel kurallar:**

- Sistem Analizi dersinden farkı: Konuları hocalar veriyor. Üç farklı konu var.
- Gruplar 5 kişilik. 6 kişi olmak isteyenler kapsamı genişletmeli, örneğin bir modül daha kodlamalı.
- Her konuyu birden fazla grup yapabilir. Hoca konulara düşen grup sayısını eşitleyecek. İlk bildiren gruplar öncelik alır.
- Diğer şubenin (Yunus Hoca'nın) öğrencileriyle karma grup kurulması istenmiyor. Notlandırmayı zorlaştırıyor.
- Grubu olmayanlar için hoca 4 Nisan'dan önceki derste bir duyuruyla yardımcı olabilir.
- Duyurular Online Yıldız'ın duyuru/duvar sayfasından yapılacak.
- Sunumlar iki hafta sürecek. Birinci sunum günü test sınavıyla aynı gün.

**Projede istenenler:**

- **Proje planı:**
  - Projenin kabul kısıtları ve proje alanı.
  - İş zaman çizelgesi (Gantt diyagramı).
  - Ekip organizasyon tablosu.
  - Risk tablosu.
- **İsteklerin modellenmesi:** Kullanım senaryosu (use case) belgesi ve use case diyagramı.
- **Sınıf diyagramı (class diagram).**
- **Nesneye dayalı tasarım:**
  - Senaryolar sınıf, sıralama (sequence), etkinlik (activity) ve durum (state) diyagramlarıyla zenginleştirilecek.
  - Tasarım kalıbı (design pattern) kullanıldıysa hangisi olduğu belirtilecek.
- **Kodlama:** Seçilen en az bir modül, istenen dilde ve platformda, nesneye dayalı olarak kodlanacak.
- **Birim testi:** Kodlanan modül için iki birim testi tasarlanacak ve raporla birlikte kaynak kodlara eklenecek.
- **Araç:** Diyagramlar elle değil, bir CASE aracıyla çizilecek. Violet UML öneriliyor. Açık kaynaklı.

**Proje konuları:**

1. **Seyahat acentesi bilet ve tatil sistemi:**
   - Havayolu, demiryolu ve tur biletleri satılıyor. Başka firmaların biletleri de satılabilir.
   - Bilet aldıkça ve tatile gittikçe puan biriken bir puan sistemi var. Biriken puanlar ödemede kullanılabiliyor.
   - Ödeme türleri: nakit, kredi kartı, çek.
2. **Yazılım evi insan kaynakları sistemi:**
   - Çalışanların bilgileri tutuluyor. Çalışan kaydı yapılıyor.
   - Yönetimin başlatıp bitirdiği projeler ve bu projelerin insan kaynağı takibi.
   - Görevler: analist, tasarımcı, programcı, yönetici.
   - Biten projeden çıkan çalışan başka projeye atanabilir ya da işten çıkarılabilir.
   - Maaş ve tazminat hesapları muhasebe programına bırakılıyor. Bu proje bu hesaplara girmiyor, yalnızca çalışanın hangi grupta olduğunu atıyor.
3. **Medya takip sistemi:**
   - Şirket radyo, televizyon, gazete ve dergileri takip ediyor. İnternet siteleri ve bloglar da eklenebilir.
   - Müşteriler şirket ya da şahıs olabilir.
   - Standart raporlar günlük, haftalık, aylık. Fiyatları belli.
   - Müşteriye özel raporların periyodu ve fiyatı anlaşmada belirlenir ve sonradan değişmez.
   - Takip edilen medya organları bir veri tabanında tutulur. Yeni çıkanlar eklenir, değişenler güncellenir, kapananlar silinir.
   - Şirket müşterilerin itibarı ve bilinirliği hakkında anketler düzenler. Anketler ayrıca ücretlendirilir. Kayıtlı anketörlerin iş planı sistem üzerinden yapılır.
   - Medya organları ortak bir arayüzle sorgulanır. Rapor belge olarak müşteriye gönderilir.

- **Modüller hocalar tarafından verilmiyor.** Gruplar kendileri belirleyecek.
  - Seyahat acentesi için örnek modüller: ödeme, rezervasyon, puan sistemi. Puanların sonraki bilet alımında kullanılması da işin içinde.
  - Medya takip için örnek: müşteri ve anlaşmalar, takip edilecek medya organlarının seçimi, ikisinin eşleştirilmesi.
- **Uygulamanın kapsamı:** Programa girişte tüm modüllere yönlendirme olabilir. Ama yalnızca seçilen modül çalışacak ve dönem sonunda gösterilecek.

**Uygulama (lab) dersleri:**

- Araştırma görevlileriyle iki uygulama dersi yapılacak.
- Bu derslerde gereksinim analizi diyagramları, durum ve etkinlik diyagramları örneklerle çözülecek. Özellikle Nesneye Yönelik Programlama dersini almamış öğrenciler için önemli.
- Hoca, laboratuvarın 12. haftadan 11. haftaya alınmasını düşünüyor. Yazılım ölçütleri konusu diyagramlarla bağımsız olduğu için yer değiştirilebilir.

### Analiz ve Tasarım Neden Önemli? (Salıncak Hikâyesi)

- Müşteri yalnızca bir ağaca basit bir salıncak istiyor.
- Ama işini kendi dünyası etrafında çok karmaşık anlatıyor.
- **Zincirleme hata:**
  1. Proje lideri yanlış anlıyor.
  2. Analist daha da karmaşık bir gereksinim çıkarıyor.
  3. Tasarımcı hatalı tasarlıyor.
  4. Programcıya hatalı aktarılıyor.
  5. Sonuçta istenmeyen bir ürün çıkıyor.
- Belgeleme (sınıf diyagramı, ER diyagramı, veri tabanı yapısı) yoksa sonradan düzeltmek çok zorlaşır. Tersine mühendislik (software re-engineering) gerekir.
- **Ders:** Müşteri istediğini basitten karmaşığa anlatmalı. Karmaşık süreçleri sorulduğunda açmalı. Analist de iyi iletişim kurup doğru sorular sormalı. Bu, çevik ilkelerdeki basitlikle de uyumludur.

### Sistem Geliştirme Yaşam Döngüsü

- Yazılım, bir kurum içinde yaşayan bir sistem olarak görülmelidir. Önce kurumun yapısı ve çalışma sistemi anlaşılır. Sonra hangi uygulamalara hangi sırayla ihtiyaç olduğu belirlenir.
- **Proje:** Planlanmış başlangıcı ve sonu olan, bir sonuca ulaşmak için yapılan işlemler.
- **Bilgi sistemi geliştirme projesi:** Bilgi sistemini üretmek için planlanmış alt işlemler.
- **SDLC (System Development Life Cycle):** Donanım ve yazılımı birlikte kapsayan genel çerçeve. Yöntemler ve kontrol listeleri (checklist) verir.
- **Software Development Life Cycle:** Yalnızca yazılımın geliştirilmesi.
- **Temel işlemler:** gereksinim analizi → tasarım → gerçekleme → test.
  - Analizde: Bilgi ihtiyaçları neler? Sistemde hangi işler yapılıyor? Bu işlemlerle veri arasında nasıl bir ilişki var?
  - Gerçekleme: kodlama, veri tabanının hazırlanması, birim testleri.
- **Şemsiye aktiviteleri:**
  - Proje yönetimi: planın yapılması, takip edilmesi, kapatılması.
  - Risk yönetimi: risklerin takibi.
  - Kalite yönetimi: gözden geçirmelerin planlanması.
  - Konfigürasyon yönetimi: değişikliklerin ve elemanlar arası ilişkilerin takibi.
  - Ölçme.
- **Ölçmenin kullanım alanları:**
  - Algoritma ve program karmaşıklığı, program ve kod büyüklüğü.
  - Çalışanların verimliliği, yapılan işin büyüklüğü.
  - Yeni bir işe başlarken eski ölçüm sonuçlarıyla maliyet tahmini.

### CASE Araçları

- CASE, yazılım mühendisliği işlerinin bilgisayar yardımıyla yapılmasıdır. Temel ve destek adımlarını iyileştirir.
- Grafik bir ortam sağlamalı.
- **Katmanlar:**
  - Üst CASE (upper CASE): diyagram çizimi ve tanımlama araçları.
  - Orta CASE: analiz ve tasarım.
  - Alt CASE (lower CASE): kod üreticiler ve kod çeviriciler.
- Hepsi bir "ansiklopedi" (repository) kullanır: veri modelleri, veri sözlüğü, işler, sistemler, fonksiyonlar.
- **Bütünleşik CASE araçları** (ör. Rational Unified Process platformu) her aşamada, test dahil destek verir. Pahalıdırlar, ancak büyük kurumsal firmalar satın alabilir.
- Belirli aşamalar için daha küçük ve açık kaynaklı araçlar da vardır:
  - Yalnızca analiz/tasarım diyagramı çizenler (ör. Violet).
  - Yalnızca teste ya da kod kalitesine destek olanlar.
  - Yalnızca kod üretenler.
- Kod üreticiler dördüncü kuşak dillerle yazılımı hızlandırabilir. Yine de bizim analiz ve tasarımımıza ihtiyaç duyarlar.
- **MS Project** bir CASE aracı değil, genel amaçlı bir proje yönetim aracıdır. Gantt ve PERT diyagramları çizer, her türlü projeye destek verir.

### Süreç Sertifikasyonu: CMM ve CMMI

- Üniversite bölümlerinin MÜDEK akreditasyonu gibi, yazılım evlerinin de süreçlerini ne kadar iyi uyguladığını gösteren süreç sertifikasyonları vardır.
- Avrupa'da ve Amerika'da farklı sistemler var. Amerika'daki: **CMMI (Capability Maturity Model Integration)**.
- **Tarihçe:**
  - İlk başta yalnızca yazılım geliştirme için CMM (Capability Maturity Model) vardı.
  - Sonra geliştirme, hizmet (service) ve ürün/hizmet alımı (acquisition) alanları CMMI'da birleştirildi.
  - 2010'dan itibaren çevik süreçleri desteklemeye başladı.
  - 2018'de üç alan tek bir olgunluk modelinde birleştirildi ve sürekli iyileştirme hedeflerine göre yapılandırıldı.
  - Ayrı yürütülen People CMM de sonradan CMMI'ya katıldı. Bu bölüm çalışanlara sağlanan olanakları ölçer: işe alım, doğru göreve yerleştirme, kariyer planı, ölçümleme.
- **Ne işe yarar?**
  - Yazılım firması süreçlerini bağımsız kurumlara onaylatıp sertifika alır.
  - İhalelere girmeyi kolaylaştırır. Örneğin askeri yazılımlar için CMMI 3 şartı aranabilir.
  - Küçük yazılım evleri için zorunlu değil. Ama CMMI süreçlerini inceleyip kendilerine göre yorumlayabilirler.
- Sertifikasyon ücretlidir. Firma başvurur ve kurallarını yerine getirmeye çalışır.
- **Diğer standartlar:** ISO 9001, yazılım süreciyle ilgili standartlar, PMI'ın proje yönetimi standartları. Bunlar proje ve kalite yönetimi konularında görülecek.

**CMMI düzeyleri (slayttan):**

| Düzey | Ad | Özellik |
|---|---|---|
| 0 | Yürütülmeyen (Incomplete) | |
| 1 | Giriş düzeyi (Initial/Performed) | İş şansa ve anahtar kişilere kalmış. Etkinliklerin tümü yürütülüyor ama tanımlanması için sistematik girişim yok, her seferinde farklılaşabilir. |
| 2 | Yönetilen/Yinelenebilir (Managed/Repeatable) | Temel planlama ve izleme yöntemleriyle önceki projelerdeki başarılar yeni projelerde tekrarlanabilir. |
| 3 | Tanımlanmış (Defined) | Kişi ve risk yönetimiyle proje yönetimi iyileştirilir. Tüm organizasyonda standart süreçler tanımlanmıştır. Büyük müşteriler en az bu düzeydeki yazılım evleriyle çalışmak ister. |
| 4 | Nicel yönetilen (Quantitatively Managed) | Süreç ve yazılım ölçütleriyle kalite yönetimine geçilir. İlerleme sürekli izlenir, bütçe ve zaman sapmaları erken belirlenir. |
| 5 | İyileştirilmiş (Optimizing) | Süreç yönetimi geçmiş deneyimlerin ışığında sürekli iyileştirilir. |

- Düzeyler birbirinin üzerine eklenir. 4. düzeydeki firma ilk üç düzeyin gereklerini zaten yapar.
- **2. düzey:** Proje planlama, analiz ve tasarım belgeleri ve mutlaka konfigürasyon yönetimi (değişiklik yönetimi sistemi).
- **3. düzey:** Bunlara ek olarak risk yönetimi ve organizasyon genelinde standart süreç modeli takibi.
- **4. düzey:** Ölçme ön plana çıkar. Geçmiş projelerin veri tabanından (büyüklük, süre, iş gücü) yararlanılarak maliyet tahmini kişisel deneyimden değil, sayısal verilerden yapılır.
- **5. düzey:** Süreçler, teknikler ve araçlar sürekli optimize edilir. Çalışanlardan gelen yeni fikirler değerlendirilir.
- **Anahtar süreç alanları (Key Process Areas, KPA):** Bir firmanın hangi düzeyde olduğu bu alanlara bakılarak belirlenir.

**Türkiye'deki durum (hocanın aktardığı):**

- Milsoft (Ankara, askeri yazılım) ve TÜBİTAK BİLGEM: 5. düzey.
- ASELSAN, Cybersoft, HAVELSAN, Koç Sistem: 3. düzey.
  - Cybersoft bankacılık yazılımı yapan, süreçlere önem veren bir firma.
- ETİYA 2020'de 3. düzeyi almış. Teknoparklardaki bazı firmalar da 3. düzeye göre çalışıyor olabilir.
- Siemens CMMI kullanıyor. Test süreçleri için TMMi (Test Maturity Model integration) sertifikası da var. Çevik yaklaşımla TMMi 5 uygulama aşamasındalar.

### Nesneye Yönelik Gereksinim Analizine Giriş

- Kaynak: Craig Larman'ın kitabı ve sunumları.
- **Fonksiyonel gereksinimleri yakalamanın bir yolu kullanıcı hikâyelerini dinlemektir.**
- Önce temel olarak ne istendiği alınır. Sonra temel bir use case ve diyagram oluşturulur. Ardından kademe kademe ayrıntıya inilir. Farklı use case seviyeleri tanımlanır.
- **Use case:** Sistemi kullananların gerçek hayatta bir hedefi gerçekleştirmek için yaptıkları.
- **Bir hikâyeden çıkarılacaklar:**
  - Birincil aktörler (primary actors), destek aktörleri, dış elemanlar.
  - Olayın kısa tanımı.
  - Sırayla gerçekleşen iş adımları.
  - Sistemin aldığı bilgi, yaptığı işlem ve verdiği çıktı.
- **Örnek (video kiralama):**
  1. Müşteri video kiralamak ister.
  2. Görevli müşterinin kimliğini (ID) ve her videonun ID'sini girer.
  3. Sistem kiralama bilgisini çıktı olarak verir.
  4. Sistemden kiralama raporu alınabilir: hangi müşteri hangi videoları kiraladı.
- Use case'ler yalnızca nesneye yönelik yaklaşımda değil, her yaklaşımda kullanılabilir.
- **Gereksinim analizinin akışı:**
  1. Bilgi toplanır.
  2. Use case diyagramıyla modellenir.
  3. Diyagram farklı bakış açılarına sunulur. Örneğin satış-sipariş işleminde stok çalışanı, fatura kesen ve müşteri temsilcisi.
  4. Hepsinin verdiği bilginin tutarlı olması sağlanır. Bunun için tüm paydaşların fikri alınır.
- **Ayrıntı düzeyi:** Önce tüm organizasyonun temel işlemlerini gösteren bir özet diyagram çizilir, sonra alt diyagramlarla ayrıntıya inilir. Bu, veri akış diyagramlarındaki seviyelendirmeye benzer.
- Use case diyagramı ve belgesi paralel yürür. Hangisinin önce yazılacağına siz karar verirsiniz. Ama önce basit bir taslak diyagramla başlanır.

**Ayrıntılı (fully dressed) use case belgesi örneği (slayttan):**

```
Use Case UC1: Rent Video (Video Kiralama)
Seviye (Level): Kullanıcı hedefi seviyesi (User-level goal, EBP level)
Birincil aktör (Primary Actor): Görevli (Clerk)
Ön koşullar (Preconditions):
  - Görevli kendini tanıtmış ve sisteme giriş yapmış (identified and authenticated)
Paydaşlar ve ilgileri (Stakeholders and their Interests):
  - Görevli: Doğru ve hızlı giriş ister.
  - Müşteri: Videoları hızlı ve az uğraşla almak ister.
  - Muhasebeci: İşlemlerin doğru kaydedilmesini ister.
  - Pazarlama: Müşteri alışkanlıklarını izlemek ister.
Ana başarı senaryosu: sıralı iş adımları (algoritma düzeyinde)
```

- Hoca: Basit bir firmada muhasebe ve pazarlama paydaşları olmayabilir, görevli her şeyi kendisi takip eder.

### Fonksiyonel ve Fonksiyonel Olmayan Gereksinimler

- **Fonksiyonel gereksinimler (functional requirements):** Yazılımı istenen sistemde hangi işlerin yapıldığı. İşin kademe kademe nasıl yapıldığını anlatır.
- **Fonksiyonel olmayan gereksinimler (non-functional requirements):** Daha teknik, standartlara uygunluğu sağlayan, kaliteyle ilgili kurallar. Örnek: performansın iyi olması, yanıt süresinin kısa olması, güvenliğin nasıl sağlanacağı.
- Gereksinim analizinde ikisi de ayrıntılı olarak ortaya çıkarılmalıdır.

### Sonraki Hafta

- Gereksinim mühendisliği: Pressman ve Sommerville'in kitaplarındaki bölümler. Bilgi toplama aşamasından başlanacak.

### Ders sonrası notlar

- **CMMI'nın açılımı** "Capability **Maturity** Model Integration"dır. Altyazıda "Majority" diye geçiyor. Kısaltma "SMMI/SMA" diye de bozulmuş.
- **0. düzeyin anlamı:** Hoca 0. düzeyi "hiç müracaat edilmemiş" diye anlattı. Bu doğru değil. CMMI'da 0. düzey (Incomplete), süreçlerin hiç ya da kısmen yürütüldüğü durumdur. Bu bir yetenek (capability) düzeyidir. Kurumsal olgunluk (maturity) düzeyleri 1'den başlar.
- **1. düzey:** Slayttaki tanım doğru. Süreçler gelişigüzel (ad hoc) yürür, başarı kişilere bağlıdır. Hoca 1. düzeyi daha olumlu anlattı.
- **Tarihçe ayrıntıları:**
  - CMM'in 1.0 sürümü 1991'de yayımlandı. CMMI 2000-2002 arasında çıktı.
  - Çevik uygulamalara yönelik açıklamalar CMMI v1.3 (2010) ile eklendi.
  - CMMI V2.0 2018'de yayımlandı.
  - Hocanın "97'ye kadar CMM olarak anlatıyorduk" ifadesi, CMMI'ya geçişten önceki dönemi kastediyor.
- **"Avrupa'daki süreç sertifikasyonu"** büyük olasılıkla SPICE'tır: ISO/IEC 15504, bugün ISO/IEC 33000 serisi.
- **PMI** = Project Management Institute ("Institution" değil).
- **Altyazıdaki bozuk yerler:**
  - "Soner Küp" büyük olasılıkla SonarQube. SonarQube bir test aracı değil, statik kod analizi ve kod kalitesi aracıdır.
  - "Kölite" = kalite.
  - "Yuz case" = use case.
  - "seconds diagram" = sequence diagram.
  - "COÇ SİSTEM" = Koç Sistem.
  - "Etia" = ETİYA.
- **Use case seviyesi:** Slayttaki "EBP" = Elementary Business Process (temel iş süreci). Larman'ın kitabında kullanıcı hedefi seviyesindeki use case'ler için kullanılır.
- **Türkiye'deki firma düzeyleri** hocanın derste aktardığı bilgilerdir. Sertifikalar süreli olduğu için güncel durum farklı olabilir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
