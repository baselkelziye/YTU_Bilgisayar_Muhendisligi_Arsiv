# Ders 5 Çalışma Özeti

## Genel Konular

- Ders 3 Kasım 2020 tarihlidir. Kitabın gözetimsiz öğrenme (unsupervised learning) bölümünün tekrarı yapılmıştır.
- Dersin başında İzmir depremi (30 Ekim 2020) konuşulmuştur. Hoca ve öğrenciler hal hatır sormuştur.
- Hoca ders kitabını (Web Data Mining) bölüm bölüm işlediğini söylemiştir. Dönem sonuna kadar web kullanım madenciliği (web usage mining) bölümüne kadar gitmeyi planlamaktadır.
- Ana konular:
  - Gözetimli ve gözetimsiz öğrenme farkı
  - Web verisinde kümeleme (clustering) kullanım alanları
  - Atama (bölümleme) tabanlı kümeleme: K-Means
  - Hiyerarşik kümeleme ve dendrogram
  - Kümeler arası uzaklık yöntemleri: single link, complete link, average link, centroid
  - Uzaklık fonksiyonları: Minkowski, Öklid, Manhattan, Chebyshev, simple matching, Jaccard, kosinüs benzerliği
  - Veri ön işleme (data preprocessing) adımları
  - Kümeleme kalitesinin ölçülmesi: entropi, saflık (purity), küme içi ve kümeler arası uzaklık
  - Dönem projesi önerisi ve öğrenci proje fikirleri

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek bir kümeleme algoritması her veri setinde başarılı olmaz.
  - Farklı kategorilerden birer temsilci algoritma seçilmelidir.
  - Bu algoritmalar farklı uzaklık fonksiyonlarıyla denenmelidir.
  - Sonuçlar kalite metrikleriyle karşılaştırılmalıdır.
- K-Means yuvarlak ve eliptik kümeleri iyi bulur. Garip şekilli ya da iç içe geçmiş kümeleri bulamaz.
- Hiyerarşik algoritmalar şekilden bağımsız kümeleri bulabilir. Ama hesaplama maliyeti yüksektir. Verinin tamamı bellekte olmalıdır.
- K-Means'te veri diskte kalabilir. Bu yüzden büyük veriye ölçeklenir.
- Uzaklık fonksiyonu tüm kümeleme algoritmalarında olmazsa olmazdır. Seçimi sonucu doğrudan etkiler. Seçimin gerekçesi (justification) verilebilirse sonuç daha başarılı olur.
- Simple matching formülünü ezberlemeye gerek yoktur: "uyuşmayan öznitelik sayısı bölü toplam öznitelik sayısı" diye akılda kalsın.
- Kosinüs benzerliği (cosine similarity) içerik madenciliğinde (content mining) çok kullanılacaktır.
- Entropi ve purity formüllerini ezberlemek yerine anlamlarını bilmek yeterlidir.
- Veri ön işleme konusunu öğrencilerin veri madenciliği ve makine öğrenmesi derslerinden bildiği varsayılmaktadır. Dersin ilk 3-4 haftası tekrar niteliğindedir. Kalan 10 haftada link analizi, içerik analizi, yapı analizi, kullanım madenciliği ve fikir madenciliği (opinion mining) işlenecektir.
- Proje önerisi gelecek hafta (10 Kasım 2020) istenmektedir.

## Kısa Tekrar Notları

- Gözetimli öğrenme (supervised learning): etiketli veriden model öğrenilir. Model yeni veriyi etiketler.
- Gözetimsiz öğrenme: etiket yoktur. Verideki yapı, yani kaç grup olduğu bulunmaya çalışılır.
- Web verisi örnekleri: tıklama akışı (clickstream), oturum (session) verisi, dinamik URL'ler, sunucu log dosyaları, crawl edilmiş dokümanlar.
- K-Means:
  - Baştan $k$ verilir.
  - Rastgele $k$ merkez (centroid) seçilir.
  - Her nokta en yakın merkeze atanır.
  - Merkezler yeniden hesaplanır.
  - Durma koşulu sağlanana kadar tekrarlanır.
- K-Means karmaşıklığı: $O(t \cdot k \cdot n)$. $t$ iterasyon, $k$ küme, $n$ veri sayısıdır. $k$ ve $t$ küçükse doğrusal büyür.
- En uygun $k$ için: dirsek (Elbow) yöntemi, siluet (Silhouette) yöntemi.
- K-Means zayıflıkları:
  - Uzaklık tanımlanabilmelidir.
  - $k$ baştan verilmelidir.
  - Aykırı değerlere (outlier) duyarlıdır.
  - Başlangıç merkezlerinin seçimine duyarlıdır.
  - Eliptik olmayan şekilleri bulamaz.
- Hiyerarşik kümeleme iki tiptir:
  - Birleştirici (agglomerative, bottom-up)
  - Bölücü (divisive, top-down)
- Hiyerarşik kümelemede $k$ verilmez. Dendrogram oluşur. En kaliteli kesit seçilir.
- Kümeler arası uzaklık:
  - Single link: en yakın iki nokta. Zincir etkisine (chain effect) açıktır.
  - Complete link: en uzak iki nokta. Aykırı değerlerden etkilenir.
  - Average link: tüm nokta çiftleri uzaklıklarının ortalaması. Hesaplaması pahalıdır.
  - Centroid: küme merkezleri arasındaki uzaklık.
- Etiket varsa kalite metrikleri: entropi (düşük olmalı), purity (yüksek olmalı), NMI, doğruluk.
- Etiket yoksa kalite metrikleri: küme içi yakınlık (cohesion, compactness) küçük olmalı, kümeler arası ayrıklık (separation, isolation) büyük olmalı.

## Detaylı Açıklamalar

### Gözetimsiz öğrenme ve web verisi

- Gözetimsiz öğrenmede önceden model kurulmaz. Doğrudan veri üzerinde kaç grup olduğu araştırılır.
- İki boyutlu bir örnekte gruplar gözle görülebilir. Gerçek web verisinde ise her nokta $n$ boyutludur. Boyutlar farklı tiplerde olabilir: tam sayı, boolean vb.
- Web oturumu (session):
  - Kullanıcı siteye girdiği andan tarayıcıyı kapatana kadar bir oturum oluşturur.
  - Site tarayıcıya bir çerez (cookie) bırakır. Çerezde kullanıcı kimliği ve oturum kimliği (session ID) bulunur.
  - Her HTTP isteğinde bu kimlikler sunucuya gider.
  - Sunucu aynı oturumdaki istekleri session ID üzerinden ilişkilendirir.
- Bir oturumdan istatistiksel bir davranış vektörü çıkarılır. Örnek öznitelikler: sayfa görüntüleme (page view) sayısı, tıklama sayısı, görüntülenen ürün sayısı.
- Çok sayıda oturum vektörü kümelenince benzer davranışlı kullanıcı grupları bulunur.
- Hocanın örnekleri:
  - Tişört üretimi: herkese ayrı beden üretilemez. İnsanlar gruplanır, her gruba bir beden üretilir.
  - Pazarlama: bir milyon müşteriye ayrı kampanya yapılamaz. Kullanıcı profilleri çıkarılır. Kampanya gruplara yönelik yapılır.
  - Doküman kümeleme: crawl edilen dokümanların etiketi yoktur. Her doküman kelime uzayında bir vektöre çevrilir. Kelime varsa 1, yoksa 0 yazılır. Kümeleme ile spor, eğitim, bilim, politika gibi gruplar bulunur.

### Kümeleme algoritması kategorileri

- Atama (bölümleme, partitional) tabanlı:
  - Önce bölümler (partition) oluşturulur. Kalan noktalar bu bölümlere atanır.
  - Yuvarlak ve eliptik kümelerde başarılıdır.
  - Hesaplama maliyeti düşüktür.
- Hiyerarşik:
  - Noktalar sürekli birbiriyle karşılaştırılıp birleştirilir.
  - Belirli bir şekle sahip olmayan grupları bulabilir.
  - Hesaplama maliyeti yüksektir. Bu yüzden "bellek içi (in-memory) kümeleme algoritmaları" diye de anılır.
- Bunların dışında dağılım (distribution) tabanlı ve yoğunluk (density) tabanlı algoritmalar da vardır. Derste işlenmemiştir.
- Kümeleme amacı:
  - Küme içi uzaklık (intra-cluster distance) en aza indirilmelidir.
  - Kümeler arası uzaklık (inter-cluster distance) en büyük yapılmalıdır.

### K-Means algoritması

- Adımlar:
  - Veri setinden rastgele $k$ nokta seçilir. Bunlar ilk merkezlerdir.
  - Her nokta $k$ merkezin hepsine olan uzaklığına bakılarak en yakın merkeze atanır.
  - Her küme için yeni merkez hesaplanır.
  - İkinci iterasyondan sonra merkezler "sanal" noktalardır. Gerçek bir veri noktasına karşılık gelmezler.
  - Durma koşulu sağlanmazsa atama adımına dönülür.
- Durma koşulları:
  - Yeni atama yok ya da çok az.
  - Merkezler değişmiyor ya da çok az değişiyor.
  - Hata kareleri toplamı (sum of squared error, SSE) iki iterasyon arasında değişmiyor ya da çok az değişiyor.
- SSE: her kümede merkez ile küme elemanları arasındaki uzaklıkların karelerinin toplamı. Tüm kümeler için toplanır.

$$SSE = \sum_{j=1}^{k} \sum_{x \in C_j} dist(x, m_j)^2$$

- Büyük veri versiyonu:
  - Her küme için iki değişken tutulur: $s_j$ (kümeye atanan noktaların toplamı) ve $n_j$ (kümedeki nokta sayısı).
  - Veri baştan sona bir kez taranır. Her nokta en yakın merkeze atanır. İlgili $s_j$ ve $n_j$ güncellenir.
  - Tarama sonunda yeni merkez $m_j = s_j / n_j$ olarak hesaplanır.
  - Veri belleğe alınmadan, diskte dururken kümeleme yapılabilir.
- Karmaşıklık: her iterasyonda $n$ noktanın her biri $k$ merkezle karşılaştırılır. $t$ iterasyon için $O(t \cdot k \cdot n)$ olur.

### K-Means'in zayıflıkları ve çözümleri

- Uzaklık hesaplanamıyorsa algoritma uygulanamaz.
- $k$ baştan verilmelidir. Çözüm: Elbow ve Silhouette gibi en uygun $k$ algoritmaları. Bunlar örneğin $k=2$'den $k=10$'a kadar kümeleme yapıp kaliteye bakar.
- Aykırı değerler (outlier):
  - Bir aykırı nokta merkezi kendine çekebilir. Doğal bir küme ortadan ikiye bölünebilir.
  - Çözüm 1: kümelemeden önce aykırı değer tespiti (outlier detection) yapılıp aykırı noktalar çıkarılır.
  - Çözüm 2: rastgele örnekleme (random sampling) yapılır. Aykırı noktalar az olduğu için örneğe düşme olasılıkları düşüktür. Örnek üzerinde kümeleme yapılır. Kalan noktalar bu kümelere atanır.
- Başlangıç merkezleri (initial seeds):
  - Birbirine çok yakın seçilirse yanlış kümeler bulunur.
  - Çözüm: ilk merkez seçilir. İkinci merkez, birinciye en uzak noktadır. Üçüncü merkez, ilk ikisine en uzak noktadır. Bunun için veri baştan sona taranır.
- Eliptik olmayan şekiller: iç içe halka şeklindeki iki küme K-Means ile bulunamaz. K-Means bunları ortadan ikiye böler. Bu durumda hiyerarşik algoritmalar denenmelidir.

### Kümelerin tanımlanması

- Kümeleme sonucunu dışarıdan bakan birine anlatmak gerekir. Yöntemler:
  - Merkez ve yarıçap (radius) vermek. Ayrıca standart sapma ile noktaların dağılımı anlatılabilir.
  - Öznitelik sınır değerleriyle kural yazmak. Örnek: "birinci boyut 2'den küçük" bir küme, "birinci boyut 2'den büyük ve ikinci boyut 1,5'ten büyük" başka bir küme.
  - Kümede en sık tekrar eden elemanları kullanmak. Doküman kümelerinde en sık kelimelere bakılarak kümenin konusu (topic) bulunur.
  - Görselleştirme.
- Hoca kendi öğrencilerinin çalışmalarından örnekler göstermiştir:
  - N11 sitesinden alınan dinamik URL'ler parçalanmış, Word2Vec ile vektöre çevrilmiş, K-Means, bisecting K-Means ve hiyerarşik algoritmalarla kümelenmiştir. Kümeler arama (search), kampanya ve kategori gezinme davranışlarını göstermiştir.
  - Sayfa gezinme yolları (örnek: C, D, A, B) vektöre çevrilip sınıflandırılmıştır.
  - Log dosyasından PrefixSpan ile sık örüntüler (frequent pattern) bulunmuş, Node2Vec ile vektörleştirilip kümelenmiştir.
  - Bu çalışmalar akademik yayına dönüşmüştür.

### Hiyerarşik kümeleme

- Algoritma bellekte bir ağaç yapısı oluşturur. Bu yapıya dendrogram denir.
- Birleştirici (agglomerative) kümeleme derste işlenmiştir. Daha yaygındır.
- Adımlar:
  - Her nokta ayrı bir kümedir (örnek: P1, P2, P3, P4, P5).
  - Tüm kümeler arasındaki ikili uzaklıklar hesaplanır.
  - En yakın iki küme birleştirilir (merge). Örnekte önce P1 ve P2 birleşir.
  - Uzaklıklar yeniden hesaplanır. Sonra P4 ve P5 birleşir. Sonra P3, P1-P2 kümesine katılır. En sonunda tümü birleşir.
  - Her birleştirme dendrograma eklenir.
- $k$ baştan verilmez. Her birleştirme adımında kümeleme kalitesine bakılır. En kaliteli kesit seçilir.

### Kümeler arası uzaklık yöntemleri

- Centroid yöntemi: kümenin merkezi bulunur. Uzaklık merkezler arasında ölçülür.
- Single link:
  - Uzaklık, iki kümenin birbirine en yakın iki noktası arasındaki uzaklıktır.
  - Eliptik olmayan şekillerde başarılı olabilir.
  - İki doğal küme arasında birbirine yakın noktalardan bir zincir varsa iki küme yanlışlıkla birleşir. Buna zincir etkisi (chain effect) denir.
- Complete link:
  - Uzaklık, iki kümenin birbirine en uzak iki noktası (two furthest data points) arasındaki uzaklıktır.
  - Zincir etkisi olan örnekte doğru kümeleri bulur.
  - Uzak noktalarda aykırı değerler varsa başarısız olabilir.
- Average link:
  - Uzaklık, iki kümedeki tüm nokta çiftleri arasındaki uzaklıkların ortalamasıdır.
  - Zincir etkisini ve aykırı değer etkisini azaltır.
  - Hesaplama maliyeti daha yüksektir.
- Bir öğrenci average link ile centroid yönteminin aynı olup olmadığını sormuştur. Hoca farkı açıklamıştır:
  - Centroid: önce merkez bulunur, sonra merkeze olan uzaklık hesaplanır.
  - Average link: tüm uzaklıklar tek tek bulunur, sonra ortalaması alınır.
- Hocanın önerisi: aykırı değerler ön işlemede atılabiliyorsa complete link hesaplama açısından büyük olasılıkla daha ucuzdur (hoca cümleyi "computation olarak daha şey" diye yarım bırakır). Emin değilseniz birden fazla uzaklık yöntemi deneyin.
- Kütüphanelerde bu yöntemler parametre olarak seçilebilir.

### Uzaklık fonksiyonları

- Minkowski uzaklığı:

$$dist(x_i, x_j) = \left( \sum_{r=1}^{n} |x_{ir} - x_{jr}|^h \right)^{1/h}$$

- $h = 2$ ise Öklid (Euclidean) uzaklığı, $h = 1$ ise Manhattan uzaklığıdır.
- Ağırlıklı Öklid uzaklığı (weighted Euclidean): özniteliklere ağırlık verilir.
- Kare Öklid uzaklığı (squared Euclidean): farkların karelerinin toplamıdır, kök alınmaz. Birbirine uzak noktaların uzaklığını daha da büyütür.
- Chebyshev uzaklığı: öznitelik farkları içinden en büyüğü alınır.

$$dist(x_i, x_j) = \max_r |x_{ir} - x_{jr}|$$

- Binary öznitelikler için karışıklık matrisi (confusion matrix) kullanılır:

```
                 x_j = 1   x_j = 0
    x_i = 1         a         b
    x_i = 0         c         d
```

- Simple matching coefficient (simetrik binary öznitelikler):

$$dist(x_i, x_j) = \frac{b + c}{a + b + c + d}$$

  - Derste 7 öznitelikli örnekte 3 uyuşmazlık vardır. Uzaklık $3/7$ çıkmıştır.
- Jaccard katsayısı (asimetrik binary öznitelikler): 1 değeri 0'dan daha önemliyse kullanılır. 0-0 eşleşmeleri paydaya alınmaz.

$$dist(x_i, x_j) = \frac{b + c}{a + b + c}$$

  - Hoca aynı örnekte uzaklığı $3/6$ olarak söylemiştir. Vektörler slaytta olduğu için altyazıdan doğrulanamıyor.
  - Web madenciliğinde yoğun kullanılır.
- Nominal öznitelikler (ikiden fazla değer alabilen): yine simple matching yaklaşımı kullanılır. $q$ eşleşen öznitelik sayısı, $r$ toplam öznitelik sayısıdır.

$$dist(x_i, x_j) = \frac{r - q}{r}$$

- Kosinüs benzerliği: dokümanlar vektör olarak tanımlanır. Vektörler arasındaki açı küçükse dokümanlar benzerdir. Açı büyüdükçe uzaklık artar.

### Veri ön işleme

- Bir öğrencinin sorusu üzerine hoca kısaca anlatmıştır.
- Web verisi önce sayısal vektörlere çevrilir. Bunun için gömme (embedding) yöntemleri kullanılır: Word2Vec, Graph2Vec, Node2Vec.
- Pipeline adımları:
  - Eksik veri tamamlama (missing data imputation): kolondaki diğer değerlerden eksik değer tahmin edilir.
  - Aykırı değer tespiti: örneğin kutu grafiği (box plot) analizi. Aykırı değerler eğitim verisinden ya da kümelenecek veriden çıkarılır.
  - Normalizasyon: örneğin bir öznitelik 0-1000, diğeri 0-1 aralığındaysa aralıklar eşitlenir.
  - Gözetimli öğrenmede öznitelik önemi: bilgi kazancı oranı (information gain ratio).
  - Bağımlı kolonların tespiti ve çıkarılması: ki-kare (chi-square) testi.
  - Boyut küçültme: temel bileşenler analizi (PCA), faktör analizi.
- Bu algoritmaların hepsi parametriktir. En iyi parametreler hiperparametre optimizasyonu (hyperparameter optimization) ile bulunur.
- Hoca, veri bilimcilerin zamanının büyük kısmının bu işlere gittiğini söylemiştir.

### Kümeleme kalitesinin değerlendirilmesi

- Etiketli veri varsa: entropi, purity, NMI, doğruluk kullanılır.
- Entropi belirsizliği ölçer:
  - Arayanı bildiğiniz telefon: belirsizlik yoktur, entropi 0'dır.
  - Bilinmeyen numara: belirsizlik vardır, entropi 1'dir.
  - Çuvaldaki bilyelerin hepsi aynı renkse entropi 0'dır. Yarısı beyaz, yarısı kırmızıysa entropi 1'dir.
- Purity: bir kümedeki noktalar ağırlıklı olarak tek bir sınıftansa saflık yüksektir.
- Derste 900 dokümanlık etiketli örnek incelenmiştir:
  - Algoritma 3 küme bulmuştur.
  - Birinci kümede ağırlıklı olarak tek sınıf vardır. Entropisi düşük, purity'si yüksektir.
  - Üçüncü kümede sınıflar karışıktır. Entropisi en yüksektir, purity'si düşüktür.
  - Tüm kümelemenin değeri, kümelerin entropi ve purity değerlerinin (ağırlıklı) ortalamasıdır.
  - Hedef: entropiyi düşürmek, purity'yi artırmak.
- Etiketli veri yoksa:
  - Küme içi yakınlık (intra-cluster cohesion, compactness): küçük olmalıdır.
  - Kümeler arası ayrıklık (inter-cluster separation, isolation): büyük olmalıdır.
- Görselleştirme yalnız 2-3 boyutta mümkündür. $n$ boyutlu uzayda zordur.

### Dönem projesi

- Proje, derste bölüm bölüm işlenen algoritmaları içermeli ve web verisi üzerinde çalışmalıdır.
- Veri kaynakları: kod depoları, Stanford gibi veri paylaşım ortamları. Örnek veriler: tıklama verisi, log dosyaları, oturum verisi, URL verisi, IIS ya da Tomcat sunucusu logları.
- Crawler algoritmaları da proje olabilir: derinlik öncelikli arama (DFS), genişlik öncelikli arama (BFS).
- Proje uluslararası bir konferansta yayınlanabilecek düzeye gelirse ders notu bir harf yukarı çıkarılacaktır. Bu bonus dönem başında da söylenmiştir.
- Hoca proje konusunu dikte etmemektedir. Geçmiş yıllarda dikte ettiği projeler tamamlanmamıştır. Öğrenci kendi konusunu seçmelidir. Mümkünse iş yerindeki kullanıcı-web etkileşim verisi kullanılmalıdır.
- Proje önerisi (project proposal) bir sayfa olmalıdır:
  - Fikir nedir, neden ilginçtir?
  - Ne önerilmektedir, dönem sonunda hangi uygulama görülecektir?
  - Nasıl yapılacaktır, hangi açık kaynak kütüphane kullanılacaktır, üzerine ne geliştirilecektir?
  - Haftalık iş planı (timeline): analiz, tasarım, geliştirme ve test için ne kadar süre ayrılacaktır?
- Teslim: gelecek hafta (10 Kasım 2020). Düzeltme gerekirse bir hafta ek süre verilebilir.

### Ders sonu soru-cevap (ofis saati)

- Bir öğrenci crawler ile toplanan verinin geçerli veri seti olup olmayacağını sormuştur. Hoca:
  - Proje crawler projesiyse değerlendirilen kısım crawler'dır. Crawler bir arama motoruyla birleştirilmelidir. Örnek: birkaç e-ticaret sitesinden veri indirip önüne hibrit bir arama arayüzü koymak.
  - Crawling yalnız veri indirmek içinse asıl iş, indirilen metinler üzerinde yapılan metin madenciliğidir (örnek: Wikipedia sayfalarını kümelemek).
  - Veri indirmek sorunludur: ne kadar veri, veri sağlıklı mı? Hazır veri setleri tercih edilebilir. Bazı veri setlerinde haber sitelerinden indirilmiş HTML sayfaları vardır.
- Bir öğrenci ürün yorumları üzerinde duygu analizi fikrini sormuştur. Hoca bunun web madenciliği kapsamında olduğunu söylemiştir:
  - Kitabın fikir madenciliği (opinion mining) bölümüne bakılmalıdır.
  - Görünüş odaklı fikir madenciliği (aspect-oriented opinion mining) ile ürünün alt özellikleri (ses kalitesi, ekran boyutu, çözünürlük vb.) hakkındaki olumlu ya da olumsuz görüşler yakalanabilir.
- Aynı öğrenci film öneri sistemi fikrini sormuştur. Hoca:
  - İçerik tabanlı (content-based) ve işbirlikçi filtreleme (collaborative filtering) yöntemlerine bakılmalıdır.
  - Bu yöntemler kullanıcı-ürün matrisi kullanır. Kullanıcının henüz puanlamadığı ürünler için puan tahmini yapar.
  - Collaborative filtering soğuk başlangıç (cold start) problemiyle karşılaşır. Content-based filtering bu probleme belli ölçüde yanıt verir.
  - Apriori ve TF-IDF eklemek projeyi gereksiz karmaşıklaştırır. Proje sadeleştirilmeli, kapsamı belli olmalıdır.
  - İş planında analiz, tasarım, geliştirme ve test süreleri kalan haftalara dağıtılmalıdır. Hoca derslerde ilerlemeyi soracaktır.
- Bir öğrenci Boğaziçi Data Comp etkinliğine katılıp fikrini geliştireceğini söylemiştir.
- Gelecek hafta web içerik madenciliğine (web content mining), bilgi erişimi (information retrieval) bölümüyle başlanacaktır. Crawler'lardan da bahsedilecektir.

### Ders sonrası notlar

- Altyazıda "K-Wins", "K-Mills", "K-Mins", "K-Mease" diye geçen algoritma K-Means'tir.
- "Yukladiğim distance" Öklid (Euclidean) uzaklığıdır. "Çebiçev" Chebyshev uzaklığıdır.
- "Jacquart / Jekart" Jaccard katsayısıdır.
- "Agnormative clustering" agglomerative clustering'dir.
- "Some squared error" sum of squared error (SSE) demektir.
- "World2Vac" ve "not to vect" sırasıyla Word2Vec ve Node2Vec'tir. "PCI" PCA'dır.
- Hoca bir yerde "intercluster distance küme içindeki uzaklıktır, minimize edilir" demiştir. Doğrusu: küme içi uzaklık intra-cluster distance'tır. Inter-cluster distance kümeler arası uzaklıktır.
- Benzer şekilde "inter-cluster cohesion" denen metrik doğru adıyla intra-cluster cohesion'dır.
- Hoca DBSCAN'ı hiyerarşik algoritma örneği olarak saymıştır. DBSCAN aslında yoğunluk tabanlı (density-based) bir algoritmadır. Bisecting K-Means ise bölücü hiyerarşik yapıda çalışan bir K-Means türevidir.
- Hoca entropi örneğinde ders sonunda ortalamadan bahsetmiştir. Genelde küme boyutlarıyla ağırlıklı ortalama alınır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
