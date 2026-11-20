# Ders 9 Çalışma Özeti

## Genel Konular

- Konunun yeri: Model değerlendirme ve seçimi
  - Önceki derslerde görülen sınıflandırma yöntemleri (karar ağaçları, kural çıkarma, Naive Bayes) kısaca hatırlatıldı. Bu derste "Model Evaluation and Selection" konusuna geçildi; aynı slayt destesinin ikinci başlığı olan topluluk (ensemble) yöntemleri sonraki derse kaldı (ekrandan, 00:13:37).
  - Amaç: bir modelin ne kadar iyi çalıştığını yalnız doğruluk (accuracy) ile değil, başka metriklerle de ölçmek; performansı güvenilir biçimde tahmin etmek için yöntemleri ve modelleri karşılaştırma araçlarını öğrenmek.
- Eğitim, doğrulama (validation) ve test kümeleri
  - Model eğitim kümesinden (training set) öğrenilir, en sonda test kümesiyle doğruluğu ölçülür. Test verisi eğitimde asla kullanılmaz.
  - Yapay sinir ağı gibi yinelemeli (iteratif) ve uzun süren yöntemlerde, eğitim kümesinden küçük bir parça validation set olarak ayrılır (ekrandan, 00:18:37). Belirli yinelemelerde bu küme üzerinde doğruluk ölçülür; hatanın önce düşüp sonra sabitlenmesi beklenir. Validation hatası sürekli dalgalanıyorsa (fluctuation) girdi ya da kodda hata olabilir ve eğitim beklemeden durdurulabilir.
  - Örnek bölme: %20 test, %15 validation, %65 eğitim. Naive Bayes gibi parametre öğrenmeyen, hızlı yöntemlerde validation kümesine gerek yoktur.
- Karışıklık matrisi (confusion matrix)
  - Satırlar gerçek sınıfı (actual class), sütunlar modelin tahmin ettiği sınıfı (predicted class) gösterir (ekrandan, 00:23:37). Karışıklık matrisi yalnız test kümesinden çıkarılır.
  - TP: gerçekte pozitif, model pozitif demiş. TN: gerçekte negatif, model negatif demiş. FP: gerçekte negatif, model pozitif demiş. FN: gerçekte pozitif, model negatif demiş.
  - Ezber kuralı: "true/false" modelin kararının doğru mu yanlış mı olduğunu, "pozitif/negatif" modelin verdiği sınıfı gösterir.
  - Köşegendekiler doğru tahminlerdir; köşegen dışı değerler ne kadar küçükse model o kadar iyidir. Satır toplamı o sınıfın gerçek örnek sayısını, sütun toplamı modelin o sınıfa atadığı örnek sayısını verir.
  - Sınıfların illa evet/hayır olması gerekmez (örneğin kuş ve sürüngen).
- Doğruluk ve hata oranı
  - $\text{Accuracy} = \dfrac{TP + TN}{TP + TN + FP + FN}$, $\text{Error rate} = \dfrac{FP + FN}{TP + TN + FP + FN} = 1 - \text{Accuracy}$.
  - Hata oranına yanlış sınıflandırma oranı (misclassification rate) da denir.
- Sınıf dengesizliği (class imbalance) problemi
  - İlgilenilen sınıf nadirse (kanser, dolandırıcılık, düzensiz nabız, afet gibi) model az olan sınıfı iyi öğrenemez ve doğruluk tek başına yanıltıcı olur (ekrandan, 00:43:37).
  - Kanser örneğinde (300 hasta, 9700 sağlam) model hastaların yalnız 90'ını bulduğu halde doğruluk yaklaşık %96'dır; hiç hasta bulamayan bir model bile yaklaşık %95 doğruluk alır.
- Duyarlılık (sensitivity), özgüllük (specificity), kesinlik (precision), anma (recall), F ölçüsü
  - $\text{Sensitivity} = \text{Recall} = \dfrac{TP}{TP + FN}$: gerçek pozitiflerin ne kadarı bulundu (satıra doğru bölme).
  - $\text{Specificity} = \dfrac{TN}{TN + FP}$: gerçek negatiflerin ne kadarı bulundu.
  - $\text{Precision} = \dfrac{TP}{TP + FP}$: modelin pozitif dediklerinin ne kadarı gerçekten pozitif (sütuna doğru bölme).
  - $F_1 = \dfrac{2 \cdot \text{Precision} \cdot \text{Recall}}{\text{Precision} + \text{Recall}}$: precision ile recall'un harmonik ortalaması.
  - İkili sınıflandırmada hangi sınıfın pozitif sayıldığı değişince sensitivity ve specificity yer değiştirir; araçlar bu yüzden pozitif sınıfı sorar.
- Çok sınıflı karışıklık matrisi
  - $m$ sınıf için $CM_{i,j}$, gerçekte $i$ sınıfında olup $j$ olarak etiketlenen örnek sayısıdır (ekrandan, 01:01:15).
  - Doğruluk: köşegen toplamı bölü tüm örnekler. Her sınıf için $\text{Recall}_{C_i} = CM_{i,i} / \sum_j CM_{i,j}$ (satır), $\text{Precision}_{C_i} = CM_{i,i} / \sum_j CM_{j,i}$ (sütun) (ekrandan, 01:06:15).
  - Çok sınıfta matris genellikle satır yüzdeleriyle ve renk haritasıyla (color map) çizilir; araçlar bunu hazır üretir.
  - Macro averaging: her sınıfın precision/recall değeri ayrı hesaplanır, düz ortalaması alınır.
  - Micro averaging: her sınıf için "bu sınıf / diğerleri" (one-vs-rest) 2x2 matrisi kurulur, bunlar toplanarak tek bir matris elde edilir ve metrikler ondan hesaplanır. Sınıf büyüklükleri hesaba girer, ama hataların hangi sınıftan geldiği bilgisi kaybolur.
- Regresyon için hata ölçüleri
  - Sürekli değer tahmin edilirken sınıf yoktur; ortalama mutlak hata (MAE) ve ortalama karesel hata (MSE) kullanılır. MAE Manhattan uzaklığına, MSE Öklid uzaklığına benzer.
- Performans değerlendirme yöntemleri
  - Öğrenme eğrisi (learning curve): eğitim kümesi büyüdükçe doğruluk artar ve bir noktadan sonra doyuma ulaşır (ekrandan, 01:21:15).
  - Holdout: veri rastgele eğitim (örneğin 2/3 ya da %80) ve test olarak ayrılır. Rastgele seçim önemlidir (örneğin yıllara göre toplanmış veride eski yıllarla eğitip yeni yıllarla test etmek yanıltır).
  - Random sampling: eğitim kümesinin içinden rastgele alt kümelerle tekrar tekrar eğitmek; yapay sinir ağlarında çok kullanılır.
  - k-katlı çapraz doğrulama (k-fold cross-validation): veri $k$ ayrık parçaya bölünür; her turda bir parça test, kalan $k-1$ parça eğitim olur (ekrandan, 01:26:15). En yaygın $k = 10$'dur. Özellikle veri azken kullanılır.
  - Leave-one-out: $k$ = örnek sayısı; her turda bir örnek test, kalan $n-1$ örnek eğitim (ekrandan, 01:41:15). Çok yavaştır, çok küçük veride kullanılır.
  - Katmanlı (stratified) çapraz doğrulama: her katta sınıf dağılımı ilk verideki gibi tutulur. 3000 örnek, 600 pozitif, 3 kat: her kata 200 pozitif ve 800 negatif.
  - Bootstrap: yerine koyarak (with replacement) örnekleme; küçük veride iyi çalışır. .632 bootstrap'te $d$ örnekten $d$ kez seçilir; verinin yaklaşık %63,2'si eğitime girer, seçilmeyen yaklaşık %36,8'i test kümesi olur (ekrandan, 01:46:15).
- ROC eğrisi
  - Receiver Operating Characteristic; adı sinyal haberleşmesinden gelir. Y ekseninde TPR, x ekseninde FPR vardır (ekrandan, 02:06:15).
  - Köşegen çizgi rastgele tahmin eden modeli gösterir. Eğrinin altındaki alan (AUC) modelin doğruluğu hakkında bilgi verir.
  - Çizimi: örnekler modelin pozitif olma olasılığına göre sıralanır, eşik (threshold) adım adım değiştirilir ve her eşik için TPR ve FPR hesaplanır (ekrandan, 02:11:15). Eşik en yüksekken nokta (0,0), en düşükken (1,1) olur.
- Model seçimini etkileyen diğer konular
  - Doğruluk, hız (özellikle test/tahmin süresi), gürbüzlük (gürültü ve eksik değer), ölçeklenebilirlik ve yorumlanabilirlik (ekrandan, 02:21:15).

## Hocanın Özellikle Vurguladığı Kısımlar

- Karışıklık matrisindeki dört terimin anlamı
  - Hoca bu kısmın önemli olduğunu, sonraki bütün metriklerin bunun üzerine kurulduğunu söyledi. True/false modelin doğru ya da yanlış yaptığını, pozitif/negatif modelin verdiği sınıfı gösterir.
- Doğruluk dengesiz veride tek başına yeterli değildir
  - Kanser örneğinde %96 doğruluk, hastaların yalnız %30'unun bulunduğunu gizler. Bu yüzden sensitivity, specificity, precision ve recall'a da bakılmalıdır.
- Formülleri ezberlemek yerine yönünü hatırlamak
  - TP'yi satıra (TP + FN) bölersen recall/sensitivity, sütuna (TP + FP) bölersen precision olur.
- İşlem önceliği
  - Accuracy yazılırken pay parantez içinde düşünülmelidir: $(90 + 9560)/10000$. Hoca sınavda parantezsiz yazımın puan kaybettirebileceğini söyledi.
- Karşılaştırmada aynı ortalamayı kullanmak
  - Farklı araçlar macro ya da micro ortalama kullanabilir. Modeller karşılaştırılırken hepsinin aynı yolla hesaplanması gerekir; yoksa küçük farklar yöntemden değil hesaplama biçiminden gelebilir.
- ROC eğrisinin çizimi
  - Hoca eşik değiştirerek ROC noktalarının nasıl bulunduğunu sorabileceğini söyledi.

## Kısa Tekrar Notları

- Karışıklık matrisi: satır gerçek sınıf, sütun tahmin; yalnız test kümesinden.
- Accuracy = (TP + TN)/hepsi; error rate = 1 - accuracy.
- Sensitivity = recall = TP/(TP + FN); specificity = TN/(TN + FP); precision = TP/(TP + FP); F1 = 2PR/(P + R).
- Kanser örneği: accuracy %96,5, sensitivity %30, specificity yaklaşık %98,6, precision yaklaşık %39.
- Çok sınıfta recall satıra, precision sütuna göre; macro = sınıf değerlerinin düz ortalaması, micro = one-vs-rest matrislerinin toplamından.
- Regresyonda MAE ve MSE.
- Validation set: yinelemeli eğitimi izlemek için eğitimden ayrılır; test kümesi en sonda kullanılır.
- Holdout, random sampling, k-fold CV, leave-one-out, stratified CV, bootstrap (.632).
- ROC: y = TPR, x = FPR; eşik yüksek → (0,0), eşik düşük → (1,1); köşegen = rastgele model; AUC büyükse model daha iyi.
- Model seçimi: doğruluk, hız (özellikle tahmin süresi), gürbüzlük, ölçeklenebilirlik, yorumlanabilirlik.

## Detaylı Açıklamalar

- **Karışıklık matrisi ve ikili örnek.** Slayttaki bilgisayar alma örneğinde test kümesinde 7000 alan ve 3000 almayan kişi vardır (ekrandan, 00:33:37). Model alanların 6954'ünü doğru, 46'sını yanlış (FN) bulmuş; almayanların 2588'ini doğru (TN), 412'sini yanlış (FP) bulmuştur. Toplam yanlış tahmin $412 + 46 = 458$'dir. Doğruluk $(6954 + 2588)/10000 = \%95{,}42$ olur.

- **Kanser örneği (ekrandan, 00:56:15).** Matris: TP = 90, FN = 210, FP = 140, TN = 9560; 300 hasta, 9700 sağlam, toplam 10000.
  - Accuracy $= (90 + 9560)/10000 = 0{,}965$.
  - Error rate $= (210 + 140)/10000 = 0{,}035$.
  - Sensitivity = Recall $= 90/300 = 0{,}30$.
  - Specificity $= 9560/9700 \approx 0{,}986$.
  - Precision $= 90/(90 + 140) = 90/230 \approx 0{,}391$.
  - Yalnız accuracy'ye bakılsaydı model mükemmel sanılırdı; precision ve recall'un düşüklüğü modelin hastaları bulmada başarısız olduğunu gösterir. Hoca ayrıca TP'yi 0, FN'yi 300 yapıp aynı alt satırla doğruluğun yine yaklaşık %95 ($9560/10000$) çıktığını gösterdi.

- **Çok sınıflı örnek (ekrandan, 01:11:15).** E-posta sınıflandırmasında urgent, normal, spam sınıfları vardır. Gerçek satırlar: urgent (30, 7, 3), normal (10, 40, 20), spam (5, 15, 70). Doğruluk $140/200 = \%70$. One-vs-rest matrisleri (TP, FN, FP, TN): urgent (30, 10, 15, 145), normal (40, 30, 22, 108), spam (70, 20, 23, 87). Toplanınca tüm sınıflar için (140, 60, 60, 340) matrisi elde edilir; micro precision ve micro recall bundan $140/200 = 0{,}70$ çıkar. Sınıf bazında precision değerleri yaklaşık 0,667, 0,645, 0,753; düz ortalamaları (macro precision) yaklaşık 0,688'dir (python ile hesaplandı; slayttaki sonuç değerleri karelerde görülemedi). <!-- BELİRSİZ: Macro/micro sonuç slaytı karelerde yok; hoca "ikisinin precision'ı farklı çıkmış" dedi, slayttaki sayılar doğrulanamadı. -->
  - Micro yaklaşımda toplam matriste FP = 60 görülür ama bunların hangi sınıftan geldiği bilinmez; gösterim kolaylaşır, bilgi kaybolur.

- **Regresyon hataları.** $n$ test örneği için $\text{MAE} = \frac{1}{n}\sum_{i=1}^{n} |y_i - \hat{y}_i|$, $\text{MSE} = \frac{1}{n}\sum_{i=1}^{n} (y_i - \hat{y}_i)^2$. Mutlak değer, tahminin büyük ya da küçük olmasından bağımsız olarak uzaklığa bakmayı sağlar.

- **Çapraz doğrulama.** 1000 örnek 5 kata bölünürse her katta 200 örnek olur; beş turun her birinde bir kat test, dördü eğitimdir. Her turda yeni bir model kurulur. Katların doğrulukları birbirine yakınsa model ve veri dağılımı iyidir; bir katta aykırı (outlier) örnekler toplanmışsa o katın doğruluğu düşer, ama ortalama alındığı için tek bir şanslı/şanssız holdout bölmesinin yanıltması önlenir. Leave-one-out'ta ardışık modeller yalnız bir örnek farklı olan 99 örnekten kurulduğu için birbirine çok benzer.

- **Bootstrap.** Her örneğin bir seçimde seçilme olasılığı $1/d$, seçilmeme olasılığı $1 - 1/d$'dir; $d$ seçimden sonra hiç seçilmeme olasılığı $(1 - 1/d)^d \approx e^{-1} = 0{,}368$'dir (ekrandan, 01:46:15). Örnekleme $k$ kez tekrarlanır ve genel doğruluk şu formülle bulunur:
  $$Acc(M) = \frac{1}{k}\sum_{i=1}^{k}\left(0{,}632 \times Acc(M_i)_{test\_set} + 0{,}368 \times Acc(M_i)_{train\_set}\right)$$

- **ROC örneği (ekrandan, 02:11:15).** On örnek, olasılıklarına göre sıralanmış: 0,25(+), 0,43(−), 0,53(+), 0,76(−), 0,85(−), 0,85(−), 0,85(+), 0,87(−), 0,93(+), 0,95(+); beş pozitif, beş negatif. Eşik "≥ 0,25" iken herkes pozitif: TPR = 1, FPR = 1. Eşik 0,43: TP = 4, FP = 5, TPR = 0,8, FPR = 1. Eşik 0,53: TP = 4, FP = 4, TPR = 0,8, FPR = 0,8. Eşik 1,00: kimse pozitif değil, TPR = FPR = 0. Az örnek olduğu için eğri basamaklıdır; bazı araçlar eğriyi yumuşatarak çizer.

- **Ders sonrası notlar.**
  - Hoca sensitivity için "hassasiyet", specificity için "duyarlılık" karşılığını kullandı. Türkçe literatürde yaygın karşılıklar sensitivity için "duyarlılık", specificity için "özgüllük"tür; bu notta bunlar kullanıldı.
  - Hoca ROC anlatımında TPR ile FPR'nin toplamının 1 olması gerektiğini söyledi. Doğrusu: $TPR + FNR = 1$ ve $FPR + TNR = 1$'dir; TPR ile FPR arasında böyle bir bağ yoktur (örneğin eşik 0,25'te ikisi de 1'dir).
  - Hoca eşik 0,53 için sözlü hesapta TPR = 3/5 ve FPR = 0,6 gibi değerler söyledi; slayttaki tabloda ve python kontrolünde doğrusu TPR = 0,8, FPR = 0,8'dir (ekrandan, 02:11:15).

- **ROC ile iki modeli karşılaştırma.** İki eğri kesişiyorsa (biri düşük FPR'de, diğeri yüksek FPR'de daha iyiyse) tek bir noktaya bakarak karar verilemez; eğrinin altındaki alana bakılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
