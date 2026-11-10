# Ders 10 Genişletilmiş Notu: Sosyal Ağ Analizi, Ağ Temsilleri ve Merkezilik Metrikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sosyal Ağ Analizi Neden Önemli?
- 2. Temel Terimler: Düğüm, Bağlantı, Yön ve Nitelikler
- 3. Sosyal Ağ Verisinin Üç Temsili
- 4. Derece, Derece Dizisi ve Derece Dağılımı
- 5. Bağlı Bileşenler
- 6. Bağlantı Analizine Dayalı Sıralamanın Doğuşu
- 7. Merkezilik Metrikleri ve Derece Merkeziliği
- 8. Arasındalık Merkeziliği
- 9. Yakınlık Merkeziliği
- 10. Merkezilik Metriklerinin Özeti ve Prestij Metriklerine Geçiş

## 1. Sosyal Ağ Analizi Neden Önemli?

Hoca derse, kitabın 7. bölümü olan Sosyal Ağ Analizi ve Bağlantı Analizi (Social Network Analysis and Link Analysis) konusuna geçtiğimizi söyleyerek başladı. Bu bölümün slaytları dönemin başında ders sayfasına konmuştu. Ders büyük ölçüde İngilizce anlatıldı. İlk soru şuydu: Sosyal ağ analizi bizim için neden önemli ve web madenciliğinde (web mining) onu nasıl kullanıyoruz?

### 1.1 Karmaşık ağ ve görselleştirme

Bir karmaşık ağda (complex network) düğümler ve düğümler arasında bağlantılar vardır. Bu ağın ayırt edici özelliği, bağlantıların özerk (autonomous) olarak oluşmasıdır. Hangi düğümün hangi düğümle ilişki kuracağına karar veren merkezi bir yer ya da merkezi bir otorite yoktur.

Sosyal ağ analizi böyle bir ağa uygulanır ve sonunda bir rapor üretilir. Hoca, sosyal ağ analizi raporlarının çoğunun görselleştirmeye (visualization) dayandığını vurguladı. Yani analizin sonucu bir çizim olarak sunulur. Örnek çizimde şunlar görülüyordu:

- Farklı renklerle boyanmış düğümler.
- Birbirinden yalıtılmış alt ağlar (isolated subnetworks).
- Düğümlerin büyük kısmını içeren dev bir alt ağ (giant subnetwork).
- Hiçbir düğümle bağlantısı olmayan ada düğümler (island nodes).

Böyle bir rapor, karmaşık ağda neler olup bittiği hakkında bilgi verir. Sosyal ağ analizinde yapılan iş budur: bağlantıları özerk olarak oluşmuş bir ağı anlamaya çalışmak.

### 1.2 Gazete terimleri ağı

Bilgisayar mühendisliğinde sosyal ağ analizi yeni çalışılıyor gibi görünse de, aslında uzun yıllardır yapılmaktadır. Hoca, bugünkü sosyal ağlar ortaya çıkmadan önce gazetelerden çıkarılmış bir analiz gösterdi. Bu çalışmada farklı gazetelerde geçen finans terimleri ve özel adlar düğüm olarak alınmış. İki terim aynı paragrafta ya da aynı haber yazısında geçiyorsa aralarına bir bağlantı konmuş. Böylece haber yazıları analiz edilerek, finans alanındaki terimlerin ve özel adların birbirine nasıl bağlandığını gösteren bir ağ kurulmuş.

### 1.3 İnternet ve Dünya Çapında Ağ

Sonraki çizim bir iletişim ağına, internete aitti. Hoca burada internet ile Dünya Çapında Ağ (World Wide Web) arasındaki farkı netleştirdi:

- **İnternet**, alttaki iletişim ağıdır. Üzerinde çok sayıda sunucu vardır ve hepsi bu iletişim ağıyla birbirine bağlıdır.
- **Web**, internetin üzerinde duran "yumuşak" (soft) bir ağdır. Düğümleri HTML belgeleridir. HTML belgelerindeki köprü bağlantıları (hyperlink) bir sayfayı başka bir sayfaya bağlar. Hoca bunlara yumuşak bağlantı (soft link) da dedi. Bu HTML sayfaları HTTP sunucularında ya da uygulama sunucularında (application server) durur.

Kısacası internet geniş alanlı bir iletişim ağıdır. Web ise onun üzerinde duran ayrı bir karmaşık ağdır. Hoca ardından internetin dünya üzerindeki bağlantılarının görselleştirmesini gösterdi.

### 1.4 ABD siyasi blogları

Hoca, gösterilen bütün resimlerin birer sosyal ağ analizi sonucu olduğunu ve hepsinin görselleştirmeyle sunulduğunu tekrar hatırlattı. Bu örnek, ABD'deki siyasi blog sitelerinin yansıttığı siyasi görüşe göre yapılmış bir analizdi. ABD'de iki büyük siyasi görüş vardır: Demokratlar ve Cumhuriyetçiler.

Çizimde bazı daireler diğerlerinden büyüktü. Bu, o blogların daha çok bağlantısı olduğu, yani ağlarında daha önemli oldukları anlamına gelir. Daha ilginç olan gözlem şuydu: Mavi bloglar mavi bloglara, kırmızı bloglar kırmızı bloglara bağlantı veriyor ve kendi aralarında kümeleniyordu. Aynı görüşteki bloglar birbirine bağlantı veriyor, karşı görüşe bağlantı vermek çok nadir görülüyordu. Bunun sonucu olarak, bir görüşü takip eden okurun karşı görüşün bakış açısını görmesi neredeyse imkânsızdı. Bu bilgi sosyal ağ analiziyle çıkarılabilen bir bilgidir.

### 1.5 Şirket e-posta ağı

Bu analiz bir şirketten alınmış e-posta verileri üzerinde yapılmıştı. Çizimde, kendi aralarında diğerlerine göre daha sık e-posta alışverişi yapan küçük kümeler görülüyordu. Ayrıca birçok farklı kümeye bağlantısı olan merkezi düğümler (central nodes) vardı.

Böyle bir analiz neden gerekir? Şirketin içinde insanların nasıl etkileştiği hakkında fikir verir. Hoca şöyle örnekledi: Şirketin genel müdürü (CEO) böyle bir sonuca sahipse, geçen bir ya da iki yılda şirketin içinde nasıl etkileşim olduğunu görebilir. E-posta üzerinden iletişim düzeyini anlar. İyileştirilmesi gereken bir şey varsa önlem alabilir.

### 1.6 Facebook ağı

Facebook'ta profil oluşturur, arkadaş ekler ve arkadaşlarımızı yakın arkadaş, iş arkadaşı gibi kategorilere ayırabiliriz. Analiz edilen Facebook ağında farklı alt ağlar farklı renklerle boyanmıştı. Düğüm büyüklükleri farklıydı ve büyük düğümler ağda diğerlerine göre daha önemliydi. Çizimde şunlar ayırt edilebiliyordu:

- Kırmızı ve mor gibi kendi içinde sıkı bağlı alt ağlar (highly connected subnetworks).
- Sarı olanlar gibi yalıtılmış alt ağlar. Bunlar kendi aralarında sıkı bağlı, ama dev alt ağa gevşek bağlıydı (loosely connected).

Bu, bir karmaşık ağın alt ağlarının birbirine nasıl bağlandığını anlamayı sağlar.

### 1.7 Yemek tarifi siteleri

Hoca bir görev örneği verdi: Bir ülkenin, örneğin İtalya'nın yeme alışkanlıklarını araştırmanız istensin. Yapılabilecek iş şudur:

- İtalya'ya ait yemek tarifi sitelerine gidilir ve hepsi taranır (crawl).
- Birbirine bağlantı veren tarif sitelerinden bir ağ kurulur.
- Sitelerden anahtar kelimeler çıkarılır. Hoca burada frekansın (frequency), yani terimin o sitede kaç kez geçtiğinin, önceki bölümlerden hatırlanmasını istedi.
- Frekansı yüksek anahtar kelimelerin yazı tipi büyütülerek bir sosyal ağ analizi çizimi oluşturulur.

Gösterilen çizime bakınca o ülkenin tariflerinde tuzun, yumurtanın, tereyağının ve soğanın önemli olduğu görülüyordu. Böylece bir ülkenin mutfağında hangi malzemelerin baskın olduğu anlaşılabilir.

Bu örneklerin hepsi karmaşık ağları anlamak için önemlidir. Web madenciliğinde ise HTML belgelerinin oluşturduğu karmaşık ağ incelenecektir. Amaç iki yönlüdür: Web sitelerinin sıralamasının (ranking) nasıl yapıldığını anlamak ve böyle raporları üretmek için kullanılan sosyal ağ analizi tekniklerini öğrenmek.

## 2. Temel Terimler: Düğüm, Bağlantı, Yön ve Nitelikler

### 2.1 Düğüm, bağlantı ve farklı disiplinlerdeki adları

Karmaşık ağda düğümler (nodes) ve bu düğümleri birbirine bağlayan bağlantılar (links) vardır. Hoca, sosyal ağ analizinin çok disiplinli (multidisciplinary) bir konu olduğunu belirtti. Matematikçiler, bilgisayar bilimciler, fizikçiler ve sosyologlar karmaşık ağları çalışır. Aynı kavram her alanda farklı adla anılır. Hocanın saydığı düğüm adları şunlardır:

| Alan | Düğümün adı |
|---|---|
| Matematik | köşe (vertex, çoğulu vertices) |
| Bilgisayar bilimi | düğüm (node) |
| Fizik | site |
| Sosyoloji | aktör (actor) |

Bilgisayar biliminde düğümler arasındaki kenarlara bağlantı (link) denir. Hoca, bağlantının da farklı alanlarda farklı adları olduğunu söyledi, ama bunları tek tek okumadı.

> **Ek bilgi (derste anlatılmadı):** Bu tür tablolarda bağlantı için genellikle şu adlar verilir: matematikte kenar (edge), fizikte bond, sosyolojide bağ (tie). Kısa notta da bu karşılıklar kullanılmıştır.

### 2.2 Yönlü ve yönsüz graf

Bir ağ yönlü (directed) ya da yönsüz (undirected) olabilir. Düğümler arasındaki bağlantıların bir yönü varsa ağa yönlü graf, yönü yoksa yönsüz graf denir.

Hoca burada öğrencilere bir soru sordu: LinkedIn yönlü bir graf mıdır, yönsüz mü? Cevapları sohbete yazmalarını istedi. Bir öğrenci "yönsüz", başka bir öğrenci "ikisi de" diye yazdı.

**Soru:** LinkedIn yönlü mü, yönsüz mü? **Cevap:** Yönsüzdür. Çünkü bağlantıyı kimin başlattığını, yani ilk bağlantı isteğini hangi kişinin gönderdiğini anlayamazsınız.

Hoca ardından iki örnek daha verdi:

- **Twitter** yönlüdür. İnsanlar birbirini takip eder. Takip eden (follower) ile takip edilen (followee) bellidir.
- **Facebook** normalde yönsüzdür, çünkü orada da arkadaşlığı kimin başlattığı anlaşılmaz. Ama Facebook'ta bir de takip (follow) özelliği vardır. İnsanların sayfalarını takip edebilirsiniz. Bu yüzden Facebook için hem yönlü hem yönsüz denebilir.

Genel kural şudur: Bir sosyal ağda bağlantıyı ilk kimin verdiğini anlamanın bir yolu varsa yönlü graf, yoksa yönsüz graf denir.

### 2.3 Bağlantı nitelikleri

Bağlantıların farklı nitelikleri (attributes) olabilir. Hoca bunları ağırlık (weight), sıra (ranking), tür (type) ve diğer özellikler olarak saydı.

**Ağırlık:** İki düğüm birbiriyle iletişim kuruyor ve iletişim sıklığı çok yüksekse, aralarındaki bağlantının ağırlığı yüksek olur. İletişim azsa ağırlık düşük olur. Hoca iki veri türü örneği verdi:

- Veri bir telekom verisiyse (CDR, çağrı kaydı), iki kişi arasındaki telefon görüşmesi sıklığı ağırlık olarak kullanılabilir.
- Veri bir e-posta veri kümesiyse, iki kişi arasında gönderilen e-posta sıklığı ağırlık olarak kullanılabilir.

**Tür:** Facebook'ta bağlantılarınızı en iyi arkadaş, yakın arkadaş, okul arkadaşı, akraba gibi kategorilere ayırabilirsiniz. Bu, tür niteliğidir.

**Sıra:** Aynı türün içinde, örneğin "arkadaş" kategorisinde, arkadaşlarınızı sıralayabilirsiniz: birinci en iyi arkadaş, ikinci en iyi arkadaş, üçüncü en iyi arkadaş. Yani bağlantıları hem kategorilere ayırabilir hem de sıralayabilirsiniz.

Hoca sıra niteliğinin kullanıldığı bir örnek gösterdi. Yurtta kalan öğrencilere yemek masasında kiminle oturmak istedikleri sorulmuş. Herkes bir birinci, bir ikinci tercih belirtmiş. Böylece her kişiden iki bağlantı çıkan bir ağ kurulmuş: biri birinci tercihi, öbürü ikinci tercihi gösteriyor. Her bağlantıya 1 ya da 2 değerinde bir sıra niteliği verilmiş. Analiz, bazı kişilerin çok popüler olduğunu, yani birçok kişi tarafından yemek masası arkadaşı olarak seçildiğini gösteriyordu.

İkinci örnek güven ve güvensizlik (trust/distrust) ağıydı. Bir kurumdaki her kişiye ağındaki diğer kişilere güvenip güvenmediği sorulmuş. Bağlantıya güvenilen ya da güvenilmeyen niteliği verilmiş. Kırmızı bağlantılar güvensizliği, mavi bağlantılar güveni gösteriyordu. Hoca, bu kurumda çözülmesi gereken büyük miktarda güvensizlik olduğunun çizimden görüldüğünü söyledi.

## 3. Sosyal Ağ Verisinin Üç Temsili

Düğümleri, bağlantıları ve bağlantı niteliklerini konuştuktan sonra hoca, bir sosyal ağ verisinin nasıl temsil edileceğine geçti. Üç yol vardır:

- Komşuluk matrisi (adjacency matrix).
- Kenar listesi (edge list).
- Komşuluk listesi (adjacency list).

### 3.1 Komşuluk matrisi

Ağ bir matrisle temsil edilir. $i$ düğümünden $j$ düğümüne bir bağlantı varsa matrisin $a_{ij}$ elemanına 1, yoksa 0 yazılır:

$$a_{ij}=\begin{cases}1 & i\text{'den } j\text{'ye bağlantı varsa}\\ 0 & \text{yoksa}\end{cases}$$

İki özel durum vardır:

- **Kendine bağlantı (self loop):** Bazı düğümler kendilerini gösterebilir. Böyle bir döngü varsa $a_{ii}=1$, yoksa $a_{ii}=0$ yazılır.
- **Yönsüz graf:** İki düğüm birbirine karşılıklı bağlantı veriyorsa bu yönsüz bir bağlantıdır. Çizimde iki oklu çizgi yerine tek düz çizgiyle de gösterilebilir. Bu durumda $a_{ij}=a_{ji}$ olur.

### 3.2 Beş düğümlü örnek

Hoca beş düğümlü bir oyuncak örnek (toy example) gösterdi. Beş düğüm olduğu için matris 5 satır ve 5 sütundan oluşur. Grafın bağlantıları şunlardır: 2→3, 2→4, 3→2, 3→4, 4→5, 5→1, 5→2.

$$A=\begin{pmatrix}0&0&0&0&0\\0&0&1&1&0\\0&1&0&1&0\\0&0&0&0&1\\1&1&0&0&0\end{pmatrix}$$

Hoca matrisi okumayı 5. düğüm üzerinden gösterdi. 5. düğüm 1. ve 2. düğümlere bağlantı verir. Bu yüzden 5. satırın 1. ve 2. sütunlarında 1 vardır, satırın geri kalanı 0'dır. 1. düğüm ise hiçbir düğüme bağlantı vermez. Bu yüzden 1. satırın bütün elemanları 0'dır.

### 3.3 Kenar listesi

İkinci temsilde matris yerine bir liste kullanılır ve ağda görünen bütün bağlantılar tek tek yazılır. Aynı örnek için liste şudur:

- (2, 3)
- (2, 4)
- (3, 2)
- (3, 4)
- (4, 5)
- (5, 1)
- (5, 2)

(2, 3) ve (3, 2) ayrı satırlardır. Biri bir yöndeki bağlantıyı, öbürü ters yöndekini gösterir. Liste sözlük sırasıyla (lexicographical order) yazılır. İlk elemanı en küçük olan bağlantılardan başlanır ve ilk eleman artarak ilerlenir.

> **Ders sonrası not:** Hoca bağlantıları sayarken "bir, iki, üç, dört, altı; yedi bir yönde, sekiz öbür yönde" dedi. Grafta toplam 7 yönlü bağlantı vardır ve kenar listesi 7 satırdır. 2 ile 3 arasındaki karşılıklı bağlantı iki ayrı kenar sayılır.

### 3.4 Komşuluk listesi

Üçüncü temsilde bütün düğümler alt alta yazılır ve her birinin yanına iki nokta konur. Düğümün bağlantı verdiği düğümler iki noktanın sağına yazılır. 1. düğüm hiçbir düğüme bağlantı vermediği için yanı boştur.

```
1:
2: 3, 4
3: 2, 4
4: 5
5: 1, 2
```

<!-- BELİRSİZ: Hoca 3., 4. ve 5. satırları okurken altyazı bozuk ("for three, four and four and four, five"). Liste, kenar listesinden ve komşuluk matrisinden kuruldu. -->

## 4. Derece, Derece Dizisi ve Derece Dağılımı

Hoca, bir sosyal ağda neler olup bittiğini özetleyen metriklere geçti. İki metrik incelendi: derece ve derece dağılımı, bir de bağlı bileşenler.

### 4.1 Derece, giriş derecesi ve çıkış derecesi

Derece (degree), bir düğümün kaç bağlantısı olduğunu söyler. Hoca bir analiz çiziminde bazı düğümlerin bir, bazılarının iki, bazılarının çok daha fazla bağlantısı olduğunu gösterdi. Görselleştirmede bağlantısı çok olan düğüm daha büyük bir daireyle çizilir. Bu, o düğümün ağdaki diğer düğümlere göre daha önemli olduğunu gösterir.

Üç kavram vardır:

- **Giriş derecesi (in-degree):** Düğümün diğer düğümlerden aldığı bağlantı sayısı, yani giriş bağlantılarının (in-links) sayısı.
- **Çıkış derecesi (out-degree):** Düğümün diğer düğümlere verdiği bağlantı sayısı, yani çıkış bağlantılarının (out-links) sayısı.
- **Derece:** Bağlantının yönüne bakılmaksızın düğümün toplam bağlantı sayısı.

Giriş ve çıkış derecesi yönlü graflarda kullanılır. Derece hem yönlü hem yönsüz graflarda kullanılır. Hocanın örneğindeki düğüm 3 bağlantı alıyor ve 2 bağlantı veriyordu. Giriş derecesi 3, çıkış derecesi 2, derecesi ise $3+2=5$'tir.

Hoca, bir düğümün önemini anlamak için şimdilik dereceyi kullanacağımızı, buna derece merkeziliği (degree centrality) diyeceğimizi söyledi. İleride arasındalık (betweenness) ve yakınlık (closeness) gibi başka metrikler de görülecekti.

### 4.2 Dereceyi komşuluk matrisinden hesaplamak

Komşuluk matrisinde satır etiketleri bağlantıyı veren düğümleri, sütun etiketleri bağlantıyı alan düğümleri gösterir. Örneğin 5. satır 1. sütundaki 1, 5. düğümün 1. düğüme bağlantı verdiğini gösterir. Buradan iki kural çıkar:

- Bir satırdaki 1'ler o düğümün verdiği çıkış bağlantılarıdır. Satır toplamı çıkış derecesini verir:

$$d_{\text{out}}(i)=\sum_{j=1}^{n} a_{ij}$$

- Bir sütundaki 1'ler o düğümün aldığı giriş bağlantılarıdır. Sütun toplamı giriş derecesini verir:

$$d_{\text{in}}(j)=\sum_{i=1}^{n} a_{ij}$$

Hoca 3. düğüm üzerinden hesapladı. 3. satırda iki tane 1 vardır: biri 2. sütunda, biri 4. sütunda. Yani 3. düğüm 2. ve 4. düğümlere bağlantı verir ve çıkış derecesi 2'dir. 3. sütunda ise tek bir 1 vardır (2. satırda). Yani 3. düğüm yalnız 2. düğümden bağlantı alır ve giriş derecesi 1'dir.

Bütün örnek için (ara adım eklendi):

| Düğüm | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| Çıkış derecesi (satır toplamı) | 0 | 2 | 2 | 1 | 2 |
| Giriş derecesi (sütun toplamı) | 1 | 2 | 1 | 2 | 1 |

Satır toplamlarının ve sütun toplamlarının ikisi de 7'dir. Bu, kenar sayısına eşittir.

### 4.3 Derece dizisi ve derece dağılımı

Giriş ve çıkış dereceleri hesaplanabiliyorsa, ağın derece dizisi (degree sequence) yazılabilir. Hoca iki yalıtılmış parçadan oluşan, toplam 8 düğümlü bir ağ gösterdi ve her düğümün giriş derecesini yazdı:

- 3 düğüm 2 giriş bağlantısı alıyor.
- 4 düğüm 1 giriş bağlantısı alıyor.
- 1 düğüm hiç bağlantı almıyor.

Çıkış derecesi için de aynısı yapıldı:

- 4 düğümün 2 çıkış bağlantısı var.
- 3 düğümün 1 çıkış bağlantısı var.
- 1 düğüm hiçbir düğüme bağlantı vermiyor.

Aynısı yönden bağımsız derece için de yapılabilir. Bu durumda her düğümün bağlantıları yönüne bakılmadan sayılır.

Derece dizilerinden derece dağılımı (degree distribution) yazılır. Dağılım, her derece değerinden kaç düğüm olduğunu gösterir. Örnekteki giriş derecesi dağılımı şudur: giriş derecesi 2 olan 3 düğüm, 1 olan 4 düğüm, 0 olan 1 düğüm. Çıkış derecesi ve yönsüz derece için de dağılım çizilebilir.

Bunlar neden gerekir? Hoca dersin başına döndü: Sosyal ağın neye benzediğini, bağlantı yapısının nasıl olduğunu daha iyi anlamak için derece dizileri ve derece dağılımı grafikleri kullanılır.

## 5. Bağlı Bileşenler

İkinci metrik bağlı bileşenlerdir (connected components). Bu metrik şu sorulara cevap verir: Ağdaki her şey birbirine bağlı mı? Yalıtılmış adalar var mı? Hiçbir düğüme bağlantı vermeyen aykırı (outlier) düğümler var mı? Çok sayıda düğüm içeren, sıkı bağlı büyük bir bileşen var mı?

Bu metrikle üç şey belirlenir:

- Güçlü bağlı bileşenler (strongly connected components).
- Zayıf bağlı bileşenler (weakly connected components).
- Dev bileşen (giant component).

Hoca yine iki yalıtılmış alt ağdan oluşan 8 düğümlü örneği kullandı.

**Güçlü bağlı bileşen:** Tanım şudur: Bileşendeki her düğüme, bileşendeki diğer her düğümden ulaşılabilir. Örnekte B, E, D, C düğümlerinden oluşan alt ağda her düğüme diğer her düğümden ulaşılabildiği için bu alt ağ güçlü bağlı bir bileşendir. J ve H de aynı şekilde güçlü bağlı bir bileşen oluşturur. Kalan A ve F tek elemanlı bileşenlerdir. Bunlar tek elemanlı güçlü bağlı bileşen olarak da düşünülebilir.

**Zayıf bağlı bileşen:** Hoca örnekteki iki alt ağın ikisinin de zayıf bağlı bileşen olduğunu gösterdi. Birinci alt ağda A, B, C, D, E düğümlerinin her birine diğer düğümlerden ulaşılabiliyordu. İkinci alt ağda F'den başlanınca H'ye ve G'ye ulaşılabiliyordu.

> **Ders sonrası not:** Hoca zayıf bağlı bileşenin tanımını "her düğüme diğer her düğümden, bağlantıları tek bir yönde izleyerek ulaşılabilir" diye okudu. Yaygın tanım şudur: Bağlantıların yönü göz ardı edildiğinde bileşendeki her düğüme diğer her düğümden ulaşılabilir. Kısa nottaki tanım da budur. Örnekteki sonuç bu tanımla da aynıdır.

<!-- BELİRSİZ: İkinci alt ağda güçlü bağlı bileşen J–H olarak, zayıf bağlı bileşen örneğinde ise F, H, G olarak geçiyor. Altyazıda J ile G karışmış olabilir. Şekil olmadan düğüm adları kesinleştirilemedi. -->

**Dev bileşen:** Sosyal ağda düğümlerin önemli bir kısmını içeren bir alt ağ varsa buna dev bileşen denir.

Hoca bu bölümü şöyle bağladı: Derece dizisi ve derece dağılımı ile bağlı bileşenler (güçlü, zayıf, dev), ağı görselleştirmeden bile bağlantı yapısının neye benzeyeceğini anlamayı sağlar. Ara vermeden önceki özet şuydu: Sosyal ağların üç temsilini ve bağlantı yapısını görselleştirmeden anlamayı sağlayan iki metriği öğrendik.

## 6. Bağlantı Analizine Dayalı Sıralamanın Doğuşu

Aradan sonra hoca, düğümlerin önemini belirleyen metriklerin ayrıntısına girmeden önce bağlantı analizinin (link analysis) neden ortaya çıktığını anlattı.

Sosyal ağ analizini web verisinde özellikle sıralama yapmak için kullanırız. 6. bölümde, içerik madenciliği yani bilgi erişimi (information retrieval) bölümünde, TF-IDF gibi benzerliğe dayalı sıralama yöntemlerini görmüştük. TF-IDF, sorgu ile belge arasındaki benzerliği ölçer ve her belgeye o sorguya ne kadar benzediğini gösteren bir puan verir. Web sayfaları bu puana göre sıralanabilir. Arama motorları bu yöntemi uzun yıllar kullandı.

Hocanın anlatımına göre 1997–1998'e kadar TF-IDF'e dayalı sıralama işe yarıyordu, ama iki önemli zayıflığı vardı:

- **Spam sayfalar fark edilemiyordu.** Sayfa sahipleri sayfalarına sitenin kendisini temsil etmeyen anahtar kelimeler koyuyordu. Amaç birçok farklı sorgunun sonuçlarında görünmekti.
- **Popülerlik ölçülemiyordu.** Sonuçlar benzerliğe göre sıralanabiliyordu, ama hangi sayfanın diğerlerinden daha popüler olduğu anlaşılamıyordu.

Bu yüzden 1997 ve 1998 yıllarında bağlantı analizine dayalı sıralama yöntemleri üzerinde çalışıldı. İki çalışma öne çıktı:

- **Cornell'den HITS algoritması.** Hoca, bunun daha sonra Yahoo tarafından kullanıldığını söyledi.
- **Stanford'dan PageRank algoritması.** Bu algoritma daha sonra Google tarafından kullanıldı.

İkisi de aynı fikre dayanır: Bir sayfa birçok sayfadan bağlantı alıyorsa, o sayfanın prestiji (prestige) ya da otoritesi (authority) yüksektir. Bir sorguya uyan arama sonuçları bu prestije, yani popülerliğe göre sıralanabilir. Bu iki algoritma web sayfalarının prestijini hesaplar. Bölümün devamında, bu prestiji hesaplamak için kullanılan sosyal ağ analizi metrikleri öğrenilecekti.

> **Ders sonrası not:** HITS'i Jon Kleinberg (Cornell) büyük olasılıkla 1998'de yayımladı, dergi sürümü 1999'da çıktı. PageRank makalesi de büyük olasılıkla 1998 tarihlidir. HITS'in ticari kullanımı en çok Teoma (sonradan Ask.com) arama motoruyla bilinir. Yahoo'nun HITS kullandığına dair yaygın bir kaynak büyük olasılıkla yoktur.

Sosyal ağ analizi yalnız sıralama için kullanılmaz. Hoca diğer kullanım alanlarını da saydı:

- Topluluk keşfi (community discovery): bir sosyal ağdaki alt toplulukları belirlemek.
- E-posta analizi.
- Facebook ya da LinkedIn gibi sosyal ağların analizi: insanların nasıl bağlandığı, alt ağların neler olduğu, profillerin siyasi görüşleri gibi.

Düğümlerin (aktörlerin) önemini belirlemek için iki metrik kategorisi kullanılır: merkezilik metrikleri (centrality metrics) ve prestij metrikleri (prestige metrics). Bu derste merkezilik metrikleri işlendi.

## 7. Merkezilik Metrikleri ve Derece Merkeziliği

### 7.1 Derece merkeziliğiyle görselleştirme

Hoca başka bir slayt setine geçti. İlk çizim oyuncak bir sosyal ağdı ve iki düğüm (Kimball ve Gerard) daha büyük dairelerle çizilmişti. Bunun nedeni, çizimde derece merkeziliğinin kullanılmasıdır. Bir düğümün bağlantısı ne kadar çoksa dairesi o kadar büyük olur. İkinci ve üçüncü örneklerde de bağlantısı çok olan düğümler büyük çizilmişti.

Üçüncü örnekte bazı bağlantılar diğerlerinden daha kalın çizilmişti. Bunun nedeni, o iki düğüm arasındaki iletişim sayısının daha yüksek olmasıdır. Hoca burada bağlantı niteliklerini hatırlattı. Bu örnekte ağırlık, iletişim düzeyiyle ilişkilendirilmişti.

Derece merkeziliği üç merkezilik metriğinden biridir. Diğer ikisi arasındalık ve yakınlıktır.

- **Yönsüz grafta** derece merkeziliği, düğümün toplam bağlantı sayısıdır.
- **Yönlü grafta** derece merkeziliği genellikle düğümün çıkış bağlantılarının sayısıdır.

### 7.2 Orkut örneği: derece tek başına yetmez

Hoca bir küçük graf gösterdi. Bu grafta Orkut adlı düğümün diğer düğümlere göre çok fazla bağlantısı vardı. Örneğin kırmızı düğümün yalnız 3 bağlantısı varken Orkut'a çok daha fazla bağlantı bağlıydı. Derece merkeziliğine göre bu küçük grafta Orkut'un önemi yüksektir. Bu doğrudur.

Ama bu, Orkut'un kendi ağında önemli olduğunu söylemeye yeter mi? Hoca bütün ağı gösterdi. Orkut ağın kenarında duruyordu. Ağın ortasındaki düğümler kadar önemli bir konumda değildi. Derece merkeziliği büyük olabilir, ama:

- Ağın geri kalanına yakın değildir.
- Ağın büyük kısmında birçok düğümün arasında durmaz.

Bu yüzden derece merkeziliğine ek olarak arasındalık merkeziliği (betweenness centrality) ve yakınlık merkeziliği (closeness centrality) gerekir.

### 7.3 Giriş derecesi ve çıkış derecesiyle merkezilik: petrol ticareti

Hoca önce giriş derecesine dayalı bir örnek gösterdi. Örnekteki iki düğümden X'in giriş derecesi 5, Y'ninki 0'dı, çünkü Y hiç giriş bağlantısı almıyordu.

Ardından petrol ticaretini gösteren bir graf geldi. Her düğüm bir ülkeydi. Bazı kenarlar diğerlerinden kalındı ve bu, iki ülke arasındaki ticaret miktarının daha büyük olduğunu gösteriyordu. Çizim giriş derecesine göre yapılmıştı:

- ABD Kanada, Meksika, Venezuela, Irak, Suudi Arabistan gibi ülkelerden petrol alıyordu.
- Japonya Suudi Arabistan ve Birleşik Arap Emirlikleri'nden petrol alıyordu.

**Soru:** Hangi ülkelerin giriş derecesi yüksektir? **Cevap:** ABD ve Japonya.

Hoca, çoğu durumda derece merkeziliği için çıkış derecesinin kullanıldığını tekrarladı. Aynı graf bu kez çıkış derecesine göre çizildi. Bu çizimde Suudi Arabistan büyük bir düğüm olarak görünüyordu, çünkü birçok ülkeye petrol satıyordu. Suudi Arabistan Japonya'ya ve ABD'ye büyük miktarlarda, Venezuela da ABD'ye büyük miktarda satıyordu. Venezuela yalnız ABD'ye satıyordu, Japonya'ya satmıyordu. Birleşik Arap Emirlikleri hem Japonya'ya hem Kore'ye satıyordu.

İki çizimin farkı şudur: Çıkış derecesine göre çizimde çok çıkış bağlantısı olan düğüm büyük çizilir. Giriş derecesine göre çizimde çok giriş bağlantısı alan düğüm büyük çizilir. İkinci çizimden Suudi Arabistan'ın dünyadaki ana petrol satıcısı olduğu anlaşılır.

<!-- BELİRSİZ: Hoca X ve Y örneğine çıkış derecesi açısından dönüp "X'in değeri 5, Y'ninki 1" dedi. Giriş derecesi örneğinde Y'nin değeri 0'dı. Şekil olmadan çıkış derecelerinin doğruluğu kontrol edilemedi. -->

### 7.4 Normalize derece merkeziliği

Hoca derece merkeziliğini sayılarla gösterdi ve normalize etti. Normalize etmek için düğümün derecesi $n-1$'e, yani kendisi dışındaki düğüm sayısına bölünür:

$$C_D(i)=\frac{d(i)}{n-1}$$

Yönlü grafta $d(i)$ yerine çıkış derecesi kullanılır. Üç oyuncak örnek çözüldü:

- **Yıldız (6 düğüm):** Ortadaki düğümün 5 bağlantısı var. $C_D=\frac{5}{6-1}=\frac{5}{5}=1$. Uçtaki düğümlerin her birinin 1 bağlantısı var. $C_D=\frac{1}{5}=0{,}2$.
- **7 düğümlü graf:** Ortadaki düğümün 2 bağlantısı var. Toplam 7 düğüm olduğu için $n-1=6$. $C_D=\frac{2}{6}\approx0{,}33$.
- **5 düğümlü graf:** Ortadaki düğümün 2 bağlantısı var. $n-1=4$. $C_D=\frac{2}{4}=0{,}5$. Hoca, aynı grafta 2 bağlantılı başka bir düğüm için de $\frac{2}{4}=0{,}5$ olduğunu gösterdi.

Böylece ağdaki her düğüm için derece merkeziliği hesaplanabilir.

### 7.5 Bütün ağın derece merkezileşmesi

Derece merkeziliği her düğüm için hesaplandığı gibi, bütün ağ için de bir değer hesaplanabilir. Buna derece merkezileşmesi (degree centralization) denir. Hocanın anlattığı adımlar şunlardır:

- Ağdaki en büyük derece merkeziliği değeri bulunur.
- Diğer bütün düğümlerin değerleri bu en büyük değerden tek tek çıkarılır.
- Bu farkların toplamı pay olur.
- Payda $(n-1)(n-2)$'dir.

$$C_D=\frac{\sum_{i=1}^{n}\left[d_{\max}-d(i)\right]}{(n-1)(n-2)}$$

Bu değer normalize edilmiştir, yani 0 ile 1 arasındadır. Yorumu şudur:

- **Yıldız ağda** değer 1'dir. Ağda tek bir ana düğüm vardır ve diğer bütün düğümler onun etrafındadır.
- **Birden fazla önemli düğüm varsa** değer küçülür ve 0'a yaklaşır.

Hoca iki ağı karşılaştırdı. Birinde en yüksek derece merkeziliğine sahip tek bir büyük düğüm vardı. Bu ağın merkezileşmesinin 1'e yakın olması beklenir. Öbüründe en yüksek değere sahip en az üç düğüm vardı. Bu ağın merkezileşmesi daha küçük olmalıdır.

Yıldız ağ için hesap (ara adım eklendi): Ham derecelerle $d_{\max}=5$'tir. Beş uç düğümün her biri için fark $5-1=4$, merkez için $0$'dır. Pay $5\cdot4=20$, payda $(6-1)(6-2)=20$'dir. Sonuç $\frac{20}{20}=1$'dir.

> **Ders sonrası not:** Hoca hesabı normalize değerlerle anlattı ($1-0{,}2$ farklarını toplayıp $(n-1)(n-2)$'ye böldü). Ayrıca farkların toplamına "payda" dedi, oysa bu toplam paydır. $(n-1)(n-2)$ paydası ham derecelerle (5, 1, …) kullanılır. Normalize değerlerle çalışılıyorsa payda $n-2$ olmalıdır. Yıldız ağda iki yol da 1 verir: $\frac{5\cdot4}{5\cdot4}=1$ ve $\frac{5\cdot0{,}8}{4}=1$. Normalize değerleri $(n-1)(n-2)$'ye bölmek bu ağda $0{,}2$ verirdi.

### 7.6 Derece merkeziliğinin yakalayamadığı şey

Hoca, derece merkeziliğinin neyi yakalayamadığını üç örnekle gösterdi.

İlk örnek yıldızdı. Ortada büyük bir düğüm, etrafında diğerleri vardı. Bu küçük ağda derece merkeziliği ortadaki düğümün önemini doğru yakalar.

İkinci örnek 7 düğümlü grafıydı. Ortadaki düğümün derecesi 2, yanındaki iki düğümün derecesi 3'tü. Derece merkeziliğine göre yandaki düğümler daha önemli görünür. Ama aslında ortadaki düğüm daha önemlidir, çünkü birçok iletişimin ortasındadır:

- Bir taraftaki düğümlerden biri öbür taraftaki 3 düğümle iletişim kurmak isterse ortadaki düğümden geçmek zorundadır. Bu 3 iletişim eder.
- Aynısı o taraftaki diğer düğümler için de geçerlidir.
- Sonuçta ortadaki düğüm 9 farklı çiftin iletişiminin ortasındadır.

Yandaki düğüm ise bir yanındaki 2 düğüm ile öbür yanındaki 4 düğüm arasındaki iletişimin ortasındadır. Bu da 8 çift eder. Demek ki ortadaki düğüm daha önemli olmalıdır. Ayrıca ortadaki düğüm, ortalamada diğer düğümlere daha yakındır. Ondan başlayınca geri kalan düğümlere ulaşmak daha kolaydır.

Böylece iki bakış açısı ortaya çıkar:

- **Arasındalık:** Düğüm birçok farklı iletişimin ortasındadır.
- **Yakınlık:** Düğüm ortalamada diğer düğümlere yakındır.

Derece merkeziliği bu iki özelliği yakalamaz. Üçüncü küçük ağda da aynı durum vardı: Ortadaki düğümün derecesi yanındakilerle aynıydı, ama ortada olduğu için geri kalan düğümlere kolayca ulaşıyor ve birçok çiftin iletişiminin arasında duruyordu. Orkut örneği de aynı şeyi gösterir: Derecesi yüksektir, ama birçok iletişimin arasında değildir ve düğümlerin çoğuna yakın değildir.

<!-- BELİRSİZ: 7 düğümlü grafın şekli altyazıda yok. Anlatılan sayılar (orta düğümün derecesi 2, yanındakilerin 3; arasındalık 9 ve 8) iki üçgenin ortadaki bir düğümle birleştirildiği grafla tutarlıdır. Python ile bu grafta orta düğüm için 9, yandaki düğümler için 8 bulundu. -->

## 8. Arasındalık Merkeziliği

### 8.1 Sezgi: X ve Y

Hoca iki düğümü (X ve Y) olan küçük bir örnek gösterdi ve hangisinin daha önemli olduğunu sordu. Cevap X'ti, çünkü X dört farklı çiftin ortasındaydı. Bir düğüm iki düğümle X üzerinden, Y de iki düğümle X üzerinden iletişim kuruyordu. Y ise üç farklı çiftin ortasındaydı. Hoca bir ek gözlem yaptı: Y'nin yanındaki düğüm Y'yi atlayıp geri kalan üç düğümle doğrudan da iletişim kurabiliyordu. Bu yüzden Y'nin hiçbir çiftin ortasında olmadığı da düşünülebilir. Sonuç olarak arasındalık açısından X, Y'den daha önemlidir.

<!-- BELİRSİZ: X ve Y örneğinin şekli altyazıda yok. Y için "3 çift" ve "0 çift" yorumlarından hangisinin şekle uyduğu kesinleştirilemedi. -->

### 8.2 Formül

Arasındalık merkeziliği hesaplanırken, birbirine ulaşmak için $i$ düğümünden geçmek zorunda olan düğüm çiftleri sayılır. İki düğüm $j$ ve $k$ arasında birden fazla en kısa yol olabilir. Bunların bazıları $i$'den geçer, bazıları geçmez. Bu yüzden her çift için $i$'den geçen yolların oranı alınır ve bütün çiftler üzerinden toplanır:

$$C_B(i)=\sum_{j<k}\frac{p_{jk}(i)}{p_{jk}}$$

- $p_{jk}$: $j$ ile $k$ arasındaki en kısa yolların toplam sayısı.
- $p_{jk}(i)$: bu yollardan $i$'den geçenlerin sayısı.

Normalize etmek için bu değer, $i$ dışındaki düğümlerden oluşturulabilecek çift sayısına bölünür:

$$C_B'(i)=\frac{2\,C_B(i)}{(n-1)(n-2)}$$

Hoca slayttaki formülde 2'nin paya yazıldığını, ama özünde değerin $\frac{(n-1)(n-2)}{2}$'ye bölündüğünü belirtti.

> **Hocanın vurgusu:** Formülleri ezberlemenizi istemiyorum. Arasındalık merkeziliğinin nasıl hesaplandığını anlamanızı istiyorum.

> **Ders sonrası not:** Hoca payda için "toplam kenar sayısı" (total number of edges) dedi. $\frac{(n-1)(n-2)}{2}$, $i$ dışındaki $n-1$ düğümden oluşturulabilecek düğüm çiftlerinin sayısıdır, kenar sayısı değildir.

### 8.3 Yıldız örneği

Hoca 5 uç düğümü olan bir yıldızda (toplam 6 düğüm) ortadaki düğümün arasındalığını adım adım saydı:

- Birinci uç düğüm diğer 4 uç düğümle ortadaki düğüm üzerinden iletişim kurar: 4 çift.
- Bu düğüm sayıldı, artık unutulur. İkinci uç düğüm kalan 3 uç düğümle iletişim kurar: 3 çift.
- Üçüncü uç düğüm kalan 2 uç düğümle: 2 çift.
- Dördüncü uç düğüm son uç düğümle: 1 çift.

Toplam $4+3+2+1=10$ çifttir. Ortadaki düğümün normalize edilmemiş arasındalığı 10'dur. Uç düğümler hiçbir çiftin ortasında olmadığı için arasındalıkları 0'dır.

Normalize değer (ara adım eklendi): $\frac{10}{\frac{5\cdot4}{2}}=\frac{10}{10}=1$.

### 8.4 Doğrusal örnek: A–B–C–D–E

Beş düğüm bir çizgi üzerinde dizilidir.

- **C:** A, D ve E ile C üzerinden konuşur: (A, D), (A, E). B de D ve E ile C üzerinden konuşur: (B, D), (B, E). C dört farklı çiftin ortasındadır. $C_B(C)=4$.
- **B:** A, C, D ve E ile B üzerinden konuşur: (A, C), (A, D), (A, E). $C_B(B)=3$.
- **A:** Uçtadır, hiçbir çiftin ortasında değildir. $C_B(A)=0$.

Simetri nedeniyle D'nin değeri 3, E'nin değeri 0'dır (ara adım eklendi).

### 8.5 7 düğümlü graf

Hoca derece merkeziliği bölümündeki 7 düğümlü grafa döndü:

- **Ortadaki düğüm:** Bir taraftaki 3 düğümün her biri öbür taraftaki 3 düğümle ortadaki düğüm üzerinden konuşur. $3\times3=9$ çift eder. Normalize edilmemiş arasındalık 9'dur.
- **Yandaki düğüm:** Bir yanındaki 2 düğümün her biri öbür yanındaki 4 düğümle bu düğüm üzerinden konuşur. $2\times4=8$ çift eder.
- **Kenardaki düğümler:** Hiçbir iletişimin ortasında değildir. Değerleri 0'dır.

> **Ders sonrası not:** Hoca ortadaki düğüm için önce "3 çift, 6, 6, yani altı çiftin ortasında" deyip hemen ardından "arasındalık 9" dedi. Doğru değer 9'dur: Bir taraftaki 3 düğüm ile öbür taraftaki 3 düğüm arasında $3\times3=9$ çift vardır. Dersin önceki kısmında da hoca bu düğüm için 9 demişti.

### 8.6 Krediyi paylaşmak: 3,5 nereden geliyor?

Bu örnekte bağlantılar A–B, B–C, B–D, C–E ve D–E'dir. Slaytta bazı arasındalık değerleri önceden yazılmıştı.

- **A:** Hiçbir iletişimin ortasında değildir. $C_B(A)=0$.
- **B:** A'nın C, D ve E ile konuştuğu bütün yollar B'den geçer. Bu 3 çift eder. Ama slaytta 3,5 yazıyordu. Ek 0,5 şuradan gelir: C ile D de B üzerinden konuşabilir. Fakat C ile D'nin iki seçeneği vardır: B üzerinden (C–B–D) ya da E üzerinden (C–E–D). İki en kısa yoldan yalnız biri B'den geçtiği için bu çift B'ye 1 değil 0,5 ekler. Sonuç $C_B(B)=3+0{,}5=3{,}5$'tir.

Hoca ardından öğrencilere E'nin değerini sordu.

**Soru:** E'nin arasındalık değeri nedir? **Cevap:** 0,5'tir. E yalnız C ile D arasındaki iletişimin ortasındadır, ama bu iki düğüm hem E hem B üzerinden konuşabilir.

Kalan düğümler için hesap şöyledir (ara adım eklendi):

- (A, E) çiftinin iki en kısa yolu vardır: A–B–C–E ve A–B–D–E. C ve D bu yolların birer tanesindedir. Her biri 0,5 alır.
- (B, E) çiftinin de iki en kısa yolu vardır: B–C–E ve B–D–E. C ve D yine birer 0,5 alır.
- $C_B(C)=C_B(D)=\frac{1}{2}+\frac{1}{2}=1$.

| Düğüm | A | B | C | D | E |
|---|---|---|---|---|---|
| Arasındalık | 0 | 3,5 | 1 | 1 | 0,5 |

Bu değerler bütün çiftler üzerinden Python ile doğrulandı.

### 8.7 Arasındalıkla görselleştirme

Her sosyal ağ analizinde bir metrik seçilir: derece merkeziliği, arasındalık merkeziliği ya da (birazdan görülecek) yakınlık merkeziliği. Hocanın gösterdiği çizimde arasındalık seçilmişti. Büyük daireli düğümler birçok çiftin iletişiminin ortasındaydı. Küçük daireli düğümler ise az sayıda çiftin ortasındaydı.

### 8.8 Düşük derece, yüksek arasındalık

Hoca bir soru gösterdi: Arasındalığı yüksek ama derece merkeziliği düşük bir düğüm bulun. Arasındalık söz konusu olduğunda ortadaki düğümlere bakılmalıdır. İki aday vardı: G ve H. İkisinin de 2 bağlantısı vardı, yani dereceleri aynıydı ve ağın geri kalanına göre düşüktü.

- **G:** Bir yanında 6, öbür yanında 5 düğüm var. Bu 6 düğüm o 5 düğümle G üzerinden konuşmak zorundadır. $6\times5=30$ çift eder.
- **H:** Bir yanında 7, öbür yanında 4 düğüm var. $7\times4=28$ çift eder.

$30>28$ olduğu için cevap G'dir: G'nin arasındalığı yüksek, derecesi düşüktür.

> **Ders sonrası not:** Hoca G için "altı çarpı otuz" dedi, H için önce "sekiz düğüm ve dört düğüm" deyip sonra "dört çarpı yedi, 28" diye hesapladı. Doğru çarpımlar $6\times5=30$ ve $7\times4=28$'dir. İki durumda da G ya da H dışındaki düğüm sayısı $11$'dir ($6+5$ ve $7+4$), yani H'nin yanındaki düğüm sayısı 8 değil 7 olmalıdır.

## 9. Yakınlık Merkeziliği

### 9.1 Sezgi: mor düğüm

Hoca mor bir düğümü olan bir örnek gösterdi. Mor düğüm birçok düğümün ortasında değildi ve derecesi yalnız 1'di. Ama ağın en önemli düğümüne bağlıydı. Bu ana düğüm birçok düğümün arasındaydı, derecesi en yüksekti ve ondan geri kalan düğümlere kolayca ulaşılabiliyordu. Mor düğüm bu merkezi düğüme çok yakın olduğu için önemlidir. Arasındalık ve derece merkeziliği bu önemi yakalayamaz. Bunu yakalamak için yakınlık merkeziliği kullanılır.

### 9.2 Formül

Yakınlık merkeziliği, düğüm ile ağdaki diğer bütün düğümler arasındaki en kısa yolların ortalama uzunluğuna dayanır. Adımlar şöyledir:

- Düğümden diğer her düğüme en kısa uzaklık hesaplanır.
- Bu uzaklıklar toplanır.
- Toplam $n-1$'e, yani düğüm dışındaki düğüm sayısına bölünür. Bu ortalama uzaklıktır.
- Sonucun $-1$'inci kuvveti, yani tersi alınır.

$$C_C(i)=\left(\frac{\sum_{j=1}^{n} d(i,j)}{n-1}\right)^{-1}=\frac{n-1}{\sum_{j=1}^{n} d(i,j)}$$

Burada $d(i,j)$, $i$'den $j$'ye en kısa yolun uzunluğudur.

> **Ders sonrası not:** Hoca formülün özetinde uzaklıklar toplamına "payda", $n-1$'e de "payda" dedi. İkinci biçimde uzaklıklar toplamı paydadır, $n-1$ paydır.

### 9.3 Doğrusal örnek

Hoca A–B–C–D–E çizgisinde A'nın yakınlığını hesapladı. A'dan B'ye uzaklık 1, C'ye 2, D'ye 3, E'ye 4'tür. Bunlar toplanır ve $n-1$'e bölünür, sonra tersi alınır (ara adım eklendi):

$$\sum_j d(A,j)=1+2+3+4=10,\qquad \frac{10}{4}=2{,}5,\qquad C_C(A)=\frac{1}{2{,}5}=0{,}4$$

Aynı hesap diğer düğümler için de yapılır. Hoca, şekle bakınca ortadaki düğümün en yüksek yakınlığa sahip olması gerektiğini söyledi, çünkü ondan başlayınca geri kalan düğümlere kolayca ulaşılır. Genel olarak yakınlık en çok ortadaki düğümlerde yüksektir. Ortadaki C için (ara adım eklendi): $\frac{4}{2+1+1+2}=\frac{4}{6}\approx0{,}67$.

### 9.4 Diğer örnekler

Hoca bir sonraki örnekte ortadaki düğümün yakınlığının 0,6 olduğunu gösterdi. Ortada olduğu için ondan başlayınca geri kalan düğümlere kolayca ulaşılabiliyordu.

<!-- BELİRSİZ: 0,6 değerinin ait olduğu şekil altyazıda yok. Bölüm 7.6'daki 7 düğümlü grafla (iki üçgenin ortadaki bir düğümle birleşmesi) tutarlıdır: Python ile orta düğüm için $\frac{6}{10}=0{,}6$ bulundu. -->

Ardından bir yıldız benzeri örnekte ortadaki düğümün diğer bütün düğümlere doğrudan erişimi olduğu için yakınlığının daha büyük olması gerektiğini söyledi. Diğer düğümlerin hepsinin yakınlığı aynıydı, çünkü her birinden geri kalan düğümlere ortalama uzaklık aynıydı.

### 9.5 Yüksek derece, düşük yakınlık

Hoca son soruyu gösterdi: Derecesi görece yüksek ama yakınlığı düşük olan düğüm hangisidir?

Düşük yakınlık arandığı için merkez bölgeden uzak düğümlere bakılmalıdır. Aynı zamanda derecesi görece yüksek olmalıdır.

- **O:** Derecesi 3'tür, bu görece yüksektir. O'dan en merkezi düğüm I'ya iki bağlantıda gidilir.
- **F:** Derecesi yine 3'tür. F'den I'ya da iki bağlantıda gidilir.
- **E:** E en merkezi düğüme doğrudan bağlıdır. Bu yüzden aday değildir.

Hocanın ayırt edici gerekçesi şuydu: F'nin I'ya ulaşmak için iki yolu, O'nun ise tek yolu vardır. F ile O'nun derecesi aynı olduğu için hoca F'yi seçmedi. Cevap O'dur.

> **Ders sonrası not:** Yakınlık merkeziliği yalnız en kısa uzaklıklara bağlıdır, en kısa yol sayısına bağlı değildir. Bu yüzden F'nin I'ya iki yolu olması, yakınlık formülüne göre tek başına F'nin yakınlığını artırmaz. Doğru karşılaştırma O'nun ve F'nin bütün düğümlere uzaklıkları toplanarak yapılır. Şekil elimizde olmadığı için O'nun gerçekten daha düşük yakınlığa sahip olduğu büyük olasılıkla doğrudur ama burada doğrulanamadı.

## 10. Merkezilik Metriklerinin Özeti ve Prestij Metriklerine Geçiş

Hoca üç merkezilik metriğini formülleriyle özetledi:

- **Derece merkeziliği:** Yönsüz grafta $i$ düğümünün bağlantı sayısı $n-1$'e bölünür. Yönlü grafta çıkış bağlantılarının sayısı tercih edilir ve yine $n-1$'e bölünür.

$$C_D(i)=\frac{d(i)}{n-1}$$

- **Yakınlık merkeziliği:** $i$ ile diğer düğümler arasındaki toplam uzaklık hesaplanır. $n-1$ ile oranlanıp tersi alınır.

$$C_C(i)=\frac{n-1}{\sum_{j=1}^{n} d(i,j)}$$

- **Arasındalık merkeziliği:** $i$'nin ortasında olduğu çiftler, her çift için $i$'den geçen en kısa yolların oranıyla toplanır. Normalize etmek için $\frac{(n-1)(n-2)}{2}$'ye bölünür.

$$C_B'(i)=\frac{2\sum_{j<k}\frac{p_{jk}(i)}{p_{jk}}}{(n-1)(n-2)}$$

Bu metriklerin iki ortak özelliği vardır:

- Bütün bağlantılara eşit ağırlık verirler.
- Yönlü graflarda çıkış bağlantılarına odaklanırlar, giriş bağlantılarına odaklanmazlar.

Giriş bağlantılarına odaklanan ikinci metrik kategorisi prestij metrikleridir. Hoca bunların bir sonraki derste işleneceğini söyledi. Üç prestij metriği vardır:

- Derece prestiji (degree prestige).
- Yakınlık prestiji (proximity prestige).
- Sıra prestiji (rank prestige).

Bir sonraki derste ayrıca ortak atıf (co-citation) ve bibliyografik eşleşme (bibliographic coupling) metrikleri işlenecek, zaman kalırsa PageRank algoritmasına başlanacaktı. Bu derste prestij metrikleri için sayısal örnek verilmedi.

> **Ek bilgi (derste anlatılmadı):** Prestij metrikleri merkezilik metriklerinin giriş bağlantısı karşılığı gibi düşünülebilir. Örneğin derece prestiji, kitapta büyük olasılıkla düğümün giriş derecesinin $n-1$'e bölünmesiyle tanımlanır. Bu dersteki komşuluk matrisinde giriş dereceleri sütun toplamlarıdır (Bölüm 4.2). Ayrıntılar bir sonraki derste işlenecekti.

## Örnek Sorular

Bu derste hazır kare yoktur. Aşağıdaki sorular derste sözlü olarak sorulan ya da hocanın slayt üzerinden sorup cevapladığı sorulardır.

**Soru 1** (derste sözlü, 00:45:15): LinkedIn yönlü bir graf mıdır, yönsüz bir graf mı? Twitter ve Facebook için durum nedir?

> **Çözüm:** LinkedIn yönsüzdür, çünkü bağlantı isteğini kimin başlattığı bilinmez. Twitter yönlüdür, çünkü takip eden ve takip edilen bellidir. Facebook'ta arkadaşlık yönsüz, takip özelliği yönlüdür. Bu yüzden Facebook için ikisi birden denebilir.

**Soru 2** (derste sözlü, 01:48:55): Petrol ticareti grafında hangi ülkelerin giriş derecesi yüksektir?

> **Çözüm:** ABD ve Japonya. ABD Kanada, Meksika, Venezuela, Irak, Suudi Arabistan gibi birçok ülkeden, Japonya Suudi Arabistan ve Birleşik Arap Emirlikleri'nden petrol alır.

**Soru 3** (derste sözlü, 01:51:55): Hangi ülkenin çıkış derecesi düşük ama ihraç ettiği miktar büyüktür?

> **Çözüm:** Venezuela. Yalnız ABD'ye satar, ama büyük miktarda satar. Hoca Birleşik Arap Emirlikleri'nin de az bağlantısı olduğunu söyledi, ama slayttaki doğru cevabın Venezuela olduğunu belirtti.

**Soru 4** (derste sözlü, 02:16:12): Bağlantıları A–B, B–C, B–D, C–E, D–E olan grafta B'nin arasındalığı neden 3,5'tir? E'nin arasındalığı nedir?

> **Çözüm:** A'nın C, D ve E'ye giden bütün en kısa yolları B'den geçer: 3. C ile D arasında iki en kısa yol vardır (C–B–D ve C–E–D) ve yalnız biri B'den geçer: 0,5. Toplam $3{,}5$. E yalnız (C, D) çiftinin iki yolundan birindedir, bu yüzden değeri $0{,}5$'tir.

**Soru 5** (derste sözlü, 02:18:07): Arasındalığı yüksek ama derecesi düşük olan düğüm hangisidir? (Adaylar G ve H, ikisinin de derecesi 2.)

> **Çözüm:** G'nin bir yanında 6, öbür yanında 5 düğüm vardır: $6\times5=30$ çift. H'nin bir yanında 7, öbür yanında 4 düğüm vardır: $7\times4=28$ çift. Cevap G'dir.

**Soru 6** (derste sözlü, 02:24:49): Derecesi görece yüksek ama yakınlığı düşük olan düğüm hangisidir?

> **Çözüm:** Merkezden uzak düğümlere bakılır. O ve F'nin derecesi 3'tür ve ikisi de en merkezi düğüm I'ya iki adımda ulaşır. E ise I'ya doğrudan bağlıdır. Hoca, F'nin I'ya iki yolu, O'nun tek yolu olduğu için cevabı O olarak verdi.

<!-- BELİRSİZ: Soru 5 ve Soru 6'nın grafları altyazıda yok. Çözümler hocanın sözlü anlatımından aktarıldı. -->

## Dersin Toparlaması

Bu derste sosyal ağ analizinin web madenciliğindeki yeri görüldü. Bağlantıları merkezi bir otorite olmadan oluşan karmaşık ağlar, çoğunlukla görselleştirme yoluyla incelenir. Siyasi bloglar, şirket e-postaları, Facebook ve yemek tarifi siteleri bunun örnekleriydi. Web de HTML belgelerinin ve köprü bağlantılarının oluşturduğu, internetin üzerinde duran böyle bir ağdır. Ardından temel terimler (düğüm, bağlantı, yönlü ve yönsüz graf, bağlantı nitelikleri), ağ verisinin üç temsili (komşuluk matrisi, kenar listesi, komşuluk listesi) ve ağın bağlantı yapısını görselleştirmeden anlamayı sağlayan iki metrik (derece dağılımı ve bağlı bileşenler) işlendi.

Dersin ikinci yarısında, TF-IDF'e dayalı sıralamanın spam ve popülerlik sorunları nedeniyle bağlantı analizine dayalı sıralamanın (HITS ve PageRank) nasıl doğduğu anlatıldı. Düğümlerin önemini ölçen üç merkezilik metriği görüldü: derece, arasındalık ve yakınlık. Derece tek başına yetmez. Orkut örneğinde olduğu gibi çok bağlantılı bir düğüm ağın kenarında kalabilir. Bu yüzden arasındalık ve yakınlık da hesaplanır. Bir sonraki derste giriş bağlantılarına odaklanan prestij metrikleri (derece, yakınlık ve sıra prestiji), ortak atıf, bibliyografik eşleşme ve PageRank işlenecekti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
