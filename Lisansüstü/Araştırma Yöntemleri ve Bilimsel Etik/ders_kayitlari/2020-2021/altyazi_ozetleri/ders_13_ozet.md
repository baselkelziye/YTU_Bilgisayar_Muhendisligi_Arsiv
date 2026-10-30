# Ders 13 Çalışma Özeti

## Genel Konular

- Bu ders (10 Haziran 2021) dönemin son dersi ve proje sunumlarının son haftasıdır. Konu anlatımı yoktur.
- Öğrenciler TÜBİTAK 1002 Hızlı Destek Programı formatında hazırladıkları araştırma projesi önerilerini sunar.
- Bu derste 8 sunum yapılır:
  - 1. sunum: Sokak hayvanları için otomatik besleme istasyonu.
  - 2. sunum (grup 8): Antalya bölgesinde domates hastalıklarını tespit eden mobil uygulama.
  - 3. sunum: Kullanıcı arayüzü testi için GAN ile otomatik test kodu üretimi.
  - 4. sunum (grup 13): Bulut tabanlı görsel etiketlemeyle akıllı galeri uygulaması.
  - 5. sunum: Çok görevli öğrenmeyle banka dokümanlarında alan tespiti, bilgi çıkarımı ve imza doğrulama.
  - 6. sunum (grup 16): Topraksız dikey tarımda makine öğrenmesiyle verim ve kaynak optimizasyonu.
  - 7. sunum: Sentetik hiperspektral görüntülerle domates hastalığı tespiti (DOHTES).
  - 8. sunum (grup 32): Türkçe sahte haber tespiti.
- Ders sonunda hoca final sınavının biçimini duyurur ve dönemi kapatır.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Final sınavı:**
  - Final, programda ilan edilen gün ve saatte online sistem üzerinden yapılacak. Hoca tarihin duyurulduğundan emin değildir; duyurulmadıysa yakında duyurulacağını söyler.
  - Sorular çoktan çok seçmelidir: bir sorunun birden fazla doğru şıkkı olabilir.
  - Sorunun doğru sayılması için tüm doğru şıkların işaretlenmesi gerekir. Yanlış bir şık işaretlenirse soru yanlış sayılır.
  - Yanlışlar doğruyu götürür: şık sayısı 4 ise 3 yanlış 1 doğruyu, 5 ise 4 yanlış 1 doğruyu götürür.
- **Eksik sunumlar:** Önceki haftalarda sunum yapamayan gruplara son hafta sunum yapabileceklerini e-postayla bildirmiştir. Derste olan varsa sunumunu tamamlayabilir.
- **Soru-cevap:** Hoca her sunumdan sonra soru olup olmadığını sorar. Çoğu sunumdan sonra soru gelmez ("her zaman olduğu gibi").

## Kısa Tekrar Notları

- Final: online, çoktan çok seçmeli, kısmi puan yok, yanlışlar doğruyu götürür.
- Sunumlarda tekrar eden proje önerisi öğeleri:
  - Araştırma sorusu ve hipotez
  - Literatürdeki boşluk ve özgün değer
  - İş paketleri, süreleri ve başarıya katkı oranları
  - Gerçekleşme olasılığına göre sınıflanmış riskler ve B planları
  - Akademik, ekonomik, toplumsal ve çevresel etki
  - Bütçe
- Sunumlarda geçen önemli kavramlar:
  - Üretken çekişmeli ağ (Generative Adversarial Network, GAN): üretici (generator) ve ayırt edici (discriminator)
  - Koşullu GAN (cGAN)
  - Çok görevli öğrenme (multi-task learning)
  - Alan uyarlama (domain adaptation)
  - Artık bağlantılı ağ (ResNet)
  - Naive Bayes, karar ağacı, lojistik regresyon

## Detaylı Açıklamalar

### 1. sunum: Sokak hayvanları için otomatik besleme istasyonu

- **Problem:**
  - Şehirleşme ve betonlaşma sokak hayvanlarının yaşam alanlarını daraltır.
  - Pandemi ve karantina dönemlerinde beslemeler aksar.
  - Bilinçsiz beslemede hayvana zararlı yiyecekler verilir (ör. köpeklere tavuk kemiği).
  - Aç kalan hayvanlar agresifleşebilir.
  - Kalan yemekler çürüyerek koku ve hijyen sorununa yol açar.
- **Tarihsel arka plan:** Sunuma göre Osmanlı döneminde halk, sokak hayvanlarını beslemesi için belirli kişilere para verirmiş.
- **Araştırma sorusu:** İstanbul'daki sokak hayvanlarını daha verimli ve sağlıklı beslemek mümkün mü?
- **Hedefler:** Toplumsal bir hayvan koruma bilinci oluşturmak. Ekonomik ve toplumsal faydayı net ortaya koymak. Prototipi şehrin küçük bir bölgesinde test edip sonra yaygınlaştırmak.
- **Sistemin özellikleri:**
  - Kedi, köpek ve kuşlar beslenir. Kedi ve köpek kapları yerde, kuş bölümü 3 m'lik bir direğin üstündedir; kuşlar için yuva kutuları da vardır.
  - Kameralar ve yapay zeka ile gelen hayvanın türü ve boyutu belirlenir, uygun mama verilir.
  - Sensörler mama deposunu izler. Stok azalınca belediye ekiplerine bildirim gider.
  - Halk mobil uygulama ya da istasyondaki kartlı ödeme ile bağış yapabilir.
- **Bileşenler:** Kamera, depo doluluğu için mesafe sensörü, ödeme sistemi, Raspberry Pi, 3G/4G/LTE modülü, yaklaşık 15 kg'a kadar yükü destekleyen servo motor (mama kapağını açıp kapatır), motor sürücü, güç kaynağı.

### 2. sunum (grup 8): Domates hastalıklarını tespit eden mobil uygulama

- **Önem:**
  - Sunumda FAO'nun 2018 verilerine göre dünya domates üretiminin yaklaşık 182 milyon ton olduğu söylenir.
  - Türkiye'nin yıllık üretimi yaklaşık 12,85 milyon tondur. Bu üretimin yaklaşık %19,7'si (yaklaşık 2,53 milyon ton) Antalya'dadır. Bu yüzden pilot bölge Antalya seçilmiştir.
  - Domates hastalıkları üç gruba ayrılır: mantar (fungal), bakteriyel ve virüs kaynaklı. Belirtiler yaprak, gövde ve meyvedeki renk ve şekil bozukluklarıdır.
- **Amaç:** Hastalığa hızlı ve yüksek başarıyla tanı koymak. Literatürdeki kültürel ve kimyasal mücadele yöntemlerini kullanıcıya sunmak. Üretim verimini artırmak.
- **Yöntem (iş paketleri):**
  1. Veri ihtiyacının karşılanması (ilk 4 ay, başarıya katkı %50): PlantVillage veri seti ve Antalya'da üreticilerden toplanacak saha verisi.
  2. Uygulamanın geliştirilmesi (5 ay, %35): React Native ile iOS ve Android uygulaması. Ön yüz, arka yüz, web servisleri ve modelin uygulamaya yüklenmesi.
  3. Son kullanıcı testleri ve yayın: Uygulama markete çıkmadan önce çiftçilerle pilot çalışma yapılacak.
- **Model süreci (5 aşama):**
  1. Görsel toplama
  2. Görsel işleme (Gaussian blur)
  3. Segmentasyon: yaprağı arka plandan ayırmak için iki merkezli K-ortalama (K-means) kümeleme
  4. Sınıflandırıcı seçimi: evrişimsel sinir ağı (CNN)
  5. Hiperparametre araması ve en iyi modelin seçimi
- **Riskler:**
  - Düşük olasılık: yeterli veri toplanamaması. Saha çalışması bu riski azaltır.
  - Orta olasılık: hedef başarının tutturulamaması. Hiperparametre ayarı ya da farklı bir derin öğrenme yöntemi.
  - Yüksek olasılık: çiftçilerin uygulamayı kullanmakta zorlanması. Pilot çalışma ve yakın iletişim.
- **Etki:** Yanlış ilaçlamanın önlenmesiyle toprak sağlığının korunması. Türkiye'de bu alandaki az sayıdaki çalışmaya (ör. kayısı) katkı. Kayıpların azalmasıyla ihracatın artması ya da iç piyasada fiyatların düşmesi.
- **Soru-cevap:** Sentetik görüntü kullanmayı düşünüp düşünmedikleri sorulur. Grup bunu düşünmediğini söyler. PlantVillage'da yaklaşık 60 bin görüntü olduğunu, gerekirse benzer veri üretilebileceğini belirtir.

### 3. sunum: GAN ile otomatik arayüz testi kodu üretimi

- **Problem:** Kullanıcı arayüzü testi zordur, çünkü arayüz sık değişir. Yeni web öğeleri eklenir ve testlerin sürekli güncellenmesi gerekir.
  - Selenium gibi araçlar testi otomatikleştirir. Ancak "sayfayı aç, şu butonu bul, şu alanı doldur" adımlarını programcı elle kodlar.
  - Grup bu adımların da bilgisayar tarafından üretilmesini istiyor.
- **Neden üretken model?**
  - Sınıflandırıcı, yeni bir örneğin hangi sınıfa girdiğine karar verir. Ör. 100 kedi ve 100 köpek resmi varsa yeni resmin hangisi olduğunu söyler.
  - Üretken model ise eğitim verisine benzer yeni örnek üretir. Ör. 100 kedi resminden 101. kediyi üretir.
  - Test senaryosu ardışık adımlardan oluştuğu için diziler üretebilen SeqGAN mimarisi seçilmiştir.
- **GAN'ın çalışması:**
  - Üretici (generator) rastgele gürültüden eğitim verisine benzeyen örnekler üretmeyi öğrenir.
  - Ayırt edici (discriminator) gerçek ve sahte örnekleri ayırt etmeyi öğrenir.
  - İki ağ birbirini geliştirir. Eğitimden sonra yalnızca üretici kullanılır.
- **Hedefler ve iş paketleri:**
  1. Sayfa yapısı bilinen bir site taranır (crawl), sayfa akışları çıkarılır.
  2. GAN ile bu site üzerinde yeni akışlar üretilir. Hiperparametreler sezgisel optimizasyon yöntemleriyle ayarlanır.
  3. Üretilen akışlar incelenir. Sayfa yapısına uymayan, gidilmesi mümkün olmayan akışlar elenir; gerekirse mimari değiştirilir.
  4. Kalan akışlardan Selenium test betikleri üretilir. Örnek: bir URL'ye POST isteği gönderildikten sonra dönen durum kodunun 201 olup olmadığının kontrolü.
- **Hedeflenen kazanç:** Test kodu yazma maliyetinde yaklaşık %90 azalma. Değerlendirmede perplexity skoru kullanılacak.
- **Çıktılar ve etki:** Kodlar açık kaynak olarak GitHub'da paylaşılacak. Bir bildiri, bir makale ve bir tez hedefleniyor. Ar-Ge sonrası ticari ürün olabilir. İleride LSTM gibi başka mimariler de denenebilir.

### 4. sunum (grup 13): Akıllı galeri uygulaması

- **Problem:** Telefonlardaki fotoğraflara hızlı ulaşmak zordur. Piyasadaki galeri uygulamalarının durumu:
  - Android'deki Google Fotoğraflar daha fazla gruplama sunar. Ancak kategorilendirme için Google Drive senkronizasyonu gerekir; gizlilik ve veri maliyeti nedeniyle kullanıcılar bunu istemeyebilir.
  - Sony Xperia'nın albüm uygulaması tasarım olarak iyidir ama kategorilendirme yapmaz.
  - iOS galerisi çevrim dışı gruplama ve anahtar kelimeyle arama sunar, ama kategorileri kısıtlıdır. Android'de benzeri yoktur.
- **Öneri:** Fotoğraflar bulutta bir kez taranır ve etiketler uygulamaya alınır. Sonrasında arama, çevrim dışı ve gerçek zamanlı yapılır.
  - Ör. doğum günü fotoğrafları için "pasta" araması, tarih aralığıyla daraltma, "kar" araması.
- **Fizibilite:**
  - Yazılım: Android, API 16 ve üzeri desteklenir, hedef API 25.
  - Donanım: Android Studio çalıştıran ve tercihen güçlü ekran kartı olan bir bilgisayar, test cihazı.
  - Görsel analiz Google Cloud Vision API ile yapılır.
- **Teknik yöntem:**
  - Meta veriler (tarih, konum, çözünürlük) gruplama için kullanılır.
  - Çevrim dışı modüller: yüz özelliklerine göre vesikalık ve gülümseyen fotoğraflar; art arda çekilmiş benzer fotoğrafların tespiti (yer açmak için).
  - Bulut modülü: ağır hesaplama mimari gereği mobil cihazda yapılmamalıdır. Bu yüzden içerik etiketleri buluttan alınır.
- **İş paketleri:** 6 iş paketi. Veri yönetimi ve arayüz, görsel arama modülü ve benzer fotoğraf algoritması paralel yürür. Google Cloud API'den etiket alma ve çevrim dışı tarama modülü sıralı yürür.
- **Riskler:**
  - Benzer fotoğraf modelinin başarısı düşük kalırsa ek meta veri kullanılacak.
  - API maliyetleri yükselirse başka sağlayıcıya geçilecek ya da yerel sunucuda önbellek tutulacak.
  - Uygulama çok enerji tüketirse ağır işler yalnızca sınırsız ağda ve şarjdayken yapılacak.
- **Çıktılar ve bütçe:** Bir makale ve fotoğrafçı, gazeteci gibi profesyonellere de yarayan bir uygulama. Bütçe: cihaz, API hizmet alımı, iki bursiyer.

### 5. sunum: Banka dokümanlarında çok görevli öğrenme

- **Problem:** Dijital bankacılık kullanıcısı artıyor. Ancak dijital kanallardan alınan müşteri evrakı hâlâ elle işleniyor ve arşivleniyor.
  - Bu iş rutindir ama çok insan kaynağı ve zaman harcar.
  - İnsan kaynaklı hatalar maddi zarara yol açabilir.
  - Göz ile ayırt edilemeyecek kadar iyi taklit edilmiş imzalar olabilir.
- **Üç görev:**
  1. İmza doğrulama (belge güvenliği)
  2. Bilgi içeren alanların tespiti (ad, soyad, adres, telefon, kart numarası vb.)
  3. Bu alanlardaki içeriğin optik karakter tanıma (OCR) ile çıkarılması
- **Özgün değer:** Literatürde her görev için ayrı çalışmalar var. Ancak üçünü tek belge üzerinde uçtan uca yapan bir sistem yok.
- **Neden çok görevli öğrenme?**
  - Üç ayrı model art arda bağlanırsa sistemin başarısı en zayıf halkayla sınırlanır. Ör. alanlar bulunamazsa OCR da çalışmaz.
  - Çok görevli öğrenmede tek bir ortak öznitelik çıkarıcı vardır. Çıkarılan öznitelikler göreve özel sınıflandırıcılara gider.
  - Eğitim, üç görev için ortak hesaplanan bir kayıp fonksiyonuyla eş zamanlı yapılır.
  - Kaynak alınan çalışmada basit sınıflandırıcılar kullanılmış. Bu projede OCR için RNN gibi daha karmaşık başlıklar gerekiyor. Yöntemin karmaşık modellerdeki başarısını ölçmek de bir katkı olacak.
- **Hipotez:** Bu alanlarda derin öğrenme, geleneksel yöntemlerin başarısını geçebilir.
- **Veri:**
  - İmza doğrulama için açık veri setleri var.
  - Türkçe bankacılık evrakı için açık veri seti yok. Grup, öğrencilerden birinin çalıştığı bir bankadan maskelenmiş ve sentetik verilerle üretilmiş 1000 doküman alacak. Bu belgeler hesap açılış sözleşmesi, para transferi formu, kredi kartı başvurusu gibi yaygın belgelerdir.
  - Etiketleme Amazon Mechanical Turk ile yapılacak. Bu veri seti literatüre kazandırılacak.
- **Değerlendirme:** Basit bir web uygulaması 10 kişilik bir grup tarafından 2 hafta test edilecek ve anketlerle değerlendirilecek.
- **Riskler:**
  - Model başarısı düşük kalırsa farklı omurga (backbone) mimarileri denenecek: VGG, ResNet, Inception.
  - Veri yetersiz kalırsa veri artırma (data augmentation) kullanılacak.
  - Test katılımcısı yetersiz kalırsa anketler Mechanical Turk üzerinden yapılacak.

### 6. sunum (grup 16): Topraksız dikey tarımda makine öğrenmesi

- **Problem:** Nüfus artıyor, verimli topraklar betonlaşmayla azalıyor. Kaliteli besine ulaşım zorlaşıyor. Topraksız tarım bu soruna bir çözümdür.
- **Literatürdeki boşluk:** Makine öğrenmesiyle hasat tahmini çalışmaları çoğunlukla geleneksel tarım üzerinedir.
- **Araştırma sorusu:** Topraksız dikey tarımda yapay zeka ve makine öğrenmesiyle ürün verimini artırıp kaynak tüketimini azaltmak mümkün mü?
- **Yenilik:** Üretim başlamadan önce sistemin çok verimli, verimli, az verimli ya da verimsiz olacağını tahmin etmek ve üretimi buna göre başlatmak.
- **İş paketleri (4 ana, 11 ara iş paketi):**
  1. Ekonomik analiz (1-2. ay): topraksız ve geleneksel üretimin kâr-zarar karşılaştırması.
  2. Üretim sistemi altyapısı (1-3. ay): kapalı cam kabin sipariş edilir ve donanımlar kurulur. Literatürdeki PVC boru düzeni yerine tepsiler kullanılacak.
  3. Veri seti araştırması (3-10. ay): Bir bitki bilimi uzmanından başlangıç verisi ve optimum değerler alınır. Her hasattan sonra veri seti genişletilir.
  4. Raporlama ve gelecek planı (9-12. ay): sonuçlar mevcut topraksız tarım verileriyle karşılaştırılır, uluslararası bildiri hazırlanır.
- **Yöntem:**
  - Pilot bitki nanedir. Optimum büyüme koşulları: pH, EC (elektriksel iletkenlik), sıcaklık, nem.
  - Hasat ilerledikçe yaprak büyüklüğü, genişliği ve besin değerleri gibi parametreler eklenecek.
  - Literatürde sık kullanılan KNN ve karar ağacı algoritmalarına bir algoritma daha eklenip karşılaştırma yapılacak. Bu algoritmanın adı altyazıda anlaşılmıyor.
- **Riskler:**
  - Genel riskler: hastalık, afet, ekonomik kriz, pandemi.
  - Cihaz arızası: önemli cihazlar yedekli alınır.
  - Hastalıklı fide: bilinen bir markadan alınır.
  - En büyük risk veri kaybıdır: veriler birden fazla sunucuda yedeklenir.
  - Referans değer hatası: bitki bilimi uzmanıyla çalışılır.
  - Bildiri reddi: farklı indeksli dergilere gönderilir, hızla revize edilir.
- **Etki:** Literatüre yeni bir bakış ve yeni veri seti. Prototip cihazın seri üretilebilmesi. Su ve elektriğin optimum kullanımı. İthalat ihtiyacının azalması.
- **Bütçe:** Toplam yaklaşık 24.328 TL.
- **Gelecek planı:** Her bitki için optimum koşulları otomatik hesaplayıp farklı sistemlere uygulayan bir ürün.

### 7. sunum: DOHTES (Domates Hastalık Tespit Sistemi)

- **Gerekçe:** Domates besin değeri yüksek ve çok tüketilen bir üründür. Sunuma göre Türkiye dünya domates ihracatında üçüncüdür ve hedef birinci olmaktır.
- **Hastalıklar:** Külleme gibi mantar hastalıkları, lekeli solgunluk virüsü gibi virüs hastalıkları ve bakteriyel hastalıklar.
- **Tespit yöntemleri:**
  - Moleküler ve spektroskopik yöntemler laboratuvar ister; zaman ve bütçe açısından pahalıdır.
  - Görüntü yöntemleri CNN'lerin başarısıyla öne çıkmıştır. Görüntü türleri: termografik (bitkinin ısı bilgisi), RGB ve hiperspektral (görünür ışıktan daha geniş spektrum).
  - İlk RGB çalışmalarında öznitelikler elle çıkarılırdı; bu yorucu ve zaman alıcıdır. Derin öğrenme daha başarılıdır ama çok veri ister. Bu yüzden sentetik veri üretimine yönelinmiştir.
  - Referans çalışmalardan birinde GAN ile sentetik veri üretilmiş ve sınıflandırmada ResNet en iyi sonucu vermiştir.
- **Fikir:** Hiperspektral görüntüler, RGB'de görülemeyen hastalıkları daha erken gösterebilir. Ancak hiperspektral kameralar çok pahalıdır. Grup RGB görüntüden sentetik hiperspektral görüntü üretmeyi önerir. Domates hastalık tespitinde böyle bir çalışma yoktur.
- **Sistem (slayttaki şema):**

```text
RGB domates yaprağı görüntüsü -> cGAN -> (sentetik hiperspektral görüntü) -> ResNet -> X hastalıklı / sağlıklı
```

- **1. iş paketi (cGAN, 2 ay):**
  - Koşullu GAN eğitimi için RGB ve hiperspektral görüntü çiftleri gerekir.
  - Başka bir alana ait açık hiperspektral veri seti ICVL kullanılır (alan uyarlama, domain adaptation).
  - ICVL'de RGB karşılıkları yoktur. Bu yüzden CIE 1964 10° renk eşleme fonksiyonlarıyla hiperspektral görüntülerden RGB görüntüler hesaplanır.
  - Elde edilen veri çiftleri açık kaynak olarak paylaşılacak.
  - Eğitilen cGAN ile açık bir RGB domates veri setinden sentetik hiperspektral domates görüntüleri üretilecek. Bu veri seti de açık kaynak olarak paylaşılacak.
- **2. iş paketi (ResNet):**
  - Sentetik hiperspektral görüntülerle mozaik virüsü, yaprak küfü, erken yaprak yanıklığı gibi 9 hastalık sınıflandırılacak.
  - ResNet, derin ağlarda katman sayısı arttıkça öğrenmenin bozulması sorununa artık bloklarla (residual blocks) çözüm getirir. 2015 ImageNet (ILSVRC) yarışmasında birinci olmuştur.
  - Model eğitildikten sonra Antalya'da ziraat mühendisleri eşliğinde saha testi yapılacak.
- **Bütçe kalemleri:** Kaliteli bir RGB kamera ve hiperspektral görüntüler için disk.

### 8. sunum (grup 32): Türkçe sahte haber tespiti

- **Önem:**
  - Sahte haberler yanlış bilgilendirir, korku ve umutsuzluk yayar, ekonomik kayba yol açar. Bunların çoğu programlanmış botlarca sürekli yayılır.
  - En hızlı yayılan ve en riskli türler: propaganda, manipülasyon, deepfake, provokatif içerik ve nefret söylemi. Sahte bilimsel haberler ve asparagas haberler de hızlı yayılır.
  - Sunumdaki grafiğe göre Türkiye, sahte habere maruz kaldığını söyleyenlerin oranında %49 ile ilk sıradadır.
  - Türkiye'de haber kaynakları: çevrim içi platformlar %88, televizyon %75, sosyal medya %66, basılı yayın %50'nin altında.
- **Amaç:** Sahte haber çalışmalarının çoğu İngilizce; Türkçe veri seti eksik. Öncelikli amaç bir Türkçe veri seti oluşturup literatüre kazandırmak, sonra doğal dil işleme ve makine öğrenmesiyle sınıflandırma yapmak.
- **Literatür:** Önceki bir Türkçe çalışmada veri GDELT (100'den fazla dilde dünya haber medyasını izleyen küresel veri tabanı), teyit.org (Türkiye merkezli doğrulama platformu) ve elle derlenmiş veriden toplanmış. GDELT haberlerinden yalnızca Anadolu Ajansı gibi büyük ajansların haberleri kullanılmış.
- **1. adım, veri seti:** GDELT, Twitter, Facebook ve Instagram gibi platformlar ile güvenilir haber siteleri. Güvenilir sitelerden gelenler "doğru" etiketlenir, kalanlar elle etiketlenir.
- **2. adım, ön işleme:** Durak kelimeler (stop words) atılır. HTML ve JavaScript kodları temizlenir. Türkçe karakterler arındırılır. Zemberek kütüphanesiyle biçimbilimsel (morfolojik) analiz yapılır.
- **3. adım, sınıflandırma:** dört yöntem karşılaştırılır:
  - Naive Bayes: Bayes teoremine dayanır, her sınıfın olasılığını hesaplar ve en olası sınıfı seçer.
  - Karar ağacı: öznitelik uzayını kurallarla böler ("if" yapıları gibi). Köke en ayırt edici öznitelik konur; seçimde bilgi kazancı kullanılır.
  - Lojistik regresyon: sonuç ikilidir (doğru/sahte).
  - CNN: veri eğitim, doğrulama ve test olarak ayrılır. Başlangıçta 3 katman, ReLU aktivasyonu ve ikili çapraz entropi (binary cross-entropy) kaybı kullanılacak. Epoch ve batch sayısı doğrulama sonuçlarına göre ayarlanacak.

### Ders sonrası notlar

- **2. sunum:** Gaussian blur görüntüdeki bulanıklığı gidermez; görüntüyü yumuşatarak gürültüyü azaltır. "Bulanıklıklara karşı Gaussian blur" ifadesi yanlış. Bulanıklık gidermek için keskinleştirme ya da ters evrişim (deconvolution) kullanılır.
- **2. sunum:** Altyazıda verilen tüketim rakamları birbiriyle tutarsız. Yaklaşık 9,5 milyon ton iç tüketim ve 83 milyon nüfus kişi başı yaklaşık 114 kg eder; sunumda geçen "14,5 kg" bununla uyuşmaz. PlantVillage'ın tamamında yaklaşık 54 bin görüntü vardır; domates sınıfları bunun bir kısmıdır.
- **2. ve 7. sunum:** Türkiye'nin dünya domates ihracatındaki sırası 2. sunumda beşinci, 7. sunumda üçüncü olarak verilir. Sıra yıla ve kaynağa göre değişir; raporda kaynak belirtilmelidir.
- **3. sunum:** Selenium bir tarayıcı otomasyon aracıdır. HTTP durum kodunu (ör. 201) doğrudan döndürmez. Bu tür API kontrolleri için REST Assured gibi araçlar ya da doğrudan HTTP istemcileri kullanılır.
- **4. sunum:** "Tüm araçlar açık kaynak" denirken Google Cloud Vision API kullanılıyor. Bu ticari bir servistir. Ayrıca KVKK Türkiye'deki yasadır, Google'ın sunduğu bir şey değildir. Kişisel veri içeren fotoğrafları yurt dışındaki bir buluta göndermek KVKK'nın yurt dışına veri aktarımı kurallarına tabidir.
- **5. sunum:** Çok görevli öğrenme için anılan çalışma Ozan Sener ve Vladlen Koltun'un "Multi-Task Learning as Multi-Objective Optimization" (NeurIPS 2018) makalesidir. Altyazıda "Şener ve Colton" diye geçiyor.
- **7. sunum:** CIE 1964 10° bir kamera değildir. Bu, standart gözlemcinin renk eşleme fonksiyonlarıdır. Hiperspektral görüntüden RGB hesaplamak için kullanılır.
- **7. sunum:** ResNet'te artık blokta, bloğun girişi kısayol bağlantısıyla (skip connection) iki evrişim katmanının çıkışına eklenir. "Peş peşe gelen iki konvolüsyonel katmanın çıkışlarının eklenmesi" ifadesi bunu tam anlatmıyor.
- **8. sunum:** Karar ağacında en yüksek bilgi kazancını (entropideki en büyük azalmayı) veren öznitelik seçilir. "Entropi ne kadar büyükse özellik o kadar bilgi içerir" ifadesi yanlış. Yüksek entropi, bir düğümdeki belirsizliğin yüksek olduğunu gösterir.
- **8. sunum:** Lojistik regresyonu seçme gerekçesi "problemimiz doğrusal" değil, "problemimiz ikili sınıflandırma" olmalıdır.
- **8. sunum:** Türkçe karakterleri metinden silmek anlam kaybına yol açabilir (ör. "sık" ve "sik" ayrımı). Güncel kütüphanelerin çoğu UTF-8'i destekler. Zemberek de Türkçe karakterlerle çalışır.
- **Whisper hataları:**
  - "Mancacı": sunumdaki tarihsel meslek adı anlaşılmıyor.
  - "Plant glitch" → PlantVillage
  - "iki merkezde kağı ortalama" → iki merkezli K-ortalama
  - "kan / gam / sekkan mimarisi" → GAN / SeqGAN
  - "elestiyen" → LSTM
  - "R&L" → RNN
  - "Seagent / SIGEN / SIGENS" → cGAN
  - "Resmet" → ResNet
  - "İmeçnet" → ImageNet
  - "Seyit.org" → teyit.org
  - "CİDELT / Cidel" → GDELT
  - "zembelek" → Zemberek
  - "Newe Bayes" → Naive Bayes

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
