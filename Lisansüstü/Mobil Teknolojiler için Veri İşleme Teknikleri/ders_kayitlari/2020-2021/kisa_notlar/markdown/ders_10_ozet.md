# Ders 10 Çalışma Özeti

## Genel Konular

- Makine öğrenmesinde performans değerlendirme: regresyon metrikleri
  - Regresyon problemlerinde dört metrik sayıldı: MAE (Mean Absolute Error), MAPE (Mean Absolute Percentage Error), MSE (Mean Squared Error) ve RMSE (Root Mean Squared Error) (ekrandan, 00:20:00).
  - MAE ve MAPE, tahmin edilen değer ile gerçek değer arasındaki farkların mutlak değerleri üzerinden hesaplanır. Tahtada yazılan ifade $\sum_{i=1}^{k} |x_i - y_i|$ biçimindeydi (ekrandan, 00:20:00).
  - MAPE oransal (yüzdesel) sapmayı ölçer. Trafik akış hızı örneğinde 60 km/sa'lik bir noktada 6 km/sa'lik sapma %10, 30 km/sa'lik bir noktada aynı sapma %20 hatadır.
  - MSE ve RMSE, sapmanın büyüklüğünü daha belirgin gösterir. Hoca bunların özellikle büyük değerlerde ve birden fazla çıktılı tahminlerde tercih edildiğini söyledi.
- Sınıflandırma metrikleri ve karışıklık matrisi (confusion matrix)
  - İki tür sınıflandırma ayrıldı: ikili (binary) ve çok sınıflı (multi-class).
  - İkili sınıflandırmada sahtecilik (fraud) örneği kullanıldı: fraud pozitif, non-fraud negatif sınıftır. Gerçek (actual) sınıflar solda, tahminler (predict) üstte yazıldığında köşegende TP ve TN, gerçek fraud olup non-fraud tahmin edilen gözde FN, gerçek non-fraud olup fraud tahmin edilen gözde FP bulunur (ekrandan, 00:30:00).
  - Çok sınıflı problemde sınıf sayısı kadar satır ve sütunu olan bir matris kurulur (10 çıkışlı problemde 10×10). Köşegendeki değerler doğru tahminlerdir; satırlar recall, sütunlar precision hesabında kullanılır.
- Doğruluk (accuracy) ve dengesiz veri
  - $Accuracy = \dfrac{TP + TN}{TP + FP + TN + FN}$ (ekrandan, 00:30:00).
  - Dengesiz (imbalanced) veri setlerinde doğruluk yanıltıcıdır: 1 milyon normal işlemin 999.990'ı ve 1000 fraud işleminin yalnız 100'ü doğru bilinse bile doğruluk yaklaşık %99,9 çıkar, ama fraud yakalama başarısı %10'dur.
- Recall, precision, specificity, FPR ve F1 skoru
  - $TPR = Recall = Sensitivity = \dfrac{TP}{TP + FN}$: veri setinde gerçekten pozitif olanların ne kadarının pozitif bulunabildiği (ekrandan, 00:35:00).
  - $Precision = \dfrac{TP}{TP + FP}$: pozitif tahmin edilenlerin ne kadarının gerçekten pozitif olduğu (ekrandan, 00:35:00).
  - $Specificity = TNR = \dfrac{TN}{TN + FP}$: negatif sınıfı (non-fraud) kendi içinde bilme başarısı (ekrandan, 00:40:00).
  - $False\ Positive\ Rate = 1 - Specificity$ (ekrandan, 00:40:00).
  - $F1 = \dfrac{2 \cdot Precision \cdot Recall}{Precision + Recall}$: precision ve recall'un harmonik ortalaması; dengesiz veri setleri için hocaya göre kullanılabilecek en iyi ölçütlerden biri (ekrandan, 00:45:00).
- Çok sınıflı recall ve precision örneği (aktivite tanıma)
  - Sınıflar walking, running, sitting, lying gibi aktivitelerdi. Gerçek walking satırında 100 doğru tahmin, 5 running, 1 sitting ve 4 başka sınıf vardı. Walking recall'u $100/110$ olarak hesaplandı (ekrandan, 00:55:00).
  - Walking sütununda 100'e ek olarak başka sınıflardan 10 ve 10 örnek walking tahmin edilmişti. Walking precision'ı $100/120$ oldu (ekrandan, 01:00:00).
- ROC eğrisi
  - Dikey eksende TPR, yatay eksende FPR vardır. Eğrinin altında kalan alan büyüdükçe sistemin başarısı artar.
- Dengesiz veride eğitim ve test seti kurma
  - Bütün non-fraud örneklerini eğitime katmak, çoğunluk sınıfına yanlı (biased) bir model üretir. Az sayıdaki sınıftan bütün örnekler alınıp çoğunluk sınıfından rastgele örnekleme yapılır.
  - Oran 1:1 ile 1:10 arasında denenir. Hocanın aktardığına göre birçok problemde 1:5 civarı (1 fraud'a 5 rastgele non-fraud) iyi sonuç verir; 1:100 gibi oranlarda iyi başarı yakalanmaz.
  - Testte de çoğunlukla 1:5 korunur. Ancak bu şekilde hesaplanan precision ve FPR, gerçek sistemdekinden iyimser çıkar; gerçek başarıyı göstermek için model bütün negatif örnekler üzerinde de çalıştırılmalıdır.
- Crowdsourcing (kitle kaynak kullanımı)
  - Bir işin bir topluluğa delege edilerek (outsource edilerek) farklı kaynaklar üzerinden çözülmesidir. Delege edilen iş illa hesaplama olmak zorunda değildir; kullanıcının ürettiği ya da cihazının algıladığı (sense ettiği) veri de kullanılabilir.
  - Slayttaki şemada açık çağrı (open call), verinin toplanması (collect) ve ödül (reward) bir döngü olarak bir merkezi sunucu etrafında gösteriliyordu (ekrandan, 01:15:00). Kullanıcıya bir karşılık (ücret, kredi ya da işine yarayan bilgi) dönmesi önemlidir.
  - İki yaklaşım: participatory (katılımcı) ve opportunistic (fırsatçı) (ekrandan, 01:15:00).
  - Dört kategori: collective intelligence, crowd creation, crowd voting, crowdfunding (ekrandan, 01:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Karışıklık matrisinde gerçek ve tahmin eksenlerinin yeri
  - Hoca bu matrisin her zaman kafa karıştırdığını, bir kez doğru oturtulursa sonrasının kolaylaştığını söyledi. Önerisi: gerçek değerleri (actual) hep sola, tahminleri (predict) hep üste yazmak.
  - Recall'u fraud örneğiyle hatırlamak: elimizdeki fraud'ların ne kadarını yakaladık? Precision: fraud diye getirdiklerimizin ne kadarı gerçekten fraud?
- Dengesiz veride doğruluğa güvenilmemesi
  - Dengesiz veri setlerinde sınıflar kendi içinde değerlendirilmeli; TPR, TNR ve FPR'ye bakılmalıdır.
- False positive'lerin pratikteki maliyeti
  - Non-fraud işlemlere fraud denirse kullanıcılara sürekli uyarı mesajı gider ve bu rahatsızlık yaratır.
  - Günde 10 milyon işlem gelen bir bankada 10 bin yanlış işaretleme oransal olarak küçüktür (%0,1), ama 10 binin kendisi büyük bir sayıdır.
  - Küçük test kümelerinde ölçülen precision ve FPR yanıltıcıdır. Hoca, fraud alanındaki bilimsel çalışmalarda %80-90 görünen başarının gerçek bankada büyük veriyle çalışıldığında, özellikle precision'da çok düştüğünü gözlemlediklerini söyledi.
- MAPE ile MAE arasındaki seçim
  - Hedef her noktadaki oransal sapma ise MAPE kullanılmalıdır. Trafik akış hızı tahmininde ise MAE yeterlidir; çünkü 30 yerine 36, 60 yerine 66 tahmin etmek yolculuk süresini oransal olarak aynı etkiler. Hedef ±5 seviyesine inmektir; kısa vadede bu yapılabilir, uzun vadede kolay değildir.
- Crowdsourcing'in önemi
  - Hoca dört kategorinin bugün dünyanın merkezine oturduğunu ve crowdsourcing'in iyi kullanıldığında teknolojideki en önemli çözümlerden biri olduğunu söyledi.

## Kısa Tekrar Notları

- Regresyon: MAE, MAPE, MSE, RMSE. Oransal sapma önemliyse MAPE.
- Sınıflandırma: karışıklık matrisi; ikili ve çok sınıflı.
- Actual solda, predict üstte: üst satır TP | FN, alt satır FP | TN.
- Accuracy = (TP+TN)/(TP+FP+TN+FN); dengesiz veride yanıltıcı.
- Recall = Sensitivity = TPR = TP/(TP+FN).
- Precision = TP/(TP+FP).
- Specificity = TNR = TN/(TN+FP); FPR = 1 − Specificity.
- F1 = 2·P·R/(P+R).
- Çok sınıflı: satır toplamına bölmek recall, sütun toplamına bölmek precision verir.
- ROC: y ekseni TPR, x ekseni FPR; eğri altındaki alan büyüdükçe başarı artar.
- Dengesiz veri: azınlık sınıfının hepsi, çoğunluk sınıfından rastgele örnek; 1:5 oranı sık kullanılır. Gerçek precision/FPR için bütün negatiflerde test gerekir.
- Crowdsourcing: işin topluluğa delege edilmesi; karşılık (ödül) önemli.
- Participatory: kullanıcı bilerek veri üretir ya da hesaplama yapar (anket, Stack Overflow).
- Opportunistic: veri cihazların sensörlerinden ve hesaplamalarından otomatik gelir (navigasyon uygulamasına akan hız bilgisi, hata raporları).
- Dört kategori: collective intelligence, crowd creation, crowd voting, crowdfunding.

## Detaylı Açıklamalar

- Regresyon metrikleri
  - MAE ve MAPE'de tahmin ile gerçek değer arasındaki farkların mutlak değerleri toplanır. MAPE'de fark gerçek değere oranlanarak yüzde olarak ifade edilir. Hoca trafik akış hızı problemine döndü: 60 km/sa'lik bir yolda 6 km/sa'lik sapma ile 30 km/sa'lik bir yoldaki 6 km/sa'lik sapma eşit değildir; birinde %10, diğerinde %20 hata vardır. Hedef herhangi bir noktadaki oransal sapmaysa MAPE kullanılır. Ama trafik akış hızında oransal sapmanın yolculuk süresine etkisi zaten orantılı olduğu için MAE yeterli olabilir.
  - MSE ve RMSE hakkında hoca, büyük değerlerde RMSE'nin tercih edildiğini, bu değerler büyüdükçe tahminin daha çok saptığını, özellikle öznitelik sayısı fazla ve birden fazla çıktılı tahminlerde bunların daha akıllıca olduğunu söyledi. Bu metriklerin ne olduğunu bilmenin yeterli olduğunu, trafik tahmini literatüründe neden seçildiklerinin görüleceğini ekledi.
  - <!-- BELİRSİZ: Tahtadaki MAE ifadesinde 1/k çarpanı yazılmamıştı; standart MAE tanımında toplam örnek sayısına bölünür. MSE ve RMSE'nin formülleri tahtaya yazılmadı. -->
- Karışıklık matrisi ve hücrelerin adlandırılması
  - Tahtada önce iki satırlı bir matris kuruldu: sütunlarda "Fraud Predict" ve "Non-Fraud Predict", satırlarda "Fraud Actual" ve "Non-Fraud Actual". Fraud pozitif, non-fraud negatif kabul edildi. Hoca başta gerçek fraud satırındaki ikinci gözü FP olarak yazdı; öğrencilerin itirazı ve tartışmadan sonra düzeltti. Doğrusu: gerçek fraud ama tahmin non-fraud olan göz FN, gerçek non-fraud ama tahmin fraud olan göz FP'dir (ekrandan, 00:25:00 ve 00:30:00).
  - Pozitif sınıfın seçimi önemlidir. Hoca'nın kuralı: pozitif genelde ilgilendiğimiz, gerçekleşmesini yakalamak istediğimiz durumdur (COVID pozitif gibi; fraud problemi için fraud).
- Dengesiz veride doğruluğun yanıltıcılığı (sayısal örnek, python ile kontrol edildi)
  - 1 milyon normal işlemden 999.990'ı doğru (FP = 10), 1000 fraud'dan 100'ü doğru (TP = 100, FN = 900) bilinmiş olsun. Doğruluk $(100 + 999.990)/1.001.000 \approx 0{,}9991$ olur. Recall ise $100/1000 = 0{,}10$'dur. Yani model fraud'ların %90'ını kaçırırken doğruluk %99,9 gösterir.
- Recall ve precision
  - Recall'da paydaki TP + FN, gerçekte pozitif olanların tamamıdır (matriste gerçek fraud satırı). Precision'da paydaki TP + FP, pozitif tahmin edilenlerin tamamıdır (fraud predict sütunu). Specificity, negatif sınıfın kendi içindeki başarısıdır. FPR, specificity'nin tümleyenidir.
  - F1 skoru precision ile recall'un harmonik ortalamasıdır; ikisini birlikte hesaba kattığı için dengesiz verilerde model başarısını tek sayıyla göstermeye uygundur.
- Çok sınıflı karışıklık matrisi örneği (ekrandan, 00:55:00 ve 01:00:00)
  - Gerçek sınıflar solda, tahminler üstte. Walking satırı: walking 100, running 5, sitting 1, bir başka sınıf 4, kalanlar 0. Satır toplamı 110 olduğundan walking recall'u $100/110 \approx 0{,}909$'dur. Walking sütununda 100'ün yanında diğer sınıflardan 10 ve 10 örnek vardır; sütun toplamı 120 olduğundan walking precision'ı $100/120 \approx 0{,}833$'tür (python ile kontrol edildi).
  - Köşegendeki değerlerin özel bir adı yoktur; en yüksek olmaları, köşegen dışının sıfır olması beklenir.
  - Hoca bir sistemin %100 başarılı olup olmadığını bulan programın nasıl yazılacağını sordu. İki yol vardır: köşegeni toplayıp toplam veri sayısına eşit mi diye bakmak, ya da matrisi gezip köşegen dışında sıfır olmayan bir değer görünce durmak. Hocaya göre köşegeni toplamak daha etkin görünür.
- Dengesiz veride eğitim ve test
  - Örnek: 1000 fraud'a karşı 10 milyon normal işlem. Bütün normal işlemlerle eğitilen model çoğunluk sınıfına yakın sonuçlar üretir. Bunun yerine eğitimde fraud'ların tamamı ve normal işlemlerden rastgele bir alt küme kullanılır. 1:1 ile 1:10 arası oranlar validasyon setinde denenir; hocaya göre çoğu problemde 1:5 iyi sonuç verir.
  - Test için örneğin 1000 test fraud'una karşı 5000 non-fraud seçilir. Bu durumda precision ve FPR beklenenden yüksek (iyimser) çıkar, çünkü 10 milyon normal işlemin hepsi test edilmemiştir. Banka günde 10 milyon işlemden kaç tanesinin yanlış işaretlendiğini bilmek ister. Öte yandan her parametre denemesinde 10 milyon kaydı çalıştırmak zaman alır; bu yüzden son değerlendirme büyük veride yapılmalı ve sonuçlar paylaşılırken bu durum göz önünde tutulmalıdır.
- Crowdsourcing
  - Tanım: bir işin çok sayıda kaynağa delege edilmesi ve onlardan gelen bilgiyle bir problemin çözülmesi. Toplanan veri ya da sonuçlar merkezi bir yerde işlenir ve sonuç kullanıcılara bir şekilde geri döndürülür. Karşılıklı kazanç önemlidir: ücret ödenir ya da üretilen bilgi kullanıcının işine yarar. Bir öğrenci karşılığı olmayan kullanımın botnet'e benzeyeceğini söyledi; hoca karşılığın her zaman şart olmadığını ama çoğunlukla verildiğini belirtti. Anket karşılığında küçük ödeme ya da kredi veren uygulamalar parasal karşılığa örnektir.
  - Participatory ve opportunistic: slayta göre participatory'de kullanıcılar hesaplama yapar ya da girdi olarak veri üretir; opportunistic'te girdi, kitlenin cihazlarında otomatik yapılan sensör ölçümlerinden ve hesaplamalardan gelen veridir (ekrandan, 01:20:00). Hocanın opportunistic örneği bir navigasyon uygulamasıdır: sürücü adres ya da hız girmez, ama hız bilgisi uygulama üzerinden merkeze akar, karşılığında yol doluluk durumu ve varış süresi döner. İşletim sistemlerinin hata raporları da benzer biçimde toplanır. Stack Overflow ve anketler ise participatory yaklaşımdır.
  - Opportunistic yaklaşıma bir başka örnek: araçla giderken telefon sensörleriyle yol kalitesini ölçmek, merkezde işleyip çukur ve tümseklerin olduğu bir risk haritasını kullanıcılara geri döndürmek. Bütün şehri sokak sokak gezmek zor olduğu için işi dağıtmak avantajlıdır.
  - Veri kullanımının hukuki boyutu: büyük firmaların kullanıcı verisini işlemesi dava konusu olabiliyor; kişisel verilerin korunması mevzuatı ve kuruluşların regülasyonları verinin nasıl ve nereye kadar işlenebileceğini sınırlar. Hoca, bankalar arası ortak bir kar amacı gütmeyen kuruluşun bütün bankaların verisine sahip olsa da tek tek bankalara avantaj sağlayacak işleme yapamamasını örnek verdi.
  - Dört kategori (ekrandan, 01:25:00):
    - Collective intelligence (wisdom of the crowd): kalabalığın problem çözmesi, ürün, süreç ya da hizmet yeniliğine götüren fikir üretmesi. Örnekler: bilgi yarışmasındaki seyirciye sorma hakkı, beyin fırtınası ve çalıştaylar, arkadaşlardan kıyafet onayı alınan gardırop uygulamaları, puanlama uygulamaları. Kalabalığın kararı her zaman doğru değildir; 80 kişinin doğru dediği şey yanlış çıkabilir.
    - Crowd creation (user-generated content): insanların içerik üretip ücretsiz ya da küçük bir ücretle paylaşması. Örnekler: Instagram, Twitter, sözlük siteleri, Stack Overflow. Bir öğrenci çok oyunculu oyunları da örnek verdi.
    - Crowd voting: fikir, ürün ya da hizmetlere görüş ve puan verme, sunulan bilgiyi değerlendirme ve filtreleme. Örnekler: beğeni ve puanlama, sürücülerin puanlandığı ulaşım uygulamaları. Hoca puanlanmanın hizmet kalitesini yükselttiğini, insan davranışını ödül-ceza sisteminin belirlediğini söyledi. Bir öğrenci demokrasiyi örnek verdi, hoca katıldı.
    - Crowdfunding: yatırım, bağış ya da mikro kredi için para toplanması. Örnekler: uygulamalardaki bağış (donate) butonu, Kickstarter, video platformlarındaki üyelik/katıl butonu.
  - Gelir modeli tartışması: yeni bir puanlama uygulamasının nasıl kazanacağı sorulunca reklam, sponsorlu içerik ve premium üyelik söylendi. Hoca mobil dünyanın modüler satış ve abonelik modellerine gittiğini, küçük ama sürekli ödemenin kullanıcıyı daha kolay ikna ettiğini anlattı.
  - Bir öğrenci blokzincirin crowdsourcing örneği olup olmadığını sordu. Öğrenci ağdaki düğümlerin ortak bir karar üzerinde anlaşmasını (oylama) ve çoğunluğun kabul ettiğinin doğru sayılmasını collective intelligence'a benzetti. Hoca benzetmeyi beğendi ve blokzincirdeki en büyük kısıtın kaynak tüketimi olduğunu söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
