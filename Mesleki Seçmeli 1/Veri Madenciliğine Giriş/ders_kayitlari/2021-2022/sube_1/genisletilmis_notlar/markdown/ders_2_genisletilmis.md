# Ders 2 Genişletilmiş Notu: Transaction Verisi ve Temel İstatistiksel Tanımlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri türlerine dönüş: doküman ve transaction verisi
- 2. Temel istatistiksel tanımlara neden ihtiyaç duyulur
- 3. Merkezi eğilim ölçüleri
- 4. Simetrik ve çarpık dağılımlar
- 5. Merkezi eğilim örneği
- 6. Verinin yayılımı: range, çeyrekler, IQR, varyans
- 7. Aykırı değerler, beş sayı özeti ve kutu grafiği
- 8. Yayılım örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Veri türlerine dönüş: doküman ve transaction verisi

Ders, bir önceki derste başlanan veri tiplerine kısa bir dönüşle açıldı. Önceki derste kayıt (record) verisi ve matris biçimindeki veri görülmüş, ardından dokümanların nasıl tutulacağına geçilmişti.

### 1.1 Doküman verisi ve terim vektörü

Dokümanlar genellikle her doküman tek bir satır olacak şekilde tutulur. Sütunlar terimlerdir (kelimeler), hücrelerde ise o terimin dokümanda kaç kez geçtiği yazılır. Bu satıra terim vektörü (term vector) denir.

Kelime sayısı çok fazla olduğu için sütun sayısı, yani attribute sayısı, çok büyür. Bu nedenle çok az geçen kelimeler atılır. Hoca örnek verdi: bin doküman varsa ve bir kelime yalnızca bir dokümanda bir kez geçiyorsa, bu kelimeyi tutmak veriyi gereksiz yere büyütür. Genellikle bir eşik (threshold) belirlenir; eşik 3 ise bin dokümanda toplam 3'ten az geçen kelimeler veriden çıkarılır.

### 1.2 Transaction verisi

Transaction verisi market alışverişlerinde, bankalarda, yani yapılan işlemlerin kaydedildiği her yerde vardır. Burada her transaction bir müşteriyi göstermez; aynı müşteri art arda iki transaction gerçekleştirmiş olabilir. Transaction, o işlemde ne alındığını tutar. Banka verisinde yapılan işlemin türü, miktarı, nereye yapıldığı gibi bilgiler tutulur.

Transaction verisi genellikle market sepeti analizi (market basket analysis) denen yöntemlerde, yani hangi ürünlerin birlikte satıldığını bulmak için kullanılır. Hoca bu konunun ilerideki derslerde birliktelik analizi (association analysis) başlığı altında görüleceğini söyledi.

### 1.3 Transaction verisini kayıt verisine çevirmek

Slayttaki örnek (ekrandan, 00:05:00) şu beş transaction'dan oluşur:

| TID | Items |
|---|---|
| 1 | Bread, Coke, Milk |
| 2 | Beer, Bread |
| 3 | Beer, Coke, Diaper, Milk |
| 4 | Beer, Bread, Diaper, Milk |
| 5 | Coke, Diaper, Milk |

Bu veri, doküman verisine benzer biçimde her ürün için bir sütun açılarak kayıt verisine çevrilebilir. Ürün o transaction'da varsa 1, yoksa 0 yazılır. Burada sayı (adet) yoktur, bu yönüyle metin verisinden farklıdır:

| TID | Bread? | Coke? | Milk? | Diaper? | Beer? |
|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 0 | 0 |
| 2 | 1 | 0 | 0 | 0 | 1 |
| 3 | 0 | 1 | 1 | 1 | 1 |
| 4 | 1 | 0 | 1 | 1 | 1 |
| 5 | 0 | 1 | 1 | 1 | 0 |

Slaytta bu sütunlar asimetrik nitelik (asymmetric attributes) olarak işaretlenmiştir. Liste biçimi daha az yer (requires less space), tablo biçimi daha çok yer (requires more space) gerektirir. Slayttaki maddeler şunlardır (ekrandan, 00:05:00):

- Gerçek veride tablo, dikkate alınan ürün sayısına bağlı olarak yüzlerce ya da binlerce sütun içerir.
- Bir transaction'da alınan ürün sayısı (ör. 5), sütun sayısına göre çok küçüktür.
- Bu matristeki değerlerin çoğu 0'dır; böyle bir matrise seyrek matris (sparse matrix) denir.

Hoca "neden 0/1 tablo değil de liste biçiminde tutuyoruz?" sorusunu graflarla bağladı. Bir graf komşuluk matrisi ya da komşuluk listesi olarak tutulabilir. Graf çok yoğunsa (dense), örneğin her düğümden her düğüme yol olan tam bir grafsa, liste ve matris aynı boyuta yaklaşır. Transaction verisinde ise yüzlerce sütun vardır ve her satır 1/0 olarak tutulursa veri çok büyür. Liste biçiminde işlem yapmak daha zordur, çünkü bilgisayar programı listeyi satır satır okur ve bir elemana erişmek yavaştır. Burada hız ile bellek arasında bir ödünleşim vardır; ancak model bir kez eğitilir, sürekli yeniden eğitilmesi gerekmez. Bu yüzden hız çok önemli değildir, veri genellikle belleğe sığmadığı için transaction verisi liste biçiminde tutulur.

Böylece dersin ilk kısmı olan veri nesneleri ve nitelik tipleri bitirilmiş oldu.

## 2. Temel istatistiksel tanımlara neden ihtiyaç duyulur

Hoca bir sonraki bölümün, öğrencilerin çoğunun istatistikten bildiği ortalama, standart sapma, medyan, mod gibi tanımlar olduğunu söyledi ve önce bunlara neden ihtiyaç duyulduğunu sordu.

Henüz veri madenciliği yöntemlerine başlamadan, istatistikler veri hakkında ön bilgi verir. Bir veri bilimci olarak veriye "veri" gözüyle bakılır; oysa veriyi toplayan kişi bir bankacı ya da meteoroloji mühendisi olabilir ve onun veriye bakışı farklıdır. İstatistiksel ölçüler, verinin uzun süre boyunca toplanmış olsa bile içinde ne tür değişiklikler olduğunu gösterebilir. Hoca iki örnek verdi:

- Veri paradan sıfır atıldığı tarihten öncesine kadar gidiyorsa, kolonların değerleri bir anda değişmiş olur.
- Saat bilgisi toplanmışsa, eskiden uygulanan saatlerin bir saat ileri ya da geri alınması veride bir kırılma yaratır.

İstatistikler verinin ne tür bir dağılım gösterdiği ve nasıl değiştiği hakkında bilgi verir. İki grup ölçü vardır:

- Merkezi eğilim (central tendency): verinin genel eğilimini söyler. Ortalama (mean), medyan (median), mod (mode) ve midrange bu gruptadır.
- Yayılım (dispersion): verinin ne kadar yayıldığını söyler. Çeyrekler (quartiles) bu gruptadır.

Hoca bütün bu işlemlerin tek bir attribute için, yani verideki tek bir kolon için yapıldığını ayrıca vurguladı.

## 3. Merkezi eğilim ölçüleri

### 3.1 Aritmetik ortalama ve ağırlıklı ortalama

Aritmetik ortalama, bütün elemanlar toplanıp eleman sayısına bölünerek bulunur:

$$\bar{x} = \frac{1}{n}\sum_{i=1}^{n} x_i$$

Ağırlıklı ortalamada her eleman kendi ağırlığıyla çarpılarak toplanır ve toplam, eleman sayısına değil toplam ağırlığa bölünür (sözlü anlatımdan):

$$\bar{x}_w = \frac{\sum_{i=1}^{n} w_i x_i}{\sum_{i=1}^{n} w_i}$$

<!-- BELİRSİZ: Ağırlıklı ortalama slaytı karelerde yok; formül hocanın sözlü tarifinden yazıldı. -->

**Soru:** Ağırlıklı ortalama ne zaman kullanılır? **Cevap:** Öğrencilerden gelen cevaplardan biri not ortalamasıydı. Hoca bunu doğruladı: dersler AKTS'leriyle çarpılarak ortalama alınır. Bir değer yalnızca kendisiyle değil başka bir şeye de bağlıysa, örneğin dersin AKTS'sindeki 3 ya da 5 size ek bir bilgi veriyorsa, değerler bu ağırlıklarla çarpılıp toplanır.

<!-- BELİRSİZ: 00:09:00 civarındaki öğrenci cevabı altyazıda anlaşılmıyor. -->

### 3.2 Kırpılmış ortalama (trimmed mean)

Slayttaki açıklama şudur (ekrandan, 00:10:00): Ortalama, bir veri kümesini tanımlamak için en kullanışlı tek büyüklük olsa da verinin merkezini ölçmenin her zaman en iyi yolu değildir. Ortalamanın en büyük sorunu uç (outlier) değerlere duyarlı olmasıdır; az sayıda uç değer bile ortalamayı bozabilir. Bunu dengelemek için kırpılmış ortalama (trimmed mean) kullanılabilir. Kırpılmış ortalama, yüksek ve düşük uçlardaki değerler kesilip atıldıktan sonra elde edilir.

Hoca burada "uç değerleri nasıl bulacağım?" diye sordu. Bir öğrenci kümelemeyle bulunabileceğini söyledi; hoca bunun doğru olduğunu ama o konuya henüz gelinmediğini belirtti ve istatistiksel bir tanım yapılabileceğini, formülünün birazdan (IQR ile) gösterileceğini söyledi (bkz. Bölüm 7).

### 3.3 Medyan

Medyan için veri sıralanır ve ortadaki değer alınır. Eleman sayısı çiftse ortada tek bir eleman yoktur; örneğin altı eleman varsa üçüncü ve dördüncü elemanın ortalaması alınır.

Medyan genellikle sayısal veriye uygulanır, ama sıralı (ordinal) kategorik veriye de uygulanabilir. Ordinal veride büyüktür/küçüktür ilişkisinin bir anlamı vardı; bütün veri sıralanır ve ortasına bakılır.

Hoca ordinal veride medyanın ne bilgi verdiğini iki örnekle anlattı:

- Kullandığı bir sistemin, işlenen dosyaların bekleme süresini medyan ve %97'lik değer olarak verdiğini söyledi. Bekleme süreleri "az bekledi, orta bekledi, çok bekledi" gibi sıralı kategorilere çevrilip medyana bakılsaydı, medyanın bulunduğu kategori çok bekleyenler tarafına da düşebilirdi; yani bu durumda medyan çok şey söylemeyebilir.
- Kahve boyları küçük, orta, büyük olarak sıralanıp medyana bakıldığında, örneğin "alanların yarısı orta ve daha küçük boy almış" denebilir. Medyan hep küçükse buradan hep küçük boy satıldığı sonucu çıkar. Mod bu kategorilerde üçte bire yakın bir oranı gösterebilirken medyan dağılımın yarısının nereye düştüğünü söyler.

<!-- BELİRSİZ: Bekleme süresi örneğindeki sayılar altyazıda net değil; nota alınmadı. -->

### 3.4 Mod

Mod, en sık tekrar eden değerdir. Hoca modun nasıl hesaplanacağını sordu: $n$ elemanlı bir dizide her eleman için ayrı bir döngü çevrilerek $O(n^2)$ ile bulunabilir; ya da dizi $O(n \log n)$ ile sıralanır, sonra sıralı dizinin üzerinden bir kez geçilerek her değerin kaç kez geçtiği sayılır.

Slayttaki tanım ve özellikler (ekrandan, 00:15:00):

- Mod, bir veri kümesinde en sık geçen değerdir.
- En yüksek frekans birden çok değere karşılık gelebilir; bu durumda birden fazla mod olur.
- Bir, iki ya da üç modu olan veri kümelerine sırasıyla unimodal, bimodal ve trimodal denir.
- Diğer uçta, her değer yalnızca bir kez geçiyorsa mod yoktur.

> **Hocanın vurgusu:** Her şey bir kez geçiyorsa "mod yoktur" denir, "hepsi moddur" denmez.

Hoca ayrıca en çok geçen değerin örneğin 5 kez geçtiği ve 5 kez geçen üç farklı değerin bulunduğu durumu sordu ve bunun mümkün olduğunu söyledi. Bir modu olan veri unimodal, iki modu olan bimodal, üç modu olan trimodal diye adlandırılır.

> **Ders sonrası not:** Hoca bu durumda "modu yine 5'tir" dedi. 5 burada modun değeri değil, en yüksek frekanstır (geçme sayısı). Mod, 5 kez geçen üç değerin kendisidir; veri trimodaldir.

Aynı slaytta niteliğin türüne göre kullanılabilecek merkezi eğilim ölçüleri verilmiştir (ekrandan, 00:15:00):

| Nitelik türü | Merkezi eğilim ölçüleri |
|---|---|
| Sayısal (numerical) | Mean, Median, Mode |
| Kategorik (categorical) | Mode (Median?) |
| Nominal | Mode |
| Ordinal | Mode, Median |

## 4. Simetrik ve çarpık dağılımlar

Hoca bu kısmı öğrencilere çizdirerek tartıştırmayı planladığını, ama zaman nedeniyle doğrudan anlattığını söyledi.

Veri simetrikse, yani dağılım sağa ya da sola eğik (yatık) değilse, mean, median ve mode aynı yerdedir; tam eşit çıkmasa bile birbirine çok yakındır.

**Zor sınav örneği.** Ders çok zor geçmiş ve öğrencilerin çoğu düşük not almıştır; az sayıda yüksek not vardır. Bu dağılımda:

- Mod, en çok geçen değer olduğu için dağılımın tepesinde, düşük notlar tarafındadır.
- Mean, yüksek not alan az sayıdaki öğrenci tarafından yukarı çekilir; bu yüzden modun yüksek notlar tarafında kalır.
- Medyan ise veri sıralandığında düşük not alanlar çok fazla olduğu için mean'den önce gelir.

Sonuç: mode < median < mean.

**Kolay sınav örneği.** Ders çok kolaydır, neredeyse herkes geçmiştir, bir iki kişi kalmıştır. Sıralandığında sınıfın yarısından fazlası en yüksek notu almıştır; bu yüzden medyan moda çok yakındır. Mean ise kalan birkaç öğrenci ve düşük not alanlar yüzünden medyandan küçüktür.

Sonuç: mean < median < mode.

> **Ek bilgi (derste anlatılmadı):** Sağ kuyruğu uzun olan (zor sınav) dağılıma pozitif çarpık ya da sağa çarpık, sol kuyruğu uzun olan (kolay sınav) dağılıma negatif çarpık ya da sola çarpık dağılım denir.

**Soru:** Bu sıralama her dağılımda böyle olmak zorunda mı? (ör. birden çok tepesi olan, dalgalı bir dağılımda) **Cevap:** Hoca bu tür dağılımlarda genellikle çok dalga olmadığını, ama sıralamanın her zaman böyle olmak zorunda olmayabileceğini söyledi; cevabı kesin bilmediğini, birkaç örnek üzerinde bakıp düşüneceğini belirtti.

<!-- BELİRSİZ: 00:17:53-00:18:24 arasındaki öğrenci sorusu altyazıda tam duyulmuyor; soru metni bağlamdan kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Mode < median < mean sıralaması tek tepeli ve belirgin çarpık dağılımlar için genel bir eğilimdir; çok tepeli ya da düzensiz dağılımlarda bu sıralama bozulabilir.

## 5. Merkezi eğilim örneği

Slayttaki soru (ekrandan, 00:20:00): Aşağıdaki nitelikler için merkezi eğilim ölçüleri (mean, median, mode) nedir?

- attr1 = {2,4,4,6,8,24}
- attr2 = {2,4,7,10,12}
- attr3 = {xs,s,s,s,m,m,l}

**attr1.** Toplam $2+4+4+6+8+24 = 48$, eleman sayısı 6:

$$\text{mean} = \frac{48}{6} = 8$$

Veri zaten sıralıdır ama eleman sayısı çift olduğu için ortada tek bir eleman yoktur; ortadaki iki eleman 4 ve 6'dır:

$$\text{median} = \frac{4+6}{2} = 5$$

En çok geçen değer 4'tür (iki kez), mod = 4. Burada 24 değeri ortalamayı medyanın üstüne çekmiştir.

**attr2.** Toplam $2+4+7+10+12 = 35$, eleman sayısı 5: mean = 7. Eleman sayısı tek olduğu için medyan doğrudan ortadaki eleman, yani 7'dir. Her değer bir kez geçtiği için mod yoktur.

**attr3.** Bu veri ordinal veridir: değerler büyüklüğe göre (xs < s < m < l) sıralanabilir. Sıralanamasaydı medyan bulunamazdı. Toplanabilecek sayısal bir şey olmadığı için mean yoktur. Sıralı yedi elemanın ortası (4. eleman) s olduğundan medyan = s. Üç kez geçen s en sık değer olduğu için mod = s.

**Soru (hocanın sorusu):** attr3'te 7 değil 6 eleman olsaydı medyan nasıl bulunurdu? **Cevap:** Ordinal değerlerde ortadaki iki değerin ortalaması alınamaz, bu yüzden "medyan yoktur" denir. Ancak veri sıralı olduğu için ortadaki iki değerin ikisi de s ise, buradan medyanın s'ye düştüğü çıkarılabilir. Hoca bunun kullanılan araca göre değiştiğini söyledi: bazı araçlar "yoktur" der, bazıları bu durumda s değerini verir.

Python ile kontrol: attr1 için mean = 8, median = 5.0, mode = 4; attr2 için mean = 7, median = 7.

## 6. Verinin yayılımı: range, çeyrekler, IQR, varyans

Slayttaki tanım (ekrandan, 00:25:00): Sayısal verinin yayılma derecesine verinin yayılımı (dispersion) ya da varyansı (variance) denir. En yaygın yayılım ölçüleri şunlardır.

### 6.1 Range

Range (aralık), en büyük ve en küçük değer arasındaki farktır: maksimum − minimum. Hoca burada da bu ölçülerin her biri için tek bir attribute'un, yani verideki tek bir kolonun kullanıldığını hatırlattı.

### 6.2 Çeyrekler ve IQR

Çeyrekler (quartiles) dağılımı dört parçaya böler. Q1 birinci çeyreğin bittiği yerdir (25. yüzdelik), Q3 üçüncü çeyreğin bittiği yerdir (75. yüzdelik). Q2 ise medyandır.

Çeyrekler şöyle bulunur: veri sıralanır, önce medyan (Q2) bulunur. Veri medyandan iki parçaya bölünür; alt yarının medyanı Q1'i, üst yarının medyanı Q3'ü verir. Parçalardan birinde eleman sayısı çiftse, medyanda olduğu gibi ortadaki iki elemanın ortalaması alınır.

Çeyrekler arası aralık (interquartile range, IQR), ortadaki %50'lik kısmın aralığıdır (ekrandan, 00:25:00):

$$IQR = Q3 - Q1$$

**Soru:** Çeyrekler neden önemlidir? **Cevap:** Hoca, çeyreklerin aykırı değerleri belirlerken kullanılabildiğini söyledi. Ayrıca Q1 ile Q3 arasındaki uzaklık dağılımın uçlarında ne kadar eleman olduğunu söyler. Dağılımın yüksekliğine ve biçimine göre Q1–Q3 arasındaki bölge değişir; bu da verinin merkezde ne kadar toplandığını gösterir. Dar bir IQR verinin merkezde toplandığını, geniş bir IQR verinin yayıldığını gösterir.

<!-- BELİRSİZ: 00:23:06 civarında bir öğrencinin çeyreklerle ilgili verdiği örnek (vergilendirme vb.) altyazıda net değil; hoca "o ayrı" diyerek konuya döndü. -->

### 6.3 Varyans ve standart sapma

Varyans şöyle hesaplanır: her elemandan ortalama çıkarılır, farkın karesi alınır, karelerin toplamı eleman sayısına bölünür. Standart sapma, varyansın kareköküdür. Slayttaki formüller (ekrandan, 00:25:00), $\mu$ gözlemlerin ortalaması olmak üzere:

$$\sigma^2 = \frac{1}{n}\sum_{i=1}^{n}(x_i - \mu)^2 \qquad s^2 = \frac{1}{n-1}\sum_{i=1}^{n}(x_i - \mu)^2$$

Burada $\sigma$ popülasyon (population), $s$ örneklem (sample) içindir. Standart sapma $\sigma$ ($s$), varyans $\sigma^2$'nin ($s^2$) kareköküdür.

Standart sapma, değerlerin ortalamadan ne kadar saptığını gösterir. Bütün elemanlar ortalamaya eşit olsaydı varyans sıfır olurdu. Varyans ne kadar büyükse elemanlar ortalamadan o kadar uzaktadır ve dağılım o kadar yayvandır.

Hoca $n-1$'e bölünen ifadenin örneklem ile popülasyon ayrımından geldiğini, örneklemde $n$ yerine $n-1$'e bölündüğünü söyledi. Bazı hesaplarda bu kullanılır; ancak öğrencilerin bunun kafalarını karıştırmasına izin vermemelerini, varyans ve standart sapma için temel tanıma odaklanmalarını istedi.

## 7. Aykırı değerler, beş sayı özeti ve kutu grafiği

### 7.1 IQR ile aykırı değer

Hoca dersin başında sorulan "aykırı değerler istatistiksel olarak belirlenebilir mi?" sorusuna geri döndü. IQR, yani Q3 − Q1, 1.5 ile çarpılır. Bu bir aralık verir: Q1'in 1.5·IQR altından ve Q3'ün 1.5·IQR üstünden, yani sağlı sollu bu aralığın dışında kalan değerler aykırı değer (outlier) kabul edilir:

$$x < Q1 - 1.5 \cdot IQR \quad \text{ya da} \quad x > Q3 + 1.5 \cdot IQR$$

Hoca çarpanın 1, 2 ya da 3 alınmasıyla neyin aykırı sayılacağının değiştiğini de belirtti; derste kullanılan çarpan 1.5'tir.

### 7.2 Beş sayı özeti

Bir dağılım beş değerle özetlenebilir: minimum, Q1, medyan, Q3 ve maksimum. Buna beş sayı özeti (five number summary) denir (ekrandan, 00:25:00). Bu beş değer verildiğinde dağılımın aşağı yukarı nasıl olduğu tahmin edilebilir.

### 7.3 Kutu grafiği (boxplot)

Hoca veriyi görselleştirme yöntemlerinden ilki olarak kutu grafiğini (boxplot) anlattı. Slayttaki maddeler şunlardır (ekrandan, 00:30:00):

- Kutu grafikleri bir dağılımı görselleştirmenin yaygın bir yoludur ve beş sayı özetini içerir.
- Kutunun uçları Q1 ve Q3 çeyrekleridir; böylece kutunun boyu IQR olur.
- Medyan, kutunun içinde bir çizgiyle işaretlenir.
- Kutunun dışına uzanan iki çizgi, aykırı değerler hariç en küçük ve en büyük gözleme kadar uzanır. Aykırı değerler ayrıca işaretlenir.
- Aykırı değer yoksa alt uç çizgisi en küçük gözlem (minimum), üst uç çizgisi en büyük gözlem (maksimum) olur.

Slayttaki çizimde soldan sağa şu öğeler vardır: aykırı değerler (nokta), Lower Extreme, Lower Quartile, Median, Upper Quartile, Upper Extreme, aykırı değerler (nokta).

Hoca grafiği yatay gösterse de kutu grafiklerinin genellikle dikey çizildiğini söyledi. Kutu kısa ise Q1 ile Q3 birbirine çok yakındır, yani IQR küçüktür ve sapma azdır. Uçlardaki çizgiler minimum ve maksimum gibi görünse de tam olarak öyle değildir; bu yüzden bunlara "extreme" denir, çünkü aykırı değerler bu çizgilerin dışında ayrı noktalar olarak gösterilir. 1.5·IQR sınırının dışına düşen değerler bu noktalardır.

**Soru:** Kutu grafiğinden mod okunabilir mi? **Cevap:** Hoca bunun her zaman mümkün olmadığını söyledi; bazı dağılımlarda mod belirli bir değere yakın olabilir, ama kutu grafiğinin her zaman bu bilgiyi vereceği söylenemez.

<!-- BELİRSİZ: 00:31:06-00:31:39 arasındaki soru-cevap altyazıda bozuk; içerik bağlamdan kuruldu. -->

**Soru:** Standart sapma tek bir sabit değer midir, yani "standart" bir sapma ve onun dışında kalan sapmalar mı vardır? **Cevap:** Hayır. Nasıl her dağılımın bir ortalaması varsa, her dağılımın da bir standart sapması vardır. Standart sapma dağılımdan hesaplanır; her dağılım için ayrı bir değerdir. Ayrıca kutu grafiğinde standart sapma doğrudan görülmez.

## 8. Yayılım örneği

Slayttaki soru (ekrandan, 00:35:00): İki niteliğin değerleri şöyledir:

- attr1: {2,3,4,5,6,7,8,9}
- attr2: {1,5,9,10,11,12,18,30}

**a) Hesaplamadan, hangisinin standart sapması daha büyüktür?** Cevap: attr2. attr1 birer birer artarken attr2'de 30 değeri vardır. Standart sapmada her elemandan ortalama çıkarılır; 30 ortalamadan çok uzakta olduğu için attr2'nin standart sapması daha büyük çıkar.

Python ile kontrol (derste hesaplanmadı): attr1 için popülasyon standart sapması yaklaşık 2.29, örneklem standart sapması yaklaşık 2.45; attr2 için sırasıyla yaklaşık 8.25 ve 8.82.

**b) IQR'leri verin.** Önce medyan bulunur, sonra iki yarının medyanları alınır.

attr1: medyan $(5+6)/2 = 5.5$. Alt yarı {2,3,4,5}, üst yarı {6,7,8,9}.

$$Q1 = \frac{3+4}{2} = 3.5, \qquad Q3 = \frac{7+8}{2} = 7.5, \qquad IQR = 7.5 - 3.5 = 4$$

attr2: medyan $(10+11)/2 = 10.5$. Alt yarı {1,5,9,10}, üst yarı {11,12,18,30}.

$$Q1 = \frac{5+9}{2} = 7, \qquad Q3 = \frac{12+18}{2} = 15, \qquad IQR = 15 - 7 = 8$$

Medyanların değeri (5.5 ve 10.5) slaytta yazılmamıştır (ara adım eklendi).

> **Hocanın vurgusu:** Q1 ve Q3 bulunurken önce medyan bulunur, sonra iki yarının her birinin medyanı alınır. Hoca örneği çözerken önce veriyi doğrudan dört eşit gruba bölüp ara değerleri yanlış söylediğini fark etti ve "benim yaptığım hatayı yapmayın" dedi.

> **Ders sonrası not:** Hoca çözüm sırasında sözlü olarak farklı ara değerler söyledi (altyazıda 2,5 ve 6,5 geçiyor); slayttaki doğru değerler attr1 için Q1 = 3.5 ve Q3 = 7.5'tir. Slaytta IQR "3.5-7.5 = 4" biçiminde yazılmıştır; doğru gösterim $Q3 - Q1 = 7.5 - 3.5 = 4$'tür.

<!-- BELİRSİZ: 00:33:36-00:36:43 arasında hocanın sözlü çözümündeki ara sayılar altyazıda bozuk; değerler slayttan alındı. -->

**c) IQR'ye göre bu veri kümelerinde aykırı değer var mı?** Cevap: Evet, attr2'deki 30.

$$Q3 + 1.5 \cdot IQR = 15 + 1.5 \cdot 8 = 27 < 30$$

attr2'nin alt sınırı $7 - 12 = -5$ olduğu için alt tarafta aykırı değer yoktur. attr1'de sınırlar $3.5 - 6 = -2.5$ ve $7.5 + 6 = 13.5$'tir; bütün değerler bu aralıkta olduğu için aykırı değer yoktur (bu iki sınır derste hesaplanmadı, ara adım eklendi).

**d) Standart sapması sıfır olan 4 elemanlı bir veri kümesi verin.** Cevap: {1,1,1,1}. Standart sapmada ortalama her elemandan çıkarılır; bütün değerler aynıysa hepsi ortalamaya eşittir ve fark sıfırdır. Grafik olarak düşünülürse dağılım tek bir çubuktan oluşur, hiçbir yere sapma yoktur; standart sapma sıfırdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): attr1 = {2,4,4,6,8,24}, attr2 = {2,4,7,10,12}, attr3 = {xs,s,s,s,m,m,l} nitelikleri için mean, median ve mode nedir?

> **Çözüm (derste verildi):** attr1: mean = 48/6 = 8, median = (4+6)/2 = 5, mode = 4. attr2: mean = 35/5 = 7, median = 7, mod yok. attr3: ordinal olduğu için mean yok, median = s, mode = s.

**Soru 2** (derste sözlü, 00:20:10): attr3 gibi ordinal bir nitelikte eleman sayısı çift olsaydı medyan nasıl bulunurdu?

> **Çözüm (derste verildi):** Ordinal değerlerin ortalaması alınamaz; bu yüzden medyan yoktur denir. Ortadaki iki değer aynıysa bazı araçlar o değeri medyan olarak verir.

**Soru 3** (derste sözlü, 00:15:42): Çoğu öğrencinin düşük not aldığı zor bir sınavın not dağılımında mean, median ve mode nasıl sıralanır? Çoğu öğrencinin yüksek not aldığı kolay bir sınavda nasıl sıralanır?

> **Çözüm (derste verildi):** Zor sınavda mode < median < mean; kolay sınavda mean < median < mode.

**Soru 4** (derste sözlü, 00:13:39): $n$ elemanlı bir dizide mod nasıl bulunur, karmaşıklığı nedir?

> **Çözüm (derste verildi):** Her eleman için sayarak $O(n^2)$; ya da $O(n \log n)$ ile sıralayıp sıralı dizi üzerinden bir kez geçerek her değerin sıklığını sayarak.

**Soru 5** (ekrandan, 00:35:00): attr1: {2,3,4,5,6,7,8,9} ve attr2: {1,5,9,10,11,12,18,30} veriliyor. (a) Hesaplamadan hangisinin standart sapması daha büyüktür? (b) IQR'leri verin. (c) IQR'ye göre aykırı değer var mı? (d) Standart sapması sıfır olan 4 elemanlı bir veri kümesi verin.

> **Çözüm (derste verildi):** (a) attr2. (b) attr1: Q1 = 3.5, Q3 = 7.5, IQR = 4; attr2: Q1 = 7, Q3 = 15, IQR = 8. (c) Evet, attr2'deki 30, çünkü 30 > 15 + 1.5·8 = 27. (d) {1,1,1,1}.

## Dersin Toparlaması

Ders, veri tiplerinin son parçası olan doküman ve transaction verisiyle başladı. Doküman verisinin terim vektörüyle tutulduğu, nadir terimlerin eşikle atıldığı; transaction verisinin 0/1 tabloya çevrilebildiği ama bu tablonun büyük ve seyrek olacağı için genellikle liste biçiminde tutulduğu görüldü. Böylece veri nesneleri ve nitelik tipleri bölümü tamamlandı.

Ardından verinin temel istatistiksel tanımlarına geçildi. Merkezi eğilim için aritmetik, ağırlıklı ve kırpılmış ortalama, medyan ve mod; hangi nitelik türüne hangi ölçünün uygulanabileceği; simetrik ve çarpık dağılımlarda mean, median ve mode'un sıralaması anlatıldı. Yayılım için range, çeyrekler, IQR, varyans ve standart sapma tanımlandı; IQR'nin 1.5 katıyla aykırı değer belirleme, beş sayı özeti ve bunu görselleştiren kutu grafiği işlendi. İki slayt örneğiyle merkezi eğilim ve yayılım ölçüleri hesaplandı. Hoca ara verirken daha çok slayt olduğunu söyledi; anlatım büyük olasılıkla bir sonraki kayıtta bu bölümün kalan slaytlarıyla sürmektedir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
