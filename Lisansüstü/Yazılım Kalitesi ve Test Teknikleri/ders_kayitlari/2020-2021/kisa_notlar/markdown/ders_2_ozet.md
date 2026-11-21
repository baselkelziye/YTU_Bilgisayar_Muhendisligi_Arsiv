# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin kapsamının tekrarı (ekrandan, 00:20:00 - 00:35:00)
  - Ders 12 ana başlıkta ilerler: yazılım geliştirme ve kalite yaklaşımı (yazılım mühendisliğinde kalitenin yeri, süreç modelleri, çevik yaklaşımlarda kalite bakış açısı, test güdümlü yazılım geliştirme), yazılım kalite özellikleri ve McCall modeli, kalite sağlama aktiviteleri, yazılım inceleme ve Fagan incelemesi, geçerleme ve doğrulama, test süreci adımları, test teknikleri, hata giderme, yazılım ölçümü ve güvenilirlik, test planlama ve yönetimi, teslim sonrası kalite sağlama, kalite iyileştirme (CMMI).
  - Test süreci adımları: birim test, bütünlük testi, regresyon testi, sistem testi, onaylama testi. Şelale modelde bu sırayla, diğer modellerde daha sık aralıklarla yapılır.
  - Test teknikleri: saydam kutu (iç test) ve kara kutu (dış test); hoca gri kutu testini de ekledi.
  - Yazılım ölçümü: Halstead ve McCabe ölçütleri (ekrandan, 00:25:00), nesneye yönelik yazılımlar için Chidamber-Kemerer (CK) metrikleri.
  - Güvenilirlik (reliability): bulunan doğru sonuca yüzde kaç güvenilebileceği, yani çalıştırma süresince görülen hata oranı.
  - Test planlama ve yönetimi: test planı, test senaryoları (test verisinin seçimi ve sayısı), test çalışma ekibi yapısı, test raporları (ekrandan, 00:30:00).
  - Teslim sonrası kalite: bakım ve yazılım konfigürasyonu. Konfigürasyon yönetimi geliştirmenin başında başlar; her değişiklik kayda geçirilir, bütün yazılım elemanlarının bilgisi izlenebilir tutulur.
  - Kalite iyileştirme: CMMI, yeterlilik düzeyleri, anahtar süreç alanları, süreç alanları sınıflaması, People CMM (ekrandan, 00:35:00).
- Yazılım mühendisliğinde kalitenin yeri (ekrandan, 00:40:00)
  - Yazılım mühendisliği bilgisayar bilimi, yönetim bilimi, ekonomi ve bilişim bilim dallarından yararlanır, sorun çözümünde mühendislik yöntemlerini kullanır.
  - Hocanın tanımı: kaliteli yazılımı en ekonomik olarak elde etmeye çalışan ve bunda mühendislik yöntemlerini kullanan bilim dalı.
  - Üç anahtar kavram: kaliteli yazılım, en ekonomik (en ucuz değil, uygun maliyetli) elde etme, mühendislik yöntemleri.
  - Mühendislik yöntemlerinin iki temel bacağı: ölçme ve tasarım.
- Katmanlı yapı
  - Temelde kalite bakış açısı, üzerinde süreçler, sonra yöntemler (metodolojiler) ve en üstte yazılım araçları (CASE: Computer Aided Software Engineering) bulunur.
  - Araç seçimi rastgele yapılmaz; süreç modeline, yönteme ve kalite bakış açısına uygun olmalıdır.
- Esas ve destek süreç adımları (ekrandan, 00:45:00)
  - Esas adımlar: gereksinim analizi, tasarım, kodlama, test, bakım.
  - Destek adımları: proje yönetimi, kalite yönetimi, geçerleme ve doğrulama, formal teknik gözden geçirme, konfigürasyon yönetimi, yeniden kullanılabilirlik yönetimi, yazılım ölçümü, risk yönetimi.
  - Destek adımlarının çoğu kalite yönetimi altındadır; bir kısmı proje yönetimiyle kesişir.
- Klasik süreç modelleri (ekrandan, 01:10:00)
  - Şelale (klasik, doğrusal akış), prototip, artımlı (incremental), helezon (spiral), hızlı uygulama geliştirme (RAD), birleştirilmiş süreç (Unified Process).
  - Hepsinde temel adımlar aynıdır; fark sıralama ve uygulamadadır.
- Spiral model (ekrandan, 01:15:00)
  - Bölgeler: müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve değişim, müşteri değerlendirme.
  - İçten dışa sarmallar: kavram geliştirme, yeni ürün geliştirme, ürün zenginleştirme, ürün bakım projesi. Model hem artımlı hem evrimseldir.
- Çevik yaklaşımlar ve kalite (ekrandan, 01:20:00 - 01:30:00)
  - Artan müşteri taleplerini hızlı karşılamak ve geç ortaya çıkan gereksinim değişikliklerini çabuk karşılamak için doğmuştur.
  - XP değerleri: basitlik, iletişim, geri besleme, cesaret. Uygulamaları: kısa aralıklı sürümler, basit tasarım, sürekli test, refactoring, eşli programlama, ortak kod mülkiyeti, sürdürülebilir hız.
  - Kaliteyle ilişkisi: dinamik değerlendirme (test) statik değerlendirmeden (inceleme) fazla kullanılır; kalite işleri sürecin erken adımlarında başlar ve kısa aralıklarla yapılır; kullanıcı hikayeleri, birim testler ve müşteri geri beslemesiyle doğruluk ve süreklilik sağlanır.
  - Test güdümlü geliştirme (TDD) basamakları: birim test case'leri yazmak, henüz kod olmadığı için başarısız olduklarını görmek, kod yazarak geçmelerini sağlamak, testleri tekrar koşturmak, kodu yeniden düzenlemek (ekrandan, 01:25:00).
- Yazılım kalite temel kavramları (ekrandan, 01:30:00)
  - Kaliteli yazılım: önceden belirlenmiş işlevsel gereksinimlere ve yazılım geliştirme standartlarına uygun, kabul edilebilir hata düzeyinde olan yazılım.
- McCall kalite üçgeni (ekrandan, 01:40:00)
  - Ürün kullanımı (kullanıcı): doğruluk, güvenilirlik, kullanışlılık, bütünlük, etkinlik.
  - Ürün geçişi (işletim, operatör): taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik.
  - Ürün değişikliği (bakım yapan): bakım yapılabilirlik, esneklik, test edilebilirlik.
- Kalite özelliklerinin tanımları (ekrandan, 01:55:00)
  - Doğruluk, güvenilirlik, verimlilik, güvenlik, kullanışlılık, hata bulma kolaylığı, esneklik, sınama yapılabilirlik, taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik (slaytta "bağlanabilirlik").
- McCall kalite modeli (ekrandan, 02:00:00)
  - Kalite faktörleri ($F_i$) doğrudan ölçülemez; ölçülebilir özelliklere ($m_j$) bağlı doğrusal bir denklemle kestirilir: $F_i = c_1 m_1 + c_2 m_2 + \dots + c_n m_n$.
  - Her faktör alt ölçütlere bağlanır; örneğin doğruluk izlenebilirlik, tam olma ve uyumluluğa; güvenilirlik hata toleransı, doğruluk ve uyumluluğa; etkinlik çalışma ve bellek etkinliğine.
- Kalite sağlama aktiviteleri (ekrandan, 02:05:00)
  - Standartlar, geçerleme ve doğrulama, gözden geçirme ve denetim, test, hata/kusur analizi, değişim ve konfigürasyon yönetimi, eğitim, risk yönetimi; ayrıca sürüm (release) yönetimi.
  - Verification: yazılımı doğru yolla üretiyor muyuz? Validation: doğru (istenen) yazılımı ürettik mi?
- Geliştirme sürecinde kaliteyi yükseltmek
  - Gereksinim analizi: kolay kullanım ve öğrenme, istenmeyen senaryoların planlı ele alınması.
  - Modüllere ayırma: taşınabilirlik ve birlikte çalışabilirlik; modüller arası bağlantı (coupling) en aza, modül içi tutarlılık (cohesion) en yükseğe.
  - Nesneye yönelikte aynı fikir sınıflar arası ilişki ve sınıf içi kuvvet olarak görülür; CK metriklerinde de yer alır.
  - Test: doğruluğun yanında performans gibi faktörler ve işlevsel olmayan gereksinimler de sınanır.
- Kalite maliyeti (ekrandan, 02:15:00)
  - Hatayı düzeltme maliyeti: gereksinim analizinde 0.2, tasarımda 0.5, birim testinde 2, kabul testinde 5, bakımda 20. Artış doğrusal değildir.
  - Süreç ilerledikçe hata bulma gideri artar, hata bulma olasılığı düşer.
  - Hata önleme maliyeti: kalite planlama, formal ve teknik gözden geçirme, test oluşturma, eğitim.
  - İç hata maliyeti: yazılım kullanıma alınmadan önce bulunan hatalar. Dış hata maliyeti: kullanımdan sonra ortaya çıkan hatanın düzeltilmesi; buna güven kaybı da eklenir.
- Yazılım mühendisliği standartları (ekrandan, 02:20:00)
  - Geliştirme aşamasına, kaynağına ve değerlendirme ölçütünün tipine göre üç biçimde sınıflandırılır.
  - Kaynaklar: IEEE, ISO, DoD, IEC, ASTM. CMMI bir standart değil, yazılım evlerini sertifikalandırma sistemidir.
  - Aşamaya göre: proje yönetimi, gereksinim tanımı (SRS), tasarım (SDS), kodlama, güvenlik, konfigürasyon yönetimi, kalite güvencesi.
  - Yazılım standartları çoğunlukla süreç temellidir; başka alanlardaki standartlar ise ürünü tanımlar.
- Yazılım kalite yönetim sistemi (ekrandan, 02:25:00 - 02:30:00)
  - Geliştirici ve kullanıcının birlikte belirlediği yönetim yapısı, sorumluluklar, etkinlikler, yetenekler ve kaynaklardan oluşur.
  - Genel standartlar, kurumun kalite yönetim sistemi ve kalite el kitabı, projeye özgü standartlar katmanlı bir ilişki kurar.
  - Kalite güvencesi planı: kalite etkenlerinin nasıl kapsanacağı, kalite kontrolünü kimin, ne zaman yürüteceği, CASE desteği.
  - Kalite yönetimi: standartlar, süreç modelleri, ölçüm yöntemleri, konfigürasyon yönetimi, doğrulama ve geçerleme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kaliteli yazılım "en ucuz" değil, "en ekonomik" (uygun maliyetli) elde edilir.
  - Hız tek başına amaç değildir; hedef kaliteli yazılımdır.
- Mühendisliğin iki temeli ölçme ve tasarımdır.
  - Hoca "mühendis" kelimesini "hendese" ile ilişkilendirdi. İnşaatta işe tasarımla başlandığı gibi yazılımda da hemen kodlamaya geçilmez, önce alt modüller tasarlanır.
- Hata ne kadar erken bulunursa o kadar ucuz düzeltilir.
  - Bu yüzden gözden geçirme (review) ve inceleme (inspection) erken adımlarda çok önemlidir. Review formal olmayan gözden geçirmedir; inspection daha formaldir.
- Verification ve validation farkı.
  - Doğru yolla mı üretiyoruz (verification), doğru yazılımı mı ürettik (validation). Test sürecinde ikisi de dikkate alınır.
- Yazılım standartları süreç temellidir.
  - Ürünün fiziksel özelliğini değil, süreci ve süreçte üretilecek belgelerin içeriğini tanımlar.
- McCall modeli çok eski olmasına rağmen hâlâ kullanılır.
  - Tanımsal kalite faktörlerini ölçülebilir değerlere bağlaması onu değerli kılar.

## Kısa Tekrar Notları

- Katmanlar: kalite bakış açısı, süreçler, yöntemler, araçlar (CASE).
- Esas adımlar: gereksinim analizi, tasarım, kodlama, test, bakım.
- Destek adımları: proje ve kalite yönetimi, V&V, formal teknik gözden geçirme, konfigürasyon, yeniden kullanılabilirlik, ölçüm, risk.
- Süreç modelleri: şelale, prototip, artımlı, spiral, RAD, Unified Process.
- RAD için iki koşul: birden fazla ekip kuracak kadar kadro ve modüllere bölünmeye uygun yazılım (hızlı geliştirme ihtiyacıyla birlikte).
- Çevik: dinamik değerlendirme ağırlıklı, kalite işleri erken ve kısa aralıklı, TDD.
- McCall üçgeni: ürün kullanımı, ürün geçişi, ürün değişikliği.
- McCall modeli: $F_i = c_1 m_1 + c_2 m_2 + \dots + c_n m_n$.
- Hata düzeltme maliyeti: 0.2, 0.5, 2, 5, 20 (gereksinimden bakıma).
- Kalite maliyeti: önleme, iç hata, dış hata.
- Standart kaynakları: IEEE, ISO, DoD, IEC, ASTM; CMMI sertifikasyondur.

## Detaylı Açıklamalar

- **Kalitenin yazılım mühendisliğindeki yeri.** Yazılım mühendisliği katmanlı bir yapı olarak düşünülür. En altta kalite bakış açısı vardır ve diğer bütün katmanlar onun üzerine kurulur. Üzerinde süreçler, yani hangi süreç modelinin kullanılacağı kararı yer alır. Sonra yöntemler gelir: hangi yazılım geliştirme yöntemi ve hangi diyagramlar kullanılacak. En üstte araçlar bulunur. CASE araçları analiz ve tasarımdaki işleri kolaylaştırır, rutinleştirir ve hatayı azaltır. Bunlar yalnız çizim aracı değil, "akıllı çizim" araçlarıdır. Araç, alttaki katmanlara uygun seçilmelidir.
- **Süreç modelleri.** Şelale modelde adımlar ardışıktır; bir adım bitince diğerine "dökülür", arada geri dönüşler olabilir. Prototip model, müşterinin analiz ve tasarımda sonucu canlandıramamasına çözüm olarak bir prototip üretir; geri kalanı şelaleye benzer. Artımlı modelde önce çekirdek yazılım kullanıma sunulur, ekler ayrı ayrı geliştirilip sonradan katılır. Spiral modelde her sarmalda müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve değişim ile müşteri değerlendirme adımları tekrarlanır. Bakım aşamasında da aynı adımlardan geçilir. RAD modelde yazılım modüllere ayrılır; her modülün analiz, tasarım ve hızlı geliştirmesi ayrı ekiplere verilir, sonra modüller birleştirilir ve bütünlük testiyle kullanıma alınır. Unified Process, IBM'in daha sonra satın aldığı Rational Unified Process (RUP) platformunun dayandığı, nesneye yönelik ve kullanım senaryolarıyla başlayan bir modeldir.
- **Çevik yaklaşımlar ve kalite.** Çevik yaklaşımlar 2000'li yıllarda bir manifestoyla ortaya çıktı ve yaklaşık son on yılda sektörde yaygınlaştı. İlk model olan XP; basitlik, iletişim, geri besleme ve cesaret değerlerine dayanır. Kısa aralıklı sürümler, basit tasarım, sürekli test, sürekli yeniden tasarım (refactoring), eşli programlama ve ortak kod mülkiyeti XP'nin özellikleridir; fazla mesai yapılmaması da hedeflenir. Kalite açısından çevik yaklaşımlar yazılımı çalıştırarak değerlendirmeye (dinamik) ağırlık verir. Kalite işleri erken başlar ve daha kısa aralıklarla yapılır. TDD yalnız XP'de değil, Scrum ve Kanban'da da kullanılır: önce test yazılır, kod olmadığı için test başarısız olur, sonra testin geçmesini sağlayacak kod yazılır, testler tekrar koşturulur ve kod yeniden düzenlenir.
- **McCall modeli.** McCall üçgeni kalite faktörlerini üç bakış açısına göre gruplar. Kullanıcı yazılımın işi doğru yapıp yapmadığına, bu doğruluğa ne kadar güvenebileceğine, bütünlüğe (security) ve etkinliğe (performans) bakar. Operatör yazılımın başka işletim sistemine taşınabilirliğine, yeniden kullanılabilirliğine ve birlikte çalışabilirliğine (interoperability) bakar. Bakımı yapan kişi ise bakım yapılabilirliğe, esnekliğe ve test edilebilirliğe bakar. Kalite faktörleri doğrudan ölçülemediği için McCall modeli her faktörü ölçülebilir alt özelliklerin ağırlıklı toplamıyla, yani $F_i = c_1 m_1 + c_2 m_2 + \dots + c_n m_n$ biçiminde kestirir. Örneğin kullanılabilirlik çalışabilirlik, eğitim ve iletişim yapılabilirliğe; yeniden kullanılabilirlik modülerite ve genelleştirilebilirliğe bağlanır.
- **Kalite maliyeti.** Kaliteyi baştan sağlamak, sonradan hata bulup düzeltmekten ucuzdur. Slayttaki değerlere göre bir hatanın düzeltme maliyeti gereksinim analizinde 0.2 iken bakımda 20'dir, yani 100 katına çıkar. Artış doğrusal değildir; ardışık aşamalar arasında 2.5 ve 4 katlık sıçramalar vardır. İç hata maliyeti ekip içinde kalır. Dış hata maliyetinde ise düzeltme giderine kurumun müşteri gözündeki güven kaybı da eklenir.
- **Standartlar ve kalite yönetim sistemi.** IEEE, ISO, DoD ve IEC yazılım standartları yayımlar. IEEE standartları numarayla ve son güncelleme tarihiyle anılır; örneğin SRS ve yazılım tasarım belirtimi (SDS) belgelerinin nasıl hazırlanacağı için ayrı standartlar vardır. Bir kurum bu genel standartlardan hangilerini kullanacağını seçerek kendi kalite yönetim sistemini kurar ve bunu bir kalite el kitabında anlatır. Her proje kurum standartlarını alır, gerekiyorsa projeye özgü ek standartlar tanımlar.
- **Ders sonrası not.** Hoca ISO'yu "Ulusal Standartlar Organizasyonu" diye andı. ISO büyük olasılıkla Uluslararası Standardizasyon Örgütü'dür (International Organization for Standardization). Hoca ayrıca ISO 9001'i yazılım mühendisliğiyle ilişkilendirdi. ISO 9001 büyük olasılıkla genel bir kalite yönetim sistemi standardıdır; yazılıma uygulanması için ayrı bir rehber (ISO/IEC 90003) bulunur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
