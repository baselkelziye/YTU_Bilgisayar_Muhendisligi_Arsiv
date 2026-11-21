# Ders 6 Çalışma Özeti

## Genel Konular

- Stokastik ve stokastik olmayan gradyan süreçleri üzerine düzeltme
  - Stokastik olmayan süreçte (GD) bir noktadaki gradyan elimizdeki bütün örneklerle, yani tam (full) gradyan olarak hesaplanır. Stokastik süreçte (SGD) her adımda örneklerin bir kısmıyla ya da tek örnekle hesaplanır; bu gradyan tam gradyanın gürültülü bir hâlidir.
  - SGD optimizasyonun başında GD'den pek farklı davranmaz; sona doğru, R diye tanımlanan bölgeye girildikten sonra rastgele seçilen örneklerin gradyanı tam gradyana benzemez olur ve SGD yalpalamaya başlar.
  - Adam ve Adagrad asıl olarak büyük ölçekli (large scale), stokastik süreçler için geliştirilmiştir. Kayıp fonksiyonunun açıkça verildiği, gerçek gradyana erişilebilen bir problemde Adam'ın gradyan inişinden daha yavaş ve kötü çıkması bu yüzden şaşırtıcı değildir.
- Kollektif öğrenmede çeşitlilik ve başarı
  - Kollektif öğrenme, öğrenme sürecinde tek model yerine birden fazla model kullanmaktır; en klasik yol modellerin kararlarını birleştirmektir.
  - Bütün temel öğreniciler aynı şeyi söylüyorsa birleştirmenin anlamı yoktur. Bu yüzden karar çeşitliliği gerekir. Öte yandan her tekil öğrenicinin doğruluğu da yüksek olmalıdır; iki istek birbiriyle uzlaşmaz.
- Farkı (çeşitliliği) sağlamanın üç yolu (ekrandan, 00:20:00)
  - Farklı temel öğreniciler: aynı eğitim kümesinde yapay sinir ağı, SVM, karar ağacı, 1-NN gibi farklı varsayımlara sahip algoritmalar farklı karar sınırları üretir.
  - Aynı öğrenicinin farklı hiperparametreli hâlleri: KNN'de farklı $k$, YSA'da farklı başlangıçlar ve gizli katmana farklı sayıda nöron, karar ağacında maksimum derinlik ya da bölme ölçütü (information gain, en yüksek doğruluk vb.).
  - Aynı öğreniciyi farklı eğitim setleriyle eğitmek: dersin en çok kullanacağı ve en basit yaklaşım.
- Tek eğitim kümesinden farklı eğitim setleri üretmek (ekrandan, 00:25:00)
  - Örnekler: Bagging, AdaBoost, Rastsal Ormanlar (Random Forest).
  - Özellikler: Rastsal Altuzaylar (Random Subspaces), Rastsal Ormanlar, Rotasyon Ormanları (Rotation Forest).
  - Sınıflar: Ensemble of Nested Dichotomies, ECOC.
  - Bölgeler: uzman karışımları (Mixture of Experts), Random Linear Oracle.
  - Model sonuçlarını modelleme (Stacking): sonraki derse bırakıldı.
- Bagging (yerine koyarak örnekleme)
  - $n$ örnekli kümeden yerine koyarak $n$ örnek seçilir; bazı örnekler birden çok kez, bazıları hiç seçilmez. Her tur orijinal veriden yeniden örneklenir ve her yeni kümede bir temel öğrenici eğitilir.
  - Seçilen $n$ örnek orijinal örneklerin ortalama yaklaşık %63.2'sini içerir, çünkü $(1-1/n)^n \approx e^{-1} = 0.368$ (ekrandan, 00:30:00).
  - Algoritmada $F$ oranı bir hiperparametredir: $F=\%100$ ise $n$ içinden $n$, $\%50$ ise $n/2$ örnek seçilir. Test aşamasında örnek bütün modellere verilir, çoğunluk oylaması (majority voting) ile sınıf belirlenir.
- Bagging ile basit öğrenicilerden karmaşık karar sınırı
  - Tek boyutlu örnek: $x \le 0.3$ ve $x \ge 0.8$ için $+1$, $0.4$ ile $0.7$ arası $-1$. Tek eşikli (doğrusal) bir sınıflandırıcı bu veriyi çözemez. 10 bagging turunda eğitilen tek eşikli sınıflandırıcıların oylaması gerçek sınıfları %100 doğru verir (ekrandan, 00:35:00 ve 00:40:00).
  - İki boyutta da aynı mantık geçerlidir: her tur farklı örneklerle farklı bir sınır çizer, birleşimi kaba ama daha iyi bir sınır verir.
- Bagging bulguları (ekrandan, 00:45:00)
  - Temel öğreniciler eğitim verisine duyarlı ise (yüksek varyanslı: karar ağacı, YSA) iyi çalışır; 1-NN gibi duyarsız öğrenicilerde topluluk tek modelden pek farklı çıkmaz.
  - Spesifik örneklere yoğunlaşmadığı için gürültülü verilere karşı gürbüzdür: tek bir gürültülü örneğin yeniden örneklemede seçilmeme şansı yüksektir.
  - Ağaçları tamamen büyütmek düşük başarı, yüksek çeşitlilik; daha genel bırakmak yüksek başarı, az çeşitlilik verir (ekrandan, 00:50:00).
- Boosting ve AdaBoost
  - Temel öğrenicilerin eğitileceği örnekler seçilirken önceki öğrenicilerin hata yaptığı örneklere öncelik verilir. Başlangıçta seçilme olasılıkları eşittir ($1/N$), her iterasyonda güncellenir; bagging'de ise sabit kalır (ekrandan, 00:55:00).
  - AdaBoost algoritmasında hata oranı $\epsilon_j$, yanlış sınıflandırılan örneklerin olasılıkları toplamıdır; $\epsilon_j > 1/2$ ise durulur. $\beta_j = \epsilon_j/(1-\epsilon_j)$ ile doğru sınıflanan örneklerin olasılığı çarpılarak azaltılır, sonra normalize edilir. Testte her öğrenicinin oyu $\log(1/\beta_j)$ ile ağırlıklandırılır (ekrandan, 01:00:00).
- Bagging ve Boosting karşılaştırmaları
  - C4.5 tabanlı karşılaştırmada ikisi de çoğu veri kümesinde tek ağaçtan daha az hata yapar. Bagging ile boosting arasında büyük fark yoktur.
  - Kazanma/beraberlik/kaybetme (win/draw/loss) sayıları 10 katlı çapraz doğrulama sonuçlarına hipotez testi (t-testi) uygulanarak bulunur.
  - Chess verisinde boosting, colic verisinde bagging daha başarılıdır (ekrandan, 01:30:00): her veri kümesinde en iyi tek algoritma yoktur (no free lunch).
- Rastsal Altuzaylar (Random Subspace, Ho, 1998)
  - Her öğrenici bütün örneklerle ama rastgele seçilmiş $d$ özellikle eğitilir; özellik seçimi yerine koymadan yapılır. Sonuçlar oylamayla birleştirilir.
  - Kaç özellik kullanılacağı veri kümesine bağlıdır (ekrandan, 01:35:00). Ağaç sayısı arttıkça başarı artar; tek ve çift ağaç sayısı arasındaki zikzaklar çift sayıda oylamada çıkan beraberliklerden kaynaklanır.
  - Bölme yöntemleri karşılaştırmasında Gain Ratio düşük maliyetle iyi sonuç vermiştir.
  - En başarılı ağaçları seçmek ile hepsini kullanmak arasında belirgin fark yoktur (ekrandan, 01:40:00); en başarılı ağaçlar birbirine benzer, çeşitlilik azalır.
- Rastsal Ormanlar (Random Forest, 2001)
  - Yalnız karar ağaçları için tasarlanmıştır ve iki tür rastgelelik kullanır: bagging ile yeniden örnekleme ve her karar düğümünde rastgele seçilmiş $F$ özellik (Forest-RI) ya da özelliklerin doğrusal kombinasyonları (Forest-RC) (ekrandan, 01:45:00).
  - Her düğümde seçim öncekilerden bağımsızdır; ağaçlar budanmaz, sonuçlar oylamayla birleştirilir.
  - Varsayılan $F = \log_2(\text{özellik sayısı})$: 1024 özellikte her düğümde 10 özellik denenir. Özellik sayısı yüksekse topluluk tek bir tam ağaçtan bile daha hızlı üretilebilir.
  - Rastgele özellik seçimi iyi özelliği kaçırabileceği için ağaçlar, bütün özelliklere bakan ağaçtan daha büyük olur.
  - AdaBoost, eğitim etiketlerine eklenen gürültüye karşı zayıftır; Random Forest'ın hatası çok daha az artar.
- Aşırı Rastsal Ormanlar (Extremely Randomized Trees; Geurts, Ernst, Wehenkel, 2006)
  - Her düğümde $K$ rastgele özelliğin her biri için rastgele bir eşik seçilir; $K$ özellik-eşik ikilisinden en iyisi düğüm olur (ekrandan, 01:55:00).
  - Ağaç boyu sıralaması: tam ağaç < Random Forest < Random Subspace < Extremely Randomized Trees.
  - Avantaj: çok yüksek çeşitlilik ve çok hızlı eğitim. Dezavantaj: ağaçlar büyük olduğu için çok bellek ve uzun test süresi.
  - 12 sınıflandırma verisinde ET; tek ağacı 10 kez yenip 2 kez berabere, bagging'i 7/5/0, random subspace'i 2/10/0, random forest'ı 5/7/0 ile yenmiş, hiç kaybetmemiştir (ekrandan, 02:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Çeşitlilik ile tekil başarı arasındaki ikilem
  - Bir tarafı iyileştirmek öbür tarafı kötüleştirir. Tam ağaçlar çeşitlidir ama tekil başarıları düşüktür; küçük ağaçlar başarılı ama birbirine benzerdir. Bagging tekil başarıyı yüksek tutan, buna karşılık çeşitliliği daha düşük olan bir algoritmadır.
- Basit öğrenicilerden karmaşık karar sınırı
  - Hiçbir tek eşikli sınıflandırıcı iki bölgeden bölemezken onların birleşimi doğrusal ayrılamayan veriyi %100 doğru sınıflandırır. Hoca bunu bagging örneğinin en önemli bulgusu olarak gösterdi.
- AdaBoost'un gürültüye duyarlılığı
  - AdaBoost yanlış sınıflanan örneklerin olasılığını artırdığı için etiketi bozulmuş (gürültülü) örneklere odaklanır; bu yüzden etiket gürültüsünde hatası çok artar.
- Random Forest'ın hız avantajı
  - Tek tek ağaçlar daha büyük olsa da düğüm başına çok az özellik denendiği için özellik sayısı yüksek verilerde topluluk tek bir tam ağaçtan hızlı üretilebilir.
- Bir algoritmanın başarısı nasıl değerlendirilir
  - Yöntemin önerildiği makalede yöntem genelde daha iyi görünür. Asıl önemli olan, çok sayıda veri kümesinde ve başka araştırmacılarca farklı alanlarda tekrarlanıp doğrulanmasıdır. Random Forest bu yüzden popülerdir.
- Adam ile ilgili önyargı
  - Adam büyük ölçekli stokastik problemler için geliştirilmiştir; tam gradyanın bilindiği bir problemde gradyan inişinden kötü çıkması onun genel olarak kötü olduğunu göstermez.

## Kısa Tekrar Notları

- Çeşitlilik kaynakları: farklı algoritma, farklı hiperparametre, farklı eğitim seti.
- Eğitim setini farklılaştırma eksenleri: örnekler, özellikler, sınıflar, bölgeler.
- Bagging: yerine koyarak $n$ içinden $n$; ortalama %63.2 farklı örnek; çoğunluk oylaması.
- Bagging yüksek varyanslı öğrenicilerle (karar ağacı, YSA) işe yarar, 1-NN ile yaramaz; gürültüye gürbüzdür.
- Boosting: hata yapılan örneklerin seçilme olasılığı artar; AdaBoost'ta $\epsilon_j > 0.5$ ise durulur.
- AdaBoost: $\beta_j = \epsilon_j/(1-\epsilon_j)$; doğruların olasılığı $\beta_j$ ile çarpılır; test ağırlığı $\log(1/\beta_j)$.
- AdaBoost etiket gürültüsüne duyarlıdır.
- Random Subspace: bütün örnekler, rastgele $d$ özellik, yerine koymadan.
- Çift sayıda ağaçta oylama beraberliği başarı eğrisinde zikzak yapar.
- En başarılı ağaçları seçmek, hepsini kullanmaktan belirgin biçimde iyi değildir.
- Random Forest: bagging + her düğümde rastgele $F$ özellik; varsayılan $\log_2$ (özellik sayısı); budama yok.
- Extremely Randomized Trees: rastgele özellik + rastgele eşik; en büyük ağaçlar, en hızlı eğitim, en yavaş test.
- Hiçbir ensemble yöntemi her veri kümesinde en iyisi değildir.

## Detaylı Açıklamalar

- **Bagging'in %63.2 kuralı.** $n$ örnekten yerine koyarak $n$ çekiliş yapılırken belirli bir örneğin bir çekilişte seçilmeme olasılığı $1-1/n$, hiç seçilmeme olasılığı $(1-1/n)^n$'dir. $n$ büyüdükçe bu değer $e^{-1} \approx 0.368$'e yaklaşır; dolayısıyla bir bagging kümesi orijinal örneklerin ortalama $1-0.368 = 0.632$'sini içerir. Kalan yer, seçilmiş örneklerin tekrarlarıyla dolar. Slayttaki tabloda birinci turda seçilen kimlikler 7, 8, 10, 8, 2, 5, 10, 10, 5, 9'dur: 10 numaralı örnek üç kez, 8 ve 5 iki kez seçilmiş, 1, 3, 4 ve 6 hiç seçilmemiştir (ekrandan, 00:30:00).
  - Ders sonrası not: Hoca sözlü olarak "%60.2" dedi; slaytta ve hesapta doğrusu %63.2'dir ($1 - e^{-1} = 0.632$).
- **Tek boyutlu bagging örneği.** Eğitim verisi $x = 0.1, 0.2, \dots, 1.0$ olan 10 örnektir; $x \le 0.3$ ve $x \ge 0.8$ için sınıf $+1$, $0.4 \le x \le 0.7$ için $-1$'dir. Her temel sınıflandırıcı bir $K$ eşiğine sahiptir ($x \le K$ ise bir sınıf, değilse öbürü) ve $K$ toplam entropiyi en küçükleyecek biçimde seçilir. Slayttaki 10 turun öğrendiği kurallar (ekrandan, 00:40:00):
  - Tur 1, 3, 5: $x \le 0.35 \Rightarrow +1$, aksi $-1$. Tur 4: $x \le 0.3 \Rightarrow +1$, aksi $-1$.
  - Tur 2: $x \le 0.65$ ve $x > 0.65$ için her iki durumda $+1$ (veride çoğunluk $+1$).
  - Tur 6, 7, 8, 9: $x \le 0.75 \Rightarrow -1$, aksi $+1$.
  - Tur 10: seçilen bütün örnekler $+1$ olduğu için $x \le 0.05 \Rightarrow -1$, aksi $+1$; pratikte her yere $+1$ der.
  - Oylama: $x = 0.1, 0.2, 0.3$ için 6 sınıflandırıcı $+1$, 4 sınıflandırıcı $-1$ der (toplam $+2$); $x = 0.4 \dots 0.7$ için 2 sınıflandırıcı $+1$, 8 sınıflandırıcı $-1$ der (toplam $-6$); $x = 0.8 \dots 1.0$ için yine 6'ya 4 ile $+1$ çıkar. Toplamın işareti gerçek sınıflarla bire bir örtüşür ve topluluk başarısı %100'dür (python ile doğrulandı).
- **Ağaç büyüklüğü ve çeşitlilik.** Slayttaki iki ağaçtan $T_1$ daha çok bölme içerir ($x_2 < 1.94$, $x_1 < -1.24$, $x_1 < 11.00$, $x_2 < 7.45$, $x_2 < 9.25$, $x_1 < 1.58$), $T_2$ yalnız ilk üç bölmeyi içerir (ekrandan, 00:50:00). Tam ağaç gürültülü noktaların çevresine bile sınır çizer, aşırı öğrenir ve testte düşük başarı verir; ama farklı eğitim kümelerinden üretilen tam ağaçlar birbirine az benzer. Küçük ağaçlar testte daha başarılı olabilir ama kararları birbirine benzer.
- **AdaBoost algoritması (ekrandan, 01:00:00).** Eğitim: bütün $\{x^t, r^t\}_{t=1}^{N}$ için $p_1^t = 1/N$. Her $j = 1, \dots, L$ için: $p_j^t$ olasılıklarıyla $\mathcal{X}_j$ çekilir, $d_j$ eğitilir, her örnek için $y_j^t \leftarrow d_j(x^t)$ hesaplanır.
  - Hata: $\epsilon_j \leftarrow \sum_t p_j^t \cdot 1(y_j^t \ne r^t)$. $\epsilon_j > 1/2$ ise $L \leftarrow j-1$ ve dur.
  - $\beta_j \leftarrow \epsilon_j/(1-\epsilon_j)$. Doğru sınıflananlarda $p_{j+1}^t \leftarrow \beta_j p_j^t$, yanlışlarda $p_{j+1}^t \leftarrow p_j^t$.
  - Normalizasyon: $Z_j \leftarrow \sum_t p_{j+1}^t$, $p_{j+1}^t \leftarrow p_{j+1}^t / Z_j$.
  - Test: $y_i = \sum_{j=1}^{L} \left(\log \frac{1}{\beta_j}\right) d_{ji}(x)$, en büyük $y_i$ seçilir.
  - Hocanın sayısal örneği: $\epsilon_j = 0.1$ ise $\beta_j = 0.1/0.9 = 1/9$. $\beta_j$ 0 ile 1 arasında olduğu için doğru sınıflanan örneklerin olasılığı azalır, normalizasyondan sonra yanlış sınıflananlarınki göreli olarak artar.
  - Ders sonrası not: Hoca testte oyların "$\beta_j$ ile çarpıldığını" söyledi; slayttaki formülde ağırlık $\log(1/\beta_j)$'dir. Hatası düşük öğrenicinin $\beta_j$'si küçük, $\log(1/\beta_j)$'si büyük olur (örnekte $\ln 9 \approx 2.20$), bu yüzden karara etkisi fazladır.
- **Random Subspace ve özellik sayısı.** Slayttaki grafikte (perceptron ile bölme) 135, 90, 45, 23 ve 12 rastgele özellik için ağaç sayısına göre doğruluk eğrileri vardır (ekrandan, 01:35:00). Hoca veri kümesinin yanlış hatırlamıyorsa 180 özellikli olduğunu söyledi; 12 ve 23 özellikli eğriler belirgin biçimde altta kalır, diğerleri birbirine yakındır. Genel kabul, özelliklerin yaklaşık yarısını kullanmanın iyi sonuç verdiğidir; bu teorik bir sonuç değildir.
  - Ders sonrası not: Hoca bir yerde "eğitim kümesindeki örnek sayısının yarısı" dedi; bağlam özellik seçimi olduğu için kastedilen büyük olasılıkla özellik sayısının yarısıdır.
- **Random Forest'ın hızı ve ağaç boyu.** Normal ağaçta her düğümde bütün özelliklerin bütün olası eşikleri denenir. Random Forest her düğümde yalnız $\log_2$(özellik sayısı) kadar rastgele özellik dener: 1024 özellikte 10 deneme. İyi özellikler rastgele altkümede bulunmayabileceğinden bölmeler daha kötü olur ve ağaç uzar; buna rağmen düğüm başına maliyet çok düştüğü için toplam süre kısalabilir.
  - Ders sonrası not: Hoca "özellik sayısı 1000 milyonsa 20 kontrol" dedi; $\log_2(10^6) \approx 20$, $\log_2(10^9) \approx 30$'dur. Kastedilen büyük olasılıkla bir milyon özelliktir.
- **Forest-RI tablosu (ekrandan, 01:50:00).** Slayttaki tabloda AdaBoost, Selection, Forest-RI single input ve One tree hata yüzdeleri karşılaştırılır; örneğin Breast cancer için 3.2 / 2.9 / 2.7 / 6.3, Sonar için 15.6 / 15.9 / 18.0 / 31.7, Liver için 30.7 / 25.1 / 24.7 / 40.6. Bütün topluluk yöntemleri tek ağaçtan belirgin biçimde iyidir; aralarındaki farklar küçüktür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
