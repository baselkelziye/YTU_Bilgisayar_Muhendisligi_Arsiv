# Ders 4 Genişletilmiş Notu: Öğrenci Sunumları: Çok Etiketli Duygu Sınıflandırması, Emoji Duygu Sözlüğü, Türkçe Kelime Bölütleme ve Metin Benzerliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu kayıt 22 Aralık 2021 tarihli derstir. Dersin tamamı öğrencilerin makale sunumlarına ayrılmıştır. Altı sunum vardır. Video bu not yazılırken kullanılamadığı için slaytta kalan tablo ve şekiller altyazıdan okunamamıştır; bu yerler işaretlenmiştir. Sunumlardaki iddialar makale yazarlarının ve sunan öğrencilerin ifadesidir.

## İçindekiler

- 1. Mikroblog Verisinde Çok Etiketli Duygu Sınıflandırması
- 2. Sosyal Medyada Olay, Duygu ve Duygu Yolu Tahmini (Polaris)
- 3. Emojiler İçin Gözetimsiz Duygu Sözlüğü
- 4. Türkçe Doküman Sınıflandırmada Kelime Bölütleme
- 5. Belge İşleme ve Anlamsal Metin Benzerliği
- 6. Teknik Analiz ve Duygu Gömmeleriyle Hisse Senedi Tahmini
- 7. Akademik Yayın Süreci Üzerine Soru ve Cevaplar

## 1. Mikroblog Verisinde Çok Etiketli Duygu Sınıflandırması

### 1.1 Çalışmanın iddiası

İlk sunumun konusu "Multilabel Classification Based Approach for Sentiment Classification" başlıklı makaledir. Makale 2015'te yayınlanmıştır. Yazarlar, duygu analizinde çok etiketli sınıflandırma yapan ilk çalışma olduklarını iddia eder. Sunan öğrenci konuyu bu iddia ilgisini çektiği için seçtiğini söyler.

Makalenin katkıları dört başlıkta anlatılır:

- Mikroblog verisi üzerinde çalışılır. Twitter'a yazılan her ileti burada mikroblog olarak anılır.
- Literatürdeki on bir iyi çok etiketli yöntem seçilir.
- Yazarların kendilerinin toplayıp etiketlediği iki veri seti kullanılır.
- Sekiz değerlendirme metriği ve üç duygu sözlüğü (sentiment dictionary) ile bir kıyaslama (benchmark) oluşturulur.

Veri Çince olduğu için bu üç sözlük de Çincedir.

<!-- BELİRSİZ: Sözlük adları altyazıda bozuk geçiyor ("DUTSE", "NTSD", "DUT-SD", "DEP-SD"). Üçüncü sözlüğün adı okunmuyor. -->

### 1.2 Çok sınıflı ve çok etiketli sınıflandırma

Hoca sunumun başında asıl kavramı sorgular: Bir yorumun birden fazla etiketi nasıl olur, hem olumlu hem olumsuz mu olur?

Çok sınıflı (multi-class) sınıflandırmada bir örneğe tek sınıf atanır. Çok etiketli (multi-label) sınıflandırmada aynı örneğe birden fazla etiket atanabilir. Sonuç tek bir sınıf değil, bir etiket kümesidir (set of labels). Bu küme tek etiketli de olabilir, çok etiketli de.

**Soru (hoca):** Çok sınıflı ile çok etiketli arasında nasıl bir fark var? Ben konuşurken sınıfa da etiket diyorum.

**Cevap (sunan öğrenci):** Bir tweet aynı anda endişe ve korku duygusu taşıyabilir. Yalnız korku da taşıyabilir. Tek sınıf seçmek yerine bu etiketlerden oluşan bir küme verilir.

Hoca şu yorumu dener: Sınıf "olumsuz" olsun, etiketler de "endişeli" ve "korkulu" olsun. Öğrenci bunu onaylar.

### 1.3 Duygu sınıflandırmasının üç yaklaşımı

Makalede duygu sınıflandırması için üç yaklaşım sayılır:

- **Sözlük tabanlı (lexicon-based):** Kelime torbası gösterimi (bag of words) ile bir sözlük birlikte kullanılır. Sözlük, hangi kelimelerin olumlu, hangilerinin olumsuz düşünce taşıdığını söyler. Bu ifadeler seçilip istatistiksel bir yaklaşımla duygu bulunur.
- **Makine öğrenmesi tabanlı:** Sınıflandırıcılar metnin duygu kutbunu (polarity) doğrudan hesaplamaya çalışır.
- **Hibrit:** Makine öğrenmesinin yüksek doğruluğu ile sözlük tabanlı yöntemin kararlılığı birleştirilmeye çalışılır.

### 1.4 Çok etiketli sınıflandırmanın iki yolu

**Problem dönüştürme (problem transformation):** Problem parçalara bölünerek basitleştirilir. Binary Relevance ve Label Powerset bu gruptandır. Her etiket, diğerlerinden "bire karşı hepsi" (one versus all) mantığıyla ayrılır. Böylece çok etiketli problem birden çok tek etiketli probleme çevrilir.

**Algoritma uyarlama (algorithm adaptation):** Var olan sınıflandırıcıların bazı özellikleri değiştirilerek çok etiketli veriye uygun hale getirilir. k en yakın komşu, karar ağacı ve Random Forest bu gruba örnek verilir.

Öğrenci yaklaşık yirmi yöntem olduğunu, hepsini tek tek araştırmadığını söyler. Makalede önceki çalışmalarda başarılı bulunan yöntemler olarak HOMER, Random Forest, Predictive Clustering Tree, Binary Relevance ve Classifier Chain anılır.

### 1.5 Veri setleri

İki veri seti de ulusal gündem olaylarından toplanmış ve yazarlarca etiketlenmiştir.

| Veri seti | Olay | Mikroblog sayısı | Etiket durumu |
|:---|:---|---:|:---|
| HR | Nehirde ölü domuzlar bulunması | 385 | 365 tek etiketli, 20 çok etiketli |
| IA | Influenza A salgını | 762 | Çok etiketli örnek daha fazla; dağılım yine dengesiz |

HR veri setinde etiket dağılımı da dengeli değildir. İki etiket çok baskındır: birinden 194, diğerinden 126 örnek vardır. Öğrenci bunu "uniform dağılım yok" diye yorumlar.

<!-- BELİRSİZ: Baskın etiketler altyazıda "Bury" ve "Anger" diye geçiyor. "Bury" büyük olasılıkla üzüntü anlamında bir etiket, slaytta. IA veri setindeki tek ve çok etiketli sayılar altyazıda okunmuyor. Öğrenci sonda "122" ve "930" sayılarını söylüyor; hangi tabloya ait oldukları net değil. -->

### 1.6 Yöntem

**Metin bölütleme:** Metinler Python'daki Jieba paketiyle bölütlenir. Paket bir kelimeyi tanıyamazsa gizli Markov modeli (Hidden Markov Model) ve Viterbi algoritması devreye girer. Öğrenci bu kütüphaneyi kullanmadığını, makalenin bu kısmına çok girmediğini söyler.

**Soru (hoca):** Burada metin bölütleme, Çincenin Latin harfleriyle yazılmamasından mı kaynaklanıyor?

**Cevap:** Öğrenci öyle düşündüğünü, İngilizce için hazır kütüphaneler bulunduğunu, bu dil için farklı bir araç gerektiğini söyler. Bu sırada "Japonca" der. Hoca "Çinceydi bu, Japonca mı oldu şimdi?" diye düzeltir.

**Sınıflandırıcılar:** Binary Relevance, Classifier Chain gibi problem dönüştürme yöntemleri ve kNN uzantıları dahil on bir çok etiketli sınıflandırıcı denenir. Random Forest ve Predictive Clustering Tree için hazır bir yazılım kullanılır. Problem dönüştürme yöntemleri bir taban sınıflandırıcı (base classifier) gerektirir. Bunun için radyal tabanlı çekirdekli (RBF) SVM seçilir. kNN uzantılarında taban sınıflandırıcı kNN'dir.

**Değerlendirme metrikleri:**

- Örnek tabanlı (example-based): Hamming loss, subset accuracy, örnek tabanlı F1.
- Etiket tabanlı (label-based): mikro F1, makro F1.
- Sıralama tabanlı (ranking-based): coverage, one-error, average precision.

### 1.7 Sonuçlar

Makalede çok sayıda tablo vardır. Öğrenci bunların üzerinden hızlı geçer. Dokuz öznitelik seti denenmiştir: ham bölütlenmiş kelimeler, üç sözlüğün her biri ve ham kelimelerle sözlüklerin birleşimleri.

- HR veri setinde RAkEL ve Classifier Chain, sözlük kullanılmayan ham bölütlenmiş kelimelerle en iyi sonucu verir.
- IA veri setinde başarılar daha düşüktür. Her metrikte birinci olan yöntem değişir. CLR ve HOMER öne çıkar.
- kNN uzantıları iki veri setinde de kötü sonuç verir.
- Sözlüklerden biri diğerinden daha iyidir. Yazarlar bunu daha çok duygu anahtar kelimesi ve duygu gücü (sentiment strength) bilgisi içermesine bağlar.
- İki veri setinde de tek başına öne çıkan bir yöntem yoktur.

### 1.8 Değerlendirme

Öğrenci, kullanılan veri setinin gerçekten çok etiketli olduğunu düşünmediğini söyler. Hoca da veri setinin çok küçük olduğunu vurgular: Birinde yaklaşık 800, diğerinde yaklaşık 400 tweet vardır. Hoca, bu kadar az veriyle neden böyle bir çalışma yapıldığını tam anlayamadığını belirtir.

Öğrencinin eleştirileri şunlardır:

- "Ulusal duygu" iddiası vardır ama yalnız birkaç yüz tweet toplanmıştır.
- Etiket dağılımı yatıktır.
- Çok etiketli örnek sayısı azdır.
- Çok tweet atılan bir gündem olayından daha iyi bir veri seti kurulabilirdi.

Hoca makalenin nerede yayınlandığını sorar. Öğrenci kesin hatırlamaz, Elsevier ya da Springer olduğunu söyler.

> **Ders sonrası not:** Öğrenci "Japonca çok farklı bir dil" derken Çinceyi kastetmiştir. Hoca bunu düzeltmiştir. Veri Çincedir.

> **Ders sonrası not:** Altyazıda bozuk geçen terimlerin doğru yazımları: "J-body" Jieba, "Viter-Balgout Mus" Viterbi algoritması, "Heming" Hamming, "Raker" RAkEL, "Karnis, Nabelhood" k en yakın komşu.

## 2. Sosyal Medyada Olay, Duygu ve Duygu Yolu Tahmini (Polaris)

### 2.1 Çalışmanın amacı

İkinci sunumun makalesi "Social Media Contents Sentiment Analysis and Prediction System" başlığını taşır ve 2018'de yayınlanmıştır. Önerilen sistemin adı Polaris'tir. Sistem büyük miktardaki sosyal medya içeriğini gerçek zamanlı işler. Önce olayları bulur, sonra duyguları sınıflandırır, sonra duyguların zamana ve yere göre izlediği yolu (trajectory) çıkarır ve tahmin eder.

Makalenin katkıları şöyle anlatılır:

- Etiketli veri oluşturmak maliyetlidir. Kişilerin etiketlemesi yerine ifade (emoticon) tabanlı olumlu ve olumsuz etiketleme önerilir.
- Önceki çalışmalarda yol ve duygu analizi genellikle ayrı yapılmıştır. Burada birlikte yapılır.
- Duygu analizi CNN ile, tahmin LSTM ile yapılır.

**Soru (hoca):** Duygu yolu ne demek?

**Cevap:** Öğrenci bunu sunumun ilerleyen kısmında açıklar. Olayla ilgili anahtar kelime içeren içerikler Twitter'da hızla yayılır. Bu içerikler önce yere, sonra zaman dilimine göre gruplanır. Böylece bir olayın ve o olaya ilişkin duyguların izlediği yol çıkarılır.

### 2.2 Veri yönetimi: AsterixDB

Yarı yapısal sorgulamada genellikle MongoDB üzerinde çalışılır. Makale, MongoDB'de join sorgularının hızının yetersiz olduğunu iddia eder. Join sık kullanılan bir sorgu tipi olduğu için gerçek zamanlı sistemde MongoDB uygun görülmez.

AsterixDB, California Üniversitesi'nce geliştirilmiş bir sistemdir. JSON'u genişleten bir veri modeline dayanır. Yarı yapısal ve yapısal olmayan verinin analizi ve sorgulanması için kullanılır. B+ ağacı ve R-ağacı gibi indeksleri destekler. Kümeler kolay yapılandırıldığı için paralel işlem yapılabilir. Gerçek zamanlı veri almak için besleme (feed) mekanizması vardır.

### 2.3 Olay tespiti ve yol analizi

Olay tespitinde Open Directory Project (ODP) tabanlı bir sınıflandırma kullanılır. Olaylar için tohum kelimeler (seed words) çıkarılır. Bu kelimeler sürekli güncellenir. Örnek tohum kelimeler kar (snow) ve kasırgadır (hurricane). Bu kelimeleri içeren içerikler önce sınıflandırılır, sonra konuma göre, ardından her konum altında zaman dilimine göre gruplanır.

**Soru (hoca):** Olay analizinde şöyle mi anlamalıyım: Twitter'da bir tweet okudum. Önce bunun bir olayla ilgili olup olmadığını tespit ediyorum. Örneğin "dolar düştü".

**Cevap:** Evet, kar ve kasırga gibi kelimeler çıkarılır ve tweetler bu kelimelere göre gruplanır. Yol çıkarılacağı için gruplama önce yer, sonra zaman bazındadır.

**Soru (hoca):** Neden hashtag'ler kullanılmamış?

**Cevap:** Makalede bu açıklanmamıştır.

Yol analizinden önceki ön işleme hakkında makalede ayrıntı verilmemiştir.

### 2.4 Duygu analizi ve duygu tahmini

Duygu analizinde cümle sınıflandırma için önerilen bir CNN modeli TensorFlow ile hazırlanmıştır. Öğrenci, CNN'in normalde daha çok görüntü sınıflandırmada kullanıldığını, burada kelimelerin word2vec ile vektöre çevrilip CNN'e verildiğini anlatır.

Duygu tahmininde önce zaman penceresi kavramı denenir. Yedi günlük pencere kullanılır. Pencere içindeki duyguların ağırlıklı ortalaması alınır ve bir sonraki duygu buna göre tahmin edilir. Sistem dinamik olduğu ve ortalama kullanıldığı için bu yöntem iyi sonuç vermez. Bu yüzden LSTM'e geçilir.

Hoca bu noktayı örnekle sorgular: Korkunç bir felaket olsun. İlk iki gün olumsuz yazılsın. Üçüncü gün destekler gelsin ve sorunlar çözülmeye başlasın. Düşünceler olumsuzdan olumluya kayamaz mı? Öğrenci aynen bu yüzden pencere yönteminin başarısız kaldığını söyler. Ortalama, ani değişiklikleri yakalayamaz.

<!-- BELİRSİZ: Zaman penceresi tahmin formülü slaytta; altyazıda okunmuyor. Sistem mimarisi şekli ve tohum kelime süreci şekli de slaytta. -->

### 2.5 Veri seti ve deneyler

- Bir aylık yaklaşık 40 milyon tweet toplanır. Uç değerler çıkarıldıktan sonra yaklaşık 10 milyon tweet kalır.
- Duygu modeli Sentiment140 veri setiyle eğitilir. Öğrenci 800.000 olumlu ve olumsuz verinin kullanıldığını söyler.
- Görselleştirmede Google Maps animasyonları kullanılır. Mavi olumlu, kırmızı olumsuz duygudur. Düğümün büyüklüğü bir bölgede kaç kez bahsedildiğini gösterir.

### 2.6 Sonuçlar

- Duygu analizinde yaklaşık %84 F1 skoru elde edilir. Karşılaştırma Naive Bayes, SVM ve Random Forest ile yapılır. Öğrenci, derin öğrenme tabanlı yöntemlerle karşılaştırma yapılmasının daha anlamlı olacağını söyler.
- Kar olayında yorumlar olumlu ve olumsuz karışıktır. Hortum (tornado) olayında duyguların %81,8'i olumsuzdur.
- Duygu modelinde 40.000 kelimelik yapı ve iki epoch ile en yüksek başarı alınır.
- Tahminler genelde gerçeğe yakındır. Hortum için yaklaşık 20 veri olduğu için sonuç kötüdür. Yazarlar veri artarsa bunun düzeleceğini iddia eder.
- Gerçek olaylara uygunluğu görmek için futbol, beyzbol ve konser gibi kelimelerle de deney yapılır.
- LSTM, pencere yönteminden daha düşük RMSE verir.
- 1500 ve 4500 iterasyon karşılaştırılır. 4500 iterasyon en iyi sonucu verir. Daha fazlası iyileşme getirmez. İterasyon arttıkça sonuç her zaman iyileşmez.

<!-- BELİRSİZ: "40.000" ifadesi altyazıda "40.000 veri" diye de okunabiliyor; grafiğin ekseni slaytta. -->

Sistemin önerilen kullanım alanları deprem ve hortum uyarı sistemleri, trafik kazası bildirimi ve pazarlamadır.

> **Ders sonrası not:** Sunumda AsterixDB için "Neste tabanlı" denmiştir; altyazıda bu ifade net değildir. AsterixDB'nin veri modeli JSON'un üst kümesi olan ADM'dir (Asterix Data Model).

> **Ders sonrası not:** Altyazıda bozuk geçen terimler: "Centimet 140" Sentiment140, "Nying Bias" ve "Nihil, Bias" Naive Bayes, "RMSI" RMSE.

## 3. Emojiler İçin Gözetimsiz Duygu Sözlüğü

### 3.1 Çalışmanın amacı

Kelimeler için duygu sözlükleri vardır. Örneğin "iyi" kelimesine artı 3 puan, "kötü" kelimesine eksi puan atanır. Bu çalışma aynı şeyi emojiler için yapar. Fark, elle etiketleme yerine gözetimsiz (unsupervised) bir yöntem kullanılmasıdır. Yaklaşık 840 emoji için duygu belirlenmeye çalışılır.

Hoca yine yayın bilgisini sorar. Öğrenci "nerede yayınlandığı çok önemli olmadığı için bakmadım" der. Hoca, kendisi için önemli olduğunu söyler. Slaytın altından çalışmanın 2017'de Elsevier'de yayınlandığı görülür.

### 3.2 Arka plan

- Emojiler son on yılda popülerleşse de yaklaşık 30 yıldır Japonya'da kullanılmaktadır.
- 2009'da 722 emoji Unicode karakteri olarak derlenmiştir. Sonraki yıllarda küme genişlemiştir.
- 2015'teki bir araştırmaya göre Instagram gönderilerinin yaklaşık yarısında emoji kullanılmıştır.
- Sunumda dört yıllık süreçte yaklaşık 20 milyar tweette emoji geçtiği ve Amerika'daki Twitter kullanımıyla ilgili %80-84 gibi bir oran anılır.

<!-- BELİRSİZ: 2009 derlemesini yapan kurumun adı altyazıda "Gobult" diye bozuk. %80-84 oranının neyi ölçtüğü altyazıda net değil. -->

### 3.3 Emojileri kategorilemenin zorluğu

Bazı emojilere olumlu ya da olumsuz demek zordur. Gülümseyen yüz kimi için mutluluk, kimi için tehdit ya da "sen bilirsin" anlamı taşır. Emojipedia sitesi de bazı emojiler için olumlu, mutlu, agresif, ironik ve buyurgan (patronizing) gibi birkaç anlam verir.

Hoca bu örneğe katılmaz. Gülen yüzü olumsuz yorumlamayacağını, "sevimli görünmeye çalışıyor" diye anlayacağını söyler. Öğrenci bunun olumsuzdan çok tehdit havası verdiğini, belki gençler arasında yaygın olduğunu ekler. Kullanımın bağlama (context) göre değiştiğini söyler.

Elle oluşturulan sözlüklerin iki sorunu vardır. Çok zaman alır. Üstelik üreticinin amacı ile emojinin kullanıldığı anlam farklılaşabilir.

**Soru (hoca):** Ben bir emoji uydursam, bunu nerede yayınlarım? Kabul görmesi için bir kurum, birim var mı?

**Cevap (öğrenciler):** Bir öğrenci önerinin gönderilebildiğini söyler. Başka bir öğrenci Wikipedia benzetmesiyle merkezi bir otorite olmadığını düşündüğünü belirtir.

> **Ders sonrası not:** Emojiler için "merkezi bir otorite yok" sözü doğru değildir. Emojiler Unicode Konsorsiyumu tarafından standartlaştırılır. Yeni emoji önerileri bu kuruma gönderilir.

Hoca ayrıca bir metnin tamamen emojilerle anlatıldığı bir çalışma gördüğünü, kesin emin olmadığını söyler.

### 3.4 Önceki çalışmalar ve emojilerin önemi

Emojilerle ilgili ön çalışmalar kısıtlıdır:

- Bir şehrin ilçelerinde ya da farklı ülkelerde hangi emojilerin yaygın olduğunu inceleyen çalışmalar vardır. Bunlar duygu değil, kullanım istatistiği içerir.
- Bazı çalışmalarda tweetlerin kelime vektörleri karşılaştırılır. İki tweet çok benziyor ama farklı emoji içeriyorsa, bu emojilerin yakın anlamda kullanıldığı düşünülür.

Duygu analizinde ön işleme sırasında emojileri temsil eden Unicode karakterleri genellikle silinir. Bu, metnin kutbuna en çok katkı yapan ipucunu kaybettirebilir.

Sunumdaki örnek "I still have Christmas shopping to do" cümlesidir. Cümle tek başına olumlu mu olumsuz mu belli değildir. Kimi alışverişi sever, kimi sevmez. Olumsuz bir emoji eklenince cümlenin tamamı olumsuzlaşır.

Hoca, "hala" kelimesinin ve üslubun da olumsuz bir his verdiğini söyler. Tartışmada "hala yapacak bir sürü işim var" ifadesinin mutluluk anlamına da gelebileceği örneklenir. Öğrenciye göre emoji konunca bu soru işareti ortadan kalkar.

### 3.5 Yöntem

Önceki çalışmalarda genellikle emojilerin geçtiği metinler belirlenir ve kişiler bunları elle etiketler. Elle etiketleme çalışmalarında emojilerin yaklaşık %25'inde etiketleyiciler arasında fikir ayrılığı çıkar. Ayrıca aynı emoji iOS ve Android'de farklı görünebildiği için platformlar arası tutarsızlık oluşur.

Bu çalışmanın adımları şöyledir:

1. Her emojinin Emojipedia'daki açıklaması (description) alınır ve duygu analizi yapılır.
2. Emojinin geçtiği Twitter cümlelerinin emojisiz kısmı ayrıca duygu analizine verilir.
3. İki sonuç aynı yöndeyse emojiye o puan atanır.
4. Emojinin açıklaması olumlu ama kullanıldığı cümleler çoğunlukla olumsuzsa puan yavaş yavaş olumsuza çekilir. Son puan buna göre belirlenir.

Kelime duygusunu bulmak için iki sözlüğün birleşimi kullanılır. Hiçbir aşamada etiketli veri gerekmez.

### 3.6 Veri seti ve sonuç

Daha önceki çalışmalarda etiketlenmiş 1,6 milyon tweet vardır. Bu çalışma yalnız İngilizce ve İspanyolca kısmıyla yapılır. Öğrenci burada 103.000 tweet olduğunu söyler. İngilizce kısmı 9, İspanyolca kısmı 5 kişi tarafından etiketlenmiştir. İngilizce tweetlerde 624, İspanyolca tweetlerde 613, toplamda 704 farklı emoji geçer.

Emojisiz metnin duygusu ile emojinin duygusunun uyum oranı %59,82'dir. Hoca cümleyi yeniden söyletir ve oranı düşük bulur. Öğrenci üç noktaya dikkat çeker:

- Emojilerin kullanımı kişiden kişiye değişir.
- Önceki çalışmalarda oran %45-50 civarındadır.
- Yöntem gözetimsiz olduğu için elle etiketleme süresi harcanmaz.

Hoca emoji etiketlerinin cinsiyete göre de değişebileceğini, kadın ve erkek bakış açısının aynı olmadığını söyler. Öğrenci kültüre, bağlama ve ülkeye göre de değiştiğini ekler. Koyun emojisi örneğini verir: Sıradan bir hayvan olarak da, hakaret olarak da kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** Uyum oranı bir sınıflandırma doğruluğu gibi okunmamalıdır. Burada iki otomatik tahmin karşılaştırılır: metnin duygusu ve emojinin duygusu. Metin ile emoji ironi nedeniyle gerçekten zıt olabilir. Bu yüzden düşük uyum her zaman yöntemin hatası anlamına gelmez.

## 4. Türkçe Doküman Sınıflandırmada Kelime Bölütleme

### 4.1 Çalışmanın amacı

Makale 2020'de IEEE INISTA (Innovations in Intelligent Systems and Applications) konferansında yayınlanmış dört sayfalık bir bildiridir. Öğrenci yayın yerini aramakta zorlanınca başka bir öğrenci Google Scholar'dan bulur, konferansın Sırbistan'da yapıldığını söyler.

Çalışmanın amacı, Türkçe doküman sınıflandırmada kelime bölütleme (word segmentation) yöntemi seçiminin sinir ağı sınıflandırıcılarının performansına etkisini araştırmaktır. Türkçe morfolojik açıdan zengin bir dildir ve çok yabancı kelime içerir. Bu durum sinir ağlarının eğitimini zorlaştırır. Literatürde morfolojik, alt kelime (subword), boşluk tabanlı ve hibrit yaklaşımlar denenmiştir.

### 4.2 Bölütleme yöntemleri

- **Kelime tabanlı:** Metin boşluklara göre bölünür. En yaygın yöntemlerden biridir.
- **Karakter tabanlı:** Metin karakterlere bölünür.
- **Karakter n-gram:** $n$ değeri 2'den 7'ye kadar alınır. Standartlaştırılmamış metinde daha verimlidir.
- **Kök (stem) tabanlı:** Kelimeler boşluklara göre ayrılır, sonra ekleri çıkarılır. Snowball kütüphanesi kullanılır.
- **Lemma tabanlı:** Bir önceki yönteme benzer. Zemberek kütüphanesi kullanılır.
- **Morfoloji tabanlı:** Kelime gramer kurallarına göre morfemlerine (biçim birimlerine) ayrılır.
- **Morfessor tabanlı:** Hoca bu terimi ilk kez duyduğunu söyler (bkz. 4.6).
- **Byte Pair Encoding (BPE):** Bir sıkıştırma algoritmasından türetilmiştir. Hem kelime dağarcığını hem test süresini azaltır. Dile sonradan katılan yabancı kelimelerde daha başarılıdır.
- **Byte düzeyinde BPE:** Bir önceki yönteme dayanır.
- **WordPiece:** Boşlukla ayrılmayan Korece ve Japonca gibi dillerde kullanılır. İngilizcede de kullanılır.
- **Unigram dil modeli tabanlı:** Bir alt kelime algoritmasıdır. Kelime bilgisinden yararlanır.

Sunumda aynı kelimelerin her yöntemle nasıl bölündüğü bir tabloyla gösterilir. Öğrenci, sıkıştırma tabanlı yöntemlerin çıktısının ilk bakışta bir şey ifade etmediğini ama başarılı olduğunu söyler.

<!-- BELİRSİZ: Örnek kelimelerin bölütleme tablosu slaytta; altyazıda okunmuyor. -->

### 4.3 Veri setleri

Dört veri seti kullanılır:

- YTÜ Kemik NLP grubunun toplayıp etiketlediği yaklaşık 17.000 tweet.
- Puanlı yorum veri seti. 4,5 ve üzeri olumlu, 1,5 ve altı olumsuz sayılır, aradakiler çıkarılır.
- Yine Kemik grubunun hazırladığı haber veri seti.
- Kaggle'dan alınan Türkçe ürün yorumları. 5 puan olumlu, 1 veya 2 puan olumsuzdur.

<!-- BELİRSİZ: Puanlı yorum veri setinin adı altyazıda yok (01:09:38-01:10:07 arası kayıp). Öğrenci sonuç kısmında "film yorumları" dediği için bu set film yorumları olabilir. -->

**Soru (hoca):** Bu veri setinin yazarları kim? Yıldız'dan mı, dışarıdan mı?

**Cevap:** Öğrenci önce "Yıldız'dan diye düşünüyorum ama bakmadım" der. Hoca "nasıl, okumadın mı makaleyi?" diye sorar. Sonra veri setinin Yıldız'da hazırlandığı, makale yazarlarının ise onu kullandığı anlaşılır.

Bir tablo, her bölütleme yönteminin her veri setinde kaç birim ürettiğini gösterir. En az birimi karakter tabanlı yöntem çıkarır. Öğrencinin aktarımına göre en çok birimi unigram ve BPE yöntemleri çıkarır.

> **Ders sonrası not:** "En çok birim" ifadesi dikkatle okunmalıdır. Bölütleme sonucu oluşan sözlük boyutu ile bir metindeki toplam birim sayısı farklı şeylerdir. Tablonun hangisini gösterdiği slaytta kalmıştır.

### 4.4 Sınıflandırıcılar ve deney düzeni

Üç sınıflandırıcı vardır: doğrusal model, CNN tabanlı ve LSTM tabanlı sınıflandırıcı. Aşırı öğrenmeyi önlemek için dropout, optimizasyon için Adam kullanılır. Dropout'un ayrıntısı makalede yoktur. Donanım sınırı nedeniyle her girdi 256 token ile sınırlanır. Her deney güvenilirlik için beş kez tekrarlanır.

Ön işleme adımları şunlardır:

- Bağlantılar kaldırılır.
- Büyük harfler küçültülür.
- Noktalama işaretleri ayrılır.
- Birden fazla boşluk tek boşluğa indirilir.
- Tekrarlanan karakterler teke indirilir.
- Ardışık noktalamalar boşlukla ayrılır.

<!-- BELİRSİZ: Modellerin parametreleri altyazıda "%1, %1, %10, %1" ve "yüz körnü" diye bozuk geçiyor. Öğrenme oranı ve CNN çekirdek sayısı olabilir; slaytta. F1 sonuç tablosu da slaytta. -->

### 4.5 Sonuçlar

- Alan (domain) ile sinir ağı mimarisi arasında uyum olmalıdır. Bölütleme yöntemi buna göre seçilmelidir.
- Mimari dizileri modelleyebiliyorsa Morfessor tabanlı bölütleme en iyi sonucu verir.
- Mimari dizileri modelleyemiyorsa unigram, lemma ve kök tabanlı yöntemler benzer sonuç verir.
- Normalize edilmemiş verilerde karakter n-gram tabanlı bölütleme, özellikle $n=5$, en iyi sonucu verir.

Öğrenci tweetleri normalize edilmemiş, film ve ürün yorumlarını normalize edilmiş veri olarak ayırır.

> **Ders sonrası not:** Öğrenci önce "normalize edilmemiş tweetlerde Morfessor en iyi" demiş, hemen ardından "normalize edilmemiş verilerde karakter n-gram en iyi" demiştir. Bu iki cümle birlikte çelişkilidir. Tutarlı okuma şudur: Dizileri modelleyen mimarilerde Morfessor, normalize edilmemiş verilerde karakter 5-gram en iyidir. Kesin eşleşme slayttaki tabloya bağlıdır.

### 4.6 Hocanın geri bildirimi

Hoca öğrenciden çalışmayı bir iki cümleyle özetlemesini ister. Öğrenci yine "dört veri seti" diye başlar.

> **Hocanın vurgusu:** Sunuma veri setiyle başlanmaz. Önce "bu çalışmanın amacı ne?" sorusu cevaplanır.

Hoca art arda şu soruları sorar: Amaç ne? Kaç veri seti kullanıldı? En başarılı yöntem hangisi? Bu yöntem nedir?

Morfessor'u sorunca öğrenci "kelimeleri morfemlerine ayıran" diye cevap verir. Hoca, sunumda bu yöntem Japonca gibi dillerle anılınca Türkçe için neden gerektiğini anlamadığını söyler. Terimi ilk kez duyduğunu belirtir ve makaleyi ister.

> **Ders sonrası not:** Sunumda bu sözün WordPiece mi Morfessor mu için söylendiği karışmıştır. Japonca ve Korece bağlantısı WordPiece içindir. Morfessor, kelimeleri morfem benzeri birimlere gözetimsiz ayıran genel bir araçtır. Türkçe gibi eklemeli dillerde de kullanılır.

> **Ders sonrası not:** Byte düzeyinde BPE sunumda "diziler yerine karakterleri birleştirir" diye anlatılmıştır. Doğrusu: Byte düzeyinde BPE, Unicode karakterleri yerine byte'lar üzerinde çalışır. Böylece sözlük dışı karakter kalmaz.

> **Ders sonrası not:** Altyazıdaki "zembere" Zemberek, "morfesör" ve "morfofesör" Morfessor, "ITRE" ve "I Triple" IEEE, "Sitem" stem, "skolar" Google Scholar'dır.

## 5. Belge İşleme ve Anlamsal Metin Benzerliği

### 5.1 Çalışmanın amacı

Makale "Document Processing Methods for Semantic Text Similarity Analysis" başlığını taşır. 2020'de INISTA konferansında yayınlanmıştır. Yazarlar İngiltere'deki bir üniversitedendir.

Metin benzerliği belge çıkarımı, makine çevirisi ve metin özetleme için önemlidir. Çok sayıda belge olduğu için otomatik analiz sistemleri gerekir. Çalışmanın amacı, metin benzerliği analizi için Jaccard ve kosinüs benzerliğini değerlendirmektir.

Uygulama alanı demiryolu güvenliğidir. Bu alanda belgeler dijitalleştirilirken kurumsal mimari (Enterprise Architecture) modelinde UML formatında toplanır. Yazarlar, kılavuz, yönetmelik ve rehberlerdeki güvenlik açısından kritik ifadelerin bu modelde yer alıp almadığını görmek ister. Bunu elle yapmak uzun sürer. NLP yöntemi kurulursa gelecekte eklenen her yeni rehber de otomatik karşılaştırılabilir.

Yayın bilgisi burada baştan verilir. Sunum ayrıca akışını da ilk slaytta anlatır.

### 5.2 Kullanılan araçlar

- **CUDA:** Paralel hesaplama için NVIDIA teknolojisi.
- **Anaconda Navigator:** Spyder ve Jupyter Notebook gibi araçları bir araya toplayan arayüz.
- **Jupyter Notebook:** Kod, grafik ve metni birlikte yazıp paylaşmaya yarayan ücretsiz araç.
- **Python, NLTK ve Gensim:** Metin işleme kütüphaneleri.
- **Google News veri seti:** Önceden eğitilmiş word2vec vektörlerinin kaynağı.

Model kendi korpusunu oluşturmaz. Eğitilmiş vektörleri hazır alır. Bu vektörlerin hepsi 300 boyutludur. Öğrenci, kosinüs benzerliği için vektör uzunluklarının eşit olması gerektiğini hatırlatır.

> **Ders sonrası not:** CUDA bir GPU değildir. NVIDIA'nın paralel hesaplama platformu ve programlama arayüzüdür. Sunumda "NVIDIA'dan bir GPU" denmiştir.

> **Ders sonrası not:** Google News modeli için sunumda "300 milyon" ve "1 milyar kelime" denmiştir. Doğrusu: Model yaklaşık 100 milyar kelimelik Google News korpusunda eğitilmiştir. Yaklaşık 3 milyon kelime ve öbek için 300 boyutlu vektör içerir. Addaki 300, vektör boyutudur.

> **Ders sonrası not:** Gensim sunumda "generate similarity" diye açıklanmıştır. Adı "generate similar" ifadesinden gelir. Konu modelleme ve kelime gömmeleri için bir Python kütüphanesidir.

### 5.3 İki benzerlik ölçütü

**Jaccard benzerliği** sayıma dayanır. İki cümle kümelere ayrılır. Kesişim, birleşime bölünür:

$$J(A,B) = \frac{|A \cap B|}{|A \cup B|}$$

**Kosinüs benzerliği** vektörler arasındaki açıya bakar. Açı büyükse benzerlik azdır, küçükse fazladır:

$$\cos\theta = \frac{\mathbf{a}\cdot\mathbf{b}}{\|\mathbf{a}\|\,\|\mathbf{b}\|}$$

Kosinüs benzerliği one-hot veya TF-IDF ile de hesaplanabilir. Burada word2vec seçilir. Sebep, başlıktaki "anlamsal" kısmıdır. Word2vec bir kelimeyi cümledeki diğer kelimelerle ilişkisinden, yani bağlamından öğrenir. One-hot gösterim bağlamdan bağımsızdır.

Öğrenci "dog" ve "cat" gibi iki kelime arasında da bu vektörlerle kosinüs benzerliği alınabileceğini gösterir. Jaccard'da word2vec yoktur.

> **Ders sonrası not:** Sunumda Jaccard için bir yerde "toplamıyla kesişimi arasındaki fark" denmiştir. Doğrusu farkı değil, kesişimin birleşime oranıdır.

> **Ders sonrası not:** Kosinüs benzerliğinin "0-1 arası" olması yalnız negatif olmayan vektörler (TF-IDF, sayım) için doğrudur. Word2vec vektörlerinde kosinüs benzerliği $[-1, 1]$ aralığındadır.

### 5.4 Veri ve ön işleme

Veri yazarların üniversitesindeki demiryolu araştırma enstitüsünden alınır. İki formattadır: CSV formatında eşleme dosyası ve UML formatında kurumsal mimari modeli. İkisi de CSV'ye dönüştürülüp Jupyter Notebook'a alınır.

İki iş paralel yürür:

- **Benzerlik işi:** Paragraflar kelimelere ayrılır (word tokenization). Stop word'ler silinir. Rakamla başlamayan paragraflar düzenli ifade (regular expression) ile atılır. Sebep şudur: Kurallar "2.1.1" gibi madde numaralarıyla ilerler. Bunun dışındaki yerler kuralla ilgili değildir. Her numaralı paragrafa ayrı puan verilir.
- **Sorumlu aktör işi:** Metin cümlelere ayrılır (sentence tokenization). Tekrarlanan sorumlu kişiler ve aktörler silinir. UML'de aktör denilen bu kişiler de karşılaştırılır. Sonuç "match difference list" adlı ayrı bir listededir. Kosinüs ve Jaccard skorlarına katılmaz.

Eşik değeri deneme yanılmayla 0,80 seçilir. Sonuç bir tabloda gösterilir.

### 5.5 Sonuç

Yazarlara göre kosinüs benzerliği Jaccard'dan iyidir, çünkü anlam bilgisini yakalar. Örneğin bir satırdaki iki cümle aslında benzerdir. Sağdaki cümlede parantez içinde çok kelime olduğu için Jaccard skoru düşer. Birkaç ortak kelime bulunan alakasız cümlelerde de kosinüs yüksek skor üretmez.

### 5.6 Tablodaki tutarsızlık tartışması

Sunan öğrenci yöntemi Jupyter Notebook'ta kendisi denemiştir. Makaledeki bazı Jaccard değerleriyle kendi sonuçları uyuşmaz. Benzer olması beklenen satırlarda değerler uyumludur. Yanlış eşleşme satırlarında ise fark çıkar.

Bir örnekte kesişimde yaklaşık 10 kelime sayar ve 0,26 bulur. Tablodaki değer ise 0,86'dır ve eksi işaretle yazılmıştır. Başka satırlarda kendi hesabı yaklaşık 0,17 ve 0,07 çıkar.

Hoca formülü hatırlatır: Bir cümle çok kısa, öbürü çok uzunsa kesişim azdır ve birleşim büyüktür. Bu durumda 0,86 çıkamaz.

Tartışmada şu açıklama ortaya çıkar: Tablodaki açıklamaya göre artı işaret doğru eşleşme, eksi işaret yanlış eşleşmedir. Sınıftan bir öğrenci eksi işaretli değerin "yanlış eşleşme oranı" olduğunu söyler. Bu okumaya göre 0,86 değeri aslında $1 - 0{,}86 = 0{,}14$ benzerlik demektir.

Hoca neden doğrudan farkın yazılmadığını sorar. Öğrenci diğer satırlarda da tutarsızlık olduğunu söyler. Makalede bu gösterim açıkça anlatılmaz.

> **Ek bilgi (derste anlatılmadı):** Jaccard uzaklığı (distance) $1 - J(A,B)$ olarak tanımlıdır. Tablodaki eksi işaretli değerler bu uzaklık olarak okunursa 0,86 uzaklık, 0,14 benzerliğe karşılık gelir. Bu bir yorumdur; sunumda makalenin bunu açıkça söylediği belirtilmez.

Öğrenci ayrıca Jaccard'da sayıların da hesaba girdiğini, kosinüste ise hazır korpusta bu sayılar olmadığı için girmediğini belirtir.

### 5.7 Hocanın değerlendirmesi

Hoca, sunumların çoğunun slaytlarının İngilizce olduğunu fark ettiğini söyler. Bu sırada birkaç öğrenci kendi slaytlarının da Türkçe olduğunu belirtir. Sınıftan bir öğrenci sunumu çok beğendiğini söyler.

> **Hocanın vurgusu:** Seminer konusu olarak alınan çalışmanın benzerini proje olarak yapmak çok faydalıdır. Veri seti değişebilir ama yöntem tanıdık olur. Hoca bunu bu dönem için geç kalmış bir öneri olarak söyler, çünkü projeler daha önce seçilmiştir.

## 6. Teknik Analiz ve Duygu Gömmeleriyle Hisse Senedi Tahmini

### 6.1 Çalışmanın amacı

Son sunumun makalesi 2019'da Elsevier'in Expert Systems with Applications dergisinde yayınlanmıştır. Öğrenci derginin Q1 olduğunu ve etki faktörünün (impact factor) yaklaşık 9 olduğunu söyler.

Hoca makalelerin aynı dergiden gelmesiyle ilgili bir soru üzerine açıklama yapar: Hakemlik için gelen makaleleri bir klasörde topladığını ve seminer konularını oradan dağıttığını söyler.

Hisse senedi piyasası tahmini yarım yüzyıldır uğraşılan bir problemdir. İki yaklaşım vardır:

- **Teknik analiz:** Tahminler hisse fiyatına dayalı matematiksel göstergelere dayanır.
- **Temel analiz:** Haberlerden ve makroekonomik faktörlerden alınan bilgi kullanılır.

Çalışmanın amacı bu ikisini birleştirmektir. Fiyat zaman serilerinden ve duygu gömmelerinden (sentiment embedding) yararlanarak bir hisse senedi portföyünün gelecekteki trendini tahmin eden model geliştirilir.

Öğrenci sunumda döviz kurundaki güncel gelişmeye gönderme yapmak ister. Hoca buna gerek olmadığını, her konunun kendine özel olduğunu söyler.

### 6.2 Piyasa teorileri

- **Etkin Piyasa Hipotezi (Efficient Market Hypothesis, EMH):** Fiyat, yeni yayınlanan bilgi ve haberlere bağlı olarak değişir. Haber doğası gereği öngörülemez. Yeni değer için mevcut veriler üzerinden hareket edilir.
- **Uyarlanabilir Piyasa Hipotezi (Adaptive Market Hypothesis, AMH):** EMH ile davranışsal finans arasında bağlantı kurmaya çalışır. Borsadaki anormallikleri psikoloji temelli teorilerle açıklar.

Geçmişte zamana bağlı istatistiklerden ve teknik modellerden yararlanılmıştır. Son dönemde ARIMA ile sinir ağlarını birleştiren hibrit modeller ve makine öğrenmesi yöntemleri kullanılmaktadır.

### 6.3 Yöntem

Problem sınıflandırma problemi olarak ele alınır. Hedef etiket, trendin boyutunu sabitleyen bir hiperparametre ile tanımlanır. Örnekler olumlu ve olumsuz diye gruplanır. Veriye min-max normalizasyonu uygulanır.

Öznitelikler iki kaynaktan gelir:

- **Metinsel kaynak:** Hisseyle ilgili haber özetleri.
- **Sayısal kaynak:** Fiyat ve fiyattan hesaplanan teknik göstergeler.

Üç öznitelik seti karşılaştırılır: fiyat, haber ve ikisinin birleşimi.

Haberlerden duygu çıkarmak için iki sözlük kullanılır:

- **Loughran-McDonald:** Finans uygulamalarına özel sözlük. Her haber için kaç olumsuz, kısıtlayıcı ve davalı (litigious) kelime geçtiği sayılır.
- **AffectiveSpace:** Alana özel değildir. Haber gibi yapılandırılmış metinlerden kavram düzeyinde duygu çıkarabildiği için seçilir. Kavramları anlamsal ve duygusal ilişkilerine göre gruplayarak çalışır.

Aynı çeyrek saatte yayınlanan haber gömmeleri gruplanır ve ortalamaları o dilimin gömmesi olur. Fiyatlar 15 dakikalık aralıklarla Google Finance API'den alınır. Fiyat ve seçilen göstergeler sıralanarak 11 boyutlu bir vektör oluşturulur.

İki sorun ele alınır:

- **Trend eğiliminden doğan sınıf dengesizliği:** SMOTE tekniğiyle çözülür.
- **Örnekler arası bağımlılık:** Örtüşen kümeler nedeniyle veri karıştırılamaz ve doğrulama kısmı rastgele alınamaz. Aksi halde doğrulama örnekleri eğitim örneklerine bağımlı olur. Bu yüzden genişleyen pencereli çapraz doğrulama (increasing window cross-validation) kullanılır.

Sınıflandırıcılar Random Forest, SVM ve yapay sinir ağıdır. Random Forest çok sayıda karar ağacı kurar. SVM karar sınırları arasındaki marjı büyütmeye çalışır. Yapay sinir ağında her birim, girdilerinin doğrusal birleşimine doğrusal olmayan bir fonksiyon uygular.

Veri NASDAQ 100 endeksinin en büyük 20 hissesinden oluşan portföydür. Yüksek frekanslı alım-satım (high-frequency trading) simülasyonu yapılır. Bir sonuç, portföydeki her hisse için elde edilen sonuçların ortalamasıdır.

<!-- BELİRSİZ: Hedef etiket formülü ve "CWD" diye geçen sınır slaytta. Sonuç tablolarındaki değerler slaytta. "VIX'le sonorlu sözünü önlemek" ifadesi anlaşılmıyor; büyük olasılıkla bir yanlılığı (bias) önlemekle ilgili. -->

### 6.4 Sonuçlar

- Duygu gömmeleri ile teknik göstergelerin birleşimi, yalnız fiyat kullanımından daha iyi sonuç verir.
- AffectiveSpace sınıflandırma başarımında daha yüksek sonuç verir.
- Yıllık getiri açısından Loughran-McDonald öznitelikleri daha yüksek sonuç verir.

### 6.5 Hocanın açıklaması: Q1 dergiler

Dergi hakkında konuşulurken hoca şu bilgiyi verir: Bazı dergiler yılda iki, üç ya da dört kez çıkar. Expert Systems with Applications'ın sayı sayısı fazladır ve her sayıda çok makale yayınlar. Çok yayın olunca ve makaleler birbirine atıf verince etki faktörü daha kolay artar.

> **Hocanın vurgusu:** Her Q1 dergi sizi korkutmasın. Yılda çok sayı çıkarmak ve her sayıda çok makale basmak Q değerini ister istemez artırır.

> **Ders sonrası not:** Random Forest için sunumda "regülasyon" denmiştir. Doğrusu regresyondur (regression).

> **Ders sonrası not:** Altyazıda bozuk geçen terimler: "Logran-McDonough", "Logan" Loughran-McDonald; "Affective Space", "Effective Space" AffectiveSpace; "smotiviren" büyük olasılıkla SMOTE; "350 seti" üç öznitelik seti; "arima" ARIMA; "tren" trend.

## 7. Akademik Yayın Süreci Üzerine Soru ve Cevaplar

Son sunumdan sonra hoca, doktorada yayın çıkaracak öğrenciler için deneyimlerini paylaşır.

**Soru (öğrenci):** Bu derginin yayın süresi bir buçuk haftaymış, doğru mu?

**Cevap:** Hoca bu dergide kendi yayını olduğunu, bir buçuk haftada dönüş almadığını söyler. Bu süre büyük olasılıkla hakemlere atanma gibi bir ilk geri dönüşün süresidir. Hoca, 6-7 ay bekledikten sonra "dergimizin kapsamına uymuyor" cevabı alınabildiğini de ekler.

**Soru (öğrenci):** Sizin yayınınız ücretli miydi, süreç ne kadar sürdü?

**Cevap:** Bu dergiye ücret ödenmez. Başka bir öğrenci IEEE Access'e ücret ödeyip süreci iki ayda tamamladığını söyler. Hoca süreçle ilgili şunları anlatır:

- Süreç hakeme bağlıdır. Kimi hakem hemen değerlendirir, kimi uzun süre bekletir.
- Çalıştığınız konuda hakem sayısı çok ya da az olabilir.
- IEEE Access iyi bir dergidir. Ücret sizi yanıltmasın. Hocaya göre ücret süreci hızlandırmak içindir: Hakem belirli süre içinde değerlendirmek zorunda kalır.

> **Hocanın vurgusu:** "Paranı ver, makalen basılsın" türü dergilerden uzak durun. Akademik yükseltmelerde bu dergiler fark edilir. Sicilinize işlenir.

Hoca bir anısını anlatır: Bir dergide uzun süre (8-10 ay) bekledikten sonra "sayfa sayınız fazla" cevabı almıştır. Gönderildiğinde sınır 10 sayfadır, süreç içinde sınır azaltılmıştır. Hocaya göre makale gönderildiği tarihteki kurala göre değerlendirilmelidir.

**Soru (öğrenci):** Bu kadar beklerken makalenin başka biriyle paylaşılıp paylaşılmadığını nasıl takip edeceğiz?

**Cevap:** Hoca şu noktaları sıralar:

- Makaleden önce sempozyum ya da ulusal dergide yayın yapılırsa, çalışmanın başlangıç tarihi ortaya çıkar. Bu önemlidir.
- Hakemin fikri kullanması etik değildir. Eninde sonunda anlaşılır.
- Dünyanın başka yerinde biri aynı konuda habersizce çalışıyor olabilir. O kişi hakem olarak makaleni alırsa, etik olarak değerlendirmemesi gerekir. Değerlendirirse fikirlerden etkilenebilir.

> **Hocanın vurgusu:** Bir sonuç elde edince beklemeden yayına dönüştürün. Aynı konuda başkası da çalışıyor olabilir ve sizin önünüze geçebilir.

Bir öğrenci arXiv gibi ön baskı (preprint) sitelerini hatırlatır. Hoca bunu onaylar. Her sempozyumun taranan bir indekste olmadığını, bu yüzden erişimin garanti olmadığını da ekler.

> **Ek bilgi (derste anlatılmadı):** IEEE Access altın açık erişimli (gold open access) bir dergidir. Ödenen tutar makale işlem ücretidir (article processing charge). Böyle ücretli dergiler ile hakem denetimi zayıf olan yağmacı (predatory) dergiler aynı şey değildir.

> **Ders sonrası not:** Hoca "hakemlere bazen ücret veriliyor" diye bir olasılık söyler, "olabilir" diye belirtir. Bu altyazıya göre hocanın tahminidir. IEEE Access'in ücretini hakem ödemesi olarak doğrulayan bir bilgi derste verilmemiştir.

## Dersin Toparlaması

Dersin altı sunumu duygu analizi ve metin işleme etrafında toplanır. İlk üç sunum duygu analizinin farklı yönlerini gösterir: bir metne birden çok etiket atamak, duygunun zaman ve mekândaki yolunu izlemek, emojiler için sözlük kurmak. Dördüncü sunum Türkçe metinlerde bölütleme seçiminin sınıflandırıcıya etkisini, beşinci sunum sayıma dayalı ve anlama dayalı benzerlik ölçütlerini karşılaştırır. Altıncı sunum duygu bilgisini finansal tahmine taşır.

Hocanın sorularından çıkan ortak ders şudur: Bir makale okunurken amacı, yayın yeri, yazarları, veri setinin kökeni ve küçük veri gibi zayıf noktaları sorgulanmalıdır. Son bölümde bu sorgulama yayın sürecine bağlanır: Dergi seçimi, hakem süreci ve fikrin önceliğini korumak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
