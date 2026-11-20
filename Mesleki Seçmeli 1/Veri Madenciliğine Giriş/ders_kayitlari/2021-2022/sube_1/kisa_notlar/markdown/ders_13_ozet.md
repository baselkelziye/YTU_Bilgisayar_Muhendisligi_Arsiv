# Ders 13 Çalışma Özeti

## Genel Konular

- Kümeleme (clustering) nedir
  - Yeni slayt destesi "Clustering" ile kümeleme konusuna geçildi (ekrandan, 00:10:00).
  - Küme (cluster), veri nesnelerinden oluşan bir topluluktur: aynı kümedeki nesneler birbirine benzer, başka kümelerdeki nesnelere benzemez (ekrandan, 00:15:00).
  - Küme analizi (cluster analysis), bir veri nesneleri kümesini kümelere ayırma işidir. Veri nesnesi, bir tablodaki (veritabanındaki) her bir satıra karşılık gelir.
  - Sınıflandırmadan farkı: elde etiket (label) yoktur, önceden tanımlı sınıf yoktur. Bu yüzden sınıflandırma gözetimli (supervised), kümeleme gözetimsiz (unsupervised) bir yöntemdir.
  - Etiket bilinmediği için kaç küme olduğu da bilinmez. Küme sayısı kullanıcı tarafından parametre olarak verilir ve genellikle kesin bilinerek değil, denenerek seçilir.
  - Benzer nesnelerin aynı kümeye düşmesi istenir. Benzerlik kümelemede genellikle uzaklık fonksiyonlarıyla ölçülür.
- Kullanım alanları
  - Tek başına bir araç olarak verinin dağılımını anlamak; başka algoritmalar için bir ön işleme adımı olmak (ekrandan, 00:15:00).
  - Bilgisayarlı görüde görüntüyü bölgelere ayırma (çimen, gökyüzü gibi), süperpiksel üretimi.
  - Pazarlamada müşteri segmentasyonu: müşteri verisi toplanmış ama her müşterinin etiketi yoktur.
  - Uydu görüntülerinde arazi kullanımı (tarım alanı, orman gibi bölgeleri ayırma).
  - Sigortada harcama davranışına göre müşteri gruplama; sismoloji gibi başka alanlar.
- İyi bir kümeleme nedir
  - Etiket olmadığı için doğruluk (accuracy), kesinlik (precision) gibi ölçüler hesaplanamaz; kimin kümelemesinin daha iyi olduğunu söylemek zordur.
  - İyi kümeleme: küme içi benzerlik (intra-class similarity) yüksek, kümeler arası benzerlik (inter-class similarity) düşük olmalıdır (ekrandan, 00:20:00).
  - Kalitenin kesin tanımı zordur: uygulamaya bağlıdır ve sonuçta özneldir. Kalite, kullanılan benzerlik ölçüsüne ve gizli örüntüleri bulabilme yeteneğine bağlıdır.
  - Benzerlik bir uzaklık fonksiyonu $d(i,j)$ ile ifade edilir. Nominal, ikili (binary), sıralı (ordinal) ve sayısal öznitelikler için farklı uzaklık fonksiyonları vardır.
  - Benzerlik ile uzaklık ters anlamda kullanılır: kümeler arası benzerlik düşük, yani uzaklık yüksek olmalıdır.
- Aynı veri, farklı küme sayıları
  - Slayttaki örnekte aynı siyah noktalar iki, dört ve altı kümeye ayrılmıştır. Küme sayısı parametre olduğundan hangisinin daha iyi olduğu deneysel olarak, küme içi ve kümeler arası ortalama uzaklıklar hesaplanarak seçilir; göz kararı söylenemez.
- Uzaklık ölçüsünün özellikleri (ekrandan, 00:25:00)
  - $d(i,j) \ge 0$, $d(i,i) = 0$, $d(i,j) = d(j,i)$, $d(i,j) \le d(i,k) + d(k,j)$ (üçgen eşitsizliği).
- Sayısal öznitelikler
  - Genel biçim Minkowski uzaklığıdır; parametre 1 ise Manhattan, 2 ise Öklid uzaklığı elde edilir. Sayısal verilerde en çok bunlar kullanılır.
- İkili öznitelikler
  - İki nesne $i$ ve $j$ için: ikisi de 1 olan öznitelik sayısı $a$, $i$ 1 ve $j$ 0 olanlar $b$, $i$ 0 ve $j$ 1 olanlar $c$, ikisi de 0 olanlar $d$.
  - Simetrik ikili (0 ve 1 eşit önemde, örneğin cinsiyet): $d(i,j) = \dfrac{b+c}{a+b+c+d}$.
  - Asimetrik ikili (1, 0'dan daha anlamlı, var/yok gibi): $d(i,j) = \dfrac{b+c}{a+b+c}$; ikisi de 0 olan $d$ paydaya katılmaz.
  <!-- BELİRSİZ: İkili öznitelik ve Minkowski slaytlarının karesi yok; formüller altyazıdaki anlatımdan yazıldı. -->
- Nominal ve sıralı öznitelikler (ekrandan, 00:30:00)
  - Nominal, basit eşleşme: $d(i,j) = \dfrac{p - m}{p}$; $m$ eşleşen nominal öznitelik sayısı, $p$ toplam nominal öznitelik sayısı. Her nominal değer için bir ikili öznitelik de kullanılabilir.
  - Sıralı: değerler sırasına göre 1, 2, 3, ... sayılarıyla değiştirilir ve sayısal kabul edilip seçilen uzaklık ölçüsü uygulanır.
- Karışık tipli öznitelikler (ekrandan, 00:35:00)
  - Bütün öznitelikler önce [0, 1] aralığına getirilir.
  - $d(i,j) = \dfrac{\sum_{k=1}^{p} \delta_{ij}^{k}\, d_{ij}^{k}}{\sum_{k=1}^{p} \delta_{ij}^{k}}$.
  - $\delta_{ij}^{k} = 0$: $k$. öznitelikte eksik değer varsa ya da $k$. öznitelik asimetrik ikili olup iki nesnede de 0 ise. Aksi halde $\delta_{ij}^{k} = 1$.
  - Sayısal öznitelikte $d_{ij}^{k} = \dfrac{|x_{ik} - x_{jk}|}{\max_k - \min_k}$; kategorik öznitelikte $d_{ij}^{k}$ 0 ya da 1'dir.
  - Kümelemede eksik değerler genellikle tahmin edilip doldurulmaz; yöntem eksik değerle çalışacak hale getirilir.
- Kümeleme yaklaşımları
  - Bölümleme (partitioning): veriyi örtüşmeyen kümelere ayırır; en çok kullanılanlar k-means ve k-medoids.
  - Hiyerarşik: iç içe kümeler bir ağaç gibi düzenlenir; bir seviyede ayrı görünen iki çocuk, bir üst seviyede tek küme olur.
  - Yoğunluk tabanlı (density-based): bir yoğunluk tanımına dayanır, örneğin DBSCAN.
  - Graf tabanlı yöntemler: yalnız ne oldukları gösterilecek.
- Bölümleme algoritmaları ve k-means
  - $n$ nesneli $D$ veri kümesi ve küme sayısı $k$ verilir; $D$, $k$ kümeye ayrılır.
  - Sezgisel (heuristic) ve yinelemelidir; sonuç başlangıç merkezlerine göre değişebilir.
  - k-means: her küme, kümedeki nesnelerin ortalaması (merkezi) ile temsil edilir. k-medoids: her küme, merkeze yakın gerçek bir nesneyle temsil edilir (sonraki kısma bırakıldı).
  - Algoritma (ekrandan, 00:40:00): girdi $k$ ve $D$; çıktı $k$ küme. (1) $D$'den rastgele $k$ eleman başlangıç küme ortalaması seçilir; (2) tekrarla: (3) her eleman ortalaması kendisine en yakın kümeye atanır; (4) bütün elemanlar atanınca gerçek yeni küme ortalamaları hesaplanır; (5) yeni ve eski ortalamalar arasında değişiklik olmayana kadar.
- K-means kümelerini değerlendirme: SSE (ekrandan, 00:55:00)
  - En yaygın ölçü karesel hata toplamıdır (Sum of Squared Error): her nokta için hata, en yakın küme ortalamasına uzaklıktır; bu hataların kareleri toplanır.
  - $SSE = \sum_{i=1}^{K} \sum_{x \in C_i} \text{dist}^2(m_i, x)$; $m_i$, $C_i$ kümesinin merkezidir (ortalaması).
  - K-means, her elemanı en yakın merkeze atayıp merkezleri yeniden hesaplayarak SSE'yi en aza indirmeye çalışır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kümeleme ile sınıflandırmayı karıştırmamak
  - Hoca, mezunlara ve mülakatlarda öğrencilere bu dersten ne hatırladıkları sorulduğunda çoğunun "kümeleme" dediğini, ama kümelemeyi sorunca sınıflandırmayı anlatmaya başladıklarını söyledi. Fark: kümelemede etiket yoktur.
- Küme sayısını kullanıcı verir
  - Kaç küme olacağı bilinmez, parametre olarak verilir; en iyi değer denenerek ve küme içi/kümeler arası uzaklıklara sayısal olarak bakılarak seçilir.
- Normalizasyon şart
  - Karışık tipli özniteliklerde uzaklıklar mutlaka [0, 1] aralığına getirilir. Örneğin 3 değerli bir kategorik öznitelik ile 1 ile 1 milyon arasında değişen sayısal bir öznitelik yan yana olursa, büyük değerli öznitelik diğer bütün öznitelikleri bastırır.
- Kümelemede eksik değer doldurmak sakıncalıdır
  - Sınıflandırmada etiket bilindiği için eksik değeri tahmin etmek mantıklı olabilir. Kümelemede doldurma, nesnelerin hangi kümeye düştüğünü değiştirebilir; bu yüzden yöntem eksik değerle çalışacak hale getirilir ($\delta = 0$).
- Başlangıç merkezleri ve durma koşulu
  - K-means'in sonucu başlangıçta seçilen merkezlere göre değişebilir. Doğru ayrılmış kümelerde merkezler bir süre sonra değişmez; ama çok büyük verilerde buna güvenilmemeli, "şu kadar yinelemeden sonra dur" gibi bir sınır konmalıdır.

## Kısa Tekrar Notları

- Kümeleme gözetimsizdir: etiket yok, küme sayısı $k$ parametre olarak verilir.
- İyi kümeleme: küme içi benzerlik yüksek, kümeler arası benzerlik düşük (uzaklık yüksek).
- Uzaklık özellikleri: negatif olmama, $d(i,i)=0$, simetri, üçgen eşitsizliği.
- Minkowski: parametre 1 Manhattan, 2 Öklid.
- İkili: simetrik $(b+c)/(a+b+c+d)$, asimetrik $(b+c)/(a+b+c)$.
- Nominal: $(p-m)/p$. Sıralı: 1, 2, 3, ... ile sayıya çevir.
- Karışık tip: $\delta$ ağırlıklı ortalama; eksik değer ya da asimetrik 0-0 durumunda $\delta = 0$; sayısal fark $\max - \min$ ile normalize edilir.
- Yaklaşımlar: bölümleme (k-means, k-medoids), hiyerarşik, yoğunluk tabanlı (DBSCAN), graf tabanlı.
- K-means: rastgele $k$ merkez, en yakın merkeze ata, ortalamaları güncelle, değişiklik olmayana kadar tekrarla.
- K-means SSE'yi en aza indirmeye çalışır.

## Detaylı Açıklamalar

- K-means sayısal örneği (ekrandan, 00:50:00)
  - Soru: Noktalar (0,2), (1,1), (2,0), (1,3), (2,3), (4,4), (5,6). $k=2$, başlangıç merkezleri (1,1) ve (2,3). Manhattan uzaklığıyla iki yineleme gösterilecek; her yinelemeden sonra küme ortalamaları ve küme içerikleri verilecek.
  - Manhattan uzaklığı: $|x_1 - x_2| + |y_1 - y_2|$; kare alınmaz.
  - 1. yineleme: (0,2) için (1,1)'e uzaklık $1+1=2$, (2,3)'e $2+1=3$, yani küme 1. (1,1) küme 1. (2,0) için $1+1=2$ ve $0+3=3$, küme 1. (1,3) için $0+2=2$ ve $1+0=1$, küme 2. (2,3), (4,4), (5,6) küme 2.
  - 1. yineleme sonu: $C_1 = \{(0,2),(1,1),(2,0)\}$, merkez $(3/3, 3/3) = (1,1)$. $C_2 = \{(1,3),(2,3),(4,4),(5,6)\}$, merkez $(12/4, 16/4) = (3,4)$.
  - 2. yineleme: (1,3) için (1,1)'e $0+2=2$, (3,4)'e $2+1=3$; artık küme 1. (2,3) için (1,1)'e $1+2=3$, (3,4)'e $1+1=2$; küme 2. (4,4) ve (5,6) küme 2; ilk üç nokta küme 1.
  - 2. yineleme sonu: $C_1 = \{(0,2),(1,1),(2,0),(1,3)\}$, merkez $(4/4, 6/4) = (1,\ 1{,}5)$. $C_2 = \{(2,3),(4,4),(5,6)\}$, merkez $(11/3,\ 13/3)$.
  - Merkezler değişmediği anda algoritma durur. Sonuçlar python ile doğrulandı.
  - Ders sonrası not: Hoca üçüncü yinelemede kümelerin büyük olasılıkla değişmeyeceğini söyledi. Python ile yapılan kontrolde değişiyor: (2,3) noktası (1; 1,5) merkezine $1+1{,}5=2{,}5$, (11/3; 13/3) merkezine $5/3+4/3=3$ uzaklıktadır ve küme 1'e geçer. Üçüncü yineleme sonunda $C_1 = \{(0,2),(1,1),(2,0),(1,3),(2,3)\}$, merkez $(6/5,\ 9/5) = (1{,}2;\ 1{,}8)$; $C_2 = \{(4,4),(5,6)\}$, merkez $(4{,}5;\ 5)$. Dördüncü yinelemede atamalar aynı kalır ve algoritma durur.
- K-means'in görsel örneği (ekrandan, 00:45:00)
  - Başta bütün noktalar aynı renktedir; $k=2$ için rastgele iki nokta merkez seçilir. Her nokta yakın olduğu merkeze atanır ve iki küme oluşur. Sonra her kümenin ortalaması (kırmızı noktalar) yeni merkez olur; noktalar yeniden atanır, bazıları küme değiştirir. Bu, merkezler sabitlenene kadar sürer.
  - Tek boyutta düşünmek sezgi verir: veri ikiye bölünür, yeni merkezler hesaplanır, aradaki sınır kayar, tekrar hesaplanır.
- SSE neden bu biçimde
  - Mükemmel bir kümelemede bir kümedeki bütün noktaların uzayda tek bir yerde toplanması beklenirdi; bu imkansız olduğu için her noktanın kendi küme merkezine uzaklığının karesi toplanır. SSE ne kadar küçükse kümeler o kadar sıkıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
