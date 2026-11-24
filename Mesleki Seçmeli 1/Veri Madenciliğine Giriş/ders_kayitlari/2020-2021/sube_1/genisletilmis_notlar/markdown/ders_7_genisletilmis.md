# Ders 7 Genişletilmiş Notu: Sınıflayıcı Değerlendirme Ölçütleri, Dengesiz Veri, ROC Eğrisi ve k-En Yakın Komşu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- Hoca dersin büyük kısmını İngilizce anlatmıştır. Altyazıda uzun Whisper tekrar halüsinasyonları vardır; bunlar nota alınmamış, eksik kalan yerler ekran karelerinden kurulmuştur. -->

## İçindekiler

- 1. Dersin Yeri ve Model Kestirimi
- 2. Veri Bölme Yöntemleri
- 3. Sınıf Karışıklık Matrisi ve Accuracy
- 4. Accuracy'nin Sorunu: Precision, Recall ve F Ölçütü
- 5. Dengesiz Sınıf Problemi ve Ders Kitabı Örnekleri
- 6. Çok Sınıflı Karışıklık Matrisi Örneği
- 7. TPR, FPR ve ROC Eğrisi
- 8. Dengesiz Veri için Çözüm Yöntemleri
- 9. k-En Yakın Komşu (k-NN) Sınıflayıcı
- Örnek Sorular

## 1. Dersin Yeri ve Model Kestirimi

Şimdiye kadar iki sınıflayıcı görülmüştü: naive Bayes sınıflayıcı ve karar ağacı (decision tree). Bu derste önce bu sınıflayıcıların nasıl değerlendirileceği, nasıl karşılaştırılacağı ve karşılaştırmada hangi ölçütlerin kullanıldığı konuşulur; dersin sonunda üçüncü bir sınıflayıcı olarak k-en yakın komşu (k-NN) anlatılır. Konu başlığı "Model Estimation and Classifier Accuracy Measures" olarak verildi.

Sınıflamada veri eğitim (training) ve test kümelerine ayrılır. Eğitim kümesinde sınıf etiketleri vardır ve model bu kümeyle kurulur. Test kümesinin de gerçek etiketleri (ground truth) bilinir, ama amaç test örneklerinin etiketlerini modelle kestirmek ve sonra kestirilen etiketle gerçek etiketi karşılaştırmaktır. İkisi eşleşirse örnek doğru sınıflanmış, eşleşmezse yanlış sınıflanmış sayılır. Buradaki temel karar, veriyi genelleme hatasını (test hatasını) en aza indirecek şekilde nasıl böleceğimizdir.

### 1.1 İki ve üç parçalı bölme

Ekrandaki "Data Splitting" slaytında iki düzen yan yana gösterildi (ekrandan, 00:25:00):

- İki parçalı bölme: veri eğitim kümesi (Train Model) ve test kümesi (Evaluate Model) olarak ayrılır.
- Üç parçalı bölme: eğitim kümesinde birden fazla model kurulur (ör. lojistik regresyon, karar ağacı, KNN); doğrulama (validation) kümesinde hiperparametreler ayarlanır ve en iyi model seçilir; test kümesinde seçilen modelin son başarımı karışıklık matrisi gibi ölçütlerle değerlendirilir.

Hocanın açıklamasına göre yapay sinir ağları gibi hiperparametre ayarı ve model seçimi gereken uygulamalarda ayrı bir doğrulama kümesi gerekir; ama çoğu uygulamada soldaki iki parçalı düzen kullanılır.

### 1.2 Aşırı öğrenme hatırlatması

Önceki derste aşırı öğrenme (overfitting) konuşulmuştu. Eğitim verisi küçükse ve karmaşık bir model kullanılırsa aşırı öğrenme görülür; böyle bir model gürbüz değildir ve genelleme yeteneği düşüktür. <!-- BELİRSİZ: bu kısmın devamı (karşıt durumun anlatımı) altyazıda halüsinasyon tekrarlarıyla kaybolmuş. -->

## 2. Veri Bölme Yöntemleri

Slaytta beş bölme yöntemi sayıldı: resubstitution, holdout, leave-one-out, rotation (k-katlı çapraz doğrulama) ve bootstrap.

### 2.1 Yeniden yerine koyma (resubstitution)

Bu yöntemde eldeki verinin tamamı hem eğitim hem test için kullanılır; test kümesi eğitim kümesiyle aynıdır. <!-- BELİRSİZ: hocanın bu yöntemin sonucuna dair yorumu altyazıda bozuk ("çok gerçek bir result" gibi); büyük olasılıkla sonucun gerçekçi olmadığı, aşırı iyimser olduğu söylenmiştir. -->

### 2.2 Ayırma (holdout)

Veri iki ya da üç parçaya ayrılır; bir parça test, kalan parça eğitim için kullanılır. Hoca slayttaki bir yazım hatasını derste düzeltti: kalan parçanın "training" (eğitim) olması gerekir.

### 2.3 Birini dışarıda bırak (leave-one-out)

Slayttaki tanım (ekrandan, 00:30:00): model $n-1$ örnekle eğitilir ve kalan tek örnekle değerlendirilir; bu işlem $n-1$ boyutlu farklı eğitim kümeleriyle $n$ kez tekrarlanır. Slayttaki şekilde "iteration 1/N, 2/N, …, N/N" satırları vardır ve her satırda test için ayrılan tek örnek bir sonraki konuma kayar.

İlk turda ilk örnek test örneği olur, kalan örnekler eğitimde kullanılır; ikinci turda sıradaki örnek test için ayrılır ve böyle devam eder. Sonunda her örnek bir kez test edilmiş olur. Bu yaklaşımın hesap yükü büyüktür, çünkü $n$ farklı model kurulup karşılaştırılmalıdır.

Hocanın verdiği kullanım önerisi: veri kümesi çok küçükse, örneğin yalnız 50 ya da 80 örnek varsa, leave-one-out kullanılabilir. Her turda tek örneği test için ayırıp geri kalanların hepsiyle eğitmek, küçük veride daha iyi bir model kurmaya yardım eder.

### 2.4 k-katlı çapraz doğrulama (k-fold cross validation)

Slayttaki tanım (ekrandan, 00:35:00):

- Bu yaklaşım holdout ile leave-one-out arasında bir orta yoldur. Eldeki örnekleri $P$ ayrık alt kümeye böler; burada $1 \le P \le n$.
- $P-1$ alt küme eğitim, kalan alt küme test için kullanılır.
- Pratikte en çok kullanılan yöntemdir; özellikle örnek sayısının görece küçük olduğu problemlerde.

Slayttaki 5 katlı şekilde her satır (Split 1 … Split 5) bir turu gösterir. Mavi parça test verisi, pembe parçalar eğitim verisidir. Split 1'de Fold 1 test, Split 2'de Fold 2 test olur ve bu böyle devam eder. Her turun sonunda bir ölçüt (Metric 1 … Metric 5) elde edilir; bu ölçüt accuracy, recall ya da precision olabilir. Sonra bu değerlerin ortalaması alınarak sınıflayıcının genel başarımı bulunur. Hoca bunun veri madenciliğinde iyi bilinen ve tercih edilen bir çözüm olduğunu vurguladı.

**Soru:** Formüldeki $n$ veri kümesindeki tüm örneklerin sayısı mı, $P$ de bizim seçtiğimiz bir sayı mı? **Cevap:** Evet, $n$ örnek sayısıdır. Hoca soruyu geri sordu: $P = n$ alınırsa yöntem ne olur? Öğrencinin cevabı doğruydu: leave-one-out yöntemi elde edilir.

**Soru (sohbetten):** k-fold ile leave-one-out arasındaki fark nedir? **Cevap:** Leave-one-out her seferinde tek bir örneği dışarıda bırakır; k-fold ise bir alt kümeyi dışarıda bırakır. k-fold'da alt küme sayısı $n$ alınırsa leave-one-out elde edilir.

### 2.5 Bootstrap

Küçük veri kümelerinde yeniden örnekleme (resampling) ile yapay örnekler üretilerek farklı veri kümeleri oluşturulabilir. Bu yeni eğitim kümeleri, hata oranının bootstrap kestirimlerini tanımlamak için kullanılır. <!-- BELİRSİZ: bootstrap anlatımının büyük kısmı altyazıda tekrar halüsinasyonuyla kaybolmuş; yalnız bu ana fikir anlaşılıyor. -->

## 3. Sınıf Karışıklık Matrisi ve Accuracy

Model kestiriminde temel araç sınıf karışıklık matrisidir (class confusion matrix). Hocanın kullandığı düzende satırlar gerçek sınıfı (actual class), sütunlar kestirilen sınıfı (predicted class) gösterir. Hoca bu matrisin bazı kaynaklarda yer değiştirmiş biçimde görülebileceğini, ama kendisinin satırları gerçek, sütunları kestirilen sınıf olarak kullanacağını belirtti.

Slayttaki ikili matris (ekrandan, 00:40:00):

| Gerçek \ Kestirilen | Class = Yes | Class = No |
|---|---|---|
| Class = Yes | a (TP) | b (FN) |
| Class = No | c (FP) | d (TN) |

- True positive (TP): gerçekte "yes" olan ve sınıflayıcının da "yes" dediği örnekler.
- True negative (TN): gerçekte "no" olan ve sınıflayıcının da "no" dediği örnekler.
- False positive (FP): gerçek etiketi "no" olduğu hâlde sınıflayıcının "yes" dediği örnekler.
- False negative (FN): gerçek etiketi "yes" olduğu hâlde sınıflayıcının "no" dediği örnekler.

Doğru sınıflanan bütün örnekler matrisin ana köşegenindedir. En yaygın ölçüt accuracy'dir:

$$\text{Accuracy} = \frac{a+d}{a+b+c+d} = \frac{TP+TN}{TP+TN+FP+FN}$$

Hata oranı da accuracy'den bulunur: $\text{Error rate} = 1 - \text{Accuracy}$.

## 4. Accuracy'nin Sorunu: Precision, Recall ve F Ölçütü

### 4.1 Sıfır sınıflayıcı örneği

İki sınıflı bir problem düşünelim: "no" sınıfında 990, "yes" sınıfında 10 örnek olsun. Bu dengesiz (imbalanced) bir veridir. Burada hiçbir sınıflayıcı kullanmadan bütün test örneklerine "no" diyen bir "sıfır sınıflayıcı" (zero classifier) uygulanırsa çok yüksek accuracy elde edilir, ama "yes" sınıfının bütün örnekleri yanlış sınıflanır. Oysa uygulamada asıl önemli olan sınıf çoğu zaman "yes" sınıfıdır. Bu yüzden yalnız accuracy'ye bakmak yeterli değildir; ek ölçütler gerekir.

### 4.2 Precision, recall ve F ölçütü

Slayttaki tanımlar (ekrandan, 00:45:00):

$$\text{Precision}\ (p) = \frac{a}{a+c} \qquad \text{Recall}\ (r) = \frac{a}{a+b}$$

$$F = \frac{2rp}{r+p} = \frac{2a}{2a+b+c}$$

Precision, "yes" sınıfından olup "yes" kestirilen örneklerin, sınıflayıcının "yes" dediği bütün örneklere oranıdır (kestirilen "yes" sütununa bakılır). Recall, doğru bulunan "yes" örneklerinin, gerçek "yes" örneklerinin tamamına oranıdır (gerçek "yes" satırına bakılır). Precision ve recall'u ayrı ayrı karşılaştırmak zordur; bu yüzden ikisinin harmonik ortalaması olan F ölçütü kullanılır.

**Soru:** F ölçütündeki ifadede "2a kare" olması gerekmiyor mu? **Cevap:** Hoca, $r$ ile $p$ çarpıldığı için öğrencinin haklı olduğunu ve düzeltme gerektiğini söyledi.

> **Ders sonrası not:** Slayttaki formül doğrudur. $r = a/(a+b)$ ve $p = a/(a+c)$ yazılırsa $2rp = \dfrac{2a^2}{(a+b)(a+c)}$ ve $r+p = \dfrac{a(2a+b+c)}{(a+b)(a+c)}$ olur; bölüm sadeleşince $F = \dfrac{2a}{2a+b+c}$ kalır. Payda geçici olarak $a^2$ görünür ama paydadaki $a$ ile sadeleşir; düzeltme gerekmez. <!-- BELİRSİZ: öğrencinin tam olarak hangi ifadeyi sorduğu altyazıdan net değil. -->

## 5. Dengesiz Sınıf Problemi ve Ders Kitabı Örnekleri

Bu bölümde "Introduction to Data Mining, 2nd Edition" kitabının slaytlarına geçildi; hoca bunun derslerin bir başka kaynağı olduğunu söyledi.

### 5.1 Dengesiz veri nerelerde görülür?

Birçok sınıflama probleminde sınıflar çarpıktır; bir sınıftan çok daha fazla kayıt vardır. Örnekler: saldırı tespiti (intrusion detection), üretim hattında kusurlu ürünler, müşteri kaybı (churn / non-churn) uygulamaları ve kredi kartı sahteciliği. Kredi kartı kullanıcılarının çoğu normal kullanıcıdır, sahtecilik yapanlar azdır. Bu problemlerde azınlık sınıfı diğer sınıftan daha önemlidir.

Slayttaki örnekte sınıf 0'da 9990, sınıf 1'de 10 örnek vardır (ekrandan, 00:50:00). Burada sıfır sınıflayıcı uygulanırsa %99 accuracy elde edilir, ama sınıf 1 hiç ayrılamaz. Bu yüzden precision, recall ve F ölçütleri kullanılır.

### 5.2 İki modelin karşılaştırılması

Slayttaki iki karışıklık matrisi (ekrandan, 01:00:00), her ikisinde de "yes" sınıfında 10, "no" sınıfında 990 örnek:

| Model | TP | FN | FP | TN | Precision | Recall | F | Accuracy |
|---|---|---|---|---|---|---|---|---|
| Birinci | 10 | 0 | 10 | 980 | $10/20 = 0.5$ | $10/10 = 1$ | 0.62 (slayt) | $990/1000 = 0.99$ |
| İkinci | 1 | 9 | 0 | 990 | $1/1 = 1$ | $1/10 = 0.1$ | $\dfrac{2 \cdot 0.1 \cdot 1}{1.1} = 0.18$ | $991/1000 = 0.991$ |

Birinci modelde "yes" örneklerinin hepsi doğru sınıflanmıştır, ama "no" sınıfından 10 örnek de "yes" denmiştir; bu yüzden precision %50, recall %100'dür. Accuracy %99 olduğu için yalnız ona bakan biri bunun mükemmel bir sınıflayıcı olduğunu düşünür; precision ise ilgilenilen "yes" sınıfının "no" sınıfından o kadar iyi ayrılmadığını gösterir.

İkinci modelde "yes" sınıfının 10 örneğinden yalnız biri doğru bulunmuş, kalan dokuzu "no" kestirilmiştir. Precision %100 çıkar, ama recall %10'dur: "yes" sınıfının yalnız %10'u doğru sınıflanmıştır. Accuracy yine %99'dur. Hoca, F ölçütü daha iyi olduğu için birinci modelin tercih edileceğini söyledi.

> **Ders sonrası not:** Slayttaki birinci model için $F = \dfrac{2 \cdot 1 \cdot 0.5}{1 + 0.5} = 0.667$'dir; slaytta ve derste 0.62 olarak geçiyor. Birinci modelin daha iyi olduğu sonucu değişmez.

### 5.3 Dengeli ve dengesiz veride aynı TP ve FN

Slayttaki ikinci karşılaştırma (ekrandan, 01:05:00):

- Dengeli veri: TP = 40, FN = 10, FP = 10, TN = 40. Precision = 0.8, TPR = Recall = 0.8, FPR = 0.2, F = 0.8, Accuracy = 0.8.
- Dengesiz veri: "yes" sınıfında 50, "no" sınıfında 5000 örnek; TP = 40, FN = 10, FP = 1000, TN = 4000. Recall $= 40/50 = 0.8$, FPR = 0.2, Accuracy ≈ 0.8, ama Precision ≈ 0.04 ve F ≈ 0.08.

Pozitif sınıftaki sonuçlar iki durumda aynı olduğu hâlde, çoğunluk sınıfının büyümesiyle yanlış pozitiflerin sayısı artar ve precision çöker. Accuracy bu farkı göstermez.

> **Ders sonrası not:** Tam değerler precision $= 40/1040 \approx 0.038$, F $\approx 0.073$ ve accuracy $= 4040/5050 = 0.8$'dir; slayttaki "~0.04" ve "~0.08" yuvarlanmış değerlerdir.

Accuracy'den hata oranı da hesaplanabilir: $\text{Error rate} = 1 - \text{Accuracy}$.

### 5.4 Precision ve recall hangi sınıf için hesaplanır?

**Soru:** Yalnız bir sınıfa mı bakıyoruz? **Cevap:** İkili sınıflamada, yani yalnız pozitif ve negatif sınıf varken, çoğunlukla pozitif sınıf ve onun precision ve recall değerleri kullanılır. Gerekirse negatif sınıf ya da diğer sınıflar için de precision ve recall hesaplanabilir.

## 6. Çok Sınıflı Karışıklık Matrisi Örneği

Aradan sonra hoca tahtada dört sınıflı (a, b, c, d) bir örnek hazırladı. Matris bir sınıflayıcının başarımından elde edilmiştir ve verinin dengesiz olduğu görülür (ekrandan, 01:25:00):

| Gerçek \ Kestirilen | a | b | c | d | Satır toplamı |
|---|---|---|---|---|---|
| a | 50 | 26 | 20 | 12 | 108 |
| b | 3 | 8 | 2 | 0 | 13 |
| c | 0 | 0 | 4 | 0 | 4 |
| d | 0 | 1 | 0 | 1 | 2 |

Soruların cevapları öğrencilerden sohbet ekranından alındı.

- Sınıf başına örnek sayısı satır toplamlarıdır: a için 108, b için 13, c için 4, d için 2. Toplam örnek sayısı 127'dir.
- Doğru sınıflanan örnekler köşegendedir: $50 + 8 + 4 + 1 = 63$.
- $\text{Accuracy} = 63/127 \approx 0.4961$.
- b sınıfının recall'u: köşegendeki 8, b'nin satır toplamına bölünür: $\dfrac{8}{3+8+2} = \dfrac{8}{13} \approx 0.615$ (ekrandan, 01:30:00).
- b sınıfının precision'ı: köşegendeki 8, b'nin sütun toplamına bölünür: $\dfrac{8}{26+8+0+1} = \dfrac{8}{35} \approx 0.229$.
- Recall değeri %100 olan sınıf c'dir: c'nin 4 örneğinin hepsi doğru sınıflanmıştır ve başka sınıfa kestirilen c örneği yoktur.
- c sınıfının precision'ı: $\dfrac{4}{20+2+4+0} = \dfrac{4}{26} \approx 0.154$.

Her sınıf için precision ve recall bu şekilde hesaplanır; F ölçütü de verilen formülle bunlardan kolayca bulunur.

**Soru:** Precision ve recall yalnız her sınıf için mi söylenir, model için tek bir genel değer söyleyemez miyiz? **Cevap:** Her sınıfın ortalamasını alarak ifade etmek mümkün olabilir, ama hoca bunu çok görmediğini söyledi. Asıl dikkat edilen şey belli bir sınıfa odaklanmaktır: kredi kartı sahteciliğinde sahtecilik yapan grup daha önemlidir ve onları en iyi ayırt eden sınıflayıcı aranır; churn tahmininde de benzer bir yaklaşım izlenir. Tamamı üzerinden değerlendirme yapmak yerine sınıf odaklı bakmak daha mantıklıdır.

## 7. TPR, FPR ve ROC Eğrisi

### 7.1 TPR ve FPR

ROC eğrilerinde kullanılacak iki ölçüt tanımlanır:

$$TPR = \frac{TP}{TP+FN} \qquad FPR = \frac{FP}{FP+TN}$$

True positive rate (TPR) recall ile aynıdır; duyarlılık (sensitivity) olarak da anılır, yani aynı ölçütün üç adı vardır. Hesabı karışıklık matrisinin pozitif satırı üzerinden yapılır.

Hoca FPR'yi akılda tutmak için "no" sınıfının recall değeri gibi düşünülebileceğini söyledi; sonra bir öğrencinin sohbetten yaptığı düzeltme üzerine bu yorumun yanlış olduğunu kabul etti.

> **Ders sonrası not:** "No" sınıfının recall'u $\dfrac{TN}{TN+FP}$'dir (özgüllük, specificity). FPR ise $\dfrac{FP}{FP+TN} = 1 - \text{özgüllük}$'tür; yani FPR, negatif sınıfın recall'unun 1'e tümleyenidir. Derste hesaplarda kullanılan formül (slayttaki $FP/(FP+TN)$) doğrudur.

### 7.2 ROC eğrisinin tanımı

Slayttaki tanım (ekrandan, 01:35:00):

- ROC (Receiver Operating Characteristic), tespit oranı (detection rate) ile yanlış alarm oranı (false alarm rate) arasındaki ödünleşimi gösteren grafiksel bir yaklaşımdır. Tespit oranı pozitif sınıfın recall'u, yanlış alarm oranı FPR'dir.
- 1950'lerde gürültülü sinyalleri incelemek için sinyal algılama kuramında geliştirilmiştir.
- ROC eğrisi TPR'yi FPR'ye karşı çizer. Bir modelin başarımı eğride bir nokta olarak gösterilir; sınıflayıcının eşik parametresi değiştirilince noktanın yeri değişir.

ROC eğrisi çizebilmek için sınıflayıcının sınıf etiketi yerine sayısal bir çıktı vermesi gerekir; bu, örneğin çıkış sınıflarının olasılığı olabilir. Grafikte yatay eksen FPR, dikey eksen TPR'dir. Ana köşegen rastgele tahmini gösterir: iki sınıflı bir problemde yazı-tura atarak tahmin yapmak bu köşegene karşılık gelir.

Amaç, eğrinin altında kalan alanı en büyük yapmaktır. Eksenler 0'dan 1'e gittiği için karenin toplam alanı 1'dir; köşegenin altında kalan alan bunun yarısı, yani 0.5'tir. İdeal durumda eğri sol alt köşeden hemen yukarı çıkıp üst kenara yaslanır ve altındaki alan 1'e yaklaşır; bu ideal bir sınıflayıcı demektir ve elde etmesi kolay değildir.

### 7.3 Sürekli değerli çıktı nereden gelir?

ROC eğrisi çizmek için sınıflayıcı sürekli değerli bir çıktı üretmelidir. Naive Bayes ve karar ağaçlarında sonuç bir sınıf etiketidir, ama bunlardan da sürekli değer elde edilebilir: karar ağacı örneğinde yapraklarda "+" ya da "−" etiketi yerine skor değerleri yer alır. <!-- BELİRSİZ: hocanın naive Bayes ve karar ağacından sürekli çıktı elde etme konusundaki açıklaması altyazıda kısmen bozuk. -->

Slayttaki bir boyutlu örnekte (ekrandan, 01:40:00) pozitif ve negatif iki sınıfın dağılımları üst üste binen iki çan eğrisidir; bir eşik değeri $t$ seçilir ve $x > t$ olan her nokta pozitif sınıflanır. $t$ kaydırıldıkça TPR ve FPR değişir.

### 7.4 İki modelin ROC eğrileriyle karşılaştırılması

İki model düşünelim: Model 1'in ROC eğrisi kırmızı, Model 2'ninki mavi çizilmiş. Düşük FPR değerlerinde Model 1 daha iyidir; yüksek FPR değerlerinde ise Model 2 daha iyidir. Yani eğriler kesişebilir ve hangi modelin daha iyi olduğu çalışılacak FPR bölgesine bağlıdır.

### 7.5 ROC eğrisinin kurulması: sayısal örnek

On örnek ve sınıflayıcının her örnek için ürettiği skorlar verilmiştir; gerçek sınıf etiketleri de bilinir (beşi pozitif, beşi negatif). Önce örnekler skorlarına göre sıralanır. Sonra her skor sırayla eşik olarak alınır ve eşiğe eşit ya da büyük skorlu örnekler pozitif sayılır. Her eşik için TP, FP, TN, FN, TPR ve FPR yazılır (ekrandan, 01:45:00):

| Sınıf | + | − | + | − | − | − | + | − | + | + | |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Eşik ≥ | 0.25 | 0.43 | 0.53 | 0.76 | 0.85 | 0.85 | 0.85 | 0.87 | 0.93 | 0.95 | 1.00 |
| TP | 5 | 4 | 4 | 3 | 3 | 3 | 3 | 2 | 2 | 1 | 0 |
| FP | 5 | 5 | 4 | 4 | 3 | 2 | 1 | 1 | 0 | 0 | 0 |
| TN | 0 | 0 | 1 | 1 | 2 | 3 | 4 | 4 | 5 | 5 | 5 |
| FN | 0 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 4 | 5 |
| TPR | 1 | 0.8 | 0.8 | 0.6 | 0.6 | 0.6 | 0.6 | 0.4 | 0.4 | 0.2 | 0 |
| FPR | 1 | 1 | 0.8 | 0.8 | 0.6 | 0.4 | 0.2 | 0.2 | 0 | 0 | 0 |

Hoca ilk üç eşiği tahtada ayrıntılı olarak çözdü (ekrandan, 02:00:00):

1. Eşik 0.25: 0.25'e eşit ya da büyük bütün örnekler pozitif etiketlenir, yani on örneğin hepsine "pozitif" denir. Pozitif sınıftaki beş örneğin hepsi doğru sınıflanır: TP = 5, FN = 0. Negatif sınıftaki beş örneğin hepsi yanlış sınıflanır: FP = 5, TN = 0. Buradan $TPR = 5/(5+0) = 1$ ve $FPR = 5/(5+0) = 1$ bulunur; eğrinin ilk noktası (FPR, TPR) = (1, 1)'dir.
2. Eşik 0.43: 0.43'e eşit ya da büyük dokuz örnek pozitif sayılır. Bunların içinde pozitif sınıfa ait dört örnek vardır; 0.25 skorlu pozitif örnek negatif etiketlenmiştir: TP = 4, FN = 1. Negatif sınıftaki beş örneğin hepsine yine pozitif denmiştir: FP = 5, TN = 0. $TPR = 4/5 = 0.8$, $FPR = 5/5 = 1$; ikinci nokta (1, 0.8)'dir.
3. Eşik 0.53: 0.53'e eşit ya da büyük sekiz örnek pozitif sayılır. Pozitiflerden dördü doğru sınıflanır, biri negatif etiketlenir: TP = 4, FN = 1. Negatif örneklerden dördü yine yanlış sınıflanır, yalnız biri (0.43 skorlu) doğru sınıflanır: FP = 4, TN = 1. $TPR = 0.8$, $FPR = 4/5 = 0.8$; üçüncü nokta (0.8, 0.8)'dir.

Eşik büyütülerek aynı işlem sürdürülür ve bulunan noktalar birleştirilerek ROC eğrisi basamaklı olarak tamamlanır. Hoca derste ilk iki noktayı eğriye kesikli çizgiyle taşıyarak gösterdi.

> **Ders sonrası not:** Slayttaki tabloda 0.85 skoru üç örnekte tekrar ediyor ve tablo bu eşitlikleri tek tek ele alarak üç ayrı sütun yazıyor. "Eşik ≥ 0.85" kuralı doğrudan uygulanırsa bu üç sütunun hepsi TP = 3, FP = 3 verir; FP = 2 ve FP = 1 sütunları, eşit skorlu örneklerin sırayla negatife geçirildiği varsayımından gelir. Bu hesap ajan tarafından python ile kontrol edilmiştir.

**Soru:** Bu eşik sayıları bize veriliyor mu, yoksa nasıl hesaplanıyor? **Cevap:** Bu sayıları sınıflayıcı üretir. Örneğin bir yapay sinir ağı modeli her örnek için bir skor üretir; Bayes sınıflayıcı da bir olasılık değeri üretebilir. Amaç, bu skorları nereden kesip üst tarafına pozitif, alt tarafına negatif dersek en iyi başarımı alacağımızı bulmaktır. ROC eğrisi eşiği değiştirerek bir tarama yapar ve sınıflayıcının başarımını ölçer. Bu tablo için ROC eğrisi slayttaki kırmızı basamaklı çizgidir; altında kalan alan ne kadar büyükse sınıflayıcı o kadar başarılıdır.

## 8. Dengesiz Veri için Çözüm Yöntemleri

Slayttaki "Handling Class Imbalanced Problem" başlığında üç çözüm sayılır (ekrandan, 02:00:00, slayt küçük resmi):

- Sınıf tabanlı sıralama (class-based ordering): seyrek sınıfa ait kurallara daha yüksek öncelik verilir (slaytta örnek olarak RIPPER geçer).
- Maliyete duyarlı sınıflama (cost-sensitive classification): seyrek sınıfı çoğunluk sınıfı olarak yanlış sınıflamak, çoğunluk sınıfını seyrek sınıf olarak yanlış sınıflamaktan daha pahalıdır.
- Örnekleme tabanlı yaklaşımlar (sampling-based approaches).

### 8.1 Maliyete duyarlı sınıflama

Karışıklık matrisinin her hücresine bir maliyet değeri konur; bu maliyet matrisinde $C(i,j)$, $i$ sınıfından bir örneği $j$ sınıfı olarak sınıflamanın maliyetidir. Toplam maliyet, karışıklık matrisinin her hücresindeki örnek sayısının ($f(i,j)$) maliyet matrisinin karşılık gelen hücresiyle çarpılıp toplanmasıyla bulunur:

$$\text{Cost} = \sum_{i,j} C(i,j)\, f(i,j)$$

Örnekte pozitif sınıfa odaklanıyoruz; pozitif sınıfın kredi kartı sahteciliği ya da churn örneklerini temsil ettiğini düşünelim. Amaç pozitif örnekleri doğru kestirmektir; pozitif bir örnek negatif kestirilirse ceza verilmelidir. Slayttaki maliyet matrisi ve iki model (ekrandan, 02:10:00):

| Maliyet $C(i,j)$ | Kestirilen + | Kestirilen − |
|---|---|---|
| Gerçek + | −1 | 100 |
| Gerçek − | 1 | 0 |

| Model | Gerçek +: (+, −) | Gerçek −: (+, −) | Accuracy | Maliyet |
|---|---|---|---|---|
| $M_1$ | 150, 40 | 60, 250 | %80 | 3910 |
| $M_2$ | 250, 45 | 5, 200 | %90 | 4255 |

İki modelin sınıf dağılımları farklıdır: $M_1$'de pozitif sınıfta 190, negatif sınıfta 310 örnek; $M_2$'de pozitif sınıfta 295, negatif sınıfta 205 örnek vardır.

- $M_1$: doğru sınıflanan örnek $150 + 250 = 400$, toplam 500, accuracy $= 400/500 = \%80$. Maliyet $= 150(-1) + 40(100) + 60(1) + 250(0) = -150 + 4000 + 60 = 3910$.
- $M_2$: accuracy $= (250 + 200)/500 = \%90$. Maliyet $= 250(-1) + 45(100) + 5(1) + 200(0) = -250 + 4500 + 5 = 4255$.

Accuracy'ye göre $M_2$ daha iyi görünür, ama maliyete göre $M_1$ daha düşük maliyetlidir. <!-- BELİRSİZ: hocanın iki modeli maliyete göre karşılaştırdığı cümle altyazıda bozuk; sonuç slayttaki değerlerden kurulmuştur. --> Maliyete duyarlı sınıflamada karışıklık matrisinde amaç false negative hücresini küçültmek ve true positive sayısını artırmaktır.

### 8.2 Örnekleme tabanlı yaklaşımlar

Slayttaki tanım (ekrandan, 02:15:00): eğitim verisinin dağılımı, seyrek sınıf eğitim kümesinde iyi temsil edilecek şekilde değiştirilir.

- Çoğunluk sınıfını alt örnekleme (undersampling): çok örnekli sınıftan rastgele örnek seçilerek örnek sayısı azaltılır; örneğin bin örnek varsa içinden yüz tanesi rastgele seçilebilir.
- Seyrek sınıfı üst örnekleme (oversampling): az örnekli sınıf için o sınıfın karakteristiğine uygun yeni (yapay) örnekler üretilir ve sınıflar dengeye getirilir.

Hoca bunun dengesiz veride en çok kullanılan çözüm olduğunu belirtti. Slaytta bu yaklaşımların avantaj ve dezavantajları başlığı da vardır. <!-- BELİRSİZ: avantaj ve dezavantajlar derste ayrıca anlatılmadı. -->

### 8.3 Bölümün toparlaması

Hoca bölümü şöyle özetledi: dengesiz veri varsa yalnız accuracy'den konuşmak yeterli değildir, precision ve recall da değerlendirilmelidir. Çok kullanılan ROC eğrileriyle sınıflayıcıların başarıları karşılaştırılabilir, ama bunun için sınıflayıcının mutlaka sayısal bir skor üretmesi gerekir; her sınıflayıcı için bu skora göre bir eğri çizdirilir. Dengesiz veri için de sınıf tabanlı sıralama, maliyete duyarlı sınıflama ve örnekleme tabanlı yaklaşım olmak üzere üç çözüm vardır.

## 9. k-En Yakın Komşu (k-NN) Sınıflayıcı

Bu bölümde üçüncü sınıflayıcı olarak k-NN anlatıldı. Slaytlar yine "Introduction to Data Mining" kitabındandır.

### 9.1 Örnek tabanlı sınıflayıcılar

k-NN örnek tabanlı (instance-based) bir öğrenme modelidir. İki örnek verildi:

- Rote learner: eğitim verisinin tamamını ezberler ve bir kaydın öz nitelikleri eğitim örneklerinden biriyle tam olarak eşleşirse sınıflama yapar. Yani test örneğinin eğitim kümesinde birebir eşi varsa onun sınıf etiketi test örneğine verilir.
- En yakın komşu (nearest neighbor): sınıflama için eğitim kümesindeki en yakın $k$ noktayı (örneği) kullanır.

Temel fikir slayttaki benzetmeyle anlatıldı: "Ördek gibi yürüyorsa, ördek gibi vaklıyorsa büyük olasılıkla ördektir." Test kaydına en benzer eğitim kayıtları, yani en yakın komşular bulunur ve test örneğinin sınıf etiketi bunlara göre kestirilir.

### 9.2 Yöntemin gerektirdikleri ve adımları

İki boyutlu bir veri kümesi düzlemde görselleştirilebilir ($x_1$ ve $x_2$ eksenleri). Slayttaki şekilde "+" ve "−" eğitim örneklerinin arasında bilinmeyen bir kayıt (kırmızı nokta) ve onun çevresinde komşuları içine alan kesikli bir çember vardır (ekrandan, 02:35:00).

k-NN için üç şey gerekir:

- Etiketli kayıtlar kümesi.
- Kayıtlar arasındaki uzaklığı hesaplamak için bir uzaklık ölçütü.
- $k$ değeri, yani alınacak en yakın komşu sayısı.

Bilinmeyen bir kaydı sınıflamak için:

1. Diğer eğitim kayıtlarına uzaklık hesaplanır.
2. En yakın $k$ komşu belirlenir.
3. En yakın komşuların sınıf etiketleri kullanılarak bilinmeyen kaydın sınıfı belirlenir (ör. çoğunluk oyu alınarak).

Slaytta 1, 2 ve 3 en yakın komşu durumları ayrı ayrı gösterildi. <!-- BELİRSİZ: bu şeklin ayrıntılı anlatımı altyazıda halüsinasyon tekrarlarıyla kaybolmuş. -->

### 9.3 Uzaklık ve oylama

Slayttaki formüller (ekrandan, 02:40:00): iki nokta arasındaki uzaklık için Öklid uzaklığı kullanılır:

$$d(p,q) = \sqrt{\sum_i (p_i - q_i)^2}$$

Burada $i$, veri kümesinin öz niteliklerini (boyutlarını) gösterir ve 1'den $n$'ye gider. $p$ ve $q$ örneklerinin karşılık gelen öz nitelikleri çıkarılır, farkların karesi alınır, kareler toplanır ve toplamın karekökü alınır; bu, $n$ boyutlu veride Öklid uzaklığıdır. Hoca bu uzaklığın önceki derslerden bilindiğini hatırlattı.

Sınıf, en yakın komşu listesinden belirlenir:

- $k$ en yakın komşunun sınıf etiketleri arasında çoğunluk oyu alınır.
- Oy uzaklığa göre ağırlıklandırılabilir: yakın komşunun oyu uzak komşununkinden büyük olur. Ağırlık faktörü $w = 1/d^2$ olarak tanımlanabilir.

### 9.4 Voronoi diyagramı ve 1-NN

Eğitim örnekleri (şekildeki mavi noktalar) verildiğinde, sınıf etiketleri önemli olmaksızın, alandaki her pikselin hangi eğitim örneğine en yakın olduğu hesaplanabilir; bu bölünme Voronoi diyagramıdır ve 1-en yakın komşu karar sınırlarını verir. Hoca bunun çok önemli olmadığını ama bununla ilgili bir literatür bulunduğunu söyledi.

### 9.5 $k$ değerinin seçimi

Yalnız bir en yakın komşuya bakarak karar vermek yeterli değildir; test örneğinin yakınında gürültülü örnekler olabilir. Bu yüzden 3, 5 ya da 7 en yakın komşu seçilmelidir.

$k$ çok büyük seçilirse komşuluk başka sınıflardan noktalar içerebilir. Slayttaki örnekte test örneği $x$'e en yakın beş örnek pozitif sınıftandır, ama çizilen çemberin içine dışarıdaki negatif örnekler de girmiştir. Hoca 3, 5, 7 gibi değerlerin uygun, 15, 20, 50 gibi değerlerin ise çok büyük olabileceğini belirtti. <!-- BELİRSİZ: bu karşılaştırmanın tam cümlesi altyazıda bozuk. -->

### 9.6 Ölçekleme

En yakın komşu sınıflamasında ölçekleme çok önemlidir. Slayttaki tanım (ekrandan, 02:45:00): uzaklık ölçüsünün öz niteliklerden birinin baskısı altında kalmaması için öz nitelikler ölçeklenmelidir. Örnek:

- Bir kişinin boyu 1.5 m ile 1.8 m arasında değişebilir.
- Bir kişinin kilosu 90 lb ile 300 lb arasında değişebilir.
- Bir kişinin geliri 10 bin dolar ile 1 milyon dolar arasında değişebilir.

Bu sayısal öz nitelikler ölçeklenmeden Öklid uzaklığı uygulanırsa değer aralığı en büyük olan öz nitelik (gelir) uzaklığı belirler. Bu yüzden sınıflamaya başlamadan önce veri min-max normalizasyonu ya da z-skor normalizasyonu ile ölçeklenmelidir.

### 9.7 Tembel öğrenici

k-NN sınıflayıcılar tembel öğrenicidir (lazy learner), çünkü açıkça bir model kurmazlar. Karar ağaçlarında eğitim kümesiyle bir model (ağaç) kurulur; k-NN'de böyle bir eğitim aşaması yoktur. Buna karşılık bilinmeyen bir kaydın sınıflanması görece pahalıdır, çünkü her test örneği için her eğitim örneğine olan uzaklık hesaplanmalıdır.

Ayrıca k-NN'in karar sınırları Voronoi diyagramı olarak görülebilir. Kararlar yerel bilgiye dayandığı için değişkenler arası etkileşimleri ele almak kolaydır. <!-- BELİRSİZ: bu slaytın maddeleri altyazıdan kısmen kurulmuştur; slayt karesi okunmamıştır. -->

### 9.8 k-NN'in verimliliğini artırmak

Her örnek için tüm eğitim örneklerine uzaklık hesaplamak çok işlem gerektirir; algoritmanın karmaşıklığı buradan gelir. Bu sorun eğitim kümesindeki bütün nesnelere uzaklık hesaplamaktan kaçınan yöntemlerle çözülebilir:

- Çok boyutlu erişim yöntemleri, örneğin KD-ağaçları (KD-trees).
- Hızlı yaklaşık benzerlik araması (fast approximate similarity search).
- Yere duyarlı karma (locality sensitive hashing).

Hoca KD-ağacı fikrini tahtada iki boyutlu bir veri kümesi üzerinde anlattı: $x_1$ ve $x_2$ boyutlu bir düzlemde pozitif ve negatif örnekler ile bilinmeyen bir test örneği $x$ vardır (ekrandan, 02:50:00). Düzlem eşik değerleriyle bölgelere ayrılır; böylece test örneğinin uzaklığı yalnız ilgili bölgedeki örneklere hesaplanır. Eşik değerlerinin nasıl seçileceği sorusuna hoca, ikili ağaçta olduğu gibi bölerek ya da verinin dağılımına göre karar verilebileceği cevabını verdi. <!-- BELİRSİZ: KD-ağacı anlatımının büyük kısmı (yaklaşık 02:49–02:53) altyazıda halüsinasyon tekrarlarıyla kaybolmuş; karedeki tahtada yalnız bir dikdörtgen içinde "+" örnekler görülüyor. Bölgelere ayırma adımları ayrıntılı olarak kurulamamıştır. -->

> **Ek bilgi (derste anlatılmadı):** KD-ağacı, uzayı her düğümde tek bir boyut üzerinde bir eşik değeriyle ikiye bölen ikili bir arama ağacıdır; bölünen boyut genellikle düzeyden düzeye sırayla değişir ve eşik çoğu zaman o boyuttaki medyan değer seçilir. En yakın komşu aranırken önce test noktasının düştüğü yaprak bulunur, sonra yalnız daha yakın bir nokta içerebilecek komşu bölgeler denetlenir.

## Örnek Sorular

### Soru 1: k-fold ve leave-one-out ilişkisi

(derste sözlü, 00:34:38) k-katlı çapraz doğrulamada örnekler $P$ ayrık alt kümeye bölünüyor ($1 \le P \le n$). $P = n$ alınırsa yöntem neye dönüşür?

**Çözüm:** Her alt kümede tek örnek kalır; her turda bir örnek test, kalan $n-1$ örnek eğitim için kullanılır. Bu leave-one-out yöntemidir.

### Soru 2: İkili karışıklık matrisi

(ekrandan, 00:55:00) Gerçek sınıfı satırlarda, kestirilen sınıfı sütunlarda gösteren matris aşağıdadır:

| Gerçek \ Kestirilen | P | N |
|---|---|---|
| P | 45 | 5 |
| N | 10 | 50 |

Pozitif ve negatif sınıfta kaç örnek vardır? TP, TN, FP, FN kaçtır? Doğru sınıflanan örnek sayısı, accuracy, precision ve recall nedir?

**Çözüm (derste verilen):** Pozitif sınıfta $45 + 5 = 50$, negatif sınıfta $10 + 50 = 60$ örnek vardır; toplam 110. TP = 45, TN = 50, FP = 10, FN = 5. Doğru sınıflanan örnek sayısı $45 + 50 = 95$.

- $\text{Accuracy} = 95/110 \approx 0.864$ (sonuç ajan tarafından hesaplandı).
- $\text{Precision} = \dfrac{45}{45+10} = \dfrac{45}{55} \approx 0.818$.
- $\text{Recall} = \dfrac{45}{45+5} = \dfrac{45}{50} = 0.9$.

### Soru 3: Dört sınıflı karışıklık matrisi

(ekrandan, 01:25:00) Bir sınıflayıcı aşağıdaki karışıklık matrisini üretmiştir (satırlar gerçek, sütunlar kestirilen sınıf):

| Gerçek \ Kestirilen | a | b | c | d |
|---|---|---|---|---|
| a | 50 | 26 | 20 | 12 |
| b | 3 | 8 | 2 | 0 |
| c | 0 | 0 | 4 | 0 |
| d | 0 | 1 | 0 | 1 |

a) Her sınıfta kaç örnek vardır? b) Accuracy nedir? c) b sınıfının recall ve precision değerleri nedir? d) Recall değeri %100 olan sınıf hangisidir? e) c sınıfının precision değeri nedir?

**Çözüm (derste verilen):**

- a) a: 108, b: 13, c: 4, d: 2; toplam 127.
- b) $\text{Accuracy} = 63/127 \approx 0.4961$.
- c) $\text{Recall}(b) = 8/13 \approx 0.615$, $\text{Precision}(b) = 8/35 \approx 0.229$.
- d) c sınıfı: 4 örneğin hepsi doğru sınıflanmıştır.
- e) $\text{Precision}(c) = 4/26 \approx 0.154$.

### Soru 4: FPR'nin yorumu

(derste sözlü, 01:32:30) $FPR = \dfrac{FP}{TN+FP}$ oranına bir ad verebilir misiniz?

**Çözüm:** Derste önce "no" sınıfının recall'u denmiş, sonra bu yorum düzeltilmiştir. Doğrusu: "no" sınıfının recall'u (özgüllük) $\dfrac{TN}{TN+FP}$'dir ve $FPR = 1 - \text{özgüllük}$'tür. FPR, yanlış alarm oranı (false alarm rate) olarak da anılır.

### Soru 5: ROC eğrisi için eşik tablosu

(ekrandan, 01:45:00) Skorlarına göre sıralanmış on örneğin gerçek sınıfları soldan sağa +, −, +, −, −, −, +, −, +, + ve skorları 0.25, 0.43, 0.53, 0.76, 0.85, 0.85, 0.85, 0.87, 0.93, 0.95'tir. Eşik 0.25, 0.43 ve 0.53 alındığında (skoru eşiğe eşit ya da büyük olanlar pozitif) karışıklık matrislerini kurun, TPR ve FPR'yi bulun ve ROC noktalarını yazın.

**Çözüm (derste verilen):**

| Eşik | TP | FN | FP | TN | TPR | FPR | Nokta (FPR, TPR) |
|---|---|---|---|---|---|---|---|
| 0.25 | 5 | 0 | 5 | 0 | 1 | 1 | (1, 1) |
| 0.43 | 4 | 1 | 5 | 0 | 0.8 | 1 | (1, 0.8) |
| 0.53 | 4 | 1 | 4 | 1 | 0.8 | 0.8 | (0.8, 0.8) |

Diğer eşikler tablodaki gibi devam eder; noktalar birleştirilerek basamaklı ROC eğrisi elde edilir.

### Soru 6: Maliyete göre model seçimi

(ekrandan, 02:10:00) Maliyet matrisi $C(+,+) = -1$, $C(+,-) = 100$, $C(-,+) = 1$, $C(-,-) = 0$ olsun. $M_1$ için karışıklık matrisi (gerçek +: 150, 40; gerçek −: 60, 250), $M_2$ için (gerçek +: 250, 45; gerçek −: 5, 200). Her modelin sınıflarındaki örnek sayıları, accuracy'si ve maliyeti nedir?

**Çözüm (derste verilen):**

- $M_1$: pozitif sınıfta 190, negatif sınıfta 310 örnek. Accuracy $= 400/500 = \%80$. Maliyet $= -150 + 4000 + 60 + 0 = 3910$.
- $M_2$: pozitif sınıfta 295, negatif sınıfta 205 örnek. Accuracy $= 450/500 = \%90$. Maliyet $= -250 + 4500 + 5 + 0 = 4255$.
- Accuracy'si daha yüksek olan $M_2$'nin maliyeti daha yüksektir; maliyete göre $M_1$ tercih edilir.

## Dersin Toparlaması

Bu derste sınıflayıcıların nasıl değerlendirileceği ele alındı. Önce verinin eğitim, doğrulama ve test kümelerine nasıl bölüneceği ve resubstitution, holdout, leave-one-out, k-katlı çapraz doğrulama ve bootstrap yöntemleri görüldü; k-katlı çapraz doğrulamanın en çok tercih edilen yöntem olduğu ve $P = n$ için leave-one-out'a dönüştüğü vurgulandı. Ardından karışıklık matrisi, accuracy ve hata oranı tanımlandı; dengesiz veride accuracy'nin yanıltıcı olduğu, bu yüzden precision, recall ve F ölçütünün sınıf odaklı olarak kullanılması gerektiği ders kitabı örnekleri ve tahtadaki iki ve dört sınıflı örneklerle gösterildi. TPR ve FPR üzerinden ROC eğrisinin tanımı, eşik taramasıyla nasıl kurulduğu ve eğri altındaki alanın anlamı sayısal bir örnekle çalışıldı. Dengesiz veri için sınıf tabanlı sıralama, maliyete duyarlı sınıflama ve alt/üst örnekleme çözümleri anlatıldı.

Son bölümde üçüncü sınıflayıcı olarak k-NN tanıtıldı: Öklid uzaklığı, çoğunluk oyu ve uzaklığa göre ağırlıklandırma, $k$ seçimi, ölçeklemenin önemi, tembel öğrenici niteliği ve KD-ağacı gibi hızlandırma yöntemleri. Derste görülen sınıflayıcılar (naive Bayes, karar ağacı, k-NN) artık bu ölçütlerle karşılaştırılabilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
