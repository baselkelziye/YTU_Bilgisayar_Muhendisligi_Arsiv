# Ders 4 Genişletilmiş Notu: Veri İndirgeme: Entropi ile Öz Nitelik Sıralama ve Temel Bileşen Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Ders büyük ölçüde İngilizce anlatıldı ve altyazının İngilizce bölümlerinde Whisper'ın uzun tekrar satırları ve anlamsız Türkçe parçaları var. Bu bölümlerin anlatımı slayt, PDF ve tahta karelerinden kuruldu. -->

## İçindekiler

- 1. Veri indirgemenin yeri ve öz nitelik indirgemenin kolları
- 2. Entropi ölçüsüyle öz nitelik sıralama: temel fikir
- 3. Uzaklık ve benzerlik ölçüleri
- 4. Kategorik veride Hamming benzerliği ve benzerlik matrisi
- 5. Bilgi kuramında entropi
- 6. Etiketsiz veri için entropi ve sıralama algoritması
- 7. Öz nitelik birleştirme ve PCA'ya giriş
- 8. İstatistik altyapısı: ortalama, standart sapma, kovaryans
- 9. Doğrusal cebir altyapısı: öz değer ve öz vektör
- 10. Temel bileşen analizi (PCA) adımları
- 11. Kaç bileşen seçilmeli?

## 1. Veri indirgemenin yeri ve öz nitelik indirgemenin kolları

Önceki derste veri indirgemeye (data reduction) başlanmıştı. Bir veri setinde üç tür indirgeme yapılabilir. Birincisi, sütunlardaki öz niteliklerin (feature, attribute) sayısını azaltmaktır. Veri hazırlanırken hangisinin faydalı olacağı baştan kestirilemediği için, faydalı olur umuduyla yüzlerce öz nitelik üretilebilir. Bu yüzden en çok indirgeme ihtiyacı duyulan ve en önemli alan budur. İkincisi, satırları yani örnekleri azaltmaktır (sample reduction); bunun için fazla çalışma yapılmaz. Üçüncüsü, tablodaki hücrelerde yazılı değerler üzerinde yapılan değer indirgemedir (value reduction). Değer indirgeme bu derse yetişmedi, sonraki derse kaldı.

Hoca konuları tahtada bir ağaçla özetledi (ekrandan, 02:15:00):

```text
Feature Reduction
├── Feature Selection
│   ├── Supervised    -> Mean & Variance
│   └── Unsupervised  -> Entropy measure
└── Feature Composition   (PCA)
```

Denetimli (supervised) öz nitelik seçimi önceki derste işlendi. Sınıf etiketi olan veriyle çalışıldığında iş kolaydır: sınıfların ortalama ve varyansları üzerinden bir test değeri üretilir. Test değeri ne kadar büyükse öz niteliğin ayırt ediciliği o kadar fazladır. Öz nitelikler bu değere göre sıralanır, belli bir noktadan sonrakiler atılır.

Bu dersin iki ana konusu, öz nitelik seçiminin ikinci kolu olan etiketsiz veri üzerindeki denetimsiz seçim (entropi ölçüsü) ve öz nitelik birleştirmede kullanılan temel bileşen analizidir (Principal Component Analysis, PCA).

## 2. Entropi ölçüsüyle öz nitelik sıralama: temel fikir

Slayttaki açıklamaya göre (ekrandan, 00:15:00):

- Entropi ölçüsüne dayalı denetimsiz öz nitelik seçimi ya da sıralaması görece basit bir tekniktir, ama öz nitelik sayısı arttıkça karmaşıklığı belirgin biçimde artar.
- Temel varsayım, bütün örneklerin çıktı sınıfı olmadan öz nitelik değerlerinden oluşan vektörler olarak verildiğidir.
- Yaklaşım şu gözleme dayanır: ilgisiz (irrelevant) ya da gereksiz (redundant) bir öz nitelik kümeden çıkarıldığında veri setinin temel özellikleri değişmeyebilir.
- Amaç, olabildiğince çok öz niteliği atıp örnekler arasındaki ayırt edicilik düzeyini hiçbir öz nitelik atılmamış gibi korumaktır.
- Algoritma, iki $n$ boyutlu örnek arasındaki uzaklık $D$ ile ters orantılı bir benzerlik ölçüsü $S$ kullanır.

Yöntemin sonunda bütün öz nitelikler en değerliden en değersize sıralanmış olur. Bunun için önce benzerlik ve uzaklık ölçüleri, sonra bilgi kuramındaki entropi anlatıldı.

## 3. Uzaklık ve benzerlik ölçüleri

### 3.1 Veri setinin gösterimi

Hoca tahtada $n$ boyutlu bir veri setinin yapısını yazdı (ekrandan, 00:30:00). Veri seti $X$, $m$ satır ve $n$ sütunlu bir matristir:

$$X = \begin{bmatrix} x_{1,1} & x_{1,2} & x_{1,3} & \cdots & x_{1,n} \\ \vdots & & & & \vdots \\ x_{m,1} & x_{m,2} & & \cdots & \end{bmatrix}$$

$x_{ik}$ gösteriminde ilk indis örnek (sample) numarasını, ikinci indis öz nitelik (feature) numarasını gösterir. Boyut sayısı öz nitelik sayısıdır. Amaç, $i$. örnek ile $j$. örnek arasındaki uzaklığı hesaplamaktır.

### 3.2 Öklid ve normalize Öklid uzaklığı

Öklid uzaklığı önceki dersteki bir örnekte kullanılmıştı. $n$ boyutlu veri için genel biçimi:

$$D_{ij} = \sqrt{\sum_{k=1}^{n} (x_{ik} - x_{jk})^2}$$

Her boyutta iki örneğin değerleri arasındaki fark alınır, farkların kareleri toplanır ve toplamın karekökü alınır.

Normalize Öklid uzaklığı için her öz niteliğin en küçük ve en büyük değeri bulunur (ekrandan, 00:35:00). Min-max normalizasyonuna benzer biçimde her fark o öz niteliğin $\max_k - \min_k$ aralığına bölünür, sonra kareler toplanıp karekök alınır:

$$d_{ij} = \sqrt{\sum_{k=1}^{n} \left(\frac{x_{ik} - x_{jk}}{\max_k - \min_k}\right)^2}$$

<!-- BELİRSİZ: Normalize Öklid formülünün tahtadaki tam hali karelerde görünmüyor (karede yalnız başlık ve "d_ij =" var); formül altyazıdaki sözlü anlatımdan kuruldu. -->

### 3.3 Sayısal öz niteliklerde benzerlik

Slayttaki tanıma göre (ekrandan, 00:25:00) uzaklık ölçüsü $D$, yakın örnekler için küçük (sıfıra yakın), farklı çiftler için büyüktür (bire yakın). Öz nitelikler sayısalsa iki örneğin benzerliği şöyle tanımlanır:

$$S_{ij} = e^{-\alpha D_{ij}}, \qquad \alpha = \frac{-\ln 0.5}{\bar{D}}$$

Burada $D_{ij}$, $x_i$ ile $x_j$ örnekleri arasındaki uzaklıktır; $\bar{D}$ veri setindeki örnekler arası ortalama uzaklıktır. Böylece $\alpha$ veriden belirlenir. Slayta göre başarıyla uygulanmış pratik bir uygulamada sabit $\alpha = 0.5$ kullanılmıştır. Benzerlik uzaklıkla ters orantılıdır: uzaklık büyüdükçe benzerlik küçülür.

> **Ek bilgi (derste anlatılmadı):** $\alpha = -\ln 0.5/\bar{D}$ seçimi, uzaklığı tam ortalama uzaklığa eşit olan iki örneğin benzerliğini $e^{\ln 0.5} = 0.5$ yapar. Yani ortalamadan yakın çiftlerin benzerliği 0.5'ten büyük, uzak çiftlerinki 0.5'ten küçük olur.

## 4. Kategorik veride Hamming benzerliği ve benzerlik matrisi

### 4.1 Hamming benzerliği

Öz nitelikler kategorikse (nominal) sayısal uzaklık hesaplanamaz; doğrudan bir benzerlik hesaplanır. En basit benzerlik ölçüsü Hamming ölçüsüdür (ekrandan, 00:50:00):

$$S_{ij} = \frac{\sum_{k=1}^{n} |x_{ik} = x_{jk}|}{n}$$

İki örneğin her boyuttaki değerleri eşitse o boyut 1, değilse 0 verir. Eşleşen boyutlar toplanır ve öz nitelik sayısı $n$'ye bölünür.

> **Ek bilgi (derste anlatılmadı):** Klasik Hamming uzaklığı farklı olan konumları sayar. Derste "Hamming distance" adıyla verilen formül eşleşmeleri saydığı için aslında bir benzerliktir ve $1 - $ (normalize Hamming uzaklığı) değerine eşittir.

### 4.2 Örnek veri seti

Slayttaki veri seti 5 örnek ve 3 kategorik öz nitelikten oluşur (ekrandan, 00:40:00):

| Örnek | F1 | F2 | F3 |
|---|---|---|---|
| R1 | A | X | 1 |
| R2 | B | Y | 2 |
| R3 | C | Y | 2 |
| R4 | B | X | 1 |
| R5 | C | Z | 3 |

F3 sütunundaki 1, 2, 3 sayısal değer değildir; kategorileri temsil eden kodlardır. Hoca bunu renkle örnekledi: 1 kırmızı, 2 yeşil, 3 mavi gibi düşünülebilir. Bu yüzden bu değerlerle aritmetik işlem yapılamaz.

### 4.3 Benzerlik matrisinin hesaplanması

Hoca adım adım sorular sorarak matrisi doldurdu (ekrandan, 00:50:00):

- Matrisin boyutu: 5 örnek olduğu için $5 \times 5$. Genel olarak $m$ örnek için $m \times m$.
- Ana köşegen: her örnek kendisine %100 benzediği için 1.
- Matris simetriktir ($S_{ij} = S_{ji}$), bu yüzden yalnız üst üçgeni hesaplamak yeter.

Karşılaştırmalar:

- R1 (A, X, 1) ile R2 (B, Y, 2): hiçbir boyut eşleşmez, $S_{12} = 0$.
- R1 ile R3 (C, Y, 2): eşleşme yok, $S_{13} = 0$.
- R1 ile R4 (B, X, 1): F2 ve F3 eşleşir, $S_{14} = 2/3$.
- R1 ile R5 (C, Z, 3): eşleşme yok, $S_{15} = 0$.
- R2 ile R3: F2 (Y) ve F3 (2) eşleşir, $S_{23} = 2/3$.
- R2 ile R4: yalnız F1 (B) eşleşir, $S_{24} = 1/3$.
- R2 ile R5: eşleşme yok, $S_{25} = 0$.
- R3 ile R4: eşleşme yok, $S_{34} = 0$.
- R3 ile R5: yalnız F1 (C) eşleşir, $S_{35} = 1/3$.
- R4 ile R5: eşleşme yok, $S_{45} = 0$.

Sonuç matrisi (slayttaki tablo ve tahta; python ile doğrulandı):

$$S = \begin{bmatrix} 1 & 0 & 0 & 2/3 & 0 \\ 0 & 1 & 2/3 & 1/3 & 0 \\ 0 & 2/3 & 1 & 0 & 1/3 \\ 2/3 & 1/3 & 0 & 1 & 0 \\ 0 & 0 & 1/3 & 0 & 1 \end{bmatrix}$$

**Soru:** Sağdaki tabloda her satır bir örneği, sütunlar öz nitelikleri göstermiyor mu? **Cevap:** Evet. Satırlar örnekleri, sütunlar öz nitelikleri gösterir; tahtada sütun başlıkları (F1, F2, F3) yazılmadı ama slaytta vardır. İki örnek arasındaki benzerlik bulunurken iki satır alınır, karşılıklı öz nitelikleri eşleşenler sayılır ve öz nitelik sayısına bölünür. $i$ ve $j$ örnek numaralarıdır.

**Soru:** Bu benzerlikleri neden ölçüyoruz? **Cevap:** Benzerlik değerlerinden entropi hesaplanacak. Ayrıca örnekler arası benzerlik ölçümüne veri madenciliğinde pek çok yerde, özellikle kümelemede (clustering) ihtiyaç duyulur. Kümeleme konusunda başka benzerlik ölçüleri de anlatılacak; Hamming bunların en basitidir.

## 5. Bilgi kuramında entropi

### 5.1 Tanım

Slayta göre entropi küresel (global) bir ölçüdür: düzenli yapılarda (ordered configuration) daha az, düzensiz yapılarda (disordered configuration) daha fazladır (ekrandan, 00:55:00). Entropi karar ağaçlarında ve başka konularda da kullanılacağı için hoca kavramın baştan iyi anlaşılmasını istedi.

Hoca Wikipedia'daki tanımı aktardı: olası sonuçları $x_1, \dots, x_n$ olan ve bunlar $P(x_1), \dots, P(x_n)$ olasılıklarıyla gerçekleşen ayrık bir rastgele değişken $X$ için entropi

$$H(X) = -\sum_{i=1}^{n} P(x_i) \log_2 P(x_i)$$

olarak tanımlanır. İkili (bit) sonuç almak için 2 tabanlı logaritma kullanılır; birim bittir.

**Soru:** Formüldeki loglar 2 tabanlı mı? **Cevap:** Evet. Uygulamalarda hep bit kavramı kullanıldığı için bilgi kuramında 2 tabanı tercih edilir. Başka tabanlar da kullanılabilir.

### 5.2 Düzensiz yapı (iki sonuç)

Masada 6 kırmızı ve 6 mavi top olsun (ekrandan, 01:00:00). İki sonuç vardır: $p_1$ kırmızı, $p_2$ mavi.

- $p_1 = 6/12 = 1/2$, $p_2 = 1/2$.
- $H = -\left(\tfrac12 \log_2 \tfrac12 + \tfrac12 \log_2 \tfrac12\right)$.
- $\log_2 \tfrac12 = \log_2 2^{-1} = -1$.
- $H = -\left(\tfrac12 \cdot (-1) + \tfrac12 \cdot (-1)\right) = 1$.

Renkler karışık ve eşit oranda olduğu için bu düzensiz yapıdır ve entropi 1 bittir.

### 5.3 Düzenli yapı (iki sonuç)

Masada yalnız kırmızı toplar olsun (ekrandan, 01:10:00). İki olası sonuç vardır ama yalnız bir sınıf görünür.

- $p_1 = 1$, $p_2 = 0$.
- $H = -\left(1 \cdot \log_2 1 + 0 \cdot \log_2 0\right)$.
- $\log_2 1 = \log_2 2^0 = 0$; ikinci terim de 0 kabul edilir.
- $H = 0$.

> **Ek bilgi (derste anlatılmadı):** $\log_2 0$ tanımsızdır; entropide $0 \cdot \log_2 0$ terimi, $p \to 0$ iken $p \log_2 p \to 0$ limitine dayanarak 0 alınır.

### 5.4 İki sonuçlu entropi grafiği

Hoca yatay eksende bir sınıfın olasılığı $p$, dikey eksende $H$ olan grafiği çizdi (ekrandan, 01:10:00):

- $p = 0$ ise diğer sınıfın olasılığı 1'dir; bu düzenli yapı örneğine karşılık gelir, $H = 0$.
- $p = 1/2$ ise diğer sınıfın olasılığı da $1/2$'dir; düzensiz yapı, $H = 1$ (en büyük değer).
- $p = 1$ ise diğer sınıf 0'dır; yine $H = 0$.

Grafik $p = 1/2$ etrafında simetriktir (bir yansıma gibi) ve yarım daireye benzeyen bir tepe biçimindedir. Bu çizim yalnız iki sonuçlu yapı için geçerlidir; yazı-tura atma da bu türdendir. En düzensiz yapı, çoğunluğun kurulamadığı, her sınıftan eşit oranda bulunduğu yapıdır.

> **Hocanın vurgusu:** Bütün sınıfların olasılıkları birbirine eşitse entropi en büyük (tepe) değerini alır. Bu yalnız iki sınıf için değil, her sınıf sayısı için geçerlidir.

### 5.5 Dört sonuçlu örnek

Dört renk (kırmızı, mavi, yeşil, sarı) ve her renkten 3 top olsun (ekrandan, 01:15:00).

- $p_1 = p_2 = p_3 = p_4 = 3/12 = 1/4$.
- $H = -4 \cdot \tfrac14 \log_2 \tfrac14$.
- $\log_2 \tfrac14 = \log_2 2^{-2} = -2$.
- $H = -4 \cdot \tfrac14 \cdot (-2) = 2$ bit.

Olasılıklar eşit olduğu için bu düzensiz yapıdır ve dört sonuç için en büyük entropi 2 bittir. Sekiz sonuçta en büyük entropi 3 bit olur.

> **Hocanın vurgusu:** Sonuç sayısına göre en büyük entropiyi bilmek önemlidir (2 sonuç: 1, 4 sonuç: 2, 8 sonuç: 3 bit); böylece hesap sonuçlarınızı kontrol edebilirsiniz.

## 6. Etiketsiz veri için entropi ve sıralama algoritması

### 6.1 Benzerlikle yazılan entropi

Bölüm 5'teki entropi sınıf olasılıklarına ihtiyaç duyar. Oysa bu öz nitelik seçim yöntemi denetimsizdir; sınıf etiketi yoktur ve sınıf olasılıkları bilinmez. Bu yüzden entropi formülü olasılık yerine benzerlik değerleriyle yeniden yazılır. $N$ örnekli bir veri seti için (ekrandan, 00:55:00 ve 01:40:00):

$$E = -\sum_{i=1}^{N-1} \sum_{j=i+1}^{N} \left( S_{ij} \log S_{ij} + (1 - S_{ij}) \log (1 - S_{ij}) \right)$$

- $i$, 1'den $N-1$'e; $j$, $i+1$'den $N$'ye gider. Yani $S_{12}, S_{13}, S_{14}, S_{15}$ kullanılır, sonra ikinci satıra geçilir. Toplam, benzerlik matrisinin ana köşegeninin üstünde kalan üçgendeki bütün değerleri dolaşır.
- Birinci terim benzerliği ($S_{ij}$) kullanır.
- İkinci terim $1 - S_{ij}$ değerini, yani benzemezliği (dissimilarity) kullanır. Benzerliğin en büyük değeri 1 olduğundan $1 - S_{ij}$ "benzememe" oranını gösterir.
- Slayttaki formülde logaritma tabanı yazılmamıştır; derste 2 tabanı kullanıldı.

Slayta göre bu ölçü her yinelemede öz niteliklerin sıralanmasına karar vermek için yeniden hesaplanır. Öz nitelikler, verinin yapı düzenini korumada en az önemli olan öz nitelik adım adım çıkarılarak sıralanır. Algoritmanın adımları ardışık geriye doğru sıralamaya (sequential backward ranking) dayanır ve birçok gerçek dünya uygulamasında başarıyla denenmiştir. Önerilen teknik, bir öz nitelik çıkarılmadan önceki ve sonraki entropiyi karşılaştırır; iki ölçü yakınsa indirgenmiş öz nitelik kümesi asıl kümeyi yeterince temsil eder.

**Soru:** Önceki örneklerde entropi hesaplarken benzerlik kullanmamıştık, neden? **Cevap:** Oradaki örneklerde sınıf etiketi vardı, olasılıklar biliniyordu. Bu yöntem denetimsiz olduğu için sınıf olasılıkları yoktur; formül bu probleme uygun hale getirilerek olasılık yerine benzerlik kullanılır.

### 6.2 Sıralama adımları

Slayttaki adımlar (ekrandan, 01:50:00):

1. Başlangıçtaki tam öz nitelik kümesi $F$ ile başla.
2. Her $f \in F$ için $f$'yi $F$'den çıkar ve $F_f$ alt kümesini elde et. $F$'nin entropisi ile her $F_f$'nin entropisi arasındaki farkı bul. Örnekte $(E_F - E_{F-F1})$, $(E_F - E_{F-F2})$ ve $(E_F - E_{F-F3})$ karşılaştırılır.
3. $F$ için entropi ile $F_{f_k}$ için entropi arasındaki fark en küçük olan öz nitelik $f_k$ olsun.
4. Öz nitelik kümesini güncelle: $F = F - \{f_k\}$ (küme farkı). Örnekte $(E_F - E_{F-F1})$ en küçükse indirgenmiş küme $\{F2, F3\}$ olur ve F1 sıralı listenin en altına gider.
5. $F$'de tek öz nitelik kalana kadar 2-4. adımları tekrarla.

### 6.3 Tahtadaki uygulama

Önceki örnekteki üç öz nitelikle (ekrandan, 01:45:00):

- Tam küme $F = \{F1, F2, F3\}$. Bu üç öz nitelikle Hamming benzerlik matrisi kurulur ve $E_F$ hesaplanır.
- $F - F1$: yalnız F2 ve F3 kalır. Bu iki öz nitelikle yeni bir benzerlik matrisi kurulur ve $E_{F-F1}$ hesaplanır.
- Aynı işlem F2 ve F3 için yapılır: $E_{F-F2}$ (F1 ve F3 ile), $E_{F-F3}$ (F1 ve F2 ile).
- Farklar bulunur: $E_F - E_{F-F1}$, $E_F - E_{F-F2}$, $E_F - E_{F-F3}$.
- Örneğin en küçük fark F1'in çıkarılmasıyla elde ediliyorsa, F1'i çıkarmak önemli bir şey kaybettirmez; kalan küme tam kümeye çok yakın bir biçimdir. F1 sıralı listenin en altına konur.

Ardından kalan F2 ve F3 yeni "tam küme" sayılır. Bunların entropisi hesaplanır, her defasında biri dışarıda bırakılarak işlemler tekrarlanır. Yöntem yinelemelidir; öz nitelikler bitene kadar sürer.

**Soru:** Bir sonraki adımda fark hesaplanırken alt kümeden mi devam ediyoruz? **Cevap:** Evet. En değersiz öz nitelik çıkarılıp listenin en altına konduktan sonra geriye kalanlar başlangıç kümesi gibi düşünülür ve işlem onlarla sürer.

<!-- BELİRSİZ: Derste bu veri seti için entropi değerleri sayısal olarak hesaplanmadı; hangi öz niteliğin önce çıkacağı derste söylenmedi. -->

## 7. Öz nitelik birleştirme ve PCA'ya giriş

Öz nitelik seçiminde var olan öz niteliklerden bazıları tutulur, diğerleri atılır; tutulanlar anlamını korur. Öz nitelik birleştirmede (feature composition) ise öz nitelikler değiştirilir: işlem sonunda asıl öz nitelikler kalmaz, onların birleşimi olan yeni öz nitelikler tanımlanır. Hoca bunu tıp verisiyle örnekledi: kan değeri belli bir sınırın (örneğin 60) üstünde mi, kalp atış hızı nedir gibi öz nitelikler doktor için anlamlıdır. Birleştirme sonrası bu öz nitelikler kaybolur; yerine bunların bileşiminden oluşan yeni öz nitelikler gelir.

<!-- BELİRSİZ: Tıp örneğinin tam ifadesi (hangi değer, hangi eşik, karar ağaçlarıyla bağlantısı) altyazıda bozuk. -->

Temel bileşen analizi (PCA) sınıf etiketine ihtiyaç duymaz; denetimsiz bir yöntemdir. PCA'yı anlamak için önce istatistik ve doğrusal cebir altyapısı hatırlatıldı. Bu bölümde kaynak olarak İngilizce bir PCA eğitim belgesi (PDF) ekranda gösterildi.

## 8. İstatistik altyapısı: ortalama, standart sapma, kovaryans

### 8.1 Ortalama ve standart sapma

Ortalama $\bar{X} = \frac{\sum_{i=1}^{n} X_i}{n}$ ile hesaplanır (ekrandan, 02:00:00). Ortalama veri hakkında bir orta nokta dışında pek bilgi vermez. Belgedeki iki küme aynı ortalamaya (10) sahiptir:

- $[0, 8, 12, 20]$: toplam 40, ortalama 10.
- $[8, 9, 11, 12]$: toplam 40, ortalama 10.

İki küme yine de açıkça farklıdır. İlki 0 ile 20 arasına geniş biçimde yayılmış, ikincisi 8 ile 12 arasında ortalamaya yakın toplanmıştır. Fark yayılımdadır (spread) ve bunu standart sapma ölçer:

$$s = \sqrt{\frac{\sum_{i=1}^{n} (X_i - \bar{X})^2}{n-1}}$$

Her değerin ortalamadan farkının karesi alınır, kareler toplanır, $n-1$'e bölünür ve karekök alınır. Varyans standart sapmanın karesidir. Python kontrolü: ilk kümenin standart sapması yaklaşık 8.33, ikincisinin yaklaşık 1.83'tür (ara adım eklendi).

### 8.2 Kovaryans

Veride $x, y, z$ gibi birden çok değişken (veri madenciliğinde öz nitelik) olduğunda değişkenler arasındaki ilişkiyi anlamak için kovaryans kullanılır. Varyans tek boyut üzerinde çalışır; kovaryans iki boyut arasında ölçülür (ekrandan, 02:05:00):

$$var(X) = \frac{\sum_{i=1}^{n} (X_i - \bar{X})(X_i - \bar{X})}{n-1}, \qquad cov(X,Y) = \frac{\sum_{i=1}^{n} (X_i - \bar{X})(Y_i - \bar{Y})}{n-1}$$

Bir boyutun kendisiyle kovaryansı o boyutun varyansıdır.

### 8.3 Çalışma saati ve not örneği

Belgedeki veri setinde 12 öğrenci ve iki değişken vardır: derse çalışılan saat ($H$) ve alınan not ($M$) (ekrandan, 02:10:00).

| $H$ | $M$ | $H_i - \bar{H}$ | $M_i - \bar{M}$ | Çarpım |
|---|---|---|---|---|
| 9 | 39 | -4.92 | -23.42 | 115.23 |
| 15 | 56 | 1.08 | -6.42 | -6.93 |
| 25 | 93 | 11.08 | 30.58 | 338.83 |
| 14 | 61 | 0.08 | -1.42 | -0.11 |
| 10 | 50 | -3.92 | -12.42 | 48.69 |
| 18 | 75 | 4.08 | 12.58 | 51.33 |
| 0 | 32 | -13.92 | -30.42 | 423.45 |
| 16 | 85 | 2.08 | 22.58 | 46.97 |
| 5 | 42 | -8.92 | -20.42 | 182.15 |
| 19 | 70 | 5.08 | 7.58 | 38.51 |
| 16 | 66 | 2.08 | 3.58 | 7.45 |
| 20 | 80 | 6.08 | 17.58 | 106.89 |

Toplamlar 167 saat ve 749 not; ortalamalar $\bar{H} = 13.92$ (yaklaşık 14) ve $\bar{M} = 62.42$. İlk öğrenci ortalamanın altında (9 saat) çalışmış ve ortalamanın altında (39) not almıştır. Çarpımların çoğu pozitiftir; sonuç pozitif çıkar. Pozitif kovaryans, iki değişken arasında pozitif bir ilişki olduğunu gösterir: daha çok çalışan daha yüksek not alma eğilimindedir.

> **Ders sonrası not:** Ekrandaki tablonun toplam satırında çarpımlar toplamı 1149.89, kovaryans 104.54 yazıyor. Tablodaki çarpımlar toplandığında (python ile) yaklaşık 1352.42 çıkıyor; doğru kovaryans $1352.42/11 \approx 122.95$'tir. Toplam satırı büyük olasılıkla kaynak belgedeki bir yazım hatasıdır. İlişkinin pozitif olduğu sonucu değişmez.

### 8.4 Kovaryans matrisi

Üç boyutlu ($x, y, z$) veri setinde bütün ikili kovaryanslar bir matriste toplanır:

$$C = \begin{pmatrix} cov(x,x) & cov(x,y) & cov(x,z) \\ cov(y,x) & cov(y,y) & cov(y,z) \\ cov(z,x) & cov(z,y) & cov(z,z) \end{pmatrix}$$

- Kare matristir.
- Simetriktir: $cov(x,y) = cov(y,x)$.
- Ana köşegeni ($cov(x,x)$, $cov(y,y)$, $cov(z,z)$) varyansları gösterir.

**Soru (hocanın sorusu):** Kovaryans matrisinin ana köşegenindeki değerler neyi ifade eder? **Cevap:** Varyansı.

## 9. Doğrusal cebir altyapısı: öz değer ve öz vektör

### 9.1 Tanım

Bir kare matris $A$ ile bir vektör $u$'nun çarpımı, bir katsayı ile aynı vektörün çarpımı olarak yazılabiliyorsa, yani

$$A u = \lambda u$$

ise $u$, $A$'nın öz vektörü (eigenvector), $\lambda$ da öz değeridir (eigenvalue). Bulmak için denklem yeniden düzenlenir:

$$(A - \lambda I) u = 0$$

Burada $I$ birim matristir. Sıfırdan farklı bir $u$ için $A - \lambda I$ tekil olmalıdır, bu yüzden

$$\det(A - \lambda I) = 0$$

denkleminden $\lambda$ değerleri bulunur. Bulunan her $\lambda$ ilk denklemde yerine konarak $u$ hesaplanır.

### 9.2 Örnek

$A = \begin{pmatrix} 2 & 1 \\ 1 & 2 \end{pmatrix}$ matrisinin öz değer ve öz vektörleri (ekrandan, 02:20:00):

$$\det\left[ \begin{pmatrix} 2 & 1 \\ 1 & 2 \end{pmatrix} - \lambda \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix} \right] = \det \begin{pmatrix} 2-\lambda & 1 \\ 1 & 2-\lambda \end{pmatrix} = 0$$

- $(2-\lambda)^2 - 1 = 0$ (ara adım eklendi).
- $\lambda^2 - 4\lambda + 3 = 0$.
- Kökler: $\lambda_1 = 3$, $\lambda_2 = 1$.

$\lambda_1 = 3$ için $A u_1 = 3 u_1$ (ekrandan, 02:25:00):

$$\begin{pmatrix} 2 & 1 \\ 1 & 2 \end{pmatrix} \begin{pmatrix} x_1 \\ y_1 \end{pmatrix} = 3 \begin{pmatrix} x_1 \\ y_1 \end{pmatrix}$$

- $2x_1 + y_1 = 3x_1$
- $x_1 + 2y_1 = 3y_1$
- İki denklemden de $x = y$ çıkar. Tam değer değil, ilişki bulunur; vektörün yönü önemli olduğu için bu sorun değildir. $u_1 = \begin{pmatrix} 1 \\ 1 \end{pmatrix}$.

$\lambda_2 = 1$ için $A u_2 = 1 \cdot u_2$:

- $2x_2 + y_2 = x_2$
- $x_2 + 2y_2 = y_2$
- Bu denklemlerden $x = -y$ çıkar. $u_2 = \begin{pmatrix} 1 \\ -1 \end{pmatrix}$.

<!-- BELİRSİZ: u2 için tahtada yazılan vektörün karesi yok; altyazıda "1 ve 1" geçiyor. x = -y ilişkisinden ve python kontrolünden (1, -1) yazıldı. -->

Python kontrolü: $A$'nın öz değerleri 3 ve 1; normalize öz vektörleri $(0.707, 0.707)$ ve $(-0.707, 0.707)$ yönündedir, yani $(1,1)$ ve $(1,-1)$ ile aynı doğrultudadır.

## 10. Temel bileşen analizi (PCA) adımları

### 10.1 Adım 1-2: Veri ve ortalamanın çıkarılması

Belgedeki örnekte iki boyutlu ($x$, $y$) 10 örnek vardır. İlk adım veriyi almaktır. İkinci adımda her sütunun ortalaması hesaplanır ve o sütundaki her değerden çıkarılır; sonuç "adjusted data" (ortalaması çıkarılmış veri) olur.

Asıl verinin grafiğinde bütün noktalar koordinat düzleminin birinci bölgesindedir. Ortalama, veri kümesinin merkez noktasıdır. Ortalamayı çıkarmak bu merkezi koordinat sisteminin orijinine kaydırmak (shift) demektir.

### 10.2 Adım 3: Kovaryans matrisi

Ortalaması çıkarılmış veride 10 örnek ve 2 boyut vardır. Bu veri için $2 \times 2$ kovaryans matrisi hesaplanır. Matris kare ve simetriktir; köşegen dışı eleman $x$ ile $y$ arasındaki kovaryanstır.

### 10.3 Adım 4: Öz değer ve öz vektörler

Kovaryans matrisinin öz değerleri ($\lambda_1$, $\lambda_2$) ve öz vektörleri ($u_1$, $u_2$) hesaplanır. Öz vektörler bir matrise yerleştirilir: birinci sütun $u_1$, ikinci sütun $u_2$'dir.

### 10.4 Yeni koordinat düzlemi

Belgedeki "Mean adjusted data with eigenvectors overlayed" grafiğinde ortalaması çıkarılmış 10 nokta ve iki öz vektör kesikli çizgilerle gösterilir (ekrandan, 02:45:00). Hoca grafikte iki çizgiyi işaretledi (ekrandan, 02:50:00):

- Sol üstten sağ alta inen çizgi $u_1$,
- sol alttan sağ üste çıkan ve noktaların uzandığı doğrultudaki çizgi $u_2$.

Noktalar $u_2$ doğrultusunda uzanan bir küme oluşturur; verinin bir yönü vardır ve bu yön $u_2$'dir. PCA, veriyi $x$-$y$ düzlemi yerine $u_1$-$u_2$ ile tanımlanan bu özel koordinat düzleminde ifade eder. Bir noktanın yeni koordinatları, o noktanın $u_1$ ve $u_2$ eksenlerine izdüşümü (projection) alınarak bulunur. Dönüşümden sonra $u_2$ ekseni üzerindeki değerler geniş bir aralığa yayılır, $u_1$ ekseni üzerindekiler dar bir aralıkta kalır.

**Soru:** Yeni eksenlerdeki değerleri nasıl belirledik? **Cevap:** Noktaların eksenlere izdüşümleri alınır. Grafikteki bir artı noktayı yeni $u_1$-$u_2$ düzleminde yerleştirmek, onu $u_1$ ve $u_2$ üzerine izdüşürmek (project etmek) demektir. İzdüşümün $u_2$ eksenini kestiği yer, noktanın yeni düzlemdeki $u_2$ koordinatıdır.

### 10.5 Dönüşümün matris çarpımıyla yapılması

Hoca dönüşümü tahtada matris çarpımı olarak gösterdi (ekrandan, 03:00:00):

$$\underbrace{\text{Adjusted Data}}_{10 \times 2} \times \underbrace{\begin{bmatrix} u_1 & u_2 \end{bmatrix}}_{2 \times 2} = \underbrace{\text{Transformed Data}}_{10 \times 2}$$

- Adjusted data, asıl veriden ortalamalar çıkarıldıktan sonraki matristir; 10 satır, 2 sütundur (x, y).
- $u_1$ ve $u_2$ her biri $2 \times 1$ boyutlu öz vektörlerdir.
- Adjusted data'nın birinci satırı $u_1$ ile çarpılınca transformed data'nın birinci satırının $u_1$ bileşeni bulunur: noktanın $u_1$ üzerine izdüşümünün ekseni kestiği yer.
- Aynı satır $u_2$ ile çarpılınca $u_2$ bileşeni bulunur.
- Sonuç matrisi de $10 \times 2$'dir; sütunları artık $u_1$ ve $u_2$ eksenlerindeki koordinatlardır.

> **Hocanın vurgusu:** Bu matris dönüşümüne dikkat edin ve matris çarpımını mutlaka not edin.

### 10.6 İndirgeme nerede yapılır?

Bu noktada yalnız dönüşüm yapılmıştır, indirgeme yapılmamıştır: girişte iki öz nitelik vardı, dönüştürülmüş veride de iki öz nitelik vardır. İndirgeme öz değerlere bakılarak yapılır. Öz değerler eksenlerdeki dağılımla ilgilidir; hangi eksende dağılımın daha büyük olduğunu gösterirler. Örnekte bir öz değer 0.04 civarında, diğeri 1.2 civarındadır. Değişimin en fazla olduğu eksen $u_2$'dir; bu yüzden yalnız $u_2$ öz niteliği seçilir ve veri iki boyuttan bire indirilir.

<!-- BELİRSİZ: Altyazıda büyük öz değer "1.2 ya da 24 gibi" diye geçiyor; değer büyük olasılıkla 1.28 civarıdır, kare yok. -->

> **Hocanın vurgusu:** Hangi öz vektörün veriyi daha iyi temsil ettiğinin ipucu öz değerde saklıdır; karar öz değerlere bakılarak verilir.

## 11. Kaç bileşen seçilmeli?

Öz nitelik sayısı ikiden fazlaysa kaç öz vektör kullanılacağına da öz değerlerle karar verilir. 5 boyutlu bir veri düşünülsün (ekrandan, 03:05:00): örneğin 10 örnek ve 5 boyut. Kovaryans matrisi $5 \times 5$ olur; 5 öz değer ve 5 öz vektör çıkar. Öz değerler büyükten küçüğe sıralanır:

$$\lambda_1 > \lambda_2 > \lambda_3 > \lambda_4 > \lambda_5$$

Önce yalnız en büyük öz değerin toplam içindeki payına bakılır; bir eşikle (örneğin verinin %95'ini temsil etsin diye 0.95) karşılaştırılır:

$$\frac{\lambda_1}{\lambda_1 + \lambda_2 + \lambda_3 + \lambda_4 + \lambda_5} \ge 0.95 \ ?$$

Sağlanmazsa sıradaki öz değer de payda toplama katılır:

$$\frac{\lambda_1 + \lambda_2}{\lambda_1 + \lambda_2 + \lambda_3 + \lambda_4 + \lambda_5} \ge 0.95 \ ?$$

Hocanın örneği: yalnız $\lambda_1$ ile oran %85 çıksın. $\lambda_2$ 0.11'lik katkı yapsın; toplam %96 olur. %95 aşıldığı için veriyi iki bileşenle ($\lambda_1$ ve $\lambda_2$'ye karşılık gelen $u_1$, $u_2$) temsil etmek yeterlidir. Veri yalnız $u_1$ ve $u_2$ üzerine izdüşürülür; $u_3$, $u_4$, $u_5$'e gerek kalmaz. İndirgenmiş veri asıl verinin %96'sını temsil eden, ona çok yakın bir veri olur.

> **Hocanın vurgusu:** Bu konu önemlidir; PCA'nın mantığını anlamış olmak çok önemlidir.

## Örnek Sorular

**1. (derste sözlü, 00:45:31; ekrandan, 00:40:00)** Beş örnekli, üç kategorik öz nitelikli veri seti (R1 = A,X,1; R2 = B,Y,2; R3 = C,Y,2; R4 = B,X,1; R5 = C,Z,3) için Hamming benzerlik matrisinin boyutu nedir, ana köşegeninde ne bulunur?

> **Çözüm (derste verildi):** 5 örnek olduğu için matris $5 \times 5$'tir. Her örnek kendisine %100 benzediği için ana köşegen 1'dir. Matris simetriktir.

**2. (ekrandan, 00:50:00)** Aynı veri seti için Hamming benzerlik matrisinin üst üçgenini hesaplayın.

> **Çözüm (derste verildi):** $S_{12}=0$, $S_{13}=0$, $S_{14}=2/3$, $S_{15}=0$; $S_{23}=2/3$, $S_{24}=1/3$, $S_{25}=0$; $S_{34}=0$, $S_{35}=1/3$; $S_{45}=0$. (Python ile doğrulandı.)

**3. (derste sözlü, 01:17:09)** Sekiz sonuçlu bir problemde en büyük entropi kaç bittir?

> **Çözüm (derste verildi):** Bütün olasılıklar $1/8$ iken $H = -8 \cdot \tfrac18 \log_2 \tfrac18 = 3$ bit.

**4. (derste sözlü, 01:37:59)** Etiketsiz entropi formülündeki $1 - S_{ij}$ neyi gösterir?

> **Çözüm (derste verildi):** $S_{ij}$ benzerlik olduğundan ve en büyük değeri 1 olduğundan $1 - S_{ij}$ benzemezliği (dissimilarity) gösterir.

**5. (derste sözlü, 02:11:46)** Kovaryans matrisinin ana köşegenindeki değerler neyi ifade eder?

> **Çözüm (derste verildi):** Varyansları: $cov(x,x) = var(x)$, $cov(y,y) = var(y)$, $cov(z,z) = var(z)$.

**6. (ekrandan, 02:20:00; derste sözlü, 02:20:45)** $A = \begin{pmatrix} 2 & 1 \\ 1 & 2 \end{pmatrix}$ matrisinin öz değerlerini ve öz vektörlerini bulun.

> **Çözüm (derste verildi):** $\det(A - \lambda I) = (2-\lambda)^2 - 1 = \lambda^2 - 4\lambda + 3 = 0$; $\lambda_1 = 3$, $\lambda_2 = 1$. $\lambda_1 = 3$ için $x = y$, $u_1 = (1, 1)^T$; $\lambda_2 = 1$ için $x = -y$, $u_2 = (1, -1)^T$. (Python ile doğrulandı.)

**7. (derste sözlü, 02:53:20; ekrandan, 02:50:00)** PCA'da noktaların yeni koordinat düzlemindeki ($u_1$, $u_2$) değerleri nasıl belirlenir?

> **Çözüm (derste verildi):** Her noktanın $u_1$ ve $u_2$ eksenlerine izdüşümü alınır. Matris biçiminde: ortalaması çıkarılmış veri ($10 \times 2$) öz vektör matrisiyle ($[u_1\ u_2]$) çarpılır; sonuç $10 \times 2$ dönüştürülmüş veridir.

## Dersin Toparlaması

Bu derste öz nitelik indirgemenin iki yolu işlendi. Etiketsiz veride öz nitelik seçimi için örnekler arası benzerlikler (sayısal veride $e^{-\alpha D}$, kategorik veride Hamming) hesaplandı, bilgi kuramındaki entropi kavramı düzenli ve düzensiz yapı örnekleriyle anlatıldı ve entropi olasılık yerine benzerlikle yeniden yazıldı. Öz nitelikler, her birinin çıkarılmasının entropiyi ne kadar değiştirdiğine bakılarak, en az değiştiren listenin en altına gidecek biçimde yinelemeli olarak sıralanır.

Öz nitelik birleştirme tarafında temel bileşen analizi için ortalama, standart sapma, kovaryans, kovaryans matrisi, öz değer ve öz vektör hatırlatıldı. PCA'da veri ortalamaya göre merkezlenir, kovaryans matrisinin öz vektörleri yeni eksenleri verir, veri bu eksenlere izdüşürülür ve öz değer oranı bir eşiği (örneğin 0.95) aşana kadar en büyük öz değerli bileşenler tutulur. Değer indirgeme (value reduction) sonraki derse kaldı. Entropi karar ağaçlarında, benzerlik ölçüleri kümelemede yeniden kullanılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
