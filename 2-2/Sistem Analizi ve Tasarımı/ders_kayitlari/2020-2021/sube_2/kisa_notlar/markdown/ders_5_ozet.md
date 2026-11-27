# Ders 5 Çalışma Özeti

## Genel Konular

- Analiz aşamasına geçiş (ekrandan, 00:15:00)
  - Önceki derslerde bilgi sistemi türleri, taraflar, süreç modelleri, ön inceleme ve fizibilite (özellikle zaman fizibilitesi, Gantt/PERT, iş kırılım yapısı) işlenmişti.
  - Bu dersin kapsamı slayttaki dört başlıktır: Gereksinim Analizi, İş Analizi, Kullanım Senaryoları, Bilgi Toplama Yöntemleri.
  - Analiz, yazılım geliştirme yaşam döngüsünde fizibiliteden sonraki adımdır; her adım bir öncekinden beslendiği için atlanmamalıdır.
- Gereksinim analizinin tanımı
  - Problemin ne olduğu, çözüm yaklaşımlarının neler olacağı ve problemi çözen sistemin nasıl çalışacağıyla ilgili soruların cevaplarını bulmak için yapılan işlemler bütünüdür.
  - Amaç, en uygun çözümü sağlayan ana öğeleri, yani sistemin işlevlerini (sorumluluklarını) bulmak ve ayrıntılarıyla tanımlamaktır.
  - Bu aşamada henüz bir sistem yaratılmaz; iş (business) anlaşılıp teknik dile çevrilir.
  - Çıktılar: kullanıcının ihtiyaç duyacağı bütün gereksinimler, varsa mevcut sistemin durumu, en uygun çözümün nasıl seçildiği, mevcut sistemin iyileştirme önerileri.
- Gereksinim analizinde öncelikle yapılacaklar (ekrandan, 00:20:00)
  - Fizibilite raporları gözden geçirilmeli.
  - Tüm teknik (alana özgü) terimler incelenmeli; örneğin öğrenci bilgi sisteminde ön koşullu ders ve AGNO.
  - Ayrıntılı inceleme planı yapılmalı, proje grubunun görev dağılımı yapılmalı, denetleme mekanizması kurulmalı.
  - İlk ikisi analizle, son üçü proje yönetimiyle ilgilidir.
- Mevcut sistemin incelenmesi
  - Mevcut bir sistem varsa sistem analisti kullanılan bilgileri ve miktarlarını, donanım ve yazılım kaynaklarını, iç ve dış paydaşlarla bilgi transferini, diğer sistemlerle haberleşmeyi, çalışma sürelerini ve performansı, raporlama ve arşivlemeyi, personeli ve maliyetleri ortaya koyar.
  - Mevcut sistem yoksa iş analizi yapılarak işin kendisi anlaşılır.
- Sistem analizi yöntemleri (ekrandan, 00:25:00)
  - Gereksinimler önceden müşteri ile saptanırsa akış diyagramları gösterimi kullanılır: bilişim alanı, işlevler, ara birimler, kabul kriterleri belirlenip diyagramlarla gösterilir. Kontratlı işler (ihale, savunma sanayii) buna örnektir.
  - Gereksinimler önceden saptanmazsa prototip oluşturulur ve prototip üzerinden müşteri ile tartışılarak gereksinimler kararlaştırılır.
- Sistem Gereksinimleri Spesifikasyonu, SRS (ekrandan, 00:30:00)
  - Analist ve müşterinin ortak çalışmasıyla sistem gereksinimlerinin özellikleri belge haline getirilir: sistem gereksinimleri spesifikasyonu ya da sistem prototipi.
  - SRS, Software/System Requirements Specification demektir; IEEE 830 bu belgenin resmi bir formatını tanımlar.
  - SRS'te işlevsel ve işlevsel olmayan gereksinimler, sistemin sorumlulukları ve sınırları, kalite unsurları (örneğin eş zamanlı kullanıcı sayısı, sistem tepkisi) yer alır.
  - Sistem geliştirme planı (Gantt) da gözden geçirilir; sistem geliştirme planı ile sistem analizi iç içe yürür (tanımlama aşaması).
- Analiz sürecinin akışı
  - Yazılım planı (project charter, fizibilite) idari incelemeden geçer. Gereksinimler biliniyorsa yazılır, bilinmiyorsa prototip/model oluşturulur.
  - Ara çıktı olarak iş gereksinimleri dokümanı (BRD) üretilebilir; ardından SRS yazılır, teknik ve yönetim incelemesinden geçer, onaylanırsa tasarıma geçilir, onaylanmazsa revize edilir.
  - Yönetim incelemesinde işletme stratejisiyle uyum, deneyim ve öngörü, finansal fayda, az organizasyonel değişiklik, iyi raporlama ve bilgi akışı, hız ve yeni teknoloji gözetilir.
- Kullanım senaryosu (use case) modellemesi (ekrandan, 00:35:00)
  - İş gereksinimlerinin bulunması ve tanımlanması için kullanılan formal bir iş analizi yaklaşımıdır.
  - Kullanıcının bakış açısından sistemin fonksiyonel çözümlemesini tanımlar; sistemin ihtiyaçlarını yerine getirmek için gereken davranışları belirlemek için kullanılır.
  - Aktörler: kullanıcılar, dış sistemler, fiziksel çevre etmenleri. Aktörün insan olması gerekmez (GPS cihazı da aktördür).
  - Senaryolar: bir olay akışı şeklinde sistemce sağlanan fonksiyonellik; ön koşulları, son koşulları, ana senaryosu, birincil ve ilgili aktörleri olmalıdır.
  - Çevik süreçlerde use case'lerin yerini daha hafif kullanıcı hikayeleri (user story) almaya başlamıştır; büyük sistemlerde use case kullanımı sürer.
- Use case diyagramının bileşenleri
  - Aktör (çöp adam), ilişki (çizgi), senaryo (elips içinde ad), sistem sınırı (dikdörtgen; zorunlu değil).
  - Aktörsüz senaryo ve senaryosuz aktör olmaz.
- Örnek diyagram: okul servisi / filo takip sistemi (ekrandan, 00:45:00)
  - GPS System aktörü "Report location" senaryosuyla ilişkilidir.
  - Adı yazılmamış ikinci aktör "Find arrival times" ve "Report error" senaryolarıyla ilişkilidir.
  - Üç senaryo sistem sınırını gösteren dikdörtgenin içindedir.
- Senaryoların ifade edilmesi (ekrandan, 00:50:00)
  - İhtiyaç-özellik listesi değildir; sistem kara kutu olarak alınır, sorumlulukları ifade edilir.
  - Aktör-sistem etkileşimi etken cümlelerle söylenir.
  - "Ne yapar?" cevaplanır; "Nasıl yapar?" tasarımın sorusudur.
  - Sistemin bitmiş hali hayal edilir, oluşabilecek senaryolar yazılır; sistemin sınırları doğru belirlenmelidir.
- Kullanım senaryosunda yer alan bilgiler (ekrandan, 00:55:00)
  - Önsöz: senaryo kodu ve adı (örneğin UC1: Find arrival times), birincil aktör, ilgililer ve beklentileri, ön koşullar, son koşullar.
  - Ana başarılı senaryo: en doğal çalışma şekli adım adım, koşulsuz ve dallanmasız, etken cümlelerle yazılır. Üç cümle tipi: kullanıcı-sistem etkileşimi/tetikleme, onaylama, durum değişikliği/bilgi kaydı.
  - Alternatif akış: başarılı ya da başarısız sonuçlara götüren dallanmalar (4a, 4b gibi numaralanır).
  - Sıra dışı durumlar (hata olunca yapılacaklar), özel istekler (hız, güvenlik gibi kalite kısıtları), teknolojik beklentiler (dil, platform).
- Senaryolar arası ilişkiler (ekrandan, 01:00:00)
  - İçerme (include): birçok senaryo grubunda kullanılan başka bir senaryo grubu; alt programa dallanıp geri dönmek gibi (login, SMS atma, sıra numarası alma, bakiye güncelleme).
  - Genişletme (extend): belirli koşulda ana senaryodan ayrılma noktasından sonra çalışan senaryo.
  - Özelleştirme: genel senaryodan özel senaryolar türetilir (ödeme → nakitle, kartla, çekle). Çoğu zaman genişletme ile de ifade edilebilir; en çok içerme ve genişletme kullanılır.
  - Aktör ile senaryo arasındaki ilişki bağıntı (association) ilişkisidir. Bazı araçlarda yönlü ok birincil aktörü, yönsüz çizgi destek aktörünü gösterir.
  - Aktörler arasında genelleştirme (kalıtım) kurulabilir; ortak işlevler soyut bir aktörde toplanır.
- Genişletme örneği: hastane bilgi sistemi (ekrandan, 01:15:00)
  - Hasta, "Tahlil Ver" ve "Tahlil Sonucu Al" senaryolarının birincil aktörüdür; Laboratuvar "Tahlil Ver" senaryosunun destek aktörüdür.
  - "Kısa Mesaj At", "Tahlil Ver"i genişletir; "e-posta ile sonuçları gönder", "Sonuçlar Çıktıysa" koşuluyla "Tahlil Sonucu Al"ı genişletir.
  - Genişletilen senaryo tek başına anlamlı olmalı, eklenti olmadan da davranış sergileyebilmelidir.
- Banka örneği (ekrandan, 01:20:00)
  - Customer: Open Account, Deposit Funds, Withdraw Funds. Bank Employee de Open Account ile ilişkilidir.
  - Calculate Bonus, "Amount over 10,000 or Age over 55" koşuluyla Deposit Funds'u genişletir (extend).
  - Deposit Funds ve Withdraw Funds, Update Balance'ı içerir (include).
  - NRFC Customer, Customer'dan türetilmiştir (genelleştirme) ve ayrıca Convert Currency senaryosuyla ilişkilidir.
  - Hoca, müşteriyle çalışma sürecini canlandırarak diyagrama Clerk aktörü (Deposit ve Withdraw ile ilişkili) ve "End of day calculations" senaryosu ekledi; modelleme artımlı bir süreçtir.
- Sözleşmeler (contracts) (ekrandan, 01:25:00)
  - Karmaşık işlemlerin daha iyi anlaşılması için yazılır; ön koşullar sağlandığında sistemin alacağı son durumu açıklar.
  - Aktör-sistem etkileşimi yanında sistem içi nesnelerdeki değişim de belirtilir. Önemli olan son koşullardır: nesne yaratma/yok etme, özellik güncelleme, bağlantı oluşturma/koparma.
  - Modele eklentiler (nitelik gibi) yapılmasına neden olabilir; işin nasıl yapılacağını göstermez, o tasarımın işidir.
  - Örnek: bölüm kapama senaryosundaki "çalışan çıkartma" işlemi için sözleşme; son koşullar: sistem tüm bölüm çalışanlarının tazminatını hesaplamıştır, çalışanın iş yerine bağlantısı kesilmiştir.
- Araştırma ve bilgi toplama yöntemleri (ekrandan, 01:30:00)
  - Gözleme yaklaşımı: mevcut belge-form-dosya örneklemesi, iş ortamının gözlenmesi.
  - Kişisel görüşme yöntemi (toplantı, mülakat, ortak gereksinim planlaması): yapılandırılmamış ve yapılandırılmış görüşme.
  - Anket yöntemi: açık uçlu ve kapalı uçlu sorular.
- Yapılandırılmış ve yapılandırılmamış görüşme (ekrandan, 01:35:00)
  - Yapılandırılmış görüşme: amaçlar saptanmış, kimle görüşüleceği, zamanı ve yeri belli; taraflara amaç, süre ve gerekli dokümanlar bildirilmiş; sorular belli; sonuçlar hemen değerlendirilip formal olarak yazılır ve ilgililere dağıtılır.
  - Yapılandırılmamış görüşme daha spontane ve esnektir; yeni fikirler çıkar, katılımcı kendini rahat ifade eder; kontrol, doğruluk ve güvenilirlik daha azdır, genişlik ve derinlik daha fazladır.
  - Soru sıralaması: piramit (tümevarım) yapıda kapalı ve ayrıntılı sorulardan açık uçlu sorulara, tümdengelimde açık uçludan kapalıya gidilir.
- Anket yöntemi (ekrandan, 01:40:00)
  - Sorular ve cevap alanlarından oluşan formdur; geniş kitleye yönelik ürünlerde ya da çok büyük iş birimlerinde tercih edilir.
  - İlkeler: açıklık, hatırlatma, cevap arzusu oluşturma (özel yaşamla ilgisiz, kolay, ilgi çekici), hataya engel olma (eleme/kontrol soruları), ifade kolaylığı (görsel öğeler), cevaplayıcıyı şartlandırmama.
  - Avantajlar: hızlı, düşük maliyetli, kimlik gizlenebilir, çok kişiye ulaşır. Dezavantajlar: az katılım, eksik cevaplar, vücut dili gözlenemez, bulanık sorularda net bilgi alınamaz.
- Açık uçlu ve kapalı uçlu sorular (ekrandan, 01:45:00)
  - Açık uçlu: serbest metin; fikir, görüş ve öncelikleri gösterir; yazması ve analizi zahmetlidir, sayısal bilgi almak zordur.
  - Kapalı uçlu: sabit seçenek kümesi (çoktan seçmeli, iki cevaplı, sıralamalı); hızlı cevaplanır ve kolay işlenir, hatırlamayı kolaylaştırır; gerçek duyguları yansıtmayabilir, kişiyi cevaba zorlar, çok fazlası cevaplayıcıyı engellenmiş hissettirir.
  - Anket soruları genelden özele, basitten zora, mantık sırasıyla dizilir; ani konu değişikliğinden kaçınılır.
- İş gereksinimleri dokümanı (BRD) ve araştırma raporu (ekrandan, 01:50:00)
  - BRD içeriği: özet, amaç-hedef, ihtiyaç (sistem neden lazım), kapsam (sınırlar), mali analiz, üst seviyeli işlevsel gereksinimler, kaynak ihtiyacı, iş zaman planı, maliyet-fayda analizi.
  - Alternatif: araştırma raporu. Teknik personel için teknik rapor (başlık, içindekiler, araştırma amacı, metodoloji, sonuç ve öneriler, ekler) ve teknik rapordan sonra yönetici için özet rapor (amaç, yöntem, sonuçlar).
  - Örnek BRD (web sitesi gereksinimleri): değişiklik geçmişi, genel bakış, paydaşlar, etkilenen iş süreçleri, işlevsel ve işlevsel olmayan gereksinim tabloları (ID, gereksinim cümlesi, Must/Want, yorum) (ekrandan, 01:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Analiz aşamasının kilit önemi
  - Dersin adının yarısı "sistem analizi"dir; analiz, yaşam döngüsünün geri kalanını besler. Ne fizibilite ne de analiz "boş ver" denerek geçilmemelidir.
- "Ne" ve "nasıl" ayrımı
  - Analizde ve senaryolarda yalnız sistemin ne yapacağı yazılır; nasıl yapılacağı her zaman tasarıma bırakılır. Sözleşmeler de bu kuralın dışında değildir.
- Senaryolar etken cümlelerle ve kara kutu bakışıyla yazılır
  - Senaryo bir ihtiyaç ya da özellik listesi değildir; kimin ne yaptığı açıkça belirtilerek iş adım adım anlatılır.
- Aktörsüz senaryo, senaryosuz aktör olmaz
  - Hiçbir senaryoyla etkileşmeyen bir taraf sistemin parçası değildir, aktör olarak modellenmez.
- Genişletilen senaryo tek başına çalışabilmelidir
  - Extend ile eklenen davranış olmadan da ana senaryo bir sorumluluğu yerine getirebilmelidir.
- Aktörler sınıflara dönüşür
  - Senaryolar analiz modeline dönüştürülürken aktörler neredeyse her zaman birer sınıf olarak modellenir.
- Sınırların doğru çizilmesi
  - Destek aktörleri ve ilgililer baştan doğru tanımlanmazsa sistemin sınırları çizilemez.
- Use case modellemesi artımlıdır
  - Bütün aktör ve senaryolar ilk seferde görülmez; müşteriyle her görüşmede model güncellenir.
- Ders projeleri için
  - Bu ders kapsamındaki projelerde tek bir use case diyagramı yeterlidir.

## Kısa Tekrar Notları

- Gereksinim analizi: problemi, çözüm yaklaşımını ve sistemin nasıl çalışacağını belirleme; çıktı SRS'tir.
- SRS = Software/System Requirements Specification; standart örneği IEEE 830.
- Gereksinimler biliniyorsa akış diyagramları, bilinmiyorsa prototip.
- BRD (Business Requirements Document) iş analizinin çıktısıdır, SRS'ten önce ara çıktı olabilir.
- Use case diyagramı: aktör (çöp adam), senaryo (elips), ilişki (çizgi), sistem sınırı (dikdörtgen).
- Aktör insan, dış sistem ya da cihaz olabilir.
- Birincil aktör senaryoyu başlatan ya da asıl faydayı alan; destek aktörü bilgi/destek sağlayan.
- Senaryo şablonu: kod ve ad, birincil aktör, ilgililer, ön koşul, son koşul, ana başarılı senaryo, alternatif akışlar, sıra dışı durumlar, özel istekler, teknolojik beklentiler.
- En sık bulunanlar: aktör, ön/son koşul, ana başarılı senaryo; çoğunlukla alternatif akış.
- İlişkiler: include (ortak alt senaryo), extend (koşullu ek davranış), özelleştirme/genelleştirme.
- Sözleşme (contract): karmaşık işlemlerin son koşullarını nesne düzeyinde açar.
- Bilgi toplama: gözleme, kişisel görüşme (yapılandırılmış/yapılandırılmamış), anket (açık/kapalı uçlu).
- Kapalı uçlu: hızlı, kolay analiz; açık uçlu: yavaş, geniş ve derin bilgi. İkisi dengeli kullanılmalı.

## Detaylı Açıklamalar

- **Gereksinim analizinin yeri.** Fizibilite ile projenin yapılabilir olduğu gösterildikten sonra analiz başlar. Bu aşamada ortada bir sistem yoktur; amaç işi (business) anlamak ve onu teknik tarafın anlayacağı bir dile çevirmektir. Analizin sonunda sistemin sahip olması gereken işlevler ve işlev dışı özellikler (işlevsel olmayan gereksinimler) SRS belgesinde toplanır; örneğin "saniyede 10 bin kullanıcıya hizmet verebilmelidir" gibi kalite unsurları da burada yazılır. Analiz sonucunda yeni modüller ortaya çıkabileceği için Gantt diyagramıyla ifade edilen sistem geliştirme planı da gözden geçirilir; bu yüzden plan ve analiz paralel yürür.

- **Analiz akışı.** Project charter ve fizibilite matrisi gibi çıktılardan oluşan yazılım planı idari incelemeden geçer. Ardından gereksinimlerin bilinip bilinmediğine göre ya doğrudan yazılır ya da prototip/model oluşturulur. İşin ne olduğunun anlaşıldığı aşamada bir BRD hazırlanabilir; daha sonra teknik ayrıntıların yer aldığı SRS yazılır. SRS önce teknik, sonra yönetim incelemesinden geçer; onaylanırsa tasarıma başlanır, onaylanmazsa revize edilir.

- **Use case modellemesi.** Use case diyagramı, bilgisayardan anlamayan birinin bile bakıp "evet bu sorumluluklar var" ya da "biz bu işi böyle yapmıyoruz" diyebileceği basit bir modeldir. Diyagram tek başına yetmez; her senaryonun içi ayrıca yazılır. Örneğin bir sisteme üyelik bile kendi içinde alt senaryolardan oluşur: kullanıcının daha önce kayıtlı olup olmadığının kontrolü, kurumsal ya da bireysel müşteriye göre değişen bilgilerin alınması, şifre unutulduğunda e-posta ya da SMS ile yapılacaklar.

- **Okul servisi örneği.** Araçlardaki GPS modülleri belirli aralıklarla (örneğin her dakika) zaman damgası, plaka ve koordinat bilgisini sisteme gönderir. Bu bir sorumluluktur ve "Report location" senaryosu olarak modellenir; aktörü GPS sistemidir. Araçların okula ne zaman varacağını konum ve mesafeden tahmin etmek "Find arrival times", GPS cihazlarının arızalarını bildirmek "Report error" senaryosudur. Slayttaki diyagramda bu iki senaryo adı yazılmamış ikinci bir aktörle ilişkilidir (ekrandan, 00:45:00). Gerçek sistemlerde senaryo sayısı çok daha fazladır; büyük sistemlerde diyagram alt sistemlere bölünebilir.

- **Senaryo yazımı.** "Find arrival times" senaryosu yazılırken önce önsöz gelir: kod ve ad (UC1, KS1 ya da S1 gibi), birincil aktör (GPS sistemi, depo çalışanı, lisans öğrencisi, laborant gibi), destek aktörleri/ilgililer ve beklentileri, ön koşullar (örneğin 30 kredilik ders alabilmek için not ortalamasının 3.0'ın üzerinde olması) ve son koşullar. Sonra ana başarılı senaryo dallanmasız yazılır: "Öğrenci seçmek istediği dersin kodunu girer, grubunu seçer. Sistem öğrenciyi derse kaydeder." Kontenjan dolu olması ya da AGNO/ön koşul nedeniyle dersin alınamaması gibi sapmalar alternatif akışlarda (4a, 4b) verilir. Sıra dışı durumlar, özel istekler ve teknolojik beklentiler isteğe bağlıdır. Bu senaryolar daha sonra SRS içindeki gereksinim tanımları olarak birebir kullanılabilir.

- **İlişkiler.** Include, pek çok senaryoda tekrarlanan bir iş grubunu (örneğin sıra numarası alma, kan verme, bakiye güncelleme) tek senaryoda tanımlayıp gereken yerlerde çağırmayı sağlar; fonksiyon çağrısına benzer. Extend, ana senaryoya koşullu ek davranış katar: banka örneğinde para yatırma tek başına çalışır, ama tutar 10.000'in ya da yaş 55'in üzerindeyse bonus hesabı devreye girer (ekrandan, 01:20:00). Genelleştirme daha çok aktörler arasında kurulur: döviz işlemleri yapabilen NRFC Customer, Customer'ın bütün özelliklerine sahip olup ek olarak Convert Currency yapabilir.

- **Artımlı modelleme.** Hoca banka diyagramı üzerinde müşteriyle yapılan bir toplantıyı canlandırdı: müşteri para yatırma ve çekmede mutlaka bir veznedarın (Clerk) olması gerektiğini söyleyince diyagrama Clerk aktörü eklendi ve bu iki senaryoya bağlandı; gün sonunda para sayımı yapılması gerektiği söylenince "End of day calculations" senaryosu eklendi ve Clerk'e bağlandı. Son olarak senaryolar bir sistem dikdörtgeni içine alındı. Her görüşmede model böyle güncellenir ve senaryo metinleri de müşteriyle birlikte yazılır.

- **Sözleşmeler.** Bazı senaryo adımları tek adımda yapılamayacak kadar karmaşıktır. Bölüm kapama senaryosunda derslikler fakülteye, bilgisayarlar ayniyata devredilir ve personel işten çıkarılır; işten çıkarma kendi içinde bir iştir. Bunun için yazılan sözleşmede işlem, kimin için yapıldığı, hangi senaryoda ve hangi koşulda çalıştığı ve son koşullar yer alır. Son koşullar ("tüm bölüm çalışanlarının tazminatı hesaplanmıştır", "çalışanın iş yerine bağlantısı kesilmiştir") nesne düzeyinde ne olacağını söyler (çalışan nesnesinin yok edilmesi gibi) ama hesabın nasıl yapılacağını söylemez.

- **Bilgi toplama.** Gözleme yaklaşımında analist iş ortamına gider, hiçbir şeye karışmadan işin nasıl yapıldığını, hangi formların ve belgelerin kullanıldığını izler ve örnekler. Kişisel görüşmede randevu alınır, konuya hazırlıklı gidilir, gündem belirlenir, not ya da kayıt tutulur, hitap ve duruşa dikkat edilir; görüşme sonunda nelerin konuşulduğu, nelerin kaldığı ve sonraki görüşmelerin planı belirlenir. Kararlaştırmak ya da belirli bir işin nasıl yapıldığını öğrenmek için yapılandırılmış görüşme, müşterinin muğlak olduğu ya da iş alanının bilinmediği durumlarda yapılandırılmamış görüşme tercih edilir. Anket ise geniş kitleler için uygundur; soruların açık, şartlandırmayan ve kolay cevaplanabilir olması gerekir.

- **BRD örneği.** Gösterilen BRD şablonunda işlevsel gereksinimler bir tabloda kimlik numarası, gereksinim cümlesi ve Must/Want önceliğiyle listelenir; bu tablo aslında senaryoların niyet beyanıdır, senaryoların içi SRS'te yazılır. İşlevsel olmayan gereksinimler tablosunda kurulum maliyetinin 1.000 doların, yıllık barındırma/bakım maliyetinin 300 doların altında olması, sitenin saldırılara karşı güvenli olması, her gece yedek alınması (Must) ve tedarikçi bulunduktan sonra 60 gün içinde yayına hazır olması (Want) yer alır (ekrandan, 01:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
