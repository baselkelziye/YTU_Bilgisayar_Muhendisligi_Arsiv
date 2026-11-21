# Ders 10 Genişletilmiş Notu: Makine Öğrenmesinde Performans Değerlendirme ve Crowdsourcing

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Performans Değerlendirmeye Giriş
- 2. Regresyon Metrikleri: MAE, MAPE, MSE, RMSE
- 3. Sınıflandırma ve Karışıklık Matrisi
- 4. Doğruluk ve Dengesiz Veri Problemi
- 5. Recall, Precision, Specificity, FPR ve F1 Skoru
- 6. Çok Sınıflı Karışıklık Matrisinde Recall ve Precision
- 7. ROC Eğrisi ve Köşegen Üzerine Bir Programlama Sorusu
- 8. Dengesiz Veride Eğitim ve Test Kümesi Kurma
- 9. Crowdsourcing: Tanım ve Temel Döngü
- 10. Participatory ve Opportunistic Crowdsourcing
- 11. Crowdsourcing Uygulamalarının Dört Kategorisi
- Örnek Sorular

## 1. Performans Değerlendirmeye Giriş

Ders, önceki haftalarda başlanıp çok konuşulamamış olan performans metrikleriyle açıldı. Hoca önce bu konuyu tamamlayıp ardından crowdsourcing konusuna geçeceğini, sensör ağlarını crowdsourcing'den sonraya bıraktığını söyledi. Tahtanın başlığı "Performance Evaluation for Machine Learning" idi ve sayfa iki sütuna ayrılmıştı: solda "Regression", sağda "Classification" (ekrandan, 00:20:00).

Hocanın ilk sorusu, bir modelin başarısını ortaya koymak için neye ihtiyaç duyulduğuydu. Bir öğrenci regresyon problemlerinde ortalama kare hata gibi sayısal hata değerlerinin, sınıflandırma problemlerinde ise karışıklık matrisinden doğru bilinenlerin toplama oranı gibi ölçülerin kullanıldığını söyledi. Hoca bu ayrımı onaylayarak iki tarafı sırayla ele aldı.

## 2. Regresyon Metrikleri: MAE, MAPE, MSE, RMSE

### 2.1 Dört metrik

Regresyon problemlerinde kullanılan dört metrik tahtaya alt alta yazıldı (ekrandan, 00:20:00):

- MAE: Mean Absolute Error (ortalama mutlak hata)
- MAPE: Mean Absolute Percentage Error (ortalama mutlak yüzde hata)
- MSE: Mean Squared Error (ortalama kare hata)
- RMSE: Root Mean Squared Error (ortalama kare hatanın karekökü)

Hoca, hepsine birden mi bakmak gerektiğini, hangi durumda hangisinin tercih edileceğini sordu. Sınıftan bu metrikleri ilk kez gördüğünü söyleyen bir cevap gelince açıklamaya kendisi girdi.

### 2.2 MAE ve MAPE

MAE için tahtaya şu toplam yazıldı (ekrandan, 00:20:00):

$$\sum_{i=1}^{k} |x_i - y_i|$$

Burada $x_i$ ve $y_i$, $i$'nci örnek için tahmin edilen değer ile gerçek değerdir. MAE ve MAPE hesaplanırken tahmin ile gerçek değer arasındaki fark alınır ve bu farkların mutlak değerleri toplanır.

> **Ek bilgi (derste anlatılmadı):** Standart tanımda MAE bu toplamın örnek sayısına bölünmesiyle bulunur: $MAE = \frac{1}{k}\sum_{i=1}^{k}|x_i - y_i|$. MAPE'de her fark gerçek değere oranlanır: $MAPE = \frac{100}{k}\sum_{i=1}^{k}\left|\frac{y_i - x_i}{y_i}\right|$. MSE farkların karelerinin ortalaması, RMSE de MSE'nin kareköküdür; RMSE hedef değişkenle aynı birimdedir ve büyük hataları MAE'den daha fazla cezalandırır.

Hoca bu iki metriğin farkını dönem projelerinin konusu olan trafik akış hızı tahmini üzerinden anlattı ve daha önce de dile getirdiği bir noktayı hatırlattı: 60 km/sa hızla gidilen bir noktadaki 6 km/sa'lik sapma ile 30 km/sa hızla gidilen bir noktadaki 6 km/sa'lik sapma eşit değildir. Yüzde olarak birinde hata %10, diğerinde %20'dir (python ile kontrol edildi: $6/60 = 0{,}10$, $6/30 = 0{,}20$). Eğer hedef, herhangi bir noktadaki oransal sapmaysa MAPE kullanmak gerekir.

Ancak hoca trafik akış hızında MAE'nin de yeterli olabileceğini savundu. ±6 km/sa'lik bir sapma aslında oldukça başarılı bir tahmindir; hedef bunu ±5 seviyesine indirmektir. Kısa vadeli tahminlerde bu yapılabiliyor, uzun vadede kolay değildir. 30 yerine 36 ya da 60 yerine 66 tahmin etmek, bir yerden bir yere gidiş hesabını orantılı olarak etkiler; yani oransal fark yolculuk süresine zaten aynı biçimde yansır. Oransal sonuç sunan çalışmalar olsa da bu problemde MAE ile çalışmak yeterli olacaktır.

### 2.3 MSE ve RMSE

Hoca MSE ve RMSE için şunları söyledi: büyük değerler söz konusu olduğunda hesabı daha rahat olsun diye RMSE tercih edilir; bu değerler büyüdükçe tahminin o kadar saptığı görülür. Özellikle boyutu birden fazla olan, yani öznitelik sayısı fazla ve birden fazla çıktının tahmin edildiği problemlerde MSE ve RMSE'yi kullanmak daha akıllıcadır. Hoca bu metriklerin ne olduğunu bilmenin yeterli olduğunu, trafik tahmini literatürü incelendikçe neden ve nasıl tercih edildiklerinin görüleceğini ekleyerek konuyu kapattı.

<!-- BELİRSİZ: MSE ve RMSE'nin formülleri tahtaya yazılmadı; "hesabı daha rahat olsun" gerekçesinin tam anlamı altyazıdan net değil. -->

## 3. Sınıflandırma ve Karışıklık Matrisi

### 3.1 İkili ve çok sınıflı sınıflandırma

Sınıflandırma tarafında temel araç karışıklık matrisidir (confusion matrix). İki tür sınıflandırmadan söz edildi: ikili sınıflandırma (binary classification) ve çok sınıflı sınıflandırma (multi-class classification) (ekrandan, 00:25:00).

### 3.2 Fraud örneğiyle ikili matris

Hoca önce "Actual Yes / Actual No" ve "Predict Yes / Predict No" etiketli bir matrisle başladı, sonra örneği somutlaştırdı: kredi kartı sahtecilik (fraud) tespiti. Matrisin satırlarına gerçek sınıflar ("Fraud Actual", "Non-Fraud Actual"), sütunlarına tahminler ("Fraud Predict", "Non-Fraud Predict") yazıldı. Altına da "Fraud: Positive", "Non-Fraud: Negative" notu düşüldü (ekrandan, 00:25:00).

Pozitif sınıfın hangisi olduğunun seçimi kritiktir. Bir öğrenci kuralı şöyle özetledi ve hoca onayladı: pozitif durum genelde o olayın gerçekleştiği, yakalamak istediğimiz durumdur. "COVID pozitif" dediğimizde istemediğimiz ama tespit etmek istediğimiz durum pozitiftir; fraud probleminde de fraud pozitiftir.

Köşegen kolaydır: gerçek fraud ve tahmin fraud TP (true positive), gerçek non-fraud ve tahmin non-fraud TN (true negative). Köşegen dışındaki iki gözün adı ise uzun bir tartışmaya yol açtı. Hoca ilk yazımda gerçek fraud satırındaki ikinci gözü (tahmin non-fraud) FP, alt satırdaki ilk gözü FN olarak yazdı (ekrandan, 00:25:00). Öğrenciler buna itiraz etti: bu gözde gerçekte fraud olan bir işlem sistem tarafından negatif (non-fraud) tahmin edilmiştir; tahmin negatif ve yanlış olduğu için adı false negative olmalıdır. Hoca bir kaynaktan kontrol ettikten sonra öğrencilerin haklı olduğunu, kendisinin bu matrisi alışkanlıkla ters yazdığı için karıştırdığını söyledi ve tahtayı düzeltti (ekrandan, 00:30:00).

Doğru yerleşim (gerçek solda, tahmin üstte):

| | Fraud Predict | Non-Fraud Predict |
|---|---|---|
| Fraud Actual | TP | FN |
| Non-Fraud Actual | FP | TN |

- Non-fraud olan bir işlemi fraud tahmin etmek: tahmin pozitif ama yanlış, yani FP.
- Fraud olan bir işlemi non-fraud tahmin etmek: tahmin negatif ama yanlış, yani FN.

İsimlendirmeyi hatırlamanın yolu şudur: ikinci kelime (positive/negative) modelin tahminini, birinci kelime (true/false) bu tahminin doğru olup olmadığını söyler.

> **Hocanın vurgusu:** Bu matris her zaman kafa karıştıran bir problemdir; bir kez doğru oturtulursa sonrası rahatlar. Gerçek değerleri (actual) her zaman sola, tahminleri (predict) her zaman üste yazın, karışmasın.

### 3.3 Çok sınıflı matris

Çok sınıflı problemde matrisin boyutu sınıf (çıkış) sayısı kadardır: 10 çıkışlı bir sınıflandırma problemi için 10×10'luk bir matris açılır. Köşegendeki değerler doğru tahminlerdir ve sistemin başarısını gösterir. Satırlar ve sütunlar da her sınıfın recall ve precision değerlerinin hesaplanmasında kullanılır (bölüm 6). Tahtada köşegeni çizilmiş boş bir ızgara bu yapıyı gösteriyordu (ekrandan, 00:30:00).

## 4. Doğruluk ve Dengesiz Veri Problemi

### 4.1 Doğruluk formülü

Doğruluk (accuracy), doğru tahminlerin bütün tahminlere oranıdır (ekrandan, 00:30:00):

$$Accuracy = \frac{TP + TN}{TP + FP + TN + FN}$$

### 4.2 Doğruluğa neden her zaman güvenilmez?

Hoca, doğruluğun birçok problemde insanı yanıltabileceğini söyleyip nedenini sordu. Bir öğrenci çok sınıflı problemlerde birbirine benzeyen sınıfların köşegen dışında yığılmasına dikkat çekti; başka bir öğrenci asıl sorunun dengesiz (imbalanced) veri setleri olduğunu söyledi. Hoca ikinci cevabı bir örnekle açtı.

Örnek: 1 milyon normal işlem ve 1000 fraud işlemi olsun. Model 1 milyon normal işlemin 999.990'ını doğru bilmiş, 1000 fraud'un ise yalnız 100'ünü doğru bilmiş olsun.

- Verilen: $TP = 100$, $FN = 1000 - 100 = 900$, $TN = 999.990$, $FP = 1.000.000 - 999.990 = 10$ (ara adım eklendi).
- Doğruluk: $\dfrac{100 + 999.990}{1.001.000} \approx 0{,}9991$, yani yaklaşık %99,9 (ara adım eklendi).
- Fraud sınıfındaki başarı: $100/1000 = 0{,}10$, yani %10.

(Değerler python ile kontrol edildi.) Doğruluk neredeyse kusursuz görünürken model asıl yakalaması gereken fraud'ların %90'ını kaçırmaktadır. Bu yüzden veri setinin dengesiz dağıldığı durumlarda sınıflar kendi içinde değerlendirilmelidir; ikili sınıflandırmada da true positive rate, true negative rate ve false positive rate gibi ölçülere bakılmalıdır.

## 5. Recall, Precision, Specificity, FPR ve F1 Skoru

### 5.1 True positive rate = Recall = Sensitivity

Hoca true positive rate'in iki başka adı olduğunu sordu; öğrenciler recall ve sensitivity cevaplarını verdi. Üçü aynı ölçüdür ve birbirinin yerine kullanılır (ekrandan, 00:35:00):

$$TPR = Recall = Sensitivity = \frac{TP}{TP + FN}$$

Sözle: veri setinde gerçekten pozitif olanların ne kadarının pozitif bulunabildiği. Paydadaki TP + FN, matristeki gerçek fraud satırının toplamıdır, yani gerçekte fraud olan bütün işlemler. Bu noktada bir öğrenci paydanın neden FN içerdiğini sordu; hoca matrise dönerek FN'nin de gerçek fraud'lardan oluştuğunu, TP ile FN'nin toplamının "aslında gerçekten fraud olanlar" olduğunu gösterdi.

### 5.2 Precision

Precision, pozitif tahmin edilenlerin kaçının doğru tahmin edildiğidir (ekrandan, 00:35:00):

$$Precision = \frac{TP}{TP + FP}$$

Paydadaki TP + FP, matrisin "Fraud Predict" sütununun toplamıdır.

> **Hocanın vurgusu:** Recall ve precision sürekli birbirine karışır. Recall'u fraud örneğiyle hatırlayın: elimizdeki fraud'ların ne kadarını başarıyla tahmin ettik? Precision ise: fraud diye getirdiklerimizin içinden ne kadarı gerçekten fraud?

### 5.3 Specificity

Specificity, true negative rate'e karşılık gelir; fraud örneğinde non-fraud'ları bilme başarısıdır. Amaç negatif sınıfın başarısını kendi içinde göstermektir (ekrandan, 00:40:00):

$$Specificity = TNR = \frac{TN}{TN + FP}$$

### 5.4 False positive rate

Hoca false positive rate'in şu ana kadar yazılanlardan biriyle nasıl ifade edileceğini sordu. Bir öğrenci önce "1 − sensitivity" dedi, ardından doğru cevap "1 − specificity" olarak verildi (ekrandan, 00:40:00):

$$FPR = 1 - Specificity = \frac{FP}{TN + FP}$$

(İkinci eşitlik ara adım olarak eklendi; $1 - \frac{TN}{TN+FP} = \frac{FP}{TN+FP}$.)

False positive'ler birçok problemde çok önemlidir. Fraud örneğinde, fraud olmayan işlemlere fraud denirse herkesin telefonuna sürekli "bu işlemde bir hata olabilir, size ait değilse şu numarayı arayın" mesajları gelir. Bu bir noktadan sonra kişiyi rahatsız eder; false positive sayısı arttıkça sorun büyür.

### 5.5 F1 skoru

Precision ve recall'u birlikte kullanan metrik F1 skorudur; ikisinin harmonik ortalamasıdır (ekrandan, 00:45:00):

$$F1 = \frac{2 \cdot Precision \cdot Recall}{Precision + Recall}$$

Hocaya göre F1 skoru bu tür dengesiz veri setleri için kullanılabilecek en iyi ölçütlerden biridir; hem precision'ı hem recall'u işin içine kattığı için model başarısı F1 üzerinden ortaya konabilir.

## 6. Çok Sınıflı Karışıklık Matrisinde Recall ve Precision

### 6.1 Satır ve sütunların anlamı

Hoca çok sınıflı matrise dönüp (satırlar sınıf 1'den sınıf $n$'ye gerçek değerler, sütunlar sınıf 1'den sınıf $n$'ye tahminler) yukarıdan aşağıya ve soldan sağa bakıldığında hangisinin recall, hangisinin precision vereceğini sordu. Bir öğrenci bunun sınıf bazında değerlendirilmesi gerektiğini söyledi; hoca her sınıfın kendi recall ve precision değerini hesaplamak istediğini belirtti. Tahtada satırların sonuna "Recall", sütunların altına "Precision" yazıldı (ekrandan, 00:50:00).

### 6.2 Aktivite tanıma örneği

Formülün matris üzerinde nasıl uygulandığı tam oturmayınca hoca sayısal bir örnek kurdu. Sınıflar aktivite tanımadan seçildi: walking (sınıf 1), running, sitting, lying ve diğerleri. Gerçek değerler solda, tahminler üstte (ekrandan, 00:55:00 ve 01:00:00).

Walking satırı (gerçekte walking olan örnekler):

| Tahmin | walking | running | sitting | (4. sınıf) | diğer | diğer |
|---|---|---|---|---|---|---|
| Gerçek walking | 100 | 5 | 1 | 4 | 0 | 0 |

**Walking recall'u.** Gerçekte walking olan $100 + 5 + 1 + 4 = 110$ örneğin 100'üne walking denmiştir. Walking olarak gelmesi gereken 10 örnek başka sınıflara gitmiştir; bunlar walking sınıfı için false negative'lerdir. Tahtada hesap $\frac{100}{100+5+1+4}$ olarak yazıldı (ekrandan, 00:55:00):

$$Recall_{walking} = \frac{100}{110} \approx 0{,}909$$

Hoca bunu ikili formülle bağladı: hesap yine $\frac{TP}{TP + FN}$'dir, yalnız burada false negative'ler $FN_1, FN_2, FN_3$ gibi birden fazla gözden gelir. Yani köşegendeki değer alınır ve o satırdaki bütün değerlerin toplamına bölünür.

**Walking precision'ı.** Walking sütununda (walking tahmin edilenler) 100'ün yanında başka iki sınıftan 10'ar örnek vardır, kalan gözler 0'dır (ekrandan, 01:00:00). Model toplam $100 + 10 + 10 = 120$ örneğe walking demiştir ama bunların yalnız 100'ü gerçekten walking'dir:

$$Precision_{walking} = \frac{100}{120} \approx 0{,}833$$

(Recall ve precision python ile kontrol edildi.) Hoca ardından recall ve precision'ı hesaplayan kodun yazılmasının kolay olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Aynı örnekte walking sınıfının F1 skoru $2 \cdot 0{,}833 \cdot 0{,}909 / (0{,}833 + 0{,}909) \approx 0{,}870$ olur (python ile hesaplandı). Çok sınıflı problemlerde sınıf bazındaki değerlerin ortalaması alınarak tek bir genel değer (macro ortalama) de raporlanabilir.

### 6.3 Köşegen neden çizildi?

Bir öğrenci köşegen çizgisinin neden çizildiğini sordu. Cevap: köşegen, en yüksek çıkmasını beklediğimiz doğru tahminlerdir. Bir satırda köşegendeki değer diğer gözlerden yüksekse o sınıfta başarılıyız demektir; köşegen dışındakilerin sıfır olması beklenir.

**Soru:** Köşegenin özel bir adı var mı?
**Cevap:** Genelde "köşegendeki değerler" denir, özel bir adı yoktur. En iyi sistemde bu değerlerin en yüksek olması beklenir.

## 7. ROC Eğrisi ve Köşegen Üzerine Bir Programlama Sorusu

### 7.1 ROC eğrisi

Daha önce konuşulmuş olan ROC eğrisi kısaca hatırlatıldı: dikey eksende true positive rate, yatay eksende false positive rate vardır. ROC eğrisinin altında kalan alan ne kadar büyükse sistemin başarısı o kadar yüksektir.

### 7.2 Sistem yüzde yüz başarılı mı?

Hoca köşegen sorusundan yola çıkıp bir programlama sorusu sordu: bir sistemin mutlak başarılı (%100) olup olmadığını bulan programı nasıl yazarsınız? İki yol konuşuldu:

- Köşegendeki değerleri toplayıp toplam veri sayısına eşit olup olmadığına bakmak.
- Matrisi gezmek ve köşegen dışındaki bir gözde sıfırdan farklı bir değer görüldüğü anda çıkmak.

Hocaya göre köşegeni toplayıp toplamla karşılaştırmak büyük olasılıkla daha etkindir. Erken çıkış seçeneğinde döngüden `break` ile çıkmak yerine `while` döngüsüyle yazılmasının daha uygun olacağı da konuşuldu.

## 8. Dengesiz Veride Eğitim ve Test Kümesi Kurma

### 8.1 Eğitim kümesinde oran

Hoca dengesiz veride FPR'nin önemine dönerek bir senaryo kurdu: 1000 fraud ve 10 milyon normal işlem var. Bütün non-fraud örnekleri eğitime katılırsa model yanlı (biased) olur; çoğunluk sınıfının örnek sayısı baskın olduğu için model non-fraud'a yakın sonuçlar üretmeye eğilimlidir. Hocanın sorusu bu baskınlığın nasıl engelleneceğiydi.

Bir öğrenci dengeli bir küme oluşturmayı, ancak seçimi kendimiz yaparsak sonuca etki edebileceğimizi söyledi; başka bir öğrenci her iki sınıftan rastgele 500'er örnek seçmeyi önerdi. Hoca 1:1 oranının tercih edilebileceğini, ama yapılan çalışmaların bu tür veri gruplarında farklı bir şey gösterdiğini anlattı:

- Oran 1:1 ile 1:10 arasında denenir.
- Birçok problemde yaklaşık 1:5'lik oran, yani her fraud'a karşı rastgele seçilmiş 5 non-fraud, eğitimde iyi başarı verir.
- Oran validasyon seti üzerindeki başarıya bakılarak seçilir. 1:100 gibi farkın çok büyük olduğu oranlarda iyi bir başarı yakalanamaz.

### 8.2 Test kümesi ve iyimser sonuçlar

İkinci adım testtir. Örneğin 1000 test fraud'u olsun. Testte de genelde 1:5 oranı korunur ve 5000 non-fraud seçilir. Sorun şudur: bu kümede hesaplanan precision ve FPR beklenenden iyi çıkar, çünkü 10 milyon non-fraud'un hepsi değil yalnız 5000'i test edilmiştir.

Gerçek sistem başarısını göstermek, örneğin bir bankayı modelin kullanılabilir olduğuna ikna etmek için model geri kalan bütün negatif örnekler üzerinde de çalıştırılmalı ve 10 milyon işlemden kaçının yanlış etiketlendiği bulunmalıdır. Banka şunu söyleyecektir: günde 10 milyon işlem geliyor ve sen bunların 10 binini hatalı işaretliyorsun. 10 milyonda 10 bin oransal olarak büyük değildir (%0,1; python ile kontrol edildi), ama 10 binin kendisi çok büyük bir sayıdır; her biri bir müşteriye giden yanlış uyarı demektir.

Bir başka pratik sorun da süredir: 10 milyon kaydı test etmek uzun sürer, her yeni parametre denemesinde 10 milyon üzerinde çalıştırmak zordur. Bu yüzden ayar küçük kümede yapılsa bile, sonuçlar bilimsel bir çalışmada ya da bir kurumla paylaşılırken bu durum göz önünde tutulmalıdır.

> **Hocanın vurgusu:** Gerçek hayattaki veri kümesi büyükse FPR'yi küçük veri setlerinde değerlendirmek yanıltır. Precision ve recall değerleri verilirken bu mutlaka göz önünde bulundurulmalıdır. Hoca, fraud alanındaki bilimsel çalışmalarda %80-90 başarı görülürken gerçek bankacılık verisinde, büyük veri kümesinde özellikle precision'ın çok düştüğünü kendi çalışmalarında gözlemlediklerini söyledi.

## 9. Crowdsourcing: Tanım ve Temel Döngü

### 9.1 Tanım

Aradan sonra yeni konuya geçildi. Slaydın başlığı "BLM5134 - Crowdsourcing, Week - 10" idi; ikinci sayfa "What is Crowdsourcing?" sorusuyla başlıyor ve tanımı "the act of taking a job traditionally performed by a designated agent (usually an employee) and outsourcing it to an ..." diye veriyordu (ekrandan, 01:10:00). Hocaya göre crowdsourcing son yıllarda birçok problemin çözümünde ciddi derecede kullanılmaya başlanan bir yaklaşımdır.

<!-- BELİRSİZ: Tanım cümlesinin devamı karede görünmüyor; büyük olasılıkla "undefined, generally large group of people in the form of an open call" biçiminde sürüyor. -->

Hocanın kendi tanımı: bir işin farklı gruplara, çok sayıda kaynağa delege edilmesi (outsource edilmesi) ve onlardan gelen bilginin kullanılmasıyla bir problemin çözülmesi. Bu, bilgisayar mühendisliğinde de giderek daha sık karşılaşılan bir yaklaşımdır.

### 9.2 Döngü: çağrı, toplama, ödül

Slayttaki şemada bir merkezi sunucu etrafında "Open call" (açık çağrı), "Collect" (toplama) ve "Reward" (ödül) adımları bir döngü olarak gösteriliyordu (ekrandan, 01:15:00). Hoca bu şemayı şöyle yorumladı:

- Delege edilen iş illa karşı tarafın hesaplama (process) yapması olmak zorunda değildir. Bazen kullanıcının ürettiği bilgi, bazen de cihazının algıladığı (sense ettiği) bilgi işinizi görür.
- Üretilen bilgi ya da sonuçlar alınır ve merkezi bir yerde işlenir.
- İşlenen sonuçların kullanıcılara bir şekilde geri dönmesi gerekir ki kullanıcılar veri üretmeye ya da probleme çözüm bulmaya devam etsin.

Burada karşılıklı kazanç önemlidir: ya ücret ödenir ya da üretilen bilgi kullanıcıların işine yarar.

**Soru (hocadan):** Karşılıklı kazanca örnek ne verilebilir?
**Cevap:** Bir öğrenci, karşılıklı çıkar ilişkisi olmasaydı bunun binlerce bilgisayarın karşılıksız kullanıldığı bir botnet'e dönüşeceğini söyledi. Hoca bunun yanlış olmadığını, karşılığın her zaman şart olmadığını ama ağırlıklı olarak karşılık döndürüldüğünü belirtti. Başka bir öğrenci, büyük bir arama şirketinin makineyle yapılamayan işler için kullanıcılardan anketle geri bildirim topladığını ve karşılığında küçük ödemeler yaptığını söyledi. Hoca bunun parasal geri dönüşe örnek olduğunu, anketlerin yıllardır uygulandığını, bilgi değerlendikçe bu tür politikaların arttığını ve karşılığın kullanım kredisi biçiminde de dönebildiğini ekledi.

## 10. Participatory ve Opportunistic Crowdsourcing

### 10.1 İki yaklaşım

Slayttaki "Two Approaches" başlığı altında iki yaklaşım sayılıyordu: participatory (katılımcı) ve opportunistic (fırsatçı). Aynı slaytta mobil cihazlardan oluşan, düğümlerin hareket ettiği (node mobility) ve kaynaktan hedefe yol bulmanın zorlaştığı bir "Routing Challenges" şekli ile şu not vardı: afet yardımı, madencilik operasyonları ve sağlık kampanyaları gibi acil durumlarda GPS'li cep telefonları ya da gözetim kameralı masaüstü bilgisayarlar gibi algılama yeteneği olan her varlık, fırsatçı ağ (OppNet) için değerlidir (ekrandan, 01:15:00).

### 10.2 Aradaki fark

Hoca iki yaklaşımın farkını sordu. Bir öğrencinin opportunistic için verdiği örnek hoca tarafından onaylandı: kullanıcılar bir uygulamayı kendi amaçları için kullanıyor, amaçları bize veri vermek değil, ama biz bu kullanımdan faydalanarak verilerini alıyoruz.

Slayttaki karşılaştırma şöyleydi (ekrandan, 01:20:00):

- Participatory: tipik olarak kullanıcılar hesaplama yapar ya da girdi olarak veri üretir.
- Opportunistic: girdi, kitlenin cihazlarında otomatik olarak yapılan sensör ölçümlerinden ve hesaplamalardan üretilen veridir.

Hocanın örnekleri:

- **Opportunistic:** Bir navigasyon uygulamasını araçta kullanırken hız bilginiz uygulamaya akar; karşılığında uygulama bir noktadan diğerine ne kadar sürede gidebileceğinizi ve yolların doluluk durumunu verir. Kullanıcı olayın içinde değildir: adres ya da hız bilgisi girmez, uygulamayı kullanması yeterlidir. Uygulama böylece gidilen yollardaki hızları toplar. Klavyede yazılan yanlış kelimelerin toplanması ve işletim sistemlerindeki hata durumlarının merkeze bildirilmesi de aynı mantıktadır; bu sayede ciddi miktarda geri bildirim toplanıp düzeltmeler yapılır.
- **Participatory:** İnsanın doğrudan dahil olduğu süreçler, örneğin anket (kişi oraya girip bilgi paylaşmak zorundadır), yorumlar ve tamamen kullanıcıların soru sorup cevapladığı Stack Overflow gibi platformlar.

Hoca "opportunistic"in kelime anlamının "fırsat bilgisi" gibi düşünülebileceğini söyledi ve akıllı şehirleri düşünerek başka örnek istedi. Bir öğrenci, büyük internet servislerinin kullanıcıdan veri toplayıp buna göre reklam önermesini örnek verdi: kullanıcının asıl amacı veri vermek değil, hizmeti kullanmaktır.

### 10.3 Verinin işlenmesinin hukuki boyutu

Bu örnek üzerine hoca, bu tür veri kullanımının sürekli tartışma ve zaman zaman dava konusu olduğunu, kişisel verilerin korunması mevzuatına uygunluğun sorgulandığını anlattı. Örnek olarak, bütün bankaların kart verisinin aktığı, kar amacı gütmeyen bankalar arası ortak bir kuruluşun bu veriyi işleyerek tek tek bankalara avantaj sağlayacak ürünler üretmesinin regülasyonlarla sınırlandığını söyledi; kuruluş yalnız bütün topluluğun işine yarayacak ürünler üretebilir. Büyük şirketler ise kuralları kendi lehlerine yorumlayıp kuralları çiğnemeden veriyi işler; kullanıcılar uzun sözleşmeleri okumadan onayladığı için bu kullanım genellikle sözleşmelerde yazılıdır.

### 10.4 Yol kalitesi ve risk haritası

Hocaya göre opportunistic yaklaşımın en güzel örneklerinden biri, araçla ya da telefonla gezerken yolun kalitesini ölçmek için sensör verisi toplamaktır. Kullanıcılar bu veriyi paylaşır, merkez işler ve nerede çukur, nerede tümsek olduğunu gösteren bir risk haritasını kullanıcılara geri döndürür. Tek tek, sokak sokak bütün şehri gezmek çok zor olduğu için bu tür çalışmaların önemi büyüktür. Haritalama gibi işler de çok zordur; bunları mümkün olduğunca dağıtarak yapmak her zaman avantajlıdır.

## 11. Crowdsourcing Uygulamalarının Dört Kategorisi

Slayttaki "4 Categories of Crowdsourcing Apps" başlığı altında dört kategori tanımlanıyordu (ekrandan, 01:25:00). Hoca öğrencilerden önce slaydı okumalarını, sonra her başlık için örnek vermelerini istedi.

### 11.1 Collective intelligence (wisdom of the crowd)

Slayttaki tanım: kalabalık içindeki insanların problem çözmesi, ürün, süreç ya da hizmet yeniliklerine götüren yeni içgörü ve fikirler sunması (ekrandan, 01:25:00). Kişilerin problem çözme konusundaki fikirleri ve görüşleri kullanılarak bir şey üretilir.

Örnekler:

- Bir öğrencinin önerdiği, televizyondaki bilgi yarışmalarındaki "seyirciye sorma hakkı". Hoca bunun basit ama mantığı çok iyi gösteren bir örnek olduğunu söyledi.
- Beyin fırtınası ve bir konuda yeni bir başlangıç yapılırken herkesin fikrinin alındığı çalıştaylar.
- Hayatta bir karar alırken en güvenilen arkadaşa, aileye, hocaya danışmak.
- Hocanın bilgisayar mühendisliği tarafından verdiği örnek: kişinin iki kıyafet arasında kaldığında arkadaşlarına gönderip onay aldığı gardırop uygulamaları. Bunu gerçek hayatta zaten yapıyoruz.
- Film puanlama sitelerinin mantığını dizi, yemek, restoran gibi hayattaki her seçeneğe uyarlayan yeni puanlama uygulamaları.

Collective intelligence her zaman en iyi ya da doğru sonucu üretmez; seyirciye sorma hakkı bazen yarışmacıyı yakar. Öyle olsaydı herkes her kararı ortak verirdi. Bazen 80 kişinin doğru dediği, 20 kişinin yanlış dediği şey gerçekten yanlış çıkabilir.

### 11.2 Puanlama uygulamaları ve gelir modeli

Hoca yeni bir puanlama uygulamasının geleceğini ve nasıl para kazanacağını sordu. Öğrencilerin cevapları: gençler arasında tutarsa hızlı yükselebilir; gelir reklam ve sponsorlu içerikten, ileride premium üyelikten gelebilir. Bu uygulamada bir ürüne puan vermeden o ürünün puanının görülemediği de konuşuldu.

Hoca premium üyelik cevabından yola çıkarak genel bir eğilimi anlattı: video ve müzik platformları reklam sıklığını kullanıcı davranışına göre ayarlıyor (örneğin aynı az popüler videoyu tekrar tekrar açtıkça reklam sıklığının arttığını gözlemlediğini söyledi) ve kullanıcıyı deneme süreleriyle premium üyeliğe doğru itiyor. Bir öğrencinin, sürekli reklamın kendisini satın almaktan uzaklaştırdığı yorumuna hoca "ya çok seversin ya nefret edersin" ayrımının oluştuğunu, sistemin henüz oturmadığını söyleyerek cevap verdi. Mobil dünya; üyeliklerin, içeriklerin parçalara ayrıldığı ve uygulama özelliklerinin parça parça satıldığı modüler ve abonelikli satış modellerine gidiyor. Kimse artık bir yazılımı komple satmıyor. Üyelik garanti bir kazanç demektir ve az az ödeme insanları daha kolay ikna eder: birinden bir anda 10 bin lira istemek yerine ayda 10 lira alarak onu 20 ay elde tutmak mümkündür.

### 11.3 Crowd creation (user-generated content)

Slayttaki tanım: insanların çeşitli türde içerik oluşturup bunu başkalarıyla ücretsiz ya da küçük bir ücret karşılığında paylaşması (ekrandan, 01:25:00).

Örnekler: Instagram (öğrencinin örneği), Twitter, sözlük siteleri, Stack Overflow. Bu platformlarda içeriği gönüllülük esasıyla üreten ve bundan keyif alan kişiler vardır.

Bir öğrenci çok oyunculu oyunları örnek verdi: oyuncular oyunu oynayarak birbirleri için deneyim üretir ve bunun için ayrıca ücret ödemez; yapay rakipler bir noktadan sonra insanları tatmin etmediği için insanları insanlarla karşılaştıran platformlar başarılı oluyor. Hoca bu görüşe katıldı: yapay zekâ rakibinin zorluğunu dengelemek zordur (ya çok zor ya çok kolay olur), karşıda bir insan olduğunu bilmek psikolojik olarak farklıdır ve insan rakibin davranışları daha doğaldır. Başka bir öğrenci satranç motorlarına karşı oynamanın keyifsiz olduğunu, insana karşı hamlelerin daha anlaşılır olduğunu söyledi. Hoca satrançta bilgisayarın bütün seçenekleri hesaplayabildiği için her hamleye en iyi opsiyonla karşılık verdiğini, insanın ise her oyunda farklı kombinasyonla oynadığını ekledi.

### 11.4 Crowd voting

Slayttaki tanım: insanların fikirler, ürünler ya da hizmetler hakkında görüş ve puan vermesi; kendilerine sunulan bilgiyi ayrıştırması, değerlendirmesi ve filtrelemesi (ekrandan, 01:25:00).

Örnekler: sosyal medyada bir gönderiyi beğenmek ya da favoriye eklemek, yorumları beğenmek, puanlama yapmak. Yukarıdaki puanlama uygulamasında yapılan iş de budur.

Hoca crowd voting'in hizmet kalitesini yükselttiğini, sürücülerin puanlandığı ulaşım uygulamalarını örnek vererek anlattı: puanlandığını bilen sürücü daha iyi puan almak için daha özenli çalışıyordu. Hocaya göre insanın hayattaki davranışlarını belirleyen en büyük etken ödül ve ceza sistemidir; ödül alan tekrar yapmak ister, kurallar ve cezalar uygulanmazsa sistem işlemez. Puanlama yüzünden otelden restorana herkes kendine çeki düzen vermek zorunda kalıyor; firmalar artık kötü yorumlara cevap yazıyor.

**Soru:** Demokrasi de crowd voting'e örnek verilebilir mi?
**Cevap:** Hoca verilebileceğini söyledi: olaylar sınırları zorladığında halk tepkisini gösterir, bunun sonucunda iktidarlar değişebilir, bakanlar istifa edebilir. Bu yüzden crowd voting her zaman işe yarayan bir mekanizmadır.

### 11.5 Crowdfunding

Slayttaki tanım: insanların yatırım, bağış ya da mikro kredi için para toplayabildiği özel bir model (ekrandan, 01:25:00).

Örnekler: bir öğrenci canlı yayın platformunu önerdi ama bunun bağış modeli olmadığını kendisi belirtti; video platformlarına gelen "katıl" (üyelik) butonu, hocanın kullandığı bir rüzgâr ve hava durumu uygulamasının bağış butonuyla hedeflenen tutara ulaşması ve Kickstarter. Hoca 2010'lu yıllardan itibaren bu yolla destek alan fikirlerin ve yatırımların iyi yerlere geldiğini, iyi bir işten ayrılıp girişim kuran insanların yaptığı işin dışarıdan göründüğünden çok daha zor olduğunu söyledi.

> **Hocanın vurgusu:** Bu dört madde bugün dünyanın merkezine oturmuş durumda ve birçok iş bunlara bağlı olarak gerçekleşiyor. Crowdsourcing iyi kullanıldığında günümüz teknolojisinde uygulanması gereken en önemli çözümlerden biridir.

### 11.6 Blokzincir crowdsourcing örneği mi?

**Soru:** Blokzincir (blockchain) crowdsourcing'e bir örnek midir?
**Cevap:** Hoca soruyu bir öğrenciye yöneltti. Öğrenci örnek olduğunu düşündüğünü söyledi: zincirdeki düğümlerin bir şey üzerinde anlaşması (handshake) gerekir, bu bir oylama (voting) olarak düşünülebilir. Çoğunluğun kabul ettiği doğru sayılıp devam edildiği için bu ortak karar collective intelligence'a da sokulabilir. Hoca benzetmeyi güzel buldu. Blokzincirin, makine öğrenmesinin 15 yıl önce yeni bir şeyken bugün sıradan hale gelmesi gibi yaygınlaşacağını, en büyük kısıtının kaynak (enerji) tüketimi olduğunu ve bu konuda yapılacak çok iş bulunduğunu, tez için iyi bir alan olabileceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00; derste sözlü, 00:23:19-00:27:46): Fraud tespiti için kurulan ikili karışıklık matrisinde gerçek sınıflar solda ("Fraud Actual", "Non-Fraud Actual"), tahminler üstte ("Fraud Predict", "Non-Fraud Predict") yazılmıştır. Fraud pozitif, non-fraud negatif sınıftır. Gerçekte fraud olup non-fraud tahmin edilen gözün ve gerçekte non-fraud olup fraud tahmin edilen gözün adı nedir?

> **Çözüm (derste verildi, hocanın ilk yazımı düzeltildikten sonra):** Gerçek fraud ve tahmin non-fraud: tahmin negatif ve yanlış, yani **FN**. Gerçek non-fraud ve tahmin fraud: tahmin pozitif ve yanlış, yani **FP**. Matris: üst satır TP | FN, alt satır FP | TN.

**Soru 2** (derste sözlü, 00:30:00-00:30:49): Neden doğruluğa (accuracy) her zaman güvenmeyiz? 1 milyon normal işlemin 999.990'ını, 1000 fraud işleminin 100'ünü doğru bilen bir model için doğruluğu ve fraud sınıfındaki başarıyı hesaplayın.

> **Çözüm (derste kısmen verildi, sayılar python ile kontrol edildi):** Dengesiz veri setlerinde çoğunluk sınıfı doğruluğu domine eder. $TP = 100$, $FN = 900$, $TN = 999.990$, $FP = 10$. $Accuracy = (100 + 999.990)/1.001.000 \approx 0{,}9991$. Fraud sınıfının recall'u $100/1000 = 0{,}10$ (%10). Precision ise $100/(100+10) \approx 0{,}909$'dur.

**Soru 3** (derste sözlü, 00:35:58-00:36:26): False positive rate, daha önce tanımlanan metriklerden biriyle nasıl ifade edilir?

> **Çözüm (derste verildi):** $FPR = 1 - Specificity$. Specificity $= TN/(TN+FP)$ olduğundan $FPR = FP/(TN+FP)$.

**Soru 4** (ekrandan, 00:55:00 ve 01:00:00): Aktivite tanıma problemine ait çok sınıflı karışıklık matrisinde gerçek walking satırı: walking 100, running 5, sitting 1, bir başka sınıf 4, diğerleri 0. Walking tahmin sütununda ise 100'e ek olarak başka iki sınıftan 10'ar örnek vardır, kalan gözler 0'dır. Walking sınıfının recall ve precision değerlerini bulun.

> **Çözüm (derste verildi, python ile kontrol edildi):** $Recall = 100/(100+5+1+4) = 100/110 \approx 0{,}909$. $Precision = 100/(100+10+10) = 100/120 \approx 0{,}833$.

**Soru 5** (derste sözlü, 00:52:32): Çok sınıflı bir karışıklık matrisinden her sınıfın recall ve precision değerini hesaplayan kodu yazın.

> **Çözüm (derste verilmedi; kod ajan tarafından yazılıp python ile denendi):**

```python
def recall_precision(cm):
    # cm[i][j]: gerçek sınıfı i olup j tahmin edilen örnek sayısı
    n = len(cm)
    sonuc = []
    for k in range(n):
        satir = sum(cm[k])                       # gerçekte k olanlar
        sutun = sum(cm[i][k] for i in range(n))  # k tahmin edilenler
        rec = cm[k][k] / satir if satir else 0.0
        pre = cm[k][k] / sutun if sutun else 0.0
        sonuc.append((rec, pre))
    return sonuc
```

**Soru 6** (derste sözlü, 00:53:40-00:54:25): Bir karışıklık matrisine bakarak sistemin %100 başarılı olup olmadığını bulan programı nasıl yazarsınız?

> **Çözüm (derste verildi):** Köşegendeki değerler toplanıp toplam örnek sayısına eşit olup olmadığına bakılır; ya da matris gezilir ve köşegen dışında sıfırdan farklı bir değer görüldüğü anda "başarısız" diye çıkılır. Hocaya göre köşegen toplamını toplamla karşılaştırmak daha etkin görünür.

**Soru 7** (derste sözlü, 00:39:40-00:41:14): 1000 fraud ve 10 milyon normal işlemden oluşan bir veri setinden eğitim kümesi nasıl kurulur? Testte 1:5 oranıyla hesaplanan precision ve FPR neden yanıltıcı olabilir?

> **Çözüm (derste verildi):** Bütün normal işlemler eğitime katılırsa model çoğunluk sınıfına yanlı olur. Fraud'ların tamamı alınır, normal işlemlerden rastgele örnekleme yapılır; 1:1 ile 1:10 arası oranlar validasyon setinde denenir, birçok problemde 1:5 iyi sonuç verir. Testte de 1:5 kullanılırsa 10 milyon normal işlemin yalnız küçük bir kısmı test edildiği için precision ve FPR gerçekte olduğundan iyi çıkar; gerçek başarı için model bütün negatif örnekler üzerinde çalıştırılmalıdır.

**Soru 8** (ekrandan, 01:20:00; derste sözlü, 01:14:31): Participatory ve opportunistic crowdsourcing arasındaki temel fark nedir? Her birine bir örnek verin.

> **Çözüm (derste verildi):** Participatory'de kullanıcı bilerek hesaplama yapar ya da veri üretir (anket, yorum, Stack Overflow). Opportunistic'te veri, kullanıcının müdahalesi olmadan cihazların sensörlerinden ve hesaplamalarından otomatik gelir (navigasyon uygulamasına akan hız bilgisi, işletim sistemi hata raporları, yol kalitesi için toplanan sensör verisi).

**Soru 9** (ekrandan, 01:25:00): Crowdsourcing uygulamalarının dört kategorisi nedir? Her birine bir örnek verin.

> **Çözüm (derste verildi):** Collective intelligence (seyirciye sorma hakkı, beyin fırtınası), crowd creation (Instagram, Twitter, Stack Overflow), crowd voting (beğeni ve puanlama, sürücü puanlama), crowdfunding (Kickstarter, bağış butonu).

## Dersin Toparlaması

Dersin ilk yarısında makine öğrenmesi modellerinin nasıl değerlendirileceği ele alındı. Regresyonda MAE, MAPE, MSE ve RMSE; sınıflandırmada karışıklık matrisi ve ondan türeyen doğruluk, recall (sensitivity, TPR), precision, specificity (TNR), FPR ve F1 skoru tanımlandı. Matriste gerçek değerlerin sola, tahminlerin üste yazılması ve FN ile FP gözlerinin doğru adlandırılması üzerinde uzun duruldu. Dengesiz verilerde doğruluğun yanıltıcı olduğu, sınıfların kendi içinde değerlendirilmesi gerektiği, eğitim kümesinde çoğunluk sınıfından örnekleme yapılması (sıklıkla 1:5) ve gerçek başarının bütün negatif örnekler üzerinde ölçülmesi gerektiği vurgulandı. Çok sınıflı matriste satır toplamına bölmenin recall, sütun toplamına bölmenin precision verdiği aktivite tanıma örneğiyle gösterildi.

İkinci yarıda crowdsourcing konusuna giriş yapıldı: bir işin topluluğa delege edilmesi, çağrı-toplama-ödül döngüsü, participatory ve opportunistic yaklaşımlar ve dört uygulama kategorisi (collective intelligence, crowd creation, crowd voting, crowdfunding). Hoca crowdsourcing konusunun bir sonraki derste tamamlanacağını, ardından sensör ağları ve kablosuz iletişim konularına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
