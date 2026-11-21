# Ders 10 Çalışma Özeti

## Genel Konular

- Çevik (agile) yaklaşımlar ve XP tekrarı
  - XP'nin dört temel değeri: basitlik, iletişim, geri besleme ve cesaret (ekrandan, 00:10:00). Bu değerler bütün çevik modellerin çekirdeğidir.
  - Bu değerler çevresinde oluşturulan uygulamalar: planlama oyunu, küçük ve kısa aralıklı yayımlar, sistem metaforu, basit tasarım, test, devamlı yeniden tasarım (refactoring), eşli programlama (pair programming), ortak kod mülkiyeti, sürekli tümleştirme (continuous integration), devam ettirilebilir hız (haftada yaklaşık 40 saat), ekip üyesi müşteri ve kodlama standartları (ekrandan, 00:10:00).
  - Derste ele alınan çevik süreç modelleri XP, Scrum ve Kanban'dır. Hepsinde ortak çekirdek özellikler, her birinde de kendine özgü öne çıkan özellikler vardır.
- Çevik modellerde test ve kalite
  - Geleneksel modellere göre dinamik kalite değerlendirme (test) statik değerlendirmeden daha fazla uygulanır (ekrandan, 00:15:00).
  - Kaliteyle ilgili işlemler sürecin daha erken adımlarında başlar ve daha kısa aralıklarla, daha sık yapılır.
  - Doğruluk ve süreklilik kullanıcı hikayeleri, birim testler ve müşteri geri beslemesiyle sağlanır. Bir use case ya da kullanıcı hikayesi belirlendiğinde onun test senaryosu da hazırlanır.
- Test güdümlü yazılım geliştirme (TDD)
  - Küçük ve hızlı iterasyonlarla, araçlarla hazırlanmış testler yazılarak ilerleyen bir geliştirme yöntemidir; çevik yaklaşımlar için daha uygundur.
  - Adımlar: birim kodu yazmadan önce test case'leri yazmak, kod henüz olmadığı için testin başarısız olduğunu görmek, kodu yazarak testin geçmesini sağlamak, testleri tekrar çalıştırmak, kodu yeniden düzenlemek.
  - TDD üzerine erken bir çalışma: H. Erdoğmuş 24 lisans öğrencisiyle önce-test ve sonra-test yöntemlerini karşılaştırmıştır. Sonuç: TDD programcı üretkenliğini artırmış ama daha iyi kalite sağlamamıştır; önce-test yaklaşımının başarısı programcıyı kodları ve test sonuçlarını yedeklemeye teşvik etmesiyle ilişkilendirilmiştir (ekrandan, 00:20:00).
- Yazılım konfigürasyonu ve konfigürasyon yönetimi (YKY) tekrarı
  - Yazılım mühendisliğinin ürünleri programlar, belgeler ve veri yapılarıdır; bunlara ait bütün maddelere topluca yazılım konfigürasyonu denir (ekrandan, 00:25:00). Hoca test verilerini ve veritabanı elemanlarını da bu elemanlara ekler.
  - Yazılım konfigürasyon maddesi (Software Configuration Item), YKY işlemlerinin uygulandığı yazılım modülüdür.
  - YKY etkinlikleri dört aşamadır: konfigürasyon tanımı (identification), konfigürasyon değişiklik kontrolü (control), konfigürasyon denetimi (auditing) ve konfigürasyon raporlama (status accounting).
  - YKY standartlarına örnekler: IEEE-STD-828 (SCM planları standardı), IEEE-STD-1042 (SCM planları rehberi) ve ISO 9004 Part 6 (ekrandan, 00:30:00).
- Release Management (yayınlama yönetimi)
  - Yeni bir yazılımın ya da yeni bir sürümün canlı (üretim) ortama alınması ve son kullanıcıya sunulması sürecini yönetir. Temel amaç canlı ortamın bütünlüğünü korumak ve doğru bileşenlerin yayınlanmasını sağlamaktır (ekrandan, 00:45:00).
  - Bazı kurumlar onu yalnız teknik dağıtım (deployment) olarak görür; daha geniş bakışta ilgili iş biriminin uyumu (adoption) ve iş süreçlerindeki değişiklikler de kapsama girer.
  - ITIL'de Service Transition başlığı altında "Release and Deployment Management" adıyla temel bir süreçtir (ekrandan, 00:50:00). Release, bir servisin ya da bileşenin yeni sürümünün geliştirilmesi; deployment, onun canlı ortama tümleştirilmesidir.
  - ITIL bu süreci altı alt sürece böler: release yönetimi desteği, release planlama, release oluşturma (build), release dağıtımı (deployment), erken yaşam desteği ve release kapanışı (ekrandan, 00:55:00).
  - Release manager koordinasyon ve gözetim rolünü birlikte üstlenir; iş birimi yöneticileri, IT proje ekipleri ve operasyon personeliyle çalışır. Büyük yayınlarda bir release ekibini yönetir ve riski değerlendirir (ekrandan, 01:05:00).
  - Faydaları: değişikliklerin kullanıcıya daha hızlı ulaşması, yetkisiz yayınların kullanılan özellikleri bozma riskinin azalması, iş etkisini en aza indiren öngörülebilir dağıtım takvimi, yeni ya da değişen servislerin anlaşılan servis gereksinimlerini karşılaması, kullanıcıya ve destek personeline uygun bilgi aktarımı (ekrandan, 01:10:00).
  - DevOps (development + operations) ile ilişkisi: DevOps benimsenmediğinde release işi teslim ekiplerinden ayrı bir ekipçe yapılır; benimsenme sürecinde ortak çalışılır; tam benimsendiğinde release yönetimini büyük ölçüde teslim ekiplerinin kendisi yapar (ekrandan, 01:15:00).
- Örnek makale sunumu: mobil uygulamalarda test
  - Mobil uygulamalarda kullanılabilirlik, mobilite ve güvenlik testleri ağır basar, test maliyeti yüksektir. Testler farklı ağ ve bağlantı senaryolarında, farklı cihazlarda tekrarlanmalıdır.
  - Yapısal (beyaz kutu) testte mobil dillerin mobilite, algılama ve enerji tüketimi için eklediği özel yapılar dikkate alınır (ekrandan, 01:35:00). Test adımları: birim, tümleştirme, sistem, kullanıcı arayüzü, regresyon ve kabul testi.
  - Fonksiyonel (kara kutu) tarafta fonksiyonel, performans, güvenlik, kullanışlılık, yük ve stres, yerelleştirme ve senkronizasyon testleri ile düşük pil ve uçuş modu gibi durum testleri yapılır.
  - Zorluklar: parçalanma (fragmentation), ağ çeşitliliği, güvenlik ve test aracı çeşitliliği (ekrandan, 01:45:00).
  - Stratejiler: emülatörler, mobil bulut çözümleri ve gerçek ağdaki gerçek cihazlar.
- SRS (IEEE 830) örneği üzerinden değerlendirme
  - Belge giriş (amaç, kapsam, tanımlar, kısaltmalar, referanslar), genel tanım ve çalışma ortamı, işlevsel gereksinimler ve sistem özellikleri olarak düzenlenir.
  - İşlevsel gereksinimler yalnız üst düzey fonksiyon listesi olarak kalmamalı, use case diyagramları ve her use case'in alt işlem adımlarıyla verilmelidir (ekrandan, 02:10:00).
  - "Sistem özellikleri" başlığı altında verilen performans, güvenilirlik, güvenlik gibi maddeler aslında fonksiyonel olmayan gereksinimlerdir; başlık buna göre konmalı, donanım gereksinimi ayrı verilmelidir (ekrandan, 02:15:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım konfigürasyon elemanları ile YKY etkinlikleri karıştırılmamalı
  - Konfigürasyon elemanları programlar, belgeler, veri yapıları (ve test verileri, veritabanı elemanları) gibi yazılımın parçalarıdır. Tanım, değişiklik kontrolü, denetim ve raporlama ise YKY etkinlikleridir. Hoca bu karışıklığın sınıfın yaklaşık yarısında görüldüğünü belirtti.
  - Benzetme: donanımın elemanları ekran, bellek gibi birimlerse yazılımın elemanları da programlar, belgeler ve veri yapılarıdır.
- Release Management ile konfigürasyon yönetimi ilişkilidir
  - Yeni sürümdeki değişikliklerin tanımı konfigürasyon yönetiminde tutulur; release management bu sürümün kullanıcıya uyumlu biçimde yayınlanmasıyla ilgilenir.
- Yazılımı teslim ettikten sonra takibi bırakmamak
  - Hoca, bu kavramın adı konmadan önce de "yazılımı ilk uygulamaya geçiş sırasında takipten bırakmayın, kullanıcıya uğrayıp nasıl gittiğini sorun" biçiminde öğretildiğini anlattı.
- Testin yeterliliği genel bir sorundur
  - "Yapılan testlerin yeterli olduğu nasıl anlaşılır?" sorusu yalnız mobil uygulamalar için değil, bütün testler için önemlidir. Test sayısı arttıkça maliyetin ne kadar arttığı değerlendirilerek yeterli test sayısına karar verilir.
- Mobil testte kullanıcı arayüzü testi öne çıkar
  - Test adımları mobilde de aynıdır, ama sistem testinin içinden kullanıcı arayüzü testi ayrı bir adım olarak öne çıkar.

## Kısa Tekrar Notları

- XP'nin dört değeri: basitlik, iletişim, geri besleme, cesaret.
- Çevik modellerde: daha çok dinamik değerlendirme, daha erken ve daha sık kalite etkinliği.
- TDD döngüsü: test yaz, başarısız gör, kodu yaz, testi geçir, tekrar çalıştır, yeniden düzenle.
- Erdoğmuş çalışması: TDD üretkenliği artırır, kaliteyi belirgin artırmaz.
- Yazılım konfigürasyonu: programlar, belgeler, veri yapıları.
- YKY etkinlikleri: tanım, değişiklik kontrolü, denetim, durum raporlama.
- YKY standartları: IEEE 828, IEEE 1042, ISO 9004 Part 6.
- Release Management: yeni sürümü canlı ortamı koruyarak devreye almak; ITIL'de Release and Deployment Management.
- ITIL altı alt süreci: destek, planlama, build, deployment, erken yaşam desteği, kapanış.
- DevOps olgunlaştıkça release işi teslim ekiplerine geçer.
- Mobil test zorlukları: parçalanma, ağ, güvenlik, araç çeşitliliği; stratejiler: emülatör, mobil bulut, gerçek cihaz.
- SRS: fonksiyonel gereksinimler use case ve alt adımlarla; fonksiyonel olmayanlar ayrı başlıkta.

## Detaylı Açıklamalar

- Ders, önceki haftada işlenen çevik yaklaşımların tekrarıyla başlar. 2000'li yıllardan itibaren kullanılan çevik modeller son yıllarda sektörde yaygınlaşmıştır. XP ilk örnek olduğu için ayrıntılı ele alınır. Basitlik, prototiplerle uzun denemeler yapmak yerine basit bir tasarımla başlayıp ilerlemek demektir. İletişim, ekip üyelerinin kısa toplantılarla birbirinden haberdar olmasıdır. Geri besleme, XP'de artımlı geliştirmeyle, Scrum'da kısa görevlerin sık değerlendirilmesiyle sağlanır. Cesaret, yenilikleri deneyip sonuçlarına göre geliştirmektir. Küçük ve kısa aralıklı yayımlar XP'nin artımlı yapısından gelir: basit tasarımla bir çekirdek yazılım kurulur, üzerine eklemeler yapılır, her küçük yayın test edilir ve tasarım refactoring ile sürekli iyileştirilir. Müşterinin ekip üyesi sayılması bütün çevik modellerin ortak özelliğidir.
- Test açısından bakıldığında çevik modeller, use case ya da kullanıcı hikayesi belirlenir belirlenmez onun nasıl test edileceğini de tanımlar. Bu, testin gereksinim aşamasına kadar çekilmesi demektir. TDD bu anlayışın yöntemidir: test önce yazılır, kod henüz olmadığı için test başarısız olur, sonra kod yazılır ve testler tekrar çalıştırılır. Kısa döngüler ve sık tekrarlar oluşur. Scrum ve Kanban'da da TDD kullanılır.
- Konfigürasyon yönetimi tekrarında hoca, yazılım konfigürasyonunun yazılımın düzenini oluşturan alt elemanlar olduğunu vurgular. YKY, bu elemanların geliştirme sürecinin başından kullanım sürecinin sonuna kadar hangi tarihte, hangi sürümde, hangi içerikte olduğunu ve hangi değişikliklere uğradığını her an açıklanabilir biçimde tutar. YKY planının ne içermesi gerektiği de IEEE ve ISO standartlarıyla tanımlanmıştır.
- Release Management, bir projenin canlı ortama geçişini koordine eder. Kurumlarda aynı anda birçok proje yürür; hangisinin önce devreye alınacağı, birbirlerini nasıl etkileyecekleri bu süreçte planlanır. Proje ekiplerinin ürettikleriyle bunları kullanacak operasyon ve kullanıcılar arasında köprü kurar; yeni özellikleri geliştiren ekiplerden destek verecek operasyon ekibine bilgi aktarımını da sağlar. Her projenin aynı süreç, politika ve rehberleri izlemesi önemlidir; bu yüzden ITIL süreci altı alt sürece bölerek tanımlamıştır. Planlama aşamasında kapsam, içerik ve build-test-deployment takvimi belirlenir, sorumlular atanır. Build aşamasında bütün bileşenler doğrulama ve teste hazır hâle getirilir. Deployment aşamasında bileşenler canlı ortama alınır, son kullanıcılara ve işletim personeline eğitim ve belge aktarılır. Erken yaşam desteğinde yeni sürüm yakın takibe alınır, hatalar ve işleyiş izlenir. Kapanışta güncelleme, raporlama ve proje ekiplerine geri bildirim tamamlanır, belgeler resmî olarak kapatılır. Hoca, Project Management Institute'un da bu konuda tanımlar yaptığını belirtir.
- Örnek makale sunumu mobil uygulamalarda testi ele alır. Mobil uygulamalar web, doğal (native) ve hibrit olarak ayrılır; çoğu sunucu tarafı teknolojiye ve internet bağlantısına dayanır. Bağlantı hızı ve güvenilirliği değiştiği için işlevsel testler farklı ağlarda tekrarlanır. Performans, cihazın donanım gücüne, çalışma moduna ve bağlantı kalitesine bağlıdır. Güvenlik testinde şifrelerin ve kullanıcı adlarının cihazda şifrelenmeden bırakılması ve uygulama izinlerinin kurulumdan sonra değiştirilebilmesi gibi senaryolar test durumlarına eklenmelidir (ekrandan, 01:40:00). Emülatörler bir cihaz profilini yükleyerek kolayca farklı cihazlara geçmeyi sağlar ama gerçek sonuçları her zaman yansıtmaz. Mobil bulut çözümleri saatlik kiralamayla maliyeti düşürür, cihaz günlüğü kaydı ve paralel test olanağı sunar. Gerçek ağdaki gerçek cihazlar en gerçekçi ama en pahalı çözümdür. Uygulama coğrafi konuma ya da çeşitli ağlara dayanıyorsa gerçek cihazda test edilmelidir.
<!-- BELİRSİZ: Altyazıda mobil testlerin "%30-40'ının emülatörlerle yapıldığı" geçiyor; bu oranın karesi yok, doğrulanamadı. -->
- SRS değerlendirmesinde hoca, rastgele seçilen bir proje belgesi üzerinden IEEE 830 düzenini gösterir. Örnek belge bir HTTP istemci kütüphanesi için hazırlanmıştır. Bir use case (isteğin iptali) için kısa açıklama ve numaralı detaylı adımlar verilmiştir; hoca istediği ayrıntı düzeyinin bu olduğunu söyler. Belgede "Sistem Özellikleri" başlığı altında performans, güvenilirlik, güvenlik, donanım gereksinimleri ve evrilebilirlik yer alır (ekrandan, 02:15:00); hoca bunların fonksiyonel olmayan gereksinimler başlığıyla verilmesinin, donanım gereksiniminin de ayrı tutulmasının daha doğru olacağını belirtir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
