# Ders 8 Genişletilmiş Notu: Blok Analizi, EM ve Gibbs Örneklemesi, Markov Modelleri ve Filogenetiğe Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Blok Analizi
- 2. Beklenti-Maksimizasyon (EM) Algoritması
- 3. EM Örneği: Sayımlar ve Frekanslar
- 4. Yalancı Sayımlar (Pseudocounts)
- 5. EM Örneği: Maksimizasyon Adımı
- 6. EM Kullanan Programlar
- 7. Gibbs Örneklemesi
- 8. Gizli Markov Modelleri ve Markov Zincirleri
- 9. CpG Adaları ve Markov Modelleriyle Ayırt Etme
- 10. PSSM, Entropi ve Dizi Logoları
- 11. Dizi Dosya Biçimleri (Hatırlatma)
- 12. Filogenetiğe Giriş
- 13. Ağaç Terimleri ve Ağaç Sayısı
- Örnek Sorular
- Dersin Toparlaması

## 1. Blok Analizi

Ders, önceki derste başlanan lokal çoklu dizi hizalama (local multiple sequence alignment) konusunun devamıyla açıldı. Anlatım büyük ölçüde İngilizce yapıldı. Önceki derste anlatılan birinci yöntem profillerdi; bu derste ikinci yöntem olan **blok analizi** ele alındı.

### 1.1 Blok ile profil arasındaki fark

Bloklar, profiller gibi, bir çoklu dizi hizalamasındaki lokal olarak korunmuş bölgeleri temsil eder. Aradaki fark boşluklardır. Ekleme ve silme olaylarına kısaca indel denir; karakter yerleşimi açısından bunlar boşluk (gap) olarak görünür. Bloklarda hiç boşluk yoktur, yani dizilerde ekleme ya da silme konumu bulunmaz. Bloğun her sütunu yalnız eşleşme (match) ve uyuşmazlık (mismatch) içerir.

> **Hocanın vurgusu:** Bloklarla profiller arasındaki fark budur: bloklarda boşluk yoktur.

### 1.2 Blokların bulunması

Bloklar iki yolla bulunabilir:

- Önce bir çoklu dizi hizalaması yapılır, sonra boşluksuz bölgeler bloklara ayrılır. Genellikle bu yol izlenir.
- Veri tabanında aynı uzunlukta benzer diziler aranır.

Blok aramak için birçok algoritma vardır. Hoca, çoklu dizi hizalamasında genel olarak olduğu gibi, bu algoritmaların hepsinin sezgisel (heuristic) olduğunu, optimal olmadığını yineledi. En benzer dizileri bulmak için istatistiksel yaklaşımlar önerilmiştir (ekrandan, 00:10:00):

- Beklenti-Maksimizasyon (Expectation-Maximization, EM) algoritmaları,
- Gibbs örnekleyicisi (Gibbs sampler).

Bir blok kümesi belirlendikten sonra blok hizalamasındaki bilgi bir dizi profili olarak da gösterilebilir (ekrandan, 00:10:00).

Hoca bu iş için yaygın kullanılan iki paket andı: BLOCKS ve eMOTIF <!-- BELİRSİZ: ikinci paket adı altyazıda "emotive" diye geçiyor, karede görülmedi -->. Bu paketlerin hangi algoritmayı uyguladığını bilmediğini, ama yaygın kullanıldıklarını söyledi.

### 1.3 Protein kinaz örneği

Örnek olarak 10 protein kinaz dizisinin kesilmiş (truncated) bölümleri gösterildi. Hoca "truncated" sözcüğünü "kısaltılmış, yalnızca bir alt kümesi alınmış" diye açıkladı. Diziler yaklaşık 75 kalıntı uzunluğundadır.

Protein kinaz, diğer proteinlere kimyasal olarak fosfat grubu ekleyerek onları değiştiren bir enzimdir; bu işleme fosforilasyon denir. Hoca insan genomunun yaklaşık 500 protein kinaz geni içerdiğini, bunların bütün insan genlerinin yaklaşık %2'si olduğunu, insan proteinlerinin %30'a kadarının kinaz etkinliğiyle değiştirilebildiğini ve kinazların hücre yolaklarının çoğunu düzenlediğini söyledi.

Ekrandaki hizalamada AF1, MOS, DGM, GFR, D28, SKH, APK, EE1, FES ve SVK adlı on dizi vardır. BLOCKS sunucusu iki boşluksuz blok bulmuştur; altta `cons` satırında korunmuş kalıntılar gösterilir (ekrandan, 00:15:00):

```text
cons 1   qf ll  lgsgsfg vykg   g     k  i v    k        r       v  l   i
         |----- 1. blok -----|      |------------ 2. blok ------------|
```

Birinci bloğun korunmuş çekirdeği `lgsgsfg vykg` örüntüsüdür; örneğin AF1 dizisinde `LGSGSFGTVYKG`, GFR dizisinde `LGSGAFGTVYKG` görülür (ekrandan, 00:15:00).

## 2. Beklenti-Maksimizasyon (EM) Algoritması

EM algoritması, hizalanmamış proteinlerde korunmuş bölgeleri (domain) ve hizalanmamış DNA dizilerinde protein bağlanma bölgelerini bulmak için yaygın olarak kullanılmıştır; boşluk içerebilen bazı bölgeler bile bulunabilir.

### 2.1 Başlangıç

Başlamadan önce aranan sinyalin (motifin) yaklaşık uzunluğu verilmelidir. Sonra her dizide ilgilenilen bölgenin yeri ve büyüklüğü için bir ilk tahmin yapılır. Bu genellikle rastgele yapılır: motifin her dizideki konumu rastgele atanır.

### 2.2 İki adım

Adından da anlaşıldığı gibi EM iki adımdan oluşur ve bu adımlar art arda tekrarlanır (ekrandan, 00:20:00):

- **Beklenti adımı (expectation step):** Arka plan kalıntı frekansları, başlangıçta hizalanmış bölgelerin (blokların) dışında kalan kalıntılardan hesaplanır. Ardından başlangıç motif hizalamasının her konumu (sütunu) için sütuna özgü kalıntı frekansları hesaplanır. Blok belirlendiğinde elimizde satır ve sütunlardan oluşan bir matris vardır.
- **Maksimizasyon adımı (maximization step):** Beklenti adımında bulunan, bölgenin her konumundaki kalıntı sayımları kullanılarak her dizide motif örüntüsüne en iyi uyan konum hesaplanır. Bu işlem her dizi için yapılır (ekrandan, 00:25:00).

Yeni motif konumları bulununca beklenti adımı tekrarlanır. Döngü çözüm yakınsayana kadar sürer (ekrandan, 00:25:00).

Hoca kalıntı kavramını açıkladı: kalıntı (residue) aslında bir karakter dizisindeki karakterdir. Amino asit dizilerinde 20 karakter, DNA'da 4 karakter vardır. Frekans ile kastedilen, veri dizisindeki kalıntıların (karakterlerin) sayısıdır. Bu frekanslardan sonra olasılık değerleri hesaplanır; bu olasılıklar aslında frekansların basit oranlarıdır.

## 3. EM Örneği: Sayımlar ve Frekanslar

### 3.1 Başlangıç bloğu

Örnekte çoklu hizalanmış DNA dizileri ve rastgele belirlenmiş bir blok vardır. Blok uzunluğu 6'dır; blok, her dizideki vurgulanmış alt dizilerden oluşur. Hoca dizileri saydı: 29 dizi vardır. Böylece blok 29 satır ve 6 sütundan oluşan bir matris olarak düşünülebilir ($29 \times 6$). Başlangıç hizalaması rastgele seçilmiş bölgelerden oluşur.

### 3.2 Yedi frekans kümesi

Bu hizalamadan her bazın görülme frekansı hesaplanır. Aranan motif 6 baz genişliğinde olduğu için yedi ayrı frekans kümesi gerekir: biri arka plan için, altısı motifin her sütunu için (ekrandan, 00:30:00).

Tablonun doldurulması şöyledir: bloğa gidilir ve 1. konumdaki A'lar sayılır. Hoca 1. konumdaki A'ları tek tek işaretleyerek 6 tane buldu. Sonra 1. konumdaki C'ler, G'ler ve T'ler sayılır; aynı işlem 2.-6. konumlar için tekrarlanır. Arka plan için blok dışında kalan bütün bazlar sayılır.

<!-- BELİRSİZ: Sayım tablosunun (ham sayılar) karesi yok; yalnız arka plandaki A sayısı (279) ve toplam (1046) altyazıdan alındı. -->

### 3.3 Kategorik veriden sayısal veriye

Hoca burada veri türüne dikkat çekti. Dizi verisi kategoriktir; hatta sıralı (ordinal) bile değil, nominaldir. EM'in ilk işi bu nominal veriyi frekans yoluyla sayısal veriye çevirmektir.

### 3.4 Gözlenen frekanslar

Sayımlar oranlara çevrilince gözlenen frekans tablosu elde edilir. Hoca arka plandaki A frekansını şöyle hesapladı:

$$\frac{279}{1046} \approx 0.2667 \approx 0.267$$

Diğer hücreler de aynı biçimde, ilgili sayım bölü ilgili toplam olarak hesaplanır. Gözlenen frekans tablosu (ekrandan, 00:35:00):

| Nükleotit | 0 (arka plan) | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| A | 0.267 | 0.209 | 0.414 | 0.209 | 0.209 | 0.379 | 0.241 |
| C | 0.267 | 0.276 | 0.103 | 0.172 | 0.241 | 0.241 | 0.241 |
| G | 0.216 | 0.310 | 0.276 | 0.345 | 0.241 | 0.172 | 0.276 |
| T | 0.250 | 0.209 | 0.209 | 0.276 | 0.310 | 0.209 | 0.241 |

> **Ders sonrası not:** Motif sütunlarındaki değerler 29 diziye bölünmüş sayımlarla uyumludur (python ile kontrol edildi): $0.414 = 12/29$, $0.103 = 3/29$, $0.345 = 10/29$, $0.379 = 11/29$, $0.310 = 9/29$, $0.276 = 8/29$, $0.241 = 7/29$, $0.172 = 5/29$. Hocanın 1. konumda saydığı 6 A için oran $6/29 \approx 0.207$ olur; slayttaki $0.209$ büyük olasılıkla yuvarlama hatasıdır. Arka plan sütunu da $1046$ toplamıyla büyük olasılıkla A: 279, C: 279, G: 226, T: 262 sayımlarına karşılık gelir (ara adım eklendi; bu sayılar derste yalnız A için söylendi).

## 4. Yalancı Sayımlar (Pseudocounts)

Doğrudan oran almak, bazı hücrelerde sayım sıfır olduğunda sorun çıkarır: o hücrenin olasılığı sıfır olur. Sıfır sayım ve verinin aşırı öğrenilmesi (overtraining) sorununu hafifletmek için gözlenen sayımlara **yalancı sayım** (pseudocount) eklenir. Bu durumda $c$ sütunundaki $a$ nükleotidinin frekansı (ekrandan, 00:40:00):

$$P_{ca} = \frac{n_{ca} + b_{ca}}{N_c + B_c}$$

Burada:

- $P_{ca}$: $c$ sütununda $a$ kalıntısının frekansı (olasılığı),
- $n_{ca}$: $c$ sütunundaki $a$ sayısı,
- $b_{ca}$: $c$ sütununda $a$ için yalancı sayım,
- $N_c$: $c$ sütunundaki toplam sayım,
- $B_c$: $c$ sütunundaki toplam yalancı sayım.

Yani doğrudan "$a$ sayısı / toplam" oranı yerine, pay ve paydaya yalancı sayımlar eklenmiş, biraz değiştirilmiş bir oran kullanılır. Yalancı sayımın seçimi keyfidir; belirli bir kuralı yoktur. Örneğin dört nükleotidin eşit olasılıklı olduğu varsayılır ve toplam yalancı sayım 1 seçilirse, her nükleotit için yalancı sayım $b_{ca} = 1/4$ olur.

Böylece ikinci aşamaya, yani frekanslardan olasılık değerlerine geçilir: önce frekanslar belirlenir, sonra olasılıklara çevrilir.

## 5. EM Örneği: Maksimizasyon Adımı

### 5.1 Adayların taranması

Beklenti adımında motifin kalıntı frekansları, motif bölgesinin bileşimini tahmin etmek için kullanılır. Bu adım, bölgenin içindeki ve dışındaki diziler arasında en iyi ayrımı yapmaya çalışır. Her dizi için olası her motif konumu, mevcut motife göre en olası konumu bulmak amacıyla tek tek değerlendirilir (ekrandan, 00:45:00).

Birinci diziyi ele alalım (ekrandan, 00:45:00):

```text
TCAGAACCAGTTATAAATTTATCATTTCCTTCTCCACTCCT
```

Bu dizide başlangıç bloğu (vurgulanmış) `ATTTAT`'tır. Dizide 41 kalıntı vardır; 6 uzunluklu bir pencere için değerlendirilecek konum sayısı:

$$41 - 6 + 1 = 36$$

### 5.2 Skor tablosu

Her aday 6'lı için, gözlenen frekans tablosundan ilgili konum olasılıkları alınır ve çarpılır. Örneğin `CAGTTA` için 1. konumdaki C'nin olasılığı, 2. konumdaki A'nın olasılığı, 3. konumdaki G'nin olasılığı vb. tablodan okunur. Hoca 1. konumdaki C olasılığının $0.263$ olduğunu söyledi. Ekrandaki skor tablosunun ilk 18 satırı (ekrandan, 00:50:00):

| Aday | 1 | 2 | 3 | 4 | 5 | 6 | Çarpım | RANDOM | ODDS |
|---|---|---|---|---|---|---|---|---|---|
| TCAGAA | .241 | .230 | .256 | .226 | .289 | .263 | 0.000244 | 0.000274 | 0.89 |
| CAGAAC | .263 | .296 | .246 | .256 | .289 | .256 | 0.000363 | 0.000362 | 1.00 |
| AGAACC | .256 | .233 | .256 | .256 | .256 | .256 | 0.000256 | 0.000362 | 0.71 |
| GAACCA | .240 | .296 | .256 | .256 | .256 | .263 | 0.000313 | 0.000362 | 0.87 |
| AACCAG | .256 | .296 | .243 | .256 | .289 | .233 | 0.000317 | 0.000362 | 0.88 |
| ACCAGT | .256 | .230 | .243 | .256 | .213 | .248 | 0.000193 | 0.000274 | 0.71 |
| CCAGTT | .263 | .230 | .256 | .226 | .241 | .248 | 0.000209 | 0.000257 | 0.81 |
| **CAGTTA** | .263 | .296 | .246 | .261 | .241 | .263 | 0.000317 | 0.000257 | **1.23** |
| AGTTAT | .256 | .233 | .254 | .261 | .289 | .248 | 0.000283 | 0.000241 | 1.18 |
| GTTATA | .240 | .241 | .254 | .256 | .241 | .263 | 0.000238 | 0.000241 | 0.99 |
| TTATAA | .241 | .241 | .256 | .261 | .289 | .263 | 0.000295 | 0.000297 | 0.99 |
| TATAAA | .241 | .296 | .254 | .256 | .289 | .263 | 0.000353 | 0.000297 | 1.19 |
| ATAAAT | .256 | .241 | .256 | .256 | .289 | .248 | 0.000290 | 0.000318 | 0.91 |
| TAAATT | .241 | .296 | .256 | .256 | .241 | .248 | 0.000279 | 0.000297 | 0.94 |
| AAATTT | .256 | .296 | .256 | .261 | .241 | .248 | 0.000303 | 0.000297 | 1.02 |
| AATTTA | .256 | .296 | .254 | .261 | .241 | .263 | 0.000318 | 0.000297 | 1.07 |
| ATTTAT | .256 | .241 | .254 | .261 | .289 | .248 | 0.000293 | 0.000278 | 1.05 |
| TTTATC | .241 | .241 | .254 | .256 | .241 | .256 | 0.000233 | 0.000278 | 0.84 |

Sütunların anlamı şöyledir: 1-6 sütunları adayın her konumdaki harfinin motif olasılığıdır; "1\*2\*3\*4\*5\*6" bunların çarpımıdır (motif modeline göre olasılık); RANDOM, aynı 6'lının arka plan modeline göre olasılığıdır; ODDS ise çarpım / RANDOM oranıdır.

`CAGTTA` için adım adım:

$$0.263 \times 0.296 \times 0.246 \times 0.261 \times 0.241 \times 0.263 \approx 0.000317$$

Arka plan olasılığı, arka plan frekanslarıyla (C: 0.267, A: 0.267, G: 0.216, T: 0.250):

$$0.267 \times 0.267 \times 0.216 \times 0.250 \times 0.250 \times 0.267 \approx 0.000257$$

$$\text{ODDS} = \frac{0.000317}{0.000257} \approx 1.23$$

Hoca skorları karşılaştırınca bu değerin en büyük olduğunu gösterdi. En yüksek skorlu alt dizi seçilir ve bir sonraki tur için bu dizinin yeni motif konumu olur. Bu işlem çoklu hizalamadaki her dizi için yapılır.

> **Ders sonrası not:** Tablodaki çarpım ve ODDS değerleri python ile kontrol edildi ve satırlardaki olasılıklarla tutarlı. Ancak RANDOM sütununda `CAGAAC`, `AGAACC`, `GAACCA`, `AACCAG` için yazılan $0.000362$, arka plan frekanslarıyla hesaplanan $0.000293$ ile uyuşmuyor; `TATAAA` için de $0.000297$ yerine $0.000318$ çıkıyor. Bu büyük olasılıkla slayttaki bir kopyalama hatasıdır. Düzeltilmiş değerle `CAGAAC`'ın oranı yaklaşık $1.24$ olur ve `CAGTTA`'yı ($1.23$) çok az geçer. Ayrıca skor tablosundaki konum olasılıkları (ör. 1. konumda C için $0.263$) gözlenen frekans tablosundaki değerlerden ($0.276$) farklıdır; derste açıklanmadı, büyük olasılıkla yalancı sayım eklenmiş bir tablodan alınmıştır.

### 5.3 Döngü ve yakınsama

Her dizi için yeni konum seçilince yeni bir blok ve dolayısıyla yeni frekanslar elde edilir. Beklenti-maksimizasyon döngüsü sonuçlar bir motif kümesinde yakınsayana kadar tekrarlanır. Hoca örnek verdi: 50 döngü yapıldığını ve sonunda hep aynı blokların bulunduğunu düşünelim; bloklar artık değişmiyorsa algoritma yakınsamıştır.

## 6. EM Kullanan Programlar

Aradan sonra hoca EM kullanan programları tanıttı (ekrandan, 01:05:00):

- **MEME:** Multiple EM for Motif Elicitation. Anlatılan EM yöntemlerini kullanan bir programdır; EM onun temel yaklaşımıdır.
- **ParaMEME:** MEME'nin bir türevi; EM algoritmasıyla blok arar.
- **Meta-MEME:** Profilleri gizli Markov modelleriyle (HMM) arar. Hoca HMM'yi yakında anlatacağı başka bir istatistiksel yaklaşım olarak andı.

MEME, tek bir DNA ya da protein dizisinde veya bir dizi kümesinde bir ya da daha fazla boşluksuz örüntü arar. Profil için en olası genişliği belirlemek amacıyla çeşitli motif genişlikleri denenir. Olasılık, EM algoritması bittikten sonra hesaplanan log-olabilirlik (log likelihood) skoruna dayanır.

Hoca motif tabanlı dizi analizi araçlarının blok diyagramını gösterdi; blokları tek tek anlatmadı, yalnızca bu algoritmaların nasıl kurulduğu hakkında fikir vermek istedi. MEME'nin modellerinden ZOOPS'un, bir öncekine (OOPS) ek olarak dizi başına 0 ya da 1 motif beklediğini, bunun OOPS'un bir tür genellemesi olduğunu söyledi. Diğeri TCM, iki bileşenli karışım (two-component mixture) modelidir. <!-- BELİRSİZ: Model adları altyazıda bozuk ("oops", "TCN2 component mixture"); ilgili slaytın karesi yok. -->

> **Ek bilgi (derste anlatılmadı):** MEME'de OOPS (One Occurrence Per Sequence) her dizide tam bir motif olduğunu varsayar. ZOOPS (Zero or One Occurrence Per Sequence) her dizide en fazla bir motif olabileceğini varsayar. TCM (Two-Component Mixture) ise bir dizide motifin herhangi bir sayıda geçebileceğine izin verir.

## 7. Gibbs Örneklemesi

Gibbs örneklemesi (Gibbs sampling) doğası gereği EM algoritmalarına benzer (ekrandan, 01:10:00):

- Çoklu dizilerin en iyi lokal hizalamasını belirlemek için EM ile benzetimli tavlama (simulated annealing) tekniklerini birleştirir.
- Amaç, model olasılığının arka plan olasılığına oranını en büyütmek için motif olasılıklarından örnekleme yaparak en olası örüntüyü bulmaktır.

Model olasılığının arka plan olasılığına oranı normalize edilir ve ağırlık olarak kullanılır. Motifin başlangıç konumu, bu ağırlıklarla yapılan rastgele örneklemeye göre seçilir. Hoca bu kısmın EM'den farklı olduğunu belirtti: EM'de en yüksek oranlı konum doğrudan seçilir, Gibbs'te ise konum ağırlıklı rastgele seçimle belirlenir.

Gibbs örneklemesinde de bir motif genişliği aralığı denenebilir. Yöntem aynı dizi kümesinde birden fazla motif aramaya ya da dizilerin yalnız bir kısmında bulunan bir örüntüyü bulmaya genişletilebilir. Ayrıca modele özgü bazı kısıtlar uygulanabilir; örneğin DNA dizileri için palindromik (ters tümleyen simetrili) motifler. <!-- BELİRSİZ: Altyazıda "anevan sequençüsü ... DNA sequençüsü" geçiyor; "palindromik" büyük olasılıkla doğru terimdir ama karede görülmedi. -->

## 8. Gizli Markov Modelleri ve Markov Zincirleri

### 8.1 Konuşma tanıma benzetmesi

Gizli Markov modelleri (Hidden Markov Models, HMM), sembol dizilerini incelemek için kullanılan olasılıksal modellerdir. Kökleri konuşma işlemedir; ilk olarak konuşma tanıma uygulamalarında yaygınlaşmışlardır. HMM'ler sembollerin eşleşmesini, uyuşmazlığını, eklenmesini ve silinmesini modelleyebilir.

Konuşma tanımada sorun, belirli bir zaman diliminde söylenen sözcüklerin fonemlerini belirlemektir. Zorluk şudur: tanıştığınız herkesin sesi farklıdır (ekrandan, 01:15:00). Konuşma tanımanın amacı, söylenen bir sözcüğü alıp olası sözcüklerin belirli bir modeline oturtmaktır. Hoca bunun beynin yaptığına çok yakın olduğunu söyledi.

Dizi analizindeki sorunlar da benzerdir. Örneğin bir amino asit dizisinin hangi protein ailesine ait olduğunu belirlemek isteyebiliriz. Amino asit dizisi konuşma sinyaline, amino asitler de fonemlere benzetilir.

### 8.2 Markov zinciri

Markov zinciri, bir sembolün olasılığının önceki sembole bağlı olduğu bir dizi üreten olasılıksal modeldir. Hoca trafik ışığını Markov zincirine örnek verdi. Rastgele bir DNA dizisi, dört durumlu bir Markov zinciriyle modellenebilir.

Ekrandaki diyagramda A, C, G, T durumları, bir başlangıç (start) ve bir bitiş (END) durumu ile durumlar arasındaki olası geçişler gösterilir (ekrandan, 01:20:00). Hoca bunun ardışıl sayısal devre tasarımındaki durum diyagramına benzediğini söyledi. Örneğin başlangıçtan sonra A'dan A'ya, C'ye, G'ye ya da T'ye geçilebilir.

Markov zincirinin temel özelliği şudur: $p$ konumundaki $S$ sembolünün olasılığı $p(S_p)$ yalnızca bir önceki konumdaki $S_{p-1}$ sembolüne bağlıdır, önceki dizinin tamamına bağlı değildir (ekrandan, 01:20:00). Sembolün olasılığı önceki sembole bağlı olduğu için Markov zincirlerinin başlıca kullanım örneklerinden biri, CG dinükleotidince zengin **CpG adalarının** tespitidir.

## 9. CpG Adaları ve Markov Modelleriyle Ayırt Etme

### 9.1 CpG ve metilasyon

CpG'deki "p", C ile G'nin bir fosfodiester bağıyla bağlı olduğunu gösterir; yani CpG aslında aynı iplikte art arda gelen C ve G'dir. Genomda bu dinükleotit metilasyon nedeniyle azdır. Sonuç olarak TG dinükleotidi fazla, CG dinükleotidi az bulunur. <!-- BELİRSİZ: Metilasyon mekanizmasını anlatan kısım altyazıda büyük ölçüde bozuk. -->

> **Ek bilgi (derste anlatılmadı):** CpG'deki C sık sık metillenir ve metil-C zamanla mutasyonla T'ye dönüşme eğilimindedir. Bu yüzden genom genelinde CG azalır, TG (ve tümleyen iplikte CA) artar.

### 9.2 Geçiş tabloları

Başlangıç ve bitiş durumları şimdilik yok sayılırsa 16 farklı geçiş vardır (A→A, A→C, A→G, A→T, C→A, ...). Hoca diyagramdaki okları sayarak 16'yı doğruladı. Genomik DNA bölgelerinin incelenmesiyle normal genomik geçiş olasılıkları belirlenmiştir. Tabloda "nereden" (from) durumu satırlarda, "nereye" (to) durumu sütunlardadır; bu bir Markov durum tablosudur. Bu olasılıklar grafın kenarlarına ağırlık olarak atanır; örneğin hocanın söylediğine göre A'dan A'ya geçiş 0.3'tür. <!-- BELİRSİZ: CpG olmayan (normal genomik) geçiş tablosunun karesi yok; yalnız A→A ≈ 0.3 altyazıdan alındı. -->

Genomun bazı bölgelerinde, örneğin genlerin başlangıç (promotör) bölgelerinde, metilasyon bastırılır ve CG dinükleotidi daha fazla bulunur. CpG adası bölgelerinin incelenmesiyle şu geçiş olasılıkları belirlenmiştir (ekrandan, 01:25:00):

| Nereden \ Nereye | A | C | G | T |
|---|---|---|---|---|
| A | 0.180 | 0.274 | 0.426 | 0.120 |
| C | 0.171 | 0.368 | 0.274 | 0.188 |
| G | 0.161 | 0.339 | 0.375 | 0.125 |
| T | 0.079 | 0.355 | 0.384 | 0.182 |

Yukarıdakiyle aynı yapıda yeni bir model, geçiş olasılıkları bu yeni tabloya göre atanarak kurulabilir. Hoca değerlerin öbür tablodan farklı olduğuna dikkat çekti. Her satırın toplamı 1'dir (python ile kontrol edildi; C satırı yuvarlamadan dolayı 1.001).

### 9.3 Dizi olasılığı ve ayırt etme

Böylece iki model elde edilir: CpG adası olmayan model (non-CpG) ve CpG modeli. Bir dizinin olasılığı, her sembolün yalnızca bir önceki sembole bağlı olduğu varsayımıyla ardışık çarpım olarak yazılır:

$$P(x) = P(x_1) \prod_{i=2}^{L} a_{x_{i-1} x_i}$$

Burada $a_{x_{i-1} x_i}$, $i-1$ konumundaki kalıntıdan $i$ konumundaki kalıntıya geçiş olasılığıdır. Hoca $\Pi$'nin ardışık çarpımı, $\Sigma$'nın toplamı gösterdiğini hatırlattı.

Hoca bir örnekte CpG olmayan model için A ve T'nin olasılığını 0.3, C ve G'nin olasılığını 0.2 olarak aldı; buna göre A ve T daha olasıdır. Eşit olasılık durumunda ise her birinin olasılığı 0.25 olur. Bir dizinin olasılığı bütün olasılıkların çarpımıdır. Aynı dizi iki modelde hesaplandı ve olasılığın hangi modelde daha büyük çıktığına bakıldı. <!-- BELİRSİZ: Örnek dizi, iki modelde çıkan değerler ve hangi modelin daha olası bulunduğu altyazıdan net çıkmıyor; ilgili kare yok. -->

> **Hocanın vurgusu:** 1'den küçük kesirli sayılar çarpıldığı için dizi uzadıkça olasılık çok çok küçülür ve kolayca sıfıra yaklaşır.

> **Ek bilgi (derste anlatılmadı):** Bu yüzden pratikte olasılıklar yerine logaritmaları toplanır. İki modeli karşılaştırmak için de log-olabilirlik oranı $\log \frac{P(x \mid \text{CpG})}{P(x \mid \text{non-CpG})}$ kullanılır; pozitif değer dizinin CpG adasından gelme olasılığının daha yüksek olduğunu gösterir.

Son olarak şu soru soruldu: CpG olmayan model ile CpG modeli birbirinden ne kadar farklıdır? Yeterince farklı değillerse, belirli bir dizinin hangi modelden türetildiğini belirlemek için yeterli bilgi yoktur (ekrandan, 01:30:00).

## 10. PSSM, Entropi ve Dizi Logoları

### 10.1 Konuma özgü skorlama matrisi

Kullanılan bir diğer önemli matris konuma özgü skorlama matrisidir (position-specific scoring matrix, PSSM). Bir hizalamanın her sütununda ne kadar bilgi bulunduğunu ölçmek için bilgi kuramından yararlanılır. Bilgi kuramı, her dizide bulunan bilgi miktarı hakkında fikir verebilir (ekrandan, 01:35:00). PSSM'deki bilgi, motifin her kalıntısının frekansının logaritmik dönüşümüdür.

Bir dizi hizalamasından model kurup bu modelle veri tabanlarında arama yapmanın bir sorunu, eğitim verisine doğru yanlılıktır (bias). Bazı kalıntılar az temsil edilmiş olabilir, bazı sütunlar ise fazla korunmuş görünebilir. <!-- BELİRSİZ: Bu sorunun çözümü için anlatılan tahmin edici (altyazıda "PECA, FCA") ve ilgili formüller okunamadı. -->

### 10.2 Entropi

Tanımlardan tahmin edilebileceği gibi belirsizliğin ölçüsü entropidir. <!-- BELİRSİZ: Entropi formülü ve örneği anlatılan kısım (yaklaşık 01:36-01:38) altyazıda bozuk; kare yok. -->

### 10.3 Dizi logoları

Dizi logoları, bir motifin her sütunundaki bilgiyi göstererek bu bilginin görselleştirilmesini sağlayan bir yoldur. Grafikte her sütundaki kalıntılar ve en önemli olanlar görülür. Harflerin yüksekliği, belirsizliğin ne kadar azaldığını, yani bilgi miktarını gösterir. Bir sütundaki frekans arka plan frekansından küçükse negatif bir göreli entropi hesaplanabilir; bu, logoda ters çevrilmiş bir karakterle gösterilir.

Ekrandaki örnek, Gibbs Block D (Tc1) için 9 dizinin logosudur; dikey eksen bit cinsinden bilgidir (0-4 bit), yatay eksende 17 konum vardır (ekrandan, 01:40:00). Hoca bazı konumların az, bazılarının (örneğin W, E harflerinin olduğu sütunlar) çok bilgi taşıdığını gösterdi.

Hoca ayrıca dizi editörleri ve ilgili kaynakların bağlantılarını listeledi; bazılarının artık çalışmayabileceğini, çoğunun ise erişilebilir olduğunu söyledi. Hoca bu noktada lokal çoklu dizi hizalama konusunu bitirdiğini belirtti.

## 11. Dizi Dosya Biçimleri (Hatırlatma)

Hoca daha önce anlatılan dizi dosya biçimlerini kısaca hatırlattı. Dizi dosyalarında yalnızca standart nükleotit (ya da amino asit) harfleri kullanılır; başka bir karakter, dizi analiz programlarının neredeyse hepsinin kabul etmeyeceği bir hata sayılır.

**FASTA biçimi:** Bir FASTA dizisinin ilk satırı büyüktür (`>`) karakteriyle başlayan açıklama satırıdır. Sonraki satırlar standart tek harfli simgelerle diziyi içerir. Ekrandaki örnekte mavi kısım dizi hakkında üst veri (metadata), yeşil kısım asıl dizidir (ekrandan, 01:45:00):

```text
>gi|27819608|ref|NP_776342.1| hemoglobin, beta [beta globin] [Bos taurus]
MLTAEEKAAVTAFWGKVKVDEVGGEALGRLLVVYPWTQRFFESFGDLSTADAVMNNPKVKAHGKKVLDSF
SNGMKHLDDLKGTFAALSELHCDKLHVDPENFKLLGNVLVVVLARNFGKEFTPVLQADFQKVVAGVANAL
AHRYH
```

**GenBank biçimi:** Veri tabanındaki bilgiler alanlara ayrılmıştır; her alanın tanımlayıcısı en soldaki sütuna yaslanır. Bazı tanımlayıcıların ek alt alanları vardır. Dizi verisi `ORIGIN` tanımlayıcısı ile kaydın sonunu gösteren `//` işareti arasında yer alır.

**ASN.1 (Abstract Syntax Notation One):** Bir veri tanımlama dilidir. Bu biçim, diğer biçimlerdeki bilgilerin hepsini içerir.

## 12. Filogenetiğe Giriş

### 12.1 Tanımlar

Hoca önceki derslerde filogenetiğe sık sık değindiğini ve birçok tekniğin onu kullandığını söyleyip bu konuya geçti.

**Filogenetik**, organizmalar arasındaki evrimsel ilişkilerin incelenmesidir. Taksonomiyi de içeren daha geniş **sistematik** alanının bir parçasıdır.

- **Taksonomi:** Organizmaların adlandırılması ve sınıflandırılması için süreç ve yöntemler. Bu bağlamda takson (çoğulu taksa) sözcüğü kullanılır.
- **Sistematik:** Biyolojinin sınıflandırma ve adlandırma (nomenklatür) ile ilgilenen dalı.

Biyolojide evrim bağlamında filogeni, bütün organizma grupları arasındaki, ata-torun ilişkileriyle anlaşılan bağlantılardır. İncelenen organizmalar, yeryüzündeki bütün organizmaların ortak bir atası olduğunu güçlü biçimde düşündürür. Türler, aynı ortak atadan evrimleştikleri için birbirleriyle ilişkilidir. Türlerin bu ilişkisine filogeni, grafik gösterimine filogenetik ağaç denir.

### 12.2 Etimoloji

Hoca modern bilimde neredeyse bütün bilimsel adların Latince ya da Yunancadan türetildiğini hatırlattı. "Phylo" Yunanca kökenlidir ve kabile, ırk, soy anlamına gelir; burada bir tür grubunu ifade eder. "Genetik" sözcüğü Yunanca *genetikos* sözcüğünden, o da köken anlamındaki *genesis*'ten gelir. Sözcük önce "köken yasaları" (laws of origination), sonra "kalıtım bilimi" (study of heredity) anlamında kullanılmıştır. <!-- BELİRSİZ: Etimoloji slaytı karede boş; altyazıda bu iki anlam için 1972 ve 1891 yılları geçiyor, ilki büyük olasılıkla 1872'dir. --> Filogenetik ise filogeniyle uğraşan bilim dalıdır.

### 12.3 Moleküler filogenetiğin kısa tarihi

Ekrandaki zaman çizelgesi (ekrandan, 02:00:00):

- **1900'ler:** İmmünokimyasal çalışmalar. Çapraz reaksiyonlar yakın akraba organizmalarda daha güçlüdür. Nuttall (1902): insanın en yakın akrabaları büyük maymunlardır.
- **1960'lar-1970'ler:** Protein dizileme yöntemleri, elektroforez, DNA hibridizasyonu ve polimeraz zincir tepkimesi (PCR) moleküler filogenide bir patlamaya yol açtı.
- **1970'lerin sonundan günümüze:** Moleküler filogeni ile yapılan keşifler; örneğin endosimbiyoz (Margulis, 1978).

Hoca ayrıca birçok "yaşam ağacı" (tree of life) projesinin tamamlandığını ya da sürdüğünü söyledi.

> **Ders sonrası not:** Altyazıda hocanın "early 90s" ve endosimbiyoz için "1907" dediği geçiyor; slayta göre doğrusu 1900'ler ve 1978'dir. Bunlar büyük olasılıkla Whisper hatası ya da dil sürçmesidir.

### 12.4 Moleküler veri ile morfoloji ve fizyolojinin karşılaştırılması

Moleküler veri kesin olarak kalıtsaldır; morfoloji ve fizyoloji ise çevresel etkenlerden etkilenebilir. Morfoloji ve fizyolojide homolojiyi değerlendirmek zordur. Uzak akraba organizmaların ilişkileri moleküler veriden çıkarılabilir; fizyolojik ya da morfolojik veriden ise yalnızca yakın ilişkiler güvenle çıkarılabilir. Hoca PCR ve dizileme sayesinde moleküler verinin kolay elde edildiğini de andı. <!-- BELİRSİZ: Karşılaştırma tablosunun bazı satırları altyazıda bozuk; kare yok. -->

## 13. Ağaç Terimleri ve Ağaç Sayısı

### 13.1 Bir filogeniyi yorumlamak

Ekrandaki tipik ağaçta beş yaprak vardır: Sequence A, B, C, D, E (ekrandan, 02:05:00). Ağacın topolojisi şöyledir: A ile B bir dalda birleşir; D ile E birleşir, onlara C katılır; en sonda iki grup kökte birleşir.

```text
((A, B), (C, (D, E)))
```

Ağaçtaki bilgi zamanla ilişkilidir. Ağacın nasıl çizildiğine bağlı olmakla birlikte bu örnekte sol taraf geçmişi gösterir. Yaprakların fiziksel yerleşimi genellikle anlamlı değildir. Dallar yalnızca düğümlerde döndürülebilir (swivel). Döndürmeden sonra ağaç farklı görünür ama aynı bilgiyi verir; yani yalnızca ağaç yapısı (topoloji) önemlidir.

### 13.2 Terimler

- **Dendrogram:** Hiyerarşik kümelemeyle üretilen kümelerin düzenini göstermek için sık kullanılan ağaç diyagramı. Hoca bu tekniği daha sonra anlatacağını, veri madenciliği ya da makine öğrenmesi gibi derslerde zaten görülmüş olabileceğini söyledi. Hesaplamalı biyolojide genlerin ya da örneklerin kümelenmesini göstermek için, bazen ısı haritalarının üzerinde kullanılır.
- **Kladogram:** Yalnızca ağaç topolojisini gösteren bir filogenetik ağaç türüdür (ekrandan, 02:10:00). Akrabalığı gösterir (ör. insanın şempanzeyle gorilden daha yakın akraba olduğu gibi), ama türler arasındaki zamanı ya da genetik uzaklığı göstermez. Sözcük Yunanca *klados* (dal) ve *gramma* sözcüklerinden gelir.
- **Topoloji:** Ağacın dallanma örüntüsüdür.
- **Gösterim biçimleri:** Ağaçlar dikdörtgen, eğik (slanted), dairesel, radyal ya da köksüz (unrooted) kladogram/filogram olarak çizilebilir. Bunlar yalnızca görselleştirme farkıdır.
- **Operasyonel taksonomik birimler (OTU) / taksa:** Ağacın uçlarındaki A, B, C, D, E, F gibi birimler; veri madenciliği terimleriyle uç düğümler ya da yapraklar.
- **İç düğümler:** Yapraklar dışındaki dallanma noktaları.

Kladogramlar genelde yalnızca evrimsel ilişkileri göstermek için kullanılır. Bütün uç düğümleri aynı hizaya dizer ve onları ayıran değişim adımlarının sayısı hakkında bir şey söylemeden yalnızca göreli akrabalığı aktarır.

- **Monofiletik grup:** Bir ata ve onun bütün torunlarından oluşan grup.
- **Parafiletik grup:** En yakın ortak ataları grubun üyeleriyle paylaşılan, ama o atanın bütün torunlarını içermeyen grup. <!-- BELİRSİZ: Parafiletik tanımı ve monofiletik örnek altyazıda bozuk; kare yok. -->
- **Gen ağacı ve tür ağacı:** Gen ağacı, tek bir homolog gende gözlenen ayrışmaya dayanan filogenetik ağaçtır. Böyle bir ağaç genin evrim tarihini gösterebilir, ama genin bulunduğu türün evrim tarihini göstermeyebilir.

DNA ve protein dizileri, ayrık karakter durumlarını betimleyen verilere örnektir.

### 13.3 Olası ağaç sayısı

$n$ tür için olası köklü ve köksüz ağaç sayıları (ekrandan, 02:15:00):

$$N_{\text{köklü}}(n) = \frac{(2n-3)!}{2^{n-2}\,(n-2)!} \qquad N_{\text{köksüz}}(n) = \frac{(2n-5)!}{2^{n-3}\,(n-3)!}$$

Küçük veri kümeleri için sayılar (ekrandan, 02:15:00):

| Veri kümesi sayısı | Köklü ağaç sayısı | Köksüz ağaç sayısı |
|---|---|---|
| 2 | 1 | 1 |
| 3 | 3 | 1 |
| 4 | 15 | 3 |
| 5 | 105 | 15 |
| 10 | 34,459,425 | 2,027,025 |
| 15 | 213,458,046,676,875 | 7,905,853,580,625 |
| 20 | 8,200,794,532,637,891,559,375 | 221,643,095,476,699,771,875 |

> **Ders sonrası not:** Tablo python ile formüllerden yeniden hesaplandı. Slaytta 15 tür için köklü ağaç sayısı `213,458,046,767,875` yazıyor; formülden çıkan doğru değer `213,458,046,676,875`'tir (yukarıdaki tabloda düzeltildi). Diğer değerler formülle uyumludur.

Hoca, kısa terim girişinden sonra filogenetik ağaç kurma yöntemlerine (Methods in Phylogenetic Reconstruction) başlayacağını söyleyip dersi burada bitirdi (ekrandan, 02:20:00).

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00): Birinci dizi `TCAGAACCAGTTATAAATTTATCATTTCCTTCTCCACTCCT` için 6 baz genişliğinde motif aranıyor. Maksimizasyon adımında kaç aday konum değerlendirilir?

> **Çözüm (derste verildi):** Dizide 41 kalıntı vardır. Aday konum sayısı $L - w + 1 = 41 - 6 + 1 = 36$'dır.

**Soru 2** (derste sözlü, 00:36:43): Blok dışında toplam 1046 kalıntı varsa ve bunların 279'u A ise arka plandaki A frekansı nedir?

> **Çözüm (derste verildi):** $279 / 1046 \approx 0.2667 \approx 0.267$.

**Soru 3** (ekrandan, 00:50:00): `CAGTTA` adayının konum olasılıkları $0.263, 0.296, 0.246, 0.261, 0.241, 0.263$, arka plan frekansları A: 0.267, C: 0.267, G: 0.216, T: 0.250'dir. Motif olasılığını, arka plan (RANDOM) olasılığını ve odds oranını bulun.

> **Çözüm (derste verildi; ara adımlar python ile doğrulandı):** Motif olasılığı $0.263 \cdot 0.296 \cdot 0.246 \cdot 0.261 \cdot 0.241 \cdot 0.263 \approx 0.000317$. Arka plan olasılığı $0.267 \cdot 0.267 \cdot 0.216 \cdot 0.250 \cdot 0.250 \cdot 0.267 \approx 0.000257$. Odds $= 0.000317 / 0.000257 \approx 1.23$. Bu, tablodaki en yüksek oran olarak seçilir.

**Soru 4** (ekrandan, 02:15:00): 5 tür için kaç köklü ve kaç köksüz ağaç vardır?

> **Çözüm (derste verilmedi):** Köklü: $\frac{(2 \cdot 5 - 3)!}{2^{3} \cdot 3!} = \frac{7!}{8 \cdot 6} = \frac{5040}{48} = 105$. Köksüz: $\frac{(2 \cdot 5 - 5)!}{2^{2} \cdot 2!} = \frac{5!}{4 \cdot 2} = \frac{120}{8} = 15$. Değerler slayttaki tabloyla aynıdır (python ile kontrol edildi).

## Dersin Toparlaması

Bu derste lokal çoklu dizi hizalamanın ikinci yöntemi olan blok analizi tamamlandı. Bloklar boşluksuz korunmuş bölgelerdir ve istatistiksel yöntemlerle bulunur. EM algoritması rastgele başlangıç bloklarından arka plan ve sütun frekanslarını hesaplar (sıfır sayımlara karşı yalancı sayım ekleyerek), sonra her dizide motif/arka plan olasılık oranını en büyüten konumu seçer ve bunu yakınsayana kadar tekrarlar. Gibbs örneklemesi aynı oranları ağırlık olarak kullanır, ama konumu ağırlıklı rastgele seçimle belirler. MEME ve türevleri bu yaklaşımları uygulayan programlardır. Ardından Markov zincirleri ve CpG adası örneğiyle iki olasılıksal modelin bir diziyi nasıl ayırt edebileceği gösterildi; PSSM, entropi ve dizi logolarıyla hizalamadaki bilginin ölçülmesi ve görselleştirilmesi anlatıldı.

Dersin son bölümünde filogenetiğe giriş yapıldı: tanımlar, etimoloji, moleküler filogenetiğin kısa tarihi, ağaçların yorumlanması, temel terimler ve olası ağaç sayısının tür sayısıyla çok hızlı büyümesi. Bir sonraki adım, filogenetik ağaç kurma yöntemleridir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
