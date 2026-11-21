# Ders 3 Çalışma Özeti

## Genel Konular

- Bağlam (context) kategorileri: operasyonel bakış açısı
  - Bağlam, kavramsal açıdan dört boyutta ele alınır: konum (location), kimlik (identity), zaman (time) ve aktivite (activity). Operasyonel açıdan her boyut birincil (primary) ve ikincil (secondary) olmak üzere ikiye ayrılır (ekrandan, 00:10:00).
  - Birincil bağlam doğrudan sensörden okunan bilgidir: GPS'ten enlem-boylam, RFID etiketinden kullanıcı kimliği, saatten zaman, kapı sensöründen kapı açılma aktivitesi.
  - İkincil bağlam birden fazla veriden çıkarım yapılarak elde edilir: iki sensör arasındaki mesafenin GPS değerlerinden hesaplanması, harita servisinden harita görüntüsü alınması, Facebook profilinden arkadaş listesi çekilmesi, yüz tanıma ile kişinin belirlenmesi, hava durumundan mevsim hesaplanması, mevcut aktivite ve takvimden zaman tahmini, takvimden ya da telefon sensörlerinden (GPS, jiroskop, ivmeölçer) kullanıcı aktivitesinin bulunması.
  - Tek bir zaman bilgisinden gün, haftanın günü, gece/gündüz, mevsim ve ay gibi bilgiler türetilebilir. Bu, veriden bilgiye (information) giden yoldur.
- RFID ve QR kod
  - Günümüzde RFID'nin rakibi QR koddur. QR kod ucuz ve yaygındır ama görüş hattı (line of sight) gerektirir ve okumalar birer birer yapılır.
  - RFID'nin maliyeti pasif/aktif etiket türüne göre değişir; görüş hattı gerektirmez, toplu eşya giriş-çıkışını aynı anda yönetebilir. Hoca bunu "biri seri, biri paralel" diye benzetti.
- Ham veri, öznitelik çıkarma ve derin öğrenme
  - Aktivite tanımada jiroskop ve ivmeölçer gibi sensörlerin ham verisiyle eğitilen sistemlerin başarısı bir sınıra dayanır.
  - Hocanın ekibinin çalışmasında medyan, standart sapma, sıfır geçiş oranı (zero crossing rate) gibi zaman alanı öznitelikleri ham veriden çıkarılıp derin öğrenmeye verildiğinde başarı arttı.
  - Öznitelikler zaman alanı, frekans alanı ve zaman-frekans alanı olmak üzere üç uzayda incelenir; bunlar ilerleyen derslerde işlenecek.
- Aktivite tanımada sensör seçimi
  - Önce kişinin bulunduğu ortam (iç/dış mekân) anlaşılmalıdır. GPS'ten belli bir süre (örneğin 2, 5, 10 dakika) değişim gelmiyorsa kişi kapalı ortamda ya da hareketsizdir; bu durumda daha az enerji tüketen sensörlere geçilir.
  - Çalışmalar jiroskop, ivmeölçer ve manyetometrenin birlikte kullanılmasının en iyi sonucu verdiğini gösterir; üçü de düşük enerjili sensörlerdir.
  - Kapalı mekânda (örneğin yaşlı bakımında) RGB ve derinlik (depth) kameraları da kullanılır. Kameranın maliyet, enerji, kurulum ve mahremiyet sorunları vardır.
- Toplumsal bağlam algılama
  - Havalimanı gibi kalabalık alanlarda kamera görüntülerinden insan hareketlerindeki anomalilerin tespiti.
  - En büyük sorun anormal davranış örneklerinin çok az olmasıdır; bu yüzden normal davranış öğretilir, normalden sapma yakalanır (anomali tespiti, aykırı değer tespiti). Aynı durum dolandırıcılık (fraud), ağ saldırısı ve zararlı yazılım tespitinde de geçerlidir.
  - Toplu taşımada araçtaki kişi sayısının bulunması: kapıda kafa sayan kamera, kart okutma (yalnız binişi yakalar), kızılötesi/ultrasonik sensörler (kalabalıkta zor) ve Bluetooth ile cihaz tespiti.
  - İBB trafik hızı tahmininde Bluetooth kullanılır: iki noktada aynı cihaz okunur, aradaki zaman farkından hız hesaplanır.
  - Mağaza ve alışveriş merkezlerinde Bluetooth ile raf önünde geçirilen süre ve izlenen rota analiz edilir.
- Veri toplama sıklığı ve enerji
  - Bağlam verileri değişme sıklığına göre dört türe ayrılır: algılanan (sensed), statik (static), profil (profiled) ve türetilmiş (derived) (ekrandan, 00:35:00).
  - Toplama sıklığı arttıkça sensörün yanında işlemci de daha sık uyanır. Bu yüzden telefonlara ana CPU dışında sensörlerden sorumlu hareket işlemcisi (motion processor) eklendi; ana işlemci uyku moduna alınabilir.
  - Telefondaki başlıca enerji tüketicileri: ekran, sürekli sensör okuma, haberleşme ve CPU'da yapılan işlem (özellikle görüntü/video işleme).
  - Haberleşme, algılamadan daha fazla enerji harcar. İletim enerjisi uzaklığın karesiyle orantılı artar; kapalı alan ve zayıf sinyal enerji tüketimini artırır.
  - 2G/3G birim zamanda daha az güç tüketir ama büyük veride aktarım uzun sürdüğü için toplam enerji daha fazladır. Yalnız ses için 2G, büyük veri için 4G tercih edilebilir.
- Telefonda derin öğrenme
  - Kaynak gerektiren kısım eğitimdir. Eğitim sunucuda ya da bulutta yapılır, eğitilmiş model telefona veya saate yüklenir; çıkarım basit aritmetik işlemlerden oluşur.
  - Model güncellemesi gerekirse yeniden eğitim sunucuda yapılıp parametreler cihaza aktarılır.
- Bağlam farkındalığının seviyeleri
  - Kişiselleştirme (personalisation): kullanıcı tercihleri (örneğin akıllı evde oda sıcaklıkları) sisteme öğretilir; şartlar ve kullanıcı değişince model de güncellenmelidir.
  - Pasif bağlam farkındalığı: sistem bağlamı algılar ve kullanıcıyı bilgilendirir ama müdahale etmez.
  - Aktif bağlam farkındalığı: sistem bağlamı algılar ve eyleyiciler (actuator) ile müdahale eder (örneğin yangında sulama sistemini çalıştırmak).
- Sürekli öğrenme
  - Makine öğrenmesi modelleri genellikle bir kez eğitilip uzun süre güncellenmeden kullanılır. Dolandırıcılık tespitinde model güncellenmezse başarı ay ay düşer.
  - Karar ağacı gibi sığ yöntemlerde yeni veri gelince model bütün veriyle yeniden kurulmalıdır. Yapay sinir ağlarında mevcut ağırlıklar yeni veriyle güncellenebilir; bu, değişen sistemlerde avantaj sağlar.
- Bağlam farkındalıklı sistemlerin özellikleri ve yaşam döngüsü
  - Sekiz özellik: sensörlerle algılanır, küçük ve kısıtlı cihazlarla algılanır, dağıtık kaynaklardan gelir, sürekli değişir, mobil nesnelerden gelir, zamansal ve mekânsal karaktere sahiptir, kusurlu ve belirsizdir (ekrandan, 01:00:00).
  - Temel yaşam döngüsü: bağlam edinimi (acquisition), modelleme, çıkarım (reasoning), yayma (dissemination).
  - Literatürde farklı yaşam döngüleri vardır: sözlü olarak Information Lifecycle Management ve Intelligence Cycle; ekranda Chantzara ve Anagnostou, Ferscha ve ark., MOSQUITO, WCXMS, Baldauf ve ark. (ekrandan, 01:15:00).
- Dijital unutma (digital forgetting)
  - Cihazların ürettiği verinin otomatik ve akıllı biçimde silinmesi gerekecek. Bugünkü sistemler genelde yalnız öneri verir, karar veremez.
- Bağlam edinimi (context acquisition)
  - Sorumluluğa göre (pull/push), sıklığa göre (anlık/aralıklı olaylar), kaynağa göre (sensör donanımı, ara katman, bağlam sunucusu), sensör türüne göre (fiziksel, sanal, mantıksal) ve edinim sürecine göre (algılama, türetme, el ile) sınıflanır (ekrandan, 01:25:00).
  - Sanal sensörler: takvim, rehber, Twitter durumları, e-posta ve sohbet uygulamaları. Twitter'dan duygu analizi ve afet anında olay tespiti yapılabilir.
  - Mantıksal sensörler: fiziksel ve sanal sensör verisini birleştirip çıktı üretir (örneğin sıcaklık, basınç, görüş ve yağıştan hava durumu bilgisi).
- Bağlam modelleme
  - Anahtar-değer, işaretleme şeması (XML, JSON, ContextML), grafiksel (UML, ORM), nesne tabanlı, mantık tabanlı ve ontoloji tabanlı modelleme (ekrandan, 01:30:00).
  - Ontoloji, bir alanın kavramlarını ve aralarındaki ilişkileri hiyerarşik olarak ortaya koyar. Aktivite ontolojisinde iç/dış ortam ya da basit/karmaşık aktivite ayrımı yapılabilir.
- Bağlam çıkarımı (context reasoning)
  - Ön işleme, sensör verisi füzyonu ve bağlam çıkarımı ayrı işlerdir. Yöntemler: gözetimli ve gözetimsiz öğrenme, kurallar, bulanık mantık, ontolojik ve olasılıksal çıkarım (ekrandan, 01:40:00).
  - Kural tabanlı sistemler uzman bilgisine dayanır ve statiktir; karar ağaçları veriden, bilgi kazancı (information gain) gibi ölçütlerle kurulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Verinin değişme sıklığı
  - Veriyi ne sıklıkla toplayacağınız sensörün ve cihazın enerji tüketimini doğrudan belirler. Hangi sensörün, hangi sıklıkta ve hangi işlemci birimiyle okunduğu pil ömrünü etkiler.
- Haberleşme her zaman algılamadan pahalıdır
  - İstisnalar dışında iletim, veri toplamaktan daha fazla enerji harcar. Bu yüzden ham veri yerine türetilmiş veri (örneğin iki GPS noktası yerine aradaki fark) göndermek tercih edilebilir.
- 2G/3G ve 4G karşılaştırması
  - Birim başına az güç tüketen teknoloji, aktarım süresi uzadığı için toplamda daha çok enerji harcayabilir.
- Uzman bilgisiyle çıkarılan öznitelikler
  - Ham veriyle eğitilen derin öğrenmeye zaman alanı öznitelikleri eklemek başarıyı artırır; her problemde yalnız ham veri (piksel gibi) yeterli değildir.
- Bilginin güvenilirliği
  - Bağlam farkındalığında en büyük sorunlardan biri bilgiye güvendir. Sosyal medyadan otomatik çıkarım, sahte haber riski taşır; bilgi birden fazla kaynaktan ve güven seviyeleriyle doğrulanmalıdır.
- Karmaşık aktivite tanıma
  - Basit aktiviteler (yürüme, koşma, oturma, uzanma) artık saatle bile kolayca tanınıyor. Karmaşık aktiviteler (yemek yeme, yemek yapma, temizlik, diş fırçalama, spor) alt aktivitelerden oluşur, tek cihazla tanınmaları zordur ve ontoloji ihtiyacı hâlâ araştırma konusudur.

## Kısa Tekrar Notları

- Bağlam boyutları: konum, kimlik, zaman, aktivite; her biri birincil (doğrudan sensör) ve ikincil (çıkarım) olabilir.
- RFID görüş hattı istemez, toplu okuma yapar; QR kod ucuzdur ama görüş hattı ister.
- Veri türleri: sensed (sık değişir), static (değişmez), profiled (seyrek değişir), derived (birincil bağlamdan hesaplanır).
- Enerji: ekran, sensör okuma sıklığı, haberleşme, CPU işlemi. Hareket işlemcisi ana CPU'yu uykuda tutar.
- İletim enerjisi uzaklığın karesiyle artar; zayıf sinyalde telefon daha çok güç harcar.
- Telefonda derin öğrenme: eğitim sunucuda, çıkarım cihazda.
- Seviyeler: kişiselleştirme, pasif (yalnız algıla ve bildir), aktif (algıla ve eyleyiciyle müdahale et).
- Yaşam döngüsü: edinim, modelleme, çıkarım, yayma.
- Sensör türleri: fiziksel, sanal (takvim, Twitter), mantıksal (hava durumu).
- Modelleme: anahtar-değer, XML/JSON/ContextML, UML/ORM, nesne, mantık, ontoloji.
- Anomali tespiti: anormal örnek az olduğunda normali öğret, sapmayı yakala.
- Sinir ağları yeni veriyle güncellenebilir; karar ağacı baştan kurulur.
- Kural tabanlı: uzman bilgisi, statik. Karar ağacı: veriden, bilgi kazancıyla.

## Detaylı Açıklamalar

- Ders, bağlamın operasyonel kategorileriyle başladı (ekrandan, 00:10:00). Tablonun satırları konum, kimlik, zaman ve aktivite; sütunları birincil ve ikincil bağlamdır. Birincil sütunda sensörden doğrudan okunan bilgiler (GPS'ten enlem-boylam, RFID etiketiyle kullanıcı tanıma, saatten zaman okuma, kapı sensöründen kapı açılma aktivitesi) yer alır. İkincil sütunda bunların üzerine çıkarım yapılır: iki sensörün GPS değerlerinden mesafesinin hesaplanması, harita servisinden harita görüntüsü, Facebook profilinden arkadaş listesi, yüz tanıma, hava durumundan mevsim hesabı, mevcut aktivite ve takvimden zaman tahmini, takvimden ya da telefon sensörlerinden aktivite tahmini. Hoca zaman örneğini açtı: bir bankacılık uygulamasının "günaydın" ya da "iyi akşamlar" demesi zamandan türetilmiş bilgiye dayanır; trafik hızı tahmininde günün saati ve mevsim önemlidir. Takvim ve aktivite bilgisiyle bir evde kimsenin olmaması beklenen saatlerde algılanan hareket alarm üretir; ev halkının evde olduğu saatlerde aynı hareket için alarm üretmek yanlış pozitif olur.
- Hoca, bahçeye gelen kediyi kamerayla tanımaya çalışan bir sistem hikâyesiyle derin öğrenmenin veriyle öğrendiğini anlattı: başta az veri yüzünden sistem kediyi tanıyamamış, veri çoğaldıkça yüksek oranda tanımaya başlamış. Verinin çeşitliliği önemlidir; yalnız önden çekilmiş fotoğraflarla yan açıdaki kedi öğrenilemez. Ancak insan tecrübesiyle çıkarılan özniteliklerin eklenmesi başarıyı artırır. Hocanın ekibinin aktivite tanıma çalışmasında ham sensör verisinden medyan, standart sapma ve sıfır geçiş oranı gibi zaman alanı öznitelikleri çıkarılıp derin öğrenmeye verildiğinde ham veriyle ulaşılan sınır aşılmıştır.
- Aktivite tanıma için sensör seçimi sorusunda önce ortamın anlaşılması gerektiği vurgulandı. GPS konumu belli bir süre sabit kalıyorsa kişi kapalı alanda ya da hareketsizdir; kapalı alanda GPS ayrıntı sağlamadığı için daha az enerji tüketen sensörlere geçilir. Jiroskop, ivmeölçer ve manyetometre birlikte en iyi sonucu verir. Kapalı alanda RGB ve derinlik kameraları ayrıntılı aksiyon bilgisi sağlar ama maliyet, enerji, kurulum ve mahremiyet sorunları vardır.
- Toplumsal bağlam örneklerinde havalimanı kameralarıyla şüpheli davranış tespiti ele alındı. Anormal davranış verisi çok az olduğundan sistem kötü örneği öğrenemez; çözüm normal davranışı öğretip sapmayı yakalayan anomali tespitidir. Ağ güvenliği ve zararlı yazılım tespitinde de yeni saldırı tipleri önceden öğretilemediği için aynı yaklaşım kullanılır. Toplu taşımada araçtaki kişi sayısının bilinmesi hem sefer planlaması hem araçların dengesiz yüklenmeden yıpranmasının anlaşılması için önemlidir. Kart okutma yalnız binişi gösterir; kızılötesi veya ultrasonik kapı sensörleri kalabalıkta işe yaramaz; Bluetooth ile cihaz tespiti bir seçenektir. İBB, yol kenarındaki tabelalarda Bluetooth cihazlarını iki noktada okuyup zaman farkından hız hesaplamaktadır. Hoca, sürekli açık Bluetooth'un günlük pil tüketiminin yaklaşık yüzde üçün altında kaldığını söyledi.
- Veri türleri slaytında (ekrandan, 00:35:00) algılanan veri (sıcaklık sensörü gibi sık değişen), statik veri (üretici, sensör yetenekleri, ölçüm aralığı), profil verisi (sensör konumu veya kimliği gibi ayda bir değişen) ve türetilmiş veri (iki GPS sensörünün mesafesi gibi birincil bağlamdan hesaplanan) tanımlandı. Ana fikir verinin değişme sıklığıdır. Sık toplanan veri hem sensörü hem işlemciyi meşgul eder. Apple'ın öncülük ettiği hareket işlemcisi sensör verisini ana CPU'dan bağımsız toplar, ana CPU uykuda kalabilir. Haberleşme algılamadan daha fazla enerji harcar (hoca kabaca algılama bir birimse haberleşmenin iki birime kadar çıkabildiğini söyledi). İletim enerjisi uzaklığın karesiyle artar. Pil azken arama, açık alanda ve baz istasyonuna yakın yerde yapılmalıdır; zayıf sinyalde telefon çıkış gücünü artırarak daha çok enerji harcar.
- Derin öğrenmenin telefonda çalıştırılması tartışıldı. Mobil GPU benzeri donanımlar katkı sağlasa da asıl nokta eğitim aşamasının ağır olmasıdır. Eğitim sunucuda yapılır, eğitilmiş model cihaza yüklenir; çıkarım ağırlıklarla girdilerin çarpılıp toplanmasından ibarettir. Model sık güncellenmesi gerekiyorsa yeniden eğitim gece sunucuda yapılıp parametreler cihaza gönderilebilir.
- Bağlam farkındalığının üç seviyesi (ekrandan, 01:00:00): kişiselleştirmede kullanıcı tercihleri (akıllı evde her odanın istenen sıcaklığı) öğrenilir. Pasif bağlam farkındalığında sistem durumu algılar ve bildirir (süpermarkete girince indirimli ürün listesi gösterilmesi). Aktif bağlam farkındalığında sistem müdahale eder (duman ve sıcaklık sensörü yangını algılayınca itfaiyeye ve ev sahibine otomatik haber verilmesi, sulama sisteminin çalıştırılması). Kişiselleştirme bağlamında hoca, makine öğrenmesi modellerinin genelde bir kez eğitilip uzun süre değişmeden kullanıldığını eleştirdi. Dolandırıcılık tespitinde model güncellenmezse başarı aydan aya düşer. Karar ağacı veya rastgele orman yeni veri geldiğinde bütün veriyle yeniden kurulurken, sinir ağının ağırlıkları yeni veriyle güncellenebilir. Hocanın aktivite tanıma çalışmasında rastgele orman ile ham veri üzerinde çalışan derin öğrenmenin başarısı birbirine çok yakın çıkmıştır; değişmeyen sistemlerde ağaçlar, evrilen sistemlerde sinir ağları daha mantıklıdır.
- Bağlam farkındalıklı sistemlerin sekiz özelliği ve yaşam döngüsü ele alındı. Temel döngü edinim, modelleme, çıkarım ve yaymadır. Literatürdeki döngüler arasında Information Lifecycle Management (oluşturma, alma, dağıtım, kullanım, bakım, elden çıkarma) ve Intelligence Cycle (toplama, işleme, analiz, yayın, geri bildirim) sözlü olarak anlatıldı; ekranda Chantzara ve Anagnostou (sense, process, disseminate, use), Ferscha ve ark. (sensing, transformation, representation, rule base, actuation), MOSQUITO, WCXMS ve Baldauf ve ark. (sensors, raw data retrieval, preprocessing, storage, application) döngüleri yer aldı (ekrandan, 01:15:00). Döngülerin sonundaki silme aşaması dijital unutma kavramına bağlandı: cihazların ürettiği büyük veri miktarı otomatik ve akıllı silme mekanizmaları gerektirecek, bu da hocaya göre doktora düzeyinde bir araştırma konusudur.
- Bağlam edinimi beş ölçüte göre sınıflandı (ekrandan, 01:25:00). Sanal sensör örneği olarak Twitter öne çıktı: duygu analizi, toplulukların saldırganlık düzeyinin ölçülmesi, afet anında etiket yoğunluğundan olay tespiti. Hoca, otomatik çıkarımların sahte haber riski taşıdığını, bilginin birden fazla kaynak ve güven seviyeleriyle (sertifika otoriteleri gibi) doğrulanması gerektiğini vurguladı. Mantıksal sensör, alttaki verileri birleştirip kullanıcıya yalnız sonucu (hava durumu) verir.
- Bağlam modellemede (ekrandan, 01:30:00) anahtar-değer yapısının mobilde (Android) sık kullanıldığı, nesne tabanlı saklama ve SQLite'ın yanında Firebase'in yaygınlaştığı söylendi. Ontoloji tabanlı modelleme hayvanlar alemi örneğiyle açıklandı: en üstte "hayvan", altında memeliler, sürüngenler gibi gruplar. Aktivite ontolojisinde iç/dış ortam ayrımı bazı aktiviteleri baştan eler (içeride basketbol olasılığı düşüktür); dış ortam aktiviteleri motorlu taşıtla yapılanlar (metrobüs, araba, minibüs, tren, uçak) ve kişinin kendi hareketleri (koşma, yürüme, durma, oturma) olarak ayrılabilir. Başka bir ontoloji basit ve karmaşık aktiviteleri ayırır; karmaşık aktivite, basit aktivitelerden oluşan aktivitedir.
- Bağlam çıkarımında (ekrandan, 01:40:00) ham verinin ön işlenmesi ile birden fazla kaynaktan gelen verinin füzyonu ayrı işlerdir. Slayttaki pasta grafiğe göre tüm uygulamalarda kurallar yüzde 54, karar ağacı yüzde 15, Naive Bayes ve gizli Markov modelleri yüzde 13'er, destek vektör makineleri yüzde 4, k-en yakın komşu yüzde 2 paya sahiptir; tanıma uygulamalarında en çok karar ağacı kullanılmıştır. Kural tabanlı sistem ile karar ağacının farkı: kural tabanlı sistemde kurallar uzman tecrübesinden, veri dağılımı gözetilmeden yazılır (hava yolu şirketinin çalıntı kartla bilet alımına karşı lokasyon, ücret ve destinasyon kuralları gibi); karar ağacında ise bilgi kazancı gibi ölçütlerle en ayırt edici öznitelik köke yerleştirilir ve ağaç veriye göre kurulur, yeni veriyle güncellenebilir. Son slayttaki taksonomi edinim, modelleme, çıkarım ve yayma tekniklerini tek şemada toplar (ekrandan, 01:45:00).
- **Ders sonrası not:** Hoca "en çok Decision Tree'ler var" dedi. Slayttaki grafiğe göre tüm uygulamalarda en büyük pay kurallarındır (yüzde 54); karar ağacı yalnız tanıma uygulamalarında en sık kullanılan yöntemdir (ekrandan, 01:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
