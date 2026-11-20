# Ders 7 Çalışma Özeti

## Genel Konular

- Sınıflandırma ve tahmin (prediction)
  - Öngörücü (predictive) yöntemlerde çıktı ayrık bir sınıf etiketiyse problem sınıflandırmadır, sürekli bir değerse tahmindir (prediction). Tahmin yöntemleri genellikle regresyona dayanır (lineer regresyon, lojistik regresyon gibi).
  - Sınıflandırma yapan modele sınıflandırıcı (classifier) denir. Derste sırasıyla karar ağaçları, Bayes sınıflandırıcıları, kural tabanlı sınıflandırıcılar ve destek vektör makinelerinin işleneceği söylendi.
  - Yapay sinir ağları hem sınıflandırmada hem tahminde kullanılabilir; bazı türleri kümeleme gibi tanımlayıcı (descriptive) işlerde de kullanılır.
- Sınıflandırma iki adımlı bir süreçtir (ekrandan, 00:07:45)
  - Model oluşturma (model construction): her örneğin (tuple/sample) önceden belirlenmiş bir sınıfa ait olduğu varsayılır; sınıf etiketi özniteliği bunu belirler. Modeli kurmakta kullanılan örnekler eğitim kümesidir (training set). Model kurallar, karar ağacı ya da matematiksel formül olarak gösterilebilir.
  - Model kullanımı (model usage): modelin doğruluğu (accuracy) test kümesiyle ölçülür; doğruluk kabul edilebilir düzeydeyse model yeni ve etiketi bilinmeyen verileri sınıflandırmakta kullanılır.
  - Test kümesi eğitim kümesinden bağımsız olmalıdır. Elimizdeki etiketli verinin genellikle %10-%20'si (en fazla %30'a kadar) test için ayrılır. Ayırma rastgele yapılmalıdır; verinin sonundaki kısmı almak (örneğin yalnız son yılın verisi) yanıltıcı olur.
  - Doğruluk = doğru tahmin sayısı / tüm tahminler. Doğru tahminler, artı iken artı ve eksi iken eksi denen örneklerdir. Örnek: 1000 test örneğinin 790'ı doğru tahmin edilirse doğruluk %79'dur.
  - Yeni gelen örnekte de modelin eğitildiği $n-1$ öznitelik bulunmalıdır; modelin görmediği bir öznitelik modele sorulamaz.
  - Model kurma tümevarım (induction), modeli test kümesine uygulama tümdengelim (deduction) olarak adlandırılır (ekrandan, 00:22:45).
- Karar ağacı (decision tree)
  - Akış diyagramına benzer bir ağaçtır; ikili olmak zorunda değildir. Her iç düğüm bir özniteliği test eder, her dal bir değere karşılık gelir, yapraklarda sınıf etiketi vardır (ekrandan, 00:27:45).
  - Kitaptaki "bilgisayar alır mı" örneği: kök `age`; `<=30` dalında `student`, `31..40` dalında doğrudan `yes`, `>40` dalında `credit_rating` sorulur. (age <= 30, income = low, student = no, credit_rating = fair) örneği negatif sınıflanır (ekrandan, 00:27:45).
  - Her öznitelik bir yol üzerinde yalnız bir kez sorulur.
- Karar ağacı oluşturma algoritması (Generate_Decision_Tree) (ekrandan, 01:15:10)
  - D'deki örneklerin hepsi aynı C sınıfındaysa düğüm C etiketli yaprak olur.
  - Öznitelik listesi boşsa düğüm, D'deki çoğunluk sınıfıyla etiketlenen yaprak olur (majority voting).
  - Aksi halde öznitelik seçme yöntemiyle en iyi bölme ölçütü bulunur, düğüm bununla etiketlenir; ayrık değerli ve çok yollu bölmeye izin varsa bu öznitelik listeden çıkarılır.
  - Her sonuç j için $D_j$ bölümü oluşturulur; $D_j$ boşsa çoğunluk sınıfıyla bir yaprak eklenir, değilse algoritma $D_j$ ve kalan öznitelik listesiyle özyinelemeli çağrılır.
  - Algoritma açgözlü (greedy) çalışır: her adımda o anki en iyi bölmeyi seçer; bulunan ağaç global en iyi ağaç olmayabilir.
- Bölme türleri
  - Bölme ölçütü öznitelik tipine (ikili, nominal, sıralı, sürekli) göre değişir.
  - İki değerli bölmeye ikili (binary, two-way) bölme, ikiden çok değerliye çok yollu (multi-way) bölme denir. CART, ID3, C4.5 gibi algoritmalar bu konularda ve kullandıkları ölçüde farklıdır.
  - Durma: bir düğümdeki örneklerin hepsi aynı sınıftaysa ya da bakılacak örnek kalmadıysa bölme durur; istatistiksel bir teste göre erken durdurma da yapılabilir.
- En iyi bölmeyi bulma ve safsızlık (impurity)
  - Homojen (saf) sınıf dağılımlı düğümler tercih edilir: [9+,1-] homojendir, safsızlığı düşüktür; [5+,5-] homojen değildir, safsızlığı yüksektir (ekrandan, 00:47:45).
  - Adımlar (ekrandan, 00:55:10): bölmeden önce safsızlık P hesaplanır; bölmeden sonra her çocuğun safsızlığı ve bunların ağırlıklı ortalaması M hesaplanır; Gain = P - M en büyük olan seçilir. P sabit olduğu için bu, M'si en küçük olanı seçmekle aynıdır.
- Entropi ve bilgi kazancı (information gain)
  - $\text{Entropy}(S) = -p_+\log_2 p_+ - p_-\log_2 p_-$ (ekrandan, 01:00:10). Oranlar 1'den küçük olduğu için logaritmalar negatiftir; başlardaki eksi işareti sonucu pozitif yapar.
  - Çok sınıflı genel hali: $\text{Info}(D) = -\sum_{i=1}^{m} p_i \log_2 p_i$, $p_i = |C_{i,D}|/|D|$. Sınıf sayısı artsa da taban 2 kalır.
  - Bölmeden sonra: $\text{Info}_A(D) = \sum_{j=1}^{v} \frac{|D_j|}{|D|}\,\text{Info}(D_j)$; kazanç $\text{Gain}(A) = \text{Info}(D) - \text{Info}_A(D)$ (ekrandan, 01:05:10).
  - Örnek veri (14 satır, [9+,5-]): $\text{Info}(D)=0.940$; kazançlar age 0.246, income 0.029, student 0.151, credit_rating 0.048. En yüksek kazanç age'de olduğu için kök age olur (ekrandan, 01:10:10).
- Sürekli öznitelikler
  - Değerler sıralanır, sınıfın değiştiği komşu değerlerin orta noktaları aday eşik olur. Örnek: sıcaklık 40, 48, 60, 72, 80, 90 ve sınıflar No, No, Yes, Yes, Yes, No için adaylar $(48+60)/2=54$ ve $(80+90)/2=85$'tir; Temperature>54 ve Temperature>85 ikili öznitelikler gibi değerlendirilir (ekrandan, 01:30:10).
- Kazanç oranı (gain ratio)
  - Bilgi kazancı çok sayıda değeri olan özniteliklere doğru yanlıdır. C4.5 bu yüzden kazancı normalize eden kazanç oranını kullanır (ekrandan, 01:35:10).
  - $\text{SplitInfo}_A(D) = -\sum_{j=1}^{v}\frac{|D_j|}{|D|}\log_2\frac{|D_j|}{|D|}$, $\text{GainRatio}(A) = \text{Gain}(A)/\text{SplitInfo}_A(D)$. Income için SplitInfo = 1.557, GainRatio = 0.029/1.557 = 0.019.
- Gini indeksi
  - $\text{Gini} = 1 - \sum_j p_j^2$. İki sınıfta [0,6] için 0, [3,3] için 0.5 çıkar; dağılım homojenleştikçe değer düşer. Logaritma içermediği için daha hızlı hesaplanır. CART, SLIQ, SPRINT gibi algoritmalarda kullanılır.
  - Bölme sonrası: $\text{GINI}_{split} = \sum_{i=1}^{k}\frac{n_i}{n}\,\text{GINI}(i)$; ağırlıklı Gini'si en küçük öznitelik seçilir (ekrandan, 01:40:10).
  - İkili öznitelik örneği: A ile bölme 0.486, B ile bölme 0.371 verir; B seçilir (ekrandan, 01:45:10).
  - Sürekli öznitelik örneği (Annual Income): her aday bölme konumu için Gini hesaplanır; en küçük değer 97'de 0.300'dür (ekrandan, 02:00:10).
- Diğer öznitelik seçme ölçüleri: CHAID (ki-kare bağımsızlık testine dayanır), G-istatistiği, birden çok özniteliğin lineer birleşimiyle bölme (CART). Hiçbiri ötekilerden belirgin biçimde üstün değildir; en çok entropi ve Gini kullanılır (ekrandan, 02:05:10).
- Aşırı uyum (overfitting) ve eksik uyum (underfitting) (ekrandan, 02:10:10)
  - Aşırı uyum: model eğitim verisinde çok iyi, görülmemiş veride kötü çalışır. Eğitim hatası düşmeye devam ederken test hatası bir noktadan sonra artar. Nedenleri: gürültü ve yetersiz örnek.
  - Eksik uyum: model çok basittir; eğitim ve test hataları ikisi de yüksektir ve hâlâ düşmektedir.
  - Önlemler: ön budama (pre-pruning, iyilik ölçüsü bir eşiğin altına düşecekse bölmeyi durdurmak) ve son budama (post-pruning, tam büyümüş ağaçtan dalları kesmek).
- Karar ağaçlarının güçlü ve zayıf yanları
  - Uygulaması ve anlaşılması kolaydır, hızlıdır, kategorik ağırlıklı ve eksenlere paralel ayrılabilen verilerde iyi çalışır; ağaçtan if-then kuralları çıkarılabilir.
  - Her karar sınırında tek öznitelik vardır; sınıflar eğik bir doğru ya da eğriyle ayrılıyorsa çok sayıda basamakla yaklaşmak gerekir (ekrandan, 02:25:10). Çok büyük veride bellek sorunu çıkabilir; RainForest, SPRINT gibi daha ölçeklenebilir algoritmalar vardır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Entropi ve bilgi kazancıyla en iyi özniteliği seçme hesabı
  - Hoca bu hesabın en kolay yöntem olduğunu ve sınavda kesin sorulacağını söyledi; örnek veri üzerinde dört özniteliğin kazancını tek tek hesaplamayı bilmek gerekir.
- Eğitim ve test hatasının birlikte izlenmesi
  - Aşırı uyumu anlamak için yalnız test hatasına değil, eğitim hatasına da bakılır. İki hata arasında %1-3 fark normaldir; fark açılıyorsa aşırı uyum vardır. Eğitim verisinde %100 doğruluk genellikle modelin gürültüyü de öğrendiğini gösterir.
- Test kümesi rastgele seçilmeli
  - Veri tabanından çekilen veri çoğunlukla bir şeye göre sıralıdır; son kısmı test olarak almak yanlıdır. Ya rastgele seçilir ya da önce karıştırılır (shuffle).
- Rastgele tahmin taban çizgisi
  - İki sınıflı ve dengeli bir problemde rastgele tahmin bile %50 doğruluk verir; %60 doğruluk iyi bir sonuç sayılmaz.
- Bölmede homojenlik
  - İyi bir bölme, çocuk düğümlerde aynı sınıftan örnekleri toplar. Örneğin [4+,0-] dalı doğrudan yaprak olur.
- Açgözlü yapı
  - Entropi ile kurulan ağaç Gini ile kurulandan farklı olabilir; öznitelik listesinin sırası değişince bile farklı ağaç çıkabilir. Bulunan ağacın global en iyi olduğu garanti değildir.
- Eğitim grafiğini çizmek
  - Eğitim sırasında hata eğrilerini çizmek, modelin aşırı ya da eksik uyumda olup olmadığını görmeyi sağlar; özellikle yapay sinir ağlarında önemlidir.

## Kısa Tekrar Notları

- Sınıflandırma: ayrık etiket; tahmin: sürekli değer.
- İki adım: eğitim kümesiyle model kur (induction), test kümesiyle doğruluğu ölç ve uygula (deduction).
- Doğruluk = doğru tahmin / tüm tahmin.
- Test kümesi: verinin yaklaşık %10-%30'u, rastgele seçilir.
- Karar ağacı: iç düğüm = öznitelik testi, dal = değer, yaprak = sınıf.
- Durma: tüm örnekler aynı sınıfta ya da öznitelik kalmadı (çoğunluk oylaması).
- $\text{Gain}(A) = \text{Info}(D) - \text{Info}_A(D)$; en büyük kazanç seçilir.
- Örnekte $\text{Info}(D)=0.940$, Gain(age) = 0.246 en büyük, kök age.
- Entropi iki sınıfta 0 (saf) ile 1 (eşit dağılım) arasındadır.
- GainRatio = Gain / SplitInfo; çok değerli özniteliklere karşı yanlılığı azaltır (C4.5).
- Gini = $1-\sum p_j^2$; iki sınıfta 0 ile 0.5 arası; ağırlıklı Gini'si en küçük bölme seçilir (CART, SLIQ, SPRINT).
- Sürekli öznitelik: sırala, sınıf değişim noktalarının ortası aday eşik, en iyi eşik seçilir.
- Aşırı uyum: eğitim hatası düşük, test hatası yüksek; nedenleri gürültü ve az örnek.
- Eksik uyum: iki hata da yüksek.
- Ön budama ve son budama aşırı uyumu azaltır.
- Karar ağacı sınırları eksenlere paraleldir; eğik sınırlarda zorlanır.

## Detaylı Açıklamalar

- **Sınıflandırma süreci.** Derste önce sınıflandırmanın yeri hatırlatıldı. Veri madenciliği yöntemleri öngörücü ve tanımlayıcı diye ikiye ayrılır. Öngörücü yöntemlerin çıktısı ayrık bir sınıfsa sınıflandırma, sürekli bir değerse tahmin söz konusudur. Sınıflandırmada elimizde etiketli bir eğitim kümesi vardır. Hocanın bitki örneğinde her satır bir bitkidir; yaprağın eni, boyu, çiçek rengi gibi öznitelikler ölçülmüş ve bitkinin cinsi sınıf olarak yazılmıştır. Bu kümeden bir model kurulur; artık eğitim kümesiyle işimiz biter ve yeni gelen, cinsi bilinmeyen bitkinin sınıfı modele sorulur. Modelin ne kadar iyi çalıştığını bilmek için etiketli verinin bir kısmı baştan ayrılır. Model yalnız geri kalan kısımla eğitilir, sonra ayrılan test kümesindeki örnekler modele sorulur ve tahminler gerçek etiketlerle karşılaştırılır. Doğru tahminlerin tüm tahminlere oranı doğruluktur. Hocanın örneğinde 10.000 satırın %10'u (1000 satır) test için ayrılmış, 1000 tahminin 790'ı doğru çıkmış, doğruluk %79 olmuştur.

- **Karar ağacı ve algoritması.** Karar ağacında bir örnek kökten başlayarak her düğümde sorulan özniteliğin değerine göre ilgili dala iner ve ulaştığı yapraktaki sınıfı alır. Kitaptaki 14 satırlık "bilgisayar alır mı" verisinde dört öznitelik vardır: age, income, student, credit_rating. Algoritma özyinelemelidir. Bir düğümdeki örneklerin hepsi aynı sınıftaysa düğüm yaprak olur (örnekte age = 31..40 dalı [4+,0-] olduğu için doğrudan yes yaprağıdır). Öznitelik kalmamışsa çoğunluk oylamasıyla etiket verilir. Aksi halde en iyi öznitelik seçilir, veri bu özniteliğin değerlerine göre $D_1, D_2, \dots$ bölümlerine ayrılır ve her bölüm için algoritma kalan özniteliklerle yeniden çağrılır. Derste algoritmanın for döngüsü içinde önce $D_1$ dalını en alta kadar işleyip sonra $D_2$'ye geçtiği, yani derinlik öncelikli ilerlediği tartışıldı. Hoca bunun tek doğru uygulama olmadığını; farklı algoritmaların (CART, ID3, C4.5) farklı uygulandığını, kendisinin genişlik öncelikli bir uygulamayı ve sonradan budamayı daha mantıklı bulduğunu söyledi.

- **Bilgi kazancı hesabı.** Kök için önce sınıf dağılımı [9+,5-] üzerinden $\text{Info}(D) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} = 0.940$ bulunur. age ile bölünce dallar [2+,3-], [4+,0-], [3+,2-] olur. $\text{Info}_{age}(D) = \frac{5}{14}(0.971) + \frac{4}{14}(0) + \frac{5}{14}(0.971) = 0.694$, kazanç $0.940-0.694 = 0.246$'dır (ekrandan, 01:10:10). Aynı hesap income ([3+,1-], [4+,2-], [2+,2-]) için 0.911 ve kazanç 0.029; student ([3+,4-], [6+,1-]) için kazanç 0.151; credit_rating ([6+,2-], [3+,3-]) için kazanç 0.048 verir. En büyük kazanç age'dedir, kök age olur ve age listeden çıkarılır. Sonra her dal yalnız kendi örnekleriyle (örneğin `<=30` dalındaki 5 kişiyle) aynı hesaba devam eder; öteki dallardaki örnekler artık bu hesaba girmez.

- **Entropinin anlamı.** Entropi bilgi kuramından gelir ve bir kümedeki örneği sınıflandırmak için gereken beklenen bilgiyi ölçer. Derste verilen örneklerde [12+,5-] için yaklaşık 0.87, [8+,8-] için 1, [8+,0-] için 0 çıkar. Saf düğümün entropisi 0'dır; iki sınıf eşit dağıldığında entropi en büyük değeri olan 1'e ulaşır.

- **Kazanç oranı.** Bilgi kazancı çok değerli özniteliklere yanlıdır. SplitInfo, verinin dallara nasıl dağıldığını (sınıflara bakmadan) ölçer; income için dallardaki örnek sayıları 4, 6, 4 olduğundan $\text{SplitInfo} = -\frac{4}{14}\log_2\frac{4}{14} - \frac{6}{14}\log_2\frac{6}{14} - \frac{4}{14}\log_2\frac{4}{14} = 1.557$ ve $\text{GainRatio} = 0.029/1.557 = 0.019$ olur. Kazanç oranı en büyük öznitelik seçilir.

- **Gini indeksi.** Gini, sınıf oranlarının karelerinin toplamını 1'den çıkarır. Bölme sonrası çocukların Gini'leri örnek sayılarıyla ağırlıklandırılır. İkili örnekte ebeveyn [6,6] (Gini 0.5) iken A ile bölme çocukları (4,3) ve (2,3): $\text{Gini}(N1) = 1-(4/7)^2-(3/7)^2 = 0.49$, $\text{Gini}(N2) = 1-(2/5)^2-(3/5)^2 = 0.48$, ağırlıklı $\frac{7}{12}(0.49)+\frac{5}{12}(0.48) = 0.486$. B ile bölme çocukları (1,4) ve (5,2): 0.32 ve 0.408, ağırlıklı 0.371. Daha küçük olduğu için B seçilir (ekrandan, 01:45:10). Sürekli Annual Income örneğinde değerler sıralanır, aday bölme konumlarında Gini hesaplanır; 80'de 0.343, 97'de 0.300 bulunur ve en iyi bölme "Annual Income <= 97" olur (ekrandan, 02:00:10). Çoğu algoritma sürekli özniteliği ikiye böler; bazıları parametreyle daha çok parçaya bölebilir.

- **Aşırı uyum.** Hoca, iki boyutlu bir uzaya kırmızı ve mavi noktalar ile birkaç gürültü noktası çizdi (02:14:15-02:16:10 arası). Her düğüm uzayı bir özniteliğe göre ikiye böler; ağaç büyüdükçe bölmeler tek tek gürültü noktalarını ayırmaya başlar ve model gürültüye duyarlı hale gelir. Slayttaki grafikte düğüm sayısı arttıkça eğitim hatası sürekli düşer, test hatası ise belli bir noktadan sonra yükselir (ekrandan, 02:10:10). Bunun önüne ön budama ya da son budamayla geçilir. Karmaşık modeller aşırı uyuma daha yatkındır; aynı hatayı veren iki modelden basit olanı tercih etmek çoğu zaman daha iyidir.

- **Güçlü ve zayıf yanlar.** Karar ağaçları kolay uygulanır, kolay anlaşılır ve hızlıdır; ağaçtan kurallar çıkarılabilir, bu da uzman bilgisinin programa dökülmesine ve kararların açıklanmasına yarar. Her karar sınırı tek bir özniteliğe dayandığı için sınırlar eksenlere paraleldir; slayttaki köşegen sınırla ayrılan veri gibi durumlarda ağaç çok sayıda basamakla yaklaşmak zorunda kalır (ekrandan, 02:25:10). Sınıf yerine sürekli değer üreten ağaçlar da vardır (CART'taki "regression"); bunun nasıl yapıldığı derste soru olarak bırakıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
