# Ders 14 Genişletilmiş Notu: HITS Algoritması ve Web Kullanım Madenciliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Link Analizinde Nerede Kaldık?
- 2. PageRank Sorgudan Bağımsızdır
- 3. HITS: Authority ve Hub
- 4. Root Set ve Base Set
- 5. HITS Denklemleri ve Power Iteration
- 6. HITS ile Co-Citation ve Bibliographic Coupling Bağı
- 7. HITS'in Zayıf ve Güçlü Yanları
- 8. Web Kullanım Madenciliğine Giriş
- 9. Veri Kaynakları ve Veriyle İlgili Sorunlar
- 10. Sunucu Günlüğünü Okumak
- 11. Web Kullanım Madenciliği Süreci
- 12. Veri Hazırlama Adımlarına Yakından Bakış
- 13. Çerez, Oturum Kimliği ve IP ile Agent
- 14. Oturum Belirleme Sezgileri
- 15. Kullanıcı Belirleme Yöntemleri
- 16. Page View Belirleme ve Yol Tamamlama
- 17. Tıklama Verisinden Olaylara
- 18. Sürece Başka Bir Bakış ve E-Ticaret Akışı
- 19. Uygulama Türleri ve Kullanılan Yöntemler

## 1. Link Analizinde Nerede Kaldık?

Hoca derse link analizi konusunda şimdiye kadar görülenleri hatırlatarak başladı. Önce sosyal ağ analizi (social network analysis) işlenmişti. Bu konunun iki temel metrik grubu vardı:

- **Centrality metrikleri:** degree centrality, closeness centrality, betweenness centrality.
- **Prestige metrikleri:** degree prestige, proximity prestige, rank prestige.

Bu metrikler oyuncak örnekler üzerinde hesaplanmış, anlamları konuşulmuştu. Ardından iki yaygın metrik daha görüldü: co-citation ve bibliographic coupling. Bu metrikler özellikle içinde referans bulunan makaleler ve dokümanlar arasında ilişki kurmak için kullanılır. Normalde iki doküman arasındaki benzerliği bulurken bilgi erişimi (information retrieval) bölümünde gördüğümüz TF-IDF tabanlı metrikleri kullanırız. Burada ise içeriğe hiç bakmayız. Yalnız iki dokümanın verdiği ya da aldığı referanslara bakarak aradaki ilişkiyi bulmaya çalışırız.

Son olarak PageRank algoritmasına geçilmişti. Nasıl hesaplandığı, matris gösterimi, spider trap ve dead end problemlerini nasıl çözdüğü ve belli bir yineleme (iteration) sonunda bütün düğümler için bir PageRank vektörüne nasıl yakınsadığı ayrıntılarıyla konuşulmuştu. Bugünün konusu, link analizinin diğer algoritması olan HITS'tir.

> **Ders sonrası not:** Hoca bu konuların hepsinden "geçtiğimiz hafta" diye söz etti. Kayıtlara göre konu büyük olasılıkla iki derse yayılmıştır: Sosyal ağ metrikleri 15 Aralık'ta (ders 11), co-citation, bibliographic coupling ve PageRank 29 Aralık'ta (ders 13) işlenmiştir.

## 2. PageRank Sorgudan Bağımsızdır

Hoca önce PageRank'in popülerite tanımını hatırlattı: Bir düğüm çok sayıda düğümden link alıyorsa ve link aldığı düğümlerin popüleritesi de yüksekse bu düğümün popüleritesi de yüksek olur. Bu özyinelemeli (recursive) bir yaklaşımdır. Bir düğümün PageRank'ini kendisine link veren düğümlerden yola çıkarak buluruz. Bu düğümün PageRank'i de link verdiği düğümlerin PageRank değerini bulmakta kullanılır.

Bu yaklaşım sorgudan bağımsızdır (query independent). Arama şöyle ilerler:

1. Google'a sorgu girilir.
2. Sorgu, ters dizin (inverted index) tablosundaki anahtar kelimelerle karşılaştırılır.
3. Bu anahtar kelimelerin bulunduğu girişlerdeki sayfalar alınıp birleştirilir ve bir arama sonucu listesi oluşturulur.
4. Liste, önceden hesaplanmış PageRank skoru tablosuna bakılarak yeniden sıralanır.

Dikkat edilecek nokta şudur: PageRank skorları önceden hesaplanır. Sorgu ne derse desin bu skorlar değişmez.

Bunun doğurduğu sorunu hoca bir örnekle anlattı. "Web data mining" kelime üçlüsünü aradığınızı düşünün. Normalde bu isimli kitabın bulunduğu sayfanın ilk 10 sonuçta çıkmasını beklersiniz. Fakat içinde bu kelimeler geçen ve PageRank skoru çok yüksek başka sayfalar varsa, sonuçlar PageRank'e göre yeniden sıralandığı için kitabın sayfaları ilk 10'a giremeyebilir. Sırf popüleritesi yüksek olduğu ve içinde bu kelimeler geçtiği için başka sayfalar ilk 10'a girmiş olur. Bu durum PageRank'in sorgudan bağımsız olmasından kaynaklanır.

## 3. HITS: Authority ve Hub

PageRank'in ortaya çıktığı yıllarda, 1998'de, PageRank Stanford Üniversitesi'nden çıkarken Cornell Üniversitesi'nden de sayfaların popüleritesini hesaplamaya yönelik başka bir algoritma çıktı: HITS (Hypertext Induced Topic Search). HITS'in PageRank'ten farkı sorguya bağlı (query dependent) olmasıdır. Skorlar hesaplanırken arama sorgusu dikkate alınır.

HITS'te her sayfanın iki ayrı skoru vardır:

- **Authority (otorite) skoru:** Bir sayfanın otoriter sayılması için çok sayıda sayfanın ona link vermesi gerekir. Yani otoriter sayfa çok sayıda link alır.
- **Hub (merkez) skoru:** Bir sayfanın hub sayılması için çok sayıda giden linki olması gerekir. Yani hub sayfası çok sayıda sayfaya link verir.

HITS, bu iki tür sayfa arasında karşılıklı pekiştirme (mutual reinforcement) ilişkisi olduğunu varsayar:

- İyi hub sayfaları iyi authority sayfalarına link verir.
- İyi authority sayfaları iyi hub sayfalarından link alır.

<!-- BELİRSİZ: Hoca mutual reinforcement tanımını okurken altyazı "e-hub sayfaları, e-hub sayfaları link verir" diye bozuk geçiyor. Yukarıdaki biçim hocanın 00:25:17 ve 00:25:59'da açıkça söylediği cümlelerden alındı. Slayttaki şekil altyazıda yalnız sözlü olarak geçiyor. -->

Hoca, bu varsayıma dayanarak sayfaların başarılı biçimde sıralanıp sıralanamayacağına bakmak için algoritmanın adımlarına geçti.

## 4. Root Set ve Base Set

HITS sorgu geldiğinde şu adımlarla çalışır:

1. **Root set oluşturma:** Sorguyla eşleşen ters dizin girdileri bulunur. Örneğin "web data mining" aranıyorsa bu kelimeleri içeren anahtarların girişlerindeki HTML sayfaları alınır ve birleştirilir. Elde edilen arama sonucu kümesine root set (kök küme) denir ve büyük $W$ ile gösterilir.
2. **Link verilen sayfaları bulma:** Root set'teki dokümanların bir derece sonrasında link verdiği dokümanlar bulunur.
3. **Link veren sayfaları bulma:** Root set'teki dokümanlara bir derece önceden link veren dokümanlar bulunur.
4. **Base set oluşturma:** Root set'teki sayfalar, bu sayfaların link verdiği sayfalar ve root set'e link veren sayfalar birleştirilir. Bu yeni kümeye base set (taban küme) denir ve büyük $S$ ile gösterilir.
5. **Küçük graf kurma:** Base set içindeki linkler kullanılarak küçük bir web grafı kurulur. Bu grafın komşuluk matrisi (adjacency matrix) $L$ ile gösterilir. Bir düğüm diğerine link veriyorsa ilgili hücre 1, vermiyorsa 0 olur.

Peki bu sayfalar nereden bulunur? Elimizde web grafı ve bu grafı tanıtan komşuluk matrisi vardır. Bu matrise bakarak root set'teki sayfaların hangi sayfalara link verdiğini ve hangi sayfaların root set'e link verdiğini tespit edebiliriz.

> **Ders sonrası not:** Hoca "oluşturduğum küçük web grafa adjacency matrix diyorum" dedi; doğrusu küçük web grafı başka, onu gösteren komşuluk matrisi $L$ başkadır.

## 5. HITS Denklemleri ve Power Iteration

### 5.1 Tek Sayfa İçin Denklemler

HITS'in iki varsayımı birer denkleme dönüştürülür. İyi otoriter sayfa iyi hub sayfalarından link alır. O halde $i$ sayfasının otorite skoru, $i$'ye link veren sayfaların hub skorlarının toplamıdır. İyi hub sayfası da iyi otoriter sayfalara link verir. O halde $i$ sayfasının hub skoru, link verdiği sayfaların otorite skorlarının toplamıdır:

$$a(i) = \sum_{(j,i) \in E} h(j), \qquad h(i) = \sum_{(i,j) \in E} a(j)$$

Hoca burada bir şeye dikkat çekti: Üstteki denklemdeki hub değerinin yerine alttaki denklemin sağ tarafı, alttaki denklemdeki otorite değerinin yerine de üstteki denklemin sağ tarafı konabilir.

### 5.2 Matris Gösterimi

Bu iki denklem yalnız bir düğümün skorunu verir. PageRank'te de önce tek düğümün skorunu konuşmuş, sonra çok sayıda düğümü aynı anda hesaplamak için matris gösterimine geçmiştik. Burada da aynısı yapılır:

$$a = L^{T} h, \qquad h = L\,a$$

Otorite kolon vektörü, komşuluk matrisinin transpozu ile hub kolon vektörünün çarpımıdır. Hub kolon vektörü de komşuluk matrisi ile otorite kolon vektörünün çarpımıdır. Slaytta vektörler satır vektörünün transpozu olarak gösterilmiştir, yani ikisi de kolon vektörüdür. Artık tek düğüm için değil, bütün düğümler için birer otorite ve hub vektörü hesaplanır.

### 5.3 Yerine Koyma

Üstteki denklemde $h$ yerine $L\,a$, alttaki denklemde $a$ yerine $L^{T}h$ yazılır:

$$a = L^{T} L\, a, \qquad h = L\, L^{T} h$$

$L^{T}$ ve $L$ birer $N \times N$ matristir. Çarpımları da $N \times N$ bir matristir.

### 5.4 Power Iteration ile Çözüm

Hoca, PageRank'te de böyle bir denklemle karşılaştığımızı hatırlattı. Orada sağdaki kolon vektörü sıfırıncı durumdaysa soldaki birinci durumdadır. Sonra sonuç alınıp sağa konur. Sağdaki birinci durumdaysa soldaki ikinci durumdadır. Bu şekilde yineleyerek denklemi çözmeye power iteration denmişti. Burada da aynısı yapılır:

$$a^{(k+1)} = L^{T} L\, a^{(k)}, \qquad h^{(k+1)} = L\, L^{T} h^{(k)}$$

Başlangıçta sıfırıncı durumda bütün skorlar 1 alınır. Yöntem bu noktadan başlayarak çalıştırılır. Hoca, belli bir yinelemeden sonra iki vektörün de değişmeyen sabit değerlere yakınsayacağını söyledi. Böylece base set içindeki her düğüm için hem otorite hem hub skoru bulunmuş olur.

> **Ders sonrası not:** Hoca denklemi $a = L^{T}L\,a$ biçiminde yazıp vektörlerin sabit değere yakınsadığını söyledi, normalizasyondan söz etmedi. Doğrusu her yinelemede vektörlerin normalize edilmesidir. Normalizasyonsuz yinelemede vektörün boyu sürekli büyür, yalnız yönü sabitlenir. Yakınsamada da tam eşitlik değil $L^{T}L\,a = \lambda\,a$ orantısı sağlanır. Bu davranış python ile rastgele graflarda doğrulandı. Slayttaki algoritmada büyük olasılıkla bir normalizasyon adımı vardır, altyazıdan doğrulanamıyor.

> **Ek bilgi (derste anlatılmadı):** $L^{T}L\,a = \lambda\,a$ biçimindeki denklem bir özvektör denklemidir. Power iteration, matrisin en büyük özdeğerine karşılık gelen özvektöre yaklaşır. Yani otorite vektörü $L^{T}L$'nin, hub vektörü de $LL^{T}$'nin asıl özvektörüdür. Ders 13'te PageRank için görülen $r = Mr$ denklemiyle benzerlik buradan gelir.

### 5.5 Hesap Neden Hızlıdır?

Base set içindeki düğüm sayısı fazla değildir. Slayttaki örnekte root set 200 sayfadır. Base set bundan büyük olur, hocanın verdiği tahminle belki 500 sayfa olur. Ama bu büyük bir matris değildir. Bu yüzden otorite ve hub skorlarını bu küçük matris üzerinde hesaplamak oldukça hızlıdır.

HITS de özyinelemeli bir algoritmadır. Slayttaki algoritmada ise yineleme yöntemiyle çözülmüştür. Girdi olarak base set düğümlerinden oluşan graf verilir. Bir döngü içinde iki denklem için power iteration çalıştırılır. Çıktı olarak otorite ve hub kolon vektörleri elde edilir.

<!-- BELİRSİZ: Slayttaki algoritmanın sözde kodu altyazıda satır satır okunmuyor; yalnız genel yapısı anlatılıyor. -->

## 6. HITS ile Co-Citation ve Bibliographic Coupling Bağı

Hoca burada ilginç bir tespit yaptı. Otorite hesabında geçen "komşuluk matrisinin transpozu çarpı komşuluk matrisi" ifadesiyle co-citation hesabında da karşılaşırız. Ders 13'te iki düğüm arasındaki co-citation değeri şöyle bulunuyordu:

$$C_{ij} = \sum_{k=1}^{n} L_{ki}\, L_{kj}$$

Bu formül matris biçiminde $C = L^{T}L$ olarak yazılabilir. Aynı şekilde hub formülündeki "komşuluk matrisi çarpı transpozu" da bibliographic coupling formülünden tanıdıktır:

$$B_{ij} = \sum_{k=1}^{n} L_{ik}\, L_{jk}$$

Bu da $B = LL^{T}$ olarak yazılır. Demek ki:

- Otorite denklemindeki $L^{T}L$ aslında co-citation matrisidir.
- Hub denklemindeki $LL^{T}$ aslında bibliographic coupling matrisidir.

Bu eşitlikler python ile rastgele graflarda doğrulandı.

<!-- BELİRSİZ: Hoca iki formülü slayttan gösteriyor ("şu formül"), altyazıda harfleri okunmuyor. Toplam biçimleri ders 13 notundan alındı. -->

## 7. HITS'in Zayıf ve Güçlü Yanları

Sonuçta HITS bütün sayfalar için otorite ve hub skorlarını bulur ve arama sonuçlarını bu değerlere göre sıralar. Hoca, bunun PageRank'e göre ne fark yarattığını sordu.

**Spam'e açıklık.** PageRank yalnız gelen linklere (in-link) dayanır. Kendisine link veren düğümlerden yola çıkarak popülerite hesaplar ve bu düğümlerin PageRank'lerini kendine yansıtır. HITS ise link vermeyi de hesaba katar. Root set'ten base set'e geçerken root set'teki sayfaların verdiği linkleri de alır. Bu sayfalardaki linkler gereğinden fazlaysa ya da spam yapmak amacıyla konmuşsa, base set'e sorguyla ilgisi olmayan gereksiz sayfalar girer. Hocaya göre PageRank'ten en büyük fark budur. HITS kolaylıkla spam edilebilir bir yöntemdir.

**Sorgu anında hesap.** HITS otorite ve hub skorlarını sorgu sırasında hesaplar: Sonuçları oluşturur, buna root set der, base set'i kurar, komşuluk matrisini oluşturur ve skorları hesaplar. Matristeki düğüm sayısı az olsa bile sorgu anında hesap yapıldığı için arama performansı düşer.

**Konu kayması (topic drift).** Root set'teki sayfalar ilgisiz sayfalara link verebilir. Normalde sonuçlarda sorguyu ve onun etrafındaki sayfaları görmek isteriz. Fakat yöntem spam'e açık olduğu için sonuçlar konudan kayabilir.

**Sorguya bağlılık.** HITS'in PageRank'e göre avantajı budur. PageRank, popüleritesi yüksek başka sayfalar yüzünden sorguya en otoriter cevabı verecek sayfaları ilk 10 sonuçta gösteremeyebilir. Hocanın örneği Wikipedia'ydı: Bazen belli bir sorgu için en otoriter sayfa Wikipedia sayfasıdır, ama ondan daha popüler sayfalar ilk 10 sonucu alabilir. Hoca, HITS'in sorguya bağlı olduğu için bunu yapmadığını söyledi.

> **Ders sonrası not:** Hoca soruyu "ne gibi avantajı oldu?" diye açtı ve sorgu anında hesabı "diğer bir önemli avantaj" diye sundu; doğrusu spam'e açıklık, sorgu anında hesap ve konu kayması HITS'in dezavantajlarıdır. Hoca bu maddelerin sonuçlarını kendisi de olumsuz anlatmıştır. Asıl avantaj sorguya bağlı olmaktır.

> **Ders sonrası not:** Hoca HITS'in sorguya en otoriter sayfayı dışarıda bırakma durumunu "yapmıyor" dedi; doğrusu bu kesin bir garanti değildir. Aynı derste anlatılan konu kayması da sonuçları sorgudan uzaklaştırabilir.

Hoca böylece link analizini bitirdi.

> **Hocanın vurgusu:** Konuşulan metriklerin hepsi çok önemlidir ve sınavda çok büyük ihtimalle karşınıza çıkacaktır. Size verilen örnek bir graf üzerinde nasıl hesaplandıklarını çok iyi bilmeniz gerekir. PageRank, HITS, co-citation, bibliographic coupling ve sosyal ağ analizi metriklerini iyi çalışın.

Hoca sorular için durdu. Bir öğrencinin sorusu kayıtta duyulmuyor. Hocanın cevabından, örneklerin üzerinden geçilmesinin istendiği anlaşılıyor. Hoca sınav öncesinde bu örneklerin üzerinden geçeceğini söyledi.

## 8. Web Kullanım Madenciliğine Giriş

Yeni konu web kullanım madenciliğidir (web usage mining). Kitapta 12. bölüme karşılık gelir. Hoca, derse başlarken web madenciliğini üç temel kategoride ele aldıklarını hatırlattı:

| Kategori | Derste işlendiği yer |
|---|---|
| Web içerik madenciliği (web content mining) | 6. bölüm ve web taraması (web crawling) bölümü |
| Web yapı madenciliği (web structure mining) | Sosyal ağ analizi bölümü |
| Web kullanım madenciliği (web usage mining) | Şimdi işlenecek bölüm |

Üzerinde çalışılan veri tıklama akışı verisidir (clickstream data). Web sayfalarında gezinirken izler bırakırız. Buna davranış verisi de diyebiliriz. Sayfanın kullanıcı arayüzündeki nesnelere tıkladıkça olaylar (event) oluşur ve bu olaylar günlük (log) dosyalarına yazılır. Bu dosyalar iki türlü olabilir:

- **Uygulama sunucusunun kendi günlükleri:** IIS, Apache Tomcat, GlassFish gibi sunucular, üzerlerinde çalışan web uygulamalarına yönlendirilen her türlü olayı kaydeder.
- **Web uygulamasının kendi günlükleri:** Uygulama da kendi üzerinde gerçekleşen olayları kaydedebilir.

> **Ders sonrası not:** Altyazıda sunucu "ISS" diye geçiyor; doğrusu büyük olasılıkla Microsoft IIS'tir.

Web kullanım madenciliğinde insanların gezinme (navigation, browsing) davranışları sonucu sunucu tarafında oluşan bu kayıtlar üzerinde analiz yaparak davranışları anlamaya çalışırız. Bu işi yapan bir insan olmayabilir, bir yazılım ajanı (software agent) da olabilir. Amaç davranış örüntülerini tespit etmektir. Bu sayede kullanıcının sayfada ne yapmaya çalıştığını ya da bir sonraki adımını tahmin etmek isteriz.

## 9. Veri Kaynakları ve Veriyle İlgili Sorunlar

### 9.1 Veri Kaynakları

Üzerinde çalışılan veri tipleri şunlardır:

- Web sunucusu günlük dosyaları.
- Uygulamaya ait günlük dosyaları.
- Web sitesinin içeriği ve link yapısı. Ana sayfayı ve menüdeki gezinme linklerini düşünürseniz sitenin bir link yapısı ve bir içeriği vardır.
- Müşteri ilişkileri yönetimi (CRM) veri tabanları. Müşterilerin form doldurarak ya da kredi kartı bilgisi girerek verdiği bilgiler burada saklanır.

Bu farklı kaynaklar kullanılarak müşterilerin davranışları anlaşılmaya çalışılır ve buna göre aksiyonlar üretilir.

### 9.2 Eksik Veri: Proxy Cache Sorunu

Müşteri davranışlarıyla ilgili veriler her zaman elimizde olmaz, bir kısmı eksiktir. Hoca bunu vekil önbellek (proxy cache) ile açıkladı. Sunucuya giden istekler önce önbelleğe gelir. Veri önbellekte yoksa sunucuya gidilir, veri önbelleğe getirilir ve istemciye gönderilir. Aynı veri yeniden istenirse artık önbellekten karşılanır.

Hocanın örneği şöyledir: Ana sayfaya A, onun altındaki sayfaya B, onun altındakine C diyelim. Kullanıcı önce A'ya, sonra B'ye, sonra C'ye gitti. Bu üç sayfa da önbelleğe alındı. Kullanıcı şimdi B'ye dönerse istek önbellekten karşılanır. Sunucuya ulaşmadığı için günlüğe de yazılmaz. Böylece kullanıcının bazı davranışlarını kaçırmış oluruz.

### 9.3 Dağınık Veri

Veriler farklı yerlerdedir. Bir kısmı IIS ya da Tomcat sunucusunun günlüğünde, bir kısmı uygulamanın kendi günlüğünde, bir kısmı CRM veri tabanında, bir kısmı site içeriğindedir. Bunların hepsinin bütünleştirilip tek bir kullanıcı işlem veritabanında (user transaction database) toplanması gerekir.

### 9.4 Modelleme İhtiyacı

Web kullanım madenciliğinde en çok tıklama akışı verisi üzerinde çalışılır. Bu verinin de modellenmesi gerekir. Hoca bunu ilerleyen kısımda ele alacağını söyledi.

## 10. Sunucu Günlüğünü Okumak

> **Hocanın vurgusu:** "Bu şekle iyi bakın arkadaşlar, bu şekil önemli."

Şekilde bir web sunucusu günlüğünün kayıtları görülür. Bir kullanıcı bir üniversite sitesinde `classes` dizini altındaki CS589 dersinin `papers.html` sayfasını tarayıcıdan istemiştir.

<!-- BELİRSİZ: Slayttaki günlük kayıtları altyazıda yalnız sözlü geçiyor. Alan adı altyazıda "mayacsdepol.edu" ve "Maya CS Depot Edu" diye bozuk; büyük olasılıkla ders kitabındaki DePaul Üniversitesi örneğidir. Kayıtların tarih, saat ve IP değerleri okunmuyor. -->

Bir kayıt şu bilgileri taşır:

- İsteğin geldiği tarih ve saat.
- İsteğin geldiği IP adresi.
- İsteğin gittiği sunucu.
- HTTP sürümü, örnekte 1.1.
- İstenen sayfa.
- Yönlendiren sayfa (referrer), yani bu sayfanın linkinin alındığı sayfa.
- Kullanıcının tarayıcısı.
- Kullanıcının işletim sistemi ve sürümü.

Bütün bu bilgiler HTTP isteğinin içinden yakalanır.

Kayıtları sırayla okuyunca kullanıcının yaptıkları ortaya çıkar:

1. `papers.html` sayfasına girer.
2. Bu sayfadan bir PDF ister.
3. Google'da arama yapar ve sonuçlardan birine tıklar. Bu da bir PDF bağlantısıdır.
4. CS480 dersinin sayfasından duyuru (announcement) bağlantısına tıklar. Kullanıcı yalnız bu sayfayı görüntülemek istemiştir. Fakat tarayıcı sayfayı gösterebilmek için arka planda iki farklı nesne için daha istek gönderir. Son kullanıcı bunları özel olarak istememiştir.

Böylece bir kullanıcının davranışını günlükten okumuş olduk. Hedefimiz bunu gözle değil, makine öğrenmesi teknikleriyle yapmaktır. Bunu başarırsak kullanıcının sayfada gezerkenki niyetini tespit edebiliriz.

## 11. Web Kullanım Madenciliği Süreci

Hoca süreci önce yukarıdan bakarak anlattı:

```
Web/uygulama sunucusu günlükleri + site içeriği
  -> Veri ön işleme (data preprocessing)
  -> Kullanıcı işlem veritabanı
  -> Makine öğrenmesi yöntemleri
  -> Kurallar, örüntüler, modeller
  -> Örüntü analizi (pattern analysis)
  -> Kullanıcı davranışlarının tanımlanması
```

### 11.1 Veri Ön İşleme Adımları

Girdi olarak iki kaynak vardır: günlük dosyaları ve belli bir alana göre oluşturulmuş sayfa içeriği. Bunlar üzerinde şu ön işleme adımları yapılır:

- **Veri temizleme (data cleaning):** Peşinde olduğumuz şey normal kullanıcıların davranışıdır. Bu yüzden robotların, örneğin tarayıcı programların (crawler) yaptığı istekler tespit edilip günlükten çıkarılır.
- **Page view belirleme (page view identification):** Az önceki duyuru sayfasında peş peşe gelen üç istek tek bir page view demektir. Yani page view, bir sayfayı görüntülemek için gerçekleşen istekler zinciridir. Çok sayıda HTTP isteği içinden hangilerinin bir page view amacıyla yapıldığı belirlenmelidir.
- **Oturum belirleme (sessionization):** Bir kullanıcı siteye sabah, öğlen ve akşam girebilir. Her girişinde login ile logout arasındaki ya da tarayıcıyı açıp sayfaya girmekle tarayıcıyı kapatmak arasındaki zaman aralığı bir oturumdur (session). Bu oturumlar günlüğe bakılarak tespit edilmelidir.
- **Veri bütünleştirme (data integration):** Günlüklerdeki, CRM veri tabanlarındaki ve site içeriğindeki müşteri verileri birleştirilir.
- **Veri dönüştürme (data transformation):** Bütün veri bir kullanıcı işlem veritabanına dönüştürülür.

### 11.2 Kullanıcı İşlem Veritabanı

Kullanıcı işlem veritabanı, satırlarında kullanıcılar bulunan ve her satırda kullanıcının sıralı hareketlerinin yazıldığı veritabanıdır. Hoca bunu iki kolonlu bir tablo olarak düşünmemizi istedi. Birinci kolonda müşteri ya da müşterinin oturumu, ikinci kolonda o oturumdaki sıralı aktiviteler vardır:

| Kullanıcı ve oturum | Sıralı aktiviteler |
|---|---|
| user 1, session 001 | ana sayfa, onun altındaki sayfa, onun altındaki sayfa |

### 11.3 Makine Öğrenmesi Yöntemleri

Bu veritabanı oluşturulduktan sonra üzerinde daha önceki derslerde öğrenilen makine öğrenmesi algoritmaları çalıştırılabilir:

- **Birliktelik kuralı madenciliği (association rule mining):** Gözetimsiz öğrenme (unsupervised learning) yöntemlerinden biridir. Birlikte satılan ürünleri, yani birliktelikleri tespit etmek için kullanılır.
- **Sıralı örüntü madenciliği (sequential pattern mining):** Sıralı eylemleri tespit eder. Bir sitede popüler olarak hangi aksiyonların sırayla gerçekleştiği bulunursa, bu aksiyonların bir kısmını yapmış kullanıcıların sonraki adımı kural tabanlı olarak tahmin edilebilir.
- **Kümeleme (clustering):** Dersin başında görülen gözetimsiz öğrenme yöntemleridir. Hoca bunlarla işlemleri (transaction) ve page view'ları tespit edebileceğimizi söyledi.
- **Korelasyon analizi ve müşteri kaybı (churn) analizi.**
- **Sınıflandırma (classification):** Gözetimli öğrenme (supervised learning) algoritmalarıyla kişinin bir sonra ne yapacağı tahmin edilebilir.

Algoritmaların çıktıları yönteme göre değişir:

| Yöntem | Çıktı |
|---|---|
| Birliktelik kuralı madenciliği | Support ve confidence değerli kural kümesi |
| Sıralı örüntü madenciliği | Belli support ve confidence değerli sıralı eylem dizileri |
| Kümeleme | Kümelerden oluşan model |
| Sınıflandırma | Gözetimli öğrenme modeli |

> **Ek bilgi (derste anlatılmadı):** $A \Rightarrow B$ kuralında destek (support), $A$ ve $B$'yi birlikte içeren işlemlerin bütün işlemlere oranıdır. Güven (confidence) ise $A$'yı içeren işlemler içinde $B$'yi de içerenlerin oranıdır. Yani güven, $P(B \mid A)$ koşullu olasılığının veriden kestirimidir.

> **Ek bilgi (derste anlatılmadı):** Müşteri kaybı (churn) analizi, müşterilerin bir hizmeti bırakıp bırakmayacağını inceleyen analizdir.

### 11.4 Örüntü Analizi

Model ya da örüntü oluştuktan sonra örüntü analizi yapılır. Kural tabanlı bir sistemde önemli olmayan kurallar süzülür. Kümeleme yapıldıysa oluşan kümelerin neye karşılık geldiği tanımlanmaya çalışılır. Amaç, modelin kullanıcı davranışını tanımlamada kullanılabilir hale gelmesidir.

## 12. Veri Hazırlama Adımlarına Yakından Bakış

### 12.1 Veri Hazırlama Şeması

Ders aradan sonra veri hazırlama (data preparation) kısmına odaklanan bir şemayla sürdü. Şemanın en üstünde web ve uygulama sunucusu günlükleri, en altında kullanıcı işlem veritabanı vardır. Akış iki aşamalıdır:

```
Sunucu günlükleri
  -> Kullanım ön işleme (usage preprocessing)
       veri kaynaştırma (data fusion), temizleme,
       page view belirleme, oturum belirleme, bölüm belirleme
  -> Ön işlenmiş tıklama akışı verisi
  -> Veri bütünleştirme (CRM verisi + site içeriği)
  -> Genelleştirme (gerekirse kolonları birleştirme)
  -> Kullanıcı işlem veritabanı
```

Veri kaynaştırma (data fusion), veri bütünleştirme demektir: Farklı yerlerden gelen veriler birleştirilir. İkinci aşamada oluşan yeni tablo üzerinde, gerekiyorsa birden fazla kolon birleştirilerek başka bir kolon oluşturulur.

### 12.2 Bölüm Belirleme

Şemada yeni bir adım vardır: bölüm belirleme (episode identification). Bir oturum içinde kullanıcı önceden tanımlı iş süreçlerinden birini gerçekleştiriyor olabilir. Her iş sürecine bir bölüm (episode) diyebiliriz. Hocanın örnekleri şunlardır:

- **Kredi kartıyla satın alma:** Ürünü görüntüler, özelliklerine bakar, sepete koyar, sepeti bir adım ileri götürür, kredi kartı bilgilerini girer ve ödemeye başlar.
- **Favorilere alma:** Ürünü görüntüler, favorilere al düğmesine basar, istek listesi (wishlist) bölümüne gider.
- **Yardım alma:** Yardım için izlenecek bir iş süreci de vardır.

Bölüm belirlemede amaç, kullanıcının oturum içindeki davranışlarıyla hangi bölümü gerçekleştirmeye çalıştığını tespit etmektir.

### 12.3 Ham Günlükten Bölüme

Bir sonraki slayt ön işlemeyi daha ayrıntılı gösterir:

1. Ham günlük üzerinde veri temizleme yapılır.
2. Kullanıcılar ve oturumlar belirlenir.
3. Tıklama akışı verisi üzerinde page view'lar belirlenir.
4. Proxy cache yüzünden sunucuya ulaşmayan istekler için yol tamamlama (path completion) yapılır. Eksik istekler tespit edilip günlükte tamamlanır.
5. Oturum içinde kullanıcının gerçekleştirmeye çalıştığı bölümler belirlenir.

### 12.4 Temizlikte Yapılanlar

Hoca bu adımlarda neler yapıldığını da sıraladı:

- İlgisiz referanslar silinir.
- Spider ya da crawler kaynaklı HTTP istek kayıtları silinir.
- Hatalı kayıtlar silinir. Bunlar günlük kütüphanesinden ya da o anda aynı sunucuda çalışan başka uygulamaların günlük dosyası üzerinde işlem yapmaya çalışmasından kaynaklanabilir.
- Önbellek yüzünden eksik kalan kayıtlar tamamlanır.
- Oturumlar belirlenir.

## 13. Çerez, Oturum Kimliği ve IP ile Agent

Hoca, oturumların nasıl belirleneceği sorusuna kullanıcıyı tanıma sorusundan girdi. Üç durum vardır.

### 13.1 Çerez Var

Bir sayfayı incelerken tarayıcı o sayfa için bir çerez (cookie) oluşturur. Çerez dosyasının içinde benzersiz bir çerez kimliği (cookie ID) bulunur. Aynı sayfayı daha sonra yeniden ziyaret ettiğimizde geri gelen kullanıcı olduğumuz bu kimlikle anlaşılır. Neredeyse her sayfa, tarayıcının yerel ortamındaki bir klasöre çerez bırakmak ister. Çerezleri engelleyen seçeneği seçmediyseniz, onayınızı da alarak bırakır. Çerez varsa kullanıcılar bu kimlikle tanınabilir.

> **Ders sonrası not:** Hoca çerezi tarayıcının oluşturduğunu söyledi; doğrusu büyük olasılıkla çerezin sitenin sunucusu tarafından belirlenmesi, tarayıcının ise onu saklayıp sonraki isteklerde göndermesidir.

### 13.2 Oturum Kimliği Var ya da Yok

Çerez kullanıcıyı tanıtır ama oturumları da tespit etmemiz gerekir. Kullanıcı sabah, öğlen ve akşam geldiyse bunların her biri ayrı oturumdur. Hangi aktivitenin hangi oturuma ait olduğu bulunmalıdır.

Gelen HTTP isteğinde oturum kimliği (session ID) varsa gerçek oturum bütün ayrıntılarıyla yakalanır. Fakat çoğu zaman istekte çerez kimliği olsa da gömülü oturum kimliği (embedded session ID) bulunmaz. Yani kullanıcıyı biliriz, ama aktivitelerin hangi oturuma ait olduğunu bilmeyiz. Bu durumda sezgisel (heuristic) yöntemler kullanılır.

### 13.3 Çerez de Yok

Kullanıcı tarayıcısında çerezleri engellemiş olabilir. O zaman tarayıcı yerel ortama çerez bırakamaz. Bu durumda genel olarak kullanılan yöntem IP adresi ile agent bilgisini birleştirmektir (concatenate). Agent bilgisinin içinde şunlar vardır:

- İşletim sistemi ve sürümü.
- İşletim sisteminin üzerindeki yazılım paketi ya da güvenlik paketi varsa adı.
- Kullanılan tarayıcı, modeli ve sürümü.

Bu bilgiler IP adresiyle birleştirilir ve sonuç kullanıcıyı temsil eden kimlik olarak kullanılır.

Yöntemin bir sorunu vardır. Çoğu yerde kablosuz internet kullanır ve dinamik IP alırız. Bilgisayarımız sürekli değişen IP'lerle bağlanır. Aynı tarayıcıyı kullansak bile IP değiştiği için sunucu bizi farklı bir kullanıcı gibi değerlendirebilir. Statik IP'den bağlanıyorsak IP ve agent ikilisi benzersiz bir kimlik olabilir.

## 14. Oturum Belirleme Sezgileri

Kullanıcı kimliğinin çerez ya da IP ve agent yoluyla bilindiği durumda oturumları bulmak için iki sezgisel yöntem vardır: zaman tabanlı (time-oriented heuristic) ve gezinme tabanlı (navigation-oriented heuristic).

### 14.1 Zaman Tabanlı Sezgi

Deneysel çalışmalar bir oturumun 30 dakikayı geçmeyeceğini söyler. Bu değer yapılandırılabilir. Bankacılık alanı için belki 15 dakikadır, başka bir alan için belki 45 dakikadır. Genelde 30 dakika kullanılır.

<!-- BELİRSİZ: Hocanın 45 dakika için verdiği alan altyazıda "trend yolu ya da FC bu aradaki domen" diye bozuk geçiyor; büyük olasılıkla e-ticaret sitelerinden söz ediyor. -->

Yöntem şöyle işler:

- Oturum, karşılaşılan ilk HTTP isteğinin zamanıyla başlar. Bu zamana 30 dakika eklenir ve bu aralığa giren bütün aktiviteler bir oturum sayılır.
- Bu aralıktan sonraki ilk isteğin zamanı yeni oturumu başlatır. Ona da 30 dakika eklenir.
- Ek bir kural daha vardır: Bir sayfada 10 dakikayı geçerseniz oturum 30 dakikayı beklemeden biter. Diyelim ki oturum başladı ve daha ilk sayfada 10 dakikadan fazla zaman harcıyorsunuz. Yöntem kalan 20 dakikayı beklemez, oturumu bitirip sonrakini başlatır.

Özetle bir oturumun toplam süresi 30 dakikayı, bir oturumda bir sayfaya harcanan zaman da 10 dakikayı geçemez.

### 14.2 Gezinme Tabanlı Sezgi

Bir HTTP isteğinde, istenen sayfaya hangi sayfadan gelindiğini belirten bir yönlendiren alanı vardır. Bu alan boşsa kullanıcı tarayıcının adres kutusuna adresi kendisi yazmış demektir. Herhangi bir bağlantıya tıklayarak gelmemiştir. Hoca bu durumda oturumun burada başladığını söyledi. Yönlendireni olmayan bir sonraki isteğe kadar geçen bütün aktiviteler aynı oturumdur.

> **Ders sonrası not:** Hoca yönlendiren alanının ancak adres elle yazıldığında boş kalacağını söyledi; doğrusu bu alan büyük olasılıkla yer imiyle açılan isteklerde de boş kalır. Bu yüzden yöntem kesin değil, sezgiseldir.

### 14.3 Oyuncak Örnek

Slaytta tek bir kullanıcının kayıtları vardır. Kullanıcı kimliği çerez kimliğinden ya da IP ve agent birleşiminden bulunmuş olabilir.

> **Ders sonrası not:** Hoca burada "user ID, agent birleşimi" dedi; doğrusu, kendisinin önceki ve sonraki anlatımındaki gibi IP adresi ve agent birleşimidir.

**Zaman tabanlı çözüm:**

- **Verilen:** Kullanıcının aktivitesi 0:01'de başlıyor. Ardından gelen kayıtlardan biri 0:25'te, bir sonraki kayıt 1:15'te.
- **Birinci oturum:** $0{:}01 + 30\text{ dk} = 0{:}31$ (ara adım eklendi). Bu sınıra kadarki bütün aktiviteler birinci oturumdur.
- **İkinci oturum:** Sınırdan sonraki ilk kayıt 1:15'tir. $1{:}15 + 30\text{ dk} = 1{:}45$ (ara adım eklendi). Bu aralıktaki bütün kayıtlar ikinci oturumdur.
- **Sonuç:** İki oturum.

**Gezinme tabanlı çözüm:** Yönlendireni olmayan birinci kayıttan başlanır. Yönlendireni olmayan bir sonraki kayda kadarki bütün aktiviteler bir oturumdur. Bu kayıttan sonra yönlendireni olmayan bir sonraki kayda kadarki aktiviteler de ayrı bir oturumdur.

<!-- BELİRSİZ: Slayttaki tablonun bütün satırları altyazıda okunmuyor. Yalnız 0:01, 0:25 ve 1:15 zamanları geçiyor. 0:25 öğrencinin sorusundan, diğerleri hocanın anlatımından. Gezinme tabanlı çözümde kayıtlar slaytta gösterilerek söyleniyor, oturum sayısı açıkça belirtilmiyor. -->

**Soru:** 0:25'ten 1:15'e kadar olan süreyi kim tutuyor, nasıl tutuluyor? **Cevap:** Her HTTP isteğinin içinde zaman bilgisi vardır. Slayttaki tablo günlük verisinden çıkarılmıştır: Zaman bilgisi, IP bilgisi, GET ile istenen sayfa ve yönlendiren bilgisi alınıp bu tabloya çevrilmiştir.

## 15. Kullanıcı Belirleme Yöntemleri

Oturum belirlemeden sonra hoca kullanıcı belirlemeye (user identification) geçti ve yöntemleri sıraladı.

**Çerez.** Tarayıcıya engel konmamışsa girilen sayfa için çerez yerel klasöre bırakılır. Çerez varsa her HTTP isteğinde çerez kimliği de bulunur. Bu sayede sayfaya geri gelen kullanıcılar takip edilebilir.

**Kayıt ve giriş (registration, login).** Kullanıcı giriş yaparsa kim olduğu bilinir.

**Kullanıcı ortamında yazılım ajanı.** Kullanıcının ortamında bir yazılım ajanı çalıştırılırsa geri gelen kullanıcı çok iyi tanınır. Bu ajanlar telefonda e-posta adresini, bilgisayarda MAC adresini alarak kullanıcıyı benzersiz biçimde belirleyebilir.

<!-- BELİRSİZ: 01:35:10 ile 01:36:47 arasında altyazıda boşluklar var; yazılım ajanı örneğinin bir kısmı eksik. -->

**Gömülü oturum kimliği.** Kullanıcı ilk başta oturumu oluşturduğunda ona bir oturum kimliği gönderilir. Uygulama bundan sonraki bütün isteklerde bu kimliği gönderir. Böylece oturum içindeki bütün hareketler izlenir.

**IP adresi ve agent.** Önceki bölümde anlatıldığı gibi ikisi birleştirilir.

Her yöntemin bir zayıf yanı vardır:

| Yöntem | Zayıf yanı |
|---|---|
| Çerez | Kullanıcılar çerez özelliğini kapatabilir |
| Kayıt ve giriş | Çok sayıda kişi hesabı olsa da giriş yapmadan gezer, ancak parayı ödemeye karar verince giriş yapar |
| Yazılım ajanı | Kimi kullanıcı her uygulamanın yazılımını telefonuna ya da bilgisayarına yüklemek istemez, tarayıcıdan kullanmak ister |
| Gömülü oturum kimliği | Yalnız aynı oturumu izler, kullanıcı sonraki oturumda geldiğinde kim olduğu bilinmez |
| IP adresi ve agent | Dinamik IP'de benzersiz kimlik oluşturmak çok zordur |

### 15.1 Oyuncak Örnek

Hoca IP adresi ve agent ikilisiyle kullanıcı belirlemeyi slayttaki veri üzerinde gösterdi. Aynı IP ve agent birleşimine sahip kayıtlar tek kullanıcı sayılır:

| IP ve agent birleşimi | Sonuç |
|---|---|
| IP ile Internet Explorer 5, Windows 2000 | user 1 |
| IP ile Internet Explorer 6, Windows XP Service Pack 1 | user 2 |
| Üçüncü birleşim | user 3 |

Her birleşime uyan kayıtlar bir araya getirilince o kullanıcının aktiviteleri çıkar.

> **Ders sonrası not:** Altyazıda "Windows XP Security Package 1" geçiyor; doğrusu büyük olasılıkla Windows XP Service Pack 1'dir.

<!-- BELİRSİZ: Hoca kayıtları slayttan parmakla gösteriyor. IP değeri altyazıda "1234" diye geçiyor. Kayıtların tam dökümü ve user 3'ün agent bilgisi okunmuyor. -->

## 16. Page View Belirleme ve Yol Tamamlama

### 16.1 Page View Belirleme

Bir sayfayı görüntülemek istediğinizde tarayıcıya linkini verirsiniz ya da bir linke tıklarsınız. Tarayıcı bu sayfayı göstermek için arka planda 4-5 farklı nesne için HTTP isteği gönderir. Günlüğe baktığınızda bir sayfa için belki çok sayıda istek görürsünüz. Bu isteklerin hepsinin tek bir page view'a ait olduğunu tespit etmeniz gerekir.

### 16.2 Yol Tamamlama

Yol tamamlama için proxy cache'i hatırlamamız gerekir. Daha önce istenip önbelleğe alınmış sayfaları yeniden isterseniz istek sunucuya ulaşmaz, önbellekten karşılanır. Slayttaki örnek şöyledir:

```
Kullanıcının gerçek yolu : A -> B -> D -> E -> D -> B -> C
Sunucu günlüğünde görünen: A -> B -> D -> E -> C
```

Adım adım incelersek:

1. A isteğinin yönlendireni yoktur. Kullanıcı belli ki adres kutusuna A'nın adresini yazmıştır.
2. A'dan B'ye, B'den D'ye ve D'den E'ye geçişler günlükte görülür.
3. E'den D'ye ve D'den B'ye dönüşler günlükte görülmez. Bu iki kayıt proxy cache tarafından karşılandığı için sunucuya düşmemiştir.
4. B'den C'ye geçiş yeniden görülür.

Demek ki önbellek yüzünden eksik referanslar olabilir. Bu eksik kayıtların doldurulmasına yol tamamlama denir. Yukarıdaki iki dizinin farkı, önbellekteki sayfaların sunucuya ulaşmadığı kabulüyle python ile de doğrulandı.

## 17. Tıklama Verisinden Olaylara

Bir sayfada tıklama verileri ve olaylar vardır. Tıklama verilerine, örneğin e-ticarette, tıklama akışı verisi deriz. Bu verilerin bir araya gelmesiyle olaylar oluşur. Hocanın örnekleri şunlardır:

- **Ürün görüntüleme (product view):** Sayfada bir ürünü görüntülersiniz. Bu bir resim, metin ya da link olabilir.
- **Ayrıntı için ürüne tıklama (click-through):** Ürünle ilgili ayrıntılı bilgi almak için ürüne basarsınız.
- **Alışveriş sepetinde değişiklik:** Ürün ekleme, çıkarma ya da adet değiştirme.
- **Satın alma ve fiyat önerisi:** Bir ürünü almak ya da onun için fiyat önerisi yapmak.

Kullanıcıların sayfada ne yaptığını modelleyebilmek için önce o sayfada ne tür olaylar olduğu incelenir, olaylar kategorize edilir ve her biri tanımlanır. Bir olayın olay sayılması için hangi tıklamaların ya da tıklama zincirlerinin oluşması gerektiğine bakılır. Bir olay tek tıklamadan oluşabileceği gibi birden fazla tıklamanın birleşmesinden de oluşabilir. Olaylar tanımlanabilirse bu olaylarla ilgili örüntüler de tespit edilebilir.

## 18. Sürece Başka Bir Bakış ve E-Ticaret Akışı

### 18.1 Sürece Başka Bir Bakış

Bir sonraki slayt süreci başka bir açıdan gösterir. Ham kullanıcı verisi günlük dosyalarından, uygulama dosyalarından, CRM verisinden ve site yapısından oluşur. Ön işleme ile ön işlenmiş tıklama akışı verisi elde edilir. Bu veri üzerinde makine öğrenmesi algoritmaları çalıştırılır ve istatistiksel modeller ve kurallar oluşur. Örüntü analizinde işe yarayan modeller kullanılır, yaramayanlar ya da modellerin yaramayan parçaları çıkarılır. Sonuçta anlamlı olabilecek kural kümeleri, örüntüler ve istatistiksel bilgiler ortaya çıkar. Web kullanım madenciliği budur.

### 18.2 Otel Örneği

Günlük verilerinin milyonlarca olduğunu düşünün. Böyle bir veriden kullanıcının ne yaptığını anlamak zordur. Slayttaki oyuncak örnekte ayrıntılı bir inceleme yapılmıştır:

1. Kullanıcı belli bir konum için konuma göre arama (search by location) yapar.
2. Sonuçları hem konuma hem fiyata göre sıralar.
3. Karşısına çıkan bir oteli görüntüler.

Burada gerçekleşen olaylar HTTP isteklerinden alınıp anlaşılır bir biçime dönüştürülmüştür. Yapmaya çalıştığımız da budur.

### 18.3 E-Ticarette Veri Analizi Akışı

Bir diğer slayt, e-ticaret dünyasında web kullanım madenciliği açısından bir veri analizi iş akışını gösterir:

```
Site içeriği + sunucu günlükleri + uygulama günlükleri
  -> İçerik analizi modülü
  -> Oturum belirleme ve veri temizleme modülü

Web sunucusu günlükleri + CRM verisi
  + uygulama sunucusu verisi + site yapısı
  -> Veri bütünleştirme modülü
  -> Data mart (kullanıcı işlem veritabanı)
  -> Örüntü analizi ya da OLAP analizi
```

İçerik analizi modülünün çıktıları oturum belirleme ve veri temizleme modülüne verilir. Veri bütünleştirme modülü farklı kaynakları birleştirir, veriyi kullanıcı işlem veritabanına dönüştürür ve üzerinde çalışılması için bir data mart kurar. Bu data mart üzerinde standart makine öğrenmesi algoritmalarıyla örüntü analizi yapılabilir. Aynı şekilde OLAP analiziyle de veri madenciliği analizleri yapılabilir.

> **Ek bilgi (derste anlatılmadı):** Data mart (veri reyonu), belli bir analiz amacı için hazırlanmış, veri ambarından daha dar kapsamlı bir veri deposudur. OLAP (online analytical processing) ise veriyi farklı boyutlara göre özetleyip inceleme yöntemidir.

## 19. Uygulama Türleri ve Kullanılan Yöntemler

Web kullanım verisi üzerinde farklı tipte uygulamalar yapılabilir.

**Sık öğe kümeleri (frequent itemsets).** Birliktelik kuralları çıkarılırken çok sayıda tekrar eden, popüler ürünleri tespit ediyorduk. Slayttaki örnekte bir e-ticaret sayfasında birlikte satılan ürünler belli bir support değerine göre tespit edilmiştir.

**Birliktelik kuralları.** Birliktelikler kurallara dönüştürülebilir. Her kuralın bir güvenilirliği, yani confidence değeri olur. Amaç, "A'yı alan kullanıcı şu olasılıkla B'yi de alır" gibi kurallar çıkarmaktır.

**Sıralı örüntü madenciliği.** Sıralı eylem dizileri tespit edilir. Hocanın örneği: Toplu müşteri verisinden "A oyununu oynayan %50-60 olasılıkla B oyununu da oynar" gibi örüntüler çıkarılır.

**Kümeleme.** Gözetimsiz öğrenme algoritmalarıyla müşteriler davranışlarına göre bölümlenir (segmentation). Aynı şekilde sonuçlarda çıkan sayfalar ya da ürünler kategorize edilir.

**Sınıflandırma.** Bir model eğitilir ve bu modelle bir ürünün hangi grubun parçası olduğu tahmin edilir.

Slayttaki uygulama ve yöntem eşleşmeleri şöyledir:

| Uygulama | Yöntem |
|---|---|
| Kart dolandırıcılığı tespiti (card fraud detection) | Sınıflandırma |
| Ziyaretçileri nitelendirme (characterization of visitors) | Sınıflandırma |
| Ortak davranışlı ziyaretçi gruplarını bulma | Kümeleme |
| Ortak özellik ve ilgili ziyaretçi gruplarını bulma | Kümeleme |
| İlişkili olayları ya da uygulama nesnelerini bulma | Birliktelik kuralı madenciliği |
| Sonraki olayı tahmin (prediction of next event) | Sıralı örüntü madenciliği |

> **Hocanın vurgusu:** Özellikle oturum belirleme ve kullanıcı belirlemeyi iyi öğrenin, bunlar karşınıza çıkabilir. Farklı tekniklerin web kullanım madenciliğinde hangi amaçla kullanıldığını da biliyor olmanız gerekir.

## Dersin Toparlaması

Bu derste önce link analizinin son algoritması olan HITS görüldü. PageRank skorları sorgudan bağımsız, önceden hesaplanırken HITS sorgu anında root set'ten base set'i kurar, bu küçük graf üzerinde her sayfa için otorite ve hub skoru hesaplar. Karşılıklı pekiştirme varsayımı $a = L^{T}h$ ve $h = La$ denklemlerine dönüşür, yerine koyma ile power iteration'a uygun biçim elde edilir. Buradaki $L^{T}L$ ve $LL^{T}$ matrisleri co-citation ve bibliographic coupling matrisleridir. HITS sorguya bağlı olmanın avantajına karşılık spam'e açıklık, sorgu anında performans kaybı ve konu kayması gibi zayıflıklar taşır.

İkinci bölümde web kullanım madenciliğine geçildi. Tıklama akışı verisi günlüklerden, CRM veri tabanlarından ve site içeriğinden gelir, eksik ve dağınıktır. Veri temizleme, page view, oturum ve kullanıcı belirleme, yol tamamlama, bölüm belirleme ve bütünleştirme adımlarıyla kullanıcı işlem veritabanı kurulur. Oturumlar zaman ya da gezinme tabanlı sezgilerle, kullanıcılar çerez, giriş, yazılım ajanı, gömülü oturum kimliği ya da IP ve agent ile belirlenir. Bu veritabanı üzerinde birliktelik kuralları, sıralı örüntüler, kümeleme ve sınıflandırma çalıştırılır, örüntü analiziyle sonuçlar kullanıcı davranışını tanımlamakta kullanılır hale getirilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
