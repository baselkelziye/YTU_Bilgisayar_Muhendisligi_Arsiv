# Ders 10 Çalışma Özeti

## Genel Konular

- Hiyerarşik kümeleme (hierarchical clustering)
  - Eğiticisiz (sınıf etiketi olmayan) kümeleme yöntemlerinden, k-means'ten sonra görülen ikinci yöntemdir. Nesneleri bir küme ağacı şeklinde gruplar (ekrandan, 00:25:00).
  - İki yaklaşım vardır: aşağıdan yukarı birleştiren (bottom-up, merging) **agglomerative** ve yukarıdan aşağı bölen (top-down, splitting) **divisive** yöntem.
  - Agglomerative yöntemler üç gruba ayrılır: linkage yöntemleri (single, complete, average linkage), varyans yöntemleri (Ward yöntemi) ve centroid yöntemleri (ekrandan, 00:45:00).
- AGNES ve DIANA
  - AGNES (Agglomerative Nesting): başlangıçta her nesne kendi başına bir "atomik küme"dir; kümeler bir ölçüte göre adım adım birleştirilir.
  - DIANA (Divisive Analysis): bütün örnekler tek kümede başlar, bölünerek sonunda atomik kümelere inilir.
  - Beş nesneli {a, b, c, d, e} örneğinde AGNES sırasıyla {a,b}, {d,e}, {c,d,e} ve {a,b,c,d,e} kümelerini oluşturur; DIANA aynı adımları ters sırada izler (ekrandan, 00:30:00).
- Dendrogram ve durma koşulu
  - Birleştirme işlemleri, hangi uzaklık düzeyinde hangi kümelerin birleştiğini gösteren bir ağaç diyagramıyla (dendrogram) çizilir.
  - Bir eşik değeri ya da istenen küme sayısı durma koşulu olarak kullanılır. Eşik çizgisinin dendrogramı kestiği nokta sayısı oluşan küme sayısıdır.
- Kümeler arası uzaklık ölçüleri
  - Minimum uzaklık: iki kümedeki birbirine en yakın iki örnek arasındaki uzaklık; bu ölçüyle yapılan kümeleme **single linkage** adını alır.
  - Maksimum uzaklık: birbirine en uzak iki örnek arasındaki uzaklık; **complete linkage**.
  - Ortalama uzaklık: iki kümedeki örneklerin bütün çiftleri arasındaki uzaklıkların ortalaması; **average linkage** (iki kümede ikişer örnek varsa 4 uzaklığın ortalaması).
  - Ortalama (mean) uzaklık: küme merkezleri (centroid) arasındaki uzaklık; centroid yöntemi.
- Ward yöntemi (varyans yöntemi)
  - Her olası birleştirme için oluşacak yeni kümenin küme içi varyansını hesaplar ve birleştirme sonunda en küçük varyansı veren iki kümeyi birleştirir.
- Kümeleme kalitesi
  - İç ölçütler (internal criteria): küme içi benzerlik (intra-class similarity) yüksek, kümeler arası benzerlik (inter-class similarity) düşük olmalıdır.
  - Dış ölçütler (external criteria): alan uzmanının etiketlediği veri (ground truth) varsa, etiketler yalnız değerlendirme aşamasında açılarak kümelerin doğruluğu ölçülür.
  - Saflık (purity): her kümede en çok bulunan sınıfın örnek sayısının küme boyutuna oranıdır.
- Weka ile uygulama
  - Waikato Üniversitesi'nde Java ile geliştirilmiş açık kaynak kodlu veri madenciliği aracı. Iris veri seti üzerinde ön işleme, sınıflandırma (Naive Bayes, k-NN, J48), kümeleme (SimpleKMeans, HierarchicalClusterer) ve öz nitelik seçimi (bilgi kazancı) gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Complete linkage'ta birleştirme kuralı
  - Kümeler arası uzaklık **en uzak** iki örnekle ölçülür, ama hangi iki kümenin birleşeceğine karar verilirken yine **en küçük** uzaklık seçilir. Hoca bunu "lütfen dikkat, burada bir trik var" diye vurguladı.
- Minimum ve maksimum uzaklığın aykırı değere duyarlılığı
  - Bu iki ölçü kümelerin uç noktalarını kullandığı için gürültüye ve aykırı değerlere (outlier) duyarlıdır. Bu duyarlılıktan kaçınmak için ortalama (average) ya da merkez (mean) uzaklığı tercih edilebilir.
- Saflık hesaplaması ve etiketleme
  - Hoca kümeleme değerlendirmesinin "çok önemli" olduğunu, iyi dinlenmesi gerektiğini söyledi.
  - Bir kümede çoğunluk sınıfı başka bir kümenin etiketiyle aynıysa ve bu yüzden bir sınıf hiç temsil edilmeyecekse, hata yüksek olsa da o kümeye kaybolan sınıfın etiketi verilmelidir. Verinin doğasında bulunan bir sınıf yok sayılmamalıdır.
- Benzerlik matrisiyle çalışma
  - Kategorik (ikili) öz nitelikler varsa uzaklık matrisi yerine SMC ya da Jaccard gibi ölçülerle bir benzerlik matrisi kurulur; köşegeni 1 olur. Single linkage bu durumda en büyük benzerlik değerlerini birleştirerek uygulanır.
- Weka'da kümeleme değerlendirmesi
  - Yanlış kümelenen örnek sayısını görmek için "Classes to clusters evaluation" seçeneği işaretlenmelidir; yalnız küme boyutları bu bilgiyi vermez.
  - Hiyerarşik kümelemede iyi sonuç için linkage türü olarak average ya da mean seçilmesi önerildi.

## Kısa Tekrar Notları

- Hiyerarşik kümeleme: agglomerative (aşağıdan yukarı birleştirme, AGNES) ve divisive (yukarıdan aşağı bölme, DIANA).
- Atomik küme: tek örnekten oluşan küme. Agglomerative yöntem n atomik kümeyle başlar.
- Single linkage = minimum uzaklık; complete linkage = maksimum uzaklık; average linkage = bütün çiftlerin ortalaması; centroid = merkezler arası uzaklık.
- Ward yöntemi: birleştirme sonrası küme içi varyansı en küçük olan çifti birleştirir; işlem maliyeti yüksektir.
- Dendrogramda eşik çizgisinin kestiği dal sayısı = küme sayısı.
- Örnek uzaklık matrisi (5 örnek), eşik 5.5: single linkage → 2 küme ({S1,S3,S5}, {S2,S4}); complete linkage → 3 küme ({S3,S5}, {S2,S4}, {S1}).
- İyi kümeleme: küme içi benzerlik yüksek, kümeler arası benzerlik düşük.
- Saflık: küme başına $\frac{1}{n_i}\max_j n_{ij}$. Örnek: 5/6, 4/6, 3/5.
- Ground truth: alan uzmanının verdiği etiketler; kümelemede yalnız değerlendirme için açılır.
- KD-tree: arama uzayını bölerek uzak örneklerle uzaklık hesaplamayı gereksiz kılar; uzaklık hesabının maliyetini düşürür.
- Weka Iris: Naive Bayes (5 katlı çapraz doğrulama) 144/150 doğru (%96); k-NN (k=5) 145/150; J48 6 hata; SimpleKMeans ve average linkage hiyerarşik kümeleme 17 yanlış kümelenmiş örnek; single linkage bir sınıfı kaybetti.

## Detaylı Açıklamalar

- **Hiyerarşik kümelemenin mantığı:** k-means'te küme sayısı baştan verilir ve örnekler merkezlere atanır. Hiyerarşik kümelemede ise örnekler bir ağaç yapısında gruplanır. Agglomerative yaklaşımda her örnek başta kendi kümesindedir (5 örnekli veri setinde 5 atomik küme). Her adımda birbirine en benzer (en yakın) iki küme birleştirilir ve sonunda bütün örnekler tek kümede toplanır. Divisive yaklaşım bunun tersidir: tüm örnekler tek kümede başlar, bölme işlemleriyle atomik kümelere inilir. Bütün ağacın kurulması gerekmez; örneğin "iki küme elde edilsin" denirse işlem iki küme kaldığında durdurulur. Beş nesneli örnekte bu, adım 3'ün sonunda {a,b} ve {c,d,e} kümelerini verir (ekrandan, 00:30:00).
- **Kümeler arası uzaklık:** İki örnek arasındaki uzaklığı ölçmek kolaydır, ama kümelerin içinde birden çok örnek olduğunda iki küme arasındaki uzaklığın nasıl tanımlanacağı yöntemin kendisini belirler. Ekrandaki "Linkage methods of Clustering" slaytında single linkage için en yakın iki nokta, complete linkage için en uzak iki nokta, average linkage için bütün çiftleri birleştiren çizgiler gösterildi (ekrandan, 00:40:00). Derste bir öğrenci dördüncü ölçü olarak küme merkezlerini önerdi; bu mean distance (centroid) ölçüsüdür.
- **Çözümlü örnek: uzaklık matrisi** (ekrandan, 00:50:00 ve 01:15:00). Beş örnek için verilen simetrik uzaklık matrisi (alt üçgen):

  ```text
         S1  S2  S3  S4  S5
    S1    0
    S2    9   0
    S3    3   7   0
    S4    6   5   9   0
    S5   11  10   2   8   0
  ```

  - Single linkage (ekrandan, 01:10:00): en küçük değer 2 → {S3,S5} 2 düzeyinde birleşir. S1'in bu kümeye uzaklığı min(3, 11) = 3 → S1 3 düzeyinde katılır. Sonra d(S2,S4) = 5 → {S2,S4} 5 düzeyinde birleşir. İki küme arasındaki en küçük uzaklık d(S1,S4) = 6 → son birleşme 6 düzeyindedir.
  - Complete linkage (ekrandan, 01:20:00): ilk adım yine {S3,S5}, 2 düzeyinde. Bu kümeye uzaklıklar: S1 için max(3, 11) = 11, S4 için max(9, 8) = 9, S2 için max(7, 10) = 10. Atomik kümeler arasında d(S2,S4) = 5 en küçük olduğu için {S2,S4} 5 düzeyinde birleşir. Sonra d(S1,{S2,S4}) = max(9, 6) = 9, d(S1,{S3,S5}) = 11, d({S2,S4},{S3,S5}) = 10 → en küçüğü 9 olduğu için S1, {S2,S4} kümesine 9 düzeyinde katılır. Son birleşme d({S1,S2,S4},{S3,S5}) = 11 düzeyindedir.
  - Durma koşulu (ekrandan, 01:25:00): eşik 5.5 alınırsa complete linkage dendrogramı üç yerden kesilir ve {S3,S5}, {S2,S4}, {S1} kümeleri oluşur. Aynı eşik single linkage dendrogramını iki yerden keser: {S1,S3,S5} ve {S2,S4}.
- **Benzerlik matrisi:** Öz nitelikler ikili/kategorik ise örnekler arasında SMC (simple matching coefficient) ya da Jaccard benzerliği hesaplanarak 5×5 bir S matrisi kurulur; köşegendeki değerler 1'dir (ekrandan, 01:30:00). Single linkage bu matriste en büyük benzerlik değerleri birleştirilerek uygulanır. Bir öğrencinin önerdiği gibi benzerlikler uzaklığa dönüştürülüp aynı işlemler de yapılabilir.
- **Ward yöntemi ve küme içi varyans:** Küme içi varyans için önce kümenin ortalaması (merkezi) bulunur; örneklerin merkeze uzaklıklarının kareleri toplanıp örnek sayısına bölünür (karekökü standart sapmayı verir). Küçük varyans, örneklerin merkez etrafında derli toplu olduğunu, yani iyi bir kümeyi gösterir. Ward yöntemi her aday çift için birleşme sonrası varyansı hesaplayıp en küçüğünü seçer (ekrandan, 01:35:00). İşlem karmaşıklığı yüksektir. Büyük veride uygulanabilirliği sorulduğunda hoca KD-tree gibi arama uzayını bölen yapıların, uzak örneklerle gereksiz uzaklık hesaplarını önleyerek maliyeti düşürebileceğini söyledi.
- **Saflık örneği** (ekrandan, 01:45:00): 17 örnek üç kümeye ayrılmış. Küme I: 5 kırmızı, 1 mavi, 0 yeşil → etiket kırmızı, saflık $\frac{1}{6}\max(5,1,0)=5/6$. Küme II: 1 kırmızı, 4 mavi, 1 yeşil → etiket mavi, saflık 4/6. Küme III: 2 kırmızı, 0 mavi, 3 yeşil → etiket yeşil, saflık 3/5. Genel başarı için küme saflıklarının ortalaması alınabilir. Saflık daha önceki derslerde görülen entropiyle de ölçülebilir.
- **Kaybolan sınıf sorunu:** Küme II'de 3 kırmızı, 2 mavi, 1 yeşil olsaydı çoğunluk kuralı iki kümeyi de kırmızı yapar ve mavi sınıf hiç temsil edilmezdi. Verinin doğasında üç sınıf varsa (hocanın örneğinde tiroid hormonu az, normal ve çok olan üç grup) bu sınıf yok sayılmamalıdır. Saflık düşse de ikinci kümeye mavi etiketi verilir. Yöntem değiştirmek (k-means yerine hiyerarşik vb.) de mümkündür, ama karşılaştırma için aynı yorum gerekir.
- **Weka:** Explorer'ın Preprocess sekmesinde Iris veri seti (150 örnek, 4 öz nitelik ve sınıf; her sınıftan 50 örnek) açıldı; her öz niteliğin en küçük/en büyük değeri, ortalaması, standart sapması ve sınıflara göre histogramı görülebilir (ekrandan, 02:15:00). Petal length ve petal width sınıfları ayırmada etkilidir. Classify sekmesinde Naive Bayes, 5 katlı çapraz doğrulamayla 144 örneği doğru sınıfladı (ekrandan, 02:20:00). Cluster sekmesinde SimpleKMeans (N = 3) ile "Classes to clusters evaluation" açıkken küme boyutları 61, 50, 39 ve 17 yanlış kümelenmiş örnek çıktı (ekrandan, 02:35:00). Select attributes sekmesinde bilgi kazancına göre sıralama 3, 4, 1, 2 oldu; yalnız 3 ve 4 numaralı öz niteliklerle J48 aynı hata sayısına (6) ulaştı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
