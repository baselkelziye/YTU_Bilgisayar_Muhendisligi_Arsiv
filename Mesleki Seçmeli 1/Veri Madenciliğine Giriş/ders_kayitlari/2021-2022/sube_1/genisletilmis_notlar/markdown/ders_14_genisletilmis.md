# Ders 14 Genişletilmiş Notu: Birliktelik Kuralları: Apriori, Kompakt Gösterim ve FP-Growth

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

> **Kayıt hakkında:** Ders çevrim içi yapıldı. Kayıt iki parçadan oluşur ve parçalar dersin gerçek sırasıyladır; yaklaşık 01:01 ile 01:16 arasında ara verilmiştir. Yaklaşık 00:06:35 ile 00:11:20 arasında ses kesilmiştir; bu aralıkta anlatılan kısım kayıtta yoktur. Slaytlar İngilizcedir ("Association Rule Mining").

## İçindekiler

- 1. Sık Örüntüler ve Birliktelik Kuralları
- 2. Veri Gösterimi ve Temel Tanımlar
- 3. Birliktelik Kuralı, Destek ve Güven
- 4. Kural Madenciliğinin Maliyeti
- 5. Sık Öğe Kümesi Üretme Stratejileri
- 6. Apriori İlkesi ve Apriori Algoritması
- 7. Aday Üretme ve Hash Ağacı
- 8. Apriori'nin Karmaşıklığını Etkileyen Etkenler
- 9. Çoklu Minimum Destek
- 10. Sık Öğe Kümelerinden Kural Üretme
- 11. Sık Öğe Kümelerinin Kompakt Gösterimi
- 12. FP-Growth Algoritması
- 13. Birliktelik Örüntülerinin Değerlendirilmesi: Lift ve Interest
- 14. Genel Değerlendirme

## 1. Sık Örüntüler ve Birliktelik Kuralları

Bu derste yeni bir konuya, birliktelik kurallarına (association rules) geçildi. Hoca, bu konunun eskiden çok popüler olduğunu, bugün ise diğer konular kadar yoğun kullanılmadığını söyledi. Bugün elimizde sosyal medya verisi, büyük metin verileri gibi çok farklı veri türleri vardır; ama veri madenciliği ilk ortaya çıktığında en temel uygulamalarından biri birliktelik kuralı madenciliğiydi (association rule mining). Bunun en klasik örneği market sepeti analizidir (market basket analysis): bir alışveriş sepetinde birlikte alınan ürünleri bulmak.

Derste sırasıyla şunlar işlendi: birliktelik kuralları nasıl tanımlanır ve bulunur; bunun temelini oluşturan iki tanım olan destek (support) ve güven (confidence); en temel algoritma olan Apriori (eski ama hâlâ sık kullanılan bir algoritma); ve kısaca FP-Growth algoritması.

### 1.1 Sık örüntü nedir

Sık örüntü (frequent pattern), bir veri kümesinde sık görülen bir örüntüdür. Slayttaki tanıma göre bu örüntü bir öğe kümesi, bir alt dizi ya da bir alt yapı olabilir (ekrandan, 00:05:00). Yani veri kümesindeki birimlerin (öğelerin) bir kümesi olabileceği gibi, bunlardan oluşmuş bir yapı da olabilir.

Slaytta üç tür sık örüntü ayrıldı:

- **Sık öğe kümesi (frequent itemset):** Süt ve ekmek gibi, bir işlem (transaction) veri kümesinde sık sık birlikte görünen öğeler. Alışveriş kayıtları incelendiğinde süt ve ekmek çoğu zaman birlikte alınmışsa {süt, ekmek} bir sık öğe kümesidir.
- **Sık sıralı örüntü (frequent sequential pattern):** Örneğin önce bir bilgisayar, sonra bir dijital kamera, sonra bir hafıza kartı almak. Bir alışveriş geçmişi veritabanında bu sıra sık tekrarlanıyorsa bir sık sıralı örüntüdür. Hoca bunu sık öğe kümesinin bir alt türü gibi düşünülebileceğini söyledi; burada sıra önemlidir.
- **Sık yapısal örüntü (frequent structured pattern):** Alt graf, alt ağaç ya da alt kafes (sublattice) gibi yapısal biçimler. Hoca bunu şöyle örnekledi: biri bir ürün aldı; bunu alanların bir kısmı bir ürünü, bir kısmı başka bir ürünü aldı. Bu ilişkiler ağaç ya da graf biçiminde tutulursa ("bunu alanların %70'i şunu da aldı" gibi) ve böyle bir yapı sık görülüyorsa ona sık yapısal örüntü denir.

<!-- BELİRSİZ: Yaklaşık 00:06:35 ile 00:11:20 arasında ses yoktur; hoca sesin gelmediğini fark edip baştan özetledi. Bu aralıkta anlatılan ek bir konu varsa kayıtta bulunmuyor. -->

### 1.2 Market sepeti analizi neden yapılır

Sık örüntüler en çok market sepeti analizinde kullanılır: insanların alışveriş sepetinde sık sık birlikte aldıkları şeyler bulunur. Hoca bunun neden önemli olduğunu pazarlama ile açıkladı: reklam kampanyaları, rafların dizilimi gibi kararlar bu bilgiye göre verilir.

## 2. Veri Gösterimi ve Temel Tanımlar

### 2.1 İşlemler nasıl tutulur

Hoca önce şunu sordu: birinci müşteri A, B, C ürünlerini, ikinci müşteri başka ürünleri aldıysa bu veriyi nasıl bir veri yapısında tutarsınız? İlk akla gelen liste olarak tutmaktır. Ama listede arama yaparken her şeye tek tek bakmak gerekir; liste çok büyüdüğünde arama çok zaman alır.

Bu yüzden bu tür veriler genellikle bir matris olarak tutulur. Sütunlarda ürünler (A, B, C, D, ...), satırlarda her müşterinin yaptığı alışveriş vardır. Her satır bir işlemdir (transaction). Müşterinin aldığı ürün 1, almadığı ürün 0 olarak yazılır. Böylece her işlem bir Boolean vektörüdür. Birlikte alınan şeyler bu Boolean vektörlerinden bulunur ve bulunan örüntülere birliktelik kuralları denir.

### 2.2 Öğe kümesi ve destek

Slayttaki örnek veri kümesi şudur (ekrandan, 00:15:00):

| Tid | Alınan öğeler |
|---|---|
| 10 | Beer, Nuts, Diaper |
| 20 | Beer, Coffee, Diaper |
| 30 | Beer, Diaper, Eggs |
| 40 | Nuts, Eggs, Milk |
| 50 | Nuts, Coffee, Diaper, Eggs, Milk |

Slayttaki Venn şemasında bira alanlar, bebek bezi alanlar ve kesişimde ikisini birden alanlar gösteriliyordu. Hoca burada şuna dikkat çekti: amaç hangi ürünlerin birlikte satıldığını bulmaktır, ama yalnız iki ürün yoktur. Kaç farklı ürün varsa o kadar küme vardır; bu yüzden birlikte alınanları bulmak göründüğü kadar kolay değildir.

Tanımlar:

- **Öğe (item):** Nuts, Eggs, Milk gibi her bir ürün.
- **Öğe kümesi (itemset):** Bir ya da daha fazla öğeden oluşan küme. $k$ öğeli öğe kümesine $k$-öğe kümesi denir: $X = \{x_1, \ldots, x_k\}$. Her işlem de bir öğe kümesidir.
- **Mutlak destek (absolute support):** $X$ öğe kümesinin sıklığı, yani $X$'in geçtiği işlem sayısı. Örneğin $\{Beer\}$, 10, 20 ve 30 numaralı işlemlerde vardır, 40 ve 50'de yoktur; mutlak desteği 3'tür. Öğe kümesi birden çok ürün içeriyorsa hepsinin birlikte geçtiği işlemler sayılır.
- **Göreli destek (relative support):** $X$'i içeren işlemlerin oranı, yani bir işlemin $X$'i içerme olasılığı. Mutlak destek toplam işlem sayısına bölünür. Örnekte 5 işlem olduğundan $\{Beer\}$'in göreli desteği $3/5$'tir. Bu sayede destek, veri kümesinin büyüklüğüne göre ifade edilmiş olur.

Hoca birkaç sayım daha yaptı: Milk 40 ve 50 numaralı işlemlerde geçer, desteği 2'dir. {Eggs, Milk} de 40 ve 50 numaralı işlemlerde birlikte geçer, desteği yine 2'dir.

### 2.3 Sık öğe kümesi ve minimum destek

Amaç sık öğe kümelerini bulmaktır. Bir şeyin sık olup olmadığına karar vermek için bir eşik (threshold) belirlenir. Bu eşiği algoritma kendisi seçmez; kullanıcı elle belirler. Buna minimum destek (minsup) denir. Slayttaki tanım: $X$'in desteği minsup eşiğinden küçük değilse $X$ sıktır (ekrandan, 00:15:00). Örneğin eşik 3 seçilirse desteği 3 ve üstü olan kümeler sık sayılır. Yani "sıklık" tamamen kullanıcının seçtiği parametreye bağlıdır.

Özetle: $n$ öğe varsa bunlardan birli, ikili, üçlü, ..., $n$'li kümeler oluşturulabilir; bunlara öğe kümesi denir. Mutlak destek bir öğe kümesinin kaç kez geçtiğidir, göreli destek bunun bütün işlemlere oranıdır. Hangi kümelerin sık sayılacağı minsup'a bağlıdır.

## 3. Birliktelik Kuralı, Destek ve Güven

### 3.1 Birliktelik kuralı

Birliktelik kuralı $X \rightarrow Y$ biçiminde bir çıkarımdır (implication); burada $X$ ve $Y$ öğe kümeleridir (ekrandan, 00:20:00). Hoca bunun karar ağaçlarındaki kurallara biraz benzediğini söyledi. Örneğin "A ve B ürünlerini aldıysa C'yi de almıştır" ya da "A, B, C ürünlerini aldıysa D ve H'yi de almıştır" birer birliktelik kuralıdır.

Birliktelik kuralı madenciliği, verilen bir işlem veri kümesinde minimum destek ve minimum güveni sağlayan bütün $X \rightarrow Y$ kurallarını bulmaktır. Yani hangi öğe kümelerinin birlikte alındığı aranır. Minimum destek, kullanıcının koyduğu sıklık sınırıdır: hangi değerin üstüne "sık" denileceğini belirler. Minimum güveni tanımlamak için önce güvenin ne olduğunu tanımlamak gerekir.

### 3.2 Destek ve güvenin tanımı

Slayttaki tanımlar (ekrandan, 00:20:00):

- **Destek (support):** Bir işlemin $X \cup Y$'yi içerme olasılığı, $P(X \cup Y)$. Yani hem $X$'i hem $Y$'yi içeren işlemlerin oranı.
- **Güven (confidence):** $X$'i içeren bir işlemin $Y$'yi de içerme koşullu olasılığı:

$$P(Y|X) = \frac{\text{support}(X \cup Y)}{\text{support}(X)}$$

Güven, $Y$'deki öğelerin $X$'i içeren işlemlerde ne sıklıkla göründüğünü ölçer. Hoca bunu şöyle açıkladı: $X$ ve $Y$'nin birlikte geçtiği işlemler, $X$'in geçtiği bütün işlemlere bölünür; yani $X$ alanların ne kadarı $Y$'yi de almış, buna bakılır. Bu değer en fazla 1 olabilir.

> **Hocanın vurgusu:** Bundan sonra hep destek ve güvenden söz edilecek. Destek, $X$ ve $Y$'nin birlikte kaç kez geçtiğidir; güven, $X$ alındığında $Y$'nin de onunla birlikte kaç kez göründüğüdür.

### 3.3 Bira ve bebek bezi örneği

Aynı beş işlemli veri kümesi üzerinde minsup = %50 ve minconf = %50 alınmıştır (ekrandan, 00:25:00).

Önce tekli sayımlar yapılır. Beer 3 işlemde geçer, desteği 3'tür. Nuts 3 işlemde (10, 40, 50) geçer. Diaper 4 işlemde (10, 20, 30, 50) geçer. Eggs 3 işlemde geçer. Sık örüntülerde illa tek ürün olması gerekmez: {Beer, Diaper} birlikte 10, 20 ve 30 numaralı işlemlerde geçer, desteği 3'tür. Slayttaki sık örüntüler:

$$\{Beer\}:3,\ \{Nuts\}:3,\ \{Diaper\}:4,\ \{Eggs\}:3,\ \{Beer, Diaper\}:3$$

Bu kümeden iki kural çıkar:

- **$Beer \rightarrow Diaper$ (%60, %100):** Bira alan 3 işlem vardır. Bunların kaçında bebek bezi de var? 10'da var, 20'de var, 30'da var; üçünde de var. Güven $3/3 = \%100$'dür.
- **$Diaper \rightarrow Beer$ (%60, %75):** Bebek bezi alan 4 işlem vardır. Bunlardan 3'ünde bira da var; 50 numaralı işlemde bebek bezi var ama bira yok. Güven $3/4 = \%75$'tir.

Hoca $3/4$'ün nereden geldiğini harflerle de gösterdi: bebek bezine D, biraya B denirse pay, veri kümesinde D ve B'nin birlikte geçtiği işlem sayısı (3), payda ise B'ye hiç bakmadan yalnız D'nin geçtiği işlem sayısıdır (4).

İki kuralın desteği aynıdır: ikisinin birlikte geçtiği 3 işlem, toplam 5 işleme bölünür; $3/5 = \%60$.

Özetle: destek, $X$ ve $Y$'nin birlikte geçtiği işlem sayısının bütün işlemlere oranıdır; güven, birlikte geçtikleri işlem sayısının yalnız $X$'in geçtiği işlem sayısına oranıdır.

### 3.4 Destek ve güven neden kullanılır

Destek ve güven kullanılmazsa "bu ürün şununla birlikte alınmış" denebilecek çok fazla kural çıkar. Desteği çok düşük bir kuralın genellikle anlamı yoktur: nadiren birlikte alınan ürünler pek bir şey söylemez. Destek ve güveni yüksek kurallar ilgi çekicidir, çünkü genel alım eğilimi o yöndedir ve pazarlama işlemleri de çoğunluğa göre yapılır. Güven ne kadar yüksekse, $X$ alındığında $Y$'nin de alınma olasılığı o kadar yüksektir.

> **Hocanın vurgusu:** Bütün bunlar eşiklere göre yapıldığı için eşiklerin iyi belirlenmesi gerekir. Ayrıca çıkan kurallar dikkatle incelenmelidir: bir ürün gerçekten diğeriyle birlikte mi alınıyor, yoksa tesadüf mü, buna bakılmalıdır.

## 4. Kural Madenciliğinin Maliyeti

### 4.1 Kaba kuvvet yaklaşımı

Elimizde $N$ işlem var ve iki eşik belirlendi: minimum destek ve minimum güven. Amaç, desteği minimum destekten, güveni minimum güvenden büyük olan kuralları bulmaktır. Bunu kaba kuvvetle (brute force) yapmaya çalışırsak, $d$ ürün için bütün birli, ikili, üçlü, dörtlü, ... kombinasyonlara bakmak gerekir. Gerçek bir markette çok fazla ürün olduğu düşünülürse bu hesaplama açısından imkansızdır; "bütün ihtimallere bakayım, en yükseğini alayım" diyen bir algoritma bilgisayarda çok uzun süre çalışır ve cevap bulamaz. Daha akıllı algoritmalar tasarlamak gerekir.

**Soru:** Kaba kuvvetten daha iyi çalışacak bir yöntem aklınıza geliyor mu? **Cevap:** Sınıftan cevap gelmedi; hoca slayttaki gözlemin ipucu verdiğini söyleyerek devam etti.

### 4.2 Aynı öğe kümesinden çıkan kurallar

Slayttaki beş işlemli yeni örnek (ekrandan, 00:30:00):

| TID | Öğeler |
|---|---|
| 1 | Bread, Milk |
| 2 | Bread, Diaper, Beer, Eggs |
| 3 | Milk, Diaper, Beer, Coke |
| 4 | Bread, Milk, Diaper, Beer |
| 5 | Bread, Milk, Diaper, Coke |

Hoca önce beş ürün dedi, sonra düzeltti: altı ürün vardır. Bu veriden çıkarılmış örnek kurallar:

| Kural | Destek | Güven |
|---|---|---|
| $\{Milk, Diaper\} \rightarrow \{Beer\}$ | 0,4 | 0,67 |
| $\{Milk, Beer\} \rightarrow \{Diaper\}$ | 0,4 | 1,0 |
| $\{Diaper, Beer\} \rightarrow \{Milk\}$ | 0,4 | 0,67 |
| $\{Beer\} \rightarrow \{Milk, Diaper\}$ | 0,4 | 0,67 |
| $\{Diaper\} \rightarrow \{Milk, Beer\}$ | 0,4 | 0,5 |
| $\{Milk\} \rightarrow \{Diaper, Beer\}$ | 0,4 | 0,5 |

Bütün kurallarda aynı üç ürün vardır: hepsi $\{Milk, Diaper, Beer\}$ kümesinin ikiye bölünmüş hâlleridir. Bu yüzden destekleri aynıdır: üçünün birlikte geçtiği 2 işlem (3 ve 4) vardır, $2/5 = 0{,}4$. Güvenleri ise farklıdır, çünkü payda soldaki kümenin desteğine göre değişir.

Slayttaki gözlem: aynı öğe kümesinden çıkan kuralların desteği aynı, güveni farklı olabilir; bu yüzden destek ve güven koşulları birbirinden ayrılabilir (decouple). Buna göre birliktelik kuralı bulmak iki adıma bölünür:

- Önce desteği minimum destekten büyük olan bütün öğe kümeleri, yani sık öğe kümeleri bulunur.
- Sonra bu sık öğe kümelerinden birliktelik kuralları üretilir.

### 4.3 Altı işlemli örnek

Hoca iki adımlı yaklaşımı bile hâlâ pahalı bulduktan sonra şu örneği çözdü (ekrandan, 00:35:00). İşlemler: ABD, ABCD, A, ABC, BC, B. minsup = 0,5, minconf = 0,7.

Önce tekli öğeler: toplam 6 işlem vardır.

- $support(\{A\}) = 4/6$
- $support(\{B\}) = 5/6$ (B beş işlemde geçer)
- $support(\{C\}) = 3/6$
- $support(\{D\}) = 2/6$ (yalnız ABD ve ABCD'de)

D'nin desteği 0,5'ten büyük olmadığı için D slayttaki sık öğe kümeleri listesine yazılmamıştır. Bundan sonra yalnız desteği eşiği geçenlerle devam edilir. Çünkü D tek başına eşiği geçemiyorsa içinde D olan hiçbir öğe kümesi de 0,5'i geçemez.

Sonra bunlar birleştirilerek ikililere bakılır:

- $support(\{A,B\}) = 3/6$: eşiği geçer.
- $support(\{B,C\}) = 3/6$: eşiği geçer.
- $\{A,C\}$ yalnız ABCD ve ABC'de geçer, desteği $2/6$'dır; silinir.

Hoca üçlü $\{A,B,C\}$'ye de bakılması gerektiğini söyledi.

<!-- BELİRSİZ: Hoca {A,B,C} üçlüsüne de bakılması gerektiğini söyledi ama değerini söylemedi; slaytta da üçlü yok. -->

Kurallar:

- $conf(A \rightarrow B) = 3/4$: A'nın geçtiği 4 işlemin 3'ünde B de var; 0,7'nin üstündedir.
- $conf(C \rightarrow B) = 3/3$: C'nin geçtiği 3 işlemin hepsinde B var.

Hoca bu örnekte dikkat edilmesi gereken şeyin arama uzayının küçültülmesi olduğunu söyledi: aşağıdan yukarı, önce tek tek öğeler alınır, sonra birleştirilerek gidilir; alt seviyede minimum koşulu sağlamayan bir öğeye hiç bakılmadan devam edilir. Bütün olasılıkları yazıp saymak yerine yinelemeli (iteratif) bir yöntemle ilerlenir.

**Soru (hocanın sorusu, sohbet penceresinden):** Buraya kadar anlaşılmayan bir yer var mı? **Cevap:** Bir öğrenci konunun kolay olduğunu ve anlaşıldığını yazdı.

### 4.4 Öğe kümesi kafesi ve alt küme sayısı

Öğe kümesi üretiminde boş kümeyle başlanır; sonra bir elemanlı, iki elemanlı, üç elemanlı, dört elemanlı ve beş elemanlı alt kümeler gelir. Bu yapıya öğe kümesi kafesi (lattice) denir.

**Soru:** $n$ elemanlı bir kümenin kaç alt kümesi vardır? **Cevap:** $2^n$. Beş öğe varsa $2^5 = 32$ alt küme vardır.

Kaba kuvvette bu 32 alt kümenin hepsi oluşturulur, her birinin desteği ve güveni hesaplanır ve hangisinin olup olmadığına karar verilir. Bu, gerçek veride mümkün değildir.

### 4.5 Kaba kuvvetin karmaşıklığı

Slayttaki kaba kuvvet yaklaşımı (ekrandan, 01:55:00):

- Kafesteki her öğe kümesi bir aday (candidate) sık öğe kümesidir.
- Her adayın desteği veritabanı taranarak sayılır.
- Her işlem her adayla eşleştirilir.
- Karmaşıklık yaklaşık $O(NMw)$'dir ve $M = 2^d$ olduğu için pahalıdır.

Burada $M$ aday sayısıdır; $d$ öğe varsa $M = 2^d$'dir. $N$ işlem sayısıdır: her aday için bütün işlemlere bakılıp aday o işlemin içinde mi diye sayılmalıdır. $w$ ise işlemin genişliğidir: bir adayın bir işlemde olup olmadığını anlamak için işlemin içine tek tek bakmak gerekir. Toplam iş, işlem sayısı çarpı işlem genişliği çarpı aday sayısıdır ve $d$'ye göre üstel büyür. Bu yüzden kaba kuvvetle çözmek mümkün değildir.

Slayttaki grafik, toplam öğe sayısı $d$ arttıkça olası kural sayısının nasıl hızla arttığını gösteriyordu. Hoca, yalnız 6 ürün için bile 602 kural olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** $d$ öğeli bir veri kümesinden çıkabilecek toplam kural sayısı büyük olasılıkla slayttaki $R = 3^d - 2^{d+1} + 1$ formülüyle verilir. $d = 6$ için $729 - 128 + 1 = 602$ eder; bu, hocanın söylediği sayıyla uyuşur (python ile kontrol edildi).

## 5. Sık Öğe Kümesi Üretme Stratejileri

Kaba kuvvet yapılamadığı için slaytta üç strateji sıralandı (ekrandan, 00:40:00):

- **Aday sayısını ($M$) azaltmak:** Tam aramada $M = 2^d$'dir. Budama (pruning) teknikleriyle $M$ azaltılır. Apriori ilkesi, bazı aday öğe kümelerini destek değerlerini saymadan elemenin etkili bir yoludur.
- **Karşılaştırma sayısını ($NM$) azaltmak:** Adayları ya da işlemleri tutmak için verimli veri yapıları kullanılır; böylece her adayı her işlemle eşleştirmeye gerek kalmaz. Hoca burada hash gibi bir yapının kullanılabileceğini söyledi.
- **İşlem sayısını ($N$) azaltmak:** Slaytta "öğe kümesinin boyu arttıkça $N$'i küçült" yazıyordu. Hoca bazı durumlarda işlem sayısının da azaltılabileceğini, örneğin belirli tarihler arasındaki işlemlerin elenebileceğini söyledi.

Budamanın mantığı şudur: önce bir elemanlılara bakılır. Bir elemanlı bir kümenin desteği eşiğin altında kalıyorsa, onun sonraki aşamalarına bakmaya gerek yoktur. Örneğin A ürünü minimum koşulu sağlamadıysa A ile B, A ile C, A ile D de sağlayamaz; çünkü A zaten az sayıdadır. Bu yüzden onlara hiç bakılmaz.

## 6. Apriori İlkesi ve Apriori Algoritması

### 6.1 Apriori ilkesi

Apriori algoritması bu konunun en temel algoritmasıdır. Dayandığı ilke şudur: bir öğe kümesi sıksa, onun bütün alt kümeleri de sık olmak zorundadır. Örneğin A, B, C öğelerinden oluşan bir küme sıksa A, B ve C de sık olmak zorundadır.

Bu, az önceki gözlemin tersten söylenişidir. Az önce "A eşiği sağlamıyorsa içinde A olan başka bir küme de sağlamaz" denmişti. Hoca bunu bir kafes şekliyle gösterdi: A, B, C, D, E ürünlerinin hepsi eşiği geçsin; ama {A, B} eşiği geçmesin. O zaman içinde A ve B bulunan bütün olasılıklar atılır ve bunlara hiç bakılmaz. Çünkü {A, B} sık değilse onu içeren hiçbir küme sık olamaz.

> **Hocanın vurgusu:** Apriori ilkesi şudur: bir öğe kümesi seyrekse (infrequent), onun üst kümeleri (supersets) de seyrektir; bu yüzden onlara bakmaya gerek yoktur. Apriori algoritması bunu temel alır ve hoca bunu "gayet mantıklı" bir algoritma olarak niteledi.

### 6.2 Apriori ilkesinin örnekle gösterimi

Slayttaki örnek, 4. bölümdeki beş işlemli Bread-Milk veri kümesi üzerindedir; minimum destek 3'tür (ekrandan, 00:45:00).

**1. adım, birli öğe kümeleri.** Her öğenin kaç işlemde geçtiği sayılır:

| Öğe | Sayı |
|---|---|
| Bread | 4 |
| Coke | 2 |
| Milk | 4 |
| Beer | 3 |
| Diaper | 4 |
| Eggs | 1 |

Eşik 3 olduğundan 3'ten küçük olanlar elenir: Coke (2) ve Eggs (1). Bundan sonra oluşturulacak ikili, üçlü öğe kümelerinde Coke ve Eggs yer almaz.

**2. adım, ikili öğe kümeleri.** Kalan Bread, Milk, Beer, Diaper öğelerinden ikililer oluşturulur ve her birinin kaç işlemde birlikte geçtiği sayılır:

| Öğe kümesi | Sayı |
|---|---|
| {Bread, Milk} | 3 |
| {Beer, Bread} | 2 |
| {Bread, Diaper} | 3 |
| {Beer, Milk} | 2 |
| {Diaper, Milk} | 3 |
| {Beer, Diaper} | 3 |

Eşik 3 olduğundan {Beer, Bread} ve {Beer, Milk} elenir. Elde dört küme kalır: {Bread, Milk}, {Bread, Diaper}, {Diaper, Milk}, {Beer, Diaper}.

**3. adım, üçlü öğe kümeleri.** Üçlüler kalan dört ikiliden oluşturulur ve destekleri sayılır. Hoca sayımların 2, 2, 2, 1 çıktığını söyledi. Hepsi 3'ten küçüktür; eşiğin ötesine geçen bir küme kalmadığı için algoritma durdurulur.

Python ile kontrol: {Beer, Bread, Diaper} = 2, {Beer, Diaper, Milk} = 2, {Bread, Diaper, Milk} = 2, {Beer, Bread, Milk} = 1. Bu sayılar hocanın söylediği 2, 2, 2, 1 ile uyuşur.

Slaytın sol altındaki kutu kazancı gösteriyordu:

- Bütün alt kümeler düşünülseydi: $\binom{6}{1} + \binom{6}{2} + \binom{6}{3} = 6 + 15 + 20 = 41$ aday.
- Destek tabanlı budamayla: $6 + 6 + 4 = 16$ aday.

Hoca burada önemli bir noktaya dikkat çekti: şu ana kadar güven hiç kullanılmadı. Bu ilk aşamada yalnız sık öğe kümeleri, yani en sık birlikte geçen öğe kümeleri bulundu. Henüz "şunu aldıysa bunu da almıştır" gibi bir kural çıkarılmadı.

### 6.3 Apriori algoritması

Algoritmanın gösterimi şöyledir: $F_k$, sık $k$-öğe kümeleridir ($k$ bir, iki, üç elemanlı olabilir); $L_k$ ise aday listeleridir. Algoritma şöyle çalışır:

```text
k = 1
Sık 1-öğe kümelerini (F1) bul
F_k boş olana kadar tekrarla:
    Aday üretme   : F_k'dan (k+1)-öğe aday kümelerini (L_k+1) üret
    Aday budama   : seyrek alt kümesi olan adayları at
    Destek sayma  : veritabanını tarayıp her adayın desteğini say
    Aday eleme    : desteği eşiğin altında kalanları at; kalanlar F_k+1 olur
    k = k + 1
```

Yani yukarıdaki örnekte yapılanın aynısıdır: önce birliler oluşturulur, eşiğe bakılır, geçmeyenler elenir; sonra ikililer oluşturulur, yine desteklerine bakılır ve elenir. Algoritma, sık $k$-öğe kümeleri boş kalana kadar çalışır. Örnekte son adımda hiçbir üçlünün sayısı 3 olmadığı için $F_k$ boş kaldı ve algoritma durdu.

> **Ders sonrası not:** Hoca algoritmayı özetlerken bir yerde ikili listelerin "confidence'larına" bakıldığını söyledi; doğrusu bu aşamada desteklerine bakılır. Güven yalnız kural üretme aşamasında kullanılır; hoca da birkaç dakika önce bunu vurgulamıştı.

## 7. Aday Üretme ve Hash Ağacı

### 7.1 $F_{k-1} \times F_{k-1}$ yöntemi

Adaylar nasıl oluşturulur? İkili örnekte {Bread, Milk} ile {Bread, Diaper} birleştirilebilir, çünkü Bread ortaktır; birleşince {Bread, Milk, Diaper} adayı çıkar. Hoca küme oldukları için bu birleştirmelerin aynı kümeye gidebileceğini de belirtti: {Bread, Diaper} ile {Milk, Diaper}'ın birleşimi de yine {Bread, Milk, Diaper}'dır.

Slayttaki kural şudur (ekrandan, 00:50:00): iki sık $(k-1)$-öğe kümesi, ilk $(k-2)$ öğeleri aynıysa birleştirilir. Yani üçlüleri birleştirip dörtlü üretirken ilk iki öğeye (ön eke, prefix) bakılır; ikilileri birleştirip üçlü üretirken ilk öğeye bakılır.

Slayttaki örnek:

$$F_3 = \{ABC, ABD, ABE, ACD, BCD, BDE, CDE\}$$

- Merge(ABC, ABD) = ABCD
- Merge(ABC, ABE) = ABCE
- Merge(ABD, ABE) = ABDE
- ABD ile ACD birleştirilmez, çünkü yalnız 1 uzunluğunda ön ek paylaşırlar; 2 uzunluğunda ön ek gerekir.

Üretilen aday 4-öğe kümeleri: $L_4 = \{ABCD, ABCE, ABDE\}$.

Aday budamada da eşiği sağlamayanlar silinir. Birinci yöntem (budama) aday sayısını azaltıyordu; ikinci yöntemin amacı karşılaştırma sayısını azaltmaktır.

### 7.2 Karşılaştırma sayısını azaltma: hash ağacı

Her aday için "bu işlemde var mı, şu işlemde var mı" diye her seferinde bütün işlemlere bakılıyor. Bu işlemler farklı bir veri yapısında tutulursa daha hızlı bakılabilir. Bunun için adaylar bir hash yapısında tutulur; her işlemi her adayla karşılaştırmak yerine hash'te tutulan şeylerle karşılaştırılır.

Slayttaki örnekte dört işlemli bir veritabanı vardı; birinci taramada (scan) eşiğin altında kalan öğe belirlenip atılıyor, sonra ikinci tarama yapılıyordu.

Hash ağacının yapısı:

- Yapraklarda öğe kümeleri ve kaç kez geçtikleri (sayaçları) tutulur.
- İç düğümlerde hash tablosu vardır.
- Alt küme fonksiyonu (subset function), bir işlemin içinde bulunan adayları bulur.

Örnekte $t$ işlemi {1, 2, 3, 5, 6}'dır. Birinci seviyede işlem 1 + {2, 3, 5, 6}, 2 + {3, 5, 6}, 3 + {5, 6} biçiminde ayrılır. Sonra örneğin 1 2 alındığında 1 2 3, 1 2 5, 1 2 6 gibi alt kümeler elde edilir. Bir kümenin (örneğin 3 5 6) olup olmadığı arandığında ağaçta hangi dala gidileceği bilinir; veri yapısı aramayı hızlandırır.

> **Hocanın vurgusu:** Konu veri yapıları olmadığı için hash ağacının ayrıntısına girilmedi; nasıl bir yapı olduğunu bilmek yeterlidir.

## 8. Apriori'nin Karmaşıklığını Etkileyen Etkenler

Hoca Apriori'nin sıkıntılarını sıraladı. Slayttaki etkenler (ekrandan, 00:55:00):

- **Minimum destek eşiğinin seçimi:** Eşiği düşürmek daha çok sık öğe kümesi demektir; bu da aday sayısını ve sık öğe kümelerinin en büyük boyunu artırabilir.
- **Veri kümesinin boyutu (öğe sayısı):** Her öğenin destek sayacını tutmak için daha çok yer gerekir. Gerçek bir market veri kümesinde binlerce ürün vardır; bu da bellekle ilgili sorun çıkarır. Sık öğe sayısı da artarsa hem hesaplama hem G/Ç (I/O) maliyeti artabilir.
- **Veritabanı büyüklüğü:** Apriori veriyi birçok kez taradığı için çalışma süresi işlem sayısıyla artabilir.
- **Ortalama işlem genişliği:** Yoğun veri kümelerinde işlem genişliği artar. Bir kişi ne kadar çok ürünü birlikte aldıysa algoritma o kadar yavaşlar, çünkü arama her işlemde bu genişliğe göre yapılır. Bu, sık öğe kümelerinin en büyük boyunu da artırabilir; bir işlemin alt küme sayısı genişliğiyle artar.

### 8.1 Parametrelerin etkisi

Hoca sonra destek eşiğinin ve işlem genişliğinin etkisini gösteren grafiklere geçti. Grafikte yatay eksende öğe kümesi boyu, eğrilerde farklı destek değerleri vardı.

<!-- BELİRSİZ: Grafiklerin eksen değerleri ve eğri etiketleri karelerde yok; hocanın andığı destek değerleri (binde 1, binde 2, binde 5 gibi) altyazıdan tam çıkmıyor. -->

Hocanın anlattığı gözlemler şunlardır:

- Destek eşiği çok büyükken öğe kümesi boyu arttıkça kümeler hemen elenir; 5 boyuna gelmeden sayı sıfırlanır, yani 5 öğeli tek bir sık küme bile bulunamaz.
- Destek eşiği küçüldükçe (örneğin binde 1 gibi) başta çok sayıda küme çıkar; sonra sayı azalır, tekrar artar ve sonunda yine sıfırlanır. 20 öğenin birçok kişi tarafından aynı anda alınması pek olası değildir.
- Sık öğe kümelerinin sayısı da destekle birlikte artar ve azalır. Bu yüzden destek eşiği ile birlikte hem aday sayısının hem de sık öğe kümesi sayısının nasıl değiştiğine bakılmalıdır.
- İşlem genişliği grafiğinde de genişlik arttıkça bir yerden sonra sayılar sıfırlanır; genişlik çok küçük tutulursa öğe kümeleri erken sıfırlanır, çok yüksek tutulursa artar; zikzaklı durumlar da çıkabilir.

> **Hocanın vurgusu:** Bu algoritma parametreye çok bağımlıdır. Bu grafikleri mutlaka çizip bakmak gerekir; tek bir parametre seçip "benim kurallarım bunlar" demek insanı çok yanlış yerlere götürür.

## 9. Çoklu Minimum Destek

**Soru:** Algoritma parametreye bu kadar bağlıysa eşiği nasıl bulacağız? **Cevap:** Minimum destek çok yüksek tutulursa önemli öğe kümeleri elenebilir; çok düşük tutulursa ilgili ilgisiz birçok öğe kümesi eklenir. Bu yüzden tek bir destek eşiği yerine çoklu minimum destek (multiple minimum support) kullanılması önerilmiştir.

Hoca bunu, optimizasyon algoritmalarında olduğu gibi, eşiğin sabit kalmayıp duruma göre değişmesi olarak anlattı: öğe kümesindeki öğe sayısı $i$ azken bir eşik, ikililerde başka bir eşik kullanılır; destek $i$'ye bağlı, dinamik bir parametre olur. Bu, daha anlamlı şeyler bulmayı sağlar; ama böyle iki parametre ya da $i$'ye bağlı bir destek parametresi ayarlamak da kolay değildir, yine deneyerek en uygun noktayı bulmak gerekir.

<!-- BELİRSİZ: Hocanın bu kısımda söylediği sayısal eşik değerleri (0,9, binde 1, binde 5 gibi) altyazıda karışık; slayttaki örnek aşağıdadır. -->

Slayttaki örnek (ekrandan, 01:00:00): öğeler minimum desteklerine göre artan sırada dizilir.

- MS(Milk) = %5, MS(Coke) = %3, MS(Broccoli) = %0,1, MS(Salmon) = %0,5
- Sıralama: Broccoli, Salmon, Coke, Milk

Apriori şöyle değiştirilir:

- $L_1$: sık öğelerin kümesi.
- $F_1$: desteği $MS(1)$'den büyük ya da eşit olan öğelerin kümesi; burada $MS(1) = \min_i MS(i)$'dir.
- $C_2$: 2 boyutlu aday öğe kümeleri $L_1$ yerine $F_1$'den üretilir.

Hoca ayrıntılı gösterime takılmamayı, mantığını anlamanın yeterli olduğunu söyledi. Ardından ara verildi.

## 10. Sık Öğe Kümelerinden Kural Üretme

Aradan sonra hoca kısa bir tekrar yaptı: Apriori'nin nasıl çalıştığı görüldü; desteklerde sorun olabileceği ve yinelemeli algoritmanın her adımında (birli, ikili, üçlü kümeler) farklı destekler kullanılarak bunun çözülebileceği söylendi. Apriori ile sık öğe kümelerini bulmayı öğrendik; şimdi bunlardan "bunu aldıysa şunu da almıştır" biçimindeki kuralların nasıl oluşturulacağına bakılır.

### 10.1 Aday kurallar

Slayttaki tanım (ekrandan, 01:05:00): sık bir $L$ öğe kümesi verildiğinde, boş olmayan her $f \subset L$ alt kümesi için $f \rightarrow L - f$ aday kuralı kurulur ve minimum güven koşulunu sağlayıp sağlamadığına bakılır.

Örneğin $\{A, B, C, D\}$ sık bir öğe kümesiyse, yani eşiği geçmiş ve bu öğeler birlikte alınmışsa, aday kurallar şunlardır:

| | | | |
|---|---|---|---|
| ABC → D | ABD → C | ACD → B | BCD → A |
| D → ABC | C → ABD | B → ACD | A → BCD |
| AB → CD | AC → BD | AD → BC | |
| CD → AB | BD → AC | BC → AD | |

ABC alındıysa D mi alınmış, ABD alındıysa C mi alınmış; ikili olarak AB alındıysa CD mi alınmış? Bu dörtlüyü kural olarak yazmanın birçok yolu vardır. Kümede $k$ eleman varsa $2^k - 2$ aday kural vardır; boş küme ($L \rightarrow \emptyset$) ve bütün elemanları içeren durum ($\emptyset \rightarrow L$) sayılmaz. Bu örnekte $2^4 - 2 = 14$ kural vardır. Yine birçok şeye bakmak gerekir; hepsine bakmak şart mı, daha verimli yapılabilir mi?

### 10.2 Güvenin anti-monoton özelliği

**Soru:** $ABC \rightarrow D$ kuralının güveni, $AB \rightarrow D$ kuralının güveninden büyük müdür? **Cevap:** Hayır; ama daha küçüktür de denemez. Genel olarak güven anti-monoton değildir: $c(ABC \rightarrow D)$, $c(AB \rightarrow D)$'den büyük de küçük de olabilir (ekrandan, 01:20:00). Bu yüzden C'yi eklemenin etkisini ayrıca değerlendirmek gerekir; Apriori'de öğe sayısını artırarak yapılan budama burada doğrudan uygulanamaz.

Ama aynı öğe kümesinden üretilen kuralların güveni anti-monotondur. $\{A, B, C, D\}$ sık bir 4-öğe kümesi olsun:

$$c(ABC \rightarrow D) \ge c(AB \rightarrow CD) \ge c(A \rightarrow BCD)$$

Neden? Üç kuralda da pay aynıdır: dördünün birlikte geçtiği işlem sayısı. Payda ise sol tarafın desteğidir. Sol taraf küçüldükçe (ABC'den AB'ye, AB'den A'ya) desteği büyür ya da aynı kalır; hoca bunu "A'yı B'den bağımsız kılıyorum" diye anlattı: yalnız A'ya bakıldığında, A'yı içeren işlem sayısı, A ve B'yi birlikte içerenlerin sayısından az olamaz. Payda büyüdüğü için güven küçülür. Slayttaki ifadeyle güven, kuralın sağ tarafındaki öğe sayısına göre anti-monotondur.

(ara adım eklendi) Biçimsel olarak: $c(X \rightarrow L - X) = s(L)/s(X)$ ve $X' \subset X$ ise $s(X') \ge s(X)$ olduğundan $c(X' \rightarrow L - X') \le c(X \rightarrow L - X)$.

### 10.3 Kurallarda budama

Bu özellik budama için kullanılır. Sol tarafında en çok eleman bulunan kural (örneğin $BCD \rightarrow A$) minimum güven eşiğini geçmiyorsa, ondan türeyen ve sağ tarafı daha büyük olan kuralların (örneğin $CD \rightarrow AB$, $BD \rightarrow AC$) eşiği geçme ihtimali yoktur.

Yöntem şöyledir: $n$ elemanlı bir küme için önce sol tarafta $n-1$ eleman, sağ tarafta bir eleman olan kurallar yazılır ve güvenleri hesaplanır. Güveni eşiği geçmeyen kurallar, bütün alt çocuklarıyla birlikte budanır. Böylece $2^k$ mertebesindeki değerlendirme sayısı azaltılır.

## 11. Sık Öğe Kümelerinin Kompakt Gösterimi

Bu bölüm bir algoritma değil, sık öğe kümelerinin nasıl gösterileceğiyle ilgilidir.

Bir işlem verisinden çıkan sık öğe kümelerinin sayısı çok fazla olabilir ve aralarında tekrarlar olur. Bu tekrarlar en çok üst kümelerden kaynaklanır: bir üst küme eşiği geçtiyse onun bütün alt kümeleri de geçmiştir. Birbirini tekrar eden çok sayıda kuralı göstermemek için daha kompakt, sıkıştırılmış bir gösterime ihtiyaç vardır. Bunun için iki kavram tanımlanır: maksimal sık öğe kümesi ve kapalı sık öğe kümesi.

### 11.1 Maksimal sık öğe kümesi

Slayttaki tanım (ekrandan, 01:25:00): maksimal sık öğe kümesi (maximal frequent itemset), hiçbir doğrudan üst kümesi (immediate superset) sık olmayan sık öğe kümesidir.

- Maksimal sık öğe kümeleri, sık öğe kümelerinin etkili bir kompakt gösterimini sağlar.
- Bütün sık öğe kümelerinin türetilebildiği en küçük öğe kümeleri topluluğunu oluştururlar.

Hoca bunu slayta yazdığı bir örnekle anlattı (ekrandan, 01:25:00):

- ABCDEFG: eşiği aşmadı.
- ABCDE: sık; BCDE'nin üst kümesi.
- BCDE: sık.
- DE: sık.

DE maksimal sık öğe kümesi midir? Hayır, çünkü bir üst kümesi (BCDE) de sık öğe kümesidir. BCDE maksimal midir? Hayır, çünkü onun üst kümesi olan ABCDE de sıktır. ABCDE'nin üst kümesi ABCDEFG ise eşiği aşamamıştır; hoca ABCDE'nin diğer üst kümelerinin de eşiği aşamadığını varsaydı. Bu durumda maksimal sık öğe kümesi ABCDE'dir. Yani maksimal kümenin kendisi ve bütün alt kümeleri eşiği geçer, ama kendisi bu özellikteki en kapsamlı (en çok elemanlı) kümedir.

Ardından slayttaki kafes örneğine geçildi. Kafeste A, B, C, D, E öğeleri ve ikilileri gibi içi gri olmayan düğümlerin hepsi sıktır. Örneğin AD'nin üst kümeleri olan, içinde AD bulunan üçlüler (örneğin ABD, ACD) eşiği geçememiştir; bu yüzden AD maksimal sık öğe kümesidir. ACE'nin üst kümeleri (ABCE, ACDE) de eşiği geçememiştir; ACE de maksimaldir. Aynı şekilde BCDE de maksimal sık öğe kümesidir. Böylece B, C, D, BC gibi kümelerin hepsini tek tek göstermek yerine kurallar AD, ACE ve BCDE üzerinden gösterilebilir.

<!-- BELİRSİZ: Hoca kafes örneğinde "ABE" demeye başlayıp düzeltti; AD'nin üst kümelerinin tam listesi altyazıdan kesin çıkmıyor. Maksimal kümeler {a,c,e}, {a,d}, {b,c,d,e} olarak 01:30:00 karesindeki slaytta da geçiyor. -->

### 11.2 Neden daha kapsamlı kurallar

Hoca bunun neden yapıldığını bir karşılaştırmayla açıkladı. Kural üretildiğinde "AB ise C vardır" ile "ABD ise C vardır" gibi kurallar çıkabilir. Kurallar üretildiğinde bunlardan çok sayıda olur; daha kapsamlı kurallara bakmak daha mantıklıdır, çünkü onlar daha çok şey söyler. Amaç, çok sayıda kural göstermek yerine daha az ama daha çok şey söyleyen kurallar bulmaktır.

### 11.3 Maksimal kümelerin eksiği

Slayttaki açıklama (ekrandan, 01:30:00):

- Maksimal sık öğe kümeleri kompakt bir gösterim sağlasa da alt kümelerinin destek bilgisini içermez.
- Örneğin maksimal sık öğe kümeleri $\{a, c, e\}$, $\{a, d\}$ ve $\{b, c, d, e\}$'nin destekleri, alt kümelerinin desteği hakkında hiçbir ipucu vermez.
- Bu yüzden maksimal olmayan sık öğe kümelerinin destek sayılarını bulmak için veri kümesi üzerinden bir tarama daha gerekir.
- Destek bilgisini koruyan küçük bir gösterim istenebilir: kapalı sık öğe kümeleri.

### 11.4 Kapalı sık öğe kümesi

Slayttaki tanım: bir $X$ öğe kümesi, doğrudan üst kümelerinden hiçbiri $X$ ile aynı destek sayısına sahip değilse kapalıdır (closed). Kapalı ve sık olan kümeye kapalı sık öğe kümesi denir. Amaç, destek bilgisini koruyan kompakt bir gösterimdir.

Bir üst kümenin desteği alt kümesininkinden büyük olamaz. Üst kümenin desteği alt kümeyle aynıysa bu şu demektir: üst kümeye eklenen yeni öğe, alt kümenin geçtiği her işlemde vardır. Hocanın örneğiyle: C'nin desteği BC'nin desteğine eşitse, C'nin geçtiği her yerde B de geçmiştir. Hocanın anlattığı mantık budur: destekler eşitse eklenen ürün bir önceki hâlin her işleminde vardır.

> **Ders sonrası not:** Hoca bu kısımda AC, ABC ve ACD gibi örneklerle desteklerin eşit olmasını anlatırken bunu "closed frequent itemset diyorum" biçiminde ifade etti; anlatım altyazıda karışık. Slayttaki tanıma göre bir kümenin doğrudan üst kümelerinden biri aynı desteğe sahipse o küme kapalı değildir; kapalı olması için hiçbir doğrudan üst kümesinin desteği kendisininkine eşit olmamalıdır.

Slayttaki kafes örneğinde hem kapalı hem maksimal olan kümeler kırmızıyla, yalnız kapalı olanlar ayrı işaretlenmişti. Hoca bu örnekte 4 maksimal ve 9 kapalı sık öğe kümesi bulunduğunu söyledi. Kurallar artık yalnız bunlardan yazılır, diğerlerine bakmaya gerek yoktur. Hepsi kullanılsaydı yüzlerce kural çıkacaktı; yalnız maksimal ve kapalı kümeleri içeren kurallar üretilir, çünkü bunlar diğer öğeleri ve daha küçük kuralları zaten barındırır.

### 11.5 Apriori'nin özeti

Hoca Apriori'yi şöyle toparladı: bir eşik belirlenir; desteğe bakılarak eşiği geçen kümeler yinelemeli olarak bulunur; ürünler eklenerek, artık hiçbir şey eklenemeyene kadar algoritma çalıştırılır. Sonra güven hesaplanıp kurallar çıkarılır. Her öğe kümesi için kural çıkarmak gerektiğinden kural sayısı çok fazladır; kural çıkarmayı kolaylaştırmak için kapalı ve maksimal sık öğe kümeleri tanımlanmıştır ve kurallar bunlardan çıkarılır.

## 12. FP-Growth Algoritması

### 12.1 Farklı bir yaklaşım

FP-Growth, Apriori ile pek ilgisi olmayan başka bir algoritmadır; slaytta da "radikal olarak farklı bir yaklaşım" diye geçer (ekrandan, 01:35:00). Farkı, kullandığı veri yapısından gelir: FP-ağacı (FP-tree). FP, Frequent Pattern (sık örüntü) sözünden gelir; algoritmanın adı Frequent Pattern Growth'tur. Algoritma veritabanından ağacı oluşturur, sonra sık öğe kümelerini bu ağaçtan seçer.

### 12.2 FP-ağacının kurulması

Örnek veri kümesi 10 işlemden oluşur; minsup = 2'dir (ekrandan, 01:40:00):

| TID | Öğeler |
|---|---|
| 1 | {A, B} |
| 2 | {B, C, D} |
| 3 | {A, C, D, E} |
| 4 | {A, D, E} |
| 5 | {A, B, C} |
| 6 | {A, B, C, D} |
| 7 | {B, C} |
| 8 | {A, B, C} |
| 9 | {A, B, D} |
| 10 | {B, C, E} |

Ağaç null kökle başlar. Birinci işlem {A, B} okunur: kökten A'ya, A'dan B'ye gidilir; A kökün çocuğu, B de A'nın çocuğu olur. Düğümlerde bu yolun kaç işlemden geçtiğini gösteren sayaçlar tutulur (A:1, B:1).

İkinci işlem {B, C, D} okunur. A ile başlamadığı için kökten yeni bir dal açılır: B, C, D. Ayrıca önceki daldaki B'den bu yeni B'ye bir işaretçi (pointer) bağlanır.

Üçüncü işlem {A, C, D, E} A ile başlar. Birinci işlem de A ile başlıyordu; bu yüzden var olan A düğümü kullanılır ve C, D, E onun altına yeni bir dal olarak eklenir. Böylece A'dan iki dal çıkar. Buradaki C de diğer C düğümlerine işaretçiyle bağlanır.

Bu şekilde bütün işlemler ağaca yerleştirilir. Hoca, Apriori'nin eleye eleye gittiğini, FP-Growth'un ise böyle bir şey yapmadığını; bütün işlemleri ağaca yerleştirip kocaman bir ağaç elde ettiğini söyledi. On işlem okunduktan sonra ağaç slayttaki hâlini alır: kökün altında A:7 ve B:3; A'nın altında B:5, C:1, D:1 gibi düğümler vardır.

Aynı öğenin farklı dallardaki düğümleri (örneğin bütün D'ler) işaretçilerle birbirine bağlanır. Bu işaretçileri izlemek için bir başlık tablosu (header table) tutulur: her öğe için o öğenin ilk düğümüne bir işaretçi.

### 12.3 Sık öğe kümelerinin bulunması

FP-Growth sık öğe kümelerini aşağıdan yukarı (bottom-up), son eklere (suffix) göre bulur. Örneğin E ile bitenler bulunmak istensin. Başlık tablosundan E'ye gidilir; işaretçiler izlenerek ağaçtaki bütün E düğümleri bulunur. E ile biten bir yoldan yalnız yukarı çıkılabilir: bir E'nin üstünde C, başka bir E'nin üstünde D vardır. Bütün E düğümlerinden köke doğru çıkılan yollar çizilir.

İşaretçilerin yararı şudur: aynı öğeyi taşıyan düğümler birbirine bağlı olduğundan, örneğin C, E ve D'nin ne kadar birlikte geçtiği bu bağlantılardan anlaşılır. Ortak işaretçi sayısı ne kadar çoksa, o öğelerin birlikte geçtiği işlem sayısı o kadar çoktur. Sonsuz sayıda kural çıkmaması için burada da bir eşik kullanılır. Öğe kümeleri tamamen yapraklardan köke doğru çıkılarak bulunur.

Slayttaki son ek tablosu (ekrandan, 01:40:00):

| Son ek | Sık öğe kümeleri |
|---|---|
| E | {E}, {D,E}, {A,D,E}, {C,E}, {A,E} |
| D | {D}, {C,D}, {B,C,D}, {A,C,D}, {B,D}, {A,B,D}, {A,D} |
| C | {C}, {B,C}, {A,B,C}, {A,C} |
| B | {B}, {A,B} |
| A | {A} |

E son ekli kümeler python ile kontrol edildi: {E} 3, {A,E} 2, {C,E} 2, {D,E} 2, {A,D,E} 2; hepsi minsup = 2'yi sağlar.

Sık öğe kümeleri ağaçtan bulunduktan sonra kurallar benzer şekilde yazılır; kurallar yazılırken yine maksimal ve kapalı sık öğe kümeleri kullanılır.

> **Hocanın vurgusu:** FP-Growth'un ayrıntısı çok önemli değildir; bir ağaç tuttuğunu ve sık öğe kümelerini bu ağaçtan çıkardığını bilmek yeterlidir.

## 13. Birliktelik Örüntülerinin Değerlendirilmesi: Lift ve Interest

### 13.1 Sorun: çok sayıda ve tekrarlayan kural

Birliktelik kuralı algoritmaları çok fazla kural üretir. Bunların birçoğu ilgi çekici değildir ve tekrarlayan kurallar vardır: örneğin AB ise D varsa, ABC ise D de vardır. Daha kapsayıcı olan kural hangisidir? Bu kurallardan biri ötekilerini de üretir (AB ise D, B ise D, ...); çok fazla tekrar oluşur. Bunu azaltmak için az önceki yöntemler kullanılır. Ama destek ve güven aynı olabildiği için yalnız bunlara bakarak hangisinin daha iyi olduğu söylenemeyebilir.

Bu yüzden ilginçlik ölçüleri (interestingness measures) kullanılır; oluşan örüntüler ya da kurallar bu ölçülerle elenir.

### 13.2 Güvenin zayıflığı: çay ve kahve

İlginçlik ölçülerini hesaplamak için bir olasılık tablosu (contingency table) kurulur: $X$ ve $Y$, $X$ ve $\overline{Y}$, $\overline{X}$ ve $Y$, $\overline{X}$ ve $\overline{Y}$ durumlarının sayıları yazılır. Slayttaki örnek (ekrandan, 01:45:00):

| | Coffee | $\overline{Coffee}$ | Toplam |
|---|---|---|---|
| Tea | 15 | 5 | 20 |
| $\overline{Tea}$ | 75 | 5 | 80 |
| Toplam | 90 | 10 | 100 |

Toplam 100 kişi vardır. Kural: $Tea \rightarrow Coffee$.

$$Confidence = P(Coffee|Tea) = \frac{support(\{Tea, Coffee\})}{support(\{Tea\})} = \frac{15}{20} = 0{,}75$$

Yani çay ve kahveyi birlikte alanlar, bütün çay alanlara bölünür. Güven yüksek görünür. Ama $P(Coffee) = 0{,}9$'dur: zaten insanların %90'ı kahve alır. Çay almayıp kahve alanlara bakılırsa:

$$P(Coffee|\overline{Tea}) = \frac{75}{80} = 0{,}9375$$

Yani çay almayanlarda kahve alma oranı yaklaşık %93'tür; çay alanlarda ise 0,75'tir. Hoca bunu precision ve recall'daki duruma benzetti: çay alıp kahve almayan sayısı (5) azdır, ama çay almayanların sayısı çok fazladır (80). Yüzde hesaplanırken bir normalizasyon yapılmadığı için sayılar yüksek çıksa bile güven tek başına anlamlı olmayabilir. Slayttaki sonuç: güven yüksek olsa da kural yanıltıcıdır.

### 13.3 İstenen kural ve istatistiksel bağımsızlık

Ne tür kurallar istenir? Güvenin yüksek olması istenir, çünkü $X$ alanlar $Y$'yi almıştır. Ama $X$ alıp $Y$'yi almayanlara da bakılmalıdır. Bu yüzden şu koşul aranır:

$$conf(X \rightarrow Y) > support(Y)$$

Çay-kahve tablosunda bu koşul sağlanmaz: $0{,}75 < 0{,}9$.

Bu fikre dayanan iki istatistiksel ölçü vardır: lift ve interest. Lift, yazılımlarda genellikle "lift" adıyla geçer ve kuralların güveni ile desteğinden hesaplanır:

$$lift = \frac{conf(A \rightarrow B)}{support(B)}$$

Interest ise olasılık olarak şöyle tanımlanır:

$$interest = \frac{P(X, Y)}{P(X)\,P(Y)}$$

Yani $X$ ve $Y$'yi birlikte alanların oranı, $X$'i alanların oranı ile $Y$'yi alanların oranının çarpımına bölünür. Yorum:

- Değer 1'e eşitse A ve B bağımsızdır.
- 1'den büyükse pozitif ilişkilidir (correlated): A'yı alanlar gerçekten B'yi de almıştır.
- 1'den küçükse negatif ilişkilidir.

> **Ders sonrası not:** Hoca lift için "bağımsızlık yorumu yapamıyoruz, interest ise bir normalizasyon gibi" anlamında konuştu. Oysa iki ölçü aynı değeri verir: $\dfrac{conf(X \rightarrow Y)}{s(Y)} = \dfrac{P(X,Y)/P(X)}{P(Y)} = \dfrac{P(X,Y)}{P(X)P(Y)}$. Bu yüzden 1'e göre yapılan yorum lift için de geçerlidir.

### 13.4 Çay-kahve için lift

$Tea \rightarrow Coffee$ kuralının güveni 0,75'tir. Hoca önce çayın desteğine bölmeye başladı, sonra düzeltti: lift hesaplanırken sağ taraftaki $Y$'nin, yani kahvenin desteğine bölünür. Kahvenin genel oranı 0,90'dır:

$$lift = \frac{0{,}75}{0{,}9} \approx 0{,}83$$

Bu değer 1'den küçüktür; çay ile kahve arasında negatif bir ilişki vardır. Çay alanlar, genel ortalamaya göre daha az kahve almıştır.

> **Ders sonrası not:** Hoca bu hesapta "lift yüksek çıktı" dedi; doğrusu lift yaklaşık 0,83'tür ve 1'den küçüktür. Hocanın hemen ardından vardığı "negatif korelasyon var" sonucu bu değerle uyumludur. (Python ile: $0{,}75/0{,}9 = 0{,}8333$; interest $0{,}15/(0{,}2 \cdot 0{,}9) = 0{,}8333$.)

### 13.5 Basketbol ve mısır gevreği örneği

Slayttaki ikinci örnek 5000 öğrenci üzerindedir (ekrandan, 01:50:00):

| | Basketball | Not basketball | Sum (row) |
|---|---|---|---|
| Cereal | 2000 | 1750 | 3750 |
| Not cereal | 1000 | 250 | 1250 |
| Sum (col.) | 3000 | 2000 | 5000 |

- "Basketbol oynuyor ⇒ mısır gevreği yiyor" kuralı [%40, %66,7] yanıltıcıdır: öğrencilerin genelinde gevrek yeme oranı %75'tir ve bu %66,7'den büyüktür.
- "Basketbol oynuyor ⇒ gevrek yemiyor" kuralı [%20, %33,3], desteği ve güveni daha düşük olmasına rağmen daha doğrudur.

Lift değerleri:

$$lift(B, C) = \frac{2000/5000}{3000/5000 \times 3750/5000} = 0{,}89$$

$$lift(B, \neg C) = \frac{1000/5000}{3000/5000 \times 1250/5000} = 1{,}33$$

Destek ve güvene bakıldığında "gevrek yiyor" kuralı (%40, %66) daha iyi, "gevrek yemiyor" kuralı (%20, %33) daha kötü görünür. Ama lift'e bakıldığında "gevrek yemiyor" kuralı daha yüksek çıkar (1,33 > 1), "gevrek yiyor" kuralı ise 1'in altında kalır (0,89).

(Python ile kontrol: $0{,}4/(0{,}6 \cdot 0{,}75) = 0{,}889$; $0{,}2/(0{,}6 \cdot 0{,}25) = 1{,}333$; güvenler $2000/3000 = 0{,}667$ ve $1000/3000 = 0{,}333$.)

> **Hocanın vurgusu:** Bu örnek şunu gösterir: kurallarda tek başına destek ve güvene bakılmaz; mutlaka lift'e bakmak gerekir. Projesinde birliktelik kuralı kullanan biri kuralların lift ve interest değerlerine mutlaka bakmalıdır.

### 13.6 Diğer ölçüler

Olasılık tablosundan (aldı-almadı, şunu aldı-bunu almadı) başka istatistikler de hesaplanır. Destek, güven ve interest dışında Jaccard, kappa istatistiği gibi ölçüler de vardır. Hoca bunların farklı yerlerde kullanıldığını, görüldüğünde şaşırılmaması gerektiğini, ama en çok kullanılanların lift ve interest olduğunu söyledi.

<!-- BELİRSİZ: Altyazıda "ya kart kullanılır, C-Major ya da kapa istatistiği" geçiyor; "ya kart" büyük olasılıkla Jaccard'dır, "C-Major" ise slayt görülmeden çözülemedi. -->

## 14. Genel Değerlendirme

Hoca dersi şöyle bağladı. Şimdiye kadar sınıflandırma (classification) yapılmış, bir önceki hafta kümeleme (clustering) görülmüştü. Burada kümeleme yapılsaydı aynı şey elde edilir miydi? Kümelemeyle belki müşteriler iki üç gruba ayrılabilirdi; ama burada istenen bu değildir. Burada "bu alındıysa şu da ne kadar birlikte alınmış" sorusunun cevabı aranır. Bu yüzden birliktelik kuralları da betimleyici (descriptive) bir yöntemdir: yapılmış bir şeyi açıklamaya çalışır.

Birliktelik kuralları en çok market sepeti analizinde kullanılır. Bunun dışında metin madenciliğinde de kullanılabilir: elde kelime listeleri varsa "şu kelimeler birlikte kullanıldıysa şu da kullanılmıştır" gibi kurallar çıkarılabilir.

İki ünlü algoritma vardır. Apriori en küçük kümelerden başlar ve eşiği sağlayan küme kalmayana kadar ekleye ekleye gider; biraz yavaş çalışır, bu yüzden hash yapısı gibi yöntemlerle hızlandırılmaya çalışılmıştır. İkincisi FP-Growth'tur: tamamen özel bir ağaç yapısına dayanır. Her işlem okunduğunda ağaca eklenir; ağaçta var olan yol tekrar oluşturulmaz, aynı öğeler birbirine bağlanır. Aynı ürünlerin aynı dallarda toplanması, sık öğe kümeleri hakkında bilgi verir.

> **Ders sonrası not:** Altyazıda "bir tanesi Apriori, diğeri de Apriori algoritması" geçiyor; bağlamdan ikinci algoritmanın FP-Growth olduğu açıktır.

Ders sonunda bir öğrenci projede birden fazla yöntemin karşılaştırılması gerekip gerekmediğini sordu. **Soru:** Projede yöntemleri karşılaştırmak gerekiyor mu? **Cevap:** Evet. Örneğin yapay sinir ağı, karar ağacı ve bir topluluk öğrenmesi (ensemble learning) yöntemi çalıştırıldıysa, birinin neden daha iyi çalıştığı açıklanmalıdır: veri doğrusal ayrılabilir olmadığı için mi, aykırı değer (outlier) çok olduğu ve bir yöntem bunları daha iyi elediği için mi? Yalnız "A yöntemi %90, B yöntemi %80 verdi" demek yetmez; neden böyle çıktığı ve başka parametreyle daha iyi çalışıp çalışmayacağı tartışılmalıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): İşlemler 10: {Beer, Nuts, Diaper}, 20: {Beer, Coffee, Diaper}, 30: {Beer, Diaper, Eggs}, 40: {Nuts, Eggs, Milk}, 50: {Nuts, Coffee, Diaper, Eggs, Milk} olsun. minsup = %50, minconf = %50 için sık örüntüleri ve $\{Beer, Diaper\}$ kümesinden çıkan kuralları destek ve güvenleriyle bulun.

> **Çözüm (derste verildi, python ile doğrulandı):** Sık örüntüler $\{Beer\}:3$, $\{Nuts\}:3$, $\{Diaper\}:4$, $\{Eggs\}:3$, $\{Beer, Diaper\}:3$. $Beer \rightarrow Diaper$: destek $3/5 = \%60$, güven $3/3 = \%100$. $Diaper \rightarrow Beer$: destek $3/5 = \%60$, güven $3/4 = \%75$.

**Soru 2** (ekrandan, 00:35:00): İşlemler ABD, ABCD, A, ABC, BC, B; minsup = 0,5, minconf = 0,7. Eşikleri sağlayan sık öğe kümelerini ve birliktelik kurallarını bulun.

> **Çözüm (derste verildi):** Tekliler: $s(A) = 4/6$, $s(B) = 5/6$, $s(C) = 3/6$; $s(D) = 2/6$ olduğu için D elenir. İkililer: $s(\{A,B\}) = 3/6$, $s(\{B,C\}) = 3/6$; $s(\{A,C\}) = 2/6$ elenir. Kurallar: $conf(A \rightarrow B) = 3/4$, $conf(C \rightarrow B) = 3/3$; ikisi de 0,7'yi geçer.

**Soru 3** (ekrandan, 00:45:00): Bread-Milk veri kümesinde (1: Bread, Milk; 2: Bread, Diaper, Beer, Eggs; 3: Milk, Diaper, Beer, Coke; 4: Bread, Milk, Diaper, Beer; 5: Bread, Milk, Diaper, Coke) minimum destek 3 iken Apriori algoritmasını adım adım uygulayın. Budamasız ve budamalı aday sayılarını karşılaştırın.

> **Çözüm (derste verildi, python ile doğrulandı):** Tekliler: Bread 4, Coke 2, Milk 4, Beer 3, Diaper 4, Eggs 1; Coke ve Eggs elenir. İkililer: {Bread, Milk} 3, {Beer, Bread} 2, {Bread, Diaper} 3, {Beer, Milk} 2, {Diaper, Milk} 3, {Beer, Diaper} 3; {Beer, Bread} ve {Beer, Milk} elenir. Üçlülerin sayıları 2, 2, 2, 1'dir ({Beer, Bread, Diaper} 2, {Beer, Diaper, Milk} 2, {Bread, Diaper, Milk} 2, {Beer, Bread, Milk} 1); hiçbiri 3'e ulaşmaz, algoritma durur. Budamasız $6 + 15 + 20 = 41$, budamalı $6 + 6 + 4 = 16$ aday sayılır.

**Soru 4** (derste sözlü, 00:36:59): $n$ elemanlı bir kümenin kaç alt kümesi vardır? Beş öğe için kaba kuvvet kaç aday kümeye bakar?

> **Cevap (derste verildi):** $2^n$ alt küme vardır. Beş öğe için $2^5 = 32$ alt küme oluşur; kaba kuvvet hepsinin destek ve güvenini hesaplar.

**Soru 5** (ekrandan, 00:50:00): $F_3 = \{ABC, ABD, ABE, ACD, BCD, BDE, CDE\}$ için $F_{k-1} \times F_{k-1}$ yöntemiyle aday 4-öğe kümelerini üretin.

> **Çözüm (derste verildi):** İlk iki öğesi aynı olanlar birleştirilir: ABC + ABD = ABCD, ABC + ABE = ABCE, ABD + ABE = ABDE. ABD ile ACD yalnız 1 uzunluğunda ön ek paylaştığı için birleştirilmez. $L_4 = \{ABCD, ABCE, ABDE\}$.

**Soru 6** (derste sözlü, 01:18:32): $c(ABC \rightarrow D)$, $c(AB \rightarrow D)$'den büyük müdür? Aynı $\{A,B,C,D\}$ kümesinden çıkan $ABC \rightarrow D$, $AB \rightarrow CD$, $A \rightarrow BCD$ kurallarının güvenleri nasıl sıralanır?

> **Cevap (derste verildi):** Genelde bir şey söylenemez; $c(ABC \rightarrow D)$ büyük de küçük de olabilir. Aynı kümeden çıkan kurallarda ise $c(ABC \rightarrow D) \ge c(AB \rightarrow CD) \ge c(A \rightarrow BCD)$'dir, çünkü pay ($s(ABCD)$) aynıdır ve sol taraf küçüldükçe payda büyür.

**Soru 7** (ekrandan, 01:25:00): ABCDEFG eşiği aşmamış; ABCDE, BCDE ve DE sık öğe kümeleri olsun (ABCDE'nin başka sık üst kümesi yok). Hangisi maksimal sık öğe kümesidir?

> **Cevap (derste verildi):** DE değildir (sık üst kümesi BCDE var), BCDE değildir (sık üst kümesi ABCDE var). Maksimal sık öğe kümesi ABCDE'dir.

**Soru 8** (ekrandan, 01:45:00): Çay-kahve tablosunda (Tea ve Coffee 15, Tea ve $\overline{Coffee}$ 5, $\overline{Tea}$ ve Coffee 75, $\overline{Tea}$ ve $\overline{Coffee}$ 5) $Tea \rightarrow Coffee$ kuralının güvenini ve lift değerini hesaplayın. Kural iyi bir kural mıdır?

> **Çözüm (derste verildi, python ile doğrulandı):** Güven $15/20 = 0{,}75$. $P(Coffee) = 0{,}9$, $P(Coffee|\overline{Tea}) = 75/80 = 0{,}9375$. Lift $= 0{,}75/0{,}9 \approx 0{,}83 < 1$. Güven yüksek görünse de kural yanıltıcıdır; çay ile kahve arasında negatif ilişki vardır.

**Soru 9** (ekrandan, 01:50:00): 5000 öğrencilik tabloda (Basketball ve Cereal 2000, Not basketball ve Cereal 1750, Basketball ve Not cereal 1000, Not basketball ve Not cereal 250) $lift(B, C)$ ve $lift(B, \neg C)$ değerlerini hesaplayın. Hangi kural daha anlamlıdır?

> **Çözüm (derste verildi, python ile doğrulandı):** $lift(B, C) = \dfrac{0{,}4}{0{,}6 \times 0{,}75} = 0{,}89$; $lift(B, \neg C) = \dfrac{0{,}2}{0{,}6 \times 0{,}25} = 1{,}33$. "Basketbol ⇒ gevrek yer" [%40, %66,7] desteği ve güveni daha yüksek olsa da yanıltıcıdır, çünkü genel gevrek yeme oranı %75'tir. "Basketbol ⇒ gevrek yemez" [%20, %33,3] lift'i 1'den büyük olduğu için daha anlamlıdır.

**Soru 10** (derste sözlü, 00:58:14): Apriori parametreye çok bağlıysa minimum destek eşiği nasıl belirlenir?

> **Cevap (derste verildi):** Çok yüksek eşik önemli öğe kümelerini eler, çok düşük eşik ilgisiz birçok öğe kümesi ekler. Farklı eşikler için sonuçlar çizilip incelenir; tek eşik yerine öğelere ya da öğe kümesi boyuna göre değişen çoklu minimum destek kullanılabilir. Bu parametreler de deneyerek ayarlanır.

## Dersin Toparlaması

Bu derste birliktelik kuralı madenciliği işlendi. Bir işlem veri kümesinde sık birlikte görülen öğe kümeleri aranır; bir öğe kümesinin desteği onu içeren işlemlerin oranı, bir $X \rightarrow Y$ kuralının güveni ise $X$'i içeren işlemlerin ne kadarının $Y$'yi de içerdiğidir. Kaba kuvvet arama $2^d$ aday nedeniyle imkansız olduğundan iş iki adıma bölünür: önce sık öğe kümeleri, sonra bunlardan kurallar bulunur. Apriori algoritması, seyrek bir kümenin üst kümelerinin de seyrek olduğu ilkesiyle adayları budar; adayları ön ekleri aynı kümeleri birleştirerek üretir ve sayımı hash ağacıyla hızlandırabilir. Sonuçlar eşiklere çok bağlıdır; çoklu minimum destek bu sorunu hafifletmeye çalışır. Kural üretmede, aynı kümeden çıkan kurallarda güvenin sağ taraf büyüdükçe azalması budama için kullanılır.

Çok sayıda tekrarlayan kümeyi azaltmak için maksimal ve kapalı sık öğe kümeleri tanımlandı; kurallar bu kümelerden üretilir. Apriori'den tamamen farklı çalışan FP-Growth, işlemleri bir FP-ağacına yerleştirip sık öğe kümelerini son eklere göre aşağıdan yukarı bulur. Son olarak, güvenin tek başına yanıltıcı olabileceği çay-kahve ve basketbol-gevrek örnekleriyle gösterildi ve kuralların lift ve interest ile değerlendirilmesi gerektiği vurgulandı. Birliktelik kuralları, kümelemeden farklı olarak "bu alındıysa şu da ne kadar alınmış" sorusunu cevaplayan betimleyici bir yöntemdir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
