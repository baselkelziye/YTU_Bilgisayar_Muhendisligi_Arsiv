# Ders 10 Çalışma Özeti

## Genel Konular

- Eğitim ve test kümesi ayrımının nedeni (önceki dersin tekrarı)
  - Model, eğitimde hiç görmediği örnekler üzerinde iyi çalışmalıdır. Test kümesi, sistemin gerçek kullanımda karşılaşacağı yeni örnekleri temsil eder.
  - Test örneklerinin gerçek sınıfları bilinir, ama bilinmiyormuş gibi davranılır; modelin tahminleriyle gerçek sınıfların uyuşması başarıyı verir. Tüm veri eğitime verilirse modelin veriyi ezberleyip ezberlemediği (overfitting) kontrol edilemez.
- Özellik belirleme: neden gerekir (ekrandan, 00:20:00)
  - Bir doktorun hasta dosyasında ad soyad, doğum yeri, cinsiyet, kan tahlili, röntgen sonuçları gibi bilgiler vardır; hepsi hastalığı belirlemek için anlamlı değildir (hastanın adı önemsizdir, cinsiyet önemli olabilir).
  - Slayttaki tabloda 3 özellik ve 4 örnek vardır: 1. özellik (1, 2, 1, 2) sınıfı (A, B, A, B) tam belirler; 2. özellik (3, 3, 4, 3) kısmen bilgi verir (4 ise A, 3 ise büyük olasılıkla B); 3. özellik (hepsi 13) hiçbir bilgi vermez.
  - "Hangi boyut?" grafiğinde (ekrandan, 00:25:00) sınıflar $x_1$ boyutunda iyi ayrılır (yaklaşık $x_1 > 0.05$ ise yuvarlak), $x_2$ boyutunda histogramlar iç içe geçer.
- Balık hali örneği: somon ve levrek (sea bass) (ekrandan, 00:30:00)
  - Kayan bant üzerindeki balıklardan kamera iki özellik çıkarır: uzunluk ve parlaklık.
  - Uzunlukta somonlar genelde levreklerden kısadır ama histogramlar çok iç içedir; en iyi eşikte bile hata büyüktür. Parlaklıkta levrekler daha parlaktır ve en iyi eşikteki hata çok daha azdır. Bu yüzden parlaklık daha iyi özelliktir.
  - Bir eşiğin iyiliği, eşiğin yanlış tarafında kalan (yanlış sınıflanan) örneklerin sayısıyla ölçülür.
- Özellik seçiminin iki ana yolu (ekrandan, 00:35:00)
  - Var olan özelliklerden bazılarını seçmek:
    - Özellikleri tek tek değerlendirmek (filter).
    - Özellik alt kümeleri oluşturup sınıflandırıcıyla performanslarını ölçmek ve alt kümeyi en iyilemek için değiştirmek (wrapper).
  - Var olan özelliklerin doğrusal birleşimlerinden yeni özellikler çıkarmak (PCA, LDA).
- Filter 1: Bilgi kazancı (information gain) (ekrandan, 00:40:00)
  - $Gain(S, A) = Entropy(S) - \sum_{v \in Values(A)} \frac{|S_v|}{|S|} Entropy(S_v)$
  - $Entropy(N) = \sum_{i=1}^{c} -p_i \log_2 p_i$; entropi düzensizliğin ölçüsüdür. İki sınıflı bir kavramda en büyük değer 1'dir (yüzde 50-50), tek değer varsa 0'dır.
  - Piknik örneği: "Pikniğe gidildi mi?" sınıfında evet 3/4, hayır 1/4; $Entropy(Piknik) = 0.811$.
  - $Gain(Piknik, Hava) = 0.811 - \frac{3}{4}(-\frac{3}{3}\log_2\frac{3}{3} - 0) - \frac{1}{4}(0 - \frac{1}{1}\log_2\frac{1}{1}) = 0.811$ (ekrandan, 00:45:00).
  - Rüzgar bütün örneklerde aynı (güçlü) olduğu için kazancı 0'dır.
  - <!-- BELİRSİZ: Nem ve su sıcaklığı özelliklerinin kazanç değerleri ve tablonun tamamı karelerde okunamadı. -->
  - Kazancı yüksek olan özellik iyidir: o özellik kullanıldığında sınıfın entropisi o kadar çok azalır. Kategorik özellikler için uygundur.
- Filter 2: Sinyalin gürültüye oranı (signal-to-noise ratio) (ekrandan, 00:50:00)
  - $S_i = \frac{m_1 - m_2}{d_1 + d_2}$; $m_1, m_2$: iki sınıftaki $i.$ özelliğin ortalamaları (sinyal), $d_1, d_2$: standart sapmaları (gürültü).
  - Sınıflar arası ayrılığın fazla, sınıf içi ayrılığın az olduğu özellikler seçilir. Paydaki $m_1 - m_2$ farkının mutlak değerini almak mantıklıdır. $S$ değeri en yüksek olanlar ya da eşiği geçenler ya da en yüksek $k$ tanesi seçilir. Sayısal özellikler için uygundur.
- Filter yöntemlerinin göremediği durum (ekrandan, 00:55:00)
  - Satranç tahtası biçimli iki sınıflı veride $x_1$ ve $x_2$ tek başlarına hiçbir şey söylemez (histogramlar üst üste biner). Oysa iki özellik birlikte kullanılınca basit kurallarla veri kusursuz sınıflanır. Bu yüzden özellikleri birlikte değerlendiren wrapper yöntemlerine ihtiyaç vardır.
- Wrapper (özellik alt kümesi seçiciler) (ekrandan, 01:25:00)
  - $N$ özellik için $2^N$ alt küme, yani $2^N$ eğitim gerekir; özellik sayısı büyükse hepsini denemek imkânsızdır.
  - Dört özellikli örnek: alt kümeler 0/1 vektörleriyle gösterilir (0,0,0,0 hiçbir özellik, 1,0,0,1 birinci ve dördüncü özellik). Başarılar: (0,0,0,0) 60; (1,0,0,0) 65, (0,1,0,0) 69, (0,0,1,0) 70, (0,0,0,1) 60; (1,0,1,0) 80, (0,1,1,0) 70, (0,0,1,1) 75; (1,1,1,0) 79, (1,0,1,1) 65. Arama 0,0,0,0 → 0,0,1,0 → 1,0,1,0 yolunu izler ve birinci ile üçüncü özelliği seçip durur. (1,1,0,0) alt kümesinin 90 olan başarısı hiç görülmez.
  - Bu, tepe tırmanma algoritmasıdır: global en iyiyi garanti etmez, ama en fazla $n + (n-1) + \dots + 1 = \frac{n(n+1)}{2}$ eğitim yapar ($n^2$ mertebesi; $2^n$'e göre çok küçük).
  - Hiç özellik yokken tahmin: Zero Rule (sıfır kural) algoritması. Eğitim kümesinde en çok hangi sınıf varsa bütün örneklere o sınıf söylenir; sınıfların %60'ı bir sınıftansa başarı yaklaşık %60 olur.
  - Oklar ters çevrilerek tüm özelliklerden başlayıp birer birer çıkarmak da mümkündür. Karmaşıklık aynıdır, ama iki yön farklı sonuç verebilir.
- Yeni özelliklerin çıkarımı (ekrandan, 02:35:00)
  - Var olan özelliklerin doğrusal birleşimlerinden yeni bir özellik uzayı kurulur: $P_1 = W_1 X_1 + W_2 X_2$, $P_2 = W_3 X_1 + W_4 X_2$, ..., $P_N = W_k X_1 + W_m X_2$. Bu bir doğrusal dönüşümdür; özellik sayısını azaltmak için yeni özelliklerin yalnızca bir kısmı kullanılabilir.
  - PCA (temel bileşen analizi) (ekrandan, 01:40:00): örneklerin en fazla değişim (standart sapma) gösterdiği boyutlar bulunur. Önce $c_1$ bulunur, sonra ona dik (ortogonal) $c_2$. Veriler $c_1$ üzerine izdüşürülerek iki boyuttan bire indirgenebilir. Sınıf bilgisini kullanmaz (unsupervised).
  - LDA (doğrusal ayırtaç analizi) (ekrandan, 01:45:00): varyansa ek olarak sınıf bilgisini de kullanır; sınıfların izdüşümde en iyi ayrılacağı ekseni seçer. PCA'nın seçtiği eksende iki sınıf iç içe geçerken LDA'nın ekseninde iyi ayrılır.
- Ne zaman hangi yöntem
  - Her veri kümesinde diğerlerinin hepsinden iyi olan bir algoritma yoktur; bu yüzden pek çok yöntem vardır.
  - Filter'ların maliyeti $n$, wrapper'ların $n^2$ mertebesindedir. Hesaplama maliyeti ile doğruluk arasında bir ödünleşim (trade-off) vardır.
  - Sayısal veride sinyalin gürültüye oranı, kategorik veride bilgi kazancı doğal seçimdir.
- Sınıflandırma metotları (ekrandan, 01:50:00)
  - Görev: önceden etiketlenmiş örnekleri kullanarak yeni örneklerin sınıflarını bulmak. Metotlar: regresyon, karar ağaçları, LVQ, yapay sinir ağları vb. Özellik seçimi yapmak zorunlu değildir.
  - Her yöntem karar sınırlarının yapısı hakkında bir varsayımda bulunur; varsayım verinin gerçeğiyle uyuşursa yöntem iyi çalışır.
- Doğrusal regresyon (ekrandan, 01:55:00)
  - Karar sınırı $w_0 + w_1 x + w_2 y \geq 0$ biçiminde bir doğru/düzlem/hiperdüzlemdir. Regresyon en az hata yapan $w_i$'leri bulmaya çalışır.
  - Basit ve hızlı bir modeldir ama yeterince esnek değildir.
  - Büyük veride genellikle iteratif çözülür: ağırlıklar rastgele başlatılır, eğitim hatası azalacak biçimde adım adım güncellenir. Yapay sinir ağlarının eğitimi de aynı mantıktadır.
  - Ağırlıklar yorumlanabilir: aynı aralıktaki iki özellikte $w_1 = 9$, $w_2 = 0.2$ ise birinci özellik karara çok daha etkilidir.
- Karar ağaçları
  - Karar sınırları özelliklere diktir (dikdörtgenler, çok boyutta hiper dikdörtgenler prizmaları). Üretilen kurallar kolay anlaşılır.
  - Oluşturma: tüm veriyle başla, bir özelliğin bir değerine göre veriyi iki alt kümeye böl, özelliği ve eşiği karar düğümüne yaz; her alt kümede yalnızca tek sınıf kalana kadar aynı işlemi özyinelemeli uygula.
  - Aday bölmeler komşu değerlerin ortalarıdır (1.5, 2.5, ...). Her bölme için iki parçanın entropileri toplanır ($E_A + E_B$); en küçük toplamı veren bölme seçilir (ekrandan, 02:10:00 ve 02:15:00).
  - Gerçek bir örnek ağaç (ekrandan, 02:20:00): kökte Uniformity of Cell Size ≤ 3, alt düğümlerde Bare Nuclei, Marginal Adhesion, Clump Thickness vb.; yapraklar benign/malignant.
  - Test örneği kökten bırakılır, her düğümdeki soruya göre dallanarak bir yaprağa düşer ve o yaprağın sınıfını alır.
- Yapay sinir ağları (ekrandan, 02:35:00)
  - Her gizli katman veriyi yeni bir uzaya dönüştürür ve ardından doğrusal olmayan bir $f$ fonksiyonu uygular. Boyutlar: $X(100 \times 10) \cdot W_1(10 \times 5) = H_1(100 \times 5)$, sonra $H_1(100 \times 5) \cdot W_2(5 \times 40)$.
  - Eğitim, $W$ matrislerinin rastgele bir başlangıçtan veriye en uygun hale getirilmesidir.
  - TensorFlow Playground gösterimi (ekrandan, 02:40:00 ve 02:45:00): sarmal veri kümesinde 2 gizli katmanlı (4 ve 2 nöron), tanh aktivasyonlu ağ yetersiz kaldı (test kaybı 0.342); 5 gizli katman, ReLU, L1 düzenlileştirme ve $X_1^2$, $X_2^2$, $X_1X_2$ gibi ek girişlerle test kaybı 0.089'a indi.
- Hiperparametre
  - Algoritmanın çalışması için gerekli olan ama algoritmanın kendisinin belirleyemediği parametrelerdir: gizli katman sayısı, katmanlardaki nöron sayısı, aktivasyon fonksiyonu, öğrenme oranı; genetik algoritmalarda mutasyon oranı, çaprazlama noktası sayısı, popülasyon büyüklüğü; k-NN'de $k$.
  - Hiperparametre ne kadar çoksa model o kadar esnek olur, ama deneme yanılma süreci uzar; eğitimi bir hafta süren büyük modellerde bu ciddi bir sorundur.
- En yakın $k$ komşu (k-NN) (ekrandan, 02:50:00)
  - "Bana arkadaşını söyle, sana kim olduğunu söyleyeyim." Eğitim (modelleme) süreci yoktur.
  - Test örneğine en yakın $k$ eğitim örneği bulunur, çoğunluğun sınıfı verilir. Slayttaki örnekte en yakın 1 komşuya göre A, en yakın 3 komşuya göre (B, B, A) B sınıfı çıkar.
  - Dezavantaj: eğitim kümesinin tamamı saklanmalıdır; örnek sayısı çoksa test süresi çok uzar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Asıl performans, modelin görmediği örneklerdeki performanstır
  - Bir OCR programını satın alan kullanıcı, programı kendi verisinde çalıştırır; firmanın kendi verisindeki başarı onu ilgilendirmez. Test kümesi bu yüzden ayrılır.
- Zero Rule algoritmasının adı
  - "Adını unutmayın": hiç özelliğe bakmadan en kalabalık sınıfı söylemek. Her yöntemin başarısı bu taban değerle karşılaştırılmalıdır.
- Her durumda en iyi algoritma yoktur
  - Özellik seçimi, sınıflandırma, kümeleme ve regresyonun hepsinde geçerlidir. Öyle bir algoritma olsaydı diğerleri yalnızca tarihsel öneme sahip olurdu; bu teorik olarak da mümkün değildir.
- Yöntem seçmek, karar sınırı hakkında varsayım yapmaktır
  - Doğrusal regresyon düz bir sınır, karar ağacı özelliklere dik sınırlar, LVQ yerel merkezlerin önemli olduğunu varsayar; yapay sinir ağları daha karmaşık dönüşümler yapar.
- Tepe tırmanma tabanlı wrapper global en iyiyi garanti etmez
  - Başlangıç noktası (boş küme ya da tüm özellikler) sonucu etkileyebilir; ama $2^n$ yerine $n^2$ mertebesinde eğitimle yeterince iyi bir çözüm bulur.

## Kısa Tekrar Notları

- Her özellik çıkışı belirlemede eşit derecede yararlı değildir; bütün örneklerde aynı olan özellik hiçbir bilgi taşımaz.
- Filter: her özellik tek başına değerlendirilir ($n$ değerlendirme). Wrapper: alt kümeler sınıflandırıcıyla denenir. Doğrusal birleşim: PCA, LDA.
- Entropi: $-\sum p_i \log_2 p_i$; iki sınıfta en fazla 1. Bilgi kazancı = sınıf entropisindeki azalma.
- $Entropy(3/4, 1/4) = 0.811$; $Gain(Piknik, Hava) = 0.811$; $Gain(Piknik, \text{Rüzgar}) = 0$.
- $S_i = (m_1 - m_2)/(d_1 + d_2)$: büyük olması iyidir.
- Filter'lar satranç tahtası verisinde başarısız olur; özellik etkileşimini wrapper yakalar.
- Wrapper + tepe tırmanma: en fazla $n(n+1)/2$ eğitim; global en iyi garanti değil.
- Zero Rule: en kalabalık sınıfı söyle.
- PCA: en çok varyans, sınıf bilgisi yok. LDA: sınıfları en iyi ayıran eksen, sınıf bilgisi gerekir.
- Doğrusal regresyon: $w_0 + w_1x + w_2y \ge 0$, basit ama esnek değil.
- Karar ağacı: dik sınırlar, en düşük $E_A + E_B$ bölmesi, tek sınıf kalana kadar böl.
- YSA: her gizli katman bir matris çarpımı + doğrusal olmayan fonksiyon.
- Hiperparametre: algoritmanın kendisinin bulamadığı ayar (katman sayısı, öğrenme oranı, $k$ ...).
- k-NN: eğitim yok, test pahalı, bütün eğitim verisi saklanır.

## Detaylı Açıklamalar

- **Histogramla özellik değerlendirme.** Bir özelliğin iyi olup olmadığını görmenin yolu, her sınıf için o özelliğin histogramını çizmektir. "Hangi boyut?" örneğinde $x_1$ ekseninde çarpılar solda, yuvarlaklar sağda toplanır; tek bir eşikle (yaklaşık 0.05) iki sınıf büyük ölçüde ayrılır. $x_2$ ekseninde ise iki histogram iç içe geçer ve tek başına $x_2$'ye bakarak "şundan büyükse şu sınıf" demek mümkün olmaz. Balık örneğinde de eşik farklı yerlere konarak yanlış sınıflanan balıklar sayılır: eşiğin solunda kalan levrekler ve sağında kalan somonlar hatadır. En az hata veren eşik o özellik için en iyi eşiktir; bu en iyi hatalar karşılaştırılarak parlaklığın uzunluktan daha iyi özellik olduğu görülür. <!-- BELİRSİZ: Hocanın histogramdan okuduğu tek tek balık sayıları (ör. eşik 5 için 9 yanlış) altyazıda tutarsız; nota alınmadı. -->
- **Entropinin iki uç değeri (derste tahtada).** 6 örnekten 3'ü A, 3'ü B ise $p_A = p_B = 0.5$ ve $\log_2 0.5 = -1$ olduğundan $Entropy = -(0.5 \cdot (-1) + 0.5 \cdot (-1)) = 1$. Bu, hiçbir yapının olmadığı, tahminin hiç yapılamadığı en düzensiz durumdur. Bütün örnekler A ise $p_A = 1$, $\log_2 1 = 0$, $p_B = 0$ olduğundan entropi 0'dır.
- **Piknik örneğinde kazanç hesabı (ekrandan, 00:45:00).** Sınıfın entropisi $-\frac{3}{4}\log_2\frac{3}{4} - \frac{1}{4}\log_2\frac{1}{4} = 0.811$. Hava özelliğinin iki değeri vardır: güneşli (oran 3/4; üçünde de pikniğe gidilmiş) ve yağmurlu (oran 1/4; gidilmemiş). Her iki alt kümenin entropisi 0 olduğundan çıkarılan terim 0'dır ve kazanç 0.811 kalır, yani hava sınıfın bütün belirsizliğini ortadan kaldırır. Rüzgarda ise tek değer olduğundan alt kümenin entropisi sınıfın entropisine eşittir, $0.811 - 0.811 = 0$. $Entropy(S)$ terimi bütün özellikler için aynı olduğundan, karşılaştırma yaparken tekrar tekrar hesaplanması gerekmez.
- **Wrapper arama yolunun okunması (ekrandan, 01:25:00).** Başlangıçta boş küme %60 başarı verir (Zero Rule). Tek özellikli dört komşudan en iyisi (0,0,1,0) %70'tir ve 60'tan iyidir; oraya geçilir. Buradan (1,0,1,0) %80, (0,1,1,0) %70, (0,0,1,1) %75 olur; %80'e geçilir. Buradan (1,1,1,0) %79, (1,0,1,1) %65 olur; ikisi de 80'den kötü olduğu için algoritma durur ve birinci ile üçüncü özelliği döndürür. Oysa (1,1,0,0) %90'dır; bu düğüme hiç bakılmadığı için bulunamaz. Bu, yerel arama algoritmalarının bilinen sorunudur.
- **Karar ağacının ilk bölmesi (ekrandan, 02:05:00-02:15:00).** Veri $x_1 \in \{1,2,3,4\}$, $x_2 \in \{1,\dots,5\}$ ızgarasında 20 noktadır. Tüm veri için 7 aday bölme vardır: $x_1 < 1.5, 2.5, 3.5$ ve $x_2 < 1.5, 2.5, 3.5, 4.5$. Slaytta $x_2 < 1.5$ seçilmiş varsayılarak devam edilmiştir (hoca değerleri hesaplamadığını, "diyelim ki bu en küçük" dediğini belirtti). Sonra alttaki satır ($x_2 = 1$) için yalnızca $x_1$ bölmeleri mümkündür ve $x_1 < 2.5$ iki parçayı da saf yapar (entropi 0). Üstteki bölge için $x_2 < 1.5$ artık aday değildir; slaytta $x_1 < 1.5$ seçilmiştir. Bu işlem bütün bölgeler tek sınıflı olana kadar sürer.
  - Ders sonrası not: Slayttaki ızgara değerleriyle python ile yapılan hesapta tüm veri için $E_A + E_B$ en küçük değeri (1.693) $x_1 < 1.5$ ve $x_1 < 3.5$ bölmelerinde verir; $x_2 < 1.5$ ise iki parçada da sınıflar yarı yarıya olduğu için en büyük değeri (2.0) verir. Yani slayttaki yıldız yalnızca anlatım için konmuş bir varsayımdır. Üst bölgede $x_1 < 1.5$ gerçekten en küçük değeri (0.918, $x_1 < 3.5$ ile eşit) verir.
- **Yapay sinir ağında boyutlar.** 100 örnek ve 10 özellikli giriş matrisi $10 \times 5$ ağırlık matrisiyle çarpılınca 100 × 5 boyutlu birinci gizli katman temsili elde edilir; bu, 10 boyutlu uzayın 5 boyutlu bir uzaya dönüştürülmesidir (matris $10 \times 50$ olsaydı 50 boyuta çıkılırdı). Bu temsil $5 \times 40$ matrisle çarpılınca 100 × 40 boyutlu ikinci katman temsili oluşur. Her adımda doğrusal olmayan bir fonksiyon uygulanır ve en sonda sınıflandırıcı yapı vardır. Bu açıdan bakıldığında gizli katmanlar, PCA ve LDA'daki doğrusal dönüşümlerin doğrusal olmayan ve ardışık bir genellemesi gibidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
