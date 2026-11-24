# Ders 11 Genişletilmiş Notu: Birliktelik Kuralları, Market Sepeti Analizi ve Apriori Algoritması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- Hoca dersin ilk yarısını İngilizce, ikinci yarısını Türkçe anlatmıştır. Altyazıda uzun Whisper tekrar halüsinasyonları vardır; bunlar nota alınmamış, eksik kalan yerler ekran karelerinden kurulmuştur. -->

## İçindekiler

- 1. Dersin Yeri: Market Sepeti Analizi
- 2. Birliktelik Kuralları ve Veri Madenciliğindeki "Altın"
- 3. Temel Kavramlar: Ürün Kümesi, Destek ve Sık Örüntü
- 4. Birliktelik Kuralı, Destek ve Güven
- 5. İkili Gösterim ve Destek-Güven Örnekleri
- 6. Güçlü Kurallar ve Madenciliğin İki Fazı
- 7. Apriori Algoritması: Adım Adım Örnek
- 8. Budama ve Sayma Maliyeti
- 9. Sık Kümelerden Kural Üretme
- 10. Ürün Kümesi Kafesi: Apriori'nin Kazancı
- Örnek Sorular

## 1. Dersin Yeri: Market Sepeti Analizi

Dönemin başında bir "veri madenciliği stratejileri" şeması gösterilmişti. Bu şemada üç ana başlık vardı: denetimli öğrenme (supervised learning, sınıflama), denetimsiz kümeleme (unsupervised clustering) ve market sepeti analizi (market basket analysis). Sınıflama ve kümeleme konuları tamamlandığı için bu derste üçüncü başlığa, birliktelik kurallarına (association rules) geçildi.

Birliktelik kurallarında amaç, verideki en sık görülen yerel örüntüleri (the most common form of local patterns) bulmaktır. Konu denetimsiz öğrenme başlığı altında yer alır: verilerde bir sınıf etiketi yoktur, yalnızca birlikte görülen nesneler aranır.

E-ticarette ya da marketlerde her gün çok sayıda satın alma işlemi (transaction) gerçekleşir. Her işlemde bir müşterinin sepetinde neler olduğu kaydedilir. Hocanın örneğindeki bir sepette ekmek (bread), bebek bezi (diapers), bira (beer) ve yumurta (egg) gibi ürünler vardır; bu işlemler marketin kayıtlarında (log) tutulur. <!-- BELİRSİZ: bu sepet örneğinin anlatıldığı slayt karelerde yok ve altyazının bu kısmı halüsinasyonla bozuk; ürün adları altyazıdan alındı. -->

Yapı iki katmanlı düşünülebilir. Başta ham veri (raw data) vardır: müşteri kayıtları, işlemler. Bu veriye veri madenciliği yöntemleri uygulanınca bilgi (knowledge) elde edilir. Bu bilgi şirketler için satışları artırmakta kullanılabilecek yararlı bir bilgidir.

## 2. Birliktelik Kuralları ve Veri Madenciliğindeki "Altın"

Slaytta konu şöyle tanımlanır (ekrandan, 00:25:00): Birliktelik kuralı madenciliği, insanların veri madenciliği sürecini anlamaya çalışırken aklına gelen sürece en çok benzeyen biçimdir; yani büyük bir veritabanında altın aramak ("mining" for gold through a vast database). Buradaki altın, ilginç bir kuraldır: veritabanınız hakkında önceden bilmediğiniz ve büyük olasılıkla açıkça ifade edilmemiş bir şey söyleyen kural.

Hoca bunu şöyle açıkladı: Bir veri kümesine bakarak ya da şirketteki bir uzmanın deneyimiyle bazı bilgiler çıkarılabilir. Veri madenciliğinde ise bu kadar açık olmayan, gözle hemen görülemeyen bilgi çıkarılmaya çalışılır.

### 2.1 Market sepeti

Market sepeti, bir müşterinin tek bir işlemde satın aldığı ürünlerin topluluğudur. Sepetlerin ayrıntısı bilinirse analiz edilip birliktelik kuralları gibi yararlı bilgiler bulunabilir. Bu, iyi tanımlanmış bir iş etkinliğidir; şirketler bu bilgiyi satışlarını artırmak için kullanır.

İşlem veritabanı üzerinde yapılan yaygın analiz, birçok işlemde birlikte görülen ürün kümelerini (item set) bulmaktır. Uygulamalarda amaç bir grup ürünün en sık görülen biçimini çıkarmaktır: bazen işlemlerde sık birlikte görülen iki ürün, bazen üç ürün bulunur.

Bu bilgi nasıl kullanılır? Slayttaki ifadeye göre işletme bu örüntü bilgisini ürünlerin mağazadaki yerleşimini (placement) iyileştirmek için kullanabilir.

## 3. Temel Kavramlar: Ürün Kümesi, Destek ve Sık Örüntü

Slayttaki tanımlar (ekrandan, 00:30:00):

- $i$ tane ürün (item) içeren bir ürün kümesine $i$-ürün kümesi ($i$-itemset) denir. Örneğin $i=2$ için ikili ürün kümeleri, $i=3$ için üçlü ürün kümeleri bulunur. $i$, gruptaki ürün sayısını gösterir.
- Bir ürün kümesini içeren işlemlerin yüzdesine o ürün kümesinin desteği (itemset's support) denir.
- Bir ürün kümesinin ilginç (interesting) sayılması için desteğinin kullanıcının belirlediği bir minimumdan yüksek olması gerekir. Böyle ürün kümelerine sık (frequent) denir.

Hoca destek parametresini şu sözlü örnekle açıkladı: Kayıtta 100 işlem olsun ve bunların 40'ında yumurta ve süt (eggs and milk) birlikte bulunsun. O zaman {yumurta, süt} kümesinin desteği %40 olur. <!-- BELİRSİZ: örneğin devamı ve "bu küme ilginç midir" sorusunun cevabı altyazıda halüsinasyonla kayıp. -->

### 3.1 Biçimsel gösterim

Mağazadaki farklı ürünler bir $I$ kümesi oluşturur; bunlar mağazanın "harfleri" (literals) gibidir. Veritabanında ($D$) bir işlemler kümesi vardır ve her işlem $T$, mağazadaki ürünlerden bazılarını içeren bir ürün kümesidir.

Algoritmaları gösterirken ürün adlarını (bread, milk, eggs) yazmak yerine kısaca A, B, C, ... harfleri kullanılır. Slayttaki örnek işlem veritabanı (ekrandan, 00:35:00):

| İşlem no | Alınan ürünler |
|---|---|
| 10 | A, C, D |
| 20 | B, C, E |
| 30 | A, B, C, E |
| 40 | B, E |

$X$ ve $Y$ birer ürün kümesi olsun. $X \subseteq T$ ise $T$ işlemi $X$ ürün kümesini içerir.

## 4. Birliktelik Kuralı, Destek ve Güven

Birliktelik kuralı $X \Rightarrow Y$ biçiminde yazılır ve "$X$ ürün kümesini alan müşteriler $Y$ ürün kümesini de almıştır" anlamına gelir. Burada $X \subset I$, $Y \subset I$ ve $X \cap Y = \emptyset$'dir; yani kuralın iki tarafı ortak ürün içermez.

Destekten sonra ikinci önemli parametre güvendir (confidence). Slayttaki tanımlar (ekrandan, 00:40:00):

- $X \Rightarrow Y$ kuralı $D$ işlem kümesinde $c$ güveniyle geçerlidir, eğer $X$'i içeren işlemlerin $c$%'si $Y$'yi de içeriyorsa.
- $X \Rightarrow Y$ kuralının $D$'deki desteği $s$'dir, eğer işlemlerin $s$%'si $X \cup Y$'yi içeriyorsa.

$$\text{Support}(X \Rightarrow Y) = P(X \cup Y)$$

$$\text{Confidence}(X \Rightarrow Y) = P(Y \mid X)$$

Desteği bulmak için tüm işlemler içinde $X \cup Y$'yi (iki kümenin bütün ürünlerini birlikte) içeren işlemler sayılır ve toplam işlem sayısına bölünür. Güven ise $X$ verildiğinde $Y$'nin koşullu olasılığıdır: $X$'i içeren işlemlerin kaçta kaçında $Y$'nin de bulunduğu.

> **Hocanın vurgusu:** "Lütfen yazın. Destek ve güvenin en açık hali budur": destek $X \cup Y$'nin olasılığıdır, güven $X$ verildiğinde $Y$'nin koşullu olasılığıdır.

> **Ek bilgi (derste anlatılmadı):** Sayılarla yazıldığında $\text{Support}(X \Rightarrow Y) = \dfrac{\text{count}(X \cup Y)}{|D|}$ ve $\text{Confidence}(X \Rightarrow Y) = \dfrac{\text{count}(X \cup Y)}{\text{count}(X)}$ olur. Buradaki $X \cup Y$ "X veya Y" değil, "X'in ve Y'nin bütün ürünleri birlikte" anlamındadır. Derste yapılan bütün hesaplar bu iki oranla yapılmıştır.

## 5. İkili Gösterim ve Destek-Güven Örnekleri

### 5.1 İkili (binary) tablo

Market sepeti analizinde işlemler, sütunlarında ürün adlarının bulunduğu bir tabloyla gösterilebilir. Mağazadaki bütün ürünlerin sütun olarak yazılması gerektiği için bu çok büyük bir matristir. Slayttaki örnek (ekrandan, 00:45:00):

| İşlem | Alınan ürünler |
|---|---|
| 1 | {Shoes, Trousers, Shirt, Belt} |
| 2 | {Shoes, Trousers, Shirt, Hat, Belt, Scarf} |
| 3 | {Shoes, Shirt} |
| 4 | {Shoes, Trousers, Belt} |

| İşlem | Shoes | Trousers | Shirt | Belt | Hat | Scarf |
|---|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 1 | 0 | 0 |
| 2 | 1 | 1 | 1 | 1 | 1 | 1 |
| 3 | 1 | 0 | 1 | 0 | 0 | 0 |
| 4 | 1 | 1 | 0 | 1 | 0 | 0 |

İkinci işlemde bütün ürünler alındığı için o satır tamamen 1'dir. Üçüncü işlemde yalnız ayakkabı ve gömlek alınmıştır. Sepette iki ayakkabı ya da iki gömlek olması önemli değildir; yalnızca o üründen alınıp alınmadığına bakılır. Alınan ürün 1, alınmayan 0 ile gösterilir. Bu yüzden tablo ikili (binary) bir tablodur.

### 5.2 Örnek: Trousers ⇒ Shirt

Hoca tabloya "Trousers → Shirt, Support =" yazdı (ekrandan, 00:45:00): pantolon alan müşteriler gömlek de almış mı?

- Destek: Trousers ve Shirt birlikte 1. ve 2. işlemde vardır. $\text{Support} = 2/4 = \%50$ (ara adım eklendi). <!-- BELİRSİZ: hocanın destek değerini söylediği kısım altyazıda halüsinasyonla kayıp; değer tablodan hesaplandı. -->
- Güven: Trousers içeren işlemler 1, 2 ve 4'tür (3 işlem). Bunların 2'sinde (1 ve 2) Shirt de vardır. $\text{Confidence} = 2/3$.

### 5.3 Örnek: {Trousers, Shoes} ⇒ Belt

Hocanın ikinci sorusu: "Pantolon ve ayakkabı alan müşteriler kemer de almış mı?" Hoca önce "shirt" dedi, sonra "belt" diye düzeltti.

- Destek: Trousers, Shoes ve Belt birlikte 1, 2 ve 4. işlemlerde vardır. $\text{Support} = 3/4 = \%75$. Bu cevap bir öğrenciden geldi.
- Güven: Trousers ve Shoes birlikte 3 işlemde (1, 2, 4) vardır, üçünde de Belt bulunur. $\text{Confidence} = 3/3 = 1 = \%100$.

<!-- BELİRSİZ: kuralın sağ tarafı altyazıda "shirt ... or belt" diye geçiyor; söylenen 3/4 ve 3/3 değerleri yalnız Belt ile tutuyor (Shirt için destek 2/4, güven 2/3 olurdu). -->

## 6. Güçlü Kurallar ve Madenciliğin İki Fazı

### 6.1 Güçlü kurallar

Slayttaki ifadeler (ekrandan, 01:05:00):

- Güven, çıkarımın gücünü (strength of implication) gösterir; destek, kuraldaki örüntülerin sıklığını (frequency of the patterns) gösterir.
- Genellikle yalnızca makul ölçüde büyük desteği olan kurallarla ilgilenmek istenir.
- Güveni yüksek ve desteği güçlü kurallara güçlü kural (strong rule) denir.
- Birliktelik kuralı madenciliğinin görevi, büyük veritabanlarında güçlü birliktelik kurallarını bulmaktır.

Üretilen kuralların güven değeri hesaplanır ve bir minimum güven değeri tanımlanır. Güven değeri bu eşiğin üstünde olan kurallar güçlü kural olarak kabul edilir; diğerleri zayıf kuraldır. Bir öğrencinin "güçlü kuralı tekrar anlatır mısınız" sorusu üzerine hoca örnek verdi: minimum güven %80 seçilirse güveni %80'in üstünde olan kurallar güçlü kural sayılır.

### 6.2 İki faz

Birliktelik kuralı madenciliği problemi iki faza ayrılır (ekrandan, 01:10:00):

1. Büyük ürün kümelerini bulmak (discover the large itemsets): işlem desteği önceden belirlenen minimum eşiğin üstünde olan ürün kümeleri. "Büyük" (large) burada "sık" (frequent) anlamındadır. Hoca slayta "Apriori Algorithm: to discover the large itemsets!" notunu ekledi.
2. Büyük ürün kümelerini kullanarak, güveni önceden belirlenen eşiğin üstünde olan birliktelik kurallarını üretmek. Hocanın slayta eklediği notlar: büyük ürün kümelerinden birliktelik kuralları üret, bu kuralların güven değerlerini hesapla, güçlü kuralları bul.

## 7. Apriori Algoritması: Adım Adım Örnek

Apriori yinelemeli (iterative) bir algoritmadır ve birkaç yineleme (iteration) yapar. Yineleme numarası bulunan kümelerin boyuyla ilişkilidir: ikinci yinelemenin sonunda büyük 2-ürün kümeleri bulunur. Her yinelemede iki adım vardır:

1. Aday üretme (candidate generation): adaylar $C_k$ ile gösterilir.
2. Adayları sayma ve sık olanları seçme (selection): seçilenler $L_k$ ile gösterilir.

Örnekte Bölüm 3.1'deki dört işlemli veritabanı kullanıldı. Hoca soruyu tahtaya "a) Apply Apriori Algorithm to discover large itemsets, min. support = 50%" diye yazdı (ekrandan, 01:20:00). Adaylar alfabetik sırayla yazılır.

### 7.1 Birinci yineleme

$C_1$ tek ürünlü adaylardır. Her ürünün kaç işlemde geçtiği sayılır ve destek yüzdesi yazılır (4 işlem olduğu için 2 işlem %50'dir):

| $C_1$ | Sayım | Destek (%) |
|---|---|---|
| A | 2 | 50 |
| B | 3 | 75 |
| C | 3 | 75 |
| D | 1 | 25 |
| E | 3 | 75 |

(ekrandan, 01:20:00; destek sütunu altyazıdan.) Minimum destek %50 olduğu için desteği %50 ya da daha yüksek olanlar seçilir; D elenir:

$L_1 = \{A\ (50),\ B\ (75),\ C\ (75),\ E\ (75)\}$. Bu, birinci yinelemenin sonudur.

### 7.2 İkinci yineleme

İkinci yinelemenin adayları $L_1$'in ikili kombinasyonlarıyla üretilir: AB, AC, AE, BC, BE, CE. Sayım ve destekler (ekrandan, 01:30:00):

| $C_2$ | Sayım | Destek (%) |
|---|---|---|
| AB | 1 | 25 |
| AC | 2 | 50 |
| AE | 1 | 25 |
| BC | 2 | 50 |
| BE | 3 | 75 |
| CE | 2 | 50 |

Seçim (selection) adımında AB ve AE elenir. Büyük 2-ürün kümeleri:

| $L_2$ | Destek (%) |
|---|---|
| AC | 50 |
| BC | 50 |
| BE | 75 |
| CE | 50 |

### 7.3 Aday üretme kuralı: yıldız işlemi

Birinci yinelemeden ikinciye geçerken aday üretmek kolaydır: yalnız ikili kombinasyonlar yazılır. Sonraki yinelemeler için hoca tahtaya şu kuralı yazdı (ekrandan, 01:30:00):

$$L_k \ast L_k = \{\, X \cup Y \mid X, Y \in L_k,\ |X \cap Y| = k-1 \,\}$$

Yani $L_k$'daki iki kümenin kesişimindeki eleman sayısı $k-1$ ise bu iki küme birleştirilerek $(k+1)$ elemanlı bir aday elde edilir.

$k = 2$ için $L_2$'ye uygulanırsa:

- AC ve BC: bir ortak eleman (C) var, birleşim ABC bir adaydır.
- AC ve BE: kesişim boştur, aday üretilemez.
- AC ve CE: bir ortak eleman (C) var, birleşim ACE.
- BC ve BE: bir ortak eleman (B) var, birleşim BCE. BC ve CE'den de aynı BCE çıkar.

Böylece üçüncü yineleme için üç aday vardır: ABC, BCE, ACE.

**Soru:** ABE neden aday olarak yazılmıyor? **Cevap:** Birleşim işlemiyle ABE elde etmek mümkün değildir; $L_2$'de bu birleşimi verecek ve bir ortak elemanı olan iki küme yoktur.

### 7.4 Budama (pruning)

Üçüncü yinelemenin başında adaylar budama işlemiyle (pruning operation, budama işlemi) kontrol edilir. Her adayın iki elemanlı alt kümeleri yazılır ve bunların $L_2$ kümesinde olup olmadığına bakılır (ekrandan, 01:40:00 ve 02:05:00):

| Aday | 2'li alt kümeler | $L_2$'de var mı? | Sonuç |
|---|---|---|---|
| {A, B, C} | {A,B}, {A,C}, {B,C} | AB yok; AC, BC var | Elenir |
| {B, C, E} | {B,C}, {B,E}, {C,E} | Hepsi var | Aday kalır |
| {A, C, E} | {A,C}, {A,E}, {C,E} | AE yok; AC, CE var | Elenir |

ABC'nin elenme nedeni şudur: AB zaten $L_2$'de değildir, yani AB'nin desteği %50'nin altındadır. ABC'yi içeren her işlem AB'yi de içerdiğinden ABC'nin desteği de %50'nin altında kalacaktır. Bu yüzden ABC sayma işleminden önce elenir. Bir adayın seçilmesi için bütün iki elemanlı alt kümelerinin $L_2$'de olması gerekir.

Budamadan sonra $C_3$ listesinde başta üç aday varken yalnız BCE kalır.

### 7.5 Üçüncü yineleme

Tek aday BCE işlemlerde sayılır (ekrandan, 01:45:00). BCE 20 ve 30 numaralı işlemlerde vardır: sayım 2, destek %50. Minimum desteğe eşit olduğu için seçilir:

$L_3 = \{BCE\ (50)\}$.

Böylece ikili ve üçlü sık satılan ürün grupları bulunmuş olur. Üçüncü yinelemeden dördüncüye geçilemez, çünkü elde yalnız bir tane üçlü grup vardır; ondan yeni aday türetilemez. Algoritma burada sona erer.

### 7.6 Varsayımsal dördüncü yineleme

Hoca aradan önce şu soruyu sordu ve aradan sonra cevaplattı: Üç adayın üçü de (ABC, BCE, ACE) $L_3$'te kalsaydı, dördüncü yinelemenin $C_4$ adayları nasıl üretilirdi?

Bir öğrenci "kesişiminde üç ortak eleman olanlar" diye önerdi. Hoca düzeltti: $L_3 \ast L_3$ uygulanacağı için $k = 3$'tür ve ortak eleman sayısı $k-1 = 2$ olmalıdır. ABC ile BCE karşılaştırılınca iki ortak eleman (B, C) vardır; birleşim ABCE bir adaydır. ABC ile ACE'nin de iki ortak elemanı (A, C) vardır, ama bu da aynı adayı (ABCE) üretir. Sonuçta $C_4$ için tek aday ABCE olurdu.

Bu yalnız bir varsayım üzerine yapılan alıştırmaydı; gerçek örnekte ABC ve ACE $L_3$'te olmadığı için geçerli değildir.

### 7.7 Slayttaki özet

Aynı örnek slaytta tek şemada özetlenmiştir (ekrandan, 02:10:00). Slaytta minimum destek sayı olarak $\text{Sup}_{min} = 2$ (4 işlemde %50) yazılır:

```text
TDB --1. tarama--> C1: A:2, B:3, C:3, D:1, E:3
                   L1: A:2, B:3, C:3, E:3
L1'den aday      -> C2: AB, AC, AE, BC, BE, CE
     --2. tarama-> C2: AB:1, AC:2, AE:1, BC:2, BE:3, CE:2
                   L2: AC:2, BC:2, BE:3, CE:2
L2'den aday      -> C3: BCE
     --3. tarama-> L3: BCE:2
```

## 8. Budama ve Sayma Maliyeti

Hoca özet slaytını anlatırken sayma (tarama, scan) işleminin bu problemin en maliyetli, en çok zaman alan kısmı olduğunu vurguladı. Örneğin $C_2$'deki yalnız AB'yi saymak için bütün işlemler baştan sona taranır. Gerçek hayatta bir aylık ya da bir yıllık satışlar inceleniyorsa milyonlarca satır olabilir. Ayrıca markete gelen bir müşteri yalnız 2-3 ürün değil, belki 20-30 çeşit ürün alır; satırdaki ürün sayısı da çok artabilir. Her aday için ilk satırdan başlayıp bütün satırlar taranır, sonra sonraki aday için yeniden baştan başlanır.

> **Hocanın vurgusu:** Bu sayma işlemlerinin sayısı ne kadar azaltılabilirse çözüm o kadar kârlı ve optimize olur.

Örnekte ikinci aşamada altı aday sayıldı. Üçüncü yineleme için üretilen adaylar ise budamayla azaltıldı: üçlü adayların ikili alt kümeleri $L_2$'de yoksa "boş yere sayma, zaten desteği minimumun altında kalacak" diye elendi. Bu sayede iki aday için tüm işlemleri satır satır sayma maliyetinden kurtulundu. $C_3$'te yalnız bir ciddi aday kaldı ve üçüncü taramada yalnız o sayıldı.

## 9. Sık Kümelerden Kural Üretme

Birinci faz tamamlandıktan sonra ikinci faza, kural üretmeye geçilir: sık ürün gruplarından kurallar üretilir, güven değerleri hesaplanır ve belli bir eşiğin üstünde olanlar güçlü kural olarak kabul edilir.

Kural üretmek için $L_2$ ve $L_3$ kullanılır. $L_1$ işe yaramaz, çünkü tek ürünlü bir kümede kuralın öbür tarafına ikinci bir ürün koyma imkânı yoktur.

Güven hesaplanırken yeniden sayma yapılmaz; Apriori'nin ürettiği tablolardaki sayımlara bakılır.

### 9.1 $L_3$'ten kurallar

$L_3$'teki BCE kümesinden üretilen kurallar (ekrandan, 02:20:00):

- $B, C \Rightarrow E$: BC'yi alan kaç kişi var? $L_2$ tablosuna göre 2. Bu iki kişinin ikisi de E'yi almış (BCE sayımı 2). $\text{Confidence} = 2/2 = \%100$, güçlü kural.
- $C, E \Rightarrow B$: CE'yi alan 2 kişi var, ikisi de B'yi almış. $\text{Confidence} = 2/2 = \%100$, güçlü kural.
- $B \Rightarrow C, E$: Hoca bu kuralın güvenini öğrencilere sordu. B'yi alan kişi sayısı 3'tür ($L_1$), bunların 2'si CE'yi de almıştır. $\text{Confidence} = 2/3 \approx \%67$. Cevap bir öğrenciden geldi.

Minimum güven eşiği %80 gibi bir değer seçilmiş olsaydı, $B \Rightarrow C, E$ kuralı %67 güvenle zayıf kural olurdu. Böylece iki güçlü kural bulunmuş olur: $B, C \Rightarrow E$ ve $C, E \Rightarrow B$.

### 9.2 $L_2$'den kurallar ve simetri

$L_2$ kullanılarak da kural yazılabilir. $L_2$'deki AC için:

- $A \Rightarrow C$: Önce $L_1$'de A'yı alanlara bakılır: 2 kişi. Bunların AC'yi alanları 2'dir. $\text{Confidence} = 2/2 = \%100$.

Hoca "lütfen dikkat, bir soru geliyor" diyerek şunu sordu: Bu kuralın tersi $C \Rightarrow A$ için aynı güven geçerli midir, yani kurallarda simetri var mıdır?

**Cevap:** Kesinlikle yoktur. C'yi alanların sayısı 3, AC'yi alanların sayısı 2'dir; $\text{Confidence}(C \Rightarrow A) = 2/3 \approx \%67$.

> **Hocanın vurgusu:** Birliktelik kurallarında simetri söz konusu değildir; $X \Rightarrow Y$'nin güveni $Y \Rightarrow X$'e aktarılamaz.

> **Ek bilgi (derste anlatılmadı):** Destek ise simetriktir: $X \Rightarrow Y$ ve $Y \Rightarrow X$ kurallarının ikisinin de desteği $P(X \cup Y)$'dir. Güvenler yalnızca paydada farklılaşır: biri $\text{count}(X)$'e, öbürü $\text{count}(Y)$'ye bölünür.

## 10. Ürün Kümesi Kafesi: Apriori'nin Kazancı

Hoca bu bölümün çok üstünde durduğu önemli bir bölüm olduğunu söyledi. Slaytta bir ürün kümesi kafes diyagramı (itemset lattice diagram) vardır (ekrandan, 02:30:00 ve 02:35:00). Diyagramın en üstünde boş küme (null), altında a, b, c, d, e tek ürünleri, onun altında 10 ikili (ab, ac, ad, ae, bc, bd, be, cd, ce, de), sonra 10 üçlü (abc, abd, abe, acd, ace, ade, bcd, bce, bde, cde), sonra 5 dörtlü (abcd, abce, abde, acde, bcde) ve en altta abcde vardır. Her küme, bir eleman eksiği olan alt kümelerine çizgiyle bağlıdır.

Örnekte mağazada A, B, C, D, E olmak üzere beş farklı ürün vardı. Apriori gibi bir algoritma kullanılmasaydı, bu kafesteki bütün kombinasyonlar için tüm işlemler taranarak sayma yapılması gerekirdi.

### 10.1 Apriori olmadan

- Tek ürünler: 5 sayma.
- İkililer: $\binom{5}{2} = \dfrac{5!}{2!\,(5-2)!} = \dfrac{5 \cdot 4}{2} = 10$ sayma (hoca tahtada bu hesabı yaptı).
- Üçlüler: 10 sayma.
- Dörtlüler: 5 sayma.
- Beşinin bir arada olduğu durum: 1 sayma.

Toplam: $5 + 10 + 10 + 5 + 1 = 31$ sayma işlemi.

### 10.2 Apriori ile

- $C_1$'de bütün tek ürünler vardı: 5 sayma (iki tarafta aynı).
- D eşik değerinin altında kaldığı için listeden çıkarıldı; kalan 4 ürünün ikili kombinasyonu olan 6 aday sayıldı: 6 sayma.
- Üçlüler için Apriori olmadan 10 sayma gerekecekti; Apriori ile aday sayısı 3'e, budamadan sonra 1'e düştü: 1 sayma.
- Dörtlü düzeye geçilmedi.

Toplam: $5 + 6 + 1 = 12$ sayma işlemi. Apriori kullanılmasaydı 31 ürün kümesi için sayma yapılacakken bu sayı 12'ye düştü. Kazanç oranı 12/31 üzerinden yüzde olarak da ifade edilebilir. Hoca yine de Apriori'nin çok iyi bir algoritma olduğunun söylenemeyeceğini, sayma adedinin hâlâ oldukça yüksek olduğunu ekledi.

### 10.3 Budamanın payı

Hoca şu soruyu sordu: Budama (pruning) adımı olmasaydı toplam sayma adedi kaç olurdu? Bir öğrenci 14 diye cevap verdi. $C_3$'te 3 aday vardı ve budamayla 1'e indirilmişti; budama olmasaydı elenen 2 aday da sayılacaktı: $5 + 6 + 3 = 14$.

**Soru:** Üçten devam etseydik ne geleceğini bilemiyoruz, değil mi? **Cevap:** Budama yapılmadan devam edilseydi o adaylar sayılır, desteklerinin düşük kaldığı görülür ve yine elenirlerdi; ama saydıktan sonra elenmiş olurlardı. Budama bunu sayma yapmadan önceden görür: ikili alt kümeleri $L_2$'de olmayan bir adayın desteği zaten yüksek olamaz.

> **Hocanın vurgusu:** İki tarafta ne kadar sayma yapıldığını ve bu sayıların ne kadar azaltılabildiğini görmek açısından bu değerlendirme çok önemlidir.

## Örnek Sorular

### Soru 1: Trousers ⇒ Shirt kuralının desteği ve güveni

(ekrandan, 00:45:00) Bölüm 5.1'deki dört işlemli ikili tabloya göre Trousers ⇒ Shirt kuralının desteğini ve güvenini bulun.

> **Çözüm:** Trousers ve Shirt birlikte 1. ve 2. işlemlerde vardır: $\text{Support} = 2/4 = \%50$ (bu değerin derste söylendiği kısım altyazıda kayıp). Trousers 3 işlemde (1, 2, 4) vardır, bunların 2'sinde Shirt de vardır: $\text{Confidence} = 2/3$ (derste verildi).

### Soru 2: {Trousers, Shoes} ⇒ Belt

(derste sözlü, 00:46:51) Pantolon ve ayakkabı alan müşterilerin kemer de alması kuralının desteğini ve güvenini bulun.

> **Çözüm:** Üç ürün birlikte 1, 2 ve 4. işlemlerde vardır: $\text{Support} = 3/4 = \%75$. Trousers ve Shoes birlikte 3 işlemdedir ve üçünde de Belt vardır: $\text{Confidence} = 3/3 = \%100$.

<!-- BELİRSİZ: kuralın sağ tarafı altyazıda önce "shirt" sonra "belt" diye geçiyor; söylenen değerler Belt ile tutuyor. -->

### Soru 3: Apriori ile büyük ürün kümeleri

(ekrandan, 01:20:00) İşlemler 10 = {A, C, D}, 20 = {B, C, E}, 30 = {A, B, C, E}, 40 = {B, E}. Minimum destek %50 iken Apriori algoritmasını uygulayarak büyük ürün kümelerini bulun.

> **Çözüm:** $C_1$: A 2, B 3, C 3, D 1, E 3; D elenir, $L_1 = \{A, B, C, E\}$. $C_2$: AB 1, AC 2, AE 1, BC 2, BE 3, CE 2; $L_2 = \{AC, BC, BE, CE\}$. $L_2 \ast L_2$ adayları ABC, ACE, BCE; budamayla ABC (AB yok) ve ACE (AE yok) elenir. BCE sayımı 2 (%50), $L_3 = \{BCE\}$. Ayrıntı Bölüm 7'dedir.

### Soru 4: Varsayımsal $C_4$ adayları

(derste sözlü, 01:49:53 ve 02:04:49) Üçüncü yinelemenin sonunda ABC, BCE ve ACE'nin üçü de $L_3$'te olsaydı, dördüncü yinelemenin adayları ne olurdu?

> **Çözüm:** $L_3 \ast L_3$'te ortak eleman sayısı $k-1 = 2$ olmalıdır. ABC ile BCE (ortak B, C) ABCE'yi verir; ABC ile ACE (ortak A, C) ve BCE ile ACE (ortak C, E) de aynı ABCE'yi verir. $C_4 = \{ABCE\}$.

### Soru 5: $B \Rightarrow C, E$ kuralının güveni

(derste sözlü, 02:19:53; ekrandan, 02:20:00) $L_3 = \{BCE\}$'den üretilen $B \Rightarrow C, E$ kuralının güveni nedir?

> **Çözüm:** B'yi alan 3 kişi, BCE'yi alan 2 kişi vardır: $\text{Confidence} = 2/3 \approx \%67$. Minimum güven %80 olsaydı zayıf kural olurdu.

### Soru 6: Kurallarda simetri

(derste sözlü, 02:23:10) $A \Rightarrow C$ kuralı için bulunan güven değeri $C \Rightarrow A$ kuralı için de geçerli midir?

> **Çözüm:** Hayır. $\text{Confidence}(A \Rightarrow C) = 2/2 = \%100$, $\text{Confidence}(C \Rightarrow A) = 2/3 \approx \%67$. Birliktelik kurallarında simetri yoktur.

### Soru 7: Budama olmadan sayma adedi

(derste sözlü, 02:33:13; ekrandan, 02:35:00) Örnekte Apriori budamayla 12 sayma yaptı. Budama adımı uygulanmasaydı toplam kaç sayma yapılırdı?

> **Çözüm:** $C_3$'teki 3 adayın hepsi sayılırdı: $5 + 6 + 3 = 14$ sayma (derste bir öğrenci cevapladı, hoca onayladı).

## Dersin Toparlaması

Bu derste veri madenciliğinin üçüncü ana başlığı olan market sepeti analizine ve birliktelik kurallarına giriş yapıldı. Ürün kümesi, destek, güven ve güçlü kural kavramları tanımlandı: destek $P(X \cup Y)$, güven $P(Y \mid X)$'tir; güveni eşiğin üstünde olan ve desteği yeterli kurallar güçlü kuraldır. Birliktelik kuralı madenciliği iki faza ayrıldı: önce Apriori ile sık (büyük) ürün kümeleri bulunur, sonra bu kümelerden kurallar üretilip güven eşiğiyle süzülür.

Apriori algoritması dört işlemli bir örnek üzerinde adım adım uygulandı: aday üretme ($L_k \ast L_k$), sayma, seçim ve budama. Sayma işleminin algoritmanın en pahalı kısmı olduğu, budamanın ve Apriori'nin bu maliyeti nasıl azalttığı kafes diyagramı üzerinden gösterildi (31 yerine 12 sayma). Bulunan sık kümelerden kurallar üretildi ve kurallarda simetri olmadığı vurgulandı. Hoca sonraki derste öneri sistemleri (recommendation systems) konusunun anlatılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
