# Ders 9 Genişletilmiş Notu: Sınıflandırıcı Değerlendirme Metrikleri, Değerlendirme Yöntemleri ve ROC Eğrisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

> **Kayıt sırası hakkında:** Kayıt iki parçadır; arşivde parçalar ters sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## İçindekiler

- 1. Önceki Derslerin Hatırlatması ve Bugünün Konusu
- 2. Eğitim, Doğrulama ve Test Kümeleri
- 3. Karışıklık Matrisi
- 4. Doğruluk ve Hata Oranı
- 5. Sınıf Dengesizliği Problemi
- 6. Sensitivity ve Specificity
- 7. Recall, Precision ve F Ölçüsü
- 8. Çok Sınıflı Sınıflandırmada Metrikler
- 9. Regresyon İçin Hata Ölçüleri
- 10. Performans Değerlendirme Yöntemleri
- 11. Modelleri Karşılaştırma ve ROC Eğrisi
- 12. Model Seçimini Etkileyen Diğer Konular
- Örnek Sorular

## 1. Önceki Derslerin Hatırlatması ve Bugünün Konusu

Hoca derse, sınıflandırma konusunda şimdiye kadar görülenleri hatırlatarak başladı. Sınıflandırma yöntemlerinden ilk olarak karar ağaçları görülmüştü: ağacın nasıl kurulduğu ve bölme ölçütü olarak information gain ile Gini index gibi ölçülerin tanımı. Ardından karar kurallarının (decision rules) nasıl çıkarıldığına bakılmıştı. Bunun iki yolu vardı: genelden özele giden (büyük bir kuraldan başlayıp koşul çıkararak ilerleyen) ve özelden genele giden (tek bir kuraldan başlayıp koşul ekleyerek ilerleyen) yaklaşımlar. Son olarak olasılık ve istatistikten bilinen Bayes kuralı, yani $P(A \mid B)$ koşullu olasılığı, sınıflandırmaya uygulanmıştı (00:08:16).

Bayes sınıflandırıcısının mantığı hava durumu ve tenis örneğiyle hatırlatıldı. Veri setinde hava (bulutlu, güneşli, parçalı bulutlu), nem (yüksek, normal) ve yağış (var, yok) öznitelikleri ile "o gün tenis oynandı mı" sınıfı vardır. Eğitim kümesinden her öznitelik değeri için tenis oynanma olasılıkları hesaplanır; örneğin hava bulutluyken ne kadar tenis oynandığı. Test örneği geldiğinde bu olasılıklar birleştirilir, sınıf 0 ve sınıf 1 için olasılık bulunur ve hangisi yüksekse örnek o sınıfa atanır (00:10:40).

Bu dersin konusu "Model Evaluation and Selection" başlığıdır; aynı slayt destesinin ikinci başlığı "Ensemble Methods: Increasing the Accuracy"dir (ekrandan, 00:13:37). Hoca bugün öğrenilecek terimlerin ileride derin öğrenme ve makine öğrenmesi derslerinde de sürekli karşılaşılacak terimler olduğunu söyledi. Şimdiye kadar bir modelin ne kadar iyi olduğu yalnız doğruluk oranıyla ("modelim %85 çalışıyor") ifade edilmişti; bu derste doğruluğun çoğu durumda yeterli olmadığı ve başka hangi metriklerin kullanıldığı görülecekti. Plan üç parçaydı: performans değerlendirme metrikleri, performans değerlendirme yöntemleri (istatistiksel testlere çok girmeden, ROC eğrileriyle birlikte) ve modellerin nasıl karşılaştırılacağı. Bagging ve boosting gibi topluluk öğrenme yöntemleri de bu planda vardı, ama derse yetişmedi.

## 2. Eğitim, Doğrulama ve Test Kümeleri

Şimdiye kadar veri iki parçaya ayrılıyordu: eğitim kümesi (training set) ve test kümesi (test set). Eğitim kümesinden bir model oluşturulur, model tamamen oluştuktan sonra test kümesiyle doğruluğu ölçülür. Test kümesine sorabilmek için bütün eğitim sürecinin bitmiş olması gerekir.

Hoca burada yeni bir kavram ekledi. Çoğu model yinelemeli (iteratif) çalışır; örneğin bin yineleme çalışıp durur. Model oluşturulurken o anki modelin ne kadar iyi olduğunu görmek istenebilir. Özellikle yapay sinir ağları gibi yöntemler çok uzun çalışır ve çok parametrelidir: görüntülerle çalışırken üç saat bekleyip sonunda modelin %60 doğrulukla çalıştığını görmek hoş değildir. Bu yüzden eğitim kümesinin küçük bir parçası ayrılır ve buna doğrulama kümesi (validation set) denir (ekrandan, 00:18:37). Model kalan eğitim verisiyle öğrenilirken, örneğin her 30 yinelemede bir, o anki modelin doğruluğu validation kümesinde ölçülür ve eğitime devam edilir.

Beklenen davranış, hatanın ilk yinelemelerde yüksekten başlayıp giderek düşmesi ve bir yerde sabitlenmesidir. Model iyi çalışmıyor ve rastgele şeyler buluyorsa validation hatasında sürekli iniş çıkışlar (fluctuation) görülür. Bu durumda girdi yanlış verilmiş ya da kodda hata yapılmış olabilir; modelin oluşmasını beklemeden eğitim durdurulup hata aranabilir.

Örnek bir bölme: verinin %20'si test, %15'i validation, kalan %65'i eğitim için kullanılabilir. Validation en çok yapay sinir ağları gibi yöntemlerde gerekir. Karar ağaçları çok yavaş çalışmaz ve ağaç sonradan budandığı için performans değişebilir; bu yüzden onlarda genellikle tüm model görülmek istenir.

**Soru:** Validation kümesi her yöntemde kullanılmalı mı? **Cevap:** Hayır. Örneğin Bayes kullanılıyorsa model tamamen hesaplamaya dayanır; eğitim sırasında öğrenilen bir parametre yoktur ve çok parametresi de yoktur. Hem hızlı çalışan hem de doğruluğu eğitim sürecine göre değişmeyen bu tür yöntemlerde, hele veri de azsa, validation kullanmanın anlamı yoktur (00:21:00).

## 3. Karışıklık Matrisi

Hoca burayı önemli bir kısım olarak tanıttı: sonraki bütün metrikler bunun üzerine kuruluyordu. Karışıklık matrisi (confusion matrix, Türkçede karmaşıklık matrisi de denir), sınıflandırmada gerçek sınıflar ile modelin tahmin ettiği sınıfları karşılaştıran tablodur. Satırlar gerçek sınıfı (actual class), sütunlar modelin tahmin ettiği sınıfı (predicted class) gösterir (ekrandan, 00:23:37). İki sınıf için sınıflar $C$ (pozitif, "artı") ve $\neg C$ (negatif, "eksi") diye adlandırılır.

| Gerçek \ Tahmin | $C$ | $\neg C$ | Toplam |
|---|---|---|---|
| $C$ | True Positives (TP) | False Negatives (FN) | P |
| $\neg C$ | False Positives (FP) | True Negatives (TN) | N |
| Toplam | P' | N' | P + N |

Dört terimin anlamı slayttaki tanımlarla şöyledir (ekrandan, 00:23:37):

- **True Positive (TP):** Gerçekte pozitif olup model tarafından doğru olarak pozitif etiketlenen örnekler.
- **True Negative (TN):** Gerçekte negatif olup model tarafından doğru olarak negatif etiketlenen örnekler.
- **False Positive (FP):** Gerçekte negatif olduğu halde modelin yanlışlıkla pozitif dediği örnekler.
- **False Negative (FN):** Gerçekte pozitif olduğu halde modelin yanlışlıkla negatif dediği örnekler.

Hocanın önerdiği ezber yolu şudur: "true" ya da "false" sizin sınıflandırıcınızın kararının doğru mu yanlış mı olduğunu; "pozitif" ya da "negatif" ise modelin verdiği sınıfı gösterir. False negative, "model negatif dedi ama bu yanlış" demektir; demek ki örnek gerçekte pozitiftir. False positive, "model pozitif dedi ama yanlış" demektir; örnek gerçekte negatiftir. Pozitif ve negatif sözcüğü modelin bulduğu sınıf için kullanılır, çünkü sonunda görülen şey modelin çıktısıdır.

> **Hocanın vurgusu:** True/false modelin doğru mu yanlış mı yaptığını, pozitif/negatif modelin hangi sınıfı söylediğini gösterir. Sonraki bütün metrikler bu dört terimin üzerine kurulur.

### 3.1 Bilgisayar alma örneği

Önceki haftalarda kullanılan "bilgisayar aldı mı" (buy_computer) veri setinden bir model öğrenildiği ve modelin şu karışıklık matrisini verdiği düşünülsün (ekrandan, 00:33:37):

| Gerçek \ Tahmin | buy_computer = yes | buy_computer = no | Toplam |
|---|---|---|---|
| buy_computer = yes | 6954 | 46 | 7000 |
| buy_computer = no | 412 | 2588 | 3000 |
| Toplam | 7366 | 2634 | 10000 |

Hoca karışıklık matrisinin yalnız test kümesinden çıkarıldığını, eğitim kümesinden çıkarılmadığını vurguladı. Matris şöyle okunur: gerçekten bilgisayar alan 6954 kişiyi model doğru tahmin etmiştir (TP). Gerçekten bilgisayar alan 46 kişiye model "almadı" demiştir; bu tahmin yanlıştır, dolayısıyla bunlar false negative'dir. Gerçekten bilgisayar almayan 2588 kişiyi model doğru bulmuştur (TN). Gerçekte almayan 412 kişiye model "aldı" demiştir; bunlar false positive'dir.

Köşegende doğru tahmin edilenler vardır. Köşegendeki değerler ne kadar yüksek, köşegen dışındakiler ne kadar küçükse modelin başarısı o kadar yüksektir. Bir satırı toplamak, gerçek verideki o sınıfın toplam örnek sayısını verir: $6954 + 46 = 7000$ kişi gerçekten bilgisayar almış, $412 + 2588 = 3000$ kişi almamıştır. Sütun toplamları ise modelin o sınıfa atadığı örnek sayısıdır: model 7366 kişiye "aldı", 2634 kişiye "almadı" demiştir. Model toplam $412 + 46 = 458$ kişiyi yanlış tahmin etmiştir; yani hata sayısı false positive ile false negative'in toplamıdır.

> **Ders sonrası not:** Hoca sütun toplamına bakıp "366 kişi no iken yes demiş" diye başladı, sonra bunun doğru ifade olmadığını kendisi belirtti. $7366 - 7000 = 366$ yalnız net farktır; gerçekte 412 kişiye fazladan "yes" denmiş, 46 gerçek "yes" ise kaçırılmıştır.

**Soru:** Sınıflar illa evet/hayır olmak zorunda mı? **Cevap:** Hayır. Geçen haftaki hayvan örneğindeki gibi sınıflar kuş ve sürüngen olabilir. Aynı tabloda üst satır kuş, alt satır sürüngen olsaydı ilk hücre, gerçekte kuş olup kuş bulunanları; yanındaki hücre gerçekte kuş olup sürüngen bulunanları gösterirdi. Sınıf sayısı ikiden fazla olduğunda matrisin nasıl büyüdüğü ayrıca görüldü (Bölüm 8) (00:33:36).

## 4. Doğruluk ve Hata Oranı

Doğruluk (accuracy), doğru bulunanların tüm örneklere oranıdır. Doğru bulunanlar köşegendeki true positive ve true negative'lerdir:

$$\text{Accuracy} = \frac{TP + TN}{TP + TN + FP + FN}$$

Bu, modelin yüzde kaç doğrulukla çalıştığını verir. Hata oranı (error rate) ise yanlış bulunanların, yani false negative ve false positive'lerin, tüm örneklere oranıdır:

$$\text{Error rate} = \frac{FP + FN}{TP + TN + FP + FN}$$

İki ifadenin paydası aynıdır ve payları toplandığında tüm örnekleri verir. Bu yüzden $\text{Accuracy} = 1 - \text{Error rate}$ yazılabilir: model %80 doğrulukla çalışıyorsa hata oranı %20'dir. Hata oranına yanlış sınıflandırma oranı (misclassification rate) da denir (00:36:16).

## 5. Sınıf Dengesizliği Problemi

Hoca doğruluğun neden yetmediğini önce bir örnekle gösterdi. Bir insanın kanser olup olmadığını gösteren bir test olsun. Elimizdeki veride 300 kanser hastası ve 9700 kanser olmayan kişi, toplam 10000 kişi vardır. Model hastalardan 90'ına doğru olarak "yes", sağlamlardan 9560'ına doğru olarak "no" demiştir (ekrandan, 00:38:37):

| Gerçek \ Tahmin | cancer = yes | cancer = no | Toplam |
|---|---|---|---|
| cancer = yes | 90 | 210 | 300 |
| cancer = no | 140 | 9560 | 9700 |
| Toplam | 230 | 9770 | 10000 |

Doğruluk $(90 + 9560)/10000 = 0{,}965$, yani yaklaşık %96'dır (hoca ekrana "yüzde 96" yazdı). Yalnız buna bakılırsa model çok iyi çalışıyor gibi görünür. Oysa testin amacı kanser hastalarını bulmaktır. Toplam popülasyonda kanser oranı yaklaşık %3'tür ve model bunların ancak üçte birini doğru bulmuştur.

Hoca durumu daha da abarttı: hasta satırındaki 90'ı 0, 210'u 300 yaptı. Bu model hiçbir gerçek hastayı bulamaz, herkese "no" der. Alt satır aynı kalırsa doğruluk $9560/10000 = 0{,}956$, yani yine yaklaşık %95'tir. Model gerçekten hasta olanları hiç bulamazken, hasta olmayanların da yaklaşık yüzde birlik bir kısmına hasta demektedir ($140/9700 \approx 0{,}014$). Doğruluk hesabı yanlış değildir; sorun başka yerdedir.

**Soru:** Gerçekten sorun hastalığın az görülmesi mi? **Cevap:** Hoca, sınıfların yerini değiştirince de aynı sorunun olacağını söyledi: kuş-sürüngen örneğinde model kuşların hiçbirini bulamayıp hepsine sürüngen dese, sürüngenlerin çoğunu da doğru bulsa, aynı durum oluşur. Asıl sorun verinin dengeli olmamasıdır (00:41:15).

Bu örnekte eğitim kümesindeki 10000 örneğin yalnız %3'ü "yes", %97'si "no" sınıfındadır. Veri böyle olduğunda model genellikle az sayıda örneği olan sınıfı iyi öğrenemez, çünkü o sınıftan çok az örnek görür. Buna veri dengesizliği problemi (class imbalance / data imbalance problem) denir (ekrandan, 00:43:37). Slayttaki tanıma göre ilgilenilen ana sınıf nadirdir: çoğunluk negatif sınıf, azınlık pozitif sınıftır. Slaytta ayrıca eğitim örneklerinin yalnız %3'ü kanserse %97 doğruluğun kabul edilemeyeceği, çünkü sınıflandırıcının yalnız kanser olmayanları doğru etiketleyip bütün kanser örneklerini yanlış sınıflandırıyor olabileceği yazıyordu.

Gerçek hayatta bu durum çok sık görülür: tıbbi verilerde hastalık nadirdir; dolandırıcılık (fraud) gibi olaylar nadirdir; nabız verisinde bir milyon düzenli kayda karşılık 100-200 düzensiz kayıt olabilir; afet ya da dolu gibi olaylara ait veriler azdır. Dengesiz veriyle başa çıkmak için yöntemler sonraki derslerde görülecekti. Bu dersin mesajı, veri dengesizse doğruluğun tek başına yeterli olmadığı ve başka metriklere ihtiyaç duyulduğudur.

## 6. Sensitivity ve Specificity

Slayttaki tanımlar şunlardır (ekrandan, 00:48:37):

$$\text{Sensitivity} = \frac{TP}{TP + FN} \qquad \text{Specificity} = \frac{TN}{TN + FP}$$

Sensitivity "true positive recognition rate" (doğru pozitif tanıma oranı), specificity "true negative recognition rate" (doğru negatif tanıma oranı) olarak tanımlanır. Hoca slayta $TP + FN$ altına "tüm pozitifler", $TN + FP$ altına "tüm negatifler" yazdı. Yani sensitivity, gerçek pozitiflerin yüzde kaçının doğru bulunduğunu; specificity, gerçek negatiflerin yüzde kaçının doğru bulunduğunu gösterir. Karışıklık matrisinde ikisi de satıra doğru bölmedir: TP kendi satırının toplamına, TN kendi satırının toplamına bölünür.

Doğruluk pozitif ve negatifleri birlikte değerlendirir; bu iki metrik ise pozitifleri kendi içinde, negatifleri kendi içinde değerlendirir. Kanser örneğinde soru şudur: gerçekten hasta olan kişilerin yüzde kaçına hasta denmiş, hasta olmayanların yüzde kaçına hasta değil denmiş? Sensitivity $90/300 = 0{,}30$ çıkar (hoca önce 90/210 dedi, sonra payda olarak tüm satırı, yani 300'ü kullanmak gerektiğini söyleyip düzeltti).

Hoca bu metriklerin tıpta çok kullanıldığını anlattı. Radyologlar ya da patologlar bilgisayardan bağımsız olarak hastalık değerlendirir ve sonuç doktora göre değişebilir. Örneğin bin kişilik bir hasta grubunu iki farklı doktor değerlendirir, bir de başka bir test sonucu vardır; aralarındaki fark bu metriklerle incelenir. Bu durumda sınıflandırıcı doktorun kendi görüşü olmuş olur.

> **Ders sonrası not:** Hoca sensitivity için "hassasiyet", specificity için "duyarlılık" karşılıklarını kullandı. Türkçe tıp ve istatistik literatüründe yaygın karşılıklar sensitivity için "duyarlılık", specificity için "özgüllük"tür. Terimler İngilizce adlarıyla öğrenilirse karışıklık olmaz.

**Soru:** Kuş-sürüngen örneğinde hangisinin pozitif, hangisinin negatif olduğu nasıl anlaşılır? Kuş üstte yazılınca sensitivity %70 çıksa, sürüngen üstte yazılınca ne olur? **Cevap:** Sınıfların yeri değişince değerler de değişir: önceki sensitivity, bu kez specificity olur. Bu yüzden birçok araç ikili sınıflandırmada hangi sınıfın pozitif kabul edileceğini kullanıcıya sorar (00:47:50). Hoca bunun Weka'da nasıl göründüğünü göstereceğini söyledi, ama kayıtta bu gösterim yer almıyor.

## 7. Recall, Precision ve F Ölçüsü

Aradan sonra hoca, sensitivity ve specificity'yi kısaca tekrar etti ve bunlardan başka çok kullanılan iki metrik daha olduğunu söyledi.

**Recall** sensitivity'nin tamamen aynısıdır; aralarında hiçbir fark yoktur. True positive'ler tüm gerçek pozitiflere, yani $TP + FN$'ye bölünür. Sensitivity'nin bir diğer adı recall'dur.

**Precision** ise true positive'leri, sınıflandırıcının pozitif dediği bütün örneklere, yani $TP + FP$'ye böler (00:54:18). Hoca Türkçesi için "kesinlik" dedi:

$$\text{Recall} = \frac{TP}{TP + FN} \qquad \text{Precision} = \frac{TP}{TP + FP}$$

Hoca formülleri ezberlemek yerine yönlerini hatırlamayı önerdi. Karışıklık matrisinde TP'yi kendi satırına (gerçek pozitiflerin toplamına) doğru bölerseniz recall/sensitivity, kendi sütununa (modelin pozitif dediklerinin toplamına) doğru bölerseniz precision elde edersiniz.

> **Hocanın vurgusu:** TP satıra doğru bölünürse recall (sensitivity), sütuna doğru bölünürse precision olur. Formülü ezberlemeyin, yönünü hatırlayın.

**F ölçüsü (F-measure)**, precision ile recall'u tek bir metrikte göstermek için kullanılır ve aslında ikisinin harmonik ortalamasıdır:

$$F_1 = \frac{2 \times \text{Precision} \times \text{Recall}}{\text{Precision} + \text{Recall}}$$

Hoca slayttaki bir sonraki ölçüyü çok kullanılmadığı için geçti; genellikle F ölçüsü ve $F_1$ ölçüsünün kullanıldığını söyledi. <!-- BELİRSİZ: Hocanın atladığı ölçü karelerde görünmüyor; büyük olasılıkla ağırlıklı F ölçüsü (F-beta). -->

### 7.1 Kanser örneğinde bütün metrikler

Hoca kanser örneğindeki bütün metrikleri sınıfla birlikte hesapladı (ekrandan, 00:56:15):

- **Accuracy:** $(90 + 9560)/10000 = 9650/10000 = 0{,}965$.
- **Error rate:** Ya $1 - \text{Accuracy}$ ya da yanlış bulunanların toplamı: $(210 + 140)/10000 = 350/10000 = 0{,}035$.
- **Sensitivity (Recall):** $90/300 = 0{,}30$. Tüm pozitifler zaten ilk satırdadır.
- **Specificity:** Negatifken negatif bulunanlar bölü tüm negatifler: $9560/9700 \approx 0{,}9856$. Hoca "neredeyse %98-99 gibi bir şey çıkacak" dedi.
- **Precision:** Sütuna doğru: $90/(90 + 140) = 90/230 \approx 0{,}391$.

Sensitivity ve recall %30, precision yaklaşık %39 gibi oldukça düşük çıkmaktadır. Yalnız doğruluğa bakılsaydı "mükemmel bir modelim var" denecekti; bu metrikler modelin aslında iyi çalışmadığını gösterir.

> **Hocanın vurgusu:** Accuracy yazılırken $90 + 9560/10000$ biçiminde yazılırsa önce bölme yapılmış olur. Pay parantez içinde düşünülmelidir: $(90 + 9560)/10000$. Hoca sınavda böyle yazımın puan kaybettirebileceğini ve "derste siz de böyle yazmıştınız" itirazının geçerli olmayacağını söyledi (00:57:30).

## 8. Çok Sınıflı Sınıflandırmada Metrikler

Derste bir öğrencinin sorusu üzerine iki sınıftan fazlası olduğunda ne yapılacağına geçildi. Bu durumda karışıklık matrisi $2 \times 2$'den $m \times m$'ye büyür (ekrandan, 01:01:15):

| Gerçek \ Tahmin | $C_1$ | $C_2$ | ... | $C_m$ | Toplam |
|---|---|---|---|---|---|
| $C_1$ | $CM_{1,1}$ | $CM_{1,2}$ | ... | $CM_{1,m}$ | $AC_1$ |
| $C_2$ | $CM_{2,1}$ | $CM_{2,2}$ | ... | $CM_{2,m}$ | $AC_2$ |
| $C_m$ | $CM_{m,1}$ | $CM_{m,2}$ | ... | $CM_{m,m}$ | $AC_m$ |
| Toplam | $PC_1$ | $PC_2$ | | $PC_m$ | $AC_1 + \dots + AC_m$ |

$CM_{i,j}$'de $i$ gerçek sınıfı, $j$ tahmin edilen sınıfı gösterir; yani $CM_{i,j}$, gerçekte $i$ sınıfında olup sınıflandırıcının $j$ olarak etiketlediği örnek sayısıdır. Örneğin $CM_{1,2}$, aslında $C_1$ olduğu halde $C_2$ bulunan örneklerdir. Köşegende ($CM_{1,1}$'den $CM_{m,m}$'ye) doğru tahminler vardır. İyi bir sınıflandırıcıda örneklerin çoğu köşegende olmalı, diğer girdiler sıfır ya da sıfıra yakın olmalıdır.

Hoca burada internette "confusion matrix" görsel araması yaparak çok sınıflı matrislerin genelde nasıl çizildiğini gösterdi. Beş sınıflı örneklerde hücrelere sayılar yerine oranlar yazılmıştı; her satırın toplamı 1 çıkar, çünkü çok sayıyı okumak zordur ve yüzde biçimi daha kolay anlaşılır. Matrisler bir renk haritasıyla (color map) renklendirilir: köşegenin koyu, diğer hücrelerin açık (sıfıra yakın) çıkması istenir. Bu çizimler hazır araçlarla otomatik üretilir, ama elle çizmek de zor değildir.

### 8.1 Doğruluk ve sınıf bazında precision, recall

Doğruluk kolaydır: köşegendeki değerlerin hepsi toplanır ve tüm değerlerin toplamına bölünür. Hata oranı ya köşegen dışındaki bütün değerlerin toplamının tüm değerlere bölünmesiyle ya da $1 - \text{Accuracy}$ ile bulunur.

Recall ve precision her sınıf için ayrı ayrı hesaplanır (ekrandan, 01:06:15). $C_1$ için recall, o sınıfın doğru bulunanları ($CM_{1,1}$) bölü tüm satırdır; $C_2$ için $CM_{2,2}$ bölü ikinci satır, ve böyle devam eder. Precision ise sütuna doğru bölmedir: $CM_{1,1}$ bölü birinci sütunun tamamı, $CM_{2,2}$ bölü ikinci sütunun tamamı:

$$\text{Precision}_{C_i} = \frac{CM_{i,i}}{\sum_j CM_{j,i}} \qquad \text{Recall}_{C_i} = \frac{CM_{i,i}}{\sum_j CM_{i,j}}$$

Slayttaki tanıma göre precision, $i$ sınıfına atanan örneklerden gerçekten $i$ sınıfında olanların oranı; recall, $i$ sınıfındaki örneklerden doğru sınıflandırılanların oranıdır. Sınıf sayısı 100 olunca her birini ayrı ayrı raporlamanın anlamı yoktur; bu değerlerin ortalaması alınır.

**Soru:** Ortalama alırken ağırlıklı ortalama mı, düz ortalama mı alınmalı? Her sınıftaki örnek sayısı farklı. **Cevap:** Hoca soruyu sınıfa sordu ve bunun iki farklı yolu olduğunu, bunların macro ve micro averaging olduğunu söyleyerek anlatmaya geçti (01:06:22).

### 8.2 Macro averaging

Macro averaging'de her sınıf için precision ve recall ayrı ayrı bulunur ve doğrudan düz ortalaması alınır. Ağırlık, çarpma gibi hiçbir işlem yapılmaz.

### 8.3 Micro averaging

Micro averaging biraz farklıdır. Her sınıf için sanki iki sınıf varmış gibi davranılır: "$C_1$ olanlar" ve "$C_1$ olmayanlar" (one-vs-rest). $C_1$ için bire bir bulunanlar true positive olur; $C_1$ olmayan bütün sınıflar ($C_2$'den $C_m$'ye) tek bir sınıfmış gibi birleştirilir. Böylece $m$ sınıf için $m$ tane $2 \times 2$ karışıklık matrisi kurulur. Hoca bu matrislerin bir araya getirildiğini önce "ortalaması alınıyor" diye anlattı, sonra slayttaki tabloda toplam sembolü olduğunu, ortalama olmadığını belirtti: matrisler toplanarak tek bir "tüm sınıflar" matrisi elde edilir ve precision ile recall bu matristen hesaplanır. Bu yaklaşımda her sınıftaki örnek sayısı işin içine girmiş olur.

### 8.4 E-posta örneği

Slayttaki örnek, üç sınıflı bir e-posta sınıflandırma görevidir: urgent, normal, spam (ekrandan, 01:11:15):

| Gerçek \ Tahmin | urgent | normal | spam |
|---|---|---|---|
| urgent | 30 | 7 | 3 |
| normal | 10 | 40 | 20 |
| spam | 5 | 15 | 70 |

Doğruluk $= 140/200 = \%70$'tir. Satır toplamlarına göre veride 40 urgent, 70 normal, 90 spam örnek vardır.

Hoca one-vs-rest matrislerini tek tek kurdu:

- **Urgent için:** 30 urgent, urgent olarak bulunmuş (TP = 30). 10 tanesi aslında urgent iken 7'si normal, 3'ü spam bulunmuş (FN = 10). Urgent olmadığı halde urgent bulunanlar $10 + 5 = 15$'tir (FP). Urgent olmayıp urgent olmayan bulunanlar $40 + 20 + 15 + 70 = 145$'tir (TN).
- **Normal için:** 40 normal, normal bulunmuş (TP). Normal iken diğer iki sınıf bulunanlar $10 + 20 = 30$'dur (FN). Normal olmadığı halde normal bulunanlar $7 + 15 = 22$'dir (FP); sınıflandırıcı bunlara normal demiş ama bunlar normal değildir. Kalan 108 örnek TN'dir.
- **Spam için:** TP = 70, FN = $5 + 15 = 20$, FP = $3 + 20 = 23$, TN = 87.

Slayttaki tablolar şöyledir (her biri sırasıyla TP, FN / FP, TN düzeninde) (ekrandan, 01:11:15):

| Matris | TP | FN | FP | TN |
|---|---|---|---|---|
| urgent | 30 | 10 | 15 | 145 |
| normal | 40 | 30 | 22 | 108 |
| spam | 70 | 20 | 23 | 87 |
| tüm sınıflar (toplam) | 140 | 60 | 60 | 340 |

Son matristen micro precision $140/(140 + 60) = 0{,}70$ ve micro recall $140/(140 + 60) = 0{,}70$ çıkar. Sınıf bazında precision değerleri $30/45 \approx 0{,}667$, $40/62 \approx 0{,}645$, $70/93 \approx 0{,}753$; recall değerleri $30/40 = 0{,}75$, $40/70 \approx 0{,}571$, $70/90 \approx 0{,}778$'dir. Bunların düz ortalaması macro precision $\approx 0{,}688$ ve macro recall $\approx 0{,}700$'dür (bu sayılar python ile hesaplandı). Hoca slayttaki sonuçlara bakarak macro ve micro averaging'in precision değerlerinin farklı çıktığını gösterdi. <!-- BELİRSİZ: Macro/micro sonuçlarını gösteren slayt karelerde yok; slayttaki sayılar doğrulanamadı. -->

**Soru:** Bu veri dengesiz mi, sensitivity gibi metrikler yalnız dengesiz veride mi kullanılır? **Cevap:** Bu veride 40 urgent, 70 normal, 90 spam vardır. Bu metrikler illa veri dengesizse kullanılacak diye bir şey yoktur; her durumda bunlara da bakılır (01:13:54).

Micro gösterim işleri basitleştirir, ama bir bedeli vardır. Toplam matriste 140 doğru ve 60 false positive görülür; fakat bu 60'ın ne kadarının urgent'tan, ne kadarının başka sınıftan geldiği bilinmez. Bir öğrenci, toplam matristeki "no iken no" hücresinin aslında alt sınıflar arasında yanlış tahminler içerdiğini sordu. Hoca bunun doğru olduğunu söyledi: örneğin urgent'a göre bakıldığında "urgent değilken urgent değil" bulunmuştur ve bu açıdan doğrudur, ama kendi içinde alt sınıflarda yanlış bulunmuş olabilir. Bu ekstra bilgi kaybolur (01:15:55).

### 8.5 Hangi ortalama kullanılmalı?

Macro ve micro ortalama farklı sonuçlar verebilir. Örneğin bir yöntem Python'da scikit-learn ile, aynı yöntem bütün parametreleri aynı tutularak R'da çalıştırıldığında precision değerleri farklı çıkabilir; bunun nedeni böyle küçük hesaplama farkları olabilir. Hoca genellikle ikisi arasında büyük fark çıkmadığını, veri çok dengesizse fark çıkabileceğini, ama o durumda modelin zaten bir şey öğrenemediğini söyledi. Asıl önemli olan, farklı yöntemler farklı araçlarda denendiğinde hepsinin aynı biçimde hesaplanmasıdır; biri macro, öbürü micro hesaplanırsa karşılaştırma anlamlı olmaz.

> **Hocanın vurgusu:** Modelleri karşılaştırırken hepsinde aynı ortalama türünü (macro ya da micro) kullanın.

## 9. Regresyon İçin Hata Ölçüleri

Buraya kadar sınıflar vardı ve sınıfın doğru bulunup bulunmadığına göre karar veriliyordu. Hoca şunu sordu: sınıflandırma değil regresyon yapılıyorsa, yani sürekli (continuous) bir değer tahmin ediliyorsa hata nasıl bulunur? Örneğin gerçek değer 70 iken 62,7 tahmin edildiyse tahmin ne kadar iyidir? (01:18:17)

Test kümesinde çok sayıda örnek olduğu için tek bir farka bakılmaz. **Ortalama mutlak hata** (mean absolute error, MAE) için her örnekte gerçek değerden tahmin çıkarılır, mutlak değeri alınır ve bunların ortalaması alınır. Mutlak değer, tahminin büyük ya da küçük olmasından bağımsız olarak aradaki uzaklığa bakmayı sağlar. Mutlak değer kullanmak istenmezse farkın karesi alınır; buna **ortalama karesel hata** (mean squared error, MSE) denir:

$$\text{MAE} = \frac{1}{n}\sum_{i=1}^{n} \lvert y_i - \hat{y}_i \rvert \qquad \text{MSE} = \frac{1}{n}\sum_{i=1}^{n} (y_i - \hat{y}_i)^2$$

Burada $y_i$ gerçek değer, $\hat{y}_i$ tahmin, $n$ örnek sayısıdır (formüller hocanın sözlü anlatımından yazıldı). Hoca daha önce görülen uzaklık ölçüleriyle bağ kurdu: MAE Manhattan uzaklığına, MSE Öklid uzaklığına benzer. Bunların yüzdeli biçimleri gibi başka ölçüler de vardır, ama genellikle bu ikisi üzerinden tanımlanır.

> **Hocanın vurgusu:** Sınıflandırmada accuracy, sensitivity, precision, recall ve F1'e; sürekli değer tahmininde MAE ve MSE'ye bakılır.

## 10. Performans Değerlendirme Yöntemleri

### 10.1 Öğrenme eğrisi

Slayttaki soru şudur: performansın güvenilir bir tahmini nasıl elde edilir? Bir modelin performansı öğrenme algoritmasının yanında başka etkenlere de bağlıdır: sınıf dağılımı, yanlış sınıflandırmanın maliyeti, eğitim ve test kümelerinin büyüklüğü (ekrandan, 01:21:15).

Slayttaki grafik bir öğrenme eğrisidir (learning curve, eğitim eğrisi). Yatay eksende logaritmik ölçekte örnek sayısı (eğitim kümesi büyüklüğü), dikey eksende doğruluk vardır. Çok az örnekle doğruluk yaklaşık %60'tır; 10 örnek civarında %80'lerin üstüne çıkar, sonra yavaşça artar ve bin örnekten sonra %90'a yaklaşır ama artık pek değişmez. Grafik her veri boyutu için modelin yeniden oluşturulup test edilmesiyle çizilmiştir. Az veriyle kalınsaydı doğruluk %80'lerde kalacaktı. Genelde eğitim verisi büyüdükçe doğruluk artar ve bir noktadan sonra doyuma ulaşır. Slayttaki notlara göre küçük örnek sayısının etkileri tahmindeki yanlılık (bias) ve tahminin varyansıdır; grafikteki dikey çubuklar küçük örneklerde çok geniştir.

### 10.2 Holdout

Holdout, şimdiye kadar kullanılan yöntemdir: veri örneğin %80 eğitim, %20 test olarak bölünür. Test verisi hiçbir şekilde eğitim verisinin içinde olmamalıdır. Bölme oranı veriye göre değişir (örneğin üçte iki eğitim), ama büyük kısım eğitime ayrılır. Veriyi seçerken rastgele seçmek önemlidir: veri yıllara göre toplanmış olabilir ve eski yıllarla eğitip son yılları test olarak kullanmak farklı durumların gözden kaçmasına ve hata oranının büyümesine yol açabilir.

### 10.3 Random sampling

Random sampling'de yine holdout yapılır: test kümesi ayrı durur. Ama model eğitim kümesinin tamamıyla değil, içinden rastgele seçilen bir kısmıyla öğrenilir; birkaç yinelemeden sonra rastgele başka bir alt küme seçilip tekrar çalıştırılır. Yapay sinir ağlarında çok kullanılır, çünkü çok büyük veriyi aynı anda eğitmek mümkün değildir: örneğin 100 örnek seçilip birkaç yineleme yapılır, sonra başka 100 örnekle devam edilir.

### 10.4 k-katlı çapraz doğrulama

Çapraz doğrulamada (cross-validation) önce bir parametreye karar verilir: veri kaç parçaya (fold) bölünecek? Buna k-fold denir ve en yaygını $k = 10$'dur (ekrandan, 01:26:15). Slayttaki tanıma göre veri rastgele $k$ tane birbirini dışlayan (mutually exclusive), yaklaşık eşit büyüklükte alt kümeye bölünür. Parçalar tam eşit olmak zorunda değildir; örnek sayısı bölünmüyorsa bir eksik ya da bir fazla olabilir. $i$. turda $D_i$ test kümesi, kalan $k-1$ alt küme eğitim kümesi olarak kullanılır.

Slayttaki 3 katlı örnekte $S_1$, $S_2$, $S_3$ vardır. Birinci turda $S_2$ ve $S_3$ ile eğitilip $S_1$ ile test edilir ve doğruluk kaydedilir. İkinci turda $S_1$ ve $S_3$ eğitim, $S_2$ test olur. Üçüncü turda $S_1$ ve $S_2$ eğitim, $S_3$ test olur. Böylece her kat bir kez test, $k-1$ kez eğitim için kullanılmış olur. Sonunda doğrulukların ortalaması alınır. Slayttaki tanımda doğruluk tahmini, $k$ turdaki toplam doğru sınıflandırma sayısının ilk verideki toplam örnek sayısına bölünmesidir.

Hoca 1000 örnekli, 5 katlı bir örnek de verdi. Her katta 200 örnek olur. Beş kez eğitim yapılır: önce birinci kat test olur, kalan dördü ile model kurulur ve bu model hiç görmediği birinci kata sorulur; sonra ikinci kat test olur, ve böyle devam eder. Böylece her örnek bir kez test kümesinde kullanılmış olur. Her turda veri değiştiği için her seferinde ayrı bir model oluşturulur.

Bunun faydası şudur: veri azsa, tek bir holdout bölmesinde test kümesine tesadüfen kolay ayrılabilen örnekler düşebilir ve model iyi görünür. Ya da tersine, rastgele bir katta bulunması zor örnekler ve aykırı değerler (outlier) toplanmış olabilir; o kat test olduğunda doğruluk düşer. Katların doğrulukları birbirine yakınsa oluşan model iyi ve veri dağılımı düzgündür. Holdout yapılıp test kümesine aykırı değerler düşseydi doğruluk yanlış raporlanırdı; çapraz doğrulamada bütün veri parça parça hem eğitim hem test olarak kullanılır.

> **Hocanın vurgusu:** Çapraz doğrulama özellikle veri azken kullanılır. Veri büyükse %70-%30 ya da %80-%20 bölmek dengeli bir sonuç verir.

**Soru:** Sonunda tek bir model çıkmıyor mu? **Cevap:** Hoca genellikle oluşturulan modellerden iyi sonuç verenlerden birinin seçildiğini söyledi (01:32:02).

> **Ders sonrası not:** Yaygın uygulamada çapraz doğrulama büyük olasılıkla modelin genel performansını tahmin etmek için kullanılır; kullanılacak son model ise çoğu zaman bütün veriyle yeniden eğitilir. Katlardan en iyisini seçmek, o katın test kümesine özgü şansı modele taşıyabilir.

**Soru:** Test kümesi eğitime katılıyor mu? **Cevap:** Hayır. Test eğitime katılırsa başarı artar, ama model gerçek dünyada iyi çalışmaz. 3 katlı örnekte $S_1$ test iken eğitim yalnız $S_2$ ve $S_3$ ile yapılır, doğruluk $S_1$'den hesaplanır (01:32:53).

### 10.5 Leave-one-out

Hoca sınıfa şunu sordu: veri setinde $n$ satır varsa ve $n$-fold çapraz doğrulama yapılırsa ne olur? (ekrandan, 01:31:15) Örneğin 100 satır için 100 katlı çapraz doğrulama yapılır; her seferinde bir örnek test, kalan 99 örnek eğitim olur. Bu çok yavaş çalışır, çünkü bir yerine yüz model kurulur. Yine de kullanılır, çünkü bazen elde çok az ama çok değerli veri olur. 100 örneğin %70'i eğitime, %30'u teste ayrılırsa eğitim verisi daha da azalır ve model belki hiç çalışmaz; böylece en azından eldeki en fazla veriyle eğitim yapılmaya çalışılır. Buna leave-one-out cross-validation denir (ekrandan, 01:41:15). Slayttaki tanımla $k$, örnek sayısına eşittir ve yöntem küçük veri içindir. Derin öğrenmede kullanılamaz.

Hoca leave-one-out'un amacını öğrenme eğrisine bağladı. Leave-one-out, veri azken ulaşılabilecek en yüksek doğruluğu gösterir; örneğin %93. Sonra veri azaltılarak denenebilir: %90 eğitim, %10 test; %85 eğitim, %15 test. Belki daha az eğitim verisiyle de yaklaşık aynı doğruluğa ulaşılır ve o model kullanılabilir. Bir kez yapıp bırakmamak gerekir.

**Soru:** Leave-one-out'ta her seferinde yalnız bir örneğe soruluyor; bu rastgele olmaz mı, hangi model alınır? **Cevap:** Ardışık iki turun modeli 99 eğitim örneğinden oluşur ve aralarında yalnız bir örnek farklıdır. Bu yüzden oluşan modeller birbirine çok benzer, hatta aynı çıkabilir; hangisinin alındığı pek fark etmez. Amaç, veri az olduğunda veriyi en fazla kullanarak öğrenme eğrisinde holdout'un vereceği %80'lerden %90'a yaklaşılabildiğini ve biraz daha veri olsa modelin daha iyi çalışabileceğini görmektir (01:35:34).

### 10.6 Katmanlı çapraz doğrulama

Katmanlı çapraz doğrulamada (stratified cross-validation) katlar, her kattaki sınıf dağılımı ilk verideki dağılımla yaklaşık aynı olacak biçimde oluşturulur (ekrandan, 01:41:15). Slayttaki örnek: ilk veride 3000 örnek vardır; 600'ü pozitif, 2400'ü negatiftir. Yani verinin yalnız %20'si pozitif sınıftadır ve veri dengesizdir.

Rastgele bölünürse her katın %20'sinin pozitif olması beklenir, ama veri az olduğunda bu garanti değildir. 3 katlı çapraz doğrulamada 600 pozitifin büyük çoğunluğu bir kata, çok azı başka bir kata, belki hiçbiri üçüncü kata gidebilir. O katta model pozitifleri iyi bulamasa bile doğruluk yüksek çıkabilir. Bunu önlemek için 600 pozitif her kata 200 olacak şekilde, 2400 negatif de her kata 800 olacak şekilde dağıtılır. Böylece her katta 1000 örnek olur ve test yapılırken her kattaki dağılımın eşit olduğu bilinir.

<!-- BELİRSİZ: Hoca 01:41:07 civarında katmanlamanın bir sıkıntısından ya da katmanlamadan kaçınılan durumdan söz etti ("şu fold'da zaten çok az negatif var..."); altyazı bozuk, söylenen tam anlaşılamadı. -->

### 10.7 Bootstrap

Bootstrap da veri azken kullanılan bir yöntemdir. Eğitim verisi, ilk veriden rastgele satırlar seçilerek oluşturulur; ama bir örnek bir kez seçildi diye bir daha seçilmesi engellenmez. Slayttaki tanımla her seçimde bir örneğin tekrar seçilip eğitim kümesine yeniden eklenme olasılığı aynıdır (ekrandan, 01:46:15). Örneğin 100 örnekten rastgele 50'si seçilecekse ve ilk seçilen 2. örnekse, 2. örnek havuzdan silinmez ve tekrar gelebilir. Amaç veriyi biraz çoğaltmaktır.

En bilineni **.632 bootstrap**'tir. $d$ örnekli bir veri seti $d$ kez, yerine koyarak (with replacement) örneklenir. Ortaya çıkan $d$ örnek ilk veriyle aynı olmaz: bazı örnekler birkaç kez seçilmiş, bazıları hiç seçilmemiştir. Seçilen örnekler eğitim kümesini, hiç seçilmeyenler test kümesini oluşturur. Slayta göre ilk verinin yaklaşık %63,2'si bootstrap eğitim kümesine girer, kalan yaklaşık %36,8'i test kümesini oluşturur. Bunun nedeni şudur: her örneğin bir seçimde seçilme olasılığı $1/d$, seçilmeme olasılığı $1 - 1/d$'dir; $d$ seçimin hiçbirinde seçilmeme olasılığı

$$\left(1 - \frac{1}{d}\right)^d \approx e^{-1} = 0{,}368$$

olur (ekrandan, 01:46:15). Python kontrolünde $d = 100$ için bu değer yaklaşık 0,366, $d = 1000$ için yaklaşık 0,368'dir.

İşlem bir kez yapılmaz; örnekleme $k$ kez (örneğin 10 ya da 20 kez, parametre ne verildiyse) tekrarlanır ve her seferinde ayrı model kurulur. Modelin genel doğruluğu slayttaki formülle hesaplanır:

$$Acc(M) = \frac{1}{k}\sum_{i=1}^{k}\left(0{,}632 \times Acc(M_i)_{test\_set} + 0{,}368 \times Acc(M_i)_{train\_set}\right)$$

Hoca bu çarpanları, iki kümenin boyutları farklı olduğu için doğrulukların sanki örnek sayısı aynıymış gibi normalize edilerek toplanması diye yorumladı.

> **Ders sonrası not:** Formüldeki ağırlıklar kümelerin boyut oranının tersi değildir: eğitim kümesinde verinin yaklaşık %63,2'si, test kümesinde %36,8'i vardır, ama 0,632 test doğruluğuna, 0,368 eğitim doğruluğuna verilir. Bu ağırlıklandırma büyük olasılıkla, verinin yalnız bir kısmıyla eğitilen modelin test doğruluğunun karamsar, eğitim doğruluğunun ise iyimser olmasını dengelemek içindir. Hoca ayrıca çarpanı bir yerde "0,62" diye söyledi; slayttaki değer 0,632'dir.

**Soru:** Bir örnek birden fazla kez seçilebilir mi? **Cevap:** Evet, bir örnek üç kez, beş kez alınabilir (01:47:29).

Hoca bootstrap'in sezgisini tahtaya bir çizimle anlattı. Artı sınıfından örnekler ve aralarında eksi örnekler olsun; bir de iki artı grubunun arasında aykırı (outlier) bir eksi bulunsun. Bir bootstrap örneğinde bazı artılar alınıp hiç eksi alınmayabilir; o zaman en azından o aykırı eksiden kurtulan bir sınıflandırıcı bulunabilir. Amaç, verinin her yerine bakmak yerine bir kısmını alarak veriyi biraz daha genelleştirmek ve daha iyi model bulmaktır. Bootstrap yapay sinir ağlarında kullanılan bir yöntem değildir, ama Bayes ya da karar ağacı gibi şimdiye kadar görülen yöntemlerde kullanılır.

## 11. Modelleri Karşılaştırma ve ROC Eğrisi

Aradan sonra modellerin nasıl karşılaştırılacağına geçildi. Aynı yöntemle parametreleri değiştirerek birden fazla sınıflandırıcı oluşturulabilir ya da farklı yöntemlerle farklı sınıflandırıcılar kurulabilir. Hangisinin daha iyi olduğuna aynı test kümesinde accuracy, precision ve recall'a bakarak karar verilebilir.

Slaytlarda bunun istatistiksel yolu da vardı: örneğin 10 katlı çapraz doğrulamayla hata oranları bulunup t-testi gibi testlerle karşılaştırma. Slaytta iki model M1 ve M2'nin bağımsız $D_1$ ($n_1$ örnek) ve $D_2$ ($n_2$ örnek) veri setlerinde test edilip $e_1$ ve $e_2$ hata oranlarının bulunduğu, $n_1$ ve $n_2$ yeterince büyükse hata oranlarının normal dağıldığı ($e_i \sim \text{NormalDist}(\mu_i, \sigma_i)$) ve yaklaşık varyansın $\hat{\sigma}_i^2 = e_i(1 - e_i)/n_i$ olduğu yazıyordu (ekrandan, 02:01:15). Hoca bu istatistiksel kısımların anlatılmasının bir hafta daha süreceğini söyleyerek bunları geçti ve bilgisayarcıların daha çok kullandığı ROC eğrisine odaklandı.

### 11.1 ROC eğrisi nedir?

ROC, Receiver Operating Characteristic'in kısaltmasıdır. Adındaki "alıcı" sözcüğünün sınıflandırmayla ilgisi yoktur; yöntem çok eskiden sinyal haberleşmesinde kullanıldığı için bu adı taşır. Slayttaki tanımlara göre (ekrandan, 02:06:15):

- ROC eğrileri sınıflandırma modellerinin görsel karşılaştırması içindir.
- True positive rate ile false positive rate arasındaki ödünleşimi (trade-off) gösterir.
- ROC eğrisinin altındaki alan, modelin doğruluğunun bir ölçüsüdür.
- Eğri, y ekseninde TP oranını (TPR), x ekseninde FP oranını (FPR) çizer.

$$TPR = \frac{TP}{TP + FN} \qquad FPR = \frac{FP}{FP + TN}$$

Bir modelde true positive oranının çok yüksek, false positive oranının düşük olması istenir. Eğri sol üst köşeye ne kadar yaklaşırsa model o kadar iyidir: TPR çok yüksekken FPR çok düşüktür.

> **Ders sonrası not:** Hoca burada TPR ile FPR'nin toplamının 1 olması gerektiğini söyledi. Bu doğru değildir: $TPR + FNR = 1$ ve $FPR + TNR = 1$'dir, TPR ile FPR arasında böyle bir bağ yoktur. Örneğin aşağıdaki örnekte eşik 0,25 iken ikisi de 1'dir.

Köşegen çizgi (diagonal line), hiç modeli olmayan ve sınıfı kafadan, yani %50 olasılıkla söyleyen rastgele bir modelin ROC eğrisidir. Her sınıflandırıcı için bir ROC eğrisi çizilebilir. Eğrinin altında kalan alana **Area Under ROC** (AUC) denir ve modelin doğruluğu hakkında bilgi verir.

### 11.2 İki modeli ROC ile karşılaştırma

Hoca kırmızı eğrinin M1, mavi eğrinin M2 olduğu iki modelli bir grafik çizdi ve hangisinin daha iyi olduğunu sordu (02:05:02). Bir öğrenci M1'in daha iyi olduğunu, çünkü belli bir noktada true positive oranının daha yüksek olduğunu söyledi. Hoca o noktada, negatiflerin %20'sine pozitif denirken M1'in pozitiflerin %50'sinden biraz fazlasını bulduğunu gösterdi. Ama grafiğin başka bir yerinde M2'nin true positive oranı daha yüksekti; orada false positive oranı da yüksekti.

**Cevap:** Eğriler kesiştiğinde tek bir noktaya bakarak hangisinin daha iyi olduğu söylenemez; eğrinin altındaki alana bakmak çok daha fazla bilgi verir. Hocaya göre bu örnekteki iki model de çok iyi değildir: M1'in false positive oranı daha düşüktür; M2'nin true positive oranı yüksektir, ama true positive arttıkça false positive de artar, yani birçok negatife de yanlışlıkla pozitif der.

### 11.3 ROC eğrisi nasıl çizilir?

Bir modelin test kümesindeki her örnek için pozitif sınıfa ait olma olasılığını verdiği düşünülsün: örneğin "bu örnek %95 olasılıkla pozitif", "bu örnek %53 olasılıkla pozitif". Elde bir de örneklerin gerçek sınıfları vardır. Eşik (threshold) adım adım değiştirilir; her eşik için bir TPR ve bir FPR hesaplanır ve bu noktalar eğriyi oluşturur.

Önce iki uç durum:

- **Eşik 1 ise** model hiçbir örneğe pozitif demez. Hiç pozitif denmediği için TP ve FP sıfırdır; TPR = 0, FPR = 0. Bu, eğrinin (0,0) noktasıdır ve eşiğin en yüksek olduğu yerdir.
- **Eşik 0 ise** model bütün örneklere pozitif der. Gerçekten pozitif olanların hepsi bulunur, TPR = 1 olur. Gerçekte negatif olanların hepsine de pozitif denir, FPR = 1 olur. Bu, eğrinin (1,1) noktasıdır ve eşiğin en düşük olduğu yerdir.

Slayttaki örnekte 10 örnek vardır; olasılıklar en küçük 0,25'ten en büyük 0,95'e kadar sıralanmıştır ve beş örnek gerçekte pozitif, beşi negatiftir. Tabloya eşik olarak bir de 1,00 eklenmiştir (ekrandan, 02:11:15):

| Sınıf | + | − | + | − | − | − | + | − | + | + | |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Eşik ≥ | 0,25 | 0,43 | 0,53 | 0,76 | 0,85 | 0,85 | 0,85 | 0,87 | 0,93 | 0,95 | 1,00 |
| TP | 5 | 4 | 4 | 3 | 3 | 3 | 3 | 2 | 2 | 1 | 0 |
| FP | 5 | 5 | 4 | 4 | 3 | 2 | 1 | 1 | 0 | 0 | 0 |
| TN | 0 | 0 | 1 | 1 | 2 | 3 | 4 | 4 | 5 | 5 | 5 |
| FN | 0 | 1 | 1 | 2 | 2 | 2 | 2 | 3 | 3 | 4 | 5 |
| TPR | 1 | 0,8 | 0,8 | 0,6 | 0,6 | 0,6 | 0,6 | 0,4 | 0,4 | 0,2 | 0 |
| FPR | 1 | 1 | 0,8 | 0,8 | 0,6 | 0,4 | 0,2 | 0,2 | 0 | 0 | 0 |

Hoca ilk sütunları adım adım hesapladı:

- **Eşik ≥ 0,25:** 0,25 dahil bütün örneklere pozitif denir. Beş pozitifin hepsine pozitif denmiştir: TP = 5, TPR = $5/5 = 1$. Beş negatifin hepsine de pozitif denmiştir; bunlar false positive olur: FPR = $5/5 = 1$. Nokta (1, 1).
- **Eşik ≥ 0,43:** 0,43 ve üstü pozitif, altı negatif sayılır. Eşiğin altında yalnız 0,25'teki örnek kalır; ona negatif denmiştir ama aslında pozitiftir, yani false negative'dir. Altta true negative yoktur (TN = 0). Üstteki beş negatife pozitif denmiştir (FP = 5); dört pozitif doğru bulunmuştur (TP = 4). TPR = $4/5 = 0{,}8$, FPR = $5/5 = 1$. Nokta (1, 0,8).
- **Eşik ≥ 0,53:** Altta 0,25(+) ve 0,43(−) kalır. 0,43'teki negatife negatif denmiştir (TN = 1); 0,25'teki pozitife negatif denmiştir (FN = 1). Üstte dört pozitif (TP = 4) ve dört negatif (FP = 4) kalır. TPR = $4/5 = 0{,}8$, FPR = $4/5 = 0{,}8$. Nokta (0,8, 0,8).

> **Ders sonrası not:** Hoca eşik 0,53 için sözlü hesapta önce TPR'yi 3/5, sonra FPR'yi 0,6 olarak söyledi. Slayttaki tablo ve python kontrolü doğru değerin TPR = 0,8, FPR = 0,8 olduğunu gösterir (ekrandan, 02:11:15).

Eşik bu şekilde adım adım yükseltilir. En son eşik 1,00 alındığında hiçbir örnek pozitif sayılmaz; TPR ve FPR sıfır çıkar ve eğri (0,0) noktasına ulaşır. Python kontrolü tablodaki bütün TP, FP, TN, FN, TPR ve FPR değerlerini doğruladı.

> **Ek bilgi (derste anlatılmadı):** Tablodaki üç 0,85 sütunu ayrı ayrı eşik gibi işlenmiştir; yani aynı puanlı örnekler sıralamadaki konumlarına göre tek tek ayrılmıştır. Eşik gerçekten "≥ 0,85" değeri olarak uygulansaydı üç örnek birlikte pozitif sayılır ve bu üç sütunun hepsinde TP = 3, FP = 3 çıkardı.

Bu örnekte çizilen eğri köşeli, basamak basamak çıkmıştır. Kitaplardaki ROC eğrilerinin yumuşak bir kavis gibi görünmesinin nedeni, gerçekte çok daha fazla veri olmasıdır. Bazı araçlar eğriyi yumuşatarak (smooth) çizer; gerçek çizim ya da kendi yazdığınız kod ise basamak basamak gider. AUC, eğrinin altında kalan alandır; üst taraftaki alan $1 \times 1$'lik karenin geri kalanıdır ve kullanılmaz.

Hoca bir de bütün örneklerin mükemmel ayrıldığı durumu düşündürdü: pozitiflerin hepsi negatiflerin hepsinden yüksek olasılık alsaydı, eğri başta hiç yükselmeden ilerleyip sonra birden tepeye çıkacak, yani köşeyi izleyecekti. Gerçek dünyada böyle örnekler çok nadir görülür.

> **Hocanın vurgusu:** ROC eğrisinin eşik değiştirilerek nasıl çizildiği sorulabilir.

## 12. Model Seçimini Etkileyen Diğer Konular

Model seçerken doğruluk, precision ve recall'un yanında başka konulara da bakılır (ekrandan, 02:21:15):

- **Doğruluk (accuracy):** sınıflandırıcının sınıf etiketini doğru tahmin etmesi.
- **Hız (speed):** modeli kurma süresi (training time) ve modeli kullanma süresi (classification/prediction time). Hoca eğitim süresinin çok önemli olmadığını, çünkü eğitimin bir kez yapılıp modelin sonra hep kullanıldığını; asıl test (tahmin) süresinin önemli olduğunu söyledi.
- **Gürbüzlük (robustness):** gürültülü ve eksik değerlerle başa çıkma. Modelin aykırı ve gürültülü verileri nasıl sınıflandırdığı, örneğin onları çoğunlukla A sınıfına mı B sınıfına mı attığı incelenmelidir.
- **Ölçeklenebilirlik (scalability):** diskte duran büyük veri tabanlarında verimlilik. Hoca, Azure gibi bulut sistemlerinde bu algoritmaların hazır bulunduğunu anlattı: önce yerelde en iyi parametreler ve en iyi model bulunur, sonra modeli bulutta çalıştırırken bu parametreler verilir. Algoritmanın bulutta nasıl ölçeklendiğine, gerekirse sentetik veri üretilerek bakılması gerekebilir.
- **Yorumlanabilirlik (interpretability):** modelin sağladığı anlayış ve kavrayış.
- **Diğer ölçüler:** örneğin karar ağacının büyüklüğü ya da sınıflandırma kurallarının sadeliği gibi kuralların iyiliği.

## Örnek Sorular

**Soru 1** (ekrandan, 00:56:15 ve 00:38:37): Kanser testi için karışıklık matrisi şöyledir: cancer = yes satırında 90 (tahmin yes), 210 (tahmin no), toplam 300; cancer = no satırında 140 (tahmin yes), 9560 (tahmin no), toplam 9700; genel toplam 10000. Accuracy, error rate, sensitivity, specificity, precision ve recall'u hesaplayın.

> **Çözüm (derste verildi):** Accuracy $= (90 + 9560)/10000 = 0{,}965$. Error rate $= (210 + 140)/10000 = 0{,}035$ (ya da $1 - 0{,}965$). Sensitivity = Recall $= 90/300 = 0{,}30$. Specificity $= 9560/9700 \approx 0{,}986$. Precision $= 90/(90 + 140) \approx 0{,}391$. Doğruluk yüksek olsa da model hastaların yalnız %30'unu bulmaktadır. (Değerler python ile doğrulandı. Derste hesaplanmayan $F_1$ değeri $2 \times 0{,}391 \times 0{,}30 / (0{,}391 + 0{,}30) \approx 0{,}340$'tır.)

**Soru 2** (derste sözlü, 00:38:41): Aynı örnekte model hiçbir hastayı bulamasaydı (TP = 0, FN = 300) ve alt satır aynı kalsaydı doğruluk kaç olurdu? Sorun nedir?

> **Çözüm (derste verildi):** Doğruluk $9560/10000 = 0{,}956$, yani yaklaşık %95 olur. Model gerçek hastaların hiçbirini bulamadığı halde doğruluk yüksek görünür. Sorun sınıf dengesizliğidir: örneklerin yalnız %3'ü pozitif sınıftadır, model azınlık sınıfı öğrenememiştir ve doğruluk tek başına yanıltıcıdır.

**Soru 3** (derste sözlü, 00:33:08): Bilgisayar alma örneğinde (TP = 6954, FN = 46, FP = 412, TN = 2588) model toplam kaç kişiyi yanlış tahmin etmiştir?

> **Çözüm (derste verildi):** Yanlış tahminler false positive ile false negative'in toplamıdır: $412 + 46 = 458$. (Derste hesaplanmayan doğruluk $(6954 + 2588)/10000 = 0{,}9542$'dir.)

**Soru 4** (derste sözlü, 00:47:50): İkili sınıflandırmada kuş üst satırda, sürüngen alt satırda yazılınca sensitivity %70 çıkıyor. Sınıfların yeri değiştirilirse ne olur?

> **Çözüm (derste verildi):** Hangi sınıfın pozitif sayıldığı değiştiği için değerler değişir: önceki sensitivity değeri bu kez specificity olur. Bu yüzden araçlar ikili sınıflandırmada hangi sınıfın pozitif alınacağını sorar.

**Soru 5** (ekrandan, 01:11:15): Üç sınıflı e-posta örneğinde gerçek satırlar urgent (30, 7, 3), normal (10, 40, 20), spam (5, 15, 70) biçimindedir. Doğruluğu, her sınıf için one-vs-rest karışıklık matrislerini ve tüm sınıflar için toplam matrisi bulun.

> **Çözüm (derste verildi):** Doğruluk $140/200 = \%70$. Urgent: TP = 30, FN = 10, FP = 15, TN = 145. Normal: TP = 40, FN = 30, FP = 22, TN = 108. Spam: TP = 70, FN = 20, FP = 23, TN = 87. Toplam matris: TP = 140, FN = 60, FP = 60, TN = 340.

> **Çözüm (derste verilmedi):** Toplam matristen micro precision $= 140/200 = 0{,}70$ ve micro recall $= 140/200 = 0{,}70$ çıkar. Sınıf bazında precision değerleri yaklaşık 0,667, 0,645, 0,753; recall değerleri 0,75, 0,571, 0,778'dir. Macro precision $\approx 0{,}688$, macro recall $\approx 0{,}700$'dür (python ile hesaplandı).

**Soru 6** (derste sözlü, 01:06:22): Çok sınıflı sınıflandırmada sınıf bazındaki precision ve recall değerlerinin ortalaması alınırken ağırlıklı ortalama mı, düz ortalama mı alınmalıdır?

> **Çözüm (derste verildi):** İki yol vardır. Macro averaging her sınıfın değerinin düz ortalamasını alır. Micro averaging one-vs-rest matrislerini toplayıp metrikleri toplam matristen hesaplar; böylece sınıfların örnek sayıları hesaba girer. Karşılaştırılan bütün modellerde aynı yol kullanılmalıdır.

**Soru 7** (derste sözlü, 01:18:17): Sınıflandırma değil de sürekli bir değer tahmin ediliyorsa (örneğin gerçek değer 70 iken 62,7 tahmin edildiyse) hata nasıl ölçülür?

> **Çözüm (derste verildi):** Test kümesindeki bütün örnekler için gerçek değer ile tahmin arasındaki farkın mutlak değerinin ortalaması (MAE) ya da karesinin ortalaması (MSE) kullanılır.

**Soru 8** (ekrandan, 01:31:15): Veri setinde $n$ satır varsa ve $n$-fold çapraz doğrulama yapılırsa ne olur? 100 satır için açıklayın.

> **Çözüm (derste verildi):** Bu leave-one-out çapraz doğrulamadır. 100 satırda 100 kat olur; her turda 1 örnek test, 99 örnek eğitim için kullanılır ve 100 model kurulur. Çok yavaştır, ama çok az veri olduğunda eldeki verinin en fazlasıyla eğitim yapmayı sağlar.

**Soru 9** (ekrandan, 01:41:15): 3000 örnekli bir veri setinde 600 örnek pozitif, 2400 örnek negatiftir. 3 katlı katmanlı çapraz doğrulamada her katta kaç pozitif ve kaç negatif örnek olur? Neden böyle yapılır?

> **Çözüm (derste verildi):** Her kata 200 pozitif ve 800 negatif, toplam 1000 örnek düşer. Rastgele bölmede az sayıdaki pozitifler katlara çok eşitsiz dağılabilir; bir katta hiç pozitif olmayabilir ve o katın doğruluğu yanıltıcı biçimde yüksek çıkabilir. Katmanlama her katta ilk verideki sınıf dağılımını korur.

**Soru 10** (derste sözlü, 02:07:42): ROC eğrisi çizilirken eşik 1 alınırsa ve eşik 0 alınırsa TPR ve FPR kaç olur?

> **Çözüm (derste verildi):** Eşik 1'de hiçbir örneğe pozitif denmez; TPR = 0, FPR = 0, yani (0,0) noktası. Eşik 0'da bütün örneklere pozitif denir; bütün pozitifler bulunur (TPR = 1), bütün negatiflere de pozitif denir (FPR = 1), yani (1,1) noktası.

**Soru 11** (ekrandan, 02:11:15): Sıralanmış olasılıklar ve gerçek sınıflar 0,25(+), 0,43(−), 0,53(+), 0,76(−), 0,85(−), 0,85(−), 0,85(+), 0,87(−), 0,93(+), 0,95(+) biçimindedir. "Eşik ≥ 0,43" ve "eşik ≥ 0,53" için TP, FP, TN, FN, TPR ve FPR'yi bulun.

> **Çözüm (derste verildi, slayttaki tabloyla):** Eşik ≥ 0,43: TP = 4, FP = 5, TN = 0, FN = 1; TPR = 0,8, FPR = 1. Eşik ≥ 0,53: TP = 4, FP = 4, TN = 1, FN = 1; TPR = 0,8, FPR = 0,8. (Hoca 0,53 için sözlü hesapta farklı değerler söyledi; doğru değerler slayttaki tablodakilerdir ve python ile doğrulandı.)

**Soru 12** (derste sözlü, 02:05:02): İki modelin ROC eğrileri kesişiyor: M1 düşük FPR bölgesinde, M2 yüksek FPR bölgesinde daha yüksek TPR veriyor. Hangisi daha iyidir?

> **Çözüm (derste verildi):** Tek bir noktaya bakarak karar verilemez. Eğrilerin altındaki alana (AUC) bakılır; alan büyük olan model daha iyidir.

## Dersin Toparlaması

Bu derste sınıflandırıcıların nasıl değerlendirileceği görüldü. Karışıklık matrisinin dört terimi (TP, TN, FP, FN) üzerine doğruluk ve hata oranı kuruldu. Kanser örneği, sınıf dengesizliği olduğunda doğruluğun tek başına yanıltıcı olduğunu gösterdi; bu yüzden sensitivity (recall), specificity, precision ve $F_1$ ölçüsü tanımlandı. Çok sınıflı durumda metrikler her sınıf için satır ve sütun yönünde hesaplandı ve macro ile micro averaging ile birleştirildi. Regresyon için MAE ve MSE tanıtıldı.

Performansı güvenilir biçimde tahmin etmek için öğrenme eğrisi, holdout, random sampling, k-katlı çapraz doğrulama, leave-one-out, katmanlı çapraz doğrulama ve .632 bootstrap yöntemleri anlatıldı; çoğunun özellikle veri az olduğunda önem kazandığı vurgulandı. Son olarak modeller ROC eğrisi ve eğrinin altındaki alanla karşılaştırıldı ve hız, gürbüzlük, ölçeklenebilirlik ve yorumlanabilirlik gibi model seçimi ölçütleri sayıldı. Hoca, slayt destesinin ikinci kısmı olan topluluk yöntemlerinin (bagging ve boosting) sonraki derste anlatılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
