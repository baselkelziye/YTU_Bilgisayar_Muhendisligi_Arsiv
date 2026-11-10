# Ders 8 Genişletilmiş Notu: Bağlantı Analizi ve PageRank: Stokastik Matris, Kuvvet Yinelemesi ve Işınlanma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri: Büyük Veri Türleri ve Graf Verisi
- 2. Graf Verisi Örnekleri
- 3. Web Grafı ve Köprüler
- 4. Web'de Bilgiye Erişim ve Web Aramasının İki Zorluğu
- 5. Bağlantı Analizi ve Popülerlik Tabanlı Sıralama
- 6. PageRank Fikri: Bağlantılar Oy Gibidir
- 7. Akış Formülasyonu
- 8. Matris Gösterimi: Stokastik Komşuluk Matrisi
- 9. Kuvvet Yinelemesi Yöntemi
- 10. Rastgele Gezgin Yorumu ve Durağan Dağılım
- 11. Rastgele Yürüyüş (Markov Zinciri) Teoremi
- 12. İki Sorun: Örümcek Tuzağı ve Çıkmaz Uç
- 13. Çözüm: Işınlanma
- 14. Google Matrisi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yeri: Büyük Veri Türleri ve Graf Verisi

Ders, ders kitabının (Mining of Massive Datasets) bağlantı analizi (link analysis) bölümüyle devam etti. Hoca, şimdiye kadar 1, 2, 3, 4 ve 7. bölümlerin işlendiğini, bu dersin konusunun büyük veri kümeleri üzerinde PageRank algoritması olduğunu söyledi.

Hoca önce bu dersi önceki derslerle ilişkilendirdi. Şimdiye kadar görülen algoritmalar ya kendileri birer büyük veri algoritmasıydı, yani tek bir bilgisayara sığmayan veriyi işlemek için tasarlanmışlardı, ya da Spark veya Hadoop gibi büyük veri işleme kütüphanelerinde çalışan MapReduce tabanlı algoritmalardı. Bugünkü algoritma da büyük ölçekli veri için tasarlanmış bir büyük veri algoritmasıdır. Farkı, üzerinde çalıştığı verinin graf verisi olmasıdır. Amaç, büyük bir grafı analiz ederek düğümler arasında bir sıralama (ranking) elde etmektir.

Hoca büyük veriyi üç türe ayırdı:

- **Yüksek boyutlu veri (high dimensional data):** Çok sayıda özniteliği olan veri. Önceki derslerde bu veri için yerelliğe duyarlı karma (locality sensitive hashing, LSH) ve kümeleme (clustering) görüldü.
- **Graf verisi (graph data):** Düğümler (node, vertex) ve düğümler arasındaki kenarlardan (edge) oluşan veri. Bu dersin konusu.
- **Sonsuz veri (infinite data):** Sürekli akan akış verisi (stream data). Bir önceki derste işlendi.

Graf verisi özellikle sosyal ağlarda ve web verisinde karşımıza çıkar. Bu veri üzerinde sıralama ve topluluk tespiti (community detection) gibi farklı analizler yapılabilir.

<!-- BELİRSİZ: 00:33:03-00:33:30 arası altyazı Türkçe-İngilizce karışık ve kopuk; graf verisi üzerinde yapılabilecek analizlerin tam listesi okunamıyor. -->

## 2. Graf Verisi Örnekleri

Hoca slaytlarda birkaç graf görselleştirmesi gösterdi:

- **Facebook sosyal ağ grafı:** Kullanıcılar düğüm, arkadaşlıklar kenardır.
- **Blog verisi görselleştirmesi:** Slaytta düğümler iki farklı renkle (biri mavi) gösterilmişti.
- **Atıf ağı (citation network):** Her makalenin ve her kitabın sonunda bir kaynakça bulunur. Yazarlar bu kaynakçada birbirlerine atıf, yani bağlantı verir. Her makale veya kitap bir düğüm, her atıf iki düğüm arasında bir bağlantı olarak düşünülürse bir ağ elde edilir. Slayttaki çizimde düğümler konularına göre renklendirilmişti. Böyle bir grafı inceleyerek makalelerin konulara nasıl dağıldığını ve birbirlerine nasıl atıf yaptıklarını anlayabiliriz.
- **İnternet:** Web sayfalarını barındıran bilgisayarlar ve sunucular da bir ağ yapısı oluşturur. Aralarında ağ bağlantıları vardır.

<!-- BELİRSİZ: 00:34:24-00:35:05 arası altyazı "bir tane de" ve "bir şekilde" tekrarına düşmüş; blog görselleştirmesindeki iki rengin neyi temsil ettiği okunamıyor. -->

### 2.1 Web ile İnternet Farkı

Hoca, World Wide Web ile interneti birbirinden ayırdı. İnternet bir bilgisayar ağı altyapısıdır: sunucular ve aralarındaki fiziksel ve mantıksal bağlantılar. Web ise bunun bir üst katmanıdır: web sayfaları ve aralarındaki bağlantılar. Web sayfaları dünyanın her yerindeki uygulama sunucularına dağılmıştır. Bu yüzden internet ağı ile web ağı farklı iki graftır. Slaytta bir internet ağı görselleştirmesi de gösterildi.

Hoca graf verisinin yeni olmadığını, matematikte uzun yıllardır çalışıldığını ve pek çok bilim alanında karşımıza çıktığını hatırlattı. Bu dersin odağı ise web'in graf verisidir.

## 3. Web Grafı ve Köprüler

Web grafında her web sayfası bir düğümdür. Sayfalar arasındaki bağlantılara köprü (hyperlink) denir.

Hoca "köprü" adının nedenini slayttaki örnekle açıkladı. Bir sayfada "data" ve "mining" gibi kelimeler görürsünüz. Bu metin bir URL'ye bağlanmıştır. Tıkladığınızda tarayıcı sizi o sayfadan başka bir sayfaya götürür. URL'nin kendisini görmezsiniz, yalnızca metni görürsünüz, ama URL bu metne iliştirilmiştir. İşte bu yüzden bunlara köprü denir.

Kısacası:

- Web sayfaları düğümlerdir.
- Köprüler kenarlardır.

Slayttaki örnek dört sayfalık küçük bir oyuncak örnekti (toy example). Bütün web düşünüldüğünde milyarlarca sayfa birbirine bağlantı verir ve bunlar bir araya getirilince devasa bir ağ verisi oluşur.

Web grafı **yönlü (directed)** bir graftır. Çünkü bir sayfadaki köprü, o sayfadan başka bir sayfaya işaret eder. Bağlantının bir yönü vardır: bir sayfadan diğer sayfaya.

## 4. Web'de Bilgiye Erişim ve Web Aramasının İki Zorluğu

Dünyaya dağılmış, metin tabanlı bu devasa veri kümesini düzenlemek isteriz. Web'in var olma nedeni bilgiye erişmektir: Biz bilgi sunarız ve başkalarının bu bilgiye erişmesini isteriz. Hoca bilgiye erişmenin iki ana yolunu anlattı.

### 4.1 Dizin Gezme

Birinci yol web'i gezmektir (browsing). Herkesin telefon numarasını bulabileceğiniz bir telefon rehberi gibi, web'in de bir dizini (directory) olsaydı, dizinin içine bakarak istediğiniz bilgiyi bulabilirdiniz. Böyle dizinler vardır: Yahoo directory, Google directory, Open directory. Bunlar web'i kategorilere ayırır. Kategoriler arasında gezerek aradığınız sayfaya ulaşırsınız.

### 4.2 Web Araması

İkinci yol web aramasıdır (web search). Mevcut arama motorlarından birini kullanır, bir veya birkaç anahtar kelime girersiniz ve arama motorundan aradığınız bilgiyi bulmasını istersiniz. Yani gezme işini kendiniz yapmak yerine arama motoruna yaptırırsınız. Arama motoru, sorgunuzla eşleşen belgeleri (web sayfalarını) bulur.

İkinci yol birincisinden çok daha kolaydır, ama kendi zorlukları vardır. Kullanıcı genellikle bütün sonuçlara bakacak zamana sahip değildir. Çoğunlukla yalnızca ilk 10 sonuca bakar. Bu yüzden arama motoru, sorguyla en ilgili sonuçları ilk 10'da getirmelidir.

### 4.3 Zorluk 1: Kime Güvenilecek?

Bazı sayfa sahipleri, sorgulara karşılık ilk 10 sonuca girmek için sayfalarına anahtar kelimeler ekler. Oysa sayfanın içeriği bu anahtar kelimelerle tamamen ilgisizdir. Bu bir spam sayfadır. Benzer şekilde, anahtar kelimeleriniz bir sayfanın içeriğiyle eşleşse bile, o sayfadaki bilgi yanlışsa bu da güvenilmez, spam bir sayfadır. Bu tür sayfaların ilk 10 sonuçta görünmesini istemeyiz. Bu yüzden ilk soru şudur: Hangi sayfalar güvenilirdir?

<!-- BELİRSİZ: 00:45:50-00:46:18 arası altyazı kopuk; spam sayfa tanımının başı okunamıyor. -->

### 4.4 Zorluk 2: Sorguya En İyi Cevap Hangisi?

Anahtar kelimeniz milyonlarca web sayfasında geçebilir. Bunlardan hangisi en iyisidir, yani sorgunuzla en ilgili olanı hangisidir? Web aramasında çözülmesi gereken ikinci zorluk budur.

## 5. Bağlantı Analizi ve Popülerlik Tabanlı Sıralama

İlk arama motorlarından bu yana bu iki sorunu çözmek için farklı yollar denendi. Bugün bildiğimiz ve kullandığımız en ünlü yaklaşım Google'ınkidir. Google'ın yaklaşımı **popülerlik tabanlı sıralamaya (popularity ranking)** dayanır. Bu yaklaşım iki zorluğa birlikte cevap verir: Sorguyla eşleşen güvenilir sayfaları bulur ve sorguyla en iyi eşleşen cevabı bulur.

Fikir şudur: Belirli bir andaki web sayfalarından web grafı kurulur. Bu grafta düğümler web sayfaları, kenarlar sayfalar arasındaki köprülerdir. Sonra bu graf kullanılarak her sayfa için bir sıralama değeri hesaplanır. Böylece popüler olan ve olmayan sayfalar ayırt edilir.

Hoca slayttaki grafta bir mavi düğümü ve bir kırmızı düğümü karşılaştırdı. Mavi düğüm pek çok sayfadan bağlantı alıyor, kırmızı düğüm ise yalnızca bir sayfadan bağlantı alıyor. Mavi düğüme bağlantı veren sayfalar birbirini tanımıyor. Buna rağmen hepsi aynı fikirde: Mavi düğümün doğru bilgi içerdiğini düşünüyorlar. Doğru bilgi içerdiğini düşünmediğiniz bir sayfaya bağlantı vermezsiniz. Kırmızı düğüm ise tek bir sayfadan bağlantı alıyor. Bu yüzden mavi düğüm kırmızı düğümden daha prestijli, başka bir deyişle daha güvenilirdir. Yalnızca grafı analiz ederek bu iki düğümün güven açısından eşit olmadığını anlayabiliriz.

<!-- BELİRSİZ: 00:50:37-00:51:07 ve 00:52:11-00:52:39 arası altyazı kopuk ("Bu adı", "Anadolu"); Google'ın bu yaklaşımı ilk tanıttığına dair cümle tam okunamıyor. -->

### 5.1 Bağlantı Analizi Yaklaşımları

Bağlantı analizi yaklaşımlarıyla farklı işler yapılabilir:

- **Sıralama:** PageRank, Google'ın kullandığı sıralama algoritmasıdır. HITS algoritması da bir başka sıralama algoritmasıdır. Hoca HITS'i Yahoo arama motorunun kullandığını söyledi.
- **Konuya özgü PageRank (topic-specific PageRank).**
- **Spam tespiti (spam detection).**

Bu derste yalnızca bağlantı analizinin PageRank algoritması için nasıl kullanıldığı işlendi.

> **Ders sonrası not:** Hoca HITS'i Yahoo'nun kullandığını söyledi. HITS, Jon Kleinberg'in algoritmasıdır ve büyük olasılıkla daha çok Teoma (sonradan Ask.com) arama motoruyla ilişkilendirilir. Bu eşleştirmeye güvenmeyin; asıl önemli olan HITS'in PageRank'ten ayrı bir bağlantı analizi sıralama algoritması olmasıdır.

## 6. PageRank Fikri: Bağlantılar Oy Gibidir

### 6.1 Bağlantı = Oy

PageRank popülerlik sıralamasına dayanır ve temel fikri şudur: **Bağlantılar oy (vote) gibi düşünülebilir.** Az önceki örnekte mavi düğüme bağlantı veren bütün sayfalar aslında ona oy veriyordu. Bir amaçla onu seçiyorlardı, çünkü içeriğinin önemli olduğunu düşünüyorlardı. Bu yüzden her köprü bir oydur.

Buradan şu sonuç çıkar: Bir sayfa ne kadar çok gelen bağlantıya (inlink) sahipse o kadar önemlidir. Gelen bağlantı, sayfanın başka sayfalardan aldığı bağlantıdır. Bir sayfanın önemini, prestijini veya popülerliğini anlamak için gelen bağlantılarına bakarız.

Hoca iki sayfa örneği verdi: biri stanford.edu'ya ait bir sayfa, öbürü isimsiz bir web sitesi. Birincisi çok sayıda gelen bağlantı alır. İkincisini ise yalnızca bir kişi önemli bulur ve ona bağlantı verir. Gelen bağlantı sayısına bakarak, popülerlik sıralamasına göre birincinin daha önemli olduğunu söyleyebiliriz.

<!-- BELİRSİZ: 00:55:57-00:56:27 arası altyazı kopuk; stanford.edu örneğindeki bağlantı sayıları okunamıyor. -->

### 6.2 Bütün Gelen Bağlantılar Eşit Değildir

PageRank'in ikinci fikri şudur: **Bütün gelen bağlantılar eşit değildir.** Bir düğümün aldığı bağlantıların ağırlığı aynı değildir. Bazı bağlantılar diğerlerinden daha önemlidir.

Hoca bunu slayttaki bir oyuncak örnekle gösterdi. Bu çizimde düğümlerin boyutları farklıydı. Hoca her düğümün yine tek bir web sayfası olduğunu, boyut farkının yalnızca sıralama puanını vurgulamak için çizildiğini belirtti: Düğümün boyutu sıralama puanıyla orantılıdır.

- **Mavi düğüm** diğerlerine göre çok sayıda gelen bağlantı alıyor. Bu yüzden puanı en büyüktür. Bu, şimdiye kadar anlatılan "çok gelen bağlantı, yüksek puan" fikriyle uyumludur.
- **Yeşil düğüm**, D ve F gibi düğümlerden daha çok bağlantı alıyor. Bu yüzden onlardan büyüktür.
- **Sarı düğüm** yalnızca bir bağlantı alıyor. Ama bu bağlantı ağdaki en prestijli, en popüler düğümden geliyor. Bu yüzden tek bağlantıya rağmen popülerlik puanı çok büyüktür. Bu köprü, ağdaki diğer bütün bağlantılardan daha ağırdır. En prestijli düğüm, kendi ağırlığının bir kısmını bu düğüme aktarır.

Özetle, PageRank gibi popülerlik tabanlı bir sıralama puanında iki şey önemlidir: gelen bağlantıların **sayısı** ve her gelen bağlantının **ağırlığı**. Yüksek prestijli bir düğümden bağlantı alırsanız sizin puanınız da yükselir.

Hoca bunu bir benzetmeyle açıkladı: Şirketin CEO'sundan alınan bir referans mektubu, bir iş arkadaşınızdan alınan referans mektubundan çok daha değerlidir.

## 7. Akış Formülasyonu

### 7.1 Puanın Giden Bağlantılara Bölünmesi

Hoca akış formülasyonunu (flow formulation) altı düğümlü bir oyuncak örnekle anlattı. Amaç $j$ düğümünün sıralama puanı $r_j$'yi hesaplamaktır.

$j$ iki gelen bağlantı alıyor: biri $i$ düğümünden, biri $k$ düğümünden. Demek ki $r_j$, $r_i$ ve $r_k$ kullanılarak hesaplanacaktır. Ayrıca PageRank şunu söyler: Her düğüm kendi puanını, giden bağlantılarının (outlink) sayısıyla orantılı olarak sonraki düğümlere dağıtır.

- $i$'nin 3 giden bağlantısı var. $r_i$ üçe bölünür ve her bağlantı $r_i/3$ ağırlık taşır.
- $k$'nin 4 giden bağlantısı var. $r_k$ dörde bölünür ve her bağlantı $r_k/4$ ağırlık taşır.
- Bunlar toplanınca $j$'nin puanı bulunur:

$$r_j = \frac{r_i}{3} + \frac{r_k}{4}$$

- $j$'nin de 3 giden bağlantısı var. Bu yüzden $j$'nin her giden bağlantısı $r_j/3$ taşır. Sonraki düğümlerin puanı da aynı şekilde hesaplanır.

### 7.2 Genel Formül

Bu hesabın genelleştirilmiş hali şudur: $j$'ye bağlantı veren her $i$ düğümü için, $i$'nin puanını $i$'nin giden bağlantı sayısına bölüp topla.

$$r_j = \sum_{i \to j} \frac{r_i}{d_i}$$

Burada $d_i$, $i$ düğümünün giden bağlantı sayısıdır (out-degree).

### 7.3 Üç Düğümlü Örnek: y, a, m

Hoca sonra üç düğümlü bir oyuncak graf gösterdi. Bağlantılar şöyledir:

- y kendine ve a'ya bağlanır ($d_y = 2$).
- a, y'ye ve m'ye bağlanır ($d_a = 2$).
- m yalnızca a'ya bağlanır ($d_m = 1$).

y iki bağlantı alır: biri kendinden, biri a'dan. y'nin iki giden bağlantısı olduğu için kendinden gelen pay $r_y/2$'dir. a'nın da iki giden bağlantısı olduğu için a'dan gelen pay $r_a/2$'dir. a ve m için de aynısı yapılınca üç denklem çıkar:

$$r_y = \frac{r_y}{2} + \frac{r_a}{2}, \qquad r_a = \frac{r_y}{2} + r_m, \qquad r_m = \frac{r_a}{2}$$

Üç bilinmeyen ($r_y, r_a, r_m$) ve üç denklem vardır. Hoca bu sistemin tek bir çözümü olmadığını söyledi: Bütün denklemleri doğru yapan birden fazla değer kümesi vardır. Biz ise tek bir çözüm isteriz. Bu yüzden sisteme bir denklem daha eklenir: Graftaki bütün düğümlerin PageRank puanlarının toplamı 1'dir.

$$r_y + r_a + r_m = 1$$

Dört denklem ve üç bilinmeyenle sistem çözülebilir ve tek bir çözümü vardır. Çözüm şudur (ara adım eklendi):

- Üçüncü denklemden $r_a = 2 r_m$.
- Birinci denklemden $r_y/2 = r_a/2$, yani $r_y = r_a = 2 r_m$.
- Toplam: $2 r_m + 2 r_m + r_m = 5 r_m = 1$, yani $r_m = 1/5$.
- Sonuç: $r_y = 2/5$, $r_a = 2/5$, $r_m = 1/5$.

Bu sonuca göre y ile a'nın prestiji ağdaki en yüksek prestijdir ve ikisi eşittir. m'nin prestiji diğer ikisinden düşüktür.

> **Ders sonrası not:** Hoca "üç denklem, üç bilinmeyen var ama tek çözüm yok" dedi. Bunun nedeni denklemlerin homojen ve birbirine bağımlı olmasıdır: Üç denklemden biri diğer ikisinden türetilebilir (python ile $M - I$ matrisinin rangı 2 bulundu). Bu yüzden $r = 0$ ve bir çözümün her katı da çözümdür. Toplamın 1 olması koşulu ölçeği sabitler ve çözümü tekleştirir. Çözüm $(2/5, 2/5, 1/5)$ python ile doğrulandı.

### 7.4 Gauss Eliminasyonu Neden Yetmez?

Böyle küçük bir grafta akış denklemleri yazılır, toplam denklemi eklenir ve sistem hepinizin bildiği Gauss eliminasyonu (Gaussian elimination) yöntemiyle çözülür. Sorun web ölçeğinde ortaya çıkar. Milyonlarca, milyarlarca web sayfası olduğunda her sayfanın PageRank puanını denklem sistemini çözerek bulmak neredeyse imkânsızdır. Bu yüzden probleme matris gösterimiyle yaklaşılır.

## 8. Matris Gösterimi: Stokastik Komşuluk Matrisi

Web grafı $N \times N$ boyutlu bir $M$ matrisiyle gösterilir. $N$, web grafındaki toplam düğüm sayısıdır.

- Grafta $i$ düğümünden $j$ düğümüne bağlantı varsa matrisin ilgili hücresine 1 yazılır, yoksa 0 yazılır.
- Sütunlar bağlantı veren sayfaları, satırlar bağlantı alan sayfaları gösterir.
- Örneğin $i$ üç farklı sayfaya bağlantı veriyorsa, $i$'nin sütununda bu üç sayfanın satırlarında sıfırdan farklı değer bulunur, geri kalanlar 0'dır.

Sıralama vektörü $r$ ise $N \times 1$ boyutlu bir sütun vektörüdür. Her elemanı bir web sayfasının PageRank puanıdır.

### 8.1 Matris-Vektör Çarpımı ile $r_j$

Hoca $r_j$'nin matris gösterimiyle nasıl hesaplandığını anlattı. $M$'nin $j$. satırı alınır ve $r$ sütun vektörüyle çarpılır (satırın elemanları $r$'nin karşılık gelen elemanlarıyla çarpılıp toplanır). Satırda $j$'ye bağlantı veren düğümlerin hizasında sıfırdan farklı değerler vardır. Bu değerlerin her biri ilgili düğümün puanıyla çarpılır ve toplamın bir terimini verir. Bütün terimler toplanınca $r_j$ bulunur. Bu, akış formülündeki toplamın aynısıdır.

### 8.2 Neden "Stokastik"?

Matrise 1 yerine **1 bölü giden bağlantı sayısı** yazılır: $i \to j$ bağlantısı varsa

$$M_{ji} = \frac{1}{d_i}$$

Örneğin üç giden bağlantısı olan bir düğümün sütununda üç tane $1/3$ bulunur. Bu kuralla doldurulan bir matriste aynı sütundaki değerler toplanınca her sütun için 1 elde edilir. Her sütununun toplamı 1 olan matrise **stokastik matris (stochastic matrix)** denir. Komşuluk matrisi bu şekilde doldurulunca **stokastik komşuluk matrisi (stochastic adjacency matrix)** elde edilir.

> **Ders sonrası not:** Hoca 01:32:20 civarında "her satır vektörü için" dedi. Kurala göre $1/d_i$ değerleri bağlantı veren düğümün **sütununa** yazılır ve toplamı 1 olan da sütunlardır. Hocanın hemen ardından söylediği "her sütunun toplamı 1'dir" ifadesi doğrudur.

Bu matrisle PageRank denklemi tek satırda yazılır:

$$r = M \cdot r$$

### 8.3 y, a, m Örneğinin Matrisi

Üç düğüm olduğu için matris $3 \times 3$'tür.

- **y sütunu:** y'nin iki giden bağlantısı var (kendine ve a'ya). y ve a satırlarına $1/2$, m satırına 0.
- **a sütunu:** a, y'ye ve m'ye bağlanıyor, kendine bağlanmıyor. y ve m satırlarına $1/2$, a satırına 0.
- **m sütunu:** m yalnızca a'ya bağlanıyor. Tek sıfırdan farklı değer a satırındaki 1'dir.

$$M = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 1 \\ 0 & 1/2 & 0 \end{pmatrix} \quad (\text{satır ve sütun sırası: } y, a, m)$$

Her sütunun toplamı 1'dir, bu yüzden matris stokastiktir. Hoca vurguladı: Sütunlardan birinin toplamı 1 değilse bu matrise stokastik denemez.

<!-- BELİRSİZ: 01:37:15-01:37:45 arası altyazı kopuk; y sütununun anlatımı okunamıyor, matris grafın tarifinden kuruldu. -->

## 9. Kuvvet Yinelemesi Yöntemi

### 9.1 Fikir

Hesap şöyle yürür: Önce stokastik komşuluk matrisi kurulur. Sonra bir başlangıç PageRank sütun vektörüyle başlanır. $N \times N$ matris $N \times 1$ sütun vektörüyle çarpılır ve sonuç yine $N \times 1$ boyutlu bir sütun vektörüdür: ikinci durumun PageRank puanları. Bu vektör yeniden $M$ ile çarpılır, üçüncü durum bulunur, o da çarpılır, dördüncü durum bulunur. Bu yinelemeli (iterative) bir hesaptır.

Doğrusal cebirde bu tür denklemler **kuvvet yinelemesi yöntemi (power iteration method)** ile çözülebilir. Belirli bir yineleme sayısından sonra sütun vektörünün içeriği artık değişmez, bir değere yakınsar (converge).

### 9.2 Algoritma

- **Başlangıç (0. yineleme):** $N$ sayfa vardır. Her sayfaya $1/N$ puan verilir: $r^{(0)} = [1/N, \dots, 1/N]^T$. Slaytta vektör satır olarak yazılmış ama yanında transpoz işareti vardır, yani aslında bir sütun vektörüdür.
- **Yineleme:** Her adımda $r^{(t+1)} = M \cdot r^{(t)}$ hesaplanır. 1. yinelemenin sonucu, 2. yinelemede yeniden $M$ ile çarpılır.
- **Durma koşulu:** Her döngü adımının sonunda ardışık iki vektör arasındaki fark kontrol edilir. Fark çok küçük bir $\varepsilon$ değerinden küçükse, yani ihmal edilebilir düzeydeyse yineleme durdurulur:

$$\lVert r^{(t+1)} - r^{(t)} \rVert < \varepsilon$$

- Son vektör, nihai PageRank vektörüdür.

### 9.3 y, a, m Örneğinde Kuvvet Yinelemesi

Üç düğüm olduğu için her düğüm $1/3$ ile başlar. Slaytta yinelemelerin değerleri gösterildi. Altyazıda sayılar okunmadığı için aşağıdaki değerler $M$ matrisiyle python'da hesaplandı (ara adım eklendi):

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 | 1/2 | 1/6 |
| 2 | 5/12 | 1/3 | 1/4 |
| 3 | 3/8 | 11/24 | 1/6 |
| 4 | 5/12 | 17/48 | 11/48 |
| ... | ... | ... | ... |
| yakınsama | 2/5 | 2/5 | 1/5 |

Örneğin 1. yinelemede $r_y = \frac12 \cdot \frac13 + \frac12 \cdot \frac13 = \frac13$, $r_a = \frac12 \cdot \frac13 + 1 \cdot \frac13 = \frac12$, $r_m = \frac12 \cdot \frac13 = \frac16$ olur.

Belirli sayıda yinelemeden sonra fark o kadar küçülür ki yineleme durdurulur. Sonuç, Gauss eliminasyonuyla bulunanla aynıdır: y ve a en yüksek, m en düşük puana sahiptir.

<!-- BELİRSİZ: Hoca 01:43:27'de "dördüncü yineleme" diyor gibi geçiyor; bağlamdan 0. yinelemeden sonraki ilk yinelemeden söz ettiği anlaşılıyor. -->

### 9.4 Özdeğer Sistemi ve Özvektör

$r = M r$ denklemine **özdeğer sistemi (eigensystem)** denir. Bu denklem çözüldükten sonra bulunan sütun vektörüne, bizim durumumuzda sıralama vektörüne, **özvektör (eigenvector)** denir.

> **Ek bilgi (derste anlatılmadı):** $A v = \lambda v$ eşitliğini sağlayan sıfırdan farklı $v$ vektörüne $A$'nın özvektörü, $\lambda$'ya özdeğeri denir. $r = M r$, özdeğeri $\lambda = 1$ olan özvektörü aramak demektir. Sütun stokastik bir matrisin en büyük özdeğeri 1'dir; kuvvet yinelemesi tekrar tekrar $M$ ile çarparak bu baskın özvektöre yaklaşır. y, a, m örneğinde python ile bulunan özdeğerler yaklaşık $1$, $0{,}309$ ve $-0{,}809$'dur; 1'e karşılık gelen özvektör toplamı 1 olacak şekilde ölçeklenince $(2/5, 2/5, 1/5)$ çıkar.

## 10. Rastgele Gezgin Yorumu ve Durağan Dağılım

### 10.1 Yalnızca Bağlantılarla Gezinmek

Hoca aynı probleme web açısından bakmak için ekranda bir tarayıcı açtı. Tarayıcıda bir URL kutusu ve bir geri tuşu vardır. Hoca bu ikisini kaldırdığımızı düşünmemizi istedi. Bu durumda bir web sitesinden başka yere gitmenin tek yolu sayfadaki bağlantılara tıklamaktır. Bağlantılara tıklamazsanız hiçbir yere gidemezsiniz.

Hoca sınıfa şunu sordu: Ana sayfadaysanız müfredat (syllabus) sayfasına gitme olasılığınız nedir? Ana sayfada dört bağlantı vardır. Dört farklı seçeneğiniz vardır ve bir sonraki sayfaya geçmek için bunlardan birini seçmek zorundasınız. Bu yüzden müfredat sayfasına gitme olasılığı $1/4$'tür.

### 10.2 Bir Sonraki Adımda $j$'de Olma Olasılığı

Rastgele bir web gezgini (random web surfer) $t$ anında $j$'ye bağlantı veren $i_1, i_2, i_3$ sayfalarından birinde olabilir. $t+1$ anında $j$ düğümüne varma olasılığı nedir?

- $i_1$'den gelmek için: gezginin $t$ anında $i_1$'de olma olasılığı, $i_1$'in giden bağlantı sayısına bölünür: $p_{i_1}(t)/d_{i_1}$.
- $i_2$ ve $i_3$ yönünden de aynı şekilde.
- Bu olasılıklar toplanınca gezginin $t+1$ anında $j$'de olma olasılığı bulunur:

$$p_j(t+1) = \sum_{i \to j} \frac{p_i(t)}{d_i}$$

Bu denklem, önceki slaytlarda görülen PageRank akış denkleminin tamamen aynısıdır.

<!-- BELİRSİZ: 01:48:39-01:49:09 ve 01:50:43-01:51:13 arası altyazı kopuk; formülün söylendiği kısım hocanın sonraki tekrarından kuruldu. -->

### 10.3 Olasılık Dağılımı Vektörü

Şimdiye kadar sıralama vektörü dediğimiz vektöre artık **olasılık dağılımı vektörü (probability distribution vector)** denir. Web grafındaki her düğümün bir olasılığı vardır: rastgele gezginin $t+1$ anında o sayfada olma olasılığı. $t$ anındaki olasılıklar $p(t)$ sütun vektörüyle, $t+1$ anındakiler $p(t+1)$ sütun vektörüyle gösterilir:

$$p(t+1) = M \cdot p(t)$$

Bu, sıralama vektörüyle tamamen aynı şeydir. Yalnızca aynı probleme rastgele gezgin açısından bakıyoruz.

### 10.4 Durağan Dağılım

Bu denklem kuvvet yinelemesiyle çözülür. Belirli bir yinelemeden sonra $p(t+1)$ ile $p(t)$ birbirine çok yaklaşır ve eşit kabul edilebilir. O zaman

$$p = M \cdot p$$

yazılabilir. Bu, daha önce gördüğümüz özdeğer sistemi denkleminin aynısıdır. Bu olasılık vektörüne **durağan dağılım (stationary distribution)** denir. "Durağan" denmesinin nedeni, belirli bir yinelemeden sonra vektörün sabit bir değere yakınsamasıdır.

## 11. Rastgele Yürüyüş (Markov Zinciri) Teoremi

Kuvvet yinelemesini bu özdeğer sistemine her zaman uygulayamayız. Bunu ancak kullandığımız web grafı belirli koşulları sağlıyorsa yapabiliriz.

Graf bu koşulları sağlıyorsa durağan dağılım vektörünün **tek (unique)** olduğunu ve belirli bir yinelemeden sonra **mutlaka ulaşılacağını** biliriz. Hem de $t_0$ anındaki başlangıç olasılık dağılımı ne olursa olsun. Hatırlarsanız denklemi çözerken sütun vektörünün her elemanına $1/N$ vererek başlamıştık. Teorem şunu söyler: Web grafını temsil eden stokastik komşuluk matrisi $M$ bu koşulları sağlıyorsa, başlangıçta her elemana $1/N$ verilse de verilmese de yineleme tek bir çözüme ulaşır.

Buna **rastgele yürüyüş teoremi (random walk theorem)** denir. **Markov zinciri süreçleri teoremi (Markov chain processes theorem)** olarak da bilinir.

Dersin sonunda hoca teoremi şöyle özetledi: Herhangi bir başlangıç sıralama vektöründen başlayarak, $P$ matrisine uygulanan kuvvet yinelemesi tek ve pozitif bir durağan vektöre yakınsar, yeter ki $P$:

- **stokastik** olsun (her sütunun toplamı 1),
- **indirgenemez (irreducible)** olsun,
- **periyodik olmayan (aperiodic)** olsun.

Hoca bu koşulların ne anlama geldiğini bir sonraki bölümdeki iki sorun üzerinden anlattı.

> **Ek bilgi (derste anlatılmadı):** Markov zinciri dilinde indirgenemez, her durumdan her duruma (bir veya birkaç adımda) gidilebilmesi demektir; periyodik olmayan ise zincirin belirli bir döngü uzunluğuna kilitlenip sabit aralıklarla aynı durumlara dönmemesi demektir. Sonlu, indirgenemez ve periyodik olmayan bir Markov zincirinin tek bir durağan dağılımı vardır ve her başlangıç dağılımından ona yakınsanır.

## 12. İki Sorun: Örümcek Tuzağı ve Çıkmaz Uç

### 12.1 Örümcek Tuzağı

Matriste **örümcek tuzağı (spider trap)** sorunu olmamalıdır. Hoca bunu önce bir slayt örneğiyle tanımladı: Bir düğümden başlayıp bağlantıları izlediğinizde belirli sayıda adımdan sonra, örneğin iki adımda, her seferinde aynı düğüme geri dönüyorsanız bir örümcek tuzağı vardır. Böyle bir grafta kuvvet yinelemesi uygulandığında sıralama vektörü yakınsamaz. Slaytta başlangıç vektörü, ikinci yineleme ve sonraki yinelemeler gösterildi: Vektör her adımda değişiyor ve hiç yakınsamıyordu. Bu sorun varsa önce düzeltilmeli, sonra hesaba devam edilmelidir.

Sonra hoca y, a, m grafının değiştirilmiş bir halini gösterdi: Bu kez m yalnızca kendine bağlanıyordu. Hoca sınıfa "Burada örümcek tuzağı var mı?" diye sordu ve "evet" diye cevapladı. Gezgin a'dan m'ye giderse m'de takılır. Her bir adımdan sonra aynı düğüme döner. Burada "belirli adım" bir adımdır. Bu grafın stokastik komşuluk matrisi (ara adım eklendi):

$$M_{\text{tuzak}} = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 1 \end{pmatrix}$$

Hoca bu durumda kuvvet yinelemesinin yakınsadığını, ama anlamsız bir şeye yakınsadığını söyledi. Biz değerlerin sıfırdan farklı olmasını isteriz ki düğümlerin önemini birbirinden ayırabilelim. Python ile yapılan hesap (ara adım eklendi):

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 | 1/6 | 1/2 |
| 2 | 1/4 | 1/6 | 7/12 |
| 3 | 5/24 | 1/8 | 2/3 |
| yakınsama | 0 | 0 | 1 |

Bütün puan tuzaktaki m düğümünde toplanır, y ve a sıfıra gider.

> **Ders sonrası not:** Hocanın ilk slayttaki tanımı ("iki adımda hep aynı düğüme dönmek") ve vektörün salınıp yakınsamaması, büyük olasılıkla iki düğümün birbirine bağlandığı $a \leftrightarrow b$ örneğidir: $(1,0) \to (0,1) \to (1,0) \to \dots$ (python ile doğrulandı). Bu aslında **periyodiklik** sorunudur. Kitaptaki örümcek tuzağı tanımı daha geneldir: dışarıya hiç bağlantı vermeyen bir düğüm grubu. Tek düğümlü öz-döngü (m'nin kendine bağlanması) de bir örümcek tuzağıdır ve hocanın ikinci örneğindeki gibi puanı yutarak yakınsar.

### 12.2 Çıkmaz Uç

İkinci sorun **çıkmaz uç (dead end)** sorunudur. A düğümünden başlayıp bir bağlantıyı izleyerek başka bir düğüme gittiğinizde, grafa ya da A'ya geri dönmenin hiçbir yolu yoksa, yani gezgin B düğümünde takılıp kalıyorsa çıkmaz uç sorunu vardır.

Slayttaki örnekte başlangıç sıralama vektöründen sonra bir yineleme yapılıyor ve sonuçlar anlamsızlaşıyordu: Değerler sıfır oluyor ve istediğimiz bir şeye yakınsamıyordu.

Hoca bunu da y, a, m üzerinde gösterdi: Bu kez m hiçbir düğüme, kendisi de dahil, bağlantı vermiyor. Bu yüzden stokastik komşuluk matrisinde m'nin sütununun toplamı sıfırdır. Bu matris artık stokastik bile değildir. Oysa Markov zinciri teoreminin ilk koşulu matrisin stokastik olmasıdır. Matris (ara adım eklendi):

$$M_{\text{çıkmaz}} = \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 0 \end{pmatrix}$$

Python ile yapılan hesap (ara adım eklendi):

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 1/3 | 1/6 | 1/6 |
| 2 | 1/4 | 1/6 | 1/12 |
| 3 | 5/24 | 1/8 | 1/12 |
| yakınsama | 0 | 0 | 0 |

Toplam puan her adımda azalır, yani puan dışarı "sızar" ve sonunda bütün değerler sıfıra gider.

Hoca, bugünkü web'de bu iki sorunun da bulunduğunu söyledi. Kuvvet yinelemesini uygulamadan ve Markov zinciri teoreminin işlemesini, yani olasılık dağılımı vektörünün bir çözüme yakınsamasını beklemeden önce çıkmaz uç ve örümcek tuzağı sorunları çözülmelidir.

## 13. Çözüm: Işınlanma

### 13.1 URL Kutusu ve $\beta$ Olasılığı

İki sorunu çözmek için **ışınlanma (teleport)** fikri kullanılır: Rastgele gezginin bir düğümden başka herhangi bir düğüme atlayabileceği bir yöntem eklenir.

Hoca yine tarayıcıya döndü. Bu kez URL kutusunu geri ekledi. Bu kutuya her an bir URL yazıp web'deki istediğiniz sayfaya gidebilirsiniz. Bağlantıları izlemek zorunda değilsiniz. Bu, bir ışınlanma imkânı yaratır: Bağlantı izlemeden, yalnızca URL yazarak her sayfadan her sayfaya gidebilirsiniz.

Bu durumda gezginin bir sayfadan diğerine gitmek için iki yolu vardır, ve her biri için bir olasılık kullanılır:

- **$\beta$ olasılıkla** sayfadaki bağlantılardan birini rastgele izler.
- **$1 - \beta$ olasılıkla** URL kutusuna bir adres yazar ve istediği herhangi bir sayfaya atlar.

Bağlantı izleme olasılığı $\beta$ genellikle $0{,}8$ veya $0{,}9$'dur. URL yazma (ışınlanma) olasılığı da buna göre $0{,}2$ veya $0{,}1$'dir.

### 13.2 Örümcek Tuzağı İçin: Denklem Güncellenir

Eski akış formülünde $j$'nin puanını bulmak için $j$'ye işaret eden bütün düğümlerin puanını giden bağlantı sayılarına bölüp topluyorduk. Yeni formülde bu toplam $\beta$ ile çarpılır. Buna ikinci bir terim eklenir: Gezgin $1-\beta$ olasılıkla URL yazıp ağdaki herhangi bir sayfaya atlar. $N$ toplam sayfa sayısı olduğundan, bu yolla $j$'ye gelme olasılığı $(1-\beta)\cdot\frac1N$'dir. İkisi toplanınca $j$'nin PageRank puanı bulunur:

$$r_j = \sum_{i \to j} \beta \frac{r_i}{d_i} + (1-\beta)\frac{1}{N}$$

Hoca bunun örümcek tuzağı sorununu çözdüğünü söyledi.

<!-- BELİRSİZ: 02:17:29-02:17:59 arası altyazı "bu sorferin" tekrarına düşmüş; formülün ikinci teriminin anlatımının başı okunamıyor. -->

### 13.3 Çıkmaz Uç İçin: Matris Güncellenir

Çıkmaz uç sorunu da ışınlanma fikriyle çözülür. Çıkmaz uç düğümü için, gezgini o düğümden ağdaki her düğüme götüren sanal bağlantılar (virtual link) varsayılır. Örnekte toplam üç düğüm olduğu için m'nin sütunundaki her hücreye $1/3$ yazılır. Bu, gezgin çıkmaz uca geldiğinde graftaki herhangi bir düğüme atlayabileceği anlamına gelir.

$$M_{\text{düzeltilmiş}} = \begin{pmatrix} 1/2 & 1/2 & 1/3 \\ 1/2 & 0 & 1/3 \\ 0 & 1/2 & 1/3 \end{pmatrix}$$

Artık bu matris de stokastiktir: m'nin sütunu $1/3 + 1/3 + 1/3 = 1$ eder, diğer sütunların toplamı zaten 1'dir. Hesaplamada bu stokastik komşuluk matrisi kullanılır.

> **Ders sonrası not:** Hoca bu düzeltilmiş matrisle kuvvet yinelemesinin sonucunu derste vermedi. Python ile her düğüm $1/3$ ile başlatılınca yineleme $(r_y, r_a, r_m) = (6/13,\ 4/13,\ 3/13) \approx (0{,}462,\ 0{,}308,\ 0{,}231)$ değerine yakınsıyor. Bütün değerler sıfırdan farklı olduğu için düğümler artık ayırt edilebiliyor.

Hoca iki çözümün farkını vurguladı:

> **Hocanın vurgusu:** Örümcek tuzağı sorununu çözmek için **denklemi** güncelliyorum (ışınlanma terimini ekliyorum). Çıkmaz uç sorununu çözmek için **web grafını**, yani matrisi güncelliyorum (çıkmaz uç düğümlerine bu değerleri ekliyorum).

### 13.4 Soru: Neden $1/2$ Değil de $1/3$?

**Soru:** Çıkmaz uç sütununa neden $1/2$ değil de $1/3$ yazılıyor? **Cevap:** Amaç, bu düğümden graftaki her düğüme, **kendisi de dahil**, atlayabilmektir. URL kutusu fikrini düşünün: Ağdaki her sayfaya atlayabilirim, bu sayfa da dahil. Aynı URL'yi yeniden yazabilir veya kopyalayıp yapıştırabilirim, bu da bu sayfadan başlayıp yine bu sayfaya atlamak demektir. Bu sayfayı hariç tutarsanız, rastgele gezginin bu sayfaya bu yolla da gelebileceğini görmezden gelmiş olursunuz. Bu yüzden payda toplam düğüm sayısıdır, örnekte 3.

### 13.5 Matris Güncellemesinin Formülü

Hoca çıkmaz uç düzeltmesinin matris formülünü de gösterdi. Çıkmaz uçlu başlangıç matrisine bir matris eklenir:

$$M' = M + \frac{1}{N}\, e\, a^T$$

- $e$, bütün elemanları 1 olan bir vektördür.
- $a$, $i$ düğümü çıkmaz uç ise (giden bağlantısı 0 ise) $a_i = 1$, aksi halde $a_i = 0$ olan bir vektördür.

Bu çarpım $N \times N$ boyutlu bir matris verir. Bu matriste bütün sütunlar sıfırdır. Sıfırdan farklı tek sütun, çıkmaz uç sorunu olan düğümün sütunudur ve orada değerler $1/3$'tür. Bu matris başlangıç matrisine eklenince çıkmaz uç sorunu kalmaz.

<!-- BELİRSİZ: 02:27:36-02:27:46 arasında altyazı "This A is equal to 1 if not I has 0" diye geçiyor; bağlamdan "i düğümünün giden bağlantı sayısı 0 ise $a_i = 1$" anlamı çıkarıldı. -->

## 14. Google Matrisi

### 14.1 Teoremin Koşulları ve İki Çözüm

Hoca iki sorunun çözümünü Markov zinciri teoreminin koşullarıyla eşleştirdi:

- Matris **stokastik**tir: her sütun vektörünün toplamı 1'dir.
- **İndirgenemez**dir: hocanın anlatımına göre bu, çıkmaz uç sorunu olmaması demektir.
- **Periyodik olmayan**dır: hocanın anlatımına göre bu, örümcek tuzağı sorunu olmaması demektir.

Hoca, denklemi güncelleyerek periyodiklik sorununu, ışınlanmayı ekleyerek çıkmaz uç sorununu çözdüğünü ve grafı stokastik yaptığını söyledi. Bu değişiklikler uygulanınca elde edilen matris nihai Google formülünde kullanılabilir.

> **Ders sonrası not:** Hocanın "indirgenemez = çıkmaz uç yok, periyodik olmayan = örümcek tuzağı yok" eşleştirmesi kabaca bir sezgidir. Kitaptaki anlatıma göre çıkmaz uç asıl olarak matrisin **stokastikliğini** bozar (sütun toplamı 0 olur). Örümcek tuzağı ise her düğümden her düğüme ulaşılamamasına, yani **indirgenebilirliğe** yol açar; periyodiklik ayrı bir sorundur (örneğin $a \leftrightarrow b$ salınımı). Işınlanma terimi her düğümden her düğüme pozitif olasılıkla geçiş sağladığı için matrisi aynı anda hem indirgenemez hem periyodik olmayan yapar.

### 14.2 Google Matrisi Formülü

Akış formülü, atlama faktörü eklenerek güncellenmişti: Gezgin $\beta$ olasılıkla mevcut web'deki bağlantıları izler, $1-\beta$ olasılıkla ağdaki herhangi bir sayfaya atlar. Bu iki parça matris olarak toplanınca **Google matrisi (Google matrix)** elde edilir:

$$A = \beta M + (1-\beta)\left[\frac{1}{N}\right]_{N \times N}, \qquad r = A \cdot r$$

Burada $M$, sorunları olan web komşuluk matrisidir (çıkmaz uçlar varsa önce $1/N$ sütunlarıyla düzeltilmiş hali). $\left[\frac1N\right]_{N\times N}$ ise bütün elemanları $1/N$ olan matristir. Hoca bu adı, fikri ilk ortaya atanların Google'ın kurucuları olmasına bağladı.

Google matrisi stokastik, periyodik olmayan ve indirgenemez bir matristir. Hiçbir sorunu yoktur ve şimdiye kadar öğrendiğimiz kuvvet yinelemesi bu matrise uygulanabilir. Markov zinciri teoremine göre başlangıç olasılık dağılımı ne olursa olsun, belirli bir yinelemeden sonra olasılık dağılımı vektörü, başka bir deyişle sıralama vektörü, bir şeye yakınsar ve bu tek bir çözümdür.

### 14.3 Slayttaki $\beta = 0{,}8$ Örneği

Hoca son olarak bu formülün bir uygulamasını gösterdi. Slayttaki grafta yeşil çizilenler dışındaki her şey gerçek web grafıydı; yeşil olanlar ışınlanma bağlantılarıydı. Hoca önce komşuluk matrisini kurdu, sonra formüle göre $A$ matrisini hesapladı. Rastgele ışınlanma değeri $\beta = 0{,}8$ verilmişti: Gezgin $0{,}8$ olasılıkla bağlantıları izliyor, $0{,}2$ olasılıkla rastgele bir sayfaya atlıyordu. Elde edilen matrisle bir başlangıç sıralama vektöründen başlanır ve belirli bir yinelemeden sonra yineleme anlamlı bir sonuca yakınsar.

<!-- BELİRSİZ: 02:32:04-02:32:33 arası altyazı kopuk ("bu noktada"); slayttaki grafın yapısı, $A$ matrisinin değerleri ve yinelemelerin sayıları okunamıyor. -->

> **Ders sonrası not:** Slayttaki örnek büyük olasılıkla kitaptaki standart örnektir: m'nin kendine bağlandığı örümcek tuzaklı y, a, m grafı ve $\beta = 0{,}8$. Bu grafla formül uygulanınca (python ile doğrulandı):
>
> $$A = 0{,}8 \begin{pmatrix} 1/2 & 1/2 & 0 \\ 1/2 & 0 & 0 \\ 0 & 1/2 & 1 \end{pmatrix} + 0{,}2 \begin{pmatrix} 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \\ 1/3 & 1/3 & 1/3 \end{pmatrix} = \begin{pmatrix} 7/15 & 7/15 & 1/15 \\ 7/15 & 1/15 & 1/15 \\ 1/15 & 7/15 & 13/15 \end{pmatrix}$$
>
> Her sütunun toplamı 1'dir. $1/3$'lük başlangıç vektöründen yinelemeler $(1/3, 1/5, 7/15)$, $(7/25, 1/5, 13/25)$, ... diye ilerler ve $(r_y, r_a, r_m) = (7/33,\ 5/33,\ 21/33) \approx (0{,}212,\ 0{,}152,\ 0{,}636)$ değerine yakınsar. Aynı sonuç akış biçimindeki $r_j = \sum_{i\to j} \beta\, r_i/d_i + (1-\beta)/N$ formülüyle de bulunur. m hâlâ en yüksek puanı alır ama y ve a artık sıfır değildir. $\beta = 0{,}9$ ile sonuç yaklaşık $(0{,}139,\ 0{,}096,\ 0{,}765)$ olur: Işınlanma olasılığı azaldıkça tuzak daha çok puan toplar.

> **Ek bilgi (derste anlatılmadı):** Gerçek web ölçeğinde $A$ matrisi yoğun (dense) olduğu için doğrudan saklanmaz. Bunun yerine seyrek $M$ ile $r' = \beta M r + \frac{1-\beta}{N}$ hesaplanır; bu tam olarak yukarıdaki akış biçimidir. Çıkmaz uçlar varsa, sızan toplam puan her adımda yeniden eşit olarak dağıtılarak vektörün toplamı 1'de tutulur.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:47:30): Tarayıcıda URL kutusu ve geri tuşu yoksa ve ana sayfada dört bağlantı varsa, ana sayfadaki bir gezginin müfredat (syllabus) sayfasına gitme olasılığı nedir?

> **Çözüm:** Gezgin yalnızca bağlantılara tıklayarak ilerleyebilir ve dört seçeneği vardır. Her bağlantı eşit olasılıkla seçildiğinden olasılık $1/4$'tür. Bu, stokastik matristeki $1/d_i$ değerinin anlamıdır.

**Soru 2** (derste sözlü, 02:12:24): m düğümünün yalnızca kendine bağlandığı y, a, m grafında örümcek tuzağı sorunu var mı?

> **Çözüm:** Evet. Gezgin a'dan m'ye geçerse m'de takılır ve her adımda yine m'ye döner. Kuvvet yinelemesinde bütün puan m'de toplanır: $(r_y, r_a, r_m) \to (0, 0, 1)$.

**Soru 3** (derste sözlü, 02:23:37): Çıkmaz uç düğümünün sütununa neden $1/2$ değil de $1/3$ yazılır?

> **Çözüm:** Gezgin çıkmaz uçtan ağdaki her düğüme, kendisi de dahil, ışınlanabilir (aynı URL'yi yeniden yazmak gibi). Üç düğüm olduğu için her hücreye $1/N = 1/3$ yazılır.

## Dersin Toparlaması

Bu derste büyük verinin üçüncü türü olan graf verisine geçildi ve web grafı üzerinde bağlantı analiziyle sayfa sıralaması işlendi. Web aramasının iki zorluğu, yani hangi sayfaya güvenileceği ve sorguya en iyi cevabın hangisi olduğu, Google'ın popülerlik tabanlı sıralamasıyla birlikte çözülür. PageRank'in iki fikri vardır: Bağlantılar oy gibidir, ve önemli bir sayfadan gelen bağlantı daha ağırdır. Bu fikirler akış denklemi $r_j = \sum_{i\to j} r_i/d_i$ ile yazılır. Küçük graflarda toplamı 1 koşuluyla Gauss eliminasyonu yeterlidir, web ölçeğinde ise stokastik komşuluk matrisi $M$ kurulur ve $r = M r$ özdeğer sistemi kuvvet yinelemesiyle çözülür. Aynı denklem rastgele gezgin açısından bir durağan dağılımdır ve Markov zinciri teoremine göre matris stokastik, indirgenemez ve periyodik olmayan olduğunda tek bir çözüme yakınsar.

Gerçek web'de örümcek tuzakları puanı yutar, çıkmaz uçlar ise puanı sızdırır. Işınlanma iki sorunu da çözer: Örümcek tuzağı için denkleme $(1-\beta)/N$ terimi eklenir, çıkmaz uç için matristeki sıfır sütunlar $1/N$ ile doldurulur. Sonuçta elde edilen Google matrisi $A = \beta M + (1-\beta)[1/N]_{N\times N}$ üzerinde kuvvet yinelemesi uygulanır; $\beta$ tipik olarak $0{,}8$ veya $0{,}9$'dur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
