# Ders 11 Genişletilmiş Notu: Ortak Atıf, Bibliyografik Eşleşme ve PageRank Algoritması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Hatırlatması: Merkezilik ve Prestij
- 2. Ortak Atıf (Co-citation)
- 3. Bibliyografik Eşleşme (Bibliographic Coupling)
- 4. Popülerliğe Dayalı Sıralama
- 5. PageRank'in Temel Fikri: Bağlantılar Oy Gibidir
- 6. Akış Denklemi ve Basit Örnek
- 7. Matris Gösterimi ve Özvektör Sistemi
- 8. Kuvvet Yinelemesi (Power Iteration)
- 9. Rastgele Yürüyüş Yorumu ve Durağan Dağılım
- 10. Web Grafındaki Sorunlar: Döngü, Çıkmaz Sokak, Örümcek Tuzağı
- 11. Çözüm: Rastgele Işınlanma ve Google Matrisi
- 12. PageRank'in Avantajları ve Eleştirisi
- Örnek Sorular

## 1. Önceki Dersin Hatırlatması: Merkezilik ve Prestij

Hoca derse, bağlantı analizi (link analysis) ve sosyal ağ analizi (social network analysis) konusunda geçen hafta nerede kalındığını hatırlatarak başladı. Sosyal ağ analizinde bir aktörün ağdaki önemini belirlemek için iki tür metrik kullanılır:

- **Merkezilik metrikleri (centrality metrics):** derece merkeziliği (degree centrality), yakınlık merkeziliği (closeness centrality) ve arasındalık merkeziliği (betweenness centrality). Her biri için küçük oyuncak örnekler (toy examples) üzerinde hesap yapılmıştı.
- **Prestij metrikleri (prestige metrics):** derece prestiji (degree prestige), yakınlık prestiji (proximity prestige) ve sıra prestiji (rank prestige).

Prestij metriklerinin hepsi giriş bağlantılarıyla (in-link), yani düğümün kendisine yönelen bağlantılarla ilgilenir. Sıra prestijini anlatırken önemli bir gözlem yapılmıştı: Bir kişi birçok kişiden bağlantı alabilir, ama bu bağlantıların hepsi aynı öneme sahip değildir. Bazı bağlantılar diğerlerinden daha değerlidir. Bu yüzden bir düğümün sıra prestiji hesaplanırken, ona bağlantı veren düğümlerin sıra prestijleri toplanır.

$i$ düğümünün sıra prestiji şu denklemle verilir:

$$P_R(i)=\sum_{j=1}^{n}A_{ji}\,P_R(j)$$

Toplam ağdaki bütün düğümler üzerinden alınır, ama her terimin önünde bir katsayı vardır. Ağdaki $j$ düğümünün $i$'ye doğrudan bağlantısı varsa katsayı 1, yoksa 0'dır. Yani hesapta yalnız $i$'ye doğrudan bağlantı veren düğümler dikkate alınır. Önemli (sıra prestiji yüksek) düğümlerden bağlantı alan bir düğümün kendi sıra prestiji de yüksek çıkar.

Bu denklem matrisle de yazılabilir. $A$ komşuluk matrisi (adjacency matrix), $A^T$ onun devriği (transpose), $P$ ise sıra prestiji sütun vektörüdür:

$$P=A^{T}P$$

Sağdaki $P$ prestij vektörünün önceki durumu, soldaki $P$ ise son durumudur. Hoca bu denkleme özvektör sistemi (eigenvector system) dendiğini ve PageRank konusunda bu yapının tekrar karşımıza çıkacağını söyledi.

<!-- BELİRSİZ: Hoca derece ve yakınlık prestijini "geçen hafta" anlattığını söylüyor; bu dersin kaydında yalnız adları geçiyor, tanımları verilmiyor. -->

## 2. Ortak Atıf (Co-citation)

Geçen dersin sonunda sosyal ağ analizinde kullanılan iki metriğe daha giriş yapılmıştı: ortak atıf (co-citation) ve bibliyografik eşleşme (bibliographic coupling). İkisi de bir ağdaki iki düğüm arasındaki ilişkiyi bulmaya yarar.

Hoca örnek ağ olarak yayın ağını aldı. Yayımlanan her makalenin bir kaynakça (references) bölümü vardır. Makaleler bu bölümde başka makalelere bağlantı, yani atıf verir. Bu bağlantılar analiz edilerek makaleler arasındaki ilişki anlaşılabilir.

Ortak atıf metriğinin fikri şudur: İki makale, $i$ ve $j$, aynı makale tarafından atıf alıyorsa bu iki makale ilişkilidir, yani ortak atıf almıştır (co-cited). Slayttaki şekilde $k$ makalesi hem $i$'ye hem $j$'ye atıf veriyordu. Eğer $k$ gibi, $i$ ve $j$'ye aynı anda atıf veren makalelerin sayısı artarsa, $i$ ile $j$ arasındaki ilişki o kadar güçlenir.

### 2.1 Atıf matrisi ve ortak atıf hesabı (tahtadaki anlatım)

Hoca formülü tahtada Türkçe anlattı. Elimizde $n$ makale varsa $n\times n$ boyutunda bir atıf matrisi (citation matrix) $L$ kurulur:

- Satırlarda referansı **veren** makale bulunur.
- Sütunlarda referansı **alan** makale bulunur.
- $i$ makalesinden $j$ makalesine atıf varsa ilgili hücreye 1, yoksa 0 yazılır.

İki makale arasındaki ortak atıf ilişkisini bulmak için bu matriste iki makalenin **sütunlarına** bakılır. İki sütunda da 1 olan bir satır varsa, o satırdaki makale ikisine birden atıf vermiş demektir. Hocanın tahtadaki örneğinde $k$ satırında iki sütunda da 1 vardı; yani $k$ makalesi hem $i$'ye hem $j$'ye atıf vermişti. Yan yana duran 1'lerin sayısı arttıkça, iki makaleye birlikte atıf veren makalelerin sayısı artmış olur.

Hesap şöyle yapılır: İki sütun vektörünün elemanları satır satır çarpılır ve toplanır. Birinci ile birinci, ikinci ile ikinci, üçüncü ile üçüncü çarpılarak aşağı doğru inilir. Sonuç, $i$ ile $j$ arasındaki ortak atıf değeridir:

$$C_{ij}=\sum_{k=1}^{n}L_{ki}\,L_{kj}$$

<!-- BELİRSİZ: Altyazıda tahtadaki ikinci makale "C" diye geçiyor; slayttaki formülle birlikte düşünüldüğünde büyük olasılıkla "j" kastediliyor. -->

## 3. Bibliyografik Eşleşme (Bibliographic Coupling)

Bibliyografik eşleşme, ortak atıfın tersidir. Hoca önce "bir makale iki farklı makaleye atıf yapıyorsa" diye başladı, sonra cümleyi düzeltti: Bir makale iki farklı makale tarafından atıf alıyorsa, bu ilk makaleye atıf yapan iki makale ilişkilidir. Slayttaki örnekte $i$ ve $j$ makaleleri ikisi de $k$ makalesine atıf yapıyordu. Bu, $i$ ile $j$ arasında bir ilişki olduğu anlamına gelir. $i$ ve $j$ ne kadar çok ortak makaleye atıf yaparsa ilişkileri o kadar güçlenir.

Tahtadaki çizim ortak atıfın aynısıdır, ama bu kez atıf matrisinde iki **satır** vektörü kullanılır. İki farklı makale aynı $k$ makalesine atıf yapmışsa, $k$'nın sütununda ikisinin de değeri 1 olur. Hesapta iki satır vektörünün elemanları eleman eleman çarpılıp toplanır:

$$B_{ij}=\sum_{k=1}^{n}L_{ik}\,L_{jk}$$

<!-- BELİRSİZ: Bibliyografik eşleşmenin tahtada anlatıldığı yaklaşık 00:36–00:38 arası altyazıda anlamsız İngilizce cümlelere dönüşmüş; bu kısım 00:38:34 ve 00:39:01'deki Türkçe toparlamadan ve standart formülden kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** İki toplam formülü matris çarpımıyla da yazılabilir. Ortak atıf matrisi $C=L^{T}L$, bibliyografik eşleşme matrisi $B=LL^{T}$'dir. İki matris de simetriktir. Bu eşitlikler python ile rastgele bir atıf matrisi üzerinde denetlendi.

### 3.1 Bu iki metrik neden önemli?

İki metrik, iki farklı belge ya da makale arasındaki ilişkiyi bulmak için kullanılır. İki belgenin benzerliği yalnız TF-IDF matrisine dayalı içerik benzerliğiyle ölçülmek zorunda değildir. Kaynakça bölümlerine bakılarak bir bağlantı analizi de yapılabilir.

Hoca intihal (plagiarism) yazılımlarını örnek verdi. Bu yazılımlar makalelerin birbirine yakınlığını hesaplarken yalnız içeriğe bakmaz, verilen referanslara da bakar:

- İki makale kaynakçalarında aynı makalelere atıf yapmışsa aralarındaki bibliyografik eşleşme değeri çok yüksek olur.
- İki makale çok sayıda makale tarafından sürekli birlikte atıf alıyorsa (co-cited) yine aralarında bir ilişki vardır.

## 4. Popülerliğe Dayalı Sıralama

Hoca bağlantı analizi bölümünde o ana kadar görülenleri toparladı: genel olarak sosyal ağ analizi, merkezilik ve prestij metrikleri, sonra belgeler arası ilişkiyi bulan ortak atıf ve bibliyografik eşleşme. Bundan sonra popülerliğe dayalı sıralama (popularity-based ranking) yöntemlerine geçildi. Bu metrikler özellikle arama uygulamalarında, arama sonuçlarının sıralamasını belirlemek için kullanılır. İki temsilcisi PageRank ve HITS'tir. Bu derste PageRank işlendi.

### 4.1 Web grafı karmaşık bir ağdır

PageRank ve HITS özellikle web grafı (web graph) üzerinde kullanılır. Web grafında düğümler web sayfaları, kenarlar ise bir sayfadan diğerine yönelen köprü bağlantılardır (hyperlink). Bu nedenle web grafı yönlü (directed) bir graftır.

Web'de herkes kendi sitesine hangi bağlantıyı koyacağına kendisi karar verir. Merkezi bir otoritenin izni gerekmez ve kimse sizi belli bir sayfaya bağlantı vermeye zorlamaz. Her sayfa özerk (autonomous) olarak düzenlendiği için ortaya çıkan web grafı karmaşık bir ağdır (complex network). Amaç, böyle bir yönlü graf verildiğinde web sayfalarının popülerliğini bulmaktır.

Web grafı çok büyük olduğu için, sayfaları yalnız sorguyla ne kadar eşleştiklerine göre TF-IDF tabanlı benzerlik metrikleriyle sıralamak yeterli değildir. Popülerliğe dayalı sıralama yöntemlerine ihtiyaç vardır.

### 4.2 Web aramasının iki sorunu

Web'de sorgu girdiğinizde sorguyla eşleşen çok sayıda sayfa çıkar. Burada iki sorun vardır:

- **Hangi sayfalara güvenilir?** Sorguyla eşleşen sayfalardan hangileri güvenilir (trustworthy) bilgi içerir? Buradaki varsayım, güvenilir sayfaların birbirine bağlantı verdiğidir. Örneğin Wikipedia'daki bir sayfanın yalnız güvenilir sayfalara bağlantı vermesi beklenir; spam sayfalara bağlantı vermesi beklenmez.
- **Güvenilir sayfalar arasında en iyisi hangisi?** Sonuçların hepsi güvenilir sayfalardan gelse bile, sorguya en iyi cevap hangisidir? Güvenilir sayfalar arasında bir sıralama yapılması gerekir.

İki sorun da sayfaların popülerliğine dayanan bir metrik gerektirir. Bir sayfa çok sayıda başka sayfadan bağlantı alıyorsa popülerdir ve güvenilir bir sayfa olduğu düşünülebilir. Yani bir sayfanın önemi popülerliğiyle belirlenir.

Slayttaki oyuncak örnekte iki sayfa vardı: kırmızı ve mavi. Mavi sayfa birçok sayfadan bağlantı alıyor, kırmızı sayfa ise yalnız bir bağlantı alıyordu. Birçok sayfa mavi sayfadaki bilgiye güvendiği için ona bağlantı verir; bu yüzden mavi sayfa popülerlik açısından daha önemlidir. Hoca aynı fikri gerçek bir örnekle de verdi: stanford.edu ana sayfası, adı bilinmeyen bir siteye (no-name site) göre çok daha fazla giriş bağlantısı alır. Bu yüzden Stanford'un daha popüler ve güvenilir olması beklenir.

## 5. PageRank'in Temel Fikri: Bağlantılar Oy Gibidir

PageRank hesabı sıra prestiji metriğine dayanır. Bir düğümün skoru, ona bağlantı veren bütün düğümlerin skorları toplanarak bulunur. Düğüme gelen her bağlantı bir **oy** (vote) gibi düşünülür; bağlantı veren düğüm, o düğüme oy vermiş olur. Bu yüzden PageRank giriş bağlantılarıyla ilgilenir.

Sıra prestijinden hatırlandığı gibi, bütün bağlantılar eşit değildir. Hocanın benzetmesi: Bir şirketin genel müdüründen (CEO) aldığınız bağlantı, iş arkadaşınızdan aldığınız bağlantıdan çok daha önemlidir.

### 5.1 Büyük düğümler örneği

Slayttaki küçük web grafında düğümlerin boyutları farklıydı. Düğümün boyutu onun popülerlik skorunu, yani PageRank skorunu gösteriyordu. Bu örnekte toplam PageRank skoru 100'dü. Bazı düğümler çok sayıda giriş bağlantısı aldığı için önemliydi.

> **Hocanın vurgusu:** Örnekteki C düğümü yalnız **bir** giriş bağlantısı alıyor, ama PageRank skoru yüksek. Yeşil renkli E düğümü dört giriş bağlantısı alıyor, ama C'nin skoru E'ninkinden çok daha yüksek. Bunun nedeni, C'nin aldığı tek bağlantının ağdaki en önemli düğümden gelmesidir.

Buradan çıkan ders şudur: Her bağlantı, onu veren düğümün önemini taşır. Önemi yüksek bir sayfadan bağlantı alırsanız sizin PageRank skorunuz da yüksek olur. Bir düğümün PageRank skoru hesaplanırken ona bağlantı veren bütün düğümlerin skorlarının (katkılarının) toplanması gerekir.

<!-- BELİRSİZ: Slayttaki düğümlerin sayısal skorları altyazıda okunmuyor; yalnız toplamın 100 olduğu söyleniyor. -->

### 5.2 Skor çıkış bağlantılarına eşit paylaştırılır

Hoca bunu küçük bir grafla açıkladı. Kırmızı $j$ düğümüne iki düğüm bağlantı veriyor: $i$ ve $k$.

- $i$ düğümünün 3 çıkış bağlantısı (out-link) vardır ve bunlardan biri $j$'ye gider. $i$, PageRank skorunu çıkış bağlantısı sayısıyla orantılı olarak dağıtır; $j$'ye skorunun yalnız $1/3$'ünü aktarır. Bu yüzden $j$'nin skoru hesaplanırken $r_i$ 3'e bölünür.
- $k$ düğümünün 4 çıkış bağlantısı vardır ve biri $j$'ye gider. Bu yüzden $r_k$ 4'e bölünür.

$j$'nin skoru bu iki değerin toplamıdır:

$$r_j=\frac{r_i}{3}+\frac{r_k}{4}$$

Aynı işlem sürer: $j$ de skorunu sonraki düğümlere aktarır. $j$'nin 3 çıkış bağlantısı olduğu için her birine skorunun $1/3$'ünü verir. Hoca bunun basit bir özyinelemeli (recursive) formül olduğunu söyledi.

## 6. Akış Denklemi ve Basit Örnek

Hoca formülü üç düğümlü bir oyuncak örnek üzerinde gösterdi. Düğümler y, a ve m'dir. Bağlantılar:

- y'nin kendine bir bağlantısı (self-link) ve a'ya bir bağlantısı var.
- a, y'ye ve m'ye bağlantı veriyor.
- m, a'ya bağlantı veriyor.

Her düğüm için denklem şöyle kurulur:

- **y:** y iki bağlantı alır: biri kendinden, biri a'dan. y'nin 2 çıkış bağlantısı olduğu için $r_y/2$; a'nın da 2 çıkış bağlantısı olduğu için $r_a/2$ alınır.
- **a:** a, y'den ($r_y/2$) ve m'den bağlantı alır. m'nin tek çıkış bağlantısı olduğu için katkısı $r_m$'dir.
- **m:** m yalnız a'dan bağlantı alır. a'nın 2 çıkış bağlantısı olduğu için $r_a/2$ alınır.

$$r_y=\frac{r_y}{2}+\frac{r_a}{2},\qquad r_a=\frac{r_y}{2}+r_m,\qquad r_m=\frac{r_a}{2}$$

Bu denklemler genelleştirildiğinde PageRank'in **akış denklemi** (flow equation) elde edilir. $d_i$, $i$ düğümünün çıkış derecesidir (out-degree):

$$r_j=\sum_{i\to j}\frac{r_i}{d_i}$$

Yani bir $j$ düğümünün skoru, $j$'ye bağlantı veren bütün düğümlerin **oransal** PageRank skorlarının toplamıdır. Oransal skor, bağlantı veren düğümün skorunun onun çıkış bağlantısı sayısına bölünmesiyle bulunur.

### 6.1 Tek çözüm için dördüncü denklem

Elimizde üç denklem ve üç bilinmeyen ($r_y$, $r_a$, $r_m$) var. Ama bu üç denklem çözülmeye çalışılırsa tek (unique) bir çözüm bulunmaz. Bu yüzden bir denklem daha eklenir: Grafındaki bütün PageRank skorlarının toplamı 1 olmalıdır.

$$r_y+r_a+r_m=1$$

Dört denklem ve üç bilinmeyenle sistem tek bir çözüm verir. Çözüm adımları (ara adım eklendi):

- Üçüncü denklemden $r_m=r_a/2$.
- Birinci denklemden $r_y/2=r_a/2$, yani $r_y=r_a$.
- İkinci denklem bu ikisiyle kendiliğinden sağlanır: $r_y/2+r_a/2=r_a$. Bu, üç denklemin bağımsız olmadığını, yani neden tek çözüm vermediğini gösterir.
- Toplam koşulu: $r_a+r_a+r_a/2=1\Rightarrow r_a=\frac{2}{5}$.

$$r_y=\frac{2}{5},\qquad r_a=\frac{2}{5},\qquad r_m=\frac{1}{5}$$

<!-- BELİRSİZ: Slayttaki çözüm değerleri altyazıda okunmuyor; değerler denklemlerden çözüldü ve python ile doğrulandı. -->

Bu yöntem üç düğümlü bir grafta işe yarar. Ama gerçek web grafında milyonlarca düğüm vardır. Denklemleri tek tek yazmak mümkün olmadığı için PageRank formülünün matris gösterimine ihtiyaç vardır.

## 7. Matris Gösterimi ve Özvektör Sistemi

Aradan sonra hoca matris gösterimini önce tahtada Türkçe anlattı.

### 7.1 Stokastik komşuluk matrisi

Tahtada $n\times n$ boyutunda bir komşuluk matrisi $M$ çizildi:

- **Sütunlarda** bağlantıyı **veren** düğümler bulunur.
- **Satırlarda** bağlantıyı **alan** düğümler bulunur.

Bir düğüm diğerine bağlantı vermişse ilgili hücreye bir değer yazılır, bağlantı yoksa 0 yazılır. Yazılacak değer, bağlantıyı veren düğümün çıkış bağlantısı sayısına bağlıdır. Bağlantıyı veren düğüm $i$ ise ve $d_i$ çıkış bağlantısı varsa, değer $1/d_i$'dir. Örneğin $i$'nin 3 çıkış bağlantısı varsa, $i$'nin bağlantı verdiği bütün düğümlerin satırına, $i$'nin sütununda $1/3$ yazılır; diğer yerlere 0 yazılır.

$$M_{ji}=\begin{cases}1/d_i, & i\to j\ \text{bağlantısı varsa}\\ 0, & \text{yoksa}\end{cases}$$

Bu matris aynı zamanda **stokastik komşuluk matrisidir** (stochastic adjacency matrix). Her sütundaki değerler toplandığında 1 çıkar.

> **Ders sonrası not:** Hoca önce "her bir satırı alıp topladığınızda değer bir çıkacak" dedi, hemen ardından sütun dedi. Doğrusu sütundur: $M$'de sütunlar bağlantıyı veren düğümlerdir ve her sütunun toplamı 1'dir (sütun stokastik, column stochastic). Çıkış bağlantısı olmayan düğümün sütunu bu kuralı bozar; bu, Bölüm 10'daki çıkmaz sokak sorunudur.

### 7.2 Matris ile vektör çarpımı

Matrisin yanına $n\times 1$ boyutunda bir sütun vektörü $r$ konur. Buna sıra vektörü (rank vector) denir. Matrisle bu vektör çarpıldığında yine bir sütun vektörü elde edilir; bu da yine bir sıra vektörüdür. İlk çarpılan vektör PageRank vektörünün başlangıç (initial) değeridir; çarpım sonucunda elde edilen vektör ise ikinci değeridir. Bu çarpım özyinelemeli olarak sürdürülür: Elde edilen vektör tekrar matrisle çarpılır, bir sonraki adımın vektörü bulunur. Nerede durulacağı kuvvet yinelemesinde anlatıldı.

$$r=M\cdot r$$

### 7.3 Tek düğümün skoru matristen nasıl çıkar?

Hoca bu çarpımın akış denklemiyle aynı olduğunu tahtada gösterdi. $j$ düğümünün skorunu hesaplamak için $M$'nin $j$. satırı alınır ve $r$ sütun vektörüyle çarpılır: birinci elemanlar çarpılıp toplanır, sonra ikinciler, en son $n$. elemanlar. Sonuç $j$'nin PageRank skorudur.

Bu işlem şununla aynıdır:

- Satırdaki sıfır olmayan elemanlar, $j$'ye bağlantı veren düğümlerdir.
- Bu elemanların değerleri $1/d_i$'dir.
- Skorlar ($r_i$) sütun vektöründen gelir.

Yani satır vektörü ile sütun vektörünün çarpımı, $j$'ye bağlantı veren bütün düğümlerin oransal PageRank değerlerinin toplamını verir. Bu, akış denkleminin ta kendisidir. İşlem birinci düğümden $n$. düğüme kadar yapılınca web grafındaki bütün düğümlerin skorları hesaplanır.

### 7.4 Özvektör sistemi

Hoca slaytlara dönerek bu denklemin doğrusal cebirde bir özvektör sistemi (eigen system) olduğunu söyledi. Genel özvektör denkleminde $x$ özvektör (eigenvector), $\lambda$ ise özdeğerdir (eigenvalue):

$$A\,x=\lambda\,x$$

PageRank denkleminde $r$ özvektördür ve özdeğer 1'dir. Bu yüzden denklemde bir katsayı görünmez. Bu denklemi çözmek için yine doğrusal cebirden gelen bir yöntem kullanılır: kuvvet yinelemesi.

### 7.5 Örneğin matrisi

Üç düğümlü örnekte (sıra y, a, m):

- y'nin 2 çıkış bağlantısı var: kendine ve a'ya. y'nin sütununda yalnız iki eleman sıfırdan farklıdır ve değerleri $1/2$'dir.
- m'nin tek çıkış bağlantısı var ve a'ya gidiyor. m'nin sütununda yalnız bir eleman sıfırdan farklıdır ve değeri $1/1=1$'dir.

$$\begin{pmatrix}r_y\\r_a\\r_m\end{pmatrix}=\begin{pmatrix}1/2&1/2&0\\1/2&0&1\\0&1/2&0\end{pmatrix}\begin{pmatrix}r_y\\r_a\\r_m\end{pmatrix}$$

Bu matris denkleminden, Bölüm 6'daki üç denklemin aynısı çıkar.

## 8. Kuvvet Yinelemesi (Power Iteration)

Kuvvet yinelemesi basit bir özyinelemeli algoritmadır. $N$ sayfa olduğu varsayılır:

- **Başlangıç:** Sıra vektörü bir sütun vektörüdür ve her sayfanın başlangıç skoru $1/N$'dir. Böylece toplam skor 1 olur.

$$r^{(0)}=\left[\tfrac{1}{N},\dots,\tfrac{1}{N}\right]^{T}$$

- **Yineleme:** Stokastik komşuluk matrisi, $t$ anındaki sıra vektörüyle çarpılır; $t+1$ anındaki sıra vektörü bulunur.

$$r^{(t+1)}=M\,r^{(t)}$$

- **Durma koşulu:** Her yeni vektör hesaplandığında eskisi yeniden çıkarılır. İki ardışık vektör arasındaki fark küçük bir eşik değer $\varepsilon$'dan küçükse durulur, değilse yinelemeye devam edilir.

$$\lVert r^{(t+1)}-r^{(t)}\rVert<\varepsilon$$

### 8.1 Basit örnekte yineleme

Hoca yöntemi aynı y, a, m örneği üzerinde uyguladı. Başlangıçta her düğümün skoru $1/3$'tür. $M$ bu vektörle çarpılınca ikinci vektör, ikinci vektör $M$ ile çarpılınca üçüncü vektör bulunur ve yakınsamış (converged) vektöre ulaşılana kadar devam edilir. Yakınsamış vektörle bir öncekinin farkı neredeyse sıfırdır.

Yineleme değerleri python ile hesaplandı:

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 | 1/2 | 1/6 |
| 2 | 5/12 | 1/3 | 1/4 |
| 3 | 3/8 | 11/24 | 1/6 |
| 4 | 5/12 | 17/48 | 11/48 |
| ∞ | 2/5 | 2/5 | 1/5 |

Örneğin 1. adım: $r_y=\frac12\cdot\frac13+\frac12\cdot\frac13=\frac13$, $r_a=\frac12\cdot\frac13+1\cdot\frac13=\frac12$, $r_m=\frac12\cdot\frac13=\frac16$. Yineleme yaklaşık 200 adımda $(0{,}4;\ 0{,}4;\ 0{,}2)$ değerine yakınsadı. Bu, Bölüm 6.1'de denklemlerle bulunan çözümün aynısıdır.

<!-- BELİRSİZ: Hoca yineleme değerlerini sözlü okumadı; tablodaki ara değerler python ile hesaplandı, slayttaki değerlerle karşılaştırılamadı. -->

Hoca bunu Türkçe de toparladı: Kuvvet yinelemesi belli sayıda yinelemeden sonra belli bir değere yakınsar. Elde edilen PageRank sütun vektörü, küçük web grafındaki bütün düğümlerin nihai PageRank skorlarını içerir.

## 9. Rastgele Yürüyüş Yorumu ve Durağan Dağılım

Hoca aynı şeyi başka bir bakış açısıyla, rastgele yürüyüş yorumuyla (random walk interpretation) anlattı.

### 9.1 Rastgele kullanıcı

Web'de gezinen rastgele bir kullanıcı (random surfer) düşünülür. Bu kişi tarayıcı kullanarak web'de dolaşır, ama tarayıcısında **geri tuşu yoktur**. Bir sayfadan başka sayfaya geçmenin tek yolu, sayfadaki bağlantıları izlemektir.

- $t$ anında kullanıcı $i$ sayfasındadır.
- $j$'ye giden bağlantıyı izlerse $t+1$ anında $j$ sayfasında olur.
- $i$'nin $d_i$ çıkış bağlantısı varsa, kullanıcı bunlardan birini düzgün rastgele (uniformly at random) seçer. $t+1$ anında $j$'de olma olasılığı $1/d_i$'dir.
- Bu süreç sonsuza kadar tekrarlanır.

### 9.2 Aynı formül, olasılık olarak

Hoca bu anlatımın şimdiye kadarki anlatımla aynı olduğunu vurguladı. Önceden "bağlantı veren düğüm skorunu çıkış bağlantısı sayısı oranında sonraki düğüme aktarır" denmişti. Örneğin y, a'ya bağlantı verir ve 2 çıkış bağlantısı olduğu için skorunu ikiye bölüp a'ya yansıtır.

Olasılık yaklaşımında $j$'de olma olasılığı şöyle hesaplanır: Bir önceki adımda $i$ sayfasında bulunma olasılığı $r_i$, $i$'den $j$'ye geçme olasılığı $1/d_i$ ile çarpılır. Bu, $j$'ye bağlantı veren bütün $i$'ler için yapılıp toplanır. Sonuç, kullanıcının $t+1$ anında $j$ düğümünde olma olasılığıdır.

$$p_j^{(t+1)}=\sum_{i\to j}\frac{p_i^{(t)}}{d_i}$$

> **Hocanın vurgusu:** Artık sıra skorundan değil, **olasılıktan** bahsediliyor. Kullanıcının herhangi bir anda herhangi bir düğümde bulunma olasılığı, PageRank formülünün aynısıyla hesaplanır.

Matris gösterimiyle $p^{(t+1)}=M\,p^{(t)}$ yazılır. Buradaki vektörlere sıra vektörü değil, olasılık vektörü (probability vector) denir.

### 9.3 Durağan dağılım

Kuvvet yinelemesi sürekli çalıştırıldığında, belli bir süre sonra $t$ anındaki olasılık vektörüyle $t+1$ anındaki olasılık vektörü birbirine eşit (ya da neredeyse eşit) olursa, bu vektöre **durağan dağılım** (stationary distribution) denir.

$$p^{(t+1)}=M\,p^{(t)}=p^{(t)}$$

Bu noktadan sonra vektörün değeri değişmez ve kuvvet yinelemesi durdurulabilir. Elde edilen olasılık vektörü, rastgele kullanıcının herhangi bir anda web grafındaki herhangi bir düğümde bulunma olasılığını verir. Böylece PageRank vektörü, kuvvet yinelemesinden sonra durağan dağılım vektörüne dönüşür.

### 9.4 Tekliğin koşulları

Bunun doğru olması, yani kuvvet yinelemesinin sonucunun **tek** (unique) bir durağan dağılım olması için grafın, dolayısıyla stokastik komşuluk matrisinin, bazı koşulları sağlaması gerekir. Bu bilgi rastgele yürüyüşler kuramından, diğer adıyla Markov zinciri süreçlerinden (Markov chain processes) gelir. Kuram şunu söyler: Elindeki graf bazı koşulları sağlıyorsa, kuvvet yinelemesinden sonra elde edilen sıra vektörü durağan dağılımdır, yani tektir; bu değerlerle her sayfanın PageRank'i bulunabilir. Hoca bu koşulları web grafındaki sorunlar üzerinden anlattı.

## 10. Web Grafındaki Sorunlar: Döngü, Çıkmaz Sokak, Örümcek Tuzağı

Hoca web grafında iki temel sorun olduğunu söyledi: örümcek tuzağı (spider trap) ve çıkmaz sokak (dead end).

### 10.1 İki düğümlü döngü: yakınsamama

Gerçek web grafında şöyle bir döngü görülebilir: a, b'ye bağlantı veriyor; b de a'ya bağlantı veriyor. Başlangıç değerleri $r_a=1$, $r_b=0$ seçilip kuvvet yinelemesi çalıştırılırsa:

| Yineleme | $r_a$ | $r_b$ |
|---|---|---|
| 0 | 1 | 0 |
| 1 | 0 | 1 |
| 2 | 1 | 0 |
| 3 | 0 | 1 |

Her yinelemede vektör değişir: bir kez $(1,0)$, bir kez $(0,1)$. Hiçbir zaman yakınsamaz. Bu yüzden durağan dağılım elde edilemez.

> **Ders sonrası not:** Hoca bu a↔b örneğini örümcek tuzağı olarak anlattı. Buradaki asıl sorun periyodikliktir (periodicity): Vektör iki durum arasında gidip gelir. Örümcek tuzağı ise, çıkış bağlantılarının hepsi kendi içinde kalan bir düğüm grubudur (Bölüm 10.3'teki m→m örneği). Kaynak slaytlarda bu örnek büyük olasılıkla "yakınsıyor mu?" sorusu için verilir.

### 10.2 Çıkmaz sokak: her şey sıfıra gider

İkinci sorun çıkmaz sokaktır: Bir düğüm başka bir düğüme bağlantı verir, ama o düğümün hiç çıkış bağlantısı yoktur. Küçük örnekte a→b var, b'nin çıkışı yok. Başlangıç $r_a=1$, $r_b=0$:

| Yineleme | $r_a$ | $r_b$ |
|---|---|---|
| 0 | 1 | 0 |
| 1 | 0 | 1 |
| 2 | 0 | 0 |

Bu kez yineleme yakınsar, ama istenmeyen bir şeye yakınsar. Düğümleri sıralayabilmek için skorlarda sayılar olmalıdır. Bütün skorlar 0 olursa sonuç işe yaramaz. Yani kuvvet yinelemesinin sonunda yakınsamak istiyoruz, ama **anlamlı** bir sıra vektörüne yakınsamak istiyoruz.

Hoca aynı sorunu üç düğümlü örnekte de gösterdi. Bu örnekte m'nin sütunundaki her değer sıfırdır; yani m'ye gelen kişi başka düğümlere gidemez. Başlangıç skorları $1/3$ seçilip kuvvet yinelemesi çalıştırılınca vektör yine yakınsar, ama bütün değerleri sıfırdır.

$$M=\begin{pmatrix}1/2&1/2&0\\1/2&0&0\\0&1/2&0\end{pmatrix}$$

Python ile: $r^{(1)}=(1/3,\ 1/6,\ 1/6)$, $r^{(2)}=(1/4,\ 1/6,\ 1/12)$ ve yineleme sürdükçe bütün değerler 0'a gider.

<!-- BELİRSİZ: Üç düğümlü çıkmaz sokak örneğinin bağlantıları altyazıda tek tek sayılmıyor; yalnız m'nin sütununun tamamen 0 olduğu söyleniyor. Yukarıdaki matris, büyük olasılıkla slayttaki y→y, y→a, a→y, a→m bağlantılı örnektir. -->

### 10.3 Örümcek tuzağı: bütün skor tek düğümde toplanır

Bu üç düğümlü örnekte m'nin yalnız kendine bir bağlantısı vardır (m→m). m'ye gelen biri, m dışında hiçbir yere gidemez. Bu bir örümcek tuzağıdır. Matriste de görülebilir: m'nin sütununda tek bir değer vardır ve o da m'nin kendisine aittir. Kullanıcı bu bağlantıyı izleyip m'ye gelirse grafın geri kalanına bir daha dönemez; sürekli m'de kalır.

$$M=\begin{pmatrix}1/2&1/2&0\\1/2&0&0\\0&1/2&1\end{pmatrix}$$

Başlangıç skorları ($1/3$) bu matrisle çarpılarak yineleme sürdürülürse vektör yine bir şeye yakınsar, ama bu düğümler arasında bir sıralama vermez. Python ile:

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 | 1/6 | 1/2 |
| 2 | 1/4 | 1/6 | 7/12 |
| 3 | 5/24 | 1/8 | 2/3 |
| ∞ | 0 | 0 | 1 |

Bütün skor m'de toplanır. Bu yüzden stokastik komşuluk matrisinde bazı değişiklikler yapılması gerekir ki kuvvet yinelemesi uygulandığında durağan dağılım elde edilsin.

## 11. Çözüm: Rastgele Işınlanma ve Google Matrisi

### 11.1 Örümcek tuzağı için rastgele ışınlanma

Çözüm rastgele ışınlanmadır (random teleport). Rastgele kullanıcı çoğu zaman bağlantıları izler, ama bazen web grafındaki herhangi bir sayfaya atlar:

- $\beta$ olasılıkla bir bağlantıyı izler.
- $1-\beta$ olasılıkla grafın herhangi bir sayfasına atlar.

Hoca bunu Türkçe şöyle açıkladı: Daha önce düğümler üzerinde hareket eden kişi yalnız bağlantıları izleyebiliyordu. Şimdi yeni bir şey eklenir: Herhangi bir anda bir düğümden istenen bir düğüme atlanabilir. Bunun için PageRank formülüne bir ekleme yapılır.

### 11.2 Çıkmaz sokak için sanal bağlantılar

Çıkmaz sokak sorunu için de ışınlanma kullanılır, ama farklı biçimde. Matriste çıkmaz sokak sorunu olan sütundaki her sıfırın yerine $1/N$ yazılır. Bu, çıkmaz sokağı oluşturan düğümden kendisi dahil mevcut bütün düğümlere **sanal bir bağlantı** konması demektir. Sanki m üzerinden bütün düğümlere artık gidilebiliyormuş gibi düşünülür. $N$ düğüm sayısıdır; örnekte 3 düğüm olduğu için $1/N=1/3$'tür. Slaytta bu sanal bağlantılar yeşil renkle gösterilmişti.

Matrisle bu ekleme şöyle yazılır:

$$A=M+\frac{1}{N}\,\mathbf{1}\,a^{T}$$

- $\frac{1}{N}\mathbf{1}$: bütün elemanları $1/N$ olan $N\times 1$ sütun vektörü. Hoca bunu bütün değerleri 1 olan vektörün $1/N$ ile çarpımı olarak anlattı.
- $a^{T}$: $1\times N$ satır vektörü. Bir düğüm dışarıya çıkış bağlantısı veriyorsa değeri 0, vermiyorsa 1'dir.

Bu iki vektörün çarpımı bir matris verir. Bu matrisin yalnız çıkmaz sokak düğümünün sütunu doludur, geri kalanı sıfırdır. Dolu sütundaki değerler $1/N$, örnekte $1/3$'tür. Bu matris, çıkmaz sokaklı $M$'ye eklendiğinde sonuç matrisi $A$ elde edilir. Örnekte (ara adım eklendi):

$$A=\begin{pmatrix}1/2&1/2&0\\1/2&0&0\\0&1/2&0\end{pmatrix}+\begin{pmatrix}0&0&1/3\\0&0&1/3\\0&0&1/3\end{pmatrix}=\begin{pmatrix}1/2&1/2&1/3\\1/2&0&1/3\\0&1/2&1/3\end{pmatrix}$$

Böylece çıkmaz sokaklı matris, çıkmaz sokağı olmayan **stokastik** bir matrise dönüşür. Python ile denetlendiğinde $A$'nın her sütununun toplamı 1'dir.

### 11.3 Işınlanmalı akış denklemi

Örümcek tuzağı için hoca akış denklemini şöyle değiştirdi. Önceki formülde $j$'nin PageRank'i, $j$'ye bağlantı veren düğümlerin oransal skorlarının toplamıydı. Şimdi:

- $\beta$ olasılıkla kullanıcı mevcut çıkış bağlantılarını izler ve $j$'ye gelir.
- $1-\beta$ olasılıkla $N$ sayfadan herhangi birine atlar; $j$'ye atlama olasılığı $(1-\beta)\frac{1}{N}$'dir.

$$r_j=\sum_{i\to j}\beta\,\frac{r_i}{d_i}+(1-\beta)\frac{1}{N}$$

İki terimin toplamı, örümcek tuzağı olan bir web grafında kullanıcının $j$ düğümünde olma olasılığını, yani $j$'nin sıra skorunu verir.

### 11.4 İki çözümün birleşimi: Google matrisi

İki çözüm matris gösteriminde birleştirilir. Çıkmaz sokak düzeltmesiyle stokastik hale gelmiş matris $\beta$ olasılıkla izlenir; $1-\beta$ olasılıkla da herhangi bir anda herhangi bir düğüme zıplanır. Bu, büyük $A$ matrisini verir:

$$A=\beta M+(1-\beta)\frac{1}{N}\mathbf{1}\mathbf{1}^{T},\qquad r=A\,r$$

Bu matris artık kuvvet yinelemesinde kullanılabilir. Çünkü $A$, Markov zinciri kuramının istediği türde bir matristir: stokastik, periyodik olmayan (aperiodic) ve indirgenemez (irreducible). Böyle bir matris üzerinde kuvvet yinelemesi çalıştırıldığında, belli bir yineleme sonunda değerleri değişmeyen bir PageRank vektörüne, yani durağan dağılıma ulaşılır.

> **Ders sonrası not:** Hoca "periyodik olmayan, yani içinde örümcek tuzağı yok; indirgenemez, yani içinde çıkmaz sokak yok" dedi. Daha doğru eşleştirme şudur: Çıkmaz sokaklar matrisin stokastik olmasını bozar ve sıfır sütunları $1/N$ ile doldurarak giderilir. Örümcek tuzakları matrisi indirgenebilir (reducible) yapar; a↔b gibi döngüler periyodikliğe yol açar. Işınlanma terimi her iki sorunu da giderir.

### 11.5 β nasıl seçilir?

$\beta$ genellikle 0,8 ile 0,9 arasında seçilir. Yani kullanıcı çok büyük olasılıkla mevcut çıkış bağlantılarını izleyerek sonraki sayfaya geçer, çok düşük bir olasılıkla da herhangi bir sayfaya atlar. Ama herhangi bir sayfaya atlayabilme yeteneği sayesinde örümcek tuzağı sorunundan kurtulunur.

Hoca bu formülün PageRank'in 1998'de yayımlanan makalesindeki formül olduğunu söyledi. Bu formülle, içinde hem örümcek tuzağı hem çıkmaz sokak olan graflarda bile belli bir yineleme sonunda sabit değerlere yakınsayan PageRank değerleri hesaplanabilir.

> **Ek bilgi (derste anlatılmadı):** Söz konusu makale, Google'ın kurucuları Sergey Brin ve Larry Page'in 1998'de yayımladığı "The Anatomy of a Large-Scale Hypertextual Web Search Engine" makalesidir. $A$ matrisine bu yüzden literatürde Google matrisi de denir. Özgün makalede $1-\beta$ yerine sönüm katsayısı (damping factor) $d$ kullanılır ve büyük olasılıkla $d=0{,}85$ önerilir.

### 11.6 Işınlanmalı örnek (β = 0,8)

Hoca son olarak, dersin başından beri kullanılan oyuncak örnek üzerinde PageRank'in son halinin uygulanışını gösterdi. Bu örnek, m'nin örümcek tuzağı olduğu graftır (y→y, y→a, a→y, a→m, m→m). $\beta=0{,}8$ seçildi: 0,8 olasılıkla mevcut bağlantılar izlenir, 0,2 olasılıkla herhangi bir sayfaya atlanır. İki matrisin birleşimi, kuvvet yinelemesinde kullanılacak matrisi verir:

$$A=0{,}8\begin{pmatrix}1/2&1/2&0\\1/2&0&0\\0&1/2&1\end{pmatrix}+0{,}2\begin{pmatrix}1/3&1/3&1/3\\1/3&1/3&1/3\\1/3&1/3&1/3\end{pmatrix}=\begin{pmatrix}7/15&7/15&1/15\\7/15&1/15&1/15\\1/15&7/15&13/15\end{pmatrix}$$

Ara adım (ara adım eklendi): $0{,}8\cdot\frac12+0{,}2\cdot\frac13=\frac{2}{5}+\frac{1}{15}=\frac{7}{15}$; $0{,}8\cdot 0+\frac{1}{15}=\frac{1}{15}$; $0{,}8\cdot1+\frac{1}{15}=\frac{13}{15}$.

Bu matris başlangıç skorlarıyla ($1/3$) çarpılır, sonraki değer bulunur ve yineleme sürdürülür. Python ile hesaplanan değerler:

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 ≈ 0,333 | 1/5 = 0,200 | 7/15 ≈ 0,467 |
| 2 | 7/25 = 0,280 | 1/5 = 0,200 | 13/25 = 0,520 |
| 3 | 97/375 ≈ 0,259 | 67/375 ≈ 0,179 | 211/375 ≈ 0,563 |
| ∞ | 7/33 ≈ 0,212 | 5/33 ≈ 0,152 | 21/33 ≈ 0,636 |

Yineleme ilerledikçe sonuçta elde edilen vektör artık değişmeyen, yakınsamış PageRank vektörüdür. m hâlâ en yüksek skoru alır, ama artık bütün skor m'de toplanmaz; y ve a da sıfırdan farklı skorlar alır ve düğümler sıralanabilir.

<!-- BELİRSİZ: Hoca yineleme değerlerini sözlü okumadı; tablodaki değerler python ile hesaplandı. Kısa nota göre slaytta 1. yinelemedeki r_m büyük olasılıkla 0,46 yazıyor; kesin değer 7/15 ≈ 0,467'dir. -->

## 12. PageRank'in Avantajları ve Eleştirisi

Hoca dersi PageRank'in avantajlarıyla kapattı:

- **Spam'e karşı dayanıklılık:** PageRank güvenilir sayfaları ayırt edebilir. PageRank vektörüne bakılarak web'deki bütün sayfalar popülerlik değerlerine göre sıralanabilir. Yüksek popülerlik değerine sahip sayfalar spam olmayan sayfalardır.
- **Sorgudan bağımsızlık (query independent):** PageRank skorları hesaplanırken yalnız bağlantı yapısı kullanıldı. Sayfaların verilen sorguyla ne kadar eşleştiğine hiç bakılmadı.

> **Hocanın vurgusu:** Sorgudan bağımsızlık aynı zamanda bir **eleştiri** olarak da konabilir. Diyelim ki bir sorgu girdiniz ve bu sorguya karşılık gelen 3-4 tane yüksek popülerliğe sahip sayfa var. Bunların arasında düşük PageRank'e sahip bir sayfa, bu sorgu için en otoriter (authoritative), yani en iyi sayfa olabilir. Ama yeterince bağlantı almadığı için PageRank skoru yüksek değildir ve sonuçlarda ilk sıralarda çıkmayabilir.

Buna karşılık sorguya bağımlı (query dependent) bir algoritma olan HITS gelecek hafta işlenecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:32:40): Atıf matrisinde iki makalenin sütunlarında aynı satırda yan yana duran 1'lerin sayısı artarsa bu ne anlama gelir?

> **Çözüm (derste verildi):** Her iki makaleye de aynı anda atıf veren makalelerin sayısı artmış demektir. Bu sayı, iki sütunun satır satır çarpılıp toplanmasıyla bulunur ve iki makale arasındaki ortak atıf değeridir: $C_{ij}=\sum_k L_{ki}L_{kj}$. Değer büyüdükçe ilişki güçlenir.

**Soru 2** (derste sözlü, 00:54:12): Örnek web grafında C düğümü yalnız bir giriş bağlantısı alıyor, ama PageRank skoru dört giriş bağlantısı alan E'ninkinden yüksek. Bu nasıl olur?

> **Çözüm (derste verildi):** Her bağlantı, onu veren düğümün önemini taşır. C'nin aldığı tek bağlantı, ağdaki en önemli düğümden geliyor. Önemli bir düğümden bağlantı almak, önemsiz düğümlerden çok sayıda bağlantı almaktan daha fazla skor kazandırır.

**Soru 3** (derste sözlü, 01:32:30): Rastgele kullanıcı $t$ anında $i$ düğümündeyse ve $i$'nin $d_i$ çıkış bağlantısı varsa, $t+1$ anında $j$ düğümünde olma olasılığı nedir?

> **Çözüm (derste verildi):** $i$'den $j$'ye bağlantı varsa olasılık $1/d_i$'dir, çünkü kullanıcı bağlantılardan birini düzgün rastgele seçer. $j$'de olmanın toplam olasılığı, $j$'ye bağlantı veren bütün $i$'ler için $p_i/d_i$ terimlerinin toplamıdır; bu PageRank'in akış denklemidir.

**Soru 4** (derste sözlü, 01:44:00): a→b ve b→a bağlantılı iki düğümlü grafta $r^{(0)}=(1,0)$ ile kuvvet yinelemesi neden sorun çıkarır?

> **Çözüm (derste verildi):** Yineleme $(0,1)$, $(1,0)$, $(0,1)$, ... diye iki durum arasında gidip gelir ve hiç yakınsamaz. Bu yüzden durağan dağılım elde edilemez. Python ile de aynı dizi elde edildi.

**Soru 5** (derste sözlü, 02:04:06): Işınlanmalı PageRank'te $\beta$ değeri nasıl seçilir?

> **Çözüm (derste verildi):** $\beta$ genellikle 0,8 ile 0,9 arasında seçilir. Kullanıcı büyük olasılıkla bağlantıları izler, küçük bir olasılıkla ($1-\beta$) herhangi bir sayfaya atlar. Bu küçük atlama olasılığı örümcek tuzağından kurtulmayı sağlar.

## Dersin Toparlaması

Ders, sosyal ağ analizindeki iki belge ilişkisi metriğiyle başladı. Ortak atıf, iki makaleye birlikte atıf veren makaleleri sayar ve atıf matrisinin iki sütununun iç çarpımıdır. Bibliyografik eşleşme ise iki makalenin ortak atıf yaptığı makaleleri sayar ve iki satırın iç çarpımıdır. İkisi de içerik benzerliğinin yanında, kaynakçaya dayalı bir benzerlik ölçüsü sağlar.

Ardından popülerliğe dayalı sıralamaya geçildi. PageRank, sıra prestijinin web grafına uyarlanmış halidir: Her düğüm skorunu çıkış bağlantılarına eşit paylaştırır ve bir düğümün skoru gelen oransal skorların toplamıdır. Bu akış denklemi $r=Mr$ biçiminde, özdeğeri 1 olan bir özvektör sistemidir ve kuvvet yinelemesiyle çözülür. Rastgele yürüyüş yorumunda PageRank vektörü, rastgele kullanıcının bir sayfada bulunma olasılığını veren durağan dağılımdır. Gerçek web grafındaki döngüler, çıkmaz sokaklar ve örümcek tuzakları bu dağılımın tek ve anlamlı olmasını engeller. Sıfır sütunları $1/N$ ile doldurmak ve $1-\beta$ olasılıklı rastgele ışınlanma eklemek, Brin ve Page'in formülünü, yani Google matrisini verir. PageRank spam'e dayanıklı ve sorgudan bağımsızdır; ama sorgudan bağımsızlık, sorgu için en otoriter sayfayı kaçırabilir. Bağlantı analizi bölümünde yalnız bu soruna sorguya bağımlı bir çözüm getiren HITS algoritması kaldı; sonraki haftalarda web kullanım madenciliği (web usage mining) ve fikir madenciliği (opinion mining) işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
