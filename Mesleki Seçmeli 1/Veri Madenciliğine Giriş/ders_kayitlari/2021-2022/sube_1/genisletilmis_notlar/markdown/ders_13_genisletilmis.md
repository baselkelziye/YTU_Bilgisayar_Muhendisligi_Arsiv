# Ders 13 Genişletilmiş Notu: Kümeleme: Temel Kavramlar, Uzaklık Ölçüleri ve K-Means

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

> **Kayıt hakkında:** Kaydın ilk yaklaşık 13 dakikası projeksiyon bağlantısı kurulurken geçer. Ders yaklaşık 56. dakikada araya girilerek kesilir; aradan sonra k-medoids ile devam edileceği söylenir, ancak kaydın geri kalanında ders sesi ve ekranı yoktur. Bu not yalnız aradan önceki birinci saati kapsar.

## İçindekiler

- 1. Kümeleme Nedir
- 2. Kümelemenin Kullanım Alanları
- 3. İyi Bir Kümeleme Nedir
- 4. Uzaklık Ölçüleri
- 5. Karışık Tipli Öznitelikler ve Eksik Değerler
- 6. Kümeleme Yaklaşımları
- 7. Bölümleme Algoritmaları ve K-Means
- 8. K-Means Sayısal Örneği
- 9. K-Means Kümelerini Değerlendirme: SSE
- Örnek Sorular

## 1. Kümeleme Nedir

Bu derste yeni bir slayt destesiyle, "Clustering" başlığıyla kümeleme konusuna geçildi (ekrandan, 00:10:00). Hoca konuya bir gözlemle başladı: mezunlara ya da mülakatlarda öğrencilere bu dersten ne hatırladıkları sorulduğunda neredeyse herkes "kümelemeyi (clustering) hatırlıyorum" diyor, ama kümeleme nedir diye sorulunca yüzde 80-90'ı sınıflandırmayı (classification) anlatmaya başlıyor. Hoca bunun nedenini bilmediğini, belki ismin daha tanıdık geldiğini, ama dersten en çok aklında kalan şeyin kümeleme olacağını söyledi. Clustering Türkçede kümeleme demektir.

Slayttaki tanımlar şöyledir (ekrandan, 00:15:00):

- **Küme (cluster):** veri nesnelerinden oluşan bir topluluk. Aynı kümedeki nesneler birbirine benzer; başka kümelerdeki nesnelere benzemez.
- **Küme analizi (cluster analysis):** bir veri nesneleri kümesini kümelere gruplama işi.
- **Kümeleme, gözetimsiz sınıflandırmadır (unsupervised classification):** önceden tanımlı sınıflar yoktur.

Veri nesnesi (data object), daha önceki derslerde olduğu gibi bir tablonun, yani bir veritabanının her bir satırına karşılık gelir. Sınıflandırmadan farklı olarak kümelemede elimizde etiketler (label) yoktur. Elimizde bir sürü örnek vardır ve bunları bir şekilde kümelere ayırmak isteriz.

Etiketleri bilmediğimiz için verinin içinde aslında kaç küme olduğunu da bilmeyiz. Bu yüzden "bunu iki kümeye ayır", "üç kümeye ayır" diye küme sayısını parametre olarak kullanıcı verir. Hoca, bu parametrenin de genellikle veri çok iyi bilindiği ya da gözlemlendiği için verilmediğini, yani çoğu zaman tam bilinmeden seçildiğini vurguladı.

Nesneleri neye göre ayırırız? Genellikle benzer nesnelerin aynı kümede olması istenir. Benzerlik de kümelemede genellikle uzaklık fonksiyonlarıyla ölçülür.

Hoca, şimdiye kadar görülen her şeyin sınıflandırma olduğunu hatırlattı: etiketler vardı, "yes/no" bulunmaya ya da nesneler üst sınıflara ayrılmaya çalışılıyordu. Kümelemede ise etiket yoktur. Bu yüzden sınıflandırma gözetimli (supervised), kümeleme gözetimsiz (unsupervised) bir yöntemdir.

## 2. Kümelemenin Kullanım Alanları

Slayttaki iki tipik kullanım şunlardır (ekrandan, 00:15:00): verinin dağılımını anlamak için tek başına bir araç olarak (stand-alone tool) ve başka algoritmalar için bir ön işleme adımı (preprocessing step) olarak.

Hocanın verdiği örnekler:

- **Bilgisayarlı görü:** bir resmi bölgelere ayırmak (segmentasyon) gerektiğinde, örneğin "burası çimenlik, burası gökyüzü" demek için, ilk başta hızlı bir kümeleme yapılır. Bu tek başına çok iyi sonuç vermez, ama süperpiksel denen küçük bölgeleri üretmekte kullanılır; bu, slayttaki "başka algoritmalar için ön işleme adımı" kullanımına örnektir.
- **Pazarlama ve müşteri segmentasyonu:** firmalar müşteri bilgilerini toplamıştır ama her müşteri için bir etiket yoktur. "Müşterilerimi segmentlere ayır" denildiğinde hangi segmentte hangi tip müşterilerin olduğu kümelemeyle bulunur.
- **Arazi kullanımı (land use):** uydudan çekilen görüntülerde kümeleme yapılarak farklı alanlar ayrılır; burası tarım alanı, burası orman gibi.
- **Sigorta:** bu da bir tür müşteri segmentasyonudur; sigortasından çok harcama yapanlar, az harcama yapanlar gibi gruplar bulunur.
- Sismolojiye kadar çok farklı alanlarda kullanılır.

## 3. İyi Bir Kümeleme Nedir

Sınıflandırmada elimizde etiketler vardı; bu yüzden doğruluk (accuracy), kesinlik (precision) gibi pek çok ölçü hesaplanabiliyordu. Kümelemede etiket yoktur. Hoca bunu şöyle sordu: "Ben size bu veriyi kümelere ayırın desem ve her biriniz ayrı ayrı ayırsanız, hanginizin kümelemesinin daha iyi, hangisinin daha doğru olduğunu nereden bileceğim?"

Genel kanı şudur (ekrandan, 00:20:00): iyi bir kümeleme yöntemi şu özelliklerde kümeler üretir:

- **Küme içi benzerlik (intra-class similarity) yüksek:** kümenin içindeki nesneler birbirine benzer, kümeler kendi içinde sıkıdır (cohesive).
- **Kümeler arası benzerlik (inter-class similarity) düşük:** kümeler birbirinden belirgin biçimde ayrılır (distinctive).

Benzerlik ile uzaklık ters anlamda kullanılabilir ve kullanılır. İki farklı kümeye bakıldığında kümeler arası benzerliğin düşük, yani aralarındaki uzaklığın yüksek olması istenir.

Slayt ayrıca şunları söyler: kümeleme kalitesinin kesin bir tanımını yapmak zordur; uygulamaya bağlıdır ve sonuçta özneldir. Bir kümeleme yönteminin kalitesi, yöntemin kullandığı benzerlik ölçüsüne ve gizli (hidden) örüntülerin bir kısmını ya da tamamını bulabilme yeteneğine bağlıdır. Benzerlik bir uzaklık fonksiyonu $d(i,j)$ ile ifade edilir; uzaklık fonksiyonlarının tanımları nominal, ikili (binary), sıralı (ordinal) ve sayısal öznitelikler için oldukça farklıdır.

Hoca, ilk konularda Minkowski, Öklid, Manhattan, ki-kare gibi uzaklık ölçülerinin görüldüğünü hatırlattı. Kullanılan ölçüye göre "iyi" denilen kümeleme de değişir. $d(i,j)$, $i$ ve $j$ nesneleri arasındaki uzaklık fonksiyonudur.

### 3.1 Aynı Veri, Farklı Küme Sayıları

Slayttaki örnekte yukarıda siyah noktalardan oluşan tek bir veri vardır. Aşağıda aynı noktalar bir kez iki kümeye (kırmızılar ve maviler), bir kez dört kümeye, bir kez de altı kümeye (maviler, yıldız şeklindekiler, morlar, kırmızılar, sarılar gibi) ayrılmıştır. Veri nesnelerinin hepsi aynıdır; değişen yalnız küme sayısıdır.

Hoca bu örneğin şu açıdan güzel olduğunu söyledi: kümelemede kaç küme olacağı parametresini kullanıcı verir. Dörde mi, ikiye mi ayırmak daha iyidir? Bu genellikle deneysel (empirik) olarak denenir; her seçenek için küme içi ve kümeler arası benzerliğe bakılır ve hangisi daha iyi çıkıyorsa parametre o seçilir. Bunun için her kümenin içindeki ortalama uzaklık ve kümeler arasındaki ortalama uzaklık hesaplanmalıdır. Yalnız şekle bakıp "bu daha iyi kümeleme" denemez; sayısal olarak bakmak gerekir.

## 4. Uzaklık Ölçüleri

### 4.1 Uzaklık Ölçüsünün Özellikleri

Bir uzaklık ölçüsü $d(i,j)$ şu özellikleri sağlar (ekrandan, 00:25:00):

- $d(i,j) \ge 0$
- $d(i,i) = 0$
- $d(i,j) = d(j,i)$
- $d(i,j) \le d(i,k) + d(k,j)$

Birinci özellik, uzaklığın negatif olamayacağını söyler: uzaklık formüllerinde ya mutlak değer ya da kare vardır, bütün uzaklıklar sıfır ya da pozitiftir. Simetri özelliği, iki nesne arasındaki uzaklığın $i$'den $j$'ye de $j$'den $i$'ye de aynı olduğunu söyler. Sonuncusu üçgen eşitsizliğidir: $i$'den $k$'ya ve $k$'dan $j$'ye uzaklıkların toplamı, $i$ ile $j$ arasındaki uzaklıktan küçük olamaz.

### 4.2 Sayısal Öznitelikler: Minkowski, Manhattan, Öklid

En genel biçim Minkowski uzaklığıdır. Formüldeki parametre 1 olursa Manhattan uzaklığı, 2 olursa Öklid uzaklığı elde edilir. Sayısal (numeric) değerlerde en çok kullanılan uzaklıklar bunlardır.

<!-- BELİRSİZ: Minkowski slaytının karesi yok; aşağıdaki formül derste hatırlatılan genel biçimin standart yazımıdır, parametre adı slayttan doğrulanamadı. -->

$$d(i,j) = \left( \sum_{f=1}^{p} |x_{if} - x_{jf}|^{q} \right)^{1/q}$$

### 4.3 İkili Öznitelikler

İkili (binary) öznitelikler 0 ya da 1 değerini alır. Daha önce ikili öznitelikler ikiye ayrılmıştı:

- **Simetrik ikili:** 1, 0'dan daha üstün değildir; iki değer eşit önemdedir. Örneğin cinsiyet (kadın, erkek).
- **Asimetrik ikili:** "var/yok" gibidir; 1, 0'dan daha fazla bir şeyi ifade eder, iki değer eşit ağırlıkta değildir.

İki nesne $i$ ve $j$ için şu sayılar tanımlanır: ikisinin de 1 olduğu öznitelik sayısı $a$; $i$ 1 iken $j$ 0 olanlar $b$; $i$ 0 iken $j$ 1 olanlar $c$; ikisinin de 0 olduğu öznitelik sayısı $d$.

<!-- BELİRSİZ: İkili öznitelik slaytının karesi yok; formüller altyazıdaki anlatımdan yazıldı. -->

Simetrik ikili öznitelikler için uzaklık, uyuşmayanların bütün özniteliklere oranıdır:

$$d(i,j) = \frac{b + c}{a + b + c + d}$$

Hoca mantığı şöyle açıkladı: uzaklık ölçüyoruz; iki nesnenin bütün değerleri aynı olsaydı (birler bir, sıfırlar sıfır) aradaki uzaklığın sıfır çıkması gerekirdi. Uzaklık yalnız biri 1 iken diğeri 0 olan durumlardan, yani $b$ ve $c$'den gelir.

Asimetrik ikili özniteliklerde pay yine $b + c$'dir, ama payda $a + b + c$ olur; ikisinin de 0 olduğu $d$ paydaya katılmaz:

$$d(i,j) = \frac{b + c}{a + b + c}$$

Neden $d$ katılmaz? Asimetrik öznitelikte 1, 0'dan daha anlamlıdır; iki nesnenin ikisinde de "yok" olması onları gerçekten benzer yapmaz. $d$'nin paydadan çıkarılması, ortak sıfırların ağırlığını azaltmak gibi düşünülebilir.

### 4.4 Nominal Öznitelikler

Nominal öznitelikler kategorik değerlerdir. Slayttaki basit eşleşme (simple matching) uzaklığı şöyledir (ekrandan, 00:30:00):

$$d(i,j) = \frac{p - m}{p}$$

Burada $m$, değeri eşleşen nominal öznitelik sayısı; $p$, toplam nominal öznitelik sayısıdır. $p - m$ eşleşmeyenlerin sayısıdır; uzaklık "eşleşmeyenler bölü hepsi" olarak hesaplanır. Slaytta ayrıca bir nominal özniteliğin her değeri için bir ikili öznitelik kullanılabileceği de yazar.

### 4.5 Sıralı Öznitelikler

Sıralı (ordinal) özniteliklerde değerler küçük, orta, büyük gibi bir sıra izler. Değerler sırasına göre 1, 2, 3, ... sayılarıyla değiştirilir ve sayısal değer gibi ele alınır (ekrandan, 00:30:00). Ardından Öklid, Manhattan ya da hangi uzaklık kullanılıyorsa o uygulanır.

## 5. Karışık Tipli Öznitelikler ve Eksik Değerler

Gerçek veride öznitelikler genellikle tek tipte olmaz: aynı veride kategorik, sayısal ve ikili öznitelikler bir arada bulunur. Nesneler arasındaki uzaklığı ölçebilmek için farklı tipteki özniteliklerin uzaklıklarından tek bir uzaklık hesaplamak gerekir.

### 5.1 Eksik Değerler Neden Doldurulmuyor

Bir başka sorun eksik (missing) değerlerdir: iki nesne arasındaki uzaklık hesaplanırken birinde bir öznitelik eksik olabilir. Daha önce eksik değerleri doldurma ve tahmin etme yöntemleri görülmüştü. Hoca, kümelemede bunun önerilmediğini açıkladı. Sınıflandırmada eksik değeri tahmin etmek biraz daha mantıklı olabilir, çünkü etiketler bilindiği için o etiketin o öznitelikteki genel davranışı tahmin edilebilir. Kümelemede ise eksik değerleri önceden doldurmak (ön işleme yapmak) nesnelerin yerini değiştirebilir ve kümeleri bozabilir. Bu yüzden kümelemede eksik değer tahmin edilmez; bunun yerine kümeleme yöntemi eksik değerle çalışacak hale getirilir.

### 5.2 Birleşik Uzaklık Formülü

Slayttaki formül şöyledir (ekrandan, 00:35:00). Önce bütün öznitelikler ortak bir ölçeğe, $[0{,}0;\ 1{,}0]$ aralığına getirilir. Nesnelerin $p$ tane karışık tipli özniteliği varsa iki nesne arasındaki uzaklık:

$$d(i,j) = \frac{\sum_{k=1}^{p} \delta_{ij}^{k}\, d_{ij}^{k}}{\sum_{k=1}^{p} \delta_{ij}^{k}}$$

Her öznitelik için $i$ ile $j$ arasındaki uzaklık $d_{ij}^{k}$, bir $\delta_{ij}^{k}$ katsayısıyla çarpılıp toplanır; normalize etmek için de toplam $\delta$'ya bölünür. Böylece ortalama bir uzaklık elde edilir.

$\delta_{ij}^{k}$ şöyle belirlenir:

- $k$. öznitelikte eksik değer varsa $\delta_{ij}^{k} = 0$. Bu öznitelik uzaklık hesabına hiç katılmaz (sıfırla çarpılmış olur).
- $k$. öznitelik asimetrik ikili ise ve iki nesnede de değeri 0 ise $\delta_{ij}^{k} = 0$. Hoca bunu önemli diye işaretledi: iki nesnenin ikisinde de 0 olması uzaklığı sıfır çıkarır ve onları yapay olarak benzer gösterir; bu etkiyi kaldırmak için $\delta$ sıfırlanır. Bu, asimetrik ikili uzaklıkta $d$'nin paydaya katılmamasıyla aynı mantıktır.
- Aksi halde $\delta_{ij}^{k} = 1$.

$d_{ij}^{k}$ öznitelik tipine göre hesaplanır:

- Sayısal öznitelikte: $d_{ij}^{k} = \dfrac{|x_{ik} - x_{jk}|}{\max_k - \min_k}$
- Kategorik öznitelikte: $d_{ij}^{k}$ 0 ya da 1'dir.

Hoca $[0, 1]$ aralığına normalizasyonun neden şart olduğunu bir örnekle anlattı. Üç değerli bir kategorik öznitelik varsa en büyük uzaklık küçük bir sayıdır. Ama 1 ile 1 milyon arasında değişen sayısal bir öznitelik varsa, o öznitelikteki fark 1 milyon mertebesinde olabilir. Bu durumda $d(i,j)$ hesaplanırken o büyük değer diğer bütün öznitelikleri bastırır. Bütün uzaklıklar $[0, 1]$ aralığına normalize edilerek bundan kurtulunur.

> **Ek bilgi (derste anlatılmadı):** Bu birleşik uzaklık, literatürde Gower uzaklığı adıyla bilinen ölçünün bir biçimidir. Sayısal öznitelikteki $\max_k - \min_k$, o özniteliğin veri kümesindeki değer aralığıdır; bölme sayesinde her özniteliğin katkısı en fazla 1 olur.

## 6. Kümeleme Yaklaşımları

Kümeleme yöntemleri dört ana yaklaşıma ayrılır:

- **Bölümleme (partitioning):** en çok kullanılan yaklaşımdır. Belli bir ölçüte göre veri, birbiriyle kesişmeyen (overlap olmayan) kümelere ayrılır. En çok kullanılanları k-means ve k-medoids yöntemleridir.
- **Hiyerarşik:** kümeler düzey düzey oluşur; ağaç gibi düşünülür. Örneğin 2. seviyedeki bir düğümün bir alt seviyede iki çocuğu varsa, alt seviyeden bakıldığında bu iki çocuk ayrı kümelerdir, bir üst seviyeden bakıldığında ise birleşip tek küme olur. Slayttaki tanımı: hiyerarşik bir ağaç olarak düzenlenmiş iç içe kümeler (nested clusters).
- **Yoğunluk tabanlı (density-based):** bir yoğunluk tanımına dayanır. DBSCAN algoritması bu gruptadır; hoca bazı durumlarda çok iyi çalıştığını, bazılarında çalışmadığını söyledi.
- **Graf tabanlı (graph-based):** bunların yalnız ne olduğu gösterilecek.

Derste bu dört yaklaşımın içindeki algoritmalara bakılacağı söylendi.

## 7. Bölümleme Algoritmaları ve K-Means

### 7.1 Bölümleme Algoritmalarının Genel Yapısı

$D$ veritabanının (tablonun) adıdır ve içinde $n$ tane nesne vardır. Bölümleme algoritması bunları $k$ kümeye (a set of $k$ clusters) ayırır. $D$ ve $n$ zaten veriyle gelir; ek parametre olarak $k$, yani küme sayısı, kullanıcı tarafından verilir.

Bölümleme yöntemleri sezgiseldir (heuristic) ve yinelemelidir: nesnelerin hangi kümeye ait olduğu adım adım yeniden hesaplanarak sonunda kümeler bulunur. Sonuç, başlangıçta kümelerin yerlerinin nasıl seçildiğine göre değişebilir. Genellikle iyi bir çözüm bulmaya çalışırlar.

İki önemli yöntem vardır:

- **K-means:** her küme, kümenin merkeziyle temsil edilir. İki boyutta düşünülürse merkez, o kümedeki bütün nesnelerin $x$ değerlerinin toplamının ve $y$ değerlerinin toplamının nesne sayısına bölümüdür, yani ortalamadır.
- **K-medoids:** her küme, kümedeki gerçek bir nesneyle, kümenin merkezine yakın bir nesneyle temsil edilir. Bu yöntem aradan sonraya bırakıldı.

### 7.2 K-Means Algoritması

Slayttaki algoritma şöyledir (ekrandan, 00:40:00):

```text
Girdi : k  -> küme sayısı
        D  -> n eleman içeren veri kümesi
Çıktı : k kümeden oluşan bir küme

(1) D'den rastgele k eleman seç; bunlar başlangıç küme ortalamaları olsun
(2) tekrarla
(3)   her elemanı, küme ortalaması kendisine en yakın olan kümeye ata
(4)   bütün elemanlar atanınca gerçek yeni küme ortalamalarını hesapla
(5) yeni ve eski küme ortalamaları arasında değişiklik olmayana kadar
```

Rastgele seçilen $k$ eleman ilk kümelerin merkezi olur. Döngüde her elemana bakılır: $k$ merkezden hangisine daha yakın? Hangisine yakınsa o kümeye atanır. Bütün elemanlar atanınca yeni merkezler hesaplanır. Merkez değiştiği için uzaklıklar bu yeni merkezlere göre tekrar tekrar hesaplanır.

Hoca tahtada da bir çizimle anlattı: bir grup nesne vardır; rastgele iki tanesi küme merkezi seçilir. Sonra her nesne için "bu hangisine daha yakın?" diye bakılır ve nesne o kümeye atanır. Kümeler böyle oluştuktan sonra yeni merkezler hesaplanır ve süreç yinelenir.

### 7.3 Görsel Örnek

Slayttaki dört panelli şekil bu süreci gösterir (ekrandan, 00:45:00). Hoca, şekilde noktaların mavi ve açık mavi olarak verildiğini, bunun biraz kafa karıştırdığını belirtti: başlangıçta bütün noktalar aslında aynı renktedir. $k = 2$ olduğu için rastgele iki nokta merkez seçilir. Her nokta için "ilk seçilen noktaya mı, ikinciye mi daha yakın?" diye bakılır ve nokta yakın olduğu kümeye atanır; böylece iki küme oluşur. Bu birinci turun sonudur.

Sonra başta rastgele belirlenen iki merkez değiştirilir: her kümenin ortalaması yeni merkez olur. Şekilde bu yeni merkezler kırmızı noktalarla gösterilmiştir. Bu yinelemede her nokta yeniden bu kırmızı merkezlere göre atanır; bazı noktalar diğer merkeze daha yakın olduğu için küme değiştirir. Sonra tekrar her kümenin ortalaması alınarak yeni merkezler bulunur ve aynı soru sorulur.

### 7.4 Durma Koşulu

Veri doğru kümelere ayrılabildiyse bir noktadan sonra merkezler değişmez; algoritma bir şekilde kararlı hale gelir ve durur. Hoca, çok büyük verilerde buna güvenilmemesini, "şu kadar yinelemeden sonra dur" gibi bir sınır koymanın faydalı olacağını söyledi.

> **Hocanın vurgusu:** Çok büyük verilerde k-means'in merkezlerin sabitlenmesiyle kendiliğinden durmasına güvenmeyin; bir en fazla yineleme sayısı koyun.

## 8. K-Means Sayısal Örneği

Slayttaki soru şudur (ekrandan, 00:50:00): aşağıdaki veri noktaları için k-means algoritmasının iki yinelemesini gösterin. $k = 2$ ve başlangıç küme ortalamaları $(1,1)$ ve $(2,3)$ olsun. Her yinelemeden sonra küme ortalamalarını ve küme içeriklerini verin. Manhattan uzaklığını kullanın.

Noktalar: $(0,2)$, $(1,1)$, $(2,0)$, $(1,3)$, $(2,3)$, $(4,4)$, $(5,6)$.

Noktalar iki boyutlu ve sayısaldır; kolay hesaplansın diye kategorik öznitelik yoktur. Manhattan uzaklığı, Minkowski parametresinin 1 olduğu durumdur: farkların mutlak değerleri doğrudan toplanır, kare alınmaz:

$$d\big((x_1,y_1),(x_2,y_2)\big) = |x_1 - x_2| + |y_1 - y_2|$$

### 8.1 Birinci Yineleme

Merkezler $m_1 = (1,1)$ ve $m_2 = (2,3)$'tür. Her nokta için iki merkeze uzaklık hesaplanır:

| Nokta | $(1,1)$'e uzaklık | $(2,3)$'e uzaklık | Küme |
|---|---|---|---|
| (0,2) | 1 + 1 = 2 | 2 + 1 = 3 | 1 |
| (1,1) | 0 | 1 + 2 = 3 | 1 |
| (2,0) | 1 + 1 = 2 | 0 + 3 = 3 | 1 |
| (1,3) | 0 + 2 = 2 | 1 + 0 = 1 | 2 |
| (2,3) | 1 + 2 = 3 | 0 | 2 |
| (4,4) | 3 + 3 = 6 | 2 + 1 = 3 | 2 |
| (5,6) | 4 + 5 = 9 | 3 + 3 = 6 | 2 |

Hoca slaytta her noktanın yanına yakın olduğu merkezi yazdı: ilk üç nokta $(1,1)$'e, son dört nokta $(2,3)$'e (ekrandan, 00:50:00). $(1,1)$ noktası zaten birinci merkezin kendisidir; $(2,3)$ de ikinci merkezin kendisidir.

Birinci yineleme sonunda:

- $C_1 = \{(0,2), (1,1), (2,0)\}$. Yeni merkez: $x = (0 + 1 + 2)/3 = 1$, $y = (2 + 1 + 0)/3 = 1$, yani $(1,1)$. Merkez değişmedi.
- $C_2 = \{(1,3), (2,3), (4,4), (5,6)\}$. Yeni merkez: $x = (1 + 2 + 4 + 5)/4 = 12/4 = 3$, $y = (3 + 3 + 4 + 6)/4 = 16/4 = 4$, yani $(3,4)$.

### 8.2 İkinci Yineleme

Merkezler artık $m_1 = (1,1)$ ve $m_2 = (3,4)$'tür (hocanın slayta yazdığı yeni merkezler, ekrandan, 00:50:00).

| Nokta | $(1,1)$'e uzaklık | $(3,4)$'e uzaklık | Küme |
|---|---|---|---|
| (0,2) | 2 | 3 + 2 = 5 | 1 |
| (1,1) | 0 | 2 + 3 = 5 | 1 |
| (2,0) | 2 | 1 + 4 = 5 | 1 |
| (1,3) | 0 + 2 = 2 | 2 + 1 = 3 | 1 |
| (2,3) | 1 + 2 = 3 | 1 + 1 = 2 | 2 |
| (4,4) | 6 | 1 + 0 = 1 | 2 |
| (5,6) | 9 | 2 + 2 = 4 | 2 |

Burada bir değişiklik olur: $(1,3)$ noktası birinci yinelemede ikinci kümedeyken artık $(1,1)$'e daha yakındır ve birinci kümeye geçer.

İkinci yineleme sonunda ilk dört nokta birinci, son üç nokta ikinci kümededir:

- $C_1 = \{(0,2), (1,1), (2,0), (1,3)\}$. Yeni merkez: $x = (0 + 1 + 2 + 1)/4 = 4/4 = 1$, $y = (2 + 1 + 0 + 3)/4 = 6/4 = 1{,}5$, yani $(1;\ 1{,}5)$.
- $C_2 = \{(2,3), (4,4), (5,6)\}$. Yeni merkez: $x = (2 + 4 + 5)/3 = 11/3$, $y = (3 + 4 + 6)/3 = 13/3$, yani $(11/3;\ 13/3)$.

Hoca ardından slayttaki çözümü de gösterdi: birinci yinelemede küme 1 ve küme 2'nin içerikleri, merkezlerin $(1,1)$ ve $(3,4)$ bulunması; ikinci yinelemede birinci kümede dört, ikinci kümede üç nokta olması ve yeni merkezler. Soru iki yineleme istediği için slaytta üçüncü yineleme yapılmamıştır. Üçüncü yinelemede noktalar yeni merkezlere göre tekrar atanır; merkezler artık değişmiyorsa algoritma durur. Bütün değerler python ile doğrulandı.

> **Ders sonrası not:** Hoca üçüncü yinelemede kümelerin büyük olasılıkla değişmeyeceğini ve algoritmanın orada sona ereceğini söyledi. Python ile yapılan kontrolde kümeler değişiyor: $(2,3)$ noktasının $(1;\ 1{,}5)$ merkezine uzaklığı $1 + 1{,}5 = 2{,}5$, $(11/3;\ 13/3)$ merkezine uzaklığı $5/3 + 4/3 = 3$'tür; nokta birinci kümeye geçer. Üçüncü yineleme sonunda $C_1 = \{(0,2),(1,1),(2,0),(1,3),(2,3)\}$, merkez $(6/5;\ 9/5) = (1{,}2;\ 1{,}8)$; $C_2 = \{(4,4),(5,6)\}$, merkez $(4{,}5;\ 5)$ olur. Dördüncü yinelemede hiçbir nokta küme değiştirmez ve algoritma durur.

### 8.3 Tek Boyutlu Sezgi

Hoca, k-means'in mantığının tek boyutta düşünülerek de anlaşılabileceğini söyledi. Veri ikiye bölünür, yeni merkezler hesaplanır; merkezlere göre aradaki sınır kayar, bazı noktalar diğer tarafa geçer. Sonra yine yeni merkez hesaplanır. Böyle böyle veri ayrılmaya çalışılır. Başlangıçta ayrılır, ortası bulunur, noktalar en yakın ortaya atanır; algoritmanın özü budur.

## 9. K-Means Kümelerini Değerlendirme: SSE

Kümeleri bulduktan sonra "kümelemem ne kadar iyi çalışıyor" sorusuna nasıl cevap verilir? Hoca önce şunu sordu: en mükemmel kümelemede nasıl bir şey çıkmasını beklersiniz? Aslında bir kümedeki bütün noktaların uzayda aynı yerde olması beklenir; ama bu imkansızdır.

Bu yüzden en yaygın ölçü karesel hata toplamıdır (Sum of Squared Error, SSE) (ekrandan, 00:55:00). Her nokta (her veri nesnesi) için hata, en yakın küme ortalamasına olan uzaklıktır. SSE'yi bulmak için bu hataların kareleri alınıp toplanır:

$$SSE = \sum_{i=1}^{K} \sum_{x \in C_i} \text{dist}^2(m_i, x)$$

Burada $x$, $C_i$ kümesindeki bir veri noktası; $m_i$ ise $C_i$ kümesinin temsilci noktasıdır ve kümenin merkezine (ortalamasına) karşılık gelir.

K-means algoritması, merkezleri sürekli yeniden hesaplayıp her elemanı en yakın merkezin kümesine atayarak aslında bütün kümelerdeki bütün elemanlar için bu karesel hatayı en aza indirmeye çalışır. Yani herkes kendisine en yakın merkezin kümesine ait olsun diye uğraşılır.

> **Ek bilgi (derste anlatılmadı):** Atama adımında her nokta en yakın merkeze gittiği için SSE artmaz; güncelleme adımında da ortalama, bir kümedeki karesel uzaklık toplamını en küçük yapan nokta olduğu için SSE yine artmaz. Bu yüzden k-means sonlu adımda durur, ama bulduğu çözüm başlangıç merkezlerine bağlı olan bir yerel en iyi olabilir.

Bu noktada derse ara verildi; aradan sonra k-medoids yöntemine geçileceği söylendi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00): Aşağıdaki veri noktaları için k-means kümeleme algoritmasının iki yinelemesini gösterin. $k = 2$ ve başlangıç küme ortalamaları $(1,1)$ ve $(2,3)$ olsun. Her yinelemeden sonra küme ortalamalarını ve küme içeriklerini verin. Manhattan uzaklığını kullanın. Noktalar: $(0,2)$, $(1,1)$, $(2,0)$, $(1,3)$, $(2,3)$, $(4,4)$, $(5,6)$.

> **Çözüm (derste verildi, python ile doğrulandı):** 1. yineleme: $C_1 = \{(0,2),(1,1),(2,0)\}$, merkez $(1,1)$; $C_2 = \{(1,3),(2,3),(4,4),(5,6)\}$, merkez $(3,4)$. 2. yineleme: $(1,3)$ birinci kümeye geçer. $C_1 = \{(0,2),(1,1),(2,0),(1,3)\}$, merkez $(1;\ 1{,}5)$; $C_2 = \{(2,3),(4,4),(5,6)\}$, merkez $(11/3;\ 13/3)$. Ayrıntılı uzaklık tabloları Bölüm 8'dedir.

**Soru 2** (derste sözlü, 00:22:26): Slayttaki aynı siyah noktalar iki, dört ve altı kümeye ayrılmıştır. Hangisinin daha iyi kümeleme olduğuna nasıl karar verilir?

> **Cevap (derste verildi):** Şekle bakarak karar verilemez. Her seçenek için küme içi ortalama uzaklık ve kümeler arası ortalama uzaklık sayısal olarak hesaplanır; küme içi benzerliği yüksek, kümeler arası benzerliği düşük olan seçenek tercih edilir. Küme sayısı bu şekilde deneysel olarak seçilir.

**Soru 3** (derste sözlü, 00:53:36): Bir kümelemenin ne kadar iyi olduğunu sayısal olarak nasıl ifade edersiniz?

> **Cevap (derste verildi):** En yaygın ölçü SSE'dir: her noktanın kendi (en yakın) küme merkezine uzaklığının karesi alınır ve bütün noktalar için toplanır. K-means bu değeri en aza indirmeye çalışır.

## Dersin Toparlaması

Bu derste gözetimsiz öğrenmenin temel yöntemi olan kümelemeye giriş yapıldı. Kümelemenin sınıflandırmadan farkı, etiketlerin ve dolayısıyla küme sayısının bilinmemesidir; küme sayısı $k$ kullanıcı tarafından verilir ve deneysel olarak seçilir. İyi bir kümeleme küme içinde yüksek, kümeler arasında düşük benzerlik ister; benzerlik uzaklık fonksiyonlarıyla ölçülür. Sayısal (Minkowski, Manhattan, Öklid), ikili (simetrik ve asimetrik), nominal (basit eşleşme) ve sıralı öznitelikler için uzaklıklar hatırlatıldı; karışık tipli verilerde öznitelik uzaklıkları $[0, 1]$ aralığına normalize edilip $\delta$ katsayılarıyla ağırlıklı ortalaması alınır, eksik değerler ise doldurulmak yerine hesaptan çıkarılır.

Kümeleme yaklaşımları bölümleme, hiyerarşik, yoğunluk tabanlı ve graf tabanlı olarak sınıflandırıldı. Bölümleme yöntemlerinden k-means algoritması adımlarıyla, görsel bir örnekle ve Manhattan uzaklığıyla yapılan sayısal bir örnekle işlendi; algoritmanın karesel hata toplamını (SSE) en aza indirmeye çalıştığı gösterildi. Aradan sonra, kümeleri gerçek bir nesneyle temsil eden k-medoids yöntemine geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
