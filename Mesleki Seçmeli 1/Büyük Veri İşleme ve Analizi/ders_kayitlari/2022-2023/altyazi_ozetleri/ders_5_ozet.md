# Ders 5 Çalışma Özeti

## Genel Konular

- Ders 29 Mart 2023 Çarşamba günü online yapıldı.
- Ders büyük ölçüde İngilizce anlatıldı. Bazı kısımlar Türkçe tekrar edildi.
- Konu: 7. bölüm (chapter 7), büyük veri kümelerinde kümeleme (clustering).
- İşlenen konular:
  - Kümelemenin tanımı ve neden zor olduğu.
  - Uygulama örnekleri: gök cisimleri, müzik CD'leri, dokümanlar.
  - Uzaklık ölçüleri: Jaccard, Öklid (Euclidean), kosinüs (cosine).
  - Hiyerarşik kümeleme (hierarchical clustering): birleştirici (agglomerative) ve bölücü (divisive).
  - Merkez (centroid) ve küme temsilcisi (clustroid).
  - Durma koşulu ve küme kalitesi: sıkılık (cohesion), çap (diameter), yarıçap (radius), yoğunluk.
  - Atama tabanlı kümeleme (point assignment): K-means, $k$ seçimi, başlangıç noktalarının seçimi.
  - Büyük veri için BFR (Bradley-Fayyad-Reina) algoritması ve Mahalanobis uzaklığı.
  - CURE algoritması.
- Gelecek hafta ders yok. Vize ve dönem projesi duyuruları yapıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Kümeleme gözetimsiz öğrenmedir (unsupervised learning).** Amaç verinin altındaki yapıyı ve bölümleri (segment) bulmaktır.
- **Kümelemeyi zorlaştıran üç şey:**
  - Gerçek verilerde kümeler birbirine çok yakındır.
  - Veri çok boyutludur. Yüksek boyutta neredeyse bütün nokta çiftleri birbirine benzer uzaklıktadır.
  - Veri tek bilgisayarın belleğine sığmaz.
- **Hiyerarşik kümeleme bellek içi (in-memory) bir algoritmadır.** İyi sonuç verir, iç içe geçmiş yapıları da bulabilir. Ama zaman karmaşıklığı yüksektir ve bütün verinin bellekte olmasını ister. Büyük veride doğrudan kullanılamaz.
- **Merkez hesaplanırken yalnız o kümedeki noktalar kullanılır.** Bütün veri kümesi kullanılmaz. Bu, derste bir öğrencinin sorusu üzerine açıklandı.
- **K-means ve BFR yalnız Öklid uzayında çalışır.** Öznitelik değerleri sayısal olmalıdır.
- **BFR'nin ek varsayımı:** Her kümede, her boyutta veriler merkez etrafında normal dağılır.
- **BFR'de bellekte ham nokta değil, özet istatistik tutulur.** Bir küme için $2d + 1$ sayı yeterlidir.
- **CURE, BFR'nin normal dağılım varsayımını kaldırır.** Kümeler her biçimde olabilir.
- **Gelecek hafta (5 Nisan) ders yok.** Hoca konferansa katılacak.
- **Sonraki ders (12 Nisan) önemli.** Dönem projesi ve vize konuşulacak. Hoca bu derse mutlaka katılmayı istedi.

## Kısa Tekrar Notları

- **Kümeleme tanımı:** Aralarında bir uzaklık kavramı tanımlı noktaları gruplara ayırmak. Aynı kümedeki noktalar birbirine yakın, farklı kümelerdekiler uzak olmalı.
- **Uzaklık ölçüleri:**
  - Jaccard: kümeler için, $1 - \dfrac{|A \cap B|}{|A \cup B|}$.
  - Öklid: sayısal vektörler için.
  - Kosinüs: vektörler arasındaki açıya dayanır.
- **Birleştirici hiyerarşik kümeleme:** Her nokta tek başına bir kümedir. En yakın iki küme tekrar tekrar birleştirilir. Bu sırada bir dendrogram oluşur.
- **Bölücü hiyerarşik kümeleme:** Bütün veri tek kümedir. Küme yinelemeli olarak alt kümelere bölünür. Yaygın olan birleştirici yöntemdir.
- **Clustroid:** Öklid dışı uzayda merkez hesaplanamaz. Kümedeki noktalardan diğerlerine en yakın olan seçilir.
- **Hiyerarşik kümelemenin karmaşıklığı:** Basit uygulamada $O(n^3)$. Dikkatli uygulamada $O(n^2 \log n)$.
- **K-means adımları:**
  1. $k$ başlangıç noktası seçilir.
  2. Her nokta en yakın merkezin kümesine atanır.
  3. Merkezler güncellenir.
  4. Noktalar kümeler arasında yer değiştirmeyene ve merkezler sabitlenene kadar 2-3 tekrarlanır.
- **K-means karmaşıklığı:** Her turda $O(kN)$. Toplam süre bunun tur sayısıyla çarpımıdır. Tur sayısı büyük olabilir.
- **BFR özet istatistikleri:** $N$, $\text{SUM}$, $\text{SUMSQ}$.
- **BFR kümeleri:** Discard set (DS), compression set (CS), retained set (RS).
- **Mahalanobis uzaklığı:** $d(p, c) = \sqrt{\sum_{i=1}^{d} \left( \dfrac{p_i - c_i}{\sigma_i} \right)^2}$.
- **CURE:** Örnek üzerinde hiyerarşik kümeleme, her kümeden birbirinden uzak temsilci noktalar, temsilcileri merkeze doğru kaydırma, sonra bütün veriyi en yakın temsilciye atama.

## Detaylı Açıklamalar

### Uygulama örnekleri

- **Gök cisimleri.** Yaklaşık 2 milyar gök cismi, her biri 7 boyutlu ışınım vektörüyle temsil ediliyor. Kümeleme yıldızları, galaksileri vb. ayırır. (Slayttaki sayı ile hocanın söylediği sayı arasında "million/billion" karışıklığı var; kaynak kitapta 2 milyar.)
- **Müzik CD'leri.** Her CD, onu satın alan müşteriler kümesiyle temsil edilir. Kümeleme benzer müzik zevkine sahip müşteri gruplarını verir.
- **Dokümanlar.** Her doküman içerdiği kelimeler kümesiyle temsil edilir. Aynı konudaki dokümanlar gruplanır. Tersi de yapılabilir: aynı dokümanlarda birlikte geçen kelimeler gruplanır.

### Hiyerarşik kümelemede üç soru

1. Çok noktalı bir küme nasıl temsil edilir?
2. İki kümenin yakınlığı nasıl ölçülür?
3. Birleştirmeye ne zaman son verilir?

- **Öklid uzayında:**
  - Küme, merkeziyle (centroid) temsil edilir. Merkez, kümedeki noktaların boyut boyut ortalamasıdır.
  - Kümeler arası uzaklık, merkezler arası uzaklıktır.
- **Öklid dışı uzayda:**
  - Merkez hesaplanamaz. Küme, clustroid ile temsil edilir.
  - Clustroid seçim ölçütleri: diğer noktalara en büyük uzaklığı en küçük olan, ortalama uzaklığı en küçük olan ya da uzaklıklarının kareleri toplamı en küçük olan nokta.
  - Kümeler arası uzaklık hesaplanırken clustroid merkez gibi kullanılır.

### Birleştirici kümeleme örneği

- 6 nokta ile başlanır. Her nokta bir kümedir.
- Her adımda bütün küme çiftlerinin uzaklığı hesaplanır. En yakın iki küme birleştirilir.
- 1. adım: $(1, 2)$ ve $(2, 1)$ birleşir. Yeni merkez $(1.5, 1.5)$.
- 2. adım: $(4, 1)$ ve $(5, 0)$ birleşir.
- 3. adım: Tek noktalı bir küme ile iki noktalı küme birleşir. Üç noktalı kümenin merkezi $(1, 1)$ olur.
- Sonraki adımlar tek bir küme kalana kadar sürer.
- Dendrogramda x ekseni noktaları, y ekseni birleşme sırasını (zamanı) gösterir. Sonra olan birleşme daha yukarıda çizilir.
- Kümeler büyüdükçe merkez hesabı uzar. BFR'de görülecek özet istatistikler merkezi her seferinde baştan hesaplamadan bulmayı sağlar.

### Durma koşulu ve küme kalitesi

- **Kaliteye göre durma.** Her birleştirmeden sonra küme kalitesi hesaplanır. Kalite düşmeye başladığında durulur. Veri hakkında ön bilgi gerekmez.
- **Küme sayısına göre durma.** Veride $k$ küme olduğu biliniyorsa $k$ küme kalınca durulur. Ön bilgi gerekir.
- **Sıkılık (cohesion) ölçüleri:**
  - Çap (diameter): Kümedeki iki nokta arasındaki en büyük uzaklık.
  - Yarıçap (radius): Bir noktanın merkeze en büyük uzaklığı.
  - Yoğunluk (density): Kümedeki nokta sayısının çapa ya da yarıçapa bölümü.

### K-means örneği ve $k$ seçimi

- 11 nokta, $k = 2$.
- Algoritma iki noktayı başlangıç merkezi seçer. 1. turda 3 nokta bir kümeye, kalanlar diğerine atanır.
- Merkezler yeniden hesaplanır, noktalar yeniden atanır. 4. turda merkezler değişmediği için algoritma yakınsar.
- **$k$ bilinmiyorsa:** $k = 2, 3, 4, \dots$ denenir. Her biri için küme kalitesi hesaplanır.
  - Örnekte veride açıkça 3 küme var. $k = 2$ iken kümelerin çapı büyük, kalite kötü.
  - $k = 3$ iken çaplar küçülür, kalite çok iyileşir.
  - $k$ arttıkça merkeze ortalama uzaklık düşer. Bir noktadan sonra düşüş küçülür. Düşüşün belirgin biçimde yavaşladığı $k$ seçilir.
- **Başlangıç noktalarını seçme:**
  - Örnekleme: Belleğe sığan bir örnek hiyerarşik yöntemle kümelenir. Hiyerarşik yöntem $k$ istemez. Her kümenin merkezine en yakın nokta başlangıç noktası olur.
  - Dağınık noktalar: İlk nokta rastgele seçilir. Sonraki her nokta, seçilmiş noktalardan en uzak olandır. $k$ nokta olana kadar sürer.
- Başlangıç noktaları algoritmanın çalışma süresini etkiler.

### BFR algoritması

- K-means'in belleğe sığmayan veri için uyarlanmış hâlidir. Örnek: 1 TB veri, 16 GB bellek.
- Varsayımlar: Öklid uzayı. Her küme, her boyutta merkez etrafında normal dağılır.
- Normal dağılım hatırlatması: $\pm 1\sigma$ içinde verinin yaklaşık %68'i, $\pm 2\sigma$ içinde %95'i bulunur.
- **Adımlar:**
  1. Veri belleğe sığan parçalara (segment) bölünür.
  2. İlk parça belleğe alınır. Bellek içi bir algoritmayla, genellikle hiyerarşik kümelemeyle, $k$ başlangıç kümesi bulunur.
  3. Noktalar üç gruba ayrılır:
     - **Discard set (DS):** Büyük kümelere giren noktalar. Bellekte tutulmaz, yalnız istatistikleri tutulur.
     - **Compression set (CS):** Birbirine yakın ama büyük kümelere girmeyen küçük alt kümeler.
     - **Retained set (RS):** Hiçbir kümeye girmeyen tek noktalar.
  4. Sonraki her parça belleğe alınır. Her nokta merkezlere uzaklığına göre değerlendirilir. Yeterince yakınsa ilgili DS kümesine eklenir, istatistikler güncellenir, nokta atılır. Değilse bellekte kalır.
  5. CS alt kümelerinin birleşip birleşemeyeceği her adımda kontrol edilir.
  6. Bütün parçalar bitince kalan CS ve RS noktaları en yakın kümelere katılır.
- **Her DS kümesi için tutulan istatistikler ($d$ boyutlu veri):**
  - $N$: Kümedeki nokta sayısı.
  - $\text{SUM}$: $d$ boyutlu vektör. $i$. bileşeni noktaların $i$. koordinatlarının toplamı.
  - $\text{SUMSQ}$: $d$ boyutlu vektör. $i$. bileşeni noktaların $i$. koordinatlarının karelerinin toplamı.
  - Toplam $2d + 1$ sayı.
- **İstatistiklerden hesaplananlar:**
  - Merkez: $c_i = \dfrac{\text{SUM}_i}{N}$.
  - Varyans: $\sigma_i^2 = \dfrac{\text{SUMSQ}_i}{N} - \left( \dfrac{\text{SUM}_i}{N} \right)^2$. Standart sapma bunun kareköküdür.
- Yeni nokta eklenince $N$ bir artar. Noktanın koordinatları $\text{SUM}$'a, karesi $\text{SUMSQ}$'a eklenir.

### Mahalanobis uzaklığı ve eşik

- Nokta $p = (p_1, \dots, p_d)$, küme merkezi $c = (c_1, \dots, c_d)$, standart sapmalar $\sigma_1, \dots, \sigma_d$.
- Normalleştirilmiş fark: $y_i = \dfrac{p_i - c_i}{\sigma_i}$.
- Uzaklık: $\sqrt{\sum_i y_i^2}$.
- Nokta, uzaklığı eşiğin altında kalan en yakın kümeye atanır.
- **Eşik seçimi:**
  - Nokta her boyutta merkezden $1\sigma$ uzaksa bütün $y_i = 1$ olur. Uzaklık $\sqrt{d}$.
  - Her boyutta $2\sigma$ uzaksa uzaklık $2\sqrt{d}$, $3\sigma$ uzaksa $3\sqrt{d}$.
  - Eşik olarak örneğin $3\sqrt{d}$ seçilebilir.

### CURE algoritması

- Öklid uzayı varsayar, çünkü merkez hesaplar. Ama kümelerin normal dağılmasını istemez. Kümeler her biçimde olabilir.
- Örnek: Birbirine geçmiş iki küme.
- **1. aşama:**
  1. Belleğe sığan rastgele bir örnek alınır.
  2. Örnek hiyerarşik kümelemeyle kümelenir.
  3. Her kümeden birbirinden olabildiğince uzak $k$ temsilci nokta seçilir (örnekte 4).
  4. Her temsilci, merkeze doğru sabit bir oranda kaydırılır (örnekte %20).
- **2. aşama:**
  - Bütün veri yeniden taranır.
  - Her nokta, en yakın temsilci noktanın kümesine atanır.
  - Örnekte 3 küme × 4 temsilci = 12 temsilci noktaya uzaklık hesaplanır.

### Duyurular

- 5 Nisan'da ders yok. Hoca konferansa katılacak.
- 12 Nisan'daki derste dönem projesi, vizeden önceki ek bir konu ve vize konuşulacak.
- Vize bu dersten üç hafta sonra, dönemin 8. haftasında.
- Ders slaytları (Clustering, Hierarchical Clustering, K-Means, BFR, CURE) dersin web sayfasında.
- Sorular e-postayla sorulabilir.

### Ders sonrası notlar

- **Kosinüs uzaklığı.** Hoca "iki vektör arasındaki kosinüs sıfırsa tam eşleşme var" dedi. Doğrusu: Açı sıfır, yani kosinüs **1** ise vektörler aynı yöndedir. Bu durumda kosinüs uzaklığı sıfırdır. Kosinüs sıfırsa vektörler diktir.
- **Normal dağılım.** Hoca $3\sigma$ için "sanırım %98" dedi. Doğru değer yaklaşık %99.7.
- **Hiyerarşik kümeleme karmaşıklığı.** Altyazıda "n log n çarpı n kare" geçiyor. Doğrusu $O(n^2 \log n)$.
- **$k$ seçiminde kalite ifadesi.** Hoca bir yerde "$k = 3$ için cohesion değeri küçük olur" dedi. Burada kastedilen merkeze ortalama uzaklık ya da çaptır; bunun küçük olması kalitenin iyi olduğunu gösterir. Grafikte y ekseni "merkeze ortalama uzaklık"tır ve $k$ arttıkça azalır.
- **Dağınık nokta seçimi.** Doğru ölçüt: Yeni nokta, seçilmiş noktalara olan en küçük uzaklığı en büyük olan noktadır.
- **Birleştirici kümeleme örneği.** Koordinatlar hocanın derste okuduğu değerlerdir. Altyazıda ilk merkez önce "1.1" diye geçiyor; $(1, 2)$ ile $(2, 1)$'in ortalaması $(1.5, 1.5)$'tir.
- **Kayıttaki eksikler.** Hiyerarşik kümelemenin üç sorusunun anlatıldığı kısım ve bazı Türkçe açıklamalar altyazıda bozuk. Bu kısımlar kitaptaki standart tanıma göre verildi.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
