# Ders 7 Çalışma Özeti

<!-- Kaynak: ders kaydı altyazısı ve 5 dakikada bir alınmış ekran kareleri. Hoca dersin büyük kısmını İngilizce anlatmıştır; altyazıda çok sayıda Whisper tekrar halüsinasyonu vardır, bunlar nota alınmamıştır. -->

## Genel Konular

- Model kestirimi ve veri bölme
  - Sınıflamada veri eğitim (training) ve test kümelerine ayrılır. Test örneklerinin gerçek etiketleri (ground truth) bilinir; amaç bu etiketleri sınıflayıcıyla kestirmek ve kestirimi gerçek etiketle karşılaştırmaktır. Eşleşen örnek doğru, eşleşmeyen örnek yanlış sınıflanmıştır.
  - Veriyi bölmenin amacı genelleme hatasını (test hatasını) en aza indirmektir.
  - Yapay sinir ağları gibi hiperparametre ayarı ve model seçimi gereken uygulamalarda veri üçe bölünür: eğitim, doğrulama (validation) ve test kümesi (ekrandan, 00:25:00). Çoğu uygulamada ikili bölme (eğitim + test) yeterlidir.
  - Eğitim verisi az iken karmaşık bir model kullanılırsa aşırı öğrenme (overfitting) görülür; model gürbüz olmaz ve genelleme yeteneği düşer.
- Veri bölme yöntemleri
  - Yeniden yerine koyma (resubstitution): tüm veri hem eğitim hem test için kullanılır. <!-- BELİRSİZ: hocanın bu yöntemin sonucu hakkındaki yorumu altyazıda bozuk; büyük olasılıkla "gerçekçi olmayan, iyimser sonuç verir" denmiştir. -->
  - Ayırma (holdout): veri iki ya da üç parçaya ayrılır; bir parça test, kalanı eğitim için kullanılır.
  - Birini dışarıda bırak (leave-one-out): $n$ örnekten $n-1$ tanesiyle model kurulur, kalan tek örnekle test edilir; bu $n$ kez tekrarlanır. $n$ farklı model kurulduğu için hesap yükü büyüktür; çok küçük veri kümelerinde (50-80 örnek gibi) tercih edilir (ekrandan, 00:30:00).
  - k-katlı çapraz doğrulama (k-fold cross validation, rotation method): örnekler $P$ ayrık alt kümeye bölünür ($1 \le P \le n$); $P-1$ alt küme eğitim, kalan alt küme test için kullanılır; test parçası her turda değiştirilir. Her turda bir ölçüt (accuracy, recall, precision) elde edilir ve ortalaması alınır (ekrandan, 00:35:00).
  - Bootstrap: küçük veri kümelerinde yeniden örnekleme ile farklı eğitim kümeleri üretilir ve bunlarla hata oranının bootstrap kestirimleri tanımlanır. <!-- BELİRSİZ: bu bölümün anlatımı altyazıda büyük ölçüde bozuk. -->
- Sınıf karışıklık matrisi (class confusion matrix)
  - Satırlar gerçek sınıfı, sütunlar kestirilen sınıfı gösterir (hoca bu düzeni kullanacağını belirtti; bazı kaynaklarda tersi görülebilir).
  - İkili sınıflamada: $a$ = TP, $b$ = FN, $c$ = FP, $d$ = TN (ekrandan, 00:40:00).
  - Doğru sınıflanan örnekler ana köşegendedir: $\text{Accuracy} = \dfrac{a+d}{a+b+c+d} = \dfrac{TP+TN}{TP+TN+FP+FN}$.
  - Hata oranı: $\text{Error rate} = 1 - \text{Accuracy}$.
- Accuracy ölçütünün sorunu ve alternatif ölçütler
  - Dengesiz veride (ör. 9990 örnek sınıf 0, 10 örnek sınıf 1) her şeye çoğunluk sınıfını diyen "sıfır sınıflayıcı" %99 accuracy verir ama azınlık sınıfını hiç ayıramaz (ekrandan, 00:50:00).
  - $\text{Precision}\ (p) = \dfrac{a}{a+c}$, $\text{Recall}\ (r) = \dfrac{a}{a+b}$, $F = \dfrac{2rp}{r+p} = \dfrac{2a}{2a+b+c}$ (ekrandan, 00:45:00).
  - F ölçütü precision ve recall'un harmonik ortalamasıdır; ikisini ayrı ayrı karşılaştırmak zor olduğu için kullanılır.
- Dengesiz sınıf problemi (class imbalance)
  - Kaynakları: kredi kartı sahteciliği, saldırı tespiti (intrusion detection), üretim hattında kusurlu ürün, müşteri kaybı (churn) tahmini.
  - Bu problemlerde azınlık sınıfı genellikle daha önemlidir.
- Çok sınıflı karışıklık matrisinde sınıf bazında precision ve recall
  - Bir sınıfın recall değeri: köşegendeki değer / o sınıfın satır toplamı.
  - Bir sınıfın precision değeri: köşegendeki değer / o sınıfın sütun toplamı.
- TPR, FPR ve ROC eğrisi
  - $TPR = \dfrac{TP}{TP+FN}$ (recall, duyarlılık / sensitivity ile aynı).
  - $FPR = \dfrac{FP}{FP+TN}$.
  - ROC (Receiver Operating Characteristic) eğrisi, tespit oranı (TPR) ile yanlış alarm oranı (FPR) arasındaki ödünleşimi gösteren grafiksel bir yaklaşımdır; 1950'lerde sinyal algılama kuramı için geliştirilmiştir (ekrandan, 01:35:00).
  - Yatay eksen FPR, dikey eksen TPR'dir. Köşegen rastgele tahmini (yazı-tura) gösterir ve altındaki alan 0.5'tir.
  - Amaç eğrinin altında kalan alanı büyütmektir; ideal sınıflayıcıda bu alan 1'e yaklaşır.
  - ROC çizebilmek için sınıflayıcının sürekli değerli bir çıktı (skor, olasılık) üretmesi gerekir; eşik değeri değiştirilerek her eşik için bir (FPR, TPR) noktası bulunur.
- Dengesiz veri için çözümler
  - Sınıf tabanlı sıralama (class-based ordering): seyrek sınıfa ait kurallara daha yüksek öncelik verilir.
  - Maliyete duyarlı sınıflama (cost-sensitive classification): bir maliyet matrisi tanımlanır; seyrek sınıfı çoğunluk sınıfı olarak yanlış sınıflamak daha pahalıdır.
  - Örnekleme tabanlı yaklaşımlar: çoğunluk sınıfını alt örnekleme (undersampling) ya da seyrek sınıfı üst örnekleme (oversampling) ile eğitim verisinin dağılımı değiştirilir (ekrandan, 02:15:00).
- k-en yakın komşu (k-NN) sınıflayıcı
  - Örnek tabanlı (instance-based) bir öğrenicidir. Rote learner eğitim verisini ezberler ve yalnız tam eşleşme varsa sınıflar; en yakın komşu yöntemi ise en yakın $k$ eğitim örneğine bakar.
  - Gerekenler: etiketli kayıtlar, uzaklık ölçütü ve $k$ değeri (ekrandan, 02:35:00).
  - Öklid uzaklığı: $d(p,q) = \sqrt{\sum_i (p_i - q_i)^2}$; sınıf, $k$ komşunun çoğunluk oyuyla belirlenir; oylar uzaklığa göre $w = 1/d^2$ ile ağırlıklandırılabilir (ekrandan, 02:40:00).
  - Öz nitelikler ölçeklenmelidir (min-max ya da z-skor normalizasyonu) (ekrandan, 02:45:00).
  - k-NN tembel öğrenicidir (lazy learner); açık bir model kurmaz, sınıflama anında maliyetlidir.
  - Verimlilik için çok boyutlu erişim yöntemleri (KD-ağaçları), hızlı yaklaşık benzerlik araması ve yere duyarlı karma (locality sensitive hashing) kullanılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dengesiz veride yalnız accuracy'ye bakmak yeterli değildir
  - %99 accuracy veren bir sınıflayıcı önemli olan azınlık sınıfının hiçbir örneğini doğru bulamıyor olabilir. Bu yüzden precision, recall ve F ölçütü birlikte değerlendirilmelidir.
- Değerlendirme sınıf odaklı yapılır
  - İkili sınıflamada precision ve recall genellikle pozitif (önemli) sınıf için hesaplanır; gerekirse negatif ya da diğer sınıflar için de hesaplanabilir.
  - Kredi kartı sahteciliği ya da churn gibi problemlerde amaç ilgilenilen sınıfı en iyi ayıran sınıflayıcıyı bulmaktır.
- k-katlı çapraz doğrulama veri madenciliğinde en çok kullanılan ve tercih edilen bölme yöntemidir
  - $P = n$ alınırsa yöntem leave-one-out'a dönüşür.
- ROC eğrisi için sınıflayıcının sayısal skor üretmesi şarttır
  - Eşik taraması yapılarak eğri çizilir; eğrinin altındaki alan ne kadar büyükse sınıflayıcı o kadar başarılıdır.
- k-NN'de tek komşuya bakmak yeterli değildir
  - Test örneğinin yakınında gürültülü örnekler olabilir; 3, 5 ya da 7 komşu seçilmelidir. $k$ çok büyük seçilirse (15, 20, 50 gibi) komşuluk başka sınıfların örneklerini içerir.
- k-NN'de ölçekleme çok önemlidir
  - Değer aralığı büyük olan öz nitelik (ör. gelir) Öklid uzaklığına hâkim olur.

## Kısa Tekrar Notları

- Karışıklık matrisinde satır = gerçek sınıf, sütun = kestirilen sınıf.
- Accuracy = köşegen toplamı / tüm örnekler; Error rate = 1 − Accuracy.
- Precision = TP / (TP + FP) (sütuna bakılır); Recall = TP / (TP + FN) (satıra bakılır).
- F = 2rp / (r + p) = 2a / (2a + b + c).
- TPR = Recall = Sensitivity; FPR = FP / (FP + TN).
- ROC: x ekseni FPR, y ekseni TPR; köşegen rastgele tahmin (alan 0.5); ideal alan 1.
- Veri bölme: resubstitution, holdout, leave-one-out, k-fold cross validation, bootstrap.
- Leave-one-out küçük veri içindir ve $n$ model kurar; k-fold'da $P = n$ alınırsa leave-one-out elde edilir.
- Dengesiz veri çözümleri: class-based ordering, cost-sensitive classification, undersampling/oversampling.
- Maliyet: $\text{Cost} = \sum_{i,j} C(i,j)\, f(i,j)$; accuracy'si yüksek model maliyeti daha yüksek olabilir.
- k-NN: tembel öğrenici, Öklid uzaklığı, çoğunluk oyu, $w = 1/d^2$, ölçekleme, Voronoi karar sınırları, KD-ağacı ile hızlandırma.

## Detaylı Açıklamalar

- Veri bölme ve aşırı öğrenme
  - Sınıflamada eğitim kümesinde sınıf etiketleri bilinir ve model bu kümeyle kurulur. Test kümesinin de gerçek etiketleri vardır, ama model bu etiketleri görmeden kestirim yapar; sonra kestirim gerçek etiketle karşılaştırılır. Veriyi nasıl böldüğümüz genelleme hatasını doğrudan etkiler. Hiperparametre ayarı gerektiren modellerde (ör. yapay sinir ağları) ayrı bir doğrulama kümesi gerekir: eğitim kümesinde birden fazla model kurulur, doğrulama kümesinde en iyisi seçilir, test kümesinde son başarım ölçülür (ekrandan, 00:25:00). Eğitim verisi küçük ve model karmaşıksa aşırı öğrenme oluşur.
  - Leave-one-out'ta her turda bir örnek test için ayrılır, kalan $n-1$ örnekle model kurulur; $n$ turda her örnek bir kez test örneği olur. Küçük veri kümelerinde eğitim için mümkün olan en çok örneği kullandığı için iyi bir model üretir, ama $n$ model kurmak hesap açısından pahalıdır.
  - k-katlı çapraz doğrulamada (ör. 5 katlı) veri beş parçaya bölünür; her turda bir parça test, dört parça eğitim olur ve test parçası değiştirilerek işlem beş kez tekrarlanır. Her turun ölçütü (Metric 1 … Metric 5) ortalanarak sınıflayıcının genel başarımı bulunur (ekrandan, 00:35:00). Leave-one-out ile farkı: leave-one-out her seferinde tek örneği, k-fold ise bir alt kümeyi dışarıda bırakır.
- Precision, recall ve F ölçütü
  - Precision, sınıflayıcının "evet" dediği örneklerin ne kadarının gerçekten "evet" olduğunu; recall, gerçek "evet" örneklerinin ne kadarının yakalandığını gösterir. Tahtadaki ikili örnekte TP = 45, FN = 5, FP = 10, TN = 50 idi (ekrandan, 00:55:00): pozitif sınıfta 50, negatif sınıfta 60 örnek, toplam 110 örnek vardır; accuracy $= 95/110 \approx 0.864$, precision $= 45/55 \approx 0.818$, recall $= 45/50 = 0.9$.
  - Ders kitabı slaytındaki iki modelde (ekrandan, 01:00:00): birinci modelde (TP = 10, FN = 0, FP = 10, TN = 980) precision 0.5, recall 1, accuracy 0.99; ikinci modelde (TP = 1, FN = 9, FP = 0, TN = 990) precision 1, recall 0.1, F = 0.18, accuracy 0.991. Accuracy neredeyse aynıyken ikinci model azınlık sınıfının yalnız %10'unu yakalar; F ölçütüne göre birinci model daha iyidir.
  - Ders sonrası not: slayt birinci model için F = 0.62 yazıyor; $2 \cdot 1 \cdot 0.5 / 1.5 = 0.667$'dir. Sıralama değişmez.
  - Dengeli veride (40/10/10/40) precision, recall, F ve accuracy hepsi 0.8'dir; aynı TP ve FN ile negatif sınıf 5000 örneğe çıkınca (FP = 1000, TN = 4000) recall 0.8 ve accuracy yaklaşık 0.8 kalırken precision yaklaşık 0.04'e, F yaklaşık 0.08'e düşer (ekrandan, 01:05:00). Ders sonrası not: tam değerler precision $= 40/1040 \approx 0.038$, F $\approx 0.073$'tür; slayttaki değerler yuvarlanmıştır.
- Çok sınıflı örnek
  - Tahtada dört sınıflı (a, b, c, d) bir karışıklık matrisi üzerinde çalışıldı (ekrandan, 01:25:00). Toplam 127 örnek, köşegen toplamı 63, accuracy $= 63/127 \approx 0.4961$. b sınıfının recall'u $8/13$, precision'ı $8/35$; c sınıfının recall'u $4/4 = 1$, precision'ı $4/26$. Ayrıntılı çözüm genişletilmiş nottadır.
- ROC eğrisinin kurulması
  - Her örnek için sınıflayıcı bir skor üretir (yapay sinir ağı çıktısı, Bayes olasılığı ya da karar ağacı yapraklarındaki skor gibi). Skorlar sıralanır, her skor sırayla eşik alınır; eşiğe eşit ya da büyük olanlar pozitif sayılır. Her eşik için karışıklık matrisi doldurulur, TPR ve FPR hesaplanır ve (FPR, TPR) noktası çizilir (ekrandan, 01:45:00).
  - Örnekte eşik 0.25 iken tüm örnekler pozitif sayılır: TP = 5, FN = 0, FP = 5, TN = 0, nokta (1, 1). Eşik 0.43'te TP = 4, FN = 1, FP = 5, TN = 0, nokta (1, 0.8). Eşik 0.53'te TP = 4, FN = 1, FP = 4, TN = 1, nokta (0.8, 0.8).
  - İki modelin ROC eğrileri kesişebilir: düşük FPR bölgesinde bir model, yüksek FPR bölgesinde diğeri daha iyi olabilir.
- Maliyete duyarlı sınıflama
  - Maliyet matrisinde $C(+,+) = -1$, $C(+,-) = 100$, $C(-,+) = 1$, $C(-,-) = 0$ (ekrandan, 02:10:00). Pozitif örneği negatif saymak ağır cezalandırılır. Model 1 (150, 40 / 60, 250) için accuracy %80, maliyet 3910; Model 2 (250, 45 / 5, 200) için accuracy %90, maliyet 4255. Accuracy'si yüksek olan Model 2'nin maliyeti daha yüksektir; amaç false negative sayısını azaltıp true positive sayısını artırmaktır.
- k-NN
  - "Ördek gibi yürüyor, ördek gibi vaklıyorsa büyük olasılıkla ördektir" benzetmesiyle anlatılan yöntemde test örneğinin tüm eğitim örneklerine uzaklığı hesaplanır, en yakın $k$ komşu bulunur ve çoğunluk oyu alınır. 1-NN karar sınırları Voronoi diyagramı oluşturur. Ölçeklenmemiş verilerde boy (1.5–1.8 m), kilo (90–300 lb) ve gelir (10 bin–1 milyon dolar) gibi öz niteliklerden geliri büyük olan uzaklığa hâkim olur (ekrandan, 02:45:00). Karar ağacı gibi yöntemler eğitimde model kurarken k-NN modeli açıkça kurmaz; her test örneği için tüm eğitim örneklerine uzaklık hesaplanır. Bu yük KD-ağacı gibi çok boyutlu erişim yöntemleriyle azaltılabilir. <!-- BELİRSİZ: hocanın KD-ağacını tahtada anlattığı bölüm (yaklaşık 02:49–02:53) altyazıda büyük ölçüde bozuk; yalnız eşik değerlerinin ikili ağaç gibi ya da veri dağılımına göre seçilebileceği anlaşılıyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
