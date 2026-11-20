# Ders 10 Genişletilmiş Notu: Filogenetik Ağaç Kurma Yöntemleri ve İstatistiğe Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Filogenetik ağaç türleri (tekrar)
- 2. Filogenetik ağaç kurma yöntemleri ve karşılaştırmaları
- 3. Uzaklık tabanlı yöntemler ve UPGMA
- 4. Dal uzunluklarının kestirimi
- 5. Komşuluk ilişkisi yöntemi ve komşu birleştirme
- 6. Karakter tabanlı yöntemler: maksimum parsimoni
- 7. Maksimum olabilirlik
- 8. Ağaç güvenilirliği: bootstrap ve parametrik testler
- 9. Moleküler filogenetiğin uygulamaları ve hata kaynakları
- 10. İstatistik tekrarı: veri analizi
- 11. Örneklem, anakütle ve veri türleri
- Örnek Sorular

## 1. Filogenetik ağaç türleri (tekrar)

Ders, ara sınavdan önce başlanan filogenetik ağaç konusunun devamıdır. Hoca önce önceki derste görülen sınıflandırmayı hatırlattı.

Filogenetik ağaçlar, gen ya da tür açısından iki türe ayrılır: gen ağacı ve tür ağacı (ekrandan, 00:10:00). Gen ağacında ağaç, tek bir homolog gen içinde gözlenen ayrışmaya (divergence) dayanarak kurulur.

Ağaçlar ayrıca kullanılan veriye göre de sınıflandırılır: karakter tabanlı ve uzaklık tabanlı ağaçlar. Slayta göre filogenetik ağaç üretmek için kullanılan moleküler veri iki kategoriden birine girer (ekrandan, 00:15:00):

- **Karakter:** sınırlı sayıda farklı durumda bulunabilen, iyi tanımlanmış bir özellik (örneğin bir hizalama konumundaki nükleotit).
- **Uzaklık:** iki veri kümesi arasındaki genel, ikili (pairwise) farkın ölçüsü.

<!-- BELİRSİZ: 00:12–00:15 arası altyazı halüsinasyonla dolu; bu aralıkta anlatılan ayrıntılar alınamadı. -->

## 2. Filogenetik ağaç kurma yöntemleri ve karşılaştırmaları

Filogenetik yeniden kurma (reconstruction) yöntemleri üç gruba ayrılır:

1. **Uzaklık tabanlı yöntemler:** Diziler arasındaki ikili uzaklıklar hesaplanır, en çok benzeyen diziler gruplanır.
2. **Karakter tabanlı yöntemler (maksimum parsimoni):** Farklı varlıklarda paylaşılan karakterlerin ortak bir atadan geldiği varsayılır. Gruplar bu paylaşılan karakterlere göre kurulur; karakterlerin evrimi için en basit açıklama doğru, yani en tutumlu (most parsimonious) açıklama kabul edilir.
3. **Olasılıksal yöntemler (maksimum olabilirlik, maximum likelihood):** Belirli bir dizi evrimi modeli altında, veri kümesinin o veri kümesinden türetilen bir ağaca uyma olasılığı hesaplanır.

Hoca yöntemlere ayrıntılı girmeden önce slayttaki karşılaştırmayı anlattı (ekrandan, 00:20:00):

| Ölçüt | Uzaklık | Maksimum parsimoni | Maksimum olabilirlik |
|---|---|---|---|
| Kullandığı veri | Yalnız ikili uzaklıklar | Yalnız paylaşılan türemiş karakterler | Bütün veri |
| Amaç | En yakın komşular arasındaki uzaklığı enküçükler | Toplam uzaklığı enküçükler | Belirli parametre değerleriyle ağaç olabilirliğini enbüyükler |
| Hız | Çok hızlı | Yavaş | Çok yavaş |
| Zayıflık | Yerel optimuma kolay takılır | Evrim hızlıysa varsayımlar bozulur | Varsayılan evrim modeline çok bağımlı |

Uzaklık tabanlı yöntemler yerel optimuma kolay takıldığı için en iyi çözümü verme olasılıkları daha düşüktür. Hoca maksimum olabilirlik modelinin çok küçük veri kümeleri için ve başka yöntemlerle kurulmuş ağaçları test etmek için çok iyi olduğunu ekledi.

> **Ders sonrası not:** Hoca anlatırken uzaklık yönteminin en yakın komşular arasındaki uzaklığı, parsimoninin de toplam uzaklığı "enbüyüklediğini" (maximizes) söyledi; slaytta ikisi de "minimizes" (enküçükler) olarak yazılıdır. Doğrusu slayttaki gibidir.

## 3. Uzaklık tabanlı yöntemler ve UPGMA

### 3.1 Genel fikir

Uzaklık tabanlı yöntemlerde temelde ikili uzaklıklar, yani bir farklılık (dissimilarity) ölçüsü kullanılır. Önce dizi hizalaması yapılır, hizalamadan ikili uzaklıklar hesaplanır ve bir uzaklık (farklılık) matrisi kurulur. Filogenetik ağaç bu matrise bir kümeleme algoritması uygulanarak elde edilir.

Hoca, veri madenciliği ya da makine öğrenmesi derslerinde görülen herhangi bir kümeleme algoritmasının uzaklık tabanlı ağaç kurmada kullanılabileceğini söyledi. Örnekler UPGMA (önceki derslerde adı geçmişti) ve komşu birleştirme (neighbor joining) yöntemleridir; başka kümeleme yöntemleri de kullanılabilir.

> **Hocanın vurgusu:** Amaç kümelemede kullanılan bütün yöntemleri vermek değil, kümeleme yaklaşımının filogenetik ağaç kurmak için nasıl kullanılacağını göstermektir.

### 3.2 UPGMA

UPGMA, "Unweighted Pair-Group Method with Arithmetic mean" (aritmetik ortalamalı ağırlıksız çift grup yöntemi) adının kısaltmasıdır (ekrandan, 00:25:00). Adından anlaşıldığı gibi bir çeşit aritmetik ortalama ve bir çift gruplama yöntemi kullanır. En eski ve en basit uzaklık matrisi yöntemidir; gerçeklenmesi ve anlaşılması çok kolaydır. İlk olarak 1960'ların başında morfolojik karakterlerin evrimsel analizine yardım etmek için önerilmiştir.

Yöntem, taksonlar arasındaki ikili uzaklıkların bir matriste verildiğini varsayar. Dört türlü (A, B, C, D) bir örnekte satır ve sütunlarda türler listelenir; her hücre bir uzaklık ölçüsüdür. $d_{AB}$, A ile B türü arasındaki uzaklıktır ($d_{AB}=d_{BA}$, sıra önemli değildir) ve varsayılan uzaklık ölçüsüne göre bir sayıdır. Benzer biçimde $d_{AC}$, $d_{AD}$, $d_{BC}$, $d_{BD}$, $d_{CD}$ tanımlanır. Matris simetrik olduğu için yalnız bir üçgenini yazmak yeterlidir.

Algoritmanın adımları:

1. UPGMA, aralarındaki uzaklık en küçük olan iki türü tek bir bileşik grupta toplayarak başlar (ekrandan, 00:30:00). Örneğin matristeki en küçük değer $d_{AB}$ ise ilk gruplanan türler A ve B olur.
2. İlk kümelemeden sonra yeni grup ile kalan türler (C ve D) arasındaki uzaklıklarla yeni bir uzaklık matrisi hesaplanır. Yeni uzaklık, iki uzaklığın ortalamasıdır: (AB) grubu ile C arasındaki uzaklık, A–C ve B–C uzaklıklarının ortalamasıdır, $d_{(AB)C}=(d_{AC}+d_{BC})/2$. Yöntemin adındaki "ortalama" buradan gelir.
3. Dallanma noktaları, gruplanan türlerin her birinden uzaklığın yarısı kadar mesafeye konur; ilk grup için $d_{AB}/2$ gibi.
4. Tek bir grup kalana kadar en küçük uzaklığı bulma ve matrisi indirgeme yinelenir.

> **Ek bilgi (derste anlatılmadı):** Standart UPGMA'da iki küme birleştirilirken yeni uzaklık, kümelerdeki üye sayılarıyla ağırlıklandırılmış ortalamadır; her üye eşit ağırlık aldığı için yönteme "ağırlıksız" denir. Tek türle iki türlü bir grup birleştirildiğinde bu, iki uzaklığın düz ortalamasından farklı sonuç verebilir. Düz ortalama alan çeşit büyük olasılıkla WPGMA olarak bilinir.

### 3.3 UPGMA örneği

Beş farklı DNA dizisi (A, B, C, D, E) arasındaki şu hizalama verildi (ekrandan, 00:35:00). Her dizi 10'luk beş bloktan, toplam 50 kalıntıdan oluşur:

```text
A: GTGCTGCACGG CTCAGTATA GCATTTACCC TTCCATCTTC AGATCCTGAA
B: ACGCTGCACGG CTCAGTGCG GTGCTTACCC TCCCATCTTC AGATCCTGAA
C: GTGCTGCACGG CTCGGCGCA GCATTTACCC TCCCATCTTC AGATCCTATC
D: GTATCACACGA CTCAGCGCA GCATTTGCCC TCCCGTCTTC AGATCCTAAA
E: GTATCACATAG CTCAGCGCA GCATTTGCCC TCCCGTCTTC AGATCTAAAA
```

<!-- BELİRSİZ: slayttaki ilk iki blok 11 ve 9 harf gibi görünüyor (toplam yine 50); blok sınırları kareden okunduğu gibi bırakıldı. -->

Uzaklık ölçüsü olarak Hamming uzaklığı kullanılır: aynı konumda harfleri farklı olan konumların sayısı. Hoca A ile B'yi konum konum karşılaştırarak gösterdi: ilk iki konum farklıdır, sayım devam ettirilince toplam 9 fark bulunur, yani $d_{AB}=9$. Aynı işlem bütün çiftler (A–C, A–D, A–E, B–C, B–D, B–E, C–D, C–E, D–E) için yapılarak ikili uzaklık matrisi elde edilir (ekrandan, 00:35:00):

| | A | B | C | D |
|---|---|---|---|---|
| B | 9 | - | - | - |
| C | 8 | 11 | - | - |
| D | 12 | 15 | 10 | - |
| E | 15 | 18 | 13 | 5 |

Bu matrisin bütün değerleri, slayttaki diziler Python ile yeniden sayılarak doğrulandı.

**Adım 1.** Matristeki en küçük değer $d_{DE}=5$'tir. Bu yüzden ilk grup D ve E türlerinden oluşur; D ve E ağacın ilk parçasını oluşturur.

**Adım 2.** (DE) grubunun kalan türlere uzaklığı ortalamayla hesaplanır (ekrandan, 00:40:00):

- $d_{(DE)A}=\dfrac{12+15}{2}=13.5$
- $d_{(DE)B}=\dfrac{15+18}{2}=16.5$
- $d_{(DE)C}=\dfrac{10+13}{2}=11.5$

İndirgenmiş matris:

| | A | B | C |
|---|---|---|---|
| B | 9 | - | - |
| C | 8 | 11 | - |
| DE | 13.5 | 16.5 | 11.5 |

**Adım 3.** Yinelemede yine en küçük uzaklık bulunur: 8. Bir sonraki grup AC'dir. Böylece önce DE, sonra AC oluşur. Ardından yeni uzaklıklar yine ortalamalarla yeniden hesaplanır.

Hoca sonuç ağacı özetlerken AC ile DE'nin birbirine en yakın gruplar olduğunu, sonunda grupların birleştiğini söyledi ve UPGMA'ya dayalı filogenetik ağacın bu şekilde kurulduğunu belirtti.

> **Ders sonrası not:** AC grubu oluştuktan sonraki uzaklıklar (ara adım eklendi): $d_{(AC)B}=(9+11)/2=10$, $d_{(AC)(DE)}=(13.5+11.5)/2=12.5$, $d_{B(DE)}=16.5$. En küçük değer 10 olduğu için standart UPGMA'da üçüncü adımda B, (AC) grubuna katılır; (DE) grubu en son birleşir. Python ile yapılan kontrol bu sırayı verdi. Hocanın 00:41 civarında söylediği birleştirme sırası altyazıda bozuk olduğundan kesinleştirilemedi.

<!-- BELİRSİZ: 00:38–00:41 arasında hocanın üçüncü adımı nasıl anlattığı altyazıdan okunamıyor ("10, 13" gibi sayılar geçiyor); ilgili slayt karede yok. -->

### 3.4 Başka uzaklık ölçüleri

Hoca soru olup olmadığını sorduktan sonra şunu ekledi: örnekte boşluk (gap) yoktu, bu yüzden Hamming uzaklığı yeterliydi. Bazı hizalamalarda boşluk bulunur; o durumda Levenshtein uzaklığı kullanılabilir. Diziler sayısal değerlere dönüştürülmüşse sayısal uzaklık ölçüleri de kullanılabilir.

## 4. Dal uzunluklarının kestirimi

### 4.1 Ölçekli ağaçta dal uzunlukları

UPGMA ağacı dizilerin akrabalığını gösterir. Filogenetik ağacın topolojisi, dizilerin birbirinden ne ölçüde ayrıştığı hakkında da bilgi taşıyabilir. Hoca, dalların uzunluğunun dizilerin birbirinden bağımsız olarak yer değiştirme (substitution) biriktirdiği tahmini süreye karşılık geldiği ağaçlara kladogram dendiğini söyledi; bu bilgi daha önce de geçmişti.

Slayta göre bir kladogramdaki her dalın göreli uzunluğu uzaklık matrisindeki bilgiyle hesaplanabilir (ekrandan, 00:45:00):

- Örnekte $d_{DE}=5$'tir. D ve E'yi ortak atalarına bağlayan dalların her biri, ölçekli dal uzunluklu bir ağaçta $d_{DE}/2=2.5$ birim uzunluğunda olmalıdır.
- A ve C ortak atalarına $d_{AC}/2=4$ birim uzunluğunda dallarla bağlanmalıdır, çünkü $d_{AC}=8$'dir.
- (AC) ile (DE) arasındaki dallanma noktası, (AC)'ye ve (DE)'ye $d_{(AC)(DE)}/2=6.25$ birim uzunluğunda dallarla bağlanmalıdır.

Sonraki slaytta dal uzunlukları her dalın yanında gösterildi (4, 4, 2.5, 2.5 vb.); dallar türler arasındaki farkın miktarını yansıtacak biçimde ölçekli çizilir ve ağaç zamanı da gösterir.

> **Ders sonrası not:** $6.25=12.5/2$ ve $12.5$, yukarıdaki ara adımda bulunan $d_{(AC)(DE)}$ değeridir. Dal uzunluklarının evrim miktarını gösterdiği ağaçlar genelde büyük olasılıkla "filogram" ya da ölçekli ağaç diye anılır; klasik kladogramda yalnız dallanma sırası önemlidir. Slayt bu ayrımı yapmadan "cladogram" terimini kullanıyor.

Dal uzunluklarını bu çok basit yolla kestirmek, UPGMA'nın kendiliğinden köklü (rooted) filogenetik ağaç üretmesini sağlar. Hoca, ağaçları farklı ölçütlere göre sınıflandırdığımızı ve ölçütlerden birinin ağacın kökünün olup olmamasının olduğunu hatırlattı.

### 4.2 Evrim hızı eşit değilse

Ölçekli bir ağaç için dal uzunluklarını belirlemek, evrim hızlarının bütün soy hatları için aynı olduğu varsayılamadığında yalnızca biraz daha karmaşıktır (ekrandan, 00:50:00).

Dal uzunluklarının anlamlı bilgi taşıyabildiği en basit ağaç üç türlü ağaçtır: A, B, C türleri ve tek bir dallanma noktası. Üç dal uzunluğu $a$, $b$, $c$ harfleriyle gösterilirse şunlar doğru olmalıdır (ekrandan, 00:55:00):

$$a+b=d_{AB},\qquad b+c=d_{BC},\qquad a+c=d_{AC}$$

Hoca bunun temelde geometriye çok benzediğini söyledi. Üç dizi için tek bir ağaç topolojisi vardır. Uzaklık matrisi dal uzunlukları cinsinden şöyle yazılır:

| | A | B | C |
|---|---|---|---|
| A | - | $a+b$ | $a+c$ |
| B | - | - | $b+c$ |
| C | - | - | - |

- **Girdi:** ikili uzaklıklar $d_{AB}$, $d_{BC}$, $d_{AC}$.
- **Çıktı:** dal uzunlukları

$$a=\frac{d_{AB}+d_{AC}-d_{BC}}{2},\qquad b=\frac{d_{AB}+d_{BC}-d_{AC}}{2},\qquad c=\frac{d_{AC}+d_{BC}-d_{AB}}{2}$$

Hoca $a$'nın formülünü tahtada gösterdi: $d_{AB}+d_{AC}-d_{BC}=(a+b)+(a+c)-(b+c)$. Burada $b$ ve $c$ birbirini götürür, $2a$ kalır; 2'ye bölünce $a$ bulunur.

> **Hocanın vurgusu:** Bu basit geometridir. Buradaki ağaç üç tür için köksüz (unrooted) bir ağaçtır.

### 4.3 Üç dizide dal uzunluğu örneği

Sonraki slaytta sayısal bir örnek çözüldü (ekrandan, 01:00:00). Slaytta görülen adımlar:

- (1) ve (4) numaralı denklemler toplanır: $a+b+b-a=2b=22+2=24$, buradan $b=24/2=12$.
- $a+b=a+12=22$ olduğundan $a=22-12=10$.
- Son olarak $a+c=10+c=39$ olduğundan $c=39-10=29$.

Sonuç ağaçta A dalı 10, B dalı 12, C dalı 29 birimdir.

Bu sonuçlar $d_{AB}=22$, $d_{AC}=39$ ve $d_{BC}=b+c=41$ uzaklıklarına karşılık gelir; (4) numaralı denklem büyük olasılıkla $b-a=d_{BC}-d_{AC}=2$'dir (ara adım eklendi). Genel formülle de aynı sonuç çıkar: $a=(22+39-41)/2=10$, $b=(22+41-39)/2=12$, $c=(39+41-22)/2=29$ (Python ile doğrulandı).

<!-- BELİRSİZ: uzaklık matrisinin ve (2)–(4) denklemlerinin bulunduğu önceki slayt karede yok; $d_{BC}=41$ sonuçtan geriye hesaplandı. -->

Hoca yöntemin basit ve doğrudan olduğunu, basit bir uzaklık matrisiyle başlayıp basit bir kümeleme uygulandığını tekrarladı.

## 5. Komşuluk ilişkisi yöntemi ve komşu birleştirme

<!-- BELİRSİZ: 00:57–01:12 arasında kayıtta ara var; altyazı yalnız halüsinasyon içeriyor. -->

### 5.1 Komşuluk ilişkisi yöntemi (Neighbor's Relation Method)

Hoca bu yöntemi UPGMA'nın bir başka popüler çeşidi olarak tanıttı. Yöntem, türleri genel olarak olabilecek en küçük toplam dal uzunluğuna sahip bir ağaç oluşacak biçimde eşleştirmeyi öne çıkarır. Herhangi bir köksüz ağaçta, birbirinden yalnız bir iç düğümle ayrılan tür çiftleri komşu olmak zorundadır.

Slayttaki gibi bir filogenetik ağacın topolojisi, komşular arasında yararlı cebirsel ilişkiler doğurur (ekrandan, 01:15:00). Ağaçta A ve B bir tarafta, C ve D öbür tarafta yer alır; $a$, $b$, $c$, $d$ uç dalların uzunlukları, $e$ tek merkez dalın uzunluğudur. Ağaç, toplanabilirliğin (additivity) geçerli olduğu gerçek bir ağaçsa:

$$d_{AC}+d_{BD}=d_{AD}+d_{BC}=a+b+c+d+2e=d_{AB}+d_{CD}+2e$$

Bu ağaçta kök yoktur. Bu yöntemde, birlikte dört nokta koşulu (four-point condition) diye bilinen şu koşullar da doğrudur:

$$d_{AB}+d_{CD}<d_{AC}+d_{BD},\qquad d_{AB}+d_{CD}<d_{AD}+d_{BC}$$

Filogenetik ağaçtaki dal uzunlukları toplanabilir olmalıdır. Yöntem bu varsayımdan sapmalara özellikle duyarlı değildir, ama toplanabilir olmayan veri kümeleri yöntemin yanlış topolojili bir ağaç üretmesine yol açabilir.

### 5.2 Komşuluk ilişkisi örneği

Mikrofon bir süre kapalı kaldığı için hoca örneği baştan anlattı. Şu hizalama verildi (ekrandan, 01:20:00):

```text
A  ACGCGTTGGGCGATGGCAAC
B  ACGCGTTGGGCGACGGTAAT
C  ACGCATTGAATGATGATAAT
D  ACACATTGAGTGATAATAAT
```

Diziler arasındaki uzaklıklar bir tabloyla gösterilir. Hoca uzaklıkların nasıl bulunduğunu tekrarladı: A ile B arasında üç konum farklıdır (1, 2, 3), yani $d_{AB}=3$. Aynısı A–C, A–D, B–C, B–D ve C–D için yapılır:

| | A | B | C | D |
|---|---|---|---|---|
| A | - | 3 | 7 | 8 |
| B | - | - | 6 | 7 |
| C | - | - | - | 3 |
| D | - | - | - | - |

Tablo değerleri Python ile doğrulandı.

Köklü ağaç kurmak istenirse ilk yaklaşım, yani UPGMA kullanılır. Köksüz ağaç kurmak istenirse dal uzunlukları kestirilir. Matristeki uzaklık bilgisiyle $a$, $b$, $c$, $d$, $e$ değerleri kolayca bulunabilir. Hoca bulunan değerleri uzaklıklarla tek tek karşılaştırdı (derste sözlü, 01:23:29):

- $d_{AB}=3$: $2+1=3$ ($a=2$, $b=1$)
- $d_{AC}=7$: $2+4+1=7$
- $d_{AD}=8$: $2+4+2=8$
- $d_{BD}=7$: $1+4+2=7$
- $d_{CD}=3$: $1+2=3$ ($c=1$, $d=2$)

Buradan $a=2$, $b=1$, $c=1$, $d=2$, $e=4$ olur ve ağaç tablodaki uzaklıklarla iyi uyuşur. $d_{BC}=1+4+1=6$ de tutar (ara adım eklendi).

> **Ders sonrası not:** Örnek dört nokta koşulunu da sağlar: $d_{AB}+d_{CD}=6$, $d_{AC}+d_{BD}=d_{AD}+d_{BC}=14$ ve $14=6+2\cdot 4$, yani $2e=8$, $e=4$ (Python ile doğrulandı).

<!-- BELİRSİZ: dal uzunluklarının gösterildiği ağaç çizimi karede yok; değerler hocanın sözlü kontrolünden alındı. -->

### 5.3 Komşu birleştirme (Neighbor-Joining)

Komşu birleştirme, komşuluk yaklaşımının basit bir çeşididir; aglomeratif (birleştirici) bir tekniktir ve bu yüzden yinelemeyle çalışır, ağacı aşağıdan yukarıya kurar (ekrandan, 01:25:00).

- Tür sayısı ne olursa olsun bütün türlerin tek bir merkez düğümden çıktığı yıldız biçimli bir ağaçla başlanır.
- Ardından ağaçtaki dalların toplam uzunluğunu enküçükleyen komşular sırayla bulunur.
- Girdi $n\times n$ bir farklılık (uzaklık) matrisidir.
- İlk yinelemede $n$ yaprağın her biri kendi kümesindedir. Her küme bir yaprak kümesidir ve kümeler ayrıktır.
- Her yinelemenin başında taksonlar kümelere ayrılmış durumdadır. Her yinelemede kardeş yapılacak bir küme çifti seçilir; bu, iki kümenin ağaçlarının köklerini kardeş yaparak daha büyük köklü bir ağaçta birleşmesiyle sonuçlanır.
- Sonunda üç alt ağaç, yeni bir $R$ düğümü eklenerek ve üç alt ağacın kökleri $R$'ye bağlanarak bütün taksonları içeren tek ağaçta birleştirilir.

Hoca bu anlatımın komşu birleştirmenin köklü bir ağaç ürettiğini düşündürdüğünü belirtti. <!-- BELİRSİZ: cümlenin devamı altyazıda kesik ve sayı halüsinasyonuyla dolu. -->

Hoca uzaklık tabanlı yöntemlerin başka çeşitleri de olduğunu, ama bunların dersin kapsamı dışında kaldığını söyledi.

## 6. Karakter tabanlı yöntemler: maksimum parsimoni

### 6.1 Parsimoni kavramı

Parsimoni kavramı, filogenetik yeniden kurmanın bütün karakter tabanlı yöntemlerinin tam merkezindedir (ekrandan, 01:30:00). Slayta göre "parsimonious", parasını harcarken özellikle dikkatli olan kişidir.

Hoca bunun Türkçe karşılığını sordu. Sınıftan "cimri" cevabı geldi; hoca bunun kabul edilebileceğini, ama daha iyi kelimenin "tutumlu" olduğunu söyledi.

Biyolojik anlamda parsimoni, bir evrimsel yolu diğerine tercih ederken en az sayıda mutasyon olayı gerektiren yolu seçme sürecini anlatır. Filogenetik ağaçlar, iki ya da daha fazla dizinin evrim tarihini gösteren kuramsal modellerdir.

### 6.2 Bilgi verici ve bilgi vermeyen konumlar

Dört dizili kısa bir çoklu dizi hizalamasında konumlar, parsimoni analizi için taşıdıkları bilgi bakımından iki kategoriye ayrılır: bilgi verici (informative) ve bilgi vermeyen (uninformative). Dört dizi için üç farklı köksüz ağaç vardır.

<!-- BELİRSİZ: bu bölümdeki hizalama ve üç ağacın çizimi karede yok; konumların durumu hocanın sözlü anlatımından aktarıldı. -->

- **Konum 1:** Dört dizide de aynı karakter (G) vardır. Bu yüzden konum değişmezdir (invariant). Değişmez konumlar açıkça bilgi vermez, çünkü dört dizinin ilişkisini anlatan üç olası ağacın her biri tam olarak aynı sayıda mutasyon gerektirir.
- **Konum 2:** Üç olası ağacın hepsinde bir mutasyon gerektiği için parsimoni açısından bilgi vermez.
- **Konum 3:** Üç ağacın hepsi iki mutasyon gerektirdiği için bilgi vermez.
- **Konum 4:** Üç ağacın hepsi üç mutasyon gerektirdiği için bilgi vermez.
- **Konum 5:** Bilgi vericidir, çünkü üç ağaçtan biri yalnız bir mutasyon gerektirir, diğer iki alternatif ağaç ikişer mutasyon gerektirir.
- **Konum 6:** Aynı nedenle bilgi vericidir: ağaçlardan biri bir mutasyon, diğer ikisi ikişer mutasyon gerektirir.

Genel kural olarak, kaç dizi hizalanmış olursa olsun bir konumun bilgi verici olması için o konumda en az iki farklı nükleotit bulunmalı ve her biri en az iki dizide görülmelidir. <!-- BELİRSİZ: kuralın ikinci kısmı altyazıda bozuk ("iki tane nucleotide var ... iki tane"); standart tanımla tamamlandı. -->

Bilgi vermeyen konumlar belirlenip atıldıktan sonra, parsimoni yaklaşımının en basit gerçeklemesi doğrudandır:

1. Her bilgi verici konum için her olası ağaç ayrı ayrı ele alınır.
2. Her ağaç için, her konumda gereken en az yer değiştirme sayısını izleyen bir sayaç tutulur.
3. Bütün bilgi verici konumlar ele alındıktan sonra en az toplam yer değiştirme gerektiren ağaç "en tutumlu" (most parsimonious) olarak işaretlenir.

### 6.3 Maksimum parsimoni örnekleri

Maksimum parsimoni yöntemleri, dizilerde gözlenen çeşitliliği üretmek için gereken adım sayısını enküçükleyen evrim ağacını öngörür. Önce bir çoklu dizi hizalaması elde edilmelidir. Sonra her hizalanmış konum için, gözlenen dizi değişimlerini üretmek üzere en az evrimsel değişim gerektiren ağaçlar belirlenir.

Slayttaki örnekte dört dizi AAG, AAA, GGA ve AGA için iki ağaç karşılaştırılır (ekrandan, 01:40:00):

- **Sol ağaç:** kök AAA; bir alt ağaçta iç düğüm AAA, yapraklar AAG ve AAA; diğer alt ağaçta iç düğüm AGA, yapraklar GGA ve AGA. Değişimler: AAA→AGA (1), AAA→AAG (1), AGA→GGA (1). Toplam yer değiştirme sayısı 3.
- **Sağ ağaç:** kök AAA; bir alt ağaçta iç düğüm AAA, yapraklar AAG ve AGA; diğer alt ağaçta iç düğüm AAA, yapraklar AAA ve GGA. Değişimler: AAA→AAG (1), AAA→AGA (1), AAA→GGA (2). Toplam yer değiştirme sayısı 4.

Sol ağaç daha tutumlu olduğu için sağ ağaca tercih edilir. Fitch algoritmasıyla yapılan Python kontrolü de sol topoloji için 3, diğer iki topoloji için 4 değişim verdi.

Dört dizi varken üç olası köksüz ağaç vardır: (1,2)(3,4), (1,3)(2,4) ve (1,4)(2,3).

Hoca ardından dört kısa diziyle (S1–S4) bir örnek daha gösterdi. (S1,S2)(S3,S4) ağacında konum konum gereken değişimler sayıldı (2, 0, 0, 1, 1, 1, 1 gibi) ve toplam 6 bulundu. (S1,S3)(S2,S4) ağacında toplam 7, (S1,S4)(S2,S3) ağacında da toplam 7 değişim çıktı. En az değişim gerektiren ilk ağaç seçilir.

<!-- BELİRSİZ: S1–S4 dizileri altyazıda bozuk ("CACCCCT", "AACCCCT", "CACTGCTT", "AACTGCTA" gibi; uzunlukları tutarsız), slayt karede yok; toplamlar hocanın sözlü anlatımından alındı ve doğrulanamadı. -->

## 7. Maksimum olabilirlik

Yöntemlerin üçüncü grubu maksimum olabilirliktir (ekrandan, 01:45:00):

- Maksimum parsimoni yöntemi gibi bütün olası ağaçları üretir.
- Ama en kısa evrimsel adımlı ağaçları tutmak yerine, farklı geçiş/dönüşüm (transition/transversion) oranlarının kullanılabildiği bir evrim modeli kullanır.
- Üretilen her ağaç için, dizi verisinin her konumunu yansıtma olasılığı hesaplanır.
- Hesap bütün nükleotit konumları için tekrarlanır.
- Sonunda en iyi olasılığa sahip ağaç maksimum olabilirlik ağacı olarak gösterilir; genelde tek bir ağaç kalır.
- Bütün dallar için eşit geçiş-dönüşüm oranı varsaymadığı için daha gerçekçi bir ağaç kestirimidir.

> **Ek bilgi (derste anlatılmadı):** Geçiş (transition), bir pürinin başka bir pürine (A↔G) ya da bir pirimidinin başka bir pirimidine (C↔T) dönüşmesidir. Dönüşüm (transversion) ise pürin ile pirimidin arasındaki değişimdir. Doğada geçişler genelde dönüşümlerden daha sık görülür; bu yüzden ikisine farklı oran vermek modeli gerçekçi kılar.

## 8. Ağaç güvenilirliği: bootstrap ve parametrik testler

### 8.1 Ağaç güveni

Bütün filogenetik ağaçlar, bir veri kümesini oluşturan dizilerin evrim tarihi hakkında birer hipotezdir. Her iyi hipotezde olduğu gibi, alttaki veriyi ne kadar iyi açıkladığına dair iki soru sormak mantıklıdır. Birinci soru, ağacın tamamına ve bileşenlerine, yani dallarına ne kadar güven duyulabileceğidir. İkinci soru (8.3'te), en tutumlu ağacın belirli bir alternatif ağaçtan ne kadar daha olası olduğudur.

### 8.2 Bootstrap

Bootstrap, belirli bir filogenetik ağacın güven düzeyini kestiren hesaplamalı bir yöntemdir (ekrandan, 01:50:00). İstatistikte bootstrap, yerine koyarak rastgele örneklemeye dayanan herhangi bir test ya da ölçüdür; daha geniş yeniden örnekleme (resampling) yöntemleri sınıfına girer. Belirli bir kümenin desteği, yeniden örneklenmiş verilerden kurulan ağaçlardan o kümeyi içerenlerin oranıyla verilir.

Slayttaki gösterimde 10 karakter uzunluğunda bir veri kümesi vardır; her karakter bir konumdur (1–10). Beş dizi Roma rakamlarıyla (I–V) gösterilir. Özgün veri kümesi ve onun en tutumlu ağacı (A) gösterilir. Ardından yeniden örneklenmiş veri kümelerinin ağaçlarından bir uzlaşı (consensus) ağacı kurulur; daire içindeki değerler, bu bootstrap ağaçlarından kaçının 1 ve 2 dizilerini, kaçının 4 ve 5 dizilerini aynı kümede gösterdiğinin oranını belirtir.

İkinci örnekte sıçan, insan, kaplumbağa, meyve sineği gibi canlıların DNA dizileri hizalanıp bu hizalamadan bir ağaç çıkarılır; ağaç, sıçan ile insanın kaplumbağaya göre birbirine daha yakın olduğunu gösterir. Sonra yeniden örneklenmiş örneklemlerle (örnek 1, ...) aynı işlem tekrarlanır.

<!-- BELİRSİZ: bootstrap gösterim slaytları karede yok; örnek canlıların listesi ve değerler altyazıda bozuk ("red, human, turtle, field, fly, or duck"). -->

> **Ek bilgi (derste anlatılmadı):** Filogenetik bootstrap'ta hizalamanın sütunları (konumları) yerine koyarak rastgele seçilir ve özgün uzunlukta yeni bir hizalama oluşturulur. Bu işlem yüzlerce kez yapılır, her yeni hizalamadan ağaç kurulur. Bir dalın bootstrap değeri, o dalı içeren ağaçların yüzdesidir.

### 8.3 Parametrik testler

Yaygın bir soru şudur: en tutumlu ağaç, bu taksonların ilişkisini anlatmak için daha önce önerilmiş belirli bir alternatif ağaçtan ne kadar daha olasıdır? Parsimoni analizinde bu tür soruları cevaplamak için geliştirilen ilk parametrik testlerden biri H. Kishino ve M. Hasegawa'nınkidir.

- Testte bir hizalamadaki bilgi verici konumların hem bağımsız hem de eşdeğer olduğu varsayılır.
- İki ağacın gerektirdiği en az yer değiştirme sayıları arasındaki fark $D$, test istatistiği olarak kullanılır.
- $D$'nin varyansı $V(D)$, bilgi verici konumların her biri ayrı ayrı ele alınarak bir formülle belirlenir; formülde $n$ bilgi verici konum sayısıdır.
- Ardından $n-1$ serbestlik dereceli eşleştirilmiş t-testi (paired t-test) ile iki ağacın birbirinden farklı olmadığı sıfır hipotezi test edilir.

Hoca t-testinin istatistiksel veri analizi derslerinden hatırlanması gerektiğini söyledi ve başka parametrik testlerin de olduğunu belirtti.

<!-- BELİRSİZ: $V(D)$ formülü slaytta gösterildi, kare yok. Altyazıda yazar adı "Yishino" diye bozuk geçiyor; doğrusu Kishino'dur. -->

## 9. Moleküler filogenetiğin uygulamaları ve hata kaynakları

### 9.1 Moleküler filogenetikle yapılan bazı keşifler

- **Evrensel yaşam ağacı:** RNA dizileri kullanılarak kurulmuştur.
- Yellowstone Ulusal Parkı'ndaki bir sıcak su kaynağından elde edilen, kültürlenemeyen organizmaların ilişkisini incelemeyi sağlamıştır.
- **Endosimbiyoz:** mitokondri ve kloroplastın kökeni (ekrandan, 01:55:00). Slayttaki ağaçta mitokondri α-mor bakterilerin (α-purple bacteria) yanında, kloroplastlar siyanobakterilerin yanında yer alır; ökaryotlar ve arkeler kökün öbür tarafındadır.

### 9.2 Hata kaynakları

Hoca, filogenetik yeniden kurmada da modern veri biliminde olduğu gibi "daha çok veri daha iyidir" ilkesinin geçerli olduğunu söyledi. Filogenide hatalar şunlardan kaynaklanabilir:

- Küçük veri kümesi ve/veya sınırlı örnekleme.
- Duplikasyon, inversiyon, ekleme (insertion), silme (deletion) gibi mutasyonların yanlış sinyal vermesi.
- Genomik sıcak noktalar: hızlı evrimleşen küçük bölgeler kolayca saptanamaz.
- Homoplazi.

<!-- BELİRSİZ: homoplazinin açıklaması altyazıda bozuk. -->

> **Ek bilgi (derste anlatılmadı):** Homoplazi, ortak atadan gelmeyen, bağımsız olarak (yakınsak evrim ya da geri mutasyonla) ortaya çıkmış benzerliktir. Ortak kökenli benzerlik sanıldığında yanlış gruplamaya yol açar.

## 10. İstatistik tekrarı: veri analizi

Aradan sonra hoca yeni bir slayt setine geçti: istatistik biyoenformatikte yoğun kullanıldığı için bu set bir istatistik tekrarı, bazı kavramları hatırlatan bilgilerdir.

### 10.1 Veri analizinin kategorileri

Veri analizi birkaç kategoriye ayrılabilir (ekrandan, 02:15:00):

- Anlatısal (narrative), örneğin hukuk, sanat.
- Betimsel (descriptive), örneğin sosyal bilimler.
- İstatistiksel/matematiksel (temel ve uygulamalı bilimler).
- İşitsel-optik (audio-optical), örneğin telekomünikasyon.
- Diğerleri.

Araştırma analizlerinin çoğu ilk üçünü kullanır. Hoca ikinci ve üçüncünün en yaygın olanlar olduğunu ve bizi daha çok ilgilendirdiğini söyledi.

İstatistiksel yöntemler istatistikle bir şey yapmak için geliştirilmiş yöntemlerdir. İstatistik, nesne, şey, kişi, olay gibi öğelerden oluşan bir örneklem hakkında anlamlı niceliklerdir; birçok alanda yaygın kullanılır, biyoenformatikte de derslerde görüldüğü gibi yoğun kullanılır. Basitten karmaşığa istatistik konuları arasında korelasyon, ANOVA, MANOVA, regresyon ve modelleme sayılabilir.

### 10.2 Betimsel ve çıkarımsal istatistik

İstatistiğin iki ana kategorisi vardır: betimsel (descriptive) ve çıkarımsal (inferential). Betimsel istatistik, örneklem bilgisini kullanarak anakütle olgularını açıklamaktır. Olgular şunlar olabilir: ilişki (association), eğilim (tendency), neden-sonuç ilişkisi, trend, bir tür örüntü, dağılım (dispersion) ya da aralık (range).

<!-- BELİRSİZ: hocanın betimsel istatistiğin parametrik olmayan analizde kullanıldığını söyleyip verdiği örnekler altyazıda bozuk ("G2, T, T, Kürver"); çıkarımsal istatistik anlatımı 02:18–02:19 arasında okunamıyor. -->

### 10.3 Hatalardan kaçınma: yararlı ipuçları

Slayttaki ipuçları (ekrandan, 02:20:00):

- Araştırma problemini netleştir; uygulanabilirliğine (operability) dikkat et.
- Veri analizi teknikleri üzerine literatür oku.
- Araştırma problemine göre benzer işi yapabilen çeşitli teknikleri değerlendir.
- Bir tekniğin ne yaptığını ve ne yapmadığını bil.

Hoca ayrıca konuyu daha iyi bilenlere danışılması ve pilot veriyle deneme yapılıp sonuçların değerlendirilmesi gerektiğini söyledi.

### 10.4 Analizin ilkeleri

Analizin amacı şunlardan biri olabilir: neden-sonuç olgusunu açıklamak, araştırmayı gerçek dünya olaylarıyla ilişkilendirmek, araştırmaya dayanarak gerçek dünya olgularını öngörmek ya da tahmin etmek, belirli bir probleme cevap bulmak, probleme dayanarak gerçek olaylar hakkında sonuç çıkarmak ya da problemden ders almak.

"Veri konuşamaz." Analiz, verinin tanımlanması, yorumlanması, değerlendirilmesi, örneklenmesi, tartışılması, açıklanması, netleştirilmesi, karşılaştırılması ve karşıtlığının gösterilmesi gibi bilimsel akıl yürütme ve argüman öğeleri içerir.

Bir analizin dört öğesi olmalıdır:

1. Veri ya da bilgi.
2. Bilimsel akıl yürütme, argüman.
3. Bulgular, yani sonuçlar.
4. Dersler ve sonuçlar (çıkarımlar).

Beklenen cevapları görselleştirmek çok önemlidir; hoca görselleştirmenin istatistik tartışmalarından birkaç hafta sonra işleneceğini söyledi. Cevaplar veriyle doğrulanmalıdır.

> **Hocanın vurgusu:** Veriyle desteklenmeyen bir şey söylenmemelidir. Bu nesnellik demektir: analiz yaparken nesnel, doğru ve dürüst olmak gerekir.

## 11. Örneklem, anakütle ve veri türleri

### 11.1 Örneklem ve anakütle

İstatistik, bir anakütlenin temsilci bir örnekleminden gözlenen veriye dayanarak o anakütle hakkında ifadeler üretmekle ilgilidir. Uygulamada istatistiksel yöntemler, yaklaşımlar ve algoritmalar örneklemler üzerinde uygulanır.

- **Parametre:** bir anakütlenin bir özelliğini betimleyen sayısal değer (ekrandan, 02:25:00).
- **İstatistik (statistic):** bir örneklemin bir özelliğini betimleyen sayısal ölçüm.

İstatistik, parametreler hakkında çıkarım yapmak için kullanılır.

### 11.2 Veri keşfi

Veri keşfi (data exploration) bir kavramdır: veri toplandıktan, yani anakütleden örneklem alındıktan sonra istatistiksel çıkarım ve karar vermeye doğru atılan bir sonraki adım veri keşfidir. Örneklem ve gözlenen (ölçülen) özellikler incelenir.

- Veriyi daha yönetilebilir yapmak için bilgi miktarı anlamlı yollarla azaltılır, böylece verinin anahtar yönlerine odaklanılır. Veri biliminde bu veri azaltmadır: ön analiz ya da veri işleme uygulanarak bazı özellikler (feature) çıkarılır ve daha az veriyle çalışılır.
- Basit betimsel istatistikte özet istatistikler kullanılır. Özet istatistikler, bir veri kümesindeki bilgiyi temsil eden birkaç istatistiksel parametreden oluşur.
- Veri keşfi teknikleriyle bir değişkenin dağılımı öğrenilir. Dağılım, değişkenin alabileceği olası değerleri, bu değerleri gözleme şansını ve anakütleden alınan rastgele bir örneklemde bunları ne sıklıkta görmeyi beklediğimizi söyler.
- Veri keşfiyle daha önce bilinmeyen ve ayrıca incelenmeye değer örüntü ve ilişkiler bulunabilir.

### 11.3 İstatistiksel çıkarım

Bilinmeyen anakütle ortalamasını kestirmek isteriz. Bunun için örneklem kullanılır. Anakütlenin tamamı yerine örneklem kullanıldığında kestirimlere her zaman bir belirsizlik girer; bu belirsizlik hata biçimindedir. İstatistiksel çıkarımda her zaman belirsizlik olduğu için olasılık kavramına gelinir: istatistikte belirsizliği ele almanın matematiksel aracı olasılıktır (ekrandan, 02:30:00).

### 11.4 Veri türleri

Bir çalışmada toplanan verinin türü, kullanılabilecek istatistiksel analizin türünü, hangi hipotezlerin test edilebileceğini ve tahmin için hangi modelin kullanılabileceğini belirler. Veri iki ana türe ayrılır: kategorik ve niceliksel.

**Kategorik veri**, bazı niteliksel özelliklere göre kategorilere ayrılabilir; sonuç veri esas olarak etiketler ya da kategorilerdir (örneğin cinsiyet ya da etnik köken).

- DNA dizileri ve amino asit dizileri kategorik veri türleridir ve nominaldir. Yapılan analize göre bu veri türleri sayısal veri türlerine, hatta ordinal veri türlerine dönüştürülebilir.
- **Nominal veri:** kategorilerin doğal bir sırası yoksa veri nominaldir (örneğin siyah ya da sarı gibi renkler).
- **Ordinal veri:** sıralama mümkünse veri ordinaldir. Örneğin ağrı: orta ağrı, daha çok ağrı, aşırı yüksek ağrı gibi düzeyler ve bir sıra vardır.

**Niceliksel (sayısal) veri**, sayıların basit etiketlerle değil bir ölçek ölçüsüyle ilişkili olduğu sayısal ölçümlerdir (ekrandan, 02:35:00). İki kategoriye ayrılır:

- **Kesikli:** sonlu ya da sayılabilir sayıda olası değeri vardır; veri sayımları temsil ediyorsa kesiklidir.
- **Sürekli:** veri boşluksuz gerçek sayılardır. Uzunluk, hacim, kütle gibi fiziksel nicelikler genelde sürekli kabul edilir.

Niceliksel veri tipik olarak ortalamalarla özetlenir.

## Örnek Sorular

**Soru 1 (ekrandan, 00:35:00 ve 00:40:00):** Beş dizinin (A–E) ikili Hamming uzaklık matrisi aşağıdadır. UPGMA ile ilk iki birleştirme adımını yapınız ve ilk adımdan sonraki indirgenmiş matrisi yazınız.

| | A | B | C | D |
|---|---|---|---|---|
| B | 9 | - | - | - |
| C | 8 | 11 | - | - |
| D | 12 | 15 | 10 | - |
| E | 15 | 18 | 13 | 5 |

**Çözüm (derste verildi):** En küçük uzaklık $d_{DE}=5$, D ve E birleşir. Yeni uzaklıklar: $d_{(DE)A}=(12+15)/2=13.5$, $d_{(DE)B}=(15+18)/2=16.5$, $d_{(DE)C}=(10+13)/2=11.5$. İndirgenmiş matristeki en küçük değer $d_{AC}=8$ olduğundan ikinci grup AC'dir. Dal uzunlukları D ve E için 2.5, A ve C için 4 birimdir.

> **Çözüm (derste verilmedi):** Sonraki adımda $d_{(AC)B}=10$, $d_{(AC)(DE)}=12.5$, $d_{B(DE)}=16.5$ olur; en küçük değer 10 olduğu için B, (AC) ile birleşir. Son adımda ((AC)B) ile (DE) birleşir; birleşme uzaklığı üye sayısıyla ağırlıklı UPGMA'da $(2\cdot 12.5+16.5)/3\approx 13.83$, iki uzaklığın düz ortalamasıyla $(12.5+16.5)/2=14.5$'tir. Python ile kontrol edildi.

**Soru 2 (ekrandan, 00:55:00 ve 01:00:00):** Üç diziden oluşan köksüz ağaçta $a+b=22$ ve $a+c=39$, ayrıca $b-a=2$ verilmiştir. $a$, $b$, $c$ dal uzunluklarını bulunuz.

**Çözüm (derste verildi):** $a+b+b-a=2b=22+2=24$, $b=12$. $a=22-12=10$. $c=39-10=29$.

**Soru 3 (ekrandan, 01:20:00; derste sözlü, 01:23:18):** A `ACGCGTTGGGCGATGGCAAC`, B `ACGCGTTGGGCGACGGTAAT`, C `ACGCATTGAATGATGATAAT`, D `ACACATTGAGTGATAATAAT` dizileri için uzaklık tablosunu çıkarınız ve (A,B)(C,D) topolojili köksüz ağacın $a,b,c,d,e$ dal uzunluklarını belirleyiniz.

**Çözüm (derste verildi):** $d_{AB}=3$, $d_{AC}=7$, $d_{AD}=8$, $d_{BC}=6$, $d_{BD}=7$, $d_{CD}=3$. Dal uzunlukları $a=2$, $b=1$, $c=1$, $d=2$, $e=4$; her uzaklık bu değerlerle tutar ($2+1=3$, $2+4+1=7$, $2+4+2=8$, $1+4+2=7$, $1+2=3$).

**Soru 4 (derste sözlü, 01:28:29):** "Parsimonious" (parasını harcarken çok dikkatli olan kişi) kelimesinin Türkçe karşılığı nedir?

**Cevap (derste verildi):** Sınıftan "cimri" cevabı geldi; hoca daha iyi karşılığın "tutumlu" olduğunu söyledi.

**Soru 5 (ekrandan, 01:40:00):** AAG, AAA, GGA, AGA dizileri için (AAG, AAA)(GGA, AGA) ve (AAG, AGA)(AAA, GGA) ağaçlarından hangisi daha tutumludur?

**Çözüm (derste verildi):** Birinci ağaç 3, ikinci ağaç 4 yer değiştirme gerektirir; birinci ağaç daha tutumludur ve tercih edilir.

## Dersin Toparlaması

Bu derste filogenetik ağaç kurmanın üç ana yaklaşımı ele alındı. Uzaklık tabanlı yöntemlerde hizalamadan ikili uzaklık matrisi kurulur ve bir kümeleme algoritması uygulanır. UPGMA en küçük uzaklıktaki çifti birleştirip uzaklıkları ortalamayla güncelleyen, dallanma noktalarını uzaklığın yarısına koyan ve böylece köklü ağaç veren en basit yöntemdir. Evrim hızı eşit varsayılamadığında üç dizi için dal uzunlukları basit doğrusal denklemlerle bulunur. Dört türlü ağaçta toplanabilirlik ve dört nokta koşulu komşuluk ilişkisi yönteminin, yıldız ağaçtan başlayıp komşuları birleştirme fikri de komşu birleştirmenin temelidir. Karakter tabanlı maksimum parsimoni en az mutasyon gerektiren ağacı yalnız bilgi verici konumlara bakarak seçer. Maksimum olabilirlik ise bir evrim modeli altında en olası ağacı arar. Ağaçların güvenilirliği bootstrap ve Kishino–Hasegawa gibi parametrik testlerle değerlendirilir.

Dersin son bölümünde biyoenformatikte yoğun kullanılan istatistiğe dönük bir tekrar başladı: veri analizinin kategorileri, betimsel ve çıkarımsal istatistik, analiz ilkeleri, parametre ve istatistik ayrımı, veri keşfi, belirsizlik ve olasılık, kategorik ve niceliksel veri türleri. Hoca istatistik konularına sonraki derste devam edileceğini ve görselleştirmenin istatistikten birkaç hafta sonra işleneceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
