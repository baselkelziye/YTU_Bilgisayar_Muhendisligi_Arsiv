# Ders 10 Çalışma Özeti

## Genel Konular

- Eğitmensiz öğrenmeye (unsupervised learning) giriş: eğitmenli öğrenmeden (supervised learning) farkı.
- Verinin neden etiketsiz olduğu ve kullanım alanları.
- Öbekleme (clustering) hedefi: sınıf içi benzerlik yüksek, sınıflar arası benzerlik düşük.
- K-ortalama (K-means) algoritması ve elle çözülen örnek.
- K-means'in sorunları: başlangıç merkezleri, $K$'nın önceden seçilmesi.
- Hata ölçüsü: küme içi kareler toplamı (within-cluster sum of squares, WCSS).
- Dirsek yöntemi (elbow method) ile en uygun $K$'yı bulma.
- K-means'in karmaşıklığı.
- Düz (flat / partitional) ve hiyerarşik (hierarchical) öbekleme.
- Birleştirici (agglomerative) ve bölücü (divisive) hiyerarşik öbekleme; küme arası mesafe ölçüleri.
- Uygulama alanları ve veri analizinin önemi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Eğitmensiz öğrenme eskiden çok gerekmiyordu. Son 4-5 yılda büyük verinin makine öğrenmesiyle kullanılmasıyla öne çıktı.
- İyi bir öbeklemede sınıf içi benzerlik (within-class similarity) çok, sınıflar arası benzerlik (between-class similarity) az olmalı.
- K-means kolaylığı ve başarısı nedeniyle en çok tercih edilen eğitmensiz öğrenme yöntemidir.
- K-means'in en önemli sorunu $K$'yı baştan belirlemek zorunda olmanızdır. Gerçek uygulamaların çoğunda kaç grup olduğunu bilmezsiniz. Artık $K$ genelde sabit verilmiyor; farklı $K$ değerleri denenip en iyisi seçiliyor.
- $K$ sürekli artırılırsa hata sıfıra iner (her örnek kendi kümesi olur). Bu iyi bir şey değildir; optimum noktayı bulmak gerekir.
- **Doktora yapanlar dikkat:** Algoritma karmaşıklıkları yeterlik sınavlarında çok sorulur. K-means karmaşıklığını $O(n \cdot k \cdot i \cdot d)$ diye yazın, sonra açıklamasını yapın.
- Makine öğrenmesinde "uzaktan bakarak" kesin doğru söylenemez. Sonuç verinin dağılımına ve özelliklerine bağlıdır. Hangi yöntemin veya parametrenin iyi olduğunu deneyerek, performans metrikleriyle karşılaştırarak bulun.
- Veriyi çok iyi analiz edin. Veriyi bir kütüphaneye verip sonuç almak yetmez; başarısızlığın nedenini (hangi örnek türünde, hangi özellikte sorun var) incelemek gerekir. Yüksek lisans ve doktora tezlerinde bu çok önemlidir.
- Öğrencilerden ders sırasında daha çok soru sormalarını istedi.

## Kısa Tekrar Notları

- Eğitmenli öğrenme: örnekler ve etiketleri (beklenen çıkışlar) verilir. Örnekler: k-NN, karar ağacı, SVM, perceptron, MLP.
- Eğitmensiz öğrenme: yalnız örnekler vardır, etiket yoktur. Örnekler benzerliklerine göre gruplanır.
- K-means adımları: $K$ merkez rastgele seç → her örneği en yakın merkeze ata → merkezleri küme ortalaması olarak güncelle → değişim bitene kadar tekrarla.
- Durma koşulu: en fazla iterasyon sayısı, merkezlerin değişmemesi veya merkez değişiminin $\varepsilon$'dan küçük olması.
- Mesafe: hassasiyet gerekiyorsa Öklid (Euclidean), hız gerekiyorsa Manhattan.
- Hata: $SSE = \sum_{i=1}^{K} \sum_{\mathbf{x} \in C_i} \lVert \mathbf{x} - \mathbf{m}_i \rVert^2$.
- Dirsek yöntemi: farklı $K$ için WCSS hesapla; en küçük ve en büyük $K$ noktalarını birleştiren doğruya en uzak olan nokta optimum $K$'dır.
- Karmaşıklık: $O(n \cdot k \cdot i \cdot d)$ ($n$ örnek, $k$ küme, $i$ iterasyon, $d$ özellik). Pratikte $O(n)$ ile $O(n^2)$ arası.
- Hiyerarşik öbekleme: birleştirici (her örnek bir küme, birleştirerek yukarı) veya bölücü (tüm örnekler bir küme, bölerek aşağı).
- Küme arası mesafe: minimum (single linkage), maksimum (complete linkage), ortalama (average), merkezler arası (mean / centroid).

## Detaylı Açıklamalar

### 1. Eğitmenli ve Eğitmensiz Öğrenme

- Şimdiye kadar görülen k-en yakın komşu, karar ağacı, destek vektör makineleri, perceptron ve çok katmanlı perceptron eğitmenli yöntemlerdir. (Yapay sinir ağlarının eğitmensiz olanları da vardır.)
- Eğitmenli öğrenmede girişler ve beklenen çıkışlar etiketli verilir. Örnek: bir fotoğrafın kime ait olduğu, bir dokümanın magazin mi spor mu olduğu.
- Eğitmensiz öğrenmede örnekler vardır ama etiketleri yoktur.

**Veri neden etiketsiz olur?**

- Veri çok büyüktür; etiketlemeye zaman ve kaynak yetmez. Örnek: bir milyon müşteriyi alışveriş karakteristiğine göre elle etiketlemek hem zor hem çok zaman alıcıdır.
- Örüntünün karakteristiği zamanla değişir. Örnek: banka müşterilerinin harcama karakteristiği iş değişikliği, mezuniyet gibi nedenlerle değişir; etiketlerin sürekli güncellenmesi gerekir.
- Veri gerçekten etiketsizdir. Örnek: telefondaki benzer fotoğrafları (aynı ortamda farklı pozlarda çekilmiş) gruplamak.

**Kullanım alanları**

- Sosyal ağ analizi: kullanıcıları kullanım benzerliğine göre gruplama.
- Pazar segmentasyonu: müşterileri harcama benzerliğine göre gruplayıp gruplara öneride bulunma.

### 2. Öbekleme (Clustering) Hedefi

- Benzer örnekler aynı gruba alınır.
- Sınıf içi benzerlik yüksek, sınıflar arası benzerlik düşük olmalı.
- "Cluster" Türkçede "öbek" olarak karşılanmıştır. Hoca "grup" veya "klaster" demeyi tercih ediyor.
- Slayttaki örnek: aynı veri iki farklı şekilde 3 gruba ayrılmış. Solda benzerler bir arada. Sağda birbirine yakın iki örnek farklı gruplarda, birbirine uzak iki örnek aynı grupta. Sağdaki öbekleme kötüdür.

### 3. K-Ortalama (K-Means) Algoritması

- Örnekleri benzerliklerine göre $K$ gruba yerleştirir.
- Adı "mean"den gelir: küme merkezi, kümedeki örneklerin ortalamasıdır. Merkezler genelde $\mu$ ile gösterilir.

**Algoritma**

1. $K$ küme merkezini rastgele seç.
2. Her örneğin her merkeze uzaklığını hesapla. Örneği en yakın merkezin kümesine ata.
3. Her kümenin merkezini kümedeki örneklerin ortalaması olarak yeniden hesapla.
4. Kümelerde değişim varsa 2. adıma dön; yoksa dur.

**Durma koşulları**

- En fazla iterasyon sayısına ulaşmak (ör. 500).
- Merkezlerin artık değişmemesi.
- Bir önceki ve sonraki merkez arasındaki farkın belirlenen $\varepsilon$'dan küçük olması.

**Mesafe ölçüleri**

- En çok Öklid uzaklığı kullanılır: $d(\mathbf{x}, \mathbf{y}) = \sqrt{\sum_j (x_j - y_j)^2}$.
- Çok hassasiyet gerekmiyorsa ve hız isteniyorsa Manhattan uzaklığı: $d(\mathbf{x}, \mathbf{y}) = \sum_j \lvert x_j - y_j \rvert$.

**Örnek 1: K-means elle çözüm ($K = 2$, Manhattan uzaklığı)**

- İki özellik (ör. harcama miktarı ve günlük harcama sayısı). Örnekler:

| Örnek | $x_1$ | $x_2$ |
| :---: | :---: | :---: |
| $\mathbf{x}_1$ | 2 | 1 |
| $\mathbf{x}_2$ | 2 | 3 |
| $\mathbf{x}_3$ | 3 | 2 |
| $\mathbf{x}_4$ | 5 | 2 |
| $\mathbf{x}_5$ | 7 | 2 |
| $\mathbf{x}_6$ | 7 | 3 |
| $\mathbf{x}_7$ | 8 | 2 |

- Başlangıç merkezleri (hoca bilerek seçti): $\mu_1 = (3, 2)$, $\mu_2 = (8, 2)$.
- **1. iterasyon, uzaklıklar:**

| Örnek | $d(\cdot, \mu_1)$ | $d(\cdot, \mu_2)$ | Küme |
| :---: | :---: | :---: | :---: |
| $\mathbf{x}_1$ | $1 + 1 = 2$ | $6 + 1 = 7$ | 1 |
| $\mathbf{x}_2$ | $1 + 1 = 2$ | $6 + 1 = 7$ | 1 |
| $\mathbf{x}_3$ | $0$ | $5$ | 1 |
| $\mathbf{x}_4$ | $2$ | $3$ | 1 |
| $\mathbf{x}_5$ | $4$ | $1$ | 2 |
| $\mathbf{x}_6$ | $4 + 1 = 5$ | $1 + 1 = 2$ | 2 |
| $\mathbf{x}_7$ | $5$ | $0$ | 2 |

- **Yeni merkezler:**
  - $\mu_1 = \left(\frac{2+2+3+5}{4}, \frac{1+3+2+2}{4}\right) = (3, 2)$ (değişmedi).
  - $\mu_2 = \left(\frac{7+7+8}{3}, \frac{2+3+2}{3}\right) = \left(\frac{22}{3}, \frac{7}{3}\right) \approx (7.33, 2.33)$.
- **2. iterasyon:** $\mathbf{x}_1, \mathbf{x}_2, \mathbf{x}_3$ açıkça $\mu_1$'e yakın. Sınırdaki $\mathbf{x}_4$ kontrol edilir:
  - $d(\mathbf{x}_4, \mu_1) = 2$
  - $d(\mathbf{x}_4, \mu_2) = \lvert 5 - 7.33 \rvert + \lvert 2 - 2.33 \rvert = 2.33 + 0.33 \approx 2.67$
  - $\mathbf{x}_4$ kümesini değiştirmez.
- Hiçbir örnek küme değiştirmediği için algoritma durur. Sonuç: Küme 1 = $\{\mathbf{x}_1, \mathbf{x}_2, \mathbf{x}_3, \mathbf{x}_4\}$, Küme 2 = $\{\mathbf{x}_5, \mathbf{x}_6, \mathbf{x}_7\}$.
- Hoca $\mathbf{x}_4$'ün ikinci adımda küme değiştirmesini planlamıştı ama seçtiği değerlerle bu olmadı; iki iterasyonda yakınsadı.

**Slayttaki örnek:** Rastgele başlayan iki merkez her iterasyonda kayıyor. Başta beklenmeyen bir şekilde ilerleyen bölümleme, iterasyonlar sonunda iki mantıklı kümeye dönüşüyor.

### 4. K-Means'in Sorunları

**Başlangıç merkezleri**

- Başlangıç merkezlerinin yeri sonucu değiştirebilir. Merkez kötü bir yerden başlarsa kayarak beklenmeyen bir yere oturabilir ve gözle bakınca daha iyi görünen öbekleme elde edilmeyebilir.

**$K$'nın önceden seçilmesi**

- $K = 3$ verilirse algoritma mutlaka 3 küme üretir. Veride aslında 2 grup varsa birbirine benzeyen bir grubu ayrı bir küme yapar.
- Tersi de olabilir: aslında 5 grup varken 3 denirse farklı gruplar birleştirilmek zorunda kalır.
- Bir çözüm fikri: kümelerdeki örnek sayısına bakmak. Bir kümedeki örnek sayısı bir eşiğin altındaysa ve yakınında (başka bir eşik mesafesi içinde) bir küme varsa iki küme birleştirilir. Ama eşikler deneysel belirlenir; dikkatli olmak gerekir.
- Uzakta kalan az sayıdaki örnek ise ayrı bir küme olabilir; bu bir anomali değildir.
- $K$'yı önceden bilmek bazen mümkündür. Örnek: sahte haber tespitinde iki küme vardır (sahte / sahte değil). Ama gelir grubu, öğrenci başarısı, sosyal ağ kullanıcıları, müşteri harcamaları gibi problemlerde grup sayısı bilinmez.

### 5. Hata Ölçüsü ve Dirsek Yöntemi

- Kare hata toplamı (sum of squared error): $\mathbf{x}$, $C_i$ kümesindeki bir örnek ve $\mathbf{m}_i$ bu kümenin merkezi olmak üzere

$$SSE = \sum_{i=1}^{K} \sum_{\mathbf{x} \in C_i} \lVert \mathbf{x} - \mathbf{m}_i \rVert^2$$

- Her örneği en yakın kümeye yerleştirmek bu toplamı küçültür. Amaç hatanın minimum olmasıdır.
- Hoca uygulamalarda bu hatanın doğrudan çok kullanıldığını görmediğini söyledi; asıl kullanımı $K$'yı belirlemektir.

**Bir öğrenci önerisi:** $K$'yı büyük (ör. 20) alıp bulunan merkezleri yeniden K-means ile 2-3 kümeye indirmek. Hoca $K$'nın otomatik belirlenmesini bunun ardından anlattı.

**Dirsek (elbow) yöntemi**

1. $K = 2$'den başla ($K = 1$ her şeyin tek grupta olması demek, gerekmez). Bir en büyük $K$ belirle (ör. 20; ihtiyaca göre daha büyük).
2. Her $K$ için K-means çalıştır ve küme içi kareler toplamını (WCSS) hesapla.
3. $K$'ya karşı WCSS grafiğini çiz. Hata önce hızlı düşer, sonra düşüş yavaşlar.
4. En küçük ve en büyük $K$ noktalarını bir doğruyla birleştir.
5. Her $K$ noktasının bu doğruya uzaklığını hesapla. En uzak nokta "dirsek"tir; optimum $K$ budur.

- **Soru:** Hata ne zaman sıfır olur? Bir öğrenci cevap verdi: her örnek ayrı bir küme olursa. 100 örnek ve $K = 100$ ise her merkez örneğin kendisidir ve hata sıfırdır. Bu yüzden $K$'yı sürekli artırmak çözüm değildir.
- Beklenen grafik, dirsekten sonra tamamen düz çizgi değildir. $K$ arttıkça hata azalmaya devam eder ama yavaşça.
- Hocanın çalışmalarından örnekler:
  - BKM ile gerçek kredi kartı verisi üzerinde sahtekârlık işlemlerini gruplama. Kaç tür sahtekârlık olduğu bilinemiyordu; tutar, sıklık, saat, iş yeri türü gibi birçok özellik vardı. Dirsek yöntemiyle en uygun $K$ bulundu.
  - Görüntüleri renk gruplarına ayırma (açık pembe ile biraz daha açık pembe aynı kümede olsun diye).

### 6. K-Means'in Karmaşıklığı

- Soru: $n$ örnek, $d$ özellik, $K$ küme için bir çalıştırmanın karmaşıklığı nedir?
- Cevap:

$$O(n \cdot k \cdot i \cdot d)$$

- $n$ örnek sayısı, $k$ küme sayısı, $i$ iterasyon sayısı, $d$ özellik sayısı.
- Küme sayısı genelde küçüktür, özellik sayısı da sınırlıdır (30, 100, 500 gibi). İterasyon sayısı çok olursa $O(n^2)$'ye yaklaşır; çabuk yakınsarsa $O(n)$ gibi düşünülebilir.
- Sınavda sabitleri atmadan $O(n \cdot k \cdot i \cdot d)$ yazın, sonra açıklayın.

### 7. Düz ve Hiyerarşik Öbekleme

- K-means bölümleyici (partitional) yani düz (flat) öbeklemedir. Hiyerarşi yoktur; bütün kümeler aynı seviyededir. Örnek: bir resmi renk benzerliğine göre mavi, yeşil, kırmızı tonlarına ayırmak.
- Hiyerarşik öbeklemede örnekler bir hiyerarşiye göre gruplanır. Örnek: canlılar → hayvanlar / bitkiler → omurgalılar / omurgasızlar; bitkiler → çekirdek üretenler / spor üretenler.
- Veride bir hiyerarşi varsa hiyerarşik öbekleme kullanılabilir.
- Gelecek hafta başka düz öbekleme yöntemleri anlatılacak: Gauss karışım modeli (Gaussian mixture), öz-düzenleyici haritalar (self-organizing map).

**İki yaklaşım**

- **Birleştirici (agglomerative):** her örnek başta ayrı bir kümedir. En yakın iki küme birleştirilir. Tüm örnekler tek kümede olana kadar devam edilebilir. Nerede duracağınıza siz karar verirsiniz. En çok kullanılan budur.
- **Bölücü (divisive):** tüm örnekler başta tek kümedir. K-means mantığıyla ikiye bölünür, sonra her parça yeniden bölünür.

**Örnek (birleştirici, A-F örnekleri):** A, B, C, D, E, F tek tek küme olarak başlar. Benzerler birleştirilir. Örneğin bir seviyede {A}, {B, C}, {D, E}, {F} kümelerinde durulabilir.

### 8. Küme Arası Mesafe Ölçüleri

- Örnekler arası mesafe için genelde Öklid, hız istenirse Manhattan kullanılır.
- İki küme arasındaki mesafe dört şekilde ölçülebilir:

**Minimum mesafe (single linkage, nearest neighbor)**

- İki kümedeki tüm örnek çiftlerinin mesafesi hesaplanır. En yakın iki örneğin mesafesi kümeler arası mesafe kabul edilir.
- Tüm küme çiftleri için bu yapılır; en kısa mesafeli iki küme birleştirilir.
- Slayttaki örnekte bir gürültülü (parazitli) örnek yüzünden iki küme beklenmedik şekilde birleşiyor.

**Maksimum mesafe (complete linkage)**

- İki kümedeki en uzak iki örneğin mesafesi kümeler arası mesafe kabul edilir.
- Bu en uzak mesafelerin en küçüğüne sahip iki küme birleştirilir. Örnek: $D_1$-$D_2$ en uzak mesafesi $D_2$-$D_3$'ten küçükse $D_1$ ile $D_2$ birleşir.

**Ortalama mesafe (average)**

- $i$. kümedeki örnekler $\mathbf{x}$, $j$. kümedeki örnekler $\mathbf{y}$ olsun. Tüm çiftlerin mesafelerinin ortalaması alınır. En küçük veya en büyüğü bulmakla uğraşılmaz.

$$d_{avg}(C_i, C_j) = \frac{1}{\lvert C_i \rvert \lvert C_j \rvert} \sum_{\mathbf{x} \in C_i} \sum_{\mathbf{y} \in C_j} d(\mathbf{x}, \mathbf{y})$$

**Merkezler arası mesafe (mean / centroid)**

- K-means'e benzer ve en basitidir. Her kümenin merkezi (ortalaması) bulunur. Merkezleri birbirine en yakın iki küme birleştirilir.

$$d_{mean}(C_i, C_j) = \lVert \mathbf{m}_i - \mathbf{m}_j \rVert$$

- Minimum ve maksimum mesafe çok masraflıdır; tüm örnek çiftlerinin mesafesi hesaplanmalıdır.

**Öğrenci sorusu: En masraflı yöntem en doğrusu mu?**

- Hoca: Deneme yapmadan konuşmak doğru değil. Ben her mesafe ölçüsüyle ayrı ayrı öbekleme yapıp hatalarını karşılaştırırdım.
- Hissiyatı: merkezler arası mesafe hem daha hızlı hem yeterince etkili olur. Çünkü merkez, dağılım ne olursa olsun kümeyi temsil eder.
- Sonuç veriye bağlıdır. Daha önce anlatılan performans metrikleri (accuracy, precision, recall) yöntem seçiminde olduğu gibi parametre seçiminde de kullanılır.
- Bir öğrenci etiket olmadığı için doğruluğun ölçülmesinin de zor olduğunu belirtti. Hoca katıldı: $K = 5$ mi $K = 6$ mı daha iyi, etiket yokken gerçekten ölçmek zor.

**Bölücü yöntemde nerede durulur?**

- Hiyerarşiyi genelde siz bilirsiniz ve hangi seviyede keseceğinize siz karar verirsiniz (ör. hayvanları omurgalı / omurgasız seviyesinde kesmek veya köpek türlerine kadar inmek).
- Görüntü bölütlemede: pikseller renk özelliklerine göre bölünür. Bir kümedeki tüm pikseller aynı renkteyse daha fazla bölmeye gerek yoktur.
- Genel kural: sınıf içi benzerlik yeterince yüksek, sınıflar arası benzerlik düşükse, yani kare hata yeterince küçükse durulur.
- Pratikte hiyerarşik öbeklemeden çok düz öbekleme (K-means türü) kullanılır.

### 9. Uygulama Alanları

- **Görüntü işleme:** ilk yıllarda K-means renk benzerliğine göre gruplamada çok kullanıldı. Örnek: doğa resimleri (mavi, yeşil ağırlıklı) ve şehir resimleri (gri ağırlıklı). Önce gruplanır, sonra gruplar etiketlenir.
- **Sahte haber tespiti:** haberler başlık ve içerik benzerliğine göre gruplanır.
- **Spam e-posta tahmini:** mailler benzerliklerine göre gruplanır; sonuç eğitmenli öğrenme sistemine bilgi olarak verilir.
- **Doküman gruplama:** $K$ bilinmeden dokümanlar gruplanır; sonra gruplar etiketlenebilir (siyaset, magazin vb.).
- **Pazarlamada kişiselleştirme:** eskiden "üniversite mezunu, büyükşehirde yaşayan kişiler şöyle harcar" gibi zorlama gruplar yapılırdı; aslında farklı özellikteki insanların aynı grupta yer alabildiği görüldü. Bugün müşteriler farklı $K$ değerleriyle gruplanıp her gruba farklı öneriler yapılıyor. Harcama profilini bir basamak yukarı taşıma, müşteri kaybı (churn) analizi, sadık / sadık olmayan müşteri ayrımı gibi.
- Yaygın yaklaşım: önce öbekle, sonra sınıflandır (öbekleme sonuçlarını sınıflandırıcıya ver).

### 10. Veri Analizinin Önemi

- **Öğrenci sorusu (ödevle ilgili):** Seçim döneminde bir konuda haberlerin çoğu sahteyse, eğitmensiz öbeklemede o konudaki doğru bir haber de sahte kümeye düşmez mi?
- Hoca: Ezbere söylemek mümkün değil, sonuç veriye bağlıdır. Ödevde yalnız başlıklara bakılıyor; az kelime (az bilgi) olduğu için başarının sınırlı olması beklenir. Twitter gibi kısa metinlerde bile sınıflandırma zordur. Öbekleme kötü sonuç verirse nedenini analiz etmek gerekir; belki problem öbeklemeye hiç uygun değildir. Ödevde beklenen de budur: deneyin, sonuçlara bakın, başarıyı neyin düşürdüğünü yazın.
- **TÜBİTAK projesi örneği:** Yurt dışı aramaların yurt içi gibi gösterilmesiyle yapılan sahtekârlık (servis sağlayıcı yurt dışı arama için yaklaşık 1 euro yerine yurt içi gibi 10 cent ödüyor). Proje ekibi yakalanan sahte aramaları "sahte" etiketlemiş, geri kalan her şeyi "sahte değil" kabul etmiş. Bu yanlıştır: geri kalanların içinde tespit edilmemiş sahteler olabilir. Gerçekten sahte olmadığı bilinen temiz örnekler seçilmelidir. Hoca bunu belirttiğinde kurum çok şaşırmış.
- Hoca TEYDEB ve Ar-Ge merkezi değerlendirmelerinde çok gördüğü bir hatayı anlattı: veriyi Python'da bir sınıflandırıcıya veya derin öğrenmeye verip sonucu almak yeterli sanılıyor. Başarılı çalışmalarda asıl önemli olan analizdir.
- Hoca bunu iyi teşhis koyan doktorlara benzetti: sebep-sonuç ilişkisini iyi değerlendirmek gerekir.

### Ders sonrası notlar

- **Tarih:** 8 Aralık 2020. Ders 9 (1 Aralık 2020) kaydı arşivde yok; o hafta vize yapıldı (hoca dersi "bugün sınavdan sonra yeni bir öğrenme modeline geçiyoruz" diye açıyor; ders 8'de vize 1 Aralık'a ertelenmişti).
- **Ödev soruları:**
  - Ödev sahte haber (fake news) sınıflandırması ile ilgili; yalnız haber başlıkları kullanılıyor.
  - Ödev Python ile yapılıyor. Naive Bayes ve karar ağacı gibi yöntemler için hazır kütüphaneler kullanılabilir.
  - Entropi hesabı için de kütüphane kullanılabilir (bir öğrenci elle yapmanın zor olduğunu söyledi). Entropi: olasılık çarpı olasılığın logaritması toplamı.
  - Veri setindeki Rusça gibi farklı dildeki örnekler dahil edilmeyecek. Farklı bir şey yapılırsa açıklama yazılmalı.
  - Test verisinin nasıl ayrılacağı ödev metninde ne yazıyorsa öyle yapılmalı; farklı yapılırsa açıklanmalı.
- **Düzeltmeler:**
  - Hoca dersin başında "eğitmensiz öğrenme, supervised learning" dedi. Eğitmensiz öğrenmenin İngilizcesi unsupervised learning'dir.
  - K-means örneğinde hoca $d(\mathbf{x}_4, \mu_1)$'i önce yanlış hesapladı; bir öğrenci uyarınca 2 olarak düzeltildi ($\lvert 5-3 \rvert + \lvert 2-2 \rvert = 2$).
  - Hoca hata ölçüsünü bir yerde "sınıflar arası toplam hata" diye andı. Doğrusu küme içi kareler toplamıdır (within-cluster sum of squares, WCSS): her örneğin kendi küme merkezine uzaklığının karelerinin toplamı. Altyazıda "BCSS" olarak geçen kısaltma da WCSS olmalıdır.
  - Altyazıda "Gözler, mixture" diye geçen yöntem Gauss karışım modelidir (Gaussian mixture model).
- **Ara:** Ders 10:43'te 15 dakikalık ara verildi (yaklaşık 00:39-00:56).
- **Kayıt:** Hocanın kayıtlara itirazı yok.

> **Not:** Bu özeti ve dersin altyazı dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
