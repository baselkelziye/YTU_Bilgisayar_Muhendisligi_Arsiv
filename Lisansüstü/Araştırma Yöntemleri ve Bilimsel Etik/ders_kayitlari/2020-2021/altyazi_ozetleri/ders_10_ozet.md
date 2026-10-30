# Ders 10 Çalışma Özeti

## Genel Konular

- Bu ders (20 Mayıs 2021) dönem projesi sunumlarının ilk haftasıdır. Konu anlatımı yoktur.
- Öğrenciler TÜBİTAK 1002 Hızlı Destek Programı formatında hazırladıkları araştırma projesi önerilerini sunar.
- Bu derste 8 sunum yapılır:
  - 1. sunum: COVID-19 tanısında derin öğrenme yöntemlerinin tarafsızlığı (veri seti kaynaklı yanlılık).
  - 2. sunum: Biyomedikal sensörler için derin öğrenme tabanlı anomali tespiti ve erken uyarı sistemi.
  - 3. sunum: Görme engelliler için giyilebilir, düşük maliyetli asistan ("Rehber Pay").
  - 4. sunum: Federe öğrenmenin (federated learning) mahremiyet gerektiren sağlık verilerine uygulanması.
  - 5. sunum: Blok zincir (blockchain) tabanlı dijital diploma oluşturma, paylaşma ve doğrulama.
  - 6. sunum: Deprem enkazında arama kurtarma robotu.
  - 7. sunum: Mobil robotlar için görüntü tabanlı hassas konum belirleme.
  - 8. sunum: Yeniden kimlik tespiti (person re-identification) için model optimizasyonu.
- Ders sonunda hoca ilk haftanın sunumlarında gördüğü genel hataları sıralar.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Süre:** Her sunumun süresi 10 dakikadır. Süreye sığmak değerlendirmenin bir parçasıdır. Hoca kimseyi sunum ortasında kesmek istemez.
- **Kamera:** Sunum yapanların kamerası açık olmalıdır. Hoca bunu önceden duyurduğunu ve değerlendirmeye girdiğini söyler.
- **Soru-cevap:** Sunum sonunda soru gelmemesi hem sunanlar hem dinleyenler için olumsuz sayılır.
  - Hoca soru-cevap kısmından sunanların konuya hakimiyetini ölçer. Soru sorulmazsa bu değerlendirme yapılamaz.
  - "Kimse kimseye soru sormasın" tavrı herkese puan kaybettirir.
- **Değerlendirme:** Rapor ve sunum ayrı ayrı değerlendirilir. Sunum değerlendirmesi çok kriterli bir Excel tablosu üzerinden yapılır.
- **Ders sonundaki genel geri bildirimler:**
  - Rapordaki blok paragrafları olduğu gibi slayta koymayın.
  - Slayttaki metni okumayın. Sunan kişi slayta bir şey katmalıdır; yoksa slaytın kendi kendine geçmesi aynı işi görür.
  - Slayt sayısını süreye göre önceden planlayın. Konuşma hızınız anlaşılır olmalıdır.
  - 2. sunumda hoca "10 dakikanız olduğunu biliyorsunuz, 20 slayt sizce uygun sayı mı?" diye sorar.
  - Kendinizi ve takım arkadaşınızı tanıtın. Takım arkadaşı söz kendisine geçince kendini yeniden tanıtmalıdır.
  - Sona bir teşekkür ve soru slaytı koyun: "Nasıl hoş geldin diyorsan, giderken de güle güle diyorsun."
- 8. sunumda hoca, anlatılanla ekrandaki slaytın uyuşmadığını düşünüp sunumu kısa süre böler. Sunan kişi slaytı okumadan konuyu aktardığını söyler.
- Sunum listesindeki sarı ve kırmızı işaretler, teslim sürecinde kurallara uymayan grupları gösterir.

## Kısa Tekrar Notları

- Sunumların ortak iskeleti, TÜBİTAK 1002 başvuru formunun bölümleridir:
  - **Özgün değer:** konunun önemi, literatür, araştırma sorusu veya hipotez.
  - **Amaç ve hedefler:** genel amaç ve ölçülebilir başarı kriterleri.
  - **Yöntem:** projede kullanılacak teknikler ve araçlar.
  - **Proje yönetimi:** iş paketleri, iş-zaman çizelgesi, kişi görev dağılımı, risk yönetimi (B planı).
  - **Yaygın etki:** çıktılar (bilimsel/akademik, ekonomik/ticari/sosyal, araştırmacı yetiştirme) ve etkiler (toplumsal/kültürel, akademik, ekonomik, ulusal güvenlik).
  - **Bütçe ve gerekçesi:** makine-teçhizat, sarf malzemesi, bursiyer, hizmet alımı, seyahat.
- Sunumlarda en sık görülen bütçe kalemleri: Raspberry Pi, Arduino, kamera, sensör, 3B yazıcı, GPU'lu sunucu, bursiyer ücreti ve danışmanlık.
- Risk yönetiminde her risk bir iş paketine bağlanır ve her riske bir B planı yazılır.
- Hocanın sunum ölçütleri: süre, kamera, slayt sayısı, slayttan okumama, tanıtım, kapanış ve soru-cevap.

## Detaylı Açıklamalar

### 1. Sunum: COVID-19 Tanısında Derin Öğrenmenin Tarafsızlığı

- **Problem:** Sağlıkta yapay zekâ en çok teşhis sistemlerinde kullanılır. Bu kararlar şeffaf, açıklanabilir ve denetlenebilir olmalı, yanlılık (bias) içermemelidir.
- **Amaç:** Veri setinden kaynaklanan yanlılığı farklı senaryolarla incelemek ve önyargısız bir model için gereken özellikleri bulmak.
- **Yöntem:**
  - Kullanıcı web kazıma (web scraping) ile toplanan veriyi ya da kendi verisini sisteme yükler.
  - Sistem, meta verilerin (cinsiyet, yaş) dağılımını gösterir. Dengesizlik potansiyel yanlılık demektir. Örnek dağılım: 166 erkek, 134 kadın.
  - Örnek senaryo: model yalnızca erkek hastaların görüntüleriyle eğitilir, kadın ve erkek görüntüleriyle ayrı ayrı test edilir.
  - Cinsiyet görüntünün bir özniteliği değil, görüntüye ait meta veridir.
  - Veri az olduğu için önceden eğitilmiş altı derin ağ mimarisi kullanılır (transfer öğrenme).
  - Metrikler: doğruluk (accuracy), eğri altında kalan alan (AUC), kesinlik (precision) ve geri çağırma (recall).
- **İş paketleri:** veri toplama ve veri tabanı; veri analizi modülü; derin öğrenme ve performans metrikleri modülü; kullanıcı arayüzü.
- **Risk:** Analize uygun veri setinin toplanamaması. Çözüm olarak başka kaynaklardan kazıma yapılır.
- **Hocanın yorumu:** Anlatım birçok açıdan iyidir, birkaç küçük sıkıntı vardır.

### 2. Sunum: Biyomedikal Sensörlerle Anomali Tespiti ve Erken Uyarı

- **Problem:** COVID-19 ile hastanelerde personel ihtiyacı arttı. Yoğun bakımdaki hastaların 7/24 takibi zorlaştı. Hatalı ölçümler hasta hayatını tehlikeye atar.
- **Özgünlük:** Önceki çalışmalar veriyi IoT ile merkezi bir sisteme taşıyıp doktora bırakır. Bu proje araya gerçek zamanlı bir anomali tespit katmanı ekler.
- **Yöntem (üç bileşen):**
  - Sensör donanımı: Raspberry Pi ve Arduino tabanlı, medikal cihazdan bağımsız IoT probları (ateş, kan basıncı, oksimetre, kalp atışı, kızılötesi termometre).
  - Merkezi veri yönetimi yazılımı: sağlık personeli için gösterge paneli (dashboard).
  - Anomali tespiti: LSTM tabanlı, denetimsiz (unsupervised) bir model. Zaman serisindeki anomalileri anlık bulur.
- **İş paketleri:** hastane ile ön araştırma, donanım geliştirme, merkezi yönetim yazılımı, anomali tespit yazılımı, hastane entegrasyonu.
- **Riskler ve B planları:**
  - Parça tedariki: tedarikçi firmalarla görüşme.
  - Siber güvenlik: sistemin hastane içi yerel ağda çalışması.
  - Sistemi kullanmak istemeyen hastalar: daha çok hastane ve poliklinikle iletişim.
- **Bütçe:** 28.500 TL teçhizat (RTX 2080 Ti GPU'lu sunucu, 3B yazıcı dahil), 500 TL sarf (filament), 14.700 TL bursiyer. Toplam 43.800 TL.
- **Hocanın sorusu:** "10 dakikanız var, 20 slayt uygun sayı mı?" Grup fazla slayt koyduğunu kabul eder.

### 3. Sunum: Görme Engelliler İçin Giyilebilir Asistan

- **Problem:** Dünya Sağlık Örgütü'nün 2010 verisine göre dünyada 285 milyon görme engelli vardır; 39 milyonu tamamen kördür. Piyasadaki giyilebilir cihazlar (OTON GLASS prototipi, eSight 4) Türkiye'de satılmaz. eSight 4'ün fiyatı yaklaşık 5950 dolardır.
- **Araştırma sorusu:** Tek kart bilgisayar, kamera, kulaklık ve internetle görme engellilerin çevreye bağımlılığı azaltılabilir mi?
- **Yöntem:** Raspberry Pi 4, 8 MP kamera, 3B yazıcıda basılan gözlük. Sesli komutla çalışan dört mod vardır.
- **İş paketleri (6 paket, 12 ay):**
  - Çalışma ortamı: Raspberry Pi OS, Python, OpenCV; kod Bitbucket'ta, belgeler Confluence'ta.
  - Sesli komut: Jasper açık kaynak platformu. Uyandırma kelimesi uygulamanın adıdır. "Dur" moddan çıkarır, "kapat" uyku moduna alır.
  - Doküman okuma: fotoğraf çekilir, Tesseract OCR ile metne, metinden sese (text-to-speech) çevrilir. Doküman taranamazsa 30 saniyede bir uyarı verilir.
  - Yürüyüş modu: bastona QR kod yapıştırılır. QR kod okununca kamera görüntü çeker, YOLO ve OpenCV ile nesne tanınır.
  - Renk tespiti: giysi gibi nesnelerin rengi söylenir (yedi temel renk).
  - Alışveriş: İTÜ'de hazırlanmış bir veri seti ve DenseNet-121 ile 5-200 TL arası kâğıt paralar tanınır.
- **Riskler:** hava şartları (gözlüğün dayanıklı filamentle basılması), gürültülü ortamda sesli komut (gürültülü veri ile eğitim), aydınlatma (yoğunluk dönüşümleri), QR kodun okunamaması (yönlendirme), yanlış sınıflandırma (modelin güven oranının kullanıcıya söylenmesi).
- **Etki:** Türkçe için literatüre katkı, patent ve ürün potansiyeli, görme engellilerin bağımsızlığı. Ulusal güvenlik açısından doküman okumada kişisel verinin dışarı sızması bir risk olarak anılır.

### 4. Sunum: Federe Öğrenme ile Sağlık Verileri

- **Problem:** Kişisel verileri koruma kanunları (Türkiye'de KVKK) sonrası kurumlar veri paylaşmıyor. Sağlık verisi mahrem olduğu için hastaneler paylaşmaz, modeller az veriyle eğitilir.
- **Çözüm:** Federe öğrenme. Veri hastanede kalır. Merkeze yalnızca model ağırlıkları gider.
- **Akış:**
  - Adım 1: Merkezi model yerel makinelere gönderilir.
  - Adım 2: Her hastane modeli kendi verisiyle eğitir.
  - Adım 3: Yerel ağırlıklar merkeze gönderilir.
  - Adım 4: Merkezi model bu ağırlıklarla güncellenir ve yeniden dağıtılır.
  - Adım 5: Döngü, belirlenen eşik başarıma ulaşılana kadar sürer.
- **İş paketleri (6 paket):** proje yönetimi ve gereksinimler; federe öğrenme altyapısı; makine öğrenmesi modeli; sunucu-istemci mimarisi; federe öğrenme algoritması ve durma kriterleri; test.
- **Riskler:** Yanlış etiketleme (uzman doktor ve radyolog desteği). Hastane yönetiminin sistemi anlamayıp çekinmesi (çalışan bir demo gösterimi).
- **Çıktılar:** SCI indeksli dergide makale, hastanelerde yaygınlaşma, doktorlar için ortak karar destek sistemi, uluslararası iş birliği.
- **Soru-cevap:** Bir öğrenci, ağırlıkların merkeze gitmesinin sorun olup olmayacağını sorar. Grup, ağırlıkların dışarıdan bakan için anlamsız sayılar olduğunu söyler (bkz. ders sonrası notlar).

### 5. Sunum: Blok Zincir Tabanlı Dijital Diploma

- **Problem:** Hologram, ıslak imza ve kabartma kolayca taklit edilir; sahte diploma yaygın bir suçtur.
- **Hipotez:** Diplomalar dijitalleştirilip blok zincirde güvenle saklanabilir ve farklı taraflarca doğrulanabilir.
- **Proje türü:** Tek kişilik bir temel araştırma projesi. Hedef bir ürün değil, sistem modeli ve yol haritasıdır.
- **İş paketleri (4 paket, 8 ay):**
  - Gereksinim analizi (1 ay).
  - Süreç analizi (1 ay): diplomanın oluşturulması, blok zincirde yayınlanması, doğrulanması.
  - Sistem tasarımı: akış diyagramları.
  - Teknik analiz (4 ay, en uzun paket): altyapı, şifreleme algoritmaları, güvenlik.
- **Ekip:** Proje yürütücüsü ve TÜBİTAK BİLGEM'den bir araştırmacı. Biri blok zincir, biri kriptoloji uzmanı iki danışman.
- **Risk:** Teknik soruya danışmanlık ile cevap bulunamaması. B planı: ek eğitim, farklı danışman, seminer veya konferans.
- **Bütçe:** TÜBİTAK'tan yalnız danışmanlık için 18.000 TL. Üniversite iki bilgisayar sağlar.
- **Soru-cevap:**
  - Soru: Onayı hangi kurum verecek? Cevap: Diplomayı üniversite verdiği için üniversite ve YÖK ortak çalışabilir; akıllı sözleşmeler (smart contract) kullanılabilir.
  - Soru: Diplomanın çıktısı alınabilecek mi? Soran öğrenci çıktıya QR kod koymayı önerir. Sunan kişi bunun mantıklı olabileceğini söyler.

### 6. Sunum: Deprem Enkazında Arama Kurtarma Robotu

- Sunumun İngilizce ilk kısmı altyazıda büyük ölçüde anlaşılmıyor. Aşağıdaki bilgiler slayt karesinden ve Türkçe kısımdan alınmıştır.
- **Amaç (slayt):** Depremden sonra enkaz alanında kazazedeleri hızla bulmak, konumlarını ve sağlık durumlarını belirlemek. Arama kurtarma süresini kısaltmak ve başarı oranını artırmak.
- **Özgünlük:** Literatürde A* ve D* gibi maliyet haritası tabanlı yol planlama kullanılır. Bunlar hiperparametre iyi ayarlanmazsa engellere çok yaklaşır.
  - Öneri: potansiyel alan (potential field) tabanlı yaklaşım. Engeller robotu iter, kazazede robotu çeker. Robot bu kuvvetlerin bileşkesiyle hareket eder.
  - Bu yaklaşım, çökmenin sürdüğü dinamik ortamda engelden kaçınmayı da sağlar.
- **Sistem:** mekanik tasarım, elektrik tasarımı, DC motorlar (her tekere bir motor), kontrol (Arduino Mega + Raspberry Pi), yazılım ve haberleşme.
  - Arduino Mega lazer ve kamera verisini işler. Raspberry Pi haritalama, keşif ve yol planlamayı yürütür.
  - Arayüz Java veya C# ile, hızlı hesaplamalar C ve C++ ile yazılacaktır.
  - Robot hem operatörle hem otonom çalışabilir.
- **Gerekçe:** Enkaz altındakiler için ilk 3-4 gün kritiktir; sonra hayatta kalma oranı çok düşer.
- **Soru-cevap:** Termal sensör kullanılacak mı? Cevap: Evet, canlıları tespit etmek için.

### 7. Sunum: Mobil Robotlar İçin Görüntü Tabanlı Konum Belirleme

- **Amaç:** İç ortamda bir mobil robotun 2B konumunu ±5 cm hassasiyetle bulmak. Biri öne, biri arkaya, biri tavana bakan üç kamera kullanılır.
- **Özgünlük:** Kameraların görüntüleri birleştirilmez. Her kameradan ayrı bir konum çıkarılır ve sonra sensör füzyonu (sensor fusion) ile tek konuma indirilir. Kameralar birbirini doğrular.
- **Geliştirme ortamı:** Ubuntu, ROS (Robot Operating System), Gazebo simülasyonu, RViz görselleştirme.
- **Özellik çıkarma:** SIFT, SURF ve ORB değerlendirilir. SIFT ve SURF en iyi sonucu verir ama lisans sorunu nedeniyle ticari aşamada ORB düşünülür.
- **Görsel odometri:** Ardışık karelerdeki eşleşen özelliklerin kaymasından robotun hareketi tahmin edilir. Daha önce görülen bir yere dönülünce döngü kapatma (loop closure) ile birikmiş hata düzeltilir.
- **Füzyon:** Düşük işlem gücü nedeniyle Kalman filtresi seçilir. Tekerlek odometrisiyle uyuşmayan, robotun fiziksel olarak yapamayacağı sıçramalar elenir.
- **Hedef donanım:** 4 çekirdekli, 2,5 GHz işlemci ve 8 GB RAM.
- **İş paketleri (4 paket, 12 ay):** teknik analiz ve kavramsal tasarım; görsel yöntemlerle özellik çıkarma; görsel yöntemlerle konum bulma; konum verilerinin füzyonu.
- **Riskler:**
  - Tavana bakan kamera uzaklık nedeniyle özellik çıkaramayabilir. B planı: daha yüksek çözünürlüklü kamera.
  - Füzyonla hedef başarım tutmayabilir. B planı: GTSAM gibi başka bir yöntem.
- **Çıktılar:** IROS veya ICRA'da bildiri, patent, ticari ürün, iki bursiyer. Sonra 1505 Üniversite-Sanayi İşbirliği programı düşünülür.
- **Bütçe:** 3.668 TL teçhizat (3 kamera, 1 mini bilgisayar), 13.200 TL bursiyer. Toplam 18.868 TL.

### 8. Sunum: Yeniden Kimlik Tespiti

- **Tanım:** Yeniden kimlik tespiti, bir kişinin farklı kameralardan veya açılardan çekilmiş görüntülerini birbiriyle eşleştirmektir.
- **Problem:** Mevcut modeller bazı durumlarda iyi, bazılarında kötü sonuç verir. Çoğu tek bir veri kümesinde test edilmiştir.
- **Literatür:** Yaklaşık 10 makaleden 6 yöntem çıkarılır. Örnekler:
  - Parça tabanlı kayıp: kişinin vücut parçaları ayrı ayrı eşlenir.
  - Top-DB-Net: parçalara önem ağırlığı verilerek benzerlik hesaplanır.
- **Araştırma sorusu:** Modelleri farklı veri kümelerinde test ederek daha başarılı bir birleşik model kurulabilir mi?
- **Hedef uygulamalar:** şüpheli tespiti; futbol ve basketbol oyuncularının hareket ve performans analizi.
- **Proje planı:** MS Project ile hazırlanmış, üç kilometre taşı vardır: tasarım, uygulama, satış.
  - Tasarımda yöntemler seçilir, test kriterleri belirlenir. Modellerin ne zaman devreye gireceği analitik hiyerarşi süreci (AHP) ile kararlaştırılır.
  - Uygulamada pazarlar büyüklüğe göre sıralanır (savunma, iç güvenlik, spor, eğlence) ve SWOT analizi yapılır.
  - Satış aşamasında fiyat politikası, demo sürüm ve sözleşme formatı hazırlanır.
- **Risk:** Her aşama için "şeytanın avukatlığı" yapılarak risk planı çıkarılır. Kadro geniş tutulur: iki yüksek lisans, iki doktora öğrencisi. COVID-19 ve hastalık için B planı ve sigorta düşünülür.
- **Çıktılar:** önce patent, sonra makale; girişim (start-up); iki yüksek lisans ve bir doktora tezi.
- **Bütçe:** 1002 üst sınırı 45.000 TL olarak verilir. Dağılım: teçhizat %35, bursiyer %25, hizmet alımı %27. Seyahat gideri konmamıştır.

### Ders sonrası notlar

- **Federe öğrenme (4. sunum):** "Ağırlıklar dışarıdan bakan için anlamsızdır, hassas veri oluşturmaz" cevabı eksiktir.
  - Gradyan sızıntısı (gradient leakage), model tersine çevirme (model inversion) ve üyelik çıkarımı (membership inference) saldırılarıyla ağırlıklardan eğitim verisi hakkında bilgi elde edilebilir.
  - Bu yüzden federe öğrenme genellikle diferansiyel mahremiyet (differential privacy) veya güvenli toplama (secure aggregation) ile birlikte kullanılır.
  - Sunumdaki "ülkemizde ilk kez uygulanacak" gibi özgünlük iddiaları bir literatür ve uygulama taramasıyla desteklenmelidir.
- **Kaynak kullanımı (1. sunum):** Yanlılık tanımı Wikipedia'dan verilir. Akademik bir başvuruda tanımlar hakemli kaynaklara dayandırılmalıdır.
- **Lisans (7. sunum):** SIFT'in patenti Mart 2020'de sona ermiştir; SIFT OpenCV 4.4'ten beri ana modüldedir. Lisans sorunu SURF için hâlâ geçerlidir (OpenCV'de "nonfree" modülde).
- **Potansiyel alan (6. sunum):** Yapay potansiyel alan yöntemi yerel minimumlara (local minima) takılabilir. Bu bilinen sınırlılık risk planında yer almalıdır.
- **Patent ve yayın (8. sunum):** "Sunumdan önce patent almamız gerekir" fikri doğru yöndedir.
  - Türkiye'de 6769 sayılı Sınai Mülkiyet Kanunu, buluş sahibinin kendi açıklamasına 12 aylık bir hoşgörü süresi tanır.
  - Avrupa Patent Ofisi'nde böyle bir süre yoktur. Bu yüzden en güvenli yol, yayından önce patent başvurusu yapmaktır.
- **Bütçe tutarlılığı (8. sunum):** Verilen yüzdelerin toplamı %87'dir. Kalan kalemler (ör. iletişim gideri) bütçe tablosunda açıkça gösterilmelidir.
- **Etik (8. ve 2. sunum):** Kişi takibi ve sağlık verisi içeren projelerde etik kurul onayı ve KVKK uyumu bir iş paketi veya risk olarak yazılmalıdır.
- **Altyazıdaki bozuk terimlerin doğruları:**
  - "LSM" → LSTM.
  - "TestRoc" → Tesseract.
  - "Zibar" → ZBar (QR kod kütüphanesi).
  - "yola" → YOLO.
  - "OpenSea" → OpenCV.
  - "eSign 4" → eSight 4.
  - "Gazava" → Gazebo.
  - "RVZ" → RViz.
  - "kalma filtresi" → Kalman filtresi.
  - "GTSM" → GTSAM.
  - "Aeros / İKRA" → IROS / ICRA.
  - "All Star, Least Star" → A*, D* türü algoritmalar.
  - "top-db.net" → Top-DB-Net.
  - "SC dergileri" → SCI indeksli dergiler.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
