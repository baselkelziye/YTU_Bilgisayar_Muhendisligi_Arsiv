# Ders 4 Çalışma Özeti

## Genel Konular

- Süreç sertifikasyonu
  - Olgunlaşmış bir yazılım geliştirme sürecine sahip olmayan bir yazılım firması projelerini başarıyla sonuçlandıramaz; firma süreçlerinin yeterliliğini bağımsız kurumlara onaylatmayı seçebilir (ekrandan, 00:15:00).
  - Gerekli olduğu durum: bazı büyük müşteriler (bakanlıklar, silahlı kuvvetler, büyük kamu kurumları, büyük kurumsal firmalar) sertifikalı yazılım firmalarıyla çalışmayı şart koşar.
  - Gereksiz olduğu durum: çok küçük şirketler ve/veya küçük, kısa projeler için ek yük olarak görülebilir. Sertifikasyonun maliyeti daha çok insan gücü ve zamandır; projeye oranla bu ek maliyet çok büyükse değmeyebilir.
  - Güncel model ve standartlar (ekrandan, 00:15:00):
    - CMMI (Capability Maturity Model Integration): Carnegie Mellon Üniversitesi'ne bağlı SEI (Software Engineering Institute) tarafından önerilmiştir; kurumsal düzeyde alınır.
    - PMI: genel amaçlı bir proje yönetimi yaklaşımıdır; hem bireysel hem kurumsal düzeyde sertifika alınabilir.
    - ISO 9001:2015: genel, kurumsal bir kalite yönetim standardıdır; her tür kurum başvurabilir.
    - ISO/IEC 90003:2018: ISO 9001'in yazılım geliştirmeye özel uygulamasıdır (kurumsal).
    - Türkiye'de ulusal belgelendirici firma Denetik, ulusal otorite (kamu için) TÜRKAK'tır.
  - "Genel mi özel mi? (Peynir mi üretiyoruz?)": peynir üreten bir firmayla yazılım üreten bir firmanın dinamikleri farklıdır; hoca, alana özel bir standart varsa onunla çalışmanın daha yararlı olduğunu, yoksa ISO 9001 gibi genel standartların tercih edilebileceğini söyler.
- PMI sertifikasının sürdürülmesi
  - Bireysel sertifika için PMI'nin bilgi birikimi kitabı (Body of Knowledge) çalışılıp sınava girilir; kurumlar denetçi tarafından değerlendirilir.
  - Sertifika aldıktan sonra aktif çalışma, PMI etkinliklerine pasif ya da aktif katılım (konuşmacı olmak daha çok puan getirir) gibi etkinliklerle puan toplanmalıdır; puan toplanmazsa sertifika iptal edilir.
  - CMMI'da ise akreditasyon belirli yıllarda yeniden değerlendirme ile yenilenir.
- CMMI düzeyleri (ekrandan, 00:35:00)
  - 0. Düzey: Yürütülmeyen (Incomplete).
  - 1. Düzey: Giriş düzeyi (Initial/Performed). İş şansa ve anahtar kişilere kalmıştır. Etkinliklerin tümü yürütülür ama tanımlanması için sistematik bir girişim yoktur, her seferinde farklılaşabilir.
  - 2. Düzey: Yönetilen/Yinelenebilir (Managed/Repeatable). Temel planlama ve izleme yöntemleriyle önceki projelerdeki başarılar yeni projelerde tekrarlanabilir.
  - 3. Düzey: Tanımlanmış (Defined). Kişi ve risk yönetimi ile proje yönetimi iyileştirilir; tüm organizasyonda standart süreçler tanımlanmıştır. Büyük müşteriler en az bu düzeydeki yazılım evleriyle çalışmak ister.
  - 4. Düzey: Nicel Yönetilen (Quantitatively Managed). Süreç ve yazılım ölçütleriyle kalite yönetimine geçilir; ilerleme sürekli izlenir, bütçe ve zaman sapmaları erkenden belirlenip önlem alınır.
  - 5. Düzey: İyileştirilmiş (Optimized). Süreç yönetimi geçmiş deneyimlerin ışığında sürekli iyileştirilir.
  - Her düzey bir öncekinin etkinliklerinin üstüne yenilerini ekler.
- CMMI süreç alanları, ilgi alanları ve tarihçe (ekrandan, 00:45:00)
  - CMMI her düzeyde belli süreç alanlarının kapsanmasını ister; süreç alanları belli hedeflere ulaşmak için beklenen uygulamalardır ve her firma bunları kendine özgü süreçlerle kapsayabilir.
  - İlgi alanları: CMMI-DEV (Development, yazılım geliştirme), CMMI-SVC (Service, hizmet sunumu ve yönetimi), CMMI-ACQ (Acquisition, ürün ve hizmet alımı). Bu üç alan CMMI v2.0 (2018) ile tek bir olgunluk modeli altında birleştirilmiştir.
  - Tarihçe: 1987-1997 CMM; 1998-2009 CMMI; 2010 CMMI v1.3 ile çevik süreçler desteklenmeye başladı; 2018 CMMI v2.0.
  - v2.0 ile continuous (kısmi, yalnız bazı süreç etkinliklerini kapsayan) ve staged (bütüncül, daha değerli) ayrımı kaldırılıp tüm süreç etkinliklerini kapsayacak içerikte birleştirildi; kaynaklar ücretli/abonelik tabanlı hale geldi.
  - Akredite kurumların listesi CMMI Institute'un değerlendirme (appraisal) sayfasından sorgulanabilir; derste Türkiye'den listelenen kurumlara bakıldı (ekrandan, 01:00:00).
- CMMI ve CASE araçları (ekrandan, 01:05:00)
  - Düzey 1: yazılım araçlarının kullanımına dair standart yoktur, yazılım ölçütleri kullanılmaz, yeniden kullanılabilirlik yoktur ya da minimaldir.
  - Düzey 2: yazılım aracı kullanımına yönelik proje standartları vardır, çalışanlara araç eğitimi verilmiştir, bazı takım tabanlı araçlar diğer araçlarla tümleştirilmiştir, tasarım ve kodun bir kısmı sınırlı olarak yeniden kullanılabilir.
  - Düzey 3: tüm araçların erişebildiği organizasyona ait bir veri deposu ve yeniden kullanım kütüphanesi vardır; çeşitli yazılım ölçütleri toplanıp veri tabanında saklanmaya başlanır.
  - Düzey 4: toplanan ölçütlerin analizi yapılır. <!-- BELİRSİZ: altyazıda "iletişimsel analizi" geçiyor, büyük olasılıkla "istatistiksel analiz"; bu slaytın karesi okunmadı. -->
  - Düzey 5: gereksinimler, kullanılan teknikler ve proje yönetimi süreçleri (kod ve proje ölçütleriyle) sürekli değerlendirilir ve iyileştirilir.
- Gereksinim mühendisliğine giriş (ekrandan, 02:10:00)
  - Üzerinde çalışılmaya başlanacak projenin amaçlarını, boyutlarını ve etkilerini belirlemeye yönelik çalışmalardır; genel proje yönetimindeki yapılabilirlik (feasibility) çalışmasına bir girdi olarak düşünülebilir.
  - Müşterinin kafasında çoğunlukla yalnız genel bir fikir vardır; yoruma açık gereksinimler projenin başarısızlığına davetiye çıkarır; kesin belirlenmiş gereksinimler bile zamanla değişebilir.
  - "Şeytan ayrıntıda gizlidir." "Yanlış veya eksik işi yapan mükemmel yazılım değil, doğru işi yapan iyi çözüm gereklidir."
  - Gereksinimler SRS (Software Requirements Specification) belgesinde toplanır. Standartlar: IEEE 830-1998 (SRS odaklı) ve ISO/IEC/IEEE 29148:2011 (Systems and Software Engineering, Life Cycle Processes, Requirements Engineering) (ekrandan, 01:30:00).
  - Yazılım geliştirmede kod dışında ortaya çıkan her türlü metin ve şemaya "artefact" (artifakt) denir: kullanım öyküsü metinleri, UML şemaları, yapılandırma dosyaları, mimari şemalar, sunumlar, gözden geçirme sonuç belgeleri vb.
- Gereksinim mühendisliğinin yedi adımı (ekrandan, 01:35:00)
  - Başlangıç (Inception), Bilgi Toplama (Elicitation), İşleme (Elaboration), Pazarlık (Negotiation), Tanımlama (Specification), Doğrulama (Validation), Yönetim (Management).
  - Adımlar gerçeklenecek yazılımın doğasına ve kullanılan sürece göre düzenlenir; yazılım ekibi ve müşteri birlikte çalışmalıdır.
- Nesneye yönelik çözümleme süreci
  - Çözümleme: bir şeyi anlayabilmek için parçalarına ayırmak; işin "nasıl"ını değil "ne"sini anlamaya yönelik çalışmalardır.
  - Uygulama alanının çözümlenmesi (domain analysis): amaç uygulama alanını anlamak ve elde edilen bilgileri analiz modeline taşımaktır (ekrandan, 02:25:00).
  - Kullanım öyküleri (use case) ve örnek bir kullanım öyküsü: NextGenPOS perakende satış programı, "Satış İşlemi".

## Hocanın Özellikle Vurguladığı Kısımlar

- Paydaşlar başlangıç aşamasında belirlenir
  - Sonra değil, gereksinim mühendisliğinin ilk adımında; her paydaşın bakış açısı, onu etkileyebilecek nedenler ve bu etkilerin sonuçları sorularla ortaya çıkarılır.
- Müşterinin katılımı
  - Gereksinimlerin net ve doğru belirlenmesi projenin başarısındaki en önemli etkenlerden biridir. Müşteri katılımı sağlanamıyorsa indirimli fiyatla bir pilot müşteri bulunmalı; o da olmazsa problem alanında konu uzmanı danışmanlık hizmeti alınmalıdır.
- Beklenen gereksinimler tehlikelidir
  - O kadar temeldir ki kullanıcı söylemeyi unutabilir; keşfedilmeden sonraki aşamalara geçilirse sonradan daha pahalıya mal olur.
- SRS ve gereksinim belgeleri
  - Hem ders hem meslek hayatı açısından bilinmesi önemlidir.
- Müşterinin dilinden konuşmak
  - Kullanılan terimler, kullanıcı arayüzleri ve raporlar müşterinin problem alanındaki terminolojisiyle aynı olmalıdır.
- Kullanım öyküsü yazım kuralları
  - Ana öykünün her adımı mutlaka numaralandırılmalıdır (madde imi kullanılmaz); döngü olmasa bile numara beklenir.
  - Cümleler etken olmalı, her adımı kimin yaptığı açıkça yazılmalıdır.
  - Her şey ana öyküye doldurulmamalı; mutlaka alternatif öykü yazılmalı ve numaralandırma kuralına uyulmalıdır. Varyasyon bulunamazsa, her adımda "başka ne olabilir?" diye düşünülerek (if-else gibi) bir alternatif çıkarılmalıdır.
- İzlenebilirlik tabloları
  - Basit ama az bilinen bir fikirdir; sınama ve bakım aşamalarında hatanın kaynağına hızlı yönlenmeyi sağlar.

## Kısa Tekrar Notları

- Sertifikasyon: büyük müşteriler ister; küçük şirket ve küçük projede ek yük.
- CMMI (SEI, Carnegie Mellon), PMI (bireysel + kurumsal), ISO 9001:2015 (genel), ISO/IEC 90003:2018 (yazılıma özel); Türkiye'de Denetik ve TÜRKAK.
- CMMI düzeyleri: 0 Incomplete, 1 Initial/Performed, 2 Managed/Repeatable, 3 Defined, 4 Quantitatively Managed, 5 Optimized.
- Düzey 3: kişi ve risk yönetimi, kurum çapında tanımlı standart süreçler; büyük müşterilerin asgari beklentisi.
- CMMI-DEV, CMMI-SVC, CMMI-ACQ; v2.0 (2018) ile birleşti. v1.3 (2010) ile çevik süreçler desteklendi.
- Gereksinim mühendisliği adımları: Başlangıç, Bilgi Toplama, İşleme, Pazarlık, Tanımlama, Doğrulama, Yönetim.
- Gereksinim türleri: normal, beklenen, heveslendirici.
- Tanımlama araçları: konuşma dili, kullanıcı senaryoları, kullanım şemaları, formel modeller (derste işlenmeyecek), ön ürün.
- Doğrulama: açıklık, çelişki, hata/eksik, eksik gereksinim, gerçekçilik kontrolü; önerilen yol formal technical review.
- Yönetim: şemsiye adım; değişiklik yönetimi ve izlenebilirlik tabloları (satır: gereksinim, sütun: modül/paket/sınıf).
- Kullanım öyküsü bölümleri: giriş (birincil aktör, ilgililer ve ilgi alanları, ön koşullar, son koşullar), ana öykü, alternatif öyküler.
- Alternatif numarası: "3a" = ana öykünün 3. adımındaki ilk alternatif; "3-7a" = 3. ile 7. adımlar arasında (dahil) herhangi birinde olabilecek ilk alternatif.

## Detaylı Açıklamalar

- Süreç sertifikasyonu neden yapılır?
  - Doğru tanımlanmış bir çalışma biçimiyle üretilen yazılımda projenin başarılı olma şansı ve ürün kalitesi artar. Olgun bir süreç yürüttüğünü kanıtlamak isteyen yazılım evi bunu bağımsız kurumlara onaylatır. Büyük devlet kurumları ve büyük kurumsal firmalar ihalelerde, örneğin "CMMI Level 3 ya da üstü akreditasyona sahip yazılım evleri başvurabilir" diye şart koyabilir. Ne kadar yetenekli olunursa olunsun, başarıların şansa mı yoksa çalışma disiplinine mi bağlı olduğu bu tür bir belge olmadan kanıtlanamaz.
  - Sertifikasyon ayrı bir uzmanlık alanıdır; başvuran kurumlarda bu işe ayrılmış birimler ya da komisyonlar olabilir. Başvurmadan önce süreçlerin belgelendirilmesi ve geçmiş dönemlere ait kanıtların biriktirilmesi gerekir.
  - Hoca, yurt dışı ya da yurt içi bir iş teklifi alındığında firmanın CMMI ya da ISO akreditasyonuna bakılmasını önerir; yazılıma özgü CMMI akreditasyonu olan bir firmada kariyere başlamanın değerli olduğunu söyler.
- CMMI düzeylerinin anlamı
  - Düzey 1'de etkinlikler yapılır ama nasıl yapılacağına dair somut kural yoktur; yeni gelen çalışan ne yapacağını ancak mevcut çalışanların yanında zaman geçirerek öğrenir, anahtar bir çalışanın kısa süre yokluğu bile kaosa yol açabilir.
  - Düzey 2'de bir iş planlama ve izleme yöntemi vardır (bunun için özel bir yazılım şart değildir). İzleme işini ekip üyelerinden biri ya da profesyonel bir proje yöneticisi yapabilir.
  - Düzey 3'te her görev için neyin nasıl yapılacağı ve kimlerle hangi kurallarla etkileşileceği belgelendirilmiştir; yeni başlayan bir çalışan ya da stajyer bu kurumsal eğitim kaynaklarından temel bilgiyi edinir ("sudan çıkmış balık gibi" olmaz).
  - Hoca, 2. düzey için "Repeatable" adının daha iyi olduğunu düşünür; çünkü 4. düzey de "Quantitatively Managed" olduğundan "Managed" sözcüğü karışıklık yaratabilir.
- CMMI ve çevik süreçler
  - 2010 öncesinde çevik çalışma ile CMMI'nin ayrıntılı belge ve süreç yönetimi beklentisi arasında belirgin bir çelişki vardı. v1.3 ile çevik süreçler desteklenmeye başladı; XP ya da Scrum gibi bir çevik süreci belirli olgunlukta işleten yazılım evi ek çabayı en aza indirerek en az Level 3 akreditasyon alabilir.
  - Microsoft'un geliştirme ortamında (Azure DevOps) ve IBM Rational'da yeni proje başlatırken kullanılabilecek hazır süreç şablonları vardır; hoca CMMI ve çevik çalışmaya uygun şablonları gördüğünü söyler. <!-- BELİRSİZ: altyazıda ürün adları bozuk ("Azoz", "Azor", "Rachel"); Azure DevOps ve IBM Rational olarak yorumlandı. -->
- CASE araçlarında tümleştirme örnekleri (Düzey 2)
  - Görev yönetimi yazılımında bir gözden geçirme (review) toplantısı tanımlandığında, toplantı yazılımında (Teams, Zoom vb.) otomatik toplantı oluşturulup ilgililere davet gitmesi.
  - Bir hata düzeltmesinin kodu havuza gönderildiğinde otomatik gözden geçirme yapılması, takım liderine bildirim gitmesi ve lider onaylamadan kodun havuza kabul edilmemesi.
  - Yalnız kodun değil, tasarımın (sınıf şemaları, veri modelleri) da yeniden kullanılabilirliği önemlidir.
- Gereksinim mühendisliği adımlarının ayrıntısı
  - Başlangıç: yeni projenin başlatılmasına karar verilen adımdır. Tetikleyiciler: yeni bir iş gereksinimi, mevcut iş süreçlerindeki güçlükler, yeni bir pazar ya da hizmetin fark edilmesi, hatta üst düzey karar vericilerle asansörde ya da kafede yapılan kısa bir konuşma. Paydaş: gerçeklenecek sistemden doğrudan ya da dolaylı olarak yararlanabilecek ve etkilenebilecek herkes; her paydaş sisteme farklı bir açıdan bakar (ekrandan, 01:40:00).
  - Bilgi toplama: herkese tek tek gitmek yerine tüm paydaşların katıldığı toplantılar en verimlisidir. Gündem önemli konuları atlamayacak kadar sıkı, beyin fırtınasını engellemeyecek kadar açık olmalı; düzeni sağlayacak bir oturum başkanı bulunmalıdır. Hoca bu konuda "Robert's Rules of Order" kitabını önerir.
  - İşleme: toplanan "ham" bilgiler işlenir; son kullanıcının ve diğer paydaşların yazılımla nasıl etkileşeceği belirlenip ayrıntılandırılır, kullanım senaryoları ve şemaları yazılmaya başlanır. Eksik bilgiler ilgili paydaşlarla tamamlanır; tekrarlı ya da eş anlamlı ifadeler belirsizlik yaratır, bu yüzden belgenin başına bir sözlük bölümü konup tek bir terim seçilir (ekrandan, 01:45:00).
  - Gereksinim türleri: normal gereksinimler paydaşların sistemden istedikleridir. Beklenen gereksinimler o kadar temeldir ki söylenmeyebilir: kütüphanede ödünç alınan kitabın belli sürede iade edilmesi ya da ansiklopedi gibi temel başvuru kaynaklarının ödünç verilmemesi. Heveslendirici gereksinimler müşteri beklentilerinin ötesindedir, varlığı müşteriyi sevindirir: lüks bir otomobilin kapısında şemsiye tutacağı bulunması gibi. Zaman ya da bütçe sıkıntısında heveslendirici gereksinimler plandan kolayca çıkarılabilir.
  - Pazarlık: paydaş istekleri birbiriyle çelişebilir ya da eldeki insan kaynağı, bütçe ve zamanla karşılanamayabilir; isteklerin makul düzeye çekilmesi gereksinim mühendisliği ekibinin sorumluluğundadır. Tüm paydaşların razı olduğu bir gereksinim listesi elde edilince biter.
  - Tanımlama: pazarlık sonucu "söz uçar, yazı kalır" ilkesiyle belgeye dökülür (ekrandan, 01:55:00). Konuşma dili doğası gereği belirsiz olduğundan mümkün olduğunca az kullanılmalı; kullanıcı senaryoları, kullanım şemaları (UML use case), formel modeller (derste işlenmeyecek) ve bir ön ürün (prototip) birlikte kullanılabilir.
  - Doğrulama: tanımlanmış gereksinimlerin tutarsızlıklara karşı sağlaması yapılır; önerilen temel yol formal technical review'dur (ekrandan, 02:00:00). Belgeyi hazırlayan konu uzmanı kendi bildiği için belirsizliği göremeyebilir ("hipermetrop" benzetmesi); başka bir okuyucu belirsizliği kendi kafasına göre netleştirip hatalı kodlayabilir.
  - Yönetim: bütün yazılım sürecini kapsayan şemsiye adımdır. Gereksinim değişikliklerinin hangi şartlarla sürece dahil edileceği önceden (sözleşmede) belirlenmeli; gereksinimlerin gerçeklenmesi ve değişiklikler izlenmelidir (ekrandan, 02:05:00).
- İzlenebilirlik tablosu (ekrandan, 02:05:00)
  - Satırlarda gereksinimler (G1, G2, ...), sütunlarda sisteme çeşitli bakış açıları (B1, B2, ...: modüller, paketler, sınıflar vb.) bulunur; her bakış açısı için ayrı tablo tutulur.
  - Slayttaki örnek: G1 → B1 ve B3; G2 → B2; G3 → B1.
  - Bir hata hangi gereksinimle ilgiliyse, o gereksinimi gerçekleyen birkaç bileşene doğrudan bakılır; özellikle kodu yazan kişi değil başka biri düzeltecekse büyük çaba tasarrufu sağlar. CRC kartları hazırlandıysa sınıf düzeyindeki tablo için gereken bilgi zaten vardır.
- Uygulama alanının çözümlenmesi
  - Bilgi kaynakları: teknik literatür (en önemlisi), mevcut uygulamalar (rakipler), müşteri anketleri, uzman tavsiyeleri, mevcut ve gelecekteki gereksinimler (ekrandan, 02:25:00).
  - Problem alanı bilinmeden "müşterinin dilinden konuşulamaz": kütüphaneciler "dergi" değil "süreli yayın" der, çünkü yayınlar haftalık, aylık, üç aylık ya da yıllık olabilir; lojistikte birden fazla taşıma türünün art arda kullanıldığı taşımaya "multimodal taşımacılık" denir.
- Örnek gereksinimler belgesi: NextGenPOS (ekrandan, 02:50:00)
  - Örnek Craig Larman'ın kitabından alınmıştır ve dersin ilerleyen bölümlerinde çözümleme ve tasarım çalışmaları bu örnek üzerinden yürütülecektir.
- Kullanım öyküleri
  - Programın yapacağı işleri ayrıntılı adımlarla ve belli kurallara uyarak anlatan belgelerdir. Amaçları: ürünün işlevlerini ve çalışma ortamını belirlemek, son kullanıcı ve yazılım ekibi arasında anlaşma zemini oluşturmak, kullanıcı ile sistemin etkileşimini açık ve belirsizlikten uzak tanımlamak, doğrulama testleri için zemin oluşturmak (ekrandan, 02:30:00).
  - Bölümler: giriş (sistemin neyi hangi koşullar ve sınırlar içinde yapacağı), ana senaryo / ana başarılı akış, alternatif senaryolar.
  - Satış İşlemi giriş bölümü (ekrandan, 02:35:00): birincil aktör kasiyer; ilgililer kasiyer (doğru ve hızlı giriş ister, kasa açığı maaşından kesildiğinden ödeme hatası istemez), satıcı (satış komisyonlarının güncellenmesini ister), müşteri (en az çabayla hızlı hizmet ve ürün iadesinde kullanmak üzere fiş ister); ön koşul: kasiyerin kimliği doğrulanır; son koşullar: ödeme tahsil edilir, satış kaydedilir, fiş yazılır.
  - Aktör: sistemle etkileşimde bulunan varlıklar (insan, yazılım ya da donanım). Birincil aktör senaryonun odağındaki, en çok katkıyı yapan aktördür; hoca, birincil aktörün akışlar yazıldıktan sonra gözden geçirilip kesinleştirilmesini önerir.
  - Ana öykü (ekrandan, 02:40:00): 1-11 numaralı adımlar; 5. adım "Kasiyer 3. ve 4. adımları müşterinin alacağı tüm ürünler için tekrarlar" bir döngü kurar, numara olmadan bu döngü yazılamaz.
  - Alternatif öyküler (ekrandan, 02:45:00): "3a. Geçersiz barkod" ve "3-7a. Müşteri bir kalem malı alışverişten çıkartmak ister"; tek alt adım olsa bile numaralandırılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
