# Ders 5 Çalışma Özeti

12 Kasım 2020 Perşembe, online ders (yaklaşık 2 saat 7 dakika). Ders büyük ölçüde İngilizce, bazı açıklamalar Türkçe. Ders kitabı: Bing Liu, *Web Data Mining* (Springer, 2007). Slaytlar kitabın CS583 sunumları (Chapter 4 ve Chapter 6).

## Genel Konular

- Hiyerarşik kümeleme (hierarchical clustering) ve dendrogram (dendrogram)
  - Aşağıdan yukarı (agglomerative, bottom-up) ve yukarıdan aşağı (divisive, top-down) kümeleme
- Kümeler arası uzaklık hesaplama stratejileri
  - Single link, complete link, average link, centroid
- Uzaklık fonksiyonları (distance functions)
  - Sayısal veri: Minkowski, Öklid (Euclidean), Manhattan, ağırlıklı Öklid, kareli Öklid, Chebyshev
  - İkili (binary) ve nominal veri: simple matching coefficient, Jaccard katsayısı
  - Metin: kosinüs benzerliği (cosine similarity)
- Kümeleme değerlendirmesi (cluster evaluation)
  - Küme içi (intra-cluster) ve kümeler arası (inter-cluster) uzaklık
  - Etiketli veri varsa: entropi (entropy), saflık (purity), precision, recall, F-score
- Chapter 6: Bilgiye erişim ve web araması (information retrieval and web search)
  - Bilgiye erişim ile veritabanı sorgusu farkı
  - Web aramasının özel sorunları (hiperlink, ölçek, yanıt süresi, spam)
  - IR modeli ve IR mimarisi
  - Sorgu türleri: anahtar kelime, Boolean, ifade (phrase), yakınlık (proximity), tam doküman, doğal dil
  - Boolean model ve vektör uzayı modeli (vector space model), TF-IDF
  - Kosinüs ve Okapi benzerliği, ilgililik geri bildirimi (relevance feedback)
- Dönem projesi önerileri

## Hocanın Özellikle Vurguladığı Kısımlar

- k-means'in iki zayıflığı var:
  - Küme sayısı $k$ baştan verilmeli.
  - Eliptik olmayan (iç içe halka gibi) şekilleri bulamaz.
- Hiyerarşik kümeleme bu iki soruna çözümdür. Derste aşağıdan yukarı (agglomerative) yöntem işlendi, çünkü yaygın kullanılan odur.
- Hangi uzaklık stratejisinin ve hangi uzaklık fonksiyonunun en iyi sonucu vereceği baştan bilinmez.
  - Algoritma bunlarla parametrik yazılmalı.
  - Farklı kombinasyonlar denenip kümeleme kalitesi karşılaştırılmalı.
- Entropi ve saflık formüllerini ezberlemeye gerek yok. Değerlerin nasıl yorumlanacağı bilinmeli.
- Kosinüs benzerliği formülü önemli; Okapi yalnızca bilgi için.
- Bilgiye erişimde veri ve sorgu yapısızdır. Veritabanında ise veri tablolar hâlinde, sorgu SQL ile yapılıdır.
- Proje önerileri aynı gün e-posta ile gönderilmeli. Bu İngilizce seçmeli derste proje yapılmadan geçmek riske atılmamalı.

## Kısa Tekrar Notları

- Agglomerative kümeleme:
  - Başta her veri noktası tek elemanlı bir kümedir.
  - Tüm ikili uzaklıklar hesaplanır, en yakın iki küme birleştirilir.
  - Yeni kümenin diğerlerine uzaklığı güncellenir. Tek küme kalana kadar tekrarlanır.
  - Sonuçta dendrogram oluşur. Dendrogramın her seviyesi farklı bir kümelemedir.
- Uzaklık stratejileri:
  - Single link: iki kümenin en yakın iki noktası.
  - Complete link: iki kümenin en uzak iki noktası.
  - Average link: tüm nokta çiftlerinin uzaklıklarının ortalaması.
  - Centroid: küme merkezleri arasındaki uzaklık.
- Minkowski: $dist(x_i,x_j)=\left(\sum_{f=1}^{r}|x_{if}-x_{jf}|^h\right)^{1/h}$
  - $h=2$: Öklid, $h=1$: Manhattan.
  - Chebyshev: $\max_f |x_{if}-x_{jf}|$.
- İkili nitelikler için karışıklık matrisi (confusion matrix):
  - $a$: ikisinde de 1, $b$: $x_i$'de 1 ve $x_j$'de 0, $c$: $x_i$'de 0 ve $x_j$'de 1, $d$: ikisinde de 0.
  - Simetrik ikili nitelik: $\frac{b+c}{a+b+c+d}$ (simple matching).
  - Asimetrik ikili nitelik: $\frac{b+c}{a+b+c}$ (Jaccard).
  - Nominal nitelik: $\frac{r-q}{r}$ ($r$: nitelik sayısı, $q$: eşleşen nitelik sayısı).
- Entropi belirsizliği ölçer: düşük entropi iyi kümedir. Saflık homojenliği ölçer: yüksek saflık iyi kümedir.
- TF-IDF:
  - $tf_{ij}=\frac{f_{ij}}{\max\{f_{1j},\dots,f_{|V|j}\}}$
  - $idf_i=\log\frac{N}{df_i}$
  - $w_{ij}=tf_{ij}\times idf_i$
- Kosinüs benzerliği: $cosine(d_j,q)=\frac{d_j\cdot q}{\|d_j\|\,\|q\|}$

## Detaylı Açıklamalar

### Hiyerarşik Kümeleme ve Dendrogram

Derse önceki haftadan kalan kümeleme konusuyla başlandı. Hoca k-means'in bölümleme tabanlı (partition-based) bir algoritma olduğunu hatırlattı.

Örnekte iki boyutlu uzayda beş nokta ($P_1$–$P_5$) var:

- İlk adımda tüm ikili uzaklıklar hesaplanır. En yakın çift $P_1$ ve $P_2$ çıkar ve birleştirilip küme 1 olur.
- Sonra $P_3$ ile $P_4$ birleşip küme 2 olur.
- Ardından küme 1 ile $P_3$... şeklinde devam edilir. (Hoca bu adımda küme 1 ile $P_3$'ün birleştiğini söyledi; slayt çiziminde $P_3$ artık küme 2'nin içinde olduğundan bu adım altyazıda tutarsız.)
- Algoritma tüm noktalar tek kümede toplanana kadar sürer.

Dendrogram yukarıdan aşağı taranır. Her seviyedeki kümeleme için kalite metriği (küme içi ve kümeler arası uzaklık) hesaplanır. En iyi kaliteyi veren seviye nihai kümeleme olarak seçilir.

### Uzaklık Stratejileri

Çok elemanlı kümeler arasındaki uzaklık için hangi noktaların kullanılacağını strateji belirler:

- 3 elemanlı küme ($P_1,P_2,P_3$) ile 2 elemanlı küme ($P_4,P_5$) örneğinde:
  - Single link en yakın çifti ($P_2,P_5$) kullanır.
  - Complete link en uzak çifti ($P_1,P_4$) kullanır.
  - Average link 6 çiftin uzaklıklarının ortalamasını alır.
  - Centroid iki küme merkezi arasındaki uzaklığı alır.

Strateji yalnızca hangi noktaların seçileceğini söyler. Uzaklığın hangi fonksiyonla ölçüleceği ayrı bir seçimdir. Örneğin single link ile Chebyshev ya da single link ile Öklid birlikte kullanılabilir.

### Uzaklık Fonksiyonları

- Sayısal (real-valued) nitelikler:
  - Minkowski genel formdur. Öklid en yaygın kullanılanıdır.
  - Ağırlıklı Öklid: her niteliğe ağırlık verilir.
  - Kareli Öklid (squared Euclidean): uzaktaki noktalara daha çok ağırlık verir.
  - Chebyshev: herhangi bir nitelikte farklıysa iki noktayı farklı saymak için en büyük fark alınır.
- İkili nitelikler:
  - Simetrik: iki durum eşit önemde (ör. cinsiyet). Simple matching kullanılır.
  - Asimetrik: bir durum daha önemli. Jaccard kullanılır; paydada iki noktada da 0 olan nitelikler ($d$) sayılmaz.
- Nominal nitelikler (haftanın günü, renk gibi ikiden fazla durumlu): eşleşmeyen nitelik sayısı bölü toplam nitelik sayısı.
- Metin dokümanları: dokümanlar kelime çantası (bag of words) ile vektöre çevrilir, kosinüs benzerliği kullanılır.

Slayttaki örnek (7 ikili nitelik):

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| $x_1$ | 1 | 1 | 1 | 0 | 1 | 0 | 0 |
| $x_2$ | 0 | 1 | 1 | 0 | 0 | 1 | 0 |

- $a=2$, $b=2$, $c=1$, $d=2$.
- Simple matching: $\frac{2+1}{2+2+1+2}=\frac{3}{7}\approx0{,}429$.
- Jaccard: $\frac{2+1}{2+2+1}=\frac{3}{5}=0{,}6$.

### Kümeleme Değerlendirmesi

Etiket yoksa küme içi ve kümeler arası uzaklıklar kullanılır:

- Küme içi uzaklık kümenin sıkılığını (compactness) gösterir.
- Kümeler arası uzaklık kümelerin birbirinden ayrıklığını (isolation) gösterir.

Etiketli veri (ground truth) varsa entropi, saflık, precision, recall ve F-score kullanılabilir. Kümeleme problemlerinde genelde etiket olmaz.

Slayttaki örnek (900 doküman, her sınıftan 300):

| Küme | Science | Sports | Politics | Entropi | Saflık |
|---|---|---|---|---|---|
| 1 | 250 | 20 | 10 | 0,589 | 0,893 |
| 2 | 20 | 180 | 80 | 1,198 | 0,643 |
| 3 | 30 | 100 | 210 | 1,257 | 0,617 |
| Toplam | 300 | 300 | 300 | 1,031 | 0,711 |

- Küme 1'de çoğunluk tek sınıftadır. Belirsizlik düşüktür, bu yüzden entropi düşük ve saflık yüksektir.
- Küme 3'te dağılım daha karışıktır. Entropi daha yüksek, saflık daha düşüktür.
- Entropi $\log_2$ ile hesaplanır. Toplam değerler küme boyutlarıyla ağırlıklı ortalamadır.

### Bilgiye Erişim ve Web Araması (Chapter 6)

Web madenciliğinin üç kolu hatırlatıldı:

- İçerik madenciliği (web content mining)
- Yapı madenciliği (structure mining)
- Kullanım madenciliği (web usage mining)

Bu bölüm içerik madenciliğine aittir; büyük ölçüde metin madenciliğidir.

Bilgiye erişim (information retrieval, IR), doküman koleksiyonundan kullanıcının bilgi ihtiyacını karşılayan dokümanları bulma çalışmasıdır. IR şu aşamaları kapsar:

- Verinin toplanması (acquisition)
- Düzenlenmesi (organization), yani indeks oluşturma
- Saklanması (storage)
- Getirilmesi (retrieval)
- Dağıtılması (distribution)

Hoca IEEE Xplore, ACM Digital Library ve Google arama arayüzlerini örnek olarak gösterdi. Veri, bilgi, bilgi birikimi ve bilgelik ayrımı:

- Ham web sayfaları veridir (data).
- Arama sonucu listesi bilgidir (information).
- Sonuçları inceleyince oluşan kavrayış bilgi birikimidir (knowledge).
- Bu kavrayış çok kişide ortaklaşınca bilgelik (wisdom) olur.

IR ile veritabanı sorgusu arasındaki fark:

- IR'de dokümanlar ve sorgu (anahtar kelimeler) yapısızdır.
- Veritabanında hem veri hem SQL sorgusu hem sonuç yapılıdır.

Web araması bir IR uygulamasıdır ama kendine özgü sorunları vardır:

- Hiperlinkler kullanılabilir.
- Dokümanları toplamak, saklamak ve güncellemek çok zordur.
- Çok sayıda eşzamanlı kullanıcıya hızlı yanıt gerekir.
- Web spam'i vardır: sayfa sahipleri üst sıralara çıkmak için sayfaya konuyla ilgisiz anahtar kelimeler ekler.

### IR Modeli ve Mimarisi

Bir IR modeli dört şey tanımlar:

- Sorgu dili
- Sorgunun iç temsili
- Dokümanın iç temsili
- Sorgu ile dokümanı karşılaştıran fonksiyon (sıralama fonksiyonu, ranking function)

Mimaride akış şöyledir:

1. İndeksleyici (indexer) doküman koleksiyonunu işleyip indeks oluşturur.
2. Kullanıcı arayüzden sorgu girer, sorgu çalıştırılabilir sorguya (executable query) dönüşür.
3. Erişim sistemi sorgunun iç temsilini indeksle karşılaştırır.
4. Sıralanmış sonuçlar (genelde ilk 10) kullanıcıya gösterilir.

Sorgu türleri:

- Anahtar kelime sorgusu: Google'da en çok kullanılan tür.
- Boolean sorgu: AND, OR, NOT ile kurulur. Yalnızca sorguyu doğru (true) yapan dokümanlar döner (tam eşleşme, exact match).
- İfade sorgusu (phrase query): tırnak içindeki kelimeler tam o sırayla aranır.
- Yakınlık sorgusu (proximity query): kelimeler yan yana olmak zorunda değil ama birbirine yakın olmalı. Ne kadar yakınsa sıralama o kadar yüksek olur.
- Tam doküman sorgusu: bir görsel ya da dokümanın tamamı sorgu olarak verilir (görsel arama, intihal denetimi siteleri).
- Doğal dil sorusu: arama motoru soruya doğrudan cevap da verebilir.

### Boolean Model ve Vektör Uzayı Modeli

Doküman koleksiyonundaki tüm ayırt edici kelimeler sözlüğü (vocabulary) oluşturur. Her doküman, sözlük boyutunda bir vektörle temsil edilir.

- Boolean model:
  - Kelime dokümanda varsa 1, yoksa 0 yazılır.
  - Eşleşme tam eşleşmedir; sıralama yoktur.
- Vektör uzayı modeli:
  - 1 yerine TF-IDF ağırlığı yazılır.
  - TF, kelimenin dokümanda kaç kez geçtiğinin, dokümanda en çok geçen kelimenin frekansına oranıdır. Kelimenin o dokümandaki önemini gösterir.
  - IDF, kelimenin koleksiyondaki nadirliğini gösterir. Az dokümanda geçen kelimenin IDF'i yüksektir; her dokümanda geçen kelimenin önemi düşüktür.
  - Sorgu da aynı boyutta vektöre çevrilir. Doküman ile sorgu arasındaki benzerlik kosinüs ile ölçülür ve sonuçlar buna göre sıralanır.

Slayttaki örnek: sözlük {hardware, software, users}, dokümanlar A1=(1,0,0), A2=(0,1,0), A3=(0,0,1), A4=(1,1,0), A5=(1,0,1), A6=(0,1,1), A7=(1,1,1), A8=(1,0,1), A9=(0,1,1).

- Sorgu "hardware AND software": Boolean model yalnızca A4 ve A7'yi getirir.
- Sorgu "hardware OR software": A3 dışındaki tüm dokümanlar gelir.
- Vektör uzayında sorgu $q=(1,1,0)$ alınır. Kosinüs değerleri:
  - A4: 1
  - A7: 0,816
  - A1 ve A2: 0,707
  - A5, A6, A8, A9: 0,5
  - A3: 0

Kosinüs dışında Okapi benzerliği gibi başka benzerlik fonksiyonları da vardır.

### İlgililik Geri Bildirimi (Relevance Feedback)

1. Kullanıcı ilk sorguyu girer, sonuçlar gelir.
2. Kullanıcı ilgili bulduğu sonuçları işaretler.
3. Sistem bu dokümanlarda sık geçen kelimeleri sorguya ekler ve aramayı tekrarlar.

Bu yöntemle daha kaliteli sonuçlar elde edildiği gösterilmiştir.

### Proje Önerileri

- Proje önerileri hocanın e-posta adresine gönderilmeli.
- Hoca önerileri inceleyip bir Excel dosyasında gruplar, konular ve gereken düzeltmelerle duyuracak. Duyurular ders sayfasından takip edilmeli.
- Sorunsuz öneriler hemen başlayabilir. Eksikleri olanlar ertesi hafta konuşup tamamlayacak.
- Konuyu öğrenciler belirliyor. Hoca yalnızca konuyu dersteki algoritmaları kullanacak şekilde yönlendiriyor.
- Kabul edilmeyen bir öneri olursa hoca öğrencilerle konuşup yeni öneri getirecek.

### Ders sonrası notlar

- Jaccard örneğinde hoca paydayı 6 aldı ve sonucu $3/6$ dedi. Doğrusu paydada $a+b+c=2+2+1=5$ olduğu için $3/5=0{,}6$'dır. Yalnızca $d$ (iki noktada da 0 olan 2 nitelik) çıkarılır.
- Hoca birinci kümede "3 sports" dedi. Slayttaki değer 20'dir (250 / 20 / 10).
- Küme sıkılığını gösteren metrik küme içi (intra-cluster) uzaklıktır. Hoca bunu da bir yerde "inter-cluster" diye söyledi.
- Uzaklık stratejileri listesinde centroid için "iki kümenin uzaklığını hesaplar" dendi. Açıkçası iki küme merkezi (centroid) arasındaki uzaklıktır.
- Doğal dil sorusu alan arama motoru olarak anılan site Ask Jeeves (bugün Ask.com).
- Altyazıda TF anlatımının bir kısmı (yaklaşık 01:54:30–01:55:15) bozuk. Formül slayttaki ve hocanın Türkçe tekrarındaki tanıma göre verildi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
