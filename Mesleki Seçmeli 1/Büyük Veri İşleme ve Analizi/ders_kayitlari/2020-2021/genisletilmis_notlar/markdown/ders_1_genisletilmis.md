# Ders 1 Genişletilmiş Notu: Derse Giriş: Büyük Veri Madenciliği ve Dersin Kapsamı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Büyük Verinin Tanımı
- 2. Ders Kitabı: Mining of Massive Datasets
- 3. Neden Büyük Veri İşleme ve Analizi?
- 4. Veri Madenciliğinin Amacı: Örüntü ve Model Keşfi
- 5. Anlamsız Örüntüler ve Bonferroni İlkesi
- 6. Büyük Veriyle Çalışırken Neler Önemlidir?
- 7. Dersin Diğer Alanlarla İlişkisi
- 8. Derste Neler Öğrenilecek?

## 1. Dersin Amacı ve Büyük Verinin Tanımı

Bu ilk ders, ders kapsamında hangi konuların işleneceğini tanıtan bir giriş dersidir. Hoca dersin tamamen İngilizce işleneceğini söyleyerek başladı ve dersin amacını şöyle özetledi: büyük ölçekli (large-scale) veriyi nasıl saklayacağımızı, yöneteceğimizi ve işleyeceğimizi; ayrıca bu veriyi nasıl analiz edip ondan bilgi çıkaracağımızı öğreneceğiz. Bunun için büyük ölçekli veriyi analiz edebilen algoritmalar öğrenilecek.

"Büyük veri" ya da "büyük ölçekli veri" denince kastedilen, tek bir makineye sığmayan veri miktarıdır. Hoca bu tanımı ders boyunca birkaç kez tekrarladı: veri tek bir depolama birimine ya da tek bir fiziksel belleğe sığmıyorsa büyük ölçeklidir. Böyle bir veri birden fazla düğümde (node) saklanmak zorundadır; verinin parçaları birçok farklı bilgisayara dağılmış durumdadır.

Bu nedenle derste öğrenilecek algoritmalar, öğrencilerin şimdiye kadar başka derslerde gördüğü algoritmalardan farklıdır: baştan büyük ölçekli veriyi işlemek için tasarlanmışlardır. Dersin odak noktası da verinin büyük olmasından doğan problemlerdir. Üç konu öğrenilecek: bu veriyi nasıl saklarız, nasıl yönetiriz ve onu hangi büyük veri işleme algoritmalarıyla analiz ederiz.

> **Hocanın vurgusu:** "Large scale" dediğimde, tek bir depolamaya ya da tek bir fiziksel belleğe sığmayan veriden söz ettiğimizi anlamalısınız. Bu veri birçok düğüme dağılmış olarak saklanır.

## 2. Ders Kitabı: Mining of Massive Datasets

Ders bir ders kitabını sıkı biçimde izler: Leskovec, Rajaraman ve Ullman'ın "Mining of Massive Datasets" (MMDS) kitabı. Hoca kitabın her bölümünü işlemeyi, bölümleri sırayla izlemeye çalışacağını, ama akışa göre bazı bölümleri atlayıp sonra işleyebileceğini söyledi. Aynı ders Stanford Üniversitesi Bilgisayar Bilimleri bölümünde CS246 "Mining Massive Datasets" adıyla da verilmektedir.

Kitabın web sitesinde (mmds.org) kitap yayıncıyla anlaşma gereği ücretsiz indirilebilir (ekrandan, 00:20:00). Sitedeki tabloda her bölümün PDF'i, PDF ve PPT biçiminde slaytları ve yazarların video dersleri bulunur. Hoca kendi kullandığı slayt sürümünün sitedekinden farklı olabileceğini, kendi sürümünün izlenmesi gerektiğini belirtti. Sitede kitabın üçüncü baskısının Spark, TensorFlow, minhashing, topluluk bulma (community-finding), simrank, graf algoritmaları ve karar ağaçları üzerine yeni materyal içerdiği ve derin öğrenmeyi anlatan yeni bir 13. bölüm eklendiği yazar (ekrandan, 00:20:00).

Kitabın bölümleri sitedeki tabloda şöyle listelenir (ekrandan, 00:20:00 ve 00:55:00):

| Bölüm | Başlık |
|---|---|
| 1 | Data Mining |
| 2 | Map-Reduce and the New Software Stack |
| 3 | Finding Similar Items |
| 4 | Mining Data Streams |
| 5 | Link Analysis |
| 6 | Frequent Itemsets |
| 7 | Clustering |
| 8 | Advertising on the Web |
| 9 | Recommendation Systems |
| 10 | Mining Social-Network Graphs |
| 11 | Dimensionality Reduction |
| 12 | Large-Scale Machine Learning |
| 13 | Neural Nets and Deep Learning |

> **Hocanın vurgusu:** Bu derste başarılı olmak için her bölümü, ben anlatmadan önce ya da anlattıktan sonra kitaptan okumanızı şiddetle öneriyorum. Yazarların YouTube'daki video dersleri de her bölümün ne anlattığını daha iyi anlamanıza yardımcı olur.

Giriş slaytlarının kapağı "Mining of Massive Datasets: Course Introduction" başlığını taşır ve kitabın yazarlarına atıf yapar (ekrandan, 00:25:00).

## 3. Neden Büyük Veri İşleme ve Analizi?

Hoca ilk olarak farklı sektörlerdeki büyük veri örneklerini gösteren bir slaytla başladı. Öğrenciler büyük veriyle uygulamalı olarak hiç çalışmamış olsalar bile, verinin biriktiği ve büyük veri problemi yaşanabilecek sektörlerin farkındadır. Bu veri müşterilerden gelebilir ya da şirketlerin kendisi tarafından üretilebilir. Sonuçta bütün bu verinin, içinden faydalı bilgi çıkarmak için işlenmesi ve analiz edilmesi gerekir.

Veriden önemli bilgiyi çıkarmayı bilmek değerlidir, çünkü veri bilgiyi (knowledge) içinde taşır. Fakat veri çok büyükse, bu bilgiyi çıkarmanın, yani veriyi işlemenin ve analiz etmenin yollarını bilmek gerekir. Ders tam olarak bu konuya, veri büyük ölçekli olduğunda bilginin nasıl çıkarılacağına odaklanır.

Algoritmaların bir amacı vardır: veri bilimi (data science) ya da tahmine dayalı analiz. Yani bu derste büyük ölçekli veri üzerinde veri madenciliği (data mining) yapılacaktır.

### 3.1 Veri madenciliğine talep

Hoca, eski olmakla birlikte eğilimi gösteren bir grafik paylaştı ("Good news: Demand for Data Mining", ekrandan, 00:30:00). Grafik, ABD'de "derin analitik yeteneğe" (deep analytical talent) olan talebin 2018'e kadar öngörülen arzdan yüzde 50-60 daha fazla olabileceğini gösteren bir şelale grafiğidir (birim: bin kişi):

| Kalem | Değer (bin kişi) |
|---|---|
| 2008 istihdamı | 150 |
| Derin analitik yetenekli mezunlar | +180 |
| Diğerleri | +30 |
| 2018 arzı | 300 |
| Yetenek açığı (talent gap) | 140-190 |
| 2018 için öngörülen talep | 440-490 |

Açık, 2018 arzına göre yüzde 50-60 kadardır. Hoca bu resmin neden veri bilimcilere ihtiyaç olduğunu gösterdiğini söyledi: farklı sektörlerde veri biriktikçe, büyük ölçekli veriyi saklayabilen, yönetebilen ve analiz edebilen veri bilimcilere daha çok ihtiyaç duyulur. Son yıllarda bu ihtiyaç ve potansiyel yalnızca artmıştır.

## 4. Veri Madenciliğinin Amacı: Örüntü ve Model Keşfi

Derste öğrenilecek bütün algoritmalar büyük ölçekli veri üzerinde çalışır ve amaçları örüntü (pattern) ya da model keşfetmektir. Bu algoritmaların iki gereksinimi vardır:

- Çıkarılan örüntü ve modeller apaçık (obvious) olmamalıdır. Ancak büyük veriden çıkarılabilecek, kendiliğinden belli olmayan bir şey bulunmalıdır.
- Sonuçlar anlaşılabilir (understandable) olmalıdır.

### 4.1 Tanımlayıcı ve tahmine dayalı çalışma

Bu algoritmalarla iki tür çalışma yapılabilir.

**Tanımlayıcı (descriptive) çalışma:** Verinin bir fotoğrafını çekeriz ve veride hangi örüntülerin bulunduğunu anlamaya çalışırız. Tipik örneği kümeleme (clustering) analizidir: büyük ölçekli verinin fotoğrafını çeker, kümeleme algoritmaları uygularız. Ancak burada yalnız büyük ölçekli veride çalışabilen kümeleme algoritmaları ele alınacaktır. Öğrenciler veri madenciliği, bilgi erişimi ya da makine öğrenmesi derslerinde kümeleme algoritmaları görmüş olabilir; bu derste odak, kümeleme algoritmalarının büyük veride nasıl ölçeklendiğidir.

**Tahmine dayalı (predictive) çalışma:** Bu kez mevcut durumun fotoğrafını çekmek yerine veriden öğrenir ve geleceği tahmin ederiz. Veriden bir model ya da örüntü oluşturulur ve bu model durumun gelecekteki değerini tahmin etmek için kullanılır. Örnek olarak öneri sistemleri (recommender systems) verildi: geçmiş veriden çıkarılan bilgiye dayanarak son kullanıcılara bazı ürünler önerilebilir.

<!-- BELİRSİZ: 00:34:30 civarında tahmine dayalı analize ikinci bir örnek verilmiş olabilir; altyazıda bu kısım bozuk. -->

## 5. Anlamsız Örüntüler ve Bonferroni İlkesi

Büyük ölçekli veriyi analiz ettiğimizde, bulduğumuz örüntülerin bir kısmı anlamsız çıkabilir. Bunun nedeni verinin kendiliğinden (otomatik olarak) üretilmesidir; veride anlam taşımayan, mantıklı olmayan örüntüler bulunabilir. Bu yüzden derste algoritmaların sonuçlarını da analiz etmeyi öğreneceğiz.

Slayt bu riski şöyle anlatır (ekrandan, 00:35:00): Veri madenciliğinde bir risk, analistin aslında anlamsız olan örüntüleri "keşfetmesi"dir. İstatistikçiler buna **Bonferroni ilkesi** der: kabaca, verinizin destekleyebileceğinden daha fazla yerde ilginç örüntü ararsanız, mutlaka işe yaramaz sonuçlar bulursunuz. Slaytta bunu anlatan bir karikatür de vardır: veriyi yeterince zorlarsanız "Tanrı'dan mesajlar" bile bulabilirsiniz.

### 5.1 Otel örneği

Hoca bu tür büyük veri problemlerine güzel bir örnek verdi. Birbiriyle ilgisi olmayan, ama geçmişte en az iki kez aynı gün aynı otelde kalmış iki kişiyi bulmak istiyoruz. Bakılan dönem son 1000 gündür.

Varsayımlar:

- Takip edilecek kişi sayısı $10^9$'dur.
- Geriye doğru 1000 güne bakılır.
- Her kişi 100 günden birinde otelde kalır (olasılık $0{,}01$).
- Her otel 100 kişi alır; bu durumda otel sayısı $10^9 \cdot 0{,}01 / 100 = 10^5$ olur.

Hoca kişi çiftlerinin olası kombinasyon sayısının çok yüksek olduğunu, sonuçta yaklaşık 250.000 kişi çiftinin "şüpheli" çıktığını söyledi. Bu tür problemler, derste öğrenilecek algoritmaların odaklandığı problemlerdir.

<!-- BELİRSİZ: Otel örneğinin slaytı karelerde görünmüyor; varsayımlar altyazıdan alındı, ara hesap ders kitabındaki örneğe göre kuruldu. -->

> **Ders sonrası not:** Hoca 250.000'i "şüpheli olup olmadıklarını kontrol etmeniz gereken çift sayısı" gibi ifade etti. Kitaptaki hesapta 250.000, insanlar tamamen rastgele davransa bile şüpheli görünecek çiftlerin beklenen sayısıdır. Bu sayı, gerçek "kötü niyetli" çiftlerin bu kadar çok rastlantısal çift arasında kaybolacağını, yani Bonferroni ilkesini gösterir. Hesap aşağıdaki Örnek Sorular bölümündedir.

## 6. Büyük Veriyle Çalışırken Neler Önemlidir?

Hoca "What matters when dealing with data?" slaytını üç eksenli bir diyagramla anlattı (ekrandan, 00:40:00). Diyagramın eksenleri ve üzerindeki öğeler şunlardır:

| Eksen | Öğeler |
|---|---|
| Veri işlemleri (Data Operators) | Collect, Prepare, Represent, Model, Reason, Visualize |
| Veri türleri (Data Modalities) | Ontologies, Structured, Networks, Text, Multimedia, Signals |
| Zorluklar (Challenges) | Scalability, Streaming, Context, Quality, Usage |

### 6.1 Veri işlemleri

Büyük ölçekli veriyle uğraşırken farklı problemler vardır: büyük ölçekli veriyi nasıl toplayacağımız (collect), nasıl ön işleyeceğimiz (prepare), makine öğrenmesine hazır olacak biçimde nasıl temsil edeceğimiz (represent), makine öğrenmesi ya da derin öğrenme teknikleriyle nasıl model oluşturacağımız (model), bu modele dayanarak nasıl çıkarım yapacağımız (reason) ve çıkarımı herkesin anlayabileceği biçimde nasıl görselleştireceğimiz (visualize).

### 6.2 Veri türleri

Büyük ölçekli veri farklı biçimlerde gelebilir: yapısal (structured) biçimde, örneğin ilişkisel bir veritabanında; ontolojiler ya da anlamsal web (semantic web) verisi olarak; ağ verisi, metin verisi, çoklu ortam (multimedia) verisi ya da işlenmesi gereken sinyal verisi olarak. Sonuçta bu farklı türleri, büyük veri işleme çatılarının uygulanabileceği bir türe çeviren filtreler ya da dönüştürücüler kullanılabilir.

Hoca bu noktada derste Hadoop, HDFS ve Spark gibi büyük veri işleme çatılarının (framework) kullanılacağını ve öğrenileceğini belirtti. Bu çatılar, verinin birden fazla düğüme dağıldığı durumda büyük ölçekli veriyi işleyebilen kütüphanelerdir. Bu kütüphanelerle nasıl kod yazılacağı ve büyük ölçekli verinin nasıl işleneceği de öğrenilecek.

### 6.3 Zorluklar

Büyük ölçekli veriyi işleyen bir uygulama geliştirirken karşılaşılan zorluklar:

- **Ölçeklenebilirlik (scalability):** Tek bir düğümden çok sayıda düğüme geçince ne olur?
- **Akış (streaming):** Veri toplu işlenen (batch) veri olabilir, yani bütün veri tek bir yerde durur. Ya da akış verisi olabilir, yani veri uygulamaya akış halinde gelir.
- **Bağlam (context):** Verinin bağlamı.
- **Kalite (quality):** Verinin kalitesi, içinde anomaliler ya da anormal değerler bulunup bulunmadığı.
- **Kullanım (usage):** Verinin nasıl kullanılacağı.

## 7. Dersin Diğer Alanlarla İlişkisi

Hoca dersin, veriyle uğraşan diğer alanlar arasında nerede durduğunu açıkladı.

- **Veritabanları:** Veritabanları alanında da büyük ölçekli veri problemi vardır; veritabanı ilişkisel ya da NoSQL olabilir. Ancak burada yapılan iş, sorgulara uyan sonuçları getiren basit sorgulardır.
- **Makine öğrenmesi:** Öğrencilerin şimdiye kadar aldığı makine öğrenmesi derslerinde veri genelde azdı ve tek bir makineye sığıyordu. Buna karşılık veriden çıkarılan modeller genelde karmaşıktır: rastgele orman (random forest), destek vektör makinesi (support vector machine) ya da Naive Bayes gibi. Bu modeller karmaşıktır ama hepsi küçük veri üzerinde çalışır.
- **Teori:** Kuramsal olarak büyük ölçekli veri üzerinde çalışabilen algoritmalar da vardır.

Büyük ölçekli veri madenciliği bu alanların kavramlarını kullanır. Daha önce makine öğrenmesi, veritabanı sistemleri ya da algoritma dersleri alanlar, bu alanlardan algoritma ve kavramların kullanıldığını göreceklerdir. Kısacası bu derste kullanılacak büyük veri madenciliği istatistikten, makine öğrenmesinden ve veritabanı sistemlerinden teknikler alır; öğrenilecek bütün algoritmalar bu teknikleri büyük ölçekli veriyi işleyecek biçimde kullanır.

> **Ek bilgi (derste anlatılmadı):** MMDS kitabının giriş bölümünde de veri madenciliği büyük olasılıkla istatistik, makine öğrenmesi ve veritabanı sistemlerinin kesişiminde gösterilir; kitabın vurgusu, algoritmaların büyük veriye ölçeklenmesidir.

## 8. Derste Neler Öğrenilecek?

"What will we learn?" slaytı dersin kapsamını iki başlıkta toplar (ekrandan, 00:45:00):

- Farklı veri türlerinde madencilik yapmak:
  - Yüksek boyutlu veri (high dimensional)
  - Graf verisi (data is a graph)
  - Sonsuz/bitmeyen veri (infinite/never-ending)
  - Etiketli veri (labeled)
- Farklı hesaplama modellerini kullanmak:
  - MapReduce
  - Akışlar ve çevrim içi (online) algoritmalar
  - Tek makinede bellek içi (single machine in-memory) işleme

Hoca MapReduce programlama modelinin, birden fazla makineye dağılmış büyük ölçekli veriyi işlemeyi sağladığını; ayrıca büyük ölçekli verinin tek bir makine kullanılarak bile nasıl işlenebileceğinin öğrenileceğini söyledi.

Bu teknikler gerçek dünya problemlerini çözmek için kullanılacak:

- **Öneri sistemleri:** Öneri sistemlerinin nasıl çalıştığı.
- **Pazar sepeti analizi (market basket):** Bu kez veri tek bir makinenin depolamasına sığmayan büyük ölçekli veri olarak ele alınacak. Birliktelik kuralına (association rule) dayalı uygulamalar da buraya girer.
- **Kopya (benzer) belge tespiti:** Örneğin intihal etkinliğini yakalamak için birbirine benzeyen belgeleri bulan bir yazılımın nasıl yapılacağı.

Hoca konuları veri türlerine göre de özetledi. Yüksek boyutlu veride kümeleme ve özetleme (hashing) ele alınacak. Graf verisinde büyük ölçekli verinin nasıl sıralanacağı (ranking) ve zaman kalırsa spam tespiti işlenecek. Sonsuz veride, yani akış verisinde, akış üzerinde sorgu yapma ve gelen veri akışlarını filtreleme öğrenilecek. Ayrıca büyük ölçekli veriye uygulanabilen farklı makine öğrenmesi yaklaşımları ve bir makine öğrenmesi algoritmasının büyük veriye uygulandığında nasıl farklılaştığı incelenecek. Kitabın web sitesindeki bölümler, bu girişte özetlenen kavramların her biri için ayrı bir bölüm içerir.

## Örnek Sorular

### Soru 1: Otel örneği ve Bonferroni ilkesi

(derste sözlü, 00:35:42)

Birbiriyle ilgisiz, ama son 1000 gün içinde en az iki kez aynı gün aynı otelde kalmış kişi çiftleri aranıyor. $10^9$ kişi vardır; her kişi 100 günden birinde otelde kalır; her otel 100 kişi alır. İnsanlar tamamen rastgele davranırsa, kaç çift "şüpheli" görünür?

Derste verilen sonuç: yaklaşık 250.000 çift.

> **Çözüm (derste verilmedi):** Otel sayısı $10^9 \cdot 0{,}01 / 100 = 10^5$. Belirli iki kişinin belirli bir gün otelde olma olasılığı $0{,}01 \cdot 0{,}01 = 10^{-4}$; aynı otelde olma olasılığı $10^{-4} / 10^5 = 10^{-9}$. Belirli iki günde bunun olma olasılığı $(10^{-9})^2 = 10^{-18}$. Kişi çifti sayısı $\binom{10^9}{2} \approx 5 \cdot 10^{17}$, gün çifti sayısı $\binom{1000}{2} \approx 5 \cdot 10^{5}$. Beklenen şüpheli çift sayısı $5 \cdot 10^{17} \cdot 5 \cdot 10^{5} \cdot 10^{-18} = 2{,}5 \cdot 10^{5}$, yani yaklaşık 250.000 (python ile doğrulandı: 249.750). Gerçekten kötü niyetli birkaç çift bu kadar çok rastlantısal çift arasında ayırt edilemez; Bonferroni ilkesinin anlattığı tam olarak budur.

## Dersin Toparlaması

Bu giriş dersinde büyük verinin, tek bir makinenin depolamasına ya da belleğine sığmayan ve bu yüzden birçok düğüme dağıtılan veri olduğu, dersin de bu verinin saklanması, yönetilmesi ve analiz edilmesine odaklandığı anlatıldı. Ders Mining of Massive Datasets kitabını izler. Amaç büyük veriden apaçık olmayan ve anlaşılabilir örüntüler çıkarmaktır; bu tanımlayıcı (kümeleme gibi) ya da tahmine dayalı (öneri sistemleri gibi) olabilir. Bonferroni ilkesi ve otel örneği, büyük veride rastlantısal ve anlamsız örüntü bulma tehlikesini gösterdi.

Büyük veriyle çalışma veri işlemleri, veri türleri ve zorluklar (ölçeklenebilirlik, akış, bağlam, kalite, kullanım) eksenlerinde düşünülür. Ders istatistik, makine öğrenmesi ve veritabanı tekniklerini büyük veriye ölçekler; yüksek boyutlu, graf, akış ve etiketli verilerle MapReduce, akış algoritmaları ve bellek içi hesaplama modellerini kullanarak öneri sistemleri, pazar sepeti analizi ve kopya belge tespiti gibi problemleri ele alacaktır. Uygulamada Hadoop, HDFS ve Spark gibi çatılar kullanılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
