# Ders 5 Çalışma Özeti

## Genel Konular

- Model değerlendirme (model evaluation) ve model seçimi (model selection): hangi modelin ve hangi parametrelerin seçileceği.
- Genelleme (generalization), aşırı öğrenme (overfitting) ve yetersiz öğrenme (underfitting).
- Occam'ın usturası (Occam's razor).
- Veriyi bölme: eğitim (training), doğrulama (validation), test.
- Holdout, rastgele alt örnekleme (random subsampling), k katlı çapraz doğrulama (k-fold cross-validation), birini dışarıda bırak (leave-one-out), bootstrap.
- Tabakalı örnekleme (stratification).
- Dengesiz veri (imbalanced data): örnek azaltma, veri artırma (data augmentation).
- Karışıklık matrisi (confusion matrix).
- Başarı ölçüleri: doğruluk (accuracy), kesinlik (precision), duyarlılık (recall, sensitivity), özgüllük (specificity), F1 skoru.
- ROC eğrisi ve eğri altındaki alan (Area Under the Curve, AUC).

## Hocanın Özellikle Vurguladığı Kısımlar

- **Altın kural:** eğitimde kullanılan veri asla test için kullanılmaz. Hoca bunun "çok sık, farkında olmadan" yapılan bir hata olduğunu ve başarının bu yüzden yapay olarak yüksek çıktığını söyledi.
- Parametre ayarları (K değeri, ağacın budanması vb.) yalnız doğrulama verisiyle yapılır. Test verisi hiçbir ayara karışmaz, sadece son başarıyı ölçmek için kullanılır.
- Tek bir model denenip bırakılmamalıdır. Birden fazla model (k-NN, karar ağacı, yapay sinir ağı...) ve her model için farklı parametreler denenmeli, en başarılısı seçilmelidir. Probleme göre %3'lük fark büyük bir farktır.
- Eğitim ve test bölünürken sınıf oranları korunmalıdır (stratified). Hoca bunun "çok önemli" olduğunu tekrar etti.
- "Makine öğrenmesi çalışmalarında bütün olay detaylarda saklı."
- Eğitim örneklerini elle, "cımbızla" en iyi örneklerden seçmek doğru değildir. Model, eğitimdeki ideal örneklerden uzaklaşan gerçek örneklerde başarısız olur.
- Dengesiz veride accuracy yanıltıcıdır.
- Çok sınıflı problemlerde mutlaka karışıklık matrisine bakılmalı, hangi sınıfın hangisiyle karıştığı ve nedeni araştırılmalıdır. Yanlış sınıflanan örnekler tek tek incelenmelidir.
- Lisansüstü öğrencilere (özellikle doktora): var olan çalışmaların "future work" kısmındaki sorunlara odaklanın. Bu sorunlar genelde karışıklık matrislerinden anlaşılır.
- Hazır kütüphanelerle bir günde sistem kurulabiliyor. Ama başarısızlığın nedenine bakılmıyor. Hoca bunu en sık gördüğü hata olarak saydı.
- Duyuru: bir sonraki hafta ilk ödev verilecek.

## Kısa Tekrar Notları

- **Overfitting:** eğitim başarısı yüksek, test başarısı düşük. Model ezberlemiştir.
- **Underfitting:** öğrenme tamamlanmadan kesilmiştir ya da model problem için yetersizdir.
- **Occam'ın usturası:** genelleme hatası benzer iki modelden basit olanı seçin.
- **Veri bölme:** önce eğitim ve test (birbirine değmeyen, disjoint). Sonra eğitim kısmı eğitim ve doğrulama olarak bölünür.
- **Holdout:** genelde 2/3 eğitim, 1/3 test (ya da %80-%20, %70-%30).
- **Random subsampling:** holdout'u rastgele bölmelerle K kez tekrarla, ortalama hatayı al.
- **k-fold CV:** veriyi K parçaya böl. Her turda 1 parça test (doğrulama), K-1 parça eğitim. K turun ortalaması alınır. K genelde 5 veya 10 (en yaygın 10-fold).
- **Leave-one-out:** $N$ örnek varsa $N-1$ ile eğit, 1 ile doğrula. Çok az veri olduğunda.
- **Bootstrap:** $N$ örnekten, yerine koyarak (aynı örnek tekrar seçilebilir) $N$ örnek seç. Seçilmeyenler test olur.
- **Stratification:** her parçada sınıf oranları tüm verideki oranla aynı olmalı.
- Model ve parametreler belirlendikten sonra, gerçek kullanıma çıkarken genelde tüm veri (eğitim + doğrulama + test) ile model yeniden eğitilir.
- **Karışıklık matrisi (iki sınıf):** TP, FN, FP, TN.
- $\text{Accuracy} = \dfrac{TP + TN}{TP + TN + FP + FN}$
- $\text{Precision} = \dfrac{TP}{TP + FP}$
- $\text{Recall} = \text{Sensitivity} = \text{TPR} = \dfrac{TP}{TP + FN}$
- $\text{Specificity} = \text{TNR} = \dfrac{TN}{TN + FP}$
- $F_1 = 2 \cdot \dfrac{\text{Precision} \cdot \text{Recall}}{\text{Precision} + \text{Recall}}$ (harmonik ortalama)
- **ROC:** x ekseni FPR, y ekseni TPR. Farklı eşik değerleri için çizilir.
- **AUC:** 0 ile 1 arası. 1 mükemmel, 0,5 rastgele tahmin (yazı-tura).

## Detaylı Açıklamalar

### Neden değerlendirme yapıyoruz?

- İki amaç var:
  1. Farklı modeller arasından (karar ağacı, k-NN, Bayes...) en iyisini seçmek.
  2. Aynı modelin en iyi parametrelerini seçmek (ör. k-NN'de K = 3, 5, 7; karar ağacında budama).
- Makine öğrenmesi, insan öğrenmesi gibi genelleme yapmaya çalışır. Hoca örnek verdi: kuşların kanat, gaga, iki ayak gibi ortak özelliklerini öğrenen biri, hiç görmediği tropik bir kuşu da kuş olarak tanır.

### Overfitting ve underfitting

**Somon-levrek örneği**

- İki sınıf: somon (salmon) ve levrek (sea bass). İki özellik: balığın uzunluğu ve pullarının parlaklığı.
- Üç model gösterildi:
  - **Doğrusal sınır:** iki tarafta da yanlış sınıflanan örnekler var. Yine de fena değil.
  - **Çok karmaşık sınır:** tüm eğitim örnekleri doğru sınıflanıyor. Ama somonların yoğun olduğu bölgedeki bilinmeyen bir örneğe "levrek" diyor, çünkü sınır birkaç aykırı örneği de kapsayacak şekilde kıvrılmış. Bu overfitting'dir.
  - **Esnek, düzgün sınır:** bazı hatalar var ama sınıfların genel yapısını en iyi yansıtan sınır. En iyi genelleme bu.

**Overfitting nedenleri**

- Geneli temsil etmeyen örnekler: gürültü (parazit) ya da gerçek ama sıra dışı örnekler (ör. kız öğrencilerin arasında 1,90 boyunda, 100 kilo bir öğrenci). Bu örnekler doğru sınıflanana kadar eğitime devam etmek ezberlemeye yol açar.
- Gereğinden fazla, ayırt edici olmayan özellik kullanmak.
- Karar ağacında düğüm sayısı arttıkça eğitim başarısı artar ama bir noktadan sonra test başarısı düşer.
- Model ne kadar karmaşıksa eğitim hatası o kadar küçük olur. Sıfır eğitim hatası, yüksek test hatası anlamına gelebilir.

**Underfitting nedenleri**

- Öğrenmenin erken kesilmesi. Ör. yapay sinir ağında "hata $\varepsilon$'un altına düşene kadar" yerine "20 bin adım" gibi sabit bir iterasyon sayısı verilir. Bu sayı yetmezse model yeterince öğrenemez.
- Modelin problem için çok basit olması.
- Çözümü görece kolaydır: eğitimi uzatmak ya da başka bir model denemek.

**Hocanın anısı (underfitting)**

- Hoca asistanken iki öğrencinin bitirme projesini yönetiyordu: fareyi sesle kontrol etme (yukarı, aşağı, sağ, sol, tıkla).
- Özellik olarak MFCC (Mel Frequency Cepstral Coefficients), model olarak klasik yapay sinir ağı kullanılmıştı.
- Literatürde %80 civarı başarı varken onlarınki %60'ı geçmiyordu. Veri, kayıtlar ve kod defalarca incelendi.
- Sonunda durdurma koşulunun hata eşiği değil sabit iterasyon sayısı olduğu ve bu sayının öğrenmeye yetmediği anlaşıldı.
- Ders: underfitting farkına varmadan karşılaşılan bir durumdur.

### Veriyi bölmek

**Temel düzen**

1. Veriyi birbirine değmeyen iki parçaya ayır: eğitim ve test.
2. Eğitim kısmını tekrar ikiye ayır: eğitim ve doğrulama.
3. Eğitim verisiyle modeli kur.
4. Doğrulama verisiyle parametreleri ayarla (budama, K seçimi vb.).
5. Her model için en iyi parametreyi bul, modelleri karşılaştır.
6. Son olarak test verisiyle, hiçbir şeye dokunmadan başarıyı ölç.

- Aynı veri farklı turlarda farklı rollerde kullanılabilir (bir turda eğitim, başka bir turda test). Ama aynı turda hem eğitim hem test için kullanılamaz.
- Sorun: veri toplamak zordur. Ör. tıbbi bir problemde zaten 50 hasta bulunabiliyorsa, veri üçe bölününce eğitime çok az veri kalır.

**Holdout**

- Verinin 2/3'ü eğitim, 1/3'ü test (ya da %80-%20).
- Veri azsa sorunludur.

**Random subsampling**

- Holdout bölmesi rastgele seçimlerle K kez tekrarlanır. Her turda model yeniden kurulur. Sonuç, turların ortalama hatasıdır:

$$E = \frac{1}{K} \sum_{i=1}^{K} E_i$$

- Sorunlar:
  - Bazı örnekler hiç teste girmeyebilir, bazıları hep teste girebilir.
  - Tesadüfen iyi örnekler hep eğitimde, kötü örnekler hep testte (ya da tersi) toplanabilir.
- Veri kümesi büyükse sorunsuz kullanılabilir.

**Eğitim örneklerini elle seçmek (yanlış uygulama)**

- Eski çalışmalarda eğitim örnekleri "en iyi" örneklerden seçilirdi. Ör. yüz tanımada: tam karşıdan, ışığı iyi, gözler açık.
- Bir öğrenci sorunu doğru tespit etti: kötü bir örnek geldiğinde model tanıyamaz.
- Gerçek örnekler eğitimdeki karakteristikten uzaklaştıkça başarı düşer. Bugün müdahalesiz örnekler tercih edilir.

**k-fold cross-validation**

- Amaç: her örneğin hem eğitimde hem testte yer almasını sağlamak.
- Veri K parçaya bölünür. Her turda bir parça test, K-1 parça eğitim için kullanılır. K tur sonunda ortalama hata alınır.

**Örnek 1: 5-fold CV**

- 100 örnek, 5 parça. Her turda 80 örnek eğitim, 20 örnek test.
- Bir turda 20 test örneğinin 11'i doğru sınıflanırsa o turun accuracy'si $11/20 = 0{,}55$ olur.
- Beş turun ortalaması alınır. Slayttaki örnekte ortalama başarı %73 çıkıyor.

**İki kullanım şekli**

- **1. Ayrı test kümesi olmadan:** tüm veri dönüşümlü olarak eğitim ve doğrulama için kullanılır, ortalama hata raporlanır.
- **2. Ayrı test kümesiyle:** test kümesi baştan ayrılır. Kalan veri üzerinde CV yapılarak parametreler seçilir. Sonra ayrı test kümesiyle son başarı ölçülür.

**Örnek 2: CV ile K seçimi (k-NN)**

1. Test kümesini ayır.
2. Kalan veriyi 5 parçaya böl.
3. K = 3 için: 4 parçayla eğit, 1 parçayla doğrula. Beş turu yap, ortalama başarıyı bul.
4. Aynı işlemi K = 1, 5, 7 için tekrarla.
5. En yüksek ortalama başarıyı veren K'yı seç.
6. Ayrı tutulan test kümesiyle son başarıyı ölç.

**Leave-one-out**

- Veri azsa kullanılır.
- $N$ örnek varsa her turda $N-1$ örnekle eğitilir, 1 örnekle doğrulanır. $N$ tur yapılır.
- Her örnek hem eğitimde hem doğrulamada yer alır ve az veri çok parçaya bölünmemiş olur.

**Bootstrap**

- $N$ örnekten, yerine koyarak $N$ örnek rastgele seçilir. Aynı örnek birden fazla kez seçilebilir.
- Hiç seçilmeyen örnekler test için kullanılır.
- İşlem birçok kez tekrarlanır.

**Hangisi ne zaman?**

- Yeterli veri varsa: %60-%70 eğitim, %30-%40 test. Eğitim kısmı da eğitim ve doğrulama olarak bölünür.
- Veri azsa: cross-validation (holdout yerine).

**Son model (öğrenci sorusu)**

- Soru: gerçek kullanıma çıkarken eğitim kısmıyla mı, tüm veriyle mi eğitilmeli?
- Cevap: model ve tüm parametreler (K değeri, yapay sinir ağında katman sayısı vb.) belirlendikten sonra genelde eğitim, doğrulama ve test verisi birleştirilir. Model bu tüm veriyle eğitilip kullanıma verilir. Böylece hiçbir veri boşa gitmez.
- Çok büyük veri varsa (ör. bir yıllık kredi kartı işlemleri) buna gerek olmayabilir.

### Stratification

**Örnek 3: Kredi kartı sahtekârlığı**

- A sınıfı: normal işlemler. B sınıfı: sahte işlemler.
- Veride oran 10'a 1 olsun (her 10 normal işleme 1 sahte işlem).
- Bölme sınıfa bakılmadan yapılırsa, eğitim parçasında oran tesadüfen 20'ye 1 olabilir. Bu istenen sonucu vermez.
- Stratified bölme: hem eğitim hem test parçasında (ve CV'nin her katında) oran 10'a 1 olacak şekilde seçilir.

### Dengesiz veri

- Yüz tanıma, araba modeli tanıma gibi kontrollü problemlerde sınıflar dengelidir.
- Hastalık teşhisi, kredi kartı sahtekârlığı, ağ saldırısı tespitinde normal veri bulmak çok kolay, olay verisi bulmak zordur.
- Çözümler:
  1. **Çok olan sınıfı azaltmak:** tam eşitlemek iyi değildir, çünkü az olan sınıf zaten azdır. Bunun yerine deneylerle en iyi oran bulunur (ör. 1'e 5 ya da 1'e 10) ve bu oran korunur. Oran serbest bırakılmamalıdır: 1 saldırı örneğine 100 normal örnek olursa model genelleme yapamaz.
  2. **Veri artırma (augmentation):** görüntüyü döndürmek, bir kısmını kesmek gibi işlemlerle örnek sayısını artırmak. Üretken çekişmeli ağlar (Generative Adversarial Networks, GAN) ile gerçekçi sahte veri üretmek. Derin öğrenme özetleri son derslerde verilecek.

### Karışıklık matrisi

- İki sınıflı (binary) problem için:

```
                    Tahmin: Pozitif   Tahmin: Negatif
Gerçek: Pozitif          TP                FN
Gerçek: Negatif          FP                TN
```

- TP: gerçekte pozitif, model pozitif dedi.
- FN: gerçekte pozitif, model negatif dedi.
- FP: gerçekte negatif, model pozitif dedi.
- TN: gerçekte negatif, model negatif dedi.
- Köşegenin yüksek olması istenir. Ama hataların (FP, FN) dağılımı da önemlidir.
- Çok sınıflı problemde matris, hangi sınıfın hangisiyle karıştığını gösterir.

**Örnek 4: Aktivite tanıma**

- Çoğu sınıf %100 doğru. Ama "run" ile "skip", "wave 1" ile "wave 2" birbirine karışıyor.
- Yapılacaklar:
  - Karışan örneklere tek tek bakmak. Ortak bir sorun olabilir.
  - Gereken bir özellik kullanılmamış ya da yanlış bir özellik kullanılmış olabilir.
  - İki hareket gerçekten çok benziyorsa sınıfları birleştirmek doğru olabilir.
  - Hiçbir şey çözmüyorsa bu karar bilinçli olarak verilir.

### Başarı ölçüleri

**Accuracy**

- Sınıflar dengeliyse temel ölçüdür.

**Örnek 5: Accuracy tuzağı**

- A sınıfında 9.990, B sınıfında 10 örnek var.
- Model 10.000 örneğin hepsine "A" diyor.
- $\text{Accuracy} = 9990 / 10000 = 99{,}9\%$.
- Model aslında hiçbir B örneğini bulamıyor. Dengesiz veride accuracy bu yüzden yanıltıcıdır.

**Precision, recall, specificity**

- **Precision:** modelin pozitif dediklerinin ne kadarı gerçekten pozitif? $TP / (TP + FP)$.
- **Recall (sensitivity, TPR):** gerçek pozitiflerin ne kadarını model buldu? $TP / (TP + FN)$.
- **Specificity (TNR):** gerçek negatiflerin ne kadarını model buldu? $TN / (TN + FP)$.

**Örnek 6: Hastalık testi**

- 100 kişiye pozitif denmiş, bunların 50'si gerçekten hasta: precision $= 50/100 = 0{,}5$. 50 sağlıklı kişiye yanlışlıkla hasta denmiş. FP'nin maliyeti yüksekse (ör. sağlıklı kişiye kanser tedavisi uygulamak) precision önemlidir.
- Gerçekte 100 hasta var, model 20'sini bulmuş: recall $= 20/100 = 0{,}2$. 80 hasta kaçırılmış. FN'nin maliyeti yüksekse (ör. hastalık ilerledikten sonra fark edilmesi) recall önemlidir.
- Hoca derste COVID testleriyle ilgili tartışmayı örnek verdi: genelde sadece doğru pozitiflerden söz ediliyor. Negatiflerin ne kadarının doğru bulunduğu konuşulmuyor.

**F1 skoru**

- Precision ve recall'u birlikte değerlendirir:

$$F_1 = \frac{2 \cdot P \cdot R}{P + R}$$

- Ne zaman ne?
  - TP ve TN'yi yakalamak önemli ve sınıflar yaklaşık dengeliyse: accuracy.
  - Yanlış sınıflananlar (FP, FN) önemliyse ya da veri dengesizse: F1.

### ROC eğrisi ve AUC

- ROC (Receiver Operating Characteristic) eğrisi ilk kez II. Dünya Savaşı'nda radar operatörlerince, radarın algıladığının gerçek bir nesne mi yoksa gürültü mü olduğunu değerlendirmek için kullanıldı. Sonra tıpta (radyoloji) ve makine öğrenmesinde kullanılmaya başlandı.
- x ekseni: FPR $= FP / (FP + TN) = 1 - \text{Specificity}$.
- y ekseni: TPR $=$ Recall.
- Gerçek dünyada pozitif ve negatif dağılımları genelde iç içe geçer. Bir eşik (threshold) seçilir: eşiğin üstü pozitif, altı negatif sayılır.
- Eşik değiştikçe TPR ve FPR değişir. ROC eğrisi bu değişimi gösterir. Sol üst köşe (FPR = 0, TPR = 1) ideal noktadır.

**AUC yorumları (hocanın çizimleri)**

- **AUC = 1:** pozitif ve negatif dağılımları hiç örtüşmüyor. Mükemmel ayrım (gerçekte pek olmaz).
- **AUC = 0,7:** sınıflar %70 oranında ayrılabiliyor. Bazı negatifler pozitif tarafına, bazı pozitifler negatif tarafına geçmiş.
- **AUC = 0,5:** dağılımlar tamamen üst üste. Model yazı-tura atmaktan farksız.
- **AUC = 0:** model her pozitife negatif, her negatife pozitif diyor.

**ROC'nin kullanımı**

- Tek modelde: en iyi eşik değerini seçmek.
- Birden fazla modelde: her modelin (FPR, TPR) noktası ROC uzayına yerleştirilir ve karşılaştırılır. Ör. TPR %80, FPR %20 olan bir model iyi bir dengedir. TPR'si artarken FPR'si de artan bir model, FP istenmiyorsa tercih edilmez.

- Hoca, farklı yöntemlerde hatanın farklı biçimlerde hesaplandığını, bunu modeller anlatılırken ayrıca göstereceğini söyledi.

### Ders sonrası notlar

- **Precision tanımı:** hoca ilk anlatımda precision'ı "gerçek pozitiflerin içinde doğru bildiklerinizin oranı" diye tanımladı ve "1000 COVID hastasının 500'ünü bildiyse precision %50" örneğini verdi. Bu tanım ve örnek aslında recall'a aittir. Arada bir öğrenci recall'un paydasının TP + FN olduğunu hatırlattı. Hoca aradan sonra slaytı düzeltti ve doğru tanımı verdi: precision $= TP/(TP+FP)$, yani modelin pozitif dediklerinin ne kadarının doğru olduğu.
- **Specificity:** hoca bir yerde "hasta olanların ne kadarını doğru bildi" dedi. Doğrusu: specificity gerçek negatiflerin (sağlıklıların) ne kadarının doğru bulunduğudur, $TN/(TN+FP)$.
- **Holdout oranı:** hoca bir yerde "üçte birini eğitim için ayırdınız" dedi. Doğrusu üçte ikisi eğitim, üçte biri testtir.
- **TPR %40 ve yazı-tura:** hoca COVID testinin %40 TPR'sinin yazı-turadan kötü olduğunu söyledi. Bu yorum tek başına eksiktir. Rastgele bir sınıflandırıcıda TPR = FPR olur. Bir testin rastgeleden iyi olup olmadığı ancak TPR ile FPR birlikte (ROC uzayında köşegenin üstünde mi?) değerlendirilerek söylenebilir. Ayrıca bu ifade hocanın kişisel yorumudur, tıbbi bir değerlendirme değildir.
- **AUC = 0:** ters çalışan bir sınıflandırıcıdır. Tahminleri tersine çevrilirse AUC = 1 olur. Bu yüzden "en kötü" durum pratikte AUC = 0,5'tir (hiç bilgi taşımayan model).
- **Bootstrap:** her turda test kümesine giren (seçilmeyen) örnekler beklenen değer olarak verinin yaklaşık %36,8'idir ($(1 - 1/N)^N \to e^{-1}$).
- **Occam's razor:** altyazıda "Occam-Schreizer" diye bozuk geçiyor.
- Hoca slaytların genelde ders sabahına kadar hazırlandığını, dört farklı ders (görüntü işleme, algoritma analizi, makine öğrenmesi, veri yapıları) verdiği için önceden paylaşamadığını söyledi. Ders kaydedildiği için paylaşmaya gerek görmediğini ama belki paylaşabileceğini ekledi.
- Ders 10:05 civarında başladı. 10:40'ta 15 dakika, 11:20 civarında 10 dakika ara verildi.

NotebookLM gibi bir araca altyazı dosyasını yükleyerek bu ders hakkında daha ayrıntılı soru-cevap yapabilirsiniz.
