# Ders 6 Çalışma Özeti

## Genel Konular

- Büyük grafların analizi ve bağlantı analizi (link analysis)
  - Ders, kaynak kitabın (Mining of Massive Datasets) 5. bölümünü, "Link Analysis" konusunu izler (ekrandan, 00:10:00).
  - Büyük veri türleri arasında graf verisi (graph data) ele alınır. Bu türün altında PageRank/SimRank, topluluk bulma (community detection) ve spam bulma (spam detection) konuları vardır (ekrandan, 00:15:00). Derste yalnız PageRank işlenir; topluluk ve spam bulma algoritmaları kitap bölümünde yer alır.
  - Amaç, tek bir makinenin belleğine sığmayan büyük grafları işleyip ondan özet bilgi çıkarmaktır: bir görselleştirme, düğümlerin sıralaması ya da istatistik tablosu.
- Graf verisi örnekleri
  - Graf, düğümlerden (node) ve onları bağlayan kenarlardan (edge) oluşur. Kenarın yönü varsa graf yönlüdür (directed), yoksa yönsüzdür (undirected).
  - Facebook arkadaşlık grafı yönsüzdür, çünkü arkadaşlığı kimin başlattığı bilinmez. Twitter yönlüdür, çünkü kimin kimi takip ettiği bilinir.
  - Web günlükleri (blog) grafı, iki ayrı kümeye ayrışmış bir görselleştirme olarak gösterilir.
  - Atıf ağları: her makale bir düğüm, kaynakçadaki her atıf bir kenardır. Görselleştirmede renkler disiplinleri gösterir; disiplinlerin çoğunlukla kendi içinde atıf yaptığı görülür (ekrandan, 00:20:00).
  - İletişim ağları: interneti oluşturan sunucular düğüm, aralarındaki bağlantılar kenardır.
  - Web grafı: her HTML sayfası bir düğüm, her köprü (hyperlink) bir yönlü kenardır. Derste bu graf türü üzerinde durulur.
- Web'de bilgiye ulaşma ve iki temel zorluk
  - İlk yol, insanların düzenlediği web dizinleridir (Yahoo, DMOZ, LookSmart); kategoriler alt kategorilere inilerek gezilir (ekrandan, 00:25:00).
  - İkinci yol web aramasıdır. Arama motoru bir bilgi erişim (information retrieval) motorudur. Klasik bilgi erişim küçük ve güvenilir bir belge kümesinde çalışır (örneğin bir şirketin binlerce PDF belgesi). Web ise çok büyüktür; güvenilmez belgeler ve spam sayfalar içerir.
  - Birinci zorluk: sorguya uyan milyonlarca sayfa içinden güvenilir olanları bulmak.
  - İkinci zorluk: güvenilir sayfalar içinden sorguya en iyi cevabı bulmak. İkisi için de sayfaların sıralanması (ranking) gerekir.
- Sayfaların bağlantı yapısına göre sıralanması
  - Bütün web sayfaları eşit derecede önemli değildir (örnek: bilinmeyen bir kişisel site ile stanford.edu) (ekrandan, 00:30:00).
  - Çok gelen bağlantı (in-link) alan sayfa, az bağlantı alan sayfadan daha önemli kabul edilir.
  - Bağlantı analizi algoritmaları: PageRank, HITS, konuya özgü (topic-specific) PageRank, web spam bulma. Derste yalnız PageRank işlenir.
- PageRank'in iki temel fikri
  - Her bağlantı bir oy sayılır; gelen bağlantısı çok olan sayfa daha önemlidir.
  - Bütün oylar eşit değildir; önemli sayfalardan gelen bağlantılar daha çok sayılır.
  - 11 düğümlü örnekte toplam puan 100'dür; en çok bağlantı alan B en yüksek puanı (38,4), yalnız B'den bağlantı alan C ise ikinci en yüksek puanı (34,3) alır (ekrandan, 00:35:00).
- Basit özyinelemeli (akış) formülasyonu
  - $d_i$ çıkış bağlantısı olan $i$ sayfası, puanını bağlantılarına eşit böler: $r_j = \sum_{i \to j} \dfrac{r_i}{d_i}$ (ekrandan, 00:40:00).
  - Örnek: $j$ düğümüne 3 çıkışlı $i$ ve 4 çıkışlı $k$ bağlanıyorsa $r_j = r_i/3 + r_k/4$.
- Akış denklemlerinin çözümü (y, a, m örneği)
  - $r_y = r_y/2 + r_a/2$, $r_a = r_y/2 + r_m$, $r_m = r_a/2$ (ekrandan, 00:45:00).
  - Üç denklem, üç bilinmeyen var, sabit terim yok; tek çözüm yoktur. Ek kısıt $r_y + r_a + r_m = 1$ ile çözüm tekleşir: $r_y = 2/5$, $r_a = 2/5$, $r_m = 1/5$.
  - Gauss eleme küçük graflarda çalışır, web boyutunda daha iyi bir yöntem gerekir.
- Matris formülasyonu
  - Stokastik komşuluk matrisi $M$: $i \to j$ ise $M_{ji} = 1/d_i$, değilse $M_{ji} = 0$. Her sütunun toplamı 1'dir (sütun stokastik matris) (ekrandan, 00:50:00).
  - Sıralama vektörü $r$: her sayfa için bir eleman, $\sum_i r_i = 1$. Akış denklemleri $r = M \cdot r$ biçiminde yazılır.
- Özvektör formülasyonu ve kuvvet yinelemesi
  - $Ax = \lambda x$ ise $x$, $\lambda$ özdeğerli bir özvektördür. $r = M r$ olduğu için $r$, $M$'nin özdeğeri 1 olan baş (principal) özvektörüdür (ekrandan, 00:55:00).
  - Kuvvet yinelemesi (power iteration): $r^{(0)} = [1/N, \dots, 1/N]^T$ ile başla, $r^{(t+1)} = M r^{(t)}$ ile yinele, $|r^{(t+1)} - r^{(t)}|_1 < \varepsilon$ olunca dur (ekrandan, 01:10:00).
- Rastgele gezgin (random surfer) yorumu
  - Geri tuşu ve adres çubuğu olmayan bir tarayıcıda gezgin her adımda bulunduğu sayfanın çıkış bağlantılarından birini düzgün rastgele seçer (ekrandan, 01:15:00).
  - $p(t)$, gezginin $t$ anında her sayfada bulunma olasılığını veren vektördür: $p(t+1) = M \cdot p(t)$.
  - $p(t+1) = M p(t) = p(t)$ olduğunda $p(t)$ durağan dağılımdır (stationary distribution). $r = M r$ olduğu için $r$ de rastgele yürüyüşün durağan dağılımıdır (ekrandan, 01:20:00).
  - Markov zinciri teoremi: matris belirli koşulları sağlarsa durağan dağılım tektir ve başlangıç vektörü ne olursa olsun ona ulaşılır; yalnız yineleme sayısı değişir.
- PageRank'in iki sorunu
  - Örümcek tuzağı (spider trap): gezgin belirli sayıda adımdan sonra hep aynı düğüme döner. $a \leftrightarrow b$ örneğinde vektör $(1,0) \to (0,1) \to (1,0) \to (0,1)$ diye salınır, yakınsamaz (ekrandan, 01:25:00).
  - Çıkmaz uç (dead end): bağlantı alan ama hiç bağlantı vermeyen düğüm. Değerler sıfıra yakınsar; bu, sayfaların göreli önemini vermez.
- Çözüm: ışınlanma (teleport)
  - Örümcek tuzağı için: gezgin her adımda $\beta$ olasılıkla bir bağlantıyı izler, $1-\beta$ olasılıkla rastgele bir sayfaya atlar. $\beta$ genelde 0,8 ile 0,9 arasındadır (ekrandan, 01:30:00).
  - Çıkmaz uç için: çıkmaz uçtan bütün düğümlere 1,0 olasılıkla ışınlanma bağlantısı eklenir; çıkmaz ucun sütunu $1/n$ değerleriyle doldurulur (ekrandan, 01:35:00).
  - Matris biçimi: $A = M + a^T \left(\frac{1}{n} e\right)$; $a_i = 1$ eğer $i$'nin çıkış derecesi 0 ise, değilse 0; $e$ bütün elemanları 1 olan vektördür (ekrandan, 01:40:00).
  - Işınlanmalı matris: $A = \beta M + (1-\beta)\frac{1}{n} \mathbf{1}\mathbf{1}^T$. $\beta = 0{,}8$ ile y, a, m örneğinde vektör $(7/33,\ 5/33,\ 21/33)$ değerine yakınsar (ekrandan, 01:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- PageRank iki fikri birleştirir
  - Gelen bağlantı sayısı önem verir; ama önemli sayfadan gelen tek bir bağlantı, önemsiz sayfalardan gelen birçok bağlantıdan değerli olabilir (C düğümü örneği).
- Neden matris ve kuvvet yinelemesi?
  - Akış denklemleri küçük graflarda Gauss eleme ile çözülebilir; milyarlarca sayfalı web grafında bu mümkün değildir. Bu yüzden $r = Mr$ özvektör formülasyonu kuvvet yinelemesiyle çözülür.
- PageRank yönlü graf ister
  - Bir öğrencinin sorusu üzerine hoca, önemin gelen bağlantılardan hesaplandığını, bu yüzden PageRank'in yönlü graf üzerinde çalışması gerektiğini vurguladı. Facebook arkadaşlık grafı gibi yönsüz graflarda kullanılamaz; takip tabanlı graflarda, Twitter'da ve web grafında kullanılabilir.
- Markov zinciri teoreminin koşulları
  - Kuvvet yinelemesinin başlangıçtan bağımsız tek bir durağan dağılıma yakınsaması için matris stokastik, indirgenemez (irreducible) ve periyodik olmayan (aperiodic) olmalıdır.
  - Işınlanma iki sorunu birlikte giderir; ortaya çıkan matris bu üç koşulu sağlar.
- Örümcek tuzağı ile çıkmaz ucun farkı
  - Örümcek tuzağında vektör yakınsamaz (salınır). Çıkmaz uçta yakınsar ama sıfıra yakınsar; yani istenen sonuç değildir.

## Kısa Tekrar Notları

- Graf = düğüm + kenar. Yönlü (Twitter, web) ve yönsüz (Facebook arkadaşlığı) graflar vardır.
- Web aramasının iki zorluğu: güvenilir sayfayı bulmak ve en iyi cevabı bulmak. İkisi de sıralama gerektirir.
- Bağlantı = oy. Önemli sayfadan gelen oy daha değerlidir.
- Akış denklemi: $r_j = \sum_{i \to j} r_i / d_i$.
- Ek kısıt $\sum r_i = 1$ olmadan akış denklemlerinin tek çözümü yoktur.
- $M_{ji} = 1/d_i$ (eğer $i \to j$), sütun toplamları 1 (sütun stokastik).
- $r = M r$: $r$, $M$'nin özdeğeri 1 olan baş özvektörüdür.
- Kuvvet yinelemesi: $r^{(0)} = 1/N$, $r^{(t+1)} = M r^{(t)}$, $L_1$ farkı $< \varepsilon$ olunca dur.
- Rastgele gezgin: $p(t+1) = M p(t)$; durağan dağılım $p = Mp$.
- Markov zinciri koşulları: stokastik, indirgenemez, periyodik olmayan.
- Örümcek tuzağı: salınım, yakınsama yok. Çıkmaz uç: değerler sıfıra gider.
- Işınlanma: $\beta$ (genelde 0,8) ile bağlantı izle, $1-\beta$ ile rastgele sayfaya atla; çıkmaz uçtan her zaman ışınlan.
- $A = \beta M + (1-\beta)\frac{1}{n}\mathbf{1}\mathbf{1}^T$; y, a, m örneğinde sonuç $7/33,\ 5/33,\ 21/33$.

## Detaylı Açıklamalar

- **Graf verisinden özet bilgi çıkarmak.** Bu bölümde büyük veri, düğüm ve kenarlardan oluşan bir graf biçimindedir. Sosyal ağlar, atıf ağları, internet altyapısı ve web bunun örnekleridir. Bu grafların hepsi tek bir makineye sığmayacak kadar büyük olabilir. Analizin amacı, bu büyük veriden işe yarar bir özet çıkarmaktır. Bu özet, atıf ağındaki disiplin kümelerini gösteren bir görselleştirme olabilir. Düğümlerin önem sıralaması ya da graf hakkında istatistik veren bir tablo da olabilir. Derste odak, web grafındaki sayfaların önemini hesaplayan bağlantı analizidir.

- **Neden sıralama gerekir?** Web'de bir şey aramanın iki yolu vardır. Biri, Yahoo gibi insanların düzenlediği dizinlerde kategori kategori gezinmektir. Diğeri, her gün kullandığımız web aramasıdır. Arama motoru, klasik bilgi erişim motorlarının büyük ölçekli bir sürümüdür. Fakat klasik bilgi erişim küçük ve güvenilir bir belge kümesinde çalışır; bir şirkette belgeleri çalışanlar girer ve denetler. Web ise devasa ve denetimsizdir. Bazı kişiler, alakasız sayfalarının arama sonuçlarında görünmesi için içeriklerini değiştirir (spam). Bu yüzden arama motorunun hem güvenilir sayfaları hem de sorguya en iyi uyan sayfaları üst sıralara koyan bir sıralama yöntemine ihtiyacı vardır. Bağlantı analizi bunu sayfanın içeriğine bakmadan, yalnız bağlantı yapısından yapar: değerli bir sayfaya pek çok kişi bağlantı verir.

- **Akış formülasyonu.** PageRank'te her sayfa kendi puanını çıkış bağlantılarına eşit paylarla dağıtır. $j$ sayfasının puanı, ona bağlantı veren sayfalardan gelen payların toplamıdır: $r_j = \sum_{i \to j} r_i/d_i$. Slayttaki örnekte $j$'ye 3 çıkışlı $i$ ile 4 çıkışlı $k$ bağlantı verir, bu yüzden $r_j = r_i/3 + r_k/4$ olur. $j$'nin 3 çıkışı olduğu için de komşularının her birine $r_j/3$ geçer (ekrandan, 00:40:00).

- **y, a, m örneği.** Üç sayfalı küçük grafta $y$ kendine ve $a$'ya, $a$ ise $y$'ye ve $m$'ye bağlantı verir; $m$ yalnız $a$'ya bağlanır. Denklemler $r_y = r_y/2 + r_a/2$, $r_a = r_y/2 + r_m$, $r_m = r_a/2$ olur. Sabit terim olmadığından her çözümün katı da çözümdür. $r_y + r_a + r_m = 1$ kısıtı eklenince çözüm $2/5,\ 2/5,\ 1/5$ olur (ekrandan, 00:45:00; python ile doğrulandı).

- **Matris ve özvektör.** Web grafı büyük olduğu için komşuluk matrisiyle gösterilir. $i$'den $j$'ye bağlantı varsa $M_{ji} = 1/d_i$ yazılır. Örneğin 3 çıkışlı bir düğümün sütununda üç tane $1/3$ bulunur, gerisi sıfırdır; sütun toplamı 1 olur. $M$'nin $j$. satırı, $j$'ye bağlantı veren düğümlerin paylarını taşır. Bu satır $r$ vektörüyle çarpılıp toplanınca $r_j$ çıkar. Bunu bütün satırlar için yazınca $r = M r$ elde edilir. Bu, doğrusal cebirdeki $Ax = \lambda x$ özvektör denkleminin $\lambda = 1$ hâlidir; $r$, $M$'nin baş özvektörüdür (ekrandan, 00:55:00).

- **Kuvvet yinelemesi.** Başlangıçta bütün sayfalara $1/N$ verilir. Vektör her adımda $M$ ile çarpılır. Ardışık iki vektörün farkı (örneğin $L_1$ normu) $\varepsilon$'dan küçük olunca durulur. Bu noktada vektör yakınsamıştır ve sayfaların önem puanlarını verir (ekrandan, 01:10:00).

- **Rastgele gezgin yorumu.** Aynı hesap olasılık açısından da okunabilir. Gezgin geri dönemez ve adres yazamaz; yalnız bulunduğu sayfadaki bağlantılardan birine rastgele tıklar. $C$ sayfasına bağlantı veren $i_1, i_2, i_3$ sayfaları için, gezginin $t+1$ anında $C$'de olma olasılığı şöyle bulunur: her $i_k$ sayfasında bulunma olasılığı, o sayfanın çıkış sayısına bölünür ve bu değerler toplanır. Bu, akış denkleminin aynısıdır. Vektör hâlinde $p(t+1) = M p(t)$ yazılır. Yineleme sonunda değişmeyen $p$ durağan dağılımdır. Markov zinciri teoremine göre matris uygun koşulları sağlıyorsa bu dağılım tektir ve başlangıç değerlerinden bağımsızdır (ekrandan, 01:20:00).

- **Sorunlar ve ışınlanma.** Örümcek tuzağında gezgin bir düğüm kümesinden çıkamaz. $a \leftrightarrow b$ örneğinde vektör iki durum arasında gidip gelir; y, a, m grafında $m$ kendine bağlanıyorsa bütün puanı $m$ toplar. Çıkmaz uçta ise puan grafın dışına sızar ve bütün değerler sıfıra gider. Google'ın çözümü ışınlanmadır. Gezgin $\beta$ olasılıkla bağlantı izler, $1-\beta$ olasılıkla rastgele bir sayfaya atlar; böylece tuzaktan birkaç adımda çıkar. Çıkmaz uçtan ise her zaman ışınlanılır: matriste o düğümün sıfır sütunu $1/n$ değerleriyle doldurulur ve matris yeniden stokastik olur. $\beta = 0{,}8$ olan y, a, m örneğinde $A = 0{,}8 M + 0{,}2 \cdot \frac{1}{3}\mathbf{1}\mathbf{1}^T$ matrisi $\begin{pmatrix} 7/15 & 7/15 & 1/15 \\ 7/15 & 1/15 & 1/15 \\ 1/15 & 7/15 & 13/15 \end{pmatrix}$ olur. Kuvvet yinelemesi bu matriste $7/33,\ 5/33,\ 21/33$ değerlerine yakınsar (ekrandan, 01:45:00; python ile doğrulandı).
  - Ders sonrası not: Slayttaki yineleme tablosunun ikinci adımında $y$ için 0,24 yazıyor. Python hesabına göre doğrusu $0{,}28$'dir; diğer değerler (0,20; 0,52; 0,26; 0,18; 0,56) hesapla uyuşur.
  - Ders sonrası not: Hoca, çıkmaz uç düzeltmesinin matrisi "indirgenemez", $\beta$ ışınlanmasının ise "periyodik olmayan" yaptığını söyledi. Kaynak kitapta büyük olasılıkla çıkmaz uç düzeltmesi matrisi stokastik yapar; indirgenemezlik ve periyodik olmama ise rastgele ışınlanmayla sağlanır. Son matrisin üç koşulu birlikte sağladığı sonucu değişmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
