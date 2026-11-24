# Ders 9 Genişletilmiş Notu: Öneri Sistemleri: İçerik Tabanlı ve İşbirlikçi Filtreleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Öneri Sistemlerine Neden İhtiyaç Var?
- 2. Uzun Kuyruk Olgusu
- 3. Öneri Türleri
- 4. Biçimsel Model ve Fayda Matrisi
- 5. Öneri Sistemlerinin Üç Temel Problemi
- 6. İçerik Tabanlı Öneri Sistemleri
- 7. İşbirlikçi Filtreleme: Kullanıcı-Kullanıcı
- 8. Öğe-Öğe İşbirlikçi Filtreleme
- Örnek Sorular
- Dersin Toparlaması

Dersin konusu, kaynak kitabın (Mining of Massive Datasets, Leskovec, Rajaraman ve Ullman) 9. bölümü olan öneri sistemleridir (recommender systems), özellikle büyük veri üzerinde çalışan öneri sistemleri (ekrandan, 00:15:00). Ders slaytları kitabın bölüm slaytlarıdır.

## 1. Öneri Sistemlerine Neden İhtiyaç Var?

Web'de çok sayıda ürün (item) vardır: ürünler, filmler, müzikler, haberler; YouTube'daki videolar, Spotify'daki müzik dosyaları gibi. Slaytta Amazon, Pandora, StumbleUpon, del.icio.us, Netflix, MovieLens, last.fm, Google News, YouTube ve Xbox Live öneri yapan sistemlere örnek olarak gösterilir (ekrandan, 00:20:00).

Bu kadar çok ürün varken kullanıcı en çok ilgilendiği ürünü bulmak ister. Bunun bir yolu aramadır (search). Ancak arama arayüzleri sınırlıdır ve sonuçlar geldikten sonra bile kullanıcının en uygun ürünü bulmak için sonuçlar arasında çok gezinmesi gerekir. Bu yüzden kullanıcıya ilgileneceği ürünleri doğrudan önerebilen sistemler (recommendations) istenir. Slayttaki şemada kullanıcı ile ürün deposu arasında iki ok vardır: kullanıcıdan ürünlere giden "Search" ve ürünlerden kullanıcıya gelen "Recommendations".

### 1.1 Kıtlıktan bolluğa

Fiziksel mağazalarda (perakende) sunulabilen ürün sayısı sınırlıdır. Bir süpermarkette yer kısıtı nedeniyle ürün sayısı sınırlıdır. Bir şehirdeki sinema salonu ve seans sayısı sınırlıdır. Bir TV kanalının günde 24 saatlik yayın süresi olduğu için yayımlanabilecek program sayısı da sınırlıdır. Ürün sayısı az olunca aranan ürünü bulmak görece kolaydır.

Web'de ise Netflix gibi yayın siteleri, e-ticaret kitap siteleri ya da Spotify gibi müzik siteleri neredeyse sınırsız sayıda ürün sunar. Fiziksel dünyadaki duruma **kıtlık** (scarcity), web'deki duruma **bolluk** (abundance) denir. Bollukta doğru ürünü bulmak çok zorlaşır.

## 2. Uzun Kuyruk Olgusu

Bu durum **uzun kuyruk** (long tail) olgusu ile açıklanır (ekrandan, 00:25:00). Grafikte:

- X ekseninde ürünler popülerliklerine göre sıralanmıştır: çok popüler ürünler solda, az popüler ürünler sağdadır.
- Y ekseninde haftalık satın alma sayısı (number of purchases / week) vardır. Filmler için bu haftalık izlenme sayısı da olabilir.
- Eğri solda çok yüksekten başlar, hızla düşer ve sağa doğru uzun, alçak bir kuyruk halinde sürer.
- Dikey bir çizginin solundaki bölge "Retail and Online" diye etiketlenmiştir: bu popüler ürünler hem fiziksel mağazada hem çevrim içi bulunur. Sağındaki bölge "Items available only online" diye etiketlenmiştir.
- Slaytın başlığı "The economics of abundance" (bolluğun ekonomisi) der; ürünler kitap, müzik, video ya da haber makalesi olabilir.

Fiziksel bir mağaza, yer kısıtı nedeniyle yalnız satılma olasılığı yüksek ürünleri rafına koyar; satılma olasılığı düşük ürünlere yer ayırmaz. Web'de ise satılma olasılığı düşük çok sayıda ürün de sunulur. Kuyruğun altında kalan toplam alan, popüler ürünlere ayrılan alandan büyüktür. Yani web'de, fiziksel mağazalara, TV kanallarına ve sinema salonlarına göre çok daha fazla ürün vardır ve bu az popüler ürünleri onlarla ilgilenebilecek kullanıcılara önerecek sistemlere ihtiyaç vardır.

### 2.1 Örnek: dağcılık kitapları

Hoca, öneri motorlarının uzun kuyruk için neden önemli olduğunu iki dağcılık kitabıyla anlattı. Konusu dağcılık olan iki kitaptan ikincisi önce yayımlanmış, ama yayımlandığında pek ilgi görmemiş ve çok satanlara girmemiştir. Sonra yayımlanan birinci kitap çok ilgi görmüş ve çok satan olmuştur. Bundan sonra Amazon'un öneri motoru eski kitabı, yeni kitabı alan kullanıcılara önermiştir. Yeni kitabı alanlar eski kitabı da almaya başlamış; eski kitap da çok satanlara girmiş, hatta yenisinden daha fazla satmıştır.

<!-- BELİRSİZ: Altyazıda kitap adı "Touching the World" diye geçiyor; kitap büyük olasılıkla "Touching the Void"dir. Diğer kitabın adı altyazıda geçmiyor ve bu anın karesi yok. -->

Bu örneğin dersi şudur: öneri motorları, başta az popüler olan ürünleri insanlara aldırabilir ve bu ürünler zamanla çok popüler hale gelebilir.

Önerilen şeyler kitap, film, müzik ya da haber makalesi olabilir. Öneri motorları yalnız ürün değil, kişi de önerir: Facebook, LinkedIn ve Twitter gibi sosyal ağların öneri motorları kullanıcıya sürekli yeni kişiler önerir.

## 3. Öneri Türleri

Bir web sitesinde yapılabilecek öneriler üç türlüdür.

**Editoryal ya da elle hazırlanmış öneriler.** Öneriyi sitenin sahibi ya da editörü yapar. Hocanın benzetmesi: bir kahve dükkânına gidildiğinde "günün en sevilen içeceği" yazan bir pano görülür. Bu tür öneri kullanıcı davranışına bakmaz.

**Basit toplamlara (simple aggregates) dayalı öneriler.** Sitede neyin popüler olduğunu anlamak için istatistiksel ölçüler kullanılır: "en çok görüntülenen ilk 10 kitap", "en çok satılan kitaplar", "son zamanlarda en çok izlenen filmler" gibi. Bu öneriler kullanıcıların toplu (collective) davranışına dayanır, tek bir kullanıcının davranışına bakmaz. Birinci tür editörün kararına, ikinci tür kalabalığın etkinliğine dayanır.

**Bireysel kullanıcıya göre öneriler.** Dersin ilgilendiği tür budur. Örneğin bir kullanıcı Netflix'e abone olduğundan beri aksiyon filmleri izliyorsa, Netflix ona daha çok aksiyon filmi önerebileceğini bilir. Site, kullanıcının etkileşimlerinden ve davranışından yola çıkarak öneri yapar. Bu yüzden ilgi alanı, müşteri davranışını inceleyip çözümleyen öneri motorlarıdır.

## 4. Biçimsel Model ve Fayda Matrisi

### 4.1 Biçimsel model

Slayttaki model şöyledir (ekrandan, 00:35:00):

- $C$: müşteriler (customers) kümesi.
- $S$: ürünler (items) kümesi.
- Fayda fonksiyonu (utility function): $u: C \times S \to R$.
  - $R$: puanlar (ratings) kümesi.
  - $R$ tam sıralı (totally ordered) bir kümedir.
  - Örnek: 0-5 yıldız, $[0,1]$ aralığında gerçel sayı.

Fonksiyon, müşterileri ve ürünleri girdi olarak alır ve bütün olası müşteri-ürün ikililerini oluşturur; ikilinin birinci elemanı müşteri, ikincisi üründür. Her ikili için bir puan bulunur. Puanlar bulunduktan sonra büyükten küçüğe sıralanır ve bir müşteriye en yüksek puanı alması beklenen ürün önerilir. Hoca puanların 0 ile 5 arası yıldız, 0 ile 1 arası gerçel sayı ya da ikili (0 veya 1) olabileceğini söyledi.

### 4.2 Fayda matrisi

Fayda matrisinde (utility matrix) satırlar kişileri, sütunlar ürünleri gösterir. Slayttaki örnekte satırlarda kullanıcılar (Alice gibi), sütunlarda filmler (Lord of the Rings, Pirates gibi) vardır.

<!-- BELİRSİZ: Fayda matrisi örneğinin anlatıldığı anın (yaklaşık 00:36:50) karesi yok; matrisin değerleri altyazıda okunmadığı için nota alınmadı. -->

Matrisin bazı hücrelerinde değer vardır, çoğu ise boştur. Bunun nedeni, insanların çoğunun bir ürünü kullandığında (film izlediğinde ya da ürün satın aldığında) geri bildirim vermemesidir. Bu yüzden gerçek hayatta karşılaşılan fayda matrisi **seyrektir** (sparse): çok sayıda boş (sıfır) hücre ve az sayıda dolu hücre vardır.

Fayda fonksiyonuyla bulunmak istenen değerler boş hücrelerdir. Bir boş hücrenin değeri yüksek çıkarsa o ürün o kullanıcıya önerilir. Hocanın örneği: Alice'in henüz izlemediği Lord of the Rings ve Pirates filmlerinden hangisine daha yüksek puan vereceği bulunursa, Alice'e o film önerilir.

> **Hocanın vurgusu:** Bundan sonra öğrenilecek algoritmaların tamamının hedefi, fayda matrisindeki boş hücrelerin değerlerini bulmaktır. Bu da matrisin dolu hücrelerinden yararlanılarak yapılır.

## 5. Öneri Sistemlerinin Üç Temel Problemi

Slayttaki üç temel problem şunlardır (ekrandan, 00:40:00):

- (1) Matris için "bilinen" puanları toplamak: fayda matrisindeki veri nasıl toplanır?
- (2) Bilinmeyen puanları bilinenlerden tahmin etmek (extrapolate): asıl ilgi yüksek bilinmeyen puanlardadır. Kullanıcının neyi sevmediğini bilmekle değil, neyi sevdiğini bilmekle ilgilenilir.
- (3) Tahmin yöntemlerini değerlendirmek: öneri yöntemlerinin başarısı ya da performansı nasıl ölçülür?

Üçüncü problemde, bilinmeyen puanlar bulunduktan sonra öneri motorunun iyi çalışıp çalışmadığını ölçecek bir değerlendirme yöntemi gerekir. Kayıttaki slayt sekmelerinden biri bu konuya ayrılmıştır ("Evaluating recommender systems", ekrandan, 00:15:00), ama derste bu konu anlatılmadı.

### 5.1 Puanları toplamak

Slayttaki iki yol şunlardır (ekrandan, 00:45:00):

- **Açık (explicit):** kullanıcılardan ürünleri puanlamaları istenir. Ölçeklenmez: kullanıcıların yalnız küçük bir kısmı puan ve yorum bırakır.
- **Örtük (implicit):** puanlar kullanıcı eylemlerinden öğrenilir. Örneğin satın alma yüksek puan anlamına gelir. Düşük puanlar ne olacak?

Açık toplamaya örnek: Netflix'te film bitince beş yıldızlı bir puanlama anketi çıkar ve kullanıcıdan puan girmesi istenir. Kullanıcı puan girerse puan açıkça toplanmış olur. Ancak çoğu insan puan vermez; öneri motoru yalnız açık puanlara dayanırsa ölçeklenmez.

Örtük toplamada puan kullanıcıya sorulmadan eylemlerinden çıkarılır: kullanıcının bir ürüne uzun zaman ayırması ya da onu satın alması gibi. Bir kişi para ödeyip ürünü satın aldıysa o ürüne yüksek puan vereceği düşünülür. Sorun şudur: satın alma yüksek puanın iyi bir göstergesidir, ama kullanıcının bir ürüne düşük puan vereceğini eylemlerinden anlamak zordur.

<!-- BELİRSİZ: 00:43:12-00:43:30 arasında altyazı bozuk; örtük geri bildirim örneğinin (kullanıcının bir ürüne zaman ayırması) ayrıntısı okunamıyor. -->

Özetle: açık geri bildirim kullanıcı görüşünü kesin olarak verir ama ölçeklenmez. Örtük geri bildirim ölçeklenir ama düşük puanları gösteremez.

### 5.2 Bilinmeyen puanları tahmin etmenin zorlukları

**Seyreklik.** Çoğu insan çoğu ürünü puanlamamıştır. Matrisin büyük kısmı bilinmeyen değerlerden, küçük bir kısmı sıfırdan farklı değerlerden oluşur. Böyle bir matriste bilinmeyenleri bulmak zordur.

**Soğuk başlangıç (cold start).** Hiç geçmişi olmayan yeni bir kullanıcıya ne önerilecektir? Kullanıcı ile sistem arasında hiç etkileşim verisi yoktur. Aynı şekilde Netflix'e yeni bir film gelmişse ve kimse onu izlememişse, hiç puanı yoktur; bu film müşterilere nasıl önerilecektir? Öneri yapmak için kullanılacak yeterli geçmiş veri yoktur.

### 5.3 Üç yaklaşım

Bu iki zorluğa rağmen, bilinen değerlerden bilinmeyenleri bulmak için üç tür öneri sistemi vardır:

- İçerik tabanlı (content-based) sistemler: derste işlendi.
- İşbirlikçi filtreleme (collaborative filtering) sistemleri: derste işlendi.
- Gizil faktör (latent factor) tabanlı sistemler: dersin kapsamı dışında bırakıldı.

## 6. İçerik Tabanlı Öneri Sistemleri

### 6.1 Temel fikir

İçerik tabanlı sistemde $x$ müşterisine, aynı müşterinin daha önce yüksek puan verdiği ürünlere benzeyen ürünler önerilir. Film, web sitesi, kişi vb. önerilebilir; ama öneri yalnız bu kullanıcının daha önce puanladığı ürünlere dayanır.

Slayttaki işleyiş ("Plan of Action", ekrandan, 00:50:00):

```text
Kullanıcı --(beğenir: likes)--> ürünler: kırmızı daire, kırmızı üçgen
   |                                   |
   |                          (kurar: build) ürün profilleri
   |                                   v
   |                      kullanıcı profili: "Red, Circles, Triangles"
   |                                   |
   |                    (eşleştirir: match) katalogdaki ürünlerle
   |                                   v
   +<--(önerir: recommend)-- aday ürünler: kırmızı altıgen,
                             yeşil daire, mavi kare, yeşil kare
```

Kullanıcı sisteme bazı ürünleri beğendiğini söylemiştir: bir kırmızı daire ve bir kırmızı üçgen. Her ürün için bir **ürün profili** (item profile) oluşturulur. Ürün profili bir özellik vektörü (feature vector) olarak düşünülebilir: ürünün sahip olduğu bütün özelliklerden oluşur; örneğin bu ürün dairedir ve rengi kırmızıdır.

Kullanıcının beğendiği ürünlerin özellik vektörleri birleştirilerek tek bir vektör elde edilir. Buna **kullanıcı profili** (user profile) denir ve kullanıcının kendisini temsil eder. İçerik tabanlı filtreleme algoritması kullanıcı profilini katalogdaki diğer ürün profilleriyle karşılaştırır. Kullanıcı profili ile bir ürün profili arasında eşleşme varsa o ürün kullanıcıya önerilir.

### 6.2 Ürün profilleri

Ürün profili özelliklerden oluşur:

- Ürün film ise: yazar, başlık, oyuncu, yönetmen, tür.
- Ürün görüntü ya da video ise: onları tanımlamak için kullanılan metaveri ve etiketler.
- Ürün kişi ise: kişinin arkadaşlarının kümesi.
- Ürün web sitesi, blog ya da haber ise: içindeki kelimeler ve makaleler.

Ürün profili vektörünün değerleri Boolean ya da gerçel olabilir. Boolean örneği: bir kitapta geçebilecek bütün olası kelimelerden bir vektör uzayı kurulur; vektörün boyutu bütün olası kelimelerin sayısıdır. Kelime kitapta geçiyorsa değeri 1, geçmiyorsa 0'dır. Böylece bir kitabın ürün profili 0 ve 1'lerden oluşan bir vektör olur. Değerler gerçel sayılar da olabilir.

### 6.3 Metin özellikleri ve TF-IDF

Slayttaki ilkeler şunlardır (ekrandan, 00:55:00):

- Profil, üründeki (belgedeki) "önemli" kelimelerin kümesidir.
- Önemli kelimeler nasıl seçilir? Metin madenciliğinde alışılmış sezgisel yöntem TF-IDF'tir (Term Frequency × Inverse Document Frequency).

Bir metinde çok sayıda kelime vardır; "and", "or" ya da "the" gibi yaygın kelimeler belgeyi temsil etmek için kullanılmak istenmez. Belgeyi temsil edecek önemli kelimeleri seçmek için TF-IDF ölçüsü kullanılır. TF terim frekansı (term frequency), IDF ters belge frekansıdır (inverse document frequency).

Slayttaki tanımlar (ekrandan, 01:00:00):

- $f_{ij}$: $i$ teriminin (özelliğinin) $j$ belgesindeki (ürünündeki) frekansı.
- Terim frekansı:

$$TF_{ij} = \frac{f_{ij}}{\max_k f_{kj}}$$

- Slayttaki not: TF, "uzun" belgelerin etkisini azaltmak için normalleştirilir.
- $n_i$: $i$ terimini içeren belge sayısı; $N$: toplam belge sayısı.
- Ters belge frekansı:

$$IDF_i = \log \frac{N}{n_i}$$

- TF-IDF puanı:

$$w_{ij} = TF_{ij} \times IDF_i$$

- Belge profili: TF-IDF puanı en yüksek kelimelerin kümesi, puanlarıyla birlikte.

> **Ders sonrası not:** Hoca TF'nin paydasını, kelimenin belge koleksiyonundaki herhangi bir belgede geçtiği en büyük sayı diye anlattı. Ekrandaki formülde payda $\max_k f_{kj}$'dir: $k$ bütün terimler üzerinde dolaşır, $j$ sabittir. Yani payda, aynı $j$ belgesinde en sık geçen terimin frekansıdır (ekrandan, 01:00:00).

IDF'nin payında koleksiyondaki toplam belge sayısı $N$, paydasında $i$ kelimesini içeren belge sayısı $n_i$ vardır. $n_i$ büyükse kelime koleksiyondaki hemen her belgede geçiyor demektir; böyle bir kelimenin koleksiyon için önemi küçüktür, yani IDF küçük çıkar. Kelime az sayıda belgede geçiyorsa payda küçük, logaritma büyük, IDF büyük olur.

Hoca bunu Türkçe olarak şöyle özetledi: TF, bir kelimenin o belge için ne kadar önemli olduğunu gösteren ölçüdür; IDF ise o kelimenin belgenin bulunduğu belge koleksiyonu içindeki önemini gösteren ölçüdür. Biri belge için, biri koleksiyon içindir. Bir kelime bir belgede çok kez geçiyor ve koleksiyonda az sayıda belgede bulunuyorsa, o kelimenin o belge için TF-IDF puanı büyük olur.

Bu hesabın amacı şudur: verilen bir metni temsil edecek ürün profili, metindeki bütün kelimeler kullanılarak kurulmaz. Kelimelerin TF-IDF puanları hesaplanır ve puanı belli bir değerin üzerinde olan kelimeler ürün profilinde kullanılır.

> **Ek bilgi (derste anlatılmadı):** Logaritmanın tabanı slaytta belirtilmemiştir; taban değişince bütün IDF değerleri aynı sabitle çarpılır, bu yüzden kelimelerin sıralaması değişmez. Bu nedenle uygulamada 2, $e$ ya da 10 tabanı kullanılabilir.

### 6.4 Kullanıcı profilini kurmak

Kullanıcı, profilleri $i_1, \ldots, i_n$ olan ürünleri puanlamıştır. Bu ürün profillerinden bir kullanıcı profili hesaplanmalıdır. Seçenekler:

- Ürün profillerinin ortalaması alınabilir.
- Ürün profillerinin ağırlıklı ortalaması alınabilir.
- Ağırlıklar, kullanıcının ortalama puanı kullanılarak normalleştirilebilir.
- Başka yaklaşımlar da vardır.

Hoca bu noktada iki örnekle devam etti.

#### Örnek 1: Boolean fayda matrisi

Slayttaki örnek (ekrandan, 01:15:00):

- Ürünler filmlerdir; tek özellik "Oyuncu"dur.
  - Ürün profili: her oyuncu için 0 ya da 1 içeren bir vektör.
- $x$ kullanıcısı 5 film izlemiştir.
  - 2 filmde A oyuncusu oynar.
  - 3 filmde B oyuncusu oynar.
- Kullanıcı profili = ürün profillerinin ortalaması.
  - A özelliğinin ağırlığı $= 2/5 = 0.4$.
  - B özelliğinin ağırlığı $= 3/5 = 0.6$.

Boolean fayda matrisinde satırlar kullanıcılar, sütunlar filmlerdir; kullanıcı filmi izlediyse 1, izlemediyse 0 vardır. $x$ kullanıcısının satırında 5 film vardır. Her filmin ürün profili; özellik A, özellik B, özellik C, özellik D gibi her oyuncu için bir özellik içerir ve film o oyuncuyu içeriyorsa 1, içermiyorsa 0 yazılır. Beş ürün profilinin ortalaması alınınca kullanıcı profili elde edilir. Beş filmin ikisinde A oynadığı için kullanıcı profilinde A'ya karşılık gelen değer $2/5 = 0.4$, üçünde B oynadığı için B'ye karşılık gelen değer $3/5 = 0.6$ olur. Diğer özellikler için de aynı yol izlenir.

Kullanıcı profili de ürün profilleriyle aynı yapıdadır (özellik A, özellik B, ...). Bu yüzden kullanıcı profili ürün profilleriyle karşılaştırılabilir ve yakın olanlar kullanıcıya önerilir.

#### Örnek 2: yıldız puanları

Slayttaki örnek (ekrandan, 01:20:00):

- Aynı örnek, 1-5 yıldız puanlarıyla.
  - A oyuncusunun filmlerine 3 ve 5 verilmiş.
  - B oyuncusunun filmlerine 1, 2 ve 4 verilmiş.
- Yararlı adım: puanları, kullanıcının ortalama puanını (3) çıkararak normalleştir.
  - A'nın normalleştirilmiş puanları $= 0, +2$; profil ağırlığı $= (0+2)/2 = 1$.
  - B'nin normalleştirilmiş puanları $= -2, -1, +1$; profil ağırlığı $= -2/3$.

Adım adım:

- Verilen: beş filme verilen puanlar 3, 5 (A'nın filmleri) ve 1, 2, 4 (B'nin filmleri).
- Puanların toplamı $3+5+1+2+4 = 15$, film sayısı 5, ortalama $15/5 = 3$.
- Her puandan ortalama çıkarılır: $3-3 = 0$, $5-3 = 2$, $1-3 = -2$, $2-3 = -1$, $4-3 = +1$.
- A özelliğinin ağırlığı: A'yı içeren filmlerin normalleştirilmiş puanlarının toplamı, A'yı içeren film sayısına bölünür: $(0+2)/2 = 1$.
- B özelliğinin ağırlığı: $(-2-1+1)/3 = -2/3$.

Ortalamanın çıkarılmasının amacı şudur: kullanıcı "kolay puanlayıcı" (easy rater) ise, yani hep cömert puan veriyorsa bütün değerleri yüksek çıkar; hep düşük puan veriyorsa bütün değerleri düşük çıkar. İstenen, kullanıcının kendi ortalamasına göre hangi filme daha iyi, hangisine daha kötü puan verdiğini görmektir. Bu örnekte 1 ve 2 verilen filmler ortalamanın altındadır, yani kullanıcı onları pek sevmemiştir; 5 ve 4 verilenler ortalamanın üstündedir, daha çok sevilmiştir; 3 ise orta derecededir.

Birinci yöntem, fayda matrisinde yalnız 0-1 değerleri (yıldız puanı yok) olduğunda kullanılır. İkinci yöntem, kullanıcının izlediği filmlere 1 ile 5 arası yıldız verdiği durumda kullanıcı profilinin nasıl hesaplanacağını gösterir.

### 6.5 Tahmin: kosinüs benzerliği

Kullanıcı profili kurulduktan sonra katalogdaki ürün profilleriyle karşılaştırılır ve kullanıcı profiline en yakın ürünler sıralanarak kullanıcıya önerilir. Yöntemlerden biri **kosinüs benzerliğidir** (cosine similarity). $x$ kullanıcı profilini, $i$ katalogdaki bir filmin ürün profilini gösteriyorsa, ikisinin ne kadar yakın olduğuna kosinüs benzerliğiyle bakılır. İki vektörün iç çarpımı, iki vektörün uzunluklarının çarpımına bölünür:

$$\cos(x, i) = \frac{x \cdot i}{\lVert x \rVert \, \lVert i \rVert}$$

<!-- BELİRSİZ: Kosinüs benzerliği slaytının (yaklaşık 01:21) karesi yok; formül altyazıdaki sözlü tanımdan yazıldı. -->

### 6.6 İçerik tabanlı yaklaşımın artıları

Hoca artıları sözlü olarak anlattı:

- **Başka kullanıcıların verisine gerek yoktur.** Yalnız kullanıcının kendi geçmişine bakılarak öneri yapılır.
- **Kendine özgü zevki olan kullanıcıya öneri yapabilir.** Bir kullanıcının müzik zevki ya da film izleme alışkanlığı diğerlerinden tamamen farklı olabilir. Yöntem, kullanıcının daha önce izlediği ya da satın aldığı ürünlerden yola çıktığı için bu kullanıcıya bile doğrudan kendi beğenisine yönelik öneri yapabilir.
- **Yeni ürünleri önerebilir.** Netflix'e yeni bir film geldiğinde kimse izlememiş ve puan vermemiş olsa da bu film kullanıcılara önerilebilir. Kullanıcı profilleri zaten çıkarılmıştır; yeni filmin ürün profili de (örneğin oyuncularına göre) kolayca çıkarılır. İkisi karşılaştırılır ve yakınsa film önerilir.
- **Açıklanabilirlik.** "Bu öneri neden yapıldı?" sorusuna bir açıklama verilebilir. Kullanıcının izlediği filmler hep aksiyon filmiyse, ona aksiyon filmi önermek beklenmedik bir şey değildir; öneri kullanıcının önceki beğeni alışkanlıklarına benzer.

### 6.7 İçerik tabanlı yaklaşımın eksileri

Slayttaki eksiler (ekrandan, 01:25:00):

- Uygun özellikleri bulmak zordur.
  - Örnek: görüntüler, filmler, müzik.
- Aşırı uzmanlaşma (overspecialization).
  - Kullanıcının içerik profili dışındaki ürünleri asla önermez.
  - İnsanların birden çok ilgi alanı olabilir.
  - Başka kullanıcıların kalite yargılarından yararlanamaz.
- Yeni kullanıcılar için soğuk başlangıç problemi.
  - Kullanıcı profili nasıl kurulacak?

Hocanın açıklamaları: Film için ürün profilini oyuncularla ifade etmek bir yaklaşımdır; ama ürün bir görüntü ya da müzik dosyası olunca onu en iyi temsil eden özelliklerden oluşan bir ürün profili vektörü kurmak zordur. Kitap, metin ya da haber makalesi gibi bazı ürünler TF-IDF puanı en yüksek kelimelerle kolayca temsil edilir, ama bazı çoklu ortam dosyaları için bu zordur.

İnsanların farklı zevkleri olabilir. Biri sürekli aksiyon filmi izliyor diye hiç klasik film izlemeyecek değildir. Yalnız geçmiş beğenilere dayanarak öneri yapılırsa, kişinin hiç görmediği ama ilgilenebileceği şeyler önerilemez: ona hep aksiyon filmi, polisiye ya da bilim kurgu okuyana hep o tarzda kitap önerilir. Oysa farklı bir şey önerilse kişi onunla da ilgilenebilir. Yöntem, kişilerin geçmiş beğenilerine aşırı odaklandığı için bu bir dezavantajdır.

Sisteme hiç geçmiş bilgisi olmayan yeni bir kullanıcı geldiğinde kullanıcı profili oluşturulamaz. Kullanıcı profili olmadan ürün profilleriyle karşılaştırma yapılamaz ve öneri verilemez.

## 7. İşbirlikçi Filtreleme: Kullanıcı-Kullanıcı

### 7.1 Temel fikir

İşbirlikçi filtrelemede (collaborative filtering) bir kullanıcıya öneri yapılırken, bu kullanıcının beğenilerine benzer beğeniler göstermiş diğer kullanıcıların beğenileri kullanılır. $x$ kullanıcısı (yine Netflix örneğiyle) bazı filmleri beğenmiştir. Bu filmlere benzer filmleri izlemiş başka kullanıcılar bulunur. Bu kullanıcıların, ortak filmler dışında izledikleri filmler varsa bunlar $x$'e önerilir. Kullanıcıya söylenen şudur: "Seninle aynı filmleri izlemiş 10 kullanıcı var; bu kullanıcılar senden farklı olarak şu filmi de izlemiş, istersen ona bir bak."

İçerik tabanlı filtrelemede kullanıcının kendi önceki alışkanlıklarına bakılarak öneri yapılır. İşbirlikçi filtrelemede ise başka kullanıcıların davranışlarından yola çıkılarak öneri yapılır.

### 7.2 Örnek fayda matrisi

Slayttaki fayda matrisi şudur (ekrandan, 01:30:00). Satırlar kullanıcılar, sütunlar filmlerdir: Harry Potter 1, 2, 3 (HP1, HP2, HP3), Twilight (TW), Star Wars 1, 2, 3 (SW1, SW2, SW3). Kullanıcılar izledikleri filmlere 1 ile 5 arası yıldız vermiştir; boş hücreler bilinmeyen puanlardır.

| | HP1 | HP2 | HP3 | TW | SW1 | SW2 | SW3 |
|---|---|---|---|---|---|---|---|
| A | 4 | | | 5 | 1 | | |
| B | 5 | 5 | 4 | | | | |
| C | | | | 2 | 4 | 5 | |
| D | | 3 | | | | | 3 |

Slayttaki ilkeler:

- $x$ ve $y$ kullanıcılarının puan vektörleri $r_x$ ve $r_y$ olsun.
- Bir benzerlik ölçüsü $\text{sim}(x, y)$ gerekir.
- Ölçü, $\text{sim}(A,B) > \text{sim}(A,C)$ sezgisini yakalamalıdır.

Hedef yine bilinmeyen değerleri bulmak ve kullanıcılara büyükten küçüğe sıralanmış önerileri yapmaktır. Örneğin A'nın bilinmeyen değerlerini bulmak için önce A'nın puan vektörüne en yakın diğer puan vektörleri bulunmalı, sonra bu vektörlerden A'nın bilinmeyen değerleri tahmin edilmelidir. Bunun için iki kullanıcının puan vektörü arasındaki benzerliği veren bir ölçü gerekir.

Sezgi şudur: A, HP1 ve Twilight'ı sevmiş, SW1'i sevmemiştir. B de HP1'i sevmiştir; Twilight ve SW1 hakkında bilgisi yoktur. Bu yüzden A ile B'nin benzerliği büyük çıkmalıdır. A ile C iki ortak film (TW ve SW1) izlemiştir ve birbirinin tam zıttı puanlar vermiştir: birinin sevdiğini öbürü sevmemiş, birinin beğenmediğini öbürü beğenmiştir. Bu yüzden A ile C'nin benzerliği düşük, hatta A-B benzerliğinden çok daha düşük olmalıdır. Kullanılacak benzerlik ölçüsü bu gözleme dayalı tespiti desteklemelidir.

### 7.3 Seçenek 1: Jaccard benzerliği

Jaccard benzerliği daha önceki derste öğrenilmişti. İki küme varsa, kesişimlerinin eleman sayısı birleşimlerinin eleman sayısına bölünür (ekrandan, 01:35:00):

$$\text{sim}(A,B) = \frac{|r_A \cap r_B|}{|r_A \cup r_B|}$$

- A ile B'nin ortak izlediği film sayısı 1'dir (HP1). İkisinin birlikte izlediği farklı film sayısı 5'tir (HP1, HP2, HP3, TW, SW1). $\text{sim}(A,B) = 1/5 = 0.2$.
- A ile C'nin ortak izlediği film sayısı 2'dir (TW, SW1). Toplam farklı film sayısı 4'tür (HP1, TW, SW1, SW2). $\text{sim}(A,C) = 2/4 = 0.5$.
- Sonuç: $\text{sim}(A,B) < \text{sim}(A,C)$.

A ile C daha benzer çıkmıştır; bu istenmeyen bir sonuçtur. Sorun (slayttaki ifadeyle "Problem: Ignores rating values!"): Jaccard yalnız ortak puanlanan ürünlere bakar, kişilerin hangi puanı verdiğine bakmaz. Bu yüzden bu ölçü kullanılamaz.

### 7.4 Seçenek 2: kosinüs benzerliği

Kosinüs benzerliği vektör ister; bu yüzden boş hücrelere bir değer yazılmalıdır. Boş değerlere 0 yazılır; böylece A ve B'nin değerleri dolu vektörleri elde edilir ve kosinüs benzerliği fonksiyonuna verilebilir.

- $\text{sim}(A,B) \approx 0.38$
- $\text{sim}(A,C) \approx 0.32$

<!-- BELİRSİZ: Bu slaytın karesi yok; 0.38 ve 0.32 değerleri altyazıdan alındı ve python ile doğrulandı (0.380 ve 0.322). -->

$\text{sim}(A,B) > \text{sim}(A,C)$ çıkmıştır; bu istenen sıradır. Ancak aradaki fark yalnız yaklaşık 0.06'dır. Oysa A ile C birbirinin tam zıttı, A ile B ise birbirine çok yakındır. Kosinüs benzerliği sırayı yakalamış, ama aradaki uzaklığın çok daha büyük olması gerektiğini yakalayamamıştır.

Sorunun nedeni şudur: boş hücrelere 0 yazmak, 0-5 ya da 1-5 arası yıldız sisteminde verilebilecek en düşük puanı yazmak demektir. Yani kullanıcılar bu filmleri izlemediği halde onlara olumsuz puan vermiş gibi davranılır. Oysa böyle bir yargıda bulunulmamalıdır: izlenmemiş filme olumsuz mu olumlu mu puan verileceği bilinmez. Bunun yerine "izlenmemiş filmlere ortalama bir değer verilecektir" varsayımı yapılabilir.

### 7.5 Seçenek 3: merkezlenmiş kosinüs (Pearson korelasyonu)

Bu varsayımı gerçeklemek için her kullanıcının verdiği puanların ortalaması bulunur ve bu ortalama kullanıcının puanlarından çıkarılır (slayttaki ifadeyle "Normalize ratings by subtracting row mean", ekrandan, 01:40:00).

A için adım adım:

- A'nın puanları 4, 5 ve 1'dir; toplam 10, ortalama $10/3$.
- $4 - 10/3 = 2/3$, $5 - 10/3 = 5/3$, $1 - 10/3 = -7/3$.

D için: puanlar 3 ve 3, ortalama 3; merkezlenmiş değerler 0 ve 0. Diğer kullanıcılar için de aynı işlem yapılır. Slayttaki merkezlenmiş matris:

| | HP1 | HP2 | HP3 | TW | SW1 | SW2 | SW3 |
|---|---|---|---|---|---|---|---|
| A | 2/3 | | | 5/3 | −7/3 | | |
| B | 1/3 | 1/3 | −2/3 | | | | |
| C | | | | −5/3 | 1/3 | 4/3 | |
| D | | 0 | | | | | 0 |

Bu dönüşümle her kullanıcının puanları bir merkez etrafında normalleştirilmiş olur. Artık boş hücrelere 0 yazıldığında bu 0, kullanıcının ortalama puanı anlamına gelir: kullanıcının henüz izlemediği filmlere ortalama bir değer vermiş gibi davranılır. Ayrıca bir değerin artı ya da eksi olması, kullanıcının o filmi sevip sevmediğini gösterir: A, HP1 ve Twilight'a artı, SW1'e eksi değer vermiştir.

> **Ders sonrası not:** Hoca A'nın merkezlenmiş değerlerini sözlü olarak "artı bir, artı bir, eksi bir" diye özetledi. Ekrandaki değerler $2/3$, $5/3$ ve $-7/3$'tür (ekrandan, 01:40:00); hocanın vurguladığı işaretler aynıdır.

Kullanıcı bazında bu normalleştirme yapıldıktan sonra boşluklara 0 yazılır ve kosinüs benzerliği hesaplanır:

- $\text{sim}(A,B) \approx 0.09$
- $\text{sim}(A,C) \approx -0.56$

Önceki örnekte iki benzerlik arasındaki fark yaklaşık 0.06 idi. Burada fark yaklaşık $0.09 - (-0.56) \approx 0.65$'tir. A-B ile A-C arasındaki farkın çok daha büyük olduğu artık yakalanmıştır.

<!-- BELİRSİZ: Altyazıda bu fark "0.064" diye geçiyor; büyük olasılıkla Whisper hatasıdır. Değerler python ile hesaplandı (0.092 ve -0.559). -->

Bu yönteme **merkezlenmiş kosinüs benzerliği** (centered cosine similarity) denir; bazı kitaplarda **Pearson korelasyon benzerliği** olarak da geçer. Bu yöntemle "sert puanlayıcılar" (hep düşük puan verenler) ve "kolay puanlayıcılar" (hep yüksek puan verenler) önce ortalamaya çekilir, sonra benzerliklerine bakılır.

> **Ek bilgi (derste anlatılmadı):** Pearson korelasyonu aslında iki kullanıcının yalnız ortak puanladığı ürünler üzerinden, her kullanıcının o ürünlerdeki ortalamasıyla hesaplanır. Buradaki merkezlenmiş kosinüs ise her kullanıcının bütün puanlarının ortalamasını çıkarır ve boşlukları 0 sayar. Bu yüzden ikisi çoğu kaynakta yakın akraba sayılsa da sayısal sonuçları her zaman aynı değildir.

### 7.6 Puan tahmini

Bir kullanıcının puan vektörüne benzer diğer kullanıcılar Pearson korelasyonuyla bulunduktan sonra, kullanılacak benzer kullanıcı sayısı $k$ ile sınırlandırılır. Örneğin "en yakın iki benzer kullanıcının değerlerini kullanarak $x$'in puan vektöründeki bilinmeyen değerleri bulalım" denir.

Slayttaki tanımlar (ekrandan, 01:45:00):

- $r_x$: $x$ kullanıcısının puan vektörü.
- $N$: $x$'e en benzer olan ve $i$ ürününü de puanlamış $k$ kullanıcının kümesi.
- $x$ kullanıcısı ve $i$ ürünü için tahmin:
  - Seçenek 1: $r_{xi} = \dfrac{1}{k} \sum_{y \in N} r_{yi}$
  - Seçenek 2: $r_{xi} = \dfrac{\sum_{y \in N} s_{xy} \, r_{yi}}{\sum_{y \in N} s_{xy}}$, burada $s_{xy} = \text{sim}(x,y)$.

**Seçenek 1.** $x$ kullanıcısının bilinmeyen $i$. değeri hesaplanmak istenir. En yakın $k$ kullanıcı belirlenir; bu kullanıcıların mutlaka $i$ ürününe puan vermiş olması gerekir. Bu kullanıcıların $i$'ye verdiği puanların ortalaması, $1/k$ ile çarpılarak alınır. Bu seçenekte benzerlik derecesi hesaba katılmaz.

**Seçenek 2.** Benzerlikler ağırlık olarak katılır. $x$'e en yakın iki kullanıcı olduğunu, ama birinin Pearson benzerliğinin $x$'e çok yakın, diğerinin çok uzak olduğunu düşünelim (yukarıdaki örnekteki 0.09 ve −0.56 gibi). Bu iki kullanıcının bir ürüne verdiği puanların düz ortalamasını almak doğru değildir. $x$'e daha yakın kullanıcının puanına daha çok, uzak kullanıcının puanına daha az ağırlık verilmelidir. Bunun için her komşunun Pearson benzerliği ile $i$ ürününe verdiği puan çarpılır, bu çarpımlar toplanır ve benzerliklerin toplamına bölünür. Sonuç, $x$'in $i$'ye vereceği puanın ağırlıklı tahminidir.

## 8. Öğe-Öğe İşbirlikçi Filtreleme

### 8.1 Fikir

Şimdiye kadar anlatılan **kullanıcı-kullanıcı** (user-user) işbirlikçi filtrelemedir: bir kullanıcının bilinmeyen değerleri, ona benzeyen kullanıcıların o ürünlere verdiği puanlardan bulunur; kullanıcıların puan vektörleri Pearson korelasyonuyla karşılaştırılır.

Slayttaki diğer bakış açısı **öğe-öğe** (item-item) yaklaşımıdır (ekrandan, 01:50:00):

- $i$ ürünü için diğer benzer ürünler bulunur.
- $i$ ürününün puanı, benzer ürünlere verilen puanlara dayanarak tahmin edilir.
- Kullanıcı-kullanıcı modelindeki benzerlik ölçüleri ve tahmin fonksiyonları aynen kullanılabilir.

$$r_{xi} = \frac{\sum_{j \in N(i;x)} s_{ij} \cdot r_{xj}}{\sum_{j \in N(i;x)} s_{ij}}$$

- $s_{ij}$: $i$ ve $j$ ürünlerinin benzerliği.
- $r_{xj}$: $x$ kullanıcısının $j$ ürününe verdiği puan.
- $N(i;x)$: $x$'in puanladığı ve $i$'ye benzer ürünlerin kümesi.

Matris şöyle düşünülür: satırlarda ürünler (filmler), sütunlarda kullanıcılar vardır. Aynı formül ve yaklaşım uygulanır; yalnız bir ürünün puan vektörü diğer ürünlerin puan vektörleriyle karşılaştırılır. En yakın $k$ puan vektörü bulunur ve bunlardan, tahmin edilmek istenen kullanıcı için değer verilmiş olanların ağırlıklı ortalaması alınır. Formül aynıdır, yalnız matrisin görünümü değişmiştir.

### 8.2 Örnek

Slayttaki örnekte (ekrandan, 01:55:00) satırlarda 6 film, sütunlarda 12 kullanıcı vardır; komşu sayısı $|N| = 2$'dir. Sarı hücreler bilinen puanlardır (kullanıcı filmi izlemiş ve 1-5 arası puan vermiş), beyaz hücreler bilinmeyenlerdir. Amaç, öğe-öğe işbirlikçi filtrelemeyle beyaz hücreleri bulmaktır. Örneğin 5 numaralı kullanıcıya film önerilecekse, bu kullanıcının izlemediği filmlerden hangisinin tahmini daha yüksek çıkarsa o önerilir.

| film \ kullanıcı | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | 1 | | 3 | | ? | 5 | | | 5 | | 4 | |
| 2 | | | 5 | 4 | | | 4 | | | 2 | 1 | 3 |
| 3 | 2 | 4 | | 1 | 2 | | 3 | | 4 | 3 | 5 | |
| 4 | | 2 | 4 | | 5 | | | 4 | | | 2 | |
| 5 | | | 4 | 3 | 4 | 2 | | | | | 2 | 5 |
| 6 | 1 | | 3 | | 3 | | | 2 | | | 4 | |

Hoca beyaz hücrelerden birini, film 1 ile kullanıcı 5'in kesişimini ($r_{15}$) seçerek hesabı gösterdi; diğer bütün beyaz hücreler de aynı yolla hesaplanır.

**Adım 1: Satırları merkezle.** Pearson korelasyonunu bulmak için her satırın ortalaması bulunur ve satırdaki değerlerden çıkarılır. Film 1'in puanları 1, 3, 5, 5, 4'tür; ortalama $18/5 = 3.6$. Merkezlenmiş değerler: $1 - 3.6 = -2.6$, $3 - 3.6 = -0.6$, $5 - 3.6 = 1.4$, $5 - 3.6 = 1.4$, $4 - 3.6 = 0.4$. Boş hücrelere dokunulmaz. Bu işlem bütün satırlar için yapılır.

**Adım 2: Benzerlikleri hesapla.** Film 1'in merkezlenmiş puan vektörü ile diğer bütün filmlerin vektörleri arasındaki kosinüs benzerlikleri hesaplanır. Film 1'in kendisiyle benzerliği doğal olarak 1'dir.

| film | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| $\text{sim}(1, m)$ | 1.00 | −0.18 | 0.41 | −0.10 | −0.31 | 0.59 |

<!-- BELİRSİZ: Benzerlik değerlerinin gösterildiği slaytın karesi yok; altyazıda yalnız 0.41 ve 0.59 geçiyor. Tablodaki bütün değerler ekrandaki matristen python ile hesaplandı. -->

**Adım 3: Komşuları seç.** Film 1'e en yakın iki film seçilir; ama yalnız 5 numaralı kullanıcının puan verdiği filmler arasından. Örneğin kullanıcı 5'in puanı olmayan bir film, benzer olsa bile seçilmez. Bu koşulla en yakın iki film, 3 numaralı film ($s_{13} = 0.41$) ve 6 numaralı filmdir ($s_{16} = 0.59$).

**Adım 4: Ağırlıklı ortalama.** Kullanıcı 5'in film 3'e verdiği puan 2, film 6'ya verdiği puan 3'tür.

$$r_{15} = \frac{0.41 \cdot 2 + 0.59 \cdot 3}{0.41 + 0.59} = \frac{0.82 + 1.77}{1.00} = 2.59 \approx 2.6$$

Yani kullanıcı 5, film 1'i izleseydi ona yaklaşık 2.6 puan vereceği tahmin edilir. Bu hesap bütün beyaz hücreler için yapılınca, kullanıcı 5 geldiğinde beyaz hücrelerdeki tahminlere bakılır ve en yüksek tahminli film ona önerilir.

> **Ders sonrası not:** Hoca 0.41 ve 0.59 değerlerine "uzaklık" dedi. Bunlar benzerlik değerleridir: değer büyüdükçe film 1'e daha yakın demektir ve tahminde ağırlık olarak kullanılırlar.

### 8.3 Kullanıcı-kullanıcı mı, öğe-öğe mi?

İki yöntemde formüller aynıdır; yalnız matrisin sütunları satır yapılmıştır. Bu yüzden ikisinin benzer sonuç vereceği düşünülebilir. Ancak pratikte öğe-öğe işbirlikçi filtreleme daha iyi sonuç verir.

Bunun nedeni insanların ürünlerden çok daha karmaşık olmasıdır. İki insanın benzerliğine bakıp "bu kişi şu filmleri izlemiş, diğerleri de bunları izlemiş, öyleyse buna şunu önereyim" demek her zaman işe yaramaz. Heavy metal seven bir kişi klasik müziği de sevebilir; insanların beğenileri ve ilgi alanları geniş bir yelpazeye yayılır. Ürünlerin birbirine benzerliği ise daha iyi tanımlanabilir.

> **Hocanın vurgusu:** Öğe-öğe işbirlikçi filtrelemenin kullanıcı-kullanıcı yönteminden daha başarılı sonuç verdiği gösterilmiştir. Bu yüzden işbirlikçi filtreleme kullanılırken öğe-öğe yöntemi tercih edilmelidir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:15:00): Ürünler filmlerdir ve tek özellik oyuncudur; ürün profili her oyuncu için 0 ya da 1 içeren bir vektördür. $x$ kullanıcısı 5 film izlemiştir: 2'sinde A oyuncusu, 3'ünde B oyuncusu oynar. Kullanıcı profili ürün profillerinin ortalaması olduğuna göre A ve B özelliklerinin ağırlıkları nedir?

> **Çözüm (derste verildi):** A ağırlığı $= 2/5 = 0.4$, B ağırlığı $= 3/5 = 0.6$.

**Soru 2** (ekrandan, 01:20:00): Aynı örnekte puanlar 1-5 yıldızdır: A'nın filmlerine 3 ve 5, B'nin filmlerine 1, 2 ve 4 verilmiştir. Puanları kullanıcının ortalamasını çıkararak normalleştirin ve A ile B'nin profil ağırlıklarını bulun.

> **Çözüm (derste verildi):** Ortalama $15/5 = 3$. A: normalleştirilmiş puanlar $0, +2$, ağırlık $(0+2)/2 = 1$. B: normalleştirilmiş puanlar $-2, -1, +1$, ağırlık $(-2-1+1)/3 = -2/3$.

**Soru 3** (ekrandan, 01:30:00 ve 01:35:00): Bölüm 7.2'deki fayda matrisinde (A: HP1=4, TW=5, SW1=1; B: HP1=5, HP2=5, HP3=4; C: TW=2, SW1=4, SW2=5; D: HP2=3, SW3=3) $\text{sim}(A,B)$ ve $\text{sim}(A,C)$'yi (a) Jaccard, (b) boşluklar 0 kabul edilerek kosinüs, (c) merkezlenmiş kosinüs ile hesaplayın. Hangisi $\text{sim}(A,B) > \text{sim}(A,C)$ sezgisini yakalar?

> **Çözüm (derste verildi):** (a) Jaccard: $1/5$ ve $2/4$; sezgiye ters, çünkü puan değerlerini yok sayar. (b) Kosinüs: yaklaşık 0.38 ve 0.32; sıra doğru ama fark yalnız 0.06, çünkü boşluk olumsuz puan gibi davranır. (c) Merkezlenmiş kosinüs: A'nın ortalaması $10/3$, merkezlenmiş A $= (2/3, 5/3, -7/3)$; benzerlikler yaklaşık 0.09 ve −0.56. Sezgiyi en iyi merkezlenmiş kosinüs yakalar. Değerler python ile doğrulandı.

**Soru 4** (ekrandan, 01:55:00): Bölüm 8.2'deki 6 film × 12 kullanıcılık matriste, $|N| = 2$ ile öğe-öğe işbirlikçi filtreleme kullanarak 5 numaralı kullanıcının 1 numaralı filme vereceği puanı tahmin edin.

> **Çözüm (derste verildi):** Film 1'in ortalaması 3.6. Merkezlenmiş kosinüs benzerlikleri: film 3 için 0.41, film 6 için 0.59 (kullanıcı 5'in puanladığı en benzer iki film). Kullanıcı 5'in bu filmlere puanları 2 ve 3. $r_{15} = (0.41 \cdot 2 + 0.59 \cdot 3)/(0.41 + 0.59) \approx 2.6$. Python ile doğrulandı (2.59).

## Dersin Toparlaması

Bu derste büyük veri üzerinde çalışan öneri sistemleri işlendi. Web'deki bolluk ve uzun kuyruk olgusu, az popüler ürünleri doğru kullanıcıya ulaştıran sistemleri gerekli kılar. Öneri problemi, müşteri-ürün ikililerine puan atayan bir fayda fonksiyonu ve seyrek bir fayda matrisi olarak modellenir; bütün yöntemlerin amacı bu matrisin boş hücrelerini dolu hücrelerden tahmin etmektir. Bunun önünde puan toplama (açık ve örtük geri bildirim), seyreklik ve soğuk başlangıç gibi zorluklar vardır.

İçerik tabanlı yaklaşımda ürünler özellik vektörleriyle (metinlerde TF-IDF ile seçilen kelimelerle) temsil edilir, kullanıcının puanladığı ürünlerden bir kullanıcı profili kurulur ve kosinüs benzerliğiyle en yakın ürünler önerilir. İşbirlikçi filtrelemede ise benzer kullanıcıların (ya da benzer ürünlerin) puanlarından yararlanılır; doğru benzerlik ölçüsü merkezlenmiş kosinüstür ve tahmin benzerlikle ağırlıklı ortalamayla yapılır. Pratikte öğe-öğe işbirlikçi filtreleme, kullanıcı-kullanıcı yönteminden daha başarılıdır. Hoca bir sonraki derste kümeleme (clustering) konusunun işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
