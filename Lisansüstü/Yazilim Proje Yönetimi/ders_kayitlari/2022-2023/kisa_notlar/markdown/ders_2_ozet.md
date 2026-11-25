# Ders 2 Çalışma Özeti

## Genel Konular

- Yazılım proje yönetiminin üç bileşeni
  - Yazılım proje yönetimi, yazılım projelerinde kaynakların en etkin biçimde kullanılmasını hedefler (ekrandan, 00:05:00).
  - Üç alanın kesişimidir: proje yönetimi bilgi ve deneyimi, genel yönetim bilimi ve yazılım mühendisliği teknikleri.
    - Proje yönetimi bilgi ve deneyimi: kapsamı belirleme, zaman planı, ekip yapısı, görev tanımları, kaynak (insan kaynağı dahil) yönetimi, planı izleme ve gerekirse B planı.
    - Genel yönetim bilimi: ekibi yönetme, sorunları kayıt altına alma, satın alma, paydaş ve müşteri ilişkileri.
    - Yazılım mühendisliği teknikleri: süreç adımları, süreç modelleri ve bunların iyileştirilmesi.
  - Etkin proje yönetimi için 3P göz önünde tutulur: insan (people), problem ve süreç (process).
  - Proje başarısı zaman, kaynak ve kapsam yönetimi üçlüsüne, dördüncü olarak da kalite takibine bağlıdır.
- Yazılım proje yönetiminin hedefleri ve yazılım geliştirme planı
  - Hedefler: proje yönetimi elemanlarının açıklığa kavuşturulması, yazılım ölçümü ve metrikler, maliyet tahmini, risk yönetimi, proje planının hazırlanması.
  - Geçmiş projeler ölçülüp arşivlenirse yeni projelerin maliyet tahmini daha kolay ve bilimsel yapılır.
  - Plan üç soruya cevap verir: ne yapılacak (kapsam), ne kadar kaynakla yapılacak (kaynak), ne zaman yapılacak (zaman).
  - Yazılım geliştirme planının alt başlıkları: sorunun tanımlanması, çözüm yolunun kararlaştırılması, geliştirme sürecinin planlanması, proje organizasyonu ve proje zamanlaması (Gantt diyagramı, PERT).
- Yazılım mühendisliğinin tanımı
  - Yazılım mühendisliği bilgisayar bilimi, yönetim bilimi, ekonomi ve bilişim bilim dallarından yararlanır ve sorun çözümünde mühendislik yöntemlerini kullanır (ekrandan, 00:20:00).
  - Amaç kaliteli yazılımı en ekonomik yolla üretmektir. En ekonomik, en ucuz demek değildir; en düşük maliyetle en etkin yazılım demektir.
  - Mühendisliğin iki gereği yazılıma katılır: kodlamadan önce gereksinim analizi ve tasarım, ve ölçüm (büyüklük, algoritma karmaşıklığı, aritmetik ifadeler, nesneye yönelik metrikler gibi).
  - Yazılım sistemi kurum ortamı, kurum içi bilgiler ve bilgi sistemlerinden oluşan katmanlı bir yapı içinde yer alır. Projeye başlamadan kurumun diğer bilgi sistemleri incelenmelidir.
- Yazılım mühendisliği dersinin hedefleri (ekrandan, 00:25:00)
  - CASE teknolojisi; yazılım proje maliyeti tahmin yöntemleri, yazılım ölçümü kriterleri ve proje planı hazırlama; yazılım kalite özellikleri ve kalite yönetimi teknikleri; yazılım bakımı kavramı.
  - Konfigürasyon yönetimi ve sürüm kontrolü kalite planı içinde planlanır; standartlar kalite yönetiminin parçasıdır.
- Yazılım geliştirme sürecinde gerçekleştirilen işlemler
  - Esas işlemler: gereksinim analizi, tasarım, kodlama (gerçekleme), test ve bakım (teslim dahil).
  - Destek işlemleri (şemsiye aktiviteler, umbrella activities): proje yönetimi, kalite yönetimi, yazılım konfigürasyon yönetimi, risk yönetimi (ekrandan, 00:30:00). Hoca yazılım ölçümünün de destek işlemlerine katılması gerektiğini söyledi.
- Yazılımın bileşenleri
  - Yazılım program demek değildir: yazılım = program + veri (veri tabanı, tablolar ve veri tanımı) + belgeler (kullanıcı belgeleri, SRS, tasarım belgesi, diyagramlar, test verileri).
- Yazılım konfigürasyon yönetimi ve risk yönetimi
  - Konfigürasyon yönetimi: yazılım elemanlarının tanımı, birbiriyle ilişkileri ve sürümler arası değişikliklerin takibi, önceki sürüme dönebilme.
  - Risk: şu anda sorun olmayan ama sorun çıkmaya müsait alanlar. Müşteri kaynaklı, çalışan kaynaklı ve teknik riskler vardır. Riskler tanımlanır, her evrede izlenir, kayıt altına alınıp ders çıkarılır.
- Yazılım geliştirme süreç modelleri
  - Klasik (şelale, doğrusal) süreç: gereksinim analizi, sistem tasarımı, gerçekleme, bütünleştirme ve kullanıma sunma, işletim ve bakım (ekrandan, 00:45:00). Geri dönüş olabilir ama adımlar sırayla yapılır.
  - Prototip modeli: hızlı tasarım ve kolay araçlarla müşteriye prototip sunulur, geri bildirimle gereksinimler netleşir.
  - Artımlı (incremental) model: yazılım kısa hedefli parçalara bölünür, her artım kullanıma alınır.
  - Spiral model: planlama, risk analizi, mühendislik ve müşteri değerlendirmesi döngüsü (ekrandan, 00:50:00). Ürün önce prototip, sonra kullanıma alınacak ürün, sonra zenginleştirilmiş ürün olur. Evrimsel bir modeldir.
  - Unified Process: başlangıç (inception), ayrıntılandırma (elaboration), yapım (construction), geçiş (transition) ve üretim (production) aşamaları (ekrandan, 01:10:00). Nesneye yönelik yaklaşım için artımlı bir modeldir.
  - CASE (Computer Aided Software Engineering) araçları: yazılım geliştirmenin her adımında (diyagram çizimi ve kural kontrolü, konfigürasyon yönetimi, test) destek veren yazılımlar.
- Çevik (agile) süreçler
  - Çevik prensipler 12 maddedir (ekrandan, 01:15:00). Hocanın özeti: müşterinin ekip içinde yer alması, ekip içi sıkı işbirliği, sık sık çalışan yazılım teslimi ve basitlik ilkesi.
  - Extreme Programming (XP): planlama (kullanıcı hikayeleri, kabul testi kriterleri), basit tasarım ve prototipler, eşli programlama (pair programming) ve refactoring, birim test ve sürekli bütünleştirme, kabul testi, artım teslimi (ekrandan, 01:20:00).
  - Scrum: ürün tanımından sprint backlog oluşturulur, 1-4 haftalık işler belirlenir, günlük toplantılarda biten ve bitmeyen işler konuşulur.
- Süreç modellerinin karşılaştırılması ve seçimi
  - Scrum ile şelale, spiral ve iteratif modellerin karşılaştırma tablosu (ekrandan, 01:25:00).
  - Proje Yönetimi Enstitüsü (PMI) üzerinden yapılan bir anket: en çok kullanılan metodolojiler, proje türleri ve süreleri (ekrandan, 01:30:00 ve 01:40:00).
  - Seçim kurumun, projenin, ekibin yapısına ve yazılımın piyasasına göre yapılır. Hata kritik yazılımda spiral, günlük iş yazılımlarında Scrum, eski sistemin yenilenmesinde şelale, çok ekip ve bölünebilir yazılımda RAD uygundur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım eşittir program değildir
  - Program, veri ve belgeler birlikte yazılımı oluşturur. Belge yoksa yazılım yalnız onu yazan kişiye bağlı kalır, başkası düzeltme yapamaz.
- En ekonomik yol en ucuz yol değildir
  - Hedef en düşük maliyetle en etkin yazılımı üretmek ve maliyeti takip etmektir.
- Mühendis ölçüm yapan kişidir
  - "Mühendislik" kelimesi hendese (geometri, ölçme) kökünden gelir. Yazılımın büyüklüğü ve karmaşıklığı ölçülmeli, planlamada ve süreç modeli seçiminde kullanılmalıdır.
- Destek işlemlerine yazılım ölçümü de eklenmeli
  - Slaytta dört destek işlemi var, hoca ölçümün de bunlara katılması gerektiğini belirtti.
- Süreç modeli gözü kapalı seçilmez
  - "Artık Scrum var, her şeyi Scrum ile yaparız" kararı uygun değildir. Projenin yapısı belirleyicidir; Scrum uyguladığını söyleyen kurumların Scrum'u ne kadar uyguladığı da tartışmalıdır.
- Çevikliğin özü
  - Müşterinin ekip içinde olması, sıkı işbirliği, hızlı çalışan yazılım ve basitlik ilkesi.

## Kısa Tekrar Notları

- Yazılım proje yönetimi = proje yönetimi bilgisi + genel yönetim bilimi + yazılım mühendisliği teknikleri.
- 3P: people, problem, process.
- Plan üç soruya cevap verir: ne, ne kadar kaynakla, ne zaman.
- Zamanlama araçları: Gantt diyagramı ve PERT.
- Esas işlemler: gereksinim analizi, tasarım, kodlama, test, bakım.
- Destek (şemsiye) işlemleri: proje yönetimi, kalite yönetimi, konfigürasyon yönetimi, risk yönetimi (+ ölçüm).
- Yazılım = program + veri + belgeler.
- Risk türleri: müşteri, çalışan ve teknik riskler.
- Şelale: sıralı, uzun süreç, hata geç fark edilir, müşteri yazılımı geç görür.
- Prototip: müşteri gereksinimlerini netleştirmek için hızlı sürüm.
- Artımlı: çekirdek modül ve üzerine yeni modüller. İteratif: aynı yazılımın tekrarlarla iyileştirilmesi.
- Spiral: planlama, risk analizi, mühendislik, müşteri değerlendirmesi; hata kritik yazılıma uygun.
- Unified Process: inception, elaboration, construction, transition.
- CASE: Computer Aided Software Engineering.
- XP: kullanıcı hikayeleri, basit tasarım, pair programming, refactoring, sürekli bütünleştirme, kabul testi.
- Scrum: sprint, backlog, 1-4 haftalık işler, günlük toplantı.
- Ankette en çok işaretlenen metodoloji şelale (%32,0), sonra Agile Unified Process (%28,1) ve Scrum (%20,3).

## Detaylı Açıklamalar

- **Yazılım proje yönetiminin kapsamı.** Hoca dersi, yazılım proje yönetimini üç alanın kesişimi olarak gösteren şemayla açtı. Proje yönetimi bilgi ve deneyimi, hangi alanda olursa olsun bir projeyi gerçekleştirmek için gereken işlemleri kapsar: kapsamı belirlemek, zaman planı yapmak, ekip ve görev tanımlarını oluşturmak, insan kaynağı dahil kaynakları yönetmek ve planı izlemek. Plan izlenirken geride kalınan noktalar saptanır ve telafi için B planı hazırlanır. Genel yönetim bilimi, proje yöneticisinin ekibini nasıl yöneteceği, sorunları nasıl kayıt altına alacağı, satın alma ve paydaş ilişkilerini nasıl yürüteceğiyle ilgilidir; hoca bunun bilgisayar mühendisliğinden gelenler için daha yabancı bir alan olduğunu söyledi. Yazılım mühendisliği teknikleri ise süreç adımlarını ve süreç modellerini kapsar.
- **Proje planının temel soruları.** Herhangi bir proje planı kapsam, kaynak ve zaman planlamasını içerir. Yazılım geliştirme planı sorunun tanımı, çözüm yolu, geliştirme süreci, proje organizasyonu ve zamanlamayı içerir. Zamanlama için Gantt diyagramı, alt adımların takibi ve kritik noktaların belirlenmesi için PERT kullanılır. Kalite yönetimi ile proje yönetimi örtüşür: ölçüm, maliyet tahmini ve risk yönetimi her ikisinde de ele alınır.
- **Yazılım mühendisliği ve ölçüm.** Yazılım mühendisliği sorunu mühendislik yöntemleriyle çözer. Mühendisliğin ilk gereği tasarımdır; tasarımdan önce de müşterinin ne istediğini ortaya koyan gereksinim analizi yapılır. İkinci gereği ölçümdür: yazılımın büyüklüğü, algoritma karmaşıklığı, aritmetik ifadelerin sayısı ve karmaşıklığı, nesneye yönelik metrikler gibi farklı boyutlarda ölçüm yapılır. Bu ölçümler planlamada ve süreç modeli seçiminde kullanılır.
- **Yazılım sistemi kurum içinde.** Hoca bir envanter sistemi örneği verdi: hazır paket programlar vardır, ama kurumun diğer bilgi sistemleriyle uyumlu çalışacak bir sistem gerekir. Bu yüzden projeye başlamadan kurumun çevre birimleri ve bilgi sistemleri incelenir, kapsam buna göre belirlenir.
- **Esas ve destek işlemleri.** Gereksinim analizi, tasarım, kodlama, test ve bakım esas işlemlerdir (hoca slaytta tasarımın eksik kaldığını belirtip ekledi). Proje yönetimi, kalite yönetimi, konfigürasyon yönetimi ve risk yönetimi bu adımları daha iyi, daha ekonomik ve daha kaliteli yapmayı sağlayan şemsiye aktivitelerdir. Proje yönetimi süre, ekip, yetenek ve maliyeti; kalite yönetimi standartları ve gözden geçirme tarihlerini; konfigürasyon yönetimi değişikliklerin kaydını ve önceki sürüme dönüşü kapsar. Eskiden konfigürasyon takibi için şirketler ayrı yazılım yazardı; bugün geliştirme platformları bunu içinde barındırır.
- **Yazılım nedir?** Hoca derste bunu sordu. Bir öğrencinin "bir problemin çözümü" cevabı üzerine yazılımın yalnız program olmadığını açıkladı: program, programın kullandığı veri tabanı ve veri tanımı, kullanıcı belgeleri, bakım yapacak geliştiriciler için SRS, tasarım belgesi, ER ve sınıf diyagramları ve test verileri birlikte yazılımı oluşturur.
- **Risk yönetimi.** Risk henüz sorun olmayan ama sorun çıkabilecek alandır ve olasılıkla ilişkilidir. Müşteri kaynaklı riskler: müşterinin bilgi vermemesi, çalışmalara katılmaması, istediğini yanlış ya da eksik anlatması, işi yarı yolda değiştirebileceğini sanması. Çalışan kaynaklı risk: ekipten birinin ayrılması. Teknik risk: kullanılan bir CASE aracının ekip tarafından tam kullanılamadığının sonradan anlaşılması. Riskler planlanır, her evrede izlenir, kayda alınır ve ders çıkarılır.
- **Süreç modelleri.** Şelale modeli, adımların birbirine sürekli bilgi aktarmasından adını alır; süreç uzundur, müşteri yazılımı geç görür ve hatalar sonda fark edilebilir. Prototip modelinde gereksinimler hızlıca tasarlanıp kolay araçlarla müşteriye sunulur, sonra kapsamlı geliştirme yapılır. Artımlı modelde yazılım kısa hedefli parçalara bölünür. Spiral model artımlı modeli daha çok test ve kontrol ile geliştirir: her döngüde planlama, risk analizi, mühendislik ve müşteri değerlendirmesi yapılır. Unified Process, nesneye yönelik yaklaşım için hazırlanmış artımlı bir modeldir. Inception aşamasında genel use case modeli, proje sözlüğü, başlangıç proje planı ve iş modeli; elaboration aşamasında ayrıntılı gereksinim analizi, yazılım mimarisi ve ayrıntılı plan; construction aşamasında tasarım modeli, bileşenlerin gerçeklenmesi, test planları, birim ve bütünlük testleri; transition aşamasında artımların teslimi yer alır. Bu modeli destekleyen güçlü bir CASE aracı vardı ve sonradan büyük bir firma tarafından satın alındı.
- **Çevik süreçler ve XP.** Çevik yaklaşımın amacı değerlendirilebilir yazılımı müşteriye hızlı vermek, değişen gereksinimlere uyum sağlamak, çalışan yazılımı sık teslim etmek, kullanıcı ve geliştiricileri motive edici bir ekipte birleştirmek ve değerlendirmeleri yüz yüze yapmaktır. Basitlik ilkesine göre proje başta çok ayrıntılı tanımlanmaz, sonra zenginleştirilir. XP ilk çevik yaklaşımlardandır: planlamada kullanıcı hikayeleri ve kabul testi kriterleri belirlenir (test güdümlü geliştirme), basit tasarım ve prototip yapılır, kodlamada iki kişi aynı kod üzerinde çalışır, refactoring ile kod kolay değiştirilir, sürekli bütünleştirme ve kabul testinden sonra artım teslim edilir.
- **Model seçimi.** Hoca, PMI üzerinden yapılan bir anketin sonuçlarını gösterdi. Katılımcıların çoğu bilgi teknolojisindendir; en yaygın proje türü yeni yazılım geliştirmedir (%38,6) ve projelerin çoğu 12 aydan kısadır. Metodoloji sorusunda birden çok seçenek işaretlenebildiği için yüzdelerin toplamı 100'ü geçer; çevik yöntemlere geçişte şelale hâlâ çok kullanılmıştır. Kurumlar modelleri birleştirerek kendilerine özgü hibrit süreçler tanımlayabilir. Hata kritik yazılımda çok iterasyon ve kontrol gerektiği için spiral, günlük iş yazılımlarında Scrum, eski bir sistemin yenilenmesinde (müşteri ne istediğini eski yazılım üzerinden gösterebildiği için) şelale, ekip ve çalışan sayısı yeterli ve yazılım bölünebiliyorsa RAD tercih edilebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
