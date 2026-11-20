# Ders 15 Genişletilmiş Notu: Proje Sunumları: Sınıflandırma Uygulamaları ve Değerlendirme Üzerine Yorumlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

> **Kayıt hakkında:** Ders baştan sona öğrenci gruplarının proje sunumlarıyla geçer; hoca yeni konu anlatmaz, sunumlar sırasında soru sorar ve yorum yapar. Kayıtta ekran paylaşımı görünmez (5 dakikada bir alınan karelerin hepsi kamera kapalı simgesi, sonuncusu siyah ekran). Sunumlardaki tablolar ve sonuç değerleri bu yüzden okunamadı. Altyazı sunum bölümlerinde çok bozuktur; bu not yalnız konuşmadan güvenle çıkarılabilen yöntemleri ve hocanın yorumlarını içerir.

## İçindekiler

- 1. Görüntü Verisiyle Sınıflandırma: Naive Bayes, k-NN ve Random Forest
- 2. Tablo Verileriyle Sınıflandırma Projeleri
- 3. Sınıflandırma ile Tahmin Arasındaki Fark
- 4. Öznitelik ve Sınıf Seçimi
- 5. Metin Verisiyle Etiket Sınıflandırma
- 6. Son Sunum: Hastalık Veri Seti
- Örnek Sorular

## 1. Görüntü Verisiyle Sınıflandırma: Naive Bayes, k-NN ve Random Forest

Birinci grup görüntülerden oluşan bir veri setiyle sınıflandırma yaptı. Görüntüleri doğrudan modele vermek yerine renk tabanlı öznitelikler çıkardılar: her görüntü için belirli renk aralıklarına düşen piksel sayısı birer öznitelik (feature) oldu. Böylece her görüntü, sabit uzunlukta sayısal bir vektöre dönüştü ve derste görülen klasik sınıflandırıcılar uygulanabilir hale geldi.

Grup üç makine öğrenmesi yöntemi seçti:

- **Naive Bayes:** Her renk alanındaki piksel sayılarına göre her sınıf için bir olasılık hesaplanır; en olası sınıf seçilir.
- **k-en yakın komşu (k-NN):** Yeni örneğe en yakın $k$ örneğe bakılır ve bu komşular arasında en çok görülen sınıf atanır.
  <!-- BELİRSİZ: Altyazıda "K10" geçiyor; k = 10 seçilmiş olabilir, ancak ekran görüntüsü olmadığı için doğrulanamadı. -->
- **Rastgele orman (random forest):** Önce farklı alt veri setleri oluşturulur. Grup 50 ağaç seçti; 50 farklı ağaç 50 farklı alt veri seti üzerinde ve farklı öznitelik alt kümeleriyle eğitilir. Test örneği için her ağaç bir sınıf önerir ve en çok çıkan sınıf sonuç olur.

Değerlendirme için 10 katlı çapraz doğrulama (10-fold cross-validation) kullanıldı. Hoca sonuçlara geçmeden önce kaç eğitim, kaç test görüntüsü ve kaç sınıf olduğunu sordu; bu bilgiler her deney raporunda baştan verilmelidir. Sonuç tablosundaki sayıların başarı oranını gösterdiği, 1'in %100 başarı anlamına geldiği açıklandı.

<!-- BELİRSİZ: Sınıf sayısı, görüntü sayısı ve her yöntemin başarı değerleri ekranda gösterildi; kayıtta ekran olmadığı ve altyazı bozuk olduğu için alınamadı. -->

### 1.1 Neden random forest en iyi çalıştı?

Grubun en başarılı algoritması random forest oldu. Grup bunun en önemli sebebinin veri setinin aşırı dengesiz (imbalanced) olması olduğunu düşündü: örneklerin yarıdan fazlası "others" adlı tek bir sınıftaydı. Random forest dengesiz veri setlerine görece iyi uyum sağlayabilen bir yöntem olarak değerlendirildi. Grup ayrıca verilerinde çok fazla gürültü (noise) olmadığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Random forest'ın dengesiz veride kendiliğinden üstün olduğu her zaman doğru değildir; çoğunluk sınıfı baskın olduğunda doğruluk (accuracy) yanıltıcı biçimde yüksek çıkabilir. Bu yüzden dengesiz veri setlerinde sınıf bazında kesinlik (precision), duyarlılık (recall) ya da F-ölçüsüne de bakmak gerekir.

### 1.2 Neden Naive Bayes kötü çalıştı?

Naive Bayes'in kötü çalışacağı baştan bekleniyordu; grup onu karşılaştırma için bilerek seçmişti. Naive Bayes'in bir ön koşulu vardır: öznitelikler sınıf verildiğinde birbirinden bağımsız varsayılır. Görüntülerde ise pikseller birbiriyle ilişkilidir. Grubun verdiği örnekle, kırmızı renkli bir bölgenin yanında sarı renkli bir bölge olmasını bekleriz; yani renk değerleri tamamen bağımsız değildir. Bu bağımlılık Naive Bayes'in varsayımını bozar ve başarısını düşürür.

### 1.3 Projeden öğrenilenler

Hoca grubun proje boyunca en çok ne öğrendiğini sordu. Grup görüntü verisiyle çalışmanın klasik makine öğrenmesi yöntemleri için zor olduğunu, internetteki kaynakların görüntü probleminde daha çok derin öğrenmeye yöneldiğini ve bu yüzden kendi denemelerine dayanmak zorunda kaldıklarını anlattı. Hoca bu yöntemlerin derste anlatılmadığını belirtti; grup da onları seçmeyince geriye kalan seçeneklerin az olduğunu ekledi.

## 2. Tablo Verileriyle Sınıflandırma Projeleri

### 2.1 Kanser veri seti

İkinci sunumda UCI makine öğrenmesi deposundan alınmış, kadınlarla ilgili bir kanser türüne ait bir veri seti kullanıldı. Çok yüksek değerli örneklerin ele alındığı ve bazı yöntemlerin iyi, bazılarının kötü uyduğu söylendi; en iyi sonuç yaklaşık %95 başarı olarak verildi.

<!-- BELİRSİZ: Kanser türü (altyazıda "göz kanseri" diye bozulmuş), kullanılan yöntemler ve hangi yöntemin %95'e ulaştığı altyazıdan net çıkmıyor. -->

### 2.2 Büyük ve dengesiz bir veri seti

Üçüncü sunumda toplam yaklaşık 3 milyon satırlık bir veri seti vardı ve sınıflar dengesizdi: bir sınıftan yalnız birkaç bin örnek vardı. Grup şu ön işleme adımlarını uyguladı:

- Veriyi karıştırdılar (shuffle).
- Az olan sınıfın örnek sayısıyla eşit sayıda örneği diğer sınıflardan alarak daha küçük, dengeli bir alt küme oluşturdular (alt örnekleme, undersampling).
- Aykırı değerleri (outlier) modellemeden önce çıkardılar; kümeleme ile aykırı değer olup olmadığına baktılar.

Ardından karar ağaçları, kümeleme ve k-NN gibi yöntemler denendi.

<!-- BELİRSİZ: Veri setinin konusu ve sınıf etiketi altyazıdan anlaşılamıyor; "8.000" sayısının az olan sınıfın örnek sayısı olduğu bağlamdan tahmin edildi. -->

## 3. Sınıflandırma ile Tahmin Arasındaki Fark

Aynı grup projesinde bir hedef sütunu için yaptığı işe "sınıflandırma", başka bir hedef sütunu için yaptığı işe "tahmin" adını vermişti. Hoca bu ayrımı sorguladı ve diğer öğrencilere de tahminle sınıflandırma arasındaki farkı sordu.

Hocanın açıklaması şöyleydi: Türkçede "tahmin" (prediction) denince daha çok regresyon tabanlı modeller anlaşılır. Örneğin sıcaklık gibi sürekli (continuous) bir değerin kestirilmesi tahmindir; lojistik regresyon gibi bir modelin çıktısı 1,24 gibi sürekli bir sayı olabilir. Grubun yaptığı iki iş ise aslında iki sınıflandırmaydı: yalnız hedef değişkenleri (sınıf etiketleri) ve dolayısıyla alt veri setleri farklıydı. Kategorik bir etiket üretilen bir probleme "tahmin" demek çok mantıklı değildir. Hoca İngilizce ve Türkçe terimlerin karışık kullanılmasının bu tür karışıklıklara yol açtığını da belirtti.

> **Hocanın vurgusu:** Sınıflandırma kategorik bir sınıf etiketi üretir; "tahmin" kelimesi daha çok sürekli değer üreten regresyon problemleri için kullanılmalıdır.

> **Ek bilgi (derste anlatılmadı):** İngilizce literatürde "prediction" bazen genel olarak modelin çıktısı (sınıf ya da sayı) anlamında da kullanılır. Veri madenciliği ders kitaplarında ise sınıflandırma kategorik etiketler için, sayısal tahmin (numeric prediction) ya da regresyon sürekli değerler için ayrılır.

## 4. Öznitelik ve Sınıf Seçimi

Dördüncü sunumdan sonra bir öğrenci önemli bulduğu bir çıkarımı paylaştı: hedef sınıfın gerçekten düzgün seçilmesi çok önemlidir ve buna önceden çok dikkatli bakmak gerekir. Hoca bunun önemli olduğunu onayladı ve hangi öznitelikleri neye göre seçtiklerini sordu.

Grup veri setinde çok fazla sütun (öznitelik) olduğunu, özniteliklerin fazla olmasının bir yandan iyi olduğunu, ama içinde serbest metin açıklamaları (description) bulunan sütunların işi bambaşka bir metin madenciliği problemine dönüştürdüğünü, bu yüzden bu sütunları dışarıda bıraktıklarını anlattı.

## 5. Metin Verisiyle Etiket Sınıflandırma

### 5.1 Veri seti ve problem

Beşinci grup bir programlama soru-cevap sitesindeki sorularla çalıştı. Bu sitede her soruya en fazla 5 etiket (tag) eklenebilir; amaç bir sorunun metninden etiketini bulmaktı. İndirilen veri yaklaşık 780 bin soruydu; hoca bunun yine oldukça büyük olduğunu belirtti.

### 5.2 Ön işleme

- **Kod bölümlerinin çıkarılması:** Soru metinlerinde kod parçaları vardı; bunlar etiketleriyle birlikte metinden çıkarıldı.
- **Tek etikete indirgeme:** Her soruya tek bir etiket verildi. Önce en popüler etiketler belirlendi. Bir sorunun örneğin 5 etiketi varsa ve bunlardan 3'ü en popüler etiketler arasındaysa, bu 3 etiketten biri seçilmeliydi. Grup bunlardan en az popüler olanı seçti. Hoca bunun gerekçesini şöyle özetledi: en az popüler olanı seçersin ki o sınıfın da elinde örneği olsun.
- **Soru uzunluğunun sınırlanması:** Çok uzun sorular sorun çıkardığı için soru uzunluğu sınırlandı.

<!-- BELİRSİZ: Seçilen popüler etiket sayısı ve uzunluk sınırı altyazıdan net okunamıyor. -->

Hoca doğruluk hesaplanırken yalnız seçilen tek etikete mi bakıldığını, yani modelin önerdiği etiket sorunun 5 etiketinden biri olsa bile bunun doğru kabul edilmediğini sordu. Bu soru, çok etiketli bir veriyi tek etikete indirgediğinizde değerlendirme ölçütünün de buna göre dikkatle tanımlanması gerektiğini gösterir.

### 5.3 Kullanılan yöntemler

- **Naive Bayes:** Grup, Naive Bayes'in öznitelikleri bağımsız varsaydığını, oysa sorulardaki anahtar kelimelerin birbiriyle bağlantılı olduğunu (bir soruda bir programlama dili geçiyorsa belirli başka teknolojilerin de geçmesi gibi) belirtti. Bu yüzden Naive Bayes'in görece zayıf sonucu olağan karşılandı.
- **Doğrusal SVM ve kernel'lı SVM:** Bir öğrenci doğrusal (linear) SVM'in ne olduğunu sordu. Hoca şöyle açıkladı: SVM aslında veriyi doğrusal olarak ayırır. Ama bazı uzaylar doğrusal olarak ayrılamaz; bu yüzden matematiksel olarak içine kernel fonksiyonları konur, kernel'ın içinde polinomlar ve benzeri fonksiyonlar vardır. Grubun kullandığı diğer SVM büyük olasılıkla böyle kernel'lı bir sürümdü; bu yüzden daha yavaş çalışmış ama iyi sonuç vermişti.
- **LSTM:** Önceden eğitilmiş kelime vektörleri (word embeddings) kullanılarak bir LSTM modeli eğitildi. Eğitim yaklaşık 20-25 saat sürdü.
  <!-- BELİRSİZ: LSTM türü altyazıda "Dileyle STM" olarak geçiyor, büyük olasılıkla Bi-LSTM; kullanılan hazır kelime vektörlerinin adı ve neden seçildiği (teknoloji alanında yeni kelimelerin eklenmesiyle ilgili bir gerekçe söyleniyor) anlaşılamıyor. Model girdisinin boyutu için "128 çarpı 200" gibi bir değer söylendi, neyi gösterdiği net değil. -->

### 5.4 Hocanın önerileri

Hoca sunumdan sonra üç öneri yaptı:

1. **Etiketler arasındaki hiyerarşi:** Bazı etiketler aslında diğerlerinin alt kümesi gibidir. Burada düz sınıflandırma yerine etiketleri hiyerarşik olarak ele alan bir yöntem (hiyerarşik sınıflandırma ya da hiyerarşik kümeleme) uygulanabilirse, hangi etiketin hangisinin altında olduğu, neyin neyle ilgili olduğu gibi özgün bir sonuç çıkabilir.
2. **Ön işlemeye dikkat:** LSTM'e vermeden önce bağlaçlar gibi gereksiz kelimeler elenir; bu adım iyi yapılmalıdır.
3. **Metin üretimi fikri:** LSTM tahmin yapabildiği gibi metin de yazabilir. Bir sonraki proje olarak model kendi kendine bu siteye uygun soru yazabilir; anlamlı soru üretip üretemediği, üretilen sorular insanlara puanlatılarak ölçülebilir.

> **Ek bilgi (derste anlatılmadı):** Hiyerarşik kümeleme derste kümeleme konusu altında görülen, nesneleri adım adım birleştirerek (ya da bölerek) bir ağaç (dendrogram) oluşturan yöntemdir. Etiketlerin birlikte görülme sıklıklarından bir benzerlik ölçüsü tanımlanırsa bu ağaç, etiketler arasındaki üst-alt ilişkilerini görselleştirmek için kullanılabilir.

## 6. Son Sunum: Hastalık Veri Seti

Son grup bir hastalıkla ilgili bir veri seti kullandı. Hoca veri setinin nereden bulunduğunu, kaç kişilik veri olduğunu ve veri setinin sınıf dağılımını sordu. Dağılım grafikleri Python'daki Matplotlib kütüphanesiyle çizilmişti. Hoca son olarak değerlendirmede çapraz doğrulama (cross-validation) mı yapıldığını, yoksa veri setinin eğitim ve test olarak mı ayrıldığını sordu.

<!-- BELİRSİZ: Veri setinin kaynağı, örnek sayısı, kullanılan yöntemler ve sonuçlar altyazıdan anlaşılamıyor; değerlendirme sorusunun cevabı kayıtta yok. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:25:34): Tahminle sınıflandırma arasında ne fark vardır? İki farklı hedef sütun için yapılan iki işten birine "sınıflandırma", diğerine "tahmin" demek doğru mudur?

> **Cevap (derste verildi, 00:25:50):** Sınıflandırma kategorik bir sınıf etiketi üretir. Türkçede "tahmin" denince daha çok regresyon tabanlı, sürekli değer (ör. sıcaklık) üreten modeller anlaşılır. Hedef sütunlar kategorikse iki iş de sınıflandırmadır; yalnız hedef değişkenler ve alt veri setleri farklıdır.

**Soru 2** (derste sözlü, 00:45:37): Doğrusal (linear) SVM nedir? Aynı veri setinde başka bir SVM sürümü neden daha yavaş ama iyi çalışmış olabilir?

> **Cevap (derste verildi, 00:45:39):** SVM temelde veriyi doğrusal olarak ayırır. Doğrusal ayrılamayan uzaylarda içine polinom gibi kernel fonksiyonları konur. Kernel'lı sürüm büyük olasılıkla daha yavaş çalışır ama doğrusal olmayan sınırları yakalayabildiği için iyi sonuç verebilir.

**Soru 3** (derste sözlü, 00:05:55 ve 00:44:27): Görüntü pikselleri ya da sorulardaki anahtar kelimeler öznitelik olarak kullanıldığında Naive Bayes neden kötü çalışabilir?

> **Cevap (derste verildi):** Naive Bayes, sınıf verildiğinde özniteliklerin birbirinden bağımsız olduğunu varsayar. Komşu pikseller (kırmızı bölgenin yanında sarı bölge beklenmesi gibi) ve birlikte geçen anahtar kelimeler birbirine bağlıdır; varsayım bozulduğu için başarı düşer.

**Soru 4** (derste sözlü, 00:48:14): Bazı etiketler diğerlerinin alt kümesi gibiyse, etiket sınıflandırma problemine nasıl farklı bir yaklaşım uygulanabilir?

> **Cevap (derste verildi):** Düz sınıflandırma yerine etiketleri hiyerarşik olarak ele alan bir yöntem (hiyerarşik sınıflandırma/kümeleme) kullanılabilir; böylece hangi etiketin hangisinin altında olduğu ortaya çıkar.

**Soru 5** (derste sözlü, 00:57:36): Bir modelin başarısı raporlanırken çapraz doğrulama mı yapıldı, yoksa veri eğitim ve test olarak mı ayrıldı?

> **Çözüm (derste verilmedi):** Kayıt soru sorulduktan hemen sonra biter. Eğitim/test ayrımında veri bir kez bölünür; sonuç bu tek bölünmeye bağlıdır. $k$ katlı çapraz doğrulamada veri $k$ parçaya bölünür, her parça bir kez test kümesi olur, kalan $k-1$ parçayla eğitilir ve $k$ sonucun ortalaması alınır; birinci gruptaki gibi 10 katlı çapraz doğrulama daha güvenilir bir başarı kestirimi verir. Hangisinin yapıldığı raporda açıkça belirtilmelidir.

## Dersin Toparlaması

Bu derste dönem boyunca görülen yöntemlerin gerçek veri setlerine uygulanması öğrenci sunumları üzerinden tartışıldı. Görüntü, tablo ve metin verilerinde Naive Bayes, k-NN, karar ağaçları, random forest, SVM ve LSTM gibi yöntemler karşılaştırıldı. Ortak dersler şunlardı: dengesiz veri setleri için alt örnekleme ya da dengesizliğe dayanıklı yöntemler gerekir; Naive Bayes'in bağımsızlık varsayımı piksellerde ve birlikte geçen kelimelerde bozulur; ön işleme (aykırı değer temizliği, kod ve gereksiz kelime ayıklama, öznitelik seçimi) sonucu doğrudan etkiler.

Hoca ayrıca terimlerin doğru kullanılmasına dikkat çekti: kategorik etiket üreten iş sınıflandırmadır, "tahmin" daha çok regresyon içindir. Doğrusal ayrılamayan veride SVM'e kernel eklenmesi, etiketler arasında hiyerarşi varsa hiyerarşik yöntemlerin düşünülmesi ve değerlendirme yönteminin (çapraz doğrulama ya da eğitim/test ayrımı) açıkça belirtilmesi derste öne çıkan noktalardı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
