# Ders 13 Çalışma Özeti

## Genel Konular

- Önceki dersin tekrarı: centrality ve prestige ölçüleri, rank prestige formülü.
- Rank prestige'in matris biçimi ve özdeğer sistemi (eigensystem).
- Co-citation ve bibliographic coupling ölçüleri.
- Web çizgesi (web graph) ve popülerlik tabanlı sıralama gerekçesi.
- PageRank: temel fikir, oyuncak örnekte denklem sistemi.
- Stokastik komşuluk matrisi (stochastic adjacency matrix) ve $r = M r$ denklemi.
- Kuvvet yinelemesi (power iteration) yöntemi.
- Rastgele yürüyüş yorumu (random walk interpretation) ve durağan dağılım (stationary distribution).
- Markov zinciri (Markov chain) koşulları: stokastik, indirgenemez (irreducible), periyodik olmayan (aperiodic).
- Örümcek tuzağı (spider trap) ve çıkmaz uç (dead end) sorunları ve çözümleri.
- Google matrisi.
- Sınav ve proje sunumu duyuruları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Geçen hafta ders yapılamadı. Hoca 1–2 ders borcu olduğunu, bu dersleri kayıt olarak sisteme yükleyeceğini söyledi.
- PageRank ve HITS tamamen rank prestige ölçüsünün üzerine kurulmuştur.
- Co-citation ve bibliographic coupling formüllerini ezberlemeye gerek yok. Matris üzerindeki mantık hatırlanırsa formül kolayca yazılır.
- Yalnız içerik benzerliğine (TF-IDF) dayalı arama kandırılmaya (spam) açıktır. Popülerlik tabanlı ölçüler güvenilir ve sorguya uyan sayfaları ilk 10 sonuçta göstermeye yarar.
- PageRank'te iki şeye bakılır: bir düğümün aldığı bağlantılar ve bu bağlantıları veren düğümlerin PageRank değerleri.
- Markov zinciri teoremi: matris koşulları sağlarsa başlangıç değeri ne olursa olsun power iteration tek bir değere yakınsar. Bu, milyonlarca düğümlü web çizgesinde sonsuz döngüye girmemek için çok önemli.
- Sınavda oyuncak bir çizge verilecek. Şunların hesaplanması istenebilir: degree centrality, degree prestige, closeness centrality, proximity prestige, bibliographic coupling, co-citation, PageRank. Ayrıca belli bir sıçrama katsayısıyla (jumping factor) PageRank ve örümcek tuzağı olan çizgede PageRank hesabı sorulabilir. Hoca bu dersin iyi öğrenilmesini istedi.

## Kısa Tekrar Notları

- Rank prestige: $P_R(i)=\sum_{j} \dfrac{A_{ji}}{O_j} P_R(j)$. $O_j$: $j$'nin dışa giden bağlantı sayısı.
- Matris biçimi: $P = A^T P$. Özdeğer sistemi, $\lambda = 1$.
- Atıf matrisi (citation matrix) $L$: $L_{ij}=1$ ise $i$, $j$'ye atıf vermiş.
- Co-citation: $C_{ij}=\sum_{k=1}^{n} L_{ki}L_{kj}$. $i$ ve $j$'ye birlikte atıf veren makale sayısı.
- Bibliographic coupling: $B_{ij}=\sum_{k=1}^{n} L_{ik}L_{jk}$. $i$ ve $j$'nin birlikte atıf verdiği makale sayısı.
- PageRank: $r_j=\sum_{i \to j} \dfrac{r_i}{d_i}$. $d_i$: $i$'nin dışa giden bağlantı sayısı.
- Stokastik matris: her sütunun toplamı 1.
- Power iteration: $r^{(0)}=[1/N,\dots,1/N]^T$, sonra $r^{(t+1)}=M r^{(t)}$. $\lVert r^{(t+1)}-r^{(t)} \rVert < \varepsilon$ olunca dur.
- Teleport ile PageRank: $r_j=\sum_{i \to j} \beta \dfrac{r_i}{d_i} + (1-\beta)\dfrac{1}{N}$. Genelde $\beta=0{,}8$ veya $0{,}9$.
- Spider trap: periyodik olmama koşulunu bozar. Çözüm: teleport (sıçrama).
- Dead end: matris stokastik olmaz, indirgenemezlik bozulur. Çözüm: çıkmaz düğümden tüm düğümlere $1/N$ ağırlıklı sanal bağlantı.
- Büyük çizgelerde PageRank yaklaşık 50 yinelemede yakınsar.

## Detaylı Açıklamalar

### Tekrar: rank prestige

- Centrality ölçüleri dışa giden bağlantılarla (outlink), prestige ölçüleri gelen bağlantılarla (inlink) hesaplanır.
- Önemli bir düğümden alınan bağlantı daha çok önem taşır. Bunu rank prestige yakalar.
- Bu derste formüle bir ek yapılır: bağlantı veren düğümün katsayısı 1 yerine $1/O_j$ alınır. Yani bir düğüm önemini dışa verdiği bağlantı sayısına bölerek dağıtır.
- Tüm düğümler için denklemler alt alta yazılınca bir matris–vektör çarpımı çıkar: $P_{t+1} = A^T P_t$.
- Bu denklem doğrusal cebirde özdeğer sistemidir. Power iteration ile çözülür. Çözümde bulunan sütun vektörü tüm düğümlerin rank prestige değerlerini verir.

### Co-citation ve bibliographic coupling

- Belge kümesi akademik makalelerden oluşsun. Her makale kaynakçasında başka makalelere atıf verir.
- Benzer makaleler TF-IDF ile içerikten bulunabilir. İkinci yol: içeriğe hiç bakmadan yalnız atıflara bakmak.
- Atıf matrisi: satırlar atıf verenler, sütunlar atıf alanlar. Atıf varsa 1, yoksa 0.
- Co-citation:
  - Bir $k$ makalesi kaynakçasında hem $i$'ye hem $j$'ye atıf veriyorsa $i$ ve $j$ birlikte atıf almıştır.
  - Yazar ikisini aynı makalede kullandığına göre büyük olasılıkla aynı alandadırlar.
  - Birlikte atıf veren makale sayısı arttıkça ilişki güçlenir.
  - Hesap: $i$ ve $j$ sütun vektörlerinin her satırdaki elemanları çarpılır ve toplanır.
- Bibliographic coupling:
  - $i$ ve $j$ ikisi de aynı $k$ makalesine atıf veriyorsa aralarında ilişki vardır.
  - Hocanın örneği: bir makale İngilizceden Fransızcaya çevrilmiş olsun. TF-IDF ikisi arasında benzerlik bulmaz. Ama ikisi de aynı makalelere atıf verdiği için bibliographic coupling değeri yüksek çıkar.
  - Hesap: $i$ ve $j$ satır vektörlerinin elemanları çarpılır ve toplanır.
- Bu ölçüler benzer makaleleri bulan araçlarda kullanılır.

### Web çizgesi ve popülerlik

- Ders boyunca sosyal ağ analizi teknikleri web çizgesine uygulanır.
- Diğer ağ örnekleri: Facebook verisi, bloglar arası bağlantılar, makaleler arası atıflar, internetin fiziksel iletişim ağı.
- Web çizgesinde HTML sayfaları düğüm, köprü bağlantılar (hyperlink) kenardır.
- Arama olmasaydı web'de sayfaları tek tek gezerek arardık.
- Popülerlik tabanlı ölçüler iki sorunu çözer:
  - Hangi sayfaya güvenilmeli? Ör. "web data mining" araması 100 sayfa getirsin. Üniversite ve Wikipedia sayfaları, bilinmeyen kişisel sayfaların önünde olmalı.
  - Sorguya en iyi uyan ve popüler sayfa ilk sırada gösterilmeli.
- Basit örnek: çok bağlantı alan mavi düğüm, tek bağlantı alan kırmızı düğümden önemlidir. Anahtar kelime ikisinde de varsa mavi düğüm ilk 10'da olmalı.
- Hocanın verdiği örnek: Stanford ana sayfası çok bağlantı alır, bilinmeyen bir kişisel sayfa bir bağlantı alır.

### PageRank fikri

- Bir düğüme bağlantı veren tüm düğümler kendi önemlerini bu düğüme aktarır.
- Çok bağlantı alan düğüm önemlidir.
- Bağlantı veren düğümlerin önemi aynı değildir. Yüksek PageRank'li düğümden bağlantı almak PageRank'i yükseltir.
- Slayttaki örnek:
  - B düğümü çok bağlantı alır, en büyük PageRank değeri onundur.
  - C yalnız bir bağlantı alır ama bu bağlantı B'den gelir. C'nin PageRank'i de çok yüksek çıkar.
  - E dört bağlantı alır ama bağlantı verenlerin PageRank değeri düşük. E'nin PageRank'i düşük çıkar.
- Hesap örneği: $j$'ye $i$ ve $k$ bağlantı verir. $i$'nin 3, $k$'nın 4 dışa bağlantısı var.

$$r_j = \frac{r_i}{3} + \frac{r_k}{4}$$

- $j$ üç düğüme bağlantı verir. Her birine $r_j/3$ aktarır.
- Hesap özyinelemelidir (recursive). Tüm düğümler için tekrarlanır. Değerler değişmeyince durulur.

### Oyuncak örnek: denklem sistemi

- Düğümler: Y, A, M. Y kendine ve A'ya, A Y'ye ve M'ye, M A'ya bağlantı verir.

$$r_y = \frac{r_y}{2} + \frac{r_a}{2}, \quad r_a = \frac{r_y}{2} + r_m, \quad r_m = \frac{r_a}{2}$$

- 3 denklem, 3 bilinmeyen var ama tek çözüm yok. Çözümler birbirinin katıdır.
- Tek çözüm için dördüncü denklem eklenir: $r_y + r_a + r_m = 1$.
- Bu yol yalnız küçük çizgelerde işe yarar. Web çizgesinde matris gösterimi gerekir.

### Stokastik komşuluk matrisi

- Bu derste sütunlar bağlantıyı veren, satırlar bağlantıyı alan düğümlerdir.
- $i$, $j$'ye bağlantı vermişse hücreye 1 yerine $1/d_i$ yazılır. $d_i$: $i$'nin dışa giden bağlantı sayısı.
- Böylece her sütunun toplamı 1 olur. Ör. 2 bağlantı varsa $1/2 + 1/2 = 1$, 3 bağlantı varsa $1/3 + 1/3 + 1/3 = 1$.
- Sütun toplamları 1 olan matrise stokastik matris denir.
- Denklem: $r = M r$. $M$ $N \times N$ matris, $r$ $N \times 1$ PageRank vektörü.
- $M$'nin $j$. satırı ile $r$ çarpılınca $j$'ye bağlantı veren düğümlerin oransal PageRank toplamı çıkar. Bu, oyuncak örnekteki formülün aynısıdır.
- Doğrusal cebirde $A x = \lambda x$ denkleminde $\lambda$ özdeğer (eigenvalue), $x$ özvektördür (eigenvector). Burada $\lambda = 1$ ve PageRank vektörü özvektördür.
- Y, A, M örneğinin matrisi:

```
        y     a     m
  y  [ 1/2   1/2    0 ]
  a  [ 1/2    0     1 ]
  m  [  0    1/2    0 ]
```

### Power iteration

- Başlangıç: $r^{(0)}$ vektörünün her elemanı $1/N$.
- Adım: $r^{(t+1)} = M r^{(t)}$.
- Kontrol: $r^{(t+1)} - r^{(t)}$ farkı bir $\varepsilon$ değerinden küçükse dur. Değilse adımı tekrarla.
- Bir öğrenci sorar: başlangıçta neden $1/N$ veriliyor, stokastik matris zaten $1/N$ değil mi?
  - Hoca: stokastik olan $M$ matrisidir. $r$ ise PageRank vektörüdür. Hesaba başlamak için her düğüme bir başlangıç değeri vermek gerekir. $1/N$ seçmek zorunlu değil. Teori, hangi değerle başlanırsa başlansın aynı sonuca yakınsandığını söyler.
- Bir öğrenci farkın $\varepsilon$ ile karşılaştırılmasını sorar. Hoca: döngü içinde ör. 50 yineleme sonunda iki ardışık vektörün farkı neredeyse sıfır olur, orada durulur.
- Y, A, M örneğinin sonucu: $r_y = 6/15$, $r_a = 6/15$, $r_m = 3/15$.

### Rastgele yürüyüş yorumu

- Kullanıcı bir sayfadadır. Sonraki sayfaya geçmek için yalnız sayfadaki bağlantılardan birine tıklayabilir.
- Tarayıcıda geri düğmesi ve adres kutusu yok.
- Sayfada 10 bağlantı varsa her birine gitme olasılığı $1/10$.
- $t+1$ anında $j$'de olma olasılığı: $j$'ye bağlantı veren her sayfada $t$ anında olma olasılığı çarpı o sayfadan $j$'ye geçme olasılığı, toplamı.
- Bu, PageRank formülünün olasılık yorumudur: $p(t+1) = M p(t)$.
- $p$ belli bir değere yakınsarsa bu değer durağan dağılımdır, değişmez.
- Markov zinciri süreç teorisi: $M$ belli koşulları sağlarsa yakınsanan değer tektir ve başlangıç değerinden bağımsızdır.

### Üç soru ve iki sorun

- Hoca üç soru sorar:
  - Denklem yakınsar mı?
  - Yakınsadığı değer istediğimiz şey mi?
  - Sonuç mantıklı mı?
- Spider trap:
  - İki düğümlü örnek: A, B'ye; B, A'ya bağlantı verir. Başka çıkış yok.
  - Başlangıç $[1, 0]$ ise sıra $[0, 1]$, $[1, 0]$, ... diye sonsuza kadar gider. Yakınsamaz.
  - Y, A, M örneğinde M yalnız kendine bağlantı verirse: yakınsar ama sonuç tüm önemi M'ye toplar. Sıralama için kullanılamaz.
- Dead end:
  - Bir düğüm bağlantı alır ama kimseye bağlantı vermez.
  - İki düğümlü örnek: başlangıç $[1, 0]$, sonra $[0, 1]$, sonra $[0, 0]$. Yakınsar ama sonuç işe yaramaz. Değerler eşit veya sıfır olursa sıralama yapılamaz.
  - Y, A, M örneğinde M kimseye bağlantı vermezse M'nin sütunu sıfırdır. Matris stokastik olmaz. Sonuç $[0, 0, 0]$'a gider.
- Gerçek web çizgesinde ikisi de vardır: dışarıya bağlantı vermeyen düğümler ve yalnız kendi aralarında bağlantı veren alt çizgeler.

### Çözüm 1: teleport (spider trap için)

- Kullanıcıya adres kutusu verilir. İstediği an herhangi bir URL yazıp istediği sayfaya geçebilir.
- $\beta$ olasılıkla sayfadaki bir bağlantıyı izler.
- $1 - \beta$ olasılıkla rastgele bir sayfaya sıçrar. Her sayfa için olasılık $1/N$.
- Genelde $\beta = 0{,}8$ (bazen $0{,}9$). Yani %80 bağlantı izleme, %20 sıçrama.
- Kullanıcı tuzağa girse bile sıçrayarak çizgenin geri kalanına döner.

### Çözüm 2: sanal bağlantılar (dead end için)

- Çıkmaz düğümden tüm düğümlere (kendisi dahil) sanal bağlantı eklenir.
- Y, A, M örneğinde M'nin sütunu $[1/3, 1/3, 1/3]^T$ olur. Matris yeniden stokastik olur.
- Matris biçiminde: $A = M + \dfrac{1}{N}\, e\, a^T$ (tahtada gösterilen yapı).
  - $a$: dışa bağlantı sayısı 0 olan düğümler için 1, diğerleri için 0 olan vektör. Örnekte $a = [0, 0, 1]$.
  - $e$: tüm elemanları 1 olan sütun vektörü. $\frac{1}{N}e$ örnekte $[1/3, 1/3, 1/3]^T$.
  - Çarpım yalnız M sütununda $1/3$ değerleri olan, diğer yerleri 0 olan bir $N \times N$ matristir.
  - Bu matris $M$'ye eklenince çıkmaz uç kalmaz.

### Google matrisi

- İki çözüm birleşince son matris:

$$G = \beta A + (1-\beta)\frac{1}{N}\, e\, e^T$$

- Bu matris stokastik, indirgenemez (dead end yok) ve periyodik olmayan (spider trap yok) bir matristir.
- Markov zinciri teoreminin istediği koşulların hepsini sağlar. Power iteration başlangıç değerinden bağımsız olarak tek bir durağan dağılıma yakınsar.
- Hoca buna Google matrisi de dendiğini söyler, çünkü formül PageRank'i öneren Google kurucularının makalesinden gelir.
- Spider trap'li oyuncak örnekte $0{,}8$ ile $M$ ve $0{,}2$ ile rastgele sıçrama matrisi toplanır. Önce işe yaramaz bir değere yakınsayan örnek artık tek ve kullanışlı bir PageRank vektörüne yakınsar.
- PageRank algoritması 1998'de yayımlandı.

### Özet: rank prestige'den PageRank'e

- Sosyal ağ analizinde centrality ölçüleri (degree, closeness, betweenness) ve prestige ölçüleri (degree, proximity, rank) aktörün önemini verir.
- Rank prestige bağlantı verenin önemine bakar ve özdeğer denklemiyle hesaplanır.
- Google bu formülü web çizgesinin sorunlarını (spider trap, dead end) hesaba katacak biçimde değiştirdi. Buna PageRank dedi ve power iteration'ın sonuca ulaşması için gereken adımları önerdi.

### Duyurular

- Gelecek hafta (5 Ocak 2021, yeni yılın ilk haftası) normal ders var.
- Hoca dönemin son gününü kontrol etti: 9 Ocak. Bu yüzden gelecek hafta son ders haftasıdır.
- Final sınavları 11 Ocak'ta başlar, 11–23 Ocak arası iki hafta sürer.
- Hoca projeyi final haftasına aktarmak istemedi. Projeyi finallere bırakmak öğrencilerin tüm sınavlarını kötü etkiler.
- Proje sunumu için iki seçenek sundu:
  - 5 Ocak'ta, normal ders gününde proje gönderimi ve demo.
  - 9 Ocak Cumartesi sabahı, normal ders saatinde proje gönderimi ve demo.
- Öğrencilerin çoğu 9 Ocak'ı seçti. Karar: 5 Ocak'ta ders işlenecek, 9 Ocak Cumartesi proje demoları yapılacak.
- Demo herkes tarafından birebir gösterilmeli. 9 Ocak'a katılmayan ve demo göstermeyen öğrenci projeden sıfır alır. Proje sunulmazsa dersten geçmek mümkün olmayabilir.
- Hoca az bir şey gösterilecek olsa bile projenin tamamlanıp sunulmasını istedi. 10 günden fazla süre var.
- Sorular için gelecek ders veya ofis saati (office hour) kullanılabilir.

### Ders sonrası notlar

- Hoca dersin başında "Prestige Centrality metrikleri" der, hemen düzeltir: iki başlık centrality ve prestige ölçüleridir.
- Sınav listesini sayarken "Proximity Centrality" der. Doğrusu proximity prestige'dir. Betweenness listede anılmamıştır ama önceki derste hesaplanmıştı.
- Teleport anlatımında hoca önce "$\beta$ olasılıkla herhangi bir sayfaya" der, hemen düzeltir: $\beta$ olasılıkla bağlantılar izlenir, $1-\beta$ olasılıkla rastgele sayfaya sıçranır.
- Bir yerde $0{,}8$ ile "matrisi takip et", $0{,}2$ ile "herhangi bir linki takip ederek geç" der. Doğrusu: $0{,}2$ olasılıkla rastgele herhangi bir sayfaya sıçranır.
- Dead end'in indirgenemezliği, spider trap'in periyodik olmamayı bozduğu eşleşmesi hocanın anlatımıdır. Kitaplarda indirgenemezlik genelde tüm düğümlerin birbirine ulaşabilmesi (güçlü bağlılık) olarak tanımlanır. Teleport bu koşulu da sağlar.
- Google matrisinde $\beta$ için hocanın verdiği değer 0,8. PageRank'in özgün makalesinde sönüm katsayısı (damping factor) genelde 0,85 alınır.
- Hoca stokastik matrisi bu derste sütun toplamı 1 olacak biçimde kurar (sütun = bağlantı veren). Önceki derslerdeki komşuluk matrisinde satırlar bağlantı verendi. Gösterim farkına dikkat.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
