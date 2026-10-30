# Ders 11 Çalışma Özeti

## Genel Konular

- Bu ders (27 Mayıs 2021) dönem projesi sunumlarının ikinci haftasıdır. Konu anlatımı yoktur.
- Öğrenciler TÜBİTAK 1002 Hızlı Destek Programı formatındaki araştırma projesi önerilerini sunar. Bazı sunumlar İngilizcedir.
- Bu derste 8 sunum yapılır:
  - 1. sunum: Geliştirilmiş genetik algoritma ile turizm rota uygulaması.
  - 2. sunum: Raylı sistemlerde yolculara istasyon ve vagon öneri sistemi.
  - 3. sunum: Blok zincir tabanlı eşler arası (P2P) enerji ticareti ve sanal güç santrali.
  - 4. sunum: Uzaktan ve örgün eğitim için eğitim yönetim sistemi.
  - 5. sunum: Mean-shift izleyici ve Harris köşe dedektörü ile video boyama (video inpainting).
  - 6. sunum: E-öğrenme verisinin bulut depolamada güvenli paylaşımı için bir denetim mekanizması.
  - 7. sunum: Akciğer BT görüntülerinden COVID-19 enfeksiyon oranının tespiti.
  - 8. sunum: Yaşlı bakım evlerinde düşmelerin tespiti ve acil müdahale sistemi.
- Ders sonunda hoca ilk haftadaki uyarılarına rağmen tekrarlanan hataları sert bir dille eleştirir.

## Hocanın Özellikle Vurguladığı Kısımlar

- **İlk haftadan ders alınmadı:** Hoca geçen haftanın sonunda yaptığı yorumlardan pek ders alınmadığını söyler.
- **Slayttan okumak:** Slayta olabildiğince metin koyup onu okumanın "hiçbir esprisi yok".
  - Sunumlar bir hafta önce teslim edildi. Öğrencilerin sunum üzerine çalışmak için fazladan bir haftası vardı.
  - Hâlâ kâğıttan veya slayttan okumak, işe yeterli özen gösterilmediğini gösterir. Bu avantaj dezavantaja dönmüştür.
- **Seviye beklentisi:** Dinleyenler yüksek lisans ve doktora öğrencileridir. Kendini ifade etme ve iletişim becerisi lisans seviyesinin çok üstünde olmalıdır.
  - Hoca hem Türkçe hem İngilizce sunumlarda konuşma akıcılığında ciddi sıkıntı görür.
- **Süre:** Slaytlar 20-30 tane olsa bile bazıları atlanarak süre makul kullanılabilirdi.
  - Herkese 10 dakika verilmişken 17 dakika sunum yapmak "belli açılardan ciddi saygısızlık" olarak görülür.
- **Dinleyici saygısı:** Başkasının sunumu sırasında mikrofonu açık bırakıp gürültü yapmak hoş değildir. Hoca bunun tekrarlanmamasını ister.
- **Kamera:** İş yerinden bağlandığı için kamerasını açamayan öğrencilere hoca "Ona göre değerlendireceğiz" der.
- **Soru:** Hoca soru gelmeyen sunumlarda "Sanırım soru yok, her zaman olduğu gibi" diyerek dinleyicilerin pasifliğini eleştirir.
- **Sunumda ek materyal:** Ders sonunda bir öğrenci, sunumda başka bir belge veya site gösterip gösteremeyeceğini sorar.
  - Teslim edilen sunum değiştirilemez; başka bir sunum yapılamaz.
  - Sunum içinde referans olarak ek bir şey gösterilebilir. Ama bu süreden yer ve önceden planlanmalıdır.
  - Kullanılacak cihaz ve ekipman önceden bilinmelidir. Video açılmaması, ekranın paylaşılamaması gibi tüm sorunlar sunanı bağlar. Önceden mutlaka test edilmelidir.
- **Ekran paylaşımı:** Bir grup ekranını paylaşamadığı için sunumu ders sonuna ertelenir. Hoca paylaşımın açık olduğunu, sunumu F5 ile başlatıp ilgili ekranı seçmenin yeterli olduğunu söyler.

## Kısa Tekrar Notları

- İyi bir proje sunumu için kontrol listesi:
  - Sunum provası yapılmış olmalı. Slayt okunmamalı.
  - Süre 10 dakikayı geçmemeli. Slayt sayısı süreye göre ayarlanmalı.
  - Kamera açık olmalı.
  - Kullanılacak cihaz ve ek materyaller önceden test edilmeli.
  - Dinleyiciler mikrofonu kapalı tutmalı ve soru sormalı.
- Bu haftanın sunumlarında öne çıkan teknikler:
  - Optimizasyon: genetik algoritma (seçim, çaprazlama, mutasyon) ve gezgin satıcı problemi.
  - Görüntü işleme: YOLO ile insan tespiti, mean-shift ile nesne takibi, Harris köşe tespiti, Sobel kenar tespiti, maskeleme.
  - Dağıtık sistemler: Ethereum akıllı sözleşmeleri, Solidity, MetaMask.
  - Güvenlik: AES şifreleme, denetçi (auditor) rolü.
  - Makine öğrenmesi: rastgele orman, k-en yakın komşu, destek vektör makineleri.

## Detaylı Açıklamalar

### 1. Sunum: Geliştirilmiş Genetik Algoritma ile Turizm Rota Uygulaması

- **Amaç:** Gezgin satıcı problemini (traveling salesman problem, TSP) günlük hayata uyarlamak. Bir turistin şehir içinde veya şehirler arasında gezeceği yerler için en uygun rotayı bulmak.
- **TSP tanımı:** Bir noktadan başlayıp her noktaya yalnız bir kez uğrayarak başlangıca dönen en kısa turu bulmak.
- **Literatür örnekleri:** Adana'da fabrika dağıtım rotası (2010), İstanbul'da toplu taşıma denetim ekibinin güzergâhı (2018), Endülüs'te ve Çin'de turist rota planlama çalışmaları (2012, 2018, 2020).
- **Yöntem:** Genetik algoritma (seçim, çaprazlama, mutasyon). Problem büyüdükçe performansı yetersiz kalır.
  - Öneri: klasik süreçlere, canlıların çevreye uyumundan esinlenen yeni bir "adaptasyon süreci" ve farklı adaptasyon operatörleri eklemek.
- **Uygulama:** Android ve iOS mobil uygulaması. Trafik bilgisini de kullanarak en kısa ve verimli rotayı önerir.
- **Etkiler:** zaman tasarrufu, daha az yakıt ve karbondioksit, turizm acenteleri için kullanım, yazılım istihdamı.
- **Proje katkı oranları:** algoritma %25, gezilecek yerlerin keşfi %10, uygulamanın son kullanıcıya ulaştırılması %65.
- Soru gelmez.

### 2. Sunum: Raylı Sistemlerde İstasyon ve Vagon Öneri Sistemi

- Grubun bir üyesi sağlık sorunu nedeniyle katılamaz; sunum tek kişiyle yapılır.
- **Problem:** COVID-19 ile raylı sistemlerde yolcu sayısı ve güven düştü. Wuhan'daki bir çalışmaya göre bulaşma mesafe arttıkça azalır, birlikte geçirilen süre arttıkça artar.
- **Araştırma soruları:**
  - Vagon öneri sistemi yolcuları daha güvende hissettirir ve bulaşma riskini azaltır mı?
  - Mobil uygulama ile anlık yoğunluk görülüp ulaşım tercihi buna göre yapılabilir mi?
- **Hipotez:** Yoğunluk önceden belirlenirse yolcular yolculuğunu planlar ve boş vagona yönlendirilir; sosyal mesafe artar.
- **Yöntem:**
  - Görüntü ön işleme, insan tespiti ve insan sayma.
  - YOLO ile nesne tespiti (görüntü ağdan tek seferde geçtiği için hızlı). Model COCO veri setiyle eğitilir.
  - Python, OpenCV ve NumPy. Her vagonun iki kapısına giriş-çıkış sayımı için kamera.
  - Yoğunluk vagon hacmine göre hesaplanır, eşiklere göre renklendirilir. Bilgi ekranlarına ve uygulamaya MQTT protokolüyle gönderilir.
  - Mobil uygulama Flutter ile geliştirilir (tek kod tabanından iOS ve Android).
  - Değerlendirme: kullanıcı anketi, uzman desteğiyle yarı yapılandırılmış gözlem formu ve paydaş görüşmeleri.
- **Riskler:** derin öğrenme modelinin yavaş veya yetersiz kalması, sunucu depolama yetersizliği, takvim kayması, ekipman arızası, kullanıcının uygulamaya erişim sorunu.
- **Soru-cevap:** Bir öğrenci, belli kapasitenin üstünde kapıların açılmamasını önerir. Sunan kişi bunun ters tepebileceğini söyler. Hoca ekler: "Açmazsak inecek olanlar inemez."

### 3. Sunum: Blok Zincir Tabanlı P2P Enerji Ticareti

- Sunumun İngilizce kısımlarının büyük bölümü altyazıda anlaşılmıyor. Aşağıdaki bilgiler slayt karesinden ve Türkçe kısımdan alınmıştır.
- **Fikir (slayt):** Sanal güç santrali (virtual power plant, VPP) içindeki blok zincir akıllı sözleşmeleri verimli, şeffaf ve ekonomik bir eşler arası enerji ticareti sağlar.
  - Şekilde enerji üreten ve tüketen ajanlar, bir P2P ticaret koordinatörü, teknik VPP, piyasa operatörü, enerji depolama sistemi ve dizel jeneratör vardır.
- **Araçlar:** Ethereum, Ethereum Sanal Makinesi (EVM), MetaMask, Solidity.
- **Proje yönetimi:** analiz, tasarım, üretim ve test aşamaları.
- **Riskler:** santral arızaları, merkeziyetsiz yapıya güvenilmemesi, Solidity'de yazılım hataları, hastalık, ekonomik kriz, savaş gibi dış etkenler.
- **Etki iddiaları:** aracı olmadığı için taşıma bedeli gibi ek giderler olmaz; temiz enerji yaygınlaşır; sistem ihraç edilebilir.

### 4. Sunum: Eğitim Yönetim Sistemi

- **Problem:** Milli Eğitim Bakanlığı'nın 2020 uzaktan eğitim raporuna göre derse katılım düşüktür. Aktif öğrenme üzerine 203 makaleyi inceleyen bir çalışma, olumlu etkiyi %95 oranında bulmuştur.
- **Amaç:** Öğrenci merkezli, derse aktif katılımı artıran, veli ve okul idaresini de kapsayan yerli bir mobil uygulama. Yurt dışı kaynaklı uygulamalara bağımlılığı ve veri dışa çıkışını azaltmak.
- **Özellikler:** anlık quiz, tartışma ortamı, zihin haritaları, akıllı tahta yönetimi, mesajlaşma, e-öğrenme içerikleri, anket, ders dışı etkinlik planlama, duyurular, ders programı yönetimi.
- **Ekip (6 kişi):** proje yürütücüsü (MEB'de idareci ve öğretmen, doktora öğrencisi), kıdemli yazılım tasarım mühendisi, iki tasarım-geliştirme mühendisi, geliştirme-test mühendisi ve test mühendisi.
  - Gerekçe: Yazılım tasarımındaki hatalar geri dönüşü en maliyetli hatalardır.
- **İş paketleri (9 paket):**
  - Muadil yurt dışı ürünlerin (ör. EduPage) incelenmesi ve sistem gereksinimleri belgesi.
  - Sistem mimarisi ve yazılım tasarımı (UML, mikroservis).
  - Tasarım ve test belgeleri.
  - Bulut servisi, backend ve API (45 gün). Arayüz geliştirme bu paketin 15. gününde başlar.
  - Backend ve arayüz entegrasyonu (40 gün).
  - Tasarım doğrulama testleri, sistem entegrasyon testleri, son kullanıcı belgeleri.
  - İlk üç paket seri ilerler, paralellik yoktur.
- **Riskler ve B planları:**
  - Nitelikli eleman bulunamaması: iş ilanları, sosyal medya, üniversite bölümleri.
  - Eleman kaybı: hızlı oryantasyon ve tecrübeli personelle birebir çalışma.
  - Testlerde performans eksikliği: tecrübeli yazılım mimarı danışman.
  - Satış-pazarlamaya zaman ve bütçe ayrılamaması.
  - Yabancı ürünlere daha çok güvenilmesi: büyük firmalarla referans ve iş birliği.
- **Bütçe:** iki bilgisayar, bir Android ve bir iOS cihaz. Toplam 24.091 TL.

### 5. Sunum: Video Boyama (Video Inpainting)

- Sunum İngilizcedir ve altyazının büyük bölümü anlaşılmıyor. Aşağıdakiler anlaşılabilen kısımlardan ve slayt karesinden alınmıştır.
- **Konu:** Videodaki bir nesneyi kaldırıp yerini arka planla doldurmak. Mean-shift izleyici ve Harris köşe dedektörü kullanılır, örtmede (occlusion) tutarlılık hedeflenir.
- **Önerilen akış:** videonun karelere ayrılması, ön plan nesne tespiti, nesne takibi, örtme analizi, köşe noktası tespiti, nesnenin boyanması, çıktı videonun birleştirilmesi.
- **Arka plan tahmini (slayt):** Birikimli histogram (accumulation histogram) kullanılır.
  - Kareler bloklara bölünür. Tüm karelerde en sık görülen blok arka plan sayılır, çünkü nesne hareket ettiği için arka plan daha sık görünür.
  - Ölçüt olarak ortalama ve varyans kullanılır. Önerilen yöntem 3x3 blokla çalışır; mevcut yöntemler 2x2 blok kullanır.
- **Takip:** Mean-shift izleyici nesne için bir hedef model kurar. Sonraki karede daha büyük bir pencerede aday modeli arar.
- **İş paketleri:** anlaşılabilen kısımlarda %10, %20 ve %35 ağırlıklı paketler geçer (ekonomik ve teknik analiz, beklenti ve strateji belgeleri, nesne tespiti ve arka plan çıkarma).

### 6. Sunum: E-Öğrenme Verisinin Bulutta Güvenli Paylaşımı

- Sunum İngilizcedir. Bazı kısımlar altyazıda anlaşılmıyor.
- **Problem:** Bulut depolama güçlü ve talebe göre ölçeklenen bir hizmettir. Ama donanım, yazılım ve insan hatası ile siber saldırılar yüzünden verinin bütünlüğü garanti edilemez.
- **Hipotez:** Bir denetçi (auditor) ile çalışan güvenli bir yöntem, e-öğrenme sistemi ile bulut arasındaki veri aktarımını güvenli hale getirebilir.
- **Sistem yapısı (slayt):**
  - Yönetici (admin): kullanıcıları, veri sahiplerini ve denetçileri oluşturur.
  - Veri sahibi: dosyaları şifreleyip buluta yükler. Anahtar ve dosya kullanıcılara e-posta (SMTP) ile gönderilir.
  - Kullanıcı: dosyaları buluttan indirir.
  - Denetçi: yüklenen ve indirilen dosyaların bozulup bozulmadığını kontrol eder.
- **Denetçinin çalışması:** Veri tipi, dosya adı ve beklenen alım zamanı gibi bilgilere bakar. Tutarsızlık görürse işlemi yetkisiz sayar, aktarımı iptal eder, veri sahibine haber verir ve sistemin işlemi tekrarlamasını ister.
- **Gereksinimler:** e-öğrenme ortamı modeli, mahremiyet ve koruma mekanizması (gizli anahtar paylaşımı, kimlik doğrulama, AES ile şifreleme ve çözme), bulut depolama.
- **Bütçe:** Ayda yaklaşık 50 TB bulut alanı ve ek hizmetler için yaklaşık 24.000 TL.

### 7. Sunum: Akciğer BT ile COVID-19 Enfeksiyon Tespiti

- **Amaç:** Bilgisayarlı tomografi (BT) görüntülerinde enfekte bölgeleri görüntü işleme ile bulmak. Enfeksiyon oranını, enfekte piksellerin tüm akciğer piksellerine oranı olarak hesaplamak.
- **Test yöntemleri:** nükleik asit tabanlı testler (PCR), serum tabanlı testler ve diğerleri (röntgen, BT). En yaygını PCR'dır. BT başka hastalıklarda da kullanıldığı için erişimi kolaydır.
- **Yöntem (MATLAB):**
  - BT'de akciğerler koyu görünür, çevresi gri, beyaz ve siyah tonlardadır.
  - Piksel yoğunluk dağılımı incelenir, eşikleme yapılır.
  - Sobel filtresiyle kenar tespiti yapılır ve ikili (binary) görüntü elde edilir.
  - Ardışık maskelerle akciğer bölütlenir ve gürültü temizlenir. Sağlıklı akciğerde son maske yalnızca gürültü üretir.
  - Son görüntü ikiliye çevrilir ve siyah olmayan pikseller sayılır.
- **Prototip:** İki örnekte enfeksiyon oranı %36 ve %15 çıkar.
- **Sınırlılık ve risk:** Gürültülü görüntülerde gri tonlar arasındaki fark az olduğundan akciğer bölütleme başarısız olabilir. Bu yüzden sistem kesin bir uzman sistem değil, doktora yardımcı bir asistan olarak önerilir. Son karar doktorundur.

### 8. Sunum: Yaşlı Bakım Evlerinde Düşme Tespiti ve Acil Müdahale

- Ekran paylaşım sorunu nedeniyle bu sunum ders sonuna ertelenir.
- **Kavram:** Dünya Sağlık Örgütü yaralanmaları kasıtlı ve kasıtsız olarak ayırır. Düşme, trafik kazası ve boğulma kasıtsız yaralanmadır. Literatürde "düşme" yerine bu terim kullanıldığı için proje başlığında da kullanılır.
- **Problem:**
  - Ölümcül olmayan yaralanmalarda düşmeler %46 ile ilk sıradadır.
  - Dünyada yılda yaklaşık 684 bin ölümcül düşme olur. Kasıtsız yaralanma ölümlerinde trafik kazalarından sonra ikinci sıradadır.
  - Yaşla birlikte düşmeye bağlı yaralanmaların ciddiyeti artar. Devlete bağlı 153 huzurevi vardır.
- **Amaç:** Düşmeyi önlemek değil, düşmeden sonra acil müdahaleyi hızlandırmak. Huzurevlerinde hastalar belli saatlerde ziyaret edilir; düşen bir hasta uzun süre fark edilmeyebilir.
- **Yöntem:**
  - Anlaşılan huzurevlerinde her odaya kamera konur; izin dahilinde 8 ay boyunca veri toplanır.
  - Tüm kayıt değil, yalnız olay anının öncesi ve sonrası kesilerek veri seti oluşturulur.
  - Gürültü temizleme, yakınlaştırma ve aynalama gibi ön işleme ve veri çoğaltma yapılır.
  - Rastgele orman, k-en yakın komşu ve destek vektör makineleri denenir; en başarılısı seçilir.
  - Örnek anomali: sürekli tekerlekli sandalyede oturan hastanın aniden yere düşmesi. Sistem bunu personele bildirir.
- **Takvim (12 ay):** veri toplama (1-8. ay), etiketleme ve model geliştirme, huzurevinde yaklaşık 2 aylık gerçek ortam testi.
- **Riskler:** Yeterli düşme verisi toplanamazsa sentetik veri üretilir. Personel kaybında süreyi aksatmayacak yeni kişi alınır.
- **Etkiler:** hayat kurtarma, sakatlık ve ölümlerin sağlık sistemine yükünün azalması. İleride anaokulları ve açık alanlarda kullanım, yurt dışı satış.
- **Soru-cevap:** Bir öğrenci açık kaynak düşme veri seti olup olmadığını ve önceden eğitilmiş modellerin kullanılıp kullanılamayacağını sorar.
  - Grup, huzurevi düşmelerine özel açık bir veri seti bulamadığını söyler.
  - Başka bir öğrenci, metro istasyonlarında düşme ve raylara atlama gibi anomaliler için veri setleri ve sistemler olduğunu ekler.

### Ders sonrası notlar

- **Genetik algoritma (1. sunum):** Genetik algoritma evrim teorisinden esinlenir (altyazıda "evren teorisi"). Sezgisel (metaheuristic) bir yöntemdir; en kısa turu bulmayı garanti etmez, iyi bir yaklaşık çözüm verir.
- **Blok zincir güvenliği (3. sunum):** "SHA-256 ile şifreleme yapılır, kırılması imkânsızdır" ifadesi hatalıdır.
  - SHA-256 bir özet (hash) fonksiyonudur, şifreleme değildir.
  - Zincirin güvenliği, geçmiş blokları değiştirmenin pratikte çok maliyetli olmasına dayanır; "imkânsız" değildir.
  - Ethereum'da kullanılan özet fonksiyonu Keccak-256'dır; SHA-256 Bitcoin'de kullanılır.
  - Açık bir blok zincirde işlem verileri herkese görünür. Yani blok zincir tek başına gizlilik sağlamaz.
- **EduPage (4. sunum):** EduPage İspanya değil, Slovakya merkezli bir yazılımdır.
- **Akademik etki (4. sunum):** Sunumda "akademik etki yok" denir. TÜBİTAK 1002 bir araştırma programıdır; akademik etki bölümü boş bırakılmamalıdır.
- **Bulut güvenliği (6. sunum):**
  - "Bulutta bakım gerekmez ve güvenlik yüksektir" iddiası abartılıdır. Bulutta paylaşılan sorumluluk modeli (shared responsibility model) geçerlidir; erişim yönetimi ve şifreleme kullanıcının sorumluluğundadır.
  - Dosya adı, tipi ve zamanı gibi üst bilgilere bakmak veri bütünlüğünü kanıtlamaz. Bütünlük için özet değeri, mesaj doğrulama kodu (MAC) veya dijital imza kullanılır.
  - Literatürde bu konu "üçüncü taraf genel denetim" (third-party public auditing) ve kanıtlanabilir veri sahipliği (provable data possession) başlıkları altında çalışılır.
- **PCR testi (7. sunum):** Altyazıdaki açıklama karışıktır. Doğrusu:
  - RT-PCR'da virüsün RNA'sı ters transkripsiyonla (reverse transcription) cDNA'ya çevrilir.
  - DNA polimeraz döngüler boyunca hedef bölgeyi çoğaltır. Prob bağlandıkça floresan sinyal artar.
  - Sinyal belirli sayıda döngü içinde eşik değeri (Ct) aşarsa test pozitif sayılır.
- **BT tanısı (7. sunum):** Enfeksiyon oranı tek başına tanı koymaz. COVID-19 dışındaki zatürreler de benzer buzlu cam görünümü (ground-glass opacity) verebilir. Grubun "yalnız doktora yardımcı" vurgusu bu yüzden doğrudur.
- **Düşme veri setleri (8. sunum):** Kamera tabanlı açık düşme veri setleri vardır. Örnekler: UR Fall Detection, Le2i Fall Detection, UP-Fall Detection, Multiple Cameras Fall Dataset. Bunlar önceden eğitim ve karşılaştırma için kullanılabilir.
- **Sayısal tutarsızlıklar (8. sunum):**
  - "Olay 50 saniye sürüyorsa 10 dakika öncesi ve 10 dakika sonrası, yani 70 saniyelik video" ifadesi tutarsızdır. 70 saniye için olayın 10 saniye öncesi ve sonrası alınmalıdır.
  - TÜİK'e göre 2020'de 65 yaş ve üstü nüfusun oranı yaklaşık %9,5'tir; sunumdaki %8,5 daha eski bir yılın verisidir.
- **Araştırma etiği (8. sunum):** Odalara 7/24 kamera konması güçlü bir mahremiyet müdahalesidir. Bilgilendirilmiş onam (yaşlı ve vasisi), etik kurul onayı ve KVKK uyumu proje planında ayrı bir iş paketi veya risk olarak yer almalıdır.
- **Altyazıdaki bozuk terimlerin doğruları:**
  - "gezge kazıcı problemi" → gezgin satıcı problemi.
  - "yolu algoritması" → YOLO.
  - "Coco" → COCO veri seti.
  - "Swoble filter" → Sobel filtresi.
  - "main shift tracker" → mean-shift tracker.
  - "mythology" → methodology.
  - "ŞA256" → SHA-256.
  - "Emek" → EVM (Ethereum Virtual Machine).
  - "kahop" → Kahoot.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
