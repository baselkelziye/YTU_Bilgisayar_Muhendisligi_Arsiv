# Ders 4 Çalışma Özeti

## Genel Konular

- Yazılım gereksinim belirtimi (SRS) ve IEEE 830 şablonu
  - Gereksinim analizi sonunda hazırlanan ayrıntılı belgenin hangi içerikte olması gerektiği IEEE 830 şablonu üzerinden gösterildi. Bu aynı zamanda bir standart örneğidir (ekrandan, 00:10:00).
  - Şablonun ana bölümleri: Giriş (amaç, belge kuralları, hedef okuyucu, ürün kapsamı, kaynaklar), Genel Tanım (ürün bakış açısı, ürün işlevleri, kullanıcı sınıfları, işletim ortamı, tasarım ve gerçekleştirme kısıtları, kullanıcı belgeleri, kabuller ve bağımlılıklar), Dış Arabirim Gereksinimleri (kullanıcı, donanım, yazılım, iletişim), Sistem Özellikleri, Diğer İşlevsel Olmayan Gereksinimler (performans, emniyet, güvenlik, kalite öznitelikleri, iş kuralları), Diğer Gereksinimler ve ekler (sözlük, analiz modelleri, belirlenecekler listesi). Başta bir sürüm geçmişi (revision history) tablosu bulunur.
  - İşlevsel gereksinimler sistem özelliklerine (modüllere) bölünüp numaralanarak (REQ-1, REQ-2, ...) ya da her modül için bir use case belgesiyle verilebilir.
- Örnek SRS belgesi (üniversite mezunlar sayfası)
  - Her alt modül (yeni kayıt, kayıt güncelleme, mezun arama ve e-posta gönderme) için ayrı bir use case tablosu hazırlanmıştır (ekrandan, 00:20:00 ve 00:25:00).
  - İşlevsel olmayan gereksinimler (kullanıcı arabirimi, performans, erişilebilirlik ve güvenilirlik, güvenlik) madde yerine kısa açıklayıcı cümlelerle yazılmıştır.
  - Gereksinim belgesi, kullanıcı kabul testinde yazılımın neyle karşılaştırılacağını belirleyen temel belgedir.
- Önceki konuların tekrarı: kalite aktiviteleri, gözden geçirme ve inceleme
  - McCall kalite modeli, kalite faktörleri ve metrikler; kaliteli yazılım için standart kullanma, formal süreç modeli seçme, gözden geçirme ve inceleme.
  - Gözden geçirme standartları: SDR, SSR, PDR, TRR (ekrandan, 00:35:00).
  - İnceleme (inspection) kodu çalıştırmadan hata bulan statik doğrulamadır; test ise çalıştırarak yapılan dinamik doğrulamadır (ekrandan, 00:30:00).
  - Fagan inceleme süreci: planlama, genel bakış, bireysel hazırlık, inceleme toplantısı, yeniden çalışma (düzeltme), izleme ve raporlama.
  - Etkili kod okuma hem yukarıdan aşağıya hem aşağıdan yukarıya incelemeyi birleştirir; inceleme ekibi: inceleme sorumlusu, inceleyiciler, yazar, kod okuyucu, kayıtçı (ekrandan, 00:40:00).
  - Teknik inceleme sonucu: değişiklik yapılmadan kabul, küçük hatalar düzeltilmek koşuluyla kabul ya da ret ve düzeltme sonrası yeniden inceleme.
- V modeli ve doğrulama/geçerleme
  - V modeli geliştirme adımlarıyla test adımlarını eşleştirir; her eşleşmede doğrulama mı geçerleme mi yapıldığını gösterir.
  - Geçerleme (validation): "Doğru ürünü ürettik mi?" Doğrulama (verification): "Ürünü doğru yolla ürettik mi?"
- Test süreci adımları
  - Birim testi: en küçük tasarım birimi olan modül üzerinde, ayrıntılı tasarıma dayanarak, çoğunlukla saydam kutu olarak ve modüller geliştirildikçe paralel yürütülür (ekrandan, 00:45:00). Bağımlı modüller için test sürücüsü (driver) ve koçan (stub) yazılır (ekrandan, 00:50:00).
  - Bütünleme testi: arabirim testi; veri kaybı, modüllerin birbirini ters etkilemesi, hata toleranslarının birikmesi aranır. Big bang yerine artırmalı (yukarıdan aşağıya, aşağıdan yukarıya, sandviç) bütünleme önerilir.
  - Regresyon testi: değişiklik ya da ekleme sonrası daha önce test edilmiş yazılımın yeniden test edilmesi.
  - Sistem testi: yazılımın işletim sistemi, veri tabanı ve donanımla uyumu; güvenlik, dayanıklılık (stres) ve yetenek (performans) testleri.
  - Onaylama testi ve kabul muayenesi: alfa testi (kullanıcıya benzer iç grup), beta testi (potansiyel kullanıcılar); onaylama testi ile düzenin (konfigürasyonun) incelenmesi birlikte kabul muayenesini oluşturur (ekrandan, 01:25:00).
- Test tipleri
  - Kara kutu (iç yapıya bakmadan gereksinimlere göre), saydam kutu (white/glass box; deyimler, dallar, akış yolları), gri kutu (ikisinin karması).
  - Saydam kutu teknikleri: temel yollar testi (akış grafı, McCabe döngüsel karmaşıklığı, bağımsız yol sayısı kadar test senaryosu) ve döngü testi.
  - Kara kutu teknikleri: eşdeğerli bölümleme, sınır değer analizi, neden-sonuç grafı, veri onaylama testi; ayrıca keşif testi.
- Hata giderme ve hata düzeyleri
  - Debugging: test sonucu saptanan hata ve eksiklerin nedenini bulup düzeltmek. Bug nedenlerinin en büyük payı gereksinimden, sonra tasarımdan, sonra koddan gelir (ekrandan, 02:05:00).
  - Hata düzeyleri: ölümcül, kritik, büyük, orta, küçük, görünüm (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Validation ile verification ayrımı
  - Validation ürünün kendisini doğrudan test eder (doğru ürün mü); verification geliştirme yolunu inceler (doğru yolla mı). İnceleme statik doğrulamadır.
- Test süreci adımları ile test tipleri ayrı şeylerdir
  - Adımlar: birim, bütünleme, sistem, kullanıcı (kabul) testi. "Validasyon" ya da "verifikasyon" bir test adımı adı değildir; sistem testinde ikisi de vardır.
  - Kara kutu, saydam kutu, gri kutu ise test tipleridir.
- Temel yollar testi "saydam kutu testinin kendisi" değildir, bir saydam kutu testi türüdür; döngü testi de öyledir ve ikisi birlikte uygulanır.
- Denenmemiş her yol bir risktir
  - Rastgele test verisi aynı yola düşebilir; önce bağımsız yollar belirlenip her biri için en az bir test senaryosu hazırlanmalıdır. Test sayısı maliyetle sınırlıdır.
- Kara kutu testi saydam kutunun alternatifi değil, tamamlayıcısıdır.
- Hata düzeylerinin adları ve sayısı sabit değildir; ekip baştan kendi sınıflama standardını belirleyebilir.

## Kısa Tekrar Notları

- IEEE 830: Giriş, Genel Tanım, Dış Arabirimler, Sistem Özellikleri, İşlevsel Olmayan Gereksinimler, Diğer, ekler.
- İşlevsel gereksinimler: numaralı liste ya da use case tabloları.
- İnceleme = statik doğrulama; test = dinamik.
- Fagan: planlama, genel bakış, hazırlık, toplantı, düzeltme, izleme.
- Validation: doğru ürün mü? Verification: ürün doğru yolla mı üretildi?
- Birim testi: modül, saydam kutu, paralel; driver üstteki çağıran modülün, stub alttaki çağrılan modülün yerini tutar.
- Bütünleme: big bang, yukarıdan aşağıya, aşağıdan yukarıya, sandviç; ardından regresyon.
- Sistem testi: güvenlik, dayanıklılık (stres), performans.
- Kabul: alfa (içeride), beta (potansiyel kullanıcı); onaylama testi + düzen incelemesi = kabul muayenesi.
- Temel yollar: akış grafı, McCabe, bağımsız yol sayısı kadar test senaryosu.
- Döngü testi: başlama, indeksleme, artırma, sınırlama hataları; basit, iç içe, birbirine bağlı döngüler.
- Eşdeğerli bölümleme: girdi alanını sınıflara böl, her sınıftan bir değer seç.
- Sınır değer analizi: hatalar kenarlarda toplanır; girdi ve çıktı uç değerleri.
- Bug nedenleri: gereksinim > tasarım > kod.
- Hata düzeyleri: ölümcül, kritik, büyük, orta, küçük, görünüm.

## Detaylı Açıklamalar

- IEEE 830 şablonu ve örnek SRS
  - Şablon bir içindekiler listesi gibi çalışır: belgenin amacı, okunması gereken önceki belgeler, ürünün alanı, kaynaklar ve belgenin kaçıncı sürümü olduğu başta verilir. Genel tanımda ürün işlevleri, kullanıcı sınıfları, çalışma ortamı, yazılım ve donanım açısından tasarım ve gerçekleştirme kısıtları, kullanıcı belgelerinin öğeleri ve kabuller yer alır. Sistem özellikleri bölümünde büyük bir yazılım modüllere bölünür; örneğin bir öğrenci bilgi sisteminde yeni öğrenci kayıtlarının aktarılması, derse kayıt ve transkript gibi belgelerin verilmesi ayrı alt sistemlerdir. Analiz modelleri (ör. use case diyagramları) eklerde verilebilir.
  - Örnek belgede use case tablolarının alanları şunlardır: Use Case Name, Brief Description, Priority, Trigger, Precondition, Basic Path, Alternate Path, Post condition, Exception Path (ekrandan, 00:25:00). İşlevsel olmayan bölümde örneğin "kayıtlı bilgi üzerindeki işlem 10 saniyeden kısa sürmeli", "en az 100 eşzamanlı kullanıcıya veri bozulmadan izin verilmeli", "belirli bir süre (ör. 30 dakika) işlem yapılmazsa oturum kapatılmalı" gibi ifadeler yer alır (ekrandan, 00:20:00).
  - Büyük bir yazılım seçildiğinde gereksinim analizi, test yapılacak modül ya da bölüm için hazırlanmalıdır; bütün sistemin gereksinim belgesi verimli olmaz.
- Fagan incelemesi ve kod okuma
  - Planlama sonrası incelenecekler genel hatlarıyla gözden geçirilir, iş kişilere bölünür, herkes bireysel inceleme yapar, toplantıda her bölüm için görüş bildirilir ve karar verilir; sonra düzeltme için geliştiricilere gönderilir, en son tamamlama ve raporlama yapılır. Kod okumada program fonksiyon, prosedür ve alt program gibi en küçük parçalara bölünür, önce parçaların kendi içindeki bütünlüğü ve doğruluğu, sonra programın bütünüyle uyumu incelenir.
  - Teknik inceleme raporu neyin, kim tarafından gözden geçirildiğini, bulunan hata ve eksikleri ve yapılması gerekenleri açıklar. Küçük projelerde bir kişi birden fazla rol üstlenebilir.
- Birim test ortamı
  - Test programı test sürücüsü üzerinden test edilen birime veri gönderir, sonuçlar sürücü üzerinden alınır; test edilen birimin çağırdığı ama henüz hazır olmayan modüllerin yerine Koçan 1, Koçan 2, ..., Koçan n konur (ekrandan, 00:50:00). Test senaryosu (test case), belirli bir program yolunu işletmek ya da bir gereksinime uygunluğu onaylamak için düzenlenen test verisi ve işlemlerden oluşur; test sayısı arttıkça maliyet arttığı için senaryolar uygun dağıtılmalıdır (ekrandan, 01:05:00).
- Bütünleme ve aşağıdan yukarı örneği
  - Arabirim testinde bir test senaryosu A, B ve C modüllerinden oluşan yapıya veri gönderir; modüller arası veri ve kontrol geçişleri sınanır (ekrandan, 01:10:00). Her modülün kendi hata toleransı kabul edilebilir olsa da birleşince büyük hatalara yol açabilir; bu yüzden toleranslar bütünlemede yeniden gözden geçirilir.
  - Aşağıdan yukarı bütünleme şeklinde Module 1, Module 7'ye (BU1); Module 2, 3, 4, Module 8'e (BU2); Module 5, 6, Module 9'a (BU3) bağlanır; en sonda bunlar Module 10 ile birleşir (BU4) (ekrandan, 01:15:00). Üstteki modüller hazır olana kadar yerlerini test sürücüleri tutar. Büyük resmi kaçırmamak için üst modüle de bakarak ilerlenmesi, yani iki yönün karma uygulanması sandviç testtir.
  <!-- BELİRSİZ: 01:12:18-01:14:14 arasında hoca önce "yukarıdan aşağıya" diye başlayıp aşağıdan yukarı şeklini anlatıyor ve okların yönünü hatalı çizdiğini söylüyor; karede oklar alttaki modülden üsttekine doğru. -->
- Sistem testi ve onaylama
  - Dayanıklılık (stres) testi, sistem miktar, frekans ya da hacim bakımından anormal yüklendiğinde dayanıp dayanmadığını ölçer: örneğin 140 kullanıcılık denen bir sistem 139-140 kullanıcı aynı anda istek gönderdiğinde cevap verebiliyor mu, veri tabanındaki kayıt sayısı arttığında aynı hizmeti verebiliyor mu. Performans testinde belirli yük altında çalışma zamanı ölçülür, ayarlar (tuning) değerlendirilir, performans düşüşünün hangi bileşenden kaynaklandığı ve hangi kullanıcı seviyesinde başladığı bulunur.
  - Onaylama testinde bütünleşmiş yazılım, gereksinimler ve kullanıcı belgeleri girdi olur; düzenin incelenmesinde kullanıcı belgeleri, tasarım belgeleri, kayıtlar ve test belgeleri girdi olur. İkisi kabul muayenesine, oradan yazılımın teslimine gider (ekrandan, 01:25:00). Müşteri uygulamayı finanse eden ve yöneten taraf, son kullanıcı ise kurum içinde uygulamayı doğrudan kullanan kişidir.
- Saydam kutu ve kara kutu teknikleri
  - Temel yollar testinde ayrıntılı tasarım ya da kaynak programdan akış grafı çizilir, McCabe döngüsel karmaşıklığı hesaplanır (bir sonraki dersin konusu), doğrusal bağımsız yolların temel grubu belirlenir, her yol için bir test programı hazırlanır ve sonuçlar beklenenle karşılaştırılır (ekrandan, 01:40:00). Hocanın örneği: ikinci dereceden denklemin kökleri programı deltanın işaretine göre üç farklı yoldan gider; iki yolu deneyip üçüncüyü denemeden teslim etmek o yoldaki hatayı gözden kaçırır.
  - Döngü testi bir giriş ve bir çıkışlı olarak soyutlanan yolları döngü olarak ayrıca sınar; basit döngülerde artışlar ve sonsuz döngü olasılığı, iç içe döngülerde iç ve dış döngünün ilişkisi, birbirine bağlı döngülerde bir döngüden diğerinin içine kontrol akışı olup olmadığı incelenir (ekrandan, 01:45:00).
  - Eşdeğerli bölümlemede girdi alanı veri sınıflarına bölünür ve her sınıftan bir değer seçilir (ekrandan, 01:55:00). Hocanın örneği 0-99 arası yaş girdisi: 20'ye kadar, 21-40, 41-60 ve 60 üstü sınıfları; geçersiz girdiler de ayrıca denenir.
  - Ders sonrası not: Hoca son sınıfı "60 ve daha üstü" dedi; 60 değeri iki sınıfa birden düşmesin diye son sınıf 61-99 olmalıdır. 0-20, 21-40, 41-60, 61-99 sınıfları 0-99 aralığını çakışmasız kaplar (python ile kontrol edildi).
  - Sınır değer analizinde girdi ya da çıktı sınıflarının, veri yapılarının ve alt program parametrelerinin sınır ve uç değerleri seçilir, çünkü hatalar merkezden çok kenarlarda toplanır (ekrandan, 02:00:00).
  - Keşif testinde ürün spesifikasyonu ya da gereksinim belgesi olmadan yazılım genel olarak çalıştırılıp çok hata verip vermediğine bakılır.
- Çevik yöntemler ve gereksinim hataları
  - Eski verilerde bug nedenlerinin en büyük kısmı gereksinim analizindendir. Çevik süreç modelleri yaygınlaştıkça bu pay azalmıştır; nedenleri, gereksinimlerin küçük artımlarla (ör. XP) gerçekleştirilmesi ve müşterinin ekibin bir parçası olarak isteklerini sürekli bildirip kontrol etmesidir.
- Hata düzeyleri ve teslim kararı
  - Ölümcül hata testin devamını engeller. Kritik hatada test sürer ama düzeltilmeden yazılım teslim edilmez. Büyük hata giderilmeden teslim zararlıdır. Orta hata ile test sürebilir; ürün bu hatayla teslim edilirse telafisi mümkün sorunlar çıkarabilir (hoca telafisinin daha zor olabileceğini, çok acil durumda teslim edilip çözümün sonradan aranabileceğini söyler). Küçük hata ile test sürer ve ürün teslim edilebilir. Görünüm hataları renk, font ve büyüklükle ilgilidir (ekrandan, 02:10:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
