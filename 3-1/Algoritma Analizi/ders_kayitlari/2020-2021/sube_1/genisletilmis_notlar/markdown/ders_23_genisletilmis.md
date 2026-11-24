# Ders 23 Genişletilmiş Notu: Geri İzleme ile N-Vezir ve Hamilton Çevrimi; Dal ve Sınır ile Atama ve Sırt Çantası Problemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. N-vezir problemi ve arama uzayının küçültülmesi
- 2. Geri izleme (backtracking) yaklaşımı
- 3. 4 vezir probleminin geri izlemeyle çözümü
- 4. Geri izleme ve derinlik öncelikli arama
- 5. Hamilton çevrimi problemi
- 6. Dal ve sınır (branch and bound) yaklaşımı
- 7. Atama problemi
- 8. 0-1 sırt çantası probleminin dal ve sınır ile çözümü
- Örnek Sorular

## 1. N-vezir problemi ve arama uzayının küçültülmesi

Dersin önceki bölümlerinde özyineleme, böl ve fethet ve dinamik programlama görülmüştü. Algoritma analizinde amaç, bir problemi o problemin ihtiyaçlarına göre en elverişli biçimde çözmektir. Bu derste farklı bir yaklaşım ele alınır: geriye doğru giderek problem çözme, yani geri izleme (backtracking). Bu yaklaşıma önceki derste başlanmıştı.

Örnek problem, kaynaklarda "sekiz vezir problemi" diye geçen N-vezir (N-Queens) problemidir. Elimizde $n$ vezir vardır ve bunları satranç tahtasına birbirini görmeyecek biçimde yerleştirmek isteriz. Vezir bir satır boyunca, bir sütun boyunca ya da çapraz olarak gidebilir (ekrandan, 00:15:00). Bu yüzden bir vezir bir kareye konunca, aynı satırdaki, aynı sütundaki ve iki çaprazdaki karelere başka vezir konamaz.

Hoca, bu problemin eskiden programlama derslerinde kaba kuvvet (brute force) yaklaşımlarıyla anlatıldığını, burada ise etkin çözümün arandığını belirtti. Kaba kuvvetten başlayarak, problemin yapısını kullandıkça denenecek durum sayısının nasıl düştüğü gösterildi (ekrandan, 00:20:00):

| Yaklaşım | Formül | 8 vezir için durum sayısı |
|---|---|---|
| 1. Kaba kuvvet | $\binom{64}{8} = \dfrac{64!}{(64-8)!\,8!}$ | $4\,426\,165\,368$ |
| 2. Her satıra bir vezir | $n^n \Rightarrow 8^8$ | $16\,777\,216$ |
| 3. Her satıra ve her sütuna bir vezir | $n! \Rightarrow 8!$ | $40\,320$ |
| 4. Geri izleme | | $2057$ |

### 1.1 Kaba kuvvet

Hiçbir şey düşünmeden her şeyi denemek: 64 karenin 8'li bütün kombinasyonları oluşturulur ve her birinin geçerli olup olmadığı kontrol edilir. Bu, yaklaşık 4,4 milyar durum demektir.

### 1.2 Her satıra bir vezir

Bakar bakmaz görülen ilk şey, bir satıra yalnız bir vezir gelebileceğidir. Her satıra bir vezir konursa her vezir için 8 sütun seçeneği kalır ve durum sayısı $8^8 = 16\,777\,216$ olur. Bu, kaba kuvvete göre çok büyük bir kazançtır.

### 1.3 Her satıra ve her sütuna bir vezir

Aynı mantıkla bir sütuna da iki vezir gelemez. Her satıra ve her sütuna bir vezir konursa, sütunların bir permütasyonu seçilmiş olur ve durum sayısı $8! = 40\,320$'ye iner.

> **Ders sonrası not:** Hoca bir yerde bu sayıyı sözlü olarak "4320" dedi; ekranda ve doğru değer $8! = 40\,320$'dir.

> **Hocanın vurgusu:** Bu örnek, "ama çalışıyor" diye savunulan verimsiz algoritmalara güzel bir cevaptır. Kaba kuvvet de doğru sonucu verir, ama 4 milyar işlem yapar. Yalnız her satıra bir vezir koyma kararıyla 16 milyona, her sütun kısıtıyla 40 bine inilir.

## 2. Geri izleme (backtracking) yaklaşımı

Daha da iyisi yapılabilir mi? Hocanın cevabı: umut olmadığı anlaşılan noktada işlemi kesip başka bir yol denemek. Yani bir yolu sonuna kadar denemek yerine "buradan artık umut yok" denilen yerde durmak.

Hoca bunu tahtada 4×4 bir örnekle gösterdi (ekrandan, 00:20:00). Birinci vezir (1,1)'de, ikinci vezir (2,3)'teyken üçüncü satırın hiçbir karesine vezir konamaz: 1. sütunu birinci vezir, 2. sütunu ikinci vezir (çapraz), 3. sütunu hem birinci hem ikinci vezir, 4. sütunu ikinci vezir (çapraz) görür. Bu durumda dördüncü satırı denemenin hiçbir anlamı yoktur; üçüncü vezir konamadıysa dördüncü de konamayacaktır. Burada durmak ve geri dönmek gerekir.

**Soru (hocanın derste sorduğu):** Üçüncü veziri yerleştiremediysem neyi değiştirmeyi denemeliyim? **Cevap (öğrencilerden):** İkinci vezirin yerini. Hoca bunu doğruladı: geriye doğru gidip bir önceki kararı düzeltmeye çalışma işlemi geri izlemedir. Hocanın verdiği bilgiye göre 8 vezir problemi geri izlemeyle 2057 adımda çözülür.

Dinamik programlamayla karşılaştırma: dinamik programlamada bir problemin alt çözümleri üretilip kullanılıyordu. Geri izlemede ise bir noktada çözüme ulaşılamayacağı anlaşılırsa o noktadan yola devam edilmez. Bu da zaman kazandırır.

Hoca genel mantığı bir ağaç çizerek anlattı: bir noktadan çıkılır, iki ya da üç yol vardır, biri seçilir. Olmazsa ikincisi denenir. Bir düğümden gidecek yol kalmazsa en son çıkılan noktaya dönülüp oradaki bir sonraki seçenek denenir. Bu böyle sürer ve çözüm bulunana kadar gerekirse daha yukarı çıkılır.

## 3. 4 vezir probleminin geri izlemeyle çözümü

Hoca 4×4 tahta üzerinde geri izlemeyi baştan sona uyguladı (ekrandan, 00:30:00). İlk kural: yerleştirme hiyerarşik yapılır. Rastgele bir yere vezir koymanın anlamı yoktur; ilk vezir 1. satırın 1. sütununa konur ve her satırda sütunlar soldan sağa denenir.

Adımlar (satır, sütun):

1. 1. vezir (1,1)'e konur.
2. 2. vezir: (2,1) aynı sütun, (2,2) çapraz; konamaz. (2,3)'e konur.
3. 3. vezir: (3,1), (3,2), (3,3), (3,4) karelerinin hepsi görülür. Konamaz; bir adım geri dönülür.
4. 2. vezir bir sonraki seçeneğe, (2,4)'e kaydırılır.
5. 3. vezir: (3,1) aynı sütun; konamaz. (3,2)'ye konur.
6. 4. vezir: (4,1), (4,2), (4,3), (4,4) karelerinin hepsi görülür; örneğin (4,4)'ü hem 2. vezir (aynı sütun) hem 1. vezir (çapraz) görür. Konamaz; geri dönülür.
7. 2. vezir zaten son sütundadır, gidecek başka yeri yoktur. Bir adım daha yukarı, 1. vezire çıkılır.
8. 1. vezir (1,2)'ye konur.
9. 2. vezir: (2,1), (2,2), (2,3) kapalıdır; (2,4)'e konur.
10. 3. vezir (3,1)'e konur.
11. 4. vezir: (4,1) ve (4,2) kapalı, (4,3)'e konur. Çözüm bulunur.

Bulunan yerleşim, satır sırasına göre sütunlarla $(2, 4, 1, 3)$'tür. Python ile yapılan kontrolde 4 vezirin iki çözümü olduğu, $(2, 4, 1, 3)$ ve $(3, 1, 4, 2)$, ve soldan sağa geri izlemenin ilk bulduğu çözümün $(2, 4, 1, 3)$ olduğu doğrulandı.

### 3.1 Durum uzayı ağacı

Bu biçimde çizilen ağaca durum uzayı ağacı (state space tree) denir. Geri izlemede çözümü göstermenin genel yolu budur: karar verirken denenen seçenekler ve geri dönüşler bu ağaç üzerinde gösterilir. Ekrandaki ağaçta kök boş tahtadır; her alt düğüm bir vezirin daha konduğu tahtadır, konamayan sütunlar "×" ile işaretlenir ve geri dönüşler oklarla gösterilir.

> **Ek bilgi (derste anlatılmadı):** Python ile yapılan kontrolde 8 vezir probleminin 92 çözümü olduğu ve bütün çözümleri arayan geri izleme ağacının kök dahil 2057 düğümden oluştuğu görüldü. Bu, hocanın verdiği 2057 sayısıyla uyumludur; büyük olasılıkla sayı bu düğüm sayısını anlatır.

## 4. Geri izleme ve derinlik öncelikli arama

Geri izlemede yapılan şey tam olarak derinlik öncelikli aramadır (depth-first search, DFS). Önceki derste graflar üzerinde DFS ve genişlik öncelikli arama (BFS) anlatılmıştı. DFS'de başlanılan noktadan gidilebilecek en son yere kadar gidilir, sonra en son gelinen yere dönülür, oradan başka bir yere gidilir; olmuyorsa bir önceki yere dönülür.

Hoca, 8 vezir algoritmasını önceki yıllarda derste anlattığını, bu kez öğrencilerin kendi başlarına yazmayı denemesini istediğini söyledi. Bu ödev değil, çalışma önerisidir; çözemeyenler için kaynaklarda çok sayıda çözüm vardır.

**Soru:** Geri izleme algoritmaları genelde özyinelemeli mi çözülür? **Cevap:** Geri izleme algoritmaları genelde DFS mantığıyla çözülür ve bunun için özyinelemeli çözüm uygundur. Yapılan, bir önceki yere geri dönmektir: "şuraya gelmeden önce şuradaydım" diye en başa değil, bir önceki düğüme dönüp sıradaki seçeneği denemek. Bu son giren ilk çıkar (LIFO) mantığıdır; yığıt (stack) ile yazılan çözümler de özünde özyinelemeli çözümlerdir.

## 5. Hamilton çevrimi problemi

Hamilton çevrimi (Hamiltonian circuit) probleminde bir graf verilir. Amaç, bir düğümden yola çıkıp her düğüme tam bir kez uğrayarak başlangıç düğümüne geri dönülüp dönülemeyeceğine karar vermektir. Dönülebiliyorsa bu yol bir Hamilton çevrimidir. Ekrandaki tanım: "Graph(V, E): visits every node exactly once" (ekrandan, 00:45:00).

Hoca, bir grafın Hamilton çevrimi içerip içermediğine karar vermenin bir NP (non-deterministic polynomial) problemi olduğunu söyledi.

> **Ders sonrası not:** Hoca ardından "A'dan çıkıp A'ya dönebiliyor muyum" diye sorulursa sorunun NP olmaktan çıktığı yönünde bir şey söyledi (altyazı burada da bozuk). Bir Hamilton çevrimi bütün düğümlerden geçtiği için başlangıç düğümünün sabitlenmesi problemi kolaylaştırmaz; Hamilton çevrimi karar problemi büyük olasılıkla bu biçimiyle de NP-tamdır. <!-- BELİRSİZ: hocanın 00:36:55-00:37:13 arasındaki cümlesi altyazıda tam anlaşılmıyor. -->

Bu problemde de geri izleme kullanılabilir: bir yol çıkmıyorsa geri dönüp başka yol denenir. Bunun için yine bir durum uzayı ağacı kurulur.

### 5.1 Örnek graf

Ekrandaki graf (ekrandan, 00:45:00) 6 düğümlüdür. Komşuluklar:

| Düğüm | Komşular |
|---|---|
| a | b, c, d |
| b | a, c, f |
| c | a, b, d, e |
| d | a, c, e |
| e | c, d, f |
| f | b, e |

Bir düğüme ikinci kez uğramak gerekirse ya da yol tıkanırsa çıkmaz (dead end) vardır.

### 5.2 Geri izlemeyle çözüm

Komşular alfabetik sırayla denenir; ziyaret edilmiş düğümler işaretlenir ve tekrar ziyaret edilmez (ekrandan, 00:40:00 ve 00:45:00).

1. $a \to b \to c \to d \to e \to f$. $f$'nin komşuları $b$ ve $e$ ziyaret edilmiştir ve $a$'ya bağlı değildir: çıkmaz.
2. $f$'den, sonra $e$'den gidecek başka yer yoktur ($e$'nin komşuları $c, d, f$). $d$'ye çıkılır: $a$ ve $c$ kullanılamaz. $d$'den de yol yoktur, $c$'ye çıkılır.
3. $c$'den $a$ ve $b$ işaretlidir, $d$ denendi; $e$ denenir: $c \to e$.
4. $e \to d$: $d$'nin komşuları $a$ ve $e$ kullanılamaz ($f$ henüz ziyaret edilmediği için $a$'ya dönülemez); çıkmaz.
5. $e \to f$: $f$'nin komşuları $b$ ve $e$ işaretlidir; çıkmaz.
6. $c$'nin seçenekleri bitti; $b$'ye dönülür. $b$'nin komşularından $a$ ziyaret edilmiş, $c$ denenmiştir; üçüncü seçenek $f$'dir: $b \to f$.
7. $f$'den $b$ işaretli; $f \to e$.
8. $e \to c$ ($e$'nin ilk seçeneği).
9. $c$'den $a$ ve $b$ işaretli; $c \to d$.
10. Bütün düğümler ziyaret edildi ve $d$, $a$'ya doğrudan bağlı: $d \to a$.

Bulunan Hamilton çevrimi: $a \to b \to f \to e \to c \to d \to a$ (ekrandaki ağaçta "SOLUTION").

Hoca yaptığı işi şöyle özetledi: olası bütün seçenekler denenir; bir noktada çıkmaz oluşursa bir adım yukarı dönülür, orada yapılacak bir şey yoksa bir adım daha yukarı dönülür ve bu, çözüm bulunana kadar sürer. Bir yerden ileri gidilemeyeceği anlaşıldığı anda kesilip yukarı dönülür. Bu yine DFS mantığıdır.

> **Ek bilgi (derste anlatılmadı):** Python ile yapılan kontrolde bu grafta $a$'dan başlayan üç farklı Hamilton çevrimi bulundu (her biri iki yönde dolaşılabilir). Alfabetik sırayla ilerleyen geri izlemenin ilk bulduğu, derste bulunan $a\,b\,f\,e\,c\,d\,a$ çevrimidir.

### 5.3 Öğrenci sorusu: son iki düğümü baştan ayırmak

**Soru:** $a$ üç düğüme bağlı. $a$ bunlardan birinden çıkacak, $a$'ya ise $c$ ya da $d$ üzerinden dönülecek. Düğüm sayısını biliyorsak, son iki düğüm kalana kadar $c$ ve $d$'ye hiç bakmasak daha verimli olmaz mıydı?

**Cevap:** Böyle bir garanti yoktur. Bu örnekte bağlantılar uygun olduğu için öyle görünür; ama genel bir grafta $c$ ile $d$ arasında bağlantı olmayabilir, $c$ bambaşka yerlere gidiyor olabilir. Son iki düğüme bakarak $a$'ya geri dönülebileceği söylenemez; yalnız uğranan son düğümün $a$'ya bağlı olduğu kontrol edilebilir. Ayrıca grafta Hamilton çevrimi hiç olmayabilir; soru zaten çevrimin var olup olmadığını sorar. Hoca bunu göstermek için tahtaya bir düğümün dışarıda kaldığı başka bir graf çizdi ve orada Hamilton çevrimi olmadığını söyledi. <!-- BELİRSİZ: hocanın bu soru için çizdiği ikinci graf hiçbir karede görünmüyor; kenarları aktarılamadı. -->

## 6. Dal ve sınır (branch and bound) yaklaşımı

Aradan sonra aynı mantıktaki algoritmalara devam edildi, ama bir farkla: bu kez seçimlerin bedelleri de vardır. İki örnek verildi:

- Dört iş ve dördüne birden başvuran dört kişi vardır; herkes her iş için farklı ücret ister. Kişiler işlere en az ücret ödenecek biçimde yerleştirilmelidir.
- Daha önce görülen sırt çantası (knapsack) problemi: hırsızın çantasının taşıyabileceği yük bellidir; eşyalar hem çantaya sığacak hem de toplam değer en yüksek olacak biçimde seçilmelidir.

Bu problemlerde de geri izlemedeki gibi seçimler yapılır, ama bir en iyileme (optimizasyon) de vardır: en çok gelir, en az ödeme, en az zaman gibi. Amaç en iyi çözümü (optimal solution) bulmaktır. Dal ve sınır (branch and bound), bu tür problemleri durum uzayı ağacıyla çözer: her düğüm için o düğümden ulaşılabilecek en iyi değerin bir sınırı hesaplanır ve ucundan iyi bir sonuç çıkmayacağı belli olan dallar açılmaz.

## 7. Atama problemi

### 7.1 Problem

Dört kişi ($a, b, c, d$) ve dört iş vardır. Maliyet matrisi $C$ (ekrandan, 01:10:00):

| | İş 1 | İş 2 | İş 3 | İş 4 |
|---|---|---|---|---|
| a | 9 | 2 | 7 | 8 |
| b | 6 | 4 | 3 | 7 |
| c | 5 | 8 | 1 | 8 |
| d | 7 | 6 | 9 | 4 |

Her kişi bir işe, her iş bir kişiye atanacak ve toplam ücret en küçük olacaktır. Deneme yanılmayla gidilirse, örneğin $a$ 2. işe, $b$ 3. işe konduğunda bir adım sonra $c$'nin 3. iş için daha az istediği görülür ve geri dönmek gerekir. Bütün olasılıkları denemek üstel (eksponansiyel) bir hesaptır.

### 7.2 Alt sınır (lower bound)

Dal ve sınır yaklaşımı şunu der: her kişinin istediği ücret bellidir; herkesi en az para istediği işe yerleştirseydim ne öderdim, oradan başlayayım. Bu aşamada aynı işe iki kişinin düşüp düşmediğine bakılmaz.

Başlangıç düğümü (ekrandan, 01:10:00): her satırın en küçüğü $a$: 2 (iş 2), $b$: 3 (iş 3), $c$: 1 (iş 3), $d$: 4 (iş 4).

$$lb = 2 + 3 + 1 + 4 = 10$$

Burada $b$ ve $c$ aynı işe (3. iş) düşmüştür; yani bu gerçek bir atama değildir. Ama hiçbir atama bundan ucuz olamaz: ödenebilecek en az para 10'dur.

### 7.3 Birinci düzey: $a$'nın sabitlenmesi

$a$ sırayla her işe kesin olarak yerleştirilir. $a$ bir işe konunca o işe başkası konamaz; kalan kişiler kalan işler arasındaki en küçük ücretleriyle hesaba katılır (ekrandan, 01:15:00).

- $a \to 1$: $lb = 9 + 3 + 1 + 4 = 17$.
- $a \to 2$: $lb = 2 + 3 + 1 + 4 = 10$.
- $a \to 3$: $a$'ya 7 ödenir. 3. iş artık $b$ ve $c$ için kapalıdır: $b$'nin en iyisi 2. iş (4), $c$'nin en iyisi 1. iş (5), $d$ 4. iş (4). $lb = 7 + 4 + 5 + 4 = 20$.
- $a \to 4$: $a$'ya 8 ödenir. $b$: 3, $c$: 1, $d$ 4. işi kullanamaz, en iyisi 2. iş (6). $lb = 8 + 3 + 1 + 6 = 18$.

Python ile dört sınır da (17, 10, 20, 18) doğrulandı.

**Soru:** Başta en küçükleri toplayıp 10 bulduk; $a \to 2$ için yeniden hesaplayınca yine 10 çıktı. Neden aynı? **Cevap:** Çünkü bu örnekte 2. iş sütununda $a$'dan başka kimsenin en ucuz seçeneği yoktu, çakışma olmadı. Örneğin $b$'nin en ucuz işi 2. iş olsaydı, $a$ 2. işe konunca $b$ başka bir işe kayacak ve sınır 10'dan büyük çıkacaktı. Hoca bunu ekranın sağına matrisi yeniden yazıp her satırın 2. iş dışındaki en küçük değerini işaretleyerek gösterdi (ekrandan, 01:15:00). İki 10'un eşit çıkması bir şanstır.

**Soru:** Alt sınır, gerçek sonuca benzer ya da yakın bir değer mi arıyor? **Cevap:** Hayır. Başlangıçtaki 10, kimin nerede durduğuna hiç bakılmadığında ödenebilecek en az paradır. $a \to 2$ düğümündeki 10 ise "$a$ kesinlikle 2. işte olursa, diğerleri en iyi yerlerine konsa en az ne öderim" sorusunun cevabıdır. Diğerlerinin çakışıp çakışmadığına bu aşamada bakılmaz.

### 7.4 Hangi düğümden devam edilir?

**Soru (hocanın derste sorduğu):** Bu tabloda ilk denemeye nereden başlarsınız? **Cevap (bir öğrenci):** $a \to 2$ düğümünden. Hoca doğruladı: şans yaver giderse buradan 10 liraya bir çözüm çıkabilir; çıkacağı kesin değildir ama 17, 20, 18 düğümlerini denemenin şu an anlamı yoktur.

### 7.5 İkinci düzey: $a \to 2$ altında $b$'nin sabitlenmesi

$a$ 2. işte sabitken $b$ 1., 3. ya da 4. işe konabilir (ekrandan, 01:20:00):

- $b \to 1$: $a$: 2, $b$: 6; $c$ 3. işte kalabilir (1), $d$ 4. işte kalabilir (4). $lb = 2 + 6 + 1 + 4 = 13$.
- $b \to 3$: $a$: 2, $b$: 3; $c$ 3. işi kullanamaz, en iyisi 1. iş (5); $d$: 4. $lb = 2 + 3 + 5 + 4 = 14$.
- $b \to 4$: $a$: 2, $b$: 7; $c$: 3. iş (1); $d$ 2. ve 4. işleri kullanamaz, en iyisi 1. iş (7). $lb = 2 + 7 + 1 + 7 = 17$.

> **Ders sonrası not:** Hoca $b \to 3$ hesabında bir yerde "B3'te 4" dedi, sonra düzeltip "B üçüncü işte üç" dedi. Doğrusu $b$'nin 3. iş ücretinin 3 olduğudur; toplam 14 bu değerle tutar.

### 7.6 Açık düğümler arasında seçim

**Soru (hocanın derste sorduğu):** Şimdi yola nereden devam edersiniz? Bir öğrenci $a \to 1$'den, bir başkası $a \to 3$'ten devam etmeyi önerdi. **Cevap:** Hoca, açık düğümlerin hepsinin birlikte değerlendirildiğini söyledi: elde 17 ($a \to 1$), 13 ($a \to 2, b \to 1$), 14, 17, 20 ($a \to 3$) ve 18 ($a \to 4$) vardır. En küçük değer 13'tür, oradan devam edilir. Çünkü 13 liraya bir çözüm bulunursa, 17, 14, 17, 20 ve 18 düğümlerinden en iyi ihtimalle bile o kadar ödeneceği için onları denemeye gerek kalmaz.

### 7.7 Üçüncü düzey: gerçek maliyet

$a \to 2$, $b \to 1$ iken $c$ ya 3. ya 4. işe konacaktır; dördüncü kişi kalan işe gider. Artık bunlar sınır değil, gerçek maliyettir:

- $c \to 3$, $d \to 4$: $2 + 6 + 1 + 4 = 13$.
- $c \to 4$, $d \to 3$: $2 + 6 + 8 + 9 = 25$.

Gerçek maliyet 13, açık kalan bütün düğümlerin alt sınırlarından (14, 17, 17, 18, 20) küçüktür. Bu yüzden başka dal denenmez ve çözüm bulunmuş olur:

$$a \to 2,\quad b \to 1,\quad c \to 3,\quad d \to 4,\qquad \text{maliyet} = 13$$

Python ile 24 olası atamanın tamamı denendi ve en küçük maliyetin 13 olduğu, bu atamayla elde edildiği doğrulandı.

Burada da geriye doğru gitme vardır, ama dal ve sınırın farkı, optimizasyonu gerektiren sınırların (en az, en çok gibi) kullanılmasıdır. Çözüm yine bir durum uzayı ağacıyla gösterilir.

**Soru:** Yalnız bulunduğumuz katmana mı bakıyoruz, yoksa üst katmanda daha küçük bir değer var mı diye ona da mı? **Cevap:** Üst katmana da bakılır. Örneğin alt katmanda 20, 25 gibi değerler çıksaydı ve üst katmanda daha küçük sınırlı düğümler olsaydı, önce onlar denenirdi. Çünkü alt katmandaki dal bir çıkmaz demektir: oradan ne yapılsa üstteki sınırdan daha iyisi bulunamaz.

## 8. 0-1 sırt çantası probleminin dal ve sınır ile çözümü

### 8.1 Problem ve sıralama

Atama probleminde en küçük değer arandı; sırt çantası probleminde en büyük değer, dolayısıyla üst sınır (upper bound) aranır. Bu problem daha önce dinamik programlamayla, bütün olasılıkları bir matris üzerinde rekürans bağıntısıyla hesaplayarak çözülmüştü. Dal ve sınırda ise iyi sonuç getirmeyeceği belli olan yollar denenmez.

Kapasite $W = 10$ kg, dört eşya (ekrandan, 01:35:00):

| Eşya | Ağırlık $w_i$ | Değer $v_i$ | Birim değer $v_i/w_i$ |
|---|---|---|---|
| 1 | 4 | 40 | 10 |
| 2 | 7 | 42 | 6 |
| 3 | 5 | 25 | 5 |
| 4 | 3 | 12 | 4 |

Önce her eşyanın birim değeri (değer / ağırlık) hesaplanır ve eşyalar birim değere göre büyükten küçüğe sıralanır: $v_1/w_1 \ge v_2/w_2 \ge \dots \ge v_n/w_n$. Örnekteki eşyalar zaten bu sıradadır. Birim değeri en yüksek eşya en kârlısı olabilir; işe oradan başlamak iyi bir çözümdür.

### 8.2 Üst sınır

İkinci karar: her adımda o düğümden en fazla ne kazanılabileceğine bakmak. Örneğin çanta boşken birinci eşyanın kilosu 10 TL'dir; 10 kg'ın tamamı bu değerde olsaydı en fazla $10 \text{ TL} \times 10 = 100$ TL kazanılırdı (ekrandan, 01:30:00). Bunun üzerine çıkılamaz. Genel formül (ekrandan, 01:35:00):

$$ub = v + (W - w)\,\frac{v_{i+1}}{w_{i+1}}$$

Burada $v$ ve $w$ o düğümde seçilmiş eşyaların toplam değeri ve ağırlığı, $v_{i+1}/w_{i+1}$ ise sıradaki (henüz karar verilmemiş en iyi) eşyanın birim değeridir.

### 8.3 Ağacın kurulması

Her eşya için iki dal vardır: alınır (with) ve alınmaz (without). Ağaç (ekrandan, 01:45:00 ve 01:50:00):

- Kök: $w = 0$, $v = 0$, $ub = 0 + (10 - 0) \cdot 10 = 100$.
- 1 alınır: $w = 4$, $v = 40$, $ub = 40 + (10 - 4) \cdot 6 = 76$.
- 1 alınmaz: $w = 0$, $v = 0$, $ub = 10 \cdot 6 = 60$.
- 76 > 60 olduğu için 1'in alındığı daldan devam edilir.
  - 1 ve 2 alınır: $w = 4 + 7 = 11 > 10$; sığmaz, dal ölür.
  - 1 var, 2 yok: $w = 4$, $v = 40$, $ub = 40 + 6 \cdot 5 = 70$.
    - 3 alınır: $w = 9$, $v = 40 + 25 = 65$, $ub = 65 + 1 \cdot 4 = 69$.
      - 4 alınır: $w = 9 + 3 = 12 > 10$; sığmaz.
      - 4 alınmaz: $w = 9$, $v = 65$, $ub = 65$ (yaprak, gerçek değer).
    - 3 alınmaz: $w = 4$, $v = 40$, $ub = 40 + 6 \cdot 4 = 64$.

70, 60'tan büyük olduğu için bu yoldan gitmeye devam edilir. Sonra 69 ile 64 karşılaştırılır ve 3'ün alındığı dal açılır.

> **Ders sonrası not:** Hoca 69 ile 64'ü karşılaştırırken bir yerde "burası 65" dedi; ekrana göre 3'ün alınmadığı düğümün üst sınırı 64'tür.

### 8.4 Budama ve sonuç

$\{1, 3\}$ yaprağında gerçek değer 65'tir. Açık kalan diğer düğümlerin üst sınırları 60 (1 alınmaz) ve 64 (1 var, 3 yok) olduğu için 65'ten iyisi o dallardan çıkamaz; bu dallar iptal edilir. 2'nin ve 4'ün alındığı dallar ağırlık sınırını aştıkları için zaten ölmüştür. En iyi çözüm: 1 alınır, 2 alınmaz, 3 alınır, 4 alınmaz; toplam 9 kg, 65 TL (ekrandan, 01:50:00). Python ile 16 alt kümenin tamamı denendi ve en büyük değerin {1, 3} ile 65 olduğu doğrulandı.

### 8.5 Üst sınırın anlamı

**Soru:** Kökte üst sınırı 100 dedik. Ama 0-1 sırt çantasında eşya bölünemiyor; birinci eşyadan iki buçuk tane almak gerekirdi, gerçekte 100'e çıkılamaz. **Cevap:** Aynen öyle; burada amaç gerçek çözümü bulmak değildir. Atama probleminde de aynı işe iki kişi konamazdı, ama "her şey yolunda gitseydi en az ne öderdim" diye bakılmıştı. Burada da "bir kilo için en fazla 10 TL kazanılabiliyorsa, 10 kg'ın tamamı bu değerde olsaydı ne kazanırdım" diye bakılır.

> **Hocanın vurgusu:** Üst sınır size gerçek çözümü söylemez. Kurallara takılmasaydım, örneğin birinci eşya 4 kg değil de 10 kg olsaydı, en fazla ne kazanabilirdim, onu söyler. Bu sayede bir yoldan devam etmenin bir şey getirip getirmeyeceği görülür: elimde 65 varsa, en fazla 60 getirebilecek yola hiç girilmez.

Böylece dal ve sınır için de bir durum uzayı ağacı (state-space tree of branch-and-bound) elde edilir ve devam edilmemesi gereken yollar görülür.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): 8 vezir problemi için kaba kuvvet, her satıra bir vezir ve her satır ile sütuna bir vezir yaklaşımlarında kaç durum denenir?

> **Çözüm:** $\binom{64}{8} = 4\,426\,165\,368$; $8^8 = 16\,777\,216$; $8! = 40\,320$. Geri izleme hocanın verdiği sayıya göre 2057 adımda çözer.

**Soru 2** (ekrandan, 00:30:00): 4×4 tahtaya 4 veziri geri izlemeyle yerleştirin; durum uzayı ağacını çizin.

> **Çözüm:** (1,1) → (2,3) → 3. satır kapalı, geri; (2,4) → (3,2) → 4. satır kapalı, geri; 2. vezirin yeri kalmadı, geri; (1,2) → (2,4) → (3,1) → (4,3). Çözüm $(2, 4, 1, 3)$. Ayrıntı için Bölüm 3.

**Soru 3** (derste sözlü, 00:19:30): Üçüncü vezir hiçbir sütuna yerleştirilemiyorsa ne değiştirilmelidir?

> **Çözüm:** Bir önceki kararın, yani ikinci vezirin yeri. Bu geriye dönüş geri izlemedir.

**Soru 4** (ekrandan, 00:45:00): Bölüm 5.1'deki 6 düğümlü grafta $a$'dan başlayan bir Hamilton çevrimini geri izlemeyle bulun.

> **Çözüm:** $a\,b\,c\,d\,e\,f$ ve $c$ altındaki $e$ dalları çıkmaza girer; $b \to f$ dalından $a \to b \to f \to e \to c \to d \to a$ bulunur. Ayrıntı için Bölüm 5.2.

**Soru 5** (ekrandan, 01:10:00 ve 01:20:00): Bölüm 7.1'deki maliyet matrisiyle atama problemini dal ve sınır ile çözün.

> **Çözüm:** Kök $lb = 10$; $a \to 1, 2, 3, 4$ için 17, 10, 20, 18; $a \to 2$ altında $b \to 1, 3, 4$ için 13, 14, 17; $a \to 2, b \to 1$ altında gerçek maliyetler 13 ($c \to 3, d \to 4$) ve 25. En iyi atama $a \to 2, b \to 1, c \to 3, d \to 4$, maliyet 13.

**Soru 6** (derste sözlü, 01:14:50 ve 01:19:00): Atama ağacında ilk düzeyden sonra hangi düğümden, ikinci düzeyden sonra hangi düğümden devam edilir?

> **Çözüm:** İlk düzeyde alt sınırı en küçük olan $a \to 2$ (10). İkinci düzeyden sonra bütün açık düğümler (17, 13, 14, 17, 20, 18) karşılaştırılır; en küçük olan $a \to 2, b \to 1$ (13) düğümünden devam edilir.

**Soru 7** (ekrandan, 01:35:00 ve 01:50:00): $W = 10$; eşyalar (ağırlık, değer) = (4, 40), (7, 42), (5, 25), (3, 12). 0-1 sırt çantası problemini dal ve sınır ile çözün.

> **Çözüm:** $ub = v + (W - w)(v_{i+1}/w_{i+1})$ ile kök 100; 1 alınır 76, alınmaz 60; 1 ve 2 sığmaz; 1 var 2 yok 70; 3 alınır 69, alınmaz 64; 4 sığmaz; 4 alınmaz 65. En iyi çözüm {1, 3}, 9 kg, 65 TL.

## Dersin Toparlaması

Bu derste, problemin yapısı kullanıldıkça arama uzayının nasıl küçüldüğü 8 vezir problemiyle gösterildi ve geri izleme tanıtıldı: çözüm adım adım kurulur, umut kalmayan noktada geri dönülür ve denenen seçenekler durum uzayı ağacında gösterilir. Geri izlemenin DFS mantığıyla çalıştığı ve özyinelemeli yazıldığı vurgulandı. Aynı yaklaşım 4 vezir ve Hamilton çevrimi örnekleriyle adım adım uygulandı.

Dersin ikinci yarısında, seçimlerin bedeli olan optimizasyon problemleri için dal ve sınır yaklaşımı anlatıldı. En küçükleme problemi olarak atama probleminde alt sınır, en büyükleme problemi olarak 0-1 sırt çantası probleminde üst sınır kullanıldı. Her iki örnekte de sınırlar gerçek çözüm değil, bir dalın denenmeye değer olup olmadığını gösteren iyimser tahminlerdir; bulunan gerçek çözümden kötü sınırı olan dallar açılmaz. Sırt çantası problemi böylece dinamik programlamadan sonra ikinci bir yöntemle çözülmüş oldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
