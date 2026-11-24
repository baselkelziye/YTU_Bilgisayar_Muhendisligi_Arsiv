# Ders 11 Genişletilmiş Notu: Kümeleme: Hiyerarşik Kümeleme, k-means ve BFR Algoritması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kümeleme Problemi ve Uygulamaları
- 2. Uzaklık Ölçüleri ve Yöntemlerin Sınıflandırması
- 3. Birleştirici Hiyerarşik Kümeleme
- 4. Öklid Dışı Uzayda Hiyerarşik Kümeleme
- 5. Ne Zaman Durmalı? Uyum (Cohesion) Ölçüleri
- 6. Hiyerarşik Kümelemenin Karmaşıklığı
- 7. k-means Algoritması
- 8. BFR Algoritması
- 9. Mahalanobis Uzaklığı ve Kümelere Kabul
- Örnek Sorular
- Dersin Toparlaması

## 1. Kümeleme Problemi ve Uygulamaları

Bu ders, MMDS kitabının (Mining of Massive Datasets, Leskovec, Rajaraman ve Ullman) 7. bölümü olan kümeleme (clustering) konusunu işler. Slaytlar dört parça hâlindedir: genel bakış ve uygulamalar, hiyerarşik kümeleme, k-means algoritması ve BFR algoritması (ekrandan, 00:05:00). Hoca, bu konuyla birlikte kitabın 9. bölümüne kadar olan konuların neredeyse tamamının işlendiğini belirtir; slaytlar ve kitabın bölüm PDF'leri, video dersleri ve sunumları kitabın sayfasında bulunabilir.

### 1.1 Problemin tanımı

Bize $n$ tane veri noktası (data point) verilir. Bu noktalar iki boyutlu olabileceği gibi çok boyutlu da olabilir. Amaç, bu noktaları gruplara, yani kümelere (cluster) ayırmaktır. Grupları oluştururken iki şeye dikkat edilir:

- Aynı kümeye konan noktalar birbirine yakın olmalıdır.
- Farklı kümeler birbirinden olabildiğince uzak olmalıdır.

Noktalar iki boyutluysa sorun yoktur; noktaları çizip grupları gözle bile seçebiliriz. Ama noktalar 100, 200 boyutlu olursa görselleştirerek grup bulmak çok zorlaşır. Hatta o kadar yüksek boyutta, iki nokta arasındaki uzaklık neredeyse bütün nokta çiftleri için aynı değere yaklaşır. Kümeleme de tam olarak bu uzaklıklara dayandığı için yüksek boyut problemi zorlaştırır.

İdeal bir kümelemede gruplar birbirinden net biçimde ayrılır. Gerçek hayat verilerinde ise daha çok birbirine geçmiş, kesişen gruplarla karşılaşılır. Slaytta bu durum, çok sayıda renkli ve iç içe geçmiş nokta bulutuyla "Clustering is a hard problem!" başlığı altında gösterilir (ekrandan, 00:20:00). Böyle bir resimde uygun algoritmalarla kümeleri bulmak, boyut sayısı da yüksekse, oldukça zordur.

### 1.2 Gökyüzü nesneleri (SkyCat)

İnternette erişilebilen veri kümelerinden biri gökyüzündeki nesnelerin bulunduğu SkyCat veri kümesidir. Burada her nesne 7 farklı frekans bandıyla, yani 7 boyutlu bir vektörle ifade edilir. Bu noktalar kümelendiğinde birbirine yakın noktalar aynı tür nesneleri gösterir: galaksileri ifade eden nesneler birbirine yakın düşer, yıldızları ifade eden nesneler birbirine yakın düşer. Hoca bu örneği, problemin ne kadar zorlayıcı olabileceğini göstermek için verir; ileride bu veri kümesinin yaklaşık 2 milyar 7 boyutlu noktadan oluştuğunu da söyler.

### 1.3 Müzik CD'leri

Büyük bir müzik mağazasında satılan CD'ler gruplandırılmak istensin. Bir CD, mağazanın müşterileriyle ifade edilebilir: mağazanın $n$ müşterisi varsa, bu CD'yi almış olan müşteriler için 1, diğerleri için 0 yazılır. Böylece her CD için $n$ boyutlu bir vektör elde edilir. Bütün CD'ler için bu yapılıp kümeleme uygulanırsa birbirine benzer CD'ler bulunur.

Tersi de yapılabilir. Benzer beğenilere sahip müşterileri gruplamak istiyorsak, bu kez her müşteri için CD uzayında bir vektör kurulur: boyutlar CD'lerdir, müşterinin aldığı CD'lere 1, diğerlerine 0 yazılır. Bu CD uzayında kümeleme yapılınca benzer beğenili müşteriler bulunur.

### 1.4 Belgeler ve konular

Belgeler de içlerindeki önemli kelimelerle vektör olarak ifade edilebilir. Kelime uzayında toplam $n$ kelime varsa, belgede geçen kelimelere 1, geçmeyenlere 0 yazılır. Bütün belgeler böyle ifade edilip kümelenince aynı konudaki (topic) benzer belgeler bulunur.

Slayttaki ikili (dual) formülasyon da aynı fikrin tersidir: bir konu, birçok belgede birlikte geçen kelimelerin grubudur; belgeler yerine kelimeler kümelenir (ekrandan, 00:25:00). Bu durumda her kelime için boyutları belgeler olan bir vektör kurulur: kelimeyi içeren belgelere 1, diğerlerine 0 yazılır. Bu vektörler kümelenince konular ortaya çıkar.

Hoca, her iki problem türünde de hem sayıca çok hem de boyutu büyük veri noktalarının kümelenmesinden söz edildiğini vurgular.

## 2. Uzaklık Ölçüleri ve Yöntemlerin Sınıflandırması

### 2.1 Uzaklık ölçüleri

Gruplama yapılırken iki $n$ boyutlu vektörün birbirine yakın olup olmadığına bakılır; bunun için bir uzaklık ölçüsü (distance metric) tanımlamak gerekir. Önceki derslerde konuşulan ölçüler şunlardır:

- Jaccard: iki belgenin kesişimindeki kelime sayısının birleşimindeki kelime sayısına oranı.
- Öklid (Euclidean) uzaklığı: iki vektör arasındaki uzaklık Öklid formülüyle bulunur.
- Kosinüs (cosine) uzaklığı: her nokta orijinden o noktaya giden bir vektör gibi düşünülür; iki vektör arasındaki açıdan yola çıkılır.
- Düzenleme (edit) uzaklığı.

> **Ders sonrası not:** Hoca kesişim/birleşim oranını "Jaccard distance" diye andı. Bu oran Jaccard benzerliğidir; Jaccard uzaklığı $1 - \dfrac{|A\cap B|}{|A\cup B|}$ biçimindedir.

### 2.2 İki ana yöntem ailesi

Slayttaki genel bakış (ekrandan, 00:30:00):

- Hiyerarşik (hierarchical) kümeleme
  - Birleştirici (agglomerative, aşağıdan yukarı, bottom-up): başta her nokta bir kümedir; en "yakın" iki küme tekrar tekrar birleştirilir.
  - Bölücü (divisive, yukarıdan aşağı, top-down): bütün veri tek bir kümeyle başlar ve yinelemeli olarak bölünür.
- Nokta atama (point assignment)
  - Bir küme kümesi tutulur; noktalar "en yakın" kümeye aittir.

Birleştirici yaklaşımda $n$ nokta varsa başta $n$ küme vardır. Bütün olası ikililerin uzaklığı bulunur (1 ile 2, 1 ile 3, 1 ile 4, ..., 2 ile 3, ...). En yakın ikili küçük bir küme hâline getirilir; artık $n-1$ küme vardır: biri iki elemanlı, $n-2$'si tek elemanlı. Aynı işlem tekrarlanır ve yukarı doğru çıkılırken birleşmeleri kaydeden ek bir veri yapısı oluşturulur. Bölücü yaklaşımda ise bütün veri önce ikiye ayrılır, sonra her parça yeniden ikiye ayrılır ve aşağı inilir. Derste birleştirici yaklaşım üzerinde durulur.

Nokta atama tabanlı algoritmalara ise baştan veride kaç küme olduğu söylenir. Algoritma her noktayı, hangi kümeye daha yakınsa o kümeye atar. Bütün noktalar atandıktan sonra veri kümesindeki gruplar belirlenmiş olur.

## 3. Birleştirici Hiyerarşik Kümeleme

### 3.1 Temel işlem ve dendrogram

Temel işlem, en yakın iki kümeyi tekrar tekrar birleştirmektir. İlk başta her nokta bir kümedir; bütün ikililerin uzaklığı hesaplanır, en yakın iki tek elemanlı küme birleştirilir ve bu sürekli yapılır. Bu sırada dendrogram adı verilen bir veri yapısı oluşturulur. Dendrogramda alt kısımda veri noktaları vardır; dikey ekseni zaman ekseni gibi düşünmek mümkündür: yukarı çıktıkça zaman ilerler, yani daha aşağıda görünen birleşme daha önce yapılmıştır.

### 3.2 Üç önemli soru

Slaytta algoritmanın çalışması için yanıtlanması gereken üç soru verilir (ekrandan, 00:35:00):

1. Birden fazla noktadan oluşan bir küme nasıl temsil edilir? İki tek elemanlı küme birleşip iki elemanlı bir küme olunca, bir sonraki adımda bu küme diğer tek elemanlı kümelerle karşılaştırılırken neyle temsil edilecektir?
2. Kümelerin "yakınlığı" nasıl belirlenir? Örneğin iki elemanlı bir küme ile üç elemanlı bir küme arasındaki uzaklık, orta noktaları arasındaki uzaklık mı, yoksa her kümeden birer nokta seçilip bu noktalar arasındaki uzaklık mı olacaktır?
3. Birleştirme ne zaman durur? Sonuna kadar gidilirse $n$ elemanlı tek bir küme elde edilir, bu da anlamsızdır. Dendrogramın bir yerinden yatay bir çizgi çekmek, o anda kaç küme olduğunu verir; örneğin bir seviyede çizilen çizgi dört kümeyi ayırabilir. Hangi seviyede durulacağına karar vermek gerekir.

### 3.3 Öklid uzayında yanıtlar: centroid

Birinci soru için Öklid uzayında merkez (centroid) bulunur. Kümede kaç nokta varsa, bu $n$ boyutlu vektörlerin boyut boyut ortalaması alınır. Sonuçta kümeyi temsil eden tek bir vektör elde edilir; bu vektörün her boyutu, kümedeki noktaların o boyuttaki değerlerinin ortalamasıdır. Centroid alabilmek için noktaların her boyutundaki değerin Öklid uzayında, yani nümerik olması gerekir; kategorik değerlerde ortalama alınamaz.

İkinci soru için iki kümenin centroid'leri arasındaki uzaklığa bakılır. Hoca başka seçenekler de olduğunu söyler: iki kümenin birbirine en yakın noktaları arasındaki uzaklık ya da birbirine en uzak noktaları arasındaki uzaklık da kullanılabilir. Derste centroid'ler arası uzaklık seçilmiştir.

### 3.4 Sayısal örnek

Slayttaki örnekte altı tane iki boyutlu nokta vardır (ekrandan, 00:40:00): $(0,0)$, $(1,2)$, $(2,1)$, $(4,1)$, $(5,0)$, $(5,3)$. Şekilde "o" veri noktasını, "x" centroid'i gösterir.

- Başlangıç: altı küme vardır. Algoritma bütün ikililerin uzaklığını bulur; bu $\binom{6}{2} = 15$ ikilidir.
- 1. adım: en yakın ikili $(1,2)$ ile $(2,1)$'dir; uzaklık $\sqrt{1^2+1^2} = \sqrt2 \approx 1{,}414$. Bunlar birleştirilir, dendrograma ilk birleşme eklenir. Yeni kümenin centroid'i $\left(\frac{1+2}{2}, \frac{2+1}{2}\right) = (1{,}5;\ 1{,}5)$ olur. Artık beş küme vardır: üç tek nokta, bir tek nokta daha ve yeni oluşan iki elemanlı küme. Birleşen iki nokta artık ayrı ayrı ele alınmaz; küme centroid'iyle temsil edilir.
- 2. adım: centroid ile diğer tek elemanlı kümeler ve tek elemanlı kümeler arasındaki uzaklıklar hesaplanır. $(4,1)$ ile $(5,0)$ arasındaki uzaklık da $\sqrt2$'dir ve en küçüktür; birleştirilir. Centroid $(4{,}5;\ 0{,}5)$. Artık dört küme vardır: ikisi iki elemanlı, ikisi tek elemanlı.
- 3. adım: mavi küme (centroid $(1{,}5;\ 1{,}5)$) ile $(0,0)$ arasındaki uzaklık en küçüktür: $\sqrt{1{,}5^2+1{,}5^2} \approx 2{,}121$. Birleştirilir; yeni centroid $\left(\frac{0+1+2}{3}, \frac{0+2+1}{3}\right) = (1,1)$. Üç küme kalır.
- 4. adım: büyük kümenin centroid'i $(1,1)$, yeşil kümenin centroid'i $(4{,}5;\ 0{,}5)$ ve tek nokta $(5,3)$ arasındaki uzaklıklara bakılır. Yeşil küme ile $(5,3)$ arası $\sqrt{0{,}5^2+2{,}5^2} \approx 2{,}550$ en küçüktür (ara adım eklendi). Birleştirilir; centroid $\left(\frac{4+5+5}{3}, \frac{1+0+3}{3}\right) = (14/3,\ 4/3) \approx (4{,}7;\ 1{,}3)$.
- 5. adım: iki küme kalır ve bunlar da birleştirilir.

Dendrogramda ilk iki birleşme (mavi ve yeşil ikililer) en altta, ardından $(0,0)$'ın mavi kümeye, sonra $(5,3)$'ün yeşil kümeye katılması ve en üstte son birleşme görünür. Bu birleşme sırası ve uzaklıklar python ile doğrulanmıştır.

Hoca burada algoritmanın nerede durması gerektiği sorusunu ileriye bırakır: sonuna kadar gidip tek bir küme oluşturmanın anlamı yoktur.

## 4. Öklid Dışı Uzayda Hiyerarşik Kümeleme

### 4.1 Clustroid

Noktaların boyutlarındaki değerler nümerik değil de kategorik olursa (Öklid dışı, non-Euclidean uzay), noktaların ortalaması tanımsızdır. Slaytın ifadesiyle konuşabileceğimiz tek "konumlar" noktaların kendisidir; iki noktanın "ortalaması" yoktur (ekrandan, 00:45:00).

Bu durumda birinci sorunun yanıtı clustroid'dir: kümeyi temsil etmek için kümedeki noktalardan biri, diğer noktalara "en yakın" olan gerçek bir veri noktası seçilir. İkinci sorunun yanıtı da buna bağlıdır: kümeler arası uzaklık hesaplanırken clustroid centroid'miş gibi kullanılır. Yani artık ortalama, sanal bir nokta yoktur; iki küme arasındaki uzaklık iki gerçek veri noktası arasındaki uzaklıktır. Hoca bunu üç elemanlı bir küme üzerinde gösterir: Öklid uzayında ortalama alınarak sanal bir centroid bulunurdu; Öklid dışı uzayda ise ortadaki gerçek nokta seçilir.

### 4.2 "En yakın" nokta nasıl tanımlanır?

Clustroid'i seçerken "diğerlerine en yakın" ifadesinin ne demek olduğunu açıkça belirlemek gerekir. Hoca üç ölçüt sayar:

- Diğer noktalara olan en büyük uzaklığı en küçük olan nokta.
- Diğer noktalara olan uzaklıklarının ortalaması en küçük olan nokta.
- Diğer noktalara olan uzaklıklarının kareleri toplamı en küçük olan nokta.

<!-- BELİRSİZ: Hoca birinci ölçütü "maksimum uzaklıkları toplamının minimum olması" diye söyledi; MMDS'deki karşılığı büyük olasılıkla en büyük uzaklığın en küçük olmasıdır. İlgili slayt karelerde yok. -->

Kategorik değerli iki $n$ boyutlu nokta arasındaki uzaklığın hesaplanabildiği unutulmamalıdır: hoca bunun için önceki derslerde görülen düzenleme (edit) uzaklığını ve Jaccard ölçüsünü hatırlatır.

Özetle ilk iki soru için Öklid uzayında centroid'ler, Öklid dışı uzayda ise gerçek veri noktaları olan clustroid'ler kullanılır.

## 5. Ne Zaman Durmalı? Uyum (Cohesion) Ölçüleri

Üçüncü soru, algoritmanın ne zaman durdurulacağıdır. İki yaklaşım vardır.

Birincisi, nokta atama algoritmalarında olduğu gibi veri hakkında önceden bilgi sahibi olmaktır: veride $k$ küme olduğu biliniyorsa $k$ küme kalınca durulur. Hoca tişört bedenleri örneğini verir: small, medium, large ve x-large olmak üzere dört kategori olduğu baştan bilinir; çok sayıda tişört kümelenecekse küme sayısı baştan bellidir.

İkincisi, veri hakkında bilgi yoksa, algoritmanın her adımında oluşan kümelemenin iyi mi kötü mü olduğunu gösteren bir uyum (cohesion) ölçüsü hesaplanır. Bu ölçü farklı biçimlerde tanımlanabilir:

- Çap (diameter): kümedeki birbirinden en uzak iki nokta arasındaki uzaklık.
- Yarıçap (radius): centroid ile kümedeki en uzak nokta arasındaki uzaklık.
- Yoğunluk (density): kümedeki nokta sayısının yarıçapa ya da çapa bölünmesi; ya da yarıçapın karesine bölünmesi.

Hoca bunu örnek üzerinde anlatır: ilk birleşmeden sonra beş küme vardır. Tek elemanlı kümelerin yarıçapı 1 kabul edilsin; iki elemanlı kümenin yarıçapı hesaplanır ve yoğunluğu için 2 bu yarıçapa bölünür. Böylece bu kümeleme için bir uyum değeri bulunur. Bir sonraki birleşmeden sonra yeni kümeleme için yeniden hesaplanır. Uyum değeri önceden belirlenmiş eşiği geçince kümeleme durdurulur.

<!-- BELİRSİZ: Hoca durma koşulunu "uyum değeri eşiğin altına düşerse" diye söyledi. Kullanılan ölçüye göre yön değişir: çap ya da yarıçap birleşmelerle büyür, yoğunluk ise düşer. Yoğunluğun yarıçapın karesine bölünerek hesaplanması da slayt karelerde yok. -->

## 6. Hiyerarşik Kümelemenin Karmaşıklığı

Hoca algoritmanın zaman karmaşıklığını sorar ve yanıtlar. Her adımda bütün küme ikililerinin uzaklığı bulunur; $n$'in ikili kombinasyonu yaklaşık $n^2$ mertebesindedir. Bu işlem yalnız bir birleşme içindir; toplamda $n$ eleman olduğu için yaklaşık $n$ adım gerekir. Böylece toplam karmaşıklık $O(n^3)$ olur. Slayt (ekrandan, 00:55:00):

- Saf (naive) uygulama: her adımda bütün küme çiftlerinin uzaklığını hesaplayıp birleştirmek, $O(N^3)$.
- Öncelik kuyruğu (priority queue) kullanan dikkatli bir uygulama süreyi $O(N^2 \log N)$'e indirir.
- Bu bile belleğe sığmayan gerçekten büyük veriler için fazla pahalıdır.

Hocanın yorumu: küçük ve belleğe sığan veri kümeleri için sorun yoktur, ama başta anılan SkyCat gibi yaklaşık 2 milyar 7 boyutlu noktadan oluşan bir veri kümesi için maliyet çok yüksektir. Bu algoritma yalnız fiziksel belleğe sığan veri kümeleri için kullanılabilir.

> **Hocanın vurgusu:** Hiyerarşik kümeleme en iyi ihtimalle $O(N^2\log N)$'dir; büyük veri kümelerinde uygulanabilecek bir algoritma değildir. Bu yüzden k-means'e geçilir.

## 7. k-means Algoritması

Aradan sonra nokta atama (partition) tabanlı algoritmalardan k-means anlatılır (ekrandan, 01:05:00). k-means daha büyük ölçekli verilerde kullanılabilen bir algoritmadır.

### 7.1 Varsayımlar (kısıtlar)

k-means ve k-means ailesindeki algoritmaların üç kısıtı vardır:

1. Veri Öklid uzayında olmalıdır; noktaların her boyutu nümerik olmalı ki ortalaması alınabilsin.
2. Küme sayısı $k$ baştan verilmelidir.
3. Başlangıç için veri kümesinden $k$ tane nokta seçilip algoritmaya verilmelidir; algoritma kümelemeye bu noktalardan başlar.

### 7.2 Algoritmanın adımları

Slayttaki "Populating Clusters" adımları (ekrandan, 01:10:00):

1. Her noktayı, şu anki centroid'i en yakın olan kümeye yerleştir.
2. Bütün noktalar atandıktan sonra $k$ kümenin centroid'lerinin yerlerini güncelle.
3. Bütün noktaları en yakın centroid'e yeniden ata. Bu bazen noktaları kümeler arasında taşır.
4. 2. ve 3. adımları yakınsamaya kadar tekrarla. Yakınsama: noktalar kümeler arasında yer değiştirmez ve centroid'ler sabitlenir.

Hoca bunu şöyle anlatır: başta $k$ nokta vardır; algoritma veri üzerinden bir kez geçer ve her noktayı bu $k$ noktadan en yakın olanına atar. Bütün veri tarandıktan sonra her kümenin centroid'i hesaplanır. Sonra noktalar yeni centroid'lere yeniden atanır, atamalar bitince centroid'ler güncellenir. Yeniden atama sırasında noktalar hep aynı kümelere düşüyorsa algoritma yakınsamıştır.

### 7.3 Örnek: kümelerin atanması

Slayttaki örnekte "x" veri noktalarını, kare ise centroid'i gösterir (ekrandan, 01:15:00). Algoritmaya iki küme olacağı ve iki başlangıç (seed) noktası verilir.

- 1. tur: bütün noktalar iki başlangıç noktasına atanır; birkaç nokta birinin, kalanlar diğerinin tarafında kalır. Atamalardan sonra pembe ve mavi kümelerin centroid'leri hesaplanır.
- 2. tur: noktalar yeni centroid'lere yeniden atanır; bazı noktalar küme değiştirir (örneğin dört nokta bir kümede toplanır). Centroid'ler yeniden hesaplanır.
- 3. tur: yeniden atama yapılır; centroid'ler yeniden hesaplandıktan sonra yapılan atamada noktalar aynı kümelere düştüğü için algoritma yakınsar. Üçüncü turda nihai kümeler bulunmuştur.

### 7.4 $k$ değerini seçmek: dirsek yöntemi

$k$'nın değeri veri hakkında önceden bilgi olmadan nasıl bilinir? Farklı $k$ değerleriyle kümeleme yapılır ve $k$ sürekli artırılır. Hocanın örneğinde veride üç temel küme ve tek başına duran iki nokta vardır, ama bu yapı önceden bilinmediği için $k=2$'den başlanır:

- $k=2$ ile kümeleme yapılır; her kümedeki noktaların kendi centroid'ine ortalama uzaklığı bulunur.
- $k=3$ yapılır, yeniden kümelenir ve ortalama uzaklıklar bulunur; toplam bir öncekinden düşük olur.
- $k=4$, $k=5$, ... diye devam edilir.

Yatay eksen $k$, dikey eksen centroid'e ortalama uzaklık olacak biçimde bu değerler çizilir. Slayttaki eğriye göre ortalama uzaklık doğru $k$'ya kadar hızla düşer, ondan sonra çok daha yavaş düşer (ekrandan, 01:20:00). Bir $k$'dan sonrakine geçerken düşüş miktarına (dikey eksendeki izdüşümler arasındaki farka) bakılır; düşüşün birden azaldığı, eğrinin dirsek yaptığı nokta en iyi $k$ değeridir. Bu yönteme dirsek (elbow) yöntemi denir.

<!-- BELİRSİZ: Altyazıda bu bölümde "HDFS'ların toplamı" geçiyor (01:17:41); bağlamdan "ortalama uzaklıkların toplamı" olduğu anlaşılıyor, Whisper hatası olarak düzeltildi. -->

### 7.5 Başlangıç noktalarını seçmek

Algoritma $k$'yı bildikten sonra kümelemeye başlamak için $k$ tane nokta ister. İki yöntem anlatılır:

- Örnekleme (sampling): veri belleğe sığmayacak kadar büyükse, verinin belleğe sığacak kadar bir kısmı (örneğin %10'u) rastgele seçilir. Bu örnek üzerinde bellek içi bir algoritma, örneğin hiyerarşik kümeleme çalıştırılır ve $k$ küme oluşturulur. Her kümenin centroid'ine en yakın nokta başlangıç noktası olarak alınır.
- Birbirinden uzak noktalar: önce rastgele bir nokta seçilir. İkinci nokta, birinciden olabildiğince uzak olan noktadır. Üçüncü nokta, seçilmiş iki noktaya olabildiğince uzak olan noktadır. Bu şekilde birbirinden olabildiğince uzak $k$ nokta seçilir ve algoritma bunlardan başlatılır.

Özetle birinci varsayım (Öklid uzayı) için yapılabilecek bir şey yoktur; ikinci varsayım için dirsek yöntemi, üçüncü varsayım için bu seçim yöntemleri kullanılır.

### 7.6 Karmaşıklık

Slayt (ekrandan, 01:25:00):

- Her turda en yakın centroid'i bulmak için her girdi noktası tam bir kez incelenir.
- $N$ nokta ve $k$ küme için her tur $O(kN)$'dir.
- Ama yakınsamaya kadarki tur sayısı çok büyük olabilir.
- Veri üzerinden tek geçişle kümeleme yapılabilir mi?

Hoca her turu, $k$ sabit düşünülerek $O(N)$ diye de anar. Sorun, kaç turda yakınsanacağının bilinmemesidir; tur sayısı çok büyürse toplam maliyet de çok artar. Veriyi her turda yeniden taramadan, tek geçişte k-means tarzı atama yapmanın yolu bir sonraki konudur.

## 8. BFR Algoritması

### 8.1 Tanım ve varsayımlar

BFR (Bradley-Fayyad-Reina), çok büyük (diskte duran) veri kümeleri için k-means'in bir türevidir (ekrandan, 01:30:00). k-means her turda bütün veriyi yeniden okumak zorundaydı ve tur sayısı bilinmiyordu; BFR veriyi bir kez okuyarak aynı işi yapmayı amaçlar.

İki varsayımı vardır:

1. k-means'teki gibi veri Öklid uzayında olmalıdır; noktaların ortalaması alınabilmelidir.
2. Her küme Öklid uzayında bir centroid etrafında normal dağılmıştır. Yani her boyut için, noktaların o boyuttaki değerleri normal dağılıma uymalıdır.

Hoca normal (Gauss) dağılımı hatırlatır: yatay eksende değişkenin aldığı değerler, dikey eksende frekans vardır. Ortalamadan her iki yönde bir standart sapma uzaklaşınca değerlerin yaklaşık %68'i, iki standart sapmada %95'i, üç standart sapmada %99'u bu aralıktadır. Böyle bir karakteristik gösteren veriye normal dağılıma uygun denir.

> **Ders sonrası not:** Hoca bir standart sapma için "%67" dedi; doğrusu yaklaşık %68'dir (tam değeri %68,27; iki sapma için %95,45, üç sapma için %99,73).

Bu varsayımın sonucu olarak BFR, verideki kümelerin elips biçimli olduğunu varsayar: elips biçimli bir kümede noktalar ortada daha yoğundur, kenarlara doğru seyrelir.

### 8.2 Genel işleyiş

Slayttaki şemada solda diskteki veri parçalara ayrılmıştır; sağda ana bellekte bir parça ve küme üst verisi (cluster metadata) görünür (ekrandan, 01:35:00).

- Büyük veri, fiziksel belleğe sığacak büyüklükte parçalara (segment, chunk) bölünür. Örneğin 8 GB bellek varsa parça büyüklüğü 6 GB seçilebilir.
- İlk parça belleğe alınır ve kümelenir. Bu kümelemeyle ilgili yalnız üst veri tutulur; verinin kendisi tutulmaz.
- İlk kümelemede $k$ ve başlangıç noktaları k-means bölümündeki yöntemlerle seçilir: $k$ dirsek yöntemiyle, başlangıç noktaları örnekleme (hiyerarşik kümeleme) ya da birbirinden uzak noktalar yöntemiyle.
- İkinci parça gelir; noktaları mevcut kümelere atanır. Atamalardan sonra kümelerin centroid'i, yarıçapı gibi istatistikleri güncellenir, noktalar bellekte tutulmaz. Üçüncü parça için aynısı yapılır.
- Son parça da bitince geriye kalan küme bilgisi, büyük veri kümesinde kaç küme olduğunu gösterir.

### 8.3 Üç küme türü

BFR bellekte üç tür bilgi tutar (ekrandan, 01:40:00):

- Atılan küme (discard set, DS): bir kümenin centroid'ine yeterince yakın olup kümeye giren noktalar. Bu noktalar özetlenir ve kendileri bellekte tutulmaz; yalnız centroid, yarıçap, eleman sayısı gibi istatistikler tutulur.
- Sıkıştırılmış küme (compression set, CS): mevcut hiçbir kümeye girmeyen ama birbirine yakın olan noktaların oluşturduğu küçük kümeler. Bunlar da özetlenir ama bir kümeye atanmamıştır; noktaları bellekte tutulmaz.
- Alıkonan küme (retained set, RS): hiçbir kümeye ve hiçbir CS'ye yakın olmayan yalıtılmış noktalar. Bu noktalar bellekte olduğu gibi tutulmak zorundadır.

Slayttaki "galaksiler" resminde büyük elips bir küme ve noktaları DS'dedir; küçük elipsler sıkıştırılmış kümelerdir, noktaları CS'dedir; tek tek duran noktalar RS'dedir.

### 8.4 Bir kümenin özeti: N, SUM, SUMSQ

Her küme için DS şu değerlerle özetlenir (ekrandan, 01:45:00):

- $N$: noktaların sayısı.
- $SUM$ vektörü: $i$. bileşeni, noktaların $i$. boyuttaki koordinatlarının toplamıdır.
- $SUMSQ$ vektörü: $i$. bileşeni, noktaların $i$. boyuttaki koordinatlarının kareleri toplamıdır.

Noktalar $d$ boyutluysa $SUM$ ve $SUMSQ$ $d$'şer elemanlıdır. Böylece bir küme (DS ya da CS) $2d+1$ sayıyla temsil edilir: $2d$ değer iki vektörden, 1 değer eleman sayısından gelir.

Bu üç değerden centroid ve standart sapma hesaplanabilir:

- Centroid: $c_i = \dfrac{SUM_i}{N}$; $SUM$ vektörünün her bileşeni $N$'ye bölününce centroid vektörü elde edilir.
- Varyans: $\sigma_i^2 = \dfrac{SUMSQ_i}{N} - \left(\dfrac{SUM_i}{N}\right)^2$; karekökü $i$. boyuttaki standart sapmadır. Sonuç yine $d$ boyutlu bir standart sapma vektörüdür.

<!-- BELİRSİZ: Hoca varyans formülünü ekranda gösterdi ama o slayt karelerde yok; yazılan formül MMDS'deki standart biçimdir. -->

> **Ek bilgi (derste anlatılmadı):** Bu özetin yararı toplanabilir olmasıdır: bir kümeye yeni nokta eklenince $N$'ye 1, $SUM$'a noktanın koordinatları, $SUMSQ$'ya koordinatların kareleri eklenir. İki küme birleşirken de üç değer bileşen bileşen toplanır. Bu yüzden noktaları saklamadan centroid ve varyans her an güncel tutulabilir.

### 8.5 Bir parçanın işlenmesi

İlk parça için:

1. Dirsek yöntemiyle $k$ bulunur; kümelerin centroid'lerine en yakın noktalar başlangıç noktası olarak seçilir.
2. Kalan noktalar kümelere atanır. Bir kümenin centroid'ine "yeterince yakın" olan noktalar o kümeye ve DS'ye eklenir, sonra atılır (ekrandan, 01:50:00).
3. DS: yeni eklenen noktaları hesaba katmak için her kümenin istatistikleri ayarlanır; $N$'ler, $SUM$'lar ve $SUMSQ$'lar eklenir.
4. Hiçbir DS kümesine girmeyen noktalar üzerinde bellek içi bir kümeleme algoritması (hiyerarşik kümeleme) çalıştırılır. Birbirine yakın noktalardan oluşan küçük kümeler CS olur; hiçbir küçük kümeye girmeyen tek noktalar RS (aykırı, outlier) olur.

Sonraki her parça için:

1. Noktalar mevcut DS kümelerine ve CS'lere yerleştirilmeye çalışılır. Yerleşenler bellekte tutulmaz, yalnız ilgili kümenin istatistikleri güncellenir.
2. Yerleşmeyen noktalar, önceki adımlardan kalan RS noktalarıyla birlikte yeniden hiyerarşik kümelemeyle gruplanmaya çalışılır. Birleşenler CS olarak tutulur, hiçbir gruba girmeyenler RS olarak kalır.

Son parça bittiğinde, yani bütün veri okunduğunda, kalan CS'ler ve RS noktaları ayrı bırakılmaz; her biri kendisine en yakın kümeye atanır.

### 8.6 Yakınlık kararları

Geriye iki soru kalır: bir noktanın bir kümeye yeterince yakın olup olmadığına (DS'ye konup konmayacağına) ve iki CS'nin birleştirilip birleştirilmeyeceğine nasıl karar verilir? Birinci soru için Mahalanobis uzaklığı kullanılır (Bölüm 9).

İki CS'nin birleştirilmesi için şu yapılır: her CS için $N$, $SUM$ ve $SUMSQ$ bilinir, içindeki noktalar bilinmez. Bu değerlerle iki CS birleştirilirse oluşacak kümenin varyansı, yani standart sapması hesaplanabilir. Standart sapma belirli bir eşiğin altındaysa, yani birleştirilince noktalar arasındaki uzaklık çok büyümeyecekse, CS'ler birleştirilir; değilse birleştirilmez.

### 8.7 Karmaşıklık

k-means'in dezavantajı her turda bütün veri kümesini okumasıydı. BFR'de veri yalnız bir kez okunur ve bütün noktaların kümelere ataması yapılır. Hocaya göre BFR'nin karmaşıklığı da k-means'in bir turu gibi $O(N)$, yani doğrusaldır.

## 9. Mahalanobis Uzaklığı ve Kümelere Kabul

### 9.1 Tanım

Herhangi bir anda DS kümelerinin centroid'leri ($SUM$ ve $N$'den) ve standart sapmaları ($SUMSQ$, $SUM$ ve $N$'den) bilinir. Slayttaki tanım (ekrandan, 01:55:00):

- $C$ kümesinin centroid'i $(c_1, \dots, c_d)$, standart sapmaları $(\sigma_1, \dots, \sigma_d)$.
- Nokta $P = (x_1, \dots, x_d)$.
- $i$. boyuttaki normalize uzaklık: $y_i = \dfrac{x_i - c_i}{\sigma_i}$.
- $P$ noktasının $C$ kümesine Mahalanobis uzaklığı (MD): $\sqrt{\sum_{i=1}^{d} y_i^2}$.

Yani her boyutta noktanın centroid'den kaç standart sapma uzakta olduğu hesaplanır. Örneğin birinci boyuttaki fark bir standart sapma ise $y_1 = 1$, iki standart sapma ise $y_1 = 2$ olur. Böylece uzaklık standart sapmaya göre normalize edilmiş olur; $y$ vektörü de $d$ elemanlıdır. MD, $y$ vektöründeki elemanların karelerinin toplamının kareköküdür.

### 9.2 Kabul ölçütü

Hocanın verdiği hesap (ekrandan, 02:00:00):

- $P$ her boyutta centroid'den bir standart sapma uzaktaysa her $y_i = 1$'dir; $d$ tane 1'in kareleri toplamı $d$, karekökü $\sqrt d$'dir. MD $= \sqrt d$.
- Her boyutta iki standart sapma uzaktaysa $y_i = 2$; $\sqrt{2^2 \cdot d} = 2\sqrt d$.
- Üç standart sapma uzaktaysa $3\sqrt d$.

Normal dağılım varsayımıyla slayt şunu verir: noktaların %68'i için $MD \le \sqrt d$, %95'i için $MD \le 2\sqrt d$, %99'u için $MD \le 3\sqrt d$. Slayttaki Gauss eğrisinde aralıkların olasılıkları da yazılıdır: $0$ ile $\sigma$ arası $0{,}3413$, $\sigma$ ile $2\sigma$ arası $0{,}1359$, $2\sigma$ ile $3\sigma$ arası $0{,}0214$, $3\sigma$ ötesi $0{,}00135$.

Kural: $P$ noktası, kümenin centroid'ine olan MD'si bir eşikten, örneğin $3\sqrt d$'den küçükse $C$ kümesine kabul edilir. Eşik $\sqrt d$, $2\sqrt d$ ya da $3\sqrt d$ seçilebilir. Bir nokta için MD bütün kümelerin centroid'lerine göre hesaplanır; eşikten küçük olduğu kümeye atanır. Noktaların boyut sayısı $d$ baştan bilindiği için eşiği belirlemek kolaydır; yalnız her nokta için MD hesaplanmalıdır.

> **Ek bilgi (derste anlatılmadı):** Bir nokta birden çok kümenin eşiği içinde kalırsa MMDS, büyük olasılıkla MD'si en küçük olan kümeye atamayı önerir. Mahalanobis uzaklığının bu biçimi, boyutlar arasında korelasyon olmadığı (kümelerin eksenlere hizalı olduğu) varsayımına dayanır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): $(0,0)$, $(1,2)$, $(2,1)$, $(4,1)$, $(5,0)$, $(5,3)$ noktaları centroid'ler arası Öklid uzaklığıyla birleştirici hiyerarşik kümelemeyle kümelenirse birleşmeler hangi sırayla olur ve ara centroid'ler nedir?

> **Çözüm (derste anlatıldı, ara değerler python ile doğrulandı):**
> 1. $(1,2)+(2,1)$, uzaklık $\sqrt2$; centroid $(1{,}5;\ 1{,}5)$.
> 2. $(4,1)+(5,0)$, uzaklık $\sqrt2$; centroid $(4{,}5;\ 0{,}5)$.
> 3. $(0,0)$ + mavi küme, uzaklık $\approx 2{,}121$; centroid $(1,1)$.
> 4. $(5,3)$ + yeşil küme, uzaklık $\approx 2{,}550$; centroid $(14/3,\ 4/3) \approx (4{,}7;\ 1{,}3)$.
> 5. İki küme birleşir (centroid'ler arası $\approx 3{,}682$).

**Soru 2** (derste sözlü, 00:40:49): Altı noktalı örnekte ilk birleşmeden sonra kaç küme kalır?

> **Cevap (derste verildi):** Beş: dört tek elemanlı küme ve bir iki elemanlı küme.

**Soru 3** (derste sözlü, 00:55:02): Saf birleştirici hiyerarşik kümelemenin zaman karmaşıklığı nedir?

> **Cevap (derste verildi):** Her adımda yaklaşık $n^2$ ikilinin uzaklığı hesaplanır ve yaklaşık $n$ birleşme yapılır; toplam $O(n^3)$. Öncelik kuyruğuyla $O(n^2 \log n)$'e iner (ekrandan, 00:55:00).

**Soru 4** (ekrandan, 01:25:00): k-means'te her turun maliyeti nedir? Veri üzerinden tek geçişte kümeleme yapılabilir mi?

> **Cevap (derste verildi):** Her tur $O(kN)$'dir ama tur sayısı çok büyük olabilir. Tek geçişte kümeleme BFR algoritmasıyla yapılır.

**Soru 5** (derste sözlü, 01:46:22): BFR'de $d$ boyutlu bir DS ya da CS kümesi için toplam kaç sayı tutulur?

> **Cevap (derste verildi):** $2d+1$: $N$ için 1, $SUM$ için $d$, $SUMSQ$ için $d$ sayı.

**Soru 6** (derste sözlü, 01:57:01; ekrandan, 02:00:00): Bir nokta centroid'den her boyutta bir standart sapma uzaktaysa Mahalanobis uzaklığı nedir? İki ve üç standart sapma için nedir?

> **Cevap (derste verildi):** Her $y_i = 1$ olduğundan $MD = \sqrt d$; iki sapmada $2\sqrt d$, üç sapmada $3\sqrt d$.

## Dersin Toparlaması

Bu derste kümeleme problemi, yani noktaları kendi içinde yakın, birbirinden uzak gruplara ayırma işi büyük veri bakış açısıyla ele alındı. Birleştirici hiyerarşik kümeleme, küme temsili (Öklid uzayında centroid, Öklid dışı uzayda clustroid), kümeler arası yakınlık ve durma ölçütleri (çap, yarıçap, yoğunluk) üzerinden anlatıldı ve altı noktalı bir örnekle adım adım gösterildi. Bu yöntemin $O(N^3)$, en iyi $O(N^2\log N)$ maliyeti nedeniyle yalnız belleğe sığan verilerde kullanılabileceği vurgulandı.

Ardından nokta atama tabanlı k-means algoritması, $k$'nın dirsek yöntemiyle seçilmesi ve başlangıç noktalarının örnekleme ya da birbirinden uzak noktalar yöntemiyle belirlenmesiyle birlikte işlendi. k-means'in her turda veriyi yeniden okuma sorununa çözüm olarak BFR algoritması anlatıldı: veri parçalar hâlinde bir kez okunur, kümeler yalnız $N$, $SUM$ ve $SUMSQ$ ile özetlenir, noktalar DS, CS ve RS olarak ayrılır ve bir noktanın kümeye kabulü Mahalanobis uzaklığıyla belirlenir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
