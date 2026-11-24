# Ders 10 Genişletilmiş Notu: Hiyerarşik Kümeleme, Kümeleme Kalitesi ve Weka ile Uygulama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Eğiticisiz Kümelemeye Dönüş ve Ödevden Akademik Bir Hatırlatma
- 2. Hiyerarşik Kümeleme: Agglomerative ve Divisive Yaklaşımlar
- 3. Kümeler Arası Uzaklık Ölçüleri
- 4. Çözümlü Örnek: Single ve Complete Linkage
- 5. Uzaklık Yerine Benzerlik Matrisi
- 6. Varyans ve Centroid Yöntemleri (Ward Yöntemi)
- 7. Kümeleme Kalitesi: İç ve Dış Ölçütler, Saflık
- 8. Büyük Veride Maliyet: KD-Tree
- 9. Weka ile Uygulama
- Örnek Sorular

## 1. Eğiticisiz Kümelemeye Dönüş ve Ödevden Akademik Bir Hatırlatma

Önceki derste eğiticisiz (unsupervised) kümeleme algoritmalarına başlanmıştı. Eğiticisiz kümelemede verinin sınıf etiketi yoktur; örnekler (sample) birbirlerine olan benzerliklerine bakılarak gruplanır. İlk yöntem olarak k-means kümeleme görülmüştü. Bu derste ikinci yöntem olan hiyerarşik kümeleme anlatılır, ardından bir soru çözülür ve son bölümde Weka aracının kullanımı gösterilir.

Derse başlarken sınıflandırma uygulamalarında sık yapılan hatalarla ilgili iki akademik nokta öne çıktı:

- **X ve Y gösterimi:** $X$ değişkeni her örneğin sahip olduğu öz nitelikleri, $Y$ ise o örneklerin sınıf etiketlerini tutar. Bu, bütün kaynaklarda kullanılan bir kuraldır. Örneğin `X_train` 800 örnek ve 4 öz nitelikten oluşan bir blok olabilir; `y_train` bu 800 örneğin hangi sınıfa ait olduğunu gösterir. Sınıf etiketlerini $X$ içinde tutmak bir hatadır.
- **Doğruluk hesabında test kümesi boyutu:** Veri %80 eğitim, %20 test olarak bölündüyse ve toplam 1000 örnek varsa test kümesinde 200 örnek olur. Veri başka bir oranla (örneğin %25 ya da %30) yeniden bölünüp doğruluk yine "doğru sayısı / 200" diye hesaplanırsa sonuç yanlış olur. Doğruluk, doğru sınıflanan örnek sayısının **o test kümesindeki** örnek sayısına bölümüdür. Ayrıca iki yöntemin başarısını karşılaştırmak için aynı bölünmüş veriyi ya da aynı bölme oranını kullanmak gerekir.

## 2. Hiyerarşik Kümeleme: Agglomerative ve Divisive Yaklaşımlar

Bu bölümün anlatımı büyük ölçüde İngilizce yapıldı. Slayttaki tanım şöyledir (ekrandan, 00:25:00): hiyerarşik kümeleme yöntemi nesneleri bir **küme ağacı** (tree of clusters) şeklinde gruplar. Hiyerarşik ayrıştırmanın aşağıdan yukarıya (birleştirerek, bottom-up, merging) ya da yukarıdan aşağıya (bölerek, top-down, splitting) yapılmasına göre yöntemler ikiye ayrılır:

- **Agglomerative (birleştirici):** aşağıdan yukarı strateji.
- **Divisive (bölücü):** yukarıdan aşağı strateji.

### 2.1 Yöntemlerin sınıflandırılması

Derste gösterilen diyagram (ekrandan, 00:45:00) şu yapıdadır:

```text
Hierarchical
├── Agglomerative
│   ├── Linkage Methods
│   │   ├── Single Linkage
│   │   ├── Complete Linkage
│   │   └── Average Linkage
│   ├── Variance Methods
│   │   └── Ward's Method
│   └── Centroid Methods
└── Divisive
```

### 2.2 Atomik kümeler ve agglomerative yaklaşım

Agglomerative yaklaşım **atomik kümelerle** başlar. Atomik küme, içinde yalnız bir örnek bulunan kümedir. Veri setinde 10 örnek varsa başlangıçta 10 atomik küme vardır. Sonra kümeler arasındaki benzerlik (ya da uzaklık) hesaplanır, en benzer iki küme birleştirilir ve bu işlem tekrarlanır. Sonunda bütün örnekler tek bir kümede toplanır.

### 2.3 AGNES ve DIANA örneği

Slayttaki örnekte beş nesneli bir veri seti $\{a,b,c,d,e\}$ vardır (ekrandan, 00:30:00). Agglomerative çözüm **AGNES** (Agglomerative Nesting), divisive çözüm **DIANA** (Divisive Analysis) diye adlandırılır. Örnekte öz niteliklerin sayısal değerleri verilmemiştir; benzerliklerin hesaplandığı ve şu birleşmelerin bulunduğu varsayılır:

| AGNES adımı | Oluşan küme |
|---|---|
| Adım 0 | $\{a\},\{b\},\{c\},\{d\},\{e\}$ (atomik kümeler) |
| Adım 1 | $\{a,b\}$ |
| Adım 2 | $\{d,e\}$ |
| Adım 3 | $\{c,d,e\}$ |
| Adım 4 | $\{a,b,c,d,e\}$ |

DIANA aynı diyagramı ters yönde izler: adım 0'da bütün örnekler tek kümededir ve bölme işlemleriyle adım 4'te atomik kümelere inilir.

Ağacın tamamının kurulması gerekmez. Bir **durma koşulu** (termination condition) ya da eşik değeri kullanılabilir. Örneğin "yalnız iki küme elde edilsin" denirse AGNES adım 3'ün sonunda durdurulur ve $\{a,b\}$ ile $\{c,d,e\}$ kümeleri elde edilir.

<!-- BELİRSİZ: 00:29:35-00:30:55 ve 00:32:30-00:33:38 arasındaki anlatım altyazıda tekrar halüsinasyonuna dönüşmüş; içerik slayttaki diyagramdan kuruldu. -->

### 2.4 Dendrogram

Birleştirme işlemlerinin sonunda elde edilen ağaç diyagramına **dendrogram** denir. En altta tek örnekli atomik kümeler bulunur; bunlar benzerliklerine göre birleştirilir, yeni örnekler eklenir ve daha büyük kümeler oluşur. Dendrogram her birleştirmenin hangi benzerlik (uzaklık) düzeyinde yapıldığını gösterir.

AGNES slaytında (ekrandan, 00:35:00) yöntem şöyle özetlenir: başlangıçta her nesne kendi kümesine konur; kümeler bir ölçüte göre adım adım birleştirilir. Örneğin $C_1$'deki bir nesne ile $C_2$'deki bir nesne, farklı kümelerden alınabilecek herhangi iki nesne arasında en küçük Öklid uzaklığını oluşturuyorsa $C_1$ ve $C_2$ birleştirilebilir. Bu, **single linkage** yaklaşımıdır: iki küme arasındaki benzerlik, farklı kümelere ait en yakın veri noktası çiftinin benzerliğiyle ölçülür.

## 3. Kümeler Arası Uzaklık Ölçüleri

İki örnek arasındaki uzaklığı ya da benzerliği ölçmek kolaydır. Asıl soru şudur: içlerinde birden çok örnek bulunan iki küme arasındaki uzaklık nasıl ölçülür? Bunun için dört yaygın ölçü verildi: minimum uzaklık, maksimum uzaklık, ortalama (mean) uzaklık ve ortalama çift (average) uzaklığı.

- **Minimum uzaklık:** Küme 1'deki örneklerle küme 2'deki örnekler arasındaki uzaklıklardan en küçüğü alınır; yani iki kümenin birbirine en yakın örnekleri kullanılır. Bu ölçüyle yapılan hiyerarşik kümeleme **single linkage** diye adlandırılır.
- **Maksimum uzaklık:** En uzak iki örnek arasındaki uzaklık alınır. Bu çözüm **complete linkage** diye adlandırılır.
- **Ortalama (average) uzaklık:** İki kümedeki örneklerin bütün çiftleri arasındaki uzaklıkların ortalamasıdır. Her kümede iki örnek varsa $2 \times 2 = 4$ uzaklık hesaplanır ve bunların ortalaması alınır. Bu çözüm **average linkage**'tır.
- **Ortalama (mean) uzaklık:** Her kümenin merkezi (centroid) bulunur ve merkezler arasındaki uzaklık ölçülür. Bu, centroid yönteminin kullandığı ölçüdür.

Slayttaki şekilde (ekrandan, 00:40:00) single linkage için iki kümenin en yakın iki noktası, complete linkage için en uzak iki noktası, average linkage için bütün nokta çiftleri birleştirilerek gösterilmiştir.

**Soru:** Kümeler arası uzaklığı ölçmek için başka ne önerirsiniz?
**Cevap:** Bir öğrenci küme merkezlerini kullanmayı önerdi. Bu, dördüncü ölçü olan mean distance (merkezler arası uzaklık) yaklaşımıdır.

### 3.1 Minimum ve maksimum uzaklığın zayıf yanı

Minimum ve maksimum ölçüler her kümenin **uç noktalarını** kullanır. Bu yüzden aykırı değerlere (outlier) ve gürültülü veriye çok duyarlıdır; bir kümenin kenarındaki tek bir aykırı nokta kümeler arası uzaklığı belirleyebilir ve gerçekçi olmayan bir sonuç verebilir. Bu duyarlılıktan kaçınmak için minimum ya da maksimum uzaklık yerine ortalama (average) ya da merkez (mean) uzaklığı tercih edilebilir.

<!-- BELİRSİZ: 00:42:26-00:44:24 arasındaki açıklamanın bir kısmı altyazıda tekrar halüsinasyonudur; yukarıdaki özet okunabilen cümlelerden kuruldu. -->

## 4. Çözümlü Örnek: Single ve Complete Linkage

Soru, çevrim içi beyaz tahtada verildi (ekrandan, 00:50:00): "Consider the distance matrix. Cluster five samples using each of the following solutions: a) single linkage, b) complete linkage."

Beş örnek arasındaki uzaklıkları gösteren 5×5 simetrik uzaklık matrisi (alt üçgeni yazılmıştır):

$$
D_{5\times 5} =
\begin{bmatrix}
0 & & & & \\
9 & 0 & & & \\
3 & 7 & 0 & & \\
6 & 5 & 9 & 0 & \\
11 & 10 & 2 & 8 & 0
\end{bmatrix}
$$

Satır ve sütunlar $S_1, \dots, S_5$ örneklerini gösterir. Köşegen üzerindeki sıfırlar her örneğin kendisine uzaklığıdır. Matris simetrik olduğu için yalnız alt üçgen yazılmıştır.

### 4.1 Single linkage (minimum uzaklık)

Single linkage'ta iki küme arasındaki uzaklık, iki kümenin birbirine en yakın örnekleri arasındaki uzaklıktır. Dendrogram için yatay bir uzaklık ekseni çizilir (ekrandan, 01:05:00 ve 01:10:00).

1. **Adım:** Köşegen dışındaki en küçük değer aranır: $d(S_3,S_5)=2$. İlk birleşme $\{S_3,S_5\}$, uzaklık 2 düzeyinde.
2. **Adım:** Sonraki en küçük değer $d(S_1,S_3)=3$. $S_1$'in $\{S_3,S_5\}$ kümesine uzaklığı $\min(d(S_1,S_3), d(S_1,S_5)) = \min(3, 11) = 3$. $S_1$ bu kümeye 3 düzeyinde katılır: $\{S_1,S_3,S_5\}$.
3. **Adım:** Sonraki en küçük değer $d(S_2,S_4)=5$. İki atomik küme 5 düzeyinde birleşir: $\{S_2,S_4\}$.
4. **Adım:** Elde iki küme kalır: $\{S_1,S_3,S_5\}$ ve $\{S_2,S_4\}$. Matristeki 5'ten sonraki en küçük değer $d(S_1,S_4)=6$'dır; $S_1$ birinci, $S_4$ ikinci kümededir. Bu iki küme arasındaki en yakın çift budur, son birleşme 6 düzeyindedir.

| Birleşme | Uzaklık düzeyi |
|---|---|
| $S_3 + S_5$ | 2 |
| $S_1 + \{S_3,S_5\}$ | 3 |
| $S_2 + S_4$ | 5 |
| $\{S_1,S_3,S_5\} + \{S_2,S_4\}$ | 6 |

**Soru:** Örnek numaralarının $S_0$'dan başlaması gerekmez mi?
**Cevap:** Gerekmez; matriste örnekler 1'den 5'e numaralandırılmıştır.

### 4.2 Complete linkage (maksimum uzaklık)

Complete linkage'ta kümeler arasındaki uzaklık, iki kümenin içinde **birbirine en uzak** iki örnek arasındaki uzaklıkla tanımlanır. Ancak hangi iki kümenin birleştirileceğine karar verilirken bütün bu uzaklıklar yazıldıktan sonra **en küçüğü**, yani en benzer olan çift seçilir.

> **Hocanın vurgusu:** Complete linkage'ta uzaklık maksimumla hesaplanır, ama birleştirme yine en küçük uzaklığa sahip çift için yapılır. Burada bir "trik" var, dikkat edin.

1. **Adım:** En küçük değer yine $d(S_3,S_5)=2$. $\{S_3,S_5\}$, 2 düzeyinde birleşir.
2. **Adım:** Kalan kümelerin $\{S_3,S_5\}$'e uzaklıkları maksimumla yazılır (ekrandan, 01:15:00):
   - $d(S_1,\{S_3,S_5\}) = \max(3, 11) = 11$
   - $d(S_4,\{S_3,S_5\}) = \max(9, 8) = 9$
   - $d(S_2,\{S_3,S_5\}) = \max(7, 10) = 10$
   - Atomik kümeler arasında: $d(S_1,S_2)=9$, $d(S_2,S_4)=5$, $d(S_1,S_4)=6$.

   En küçüğü $d(S_2,S_4)=5$ olduğu için $\{S_2,S_4\}$, 5 düzeyinde birleşir.

> **Ders sonrası not:** Hoca bu adımda $S_2$'nin $\{S_3,S_5\}$ kümesine uzaklığını sözlü olarak 11 diye söyledi; matriste $d(S_2,S_5)=10$ olduğundan doğrusu $\max(7,10)=10$'dur. Sonraki adımda hoca da $\{S_2,S_4\}$ ile $\{S_3,S_5\}$ arası uzaklığı 10 olarak aldı. Sonuç değişmez.

3. **Adım:** Elde üç küme vardır: $\{S_1\}$, $\{S_3,S_5\}$, $\{S_2,S_4\}$.
   - $d(S_1,\{S_3,S_5\}) = 11$
   - $d(S_1,\{S_2,S_4\}) = \max(9, 6) = 9$
   - $d(\{S_2,S_4\},\{S_3,S_5\}) = \max(7, 10, 9, 8) = 10$

   En küçüğü 9'dur; $S_1$, $\{S_2,S_4\}$ kümesine 9 düzeyinde katılır: $\{S_1,S_2,S_4\}$.
4. **Adım:** Son iki küme $\{S_1,S_2,S_4\}$ ve $\{S_3,S_5\}$ arasındaki uzaklık en uzak çift olan $d(S_1,S_5)=11$'dir. Son birleşme 11 düzeyindedir.

| Birleşme | Uzaklık düzeyi |
|---|---|
| $S_3 + S_5$ | 2 |
| $S_2 + S_4$ | 5 |
| $S_1 + \{S_2,S_4\}$ | 9 |
| $\{S_1,S_2,S_4\} + \{S_3,S_5\}$ | 11 |

Her iki çözümün birleşme sırası ve düzeyleri python ile tekrar hesaplanarak doğrulandı.

### 4.3 Durma koşulu: eşik 5.5

Durma koşulu olarak uzaklık ekseninde 5.5 eşik değeri seçildiğini varsayalım (ekrandan, 01:25:00). Eşik değerinden dikey bir çizgi çekilir; çizginin dendrogramı kestiği her nokta bir kümeye karşılık gelir.

- **Complete linkage:** Çizgi dendrogramı üç yerden keser ("Th = 5.5 ⇒ 3 clusters"). Kümeler: $\{S_3,S_5\}$, $\{S_2,S_4\}$ ve tek başına $\{S_1\}$.
- **Single linkage:** Aynı eşik dendrogramı iki yerden keser. Kümeler: $\{S_1,S_3,S_5\}$ ve $\{S_2,S_4\}$.

**Soru:** Complete linkage'ta $S_1$ hem $\{S_3,S_5\}$ hem de $\{S_2,S_4\}$ kümesine eşit uzaklıkta olsaydı nasıl karar verirdik?
**Cevap:** O durumda hepsi aynı düzeyde, aynı noktada birleşirdi. Böyle bir durum zaman zaman ortaya çıkabilir.

## 5. Uzaklık Yerine Benzerlik Matrisi

Hoca öğrencilere bir düşünme sorusu sordu: verilen matris bir uzaklık matrisi değil de bir **benzerlik (similarity) matrisi** olsaydı ne değişirdi?

Öz nitelikler sayısal değil de kategorik, özellikle ikili (0/1) ise örnekler arasında **SMC** (Simple Matching Coefficient) ya da **Jaccard** benzerliği gibi ölçüler kullanılır. Örneğin $SMC(S_1,S_3)$ hesaplanır; bütün çiftler için bu yapılınca bir $S$ matrisi oluşur (ekrandan, 01:30:00). 5×5 bir benzerlik matrisinde köşegen üzerindeki değerler bu kez 1'dir, çünkü her örneğin kendisine benzerliği 1'dir.

**Soru:** Single linkage uzaklık matrisinde minimum uzaklığı kullanmak demekti. Benzerlik matrisinde ne demektir?
**Cevap:** Benzerlik matrisinde yaklaşım tersine döner: en yüksek benzerlik kullanılır ve en büyük değerler birleştirilir. Bir öğrencinin önerdiği gibi benzerlikler uzaklığa dönüştürülüp (örneğin 1'den çıkarılarak) aynı işlemler uzaklık matrisi üzerinde de yapılabilir; ama benzerlik matrisi üzerinde doğrudan da çözülebilir.

Hocaya göre single linkage'ı benzerlik matrisi üzerinde kurgulamak kolaydır; complete linkage'ı benzerlik matrisi üzerinde kurgulamak ise zordur ve derste bu konuya girilmedi.

**Soru:** Kümeler arası uzaklık için merkezleri kullansaydık bu complete linkage olur muydu?
**Cevap:** Hayır. Merkezler arası uzaklık mean distance (centroid yaklaşımı) olur; complete linkage maksimum uzaklığı kullanır.

## 6. Varyans ve Centroid Yöntemleri (Ward Yöntemi)

Agglomerative yöntemlerin ikinci ve üçüncü grubu varyans yöntemleri ve centroid yöntemleridir. Centroid yöntemi, kümeler arası uzaklığı küme merkezleri arasındaki uzaklıkla (mean distance) ölçen çözümdür.

### 6.1 Küme içi varyans

Varyans yöntemi, kümeler birleştirildiğinde oluşacak yeni kümenin **küme içi varyansını** (within-cluster variance) en küçük yapacak şekilde kümeler üretir.

**Soru:** Küme içi varyans nasıl ölçülür?
**Cevap:** Önce kümedeki örneklerin ortalaması alınarak küme merkezi (mean) bulunur. Her örneğin bu merkeze uzaklığının karesi alınıp toplanır ve örnek sayısına bölünür; bu varyanstır. Karekökü alınırsa standart sapma elde edilir:

$$
\sigma^2_{C} = \frac{1}{n}\sum_{x \in C} \lVert x - \mu_C \rVert^2
$$

**Soru:** Küme içi varyansın küçük çıkması ne anlama gelir?
**Cevap:** Bir öğrenci varyans yüksekse örneklerin dağınık olacağını söyledi. Yüksek varyans, örneklerin merkezden uzaklaşıp dışarıya saçıldığı anlamına gelir. Küçük varyans ise örneklerin merkez etrafında derli toplu, birbirine yakın olduğunu gösterir. İyi bir kümenin göstergesi küçük küme içi varyanstır.

### 6.2 Ward yöntemi

Ward yöntemi (Ward's procedure) her aday çift için şunu yapar: iki kümenin birleştirildiğini varsayar ve oluşacak kümenin küme içi varyansını hesaplayıp kenara koyar. Sonra birleştirilebilecek başka bir çift için aynı hesabı yapar. Sonunda, birleştirme sonrasında **en küçük varyansı** verecek iki kümeyi birleştirir. Slaytta Ward yönteminde her örneğin kendi küme merkezine bağlandığı, centroid yönteminde ise iki kümenin merkezlerinin birbirine bağlandığı gösterilmiştir (ekrandan, 01:35:00).

Mantığı güzel bir yöntemdir, ama işlem karmaşıklığı yüksektir.

## 7. Kümeleme Kalitesi: İç ve Dış Ölçütler, Saflık

Şimdiye kadar iki kümeleme algoritması görüldü: k-means ve hiyerarşik kümeleme. Bu yöntemlerin sonunda kümelemenin ne kadar doğru yapıldığının nasıl ölçüleceği sorusu ortaya çıkar: iyi bir kümeleme nedir?

### 7.1 İç ölçütler (internal criteria)

İki ölçüm vardır: **küme içi benzerlik** (intra-class similarity) ve **kümeler arası benzerlik** (inter-class similarity). Beklenen, küme içindeki örneklerin birbirine benzerliğinin yüksek, iki küme arasındaki benzerliğin ise düşük olmasıdır. Oluşan kümeler üzerinde bu ölçümler yapılarak başarı değerlendirilebilir.

### 7.2 Dış ölçütler (external criteria)

Slayttaki tanıma göre (ekrandan, 01:40:00) dış ölçütlerde kalite, kümelemenin "altın standart" (gold standard) verideki gizli örüntüleri ya da sınıfları bulma yeteneğiyle ölçülür. Bu değerlendirme **ground truth** gerektirir, yani etiketli veri gerekir. $C$ altın standart sınıf olduğu ve algoritmanın $n_i$ üyeli $K$ küme ($\omega_1, \omega_2, \dots, \omega_K$) ürettiği varsayılır.

Kümeleme ihtiyacı sınıf etiketlerinin olmamasından doğar. Ancak bazı uygulamalarda bir alan uzmanının etiketlediği veri vardır; bu etiketlere ground truth ("gerçek doğru") denir. Kümeleme etiketler kapalıyken yapılır; etiketler yalnız son aşamada, oluşan kümelerin doğru gruplanıp gruplanmadığını değerlendirmek için açılır. Her veri setinde böyle etiketler olmayabilir: örneğin müşteri segmentasyonunda müşterilerin segmentini kimse baştan bilmez. Bir tıbbi veri setinde ise doktorun etiketlediği veri bulunabilir.

> **Hocanın vurgusu:** Bu aşama bütün kümeleme işlemlerini değerlendirme açısından çok önemlidir; iyi dinleyin.

### 7.3 Saflık (purity) örneği

Saflık, aynı türden örneklerin ne ölçüde aynı kümeye konduğunu ölçer. Daha önceki derslerde saflığın entropiyle de ölçülebileceği görülmüştü; burada basit bir sayma yöntemi kullanılır. Bir kümenin saflığı:

$$
\text{Purity}(\omega_i) = \frac{1}{n_i}\max_j n_{ij}
$$

Burada $n_{ij}$, $i$. kümedeki $j$. sınıftan örnek sayısıdır.

Örnekte (ekrandan, 01:45:00) 17 örnekli bir veri seti bir kümeleme yöntemiyle (örneğin k-means) üç kümeye ayrılmıştır. Algoritmanın sonunda yalnız hangi örneğin hangi kümeye konduğu bilinir: birinci ve ikinci kümede 6'şar, üçüncüde 5 örnek. Sonra sınıf etiketleri açılır ve her kümedeki kırmızı, mavi, yeşil örnekler sayılır:

| Küme | Kırmızı | Mavi | Yeşil | Etiket | Saflık |
|---|---|---|---|---|---|
| Küme I | 5 | 1 | 0 | kırmızı | $\frac{1}{6}\max(5,1,0) = 5/6$ |
| Küme II | 1 | 4 | 1 | mavi | $\frac{1}{6}\max(1,4,1) = 4/6$ |
| Küme III | 2 | 0 | 3 | yeşil | $\frac{1}{5}\max(2,0,3) = 3/5$ |

Her kümenin etiketi, içindeki çoğunluk sınıfıdır. Saflık 1'e ne kadar yakınsa kümeleme o kadar başarılıdır. Toplam bir başarı ölçüsü için üç kümenin saflık değerlerinin ortalaması alınabilir.

> **Ek bilgi (derste anlatılmadı):** Kaynaklarda toplam saflık çoğunlukla küme boyutlarıyla ağırlıklı olarak, yani $\frac{1}{N}\sum_i \max_j n_{ij}$ biçiminde tanımlanır. Bu örnekte $(5+4+3)/17 = 12/17 \approx 0{,}706$ olur; üç değerin basit ortalaması ise $(5/6 + 4/6 + 3/5)/3 = 0{,}7$'dir.

### 7.4 Kaybolan sınıf sorunu

Hoca bir soru sordu: Küme II'deki 6 örnekten 3'ü kırmızı, 2'si mavi, 1'i yeşil olsaydı etiketleme nasıl yapılırdı?

Çoğunluk kuralına göre Küme I kırmızı, Küme II de kırmızı olur ve mavi sınıfa hiç küme kalmaz. Gerçek uygulamalarda karşılaşılan bir sorundur bu. Hocanın verdiği örnekte üç sınıflı bir tıbbi veri seti vardı: hormonu az olanlar, çok olanlar ve normal olanlar. Sınıf bilgisi kapatılarak üç kümeye ayrılan veride kümelerden biri "kayboluyordu"; normal gruptaki örnekler iki yana dağılıyordu.

Verinin doğasında üç sınıf varsa o sınıf yok sayılamaz. Bu durumda hata yüksek olsa da ikinci kümeye çoğunluğun etiketi değil, kaybolmasını istemediğimiz sınıfın, yani **mavinin** etiketi verilir. Saflık açısından ciddi bir bozulma olur; ama veri iç içe geçmiş ve kolay ayrılamıyorsa böyle bir tabloyla karşılaşılabilir.

**Soru:** Maviyi yok etmenin zararı nedir? Böyle daha yüksek doğruluk elde edilmez mi?
**Cevap:** Doğruluk daha yüksek çıkabilir, ama verinin doğasında üç sınıf vardır ve bir sınıfı yok etmek o sınıfı hiç tanımamak demektir. Örnekteki gibi normal çalışan grubu görmek istiyorsak, belli bir hatayla da olsa o sınıfı korumak gerekir.

**Soru:** İkinci kümeye mavi denirse bu kez kırmızı yok olmaz mı?
**Cevap:** Hayır. Kırmızı sınıf Küme I'in etiketi olarak zaten tanımlıdır. Yalnız Küme II'ye de kırmızı denmez.

**Soru:** Böyle bir durumda etiketi değiştirmek mi, yoksa yöntemi değiştirmek mi daha mantıklıdır?
**Cevap:** Yöntem değiştirmek mümkündür; örneğin k-means yerine hiyerarşik kümeleme ya da başka çözümler denenebilir. Ama yöntemleri karşılaştırabilmek için sonuçta yine bu etiketleme yorumunu yapmak gerekir. Verinin doğasında üçüncü bir grup varsa, başarısı düşük de olsa onu tahmin etmek isteriz.

## 8. Büyük Veride Maliyet: KD-Tree

Aradan sonra sohbet bölümüne yazılmış bir soru cevaplandı.

**Soru:** Ward yönteminin büyük veride uygulanabilirliği düşük müdür?
**Cevap:** İşlem karmaşıklığı yüksektir, ama maliyeti düşürmenin yolları vardır. Bunlardan biri **KD-tree** (k boyutlu ağaç) yapısıdır. İkili aramadaki mantığa benzer: 0 ile 100 arasında tutulan bir sayıyı bulmak için önce 50 sorulur, sayı daha küçükse 0 ile 50 arasında 25 sorulur ve gerek olmayan bölgeler hiç aranmaz. KD-tree de arama uzayını böler; örneğin k-NN'de arama uzayının çok uzak bir noktasındaki örnekle uzaklık hesaplamaya gerek kalmaz. Böylece Ward yönteminde ya da genel olarak uzaklık hesaplamalarında işlem maliyeti büyük ölçüde azaltılabilir.

<!-- BELİRSİZ: Altyazıda "KD3" yazıyor; bağlamdan ve Weka'daki seçenekten KD-tree olduğu anlaşılıyor. -->

## 9. Weka ile Uygulama

### 9.1 Weka'ya genel bakış

Weka (Waikato Environment for Knowledge Analysis), Yeni Zelanda'daki Waikato Üniversitesi'nde geliştirilmiş, açık kaynak kodlu, Java platformunda yazılmış bir veri madenciliği uygulamasıdır. Derste kullanılan sürüm 3.8.1'dir (ekrandan, 02:10:00). Başlangıç penceresinde Explorer, Experimenter, KnowledgeFlow, Workbench ve Simple CLI uygulamaları bulunur. Java'da geliştirildiği için kod parçaları alınıp kendi uygulamalarınıza entegre edilebilir; dünyanın her yerinden araştırmacılar platforma yeni kod ekler.

### 9.2 Iris veri seti ve Preprocess sekmesi

Explorer'da "Open file" ile Weka'yla birlikte gelen hazır veri setlerinden biri açıldı. Bu veri setleri ARFF uzantılı dosyalardır. Açılan Iris veri seti, süsen çiçeğinin üç türünü içerir: Iris setosa, Iris versicolor ve Iris virginica. Biyologlar çiçek üzerinde dört ölçüm yapmıştır: çanak yaprağın (sepal) boyu ve eni, taç yaprağın (petal) boyu ve eni.

Ekrandaki bilgiler (ekrandan, 02:15:00):

- Relation: iris, Instances: 150, Attributes: 5 (4 öz nitelik ve sınıf etiketi).
- Her sınıftan 50 örnek vardır; sınıflar dengeli dağılmıştır. Histogramlarda sınıflara renk atanmıştır (setosa mavi, versicolor kırmızı, virginica turkuaz).
- Öz nitelikler: sepallength, sepalwidth, petallength, petalwidth, class.
- sepallength için seçili öz nitelik istatistikleri: Minimum 4.3, Maximum 7.9, Mean 5.843, StdDev 0.828.

İlk iki öz nitelik sınıfları ayırmada pek etkili görünmez. Üçüncü öz nitelik petal length ise çok ayırt edicidir: 1 ile 6.9 arasında değer alır ve 1 ile 3 arasında yalnız birinci sınıfın (mavi, setosa) 50 örneği toplanır. Kırmızı ile turkuazı ayırmak için ek öz nitelikler gerekir. Petal width de çok ayırt edicidir ve kırmızıyı turkuazdan ayırmada da etkilidir.

Preprocess sekmesinde "Edit" ile bütün örneklerin değerleri görülebilir, değiştirilebilir ve "Save" ile kaydedilebilir. Öz nitelik seçimi yapıldıysa kullanılmayacak öz nitelikler "Remove" ile veri setinden çıkarılabilir.

### 9.3 Sınıflandırma (Classify sekmesi)

**Naive Bayes:** Choose ile Bayes grubundan NaiveBayes seçildi. Test seçeneği olarak 5 katlı çapraz doğrulama (Cross-validation, Folds = 5) kullanıldı: veri beşe bölünür, beşte biri test, beşte dördü eğitim için kullanılır. Çıktı değişkeni sondaki "class" öz niteliğidir. Sonuç: 150 örneğin 144'ü doğru sınıflandı (Correctly Classified Instances), yani %96. Çıktıda her sınıf için TP rate, FP rate, precision, recall değerleri ve ağırlıklı ortalamaları verilir (ekrandan, 02:20:00):

| Sınıf | TP Rate | FP Rate | Precision | Recall | F-Measure |
|---|---|---|---|---|---|
| Iris-setosa | 1,000 | 0,000 | 1,000 | 1,000 | 1,000 |
| Iris-versicolor | 0,960 | 0,040 | 0,923 | 0,960 | 0,941 |
| Iris-virginica | 0,920 | 0,020 | 0,958 | 0,920 | 0,939 |
| Weighted Avg. | 0,960 | 0,020 | 0,960 | 0,960 | 0,960 |

Karışıklık matrisinde (confusion matrix) satırlar gerçek sınıfı, sütunlar tahmin edilen sınıfı gösterir:

```text
  a  b  c   <-- classified as
 50  0  0 | a = Iris-setosa
  0 48  2 | b = Iris-versicolor
  0  4 46 | c = Iris-virginica
```

Versicolor (b) sınıfının 50 örneğinin 48'i doğru, 2'si virginica (c) olarak sınıflanmıştır; virginica'nın 50 örneğinin 46'sı doğru, 4'ü versicolor olarak sınıflanmıştır. Toplam 6 hata vardır.

<!-- BELİRSİZ: Karedeki üçüncü satırın orta değeri fare imleciyle örtülü; 4 değeri altyazıdan ve 50 - 46 = 4 hesabından alındı. -->

**k-en yakın komşu:** "Lazy" grubundaki k-NN yöntemi (Weka'da IBk) seçildi ve $k = 5$ verildi. Parametrelerde uzaklıklara ağırlık verme seçeneği (başlangıçta kapalı) ve uzaklık ölçümü/komşu arama algoritmasını değiştirme seçeneği bulunur; aramayı hızlandırmak için KD-tree seçeneği de vardır. Sonuç: 145 örnek doğru sınıflandı, hatalı örnek sayısı 5'e düştü; Naive Bayes'ten daha başarılıdır. Uzaklık ağırlığı olarak "1/uzaklık" seçilmesi sonucu değiştirmedi.

<!-- BELİRSİZ: Altyazıda "ID3 ile hızlandırmak" ve "Wait by bir bölü" geçiyor; Weka IBk parametrelerinden KD-tree arama ve 1/distance ağırlığı kastedildiği düşünülüyor, kare yok. -->

**Karar ağacı (J48):** Derste görülen karar ağaçları Weka'da J48 adıyla bulunur. Çalıştırıldığında 6 örnek yanlış sınıflandı. Ağacı görmek için sol alttaki sonuç listesinde (Result list) J48 satırına sağ tıklanıp "Visualize tree" seçilir. Kök düğümde petal width bulunur. Ağacın alt seviyelerinde aynı öz niteliğin yeniden test düğümü olarak kullanıldığı görülür; derste kurulan ağaçlarda bu yapılmamıştı, ama bu da bir seçenektir.

### 9.4 Kümeleme (Cluster sekmesi)

**SimpleKMeans:** Veri setinde üç sınıf olduğu için küme sayısı (numClusters) 3 yapıldı (ekrandan, 02:25:00). İlk çalıştırmada küme modu "Use training set" iken veri yalnız üç kümeye ayrıldı; bu çıktı yanlış kümelenmiş örnek sayısını vermez.

> **Hocanın vurgusu:** Kümelemenin sonunda bir etiketleme işlemi gerekir. Weka'nın bu değerlendirmeyi yapması için Cluster mode bölümünde "Classes to clusters evaluation" seçeneği işaretlenmelidir.

Seçenek işaretlenip yöntem yeniden çalıştırıldığında küme boyutları 61, 50 ve 39 (%26) oldu ve şu tablo üretildi (ekrandan, 02:35:00):

```text
  0  1  2   <-- assigned to cluster
  0 50  0 | Iris-setosa
 47  0  3 | Iris-versicolor
 14  0 36 | Iris-virginica

Cluster 0 <-- Iris-versicolor
Cluster 1 <-- Iris-setosa
Cluster 2 <-- Iris-virginica
```

Tablo sütun sütun okunur. Küme 0'da $47 + 14 = 61$ örnek vardır; 47'si versicolor olduğundan etiketi Iris-versicolor'dur. Küme 1'deki 50 örneğin hepsi setosa'dır. Küme 2'de $3 + 36 = 39$ örnek vardır; 36'sı virginica olduğundan etiketi Iris-virginica'dır.

**Soru:** Kaç örnek yanlış kümelenmiştir?
**Cevap:** $14 + 3 = 17$ örnek. Yalnız küme boyutlarına bakılarak bu sayı bulunamaz; "Classes to clusters evaluation" seçeneği bunun için gereklidir.

**HierarchicalClusterer:** Yöntemin parametreleri, adının üzerine tıklanarak açılır. Küme sayısı 3, uzaklık ölçüsü Öklid (Euclidean distance), bağlantı türü (link type) single linkage seçildi. Sonuç: 0 numaralı kümede 49, 1 numaralı kümede 1, 2 numaralı kümede 100 örnek. 49 örnekli küme Iris-setosa olarak etiketlendi. Tek örnekli küme de setosa'dan olduğu ve setosa etiketi zaten kullanıldığı için "no class" kaldı. Virginica sınıfı ayırt edilemedi, yani bir sınıf kayboldu.

Bağlantı türü average olarak değiştirilince daha iyi bir yerleşim elde edildi: küme boyutları 50, 67 ve 33. Birinci sütunda $50 + 17 = 67$ örnek bulunur. Yanlış kümelenen örnek sayısı 17 oldu. Sonuç listesinde sağ tıklayıp "Visualize tree" seçilince dendrogram çizildi (ekrandan, 02:40:00); 150 örnek olduğu için atomik kümelerden başlayan gruplamayı bu grafikte izlemek kolay değildir.

> **Hocanın vurgusu:** Hiyerarşik kümelemede iyi sonuç almak için bağlantı türü olarak mean ya da average linkage seçmenizi öneririm. Parametreleri değiştirerek sonuçların nasıl değiştiğini deneyin.

### 9.5 Öz nitelik seçimi (Select attributes sekmesi)

Bu sekme hangi öz niteliklerin daha ayırt edici olduğunu belirlemeye yarar. Bilgi kazancına (info gain) göre öz nitelik değerlendirmesi yapıldı. 3 numaralı öz niteliğin (petal length) puanı yaklaşık 1.41 ile en yüksek, 4 numaralının (petal width) puanı yaklaşık 1.37 ile ona yakın çıktı. 1 ve 2 numaralı öz niteliklerin ayırt ediciliği oldukça düşük kaldı. Sıralama 3, 4, 1, 2 oldu.

<!-- BELİRSİZ: Bilgi kazancı puanları (1.41 ve 1.37) karede görülmedi, altyazıdan alındı. -->

Buna göre yalnız 3 ve 4 numaralı öz nitelikler kullanılabilir. Preprocess sekmesinde 1 ve 2 numaralı öz nitelikler kaldırılıp sınıflandırma (J48) tekrarlandı: yine 6 örnek yanlış sınıflandı, ama bu kez yalnız iki öz nitelik kullanıldı. Daha az öz nitelikle aynı sonucu veren, karmaşıklığı daha düşük bir model elde edilmiş olur.

<!-- BELİRSİZ: Öz nitelik çıkarıldıktan sonra tekrar çalıştırılan sınıflandırıcının J48 olduğu altyazıda açıkça söylenmiyor; bağlamdan çıkarıldı. -->

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00): Aşağıdaki uzaklık matrisini kullanarak beş örneği a) single linkage, b) complete linkage yöntemleriyle kümeleyin.

$$
D_{5\times 5} =
\begin{bmatrix}
0 & & & & \\
9 & 0 & & & \\
3 & 7 & 0 & & \\
6 & 5 & 9 & 0 & \\
11 & 10 & 2 & 8 & 0
\end{bmatrix}
$$

> **Çözüm (derste verildi):** a) Single linkage birleşmeleri: $S_3+S_5$ (2), $S_1+\{S_3,S_5\}$ (3), $S_2+S_4$ (5), son birleşme (6). b) Complete linkage birleşmeleri: $S_3+S_5$ (2), $S_2+S_4$ (5), $S_1+\{S_2,S_4\}$ (9), son birleşme (11). Ayrıntılı adımlar Bölüm 4'tedir.

**Soru 2** (ekrandan, 01:25:00): Durma koşulu olarak uzaklık eşiği 5.5 seçilirse her iki yöntem kaç küme verir?

> **Çözüm (derste verildi):** Complete linkage 3 küme verir: $\{S_3,S_5\}$, $\{S_2,S_4\}$, $\{S_1\}$. Single linkage 2 küme verir: $\{S_1,S_3,S_5\}$, $\{S_2,S_4\}$.

**Soru 3** (derste sözlü, 01:25:37): Verilen matris bir uzaklık matrisi değil de ikili öz niteliklerden (SMC ya da Jaccard ile) hesaplanmış bir benzerlik matrisi olsaydı single linkage nasıl uygulanırdı?

> **Çözüm (derste verildi):** Benzerlik matrisinde köşegen 1'dir ve en büyük benzerlik değerleri birleştirilir; ya da benzerlikler uzaklığa dönüştürülüp aynı işlemler yapılır.

**Soru 4** (derste sözlü, 01:31:51): Küme içi varyans nasıl ölçülür ve küçük çıkması ne anlama gelir?

> **Çözüm (derste verildi):** Küme merkezi bulunur; örneklerin merkeze uzaklıklarının kareleri toplanıp örnek sayısına bölünür. Küçük varyans, örneklerin merkez etrafında derli toplu olduğunu, yani iyi bir kümeyi gösterir.

**Soru 5** (ekrandan, 01:45:00): Üç kümede sınıf dağılımları Küme I (5 kırmızı, 1 mavi, 0 yeşil), Küme II (1, 4, 1), Küme III (2, 0, 3) olduğuna göre her kümenin etiketini ve saflığını bulun.

> **Çözüm (derste verildi):** Küme I: kırmızı, 5/6. Küme II: mavi, 4/6. Küme III: yeşil, 3/5.

**Soru 6** (derste sözlü, 01:46:50): Küme II'deki 6 örnekten 3'ü kırmızı, 2'si mavi, 1'i yeşil olsaydı etiketleme nasıl yapılırdı?

> **Çözüm (derste verildi):** Çoğunluk kuralı uygulanırsa iki küme kırmızı olur ve mavi sınıf kaybolur. Verinin doğasındaki sınıfı korumak için, saflık düşse de Küme II'ye mavi etiketi verilir.

**Soru 7** (ekrandan, 02:35:00): Weka'da SimpleKMeans ile Iris verisi üç kümeye ayrıldığında "Classes to clusters" tablosu yukarıdaki gibi çıkıyor. Kaç örnek yanlış kümelenmiştir?

> **Çözüm (derste verildi):** $14 + 3 = 17$.

## Dersin Toparlaması

Bu derste eğiticisiz kümelemenin ikinci yöntemi olan hiyerarşik kümeleme işlendi. Agglomerative yaklaşım atomik kümelerden başlayıp en yakın kümeleri adım adım birleştirir (AGNES); divisive yaklaşım tek kümeden başlayıp böler (DIANA). Sonuç bir dendrogramla gösterilir ve bir eşik değeriyle istenen düzeyde kesilerek kümeler elde edilir. Kümeler arası uzaklığın tanımı yöntemi belirler: single linkage en yakın, complete linkage en uzak örnek çiftini, average linkage bütün çiftlerin ortalamasını, centroid yöntemi merkezleri kullanır; Ward yöntemi ise birleşme sonrası küme içi varyansı en küçükleyen çifti seçer. Beş örnekli uzaklık matrisi üzerinde single ve complete linkage adım adım çözüldü ve aynı eşiğin iki yöntemde farklı sayıda küme verdiği görüldü.

Ardından kümeleme kalitesinin iç ölçütlerle (küme içi benzerlik yüksek, kümeler arası benzerlik düşük) ve ground truth varsa dış ölçütlerle, özellikle saflıkla nasıl değerlendirileceği anlatıldı; çoğunluk etiketlemesinin bir sınıfı yok edebileceği uyarısı yapıldı. Son bölümde Weka'da Iris veri seti üzerinde Naive Bayes, k-NN ve J48 ile sınıflandırma, SimpleKMeans ve hiyerarşik kümeleme ile "Classes to clusters evaluation" kullanımı ve bilgi kazancıyla öz nitelik seçimi uygulamalı olarak gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
