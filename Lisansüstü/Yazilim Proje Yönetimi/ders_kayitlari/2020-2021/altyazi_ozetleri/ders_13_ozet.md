# Ders 13 Çalışma Özeti

## Genel Konular

- Ders 8 Haziran 2021'de yapıldı. Dönemin son dersi.
- Ders uygulama projesi sunumlarıyla geçti. Her sunum yaklaşık 10 dakika olacak şekilde planlandı.
- Uygulama sunumları:
  - 1. uygulama: birim dönüştürme uygulaması (tek kişilik, şelale).
  - 2. uygulama: makine öğrenmesiyle banka kredi onayı (kapsam değişikliği senaryosu).
  - 3. uygulama: deprem sonrası düşme tespitiyle enkaz belirleme (mobil uygulama).
  - 4. uygulama: film veritabanı ve paylaşım sistemi.
  - 5. uygulama: demirbaş ve zimmet envanter yönetimi.
  - 6. uygulama: bir şirketin süreç, risk ve iç kontrol platformunun ikinci fazı (Kanban).
  - 7. uygulama: uçak içi alışveriş ve ağırlama sistemi (havacılık).
  - 8. uygulama: üniversite için iş ve staj portalı.
  - 9. uygulama: havalimanı hizmetleri ve gelirleri faturalandırma sistemi.
- Bir öğrenci ayrıca geciken makale sunumunu yaptı: proje yönetiminde duygusal zekanın önemi.
- Hoca devam kuralını, final sınavını ve son teslimleri duyurdu.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Proje takibi:** plan yapıldıktan sonra planlanan ile gerçekleşen karşılaştırılmalı. Bunun için kazanılan değer analizi (Earned Value Analysis) gibi bir araç kullanılır. Ölçüm kilometre taşlarında (milestone) bütçe, zaman ve kapsam açısından yapılır.
- **Risk takibi:** risk tablosunda etki ve olasılıktan bir derece (skor) çıkar. Küçük bir projede 15 riskin hepsi takip edilemez. Bir eşik konur, o değerin üstündeki riskler takip edilir. Etki ve olasılık zaten bunun için belirlenir.
- **Bütçe:** maliyet hesabında kişi iş gücü de sayılmalı. Tek kişilik bir projede bile yalnız bilgisayar gideri yazmak eksik.
- **Devam kuralı** (herkes için geçerli):
  - Yönetmelikte devam şartı %70. Hoca alt sınırı 4 ders olarak belirledi.
  - 4'ten az derse katılanlar sunum yapmış olsa bile devamsızlıktan kalacak.
  - 5-8 derse katılanların notundan 20 puan düşülecek. Hoca duruma göre bu kesintiyi azaltabileceğini, ama düzenli devam edenlerle bir fark olacağını söyledi.
  - 8'den fazla derse katılanlar gerçek notunu alacak.
- **Final sınavı:**
  - 15 Haziran 2021, sabah, ders saati içinde.
  - Büyük ihtimalle test usulü.
  - Kapsam: hocanın derslerde anlattıkları. Sisteme konan slaytların dışında anlatılanlar da dahil.
  - Öğrencilerin makale sunumları final kapsamında olmayacak.
  - Derste anlaşılmayan yerler tavsiye edilen kitaptan tamamlanabilir; kitapta konular daha anlaşılır örneklerle anlatılmış.
- **Son teslim:** IEEE formatındaki makaleler sisteme yüklenecek. Hoca bugün akşama kadar tanımladığını hatırlıyor.

## Kısa Tekrar Notları

- Plan takibi: kilometre taşlarında bütçe, zaman ve kapsam için planlanan ile gerçekleşen karşılaştırılır (kazanılan değer analizi).
- Risk derecesi = etki × olasılık. Eşiğin üstündeki riskler takip edilir.
- Örnek risk skoru sınıflaması (7. uygulama): 4 ve altı düşük, 4-8 arası orta, 8'den büyük yüksek.
- Müşteri yeni bir talep getirirse kapsam, adımlar, zaman planı, kaynak ihtiyacı ve maliyet değişir. Plan güncellenir, eski planlar sürüm bilgisiyle saklanır.
- Kanban, dış ekiplere bağımlı olunduğu ve sprint koşmanın zor olduğu durumlarda tercih edilebilir.
- Havacılıkta DO-178'e uygun projelerde otoritelerin katılım aşamaları (Stage of Involvement, SOI) vardır.
- Duygusal zekanın dört alanı: öz farkındalık, öz yönetim, sosyal farkındalık, ilişki yönetimi.
- Final: 15 Haziran 2021, test usulü, hocanın anlattıklarından.

## Detaylı Açıklamalar

### 1. uygulama: birim dönüştürme uygulaması

- **Konu:** uzaklık, alan, ağırlık, hacim, sıcaklık, mutfak, veri ve sayı sistemi birimleri arasında dönüşüm yapan basit, çevrimdışı bir Java uygulaması. Hedef kitle ödevlerinde birim dönüşümüne ihtiyaç duyan öğrenciler, ilkokul öğrencileri de dahil. Sunucu iş yerindeki projeleri gizlilik nedeniyle kullanmadı.
- **Hedefler:** kullanıcı dostu basit arayüz ve Java sayesinde farklı platformlarda çalışma. Tek kısıt tasarımın basit tutulması.
- **Model:** şelale. Proje basit olduğu için her adımın çıktısı sonrakine sorunsuz aktarılabiliyor.
- **Riskler:**
  - Tek kişi çalıştığı için kontrolsüz proje yönetimi. Gösterge: Gantt şemasındaki sürelere uyulmaması. Önlem: başka bir yazılımcı istihdam etmek.
  - Tasarımın hedeflenen kadar basit olmaması. Gösterge: kullanıcı geri bildirimleri. Önlem: daha basit arayüzlü yeni sürüm.
- **WBS:** 3 seviye, 5 adım: gereksinimler, risk analizi, kabul testi planı, yazılım geliştirme (mimari, tasarım, kodlama, test), kalite değerlendirme.
- **Takvim:** 24 Mart-26 Mayıs. Plana uyuldu.
- **Bütçe:** 12.000 TL bilgisayar gideri.
- **Kalite planı:** SRS gözden geçirmesi, çeviriyi yapan ana sınıfın incelenmesi, model, görünüm ve kontrol modülleri için birim testler (henüz yapılmadı), kullanılabilirlik testi ve kabul testi.
- **Hocanın soruları:**
  - Bütçede kişi iş gücü sayılmamış.
  - Proje yeni başlıyormuş gibi düşünülürse takip nasıl yapılır? Sunucu kazanılan değer analiziyle yapacağını söyledi. Hoca bunun kilometre taşlarında bütçe, zaman ve kapsam açısından yapılması gerektiğini ekledi.

### 2. uygulama: makine öğrenmesiyle kredi onayı

- **Konu:** banka müşterisinin kredi talebinin makine öğrenmesi yöntemleriyle değerlendirilmesi. Amaç manuel süreci otomatikleştirmek ve insan faktörünü azaltmak. İki öğrenci sundu.
- **Veriler:** yaş, yıllık gelir, ev sahibi ya da kiracı olma, çalışma süresi, kredi puanı, kredi geçmişinin süresi.
- **Kapsam:** veri toplama ve işleme, eğitim ve test verisine ayırma, model kurma, model testi.
- **Senaryo:** derste anlatılan "proje ilerledikçe plan güncellenebilir" durumunu göstermek için kurgulandı.
  - Başta müşteri, modelin anlaşılır olmasından çok doğru sonuç vermesini önemsiyor.
  - Gerçekleme aşamasındaki bir toplantıda müşteri modelin görselleştirilmesini istiyor.
  - Plan güncelleniyor: kapsam, planlanan adımlar, zaman planı, kaynak ve personel ihtiyacı ve maliyet değişiyor. Görselleştirme gerçekleme aşamasına ekleniyor.
  - Eski proje planları silinmiyor, sürüm bilgisiyle saklanıyor.
- **Riskler:** takvimde gecikme, ekibin bilgi eksikliği, kritik personelin ayrılması, müşteri taleplerinin karşılanamaması. Önlemler: süre uzatma, eğitim, bilgi paylaşımı, plan güncelleme.
- **WBS:** şelale. Analiz aşaması veri toplamayı içerdiği için uzun. Gerçeklemede birden fazla model kurulduğu için model kurma ve test eş zamanlı yürüyor.
- **Hocanın sorusu:** risk tablosu nasıl takip edilir, takip edilecek riskler nasıl azaltılır? Sunucular cevap veremedi. Hoca etki ve olasılıktan çıkan dereceye göre bir eşik konacağını, eşiğin üstündekilerin takip edileceğini açıkladı.

### 3. uygulama: düşme tespitiyle enkaz belirleme

- **Konu:** deprem bölgesindeki insanların akıllı telefonları için bir mobil uygulama. İki öğrenci sundu.
  - Deprem sonrası enkazın tespiti.
  - Enkaz konumunun ilgili kurumlarla paylaşılması.
  - Enkaz altında kalmış olabilecek kullanıcıların bilgilerinin paylaşılması.
- **Hedefler:** akıllı telefonların en az %90'ında çalışan bir uygulama, düşme tespiti için bir makine öğrenmesi modeli, sunucu tabanlı iletişim.
- **Kaynaklar:** yazılım mimarı, proje yöneticisi, Android ve iOS geliştiricileri, web geliştirici, yazılım analisti, DevOps uzmanı, test uzmanı, jeofizik mühendisi (danışman), arayüz tasarımcısı.
- **WBS** (5 temel iş): proje gereksinimleri (son kullanıcı, mobil ve web gereksinimleri, dokümantasyon, sistem gereksinimleri, mimari, arayüz tasarımı), geliştirme ortamı hazırlığı, geliştirme (frontend, backend, mobil), test, yükleme.
  - Bazı işler öncülü bitmeden başlamıyor, bazıları aynı anda başlıyor.
  - Kilometre taşları: arayüz tasarımlarının bitişi, frontend'in bitişi, sürüm adayının onaylanıp ilk sürümün yayınlanması.
  - Android ve iOS için ayrı uygulamalar planlandı (hibrit de düşünülebilirdi). iOS mağaza onayı Android'den uzun sürebiliyor.
  - Uygulama mağazalarının yıllık ücretleri bütçeye eklendi.
- **Riskler ve önlemler:**
  - İnternet kesilmesi: Bluetooth ile veri aktarımı.
  - Kullanıcının izin vermemesi (konum, Bluetooth): iznin neden gerektiğini açıklayan mesajlar.
  - Bölgedeki kullanıcı sayısının az olması: sunucu tarafı devreye girer.
  - Sunucunun aşırı yüklenmesi: yük dengeleyici (load balancer) ve yedek sunucu.
  - GPS'in hatalı veri üretmesi: çevredeki kullanıcıların konum verileriyle düzeltme.
- **Maliyet:**
  - Planlanan toplam yaklaşık 109.213 TL.
  - Gecikmeler yüzünden varyansla 130 bin TL'ye kadar çıkıyor.
  - Malzeme yaklaşık 60 bin TL (iOS cihaz, dövizle ödenen yıllık ücretler), çalışma yaklaşık 50 bin TL.
  - Malzeme bir kez alındığı için gecikmeden etkilenmiyor. Varyansın çoğu saatlik ücretlerin artmasından, yani çalışma kaleminden geliyor. Gecikme maliyeti 14.441 TL.
- **Hocanın değerlendirmesi:** planlanan ile sonraki durum arasındaki değişiklikler incelenmiş.

### 4. uygulama: film veritabanı ve paylaşım sistemi

- **Konu:** profesyonel ve izleyici sinema kitlesini bir araya getiren, yorum ve etkileşim sağlayan, kişisel film arşivi oluşturulabilen bir web sistemi.
- **Organizasyon:** ana yüklenici yapısı. Bir üye birden fazla role sahip olabilir. Olası bir alt yüklenici riski için organizasyona alt yüklenici kontrolü eklendi.
- **Kullanıcılar:** yönetici (kullanıcı, film, oyuncu, yönetmen ekleme, silme, güncelleme) ve üye (görüntüleme, yorum, kendi bilgilerini yönetme, arşiv oluşturma).
- **Tahmin:**
  - Fonksiyon noktası: 14 maddelik etki derecesi soruları ve girdi, çıktı, sorgu sayılarıyla ağırlık faktörü.
  - COCOMO ile iş hacmi ve süre. Dil PHP, fonksiyon noktası başına satır sayısı 40 alındı.
  - Sonuç: yaklaşık 6,7 ay, toplam maliyet yaklaşık 225-230 bin TL.
- **Araçlar:** Visual Studio Code, MySQL, PHP, ProjectLibre, LibreOffice.
- **WBS:** şelale. Analiz (bilgi toplama, modelleme, SRS), tasarım (mimari, veritabanı), gerçekleme (kodlama, eş zamanlı birim testler ve kalite kontrolü), test (bütünlük, kullanıcı testi), kullanıcı dokümanları.
- **Riskler:** eğitim ve deneyim eksikliği (olasılık düşük), kullanıcının uygulamayı verimli kullanamaması (eğitim ve demolar), personel üzerinde pandemi etkisi (yüksek etki, orta-yüksek olasılık), takvimde gecikme, yazılım ortamının hazırlanamaması (açık kaynak araçlar nedeniyle düşük), yetersiz test, ekipten ayrılma.
- **Kalite:** kodlama standartlarına uyum, statik ve dinamik kod analizi, birim, entegrasyon ve sistem testleri, kısa aralıklarla sürüm ve müşteriye demo.
- **Hocanın soruları:** hangi riskler takip edilecek? Sunucu kullanıcının uygulamayı verimli kullanmasını, takvim gecikmesini ve pandemi etkisini saydı. Ekipten ayrılma gibi olasılığı düşük riskler daha seyrek takip edilebilir. Hoca sıralamanın etki ile olasılığın çarpımına göre yapıldığını hatırlattı.

### 5. uygulama: demirbaş ve zimmet envanter yönetimi

- **Konu:** bir müşterinin demirbaş, personel ve zimmet kayıtlarını tutan bir web sistemi. Zimmet tutanağı PDF olarak alınabiliyor.
- **Gerekçe:** müşteri kayıtları Excel'de tutuyor. Muhasebe incelemelerinde kayıtlarla gerçekte var olan demirbaşlar arasında farklar çıkmış.
- **Model:** şelale. Mevcut bir sistem olduğu için gereksinimler belli.
- **Riskler** (6 risk, düşük olanlar için bile azaltma planı):
  - Kullanıcıların yeni sisteme uyumunun zor olması: iyi analiz ve planlama.
  - Zimmet kayıtlarının yine düzensiz tutulması: kurumda yetkili personel belirlenmesi.
  - Teslimden sonra yeni ihtiyaçlar çıkması: esnek bir tasarım.
  - Kapsamın yeterince geniş tutulmaması.
  - Ekipten birinin ayrılması (proje küçük olduğu için olasılık düşük).
  - Maliyetin aşılması (en büyük maliyet yazılımcı ve zaman).
- **Zaman planı:** MS Project, 3. seviyeye kadar. Her aşama bir öncekinin bitmesine bağlı, her aşama sonunda kilometre taşı var. Gerçekleme hazırlık ve geliştirme diye ikiye ayrılmış.
- **Bütçe:** proje yöneticisi, iş analisti, orta ve kıdemli seviyede iki yazılımcı. Donanım yazılım firmasınca karşılanıyor. Yazılım kalemi araçların lisansları. Müşteri ziyaretleri için 2.000 TL. Toplam 97.000 TL.
- **Kalite planı:** SRS'in müşteriyle gözden geçirilmesi, UML use case diyagramları, pull request ile kod gözden geçirme, tüm servis ve bileşenler için birim testler, veritabanında ACID kuralları.
- **Teknolojiler:** backend Java ve Spring Boot (IntelliJ IDEA), frontend TypeScript ve Angular (VS Code), veritabanı Microsoft SQL Server. Diyagramlar Lucidchart ile çizildi. Bir prototip de gösterildi.
- **Hocanın soruları:** projenin PERT görünümü var mı diye sordu ve MS Project'ten alınabileceğini söyledi. Kalite planında ayrı bir gözden geçirme planına gerek olup olmadığını sordu.

### 6. uygulama: süreç, risk ve iç kontrol platformunun ikinci fazı

- **Konu:** sunucunun çalıştığı şirkette, dış bir tedarikçiden alınan ve şirketin süreçlerini, risklerini ve iç kontrollerini tek dijital platformda yöneten bir uygulamanın yaygınlaştırma fazı. Sunucu şirket prosedürleri nedeniyle dokümanda şirket adını ve bazı parametreleri değiştirdi.
- **Neden ikinci faz:** pilot çalışmada son kullanıcılardan yeni ihtiyaçlar geldi. Bunlar not edildi ve SRS için önemli veri oldu.
- **Kapsam:** süreç yönetimi, süreç performans yönetimi, risk yönetimi, iş sürekliliği ve iç kontrol modüllerinde yeni geliştirmeler. Örnekler: izne çıkan çalışanın yetkilerini aktarabileceği vekâlet sistemi, onay akışları.
- **Başarı faktörleri:** ikinci fazın pilotunun 2021 sonuna kadar, yaygınlaştırmanın 2022 ilk çeyreği sonuna kadar tamamlanması. Kurumsal risk yönetiminin güçlenmesi.
- **Yöntem: Kanban.**
  - Ekip mimari, sistem ve bilgi güvenliği gibi birçok dış ekibe bağımlı. Bu yüzden sprint koşmak, yani Scrum uygulamak zor.
  - Birinci fazda proje sürerken yeni talepler gelmiş, takip edilen işler durdurularak ek geliştirmeler yapılmıştı. Aynısı beklendiği için Kanban uygun.
- **Ekip:** BT süreç yönetimi (analiz ve test), yazılım tedarikçisi, iş birimleri (sahipler ve son kullanıcılar), danışmanlık (eğitim).
- **Takvim:** 12 Nisan-17 Temmuz, yaklaşık 3 ay. Tedarikçi hafta sonu da çalıştığı için hafta sonları dahil edildi. Modül bazında ilerleniyor: geliştirme, tedarikçi entegrasyon testi, BT testleri, kullanıcı kabul testi (UAT), onay, canlıya alma. Kilometre taşları entegrasyonun ve her modülün tamamlanması.
- **Riskler:**
  - Süreç, risk ve kontrol sahiplerinin projeyi sahiplenmemesi: etki yüksek, olasılık düşük. Önlem: her seviyede güçlü iletişim, haftalık toplantılar ve Jira ile takip.
  - Piyasa koşulları nedeniyle şirket önceliklerinin değişmesi: orta olasılık. Önlem yalnız süre uzatma.
  - Geliştirme süresinin uzaması: modül bazlı canlıya alma ile kısa vadeli kazanımlar öne çıkarılıyor.
- **Bütçe:** adam-gün üzerinden, yaklaşık 200 bin TL.

### 7. uygulama: uçak içi alışveriş ve ağırlama sistemi

- **Konu:** uçak içi eğlence sistemine eklenen bir katalog. 350 yolcu, önlerindeki koltuk ekranlarından ürün satın alabiliyor. İnternet bağlantısıyla gümrüksüz (duty free) ve dışarıdan alışveriş de yapılabiliyor. Sunucu havacılık sistemleri geliştiren bir firmada gereksinim analizi ekibinde çalışıyor ve böyle bir sistemin birkaç yıl içinde geleceğini öngörüyor.
- **Plan:** roller ve sorumluluklar, başlatma, planlama, yürütme, izleme-kontrol ve kapanış süreçleri.
- **Model:** havacılıkta DO-178 için tarif edilen bir model. Kodlama aşaması Scrum ile, 2 haftalık 7 sprint olarak planlandı.
- **Risk yönetimi:**
  - Etki ve olasılıktan risk skoru: 4 ve altı düşük, 4-8 arası orta, 8'den büyük yüksek.
  - Her ay risk azaltma toplantılarında aksiyonlar gözden geçirilecek. Düşük riskler için plan yapılmadı.
  - Pandemi havacılığı çok etkilediği için pandemiyle ilgili çevresel risklere öncelik verildi.
- **WBS:** 4 seviye, 89 kalem. Bazı aktiviteler bitiş-başlangıç, bazıları aynı anda başlıyor; kaynak durumuna ve işin yapısına göre belirlendi. Önemli tarihli görevler bitiş tarihiyle sınırlanarak kritik yol belirlendi.
- **Kilometre taşları ve baseline'lar:** kavramsal tasarım sonrası fonksiyonel baseline, ön tasarım sonrası tahsis (allocated) baseline, kritik tasarım sonrası ürün baseline.
- **Kaynaklar:** proje sponsoru, proje yöneticisi, iş analistleri, frontend ve backend yazılımcıları, test mühendisi. Kaynak aşımı görülmediği için fazla mesai ya da ek istihdam planlanmadı.
- **Bütçe:** yaklaşık 217 bin dolar. Ana kalemler personel ve yazılım araçları.
- **Kalite planı:** DO-178'e uygun projelerde otoritelerin katılım aşamaları (SOI) vardır: yazılım planlamasından sonra, geliştirmeden sonra, doğrulamadan sonra ve sertifikasyonda. Bunlara hazırlık için iç gözden geçirmeler tanımlandı.
- **SRS:** gereksinimler fonksiyonel, arayüz, sistem ve fonksiyonel olmayan diye dört grupta, gereksinim kodlarıyla yazıldı.
- **Hocanın değerlendirmesi:** kendi iş hayatındaki alandan bir projenin planı oluşturulmuş.

### 8. uygulama: üniversite iş ve staj portalı

- **Konu:** bilgisayar mühendisliği öğrencileri için bir iş ve staj portalı. Panolardaki karışık ilanları dijital ortama taşımak, şirketlerin daha çok öğrenciye ulaşmasını sağlamak. Şirketler abonelikle ilan verecek, gelir burs ve bölüm ihtiyaçları için kullanılacak. Sunucu iş yerindeki gizlilik nedeniyle bu konuyu seçti.
- **Model:** çevik. Stand-up toplantıları, yinelemeler (iteration) ve retrospektif, sürekli entegrasyon, Kanban, refactoring, kaynak kod yönetimi. Hoca çeviklerin genel özelliklerinin sayılmasına gerek olmadığını söyledi.
- **Riskler** (tabloda etki, önlem stratejisi, çözüm etkinliği, sorumlu):
  - Gereksinimlerin geç belirlenmesi (test faaliyetlerinin gecikmesi): müşteriyle ilişkileri güçlendirme, düzenli toplantılar, gereksinim ve konfigürasyon yönetimi için yardımcı yazılım.
  - Test için öğrencilerin zamanında hazır olmaması.
  - Yazılımın hazır olmaması: düzenli toplantılar ve gerekli aksiyonlar.
- **WBS:** proje planı, veritabanı tasarımı, kodlama ve arayüz tasarımı, test. Sistem öğrenci, firma, memur ve yönetici işlemlerine ayrılıyor.
- **İş gücü:** proje yöneticisi 15 adam-ay, veritabanı sorumlusu 10, yazılım geliştirme 10, test 4, kalite 2, iş analisti 4.
- **Görev ataması:** Jira'da Kanban panosu ve günlük Scrum.
- **Bütçe:** birinci faz (5. ay) 500 bin TL, ikinci faz (teslim) 1 milyon TL, toplam 1,5 milyon TL.
- **Kalite planı:** işlevsellik, mevzuata uygunluk, zamanında teslim, yönetim performansı, dokümantasyon ve test başarı oranları. Kalite güvencesi (analiz ve iyileştirme) ve kalite kontrolü (izleme) tanımlandı.

### 9. uygulama: havalimanı hizmetleri ve gelirleri sistemi

- **Konu:** sunucunun çalıştığı DHMİ'nin havayolu şirketlerine verdiği tüm hizmetlerin, her yıl yayımlanan ücret tarifelerine göre hesaplanıp faturalanması. Benzer sistemler yurt dışında Airport Operation Database olarak geçiyor.
- **Modüller:** terminal operasyonları (iç ve dış hat terminal hizmetleri), yer hizmetleri (kalkış öncesi ve iniş sonrası, örneğin ikram ve 400 Hz elektrik), hava trafik (bir havalimanından kalkıştan diğerine inişe kadar seyir hizmetleri).
- **Model:** şelale. Faturalama için önce uçuş başlamalı, uçuş verileri girilmeli, sonra verilen hizmetler girilmeli. Adımlar birbirine bağlı.
- **Teknolojiler:** ASP.NET, C#, HTML5, CSS3, JavaScript, Oracle (11g'den 12c'ye geçildi).
- **Use case akışı:** kullanıcı girişi, uçuş bilgileri (hava trafik kontrolörlerinden), uçuş ayrıntıları (tescil, sahip firma, rota; ücret havada geçen süreye bağlı), apron hizmetleri (örneğin "follow me" aracı, yakıt alımında itfaiye emniyet hizmeti), yer hizmetleri, faturalama.
- **Riskler:** takvimde gecikme ve yazılım-donanım ortamının hazırlanması (yüksek), personel değişikliği (orta etki, düşük olasılık), eğitim eksikliği (yüksek etki, düşük olasılık; sürekli eğitim veriliyor), kullanılabilirlik sorunları ve kullanıcı geri bildirimlerinin anlaşılmaması (yüksek etki).
- **Zaman planı** (MS Project 2016): planlama, ön inceleme, veri toplama ve analiz, tasarım, eski uygulamayla karşılaştırma ve eski verinin entegrasyonu. Proje, 2005-2006'da Visual Basic ile yazılmış bir masaüstü uygulamasını web'e taşıyor.
- **Kalite planı:** kapsama, zaman planına ve geliştirme modeline uygunluk.

### Geciken makale sunumu: proje yönetiminde duygusal zeka

- **Makale:** "Project Managers' Emotional Intelligence: Ticket to Success", 2012 IPMA Dünya Kongresi, 5 yazarlı. Sunucu 2013 tarihli bir eğitim dokümanından da yararlandı.
- **Temel fikir:** iyi takım çalışması birbirini anlamaktan ve grubun duygularını avantaja çevirmekten geçer. Proje yöneticisinin takım içi iletişimi sağlamak için yüksek duygusal zekaya sahip olması önemlidir.
- **Tanım:** kendi duygularını ve başkalarının duygularını fark edip bu doğrultuda hareket edebilmek. Deneyimle öğrenilebilir.
- **Tarihçe:** kavramı ilk kez 1964'te Michael Beldoch yazdı. 1989'da Stanley Greenspan bir model geliştirdi. Model Peter Salovey ve John Mayer tarafından geliştirildi. Daniel Goleman 1995'teki kitabıyla kavramı iş dünyasında yaygınlaştırdı.
- **Dört alan:**
  - Öz farkındalık: duyguları dinlemek, güçlü ve zayıf yanları bilmek, olaylara farklı açılardan bakabilmek.
  - Öz yönetim: öz kontrol (doğru duyguyu doğru zamanda göstermek), uyum yeteneği, başarı yönelimi, pozitif bakış.
  - Sosyal farkındalık: empati ve grup farkındalığı (takımın hislerini analiz edebilmek).
  - İlişki yönetimi: liderlik, koçluk ve mentorluk, çatışma yönetimi, ekip çalışması.
- **Proje yönetimindeki önemi:**
  - Yaygın iki söz: proje yönetiminin yarısı bilim, yarısı sanattır; proje yöneticisi zamanının %80'ini iletişimle geçirir.
  - Araştırmalar duygusal zeka ile hedeflere ulaşma, sağlıklı ilişkiler ve yaşam tatmini arasında güçlü bir ilişki gösteriyor.
  - Goleman'a göre fark yaratan liderlerin yetkinliklerinin %85'i duygusal zekayla ilgili.
  - Proje yöneticilerinin başlıca sorunları: geri bildirim verme ve almayı da içeren iletişim sorunları, kültürel faktörler, farklı kişiliklere saygı, ekip olamama.
- **Geliştirme önerileri:** duyguları fark edip adlandırmak, iyi bir gözlemci olmak, kitap okumak ve atölyelere katılmak, sosyal girişkenliği ve öz güveni artırmak, takım çalışmalarına ve sosyal sorumluluk projelerine katılmak, olumsuz durumlardan ders çıkarmak.
- **Hocanın soruları:** makalede bir anket çalışması mı var, yoksa bir durum değerlendirmesi mi? Sunucu durum değerlendirmesi olduğunu söyledi. Hoca 2012'den sonraki daha yeni kaynaklara bakılıp bakılmadığını da sordu.

### Diğer konular

- Bir öğrenci doktora tezi danışmanlığı için ne zamana kadar danışman seçilmesi gerektiğini sordu. Hoca şu anda yeni bir doktora öğrencisi alamayacağını, yüksek lisans tezi ekleyebileceğini söyledi. Enstitü kuralları değiştiği için en doğru bilginin enstitüden ya da bölüm başkanlığından alınmasını önerdi.
- Hoca vize notlarını daha sonra duyuracağını söyledi.

### Ders sonrası notlar

- Duygusal zeka sunumunda altyazıda "Bill Goldman" ve "Daniel Goldman" diye geçen ad Daniel Goleman'dır. "Peter Salloway" Peter Salovey, "Michael Beldoke" Michael Beldoch olmalıdır.
- Aynı sunumda EQ "emotional question" diye açıldı. Doğrusu "emotional quotient" (duygusal zekâ bölümü).
- 8. uygulamada süreler altyazıda tutarsız. Toplam 55 gün denirken alt işler 30, 26, 29 ve 55 gün olarak sayılıyor. Aylarla verilen takvim de bunlarla uyuşmuyor. Doğru değerler sunumda anlaşılmıyor.
- 7. uygulamadaki model adı altyazıda "bir model" diye geçiyor. Havacılık bağlamında büyük ihtimalle V modelidir, ama altyazıdan kesin değil.
- Devam kuralında tam 4 derse katılan öğrencinin durumu açık söylenmedi ("4'ten az" ve "5-8" arası tanımlandı).

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
