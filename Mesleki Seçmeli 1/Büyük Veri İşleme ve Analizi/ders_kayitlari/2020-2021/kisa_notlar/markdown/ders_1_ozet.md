# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin amacı ve "büyük veri" tanımı
  - Ders, büyük ölçekli (large-scale) verinin nasıl saklanacağını, yönetileceğini, işleneceğini ve analiz edileceğini öğretir.
  - Büyük veri: tek bir makinenin diskine ya da fiziksel belleğine sığmayan veridir. Bu yüzden parçalara bölünüp birden fazla düğüme (node) dağıtılarak saklanır.
  - Derste öğrenilecek algoritmalar, önceki derslerde görülen algoritmalardan farklıdır; çünkü baştan büyük veriyi işlemek için tasarlanmıştır.
- Ders kitabı ve kaynaklar
  - Ders "Mining of Massive Datasets" (MMDS; Leskovec, Rajaraman, Ullman) kitabını bölüm bölüm izler (ekrandan, 00:20:00).
  - Kitabın web sitesinde (mmds.org) her bölümün PDF'i, slaytları (PDF ve PPT) ve yazarların video dersleri vardır. Aynı içerik Stanford'da CS246 "Mining Massive Datasets" dersi olarak okutulur.
  - Kitabın bölümleri (ekrandan, 00:55:00): 1 Data Mining, 2 Map-Reduce and the New Software Stack, 3 Finding Similar Items, 4 Mining Data Streams, 5 Link Analysis, 6 Frequent Itemsets, 7 Clustering, 8 Advertising on the Web, 9 Recommendation Systems, 10 Mining Social-Network Graphs, 11 Dimensionality Reduction, 12 Large-Scale Machine Learning, 13 Neural Nets and Deep Learning.
- Neden büyük veri işleme öğrenmeliyiz?
  - Pek çok sektörde veri birikir; veri müşterilerden gelebilir ya da şirketin kendisi üretebilir.
  - Veriden faydalı bilgi (knowledge) çıkarmak değerlidir; ama veri çok büyükse bu bilgiyi çıkarmanın yolunu bilmek gerekir.
  - Veri bilimciye (data scientist) talep yıllar içinde artmıştır (ekrandan, 00:30:00; aşağıda ayrıntı).
- Veri madenciliğinin amacı: örüntü ve model keşfi
  - Büyük veriden örüntü (pattern) ya da model çıkarılır.
  - Çıkarılan örüntü apaçık (obvious) olmamalı, yalnız büyük veriden çıkarılabilecek bir şey olmalıdır.
  - Sonuçlar anlaşılabilir (understandable) olmalıdır.
- Tanımlayıcı (descriptive) ve tahmine dayalı (predictive) analiz
  - Tanımlayıcı analiz: verinin "fotoğrafını çeker", veride hangi örüntülerin olduğunu anlamaya çalışır. Örnek: kümeleme (clustering) analizi; ama yalnız büyük veride ölçeklenebilen kümeleme algoritmaları.
  - Tahmine dayalı analiz: veriden öğrenip model ya da örüntü kurar, bunu geleceği tahmin etmek için kullanır. Örnek: öneri sistemleri (recommender systems).
- Anlamsız örüntüler ve Bonferroni ilkesi
  - Büyük veride bulunan örüntülerin bir kısmı anlamsız çıkabilir; bu yüzden algoritma sonuçlarının da analiz edilmesi gerekir.
  - Bonferroni ilkesi (ekrandan, 00:35:00): Verinin destekleyebileceğinden daha çok yerde ilginç örüntü ararsanız, rastlantısal ve anlamsız örüntü bulmanız kaçınılmazdır.
  - Otel örneği: Son 1000 gün içinde en az iki kez aynı gün aynı otelde kalmış, birbiriyle ilgisiz iki kişi aranıyor. $10^9$ kişi, kişi başına 100 günde bir otelde kalma, otel başına 100 kişi, yani $10^5$ otel. Tamamen rastgele davranışta bile yaklaşık 250.000 "şüpheli" çift çıkar.
- Büyük veriyle çalışırken önemli olanlar (ekrandan, 00:40:00)
  - Veri işlemleri (data operators): toplama (collect), hazırlama (prepare), temsil etme (represent), modelleme (model), çıkarım/gerekçe (reason), görselleştirme (visualize).
  - Veri türleri (data modalities): ontolojiler, yapısal (structured, ilişkisel veritabanı), ağ (network), metin, çoklu ortam (multimedia), sinyal.
  - Zorluklar (challenges): ölçeklenebilirlik (scalability), akış (streaming), bağlam (context), kalite (quality), kullanım (usage).
- Büyük veri işleme çatıları
  - Derste Hadoop, HDFS ve Spark gibi, birden fazla düğüme dağılmış veriyi işleyen kütüphaneler kullanılacak.
- Dersin diğer alanlarla ilişkisi
  - Veritabanları (ilişkisel ya da NoSQL): büyük veri vardır ama sorgular basittir.
  - Makine öğrenmesi: genelde tek makineye sığan küçük veri ve karmaşık modeller (rastgele orman, destek vektör makinesi, Naive Bayes).
  - Büyük veri madenciliği istatistik, makine öğrenmesi ve veritabanı sistemlerinin tekniklerini birleştirir; odak, bu teknikleri büyük veriye ölçeklemektir.
- Derste öğrenilecekler (ekrandan, 00:45:00)
  - Farklı veri türleri: yüksek boyutlu veri, graf verisi, sonsuz/bitmeyen (akış) veri, etiketli veri.
  - Farklı hesaplama modelleri: MapReduce, akışlar ve çevrim içi (online) algoritmalar, tek makinede bellek içi (single machine in-memory) işleme.
  - Konular: yüksek boyutlu veride kümeleme ve özetleme (hashing), graf verisinde sıralama (ranking) ve spam tespiti, akış verisinde sorgulama ve filtreleme, büyük ölçekli makine öğrenmesi.
  - Uygulamalar: öneri sistemleri, pazar sepeti (market basket) analizi ve birliktelik kuralları, benzer/kopya belge tespiti (intihal yakalama).

## Hocanın Özellikle Vurguladığı Kısımlar

- Büyük verinin ölçütü tek makineye sığmamasıdır
  - Hoca "large scale" dediğinde, tek bir depolamaya ya da tek bir fiziksel belleğe sığmayan veriyi kastettiğini birkaç kez tekrarladı. Bu yüzden derslerin tüm problemleri, verinin birçok bilgisayara dağılmış olmasından doğan problemlerdir.
- Kitap sıkı biçimde izlenecek
  - Başarılı olmak için her bölümün dersten önce ya da sonra kitaptan okunması önerildi. Yazarların video dersleri de konuyu anlamaya yardımcıdır. Hocanın kullandığı slayt sürümü sitedekinden farklı olabilir.
- Algoritmanın amacı veri bilimi / tahmine dayalı analizdir
  - Öğrenilecek algoritmalar, büyük veri üzerinde veri madenciliği yapmak içindir. Kümeleme gibi tanıdık yöntemler, "büyük veride nasıl ölçeklenir" sorusuyla ele alınacak.
- Bulunan örüntülerin anlamlı olup olmadığı sorgulanmalı
  - Veri kendiliğinden (otomatik) üretildiği için anlamsız örüntüler de çıkar; sonuçları değerlendirmeyi öğrenmek de dersin parçasıdır.
- Soru sormanın önemi
  - Çevrim içi derste hoca öğrencinin anlayıp anlamadığını göremediği için anlaşılmayan yerin hemen sorulmasını istedi.

## Kısa Tekrar Notları

- Büyük veri = tek makinenin diskine/belleğine sığmayan veri; parçaları birçok düğüme dağılır.
- Ders kitabı: Mining of Massive Datasets (mmds.org); Stanford CS246 ile aynı içerik.
- Örüntü: apaçık olmamalı, anlaşılabilir olmalı.
- Tanımlayıcı analiz: verinin fotoğrafı (örnek: kümeleme).
- Tahmine dayalı analiz: modelle geleceği tahmin (örnek: öneri sistemleri).
- Bonferroni ilkesi: çok yerde ararsan rastlantısal "örüntü" bulursun.
- Otel örneğinde rastgele davranışla bile yaklaşık 250.000 şüpheli çift çıkar.
- Üç eksen: veri işlemleri (collect → visualize), veri türleri (structured, text, signals...), zorluklar (scalability, streaming, context, quality, usage).
- Çatılar: Hadoop, HDFS, Spark.
- Hesaplama modelleri: MapReduce, akış/çevrim içi algoritmalar, tek makinede bellek içi.
- Veri türleri: yüksek boyutlu, graf, sonsuz (akış), etiketli.
- Uygulamalar: öneri sistemleri, pazar sepeti, kopya belge tespiti.

## Detaylı Açıklamalar

Bu ilk ders, dersin kapsamını tanıtan bir giriş dersidir. Dersin merkezindeki kavram "büyük ölçekli veri"dir. Hoca bu kavramı nicelik üzerinden tanımlar: veri, tek bir bilgisayarın depolama birimine ya da fiziksel belleğine sığmıyorsa büyük veridir. Böyle bir veri parçalara bölünür ve parçalar birçok farklı bilgisayara (düğüme) dağıtılır. Bu durum, alışılmış algoritmaların doğrudan kullanılamamasına yol açar. Dersin bütün algoritmaları bu dağınıklığı hesaba katarak, büyük veriyi işlemek için tasarlanmıştır. Odak, algoritmanın kendisinden çok verinin büyüklüğünden doğan problemlerdir.

Ders "Mining of Massive Datasets" kitabını izler. Kitabın sitesinde her bölümün PDF'i, PDF ve PPT slaytları ve yazarların bölüm bölüm video dersleri bulunur (ekrandan, 00:20:00). Kitabın üçüncü baskısı Spark, TensorFlow, minhashing, topluluk bulma, simrank, graf algoritmaları ve karar ağaçları üzerine yeni materyal ile derin öğrenmeyi anlatan 13. bölümü içerir (ekrandan, 00:20:00). Hoca bölümleri sırayla izlemeyi, akışa göre bazı bölümleri sonraya bırakabileceğini söyledi.

Veri bilimine olan talebi anlatan slaytta (ekrandan, 00:30:00) ABD'de "derin analitik yeteneğe" talep için bir şelale grafiği vardır: 2008 istihdamı 150 bin kişi, derin analitik yetenekli mezunlar +180 bin, diğerleri +30 bin, 2018 arzı 300 bin; 2018 için öngörülen talep 440-490 bin; aradaki yetenek açığı 140-190 bin, yani 2018 arzına göre %50-60 açık. Hoca bu resmin eski olduğunu, ama eğilimin, yani veri bilimciye olan ihtiyacın son yıllarda yalnızca arttığını vurguladı.

Büyük veriden çıkarılacak örüntü ve modellerin iki niteliği olmalıdır: apaçık olmamalı (yalnızca büyük veriden çıkarılabilecek bir şey olmalı) ve anlaşılabilir olmalı. Analiz iki türlüdür. Tanımlayıcı analiz mevcut durumun bir fotoğrafını çeker; kümeleme bunun tipik örneğidir. Tahmine dayalı analiz ise veriden bir model ya da örüntü öğrenip geleceği tahmin eder; öneri sistemleri bunun örneğidir.

Büyük veride bir tehlike, anlamsız örüntülerin "keşfedilmesidir". İstatistikte buna Bonferroni ilkesi denir: verinin destekleyebileceğinden daha fazla yerde ilginç örüntü ararsanız, kaçınılmaz olarak anlamsız sonuçlar bulursunuz (ekrandan, 00:35:00). Hocanın anlattığı otel örneğinde, son 1000 günde en az iki kez aynı gün aynı otelde kalmış iki ilgisiz kişi aranır. $10^9$ kişi vardır, her kişi 100 günden birinde otelde kalır, her otel 100 kişi alır; bu da $10^9 \cdot 0{,}01 / 100 = 10^5$ otel demektir. Kişi çifti ve gün çifti sayısı çok büyük olduğundan, insanlar tamamen rastgele davransa bile yaklaşık 250.000 çift "şüpheli" görünür.

- Ders sonrası not: Hoca 250.000'i "kontrol etmeniz gereken çift sayısı" gibi söyledi. Kitaptaki hesapta 250.000, rastgele davranışta bile şüpheli görünecek çiftlerin beklenen sayısıdır: iki kişinin belirli bir gün aynı otelde olma olasılığı $0{,}01^2/10^5 = 10^{-9}$, belirli iki günde bunun olma olasılığı $10^{-18}$, kişi çifti sayısı yaklaşık $5\cdot10^{17}$, gün çifti sayısı yaklaşık $5\cdot10^{5}$; çarpım yaklaşık $2{,}5\cdot10^{5}$ (python ile doğrulandı). <!-- BELİRSİZ: Otel örneği slaytı karelerde görünmüyor; sayılar altyazıdan ve kitaptaki örnekten alındı. -->

Büyük veriyle çalışmanın üç ekseni bir slaytta gösterilir (ekrandan, 00:40:00). Veri işlemleri ekseni veri toplama, hazırlama, temsil etme (makine öğrenmesine hazır hale getirme), modelleme, model üzerinden çıkarım ve herkesin anlayacağı biçimde görselleştirmeyi içerir. Veri türleri ekseni ontolojiler, yapısal veri, ağ verisi, metin, çoklu ortam ve sinyallerden oluşur; farklı türler filtre ya da dönüştürücülerle büyük veri çatılarının işleyebileceği biçime çevrilir. Zorluklar ekseninde ölçeklenebilirlik (tek düğümden çok düğüme geçince ne olur), akış (verinin toplu (batch) değil akış halinde gelmesi), verinin bağlamı, kalitesi (anomaliler) ve kullanımı bulunur. Derste Hadoop, HDFS ve Spark gibi çatılar da öğrenilecek.

Büyük veri madenciliği istatistik, makine öğrenmesi ve veritabanı sistemlerinin tekniklerinden yararlanır. Veritabanlarında da büyük veri vardır ama sorgular basittir. Makine öğrenmesi derslerinde ise veri genelde tek makineye sığar, modeller (rastgele orman, destek vektör makinesi, Naive Bayes) karmaşıktır. Bu dersin farkı, bu tekniklerin büyük veriye nasıl ölçekleneceğidir. Derste yüksek boyutlu, graf, sonsuz (akış) ve etiketli veri türleri; MapReduce, akış/çevrim içi algoritmalar ve tek makinede bellek içi hesaplama modelleri öğrenilecektir (ekrandan, 00:45:00). Uygulama olarak öneri sistemleri, pazar sepeti analizi (birliktelik kuralları) ve benzer/kopya belge tespiti işlenecektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
