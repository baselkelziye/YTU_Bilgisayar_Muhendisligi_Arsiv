# Ders 12 Genişletilmiş Notu: Öğrenci Sunumları: İnce Eylem Tanıma, MEVA, Model Ters Çevirme Saldırısı, Öğrenilebilir Veri Artırma, Bağlam R-CNN ve CoSOD

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. İnce Ayrıntılı İnsan Eylemlerini Tanıma İçin Yeni Bir Veri Seti
- 3. MEVA: Çok Görüşlü ve Çok Kipli Etkinlik Tespiti Veri Seti
- 4. Üretken Model Ters Çevirme Saldırısı (GMI)
- 5. Metin Tanımada Öğrenilebilir Veri Artırma
- 6. Bağlam R-CNN: Statik Kameralarda Uzun Süreli Zamansal Bağlam
- 7. Ortak Belirgin Nesne Tespiti (CoSOD) ve CoSOD3k
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Biçimi

Bu ders tamamen öğrenci makale sunumlarına ayrıldı. Her öğrenci, bilgisayarla görme alanında yayımlanmış (çoğu CVPR 2020) bir makaleyi yaklaşık 20 dakikada anlattı; sunumdan sonra hoca ve diğer öğrenciler soru sordu. Toplam altı sunum yapıldı. Aşağıda her sunum ayrı bir bölüm olarak, sunumda anlatıldığı sırayla verilmiştir. Sunumlardaki sayısal değerler mümkün olduğunca ekrandaki slaytlardan alınmıştır.

> **Hocanın vurgusu:** CVPR, bilgisayarla görme alanında çok güçlü bir konferanstır; buradaki çalışmaları okumak alanda ufuk açar.

## 2. İnce Ayrıntılı İnsan Eylemlerini Tanıma İçin Yeni Bir Veri Seti

Birinci sunumda CVPR 2020'de yayımlanmış, derin öğrenmenin ince (subtle) insan eylemlerini tanıyıp tanıyamayacağını soran bir makale anlatıldı.

> **Ek bilgi (derste anlatılmadı):** Makale büyük olasılıkla "Can Deep Learning Recognize Subtle Human Activities?" başlıklı çalışmadır. Altyazıda başlık bozuk yazıya dökülmüştür.

Sunumu yapan öğrenci konuyu, dersin ilk haftasında uygulama alanları arasında sayılan insan aktivitesi tanıma başlığından esinlenerek seçtiğini söyledi. Makalenin yazarlarından birinin biyoloji, yapay zekâ ve hesaplamalı sinirbilim alanlarında çalışan bir profesör olduğu belirtildi. Hoca burada disiplinler arası çalışmalarda bir alan uzmanına (domain expert) ihtiyaç duyulabileceğini, bu yazarın da böyle bir rol üstlenmiş olabileceğini ekledi.

### 2.1 Action ve Activity

Literatürde "action recognition" ve "activity recognition" başlıkları çoğu zaman birbirinin yerine kullanılır (ekrandan, 00:15:00). Sunumda yapılan ayrım şöyledir:

- **Action (eylem):** insanın tek başına yaptığı hareket; el sallamak, koşmak gibi.
- **Activity (aktivite):** bir nesneyle ya da başka insanlarla etkileşim içeren eylem.

İki terim arasında net bir sınır yoktur; aktivite başlığı altında eylemleri de kapsayan çalışmalar vardır. İnsan pozu kestirimi (human pose estimation), yani insan vücudunun duruşunu bulma çalışmaları, her ikisinin de temelini oluşturur.

Makalenin üç katkısı vardır: yeni bir veri seti oluşturmak, bu veri setini mevcut derin öğrenme ve geleneksel makine öğrenmesi modelleriyle test etmek ve kendi önerdikleri bir modeli denemek. Asıl amaç yeni ve zor bir veri seti oluşturmaktır. Makalede matematiksel türetme neredeyse yoktur; çalışma uygulamalıdır.

### 2.2 "Subtle" Kavramı ve Mevcut Veri Setlerinin Sorunu

UCF-101 gibi mevcut eylem tanıma veri setlerinde eylem çoğu zaman sahnenin kendisinden anlaşılır (ekrandan, 00:20:00). Gitar çalan bir kişide gitar ve mikrofon, bowling görüntüsünde lobutlar ve pist, paraşütle atlamada mavi gökyüzü ve bulutlar, eylemin ne olduğunu ele verir. Böyle veri setlerinde birkaç nesne ya da arka plan ipucuyla şans düzeyinin üstünde bir tahmin yapılabilir; bu yüzden bu veri setleri "kolay" kabul edilmiştir.

Makalenin oluşturduğu veri setinde ise aynı nesne ve neredeyse aynı duruş, eylemin yapıldığı ve yapılmadığı görüntülerde birlikte bulunur:

- Bir kişi bardağı ağzına götürmüş içiyor; diğer görüntüde bardak elinde ama içmiyor.
- Bir kişi oturuyor; diğerinde oturmaya çok yakın bir pozda ama oturmuyor.
- Bir kişi kitabı okuyor; diğerinde kitap elinde ama başka yöne bakıyor, okumuyor.

"Subtle" burada eylemi belirleyen farkın küçük ve belirgin olmayan ayrıntılarda olması anlamındadır. Mevcut veri setlerinde eğitilmiş bir model iki kitaplı görüntünün ikisini de "kitap okuyor" diye etiketler; amaç bu iki durumu ayırabilmektir.

### 2.3 Yanlılık (Bias) ve Alan Kayması

Sunumda veri setlerindeki yanlılık sorunu da ele alındı. Makale mevcut veri setlerini "kontrolsüz", kendi veri setini mümkün olduğunca "kontrollü" (yanlılığı azaltılmış) olarak nitelendiriyor. Örnekler:

- Eğitim görüntülerinde insanlar yazlık kıyafetli ve ağaçlar yeşilse, test görüntülerinde kalın kıyafetler ve kar varsa model zorlanır.
- MNIST ile eğitilip yine MNIST ile test edilen el yazısı rakam tanıma modeli yaklaşık %99 başarı verir; başka bir el yazısı veri setiyle test edildiğinde başarı düşer.

Bu tür durumlara alan kayması (domain shift) da denir. Nedenleri arasında eğitim ve test görüntülerinin farklı dağılımlardan, farklı zaman ve kaynaklardan gelmesi ve ayırt edici özelliklerin eksikliği sayıldı. Sunumda sayılan çözüm yolları: farklı CNN modelleri, normalleştirme, ince ayar (fine-tuning), veri artırma, sözde etiketleme (pseudo-labeling; test kümesinde güvenle tahmin edilen örnekleri etiketli kabul edip yeniden eğitime katmak) ve ayrı bir araştırma konusu olan alan uyarlaması (domain adaptation).

### 2.4 Kullanılan Kavram ve Araçlar

**Anahtar noktalar (keypoints).** Aktiviteyi belirlemek için önce kişinin vücut duruşu, yani vücuttaki temel noktalar bulunmalıdır (ekrandan, 00:25:00). Bazı veri setlerinde 14, bu çalışmada kullanılan veri setinde 17 nokta vardır: burun, sol ve sağ göz, sol ve sağ kulak, sol ve sağ omuz, sol ve sağ dirsek, sol ve sağ bilek, sol ve sağ kalça, sol ve sağ diz, sol ve sağ ayak bileği. Yüz, el, avuç içi, ayak gibi görevler için ayrı özel anahtar noktalar tanımlanabilir. Slaytta anahtar noktaların döndürme ve ölçekleme gibi işlemlerden etkilenmediği yazıyordu.

> **Ders sonrası not:** Sunumda anahtar noktaların döndürme ve ölçeklemeden etkilenmediği söylendi. Noktaların görüntüdeki konumları bu dönüşümlerle değişir; kastedilen büyük olasılıkla, hangi noktanın hangi eklem olduğunun (noktanın kimliğinin) değişmemesidir.

**Detectron.** Facebook'un açık kaynaklı nesne tespiti kütüphanesidir. RPN, Mask R-CNN, Fast R-CNN gibi algoritmaları ve ResNet, FPN, VGG-16 gibi omurga (backbone) mimarilerini içerir. Çalışmada anahtar nokta ve nesne özniteliklerini çıkarmak için kullanıldı.

**Amazon Mechanical Turk.** Ücretli katılımcıların bulunduğu bir platformdur. Elinizdeki veri setini etiketletmek ya da insanlara test ettirmek için görev açarsınız, katılımcı sayısını ve niteliklerini seçersiniz.

**Mevcut veri setleri.** Omurga modellerin eğitimi için ImageNet, insan ve aktivite tespiti için COCO kullanılmıştır; aktivite tanıma için birkaç başka veri setine (ör. pose track) de başvurulmuştur.

### 2.5 Yeni Veri Setinin Oluşturulması

Veri setinde üç eylem vardır: içme, okuma, oturma. Her biri ayrı bir alt küme ve ikili (evet/hayır) bir sınıflandırma problemidir; yani üç ikili problem, toplamda altı sınıf gibi düşünülebilir.

Etiketleme kuralı (ekrandan, 00:30:00): her görüntüyü üç katılımcı süre sınırı olmadan etiketlemiş, yalnızca üçünün de aynı etiketi verdiği görüntüler veri setine alınmıştır. Eylemin tanımı katıdır:

- "İçiyor" sayılması için bardağın ağızda olması gerekir.
- "Okuyor" sayılması için kitabın elde olması ve bakışın kitaba yönelmesi gerekir; kitap elde ama bakış hafif yana kaymışsa "okumuyor" sayılır.

Ardından veri seti, derin öğrenme modellerinin kolayca çözemeyeceği hale getirilmiştir. İnce ayarlanmış AlexNet ile %80 eğitim, %20 test ayrımıyla sınıflandırma yapılmış; en kolay sınıflanan görüntüler (her turda en başarılı yaklaşık %10'luk dilim) atılmıştır. Bu işlem, modelin başarısı şans düzeyine (%50) inene kadar tekrarlanmıştır; örneğin okuma alt kümesinde birkaç tur sürmüştür. İnternetten toplanan görüntülerde de SVM ile çok yüksek doğrulukla sınıflanan görüntüler alınmamıştır.

<!-- BELİRSİZ: Eleme turlarının sayısı (okuma için 4 mü 5 mi) ve başlangıç doğruluğu altyazıda karışık anlatıldı; ilgili slaytın karesi yok. -->

### 2.6 Psikofizik Değerlendirme: İnsanlar Ne Kadar Başarılı?

İnsanların bu veri setindeki başarısı Amazon Mechanical Turk üzerinden 54 katılımcıyla ölçülmüştür. Deney akışı şöyledir:

1. Ekranda 500 ms boyunca boş bir ekran (sabitleme) gösterilir.
2. Görüntü rastgele seçilen bir süre boyunca gösterilir: 50, 150, 400 ya da 800 ms (ekrandan, 00:35:00).
3. Görüntü kapanır; katılımcı süre sınırı olmadan evet/hayır yanıtı verir.
4. Sonraki görüntüye geçilir.

Sonuç grafiğine göre insanlar 50 ms'lik gösterimde bile şans düzeyinin çok üstündedir: içme için yaklaşık %72, okuma için yaklaşık %78, oturma için yaklaşık %80. 800 ms'de üç eylemde de yaklaşık %90 ve üzerine çıkılır (ekrandan, 00:35:00; değerler grafikten okunmuştur). Ağızda bardak olup olmadığı gibi küçük bir ayrıntıyı 50 ms'de yakalamak zordur, buna rağmen insanlar yüksek başarı gösterir. Yazarın sinirbilim kökeni burada belirleyicidir: amaç insan ile makinenin tepkisini karşılaştırmaktır.

> **Hocanın vurgusu:** Bu tür ikili problemlerde rastgele bir sınıflandırıcı (chance classifier) zaten %50 başarı verir; yazı tura atmak da %50'dir. Grafikte %50'nin altında kalan yöntemler çok kötü yöntemlerdir; bir yöntemin en az bu düzeyi geçmesi beklenir.

### 2.7 Mevcut Modellerle Sınıflandırma

AlexNet ve benzeri mevcut CNN'ler ince ayarlanmıştır: ImageNet için 1000 sınıflı olan son tam bağlantılı katman kaldırılıp yerine iki sınıflı bir çıkış konmuştur. Her eylem için ayrı bir ikili model eğitilir. Renkli görüntü kullanma, veri artırma ve ince ayar gibi iyileştirmeler denenmiş, ancak başarı çok değişmemiştir; bütün modeller insan başarısının çok altında kalmıştır.

Modellerin nereye baktığı ısı haritalarıyla görselleştirilmiştir. Kırmızı bölgeler modelin odaklandığı yerlerdir. Yorum şudur: model çoğu zaman doğru bölgeye (ağız, el, kitap) odaklanıyor, ama yine de yanlış karar veriyor.

### 2.8 Önerilen Model

Önerilen yaklaşım insanın bir eylemi nasıl sınıflandırdığından esinlenir: hem nesneye hem de insan ile nesne arasındaki ilişkiye bakılır. İki kol vardır:

- **Anahtar nokta kolu:** kişinin anahtar noktaları (göz, kulak gibi birkaç nokta) çıkarılır.
- **Nesne kolu:** ilgili nesnenin (örneğin kitap) sınırlayıcı kutusu ve bu kutudaki öznitelikler çıkarılır.

Öznitelikler Detectron içindeki Mask R-CNN yapılandırmalarıyla elde edilmiş, sınıflandırma SVM ve yapay sinir ağı (YSA) ile yapılmıştır. Sonuç grafiğinde (ekrandan, 00:40:00) içme için anahtar nokta, öznitelik ve ikisinin birleşimi yaklaşık %53, %57 ve %55; okuma için yaklaşık %63, %56, %56; oturma için yaklaşık %56, %77, %75 düzeyindedir (değerler grafikten okunmuştur). İnsanlar aynı grafikte 50 ms'de yaklaşık %72-80, 800 ms'de yaklaşık %90-94'tür. Grafiğin açıklamasında da belirtildiği gibi hiçbir model insan düzeyine ulaşamamıştır.

Sonuç olarak makale, sınıflandırılması zor ve kontrollü bir veri seti sunmakta, daha iyi modellerin geliştirilmesini hedeflemekte ve insanların bu görevde makinelerden çok daha başarılı olduğunu göstermektedir.

## 3. MEVA: Çok Görüşlü ve Çok Kipli Etkinlik Tespiti Veri Seti

İkinci sunum da hareket/etkinlik algılama üzerineydi, ancak bu kez video veri setleri ele alındı. Çalışmanın yazarları ABD'de bilgisayarla görme üzerine çalışan bir teknoloji şirketindendir (Kitware). Amaçları en düşük maliyetle, en yüksek kalitede ve en geniş kapsamlı etkinlik tespiti video veri setini hazırlamaktır.

### 3.1 Genel Özellikler

Slayta göre MEVA (ekrandan, 00:45:00):

- Etkinlik tespiti (activity detection) için bir veri setidir.
- Görüş açısı ve sensör çeşitliliği yüksektir.
- Senaryolu (scripted) ve senaryosuz (unscripted) etkinlikler içerir.
- 9300 saatten fazla yer kamerası videosu vardır.
- 42 saat İHA (insansız hava aracı) videosu vardır.
- Üç milyondan fazla GPS iz noktası vardır.

İHA videoları ve GPS izleri, çekim yapılan alanın haritası üzerinde kişilerin izlediği yolları göstermek için kullanılmıştır; sunumun asıl konusu yer kameralarıdır. Toplam veri yaklaşık 2 TB'tır ve üç parçaya bölünmüştür (her biri 600-650 GB civarı); Amazon'un bulut hizmeti üzerinden ücretsiz indirilebilir.

### 3.2 Kayıt Alanı ve Kameralar

Çeşitliliği artırmak için açık alanlar, spor salonu, tiyatro salonu, kantin önü, küçük alışveriş alanları gibi farklı mekânlar kullanılmıştır. Aynı yer farklı açılardan, gölgede ve güneşte, gündüz ve akşam, kar ve kış koşullarında çekilmiştir. Kameralar üç türdür:

- **Sabit kameralar:** yalnız tek bir açıya bakar.
- **Sabit konumlu PTZ kameralar:** dönmeden yakınlaşıp uzaklaşabilir (örneğin bir aracın plakasına kadar yakınlaşıp geri çekilir).
- **Devriye (patrol) kameralar:** hem döner hem yakınlaşır; birden fazla bölgeye sırayla bakar, ışık açısı da değiştiği için farklı türde görüntü kaydeder.

Sensörler: güvenlik kameraları, kızılötesi kameralar, İHA kameraları, kişinin üzerine ya da çantasına takılan aksiyon kameraları (GoPro gibi).

### 3.3 Diğer Veri Setleriyle Karşılaştırma

Slayttaki karşılaştırma tablosu (ekrandan, 00:50:00):

| Özellik | VIRAT | UCF-101 Untrimmed | Duke MTMC | UCF-Crimes | MEVA |
|---|---|---|---|---|---|
| Etkinlik türü sayısı | 23 | 101 | - | 13 | 37 |
| Tür başına örnek | 10-1500 | 90-170 | - | 50-150 | 5-750 (1200) |
| Rastlantısal nesne ve etkinlik | evet | hayır | evet | evet | evet |
| Doğal arka plan davranışı | evet | hayır | evet | evet | evet |
| Sıkı sınırlayıcı kutular | evet | hayır | hayır | hayır | evet |
| En yüksek çözünürlük | 1920x1080 | 320x240 | 1920x1080 | 320x240 | 1920x1080 |
| Sensör kipi sayısı | 1 | 1 | 1 | 2 | 5 |
| Güvenlik kamerası | evet | hayır | evet | evet | evet |
| Görüş alanı (FOV) sayısı | 17 | klip başına | 8 | klip başına | 28 |
| Örtüşen görüş alanı | hayır | hayır | evet | hayır | evet |
| İç ve dış mekân | hayır | evet | hayır | evet | evet |
| Erişim | doğrudan | referans | geri çekildi | doğrudan | doğrudan |
| Klip uzunluğu | 2-3 dk | 1-71 sn | - | 4 dk | 5 dk |
| Süre (saat) | 29 | 26.6 | 10 | 128 | 9300 / 144 |

MEVA'yı öne çıkaran özellikler çok uzun toplam süre, 28 farklı görüş alanı ve 5 sensör kipidir.

### 3.4 Etkinliklerin Kurgulanması (Scripting)

Etkinlikler insan-insan, insan-araç ve araç-araç gibi ikili ve üçlü bütün ilişki türlerini kapsayacak biçimde kurgulanmıştır. 9300 saatlik kayıtta bile bazı davranışlar kendiliğinden ortaya çıkmayabileceği için profesyonel oyuncular kiralanmış ve onlar için senaryolar yazılmıştır.

İki yaklaşım denenmiştir (ekrandan, 00:55:00):

- **Bireysel senaryo (başarısız):** herkese ayrı bir senaryo verilmiştir. Kişiler bir görevi uzun sürdükten sonra ikinci göreve telaşla geçmiş, hareketler yapmacıklaşmış ve doğallıktan uzaklaşmıştır. Bu, veri setiyle eğitilen modellerin başarısını düşürür.
- **Grup başına tek oyuncu (başarılı):** her grubun başına senaryoyu izleyen bir oyuncu konmuştur. Gruptaki diğer kişiler oyuncuyla birlikte hareket eder ama kendi aralarında konuşmak gibi doğal davranışlarını sürdürür. Örneğin oyuncuya "kantinden bir şey al" görevi verilmişse grup da onunla gider.

### 3.5 Etiketleme (Annotation)

Etiketlemede iki temel ölçüt kalite ve maliyettir. Çok titiz bir etiketleme yüksek kalite sağlar ama maliyeti çok artırır; yalnız denetim aşamasının bile yaklaşık iki ay sürdüğü belirtilmiştir. Bu yüzden ikisi dengelenmeye çalışılmıştır. Etiketleme iki kısma ayrılmıştır: etkinlik etiketleme ve kişinin kameralar arasında izlenmesi (track annotation).

Slayttaki çok adımlı süreç (ekrandan, 01:00:00):

1. Etkinliklerin ve ilgili nesnelerin zaman sınırlarını belirleyen bir etiketleme adımı.
2. Etkinlik etiketlerinin eksiksizliğini ve doğruluğunu sağlamak için uzmanların yaptığı bir denetim (audit) adımı.
3. Nesneler için sınırlayıcı kutu izlerinin kitle kaynaklı (crowdsourced) yöntemle oluşturulması.
4. Köşe durumlarının (corner cases) uzmanlarca hızla düzeltilmesi için özel bir arayüz; adımlar arasında sık yapılan insan hatalarının otomatik kontrolü.

Videolar beşer dakikalık parçalara bölünerek işlenmiştir. Üç zorluk vurgulanmıştır: farklı açılardan çekilen kişinin izlenmesi, etiketlerin tutarlılığı ve ölçek değişimi. Slayttaki örnekte aynı kişi dört farklı görüş alanında sırasıyla 301, 118, 176 ve 89 piksel boyunda görünür. Köşe durumlarına örnek olarak uzaktaki bir kişinin yakındaki kameradaki kişiyle aynı olduğunun anlaşılması ve kişi bir nesnenin arkasından geçtiğinde izin korunması verildi.

Sunumda gösterilen kısa videoda bisiklet süren kişi için hem bisikletin hem kişinin algılandığı ve "bisiklet sürüyor" etiketi, bir sandalyenin alınıp taşınması, bardak alışverişi ve araçtan inen kişinin daha inmeden "araçtan iniyor" diye etiketlenmesi görüldü. Bu son durum etiketlemenin en zor kısımlarından biri olarak anlatıldı.

### 3.6 Sonuç

Makalede, ilgili bir değerlendirmede hata oranının %5'in altına indiği iddia edilmektedir; önceki veri setlerinde en iyi değer %12-13 civarındadır. Sunumu yapan öğrenci, bu iddiaya ait eğrinin grafikte çizilmediğini belirtti. Veri setinin yer kamerası kısmı herkese açılmıştır; İHA kısmı açılmamıştır.

<!-- BELİRSİZ: %5 ve %12-13 değerlerinin hangi ölçüte ait olduğu altyazıda net değil; grafiğin karesi yok. -->

> **Hocanın vurgusu:** Büyük video veri setlerini etiketlemek çok uzun saatler ve ciddi emek isteyen bir iştir. Bu tür çalışmalar büyük ekipler ve büyük finansal kaynaklarla yapılır; sensör çeşitliliği açısından da bu çalışma dikkat çekicidir.

## 4. Üretken Model Ters Çevirme Saldırısı (GMI)

Üçüncü sunumda derin sinir ağlarına karşı geliştirilmiş, eğitim verisini geri elde etmeye yönelik bir saldırı anlatıldı. Bu çalışma da CVPR 2020'de yayımlanmıştır.

> **Ek bilgi (derste anlatılmadı):** Makale büyük olasılıkla "The Secret Revealer: Generative Model-Inversion Attacks Against Deep Neural Networks" başlıklı çalışmadır.

### 4.1 Derin Sinir Ağları ve Güvenlik

Derin sinir ağları bir ya da daha fazla gizli katmanı olan yapay sinir ağlarıdır; bilgisayarla görme, konuşma tanıma ve sağlık hizmetleri gibi pek çok alanda kullanılır. Kullanıldıkça güvenlik endişesi doğmuştur, çünkü eğitimde kullanılan veriler mahrem olabilir ve kötü niyetli birinin eline geçmesi ciddi sonuçlar doğurabilir. Veri ele geçirme saldırılarından biri model ters çevirme saldırısıdır (model inversion attack).

### 4.2 Model Ters Çevirme Saldırısı

Saldırının bileşenleri (ekrandan, 01:20:00):

- **Hedef model (target model):** verisi elde edilmek istenen, saldırının yapıldığı eğitilmiş model.
- **Hedef etiket (target label):** geri kazanılmak istenen sınıf, örneğin bir kişinin kimliği.
- **Yardımcı bilgi (auxiliary knowledge):** varsa bozuk, bulanıklaştırılmış ya da maskelenmiş bir görüntü veya açık bir veri uzayı.
- **Çıktı:** geri kazanılan öznitelik, örneğin hedef kişinin yüz görüntüsü.

Saldırı, hassas özellikler ile model çıktıları arasındaki ilişkiden yararlanarak hassas veriyi yeniden üretmeye çalışır.

Model ters çevirme saldırıları ilk kez Fredrikson ve arkadaşları tarafından ele alınmıştır (ekrandan, 01:25:00). Bu çalışmada hastanın genotipine ve geçmişine dayanarak kişiye özel ilaç dozu öneren bir doğrusal regresyon modeli incelenmiştir. Saldırganın model ve hasta hakkında bazı demografik bilgilere sahip olduğunda hastanın genetik belirteçlerini tahmin edebildiği görülmüştür.

Bunu önlemek için diferansiyel gizlilik (differential privacy) kullanılmıştır. Diferansiyel gizlilik, model çıktısı ile tek tek kayıtlar arasındaki ilişkiyi anonimleştirir. Sunumdaki benzetme: bir kreşteki aşçı için hangi çocuğun bir yemeği sevmediği değil, kaç çocuğun sevmediği önemlidir. Verilerin ne kadarının kullanılacağını sınırlayan bir mahremiyet bütçesi (privacy budget) vardır. Çalışmada bütçe ayarlanarak saldırı önlenmiş, ancak bu kez modelin ilaç dozu önerilerinde felç, kanama, ölüm gibi tehlikelerin olasılığı artmıştır. Yani diferansiyel gizlilik genomik mahremiyeti sağlarken klinik etkinliği koruyamamıştır.

### 4.3 Derin Ağlarda Neden Zor?

Doğrusal regresyon gibi basit modellerde ve küçük veri uzaylarında ters çevirme daha başarılıdır. Derin ağlarda ise:

- Yapı karmaşık ve doğrusal değildir; ters çevirme bir optimizasyon problemine dönüşür.
- Gradyan inişi kolayca yerel minimuma takılır.
- Yüksek boyutlu görüntü uzayında doğrudan optimizasyon anlamsız, gerçekten uzak görüntüler üretir ve saldırı başarısız olur.

GMI bu sorunu bir GAN ile çözer: aramayı piksel uzayında değil, açık veriyle eğitilmiş bir GAN'ın üreteç uzayında yapar.

### 4.4 GAN'ın Temelleri

GAN, aynı türde yeni örnekler üretebilen ve iki sinir ağından oluşan bir yapıdır:

- **Üreteç (generator):** gerçeğe benzeyen yeni veriler üretir.
- **Ayırt edici (discriminator):** gelen görüntünün gerçek olma olasılığını hesaplar; gerçekse 1, sahteyse 0 vermesi beklenir.

Ayırt edicinin verdiği olasılık ile olması gereken değer arasındaki fark kayıptır. Sunumdaki sayısal örnek:

- Gerçek bir görüntüye 0.7 verilirse, olması gereken 1 olduğundan hata $1 - 0.7 = 0.3$'tür.
- Sahte bir görüntüye 0.7 verilirse, olması gereken 0 olduğundan hata $0.7 - 0 = 0.7$'dir.
- Üreteç ise ürettiği görüntünün 1 olarak değerlendirilmesini ister. Ayırt edici sahte görüntüye 0.6 verdiyse üretecin hatası $1 - 0.6 = 0.4$'tür (ara adım eklendi: altyazıda yalnız 0.4'lük hata söylendi).

Her yinelemede bu hatalar sıfıra yaklaştırılacak şekilde iki ağ güncellenir.

### 4.5 GMI'nin Yapısı

Saldırı iki aşamalıdır (ekrandan, 01:25:00):

- **Birinci aşama:** açık veri üzerinde bir GAN eğitilir. Eğitim amacı GAN kaybı ile çeşitlilik (diversity) kaybının toplamıdır. Hedef ağ (bu çalışmada bir yüz tanıma modeli) bu aşamada sabittir. Açık veri hedef kişileri içermez, ama GAN'a "bir yüz nasıl görünür" konusunda geniş bir önbilgi kazandırır; bu önbilgi kötü koşullu ters çevirme problemini düzenler.
- **İkinci aşama:** üreteç ve ayırt edici sabit tutulur, yalnız gizli vektör $z$ güncellenir. Üretilen görüntü hedef ağa sorulur ve hedef etiketle eşleşip eşleşmediğine bakılır. Varsa bulanık ya da maskelenmiş görüntü de yardımcı bilgi olarak kullanılır.

Kullanılan formüller (ekrandan, 01:30:00):

GAN kaybı (Wasserstein biçiminde):

$$\min_G \max_D L_{wgan}(G,D) = E_x[D(x)] - E_z[D(G(z))]$$

Burada $D(x)$ ayırt edicinin gerçek görüntüye verdiği değer, $D(G(z))$ ise $z$ uzayından üretilen görüntüye verdiği değerdir. Üreteç bu ifadeyi en küçüklerken ayırt edici en büyükler.

Çeşitlilik kaybı:

$$\max_G L_{div}(G) = E_{z_1,z_2}\left[\frac{\lVert F(G(z_1)) - F(G(z_2))\rVert}{\lVert z_1 - z_2\rVert}\right]$$

Üreteç ne kadar çeşitli görüntü üretirse hedefte o kadar başarılı olunur; hep aynı görüntüler üretilirse başarı düşer.

Saldırının hedefi (bilgi özütü):

$$\hat{z} = \arg\min_z L_{prior}(z) + \lambda_i L_{id}(z)$$

$$L_{prior}(z) = -D(G(z)), \qquad L_{id}(z) = -\log C(G(z))$$

$L_{prior}$ gerçekçi olmayan görüntüleri cezalandırır. $L_{id}$ (kimlik kaybı), üretilen görüntünün hedef ağ altında hedef sınıfa yüksek olasılıkla atanmasını sağlar; $C(G(z))$, hedef ağın $G(z)$ için verdiği olasılıktır. Saldırının başarılı sayılması için bu iki kaybın sıfıra yaklaşacak biçimde $z$'nin güncellenmesi gerekir.

Hassas özelliğin tahmin gücü, belirli bir $y$ sınıfı ve hassas olmayan $x_{ns}$ özelliği verildiğinde:

$$U_f(x_{ns}, y) = E_{X_s \sim p(X_s|y,x_{ns})}\left[\log p_f(y|X_s, x_{ns}) - \log p_f(y|x_{ns})\right]$$

Yani hassas özellik $X_s$ eklendiğinde modelin doğru sınıfa verdiği log olasılığın ne kadar arttığı ölçülür.

### 4.6 Deney Düzeni ve Sonuçlar

Veri setleri MNIST (el yazısı rakamlar), ChestX-ray8 (tıbbi göğüs röntgeni) ve CelebA'dır (ünlü yüzleri). Her veri seti için ayrı modeller kullanılmış, verinin %90'ı eğitim, %10'u test için ayrılmıştır. Değerlendirme ölçütleri PSNR, saldırı doğruluğu (attack accuracy), öznitelik uzaklığı (feature distance) ve KNN uzaklığıdır.

Karşılaştırılan yöntemler:

- **EMI:** geleneksel model ters çevirme.
- **PII:** görüntü içi boyama (inpainting) ile görüntü üretme. Klasik boyamada sentezlenen piksellerin belirli bir kimlikle tutarlı olup olmadığı önemsenmez; GMI'de kimlik eşleşmesi gözetilir.
- **GMI:** önerilen yöntem.

Görsel sonuçlarda EMI anlamsız görüntüler üretir, PII daha net bir yüz oluşturur ama hedefle eşleşmez, GMI hedefe en yakın görüntüyü üretir.

Bulanık ve maskelenmiş görüntülerde saldırı doğruluğu (ekrandan, 01:35:00):

| Hedef model | Bulanık: EMI / PII / GMI | Merkez maske: EMI / PII / GMI | Yüz T maske: EMI / PII / GMI |
|---|---|---|---|
| VGG16 | %0 / %6 / %43 | %14 / %34 / %78 | %11 / %20 / %58 |
| ResNet-152 | %1 / %6 / %50 | %9 / %34 / %80 | %11 / %20 / %63 |
| face.evoLVe | %1 / %6 / %51 | %12 / %34 / %82 | %11 / %20 / %64 |

Aynı tabloda PSNR değerlerinde de GMI en yüksektir; örneğin VGG16 ve merkez maskede EMI 18.69, PII 25.49, GMI 27.58'dir. Yardımcı bilgi olmadan da EMI ve PII'nin saldırı doğruluğu sıfıra yakındır; sunumda GMI'nin ilk 5 (top-5) saldırı doğruluğunun yaklaşık %53'e ulaştığı söylendi.

Açık verinin saldırı doğruluğuna etkisi (ekrandan, 01:35:00):

| Model | CelebA→CelebA 1:1 | 1:4 | 1:6 | 1:10 | PubFig83→CelebA ön işlemsiz | ön işlemli | EMI |
|---|---|---|---|---|---|---|---|
| VGG | %78 | %77 | %75 | %72 | %48 | %67 | %14 |
| LeNet | %81 | %75 | %77 | %75 | %52 | %66 | %9 |
| face.evoLVe | %77 | %77 | %77 | %70 | %56 | %70 | %12 |

Açık verinin tamamı kullanıldığında (1:1) doğruluk yüksektir; açık veri azaldıkça düşer. PubFig83 veri setinde gözlüklü ve yüzü örtülü görüntüler daha fazla olduğu için, CelebA'ya aktarımda doğruluk düşer; ön işlem bu düşüşü kısmen telafi eder. Maskelenmiş görüntülerde sarışınlık, gür kaş, gözlük, cinsiyet, bıyık, gençlik gibi özelliklerin geri kazanılmasında da GMI diğer iki yöntemden belirgin şekilde üstündür.

Hoca, böyle bir çalışmanın hiç akla gelmeyecek kadar ilginç bir konu olduğunu söyledi.

## 5. Metin Tanımada Öğrenilebilir Veri Artırma

Dördüncü sunumun konusu metin tanımada (text recognition) veri artırma yöntemleriydi.

> **Ek bilgi (derste anlatılmadı):** Makale büyük olasılıkla "Learn to Augment: Joint Data Augmentation and Network Optimization for Text Recognition" (CVPR 2020) başlıklı çalışmadır.

### 5.1 Problem

İki metin türü vardır:

- **Sahne metni (scene text):** tabela, levha gibi fotoğraflarda görülen, daha düzenli yazılmış metin. Ekrandaki örnekte "Safety" yazısı.
- **El yazısı metin (handwritten text):** el ile yazılmış metinlerin görüntüleri.

Ayrıca düzenli (regular) ve düzensiz (irregular) metin ayrımı vardır (ekrandan, 01:40:00). Düzenli metinde harfler aynı yazı tipinde ve aynı boyuttadır. Düzensiz metinde bazı harfler büyük bazıları küçüktür, yazı kavislidir ya da perspektif bozulması vardır.

Tek bir harfi (MNIST'teki rakamlar gibi) tanımak görece kolaydır; bütün bir yazıyı tanımak daha karmaşıktır ve model başarısını artırmak çok büyük veri gerektirir. Bu da maliyeti artırır. Veri artırma maliyeti düşürüp başarıyı artırmak için kullanılır. Klasik veri artırma görüntüyü döndürme, küçültme ya da kaydırmaya dayanır; ancak gerçek hayattaki metin bozulmaları bunlardan farklıdır.

### 5.2 Kontrol Noktalarıyla Metin Bükme

Yöntem şöyle çalışır (ekrandan, 01:50:00):

1. Metin görüntüsü $N$ parçaya (patch) bölünür. Slayttaki örnekte $N = 3$'tür.
2. Parça sınırlarında kırmızı kontrol noktaları seçilir.
3. Her kontrol noktası, yarıçapı $R$ olan bir daire içinde belirli bir dağılıma göre rastgele kaydırılır. Örnekte $R = 10$'dur.
4. Görüntü yeni kontrol noktalarına göre bükülür ve artırılmış görüntüler elde edilir; bazı bölgeler küçülür, bazıları büyür.

Bu artırma türleri bükme (distort), germe (stretch) ve perspektiftir. Sunumdaki demoda perspektif artırmada metne kavis verildiği, germede boyutun rastgele küçültülüp büyütüldüğü, bükmede harflerin eğiminin bölgesel olarak değiştirildiği gösterildi.

### 5.3 Öğrenilebilir Ajan

Asıl yenilik, artırmanın rastgele değil öğrenilerek yapılmasıdır. Akış:

1. Rastgele bir artırma uygulanır.
2. Artırılmış görüntü tanıyıcıya (recognizer) verilir ve tanıma kaybı kaydedilir.
3. Bir ajan ağı (learnable agent), farklı artırmaların kayıplarını karşılaştırır. Kaybı daha çok artıran, yani tanıyıcı için daha zor olan artırmaları öğrenir.
4. Tanıyıcı bu zor örneklerle eğitilir; böylece daha sağlam hale gelir.

Süreç, doğru artırma politikası elde edilene kadar sürer. Sunumda ajan ağında evrişim katmanları ve 2x2 ortalama havuzlama kullanıldığı söylendi. Ajan, yarıçap $R$'nin uygun büyüklüğünü ayarlamaya da çalışır.

<!-- BELİRSİZ: Sunumda ajanın bir "RNN" modeli olduğu da söylendi ve sentetik veri setlerinde başarının artırmayla 63'e, ajanla birlikte 66.5'e çıktığı belirtildi; ilgili tablonun karesi yok. -->

### 5.4 Sonuçlar

Düzensiz metinde kelime doğruluğu (ekrandan, 01:45:00):

| Yöntem | SVT-P | CT80 | IC15 |
|---|---|---|---|
| Temel model (ASTER) | 77.7 | 79.9 | 75.8 |
| + Önerilen artırma | 79.2 | 84.4 | 76.1 |

Artışlar sırasıyla 1.5, 4.5 ve 0.3 puandır (python ile hesaplandı). Önerilen yöntem tabloda yer alan diğer çalışmaların sonuçlarını da geçmektedir. Aynı slaytta artırılmış sahne metni ve el yazısı örnekleri gösterildi.

El yazısı veri setleri (IAM gibi) üzerinde başarı WER ve CER ile ölçülmüştür:

- **WER (Word Error Rate):** kelime hata oranı.
- **CER (Character Error Rate):** karakter hata oranı.

Önerilen yöntem bu hata oranlarını belirgin şekilde düşürmüş, başka bir grubun geliştirdiği AFDM adlı artırma yönteminden de daha iyi sonuç vermiştir.

Hoca bu çalışmanın, veri artırmayı öğrenilebilir bir yapıya dönüştürmesi bakımından ilginç olduğunu, birkaç puanlık iyileşmenin de en iyi sonuçlar (state of the art) düzeyinde elde edildiğini söyledi.

## 6. Bağlam R-CNN: Statik Kameralarda Uzun Süreli Zamansal Bağlam

Beşinci sunumda, kamera başına nesne tespiti için uzun süreli zamansal bağlamı kullanan Bağlam R-CNN (Context R-CNN) modeli anlatıldı. Çalışma Google ekibine aittir ve CVPR 2020'de yayımlanmıştır. Çalışma, doğal dil işlemede yaygın olan bağlam ve dikkat mekanizması fikirlerini nesne tespitine taşır.

### 6.1 Statik İzleme Kameraları ve Zorlukları

Statik izleme kameraları özellikle ekolojik izleme için önemlidir: araştırmacılar biyoçeşitliliği ölçmek, korumak, iklim değişikliğinin ve insan faaliyetlerinin ekosistemlere etkisini anlamak için doğal alanlara kamera yerleştirir. Bu kameralardan gelen verinin otomatik sınıflandırılması ve bölütlenmesi makine öğrenmesinin işidir. Ancak bu veri bazı zorluklar taşır:

- **Depolama ve düzensiz örnekleme:** kamera aylarca kayıt yapar. Depolamayı azaltmak için sahnede ilgilenilen bir nesne varsa yüksek, yoksa düşük örnekleme yapılır. Örneğin altı saat boyunca yalnız arka plan, sonra 30-40 saniye bir hayvan, sonra yine saatlerce boş sahne görülür.
- **Boş görüntüler:** bazı kamera tuzağı veri setlerinde görüntülerin yaklaşık %75'i boştur.
- **Kötü kadraj:** görüntüleri bir fotoğrafçı çekmediği için nesnenin ortalanacağı, odakta, iyi aydınlatılmış ya da uygun ölçekte olacağı garanti değildir.
- **Tekrar:** hayvanlar belirli hareketleri düzenli tekrarladığı için çok benzer görüntüler oluşur; aralarında bir buçuk ay ya da üç gün olan iki görüntü neredeyse aynı olabilir. Bu da modelin arka plana aşırı uyum sağlamasına (arka plan korelasyonlarına odaklanmasına) yol açar.

Öte yandan bu tekrar bir fırsattır: özneler günlerce benzer davranır, arka plan nesneleri sabittir, hayvanlar grup davranışı sergiler. Yani bağlam çok güçlüdür.

Slayttaki örnek (ekrandan, 02:00:00): yoğun sisli bir karede insan bile bir nesne göremez ve bunu arka plan görüntüsü sayar. Ama aynı kameranın birkaç gün önce ve sonraki görüntüleri kullanılırsa sisteki nesnenin bir antilop (görüntüde bir antilop türü) olduğu anlaşılır.

### 6.2 Amaç ve Veri Setleri

Amaç, çerçeve hızından ve örnekleme düzensizliğinden bağımsız olarak zamansal bağlamdan yararlanan, dikkat tabanlı bir nesne tespit modeli geliştirmektir. Kameralar sabit olduğu için eğitim ve test kümelerinde farklı kamera konumları kullanılarak model yanlılığı önlenmiştir.

Üç veri seti kullanılmıştır:

- **Snapshot Serengeti (kamera tuzağı):** eğitimde 245 kameradan 3.2 milyon görüntü, 48 sınıf; test için 45 konumda 64 bin görüntü.
- **Caltech Camera Traps (kamera tuzağı):** eğitimde 140 kameradan 243 bin görüntü, 18 sınıf; test için 40 konumda 62 bin görüntü.
- **CityCam (trafik kamerası):** kalabalık caddelerde çekilmiş, 17 kamera, 10 araç sınıfı, yaklaşık 60 bin çerçeve ve 900 bin etiketli nesne; 13 kamera eğitim, 4 kamera test için.

### 6.3 Faster R-CNN'in Hatırlatılması

Bağlam R-CNN, ResNet-101 tabanlı Faster R-CNN üzerine kurulmuştur. Faster R-CNN iki aşamalıdır:

1. **Bölge öneri ağı (Region Proposal Network, RPN):** görüntüde nesne olabilecek bölgeleri kutularla önerir; bu aşamada sınıf bilgisi yoktur.
2. **İkinci aşama:** önerilen kutulardan öznitelikler (ROI Align ile) çıkarılır ve her kutu arka plan ya da hedef sınıflardan biri olarak sınıflandırılır.

### 6.4 Bağlam R-CNN Mimarisi

Bağlam R-CNN, Faster R-CNN'in birinci aşaması ile ikinci aşaması arasına bir bağlam mekanizması yerleştirir (ekrandan, 02:05:00):

- Mevcut pencerede ana kare (keyframe) ve çevresindeki kareler birinci aşamadan geçirilir; kutu başına RPN öznitelikleri elde edilir.
- **Kısa süreli bellek ($M^{short}$):** mevcut penceredeki komşu karelerin özniteliklerinden oluşur; her görüntü için 3 çerçeve kullanılmıştır.
- **Uzun süreli bellek ($M^{long}$):** gelen görüntülerden doğrudan oluşturulmaz, çünkü uzun süreli hafıza oluşturmak zordur. COCO ile önceden eğitilmiş bir nesne dedektörünün öznitelikleri kullanılarak 8500'e kadar bağlamsal öznitelik içeren bir bellek bankası kurulur. Bu banka yaklaşık bir ay ve daha uzun süreli bağlam tutmayı sağlar.
- Ana kare öznitelikleri önce kısa süreli, sonra uzun süreli dikkat modülünden geçer; her modülün çıktısı ana kare özniteliklerine eklenir ve sonuç ikinci aşamaya verilir.

Bellek bankaları modülerdir: ikisi birlikte ya da ayrı ayrı kullanılabilir.

### 6.5 Dikkat Mekanizması

Dikkat mekanizması bellekteki her özniteliğin mevcut kareyle ne kadar ilgili olduğunu belirler ve benzerlik varsayımına dayanır. Adımlar:

1. Ana karede RPN'in önerdiği $n$ kutunun öznitelikleri havuzlama katmanından geçirilir; her kutu için sorgu (query), anahtar (key) ve değer (value) elde edilir.
2. Sorgu ile bellekten gelen özniteliklerin anahtarları arasında iç çarpım (dot product) alınır; bu, aralarındaki benzerliktir.
3. Benzerlikler softmax'tan geçirilerek olasılık tabanına indirgenir (değerlerin 1'i aşması önlenir).
4. Bu ağırlıklarla bellekten gelen değerler toplanır ve çıktı öznitelikleri $F^{context}$ elde edilir.

Sunumda $n$ ana karedeki kutu sayısı, $m$ karşılaştırma (bellek) özniteliklerinin sayısı, $d$ öznitelik derinliği olarak verildi; $d = 2048$'dir. Böylece $F^{context}$ boyutu $n \times 2048$ olur.

<!-- BELİRSİZ: Dikkat formülünün gösterildiği slaytın karesi yok; ağırlık matrisinin tam tanımı altyazıdan çıkarılamadı. -->

> **Ek bilgi (derste anlatılmadı):** Bu yapı genel ölçekli iç çarpım dikkatine karşılık gelir: sorgu matrisi $Q$, anahtar matrisi $K$ ve değer matrisi $V$ için çıktı $\text{softmax}(QK^T/T)\,V$ biçimindedir; $T$ bir ölçek (sıcaklık) katsayısıdır. Ayrıntılar büyük olasılıkla makalenin yöntem bölümündedir.

Slayttaki örnekte (ekrandan, 02:10:00) sisli bir ana kare için bağlamdaki sekiz görüntüye 0.03-0.04 arasında dikkat ağırlıkları verilmiş ve ikinci aşamada nesne "antilop, skor 0.942" olarak sınıflandırılmıştır.

Öğrenci, dikkat mekanizmasını tanıtan makalenin de Google ekibine ait olduğunu ve başlığının "dikkat ihtiyacınız olan tek şeydir" anlamına geldiğini hatırlattı.

### 6.6 Değerlendirme Ölçütleri

İki ölçüt kullanılmıştır: ortalama kesinlik değerlerinin ortalaması (mAP) ve ortalama geri çağırma (AR). Her ikisi de önceden belirlenmiş bir IoU eşiği ile hesaplanır. IoU (intersection over union), tahmin edilen kutu ile gerçek nesne kutusunun örtüşme düzeyidir; bu çalışmada eşik 0.5'tir.

### 6.7 Bulgular

Tek kare Faster R-CNN ile Bağlam R-CNN üç veri setinde karşılaştırılmıştır. Sunumda Bağlam R-CNN'in Caltech Camera Traps'te yaklaşık 19.5, Snapshot Serengeti'de 17.9, CityCam'de 4.5 puanlık mAP iyileştirmesi sağladığı söylendi. Geri çağırmada da iyileşme vardır ve iyileşme tek bir sınıfta değil neredeyse bütün sınıflara yayılmıştır.

Snapshot Serengeti üzerinde bellek varyasyonları (ekrandan, 02:15:00):

| Yöntem | mAP | AR |
|---|---|---|
| Tek çerçeve | 37.9 | 46.5 |
| Çoğunluk oylaması | 37.8 | 46.4 |
| Çevreleyen çerçeveler (ST Spatial) | 39.6 | 36.0 |
| S3D modeli | 44.7 | 46.0 |
| Tek çerçeve + dikkat | 44.9 | 50.2 |
| ST dikkat ($M^{short}$) | 46.4 | 55.3 |
| LT dikkat ($M^{long}$) | 55.6 | 57.5 |
| ST+LT dikkat | 55.9 | 58.3 |

> **Ders sonrası not:** Tabloda tek çerçeveden ST+LT dikkate fark $55.9 - 37.9 = 18.0$ puandır (python ile hesaplandı); sunumda söylenen 17.9 değeri büyük olasılıkla makalenin ana tablosundaki biraz farklı bir karşılaştırmadan gelir.

Tablodan çıkan sonuçlar:

- En iyi sonuç kısa ve uzun süreli belleğin birlikte kullanıldığı modelle elde edilir.
- Kısa süreli bellek kullanılmasa bile uzun süreli bellek ve dikkat ile neredeyse aynı sonuca ulaşılır (55.6'ya karşı 55.9).
- Hiç bellek kullanılmadan, yalnız tek kareye dikkat eklemek bile mAP'yi 37.9'dan 44.9'a çıkarır.

Örnek görüntülerde (mavi kutular iki modelin de bulduğu, yeşil kutular yalnız Bağlam R-CNN'in bulduğu nesneler):

- Yarısı kadrajın dışında kalan bir kamyonet tek kare modelince bulunamaz; Bağlam R-CNN bulur, çünkü belki iki saniye önce kamyonet kadrajın içindeydi.
- Ağacın arkasındaki bir fili tek kare modeli bulamaz, Bağlam R-CNN bulur.
- Yetersiz ışıkta da sonuçlar iyidir.
- Tek kare Faster R-CNN, arka plandaki araca benzer bir yapıyı araç sanar (kırmızı kutu); Bağlam R-CNN bağlamdan bunun arka plan olduğunu anlar.

Zaman aralığının etkisi incelendiğinde en iyi sonucun bir aylık bağlamla elde edildiği, ancak farkın çok büyük olmadığı görülmüştür. Arka plan kaynaklı yanlış sınıflanmış 100 örnek üzerinde yapılan testte Bağlam R-CNN neredeyse her eşik değerinde bu örnekleri doğru tespit etmiş, yalnız üç örneği yanlış sınıflamıştır; bu üç görüntüde sıra sıra uzun ağaçlar vardır ve model onları bir zürafa sürüsüne benzetmiştir.

### 6.8 Değerlendirme

Geliştirilen mimari esnektir ve herhangi bir statik izleme verisine uygulanabilir; bağlamsal öznitelik süresi arttıkça başarı artar. Model Google TPU'ları (8 TPU) üzerinde çalıştırılmıştır, ancak bellek kullanımı ve çalışma süresi hakkında veri verilmemiştir. Öğrenci, Transformer yapısında yineleme (recurrence) olmadığı için her hesaplamanın baştan yapıldığını, bu yüzden sürenin uzun olabileceğini; önceki veriyi önbellekte tutan Transformer-XL benzeri bir yaklaşımla hesaplama maliyetinin azaltılabileceğini önerdi.

Hoca, yazarların güzel bir problemi kendilerinin ortaya koyup çözümünü de önerdiğini, bu yüzden çalışmayı çok beğendiğini söyledi.

## 7. Ortak Belirgin Nesne Tespiti (CoSOD) ve CoSOD3k

Altıncı ve son sunumun konusu ortak belirgin nesne tespitiydi. Sunulan makale "Taking a Deeper Look at Co-Salient Object Detection" başlıklı çalışmadır.

### 7.1 Tanım

Belirgin nesne tespiti (Salient Object Detection, SOD), bir görüntüde göze en çok çarpan nesneyi bulup ayırma problemidir ve yaklaşık on yıldır çalışılan bir konudur. Ortak belirgin nesne tespiti (Co-Salient Object Detection, CoSOD) SOD'un bir alt dalıdır: bir grup görüntüde ortak olan belirgin nesneleri bulup ortamdan ayırır (ekrandan, 02:25:00).

Slayttaki örnekler:

- Tek bir görüntüde (a) çocuk belirgin nesnedir.
- Bir futbol görüntüsünde aynı takımın kırmızı formalı oyuncuları ayrılır; beyaz formalı rakip ve arka plandaki seyirciler maskeye girmez.
- İki farklı görüntüde jimnastik yapan sporcular ortak nesne olarak ayrılır.
- Çocuk, köpek ve top içeren farklı görüntülerde ortak nesne futbol topudur; sistem yalnız topu bölütler.

Sunumda bölütleme adımında Otsu eşiklemesinin kullanıldığı söylendi. <!-- BELİRSİZ: Otsu yönteminin hangi aşamada ve hangi yöntemde kullanıldığı altyazıdan net değil. -->

### 7.2 Önceki Veri Setleri ve Geleneksel Yöntemler

CoSOD veri setleri 2005'teki MSRC ile başlamış; iCoseg, THUR15K ve CoSal2015 gibi veri setleriyle devam etmiş, en yenisi 2020'de çıkan CoSOD3k olmuştur. Bu veri setleri grup sayısı, görüntü sayısı ve grup başına ortalama görüntü sayısı ile karşılaştırılır.

Geleneksel CoSOD yöntemleri hesaplamayı birimlere bölerek modellemiş; çoklu örnek öğrenme veya kendi kendine uyarlanan ağırlıklandırma gibi yollarla anlamsal nitelikleri yüksek seviyeli özelliklerle ifade etmiştir. Görüntüler arası kısıtları yakalamak için dönüşümsel hizalama, manifold sıralama ve global eşleşme gibi mekanizmalar araştırılmıştır.

### 7.3 CoSOD3k Veri Seti

- Görüntüler ILSVRC (ImageNet büyük ölçekli görsel tanıma yarışması) kategorilerinden yararlanılarak Flickr'dan toplanmıştır.
- 160 grup (kategori) ve toplam 3316 görüntü vardır. Ortalama grup başına $3316 / 160 \approx 20.7$, yani yaklaşık 21 görüntü düşer (python ile hesaplandı).
- 160 kategori önce orta düzey sınıflara, sonra 13 üst sınıfa (süper sınıf) bağlanmıştır (ekrandan, 02:30:00). Örneğin otobüs, araba gibi kategoriler "dört tekerlekli araç" orta sınıfında, o da "araç" üst sınıfında toplanır. Diğer üst sınıflar arasında top, alet, meyve, hayvan, elektronik, mutfak eşyası, enstrüman, yiyecek, günlük ihtiyaçlar sayılabilir.
- Etiketler: sınırlayıcı kutular (nesnenin nerede olduğunu belirlemek için) ve yüksek kaliteli, nesne ve örnek düzeyinde piksel maskeleri.

Sunumu yapan öğrenci, ortalamanın yanıltıcı olabileceğini, çünkü bazı gruplarda yalnız birkaç görüntü bulunurken bazılarında 30 civarı görüntü olduğunu, yani veri setinin dengesiz olduğunu belirtti.

### 7.4 Deneysel Karşılaştırmalar

CBCS, ESMG, RFPR gibi geleneksel ve çeşitli derin öğrenme tabanlı algoritmalar önce MSRC, CoSal2015 ve iCoseg ile eğitilmiş, ardından CoSOD3k'nın 13 üst sınıfı üzerinde test edilmiştir. Sunumda genel ortalama başarının yaklaşık %63.9 olduğu, 160 alt sınıf üzerinde değerlendirilseydi büyük olasılıkla daha düşük çıkacağı söylendi. <!-- BELİRSİZ: %63.9 değerinin hangi ölçüte ait olduğu altyazıdan net değil; tablonun karesi yok. -->

Örnek çıktılarda model bir karıncayı yanındaki arıdan ayırıp yalnız karıncayı, bir baltayı diğer nesnelerden ayırıp yalnız baltayı, bisiklet süren bir kişinin görüntüsünden yalnız bisikleti bölütlemiştir.

Bulgular (ekrandan, 02:35:00):

- Neredeyse bütün derin öğrenme tabanlı modeller geleneksel yaklaşımlardan daha iyi performans göstermiştir; bu da CoSOD için derin öğrenmenin potansiyel avantajını gösterir.
- Uç (kenar) özellikleri iyi sınırlar elde etmeye yardımcı olabilir. Örneğin baltanın uzun bir tutma yerinin olması onu diğer nesnelerden ayıran bir özelliktir.

### 7.5 Tartışma

Makalede tartışılan konular:

- **Ölçeklenebilirlik:** veri seti büyüdüğünde aynı başarı korunabilir mi; modeller her gruptan birden fazla görüntüyü dikkate alabilmelidir.
- **Kararlılık:** bazı yöntemler grubu görüntü çiftlerine ya da alt gruplara ayırır; bu durum sonucun kararlılığını etkiler.
- **Uyumluluk:** SOD on yıldır çalışılan bir alt alan olduğu için, CNN tabanlı SOD modellerini uçtan uca eğitilebilir bir CoSOD çerçevesine bağlamak etkili bir stratejidir.
- **Ölçütler:** mevcut değerlendirme ölçütleri SOD için tasarlanmıştır ve görüntü başına puanların ortalamasını alır. CoSOD ise farklı görüntülerdeki ortak nesnelerin ilişkisini içerdiği için daha uygun ölçütler gerektirir.

Sonuç olarak CoSOD3k'nın çeşitlilik, zorluk ve ölçeklenebilirlik bakımından bir sıçrama yarattığı, zayıf denetimli konumlandırma ve örnek düzeyinde tespit gibi görevlere de yarar sağlayacağı belirtilmiştir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:34:46): Psikofizik değerlendirme grafiğindeki sonuçlar insanlara mı ait?

> **Cevap:** Evet. Grafik, görüntüyü 50-800 ms gören insan katılımcıların doğruluğunu gösterir; amaç insan ile makine başarısını karşılaştırmaktır.

**Soru 2** (derste sözlü, 00:35:58): İnce eylem veri setinde üç farklı model mi eğitiliyor?

> **Cevap:** Evet. İçme, okuma ve oturma için ayrı alt kümeler vardır; her biri için ayrı bir ikili (örneğin okuyor/okumuyor) sınıflandırıcı eğitilir.

**Soru 3** (derste sözlü, 00:47:40): MEVA'da kameraların yerleri sabit mi?

> **Cevap:** Hepsi değil. Bir kısmı yalnız tek açıya bakan sabit kameralardır; bir kısmı sabit konumlu ama yakınlaşıp uzaklaşabilen PTZ kameralardır; devriye kameraları ise dönerek birden fazla bölgeye bakar ve yakınlaşabilir.

**Soru 4** (derste sözlü, 01:02:57): MEVA veri seti herkesin kullanımına açılmış mı?

> **Cevap:** Güvenlik ve yer kameralarıyla çekilmiş kısım açılmıştır; İHA çekimleri açılmamıştır.

**Soru 5** (derste sözlü, 01:06:20): MEVA'da farklı çözünürlükte kameralar var mı, farklı çözünürlükler eğitimde aynı anda kullanılabilir mi?

> **Cevap:** Karşılaştırma tablosuna göre en yüksek çözünürlük 1920x1080'dir; kızılötesi kameraların daha düşük çözünürlükte olduğu düşünülmektedir. Farklı çözünürlüklerin eğitimde birlikte kullanılıp kullanılmadığı makalede anlatılmamıştır; derste bu sorunun kesin cevabı verilmedi.

**Soru 6** (derste sözlü, 01:47:02): Tablodaki CER ne anlama geliyor?

> **Cevap:** Character Error Rate, yani karakter hata oranı. WER ise Word Error Rate, kelime hata oranıdır.

**Soru 7** (derste sözlü, 01:49:13): Metin artırma demosunda görüntü kaç parçaya bölündü, bu sayı değiştirilebilir mi?

> **Cevap:** Üç parçaya ($N = 3$). Parça sayısı parametriktir; daha uzun metinlerde artırılabilir. Ajan ise yarıçap $R$'nin uygun büyüklüğünü ayarlamaya çalışır.

**Soru 8** (derste sözlü, 02:40:07): Ortak belirgin nesne tespiti tıbbi görüntüler dışında nerede ve ne amaçla kullanılabilir?

> **Cevap:** Sunumu yapan öğrenci, ortamda göz ardı edilebilecek çok ayrıntılı bir nesneyi bulunduğu yerden ayırmak için kullanılabileceğini, ilk akla gelenin tıbbi görüntülerde kanserli hücreleri bulmak olduğunu söyledi. Hoca, bir dizi çerçevede belirli nesneleri (örneğin sunumdaki top örneğindeki gibi) bölütlemek için kullanılabileceğini ekledi. Öğrenci ayrıca nesnenin önünde bir engel (örneğin el) olsa bile modelin nesneyi ayırmayı sürdürdüğünü, yani örtülmüş nesneleri de tanıyabildiğini belirtti.

## Dersin Toparlaması

Bu derste altı makale sunumu üzerinden bilgisayarla görmenin güncel araştırma konularına bakıldı. İlk iki sunum veri setleri üzerineydi: ince eylem tanıma çalışması, arka plan ve nesne ipuçlarının eylem tanımayı nasıl kolaylaştırdığını ve gerçekten ince ayrıntıya dayanan bir veri setinde modellerin insanların çok gerisinde kaldığını gösterdi. MEVA ise çok kameralı, çok sensörlü ve senaryolu büyük bir etkinlik veri setinin nasıl tasarlandığını ve etiketlemenin kalite ile maliyet arasındaki dengesini anlattı. Model ters çevirme sunumu, derin ağların güvenlik ve gizlilik boyutunu ve GAN önbilgisinin saldırıda nasıl kullanıldığını ortaya koydu.

Son üç sunumda yöntem odaklı çalışmalar vardı: veri artırmayı öğrenilebilir hale getiren metin tanıma yaklaşımı, statik kameralarda kısa ve uzun süreli bellekle dikkat mekanizmasını Faster R-CNN'e ekleyen Bağlam R-CNN ve bir grup görüntüdeki ortak belirgin nesneyi bulan CoSOD. Hoca bu çalışmaların ortak yanının, yazarların yeni ve iyi tanımlanmış bir problemi kendilerinin ortaya koyup buna çözüm önermesi olduğunu vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
