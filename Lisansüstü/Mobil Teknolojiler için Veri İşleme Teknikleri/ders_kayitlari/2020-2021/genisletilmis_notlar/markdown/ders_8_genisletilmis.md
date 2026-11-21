# Ders 8 Genişletilmiş Notu: Ayrıklaştırma ve Makine Öğrenmesi Yöntemlerine Genel Bakış

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Haftanın Hatırlatması: Özellik ve Örnek Seçimi
- 2. Ayrıklaştırma (Discretization)
- 3. Makine Öğrenmesinin Ana Başlıkları
- 4. Sınıf Sayısı ve Başarı
- 5. Sınıflandırıcıların Karar Verme Hızı: Karar Ağacı ve Naive Bayes
- 6. Mobil Bir Uygulama Örneği: Akıllı SMS Kutusu
- 7. SVM ile Çok Sınıflı Sınıflandırma
- 8. k-NN'de k Seçimi ve ROC Eğrisi
- 9. Dengesiz Veri ve Accuracy
- 10. Regresyon ve Regresyon Metrikleri
- 11. Kümeleme: K-Means, Dirsek Yöntemi, GMM ve Hiyerarşik Kümeleme
- 12. Birliktelik Kuralları, Boyut İndirgeme ve Pekiştirmeli Öğrenme
- 13. Topluluk Öğrenme ve Hiperparametreler
- 14. Yarı Gözetimli Öğrenme ve Anomali Tespiti
- 15. Yapay Sinir Ağları ve Derin Öğrenme
- 16. Derin Öğrenmenin Hiperparametreleri
- 17. Mobil Teknolojilerle Bağlantı

## 1. Önceki Haftanın Hatırlatması: Özellik ve Örnek Seçimi

Bir önceki hafta veri hazırlama (data preparation) ayrıntılı işlenmiş, son olarak özellik seçimi (feature selection) ve örnek seçimi (instance selection) konuşulmuştu. Hoca özellik seçimini kısaca hatırlattı. $M$ özellik varsa boş olmayan alt küme sayısı $2^M-1$'dir ve en uygun alt kümeyi bulmak için bunların hepsini denemek çok maliyetlidir. Bu yüzden filter ve wrapper yöntemleri kullanılır. Wrapper yöntemleri bir özellik alt kümesinin o probleme özgü başarıya katkısını doğrudan ölçer. Daha maliyetlidir ama o problemde daha yüksek başarı sağlar.

## 2. Ayrıklaştırma (Discretization)

### 2.1 Ne işe yarar?

Ayrıklaştırma sürekli verileri kategorik verilere dönüştürür. Hoca slayttaki küçük şekli anlattı: kartezyen düzlemde farklı noktalarda örnekler (instance) vardır. Her örneğin koordinat değerini tek tek kullanmak yerine düzlem bölgelere ayrılır, yeni gelen örnek hangi bölgedeyse o bölgenin etiketi özellik olarak kullanılır. Şekilde altı bölge vardır (ekrandan, 00:15:00).

Slayttaki ilkeler şunlardır (ekrandan, 00:15:00):

- Sayısal (sürekli olsun ya da olmasın) özelliklerin değer aralığı aralıklara bölünür.
- Aralıkların etiketleri saklanır.
- Birliktelik kuralları ve yalnızca ayrık veri kabul eden bazı sınıflandırma algoritmaları için zorunludur.

Slayttaki tablo yaş ile araba sahibi olma bilgisini gösterir ve yaşı üç aralığa ayırır (ekrandan, 00:15:00):

| Yaş | 5 | 6 | 6 | 9 | ... | 15 | 16 | 16 | 17 | 20 | ... | 24 | 25 | 41 | 50 | 65 | ... | 67 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Araba sahibi | 0 | 0 | 0 | 0 | ... | 0 | 1 | 0 | 1 | 1 | ... | 0 | 1 | 1 | 1 | 1 | ... | 1 |

Ortaya çıkan aralıklar: AGE $[5,15]$, AGE $[16,24]$, AGE $[25,67]$.

Hoca günlük örnekler de verdi. Yaş 0-10, 10-20, 20-30 diye bölünebilir. Kimi uygulamalar 25-34, 35-44 diye, kimileri 18-25, 25-40, 40-55 diye böler. Hangi bölmenin kullanılacağı probleme bağlıdır.

### 2.2 Neden ayrıklaştırırız?

Hoca soruyu sınıfa yöneltti. Bir öğrenci, özellik uzayını küçültmenin faydalı olabileceğini söyledi. Hoca bunu genişletti. Uzay büyük olduğunda ayrıntı bilgi bir yerde toplanamaz ve kaybolur. Değerler bir arada olmadığı için ağırlık etkisi de oluşmaz. Bölgeler ayrılınca bu etki ortaya çıkar. İşlem yalnız sayısal veride değil kategorik veride de yapılabilir: sokak yerine ilçe, ilçe yerine il kullanmak ya da bir kişinin bebek mi, çocuk mu, genç mi olduğuna bakmak problemin doğasını değiştirebilir.

Hocanın COVID örneği: 63 yaş ile 43 yaşın tek tek bir etkisi yoktur, ama yaş aralıklarının belirgin bir etkisi vardır. Yaş ham haliyle verilirse sistem yine bir şey öğrenir, ama aralığın etkisi daha zayıf kalır ve karar verirken daha az belirleyici olur. Bu yüzden değerleri etkili aralıklara sıkıştırmak önemlidir.

**Soru:** Aralıkların sınırlarını nasıl belirleriz? Neden bir yerde 25-40, başka yerde 35-44 kullanılıyor?
**Cevap (öğrenciler ve hoca):** Verinin ne kadar yayıldığına (standart sapma) ve kaç gruba ihtiyaç olduğuna bakılır. Grupların alanda önceden bilinen bir anlamı varsa (COVID'deki risk yaşları gibi) sınırlar ona göre seçilir. Ön denemelerle kaç grup gerektiği ve nereden bölüneceği de çıkarılabilir.

### 2.3 Ayrıklaştırma süreci

Slayttaki akış şöyledir (ekrandan, 00:15:00):

```text
Sürekli özellik
  -> Sıralama (Sort Attribute)
  -> Aday kesme noktası ya da komşu aralıkları seçme (Obtain Cut Point or Adjacent Intervals)
  -> Değerlendirme (Perform Evaluation): uygun ölçütü çalıştır
  -> Ölçüt sağlandı mı? Hayır ise kesme noktası seçimine dön
```

İlk adım değerleri sıralamaktır. Sonra farklı yaklaşımlar kullanılabilir: kutulara (bin) ayırmak ya da %25, %50, %75, %100'lük yüzdeliklere ayırmak. Hoca önemli olanın ayrıklaştırma sonunda başarının olumlu yönde etkilenmesi olduğunu, bunun da değerlendirmede ölçüt olarak kullanıldığını vurguladı.

### 2.4 Gözetimsiz ayrıklaştırma: eşit genişlik ve eşit frekans

Eşit genişlikte (equal width) aralıklar aynı uzunluktadır. Hocanın gösterdiği örnekte aralıklar 64-67, 67-70, 70-73, ... diye üçer birimlik eşit mesafelerle bölünmüştü. Eşit frekansta (equal frequency) her aralığa yaklaşık aynı sayıda örnek düşer, örneğin her aralıkta dörder eleman. Bu yaklaşımda son aralık tam denk gelmeyebilir. <!-- BELİRSİZ: Eşit genişlik/eşit frekans slaytı karelere düşmedi; aralık değerleri altyazıdan alındı. Altyazıda dördüncü aralık "70-76" diye geçiyor; eşit genişlik mantığına göre büyük olasılıkla 73-76'dır. -->

Hoca ayrıklaştırma için çok daha farklı yöntemler olduğunu ve bakmakta fayda olduğunu söyledi. Bu derste vurgulamak istediği iki şey vardı: sınırlar belli yaklaşımlar gözetilerek belirlenmelidir ve ayrıklaştırma bir veri ön işleme adımıdır. Başarıya etkisi farklı algoritmalarla ölçülebilir.

Veri hazırlama bölümü slayttaki özetle kapandı (ekrandan, 00:20:00). Veri ön işleme veri madenciliği için büyük bir konudur. Veri hazırlama (temizleme, kusurlu veri, dönüştürme) ile veri indirgeme ve dönüştürmeyi içerir. Birçok yöntem geliştirilmiştir ama hâlâ aktif bir araştırma alanıdır. Veri madenciliği algoritmaları ile veri hazırlama yöntemlerinin birlikte çalışması da ilgi çekici bir alandır.

## 3. Makine Öğrenmesinin Ana Başlıkları

Hoca makine öğrenmesinin kaç ana alt başlığı olduğunu sordu. Öğrencilerle birlikte beş başlık toplandı: gözetimli öğrenme, gözetimsiz öğrenme, pekiştirmeli öğrenme, yapay sinir ağları ve derin öğrenme, topluluk (ensemble) öğrenme. Bir öğrenci regresyonu önerdi. Hoca regresyonun gözetimli öğrenmenin altında olduğunu söyledi.

Hoca bu yapıyı bir zihin haritasıyla gösterdi (ekrandan, 00:25:00):

- **Gözetimli öğrenme (Supervised Learning)**
  - Sınıflandırma: Logistic Regression, SVM, Decision Trees, Naive Bayes, K-NN
  - Regresyon: Linear Regression, Polynomial Regression, Ridge/Lasso Regression
- **Gözetimsiz öğrenme (Unsupervised Learning)**
  - Kümeleme: K-Means, DBSCAN, Agglomerative, Mean Shift, Fuzzy C-Means
  - Birliktelik kuralı öğrenme: FP Growth, Eclat, Apriori
  - Boyut indirgeme: t-SNE, PCA, LSA, SVD, LDA
- **Pekiştirmeli öğrenme (Reinforcement Learning):** Q-Learning, DQN, SARSA, Genetic Algorithm, A3C
- **Topluluk öğrenme (Ensemble Learning)**
  - Stacking
  - Bagging: Random Forest
  - Boosting: XGBoost, LightGBM, AdaBoost, CatBoost
- **Yapay sinir ağları ve derin öğrenme (Neural Networks and Deep Learning):** CNN (DCNN), RNN (LSTM, GRU, LSM), GAN, Autoencoders (seq2seq), Perceptrons

Gözetimli öğrenmede iki temel yaklaşım vardır. Sınıflandırma ayrık tahmin yapar (sınıflar), regresyon sürekli değer tahmin eder.

## 4. Sınıf Sayısı ve Başarı

Hoca öğrencilere en fazla kaç sınıflı bir problemle uğraştıklarını sordu. Cevaplarda iki ile yaklaşık 16 arasında sınıf sayıları ve sınıf yerine sürekli değer tahmin eden regresyon problemleri geçti.

Hoca soruyu şu noktaya bağladı. Bu tür problemlerde sınıf sayısı genelde yüksek değildir, çoğu zaman 10'un altındadır. Sınıf sayısı arttıkça başarı kendiliğinden düşmeye başlar, çünkü birbirine benzeyen sınıflar ortaya çıkar ve ayırt etmek zorlaşır.

Gerçek hayatta bazı problemlerde sınıf sayısı sabittir, ama zamanla artan sınıflar da olabilir. Örneğin ağ güvenliğinde saldırı tipi tespitinde yeni bir saldırı türü çıkması yeni bir sınıf demektir. Sisteme öğretilmemiş bir sınıfı tahmin etmek pek mümkün değildir. Bu durumda "beş sınıf ve diğerleri" şeklinde çalışılır. Bilinen beş sınıfa benzemeyen örnek "diğerleri"ne atılır. Zamanla yeni bir sınıf belirginleşirse örnekleri etiketlenir ve sisteme öğretilir.

Aktivite tanımada basit aktiviteler (yürüme, koşma, oturma, yatma) 7-8 sınıf iken, karmaşık aktivitelere geçince (diş fırçalama, araba kullanma, gitar çalma, müzik dinleme, bulaşık yıkama, çamaşır yıkama, evi süpürme) sınıf sayısı 20-30-40'a çıkabilir. Hedef de budur: daha önce konuşulan ortam zekâsı (ambient intelligence) kapsamında insanın aksiyonlarını mümkün olduğunca anlamak, böylece akıllı sistemlerin daha net karar vermesini sağlamak.

> **Hocanın vurgusu:** Az sınıflı problemlerde başarı belli bir noktaya gelmiştir. Sınıf uzayı geniş problemlerde başarıyı artırmak her zaman daha zordur ve farklı, ek çözümler gerektirir.

## 5. Sınıflandırıcıların Karar Verme Hızı: Karar Ağacı ve Naive Bayes

### 5.1 Hangisi en hızlı karar verir?

Hoca zihin haritasındaki sınıflandırıcılardan (k-NN, Naive Bayes, lojistik regresyon, SVM, karar ağacı) hangisinin çalışma (karar verme) sırasında en hızlı olduğunu sordu. Burada eğitim değil test hızı kastediliyordu. Öğrenciler karar ağacını önerdi. Hoca doğrudan cevap vermenin kolay olmadığını, önce zaman karmaşıklığını hangi parametrelerin etkilediğini konuşmak gerektiğini söyledi. Genelleme yapılırsa bu cevap kabul edilebilir.

### 5.2 Karar ağacında test süresi

Öğrenciler karar ağacında süreyi etkileyen etkenler olarak özellik sayısını, özelliklerin entropilerini ve dağılımını, ağacın dallanma miktarını saydı. Hoca en kritik etkenin ağacın derinliği olduğunu söyledi. Ağaç ne kadar derinse o kadar çok karar düğümünden geçilir.

**Soru:** $n$ örnek sayısı, $d$ özellik sayısı olsun. En kötü durumda ağacın derinliği neye eşittir?
**Cevap:** Öğrenciler önce $n$ ve $\log_2 n$ önerdi. Hocanın beklediği cevap $d$'dir, yani özellik sayısı. Karar her düğümde bir özelliğe göre verilir (örneğin 45 yaşından büyükler sağa, küçükler sola). En kötü durumda ağaç tek tarafa yığılır ve $d$ adım gitmek gerekir. Bu, istenmeyen dengesiz (unbalanced) ağaçtır. Pratikte böyle bir ağaç zor oluşur, genelde daha dengeli ağaçlar çıkar.

Hocaya göre bu yüzden karar ağacı, özellik sayısının çok olduğu birçok problemde karar verme hızı bakımından avantajlıdır.

> **Ders sonrası not:** Hocanın "en kötü durumda derinlik $d$" ifadesi her özelliğin bir yolda en çok bir kez kullanıldığı kategorik özellikler için geçerlidir. Sayısal özelliklerde aynı özellik farklı eşiklerle aynı yolda tekrar kullanılabildiği için derinlik büyük olasılıkla $d$ ile sınırlı değildir ve en kötü durumda $n-1$'e kadar çıkabilir.

Karar ağaçlarının farklı türleri vardır. En yaygın kullanılanı literatürde C4.5 diye geçen, Weka'da J48 adıyla bulunan algoritmadır. Algoritmanın standart parametreleri değiştirilince ağacın karar verme biçimi de değişir.

### 5.3 Naive Bayes

Karar ağacı özelliklerin entropilerini kullanarak dallanır. Hoca bunu COVID örneğiyle tekrarladı: 45 yaşından büyük olanlar, şeker hastaları, hamileler riskli gruba girer. Naive Bayes ise olasılıksal bir sınıflandırıcıdır. Bir örneğin bir sınıfa ait olma olasılığını hesaplar. Bunun için eğitim setindeki verilerin dağılımlarına ve istatistiklerine bakar, dağılım parametrelerinin değerlerini çıkarır. Yeni bir örneğin değerleri bu formüle yerleştirilir ve olasılık hesaplanır.

**Soru:** Olasılığı her sınıf için ayrı ayrı mı hesaplarız?
**Cevap:** İki sınıflı problemde tek bir hesap yeter. Örneğin telefona gelen bir mesajın spam olma olasılığı hesaplanır ve bir eşikle karar verilir. İki sınıfta bir tarafın ağır basması, yani olasılığın 0,5'ten büyük olması karar için yeterlidir. Çok sınıflı problemlerde olasılıklar dağılır (0,4, 0,3 gibi) ve genelde en yüksek olasılıklı sınıf seçilir.

## 6. Mobil Bir Uygulama Örneği: Akıllı SMS Kutusu

Hoca spam örneğinden yola çıkarak bir parantez açtı: SMS'te bir mesajın spam olduğuna hangi bilgilerle karar verilir?

Öğrencilerin önerileri şunlardı: gönderenin daha önce kaç kez spam olarak bildirildiği; reklam mesajlarının sonundaki zorunlu "B" ile başlayan kod; gönderen firmanın telefon numarası; internette "olası dolandırıcılık" diye işaretlenmiş numaraların sorgulanması.

Hoca bunları şöyle topladı. E-postada eskiden içerik analiz edilirdi. Spam mesajlar basit olduğu için büyük harf kullanım sıklığı ve belli kelimelerle eşleşme gibi özelliklerle karar verilirdi. SMS'te de aynı yöntem birçok noktada işe yarar. Ama telefonda daha katı kararlar verdiren başka bakış açıları da vardır:

- Gönderenin rehberde olup olmaması.
- Beyaz liste (white list) ve kullanıcının eklediği kara liste (black list). Bu çok basit kontrol mesajların önemli ölçüde ayrışmasını sağlar.
- Numaranın bir API üzerinden sorgulanması.
- İçerikte düzenli ifadeler (regular expression) kullanmak. Belli ifadelerin, örneğin mesaj sonundaki kodun, geçip geçmediği bir özellik uzayına dönüştürülerek karar verilebilir.

Hoca bu örneği şunun için anlattığını söyledi: herkesin aklına gelebilecek basit bir çözüm, yapı doğru tasarlanınca telefonun karar sürecini hızlandırır ve başarıyı artırır.

**Soru:** Mesajları yalnız spam/spam değil diye mi ayırmak isteriz, yoksa başka kategoriler de olabilir mi?
**Cevap:** Bir öğrenci banka bildirim kodları, kargo bildirimleri ve kamu kurumlarının duyuruları gibi kategoriler önerdi. Hoca tam bu noktaya gelmek istediğini söyledi. Hoca öğrencileriyle akıllı bir SMS kutusu tasarlamıştı. İlk çalışma daha basit bir mantıkla yapılmıştı. Sonra mesaj kategorileri çoğaldı: bankalardan gelen tek kullanımlık şifreler (OTP), özellikle pandemide artan sipariş/kargo bildirimleri, reklamlar, son kullanma tarihli puan bildirimleri. Bu mesajları arka arkaya gelen bir SMS kutusunda takip etmek zordur. Çalışmada mesajlar yaklaşık 5-6 kategoriye ayrıldı, bugün bu sayı daha da artmıştır. Yöntem olarak Naive Bayes ve karar ağacı gibi yaklaşımlar beyaz liste/kara liste yaklaşımıyla birleştirildi. Ortaya saf gözetimli öğrenme yerine hibrit bir model çıktı.

> **Hocanın vurgusu:** Telefon ve akıllı saatler söz konusuysa hibrit yaklaşımlar her zaman daha az karmaşık ve daha az enerji tüketen yaklaşımlardır. Mobil telefonda çok basit bir problemi ele alarak insanların hayatını kolaylaştırmak mümkündür.

## 7. SVM ile Çok Sınıflı Sınıflandırma

Destek vektör makinesi (SVM) genelde iki sınıflı problemler için kullanılır. Sınıfları ayıran bir sınır, yani bir hiperdüzlem çizer.

Bir öğrenci iki boyuttaki ayırıcı çizgiden yola çıkarak üç sınıf için üç boyutlu bir ayrım gerektiğini düşündü. Hoca bunu düzeltti: iki boyutta görülen doğru aslında bir hiperdüzlemin özel halidir. $n$ boyutlu bir uzayda çizilen bir hiperdüzlem düşünülmelidir. Sınıf sayısı ile uzayın boyutu arasında böyle bir bağ yoktur.

**Soru:** İkili bir sınıflandırıcı olan SVM'yi çok sınıflı problemde nasıl kullanırız?
**Cevap:** İki yaklaşım vardır:

- **Bire-karşı-hepsi (one versus all):** Önce "A sınıfı mı, diğerleri mi?" diye bakılır. Diğerlerine düştüyse "B mi, diğerleri mi?" diye devam edilir.
- **İkili karşılaştırma:** Sınıflar ikişer ikişer karşılaştırılır. A ile B, C ile D karşılaştırılır, kazananlar kendi aralarında karşılaştırılır. Bir öğrenci bunu turnuva yöntemine benzetti, hoca da onayladı.

Bir öğrenci ikinci yöntemin maliyetli olup olmadığını sordu. Hoca karmaşıklığın sınıf yapısına göre tartışılacağını söyledi. Bire-karşı-hepsi yaklaşımında beş sınıf için en kötü durumda dört adımda, genel olarak $M-1$ adımda sonuca gidilir. İkili karşılaştırma bir ağaç gibi ilerler ve paralel dallar vardır. Ağaçtaki bütün karşılaştırmalar toplandığında yine $M-1$'e denk gelir, bu yüzden hocaya göre iki yaklaşımın karmaşıklığı değişmez. Problemde olasılığı yüksek, yani daha sık görülen bir sınıf varsa tasarım ona göre yapılabilir (o sınıf önce sınanır).

> **Ek bilgi (derste anlatılmadı):** Yaygın uygulamada bire-karşı-hepsi $M$ ikili sınıflandırıcı eğitir ve testte hepsinin skorunu karşılaştırıp en yükseğini seçer. Bire-bir (one-vs-one) ise $M(M-1)/2$ sınıflandırıcı eğitir; testte ya hepsi oylanır ya da turnuva/DAG yapısında $M-1$ karşılaştırma yapılır. Beş sınıf için bu sayılar 5 ve 10'dur.

## 8. k-NN'de k Seçimi ve ROC Eğrisi

### 8.1 k-NN'nin karmaşıklığı ve k değeri

k-NN'ye daha önce kısaca değinilmişti. k-NN'de eğitim yoktur, yalnız test karmaşıklığı vardır. Test karmaşıklığını örnek sayısı ve özellik sayısı belirler. k da etkiler, ama k'nın alabileceği değerler sınırlıdır.

**Soru:** k genelde kaç seçilir?
**Cevap:** Genelde tek sayı seçilir. k = 1 seçilirse algoritma en yakın komşu (nearest neighbor) olur. Genelde 3, 5 ve 7 kullanılır, 9 ve 11 seyrektir. Hoca 13-15 gibi değerleri hiç görmediğini söyledi. Tek komşuya bakmak risklidir, çünkü tesadüfen bir veri o örneğin en yakınında bulunuyor olabilir. Topluluk öğrenme bakış açısıyla çevredeki komşuların çoğunluğuna bakmak (3'ten, 5'ten en fazla olan) daha doğru karar verdirir. Dağılım iyiyse en yakın komşu da iyi sonuç verebilir, ama hocaya göre en iyi sonuç üreten iki değer 3 ve 5'tir.

### 8.2 En iyi k nasıl seçilir: ROC eğrisi

k = 1, 3, 5, 7 için sonuçlar üretildiğinde en iyisini seçmek için accuracy kullanılabilir, ama daha iyi fikir veren bir grafik vardır. Öğrenciler önce dirsek yöntemini önerdi. Hoca dirsek yönteminin K-Means kümelemesinde kullanıldığını, aradığının ona benzeyen ama ters yönde (kolun aşağıdan başlayıp dirseğin yukarıda olduğu) bir eğri olduğunu söyledi. Doğru cevap ROC eğrisidir.

Hoca ROC eğrisini tablette çizdi (ekrandan, 01:15:00). X ekseni yanlış pozitif (FP) oranı, Y ekseni doğru pozitif (TP) oranıdır. Eğri üzerinde k = 1, 3, 5, 7, 9, 11 için elde edilen noktalar işaretlenir.

**Soru:** Bu noktalardan hangisini seçersiniz?
**Cevap:** Öğrenciler 5 ya da 7 dedi. Hoca dirsek mantığındaki gibi eğimin artışının düzleştiği noktanın önemli olduğunu söyledi. 5'ten 7'ye geçerken TP oranı pek artmamış, ama FP oranı çok artmıştır. Bu yüzden 5'i seçmek akıllıcadır.

Eğrinin altında kalan alan ne kadar büyükse o kadar iyidir. Teorideki en iyi sonuç TP oranının 1, FP oranının 0 olduğu noktadır, yani %100 başarı. Hoca bunu ayrı bir grafikte sol üst köşeden geçen basamak şeklinde çizdi (ekrandan, 01:15:00). Pratikte bu olmaz. 45 derecelik köşegenin üstüne çıkan eğriler istenen eğrilerdir. Hoca köşegenin üstünde üç farklı eğri çizip (1, 2, 3) hangisinin daha iyi olduğunu sordu. En dıştaki 1 numaralı eğri, yani sol üst köşeye en yakın olanı, en avantajlıdır.

> **Hocanın vurgusu:** ROC eğrisi farklı parametrelerin başarıya etkisini incelerken en sık kullanılan yöntemlerden biridir. TP ile FP arasındaki ödünleşimi (trade-off) gösterir ve bu ödünleşime göre karar vermek akıllıcadır.

### 8.3 Sahtekârlık tespitinde yanlış pozitifler

Grafikte k = 11 çok yüksek bir TP oranı vermiştir, ama FP oranı çok kötüdür. Sistem doğruların hepsini bilir, ama yanlış olanların bir kısmını da doğruymuş gibi gösterir. Hoca bunun sahtekârlık (fraud) tespitinde sık görüldüğünü anlattı. Bankacılıkta sahtekârlık tespit oranları (TP oranı) yüksektir, %90'ın üzerinde, %95 civarındadır. Ama işlem sayısı çok fazladır.

Hocanın sayısal örneği (derste sözlü, 01:13:21):

- Verilen: günde yaklaşık 15 milyon işlem, %1 yanlış pozitif oranı.
- İşlem: $15\,000\,000 \times 0{,}01 = 150\,000$.
- Sonuç: Günde 150 bin işlem sanki sahtekârlıkmış gibi sistem tarafından işaretlenir.

Müşteriye gelen "şöyle bir işlem yaptınız, size ait değilse bize ulaşın" mesajları aslında bu yanlış pozitiflerdir. Olası sahtekârlıkları inceleyen ve insanların çalıştığı ekipler vardır. Hedef yanlış pozitif sayısını azaltmaktır. Bu yüzden biraz feragat edilip k = 5 gibi bir nokta seçilir: TP oranı belli bir seviyede tutulurken FP oranı düşürülür.

### 8.4 Düşme tespitinde eşik seçimi

Hoca daha önce anlattığı akıllı telefonlarla düşme tespitine döndü. Eşik (threshold) yöntemiyle çalışan bir düşme tespiti için ROC eğrisi çizilirse eğri üzerindeki noktalar eşik değerleri olur. Tablette işaretlenen değerler 1,3; 1,5; 1,7; 2,1 ve 2,5'tir. Hoca 1,7 ve 2,1'i daire içine aldı (ekrandan, 01:25:00). Eşiğin 1,7 ya da 2,1 olmasına karar verip kullanılan parametrenin başarıya etkisi ROC eğrisiyle değerlendirilebilir.

## 9. Dengesiz Veri ve Accuracy

Accuracy karar vermede bir ölçüt olarak kullanılabilir, ama risklidir. Veri dengesiz (imbalanced) olabilir, yani sınıflarda eşit sayıda örnek olmayabilir.

**Soru:** Dengesiz verinin sıkıntısı nedir?
**Cevap (bir öğrenci):** Çok örnekli sınıflarda başarı yüksek olabilir. Az örnekli bir sınıfta, örneğin iki örnek varsa, birini yanlış bilmek o sınıfta %50 hata demektir, ama bu genel başarıda görünmez.

Hoca bunu şöyle özetledi: az örnekli sınıfların başarıya etkisi "arada kaynar" ve accuracy bunu göstermez. Hocanın örneği (derste sözlü, 01:16:34):

- Verilen: 1 milyon normal işlem (hepsi doğru bilinmiş), 100 sahte işlem (50'si doğru bilinmiş).
- Accuracy: $\dfrac{1\,000\,000 + 50}{1\,000\,100} \approx 0{,}99995$, yani %99,9'un üzerinde.
- Sahtekârlık sınıfındaki başarı: $50/100 = $ %50.

> **Ders sonrası not:** Hoca accuracy için "%99,9" dedi; python ile hesaplanan değer yaklaşık %99,995'tir. Sonuç değişmez: accuracy neredeyse kusursuz görünürken asıl ilgilenilen sınıftaki başarı yalnızca %50'dir.

> **Hocanın vurgusu:** Dengesiz veri problemlerinde accuracy kullanmaktan kaçınmak gerekir. Bunun yerine precision, recall ve F-ölçütü (F-measure) gibi metrikler kullanılmalıdır.

## 10. Regresyon ve Regresyon Metrikleri

Regresyon sürekli değerleri tahmin etmek için kullanılır. Doğrusal regresyon en çok istenen problem türüdür, ama gerçekte çoğu zaman yetmez. Polinomsal regresyonda $x^3$, $x^5$, $x^7$ gibi terimlerle bir eğri oturtulur. Genelleştirilebilir olması için polinomun derecesinin düşük olması önemlidir. Hoca $x^{13}$ gibi bir terim varsa bunun sıkıntılı olduğunu, genelde aşırı öğrenmeye (overfitting) götürdüğünü söyledi.

Regresyonun metrikleri sınıflandırmanınkilerden farklıdır. Öğrencilerle birlikte şunlar sayıldı:

- Ortalama kare hata (MSE)
- Kök ortalama kare hata (RMSE): kare hataların ortalamasının karekökü
- Ortalama mutlak hata (MAE)
- Ortalama mutlak yüzde hata (MAPE): farkın karesini almadan, gerçek değere oranlayarak hesaplanır

> **Ek bilgi (derste anlatılmadı):** $y_i$ gerçek, $\hat{y}_i$ tahmin değeri olmak üzere $\text{MSE}=\frac{1}{n}\sum (y_i-\hat{y}_i)^2$, $\text{RMSE}=\sqrt{\text{MSE}}$, $\text{MAE}=\frac{1}{n}\sum |y_i-\hat{y}_i|$, $\text{MAPE}=\frac{100}{n}\sum \left|\frac{y_i-\hat{y}_i}{y_i}\right|$ olarak tanımlanır.

Trafik akış hızı tahmini de bir regresyon problemidir ve bu metrikler kullanılır.

> **Hocanın vurgusu:** Trafik akış hızı tahmininde MAE ile MAPE'yi birlikte kullanmak çok kritiktir.

Hocanın örneği (derste sözlü, 01:19:21): Gerçek hız 30 km/sa iken 6 km/sa sapmak $6/30 = $ %20 hata, 60 km/sa iken 6 km/sa sapmak $6/60 = $ %10 hatadır. Mutlak hata ikisinde de 6'dır, yüzde hata ise farklıdır.

**Soru:** MAE mi kullanmak akıllıca, MAPE mi?
**Cevap (bir öğrenci ve hoca):** Hız düştükçe tahmindeki sapmanın önemi artar. Trafik sıkışıkken 10 ile 20 km/sa arasındaki fark büyüktür; yol açıkken 80 ile 90 km/sa arasındaki fark pek önemli değildir. Öğrenci farklı bir metrik ya da ters orantılı bir ağırlıklandırma gerektiğini düşündü. Hoca bunu ayrıklaştırmaya bağladı: düşük hızlar daha yüksek çözünürlükle kategorilere ayrılır. Örneğin 10-20, 20-30, 30-40 ayrı kategorilerken 40-60, 60-80, 80-120 daha geniş kategoriler olur. Trafik haritalarındaki renkler (çok koyu kırmızı, kırmızı, turuncu, sarı, koyu yeşil, açık yeşil) bunun bir karşılığıdır ve kırmızı tarafında bir yoğunlaşma vardır. Metrikleri genel halleriyle kullanmak önemlidir, ama problemin özelliğine göre uyarlamak gerekir.

## 11. Kümeleme: K-Means, Dirsek Yöntemi, GMM ve Hiyerarşik Kümeleme

### 11.1 K-Means ve doğru k

Gözetimli öğrenmede etiketli bilgi vardır. Etiketli bilginin olmadığı durumlar gözetimsiz öğrenmenin konusudur. Hoca önceki haftalarda K-Means ile k-NN'nin karıştırıldığını hatırlattı. K-Means gözetimsiz bir kümeleme algoritmasıdır. Veriyi gruplamak için önceden bir k (küme sayısı) verilir ve veriler birbirlerine yakınlıklarına göre gruplanır. Ama küme sayısı bilinmeden verildiği için doğru k'nın verilip verilmediği bilinmez.

Bir öğrenci X-Means adlı, k'yı kendisi bulan bir algoritmadan söz etti. Hoca bunu doğruladı, ama K-Means özelinde teorik yolu anlattı: dirsek (elbow) yöntemi.

### 11.2 Dirsek yöntemi

**Soru:** Dirsek grafiğinde X ve Y eksenlerinde ne vardır?
**Cevap:** X ekseni küme sayısı k'dır. Öğrenciler Y ekseni için önce varyansı, sonra toplam uzaklığı önerdi. Doğru cevap toplam uzaklıktır, başka bir deyişle hata (error): her örneğin kendi kümesinin merkezine olan uzaklığı (ekrandan, 01:30:00).

**Soru:** Hangi koşulda hata sıfır olur?
**Cevap:** k örnek sayısına eşitse, yani her örnek kendi başına bir küme olursa. Hoca tahtaya "k = instance number" yazdı (ekrandan, 01:30:00).

Grafiğin başı (k = 1) tüm verinin tek bir küme olduğu durumu gösterir ve hata en büyüktür. Aranan nokta hatanın çok hızlı düştüğü bölgenin bittiği noktadır. O noktadan sonra sistem oturmuştur, hata artık çok az azalır ve yeni kümelere ayırmak gerekmez. O noktanın etrafındaki değerler olası küme sayısı, yani optimum k olarak değerlendirilmelidir.

Dirsek her zaman böyle keskin çıkmaz. Tahtada farklı biçimli eğriler çizildi (ekrandan, 01:30:00). Hata yavaş yavaş azalıyorsa hangi noktanın seçileceğine karar vermek kolay değildir. Dirsek ne kadar keskinse tahmin o kadar güvenilirdir. Dirsek ne kadar yayılmışsa küme sayısının o aralıktaki değerlerden biri olma olasılığı o kadar yüksektir.

### 11.3 Kümeleri düzeltmek

**Soru:** k belirlendi, kümeler oluştu ama içimize sinmedi. Üzerinden bir kez daha geçmek istersek neye bakarız?
**Cevap:** Bir öğrenci uzaklık ölçüsünü değiştirmeyi önerdi. Hocanın kastettiği başkaydı. Kümelerin üzerinden bir kez geçilir. Merkezleri birbirine belirlenen bir eşikten daha yakın olan kümeler varsa birleştirilir. Bazen bir grup veri tek bir küme oluşturur, ama kendi içinde iki-üç alt gruba ayrılmıştır. Bunları birleştirip tek küme yapmak akıllıcadır.

> **Hocanın vurgusu:** Kümeleme ile çalışırken oluşan kümelerin birleştirilebilir olma ihtimali mutlaka göz önünde bulundurulmalıdır.

Bir öğrenci başlangıç noktalarının da sonucu çok etkilediğini, birden fazla başlangıçla çalıştırıp topluluk öğrenme mantığıyla en kararlı sonucu almanın mümkün olduğunu ekledi. Hoca bunun dikkat edilmesi gereken bir diğer nokta olduğunu söyledi. Küme merkezlerinin başlangıç (seed) noktaları çok rastgele seçilir ve doğru olmazsa kümelerin dağılımı da sorunlu olur. Başlangıç merkezleri genelde eldeki örneklerden seçilir ve daha akıllıca noktalar seçerek başlamak tercih edilir. Hoca bunun nasıl yapıldığına sınavdan önce bakılmasını istedi.

> **Ek bilgi (derste anlatılmadı):** Başlangıç merkezlerini akıllıca seçmenin en bilinen yolu k-means++'tır. İlk merkez örneklerden rastgele seçilir; sonraki her merkez, örneklerin mevcut en yakın merkeze uzaklığının karesiyle orantılı olasılıkla seçilir. Böylece merkezler birbirinden uzak başlar.

### 11.4 Gauss karışım modeli (GMM)

Hoca K-Means'in gelişmiş bir versiyonu olarak Gauss karışım modelini (Gaussian Mixture Model) tanıttı. X-Means'in de ek özellikleri vardır, ama GMM kümelere karar verirken yapısı gereği farklı bir yol izler. GMM ile kümeleme genelde büyük oranda daha başarılı olur.

**Soru:** K-Means ile GMM arasındaki temel fark nedir?
**Cevap:** Bir öğrenci GMM'nin grupları bir Gauss dağılımına uydurmaya çalıştığını, bunun için dağılım olasılığına baktığını söyledi. Hoca açıkladı: K-Means yalnız ortalama bilgisini kullanır. GMM dağılımın standart sapmasını da kullanır.

Hocanın örneği (derste sözlü, 01:33:30): 1 ve 5 değerli iki elemanın ortalaması $(1+5)/2 = 3$'tür. 4 ve 2 olsaydı ortalama yine 3, 3 ve 3 olsaydı yine 3 olurdu. K-Means bu grupların hepsini merkezi 3 olan aynı küme gibi görür ve standart sapma farkını kaçırır. GMM'de {1, 5} grubu ile {3, 3} grubu arasındaki fark ortaya çıkar. Python ile kontrol: üç grubun ortalaması 3'tür, standart sapmaları (popülasyon) sırasıyla 2, 1 ve 0'dır.

GMM'nin hedefi yalnız merkez noktayı kullanmak değildir. Dağılımın Gauss dağılımına göre olduğu varsayılır ve örneğin o kümede olma olasılığı hesaplanır. Yani örnek doğrudan bir kümeye atanmaz: örneğin bir kümeye 0,8, diğerine 0,2 olasılıkla aittir. Bir eşik belirlenip örnek ilgili kümeye atanır.

> **Hocanın vurgusu:** GMM kümelemede çok işe yarayabilecek bir algoritmadır ve bir örneğin bir kümeye ait olma olasılığını da verir.

### 11.5 Hiyerarşik (agglomerative) kümeleme

Zihin haritasındaki agglomerative başlığı soruldu. Bir öğrenci her elemanın tek başına bir küme kabul edildiğini, sonra uzaklık hesaplama yöntemleriyle kümelerin birleştirile birleştirile ilerlendiğini söyledi. Hoca onayladı ve iki yaklaşım olduğunu söyledi:

- Tepeden başlayıp tüm veriyi tek küme kabul etmek, sonra önce iki kümeye, sonra daha fazla kümeye ayırarak ilerlemek. Bu hiyerarşik bir yapıdır.
- Her elemanı ayrı bir küme kabul edip kümeleri birleştirerek ilerlemek. Her birleştirmede birleşim kümesinin oluşturduğu hata hesaplanır.

## 12. Birliktelik Kuralları, Boyut İndirgeme ve Pekiştirmeli Öğrenme

### 12.1 Birliktelik kuralı öğrenme

Bir öğrenci bunu daha önce konuşulan kural tabanlı yaklaşımla karıştırdı. Hoca birliktelik kuralı öğrenmenin (association rule learning) veriler arasındaki ilişkilerin öğrenilmesi olduğunu söyledi. İkili ilişkilerden söz ediliyorsa ağırlıklı olarak veri madenciliği kastedilir, çünkü veri madenciliği genelde veriler arasındaki ilişkiyi ele alır. Birliktelik kuralı öğrenme veri madenciliğinin altında yer alan bir yaklaşımdır. Gözetimsiz öğrenme de veri madenciliğinde çok sık kullanılır, çünkü etiketli bilginin olmadığı durumlar çoktur.

### 12.2 Boyut indirgeme

Gözetimsiz öğrenmenin son başlığı boyut indirgemedir (dimensionality reduction). PCA ve LDA bir önceki hafta konuşulmuştu. Eldeki özelliklerin sayısını azaltmak için kullanılır ve en önemli algoritmalar PCA ile LDA'dır.

### 12.3 Pekiştirmeli öğrenme

**Soru:** Pekiştirmeli öğrenme nedir, nerede kullanılır?
**Cevap (bir öğrenci):** Etiketli veri kullanmak yerine ödül-ceza mantığıyla öğretmektir. Bir ölçüt belirlenir ve davranışın ödüllendirilmesine ya da cezalandırılmasına buna göre karar verilir.

Hoca tamamladı: Sistem başarılı oldukça ödül alır, puan toplar. Yanlış bir hareket yaptığında ceza ile öğrenir. Bu, insanın öğrenme modeline çok yakındır. Hocanın benzetmesi: sobaya dokunup eli yanan çocuk bir daha dokunmakta tereddüt eder. Deneyimler bazen insanı yanlış öğrenmeye de götürür. Bilgisayar dünyasında bu yaklaşım insan duygularından arındırılmış ve daha iyi bir metodolojiyle tasarlanmıştır.

Robotikte pekiştirmeli öğrenmenin sıkça kullanıldığı konuşuldu. Sistemin tekrar tekrar denemesi gerektiği için yöntem özellikle simülasyonda uygulanabilir. Simülasyonda öğrenilen bilginin gerçek hayata aktarılması da tartışıldı; çok karmaşık olmayan problemlerde bu geçişin büyük sorun çıkarmadığı söylendi.

Konu otonom araçlara uzandı. Simülasyonda dünyanın fiziksel modeli ve koşullar modellenir. Her modellemede yeni bir durum ele alınır: hava durumu, binalar, fiziksel yapılar. Hoca dijital haritaların otonom araçlara önemli katkı sağladığını söyledi. Dijital haritalar oturmadan önce araç yalnız kamera görüntüsünden karar vermek zorundaydı ve çok daha fazla parametre işlenmesi gerekiyordu. Harita önceden tanımlı olunca aracın karar uzayı daraldı. Yollar, şeritler ve binalar ne kadar net tanımlanırsa başarı o kadar artar. Şeritlerin silik ya da hiç olmadığı yollarda ise başka sorunlar vardır. Hoca yoldaki çukur, tümsek, yol çalışması gibi bilgilerin önceden bilinmesi gerektiğini, her şeyin o anki görüntü işleme, lidar ve radarla çözülemeyeceğini söyledi.

## 13. Topluluk Öğrenme ve Hiperparametreler

Zihin haritasına göre genetik algoritma da pekiştirmeli öğrenme başlığının altında yer alıyordu (ekrandan, 02:10:00). Sonraki başlık topluluk (ensemble) öğrenmedir, yani kolektif öğrenme yaklaşımları. Başlıca yöntemler bagging ve boosting'tir.

### 13.1 Random Forest

Bagging'in altında Random Forest vardır.

**Soru:** Random Forest nasıl bir karar mekanizmasına sahiptir?
**Cevap:** Bir öğrenci karar ağacının gelişmiş hali olduğunu söyledi. Hoca açıkladı: Random Forest karar ağacı yaklaşımını kendi içinde kullanır. Farklı ağaçlar üretir ve bu ağaçlardan gelen sonuçları birleştirerek karar verir. Ağaç sayısı bir parametre olarak değiştirilebilir.

Random Forest'ın güçlü bir karar verici olmasının ve birçok problemde üst sıralarda görülmesinin sebebi, ağaç yapısının çok geniş bir yelpazede başarılı bir karar verici olmasıdır. Hoca bunu geniş spektrumlu antibiyotiğe benzetti: hangi problemi yaşarsanız ona iyi gelir. Genelde başarı bakımından ilk üç sırada yer alan bir algoritmadır.

### 13.2 Varsayılan parametrelerle yetinmemek

> **Hocanın vurgusu:** Bu algoritmalar denendiğinde genelde standart parametreleriyle denenir. Oysa derin öğrenmede olduğu gibi bu algoritmaların da hiperparametreleri vardır ve değiştirilerek denenmeleri, sonuçlarının incelenmesi gerekir.

Örneğin Random Forest'ta ağaç sayısını azaltmak başarıyı değiştirmiyorsa daha az ağaçta karar kılınmalıdır. Oysa çoğu zaman Weka'da ya da scikit-learn'de varsayılan değer neyse o kullanılır. Hoca bu konuyu mobil teknolojilerle şöyle ilişkilendirdi: mümkün olduğunca iş yükünü azaltacak parametrelerle yola çıkmak gerekir. Random Forest için hedef varsayılan ağaç sayısı değil, yeterli olan en az ağaç sayısıdır. ROC eğrisinde TP/FP oranına bakılıp optimum nokta seçilebilir. Literatürdeki çoğu çalışma Random Forest ya da SVM kullandığını söyler, ama parametre vermez. Hoca kendi çalışmaları dahil çoğu çalışmada varsayılan değerlerin kullanıldığını, bunun aslında doğru olmadığını, problem özelinde farklı durumların değerlendirilmesi gerektiğini söyledi.

### 13.3 Boosting

Topluluk öğrenme birçok noktada çok başarılı sonuçlar üretir. AdaBoost ve XGBoost da önemli problemlerde başarılı sonuçlar üreten algoritmalardır. Hoca topluluk öğrenmenin mutlaka denenmesi gereken bir yaklaşım olduğunu, makine öğrenmesi dersini almamış olanların özellikle doktora yeterlik sınavına hazırlanırken bu konulara mutlaka çalışmasını, tezinde veri işleme ve öğrenme ile ilgili bir şey yapanların da bunları taraması gerektiğini söyledi.

## 14. Yarı Gözetimli Öğrenme ve Anomali Tespiti

**Soru:** Yarı gözetimli öğrenme (semi-supervised learning) nedir?
**Cevap:** Bir öğrenci verinin bir kısmının etiketli olduğu durum olarak tahmin etti. Hoca doğruladı ve ekledi: Bu kısım genelde tek bir sınıftır. Böyle olmak zorunda değildir, ama genelde verinin yalnız bir tarafı bilinir.

Hocanın örneği: hasta olmayan kişilerin bilgisine sahip olup hastaların bilgisine sahip olmamak. Sistem hasta olmayanlarla eğitilir. Hasta bir kişi geldiğinde bir aykırı değer (outlier) oluşturduğu için fark edilir. Hiç etiketli bilgi yoksa farklı, gözetimsiz bir yöntem uygulamak gerekir.

Burada anomali tespiti (anomaly detection) kavramı devreye girer. Ağ güvenliğinde, ağ saldırı tespit sistemlerinde ve sahtekârlık tespitinde kullanılır. Gözetimli öğrenmede de, yarı gözetimli öğrenmede de uygulanır. Yarı gözetimli yaklaşımda sisteme normal (non-fraud) işlemler öğretilir. Gelen bir işlemin normallerden farklı olduğu ortaya konunca anomali, yani bir tür aykırı değer tespit edilmiş olur. Gözetimsiz öğrenmede de anomali tespit edilebilir: veri iki gruba ayrılır ve küçük grubun büyük olasılıkla sahtekârlık olduğu varsayılır.

Hoca bu kavramları çok kapsamlı bilmeyi beklemediğini, ama ne olduklarından ve hangi durumlarda kullanıldıklarından haberdar olmak gerektiğini söyledi.

## 15. Yapay Sinir Ağları ve Derin Öğrenme

### 15.1 Temel yapı

Yapay sinir ağlarında nöronlar vardır ve her nöron bir fonksiyon uygular: sigmoid, tanh ve diğer aktivasyon fonksiyonları. Hoca aktivasyon fonksiyonlarını bir mantık kapısına benzetti; mantık kapısı bunların basit halidir. Fonksiyona bir değer verilir, o da bir çıktı üretir. Ağırlıklar her adımda değişir. Katman sayısı arttıkça ağın modelleyebildiği doğrusal olmama, yani karmaşıklık artar. Birçok problem tek katmanla ve az nöronla çözülebilir. Ama sinir ağlarından beklenen karmaşık problemleri çözmesidir. Özellikle katman ve nöron sayısı fazlaysa eğitim süreci uzundur.

Farklı tasarlanmış sinir ağları vardır: CNN, RNN, GAN ve otokodlayıcılar. Algılayıcılar (perceptron) ve çok katmanlı algılayıcılar ilk ve daha basit versiyonlardır. Hoca diğerlerini mantık kapılarından entegre devre üretilmesine benzetti: CNN ve RNN çok katmanlı algılayıcıların daha sofistike tasarlanmış halleridir.

### 15.2 CNN ve RNN

CNN özellikle görüntüde çok sık kullanılır ve piksellerin birbirleriyle ilişkisini ortaya koymaya odaklanır. Bunun için görüntü üzerinde gezdirilen çekirdeklerden (kernel) üretilen değerler kullanılır. CNN daha çok uzamsal (spatial) ilişki kurar.

RNN ise zaman ekseninde ilişki kurar. Örneğin aktivite tanımada LSTM ya da GRU kullanmak daha avantajlıdır. Bir hareketin öncesi ve sonrası vardır. RNN hareketin önce ve sonrasındaki bilgileri birlikte öğrenmeyi sağlar. Verilen bilginin bir kısmını saklayıp bir sonraki kapıya (nörona) aktaran bir yapı kurulur ve iki bilgi arasında ilişki kurulmuş olur. CNN ve RNN tabanlı çözümler en çok kullanılan çözümlerdir. GRU ve LSTM farklı tasarımlardır: GRU'da 2, LSTM'de 3 kapı vardır. CNN ve RNN sınıflandırmanın yanında öznitelik çıkarmak için de kullanılabilir.

### 15.3 Otokodlayıcı (autoencoder)

Hoca otokodlayıcıya dikkat çekmek istedi ve ipucu olarak boyut indirgemeyi verdi. Bir öğrenci veri içindeki örüntülerin anlaşılması için kullanıldığını söyledi. Hoca doğruladı: otokodlayıcı verinin göremediğimiz örüntülerini ortaya çıkarmak için kullanılan bir yapıdır.

Yapısı bir sinir ağıdır: girdi katmanı, ara katmanlar ve çıktı katmanı vardır. Girdi ile çıktı birbirine eşitlenir, yani verilen girdinin çıktı olarak geri üretilmesi beklenir. Ara katmanların bunu en az hatayla yapacak şekilde kendini ayarlaması istenir. Örneğin 100 özellik verilir ve çıkışta yine 100 özellik alınmak istenir. Ara katmanlar 75, 50, 25 diye küçültülerek birden fazla katman kurulabilir. Özellik kaça indirilmek isteniyorsa ağ ona göre kurulur. Genelde çok daha büyük özellik sayılarında (1000, 10 000) kullanılır. Örneğin 10 000 özellikten 1000'e inilince problem farklı bir uzayda 1000 özellikle temsil edilebilir.

PCA ve LDA'da da farklı bir uzaya geçiliyordu ve bu dönüşüm örnekler ya da sınıflar arasındaki istatistiksel bilgiye dayanıyordu. Otokodlayıcıda dönüşümü sinir ağı yapısı öğrenir. Hoca üniversitede yapılan bir sunumdaki sloganı aktardı: "Making invisible visible", görünmeyeni görünür kılmak. Otokodlayıcı, elle üretilemeyecek öznitelikleri öğrenmeyi sağlar.

Hocanın deneyimi ilgi çekicidir. Aktivite tanımada pencerelerden üretilen değerlerle otokodlayıcı denenmiş ve yeterince başarı elde edilmemiştir. Ağ saldırılarının sınıflandırmasında, yani daha ayrık/kategorik veriye sahip bir problemde ise daha başarılı sonuçlar vermiştir. Hocaya göre tekrarlı (repetitif) veride otokodlayıcılar çok başarılı olmamış, daha kategorik verilerde daha başarılı olmuştur.

### 15.4 GAN

**Soru:** GAN (Generative Adversarial Network) nedir?
**Cevap (bir öğrenci):** İki ağ vardır. Biri veri üretmeye çalışır, diğeri bu verinin gerçek mi sahte mi olduğuna karar vermeye çalışır. Böylece birbirlerini karşılıklı eğitirler.

Hoca bunu hırsız-polis hikâyesinin sinir ağına uyarlanması olarak anlattı. Üretici (generator) rastgele veri üretir. Amacı gerçek veriden ayırt edilemeyecek düzeyde sentetik veri üretmektir. Ayırıcı (discriminator) üreticinin ürettiği verinin sahte mi gerçek mi olduğunu anlamaya çalışır.

GAN görüntüde de kullanılır, ama hoca daha anlamlı bir örnek verdi: sahtekârlık verileri ve ağ saldırısı verileri çok azdır. Amaç bu verileri gerçek verilere mümkün olduğunca uygun şekilde çoğaltmaktır. Bu alana veri artırımı (data augmentation) denir: az sayıdaki gerçek veriyi, gerçeğe benzeyen sentetik verilerle tamamlamak.

İki ağ arasında bir ödünleşim vardır. Ayırıcının çok iyi ayırt etmesi üreticinin çok kötü ürettiği anlamına gelir. Üreticinin ürettiği her şeyin gerçek kabul edilmesi ise ayırıcının çok başarısız bir "polis" olduğunu gösterir. İkisi de kötü durumdur. Bu yüzden ikisinin dengeli çalışması istenir. GAN'lar genelde iki sınıflı problemler için kullanılır, çok sınıflı problemlerde başka sıkıntılar vardır.

Hedef, örneğin üç-beş veriden yola çıkarak hiç üretilmemiş ama üretilme ihtimali olan gerçekçi veriler üretmek, yani çok iyi taklit eden bir yapı kurmaktır. Önemli değerlendirme ölçütlerinden biri üretilen iki sentetik verinin birbirine benzeme oranıdır. Yeni üretilen her verinin bir öncekine benzerliği çok yüksek olmamalıdır. Yalnız üç değeri değiştirip "yeni veri ürettim" demek gerçekçi değildir. Hocanın grubu en son GAN'larla aktivite tanımada aktivite verisi üretmeye çalışmıştı. Hoca bunun yüksek lisans konusu olarak da güzel bir çalışma alanı olduğunu söyledi.

## 16. Derin Öğrenmenin Hiperparametreleri

### 16.1 Dropout ve düzenlileştirme

Bir öğrenci dropout'u katmanlar arası geçişte bazı nöronların devre dışı bırakılması olarak tanımladı. Hoca bunun gerçek hayattaki bir mantığa dayandığını söyledi: her nöronu etkin kılmak yerine, bazı nöronların rastgele olarak kararda etkisiz kalabileceği prensibi kullanılır. Amaç hem aşırı öğrenmeyi engellemek hem de çözümün genelleştirilebilirliğini sağlamaktır. Dropout'a paralel olarak düzenlileştirme (regularization) da kullanılabilir. İkisi tek tek ya da birlikte kullanılabilir.

### 16.2 Öğrenme oranı ve optimize ediciler

Bir öğrenci öğrenme oranının her iterasyondaki adım büyüklüğünün katsayısı olduğunu söyledi. Başka bir öğrenci bir benzetme yaptı: gözü kapalı bir dağda en çukur noktaya gitmeye çalışıyoruz. Çok büyük adım atarsak minimumu kaçırabiliriz, çok küçük adım atarsak minimuma ulaşmak çok zaman alır.

Hoca onayladı. Öğrenme oranı çok büyük seçilirse global minimum kaçırılabilir. Küçük adımlarla ilerlenirse lokal minimuma (ya da maksimuma) takılma ihtimali doğar ve hedefe uzun sürede ulaşılır. Bu yüzden uygun optimize edicileri seçmekte fayda vardır: Adam, AdaDelta gibi.

### 16.3 Aktivasyon fonksiyonları

**Soru:** Son dönemde en çok tercih edilen aktivasyon fonksiyonu hangisidir?
**Cevap:** Öğrenciler ReLU ve sigmoid dedi. Hoca ReLU'nun bir tık önde olduğunu, sigmoid'in de sık kullanıldığını söyledi. Sigmoid'de verilen değere göre genelde 0-1 aralığında bir değer üretilir. Bu yapıda kaybolan gradyan (vanishing gradient) sorunu oluşabilir. ReLU'da genelde bu sorun görülmez.

### 16.4 Batch boyutu

**Soru:** Batch boyutu neyi söyler?
**Cevap:** Verinin modele belli bloklar halinde verildiği boyutu temsil eder. Güncellemeler bu blokların sonunda yapılır. Veriyi tek tek vermek çok maliyetli ve zaman alıcıdır. Genelde ikinin kuvvetleri olan 64, 128, 256 optimum değerler olarak karşımıza çıkar ve öğrenme daha hızlı olur. Veri büyük bloklar halinde verilirse bellek yetersizliği yaşanabilir. Hoca derin öğrenmede en çok yaşanan sıkıntının bellek yetersizliği olduğunu, görüntüyle çalışırken bunun daha da büyüdüğünü söyledi. Bu yüzden görüntülerde 1024×1024 gibi çok büyük boyutlar pek tercih edilmez, daha çok 256×256 kullanılır.

### 16.5 Epoch sayısı, aşırı öğrenme ve özellik kümesi

**Soru:** Epoch sayısının yeterli olduğuna nasıl karar veririz?
**Cevap:** Bir öğrenci geri çağırma (callback) fonksiyonlarıyla, örneğin belli bir doğruluğa ulaşınca eğitimi kesmeyi önerdi. Hoca bunun mümkün olduğunu, ama böyle bir kontrol yokken grafiğe bakıldığında ne görülmek istendiğini sordu. Cevap yakınsamadır. Eğitim doğruluğu ve doğrulama doğruluğu çizilir. Eğitim doğruluğu genelde daha yüksektir ve bir noktada yakınsaması beklenir. Asıl bakılan doğrulama doğruluğudur. Doğrulama doğruluğu henüz yakınsamadıysa ve iyileşme gösteriyorsa daha fazla epoch ile eğitmek gerekir. Bazen ise doğrulama doğruluğu yakınsamaz, hatta epoch arttıkça kötüleşmeye başlar.

Bu durumun nasıl yorumlanacağı tartışıldı:

- **Eğitim doğruluğu çok yüksek, doğrulama yakınsamıyor:** Bu aşırı öğrenmedir (overfitting). Model eğitim verisini fazla öğrenmiş, test verisine genelleştirilebilir bir yapı kuramamıştır. Hocaya göre bu durumda çok fazla nöron ya da çok fazla katman kullanılıyor olabilir ve bunlarda değişiklik yapmak gerekir.
- **Hem eğitimde hem doğrulamada sorun var:** Model eğitim tarafında da doyuma ulaşamıyorsa, modele ayırt edici, öğrenilebilir bir özellik kümesi verilmemiş demektir. Sorun özellik setindedir.

Nöron sayısı, katman sayısı ve katmanlar arasındaki bağlantı biçimi de hiperparametredir. Örneğin tam bağlantılı (fully connected) ağlar her yerde kullanılmak zorunda değildir. Bir derin öğrenme ağı içinde farklı bağlantı biçimleri kullanılabilir. Transfer öğrenmede başarısını ispatlamış hazır ağ yapıları alınıp başka bir probleme uygulanır. Hoca transfer öğrenmeye ilerleyen haftalarda kısaca değinilebileceğini söyledi.

## 17. Mobil Teknolojilerle Bağlantı

Hoca bu bölümde makine öğrenmesi dünyasına hızlı bir giriş yapıldığını, bilinen bilgilerin hatırlatıldığını ve bilinmeyenlerin gözler önüne konduğunu söyledi. Amacı bu yöntemleri derinlemesine anlatmak değildi; teorileri makine öğrenmesi ve derin öğrenme derslerinde ayrıntılı işlenmektedir. Bu derste kullanım alanları, yani mobil teknolojilerde nerelerde kullanıldıkları ilerleyen haftalarda ayrıntılı konuşulacaktır.

Derin öğrenme maliyetli görünse de mobil tarafta rahatlıkla kullanılabilir. Öğrenme bulutta yapılır, modelin parametreleri buluttan telefona aktarılır ve telefonda yalnız model çalıştırılır. Bu yolla oldukça başarılı sonuçlar elde edilebilir.

Hoca derste sonraki konuları da sıraladı: performans metrikleri, sensör ağları ile IoT'nin kesiştiği noktalar ve farkları, kitle kaynak kullanımı (crowdsourcing) ve uygulamaları, IoT ve büyük veri. Performans metrikleri için karışıklık matrisine, TP/TN/FP/FN'ye ve precision/recall'a önceden bakılmasını önerdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:53): Makine öğrenmesinin ana alt başlıkları nelerdir?

> **Cevap (derste verildi):** Gözetimli öğrenme (sınıflandırma, regresyon), gözetimsiz öğrenme (kümeleme, birliktelik kuralları, boyut indirgeme), pekiştirmeli öğrenme, topluluk öğrenme (bagging, boosting, stacking), yapay sinir ağları ve derin öğrenme.

**Soru 2** (derste sözlü, 00:34:21): $n$ örnek sayısı, $d$ özellik sayısı olmak üzere bir karar ağacının en kötü durumdaki derinliği nedir? Bu, karar verme hızı için ne anlama gelir?

> **Cevap (derste verildi):** Hocaya göre $d$'dir. Ağaç tek tarafa yığılırsa (dengesiz ağaç) özellik sayısı kadar karşılaştırma yapılır. Pratikte daha dengeli ağaçlar oluştuğu için karar ağacı hızlı karar verir. (Sayısal özelliklerdeki istisna için 5.2'deki ders sonrası nota bakın.)

**Soru 3** (derste sözlü, 00:59:45): İkili bir sınıflandırıcı olan SVM çok sınıflı bir problemde nasıl kullanılır?

> **Cevap (derste verildi):** Bire-karşı-hepsi (A mı diğerleri mi, sonra B mi diğerleri mi) ya da sınıfları ikişer ikişer karşılaştıran turnuva benzeri yaklaşım.

**Soru 4** (derste sözlü, 01:04:59): k-NN'de k genelde hangi değerlerden seçilir, neden?

> **Cevap (derste verildi):** Genelde tek sayılar: 1, 3, 5, 7. k = 1 en yakın komşudur ve tesadüfi bir komşu yüzünden riskli olabilir. Komşuların çoğunluğuna bakmak (3 ya da 5) daha güvenilir karar verir.

**Soru 5** (ekrandan, 01:15:00): Bir ROC eğrisinin eksenleri nelerdir? k = 1, 3, 5, 7, 9, 11 için çizilen eğride hangi k seçilmelidir? İdeal ROC eğrisi nasıldır?

> **Cevap (derste verildi):** X ekseni yanlış pozitif oranı, Y ekseni doğru pozitif oranıdır. Eğrinin düzleşmeye başladığı nokta seçilir: 5'ten 7'ye geçerken TP oranı az, FP oranı çok arttığı için k = 5. İdeal eğri TP = 1, FP = 0 noktasından geçer; eğrinin altındaki alan ne kadar büyükse o kadar iyidir.

**Soru 6** (derste sözlü, 01:13:21): Günde 15 milyon işlem yapılan bir bankada sahtekârlık tespit sisteminin yanlış pozitif oranı %1 ise günde kaç hatalı alarm üretilir?

> **Cevap (derste verildi):** $15\,000\,000 \times 0{,}01 = 150\,000$ hatalı alarm.

**Soru 7** (derste sözlü, 01:16:34): 1 milyon normal işlemin hepsini ve 100 sahte işlemin 50'sini doğru bilen bir sistemin accuracy değeri ve sahtekârlık başarısı nedir? Ne sonuç çıkarılır?

> **Cevap (derste verildi, sayı python ile kontrol edildi):** Accuracy $\approx$ %99,995, sahtekârlık başarısı %50. Dengesiz veride accuracy yanıltıcıdır; precision, recall ve F-ölçütü kullanılmalıdır.

**Soru 8** (derste sözlü, 01:19:21): 30 km/sa ve 60 km/sa gerçek hızlarda tahmin 6 km/sa sapıyorsa MAE ve MAPE'ye katkı ne olur? Trafik akış hızı tahmininde hangi metrik kullanılmalıdır?

> **Cevap (derste verildi):** Mutlak hata ikisinde de 6 km/sa'dir. Yüzde hata 30 km/sa'de %20, 60 km/sa'de %10'dur. Düşük hızlarda sapma daha önemli olduğu için MAE ve MAPE birlikte kullanılmalıdır.

**Soru 9** (ekrandan, 01:30:00): Dirsek yönteminde eksenler nelerdir? Hata hangi durumda sıfır olur?

> **Cevap (derste verildi):** X ekseni küme sayısı k, Y ekseni her örneğin kendi küme merkezine uzaklıklarının toplamıdır (hata). k örnek sayısına eşitse, yani her örnek ayrı bir küme olursa hata sıfırdır. Hatanın hızlı düşüşünün bittiği nokta optimum k'dır.

**Soru 10** (derste sözlü, 01:32:38): K-Means ile Gauss karışım modeli arasındaki temel fark nedir?

> **Cevap (derste verildi):** K-Means yalnız ortalamayı kullanır: {1, 5}, {2, 4} ve {3, 3} gruplarının hepsinin merkezi 3'tür. GMM standart sapmayı da kullanarak (2, 1 ve 0) bu grupları ayırt eder ve her örnek için kümeye ait olma olasılığını verir (örneğin 0,8 ve 0,2).

**Soru 11** (derste sözlü, 02:28:20): Eğitim sırasında doğrulama doğruluğu yakınsamıyor ve epoch arttıkça kötüleşiyorsa ne düşünülmelidir? Eğitim doğruluğu da düşükse ne söylenir?

> **Cevap (derste verildi):** Eğitim doğruluğu çok yüksek, doğrulama kötüyse aşırı öğrenme vardır; nöron ya da katman sayısı azaltılabilir. Hem eğitim hem doğrulama kötüyse modele ayırt edici bir özellik kümesi verilmemiştir.

## Dersin Toparlaması

Ders, veri hazırlama bölümünün son konusu olan ayrıklaştırma ile başladı: sürekli değerlerin anlamlı aralıklara toplanması, sınırların seçimi ve eşit genişlik/eşit frekans yöntemleri. Ardından bir zihin haritası üzerinden makine öğrenmesinin beş ana başlığı gözden geçirildi. Gözetimli öğrenmede sınıflandırıcıların karar verme hızı, çok sınıflı SVM ve k-NN'de k seçimi konuşuldu. Parametre seçimi için ROC eğrisi, dengesiz veride accuracy'nin yanıltıcılığı ve trafik hızı tahmininde MAE ile MAPE'nin birlikte kullanımı örneklerle anlatıldı. Gözetimsiz tarafta dirsek yöntemi, kümelerin birleştirilmesi, başlangıç merkezleri ve Gauss karışım modeli işlendi. Pekiştirmeli öğrenme, topluluk öğrenme, yarı gözetimli öğrenme ve anomali tespitinin ardından CNN, RNN, otokodlayıcı, GAN ve derin öğrenmenin hiperparametreleri tartışıldı.

Bütün bu yöntemler mobil teknolojilere şu fikirle bağlandı: hibrit yaklaşımlar ve iş yükünü azaltan en küçük parametreler telefonda hız ve enerji kazandırır. Ağır modeller bulutta eğitilip telefonda yalnız çalıştırılabilir. Derste bir sonraki konunun performans metrikleri (karışıklık matrisi, precision, recall) olacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
