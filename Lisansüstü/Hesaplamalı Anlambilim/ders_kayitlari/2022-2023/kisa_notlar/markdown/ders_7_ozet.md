# Ders 7 Çalışma Özeti

## Genel Konular

- Kaldığımız yer ve insan-makine işbirliği
  - Bölüm 4'e ("makine öğrenmesi versiyon 2") devam edildi. Önceki derste aktif örneklemede modelin hangi bölgeden örnek istediğini kendisinin söylediği anlatılmıştı; bu ders insan-makine işbirliğiyle başladı.
  - Slayttaki tanım (ekrandan, 00:08:45): insan ve makine zekasının birleşimi; "human in the loop" ya da "weak supervision" diye de geçer. İnsanlar yavaş ama doğrudur: veri etiketleyebilir, tahminleri düzeltebilir, tahminler arasından seçim yapabilir (100 sınıftan en olası 5'inden doğru olanı seçmek gibi), örneklerin ortak bir özelliği için kural verebilir ("içinde şu ifade geçenler negatiftir", "kedilerin kuyruğu vardır"). Makineler hızlıdır, çok sayıda bilgiyle başa çıkabilir, ama daha az doğrudur; tahmin üretebilirler.
- İnsan-makine işbirliği örnekleri
  - Video etiketleme: insan bir nesneyi yalnız birkaç anahtar karede işaretler; makine aradaki karelerdeki yörüngeyi interpolasyonla tahmin eder. Böylece birkaç etiketle onlarca kare etiketlenmiş olur.
  - Otomatik çeviri ve insan düzeltmesi: önce makine çevirisi alınır, sonra insan onu düzenler.
  - Zayıf denetim (weak supervision): örnekleri tek tek etiketlemek yerine örnek topluluklarına kural verilir ("içinde şu ifadeler geçen tweet olumsuzdur", "kuyruğu olanlar hayvandır"). Avantajı az emekle çok örnek etiketlemek, dezavantajı kuralların her zaman doğru olmamasıdır. Bir örnek için birden fazla zayıf etiket oluşur, bazen çelişirler; zayıf etiketleri güçlü etiketlere dönüştüren bir model kurulur. Bunun için Snorkel adlı bir çerçeve vardır.
- İnsan geri bildirimiyle pekiştirmeli öğrenme (RLHF)
  - Denetimli öğrenmede her girdi için doğru çıktı söylenir. Pekiştirmeli öğrenmede doğru çıktı söylenmez; sistemin ürettiği çıktıya ödül ya da ceza verilir. Etiketleyicinin tam doğru cevabı bilmesi gerekmez; çıktının hedefe ne kadar yakın olduğunu söylemesi yeter.
  - Oyun gibi klasik pekiştirmeli öğrenme uygulamalarında geri bildirim ortamdan ya da kendi kendine oynamadan (self-play) gelir ve milyarlarca kez alınabilir. İnsandan geri bildirim almak değerlidir ama pahalıdır ve ölçeklenmez.
  - InstructGPT'nin üç adımı (ekrandan, 00:20:00): (1) gösterim verisi toplanır ve denetimli bir politika eğitilir: istem veri kümesinden bir istem seçilir, bir etiketleyici istenen çıktıyı yazar, bu veriyle GPT-3 ince ayarlanır (SFT); (2) karşılaştırma verisi toplanır ve ödül modeli (reward model, RM) eğitilir: bir isteme karşı modelden birkaç çıktı örneklenir, etiketleyici bunları en iyiden en kötüye sıralar, bu sıralamalarla ödül modeli eğitilir; (3) ödül modeline karşı politika pekiştirmeli öğrenmeyle (PPO) optimize edilir: yeni bir istem için politika çıktı üretir, ödül modeli ödül hesaplar, ödül politikayı günceller.
  - Bu yapıda "politika", bir girdiye karşı çıktı üreten üretici dil modelidir; genel tanımıyla gözlem uzayından eylem uzayına bir eşlemedir.
  - Kritik nokta ödül modelidir: insanın ne diyeceğini tahmin eden ayrı bir model kurulunca geri bildirim makineden gelir ve pekiştirmeli öğrenme ölçeklenebilir hale gelir. Hoca güncelleme adımlarının en büyük kısmının üçüncü adımda yer aldığını, ama sayıları tam hatırlamadığını söyledi.
  - Aynı modelden bir isteme karşı farklı çıktılar alınabilmesinin sebebi, üretici modellerdeki rastgelelik, dropout ve sıcaklık (temperature) gibi mekanizmalardır.
- Az sayıda örnekle eğitim
  - François Chollet'nin sözü (ekrandan, 00:40:00): eğitim verisi problem uzayını yeterince yoğun örnekliyorsa her problem bir örüntü tanıma problemi olarak ele alınabilir; ilginç olan veri seyrekken olandır: ekstrapolasyon için zeka gerekir.
  - İnterpolasyon, verinin bulunduğu bölgenin içinde tahmin yapmaktır. Ekstrapolasyon, verinin olmadığı bölgelerde (aralığın öncesinde ve sonrasında) davranışı tahmin etmektir.
  - Tek çekimli öğrenme (one-shot learning): eğitim kümesinde her sınıf için tek bir örneğin olduğu problemler. Zürafayı tek resimden tanımak, çok sayıda resimden tanımaktan çok daha zordur. Sıfır çekimli öğrenmede (zero-shot) o sınıfa ait hiç örnek yoktur.
- Google'ın sıfır çekimli makine çevirisi (ekrandan, 00:44:30)
  - 100 dilden 100 dile her dil ikilisi için ayrı model eğitmek 10.000 model demektir ve her ikili için paralel derlem yoktur.
  - A→B ve B→C için veri var, A→C için yok. Çözüm: bütün girişler ortak bir katmana (ortak temsil uzayına) dönüştürülür, çıkışlar bu ortak katmandan üretilir. Örneğin Türkçe-Vietnamca paralel derlem olmasa da Türkçe-İngilizce ve İngilizce-Vietnamca varsa çeviri yapılabilir.
  - Gereken koşul: aynı anlamlı farklı kaynak dillerdeki cümlelerin temsilleri birbirine yakın olmalıdır. Slayttaki görselde Japonca, Korece ve İngilizce aynı anlamlı cümleler aynı kümede toplanır.
- Sıfır çekimli sınıflandırma (ekrandan, 00:50:00)
  - Etiketli veri yoktur, ama hangi sınıflara ayırmak istediğimiz bellidir.
  - Yöntem 1: sınıfları belirle; sınıfları temsil eden örnekleri ve temsillerini bul ($X_i$, $i=1..N$, $N$ sınıf sayısı); yeni gelen örneğin temsilini bul ($K$). $K$, $X_i$'lerin hangisine en yakınsa sınıfı odur. Yakınlık aynı uzaydaki temsiller arasında kosinüs uzaklığı gibi bir ölçüyle bulunur; temsiller word2vec, BERT ya da daha karmaşık modellerden gelebilir.
  - Yöntem 2: BERT gibi bir dil modeli NLI gibi bir veri kümesiyle eğitilir (modelX). Sınıfları temsil eden örnekler bulunur. "$X_i$ [SEP] $K$" girdileri modelX'e verilir; bunların içinde gerektirme (entailment) olasılığı en yüksek olan $X_i$, $K$'nın sınıfıdır. Örnek kalıplar: "Bu metnin konusu {sağlık, spor vb.}", "Bu tweet bana {neşeli, hüzünlü vb.} hissettiriyor."
  - NLI veri kümesi cümle ikililerinden oluşur ve üç sınıf vardır: gerektirme (entailment: birinci doğruysa ikinci de doğrudur), çelişki (contradiction: birinci doğruysa ikinci yanlıştır), nötr (birincinin doğruluğu ikinci hakkında bir şey söylemez). NLI ile ince ayarlanan BERT, iki cümle arasındaki ilişkinin her sınıfa ait olma olasılığını verir (örneğin entailment %90, contradiction %5, nötr %5).
- Veri zenginleştirme (data augmentation)
  - Amaç, etiketli veri miktarını model performansını iyileştirecek biçimde artırmaktır; her ne pahasına olursa olsun artırmak değildir. Yollardan biri yeni veri toplamak, diğeri var olan veride sınıfı değiştirmeyen dönüşümler yapmaktır.
  - Görüntüler için: döndürme, elastik deformasyon, rastgele kırpma, ayna yansıması, renk bilgilerinde değişim (ekrandan, 01:13:00). Her epokta rastgele dönüşüm uygulanırsa model bir eğitim örneğinin özgün halini belki hiç görmez, ama dönüşümlere karşı daha dayanıklı olur.
  - Alana dikkat: MNIST'te rastgele parçalar kırpmak ya da radyoloji görüntülerine bazı filtreler uygulamak uygun olmayabilir.
  - Üretici çekişmeli ağlar (GAN) (ekrandan, 01:20:00): üretici ağ rastgele bir gürültüden eğitim kümesine benzer örnekler üretir; ayırt edici ağ gerçek ve yapay örnekleri ayırmayı öğrenir. İki ağ çekişme halindedir; üretici çok başarılı olursa ayırt edici doğal olarak başarısız olur.
  - Metin verileri için (ekrandan, 01:21:00): eş anlamlı kelime ve deyişler ("Bir gün bana yaptıklarının acısını senden çıkaracağım" → "Senden intikamımı elbet alacağım") ve geri çeviri (orijinal örnek → başka bir dildeki karşılığı → yeni örnek).
  - Genel amaçlı (sayısal) veriler için SMOTE (ekrandan, 01:23:20): amaç sınıf dengesizliğini gidermektir. Az örnekli sınıftan bir örneğin aynı sınıftaki komşularından biri seçilir, ikisini birleştiren doğru üzerinde yeni bir örnek üretilir.
- Gürültü ile düzenlileştirme (ekrandan, 01:27:10 ve 01:30:00)
  - Gerçek ilişki doğrusaldır; 1. dereceden ve 36. dereceden modeller oturtulur. Az veriyle 36. dereceden model ezberler (aşırı uyum). Eğitim örneği çoğalınca yüksek dereceli model de alan (domain) içinde iyi sonuç verir, ama alanın dışına doğru sapma büyür. Yüksek boyutlu uzaylarda ise yeterince çok örnek olmaz.
  - Çözüm: girişe Gauss gürültüsü ekleyip çıkışı aynı bırakarak yeni örnek üretmek. 20 eğitim örneğinden 120 örnek elde edilir. Test hataları: 1. dereceden 0.1908; 36. dereceden (gürültülü eğitim) 0.2404; 36. dereceden (yalnız eğitim) 5.5473e+03.
  - Sonuç: karmaşık modellerin eğitiminde örneklere gürültü eklemek modelin varyansını düşürür.
- Temsilde noktadan dağılıma
  - Gürültüyü çevrim içi eklemek (her epokta yeni gürültülü örnek üretmek), örneği tek bir nokta yerine bir dağılım olarak temsil etmeye denktir (ekrandan, 01:37:30).
  - Varyasyonel otomatik kodlayıcı (VAE), örneklerin saklı uzaydaki temsillerinin hem ortalamalarını hem varyanslarını öğrenir. Kodlayıcı çıktısının bir kısmı ortalama ($\mu$), bir kısmı varyans ($\sigma$) gibi kullanılır; saklı boyutların ilişkisiz olduğu, yani kovaryans matrisinin köşegen olduğu varsayılır. Bu dağılımdan $z$ örneklenir ve kod çözücüye verilir.
  - Dağılım temsili sayesinde yeni örnekler üretilebilir ve temsiller arasında interpolasyon yapılabilir: rakamlar arası (1→9, 6→9), yüzler arası ve cümleler arası geçişler (ekrandan, 01:40:00).
- Makine öğrenmesi algoritmalarını kandırmak (adversarial attacks) (ekrandan, 01:45:45)
  - Kararlar makinelere bırakıldıkça onları kandırma çalışmaları da başlar (istenmeyen e-postalarda olduğu gibi). Bu yalnız derin öğrenmeye özgü değildir; ama doğrusal modelleri kandırmak daha zordur.
  - Slayttaki örnek: orijinal papağan resmi Inception v3'e göre %97 olasılıkla "papağan"dır; üzerine özel hazırlanmış gürültü eklenince aynı mimari göze neredeyse aynı görünen resme %99 olasılıkla "kitaplık" der.
- Planlı öğrenme (curriculum learning)
  - İnsan eğitimindeki gibi, örnekleri anlamlı bir sırayla (kolaydan zora) vermek eğitimi iyileştirir mi sorusu. Zorluğun neye göre belirleneceği (örneğin topluluk/ensemble modellerle) ve önce kolayların mı zorların mı verileceği araştırma konusudur; insan için kolay ve zor olan, makine için kolay ve zor olanla çok ilişkili olmayabilir.
  - Ekrandaki "Sürpriz" tablosunda (ekrandan, 01:50:00) klasik, curriculum ve anti-curriculum (zordan kolaya) yöntemleri ikili olarak karşılaştırılmıştır; literatürde hem kolaydan zora hem zordan kolaya yaklaşımın daha iyi olduğunu söyleyen çalışmalar vardır.
- Hayat boyu öğrenme (lifelong learning)
  - Öğrenme süreci bitmez. Örneğin firmanız hakkındaki kamuoyu algısını ölçen bir duygu analizi modeli kurulduğu andan itibaren eskimeye başlar: dil, jargon, iş dünyası ve ihtiyaçlar değişir. Akademide değil, endüstride daha yaygındır; sürece bir insanın dahil olması (human in the loop) faydalıdır.
- Kendi kendine öğrenme (self-supervised learning) (ekrandan, 01:53:30)
  - Girdi-çıktı ikilileri insan etiketlemesi gerektirmeden derlemden hazırlanır; bu sayede çok büyük miktarda eğitim örneği olur.
  - Görevler: bir sonraki kelime (GPT), maskelenmiş kelime ya da resim parçası (BERT), iki cümle ardışık mı (BERT), bu cümlede değiştirilmiş kelime var mı (ELECTRA), bu kelimelerin doğru sıralaması nedir (hoca: "herhalde T5'te").
  - Büyük derlemlerde bu görevlerle eğitilen önceden eğitilmiş modeller yeni bir eşiğin aşılmasını sağladı.
- Karşıtsal öğrenme (contrastive learning) (ekrandan, 02:00:00)
  - Bir tür kendi kendine öğrenmedir. Sınıf bulmak yerine örnek ikililerinin temsillerini birbirine yakın (pozitif) ya da uzak (negatif) yapmayı öğrenir. Aynı resmin farklı parçaları yakın, farklı resimlerin parçaları uzak olmalıdır.
  - Hoca ilk örneklerden birinin word2vec olduğunu vurguladı: makalede bu ifade geçmese de negatif örneklemeyle tamamen karşıtsal bir öğrenmedir.
  - Çerçeve: $x$ örneğine aynı dönüşüm ailesinden iki farklı veri zenginleştirme ($t \sim \mathcal{T}$, $t' \sim \mathcal{T}$) uygulanır; bir kodlayıcı $f(\cdot)$ (CNN) temsilleri $h_i, h_j$'yi, bir izdüşüm başlığı $g(\cdot)$ (MLP) $z_i, z_j$'yi üretir ve $z$ uzayında uyum en büyüklenir. MLP teorik olarak şart değildir, uygulamada daha iyi sonuç verdiği görülmüştür. Eğitimden sonra elde kalan kodlayıcı, alt görevler için önceden eğitilmiş bir omurga (backbone) olarak kullanılır.
- Bağlam içi öğrenme (in-context learning) (ekrandan, 02:00:40)
  - Büyük dil modellerinde klasik makine öğrenmesi yaklaşımına alternatiftir: model seçimi, eğitim, hiperparametre optimizasyonu yoktur. İsteme "input1 – output1, input2 – output2, input3 – output3, input4 – ?" verilir ve model sonuncunun çıktısını tahmin eder. Yalnız çıkarım (inference) zamanında olur.
  - Her durumda mükemmel çalışmaz; çok büyük verilerle eğitilmiş çok büyük mimarilerde görülür, basit mimarilerde henüz gözlenmemiştir.

## Hocanın Özellikle Vurguladığı Kısımlar

- RLHF'nin asıl hilesi ödül modelidir
  - İnsan geri bildirimi pahalı ve ölçeklenemezdir. İnsanın sıralamalarından, insanın ne diyeceğini tahmin eden bir ödül modeli eğitmek, geri bildirimi makineye devreder ve süreci ölçeklenebilir kılar. Hoca bunu insan-makine işbirliğinin en güzel örneklerinden biri saydı. ChatGPT'nin tam olarak aynı yöntemi kullanıp kullanmadığı bilinmez; InstructGPT'nin makalesi vardır, ChatGPT için blog yazısında bu yöntemi kullandıkları söylenir.
- GAN'da iki ağın başarısı zıttır
  - Ayırt edici ağın çok başarılı olması, gerçek ve üretilmiş resimler arasında bariz fark olduğu, yani üreticinin başarısız olduğu anlamına gelir. Başlangıçta üretici zayıftır; eğitim ilerledikçe üretici iyileşir, ayırt edici kötüleşir.
- Veri zenginleştirmede alan bilgisi önemlidir
  - Bir dönüşüm sınıfı değiştirmemelidir; uygun dönüşüm alana göre seçilir.
- Karmaşık model + gürültü = düşük varyans
  - Derin mimarilerde parametre sayısı çok yüksektir, bu da az veride 36. dereceden polinom oturtmaya benzer. Girişe gürültü eklemek varyansı düşürmenin etkili bir yoludur.
- Sıfır çekimde istemler (prompt) önemlidir
  - Sınıfı temsil eden kalıbın nasıl yazıldığına göre performans değişir; istemleri iyileştirmenin yollarını araştırmak sıfır çekimli öğrenmenin özüdür.
- Kandırma saldırıları bitmeyecektir
  - Spam e-postalar nasıl hiç bitmediyse, kararları makinelere bırakıldıkça bu sistemleri kandırmaya çalışanlar da olacaktır.

## Kısa Tekrar Notları

- İnsan yavaş ama doğru, makine hızlı ama daha az doğru; işbirliği ikisini birleştirir.
- Zayıf denetim: kurallarla toplu, gürültülü etiketler; zayıf etiketleri güçlüye çeviren model (Snorkel).
- RLHF/InstructGPT: (1) SFT, (2) sıralamalarla ödül modeli, (3) ödül modeline karşı PPO.
- İnterpolasyon veri içinde, ekstrapolasyon veri dışında tahmin.
- One-shot: sınıf başına tek örnek; zero-shot: hiç örnek yok.
- Sıfır çekimli çeviri: tüm diller ortak temsil uzayına.
- Sıfır çekimli sınıflandırma: Yöntem 1 temsil uzayında en yakın sınıf kalıbı; Yöntem 2 NLI ile eğitilmiş modelde en yüksek entailment.
- Veri zenginleştirme: görüntü (kırpma, yansıma, renk, döndürme), metin (eş anlamlı, geri çeviri), sayısal (SMOTE), GAN.
- Gürültü eklemek karmaşık modelin varyansını düşürür; çevrim içi gürültü ≈ örneği dağılım olarak temsil etmek (VAE).
- Adversarial: fark edilmeyecek gürültüyle model yanıltılır.
- Curriculum: kolaydan zora mı, zordan kolaya mı tartışmalı.
- Self-supervised: etiket derlemden gelir (sonraki kelime, maskeli kelime, ardışık cümle, değiştirilmiş kelime).
- Contrastive: pozitif ikililer yakın, negatifler uzak; word2vec de bir örnektir.
- In-context: eğitim yok, istemdeki örneklerden tahmin.

## Detaylı Açıklamalar

- İnsan-makine işbirliğinde amaç iki tarafın farklı yeteneklerini birleştirmektir. Video etiketleme örneğinde insan, yürüyen bir kişiyi yalnız birkaç anahtar karede işaretler; makine aradaki karelerdeki konumu interpolasyonla tahmin eder. Hocanın örneğinde dört etiketle yaklaşık otuz kare etiketlenir. <!-- BELİRSİZ: Hocanın tahtaya çizdiği kare numaraları altyazıda karışık (1, 10, 15, 20, 30, 100); kesin numaralar verilmedi. --> Zayıf denetimde ise insan tek örneğe değil örnek topluluğuna bir şey söyler. Bu kurallar bazı örnekler için yanlış olabilir ve aynı örneğe çelişen etiketler verebilir; bu yüzden zayıf etiketleri birleştirip daha güçlü etiketlere dönüştüren ayrı bir model kurulur.
- Pekiştirmeli öğrenmede etiketleme, denetimli öğrenmedeki gibi uzmanlık gerektirmez: etiketleyici doğru cevabı yazamasa bile modelin ürettiği cevabın iyi ya da kötü olduğunu söyleyebilir. InstructGPT'de ilk adım yine denetimlidir: insanlar talimatlara karşı istenen çıktıları yazar ve GPT-3 bu veriyle ince ayarlanır; ama bu adım ölçeklenemez. İkinci adımda ince ayarlanmış model bir isteme karşı birden fazla çıktı üretir (örneğin A, B, C, D), insan bunları en iyiden en kötüye sıralar (hocanın örneğinde D en iyi, B en kötü), bu sıralamalarla ödül modeli eğitilir. Ödül modeli üretici modelden ayrı bir modeldir. Üçüncü adımda üretici model bir çıktı üretir, ödül modeli bunu puanlar ve üretici model bu puana göre güncellenir; böylece insan döngüden çıkar ve süreç ölçeklenir.
- Sıfır çekimli sınıflandırmada Yöntem 1 ödevle doğrudan ilgilidir: sınıfı temsil eden metin (örneğin "Bu metnin konusu ekonomi") ve sınıflandırılacak metin aynı modelle aynı uzaya taşınır, ikisi arasındaki kosinüs uzaklığına bakılır. Yöntem 2'de karşılaştırma doğrudan temsil uzayında yapılmaz; NLI ile ince ayarlanmış model, "sınıf kalıbı [SEP] metin" ikilisinin gerektirme olasılığını verir. Her sınıf kalıbı için bu olasılık hesaplanır ve en yüksek olan sınıf seçilir. Hoca ödevde NLI ile model eğitmenin istenmediğini, yalnız temsil uzayında uzaklık hesabı yapılacağını belirtti.
- SMOTE'de az örnekli sınıftaki bir örnek ($x_1$) ile aynı sınıftaki bir komşusu ($x_2, \dots, x_6$) arasındaki doğru üzerinde bir nokta seçilir ve yeni örnek olarak eklenir. Yeni örnekler uzayı daha fazla kapsar; ama yeni örneğin etiketinin doğru belirlenmesi de önemlidir. Ekrandaki slaytta (ekrandan, 01:23:20) SMOTE'nin karar sınırına yakın yerlerde yapay örnek ürettiğinde sert sınıf geçişlerini zorladığı, bunu önlemek için SMOTE-IPF'in geliştirildiği yazılıdır: önce SMOTE ile örnek üretilir; veri kümesi k parçaya bölünüp her parçayla bir model eğitilir; bu modellerin tutarsız tahmin ettiği örnekler veri kümesinden çıkarılır ve karar sınırları daha yumuşak modellenir.
- Gürültü ile düzenlileştirme deneyinde (kod noise_regularization.m) gerçek model doğrusaldır. Yalnız 20 eğitim örneğiyle oturtulan 36. dereceden model test örneklerinde 5.5473e+03 hata verir. Her eğitim örneğine girişte Gauss gürültüsü eklenerek 5'er yeni örnek üretilir ($20 + 20 \cdot 5 = 120$ örnek); çıkışlar değişmez. Bu 120 örnekle eğitilen 36. dereceden modelin test hatası 0.2404'e düşer, 1. dereceden modelin 0.1908'ine yaklaşır (ekrandan, 01:30:00). Gürültü çevrimdışı (bir kez üretip eğitim kümesine katmak) ya da çevrim içi (her epokta yeniden üretmek) eklenebilir; çevrim içi ekleme, CNN'de her epokta resimlere rastgele dönüşüm uygulamaya benzer.
- VAE'de kodlayıcı çıktısındaki vektörün bir kısmı ortalama, bir kısmı varyans gibi yorumlanır. Saklı uzayın boyutlarının ilişkisiz olduğu varsayıldığından kovaryans matrisi köşegendir. Bu dağılımdan örneklenen $z$, kod çözücüye verilir; otomatik kodlayıcıda hedef girdinin kendisini geri üretmektir. Slayttaki cümle VAE'sinde kodlayıcı ve kod çözücü LSTM hücreleridir (ekrandan, 01:37:30). Hoca, temsili tek bir nokta olarak tutmanın da mümkün olduğunu, ama o zaman yeni ve yeterince farklı örnekler üretmenin zorlaşacağını söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
